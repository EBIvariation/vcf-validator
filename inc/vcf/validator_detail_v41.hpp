
#line 1 "src/vcf/vcf_v41.ragel"
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


#line 750 "src/vcf/vcf_v41.ragel"


namespace
{
  
#line 31 "inc/vcf/validator_detail_v41.hpp"
static const int vcf_v41_start = 1;
static const int vcf_v41_first_final = 658;
static const int vcf_v41_error = 0;

static const int vcf_v41_en_main = 1;
static const int vcf_v41_en_main_meta_section = 28;
static const int vcf_v41_en_main_body_section = 659;
static const int vcf_v41_en_meta_section_skip = 656;
static const int vcf_v41_en_body_section_skip = 657;


#line 756 "src/vcf/vcf_v41.ragel"

}

namespace ebi
{
  namespace vcf
  {
    
    template <typename Configuration>
    ParserImpl_v41<Configuration>::ParserImpl_v41(std::shared_ptr<Source> const & source,
                                                  std::shared_ptr<std::vector<Record>> const & records
    )
    : ParserImpl{source, records}
    {
      
#line 59 "inc/vcf/validator_detail_v41.hpp"
	{
	cs = vcf_v41_start;
	}

#line 772 "src/vcf/vcf_v41.ragel"

    }

    template <typename Configuration>
    void ParserImpl_v41<Configuration>::parse_buffer(char const * p, char const * pe, char const * eof)
    {
      
#line 72 "inc/vcf/validator_detail_v41.hpp"
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
#line 60 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this);
        p--; {goto st656;}
    }
	goto st0;
tr14:
#line 210 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this,
            "The fileformat declaration is not 'fileformat=VCFv4.1'");
        p--; {goto st656;}
    }
#line 60 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this);
        p--; {goto st656;}
    }
	goto st0;
tr23:
#line 60 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this);
        p--; {goto st656;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
#line 322 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this, "The header line does not start with the mandatory columns: CHROM, POS, ID, REF, ALT, QUAL, FILTER and INFO");
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (ParsingWarning warn) {
          ErrorPolicy::handle_meta_section_warning(*this, warn.what());
        }
        
        p--; {goto st657;}
    }
#line 78 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (ParsingWarning warn) {
          ErrorPolicy::handle_meta_section_warning(*this, warn.what());
        }
        
        p--; {goto st657;}
    }
	goto st0;
tr25:
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
#line 322 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this, "The header line does not start with the mandatory columns: CHROM, POS, ID, REF, ALT, QUAL, FILTER and INFO");
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (ParsingWarning warn) {
          ErrorPolicy::handle_meta_section_warning(*this, warn.what());
        }
        
        p--; {goto st657;}
    }
#line 78 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (ParsingWarning warn) {
          ErrorPolicy::handle_meta_section_warning(*this, warn.what());
        }
        
        p--; {goto st657;}
    }
	goto st0;
tr28:
#line 217 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st656;}
    }
#line 240 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st656;}
    }
#line 246 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st656;}
    }
#line 262 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st656;}
    }
#line 228 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in assembly metadata");
        p--; {goto st656;}
    }
#line 234 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in contig metadata");
        p--; {goto st656;}
    }
#line 290 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st656;}
    }
#line 278 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in PEDIGREE metadata");
        p--; {goto st656;}
    }
#line 284 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in pedigreeDB metadata");
        p--; {goto st656;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
	goto st0;
tr38:
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
	goto st0;
tr121:
#line 217 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st656;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
	goto st0;
tr129:
#line 222 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "ALT metadata ID is not prefixed by DEL/INS/DUP/INV/CNV and suffixed by ':' and a text sequence");
        p--; {goto st656;}
    }
#line 217 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st656;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
	goto st0;
tr147:
#line 311 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st656;}
    }
#line 217 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st656;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
	goto st0;
tr158:
#line 240 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st656;}
    }
#line 246 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st656;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
	goto st0;
tr161:
#line 240 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st656;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
	goto st0;
tr171:
#line 306 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st656;}
    }
#line 240 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st656;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
	goto st0;
tr190:
#line 311 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st656;}
    }
#line 240 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st656;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
	goto st0;
tr200:
#line 246 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st656;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
	goto st0;
tr210:
#line 306 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st656;}
    }
#line 246 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st656;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
	goto st0;
tr223:
#line 251 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "FORMAT metadata Number is not a number, A, R, G or dot");
        p--; {goto st656;}
    }
#line 246 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st656;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
	goto st0;
tr232:
#line 272 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "INFO metadata Type is not a Integer, Float, Flag, Character or String");
        p--; {goto st656;}
    }
#line 246 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st656;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
	goto st0;
tr249:
#line 311 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st656;}
    }
#line 246 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st656;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
	goto st0;
tr260:
#line 262 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st656;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
	goto st0;
tr269:
#line 306 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st656;}
    }
#line 262 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st656;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
	goto st0;
tr282:
#line 267 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "INFO metadata Number is not a number, A, R, G or dot");
        p--; {goto st656;}
    }
#line 262 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st656;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
	goto st0;
tr291:
#line 272 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "INFO metadata Type is not a Integer, Float, Flag, Character or String");
        p--; {goto st656;}
    }
#line 262 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st656;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
	goto st0;
tr308:
#line 311 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st656;}
    }
#line 262 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st656;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
	goto st0;
tr319:
#line 278 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in PEDIGREE metadata");
        p--; {goto st656;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
	goto st0;
tr329:
#line 306 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st656;}
    }
#line 278 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in PEDIGREE metadata");
        p--; {goto st656;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
	goto st0;
tr341:
#line 290 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st656;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
	goto st0;
tr352:
#line 306 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st656;}
    }
#line 290 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st656;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
	goto st0;
tr357:
#line 306 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st656;}
    }
#line 295 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Genomes is not a valid string (maybe it contains quotes?)");
        p--; {goto st656;}
    }
#line 290 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st656;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
	goto st0;
tr359:
#line 295 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Genomes is not a valid string (maybe it contains quotes?)");
        p--; {goto st656;}
    }
#line 290 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st656;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
	goto st0;
tr369:
#line 295 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Genomes is not a valid string (maybe it contains quotes?)");
        p--; {goto st656;}
    }
#line 300 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Mixture is not a valid string (maybe it contains quotes?)");
        p--; {goto st656;}
    }
#line 290 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st656;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
	goto st0;
tr372:
#line 300 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Mixture is not a valid string (maybe it contains quotes?)");
        p--; {goto st656;}
    }
#line 290 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st656;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
	goto st0;
tr382:
#line 300 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Mixture is not a valid string (maybe it contains quotes?)");
        p--; {goto st656;}
    }
#line 311 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st656;}
    }
#line 290 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st656;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
	goto st0;
tr385:
#line 311 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st656;}
    }
#line 290 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st656;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
	goto st0;
tr408:
#line 228 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in assembly metadata");
        p--; {goto st656;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
	goto st0;
tr417:
#line 316 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata URL is not valid");
        p--; {goto st656;}
    }
#line 228 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in assembly metadata");
        p--; {goto st656;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
	goto st0;
tr424:
#line 234 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in contig metadata");
        p--; {goto st656;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
	goto st0;
tr435:
#line 306 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st656;}
    }
#line 234 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in contig metadata");
        p--; {goto st656;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
	goto st0;
tr474:
#line 284 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in pedigreeDB metadata");
        p--; {goto st656;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
	goto st0;
tr486:
#line 316 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata URL is not valid");
        p--; {goto st656;}
    }
#line 284 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in pedigreeDB metadata");
        p--; {goto st656;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
	goto st0;
tr494:
#line 322 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this, "The header line does not start with the mandatory columns: CHROM, POS, ID, REF, ALT, QUAL, FILTER and INFO");
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (ParsingWarning warn) {
          ErrorPolicy::handle_meta_section_warning(*this, warn.what());
        }
        
        p--; {goto st657;}
    }
#line 78 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (ParsingWarning warn) {
          ErrorPolicy::handle_meta_section_warning(*this, warn.what());
        }
        
        p--; {goto st657;}
    }
	goto st0;
tr533:
#line 78 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (ParsingWarning warn) {
          ErrorPolicy::handle_meta_section_warning(*this, warn.what());
        }
        
        p--; {goto st657;}
    }
	goto st0;
tr545:
#line 338 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Chromosome is not a string without colons or whitespaces, optionally wrapped with angle brackets (<>)");
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	goto st0;
tr549:
#line 344 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Position is not a positive number");
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	goto st0;
tr554:
#line 350 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "ID is not a single dot or a list of strings without semicolons or whitespaces");
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	goto st0;
tr559:
#line 356 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Reference is not a string of bases");
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	goto st0;
tr563:
#line 362 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Alternate is not a single dot or a comma-separated list of bases");
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	goto st0;
tr572:
#line 368 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Quality is not a single dot or a positive number");
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	goto st0;
tr584:
#line 374 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Filter is not a single dot or a semicolon-separated list of strings");
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	goto st0;
tr592:
#line 385 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st657;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	goto st0;
tr613:
#line 486 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Format is not a colon-separated list of alphanumeric strings");
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	goto st0;
tr618:
#line 499 "src/vcf/vcf_v41.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " does not start with a valid genotype";
        ErrorPolicy::handle_body_section_error(*this, message_stream.str());
        p--; {goto st657;}
    }
#line 492 "src/vcf/vcf_v41.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " is not a valid string";
        ErrorPolicy::handle_body_section_error(*this, message_stream.str());
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	goto st0;
tr630:
#line 492 "src/vcf/vcf_v41.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " is not a valid string";
        ErrorPolicy::handle_body_section_error(*this, message_stream.str());
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	goto st0;
tr636:
#line 390 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info field value is not a comma-separated list of valid strings (maybe it contains whitespaces?)");
        p--; {goto st657;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	goto st0;
tr638:
#line 480 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info 1000G is not a flag (with 1/0/no value)");
        p--; {goto st657;}
    }
#line 385 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st657;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	goto st0;
tr640:
#line 480 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info 1000G is not a flag (with 1/0/no value)");
        p--; {goto st657;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	goto st0;
tr647:
#line 395 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info AA value is not a single dot or a string of bases");
        p--; {goto st657;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	goto st0;
tr651:
#line 400 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info AC value is not a comma-separated list of numbers");
        p--; {goto st657;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	goto st0;
tr655:
#line 405 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info AF value is not a comma-separated list of numbers");
        p--; {goto st657;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	goto st0;
tr669:
#line 410 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info AN value is not an integer number");
        p--; {goto st657;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	goto st0;
tr674:
#line 415 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info BQ value is not a number");
        p--; {goto st657;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	goto st0;
tr692:
#line 420 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info CIGAR value is not an alphanumeric string");
        p--; {goto st657;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	goto st0;
tr696:
#line 425 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info DB is not a flag (with 1/0/no value)");
        p--; {goto st657;}
    }
#line 385 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st657;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	goto st0;
tr698:
#line 425 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info DB is not a flag (with 1/0/no value)");
        p--; {goto st657;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	goto st0;
tr701:
#line 430 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info DP value is not an integer number");
        p--; {goto st657;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	goto st0;
tr707:
#line 435 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info END value is not an integer number");
        p--; {goto st657;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	goto st0;
tr712:
#line 440 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info H2 is not a flag (with 1/0/no value)");
        p--; {goto st657;}
    }
#line 385 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st657;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	goto st0;
tr714:
#line 440 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info H2 is not a flag (with 1/0/no value)");
        p--; {goto st657;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	goto st0;
tr716:
#line 445 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info H3 is not a flag (with 1/0/no value)");
        p--; {goto st657;}
    }
#line 385 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st657;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	goto st0;
tr718:
#line 445 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info H3 is not a flag (with 1/0/no value)");
        p--; {goto st657;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	goto st0;
tr724:
#line 455 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info MQ0 value is not an integer number");
        p--; {goto st657;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	goto st0;
tr727:
#line 450 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info MQ value is not a number");
        p--; {goto st657;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	goto st0;
tr742:
#line 460 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info NS value is not an integer number");
        p--; {goto st657;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	goto st0;
tr748:
#line 465 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info SB value is not a number");
        p--; {goto st657;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	goto st0;
tr766:
#line 470 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info SOMATIC is not a flag (with 1/0/no value)");
        p--; {goto st657;}
    }
#line 385 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st657;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	goto st0;
tr768:
#line 470 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info SOMATIC is not a flag (with 1/0/no value)");
        p--; {goto st657;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	goto st0;
tr778:
#line 475 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info VALIDATED is not a flag (with 1/0/no value)");
        p--; {goto st657;}
    }
#line 385 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st657;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	goto st0;
tr780:
#line 475 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info VALIDATED is not a flag (with 1/0/no value)");
        p--; {goto st657;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	goto st0;
tr844:
#line 78 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (ParsingWarning warn) {
          ErrorPolicy::handle_meta_section_warning(*this, warn.what());
        }
        
        p--; {goto st657;}
    }
#line 338 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Chromosome is not a string without colons or whitespaces, optionally wrapped with angle brackets (<>)");
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	goto st0;
#line 1434 "inc/vcf/validator_detail_v41.hpp"
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
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st15;
st15:
	if ( ++p == pe )
		goto _test_eof15;
case 15:
#line 1539 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 67 )
		goto st16;
	goto tr14;
st16:
	if ( ++p == pe )
		goto _test_eof16;
case 16:
	if ( (*p) == 70 )
		goto st17;
	goto tr14;
st17:
	if ( ++p == pe )
		goto _test_eof17;
case 17:
	if ( (*p) == 118 )
		goto st18;
	goto tr14;
st18:
	if ( ++p == pe )
		goto _test_eof18;
case 18:
	if ( (*p) == 52 )
		goto st19;
	goto tr14;
st19:
	if ( ++p == pe )
		goto _test_eof19;
case 19:
	if ( (*p) == 46 )
		goto st20;
	goto tr14;
st20:
	if ( ++p == pe )
		goto _test_eof20;
case 20:
	if ( (*p) == 49 )
		goto tr21;
	goto tr14;
tr21:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st21;
st21:
	if ( ++p == pe )
		goto _test_eof21;
case 21:
#line 1588 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 10 )
		goto tr22;
	goto tr14;
tr22:
#line 99 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_fileformat(*this);
    }
#line 43 "src/vcf/vcf_v41.ragel"
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
#line 1612 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 35 )
		goto st23;
	goto tr23;
st23:
	if ( ++p == pe )
		goto _test_eof23;
case 23:
	switch( (*p) ) {
		case 35: goto st24;
		case 67: goto st369;
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
tr39:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st25;
tr29:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st25;
st25:
	if ( ++p == pe )
		goto _test_eof25;
case 25:
#line 1665 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 61 )
		goto tr40;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr38;
tr40:
#line 163 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this);
    }
	goto st26;
st26:
	if ( ++p == pe )
		goto _test_eof26;
case 26:
#line 1681 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto st29;
		case 60: goto st34;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr38;
tr45:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st27;
tr41:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st27;
st27:
	if ( ++p == pe )
		goto _test_eof27;
case 27:
#line 1709 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 10 )
		goto tr44;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr45;
	goto tr38;
tr44:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 171 "src/vcf/vcf_v41.ragel"
	{
        try {
          ParsePolicy::handle_meta_line(*this);
        } catch (ParsingError ex) {
          ErrorPolicy::handle_meta_section_error(*this, ex.what());
        }
    }
#line 43 "src/vcf/vcf_v41.ragel"
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
#line 171 "src/vcf/vcf_v41.ragel"
	{
        try {
          ParsePolicy::handle_meta_line(*this);
        } catch (ParsingError ex) {
          ErrorPolicy::handle_meta_section_error(*this, ex.what());
        }
    }
#line 43 "src/vcf/vcf_v41.ragel"
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
#line 1763 "inc/vcf/validator_detail_v41.hpp"
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
tr49:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st30;
tr46:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st30;
st30:
	if ( ++p == pe )
		goto _test_eof30;
case 30:
#line 1798 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr50;
		case 92: goto tr51;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr49;
	goto tr38;
tr47:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st31;
tr50:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st31;
st31:
	if ( ++p == pe )
		goto _test_eof31;
case 31:
#line 1826 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 10 )
		goto tr52;
	goto tr38;
tr51:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st32;
tr48:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st32;
st32:
	if ( ++p == pe )
		goto _test_eof32;
case 32:
#line 1850 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr53;
		case 92: goto tr51;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr49;
	goto tr38;
tr53:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st33;
st33:
	if ( ++p == pe )
		goto _test_eof33;
case 33:
#line 1872 "inc/vcf/validator_detail_v41.hpp"
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
tr60:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st36;
tr57:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st36;
st36:
	if ( ++p == pe )
		goto _test_eof36;
case 36:
#line 1932 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr61;
		case 92: goto tr62;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr60;
	goto tr38;
tr58:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st37;
tr61:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st37;
st37:
	if ( ++p == pe )
		goto _test_eof37;
case 37:
#line 1960 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 62 )
		goto st31;
	goto tr38;
tr62:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st38;
tr59:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st38;
st38:
	if ( ++p == pe )
		goto _test_eof38;
case 38:
#line 1984 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr64;
		case 92: goto tr62;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr60;
	goto tr38;
tr64:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st39;
st39:
	if ( ++p == pe )
		goto _test_eof39;
case 39:
#line 2006 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr61;
		case 62: goto tr65;
		case 92: goto tr62;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr60;
	goto tr38;
tr65:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st40;
st40:
	if ( ++p == pe )
		goto _test_eof40;
case 40:
#line 2025 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 10: goto tr52;
		case 34: goto tr61;
		case 92: goto tr62;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr60;
	goto tr38;
tr55:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st41;
st41:
	if ( ++p == pe )
		goto _test_eof41;
case 41:
#line 2044 "inc/vcf/validator_detail_v41.hpp"
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
tr67:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st42;
tr56:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st42;
st42:
	if ( ++p == pe )
		goto _test_eof42;
case 42:
#line 2079 "inc/vcf/validator_detail_v41.hpp"
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
#line 167 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st43;
st43:
	if ( ++p == pe )
		goto _test_eof43;
case 43:
#line 2106 "inc/vcf/validator_detail_v41.hpp"
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
tr71:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st44;
tr69:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st44;
st44:
	if ( ++p == pe )
		goto _test_eof44;
case 44:
#line 2138 "inc/vcf/validator_detail_v41.hpp"
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
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st45;
st45:
	if ( ++p == pe )
		goto _test_eof45;
case 45:
#line 2159 "inc/vcf/validator_detail_v41.hpp"
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
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st46;
st46:
	if ( ++p == pe )
		goto _test_eof46;
case 46:
#line 2184 "inc/vcf/validator_detail_v41.hpp"
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
tr76:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st47;
tr74:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st47;
st47:
	if ( ++p == pe )
		goto _test_eof47;
case 47:
#line 2219 "inc/vcf/validator_detail_v41.hpp"
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
#line 167 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st48;
st48:
	if ( ++p == pe )
		goto _test_eof48;
case 48:
#line 2246 "inc/vcf/validator_detail_v41.hpp"
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
tr82:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st50;
tr79:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st50;
st50:
	if ( ++p == pe )
		goto _test_eof50;
case 50:
#line 2289 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr83;
		case 92: goto tr84;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr82;
	goto tr38;
tr80:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st51;
tr83:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st51;
st51:
	if ( ++p == pe )
		goto _test_eof51;
case 51:
#line 2317 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 44: goto st45;
		case 62: goto st31;
	}
	goto tr38;
tr84:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st52;
tr81:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st52;
st52:
	if ( ++p == pe )
		goto _test_eof52;
case 52:
#line 2343 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr86;
		case 92: goto tr84;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr82;
	goto tr38;
tr86:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st53;
st53:
	if ( ++p == pe )
		goto _test_eof53;
case 53:
#line 2365 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr83;
		case 44: goto tr87;
		case 62: goto tr88;
		case 92: goto tr84;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr82;
	goto tr38;
tr87:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st54;
tr101:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st54;
tr98:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st54;
st54:
	if ( ++p == pe )
		goto _test_eof54;
case 54:
#line 2405 "inc/vcf/validator_detail_v41.hpp"
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
tr91:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st55;
tr89:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st55;
st55:
	if ( ++p == pe )
		goto _test_eof55;
case 55:
#line 2456 "inc/vcf/validator_detail_v41.hpp"
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
tr92:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st56;
tr90:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st56;
st56:
	if ( ++p == pe )
		goto _test_eof56;
case 56:
#line 2507 "inc/vcf/validator_detail_v41.hpp"
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
#line 167 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st57;
st57:
	if ( ++p == pe )
		goto _test_eof57;
case 57:
#line 2550 "inc/vcf/validator_detail_v41.hpp"
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
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st58;
tr94:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st58;
st58:
	if ( ++p == pe )
		goto _test_eof58;
case 58:
#line 2580 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr83;
		case 44: goto tr98;
		case 62: goto tr99;
		case 92: goto tr100;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr97;
	goto tr38;
tr88:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st59;
tr102:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st59;
tr99:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st59;
st59:
	if ( ++p == pe )
		goto _test_eof59;
case 59:
#line 2620 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 10: goto tr52;
		case 34: goto tr83;
		case 92: goto tr84;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr82;
	goto tr38;
tr100:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st60;
tr96:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st60;
st60:
	if ( ++p == pe )
		goto _test_eof60;
case 60:
#line 2649 "inc/vcf/validator_detail_v41.hpp"
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
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st61;
st61:
	if ( ++p == pe )
		goto _test_eof61;
case 61:
#line 2669 "inc/vcf/validator_detail_v41.hpp"
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
tr105:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st63;
tr103:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st63;
st63:
	if ( ++p == pe )
		goto _test_eof63;
case 63:
#line 2710 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr83;
		case 92: goto tr106;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr105;
	goto tr38;
tr106:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st64;
tr104:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st64;
st64:
	if ( ++p == pe )
		goto _test_eof64;
case 64:
#line 2738 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr107;
		case 92: goto tr106;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr105;
	goto tr38;
tr107:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st65;
st65:
	if ( ++p == pe )
		goto _test_eof65;
case 65:
#line 2760 "inc/vcf/validator_detail_v41.hpp"
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
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st66;
tr118:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st66;
st66:
	if ( ++p == pe )
		goto _test_eof66;
case 66:
#line 2790 "inc/vcf/validator_detail_v41.hpp"
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
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st67;
tr110:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st67;
st67:
	if ( ++p == pe )
		goto _test_eof67;
case 67:
#line 2841 "inc/vcf/validator_detail_v41.hpp"
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
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st68;
tr111:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st68;
st68:
	if ( ++p == pe )
		goto _test_eof68;
case 68:
#line 2892 "inc/vcf/validator_detail_v41.hpp"
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
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 167 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st69;
st69:
	if ( ++p == pe )
		goto _test_eof69;
case 69:
#line 2935 "inc/vcf/validator_detail_v41.hpp"
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
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st70;
tr115:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st70;
st70:
	if ( ++p == pe )
		goto _test_eof70;
case 70:
#line 2965 "inc/vcf/validator_detail_v41.hpp"
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
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st71;
tr119:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st71;
st71:
	if ( ++p == pe )
		goto _test_eof71;
case 71:
#line 2995 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 10: goto tr52;
		case 34: goto tr83;
		case 92: goto tr106;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr105;
	goto tr38;
tr120:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st72;
tr116:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st72;
st72:
	if ( ++p == pe )
		goto _test_eof72;
case 72:
#line 3024 "inc/vcf/validator_detail_v41.hpp"
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
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st73;
st73:
	if ( ++p == pe )
		goto _test_eof73;
case 73:
#line 3048 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 76: goto tr122;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr121;
tr122:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st74;
st74:
	if ( ++p == pe )
		goto _test_eof74;
case 74:
#line 3066 "inc/vcf/validator_detail_v41.hpp"
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
#line 103 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "ALT");
    }
	goto st76;
st76:
	if ( ++p == pe )
		goto _test_eof76;
case 76:
#line 3093 "inc/vcf/validator_detail_v41.hpp"
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
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st81;
tr130:
#line 139 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st81;
st81:
	if ( ++p == pe )
		goto _test_eof81;
case 81:
#line 3159 "inc/vcf/validator_detail_v41.hpp"
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
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st82;
st82:
	if ( ++p == pe )
		goto _test_eof82;
case 82:
#line 3183 "inc/vcf/validator_detail_v41.hpp"
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
#line 151 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Description");
    }
	goto st95;
st95:
	if ( ++p == pe )
		goto _test_eof95;
case 95:
#line 3281 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr149;
		case 92: goto tr150;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr148;
	goto tr147;
tr151:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st96;
tr148:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st96;
st96:
	if ( ++p == pe )
		goto _test_eof96;
case 96:
#line 3309 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr152;
		case 92: goto tr153;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr151;
	goto tr147;
tr149:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st97;
tr152:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st97;
st97:
	if ( ++p == pe )
		goto _test_eof97;
case 97:
#line 3337 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 62 )
		goto st98;
	goto tr147;
st98:
	if ( ++p == pe )
		goto _test_eof98;
case 98:
	if ( (*p) == 10 )
		goto tr52;
	goto tr121;
tr153:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st99;
tr150:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st99;
st99:
	if ( ++p == pe )
		goto _test_eof99;
case 99:
#line 3368 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr155;
		case 92: goto tr153;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr151;
	goto tr147;
tr155:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st100;
st100:
	if ( ++p == pe )
		goto _test_eof100;
case 100:
#line 3390 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr152;
		case 62: goto tr156;
		case 92: goto tr153;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr151;
	goto tr147;
tr156:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st101;
st101:
	if ( ++p == pe )
		goto _test_eof101;
case 101:
#line 3409 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 10: goto tr52;
		case 34: goto tr152;
		case 92: goto tr153;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr151;
	goto tr147;
tr131:
#line 139 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st102;
st102:
	if ( ++p == pe )
		goto _test_eof102;
case 102:
#line 3432 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 58: goto st102;
		case 95: goto st102;
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
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st103;
st103:
	if ( ++p == pe )
		goto _test_eof103;
case 103:
#line 3460 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 73: goto tr159;
		case 79: goto tr160;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr158;
tr159:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st104;
st104:
	if ( ++p == pe )
		goto _test_eof104;
case 104:
#line 3479 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 76: goto tr162;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr161;
tr162:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st105;
st105:
	if ( ++p == pe )
		goto _test_eof105;
case 105:
#line 3497 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 84: goto tr163;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr161;
tr163:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st106;
st106:
	if ( ++p == pe )
		goto _test_eof106;
case 106:
#line 3515 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 69: goto tr164;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr161;
tr164:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st107;
st107:
	if ( ++p == pe )
		goto _test_eof107;
case 107:
#line 3533 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 82: goto st108;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr161;
st108:
	if ( ++p == pe )
		goto _test_eof108;
case 108:
	if ( (*p) == 61 )
		goto tr166;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr161;
tr166:
#line 115 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "FILTER");
    }
	goto st109;
st109:
	if ( ++p == pe )
		goto _test_eof109;
case 109:
#line 3560 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 60 )
		goto st110;
	goto tr161;
st110:
	if ( ++p == pe )
		goto _test_eof110;
case 110:
	if ( (*p) == 73 )
		goto st111;
	goto tr161;
st111:
	if ( ++p == pe )
		goto _test_eof111;
case 111:
	if ( (*p) == 68 )
		goto st112;
	goto tr161;
st112:
	if ( ++p == pe )
		goto _test_eof112;
case 112:
	if ( (*p) == 61 )
		goto st113;
	goto tr161;
st113:
	if ( ++p == pe )
		goto _test_eof113;
case 113:
	if ( (*p) == 95 )
		goto tr172;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr172;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr173;
		} else if ( (*p) >= 65 )
			goto tr173;
	} else
		goto tr173;
	goto tr171;
tr172:
#line 139 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st114;
st114:
	if ( ++p == pe )
		goto _test_eof114;
case 114:
#line 3617 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 95 )
		goto st114;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st114;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr175;
		} else if ( (*p) >= 65 )
			goto tr175;
	} else
		goto tr175;
	goto tr171;
tr175:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st115;
tr173:
#line 139 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st115;
st115:
	if ( ++p == pe )
		goto _test_eof115;
case 115:
#line 3656 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 44: goto tr176;
		case 95: goto tr175;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr175;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr175;
		} else if ( (*p) >= 65 )
			goto tr175;
	} else
		goto tr175;
	goto tr171;
