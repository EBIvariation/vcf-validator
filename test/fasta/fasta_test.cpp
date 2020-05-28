/**
 * Copyright 2019 EMBL - European Bioinformatics Institute
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

#include <fstream>
#include <string>

#include "catch/catch.hpp"
#include "util/curl_easy.hpp"
#include "fasta/fasta.hpp"

namespace ebi
{
  const std::string WHOLE_GENOME_FASTA = "test/input_files/fasta/whole_genome.fa";
  const std::string WHOLE_GENOME_FASTA_INDEX = "test/input_files/fasta/whole_genome.fa.fai";
  const std::string SINGLE_CHROMOSOME_FASTA = "test/input_files/fasta/single_chromosome.fa";
  const std::string SINGLE_CHROMOSOME_FASTA_INDEX = "test/input_files/fasta/single_chromosome.fa.fai";

  TEST_CASE("Tests for using file based fasta", "[fasta]")
  {
      SECTION("Create file based fasta objects")
      {
          CHECK_NOTHROW(std::unique_ptr<ebi::vcf::fasta::IFasta>(
                  new ebi::vcf::fasta::FileBasedFasta(WHOLE_GENOME_FASTA, WHOLE_GENOME_FASTA_INDEX)));
          CHECK_NOTHROW(std::unique_ptr<ebi::vcf::fasta::IFasta>(
                  new ebi::vcf::fasta::FileBasedFasta(SINGLE_CHROMOSOME_FASTA, SINGLE_CHROMOSOME_FASTA_INDEX)));
      }

      SECTION("Check if contigs exist, whole genome")
      {
          std::unique_ptr<ebi::vcf::fasta::IFasta> fasta(
                  new ebi::vcf::fasta::FileBasedFasta(WHOLE_GENOME_FASTA, WHOLE_GENOME_FASTA_INDEX));

          CHECK(fasta->sequence_exists("I"));
          CHECK(fasta->sequence_exists("II"));
          CHECK(fasta->sequence_exists("III"));
          CHECK_FALSE(fasta->sequence_exists("Non-existing"));
      }

      SECTION("Check if contigs exist, single chromosome")
      {
          std::unique_ptr<ebi::vcf::fasta::IFasta> fasta(
                  new ebi::vcf::fasta::FileBasedFasta(SINGLE_CHROMOSOME_FASTA, SINGLE_CHROMOSOME_FASTA_INDEX));

          CHECK(fasta->sequence_exists("III"));
          CHECK_FALSE(fasta->sequence_exists("Non-existing"));
      }

      SECTION("Check the contigs' length, whole genome")
      {
          std::unique_ptr<ebi::vcf::fasta::IFasta> fasta(
                  new ebi::vcf::fasta::FileBasedFasta(WHOLE_GENOME_FASTA, WHOLE_GENOME_FASTA_INDEX));

          CHECK(fasta->sequence_length("I") == 200);
          CHECK(fasta->sequence_length("II") == 172);
          CHECK(fasta->sequence_length("III") == 78);
          CHECK(fasta->sequence_length("Non-existing") == 0);
      }

      SECTION("Check the contigs' length, single chromosome")
      {
          std::unique_ptr<ebi::vcf::fasta::IFasta> fasta(
                  new ebi::vcf::fasta::FileBasedFasta(SINGLE_CHROMOSOME_FASTA, SINGLE_CHROMOSOME_FASTA_INDEX));

          CHECK(fasta->sequence_length("III") == 78);
          CHECK(fasta->sequence_length("Non-existing") == 0);
      }

      SECTION("Check the contigs' sequence, whole genome")
      {
          std::unique_ptr<ebi::vcf::fasta::IFasta> fasta(
                  new ebi::vcf::fasta::FileBasedFasta(WHOLE_GENOME_FASTA, WHOLE_GENOME_FASTA_INDEX));

          CHECK(fasta->sequence("I", 0, 31) == "GATCACGTACATCACCTTGTAAGAATTTATC");
          CHECK(fasta->sequence("I", 199, 31) == "T");
          CHECK(fasta->sequence("I", 200, 31) == "");
          CHECK(fasta->sequence("I", 0, 0) == "");
          CHECK(fasta->sequence("Non-existing", 0, 31) == "");
      }

      SECTION("Check the contigs' sequence, single chromosome")
      {
          std::unique_ptr<ebi::vcf::fasta::IFasta> fasta(
                  new ebi::vcf::fasta::FileBasedFasta(SINGLE_CHROMOSOME_FASTA, SINGLE_CHROMOSOME_FASTA_INDEX));

          CHECK(fasta->sequence("III", 0, 31) == "GATCAGCCAAAATGGCTGATCCAGCTATTTA");
          CHECK(fasta->sequence("III", 77, 31) == "T");
          CHECK(fasta->sequence("III", 78, 31) == "");
          CHECK(fasta->sequence("III", 0, 0) == "");
          CHECK(fasta->sequence("Non-existing", 0, 31) == "");
      }
  }

  TEST_CASE("Tests for using contig downloaded from ENA", "[fasta]")
  {
      SECTION("Create contig based fasta objects")
      {
          CHECK_NOTHROW(std::unique_ptr<ebi::vcf::fasta::IFasta>(new ebi::vcf::fasta::RemoteContig()));
      }

      SECTION("Download contigs and be able to extract sequences")
      {
          std::unique_ptr<ebi::vcf::fasta::IFasta> fasta(new ebi::vcf::fasta::RemoteContig());
          CHECK_NOTHROW(fasta->sequence("DQ083950", 0, 1));
          CHECK_THROWS_AS(fasta->sequence("Non-existing", 0, 1), ebi::util::curl::URLRetrievalException);

          CHECK(fasta->sequence_exists("DQ083950"));
          CHECK(fasta->sequence_exists("Non-existing"));
          CHECK_FALSE(fasta->sequence_exists("Undownloaded"));

          CHECK(fasta->sequence_length("DQ083950") == 174);
          CHECK(fasta->sequence_length("Non-existing") == 0);
          CHECK(fasta->sequence_length("Undownloaded") == 0);

          CHECK(fasta->sequence("DQ083950", 0, 31) == "GCCTCTGGTATGCTTCCCTGCTTGATGATTG");
          CHECK(fasta->sequence("DQ083950", 60, 31) == "ATGCTAGAAAAAACCAAGCAGTTTGTGGAGA");
          CHECK(fasta->sequence("DQ083950", 170, 31) == "GGTG");
          CHECK(fasta->sequence("DQ083950", 174, 31) == "");
          CHECK(fasta->sequence("DQ083950", 0, 0) == "");
          CHECK(fasta->sequence("Non-existing", 0, 31) == "");
      }
  }
}
