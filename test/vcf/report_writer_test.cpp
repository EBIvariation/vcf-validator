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

#include <memory>
#include <iostream>
#include <fstream>

#include <boost/filesystem.hpp>

#include "catch/catch.hpp"

#include "cmake_config.hpp"
#include "vcf/odb_report.hpp"
#include "vcf/file_structure.hpp"
#include "vcf/validator.hpp"
#include "vcf/error.hpp"
#include "vcf/report_writer.hpp"
#include "vcf/summary_report_writer.hpp"
#include "test_utils.hpp"

namespace ebi
{
  const std::string version_info = "vcf_validator version " + std::to_string(VERSION_MAJOR) + "."
                                     + std::to_string(VERSION_MINOR);

  bool is_valid(std::string path, std::unique_ptr<ebi::vcf::ReportWriter> output)
  {
      std::ifstream input{path};
      if (!input) {
          throw std::runtime_error("file not found: " + path);
      }
      std::vector<std::unique_ptr<vcf::ReportWriter>> outputs;
      outputs.push_back(std::move(output));

      return ebi::vcf::is_valid_vcf_file(input, path, vcf::ValidationLevel::warning, outputs);
  }

  TEST_CASE("Unit test: odb", "[output]")
  {

      std::string db_name = "test/input_files/sqlite_test.errors.odb.db";
      ebi::vcf::OdbReportRW errorDAO{db_name, version_info};

      SECTION("Write and count errors") {
          ebi::vcf::Error test_error{1, "testing errors"};
          errorDAO.write_error(test_error);
          errorDAO.write_error(test_error);
          errorDAO.flush();
          size_t count_errors = errorDAO.count_errors();
          size_t count_warnings = errorDAO.count_warnings();
          CHECK(count_errors == 2);
          CHECK(count_warnings == 0);
      }

      SECTION("Write and count warnings")
      {
          ebi::vcf::Error test_error{1, "testing warnings"};
          errorDAO.write_warning(test_error);
          errorDAO.flush();
          size_t count_errors = errorDAO.count_errors();
          size_t count_warnings = errorDAO.count_warnings();
          CHECK(count_errors == 0);
          CHECK(count_warnings == 1);
      }

      SECTION("Write and read errors")
      {
          size_t line = 8;
          std::string message{"testing errors"};
          ebi::vcf::Error test_error{line, message};
          errorDAO.write_error(test_error);
          errorDAO.flush();

          size_t errors_read = 0;
          errorDAO.for_each_error([&](std::shared_ptr<ebi::vcf::Error> error) {
              CHECK(error->line == line);
              CHECK(error->message == message);
              errors_read++;
          });
          CHECK(errors_read == 1);
      }

      SECTION("Write and read warnings")
      {
          size_t line = 10;
          std::string message{"testing warnings"};
          ebi::vcf::Error test_error{line, message};
          errorDAO.write_warning(test_error);
          errorDAO.flush();

          size_t errors_read = 0;
          errorDAO.for_each_warning([&](std::shared_ptr<ebi::vcf::Error> error) {
              CHECK(error->line == line);
              CHECK(error->message == message);
              errors_read++;
          });
          CHECK(errors_read == 1);
      }


      SECTION("Write and read error codes")
      {
          size_t line = 8;
          std::string message{"testing errors"};
          ebi::vcf::Error generic_error{line, message};
          ebi::vcf::MetaSectionError meta_section_error{line, message};
          ebi::vcf::SamplesBodyError samples_body_error{line, message};
          errorDAO.write_error(generic_error);
          errorDAO.write_error(meta_section_error);
          errorDAO.write_error(samples_body_error);
          errorDAO.flush();

          std::vector<std::shared_ptr<ebi::vcf::Error>> errors;
          errorDAO.for_each_error([&](std::shared_ptr<ebi::vcf::Error> error) {
              errors.push_back(error);
          });

          CHECK(errors.size());
          CHECK(typeid(*errors[0]).name() == typeid(ebi::vcf::Error).name());
          CHECK(typeid(*errors[1]).name() == typeid(ebi::vcf::MetaSectionError).name());
          CHECK(typeid(*errors[2]).name() == typeid(ebi::vcf::SamplesBodyError).name());
      }


      boost::filesystem::path db_file{db_name};
      boost::filesystem::remove(db_file);
      CHECK_FALSE(boost::filesystem::exists(db_file));

  }

