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

#include "vcf/assembly_checker.hpp"

namespace ebi
{
  namespace vcf
  {
    namespace assembly_checker
    {

      bool check_vcf_ref(std::istream &vcf_input,
                         std::istream &fasta_input,
                         std::istream &fasta_index_input,
                         std::vector<std::unique_ptr<ebi::vcf::AssemblyReportWriter>> &outputs)
      {
          std::vector<char> vector_line;
          vector_line.reserve(default_line_buffer_size);

          // Reading FASTA index, and querying FASTA file
          auto index = bioio::read_fasta_index(fasta_index_input);

          while (util::readline(vcf_input, vector_line).size() != 0) {
              std::string line{vector_line.begin(), vector_line.end()};
              std::vector<std::string> record_columns;

              if (boost::starts_with(line, "#")) {
                  continue;
              }

              Record_Core record_core{line};

              if (index.count(record_core.chromosome) == 0) {
                  BOOST_LOG_TRIVIAL(warning) << record_core.chromosome << " is not present in FASTA file";
                  continue;
              }

              if (record_core.position == 0) {
                  BOOST_LOG_TRIVIAL(warning) << "Position 0 should only be used for a telomere";
                  continue;
              }

              auto fasta_sequence = bioio::read_fasta_contig(fasta_input,
                                                             index.at(record_core.chromosome),
                                                             record_core.position - 1,
                                                             record_core.reference_allele.length());
              auto reference_sequence = record_core.reference_allele;

              bool match_result = is_matching_sequence(fasta_sequence, reference_sequence);

              for (auto &output : outputs ) {
                  if (match_result) {
                      output->write_match(record_core);
                  } else {
                      output->write_mismatch(record_core);
                  }
              }
          }

          outputs[0]->finish_report();
          return outputs[0]->is_valid_report();
      }

      bool is_matching_sequence(std::string fasta_sequence, std::string reference_sequence)
      {
          std::transform(fasta_sequence.begin(), fasta_sequence.end(), fasta_sequence.begin(), ::tolower);
          std::transform(reference_sequence.begin(), reference_sequence.end(), reference_sequence.begin(), ::tolower);

          return fasta_sequence == reference_sequence;
      }

    }
  }
}