tr176:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st116;
st116:
	if ( ++p == pe )
		goto _test_eof116;
case 116:
#line 3683 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 68 )
		goto st117;
	goto tr161;
st117:
	if ( ++p == pe )
		goto _test_eof117;
case 117:
	if ( (*p) == 101 )
		goto st118;
	goto tr161;
st118:
	if ( ++p == pe )
		goto _test_eof118;
case 118:
	if ( (*p) == 115 )
		goto st119;
	goto tr161;
st119:
	if ( ++p == pe )
		goto _test_eof119;
case 119:
	if ( (*p) == 99 )
		goto st120;
	goto tr161;
st120:
	if ( ++p == pe )
		goto _test_eof120;
case 120:
	if ( (*p) == 114 )
		goto st121;
	goto tr161;
st121:
	if ( ++p == pe )
		goto _test_eof121;
case 121:
	if ( (*p) == 105 )
		goto st122;
	goto tr161;
st122:
	if ( ++p == pe )
		goto _test_eof122;
case 122:
	if ( (*p) == 112 )
		goto st123;
	goto tr161;
st123:
	if ( ++p == pe )
		goto _test_eof123;
case 123:
	if ( (*p) == 116 )
		goto st124;
	goto tr161;
st124:
	if ( ++p == pe )
		goto _test_eof124;
case 124:
	if ( (*p) == 105 )
		goto st125;
	goto tr161;
st125:
	if ( ++p == pe )
		goto _test_eof125;
case 125:
	if ( (*p) == 111 )
		goto st126;
	goto tr161;
st126:
	if ( ++p == pe )
		goto _test_eof126;
case 126:
	if ( (*p) == 110 )
		goto st127;
	goto tr161;
st127:
	if ( ++p == pe )
		goto _test_eof127;
case 127:
	if ( (*p) == 61 )
		goto st128;
	goto tr161;
st128:
	if ( ++p == pe )
		goto _test_eof128;
case 128:
	if ( (*p) == 34 )
		goto tr189;
	goto tr161;
tr189:
#line 151 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Description");
    }
	goto st129;
st129:
	if ( ++p == pe )
		goto _test_eof129;
case 129:
#line 3781 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr192;
		case 92: goto tr193;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr191;
	goto tr190;
tr194:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st130;
tr191:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st130;
st130:
	if ( ++p == pe )
		goto _test_eof130;
case 130:
#line 3809 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr195;
		case 92: goto tr196;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr194;
	goto tr190;
tr192:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st131;
tr195:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st131;
st131:
	if ( ++p == pe )
		goto _test_eof131;
case 131:
#line 3837 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 62 )
		goto st132;
	goto tr190;
st132:
	if ( ++p == pe )
		goto _test_eof132;
case 132:
	if ( (*p) == 10 )
		goto tr52;
	goto tr161;
tr196:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st133;
tr193:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st133;
st133:
	if ( ++p == pe )
		goto _test_eof133;
case 133:
#line 3868 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr198;
		case 92: goto tr196;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr194;
	goto tr190;
tr198:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st134;
st134:
	if ( ++p == pe )
		goto _test_eof134;
case 134:
#line 3890 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr195;
		case 62: goto tr199;
		case 92: goto tr196;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr194;
	goto tr190;
tr199:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st135;
st135:
	if ( ++p == pe )
		goto _test_eof135;
case 135:
#line 3909 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 10: goto tr52;
		case 34: goto tr195;
		case 92: goto tr196;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr194;
	goto tr190;
tr160:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st136;
st136:
	if ( ++p == pe )
		goto _test_eof136;
case 136:
#line 3928 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 82: goto tr201;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr200;
tr201:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st137;
st137:
	if ( ++p == pe )
		goto _test_eof137;
case 137:
#line 3946 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 77: goto tr202;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr200;
tr202:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st138;
st138:
	if ( ++p == pe )
		goto _test_eof138;
case 138:
#line 3964 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 65: goto tr203;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr200;
tr203:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st139;
st139:
	if ( ++p == pe )
		goto _test_eof139;
case 139:
#line 3982 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 84: goto st140;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr200;
st140:
	if ( ++p == pe )
		goto _test_eof140;
case 140:
	if ( (*p) == 61 )
		goto tr205;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr200;
tr205:
#line 119 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "FORMAT");
    }
	goto st141;
st141:
	if ( ++p == pe )
		goto _test_eof141;
case 141:
#line 4009 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 60 )
		goto st142;
	goto tr200;
st142:
	if ( ++p == pe )
		goto _test_eof142;
case 142:
	if ( (*p) == 73 )
		goto st143;
	goto tr200;
st143:
	if ( ++p == pe )
		goto _test_eof143;
case 143:
	if ( (*p) == 68 )
		goto st144;
	goto tr200;
st144:
	if ( ++p == pe )
		goto _test_eof144;
case 144:
	if ( (*p) == 61 )
		goto st145;
	goto tr200;
st145:
	if ( ++p == pe )
		goto _test_eof145;
case 145:
	if ( (*p) == 95 )
		goto tr211;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr211;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr212;
		} else if ( (*p) >= 65 )
			goto tr212;
	} else
		goto tr212;
	goto tr210;
tr211:
#line 139 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st146;
st146:
	if ( ++p == pe )
		goto _test_eof146;
case 146:
#line 4066 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 95 )
		goto st146;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st146;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr214;
		} else if ( (*p) >= 65 )
			goto tr214;
	} else
		goto tr214;
	goto tr210;
tr214:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st147;
tr212:
#line 139 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st147;
st147:
	if ( ++p == pe )
		goto _test_eof147;
case 147:
#line 4105 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 44: goto tr215;
		case 95: goto tr214;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr214;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr214;
		} else if ( (*p) >= 65 )
			goto tr214;
	} else
		goto tr214;
	goto tr210;
tr215:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st148;
st148:
	if ( ++p == pe )
		goto _test_eof148;
case 148:
#line 4132 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 78 )
		goto st149;
	goto tr200;
st149:
	if ( ++p == pe )
		goto _test_eof149;
case 149:
	if ( (*p) == 117 )
		goto st150;
	goto tr200;
st150:
	if ( ++p == pe )
		goto _test_eof150;
case 150:
	if ( (*p) == 109 )
		goto st151;
	goto tr200;
st151:
	if ( ++p == pe )
		goto _test_eof151;
case 151:
	if ( (*p) == 98 )
		goto st152;
	goto tr200;
st152:
	if ( ++p == pe )
		goto _test_eof152;
case 152:
	if ( (*p) == 101 )
		goto st153;
	goto tr200;
st153:
	if ( ++p == pe )
		goto _test_eof153;
case 153:
	if ( (*p) == 114 )
		goto st154;
	goto tr200;
st154:
	if ( ++p == pe )
		goto _test_eof154;
case 154:
	if ( (*p) == 61 )
		goto st155;
	goto tr200;
st155:
	if ( ++p == pe )
		goto _test_eof155;
case 155:
	switch( (*p) ) {
		case 46: goto tr224;
		case 65: goto tr224;
		case 71: goto tr224;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr225;
	goto tr223;
tr224:
#line 143 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Number");
    }
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st156;
st156:
	if ( ++p == pe )
		goto _test_eof156;
case 156:
#line 4208 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 44 )
		goto tr226;
	goto tr223;
tr226:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st157;
st157:
	if ( ++p == pe )
		goto _test_eof157;
case 157:
#line 4222 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 84 )
		goto st158;
	goto tr200;
st158:
	if ( ++p == pe )
		goto _test_eof158;
case 158:
	if ( (*p) == 121 )
		goto st159;
	goto tr200;
st159:
	if ( ++p == pe )
		goto _test_eof159;
case 159:
	if ( (*p) == 112 )
		goto st160;
	goto tr200;
st160:
	if ( ++p == pe )
		goto _test_eof160;
case 160:
	if ( (*p) == 101 )
		goto st161;
	goto tr200;
st161:
	if ( ++p == pe )
		goto _test_eof161;
case 161:
	if ( (*p) == 61 )
		goto st162;
	goto tr200;
st162:
	if ( ++p == pe )
		goto _test_eof162;
case 162:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr233;
	} else if ( (*p) >= 65 )
		goto tr233;
	goto tr232;
tr235:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st163;
tr233:
#line 147 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Type");
    }
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st163;
st163:
	if ( ++p == pe )
		goto _test_eof163;
case 163:
#line 4288 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 44 )
		goto tr234;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr235;
	} else if ( (*p) >= 65 )
		goto tr235;
	goto tr232;
tr234:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st164;
st164:
	if ( ++p == pe )
		goto _test_eof164;
case 164:
#line 4307 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 68 )
		goto st165;
	goto tr200;
st165:
	if ( ++p == pe )
		goto _test_eof165;
case 165:
	if ( (*p) == 101 )
		goto st166;
	goto tr200;
st166:
	if ( ++p == pe )
		goto _test_eof166;
case 166:
	if ( (*p) == 115 )
		goto st167;
	goto tr200;
st167:
	if ( ++p == pe )
		goto _test_eof167;
case 167:
	if ( (*p) == 99 )
		goto st168;
	goto tr200;
st168:
	if ( ++p == pe )
		goto _test_eof168;
case 168:
	if ( (*p) == 114 )
		goto st169;
	goto tr200;
st169:
	if ( ++p == pe )
		goto _test_eof169;
case 169:
	if ( (*p) == 105 )
		goto st170;
	goto tr200;
st170:
	if ( ++p == pe )
		goto _test_eof170;
case 170:
	if ( (*p) == 112 )
		goto st171;
	goto tr200;
st171:
	if ( ++p == pe )
		goto _test_eof171;
case 171:
	if ( (*p) == 116 )
		goto st172;
	goto tr200;
st172:
	if ( ++p == pe )
		goto _test_eof172;
case 172:
	if ( (*p) == 105 )
		goto st173;
	goto tr200;
st173:
	if ( ++p == pe )
		goto _test_eof173;
case 173:
	if ( (*p) == 111 )
		goto st174;
	goto tr200;
st174:
	if ( ++p == pe )
		goto _test_eof174;
case 174:
	if ( (*p) == 110 )
		goto st175;
	goto tr200;
st175:
	if ( ++p == pe )
		goto _test_eof175;
case 175:
	if ( (*p) == 61 )
		goto st176;
	goto tr200;
st176:
	if ( ++p == pe )
		goto _test_eof176;
case 176:
	if ( (*p) == 34 )
		goto tr248;
	goto tr200;
tr248:
#line 151 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Description");
    }
	goto st177;
st177:
	if ( ++p == pe )
		goto _test_eof177;
case 177:
#line 4405 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr251;
		case 92: goto tr252;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr250;
	goto tr249;
tr253:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st178;
tr250:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st178;
st178:
	if ( ++p == pe )
		goto _test_eof178;
case 178:
#line 4433 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr254;
		case 92: goto tr255;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr253;
	goto tr249;
tr251:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st179;
tr254:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st179;
st179:
	if ( ++p == pe )
		goto _test_eof179;
case 179:
#line 4461 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 62 )
		goto st180;
	goto tr249;
st180:
	if ( ++p == pe )
		goto _test_eof180;
case 180:
	if ( (*p) == 10 )
		goto tr52;
	goto tr200;
tr255:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st181;
tr252:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st181;
st181:
	if ( ++p == pe )
		goto _test_eof181;
case 181:
#line 4492 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr257;
		case 92: goto tr255;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr253;
	goto tr249;
tr257:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st182;
st182:
	if ( ++p == pe )
		goto _test_eof182;
case 182:
#line 4514 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr254;
		case 62: goto tr258;
		case 92: goto tr255;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr253;
	goto tr249;
tr258:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st183;
st183:
	if ( ++p == pe )
		goto _test_eof183;
case 183:
#line 4533 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 10: goto tr52;
		case 34: goto tr254;
		case 92: goto tr255;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr253;
	goto tr249;
tr259:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st184;
tr225:
#line 143 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Number");
    }
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st184;
st184:
	if ( ++p == pe )
		goto _test_eof184;
case 184:
#line 4566 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 44 )
		goto tr226;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr259;
	goto tr223;
tr32:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st185;
st185:
	if ( ++p == pe )
		goto _test_eof185;
case 185:
#line 4586 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 78: goto tr261;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr260;
tr261:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st186;
st186:
	if ( ++p == pe )
		goto _test_eof186;
case 186:
#line 4604 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 70: goto tr262;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr260;
tr262:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st187;
st187:
	if ( ++p == pe )
		goto _test_eof187;
case 187:
#line 4622 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 79: goto st188;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr260;
st188:
	if ( ++p == pe )
		goto _test_eof188;
case 188:
	if ( (*p) == 61 )
		goto tr264;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr260;
tr264:
#line 123 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "INFO");
    }
	goto st189;
st189:
	if ( ++p == pe )
		goto _test_eof189;
case 189:
#line 4649 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 60 )
		goto st190;
	goto tr260;
st190:
	if ( ++p == pe )
		goto _test_eof190;
case 190:
	if ( (*p) == 73 )
		goto st191;
	goto tr260;
st191:
	if ( ++p == pe )
		goto _test_eof191;
case 191:
	if ( (*p) == 68 )
		goto st192;
	goto tr260;
st192:
	if ( ++p == pe )
		goto _test_eof192;
case 192:
	if ( (*p) == 61 )
		goto st193;
	goto tr260;
st193:
	if ( ++p == pe )
		goto _test_eof193;
case 193:
	if ( (*p) == 95 )
		goto tr270;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr270;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr271;
		} else if ( (*p) >= 65 )
			goto tr271;
	} else
		goto tr271;
	goto tr269;
tr270:
#line 139 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st194;
st194:
	if ( ++p == pe )
		goto _test_eof194;
