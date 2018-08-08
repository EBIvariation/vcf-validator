/**
 * Copyright 2018 EMBL - European Bioinformatics Institute
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

#include <boost/filesystem/operations.hpp>
#include <boost/program_options.hpp>

#include "cmake_config.hpp"
#include "util/logger.hpp"
#include "vcf/assembly_checker.hpp"
#include "vcf/string_constants.hpp"
#include "vcf/assembly_report_writer.hpp"

namespace
{
    namespace po = boost::program_options;

    const std::string version_info = "vcf-assembly-checker version " + std::to_string(VERSION_MAJOR) + "."
                                       + std::to_string(VERSION_MINOR);

    po::options_description build_command_line_options()
    {
        po::options_description description(version_info + "\n\nUsage: vcf-assembly-checker [OPTIONS] [< input_file]\nAllowed options");

        description.add_options()
            (ebi::vcf::HELP_OPTION, "Display this help")
            (ebi::vcf::VERSION_OPTION, "Display version of the assembly-checker")
            (ebi::vcf::INPUT_OPTION, po::value<std::string>(), "Path to the input VCF file")
            (ebi::vcf::FASTA_OPTION, po::value<std::string>(), "Path to the input FASTA file; please note that the index file must have the same name as the FASTA file and saved with a .idx extension")
            (ebi::vcf::REPORT_OPTION, po::value<std::string>()->default_value(ebi::vcf::SUMMARY), "Comma separated values for types of reports (summary, valid, invalid)")
        ;

        return description;
    }

    int check_command_line_options(po::variables_map const & vm, po::options_description const & desc)
    {
        if (vm.count(ebi::vcf::HELP)) {
            std::cout << desc << std::endl;
            return -1;
        }

        if (vm.count(ebi::vcf::VERSION)) {
            std::cout << version_info << std::endl;
            return -1;
        }

        if (!vm.count(ebi::vcf::INPUT)) {
            std::cout << desc << std::endl;
            BOOST_LOG_TRIVIAL(error) << "Please specify the path to the VCF file (--vcf)";
            return 1;
        }

        if (!vm.count(ebi::vcf::FASTA)) {
            std::cout << desc << std::endl;
            BOOST_LOG_TRIVIAL(error) << "Please specify the path to the FASTA file (--fasta)";
            return 1;
        }

        return 0;
    }

    std::vector<std::unique_ptr<ebi::vcf::AssemblyReportWriter>> get_outputs(std::string const &output_str,
                                                                             std::string const &input)
    {
        std::vector<std::string> outs;
        ebi::util::string_split(output_str, ",", outs);
        size_t initial_size = outs.size();

        std::sort(outs.begin(), outs.end());
        std::unique(outs.begin(), outs.end());
        if (initial_size != outs.size()) {
            BOOST_LOG_TRIVIAL(warning) << "Duplicated outputs! Will write just once to each output specified by -r/--report";
        }

        std::vector<std::unique_ptr<ebi::vcf::AssemblyReportWriter>> outputs;

        for (auto out : outs) {
            auto epoch = std::chrono::system_clock::now().time_since_epoch();
            auto timestamp = std::chrono::duration_cast<std::chrono::milliseconds>(epoch).count();
            std::string filetype = ".txt";
            if (out == ebi::vcf::VALID) {
                std::string filename = input + ".valid_assembly_report." + std::to_string(timestamp) + filetype;
                boost::filesystem::path file{filename};
                if (boost::filesystem::exists(file)) {
                    throw std::runtime_error{"Report file already exists on " + filename + ", please delete it or rename it"};
                }
                outputs.emplace_back(new ebi::vcf::TextAssemblyReportWriter(filename, out));
            } else if (out == ebi::vcf::INVALID) {
                std::string filename = input + ".invalid_assembly_report." + std::to_string(timestamp) + filetype;
                boost::filesystem::path file{filename};
                if (boost::filesystem::exists(file)) {
                    throw std::runtime_error{"Report file already exists on " + filename + ", please delete it or rename it"};
                }
                outputs.emplace_back(new ebi::vcf::TextAssemblyReportWriter(filename, out));
            } else if (out == ebi::vcf::SUMMARY) {
                outputs.emplace_back(new ebi::vcf::SummaryAssemblyReportWriter());
            } else {
                throw std::invalid_argument{"Please use only valid report types"};
            }
        }

        return outputs;
    }

    inline void open_file(std::ifstream & input,
                          std::string path,
                          std::ios_base::openmode mode = std::ios_base::in)
    {
        input.open(path,mode);
        if (!input) {
            std::string file_error_msg = "Couldn't open file " + path;
            throw std::runtime_error{file_error_msg};
        }
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

    try {
        auto vcf_path = vm[ebi::vcf::INPUT].as<std::string>();
        auto fasta_path = vm[ebi::vcf::FASTA].as<std::string>();
        auto fasta_index_path = fasta_path + ".fai";
        auto outputs = get_outputs(vm[ebi::vcf::REPORT].as<std::string>(), vcf_path);

        BOOST_LOG_TRIVIAL(info) << "Reading from input VCF file...";
        std::ifstream vcf_input;
        open_file(vcf_input, vcf_path);

        BOOST_LOG_TRIVIAL(info) << "Reading from input FASTA file...";
        std::ifstream fasta_input;
        open_file(fasta_input, fasta_path, std::ifstream::binary);

        BOOST_LOG_TRIVIAL(info) << "Reading from input FASTA index file...";
        std::ifstream fasta_index_input;
        open_file(fasta_index_input, fasta_index_path, std::ifstream::binary);

        ebi::vcf::assembly_checker::check_vcf_ref(vcf_input, fasta_input, fasta_index_input, outputs);
        return 0;
    } catch (std::invalid_argument const & ex) {
        BOOST_LOG_TRIVIAL(error) << ex.what();
        return 1;
    } catch (std::runtime_error const & ex) {
        BOOST_LOG_TRIVIAL(error) << "The validation could not be completed: " << ex.what();
        return 1;
    } catch (std::exception const &ex) {
        BOOST_LOG_TRIVIAL(error) << ex.what();
        return 1;
    }
}
