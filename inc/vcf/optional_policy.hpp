/**
 * Copyright 2017 EMBL - European Bioinformatics Institute
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

#ifndef VCF_OPTIONAL_POLICY_HPP
#define VCF_OPTIONAL_POLICY_HPP

#include "file_structure.hpp"
#include "parsing_state.hpp"
#include "record.hpp"
#include "error.hpp"

namespace ebi
{
  namespace vcf
  {
    
    /**
     * Validation policy that omits optional and context-based validations
     */
    class IgnoreOptionalPolicy
    {
      public:
        void optional_check_meta_section(ParsingState const & state) const {}
        void optional_check_body_entry(ParsingState & state, Record & record) {}
        void optional_check_body_section(ParsingState const & state) const {}
    };
    
    /**
     * Validation policy that runs optional and context-based validations
     */
    class ValidateOptionalPolicy
    {
      public:
        void optional_check_meta_section(ParsingState const & state) const;
        void optional_check_body_entry(ParsingState & state, Record const & record) ;//const;
        void optional_check_body_section(ParsingState const & state) const;

      private:
        void check_body_entry_position_zero(ParsingState & state, Record const & record) const;
        void check_body_entry_id_commas(ParsingState & state, Record const & record) const;
        void check_body_entry_reference_alternate_matching(ParsingState & state, Record const & record);
        void check_body_entry_alt_gvcf_gt_value(ParsingState & state, Record const & record) const;
        bool sample_has_reference_in_all_alleles(std::string const & sample) const;
        void check_body_entry_info_gvcf_end(ParsingState & state, Record const & record) const;
        void check_body_entry_info_imprecise(ParsingState & state, Record const & record) const;
        void check_body_entry_info_other_tag(ParsingState & state, std::multimap<std::string, std::string> const & info,
                                             std::string const & tag) const;
        void check_body_entry_info_svlen(ParsingState & state, Record const & record) const;
        void check_body_entry_info_svclaim(ParsingState & state, Record const & record) const;
        void check_body_entry_info_confidence_interval(ParsingState & state, Record const & record) const;
        void check_body_entry_info_rb_ruc(ParsingState & state, Record const & record) const;
        void check_body_entry_info_rul_rus(ParsingState & state, Record const & record) const;
        void check_contig_meta(ParsingState & state, Record const & record) const;
        void check_alternate_allele_meta(ParsingState & state, Record const & record) const;
        void check_filter_meta(ParsingState & state, Record const & record) const;
        void check_info_meta(ParsingState & state, Record const & record) const;
        void check_format_meta(ParsingState & state, Record const & record) const;
    };
    
  }
}

#endif // VCF_OPTIONAL_POLICY_HPP