case 194:
#line 4706 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 95 )
		goto st194;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st194;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr273;
		} else if ( (*p) >= 65 )
			goto tr273;
	} else
		goto tr273;
	goto tr269;
tr273:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st195;
tr271:
#line 139 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st195;
st195:
	if ( ++p == pe )
		goto _test_eof195;
case 195:
#line 4745 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 44: goto tr274;
		case 95: goto tr273;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr273;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr273;
		} else if ( (*p) >= 65 )
			goto tr273;
	} else
		goto tr273;
	goto tr269;
tr274:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st196;
st196:
	if ( ++p == pe )
		goto _test_eof196;
case 196:
#line 4772 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 78 )
		goto st197;
	goto tr260;
st197:
	if ( ++p == pe )
		goto _test_eof197;
case 197:
	if ( (*p) == 117 )
		goto st198;
	goto tr260;
st198:
	if ( ++p == pe )
		goto _test_eof198;
case 198:
	if ( (*p) == 109 )
		goto st199;
	goto tr260;
st199:
	if ( ++p == pe )
		goto _test_eof199;
case 199:
	if ( (*p) == 98 )
		goto st200;
	goto tr260;
st200:
	if ( ++p == pe )
		goto _test_eof200;
case 200:
	if ( (*p) == 101 )
		goto st201;
	goto tr260;
st201:
	if ( ++p == pe )
		goto _test_eof201;
case 201:
	if ( (*p) == 114 )
		goto st202;
	goto tr260;
st202:
	if ( ++p == pe )
		goto _test_eof202;
case 202:
	if ( (*p) == 61 )
		goto st203;
	goto tr260;
st203:
	if ( ++p == pe )
		goto _test_eof203;
case 203:
	switch( (*p) ) {
		case 46: goto tr283;
		case 65: goto tr283;
		case 71: goto tr283;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr284;
	goto tr282;
tr283:
#line 143 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Number");
    }
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st204;
st204:
	if ( ++p == pe )
		goto _test_eof204;
case 204:
#line 4848 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 44 )
		goto tr285;
	goto tr282;
tr285:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st205;
st205:
	if ( ++p == pe )
		goto _test_eof205;
case 205:
#line 4862 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 84 )
		goto st206;
	goto tr260;
st206:
	if ( ++p == pe )
		goto _test_eof206;
case 206:
	if ( (*p) == 121 )
		goto st207;
	goto tr260;
st207:
	if ( ++p == pe )
		goto _test_eof207;
case 207:
	if ( (*p) == 112 )
		goto st208;
	goto tr260;
st208:
	if ( ++p == pe )
		goto _test_eof208;
case 208:
	if ( (*p) == 101 )
		goto st209;
	goto tr260;
st209:
	if ( ++p == pe )
		goto _test_eof209;
case 209:
	if ( (*p) == 61 )
		goto st210;
	goto tr260;
st210:
	if ( ++p == pe )
		goto _test_eof210;
case 210:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr292;
	} else if ( (*p) >= 65 )
		goto tr292;
	goto tr291;
tr294:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st211;
tr292:
#line 147 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Type");
    }
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st211;
st211:
	if ( ++p == pe )
		goto _test_eof211;
case 211:
#line 4928 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 44 )
		goto tr293;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr294;
	} else if ( (*p) >= 65 )
		goto tr294;
	goto tr291;
tr293:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st212;
st212:
	if ( ++p == pe )
		goto _test_eof212;
case 212:
#line 4947 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 68 )
		goto st213;
	goto tr260;
st213:
	if ( ++p == pe )
		goto _test_eof213;
case 213:
	if ( (*p) == 101 )
		goto st214;
	goto tr260;
st214:
	if ( ++p == pe )
		goto _test_eof214;
case 214:
	if ( (*p) == 115 )
		goto st215;
	goto tr260;
st215:
	if ( ++p == pe )
		goto _test_eof215;
case 215:
	if ( (*p) == 99 )
		goto st216;
	goto tr260;
st216:
	if ( ++p == pe )
		goto _test_eof216;
case 216:
	if ( (*p) == 114 )
		goto st217;
	goto tr260;
st217:
	if ( ++p == pe )
		goto _test_eof217;
case 217:
	if ( (*p) == 105 )
		goto st218;
	goto tr260;
st218:
	if ( ++p == pe )
		goto _test_eof218;
case 218:
	if ( (*p) == 112 )
		goto st219;
	goto tr260;
st219:
	if ( ++p == pe )
		goto _test_eof219;
case 219:
	if ( (*p) == 116 )
		goto st220;
	goto tr260;
st220:
	if ( ++p == pe )
		goto _test_eof220;
case 220:
	if ( (*p) == 105 )
		goto st221;
	goto tr260;
st221:
	if ( ++p == pe )
		goto _test_eof221;
case 221:
	if ( (*p) == 111 )
		goto st222;
	goto tr260;
st222:
	if ( ++p == pe )
		goto _test_eof222;
case 222:
	if ( (*p) == 110 )
		goto st223;
	goto tr260;
st223:
	if ( ++p == pe )
		goto _test_eof223;
case 223:
	if ( (*p) == 61 )
		goto st224;
	goto tr260;
st224:
	if ( ++p == pe )
		goto _test_eof224;
case 224:
	if ( (*p) == 34 )
		goto tr307;
	goto tr260;
tr307:
#line 151 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Description");
    }
	goto st225;
st225:
	if ( ++p == pe )
		goto _test_eof225;
case 225:
#line 5045 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr310;
		case 92: goto tr311;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr309;
	goto tr308;
tr312:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st226;
tr309:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st226;
st226:
	if ( ++p == pe )
		goto _test_eof226;
case 226:
#line 5073 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr313;
		case 92: goto tr314;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr312;
	goto tr308;
tr310:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st227;
tr313:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st227;
st227:
	if ( ++p == pe )
		goto _test_eof227;
case 227:
#line 5101 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 62 )
		goto st228;
	goto tr308;
st228:
	if ( ++p == pe )
		goto _test_eof228;
case 228:
	if ( (*p) == 10 )
		goto tr52;
	goto tr260;
tr314:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st229;
tr311:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st229;
st229:
	if ( ++p == pe )
		goto _test_eof229;
case 229:
#line 5132 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr316;
		case 92: goto tr314;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr312;
	goto tr308;
tr316:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st230;
st230:
	if ( ++p == pe )
		goto _test_eof230;
case 230:
#line 5154 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr313;
		case 62: goto tr317;
		case 92: goto tr314;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr312;
	goto tr308;
tr317:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st231;
st231:
	if ( ++p == pe )
		goto _test_eof231;
case 231:
#line 5173 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 10: goto tr52;
		case 34: goto tr313;
		case 92: goto tr314;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr312;
	goto tr308;
tr318:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st232;
tr284:
#line 143 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Number");
    }
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st232;
st232:
	if ( ++p == pe )
		goto _test_eof232;
case 232:
#line 5206 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 44 )
		goto tr285;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr318;
	goto tr282;
tr33:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st233;
st233:
	if ( ++p == pe )
		goto _test_eof233;
case 233:
#line 5226 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 69: goto tr320;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr319;
tr320:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st234;
st234:
	if ( ++p == pe )
		goto _test_eof234;
case 234:
#line 5244 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 68: goto tr321;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr319;
tr321:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st235;
st235:
	if ( ++p == pe )
		goto _test_eof235;
case 235:
#line 5262 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 73: goto tr322;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr319;
tr322:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st236;
st236:
	if ( ++p == pe )
		goto _test_eof236;
case 236:
#line 5280 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 71: goto tr323;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr319;
tr323:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st237;
st237:
	if ( ++p == pe )
		goto _test_eof237;
case 237:
#line 5298 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 82: goto tr324;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr319;
tr324:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st238;
st238:
	if ( ++p == pe )
		goto _test_eof238;
case 238:
#line 5316 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 69: goto tr325;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr319;
tr325:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st239;
st239:
	if ( ++p == pe )
		goto _test_eof239;
case 239:
#line 5334 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 69: goto st240;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr319;
st240:
	if ( ++p == pe )
		goto _test_eof240;
case 240:
	if ( (*p) == 61 )
		goto tr327;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr319;
tr327:
#line 127 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "PEDIGREE");
    }
	goto st241;
st241:
	if ( ++p == pe )
		goto _test_eof241;
case 241:
#line 5361 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 60 )
		goto st242;
	goto tr319;
tr339:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st242;
st242:
	if ( ++p == pe )
		goto _test_eof242;
case 242:
#line 5375 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 95 )
		goto tr330;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr330;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr331;
		} else if ( (*p) >= 65 )
			goto tr331;
	} else
		goto tr331;
	goto tr329;
tr330:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st243;
st243:
	if ( ++p == pe )
		goto _test_eof243;
case 243:
#line 5400 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 95 )
		goto st243;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st243;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr333;
		} else if ( (*p) >= 65 )
			goto tr333;
	} else
		goto tr333;
	goto tr329;
tr333:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st244;
tr331:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st244;
st244:
	if ( ++p == pe )
		goto _test_eof244;
case 244:
#line 5435 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr334;
		case 95: goto tr333;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr333;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr333;
		} else if ( (*p) >= 65 )
			goto tr333;
	} else
		goto tr333;
	goto tr329;
tr334:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st245;
st245:
	if ( ++p == pe )
		goto _test_eof245;
case 245:
#line 5462 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 95 )
		goto tr335;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr335;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr336;
		} else if ( (*p) >= 65 )
			goto tr336;
	} else
		goto tr336;
	goto tr329;
tr335:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st246;
st246:
	if ( ++p == pe )
		goto _test_eof246;
case 246:
#line 5487 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 95 )
		goto st246;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st246;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr338;
		} else if ( (*p) >= 65 )
			goto tr338;
	} else
		goto tr338;
	goto tr329;
tr338:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st247;
tr336:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st247;
st247:
	if ( ++p == pe )
		goto _test_eof247;
case 247:
#line 5522 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 44: goto tr339;
		case 62: goto tr340;
		case 95: goto tr338;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr338;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr338;
		} else if ( (*p) >= 65 )
			goto tr338;
	} else
		goto tr338;
	goto tr329;
tr340:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st248;
st248:
	if ( ++p == pe )
		goto _test_eof248;
case 248:
#line 5550 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 10 )
		goto tr52;
	goto tr319;
tr34:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st249;
st249:
	if ( ++p == pe )
		goto _test_eof249;
case 249:
#line 5568 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 65: goto tr342;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr341;
tr342:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st250;
st250:
	if ( ++p == pe )
		goto _test_eof250;
case 250:
#line 5586 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 77: goto tr343;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr341;
tr343:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st251;
st251:
	if ( ++p == pe )
		goto _test_eof251;
case 251:
#line 5604 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 80: goto tr344;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr341;
tr344:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st252;
st252:
	if ( ++p == pe )
		goto _test_eof252;
case 252:
#line 5622 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 76: goto tr345;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr341;
tr345:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st253;
st253:
	if ( ++p == pe )
		goto _test_eof253;
case 253:
#line 5640 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 69: goto st254;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr341;
st254:
	if ( ++p == pe )
		goto _test_eof254;
case 254:
	if ( (*p) == 61 )
		goto tr347;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr341;
tr347:
#line 135 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "SAMPLE");
    }
	goto st255;
st255:
	if ( ++p == pe )
		goto _test_eof255;
case 255:
#line 5667 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 60 )
		goto st256;
	goto tr341;
st256:
	if ( ++p == pe )
		goto _test_eof256;
case 256:
	if ( (*p) == 73 )
		goto st257;
	goto tr341;
st257:
	if ( ++p == pe )
		goto _test_eof257;
case 257:
	if ( (*p) == 68 )
		goto st258;
	goto tr341;
st258:
	if ( ++p == pe )
		goto _test_eof258;
case 258:
	if ( (*p) == 61 )
		goto st259;
	goto tr341;
st259:
	if ( ++p == pe )
		goto _test_eof259;
case 259:
	if ( (*p) == 95 )
		goto tr353;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr353;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr354;
		} else if ( (*p) >= 65 )
			goto tr354;
	} else
		goto tr354;
	goto tr352;
tr353:
#line 139 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st260;
st260:
	if ( ++p == pe )
		goto _test_eof260;
case 260:
#line 5724 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 95 )
		goto st260;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st260;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr356;
		} else if ( (*p) >= 65 )
			goto tr356;
	} else
		goto tr356;
	goto tr352;
tr356:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st261;
tr354:
#line 139 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st261;
st261:
	if ( ++p == pe )
		goto _test_eof261;
case 261:
#line 5763 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 44: goto tr358;
		case 95: goto tr356;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr356;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr356;
		} else if ( (*p) >= 65 )
			goto tr356;
	} else
		goto tr356;
	goto tr357;
tr358:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st262;
st262:
	if ( ++p == pe )
		goto _test_eof262;
case 262:
#line 5790 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 71 )
		goto st263;
	goto tr359;
st263:
	if ( ++p == pe )
		goto _test_eof263;
case 263:
	if ( (*p) == 101 )
		goto st264;
	goto tr359;
st264:
	if ( ++p == pe )
		goto _test_eof264;
case 264:
	if ( (*p) == 110 )
		goto st265;
	goto tr359;
st265:
	if ( ++p == pe )
		goto _test_eof265;
case 265:
	if ( (*p) == 111 )
		goto st266;
	goto tr359;
st266:
	if ( ++p == pe )
		goto _test_eof266;
case 266:
	if ( (*p) == 109 )
		goto st267;
	goto tr359;
st267:
	if ( ++p == pe )
		goto _test_eof267;
case 267:
	if ( (*p) == 101 )
		goto st268;
	goto tr359;
st268:
	if ( ++p == pe )
		goto _test_eof268;
case 268:
	if ( (*p) == 115 )
		goto st269;
	goto tr359;
st269:
	if ( ++p == pe )
		goto _test_eof269;
case 269:
	if ( (*p) == 61 )
		goto st270;
	goto tr359;
st270:
	if ( ++p == pe )
		goto _test_eof270;
case 270:
	if ( (*p) < 35 ) {
		if ( 32 <= (*p) && (*p) <= 33 )
			goto tr368;
	} else if ( (*p) > 43 ) {
		if ( (*p) > 61 ) {
			if ( 63 <= (*p) && (*p) <= 126 )
				goto tr368;
		} else if ( (*p) >= 45 )
			goto tr368;
	} else
		goto tr368;
	goto tr359;
tr370:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st271;
tr368:
#line 155 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Genomes");
    }
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st271;
st271:
	if ( ++p == pe )
		goto _test_eof271;
case 271:
#line 5883 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 44 )
		goto tr371;
	if ( (*p) < 35 ) {
		if ( 32 <= (*p) && (*p) <= 33 )
			goto tr370;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr370;
	} else
		goto tr370;
	goto tr369;
tr371:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st272;
st272:
	if ( ++p == pe )
		goto _test_eof272;
case 272:
#line 5905 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 77 )
		goto st273;
	goto tr372;
st273:
	if ( ++p == pe )
		goto _test_eof273;
case 273:
	if ( (*p) == 105 )
		goto st274;
	goto tr372;
st274:
	if ( ++p == pe )
		goto _test_eof274;
case 274:
	if ( (*p) == 120 )
		goto st275;
	goto tr372;
st275:
	if ( ++p == pe )
		goto _test_eof275;
case 275:
	if ( (*p) == 116 )
		goto st276;
	goto tr372;
st276:
	if ( ++p == pe )
		goto _test_eof276;
case 276:
	if ( (*p) == 117 )
		goto st277;
	goto tr372;
st277:
	if ( ++p == pe )
		goto _test_eof277;
case 277:
	if ( (*p) == 114 )
		goto st278;
	goto tr372;
st278:
	if ( ++p == pe )
		goto _test_eof278;
case 278:
	if ( (*p) == 101 )
		goto st279;
	goto tr372;
st279:
	if ( ++p == pe )
		goto _test_eof279;
case 279:
	if ( (*p) == 61 )
		goto st280;
	goto tr372;
st280:
	if ( ++p == pe )
		goto _test_eof280;
case 280:
	if ( (*p) < 35 ) {
		if ( 32 <= (*p) && (*p) <= 33 )
			goto tr381;
	} else if ( (*p) > 43 ) {
		if ( (*p) > 61 ) {
			if ( 63 <= (*p) && (*p) <= 126 )
				goto tr381;
		} else if ( (*p) >= 45 )
			goto tr381;
	} else
		goto tr381;
	goto tr372;
tr383:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st281;
tr381:
#line 159 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Mixture");
    }
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st281;
st281:
	if ( ++p == pe )
		goto _test_eof281;
case 281:
#line 5998 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 44 )
		goto tr384;
	if ( (*p) < 35 ) {
		if ( 32 <= (*p) && (*p) <= 33 )
			goto tr383;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr383;
	} else
		goto tr383;
	goto tr382;
tr384:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st282;
st282:
	if ( ++p == pe )
		goto _test_eof282;
case 282:
#line 6020 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 68 )
		goto st283;
	goto tr385;
st283:
	if ( ++p == pe )
		goto _test_eof283;
case 283:
	if ( (*p) == 101 )
		goto st284;
	goto tr385;
st284:
	if ( ++p == pe )
		goto _test_eof284;
case 284:
	if ( (*p) == 115 )
		goto st285;
	goto tr385;
st285:
	if ( ++p == pe )
		goto _test_eof285;
case 285:
	if ( (*p) == 99 )
		goto st286;
	goto tr385;
st286:
	if ( ++p == pe )
		goto _test_eof286;
case 286:
	if ( (*p) == 114 )
		goto st287;
	goto tr385;
st287:
	if ( ++p == pe )
		goto _test_eof287;
case 287:
	if ( (*p) == 105 )
		goto st288;
	goto tr385;
st288:
	if ( ++p == pe )
		goto _test_eof288;
case 288:
	if ( (*p) == 112 )
		goto st289;
	goto tr385;
st289:
	if ( ++p == pe )
		goto _test_eof289;
case 289:
	if ( (*p) == 116 )
		goto st290;
	goto tr385;
st290:
	if ( ++p == pe )
		goto _test_eof290;
case 290:
	if ( (*p) == 105 )
		goto st291;
	goto tr385;
st291:
	if ( ++p == pe )
		goto _test_eof291;
case 291:
	if ( (*p) == 111 )
		goto st292;
	goto tr385;
st292:
	if ( ++p == pe )
		goto _test_eof292;
case 292:
	if ( (*p) == 110 )
		goto st293;
	goto tr385;
st293:
	if ( ++p == pe )
		goto _test_eof293;
case 293:
	if ( (*p) == 61 )
		goto st294;
	goto tr385;
st294:
	if ( ++p == pe )
		goto _test_eof294;
case 294:
	if ( (*p) == 34 )
		goto tr398;
	goto tr385;
tr398:
#line 151 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Description");
    }
	goto st295;
st295:
	if ( ++p == pe )
		goto _test_eof295;
case 295:
#line 6118 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr400;
		case 92: goto tr401;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr399;
	goto tr385;
tr402:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st296;
tr399:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st296;
st296:
	if ( ++p == pe )
		goto _test_eof296;
case 296:
#line 6146 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr403;
		case 92: goto tr404;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr402;
	goto tr385;
tr400:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st297;
tr403:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st297;
st297:
	if ( ++p == pe )
		goto _test_eof297;
case 297:
#line 6174 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 62 )
		goto st298;
	goto tr385;
st298:
	if ( ++p == pe )
		goto _test_eof298;
case 298:
	if ( (*p) == 10 )
		goto tr52;
	goto tr341;
tr404:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st299;
tr401:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st299;
st299:
	if ( ++p == pe )
		goto _test_eof299;
case 299:
#line 6205 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr406;
		case 92: goto tr404;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr402;
	goto tr385;
tr406:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st300;
st300:
	if ( ++p == pe )
		goto _test_eof300;
case 300:
#line 6227 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr403;
		case 62: goto tr407;
		case 92: goto tr404;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr402;
	goto tr385;
tr407:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st301;
st301:
	if ( ++p == pe )
		goto _test_eof301;
case 301:
#line 6246 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 10: goto tr52;
		case 34: goto tr403;
		case 92: goto tr404;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr402;
	goto tr385;
tr35:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st302;
st302:
	if ( ++p == pe )
		goto _test_eof302;
case 302:
#line 6269 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 115: goto tr409;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr408;
tr409:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st303;
st303:
	if ( ++p == pe )
		goto _test_eof303;
case 303:
#line 6287 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 115: goto tr410;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr408;
tr410:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st304;
st304:
	if ( ++p == pe )
		goto _test_eof304;
case 304:
#line 6305 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 101: goto tr411;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr408;
tr411:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st305;
st305:
	if ( ++p == pe )
		goto _test_eof305;
case 305:
#line 6323 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 109: goto tr412;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr408;
tr412:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st306;
st306:
	if ( ++p == pe )
		goto _test_eof306;
case 306:
#line 6341 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 98: goto tr413;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr408;
tr413:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st307;
st307:
	if ( ++p == pe )
		goto _test_eof307;
