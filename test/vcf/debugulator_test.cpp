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
#include <fstream>

#include "catch/catch.hpp"

#include "vcf/odb_report.hpp"
#include "vcf/debugulator.hpp"

namespace ebi
{
  TEST_CASE("Fixing errors", "[debugulator]")
  {
      SECTION("Fix duplicates")
      {
          size_t line_number = 8;
          std::string message{"error message mock: Duplication error"};
          ebi::vcf::DuplicationError test_error{line_number, message};

          std::string string_line = "mock of a line with a duplicate variant";
          std::vector<char> line{string_line.begin(), string_line.end()};

          std::stringstream output;
          output << "previous line";
          size_t previous_size = output.str().size();

          vcf::Fixer{output}.fix(line_number, line, test_error);

          // the fix for duplicated variants is avoiding to write the duplicated line
          CHECK(output.str().size() == previous_size);
      }

      SECTION("Fix INFO field")
      {
          size_t line_number = 8;
          std::string message{"error message mock: There's an invalid info field"};
          ebi::vcf::InfoBodyError test_error{line_number, message, "wrong_field"};

          std::string string_line = "chr\tpos\tid\tref\talt\tqual\tfilter\tAN=2;wrong_field=x;AC=1\tformat\tsamples";
          std::vector<char> line{string_line.begin(), string_line.end()};

          std::stringstream output;
          vcf::Fixer{output}.fix(line_number, line, test_error);

          std::vector<std::string> columns, info_fields;
          util::string_split(output.str(), "\t", columns);
          util::string_split(columns[7], ";", info_fields);
          INFO(columns[7]);
          CHECK(info_fields.size() == 2);
      }
      SECTION("Fix first INFO field")
      {
          size_t line_number = 8;
          std::string message{"error message mock: There's an invalid info field"};
          ebi::vcf::InfoBodyError test_error{line_number, message, "wrong_field"};

          std::string string_line = "chr\tpos\tid\tref\talt\tqual\tfilter\twrong_field=x;AC=1\tformat\tsamples";
          std::vector<char> line{string_line.begin(), string_line.end()};

          std::stringstream output;
          vcf::Fixer{output}.fix(line_number, line, test_error);

          std::vector<std::string> columns, info_fields;
          util::string_split(output.str(), "\t", columns);
          util::string_split(columns[7], ";", info_fields);
          CHECK(info_fields.size() == 1);
      }
      SECTION("Fix unique INFO field")
      {
          size_t line_number = 8;
          std::string message{"error message mock: There's an invalid info field"};
          ebi::vcf::InfoBodyError test_error{line_number, message, "wrong_field"};

          std::string string_line = "chr\tpos\tid\tref\talt\tqual\tfilter\twrong_field=x\tformat\tsamples";
          std::vector<char> line{string_line.begin(), string_line.end()};

          std::stringstream output;
          vcf::Fixer{output}.fix(line_number, line, test_error);

          std::vector<std::string> columns, info_fields;
          util::string_split(output.str(), "\t", columns);
          CHECK(columns[7] == ".");
      }

      SECTION("Fix SAMPLE field GT")
      {
          size_t line_number = 8;
          std::string message{"the genotype in the sample column has an illegal value"};
          ebi::vcf::SamplesFieldBodyError test_error{line_number, message, "GT"};

          std::string string_line = "1\t55388\trs182711216\tC\tT\t100\tPASS\tTHETA=0.0102;AA=C\tGT:GS:GL\t1/C:0.000:-0.18,-0.48,-2.49";
          std::vector<char> line{string_line.begin(), string_line.end()};

          std::stringstream output;
          vcf::Fixer{output}.fix(line_number, line, test_error);

          std::vector<std::string> columns, sample_fields;
          util::string_split(output.str(), "\t", columns);
          util::string_split(columns[9], ":", sample_fields);
          INFO(output.str());
          CHECK(sample_fields[0] == ".");
          CHECK(columns[8] == "GT:GS:GL");
      }
      SECTION("Fix SAMPLE field AC")
      {
          size_t line_number = 8;
          std::string message{"the genotype in the sample column has an illegal value"};
          ebi::vcf::SamplesFieldBodyError test_error{line_number, message, "AC"};

          std::string string_line = "1\t55388\trs182711216\tC\tT\t100\tPASS\tTHETA=0.0102;AA=C\tGT:AC:GL\t1/1:0.000:-0.18,-0.48,-2.49";
          std::vector<char> line{string_line.begin(), string_line.end()};

          std::stringstream output;
          vcf::Fixer{output}.fix(line_number, line, test_error);

          std::vector<std::string> columns, sample_fields;
          util::string_split(output.str(), "\t", columns);
          util::string_split(columns[9], ":", sample_fields);
          INFO(output.str());
          CHECK(sample_fields.size() == 2);
          CHECK(columns[8] == "GT:GL");
      }
      SECTION("Fix SAMPLE field that doesn't exist")
      {
          size_t line_number = 8;
          std::string message{"requested to remove a wrong field"};
          ebi::vcf::SamplesFieldBodyError test_error{line_number, message, "AC"};

          std::string string_line = "1\t55388\trs182711216\tC\tT\t100\tPASS\tTHETA=0.0102;AA=C\tGT:GS:GL\t1/1:0.000:-0.18,-0.48,-2.49";
          std::vector<char> line{string_line.begin(), string_line.end()};

          std::stringstream output;
          vcf::Fixer{output}.fix(line_number, line, test_error);

          INFO("the line should be left identical, because we told it to remove a wrong field")
          CHECK(output.str() == string_line);
      }
      SECTION("Fix SAMPLE without samples")
      {
          size_t line_number = 8;
          std::string message{"requested to remove a wrong file"};
          ebi::vcf::SamplesFieldBodyError test_error{line_number, message, "AC"};

          std::string string_line = "1\t55388\trs182711216\tC\tT\t100\tPASS\tTHETA=0.0102;AA=C";

          std::vector<char> line{string_line.begin(), string_line.end()};

          std::stringstream output;
          vcf::Fixer{output}.fix(line_number, line, test_error);

          CHECK(output.str() == string_line);
      }
  }

  TEST_CASE("Empty report", "[debugulator]")
  {
      boost::filesystem::path path{"test/input_files/complexfile_passed_000.vcf.errors.1472743634194.db"};
      std::ifstream file{"test/input_files/v4.1/passed/complexfile_passed_000.vcf"};
      std::stringstream ss;
      SECTION(path.string())
      {
          vcf::OdbReportRW report{path.string()};
          size_t fixed_errors = vcf::debugulator::fix_vcf_file(file, report, ss);
          CHECK(fixed_errors == 0);
      }
  }

}

