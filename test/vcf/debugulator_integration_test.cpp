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

#include <boost/filesystem.hpp>

#include "catch/catch.hpp"

#include "vcf/validator.hpp"
#include "vcf/odb_report.hpp"
#include "vcf/debugulator.hpp"
#include "test_utils.hpp"

namespace ebi
{
  static const std::string BEFORE_TAG = "before";
  static const std::string AFTER_TAG = "after";

  bool validate(std::istream &file, const boost::filesystem::path &path, std::string report_tag)
  {
      auto db_path = boost::filesystem::temp_directory_path() / path.filename();
      db_path += ".debugulator_test." + report_tag + ".db";
      boost::filesystem::remove(db_path);   // make sure the db doesn't exist from previous runs

      auto report = new ebi::vcf::OdbReportRW{db_path.string()};
      std::vector<std::unique_ptr<ebi::vcf::ReportWriter>> reports;
      reports.emplace_back(report);

      return vcf::is_valid_vcf_file(file, path.string(), vcf::ValidationLevel::warning, reports, vcf::AdditionalChecks());
  }

  std::tuple<std::unique_ptr<std::stringstream>, long> fix(const boost::filesystem::path &path, std::string report_tag)
  {
      std::ifstream file{path.c_str()};

      // report: SqliteReportRW to read the errors. the DB must be flushed before this
      auto db_path = boost::filesystem::temp_directory_path() / path.filename();
      db_path += ".debugulator_test." + report_tag + ".db";
      ebi::vcf::OdbReportRW report{db_path.string()};

      std::unique_ptr<std::stringstream> fixed_vcf{new std::stringstream{}}; // writing result vcf to a stringstream in memory

      vcf::debugulator::fix_vcf_file(file, report, *fixed_vcf);
      file.close();
      fixed_vcf->seekg(0);
      long fixed_vcf_lines = count_lines(*fixed_vcf);
      fixed_vcf->seekg(0);

      return std::tuple<std::unique_ptr<std::stringstream>, long>(std::move(fixed_vcf), fixed_vcf_lines);
  }

  std::string handle_test_results(const boost::filesystem::path &path,
                                  bool successfully_fixed, const std::stringstream &fixed_vcf)
  {
      std::stringstream debug_message;
      boost::filesystem::path fixed_vcf_path, db_path, db_path_after;
      boost::filesystem::path base_path = boost::filesystem::temp_directory_path() / path.filename();
      fixed_vcf_path = db_path = db_path_after = base_path;
      fixed_vcf_path += ".debugulator_test.fixed.vcf";
      db_path += ".debugulator_test." + BEFORE_TAG + ".db";
      db_path_after += ".debugulator_test." + AFTER_TAG + ".db";

      boost::filesystem::remove(fixed_vcf_path);

      if (!successfully_fixed) {
          // dump fixed file to manually inspect
          std::ofstream fixed_file{fixed_vcf_path.string()};
          fixed_file << fixed_vcf.str();
          fixed_file.close();
          debug_message << "This test failed, you can see the related data at: \n" << db_path.string() << "\n";
          debug_message << db_path_after.string() << "\n" << fixed_vcf_path.string() << std::endl;
      } else {
          // clean report dbs
          boost::filesystem::remove(db_path);
          boost::filesystem::remove(db_path_after);
      }

      return debug_message.str();
  }

  TEST_CASE("Fixing a VCF with duplicates", "[debugulator]")
  {
      bool first_validation, second_validation;
      std::string debug_message;
      std::unique_ptr<std::stringstream> fixed_vcf;
      long lines;

      for (size_t i = 1; i <= 4; ++i) {
          auto path = boost::filesystem::path("test/input_files/v4." + std::to_string(i) + "/failed/failed_body_duplicated_001.vcf");
          SECTION(path.string()) {
              std::ifstream file{path.c_str()};
              first_validation = validate(file, path, BEFORE_TAG);
              REQUIRE_FALSE(first_validation);
              std::tie(fixed_vcf, lines) = fix(path, BEFORE_TAG);
              second_validation = validate(*fixed_vcf, path, AFTER_TAG);
              debug_message = handle_test_results(path, second_validation, *fixed_vcf);
              INFO(debug_message);
              REQUIRE(second_validation);
              REQUIRE(lines == 6);
          }
      }
  }

