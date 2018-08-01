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

#include <set>
#include <vector>

#include <boost/algorithm/string/predicate.hpp>

#include "bioio/bioio.hpp"
#include "util/logger.hpp"
#include "util/stream_utils.hpp"
#include "vcf/assembly_checker.hpp"
#include "vcf/vcf_fasta_variant.hpp"

namespace ebi
{
  namespace vcf
  {
    namespace assembly_checker
    {

      bool check_vcf_ref(std::istream &vcf_input,
                         std::istream &fasta_input,
                         std::istream &fasta_index_input,
                         std::ostream &problem_lines_output)
      {
          std::vector<char> vector_line;
          vector_line.reserve(default_line_buffer_size);

          std::set<std::string> absent_chromosomes;
          size_t num_matches = 0;
          size_t num_variants = 0;

          // Reading FASTA index, and querying FASTA file
          auto index = bioio::read_fasta_index(fasta_index_input);

          // Reading VCF file
          while (util::readline(vcf_input, vector_line).size() != 0) {
              std::string line{vector_line.begin(), vector_line.end()};

              if (boost::starts_with(line, "#")) {
                  continue;
              }

              std::vector<std::string> record_columns;

              VcfVariant vcf_variant{line};
              num_variants++;

              if (index.count(vcf_variant.chromosome) == 0) {
                  absent_chromosomes.insert(vcf_variant.chromosome);
                  continue;
              }

              if (vcf_variant.position == 0) {
                  BOOST_LOG_TRIVIAL(warning) << "Position 0 should only be used for a telomere";
                  continue;
              }

              auto sequence = bioio::read_fasta_contig(fasta_input, index.at(vcf_variant.chromosome),
                                                       vcf_variant.position - 1, vcf_variant.reference_allele.length());
              auto reference_sequence = vcf_variant.reference_allele;

              std::transform(sequence.begin(), sequence.end(), sequence.begin(), ::tolower);
              std::transform(reference_sequence.begin(), reference_sequence.end(), reference_sequence.begin(), ::tolower);

              if (sequence == reference_sequence) {
                  num_matches++;
              } else {
                  util::writeline(problem_lines_output, line);
              }
          } // end while loop

          BOOST_LOG_TRIVIAL(info) << "Number of matches: " << num_matches << "/" << num_variants;
          BOOST_LOG_TRIVIAL(info) << "Percentage of matches: " << (static_cast<double>(num_matches) / num_variants) * 100 << "%";

          if (absent_chromosomes.size() > 0) {
              std::string message = "Please check if FASTA is correct; chromosomes from VCF that don't appear in FASTA file:";
              for (auto & absent_chromosome : absent_chromosomes) {
                  message += " " + absent_chromosome + ",";
              }
              message.pop_back();
              throw std::invalid_argument{message};
          }

          return (num_matches == num_variants);
      } // end check_vcf_ref
    } // end namespace assembly_checker
  } // end namespace vcf
} // end namespace ebi
