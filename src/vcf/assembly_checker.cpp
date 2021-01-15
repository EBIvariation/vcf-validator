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
      size_t const DEFAULT_LINE_BUFFER_SIZE = 64 * 1024;

      bool process_vcf_ref(std::istream & vcf_input,
                           const std::string & fasta,
                           const std::string & assembly_report,
                           std::vector<std::unique_ptr<ebi::vcf::AssemblyCheckReportWriter>> & outputs);

      std::string get_reference_accession(const std::string& reference_tagged_line);

      std::string get_contig_accession(const std::string& contig_tagged_line);

      bool process_vcf_records(std::istream & vcf_input,
                               std::shared_ptr<ebi::vcf::fasta::IFasta> & fasta,
                               const std::string & assembly_report,
                               std::vector<std::unique_ptr<ebi::vcf::AssemblyCheckReportWriter>> & outputs,
                               bool use_fasta_from_ena);

      RecordCore build_record_core(std::string const & line, size_t line_num);

      void report_telomere_position(size_t line_num,
                                    std::vector<std::unique_ptr<ebi::vcf::AssemblyCheckReportWriter>> & outputs);

      std::vector<std::string> get_matching_synonyms_list(ebi::assembly_report::SynonymsMap & synonyms_map,
                                                          size_t line_num,
                                                          RecordCore & record_core,
                                                          const std::shared_ptr<ebi::vcf::fasta::IFasta> & fasta,
                                                          std::vector<std::unique_ptr<ebi::vcf::AssemblyCheckReportWriter>> & outputs);

      void report_missing_chromosome_in_FASTA(size_t line_num,
                                     RecordCore & record_core,
                                     std::vector<std::unique_ptr<ebi::vcf::AssemblyCheckReportWriter>> & outputs);

      void report_missing_chromosome_in_ENA(size_t line_num, std::string exceptionMessage,
                                     RecordCore & record_core,
                                     std::vector<std::unique_ptr<ebi::vcf::AssemblyCheckReportWriter>> & outputs);

      void report_multiple_synonym_match(size_t line_num,
                                         RecordCore & record_core,
                                         std::vector<std::string> found_synonyms,
                                         std::vector<std::unique_ptr<ebi::vcf::AssemblyCheckReportWriter>> & outputs);

      void write_warning_output(std::vector<std::unique_ptr<ebi::vcf::AssemblyCheckReportWriter>> & outputs,
                                std::string warningMessage);

      bool check_vcf_ref(std::istream & vcf_input,
                         const std::string & sourceName,
                         const std::string & fasta_path,
                         const std::string & assembly_report,
                         std::vector<std::unique_ptr<ebi::vcf::AssemblyCheckReportWriter>> & outputs)
      {
          std::vector<char> line;
          ebi::vcf::get_magic_num(vcf_input, line);
          std::string file_extension = ebi::vcf::get_compression(sourceName, line);
          ebi::vcf::check_readability_of_file(file_extension);

          if (file_extension == NO_EXT) {
              return process_vcf_ref(vcf_input, fasta_path, assembly_report, outputs);
          } else {
              boost::iostreams::filtering_istream uncompressed_input;
              ebi::vcf::create_uncompressed_stream(vcf_input, file_extension, uncompressed_input);
              return process_vcf_ref(uncompressed_input, fasta_path, assembly_report, outputs);
          }
      }

      bool process_vcf_ref(std::istream & vcf_input,
                           const std::string & fasta_path,
                           const std::string & assembly_report,
                           std::vector<std::unique_ptr<ebi::vcf::AssemblyCheckReportWriter>> & outputs)
      {
          std::shared_ptr<ebi::vcf::fasta::IFasta> fasta;
          bool use_fasta_from_ena = false;
          if (fasta_path.empty()) { // No local fasta file provided
              std::string reference_accession;
              std::vector<std::string> contigs;
              std::vector<char> vector_line;
              vector_line.reserve(DEFAULT_LINE_BUFFER_SIZE);

              for (size_t line_num = 1; util::readline(vcf_input, vector_line).size() != 0; ++line_num) {
                  std::string line{vector_line.begin(), vector_line.end()};
                  if (boost::starts_with(line, "#")) {
                      for (auto & output : outputs) {
                          output->write_meta_info(line);
                      }
                  }

                  if (!boost::starts_with(line, "##")) {
                      break;
                  }

                  if (boost::starts_with(line, "##reference")) {
                      // trying to get the reference sequence accession
                      reference_accession = get_reference_accession(line);
                      continue;
                  }

                  if (boost::starts_with(line, "##contig")) {
                      // trying to get the contig accession
                      contigs.push_back(get_contig_accession(line));
                  }
              }

              fasta.reset(new ebi::vcf::fasta::RemoteContig());
              if (!reference_accession.empty()) { // second, try with the reference accession with ENA API
                  fasta->sequence(reference_accession, 0, 1); // trigger download
              }

              for (auto contig : contigs) {
                  try {
                      fasta->sequence(contig, 0, 1);
                  }
                  catch(ebi::util::curl::URLRetrievalException ex) {
                      std::string warningMessage = "Could not download sequence for contig/chromosome "
                                                   + contig + " because: " + ex.what();
                      write_warning_output(outputs, warningMessage);
                  }
              }

              use_fasta_from_ena = true;
          }
          else {
              const std::string fasta_index_path = fasta_path + ebi::vcf::INDEX_EXT;
              fasta.reset(new ebi::vcf::fasta::FileBasedFasta(fasta_path, fasta_index_path));
          }

          return process_vcf_records(vcf_input, fasta, assembly_report, outputs, use_fasta_from_ena);
      }

      std::string get_reference_accession(const std::string& reference_tagged_line)
      {
          std::vector<std::string> metadata;
          ebi::util::string_split(reference_tagged_line, "=", metadata);

          if (metadata.size() > 1) {
              std::string reference_value = metadata[1];
              ebi::util::remove_end_of_line(reference_value);

              if (!ebi::util::is_remote_url(reference_value) &&
                  !boost::ends_with(reference_value, ebi::vcf::GZ) &&
                  !boost::ends_with(reference_value, ebi::vcf::FASTA) &&
                  !boost::ends_with(reference_value, ebi::vcf::FASTA_EXT)) {
                  //does not look like a fasta file name, try it as an accession.
                  return reference_value;
              }
          }

          return "";
      }

      std::string get_contig_accession(const std::string& contig_tagged_line)
      {
          size_t pos = contig_tagged_line.find("=<");

          if (pos != std::string::npos) {
              std::string contig_value = contig_tagged_line.substr(pos+2);
              ebi::util::remove_end_of_line(contig_value);
              contig_value.erase(contig_value.size() - 1, 1);

              std::vector<std::string> metadata;
              ebi::util::string_split(contig_value, ",", metadata);

              for (std::string s :  metadata) {
                  if (boost::starts_with(s, "ID=")) {
                      return s.substr(3);
                  }
              }
            }

          return "";
      }

      bool process_vcf_records(std::istream & vcf_input,
                               std::shared_ptr<ebi::vcf::fasta::IFasta> & fasta,
                               const std::string & assembly_report,
                               std::vector<std::unique_ptr<ebi::vcf::AssemblyCheckReportWriter>> & outputs,
                               bool use_fasta_from_ena)
      {
          std::vector<char> vector_line;
          vector_line.reserve(DEFAULT_LINE_BUFFER_SIZE);

          // Create contig synonyms mapping from assembly report
          ebi::assembly_report::SynonymsMap synonyms_map;
          if (assembly_report != ebi::vcf::NO_MAPPING) {
              std::ifstream assembly_report_file;
              ebi::util::open_file(assembly_report_file, assembly_report);
              synonyms_map.parse_assembly_report(assembly_report_file);
          }

          bool is_valid = true;
          for (size_t line_num = 1; util::readline(vcf_input, vector_line).size() != 0; ++line_num) {
              std::string line{vector_line.begin(), vector_line.end()};

              if (boost::starts_with(line, "#")) {
                  for (auto & output : outputs ) {
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
                                                               line_num, record_core, fasta, outputs);
                  if (found_synonyms.size() != 1) {
                      // found zero or more than one synonyms matching in fasta index file
                      is_valid = false;
                      continue;
                  }
                  contig_name = found_synonyms[0];
              }

              if (use_fasta_from_ena && fasta->sequence_exists(contig_name) == 0) {
                  try {
                      fasta->sequence(contig_name, 0, 1); // trigger download
                  }
                  catch(ebi::util::curl::URLRetrievalException ex) {
                      report_missing_chromosome_in_ENA(line_num, ex.what(), record_core, outputs);
                      is_valid = false;
                      continue;
                  }
              }

              if (fasta->sequence_exists(contig_name)==0 || fasta->sequence_length(contig_name)==0) {
                  report_missing_chromosome_in_FASTA(line_num, record_core, outputs);
                  is_valid = false;
                  continue;
              }

              auto fasta_sequence = fasta->sequence(contig_name,
                                                    record_core.position - 1,
                                                    record_core.reference_allele.length());
              auto reference_sequence = record_core.reference_allele;
              bool match_result = ebi::util::is_matching_sequence(fasta_sequence, reference_sequence);

              for (auto & output : outputs ) {
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

      void report_telomere_position(size_t line_num,
                                    std::vector<std::unique_ptr<ebi::vcf::AssemblyCheckReportWriter>> & outputs)
      {
          std::string position_0_warning = "Line " + std::to_string(line_num)
                                           + ": Position 0 should only be used for a telomere";
          write_warning_output(outputs, position_0_warning);
      }

      std::vector<std::string> get_matching_synonyms_list(ebi::assembly_report::SynonymsMap & synonyms_map,
                                  size_t line_num,
                                  RecordCore & record_core,
                                  const std::shared_ptr<ebi::vcf::fasta::IFasta> & fasta,
                                  std::vector<std::unique_ptr<ebi::vcf::AssemblyCheckReportWriter>> & outputs)
      {
          std::vector<std::string> found_synonyms;

          bool is_contig_available = synonyms_map.is_contig_available(record_core.chromosome);
          if (!is_contig_available) {
              throw std::runtime_error("Contig '" + record_core.chromosome + "' not found in assembly report");
          }

          auto & contig_synonyms = synonyms_map.get_contig_synonyms(record_core.chromosome);
          for (auto contig : contig_synonyms) {
              if (fasta->sequence_exists(contig) != 0) {
                  found_synonyms.push_back(contig);
              }
          }

          auto atleast_one_genbank_synonym = std::find_if(contig_synonyms.begin(), contig_synonyms.end(),
                                                          ebi::assembly_report::SynonymsMap::is_a_genbank_accession);
          if(atleast_one_genbank_synonym == contig_synonyms.end()) {
              throw std::runtime_error("No Genbank synonyms found for '" + record_core.chromosome + "' in the assembly report");
          }

          if (found_synonyms.size() == 0) {
              report_missing_chromosome_in_FASTA(line_num, record_core, outputs);
          } else if (found_synonyms.size() > 1) {
              report_multiple_synonym_match(line_num, record_core, found_synonyms, outputs);
          }

          return found_synonyms;
      }

      void report_missing_chromosome_in_ENA(size_t line_num, const std::string exceptionMessage,
              RecordCore & record_core, std::vector<std::unique_ptr<ebi::vcf::AssemblyCheckReportWriter>> & outputs)
      {
          std::string missing_warning = "Line " + std::to_string(line_num)
                                        + ": Chromosome/Contig " + record_core.chromosome
                                        + " could not be retrieved from ENA because: " + exceptionMessage;
          write_warning_output(outputs, missing_warning);
      }

      void report_missing_chromosome_in_FASTA(size_t line_num,
                                     RecordCore & record_core,
                                     std::vector<std::unique_ptr<ebi::vcf::AssemblyCheckReportWriter>> & outputs)
      {
          std::string missing_warning = "Line " + std::to_string(line_num)
                                        + ": Chromosome " + record_core.chromosome + " is not present in FASTA file";
          write_warning_output(outputs, missing_warning);
      }

      void report_multiple_synonym_match(size_t line_num,
                                         RecordCore & record_core,
                                         std::vector<std::string> found_synonyms,
                                         std::vector<std::unique_ptr<ebi::vcf::AssemblyCheckReportWriter>> & outputs)
      {
          std::string multiple_synonym_match_warning = "Line " + std::to_string(line_num)
                    + ": Multiple synonyms " + " found for contig '"
                    + record_core.chromosome + "' in FASTA index file: ";

          for (auto contig : found_synonyms) {
              multiple_synonym_match_warning += contig + " ";
          }

          write_warning_output(outputs, multiple_synonym_match_warning);
      }

      void write_warning_output(std::vector<std::unique_ptr<ebi::vcf::AssemblyCheckReportWriter>> & outputs,
                                std::string warningMessage) {
          for (auto & output : outputs) {
              output->write_warning(warningMessage);
          }
      }

    }
  }
}
