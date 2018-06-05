/**
 * Copyright 2018 EMBL - European Bioinformatics Institute
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

//#include "boost/algorithm/string/split.hpp"
//#include "boost/algorithm/string/classification.hpp"
//#include <fstream>
//#iclude "catch/catch.hpp"
#include "assembly_checker_test_aux.hpp"
#include "vcf/vcf_fasta_variant.hpp"

namespace ebi
{  
  
  TEST_CASE("Function checks", "[assembly_checker]")
  {
      SECTION("Missing chromosome")
      {
          std::set<std::string> chromosomes;
          chromosomes.insert("1");
          CHECK_THROWS_AS(ebi::vcf::assembly_checker::check_missing_chromosomes(chromosomes), std::invalid_argument);
      }
      SECTION("Check sequence matches")
      {
          std::string line{"1\t10177\trs367896724\tA\tAC"};
          vcf::VcfVariant vcf_variant{line};
          CHECK(ebi::vcf::assembly_checker::is_matching_sequence(vcf_variant.reference_allele, "A"));
          CHECK_FALSE(ebi::vcf::assembly_checker::is_matching_sequence(vcf_variant.reference_allele, "G"));
      }
      SECTION("All matches")
      {
          ebi::vcf::assembly_checker::MatchStats match_stats;
          match_stats.add_match_result(true);
          match_stats.add_match_result(true);
          CHECK(match_stats.is_valid_combination());
      }
      SECTION("Mismatches")
      {
          ebi::vcf::assembly_checker::MatchStats match_stats;
          match_stats.add_match_result(true);
          match_stats.add_match_result(false);
          CHECK_FALSE(match_stats.is_valid_combination());
      }
  }

  TEST_CASE("Files missing", "[assembly_checker]")
  {
      SECTION("Missing FASTA File")
      {
          auto folder = boost::filesystem::path("test/input_files/assembly_checker/failed/failed_missing_fasta/");
          std::string file_prefix = get_file_prefix(folder);
          std::ifstream fasta_input{folder.string() + file_prefix + ebi::vcf::FASTA_EXT};
          CHECK_THROWS_AS(ebi::vcf::assembly_checker::check_file_validity(fasta_input, ""), std::runtime_error);
      }
      SECTION("Missing index file")
      {
          auto folder = boost::filesystem::path("test/input_files/assembly_checker/failed/failed_missing_index/");
          std::string file_prefix = get_file_prefix(folder);
          std::ifstream fasta_index_input{folder.string() + file_prefix + ebi::vcf::INDEX_EXT};
          CHECK_THROWS_AS(ebi::vcf::assembly_checker::check_file_validity(fasta_index_input, ""), std::runtime_error);
      }
      SECTION("Missing VCF file")
      {
          auto folder = boost::filesystem::path("test/input_files/assembly_checker/failed/failed_missing_vcf/");
          std::string file_prefix = get_file_prefix(folder);
          std::ifstream vcf_input{folder.string() + file_prefix + ebi::vcf::VCF_EXT};
          CHECK_THROWS_AS(ebi::vcf::assembly_checker::check_file_validity(vcf_input, ""), std::runtime_error);
      }
  }
}