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

#include "catch/catch.hpp"

#include "vcf/validator.hpp"

namespace ebi
{

  TEST_CASE("Tests for compressed files", "[compressed]")
  {
      SECTION("File with extensions of compressed files")
      {
          auto folder = boost::filesystem::path("test/input_files/v4.3/compressed_files");
          std::vector<boost::filesystem::path> v;
          copy(boost::filesystem::directory_iterator(folder), boost::filesystem::directory_iterator(), back_inserter(v));

          for (auto path : v)
          {
              CHECK(vcf::is_compressed_extension(path.string()));
          }
      }

      SECTION("Compressed file streams")
      {
          auto folder = boost::filesystem::path("test/input_files/v4.3/compressed_files");
          std::vector<boost::filesystem::path> v;
          copy(boost::filesystem::directory_iterator(folder), boost::filesystem::directory_iterator(), back_inserter(v));

          for (auto path : v)
          {
              std::ifstream input{path.string()};
              CHECK(vcf::is_compressed_magic_num(input));
          }
      }
  }

  TEST_CASE("Tests for non-compressed files", "[non-compressed]")
  {
      SECTION("File without extensions of compressed files")
      {
          auto folder = boost::filesystem::path("test/input_files/v4.3/passed");
          std::vector<boost::filesystem::path> v;
          copy(boost::filesystem::directory_iterator(folder), boost::filesystem::directory_iterator(), back_inserter(v));
          folder = boost::filesystem::path("test/input_files/v4.3/failed");
          copy(boost::filesystem::directory_iterator(folder), boost::filesystem::directory_iterator(), back_inserter(v));

          for (auto path : v)
          {
              CHECK_FALSE(vcf::is_compressed_extension(path.string()));
          }
      }

      SECTION("Non-Compressed file streams")
      {
          auto folder = boost::filesystem::path("test/input_files/v4.3/passed");
          std::vector<boost::filesystem::path> v;
          copy(boost::filesystem::directory_iterator(folder), boost::filesystem::directory_iterator(), back_inserter(v));
          folder = boost::filesystem::path("test/input_files/v4.3/failed");
          copy(boost::filesystem::directory_iterator(folder), boost::filesystem::directory_iterator(), back_inserter(v));

          for (auto path : v)
          {
              std::ifstream input{path.string()};
              CHECK_FALSE(vcf::is_compressed_magic_num(input));

              std::vector<char> line;
              ebi::util::readline(input, line);

              std::ifstream input_dup{path.string()};
              std::vector<char> line_dup;
              ebi::util::readline(input_dup, line_dup);

              std::string str{line.begin(), line.end()};
              std::string str_dup{line_dup.begin(), line_dup.end()};
              CHECK(str == str_dup);
          }
      }
  }
}
