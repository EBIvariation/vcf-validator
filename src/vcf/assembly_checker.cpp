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
                         const std::string &sourceName,
                         std::istream &fasta_input,
                         std::istream &fasta_index_input,
                         std::vector<std::unique_ptr<ebi::vcf::AssemblyReportWriter>> &outputs)

      {
          std::vector<char> line;
          ebi::vcf::get_magic_num(vcf_input, line);
          std::string file_extension = ebi::vcf::get_compression(sourceName, line);
          ebi::vcf::check_readability_of_file(file_extension);

          if (file_extension == NO_EXT) {
              return process_vcf_ref(vcf_input, fasta_input, fasta_index_input, outputs);
          } else {
              boost::iostreams::filtering_istream uncompressed_input;
              ebi::vcf::create_uncompressed_stream(vcf_input, file_extension, uncompressed_input);
              return process_vcf_ref(uncompressed_input, fasta_input, fasta_index_input, outputs);
          }
      }

      bool process_vcf_ref(std::istream &vcf_input,
                              std::istream &fasta_input,
                              std::istream &fasta_index_input,
                              std::vector<std::unique_ptr<ebi::vcf::AssemblyReportWriter>> &outputs)

      {
          std::vector<char> vector_line;
          vector_line.reserve(default_line_buffer_size);

          // Reading FASTA index, and querying FASTA file
          auto index = bioio::read_fasta_index(fasta_index_input);

          for (size_t line_num = 1; util::readline(vcf_input, vector_line).size() != 0; ++line_num) {
              std::string line{vector_line.begin(), vector_line.end()};

              if (boost::starts_with(line, "#")) {
                  continue;
              }

              RecordCore record_core = build_record_core(line,line_num);

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
                      output->match(record_core);
                  } else {
                      output->mismatch(record_core);
                  }
              }
          }

          outputs[0]->finish_report();
          return outputs[0]->is_valid_report();
      }

      RecordCore build_record_core(std::string const & line, size_t line_num)
      {
          std::vector<std::string> record_columns;
          util::string_split(line, "\t", record_columns);

          std::string chromosome = record_columns[0];
          size_t position = static_cast<size_t>(std::stoi(record_columns[1]));
          std::string reference_allele = record_columns[3];
          std::string alternate_alleles = record_columns[4];

          /*
           * Here the last parameter which is having type `RecordType` is kept `NO_VARIATION`
           *
           * Till now the behaviour of assemblychecker is independent from this parameter.
           * In future this can be modified if needed.
           */
          return RecordCore{line,
                            line_num,
                            chromosome,
                            position,
                            reference_allele,
                            alternate_alleles,
                            vcf::RecordType::NO_VARIATION};
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