  TEST_CASE("Integration test: validator and odb", "[output]")
  {
      auto path = boost::filesystem::path("test/input_files/v4.1/failed/failed_body_sample_000.vcf");

      std::string db_name = path.string() + ".errors.db";

      {
          std::unique_ptr<ebi::vcf::ReportWriter> output{new ebi::vcf::OdbReportRW{db_name, version_info}};
          CHECK_FALSE(is_valid(path.string(), std::move(output)));
      }

      SECTION(path.string() + " error count")
      {
          size_t count_errors;
          size_t count_warnings;

          {
              ebi::vcf::OdbReportRW errorsDAO{db_name, version_info};
              count_errors = errorsDAO.count_errors();
              count_warnings = errorsDAO.count_warnings();
          }

          CHECK(count_errors == 1);
          CHECK(count_warnings == 1);
      }

      SECTION(path.string() + " error details")
      {
          size_t errors_read = 0;
          ebi::vcf::OdbReportRW errorsDAO{db_name, version_info};

          errorsDAO.for_each_error([&errors_read](std::shared_ptr<ebi::vcf::Error> error) {
              CHECK(error->line == 4);
              CHECK(error->message == "Allele must be a non-negative integer number");
              errors_read++;
          });

          // do we prefer this?
//          for(ebi::vcf::Error* error : errorsDAO.read_errors()) {
//              CHECK(error->get_line() == 1);
//              CHECK(error->get_raw_message() == "The fileformat declaration is not 'fileformat=VCFv4.1'");
//              errors_read++;
//          }

          CHECK(errors_read == 1);
      }

      boost::filesystem::path db_file{db_name};
      boost::filesystem::remove(db_file);
      CHECK_FALSE(boost::filesystem::exists(db_file));

  }

  TEST_CASE("Unit test: summary tracker", "[output]")
  {
      SECTION("SummaryTracker should skip repeated Errors")
      {
          ebi::vcf::SummaryTracker reporter;
          ebi::vcf::FormatBodyError error{7, "format body error"};

          reporter.add_to_summary(error.message, error.line);
          REQUIRE(reporter.error_summary_report[error.message].occurrences == 1);
          REQUIRE(reporter.error_summary_report[error.message].first_occurrence_line == 7);

          reporter.add_to_summary(error.message, 11);
          REQUIRE(reporter.error_summary_report[error.message].occurrences == 2);
          REQUIRE(reporter.error_summary_report[error.message].first_occurrence_line == 7);
      }
  }

  TEST_CASE("Integration test: summary report", "[output]")
  {
      auto path = boost::filesystem::path("test/input_files/v4.3/passed/passed_body_format.vcf"); 
      auto summary_path = path;
      summary_path += ".errors_summary.txt";

      SECTION(path.string() + " summary error count")
      {
          {
              auto output = new ebi::vcf::SummaryReportWriter{summary_path.string()};
              std::vector<std::unique_ptr<ebi::vcf::ReportWriter>> outputs;
              outputs.emplace_back(output);

              std::ifstream input{path.string()};
              vcf::is_valid_vcf_file(input, path.string(), vcf::ValidationLevel::warning, outputs);
              input.close();
          }

          CHECK(count_lines(summary_path.string()) == 2);
      }

      boost::filesystem::remove(summary_path);
      CHECK_FALSE(boost::filesystem::exists(summary_path));
  }

}
