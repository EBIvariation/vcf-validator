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

#include <chrono>
#include <fstream>
#include <iostream>
#include <memory>

#include <boost/filesystem.hpp>

#include "catch/catch.hpp"

#include "test_utils.hpp"
#include "vcf/error.hpp"
#include "vcf/file_structure.hpp"
#include "vcf/report_writer.hpp"
#include "vcf/summary_report_writer.hpp"
#include "vcf/validator.hpp"

namespace ebi
{
  bool is_valid(std::string path, std::unique_ptr<ebi::vcf::ReportWriter> output)
  {
      std::ifstream input{path};
      if (!input) {
          throw std::runtime_error("file not found: " + path);
      }
      std::vector<std::unique_ptr<vcf::ReportWriter>> outputs;
      outputs.push_back(std::move(output));

      return ebi::vcf::is_valid_vcf_file(input, path, vcf::ValidationLevel::warning, outputs, vcf::AdditionalChecks());
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
              vcf::is_valid_vcf_file(input, path.string(), vcf::ValidationLevel::warning, outputs,
                                     vcf::AdditionalChecks());
              input.close();
          }

          CHECK(count_lines(summary_path.string()) == 3);
      }

      boost::filesystem::remove(summary_path);
      CHECK_FALSE(boost::filesystem::exists(summary_path));
  }

}
