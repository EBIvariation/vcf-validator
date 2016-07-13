/**
 * Copyright 2015-2016 EMBL - European Bioinformatics Institute
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


#include "catch/catch.hpp"

#include "vcf/debugulator.hpp"

namespace ebi
{
  TEST_CASE("Fixing errors", "[debugulator]")
  {
      SECTION("Fix duplicates")
      {
          size_t line_number = 8;
          std::string message{"testing errors"};
          ebi::vcf::DuplicationError test_error{line_number, message};

          std::string string_line = "line with duplicate variant";
          std::vector<char> line{string_line.begin(), string_line.end()};

          std::stringstream ss;
          ss << "previous line";
          size_t previous_size = ss.str().size();

          vcf::Fixer{ss}.fix(line_number, line, test_error);

          // the fix for duplicated variants is avoiding to write that line
          CHECK(ss.str().size() == previous_size);
      }
  }
}

