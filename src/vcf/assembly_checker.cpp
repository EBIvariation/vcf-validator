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
                         const std::string &assembly_report,
                         std::vector<std::unique_ptr<ebi::vcf::AssemblyCheckReportWriter>> &outputs)

      {
          std::vector<char> line;
          ebi::vcf::get_magic_num(vcf_input, line);
          std::string file_extension = ebi::vcf::get_compression(sourceName, line);
          ebi::vcf::check_readability_of_file(file_extension);

          if (file_extension == NO_EXT) {
              return process_vcf_ref(vcf_input, fasta_input, fasta_index_input, assembly_report, outputs);
          } else {
              boost::iostreams::filtering_istream uncompressed_input;
              ebi::vcf::create_uncompressed_stream(vcf_input, file_extension, uncompressed_input);
              return process_vcf_ref(uncompressed_input, fasta_input, fasta_index_input, assembly_report, outputs);
          }
      }

      bool process_vcf_ref(std::istream &vcf_input,
                              std::istream &fasta_input,
                              std::istream &fasta_index_input,
                              const std::string &assembly_report,
                              std::vector<std::unique_ptr<ebi::vcf::AssemblyCheckReportWriter>> &outputs)

      {
          std::vector<char> vector_line;
          vector_line.reserve(default_line_buffer_size);

          // create a synonym_map
          ebi::assembly_report::SynonymsMap synonyms_map;
          if (assembly_report != ebi::vcf::NO_MAPPING) {
              std::ifstream assembly_report_file;
              ebi::util::open_file(assembly_report_file, assembly_report);
              synonyms_map.parse_file(assembly_report_file);
          }

          // Reading FASTA index, and querying FASTA file
          auto fasta_index = bioio::read_fasta_index(fasta_index_input);

          bool is_valid = true;
          for (size_t line_num = 1; util::readline(vcf_input, vector_line).size() != 0; ++line_num) {
              std::string line{vector_line.begin(), vector_line.end()};

              if (boost::starts_with(line, "#")) {
                  for (auto &output : outputs ) {
                      output->write_meta_info(line);
                  }
                  continue;
              }

              RecordCore record_core = build_record_core(line, line_num);

              if (record_core.position == 0) {
                  report_telomere_position(line_num,outputs);
                  continue;
              }

              std::string contig_name = record_core.chromosome;
              if (assembly_report != ebi::vcf::NO_MAPPING) {
                  std::vector<std::string> found_synonyms = get_matching_synonyms_list(synonyms_map,
                                                               line_num, record_core, fasta_index, outputs);
                  if(found_synonyms.size() != 1) {
                      // found one or more synonyms matching in fasta index file
                      // so we wont validate the ambigious contig
                      is_valid = false;
                      continue;
                  }
                  contig_name = found_synonyms[0];
              } else {
                  if (fasta_index.count(contig_name) == 0) {
                      report_missing_chromosome(line_num,record_core,outputs);
                      is_valid = false;
                      continue;
                  }
              }

              auto fasta_sequence = bioio::read_fasta_contig(fasta_input,
                                                             fasta_index.at(contig_name),
                                                             record_core.position - 1,
                                                             record_core.reference_allele.length());
              auto reference_sequence = record_core.reference_allele;
              bool match_result = is_matching_sequence(fasta_sequence, reference_sequence);

              for (auto &output : outputs ) {
                  if (match_result) {
                      output->match(line);
                  } else {
                      is_valid = false;
                      output->mismatch(record_core,line,line_num,fasta_sequence);
                  }
              }
          }

          return is_valid;
      }

      std::vector<std::string> get_matching_synonyms_list(ebi::assembly_report::SynonymsMap &synonyms_map,
                                  size_t line_num,
                                  RecordCore &record_core,
                                  bioio::FastaIndex &fasta_index,
                                  std::vector<std::unique_ptr<ebi::vcf::AssemblyCheckReportWriter>> &outputs)
      {
          std::vector<std::string> found_synonyms;

          bool is_contig_available = synonyms_map.is_contig_available(record_core.chromosome);
          if (!is_contig_available) {
              throw std::runtime_error("Contig : " + record_core.chromosome + ", is not found in assembly report");
          }

          auto contig_synonyms = synonyms_map.get_contig_synonyms(record_core.chromosome);
          for (auto contig : contig_synonyms.synonyms) {
              if (fasta_index.count(contig) != 0) {
                  found_synonyms.push_back(contig);
              }
          }

          if (found_synonyms.size() == 0) {
              report_missing_chromosome(line_num, record_core, outputs);
          } else if (found_synonyms.size() > 1) {
              report_multiple_synonym_match(line_num, record_core, found_synonyms, outputs);
          }

          return found_synonyms;
      }

      void report_multiple_synonym_match(size_t line_num,
                                         RecordCore &record_core,
                                         std::vector<std::string> found_synonyms,
                                         std::vector<std::unique_ptr<ebi::vcf::AssemblyCheckReportWriter>> &outputs)
      {
          std::string multiple_synonym_match_warning = "Line " + std::to_string(line_num) + ": Chromosome "
              + record_core.chromosome + " has multiple synonyms present in fasta index file,"
              + " synonyms found : ";

          for (auto contig : found_synonyms) {
              multiple_synonym_match_warning += contig + " ";
          }

          for (auto &output : outputs ) {
              output->write_warning(multiple_synonym_match_warning);
          }

      }

      void report_missing_chromosome(size_t line_num,
                                     RecordCore &record_core,
                                     std::vector<std::unique_ptr<ebi::vcf::AssemblyCheckReportWriter>> &outputs)
      {
          std::string missing_warning = "Line " + std::to_string(line_num)
              + ": Chromosome " + record_core.chromosome + " is not present in FASTA file";
          for (auto &output : outputs ) {
              output->write_warning(missing_warning);
          }
      }

      void report_telomere_position(size_t line_num,
                                    std::vector<std::unique_ptr<ebi::vcf::AssemblyCheckReportWriter>> &outputs)
      {
          std::string position_0_warning = "Line " + std::to_string(line_num)
              + ": Position 0 should only be used for a telomere";
          for (auto &output : outputs ) {
              output->write_warning(position_0_warning);
          }
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
          return RecordCore{line_num,
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
