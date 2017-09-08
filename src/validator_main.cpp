/**
 * Copyright 2014-2017 EMBL - European Bioinformatics Institute
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <vector>
#include <stdexcept>
#include <chrono>
#include <iomanip>

#include <boost/program_options.hpp>
#include <boost/filesystem/operations.hpp>

#include "util/logger.hpp"
#include "vcf/file_structure.hpp"
#include "vcf/validator.hpp"
#include "vcf/ploidy.hpp"
#include "vcf/report_writer.hpp"
#include "vcf/odb_report.hpp"
#include "vcf/summary_report_writer.hpp"

namespace
{
    namespace po = boost::program_options;

    po::options_description build_command_line_options()
    {
        po::options_description description("Usage: vcf-validator [OPTIONS] [< input_file]\nAllowed options");

        description.add_options()
            (ebi::vcf::HELP_OPTION, "Display this help")
            (ebi::vcf::INPUT_OPTION, po::value<std::string>()->default_value(ebi::vcf::STDIN), "Path to the input VCF file, or stdin")
            (ebi::vcf::LEVEL_OPTION, po::value<std::string>()->default_value(ebi::vcf::WARNING), "Validation level (error, warning, stop)")
            (ebi::vcf::REPORT_OPTION, po::value<std::string>()->default_value(ebi::vcf::STDOUT), "Comma separated values for types of reports (database, stdout)")
            (ebi::vcf::OUTDIR_OPTION, po::value<std::string>()->default_value(""), "Directory for the output")
            (ebi::vcf::PLOIDY_OPTION, po::value<long>()->default_value(2), "Genome ploidy to expect through most or the whole VCF file (can be overwritten with --special-ploidy)")
            (ebi::vcf::SPECIAL_PLOIDY_OPTION, po::value<std::string>(), "Ploidy expected in specific chromosomes/contigs, e.g Y=1,MyTriploidContig=3")
        ;

        return description;
    }

    int check_command_line_options(po::variables_map const & vm, po::options_description const & desc)
    {
        if (vm.count(ebi::vcf::HELP)) {
            std::cout << desc << std::endl;
            return -1;
        }

        std::string level = vm[ebi::vcf::LEVEL].as<std::string>();
        if (level != ebi::vcf::ERROR && level != ebi::vcf::WARNING && level != ebi::vcf::STOP) {
            std::cout << desc << std::endl;
            BOOST_LOG_TRIVIAL(error) << "Please choose one of the accepted validation levels";
            return 1;
        }

        long ploidy = vm[ebi::vcf::PLOIDY].as<long>();
        if (ploidy <= 0) {
            BOOST_LOG_TRIVIAL(error) << "Ploidy must be greater that 0";
            return 1;
        }

        return 0;
    }

    ebi::vcf::ValidationLevel get_validation_level(std::string const & level_str)
    {
        if (level_str == ebi::vcf::ERROR) {
            return ebi::vcf::ValidationLevel::error;
        } else if (level_str == ebi::vcf::WARNING) {
            return ebi::vcf::ValidationLevel::warning;
        } else if (level_str == ebi::vcf::STOP) {
            return ebi::vcf::ValidationLevel::stop;
        }

        throw std::invalid_argument{"Please choose one of the accepted validation levels"};
    }

    std::string get_output_path(const std::string &outdir, const std::string &file_path)
    {
        if (outdir == "") {
            return file_path;
        }
        
        boost::filesystem::path file_boost_path{file_path};
        boost::filesystem::path outdir_boost_path{outdir};
        if (not boost::filesystem::is_directory(outdir_boost_path)) {
            throw std::invalid_argument{"outdir should be a directory, not a file: " + outdir_boost_path.string()};
        }
        
        outdir_boost_path /= file_boost_path.filename();

        return outdir_boost_path.string();
    }

    ebi::vcf::Ploidy get_ploidy(long default_ploidy, po::variables_map const & vm)
    {
        const std::string message = "Please provide the special ploidies as a comma-separated list of pairs "
                "CHROM=PLOIDY where CHROM is the name as in the VCF, and PLOIDY is a number strictly greater than 0.";


        size_t unsigned_ploidy;
        if (default_ploidy <= 0) {
            throw std::invalid_argument{std::to_string(default_ploidy)
                                                + " is not a valid ploidy, must be a number strictly greater than 0."};
        }
        unsigned_ploidy = static_cast<size_t>(default_ploidy);

        std::map<std::string, size_t> special_ploidies;
        if (vm.count(ebi::vcf::SPECIAL_PLOIDY)) {
            std::string parameter{vm[ebi::vcf::SPECIAL_PLOIDY].as<std::string>()};
            std::vector<std::string> ploidies;
            ebi::util::string_split(parameter, ",", ploidies);
            for (std::string &ploidy_assignment : ploidies) {
                std::vector<std::string> contig_and_ploidy;
                ebi::util::string_split(ploidy_assignment, "=", contig_and_ploidy);
                if (contig_and_ploidy.size() != 2) {
                    throw std::invalid_argument{ploidy_assignment + " is not a valid CHROM=PLOIDY pair. " + message};
                }
                size_t ploidy;
                try {
                    ploidy = std::stoul(contig_and_ploidy[1]);
                } catch (std::exception e) {
                    throw std::invalid_argument{contig_and_ploidy[1] + " is not a valid ploidy. " + message};
                }
                special_ploidies[contig_and_ploidy[0]] = ploidy;
            }
        }

        return ebi::vcf::Ploidy{unsigned_ploidy, special_ploidies};
    }

    std::vector<std::unique_ptr<ebi::vcf::ReportWriter>> get_outputs(std::string const &output_str, std::string const &input) {
        std::vector<std::string> outs;
        ebi::util::string_split(output_str, ",", outs);
        size_t initial_size = outs.size();

        // don't write several times to the same output
        std::sort(outs.begin(), outs.end());
        std::unique(outs.begin(), outs.end());
        if (initial_size != outs.size()) {
            BOOST_LOG_TRIVIAL(warning) << "Duplicated outputs! will write just once to each output specified by -r/--report";
        }

        std::vector<std::unique_ptr<ebi::vcf::ReportWriter>> outputs;

        for (auto out : outs) {
            if (out == ebi::vcf::DATABASE) {
                auto epoch = std::chrono::system_clock::now().time_since_epoch();
                auto timestamp = std::chrono::duration_cast<std::chrono::milliseconds>(epoch).count();
                std::string db_filename = input + ".errors." + std::to_string(timestamp) + ".db";
                boost::filesystem::path db_file{db_filename};
                if (boost::filesystem::exists(db_file)) {
                    throw std::runtime_error{"Report file already exists on " + db_filename + ", please delete it or rename it"};
                }
                outputs.emplace_back(new ebi::vcf::OdbReportRW(db_filename));
            } else if (out == ebi::vcf::STDOUT) {
                outputs.emplace_back(new ebi::vcf::SummaryReportWriter(std::cout));
            } else {
                throw std::invalid_argument{"Please use only valid report types"};
            }
        }

        return outputs;
    }

}

int main(int argc, char** argv)
{
    ebi::util::init_boost_loggers();

    po::options_description desc = build_command_line_options();
    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);
    
    int check_options = check_command_line_options(vm, desc);
    if (check_options < 0) { return 0; }
    if (check_options > 0) { return check_options; }
    
    bool is_valid;

    try {
        auto path = vm[ebi::vcf::INPUT].as<std::string>();
        auto level = vm[ebi::vcf::LEVEL].as<std::string>();
        ebi::vcf::Ploidy ploidy = get_ploidy(vm[ebi::vcf::PLOIDY].as<long>(), vm);
        ebi::vcf::ValidationLevel validationLevel = get_validation_level(level);
        auto outdir = get_output_path(vm[ebi::vcf::OUTDIR].as<std::string>(), path);
        auto outputs = get_outputs(vm[ebi::vcf::REPORT].as<std::string>(), outdir);

        if (path == ebi::vcf::STDIN) {
            BOOST_LOG_TRIVIAL(info) << "Reading from standard input...";
            is_valid = ebi::vcf::is_valid_vcf_file(std::cin, path, validationLevel, ploidy, outputs);
        } else {
            BOOST_LOG_TRIVIAL(info) << "Reading from input file...";
            std::ifstream input{path};
            if (!input) {
                throw std::runtime_error{"Couldn't open file " + path};
            } else {
                is_valid = ebi::vcf::is_valid_vcf_file(input, path, validationLevel, ploidy, outputs);
            }
        }

        BOOST_LOG_TRIVIAL(info) << "According to the VCF specification, the input file is " << (is_valid ? "" : "not ") << "valid";
        return !is_valid; // A valid file returns an exit code 0
        
    } catch (std::invalid_argument const & ex) {
        BOOST_LOG_TRIVIAL(error) << ex.what();
        return 1;
    } catch (std::runtime_error const & ex) {
        BOOST_LOG_TRIVIAL(error) << "The input file is not valid: " << ex.what();
        return 1;
    } catch (std::exception const &ex) {
        BOOST_LOG_TRIVIAL(error) << ex.what();
        return 1;
    }
}
