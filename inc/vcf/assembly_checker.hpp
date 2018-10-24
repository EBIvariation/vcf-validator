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

#include <chrono>
#include <fstream>
#include <set>
#include <vector>

#include <boost/filesystem.hpp>
#include <boost/iostreams/filtering_stream.hpp>
#include <boost/log/trivial.hpp>

#include "assembly_report/assembly_report.hpp"
#include "bioio/bioio.hpp"
#include "vcf/assembly_check_report_writer.hpp"
#include "vcf/compression.hpp"
#include "vcf/file_structure.hpp"
#include "vcf/normalizer.hpp"
#include "vcf/validator.hpp"
#include "util/file_utils.hpp"
#include "util/logger.hpp"
#include "util/stream_utils.hpp"
#include "util/string_utils.hpp"


namespace ebi
{
  namespace vcf
  {
    namespace assembly_checker
    {

      size_t const default_line_buffer_size = 64 * 1024;

      bool check_vcf_ref(std::istream &vcf_input,
                         const std::string &sourceName,
                         std::istream &fasta_input,
                         std::istream &fasta_index_input,
                         const std::string &assembly_report,
                         std::vector<std::unique_ptr<ebi::vcf::AssemblyCheckReportWriter>> &outputs);

      bool process_vcf_ref(std::istream &vcf_input,
                         std::istream &fasta_input,
                         std::istream &fasta_index_input,
                         const std::string &assembly_report,
                         std::vector<std::unique_ptr<ebi::vcf::AssemblyCheckReportWriter>> &outputs);

      bool is_matching_sequence(std::string fasta_sequence, std::string reference_sequence);

      RecordCore build_record_core(std::string const & line, size_t line_num);


      std::vector<std::string> get_matching_synonyms_list(ebi::assembly_report::Synonyms_map &synonyms_map,
                                  size_t line_num,
                                  RecordCore &record_core,
                                  bioio::FastaIndex &fasta_index,
                                  std::vector<std::unique_ptr<ebi::vcf::AssemblyCheckReportWriter>> &outputs);

      void report_multiple_synonym_match(size_t line_num,
                                         RecordCore &record_core,
                                         std::vector<std::string> found_synonyms,
                                         std::vector<std::unique_ptr<ebi::vcf::AssemblyCheckReportWriter>> &outputs);

      void report_missing_chromosome(size_t line_num,
                                     RecordCore &record_core,
                                     std::vector<std::unique_ptr<ebi::vcf::AssemblyCheckReportWriter>> &outputs);

      void report_telomere_position(size_t line_num,
                                    std::vector<std::unique_ptr<ebi::vcf::AssemblyCheckReportWriter>> &outputs);

    }
  }
}

#endif // VCF_ASSEMBLY_CHECKER_HPP
