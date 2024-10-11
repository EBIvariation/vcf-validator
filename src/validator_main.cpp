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

#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

#include <boost/program_options.hpp>
#include <boost/filesystem/operations.hpp>

#include "cmake_config.hpp"
#include "util/cli_utils.hpp"
#include "util/logger.hpp"
#include "vcf/file_structure.hpp"
#include "vcf/report_writer.hpp"
#include "vcf/summary_report_writer.hpp"
#include "vcf/validator.hpp"

namespace
{
    namespace po = boost::program_options;

    const std::string version_info = "vcf_validator version " + std::to_string(VERSION_MAJOR) + "."
                                     + std::to_string(VERSION_MINOR) + "." + std::to_string(VERSION_PATCH);

    po::options_description build_command_line_options()
    {
        po::options_description description(version_info + "\n\nUsage: vcf-validator [OPTIONS] [< input_file]\nAllowed options");

        description.add_options()
            (ebi::vcf::HELP_OPTION, "Display this help")
            (ebi::vcf::VERSION_OPTION, "Display version of the validator")
            (ebi::vcf::INPUT_OPTION, po::value<std::string>()->default_value(ebi::vcf::STDIN), "Path to the input VCF file, or stdin")
            (ebi::vcf::LEVEL_OPTION, po::value<std::string>()->default_value(ebi::vcf::WARNING_LEVEL), "Validation level (error, warning, stop)")
            (ebi::vcf::REPORT_OPTION, po::value<std::string>()->default_value(ebi::vcf::SUMMARY), "Comma separated values for types of reports (summary, text)")
            (ebi::vcf::OUTDIR_OPTION, po::value<std::string>()->default_value(""), "Output directory")
            (ebi::vcf::CHECK_EVIDENCE, "Flag to check genotypes or allele frequencies are present")
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

        std::string level = vm[ebi::vcf::LEVEL].as<std::string>();
        if (level != ebi::vcf::ERROR_LEVEL && level != ebi::vcf::WARNING_LEVEL && level != ebi::vcf::STOP_LEVEL) {
            std::cout << desc << std::endl;
            BOOST_LOG_TRIVIAL(error) << "Please choose one of the accepted validation levels";
            return 1;
        }

        return 0;
    }

    ebi::vcf::ValidationLevel get_validation_level(std::string const & level_str)
    {
        if (level_str == ebi::vcf::ERROR_LEVEL) {
            return ebi::vcf::ValidationLevel::error;
        } else if (level_str == ebi::vcf::WARNING_LEVEL) {
            return ebi::vcf::ValidationLevel::warning;
        } else if (level_str == ebi::vcf::STOP_LEVEL) {
            return ebi::vcf::ValidationLevel::stop;
        }

        throw std::invalid_argument{"Please choose one of the accepted validation levels"};
    }

    std::vector<std::unique_ptr<ebi::vcf::ReportWriter>> get_outputs(std::string const &output_str, std::string const &input)
    {
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

        auto epoch = std::chrono::system_clock::now().time_since_epoch();
        auto timestamp = std::chrono::duration_cast<std::chrono::milliseconds>(epoch).count();
        for (auto out : outs) {
            if (out == ebi::vcf::TEXT || out == ebi::vcf::SUMMARY) {
                std::string filetype = "txt";
                std::string errortype = (out == ebi::vcf::SUMMARY) ? "errors_summary" : "errors";
                std::string filename = input + "." + errortype + "." + std::to_string(timestamp) + "." + filetype;
                boost::filesystem::path file{filename};
                if (boost::filesystem::exists(file)) {
                    throw std::runtime_error{"Report file already exists on " + filename + ", please delete it or rename it"};
                } else if (out == ebi::vcf::TEXT) {
                    outputs.emplace_back(new ebi::vcf::FileReportWriter(filename));
                } else {
                    outputs.emplace_back(new ebi::vcf::SummaryReportWriter(filename));
                }
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

    bool is_valid;
    try {
        auto path = vm[ebi::vcf::INPUT].as<std::string>();
        auto level = vm[ebi::vcf::LEVEL].as<std::string>();
        ebi::vcf::ValidationLevel validationLevel = get_validation_level(level);
        auto outdir = ebi::util::get_output_path(vm[ebi::vcf::OUTDIR].as<std::string>(), path);
        auto outputs = get_outputs(vm[ebi::vcf::REPORT].as<std::string>(), outdir);
        bool checkEvidence = vm.count(ebi::vcf::CHECK_EVIDENCE) >= 1;
        ebi::vcf::AdditionalChecks additionalChecks { checkEvidence };

        if (path == ebi::vcf::STDIN) {
            BOOST_LOG_TRIVIAL(info) << "Reading from standard input...";
            is_valid = ebi::vcf::is_valid_vcf_file(std::cin, path, validationLevel, outputs, additionalChecks);
        } else {
            BOOST_LOG_TRIVIAL(info) << "Reading from input file...";
            std::ifstream input{path};
            if (!input) {
                throw std::runtime_error{"Couldn't open file " + path};
            } else {
                is_valid = ebi::vcf::is_valid_vcf_file(input, path, validationLevel, outputs, additionalChecks);
            }
        }

        std::string report_result = "According to the VCF specification, the input file is " + std::string(is_valid ? "" : "not ") + "valid";
        for (auto & output : outputs) {
            BOOST_LOG_TRIVIAL(info) << output->get_report_message();
            output->write_message(report_result);
        }
        BOOST_LOG_TRIVIAL(info) << report_result;
        return !is_valid; // A valid file returns an exit code 0

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
