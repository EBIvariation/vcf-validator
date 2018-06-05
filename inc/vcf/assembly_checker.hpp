/**
 * Copyright 2014-2018 EMBL - European Bioinformatics Institute
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

#ifndef VCF_ASSEMBLY_CHECKER_HPP
#define VCF_ASSEMBLY_CHECKER_HPP

#include <fstream>
#include <set>
#include <vector>

#include <boost/algorithm/string/predicate.hpp>

#include "bioio/bioio.hpp"
#include "util/logger.hpp"
#include "util/stream_utils.hpp"
#include "vcf/vcf_fasta_variant.hpp"
#include <fstream>


namespace ebi
{
  namespace vcf
  {
    namespace assembly_checker
    {

      size_t const default_line_buffer_size = 64 * 1024;

      bool check_vcf_ref(std::istream &vcf_input, std::istream &fasta_input, std::istream &fasta_index_input);

      void check_missing_chromosomes(std::set<std::string> absent_chromosomes);

      bool is_matching_sequence(std::string fasta_sequence, std::string reference_sequence);

      inline void check_file_validity(std::ifstream &input, std::string error_msg)
      {
          if (!input) {
            throw std::runtime_error{error_msg};
          }
      }

      class MatchStats
      {
        public:
          MatchStats();
          void add_match_result(bool result);
          bool is_valid_combination();
          int num_matches;
          int num_variants;
      };
    }
  }
}

#endif // VCF_ASSEMBLY_CHECKER_HPP
