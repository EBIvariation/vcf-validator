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
          auto folder = boost::filesystem::path("test/input_files/v4.3/compressed_files/non_readable");
          std::vector<boost::filesystem::path> v;
          copy(boost::filesystem::directory_iterator(folder), boost::filesystem::directory_iterator(), back_inserter(v));
          folder = boost::filesystem::path("test/input_files/v4.3/compressed_files/readable");
          copy(boost::filesystem::directory_iterator(folder), boost::filesystem::directory_iterator(), back_inserter(v));

          for (auto path : v)
          {
              CHECK(vcf::is_compressed_extension(path.string()) != vcf::NO_EXT);
          }
      }

      SECTION("Compressed file streams")
      {
          auto folder = boost::filesystem::path("test/input_files/v4.3/compressed_files/non_readable");
          std::vector<boost::filesystem::path> v;
          copy(boost::filesystem::directory_iterator(folder), boost::filesystem::directory_iterator(), back_inserter(v));
          folder = boost::filesystem::path("test/input_files/v4.3/compressed_files/readable");
          copy(boost::filesystem::directory_iterator(folder), boost::filesystem::directory_iterator(), back_inserter(v));

          std::vector<char> line;
          line.reserve(ebi::vcf::default_line_buffer_size);

          for (auto path : v)
          {
              std::ifstream input{path.string()};
              ebi::util::readline(input, line);
              CHECK(vcf::is_compressed_magic_num(line) != vcf::NO_EXT);
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
              CHECK(vcf::is_compressed_extension(path.string()) == vcf::NO_EXT);
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
              CHECK(vcf::is_compressed_magic_num(line) == vcf::NO_EXT);
          }
      }
  }
}
