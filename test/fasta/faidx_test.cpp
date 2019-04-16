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

#include "fasta/faidx.hpp"
#include "vcf/compression.hpp"

namespace ebi {
  const std::string EMPTY_FASTA = "test/input_files/fasta/empty_fasta.fa";
  const std::string SINGLE_CHROMOSOME_FASTA = "test/input_files/fasta/single_chromosome.fa";
  const std::string WHOLE_GENOME_FASTA = "test/input_files/fasta/whole_genome.fa";

  void test_index_fasta(const std::string fasta_input, const std::string expected_fasta_index) {
      std::ostringstream output;
      std::ifstream input(fasta_input.c_str(), std::ifstream::binary);
      CHECK_NOTHROW(ebi::vcf::faidx::index_fasta(input, output));

      std::ifstream index(expected_fasta_index.c_str(), std::ifstream::binary);
      std::stringstream index_stringstream;
      index_stringstream << index.rdbuf();
      CHECK(output.str() == index_stringstream.str());
  }

  TEST_CASE("Tests for on-the-fly indexing of plain fasta input", "[faidx]")
  {

      SECTION("Create index for empty fasta")
      {
          test_index_fasta(EMPTY_FASTA, EMPTY_FASTA + ".fai");
      }

      SECTION("Create index for single chromosome fasta")
      {
          test_index_fasta(SINGLE_CHROMOSOME_FASTA, SINGLE_CHROMOSOME_FASTA + ".fai");
      }

      SECTION("Create index for multiple chromosomes fasta")
      {
          test_index_fasta(WHOLE_GENOME_FASTA, WHOLE_GENOME_FASTA + ".fai");
      }
  }
}