case 307:
#line 6359 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 108: goto tr414;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr408;
tr414:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st308;
st308:
	if ( ++p == pe )
		goto _test_eof308;
case 308:
#line 6377 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 121: goto st309;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr408;
st309:
	if ( ++p == pe )
		goto _test_eof309;
case 309:
	if ( (*p) == 61 )
		goto tr416;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr408;
tr416:
#line 107 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "assembly");
    }
	goto st310;
st310:
	if ( ++p == pe )
		goto _test_eof310;
case 310:
#line 6404 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr418;
	} else if ( (*p) >= 65 )
		goto tr418;
	goto tr417;
tr418:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st311;
st311:
	if ( ++p == pe )
		goto _test_eof311;
case 311:
#line 6421 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 10: goto tr417;
		case 35: goto tr417;
		case 47: goto tr417;
		case 58: goto tr417;
		case 63: goto tr417;
	}
	goto st312;
st312:
	if ( ++p == pe )
		goto _test_eof312;
case 312:
	switch( (*p) ) {
		case 10: goto tr417;
		case 35: goto tr417;
		case 47: goto tr417;
		case 58: goto st313;
		case 63: goto tr417;
	}
	goto st312;
st313:
	if ( ++p == pe )
		goto _test_eof313;
case 313:
	if ( (*p) == 47 )
		goto st314;
	goto tr417;
st314:
	if ( ++p == pe )
		goto _test_eof314;
case 314:
	if ( (*p) == 47 )
		goto st315;
	goto tr417;
st315:
	if ( ++p == pe )
		goto _test_eof315;
case 315:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr423;
	} else if ( (*p) >= 65 )
		goto tr423;
	goto tr417;
tr423:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st316;
st316:
	if ( ++p == pe )
		goto _test_eof316;
case 316:
#line 6476 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 10 )
		goto tr44;
	goto tr423;
tr36:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st317;
st317:
	if ( ++p == pe )
		goto _test_eof317;
case 317:
#line 6494 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 111: goto tr425;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr424;
tr425:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st318;
st318:
	if ( ++p == pe )
		goto _test_eof318;
case 318:
#line 6512 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 110: goto tr426;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr424;
tr426:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st319;
st319:
	if ( ++p == pe )
		goto _test_eof319;
case 319:
#line 6530 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 116: goto tr427;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr424;
tr427:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st320;
st320:
	if ( ++p == pe )
		goto _test_eof320;
case 320:
#line 6548 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 105: goto tr428;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr424;
tr428:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st321;
st321:
	if ( ++p == pe )
		goto _test_eof321;
case 321:
#line 6566 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 103: goto st322;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr424;
st322:
	if ( ++p == pe )
		goto _test_eof322;
case 322:
	if ( (*p) == 61 )
		goto tr430;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr424;
tr430:
#line 111 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "contig");
    }
	goto st323;
st323:
	if ( ++p == pe )
		goto _test_eof323;
case 323:
#line 6593 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 60 )
		goto st324;
	goto tr424;
st324:
	if ( ++p == pe )
		goto _test_eof324;
case 324:
	if ( (*p) == 73 )
		goto st325;
	goto tr424;
st325:
	if ( ++p == pe )
		goto _test_eof325;
case 325:
	if ( (*p) == 68 )
		goto st326;
	goto tr424;
st326:
	if ( ++p == pe )
		goto _test_eof326;
case 326:
	if ( (*p) == 61 )
		goto st327;
	goto tr424;
st327:
	if ( ++p == pe )
		goto _test_eof327;
case 327:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr436;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr436;
	} else
		goto tr436;
	goto tr435;
tr436:
#line 139 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st328;
st328:
	if ( ++p == pe )
		goto _test_eof328;
case 328:
#line 6649 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 44: goto tr438;
		case 59: goto tr437;
		case 62: goto tr440;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr437;
		} else if ( (*p) > 57 ) {
			if ( 61 <= (*p) && (*p) <= 64 )
				goto tr437;
		} else
			goto tr439;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr437;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr437;
		} else
			goto tr439;
	} else
		goto tr439;
	goto tr435;
tr437:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st329;
st329:
	if ( ++p == pe )
		goto _test_eof329;
case 329:
#line 6686 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 59: goto tr437;
		case 61: goto tr437;
	}
	if ( (*p) < 63 ) {
		if ( (*p) < 45 ) {
			if ( 33 <= (*p) && (*p) <= 43 )
				goto tr437;
		} else if ( (*p) > 47 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr439;
		} else
			goto tr437;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr439;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr437;
			} else if ( (*p) >= 97 )
				goto tr439;
		} else
			goto tr437;
	} else
		goto tr437;
	goto tr435;
tr439:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st330;
st330:
	if ( ++p == pe )
		goto _test_eof330;
case 330:
#line 6725 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 44: goto tr438;
		case 59: goto tr439;
		case 62: goto tr440;
	}
	if ( (*p) > 57 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr439;
	} else if ( (*p) >= 33 )
		goto tr439;
	goto tr435;
tr438:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st331;
st331:
	if ( ++p == pe )
		goto _test_eof331;
case 331:
#line 6747 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 95 )
		goto tr441;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr441;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr442;
		} else if ( (*p) >= 65 )
			goto tr442;
	} else
		goto tr442;
	goto tr424;
tr441:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st332;
st332:
	if ( ++p == pe )
		goto _test_eof332;
case 332:
#line 6772 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 95 )
		goto st332;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st332;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr444;
		} else if ( (*p) >= 65 )
			goto tr444;
	} else
		goto tr444;
	goto tr424;
tr444:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st333;
tr442:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st333;
st333:
	if ( ++p == pe )
		goto _test_eof333;
case 333:
#line 6807 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr445;
		case 95: goto tr444;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr444;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr444;
		} else if ( (*p) >= 65 )
			goto tr444;
	} else
		goto tr444;
	goto tr424;
tr445:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st334;
st334:
	if ( ++p == pe )
		goto _test_eof334;
case 334:
#line 6834 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 34 )
		goto st337;
	if ( (*p) < 45 ) {
		if ( 32 <= (*p) && (*p) <= 43 )
			goto tr446;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr446;
	} else
		goto tr446;
	goto tr424;
tr448:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st335;
tr446:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st335;
st335:
	if ( ++p == pe )
		goto _test_eof335;
case 335:
#line 6866 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 44: goto tr438;
		case 62: goto tr440;
	}
	if ( (*p) > 33 ) {
		if ( 35 <= (*p) && (*p) <= 126 )
			goto tr448;
	} else if ( (*p) >= 32 )
		goto tr448;
	goto tr424;
tr440:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st336;
st336:
	if ( ++p == pe )
		goto _test_eof336;
case 336:
#line 6887 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 10 )
		goto tr52;
	goto tr424;
st337:
	if ( ++p == pe )
		goto _test_eof337;
case 337:
	switch( (*p) ) {
		case 34: goto tr450;
		case 92: goto tr451;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr449;
	goto tr424;
tr452:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st338;
tr449:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st338;
st338:
	if ( ++p == pe )
		goto _test_eof338;
case 338:
#line 6922 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr453;
		case 92: goto tr454;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr452;
	goto tr424;
tr450:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st339;
tr453:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st339;
st339:
	if ( ++p == pe )
		goto _test_eof339;
case 339:
#line 6950 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 44: goto st331;
		case 62: goto st336;
	}
	goto tr424;
tr454:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st340;
tr451:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st340;
st340:
	if ( ++p == pe )
		goto _test_eof340;
case 340:
#line 6976 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr457;
		case 92: goto tr454;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr452;
	goto tr424;
tr457:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st341;
st341:
	if ( ++p == pe )
		goto _test_eof341;
case 341:
#line 6998 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr453;
		case 44: goto tr458;
		case 62: goto tr459;
		case 92: goto tr454;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr452;
	goto tr424;
tr458:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st342;
tr472:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st342;
tr469:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st342;
st342:
	if ( ++p == pe )
		goto _test_eof342;
case 342:
#line 7038 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr453;
		case 47: goto tr452;
		case 92: goto tr454;
		case 95: goto tr460;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr452;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr461;
		} else
			goto tr460;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr461;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr452;
			} else if ( (*p) >= 97 )
				goto tr461;
		} else
			goto tr452;
	} else
		goto tr452;
	goto tr424;
tr462:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st343;
tr460:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st343;
st343:
	if ( ++p == pe )
		goto _test_eof343;
case 343:
#line 7089 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr453;
		case 47: goto tr452;
		case 92: goto tr454;
		case 95: goto tr462;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr452;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr463;
		} else
			goto tr462;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr463;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr452;
			} else if ( (*p) >= 97 )
				goto tr463;
		} else
			goto tr452;
	} else
		goto tr452;
	goto tr424;
tr463:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st344;
tr461:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st344;
st344:
	if ( ++p == pe )
		goto _test_eof344;
case 344:
#line 7140 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr453;
		case 47: goto tr452;
		case 61: goto tr464;
		case 92: goto tr454;
		case 95: goto tr463;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr452;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr452;
		} else
			goto tr463;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr452;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr452;
		} else
			goto tr463;
	} else
		goto tr463;
	goto tr424;
tr464:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st345;
st345:
	if ( ++p == pe )
		goto _test_eof345;
case 345:
#line 7183 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr466;
		case 44: goto tr452;
		case 62: goto tr452;
		case 92: goto tr467;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr465;
	goto tr424;
tr468:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st346;
tr465:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st346;
st346:
	if ( ++p == pe )
		goto _test_eof346;
case 346:
#line 7213 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr453;
		case 44: goto tr469;
		case 62: goto tr470;
		case 92: goto tr471;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr468;
	goto tr424;
tr459:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st347;
tr473:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st347;
tr470:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st347;
st347:
	if ( ++p == pe )
		goto _test_eof347;
case 347:
#line 7253 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 10: goto tr52;
		case 34: goto tr453;
		case 92: goto tr454;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr452;
	goto tr424;
tr471:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st348;
tr467:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st348;
st348:
	if ( ++p == pe )
		goto _test_eof348;
case 348:
#line 7282 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr457;
		case 44: goto tr469;
		case 62: goto tr470;
		case 92: goto tr471;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr468;
	goto tr424;
tr466:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st349;
st349:
	if ( ++p == pe )
		goto _test_eof349;
case 349:
#line 7302 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr450;
		case 44: goto tr472;
		case 62: goto tr473;
		case 92: goto tr451;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr449;
	goto tr424;
tr37:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st350;
st350:
	if ( ++p == pe )
		goto _test_eof350;
case 350:
#line 7326 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 101: goto tr475;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr474;
tr475:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st351;
st351:
	if ( ++p == pe )
		goto _test_eof351;
case 351:
#line 7344 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 100: goto tr476;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr474;
tr476:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st352;
st352:
	if ( ++p == pe )
		goto _test_eof352;
case 352:
#line 7362 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 105: goto tr477;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr474;
tr477:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st353;
st353:
	if ( ++p == pe )
		goto _test_eof353;
case 353:
#line 7380 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 103: goto tr478;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr474;
tr478:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st354;
st354:
	if ( ++p == pe )
		goto _test_eof354;
case 354:
#line 7398 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 114: goto tr479;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr474;
tr479:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st355;
st355:
	if ( ++p == pe )
		goto _test_eof355;
case 355:
#line 7416 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 101: goto tr480;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr474;
tr480:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st356;
st356:
	if ( ++p == pe )
		goto _test_eof356;
case 356:
#line 7434 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 101: goto tr481;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr474;
tr481:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st357;
st357:
	if ( ++p == pe )
		goto _test_eof357;
case 357:
#line 7452 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 68: goto tr482;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr474;
tr482:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st358;
st358:
	if ( ++p == pe )
		goto _test_eof358;
case 358:
#line 7470 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 66: goto st359;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr474;
st359:
	if ( ++p == pe )
		goto _test_eof359;
case 359:
	if ( (*p) == 61 )
		goto tr484;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr474;
tr484:
#line 131 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "pedigreeDB");
    }
	goto st360;
st360:
	if ( ++p == pe )
		goto _test_eof360;
case 360:
#line 7497 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 60 )
		goto st361;
	goto tr474;
st361:
	if ( ++p == pe )
		goto _test_eof361;
case 361:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr487;
	} else if ( (*p) >= 65 )
		goto tr487;
	goto tr486;
tr487:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st362;
st362:
	if ( ++p == pe )
		goto _test_eof362;
case 362:
#line 7521 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 10: goto tr486;
		case 35: goto tr486;
		case 47: goto tr486;
		case 58: goto tr486;
		case 63: goto tr486;
	}
	goto st363;
st363:
	if ( ++p == pe )
		goto _test_eof363;
case 363:
	switch( (*p) ) {
		case 10: goto tr486;
		case 35: goto tr486;
		case 47: goto tr486;
		case 58: goto st364;
		case 63: goto tr486;
	}
	goto st363;
st364:
	if ( ++p == pe )
		goto _test_eof364;
case 364:
	if ( (*p) == 47 )
		goto st365;
	goto tr486;
st365:
	if ( ++p == pe )
		goto _test_eof365;
case 365:
	if ( (*p) == 47 )
		goto st366;
	goto tr486;
st366:
	if ( ++p == pe )
		goto _test_eof366;
case 366:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr492;
	} else if ( (*p) >= 65 )
		goto tr492;
	goto tr486;
tr492:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st367;
st367:
	if ( ++p == pe )
		goto _test_eof367;
case 367:
#line 7576 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 10: goto tr486;
		case 62: goto tr493;
	}
	goto tr492;
tr493:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st368;
st368:
	if ( ++p == pe )
		goto _test_eof368;
case 368:
#line 7596 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 10: goto tr52;
		case 62: goto tr493;
	}
	goto tr492;
st369:
	if ( ++p == pe )
		goto _test_eof369;
case 369:
	if ( (*p) == 72 )
		goto st370;
	goto tr494;
st370:
	if ( ++p == pe )
		goto _test_eof370;
case 370:
	if ( (*p) == 82 )
		goto st371;
	goto tr494;
st371:
	if ( ++p == pe )
		goto _test_eof371;
case 371:
	if ( (*p) == 79 )
		goto st372;
	goto tr494;
st372:
	if ( ++p == pe )
		goto _test_eof372;
case 372:
	if ( (*p) == 77 )
		goto st373;
	goto tr494;
st373:
	if ( ++p == pe )
		goto _test_eof373;
case 373:
	if ( (*p) == 9 )
		goto st374;
	goto tr494;
st374:
	if ( ++p == pe )
		goto _test_eof374;
case 374:
	if ( (*p) == 80 )
		goto st375;
	goto tr494;
st375:
	if ( ++p == pe )
		goto _test_eof375;
case 375:
	if ( (*p) == 79 )
		goto st376;
	goto tr494;
st376:
	if ( ++p == pe )
		goto _test_eof376;
case 376:
	if ( (*p) == 83 )
		goto st377;
	goto tr494;
st377:
	if ( ++p == pe )
		goto _test_eof377;
case 377:
	if ( (*p) == 9 )
		goto st378;
	goto tr494;
st378:
	if ( ++p == pe )
		goto _test_eof378;
case 378:
	if ( (*p) == 73 )
		goto st379;
	goto tr494;
st379:
	if ( ++p == pe )
		goto _test_eof379;
case 379:
	if ( (*p) == 68 )
		goto st380;
	goto tr494;
st380:
	if ( ++p == pe )
		goto _test_eof380;
case 380:
	if ( (*p) == 9 )
		goto st381;
	goto tr494;
st381:
	if ( ++p == pe )
		goto _test_eof381;
case 381:
	if ( (*p) == 82 )
		goto st382;
	goto tr494;
st382:
	if ( ++p == pe )
		goto _test_eof382;
case 382:
	if ( (*p) == 69 )
		goto st383;
	goto tr494;
st383:
	if ( ++p == pe )
		goto _test_eof383;
case 383:
	if ( (*p) == 70 )
		goto st384;
	goto tr494;
st384:
	if ( ++p == pe )
		goto _test_eof384;
case 384:
	if ( (*p) == 9 )
		goto st385;
	goto tr494;
st385:
	if ( ++p == pe )
		goto _test_eof385;
case 385:
	if ( (*p) == 65 )
		goto st386;
	goto tr494;
st386:
	if ( ++p == pe )
		goto _test_eof386;
case 386:
	if ( (*p) == 76 )
		goto st387;
	goto tr494;
st387:
	if ( ++p == pe )
		goto _test_eof387;
case 387:
	if ( (*p) == 84 )
		goto st388;
	goto tr494;
st388:
	if ( ++p == pe )
		goto _test_eof388;
case 388:
	if ( (*p) == 9 )
		goto st389;
	goto tr494;
st389:
	if ( ++p == pe )
		goto _test_eof389;
case 389:
	if ( (*p) == 81 )
		goto st390;
	goto tr494;
st390:
	if ( ++p == pe )
		goto _test_eof390;
case 390:
	if ( (*p) == 85 )
		goto st391;
	goto tr494;
st391:
	if ( ++p == pe )
		goto _test_eof391;
case 391:
	if ( (*p) == 65 )
		goto st392;
	goto tr494;
st392:
	if ( ++p == pe )
		goto _test_eof392;
case 392:
	if ( (*p) == 76 )
		goto st393;
	goto tr494;
st393:
	if ( ++p == pe )
		goto _test_eof393;
case 393:
	if ( (*p) == 9 )
		goto st394;
	goto tr494;
st394:
	if ( ++p == pe )
		goto _test_eof394;
case 394:
	if ( (*p) == 70 )
		goto st395;
	goto tr494;
st395:
	if ( ++p == pe )
		goto _test_eof395;
case 395:
	if ( (*p) == 73 )
		goto st396;
	goto tr494;
st396:
	if ( ++p == pe )
		goto _test_eof396;
case 396:
	if ( (*p) == 76 )
		goto st397;
	goto tr494;
st397:
	if ( ++p == pe )
		goto _test_eof397;
case 397:
	if ( (*p) == 84 )
		goto st398;
	goto tr494;
st398:
	if ( ++p == pe )
		goto _test_eof398;
case 398:
	if ( (*p) == 69 )
		goto st399;
	goto tr494;
st399:
	if ( ++p == pe )
		goto _test_eof399;
case 399:
	if ( (*p) == 82 )
		goto st400;
	goto tr494;
st400:
	if ( ++p == pe )
		goto _test_eof400;
case 400:
	if ( (*p) == 9 )
		goto st401;
	goto tr494;
st401:
	if ( ++p == pe )
		goto _test_eof401;
case 401:
	if ( (*p) == 73 )
		goto st402;
	goto tr494;
st402:
	if ( ++p == pe )
		goto _test_eof402;
case 402:
	if ( (*p) == 78 )
		goto st403;
	goto tr494;
st403:
	if ( ++p == pe )
		goto _test_eof403;
case 403:
	if ( (*p) == 70 )
		goto st404;
	goto tr494;
st404:
	if ( ++p == pe )
		goto _test_eof404;
case 404:
	if ( (*p) == 79 )
		goto st405;
	goto tr494;
st405:
	if ( ++p == pe )
		goto _test_eof405;
case 405:
	switch( (*p) ) {
		case 9: goto st406;
		case 10: goto tr532;
	}
	goto tr494;
st406:
	if ( ++p == pe )
		goto _test_eof406;
case 406:
	if ( (*p) == 70 )
		goto st407;
	goto tr533;
st407:
	if ( ++p == pe )
		goto _test_eof407;
case 407:
	if ( (*p) == 79 )
		goto st408;
	goto tr533;
st408:
	if ( ++p == pe )
		goto _test_eof408;
case 408:
	if ( (*p) == 82 )
		goto st409;
	goto tr533;
st409:
	if ( ++p == pe )
		goto _test_eof409;
case 409:
	if ( (*p) == 77 )
		goto st410;
	goto tr533;
st410:
	if ( ++p == pe )
		goto _test_eof410;
case 410:
	if ( (*p) == 65 )
		goto st411;
	goto tr533;
st411:
	if ( ++p == pe )
		goto _test_eof411;
case 411:
	if ( (*p) == 84 )
		goto st412;
	goto tr533;
st412:
	if ( ++p == pe )
		goto _test_eof412;
case 412:
	if ( (*p) == 9 )
		goto st413;
	goto tr533;
tr542:
#line 179 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_sample_name(*this);
    }
	goto st413;
st413:
	if ( ++p == pe )
		goto _test_eof413;
case 413:
#line 7922 "inc/vcf/validator_detail_v41.hpp"
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr541;
	goto tr533;
tr544:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st414;
tr541:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st414;
st414:
	if ( ++p == pe )
		goto _test_eof414;
case 414:
#line 7946 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr544;
	goto tr533;
tr532:
#line 183 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_header_line(*this);
    }
#line 43 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st658;
tr543:
#line 179 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_sample_name(*this);
    }
#line 183 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_header_line(*this);
    }
#line 43 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st658;
st658:
	if ( ++p == pe )
		goto _test_eof658;
case 658:
#line 7994 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 60 )
		goto tr846;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr845;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr845;
	} else
		goto tr845;
	goto tr844;
