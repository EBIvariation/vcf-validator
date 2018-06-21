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

#include "vcf/assembly_report_writer.hpp"
#include "vcf/file_structure.hpp"
#include "vcf/assembly_checker.hpp"
#include "vcf/error.hpp"
#include "vcf/report_writer.hpp"
#include "vcf/vcf_fasta_variant.hpp"
#include "test_utils.hpp"

namespace ebi
{
  TEST_CASE("Unit test: odbAssembly", "[output]")
  {
      std::string line{"1\t10177\trs367896724\tA\tAC"};
      vcf::VcfVariant vcf_variant{line};
      std::string db_name = "test/input_files/sqlite_test.errors.assembly.odb.db";

      SECTION("Write and count MatchStats entries") {
          ebi::vcf::OdbAssemblyReportRW TestReportRW{db_name};
          TestReportRW.add_result(true, vcf_variant);
          TestReportRW.add_result(true, vcf_variant);
          TestReportRW.write_results();
          TestReportRW.flush();
          size_t count_entry = TestReportRW.count_entry();
          CHECK(count_entry == 1);
      }

      SECTION("Write and read MatchStats entries")
      {
          ebi::vcf::OdbAssemblyReportRW TestReportRW{db_name};
          TestReportRW.add_result(true, vcf_variant);
          TestReportRW.add_result(false, vcf_variant);
          TestReportRW.write_results();
          TestReportRW.flush();

          size_t entry_count = 0;
          TestReportRW.for_each_entry([&](std::shared_ptr<ebi::vcf::MatchStats> match_stats) {
              CHECK(match_stats->num_variants == 2);
              CHECK(match_stats->num_matches == 1);
              entry_count++;
          });
          CHECK(entry_count == 1);
      }
      boost::filesystem::path db_file{db_name};
      boost::filesystem::remove(db_file);
      CHECK_FALSE(boost::filesystem::exists(db_file));  
  }

}
