/**
 * Copyright 2015-2017 EMBL - European Bioinformatics Institute
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

#include "parser_test_aux.hpp"

namespace ebi
{

  TEST_CASE("Files that fail the validation under specification v4.3", "[failed]")
  {
      auto folder = boost::filesystem::path("test/input_files/v4.3/failed");
      std::vector<boost::filesystem::path> v;
      copy(boost::filesystem::directory_iterator(folder), boost::filesystem::directory_iterator(), back_inserter(v));

      for (auto path : v)
      {
          SECTION(path.string())
          {
              CHECK_FALSE(is_valid(path.string()));
          }
      }
  }

  TEST_CASE("Compressed files that throw std::invalid_argument", "[compressed]")
  {
      auto folder = boost::filesystem::path("test/input_files/v4.3/compressed_files");
      std::vector<boost::filesystem::path> v;
      copy(boost::filesystem::directory_iterator(folder), boost::filesystem::directory_iterator(), back_inserter(v));

      for (auto path : v)
      {
          SECTION(path.string())
          {
              CHECK_THROWS_AS(is_valid(path.string()), std::invalid_argument);
          }
      }
  }

  TEST_CASE("Files that pass the validation under specification v4.3", "[passed]")
  {
      auto folder = boost::filesystem::path("test/input_files/v4.3/passed");
      std::vector<boost::filesystem::path> v;
      copy(boost::filesystem::directory_iterator(folder), boost::filesystem::directory_iterator(), back_inserter(v));

      for (auto path : v)
      {
          SECTION(path.string())
          {
              CHECK(is_valid(path.string()));
          }
      }
  }

}

