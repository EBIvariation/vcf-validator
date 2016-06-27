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

#include <boost/filesystem.hpp>

#include "catch/catch.hpp"

#include "parser_test_aux.hpp"
#include "vcf/debugulator.hpp"
#include "vcf/report_writer.hpp"
#include "vcf/sqlite_report.hpp"

namespace ebi
{
  bool is_valid_vcf_file(std::istream &input,
                         ebi::vcf::Parser &validator,
                         std::vector<std::unique_ptr<ebi::vcf::ReportWriter>> &outputs)
  {
      std::vector<char> line;
      line.reserve(default_line_buffer_size);

      while (ebi::util::readline(input, line)) {
          validator.parse(line);

          for (auto &error : *validator.errors()) {
              for (auto &output : outputs) {
                  output->write_error(*error);
              }
          }
          for (auto &error : *validator.warnings()) {
              for (auto &output : outputs) {
                  output->write_warning(*error);
              }
          }
      }

      validator.end();

      return validator.is_valid();
  }

  TEST_CASE("Fixing a VCF with duplicates", "[debugulator]")
  {
      auto path = boost::filesystem::path("test/input_files/v4.1/failed/failed_body_duplicated_000.vcf");
      SECTION(path.string())
      {
          std::ifstream file{path.c_str()};
          if (not file) {
              throw std::runtime_error{"test file not found: " + path.string()};
          }

          auto source = ebi::vcf::Source{path.string(), ebi::vcf::InputFormat::VCF_FILE_VCF, ebi::vcf::Version::v41};
          auto records = std::vector<ebi::vcf::Record>{};

          auto validator = ebi::vcf::FullValidator_v41{
                  std::make_shared<ebi::vcf::Source>(source),
                  std::make_shared<std::vector<ebi::vcf::Record>>(records)};

          // here we check that the file is not valid:
          // file: ifstream from test files
          // outputs: ReportWriters (one SqliteReportRW writing to database "errors_before")
          auto db_path = boost::filesystem::path{"/tmp/"} / path.filename();
          db_path += ".debugulator_test.errors_before.db";
          boost::filesystem::remove(db_path);   // make sure the dbs doesn't exist from previous runs
          auto output = new ebi::vcf::SqliteReportRW{db_path.string()};
          std::vector<std::unique_ptr<ebi::vcf::ReportWriter>> outputs;
          outputs.emplace_back(output);
          CHECK_FALSE(is_valid_vcf_file(file, validator, outputs));


          // now we fix the file
          // file: rewind the same ifstream as before
          // output: SqliteReportRW to read the errors. it must be flushed before this
          // fixed_vcf: writing result vcf to a stringstream in memory
          file.clear();
          file.seekg(0);
          output->flush();
          std::stringstream fixed_vcf;
          vcf::debugulator::fix_vcf_file(file, *output, fixed_vcf);
          file.close();

          // here we check that the fixed file is valid:
          // fixed_vcf: stringstream the debugulator::fix_vcf_file wrote
          // outputs: ReportWriters (one SqliteReportRW writing to database "errors_after")
          fixed_vcf.seekg(0);
          auto validator2 = ebi::vcf::FullValidator_v41{
                  std::make_shared<ebi::vcf::Source>(source),
                  std::make_shared<std::vector<ebi::vcf::Record>>(records)};
          auto db_path_after = boost::filesystem::path{"/tmp/"} / path.filename();
          db_path_after += ".debugulator_test.errors_after.db";
          boost::filesystem::remove(db_path_after);   // make sure the dbs doesn't exist from previous runs
          auto output_after = new ebi::vcf::SqliteReportRW{db_path_after.string()};
          outputs.clear();
          outputs.emplace_back(output_after);
          bool successfully_fixed = is_valid_vcf_file(fixed_vcf, validator2, outputs);

          CHECK(successfully_fixed);

          auto fixed_vcf_path = boost::filesystem::path{"/tmp/"} / path.filename();
          fixed_vcf_path += ".debugulator_test.fixed.vcf";
          boost::filesystem::remove(fixed_vcf_path);
          if (not successfully_fixed) {
              // dump fixed file to manually inspect
              std::ofstream fixed_file{fixed_vcf_path.string()};
              fixed_file << fixed_vcf.str();
              fixed_file.close();
              std::cout << "This test failed, you can see the related data at: " << db_path_after.string() << ", ";
              std::cout << db_path.string() << " and " << fixed_vcf_path.string() << std::endl;
          } else {
              // clean report dbs
              boost::filesystem::remove(db_path);
              boost::filesystem::remove(db_path_after);
          }
      }
  }
}

