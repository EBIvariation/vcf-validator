
#line 1 "src/vcf/vcf_v42.ragel"
/**
 * Copyright 2014-2015 EMBL - European Bioinformatics Institute
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

#include <cstdio>

#include "vcf/validator.hpp"


#line 748 "src/vcf/vcf_v42.ragel"


namespace
{
  
#line 31 "inc/vcf/validator_detail_v42.hpp"
static const int vcf_v42_start = 1;
static const int vcf_v42_first_final = 730;
static const int vcf_v42_error = 0;

static const int vcf_v42_en_main = 1;
static const int vcf_v42_en_main_meta_section = 28;
static const int vcf_v42_en_main_body_section = 731;
static const int vcf_v42_en_meta_section_skip = 728;
static const int vcf_v42_en_body_section_skip = 729;


#line 754 "src/vcf/vcf_v42.ragel"

}

namespace ebi
{
  namespace vcf
  {
   
    template <typename Configuration>
    ParserImpl_v42<Configuration>::ParserImpl_v42(std::shared_ptr<Source> const & source,
                                                  std::shared_ptr<std::vector<Record>> const & records
    )
    : ParserImpl{source, records}
    {
      
#line 59 "inc/vcf/validator_detail_v42.hpp"
	{
	cs = vcf_v42_start;
	}

#line 770 "src/vcf/vcf_v42.ragel"

    }

    template <typename Configuration>
    void ParserImpl_v42<Configuration>::parse_buffer(char const * p, char const * pe, char const * eof)
    {
      
#line 72 "inc/vcf/validator_detail_v42.hpp"
	{
	if ( p == pe )
		goto _test_eof;
	switch ( cs )
	{
case 1:
	if ( (*p) == 35 )
		goto st2;
	goto tr0;
tr0:
#line 60 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new FileformatError{n_lines});
        p--; {goto st728;}
    }
	goto st0;
tr14:
#line 214 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this,
            new FileformatError{n_lines, "The fileformat declaration is not 'fileformat=VCFv4.2'"});
        p--; {goto st728;}
    }
#line 60 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new FileformatError{n_lines});
        p--; {goto st728;}
    }
	goto st0;
tr23:
#line 60 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new FileformatError{n_lines});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
#line 327 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new HeaderSectionError{n_lines,
            "The header line does not start with the mandatory columns: CHROM, POS, ID, REF, ALT, QUAL, FILTER and INFO"});
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (MetaSectionError *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
        
        p--; {goto st729;}
    }
#line 78 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new HeaderSectionError{n_lines});
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (MetaSectionError *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
        
        p--; {goto st729;}
    }
	goto st0;
tr25:
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
#line 327 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new HeaderSectionError{n_lines,
            "The header line does not start with the mandatory columns: CHROM, POS, ID, REF, ALT, QUAL, FILTER and INFO"});
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (MetaSectionError *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
        
        p--; {goto st729;}
    }
#line 78 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new HeaderSectionError{n_lines});
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (MetaSectionError *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
        
        p--; {goto st729;}
    }
	goto st0;
tr28:
#line 221 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {goto st728;}
    }
#line 245 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {goto st728;}
    }
#line 251 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st728;}
    }
#line 267 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st728;}
    }
#line 233 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in assembly metadata"});
        p--; {goto st728;}
    }
#line 239 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in contig metadata"});
        p--; {goto st728;}
    }
#line 295 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st728;}
    }
#line 283 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {goto st728;}
    }
#line 289 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in pedigreeDB metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	goto st0;
tr38:
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	goto st0;
tr121:
#line 221 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	goto st0;
tr129:
#line 226 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines,
            "ALT metadata ID is not prefixed by DEL/INS/DUP/INV/CNV and suffixed by ':' and a text sequence"});
        p--; {goto st728;}
    }
#line 221 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	goto st0;
tr147:
#line 316 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st728;}
    }
#line 221 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	goto st0;
tr156:
#line 311 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st728;}
    }
#line 221 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	goto st0;
tr170:
#line 311 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st728;}
    }
#line 316 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st728;}
    }
#line 221 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	goto st0;
tr182:
#line 316 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st728;}
    }
#line 311 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st728;}
    }
#line 221 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	goto st0;
tr189:
#line 245 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {goto st728;}
    }
#line 251 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	goto st0;
tr192:
#line 245 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	goto st0;
tr202:
#line 311 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st728;}
    }
#line 245 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	goto st0;
tr221:
#line 316 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st728;}
    }
#line 245 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	goto st0;
tr243:
#line 311 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st728;}
    }
#line 316 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st728;}
    }
#line 245 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	goto st0;
tr255:
#line 316 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st728;}
    }
#line 311 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st728;}
    }
#line 245 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	goto st0;
tr261:
#line 251 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	goto st0;
tr271:
#line 311 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st728;}
    }
#line 251 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	goto st0;
tr284:
#line 256 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "FORMAT metadata Number is not a number, A, R, G or dot"});
        p--; {goto st728;}
    }
#line 251 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	goto st0;
tr293:
#line 277 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "INFO metadata Type is not a Integer, Float, Flag, Character or String"});
        p--; {goto st728;}
    }
#line 251 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	goto st0;
tr310:
#line 316 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st728;}
    }
#line 251 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	goto st0;
tr332:
#line 311 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st728;}
    }
#line 316 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st728;}
    }
#line 251 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	goto st0;
tr344:
#line 316 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st728;}
    }
#line 311 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st728;}
    }
#line 251 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	goto st0;
tr351:
#line 267 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	goto st0;
tr360:
#line 311 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st728;}
    }
#line 267 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	goto st0;
tr373:
#line 272 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "INFO metadata Number is not a number, A, R, G or dot"});
        p--; {goto st728;}
    }
#line 267 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	goto st0;
tr382:
#line 277 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "INFO metadata Type is not a Integer, Float, Flag, Character or String"});
        p--; {goto st728;}
    }
#line 267 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	goto st0;
tr399:
#line 316 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st728;}
    }
#line 267 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	goto st0;
tr421:
#line 311 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st728;}
    }
#line 316 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st728;}
    }
#line 267 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	goto st0;
tr433:
#line 316 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st728;}
    }
#line 311 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st728;}
    }
#line 267 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	goto st0;
tr440:
#line 283 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	goto st0;
tr450:
#line 311 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st728;}
    }
#line 283 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	goto st0;
tr462:
#line 295 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	goto st0;
tr473:
#line 311 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st728;}
    }
#line 295 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	goto st0;
tr478:
#line 311 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st728;}
    }
#line 300 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "SAMPLE metadata Genomes is not a valid string (maybe it contains quotes?)"});
        p--; {goto st728;}
    }
#line 295 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	goto st0;
tr480:
#line 300 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "SAMPLE metadata Genomes is not a valid string (maybe it contains quotes?)"});
        p--; {goto st728;}
    }
#line 295 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	goto st0;
tr490:
#line 300 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "SAMPLE metadata Genomes is not a valid string (maybe it contains quotes?)"});
        p--; {goto st728;}
    }
#line 305 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "SAMPLE metadata Mixture is not a valid string (maybe it contains quotes?)"});
        p--; {goto st728;}
    }
#line 295 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	goto st0;
tr493:
#line 305 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "SAMPLE metadata Mixture is not a valid string (maybe it contains quotes?)"});
        p--; {goto st728;}
    }
#line 295 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	goto st0;
tr503:
#line 305 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "SAMPLE metadata Mixture is not a valid string (maybe it contains quotes?)"});
        p--; {goto st728;}
    }
#line 316 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st728;}
    }
#line 295 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	goto st0;
tr506:
#line 316 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st728;}
    }
#line 295 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	goto st0;
tr529:
#line 233 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in assembly metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	goto st0;
tr538:
#line 321 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata URL is not valid"});
        p--; {goto st728;}
    }
#line 233 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in assembly metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	goto st0;
tr545:
#line 239 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in contig metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	goto st0;
tr556:
#line 311 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st728;}
    }
#line 239 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in contig metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	goto st0;
tr595:
#line 289 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in pedigreeDB metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	goto st0;
tr607:
#line 321 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata URL is not valid"});
        p--; {goto st728;}
    }
#line 289 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in pedigreeDB metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	goto st0;
tr615:
#line 327 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new HeaderSectionError{n_lines,
            "The header line does not start with the mandatory columns: CHROM, POS, ID, REF, ALT, QUAL, FILTER and INFO"});
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (MetaSectionError *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
        
        p--; {goto st729;}
    }
#line 78 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new HeaderSectionError{n_lines});
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (MetaSectionError *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
        
        p--; {goto st729;}
    }
	goto st0;
tr654:
#line 78 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new HeaderSectionError{n_lines});
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (MetaSectionError *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
        
        p--; {goto st729;}
    }
	goto st0;
tr666:
#line 344 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new ChromosomeBodyError{n_lines});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	goto st0;
tr670:
#line 350 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new PositionBodyError{n_lines});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	goto st0;
tr675:
#line 356 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new IdBodyError{n_lines});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	goto st0;
tr680:
#line 362 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new ReferenceAlleleBodyError{n_lines});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	goto st0;
tr684:
#line 368 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new AlternateAllelesBodyError{n_lines});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	goto st0;
tr693:
#line 374 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new QualityBodyError{n_lines});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	goto st0;
tr705:
#line 380 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new FilterBodyError{n_lines});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	goto st0;
tr713:
#line 391 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info key is not a sequence of alphanumeric and/or punctuation characters"});
        p--; {goto st729;}
    }
#line 386 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	goto st0;
tr734:
#line 492 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new FormatBodyError{n_lines});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	goto st0;
tr739:
#line 505 "src/vcf/vcf_v42.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " does not start with a valid genotype";
        ErrorPolicy::handle_error(*this, new SamplesBodyError{n_lines, message_stream.str()});
        p--; {goto st729;}
    }
#line 498 "src/vcf/vcf_v42.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " is not a valid string";
        ErrorPolicy::handle_error(*this, new SamplesBodyError{n_lines, message_stream.str()});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	goto st0;
tr751:
#line 498 "src/vcf/vcf_v42.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " is not a valid string";
        ErrorPolicy::handle_error(*this, new SamplesBodyError{n_lines, message_stream.str()});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	goto st0;
tr757:
#line 396 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info field value is not a comma-separated list of valid strings (maybe it contains whitespaces?)"});
        p--; {goto st729;}
    }
#line 386 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	goto st0;
tr759:
#line 486 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info 1000G is not a flag (with 1/0/no value)"});
        p--; {goto st729;}
    }
#line 391 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info key is not a sequence of alphanumeric and/or punctuation characters"});
        p--; {goto st729;}
    }
#line 386 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	goto st0;
tr761:
#line 486 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info 1000G is not a flag (with 1/0/no value)"});
        p--; {goto st729;}
    }
#line 386 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	goto st0;
tr768:
#line 401 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info AA value is not a single dot or a string of bases"});
        p--; {goto st729;}
    }
#line 386 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	goto st0;
tr772:
#line 406 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info AC value is not a comma-separated list of numbers"});
        p--; {goto st729;}
    }
#line 386 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	goto st0;
tr776:
#line 411 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info AF value is not a comma-separated list of numbers"});
        p--; {goto st729;}
    }
#line 386 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	goto st0;
tr790:
#line 416 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info AN value is not an integer number"});
        p--; {goto st729;}
    }
#line 386 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	goto st0;
tr795:
#line 421 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info BQ value is not a number"});
        p--; {goto st729;}
    }
#line 386 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	goto st0;
tr813:
#line 426 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info CIGAR value is not an alphanumeric string"});
        p--; {goto st729;}
    }
#line 386 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	goto st0;
tr817:
#line 431 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info DB is not a flag (with 1/0/no value)"});
        p--; {goto st729;}
    }
#line 391 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info key is not a sequence of alphanumeric and/or punctuation characters"});
        p--; {goto st729;}
    }
#line 386 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	goto st0;
tr819:
#line 431 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info DB is not a flag (with 1/0/no value)"});
        p--; {goto st729;}
    }
#line 386 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	goto st0;
tr822:
#line 436 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info DP value is not an integer number"});
        p--; {goto st729;}
    }
#line 386 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	goto st0;
tr828:
#line 441 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info END value is not an integer number"});
        p--; {goto st729;}
    }
#line 386 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	goto st0;
tr833:
#line 446 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info H2 is not a flag (with 1/0/no value)"});
        p--; {goto st729;}
    }
#line 391 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info key is not a sequence of alphanumeric and/or punctuation characters"});
        p--; {goto st729;}
    }
#line 386 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	goto st0;
tr835:
#line 446 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info H2 is not a flag (with 1/0/no value)"});
        p--; {goto st729;}
    }
#line 386 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	goto st0;
tr837:
#line 451 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info H3 is not a flag (with 1/0/no value)"});
        p--; {goto st729;}
    }
#line 391 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info key is not a sequence of alphanumeric and/or punctuation characters"});
        p--; {goto st729;}
    }
#line 386 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	goto st0;
tr839:
#line 451 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info H3 is not a flag (with 1/0/no value)"});
        p--; {goto st729;}
    }
#line 386 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	goto st0;
tr845:
#line 461 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info MQ0 value is not an integer number"});
        p--; {goto st729;}
    }
#line 386 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	goto st0;
tr848:
#line 456 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info MQ value is not a number"});
        p--; {goto st729;}
    }
#line 386 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	goto st0;
tr863:
#line 466 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info NS value is not an integer number"});
        p--; {goto st729;}
    }
#line 386 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	goto st0;
tr869:
#line 471 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info SB value is not a number"});
        p--; {goto st729;}
    }
#line 386 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	goto st0;
tr887:
#line 476 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info SOMATIC is not a flag (with 1/0/no value)"});
        p--; {goto st729;}
    }
#line 391 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info key is not a sequence of alphanumeric and/or punctuation characters"});
        p--; {goto st729;}
    }
#line 386 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	goto st0;
tr889:
#line 476 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info SOMATIC is not a flag (with 1/0/no value)"});
        p--; {goto st729;}
    }
#line 386 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	goto st0;
tr899:
#line 481 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info VALIDATED is not a flag (with 1/0/no value)"});
        p--; {goto st729;}
    }
#line 391 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info key is not a sequence of alphanumeric and/or punctuation characters"});
        p--; {goto st729;}
    }
#line 386 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	goto st0;
tr901:
#line 481 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info VALIDATED is not a flag (with 1/0/no value)"});
        p--; {goto st729;}
    }
#line 386 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	goto st0;
tr965:
#line 78 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new HeaderSectionError{n_lines});
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (MetaSectionError *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
        
        p--; {goto st729;}
    }
#line 344 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new ChromosomeBodyError{n_lines});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	goto st0;
#line 1631 "inc/vcf/validator_detail_v42.hpp"
st0:
cs = 0;
	goto _out;
st2:
	if ( ++p == pe )
		goto _test_eof2;
case 2:
	if ( (*p) == 35 )
		goto st3;
	goto tr0;
st3:
	if ( ++p == pe )
		goto _test_eof3;
case 3:
	if ( (*p) == 102 )
		goto st4;
	goto tr0;
st4:
	if ( ++p == pe )
		goto _test_eof4;
case 4:
	if ( (*p) == 105 )
		goto st5;
	goto tr0;
st5:
	if ( ++p == pe )
		goto _test_eof5;
case 5:
	if ( (*p) == 108 )
		goto st6;
	goto tr0;
st6:
	if ( ++p == pe )
		goto _test_eof6;
case 6:
	if ( (*p) == 101 )
		goto st7;
	goto tr0;
st7:
	if ( ++p == pe )
		goto _test_eof7;
case 7:
	if ( (*p) == 102 )
		goto st8;
	goto tr0;
st8:
	if ( ++p == pe )
		goto _test_eof8;
case 8:
	if ( (*p) == 111 )
		goto st9;
	goto tr0;
st9:
	if ( ++p == pe )
		goto _test_eof9;
case 9:
	if ( (*p) == 114 )
		goto st10;
	goto tr0;
st10:
	if ( ++p == pe )
		goto _test_eof10;
case 10:
	if ( (*p) == 109 )
		goto st11;
	goto tr0;
st11:
	if ( ++p == pe )
		goto _test_eof11;
case 11:
	if ( (*p) == 97 )
		goto st12;
	goto tr0;
st12:
	if ( ++p == pe )
		goto _test_eof12;
case 12:
	if ( (*p) == 116 )
		goto st13;
	goto tr0;
st13:
	if ( ++p == pe )
		goto _test_eof13;
case 13:
	if ( (*p) == 61 )
		goto st14;
	goto tr0;
st14:
	if ( ++p == pe )
		goto _test_eof14;
case 14:
	if ( (*p) == 86 )
		goto tr15;
	goto tr14;
tr15:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st15;
st15:
	if ( ++p == pe )
		goto _test_eof15;
case 15:
#line 1740 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 67 )
		goto tr16;
	goto tr14;
tr16:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st16;
st16:
	if ( ++p == pe )
		goto _test_eof16;
case 16:
#line 1754 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 70 )
		goto tr17;
	goto tr14;
tr17:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st17;
st17:
	if ( ++p == pe )
		goto _test_eof17;
case 17:
#line 1768 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 118 )
		goto tr18;
	goto tr14;
tr18:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st18;
st18:
	if ( ++p == pe )
		goto _test_eof18;
case 18:
#line 1782 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 52 )
		goto tr19;
	goto tr14;
tr19:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st19;
st19:
	if ( ++p == pe )
		goto _test_eof19;
case 19:
#line 1796 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 46 )
		goto tr20;
	goto tr14;
tr20:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st20;
st20:
	if ( ++p == pe )
		goto _test_eof20;
case 20:
#line 1810 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 50 )
		goto tr21;
	goto tr14;
tr21:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st21;
st21:
	if ( ++p == pe )
		goto _test_eof21;
case 21:
#line 1824 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 10 )
		goto tr22;
	goto tr14;
tr22:
#line 99 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_fileformat(*this);
    }
#line 43 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st22;
st22:
	if ( ++p == pe )
		goto _test_eof22;
case 22:
#line 1848 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 35 )
		goto st23;
	goto tr23;
st23:
	if ( ++p == pe )
		goto _test_eof23;
case 23:
	switch( (*p) ) {
		case 35: goto st24;
		case 67: goto st441;
	}
	goto tr25;
st24:
	if ( ++p == pe )
		goto _test_eof24;
case 24:
	switch( (*p) ) {
		case 65: goto tr30;
		case 70: goto tr31;
		case 73: goto tr32;
		case 80: goto tr33;
		case 83: goto tr34;
		case 97: goto tr35;
		case 99: goto tr36;
		case 112: goto tr37;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto tr29;
	} else if ( (*p) >= 32 )
		goto tr29;
	goto tr28;
tr29:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st25;
tr39:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st25;
st25:
	if ( ++p == pe )
		goto _test_eof25;
case 25:
#line 1901 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 61 )
		goto tr40;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr38;
tr40:
#line 163 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this);
    }
	goto st26;
st26:
	if ( ++p == pe )
		goto _test_eof26;
case 26:
#line 1917 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto st29;
		case 60: goto st34;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr38;
tr41:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st27;
tr45:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st27;
st27:
	if ( ++p == pe )
		goto _test_eof27;
case 27:
#line 1945 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 10 )
		goto tr44;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr45;
	goto tr38;
tr44:
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 171 "src/vcf/vcf_v42.ragel"
	{
        try {
          ParsePolicy::handle_meta_line(*this);
        } catch (MetaSectionError *error) {
          ErrorPolicy::handle_error(*this, error);
        }
    }
#line 43 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st28;
tr52:
#line 171 "src/vcf/vcf_v42.ragel"
	{
        try {
          ParsePolicy::handle_meta_line(*this);
        } catch (MetaSectionError *error) {
          ErrorPolicy::handle_error(*this, error);
        }
    }
#line 43 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st28;
st28:
	if ( ++p == pe )
		goto _test_eof28;
case 28:
#line 1999 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 35 )
		goto st23;
	goto tr25;
st29:
	if ( ++p == pe )
		goto _test_eof29;
case 29:
	switch( (*p) ) {
		case 34: goto tr47;
		case 92: goto tr48;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr46;
	goto tr38;
tr46:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st30;
tr49:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st30;
st30:
	if ( ++p == pe )
		goto _test_eof30;
case 30:
#line 2034 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr50;
		case 92: goto tr51;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr49;
	goto tr38;
tr47:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st31;
tr50:
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st31;
st31:
	if ( ++p == pe )
		goto _test_eof31;
case 31:
#line 2062 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 10 )
		goto tr52;
	goto tr38;
tr48:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st32;
tr51:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st32;
st32:
	if ( ++p == pe )
		goto _test_eof32;
case 32:
#line 2086 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr53;
		case 92: goto tr51;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr49;
	goto tr38;
tr53:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st33;
st33:
	if ( ++p == pe )
		goto _test_eof33;
case 33:
#line 2108 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 10: goto tr52;
		case 34: goto tr50;
		case 92: goto tr51;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr49;
	goto tr38;
st34:
	if ( ++p == pe )
		goto _test_eof34;
case 34:
	switch( (*p) ) {
		case 34: goto st35;
		case 95: goto tr55;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr55;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr56;
		} else if ( (*p) >= 65 )
			goto tr56;
	} else
		goto tr56;
	goto tr38;
st35:
	if ( ++p == pe )
		goto _test_eof35;
case 35:
	switch( (*p) ) {
		case 34: goto tr58;
		case 92: goto tr59;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr57;
	goto tr38;
tr57:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st36;
tr60:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st36;
st36:
	if ( ++p == pe )
		goto _test_eof36;
case 36:
#line 2168 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr61;
		case 92: goto tr62;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr60;
	goto tr38;
tr58:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st37;
tr61:
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st37;
st37:
	if ( ++p == pe )
		goto _test_eof37;
case 37:
#line 2196 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 62 )
		goto st31;
	goto tr38;
tr59:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st38;
tr62:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st38;
st38:
	if ( ++p == pe )
		goto _test_eof38;
case 38:
#line 2220 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr64;
		case 92: goto tr62;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr60;
	goto tr38;
tr64:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st39;
st39:
	if ( ++p == pe )
		goto _test_eof39;
case 39:
#line 2242 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr61;
		case 62: goto tr65;
		case 92: goto tr62;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr60;
	goto tr38;
tr65:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st40;
st40:
	if ( ++p == pe )
		goto _test_eof40;
case 40:
#line 2261 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 10: goto tr52;
		case 34: goto tr61;
		case 92: goto tr62;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr60;
	goto tr38;
tr55:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st41;
st41:
	if ( ++p == pe )
		goto _test_eof41;
case 41:
#line 2280 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 95 )
		goto st41;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st41;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr67;
		} else if ( (*p) >= 65 )
			goto tr67;
	} else
		goto tr67;
	goto tr38;
tr56:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st42;
tr67:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st42;
st42:
	if ( ++p == pe )
		goto _test_eof42;
case 42:
#line 2315 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr68;
		case 95: goto tr67;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr67;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr67;
		} else if ( (*p) >= 65 )
			goto tr67;
	} else
		goto tr67;
	goto tr38;
tr68:
#line 167 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st43;
st43:
	if ( ++p == pe )
		goto _test_eof43;
case 43:
#line 2342 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 34 )
		goto st62;
	if ( (*p) < 45 ) {
		if ( 32 <= (*p) && (*p) <= 43 )
			goto tr69;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr69;
	} else
		goto tr69;
	goto tr38;
tr69:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st44;
tr71:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st44;
st44:
	if ( ++p == pe )
		goto _test_eof44;
case 44:
#line 2374 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 44: goto tr72;
		case 62: goto tr50;
	}
	if ( (*p) > 33 ) {
		if ( 35 <= (*p) && (*p) <= 126 )
			goto tr71;
	} else if ( (*p) >= 32 )
		goto tr71;
	goto tr38;
tr72:
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st45;
st45:
	if ( ++p == pe )
		goto _test_eof45;
case 45:
#line 2395 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 95 )
		goto tr73;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr73;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr74;
		} else if ( (*p) >= 65 )
			goto tr74;
	} else
		goto tr74;
	goto tr38;
tr73:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st46;
st46:
	if ( ++p == pe )
		goto _test_eof46;
case 46:
#line 2420 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 95 )
		goto st46;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st46;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr76;
		} else if ( (*p) >= 65 )
			goto tr76;
	} else
		goto tr76;
	goto tr38;
tr74:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st47;
tr76:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st47;
st47:
	if ( ++p == pe )
		goto _test_eof47;
case 47:
#line 2455 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr77;
		case 95: goto tr76;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr76;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr76;
		} else if ( (*p) >= 65 )
			goto tr76;
	} else
		goto tr76;
	goto tr38;
tr77:
#line 167 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st48;
st48:
	if ( ++p == pe )
		goto _test_eof48;
case 48:
#line 2482 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 34 )
		goto st49;
	if ( (*p) < 45 ) {
		if ( 32 <= (*p) && (*p) <= 43 )
			goto tr69;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr69;
	} else
		goto tr69;
	goto tr38;
st49:
	if ( ++p == pe )
		goto _test_eof49;
case 49:
	switch( (*p) ) {
		case 34: goto tr80;
		case 92: goto tr81;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr79;
	goto tr38;
tr79:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st50;
tr82:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st50;
st50:
	if ( ++p == pe )
		goto _test_eof50;
case 50:
#line 2525 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr83;
		case 92: goto tr84;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr82;
	goto tr38;
tr80:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st51;
tr83:
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st51;
st51:
	if ( ++p == pe )
		goto _test_eof51;
case 51:
#line 2553 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 44: goto st45;
		case 62: goto st31;
	}
	goto tr38;
tr81:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st52;
tr84:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st52;
st52:
	if ( ++p == pe )
		goto _test_eof52;
case 52:
#line 2579 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr86;
		case 92: goto tr84;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr82;
	goto tr38;
tr86:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st53;
st53:
	if ( ++p == pe )
		goto _test_eof53;
case 53:
#line 2601 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr83;
		case 44: goto tr87;
		case 62: goto tr88;
		case 92: goto tr84;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr82;
	goto tr38;
tr101:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st54;
tr87:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st54;
tr98:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st54;
st54:
	if ( ++p == pe )
		goto _test_eof54;
case 54:
#line 2641 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr83;
		case 47: goto tr82;
		case 92: goto tr84;
		case 95: goto tr89;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr82;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr90;
		} else
			goto tr89;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr90;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr82;
			} else if ( (*p) >= 97 )
				goto tr90;
		} else
			goto tr82;
	} else
		goto tr82;
	goto tr38;
tr89:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st55;
tr91:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st55;
st55:
	if ( ++p == pe )
		goto _test_eof55;
case 55:
#line 2692 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr83;
		case 47: goto tr82;
		case 92: goto tr84;
		case 95: goto tr91;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr82;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr92;
		} else
			goto tr91;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr92;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr82;
			} else if ( (*p) >= 97 )
				goto tr92;
		} else
			goto tr82;
	} else
		goto tr82;
	goto tr38;
tr90:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st56;
tr92:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st56;
st56:
	if ( ++p == pe )
		goto _test_eof56;
case 56:
#line 2743 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr83;
		case 47: goto tr82;
		case 61: goto tr93;
		case 92: goto tr84;
		case 95: goto tr92;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr82;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr82;
		} else
			goto tr92;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr82;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr82;
		} else
			goto tr92;
	} else
		goto tr92;
	goto tr38;
tr93:
#line 167 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st57;
st57:
	if ( ++p == pe )
		goto _test_eof57;
case 57:
#line 2786 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr95;
		case 44: goto tr82;
		case 62: goto tr82;
		case 92: goto tr96;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr94;
	goto tr38;
tr97:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st58;
tr94:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st58;
st58:
	if ( ++p == pe )
		goto _test_eof58;
case 58:
#line 2816 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr83;
		case 44: goto tr98;
		case 62: goto tr99;
		case 92: goto tr100;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr97;
	goto tr38;
tr102:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st59;
tr88:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st59;
tr99:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st59;
st59:
	if ( ++p == pe )
		goto _test_eof59;
case 59:
#line 2856 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 10: goto tr52;
		case 34: goto tr83;
		case 92: goto tr84;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr82;
	goto tr38;
tr100:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st60;
tr96:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st60;
st60:
	if ( ++p == pe )
		goto _test_eof60;
case 60:
#line 2885 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr86;
		case 44: goto tr98;
		case 62: goto tr99;
		case 92: goto tr100;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr97;
	goto tr38;
tr95:
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st61;
st61:
	if ( ++p == pe )
		goto _test_eof61;
case 61:
#line 2905 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr80;
		case 44: goto tr101;
		case 62: goto tr102;
		case 92: goto tr81;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr79;
	goto tr38;
st62:
	if ( ++p == pe )
		goto _test_eof62;
case 62:
	switch( (*p) ) {
		case 34: goto tr80;
		case 92: goto tr104;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr103;
	goto tr38;
tr103:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st63;
tr105:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st63;
st63:
	if ( ++p == pe )
		goto _test_eof63;
case 63:
#line 2946 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr83;
		case 92: goto tr106;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr105;
	goto tr38;
tr104:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st64;
tr106:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st64;
st64:
	if ( ++p == pe )
		goto _test_eof64;
case 64:
#line 2974 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr107;
		case 92: goto tr106;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr105;
	goto tr38;
tr107:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st65;
st65:
	if ( ++p == pe )
		goto _test_eof65;
case 65:
#line 2996 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr83;
		case 44: goto tr108;
		case 62: goto tr109;
		case 92: goto tr106;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr105;
	goto tr38;
tr108:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st66;
tr118:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st66;
st66:
	if ( ++p == pe )
		goto _test_eof66;
case 66:
#line 3026 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr83;
		case 47: goto tr105;
		case 92: goto tr106;
		case 95: goto tr110;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr105;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr111;
		} else
			goto tr110;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr111;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr105;
			} else if ( (*p) >= 97 )
				goto tr111;
		} else
			goto tr105;
	} else
		goto tr105;
	goto tr38;
tr112:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st67;
tr110:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st67;
st67:
	if ( ++p == pe )
		goto _test_eof67;
case 67:
#line 3077 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr83;
		case 47: goto tr105;
		case 92: goto tr106;
		case 95: goto tr112;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr105;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr113;
		} else
			goto tr112;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr113;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr105;
			} else if ( (*p) >= 97 )
				goto tr113;
		} else
			goto tr105;
	} else
		goto tr105;
	goto tr38;
tr113:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st68;
tr111:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st68;
st68:
	if ( ++p == pe )
		goto _test_eof68;
case 68:
#line 3128 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr83;
		case 47: goto tr105;
		case 61: goto tr114;
		case 92: goto tr106;
		case 95: goto tr113;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr105;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr105;
		} else
			goto tr113;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr105;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr105;
		} else
			goto tr113;
	} else
		goto tr113;
	goto tr38;
tr114:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 167 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st69;
st69:
	if ( ++p == pe )
		goto _test_eof69;
case 69:
#line 3171 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr95;
		case 44: goto tr105;
		case 62: goto tr105;
		case 92: goto tr116;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr115;
	goto tr38;
tr117:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st70;
tr115:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st70;
st70:
	if ( ++p == pe )
		goto _test_eof70;
case 70:
#line 3201 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr83;
		case 44: goto tr118;
		case 62: goto tr119;
		case 92: goto tr120;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr117;
	goto tr38;
tr109:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st71;
tr119:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st71;
st71:
	if ( ++p == pe )
		goto _test_eof71;
case 71:
#line 3231 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 10: goto tr52;
		case 34: goto tr83;
		case 92: goto tr106;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr105;
	goto tr38;
tr120:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st72;
tr116:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st72;
st72:
	if ( ++p == pe )
		goto _test_eof72;
case 72:
#line 3260 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr107;
		case 44: goto tr118;
		case 62: goto tr119;
		case 92: goto tr120;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr117;
	goto tr38;
tr30:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st73;
st73:
	if ( ++p == pe )
		goto _test_eof73;
case 73:
#line 3284 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 76: goto tr122;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr121;
tr122:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st74;
st74:
	if ( ++p == pe )
		goto _test_eof74;
case 74:
#line 3302 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 84: goto st75;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr121;
st75:
	if ( ++p == pe )
		goto _test_eof75;
case 75:
	if ( (*p) == 61 )
		goto tr124;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr121;
tr124:
#line 103 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "ALT");
    }
	goto st76;
st76:
	if ( ++p == pe )
		goto _test_eof76;
case 76:
#line 3329 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 60 )
		goto st77;
	goto tr121;
st77:
	if ( ++p == pe )
		goto _test_eof77;
case 77:
	if ( (*p) == 73 )
		goto st78;
	goto tr121;
st78:
	if ( ++p == pe )
		goto _test_eof78;
case 78:
	if ( (*p) == 68 )
		goto st79;
	goto tr121;
st79:
	if ( ++p == pe )
		goto _test_eof79;
case 79:
	if ( (*p) == 61 )
		goto st80;
	goto tr121;
st80:
	if ( ++p == pe )
		goto _test_eof80;
case 80:
	switch( (*p) ) {
		case 58: goto tr131;
		case 95: goto tr131;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr130;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr130;
	} else
		goto tr130;
	goto tr129;
tr133:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st81;
tr130:
#line 139 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st81;
st81:
	if ( ++p == pe )
		goto _test_eof81;
case 81:
#line 3395 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 44: goto tr132;
		case 95: goto tr133;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 58 )
			goto tr133;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr133;
	} else
		goto tr133;
	goto tr129;
tr132:
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st82;
st82:
	if ( ++p == pe )
		goto _test_eof82;
case 82:
#line 3419 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 68 )
		goto st83;
	goto tr121;
st83:
	if ( ++p == pe )
		goto _test_eof83;
case 83:
	if ( (*p) == 101 )
		goto st84;
	goto tr121;
st84:
	if ( ++p == pe )
		goto _test_eof84;
case 84:
	if ( (*p) == 115 )
		goto st85;
	goto tr121;
st85:
	if ( ++p == pe )
		goto _test_eof85;
case 85:
	if ( (*p) == 99 )
		goto st86;
	goto tr121;
st86:
	if ( ++p == pe )
		goto _test_eof86;
case 86:
	if ( (*p) == 114 )
		goto st87;
	goto tr121;
st87:
	if ( ++p == pe )
		goto _test_eof87;
case 87:
	if ( (*p) == 105 )
		goto st88;
	goto tr121;
st88:
	if ( ++p == pe )
		goto _test_eof88;
case 88:
	if ( (*p) == 112 )
		goto st89;
	goto tr121;
st89:
	if ( ++p == pe )
		goto _test_eof89;
case 89:
	if ( (*p) == 116 )
		goto st90;
	goto tr121;
st90:
	if ( ++p == pe )
		goto _test_eof90;
case 90:
	if ( (*p) == 105 )
		goto st91;
	goto tr121;
st91:
	if ( ++p == pe )
		goto _test_eof91;
case 91:
	if ( (*p) == 111 )
		goto st92;
	goto tr121;
st92:
	if ( ++p == pe )
		goto _test_eof92;
case 92:
	if ( (*p) == 110 )
		goto st93;
	goto tr121;
st93:
	if ( ++p == pe )
		goto _test_eof93;
case 93:
	if ( (*p) == 61 )
		goto st94;
	goto tr121;
st94:
	if ( ++p == pe )
		goto _test_eof94;
case 94:
	if ( (*p) == 34 )
		goto tr146;
	goto tr121;
tr146:
#line 151 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Description");
    }
	goto st95;
st95:
	if ( ++p == pe )
		goto _test_eof95;
case 95:
#line 3517 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr149;
		case 92: goto tr150;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr148;
	goto tr147;
tr148:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st96;
tr151:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st96;
st96:
	if ( ++p == pe )
		goto _test_eof96;
case 96:
#line 3545 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr152;
		case 92: goto tr153;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr151;
	goto tr147;
tr149:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st97;
tr152:
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st97;
st97:
	if ( ++p == pe )
		goto _test_eof97;
case 97:
#line 3573 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 44: goto st98;
		case 62: goto st112;
	}
	goto tr147;
st98:
	if ( ++p == pe )
		goto _test_eof98;
case 98:
	if ( (*p) == 95 )
		goto tr157;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr157;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr158;
		} else if ( (*p) >= 65 )
			goto tr158;
	} else
		goto tr158;
	goto tr156;
tr157:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st99;
st99:
	if ( ++p == pe )
		goto _test_eof99;
case 99:
#line 3607 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 95 )
		goto st99;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st99;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr160;
		} else if ( (*p) >= 65 )
			goto tr160;
	} else
		goto tr160;
	goto tr156;
tr158:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st100;
tr160:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st100;
st100:
	if ( ++p == pe )
		goto _test_eof100;
case 100:
#line 3642 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr161;
		case 95: goto tr160;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr160;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr160;
		} else if ( (*p) >= 65 )
			goto tr160;
	} else
		goto tr160;
	goto tr156;
tr161:
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st101;
st101:
	if ( ++p == pe )
		goto _test_eof101;
case 101:
#line 3669 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 34 )
		goto st102;
	goto tr121;
st102:
	if ( ++p == pe )
		goto _test_eof102;
case 102:
	switch( (*p) ) {
		case 34: goto tr149;
		case 92: goto tr164;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr163;
	goto tr147;
tr163:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st103;
tr165:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st103;
st103:
	if ( ++p == pe )
		goto _test_eof103;
case 103:
#line 3704 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr152;
		case 92: goto tr166;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr165;
	goto tr147;
tr164:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st104;
tr166:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st104;
st104:
	if ( ++p == pe )
		goto _test_eof104;
case 104:
#line 3732 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr167;
		case 92: goto tr166;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr165;
	goto tr147;
tr167:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st105;
st105:
	if ( ++p == pe )
		goto _test_eof105;
case 105:
#line 3754 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr152;
		case 44: goto tr168;
		case 62: goto tr169;
		case 92: goto tr166;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr165;
	goto tr147;
tr177:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st106;
tr168:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st106;
st106:
	if ( ++p == pe )
		goto _test_eof106;
case 106:
#line 3784 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr152;
		case 47: goto tr165;
		case 92: goto tr166;
		case 95: goto tr171;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr165;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr172;
		} else
			goto tr171;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr172;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr165;
			} else if ( (*p) >= 97 )
				goto tr172;
		} else
			goto tr165;
	} else
		goto tr165;
	goto tr170;
tr171:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st107;
tr173:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st107;
st107:
	if ( ++p == pe )
		goto _test_eof107;
case 107:
#line 3835 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr152;
		case 47: goto tr165;
		case 92: goto tr166;
		case 95: goto tr173;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr165;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr174;
		} else
			goto tr173;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr174;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr165;
			} else if ( (*p) >= 97 )
				goto tr174;
		} else
			goto tr165;
	} else
		goto tr165;
	goto tr170;
tr172:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st108;
tr174:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st108;
st108:
	if ( ++p == pe )
		goto _test_eof108;
case 108:
#line 3886 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr152;
		case 47: goto tr165;
		case 61: goto tr175;
		case 92: goto tr166;
		case 95: goto tr174;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr165;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr165;
		} else
			goto tr174;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr165;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr165;
		} else
			goto tr174;
	} else
		goto tr174;
	goto tr170;
tr175:
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st109;
st109:
	if ( ++p == pe )
		goto _test_eof109;
case 109:
#line 3929 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr176;
		case 92: goto tr166;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr165;
	goto tr147;
tr176:
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st110;
st110:
	if ( ++p == pe )
		goto _test_eof110;
case 110:
#line 3947 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr149;
		case 44: goto tr177;
		case 62: goto tr178;
		case 92: goto tr164;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr163;
	goto tr147;
tr178:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st111;
tr169:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st111;
st111:
	if ( ++p == pe )
		goto _test_eof111;
case 111:
#line 3977 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 10: goto tr52;
		case 34: goto tr152;
		case 92: goto tr166;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr165;
	goto tr147;
st112:
	if ( ++p == pe )
		goto _test_eof112;
case 112:
	if ( (*p) == 10 )
		goto tr52;
	goto tr121;
tr150:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st113;
tr153:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st113;
st113:
	if ( ++p == pe )
		goto _test_eof113;
case 113:
#line 4013 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr179;
		case 92: goto tr153;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr151;
	goto tr147;
tr179:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st114;
st114:
	if ( ++p == pe )
		goto _test_eof114;
case 114:
#line 4035 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr152;
		case 44: goto tr180;
		case 62: goto tr181;
		case 92: goto tr153;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr151;
	goto tr147;
tr180:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st115;
st115:
	if ( ++p == pe )
		goto _test_eof115;
case 115:
#line 4055 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr152;
		case 47: goto tr151;
		case 92: goto tr153;
		case 95: goto tr183;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr151;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr184;
		} else
			goto tr183;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr184;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr151;
			} else if ( (*p) >= 97 )
				goto tr184;
		} else
			goto tr151;
	} else
		goto tr151;
	goto tr182;
tr185:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st116;
tr183:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st116;
st116:
	if ( ++p == pe )
		goto _test_eof116;
case 116:
#line 4106 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr152;
		case 47: goto tr151;
		case 92: goto tr153;
		case 95: goto tr185;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr151;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr186;
		} else
			goto tr185;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr186;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr151;
			} else if ( (*p) >= 97 )
				goto tr186;
		} else
			goto tr151;
	} else
		goto tr151;
	goto tr182;
tr186:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st117;
tr184:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st117;
st117:
	if ( ++p == pe )
		goto _test_eof117;
case 117:
#line 4157 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr152;
		case 47: goto tr151;
		case 61: goto tr187;
		case 92: goto tr153;
		case 95: goto tr186;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr151;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr151;
		} else
			goto tr186;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr151;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr151;
		} else
			goto tr186;
	} else
		goto tr186;
	goto tr182;
tr187:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st118;
st118:
	if ( ++p == pe )
		goto _test_eof118;
case 118:
#line 4200 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr176;
		case 92: goto tr153;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr151;
	goto tr147;
tr181:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st119;
st119:
	if ( ++p == pe )
		goto _test_eof119;
case 119:
#line 4218 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 10: goto tr52;
		case 34: goto tr152;
		case 92: goto tr153;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr151;
	goto tr147;
tr131:
#line 139 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st120;
st120:
	if ( ++p == pe )
		goto _test_eof120;
case 120:
#line 4241 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 58: goto st120;
		case 95: goto st120;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr133;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr133;
	} else
		goto tr133;
	goto tr129;
tr31:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st121;
st121:
	if ( ++p == pe )
		goto _test_eof121;
case 121:
#line 4269 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 73: goto tr190;
		case 79: goto tr191;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr189;
tr190:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st122;
st122:
	if ( ++p == pe )
		goto _test_eof122;
case 122:
#line 4288 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 76: goto tr193;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr192;
tr193:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st123;
st123:
	if ( ++p == pe )
		goto _test_eof123;
case 123:
#line 4306 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 84: goto tr194;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr192;
tr194:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st124;
st124:
	if ( ++p == pe )
		goto _test_eof124;
case 124:
#line 4324 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 69: goto tr195;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr192;
tr195:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st125;
st125:
	if ( ++p == pe )
		goto _test_eof125;
case 125:
#line 4342 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 82: goto st126;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr192;
st126:
	if ( ++p == pe )
		goto _test_eof126;
case 126:
	if ( (*p) == 61 )
		goto tr197;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr192;
tr197:
#line 115 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "FILTER");
    }
	goto st127;
st127:
	if ( ++p == pe )
		goto _test_eof127;
case 127:
#line 4369 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 60 )
		goto st128;
	goto tr192;
st128:
	if ( ++p == pe )
		goto _test_eof128;
case 128:
	if ( (*p) == 73 )
		goto st129;
	goto tr192;
st129:
	if ( ++p == pe )
		goto _test_eof129;
case 129:
	if ( (*p) == 68 )
		goto st130;
	goto tr192;
st130:
	if ( ++p == pe )
		goto _test_eof130;
case 130:
	if ( (*p) == 61 )
		goto st131;
	goto tr192;
st131:
	if ( ++p == pe )
		goto _test_eof131;
case 131:
	if ( (*p) == 95 )
		goto tr203;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr203;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr204;
		} else if ( (*p) >= 65 )
			goto tr204;
	} else
		goto tr204;
	goto tr202;
tr203:
#line 139 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st132;
st132:
	if ( ++p == pe )
		goto _test_eof132;
case 132:
#line 4426 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 95 )
		goto st132;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st132;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr206;
		} else if ( (*p) >= 65 )
			goto tr206;
	} else
		goto tr206;
	goto tr202;
tr206:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st133;
tr204:
#line 139 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st133;
st133:
	if ( ++p == pe )
		goto _test_eof133;
case 133:
#line 4465 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 44: goto tr207;
		case 95: goto tr206;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr206;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr206;
		} else if ( (*p) >= 65 )
			goto tr206;
	} else
		goto tr206;
	goto tr202;
tr207:
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st134;
st134:
	if ( ++p == pe )
		goto _test_eof134;
case 134:
#line 4492 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 68 )
		goto st135;
	goto tr192;
st135:
	if ( ++p == pe )
		goto _test_eof135;
case 135:
	if ( (*p) == 101 )
		goto st136;
	goto tr192;
st136:
	if ( ++p == pe )
		goto _test_eof136;
case 136:
	if ( (*p) == 115 )
		goto st137;
	goto tr192;
st137:
	if ( ++p == pe )
		goto _test_eof137;
case 137:
	if ( (*p) == 99 )
		goto st138;
	goto tr192;
st138:
	if ( ++p == pe )
		goto _test_eof138;
case 138:
	if ( (*p) == 114 )
		goto st139;
	goto tr192;
st139:
	if ( ++p == pe )
		goto _test_eof139;
case 139:
	if ( (*p) == 105 )
		goto st140;
	goto tr192;
st140:
	if ( ++p == pe )
		goto _test_eof140;
case 140:
	if ( (*p) == 112 )
		goto st141;
	goto tr192;
st141:
	if ( ++p == pe )
		goto _test_eof141;
case 141:
	if ( (*p) == 116 )
		goto st142;
	goto tr192;
st142:
	if ( ++p == pe )
		goto _test_eof142;
case 142:
	if ( (*p) == 105 )
		goto st143;
	goto tr192;
st143:
	if ( ++p == pe )
		goto _test_eof143;
case 143:
	if ( (*p) == 111 )
		goto st144;
	goto tr192;
st144:
	if ( ++p == pe )
		goto _test_eof144;
case 144:
	if ( (*p) == 110 )
		goto st145;
	goto tr192;
st145:
	if ( ++p == pe )
		goto _test_eof145;
case 145:
	if ( (*p) == 61 )
		goto st146;
	goto tr192;
st146:
	if ( ++p == pe )
		goto _test_eof146;
case 146:
	if ( (*p) == 34 )
		goto tr220;
	goto tr192;
tr220:
#line 151 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Description");
    }
	goto st147;
st147:
	if ( ++p == pe )
		goto _test_eof147;
case 147:
#line 4590 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr223;
		case 92: goto tr224;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr222;
	goto tr221;
tr222:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st148;
tr225:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st148;
st148:
	if ( ++p == pe )
		goto _test_eof148;
case 148:
#line 4618 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr226;
		case 92: goto tr227;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr225;
	goto tr221;
tr223:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st149;
tr226:
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st149;
st149:
	if ( ++p == pe )
		goto _test_eof149;
case 149:
#line 4646 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 44: goto st150;
		case 62: goto st164;
	}
	goto tr221;
st150:
	if ( ++p == pe )
		goto _test_eof150;
case 150:
	if ( (*p) == 95 )
		goto tr230;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr230;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr231;
		} else if ( (*p) >= 65 )
			goto tr231;
	} else
		goto tr231;
	goto tr202;
tr230:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st151;
st151:
	if ( ++p == pe )
		goto _test_eof151;
case 151:
#line 4680 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 95 )
		goto st151;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st151;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr233;
		} else if ( (*p) >= 65 )
			goto tr233;
	} else
		goto tr233;
	goto tr202;
tr231:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st152;
tr233:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st152;
st152:
	if ( ++p == pe )
		goto _test_eof152;
case 152:
#line 4715 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr234;
		case 95: goto tr233;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr233;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr233;
		} else if ( (*p) >= 65 )
			goto tr233;
	} else
		goto tr233;
	goto tr202;
tr234:
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st153;
st153:
	if ( ++p == pe )
		goto _test_eof153;
case 153:
#line 4742 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 34 )
		goto st154;
	goto tr192;
st154:
	if ( ++p == pe )
		goto _test_eof154;
case 154:
	switch( (*p) ) {
		case 34: goto tr223;
		case 92: goto tr237;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr236;
	goto tr221;
tr236:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st155;
tr238:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st155;
st155:
	if ( ++p == pe )
		goto _test_eof155;
case 155:
#line 4777 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr226;
		case 92: goto tr239;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr238;
	goto tr221;
tr237:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st156;
tr239:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st156;
st156:
	if ( ++p == pe )
		goto _test_eof156;
case 156:
#line 4805 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr240;
		case 92: goto tr239;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr238;
	goto tr221;
tr240:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st157;
st157:
	if ( ++p == pe )
		goto _test_eof157;
case 157:
#line 4827 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr226;
		case 44: goto tr241;
		case 62: goto tr242;
		case 92: goto tr239;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr238;
	goto tr221;
tr250:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st158;
tr241:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st158;
st158:
	if ( ++p == pe )
		goto _test_eof158;
case 158:
#line 4857 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr226;
		case 47: goto tr238;
		case 92: goto tr239;
		case 95: goto tr244;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr238;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr245;
		} else
			goto tr244;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr245;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr238;
			} else if ( (*p) >= 97 )
				goto tr245;
		} else
			goto tr238;
	} else
		goto tr238;
	goto tr243;
tr244:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st159;
tr246:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st159;
st159:
	if ( ++p == pe )
		goto _test_eof159;
case 159:
#line 4908 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr226;
		case 47: goto tr238;
		case 92: goto tr239;
		case 95: goto tr246;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr238;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr247;
		} else
			goto tr246;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr247;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr238;
			} else if ( (*p) >= 97 )
				goto tr247;
		} else
			goto tr238;
	} else
		goto tr238;
	goto tr243;
tr245:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st160;
tr247:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st160;
st160:
	if ( ++p == pe )
		goto _test_eof160;
case 160:
#line 4959 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr226;
		case 47: goto tr238;
		case 61: goto tr248;
		case 92: goto tr239;
		case 95: goto tr247;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr238;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr238;
		} else
			goto tr247;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr238;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr238;
		} else
			goto tr247;
	} else
		goto tr247;
	goto tr243;
tr248:
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st161;
st161:
	if ( ++p == pe )
		goto _test_eof161;
case 161:
#line 5002 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr249;
		case 92: goto tr239;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr238;
	goto tr221;
tr249:
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st162;
st162:
	if ( ++p == pe )
		goto _test_eof162;
case 162:
#line 5020 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr223;
		case 44: goto tr250;
		case 62: goto tr251;
		case 92: goto tr237;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr236;
	goto tr221;
tr251:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st163;
tr242:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st163;
st163:
	if ( ++p == pe )
		goto _test_eof163;
case 163:
#line 5050 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 10: goto tr52;
		case 34: goto tr226;
		case 92: goto tr239;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr238;
	goto tr221;
st164:
	if ( ++p == pe )
		goto _test_eof164;
case 164:
	if ( (*p) == 10 )
		goto tr52;
	goto tr192;
tr224:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st165;
tr227:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st165;
st165:
	if ( ++p == pe )
		goto _test_eof165;
case 165:
#line 5086 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr252;
		case 92: goto tr227;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr225;
	goto tr221;
tr252:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st166;
st166:
	if ( ++p == pe )
		goto _test_eof166;
case 166:
#line 5108 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr226;
		case 44: goto tr253;
		case 62: goto tr254;
		case 92: goto tr227;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr225;
	goto tr221;
tr253:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st167;
st167:
	if ( ++p == pe )
		goto _test_eof167;
case 167:
#line 5128 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr226;
		case 47: goto tr225;
		case 92: goto tr227;
		case 95: goto tr256;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr225;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr257;
		} else
			goto tr256;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr257;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr225;
			} else if ( (*p) >= 97 )
				goto tr257;
		} else
			goto tr225;
	} else
		goto tr225;
	goto tr255;
tr258:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st168;
tr256:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st168;
st168:
	if ( ++p == pe )
		goto _test_eof168;
case 168:
#line 5179 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr226;
		case 47: goto tr225;
		case 92: goto tr227;
		case 95: goto tr258;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr225;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr259;
		} else
			goto tr258;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr259;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr225;
			} else if ( (*p) >= 97 )
				goto tr259;
		} else
			goto tr225;
	} else
		goto tr225;
	goto tr255;
tr259:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st169;
tr257:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st169;
st169:
	if ( ++p == pe )
		goto _test_eof169;
case 169:
#line 5230 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr226;
		case 47: goto tr225;
		case 61: goto tr260;
		case 92: goto tr227;
		case 95: goto tr259;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr225;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr225;
		} else
			goto tr259;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr225;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr225;
		} else
			goto tr259;
	} else
		goto tr259;
	goto tr255;
tr260:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st170;
st170:
	if ( ++p == pe )
		goto _test_eof170;
case 170:
#line 5273 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr249;
		case 92: goto tr227;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr225;
	goto tr221;
tr254:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st171;
st171:
	if ( ++p == pe )
		goto _test_eof171;
case 171:
#line 5291 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 10: goto tr52;
		case 34: goto tr226;
		case 92: goto tr227;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr225;
	goto tr221;
tr191:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st172;
st172:
	if ( ++p == pe )
		goto _test_eof172;
case 172:
#line 5310 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 82: goto tr262;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr261;
tr262:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st173;
st173:
	if ( ++p == pe )
		goto _test_eof173;
case 173:
#line 5328 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 77: goto tr263;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr261;
tr263:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st174;
st174:
	if ( ++p == pe )
		goto _test_eof174;
case 174:
#line 5346 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 65: goto tr264;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr261;
tr264:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st175;
st175:
	if ( ++p == pe )
		goto _test_eof175;
case 175:
#line 5364 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 84: goto st176;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr261;
st176:
	if ( ++p == pe )
		goto _test_eof176;
case 176:
	if ( (*p) == 61 )
		goto tr266;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr261;
tr266:
#line 119 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "FORMAT");
    }
	goto st177;
st177:
	if ( ++p == pe )
		goto _test_eof177;
case 177:
#line 5391 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 60 )
		goto st178;
	goto tr261;
st178:
	if ( ++p == pe )
		goto _test_eof178;
case 178:
	if ( (*p) == 73 )
		goto st179;
	goto tr261;
st179:
	if ( ++p == pe )
		goto _test_eof179;
case 179:
	if ( (*p) == 68 )
		goto st180;
	goto tr261;
st180:
	if ( ++p == pe )
		goto _test_eof180;
case 180:
	if ( (*p) == 61 )
		goto st181;
	goto tr261;
st181:
	if ( ++p == pe )
		goto _test_eof181;
case 181:
	if ( (*p) == 95 )
		goto tr272;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr272;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr273;
		} else if ( (*p) >= 65 )
			goto tr273;
	} else
		goto tr273;
	goto tr271;
tr272:
#line 139 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st182;
st182:
	if ( ++p == pe )
		goto _test_eof182;
case 182:
#line 5448 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 95 )
		goto st182;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st182;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr275;
		} else if ( (*p) >= 65 )
			goto tr275;
	} else
		goto tr275;
	goto tr271;
tr275:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st183;
tr273:
#line 139 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st183;
st183:
	if ( ++p == pe )
		goto _test_eof183;
case 183:
#line 5487 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 44: goto tr276;
		case 95: goto tr275;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr275;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr275;
		} else if ( (*p) >= 65 )
			goto tr275;
	} else
		goto tr275;
	goto tr271;
tr276:
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st184;
st184:
	if ( ++p == pe )
		goto _test_eof184;
case 184:
#line 5514 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 78 )
		goto st185;
	goto tr261;
st185:
	if ( ++p == pe )
		goto _test_eof185;
case 185:
	if ( (*p) == 117 )
		goto st186;
	goto tr261;
st186:
	if ( ++p == pe )
		goto _test_eof186;
case 186:
	if ( (*p) == 109 )
		goto st187;
	goto tr261;
st187:
	if ( ++p == pe )
		goto _test_eof187;
case 187:
	if ( (*p) == 98 )
		goto st188;
	goto tr261;
st188:
	if ( ++p == pe )
		goto _test_eof188;
case 188:
	if ( (*p) == 101 )
		goto st189;
	goto tr261;
st189:
	if ( ++p == pe )
		goto _test_eof189;
case 189:
	if ( (*p) == 114 )
		goto st190;
	goto tr261;
st190:
	if ( ++p == pe )
		goto _test_eof190;
case 190:
	if ( (*p) == 61 )
		goto st191;
	goto tr261;
st191:
	if ( ++p == pe )
		goto _test_eof191;
case 191:
	switch( (*p) ) {
		case 46: goto tr285;
		case 65: goto tr285;
		case 71: goto tr285;
		case 82: goto tr285;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr286;
	goto tr284;
tr285:
#line 143 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Number");
    }
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st192;
st192:
	if ( ++p == pe )
		goto _test_eof192;
case 192:
#line 5591 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 44 )
		goto tr287;
	goto tr284;
tr287:
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st193;
st193:
	if ( ++p == pe )
		goto _test_eof193;
case 193:
#line 5605 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 84 )
		goto st194;
	goto tr261;
st194:
	if ( ++p == pe )
		goto _test_eof194;
case 194:
	if ( (*p) == 121 )
		goto st195;
	goto tr261;
st195:
	if ( ++p == pe )
		goto _test_eof195;
case 195:
	if ( (*p) == 112 )
		goto st196;
	goto tr261;
st196:
	if ( ++p == pe )
		goto _test_eof196;
case 196:
	if ( (*p) == 101 )
		goto st197;
	goto tr261;
st197:
	if ( ++p == pe )
		goto _test_eof197;
case 197:
	if ( (*p) == 61 )
		goto st198;
	goto tr261;
st198:
	if ( ++p == pe )
		goto _test_eof198;
case 198:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr294;
	} else if ( (*p) >= 65 )
		goto tr294;
	goto tr293;
tr296:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st199;
tr294:
#line 147 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Type");
    }
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st199;
st199:
	if ( ++p == pe )
		goto _test_eof199;
case 199:
#line 5671 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 44 )
		goto tr295;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr296;
	} else if ( (*p) >= 65 )
		goto tr296;
	goto tr293;
tr295:
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st200;
st200:
	if ( ++p == pe )
		goto _test_eof200;
case 200:
#line 5690 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 68 )
		goto st201;
	goto tr261;
st201:
	if ( ++p == pe )
		goto _test_eof201;
case 201:
	if ( (*p) == 101 )
		goto st202;
	goto tr261;
st202:
	if ( ++p == pe )
		goto _test_eof202;
case 202:
	if ( (*p) == 115 )
		goto st203;
	goto tr261;
st203:
	if ( ++p == pe )
		goto _test_eof203;
case 203:
	if ( (*p) == 99 )
		goto st204;
	goto tr261;
st204:
	if ( ++p == pe )
		goto _test_eof204;
case 204:
	if ( (*p) == 114 )
		goto st205;
	goto tr261;
st205:
	if ( ++p == pe )
		goto _test_eof205;
case 205:
	if ( (*p) == 105 )
		goto st206;
	goto tr261;
st206:
	if ( ++p == pe )
		goto _test_eof206;
case 206:
	if ( (*p) == 112 )
		goto st207;
	goto tr261;
st207:
	if ( ++p == pe )
		goto _test_eof207;
case 207:
	if ( (*p) == 116 )
		goto st208;
	goto tr261;
st208:
	if ( ++p == pe )
		goto _test_eof208;
case 208:
	if ( (*p) == 105 )
		goto st209;
	goto tr261;
st209:
	if ( ++p == pe )
		goto _test_eof209;
case 209:
	if ( (*p) == 111 )
		goto st210;
	goto tr261;
st210:
	if ( ++p == pe )
		goto _test_eof210;
case 210:
	if ( (*p) == 110 )
		goto st211;
	goto tr261;
st211:
	if ( ++p == pe )
		goto _test_eof211;
case 211:
	if ( (*p) == 61 )
		goto st212;
	goto tr261;
st212:
	if ( ++p == pe )
		goto _test_eof212;
case 212:
	if ( (*p) == 34 )
		goto tr309;
	goto tr261;
tr309:
#line 151 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Description");
    }
	goto st213;
st213:
	if ( ++p == pe )
		goto _test_eof213;
case 213:
#line 5788 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr312;
		case 92: goto tr313;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr311;
	goto tr310;
tr311:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st214;
tr314:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st214;
st214:
	if ( ++p == pe )
		goto _test_eof214;
case 214:
#line 5816 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr315;
		case 92: goto tr316;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr314;
	goto tr310;
tr312:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st215;
tr315:
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st215;
st215:
	if ( ++p == pe )
		goto _test_eof215;
case 215:
#line 5844 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 44: goto st216;
		case 62: goto st230;
	}
	goto tr310;
st216:
	if ( ++p == pe )
		goto _test_eof216;
case 216:
	if ( (*p) == 95 )
		goto tr319;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr319;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr320;
		} else if ( (*p) >= 65 )
			goto tr320;
	} else
		goto tr320;
	goto tr271;
tr319:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st217;
st217:
	if ( ++p == pe )
		goto _test_eof217;
case 217:
#line 5878 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 95 )
		goto st217;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st217;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr322;
		} else if ( (*p) >= 65 )
			goto tr322;
	} else
		goto tr322;
	goto tr271;
tr320:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st218;
tr322:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st218;
st218:
	if ( ++p == pe )
		goto _test_eof218;
case 218:
#line 5913 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr323;
		case 95: goto tr322;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr322;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr322;
		} else if ( (*p) >= 65 )
			goto tr322;
	} else
		goto tr322;
	goto tr271;
tr323:
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st219;
st219:
	if ( ++p == pe )
		goto _test_eof219;
case 219:
#line 5940 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 34 )
		goto st220;
	goto tr261;
st220:
	if ( ++p == pe )
		goto _test_eof220;
case 220:
	switch( (*p) ) {
		case 34: goto tr312;
		case 92: goto tr326;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr325;
	goto tr310;
tr325:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st221;
tr327:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st221;
st221:
	if ( ++p == pe )
		goto _test_eof221;
case 221:
#line 5975 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr315;
		case 92: goto tr328;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr327;
	goto tr310;
tr326:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st222;
tr328:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st222;
st222:
	if ( ++p == pe )
		goto _test_eof222;
case 222:
#line 6003 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr329;
		case 92: goto tr328;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr327;
	goto tr310;
tr329:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st223;
st223:
	if ( ++p == pe )
		goto _test_eof223;
case 223:
#line 6025 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr315;
		case 44: goto tr330;
		case 62: goto tr331;
		case 92: goto tr328;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr327;
	goto tr310;
tr339:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st224;
tr330:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st224;
st224:
	if ( ++p == pe )
		goto _test_eof224;
case 224:
#line 6055 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr315;
		case 47: goto tr327;
		case 92: goto tr328;
		case 95: goto tr333;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr327;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr334;
		} else
			goto tr333;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr334;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr327;
			} else if ( (*p) >= 97 )
				goto tr334;
		} else
			goto tr327;
	} else
		goto tr327;
	goto tr332;
tr333:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st225;
tr335:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st225;
st225:
	if ( ++p == pe )
		goto _test_eof225;
case 225:
#line 6106 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr315;
		case 47: goto tr327;
		case 92: goto tr328;
		case 95: goto tr335;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr327;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr336;
		} else
			goto tr335;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr336;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr327;
			} else if ( (*p) >= 97 )
				goto tr336;
		} else
			goto tr327;
	} else
		goto tr327;
	goto tr332;
tr334:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st226;
tr336:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st226;
st226:
	if ( ++p == pe )
		goto _test_eof226;
case 226:
#line 6157 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr315;
		case 47: goto tr327;
		case 61: goto tr337;
		case 92: goto tr328;
		case 95: goto tr336;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr327;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr327;
		} else
			goto tr336;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr327;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr327;
		} else
			goto tr336;
	} else
		goto tr336;
	goto tr332;
tr337:
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st227;
st227:
	if ( ++p == pe )
		goto _test_eof227;
case 227:
#line 6200 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr338;
		case 92: goto tr328;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr327;
	goto tr310;
tr338:
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st228;
st228:
	if ( ++p == pe )
		goto _test_eof228;
case 228:
#line 6218 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr312;
		case 44: goto tr339;
		case 62: goto tr340;
		case 92: goto tr326;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr325;
	goto tr310;
tr340:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st229;
tr331:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st229;
st229:
	if ( ++p == pe )
		goto _test_eof229;
case 229:
#line 6248 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 10: goto tr52;
		case 34: goto tr315;
		case 92: goto tr328;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr327;
	goto tr310;
st230:
	if ( ++p == pe )
		goto _test_eof230;
case 230:
	if ( (*p) == 10 )
		goto tr52;
	goto tr261;
tr313:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st231;
tr316:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st231;
st231:
	if ( ++p == pe )
		goto _test_eof231;
case 231:
#line 6284 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr341;
		case 92: goto tr316;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr314;
	goto tr310;
tr341:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st232;
st232:
	if ( ++p == pe )
		goto _test_eof232;
case 232:
#line 6306 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr315;
		case 44: goto tr342;
		case 62: goto tr343;
		case 92: goto tr316;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr314;
	goto tr310;
tr342:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st233;
st233:
	if ( ++p == pe )
		goto _test_eof233;
case 233:
#line 6326 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr315;
		case 47: goto tr314;
		case 92: goto tr316;
		case 95: goto tr345;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr314;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr346;
		} else
			goto tr345;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr346;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr314;
			} else if ( (*p) >= 97 )
				goto tr346;
		} else
			goto tr314;
	} else
		goto tr314;
	goto tr344;
tr347:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st234;
tr345:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st234;
st234:
	if ( ++p == pe )
		goto _test_eof234;
case 234:
#line 6377 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr315;
		case 47: goto tr314;
		case 92: goto tr316;
		case 95: goto tr347;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr314;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr348;
		} else
			goto tr347;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr348;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr314;
			} else if ( (*p) >= 97 )
				goto tr348;
		} else
			goto tr314;
	} else
		goto tr314;
	goto tr344;
tr348:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st235;
tr346:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st235;
st235:
	if ( ++p == pe )
		goto _test_eof235;
case 235:
#line 6428 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr315;
		case 47: goto tr314;
		case 61: goto tr349;
		case 92: goto tr316;
		case 95: goto tr348;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr314;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr314;
		} else
			goto tr348;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr314;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr314;
		} else
			goto tr348;
	} else
		goto tr348;
	goto tr344;
tr349:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st236;
st236:
	if ( ++p == pe )
		goto _test_eof236;
case 236:
#line 6471 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr338;
		case 92: goto tr316;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr314;
	goto tr310;
tr343:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st237;
st237:
	if ( ++p == pe )
		goto _test_eof237;
case 237:
#line 6489 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 10: goto tr52;
		case 34: goto tr315;
		case 92: goto tr316;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr314;
	goto tr310;
tr350:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st238;
tr286:
#line 143 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Number");
    }
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st238;
st238:
	if ( ++p == pe )
		goto _test_eof238;
case 238:
#line 6522 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 44 )
		goto tr287;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr350;
	goto tr284;
tr32:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st239;
st239:
	if ( ++p == pe )
		goto _test_eof239;
case 239:
#line 6542 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 78: goto tr352;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr351;
tr352:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st240;
st240:
	if ( ++p == pe )
		goto _test_eof240;
case 240:
#line 6560 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 70: goto tr353;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr351;
tr353:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st241;
st241:
	if ( ++p == pe )
		goto _test_eof241;
case 241:
#line 6578 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 79: goto st242;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr351;
st242:
	if ( ++p == pe )
		goto _test_eof242;
case 242:
	if ( (*p) == 61 )
		goto tr355;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr351;
tr355:
#line 123 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "INFO");
    }
	goto st243;
st243:
	if ( ++p == pe )
		goto _test_eof243;
case 243:
#line 6605 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 60 )
		goto st244;
	goto tr351;
st244:
	if ( ++p == pe )
		goto _test_eof244;
case 244:
	if ( (*p) == 73 )
		goto st245;
	goto tr351;
st245:
	if ( ++p == pe )
		goto _test_eof245;
case 245:
	if ( (*p) == 68 )
		goto st246;
	goto tr351;
st246:
	if ( ++p == pe )
		goto _test_eof246;
case 246:
	if ( (*p) == 61 )
		goto st247;
	goto tr351;
st247:
	if ( ++p == pe )
		goto _test_eof247;
case 247:
	if ( (*p) == 95 )
		goto tr361;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr361;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr362;
		} else if ( (*p) >= 65 )
			goto tr362;
	} else
		goto tr362;
	goto tr360;
tr361:
#line 139 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st248;
st248:
	if ( ++p == pe )
		goto _test_eof248;
case 248:
#line 6662 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 95 )
		goto st248;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st248;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr364;
		} else if ( (*p) >= 65 )
			goto tr364;
	} else
		goto tr364;
	goto tr360;
tr364:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st249;
tr362:
#line 139 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st249;
st249:
	if ( ++p == pe )
		goto _test_eof249;
case 249:
#line 6701 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 44: goto tr365;
		case 95: goto tr364;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr364;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr364;
		} else if ( (*p) >= 65 )
			goto tr364;
	} else
		goto tr364;
	goto tr360;
tr365:
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st250;
st250:
	if ( ++p == pe )
		goto _test_eof250;
case 250:
#line 6728 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 78 )
		goto st251;
	goto tr351;
st251:
	if ( ++p == pe )
		goto _test_eof251;
case 251:
	if ( (*p) == 117 )
		goto st252;
	goto tr351;
st252:
	if ( ++p == pe )
		goto _test_eof252;
case 252:
	if ( (*p) == 109 )
		goto st253;
	goto tr351;
st253:
	if ( ++p == pe )
		goto _test_eof253;
case 253:
	if ( (*p) == 98 )
		goto st254;
	goto tr351;
st254:
	if ( ++p == pe )
		goto _test_eof254;
case 254:
	if ( (*p) == 101 )
		goto st255;
	goto tr351;
st255:
	if ( ++p == pe )
		goto _test_eof255;
case 255:
	if ( (*p) == 114 )
		goto st256;
	goto tr351;
st256:
	if ( ++p == pe )
		goto _test_eof256;
case 256:
	if ( (*p) == 61 )
		goto st257;
	goto tr351;
st257:
	if ( ++p == pe )
		goto _test_eof257;
case 257:
	switch( (*p) ) {
		case 46: goto tr374;
		case 65: goto tr374;
		case 71: goto tr374;
		case 82: goto tr374;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr375;
	goto tr373;
tr374:
#line 143 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Number");
    }
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st258;
st258:
	if ( ++p == pe )
		goto _test_eof258;
case 258:
#line 6805 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 44 )
		goto tr376;
	goto tr373;
tr376:
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st259;
st259:
	if ( ++p == pe )
		goto _test_eof259;
case 259:
#line 6819 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 84 )
		goto st260;
	goto tr351;
st260:
	if ( ++p == pe )
		goto _test_eof260;
case 260:
	if ( (*p) == 121 )
		goto st261;
	goto tr351;
st261:
	if ( ++p == pe )
		goto _test_eof261;
case 261:
	if ( (*p) == 112 )
		goto st262;
	goto tr351;
st262:
	if ( ++p == pe )
		goto _test_eof262;
case 262:
	if ( (*p) == 101 )
		goto st263;
	goto tr351;
st263:
	if ( ++p == pe )
		goto _test_eof263;
case 263:
	if ( (*p) == 61 )
		goto st264;
	goto tr351;
st264:
	if ( ++p == pe )
		goto _test_eof264;
case 264:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr383;
	} else if ( (*p) >= 65 )
		goto tr383;
	goto tr382;
tr385:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st265;
tr383:
#line 147 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Type");
    }
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st265;
st265:
	if ( ++p == pe )
		goto _test_eof265;
case 265:
#line 6885 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 44 )
		goto tr384;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr385;
	} else if ( (*p) >= 65 )
		goto tr385;
	goto tr382;
tr384:
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st266;
st266:
	if ( ++p == pe )
		goto _test_eof266;
case 266:
#line 6904 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 68 )
		goto st267;
	goto tr351;
st267:
	if ( ++p == pe )
		goto _test_eof267;
case 267:
	if ( (*p) == 101 )
		goto st268;
	goto tr351;
st268:
	if ( ++p == pe )
		goto _test_eof268;
case 268:
	if ( (*p) == 115 )
		goto st269;
	goto tr351;
st269:
	if ( ++p == pe )
		goto _test_eof269;
case 269:
	if ( (*p) == 99 )
		goto st270;
	goto tr351;
st270:
	if ( ++p == pe )
		goto _test_eof270;
case 270:
	if ( (*p) == 114 )
		goto st271;
	goto tr351;
st271:
	if ( ++p == pe )
		goto _test_eof271;
case 271:
	if ( (*p) == 105 )
		goto st272;
	goto tr351;
st272:
	if ( ++p == pe )
		goto _test_eof272;
case 272:
	if ( (*p) == 112 )
		goto st273;
	goto tr351;
st273:
	if ( ++p == pe )
		goto _test_eof273;
case 273:
	if ( (*p) == 116 )
		goto st274;
	goto tr351;
st274:
	if ( ++p == pe )
		goto _test_eof274;
case 274:
	if ( (*p) == 105 )
		goto st275;
	goto tr351;
st275:
	if ( ++p == pe )
		goto _test_eof275;
case 275:
	if ( (*p) == 111 )
		goto st276;
	goto tr351;
st276:
	if ( ++p == pe )
		goto _test_eof276;
case 276:
	if ( (*p) == 110 )
		goto st277;
	goto tr351;
st277:
	if ( ++p == pe )
		goto _test_eof277;
case 277:
	if ( (*p) == 61 )
		goto st278;
	goto tr351;
st278:
	if ( ++p == pe )
		goto _test_eof278;
case 278:
	if ( (*p) == 34 )
		goto tr398;
	goto tr351;
tr398:
#line 151 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Description");
    }
	goto st279;
st279:
	if ( ++p == pe )
		goto _test_eof279;
case 279:
#line 7002 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr401;
		case 92: goto tr402;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr400;
	goto tr399;
tr400:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st280;
tr403:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st280;
st280:
	if ( ++p == pe )
		goto _test_eof280;
case 280:
#line 7030 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr404;
		case 92: goto tr405;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr403;
	goto tr399;
tr401:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st281;
tr404:
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st281;
st281:
	if ( ++p == pe )
		goto _test_eof281;
case 281:
#line 7058 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 44: goto st282;
		case 62: goto st296;
	}
	goto tr399;
st282:
	if ( ++p == pe )
		goto _test_eof282;
case 282:
	if ( (*p) == 95 )
		goto tr408;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr408;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr409;
		} else if ( (*p) >= 65 )
			goto tr409;
	} else
		goto tr409;
	goto tr360;
tr408:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st283;
st283:
	if ( ++p == pe )
		goto _test_eof283;
case 283:
#line 7092 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 95 )
		goto st283;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st283;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr411;
		} else if ( (*p) >= 65 )
			goto tr411;
	} else
		goto tr411;
	goto tr360;
tr409:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st284;
tr411:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st284;
st284:
	if ( ++p == pe )
		goto _test_eof284;
case 284:
#line 7127 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr412;
		case 95: goto tr411;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr411;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr411;
		} else if ( (*p) >= 65 )
			goto tr411;
	} else
		goto tr411;
	goto tr360;
tr412:
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st285;
st285:
	if ( ++p == pe )
		goto _test_eof285;
case 285:
#line 7154 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 34 )
		goto st286;
	goto tr351;
st286:
	if ( ++p == pe )
		goto _test_eof286;
case 286:
	switch( (*p) ) {
		case 34: goto tr401;
		case 92: goto tr415;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr414;
	goto tr399;
tr414:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st287;
tr416:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st287;
st287:
	if ( ++p == pe )
		goto _test_eof287;
case 287:
#line 7189 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr404;
		case 92: goto tr417;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr416;
	goto tr399;
tr415:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st288;
tr417:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st288;
st288:
	if ( ++p == pe )
		goto _test_eof288;
case 288:
#line 7217 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr418;
		case 92: goto tr417;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr416;
	goto tr399;
tr418:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st289;
st289:
	if ( ++p == pe )
		goto _test_eof289;
case 289:
#line 7239 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr404;
		case 44: goto tr419;
		case 62: goto tr420;
		case 92: goto tr417;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr416;
	goto tr399;
tr428:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st290;
tr419:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st290;
st290:
	if ( ++p == pe )
		goto _test_eof290;
case 290:
#line 7269 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr404;
		case 47: goto tr416;
		case 92: goto tr417;
		case 95: goto tr422;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr416;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr423;
		} else
			goto tr422;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr423;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr416;
			} else if ( (*p) >= 97 )
				goto tr423;
		} else
			goto tr416;
	} else
		goto tr416;
	goto tr421;
tr422:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st291;
tr424:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st291;
st291:
	if ( ++p == pe )
		goto _test_eof291;
case 291:
#line 7320 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr404;
		case 47: goto tr416;
		case 92: goto tr417;
		case 95: goto tr424;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr416;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr425;
		} else
			goto tr424;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr425;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr416;
			} else if ( (*p) >= 97 )
				goto tr425;
		} else
			goto tr416;
	} else
		goto tr416;
	goto tr421;
tr423:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st292;
tr425:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st292;
st292:
	if ( ++p == pe )
		goto _test_eof292;
case 292:
#line 7371 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr404;
		case 47: goto tr416;
		case 61: goto tr426;
		case 92: goto tr417;
		case 95: goto tr425;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr416;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr416;
		} else
			goto tr425;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr416;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr416;
		} else
			goto tr425;
	} else
		goto tr425;
	goto tr421;
tr426:
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st293;
st293:
	if ( ++p == pe )
		goto _test_eof293;
case 293:
#line 7414 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr427;
		case 92: goto tr417;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr416;
	goto tr399;
tr427:
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st294;
st294:
	if ( ++p == pe )
		goto _test_eof294;
case 294:
#line 7432 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr401;
		case 44: goto tr428;
		case 62: goto tr429;
		case 92: goto tr415;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr414;
	goto tr399;
tr429:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st295;
tr420:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st295;
st295:
	if ( ++p == pe )
		goto _test_eof295;
case 295:
#line 7462 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 10: goto tr52;
		case 34: goto tr404;
		case 92: goto tr417;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr416;
	goto tr399;
st296:
	if ( ++p == pe )
		goto _test_eof296;
case 296:
	if ( (*p) == 10 )
		goto tr52;
	goto tr351;
tr402:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st297;
tr405:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st297;
st297:
	if ( ++p == pe )
		goto _test_eof297;
case 297:
#line 7498 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr430;
		case 92: goto tr405;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr403;
	goto tr399;
tr430:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st298;
st298:
	if ( ++p == pe )
		goto _test_eof298;
case 298:
#line 7520 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr404;
		case 44: goto tr431;
		case 62: goto tr432;
		case 92: goto tr405;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr403;
	goto tr399;
tr431:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st299;
st299:
	if ( ++p == pe )
		goto _test_eof299;
case 299:
#line 7540 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr404;
		case 47: goto tr403;
		case 92: goto tr405;
		case 95: goto tr434;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr403;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr435;
		} else
			goto tr434;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr435;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr403;
			} else if ( (*p) >= 97 )
				goto tr435;
		} else
			goto tr403;
	} else
		goto tr403;
	goto tr433;
tr436:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st300;
tr434:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st300;
st300:
	if ( ++p == pe )
		goto _test_eof300;
case 300:
#line 7591 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr404;
		case 47: goto tr403;
		case 92: goto tr405;
		case 95: goto tr436;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr403;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr437;
		} else
			goto tr436;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr437;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr403;
			} else if ( (*p) >= 97 )
				goto tr437;
		} else
			goto tr403;
	} else
		goto tr403;
	goto tr433;
tr437:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st301;
tr435:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st301;
st301:
	if ( ++p == pe )
		goto _test_eof301;
case 301:
#line 7642 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr404;
		case 47: goto tr403;
		case 61: goto tr438;
		case 92: goto tr405;
		case 95: goto tr437;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr403;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr403;
		} else
			goto tr437;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr403;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr403;
		} else
			goto tr437;
	} else
		goto tr437;
	goto tr433;
tr438:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st302;
st302:
	if ( ++p == pe )
		goto _test_eof302;
case 302:
#line 7685 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr427;
		case 92: goto tr405;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr403;
	goto tr399;
tr432:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st303;
st303:
	if ( ++p == pe )
		goto _test_eof303;
case 303:
#line 7703 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 10: goto tr52;
		case 34: goto tr404;
		case 92: goto tr405;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr403;
	goto tr399;
tr439:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st304;
tr375:
#line 143 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Number");
    }
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st304;
st304:
	if ( ++p == pe )
		goto _test_eof304;
case 304:
#line 7736 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 44 )
		goto tr376;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr439;
	goto tr373;
tr33:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st305;
st305:
	if ( ++p == pe )
		goto _test_eof305;
case 305:
#line 7756 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 69: goto tr441;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr440;
tr441:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st306;
st306:
	if ( ++p == pe )
		goto _test_eof306;
case 306:
#line 7774 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 68: goto tr442;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr440;
tr442:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st307;
st307:
	if ( ++p == pe )
		goto _test_eof307;
case 307:
#line 7792 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 73: goto tr443;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr440;
tr443:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st308;
st308:
	if ( ++p == pe )
		goto _test_eof308;
case 308:
#line 7810 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 71: goto tr444;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr440;
tr444:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st309;
st309:
	if ( ++p == pe )
		goto _test_eof309;
case 309:
#line 7828 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 82: goto tr445;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr440;
tr445:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st310;
st310:
	if ( ++p == pe )
		goto _test_eof310;
case 310:
#line 7846 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 69: goto tr446;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr440;
tr446:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st311;
st311:
	if ( ++p == pe )
		goto _test_eof311;
case 311:
#line 7864 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 69: goto st312;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr440;
st312:
	if ( ++p == pe )
		goto _test_eof312;
case 312:
	if ( (*p) == 61 )
		goto tr448;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr440;
tr448:
#line 127 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "PEDIGREE");
    }
	goto st313;
st313:
	if ( ++p == pe )
		goto _test_eof313;
case 313:
#line 7891 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 60 )
		goto st314;
	goto tr440;
tr460:
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st314;
st314:
	if ( ++p == pe )
		goto _test_eof314;
case 314:
#line 7905 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 95 )
		goto tr451;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr451;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr452;
		} else if ( (*p) >= 65 )
			goto tr452;
	} else
		goto tr452;
	goto tr450;
tr451:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st315;
st315:
	if ( ++p == pe )
		goto _test_eof315;
case 315:
#line 7930 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 95 )
		goto st315;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st315;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr454;
		} else if ( (*p) >= 65 )
			goto tr454;
	} else
		goto tr454;
	goto tr450;
tr452:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st316;
tr454:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st316;
st316:
	if ( ++p == pe )
		goto _test_eof316;
case 316:
#line 7965 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr455;
		case 95: goto tr454;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr454;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr454;
		} else if ( (*p) >= 65 )
			goto tr454;
	} else
		goto tr454;
	goto tr450;
tr455:
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st317;
st317:
	if ( ++p == pe )
		goto _test_eof317;
case 317:
#line 7992 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 95 )
		goto tr456;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr456;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr457;
		} else if ( (*p) >= 65 )
			goto tr457;
	} else
		goto tr457;
	goto tr450;
tr456:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st318;
st318:
	if ( ++p == pe )
		goto _test_eof318;
case 318:
#line 8017 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 95 )
		goto st318;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st318;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr459;
		} else if ( (*p) >= 65 )
			goto tr459;
	} else
		goto tr459;
	goto tr450;
tr457:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st319;
tr459:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st319;
st319:
	if ( ++p == pe )
		goto _test_eof319;
case 319:
#line 8052 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 44: goto tr460;
		case 62: goto tr461;
		case 95: goto tr459;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr459;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr459;
		} else if ( (*p) >= 65 )
			goto tr459;
	} else
		goto tr459;
	goto tr450;
tr461:
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st320;
st320:
	if ( ++p == pe )
		goto _test_eof320;
case 320:
#line 8080 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 10 )
		goto tr52;
	goto tr440;
tr34:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st321;
st321:
	if ( ++p == pe )
		goto _test_eof321;
case 321:
#line 8098 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 65: goto tr463;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr462;
tr463:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st322;
st322:
	if ( ++p == pe )
		goto _test_eof322;
case 322:
#line 8116 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 77: goto tr464;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr462;
tr464:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st323;
st323:
	if ( ++p == pe )
		goto _test_eof323;
case 323:
#line 8134 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 80: goto tr465;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr462;
tr465:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st324;
st324:
	if ( ++p == pe )
		goto _test_eof324;
case 324:
#line 8152 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 76: goto tr466;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr462;
tr466:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st325;
st325:
	if ( ++p == pe )
		goto _test_eof325;
case 325:
#line 8170 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 69: goto st326;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr462;
st326:
	if ( ++p == pe )
		goto _test_eof326;
case 326:
	if ( (*p) == 61 )
		goto tr468;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr462;
tr468:
#line 135 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "SAMPLE");
    }
	goto st327;
st327:
	if ( ++p == pe )
		goto _test_eof327;
case 327:
#line 8197 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 60 )
		goto st328;
	goto tr462;
st328:
	if ( ++p == pe )
		goto _test_eof328;
case 328:
	if ( (*p) == 73 )
		goto st329;
	goto tr462;
st329:
	if ( ++p == pe )
		goto _test_eof329;
case 329:
	if ( (*p) == 68 )
		goto st330;
	goto tr462;
st330:
	if ( ++p == pe )
		goto _test_eof330;
case 330:
	if ( (*p) == 61 )
		goto st331;
	goto tr462;
st331:
	if ( ++p == pe )
		goto _test_eof331;
case 331:
	if ( (*p) == 95 )
		goto tr474;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr474;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr475;
		} else if ( (*p) >= 65 )
			goto tr475;
	} else
		goto tr475;
	goto tr473;
tr474:
#line 139 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st332;
st332:
	if ( ++p == pe )
		goto _test_eof332;
case 332:
#line 8254 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 95 )
		goto st332;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st332;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr477;
		} else if ( (*p) >= 65 )
			goto tr477;
	} else
		goto tr477;
	goto tr473;
tr477:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st333;
tr475:
#line 139 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st333;
st333:
	if ( ++p == pe )
		goto _test_eof333;
case 333:
#line 8293 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 44: goto tr479;
		case 95: goto tr477;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr477;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr477;
		} else if ( (*p) >= 65 )
			goto tr477;
	} else
		goto tr477;
	goto tr478;
tr479:
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st334;
st334:
	if ( ++p == pe )
		goto _test_eof334;
case 334:
#line 8320 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 71 )
		goto st335;
	goto tr480;
st335:
	if ( ++p == pe )
		goto _test_eof335;
case 335:
	if ( (*p) == 101 )
		goto st336;
	goto tr480;
st336:
	if ( ++p == pe )
		goto _test_eof336;
case 336:
	if ( (*p) == 110 )
		goto st337;
	goto tr480;
st337:
	if ( ++p == pe )
		goto _test_eof337;
case 337:
	if ( (*p) == 111 )
		goto st338;
	goto tr480;
st338:
	if ( ++p == pe )
		goto _test_eof338;
case 338:
	if ( (*p) == 109 )
		goto st339;
	goto tr480;
st339:
	if ( ++p == pe )
		goto _test_eof339;
case 339:
	if ( (*p) == 101 )
		goto st340;
	goto tr480;
st340:
	if ( ++p == pe )
		goto _test_eof340;
case 340:
	if ( (*p) == 115 )
		goto st341;
	goto tr480;
st341:
	if ( ++p == pe )
		goto _test_eof341;
case 341:
	if ( (*p) == 61 )
		goto st342;
	goto tr480;
st342:
	if ( ++p == pe )
		goto _test_eof342;
case 342:
	if ( (*p) < 35 ) {
		if ( 32 <= (*p) && (*p) <= 33 )
			goto tr489;
	} else if ( (*p) > 43 ) {
		if ( (*p) > 61 ) {
			if ( 63 <= (*p) && (*p) <= 126 )
				goto tr489;
		} else if ( (*p) >= 45 )
			goto tr489;
	} else
		goto tr489;
	goto tr480;
tr491:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st343;
tr489:
#line 155 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Genomes");
    }
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st343;
st343:
	if ( ++p == pe )
		goto _test_eof343;
case 343:
#line 8413 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 44 )
		goto tr492;
	if ( (*p) < 35 ) {
		if ( 32 <= (*p) && (*p) <= 33 )
			goto tr491;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr491;
	} else
		goto tr491;
	goto tr490;
tr492:
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st344;
st344:
	if ( ++p == pe )
		goto _test_eof344;
case 344:
#line 8435 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 77 )
		goto st345;
	goto tr493;
st345:
	if ( ++p == pe )
		goto _test_eof345;
case 345:
	if ( (*p) == 105 )
		goto st346;
	goto tr493;
st346:
	if ( ++p == pe )
		goto _test_eof346;
case 346:
	if ( (*p) == 120 )
		goto st347;
	goto tr493;
st347:
	if ( ++p == pe )
		goto _test_eof347;
case 347:
	if ( (*p) == 116 )
		goto st348;
	goto tr493;
st348:
	if ( ++p == pe )
		goto _test_eof348;
case 348:
	if ( (*p) == 117 )
		goto st349;
	goto tr493;
st349:
	if ( ++p == pe )
		goto _test_eof349;
case 349:
	if ( (*p) == 114 )
		goto st350;
	goto tr493;
st350:
	if ( ++p == pe )
		goto _test_eof350;
case 350:
	if ( (*p) == 101 )
		goto st351;
	goto tr493;
st351:
	if ( ++p == pe )
		goto _test_eof351;
case 351:
	if ( (*p) == 61 )
		goto st352;
	goto tr493;
st352:
	if ( ++p == pe )
		goto _test_eof352;
case 352:
	if ( (*p) < 35 ) {
		if ( 32 <= (*p) && (*p) <= 33 )
			goto tr502;
	} else if ( (*p) > 43 ) {
		if ( (*p) > 61 ) {
			if ( 63 <= (*p) && (*p) <= 126 )
				goto tr502;
		} else if ( (*p) >= 45 )
			goto tr502;
	} else
		goto tr502;
	goto tr493;
tr504:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st353;
tr502:
#line 159 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Mixture");
    }
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st353;
st353:
	if ( ++p == pe )
		goto _test_eof353;
case 353:
#line 8528 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 44 )
		goto tr505;
	if ( (*p) < 35 ) {
		if ( 32 <= (*p) && (*p) <= 33 )
			goto tr504;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr504;
	} else
		goto tr504;
	goto tr503;
tr505:
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st354;
st354:
	if ( ++p == pe )
		goto _test_eof354;
case 354:
#line 8550 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 68 )
		goto st355;
	goto tr506;
st355:
	if ( ++p == pe )
		goto _test_eof355;
case 355:
	if ( (*p) == 101 )
		goto st356;
	goto tr506;
st356:
	if ( ++p == pe )
		goto _test_eof356;
case 356:
	if ( (*p) == 115 )
		goto st357;
	goto tr506;
st357:
	if ( ++p == pe )
		goto _test_eof357;
case 357:
	if ( (*p) == 99 )
		goto st358;
	goto tr506;
st358:
	if ( ++p == pe )
		goto _test_eof358;
case 358:
	if ( (*p) == 114 )
		goto st359;
	goto tr506;
st359:
	if ( ++p == pe )
		goto _test_eof359;
case 359:
	if ( (*p) == 105 )
		goto st360;
	goto tr506;
st360:
	if ( ++p == pe )
		goto _test_eof360;
case 360:
	if ( (*p) == 112 )
		goto st361;
	goto tr506;
st361:
	if ( ++p == pe )
		goto _test_eof361;
case 361:
	if ( (*p) == 116 )
		goto st362;
	goto tr506;
st362:
	if ( ++p == pe )
		goto _test_eof362;
case 362:
	if ( (*p) == 105 )
		goto st363;
	goto tr506;
st363:
	if ( ++p == pe )
		goto _test_eof363;
case 363:
	if ( (*p) == 111 )
		goto st364;
	goto tr506;
st364:
	if ( ++p == pe )
		goto _test_eof364;
case 364:
	if ( (*p) == 110 )
		goto st365;
	goto tr506;
st365:
	if ( ++p == pe )
		goto _test_eof365;
case 365:
	if ( (*p) == 61 )
		goto st366;
	goto tr506;
st366:
	if ( ++p == pe )
		goto _test_eof366;
case 366:
	if ( (*p) == 34 )
		goto tr519;
	goto tr506;
tr519:
#line 151 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Description");
    }
	goto st367;
st367:
	if ( ++p == pe )
		goto _test_eof367;
case 367:
#line 8648 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr521;
		case 92: goto tr522;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr520;
	goto tr506;
tr520:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st368;
tr523:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st368;
st368:
	if ( ++p == pe )
		goto _test_eof368;
case 368:
#line 8676 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr524;
		case 92: goto tr525;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr523;
	goto tr506;
tr521:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st369;
tr524:
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st369;
st369:
	if ( ++p == pe )
		goto _test_eof369;
case 369:
#line 8704 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 62 )
		goto st370;
	goto tr506;
st370:
	if ( ++p == pe )
		goto _test_eof370;
case 370:
	if ( (*p) == 10 )
		goto tr52;
	goto tr462;
tr522:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st371;
tr525:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st371;
st371:
	if ( ++p == pe )
		goto _test_eof371;
case 371:
#line 8735 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr527;
		case 92: goto tr525;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr523;
	goto tr506;
tr527:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st372;
st372:
	if ( ++p == pe )
		goto _test_eof372;
case 372:
#line 8757 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr524;
		case 62: goto tr528;
		case 92: goto tr525;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr523;
	goto tr506;
tr528:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st373;
st373:
	if ( ++p == pe )
		goto _test_eof373;
case 373:
#line 8776 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 10: goto tr52;
		case 34: goto tr524;
		case 92: goto tr525;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr523;
	goto tr506;
tr35:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st374;
st374:
	if ( ++p == pe )
		goto _test_eof374;
case 374:
#line 8799 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 115: goto tr530;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr529;
tr530:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st375;
st375:
	if ( ++p == pe )
		goto _test_eof375;
case 375:
#line 8817 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 115: goto tr531;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr529;
tr531:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st376;
st376:
	if ( ++p == pe )
		goto _test_eof376;
case 376:
#line 8835 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 101: goto tr532;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr529;
tr532:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st377;
st377:
	if ( ++p == pe )
		goto _test_eof377;
case 377:
#line 8853 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 109: goto tr533;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr529;
tr533:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st378;
st378:
	if ( ++p == pe )
		goto _test_eof378;
case 378:
#line 8871 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 98: goto tr534;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr529;
tr534:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st379;
st379:
	if ( ++p == pe )
		goto _test_eof379;
case 379:
#line 8889 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 108: goto tr535;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr529;
tr535:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st380;
st380:
	if ( ++p == pe )
		goto _test_eof380;
case 380:
#line 8907 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 121: goto st381;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr529;
st381:
	if ( ++p == pe )
		goto _test_eof381;
case 381:
	if ( (*p) == 61 )
		goto tr537;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr529;
tr537:
#line 107 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "assembly");
    }
	goto st382;
st382:
	if ( ++p == pe )
		goto _test_eof382;
case 382:
#line 8934 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr539;
	} else if ( (*p) >= 65 )
		goto tr539;
	goto tr538;
tr539:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st383;
st383:
	if ( ++p == pe )
		goto _test_eof383;
case 383:
#line 8951 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 10: goto tr538;
		case 35: goto tr538;
		case 47: goto tr538;
		case 58: goto tr538;
		case 63: goto tr538;
	}
	goto st384;
st384:
	if ( ++p == pe )
		goto _test_eof384;
case 384:
	switch( (*p) ) {
		case 10: goto tr538;
		case 35: goto tr538;
		case 47: goto tr538;
		case 58: goto st385;
		case 63: goto tr538;
	}
	goto st384;
st385:
	if ( ++p == pe )
		goto _test_eof385;
case 385:
	if ( (*p) == 47 )
		goto st386;
	goto tr538;
st386:
	if ( ++p == pe )
		goto _test_eof386;
case 386:
	if ( (*p) == 47 )
		goto st387;
	goto tr538;
st387:
	if ( ++p == pe )
		goto _test_eof387;
case 387:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr544;
	} else if ( (*p) >= 65 )
		goto tr544;
	goto tr538;
tr544:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st388;
st388:
	if ( ++p == pe )
		goto _test_eof388;
case 388:
#line 9006 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 10 )
		goto tr44;
	goto tr544;
tr36:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st389;
st389:
	if ( ++p == pe )
		goto _test_eof389;
case 389:
#line 9024 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 111: goto tr546;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr545;
tr546:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st390;
st390:
	if ( ++p == pe )
		goto _test_eof390;
case 390:
#line 9042 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 110: goto tr547;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr545;
tr547:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st391;
st391:
	if ( ++p == pe )
		goto _test_eof391;
case 391:
#line 9060 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 116: goto tr548;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr545;
tr548:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st392;
st392:
	if ( ++p == pe )
		goto _test_eof392;
case 392:
#line 9078 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 105: goto tr549;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr545;
tr549:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st393;
st393:
	if ( ++p == pe )
		goto _test_eof393;
case 393:
#line 9096 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 103: goto st394;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr545;
st394:
	if ( ++p == pe )
		goto _test_eof394;
case 394:
	if ( (*p) == 61 )
		goto tr551;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr545;
tr551:
#line 111 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "contig");
    }
	goto st395;
st395:
	if ( ++p == pe )
		goto _test_eof395;
case 395:
#line 9123 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 60 )
		goto st396;
	goto tr545;
st396:
	if ( ++p == pe )
		goto _test_eof396;
case 396:
	if ( (*p) == 73 )
		goto st397;
	goto tr545;
st397:
	if ( ++p == pe )
		goto _test_eof397;
case 397:
	if ( (*p) == 68 )
		goto st398;
	goto tr545;
st398:
	if ( ++p == pe )
		goto _test_eof398;
case 398:
	if ( (*p) == 61 )
		goto st399;
	goto tr545;
st399:
	if ( ++p == pe )
		goto _test_eof399;
case 399:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr557;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr557;
	} else
		goto tr557;
	goto tr556;
tr557:
#line 139 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st400;
st400:
	if ( ++p == pe )
		goto _test_eof400;
case 400:
#line 9179 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 44: goto tr559;
		case 59: goto tr558;
		case 62: goto tr561;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr558;
		} else if ( (*p) > 57 ) {
			if ( 61 <= (*p) && (*p) <= 64 )
				goto tr558;
		} else
			goto tr560;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr558;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr558;
		} else
			goto tr560;
	} else
		goto tr560;
	goto tr556;
tr558:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st401;
st401:
	if ( ++p == pe )
		goto _test_eof401;
case 401:
#line 9216 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 59: goto tr558;
		case 61: goto tr558;
	}
	if ( (*p) < 63 ) {
		if ( (*p) < 45 ) {
			if ( 33 <= (*p) && (*p) <= 43 )
				goto tr558;
		} else if ( (*p) > 47 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr560;
		} else
			goto tr558;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr560;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr558;
			} else if ( (*p) >= 97 )
				goto tr560;
		} else
			goto tr558;
	} else
		goto tr558;
	goto tr556;
tr560:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st402;
st402:
	if ( ++p == pe )
		goto _test_eof402;
case 402:
#line 9255 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 44: goto tr559;
		case 59: goto tr560;
		case 62: goto tr561;
	}
	if ( (*p) > 57 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr560;
	} else if ( (*p) >= 33 )
		goto tr560;
	goto tr556;
tr559:
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st403;
st403:
	if ( ++p == pe )
		goto _test_eof403;
case 403:
#line 9277 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 95 )
		goto tr562;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr562;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr563;
		} else if ( (*p) >= 65 )
			goto tr563;
	} else
		goto tr563;
	goto tr545;
tr562:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st404;
st404:
	if ( ++p == pe )
		goto _test_eof404;
case 404:
#line 9302 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 95 )
		goto st404;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st404;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr565;
		} else if ( (*p) >= 65 )
			goto tr565;
	} else
		goto tr565;
	goto tr545;
tr563:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st405;
tr565:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st405;
st405:
	if ( ++p == pe )
		goto _test_eof405;
case 405:
#line 9337 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr566;
		case 95: goto tr565;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr565;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr565;
		} else if ( (*p) >= 65 )
			goto tr565;
	} else
		goto tr565;
	goto tr545;
tr566:
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st406;
st406:
	if ( ++p == pe )
		goto _test_eof406;
case 406:
#line 9364 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 34 )
		goto st409;
	if ( (*p) < 45 ) {
		if ( 32 <= (*p) && (*p) <= 43 )
			goto tr567;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr567;
	} else
		goto tr567;
	goto tr545;
tr567:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st407;
tr569:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st407;
st407:
	if ( ++p == pe )
		goto _test_eof407;
case 407:
#line 9396 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 44: goto tr559;
		case 62: goto tr561;
	}
	if ( (*p) > 33 ) {
		if ( 35 <= (*p) && (*p) <= 126 )
			goto tr569;
	} else if ( (*p) >= 32 )
		goto tr569;
	goto tr545;
tr561:
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st408;
st408:
	if ( ++p == pe )
		goto _test_eof408;
case 408:
#line 9417 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 10 )
		goto tr52;
	goto tr545;
st409:
	if ( ++p == pe )
		goto _test_eof409;
case 409:
	switch( (*p) ) {
		case 34: goto tr571;
		case 92: goto tr572;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr570;
	goto tr545;
tr570:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st410;
tr573:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st410;
st410:
	if ( ++p == pe )
		goto _test_eof410;
case 410:
#line 9452 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr574;
		case 92: goto tr575;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr573;
	goto tr545;
tr571:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st411;
tr574:
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st411;
st411:
	if ( ++p == pe )
		goto _test_eof411;
case 411:
#line 9480 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 44: goto st403;
		case 62: goto st408;
	}
	goto tr545;
tr572:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st412;
tr575:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st412;
st412:
	if ( ++p == pe )
		goto _test_eof412;
case 412:
#line 9506 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr578;
		case 92: goto tr575;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr573;
	goto tr545;
tr578:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st413;
st413:
	if ( ++p == pe )
		goto _test_eof413;
case 413:
#line 9528 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr574;
		case 44: goto tr579;
		case 62: goto tr580;
		case 92: goto tr575;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr573;
	goto tr545;
tr593:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st414;
tr579:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st414;
tr590:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st414;
st414:
	if ( ++p == pe )
		goto _test_eof414;
case 414:
#line 9568 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr574;
		case 47: goto tr573;
		case 92: goto tr575;
		case 95: goto tr581;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr573;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr582;
		} else
			goto tr581;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr582;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr573;
			} else if ( (*p) >= 97 )
				goto tr582;
		} else
			goto tr573;
	} else
		goto tr573;
	goto tr545;
tr581:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st415;
tr583:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st415;
st415:
	if ( ++p == pe )
		goto _test_eof415;
case 415:
#line 9619 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr574;
		case 47: goto tr573;
		case 92: goto tr575;
		case 95: goto tr583;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr573;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr584;
		} else
			goto tr583;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr584;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr573;
			} else if ( (*p) >= 97 )
				goto tr584;
		} else
			goto tr573;
	} else
		goto tr573;
	goto tr545;
tr582:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st416;
tr584:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st416;
st416:
	if ( ++p == pe )
		goto _test_eof416;
case 416:
#line 9670 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr574;
		case 47: goto tr573;
		case 61: goto tr585;
		case 92: goto tr575;
		case 95: goto tr584;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr573;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr573;
		} else
			goto tr584;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr573;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr573;
		} else
			goto tr584;
	} else
		goto tr584;
	goto tr545;
tr585:
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st417;
st417:
	if ( ++p == pe )
		goto _test_eof417;
case 417:
#line 9713 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr587;
		case 44: goto tr573;
		case 62: goto tr573;
		case 92: goto tr588;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr586;
	goto tr545;
tr589:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st418;
tr586:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st418;
st418:
	if ( ++p == pe )
		goto _test_eof418;
case 418:
#line 9743 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr574;
		case 44: goto tr590;
		case 62: goto tr591;
		case 92: goto tr592;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr589;
	goto tr545;
tr594:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st419;
tr580:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st419;
tr591:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st419;
st419:
	if ( ++p == pe )
		goto _test_eof419;
case 419:
#line 9783 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 10: goto tr52;
		case 34: goto tr574;
		case 92: goto tr575;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr573;
	goto tr545;
tr592:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st420;
tr588:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st420;
st420:
	if ( ++p == pe )
		goto _test_eof420;
case 420:
#line 9812 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr578;
		case 44: goto tr590;
		case 62: goto tr591;
		case 92: goto tr592;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr589;
	goto tr545;
tr587:
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st421;
st421:
	if ( ++p == pe )
		goto _test_eof421;
case 421:
#line 9832 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr571;
		case 44: goto tr593;
		case 62: goto tr594;
		case 92: goto tr572;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr570;
	goto tr545;
tr37:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st422;
st422:
	if ( ++p == pe )
		goto _test_eof422;
case 422:
#line 9856 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 101: goto tr596;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr595;
tr596:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st423;
st423:
	if ( ++p == pe )
		goto _test_eof423;
case 423:
#line 9874 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 100: goto tr597;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr595;
tr597:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st424;
st424:
	if ( ++p == pe )
		goto _test_eof424;
case 424:
#line 9892 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 105: goto tr598;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr595;
tr598:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st425;
st425:
	if ( ++p == pe )
		goto _test_eof425;
case 425:
#line 9910 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 103: goto tr599;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr595;
tr599:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st426;
st426:
	if ( ++p == pe )
		goto _test_eof426;
case 426:
#line 9928 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 114: goto tr600;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr595;
tr600:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st427;
st427:
	if ( ++p == pe )
		goto _test_eof427;
case 427:
#line 9946 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 101: goto tr601;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr595;
tr601:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st428;
st428:
	if ( ++p == pe )
		goto _test_eof428;
case 428:
#line 9964 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 101: goto tr602;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr595;
tr602:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st429;
st429:
	if ( ++p == pe )
		goto _test_eof429;
case 429:
#line 9982 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 68: goto tr603;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr595;
tr603:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st430;
st430:
	if ( ++p == pe )
		goto _test_eof430;
case 430:
#line 10000 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 66: goto st431;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr595;
st431:
	if ( ++p == pe )
		goto _test_eof431;
case 431:
	if ( (*p) == 61 )
		goto tr605;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr595;
tr605:
#line 131 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "pedigreeDB");
    }
	goto st432;
st432:
	if ( ++p == pe )
		goto _test_eof432;
case 432:
#line 10027 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 60 )
		goto st433;
	goto tr595;
st433:
	if ( ++p == pe )
		goto _test_eof433;
case 433:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr608;
	} else if ( (*p) >= 65 )
		goto tr608;
	goto tr607;
tr608:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st434;
st434:
	if ( ++p == pe )
		goto _test_eof434;
case 434:
#line 10051 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 10: goto tr607;
		case 35: goto tr607;
		case 47: goto tr607;
		case 58: goto tr607;
		case 63: goto tr607;
	}
	goto st435;
st435:
	if ( ++p == pe )
		goto _test_eof435;
case 435:
	switch( (*p) ) {
		case 10: goto tr607;
		case 35: goto tr607;
		case 47: goto tr607;
		case 58: goto st436;
		case 63: goto tr607;
	}
	goto st435;
st436:
	if ( ++p == pe )
		goto _test_eof436;
case 436:
	if ( (*p) == 47 )
		goto st437;
	goto tr607;
st437:
	if ( ++p == pe )
		goto _test_eof437;
case 437:
	if ( (*p) == 47 )
		goto st438;
	goto tr607;
st438:
	if ( ++p == pe )
		goto _test_eof438;
case 438:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr613;
	} else if ( (*p) >= 65 )
		goto tr613;
	goto tr607;
tr613:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st439;
st439:
	if ( ++p == pe )
		goto _test_eof439;
case 439:
#line 10106 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 10: goto tr607;
		case 62: goto tr614;
	}
	goto tr613;
tr614:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st440;
st440:
	if ( ++p == pe )
		goto _test_eof440;
case 440:
#line 10126 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 10: goto tr52;
		case 62: goto tr614;
	}
	goto tr613;
st441:
	if ( ++p == pe )
		goto _test_eof441;
case 441:
	if ( (*p) == 72 )
		goto st442;
	goto tr615;
st442:
	if ( ++p == pe )
		goto _test_eof442;
case 442:
	if ( (*p) == 82 )
		goto st443;
	goto tr615;
st443:
	if ( ++p == pe )
		goto _test_eof443;
case 443:
	if ( (*p) == 79 )
		goto st444;
	goto tr615;
st444:
	if ( ++p == pe )
		goto _test_eof444;
case 444:
	if ( (*p) == 77 )
		goto st445;
	goto tr615;
st445:
	if ( ++p == pe )
		goto _test_eof445;
case 445:
	if ( (*p) == 9 )
		goto st446;
	goto tr615;
st446:
	if ( ++p == pe )
		goto _test_eof446;
case 446:
	if ( (*p) == 80 )
		goto st447;
	goto tr615;
st447:
	if ( ++p == pe )
		goto _test_eof447;
case 447:
	if ( (*p) == 79 )
		goto st448;
	goto tr615;
st448:
	if ( ++p == pe )
		goto _test_eof448;
case 448:
	if ( (*p) == 83 )
		goto st449;
	goto tr615;
st449:
	if ( ++p == pe )
		goto _test_eof449;
case 449:
	if ( (*p) == 9 )
		goto st450;
	goto tr615;
st450:
	if ( ++p == pe )
		goto _test_eof450;
case 450:
	if ( (*p) == 73 )
		goto st451;
	goto tr615;
st451:
	if ( ++p == pe )
		goto _test_eof451;
case 451:
	if ( (*p) == 68 )
		goto st452;
	goto tr615;
st452:
	if ( ++p == pe )
		goto _test_eof452;
case 452:
	if ( (*p) == 9 )
		goto st453;
	goto tr615;
st453:
	if ( ++p == pe )
		goto _test_eof453;
case 453:
	if ( (*p) == 82 )
		goto st454;
	goto tr615;
st454:
	if ( ++p == pe )
		goto _test_eof454;
case 454:
	if ( (*p) == 69 )
		goto st455;
	goto tr615;
st455:
	if ( ++p == pe )
		goto _test_eof455;
case 455:
	if ( (*p) == 70 )
		goto st456;
	goto tr615;
st456:
	if ( ++p == pe )
		goto _test_eof456;
case 456:
	if ( (*p) == 9 )
		goto st457;
	goto tr615;
st457:
	if ( ++p == pe )
		goto _test_eof457;
case 457:
	if ( (*p) == 65 )
		goto st458;
	goto tr615;
st458:
	if ( ++p == pe )
		goto _test_eof458;
case 458:
	if ( (*p) == 76 )
		goto st459;
	goto tr615;
st459:
	if ( ++p == pe )
		goto _test_eof459;
case 459:
	if ( (*p) == 84 )
		goto st460;
	goto tr615;
st460:
	if ( ++p == pe )
		goto _test_eof460;
case 460:
	if ( (*p) == 9 )
		goto st461;
	goto tr615;
st461:
	if ( ++p == pe )
		goto _test_eof461;
case 461:
	if ( (*p) == 81 )
		goto st462;
	goto tr615;
st462:
	if ( ++p == pe )
		goto _test_eof462;
case 462:
	if ( (*p) == 85 )
		goto st463;
	goto tr615;
st463:
	if ( ++p == pe )
		goto _test_eof463;
case 463:
	if ( (*p) == 65 )
		goto st464;
	goto tr615;
st464:
	if ( ++p == pe )
		goto _test_eof464;
case 464:
	if ( (*p) == 76 )
		goto st465;
	goto tr615;
st465:
	if ( ++p == pe )
		goto _test_eof465;
case 465:
	if ( (*p) == 9 )
		goto st466;
	goto tr615;
st466:
	if ( ++p == pe )
		goto _test_eof466;
case 466:
	if ( (*p) == 70 )
		goto st467;
	goto tr615;
st467:
	if ( ++p == pe )
		goto _test_eof467;
case 467:
	if ( (*p) == 73 )
		goto st468;
	goto tr615;
st468:
	if ( ++p == pe )
		goto _test_eof468;
case 468:
	if ( (*p) == 76 )
		goto st469;
	goto tr615;
st469:
	if ( ++p == pe )
		goto _test_eof469;
case 469:
	if ( (*p) == 84 )
		goto st470;
	goto tr615;
st470:
	if ( ++p == pe )
		goto _test_eof470;
case 470:
	if ( (*p) == 69 )
		goto st471;
	goto tr615;
st471:
	if ( ++p == pe )
		goto _test_eof471;
case 471:
	if ( (*p) == 82 )
		goto st472;
	goto tr615;
st472:
	if ( ++p == pe )
		goto _test_eof472;
case 472:
	if ( (*p) == 9 )
		goto st473;
	goto tr615;
st473:
	if ( ++p == pe )
		goto _test_eof473;
case 473:
	if ( (*p) == 73 )
		goto st474;
	goto tr615;
st474:
	if ( ++p == pe )
		goto _test_eof474;
case 474:
	if ( (*p) == 78 )
		goto st475;
	goto tr615;
st475:
	if ( ++p == pe )
		goto _test_eof475;
case 475:
	if ( (*p) == 70 )
		goto st476;
	goto tr615;
st476:
	if ( ++p == pe )
		goto _test_eof476;
case 476:
	if ( (*p) == 79 )
		goto st477;
	goto tr615;
st477:
	if ( ++p == pe )
		goto _test_eof477;
case 477:
	switch( (*p) ) {
		case 9: goto st478;
		case 10: goto tr653;
	}
	goto tr615;
st478:
	if ( ++p == pe )
		goto _test_eof478;
case 478:
	if ( (*p) == 70 )
		goto st479;
	goto tr654;
st479:
	if ( ++p == pe )
		goto _test_eof479;
case 479:
	if ( (*p) == 79 )
		goto st480;
	goto tr654;
st480:
	if ( ++p == pe )
		goto _test_eof480;
case 480:
	if ( (*p) == 82 )
		goto st481;
	goto tr654;
st481:
	if ( ++p == pe )
		goto _test_eof481;
case 481:
	if ( (*p) == 77 )
		goto st482;
	goto tr654;
st482:
	if ( ++p == pe )
		goto _test_eof482;
case 482:
	if ( (*p) == 65 )
		goto st483;
	goto tr654;
st483:
	if ( ++p == pe )
		goto _test_eof483;
case 483:
	if ( (*p) == 84 )
		goto st484;
	goto tr654;
st484:
	if ( ++p == pe )
		goto _test_eof484;
case 484:
	if ( (*p) == 9 )
		goto st485;
	goto tr654;
tr663:
#line 179 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_sample_name(*this);
    }
	goto st485;
st485:
	if ( ++p == pe )
		goto _test_eof485;
case 485:
#line 10452 "inc/vcf/validator_detail_v42.hpp"
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr662;
	goto tr654;
tr662:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st486;
tr665:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st486;
st486:
	if ( ++p == pe )
		goto _test_eof486;
case 486:
#line 10476 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr663;
		case 10: goto tr664;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr665;
	goto tr654;
tr653:
#line 183 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_header_line(*this);
    }
#line 43 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st730;
tr664:
#line 179 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_sample_name(*this);
    }
#line 183 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_header_line(*this);
    }
#line 43 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st730;
st730:
	if ( ++p == pe )
		goto _test_eof730;
case 730:
#line 10524 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 60 )
		goto tr967;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr966;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr966;
	} else
		goto tr966;
	goto tr965;
tr968:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st487;
tr966:
#line 70 "src/vcf/vcf_v42.ragel"
	{
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (MetaSectionError *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
    }
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st487;
st487:
	if ( ++p == pe )
		goto _test_eof487;
case 487:
#line 10568 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr667;
		case 59: goto tr668;
		case 61: goto tr668;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr668;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr668;
		} else
			goto tr669;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr668;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr668;
		} else
			goto tr669;
	} else
		goto tr669;
	goto tr666;
tr667:
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 189 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 53 "src/vcf/vcf_v42.ragel"
	{
        ++n_columns;
    }
	goto st488;
tr748:
#line 189 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 53 "src/vcf/vcf_v42.ragel"
	{
        ++n_columns;
    }
	goto st488;
st488:
	if ( ++p == pe )
		goto _test_eof488;
case 488:
#line 10623 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 43: goto tr671;
		case 45: goto tr671;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr672;
	goto tr670;
tr671:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st489;
st489:
	if ( ++p == pe )
		goto _test_eof489;
case 489:
#line 10641 "inc/vcf/validator_detail_v42.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr673;
	goto tr670;
tr672:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st490;
tr673:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st490;
st490:
	if ( ++p == pe )
		goto _test_eof490;
case 490:
#line 10665 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 9 )
		goto tr674;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr673;
	goto tr670;
tr679:
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st491;
tr674:
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 189 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 53 "src/vcf/vcf_v42.ragel"
	{
        ++n_columns;
    }
	goto st491;
st491:
	if ( ++p == pe )
		goto _test_eof491;
case 491:
#line 10695 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr676;
	} else if ( (*p) >= 33 )
		goto tr676;
	goto tr675;
tr676:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st492;
tr678:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st492;
st492:
	if ( ++p == pe )
		goto _test_eof492;
case 492:
#line 10722 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr677;
		case 59: goto tr679;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr678;
	goto tr675;
tr677:
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 189 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 53 "src/vcf/vcf_v42.ragel"
	{
        ++n_columns;
    }
	goto st493;
st493:
	if ( ++p == pe )
		goto _test_eof493;
case 493:
#line 10748 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 65: goto tr681;
		case 67: goto tr681;
		case 71: goto tr681;
		case 78: goto tr681;
		case 84: goto tr681;
		case 97: goto tr681;
		case 99: goto tr681;
		case 103: goto tr681;
		case 110: goto tr681;
		case 116: goto tr681;
	}
	goto tr680;
tr681:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st494;
tr683:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st494;
st494:
	if ( ++p == pe )
		goto _test_eof494;
case 494:
#line 10782 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr682;
		case 65: goto tr683;
		case 67: goto tr683;
		case 71: goto tr683;
		case 78: goto tr683;
		case 84: goto tr683;
		case 97: goto tr683;
		case 99: goto tr683;
		case 103: goto tr683;
		case 110: goto tr683;
		case 116: goto tr683;
	}
	goto tr680;
tr682:
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 189 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 53 "src/vcf/vcf_v42.ragel"
	{
        ++n_columns;
    }
	goto st495;
st495:
	if ( ++p == pe )
		goto _test_eof495;
case 495:
#line 10815 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 42: goto tr685;
		case 46: goto tr686;
		case 60: goto tr687;
		case 65: goto tr688;
		case 67: goto tr688;
		case 71: goto tr688;
		case 78: goto tr688;
		case 84: goto tr688;
		case 91: goto tr689;
		case 93: goto tr690;
		case 97: goto tr688;
		case 99: goto tr688;
		case 103: goto tr688;
		case 110: goto tr688;
		case 116: goto tr688;
	}
	goto tr684;
tr685:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st496;
tr912:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st496;
st496:
	if ( ++p == pe )
		goto _test_eof496;
case 496:
#line 10854 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr691;
		case 44: goto tr692;
	}
	goto tr684;
tr691:
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 189 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 53 "src/vcf/vcf_v42.ragel"
	{
        ++n_columns;
    }
	goto st497;
st497:
	if ( ++p == pe )
		goto _test_eof497;
case 497:
#line 10878 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 43: goto tr694;
		case 45: goto tr694;
		case 46: goto tr695;
		case 73: goto tr697;
		case 78: goto tr698;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr696;
	goto tr693;
tr694:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st498;
st498:
	if ( ++p == pe )
		goto _test_eof498;
case 498:
#line 10903 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 46: goto tr699;
		case 73: goto tr701;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr700;
	goto tr693;
tr699:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st499;
st499:
	if ( ++p == pe )
		goto _test_eof499;
case 499:
#line 10921 "inc/vcf/validator_detail_v42.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr702;
	goto tr693;
tr702:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st500;
st500:
	if ( ++p == pe )
		goto _test_eof500;
case 500:
#line 10935 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr703;
		case 69: goto tr704;
		case 101: goto tr704;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr702;
	goto tr693;
tr703:
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 189 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 53 "src/vcf/vcf_v42.ragel"
	{
        ++n_columns;
    }
	goto st501;
st501:
	if ( ++p == pe )
		goto _test_eof501;
case 501:
#line 10962 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 46: goto tr707;
		case 58: goto tr706;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr706;
		} else if ( (*p) > 57 ) {
			if ( 60 <= (*p) && (*p) <= 64 )
				goto tr706;
		} else
			goto tr708;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr706;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr706;
		} else
			goto tr708;
	} else
		goto tr708;
	goto tr705;
tr706:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st502;
st502:
	if ( ++p == pe )
		goto _test_eof502;
case 502:
#line 10998 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 58 )
		goto st502;
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto st502;
		} else if ( (*p) > 57 ) {
			if ( 60 <= (*p) && (*p) <= 64 )
				goto st502;
		} else
			goto tr710;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st502;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st502;
		} else
			goto tr710;
	} else
		goto tr710;
	goto tr705;
tr708:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st503;
tr710:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st503;
st503:
	if ( ++p == pe )
		goto _test_eof503;
case 503:
#line 11042 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr711;
		case 59: goto tr712;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr710;
	goto tr705;
tr711:
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 189 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 53 "src/vcf/vcf_v42.ragel"
	{
        ++n_columns;
    }
	goto st504;
st504:
	if ( ++p == pe )
		goto _test_eof504;
case 504:
#line 11068 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 46: goto tr715;
		case 49: goto tr717;
		case 58: goto tr714;
		case 60: goto tr714;
		case 65: goto tr718;
		case 66: goto tr719;
		case 67: goto tr720;
		case 68: goto tr721;
		case 69: goto tr722;
		case 72: goto tr723;
		case 77: goto tr724;
		case 78: goto tr725;
		case 83: goto tr726;
		case 86: goto tr727;
	}
	if ( (*p) < 70 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr714;
		} else if ( (*p) > 57 ) {
			if ( 62 <= (*p) && (*p) <= 64 )
				goto tr714;
		} else
			goto tr716;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr714;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr714;
		} else
			goto tr716;
	} else
		goto tr716;
	goto tr713;
tr714:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st505;
tr728:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st505;
st505:
	if ( ++p == pe )
		goto _test_eof505;
case 505:
#line 11126 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 58: goto tr728;
		case 60: goto tr728;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr728;
		} else if ( (*p) > 57 ) {
			if ( 62 <= (*p) && (*p) <= 64 )
				goto tr728;
		} else
			goto tr729;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr728;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr728;
		} else
			goto tr729;
	} else
		goto tr729;
	goto tr713;
tr716:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st506;
tr729:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st506;
st506:
	if ( ++p == pe )
		goto _test_eof506;
case 506:
#line 11172 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 10: goto tr731;
		case 59: goto tr732;
		case 61: goto tr733;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr729;
	goto tr713;
tr738:
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st507;
tr730:
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 189 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 53 "src/vcf/vcf_v42.ragel"
	{
        ++n_columns;
    }
	goto st507;
st507:
	if ( ++p == pe )
		goto _test_eof507;
case 507:
#line 11206 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 95 )
		goto tr735;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr735;
	} else if ( (*p) >= 65 )
		goto tr735;
	goto tr734;
tr735:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st508;
tr737:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st508;
st508:
	if ( ++p == pe )
		goto _test_eof508;
case 508:
#line 11235 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr736;
		case 46: goto tr737;
		case 58: goto tr738;
		case 95: goto tr737;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr737;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr737;
	} else
		goto tr737;
	goto tr734;
tr736:
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 189 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 53 "src/vcf/vcf_v42.ragel"
	{
        ++n_columns;
    }
	goto st509;
st509:
	if ( ++p == pe )
		goto _test_eof509;
case 509:
#line 11269 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 46 )
		goto tr740;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr741;
	goto tr739;
tr740:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st510;
tr749:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st510;
st510:
	if ( ++p == pe )
		goto _test_eof510;
case 510:
#line 11295 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr736;
		case 10: goto tr731;
		case 47: goto tr742;
		case 58: goto tr743;
		case 124: goto tr742;
	}
	goto tr739;
tr731:
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 189 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 193 "src/vcf/vcf_v42.ragel"
	{
        try {
          // Handle all columns and build record
          ParsePolicy::handle_body_line(*this);
            try {
          // Check warnings (non-blocking errors but potential mistakes anyway, only makes sense if the last record parsed was correct)
          OptionalPolicy::optional_check_body_entry(*this, ParsingState::records->back());
            } catch (MetaSectionError *warn) {
                ErrorPolicy::handle_warning(*this, warn);
            } catch (BodySectionError *warn) {
                ErrorPolicy::handle_warning(*this, warn);
            }
        } catch (BodySectionError *error) {
            ErrorPolicy::handle_error(*this, error);
        }
    }
#line 43 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st731;
st731:
	if ( ++p == pe )
		goto _test_eof731;
case 731:
#line 11345 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 60 )
		goto st511;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr968;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr968;
	} else
		goto tr968;
	goto tr666;
tr967:
#line 70 "src/vcf/vcf_v42.ragel"
	{
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (MetaSectionError *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
    }
	goto st511;
st511:
	if ( ++p == pe )
		goto _test_eof511;
case 511:
#line 11371 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr744;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr744;
	} else
		goto tr744;
	goto tr666;
tr744:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st512;
st512:
	if ( ++p == pe )
		goto _test_eof512;
case 512:
#line 11395 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 59: goto tr745;
		case 62: goto tr747;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr745;
		} else if ( (*p) > 57 ) {
			if ( 61 <= (*p) && (*p) <= 64 )
				goto tr745;
		} else
			goto tr746;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr745;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr745;
		} else
			goto tr746;
	} else
		goto tr746;
	goto tr666;
tr745:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st513;
st513:
	if ( ++p == pe )
		goto _test_eof513;
case 513:
#line 11431 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 59: goto tr745;
		case 61: goto tr745;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr745;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr745;
		} else
			goto tr746;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr745;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr745;
		} else
			goto tr746;
	} else
		goto tr746;
	goto tr666;
tr746:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st514;
st514:
	if ( ++p == pe )
		goto _test_eof514;
case 514:
#line 11467 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 59: goto tr746;
		case 62: goto tr747;
	}
	if ( (*p) > 57 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr746;
	} else if ( (*p) >= 33 )
		goto tr746;
	goto tr666;
tr747:
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st515;
st515:
	if ( ++p == pe )
		goto _test_eof515;
case 515:
#line 11488 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 9 )
		goto tr748;
	goto tr666;
tr742:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st516;
st516:
	if ( ++p == pe )
		goto _test_eof516;
case 516:
#line 11502 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 46 )
		goto tr749;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr750;
	goto tr739;
tr741:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st517;
tr750:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st517;
st517:
	if ( ++p == pe )
		goto _test_eof517;
case 517:
#line 11528 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr736;
		case 10: goto tr731;
		case 47: goto tr742;
		case 58: goto tr743;
		case 124: goto tr742;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr750;
	goto tr739;
tr743:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st518;
st518:
	if ( ++p == pe )
		goto _test_eof518;
case 518:
#line 11549 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) > 57 ) {
		if ( 59 <= (*p) && (*p) <= 126 )
			goto tr752;
	} else if ( (*p) >= 33 )
		goto tr752;
	goto tr751;
tr752:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st519;
st519:
	if ( ++p == pe )
		goto _test_eof519;
case 519:
#line 11566 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr736;
		case 10: goto tr731;
		case 58: goto tr743;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr752;
	goto tr751;
tr732:
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st520;
st520:
	if ( ++p == pe )
		goto _test_eof520;
case 520:
#line 11585 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 49: goto tr717;
		case 58: goto tr714;
		case 60: goto tr714;
		case 65: goto tr718;
		case 66: goto tr719;
		case 67: goto tr720;
		case 68: goto tr721;
		case 69: goto tr722;
		case 72: goto tr723;
		case 77: goto tr724;
		case 78: goto tr725;
		case 83: goto tr726;
		case 86: goto tr727;
	}
	if ( (*p) < 70 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr714;
		} else if ( (*p) > 57 ) {
			if ( 62 <= (*p) && (*p) <= 64 )
				goto tr714;
		} else
			goto tr716;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr714;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr714;
		} else
			goto tr716;
	} else
		goto tr716;
	goto tr713;
tr717:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st521;
st521:
	if ( ++p == pe )
		goto _test_eof521;
case 521:
#line 11636 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 10: goto tr731;
		case 48: goto tr753;
		case 59: goto tr732;
		case 61: goto tr733;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr729;
	goto tr713;
tr753:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st522;
st522:
	if ( ++p == pe )
		goto _test_eof522;
case 522:
#line 11657 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 10: goto tr731;
		case 48: goto tr754;
		case 59: goto tr732;
		case 61: goto tr733;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr729;
	goto tr713;
tr754:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st523;
st523:
	if ( ++p == pe )
		goto _test_eof523;
case 523:
#line 11678 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 10: goto tr731;
		case 48: goto tr755;
		case 59: goto tr732;
		case 61: goto tr733;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr729;
	goto tr713;
tr755:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st524;
st524:
	if ( ++p == pe )
		goto _test_eof524;
case 524:
#line 11699 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 10: goto tr731;
		case 59: goto tr732;
		case 61: goto tr733;
		case 71: goto tr756;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr729;
	goto tr713;
tr733:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st525;
st525:
	if ( ++p == pe )
		goto _test_eof525;
case 525:
#line 11720 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr758;
	} else if ( (*p) >= 33 )
		goto tr758;
	goto tr757;
tr758:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st526;
st526:
	if ( ++p == pe )
		goto _test_eof526;
case 526:
#line 11737 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 10: goto tr731;
		case 59: goto tr732;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr758;
	goto tr757;
tr756:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st527;
st527:
	if ( ++p == pe )
		goto _test_eof527;
case 527:
#line 11756 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 10: goto tr731;
		case 59: goto tr732;
		case 61: goto tr760;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr729;
	goto tr759;
tr760:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st528;
st528:
	if ( ++p == pe )
		goto _test_eof528;
case 528:
#line 11776 "inc/vcf/validator_detail_v42.hpp"
	if ( 48 <= (*p) && (*p) <= 49 )
		goto tr762;
	goto tr761;
tr762:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st529;
st529:
	if ( ++p == pe )
		goto _test_eof529;
case 529:
#line 11790 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 10: goto tr731;
		case 59: goto tr732;
	}
	goto tr761;
tr718:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st530;
st530:
	if ( ++p == pe )
		goto _test_eof530;
case 530:
#line 11811 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 10: goto tr731;
		case 59: goto tr732;
		case 61: goto tr733;
		case 65: goto tr763;
		case 67: goto tr764;
		case 70: goto tr765;
		case 78: goto tr766;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr729;
	goto tr713;
tr763:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st531;
st531:
	if ( ++p == pe )
		goto _test_eof531;
case 531:
#line 11835 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 61 )
		goto tr767;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr729;
	} else if ( (*p) >= 33 )
		goto tr729;
	goto tr713;
tr767:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st532;
st532:
	if ( ++p == pe )
		goto _test_eof532;
case 532:
#line 11854 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 65: goto tr770;
		case 67: goto tr770;
		case 71: goto tr770;
		case 78: goto tr770;
		case 84: goto tr770;
		case 97: goto tr770;
		case 99: goto tr770;
		case 103: goto tr770;
		case 110: goto tr770;
		case 116: goto tr770;
	}
	if ( 45 <= (*p) && (*p) <= 46 )
		goto tr769;
	goto tr768;
tr769:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st533;
st533:
	if ( ++p == pe )
		goto _test_eof533;
case 533:
#line 11880 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 10: goto tr731;
		case 59: goto tr732;
	}
	goto tr768;
tr770:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st534;
st534:
	if ( ++p == pe )
		goto _test_eof534;
case 534:
#line 11897 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 10: goto tr731;
		case 59: goto tr732;
		case 65: goto tr770;
		case 67: goto tr770;
		case 71: goto tr770;
		case 78: goto tr770;
		case 84: goto tr770;
		case 97: goto tr770;
		case 99: goto tr770;
		case 103: goto tr770;
		case 110: goto tr770;
		case 116: goto tr770;
	}
	goto tr768;
tr764:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st535;
st535:
	if ( ++p == pe )
		goto _test_eof535;
case 535:
#line 11924 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 61 )
		goto tr771;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr729;
	} else if ( (*p) >= 33 )
		goto tr729;
	goto tr713;
tr771:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st536;
st536:
	if ( ++p == pe )
		goto _test_eof536;
case 536:
#line 11943 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 43: goto tr773;
		case 45: goto tr773;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr774;
	goto tr772;
tr773:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st537;
st537:
	if ( ++p == pe )
		goto _test_eof537;
case 537:
#line 11961 "inc/vcf/validator_detail_v42.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr774;
	goto tr772;
tr774:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st538;
st538:
	if ( ++p == pe )
		goto _test_eof538;
case 538:
#line 11975 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 10: goto tr731;
		case 44: goto tr771;
		case 59: goto tr732;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr774;
	goto tr772;
tr765:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st539;
st539:
	if ( ++p == pe )
		goto _test_eof539;
case 539:
#line 11995 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 61 )
		goto tr775;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr729;
	} else if ( (*p) >= 33 )
		goto tr729;
	goto tr713;
tr775:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st540;
st540:
	if ( ++p == pe )
		goto _test_eof540;
case 540:
#line 12014 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 43: goto tr777;
		case 45: goto tr777;
		case 46: goto tr778;
		case 73: goto tr780;
		case 78: goto tr781;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr779;
	goto tr776;
tr777:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st541;
st541:
	if ( ++p == pe )
		goto _test_eof541;
case 541:
#line 12035 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 46: goto tr778;
		case 73: goto tr780;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr779;
	goto tr776;
tr778:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st542;
st542:
	if ( ++p == pe )
		goto _test_eof542;
case 542:
#line 12053 "inc/vcf/validator_detail_v42.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr782;
	goto tr776;
tr782:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st543;
st543:
	if ( ++p == pe )
		goto _test_eof543;
case 543:
#line 12067 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 10: goto tr731;
		case 44: goto tr775;
		case 59: goto tr732;
		case 69: goto tr783;
		case 101: goto tr783;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr782;
	goto tr776;
tr783:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st544;
st544:
	if ( ++p == pe )
		goto _test_eof544;
case 544:
#line 12089 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 43: goto tr784;
		case 45: goto tr784;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr785;
	goto tr776;
tr784:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st545;
st545:
	if ( ++p == pe )
		goto _test_eof545;
case 545:
#line 12107 "inc/vcf/validator_detail_v42.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr785;
	goto tr776;
tr785:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st546;
st546:
	if ( ++p == pe )
		goto _test_eof546;
case 546:
#line 12121 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 10: goto tr731;
		case 44: goto tr775;
		case 59: goto tr732;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr785;
	goto tr776;
tr779:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st547;
st547:
	if ( ++p == pe )
		goto _test_eof547;
case 547:
#line 12141 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 10: goto tr731;
		case 44: goto tr775;
		case 46: goto tr778;
		case 59: goto tr732;
		case 69: goto tr783;
		case 101: goto tr783;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr779;
	goto tr776;
tr780:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st548;
st548:
	if ( ++p == pe )
		goto _test_eof548;
case 548:
#line 12164 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 110 )
		goto tr786;
	goto tr776;
tr786:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st549;
st549:
	if ( ++p == pe )
		goto _test_eof549;
case 549:
#line 12178 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 102 )
		goto tr787;
	goto tr776;
tr787:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st550;
st550:
	if ( ++p == pe )
		goto _test_eof550;
case 550:
#line 12192 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 10: goto tr731;
		case 44: goto tr775;
		case 59: goto tr732;
	}
	goto tr776;
tr781:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st551;
st551:
	if ( ++p == pe )
		goto _test_eof551;
case 551:
#line 12210 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 97 )
		goto tr788;
	goto tr776;
tr788:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st552;
st552:
	if ( ++p == pe )
		goto _test_eof552;
case 552:
#line 12224 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 78 )
		goto tr787;
	goto tr776;
tr766:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st553;
st553:
	if ( ++p == pe )
		goto _test_eof553;
case 553:
#line 12238 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 61 )
		goto tr789;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr729;
	} else if ( (*p) >= 33 )
		goto tr729;
	goto tr713;
tr789:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st554;
st554:
	if ( ++p == pe )
		goto _test_eof554;
case 554:
#line 12257 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 43: goto tr791;
		case 45: goto tr791;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr792;
	goto tr790;
tr791:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st555;
st555:
	if ( ++p == pe )
		goto _test_eof555;
case 555:
#line 12275 "inc/vcf/validator_detail_v42.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr792;
	goto tr790;
tr792:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st556;
st556:
	if ( ++p == pe )
		goto _test_eof556;
case 556:
#line 12289 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 10: goto tr731;
		case 59: goto tr732;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr792;
	goto tr790;
tr719:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st557;
st557:
	if ( ++p == pe )
		goto _test_eof557;
case 557:
#line 12312 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 10: goto tr731;
		case 59: goto tr732;
		case 61: goto tr733;
		case 81: goto tr793;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr729;
	goto tr713;
tr793:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st558;
st558:
	if ( ++p == pe )
		goto _test_eof558;
case 558:
#line 12333 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 61 )
		goto tr794;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr729;
	} else if ( (*p) >= 33 )
		goto tr729;
	goto tr713;
tr794:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st559;
st559:
	if ( ++p == pe )
		goto _test_eof559;
case 559:
#line 12352 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 43: goto tr796;
		case 45: goto tr796;
		case 46: goto tr797;
		case 73: goto tr799;
		case 78: goto tr800;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr798;
	goto tr795;
tr796:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st560;
st560:
	if ( ++p == pe )
		goto _test_eof560;
case 560:
#line 12373 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 46: goto tr797;
		case 73: goto tr799;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr798;
	goto tr795;
tr797:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st561;
st561:
	if ( ++p == pe )
		goto _test_eof561;
case 561:
#line 12391 "inc/vcf/validator_detail_v42.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr801;
	goto tr795;
tr801:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st562;
st562:
	if ( ++p == pe )
		goto _test_eof562;
case 562:
#line 12405 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 10: goto tr731;
		case 59: goto tr732;
		case 69: goto tr802;
		case 101: goto tr802;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr801;
	goto tr795;
tr802:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st563;
st563:
	if ( ++p == pe )
		goto _test_eof563;
case 563:
#line 12426 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 43: goto tr803;
		case 45: goto tr803;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr804;
	goto tr795;
tr803:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st564;
st564:
	if ( ++p == pe )
		goto _test_eof564;
case 564:
#line 12444 "inc/vcf/validator_detail_v42.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr804;
	goto tr795;
tr804:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st565;
st565:
	if ( ++p == pe )
		goto _test_eof565;
case 565:
#line 12458 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 10: goto tr731;
		case 59: goto tr732;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr804;
	goto tr795;
tr798:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st566;
st566:
	if ( ++p == pe )
		goto _test_eof566;
case 566:
#line 12477 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 10: goto tr731;
		case 46: goto tr797;
		case 59: goto tr732;
		case 69: goto tr802;
		case 101: goto tr802;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr798;
	goto tr795;
tr799:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st567;
st567:
	if ( ++p == pe )
		goto _test_eof567;
case 567:
#line 12499 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 110 )
		goto tr805;
	goto tr795;
tr805:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st568;
st568:
	if ( ++p == pe )
		goto _test_eof568;
case 568:
#line 12513 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 102 )
		goto tr806;
	goto tr795;
tr806:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st569;
st569:
	if ( ++p == pe )
		goto _test_eof569;
case 569:
#line 12527 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 10: goto tr731;
		case 59: goto tr732;
	}
	goto tr795;
tr800:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st570;
st570:
	if ( ++p == pe )
		goto _test_eof570;
case 570:
#line 12544 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 97 )
		goto tr807;
	goto tr795;
tr807:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st571;
st571:
	if ( ++p == pe )
		goto _test_eof571;
case 571:
#line 12558 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 78 )
		goto tr806;
	goto tr795;
tr720:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st572;
st572:
	if ( ++p == pe )
		goto _test_eof572;
case 572:
#line 12576 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 10: goto tr731;
		case 59: goto tr732;
		case 61: goto tr733;
		case 73: goto tr808;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr729;
	goto tr713;
tr808:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st573;
st573:
	if ( ++p == pe )
		goto _test_eof573;
case 573:
#line 12597 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 10: goto tr731;
		case 59: goto tr732;
		case 61: goto tr733;
		case 71: goto tr809;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr729;
	goto tr713;
tr809:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st574;
st574:
	if ( ++p == pe )
		goto _test_eof574;
case 574:
#line 12618 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 10: goto tr731;
		case 59: goto tr732;
		case 61: goto tr733;
		case 65: goto tr810;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr729;
	goto tr713;
tr810:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st575;
st575:
	if ( ++p == pe )
		goto _test_eof575;
case 575:
#line 12639 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 10: goto tr731;
		case 59: goto tr732;
		case 61: goto tr733;
		case 82: goto tr811;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr729;
	goto tr713;
tr811:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st576;
st576:
	if ( ++p == pe )
		goto _test_eof576;
case 576:
#line 12660 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 61 )
		goto tr812;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr729;
	} else if ( (*p) >= 33 )
		goto tr729;
	goto tr713;
tr812:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st577;
st577:
	if ( ++p == pe )
		goto _test_eof577;
case 577:
#line 12679 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr814;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr814;
	} else
		goto tr814;
	goto tr813;
tr814:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st578;
st578:
	if ( ++p == pe )
		goto _test_eof578;
case 578:
#line 12699 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 10: goto tr731;
		case 59: goto tr732;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr814;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr814;
	} else
		goto tr814;
	goto tr813;
tr721:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st579;
st579:
	if ( ++p == pe )
		goto _test_eof579;
case 579:
#line 12728 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 10: goto tr731;
		case 59: goto tr732;
		case 61: goto tr733;
		case 66: goto tr815;
		case 80: goto tr816;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr729;
	goto tr713;
tr815:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st580;
st580:
	if ( ++p == pe )
		goto _test_eof580;
case 580:
#line 12750 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 10: goto tr731;
		case 59: goto tr732;
		case 61: goto tr818;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr729;
	goto tr817;
tr818:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st581;
st581:
	if ( ++p == pe )
		goto _test_eof581;
case 581:
#line 12770 "inc/vcf/validator_detail_v42.hpp"
	if ( 48 <= (*p) && (*p) <= 49 )
		goto tr820;
	goto tr819;
tr820:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st582;
st582:
	if ( ++p == pe )
		goto _test_eof582;
case 582:
#line 12784 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 10: goto tr731;
		case 59: goto tr732;
	}
	goto tr819;
tr816:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st583;
st583:
	if ( ++p == pe )
		goto _test_eof583;
case 583:
#line 12801 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 61 )
		goto tr821;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr729;
	} else if ( (*p) >= 33 )
		goto tr729;
	goto tr713;
tr821:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st584;
st584:
	if ( ++p == pe )
		goto _test_eof584;
case 584:
#line 12820 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 43: goto tr823;
		case 45: goto tr823;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr824;
	goto tr822;
tr823:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st585;
st585:
	if ( ++p == pe )
		goto _test_eof585;
case 585:
#line 12838 "inc/vcf/validator_detail_v42.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr824;
	goto tr822;
tr824:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st586;
st586:
	if ( ++p == pe )
		goto _test_eof586;
case 586:
#line 12852 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 10: goto tr731;
		case 59: goto tr732;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr824;
	goto tr822;
tr722:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st587;
st587:
	if ( ++p == pe )
		goto _test_eof587;
case 587:
#line 12875 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 10: goto tr731;
		case 59: goto tr732;
		case 61: goto tr733;
		case 78: goto tr825;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr729;
	goto tr713;
tr825:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st588;
st588:
	if ( ++p == pe )
		goto _test_eof588;
case 588:
#line 12896 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 10: goto tr731;
		case 59: goto tr732;
		case 61: goto tr733;
		case 68: goto tr826;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr729;
	goto tr713;
tr826:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st589;
st589:
	if ( ++p == pe )
		goto _test_eof589;
case 589:
#line 12917 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 61 )
		goto tr827;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr729;
	} else if ( (*p) >= 33 )
		goto tr729;
	goto tr713;
tr827:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st590;
st590:
	if ( ++p == pe )
		goto _test_eof590;
case 590:
#line 12936 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 43: goto tr829;
		case 45: goto tr829;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr830;
	goto tr828;
tr829:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st591;
st591:
	if ( ++p == pe )
		goto _test_eof591;
case 591:
#line 12954 "inc/vcf/validator_detail_v42.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr830;
	goto tr828;
tr830:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st592;
st592:
	if ( ++p == pe )
		goto _test_eof592;
case 592:
#line 12968 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 10: goto tr731;
		case 59: goto tr732;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr830;
	goto tr828;
tr723:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st593;
st593:
	if ( ++p == pe )
		goto _test_eof593;
case 593:
#line 12991 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 10: goto tr731;
		case 50: goto tr831;
		case 51: goto tr832;
		case 59: goto tr732;
		case 61: goto tr733;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr729;
	goto tr713;
tr831:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st594;
st594:
	if ( ++p == pe )
		goto _test_eof594;
case 594:
#line 13013 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 10: goto tr731;
		case 59: goto tr732;
		case 61: goto tr834;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr729;
	goto tr833;
tr834:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st595;
st595:
	if ( ++p == pe )
		goto _test_eof595;
case 595:
#line 13033 "inc/vcf/validator_detail_v42.hpp"
	if ( 48 <= (*p) && (*p) <= 49 )
		goto tr836;
	goto tr835;
tr836:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st596;
st596:
	if ( ++p == pe )
		goto _test_eof596;
case 596:
#line 13047 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 10: goto tr731;
		case 59: goto tr732;
	}
	goto tr835;
tr832:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st597;
st597:
	if ( ++p == pe )
		goto _test_eof597;
case 597:
#line 13064 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 10: goto tr731;
		case 59: goto tr732;
		case 61: goto tr838;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr729;
	goto tr837;
tr838:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st598;
st598:
	if ( ++p == pe )
		goto _test_eof598;
case 598:
#line 13084 "inc/vcf/validator_detail_v42.hpp"
	if ( 48 <= (*p) && (*p) <= 49 )
		goto tr840;
	goto tr839;
tr840:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st599;
st599:
	if ( ++p == pe )
		goto _test_eof599;
case 599:
#line 13098 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 10: goto tr731;
		case 59: goto tr732;
	}
	goto tr839;
tr724:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st600;
st600:
	if ( ++p == pe )
		goto _test_eof600;
case 600:
#line 13119 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 10: goto tr731;
		case 59: goto tr732;
		case 61: goto tr733;
		case 81: goto tr841;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr729;
	goto tr713;
tr841:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st601;
st601:
	if ( ++p == pe )
		goto _test_eof601;
case 601:
#line 13140 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 48: goto tr842;
		case 61: goto tr843;
	}
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr729;
	} else if ( (*p) >= 33 )
		goto tr729;
	goto tr713;
tr842:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st602;
st602:
	if ( ++p == pe )
		goto _test_eof602;
case 602:
#line 13161 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 61 )
		goto tr844;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr729;
	} else if ( (*p) >= 33 )
		goto tr729;
	goto tr713;
tr844:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st603;
st603:
	if ( ++p == pe )
		goto _test_eof603;
case 603:
#line 13180 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 43: goto tr846;
		case 45: goto tr846;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr847;
	goto tr845;
tr846:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st604;
st604:
	if ( ++p == pe )
		goto _test_eof604;
case 604:
#line 13198 "inc/vcf/validator_detail_v42.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr847;
	goto tr845;
tr847:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st605;
st605:
	if ( ++p == pe )
		goto _test_eof605;
case 605:
#line 13212 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 10: goto tr731;
		case 59: goto tr732;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr847;
	goto tr845;
tr843:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st606;
st606:
	if ( ++p == pe )
		goto _test_eof606;
case 606:
#line 13231 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 43: goto tr849;
		case 45: goto tr849;
		case 46: goto tr850;
		case 73: goto tr852;
		case 78: goto tr853;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr851;
	goto tr848;
tr849:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st607;
st607:
	if ( ++p == pe )
		goto _test_eof607;
case 607:
#line 13252 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 46: goto tr850;
		case 73: goto tr852;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr851;
	goto tr848;
tr850:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st608;
st608:
	if ( ++p == pe )
		goto _test_eof608;
case 608:
#line 13270 "inc/vcf/validator_detail_v42.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr854;
	goto tr848;
tr854:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st609;
st609:
	if ( ++p == pe )
		goto _test_eof609;
case 609:
#line 13284 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 10: goto tr731;
		case 59: goto tr732;
		case 69: goto tr855;
		case 101: goto tr855;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr854;
	goto tr848;
tr855:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st610;
st610:
	if ( ++p == pe )
		goto _test_eof610;
case 610:
#line 13305 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 43: goto tr856;
		case 45: goto tr856;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr857;
	goto tr848;
tr856:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st611;
st611:
	if ( ++p == pe )
		goto _test_eof611;
case 611:
#line 13323 "inc/vcf/validator_detail_v42.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr857;
	goto tr848;
tr857:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st612;
st612:
	if ( ++p == pe )
		goto _test_eof612;
case 612:
#line 13337 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 10: goto tr731;
		case 59: goto tr732;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr857;
	goto tr848;
tr851:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st613;
st613:
	if ( ++p == pe )
		goto _test_eof613;
case 613:
#line 13356 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 10: goto tr731;
		case 46: goto tr850;
		case 59: goto tr732;
		case 69: goto tr855;
		case 101: goto tr855;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr851;
	goto tr848;
tr852:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st614;
st614:
	if ( ++p == pe )
		goto _test_eof614;
case 614:
#line 13378 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 110 )
		goto tr858;
	goto tr848;
tr858:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st615;
st615:
	if ( ++p == pe )
		goto _test_eof615;
case 615:
#line 13392 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 102 )
		goto tr859;
	goto tr848;
tr859:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st616;
st616:
	if ( ++p == pe )
		goto _test_eof616;
case 616:
#line 13406 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 10: goto tr731;
		case 59: goto tr732;
	}
	goto tr848;
tr853:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st617;
st617:
	if ( ++p == pe )
		goto _test_eof617;
case 617:
#line 13423 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 97 )
		goto tr860;
	goto tr848;
tr860:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st618;
st618:
	if ( ++p == pe )
		goto _test_eof618;
case 618:
#line 13437 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 78 )
		goto tr859;
	goto tr848;
tr725:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st619;
st619:
	if ( ++p == pe )
		goto _test_eof619;
case 619:
#line 13455 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 10: goto tr731;
		case 59: goto tr732;
		case 61: goto tr733;
		case 83: goto tr861;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr729;
	goto tr713;
tr861:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st620;
st620:
	if ( ++p == pe )
		goto _test_eof620;
case 620:
#line 13476 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 61 )
		goto tr862;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr729;
	} else if ( (*p) >= 33 )
		goto tr729;
	goto tr713;
tr862:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st621;
st621:
	if ( ++p == pe )
		goto _test_eof621;
case 621:
#line 13495 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 43: goto tr864;
		case 45: goto tr864;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr865;
	goto tr863;
tr864:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st622;
st622:
	if ( ++p == pe )
		goto _test_eof622;
case 622:
#line 13513 "inc/vcf/validator_detail_v42.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr865;
	goto tr863;
tr865:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st623;
st623:
	if ( ++p == pe )
		goto _test_eof623;
case 623:
#line 13527 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 10: goto tr731;
		case 59: goto tr732;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr865;
	goto tr863;
tr726:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st624;
st624:
	if ( ++p == pe )
		goto _test_eof624;
case 624:
#line 13550 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 10: goto tr731;
		case 59: goto tr732;
		case 61: goto tr733;
		case 66: goto tr866;
		case 79: goto tr867;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr729;
	goto tr713;
tr866:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st625;
st625:
	if ( ++p == pe )
		goto _test_eof625;
case 625:
#line 13572 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 61 )
		goto tr868;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr729;
	} else if ( (*p) >= 33 )
		goto tr729;
	goto tr713;
tr868:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st626;
st626:
	if ( ++p == pe )
		goto _test_eof626;
case 626:
#line 13591 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 43: goto tr870;
		case 45: goto tr870;
		case 46: goto tr871;
		case 73: goto tr873;
		case 78: goto tr874;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr872;
	goto tr869;
tr870:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st627;
st627:
	if ( ++p == pe )
		goto _test_eof627;
case 627:
#line 13612 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 46: goto tr871;
		case 73: goto tr873;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr872;
	goto tr869;
tr871:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st628;
st628:
	if ( ++p == pe )
		goto _test_eof628;
case 628:
#line 13630 "inc/vcf/validator_detail_v42.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr875;
	goto tr869;
tr875:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st629;
st629:
	if ( ++p == pe )
		goto _test_eof629;
case 629:
#line 13644 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 10: goto tr731;
		case 59: goto tr732;
		case 69: goto tr876;
		case 101: goto tr876;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr875;
	goto tr869;
tr876:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st630;
st630:
	if ( ++p == pe )
		goto _test_eof630;
case 630:
#line 13665 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 43: goto tr877;
		case 45: goto tr877;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr878;
	goto tr869;
tr877:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st631;
st631:
	if ( ++p == pe )
		goto _test_eof631;
case 631:
#line 13683 "inc/vcf/validator_detail_v42.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr878;
	goto tr869;
tr878:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st632;
st632:
	if ( ++p == pe )
		goto _test_eof632;
case 632:
#line 13697 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 10: goto tr731;
		case 59: goto tr732;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr878;
	goto tr869;
tr872:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st633;
st633:
	if ( ++p == pe )
		goto _test_eof633;
case 633:
#line 13716 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 10: goto tr731;
		case 46: goto tr871;
		case 59: goto tr732;
		case 69: goto tr876;
		case 101: goto tr876;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr872;
	goto tr869;
tr873:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st634;
st634:
	if ( ++p == pe )
		goto _test_eof634;
case 634:
#line 13738 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 110 )
		goto tr879;
	goto tr869;
tr879:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st635;
st635:
	if ( ++p == pe )
		goto _test_eof635;
case 635:
#line 13752 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 102 )
		goto tr880;
	goto tr869;
tr880:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st636;
st636:
	if ( ++p == pe )
		goto _test_eof636;
case 636:
#line 13766 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 10: goto tr731;
		case 59: goto tr732;
	}
	goto tr869;
tr874:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st637;
st637:
	if ( ++p == pe )
		goto _test_eof637;
case 637:
#line 13783 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 97 )
		goto tr881;
	goto tr869;
tr881:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st638;
st638:
	if ( ++p == pe )
		goto _test_eof638;
case 638:
#line 13797 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 78 )
		goto tr880;
	goto tr869;
tr867:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st639;
st639:
	if ( ++p == pe )
		goto _test_eof639;
case 639:
#line 13811 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 10: goto tr731;
		case 59: goto tr732;
		case 61: goto tr733;
		case 77: goto tr882;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr729;
	goto tr713;
tr882:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st640;
st640:
	if ( ++p == pe )
		goto _test_eof640;
case 640:
#line 13832 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 10: goto tr731;
		case 59: goto tr732;
		case 61: goto tr733;
		case 65: goto tr883;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr729;
	goto tr713;
tr883:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st641;
st641:
	if ( ++p == pe )
		goto _test_eof641;
case 641:
#line 13853 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 10: goto tr731;
		case 59: goto tr732;
		case 61: goto tr733;
		case 84: goto tr884;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr729;
	goto tr713;
tr884:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st642;
st642:
	if ( ++p == pe )
		goto _test_eof642;
case 642:
#line 13874 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 10: goto tr731;
		case 59: goto tr732;
		case 61: goto tr733;
		case 73: goto tr885;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr729;
	goto tr713;
tr885:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st643;
st643:
	if ( ++p == pe )
		goto _test_eof643;
case 643:
#line 13895 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 10: goto tr731;
		case 59: goto tr732;
		case 61: goto tr733;
		case 67: goto tr886;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr729;
	goto tr713;
tr886:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st644;
st644:
	if ( ++p == pe )
		goto _test_eof644;
case 644:
#line 13916 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 10: goto tr731;
		case 59: goto tr732;
		case 61: goto tr888;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr729;
	goto tr887;
tr888:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st645;
st645:
	if ( ++p == pe )
		goto _test_eof645;
case 645:
#line 13936 "inc/vcf/validator_detail_v42.hpp"
	if ( 48 <= (*p) && (*p) <= 49 )
		goto tr890;
	goto tr889;
tr890:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st646;
st646:
	if ( ++p == pe )
		goto _test_eof646;
case 646:
#line 13950 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 10: goto tr731;
		case 59: goto tr732;
	}
	goto tr889;
tr727:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st647;
st647:
	if ( ++p == pe )
		goto _test_eof647;
case 647:
#line 13971 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 10: goto tr731;
		case 59: goto tr732;
		case 61: goto tr733;
		case 65: goto tr891;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr729;
	goto tr713;
tr891:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st648;
st648:
	if ( ++p == pe )
		goto _test_eof648;
case 648:
#line 13992 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 10: goto tr731;
		case 59: goto tr732;
		case 61: goto tr733;
		case 76: goto tr892;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr729;
	goto tr713;
tr892:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st649;
st649:
	if ( ++p == pe )
		goto _test_eof649;
case 649:
#line 14013 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 10: goto tr731;
		case 59: goto tr732;
		case 61: goto tr733;
		case 73: goto tr893;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr729;
	goto tr713;
tr893:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st650;
st650:
	if ( ++p == pe )
		goto _test_eof650;
case 650:
#line 14034 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 10: goto tr731;
		case 59: goto tr732;
		case 61: goto tr733;
		case 68: goto tr894;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr729;
	goto tr713;
tr894:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st651;
st651:
	if ( ++p == pe )
		goto _test_eof651;
case 651:
#line 14055 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 10: goto tr731;
		case 59: goto tr732;
		case 61: goto tr733;
		case 65: goto tr895;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr729;
	goto tr713;
tr895:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st652;
st652:
	if ( ++p == pe )
		goto _test_eof652;
case 652:
#line 14076 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 10: goto tr731;
		case 59: goto tr732;
		case 61: goto tr733;
		case 84: goto tr896;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr729;
	goto tr713;
tr896:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st653;
st653:
	if ( ++p == pe )
		goto _test_eof653;
case 653:
#line 14097 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 10: goto tr731;
		case 59: goto tr732;
		case 61: goto tr733;
		case 69: goto tr897;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr729;
	goto tr713;
tr897:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st654;
st654:
	if ( ++p == pe )
		goto _test_eof654;
case 654:
#line 14118 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 10: goto tr731;
		case 59: goto tr732;
		case 61: goto tr733;
		case 68: goto tr898;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr729;
	goto tr713;
tr898:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st655;
st655:
	if ( ++p == pe )
		goto _test_eof655;
case 655:
#line 14139 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 10: goto tr731;
		case 59: goto tr732;
		case 61: goto tr900;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr729;
	goto tr899;
tr900:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st656;
st656:
	if ( ++p == pe )
		goto _test_eof656;
case 656:
#line 14159 "inc/vcf/validator_detail_v42.hpp"
	if ( 48 <= (*p) && (*p) <= 49 )
		goto tr902;
	goto tr901;
tr902:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st657;
st657:
	if ( ++p == pe )
		goto _test_eof657;
case 657:
#line 14173 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 10: goto tr731;
		case 59: goto tr732;
	}
	goto tr901;
tr715:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st658;
st658:
	if ( ++p == pe )
		goto _test_eof658;
case 658:
#line 14194 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 10: goto tr731;
		case 58: goto tr728;
		case 60: goto tr728;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr728;
		} else if ( (*p) > 57 ) {
			if ( 62 <= (*p) && (*p) <= 64 )
				goto tr728;
		} else
			goto tr729;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr728;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr728;
		} else
			goto tr729;
	} else
		goto tr729;
	goto tr713;
tr712:
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st659;
st659:
	if ( ++p == pe )
		goto _test_eof659;
case 659:
#line 14232 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 58 )
		goto tr706;
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr706;
		} else if ( (*p) > 57 ) {
			if ( 60 <= (*p) && (*p) <= 64 )
				goto tr706;
		} else
			goto tr708;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr706;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr706;
		} else
			goto tr708;
	} else
		goto tr708;
	goto tr705;
tr707:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st660;
st660:
	if ( ++p == pe )
		goto _test_eof660;
case 660:
#line 14270 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr711;
		case 58: goto st502;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto st502;
		} else if ( (*p) > 57 ) {
			if ( 60 <= (*p) && (*p) <= 64 )
				goto st502;
		} else
			goto tr710;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st502;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st502;
		} else
			goto tr710;
	} else
		goto tr710;
	goto tr705;
tr704:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st661;
st661:
	if ( ++p == pe )
		goto _test_eof661;
case 661:
#line 14306 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 43: goto tr903;
		case 45: goto tr903;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr904;
	goto tr693;
tr903:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st662;
st662:
	if ( ++p == pe )
		goto _test_eof662;
case 662:
#line 14324 "inc/vcf/validator_detail_v42.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr904;
	goto tr693;
tr904:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st663;
st663:
	if ( ++p == pe )
		goto _test_eof663;
case 663:
#line 14338 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 9 )
		goto tr703;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr904;
	goto tr693;
tr696:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st664;
tr700:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st664;
st664:
	if ( ++p == pe )
		goto _test_eof664;
case 664:
#line 14364 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr703;
		case 46: goto tr699;
		case 69: goto tr704;
		case 101: goto tr704;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr700;
	goto tr693;
tr697:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st665;
tr701:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st665;
st665:
	if ( ++p == pe )
		goto _test_eof665;
case 665:
#line 14394 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 110 )
		goto tr905;
	goto tr693;
tr905:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st666;
st666:
	if ( ++p == pe )
		goto _test_eof666;
case 666:
#line 14408 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 102 )
		goto tr906;
	goto tr693;
tr906:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st667;
st667:
	if ( ++p == pe )
		goto _test_eof667;
case 667:
#line 14422 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 9 )
		goto tr703;
	goto tr693;
tr695:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st668;
st668:
	if ( ++p == pe )
		goto _test_eof668;
case 668:
#line 14440 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 9 )
		goto tr703;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr702;
	goto tr693;
tr698:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st669;
st669:
	if ( ++p == pe )
		goto _test_eof669;
case 669:
#line 14460 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 97 )
		goto tr907;
	goto tr693;
tr907:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st670;
st670:
	if ( ++p == pe )
		goto _test_eof670;
case 670:
#line 14474 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 78 )
		goto tr906;
	goto tr693;
tr692:
#line 39 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st671;
st671:
	if ( ++p == pe )
		goto _test_eof671;
case 671:
#line 14488 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 42: goto tr685;
		case 46: goto tr908;
		case 60: goto tr687;
		case 65: goto tr688;
		case 67: goto tr688;
		case 71: goto tr688;
		case 78: goto tr688;
		case 84: goto tr688;
		case 91: goto tr689;
		case 93: goto tr690;
		case 97: goto tr688;
		case 99: goto tr688;
		case 103: goto tr688;
		case 110: goto tr688;
		case 116: goto tr688;
	}
	goto tr684;
tr908:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st672;
tr945:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st672;
st672:
	if ( ++p == pe )
		goto _test_eof672;
case 672:
#line 14527 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 65: goto tr909;
		case 67: goto tr909;
		case 71: goto tr909;
		case 78: goto tr909;
		case 84: goto tr909;
		case 97: goto tr909;
		case 99: goto tr909;
		case 103: goto tr909;
		case 110: goto tr909;
		case 116: goto tr909;
	}
	goto tr684;
tr909:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st673;
st673:
	if ( ++p == pe )
		goto _test_eof673;
case 673:
#line 14551 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr691;
		case 44: goto tr692;
		case 65: goto tr909;
		case 67: goto tr909;
		case 71: goto tr909;
		case 78: goto tr909;
		case 84: goto tr909;
		case 97: goto tr909;
		case 99: goto tr909;
		case 103: goto tr909;
		case 110: goto tr909;
		case 116: goto tr909;
	}
	goto tr684;
tr687:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st674;
tr911:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st674;
st674:
	if ( ++p == pe )
		goto _test_eof674;
case 674:
#line 14587 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 58: goto tr911;
		case 95: goto tr911;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr910;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr910;
	} else
		goto tr910;
	goto tr684;
tr910:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st675;
st675:
	if ( ++p == pe )
		goto _test_eof675;
case 675:
#line 14611 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 62: goto tr912;
		case 95: goto tr910;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 58 )
			goto tr910;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr910;
	} else
		goto tr910;
	goto tr684;
tr688:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st676;
tr913:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st676;
st676:
	if ( ++p == pe )
		goto _test_eof676;
case 676:
#line 14645 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr691;
		case 44: goto tr692;
		case 46: goto tr912;
		case 65: goto tr913;
		case 67: goto tr913;
		case 71: goto tr913;
		case 78: goto tr913;
		case 84: goto tr913;
		case 91: goto tr914;
		case 93: goto tr915;
		case 97: goto tr913;
		case 99: goto tr913;
		case 103: goto tr913;
		case 110: goto tr913;
		case 116: goto tr913;
	}
	goto tr684;
tr914:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st677;
st677:
	if ( ++p == pe )
		goto _test_eof677;
case 677:
#line 14674 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 60 )
		goto tr917;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr916;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr916;
	} else
		goto tr916;
	goto tr684;
tr916:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st678;
st678:
	if ( ++p == pe )
		goto _test_eof678;
case 678:
#line 14696 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 58: goto tr920;
		case 59: goto tr918;
		case 61: goto tr918;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr918;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr918;
		} else
			goto tr919;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr918;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr918;
		} else
			goto tr919;
	} else
		goto tr919;
	goto tr684;
tr918:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st679;
st679:
	if ( ++p == pe )
		goto _test_eof679;
case 679:
#line 14733 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 59: goto tr918;
		case 61: goto tr918;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr918;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr918;
		} else
			goto tr919;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr918;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr918;
		} else
			goto tr919;
	} else
		goto tr919;
	goto tr684;
tr919:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st680;
st680:
	if ( ++p == pe )
		goto _test_eof680;
case 680:
#line 14769 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 58: goto tr920;
		case 61: goto tr919;
	}
	if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr919;
	} else if ( (*p) >= 33 )
		goto tr919;
	goto tr684;
tr920:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st681;
st681:
	if ( ++p == pe )
		goto _test_eof681;
case 681:
#line 14790 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 43: goto tr921;
		case 45: goto tr921;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr922;
	goto tr684;
tr921:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st682;
st682:
	if ( ++p == pe )
		goto _test_eof682;
case 682:
#line 14808 "inc/vcf/validator_detail_v42.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr922;
	goto tr684;
tr922:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st683;
st683:
	if ( ++p == pe )
		goto _test_eof683;
case 683:
#line 14822 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 91 )
		goto tr912;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr922;
	goto tr684;
tr917:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st684;
st684:
	if ( ++p == pe )
		goto _test_eof684;
case 684:
#line 14838 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr923;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr923;
	} else
		goto tr923;
	goto tr684;
tr923:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st685;
st685:
	if ( ++p == pe )
		goto _test_eof685;
case 685:
#line 14858 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 59: goto tr924;
		case 62: goto tr926;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr924;
		} else if ( (*p) > 57 ) {
			if ( 61 <= (*p) && (*p) <= 64 )
				goto tr924;
		} else
			goto tr925;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr924;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr924;
		} else
			goto tr925;
	} else
		goto tr925;
	goto tr684;
tr924:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st686;
st686:
	if ( ++p == pe )
		goto _test_eof686;
case 686:
#line 14894 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 59: goto tr924;
		case 61: goto tr924;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr924;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr924;
		} else
			goto tr925;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr924;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr924;
		} else
			goto tr925;
	} else
		goto tr925;
	goto tr684;
tr925:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st687;
st687:
	if ( ++p == pe )
		goto _test_eof687;
case 687:
#line 14930 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 59: goto tr925;
		case 62: goto tr926;
	}
	if ( (*p) > 57 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr925;
	} else if ( (*p) >= 33 )
		goto tr925;
	goto tr684;
tr926:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st688;
st688:
	if ( ++p == pe )
		goto _test_eof688;
case 688:
#line 14951 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 58 )
		goto tr920;
	goto tr684;
tr915:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st689;
st689:
	if ( ++p == pe )
		goto _test_eof689;
case 689:
#line 14965 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 60 )
		goto tr928;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr927;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr927;
	} else
		goto tr927;
	goto tr684;
tr927:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st690;
st690:
	if ( ++p == pe )
		goto _test_eof690;
case 690:
#line 14987 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 58: goto tr931;
		case 59: goto tr929;
		case 61: goto tr929;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr929;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr929;
		} else
			goto tr930;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr929;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr929;
		} else
			goto tr930;
	} else
		goto tr930;
	goto tr684;
tr929:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st691;
st691:
	if ( ++p == pe )
		goto _test_eof691;
case 691:
#line 15024 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 59: goto tr929;
		case 61: goto tr929;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr929;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr929;
		} else
			goto tr930;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr929;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr929;
		} else
			goto tr930;
	} else
		goto tr930;
	goto tr684;
tr930:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st692;
st692:
	if ( ++p == pe )
		goto _test_eof692;
case 692:
#line 15060 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 58: goto tr931;
		case 61: goto tr930;
	}
	if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr930;
	} else if ( (*p) >= 33 )
		goto tr930;
	goto tr684;
tr931:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st693;
st693:
	if ( ++p == pe )
		goto _test_eof693;
case 693:
#line 15081 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 43: goto tr932;
		case 45: goto tr932;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr933;
	goto tr684;
tr932:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st694;
st694:
	if ( ++p == pe )
		goto _test_eof694;
case 694:
#line 15099 "inc/vcf/validator_detail_v42.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr933;
	goto tr684;
tr933:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st695;
st695:
	if ( ++p == pe )
		goto _test_eof695;
case 695:
#line 15113 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 93 )
		goto tr912;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr933;
	goto tr684;
tr928:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st696;
st696:
	if ( ++p == pe )
		goto _test_eof696;
case 696:
#line 15129 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr934;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr934;
	} else
		goto tr934;
	goto tr684;
tr934:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st697;
st697:
	if ( ++p == pe )
		goto _test_eof697;
case 697:
#line 15149 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 59: goto tr935;
		case 62: goto tr937;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr935;
		} else if ( (*p) > 57 ) {
			if ( 61 <= (*p) && (*p) <= 64 )
				goto tr935;
		} else
			goto tr936;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr935;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr935;
		} else
			goto tr936;
	} else
		goto tr936;
	goto tr684;
tr935:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st698;
st698:
	if ( ++p == pe )
		goto _test_eof698;
case 698:
#line 15185 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 59: goto tr935;
		case 61: goto tr935;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr935;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr935;
		} else
			goto tr936;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr935;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr935;
		} else
			goto tr936;
	} else
		goto tr936;
	goto tr684;
tr936:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st699;
st699:
	if ( ++p == pe )
		goto _test_eof699;
case 699:
#line 15221 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 59: goto tr936;
		case 62: goto tr937;
	}
	if ( (*p) > 57 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr936;
	} else if ( (*p) >= 33 )
		goto tr936;
	goto tr684;
tr937:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st700;
st700:
	if ( ++p == pe )
		goto _test_eof700;
case 700:
#line 15242 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 58 )
		goto tr931;
	goto tr684;
tr689:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st701;
st701:
	if ( ++p == pe )
		goto _test_eof701;
case 701:
#line 15260 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 60 )
		goto tr939;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr938;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr938;
	} else
		goto tr938;
	goto tr684;
tr938:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st702;
st702:
	if ( ++p == pe )
		goto _test_eof702;
case 702:
#line 15282 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 58: goto tr942;
		case 59: goto tr940;
		case 61: goto tr940;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr940;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr940;
		} else
			goto tr941;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr940;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr940;
		} else
			goto tr941;
	} else
		goto tr941;
	goto tr684;
tr940:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st703;
st703:
	if ( ++p == pe )
		goto _test_eof703;
case 703:
#line 15319 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 59: goto tr940;
		case 61: goto tr940;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr940;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr940;
		} else
			goto tr941;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr940;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr940;
		} else
			goto tr941;
	} else
		goto tr941;
	goto tr684;
tr941:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st704;
st704:
	if ( ++p == pe )
		goto _test_eof704;
case 704:
#line 15355 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 58: goto tr942;
		case 61: goto tr941;
	}
	if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr941;
	} else if ( (*p) >= 33 )
		goto tr941;
	goto tr684;
tr942:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st705;
st705:
	if ( ++p == pe )
		goto _test_eof705;
case 705:
#line 15376 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 43: goto tr943;
		case 45: goto tr943;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr944;
	goto tr684;
tr943:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st706;
st706:
	if ( ++p == pe )
		goto _test_eof706;
case 706:
#line 15394 "inc/vcf/validator_detail_v42.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr944;
	goto tr684;
tr944:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st707;
st707:
	if ( ++p == pe )
		goto _test_eof707;
case 707:
#line 15408 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 91 )
		goto tr945;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr944;
	goto tr684;
tr939:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st708;
st708:
	if ( ++p == pe )
		goto _test_eof708;
case 708:
#line 15424 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr946;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr946;
	} else
		goto tr946;
	goto tr684;
tr946:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st709;
st709:
	if ( ++p == pe )
		goto _test_eof709;
case 709:
#line 15444 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 59: goto tr947;
		case 62: goto tr949;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr947;
		} else if ( (*p) > 57 ) {
			if ( 61 <= (*p) && (*p) <= 64 )
				goto tr947;
		} else
			goto tr948;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr947;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr947;
		} else
			goto tr948;
	} else
		goto tr948;
	goto tr684;
tr947:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st710;
st710:
	if ( ++p == pe )
		goto _test_eof710;
case 710:
#line 15480 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 59: goto tr947;
		case 61: goto tr947;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr947;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr947;
		} else
			goto tr948;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr947;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr947;
		} else
			goto tr948;
	} else
		goto tr948;
	goto tr684;
tr948:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st711;
st711:
	if ( ++p == pe )
		goto _test_eof711;
case 711:
#line 15516 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 59: goto tr948;
		case 62: goto tr949;
	}
	if ( (*p) > 57 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr948;
	} else if ( (*p) >= 33 )
		goto tr948;
	goto tr684;
tr949:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st712;
st712:
	if ( ++p == pe )
		goto _test_eof712;
case 712:
#line 15537 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 58 )
		goto tr942;
	goto tr684;
tr690:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st713;
st713:
	if ( ++p == pe )
		goto _test_eof713;
case 713:
#line 15555 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 60 )
		goto tr951;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr950;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr950;
	} else
		goto tr950;
	goto tr684;
tr950:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st714;
st714:
	if ( ++p == pe )
		goto _test_eof714;
case 714:
#line 15577 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 58: goto tr954;
		case 59: goto tr952;
		case 61: goto tr952;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr952;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr952;
		} else
			goto tr953;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr952;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr952;
		} else
			goto tr953;
	} else
		goto tr953;
	goto tr684;
tr952:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st715;
st715:
	if ( ++p == pe )
		goto _test_eof715;
case 715:
#line 15614 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 59: goto tr952;
		case 61: goto tr952;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr952;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr952;
		} else
			goto tr953;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr952;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr952;
		} else
			goto tr953;
	} else
		goto tr953;
	goto tr684;
tr953:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st716;
st716:
	if ( ++p == pe )
		goto _test_eof716;
case 716:
#line 15650 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 58: goto tr954;
		case 61: goto tr953;
	}
	if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr953;
	} else if ( (*p) >= 33 )
		goto tr953;
	goto tr684;
tr954:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st717;
st717:
	if ( ++p == pe )
		goto _test_eof717;
case 717:
#line 15671 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 43: goto tr955;
		case 45: goto tr955;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr956;
	goto tr684;
tr955:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st718;
st718:
	if ( ++p == pe )
		goto _test_eof718;
case 718:
#line 15689 "inc/vcf/validator_detail_v42.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr956;
	goto tr684;
tr956:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st719;
st719:
	if ( ++p == pe )
		goto _test_eof719;
case 719:
#line 15703 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 93 )
		goto tr945;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr956;
	goto tr684;
tr951:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st720;
st720:
	if ( ++p == pe )
		goto _test_eof720;
case 720:
#line 15719 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr957;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr957;
	} else
		goto tr957;
	goto tr684;
tr957:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st721;
st721:
	if ( ++p == pe )
		goto _test_eof721;
case 721:
#line 15739 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 59: goto tr958;
		case 62: goto tr960;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr958;
		} else if ( (*p) > 57 ) {
			if ( 61 <= (*p) && (*p) <= 64 )
				goto tr958;
		} else
			goto tr959;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr958;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr958;
		} else
			goto tr959;
	} else
		goto tr959;
	goto tr684;
tr958:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st722;
st722:
	if ( ++p == pe )
		goto _test_eof722;
case 722:
#line 15775 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 59: goto tr958;
		case 61: goto tr958;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr958;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr958;
		} else
			goto tr959;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr958;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr958;
		} else
			goto tr959;
	} else
		goto tr959;
	goto tr684;
tr959:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st723;
st723:
	if ( ++p == pe )
		goto _test_eof723;
case 723:
#line 15811 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 59: goto tr959;
		case 62: goto tr960;
	}
	if ( (*p) > 57 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr959;
	} else if ( (*p) >= 33 )
		goto tr959;
	goto tr684;
tr960:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st724;
st724:
	if ( ++p == pe )
		goto _test_eof724;
case 724:
#line 15832 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 58 )
		goto tr954;
	goto tr684;
tr686:
#line 31 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st725;
st725:
	if ( ++p == pe )
		goto _test_eof725;
case 725:
#line 15850 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr691;
		case 65: goto tr909;
		case 67: goto tr909;
		case 71: goto tr909;
		case 78: goto tr909;
		case 84: goto tr909;
		case 97: goto tr909;
		case 99: goto tr909;
		case 103: goto tr909;
		case 110: goto tr909;
		case 116: goto tr909;
	}
	goto tr684;
tr668:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st726;
st726:
	if ( ++p == pe )
		goto _test_eof726;
case 726:
#line 15875 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 59: goto tr668;
		case 61: goto tr668;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr668;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr668;
		} else
			goto tr669;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr668;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr668;
		} else
			goto tr669;
	} else
		goto tr669;
	goto tr666;
tr669:
#line 35 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st727;
st727:
	if ( ++p == pe )
		goto _test_eof727;
case 727:
#line 15911 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr667;
		case 59: goto tr669;
		case 61: goto tr669;
	}
	if ( (*p) > 57 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr669;
	} else if ( (*p) >= 33 )
		goto tr669;
	goto tr666;
st728:
	if ( ++p == pe )
		goto _test_eof728;
case 728:
	if ( (*p) == 10 )
		goto tr962;
	goto st728;
tr962:
#line 43 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
#line 746 "src/vcf/vcf_v42.ragel"
	{ {goto st28;} }
	goto st732;
st732:
	if ( ++p == pe )
		goto _test_eof732;
case 732:
#line 15948 "inc/vcf/validator_detail_v42.hpp"
	goto st0;
st729:
	if ( ++p == pe )
		goto _test_eof729;
case 729:
	if ( (*p) == 10 )
		goto tr964;
	goto st729;
tr964:
#line 43 "src/vcf/vcf_v42.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
#line 747 "src/vcf/vcf_v42.ragel"
	{ {goto st731;} }
	goto st733;
st733:
	if ( ++p == pe )
		goto _test_eof733;
case 733:
#line 15975 "inc/vcf/validator_detail_v42.hpp"
	goto st0;
	}
	_test_eof2: cs = 2; goto _test_eof; 
	_test_eof3: cs = 3; goto _test_eof; 
	_test_eof4: cs = 4; goto _test_eof; 
	_test_eof5: cs = 5; goto _test_eof; 
	_test_eof6: cs = 6; goto _test_eof; 
	_test_eof7: cs = 7; goto _test_eof; 
	_test_eof8: cs = 8; goto _test_eof; 
	_test_eof9: cs = 9; goto _test_eof; 
	_test_eof10: cs = 10; goto _test_eof; 
	_test_eof11: cs = 11; goto _test_eof; 
	_test_eof12: cs = 12; goto _test_eof; 
	_test_eof13: cs = 13; goto _test_eof; 
	_test_eof14: cs = 14; goto _test_eof; 
	_test_eof15: cs = 15; goto _test_eof; 
	_test_eof16: cs = 16; goto _test_eof; 
	_test_eof17: cs = 17; goto _test_eof; 
	_test_eof18: cs = 18; goto _test_eof; 
	_test_eof19: cs = 19; goto _test_eof; 
	_test_eof20: cs = 20; goto _test_eof; 
	_test_eof21: cs = 21; goto _test_eof; 
	_test_eof22: cs = 22; goto _test_eof; 
	_test_eof23: cs = 23; goto _test_eof; 
	_test_eof24: cs = 24; goto _test_eof; 
	_test_eof25: cs = 25; goto _test_eof; 
	_test_eof26: cs = 26; goto _test_eof; 
	_test_eof27: cs = 27; goto _test_eof; 
	_test_eof28: cs = 28; goto _test_eof; 
	_test_eof29: cs = 29; goto _test_eof; 
	_test_eof30: cs = 30; goto _test_eof; 
	_test_eof31: cs = 31; goto _test_eof; 
	_test_eof32: cs = 32; goto _test_eof; 
	_test_eof33: cs = 33; goto _test_eof; 
	_test_eof34: cs = 34; goto _test_eof; 
	_test_eof35: cs = 35; goto _test_eof; 
	_test_eof36: cs = 36; goto _test_eof; 
	_test_eof37: cs = 37; goto _test_eof; 
	_test_eof38: cs = 38; goto _test_eof; 
	_test_eof39: cs = 39; goto _test_eof; 
	_test_eof40: cs = 40; goto _test_eof; 
	_test_eof41: cs = 41; goto _test_eof; 
	_test_eof42: cs = 42; goto _test_eof; 
	_test_eof43: cs = 43; goto _test_eof; 
	_test_eof44: cs = 44; goto _test_eof; 
	_test_eof45: cs = 45; goto _test_eof; 
	_test_eof46: cs = 46; goto _test_eof; 
	_test_eof47: cs = 47; goto _test_eof; 
	_test_eof48: cs = 48; goto _test_eof; 
	_test_eof49: cs = 49; goto _test_eof; 
	_test_eof50: cs = 50; goto _test_eof; 
	_test_eof51: cs = 51; goto _test_eof; 
	_test_eof52: cs = 52; goto _test_eof; 
	_test_eof53: cs = 53; goto _test_eof; 
	_test_eof54: cs = 54; goto _test_eof; 
	_test_eof55: cs = 55; goto _test_eof; 
	_test_eof56: cs = 56; goto _test_eof; 
	_test_eof57: cs = 57; goto _test_eof; 
	_test_eof58: cs = 58; goto _test_eof; 
	_test_eof59: cs = 59; goto _test_eof; 
	_test_eof60: cs = 60; goto _test_eof; 
	_test_eof61: cs = 61; goto _test_eof; 
	_test_eof62: cs = 62; goto _test_eof; 
	_test_eof63: cs = 63; goto _test_eof; 
	_test_eof64: cs = 64; goto _test_eof; 
	_test_eof65: cs = 65; goto _test_eof; 
	_test_eof66: cs = 66; goto _test_eof; 
	_test_eof67: cs = 67; goto _test_eof; 
	_test_eof68: cs = 68; goto _test_eof; 
	_test_eof69: cs = 69; goto _test_eof; 
	_test_eof70: cs = 70; goto _test_eof; 
	_test_eof71: cs = 71; goto _test_eof; 
	_test_eof72: cs = 72; goto _test_eof; 
	_test_eof73: cs = 73; goto _test_eof; 
	_test_eof74: cs = 74; goto _test_eof; 
	_test_eof75: cs = 75; goto _test_eof; 
	_test_eof76: cs = 76; goto _test_eof; 
	_test_eof77: cs = 77; goto _test_eof; 
	_test_eof78: cs = 78; goto _test_eof; 
	_test_eof79: cs = 79; goto _test_eof; 
	_test_eof80: cs = 80; goto _test_eof; 
	_test_eof81: cs = 81; goto _test_eof; 
	_test_eof82: cs = 82; goto _test_eof; 
	_test_eof83: cs = 83; goto _test_eof; 
	_test_eof84: cs = 84; goto _test_eof; 
	_test_eof85: cs = 85; goto _test_eof; 
	_test_eof86: cs = 86; goto _test_eof; 
	_test_eof87: cs = 87; goto _test_eof; 
	_test_eof88: cs = 88; goto _test_eof; 
	_test_eof89: cs = 89; goto _test_eof; 
	_test_eof90: cs = 90; goto _test_eof; 
	_test_eof91: cs = 91; goto _test_eof; 
	_test_eof92: cs = 92; goto _test_eof; 
	_test_eof93: cs = 93; goto _test_eof; 
	_test_eof94: cs = 94; goto _test_eof; 
	_test_eof95: cs = 95; goto _test_eof; 
	_test_eof96: cs = 96; goto _test_eof; 
	_test_eof97: cs = 97; goto _test_eof; 
	_test_eof98: cs = 98; goto _test_eof; 
	_test_eof99: cs = 99; goto _test_eof; 
	_test_eof100: cs = 100; goto _test_eof; 
	_test_eof101: cs = 101; goto _test_eof; 
	_test_eof102: cs = 102; goto _test_eof; 
	_test_eof103: cs = 103; goto _test_eof; 
	_test_eof104: cs = 104; goto _test_eof; 
	_test_eof105: cs = 105; goto _test_eof; 
	_test_eof106: cs = 106; goto _test_eof; 
	_test_eof107: cs = 107; goto _test_eof; 
	_test_eof108: cs = 108; goto _test_eof; 
	_test_eof109: cs = 109; goto _test_eof; 
	_test_eof110: cs = 110; goto _test_eof; 
	_test_eof111: cs = 111; goto _test_eof; 
	_test_eof112: cs = 112; goto _test_eof; 
	_test_eof113: cs = 113; goto _test_eof; 
	_test_eof114: cs = 114; goto _test_eof; 
	_test_eof115: cs = 115; goto _test_eof; 
	_test_eof116: cs = 116; goto _test_eof; 
	_test_eof117: cs = 117; goto _test_eof; 
	_test_eof118: cs = 118; goto _test_eof; 
	_test_eof119: cs = 119; goto _test_eof; 
	_test_eof120: cs = 120; goto _test_eof; 
	_test_eof121: cs = 121; goto _test_eof; 
	_test_eof122: cs = 122; goto _test_eof; 
	_test_eof123: cs = 123; goto _test_eof; 
	_test_eof124: cs = 124; goto _test_eof; 
	_test_eof125: cs = 125; goto _test_eof; 
	_test_eof126: cs = 126; goto _test_eof; 
	_test_eof127: cs = 127; goto _test_eof; 
	_test_eof128: cs = 128; goto _test_eof; 
	_test_eof129: cs = 129; goto _test_eof; 
	_test_eof130: cs = 130; goto _test_eof; 
	_test_eof131: cs = 131; goto _test_eof; 
	_test_eof132: cs = 132; goto _test_eof; 
	_test_eof133: cs = 133; goto _test_eof; 
	_test_eof134: cs = 134; goto _test_eof; 
	_test_eof135: cs = 135; goto _test_eof; 
	_test_eof136: cs = 136; goto _test_eof; 
	_test_eof137: cs = 137; goto _test_eof; 
	_test_eof138: cs = 138; goto _test_eof; 
	_test_eof139: cs = 139; goto _test_eof; 
	_test_eof140: cs = 140; goto _test_eof; 
	_test_eof141: cs = 141; goto _test_eof; 
	_test_eof142: cs = 142; goto _test_eof; 
	_test_eof143: cs = 143; goto _test_eof; 
	_test_eof144: cs = 144; goto _test_eof; 
	_test_eof145: cs = 145; goto _test_eof; 
	_test_eof146: cs = 146; goto _test_eof; 
	_test_eof147: cs = 147; goto _test_eof; 
	_test_eof148: cs = 148; goto _test_eof; 
	_test_eof149: cs = 149; goto _test_eof; 
	_test_eof150: cs = 150; goto _test_eof; 
	_test_eof151: cs = 151; goto _test_eof; 
	_test_eof152: cs = 152; goto _test_eof; 
	_test_eof153: cs = 153; goto _test_eof; 
	_test_eof154: cs = 154; goto _test_eof; 
	_test_eof155: cs = 155; goto _test_eof; 
	_test_eof156: cs = 156; goto _test_eof; 
	_test_eof157: cs = 157; goto _test_eof; 
	_test_eof158: cs = 158; goto _test_eof; 
	_test_eof159: cs = 159; goto _test_eof; 
	_test_eof160: cs = 160; goto _test_eof; 
	_test_eof161: cs = 161; goto _test_eof; 
	_test_eof162: cs = 162; goto _test_eof; 
	_test_eof163: cs = 163; goto _test_eof; 
	_test_eof164: cs = 164; goto _test_eof; 
	_test_eof165: cs = 165; goto _test_eof; 
	_test_eof166: cs = 166; goto _test_eof; 
	_test_eof167: cs = 167; goto _test_eof; 
	_test_eof168: cs = 168; goto _test_eof; 
	_test_eof169: cs = 169; goto _test_eof; 
	_test_eof170: cs = 170; goto _test_eof; 
	_test_eof171: cs = 171; goto _test_eof; 
	_test_eof172: cs = 172; goto _test_eof; 
	_test_eof173: cs = 173; goto _test_eof; 
	_test_eof174: cs = 174; goto _test_eof; 
	_test_eof175: cs = 175; goto _test_eof; 
	_test_eof176: cs = 176; goto _test_eof; 
	_test_eof177: cs = 177; goto _test_eof; 
	_test_eof178: cs = 178; goto _test_eof; 
	_test_eof179: cs = 179; goto _test_eof; 
	_test_eof180: cs = 180; goto _test_eof; 
	_test_eof181: cs = 181; goto _test_eof; 
	_test_eof182: cs = 182; goto _test_eof; 
	_test_eof183: cs = 183; goto _test_eof; 
	_test_eof184: cs = 184; goto _test_eof; 
	_test_eof185: cs = 185; goto _test_eof; 
	_test_eof186: cs = 186; goto _test_eof; 
	_test_eof187: cs = 187; goto _test_eof; 
	_test_eof188: cs = 188; goto _test_eof; 
	_test_eof189: cs = 189; goto _test_eof; 
	_test_eof190: cs = 190; goto _test_eof; 
	_test_eof191: cs = 191; goto _test_eof; 
	_test_eof192: cs = 192; goto _test_eof; 
	_test_eof193: cs = 193; goto _test_eof; 
	_test_eof194: cs = 194; goto _test_eof; 
	_test_eof195: cs = 195; goto _test_eof; 
	_test_eof196: cs = 196; goto _test_eof; 
	_test_eof197: cs = 197; goto _test_eof; 
	_test_eof198: cs = 198; goto _test_eof; 
	_test_eof199: cs = 199; goto _test_eof; 
	_test_eof200: cs = 200; goto _test_eof; 
	_test_eof201: cs = 201; goto _test_eof; 
	_test_eof202: cs = 202; goto _test_eof; 
	_test_eof203: cs = 203; goto _test_eof; 
	_test_eof204: cs = 204; goto _test_eof; 
	_test_eof205: cs = 205; goto _test_eof; 
	_test_eof206: cs = 206; goto _test_eof; 
	_test_eof207: cs = 207; goto _test_eof; 
	_test_eof208: cs = 208; goto _test_eof; 
	_test_eof209: cs = 209; goto _test_eof; 
	_test_eof210: cs = 210; goto _test_eof; 
	_test_eof211: cs = 211; goto _test_eof; 
	_test_eof212: cs = 212; goto _test_eof; 
	_test_eof213: cs = 213; goto _test_eof; 
	_test_eof214: cs = 214; goto _test_eof; 
	_test_eof215: cs = 215; goto _test_eof; 
	_test_eof216: cs = 216; goto _test_eof; 
	_test_eof217: cs = 217; goto _test_eof; 
	_test_eof218: cs = 218; goto _test_eof; 
	_test_eof219: cs = 219; goto _test_eof; 
	_test_eof220: cs = 220; goto _test_eof; 
	_test_eof221: cs = 221; goto _test_eof; 
	_test_eof222: cs = 222; goto _test_eof; 
	_test_eof223: cs = 223; goto _test_eof; 
	_test_eof224: cs = 224; goto _test_eof; 
	_test_eof225: cs = 225; goto _test_eof; 
	_test_eof226: cs = 226; goto _test_eof; 
	_test_eof227: cs = 227; goto _test_eof; 
	_test_eof228: cs = 228; goto _test_eof; 
	_test_eof229: cs = 229; goto _test_eof; 
	_test_eof230: cs = 230; goto _test_eof; 
	_test_eof231: cs = 231; goto _test_eof; 
	_test_eof232: cs = 232; goto _test_eof; 
	_test_eof233: cs = 233; goto _test_eof; 
	_test_eof234: cs = 234; goto _test_eof; 
	_test_eof235: cs = 235; goto _test_eof; 
	_test_eof236: cs = 236; goto _test_eof; 
	_test_eof237: cs = 237; goto _test_eof; 
	_test_eof238: cs = 238; goto _test_eof; 
	_test_eof239: cs = 239; goto _test_eof; 
	_test_eof240: cs = 240; goto _test_eof; 
	_test_eof241: cs = 241; goto _test_eof; 
	_test_eof242: cs = 242; goto _test_eof; 
	_test_eof243: cs = 243; goto _test_eof; 
	_test_eof244: cs = 244; goto _test_eof; 
	_test_eof245: cs = 245; goto _test_eof; 
	_test_eof246: cs = 246; goto _test_eof; 
	_test_eof247: cs = 247; goto _test_eof; 
	_test_eof248: cs = 248; goto _test_eof; 
	_test_eof249: cs = 249; goto _test_eof; 
	_test_eof250: cs = 250; goto _test_eof; 
	_test_eof251: cs = 251; goto _test_eof; 
	_test_eof252: cs = 252; goto _test_eof; 
	_test_eof253: cs = 253; goto _test_eof; 
	_test_eof254: cs = 254; goto _test_eof; 
	_test_eof255: cs = 255; goto _test_eof; 
	_test_eof256: cs = 256; goto _test_eof; 
	_test_eof257: cs = 257; goto _test_eof; 
	_test_eof258: cs = 258; goto _test_eof; 
	_test_eof259: cs = 259; goto _test_eof; 
	_test_eof260: cs = 260; goto _test_eof; 
	_test_eof261: cs = 261; goto _test_eof; 
	_test_eof262: cs = 262; goto _test_eof; 
	_test_eof263: cs = 263; goto _test_eof; 
	_test_eof264: cs = 264; goto _test_eof; 
	_test_eof265: cs = 265; goto _test_eof; 
	_test_eof266: cs = 266; goto _test_eof; 
	_test_eof267: cs = 267; goto _test_eof; 
	_test_eof268: cs = 268; goto _test_eof; 
	_test_eof269: cs = 269; goto _test_eof; 
	_test_eof270: cs = 270; goto _test_eof; 
	_test_eof271: cs = 271; goto _test_eof; 
	_test_eof272: cs = 272; goto _test_eof; 
	_test_eof273: cs = 273; goto _test_eof; 
	_test_eof274: cs = 274; goto _test_eof; 
	_test_eof275: cs = 275; goto _test_eof; 
	_test_eof276: cs = 276; goto _test_eof; 
	_test_eof277: cs = 277; goto _test_eof; 
	_test_eof278: cs = 278; goto _test_eof; 
	_test_eof279: cs = 279; goto _test_eof; 
	_test_eof280: cs = 280; goto _test_eof; 
	_test_eof281: cs = 281; goto _test_eof; 
	_test_eof282: cs = 282; goto _test_eof; 
	_test_eof283: cs = 283; goto _test_eof; 
	_test_eof284: cs = 284; goto _test_eof; 
	_test_eof285: cs = 285; goto _test_eof; 
	_test_eof286: cs = 286; goto _test_eof; 
	_test_eof287: cs = 287; goto _test_eof; 
	_test_eof288: cs = 288; goto _test_eof; 
	_test_eof289: cs = 289; goto _test_eof; 
	_test_eof290: cs = 290; goto _test_eof; 
	_test_eof291: cs = 291; goto _test_eof; 
	_test_eof292: cs = 292; goto _test_eof; 
	_test_eof293: cs = 293; goto _test_eof; 
	_test_eof294: cs = 294; goto _test_eof; 
	_test_eof295: cs = 295; goto _test_eof; 
	_test_eof296: cs = 296; goto _test_eof; 
	_test_eof297: cs = 297; goto _test_eof; 
	_test_eof298: cs = 298; goto _test_eof; 
	_test_eof299: cs = 299; goto _test_eof; 
	_test_eof300: cs = 300; goto _test_eof; 
	_test_eof301: cs = 301; goto _test_eof; 
	_test_eof302: cs = 302; goto _test_eof; 
	_test_eof303: cs = 303; goto _test_eof; 
	_test_eof304: cs = 304; goto _test_eof; 
	_test_eof305: cs = 305; goto _test_eof; 
	_test_eof306: cs = 306; goto _test_eof; 
	_test_eof307: cs = 307; goto _test_eof; 
	_test_eof308: cs = 308; goto _test_eof; 
	_test_eof309: cs = 309; goto _test_eof; 
	_test_eof310: cs = 310; goto _test_eof; 
	_test_eof311: cs = 311; goto _test_eof; 
	_test_eof312: cs = 312; goto _test_eof; 
	_test_eof313: cs = 313; goto _test_eof; 
	_test_eof314: cs = 314; goto _test_eof; 
	_test_eof315: cs = 315; goto _test_eof; 
	_test_eof316: cs = 316; goto _test_eof; 
	_test_eof317: cs = 317; goto _test_eof; 
	_test_eof318: cs = 318; goto _test_eof; 
	_test_eof319: cs = 319; goto _test_eof; 
	_test_eof320: cs = 320; goto _test_eof; 
	_test_eof321: cs = 321; goto _test_eof; 
	_test_eof322: cs = 322; goto _test_eof; 
	_test_eof323: cs = 323; goto _test_eof; 
	_test_eof324: cs = 324; goto _test_eof; 
	_test_eof325: cs = 325; goto _test_eof; 
	_test_eof326: cs = 326; goto _test_eof; 
	_test_eof327: cs = 327; goto _test_eof; 
	_test_eof328: cs = 328; goto _test_eof; 
	_test_eof329: cs = 329; goto _test_eof; 
	_test_eof330: cs = 330; goto _test_eof; 
	_test_eof331: cs = 331; goto _test_eof; 
	_test_eof332: cs = 332; goto _test_eof; 
	_test_eof333: cs = 333; goto _test_eof; 
	_test_eof334: cs = 334; goto _test_eof; 
	_test_eof335: cs = 335; goto _test_eof; 
	_test_eof336: cs = 336; goto _test_eof; 
	_test_eof337: cs = 337; goto _test_eof; 
	_test_eof338: cs = 338; goto _test_eof; 
	_test_eof339: cs = 339; goto _test_eof; 
	_test_eof340: cs = 340; goto _test_eof; 
	_test_eof341: cs = 341; goto _test_eof; 
	_test_eof342: cs = 342; goto _test_eof; 
	_test_eof343: cs = 343; goto _test_eof; 
	_test_eof344: cs = 344; goto _test_eof; 
	_test_eof345: cs = 345; goto _test_eof; 
	_test_eof346: cs = 346; goto _test_eof; 
	_test_eof347: cs = 347; goto _test_eof; 
	_test_eof348: cs = 348; goto _test_eof; 
	_test_eof349: cs = 349; goto _test_eof; 
	_test_eof350: cs = 350; goto _test_eof; 
	_test_eof351: cs = 351; goto _test_eof; 
	_test_eof352: cs = 352; goto _test_eof; 
	_test_eof353: cs = 353; goto _test_eof; 
	_test_eof354: cs = 354; goto _test_eof; 
	_test_eof355: cs = 355; goto _test_eof; 
	_test_eof356: cs = 356; goto _test_eof; 
	_test_eof357: cs = 357; goto _test_eof; 
	_test_eof358: cs = 358; goto _test_eof; 
	_test_eof359: cs = 359; goto _test_eof; 
	_test_eof360: cs = 360; goto _test_eof; 
	_test_eof361: cs = 361; goto _test_eof; 
	_test_eof362: cs = 362; goto _test_eof; 
	_test_eof363: cs = 363; goto _test_eof; 
	_test_eof364: cs = 364; goto _test_eof; 
	_test_eof365: cs = 365; goto _test_eof; 
	_test_eof366: cs = 366; goto _test_eof; 
	_test_eof367: cs = 367; goto _test_eof; 
	_test_eof368: cs = 368; goto _test_eof; 
	_test_eof369: cs = 369; goto _test_eof; 
	_test_eof370: cs = 370; goto _test_eof; 
	_test_eof371: cs = 371; goto _test_eof; 
	_test_eof372: cs = 372; goto _test_eof; 
	_test_eof373: cs = 373; goto _test_eof; 
	_test_eof374: cs = 374; goto _test_eof; 
	_test_eof375: cs = 375; goto _test_eof; 
	_test_eof376: cs = 376; goto _test_eof; 
	_test_eof377: cs = 377; goto _test_eof; 
	_test_eof378: cs = 378; goto _test_eof; 
	_test_eof379: cs = 379; goto _test_eof; 
	_test_eof380: cs = 380; goto _test_eof; 
	_test_eof381: cs = 381; goto _test_eof; 
	_test_eof382: cs = 382; goto _test_eof; 
	_test_eof383: cs = 383; goto _test_eof; 
	_test_eof384: cs = 384; goto _test_eof; 
	_test_eof385: cs = 385; goto _test_eof; 
	_test_eof386: cs = 386; goto _test_eof; 
	_test_eof387: cs = 387; goto _test_eof; 
	_test_eof388: cs = 388; goto _test_eof; 
	_test_eof389: cs = 389; goto _test_eof; 
	_test_eof390: cs = 390; goto _test_eof; 
	_test_eof391: cs = 391; goto _test_eof; 
	_test_eof392: cs = 392; goto _test_eof; 
	_test_eof393: cs = 393; goto _test_eof; 
	_test_eof394: cs = 394; goto _test_eof; 
	_test_eof395: cs = 395; goto _test_eof; 
	_test_eof396: cs = 396; goto _test_eof; 
	_test_eof397: cs = 397; goto _test_eof; 
	_test_eof398: cs = 398; goto _test_eof; 
	_test_eof399: cs = 399; goto _test_eof; 
	_test_eof400: cs = 400; goto _test_eof; 
	_test_eof401: cs = 401; goto _test_eof; 
	_test_eof402: cs = 402; goto _test_eof; 
	_test_eof403: cs = 403; goto _test_eof; 
	_test_eof404: cs = 404; goto _test_eof; 
	_test_eof405: cs = 405; goto _test_eof; 
	_test_eof406: cs = 406; goto _test_eof; 
	_test_eof407: cs = 407; goto _test_eof; 
	_test_eof408: cs = 408; goto _test_eof; 
	_test_eof409: cs = 409; goto _test_eof; 
	_test_eof410: cs = 410; goto _test_eof; 
	_test_eof411: cs = 411; goto _test_eof; 
	_test_eof412: cs = 412; goto _test_eof; 
	_test_eof413: cs = 413; goto _test_eof; 
	_test_eof414: cs = 414; goto _test_eof; 
	_test_eof415: cs = 415; goto _test_eof; 
	_test_eof416: cs = 416; goto _test_eof; 
	_test_eof417: cs = 417; goto _test_eof; 
	_test_eof418: cs = 418; goto _test_eof; 
	_test_eof419: cs = 419; goto _test_eof; 
	_test_eof420: cs = 420; goto _test_eof; 
	_test_eof421: cs = 421; goto _test_eof; 
	_test_eof422: cs = 422; goto _test_eof; 
	_test_eof423: cs = 423; goto _test_eof; 
	_test_eof424: cs = 424; goto _test_eof; 
	_test_eof425: cs = 425; goto _test_eof; 
	_test_eof426: cs = 426; goto _test_eof; 
	_test_eof427: cs = 427; goto _test_eof; 
	_test_eof428: cs = 428; goto _test_eof; 
	_test_eof429: cs = 429; goto _test_eof; 
	_test_eof430: cs = 430; goto _test_eof; 
	_test_eof431: cs = 431; goto _test_eof; 
	_test_eof432: cs = 432; goto _test_eof; 
	_test_eof433: cs = 433; goto _test_eof; 
	_test_eof434: cs = 434; goto _test_eof; 
	_test_eof435: cs = 435; goto _test_eof; 
	_test_eof436: cs = 436; goto _test_eof; 
	_test_eof437: cs = 437; goto _test_eof; 
	_test_eof438: cs = 438; goto _test_eof; 
	_test_eof439: cs = 439; goto _test_eof; 
	_test_eof440: cs = 440; goto _test_eof; 
	_test_eof441: cs = 441; goto _test_eof; 
	_test_eof442: cs = 442; goto _test_eof; 
	_test_eof443: cs = 443; goto _test_eof; 
	_test_eof444: cs = 444; goto _test_eof; 
	_test_eof445: cs = 445; goto _test_eof; 
	_test_eof446: cs = 446; goto _test_eof; 
	_test_eof447: cs = 447; goto _test_eof; 
	_test_eof448: cs = 448; goto _test_eof; 
	_test_eof449: cs = 449; goto _test_eof; 
	_test_eof450: cs = 450; goto _test_eof; 
	_test_eof451: cs = 451; goto _test_eof; 
	_test_eof452: cs = 452; goto _test_eof; 
	_test_eof453: cs = 453; goto _test_eof; 
	_test_eof454: cs = 454; goto _test_eof; 
	_test_eof455: cs = 455; goto _test_eof; 
	_test_eof456: cs = 456; goto _test_eof; 
	_test_eof457: cs = 457; goto _test_eof; 
	_test_eof458: cs = 458; goto _test_eof; 
	_test_eof459: cs = 459; goto _test_eof; 
	_test_eof460: cs = 460; goto _test_eof; 
	_test_eof461: cs = 461; goto _test_eof; 
	_test_eof462: cs = 462; goto _test_eof; 
	_test_eof463: cs = 463; goto _test_eof; 
	_test_eof464: cs = 464; goto _test_eof; 
	_test_eof465: cs = 465; goto _test_eof; 
	_test_eof466: cs = 466; goto _test_eof; 
	_test_eof467: cs = 467; goto _test_eof; 
	_test_eof468: cs = 468; goto _test_eof; 
	_test_eof469: cs = 469; goto _test_eof; 
	_test_eof470: cs = 470; goto _test_eof; 
	_test_eof471: cs = 471; goto _test_eof; 
	_test_eof472: cs = 472; goto _test_eof; 
	_test_eof473: cs = 473; goto _test_eof; 
	_test_eof474: cs = 474; goto _test_eof; 
	_test_eof475: cs = 475; goto _test_eof; 
	_test_eof476: cs = 476; goto _test_eof; 
	_test_eof477: cs = 477; goto _test_eof; 
	_test_eof478: cs = 478; goto _test_eof; 
	_test_eof479: cs = 479; goto _test_eof; 
	_test_eof480: cs = 480; goto _test_eof; 
	_test_eof481: cs = 481; goto _test_eof; 
	_test_eof482: cs = 482; goto _test_eof; 
	_test_eof483: cs = 483; goto _test_eof; 
	_test_eof484: cs = 484; goto _test_eof; 
	_test_eof485: cs = 485; goto _test_eof; 
	_test_eof486: cs = 486; goto _test_eof; 
	_test_eof730: cs = 730; goto _test_eof; 
	_test_eof487: cs = 487; goto _test_eof; 
	_test_eof488: cs = 488; goto _test_eof; 
	_test_eof489: cs = 489; goto _test_eof; 
	_test_eof490: cs = 490; goto _test_eof; 
	_test_eof491: cs = 491; goto _test_eof; 
	_test_eof492: cs = 492; goto _test_eof; 
	_test_eof493: cs = 493; goto _test_eof; 
	_test_eof494: cs = 494; goto _test_eof; 
	_test_eof495: cs = 495; goto _test_eof; 
	_test_eof496: cs = 496; goto _test_eof; 
	_test_eof497: cs = 497; goto _test_eof; 
	_test_eof498: cs = 498; goto _test_eof; 
	_test_eof499: cs = 499; goto _test_eof; 
	_test_eof500: cs = 500; goto _test_eof; 
	_test_eof501: cs = 501; goto _test_eof; 
	_test_eof502: cs = 502; goto _test_eof; 
	_test_eof503: cs = 503; goto _test_eof; 
	_test_eof504: cs = 504; goto _test_eof; 
	_test_eof505: cs = 505; goto _test_eof; 
	_test_eof506: cs = 506; goto _test_eof; 
	_test_eof507: cs = 507; goto _test_eof; 
	_test_eof508: cs = 508; goto _test_eof; 
	_test_eof509: cs = 509; goto _test_eof; 
	_test_eof510: cs = 510; goto _test_eof; 
	_test_eof731: cs = 731; goto _test_eof; 
	_test_eof511: cs = 511; goto _test_eof; 
	_test_eof512: cs = 512; goto _test_eof; 
	_test_eof513: cs = 513; goto _test_eof; 
	_test_eof514: cs = 514; goto _test_eof; 
	_test_eof515: cs = 515; goto _test_eof; 
	_test_eof516: cs = 516; goto _test_eof; 
	_test_eof517: cs = 517; goto _test_eof; 
	_test_eof518: cs = 518; goto _test_eof; 
	_test_eof519: cs = 519; goto _test_eof; 
	_test_eof520: cs = 520; goto _test_eof; 
	_test_eof521: cs = 521; goto _test_eof; 
	_test_eof522: cs = 522; goto _test_eof; 
	_test_eof523: cs = 523; goto _test_eof; 
	_test_eof524: cs = 524; goto _test_eof; 
	_test_eof525: cs = 525; goto _test_eof; 
	_test_eof526: cs = 526; goto _test_eof; 
	_test_eof527: cs = 527; goto _test_eof; 
	_test_eof528: cs = 528; goto _test_eof; 
	_test_eof529: cs = 529; goto _test_eof; 
	_test_eof530: cs = 530; goto _test_eof; 
	_test_eof531: cs = 531; goto _test_eof; 
	_test_eof532: cs = 532; goto _test_eof; 
	_test_eof533: cs = 533; goto _test_eof; 
	_test_eof534: cs = 534; goto _test_eof; 
	_test_eof535: cs = 535; goto _test_eof; 
	_test_eof536: cs = 536; goto _test_eof; 
	_test_eof537: cs = 537; goto _test_eof; 
	_test_eof538: cs = 538; goto _test_eof; 
	_test_eof539: cs = 539; goto _test_eof; 
	_test_eof540: cs = 540; goto _test_eof; 
	_test_eof541: cs = 541; goto _test_eof; 
	_test_eof542: cs = 542; goto _test_eof; 
	_test_eof543: cs = 543; goto _test_eof; 
	_test_eof544: cs = 544; goto _test_eof; 
	_test_eof545: cs = 545; goto _test_eof; 
	_test_eof546: cs = 546; goto _test_eof; 
	_test_eof547: cs = 547; goto _test_eof; 
	_test_eof548: cs = 548; goto _test_eof; 
	_test_eof549: cs = 549; goto _test_eof; 
	_test_eof550: cs = 550; goto _test_eof; 
	_test_eof551: cs = 551; goto _test_eof; 
	_test_eof552: cs = 552; goto _test_eof; 
	_test_eof553: cs = 553; goto _test_eof; 
	_test_eof554: cs = 554; goto _test_eof; 
	_test_eof555: cs = 555; goto _test_eof; 
	_test_eof556: cs = 556; goto _test_eof; 
	_test_eof557: cs = 557; goto _test_eof; 
	_test_eof558: cs = 558; goto _test_eof; 
	_test_eof559: cs = 559; goto _test_eof; 
	_test_eof560: cs = 560; goto _test_eof; 
	_test_eof561: cs = 561; goto _test_eof; 
	_test_eof562: cs = 562; goto _test_eof; 
	_test_eof563: cs = 563; goto _test_eof; 
	_test_eof564: cs = 564; goto _test_eof; 
	_test_eof565: cs = 565; goto _test_eof; 
	_test_eof566: cs = 566; goto _test_eof; 
	_test_eof567: cs = 567; goto _test_eof; 
	_test_eof568: cs = 568; goto _test_eof; 
	_test_eof569: cs = 569; goto _test_eof; 
	_test_eof570: cs = 570; goto _test_eof; 
	_test_eof571: cs = 571; goto _test_eof; 
	_test_eof572: cs = 572; goto _test_eof; 
	_test_eof573: cs = 573; goto _test_eof; 
	_test_eof574: cs = 574; goto _test_eof; 
	_test_eof575: cs = 575; goto _test_eof; 
	_test_eof576: cs = 576; goto _test_eof; 
	_test_eof577: cs = 577; goto _test_eof; 
	_test_eof578: cs = 578; goto _test_eof; 
	_test_eof579: cs = 579; goto _test_eof; 
	_test_eof580: cs = 580; goto _test_eof; 
	_test_eof581: cs = 581; goto _test_eof; 
	_test_eof582: cs = 582; goto _test_eof; 
	_test_eof583: cs = 583; goto _test_eof; 
	_test_eof584: cs = 584; goto _test_eof; 
	_test_eof585: cs = 585; goto _test_eof; 
	_test_eof586: cs = 586; goto _test_eof; 
	_test_eof587: cs = 587; goto _test_eof; 
	_test_eof588: cs = 588; goto _test_eof; 
	_test_eof589: cs = 589; goto _test_eof; 
	_test_eof590: cs = 590; goto _test_eof; 
	_test_eof591: cs = 591; goto _test_eof; 
	_test_eof592: cs = 592; goto _test_eof; 
	_test_eof593: cs = 593; goto _test_eof; 
	_test_eof594: cs = 594; goto _test_eof; 
	_test_eof595: cs = 595; goto _test_eof; 
	_test_eof596: cs = 596; goto _test_eof; 
	_test_eof597: cs = 597; goto _test_eof; 
	_test_eof598: cs = 598; goto _test_eof; 
	_test_eof599: cs = 599; goto _test_eof; 
	_test_eof600: cs = 600; goto _test_eof; 
	_test_eof601: cs = 601; goto _test_eof; 
	_test_eof602: cs = 602; goto _test_eof; 
	_test_eof603: cs = 603; goto _test_eof; 
	_test_eof604: cs = 604; goto _test_eof; 
	_test_eof605: cs = 605; goto _test_eof; 
	_test_eof606: cs = 606; goto _test_eof; 
	_test_eof607: cs = 607; goto _test_eof; 
	_test_eof608: cs = 608; goto _test_eof; 
	_test_eof609: cs = 609; goto _test_eof; 
	_test_eof610: cs = 610; goto _test_eof; 
	_test_eof611: cs = 611; goto _test_eof; 
	_test_eof612: cs = 612; goto _test_eof; 
	_test_eof613: cs = 613; goto _test_eof; 
	_test_eof614: cs = 614; goto _test_eof; 
	_test_eof615: cs = 615; goto _test_eof; 
	_test_eof616: cs = 616; goto _test_eof; 
	_test_eof617: cs = 617; goto _test_eof; 
	_test_eof618: cs = 618; goto _test_eof; 
	_test_eof619: cs = 619; goto _test_eof; 
	_test_eof620: cs = 620; goto _test_eof; 
	_test_eof621: cs = 621; goto _test_eof; 
	_test_eof622: cs = 622; goto _test_eof; 
	_test_eof623: cs = 623; goto _test_eof; 
	_test_eof624: cs = 624; goto _test_eof; 
	_test_eof625: cs = 625; goto _test_eof; 
	_test_eof626: cs = 626; goto _test_eof; 
	_test_eof627: cs = 627; goto _test_eof; 
	_test_eof628: cs = 628; goto _test_eof; 
	_test_eof629: cs = 629; goto _test_eof; 
	_test_eof630: cs = 630; goto _test_eof; 
	_test_eof631: cs = 631; goto _test_eof; 
	_test_eof632: cs = 632; goto _test_eof; 
	_test_eof633: cs = 633; goto _test_eof; 
	_test_eof634: cs = 634; goto _test_eof; 
	_test_eof635: cs = 635; goto _test_eof; 
	_test_eof636: cs = 636; goto _test_eof; 
	_test_eof637: cs = 637; goto _test_eof; 
	_test_eof638: cs = 638; goto _test_eof; 
	_test_eof639: cs = 639; goto _test_eof; 
	_test_eof640: cs = 640; goto _test_eof; 
	_test_eof641: cs = 641; goto _test_eof; 
	_test_eof642: cs = 642; goto _test_eof; 
	_test_eof643: cs = 643; goto _test_eof; 
	_test_eof644: cs = 644; goto _test_eof; 
	_test_eof645: cs = 645; goto _test_eof; 
	_test_eof646: cs = 646; goto _test_eof; 
	_test_eof647: cs = 647; goto _test_eof; 
	_test_eof648: cs = 648; goto _test_eof; 
	_test_eof649: cs = 649; goto _test_eof; 
	_test_eof650: cs = 650; goto _test_eof; 
	_test_eof651: cs = 651; goto _test_eof; 
	_test_eof652: cs = 652; goto _test_eof; 
	_test_eof653: cs = 653; goto _test_eof; 
	_test_eof654: cs = 654; goto _test_eof; 
	_test_eof655: cs = 655; goto _test_eof; 
	_test_eof656: cs = 656; goto _test_eof; 
	_test_eof657: cs = 657; goto _test_eof; 
	_test_eof658: cs = 658; goto _test_eof; 
	_test_eof659: cs = 659; goto _test_eof; 
	_test_eof660: cs = 660; goto _test_eof; 
	_test_eof661: cs = 661; goto _test_eof; 
	_test_eof662: cs = 662; goto _test_eof; 
	_test_eof663: cs = 663; goto _test_eof; 
	_test_eof664: cs = 664; goto _test_eof; 
	_test_eof665: cs = 665; goto _test_eof; 
	_test_eof666: cs = 666; goto _test_eof; 
	_test_eof667: cs = 667; goto _test_eof; 
	_test_eof668: cs = 668; goto _test_eof; 
	_test_eof669: cs = 669; goto _test_eof; 
	_test_eof670: cs = 670; goto _test_eof; 
	_test_eof671: cs = 671; goto _test_eof; 
	_test_eof672: cs = 672; goto _test_eof; 
	_test_eof673: cs = 673; goto _test_eof; 
	_test_eof674: cs = 674; goto _test_eof; 
	_test_eof675: cs = 675; goto _test_eof; 
	_test_eof676: cs = 676; goto _test_eof; 
	_test_eof677: cs = 677; goto _test_eof; 
	_test_eof678: cs = 678; goto _test_eof; 
	_test_eof679: cs = 679; goto _test_eof; 
	_test_eof680: cs = 680; goto _test_eof; 
	_test_eof681: cs = 681; goto _test_eof; 
	_test_eof682: cs = 682; goto _test_eof; 
	_test_eof683: cs = 683; goto _test_eof; 
	_test_eof684: cs = 684; goto _test_eof; 
	_test_eof685: cs = 685; goto _test_eof; 
	_test_eof686: cs = 686; goto _test_eof; 
	_test_eof687: cs = 687; goto _test_eof; 
	_test_eof688: cs = 688; goto _test_eof; 
	_test_eof689: cs = 689; goto _test_eof; 
	_test_eof690: cs = 690; goto _test_eof; 
	_test_eof691: cs = 691; goto _test_eof; 
	_test_eof692: cs = 692; goto _test_eof; 
	_test_eof693: cs = 693; goto _test_eof; 
	_test_eof694: cs = 694; goto _test_eof; 
	_test_eof695: cs = 695; goto _test_eof; 
	_test_eof696: cs = 696; goto _test_eof; 
	_test_eof697: cs = 697; goto _test_eof; 
	_test_eof698: cs = 698; goto _test_eof; 
	_test_eof699: cs = 699; goto _test_eof; 
	_test_eof700: cs = 700; goto _test_eof; 
	_test_eof701: cs = 701; goto _test_eof; 
	_test_eof702: cs = 702; goto _test_eof; 
	_test_eof703: cs = 703; goto _test_eof; 
	_test_eof704: cs = 704; goto _test_eof; 
	_test_eof705: cs = 705; goto _test_eof; 
	_test_eof706: cs = 706; goto _test_eof; 
	_test_eof707: cs = 707; goto _test_eof; 
	_test_eof708: cs = 708; goto _test_eof; 
	_test_eof709: cs = 709; goto _test_eof; 
	_test_eof710: cs = 710; goto _test_eof; 
	_test_eof711: cs = 711; goto _test_eof; 
	_test_eof712: cs = 712; goto _test_eof; 
	_test_eof713: cs = 713; goto _test_eof; 
	_test_eof714: cs = 714; goto _test_eof; 
	_test_eof715: cs = 715; goto _test_eof; 
	_test_eof716: cs = 716; goto _test_eof; 
	_test_eof717: cs = 717; goto _test_eof; 
	_test_eof718: cs = 718; goto _test_eof; 
	_test_eof719: cs = 719; goto _test_eof; 
	_test_eof720: cs = 720; goto _test_eof; 
	_test_eof721: cs = 721; goto _test_eof; 
	_test_eof722: cs = 722; goto _test_eof; 
	_test_eof723: cs = 723; goto _test_eof; 
	_test_eof724: cs = 724; goto _test_eof; 
	_test_eof725: cs = 725; goto _test_eof; 
	_test_eof726: cs = 726; goto _test_eof; 
	_test_eof727: cs = 727; goto _test_eof; 
	_test_eof728: cs = 728; goto _test_eof; 
	_test_eof732: cs = 732; goto _test_eof; 
	_test_eof729: cs = 729; goto _test_eof; 
	_test_eof733: cs = 733; goto _test_eof; 

	_test_eof: {}
	if ( p == eof )
	{
	switch ( cs ) {
	case 1: 
	case 2: 
	case 3: 
	case 4: 
	case 5: 
	case 6: 
	case 7: 
	case 8: 
	case 9: 
	case 10: 
	case 11: 
	case 12: 
	case 13: 
#line 60 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new FileformatError{n_lines});
        p--; {goto st728;}
    }
	break;
	case 25: 
	case 26: 
	case 27: 
	case 29: 
	case 30: 
	case 31: 
	case 32: 
	case 33: 
	case 34: 
	case 35: 
	case 36: 
	case 37: 
	case 38: 
	case 39: 
	case 40: 
	case 41: 
	case 42: 
	case 43: 
	case 44: 
	case 45: 
	case 46: 
	case 47: 
	case 48: 
	case 49: 
	case 50: 
	case 51: 
	case 52: 
	case 53: 
	case 54: 
	case 55: 
	case 56: 
	case 57: 
	case 58: 
	case 59: 
	case 60: 
	case 61: 
	case 62: 
	case 63: 
	case 64: 
	case 65: 
	case 66: 
	case 67: 
	case 68: 
	case 69: 
	case 70: 
	case 71: 
	case 72: 
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	break;
	case 730: 
#line 70 "src/vcf/vcf_v42.ragel"
	{
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (MetaSectionError *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
    }
	break;
	case 478: 
	case 479: 
	case 480: 
	case 481: 
	case 482: 
	case 483: 
	case 484: 
	case 485: 
	case 486: 
#line 78 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new HeaderSectionError{n_lines});
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (MetaSectionError *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
        
        p--; {goto st729;}
    }
	break;
	case 14: 
	case 15: 
	case 16: 
	case 17: 
	case 18: 
	case 19: 
	case 20: 
	case 21: 
#line 214 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this,
            new FileformatError{n_lines, "The fileformat declaration is not 'fileformat=VCFv4.2'"});
        p--; {goto st728;}
    }
#line 60 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new FileformatError{n_lines});
        p--; {goto st728;}
    }
	break;
	case 73: 
	case 74: 
	case 75: 
	case 76: 
	case 77: 
	case 78: 
	case 79: 
	case 82: 
	case 83: 
	case 84: 
	case 85: 
	case 86: 
	case 87: 
	case 88: 
	case 89: 
	case 90: 
	case 91: 
	case 92: 
	case 93: 
	case 94: 
	case 101: 
	case 112: 
#line 221 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	break;
	case 374: 
	case 375: 
	case 376: 
	case 377: 
	case 378: 
	case 379: 
	case 380: 
	case 381: 
#line 233 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in assembly metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	break;
	case 389: 
	case 390: 
	case 391: 
	case 392: 
	case 393: 
	case 394: 
	case 395: 
	case 396: 
	case 397: 
	case 398: 
	case 403: 
	case 404: 
	case 405: 
	case 406: 
	case 407: 
	case 408: 
	case 409: 
	case 410: 
	case 411: 
	case 412: 
	case 413: 
	case 414: 
	case 415: 
	case 416: 
	case 417: 
	case 418: 
	case 419: 
	case 420: 
	case 421: 
#line 239 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in contig metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	break;
	case 122: 
	case 123: 
	case 124: 
	case 125: 
	case 126: 
	case 127: 
	case 128: 
	case 129: 
	case 130: 
	case 134: 
	case 135: 
	case 136: 
	case 137: 
	case 138: 
	case 139: 
	case 140: 
	case 141: 
	case 142: 
	case 143: 
	case 144: 
	case 145: 
	case 146: 
	case 153: 
	case 164: 
#line 245 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	break;
	case 172: 
	case 173: 
	case 174: 
	case 175: 
	case 176: 
	case 177: 
	case 178: 
	case 179: 
	case 180: 
	case 184: 
	case 185: 
	case 186: 
	case 187: 
	case 188: 
	case 189: 
	case 190: 
	case 193: 
	case 194: 
	case 195: 
	case 196: 
	case 197: 
	case 200: 
	case 201: 
	case 202: 
	case 203: 
	case 204: 
	case 205: 
	case 206: 
	case 207: 
	case 208: 
	case 209: 
	case 210: 
	case 211: 
	case 212: 
	case 219: 
	case 230: 
#line 251 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	break;
	case 239: 
	case 240: 
	case 241: 
	case 242: 
	case 243: 
	case 244: 
	case 245: 
	case 246: 
	case 250: 
	case 251: 
	case 252: 
	case 253: 
	case 254: 
	case 255: 
	case 256: 
	case 259: 
	case 260: 
	case 261: 
	case 262: 
	case 263: 
	case 266: 
	case 267: 
	case 268: 
	case 269: 
	case 270: 
	case 271: 
	case 272: 
	case 273: 
	case 274: 
	case 275: 
	case 276: 
	case 277: 
	case 278: 
	case 285: 
	case 296: 
#line 267 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	break;
	case 305: 
	case 306: 
	case 307: 
	case 308: 
	case 309: 
	case 310: 
	case 311: 
	case 312: 
	case 313: 
	case 320: 
#line 283 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	break;
	case 422: 
	case 423: 
	case 424: 
	case 425: 
	case 426: 
	case 427: 
	case 428: 
	case 429: 
	case 430: 
	case 431: 
	case 432: 
#line 289 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in pedigreeDB metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	break;
	case 321: 
	case 322: 
	case 323: 
	case 324: 
	case 325: 
	case 326: 
	case 327: 
	case 328: 
	case 329: 
	case 330: 
	case 370: 
#line 295 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	break;
	case 441: 
	case 442: 
	case 443: 
	case 444: 
	case 445: 
	case 446: 
	case 447: 
	case 448: 
	case 449: 
	case 450: 
	case 451: 
	case 452: 
	case 453: 
	case 454: 
	case 455: 
	case 456: 
	case 457: 
	case 458: 
	case 459: 
	case 460: 
	case 461: 
	case 462: 
	case 463: 
	case 464: 
	case 465: 
	case 466: 
	case 467: 
	case 468: 
	case 469: 
	case 470: 
	case 471: 
	case 472: 
	case 473: 
	case 474: 
	case 475: 
	case 476: 
	case 477: 
#line 327 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new HeaderSectionError{n_lines,
            "The header line does not start with the mandatory columns: CHROM, POS, ID, REF, ALT, QUAL, FILTER and INFO"});
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (MetaSectionError *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
        
        p--; {goto st729;}
    }
#line 78 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new HeaderSectionError{n_lines});
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (MetaSectionError *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
        
        p--; {goto st729;}
    }
	break;
	case 487: 
	case 511: 
	case 512: 
	case 513: 
	case 514: 
	case 515: 
	case 726: 
	case 727: 
#line 344 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new ChromosomeBodyError{n_lines});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	break;
	case 488: 
	case 489: 
	case 490: 
#line 350 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new PositionBodyError{n_lines});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	break;
	case 491: 
	case 492: 
#line 356 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new IdBodyError{n_lines});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	break;
	case 493: 
	case 494: 
#line 362 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new ReferenceAlleleBodyError{n_lines});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	break;
	case 495: 
	case 496: 
	case 671: 
	case 672: 
	case 673: 
	case 674: 
	case 675: 
	case 676: 
	case 677: 
	case 678: 
	case 679: 
	case 680: 
	case 681: 
	case 682: 
	case 683: 
	case 684: 
	case 685: 
	case 686: 
	case 687: 
	case 688: 
	case 689: 
	case 690: 
	case 691: 
	case 692: 
	case 693: 
	case 694: 
	case 695: 
	case 696: 
	case 697: 
	case 698: 
	case 699: 
	case 700: 
	case 701: 
	case 702: 
	case 703: 
	case 704: 
	case 705: 
	case 706: 
	case 707: 
	case 708: 
	case 709: 
	case 710: 
	case 711: 
	case 712: 
	case 713: 
	case 714: 
	case 715: 
	case 716: 
	case 717: 
	case 718: 
	case 719: 
	case 720: 
	case 721: 
	case 722: 
	case 723: 
	case 724: 
	case 725: 
#line 368 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new AlternateAllelesBodyError{n_lines});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	break;
	case 497: 
	case 498: 
	case 499: 
	case 500: 
	case 661: 
	case 662: 
	case 663: 
	case 664: 
	case 665: 
	case 666: 
	case 667: 
	case 668: 
	case 669: 
	case 670: 
#line 374 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new QualityBodyError{n_lines});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	break;
	case 501: 
	case 502: 
	case 503: 
	case 659: 
	case 660: 
#line 380 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new FilterBodyError{n_lines});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	break;
	case 507: 
	case 508: 
#line 492 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new FormatBodyError{n_lines});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	break;
	case 518: 
	case 519: 
#line 498 "src/vcf/vcf_v42.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " is not a valid string";
        ErrorPolicy::handle_error(*this, new SamplesBodyError{n_lines, message_stream.str()});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	break;
	case 23: 
	case 28: 
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
#line 327 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new HeaderSectionError{n_lines,
            "The header line does not start with the mandatory columns: CHROM, POS, ID, REF, ALT, QUAL, FILTER and INFO"});
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (MetaSectionError *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
        
        p--; {goto st729;}
    }
#line 78 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new HeaderSectionError{n_lines});
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (MetaSectionError *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
        
        p--; {goto st729;}
    }
	break;
	case 80: 
	case 81: 
	case 120: 
#line 226 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines,
            "ALT metadata ID is not prefixed by DEL/INS/DUP/INV/CNV and suffixed by ':' and a text sequence"});
        p--; {goto st728;}
    }
#line 221 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	break;
	case 121: 
#line 245 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {goto st728;}
    }
#line 251 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	break;
	case 191: 
	case 192: 
	case 238: 
#line 256 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "FORMAT metadata Number is not a number, A, R, G or dot"});
        p--; {goto st728;}
    }
#line 251 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	break;
	case 257: 
	case 258: 
	case 304: 
#line 272 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "INFO metadata Number is not a number, A, R, G or dot"});
        p--; {goto st728;}
    }
#line 267 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	break;
	case 198: 
	case 199: 
#line 277 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "INFO metadata Type is not a Integer, Float, Flag, Character or String"});
        p--; {goto st728;}
    }
#line 251 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	break;
	case 264: 
	case 265: 
#line 277 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "INFO metadata Type is not a Integer, Float, Flag, Character or String"});
        p--; {goto st728;}
    }
#line 267 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	break;
	case 334: 
	case 335: 
	case 336: 
	case 337: 
	case 338: 
	case 339: 
	case 340: 
	case 341: 
	case 342: 
#line 300 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "SAMPLE metadata Genomes is not a valid string (maybe it contains quotes?)"});
        p--; {goto st728;}
    }
#line 295 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	break;
	case 344: 
	case 345: 
	case 346: 
	case 347: 
	case 348: 
	case 349: 
	case 350: 
	case 351: 
	case 352: 
#line 305 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "SAMPLE metadata Mixture is not a valid string (maybe it contains quotes?)"});
        p--; {goto st728;}
    }
#line 295 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	break;
	case 98: 
	case 99: 
	case 100: 
#line 311 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st728;}
    }
#line 221 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	break;
	case 399: 
	case 400: 
	case 401: 
	case 402: 
#line 311 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st728;}
    }
#line 239 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in contig metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	break;
	case 131: 
	case 132: 
	case 133: 
	case 150: 
	case 151: 
	case 152: 
#line 311 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st728;}
    }
#line 245 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	break;
	case 181: 
	case 182: 
	case 183: 
	case 216: 
	case 217: 
	case 218: 
#line 311 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st728;}
    }
#line 251 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	break;
	case 247: 
	case 248: 
	case 249: 
	case 282: 
	case 283: 
	case 284: 
#line 311 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st728;}
    }
#line 267 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	break;
	case 314: 
	case 315: 
	case 316: 
	case 317: 
	case 318: 
	case 319: 
#line 311 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st728;}
    }
#line 283 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	break;
	case 331: 
	case 332: 
#line 311 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st728;}
    }
#line 295 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	break;
	case 95: 
	case 96: 
	case 97: 
	case 102: 
	case 103: 
	case 104: 
	case 105: 
	case 109: 
	case 110: 
	case 111: 
	case 113: 
	case 114: 
	case 118: 
	case 119: 
#line 316 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st728;}
    }
#line 221 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	break;
	case 147: 
	case 148: 
	case 149: 
	case 154: 
	case 155: 
	case 156: 
	case 157: 
	case 161: 
	case 162: 
	case 163: 
	case 165: 
	case 166: 
	case 170: 
	case 171: 
#line 316 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st728;}
    }
#line 245 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	break;
	case 213: 
	case 214: 
	case 215: 
	case 220: 
	case 221: 
	case 222: 
	case 223: 
	case 227: 
	case 228: 
	case 229: 
	case 231: 
	case 232: 
	case 236: 
	case 237: 
#line 316 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st728;}
    }
#line 251 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	break;
	case 279: 
	case 280: 
	case 281: 
	case 286: 
	case 287: 
	case 288: 
	case 289: 
	case 293: 
	case 294: 
	case 295: 
	case 297: 
	case 298: 
	case 302: 
	case 303: 
#line 316 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st728;}
    }
#line 267 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	break;
	case 354: 
	case 355: 
	case 356: 
	case 357: 
	case 358: 
	case 359: 
	case 360: 
	case 361: 
	case 362: 
	case 363: 
	case 364: 
	case 365: 
	case 366: 
	case 367: 
	case 368: 
	case 369: 
	case 371: 
	case 372: 
	case 373: 
#line 316 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st728;}
    }
#line 295 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	break;
	case 382: 
	case 383: 
	case 384: 
	case 385: 
	case 386: 
	case 387: 
	case 388: 
#line 321 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata URL is not valid"});
        p--; {goto st728;}
    }
#line 233 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in assembly metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	break;
	case 433: 
	case 434: 
	case 435: 
	case 436: 
	case 437: 
	case 438: 
	case 439: 
	case 440: 
#line 321 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata URL is not valid"});
        p--; {goto st728;}
    }
#line 289 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in pedigreeDB metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	break;
	case 504: 
	case 505: 
	case 506: 
	case 520: 
	case 521: 
	case 522: 
	case 523: 
	case 524: 
	case 530: 
	case 531: 
	case 535: 
	case 539: 
	case 553: 
	case 557: 
	case 558: 
	case 572: 
	case 573: 
	case 574: 
	case 575: 
	case 576: 
	case 579: 
	case 583: 
	case 587: 
	case 588: 
	case 589: 
	case 593: 
	case 600: 
	case 601: 
	case 602: 
	case 619: 
	case 620: 
	case 624: 
	case 625: 
	case 639: 
	case 640: 
	case 641: 
	case 642: 
	case 643: 
	case 647: 
	case 648: 
	case 649: 
	case 650: 
	case 651: 
	case 652: 
	case 653: 
	case 654: 
	case 658: 
#line 391 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info key is not a sequence of alphanumeric and/or punctuation characters"});
        p--; {goto st729;}
    }
#line 386 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	break;
	case 525: 
	case 526: 
#line 396 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info field value is not a comma-separated list of valid strings (maybe it contains whitespaces?)"});
        p--; {goto st729;}
    }
#line 386 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	break;
	case 532: 
	case 533: 
	case 534: 
#line 401 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info AA value is not a single dot or a string of bases"});
        p--; {goto st729;}
    }
#line 386 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	break;
	case 536: 
	case 537: 
	case 538: 
#line 406 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info AC value is not a comma-separated list of numbers"});
        p--; {goto st729;}
    }
#line 386 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	break;
	case 540: 
	case 541: 
	case 542: 
	case 543: 
	case 544: 
	case 545: 
	case 546: 
	case 547: 
	case 548: 
	case 549: 
	case 550: 
	case 551: 
	case 552: 
#line 411 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info AF value is not a comma-separated list of numbers"});
        p--; {goto st729;}
    }
#line 386 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	break;
	case 554: 
	case 555: 
	case 556: 
#line 416 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info AN value is not an integer number"});
        p--; {goto st729;}
    }
#line 386 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	break;
	case 559: 
	case 560: 
	case 561: 
	case 562: 
	case 563: 
	case 564: 
	case 565: 
	case 566: 
	case 567: 
	case 568: 
	case 569: 
	case 570: 
	case 571: 
#line 421 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info BQ value is not a number"});
        p--; {goto st729;}
    }
#line 386 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	break;
	case 577: 
	case 578: 
#line 426 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info CIGAR value is not an alphanumeric string"});
        p--; {goto st729;}
    }
#line 386 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	break;
	case 581: 
	case 582: 
#line 431 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info DB is not a flag (with 1/0/no value)"});
        p--; {goto st729;}
    }
#line 386 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	break;
	case 584: 
	case 585: 
	case 586: 
#line 436 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info DP value is not an integer number"});
        p--; {goto st729;}
    }
#line 386 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	break;
	case 590: 
	case 591: 
	case 592: 
#line 441 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info END value is not an integer number"});
        p--; {goto st729;}
    }
#line 386 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	break;
	case 595: 
	case 596: 
#line 446 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info H2 is not a flag (with 1/0/no value)"});
        p--; {goto st729;}
    }
#line 386 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	break;
	case 598: 
	case 599: 
#line 451 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info H3 is not a flag (with 1/0/no value)"});
        p--; {goto st729;}
    }
#line 386 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	break;
	case 606: 
	case 607: 
	case 608: 
	case 609: 
	case 610: 
	case 611: 
	case 612: 
	case 613: 
	case 614: 
	case 615: 
	case 616: 
	case 617: 
	case 618: 
#line 456 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info MQ value is not a number"});
        p--; {goto st729;}
    }
#line 386 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	break;
	case 603: 
	case 604: 
	case 605: 
#line 461 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info MQ0 value is not an integer number"});
        p--; {goto st729;}
    }
#line 386 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	break;
	case 621: 
	case 622: 
	case 623: 
#line 466 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info NS value is not an integer number"});
        p--; {goto st729;}
    }
#line 386 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	break;
	case 626: 
	case 627: 
	case 628: 
	case 629: 
	case 630: 
	case 631: 
	case 632: 
	case 633: 
	case 634: 
	case 635: 
	case 636: 
	case 637: 
	case 638: 
#line 471 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info SB value is not a number"});
        p--; {goto st729;}
    }
#line 386 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	break;
	case 645: 
	case 646: 
#line 476 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info SOMATIC is not a flag (with 1/0/no value)"});
        p--; {goto st729;}
    }
#line 386 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	break;
	case 656: 
	case 657: 
#line 481 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info VALIDATED is not a flag (with 1/0/no value)"});
        p--; {goto st729;}
    }
#line 386 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	break;
	case 528: 
	case 529: 
#line 486 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info 1000G is not a flag (with 1/0/no value)"});
        p--; {goto st729;}
    }
#line 386 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	break;
	case 509: 
	case 510: 
	case 516: 
	case 517: 
#line 505 "src/vcf/vcf_v42.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " does not start with a valid genotype";
        ErrorPolicy::handle_error(*this, new SamplesBodyError{n_lines, message_stream.str()});
        p--; {goto st729;}
    }
#line 498 "src/vcf/vcf_v42.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " is not a valid string";
        ErrorPolicy::handle_error(*this, new SamplesBodyError{n_lines, message_stream.str()});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	break;
	case 22: 
#line 60 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new FileformatError{n_lines});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
#line 327 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new HeaderSectionError{n_lines,
            "The header line does not start with the mandatory columns: CHROM, POS, ID, REF, ALT, QUAL, FILTER and INFO"});
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (MetaSectionError *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
        
        p--; {goto st729;}
    }
#line 78 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new HeaderSectionError{n_lines});
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (MetaSectionError *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
        
        p--; {goto st729;}
    }
	break;
	case 343: 
#line 300 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "SAMPLE metadata Genomes is not a valid string (maybe it contains quotes?)"});
        p--; {goto st728;}
    }
#line 305 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "SAMPLE metadata Mixture is not a valid string (maybe it contains quotes?)"});
        p--; {goto st728;}
    }
#line 295 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	break;
	case 353: 
#line 305 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "SAMPLE metadata Mixture is not a valid string (maybe it contains quotes?)"});
        p--; {goto st728;}
    }
#line 316 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st728;}
    }
#line 295 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	break;
	case 333: 
#line 311 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st728;}
    }
#line 300 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "SAMPLE metadata Genomes is not a valid string (maybe it contains quotes?)"});
        p--; {goto st728;}
    }
#line 295 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	break;
	case 106: 
	case 107: 
	case 108: 
#line 311 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st728;}
    }
#line 316 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st728;}
    }
#line 221 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	break;
	case 158: 
	case 159: 
	case 160: 
#line 311 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st728;}
    }
#line 316 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st728;}
    }
#line 245 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	break;
	case 224: 
	case 225: 
	case 226: 
#line 311 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st728;}
    }
#line 316 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st728;}
    }
#line 251 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	break;
	case 290: 
	case 291: 
	case 292: 
#line 311 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st728;}
    }
#line 316 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st728;}
    }
#line 267 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	break;
	case 115: 
	case 116: 
	case 117: 
#line 316 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st728;}
    }
#line 311 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st728;}
    }
#line 221 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	break;
	case 167: 
	case 168: 
	case 169: 
#line 316 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st728;}
    }
#line 311 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st728;}
    }
#line 245 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	break;
	case 233: 
	case 234: 
	case 235: 
#line 316 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st728;}
    }
#line 311 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st728;}
    }
#line 251 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	break;
	case 299: 
	case 300: 
	case 301: 
#line 316 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st728;}
    }
#line 311 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st728;}
    }
#line 267 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	break;
	case 580: 
#line 431 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info DB is not a flag (with 1/0/no value)"});
        p--; {goto st729;}
    }
#line 391 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info key is not a sequence of alphanumeric and/or punctuation characters"});
        p--; {goto st729;}
    }
#line 386 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	break;
	case 594: 
#line 446 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info H2 is not a flag (with 1/0/no value)"});
        p--; {goto st729;}
    }
#line 391 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info key is not a sequence of alphanumeric and/or punctuation characters"});
        p--; {goto st729;}
    }
#line 386 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	break;
	case 597: 
#line 451 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info H3 is not a flag (with 1/0/no value)"});
        p--; {goto st729;}
    }
#line 391 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info key is not a sequence of alphanumeric and/or punctuation characters"});
        p--; {goto st729;}
    }
#line 386 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	break;
	case 644: 
#line 476 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info SOMATIC is not a flag (with 1/0/no value)"});
        p--; {goto st729;}
    }
#line 391 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info key is not a sequence of alphanumeric and/or punctuation characters"});
        p--; {goto st729;}
    }
#line 386 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	break;
	case 655: 
#line 481 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info VALIDATED is not a flag (with 1/0/no value)"});
        p--; {goto st729;}
    }
#line 391 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info key is not a sequence of alphanumeric and/or punctuation characters"});
        p--; {goto st729;}
    }
#line 386 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	break;
	case 527: 
#line 486 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info 1000G is not a flag (with 1/0/no value)"});
        p--; {goto st729;}
    }
#line 391 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info key is not a sequence of alphanumeric and/or punctuation characters"});
        p--; {goto st729;}
    }
#line 386 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st729;}
    }
#line 91 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st729;}
    }
	break;
	case 24: 
#line 221 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {goto st728;}
    }
#line 245 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {goto st728;}
    }
#line 251 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st728;}
    }
#line 267 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st728;}
    }
#line 233 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in assembly metadata"});
        p--; {goto st728;}
    }
#line 239 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in contig metadata"});
        p--; {goto st728;}
    }
#line 295 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st728;}
    }
#line 283 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {goto st728;}
    }
#line 289 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in pedigreeDB metadata"});
        p--; {goto st728;}
    }
#line 65 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st728;}
    }
	break;
#line 18890 "inc/vcf/validator_detail_v42.hpp"
	}
	}

	_out: {}
	}

#line 778 "src/vcf/vcf_v42.ragel"

    }
   
  }
}
