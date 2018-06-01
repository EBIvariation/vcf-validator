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

#include "assembly_checker_test_aux.hpp"

namespace ebi
{  

  TEST_CASE("Integration tests", "[assembly_checker]")
  {
      SECTION("Multiple entry, single mismatch")
      {
          std::string folder = "test/input_files/assembly_checker/failed/failed_singlemismatch_multipleentry/";
          std::string file_prefix = get_file_prefix(folder);
          std::string command = get_command(folder, file_prefix);
          if(std::system(command.c_str()) != 0) {
              throw std::runtime_error{"vcf_assembly_checker binary not found"};
          }
          auto output_file = get_output_path(folder, file_prefix);
          CHECK(file_exists(output_file));
          CHECK(count_lines(output_file) == 1);
      }
      SECTION("Multiple entry, multiple mismatch")
      {
          std::string folder = "test/input_files/assembly_checker/failed/failed_multiplemismatch_multipleentry/";
          std::string file_prefix = get_file_prefix(folder);
          std::string command = get_command(folder, file_prefix);
          if(std::system(command.c_str()) != 0) {
              throw std::runtime_error{"vcf_assembly_checker binary not found"};
          }
          auto output_file = get_output_path(folder, file_prefix);
          CHECK(file_exists(output_file));
          CHECK(count_lines(output_file) == 2);
      }
      SECTION("Full sample VCF, all match")
      {
          std::string folder = "test/input_files/assembly_checker/passed/passed_fullsample/";
          std::string file_prefix = get_file_prefix(folder);
          std::string command = get_command(folder, file_prefix);
          if(std::system(command.c_str()) != 0) {
              throw std::runtime_error{"vcf_assembly_checker binary not found"};
          }
          auto output_file = get_output_path(folder, file_prefix);
          CHECK(file_exists(output_file));
          CHECK(is_empty_file(output_file));
      }
  }
}