tr847:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st415;
tr845:
#line 70 "src/vcf/vcf_v41.ragel"
	{
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (ParsingWarning warn) {
          ErrorPolicy::handle_meta_section_warning(*this, warn.what());
        }
    }
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st415;
st415:
	if ( ++p == pe )
		goto _test_eof415;
case 415:
#line 8038 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr546;
		case 59: goto tr547;
		case 61: goto tr547;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr547;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr547;
		} else
			goto tr548;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr547;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr547;
		} else
			goto tr548;
	} else
		goto tr548;
	goto tr545;
tr546:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 189 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 53 "src/vcf/vcf_v41.ragel"
	{
        ++n_columns;
    }
	goto st416;
tr627:
#line 189 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 53 "src/vcf/vcf_v41.ragel"
	{
        ++n_columns;
    }
	goto st416;
st416:
	if ( ++p == pe )
		goto _test_eof416;
case 416:
#line 8093 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 43: goto tr550;
		case 45: goto tr550;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr551;
	goto tr549;
tr550:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st417;
st417:
	if ( ++p == pe )
		goto _test_eof417;
case 417:
#line 8111 "inc/vcf/validator_detail_v41.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr552;
	goto tr549;
tr552:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st418;
tr551:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st418;
st418:
	if ( ++p == pe )
		goto _test_eof418;
case 418:
#line 8135 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 9 )
		goto tr553;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr552;
	goto tr549;
tr558:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st419;
tr553:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 189 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 53 "src/vcf/vcf_v41.ragel"
	{
        ++n_columns;
    }
	goto st419;
st419:
	if ( ++p == pe )
		goto _test_eof419;
case 419:
#line 8165 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr555;
	} else if ( (*p) >= 33 )
		goto tr555;
	goto tr554;
tr557:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st420;
tr555:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st420;
st420:
	if ( ++p == pe )
		goto _test_eof420;
case 420:
#line 8192 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr556;
		case 59: goto tr558;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr557;
	goto tr554;
tr556:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 189 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 53 "src/vcf/vcf_v41.ragel"
	{
        ++n_columns;
    }
	goto st421;
st421:
	if ( ++p == pe )
		goto _test_eof421;
case 421:
#line 8218 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 65: goto tr560;
		case 67: goto tr560;
		case 71: goto tr560;
		case 78: goto tr560;
		case 84: goto tr560;
		case 97: goto tr560;
		case 99: goto tr560;
		case 103: goto tr560;
		case 110: goto tr560;
		case 116: goto tr560;
	}
	goto tr559;
tr562:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st422;
tr560:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st422;
st422:
	if ( ++p == pe )
		goto _test_eof422;
case 422:
#line 8252 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr561;
		case 65: goto tr562;
		case 67: goto tr562;
		case 71: goto tr562;
		case 78: goto tr562;
		case 84: goto tr562;
		case 97: goto tr562;
		case 99: goto tr562;
		case 103: goto tr562;
		case 110: goto tr562;
		case 116: goto tr562;
	}
	goto tr559;
tr561:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 189 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 53 "src/vcf/vcf_v41.ragel"
	{
        ++n_columns;
    }
	goto st423;
st423:
	if ( ++p == pe )
		goto _test_eof423;
case 423:
#line 8285 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 42: goto tr564;
		case 46: goto tr565;
		case 60: goto tr566;
		case 65: goto tr567;
		case 67: goto tr567;
		case 71: goto tr567;
		case 78: goto tr567;
		case 84: goto tr567;
		case 91: goto tr568;
		case 93: goto tr569;
		case 97: goto tr567;
		case 99: goto tr567;
		case 103: goto tr567;
		case 110: goto tr567;
		case 116: goto tr567;
	}
	goto tr563;
tr791:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st424;
tr564:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st424;
st424:
	if ( ++p == pe )
		goto _test_eof424;
case 424:
#line 8324 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr570;
		case 44: goto tr571;
	}
	goto tr563;
tr570:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 189 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 53 "src/vcf/vcf_v41.ragel"
	{
        ++n_columns;
    }
	goto st425;
st425:
	if ( ++p == pe )
		goto _test_eof425;
case 425:
#line 8348 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 43: goto tr573;
		case 45: goto tr573;
		case 46: goto tr574;
		case 73: goto tr576;
		case 78: goto tr577;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr575;
	goto tr572;
tr573:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st426;
st426:
	if ( ++p == pe )
		goto _test_eof426;
case 426:
#line 8373 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 46: goto tr578;
		case 73: goto tr580;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr579;
	goto tr572;
tr578:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st427;
st427:
	if ( ++p == pe )
		goto _test_eof427;
case 427:
#line 8391 "inc/vcf/validator_detail_v41.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr581;
	goto tr572;
tr581:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st428;
st428:
	if ( ++p == pe )
		goto _test_eof428;
case 428:
#line 8405 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr582;
		case 69: goto tr583;
		case 101: goto tr583;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr581;
	goto tr572;
tr582:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 189 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 53 "src/vcf/vcf_v41.ragel"
	{
        ++n_columns;
    }
	goto st429;
st429:
	if ( ++p == pe )
		goto _test_eof429;
case 429:
#line 8432 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 46: goto tr586;
		case 58: goto tr585;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr585;
		} else if ( (*p) > 57 ) {
			if ( 60 <= (*p) && (*p) <= 64 )
				goto tr585;
		} else
			goto tr587;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr585;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr585;
		} else
			goto tr587;
	} else
		goto tr587;
	goto tr584;
tr585:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st430;
st430:
	if ( ++p == pe )
		goto _test_eof430;
case 430:
#line 8468 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 58 )
		goto st430;
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto st430;
		} else if ( (*p) > 57 ) {
			if ( 60 <= (*p) && (*p) <= 64 )
				goto st430;
		} else
			goto tr589;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st430;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st430;
		} else
			goto tr589;
	} else
		goto tr589;
	goto tr584;
tr589:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st431;
tr587:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st431;
st431:
	if ( ++p == pe )
		goto _test_eof431;
case 431:
#line 8512 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr590;
		case 59: goto tr591;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr589;
	goto tr584;
tr590:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 189 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 53 "src/vcf/vcf_v41.ragel"
	{
        ++n_columns;
    }
	goto st432;
st432:
	if ( ++p == pe )
		goto _test_eof432;
case 432:
#line 8538 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 46: goto tr594;
		case 49: goto tr596;
		case 58: goto tr593;
		case 60: goto tr593;
		case 65: goto tr597;
		case 66: goto tr598;
		case 67: goto tr599;
		case 68: goto tr600;
		case 69: goto tr601;
		case 72: goto tr602;
		case 77: goto tr603;
		case 78: goto tr604;
		case 83: goto tr605;
		case 86: goto tr606;
	}
	if ( (*p) < 70 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr593;
		} else if ( (*p) > 57 ) {
			if ( 62 <= (*p) && (*p) <= 64 )
				goto tr593;
		} else
			goto tr595;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr593;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr593;
		} else
			goto tr595;
	} else
		goto tr595;
	goto tr592;
tr607:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st433;
tr593:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st433;
st433:
	if ( ++p == pe )
		goto _test_eof433;
case 433:
#line 8596 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 58: goto tr607;
		case 60: goto tr607;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr607;
		} else if ( (*p) > 57 ) {
			if ( 62 <= (*p) && (*p) <= 64 )
				goto tr607;
		} else
			goto tr608;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr607;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr607;
		} else
			goto tr608;
	} else
		goto tr608;
	goto tr592;
tr608:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st434;
tr595:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st434;
st434:
	if ( ++p == pe )
		goto _test_eof434;
case 434:
#line 8642 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr609;
		case 10: goto tr610;
		case 59: goto tr611;
		case 61: goto tr612;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr608;
	goto tr592;
tr617:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st435;
tr609:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 189 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 53 "src/vcf/vcf_v41.ragel"
	{
        ++n_columns;
    }
	goto st435;
st435:
	if ( ++p == pe )
		goto _test_eof435;
case 435:
#line 8676 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 95 )
		goto tr614;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr614;
	} else if ( (*p) >= 65 )
		goto tr614;
	goto tr613;
tr616:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st436;
tr614:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st436;
st436:
	if ( ++p == pe )
		goto _test_eof436;
case 436:
#line 8705 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr615;
		case 46: goto tr616;
		case 58: goto tr617;
		case 95: goto tr616;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr616;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr616;
	} else
		goto tr616;
	goto tr613;
tr615:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 189 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 53 "src/vcf/vcf_v41.ragel"
	{
        ++n_columns;
    }
	goto st437;
st437:
	if ( ++p == pe )
		goto _test_eof437;
case 437:
#line 8739 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 46 )
		goto tr619;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr620;
	goto tr618;
tr628:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st438;
tr619:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st438;
st438:
	if ( ++p == pe )
		goto _test_eof438;
case 438:
#line 8765 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr615;
		case 10: goto tr610;
		case 47: goto tr621;
		case 58: goto tr622;
		case 124: goto tr621;
	}
	goto tr618;
tr610:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 189 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 193 "src/vcf/vcf_v41.ragel"
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
#line 43 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st659;
st659:
	if ( ++p == pe )
		goto _test_eof659;
case 659:
#line 8811 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 60 )
		goto st439;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr847;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr847;
	} else
		goto tr847;
	goto tr545;
tr846:
#line 70 "src/vcf/vcf_v41.ragel"
	{
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (ParsingWarning warn) {
          ErrorPolicy::handle_meta_section_warning(*this, warn.what());
        }
    }
	goto st439;
st439:
	if ( ++p == pe )
		goto _test_eof439;
case 439:
#line 8837 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr623;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr623;
	} else
		goto tr623;
	goto tr545;
tr623:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st440;
st440:
	if ( ++p == pe )
		goto _test_eof440;
case 440:
#line 8861 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 59: goto tr624;
		case 62: goto tr626;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr624;
		} else if ( (*p) > 57 ) {
			if ( 61 <= (*p) && (*p) <= 64 )
				goto tr624;
		} else
			goto tr625;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr624;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr624;
		} else
			goto tr625;
	} else
		goto tr625;
	goto tr545;
tr624:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st441;
st441:
	if ( ++p == pe )
		goto _test_eof441;
case 441:
#line 8897 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 59: goto tr624;
		case 61: goto tr624;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr624;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr624;
		} else
			goto tr625;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr624;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr624;
		} else
			goto tr625;
	} else
		goto tr625;
	goto tr545;
tr625:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st442;
st442:
	if ( ++p == pe )
		goto _test_eof442;
case 442:
#line 8933 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 59: goto tr625;
		case 62: goto tr626;
	}
	if ( (*p) > 57 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr625;
	} else if ( (*p) >= 33 )
		goto tr625;
	goto tr545;
tr626:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st443;
st443:
	if ( ++p == pe )
		goto _test_eof443;
case 443:
#line 8954 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 9 )
		goto tr627;
	goto tr545;
tr621:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st444;
st444:
	if ( ++p == pe )
		goto _test_eof444;
case 444:
#line 8968 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 46 )
		goto tr628;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr629;
	goto tr618;
tr629:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st445;
tr620:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st445;
st445:
	if ( ++p == pe )
		goto _test_eof445;
case 445:
#line 8994 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr615;
		case 10: goto tr610;
		case 47: goto tr621;
		case 58: goto tr622;
		case 124: goto tr621;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr629;
	goto tr618;
tr622:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st446;
st446:
	if ( ++p == pe )
		goto _test_eof446;
case 446:
#line 9015 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) > 57 ) {
		if ( 59 <= (*p) && (*p) <= 126 )
			goto tr631;
	} else if ( (*p) >= 33 )
		goto tr631;
	goto tr630;
tr631:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st447;
st447:
	if ( ++p == pe )
		goto _test_eof447;
case 447:
#line 9032 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr615;
		case 10: goto tr610;
		case 58: goto tr622;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr631;
	goto tr630;
tr611:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st448;
st448:
	if ( ++p == pe )
		goto _test_eof448;
case 448:
#line 9051 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 49: goto tr596;
		case 58: goto tr593;
		case 60: goto tr593;
		case 65: goto tr597;
		case 66: goto tr598;
		case 67: goto tr599;
		case 68: goto tr600;
		case 69: goto tr601;
		case 72: goto tr602;
		case 77: goto tr603;
		case 78: goto tr604;
		case 83: goto tr605;
		case 86: goto tr606;
	}
	if ( (*p) < 70 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr593;
		} else if ( (*p) > 57 ) {
			if ( 62 <= (*p) && (*p) <= 64 )
				goto tr593;
		} else
			goto tr595;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr593;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr593;
		} else
			goto tr595;
	} else
		goto tr595;
	goto tr592;
tr596:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st449;
st449:
	if ( ++p == pe )
		goto _test_eof449;
case 449:
#line 9102 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr609;
		case 10: goto tr610;
		case 48: goto tr632;
		case 59: goto tr611;
		case 61: goto tr612;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr608;
	goto tr592;
tr632:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st450;
st450:
	if ( ++p == pe )
		goto _test_eof450;
case 450:
#line 9123 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr609;
		case 10: goto tr610;
		case 48: goto tr633;
		case 59: goto tr611;
		case 61: goto tr612;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr608;
	goto tr592;
tr633:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st451;
st451:
	if ( ++p == pe )
		goto _test_eof451;
case 451:
#line 9144 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr609;
		case 10: goto tr610;
		case 48: goto tr634;
		case 59: goto tr611;
		case 61: goto tr612;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr608;
	goto tr592;
tr634:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st452;
st452:
	if ( ++p == pe )
		goto _test_eof452;
case 452:
#line 9165 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr609;
		case 10: goto tr610;
		case 59: goto tr611;
		case 61: goto tr612;
		case 71: goto tr635;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr608;
	goto tr592;
tr612:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st453;
st453:
	if ( ++p == pe )
		goto _test_eof453;
case 453:
#line 9186 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr637;
	} else if ( (*p) >= 33 )
		goto tr637;
	goto tr636;
tr637:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st454;
st454:
	if ( ++p == pe )
		goto _test_eof454;
case 454:
#line 9203 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr609;
		case 10: goto tr610;
		case 59: goto tr611;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr637;
	goto tr636;
tr635:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st455;
st455:
	if ( ++p == pe )
		goto _test_eof455;
case 455:
#line 9222 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr609;
		case 10: goto tr610;
		case 59: goto tr611;
		case 61: goto tr639;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr608;
	goto tr638;
tr639:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st456;
st456:
	if ( ++p == pe )
		goto _test_eof456;
case 456:
#line 9242 "inc/vcf/validator_detail_v41.hpp"
	if ( 48 <= (*p) && (*p) <= 49 )
		goto tr641;
	goto tr640;
tr641:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st457;
st457:
	if ( ++p == pe )
		goto _test_eof457;
case 457:
#line 9256 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr609;
		case 10: goto tr610;
		case 59: goto tr611;
	}
	goto tr640;
tr597:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st458;
st458:
	if ( ++p == pe )
		goto _test_eof458;
case 458:
#line 9277 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr609;
		case 10: goto tr610;
		case 59: goto tr611;
		case 61: goto tr612;
		case 65: goto tr642;
		case 67: goto tr643;
		case 70: goto tr644;
		case 78: goto tr645;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr608;
	goto tr592;
tr642:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st459;
st459:
	if ( ++p == pe )
		goto _test_eof459;
case 459:
#line 9301 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 61 )
		goto tr646;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr608;
	} else if ( (*p) >= 33 )
		goto tr608;
	goto tr592;
tr646:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st460;
st460:
	if ( ++p == pe )
		goto _test_eof460;
case 460:
#line 9320 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 65: goto tr649;
		case 67: goto tr649;
		case 71: goto tr649;
		case 78: goto tr649;
		case 84: goto tr649;
		case 97: goto tr649;
		case 99: goto tr649;
		case 103: goto tr649;
		case 110: goto tr649;
		case 116: goto tr649;
	}
	if ( 45 <= (*p) && (*p) <= 46 )
		goto tr648;
	goto tr647;
tr648:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st461;
st461:
	if ( ++p == pe )
		goto _test_eof461;
case 461:
#line 9346 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr609;
		case 10: goto tr610;
		case 59: goto tr611;
	}
	goto tr647;
tr649:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st462;
st462:
	if ( ++p == pe )
		goto _test_eof462;
case 462:
#line 9363 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr609;
		case 10: goto tr610;
		case 59: goto tr611;
		case 65: goto tr649;
		case 67: goto tr649;
		case 71: goto tr649;
		case 78: goto tr649;
		case 84: goto tr649;
		case 97: goto tr649;
		case 99: goto tr649;
		case 103: goto tr649;
		case 110: goto tr649;
		case 116: goto tr649;
	}
	goto tr647;
tr643:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st463;
st463:
	if ( ++p == pe )
		goto _test_eof463;
case 463:
#line 9390 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 61 )
		goto tr650;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr608;
	} else if ( (*p) >= 33 )
		goto tr608;
	goto tr592;
tr650:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st464;
st464:
	if ( ++p == pe )
		goto _test_eof464;
case 464:
#line 9409 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 43: goto tr652;
		case 45: goto tr652;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr653;
	goto tr651;
tr652:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st465;
st465:
	if ( ++p == pe )
		goto _test_eof465;
case 465:
#line 9427 "inc/vcf/validator_detail_v41.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr653;
	goto tr651;
tr653:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st466;
st466:
	if ( ++p == pe )
		goto _test_eof466;
case 466:
#line 9441 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr609;
		case 10: goto tr610;
		case 44: goto tr650;
		case 59: goto tr611;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr653;
	goto tr651;
tr644:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st467;
st467:
	if ( ++p == pe )
		goto _test_eof467;
case 467:
#line 9461 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 61 )
		goto tr654;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr608;
	} else if ( (*p) >= 33 )
		goto tr608;
	goto tr592;
tr654:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st468;
st468:
	if ( ++p == pe )
		goto _test_eof468;
case 468:
#line 9480 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 43: goto tr656;
		case 45: goto tr656;
		case 46: goto tr657;
		case 73: goto tr659;
		case 78: goto tr660;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr658;
	goto tr655;
tr656:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st469;
st469:
	if ( ++p == pe )
		goto _test_eof469;
case 469:
#line 9501 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 46: goto tr657;
		case 73: goto tr659;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr658;
	goto tr655;
tr657:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st470;
st470:
	if ( ++p == pe )
		goto _test_eof470;
case 470:
#line 9519 "inc/vcf/validator_detail_v41.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr661;
	goto tr655;
tr661:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st471;
st471:
	if ( ++p == pe )
		goto _test_eof471;
case 471:
#line 9533 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr609;
		case 10: goto tr610;
		case 44: goto tr654;
		case 59: goto tr611;
		case 69: goto tr662;
		case 101: goto tr662;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr661;
	goto tr655;
tr662:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st472;
st472:
	if ( ++p == pe )
		goto _test_eof472;
case 472:
#line 9555 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 43: goto tr663;
		case 45: goto tr663;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr664;
	goto tr655;
tr663:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st473;
st473:
	if ( ++p == pe )
		goto _test_eof473;
case 473:
#line 9573 "inc/vcf/validator_detail_v41.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr664;
	goto tr655;
tr664:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st474;
st474:
	if ( ++p == pe )
		goto _test_eof474;
case 474:
#line 9587 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr609;
		case 10: goto tr610;
		case 44: goto tr654;
		case 59: goto tr611;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr664;
	goto tr655;
tr658:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st475;
st475:
	if ( ++p == pe )
		goto _test_eof475;
case 475:
#line 9607 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr609;
		case 10: goto tr610;
		case 44: goto tr654;
		case 46: goto tr657;
		case 59: goto tr611;
		case 69: goto tr662;
		case 101: goto tr662;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr658;
	goto tr655;
tr659:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st476;
st476:
	if ( ++p == pe )
		goto _test_eof476;
case 476:
#line 9630 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 110 )
		goto tr665;
	goto tr655;
tr665:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st477;
st477:
	if ( ++p == pe )
		goto _test_eof477;
case 477:
#line 9644 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 102 )
		goto tr666;
	goto tr655;
tr666:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st478;
st478:
	if ( ++p == pe )
		goto _test_eof478;
case 478:
#line 9658 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr609;
		case 10: goto tr610;
		case 44: goto tr654;
		case 59: goto tr611;
	}
	goto tr655;
tr660:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st479;
st479:
	if ( ++p == pe )
		goto _test_eof479;
case 479:
#line 9676 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 97 )
		goto tr667;
	goto tr655;
tr667:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st480;
st480:
	if ( ++p == pe )
		goto _test_eof480;
case 480:
#line 9690 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 78 )
		goto tr666;
	goto tr655;
tr645:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st481;
st481:
	if ( ++p == pe )
		goto _test_eof481;
case 481:
#line 9704 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 61 )
		goto tr668;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr608;
	} else if ( (*p) >= 33 )
		goto tr608;
	goto tr592;
tr668:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st482;
st482:
	if ( ++p == pe )
		goto _test_eof482;
