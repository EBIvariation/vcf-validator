/**
 * Copyright 2016 EMBL - European Bioinformatics Institute
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

#include "vcf/debugulator.hpp"

namespace ebi
{
  namespace vcf
  {
    namespace debugulator
    {
      namespace po = boost::program_options;

      po::options_description build_command_line_options()
      {
          po::options_description description("Usage: vcf-debugulator [OPTIONS] [< input_file]\nAllowed options");

          description.add_options()
                             ("help,h", "Display this help")
                             ("input,i", po::value<std::string>()->default_value("stdin"),
                              "Path to the input VCF file, or stdin")
                             ("errors,e", po::value<std::string>()->required(),
                              "Path to the errors DB from the input VCF file")
                             ("level,l", po::value<std::string>()->default_value("warning"),
                              "Validation level (error, warning, stop)")
                             ("output,o", po::value<std::string>()->default_value("stdout"),
                              "write to a file or stdout");

          return description;
      }

      int check_command_line_options(po::variables_map const &vm, po::options_description const &desc)
      {
          if (vm.count("help")) {
            std::cout << desc << std::endl;
            return -1;
          }

          std::string level = vm["level"].as<std::string>();
          if (level != "error" && level != "warning" && level != "stop") {
            std::cout << desc << std::endl;
            std::cout << "Please choose one of the accepted validation levels" << std::endl;
            return 1;
          }

          return 0;
      }

      ValidationLevel get_validation_level(std::string const &level_str)
      {
          if (level_str == "error") {
            return ValidationLevel::error;
          } else if (level_str == "warning") {
            return ValidationLevel::warning;
          } else if (level_str == "stop") {
            return ValidationLevel::stop;
          }

          throw std::invalid_argument{"Please choose one of the accepted validation levels"};
      }

      bool fix_vcf_file(std::istream &input,
                        ebi::vcf::SqliteReportRW &errorDAO,
                        std::ostream &output)
      {
          std::vector<char> line;
          line.reserve(default_line_buffer_size);

          size_t current_line = 0;  // the first line is the number 1, ParsingState takes this convention too

          size_t errors = errorDAO.count_errors();
          if (errors == 0) {
              throw std::runtime_error{"The errors DB was empty, there are no errors to fix the input"};
          }

          errorDAO.for_each_error([&](std::shared_ptr<ebi::vcf::Error> error) {
              size_t line_index = error->get_line();
              while (current_line < line_index) {

                  // advance input
                  if (!ebi::util::readline(input, line)) {
                      // file finished, return ?
                      return;
                  }
                  current_line++;
                  if (current_line == line_index) {
                      break;
                  }
                  for (auto c : line) {
                      output << c;
                  }
              }

              ebi::vcf::Fixer{line_index, line, output}.fix(*error);
          });

          // close outputs?

          return 0;     // fixer.is_valid();
      }
    }
  }
}

