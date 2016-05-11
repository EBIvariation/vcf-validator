/**
 * Copyright 2016 EMBL - European Bioinformatics Institute
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
#define	VCF_OPTIONAL_POLICY_HPP

#include "file_structure.hpp"
#include "parsing_utils.hpp"
#include "record.hpp"

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
        void optional_check_body_entry(ParsingState & state, Record & record) ;//const;
        void optional_check_body_section(ParsingState const & state) const;
        
      private:
        void check_body_entry_ploidy(ParsingState & state, Record & record);
        void check_body_entry_position_zero(ParsingState & state, Record & record) const;
        void check_body_entry_id_commas(ParsingState & state, Record & record) const;
        void check_body_entry_reference_alternate_matching(ParsingState & state, Record & record);
        
        void check_contig_meta(ParsingState & state, Record & record) const;
        void check_alternate_allele_meta(ParsingState & state, Record & record) const;
        void check_filter_meta(ParsingState & state, Record & record) const;
        void check_info_meta(ParsingState & state, Record & record) const;
        void check_format_meta(ParsingState & state, Record & record) const;
    };
    
  }
}

#endif	/* VCF_OPTIONAL_POLICY_HPP */