case 482:
#line 9723 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 43: goto tr670;
		case 45: goto tr670;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr671;
	goto tr669;
tr670:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st483;
st483:
	if ( ++p == pe )
		goto _test_eof483;
case 483:
#line 9741 "inc/vcf/validator_detail_v41.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr671;
	goto tr669;
tr671:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st484;
st484:
	if ( ++p == pe )
		goto _test_eof484;
case 484:
#line 9755 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr609;
		case 10: goto tr610;
		case 59: goto tr611;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr671;
	goto tr669;
tr598:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st485;
st485:
	if ( ++p == pe )
		goto _test_eof485;
case 485:
#line 9778 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr609;
		case 10: goto tr610;
		case 59: goto tr611;
		case 61: goto tr612;
		case 81: goto tr672;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr608;
	goto tr592;
tr672:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st486;
st486:
	if ( ++p == pe )
		goto _test_eof486;
case 486:
#line 9799 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 61 )
		goto tr673;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr608;
	} else if ( (*p) >= 33 )
		goto tr608;
	goto tr592;
tr673:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st487;
st487:
	if ( ++p == pe )
		goto _test_eof487;
case 487:
#line 9818 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 43: goto tr675;
		case 45: goto tr675;
		case 46: goto tr676;
		case 73: goto tr678;
		case 78: goto tr679;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr677;
	goto tr674;
tr675:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st488;
st488:
	if ( ++p == pe )
		goto _test_eof488;
case 488:
#line 9839 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 46: goto tr676;
		case 73: goto tr678;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr677;
	goto tr674;
tr676:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st489;
st489:
	if ( ++p == pe )
		goto _test_eof489;
case 489:
#line 9857 "inc/vcf/validator_detail_v41.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr680;
	goto tr674;
tr680:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st490;
st490:
	if ( ++p == pe )
		goto _test_eof490;
case 490:
#line 9871 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr609;
		case 10: goto tr610;
		case 59: goto tr611;
		case 69: goto tr681;
		case 101: goto tr681;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr680;
	goto tr674;
tr681:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st491;
st491:
	if ( ++p == pe )
		goto _test_eof491;
case 491:
#line 9892 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 43: goto tr682;
		case 45: goto tr682;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr683;
	goto tr674;
tr682:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st492;
st492:
	if ( ++p == pe )
		goto _test_eof492;
case 492:
#line 9910 "inc/vcf/validator_detail_v41.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr683;
	goto tr674;
tr683:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st493;
st493:
	if ( ++p == pe )
		goto _test_eof493;
case 493:
#line 9924 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr609;
		case 10: goto tr610;
		case 59: goto tr611;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr683;
	goto tr674;
tr677:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st494;
st494:
	if ( ++p == pe )
		goto _test_eof494;
case 494:
#line 9943 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr609;
		case 10: goto tr610;
		case 46: goto tr676;
		case 59: goto tr611;
		case 69: goto tr681;
		case 101: goto tr681;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr677;
	goto tr674;
tr678:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st495;
st495:
	if ( ++p == pe )
		goto _test_eof495;
case 495:
#line 9965 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 110 )
		goto tr684;
	goto tr674;
tr684:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st496;
st496:
	if ( ++p == pe )
		goto _test_eof496;
case 496:
#line 9979 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 102 )
		goto tr685;
	goto tr674;
tr685:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st497;
st497:
	if ( ++p == pe )
		goto _test_eof497;
case 497:
#line 9993 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr609;
		case 10: goto tr610;
		case 59: goto tr611;
	}
	goto tr674;
tr679:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st498;
st498:
	if ( ++p == pe )
		goto _test_eof498;
case 498:
#line 10010 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 97 )
		goto tr686;
	goto tr674;
tr686:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st499;
st499:
	if ( ++p == pe )
		goto _test_eof499;
case 499:
#line 10024 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 78 )
		goto tr685;
	goto tr674;
tr599:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st500;
st500:
	if ( ++p == pe )
		goto _test_eof500;
case 500:
#line 10042 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr609;
		case 10: goto tr610;
		case 59: goto tr611;
		case 61: goto tr612;
		case 73: goto tr687;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr608;
	goto tr592;
tr687:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st501;
st501:
	if ( ++p == pe )
		goto _test_eof501;
case 501:
#line 10063 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr609;
		case 10: goto tr610;
		case 59: goto tr611;
		case 61: goto tr612;
		case 71: goto tr688;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr608;
	goto tr592;
tr688:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st502;
st502:
	if ( ++p == pe )
		goto _test_eof502;
case 502:
#line 10084 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr609;
		case 10: goto tr610;
		case 59: goto tr611;
		case 61: goto tr612;
		case 65: goto tr689;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr608;
	goto tr592;
tr689:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st503;
st503:
	if ( ++p == pe )
		goto _test_eof503;
case 503:
#line 10105 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr609;
		case 10: goto tr610;
		case 59: goto tr611;
		case 61: goto tr612;
		case 82: goto tr690;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr608;
	goto tr592;
tr690:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st504;
st504:
	if ( ++p == pe )
		goto _test_eof504;
case 504:
#line 10126 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 61 )
		goto tr691;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr608;
	} else if ( (*p) >= 33 )
		goto tr608;
	goto tr592;
tr691:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st505;
st505:
	if ( ++p == pe )
		goto _test_eof505;
case 505:
#line 10145 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr693;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr693;
	} else
		goto tr693;
	goto tr692;
tr693:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st506;
st506:
	if ( ++p == pe )
		goto _test_eof506;
case 506:
#line 10165 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr609;
		case 10: goto tr610;
		case 59: goto tr611;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr693;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr693;
	} else
		goto tr693;
	goto tr692;
tr600:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st507;
st507:
	if ( ++p == pe )
		goto _test_eof507;
case 507:
#line 10194 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr609;
		case 10: goto tr610;
		case 59: goto tr611;
		case 61: goto tr612;
		case 66: goto tr694;
		case 80: goto tr695;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr608;
	goto tr592;
tr694:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st508;
st508:
	if ( ++p == pe )
		goto _test_eof508;
case 508:
#line 10216 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr609;
		case 10: goto tr610;
		case 59: goto tr611;
		case 61: goto tr697;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr608;
	goto tr696;
tr697:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st509;
st509:
	if ( ++p == pe )
		goto _test_eof509;
case 509:
#line 10236 "inc/vcf/validator_detail_v41.hpp"
	if ( 48 <= (*p) && (*p) <= 49 )
		goto tr699;
	goto tr698;
tr699:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st510;
st510:
	if ( ++p == pe )
		goto _test_eof510;
case 510:
#line 10250 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr609;
		case 10: goto tr610;
		case 59: goto tr611;
	}
	goto tr698;
tr695:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st511;
st511:
	if ( ++p == pe )
		goto _test_eof511;
case 511:
#line 10267 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 61 )
		goto tr700;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr608;
	} else if ( (*p) >= 33 )
		goto tr608;
	goto tr592;
tr700:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st512;
st512:
	if ( ++p == pe )
		goto _test_eof512;
case 512:
#line 10286 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 43: goto tr702;
		case 45: goto tr702;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr703;
	goto tr701;
tr702:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st513;
st513:
	if ( ++p == pe )
		goto _test_eof513;
case 513:
#line 10304 "inc/vcf/validator_detail_v41.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr703;
	goto tr701;
tr703:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st514;
st514:
	if ( ++p == pe )
		goto _test_eof514;
case 514:
#line 10318 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr609;
		case 10: goto tr610;
		case 59: goto tr611;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr703;
	goto tr701;
tr601:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st515;
st515:
	if ( ++p == pe )
		goto _test_eof515;
case 515:
#line 10341 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr609;
		case 10: goto tr610;
		case 59: goto tr611;
		case 61: goto tr612;
		case 78: goto tr704;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr608;
	goto tr592;
tr704:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st516;
st516:
	if ( ++p == pe )
		goto _test_eof516;
case 516:
#line 10362 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr609;
		case 10: goto tr610;
		case 59: goto tr611;
		case 61: goto tr612;
		case 68: goto tr705;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr608;
	goto tr592;
tr705:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st517;
st517:
	if ( ++p == pe )
		goto _test_eof517;
case 517:
#line 10383 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 61 )
		goto tr706;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr608;
	} else if ( (*p) >= 33 )
		goto tr608;
	goto tr592;
tr706:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st518;
st518:
	if ( ++p == pe )
		goto _test_eof518;
case 518:
#line 10402 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 43: goto tr708;
		case 45: goto tr708;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr709;
	goto tr707;
tr708:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st519;
st519:
	if ( ++p == pe )
		goto _test_eof519;
case 519:
#line 10420 "inc/vcf/validator_detail_v41.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr709;
	goto tr707;
tr709:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st520;
st520:
	if ( ++p == pe )
		goto _test_eof520;
case 520:
#line 10434 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr609;
		case 10: goto tr610;
		case 59: goto tr611;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr709;
	goto tr707;
tr602:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st521;
st521:
	if ( ++p == pe )
		goto _test_eof521;
case 521:
#line 10457 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr609;
		case 10: goto tr610;
		case 50: goto tr710;
		case 51: goto tr711;
		case 59: goto tr611;
		case 61: goto tr612;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr608;
	goto tr592;
tr710:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st522;
st522:
	if ( ++p == pe )
		goto _test_eof522;
case 522:
#line 10479 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr609;
		case 10: goto tr610;
		case 59: goto tr611;
		case 61: goto tr713;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr608;
	goto tr712;
tr713:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st523;
st523:
	if ( ++p == pe )
		goto _test_eof523;
case 523:
#line 10499 "inc/vcf/validator_detail_v41.hpp"
	if ( 48 <= (*p) && (*p) <= 49 )
		goto tr715;
	goto tr714;
tr715:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st524;
st524:
	if ( ++p == pe )
		goto _test_eof524;
case 524:
#line 10513 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr609;
		case 10: goto tr610;
		case 59: goto tr611;
	}
	goto tr714;
tr711:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st525;
st525:
	if ( ++p == pe )
		goto _test_eof525;
case 525:
#line 10530 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr609;
		case 10: goto tr610;
		case 59: goto tr611;
		case 61: goto tr717;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr608;
	goto tr716;
tr717:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st526;
st526:
	if ( ++p == pe )
		goto _test_eof526;
case 526:
#line 10550 "inc/vcf/validator_detail_v41.hpp"
	if ( 48 <= (*p) && (*p) <= 49 )
		goto tr719;
	goto tr718;
tr719:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st527;
st527:
	if ( ++p == pe )
		goto _test_eof527;
case 527:
#line 10564 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr609;
		case 10: goto tr610;
		case 59: goto tr611;
	}
	goto tr718;
tr603:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st528;
st528:
	if ( ++p == pe )
		goto _test_eof528;
case 528:
#line 10585 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr609;
		case 10: goto tr610;
		case 59: goto tr611;
		case 61: goto tr612;
		case 81: goto tr720;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr608;
	goto tr592;
tr720:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st529;
st529:
	if ( ++p == pe )
		goto _test_eof529;
case 529:
#line 10606 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 48: goto tr721;
		case 61: goto tr722;
	}
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr608;
	} else if ( (*p) >= 33 )
		goto tr608;
	goto tr592;
tr721:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st530;
st530:
	if ( ++p == pe )
		goto _test_eof530;
case 530:
#line 10627 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 61 )
		goto tr723;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr608;
	} else if ( (*p) >= 33 )
		goto tr608;
	goto tr592;
tr723:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st531;
st531:
	if ( ++p == pe )
		goto _test_eof531;
case 531:
#line 10646 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 43: goto tr725;
		case 45: goto tr725;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr726;
	goto tr724;
tr725:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st532;
st532:
	if ( ++p == pe )
		goto _test_eof532;
case 532:
#line 10664 "inc/vcf/validator_detail_v41.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr726;
	goto tr724;
tr726:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st533;
st533:
	if ( ++p == pe )
		goto _test_eof533;
case 533:
#line 10678 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr609;
		case 10: goto tr610;
		case 59: goto tr611;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr726;
	goto tr724;
tr722:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st534;
st534:
	if ( ++p == pe )
		goto _test_eof534;
case 534:
#line 10697 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 43: goto tr728;
		case 45: goto tr728;
		case 46: goto tr729;
		case 73: goto tr731;
		case 78: goto tr732;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr730;
	goto tr727;
tr728:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st535;
st535:
	if ( ++p == pe )
		goto _test_eof535;
case 535:
#line 10718 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 46: goto tr729;
		case 73: goto tr731;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr730;
	goto tr727;
tr729:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st536;
st536:
	if ( ++p == pe )
		goto _test_eof536;
case 536:
#line 10736 "inc/vcf/validator_detail_v41.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr733;
	goto tr727;
tr733:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st537;
st537:
	if ( ++p == pe )
		goto _test_eof537;
case 537:
#line 10750 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr609;
		case 10: goto tr610;
		case 59: goto tr611;
		case 69: goto tr734;
		case 101: goto tr734;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr733;
	goto tr727;
tr734:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st538;
st538:
	if ( ++p == pe )
		goto _test_eof538;
case 538:
#line 10771 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 43: goto tr735;
		case 45: goto tr735;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr736;
	goto tr727;
tr735:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st539;
st539:
	if ( ++p == pe )
		goto _test_eof539;
case 539:
#line 10789 "inc/vcf/validator_detail_v41.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr736;
	goto tr727;
tr736:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st540;
st540:
	if ( ++p == pe )
		goto _test_eof540;
case 540:
#line 10803 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr609;
		case 10: goto tr610;
		case 59: goto tr611;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr736;
	goto tr727;
tr730:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st541;
st541:
	if ( ++p == pe )
		goto _test_eof541;
case 541:
#line 10822 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr609;
		case 10: goto tr610;
		case 46: goto tr729;
		case 59: goto tr611;
		case 69: goto tr734;
		case 101: goto tr734;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr730;
	goto tr727;
tr731:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st542;
st542:
	if ( ++p == pe )
		goto _test_eof542;
case 542:
#line 10844 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 110 )
		goto tr737;
	goto tr727;
tr737:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st543;
st543:
	if ( ++p == pe )
		goto _test_eof543;
case 543:
#line 10858 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 102 )
		goto tr738;
	goto tr727;
tr738:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st544;
st544:
	if ( ++p == pe )
		goto _test_eof544;
case 544:
#line 10872 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr609;
		case 10: goto tr610;
		case 59: goto tr611;
	}
	goto tr727;
tr732:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st545;
st545:
	if ( ++p == pe )
		goto _test_eof545;
case 545:
#line 10889 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 97 )
		goto tr739;
	goto tr727;
tr739:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st546;
st546:
	if ( ++p == pe )
		goto _test_eof546;
case 546:
#line 10903 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 78 )
		goto tr738;
	goto tr727;
tr604:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st547;
st547:
	if ( ++p == pe )
		goto _test_eof547;
case 547:
#line 10921 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr609;
		case 10: goto tr610;
		case 59: goto tr611;
		case 61: goto tr612;
		case 83: goto tr740;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr608;
	goto tr592;
tr740:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st548;
st548:
	if ( ++p == pe )
		goto _test_eof548;
case 548:
#line 10942 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 61 )
		goto tr741;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr608;
	} else if ( (*p) >= 33 )
		goto tr608;
	goto tr592;
tr741:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st549;
st549:
	if ( ++p == pe )
		goto _test_eof549;
case 549:
#line 10961 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 43: goto tr743;
		case 45: goto tr743;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr744;
	goto tr742;
tr743:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st550;
st550:
	if ( ++p == pe )
		goto _test_eof550;
case 550:
#line 10979 "inc/vcf/validator_detail_v41.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr744;
	goto tr742;
tr744:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st551;
st551:
	if ( ++p == pe )
		goto _test_eof551;
case 551:
#line 10993 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr609;
		case 10: goto tr610;
		case 59: goto tr611;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr744;
	goto tr742;
tr605:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st552;
st552:
	if ( ++p == pe )
		goto _test_eof552;
case 552:
#line 11016 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr609;
		case 10: goto tr610;
		case 59: goto tr611;
		case 61: goto tr612;
		case 66: goto tr745;
		case 79: goto tr746;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr608;
	goto tr592;
tr745:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st553;
st553:
	if ( ++p == pe )
		goto _test_eof553;
case 553:
#line 11038 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 61 )
		goto tr747;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr608;
	} else if ( (*p) >= 33 )
		goto tr608;
	goto tr592;
tr747:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st554;
st554:
	if ( ++p == pe )
		goto _test_eof554;
case 554:
#line 11057 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 43: goto tr749;
		case 45: goto tr749;
		case 46: goto tr750;
		case 73: goto tr752;
		case 78: goto tr753;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr751;
	goto tr748;
tr749:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st555;
st555:
	if ( ++p == pe )
		goto _test_eof555;
case 555:
#line 11078 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 46: goto tr750;
		case 73: goto tr752;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr751;
	goto tr748;
tr750:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st556;
st556:
	if ( ++p == pe )
		goto _test_eof556;
case 556:
#line 11096 "inc/vcf/validator_detail_v41.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr754;
	goto tr748;
tr754:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st557;
st557:
	if ( ++p == pe )
		goto _test_eof557;
case 557:
#line 11110 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr609;
		case 10: goto tr610;
		case 59: goto tr611;
		case 69: goto tr755;
		case 101: goto tr755;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr754;
	goto tr748;
tr755:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st558;
st558:
	if ( ++p == pe )
		goto _test_eof558;
case 558:
#line 11131 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 43: goto tr756;
		case 45: goto tr756;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr757;
	goto tr748;
tr756:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st559;
st559:
	if ( ++p == pe )
		goto _test_eof559;
case 559:
#line 11149 "inc/vcf/validator_detail_v41.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr757;
	goto tr748;
tr757:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st560;
st560:
	if ( ++p == pe )
		goto _test_eof560;
case 560:
#line 11163 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr609;
		case 10: goto tr610;
		case 59: goto tr611;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr757;
	goto tr748;
tr751:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st561;
st561:
	if ( ++p == pe )
		goto _test_eof561;
case 561:
#line 11182 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr609;
		case 10: goto tr610;
		case 46: goto tr750;
		case 59: goto tr611;
		case 69: goto tr755;
		case 101: goto tr755;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr751;
	goto tr748;
tr752:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st562;
st562:
	if ( ++p == pe )
		goto _test_eof562;
case 562:
#line 11204 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 110 )
		goto tr758;
	goto tr748;
tr758:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st563;
st563:
	if ( ++p == pe )
		goto _test_eof563;
case 563:
#line 11218 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 102 )
		goto tr759;
	goto tr748;
tr759:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st564;
st564:
	if ( ++p == pe )
		goto _test_eof564;
case 564:
#line 11232 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr609;
		case 10: goto tr610;
		case 59: goto tr611;
	}
	goto tr748;
tr753:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st565;
st565:
	if ( ++p == pe )
		goto _test_eof565;
case 565:
#line 11249 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 97 )
		goto tr760;
	goto tr748;
tr760:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st566;
st566:
	if ( ++p == pe )
		goto _test_eof566;
case 566:
#line 11263 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 78 )
		goto tr759;
	goto tr748;
tr746:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st567;
st567:
	if ( ++p == pe )
		goto _test_eof567;
case 567:
#line 11277 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr609;
		case 10: goto tr610;
		case 59: goto tr611;
		case 61: goto tr612;
		case 77: goto tr761;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr608;
	goto tr592;
tr761:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st568;
st568:
	if ( ++p == pe )
		goto _test_eof568;
case 568:
#line 11298 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr609;
		case 10: goto tr610;
		case 59: goto tr611;
		case 61: goto tr612;
		case 65: goto tr762;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr608;
	goto tr592;
tr762:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st569;
st569:
	if ( ++p == pe )
		goto _test_eof569;
case 569:
#line 11319 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr609;
		case 10: goto tr610;
		case 59: goto tr611;
		case 61: goto tr612;
		case 84: goto tr763;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr608;
	goto tr592;
tr763:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st570;
st570:
	if ( ++p == pe )
		goto _test_eof570;
case 570:
#line 11340 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr609;
		case 10: goto tr610;
		case 59: goto tr611;
		case 61: goto tr612;
		case 73: goto tr764;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr608;
	goto tr592;
tr764:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st571;
st571:
	if ( ++p == pe )
		goto _test_eof571;
case 571:
#line 11361 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr609;
		case 10: goto tr610;
		case 59: goto tr611;
		case 61: goto tr612;
		case 67: goto tr765;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr608;
	goto tr592;
tr765:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st572;
st572:
	if ( ++p == pe )
		goto _test_eof572;
case 572:
#line 11382 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr609;
		case 10: goto tr610;
		case 59: goto tr611;
		case 61: goto tr767;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr608;
	goto tr766;
tr767:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st573;
st573:
	if ( ++p == pe )
		goto _test_eof573;
case 573:
#line 11402 "inc/vcf/validator_detail_v41.hpp"
	if ( 48 <= (*p) && (*p) <= 49 )
		goto tr769;
	goto tr768;
tr769:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st574;
st574:
	if ( ++p == pe )
		goto _test_eof574;
