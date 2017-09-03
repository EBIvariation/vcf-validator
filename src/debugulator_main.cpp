/**
 * Copyright 2017 EMBL - European Bioinformatics Institute
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

#include <fstream>
#include <string>

#include <boost/program_options.hpp>

#include "util/logger.hpp"
#include "vcf/odb_report.hpp"
#include "vcf/string_constants.hpp"
#include "vcf/debugulator.hpp"

namespace
{
  namespace po = boost::program_options;

  enum class ValidationLevel
  {
      error, warning, stop
  };

  po::options_description build_command_line_options()
  {
      po::options_description description("Usage: vcf-debugulator [OPTIONS] [< input_file]\nAllowed options");

      description.add_options()
              (ebi::vcf::HELP_OPTION, "Display this help")
              (ebi::vcf::INPUT_OPTION, po::value<std::string>()->default_value(ebi::vcf::STDIN), "Path to the input VCF file, or stdin")
              (ebi::vcf::ERRORS_OPTION, po::value<std::string>(), "Path to the errors report from the input VCF file")
              (ebi::vcf::LEVEL_OPTION, po::value<std::string>()->default_value(ebi::vcf::WARNING), "Validation level (error, warning, stop)")
              (ebi::vcf::OUTPUT_OPTION, po::value<std::string>()->default_value(ebi::vcf::STDOUT), "Write to a file or stdout")
      ;

      return description;
  }

  int check_command_line_options(po::variables_map const &vm, po::options_description const &desc)
  {
      if (vm.count(ebi::vcf::HELP)) {
          std::cout << desc << std::endl;
          return -1;
      }

      std::string level = vm[ebi::vcf::LEVEL].as<std::string>();
      if (level != ebi::vcf::ERROR && level != ebi::vcf::WARNING && level != ebi::vcf::STOP) {
          std::cout << desc << std::endl;
          ebi::util::logger_error("Please choose one of the accepted validation levels");
          return 1;
      }

      if (!vm.count(ebi::vcf::ERRORS)) {
          std::cout << desc << std::endl;
          ebi::util::logger_error("Please specify the path to the errors report (--errors)");
          return 1;
      }

      return 0;
  }
}

int main(int argc, char **argv)
{
    namespace po = boost::program_options;

    po::options_description desc = build_command_line_options();
    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    int check_options = check_command_line_options(vm, desc);
    if (check_options < 0) { return 0; }
    if (check_options > 0) { return check_options; }

    try {
        auto input_path = vm[ebi::vcf::INPUT].as<std::string>();
        auto level = vm[ebi::vcf::LEVEL].as<std::string>();
        auto errors = vm[ebi::vcf::ERRORS].as<std::string>();
        auto output_path = vm[ebi::vcf::OUTPUT].as<std::string>();


        std::ifstream input_file;
        if (input_path != ebi::vcf::STDIN) {
            input_file.open(input_path.c_str());
            if (!input_file) {
                throw std::runtime_error{"Couldn't open file " + input_path};
            }
        } else {
            ebi::util::logger_info("Reading from standard input...");
        }

        std::ofstream output_file;
        if (output_path != ebi::vcf::STDOUT) {
            output_file.open(output_path.c_str());
            if (!output_file) {
                throw std::runtime_error{"Couldn't open file " + output_path};
            }
        } else {
            ebi::util::logger_info("Writing to standard output...");
        }

        ebi::vcf::OdbReportRW errorDAO{errors};

        auto &input_stream = input_path == ebi::vcf::STDIN ? std::cin : input_file;
        auto &output_stream = output_path == ebi::vcf::STDOUT ? std::cout : output_file;

        ebi::vcf::debugulator::fix_vcf_file(input_stream, errorDAO, output_stream);

        return 0;

    } catch (std::exception const &ex) {
        ebi::util::logger_info("Aborting execution, error: " + std::string(ex.what()));
        return 1;
    }
}
