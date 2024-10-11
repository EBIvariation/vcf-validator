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

  TEST_CASE("Files that fail the validation under specification v4.4", "[failed]")
  {
      auto folder = boost::filesystem::path("test/input_files/v4.4/failed");
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

  TEST_CASE("Files that pass the validation under specification v4.4", "[passed]")
  {
      auto folder = boost::filesystem::path("test/input_files/v4.4/passed");
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

  TEST_CASE("Compressed files that throw std::invalid_argument v4.4", "[compressed]")
  {
      auto folder = boost::filesystem::path("test/input_files/v4.4/compressed_files/non_readable");
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

  TEST_CASE("Compressed files that do not throw std::invalid_argument v4.4", "[compressed]")
  {
      std::vector<boost::filesystem::path> v;
      auto pass_folder = boost::filesystem::path("test/input_files/v4.4/compressed_files/readable/passed");
      copy(boost::filesystem::directory_iterator(pass_folder), boost::filesystem::directory_iterator(), back_inserter(v));
      auto fail_folder = boost::filesystem::path("test/input_files/v4.4/compressed_files/readable/failed");
      copy(boost::filesystem::directory_iterator(fail_folder), boost::filesystem::directory_iterator(), back_inserter(v));

      for (auto path : v)
      {
          SECTION(path.string())
          {
              CHECK_NOTHROW(is_valid(path.string()));
          }
      }
  }

  TEST_CASE("Files to validate evidence flag under specification v4.4", "[evidence]")
  {
      SECTION("Without genotypes or frequencies") {
          auto folder = boost::filesystem::path("test/input_files/v4.4/evidence/failed");
          std::vector<boost::filesystem::path> v;
          copy(boost::filesystem::directory_iterator(folder),
               boost::filesystem::directory_iterator(),
               back_inserter(v));

          for (auto path : v)
          {
              SECTION((path.string() + " Validate evidence"))
              {
                  CHECK_FALSE(is_valid(path.string(), {true}));
              }
              SECTION(path.string() + " Don't validate evidence")
              {
                  CHECK(is_valid(path.string(), {false}));
              }
          }
      }

      SECTION("With genotypes or frequencies") {
          auto folder = boost::filesystem::path("test/input_files/v4.4/evidence/passed");
          std::vector<boost::filesystem::path> v;
          copy(boost::filesystem::directory_iterator(folder),
               boost::filesystem::directory_iterator(),
               back_inserter(v));

          for (auto path : v)
          {
              SECTION(path.string() + " Validate evidence")
              {
                  CHECK(is_valid(path.string(), {true}));
              }
              SECTION(path.string() + " Don't validate evidence")
              {
                  CHECK(is_valid(path.string(), {false}));
              }
          }
      }
  }
}