case 574:
#line 11416 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr609;
		case 10: goto tr610;
		case 59: goto tr611;
	}
	goto tr768;
tr606:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st575;
st575:
	if ( ++p == pe )
		goto _test_eof575;
case 575:
#line 11437 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr609;
		case 10: goto tr610;
		case 59: goto tr611;
		case 61: goto tr612;
		case 65: goto tr770;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr608;
	goto tr592;
tr770:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st576;
st576:
	if ( ++p == pe )
		goto _test_eof576;
case 576:
#line 11458 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr609;
		case 10: goto tr610;
		case 59: goto tr611;
		case 61: goto tr612;
		case 76: goto tr771;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr608;
	goto tr592;
tr771:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st577;
st577:
	if ( ++p == pe )
		goto _test_eof577;
case 577:
#line 11479 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr609;
		case 10: goto tr610;
		case 59: goto tr611;
		case 61: goto tr612;
		case 73: goto tr772;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr608;
	goto tr592;
tr772:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st578;
st578:
	if ( ++p == pe )
		goto _test_eof578;
case 578:
#line 11500 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr609;
		case 10: goto tr610;
		case 59: goto tr611;
		case 61: goto tr612;
		case 68: goto tr773;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr608;
	goto tr592;
tr773:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st579;
st579:
	if ( ++p == pe )
		goto _test_eof579;
case 579:
#line 11521 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr609;
		case 10: goto tr610;
		case 59: goto tr611;
		case 61: goto tr612;
		case 65: goto tr774;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr608;
	goto tr592;
tr774:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st580;
st580:
	if ( ++p == pe )
		goto _test_eof580;
case 580:
#line 11542 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr609;
		case 10: goto tr610;
		case 59: goto tr611;
		case 61: goto tr612;
		case 84: goto tr775;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr608;
	goto tr592;
tr775:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st581;
st581:
	if ( ++p == pe )
		goto _test_eof581;
case 581:
#line 11563 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr609;
		case 10: goto tr610;
		case 59: goto tr611;
		case 61: goto tr612;
		case 69: goto tr776;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr608;
	goto tr592;
tr776:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st582;
st582:
	if ( ++p == pe )
		goto _test_eof582;
case 582:
#line 11584 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr609;
		case 10: goto tr610;
		case 59: goto tr611;
		case 61: goto tr612;
		case 68: goto tr777;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr608;
	goto tr592;
tr777:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st583;
st583:
	if ( ++p == pe )
		goto _test_eof583;
case 583:
#line 11605 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr609;
		case 10: goto tr610;
		case 59: goto tr611;
		case 61: goto tr779;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr608;
	goto tr778;
tr779:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st584;
st584:
	if ( ++p == pe )
		goto _test_eof584;
case 584:
#line 11625 "inc/vcf/validator_detail_v41.hpp"
	if ( 48 <= (*p) && (*p) <= 49 )
		goto tr781;
	goto tr780;
tr781:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st585;
st585:
	if ( ++p == pe )
		goto _test_eof585;
case 585:
#line 11639 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr609;
		case 10: goto tr610;
		case 59: goto tr611;
	}
	goto tr780;
tr594:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st586;
st586:
	if ( ++p == pe )
		goto _test_eof586;
case 586:
#line 11660 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr609;
		case 10: goto tr610;
		case 58: goto tr607;
		case 60: goto tr607;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr607;
		} else if ( (*p) > 57 ) {
			if ( 62 <= (*p) && (*p) <= 64 )
				goto tr607;
		} else
			goto tr608;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr607;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr607;
		} else
			goto tr608;
	} else
		goto tr608;
	goto tr592;
tr591:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st587;
st587:
	if ( ++p == pe )
		goto _test_eof587;
case 587:
#line 11698 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 58 )
		goto tr585;
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr585;
		} else if ( (*p) > 57 ) {
			if ( 60 <= (*p) && (*p) <= 64 )
				goto tr585;
		} else
			goto tr587;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr585;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr585;
		} else
			goto tr587;
	} else
		goto tr587;
	goto tr584;
tr586:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st588;
st588:
	if ( ++p == pe )
		goto _test_eof588;
case 588:
#line 11736 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr590;
		case 58: goto st430;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto st430;
		} else if ( (*p) > 57 ) {
			if ( 60 <= (*p) && (*p) <= 64 )
				goto st430;
		} else
			goto tr589;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st430;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st430;
		} else
			goto tr589;
	} else
		goto tr589;
	goto tr584;
tr583:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st589;
st589:
	if ( ++p == pe )
		goto _test_eof589;
case 589:
#line 11772 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 43: goto tr782;
		case 45: goto tr782;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr783;
	goto tr572;
tr782:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st590;
st590:
	if ( ++p == pe )
		goto _test_eof590;
case 590:
#line 11790 "inc/vcf/validator_detail_v41.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr783;
	goto tr572;
tr783:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st591;
st591:
	if ( ++p == pe )
		goto _test_eof591;
case 591:
#line 11804 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 9 )
		goto tr582;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr783;
	goto tr572;
tr579:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st592;
tr575:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st592;
st592:
	if ( ++p == pe )
		goto _test_eof592;
case 592:
#line 11830 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr582;
		case 46: goto tr578;
		case 69: goto tr583;
		case 101: goto tr583;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr579;
	goto tr572;
tr580:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st593;
tr576:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st593;
st593:
	if ( ++p == pe )
		goto _test_eof593;
case 593:
#line 11860 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 110 )
		goto tr784;
	goto tr572;
tr784:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st594;
st594:
	if ( ++p == pe )
		goto _test_eof594;
case 594:
#line 11874 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 102 )
		goto tr785;
	goto tr572;
tr785:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st595;
st595:
	if ( ++p == pe )
		goto _test_eof595;
case 595:
#line 11888 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 9 )
		goto tr582;
	goto tr572;
tr574:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st596;
st596:
	if ( ++p == pe )
		goto _test_eof596;
case 596:
#line 11906 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 9 )
		goto tr582;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr581;
	goto tr572;
tr577:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st597;
st597:
	if ( ++p == pe )
		goto _test_eof597;
case 597:
#line 11926 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 97 )
		goto tr786;
	goto tr572;
tr786:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st598;
st598:
	if ( ++p == pe )
		goto _test_eof598;
case 598:
#line 11940 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 78 )
		goto tr785;
	goto tr572;
tr571:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st599;
st599:
	if ( ++p == pe )
		goto _test_eof599;
case 599:
#line 11954 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 42: goto tr564;
		case 46: goto tr787;
		case 60: goto tr566;
		case 65: goto tr567;
		case 67: goto tr567;
		case 71: goto tr567;
		case 78: goto tr567;
		case 84: goto tr567;
		case 91: goto tr568;
		case 93: goto tr569;
		case 97: goto tr567;
		case 99: goto tr567;
		case 103: goto tr567;
		case 110: goto tr567;
		case 116: goto tr567;
	}
	goto tr563;
tr824:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st600;
tr787:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st600;
st600:
	if ( ++p == pe )
		goto _test_eof600;
case 600:
#line 11993 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 65: goto tr788;
		case 67: goto tr788;
		case 71: goto tr788;
		case 78: goto tr788;
		case 84: goto tr788;
		case 97: goto tr788;
		case 99: goto tr788;
		case 103: goto tr788;
		case 110: goto tr788;
		case 116: goto tr788;
	}
	goto tr563;
tr788:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st601;
st601:
	if ( ++p == pe )
		goto _test_eof601;
case 601:
#line 12017 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr570;
		case 44: goto tr571;
		case 65: goto tr788;
		case 67: goto tr788;
		case 71: goto tr788;
		case 78: goto tr788;
		case 84: goto tr788;
		case 97: goto tr788;
		case 99: goto tr788;
		case 103: goto tr788;
		case 110: goto tr788;
		case 116: goto tr788;
	}
	goto tr563;
tr790:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st602;
tr566:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st602;
st602:
	if ( ++p == pe )
		goto _test_eof602;
case 602:
#line 12053 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 58: goto tr790;
		case 95: goto tr790;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr789;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr789;
	} else
		goto tr789;
	goto tr563;
tr789:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st603;
st603:
	if ( ++p == pe )
		goto _test_eof603;
case 603:
#line 12077 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 62: goto tr791;
		case 95: goto tr789;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 58 )
			goto tr789;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr789;
	} else
		goto tr789;
	goto tr563;
tr792:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st604;
tr567:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st604;
st604:
	if ( ++p == pe )
		goto _test_eof604;
case 604:
#line 12111 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr570;
		case 44: goto tr571;
		case 46: goto tr791;
		case 65: goto tr792;
		case 67: goto tr792;
		case 71: goto tr792;
		case 78: goto tr792;
		case 84: goto tr792;
		case 91: goto tr793;
		case 93: goto tr794;
		case 97: goto tr792;
		case 99: goto tr792;
		case 103: goto tr792;
		case 110: goto tr792;
		case 116: goto tr792;
	}
	goto tr563;
tr793:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st605;
st605:
	if ( ++p == pe )
		goto _test_eof605;
case 605:
#line 12140 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 60 )
		goto tr796;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr795;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr795;
	} else
		goto tr795;
	goto tr563;
tr795:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st606;
st606:
	if ( ++p == pe )
		goto _test_eof606;
case 606:
#line 12162 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 58: goto tr799;
		case 59: goto tr797;
		case 61: goto tr797;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr797;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr797;
		} else
			goto tr798;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr797;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr797;
		} else
			goto tr798;
	} else
		goto tr798;
	goto tr563;
tr797:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st607;
st607:
	if ( ++p == pe )
		goto _test_eof607;
case 607:
#line 12199 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 59: goto tr797;
		case 61: goto tr797;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr797;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr797;
		} else
			goto tr798;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr797;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr797;
		} else
			goto tr798;
	} else
		goto tr798;
	goto tr563;
tr798:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st608;
st608:
	if ( ++p == pe )
		goto _test_eof608;
case 608:
#line 12235 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 58: goto tr799;
		case 61: goto tr798;
	}
	if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr798;
	} else if ( (*p) >= 33 )
		goto tr798;
	goto tr563;
tr799:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st609;
st609:
	if ( ++p == pe )
		goto _test_eof609;
case 609:
#line 12256 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 43: goto tr800;
		case 45: goto tr800;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr801;
	goto tr563;
tr800:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st610;
st610:
	if ( ++p == pe )
		goto _test_eof610;
case 610:
#line 12274 "inc/vcf/validator_detail_v41.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr801;
	goto tr563;
tr801:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st611;
st611:
	if ( ++p == pe )
		goto _test_eof611;
case 611:
#line 12288 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 91 )
		goto tr791;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr801;
	goto tr563;
tr796:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st612;
st612:
	if ( ++p == pe )
		goto _test_eof612;
case 612:
#line 12304 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr802;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr802;
	} else
		goto tr802;
	goto tr563;
tr802:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st613;
st613:
	if ( ++p == pe )
		goto _test_eof613;
case 613:
#line 12324 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 59: goto tr803;
		case 62: goto tr805;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr803;
		} else if ( (*p) > 57 ) {
			if ( 61 <= (*p) && (*p) <= 64 )
				goto tr803;
		} else
			goto tr804;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr803;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr803;
		} else
			goto tr804;
	} else
		goto tr804;
	goto tr563;
tr803:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st614;
st614:
	if ( ++p == pe )
		goto _test_eof614;
case 614:
#line 12360 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 59: goto tr803;
		case 61: goto tr803;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr803;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr803;
		} else
			goto tr804;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr803;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr803;
		} else
			goto tr804;
	} else
		goto tr804;
	goto tr563;
tr804:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st615;
st615:
	if ( ++p == pe )
		goto _test_eof615;
case 615:
#line 12396 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 59: goto tr804;
		case 62: goto tr805;
	}
	if ( (*p) > 57 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr804;
	} else if ( (*p) >= 33 )
		goto tr804;
	goto tr563;
tr805:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st616;
st616:
	if ( ++p == pe )
		goto _test_eof616;
case 616:
#line 12417 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 58 )
		goto tr799;
	goto tr563;
tr794:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st617;
st617:
	if ( ++p == pe )
		goto _test_eof617;
case 617:
#line 12431 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 60 )
		goto tr807;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr806;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr806;
	} else
		goto tr806;
	goto tr563;
tr806:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st618;
st618:
	if ( ++p == pe )
		goto _test_eof618;
case 618:
#line 12453 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 58: goto tr810;
		case 59: goto tr808;
		case 61: goto tr808;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr808;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr808;
		} else
			goto tr809;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr808;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr808;
		} else
			goto tr809;
	} else
		goto tr809;
	goto tr563;
tr808:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st619;
st619:
	if ( ++p == pe )
		goto _test_eof619;
case 619:
#line 12490 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 59: goto tr808;
		case 61: goto tr808;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr808;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr808;
		} else
			goto tr809;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr808;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr808;
		} else
			goto tr809;
	} else
		goto tr809;
	goto tr563;
tr809:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st620;
st620:
	if ( ++p == pe )
		goto _test_eof620;
case 620:
#line 12526 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 58: goto tr810;
		case 61: goto tr809;
	}
	if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr809;
	} else if ( (*p) >= 33 )
		goto tr809;
	goto tr563;
tr810:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st621;
st621:
	if ( ++p == pe )
		goto _test_eof621;
case 621:
#line 12547 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 43: goto tr811;
		case 45: goto tr811;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr812;
	goto tr563;
tr811:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st622;
st622:
	if ( ++p == pe )
		goto _test_eof622;
case 622:
#line 12565 "inc/vcf/validator_detail_v41.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr812;
	goto tr563;
tr812:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st623;
st623:
	if ( ++p == pe )
		goto _test_eof623;
case 623:
#line 12579 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 93 )
		goto tr791;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr812;
	goto tr563;
tr807:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st624;
st624:
	if ( ++p == pe )
		goto _test_eof624;
case 624:
#line 12595 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr813;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr813;
	} else
		goto tr813;
	goto tr563;
tr813:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st625;
st625:
	if ( ++p == pe )
		goto _test_eof625;
case 625:
#line 12615 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 59: goto tr814;
		case 62: goto tr816;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr814;
		} else if ( (*p) > 57 ) {
			if ( 61 <= (*p) && (*p) <= 64 )
				goto tr814;
		} else
			goto tr815;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr814;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr814;
		} else
			goto tr815;
	} else
		goto tr815;
	goto tr563;
tr814:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st626;
st626:
	if ( ++p == pe )
		goto _test_eof626;
case 626:
#line 12651 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 59: goto tr814;
		case 61: goto tr814;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr814;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr814;
		} else
			goto tr815;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr814;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr814;
		} else
			goto tr815;
	} else
		goto tr815;
	goto tr563;
tr815:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st627;
st627:
	if ( ++p == pe )
		goto _test_eof627;
case 627:
#line 12687 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 59: goto tr815;
		case 62: goto tr816;
	}
	if ( (*p) > 57 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr815;
	} else if ( (*p) >= 33 )
		goto tr815;
	goto tr563;
tr816:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st628;
st628:
	if ( ++p == pe )
		goto _test_eof628;
case 628:
#line 12708 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 58 )
		goto tr810;
	goto tr563;
tr568:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st629;
st629:
	if ( ++p == pe )
		goto _test_eof629;
case 629:
#line 12726 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 60 )
		goto tr818;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr817;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr817;
	} else
		goto tr817;
	goto tr563;
tr817:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st630;
st630:
	if ( ++p == pe )
		goto _test_eof630;
case 630:
#line 12748 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 58: goto tr821;
		case 59: goto tr819;
		case 61: goto tr819;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr819;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr819;
		} else
			goto tr820;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr819;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr819;
		} else
			goto tr820;
	} else
		goto tr820;
	goto tr563;
tr819:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st631;
st631:
	if ( ++p == pe )
		goto _test_eof631;
case 631:
#line 12785 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 59: goto tr819;
		case 61: goto tr819;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr819;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr819;
		} else
			goto tr820;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr819;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr819;
		} else
			goto tr820;
	} else
		goto tr820;
	goto tr563;
tr820:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st632;
st632:
	if ( ++p == pe )
		goto _test_eof632;
case 632:
#line 12821 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 58: goto tr821;
		case 61: goto tr820;
	}
	if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr820;
	} else if ( (*p) >= 33 )
		goto tr820;
	goto tr563;
tr821:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st633;
st633:
	if ( ++p == pe )
		goto _test_eof633;
case 633:
#line 12842 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 43: goto tr822;
		case 45: goto tr822;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr823;
	goto tr563;
tr822:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st634;
st634:
	if ( ++p == pe )
		goto _test_eof634;
case 634:
#line 12860 "inc/vcf/validator_detail_v41.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr823;
	goto tr563;
tr823:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st635;
st635:
	if ( ++p == pe )
		goto _test_eof635;
case 635:
#line 12874 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 91 )
		goto tr824;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr823;
	goto tr563;
tr818:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st636;
st636:
	if ( ++p == pe )
		goto _test_eof636;
case 636:
#line 12890 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr825;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr825;
	} else
		goto tr825;
	goto tr563;
tr825:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st637;
st637:
	if ( ++p == pe )
		goto _test_eof637;
case 637:
#line 12910 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 59: goto tr826;
		case 62: goto tr828;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr826;
		} else if ( (*p) > 57 ) {
			if ( 61 <= (*p) && (*p) <= 64 )
				goto tr826;
		} else
			goto tr827;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr826;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr826;
		} else
			goto tr827;
	} else
		goto tr827;
	goto tr563;
tr826:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st638;
st638:
	if ( ++p == pe )
		goto _test_eof638;
case 638:
#line 12946 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 59: goto tr826;
		case 61: goto tr826;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr826;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr826;
		} else
			goto tr827;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr826;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr826;
		} else
			goto tr827;
	} else
		goto tr827;
	goto tr563;
tr827:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st639;
st639:
	if ( ++p == pe )
		goto _test_eof639;
case 639:
#line 12982 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 59: goto tr827;
		case 62: goto tr828;
	}
	if ( (*p) > 57 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr827;
	} else if ( (*p) >= 33 )
		goto tr827;
	goto tr563;
tr828:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st640;
st640:
	if ( ++p == pe )
		goto _test_eof640;
case 640:
#line 13003 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 58 )
		goto tr821;
	goto tr563;
tr569:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st641;
st641:
	if ( ++p == pe )
		goto _test_eof641;
case 641:
#line 13021 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 60 )
		goto tr830;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr829;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr829;
	} else
		goto tr829;
	goto tr563;
tr829:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st642;
st642:
	if ( ++p == pe )
		goto _test_eof642;
case 642:
#line 13043 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 58: goto tr833;
		case 59: goto tr831;
		case 61: goto tr831;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr831;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr831;
		} else
			goto tr832;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr831;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr831;
		} else
			goto tr832;
	} else
		goto tr832;
	goto tr563;
tr831:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st643;
st643:
	if ( ++p == pe )
		goto _test_eof643;
case 643:
#line 13080 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 59: goto tr831;
		case 61: goto tr831;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr831;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr831;
		} else
			goto tr832;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr831;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr831;
		} else
			goto tr832;
	} else
		goto tr832;
	goto tr563;
tr832:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st644;
st644:
	if ( ++p == pe )
		goto _test_eof644;
case 644:
#line 13116 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 58: goto tr833;
		case 61: goto tr832;
	}
	if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr832;
	} else if ( (*p) >= 33 )
		goto tr832;
	goto tr563;
tr833:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st645;
st645:
	if ( ++p == pe )
		goto _test_eof645;
case 645:
#line 13137 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 43: goto tr834;
		case 45: goto tr834;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr835;
	goto tr563;
tr834:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st646;
st646:
	if ( ++p == pe )
		goto _test_eof646;
case 646:
#line 13155 "inc/vcf/validator_detail_v41.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr835;
	goto tr563;
tr835:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st647;
st647:
	if ( ++p == pe )
		goto _test_eof647;
case 647:
#line 13169 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 93 )
		goto tr824;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr835;
	goto tr563;
tr830:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st648;
st648:
	if ( ++p == pe )
		goto _test_eof648;
case 648:
#line 13185 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr836;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr836;
	} else
		goto tr836;
	goto tr563;
tr836:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st649;
st649:
	if ( ++p == pe )
		goto _test_eof649;
case 649:
#line 13205 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 59: goto tr837;
		case 62: goto tr839;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr837;
		} else if ( (*p) > 57 ) {
			if ( 61 <= (*p) && (*p) <= 64 )
				goto tr837;
		} else
			goto tr838;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr837;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr837;
		} else
			goto tr838;
	} else
		goto tr838;
	goto tr563;
tr837:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st650;
st650:
	if ( ++p == pe )
		goto _test_eof650;
case 650:
#line 13241 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 59: goto tr837;
		case 61: goto tr837;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr837;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr837;
		} else
			goto tr838;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr837;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr837;
		} else
			goto tr838;
	} else
		goto tr838;
	goto tr563;
tr838:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st651;
st651:
	if ( ++p == pe )
		goto _test_eof651;
