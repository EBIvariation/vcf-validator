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
#include "util/cli_utils.hpp"
#include "util/file_utils.hpp"
#include "util/logger.hpp"
#include "vcf/assembly_checker.hpp"
#include "vcf/assembly_check_report_writer.hpp"
#include "vcf/compression.hpp"
#include "vcf/string_constants.hpp"

namespace
{
    namespace po = boost::program_options;

    const std::string version_info = "vcf-assembly-checker version " + std::to_string(VERSION_MAJOR) + "."
                                       + std::to_string(VERSION_MINOR) + "." + std::to_string(VERSION_PATCH);

    po::options_description build_command_line_options()
    {
        po::options_description description(version_info + "\n\nUsage: vcf-assembly-checker [OPTIONS] [< input_file]\nAllowed options");

        description.add_options()
            (ebi::vcf::HELP_OPTION, "Display this help")
            (ebi::vcf::VERSION_OPTION, "Display version of the assembly checker")
            (ebi::vcf::INPUT_OPTION, po::value<std::string>()->default_value(ebi::vcf::STDIN), "Path to the input VCF file, or stdin")
            (ebi::vcf::FASTA_OPTION, po::value<std::string>()->default_value(""), "Path to the input FASTA file; please note that the index file (from samtools faidx) must have the same name as the FASTA file and saved with a .fai extension")
            (ebi::vcf::ASSEMBLY_REPORT_OPTION, po::value<std::string>()->default_value(ebi::vcf::NO_MAPPING), "Path to the input assembly report used for contig synonym mapping")
            (ebi::vcf::REPORT_OPTION, po::value<std::string>()->default_value(ebi::vcf::SUMMARY), "Comma separated values for types of reports (summary, text, valid)")
            (ebi::vcf::OUTDIR_OPTION, po::value<std::string>()->default_value(""), "Output directory")
            (ebi::vcf::REQUIRE_GENBANK, "Flag to indicate that VCF should be checked for Genbank accessions")
        ;

        return description;
    }

    bool check_compressed_file(const std::string filePath) {
        std::string fileExtension = ebi::vcf::get_compression_from_extension(filePath);
        return fileExtension != ebi::vcf::NO_EXT;
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

        if (vm.count(ebi::vcf::FASTA) > 0) {
            std::string fastaFileName = vm[ebi::vcf::FASTA].as<std::string>();
            if (check_compressed_file(fastaFileName)) {
                throw std::invalid_argument("Only uncompressed FASTA files are supported! Cannot use FASTA file: "
                                            + fastaFileName);
                return 1;
            }
        }

        if (vm.count(ebi::vcf::ASSEMBLY_REPORT) > 0) {
            std::string assemblyReportFileName = vm[ebi::vcf::ASSEMBLY_REPORT].as<std::string>();
            if (check_compressed_file(assemblyReportFileName)) {
                throw std::invalid_argument("Only uncompressed assembly report files are supported! "
                                            "Cannot use assembly report file: " + assemblyReportFileName);
                return 1;
            }
        }

        return 0;
    }

    std::vector<std::unique_ptr<ebi::vcf::AssemblyCheckReportWriter>> get_outputs(std::string const &output_str,
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

        std::vector<std::unique_ptr<ebi::vcf::AssemblyCheckReportWriter>> outputs;

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
                outputs.emplace_back(new ebi::vcf::ValidAssemblyCheckReportWriter(filename));
            } else if (out == ebi::vcf::TEXT) {
                std::string filename = input + ".text_assembly_report." + std::to_string(timestamp) + filetype;
                boost::filesystem::path file{filename};
                if (boost::filesystem::exists(file)) {
                    throw std::runtime_error{"Report file already exists on " + filename + ", please delete it or rename it"};
                }
                outputs.emplace_back(new ebi::vcf::TextAssemblyCheckReportWriter(filename));
            } else if (out == ebi::vcf::SUMMARY) {
                outputs.emplace_back(new ebi::vcf::SummaryAssemblyCheckReportWriter());
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
    po::variables_map vm = ebi::util::build_variables_map(argc, argv, desc);

    int check_options = check_command_line_options(vm, desc);
    if (check_options < 0) { return 0; }
    if (check_options > 0) { return check_options; }

    try {
        auto vcf_path = vm[ebi::vcf::INPUT].as<std::string>();
        auto fasta_path = vm[ebi::vcf::FASTA].as<std::string>();
        auto assembly_report = vm[ebi::vcf::ASSEMBLY_REPORT].as<std::string>();
        auto outdir = ebi::util::get_output_path(vm[ebi::vcf::OUTDIR].as<std::string>(), vcf_path);
        auto outputs = get_outputs(vm[ebi::vcf::REPORT].as<std::string>(), outdir);
        bool requireGenbank = vm.count(ebi::vcf::REQUIRE_GENBANK) >= 1;

        bool is_valid;
        if (vcf_path == ebi::vcf::STDIN) {
            BOOST_LOG_TRIVIAL(info) << "Reading from standard input...";
            is_valid = ebi::vcf::assembly_checker::check_vcf_ref(std::cin, vcf_path, fasta_path, assembly_report,
                                                                 outputs, requireGenbank);
        } else {
            BOOST_LOG_TRIVIAL(info) << "Reading from input VCF file...";
            std::ifstream vcf_input;
            ebi::util::open_file(vcf_input, vcf_path);
            is_valid = ebi::vcf::assembly_checker::check_vcf_ref(vcf_input, vcf_path, fasta_path, assembly_report,
                                                                 outputs, requireGenbank);
        }

        return !is_valid; // A valid file returns an exit code 0
    } catch (std::invalid_argument const & ex) {
        BOOST_LOG_TRIVIAL(error) << ex.what();
        return 1;
    } catch (std::runtime_error const & ex) {
        BOOST_LOG_TRIVIAL(error) << "The assembly checking could not be completed: " << ex.what();
        return 1;
    } catch (std::exception const &ex) {
        BOOST_LOG_TRIVIAL(error) << ex.what();
        return 1;
    }

}