  TEST_CASE("Fixing a VCF with wrong INFO fields", "[debugulator]")
  {
      boost::filesystem::path path;
      bool first_validation, second_validation;
      std::string debug_message;
      std::unique_ptr<std::stringstream> fixed_vcf;
      long lines;

      for (size_t i = 1; i <= 4; ++i) {
          // syntax error, AC must be a positive integer
          path = boost::filesystem::path(
                  "test/input_files/v4." + std::to_string(i) + "/failed/failed_body_info_036.vcf");
          SECTION(path.string()) {
              std::ifstream file{path.c_str()};
              first_validation = validate(file, path, BEFORE_TAG);
              REQUIRE_FALSE(first_validation);
              std::tie(fixed_vcf, lines) = fix(path, BEFORE_TAG);
              second_validation = validate(*fixed_vcf, path, AFTER_TAG);
              debug_message = handle_test_results(path, second_validation, *fixed_vcf);
              INFO(debug_message);
              REQUIRE(second_validation);
              REQUIRE(lines == 11);
          }

          // semantic error, the number of values doesn't match the description in the meta section
          path = boost::filesystem::path(
                  "test/input_files/v4." + std::to_string(i) + "/failed/failed_body_info_031.vcf");
          SECTION(path.string()) {
              std::ifstream file{path.c_str()};
              first_validation = validate(file, path, BEFORE_TAG);
              REQUIRE_FALSE(first_validation);
              std::tie(fixed_vcf, lines) = fix(path, BEFORE_TAG);
              second_validation = validate(*fixed_vcf, path, AFTER_TAG);
              debug_message = handle_test_results(path, second_validation, *fixed_vcf);
              INFO(debug_message);
              REQUIRE(second_validation);
              REQUIRE(lines == 5);
          }
      }
  }

  TEST_CASE("Fixing a VCF with wrong SAMPLE fields", "[debugulator]")
  {
      boost::filesystem::path path;
      bool first_validation, second_validation;
      std::string debug_message;
      std::unique_ptr<std::stringstream> fixed_vcf;
      long lines;

      for (size_t i = 1; i <= 4; ++i) {
          // syntax error, alleles are not digits
          path = boost::filesystem::path("test/input_files/v4." + std::to_string(i) + "/failed/failed_body_sample_000.vcf");
          SECTION(path.string()) {
              std::ifstream file{path.c_str()};
              first_validation = validate(file, path, BEFORE_TAG);
              REQUIRE_FALSE(first_validation);
              std::tie(fixed_vcf, lines) = fix(path, BEFORE_TAG);
              second_validation = validate(*fixed_vcf, path, AFTER_TAG);
              debug_message = handle_test_results(path, second_validation, *fixed_vcf);
              INFO(debug_message);
              REQUIRE(second_validation);
              REQUIRE(lines == 4);
          }

          // semantic error, the number of values doesn't match the description in the meta section
          path = boost::filesystem::path("test/input_files/v4." + std::to_string(i) + "/failed/failed_body_sample_005.vcf");
          SECTION(path.string()) {
              std::ifstream file{path.c_str()};
              first_validation = validate(file, path, BEFORE_TAG);
              REQUIRE_FALSE(first_validation);
              std::tie(fixed_vcf, lines) = fix(path, BEFORE_TAG);
              second_validation = validate(*fixed_vcf, path, AFTER_TAG);
              debug_message = handle_test_results(path, second_validation, *fixed_vcf);
              INFO(debug_message);
              REQUIRE(second_validation);
              REQUIRE(lines == 5);
          }

          // semantic error, the number of values doesn't match the description in the meta section
          path = boost::filesystem::path("test/input_files/v4." + std::to_string(i) + "/failed/failed_body_sample_006.vcf");
          SECTION(path.string()) {
              std::ifstream file{path.c_str()};
              first_validation = validate(file, path, BEFORE_TAG);
              REQUIRE_FALSE(first_validation);
              std::tie(fixed_vcf, lines) = fix(path, BEFORE_TAG);
              second_validation = validate(*fixed_vcf, path, AFTER_TAG);
              debug_message = handle_test_results(path, second_validation, *fixed_vcf);
              INFO(debug_message);
              REQUIRE(second_validation);
              REQUIRE(lines == 5);
          }
      }
  }
}