case 651:
#line 13277 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 59: goto tr838;
		case 62: goto tr839;
	}
	if ( (*p) > 57 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr838;
	} else if ( (*p) >= 33 )
		goto tr838;
	goto tr563;
tr839:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st652;
st652:
	if ( ++p == pe )
		goto _test_eof652;
case 652:
#line 13298 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 58 )
		goto tr833;
	goto tr563;
tr565:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st653;
st653:
	if ( ++p == pe )
		goto _test_eof653;
case 653:
#line 13316 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr570;
		case 65: goto tr788;
		case 67: goto tr788;
		case 71: goto tr788;
		case 78: goto tr788;
		case 84: goto tr788;
		case 97: goto tr788;
		case 99: goto tr788;
		case 103: goto tr788;
		case 110: goto tr788;
		case 116: goto tr788;
	}
	goto tr563;
tr547:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st654;
st654:
	if ( ++p == pe )
		goto _test_eof654;
case 654:
#line 13341 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 59: goto tr547;
		case 61: goto tr547;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr547;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr547;
		} else
			goto tr548;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr547;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr547;
		} else
			goto tr548;
	} else
		goto tr548;
	goto tr545;
tr548:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st655;
st655:
	if ( ++p == pe )
		goto _test_eof655;
case 655:
#line 13377 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr546;
		case 59: goto tr548;
		case 61: goto tr548;
	}
	if ( (*p) > 57 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr548;
	} else if ( (*p) >= 33 )
		goto tr548;
	goto tr545;
st656:
	if ( ++p == pe )
		goto _test_eof656;
case 656:
	if ( (*p) == 10 )
		goto tr841;
	goto st656;
tr841:
#line 43 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
#line 748 "src/vcf/vcf_v41.ragel"
	{ {goto st28;} }
	goto st660;
st660:
	if ( ++p == pe )
		goto _test_eof660;
case 660:
#line 13414 "inc/vcf/validator_detail_v41.hpp"
	goto st0;
st657:
	if ( ++p == pe )
		goto _test_eof657;
case 657:
	if ( (*p) == 10 )
		goto tr843;
	goto st657;
tr843:
#line 43 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
#line 749 "src/vcf/vcf_v41.ragel"
	{ {goto st659;} }
	goto st661;
st661:
	if ( ++p == pe )
		goto _test_eof661;
case 661:
#line 13441 "inc/vcf/validator_detail_v41.hpp"
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
	_test_eof658: cs = 658; goto _test_eof; 
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
	_test_eof659: cs = 659; goto _test_eof; 
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
	_test_eof660: cs = 660; goto _test_eof; 
	_test_eof657: cs = 657; goto _test_eof; 
	_test_eof661: cs = 661; goto _test_eof; 

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
#line 60 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this);
        p--; {goto st656;}
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
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
	break;
	case 658: 
#line 70 "src/vcf/vcf_v41.ragel"
	{
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (ParsingWarning warn) {
          ErrorPolicy::handle_meta_section_warning(*this, warn.what());
        }
    }
	break;
	case 406: 
	case 407: 
	case 408: 
	case 409: 
	case 410: 
	case 411: 
	case 412: 
	case 413: 
	case 414: 
#line 78 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (ParsingWarning warn) {
          ErrorPolicy::handle_meta_section_warning(*this, warn.what());
        }
        
        p--; {goto st657;}
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
#line 210 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this,
            "The fileformat declaration is not 'fileformat=VCFv4.1'");
        p--; {goto st656;}
    }
#line 60 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this);
        p--; {goto st656;}
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
	case 98: 
#line 217 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st656;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
	break;
	case 302: 
	case 303: 
	case 304: 
	case 305: 
	case 306: 
	case 307: 
	case 308: 
	case 309: 
#line 228 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in assembly metadata");
        p--; {goto st656;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
	break;
	case 317: 
	case 318: 
	case 319: 
	case 320: 
	case 321: 
	case 322: 
	case 323: 
	case 324: 
	case 325: 
	case 326: 
	case 331: 
	case 332: 
	case 333: 
	case 334: 
	case 335: 
	case 336: 
	case 337: 
	case 338: 
	case 339: 
	case 340: 
	case 341: 
	case 342: 
	case 343: 
	case 344: 
	case 345: 
	case 346: 
	case 347: 
	case 348: 
	case 349: 
#line 234 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in contig metadata");
        p--; {goto st656;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
	break;
	case 104: 
	case 105: 
	case 106: 
	case 107: 
	case 108: 
	case 109: 
	case 110: 
	case 111: 
	case 112: 
	case 116: 
	case 117: 
	case 118: 
	case 119: 
	case 120: 
	case 121: 
	case 122: 
	case 123: 
	case 124: 
	case 125: 
	case 126: 
	case 127: 
	case 128: 
	case 132: 
#line 240 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st656;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
	break;
	case 136: 
	case 137: 
	case 138: 
	case 139: 
	case 140: 
	case 141: 
	case 142: 
	case 143: 
	case 144: 
	case 148: 
	case 149: 
	case 150: 
	case 151: 
	case 152: 
	case 153: 
	case 154: 
	case 157: 
	case 158: 
	case 159: 
	case 160: 
	case 161: 
	case 164: 
	case 165: 
	case 166: 
	case 167: 
	case 168: 
	case 169: 
	case 170: 
	case 171: 
	case 172: 
	case 173: 
	case 174: 
	case 175: 
	case 176: 
	case 180: 
#line 246 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st656;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
	break;
	case 185: 
	case 186: 
	case 187: 
	case 188: 
	case 189: 
	case 190: 
	case 191: 
	case 192: 
	case 196: 
	case 197: 
	case 198: 
	case 199: 
	case 200: 
	case 201: 
	case 202: 
	case 205: 
	case 206: 
	case 207: 
	case 208: 
	case 209: 
	case 212: 
	case 213: 
	case 214: 
	case 215: 
	case 216: 
	case 217: 
	case 218: 
	case 219: 
	case 220: 
	case 221: 
	case 222: 
	case 223: 
	case 224: 
	case 228: 
#line 262 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st656;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
	break;
	case 233: 
	case 234: 
	case 235: 
	case 236: 
	case 237: 
	case 238: 
	case 239: 
	case 240: 
	case 241: 
	case 248: 
#line 278 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in PEDIGREE metadata");
        p--; {goto st656;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
	break;
	case 350: 
	case 351: 
	case 352: 
	case 353: 
	case 354: 
	case 355: 
	case 356: 
	case 357: 
	case 358: 
	case 359: 
	case 360: 
#line 284 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in pedigreeDB metadata");
        p--; {goto st656;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
	break;
	case 249: 
	case 250: 
	case 251: 
	case 252: 
	case 253: 
	case 254: 
	case 255: 
	case 256: 
	case 257: 
	case 258: 
	case 298: 
#line 290 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st656;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
	break;
	case 369: 
	case 370: 
	case 371: 
	case 372: 
	case 373: 
	case 374: 
	case 375: 
	case 376: 
	case 377: 
	case 378: 
	case 379: 
	case 380: 
	case 381: 
	case 382: 
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
	case 402: 
	case 403: 
	case 404: 
	case 405: 
#line 322 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this, "The header line does not start with the mandatory columns: CHROM, POS, ID, REF, ALT, QUAL, FILTER and INFO");
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (ParsingWarning warn) {
          ErrorPolicy::handle_meta_section_warning(*this, warn.what());
        }
        
        p--; {goto st657;}
    }
#line 78 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (ParsingWarning warn) {
          ErrorPolicy::handle_meta_section_warning(*this, warn.what());
        }
        
        p--; {goto st657;}
    }
	break;
	case 415: 
	case 439: 
	case 440: 
	case 441: 
	case 442: 
	case 443: 
	case 654: 
	case 655: 
#line 338 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Chromosome is not a string without colons or whitespaces, optionally wrapped with angle brackets (<>)");
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	break;
	case 416: 
	case 417: 
	case 418: 
#line 344 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Position is not a positive number");
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	break;
	case 419: 
	case 420: 
#line 350 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "ID is not a single dot or a list of strings without semicolons or whitespaces");
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	break;
	case 421: 
	case 422: 
#line 356 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Reference is not a string of bases");
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	break;
	case 423: 
	case 424: 
	case 599: 
	case 600: 
	case 601: 
	case 602: 
	case 603: 
	case 604: 
	case 605: 
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
	case 619: 
	case 620: 
	case 621: 
	case 622: 
	case 623: 
	case 624: 
	case 625: 
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
	case 639: 
	case 640: 
	case 641: 
	case 642: 
	case 643: 
	case 644: 
	case 645: 
	case 646: 
	case 647: 
	case 648: 
	case 649: 
	case 650: 
	case 651: 
	case 652: 
	case 653: 
#line 362 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Alternate is not a single dot or a comma-separated list of bases");
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	break;
	case 425: 
	case 426: 
	case 427: 
	case 428: 
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
#line 368 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Quality is not a single dot or a positive number");
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	break;
	case 429: 
	case 430: 
	case 431: 
	case 587: 
	case 588: 
#line 374 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Filter is not a single dot or a semicolon-separated list of strings");
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	break;
	case 435: 
	case 436: 
#line 486 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Format is not a colon-separated list of alphanumeric strings");
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	break;
	case 446: 
	case 447: 
#line 492 "src/vcf/vcf_v41.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " is not a valid string";
        ErrorPolicy::handle_body_section_error(*this, message_stream.str());
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	break;
	case 23: 
	case 28: 
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
#line 322 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this, "The header line does not start with the mandatory columns: CHROM, POS, ID, REF, ALT, QUAL, FILTER and INFO");
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (ParsingWarning warn) {
          ErrorPolicy::handle_meta_section_warning(*this, warn.what());
        }
        
        p--; {goto st657;}
    }
#line 78 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (ParsingWarning warn) {
          ErrorPolicy::handle_meta_section_warning(*this, warn.what());
        }
        
        p--; {goto st657;}
    }
	break;
	case 80: 
	case 81: 
	case 102: 
#line 222 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "ALT metadata ID is not prefixed by DEL/INS/DUP/INV/CNV and suffixed by ':' and a text sequence");
        p--; {goto st656;}
    }
#line 217 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st656;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
	break;
	case 103: 
#line 240 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st656;}
    }
#line 246 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st656;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
	break;
	case 155: 
	case 156: 
	case 184: 
#line 251 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "FORMAT metadata Number is not a number, A, R, G or dot");
        p--; {goto st656;}
    }
#line 246 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st656;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
	break;
	case 203: 
	case 204: 
	case 232: 
#line 267 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "INFO metadata Number is not a number, A, R, G or dot");
        p--; {goto st656;}
    }
#line 262 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st656;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
	break;
	case 162: 
	case 163: 
#line 272 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "INFO metadata Type is not a Integer, Float, Flag, Character or String");
        p--; {goto st656;}
    }
#line 246 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st656;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
	break;
	case 210: 
	case 211: 
#line 272 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "INFO metadata Type is not a Integer, Float, Flag, Character or String");
        p--; {goto st656;}
    }
#line 262 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st656;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
	break;
	case 262: 
	case 263: 
	case 264: 
	case 265: 
	case 266: 
	case 267: 
	case 268: 
	case 269: 
	case 270: 
#line 295 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Genomes is not a valid string (maybe it contains quotes?)");
        p--; {goto st656;}
    }
#line 290 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st656;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
	break;
	case 272: 
	case 273: 
	case 274: 
	case 275: 
	case 276: 
	case 277: 
	case 278: 
	case 279: 
	case 280: 
#line 300 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Mixture is not a valid string (maybe it contains quotes?)");
        p--; {goto st656;}
    }
#line 290 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st656;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
	break;
	case 327: 
	case 328: 
	case 329: 
	case 330: 
#line 306 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st656;}
    }
#line 234 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in contig metadata");
        p--; {goto st656;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
	break;
	case 113: 
	case 114: 
	case 115: 
#line 306 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st656;}
    }
#line 240 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st656;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
	break;
	case 145: 
	case 146: 
	case 147: 
#line 306 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st656;}
    }
#line 246 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st656;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
	break;
	case 193: 
	case 194: 
	case 195: 
#line 306 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st656;}
    }
#line 262 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st656;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
	break;
	case 242: 
	case 243: 
	case 244: 
	case 245: 
	case 246: 
	case 247: 
#line 306 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st656;}
    }
#line 278 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in PEDIGREE metadata");
        p--; {goto st656;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
	break;
	case 259: 
	case 260: 
#line 306 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st656;}
    }
#line 290 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st656;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
	break;
	case 95: 
	case 96: 
	case 97: 
	case 99: 
	case 100: 
	case 101: 
#line 311 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st656;}
    }
#line 217 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st656;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
	break;
	case 129: 
	case 130: 
	case 131: 
	case 133: 
	case 134: 
	case 135: 
#line 311 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st656;}
    }
#line 240 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st656;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
	break;
	case 177: 
	case 178: 
	case 179: 
	case 181: 
	case 182: 
	case 183: 
#line 311 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st656;}
    }
#line 246 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st656;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
	break;
	case 225: 
	case 226: 
	case 227: 
	case 229: 
	case 230: 
	case 231: 
#line 311 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st656;}
    }
#line 262 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st656;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
	break;
	case 282: 
	case 283: 
	case 284: 
	case 285: 
	case 286: 
	case 287: 
	case 288: 
	case 289: 
	case 290: 
	case 291: 
	case 292: 
	case 293: 
	case 294: 
	case 295: 
	case 296: 
	case 297: 
	case 299: 
	case 300: 
	case 301: 
#line 311 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st656;}
    }
#line 290 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st656;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
	break;
	case 310: 
	case 311: 
	case 312: 
	case 313: 
	case 314: 
	case 315: 
	case 316: 
#line 316 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata URL is not valid");
        p--; {goto st656;}
    }
#line 228 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in assembly metadata");
        p--; {goto st656;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
	break;
	case 361: 
	case 362: 
	case 363: 
	case 364: 
	case 365: 
	case 366: 
	case 367: 
	case 368: 
#line 316 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata URL is not valid");
        p--; {goto st656;}
    }
#line 284 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in pedigreeDB metadata");
        p--; {goto st656;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
	break;
	case 432: 
	case 433: 
	case 434: 
	case 448: 
	case 449: 
	case 450: 
	case 451: 
	case 452: 
	case 458: 
	case 459: 
	case 463: 
	case 467: 
	case 481: 
	case 485: 
	case 486: 
	case 500: 
	case 501: 
	case 502: 
	case 503: 
	case 504: 
	case 507: 
	case 511: 
	case 515: 
	case 516: 
	case 517: 
	case 521: 
	case 528: 
	case 529: 
	case 530: 
	case 547: 
	case 548: 
	case 552: 
	case 553: 
	case 567: 
	case 568: 
	case 569: 
	case 570: 
	case 571: 
	case 575: 
	case 576: 
	case 577: 
	case 578: 
	case 579: 
	case 580: 
	case 581: 
	case 582: 
	case 586: 
#line 385 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st657;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	break;
	case 453: 
	case 454: 
#line 390 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info field value is not a comma-separated list of valid strings (maybe it contains whitespaces?)");
        p--; {goto st657;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	break;
	case 460: 
	case 461: 
	case 462: 
#line 395 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info AA value is not a single dot or a string of bases");
        p--; {goto st657;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	break;
	case 464: 
	case 465: 
	case 466: 
#line 400 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info AC value is not a comma-separated list of numbers");
        p--; {goto st657;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	break;
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
#line 405 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info AF value is not a comma-separated list of numbers");
        p--; {goto st657;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	break;
	case 482: 
	case 483: 
	case 484: 
#line 410 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info AN value is not an integer number");
        p--; {goto st657;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	break;
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
#line 415 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info BQ value is not a number");
        p--; {goto st657;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	break;
	case 505: 
	case 506: 
#line 420 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info CIGAR value is not an alphanumeric string");
        p--; {goto st657;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	break;
	case 509: 
	case 510: 
#line 425 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info DB is not a flag (with 1/0/no value)");
        p--; {goto st657;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	break;
	case 512: 
	case 513: 
	case 514: 
#line 430 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info DP value is not an integer number");
        p--; {goto st657;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	break;
	case 518: 
	case 519: 
	case 520: 
#line 435 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info END value is not an integer number");
        p--; {goto st657;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	break;
	case 523: 
	case 524: 
#line 440 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info H2 is not a flag (with 1/0/no value)");
        p--; {goto st657;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	break;
	case 526: 
	case 527: 
#line 445 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info H3 is not a flag (with 1/0/no value)");
        p--; {goto st657;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	break;
	case 534: 
	case 535: 
	case 536: 
	case 537: 
	case 538: 
	case 539: 
	case 540: 
	case 541: 
	case 542: 
	case 543: 
	case 544: 
	case 545: 
	case 546: 
#line 450 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info MQ value is not a number");
        p--; {goto st657;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	break;
	case 531: 
	case 532: 
	case 533: 
#line 455 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info MQ0 value is not an integer number");
        p--; {goto st657;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	break;
	case 549: 
	case 550: 
	case 551: 
#line 460 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info NS value is not an integer number");
        p--; {goto st657;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	break;
	case 554: 
	case 555: 
	case 556: 
	case 557: 
	case 558: 
	case 559: 
	case 560: 
	case 561: 
	case 562: 
	case 563: 
	case 564: 
	case 565: 
	case 566: 
#line 465 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info SB value is not a number");
        p--; {goto st657;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	break;
	case 573: 
	case 574: 
#line 470 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info SOMATIC is not a flag (with 1/0/no value)");
        p--; {goto st657;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	break;
	case 584: 
	case 585: 
#line 475 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info VALIDATED is not a flag (with 1/0/no value)");
        p--; {goto st657;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	break;
	case 456: 
	case 457: 
#line 480 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info 1000G is not a flag (with 1/0/no value)");
        p--; {goto st657;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	break;
	case 437: 
	case 438: 
	case 444: 
	case 445: 
#line 499 "src/vcf/vcf_v41.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " does not start with a valid genotype";
        ErrorPolicy::handle_body_section_error(*this, message_stream.str());
        p--; {goto st657;}
    }
#line 492 "src/vcf/vcf_v41.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " is not a valid string";
        ErrorPolicy::handle_body_section_error(*this, message_stream.str());
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	break;
	case 22: 
#line 60 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this);
        p--; {goto st656;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
#line 322 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this, "The header line does not start with the mandatory columns: CHROM, POS, ID, REF, ALT, QUAL, FILTER and INFO");
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (ParsingWarning warn) {
          ErrorPolicy::handle_meta_section_warning(*this, warn.what());
        }
        
        p--; {goto st657;}
    }
#line 78 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (ParsingWarning warn) {
          ErrorPolicy::handle_meta_section_warning(*this, warn.what());
        }
        
        p--; {goto st657;}
    }
	break;
	case 271: 
#line 295 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Genomes is not a valid string (maybe it contains quotes?)");
        p--; {goto st656;}
    }
#line 300 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Mixture is not a valid string (maybe it contains quotes?)");
        p--; {goto st656;}
    }
#line 290 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st656;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
	break;
	case 281: 
#line 300 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Mixture is not a valid string (maybe it contains quotes?)");
        p--; {goto st656;}
    }
#line 311 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st656;}
    }
#line 290 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st656;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
	break;
	case 261: 
#line 306 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st656;}
    }
#line 295 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Genomes is not a valid string (maybe it contains quotes?)");
        p--; {goto st656;}
    }
#line 290 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st656;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
	break;
	case 508: 
#line 425 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info DB is not a flag (with 1/0/no value)");
        p--; {goto st657;}
    }
#line 385 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st657;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	break;
	case 522: 
#line 440 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info H2 is not a flag (with 1/0/no value)");
        p--; {goto st657;}
    }
#line 385 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st657;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	break;
	case 525: 
#line 445 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info H3 is not a flag (with 1/0/no value)");
        p--; {goto st657;}
    }
#line 385 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st657;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	break;
	case 572: 
#line 470 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info SOMATIC is not a flag (with 1/0/no value)");
        p--; {goto st657;}
    }
#line 385 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st657;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	break;
	case 583: 
#line 475 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info VALIDATED is not a flag (with 1/0/no value)");
        p--; {goto st657;}
    }
#line 385 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st657;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	break;
	case 455: 
#line 480 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info 1000G is not a flag (with 1/0/no value)");
        p--; {goto st657;}
    }
#line 385 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st657;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st657;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st657;}
    }
	break;
	case 24: 
#line 217 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st656;}
    }
#line 240 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st656;}
    }
#line 246 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st656;}
    }
#line 262 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st656;}
    }
#line 228 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in assembly metadata");
        p--; {goto st656;}
    }
#line 234 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in contig metadata");
        p--; {goto st656;}
    }
#line 290 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st656;}
    }
#line 278 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in PEDIGREE metadata");
        p--; {goto st656;}
    }
#line 284 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in pedigreeDB metadata");
        p--; {goto st656;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st656;}
    }
	break;
#line 16024 "inc/vcf/validator_detail_v41.hpp"
	}
	}

	_out: {}
	}

#line 780 "src/vcf/vcf_v41.ragel"

    }
   
  }
}
