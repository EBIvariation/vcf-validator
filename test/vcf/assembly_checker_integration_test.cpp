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

#include "assembly_checker_test_aux.hpp"

namespace ebi
{  

  TEST_CASE("Valid fasta and vcf combination", "[assembly_checker]")
  {
      SECTION("Empty VCF File")
      {
          std::string folder = "test/input_files/assembly_checker/passed/passed_empty_vcf/";
          std::string file_prefix = get_file_prefix(folder);
          CHECK(ebi::vcf::assembly_checker::check_vcf_ref(folder + file_prefix + ebi::vcf::VCF_EXT, folder + file_prefix + ebi::vcf::FASTA_EXT, folder + file_prefix + ebi::vcf::INDEX_EXT));
      }
      SECTION("Single entry")
      {
          std::string folder = "test/input_files/assembly_checker/passed/passed_single_variant/";
          std::string file_prefix = get_file_prefix(folder);
          CHECK(ebi::vcf::assembly_checker::check_vcf_ref(folder + file_prefix + ebi::vcf::VCF_EXT, folder + file_prefix + ebi::vcf::FASTA_EXT, folder + file_prefix + ebi::vcf::INDEX_EXT));
      }
      SECTION("Full sample VCF, all match")
      {
          std::string folder = "test/input_files/assembly_checker/passed/passed_fullsample/";
          std::string file_prefix = get_file_prefix(folder);
          CHECK(ebi::vcf::assembly_checker::check_vcf_ref(folder + file_prefix + ebi::vcf::VCF_EXT, folder + file_prefix + ebi::vcf::FASTA_EXT, folder + file_prefix + ebi::vcf::INDEX_EXT));
      }
  }

  TEST_CASE("Invalid VCF and Fasta combination", "[assembly_checker]")
  {
      SECTION("Single entry, single mismatch")
      {
          std::string folder = "test/input_files/assembly_checker/failed/failed_singlemismatch_singleentry/";
          std::string file_prefix = get_file_prefix(folder);
          CHECK_FALSE(ebi::vcf::assembly_checker::check_vcf_ref(folder + file_prefix + ebi::vcf::VCF_EXT, folder + file_prefix + ebi::vcf::FASTA_EXT, folder + file_prefix + ebi::vcf::INDEX_EXT));
      }
      SECTION("Multiple entry, multiple mismatch")
      {
          std::string folder = "test/input_files/assembly_checker/failed/failed_multiplemismatch_multipleentry/";
          std::string file_prefix = get_file_prefix(folder);
          CHECK_FALSE(ebi::vcf::assembly_checker::check_vcf_ref(folder + file_prefix + ebi::vcf::VCF_EXT, folder + file_prefix + ebi::vcf::FASTA_EXT, folder + file_prefix + ebi::vcf::INDEX_EXT));
      }
      SECTION("Empty fasta file, single entry")
      {
          std::string folder = "test/input_files/assembly_checker/failed/failed_empty_fasta/";
          std::string file_prefix = get_file_prefix(folder);
          CHECK_FALSE(ebi::vcf::assembly_checker::check_vcf_ref(folder + file_prefix + ebi::vcf::VCF_EXT, folder + file_prefix + ebi::vcf::FASTA_EXT, folder + file_prefix + ebi::vcf::INDEX_EXT));
      }
      SECTION("Multiple entry, all mismatch")
      {
          std::string folder = "test/input_files/assembly_checker/failed/failed_allmismatch_multipleentry/";
          std::string file_prefix = get_file_prefix(folder);
          CHECK_FALSE(ebi::vcf::assembly_checker::check_vcf_ref(folder + file_prefix + ebi::vcf::VCF_EXT, folder + file_prefix + ebi::vcf::FASTA_EXT, folder + file_prefix + ebi::vcf::INDEX_EXT));
      } 
  }

  TEST_CASE("Files missing", "[assembly_checker]")
  {
      SECTION("Missing fasta File")
      {
          std::string folder = "test/input_files/assembly_checker/failed/failed_missing_fasta/";
          std::string file_prefix = get_file_prefix(folder);
          CHECK_THROWS_AS(ebi::vcf::assembly_checker::check_vcf_ref(folder + file_prefix + ebi::vcf::VCF_EXT, folder + file_prefix + ebi::vcf::FASTA_EXT, folder + file_prefix + ebi::vcf::INDEX_EXT), std::runtime_error);
      }
      SECTION("Missing index file")
      {
          std::string folder = "test/input_files/assembly_checker/failed/failed_missing_index/";
          std::string file_prefix = get_file_prefix(folder);
          CHECK_THROWS_AS(ebi::vcf::assembly_checker::check_vcf_ref(folder + file_prefix + ebi::vcf::VCF_EXT, folder + file_prefix + ebi::vcf::FASTA_EXT, folder + file_prefix + ebi::vcf::INDEX_EXT), std::runtime_error);
      }
      SECTION("Missing VCF file")
      {
          std::string folder = "test/input_files/assembly_checker/failed/failed_missing_vcf/";
          std::string file_prefix = get_file_prefix(folder);
          CHECK_THROWS_AS(ebi::vcf::assembly_checker::check_vcf_ref(folder + file_prefix + ebi::vcf::VCF_EXT, folder + file_prefix + ebi::vcf::FASTA_EXT, folder + file_prefix + ebi::vcf::INDEX_EXT), std::runtime_error);
      }
  }
}
