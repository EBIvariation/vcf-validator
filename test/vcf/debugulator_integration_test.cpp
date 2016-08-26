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
#include "vcf/odb_report.hpp"
#include "vcf/debugulator.hpp"

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

  std::tuple<bool, bool, std::string> fix_file(boost::filesystem::path path, vcf::Version version)
  {
      std::ifstream file{path.c_str()};
      if (not file) {
          throw std::runtime_error{"test file not found: " + path.string()};
      }

      auto source = ebi::vcf::Source{path.string(), ebi::vcf::InputFormat::VCF_FILE_VCF, version};
      auto records = std::vector<ebi::vcf::Record>{};


      auto validator = ebi::vcf::build_parser(path.string(), ebi::vcf::ValidationLevel::warning, version);

      // here we check that the file is not valid:
      // file: ifstream from test files
      // reports: ReportWriters (one OdbReportRW writing to database "errors_before")
      auto db_path = boost::filesystem::path{"/tmp/"} / path.filename();
      db_path += ".debugulator_test.errors_before.db";
      boost::filesystem::remove(db_path);   // make sure the dbs doesn't exist from previous runs
      auto report = new ebi::vcf::OdbReportRW{db_path.string()};
      std::vector<std::unique_ptr<ebi::vcf::ReportWriter>> reports;
      reports.emplace_back(report);
      bool first_validation = is_valid_vcf_file(file, *validator, reports);


      // now we fix the file
      // file: rewind the same ifstream as before
      // report: SqliteReportRW to read the errors. it must be flushed before this
      // fixed_vcf: writing result vcf to a stringstream in memory
      file.clear();
      file.seekg(0);
      report->flush();
      std::stringstream fixed_vcf;
      vcf::debugulator::fix_vcf_file(file, *report, fixed_vcf);
      file.close();

      // here we check that the fixed file is valid:
      // fixed_vcf: stringstream the debugulator::fix_vcf_file wrote
      // reports: ReportWriters (one OdbReportRW writing to database "errors_after")
      fixed_vcf.seekg(0);
      auto validator2 = ebi::vcf::build_parser(path.string(), ebi::vcf::ValidationLevel::warning, version);
      auto db_path_after = boost::filesystem::path{"/tmp/"} / path.filename();
      db_path_after += ".debugulator_test.errors_after.db";
      boost::filesystem::remove(db_path_after);   // make sure the dbs doesn't exist from previous runs
      auto output_after = new ebi::vcf::OdbReportRW{db_path_after.string()};
      reports.clear();
      reports.emplace_back(output_after);
      bool successfully_fixed = is_valid_vcf_file(fixed_vcf, *validator2, reports);

      auto fixed_vcf_path = boost::filesystem::path{"/tmp/"} / path.filename();
      fixed_vcf_path += ".debugulator_test.fixed.vcf";
      boost::filesystem::remove(fixed_vcf_path);
      std::stringstream debug_message;
      if (not successfully_fixed) {
          // dump fixed file to manually inspect
          std::ofstream fixed_file{fixed_vcf_path.string()};
          fixed_file << fixed_vcf.str();
          fixed_file.close();
          debug_message << "This test failed, you can see the related data at: \n" << db_path_after.string() << "\n";
          debug_message << db_path.string() << "\n" << fixed_vcf_path.string() << std::endl;
      } else {
          // clean report dbs
          boost::filesystem::remove(db_path);
          boost::filesystem::remove(db_path_after);
      }
      return std::tuple<bool, bool, std::string>{first_validation, successfully_fixed, debug_message.str()};
  }

  TEST_CASE("Fixing a VCF with duplicates", "[debugulator]")
  {
      ebi::vcf::Version version = ebi::vcf::Version::v41;
      for (size_t i = 1; i <= 3; ++i) {
          auto path = boost::filesystem::path("test/input_files/v4." + std::to_string(i) + "/failed/failed_body_duplicated_000.vcf");
          bool first_validation, validation_after_fixing;
          std::string debug_message;
          SECTION(path.string()) {
              std::tie(first_validation, validation_after_fixing, debug_message) = fix_file(path, version);
              CHECK_FALSE(first_validation);
              INFO(debug_message);
              CHECK(validation_after_fixing);
          }
          version = static_cast<ebi::vcf::Version>(i);
      }
  }

  TEST_CASE("Fixing a VCF with wrong INFO fields", "[debugulator]")
  {
      boost::filesystem::path path;
      ebi::vcf::Version version = ebi::vcf::Version::v41;

      for (size_t i = 1; i <= 3; ++i) {
          // syntax error, AC must be a positive integer
          path = boost::filesystem::path("test/input_files/v4." + std::to_string(i) + "/failed/failed_body_info_038.vcf");
          bool first_validation, validation_after_fixing;
          std::string debug_message;
          SECTION(path.string())
          {
              std::tie(first_validation, validation_after_fixing, debug_message) = fix_file(path, version);
              CHECK_FALSE(first_validation);
              INFO(debug_message);
              CHECK(validation_after_fixing);
          }

          // semantic error, the number of values doesn't match the description in the meta section
          path = boost::filesystem::path("test/input_files/v4." + std::to_string(i) + "/failed/failed_body_info_034.vcf");
          SECTION(path.string())
          {
              std::tie(first_validation, validation_after_fixing, debug_message) = fix_file(path, version);
              CHECK_FALSE(first_validation);
              INFO(debug_message);
              CHECK(validation_after_fixing);
          }
          version = static_cast<ebi::vcf::Version>(i);
      }
  }
}
