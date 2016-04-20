
#line 1 "src/vcf/vcf_v43.ragel"
/**
 * Copyright 2014-2016 EMBL - European Bioinformatics Institute
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


#line 770 "src/vcf/vcf_v43.ragel"


namespace
{
  
#line 31 "inc/vcf/validator_detail_v43.hpp"
static const int vcf_v43_start = 1;
static const int vcf_v43_first_final = 734;
static const int vcf_v43_error = 0;

static const int vcf_v43_en_main = 1;
static const int vcf_v43_en_main_meta_section = 28;
static const int vcf_v43_en_main_body_section = 735;
static const int vcf_v43_en_meta_section_skip = 732;
static const int vcf_v43_en_body_section_skip = 733;


#line 776 "src/vcf/vcf_v43.ragel"

}

namespace ebi
{
  namespace vcf
  {
    
    template <typename Configuration>
    ParserImpl_v43<Configuration>::ParserImpl_v43(std::shared_ptr<Source> const & source,
                                                  std::shared_ptr<std::vector<Record>> const & records
    )
    : ParserImpl{source, records}
    {
      
#line 59 "inc/vcf/validator_detail_v43.hpp"
	{
	cs = vcf_v43_start;
	}

#line 792 "src/vcf/vcf_v43.ragel"

    }

    template <typename Configuration>
    void ParserImpl_v43<Configuration>::parse_buffer(char const * p, char const * pe, char const * eof)
    {
      
#line 72 "inc/vcf/validator_detail_v43.hpp"
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
#line 60 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this);
        p--; {goto st732;}
    }
	goto st0;
tr14:
#line 210 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this,
            "The fileformat declaration is not 'fileformat=VCFv4.3'");
        p--; {goto st732;}
    }
#line 60 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this);
        p--; {goto st732;}
    }
	goto st0;
tr24:
#line 60 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this);
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
#line 322 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this, "The header line does not start with the mandatory columns: CHROM, POS, ID, REF, ALT, QUAL, FILTER and INFO");
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (ParsingWarning warn) {
          ErrorPolicy::handle_meta_section_warning(*this, warn.what());
        }
        
        p--; {goto st733;}
    }
#line 78 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (ParsingWarning warn) {
          ErrorPolicy::handle_meta_section_warning(*this, warn.what());
        }
        
        p--; {goto st733;}
    }
	goto st0;
tr26:
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
#line 322 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this, "The header line does not start with the mandatory columns: CHROM, POS, ID, REF, ALT, QUAL, FILTER and INFO");
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (ParsingWarning warn) {
          ErrorPolicy::handle_meta_section_warning(*this, warn.what());
        }
        
        p--; {goto st733;}
    }
#line 78 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (ParsingWarning warn) {
          ErrorPolicy::handle_meta_section_warning(*this, warn.what());
        }
        
        p--; {goto st733;}
    }
	goto st0;
tr29:
#line 217 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st732;}
    }
#line 240 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st732;}
    }
#line 246 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st732;}
    }
#line 262 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st732;}
    }
#line 228 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in assembly metadata");
        p--; {goto st732;}
    }
#line 234 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in contig metadata");
        p--; {goto st732;}
    }
#line 290 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st732;}
    }
#line 278 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in PEDIGREE metadata");
        p--; {goto st732;}
    }
#line 284 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in pedigreeDB metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	goto st0;
tr39:
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	goto st0;
tr125:
#line 217 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	goto st0;
tr133:
#line 222 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "ALT metadata ID is not prefixed by DEL/INS/DUP/INV/CNV and suffixed by ':' and a text sequence");
        p--; {goto st732;}
    }
#line 217 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	goto st0;
tr152:
#line 311 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st732;}
    }
#line 217 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	goto st0;
tr161:
#line 306 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st732;}
    }
#line 217 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	goto st0;
tr175:
#line 306 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st732;}
    }
#line 311 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st732;}
    }
#line 217 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	goto st0;
tr187:
#line 311 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st732;}
    }
#line 306 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st732;}
    }
#line 217 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	goto st0;
tr193:
#line 240 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st732;}
    }
#line 246 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	goto st0;
tr196:
#line 240 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	goto st0;
tr206:
#line 306 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st732;}
    }
#line 240 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	goto st0;
tr225:
#line 311 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st732;}
    }
#line 240 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	goto st0;
tr247:
#line 306 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st732;}
    }
#line 311 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st732;}
    }
#line 240 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	goto st0;
tr259:
#line 311 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st732;}
    }
#line 306 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st732;}
    }
#line 240 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	goto st0;
tr265:
#line 246 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	goto st0;
tr275:
#line 306 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st732;}
    }
#line 246 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	goto st0;
tr288:
#line 251 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "FORMAT metadata Number is not a number, A, R, G or dot");
        p--; {goto st732;}
    }
#line 246 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	goto st0;
tr297:
#line 272 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "INFO metadata Type is not a Integer, Float, Flag, Character or String");
        p--; {goto st732;}
    }
#line 246 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	goto st0;
tr314:
#line 311 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st732;}
    }
#line 246 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	goto st0;
tr336:
#line 306 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st732;}
    }
#line 311 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st732;}
    }
#line 246 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	goto st0;
tr348:
#line 311 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st732;}
    }
#line 306 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st732;}
    }
#line 246 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	goto st0;
tr355:
#line 262 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	goto st0;
tr364:
#line 306 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st732;}
    }
#line 262 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	goto st0;
tr377:
#line 267 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "INFO metadata Number is not a number, A, R, G or dot");
        p--; {goto st732;}
    }
#line 262 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	goto st0;
tr386:
#line 272 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "INFO metadata Type is not a Integer, Float, Flag, Character or String");
        p--; {goto st732;}
    }
#line 262 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	goto st0;
tr403:
#line 311 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st732;}
    }
#line 262 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	goto st0;
tr425:
#line 306 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st732;}
    }
#line 311 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st732;}
    }
#line 262 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	goto st0;
tr437:
#line 311 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st732;}
    }
#line 306 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st732;}
    }
#line 262 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	goto st0;
tr444:
#line 278 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in PEDIGREE metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	goto st0;
tr454:
#line 306 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st732;}
    }
#line 278 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in PEDIGREE metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	goto st0;
tr466:
#line 290 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	goto st0;
tr477:
#line 306 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st732;}
    }
#line 290 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	goto st0;
tr482:
#line 306 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st732;}
    }
#line 295 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Genomes is not a valid string (maybe it contains quotes?)");
        p--; {goto st732;}
    }
#line 290 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	goto st0;
tr484:
#line 295 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Genomes is not a valid string (maybe it contains quotes?)");
        p--; {goto st732;}
    }
#line 290 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	goto st0;
tr494:
#line 295 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Genomes is not a valid string (maybe it contains quotes?)");
        p--; {goto st732;}
    }
#line 300 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Mixture is not a valid string (maybe it contains quotes?)");
        p--; {goto st732;}
    }
#line 290 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	goto st0;
tr497:
#line 300 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Mixture is not a valid string (maybe it contains quotes?)");
        p--; {goto st732;}
    }
#line 290 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	goto st0;
tr507:
#line 300 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Mixture is not a valid string (maybe it contains quotes?)");
        p--; {goto st732;}
    }
#line 311 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st732;}
    }
#line 290 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	goto st0;
tr510:
#line 311 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st732;}
    }
#line 290 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	goto st0;
tr533:
#line 228 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in assembly metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	goto st0;
tr542:
#line 316 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata URL is not valid");
        p--; {goto st732;}
    }
#line 228 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in assembly metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	goto st0;
tr562:
#line 234 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in contig metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	goto st0;
tr573:
#line 306 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st732;}
    }
#line 234 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in contig metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	goto st0;
tr611:
#line 284 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in pedigreeDB metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	goto st0;
tr623:
#line 316 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata URL is not valid");
        p--; {goto st732;}
    }
#line 284 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in pedigreeDB metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	goto st0;
tr644:
#line 322 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this, "The header line does not start with the mandatory columns: CHROM, POS, ID, REF, ALT, QUAL, FILTER and INFO");
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (ParsingWarning warn) {
          ErrorPolicy::handle_meta_section_warning(*this, warn.what());
        }
        
        p--; {goto st733;}
    }
#line 78 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (ParsingWarning warn) {
          ErrorPolicy::handle_meta_section_warning(*this, warn.what());
        }
        
        p--; {goto st733;}
    }
	goto st0;
tr684:
#line 78 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (ParsingWarning warn) {
          ErrorPolicy::handle_meta_section_warning(*this, warn.what());
        }
        
        p--; {goto st733;}
    }
	goto st0;
tr697:
#line 338 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Chromosome is not a string without colons or whitespaces, optionally wrapped with angle brackets (<>)");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	goto st0;
tr700:
#line 344 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Position is not a positive number");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	goto st0;
tr704:
#line 350 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "ID is not a single dot or a list of strings without semicolons or whitespaces");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	goto st0;
tr709:
#line 356 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Reference is not a string of bases");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	goto st0;
tr713:
#line 362 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Alternate is not a single dot or a comma-separated list of bases");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	goto st0;
tr722:
#line 368 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Quality is not a single dot or a positive number");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	goto st0;
tr734:
#line 374 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Filter is not a single dot or a semicolon-separated list of strings");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	goto st0;
tr742:
#line 385 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st733;}
    }
#line 380 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	goto st0;
tr756:
#line 380 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	goto st0;
tr760:
#line 501 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Format is not a colon-separated list of alphanumeric strings");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	goto st0;
tr765:
#line 514 "src/vcf/vcf_v43.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " does not start with a valid genotype";
        ErrorPolicy::handle_body_section_error(*this, message_stream.str());
        p--; {goto st733;}
    }
#line 507 "src/vcf/vcf_v43.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " is not a valid string";
        ErrorPolicy::handle_body_section_error(*this, message_stream.str());
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	goto st0;
tr774:
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	goto st0;
tr778:
#line 507 "src/vcf/vcf_v43.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " is not a valid string";
        ErrorPolicy::handle_body_section_error(*this, message_stream.str());
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	goto st0;
tr787:
#line 390 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info field value is not a comma-separated list of valid strings (maybe it contains whitespaces?)");
        p--; {goto st733;}
    }
#line 380 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	goto st0;
tr789:
#line 495 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info 1000G is not a flag (with 1/0/no value)");
        p--; {goto st733;}
    }
#line 385 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st733;}
    }
#line 380 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	goto st0;
tr791:
#line 495 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info 1000G is not a flag (with 1/0/no value)");
        p--; {goto st733;}
    }
#line 380 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	goto st0;
tr799:
#line 395 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info AA value is not a single dot or a string of bases");
        p--; {goto st733;}
    }
#line 380 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	goto st0;
tr803:
#line 400 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info AC value is not a comma-separated list of numbers");
        p--; {goto st733;}
    }
#line 380 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	goto st0;
tr808:
#line 405 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info AD value is not a comma-separated list of numbers");
        p--; {goto st733;}
    }
#line 380 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	goto st0;
tr811:
#line 410 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info ADF value is not a comma-separated list of numbers");
        p--; {goto st733;}
    }
#line 380 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	goto st0;
tr814:
#line 415 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info ADR value is not a comma-separated list of numbers");
        p--; {goto st733;}
    }
#line 380 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	goto st0;
tr817:
#line 420 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info AF value is not a comma-separated list of numbers");
        p--; {goto st733;}
    }
#line 380 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	goto st0;
tr831:
#line 425 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info AN value is not an integer number");
        p--; {goto st733;}
    }
#line 380 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	goto st0;
tr835:
#line 430 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info BQ value is not a number");
        p--; {goto st733;}
    }
#line 380 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	goto st0;
tr853:
#line 435 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info CIGAR value is not an alphanumeric string");
        p--; {goto st733;}
    }
#line 380 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	goto st0;
tr857:
#line 440 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info DB is not a flag (with 1/0/no value)");
        p--; {goto st733;}
    }
#line 385 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st733;}
    }
#line 380 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	goto st0;
tr859:
#line 440 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info DB is not a flag (with 1/0/no value)");
        p--; {goto st733;}
    }
#line 380 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	goto st0;
tr862:
#line 445 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info DP value is not an integer number");
        p--; {goto st733;}
    }
#line 380 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	goto st0;
tr867:
#line 450 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info END value is not an integer number");
        p--; {goto st733;}
    }
#line 380 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	goto st0;
tr871:
#line 455 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info H2 is not a flag (with 1/0/no value)");
        p--; {goto st733;}
    }
#line 385 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st733;}
    }
#line 380 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	goto st0;
tr873:
#line 455 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info H2 is not a flag (with 1/0/no value)");
        p--; {goto st733;}
    }
#line 380 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	goto st0;
tr875:
#line 460 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info H3 is not a flag (with 1/0/no value)");
        p--; {goto st733;}
    }
#line 385 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st733;}
    }
#line 380 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	goto st0;
tr877:
#line 460 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info H3 is not a flag (with 1/0/no value)");
        p--; {goto st733;}
    }
#line 380 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	goto st0;
tr883:
#line 470 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info MQ0 value is not an integer number");
        p--; {goto st733;}
    }
#line 380 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	goto st0;
tr885:
#line 465 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info MQ value is not a number");
        p--; {goto st733;}
    }
#line 380 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	goto st0;
tr900:
#line 475 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info NS value is not an integer number");
        p--; {goto st733;}
    }
#line 380 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	goto st0;
tr905:
#line 480 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info SB value is not a number");
        p--; {goto st733;}
    }
#line 380 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	goto st0;
tr923:
#line 485 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info SOMATIC is not a flag (with 1/0/no value)");
        p--; {goto st733;}
    }
#line 385 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st733;}
    }
#line 380 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	goto st0;
tr925:
#line 485 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info SOMATIC is not a flag (with 1/0/no value)");
        p--; {goto st733;}
    }
#line 380 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	goto st0;
tr935:
#line 490 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info VALIDATED is not a flag (with 1/0/no value)");
        p--; {goto st733;}
    }
#line 385 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st733;}
    }
#line 380 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	goto st0;
tr937:
#line 490 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info VALIDATED is not a flag (with 1/0/no value)");
        p--; {goto st733;}
    }
#line 380 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	goto st0;
tr985:
#line 78 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (ParsingWarning warn) {
          ErrorPolicy::handle_meta_section_warning(*this, warn.what());
        }
        
        p--; {goto st733;}
    }
#line 338 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Chromosome is not a string without colons or whitespaces, optionally wrapped with angle brackets (<>)");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	goto st0;
#line 1697 "inc/vcf/validator_detail_v43.hpp"
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
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st15;
st15:
	if ( ++p == pe )
		goto _test_eof15;
case 15:
#line 1806 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 67 )
		goto tr16;
	goto tr14;
tr16:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st16;
st16:
	if ( ++p == pe )
		goto _test_eof16;
case 16:
#line 1820 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 70 )
		goto tr17;
	goto tr14;
tr17:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st17;
st17:
	if ( ++p == pe )
		goto _test_eof17;
case 17:
#line 1834 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 118 )
		goto tr18;
	goto tr14;
tr18:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st18;
st18:
	if ( ++p == pe )
		goto _test_eof18;
case 18:
#line 1848 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 52 )
		goto tr19;
	goto tr14;
tr19:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st19;
st19:
	if ( ++p == pe )
		goto _test_eof19;
case 19:
#line 1862 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 46 )
		goto tr20;
	goto tr14;
tr20:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st20;
st20:
	if ( ++p == pe )
		goto _test_eof20;
case 20:
#line 1876 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 51 )
		goto tr21;
	goto tr14;
tr21:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st21;
st21:
	if ( ++p == pe )
		goto _test_eof21;
case 21:
#line 1890 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 10: goto tr22;
		case 13: goto tr23;
	}
	goto tr14;
tr22:
#line 99 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_fileformat(*this);
    }
#line 43 "src/vcf/vcf_v43.ragel"
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
#line 1916 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 35 )
		goto st23;
	goto tr24;
st23:
	if ( ++p == pe )
		goto _test_eof23;
case 23:
	switch( (*p) ) {
		case 35: goto st24;
		case 67: goto st465;
	}
	goto tr26;
st24:
	if ( ++p == pe )
		goto _test_eof24;
case 24:
	switch( (*p) ) {
		case 65: goto tr31;
		case 70: goto tr32;
		case 73: goto tr33;
		case 80: goto tr34;
		case 83: goto tr35;
		case 97: goto tr36;
		case 99: goto tr37;
		case 112: goto tr38;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto tr30;
	} else if ( (*p) >= 32 )
		goto tr30;
	goto tr29;
tr30:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st25;
tr40:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st25;
st25:
	if ( ++p == pe )
		goto _test_eof25;
case 25:
#line 1969 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 61 )
		goto tr41;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr39;
tr41:
#line 163 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this);
    }
	goto st26;
st26:
	if ( ++p == pe )
		goto _test_eof26;
case 26:
#line 1985 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto st30;
		case 60: goto st35;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr42;
	goto tr39;
tr42:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st27;
tr47:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st27;
st27:
	if ( ++p == pe )
		goto _test_eof27;
case 27:
#line 2013 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 10: goto tr45;
		case 13: goto tr46;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr47;
	goto tr39;
tr45:
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 171 "src/vcf/vcf_v43.ragel"
	{
        try {
          ParsePolicy::handle_meta_line(*this);
        } catch (ParsingError ex) {
          ErrorPolicy::handle_meta_section_error(*this, ex.what());
        }
    }
#line 43 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st28;
tr55:
#line 171 "src/vcf/vcf_v43.ragel"
	{
        try {
          ParsePolicy::handle_meta_line(*this);
        } catch (ParsingError ex) {
          ErrorPolicy::handle_meta_section_error(*this, ex.what());
        }
    }
#line 43 "src/vcf/vcf_v43.ragel"
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
#line 2069 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 35 )
		goto st23;
	goto tr26;
tr46:
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 171 "src/vcf/vcf_v43.ragel"
	{
        try {
          ParsePolicy::handle_meta_line(*this);
        } catch (ParsingError ex) {
          ErrorPolicy::handle_meta_section_error(*this, ex.what());
        }
    }
#line 43 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st29;
tr56:
#line 171 "src/vcf/vcf_v43.ragel"
	{
        try {
          ParsePolicy::handle_meta_line(*this);
        } catch (ParsingError ex) {
          ErrorPolicy::handle_meta_section_error(*this, ex.what());
        }
    }
#line 43 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st29;
st29:
	if ( ++p == pe )
		goto _test_eof29;
case 29:
#line 2121 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 10 )
		goto st28;
	goto tr39;
st30:
	if ( ++p == pe )
		goto _test_eof30;
case 30:
	switch( (*p) ) {
		case 34: goto tr50;
		case 92: goto tr51;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr49;
	goto tr39;
tr49:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st31;
tr52:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st31;
st31:
	if ( ++p == pe )
		goto _test_eof31;
case 31:
#line 2156 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr53;
		case 92: goto tr54;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr52;
	goto tr39;
tr50:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st32;
tr53:
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st32;
st32:
	if ( ++p == pe )
		goto _test_eof32;
case 32:
#line 2184 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 10: goto tr55;
		case 13: goto tr56;
	}
	goto tr39;
tr51:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st33;
tr54:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st33;
st33:
	if ( ++p == pe )
		goto _test_eof33;
case 33:
#line 2210 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr57;
		case 92: goto tr54;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr52;
	goto tr39;
tr57:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st34;
st34:
	if ( ++p == pe )
		goto _test_eof34;
case 34:
#line 2232 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 10: goto tr55;
		case 13: goto tr56;
		case 34: goto tr53;
		case 92: goto tr54;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr52;
	goto tr39;
st35:
	if ( ++p == pe )
		goto _test_eof35;
case 35:
	switch( (*p) ) {
		case 34: goto st36;
		case 95: goto tr59;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr59;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr60;
		} else if ( (*p) >= 65 )
			goto tr60;
	} else
		goto tr60;
	goto tr39;
st36:
	if ( ++p == pe )
		goto _test_eof36;
case 36:
	switch( (*p) ) {
		case 34: goto tr62;
		case 92: goto tr63;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr61;
	goto tr39;
tr61:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st37;
tr64:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st37;
st37:
	if ( ++p == pe )
		goto _test_eof37;
case 37:
#line 2293 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr65;
		case 92: goto tr66;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr64;
	goto tr39;
tr62:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st38;
tr65:
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st38;
st38:
	if ( ++p == pe )
		goto _test_eof38;
case 38:
#line 2321 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 62 )
		goto st32;
	goto tr39;
tr63:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st39;
tr66:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st39;
st39:
	if ( ++p == pe )
		goto _test_eof39;
case 39:
#line 2345 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr68;
		case 92: goto tr66;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr64;
	goto tr39;
tr68:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st40;
st40:
	if ( ++p == pe )
		goto _test_eof40;
case 40:
#line 2367 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr65;
		case 62: goto tr69;
		case 92: goto tr66;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr64;
	goto tr39;
tr69:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st41;
st41:
	if ( ++p == pe )
		goto _test_eof41;
case 41:
#line 2386 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 10: goto tr55;
		case 13: goto tr56;
		case 34: goto tr65;
		case 92: goto tr66;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr64;
	goto tr39;
tr59:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st42;
st42:
	if ( ++p == pe )
		goto _test_eof42;
case 42:
#line 2406 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 95 )
		goto st42;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st42;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr71;
		} else if ( (*p) >= 65 )
			goto tr71;
	} else
		goto tr71;
	goto tr39;
tr60:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st43;
tr71:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st43;
st43:
	if ( ++p == pe )
		goto _test_eof43;
case 43:
#line 2441 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr72;
		case 95: goto tr71;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr71;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr71;
		} else if ( (*p) >= 65 )
			goto tr71;
	} else
		goto tr71;
	goto tr39;
tr72:
#line 167 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st44;
st44:
	if ( ++p == pe )
		goto _test_eof44;
case 44:
#line 2468 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 34 )
		goto st63;
	if ( (*p) < 45 ) {
		if ( 32 <= (*p) && (*p) <= 43 )
			goto tr73;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr73;
	} else
		goto tr73;
	goto tr39;
tr73:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st45;
tr75:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st45;
st45:
	if ( ++p == pe )
		goto _test_eof45;
case 45:
#line 2500 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 44: goto tr76;
		case 62: goto tr53;
	}
	if ( (*p) > 33 ) {
		if ( 35 <= (*p) && (*p) <= 126 )
			goto tr75;
	} else if ( (*p) >= 32 )
		goto tr75;
	goto tr39;
tr76:
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st46;
st46:
	if ( ++p == pe )
		goto _test_eof46;
case 46:
#line 2521 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 95 )
		goto tr77;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr77;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr78;
		} else if ( (*p) >= 65 )
			goto tr78;
	} else
		goto tr78;
	goto tr39;
tr77:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st47;
st47:
	if ( ++p == pe )
		goto _test_eof47;
case 47:
#line 2546 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 95 )
		goto st47;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st47;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr80;
		} else if ( (*p) >= 65 )
			goto tr80;
	} else
		goto tr80;
	goto tr39;
tr78:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st48;
tr80:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st48;
st48:
	if ( ++p == pe )
		goto _test_eof48;
case 48:
#line 2581 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr81;
		case 95: goto tr80;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr80;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr80;
		} else if ( (*p) >= 65 )
			goto tr80;
	} else
		goto tr80;
	goto tr39;
tr81:
#line 167 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st49;
st49:
	if ( ++p == pe )
		goto _test_eof49;
case 49:
#line 2608 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 34 )
		goto st50;
	if ( (*p) < 45 ) {
		if ( 32 <= (*p) && (*p) <= 43 )
			goto tr73;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr73;
	} else
		goto tr73;
	goto tr39;
st50:
	if ( ++p == pe )
		goto _test_eof50;
case 50:
	switch( (*p) ) {
		case 34: goto tr84;
		case 92: goto tr85;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr83;
	goto tr39;
tr83:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st51;
tr86:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st51;
st51:
	if ( ++p == pe )
		goto _test_eof51;
case 51:
#line 2651 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr87;
		case 92: goto tr88;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr86;
	goto tr39;
tr84:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st52;
tr87:
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st52;
st52:
	if ( ++p == pe )
		goto _test_eof52;
case 52:
#line 2679 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 44: goto st46;
		case 62: goto st32;
	}
	goto tr39;
tr85:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st53;
tr88:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st53;
st53:
	if ( ++p == pe )
		goto _test_eof53;
case 53:
#line 2705 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr90;
		case 92: goto tr88;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr86;
	goto tr39;
tr90:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st54;
st54:
	if ( ++p == pe )
		goto _test_eof54;
case 54:
#line 2727 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr87;
		case 44: goto tr91;
		case 62: goto tr92;
		case 92: goto tr88;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr86;
	goto tr39;
tr105:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st55;
tr91:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st55;
tr102:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st55;
st55:
	if ( ++p == pe )
		goto _test_eof55;
case 55:
#line 2767 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr87;
		case 47: goto tr86;
		case 92: goto tr88;
		case 95: goto tr93;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr86;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr94;
		} else
			goto tr93;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr94;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr86;
			} else if ( (*p) >= 97 )
				goto tr94;
		} else
			goto tr86;
	} else
		goto tr86;
	goto tr39;
tr93:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st56;
tr95:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st56;
st56:
	if ( ++p == pe )
		goto _test_eof56;
case 56:
#line 2818 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr87;
		case 47: goto tr86;
		case 92: goto tr88;
		case 95: goto tr95;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr86;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr96;
		} else
			goto tr95;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr96;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr86;
			} else if ( (*p) >= 97 )
				goto tr96;
		} else
			goto tr86;
	} else
		goto tr86;
	goto tr39;
tr94:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st57;
tr96:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st57;
st57:
	if ( ++p == pe )
		goto _test_eof57;
case 57:
#line 2869 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr87;
		case 47: goto tr86;
		case 61: goto tr97;
		case 92: goto tr88;
		case 95: goto tr96;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr86;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr86;
		} else
			goto tr96;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr86;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr86;
		} else
			goto tr96;
	} else
		goto tr96;
	goto tr39;
tr97:
#line 167 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st58;
st58:
	if ( ++p == pe )
		goto _test_eof58;
case 58:
#line 2912 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr99;
		case 44: goto tr86;
		case 62: goto tr86;
		case 92: goto tr100;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr98;
	goto tr39;
tr101:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st59;
tr98:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st59;
st59:
	if ( ++p == pe )
		goto _test_eof59;
case 59:
#line 2942 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr87;
		case 44: goto tr102;
		case 62: goto tr103;
		case 92: goto tr104;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr101;
	goto tr39;
tr106:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st60;
tr92:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st60;
tr103:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st60;
st60:
	if ( ++p == pe )
		goto _test_eof60;
case 60:
#line 2982 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 10: goto tr55;
		case 13: goto tr56;
		case 34: goto tr87;
		case 92: goto tr88;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr86;
	goto tr39;
tr104:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st61;
tr100:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st61;
st61:
	if ( ++p == pe )
		goto _test_eof61;
case 61:
#line 3012 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr90;
		case 44: goto tr102;
		case 62: goto tr103;
		case 92: goto tr104;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr101;
	goto tr39;
tr99:
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st62;
st62:
	if ( ++p == pe )
		goto _test_eof62;
case 62:
#line 3032 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr84;
		case 44: goto tr105;
		case 62: goto tr106;
		case 92: goto tr85;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr83;
	goto tr39;
st63:
	if ( ++p == pe )
		goto _test_eof63;
case 63:
	switch( (*p) ) {
		case 34: goto tr84;
		case 92: goto tr108;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr107;
	goto tr39;
tr107:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st64;
tr109:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st64;
st64:
	if ( ++p == pe )
		goto _test_eof64;
case 64:
#line 3073 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr87;
		case 92: goto tr110;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr109;
	goto tr39;
tr108:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st65;
tr110:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st65;
st65:
	if ( ++p == pe )
		goto _test_eof65;
case 65:
#line 3101 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr111;
		case 92: goto tr110;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr109;
	goto tr39;
tr111:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st66;
st66:
	if ( ++p == pe )
		goto _test_eof66;
case 66:
#line 3123 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr87;
		case 44: goto tr112;
		case 62: goto tr113;
		case 92: goto tr110;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr109;
	goto tr39;
tr112:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st67;
tr122:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st67;
st67:
	if ( ++p == pe )
		goto _test_eof67;
case 67:
#line 3153 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr87;
		case 47: goto tr109;
		case 92: goto tr110;
		case 95: goto tr114;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr109;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr115;
		} else
			goto tr114;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr115;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr109;
			} else if ( (*p) >= 97 )
				goto tr115;
		} else
			goto tr109;
	} else
		goto tr109;
	goto tr39;
tr116:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st68;
tr114:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st68;
st68:
	if ( ++p == pe )
		goto _test_eof68;
case 68:
#line 3204 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr87;
		case 47: goto tr109;
		case 92: goto tr110;
		case 95: goto tr116;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr109;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr117;
		} else
			goto tr116;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr117;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr109;
			} else if ( (*p) >= 97 )
				goto tr117;
		} else
			goto tr109;
	} else
		goto tr109;
	goto tr39;
tr117:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st69;
tr115:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st69;
st69:
	if ( ++p == pe )
		goto _test_eof69;
case 69:
#line 3255 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr87;
		case 47: goto tr109;
		case 61: goto tr118;
		case 92: goto tr110;
		case 95: goto tr117;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr109;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr109;
		} else
			goto tr117;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr109;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr109;
		} else
			goto tr117;
	} else
		goto tr117;
	goto tr39;
tr118:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 167 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st70;
st70:
	if ( ++p == pe )
		goto _test_eof70;
case 70:
#line 3298 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr99;
		case 44: goto tr109;
		case 62: goto tr109;
		case 92: goto tr120;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr119;
	goto tr39;
tr121:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st71;
tr119:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st71;
st71:
	if ( ++p == pe )
		goto _test_eof71;
case 71:
#line 3328 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr87;
		case 44: goto tr122;
		case 62: goto tr123;
		case 92: goto tr124;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr121;
	goto tr39;
tr113:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st72;
tr123:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st72;
st72:
	if ( ++p == pe )
		goto _test_eof72;
case 72:
#line 3358 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 10: goto tr55;
		case 13: goto tr56;
		case 34: goto tr87;
		case 92: goto tr110;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr109;
	goto tr39;
tr124:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st73;
tr120:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st73;
st73:
	if ( ++p == pe )
		goto _test_eof73;
case 73:
#line 3388 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr111;
		case 44: goto tr122;
		case 62: goto tr123;
		case 92: goto tr124;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr121;
	goto tr39;
tr31:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st74;
st74:
	if ( ++p == pe )
		goto _test_eof74;
case 74:
#line 3412 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 76: goto tr126;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr125;
tr126:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st75;
st75:
	if ( ++p == pe )
		goto _test_eof75;
case 75:
#line 3430 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 84: goto st76;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr125;
st76:
	if ( ++p == pe )
		goto _test_eof76;
case 76:
	if ( (*p) == 61 )
		goto tr128;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr125;
tr128:
#line 103 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "ALT");
    }
	goto st77;
st77:
	if ( ++p == pe )
		goto _test_eof77;
case 77:
#line 3457 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 60 )
		goto st78;
	goto tr125;
st78:
	if ( ++p == pe )
		goto _test_eof78;
case 78:
	if ( (*p) == 73 )
		goto st79;
	goto tr125;
st79:
	if ( ++p == pe )
		goto _test_eof79;
case 79:
	if ( (*p) == 68 )
		goto st80;
	goto tr125;
st80:
	if ( ++p == pe )
		goto _test_eof80;
case 80:
	if ( (*p) == 61 )
		goto st81;
	goto tr125;
st81:
	if ( ++p == pe )
		goto _test_eof81;
case 81:
	if ( (*p) == 61 )
		goto tr134;
	if ( (*p) < 63 ) {
		if ( (*p) < 45 ) {
			if ( 33 <= (*p) && (*p) <= 43 )
				goto tr134;
		} else if ( (*p) > 47 ) {
			if ( (*p) > 57 ) {
				if ( 58 <= (*p) && (*p) <= 59 )
					goto tr134;
			} else if ( (*p) >= 48 )
				goto tr135;
		} else
			goto tr134;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr135;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr134;
			} else if ( (*p) >= 97 )
				goto tr135;
		} else
			goto tr134;
	} else
		goto tr134;
	goto tr133;
tr134:
#line 139 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st82;
st82:
	if ( ++p == pe )
		goto _test_eof82;
case 82:
#line 3529 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 61 )
		goto st82;
	if ( (*p) < 63 ) {
		if ( (*p) < 45 ) {
			if ( 33 <= (*p) && (*p) <= 43 )
				goto st82;
		} else if ( (*p) > 47 ) {
			if ( (*p) > 57 ) {
				if ( 58 <= (*p) && (*p) <= 59 )
					goto st82;
			} else if ( (*p) >= 48 )
				goto tr137;
		} else
			goto st82;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr137;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto st82;
			} else if ( (*p) >= 97 )
				goto tr137;
		} else
			goto st82;
	} else
		goto st82;
	goto tr133;
tr137:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st83;
tr135:
#line 139 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st83;
st83:
	if ( ++p == pe )
		goto _test_eof83;
case 83:
#line 3583 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 44: goto tr138;
		case 61: goto tr137;
	}
	if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr137;
	} else if ( (*p) >= 33 )
		goto tr137;
	goto tr133;
tr138:
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st84;
st84:
	if ( ++p == pe )
		goto _test_eof84;
case 84:
#line 3604 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 68 )
		goto st85;
	goto tr125;
st85:
	if ( ++p == pe )
		goto _test_eof85;
case 85:
	if ( (*p) == 101 )
		goto st86;
	goto tr125;
st86:
	if ( ++p == pe )
		goto _test_eof86;
case 86:
	if ( (*p) == 115 )
		goto st87;
	goto tr125;
st87:
	if ( ++p == pe )
		goto _test_eof87;
case 87:
	if ( (*p) == 99 )
		goto st88;
	goto tr125;
st88:
	if ( ++p == pe )
		goto _test_eof88;
case 88:
	if ( (*p) == 114 )
		goto st89;
	goto tr125;
st89:
	if ( ++p == pe )
		goto _test_eof89;
case 89:
	if ( (*p) == 105 )
		goto st90;
	goto tr125;
st90:
	if ( ++p == pe )
		goto _test_eof90;
case 90:
	if ( (*p) == 112 )
		goto st91;
	goto tr125;
st91:
	if ( ++p == pe )
		goto _test_eof91;
case 91:
	if ( (*p) == 116 )
		goto st92;
	goto tr125;
st92:
	if ( ++p == pe )
		goto _test_eof92;
case 92:
	if ( (*p) == 105 )
		goto st93;
	goto tr125;
st93:
	if ( ++p == pe )
		goto _test_eof93;
case 93:
	if ( (*p) == 111 )
		goto st94;
	goto tr125;
st94:
	if ( ++p == pe )
		goto _test_eof94;
case 94:
	if ( (*p) == 110 )
		goto st95;
	goto tr125;
st95:
	if ( ++p == pe )
		goto _test_eof95;
case 95:
	if ( (*p) == 61 )
		goto st96;
	goto tr125;
st96:
	if ( ++p == pe )
		goto _test_eof96;
case 96:
	if ( (*p) == 34 )
		goto tr151;
	goto tr125;
tr151:
#line 151 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Description");
    }
	goto st97;
st97:
	if ( ++p == pe )
		goto _test_eof97;
case 97:
#line 3702 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr154;
		case 92: goto tr155;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr153;
	goto tr152;
tr153:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st98;
tr156:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st98;
st98:
	if ( ++p == pe )
		goto _test_eof98;
case 98:
#line 3730 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr157;
		case 92: goto tr158;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr156;
	goto tr152;
tr154:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st99;
tr157:
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st99;
st99:
	if ( ++p == pe )
		goto _test_eof99;
case 99:
#line 3758 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 44: goto st100;
		case 62: goto st114;
	}
	goto tr152;
st100:
	if ( ++p == pe )
		goto _test_eof100;
case 100:
	if ( (*p) == 95 )
		goto tr162;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr162;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr163;
		} else if ( (*p) >= 65 )
			goto tr163;
	} else
		goto tr163;
	goto tr161;
tr162:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st101;
st101:
	if ( ++p == pe )
		goto _test_eof101;
case 101:
#line 3792 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 95 )
		goto st101;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st101;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr165;
		} else if ( (*p) >= 65 )
			goto tr165;
	} else
		goto tr165;
	goto tr161;
tr163:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st102;
tr165:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st102;
st102:
	if ( ++p == pe )
		goto _test_eof102;
case 102:
#line 3827 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr166;
		case 95: goto tr165;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr165;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr165;
		} else if ( (*p) >= 65 )
			goto tr165;
	} else
		goto tr165;
	goto tr161;
tr166:
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st103;
st103:
	if ( ++p == pe )
		goto _test_eof103;
case 103:
#line 3854 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 34 )
		goto st104;
	goto tr125;
st104:
	if ( ++p == pe )
		goto _test_eof104;
case 104:
	switch( (*p) ) {
		case 34: goto tr154;
		case 92: goto tr169;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr168;
	goto tr152;
tr168:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st105;
tr170:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st105;
st105:
	if ( ++p == pe )
		goto _test_eof105;
case 105:
#line 3889 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr157;
		case 92: goto tr171;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr170;
	goto tr152;
tr169:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st106;
tr171:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st106;
st106:
	if ( ++p == pe )
		goto _test_eof106;
case 106:
#line 3917 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr172;
		case 92: goto tr171;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr170;
	goto tr152;
tr172:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st107;
st107:
	if ( ++p == pe )
		goto _test_eof107;
case 107:
#line 3939 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr157;
		case 44: goto tr173;
		case 62: goto tr174;
		case 92: goto tr171;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr170;
	goto tr152;
tr182:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st108;
tr173:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st108;
st108:
	if ( ++p == pe )
		goto _test_eof108;
case 108:
#line 3969 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr157;
		case 47: goto tr170;
		case 92: goto tr171;
		case 95: goto tr176;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr170;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr177;
		} else
			goto tr176;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr177;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr170;
			} else if ( (*p) >= 97 )
				goto tr177;
		} else
			goto tr170;
	} else
		goto tr170;
	goto tr175;
tr176:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st109;
tr178:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st109;
st109:
	if ( ++p == pe )
		goto _test_eof109;
case 109:
#line 4020 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr157;
		case 47: goto tr170;
		case 92: goto tr171;
		case 95: goto tr178;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr170;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr179;
		} else
			goto tr178;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr179;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr170;
			} else if ( (*p) >= 97 )
				goto tr179;
		} else
			goto tr170;
	} else
		goto tr170;
	goto tr175;
tr177:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st110;
tr179:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st110;
st110:
	if ( ++p == pe )
		goto _test_eof110;
case 110:
#line 4071 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr157;
		case 47: goto tr170;
		case 61: goto tr180;
		case 92: goto tr171;
		case 95: goto tr179;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr170;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr170;
		} else
			goto tr179;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr170;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr170;
		} else
			goto tr179;
	} else
		goto tr179;
	goto tr175;
tr180:
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st111;
st111:
	if ( ++p == pe )
		goto _test_eof111;
case 111:
#line 4114 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr181;
		case 92: goto tr171;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr170;
	goto tr152;
tr181:
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st112;
st112:
	if ( ++p == pe )
		goto _test_eof112;
case 112:
#line 4132 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr154;
		case 44: goto tr182;
		case 62: goto tr183;
		case 92: goto tr169;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr168;
	goto tr152;
tr183:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st113;
tr174:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st113;
st113:
	if ( ++p == pe )
		goto _test_eof113;
case 113:
#line 4162 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 10: goto tr55;
		case 13: goto tr56;
		case 34: goto tr157;
		case 92: goto tr171;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr170;
	goto tr152;
st114:
	if ( ++p == pe )
		goto _test_eof114;
case 114:
	switch( (*p) ) {
		case 10: goto tr55;
		case 13: goto tr56;
	}
	goto tr125;
tr155:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st115;
tr158:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st115;
st115:
	if ( ++p == pe )
		goto _test_eof115;
case 115:
#line 4201 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr184;
		case 92: goto tr158;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr156;
	goto tr152;
tr184:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st116;
st116:
	if ( ++p == pe )
		goto _test_eof116;
case 116:
#line 4223 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr157;
		case 44: goto tr185;
		case 62: goto tr186;
		case 92: goto tr158;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr156;
	goto tr152;
tr185:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st117;
st117:
	if ( ++p == pe )
		goto _test_eof117;
case 117:
#line 4243 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr157;
		case 47: goto tr156;
		case 92: goto tr158;
		case 95: goto tr188;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr156;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr189;
		} else
			goto tr188;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr189;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr156;
			} else if ( (*p) >= 97 )
				goto tr189;
		} else
			goto tr156;
	} else
		goto tr156;
	goto tr187;
tr190:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st118;
tr188:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st118;
st118:
	if ( ++p == pe )
		goto _test_eof118;
case 118:
#line 4294 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr157;
		case 47: goto tr156;
		case 92: goto tr158;
		case 95: goto tr190;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr156;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr191;
		} else
			goto tr190;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr191;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr156;
			} else if ( (*p) >= 97 )
				goto tr191;
		} else
			goto tr156;
	} else
		goto tr156;
	goto tr187;
tr191:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st119;
tr189:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st119;
st119:
	if ( ++p == pe )
		goto _test_eof119;
case 119:
#line 4345 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr157;
		case 47: goto tr156;
		case 61: goto tr192;
		case 92: goto tr158;
		case 95: goto tr191;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr156;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr156;
		} else
			goto tr191;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr156;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr156;
		} else
			goto tr191;
	} else
		goto tr191;
	goto tr187;
tr192:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st120;
st120:
	if ( ++p == pe )
		goto _test_eof120;
case 120:
#line 4388 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr181;
		case 92: goto tr158;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr156;
	goto tr152;
tr186:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st121;
st121:
	if ( ++p == pe )
		goto _test_eof121;
case 121:
#line 4406 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 10: goto tr55;
		case 13: goto tr56;
		case 34: goto tr157;
		case 92: goto tr158;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr156;
	goto tr152;
tr32:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st122;
st122:
	if ( ++p == pe )
		goto _test_eof122;
case 122:
#line 4430 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 73: goto tr194;
		case 79: goto tr195;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr193;
tr194:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st123;
st123:
	if ( ++p == pe )
		goto _test_eof123;
case 123:
#line 4449 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 76: goto tr197;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr196;
tr197:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st124;
st124:
	if ( ++p == pe )
		goto _test_eof124;
case 124:
#line 4467 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 84: goto tr198;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr196;
tr198:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st125;
st125:
	if ( ++p == pe )
		goto _test_eof125;
case 125:
#line 4485 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 69: goto tr199;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr196;
tr199:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st126;
st126:
	if ( ++p == pe )
		goto _test_eof126;
case 126:
#line 4503 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 82: goto st127;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr196;
st127:
	if ( ++p == pe )
		goto _test_eof127;
case 127:
	if ( (*p) == 61 )
		goto tr201;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr196;
tr201:
#line 115 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "FILTER");
    }
	goto st128;
st128:
	if ( ++p == pe )
		goto _test_eof128;
case 128:
#line 4530 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 60 )
		goto st129;
	goto tr196;
st129:
	if ( ++p == pe )
		goto _test_eof129;
case 129:
	if ( (*p) == 73 )
		goto st130;
	goto tr196;
st130:
	if ( ++p == pe )
		goto _test_eof130;
case 130:
	if ( (*p) == 68 )
		goto st131;
	goto tr196;
st131:
	if ( ++p == pe )
		goto _test_eof131;
case 131:
	if ( (*p) == 61 )
		goto st132;
	goto tr196;
st132:
	if ( ++p == pe )
		goto _test_eof132;
case 132:
	if ( (*p) == 95 )
		goto tr207;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr207;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr208;
		} else if ( (*p) >= 65 )
			goto tr208;
	} else
		goto tr208;
	goto tr206;
tr207:
#line 139 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st133;
st133:
	if ( ++p == pe )
		goto _test_eof133;
case 133:
#line 4587 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 95 )
		goto st133;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st133;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr210;
		} else if ( (*p) >= 65 )
			goto tr210;
	} else
		goto tr210;
	goto tr206;
tr210:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st134;
tr208:
#line 139 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st134;
st134:
	if ( ++p == pe )
		goto _test_eof134;
case 134:
#line 4626 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 44: goto tr211;
		case 95: goto tr210;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr210;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr210;
		} else if ( (*p) >= 65 )
			goto tr210;
	} else
		goto tr210;
	goto tr206;
tr211:
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st135;
st135:
	if ( ++p == pe )
		goto _test_eof135;
case 135:
#line 4653 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 68 )
		goto st136;
	goto tr196;
st136:
	if ( ++p == pe )
		goto _test_eof136;
case 136:
	if ( (*p) == 101 )
		goto st137;
	goto tr196;
st137:
	if ( ++p == pe )
		goto _test_eof137;
case 137:
	if ( (*p) == 115 )
		goto st138;
	goto tr196;
st138:
	if ( ++p == pe )
		goto _test_eof138;
case 138:
	if ( (*p) == 99 )
		goto st139;
	goto tr196;
st139:
	if ( ++p == pe )
		goto _test_eof139;
case 139:
	if ( (*p) == 114 )
		goto st140;
	goto tr196;
st140:
	if ( ++p == pe )
		goto _test_eof140;
case 140:
	if ( (*p) == 105 )
		goto st141;
	goto tr196;
st141:
	if ( ++p == pe )
		goto _test_eof141;
case 141:
	if ( (*p) == 112 )
		goto st142;
	goto tr196;
st142:
	if ( ++p == pe )
		goto _test_eof142;
case 142:
	if ( (*p) == 116 )
		goto st143;
	goto tr196;
st143:
	if ( ++p == pe )
		goto _test_eof143;
case 143:
	if ( (*p) == 105 )
		goto st144;
	goto tr196;
st144:
	if ( ++p == pe )
		goto _test_eof144;
case 144:
	if ( (*p) == 111 )
		goto st145;
	goto tr196;
st145:
	if ( ++p == pe )
		goto _test_eof145;
case 145:
	if ( (*p) == 110 )
		goto st146;
	goto tr196;
st146:
	if ( ++p == pe )
		goto _test_eof146;
case 146:
	if ( (*p) == 61 )
		goto st147;
	goto tr196;
st147:
	if ( ++p == pe )
		goto _test_eof147;
case 147:
	if ( (*p) == 34 )
		goto tr224;
	goto tr196;
tr224:
#line 151 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Description");
    }
	goto st148;
st148:
	if ( ++p == pe )
		goto _test_eof148;
case 148:
#line 4751 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr227;
		case 92: goto tr228;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr226;
	goto tr225;
tr226:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st149;
tr229:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st149;
st149:
	if ( ++p == pe )
		goto _test_eof149;
case 149:
#line 4779 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr230;
		case 92: goto tr231;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr229;
	goto tr225;
tr227:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st150;
tr230:
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st150;
st150:
	if ( ++p == pe )
		goto _test_eof150;
case 150:
#line 4807 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 44: goto st151;
		case 62: goto st165;
	}
	goto tr225;
st151:
	if ( ++p == pe )
		goto _test_eof151;
case 151:
	if ( (*p) == 95 )
		goto tr234;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr234;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr235;
		} else if ( (*p) >= 65 )
			goto tr235;
	} else
		goto tr235;
	goto tr206;
tr234:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st152;
st152:
	if ( ++p == pe )
		goto _test_eof152;
case 152:
#line 4841 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 95 )
		goto st152;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st152;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr237;
		} else if ( (*p) >= 65 )
			goto tr237;
	} else
		goto tr237;
	goto tr206;
tr235:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st153;
tr237:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st153;
st153:
	if ( ++p == pe )
		goto _test_eof153;
case 153:
#line 4876 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr238;
		case 95: goto tr237;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr237;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr237;
		} else if ( (*p) >= 65 )
			goto tr237;
	} else
		goto tr237;
	goto tr206;
tr238:
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st154;
st154:
	if ( ++p == pe )
		goto _test_eof154;
case 154:
#line 4903 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 34 )
		goto st155;
	goto tr196;
st155:
	if ( ++p == pe )
		goto _test_eof155;
case 155:
	switch( (*p) ) {
		case 34: goto tr227;
		case 92: goto tr241;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr240;
	goto tr225;
tr240:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st156;
tr242:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st156;
st156:
	if ( ++p == pe )
		goto _test_eof156;
case 156:
#line 4938 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr230;
		case 92: goto tr243;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr242;
	goto tr225;
tr241:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st157;
tr243:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st157;
st157:
	if ( ++p == pe )
		goto _test_eof157;
case 157:
#line 4966 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr244;
		case 92: goto tr243;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr242;
	goto tr225;
tr244:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st158;
st158:
	if ( ++p == pe )
		goto _test_eof158;
case 158:
#line 4988 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr230;
		case 44: goto tr245;
		case 62: goto tr246;
		case 92: goto tr243;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr242;
	goto tr225;
tr254:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st159;
tr245:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st159;
st159:
	if ( ++p == pe )
		goto _test_eof159;
case 159:
#line 5018 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr230;
		case 47: goto tr242;
		case 92: goto tr243;
		case 95: goto tr248;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr242;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr249;
		} else
			goto tr248;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr249;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr242;
			} else if ( (*p) >= 97 )
				goto tr249;
		} else
			goto tr242;
	} else
		goto tr242;
	goto tr247;
tr248:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st160;
tr250:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st160;
st160:
	if ( ++p == pe )
		goto _test_eof160;
case 160:
#line 5069 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr230;
		case 47: goto tr242;
		case 92: goto tr243;
		case 95: goto tr250;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr242;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr251;
		} else
			goto tr250;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr251;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr242;
			} else if ( (*p) >= 97 )
				goto tr251;
		} else
			goto tr242;
	} else
		goto tr242;
	goto tr247;
tr249:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st161;
tr251:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st161;
st161:
	if ( ++p == pe )
		goto _test_eof161;
case 161:
#line 5120 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr230;
		case 47: goto tr242;
		case 61: goto tr252;
		case 92: goto tr243;
		case 95: goto tr251;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr242;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr242;
		} else
			goto tr251;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr242;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr242;
		} else
			goto tr251;
	} else
		goto tr251;
	goto tr247;
tr252:
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st162;
st162:
	if ( ++p == pe )
		goto _test_eof162;
case 162:
#line 5163 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr253;
		case 92: goto tr243;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr242;
	goto tr225;
tr253:
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st163;
st163:
	if ( ++p == pe )
		goto _test_eof163;
case 163:
#line 5181 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr227;
		case 44: goto tr254;
		case 62: goto tr255;
		case 92: goto tr241;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr240;
	goto tr225;
tr255:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st164;
tr246:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st164;
st164:
	if ( ++p == pe )
		goto _test_eof164;
case 164:
#line 5211 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 10: goto tr55;
		case 13: goto tr56;
		case 34: goto tr230;
		case 92: goto tr243;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr242;
	goto tr225;
st165:
	if ( ++p == pe )
		goto _test_eof165;
case 165:
	switch( (*p) ) {
		case 10: goto tr55;
		case 13: goto tr56;
	}
	goto tr196;
tr228:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st166;
tr231:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st166;
st166:
	if ( ++p == pe )
		goto _test_eof166;
case 166:
#line 5250 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr256;
		case 92: goto tr231;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr229;
	goto tr225;
tr256:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st167;
st167:
	if ( ++p == pe )
		goto _test_eof167;
case 167:
#line 5272 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr230;
		case 44: goto tr257;
		case 62: goto tr258;
		case 92: goto tr231;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr229;
	goto tr225;
tr257:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st168;
st168:
	if ( ++p == pe )
		goto _test_eof168;
case 168:
#line 5292 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr230;
		case 47: goto tr229;
		case 92: goto tr231;
		case 95: goto tr260;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr229;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr261;
		} else
			goto tr260;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr261;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr229;
			} else if ( (*p) >= 97 )
				goto tr261;
		} else
			goto tr229;
	} else
		goto tr229;
	goto tr259;
tr262:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st169;
tr260:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st169;
st169:
	if ( ++p == pe )
		goto _test_eof169;
case 169:
#line 5343 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr230;
		case 47: goto tr229;
		case 92: goto tr231;
		case 95: goto tr262;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr229;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr263;
		} else
			goto tr262;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr263;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr229;
			} else if ( (*p) >= 97 )
				goto tr263;
		} else
			goto tr229;
	} else
		goto tr229;
	goto tr259;
tr263:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st170;
tr261:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st170;
st170:
	if ( ++p == pe )
		goto _test_eof170;
case 170:
#line 5394 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr230;
		case 47: goto tr229;
		case 61: goto tr264;
		case 92: goto tr231;
		case 95: goto tr263;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr229;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr229;
		} else
			goto tr263;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr229;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr229;
		} else
			goto tr263;
	} else
		goto tr263;
	goto tr259;
tr264:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st171;
st171:
	if ( ++p == pe )
		goto _test_eof171;
case 171:
#line 5437 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr253;
		case 92: goto tr231;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr229;
	goto tr225;
tr258:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st172;
st172:
	if ( ++p == pe )
		goto _test_eof172;
case 172:
#line 5455 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 10: goto tr55;
		case 13: goto tr56;
		case 34: goto tr230;
		case 92: goto tr231;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr229;
	goto tr225;
tr195:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st173;
st173:
	if ( ++p == pe )
		goto _test_eof173;
case 173:
#line 5475 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 82: goto tr266;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr265;
tr266:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st174;
st174:
	if ( ++p == pe )
		goto _test_eof174;
case 174:
#line 5493 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 77: goto tr267;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr265;
tr267:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st175;
st175:
	if ( ++p == pe )
		goto _test_eof175;
case 175:
#line 5511 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 65: goto tr268;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr265;
tr268:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st176;
st176:
	if ( ++p == pe )
		goto _test_eof176;
case 176:
#line 5529 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 84: goto st177;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr265;
st177:
	if ( ++p == pe )
		goto _test_eof177;
case 177:
	if ( (*p) == 61 )
		goto tr270;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr265;
tr270:
#line 119 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "FORMAT");
    }
	goto st178;
st178:
	if ( ++p == pe )
		goto _test_eof178;
case 178:
#line 5556 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 60 )
		goto st179;
	goto tr265;
st179:
	if ( ++p == pe )
		goto _test_eof179;
case 179:
	if ( (*p) == 73 )
		goto st180;
	goto tr265;
st180:
	if ( ++p == pe )
		goto _test_eof180;
case 180:
	if ( (*p) == 68 )
		goto st181;
	goto tr265;
st181:
	if ( ++p == pe )
		goto _test_eof181;
case 181:
	if ( (*p) == 61 )
		goto st182;
	goto tr265;
st182:
	if ( ++p == pe )
		goto _test_eof182;
case 182:
	if ( (*p) == 95 )
		goto tr276;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr276;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr277;
		} else if ( (*p) >= 65 )
			goto tr277;
	} else
		goto tr277;
	goto tr275;
tr276:
#line 139 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st183;
st183:
	if ( ++p == pe )
		goto _test_eof183;
case 183:
#line 5613 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 95 )
		goto st183;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st183;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr279;
		} else if ( (*p) >= 65 )
			goto tr279;
	} else
		goto tr279;
	goto tr275;
tr279:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st184;
tr277:
#line 139 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st184;
st184:
	if ( ++p == pe )
		goto _test_eof184;
case 184:
#line 5652 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 44: goto tr280;
		case 95: goto tr279;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr279;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr279;
		} else if ( (*p) >= 65 )
			goto tr279;
	} else
		goto tr279;
	goto tr275;
tr280:
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st185;
st185:
	if ( ++p == pe )
		goto _test_eof185;
case 185:
#line 5679 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 78 )
		goto st186;
	goto tr265;
st186:
	if ( ++p == pe )
		goto _test_eof186;
case 186:
	if ( (*p) == 117 )
		goto st187;
	goto tr265;
st187:
	if ( ++p == pe )
		goto _test_eof187;
case 187:
	if ( (*p) == 109 )
		goto st188;
	goto tr265;
st188:
	if ( ++p == pe )
		goto _test_eof188;
case 188:
	if ( (*p) == 98 )
		goto st189;
	goto tr265;
st189:
	if ( ++p == pe )
		goto _test_eof189;
case 189:
	if ( (*p) == 101 )
		goto st190;
	goto tr265;
st190:
	if ( ++p == pe )
		goto _test_eof190;
case 190:
	if ( (*p) == 114 )
		goto st191;
	goto tr265;
st191:
	if ( ++p == pe )
		goto _test_eof191;
case 191:
	if ( (*p) == 61 )
		goto st192;
	goto tr265;
st192:
	if ( ++p == pe )
		goto _test_eof192;
case 192:
	switch( (*p) ) {
		case 46: goto tr289;
		case 65: goto tr289;
		case 71: goto tr289;
		case 82: goto tr289;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr290;
	goto tr288;
tr289:
#line 143 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Number");
    }
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st193;
st193:
	if ( ++p == pe )
		goto _test_eof193;
case 193:
#line 5756 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 44 )
		goto tr291;
	goto tr288;
tr291:
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st194;
st194:
	if ( ++p == pe )
		goto _test_eof194;
case 194:
#line 5770 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 84 )
		goto st195;
	goto tr265;
st195:
	if ( ++p == pe )
		goto _test_eof195;
case 195:
	if ( (*p) == 121 )
		goto st196;
	goto tr265;
st196:
	if ( ++p == pe )
		goto _test_eof196;
case 196:
	if ( (*p) == 112 )
		goto st197;
	goto tr265;
st197:
	if ( ++p == pe )
		goto _test_eof197;
case 197:
	if ( (*p) == 101 )
		goto st198;
	goto tr265;
st198:
	if ( ++p == pe )
		goto _test_eof198;
case 198:
	if ( (*p) == 61 )
		goto st199;
	goto tr265;
st199:
	if ( ++p == pe )
		goto _test_eof199;
case 199:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr298;
	} else if ( (*p) >= 65 )
		goto tr298;
	goto tr297;
tr300:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st200;
tr298:
#line 147 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Type");
    }
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st200;
st200:
	if ( ++p == pe )
		goto _test_eof200;
case 200:
#line 5836 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 44 )
		goto tr299;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr300;
	} else if ( (*p) >= 65 )
		goto tr300;
	goto tr297;
tr299:
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st201;
st201:
	if ( ++p == pe )
		goto _test_eof201;
case 201:
#line 5855 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 68 )
		goto st202;
	goto tr265;
st202:
	if ( ++p == pe )
		goto _test_eof202;
case 202:
	if ( (*p) == 101 )
		goto st203;
	goto tr265;
st203:
	if ( ++p == pe )
		goto _test_eof203;
case 203:
	if ( (*p) == 115 )
		goto st204;
	goto tr265;
st204:
	if ( ++p == pe )
		goto _test_eof204;
case 204:
	if ( (*p) == 99 )
		goto st205;
	goto tr265;
st205:
	if ( ++p == pe )
		goto _test_eof205;
case 205:
	if ( (*p) == 114 )
		goto st206;
	goto tr265;
st206:
	if ( ++p == pe )
		goto _test_eof206;
case 206:
	if ( (*p) == 105 )
		goto st207;
	goto tr265;
st207:
	if ( ++p == pe )
		goto _test_eof207;
case 207:
	if ( (*p) == 112 )
		goto st208;
	goto tr265;
st208:
	if ( ++p == pe )
		goto _test_eof208;
case 208:
	if ( (*p) == 116 )
		goto st209;
	goto tr265;
st209:
	if ( ++p == pe )
		goto _test_eof209;
case 209:
	if ( (*p) == 105 )
		goto st210;
	goto tr265;
st210:
	if ( ++p == pe )
		goto _test_eof210;
case 210:
	if ( (*p) == 111 )
		goto st211;
	goto tr265;
st211:
	if ( ++p == pe )
		goto _test_eof211;
case 211:
	if ( (*p) == 110 )
		goto st212;
	goto tr265;
st212:
	if ( ++p == pe )
		goto _test_eof212;
case 212:
	if ( (*p) == 61 )
		goto st213;
	goto tr265;
st213:
	if ( ++p == pe )
		goto _test_eof213;
case 213:
	if ( (*p) == 34 )
		goto tr313;
	goto tr265;
tr313:
#line 151 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Description");
    }
	goto st214;
st214:
	if ( ++p == pe )
		goto _test_eof214;
case 214:
#line 5953 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr316;
		case 92: goto tr317;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr315;
	goto tr314;
tr315:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st215;
tr318:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st215;
st215:
	if ( ++p == pe )
		goto _test_eof215;
case 215:
#line 5981 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr319;
		case 92: goto tr320;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr318;
	goto tr314;
tr316:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st216;
tr319:
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st216;
st216:
	if ( ++p == pe )
		goto _test_eof216;
case 216:
#line 6009 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 44: goto st217;
		case 62: goto st231;
	}
	goto tr314;
st217:
	if ( ++p == pe )
		goto _test_eof217;
case 217:
	if ( (*p) == 95 )
		goto tr323;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr323;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr324;
		} else if ( (*p) >= 65 )
			goto tr324;
	} else
		goto tr324;
	goto tr275;
tr323:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st218;
st218:
	if ( ++p == pe )
		goto _test_eof218;
case 218:
#line 6043 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 95 )
		goto st218;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st218;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr326;
		} else if ( (*p) >= 65 )
			goto tr326;
	} else
		goto tr326;
	goto tr275;
tr324:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st219;
tr326:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st219;
st219:
	if ( ++p == pe )
		goto _test_eof219;
case 219:
#line 6078 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr327;
		case 95: goto tr326;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr326;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr326;
		} else if ( (*p) >= 65 )
			goto tr326;
	} else
		goto tr326;
	goto tr275;
tr327:
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st220;
st220:
	if ( ++p == pe )
		goto _test_eof220;
case 220:
#line 6105 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 34 )
		goto st221;
	goto tr265;
st221:
	if ( ++p == pe )
		goto _test_eof221;
case 221:
	switch( (*p) ) {
		case 34: goto tr316;
		case 92: goto tr330;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr329;
	goto tr314;
tr329:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st222;
tr331:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st222;
st222:
	if ( ++p == pe )
		goto _test_eof222;
case 222:
#line 6140 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr319;
		case 92: goto tr332;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr331;
	goto tr314;
tr330:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st223;
tr332:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st223;
st223:
	if ( ++p == pe )
		goto _test_eof223;
case 223:
#line 6168 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr333;
		case 92: goto tr332;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr331;
	goto tr314;
tr333:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st224;
st224:
	if ( ++p == pe )
		goto _test_eof224;
case 224:
#line 6190 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr319;
		case 44: goto tr334;
		case 62: goto tr335;
		case 92: goto tr332;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr331;
	goto tr314;
tr343:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st225;
tr334:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st225;
st225:
	if ( ++p == pe )
		goto _test_eof225;
case 225:
#line 6220 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr319;
		case 47: goto tr331;
		case 92: goto tr332;
		case 95: goto tr337;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr331;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr338;
		} else
			goto tr337;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr338;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr331;
			} else if ( (*p) >= 97 )
				goto tr338;
		} else
			goto tr331;
	} else
		goto tr331;
	goto tr336;
tr337:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st226;
tr339:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st226;
st226:
	if ( ++p == pe )
		goto _test_eof226;
case 226:
#line 6271 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr319;
		case 47: goto tr331;
		case 92: goto tr332;
		case 95: goto tr339;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr331;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr340;
		} else
			goto tr339;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr340;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr331;
			} else if ( (*p) >= 97 )
				goto tr340;
		} else
			goto tr331;
	} else
		goto tr331;
	goto tr336;
tr338:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st227;
tr340:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st227;
st227:
	if ( ++p == pe )
		goto _test_eof227;
case 227:
#line 6322 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr319;
		case 47: goto tr331;
		case 61: goto tr341;
		case 92: goto tr332;
		case 95: goto tr340;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr331;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr331;
		} else
			goto tr340;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr331;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr331;
		} else
			goto tr340;
	} else
		goto tr340;
	goto tr336;
tr341:
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st228;
st228:
	if ( ++p == pe )
		goto _test_eof228;
case 228:
#line 6365 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr342;
		case 92: goto tr332;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr331;
	goto tr314;
tr342:
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st229;
st229:
	if ( ++p == pe )
		goto _test_eof229;
case 229:
#line 6383 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr316;
		case 44: goto tr343;
		case 62: goto tr344;
		case 92: goto tr330;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr329;
	goto tr314;
tr344:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st230;
tr335:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st230;
st230:
	if ( ++p == pe )
		goto _test_eof230;
case 230:
#line 6413 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 10: goto tr55;
		case 13: goto tr56;
		case 34: goto tr319;
		case 92: goto tr332;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr331;
	goto tr314;
st231:
	if ( ++p == pe )
		goto _test_eof231;
case 231:
	switch( (*p) ) {
		case 10: goto tr55;
		case 13: goto tr56;
	}
	goto tr265;
tr317:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st232;
tr320:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st232;
st232:
	if ( ++p == pe )
		goto _test_eof232;
case 232:
#line 6452 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr345;
		case 92: goto tr320;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr318;
	goto tr314;
tr345:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st233;
st233:
	if ( ++p == pe )
		goto _test_eof233;
case 233:
#line 6474 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr319;
		case 44: goto tr346;
		case 62: goto tr347;
		case 92: goto tr320;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr318;
	goto tr314;
tr346:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st234;
st234:
	if ( ++p == pe )
		goto _test_eof234;
case 234:
#line 6494 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr319;
		case 47: goto tr318;
		case 92: goto tr320;
		case 95: goto tr349;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr318;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr350;
		} else
			goto tr349;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr350;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr318;
			} else if ( (*p) >= 97 )
				goto tr350;
		} else
			goto tr318;
	} else
		goto tr318;
	goto tr348;
tr351:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st235;
tr349:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st235;
st235:
	if ( ++p == pe )
		goto _test_eof235;
case 235:
#line 6545 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr319;
		case 47: goto tr318;
		case 92: goto tr320;
		case 95: goto tr351;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr318;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr352;
		} else
			goto tr351;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr352;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr318;
			} else if ( (*p) >= 97 )
				goto tr352;
		} else
			goto tr318;
	} else
		goto tr318;
	goto tr348;
tr352:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st236;
tr350:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st236;
st236:
	if ( ++p == pe )
		goto _test_eof236;
case 236:
#line 6596 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr319;
		case 47: goto tr318;
		case 61: goto tr353;
		case 92: goto tr320;
		case 95: goto tr352;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr318;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr318;
		} else
			goto tr352;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr318;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr318;
		} else
			goto tr352;
	} else
		goto tr352;
	goto tr348;
tr353:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st237;
st237:
	if ( ++p == pe )
		goto _test_eof237;
case 237:
#line 6639 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr342;
		case 92: goto tr320;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr318;
	goto tr314;
tr347:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st238;
st238:
	if ( ++p == pe )
		goto _test_eof238;
case 238:
#line 6657 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 10: goto tr55;
		case 13: goto tr56;
		case 34: goto tr319;
		case 92: goto tr320;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr318;
	goto tr314;
tr354:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st239;
tr290:
#line 143 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Number");
    }
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st239;
st239:
	if ( ++p == pe )
		goto _test_eof239;
case 239:
#line 6691 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 44 )
		goto tr291;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr354;
	goto tr288;
tr33:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st240;
st240:
	if ( ++p == pe )
		goto _test_eof240;
case 240:
#line 6711 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 78: goto tr356;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr355;
tr356:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st241;
st241:
	if ( ++p == pe )
		goto _test_eof241;
case 241:
#line 6729 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 70: goto tr357;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr355;
tr357:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st242;
st242:
	if ( ++p == pe )
		goto _test_eof242;
case 242:
#line 6747 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 79: goto st243;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr355;
st243:
	if ( ++p == pe )
		goto _test_eof243;
case 243:
	if ( (*p) == 61 )
		goto tr359;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr355;
tr359:
#line 123 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "INFO");
    }
	goto st244;
st244:
	if ( ++p == pe )
		goto _test_eof244;
case 244:
#line 6774 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 60 )
		goto st245;
	goto tr355;
st245:
	if ( ++p == pe )
		goto _test_eof245;
case 245:
	if ( (*p) == 73 )
		goto st246;
	goto tr355;
st246:
	if ( ++p == pe )
		goto _test_eof246;
case 246:
	if ( (*p) == 68 )
		goto st247;
	goto tr355;
st247:
	if ( ++p == pe )
		goto _test_eof247;
case 247:
	if ( (*p) == 61 )
		goto st248;
	goto tr355;
st248:
	if ( ++p == pe )
		goto _test_eof248;
case 248:
	if ( (*p) == 95 )
		goto tr365;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr365;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr366;
		} else if ( (*p) >= 65 )
			goto tr366;
	} else
		goto tr366;
	goto tr364;
tr365:
#line 139 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st249;
st249:
	if ( ++p == pe )
		goto _test_eof249;
case 249:
#line 6831 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 95 )
		goto st249;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st249;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr368;
		} else if ( (*p) >= 65 )
			goto tr368;
	} else
		goto tr368;
	goto tr364;
tr368:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st250;
tr366:
#line 139 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st250;
st250:
	if ( ++p == pe )
		goto _test_eof250;
case 250:
#line 6870 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 44: goto tr369;
		case 95: goto tr368;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr368;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr368;
		} else if ( (*p) >= 65 )
			goto tr368;
	} else
		goto tr368;
	goto tr364;
tr369:
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st251;
st251:
	if ( ++p == pe )
		goto _test_eof251;
case 251:
#line 6897 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 78 )
		goto st252;
	goto tr355;
st252:
	if ( ++p == pe )
		goto _test_eof252;
case 252:
	if ( (*p) == 117 )
		goto st253;
	goto tr355;
st253:
	if ( ++p == pe )
		goto _test_eof253;
case 253:
	if ( (*p) == 109 )
		goto st254;
	goto tr355;
st254:
	if ( ++p == pe )
		goto _test_eof254;
case 254:
	if ( (*p) == 98 )
		goto st255;
	goto tr355;
st255:
	if ( ++p == pe )
		goto _test_eof255;
case 255:
	if ( (*p) == 101 )
		goto st256;
	goto tr355;
st256:
	if ( ++p == pe )
		goto _test_eof256;
case 256:
	if ( (*p) == 114 )
		goto st257;
	goto tr355;
st257:
	if ( ++p == pe )
		goto _test_eof257;
case 257:
	if ( (*p) == 61 )
		goto st258;
	goto tr355;
st258:
	if ( ++p == pe )
		goto _test_eof258;
case 258:
	switch( (*p) ) {
		case 46: goto tr378;
		case 65: goto tr378;
		case 71: goto tr378;
		case 82: goto tr378;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr379;
	goto tr377;
tr378:
#line 143 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Number");
    }
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st259;
st259:
	if ( ++p == pe )
		goto _test_eof259;
case 259:
#line 6974 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 44 )
		goto tr380;
	goto tr377;
tr380:
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st260;
st260:
	if ( ++p == pe )
		goto _test_eof260;
case 260:
#line 6988 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 84 )
		goto st261;
	goto tr355;
st261:
	if ( ++p == pe )
		goto _test_eof261;
case 261:
	if ( (*p) == 121 )
		goto st262;
	goto tr355;
st262:
	if ( ++p == pe )
		goto _test_eof262;
case 262:
	if ( (*p) == 112 )
		goto st263;
	goto tr355;
st263:
	if ( ++p == pe )
		goto _test_eof263;
case 263:
	if ( (*p) == 101 )
		goto st264;
	goto tr355;
st264:
	if ( ++p == pe )
		goto _test_eof264;
case 264:
	if ( (*p) == 61 )
		goto st265;
	goto tr355;
st265:
	if ( ++p == pe )
		goto _test_eof265;
case 265:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr387;
	} else if ( (*p) >= 65 )
		goto tr387;
	goto tr386;
tr389:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st266;
tr387:
#line 147 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Type");
    }
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st266;
st266:
	if ( ++p == pe )
		goto _test_eof266;
case 266:
#line 7054 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 44 )
		goto tr388;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr389;
	} else if ( (*p) >= 65 )
		goto tr389;
	goto tr386;
tr388:
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st267;
st267:
	if ( ++p == pe )
		goto _test_eof267;
case 267:
#line 7073 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 68 )
		goto st268;
	goto tr355;
st268:
	if ( ++p == pe )
		goto _test_eof268;
case 268:
	if ( (*p) == 101 )
		goto st269;
	goto tr355;
st269:
	if ( ++p == pe )
		goto _test_eof269;
case 269:
	if ( (*p) == 115 )
		goto st270;
	goto tr355;
st270:
	if ( ++p == pe )
		goto _test_eof270;
case 270:
	if ( (*p) == 99 )
		goto st271;
	goto tr355;
st271:
	if ( ++p == pe )
		goto _test_eof271;
case 271:
	if ( (*p) == 114 )
		goto st272;
	goto tr355;
st272:
	if ( ++p == pe )
		goto _test_eof272;
case 272:
	if ( (*p) == 105 )
		goto st273;
	goto tr355;
st273:
	if ( ++p == pe )
		goto _test_eof273;
case 273:
	if ( (*p) == 112 )
		goto st274;
	goto tr355;
st274:
	if ( ++p == pe )
		goto _test_eof274;
case 274:
	if ( (*p) == 116 )
		goto st275;
	goto tr355;
st275:
	if ( ++p == pe )
		goto _test_eof275;
case 275:
	if ( (*p) == 105 )
		goto st276;
	goto tr355;
st276:
	if ( ++p == pe )
		goto _test_eof276;
case 276:
	if ( (*p) == 111 )
		goto st277;
	goto tr355;
st277:
	if ( ++p == pe )
		goto _test_eof277;
case 277:
	if ( (*p) == 110 )
		goto st278;
	goto tr355;
st278:
	if ( ++p == pe )
		goto _test_eof278;
case 278:
	if ( (*p) == 61 )
		goto st279;
	goto tr355;
st279:
	if ( ++p == pe )
		goto _test_eof279;
case 279:
	if ( (*p) == 34 )
		goto tr402;
	goto tr355;
tr402:
#line 151 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Description");
    }
	goto st280;
st280:
	if ( ++p == pe )
		goto _test_eof280;
case 280:
#line 7171 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr405;
		case 92: goto tr406;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr404;
	goto tr403;
tr404:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st281;
tr407:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st281;
st281:
	if ( ++p == pe )
		goto _test_eof281;
case 281:
#line 7199 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr408;
		case 92: goto tr409;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr407;
	goto tr403;
tr405:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st282;
tr408:
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st282;
st282:
	if ( ++p == pe )
		goto _test_eof282;
case 282:
#line 7227 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 44: goto st283;
		case 62: goto st297;
	}
	goto tr403;
st283:
	if ( ++p == pe )
		goto _test_eof283;
case 283:
	if ( (*p) == 95 )
		goto tr412;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr412;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr413;
		} else if ( (*p) >= 65 )
			goto tr413;
	} else
		goto tr413;
	goto tr364;
tr412:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st284;
st284:
	if ( ++p == pe )
		goto _test_eof284;
case 284:
#line 7261 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 95 )
		goto st284;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st284;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr415;
		} else if ( (*p) >= 65 )
			goto tr415;
	} else
		goto tr415;
	goto tr364;
tr413:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st285;
tr415:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st285;
st285:
	if ( ++p == pe )
		goto _test_eof285;
case 285:
#line 7296 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr416;
		case 95: goto tr415;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr415;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr415;
		} else if ( (*p) >= 65 )
			goto tr415;
	} else
		goto tr415;
	goto tr364;
tr416:
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st286;
st286:
	if ( ++p == pe )
		goto _test_eof286;
case 286:
#line 7323 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 34 )
		goto st287;
	goto tr355;
st287:
	if ( ++p == pe )
		goto _test_eof287;
case 287:
	switch( (*p) ) {
		case 34: goto tr405;
		case 92: goto tr419;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr418;
	goto tr403;
tr418:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st288;
tr420:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st288;
st288:
	if ( ++p == pe )
		goto _test_eof288;
case 288:
#line 7358 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr408;
		case 92: goto tr421;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr420;
	goto tr403;
tr419:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st289;
tr421:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st289;
st289:
	if ( ++p == pe )
		goto _test_eof289;
case 289:
#line 7386 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr422;
		case 92: goto tr421;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr420;
	goto tr403;
tr422:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st290;
st290:
	if ( ++p == pe )
		goto _test_eof290;
case 290:
#line 7408 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr408;
		case 44: goto tr423;
		case 62: goto tr424;
		case 92: goto tr421;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr420;
	goto tr403;
tr432:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st291;
tr423:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st291;
st291:
	if ( ++p == pe )
		goto _test_eof291;
case 291:
#line 7438 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr408;
		case 47: goto tr420;
		case 92: goto tr421;
		case 95: goto tr426;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr420;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr427;
		} else
			goto tr426;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr427;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr420;
			} else if ( (*p) >= 97 )
				goto tr427;
		} else
			goto tr420;
	} else
		goto tr420;
	goto tr425;
tr426:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st292;
tr428:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st292;
st292:
	if ( ++p == pe )
		goto _test_eof292;
case 292:
#line 7489 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr408;
		case 47: goto tr420;
		case 92: goto tr421;
		case 95: goto tr428;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr420;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr429;
		} else
			goto tr428;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr429;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr420;
			} else if ( (*p) >= 97 )
				goto tr429;
		} else
			goto tr420;
	} else
		goto tr420;
	goto tr425;
tr427:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st293;
tr429:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st293;
st293:
	if ( ++p == pe )
		goto _test_eof293;
case 293:
#line 7540 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr408;
		case 47: goto tr420;
		case 61: goto tr430;
		case 92: goto tr421;
		case 95: goto tr429;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr420;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr420;
		} else
			goto tr429;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr420;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr420;
		} else
			goto tr429;
	} else
		goto tr429;
	goto tr425;
tr430:
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st294;
st294:
	if ( ++p == pe )
		goto _test_eof294;
case 294:
#line 7583 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr431;
		case 92: goto tr421;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr420;
	goto tr403;
tr431:
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st295;
st295:
	if ( ++p == pe )
		goto _test_eof295;
case 295:
#line 7601 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr405;
		case 44: goto tr432;
		case 62: goto tr433;
		case 92: goto tr419;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr418;
	goto tr403;
tr433:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st296;
tr424:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st296;
st296:
	if ( ++p == pe )
		goto _test_eof296;
case 296:
#line 7631 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 10: goto tr55;
		case 13: goto tr56;
		case 34: goto tr408;
		case 92: goto tr421;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr420;
	goto tr403;
st297:
	if ( ++p == pe )
		goto _test_eof297;
case 297:
	switch( (*p) ) {
		case 10: goto tr55;
		case 13: goto tr56;
	}
	goto tr355;
tr406:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st298;
tr409:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st298;
st298:
	if ( ++p == pe )
		goto _test_eof298;
case 298:
#line 7670 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr434;
		case 92: goto tr409;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr407;
	goto tr403;
tr434:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st299;
st299:
	if ( ++p == pe )
		goto _test_eof299;
case 299:
#line 7692 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr408;
		case 44: goto tr435;
		case 62: goto tr436;
		case 92: goto tr409;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr407;
	goto tr403;
tr435:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st300;
st300:
	if ( ++p == pe )
		goto _test_eof300;
case 300:
#line 7712 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr408;
		case 47: goto tr407;
		case 92: goto tr409;
		case 95: goto tr438;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr407;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr439;
		} else
			goto tr438;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr439;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr407;
			} else if ( (*p) >= 97 )
				goto tr439;
		} else
			goto tr407;
	} else
		goto tr407;
	goto tr437;
tr440:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st301;
tr438:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st301;
st301:
	if ( ++p == pe )
		goto _test_eof301;
case 301:
#line 7763 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr408;
		case 47: goto tr407;
		case 92: goto tr409;
		case 95: goto tr440;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr407;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr441;
		} else
			goto tr440;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr441;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr407;
			} else if ( (*p) >= 97 )
				goto tr441;
		} else
			goto tr407;
	} else
		goto tr407;
	goto tr437;
tr441:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st302;
tr439:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st302;
st302:
	if ( ++p == pe )
		goto _test_eof302;
case 302:
#line 7814 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr408;
		case 47: goto tr407;
		case 61: goto tr442;
		case 92: goto tr409;
		case 95: goto tr441;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr407;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr407;
		} else
			goto tr441;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr407;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr407;
		} else
			goto tr441;
	} else
		goto tr441;
	goto tr437;
tr442:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st303;
st303:
	if ( ++p == pe )
		goto _test_eof303;
case 303:
#line 7857 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr431;
		case 92: goto tr409;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr407;
	goto tr403;
tr436:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st304;
st304:
	if ( ++p == pe )
		goto _test_eof304;
case 304:
#line 7875 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 10: goto tr55;
		case 13: goto tr56;
		case 34: goto tr408;
		case 92: goto tr409;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr407;
	goto tr403;
tr443:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st305;
tr379:
#line 143 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Number");
    }
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st305;
st305:
	if ( ++p == pe )
		goto _test_eof305;
case 305:
#line 7909 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 44 )
		goto tr380;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr443;
	goto tr377;
tr34:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st306;
st306:
	if ( ++p == pe )
		goto _test_eof306;
case 306:
#line 7929 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 69: goto tr445;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr444;
tr445:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st307;
st307:
	if ( ++p == pe )
		goto _test_eof307;
case 307:
#line 7947 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 68: goto tr446;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr444;
tr446:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st308;
st308:
	if ( ++p == pe )
		goto _test_eof308;
case 308:
#line 7965 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 73: goto tr447;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr444;
tr447:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st309;
st309:
	if ( ++p == pe )
		goto _test_eof309;
case 309:
#line 7983 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 71: goto tr448;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr444;
tr448:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st310;
st310:
	if ( ++p == pe )
		goto _test_eof310;
case 310:
#line 8001 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 82: goto tr449;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr444;
tr449:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st311;
st311:
	if ( ++p == pe )
		goto _test_eof311;
case 311:
#line 8019 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 69: goto tr450;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr444;
tr450:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st312;
st312:
	if ( ++p == pe )
		goto _test_eof312;
case 312:
#line 8037 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 69: goto st313;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr444;
st313:
	if ( ++p == pe )
		goto _test_eof313;
case 313:
	if ( (*p) == 61 )
		goto tr452;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr444;
tr452:
#line 127 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "PEDIGREE");
    }
	goto st314;
st314:
	if ( ++p == pe )
		goto _test_eof314;
case 314:
#line 8064 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 60 )
		goto st315;
	goto tr444;
tr464:
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st315;
st315:
	if ( ++p == pe )
		goto _test_eof315;
case 315:
#line 8078 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 95 )
		goto tr455;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr455;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr456;
		} else if ( (*p) >= 65 )
			goto tr456;
	} else
		goto tr456;
	goto tr454;
tr455:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st316;
st316:
	if ( ++p == pe )
		goto _test_eof316;
case 316:
#line 8103 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 95 )
		goto st316;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st316;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr458;
		} else if ( (*p) >= 65 )
			goto tr458;
	} else
		goto tr458;
	goto tr454;
tr456:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st317;
tr458:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st317;
st317:
	if ( ++p == pe )
		goto _test_eof317;
case 317:
#line 8138 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr459;
		case 95: goto tr458;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr458;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr458;
		} else if ( (*p) >= 65 )
			goto tr458;
	} else
		goto tr458;
	goto tr454;
tr459:
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st318;
st318:
	if ( ++p == pe )
		goto _test_eof318;
case 318:
#line 8165 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 95 )
		goto tr460;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr460;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr461;
		} else if ( (*p) >= 65 )
			goto tr461;
	} else
		goto tr461;
	goto tr454;
tr460:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st319;
st319:
	if ( ++p == pe )
		goto _test_eof319;
case 319:
#line 8190 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 95 )
		goto st319;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st319;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr463;
		} else if ( (*p) >= 65 )
			goto tr463;
	} else
		goto tr463;
	goto tr454;
tr461:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st320;
tr463:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st320;
st320:
	if ( ++p == pe )
		goto _test_eof320;
case 320:
#line 8225 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 44: goto tr464;
		case 62: goto tr465;
		case 95: goto tr463;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr463;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr463;
		} else if ( (*p) >= 65 )
			goto tr463;
	} else
		goto tr463;
	goto tr454;
tr465:
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st321;
st321:
	if ( ++p == pe )
		goto _test_eof321;
case 321:
#line 8253 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 10: goto tr55;
		case 13: goto tr56;
	}
	goto tr444;
tr35:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st322;
st322:
	if ( ++p == pe )
		goto _test_eof322;
case 322:
#line 8273 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 65: goto tr467;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr466;
tr467:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st323;
st323:
	if ( ++p == pe )
		goto _test_eof323;
case 323:
#line 8291 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 77: goto tr468;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr466;
tr468:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st324;
st324:
	if ( ++p == pe )
		goto _test_eof324;
case 324:
#line 8309 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 80: goto tr469;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr466;
tr469:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st325;
st325:
	if ( ++p == pe )
		goto _test_eof325;
case 325:
#line 8327 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 76: goto tr470;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr466;
tr470:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st326;
st326:
	if ( ++p == pe )
		goto _test_eof326;
case 326:
#line 8345 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 69: goto st327;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr466;
st327:
	if ( ++p == pe )
		goto _test_eof327;
case 327:
	if ( (*p) == 61 )
		goto tr472;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr466;
tr472:
#line 135 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "SAMPLE");
    }
	goto st328;
st328:
	if ( ++p == pe )
		goto _test_eof328;
case 328:
#line 8372 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 60 )
		goto st329;
	goto tr466;
st329:
	if ( ++p == pe )
		goto _test_eof329;
case 329:
	if ( (*p) == 73 )
		goto st330;
	goto tr466;
st330:
	if ( ++p == pe )
		goto _test_eof330;
case 330:
	if ( (*p) == 68 )
		goto st331;
	goto tr466;
st331:
	if ( ++p == pe )
		goto _test_eof331;
case 331:
	if ( (*p) == 61 )
		goto st332;
	goto tr466;
st332:
	if ( ++p == pe )
		goto _test_eof332;
case 332:
	if ( (*p) == 95 )
		goto tr478;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr478;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr479;
		} else if ( (*p) >= 65 )
			goto tr479;
	} else
		goto tr479;
	goto tr477;
tr478:
#line 139 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st333;
st333:
	if ( ++p == pe )
		goto _test_eof333;
case 333:
#line 8429 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 95 )
		goto st333;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st333;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr481;
		} else if ( (*p) >= 65 )
			goto tr481;
	} else
		goto tr481;
	goto tr477;
tr481:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st334;
tr479:
#line 139 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st334;
st334:
	if ( ++p == pe )
		goto _test_eof334;
case 334:
#line 8468 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 44: goto tr483;
		case 95: goto tr481;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr481;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr481;
		} else if ( (*p) >= 65 )
			goto tr481;
	} else
		goto tr481;
	goto tr482;
tr483:
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st335;
st335:
	if ( ++p == pe )
		goto _test_eof335;
case 335:
#line 8495 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 71 )
		goto st336;
	goto tr484;
st336:
	if ( ++p == pe )
		goto _test_eof336;
case 336:
	if ( (*p) == 101 )
		goto st337;
	goto tr484;
st337:
	if ( ++p == pe )
		goto _test_eof337;
case 337:
	if ( (*p) == 110 )
		goto st338;
	goto tr484;
st338:
	if ( ++p == pe )
		goto _test_eof338;
case 338:
	if ( (*p) == 111 )
		goto st339;
	goto tr484;
st339:
	if ( ++p == pe )
		goto _test_eof339;
case 339:
	if ( (*p) == 109 )
		goto st340;
	goto tr484;
st340:
	if ( ++p == pe )
		goto _test_eof340;
case 340:
	if ( (*p) == 101 )
		goto st341;
	goto tr484;
st341:
	if ( ++p == pe )
		goto _test_eof341;
case 341:
	if ( (*p) == 115 )
		goto st342;
	goto tr484;
st342:
	if ( ++p == pe )
		goto _test_eof342;
case 342:
	if ( (*p) == 61 )
		goto st343;
	goto tr484;
st343:
	if ( ++p == pe )
		goto _test_eof343;
case 343:
	if ( (*p) < 35 ) {
		if ( 32 <= (*p) && (*p) <= 33 )
			goto tr493;
	} else if ( (*p) > 43 ) {
		if ( (*p) > 61 ) {
			if ( 63 <= (*p) && (*p) <= 126 )
				goto tr493;
		} else if ( (*p) >= 45 )
			goto tr493;
	} else
		goto tr493;
	goto tr484;
tr495:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st344;
tr493:
#line 155 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Genomes");
    }
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st344;
st344:
	if ( ++p == pe )
		goto _test_eof344;
case 344:
#line 8588 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 44 )
		goto tr496;
	if ( (*p) < 35 ) {
		if ( 32 <= (*p) && (*p) <= 33 )
			goto tr495;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr495;
	} else
		goto tr495;
	goto tr494;
tr496:
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st345;
st345:
	if ( ++p == pe )
		goto _test_eof345;
case 345:
#line 8610 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 77 )
		goto st346;
	goto tr497;
st346:
	if ( ++p == pe )
		goto _test_eof346;
case 346:
	if ( (*p) == 105 )
		goto st347;
	goto tr497;
st347:
	if ( ++p == pe )
		goto _test_eof347;
case 347:
	if ( (*p) == 120 )
		goto st348;
	goto tr497;
st348:
	if ( ++p == pe )
		goto _test_eof348;
case 348:
	if ( (*p) == 116 )
		goto st349;
	goto tr497;
st349:
	if ( ++p == pe )
		goto _test_eof349;
case 349:
	if ( (*p) == 117 )
		goto st350;
	goto tr497;
st350:
	if ( ++p == pe )
		goto _test_eof350;
case 350:
	if ( (*p) == 114 )
		goto st351;
	goto tr497;
st351:
	if ( ++p == pe )
		goto _test_eof351;
case 351:
	if ( (*p) == 101 )
		goto st352;
	goto tr497;
st352:
	if ( ++p == pe )
		goto _test_eof352;
case 352:
	if ( (*p) == 61 )
		goto st353;
	goto tr497;
st353:
	if ( ++p == pe )
		goto _test_eof353;
case 353:
	if ( (*p) < 35 ) {
		if ( 32 <= (*p) && (*p) <= 33 )
			goto tr506;
	} else if ( (*p) > 43 ) {
		if ( (*p) > 61 ) {
			if ( 63 <= (*p) && (*p) <= 126 )
				goto tr506;
		} else if ( (*p) >= 45 )
			goto tr506;
	} else
		goto tr506;
	goto tr497;
tr508:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st354;
tr506:
#line 159 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Mixture");
    }
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st354;
st354:
	if ( ++p == pe )
		goto _test_eof354;
case 354:
#line 8703 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 44 )
		goto tr509;
	if ( (*p) < 35 ) {
		if ( 32 <= (*p) && (*p) <= 33 )
			goto tr508;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr508;
	} else
		goto tr508;
	goto tr507;
tr509:
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st355;
st355:
	if ( ++p == pe )
		goto _test_eof355;
case 355:
#line 8725 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 68 )
		goto st356;
	goto tr510;
st356:
	if ( ++p == pe )
		goto _test_eof356;
case 356:
	if ( (*p) == 101 )
		goto st357;
	goto tr510;
st357:
	if ( ++p == pe )
		goto _test_eof357;
case 357:
	if ( (*p) == 115 )
		goto st358;
	goto tr510;
st358:
	if ( ++p == pe )
		goto _test_eof358;
case 358:
	if ( (*p) == 99 )
		goto st359;
	goto tr510;
st359:
	if ( ++p == pe )
		goto _test_eof359;
case 359:
	if ( (*p) == 114 )
		goto st360;
	goto tr510;
st360:
	if ( ++p == pe )
		goto _test_eof360;
case 360:
	if ( (*p) == 105 )
		goto st361;
	goto tr510;
st361:
	if ( ++p == pe )
		goto _test_eof361;
case 361:
	if ( (*p) == 112 )
		goto st362;
	goto tr510;
st362:
	if ( ++p == pe )
		goto _test_eof362;
case 362:
	if ( (*p) == 116 )
		goto st363;
	goto tr510;
st363:
	if ( ++p == pe )
		goto _test_eof363;
case 363:
	if ( (*p) == 105 )
		goto st364;
	goto tr510;
st364:
	if ( ++p == pe )
		goto _test_eof364;
case 364:
	if ( (*p) == 111 )
		goto st365;
	goto tr510;
st365:
	if ( ++p == pe )
		goto _test_eof365;
case 365:
	if ( (*p) == 110 )
		goto st366;
	goto tr510;
st366:
	if ( ++p == pe )
		goto _test_eof366;
case 366:
	if ( (*p) == 61 )
		goto st367;
	goto tr510;
st367:
	if ( ++p == pe )
		goto _test_eof367;
case 367:
	if ( (*p) == 34 )
		goto tr523;
	goto tr510;
tr523:
#line 151 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Description");
    }
	goto st368;
st368:
	if ( ++p == pe )
		goto _test_eof368;
case 368:
#line 8823 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr525;
		case 92: goto tr526;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr524;
	goto tr510;
tr524:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st369;
tr527:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st369;
st369:
	if ( ++p == pe )
		goto _test_eof369;
case 369:
#line 8851 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr528;
		case 92: goto tr529;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr527;
	goto tr510;
tr525:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st370;
tr528:
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st370;
st370:
	if ( ++p == pe )
		goto _test_eof370;
case 370:
#line 8879 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 62 )
		goto st371;
	goto tr510;
st371:
	if ( ++p == pe )
		goto _test_eof371;
case 371:
	switch( (*p) ) {
		case 10: goto tr55;
		case 13: goto tr56;
	}
	goto tr466;
tr526:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st372;
tr529:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st372;
st372:
	if ( ++p == pe )
		goto _test_eof372;
case 372:
#line 8912 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr531;
		case 92: goto tr529;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr527;
	goto tr510;
tr531:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st373;
st373:
	if ( ++p == pe )
		goto _test_eof373;
case 373:
#line 8934 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr528;
		case 62: goto tr532;
		case 92: goto tr529;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr527;
	goto tr510;
tr532:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st374;
st374:
	if ( ++p == pe )
		goto _test_eof374;
case 374:
#line 8953 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 10: goto tr55;
		case 13: goto tr56;
		case 34: goto tr528;
		case 92: goto tr529;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr527;
	goto tr510;
tr36:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st375;
st375:
	if ( ++p == pe )
		goto _test_eof375;
case 375:
#line 8977 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 115: goto tr534;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr533;
tr534:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st376;
st376:
	if ( ++p == pe )
		goto _test_eof376;
case 376:
#line 8995 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 115: goto tr535;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr533;
tr535:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st377;
st377:
	if ( ++p == pe )
		goto _test_eof377;
case 377:
#line 9013 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 101: goto tr536;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr533;
tr536:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st378;
st378:
	if ( ++p == pe )
		goto _test_eof378;
case 378:
#line 9031 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 109: goto tr537;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr533;
tr537:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st379;
st379:
	if ( ++p == pe )
		goto _test_eof379;
case 379:
#line 9049 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 98: goto tr538;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr533;
tr538:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st380;
st380:
	if ( ++p == pe )
		goto _test_eof380;
case 380:
#line 9067 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 108: goto tr539;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr533;
tr539:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st381;
st381:
	if ( ++p == pe )
		goto _test_eof381;
case 381:
#line 9085 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 121: goto st382;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr533;
st382:
	if ( ++p == pe )
		goto _test_eof382;
case 382:
	if ( (*p) == 61 )
		goto tr541;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr533;
tr541:
#line 107 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "assembly");
    }
	goto st383;
st383:
	if ( ++p == pe )
		goto _test_eof383;
case 383:
#line 9112 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr543;
	} else if ( (*p) >= 65 )
		goto tr543;
	goto tr542;
tr543:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st384;
st384:
	if ( ++p == pe )
		goto _test_eof384;
case 384:
#line 9129 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 10: goto tr542;
		case 35: goto tr542;
		case 47: goto tr542;
		case 58: goto tr542;
		case 63: goto tr542;
	}
	goto st385;
st385:
	if ( ++p == pe )
		goto _test_eof385;
case 385:
	switch( (*p) ) {
		case 10: goto tr542;
		case 35: goto tr542;
		case 47: goto tr542;
		case 58: goto st386;
		case 63: goto tr542;
	}
	goto st385;
st386:
	if ( ++p == pe )
		goto _test_eof386;
case 386:
	if ( (*p) == 47 )
		goto st387;
	goto tr542;
st387:
	if ( ++p == pe )
		goto _test_eof387;
case 387:
	if ( (*p) == 47 )
		goto st388;
	goto tr542;
st388:
	if ( ++p == pe )
		goto _test_eof388;
case 388:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st389;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr549;
	} else
		goto tr549;
	goto tr542;
st389:
	if ( ++p == pe )
		goto _test_eof389;
case 389:
	if ( (*p) == 46 )
		goto st390;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st400;
	goto tr542;
st390:
	if ( ++p == pe )
		goto _test_eof390;
case 390:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st391;
	goto tr542;
st391:
	if ( ++p == pe )
		goto _test_eof391;
case 391:
	if ( (*p) == 46 )
		goto st392;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st398;
	goto tr542;
st392:
	if ( ++p == pe )
		goto _test_eof392;
case 392:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st393;
	goto tr542;
st393:
	if ( ++p == pe )
		goto _test_eof393;
case 393:
	if ( (*p) == 46 )
		goto st394;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st396;
	goto tr542;
st394:
	if ( ++p == pe )
		goto _test_eof394;
case 394:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr549;
	goto tr542;
tr549:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st395;
tr558:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 171 "src/vcf/vcf_v43.ragel"
	{
        try {
          ParsePolicy::handle_meta_line(*this);
        } catch (ParsingError ex) {
          ErrorPolicy::handle_meta_section_error(*this, ex.what());
        }
    }
#line 43 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st395;
st395:
	if ( ++p == pe )
		goto _test_eof395;
case 395:
#line 9263 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 10: goto tr45;
		case 13: goto tr558;
	}
	goto tr549;
st396:
	if ( ++p == pe )
		goto _test_eof396;
case 396:
	if ( (*p) == 46 )
		goto st394;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st397;
	goto tr542;
st397:
	if ( ++p == pe )
		goto _test_eof397;
case 397:
	if ( (*p) == 46 )
		goto st394;
	goto tr542;
st398:
	if ( ++p == pe )
		goto _test_eof398;
case 398:
	if ( (*p) == 46 )
		goto st392;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st399;
	goto tr542;
st399:
	if ( ++p == pe )
		goto _test_eof399;
case 399:
	if ( (*p) == 46 )
		goto st392;
	goto tr542;
st400:
	if ( ++p == pe )
		goto _test_eof400;
case 400:
	if ( (*p) == 46 )
		goto st390;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st401;
	goto tr542;
st401:
	if ( ++p == pe )
		goto _test_eof401;
case 401:
	if ( (*p) == 46 )
		goto st390;
	goto tr542;
tr37:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st402;
st402:
	if ( ++p == pe )
		goto _test_eof402;
case 402:
#line 9331 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 111: goto tr563;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr562;
tr563:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st403;
st403:
	if ( ++p == pe )
		goto _test_eof403;
case 403:
#line 9349 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 110: goto tr564;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr562;
tr564:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st404;
st404:
	if ( ++p == pe )
		goto _test_eof404;
case 404:
#line 9367 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 116: goto tr565;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr562;
tr565:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st405;
st405:
	if ( ++p == pe )
		goto _test_eof405;
case 405:
#line 9385 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 105: goto tr566;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr562;
tr566:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st406;
st406:
	if ( ++p == pe )
		goto _test_eof406;
case 406:
#line 9403 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 103: goto st407;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr562;
st407:
	if ( ++p == pe )
		goto _test_eof407;
case 407:
	if ( (*p) == 61 )
		goto tr568;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr562;
tr568:
#line 111 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "contig");
    }
	goto st408;
st408:
	if ( ++p == pe )
		goto _test_eof408;
case 408:
#line 9430 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 60 )
		goto st409;
	goto tr562;
st409:
	if ( ++p == pe )
		goto _test_eof409;
case 409:
	if ( (*p) == 73 )
		goto st410;
	goto tr562;
st410:
	if ( ++p == pe )
		goto _test_eof410;
case 410:
	if ( (*p) == 68 )
		goto st411;
	goto tr562;
st411:
	if ( ++p == pe )
		goto _test_eof411;
case 411:
	if ( (*p) == 61 )
		goto st412;
	goto tr562;
st412:
	if ( ++p == pe )
		goto _test_eof412;
case 412:
	switch( (*p) ) {
		case 43: goto tr574;
		case 59: goto tr574;
		case 92: goto tr574;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr574;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr574;
		} else if ( (*p) >= 63 )
			goto tr574;
	} else
		goto tr574;
	goto tr573;
tr575:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st413;
tr574:
#line 139 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st413;
st413:
	if ( ++p == pe )
		goto _test_eof413;
case 413:
#line 9500 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 44: goto tr576;
		case 59: goto tr575;
		case 62: goto tr577;
		case 92: goto tr575;
	}
	if ( (*p) < 43 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr575;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr575;
		} else if ( (*p) >= 63 )
			goto tr575;
	} else
		goto tr575;
	goto tr573;
tr576:
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st414;
st414:
	if ( ++p == pe )
		goto _test_eof414;
case 414:
#line 9529 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 95 )
		goto tr578;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr578;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr579;
		} else if ( (*p) >= 65 )
			goto tr579;
	} else
		goto tr579;
	goto tr562;
tr578:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st415;
st415:
	if ( ++p == pe )
		goto _test_eof415;
case 415:
#line 9554 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 95 )
		goto st415;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st415;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr581;
		} else if ( (*p) >= 65 )
			goto tr581;
	} else
		goto tr581;
	goto tr562;
tr579:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st416;
tr581:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st416;
st416:
	if ( ++p == pe )
		goto _test_eof416;
case 416:
#line 9589 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr582;
		case 95: goto tr581;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr581;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr581;
		} else if ( (*p) >= 65 )
			goto tr581;
	} else
		goto tr581;
	goto tr562;
tr582:
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st417;
st417:
	if ( ++p == pe )
		goto _test_eof417;
case 417:
#line 9616 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 34 )
		goto st420;
	if ( (*p) < 45 ) {
		if ( 32 <= (*p) && (*p) <= 43 )
			goto tr583;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr583;
	} else
		goto tr583;
	goto tr562;
tr583:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st418;
tr585:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st418;
st418:
	if ( ++p == pe )
		goto _test_eof418;
case 418:
#line 9648 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 44: goto tr576;
		case 62: goto tr577;
	}
	if ( (*p) > 33 ) {
		if ( 35 <= (*p) && (*p) <= 126 )
			goto tr585;
	} else if ( (*p) >= 32 )
		goto tr585;
	goto tr562;
tr577:
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st419;
st419:
	if ( ++p == pe )
		goto _test_eof419;
case 419:
#line 9669 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 10: goto tr55;
		case 13: goto tr56;
	}
	goto tr562;
st420:
	if ( ++p == pe )
		goto _test_eof420;
case 420:
	switch( (*p) ) {
		case 34: goto tr587;
		case 92: goto tr588;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr586;
	goto tr562;
tr586:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st421;
tr589:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st421;
st421:
	if ( ++p == pe )
		goto _test_eof421;
case 421:
#line 9706 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr590;
		case 92: goto tr591;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr589;
	goto tr562;
tr587:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st422;
tr590:
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st422;
st422:
	if ( ++p == pe )
		goto _test_eof422;
case 422:
#line 9734 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 44: goto st414;
		case 62: goto st419;
	}
	goto tr562;
tr588:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st423;
tr591:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st423;
st423:
	if ( ++p == pe )
		goto _test_eof423;
case 423:
#line 9760 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr594;
		case 92: goto tr591;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr589;
	goto tr562;
tr594:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st424;
st424:
	if ( ++p == pe )
		goto _test_eof424;
case 424:
#line 9782 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr590;
		case 44: goto tr595;
		case 62: goto tr596;
		case 92: goto tr591;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr589;
	goto tr562;
tr609:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st425;
tr595:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st425;
tr606:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st425;
st425:
	if ( ++p == pe )
		goto _test_eof425;
case 425:
#line 9822 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr590;
		case 47: goto tr589;
		case 92: goto tr591;
		case 95: goto tr597;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr589;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr598;
		} else
			goto tr597;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr598;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr589;
			} else if ( (*p) >= 97 )
				goto tr598;
		} else
			goto tr589;
	} else
		goto tr589;
	goto tr562;
tr597:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st426;
tr599:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st426;
st426:
	if ( ++p == pe )
		goto _test_eof426;
case 426:
#line 9873 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr590;
		case 47: goto tr589;
		case 92: goto tr591;
		case 95: goto tr599;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr589;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr600;
		} else
			goto tr599;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr600;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr589;
			} else if ( (*p) >= 97 )
				goto tr600;
		} else
			goto tr589;
	} else
		goto tr589;
	goto tr562;
tr598:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st427;
tr600:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st427;
st427:
	if ( ++p == pe )
		goto _test_eof427;
case 427:
#line 9924 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr590;
		case 47: goto tr589;
		case 61: goto tr601;
		case 92: goto tr591;
		case 95: goto tr600;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr589;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr589;
		} else
			goto tr600;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr589;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr589;
		} else
			goto tr600;
	} else
		goto tr600;
	goto tr562;
tr601:
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st428;
st428:
	if ( ++p == pe )
		goto _test_eof428;
case 428:
#line 9967 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr603;
		case 44: goto tr589;
		case 62: goto tr589;
		case 92: goto tr604;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr602;
	goto tr562;
tr605:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st429;
tr602:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st429;
st429:
	if ( ++p == pe )
		goto _test_eof429;
case 429:
#line 9997 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr590;
		case 44: goto tr606;
		case 62: goto tr607;
		case 92: goto tr608;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr605;
	goto tr562;
tr610:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st430;
tr596:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st430;
tr607:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st430;
st430:
	if ( ++p == pe )
		goto _test_eof430;
case 430:
#line 10037 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 10: goto tr55;
		case 13: goto tr56;
		case 34: goto tr590;
		case 92: goto tr591;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr589;
	goto tr562;
tr608:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st431;
tr604:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st431;
st431:
	if ( ++p == pe )
		goto _test_eof431;
case 431:
#line 10067 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr594;
		case 44: goto tr606;
		case 62: goto tr607;
		case 92: goto tr608;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr605;
	goto tr562;
tr603:
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st432;
st432:
	if ( ++p == pe )
		goto _test_eof432;
case 432:
#line 10087 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr587;
		case 44: goto tr609;
		case 62: goto tr610;
		case 92: goto tr588;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr586;
	goto tr562;
tr38:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st433;
st433:
	if ( ++p == pe )
		goto _test_eof433;
case 433:
#line 10111 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 101: goto tr612;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr611;
tr612:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st434;
st434:
	if ( ++p == pe )
		goto _test_eof434;
case 434:
#line 10129 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 100: goto tr613;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr611;
tr613:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st435;
st435:
	if ( ++p == pe )
		goto _test_eof435;
case 435:
#line 10147 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 105: goto tr614;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr611;
tr614:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st436;
st436:
	if ( ++p == pe )
		goto _test_eof436;
case 436:
#line 10165 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 103: goto tr615;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr611;
tr615:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st437;
st437:
	if ( ++p == pe )
		goto _test_eof437;
case 437:
#line 10183 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 114: goto tr616;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr611;
tr616:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st438;
st438:
	if ( ++p == pe )
		goto _test_eof438;
case 438:
#line 10201 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 101: goto tr617;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr611;
tr617:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st439;
st439:
	if ( ++p == pe )
		goto _test_eof439;
case 439:
#line 10219 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 101: goto tr618;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr611;
tr618:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st440;
st440:
	if ( ++p == pe )
		goto _test_eof440;
case 440:
#line 10237 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 68: goto tr619;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr611;
tr619:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st441;
st441:
	if ( ++p == pe )
		goto _test_eof441;
case 441:
#line 10255 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 66: goto st442;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr611;
st442:
	if ( ++p == pe )
		goto _test_eof442;
case 442:
	if ( (*p) == 61 )
		goto tr621;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr611;
tr621:
#line 131 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "pedigreeDB");
    }
	goto st443;
st443:
	if ( ++p == pe )
		goto _test_eof443;
case 443:
#line 10282 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 60 )
		goto st444;
	goto tr611;
st444:
	if ( ++p == pe )
		goto _test_eof444;
case 444:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr624;
	} else if ( (*p) >= 65 )
		goto tr624;
	goto tr623;
tr624:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st445;
st445:
	if ( ++p == pe )
		goto _test_eof445;
case 445:
#line 10306 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 10: goto tr623;
		case 35: goto tr623;
		case 47: goto tr623;
		case 58: goto tr623;
		case 63: goto tr623;
	}
	goto st446;
st446:
	if ( ++p == pe )
		goto _test_eof446;
case 446:
	switch( (*p) ) {
		case 10: goto tr623;
		case 35: goto tr623;
		case 47: goto tr623;
		case 58: goto st447;
		case 63: goto tr623;
	}
	goto st446;
st447:
	if ( ++p == pe )
		goto _test_eof447;
case 447:
	if ( (*p) == 47 )
		goto st448;
	goto tr623;
st448:
	if ( ++p == pe )
		goto _test_eof448;
case 448:
	if ( (*p) == 47 )
		goto st449;
	goto tr623;
st449:
	if ( ++p == pe )
		goto _test_eof449;
case 449:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st450;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr630;
	} else
		goto tr630;
	goto tr623;
st450:
	if ( ++p == pe )
		goto _test_eof450;
case 450:
	if ( (*p) == 46 )
		goto st451;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st463;
	goto tr623;
st451:
	if ( ++p == pe )
		goto _test_eof451;
case 451:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st452;
	goto tr623;
st452:
	if ( ++p == pe )
		goto _test_eof452;
case 452:
	if ( (*p) == 46 )
		goto st453;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st461;
	goto tr623;
st453:
	if ( ++p == pe )
		goto _test_eof453;
case 453:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st454;
	goto tr623;
st454:
	if ( ++p == pe )
		goto _test_eof454;
case 454:
	if ( (*p) == 46 )
		goto st455;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st459;
	goto tr623;
st455:
	if ( ++p == pe )
		goto _test_eof455;
case 455:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr630;
	goto tr623;
tr630:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st456;
st456:
	if ( ++p == pe )
		goto _test_eof456;
case 456:
#line 10412 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 10: goto tr623;
		case 62: goto tr639;
	}
	goto tr630;
tr639:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st457;
st457:
	if ( ++p == pe )
		goto _test_eof457;
case 457:
#line 10432 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 10: goto tr55;
		case 13: goto tr640;
		case 62: goto tr639;
	}
	goto tr630;
tr640:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 171 "src/vcf/vcf_v43.ragel"
	{
        try {
          ParsePolicy::handle_meta_line(*this);
        } catch (ParsingError ex) {
          ErrorPolicy::handle_meta_section_error(*this, ex.what());
        }
    }
#line 43 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st458;
st458:
	if ( ++p == pe )
		goto _test_eof458;
case 458:
#line 10467 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 10: goto st28;
		case 62: goto tr639;
	}
	goto tr630;
st459:
	if ( ++p == pe )
		goto _test_eof459;
case 459:
	if ( (*p) == 46 )
		goto st455;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st460;
	goto tr623;
st460:
	if ( ++p == pe )
		goto _test_eof460;
case 460:
	if ( (*p) == 46 )
		goto st455;
	goto tr623;
st461:
	if ( ++p == pe )
		goto _test_eof461;
case 461:
	if ( (*p) == 46 )
		goto st453;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st462;
	goto tr623;
st462:
	if ( ++p == pe )
		goto _test_eof462;
case 462:
	if ( (*p) == 46 )
		goto st453;
	goto tr623;
st463:
	if ( ++p == pe )
		goto _test_eof463;
case 463:
	if ( (*p) == 46 )
		goto st451;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st464;
	goto tr623;
st464:
	if ( ++p == pe )
		goto _test_eof464;
case 464:
	if ( (*p) == 46 )
		goto st451;
	goto tr623;
st465:
	if ( ++p == pe )
		goto _test_eof465;
case 465:
	if ( (*p) == 72 )
		goto st466;
	goto tr644;
st466:
	if ( ++p == pe )
		goto _test_eof466;
case 466:
	if ( (*p) == 82 )
		goto st467;
	goto tr644;
st467:
	if ( ++p == pe )
		goto _test_eof467;
case 467:
	if ( (*p) == 79 )
		goto st468;
	goto tr644;
st468:
	if ( ++p == pe )
		goto _test_eof468;
case 468:
	if ( (*p) == 77 )
		goto st469;
	goto tr644;
st469:
	if ( ++p == pe )
		goto _test_eof469;
case 469:
	if ( (*p) == 9 )
		goto st470;
	goto tr644;
st470:
	if ( ++p == pe )
		goto _test_eof470;
case 470:
	if ( (*p) == 80 )
		goto st471;
	goto tr644;
st471:
	if ( ++p == pe )
		goto _test_eof471;
case 471:
	if ( (*p) == 79 )
		goto st472;
	goto tr644;
st472:
	if ( ++p == pe )
		goto _test_eof472;
case 472:
	if ( (*p) == 83 )
		goto st473;
	goto tr644;
st473:
	if ( ++p == pe )
		goto _test_eof473;
case 473:
	if ( (*p) == 9 )
		goto st474;
	goto tr644;
st474:
	if ( ++p == pe )
		goto _test_eof474;
case 474:
	if ( (*p) == 73 )
		goto st475;
	goto tr644;
st475:
	if ( ++p == pe )
		goto _test_eof475;
case 475:
	if ( (*p) == 68 )
		goto st476;
	goto tr644;
st476:
	if ( ++p == pe )
		goto _test_eof476;
case 476:
	if ( (*p) == 9 )
		goto st477;
	goto tr644;
st477:
	if ( ++p == pe )
		goto _test_eof477;
case 477:
	if ( (*p) == 82 )
		goto st478;
	goto tr644;
st478:
	if ( ++p == pe )
		goto _test_eof478;
case 478:
	if ( (*p) == 69 )
		goto st479;
	goto tr644;
st479:
	if ( ++p == pe )
		goto _test_eof479;
case 479:
	if ( (*p) == 70 )
		goto st480;
	goto tr644;
st480:
	if ( ++p == pe )
		goto _test_eof480;
case 480:
	if ( (*p) == 9 )
		goto st481;
	goto tr644;
st481:
	if ( ++p == pe )
		goto _test_eof481;
case 481:
	if ( (*p) == 65 )
		goto st482;
	goto tr644;
st482:
	if ( ++p == pe )
		goto _test_eof482;
case 482:
	if ( (*p) == 76 )
		goto st483;
	goto tr644;
st483:
	if ( ++p == pe )
		goto _test_eof483;
case 483:
	if ( (*p) == 84 )
		goto st484;
	goto tr644;
st484:
	if ( ++p == pe )
		goto _test_eof484;
case 484:
	if ( (*p) == 9 )
		goto st485;
	goto tr644;
st485:
	if ( ++p == pe )
		goto _test_eof485;
case 485:
	if ( (*p) == 81 )
		goto st486;
	goto tr644;
st486:
	if ( ++p == pe )
		goto _test_eof486;
case 486:
	if ( (*p) == 85 )
		goto st487;
	goto tr644;
st487:
	if ( ++p == pe )
		goto _test_eof487;
case 487:
	if ( (*p) == 65 )
		goto st488;
	goto tr644;
st488:
	if ( ++p == pe )
		goto _test_eof488;
case 488:
	if ( (*p) == 76 )
		goto st489;
	goto tr644;
st489:
	if ( ++p == pe )
		goto _test_eof489;
case 489:
	if ( (*p) == 9 )
		goto st490;
	goto tr644;
st490:
	if ( ++p == pe )
		goto _test_eof490;
case 490:
	if ( (*p) == 70 )
		goto st491;
	goto tr644;
st491:
	if ( ++p == pe )
		goto _test_eof491;
case 491:
	if ( (*p) == 73 )
		goto st492;
	goto tr644;
st492:
	if ( ++p == pe )
		goto _test_eof492;
case 492:
	if ( (*p) == 76 )
		goto st493;
	goto tr644;
st493:
	if ( ++p == pe )
		goto _test_eof493;
case 493:
	if ( (*p) == 84 )
		goto st494;
	goto tr644;
st494:
	if ( ++p == pe )
		goto _test_eof494;
case 494:
	if ( (*p) == 69 )
		goto st495;
	goto tr644;
st495:
	if ( ++p == pe )
		goto _test_eof495;
case 495:
	if ( (*p) == 82 )
		goto st496;
	goto tr644;
st496:
	if ( ++p == pe )
		goto _test_eof496;
case 496:
	if ( (*p) == 9 )
		goto st497;
	goto tr644;
st497:
	if ( ++p == pe )
		goto _test_eof497;
case 497:
	if ( (*p) == 73 )
		goto st498;
	goto tr644;
st498:
	if ( ++p == pe )
		goto _test_eof498;
case 498:
	if ( (*p) == 78 )
		goto st499;
	goto tr644;
st499:
	if ( ++p == pe )
		goto _test_eof499;
case 499:
	if ( (*p) == 70 )
		goto st500;
	goto tr644;
st500:
	if ( ++p == pe )
		goto _test_eof500;
case 500:
	if ( (*p) == 79 )
		goto st501;
	goto tr644;
st501:
	if ( ++p == pe )
		goto _test_eof501;
case 501:
	switch( (*p) ) {
		case 9: goto st502;
		case 10: goto tr682;
		case 13: goto tr683;
	}
	goto tr644;
st502:
	if ( ++p == pe )
		goto _test_eof502;
case 502:
	if ( (*p) == 70 )
		goto st503;
	goto tr684;
st503:
	if ( ++p == pe )
		goto _test_eof503;
case 503:
	if ( (*p) == 79 )
		goto st504;
	goto tr684;
st504:
	if ( ++p == pe )
		goto _test_eof504;
case 504:
	if ( (*p) == 82 )
		goto st505;
	goto tr684;
st505:
	if ( ++p == pe )
		goto _test_eof505;
case 505:
	if ( (*p) == 77 )
		goto st506;
	goto tr684;
st506:
	if ( ++p == pe )
		goto _test_eof506;
case 506:
	if ( (*p) == 65 )
		goto st507;
	goto tr684;
st507:
	if ( ++p == pe )
		goto _test_eof507;
case 507:
	if ( (*p) == 84 )
		goto st508;
	goto tr684;
st508:
	if ( ++p == pe )
		goto _test_eof508;
case 508:
	if ( (*p) == 9 )
		goto st509;
	goto tr684;
tr693:
#line 179 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_sample_name(*this);
    }
	goto st509;
st509:
	if ( ++p == pe )
		goto _test_eof509;
case 509:
#line 10842 "inc/vcf/validator_detail_v43.hpp"
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr692;
	goto tr684;
tr692:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st510;
tr696:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st510;
st510:
	if ( ++p == pe )
		goto _test_eof510;
case 510:
#line 10866 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr693;
		case 10: goto tr694;
		case 13: goto tr695;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr696;
	goto tr684;
tr682:
#line 183 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_header_line(*this);
    }
#line 43 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st734;
tr694:
#line 179 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_sample_name(*this);
    }
#line 183 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_header_line(*this);
    }
#line 43 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st734;
st734:
	if ( ++p == pe )
		goto _test_eof734;
case 734:
#line 10915 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr986;
		case 59: goto tr986;
		case 60: goto tr987;
		case 92: goto tr986;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr986;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr986;
		} else if ( (*p) >= 63 )
			goto tr986;
	} else
		goto tr986;
	goto tr985;
tr988:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st511;
tr699:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st511;
tr986:
#line 70 "src/vcf/vcf_v43.ragel"
	{
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (ParsingWarning warn) {
          ErrorPolicy::handle_meta_section_warning(*this, warn.what());
        }
    }
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st511;
st511:
	if ( ++p == pe )
		goto _test_eof511;
case 511:
#line 10972 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr698;
		case 43: goto tr699;
		case 59: goto tr699;
		case 92: goto tr699;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr699;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr699;
		} else if ( (*p) >= 63 )
			goto tr699;
	} else
		goto tr699;
	goto tr697;
tr698:
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 189 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 53 "src/vcf/vcf_v43.ragel"
	{
        ++n_columns;
    }
	goto st512;
tr773:
#line 189 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 53 "src/vcf/vcf_v43.ragel"
	{
        ++n_columns;
    }
	goto st512;
st512:
	if ( ++p == pe )
		goto _test_eof512;
case 512:
#line 11019 "inc/vcf/validator_detail_v43.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr701;
	goto tr700;
tr701:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st513;
tr703:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st513;
st513:
	if ( ++p == pe )
		goto _test_eof513;
case 513:
#line 11043 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 9 )
		goto tr702;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr703;
	goto tr700;
tr708:
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st514;
tr702:
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 189 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 53 "src/vcf/vcf_v43.ragel"
	{
        ++n_columns;
    }
	goto st514;
st514:
	if ( ++p == pe )
		goto _test_eof514;
case 514:
#line 11073 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr705;
	} else if ( (*p) >= 33 )
		goto tr705;
	goto tr704;
tr705:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st515;
tr707:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st515;
st515:
	if ( ++p == pe )
		goto _test_eof515;
case 515:
#line 11100 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr706;
		case 59: goto tr708;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr707;
	goto tr704;
tr706:
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 189 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 53 "src/vcf/vcf_v43.ragel"
	{
        ++n_columns;
    }
	goto st516;
st516:
	if ( ++p == pe )
		goto _test_eof516;
case 516:
#line 11126 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 65: goto tr710;
		case 67: goto tr710;
		case 71: goto tr710;
		case 78: goto tr710;
		case 84: goto tr710;
		case 97: goto tr710;
		case 99: goto tr710;
		case 103: goto tr710;
		case 110: goto tr710;
		case 116: goto tr710;
	}
	goto tr709;
tr710:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st517;
tr712:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st517;
st517:
	if ( ++p == pe )
		goto _test_eof517;
case 517:
#line 11160 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr711;
		case 65: goto tr712;
		case 67: goto tr712;
		case 71: goto tr712;
		case 78: goto tr712;
		case 84: goto tr712;
		case 97: goto tr712;
		case 99: goto tr712;
		case 103: goto tr712;
		case 110: goto tr712;
		case 116: goto tr712;
	}
	goto tr709;
tr711:
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 189 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 53 "src/vcf/vcf_v43.ragel"
	{
        ++n_columns;
    }
	goto st518;
st518:
	if ( ++p == pe )
		goto _test_eof518;
case 518:
#line 11193 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 42: goto tr714;
		case 46: goto tr715;
		case 60: goto tr716;
		case 65: goto tr717;
		case 67: goto tr717;
		case 71: goto tr717;
		case 78: goto tr717;
		case 84: goto tr717;
		case 91: goto tr718;
		case 93: goto tr719;
		case 97: goto tr717;
		case 99: goto tr717;
		case 103: goto tr717;
		case 110: goto tr717;
		case 116: goto tr717;
	}
	goto tr713;
tr714:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st519;
tr948:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st519;
st519:
	if ( ++p == pe )
		goto _test_eof519;
case 519:
#line 11232 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr720;
		case 44: goto tr721;
	}
	goto tr713;
tr720:
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 189 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 53 "src/vcf/vcf_v43.ragel"
	{
        ++n_columns;
    }
	goto st520;
st520:
	if ( ++p == pe )
		goto _test_eof520;
case 520:
#line 11256 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr723;
		case 45: goto tr723;
		case 46: goto tr724;
		case 73: goto tr726;
		case 78: goto tr727;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr725;
	goto tr722;
tr723:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st521;
st521:
	if ( ++p == pe )
		goto _test_eof521;
case 521:
#line 11281 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 46: goto tr728;
		case 73: goto tr730;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr729;
	goto tr722;
tr728:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st522;
st522:
	if ( ++p == pe )
		goto _test_eof522;
case 522:
#line 11299 "inc/vcf/validator_detail_v43.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr731;
	goto tr722;
tr731:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st523;
st523:
	if ( ++p == pe )
		goto _test_eof523;
case 523:
#line 11313 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr732;
		case 69: goto tr733;
		case 101: goto tr733;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr731;
	goto tr722;
tr732:
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 189 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 53 "src/vcf/vcf_v43.ragel"
	{
        ++n_columns;
    }
	goto st524;
st524:
	if ( ++p == pe )
		goto _test_eof524;
case 524:
#line 11340 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 46: goto tr736;
		case 58: goto tr735;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr735;
		} else if ( (*p) > 57 ) {
			if ( 60 <= (*p) && (*p) <= 64 )
				goto tr735;
		} else
			goto tr737;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr735;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr735;
		} else
			goto tr737;
	} else
		goto tr737;
	goto tr734;
tr735:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st525;
st525:
	if ( ++p == pe )
		goto _test_eof525;
case 525:
#line 11376 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 58 )
		goto st525;
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto st525;
		} else if ( (*p) > 57 ) {
			if ( 60 <= (*p) && (*p) <= 64 )
				goto st525;
		} else
			goto tr739;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st525;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st525;
		} else
			goto tr739;
	} else
		goto tr739;
	goto tr734;
tr737:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st526;
tr739:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st526;
st526:
	if ( ++p == pe )
		goto _test_eof526;
case 526:
#line 11420 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr740;
		case 59: goto tr741;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr739;
	goto tr734;
tr740:
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 189 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 53 "src/vcf/vcf_v43.ragel"
	{
        ++n_columns;
    }
	goto st527;
st527:
	if ( ++p == pe )
		goto _test_eof527;
case 527:
#line 11446 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 46: goto tr743;
		case 49: goto tr745;
		case 65: goto tr746;
		case 66: goto tr747;
		case 67: goto tr748;
		case 68: goto tr749;
		case 69: goto tr750;
		case 72: goto tr751;
		case 77: goto tr752;
		case 78: goto tr753;
		case 83: goto tr754;
		case 86: goto tr755;
		case 95: goto tr744;
	}
	if ( (*p) < 70 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr744;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr744;
	} else
		goto tr744;
	goto tr742;
tr743:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st528;
st528:
	if ( ++p == pe )
		goto _test_eof528;
case 528:
#line 11485 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
	}
	goto tr756;
tr764:
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st529;
tr757:
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 189 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 53 "src/vcf/vcf_v43.ragel"
	{
        ++n_columns;
    }
	goto st529;
st529:
	if ( ++p == pe )
		goto _test_eof529;
case 529:
#line 11516 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 95 )
		goto tr761;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr761;
	} else if ( (*p) >= 65 )
		goto tr761;
	goto tr760;
tr761:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st530;
tr763:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st530;
st530:
	if ( ++p == pe )
		goto _test_eof530;
case 530:
#line 11545 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr762;
		case 46: goto tr763;
		case 58: goto tr764;
		case 95: goto tr763;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr763;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr763;
	} else
		goto tr763;
	goto tr760;
tr762:
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 189 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 53 "src/vcf/vcf_v43.ragel"
	{
        ++n_columns;
    }
	goto st531;
st531:
	if ( ++p == pe )
		goto _test_eof531;
case 531:
#line 11579 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 46 )
		goto tr766;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr767;
	goto tr765;
tr766:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st532;
tr776:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st532;
st532:
	if ( ++p == pe )
		goto _test_eof532;
case 532:
#line 11605 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr762;
		case 10: goto tr758;
		case 13: goto tr759;
		case 47: goto tr768;
		case 58: goto tr769;
		case 124: goto tr768;
	}
	goto tr765;
tr758:
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 189 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 193 "src/vcf/vcf_v43.ragel"
	{
        try {
          // Handle all columns and build record
          ParsePolicy::handle_body_line(*this);
          // Check warnings (non-blocking errors but potential mistakes anyway, only makes sense if the last record parsed was correct)
          OptionalPolicy::optional_check_body_entry(*this, ParsingState::records->back());
        } catch (ParsingError ex) {
          ErrorPolicy::handle_body_section_error(*this, ex.what());
        } catch (ParsingWarning ex) {
          ErrorPolicy::handle_body_section_warning(*this, ex.what());
        }
    }
#line 43 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st735;
st735:
	if ( ++p == pe )
		goto _test_eof735;
case 735:
#line 11652 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr988;
		case 59: goto tr988;
		case 60: goto st533;
		case 92: goto tr988;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr988;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr988;
		} else if ( (*p) >= 63 )
			goto tr988;
	} else
		goto tr988;
	goto tr697;
tr987:
#line 70 "src/vcf/vcf_v43.ragel"
	{
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (ParsingWarning warn) {
          ErrorPolicy::handle_meta_section_warning(*this, warn.what());
        }
    }
	goto st533;
st533:
	if ( ++p == pe )
		goto _test_eof533;
case 533:
#line 11685 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr770;
		case 59: goto tr770;
		case 92: goto tr770;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr770;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr770;
		} else if ( (*p) >= 63 )
			goto tr770;
	} else
		goto tr770;
	goto tr697;
tr770:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st534;
tr771:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st534;
st534:
	if ( ++p == pe )
		goto _test_eof534;
case 534:
#line 11723 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr771;
		case 59: goto tr771;
		case 62: goto tr772;
		case 92: goto tr771;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr771;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr771;
		} else if ( (*p) >= 63 )
			goto tr771;
	} else
		goto tr771;
	goto tr697;
tr772:
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st535;
st535:
	if ( ++p == pe )
		goto _test_eof535;
case 535:
#line 11752 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 9 )
		goto tr773;
	goto tr697;
tr759:
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 189 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 193 "src/vcf/vcf_v43.ragel"
	{
        try {
          // Handle all columns and build record
          ParsePolicy::handle_body_line(*this);
          // Check warnings (non-blocking errors but potential mistakes anyway, only makes sense if the last record parsed was correct)
          OptionalPolicy::optional_check_body_entry(*this, ParsingState::records->back());
        } catch (ParsingError ex) {
          ErrorPolicy::handle_body_section_error(*this, ex.what());
        } catch (ParsingWarning ex) {
          ErrorPolicy::handle_body_section_warning(*this, ex.what());
        }
    }
#line 43 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st536;
st536:
	if ( ++p == pe )
		goto _test_eof536;
case 536:
#line 11793 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 10 )
		goto st735;
	goto tr774;
tr768:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st537;
st537:
	if ( ++p == pe )
		goto _test_eof537;
case 537:
#line 11807 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 46 )
		goto tr776;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr777;
	goto tr765;
tr767:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st538;
tr777:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st538;
st538:
	if ( ++p == pe )
		goto _test_eof538;
case 538:
#line 11833 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr762;
		case 10: goto tr758;
		case 13: goto tr759;
		case 47: goto tr768;
		case 58: goto tr769;
		case 124: goto tr768;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr777;
	goto tr765;
tr769:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st539;
st539:
	if ( ++p == pe )
		goto _test_eof539;
case 539:
#line 11855 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) > 57 ) {
		if ( 59 <= (*p) && (*p) <= 126 )
			goto tr779;
	} else if ( (*p) >= 33 )
		goto tr779;
	goto tr778;
tr779:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st540;
st540:
	if ( ++p == pe )
		goto _test_eof540;
case 540:
#line 11872 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr762;
		case 10: goto tr758;
		case 13: goto tr759;
		case 58: goto tr769;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr779;
	goto tr778;
tr744:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st541;
tr780:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st541;
st541:
	if ( ++p == pe )
		goto _test_eof541;
case 541:
#line 11902 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 46: goto tr780;
		case 59: goto tr781;
		case 61: goto tr782;
		case 95: goto tr780;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr780;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr780;
	} else
		goto tr780;
	goto tr742;
tr781:
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st542;
st542:
	if ( ++p == pe )
		goto _test_eof542;
case 542:
#line 11931 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 49: goto tr745;
		case 65: goto tr746;
		case 66: goto tr747;
		case 67: goto tr748;
		case 68: goto tr749;
		case 69: goto tr750;
		case 72: goto tr751;
		case 77: goto tr752;
		case 78: goto tr753;
		case 83: goto tr754;
		case 86: goto tr755;
		case 95: goto tr744;
	}
	if ( (*p) < 70 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr744;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr744;
	} else
		goto tr744;
	goto tr742;
tr745:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st543;
st543:
	if ( ++p == pe )
		goto _test_eof543;
case 543:
#line 11969 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 46: goto tr780;
		case 48: goto tr783;
		case 59: goto tr781;
		case 61: goto tr782;
		case 95: goto tr780;
	}
	if ( (*p) < 65 ) {
		if ( 49 <= (*p) && (*p) <= 57 )
			goto tr780;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr780;
	} else
		goto tr780;
	goto tr742;
tr783:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st544;
st544:
	if ( ++p == pe )
		goto _test_eof544;
case 544:
#line 11999 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 46: goto tr780;
		case 48: goto tr784;
		case 59: goto tr781;
		case 61: goto tr782;
		case 95: goto tr780;
	}
	if ( (*p) < 65 ) {
		if ( 49 <= (*p) && (*p) <= 57 )
			goto tr780;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr780;
	} else
		goto tr780;
	goto tr742;
tr784:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st545;
st545:
	if ( ++p == pe )
		goto _test_eof545;
case 545:
#line 12029 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 46: goto tr780;
		case 48: goto tr785;
		case 59: goto tr781;
		case 61: goto tr782;
		case 95: goto tr780;
	}
	if ( (*p) < 65 ) {
		if ( 49 <= (*p) && (*p) <= 57 )
			goto tr780;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr780;
	} else
		goto tr780;
	goto tr742;
tr785:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st546;
st546:
	if ( ++p == pe )
		goto _test_eof546;
case 546:
#line 12059 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 46: goto tr780;
		case 59: goto tr781;
		case 61: goto tr782;
		case 71: goto tr786;
		case 95: goto tr780;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr780;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr780;
	} else
		goto tr780;
	goto tr742;
tr782:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st547;
st547:
	if ( ++p == pe )
		goto _test_eof547;
case 547:
#line 12089 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr788;
	} else if ( (*p) >= 32 )
		goto tr788;
	goto tr787;
tr788:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st548;
st548:
	if ( ++p == pe )
		goto _test_eof548;
case 548:
#line 12106 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 59: goto tr781;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr788;
	goto tr787;
tr786:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st549;
st549:
	if ( ++p == pe )
		goto _test_eof549;
case 549:
#line 12126 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 46: goto tr780;
		case 59: goto tr781;
		case 61: goto tr790;
		case 95: goto tr780;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr780;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr780;
	} else
		goto tr780;
	goto tr789;
tr790:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st550;
st550:
	if ( ++p == pe )
		goto _test_eof550;
case 550:
#line 12155 "inc/vcf/validator_detail_v43.hpp"
	if ( 48 <= (*p) && (*p) <= 49 )
		goto tr792;
	goto tr791;
tr792:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st551;
st551:
	if ( ++p == pe )
		goto _test_eof551;
case 551:
#line 12169 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 59: goto tr781;
	}
	goto tr791;
tr746:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st552;
st552:
	if ( ++p == pe )
		goto _test_eof552;
case 552:
#line 12191 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 46: goto tr780;
		case 59: goto tr781;
		case 61: goto tr782;
		case 65: goto tr793;
		case 67: goto tr794;
		case 68: goto tr795;
		case 70: goto tr796;
		case 78: goto tr797;
		case 95: goto tr780;
	}
	if ( (*p) < 66 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr780;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr780;
	} else
		goto tr780;
	goto tr742;
tr793:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st553;
st553:
	if ( ++p == pe )
		goto _test_eof553;
case 553:
#line 12225 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 46: goto tr780;
		case 61: goto tr798;
		case 95: goto tr780;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr780;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr780;
	} else
		goto tr780;
	goto tr742;
tr798:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st554;
st554:
	if ( ++p == pe )
		goto _test_eof554;
case 554:
#line 12250 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 65: goto tr801;
		case 67: goto tr801;
		case 71: goto tr801;
		case 78: goto tr801;
		case 84: goto tr801;
		case 97: goto tr801;
		case 99: goto tr801;
		case 103: goto tr801;
		case 110: goto tr801;
		case 116: goto tr801;
	}
	if ( 45 <= (*p) && (*p) <= 46 )
		goto tr800;
	goto tr799;
tr800:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st555;
st555:
	if ( ++p == pe )
		goto _test_eof555;
case 555:
#line 12276 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 59: goto tr781;
	}
	goto tr799;
tr801:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st556;
st556:
	if ( ++p == pe )
		goto _test_eof556;
case 556:
#line 12294 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 59: goto tr781;
		case 65: goto tr801;
		case 67: goto tr801;
		case 71: goto tr801;
		case 78: goto tr801;
		case 84: goto tr801;
		case 97: goto tr801;
		case 99: goto tr801;
		case 103: goto tr801;
		case 110: goto tr801;
		case 116: goto tr801;
	}
	goto tr799;
tr794:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st557;
st557:
	if ( ++p == pe )
		goto _test_eof557;
case 557:
#line 12322 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 46: goto tr780;
		case 61: goto tr802;
		case 95: goto tr780;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr780;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr780;
	} else
		goto tr780;
	goto tr742;
tr802:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st558;
st558:
	if ( ++p == pe )
		goto _test_eof558;
case 558:
#line 12347 "inc/vcf/validator_detail_v43.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr804;
	goto tr803;
tr804:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st559;
st559:
	if ( ++p == pe )
		goto _test_eof559;
case 559:
#line 12361 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 44: goto tr802;
		case 59: goto tr781;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr804;
	goto tr803;
tr795:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st560;
st560:
	if ( ++p == pe )
		goto _test_eof560;
case 560:
#line 12382 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 46: goto tr780;
		case 61: goto tr805;
		case 70: goto tr806;
		case 82: goto tr807;
		case 95: goto tr780;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr780;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr780;
	} else
		goto tr780;
	goto tr742;
tr805:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st561;
st561:
	if ( ++p == pe )
		goto _test_eof561;
case 561:
#line 12409 "inc/vcf/validator_detail_v43.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr809;
	goto tr808;
tr809:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st562;
st562:
	if ( ++p == pe )
		goto _test_eof562;
case 562:
#line 12423 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 44: goto tr805;
		case 59: goto tr781;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr809;
	goto tr808;
tr806:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st563;
st563:
	if ( ++p == pe )
		goto _test_eof563;
case 563:
#line 12444 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 46: goto tr780;
		case 61: goto tr810;
		case 95: goto tr780;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr780;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr780;
	} else
		goto tr780;
	goto tr742;
tr810:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st564;
st564:
	if ( ++p == pe )
		goto _test_eof564;
case 564:
#line 12469 "inc/vcf/validator_detail_v43.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr812;
	goto tr811;
tr812:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st565;
st565:
	if ( ++p == pe )
		goto _test_eof565;
case 565:
#line 12483 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 44: goto tr810;
		case 59: goto tr781;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr812;
	goto tr811;
tr807:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st566;
st566:
	if ( ++p == pe )
		goto _test_eof566;
case 566:
#line 12504 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 46: goto tr780;
		case 61: goto tr813;
		case 95: goto tr780;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr780;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr780;
	} else
		goto tr780;
	goto tr742;
tr813:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st567;
st567:
	if ( ++p == pe )
		goto _test_eof567;
case 567:
#line 12529 "inc/vcf/validator_detail_v43.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr815;
	goto tr814;
tr815:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st568;
st568:
	if ( ++p == pe )
		goto _test_eof568;
case 568:
#line 12543 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 44: goto tr813;
		case 59: goto tr781;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr815;
	goto tr814;
tr796:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st569;
st569:
	if ( ++p == pe )
		goto _test_eof569;
case 569:
#line 12564 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 46: goto tr780;
		case 61: goto tr816;
		case 95: goto tr780;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr780;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr780;
	} else
		goto tr780;
	goto tr742;
tr816:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st570;
st570:
	if ( ++p == pe )
		goto _test_eof570;
case 570:
#line 12589 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr818;
		case 45: goto tr818;
		case 46: goto tr819;
		case 73: goto tr821;
		case 78: goto tr822;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr820;
	goto tr817;
tr818:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st571;
st571:
	if ( ++p == pe )
		goto _test_eof571;
case 571:
#line 12610 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 46: goto tr819;
		case 73: goto tr821;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr820;
	goto tr817;
tr819:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st572;
st572:
	if ( ++p == pe )
		goto _test_eof572;
case 572:
#line 12628 "inc/vcf/validator_detail_v43.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr823;
	goto tr817;
tr823:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st573;
st573:
	if ( ++p == pe )
		goto _test_eof573;
case 573:
#line 12642 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 44: goto tr816;
		case 59: goto tr781;
		case 69: goto tr824;
		case 101: goto tr824;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr823;
	goto tr817;
tr824:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st574;
st574:
	if ( ++p == pe )
		goto _test_eof574;
case 574:
#line 12665 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr825;
		case 45: goto tr825;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr826;
	goto tr817;
tr825:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st575;
st575:
	if ( ++p == pe )
		goto _test_eof575;
case 575:
#line 12683 "inc/vcf/validator_detail_v43.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr826;
	goto tr817;
tr826:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st576;
st576:
	if ( ++p == pe )
		goto _test_eof576;
case 576:
#line 12697 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 44: goto tr816;
		case 59: goto tr781;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr826;
	goto tr817;
tr820:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st577;
st577:
	if ( ++p == pe )
		goto _test_eof577;
case 577:
#line 12718 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 44: goto tr816;
		case 46: goto tr819;
		case 59: goto tr781;
		case 69: goto tr824;
		case 101: goto tr824;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr820;
	goto tr817;
tr821:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st578;
st578:
	if ( ++p == pe )
		goto _test_eof578;
case 578:
#line 12742 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 110 )
		goto tr827;
	goto tr817;
tr827:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st579;
st579:
	if ( ++p == pe )
		goto _test_eof579;
case 579:
#line 12756 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 102 )
		goto tr828;
	goto tr817;
tr828:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st580;
st580:
	if ( ++p == pe )
		goto _test_eof580;
case 580:
#line 12770 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 44: goto tr816;
		case 59: goto tr781;
	}
	goto tr817;
tr822:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st581;
st581:
	if ( ++p == pe )
		goto _test_eof581;
case 581:
#line 12789 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 97 )
		goto tr829;
	goto tr817;
tr829:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st582;
st582:
	if ( ++p == pe )
		goto _test_eof582;
case 582:
#line 12803 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 78 )
		goto tr828;
	goto tr817;
tr797:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st583;
st583:
	if ( ++p == pe )
		goto _test_eof583;
case 583:
#line 12817 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 46: goto tr780;
		case 61: goto tr830;
		case 95: goto tr780;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr780;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr780;
	} else
		goto tr780;
	goto tr742;
tr830:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st584;
st584:
	if ( ++p == pe )
		goto _test_eof584;
case 584:
#line 12842 "inc/vcf/validator_detail_v43.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr832;
	goto tr831;
tr832:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st585;
st585:
	if ( ++p == pe )
		goto _test_eof585;
case 585:
#line 12856 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 59: goto tr781;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr832;
	goto tr831;
tr747:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st586;
st586:
	if ( ++p == pe )
		goto _test_eof586;
case 586:
#line 12880 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 46: goto tr780;
		case 59: goto tr781;
		case 61: goto tr782;
		case 81: goto tr833;
		case 95: goto tr780;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr780;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr780;
	} else
		goto tr780;
	goto tr742;
tr833:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st587;
st587:
	if ( ++p == pe )
		goto _test_eof587;
case 587:
#line 12910 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 46: goto tr780;
		case 61: goto tr834;
		case 95: goto tr780;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr780;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr780;
	} else
		goto tr780;
	goto tr742;
tr834:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st588;
st588:
	if ( ++p == pe )
		goto _test_eof588;
case 588:
#line 12935 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr836;
		case 45: goto tr836;
		case 46: goto tr837;
		case 73: goto tr839;
		case 78: goto tr840;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr838;
	goto tr835;
tr836:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st589;
st589:
	if ( ++p == pe )
		goto _test_eof589;
case 589:
#line 12956 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 46: goto tr837;
		case 73: goto tr839;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr838;
	goto tr835;
tr837:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st590;
st590:
	if ( ++p == pe )
		goto _test_eof590;
case 590:
#line 12974 "inc/vcf/validator_detail_v43.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr841;
	goto tr835;
tr841:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st591;
st591:
	if ( ++p == pe )
		goto _test_eof591;
case 591:
#line 12988 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 59: goto tr781;
		case 69: goto tr842;
		case 101: goto tr842;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr841;
	goto tr835;
tr842:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st592;
st592:
	if ( ++p == pe )
		goto _test_eof592;
case 592:
#line 13010 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr843;
		case 45: goto tr843;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr844;
	goto tr835;
tr843:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st593;
st593:
	if ( ++p == pe )
		goto _test_eof593;
case 593:
#line 13028 "inc/vcf/validator_detail_v43.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr844;
	goto tr835;
tr844:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st594;
st594:
	if ( ++p == pe )
		goto _test_eof594;
case 594:
#line 13042 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 59: goto tr781;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr844;
	goto tr835;
tr838:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st595;
st595:
	if ( ++p == pe )
		goto _test_eof595;
case 595:
#line 13062 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 46: goto tr837;
		case 59: goto tr781;
		case 69: goto tr842;
		case 101: goto tr842;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr838;
	goto tr835;
tr839:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st596;
st596:
	if ( ++p == pe )
		goto _test_eof596;
case 596:
#line 13085 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 110 )
		goto tr845;
	goto tr835;
tr845:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st597;
st597:
	if ( ++p == pe )
		goto _test_eof597;
case 597:
#line 13099 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 102 )
		goto tr846;
	goto tr835;
tr846:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st598;
st598:
	if ( ++p == pe )
		goto _test_eof598;
case 598:
#line 13113 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 59: goto tr781;
	}
	goto tr835;
tr840:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st599;
st599:
	if ( ++p == pe )
		goto _test_eof599;
case 599:
#line 13131 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 97 )
		goto tr847;
	goto tr835;
tr847:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st600;
st600:
	if ( ++p == pe )
		goto _test_eof600;
case 600:
#line 13145 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 78 )
		goto tr846;
	goto tr835;
tr748:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st601;
st601:
	if ( ++p == pe )
		goto _test_eof601;
case 601:
#line 13163 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 46: goto tr780;
		case 59: goto tr781;
		case 61: goto tr782;
		case 73: goto tr848;
		case 95: goto tr780;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr780;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr780;
	} else
		goto tr780;
	goto tr742;
tr848:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st602;
st602:
	if ( ++p == pe )
		goto _test_eof602;
case 602:
#line 13193 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 46: goto tr780;
		case 59: goto tr781;
		case 61: goto tr782;
		case 71: goto tr849;
		case 95: goto tr780;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr780;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr780;
	} else
		goto tr780;
	goto tr742;
tr849:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st603;
st603:
	if ( ++p == pe )
		goto _test_eof603;
case 603:
#line 13223 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 46: goto tr780;
		case 59: goto tr781;
		case 61: goto tr782;
		case 65: goto tr850;
		case 95: goto tr780;
	}
	if ( (*p) < 66 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr780;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr780;
	} else
		goto tr780;
	goto tr742;
tr850:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st604;
st604:
	if ( ++p == pe )
		goto _test_eof604;
case 604:
#line 13253 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 46: goto tr780;
		case 59: goto tr781;
		case 61: goto tr782;
		case 82: goto tr851;
		case 95: goto tr780;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr780;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr780;
	} else
		goto tr780;
	goto tr742;
tr851:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st605;
st605:
	if ( ++p == pe )
		goto _test_eof605;
case 605:
#line 13283 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 46: goto tr780;
		case 61: goto tr852;
		case 95: goto tr780;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr780;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr780;
	} else
		goto tr780;
	goto tr742;
tr852:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st606;
st606:
	if ( ++p == pe )
		goto _test_eof606;
case 606:
#line 13308 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr854;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr854;
	} else
		goto tr854;
	goto tr853;
tr854:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st607;
st607:
	if ( ++p == pe )
		goto _test_eof607;
case 607:
#line 13328 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 59: goto tr781;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr854;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr854;
	} else
		goto tr854;
	goto tr853;
tr749:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st608;
st608:
	if ( ++p == pe )
		goto _test_eof608;
case 608:
#line 13358 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 46: goto tr780;
		case 59: goto tr781;
		case 61: goto tr782;
		case 66: goto tr855;
		case 80: goto tr856;
		case 95: goto tr780;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr780;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr780;
	} else
		goto tr780;
	goto tr742;
tr855:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st609;
st609:
	if ( ++p == pe )
		goto _test_eof609;
case 609:
#line 13389 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 46: goto tr780;
		case 59: goto tr781;
		case 61: goto tr858;
		case 95: goto tr780;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr780;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr780;
	} else
		goto tr780;
	goto tr857;
tr858:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st610;
st610:
	if ( ++p == pe )
		goto _test_eof610;
case 610:
#line 13418 "inc/vcf/validator_detail_v43.hpp"
	if ( 48 <= (*p) && (*p) <= 49 )
		goto tr860;
	goto tr859;
tr860:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st611;
st611:
	if ( ++p == pe )
		goto _test_eof611;
case 611:
#line 13432 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 59: goto tr781;
	}
	goto tr859;
tr856:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st612;
st612:
	if ( ++p == pe )
		goto _test_eof612;
case 612:
#line 13450 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 46: goto tr780;
		case 61: goto tr861;
		case 95: goto tr780;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr780;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr780;
	} else
		goto tr780;
	goto tr742;
tr861:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st613;
st613:
	if ( ++p == pe )
		goto _test_eof613;
case 613:
#line 13475 "inc/vcf/validator_detail_v43.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr863;
	goto tr862;
tr863:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st614;
st614:
	if ( ++p == pe )
		goto _test_eof614;
case 614:
#line 13489 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 59: goto tr781;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr863;
	goto tr862;
tr750:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st615;
st615:
	if ( ++p == pe )
		goto _test_eof615;
case 615:
#line 13513 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 46: goto tr780;
		case 59: goto tr781;
		case 61: goto tr782;
		case 78: goto tr864;
		case 95: goto tr780;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr780;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr780;
	} else
		goto tr780;
	goto tr742;
tr864:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st616;
st616:
	if ( ++p == pe )
		goto _test_eof616;
case 616:
#line 13543 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 46: goto tr780;
		case 59: goto tr781;
		case 61: goto tr782;
		case 68: goto tr865;
		case 95: goto tr780;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr780;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr780;
	} else
		goto tr780;
	goto tr742;
tr865:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st617;
st617:
	if ( ++p == pe )
		goto _test_eof617;
case 617:
#line 13573 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 46: goto tr780;
		case 61: goto tr866;
		case 95: goto tr780;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr780;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr780;
	} else
		goto tr780;
	goto tr742;
tr866:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st618;
st618:
	if ( ++p == pe )
		goto _test_eof618;
case 618:
#line 13598 "inc/vcf/validator_detail_v43.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr868;
	goto tr867;
tr868:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st619;
st619:
	if ( ++p == pe )
		goto _test_eof619;
case 619:
#line 13612 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 59: goto tr781;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr868;
	goto tr867;
tr751:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st620;
st620:
	if ( ++p == pe )
		goto _test_eof620;
case 620:
#line 13636 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 46: goto tr780;
		case 50: goto tr869;
		case 51: goto tr870;
		case 59: goto tr781;
		case 61: goto tr782;
		case 95: goto tr780;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr780;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr780;
	} else
		goto tr780;
	goto tr742;
tr869:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st621;
st621:
	if ( ++p == pe )
		goto _test_eof621;
case 621:
#line 13667 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 46: goto tr780;
		case 59: goto tr781;
		case 61: goto tr872;
		case 95: goto tr780;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr780;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr780;
	} else
		goto tr780;
	goto tr871;
tr872:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st622;
st622:
	if ( ++p == pe )
		goto _test_eof622;
case 622:
#line 13696 "inc/vcf/validator_detail_v43.hpp"
	if ( 48 <= (*p) && (*p) <= 49 )
		goto tr874;
	goto tr873;
tr874:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st623;
st623:
	if ( ++p == pe )
		goto _test_eof623;
case 623:
#line 13710 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 59: goto tr781;
	}
	goto tr873;
tr870:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st624;
st624:
	if ( ++p == pe )
		goto _test_eof624;
case 624:
#line 13728 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 46: goto tr780;
		case 59: goto tr781;
		case 61: goto tr876;
		case 95: goto tr780;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr780;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr780;
	} else
		goto tr780;
	goto tr875;
tr876:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st625;
st625:
	if ( ++p == pe )
		goto _test_eof625;
case 625:
#line 13757 "inc/vcf/validator_detail_v43.hpp"
	if ( 48 <= (*p) && (*p) <= 49 )
		goto tr878;
	goto tr877;
tr878:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st626;
st626:
	if ( ++p == pe )
		goto _test_eof626;
case 626:
#line 13771 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 59: goto tr781;
	}
	goto tr877;
tr752:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st627;
st627:
	if ( ++p == pe )
		goto _test_eof627;
case 627:
#line 13793 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 46: goto tr780;
		case 59: goto tr781;
		case 61: goto tr782;
		case 81: goto tr879;
		case 95: goto tr780;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr780;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr780;
	} else
		goto tr780;
	goto tr742;
tr879:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st628;
st628:
	if ( ++p == pe )
		goto _test_eof628;
case 628:
#line 13823 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 46: goto tr780;
		case 48: goto tr880;
		case 61: goto tr881;
		case 95: goto tr780;
	}
	if ( (*p) < 65 ) {
		if ( 49 <= (*p) && (*p) <= 57 )
			goto tr780;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr780;
	} else
		goto tr780;
	goto tr742;
tr880:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st629;
st629:
	if ( ++p == pe )
		goto _test_eof629;
case 629:
#line 13849 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 46: goto tr780;
		case 61: goto tr882;
		case 95: goto tr780;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr780;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr780;
	} else
		goto tr780;
	goto tr742;
tr882:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st630;
st630:
	if ( ++p == pe )
		goto _test_eof630;
case 630:
#line 13874 "inc/vcf/validator_detail_v43.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr884;
	goto tr883;
tr884:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st631;
st631:
	if ( ++p == pe )
		goto _test_eof631;
case 631:
#line 13888 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 59: goto tr781;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr884;
	goto tr883;
tr881:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st632;
st632:
	if ( ++p == pe )
		goto _test_eof632;
case 632:
#line 13908 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr886;
		case 45: goto tr886;
		case 46: goto tr887;
		case 73: goto tr889;
		case 78: goto tr890;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr888;
	goto tr885;
tr886:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st633;
st633:
	if ( ++p == pe )
		goto _test_eof633;
case 633:
#line 13929 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 46: goto tr887;
		case 73: goto tr889;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr888;
	goto tr885;
tr887:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st634;
st634:
	if ( ++p == pe )
		goto _test_eof634;
case 634:
#line 13947 "inc/vcf/validator_detail_v43.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr891;
	goto tr885;
tr891:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st635;
st635:
	if ( ++p == pe )
		goto _test_eof635;
case 635:
#line 13961 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 59: goto tr781;
		case 69: goto tr892;
		case 101: goto tr892;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr891;
	goto tr885;
tr892:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st636;
st636:
	if ( ++p == pe )
		goto _test_eof636;
case 636:
#line 13983 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr893;
		case 45: goto tr893;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr894;
	goto tr885;
tr893:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st637;
st637:
	if ( ++p == pe )
		goto _test_eof637;
case 637:
#line 14001 "inc/vcf/validator_detail_v43.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr894;
	goto tr885;
tr894:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st638;
st638:
	if ( ++p == pe )
		goto _test_eof638;
case 638:
#line 14015 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 59: goto tr781;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr894;
	goto tr885;
tr888:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st639;
st639:
	if ( ++p == pe )
		goto _test_eof639;
case 639:
#line 14035 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 46: goto tr887;
		case 59: goto tr781;
		case 69: goto tr892;
		case 101: goto tr892;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr888;
	goto tr885;
tr889:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st640;
st640:
	if ( ++p == pe )
		goto _test_eof640;
case 640:
#line 14058 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 110 )
		goto tr895;
	goto tr885;
tr895:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st641;
st641:
	if ( ++p == pe )
		goto _test_eof641;
case 641:
#line 14072 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 102 )
		goto tr896;
	goto tr885;
tr896:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st642;
st642:
	if ( ++p == pe )
		goto _test_eof642;
case 642:
#line 14086 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 59: goto tr781;
	}
	goto tr885;
tr890:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st643;
st643:
	if ( ++p == pe )
		goto _test_eof643;
case 643:
#line 14104 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 97 )
		goto tr897;
	goto tr885;
tr897:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st644;
st644:
	if ( ++p == pe )
		goto _test_eof644;
case 644:
#line 14118 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 78 )
		goto tr896;
	goto tr885;
tr753:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st645;
st645:
	if ( ++p == pe )
		goto _test_eof645;
case 645:
#line 14136 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 46: goto tr780;
		case 59: goto tr781;
		case 61: goto tr782;
		case 83: goto tr898;
		case 95: goto tr780;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr780;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr780;
	} else
		goto tr780;
	goto tr742;
tr898:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st646;
st646:
	if ( ++p == pe )
		goto _test_eof646;
case 646:
#line 14166 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 46: goto tr780;
		case 61: goto tr899;
		case 95: goto tr780;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr780;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr780;
	} else
		goto tr780;
	goto tr742;
tr899:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st647;
st647:
	if ( ++p == pe )
		goto _test_eof647;
case 647:
#line 14191 "inc/vcf/validator_detail_v43.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr901;
	goto tr900;
tr901:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st648;
st648:
	if ( ++p == pe )
		goto _test_eof648;
case 648:
#line 14205 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 59: goto tr781;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr901;
	goto tr900;
tr754:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st649;
st649:
	if ( ++p == pe )
		goto _test_eof649;
case 649:
#line 14229 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 46: goto tr780;
		case 59: goto tr781;
		case 61: goto tr782;
		case 66: goto tr902;
		case 79: goto tr903;
		case 95: goto tr780;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr780;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr780;
	} else
		goto tr780;
	goto tr742;
tr902:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st650;
st650:
	if ( ++p == pe )
		goto _test_eof650;
case 650:
#line 14260 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 46: goto tr780;
		case 61: goto tr904;
		case 95: goto tr780;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr780;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr780;
	} else
		goto tr780;
	goto tr742;
tr904:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st651;
st651:
	if ( ++p == pe )
		goto _test_eof651;
case 651:
#line 14285 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr906;
		case 45: goto tr906;
		case 46: goto tr907;
		case 73: goto tr909;
		case 78: goto tr910;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr908;
	goto tr905;
tr906:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st652;
st652:
	if ( ++p == pe )
		goto _test_eof652;
case 652:
#line 14306 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 46: goto tr907;
		case 73: goto tr909;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr908;
	goto tr905;
tr907:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st653;
st653:
	if ( ++p == pe )
		goto _test_eof653;
case 653:
#line 14324 "inc/vcf/validator_detail_v43.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr911;
	goto tr905;
tr911:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st654;
st654:
	if ( ++p == pe )
		goto _test_eof654;
case 654:
#line 14338 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 59: goto tr781;
		case 69: goto tr912;
		case 101: goto tr912;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr911;
	goto tr905;
tr912:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st655;
st655:
	if ( ++p == pe )
		goto _test_eof655;
case 655:
#line 14360 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr913;
		case 45: goto tr913;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr914;
	goto tr905;
tr913:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st656;
st656:
	if ( ++p == pe )
		goto _test_eof656;
case 656:
#line 14378 "inc/vcf/validator_detail_v43.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr914;
	goto tr905;
tr914:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st657;
st657:
	if ( ++p == pe )
		goto _test_eof657;
case 657:
#line 14392 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 59: goto tr781;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr914;
	goto tr905;
tr908:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st658;
st658:
	if ( ++p == pe )
		goto _test_eof658;
case 658:
#line 14412 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 46: goto tr907;
		case 59: goto tr781;
		case 69: goto tr912;
		case 101: goto tr912;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr908;
	goto tr905;
tr909:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st659;
st659:
	if ( ++p == pe )
		goto _test_eof659;
case 659:
#line 14435 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 110 )
		goto tr915;
	goto tr905;
tr915:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st660;
st660:
	if ( ++p == pe )
		goto _test_eof660;
case 660:
#line 14449 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 102 )
		goto tr916;
	goto tr905;
tr916:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st661;
st661:
	if ( ++p == pe )
		goto _test_eof661;
case 661:
#line 14463 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 59: goto tr781;
	}
	goto tr905;
tr910:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st662;
st662:
	if ( ++p == pe )
		goto _test_eof662;
case 662:
#line 14481 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 97 )
		goto tr917;
	goto tr905;
tr917:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st663;
st663:
	if ( ++p == pe )
		goto _test_eof663;
case 663:
#line 14495 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 78 )
		goto tr916;
	goto tr905;
tr903:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st664;
st664:
	if ( ++p == pe )
		goto _test_eof664;
case 664:
#line 14509 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 46: goto tr780;
		case 59: goto tr781;
		case 61: goto tr782;
		case 77: goto tr918;
		case 95: goto tr780;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr780;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr780;
	} else
		goto tr780;
	goto tr742;
tr918:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st665;
st665:
	if ( ++p == pe )
		goto _test_eof665;
case 665:
#line 14539 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 46: goto tr780;
		case 59: goto tr781;
		case 61: goto tr782;
		case 65: goto tr919;
		case 95: goto tr780;
	}
	if ( (*p) < 66 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr780;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr780;
	} else
		goto tr780;
	goto tr742;
tr919:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st666;
st666:
	if ( ++p == pe )
		goto _test_eof666;
case 666:
#line 14569 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 46: goto tr780;
		case 59: goto tr781;
		case 61: goto tr782;
		case 84: goto tr920;
		case 95: goto tr780;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr780;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr780;
	} else
		goto tr780;
	goto tr742;
tr920:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st667;
st667:
	if ( ++p == pe )
		goto _test_eof667;
case 667:
#line 14599 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 46: goto tr780;
		case 59: goto tr781;
		case 61: goto tr782;
		case 73: goto tr921;
		case 95: goto tr780;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr780;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr780;
	} else
		goto tr780;
	goto tr742;
tr921:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st668;
st668:
	if ( ++p == pe )
		goto _test_eof668;
case 668:
#line 14629 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 46: goto tr780;
		case 59: goto tr781;
		case 61: goto tr782;
		case 67: goto tr922;
		case 95: goto tr780;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr780;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr780;
	} else
		goto tr780;
	goto tr742;
tr922:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st669;
st669:
	if ( ++p == pe )
		goto _test_eof669;
case 669:
#line 14659 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 46: goto tr780;
		case 59: goto tr781;
		case 61: goto tr924;
		case 95: goto tr780;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr780;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr780;
	} else
		goto tr780;
	goto tr923;
tr924:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st670;
st670:
	if ( ++p == pe )
		goto _test_eof670;
case 670:
#line 14688 "inc/vcf/validator_detail_v43.hpp"
	if ( 48 <= (*p) && (*p) <= 49 )
		goto tr926;
	goto tr925;
tr926:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st671;
st671:
	if ( ++p == pe )
		goto _test_eof671;
case 671:
#line 14702 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 59: goto tr781;
	}
	goto tr925;
tr755:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st672;
st672:
	if ( ++p == pe )
		goto _test_eof672;
case 672:
#line 14724 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 46: goto tr780;
		case 59: goto tr781;
		case 61: goto tr782;
		case 65: goto tr927;
		case 95: goto tr780;
	}
	if ( (*p) < 66 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr780;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr780;
	} else
		goto tr780;
	goto tr742;
tr927:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st673;
st673:
	if ( ++p == pe )
		goto _test_eof673;
case 673:
#line 14754 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 46: goto tr780;
		case 59: goto tr781;
		case 61: goto tr782;
		case 76: goto tr928;
		case 95: goto tr780;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr780;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr780;
	} else
		goto tr780;
	goto tr742;
tr928:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st674;
st674:
	if ( ++p == pe )
		goto _test_eof674;
case 674:
#line 14784 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 46: goto tr780;
		case 59: goto tr781;
		case 61: goto tr782;
		case 73: goto tr929;
		case 95: goto tr780;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr780;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr780;
	} else
		goto tr780;
	goto tr742;
tr929:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st675;
st675:
	if ( ++p == pe )
		goto _test_eof675;
case 675:
#line 14814 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 46: goto tr780;
		case 59: goto tr781;
		case 61: goto tr782;
		case 68: goto tr930;
		case 95: goto tr780;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr780;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr780;
	} else
		goto tr780;
	goto tr742;
tr930:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st676;
st676:
	if ( ++p == pe )
		goto _test_eof676;
case 676:
#line 14844 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 46: goto tr780;
		case 59: goto tr781;
		case 61: goto tr782;
		case 65: goto tr931;
		case 95: goto tr780;
	}
	if ( (*p) < 66 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr780;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr780;
	} else
		goto tr780;
	goto tr742;
tr931:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st677;
st677:
	if ( ++p == pe )
		goto _test_eof677;
case 677:
#line 14874 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 46: goto tr780;
		case 59: goto tr781;
		case 61: goto tr782;
		case 84: goto tr932;
		case 95: goto tr780;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr780;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr780;
	} else
		goto tr780;
	goto tr742;
tr932:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st678;
st678:
	if ( ++p == pe )
		goto _test_eof678;
case 678:
#line 14904 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 46: goto tr780;
		case 59: goto tr781;
		case 61: goto tr782;
		case 69: goto tr933;
		case 95: goto tr780;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr780;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr780;
	} else
		goto tr780;
	goto tr742;
tr933:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st679;
st679:
	if ( ++p == pe )
		goto _test_eof679;
case 679:
#line 14934 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 46: goto tr780;
		case 59: goto tr781;
		case 61: goto tr782;
		case 68: goto tr934;
		case 95: goto tr780;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr780;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr780;
	} else
		goto tr780;
	goto tr742;
tr934:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st680;
st680:
	if ( ++p == pe )
		goto _test_eof680;
case 680:
#line 14964 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 46: goto tr780;
		case 59: goto tr781;
		case 61: goto tr936;
		case 95: goto tr780;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr780;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr780;
	} else
		goto tr780;
	goto tr935;
tr936:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st681;
st681:
	if ( ++p == pe )
		goto _test_eof681;
case 681:
#line 14993 "inc/vcf/validator_detail_v43.hpp"
	if ( 48 <= (*p) && (*p) <= 49 )
		goto tr938;
	goto tr937;
tr938:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st682;
st682:
	if ( ++p == pe )
		goto _test_eof682;
case 682:
#line 15007 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr757;
		case 10: goto tr758;
		case 13: goto tr759;
		case 59: goto tr781;
	}
	goto tr937;
tr741:
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st683;
st683:
	if ( ++p == pe )
		goto _test_eof683;
case 683:
#line 15025 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 58 )
		goto tr735;
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr735;
		} else if ( (*p) > 57 ) {
			if ( 60 <= (*p) && (*p) <= 64 )
				goto tr735;
		} else
			goto tr737;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr735;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr735;
		} else
			goto tr737;
	} else
		goto tr737;
	goto tr734;
tr736:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st684;
st684:
	if ( ++p == pe )
		goto _test_eof684;
case 684:
#line 15063 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr740;
		case 58: goto st525;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto st525;
		} else if ( (*p) > 57 ) {
			if ( 60 <= (*p) && (*p) <= 64 )
				goto st525;
		} else
			goto tr739;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st525;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st525;
		} else
			goto tr739;
	} else
		goto tr739;
	goto tr734;
tr733:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st685;
st685:
	if ( ++p == pe )
		goto _test_eof685;
case 685:
#line 15099 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr939;
		case 45: goto tr939;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr940;
	goto tr722;
tr939:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st686;
st686:
	if ( ++p == pe )
		goto _test_eof686;
case 686:
#line 15117 "inc/vcf/validator_detail_v43.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr940;
	goto tr722;
tr940:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st687;
st687:
	if ( ++p == pe )
		goto _test_eof687;
case 687:
#line 15131 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 9 )
		goto tr732;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr940;
	goto tr722;
tr725:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st688;
tr729:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st688;
st688:
	if ( ++p == pe )
		goto _test_eof688;
case 688:
#line 15157 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr732;
		case 46: goto tr728;
		case 69: goto tr733;
		case 101: goto tr733;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr729;
	goto tr722;
tr726:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st689;
tr730:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st689;
st689:
	if ( ++p == pe )
		goto _test_eof689;
case 689:
#line 15187 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 110 )
		goto tr941;
	goto tr722;
tr941:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st690;
st690:
	if ( ++p == pe )
		goto _test_eof690;
case 690:
#line 15201 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 102 )
		goto tr942;
	goto tr722;
tr942:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st691;
st691:
	if ( ++p == pe )
		goto _test_eof691;
case 691:
#line 15215 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 9 )
		goto tr732;
	goto tr722;
tr724:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st692;
st692:
	if ( ++p == pe )
		goto _test_eof692;
case 692:
#line 15233 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 9 )
		goto tr732;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr731;
	goto tr722;
tr727:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st693;
st693:
	if ( ++p == pe )
		goto _test_eof693;
case 693:
#line 15253 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 97 )
		goto tr943;
	goto tr722;
tr943:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st694;
st694:
	if ( ++p == pe )
		goto _test_eof694;
case 694:
#line 15267 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 78 )
		goto tr942;
	goto tr722;
tr721:
#line 39 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st695;
st695:
	if ( ++p == pe )
		goto _test_eof695;
case 695:
#line 15281 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 42: goto tr714;
		case 46: goto tr944;
		case 60: goto tr716;
		case 65: goto tr717;
		case 67: goto tr717;
		case 71: goto tr717;
		case 78: goto tr717;
		case 84: goto tr717;
		case 91: goto tr718;
		case 93: goto tr719;
		case 97: goto tr717;
		case 99: goto tr717;
		case 103: goto tr717;
		case 110: goto tr717;
		case 116: goto tr717;
	}
	goto tr713;
tr944:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st696;
tr968:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st696;
st696:
	if ( ++p == pe )
		goto _test_eof696;
case 696:
#line 15320 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 65: goto tr945;
		case 67: goto tr945;
		case 71: goto tr945;
		case 78: goto tr945;
		case 84: goto tr945;
		case 97: goto tr945;
		case 99: goto tr945;
		case 103: goto tr945;
		case 110: goto tr945;
		case 116: goto tr945;
	}
	goto tr713;
tr945:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st697;
st697:
	if ( ++p == pe )
		goto _test_eof697;
case 697:
#line 15344 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr720;
		case 44: goto tr721;
		case 65: goto tr945;
		case 67: goto tr945;
		case 71: goto tr945;
		case 78: goto tr945;
		case 84: goto tr945;
		case 97: goto tr945;
		case 99: goto tr945;
		case 103: goto tr945;
		case 110: goto tr945;
		case 116: goto tr945;
	}
	goto tr713;
tr716:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st698;
tr946:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st698;
st698:
	if ( ++p == pe )
		goto _test_eof698;
case 698:
#line 15380 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 61 )
		goto tr946;
	if ( (*p) < 63 ) {
		if ( (*p) < 45 ) {
			if ( 33 <= (*p) && (*p) <= 43 )
				goto tr946;
		} else if ( (*p) > 47 ) {
			if ( (*p) > 57 ) {
				if ( 58 <= (*p) && (*p) <= 59 )
					goto tr946;
			} else if ( (*p) >= 48 )
				goto tr947;
		} else
			goto tr946;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr947;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr946;
			} else if ( (*p) >= 97 )
				goto tr947;
		} else
			goto tr946;
	} else
		goto tr946;
	goto tr713;
tr947:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st699;
st699:
	if ( ++p == pe )
		goto _test_eof699;
case 699:
#line 15420 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 62 )
		goto tr948;
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr947;
	} else if ( (*p) > 59 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr947;
	} else
		goto tr947;
	goto tr713;
tr717:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st700;
tr949:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st700;
st700:
	if ( ++p == pe )
		goto _test_eof700;
case 700:
#line 15452 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr720;
		case 44: goto tr721;
		case 46: goto tr948;
		case 65: goto tr949;
		case 67: goto tr949;
		case 71: goto tr949;
		case 78: goto tr949;
		case 84: goto tr949;
		case 91: goto tr950;
		case 93: goto tr951;
		case 97: goto tr949;
		case 99: goto tr949;
		case 103: goto tr949;
		case 110: goto tr949;
		case 116: goto tr949;
	}
	goto tr713;
tr950:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st701;
st701:
	if ( ++p == pe )
		goto _test_eof701;
case 701:
#line 15481 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr952;
		case 59: goto tr952;
		case 60: goto tr953;
		case 92: goto tr952;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr952;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr952;
		} else if ( (*p) >= 63 )
			goto tr952;
	} else
		goto tr952;
	goto tr713;
tr952:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st702;
st702:
	if ( ++p == pe )
		goto _test_eof702;
case 702:
#line 15510 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr952;
		case 58: goto tr954;
		case 92: goto tr952;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr952;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr952;
		} else if ( (*p) >= 63 )
			goto tr952;
	} else
		goto tr952;
	goto tr713;
tr954:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st703;
st703:
	if ( ++p == pe )
		goto _test_eof703;
case 703:
#line 15538 "inc/vcf/validator_detail_v43.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr955;
	goto tr713;
tr955:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st704;
st704:
	if ( ++p == pe )
		goto _test_eof704;
case 704:
#line 15552 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 91 )
		goto tr948;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr955;
	goto tr713;
tr953:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st705;
st705:
	if ( ++p == pe )
		goto _test_eof705;
case 705:
#line 15568 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr956;
		case 59: goto tr956;
		case 92: goto tr956;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr956;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr956;
		} else if ( (*p) >= 63 )
			goto tr956;
	} else
		goto tr956;
	goto tr713;
tr956:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st706;
st706:
	if ( ++p == pe )
		goto _test_eof706;
case 706:
#line 15596 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr956;
		case 59: goto tr956;
		case 62: goto tr957;
		case 92: goto tr956;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr956;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr956;
		} else if ( (*p) >= 63 )
			goto tr956;
	} else
		goto tr956;
	goto tr713;
tr957:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st707;
st707:
	if ( ++p == pe )
		goto _test_eof707;
case 707:
#line 15625 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 58 )
		goto tr954;
	goto tr713;
tr951:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st708;
st708:
	if ( ++p == pe )
		goto _test_eof708;
case 708:
#line 15639 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr958;
		case 59: goto tr958;
		case 60: goto tr959;
		case 92: goto tr958;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr958;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr958;
		} else if ( (*p) >= 63 )
			goto tr958;
	} else
		goto tr958;
	goto tr713;
tr958:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st709;
st709:
	if ( ++p == pe )
		goto _test_eof709;
case 709:
#line 15668 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr958;
		case 58: goto tr960;
		case 92: goto tr958;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr958;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr958;
		} else if ( (*p) >= 63 )
			goto tr958;
	} else
		goto tr958;
	goto tr713;
tr960:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st710;
st710:
	if ( ++p == pe )
		goto _test_eof710;
case 710:
#line 15696 "inc/vcf/validator_detail_v43.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr961;
	goto tr713;
tr961:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st711;
st711:
	if ( ++p == pe )
		goto _test_eof711;
case 711:
#line 15710 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 93 )
		goto tr948;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr961;
	goto tr713;
tr959:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st712;
st712:
	if ( ++p == pe )
		goto _test_eof712;
case 712:
#line 15726 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr962;
		case 59: goto tr962;
		case 92: goto tr962;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr962;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr962;
		} else if ( (*p) >= 63 )
			goto tr962;
	} else
		goto tr962;
	goto tr713;
tr962:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st713;
st713:
	if ( ++p == pe )
		goto _test_eof713;
case 713:
#line 15754 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr962;
		case 59: goto tr962;
		case 62: goto tr963;
		case 92: goto tr962;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr962;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr962;
		} else if ( (*p) >= 63 )
			goto tr962;
	} else
		goto tr962;
	goto tr713;
tr963:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st714;
st714:
	if ( ++p == pe )
		goto _test_eof714;
case 714:
#line 15783 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 58 )
		goto tr960;
	goto tr713;
tr718:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st715;
st715:
	if ( ++p == pe )
		goto _test_eof715;
case 715:
#line 15801 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr964;
		case 59: goto tr964;
		case 60: goto tr965;
		case 92: goto tr964;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr964;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr964;
		} else if ( (*p) >= 63 )
			goto tr964;
	} else
		goto tr964;
	goto tr713;
tr964:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st716;
st716:
	if ( ++p == pe )
		goto _test_eof716;
case 716:
#line 15830 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr964;
		case 58: goto tr966;
		case 92: goto tr964;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr964;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr964;
		} else if ( (*p) >= 63 )
			goto tr964;
	} else
		goto tr964;
	goto tr713;
tr966:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st717;
st717:
	if ( ++p == pe )
		goto _test_eof717;
case 717:
#line 15858 "inc/vcf/validator_detail_v43.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr967;
	goto tr713;
tr967:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st718;
st718:
	if ( ++p == pe )
		goto _test_eof718;
case 718:
#line 15872 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 91 )
		goto tr968;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr967;
	goto tr713;
tr965:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st719;
st719:
	if ( ++p == pe )
		goto _test_eof719;
case 719:
#line 15888 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr969;
		case 59: goto tr969;
		case 92: goto tr969;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr969;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr969;
		} else if ( (*p) >= 63 )
			goto tr969;
	} else
		goto tr969;
	goto tr713;
tr969:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st720;
st720:
	if ( ++p == pe )
		goto _test_eof720;
case 720:
#line 15916 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr969;
		case 59: goto tr969;
		case 62: goto tr970;
		case 92: goto tr969;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr969;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr969;
		} else if ( (*p) >= 63 )
			goto tr969;
	} else
		goto tr969;
	goto tr713;
tr970:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st721;
st721:
	if ( ++p == pe )
		goto _test_eof721;
case 721:
#line 15945 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 58 )
		goto tr966;
	goto tr713;
tr719:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st722;
st722:
	if ( ++p == pe )
		goto _test_eof722;
case 722:
#line 15963 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr971;
		case 59: goto tr971;
		case 60: goto tr972;
		case 92: goto tr971;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr971;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr971;
		} else if ( (*p) >= 63 )
			goto tr971;
	} else
		goto tr971;
	goto tr713;
tr971:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st723;
st723:
	if ( ++p == pe )
		goto _test_eof723;
case 723:
#line 15992 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr971;
		case 58: goto tr973;
		case 92: goto tr971;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr971;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr971;
		} else if ( (*p) >= 63 )
			goto tr971;
	} else
		goto tr971;
	goto tr713;
tr973:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st724;
st724:
	if ( ++p == pe )
		goto _test_eof724;
case 724:
#line 16020 "inc/vcf/validator_detail_v43.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr974;
	goto tr713;
tr974:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st725;
st725:
	if ( ++p == pe )
		goto _test_eof725;
case 725:
#line 16034 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 93 )
		goto tr968;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr974;
	goto tr713;
tr972:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st726;
st726:
	if ( ++p == pe )
		goto _test_eof726;
case 726:
#line 16050 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr975;
		case 59: goto tr975;
		case 92: goto tr975;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr975;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr975;
		} else if ( (*p) >= 63 )
			goto tr975;
	} else
		goto tr975;
	goto tr713;
tr975:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st727;
st727:
	if ( ++p == pe )
		goto _test_eof727;
case 727:
#line 16078 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr975;
		case 59: goto tr975;
		case 62: goto tr976;
		case 92: goto tr975;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr975;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr975;
		} else if ( (*p) >= 63 )
			goto tr975;
	} else
		goto tr975;
	goto tr713;
tr976:
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st728;
st728:
	if ( ++p == pe )
		goto _test_eof728;
case 728:
#line 16107 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 58 )
		goto tr973;
	goto tr713;
tr715:
#line 31 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st729;
st729:
	if ( ++p == pe )
		goto _test_eof729;
case 729:
#line 16125 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr720;
		case 65: goto tr945;
		case 67: goto tr945;
		case 71: goto tr945;
		case 78: goto tr945;
		case 84: goto tr945;
		case 97: goto tr945;
		case 99: goto tr945;
		case 103: goto tr945;
		case 110: goto tr945;
		case 116: goto tr945;
	}
	goto tr713;
tr683:
#line 183 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_header_line(*this);
    }
#line 43 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st730;
tr695:
#line 179 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_sample_name(*this);
    }
#line 183 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_header_line(*this);
    }
#line 43 "src/vcf/vcf_v43.ragel"
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
#line 16180 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 10 )
		goto st734;
	goto tr684;
tr23:
#line 99 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_fileformat(*this);
    }
#line 43 "src/vcf/vcf_v43.ragel"
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
#line 16204 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 10 )
		goto st22;
	goto tr0;
tr981:
#line 43 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st732;
st732:
	if ( ++p == pe )
		goto _test_eof732;
case 732:
#line 16224 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 10: goto tr980;
		case 13: goto tr981;
	}
	goto st732;
tr980:
#line 43 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
#line 768 "src/vcf/vcf_v43.ragel"
	{ {goto st28;} }
	goto st736;
st736:
	if ( ++p == pe )
		goto _test_eof736;
case 736:
#line 16248 "inc/vcf/validator_detail_v43.hpp"
	goto st0;
tr984:
#line 43 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st733;
st733:
	if ( ++p == pe )
		goto _test_eof733;
case 733:
#line 16266 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 10: goto tr983;
		case 13: goto tr984;
	}
	goto st733;
tr983:
#line 43 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
#line 769 "src/vcf/vcf_v43.ragel"
	{ {goto st735;} }
	goto st737;
st737:
	if ( ++p == pe )
		goto _test_eof737;
case 737:
#line 16290 "inc/vcf/validator_detail_v43.hpp"
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
	_test_eof734: cs = 734; goto _test_eof; 
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
	_test_eof735: cs = 735; goto _test_eof; 
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
	_test_eof729: cs = 729; goto _test_eof; 
	_test_eof730: cs = 730; goto _test_eof; 
	_test_eof731: cs = 731; goto _test_eof; 
	_test_eof732: cs = 732; goto _test_eof; 
	_test_eof736: cs = 736; goto _test_eof; 
	_test_eof733: cs = 733; goto _test_eof; 
	_test_eof737: cs = 737; goto _test_eof; 

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
	case 731: 
#line 60 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this);
        p--; {goto st732;}
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
	case 73: 
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	break;
	case 734: 
#line 70 "src/vcf/vcf_v43.ragel"
	{
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (ParsingWarning warn) {
          ErrorPolicy::handle_meta_section_warning(*this, warn.what());
        }
    }
	break;
	case 502: 
	case 503: 
	case 504: 
	case 505: 
	case 506: 
	case 507: 
	case 508: 
	case 509: 
	case 510: 
	case 730: 
#line 78 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (ParsingWarning warn) {
          ErrorPolicy::handle_meta_section_warning(*this, warn.what());
        }
        
        p--; {goto st733;}
    }
	break;
	case 536: 
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
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
#line 210 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this,
            "The fileformat declaration is not 'fileformat=VCFv4.3'");
        p--; {goto st732;}
    }
#line 60 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this);
        p--; {goto st732;}
    }
	break;
	case 74: 
	case 75: 
	case 76: 
	case 77: 
	case 78: 
	case 79: 
	case 80: 
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
	case 95: 
	case 96: 
	case 103: 
	case 114: 
#line 217 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	break;
	case 375: 
	case 376: 
	case 377: 
	case 378: 
	case 379: 
	case 380: 
	case 381: 
	case 382: 
#line 228 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in assembly metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	break;
	case 402: 
	case 403: 
	case 404: 
	case 405: 
	case 406: 
	case 407: 
	case 408: 
	case 409: 
	case 410: 
	case 411: 
	case 414: 
	case 415: 
	case 416: 
	case 417: 
	case 418: 
	case 419: 
	case 420: 
	case 421: 
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
#line 234 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in contig metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	break;
	case 123: 
	case 124: 
	case 125: 
	case 126: 
	case 127: 
	case 128: 
	case 129: 
	case 130: 
	case 131: 
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
	case 147: 
	case 154: 
	case 165: 
#line 240 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	break;
	case 173: 
	case 174: 
	case 175: 
	case 176: 
	case 177: 
	case 178: 
	case 179: 
	case 180: 
	case 181: 
	case 185: 
	case 186: 
	case 187: 
	case 188: 
	case 189: 
	case 190: 
	case 191: 
	case 194: 
	case 195: 
	case 196: 
	case 197: 
	case 198: 
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
	case 213: 
	case 220: 
	case 231: 
#line 246 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	break;
	case 240: 
	case 241: 
	case 242: 
	case 243: 
	case 244: 
	case 245: 
	case 246: 
	case 247: 
	case 251: 
	case 252: 
	case 253: 
	case 254: 
	case 255: 
	case 256: 
	case 257: 
	case 260: 
	case 261: 
	case 262: 
	case 263: 
	case 264: 
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
	case 279: 
	case 286: 
	case 297: 
#line 262 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	break;
	case 306: 
	case 307: 
	case 308: 
	case 309: 
	case 310: 
	case 311: 
	case 312: 
	case 313: 
	case 314: 
	case 321: 
#line 278 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in PEDIGREE metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
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
	case 441: 
	case 442: 
	case 443: 
#line 284 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in pedigreeDB metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	break;
	case 322: 
	case 323: 
	case 324: 
	case 325: 
	case 326: 
	case 327: 
	case 328: 
	case 329: 
	case 330: 
	case 331: 
	case 371: 
#line 290 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	break;
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
	case 478: 
	case 479: 
	case 480: 
	case 481: 
	case 482: 
	case 483: 
	case 484: 
	case 485: 
	case 486: 
	case 487: 
	case 488: 
	case 489: 
	case 490: 
	case 491: 
	case 492: 
	case 493: 
	case 494: 
	case 495: 
	case 496: 
	case 497: 
	case 498: 
	case 499: 
	case 500: 
	case 501: 
#line 322 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this, "The header line does not start with the mandatory columns: CHROM, POS, ID, REF, ALT, QUAL, FILTER and INFO");
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (ParsingWarning warn) {
          ErrorPolicy::handle_meta_section_warning(*this, warn.what());
        }
        
        p--; {goto st733;}
    }
#line 78 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (ParsingWarning warn) {
          ErrorPolicy::handle_meta_section_warning(*this, warn.what());
        }
        
        p--; {goto st733;}
    }
	break;
	case 511: 
	case 533: 
	case 534: 
	case 535: 
#line 338 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Chromosome is not a string without colons or whitespaces, optionally wrapped with angle brackets (<>)");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	break;
	case 512: 
	case 513: 
#line 344 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Position is not a positive number");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	break;
	case 514: 
	case 515: 
#line 350 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "ID is not a single dot or a list of strings without semicolons or whitespaces");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	break;
	case 516: 
	case 517: 
#line 356 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Reference is not a string of bases");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	break;
	case 518: 
	case 519: 
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
	case 726: 
	case 727: 
	case 728: 
	case 729: 
#line 362 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Alternate is not a single dot or a comma-separated list of bases");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	break;
	case 520: 
	case 521: 
	case 522: 
	case 523: 
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
#line 368 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Quality is not a single dot or a positive number");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	break;
	case 524: 
	case 525: 
	case 526: 
	case 683: 
	case 684: 
#line 374 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Filter is not a single dot or a semicolon-separated list of strings");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	break;
	case 528: 
#line 380 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	break;
	case 529: 
	case 530: 
#line 501 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Format is not a colon-separated list of alphanumeric strings");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	break;
	case 539: 
	case 540: 
#line 507 "src/vcf/vcf_v43.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " is not a valid string";
        ErrorPolicy::handle_body_section_error(*this, message_stream.str());
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	break;
	case 23: 
	case 28: 
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
#line 322 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this, "The header line does not start with the mandatory columns: CHROM, POS, ID, REF, ALT, QUAL, FILTER and INFO");
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (ParsingWarning warn) {
          ErrorPolicy::handle_meta_section_warning(*this, warn.what());
        }
        
        p--; {goto st733;}
    }
#line 78 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (ParsingWarning warn) {
          ErrorPolicy::handle_meta_section_warning(*this, warn.what());
        }
        
        p--; {goto st733;}
    }
	break;
	case 81: 
	case 82: 
	case 83: 
#line 222 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "ALT metadata ID is not prefixed by DEL/INS/DUP/INV/CNV and suffixed by ':' and a text sequence");
        p--; {goto st732;}
    }
#line 217 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	break;
	case 122: 
#line 240 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st732;}
    }
#line 246 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	break;
	case 192: 
	case 193: 
	case 239: 
#line 251 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "FORMAT metadata Number is not a number, A, R, G or dot");
        p--; {goto st732;}
    }
#line 246 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	break;
	case 258: 
	case 259: 
	case 305: 
#line 267 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "INFO metadata Number is not a number, A, R, G or dot");
        p--; {goto st732;}
    }
#line 262 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	break;
	case 199: 
	case 200: 
#line 272 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "INFO metadata Type is not a Integer, Float, Flag, Character or String");
        p--; {goto st732;}
    }
#line 246 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	break;
	case 265: 
	case 266: 
#line 272 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "INFO metadata Type is not a Integer, Float, Flag, Character or String");
        p--; {goto st732;}
    }
#line 262 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	break;
	case 335: 
	case 336: 
	case 337: 
	case 338: 
	case 339: 
	case 340: 
	case 341: 
	case 342: 
	case 343: 
#line 295 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Genomes is not a valid string (maybe it contains quotes?)");
        p--; {goto st732;}
    }
#line 290 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	break;
	case 345: 
	case 346: 
	case 347: 
	case 348: 
	case 349: 
	case 350: 
	case 351: 
	case 352: 
	case 353: 
#line 300 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Mixture is not a valid string (maybe it contains quotes?)");
        p--; {goto st732;}
    }
#line 290 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	break;
	case 100: 
	case 101: 
	case 102: 
#line 306 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st732;}
    }
#line 217 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	break;
	case 412: 
	case 413: 
#line 306 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st732;}
    }
#line 234 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in contig metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	break;
	case 132: 
	case 133: 
	case 134: 
	case 151: 
	case 152: 
	case 153: 
#line 306 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st732;}
    }
#line 240 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	break;
	case 182: 
	case 183: 
	case 184: 
	case 217: 
	case 218: 
	case 219: 
#line 306 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st732;}
    }
#line 246 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	break;
	case 248: 
	case 249: 
	case 250: 
	case 283: 
	case 284: 
	case 285: 
#line 306 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st732;}
    }
#line 262 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	break;
	case 315: 
	case 316: 
	case 317: 
	case 318: 
	case 319: 
	case 320: 
#line 306 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st732;}
    }
#line 278 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in PEDIGREE metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	break;
	case 332: 
	case 333: 
#line 306 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st732;}
    }
#line 290 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	break;
	case 97: 
	case 98: 
	case 99: 
	case 104: 
	case 105: 
	case 106: 
	case 107: 
	case 111: 
	case 112: 
	case 113: 
	case 115: 
	case 116: 
	case 120: 
	case 121: 
#line 311 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st732;}
    }
#line 217 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	break;
	case 148: 
	case 149: 
	case 150: 
	case 155: 
	case 156: 
	case 157: 
	case 158: 
	case 162: 
	case 163: 
	case 164: 
	case 166: 
	case 167: 
	case 171: 
	case 172: 
#line 311 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st732;}
    }
#line 240 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	break;
	case 214: 
	case 215: 
	case 216: 
	case 221: 
	case 222: 
	case 223: 
	case 224: 
	case 228: 
	case 229: 
	case 230: 
	case 232: 
	case 233: 
	case 237: 
	case 238: 
#line 311 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st732;}
    }
#line 246 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	break;
	case 280: 
	case 281: 
	case 282: 
	case 287: 
	case 288: 
	case 289: 
	case 290: 
	case 294: 
	case 295: 
	case 296: 
	case 298: 
	case 299: 
	case 303: 
	case 304: 
#line 311 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st732;}
    }
#line 262 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	break;
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
	case 370: 
	case 372: 
	case 373: 
	case 374: 
#line 311 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st732;}
    }
#line 290 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	break;
	case 383: 
	case 384: 
	case 385: 
	case 386: 
	case 387: 
	case 388: 
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
	case 399: 
	case 400: 
	case 401: 
#line 316 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata URL is not valid");
        p--; {goto st732;}
    }
#line 228 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in assembly metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	break;
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
#line 316 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata URL is not valid");
        p--; {goto st732;}
    }
#line 284 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in pedigreeDB metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	break;
	case 527: 
	case 541: 
	case 542: 
	case 543: 
	case 544: 
	case 545: 
	case 546: 
	case 552: 
	case 553: 
	case 557: 
	case 560: 
	case 563: 
	case 566: 
	case 569: 
	case 583: 
	case 586: 
	case 587: 
	case 601: 
	case 602: 
	case 603: 
	case 604: 
	case 605: 
	case 608: 
	case 612: 
	case 615: 
	case 616: 
	case 617: 
	case 620: 
	case 627: 
	case 628: 
	case 629: 
	case 645: 
	case 646: 
	case 649: 
	case 650: 
	case 664: 
	case 665: 
	case 666: 
	case 667: 
	case 668: 
	case 672: 
	case 673: 
	case 674: 
	case 675: 
	case 676: 
	case 677: 
	case 678: 
	case 679: 
#line 385 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st733;}
    }
#line 380 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	break;
	case 547: 
	case 548: 
#line 390 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info field value is not a comma-separated list of valid strings (maybe it contains whitespaces?)");
        p--; {goto st733;}
    }
#line 380 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	break;
	case 554: 
	case 555: 
	case 556: 
#line 395 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info AA value is not a single dot or a string of bases");
        p--; {goto st733;}
    }
#line 380 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	break;
	case 558: 
	case 559: 
#line 400 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info AC value is not a comma-separated list of numbers");
        p--; {goto st733;}
    }
#line 380 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	break;
	case 561: 
	case 562: 
#line 405 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info AD value is not a comma-separated list of numbers");
        p--; {goto st733;}
    }
#line 380 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	break;
	case 564: 
	case 565: 
#line 410 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info ADF value is not a comma-separated list of numbers");
        p--; {goto st733;}
    }
#line 380 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	break;
	case 567: 
	case 568: 
#line 415 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info ADR value is not a comma-separated list of numbers");
        p--; {goto st733;}
    }
#line 380 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	break;
	case 570: 
	case 571: 
	case 572: 
	case 573: 
	case 574: 
	case 575: 
	case 576: 
	case 577: 
	case 578: 
	case 579: 
	case 580: 
	case 581: 
	case 582: 
#line 420 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info AF value is not a comma-separated list of numbers");
        p--; {goto st733;}
    }
#line 380 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	break;
	case 584: 
	case 585: 
#line 425 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info AN value is not an integer number");
        p--; {goto st733;}
    }
#line 380 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	break;
	case 588: 
	case 589: 
	case 590: 
	case 591: 
	case 592: 
	case 593: 
	case 594: 
	case 595: 
	case 596: 
	case 597: 
	case 598: 
	case 599: 
	case 600: 
#line 430 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info BQ value is not a number");
        p--; {goto st733;}
    }
#line 380 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	break;
	case 606: 
	case 607: 
#line 435 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info CIGAR value is not an alphanumeric string");
        p--; {goto st733;}
    }
#line 380 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	break;
	case 610: 
	case 611: 
#line 440 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info DB is not a flag (with 1/0/no value)");
        p--; {goto st733;}
    }
#line 380 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	break;
	case 613: 
	case 614: 
#line 445 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info DP value is not an integer number");
        p--; {goto st733;}
    }
#line 380 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	break;
	case 618: 
	case 619: 
#line 450 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info END value is not an integer number");
        p--; {goto st733;}
    }
#line 380 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	break;
	case 622: 
	case 623: 
#line 455 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info H2 is not a flag (with 1/0/no value)");
        p--; {goto st733;}
    }
#line 380 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	break;
	case 625: 
	case 626: 
#line 460 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info H3 is not a flag (with 1/0/no value)");
        p--; {goto st733;}
    }
#line 380 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	break;
	case 632: 
	case 633: 
	case 634: 
	case 635: 
	case 636: 
	case 637: 
	case 638: 
	case 639: 
	case 640: 
	case 641: 
	case 642: 
	case 643: 
	case 644: 
#line 465 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info MQ value is not a number");
        p--; {goto st733;}
    }
#line 380 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	break;
	case 630: 
	case 631: 
#line 470 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info MQ0 value is not an integer number");
        p--; {goto st733;}
    }
#line 380 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	break;
	case 647: 
	case 648: 
#line 475 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info NS value is not an integer number");
        p--; {goto st733;}
    }
#line 380 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	break;
	case 651: 
	case 652: 
	case 653: 
	case 654: 
	case 655: 
	case 656: 
	case 657: 
	case 658: 
	case 659: 
	case 660: 
	case 661: 
	case 662: 
	case 663: 
#line 480 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info SB value is not a number");
        p--; {goto st733;}
    }
#line 380 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	break;
	case 670: 
	case 671: 
#line 485 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info SOMATIC is not a flag (with 1/0/no value)");
        p--; {goto st733;}
    }
#line 380 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	break;
	case 681: 
	case 682: 
#line 490 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info VALIDATED is not a flag (with 1/0/no value)");
        p--; {goto st733;}
    }
#line 380 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	break;
	case 550: 
	case 551: 
#line 495 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info 1000G is not a flag (with 1/0/no value)");
        p--; {goto st733;}
    }
#line 380 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	break;
	case 531: 
	case 532: 
	case 537: 
	case 538: 
#line 514 "src/vcf/vcf_v43.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " does not start with a valid genotype";
        ErrorPolicy::handle_body_section_error(*this, message_stream.str());
        p--; {goto st733;}
    }
#line 507 "src/vcf/vcf_v43.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " is not a valid string";
        ErrorPolicy::handle_body_section_error(*this, message_stream.str());
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	break;
	case 22: 
#line 60 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this);
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
#line 322 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this, "The header line does not start with the mandatory columns: CHROM, POS, ID, REF, ALT, QUAL, FILTER and INFO");
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (ParsingWarning warn) {
          ErrorPolicy::handle_meta_section_warning(*this, warn.what());
        }
        
        p--; {goto st733;}
    }
#line 78 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (ParsingWarning warn) {
          ErrorPolicy::handle_meta_section_warning(*this, warn.what());
        }
        
        p--; {goto st733;}
    }
	break;
	case 344: 
#line 295 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Genomes is not a valid string (maybe it contains quotes?)");
        p--; {goto st732;}
    }
#line 300 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Mixture is not a valid string (maybe it contains quotes?)");
        p--; {goto st732;}
    }
#line 290 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	break;
	case 354: 
#line 300 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Mixture is not a valid string (maybe it contains quotes?)");
        p--; {goto st732;}
    }
#line 311 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st732;}
    }
#line 290 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	break;
	case 334: 
#line 306 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st732;}
    }
#line 295 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Genomes is not a valid string (maybe it contains quotes?)");
        p--; {goto st732;}
    }
#line 290 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	break;
	case 108: 
	case 109: 
	case 110: 
#line 306 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st732;}
    }
#line 311 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st732;}
    }
#line 217 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	break;
	case 159: 
	case 160: 
	case 161: 
#line 306 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st732;}
    }
#line 311 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st732;}
    }
#line 240 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	break;
	case 225: 
	case 226: 
	case 227: 
#line 306 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st732;}
    }
#line 311 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st732;}
    }
#line 246 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	break;
	case 291: 
	case 292: 
	case 293: 
#line 306 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st732;}
    }
#line 311 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st732;}
    }
#line 262 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	break;
	case 117: 
	case 118: 
	case 119: 
#line 311 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st732;}
    }
#line 306 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st732;}
    }
#line 217 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	break;
	case 168: 
	case 169: 
	case 170: 
#line 311 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st732;}
    }
#line 306 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st732;}
    }
#line 240 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	break;
	case 234: 
	case 235: 
	case 236: 
#line 311 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st732;}
    }
#line 306 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st732;}
    }
#line 246 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	break;
	case 300: 
	case 301: 
	case 302: 
#line 311 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st732;}
    }
#line 306 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st732;}
    }
#line 262 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	break;
	case 609: 
#line 440 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info DB is not a flag (with 1/0/no value)");
        p--; {goto st733;}
    }
#line 385 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st733;}
    }
#line 380 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	break;
	case 621: 
#line 455 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info H2 is not a flag (with 1/0/no value)");
        p--; {goto st733;}
    }
#line 385 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st733;}
    }
#line 380 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	break;
	case 624: 
#line 460 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info H3 is not a flag (with 1/0/no value)");
        p--; {goto st733;}
    }
#line 385 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st733;}
    }
#line 380 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	break;
	case 669: 
#line 485 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info SOMATIC is not a flag (with 1/0/no value)");
        p--; {goto st733;}
    }
#line 385 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st733;}
    }
#line 380 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	break;
	case 680: 
#line 490 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info VALIDATED is not a flag (with 1/0/no value)");
        p--; {goto st733;}
    }
#line 385 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st733;}
    }
#line 380 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	break;
	case 549: 
#line 495 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info 1000G is not a flag (with 1/0/no value)");
        p--; {goto st733;}
    }
#line 385 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st733;}
    }
#line 380 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st733;}
    }
#line 91 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st733;}
    }
	break;
	case 24: 
#line 217 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st732;}
    }
#line 240 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st732;}
    }
#line 246 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st732;}
    }
#line 262 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st732;}
    }
#line 228 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in assembly metadata");
        p--; {goto st732;}
    }
#line 234 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in contig metadata");
        p--; {goto st732;}
    }
#line 290 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st732;}
    }
#line 278 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in PEDIGREE metadata");
        p--; {goto st732;}
    }
#line 284 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in pedigreeDB metadata");
        p--; {goto st732;}
    }
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st732;}
    }
	break;
#line 19274 "inc/vcf/validator_detail_v43.hpp"
	}
	}

	_out: {}
	}

#line 800 "src/vcf/vcf_v43.ragel"

    }
    
  }
}
