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

#include <memory>
#include <iostream>
#include <fstream>

#include <boost/filesystem.hpp>
#include <vcf/output.hpp>

#include "catch/catch.hpp"
#include "sqlite/sqlite3.h"

#include "vcf/file_structure.hpp"
#include "vcf/validator.hpp"
#include "vcf/error.hpp"


namespace ebi
{
  size_t const default_line_buffer_size = 64 * 1024;

  template <typename Container>
  std::istream & readline(std::istream & stream, Container & container)
  {
      char c;

      container.clear();

      do {
          stream.get(c);
          container.push_back(c);
      } while (!stream.eof() && c != '\n');

      return stream;
  }

  bool is_valid(std::string path, ebi::vcf::Output &output)
  {
      std::ifstream input{path};
      if (!input) {
          throw std::runtime_error("file not found: " + path);
      }
      auto source = ebi::vcf::Source{path, ebi::vcf::InputFormat::VCF_FILE_VCF, ebi::vcf::Version::v41};
      auto records = std::vector<ebi::vcf::Record>{};

      auto validator = ebi::vcf::FullValidator_v41{
          std::make_shared<ebi::vcf::Source>(source),
          std::make_shared<std::vector<ebi::vcf::Record>>(records)};

      std::vector<char> line;
      line.reserve(default_line_buffer_size);

      while (readline(input, line)) {
          validator.parse(line);
          for (auto error : *validator.errors()) {
              output.write_error(*error);
          }
          for (auto warn : *validator.warnings()) {
              output.write_warning(*warn);
          }
      }

      validator.end();

      return validator.is_valid();
  }

  TEST_CASE("output errors to sqlite", "[output]")
  {
      auto path = boost::filesystem::path("test/input_files/failed/failed_fileformat_000.vcf");

      std::string db_name = path.string() + ".errors.db";
      sqlite3* db;

      SECTION(path.string())
      {
          {
              std::shared_ptr<ebi::vcf::Output> output{std::make_shared<ebi::vcf::SqliteOutput>(db_name)};
              CHECK_FALSE(is_valid(path.string(), *output));
          }
          int rc = sqlite3_open(db_name.c_str(), &db);
          if(rc != SQLITE_OK) {
              sqlite3_close(db);
              throw std::runtime_error(std::string("Can't open database: ") + sqlite3_errmsg(db));
          }

          char *zErrMsg = NULL;
          int count_errors = -1;
          rc = sqlite3_exec(db, "SELECT count(*) FROM Errors", [](void* count, int columns, char**values, char**names) {
              if (values[0] != NULL) {
                  *(int*)count = std::stoi(values[0]);
              }
              return 0;
          }, &count_errors, &zErrMsg);
          if (rc != SQLITE_OK) {
              std::string error_message = std::string("Can't read database: ") + zErrMsg;
              sqlite3_free(zErrMsg);
              throw std::runtime_error(error_message);
          }
          
          int count_warnings = -1;
          rc = sqlite3_exec(db, "SELECT count(*) FROM Warnings", [](void* count, int columns, char**values, char**names) {
              if (values[0] != NULL) {
                  *(int*)count = std::stoi(values[0]);
              }
              return 0;
          }, &count_warnings, &zErrMsg);
          if (rc != SQLITE_OK) {
              std::string error_message = std::string("Can't read database: ") + zErrMsg;
              sqlite3_free(zErrMsg);
              throw std::runtime_error(error_message);
          }

          sqlite3_close(db);
          boost::filesystem::path db_file{db_name};
          boost::filesystem::remove(db_file);
          CHECK(count_errors == 1);
          CHECK(count_warnings == 2);
          CHECK_FALSE(boost::filesystem::exists(db_file));
      }

  }
}
