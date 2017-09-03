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
#include <fstream>

#include "catch/catch.hpp"

#include "util/string_utils.hpp"
#include "vcf/odb_report.hpp"
#include "vcf/debugulator.hpp"
#include "vcf/string_constants.hpp"

namespace ebi
{
  TEST_CASE("Fixing errors", "[debugulator]")
  {
      SECTION("Fix meta definition Type for predefined tags")
      {
          size_t line_number = 8;
          std::string message{"error message mock: Incorrect meta header definition for predefined tags"};
          ebi::vcf::MetaSectionError test_error{line_number, message, ebi::vcf::ErrorFix::RECOVERABLE_VALUE, ebi::vcf::TYPE, ebi::vcf::STRING};

          std::string string_line = "##INFO=<ID=AA,Number=1,Type=Integer,Description=\"Ancestral allele\">";
          std::vector<char> line{string_line.begin(), string_line.end()};

          std::stringstream output;
          vcf::Fixer{output}.fix(line_number, line, test_error);

          CHECK(output.str() == "##INFO=<ID=AA,Number=1,Type=String,Description=\"Ancestral allele\">");
      }
      SECTION("Fix meta definition Number for predefined tags")
      {
          size_t line_number = 8;
          std::string message{"error message mock: Incorrect meta header definition for predefined tags"};
          ebi::vcf::MetaSectionError test_error{line_number, message, ebi::vcf::ErrorFix::RECOVERABLE_VALUE, ebi::vcf::NUMBER, "1"};

          std::string string_line = "##FORMAT=<ID=DP,Number=2,Type=Integer,Description=\"Read depth\">";
          std::vector<char> line{string_line.begin(), string_line.end()};

          std::stringstream output;
          vcf::Fixer{output}.fix(line_number, line, test_error);

          CHECK(output.str() == "##FORMAT=<ID=DP,Number=1,Type=Integer,Description=\"Read depth\">");
      }

      SECTION("Fix duplicate variants")
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

      SECTION("Fix ID duplicates")
      {
          size_t line_number = 8;
          std::string message{"error message mock: Duplicate ID fields"};
          ebi::vcf::IdBodyError test_error{line_number, message, ebi::vcf::ErrorFix::DUPLICATE_VALUES};

          std::string string_line = "chr\tpos\tdupid;dupid\tref\talt\tqual\tfilter\tinfo=x\tformat\tsamples";
          std::vector<char> line{string_line.begin(), string_line.end()};

          std::stringstream output;
          vcf::Fixer{output}.fix(line_number, line, test_error);

          std::vector<std::string> columns, id_fields;
          util::string_split(output.str(), "\t", columns);
          util::string_split(columns[2], ";", id_fields);
          CHECK(id_fields.size() == 1);
      }

      SECTION("Fix FILTER field")
      {
          size_t line_number = 8;
          std::string message{"error message mock: Invalid filter string 0"};
          ebi::vcf::FilterBodyError test_error{line_number, message, ebi::vcf::ErrorFix::IRRECOVERABLE_VALUE, "0"};

          std::string string_line = "chr\tpos\tid\tref\talt\tqual\t0;filter\tinfo=x\tformat\tsamples";
          std::vector<char> line{string_line.begin(), string_line.end()};

          std::stringstream output;
          vcf::Fixer{output}.fix(line_number, line, test_error);

          std::vector<std::string> columns, filter_strings;
          util::string_split(output.str(), "\t", columns);
          util::string_split(columns[6], ";", filter_strings);
          CHECK(filter_strings.size() == 1); 
      }
      SECTION("Fix unique FILTER field")
      {
          size_t line_number = 8;
          std::string message{"error message mock: Invalid solitary filter string 0"};
          ebi::vcf::FilterBodyError test_error{line_number, message, ebi::vcf::ErrorFix::IRRECOVERABLE_VALUE, "0"};

          std::string string_line = "chr\tpos\tid\tref\talt\tqual\t0\tinfo=x\tformat\tsamples";
          std::vector<char> line{string_line.begin(), string_line.end()};

          std::stringstream output;
          vcf::Fixer{output}.fix(line_number, line, test_error);

          std::vector<std::string> columns;
          util::string_split(output.str(), "\t", columns);
          CHECK(columns[6] == ebi::vcf::MISSING_VALUE);
      }
      SECTION("Fix FILTER duplicates")
      {
          size_t line_number = 8;
          std::string message{"error message mock: Duplicate filter strings"};
          ebi::vcf::FilterBodyError test_error{line_number, message, ebi::vcf::ErrorFix::DUPLICATE_VALUES};

          std::string string_line = "chr\tpos\tid\tref\talt\tqual\tdupfil;filter;dupfil\tinfo=x\tformat\tsamples";
          std::vector<char> line{string_line.begin(), string_line.end()};

          std::stringstream output;
          vcf::Fixer{output}.fix(line_number, line, test_error);

          std::vector<std::string> columns, filter_strings;
          util::string_split(output.str(), "\t", columns);
          util::string_split(columns[6], ";", filter_strings);
          CHECK(filter_strings.size() == 2);
      }

      SECTION("Fix INFO field")
      {
          size_t line_number = 8;
          std::string message{"error message mock: There's an invalid info field"};
          ebi::vcf::InfoBodyError test_error{line_number, message, ebi::vcf::ErrorFix::IRRECOVERABLE_VALUE,"wrong_field"};

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
          ebi::vcf::InfoBodyError test_error{line_number, message, ebi::vcf::ErrorFix::IRRECOVERABLE_VALUE, "wrong_field"};

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
          ebi::vcf::InfoBodyError test_error{line_number, message, ebi::vcf::ErrorFix::IRRECOVERABLE_VALUE, "wrong_field"};

          std::string string_line = "chr\tpos\tid\tref\talt\tqual\tfilter\twrong_field=x\tformat\tsamples";
          std::vector<char> line{string_line.begin(), string_line.end()};

          std::stringstream output;
          vcf::Fixer{output}.fix(line_number, line, test_error);

          std::vector<std::string> columns;
          util::string_split(output.str(), "\t", columns);
          CHECK(columns[7] == ebi::vcf::MISSING_VALUE);
      }
      SECTION("Fix INFO duplicate key with varying values")
      {
          size_t line_number = 8;
          std::string message{"error message mock: Duplicate info fields"};
          ebi::vcf::InfoBodyError test_error{line_number, message, ebi::vcf::ErrorFix::DUPLICATE_VALUES};

          std::string string_line = "chr\tpos\tid\tref\talt\tqual\tfilter\tdupkey=x;info=y;dupkey=z\tformat\tsamples";
          std::vector<char> line{string_line.begin(), string_line.end()};

          std::stringstream output;
          vcf::Fixer{output}.fix(line_number, line, test_error);

          std::vector<std::string> columns, info_fields;
          util::string_split(output.str(), "\t", columns);
          util::string_split(columns[7], ";", info_fields);
          CHECK(info_fields.size() == 1);
          CHECK(columns[7] == "info=y");
      }
      SECTION("Fix INFO duplicate key with single value")
      {
          size_t line_number = 8;
          std::string message{"error message mock: Duplicate info fields"};
          ebi::vcf::InfoBodyError test_error{line_number, message, ebi::vcf::ErrorFix::DUPLICATE_VALUES};

          std::string string_line = "chr\tpos\tid\tref\talt\tqual\tfilter\tdupkey=x;info=y;dupkey=x\tformat\tsamples";
          std::vector<char> line{string_line.begin(), string_line.end()};

          std::stringstream output;
          vcf::Fixer{output}.fix(line_number, line, test_error);

          std::vector<std::string> columns, info_fields;
          util::string_split(output.str(), "\t", columns);
          util::string_split(columns[7], ";", info_fields);
          CHECK(info_fields.size() == 2);
          CHECK(info_fields[0] == "dupkey=x");
          CHECK(info_fields[1] == "info=y");
      }
      SECTION("Fix INFO with duplicates of unique key")
      {
          size_t line_number = 8;
          std::string message{"error message mock: Duplicated info fields"};
          ebi::vcf::InfoBodyError test_error{line_number, message, ebi::vcf::ErrorFix::DUPLICATE_VALUES};

          std::string string_line = "chr\tpos\tid\tref\talt\tqual\tfilter\tdupkey=x;dupkey=y\tformat\tsamples";
          std::vector<char> line{string_line.begin(), string_line.end()};

          std::stringstream output;
          vcf::Fixer{output}.fix(line_number, line, test_error);

          std::vector<std::string> columns;
          util::string_split(output.str(), "\t", columns);
          CHECK(columns[7] == ebi::vcf::MISSING_VALUE);
      }
      SECTION("Fix INFO with duplicates, preserve order of fields")
      {
          size_t line_number = 8;
          std::string message{"error message mock: Duplicated info fields"};
          ebi::vcf::InfoBodyError test_error{line_number, message, ebi::vcf::ErrorFix::DUPLICATE_VALUES};

          std::string string_line = "chr\tpos\tid\tref\talt\tqual\tfilter\tac=x;ab=y;ac=x\tformat\tsamples";
          std::vector<char> line{string_line.begin(), string_line.end()};

          std::stringstream output;
          vcf::Fixer{output}.fix(line_number, line, test_error);

          std::vector<std::string> columns;
          util::string_split(output.str(), "\t", columns);
          CHECK(columns[7] == "ac=x;ab=y");
      }
      SECTION("Fix INFO SVLEN for non-symbolic alternate alleles")
      {
          size_t line_number = 8;
          std::string message{"error message mock: Invalid value of predefined tag SVLEN"};
          ebi::vcf::InfoBodyError test_error{line_number, message, ebi::vcf::ErrorFix::RECOVERABLE_VALUE, "SVLEN", "-3"};

          std::string string_line = "chr\tpos\tid\tACTNG\tGT\tqual\tfilter\tSVLEN=12\tformat\tsamples";
          std::vector<char> line{string_line.begin(), string_line.end()};

          std::stringstream output;
          vcf::Fixer{output}.fix(line_number, line, test_error);

          std::vector<std::string> columns;
          util::string_split(output.str(), "\t", columns);
          CHECK(columns[7] == "SVLEN=-3");
      }
      SECTION("Fix INFO END for precise variants")
      {
          size_t line_number = 8;
          std::string message{"error message mock: Invalid value of predefined tag END"};
          ebi::vcf::InfoBodyError test_error{line_number, message, ebi::vcf::ErrorFix::RECOVERABLE_VALUE, "END", "102"};

          std::string string_line = "chr\t100\tid\tACT\t.\t.\tfilter\tEND=5;IMPRECISE=0\tformat\tsamples";
          std::vector<char> line{string_line.begin(), string_line.end()};

          std::stringstream output;
          vcf::Fixer{output}.fix(line_number, line, test_error);

          std::vector<std::string> columns, info_fields;
          util::string_split(output.str(), "\t", columns);
          util::string_split(columns[7], ";", info_fields);
          CHECK(info_fields.size() == 2);
          CHECK(info_fields[0] == "END=102");
      }

      SECTION("Fix FORMAT duplicate field with no samples, preserve order of fields")
      {
          size_t line_number = 8;
          std::string message{"error message mock: Duplicate format fields"};
          ebi::vcf::FormatBodyError test_error{line_number, message, ebi::vcf::ErrorFix::DUPLICATE_VALUES};

          std::string string_line = "chr\tpos\tid\tref\talt\tqual\tfilter\tinfo\tGT:GH:GT:GH:GT";
          std::vector<char> line{string_line.begin(), string_line.end()};

          std::stringstream output;
          vcf::Fixer{output}.fix(line_number, line, test_error);

          std::vector<std::string> columns;
          util::string_split(output.str(), "\t", columns);
          CHECK(columns[8] == "GT:GH");
      }
      SECTION("Fix FORMAT duplicate field, throw exception if format column gets empty (because of different values)")
      {
          size_t line_number = 8;
          std::string message{"error message mock: Duplicate format fields"};
          ebi::vcf::FormatBodyError test_error{line_number, message, ebi::vcf::ErrorFix::DUPLICATE_VALUES};

          std::string string_line = "chr\tpos\tid\tref\talt\tqual\tfilter\tinfo\tGT:GH:GT:GH\t1:2:3:4";
          std::vector<char> line{string_line.begin(), string_line.end()};

          std::stringstream output;
          CHECK_THROWS_AS(vcf::Fixer{output}.fix(line_number, line, test_error), std::runtime_error);
      }
      SECTION("Fix FORMAT duplicate fields with 1 sample, same values for some")
      {
          size_t line_number = 8;
          std::string message{"error message mock: Duplicate format fields"};
          ebi::vcf::FormatBodyError test_error{line_number, message, ebi::vcf::ErrorFix::DUPLICATE_VALUES};

          std::string string_line = "chr\tpos\tid\tref\talt\tqual\tfilter\tinfo\tGT:GH:GT:GH:GP\t1:2:3:2:5";
          std::vector<char> line{string_line.begin(), string_line.end()};

          std::stringstream output;
          vcf::Fixer{output}.fix(line_number, line, test_error);

          std::vector<std::string> columns;
          util::string_split(output.str(), "\t", columns);
          CHECK(columns[8] == "GH:GP");
          CHECK(columns[9] == "2:5");
      }
      SECTION("Fix FORMAT duplicate fields with 1 sample, same values for some, sample with dropped trailing fields")
      {
          size_t line_number = 8;
          std::string message{"error message mock: Duplicate format fields"};
          ebi::vcf::FormatBodyError test_error{line_number, message, ebi::vcf::ErrorFix::DUPLICATE_VALUES};

          std::string string_line = "chr\tpos\tid\tref\talt\tqual\tfilter\tinfo\tGT:GH:GT:GH:GP\t1:2";
          std::vector<char> line{string_line.begin(), string_line.end()};

          std::stringstream output;
          vcf::Fixer{output}.fix(line_number, line, test_error);

          std::vector<std::string> columns;
          util::string_split(output.str(), "\t", columns);
          CHECK(columns[8] == "GT:GH:GP");
          CHECK(columns[9] == "1:2");
      }
      SECTION("Fix FORMAT duplicate fields with 1 sample, missing but not matching values in between")
      {
          size_t line_number = 8;
          std::string message{"error message mock: Duplicate format fields"};
          ebi::vcf::FormatBodyError test_error{line_number, message, ebi::vcf::ErrorFix::DUPLICATE_VALUES};

          std::string string_line = "chr\tpos\tid\tref\talt\tqual\tfilter\tinfo\tGT:GT:GP\t1:.:8";
          std::vector<char> line{string_line.begin(), string_line.end()};

          std::stringstream output;
          vcf::Fixer{output}.fix(line_number, line, test_error);

          std::vector<std::string> columns;
          util::string_split(output.str(), "\t", columns);
          CHECK(columns[8] == "GP");
          CHECK(columns[9] == "8");
      }
      SECTION("Fix FORMAT duplicate fields with 1 sample, missing but matching values in between")
      {
          size_t line_number = 8;
          std::string message{"error message mock: Duplicate format fields"};
          ebi::vcf::FormatBodyError test_error{line_number, message, ebi::vcf::ErrorFix::DUPLICATE_VALUES};

          std::string string_line = "chr\tpos\tid\tref\talt\tqual\tfilter\tinfo\tGH:GH:GP\t.:.:8";
          std::vector<char> line{string_line.begin(), string_line.end()};

          std::stringstream output;
          vcf::Fixer{output}.fix(line_number, line, test_error);

          std::vector<std::string> columns;
          util::string_split(output.str(), "\t", columns);
          CHECK(columns[8] == "GH:GP");
          CHECK(columns[9] == ".:8");
      }
      SECTION("Fix FORMAT duplicate fields with 2 samples, different values for same key in 1 sample")
      {
          size_t line_number = 8;
          std::string message{"error message mock: Duplicate format fields"};
          ebi::vcf::FormatBodyError test_error{line_number, message, ebi::vcf::ErrorFix::DUPLICATE_VALUES};

          std::string string_line = "chr\tpos\tid\tref\talt\tqual\tfilter\tinfo\tGT:GT:GP\t1:1\t3:4";
          std::vector<char> line{string_line.begin(), string_line.end()};

          std::stringstream output;
          vcf::Fixer{output}.fix(line_number, line, test_error);

          std::vector<std::string> columns;
          util::string_split(output.str(), "\t", columns);
          CHECK(columns[8] == "GP");
          CHECK(columns[9] == ebi::vcf::MISSING_VALUE);
          CHECK(columns[10] == ebi::vcf::MISSING_VALUE);
      }
      SECTION("Fix FORMAT duplicate fields with 2 samples, same values for same key in each sample")
      {
          size_t line_number = 8;
          std::string message{"error message mock: Duplicate format fields"};
          ebi::vcf::FormatBodyError test_error{line_number, message, ebi::vcf::ErrorFix::DUPLICATE_VALUES};

          std::string string_line = "chr\tpos\tid\tref\talt\tqual\tfilter\tinfo\tGT:GT\t1:1\t3:3";
          std::vector<char> line{string_line.begin(), string_line.end()};

          std::stringstream output;
          vcf::Fixer{output}.fix(line_number, line, test_error);

          std::vector<std::string> columns;
          util::string_split(output.str(), "\t", columns);
          CHECK(columns[8] == "GT");
          CHECK(columns[9] == "1");
          CHECK(columns[10] == "3");
      }

      SECTION("Fix SAMPLE field GT")
      {
          size_t line_number = 8;
          std::string message{"the genotype in the sample column has an illegal value"};
          ebi::vcf::SamplesFieldBodyError test_error{line_number, message, vcf::GT, 2};

          std::string string_line = "1\t55388\trs182711216\tC\tT\t100\tPASS\tTHETA=0.0102;AA=C\tGT:GS:GL\t1/C:0.000:-0.18,-0.48,-2.49";
          std::vector<char> line{string_line.begin(), string_line.end()};

          std::stringstream output;
          vcf::Fixer{output}.fix(line_number, line, test_error);

          std::vector<std::string> columns, sample_fields;
          util::string_split(output.str(), "\t", columns);
          util::string_split(columns[9], ":", sample_fields);
          INFO(output.str());
          CHECK(sample_fields[0] == "./.");
          CHECK(columns[8] == "GT:GS:GL");
      }
      SECTION("Fix SAMPLE field AC")
      {
          size_t line_number = 8;
          std::string message{"the genotype in the sample column has an illegal value"};
          ebi::vcf::SamplesFieldBodyError test_error{line_number, message, vcf::AC};

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
          ebi::vcf::SamplesFieldBodyError test_error{line_number, message, vcf::AC};

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
          ebi::vcf::SamplesFieldBodyError test_error{line_number, message, vcf::AC};

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

