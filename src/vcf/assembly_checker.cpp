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

#include <boost/algorithm/string/predicate.hpp>

#include "bioio/bioio.hpp"
#include "util/stream_utils.hpp"
#include "vcf/assembly_checker.hpp"
#include "vcf/vcf_fasta_relation.hpp"

namespace ebi
{
  namespace vcf
  {
    namespace assembly_checker
    {

      bool check_vcf_ref(std::istream &vcf_input, std::istream &fasta_input, std::istream &fasta_index_input)
      {
          std::vector<char> line;
          line.reserve(default_line_buffer_size);

          while (util::readline(vcf_input, line).size() != 0) {
              
          }
      }
    }
  }
}
