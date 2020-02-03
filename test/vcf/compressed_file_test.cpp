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
#include "parser_test_aux.hpp"

#include "vcf/validator.hpp"

namespace ebi
{

  TEST_CASE("Tests for compressed files", "[compressed]")
  {
      SECTION("File with extensions of compressed files")
      {
          std::vector<boost::filesystem::path> v;

          auto folder = boost::filesystem::path("test/input_files/v4.3/compressed_files/non_readable");
          copy(boost::filesystem::directory_iterator(folder), boost::filesystem::directory_iterator(), back_inserter(v));
          folder = boost::filesystem::path("test/input_files/v4.3/compressed_files/readable/passed");
          copy(boost::filesystem::directory_iterator(folder), boost::filesystem::directory_iterator(), back_inserter(v));
          folder = boost::filesystem::path("test/input_files/v4.3/compressed_files/readable/failed");
          copy(boost::filesystem::directory_iterator(folder), boost::filesystem::directory_iterator(), back_inserter(v));

          for (auto path : v)
          {
              SECTION(path.string())
              {
                  CHECK(vcf::get_compression_from_extension(path.string()) != vcf::NO_EXT);
              }
          }
      }

      SECTION("Compressed file streams")
      {
          std::vector<boost::filesystem::path> v;

          auto folder = boost::filesystem::path("test/input_files/v4.3/compressed_files/non_readable");
          copy(boost::filesystem::directory_iterator(folder), boost::filesystem::directory_iterator(), back_inserter(v));
          folder = boost::filesystem::path("test/input_files/v4.3/compressed_files/readable/passed");
          copy(boost::filesystem::directory_iterator(folder), boost::filesystem::directory_iterator(), back_inserter(v));
          folder = boost::filesystem::path("test/input_files/v4.3/compressed_files/readable/failed");
          copy(boost::filesystem::directory_iterator(folder), boost::filesystem::directory_iterator(), back_inserter(v));

          std::vector<char> line;
          line.reserve(ebi::vcf::default_line_buffer_size);

          for (auto path : v)
          {
              std::ifstream input{path.string()};
              ebi::util::readline(input, line);
              CHECK(vcf::get_compression_from_magic_num(line) != vcf::NO_EXT);
          }
      }

      // TODO: make this test work in windows
#ifndef _WIN32
      SECTION("Passed compressed files")
      {
          std::vector<boost::filesystem::path> v;
          auto folder = boost::filesystem::path("test/input_files/v4.3/compressed_files/readable/passed");
          copy(boost::filesystem::directory_iterator(folder), boost::filesystem::directory_iterator(), back_inserter(v));

          for (auto path : v)
          {
              SECTION(path.string())
              {
                  CHECK(is_valid(path.string()));
              }
          }
      }
#endif // _WIN32

      SECTION("Failed compressed files")
      {
          std::vector<boost::filesystem::path> v;
          auto folder = boost::filesystem::path("test/input_files/v4.3/compressed_files/readable/failed");
          copy(boost::filesystem::directory_iterator(folder), boost::filesystem::directory_iterator(), back_inserter(v));

          for (auto path : v)
          {
              SECTION(path.string())
              {
                  CHECK_FALSE(is_valid(path.string()));
              }
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
              SECTION(path.string())
              {
                  CHECK(vcf::get_compression_from_extension(path.string()) == vcf::NO_EXT);
              }
          }
      }

      SECTION("Non-Compressed file streams")
      {
          auto folder = boost::filesystem::path("test/input_files/v4.3/passed");
          std::vector<boost::filesystem::path> v;
          copy(boost::filesystem::directory_iterator(folder), boost::filesystem::directory_iterator(), back_inserter(v));
          folder = boost::filesystem::path("test/input_files/v4.3/failed");
          copy(boost::filesystem::directory_iterator(folder), boost::filesystem::directory_iterator(), back_inserter(v));

          std::vector<char> line;
          line.reserve(ebi::vcf::default_line_buffer_size);

          for (auto path : v)
          {
              std::ifstream input{path.string()};
              ebi::util::readline(input, line);
              CHECK(vcf::get_compression_from_magic_num(line) == vcf::NO_EXT);
          }
      }
  }
}
