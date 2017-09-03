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

#include "util/logger.hpp"
#include "vcf/debugulator.hpp"

namespace ebi
{
  namespace vcf
  {
    namespace debugulator
    {
      size_t fix_vcf_file(std::istream &input,
                          ebi::vcf::ReportReader &errorDAO,
                          std::ostream &output)
      {
          std::vector<char> line;
          line.reserve(default_line_buffer_size);

          size_t current_line = 0;  // the first line is the number 1, ParsingState takes this convention too

          size_t errors = errorDAO.count_errors();
          size_t errors_fixed = 0;
          if (errors == 0) {
              ebi::util::logger_info("The errors report was empty, there are no errors to fix the input");
              return 0;
          }

          ebi::vcf::Fixer fixer{output};

          errorDAO.for_each_error([&](std::shared_ptr<ebi::vcf::Error> error) {
              size_t line_index = error->line;
              while (current_line < line_index) {

                  // advance input
                  if (ebi::util::readline(input, line).size() == 0) {
                      throw std::runtime_error("The file was shorter than expected, only "
                                                       + std::to_string(errors_fixed) + "/" + std::to_string(errors)
                                                       + " error reports were processed");
                  }
                  current_line++;
                  if (current_line == line_index) {
                      break;
                  }
                  ebi::util::writeline(output, line);
              }
              fixer.fix(line_index, line, *error);
              ++errors_fixed;
          });

          // advance input from the last error to the end of input
          while (ebi::util::readline(input, line).size() != 0) {
              for (auto c : line) {
                  output << c;
              }
          }

          size_t ignored_errors = fixer.get_ignored_errors();
          if (ignored_errors != 0) {
              ebi::util::logger_info("There were " + std::to_string(ignored_errors)
                                         + " errors that couldn't be automatically fixed");
          }

          return ignored_errors;
      }
    }
  }
}

