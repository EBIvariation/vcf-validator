
#line 1 "src/vcf/vcf_v41.ragel"
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


#line 767 "src/vcf/vcf_v41.ragel"


namespace
{
  
#line 31 "inc/vcf/validator_detail_v41.hpp"
static const int vcf_v41_start = 1;
static const int vcf_v41_first_final = 648;
static const int vcf_v41_error = 0;

static const int vcf_v41_en_main = 1;
static const int vcf_v41_en_main_meta_section = 28;
static const int vcf_v41_en_main_body_section = 650;
static const int vcf_v41_en_meta_section_skip = 646;
static const int vcf_v41_en_body_section_skip = 647;


#line 773 "src/vcf/vcf_v41.ragel"

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

#line 789 "src/vcf/vcf_v41.ragel"

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
        ErrorPolicy::handle_error(*this, new FileformatError{n_lines});
        p--; {goto st646;}
    }
	goto st0;
tr14:
#line 227 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this,
            new FileformatError{n_lines, "The fileformat declaration is not 'fileformat=VCFv4.1'"});
        p--; {goto st646;}
    }
#line 60 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new FileformatError{n_lines});
        p--; {goto st646;}
    }
	goto st0;
tr23:
#line 60 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new FileformatError{n_lines});
        p--; {goto st646;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
    }
#line 340 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new HeaderSectionError{n_lines,
            "The header line does not start with the mandatory columns: CHROM, POS, ID, REF, ALT, QUAL, FILTER and INFO"});
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (MetaSectionError *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
        
        p--; {goto st647;}
    }
#line 78 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new HeaderSectionError{n_lines});
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (MetaSectionError *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
        
        p--; {goto st647;}
    }
	goto st0;
tr25:
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
    }
#line 340 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new HeaderSectionError{n_lines,
            "The header line does not start with the mandatory columns: CHROM, POS, ID, REF, ALT, QUAL, FILTER and INFO"});
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (MetaSectionError *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
        
        p--; {goto st647;}
    }
#line 78 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new HeaderSectionError{n_lines});
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (MetaSectionError *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
        
        p--; {goto st647;}
    }
	goto st0;
tr28:
#line 234 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {goto st646;}
    }
#line 258 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {goto st646;}
    }
#line 264 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st646;}
    }
#line 280 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st646;}
    }
#line 246 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in assembly metadata"});
        p--; {goto st646;}
    }
#line 252 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in contig metadata"});
        p--; {goto st646;}
    }
#line 308 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st646;}
    }
#line 296 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {goto st646;}
    }
#line 302 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in pedigreeDB metadata"});
        p--; {goto st646;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
    }
	goto st0;
tr38:
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
    }
	goto st0;
tr121:
#line 234 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {goto st646;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
    }
	goto st0;
tr129:
#line 239 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines,
            "ALT metadata ID is not prefixed by DEL/INS/DUP/INV/CNV and suffixed by ':' and a text sequence"});
        p--; {goto st646;}
    }
#line 234 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {goto st646;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
    }
	goto st0;
tr148:
#line 329 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st646;}
    }
#line 234 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {goto st646;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
    }
	goto st0;
tr158:
#line 258 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {goto st646;}
    }
#line 264 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st646;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
    }
	goto st0;
tr161:
#line 258 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {goto st646;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
    }
	goto st0;
tr171:
#line 324 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st646;}
    }
#line 258 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {goto st646;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
    }
	goto st0;
tr190:
#line 329 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st646;}
    }
#line 258 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {goto st646;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
    }
	goto st0;
tr200:
#line 264 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st646;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
    }
	goto st0;
tr210:
#line 324 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st646;}
    }
#line 264 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st646;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
    }
	goto st0;
tr223:
#line 269 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "FORMAT metadata Number is not a number, A, G or dot"});
        p--; {goto st646;}
    }
#line 264 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st646;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
    }
	goto st0;
tr232:
#line 290 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "INFO metadata Type is not a Integer, Float, Flag, Character or String"});
        p--; {goto st646;}
    }
#line 264 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st646;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
    }
	goto st0;
tr249:
#line 329 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st646;}
    }
#line 264 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st646;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
    }
	goto st0;
tr260:
#line 280 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st646;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
    }
	goto st0;
tr269:
#line 324 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st646;}
    }
#line 280 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st646;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
    }
	goto st0;
tr282:
#line 285 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "INFO metadata Number is not a number, A, G or dot"});
        p--; {goto st646;}
    }
#line 280 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st646;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
    }
	goto st0;
tr291:
#line 290 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "INFO metadata Type is not a Integer, Float, Flag, Character or String"});
        p--; {goto st646;}
    }
#line 280 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st646;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
    }
	goto st0;
tr308:
#line 329 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st646;}
    }
#line 280 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st646;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
    }
	goto st0;
tr319:
#line 296 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {goto st646;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
    }
	goto st0;
tr329:
#line 324 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st646;}
    }
#line 296 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {goto st646;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
    }
	goto st0;
tr341:
#line 308 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st646;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
    }
	goto st0;
tr352:
#line 324 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st646;}
    }
#line 308 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st646;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
    }
	goto st0;
tr357:
#line 324 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st646;}
    }
#line 313 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "SAMPLE metadata Genomes is not a valid string (maybe it contains quotes?)"});
        p--; {goto st646;}
    }
#line 308 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st646;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
    }
	goto st0;
tr359:
#line 313 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "SAMPLE metadata Genomes is not a valid string (maybe it contains quotes?)"});
        p--; {goto st646;}
    }
#line 308 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st646;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
    }
	goto st0;
tr369:
#line 313 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "SAMPLE metadata Genomes is not a valid string (maybe it contains quotes?)"});
        p--; {goto st646;}
    }
#line 318 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "SAMPLE metadata Mixture is not a valid string (maybe it contains quotes?)"});
        p--; {goto st646;}
    }
#line 308 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st646;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
    }
	goto st0;
tr372:
#line 318 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "SAMPLE metadata Mixture is not a valid string (maybe it contains quotes?)"});
        p--; {goto st646;}
    }
#line 308 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st646;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
    }
	goto st0;
tr382:
#line 318 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "SAMPLE metadata Mixture is not a valid string (maybe it contains quotes?)"});
        p--; {goto st646;}
    }
#line 329 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st646;}
    }
#line 308 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st646;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
    }
	goto st0;
tr385:
#line 329 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st646;}
    }
#line 308 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st646;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
    }
	goto st0;
tr408:
#line 246 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in assembly metadata"});
        p--; {goto st646;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
    }
	goto st0;
tr417:
#line 334 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata URL is not valid"});
        p--; {goto st646;}
    }
#line 246 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in assembly metadata"});
        p--; {goto st646;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
    }
	goto st0;
tr436:
#line 252 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in contig metadata"});
        p--; {goto st646;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
    }
	goto st0;
tr447:
#line 324 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st646;}
    }
#line 252 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in contig metadata"});
        p--; {goto st646;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
    }
	goto st0;
tr485:
#line 302 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in pedigreeDB metadata"});
        p--; {goto st646;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
    }
	goto st0;
tr497:
#line 334 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata URL is not valid"});
        p--; {goto st646;}
    }
#line 302 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in pedigreeDB metadata"});
        p--; {goto st646;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
    }
	goto st0;
tr517:
#line 340 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new HeaderSectionError{n_lines,
            "The header line does not start with the mandatory columns: CHROM, POS, ID, REF, ALT, QUAL, FILTER and INFO"});
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (MetaSectionError *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
        
        p--; {goto st647;}
    }
#line 78 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new HeaderSectionError{n_lines});
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (MetaSectionError *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
        
        p--; {goto st647;}
    }
	goto st0;
tr556:
#line 78 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new HeaderSectionError{n_lines});
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (MetaSectionError *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
        
        p--; {goto st647;}
    }
	goto st0;
tr568:
#line 357 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new ChromosomeBodyError{n_lines});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	goto st0;
tr571:
#line 363 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new PositionBodyError{n_lines});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	goto st0;
tr575:
#line 369 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new IdBodyError{n_lines});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	goto st0;
tr580:
#line 375 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new ReferenceAlleleBodyError{n_lines});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	goto st0;
tr584:
#line 381 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new AlternateAllelesBodyError{n_lines});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	goto st0;
tr593:
#line 387 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new QualityBodyError{n_lines});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	goto st0;
tr604:
#line 393 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new FilterBodyError{n_lines});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	goto st0;
tr612:
#line 404 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info key is not a sequence of alphanumeric and/or punctuation characters"});
        p--; {goto st647;}
    }
#line 399 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	goto st0;
tr633:
#line 505 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new FormatBodyError{n_lines});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	goto st0;
tr638:
#line 518 "src/vcf/vcf_v41.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " does not start with a valid genotype";
        ErrorPolicy::handle_error(*this, new SamplesBodyError{n_lines, message_stream.str()});
        p--; {goto st647;}
    }
#line 511 "src/vcf/vcf_v41.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " is not a valid string";
        ErrorPolicy::handle_error(*this, new SamplesBodyError{n_lines, message_stream.str()});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	goto st0;
tr642:
#line 511 "src/vcf/vcf_v41.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " is not a valid string";
        ErrorPolicy::handle_error(*this, new SamplesBodyError{n_lines, message_stream.str()});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	goto st0;
tr656:
#line 409 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info field value is not a comma-separated list of valid strings (maybe it contains whitespaces?)"});
        p--; {goto st647;}
    }
#line 399 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	goto st0;
tr658:
#line 499 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info 1000G is not a flag (with 1/0/no value)"});
        p--; {goto st647;}
    }
#line 404 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info key is not a sequence of alphanumeric and/or punctuation characters"});
        p--; {goto st647;}
    }
#line 399 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	goto st0;
tr660:
#line 499 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info 1000G is not a flag (with 1/0/no value)"});
        p--; {goto st647;}
    }
#line 399 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	goto st0;
tr667:
#line 414 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info AA value is not a single dot or a string of bases"});
        p--; {goto st647;}
    }
#line 399 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	goto st0;
tr670:
#line 419 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info AC value is not a comma-separated list of numbers"});
        p--; {goto st647;}
    }
#line 399 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	goto st0;
tr673:
#line 424 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info AF value is not a comma-separated list of numbers"});
        p--; {goto st647;}
    }
#line 399 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	goto st0;
tr687:
#line 429 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info AN value is not an integer number"});
        p--; {goto st647;}
    }
#line 399 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	goto st0;
tr691:
#line 434 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info BQ value is not a number"});
        p--; {goto st647;}
    }
#line 399 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	goto st0;
tr709:
#line 439 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info CIGAR value is not an alphanumeric string compliant with the SAM specification"});
        p--; {goto st647;}
    }
#line 399 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	goto st0;
tr714:
#line 444 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info DB is not a flag (with 1/0/no value)"});
        p--; {goto st647;}
    }
#line 404 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info key is not a sequence of alphanumeric and/or punctuation characters"});
        p--; {goto st647;}
    }
#line 399 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	goto st0;
tr716:
#line 444 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info DB is not a flag (with 1/0/no value)"});
        p--; {goto st647;}
    }
#line 399 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	goto st0;
tr719:
#line 449 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info DP value is not an integer number"});
        p--; {goto st647;}
    }
#line 399 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	goto st0;
tr724:
#line 454 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info END value is not an integer number"});
        p--; {goto st647;}
    }
#line 399 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	goto st0;
tr728:
#line 459 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info H2 is not a flag (with 1/0/no value)"});
        p--; {goto st647;}
    }
#line 404 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info key is not a sequence of alphanumeric and/or punctuation characters"});
        p--; {goto st647;}
    }
#line 399 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	goto st0;
tr730:
#line 459 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info H2 is not a flag (with 1/0/no value)"});
        p--; {goto st647;}
    }
#line 399 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	goto st0;
tr732:
#line 464 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info H3 is not a flag (with 1/0/no value)"});
        p--; {goto st647;}
    }
#line 404 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info key is not a sequence of alphanumeric and/or punctuation characters"});
        p--; {goto st647;}
    }
#line 399 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	goto st0;
tr734:
#line 464 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info H3 is not a flag (with 1/0/no value)"});
        p--; {goto st647;}
    }
#line 399 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	goto st0;
tr740:
#line 474 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info MQ0 value is not an integer number"});
        p--; {goto st647;}
    }
#line 399 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	goto st0;
tr742:
#line 469 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info MQ value is not a number"});
        p--; {goto st647;}
    }
#line 399 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	goto st0;
tr757:
#line 479 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info NS value is not an integer number"});
        p--; {goto st647;}
    }
#line 399 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	goto st0;
tr762:
#line 484 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info SB value is not a number"});
        p--; {goto st647;}
    }
#line 399 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	goto st0;
tr780:
#line 489 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info SOMATIC is not a flag (with 1/0/no value)"});
        p--; {goto st647;}
    }
#line 404 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info key is not a sequence of alphanumeric and/or punctuation characters"});
        p--; {goto st647;}
    }
#line 399 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	goto st0;
tr782:
#line 489 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info SOMATIC is not a flag (with 1/0/no value)"});
        p--; {goto st647;}
    }
#line 399 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	goto st0;
tr792:
#line 494 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info VALIDATED is not a flag (with 1/0/no value)"});
        p--; {goto st647;}
    }
#line 404 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info key is not a sequence of alphanumeric and/or punctuation characters"});
        p--; {goto st647;}
    }
#line 399 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	goto st0;
tr794:
#line 494 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info VALIDATED is not a flag (with 1/0/no value)"});
        p--; {goto st647;}
    }
#line 399 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	goto st0;
tr839:
#line 78 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new HeaderSectionError{n_lines});
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (MetaSectionError *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
        
        p--; {goto st647;}
    }
#line 357 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new ChromosomeBodyError{n_lines});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	goto st0;
#line 1438 "inc/vcf/validator_detail_v41.hpp"
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
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st15;
st15:
	if ( ++p == pe )
		goto _test_eof15;
case 15:
#line 1547 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 67 )
		goto tr16;
	goto tr14;
tr16:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st16;
st16:
	if ( ++p == pe )
		goto _test_eof16;
case 16:
#line 1561 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 70 )
		goto tr17;
	goto tr14;
tr17:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st17;
st17:
	if ( ++p == pe )
		goto _test_eof17;
case 17:
#line 1575 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 118 )
		goto tr18;
	goto tr14;
tr18:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st18;
st18:
	if ( ++p == pe )
		goto _test_eof18;
case 18:
#line 1589 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 52 )
		goto tr19;
	goto tr14;
tr19:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st19;
st19:
	if ( ++p == pe )
		goto _test_eof19;
case 19:
#line 1603 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 46 )
		goto tr20;
	goto tr14;
tr20:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st20;
st20:
	if ( ++p == pe )
		goto _test_eof20;
case 20:
#line 1617 "inc/vcf/validator_detail_v41.hpp"
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
#line 1631 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 10 )
		goto tr22;
	goto tr14;
tr22:
#line 99 "src/vcf/vcf_v41.ragel"
	{
        try {
          ParsePolicy::handle_fileformat(*this);
        } catch (FileformatError *error) {
          ErrorPolicy::handle_error(*this, error);
          p--; {goto st646;}
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
	goto st22;
st22:
	if ( ++p == pe )
		goto _test_eof22;
case 22:
#line 1660 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 35 )
		goto st23;
	goto tr23;
st23:
	if ( ++p == pe )
		goto _test_eof23;
case 23:
	switch( (*p) ) {
		case 35: goto st24;
		case 67: goto st391;
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
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st25;
tr39:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st25;
st25:
	if ( ++p == pe )
		goto _test_eof25;
case 25:
#line 1713 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 61 )
		goto tr40;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr38;
tr40:
#line 168 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this);
    }
	goto st26;
st26:
	if ( ++p == pe )
		goto _test_eof26;
case 26:
#line 1729 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto st29;
		case 60: goto st34;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr38;
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
tr45:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st27;
st27:
	if ( ++p == pe )
		goto _test_eof27;
case 27:
#line 1757 "inc/vcf/validator_detail_v41.hpp"
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
#line 176 "src/vcf/vcf_v41.ragel"
	{
        try {
          ParsePolicy::handle_meta_line(*this);
        } catch (MetaSectionError *error) {
          ErrorPolicy::handle_error(*this, error);
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
#line 176 "src/vcf/vcf_v41.ragel"
	{
        try {
          ParsePolicy::handle_meta_line(*this);
        } catch (MetaSectionError *error) {
          ErrorPolicy::handle_error(*this, error);
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
#line 1811 "inc/vcf/validator_detail_v41.hpp"
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
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st30;
tr49:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st30;
st30:
	if ( ++p == pe )
		goto _test_eof30;
case 30:
#line 1846 "inc/vcf/validator_detail_v41.hpp"
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
#line 1874 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 10 )
		goto tr52;
	goto tr38;
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
tr51:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st32;
st32:
	if ( ++p == pe )
		goto _test_eof32;
case 32:
#line 1898 "inc/vcf/validator_detail_v41.hpp"
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
#line 1920 "inc/vcf/validator_detail_v41.hpp"
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
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st36;
tr60:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st36;
st36:
	if ( ++p == pe )
		goto _test_eof36;
case 36:
#line 1980 "inc/vcf/validator_detail_v41.hpp"
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
#line 2008 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 62 )
		goto st31;
	goto tr38;
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
tr62:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st38;
st38:
	if ( ++p == pe )
		goto _test_eof38;
case 38:
#line 2032 "inc/vcf/validator_detail_v41.hpp"
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
#line 2054 "inc/vcf/validator_detail_v41.hpp"
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
#line 2073 "inc/vcf/validator_detail_v41.hpp"
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
#line 2092 "inc/vcf/validator_detail_v41.hpp"
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
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st42;
tr67:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st42;
st42:
	if ( ++p == pe )
		goto _test_eof42;
case 42:
#line 2127 "inc/vcf/validator_detail_v41.hpp"
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
#line 172 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st43;
st43:
	if ( ++p == pe )
		goto _test_eof43;
case 43:
#line 2154 "inc/vcf/validator_detail_v41.hpp"
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
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st44;
tr71:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st44;
st44:
	if ( ++p == pe )
		goto _test_eof44;
case 44:
#line 2186 "inc/vcf/validator_detail_v41.hpp"
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
#line 2207 "inc/vcf/validator_detail_v41.hpp"
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
#line 2232 "inc/vcf/validator_detail_v41.hpp"
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
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st47;
tr76:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st47;
st47:
	if ( ++p == pe )
		goto _test_eof47;
case 47:
#line 2267 "inc/vcf/validator_detail_v41.hpp"
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
#line 172 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st48;
st48:
	if ( ++p == pe )
		goto _test_eof48;
case 48:
#line 2294 "inc/vcf/validator_detail_v41.hpp"
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
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st50;
tr82:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st50;
st50:
	if ( ++p == pe )
		goto _test_eof50;
case 50:
#line 2337 "inc/vcf/validator_detail_v41.hpp"
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
#line 2365 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 44: goto st45;
		case 62: goto st31;
	}
	goto tr38;
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
tr84:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st52;
st52:
	if ( ++p == pe )
		goto _test_eof52;
case 52:
#line 2391 "inc/vcf/validator_detail_v41.hpp"
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
#line 2413 "inc/vcf/validator_detail_v41.hpp"
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
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st54;
tr87:
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
#line 2453 "inc/vcf/validator_detail_v41.hpp"
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
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st55;
tr91:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st55;
st55:
	if ( ++p == pe )
		goto _test_eof55;
case 55:
#line 2504 "inc/vcf/validator_detail_v41.hpp"
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
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st56;
tr92:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st56;
st56:
	if ( ++p == pe )
		goto _test_eof56;
case 56:
#line 2555 "inc/vcf/validator_detail_v41.hpp"
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
#line 172 "src/vcf/vcf_v41.ragel"
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
#line 2598 "inc/vcf/validator_detail_v41.hpp"
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
#line 2628 "inc/vcf/validator_detail_v41.hpp"
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
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st59;
tr88:
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
#line 2668 "inc/vcf/validator_detail_v41.hpp"
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
#line 2697 "inc/vcf/validator_detail_v41.hpp"
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
#line 2717 "inc/vcf/validator_detail_v41.hpp"
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
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st63;
tr105:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st63;
st63:
	if ( ++p == pe )
		goto _test_eof63;
case 63:
#line 2758 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr83;
		case 92: goto tr106;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr105;
	goto tr38;
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
tr106:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st64;
st64:
	if ( ++p == pe )
		goto _test_eof64;
case 64:
#line 2786 "inc/vcf/validator_detail_v41.hpp"
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
#line 2808 "inc/vcf/validator_detail_v41.hpp"
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
#line 2838 "inc/vcf/validator_detail_v41.hpp"
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
#line 2889 "inc/vcf/validator_detail_v41.hpp"
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
#line 2940 "inc/vcf/validator_detail_v41.hpp"
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
#line 172 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st69;
st69:
	if ( ++p == pe )
		goto _test_eof69;
case 69:
#line 2983 "inc/vcf/validator_detail_v41.hpp"
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
#line 3013 "inc/vcf/validator_detail_v41.hpp"
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
#line 3043 "inc/vcf/validator_detail_v41.hpp"
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
#line 3072 "inc/vcf/validator_detail_v41.hpp"
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
#line 3096 "inc/vcf/validator_detail_v41.hpp"
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
#line 3114 "inc/vcf/validator_detail_v41.hpp"
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
#line 108 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "ALT");
    }
	goto st76;
st76:
	if ( ++p == pe )
		goto _test_eof76;
case 76:
#line 3141 "inc/vcf/validator_detail_v41.hpp"
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
	if ( (*p) == 61 )
		goto tr130;
	if ( (*p) < 63 ) {
		if ( (*p) < 45 ) {
			if ( 33 <= (*p) && (*p) <= 43 )
				goto tr130;
		} else if ( (*p) > 47 ) {
			if ( (*p) > 57 ) {
				if ( 58 <= (*p) && (*p) <= 59 )
					goto tr130;
			} else if ( (*p) >= 48 )
				goto tr131;
		} else
			goto tr130;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr131;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr130;
			} else if ( (*p) >= 97 )
				goto tr131;
		} else
			goto tr130;
	} else
		goto tr130;
	goto tr129;
tr130:
#line 144 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st81;
st81:
	if ( ++p == pe )
		goto _test_eof81;
case 81:
#line 3213 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 61 )
		goto st81;
	if ( (*p) < 63 ) {
		if ( (*p) < 45 ) {
			if ( 33 <= (*p) && (*p) <= 43 )
				goto st81;
		} else if ( (*p) > 47 ) {
			if ( (*p) > 57 ) {
				if ( 58 <= (*p) && (*p) <= 59 )
					goto st81;
			} else if ( (*p) >= 48 )
				goto tr133;
		} else
			goto st81;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr133;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto st81;
			} else if ( (*p) >= 97 )
				goto tr133;
		} else
			goto st81;
	} else
		goto st81;
	goto tr129;
tr133:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st82;
tr131:
#line 144 "src/vcf/vcf_v41.ragel"
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
	goto st82;
st82:
	if ( ++p == pe )
		goto _test_eof82;
case 82:
#line 3267 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 44: goto tr134;
		case 61: goto tr133;
	}
	if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr133;
	} else if ( (*p) >= 33 )
		goto tr133;
	goto tr129;
tr134:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st83;
st83:
	if ( ++p == pe )
		goto _test_eof83;
case 83:
#line 3288 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 68 )
		goto st84;
	goto tr121;
st84:
	if ( ++p == pe )
		goto _test_eof84;
case 84:
	if ( (*p) == 101 )
		goto st85;
	goto tr121;
st85:
	if ( ++p == pe )
		goto _test_eof85;
case 85:
	if ( (*p) == 115 )
		goto st86;
	goto tr121;
st86:
	if ( ++p == pe )
		goto _test_eof86;
case 86:
	if ( (*p) == 99 )
		goto st87;
	goto tr121;
st87:
	if ( ++p == pe )
		goto _test_eof87;
case 87:
	if ( (*p) == 114 )
		goto st88;
	goto tr121;
st88:
	if ( ++p == pe )
		goto _test_eof88;
case 88:
	if ( (*p) == 105 )
		goto st89;
	goto tr121;
st89:
	if ( ++p == pe )
		goto _test_eof89;
case 89:
	if ( (*p) == 112 )
		goto st90;
	goto tr121;
st90:
	if ( ++p == pe )
		goto _test_eof90;
case 90:
	if ( (*p) == 116 )
		goto st91;
	goto tr121;
st91:
	if ( ++p == pe )
		goto _test_eof91;
case 91:
	if ( (*p) == 105 )
		goto st92;
	goto tr121;
st92:
	if ( ++p == pe )
		goto _test_eof92;
case 92:
	if ( (*p) == 111 )
		goto st93;
	goto tr121;
st93:
	if ( ++p == pe )
		goto _test_eof93;
case 93:
	if ( (*p) == 110 )
		goto st94;
	goto tr121;
st94:
	if ( ++p == pe )
		goto _test_eof94;
case 94:
	if ( (*p) == 61 )
		goto st95;
	goto tr121;
st95:
	if ( ++p == pe )
		goto _test_eof95;
case 95:
	if ( (*p) == 34 )
		goto tr147;
	goto tr121;
tr147:
#line 156 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Description");
    }
	goto st96;
st96:
	if ( ++p == pe )
		goto _test_eof96;
case 96:
#line 3386 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr150;
		case 92: goto tr151;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr149;
	goto tr148;
tr149:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st97;
tr152:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st97;
st97:
	if ( ++p == pe )
		goto _test_eof97;
case 97:
#line 3414 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr153;
		case 92: goto tr154;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr152;
	goto tr148;
tr150:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st98;
tr153:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st98;
st98:
	if ( ++p == pe )
		goto _test_eof98;
case 98:
#line 3442 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 62 )
		goto st99;
	goto tr148;
st99:
	if ( ++p == pe )
		goto _test_eof99;
case 99:
	if ( (*p) == 10 )
		goto tr52;
	goto tr121;
tr151:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st100;
tr154:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st100;
st100:
	if ( ++p == pe )
		goto _test_eof100;
case 100:
#line 3473 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr156;
		case 92: goto tr154;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr152;
	goto tr148;
tr156:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st101;
st101:
	if ( ++p == pe )
		goto _test_eof101;
case 101:
#line 3495 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr153;
		case 62: goto tr157;
		case 92: goto tr154;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr152;
	goto tr148;
tr157:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st102;
st102:
	if ( ++p == pe )
		goto _test_eof102;
case 102:
#line 3514 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 10: goto tr52;
		case 34: goto tr153;
		case 92: goto tr154;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr152;
	goto tr148;
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
#line 3537 "inc/vcf/validator_detail_v41.hpp"
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
#line 3556 "inc/vcf/validator_detail_v41.hpp"
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
#line 3574 "inc/vcf/validator_detail_v41.hpp"
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
#line 3592 "inc/vcf/validator_detail_v41.hpp"
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
#line 3610 "inc/vcf/validator_detail_v41.hpp"
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
#line 120 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "FILTER");
    }
	goto st109;
st109:
	if ( ++p == pe )
		goto _test_eof109;
case 109:
#line 3637 "inc/vcf/validator_detail_v41.hpp"
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
#line 144 "src/vcf/vcf_v41.ragel"
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
#line 3694 "inc/vcf/validator_detail_v41.hpp"
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
#line 144 "src/vcf/vcf_v41.ragel"
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
#line 3733 "inc/vcf/validator_detail_v41.hpp"
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
#line 3760 "inc/vcf/validator_detail_v41.hpp"
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
#line 156 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Description");
    }
	goto st129;
st129:
	if ( ++p == pe )
		goto _test_eof129;
case 129:
#line 3858 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr192;
		case 92: goto tr193;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr191;
	goto tr190;
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
tr194:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st130;
st130:
	if ( ++p == pe )
		goto _test_eof130;
case 130:
#line 3886 "inc/vcf/validator_detail_v41.hpp"
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
#line 3914 "inc/vcf/validator_detail_v41.hpp"
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
tr196:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st133;
st133:
	if ( ++p == pe )
		goto _test_eof133;
case 133:
#line 3945 "inc/vcf/validator_detail_v41.hpp"
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
#line 3967 "inc/vcf/validator_detail_v41.hpp"
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
#line 3986 "inc/vcf/validator_detail_v41.hpp"
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
#line 4005 "inc/vcf/validator_detail_v41.hpp"
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
#line 4023 "inc/vcf/validator_detail_v41.hpp"
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
#line 4041 "inc/vcf/validator_detail_v41.hpp"
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
#line 4059 "inc/vcf/validator_detail_v41.hpp"
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
#line 124 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "FORMAT");
    }
	goto st141;
st141:
	if ( ++p == pe )
		goto _test_eof141;
case 141:
#line 4086 "inc/vcf/validator_detail_v41.hpp"
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
#line 144 "src/vcf/vcf_v41.ragel"
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
#line 4143 "inc/vcf/validator_detail_v41.hpp"
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
#line 144 "src/vcf/vcf_v41.ragel"
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
#line 4182 "inc/vcf/validator_detail_v41.hpp"
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
#line 4209 "inc/vcf/validator_detail_v41.hpp"
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
#line 148 "src/vcf/vcf_v41.ragel"
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
#line 4285 "inc/vcf/validator_detail_v41.hpp"
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
#line 4299 "inc/vcf/validator_detail_v41.hpp"
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
#line 152 "src/vcf/vcf_v41.ragel"
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
#line 4365 "inc/vcf/validator_detail_v41.hpp"
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
#line 4384 "inc/vcf/validator_detail_v41.hpp"
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
#line 156 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Description");
    }
	goto st177;
st177:
	if ( ++p == pe )
		goto _test_eof177;
case 177:
#line 4482 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr251;
		case 92: goto tr252;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr250;
	goto tr249;
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
tr253:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st178;
st178:
	if ( ++p == pe )
		goto _test_eof178;
case 178:
#line 4510 "inc/vcf/validator_detail_v41.hpp"
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
#line 4538 "inc/vcf/validator_detail_v41.hpp"
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
tr255:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st181;
st181:
	if ( ++p == pe )
		goto _test_eof181;
case 181:
#line 4569 "inc/vcf/validator_detail_v41.hpp"
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
#line 4591 "inc/vcf/validator_detail_v41.hpp"
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
#line 4610 "inc/vcf/validator_detail_v41.hpp"
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
#line 148 "src/vcf/vcf_v41.ragel"
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
#line 4643 "inc/vcf/validator_detail_v41.hpp"
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
#line 4663 "inc/vcf/validator_detail_v41.hpp"
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
#line 4681 "inc/vcf/validator_detail_v41.hpp"
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
#line 4699 "inc/vcf/validator_detail_v41.hpp"
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
#line 128 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "INFO");
    }
	goto st189;
st189:
	if ( ++p == pe )
		goto _test_eof189;
case 189:
#line 4726 "inc/vcf/validator_detail_v41.hpp"
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
#line 144 "src/vcf/vcf_v41.ragel"
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
#line 4783 "inc/vcf/validator_detail_v41.hpp"
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
#line 144 "src/vcf/vcf_v41.ragel"
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
#line 4822 "inc/vcf/validator_detail_v41.hpp"
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
#line 4849 "inc/vcf/validator_detail_v41.hpp"
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
#line 148 "src/vcf/vcf_v41.ragel"
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
#line 4925 "inc/vcf/validator_detail_v41.hpp"
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
#line 4939 "inc/vcf/validator_detail_v41.hpp"
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
#line 152 "src/vcf/vcf_v41.ragel"
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
#line 5005 "inc/vcf/validator_detail_v41.hpp"
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
#line 5024 "inc/vcf/validator_detail_v41.hpp"
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
#line 156 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Description");
    }
	goto st225;
st225:
	if ( ++p == pe )
		goto _test_eof225;
case 225:
#line 5122 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr310;
		case 92: goto tr311;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr309;
	goto tr308;
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
tr312:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st226;
st226:
	if ( ++p == pe )
		goto _test_eof226;
case 226:
#line 5150 "inc/vcf/validator_detail_v41.hpp"
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
#line 5178 "inc/vcf/validator_detail_v41.hpp"
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
tr314:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st229;
st229:
	if ( ++p == pe )
		goto _test_eof229;
case 229:
#line 5209 "inc/vcf/validator_detail_v41.hpp"
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
#line 5231 "inc/vcf/validator_detail_v41.hpp"
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
#line 5250 "inc/vcf/validator_detail_v41.hpp"
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
#line 148 "src/vcf/vcf_v41.ragel"
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
#line 5283 "inc/vcf/validator_detail_v41.hpp"
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
#line 5303 "inc/vcf/validator_detail_v41.hpp"
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
#line 5321 "inc/vcf/validator_detail_v41.hpp"
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
#line 5339 "inc/vcf/validator_detail_v41.hpp"
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
#line 5357 "inc/vcf/validator_detail_v41.hpp"
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
#line 5375 "inc/vcf/validator_detail_v41.hpp"
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
#line 5393 "inc/vcf/validator_detail_v41.hpp"
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
#line 5411 "inc/vcf/validator_detail_v41.hpp"
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
#line 132 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "PEDIGREE");
    }
	goto st241;
st241:
	if ( ++p == pe )
		goto _test_eof241;
case 241:
#line 5438 "inc/vcf/validator_detail_v41.hpp"
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
#line 5452 "inc/vcf/validator_detail_v41.hpp"
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
#line 5477 "inc/vcf/validator_detail_v41.hpp"
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
tr333:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st244;
st244:
	if ( ++p == pe )
		goto _test_eof244;
case 244:
#line 5512 "inc/vcf/validator_detail_v41.hpp"
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
#line 5539 "inc/vcf/validator_detail_v41.hpp"
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
#line 5564 "inc/vcf/validator_detail_v41.hpp"
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
tr338:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st247;
st247:
	if ( ++p == pe )
		goto _test_eof247;
case 247:
#line 5599 "inc/vcf/validator_detail_v41.hpp"
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
#line 5627 "inc/vcf/validator_detail_v41.hpp"
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
#line 5645 "inc/vcf/validator_detail_v41.hpp"
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
#line 5663 "inc/vcf/validator_detail_v41.hpp"
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
#line 5681 "inc/vcf/validator_detail_v41.hpp"
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
#line 5699 "inc/vcf/validator_detail_v41.hpp"
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
#line 5717 "inc/vcf/validator_detail_v41.hpp"
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
#line 140 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "SAMPLE");
    }
	goto st255;
st255:
	if ( ++p == pe )
		goto _test_eof255;
case 255:
#line 5744 "inc/vcf/validator_detail_v41.hpp"
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
#line 144 "src/vcf/vcf_v41.ragel"
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
#line 5801 "inc/vcf/validator_detail_v41.hpp"
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
#line 144 "src/vcf/vcf_v41.ragel"
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
#line 5840 "inc/vcf/validator_detail_v41.hpp"
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
#line 5867 "inc/vcf/validator_detail_v41.hpp"
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
#line 160 "src/vcf/vcf_v41.ragel"
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
#line 5960 "inc/vcf/validator_detail_v41.hpp"
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
#line 5982 "inc/vcf/validator_detail_v41.hpp"
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
#line 164 "src/vcf/vcf_v41.ragel"
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
#line 6075 "inc/vcf/validator_detail_v41.hpp"
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
#line 6097 "inc/vcf/validator_detail_v41.hpp"
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
#line 156 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Description");
    }
	goto st295;
st295:
	if ( ++p == pe )
		goto _test_eof295;
case 295:
#line 6195 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr400;
		case 92: goto tr401;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr399;
	goto tr385;
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
tr402:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st296;
st296:
	if ( ++p == pe )
		goto _test_eof296;
case 296:
#line 6223 "inc/vcf/validator_detail_v41.hpp"
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
#line 6251 "inc/vcf/validator_detail_v41.hpp"
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
tr404:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st299;
st299:
	if ( ++p == pe )
		goto _test_eof299;
case 299:
#line 6282 "inc/vcf/validator_detail_v41.hpp"
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
#line 6304 "inc/vcf/validator_detail_v41.hpp"
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
#line 6323 "inc/vcf/validator_detail_v41.hpp"
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
#line 6346 "inc/vcf/validator_detail_v41.hpp"
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
#line 6364 "inc/vcf/validator_detail_v41.hpp"
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
#line 6382 "inc/vcf/validator_detail_v41.hpp"
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
#line 6400 "inc/vcf/validator_detail_v41.hpp"
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
#line 6418 "inc/vcf/validator_detail_v41.hpp"
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
#line 6436 "inc/vcf/validator_detail_v41.hpp"
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
#line 6454 "inc/vcf/validator_detail_v41.hpp"
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
#line 112 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "assembly");
    }
	goto st310;
st310:
	if ( ++p == pe )
		goto _test_eof310;
case 310:
#line 6481 "inc/vcf/validator_detail_v41.hpp"
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
#line 6498 "inc/vcf/validator_detail_v41.hpp"
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
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st316;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr424;
	} else
		goto tr424;
	goto tr417;
st316:
	if ( ++p == pe )
		goto _test_eof316;
case 316:
	if ( (*p) == 46 )
		goto st317;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st327;
	goto tr417;
st317:
	if ( ++p == pe )
		goto _test_eof317;
case 317:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st318;
	goto tr417;
st318:
	if ( ++p == pe )
		goto _test_eof318;
case 318:
	if ( (*p) == 46 )
		goto st319;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st325;
	goto tr417;
st319:
	if ( ++p == pe )
		goto _test_eof319;
case 319:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st320;
	goto tr417;
st320:
	if ( ++p == pe )
		goto _test_eof320;
case 320:
	if ( (*p) == 46 )
		goto st321;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st323;
	goto tr417;
st321:
	if ( ++p == pe )
		goto _test_eof321;
case 321:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr424;
	goto tr417;
tr424:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st322;
st322:
	if ( ++p == pe )
		goto _test_eof322;
case 322:
#line 6604 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 10 )
		goto tr44;
	goto tr424;
st323:
	if ( ++p == pe )
		goto _test_eof323;
case 323:
	if ( (*p) == 46 )
		goto st321;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st324;
	goto tr417;
st324:
	if ( ++p == pe )
		goto _test_eof324;
case 324:
	if ( (*p) == 46 )
		goto st321;
	goto tr417;
st325:
	if ( ++p == pe )
		goto _test_eof325;
case 325:
	if ( (*p) == 46 )
		goto st319;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st326;
	goto tr417;
st326:
	if ( ++p == pe )
		goto _test_eof326;
case 326:
	if ( (*p) == 46 )
		goto st319;
	goto tr417;
st327:
	if ( ++p == pe )
		goto _test_eof327;
case 327:
	if ( (*p) == 46 )
		goto st317;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st328;
	goto tr417;
st328:
	if ( ++p == pe )
		goto _test_eof328;
case 328:
	if ( (*p) == 46 )
		goto st317;
	goto tr417;
tr36:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st329;
st329:
	if ( ++p == pe )
		goto _test_eof329;
case 329:
#line 6670 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 111: goto tr437;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr436;
tr437:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st330;
st330:
	if ( ++p == pe )
		goto _test_eof330;
case 330:
#line 6688 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 110: goto tr438;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr436;
tr438:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st331;
st331:
	if ( ++p == pe )
		goto _test_eof331;
case 331:
#line 6706 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 116: goto tr439;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr436;
tr439:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st332;
st332:
	if ( ++p == pe )
		goto _test_eof332;
case 332:
#line 6724 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 105: goto tr440;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr436;
tr440:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st333;
st333:
	if ( ++p == pe )
		goto _test_eof333;
case 333:
#line 6742 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 103: goto st334;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr436;
st334:
	if ( ++p == pe )
		goto _test_eof334;
case 334:
	if ( (*p) == 61 )
		goto tr442;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr436;
tr442:
#line 116 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "contig");
    }
	goto st335;
st335:
	if ( ++p == pe )
		goto _test_eof335;
case 335:
#line 6769 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 60 )
		goto st336;
	goto tr436;
st336:
	if ( ++p == pe )
		goto _test_eof336;
case 336:
	if ( (*p) == 73 )
		goto st337;
	goto tr436;
st337:
	if ( ++p == pe )
		goto _test_eof337;
case 337:
	if ( (*p) == 68 )
		goto st338;
	goto tr436;
st338:
	if ( ++p == pe )
		goto _test_eof338;
case 338:
	if ( (*p) == 61 )
		goto st339;
	goto tr436;
st339:
	if ( ++p == pe )
		goto _test_eof339;
case 339:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr448;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr448;
	} else
		goto tr448;
	goto tr447;
tr449:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st340;
tr448:
#line 144 "src/vcf/vcf_v41.ragel"
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
	goto st340;
st340:
	if ( ++p == pe )
		goto _test_eof340;
case 340:
#line 6831 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 44: goto tr450;
		case 59: goto tr449;
		case 62: goto tr451;
	}
	if ( (*p) > 57 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr449;
	} else if ( (*p) >= 33 )
		goto tr449;
	goto tr447;
tr450:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st341;
st341:
	if ( ++p == pe )
		goto _test_eof341;
case 341:
#line 6853 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 95 )
		goto tr452;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr452;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr453;
		} else if ( (*p) >= 65 )
			goto tr453;
	} else
		goto tr453;
	goto tr436;
tr452:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st342;
st342:
	if ( ++p == pe )
		goto _test_eof342;
case 342:
#line 6878 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 95 )
		goto st342;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st342;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr455;
		} else if ( (*p) >= 65 )
			goto tr455;
	} else
		goto tr455;
	goto tr436;
tr453:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st343;
tr455:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st343;
st343:
	if ( ++p == pe )
		goto _test_eof343;
case 343:
#line 6913 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr456;
		case 95: goto tr455;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr455;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr455;
		} else if ( (*p) >= 65 )
			goto tr455;
	} else
		goto tr455;
	goto tr436;
tr456:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st344;
st344:
	if ( ++p == pe )
		goto _test_eof344;
case 344:
#line 6940 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 34 )
		goto st347;
	if ( (*p) < 45 ) {
		if ( 32 <= (*p) && (*p) <= 43 )
			goto tr457;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr457;
	} else
		goto tr457;
	goto tr436;
tr457:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st345;
tr459:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st345;
st345:
	if ( ++p == pe )
		goto _test_eof345;
case 345:
#line 6972 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 44: goto tr450;
		case 62: goto tr451;
	}
	if ( (*p) > 33 ) {
		if ( 35 <= (*p) && (*p) <= 126 )
			goto tr459;
	} else if ( (*p) >= 32 )
		goto tr459;
	goto tr436;
tr451:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st346;
st346:
	if ( ++p == pe )
		goto _test_eof346;
case 346:
#line 6993 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 10 )
		goto tr52;
	goto tr436;
st347:
	if ( ++p == pe )
		goto _test_eof347;
case 347:
	switch( (*p) ) {
		case 34: goto tr461;
		case 92: goto tr462;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr460;
	goto tr436;
tr460:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st348;
tr463:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st348;
st348:
	if ( ++p == pe )
		goto _test_eof348;
case 348:
#line 7028 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr464;
		case 92: goto tr465;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr463;
	goto tr436;
tr461:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st349;
tr464:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st349;
st349:
	if ( ++p == pe )
		goto _test_eof349;
case 349:
#line 7056 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 44: goto st341;
		case 62: goto st346;
	}
	goto tr436;
tr462:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st350;
tr465:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st350;
st350:
	if ( ++p == pe )
		goto _test_eof350;
case 350:
#line 7082 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr468;
		case 92: goto tr465;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr463;
	goto tr436;
tr468:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st351;
st351:
	if ( ++p == pe )
		goto _test_eof351;
case 351:
#line 7104 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr464;
		case 44: goto tr469;
		case 62: goto tr470;
		case 92: goto tr465;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr463;
	goto tr436;
tr483:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st352;
tr469:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st352;
tr480:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st352;
st352:
	if ( ++p == pe )
		goto _test_eof352;
case 352:
#line 7144 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr464;
		case 47: goto tr463;
		case 92: goto tr465;
		case 95: goto tr471;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr463;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr472;
		} else
			goto tr471;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr472;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr463;
			} else if ( (*p) >= 97 )
				goto tr472;
		} else
			goto tr463;
	} else
		goto tr463;
	goto tr436;
tr471:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st353;
tr473:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st353;
st353:
	if ( ++p == pe )
		goto _test_eof353;
case 353:
#line 7195 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr464;
		case 47: goto tr463;
		case 92: goto tr465;
		case 95: goto tr473;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr463;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr474;
		} else
			goto tr473;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr474;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr463;
			} else if ( (*p) >= 97 )
				goto tr474;
		} else
			goto tr463;
	} else
		goto tr463;
	goto tr436;
tr472:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st354;
tr474:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st354;
st354:
	if ( ++p == pe )
		goto _test_eof354;
case 354:
#line 7246 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr464;
		case 47: goto tr463;
		case 61: goto tr475;
		case 92: goto tr465;
		case 95: goto tr474;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr463;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr463;
		} else
			goto tr474;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr463;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr463;
		} else
			goto tr474;
	} else
		goto tr474;
	goto tr436;
tr475:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st355;
st355:
	if ( ++p == pe )
		goto _test_eof355;
case 355:
#line 7289 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr477;
		case 44: goto tr463;
		case 62: goto tr463;
		case 92: goto tr478;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr476;
	goto tr436;
tr479:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st356;
tr476:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st356;
st356:
	if ( ++p == pe )
		goto _test_eof356;
case 356:
#line 7319 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr464;
		case 44: goto tr480;
		case 62: goto tr481;
		case 92: goto tr482;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr479;
	goto tr436;
tr484:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st357;
tr470:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st357;
tr481:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st357;
st357:
	if ( ++p == pe )
		goto _test_eof357;
case 357:
#line 7359 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 10: goto tr52;
		case 34: goto tr464;
		case 92: goto tr465;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr463;
	goto tr436;
tr482:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st358;
tr478:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st358;
st358:
	if ( ++p == pe )
		goto _test_eof358;
case 358:
#line 7388 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr468;
		case 44: goto tr480;
		case 62: goto tr481;
		case 92: goto tr482;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr479;
	goto tr436;
tr477:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st359;
st359:
	if ( ++p == pe )
		goto _test_eof359;
case 359:
#line 7408 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr461;
		case 44: goto tr483;
		case 62: goto tr484;
		case 92: goto tr462;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr460;
	goto tr436;
tr37:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st360;
st360:
	if ( ++p == pe )
		goto _test_eof360;
case 360:
#line 7432 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 101: goto tr486;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr485;
tr486:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st361;
st361:
	if ( ++p == pe )
		goto _test_eof361;
case 361:
#line 7450 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 100: goto tr487;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr485;
tr487:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st362;
st362:
	if ( ++p == pe )
		goto _test_eof362;
case 362:
#line 7468 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 105: goto tr488;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr485;
tr488:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st363;
st363:
	if ( ++p == pe )
		goto _test_eof363;
case 363:
#line 7486 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 103: goto tr489;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr485;
tr489:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st364;
st364:
	if ( ++p == pe )
		goto _test_eof364;
case 364:
#line 7504 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 114: goto tr490;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr485;
tr490:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st365;
st365:
	if ( ++p == pe )
		goto _test_eof365;
case 365:
#line 7522 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 101: goto tr491;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr485;
tr491:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st366;
st366:
	if ( ++p == pe )
		goto _test_eof366;
case 366:
#line 7540 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 101: goto tr492;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr485;
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
#line 7558 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 68: goto tr493;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr485;
tr493:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st368;
st368:
	if ( ++p == pe )
		goto _test_eof368;
case 368:
#line 7576 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr40;
		case 66: goto st369;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr485;
st369:
	if ( ++p == pe )
		goto _test_eof369;
case 369:
	if ( (*p) == 61 )
		goto tr495;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr485;
tr495:
#line 136 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "pedigreeDB");
    }
	goto st370;
st370:
	if ( ++p == pe )
		goto _test_eof370;
case 370:
#line 7603 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 60 )
		goto st371;
	goto tr485;
st371:
	if ( ++p == pe )
		goto _test_eof371;
case 371:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr498;
	} else if ( (*p) >= 65 )
		goto tr498;
	goto tr497;
tr498:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st372;
st372:
	if ( ++p == pe )
		goto _test_eof372;
case 372:
#line 7627 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 10: goto tr497;
		case 35: goto tr497;
		case 47: goto tr497;
		case 58: goto tr497;
		case 63: goto tr497;
	}
	goto st373;
st373:
	if ( ++p == pe )
		goto _test_eof373;
case 373:
	switch( (*p) ) {
		case 10: goto tr497;
		case 35: goto tr497;
		case 47: goto tr497;
		case 58: goto st374;
		case 63: goto tr497;
	}
	goto st373;
st374:
	if ( ++p == pe )
		goto _test_eof374;
case 374:
	if ( (*p) == 47 )
		goto st375;
	goto tr497;
st375:
	if ( ++p == pe )
		goto _test_eof375;
case 375:
	if ( (*p) == 47 )
		goto st376;
	goto tr497;
st376:
	if ( ++p == pe )
		goto _test_eof376;
case 376:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st377;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr504;
	} else
		goto tr504;
	goto tr497;
st377:
	if ( ++p == pe )
		goto _test_eof377;
case 377:
	if ( (*p) == 46 )
		goto st378;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st389;
	goto tr497;
st378:
	if ( ++p == pe )
		goto _test_eof378;
case 378:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st379;
	goto tr497;
st379:
	if ( ++p == pe )
		goto _test_eof379;
case 379:
	if ( (*p) == 46 )
		goto st380;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st387;
	goto tr497;
st380:
	if ( ++p == pe )
		goto _test_eof380;
case 380:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st381;
	goto tr497;
st381:
	if ( ++p == pe )
		goto _test_eof381;
case 381:
	if ( (*p) == 46 )
		goto st382;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st385;
	goto tr497;
st382:
	if ( ++p == pe )
		goto _test_eof382;
case 382:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr504;
	goto tr497;
tr504:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st383;
st383:
	if ( ++p == pe )
		goto _test_eof383;
case 383:
#line 7733 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 10: goto tr497;
		case 62: goto tr513;
	}
	goto tr504;
tr513:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st384;
st384:
	if ( ++p == pe )
		goto _test_eof384;
case 384:
#line 7753 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 10: goto tr52;
		case 62: goto tr513;
	}
	goto tr504;
st385:
	if ( ++p == pe )
		goto _test_eof385;
case 385:
	if ( (*p) == 46 )
		goto st382;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st386;
	goto tr497;
st386:
	if ( ++p == pe )
		goto _test_eof386;
case 386:
	if ( (*p) == 46 )
		goto st382;
	goto tr497;
st387:
	if ( ++p == pe )
		goto _test_eof387;
case 387:
	if ( (*p) == 46 )
		goto st380;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st388;
	goto tr497;
st388:
	if ( ++p == pe )
		goto _test_eof388;
case 388:
	if ( (*p) == 46 )
		goto st380;
	goto tr497;
st389:
	if ( ++p == pe )
		goto _test_eof389;
case 389:
	if ( (*p) == 46 )
		goto st378;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st390;
	goto tr497;
st390:
	if ( ++p == pe )
		goto _test_eof390;
case 390:
	if ( (*p) == 46 )
		goto st378;
	goto tr497;
st391:
	if ( ++p == pe )
		goto _test_eof391;
case 391:
	if ( (*p) == 72 )
		goto st392;
	goto tr517;
st392:
	if ( ++p == pe )
		goto _test_eof392;
case 392:
	if ( (*p) == 82 )
		goto st393;
	goto tr517;
st393:
	if ( ++p == pe )
		goto _test_eof393;
case 393:
	if ( (*p) == 79 )
		goto st394;
	goto tr517;
st394:
	if ( ++p == pe )
		goto _test_eof394;
case 394:
	if ( (*p) == 77 )
		goto st395;
	goto tr517;
st395:
	if ( ++p == pe )
		goto _test_eof395;
case 395:
	if ( (*p) == 9 )
		goto st396;
	goto tr517;
st396:
	if ( ++p == pe )
		goto _test_eof396;
case 396:
	if ( (*p) == 80 )
		goto st397;
	goto tr517;
st397:
	if ( ++p == pe )
		goto _test_eof397;
case 397:
	if ( (*p) == 79 )
		goto st398;
	goto tr517;
st398:
	if ( ++p == pe )
		goto _test_eof398;
case 398:
	if ( (*p) == 83 )
		goto st399;
	goto tr517;
st399:
	if ( ++p == pe )
		goto _test_eof399;
case 399:
	if ( (*p) == 9 )
		goto st400;
	goto tr517;
st400:
	if ( ++p == pe )
		goto _test_eof400;
case 400:
	if ( (*p) == 73 )
		goto st401;
	goto tr517;
st401:
	if ( ++p == pe )
		goto _test_eof401;
case 401:
	if ( (*p) == 68 )
		goto st402;
	goto tr517;
st402:
	if ( ++p == pe )
		goto _test_eof402;
case 402:
	if ( (*p) == 9 )
		goto st403;
	goto tr517;
st403:
	if ( ++p == pe )
		goto _test_eof403;
case 403:
	if ( (*p) == 82 )
		goto st404;
	goto tr517;
st404:
	if ( ++p == pe )
		goto _test_eof404;
case 404:
	if ( (*p) == 69 )
		goto st405;
	goto tr517;
st405:
	if ( ++p == pe )
		goto _test_eof405;
case 405:
	if ( (*p) == 70 )
		goto st406;
	goto tr517;
st406:
	if ( ++p == pe )
		goto _test_eof406;
case 406:
	if ( (*p) == 9 )
		goto st407;
	goto tr517;
st407:
	if ( ++p == pe )
		goto _test_eof407;
case 407:
	if ( (*p) == 65 )
		goto st408;
	goto tr517;
st408:
	if ( ++p == pe )
		goto _test_eof408;
case 408:
	if ( (*p) == 76 )
		goto st409;
	goto tr517;
st409:
	if ( ++p == pe )
		goto _test_eof409;
case 409:
	if ( (*p) == 84 )
		goto st410;
	goto tr517;
st410:
	if ( ++p == pe )
		goto _test_eof410;
case 410:
	if ( (*p) == 9 )
		goto st411;
	goto tr517;
st411:
	if ( ++p == pe )
		goto _test_eof411;
case 411:
	if ( (*p) == 81 )
		goto st412;
	goto tr517;
st412:
	if ( ++p == pe )
		goto _test_eof412;
case 412:
	if ( (*p) == 85 )
		goto st413;
	goto tr517;
st413:
	if ( ++p == pe )
		goto _test_eof413;
case 413:
	if ( (*p) == 65 )
		goto st414;
	goto tr517;
st414:
	if ( ++p == pe )
		goto _test_eof414;
case 414:
	if ( (*p) == 76 )
		goto st415;
	goto tr517;
st415:
	if ( ++p == pe )
		goto _test_eof415;
case 415:
	if ( (*p) == 9 )
		goto st416;
	goto tr517;
st416:
	if ( ++p == pe )
		goto _test_eof416;
case 416:
	if ( (*p) == 70 )
		goto st417;
	goto tr517;
st417:
	if ( ++p == pe )
		goto _test_eof417;
case 417:
	if ( (*p) == 73 )
		goto st418;
	goto tr517;
st418:
	if ( ++p == pe )
		goto _test_eof418;
case 418:
	if ( (*p) == 76 )
		goto st419;
	goto tr517;
st419:
	if ( ++p == pe )
		goto _test_eof419;
case 419:
	if ( (*p) == 84 )
		goto st420;
	goto tr517;
st420:
	if ( ++p == pe )
		goto _test_eof420;
case 420:
	if ( (*p) == 69 )
		goto st421;
	goto tr517;
st421:
	if ( ++p == pe )
		goto _test_eof421;
case 421:
	if ( (*p) == 82 )
		goto st422;
	goto tr517;
st422:
	if ( ++p == pe )
		goto _test_eof422;
case 422:
	if ( (*p) == 9 )
		goto st423;
	goto tr517;
st423:
	if ( ++p == pe )
		goto _test_eof423;
case 423:
	if ( (*p) == 73 )
		goto st424;
	goto tr517;
st424:
	if ( ++p == pe )
		goto _test_eof424;
case 424:
	if ( (*p) == 78 )
		goto st425;
	goto tr517;
st425:
	if ( ++p == pe )
		goto _test_eof425;
case 425:
	if ( (*p) == 70 )
		goto st426;
	goto tr517;
st426:
	if ( ++p == pe )
		goto _test_eof426;
case 426:
	if ( (*p) == 79 )
		goto st427;
	goto tr517;
st427:
	if ( ++p == pe )
		goto _test_eof427;
case 427:
	switch( (*p) ) {
		case 9: goto st428;
		case 10: goto tr555;
	}
	goto tr517;
st428:
	if ( ++p == pe )
		goto _test_eof428;
case 428:
	if ( (*p) == 70 )
		goto st429;
	goto tr556;
st429:
	if ( ++p == pe )
		goto _test_eof429;
case 429:
	if ( (*p) == 79 )
		goto st430;
	goto tr556;
st430:
	if ( ++p == pe )
		goto _test_eof430;
case 430:
	if ( (*p) == 82 )
		goto st431;
	goto tr556;
st431:
	if ( ++p == pe )
		goto _test_eof431;
case 431:
	if ( (*p) == 77 )
		goto st432;
	goto tr556;
st432:
	if ( ++p == pe )
		goto _test_eof432;
case 432:
	if ( (*p) == 65 )
		goto st433;
	goto tr556;
st433:
	if ( ++p == pe )
		goto _test_eof433;
case 433:
	if ( (*p) == 84 )
		goto st434;
	goto tr556;
st434:
	if ( ++p == pe )
		goto _test_eof434;
case 434:
	if ( (*p) == 9 )
		goto st435;
	goto tr556;
tr565:
#line 184 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_sample_name(*this);
    }
	goto st435;
st435:
	if ( ++p == pe )
		goto _test_eof435;
case 435:
#line 8127 "inc/vcf/validator_detail_v41.hpp"
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr564;
	goto tr556;
tr564:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st436;
tr567:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st436;
st436:
	if ( ++p == pe )
		goto _test_eof436;
case 436:
#line 8151 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr565;
		case 10: goto tr566;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr567;
	goto tr556;
tr555:
#line 188 "src/vcf/vcf_v41.ragel"
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
	goto st648;
tr566:
#line 184 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_sample_name(*this);
    }
#line 188 "src/vcf/vcf_v41.ragel"
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
	goto st648;
st648:
	if ( ++p == pe )
		goto _test_eof648;
case 648:
#line 8199 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 10: goto tr840;
		case 60: goto tr842;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr841;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr841;
	} else
		goto tr841;
	goto tr839;
tr840:
#line 70 "src/vcf/vcf_v41.ragel"
	{
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (MetaSectionError *warn) {
          ErrorPolicy::handle_warning(*this, warn);
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
	goto st649;
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
	goto st649;
st649:
	if ( ++p == pe )
		goto _test_eof649;
case 649:
#line 8249 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 10 )
		goto tr843;
	goto st0;
tr845:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st437;
tr570:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st437;
tr841:
#line 70 "src/vcf/vcf_v41.ragel"
	{
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (MetaSectionError *warn) {
          ErrorPolicy::handle_warning(*this, warn);
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
	goto st437;
st437:
	if ( ++p == pe )
		goto _test_eof437;
case 437:
#line 8291 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr569;
		case 59: goto tr570;
		case 61: goto tr570;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr570;
	} else if ( (*p) > 57 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr570;
	} else
		goto tr570;
	goto tr568;
tr569:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 194 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 53 "src/vcf/vcf_v41.ragel"
	{
        ++n_columns;
    }
	goto st438;
tr648:
#line 194 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 53 "src/vcf/vcf_v41.ragel"
	{
        ++n_columns;
    }
	goto st438;
st438:
	if ( ++p == pe )
		goto _test_eof438;
case 438:
#line 8334 "inc/vcf/validator_detail_v41.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr572;
	goto tr571;
tr572:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st439;
tr574:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st439;
st439:
	if ( ++p == pe )
		goto _test_eof439;
case 439:
#line 8358 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 9 )
		goto tr573;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr574;
	goto tr571;
tr579:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st440;
tr573:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 194 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 53 "src/vcf/vcf_v41.ragel"
	{
        ++n_columns;
    }
	goto st440;
st440:
	if ( ++p == pe )
		goto _test_eof440;
case 440:
#line 8388 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr576;
	} else if ( (*p) >= 33 )
		goto tr576;
	goto tr575;
tr576:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st441;
tr578:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st441;
st441:
	if ( ++p == pe )
		goto _test_eof441;
case 441:
#line 8415 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr577;
		case 59: goto tr579;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr578;
	goto tr575;
tr577:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 194 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 53 "src/vcf/vcf_v41.ragel"
	{
        ++n_columns;
    }
	goto st442;
st442:
	if ( ++p == pe )
		goto _test_eof442;
case 442:
#line 8441 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 65: goto tr581;
		case 67: goto tr581;
		case 71: goto tr581;
		case 78: goto tr581;
		case 84: goto tr581;
		case 97: goto tr581;
		case 99: goto tr581;
		case 103: goto tr581;
		case 110: goto tr581;
		case 116: goto tr581;
	}
	goto tr580;
tr581:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st443;
tr583:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st443;
st443:
	if ( ++p == pe )
		goto _test_eof443;
case 443:
#line 8475 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr582;
		case 65: goto tr583;
		case 67: goto tr583;
		case 71: goto tr583;
		case 78: goto tr583;
		case 84: goto tr583;
		case 97: goto tr583;
		case 99: goto tr583;
		case 103: goto tr583;
		case 110: goto tr583;
		case 116: goto tr583;
	}
	goto tr580;
tr582:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 194 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 53 "src/vcf/vcf_v41.ragel"
	{
        ++n_columns;
    }
	goto st444;
st444:
	if ( ++p == pe )
		goto _test_eof444;
case 444:
#line 8508 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 42: goto tr585;
		case 46: goto tr586;
		case 60: goto tr587;
		case 65: goto tr588;
		case 67: goto tr588;
		case 71: goto tr588;
		case 78: goto tr588;
		case 84: goto tr588;
		case 91: goto tr589;
		case 93: goto tr590;
		case 97: goto tr588;
		case 99: goto tr588;
		case 103: goto tr588;
		case 110: goto tr588;
		case 116: goto tr588;
	}
	goto tr584;
tr585:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st445;
tr806:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st445;
st445:
	if ( ++p == pe )
		goto _test_eof445;
case 445:
#line 8547 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr591;
		case 44: goto tr592;
	}
	goto tr584;
tr591:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 194 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 53 "src/vcf/vcf_v41.ragel"
	{
        ++n_columns;
    }
	goto st446;
st446:
	if ( ++p == pe )
		goto _test_eof446;
case 446:
#line 8571 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 43: goto tr594;
		case 45: goto tr594;
		case 46: goto tr595;
		case 73: goto tr597;
		case 78: goto tr598;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr596;
	goto tr593;
tr594:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st447;
st447:
	if ( ++p == pe )
		goto _test_eof447;
case 447:
#line 8596 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 73 )
		goto tr600;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr599;
	goto tr593;
tr596:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st448;
tr599:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st448;
st448:
	if ( ++p == pe )
		goto _test_eof448;
case 448:
#line 8622 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr601;
		case 46: goto tr602;
		case 69: goto tr603;
		case 101: goto tr603;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr599;
	goto tr593;
tr601:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 194 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 53 "src/vcf/vcf_v41.ragel"
	{
        ++n_columns;
    }
	goto st449;
st449:
	if ( ++p == pe )
		goto _test_eof449;
case 449:
#line 8650 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 46: goto tr606;
		case 58: goto tr605;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr605;
		} else if ( (*p) > 57 ) {
			if ( 60 <= (*p) && (*p) <= 64 )
				goto tr605;
		} else
			goto tr607;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr605;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr605;
		} else
			goto tr607;
	} else
		goto tr607;
	goto tr604;
tr605:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st450;
st450:
	if ( ++p == pe )
		goto _test_eof450;
case 450:
#line 8686 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 58 )
		goto st450;
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto st450;
		} else if ( (*p) > 57 ) {
			if ( 60 <= (*p) && (*p) <= 64 )
				goto st450;
		} else
			goto tr609;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st450;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st450;
		} else
			goto tr609;
	} else
		goto tr609;
	goto tr604;
tr607:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st451;
tr609:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st451;
st451:
	if ( ++p == pe )
		goto _test_eof451;
case 451:
#line 8730 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr610;
		case 59: goto tr611;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr609;
	goto tr604;
tr610:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 194 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 53 "src/vcf/vcf_v41.ragel"
	{
        ++n_columns;
    }
	goto st452;
st452:
	if ( ++p == pe )
		goto _test_eof452;
case 452:
#line 8756 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 46: goto tr614;
		case 49: goto tr616;
		case 58: goto tr613;
		case 60: goto tr613;
		case 65: goto tr617;
		case 66: goto tr618;
		case 67: goto tr619;
		case 68: goto tr620;
		case 69: goto tr621;
		case 72: goto tr622;
		case 77: goto tr623;
		case 78: goto tr624;
		case 83: goto tr625;
		case 86: goto tr626;
	}
	if ( (*p) < 70 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr613;
		} else if ( (*p) > 57 ) {
			if ( 62 <= (*p) && (*p) <= 64 )
				goto tr613;
		} else
			goto tr615;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr613;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr613;
		} else
			goto tr615;
	} else
		goto tr615;
	goto tr612;
tr613:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st453;
tr627:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st453;
st453:
	if ( ++p == pe )
		goto _test_eof453;
case 453:
#line 8814 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 58: goto tr627;
		case 60: goto tr627;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr627;
		} else if ( (*p) > 57 ) {
			if ( 62 <= (*p) && (*p) <= 64 )
				goto tr627;
		} else
			goto tr628;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr627;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr627;
		} else
			goto tr628;
	} else
		goto tr628;
	goto tr612;
tr615:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st454;
tr628:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st454;
st454:
	if ( ++p == pe )
		goto _test_eof454;
case 454:
#line 8860 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 10: goto tr630;
		case 59: goto tr631;
		case 61: goto tr632;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr628;
	goto tr612;
tr637:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st455;
tr629:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 194 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 53 "src/vcf/vcf_v41.ragel"
	{
        ++n_columns;
    }
	goto st455;
st455:
	if ( ++p == pe )
		goto _test_eof455;
case 455:
#line 8894 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr634;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr634;
	} else
		goto tr634;
	goto tr633;
tr634:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st456;
tr636:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st456;
st456:
	if ( ++p == pe )
		goto _test_eof456;
case 456:
#line 8924 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr635;
		case 58: goto tr637;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr636;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr636;
	} else
		goto tr636;
	goto tr633;
tr635:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 194 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 53 "src/vcf/vcf_v41.ragel"
	{
        ++n_columns;
    }
	goto st457;
st457:
	if ( ++p == pe )
		goto _test_eof457;
case 457:
#line 8956 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 46 )
		goto tr640;
	if ( (*p) < 48 ) {
		if ( 33 <= (*p) && (*p) <= 47 )
			goto tr639;
	} else if ( (*p) > 57 ) {
		if ( 59 <= (*p) && (*p) <= 126 )
			goto tr639;
	} else
		goto tr641;
	goto tr638;
tr639:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st458;
tr643:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st458;
st458:
	if ( ++p == pe )
		goto _test_eof458;
case 458:
#line 8988 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr635;
		case 10: goto tr630;
		case 58: goto tr644;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr643;
	goto tr642;
tr630:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 194 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 198 "src/vcf/vcf_v41.ragel"
	{
        try {
            // Handle all columns and build record
            ParsePolicy::handle_body_line(*this);

            for (auto & record : *(ParsingState::records)){
                auto duplicated_errors = previous_records.check_duplicates(record);
                for(auto &error_ptr : duplicated_errors) {
                    ErrorPolicy::handle_error(*this, error_ptr.release());
                }
            }

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
#line 43 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st650;
st650:
	if ( ++p == pe )
		goto _test_eof650;
case 650:
#line 9046 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 10: goto tr843;
		case 60: goto st459;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr845;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr845;
	} else
		goto tr845;
	goto tr568;
tr842:
#line 70 "src/vcf/vcf_v41.ragel"
	{
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (MetaSectionError *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
    }
	goto st459;
st459:
	if ( ++p == pe )
		goto _test_eof459;
case 459:
#line 9074 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr645;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr645;
	} else
		goto tr645;
	goto tr568;
tr645:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st460;
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
#line 9104 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 59: goto tr646;
		case 62: goto tr647;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr646;
	} else if ( (*p) > 57 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr646;
	} else
		goto tr646;
	goto tr568;
tr647:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st461;
st461:
	if ( ++p == pe )
		goto _test_eof461;
case 461:
#line 9128 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 9 )
		goto tr648;
	goto tr568;
tr644:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st462;
st462:
	if ( ++p == pe )
		goto _test_eof462;
case 462:
#line 9142 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) > 57 ) {
		if ( 59 <= (*p) && (*p) <= 126 )
			goto tr643;
	} else if ( (*p) >= 33 )
		goto tr643;
	goto tr642;
tr640:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st463;
tr650:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st463;
st463:
	if ( ++p == pe )
		goto _test_eof463;
case 463:
#line 9169 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr635;
		case 10: goto tr630;
		case 47: goto tr649;
		case 58: goto tr644;
		case 124: goto tr649;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr643;
	goto tr638;
tr649:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st464;
st464:
	if ( ++p == pe )
		goto _test_eof464;
case 464:
#line 9190 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr635;
		case 10: goto tr630;
		case 46: goto tr650;
		case 58: goto tr644;
	}
	if ( (*p) < 48 ) {
		if ( 33 <= (*p) && (*p) <= 47 )
			goto tr643;
	} else if ( (*p) > 57 ) {
		if ( 59 <= (*p) && (*p) <= 126 )
			goto tr643;
	} else
		goto tr651;
	goto tr638;
tr641:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st465;
tr651:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st465;
st465:
	if ( ++p == pe )
		goto _test_eof465;
case 465:
#line 9226 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr635;
		case 10: goto tr630;
		case 47: goto tr649;
		case 58: goto tr644;
		case 124: goto tr649;
	}
	if ( (*p) < 48 ) {
		if ( 33 <= (*p) && (*p) <= 46 )
			goto tr643;
	} else if ( (*p) > 57 ) {
		if ( 59 <= (*p) && (*p) <= 126 )
			goto tr643;
	} else
		goto tr651;
	goto tr638;
tr631:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st466;
st466:
	if ( ++p == pe )
		goto _test_eof466;
case 466:
#line 9253 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 49: goto tr616;
		case 58: goto tr613;
		case 60: goto tr613;
		case 65: goto tr617;
		case 66: goto tr618;
		case 67: goto tr619;
		case 68: goto tr620;
		case 69: goto tr621;
		case 72: goto tr622;
		case 77: goto tr623;
		case 78: goto tr624;
		case 83: goto tr625;
		case 86: goto tr626;
	}
	if ( (*p) < 70 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr613;
		} else if ( (*p) > 57 ) {
			if ( 62 <= (*p) && (*p) <= 64 )
				goto tr613;
		} else
			goto tr615;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr613;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr613;
		} else
			goto tr615;
	} else
		goto tr615;
	goto tr612;
tr616:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st467;
st467:
	if ( ++p == pe )
		goto _test_eof467;
case 467:
#line 9304 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 10: goto tr630;
		case 48: goto tr652;
		case 59: goto tr631;
		case 61: goto tr632;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr628;
	goto tr612;
tr652:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st468;
st468:
	if ( ++p == pe )
		goto _test_eof468;
case 468:
#line 9325 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 10: goto tr630;
		case 48: goto tr653;
		case 59: goto tr631;
		case 61: goto tr632;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr628;
	goto tr612;
tr653:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st469;
st469:
	if ( ++p == pe )
		goto _test_eof469;
case 469:
#line 9346 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 10: goto tr630;
		case 48: goto tr654;
		case 59: goto tr631;
		case 61: goto tr632;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr628;
	goto tr612;
tr654:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st470;
st470:
	if ( ++p == pe )
		goto _test_eof470;
case 470:
#line 9367 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 10: goto tr630;
		case 59: goto tr631;
		case 61: goto tr632;
		case 71: goto tr655;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr628;
	goto tr612;
tr632:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st471;
st471:
	if ( ++p == pe )
		goto _test_eof471;
case 471:
#line 9388 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr657;
	} else if ( (*p) >= 33 )
		goto tr657;
	goto tr656;
tr657:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st472;
st472:
	if ( ++p == pe )
		goto _test_eof472;
case 472:
#line 9405 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 10: goto tr630;
		case 59: goto tr631;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr657;
	goto tr656;
tr655:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st473;
st473:
	if ( ++p == pe )
		goto _test_eof473;
case 473:
#line 9424 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 10: goto tr630;
		case 59: goto tr631;
		case 61: goto tr659;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr628;
	goto tr658;
tr659:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st474;
st474:
	if ( ++p == pe )
		goto _test_eof474;
case 474:
#line 9444 "inc/vcf/validator_detail_v41.hpp"
	if ( 48 <= (*p) && (*p) <= 49 )
		goto tr661;
	goto tr660;
tr661:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st475;
st475:
	if ( ++p == pe )
		goto _test_eof475;
case 475:
#line 9458 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 10: goto tr630;
		case 59: goto tr631;
	}
	goto tr660;
tr617:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st476;
st476:
	if ( ++p == pe )
		goto _test_eof476;
case 476:
#line 9479 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 10: goto tr630;
		case 59: goto tr631;
		case 61: goto tr632;
		case 65: goto tr662;
		case 67: goto tr663;
		case 70: goto tr664;
		case 78: goto tr665;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr628;
	goto tr612;
tr662:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st477;
st477:
	if ( ++p == pe )
		goto _test_eof477;
case 477:
#line 9503 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 61 )
		goto tr666;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr628;
	} else if ( (*p) >= 33 )
		goto tr628;
	goto tr612;
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
#line 9522 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 60 )
		goto tr668;
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr668;
	} else if ( (*p) > 58 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto tr668;
	} else
		goto tr668;
	goto tr667;
tr668:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st479;
st479:
	if ( ++p == pe )
		goto _test_eof479;
case 479:
#line 9544 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 10: goto tr630;
		case 59: goto tr631;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr668;
	} else if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto tr668;
	} else
		goto tr668;
	goto tr667;
tr663:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st480;
st480:
	if ( ++p == pe )
		goto _test_eof480;
case 480:
#line 9569 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 61 )
		goto tr669;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr628;
	} else if ( (*p) >= 33 )
		goto tr628;
	goto tr612;
tr669:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st481;
st481:
	if ( ++p == pe )
		goto _test_eof481;
case 481:
#line 9588 "inc/vcf/validator_detail_v41.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr671;
	goto tr670;
tr671:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st482;
st482:
	if ( ++p == pe )
		goto _test_eof482;
case 482:
#line 9602 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 10: goto tr630;
		case 44: goto tr669;
		case 59: goto tr631;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr671;
	goto tr670;
tr664:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st483;
st483:
	if ( ++p == pe )
		goto _test_eof483;
case 483:
#line 9622 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 61 )
		goto tr672;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr628;
	} else if ( (*p) >= 33 )
		goto tr628;
	goto tr612;
tr672:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st484;
st484:
	if ( ++p == pe )
		goto _test_eof484;
case 484:
#line 9641 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 43: goto tr674;
		case 45: goto tr674;
		case 73: goto tr676;
		case 78: goto tr677;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr675;
	goto tr673;
tr674:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st485;
st485:
	if ( ++p == pe )
		goto _test_eof485;
case 485:
#line 9661 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 73 )
		goto tr676;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr675;
	goto tr673;
tr675:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st486;
st486:
	if ( ++p == pe )
		goto _test_eof486;
case 486:
#line 9677 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 10: goto tr630;
		case 44: goto tr672;
		case 46: goto tr678;
		case 59: goto tr631;
		case 69: goto tr679;
		case 101: goto tr679;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr675;
	goto tr673;
tr678:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st487;
st487:
	if ( ++p == pe )
		goto _test_eof487;
case 487:
#line 9700 "inc/vcf/validator_detail_v41.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr680;
	goto tr673;
tr680:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st488;
st488:
	if ( ++p == pe )
		goto _test_eof488;
case 488:
#line 9714 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 10: goto tr630;
		case 44: goto tr672;
		case 59: goto tr631;
		case 69: goto tr679;
		case 101: goto tr679;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr680;
	goto tr673;
tr679:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st489;
st489:
	if ( ++p == pe )
		goto _test_eof489;
case 489:
#line 9736 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 43: goto tr681;
		case 45: goto tr681;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr682;
	goto tr673;
tr681:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st490;
st490:
	if ( ++p == pe )
		goto _test_eof490;
case 490:
#line 9754 "inc/vcf/validator_detail_v41.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr682;
	goto tr673;
tr682:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st491;
st491:
	if ( ++p == pe )
		goto _test_eof491;
case 491:
#line 9768 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 10: goto tr630;
		case 44: goto tr672;
		case 59: goto tr631;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr682;
	goto tr673;
tr676:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st492;
st492:
	if ( ++p == pe )
		goto _test_eof492;
case 492:
#line 9788 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 110 )
		goto tr683;
	goto tr673;
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
#line 9802 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 102 )
		goto tr684;
	goto tr673;
tr684:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st494;
st494:
	if ( ++p == pe )
		goto _test_eof494;
case 494:
#line 9816 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 10: goto tr630;
		case 44: goto tr672;
		case 59: goto tr631;
	}
	goto tr673;
tr677:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st495;
st495:
	if ( ++p == pe )
		goto _test_eof495;
case 495:
#line 9834 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 97 )
		goto tr685;
	goto tr673;
tr685:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st496;
st496:
	if ( ++p == pe )
		goto _test_eof496;
case 496:
#line 9848 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 78 )
		goto tr684;
	goto tr673;
tr665:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st497;
st497:
	if ( ++p == pe )
		goto _test_eof497;
case 497:
#line 9862 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 61 )
		goto tr686;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr628;
	} else if ( (*p) >= 33 )
		goto tr628;
	goto tr612;
tr686:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st498;
st498:
	if ( ++p == pe )
		goto _test_eof498;
case 498:
#line 9881 "inc/vcf/validator_detail_v41.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr688;
	goto tr687;
tr688:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st499;
st499:
	if ( ++p == pe )
		goto _test_eof499;
case 499:
#line 9895 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 10: goto tr630;
		case 59: goto tr631;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr688;
	goto tr687;
tr618:
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
#line 9918 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 10: goto tr630;
		case 59: goto tr631;
		case 61: goto tr632;
		case 81: goto tr689;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr628;
	goto tr612;
tr689:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st501;
st501:
	if ( ++p == pe )
		goto _test_eof501;
case 501:
#line 9939 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 61 )
		goto tr690;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr628;
	} else if ( (*p) >= 33 )
		goto tr628;
	goto tr612;
tr690:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st502;
st502:
	if ( ++p == pe )
		goto _test_eof502;
case 502:
#line 9958 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 43: goto tr692;
		case 45: goto tr692;
		case 73: goto tr694;
		case 78: goto tr695;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr693;
	goto tr691;
tr692:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st503;
st503:
	if ( ++p == pe )
		goto _test_eof503;
case 503:
#line 9978 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 73 )
		goto tr694;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr693;
	goto tr691;
tr693:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st504;
st504:
	if ( ++p == pe )
		goto _test_eof504;
case 504:
#line 9994 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 10: goto tr630;
		case 46: goto tr696;
		case 59: goto tr631;
		case 69: goto tr697;
		case 101: goto tr697;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr693;
	goto tr691;
tr696:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st505;
st505:
	if ( ++p == pe )
		goto _test_eof505;
case 505:
#line 10016 "inc/vcf/validator_detail_v41.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr698;
	goto tr691;
tr698:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st506;
st506:
	if ( ++p == pe )
		goto _test_eof506;
case 506:
#line 10030 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 10: goto tr630;
		case 59: goto tr631;
		case 69: goto tr697;
		case 101: goto tr697;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr698;
	goto tr691;
tr697:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st507;
st507:
	if ( ++p == pe )
		goto _test_eof507;
case 507:
#line 10051 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 43: goto tr699;
		case 45: goto tr699;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr700;
	goto tr691;
tr699:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st508;
st508:
	if ( ++p == pe )
		goto _test_eof508;
case 508:
#line 10069 "inc/vcf/validator_detail_v41.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr700;
	goto tr691;
tr700:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st509;
st509:
	if ( ++p == pe )
		goto _test_eof509;
case 509:
#line 10083 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 10: goto tr630;
		case 59: goto tr631;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr700;
	goto tr691;
tr694:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st510;
st510:
	if ( ++p == pe )
		goto _test_eof510;
case 510:
#line 10102 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 110 )
		goto tr701;
	goto tr691;
tr701:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st511;
st511:
	if ( ++p == pe )
		goto _test_eof511;
case 511:
#line 10116 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 102 )
		goto tr702;
	goto tr691;
tr702:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st512;
st512:
	if ( ++p == pe )
		goto _test_eof512;
case 512:
#line 10130 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 10: goto tr630;
		case 59: goto tr631;
	}
	goto tr691;
tr695:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st513;
st513:
	if ( ++p == pe )
		goto _test_eof513;
case 513:
#line 10147 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 97 )
		goto tr703;
	goto tr691;
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
#line 10161 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 78 )
		goto tr702;
	goto tr691;
tr619:
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
#line 10179 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 10: goto tr630;
		case 59: goto tr631;
		case 61: goto tr632;
		case 73: goto tr704;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr628;
	goto tr612;
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
#line 10200 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 10: goto tr630;
		case 59: goto tr631;
		case 61: goto tr632;
		case 71: goto tr705;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr628;
	goto tr612;
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
#line 10221 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 10: goto tr630;
		case 59: goto tr631;
		case 61: goto tr632;
		case 65: goto tr706;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr628;
	goto tr612;
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
#line 10242 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 10: goto tr630;
		case 59: goto tr631;
		case 61: goto tr632;
		case 82: goto tr707;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr628;
	goto tr612;
tr707:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st519;
st519:
	if ( ++p == pe )
		goto _test_eof519;
case 519:
#line 10263 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 61 )
		goto tr708;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr628;
	} else if ( (*p) >= 33 )
		goto tr628;
	goto tr612;
tr708:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st520;
st520:
	if ( ++p == pe )
		goto _test_eof520;
case 520:
#line 10282 "inc/vcf/validator_detail_v41.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr710;
	goto tr709;
tr710:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st521;
st521:
	if ( ++p == pe )
		goto _test_eof521;
case 521:
#line 10296 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 68: goto tr711;
		case 80: goto tr711;
		case 83: goto tr711;
		case 88: goto tr711;
	}
	if ( (*p) < 72 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr710;
	} else if ( (*p) > 73 ) {
		if ( 77 <= (*p) && (*p) <= 78 )
			goto tr711;
	} else
		goto tr711;
	goto tr709;
tr711:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st522;
st522:
	if ( ++p == pe )
		goto _test_eof522;
case 522:
#line 10322 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 10: goto tr630;
		case 59: goto tr631;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr710;
	goto tr709;
tr620:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st523;
st523:
	if ( ++p == pe )
		goto _test_eof523;
case 523:
#line 10345 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 10: goto tr630;
		case 59: goto tr631;
		case 61: goto tr632;
		case 66: goto tr712;
		case 80: goto tr713;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr628;
	goto tr612;
tr712:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st524;
st524:
	if ( ++p == pe )
		goto _test_eof524;
case 524:
#line 10367 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 10: goto tr630;
		case 59: goto tr631;
		case 61: goto tr715;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr628;
	goto tr714;
tr715:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st525;
st525:
	if ( ++p == pe )
		goto _test_eof525;
case 525:
#line 10387 "inc/vcf/validator_detail_v41.hpp"
	if ( 48 <= (*p) && (*p) <= 49 )
		goto tr717;
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
#line 10401 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 10: goto tr630;
		case 59: goto tr631;
	}
	goto tr716;
tr713:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st527;
st527:
	if ( ++p == pe )
		goto _test_eof527;
case 527:
#line 10418 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 61 )
		goto tr718;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr628;
	} else if ( (*p) >= 33 )
		goto tr628;
	goto tr612;
tr718:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st528;
st528:
	if ( ++p == pe )
		goto _test_eof528;
case 528:
#line 10437 "inc/vcf/validator_detail_v41.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr720;
	goto tr719;
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
#line 10451 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 10: goto tr630;
		case 59: goto tr631;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr720;
	goto tr719;
tr621:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st530;
st530:
	if ( ++p == pe )
		goto _test_eof530;
case 530:
#line 10474 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 10: goto tr630;
		case 59: goto tr631;
		case 61: goto tr632;
		case 78: goto tr721;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr628;
	goto tr612;
tr721:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st531;
st531:
	if ( ++p == pe )
		goto _test_eof531;
case 531:
#line 10495 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 10: goto tr630;
		case 59: goto tr631;
		case 61: goto tr632;
		case 68: goto tr722;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr628;
	goto tr612;
tr722:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st532;
st532:
	if ( ++p == pe )
		goto _test_eof532;
case 532:
#line 10516 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 61 )
		goto tr723;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr628;
	} else if ( (*p) >= 33 )
		goto tr628;
	goto tr612;
tr723:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st533;
st533:
	if ( ++p == pe )
		goto _test_eof533;
case 533:
#line 10535 "inc/vcf/validator_detail_v41.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr725;
	goto tr724;
tr725:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st534;
st534:
	if ( ++p == pe )
		goto _test_eof534;
case 534:
#line 10549 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 10: goto tr630;
		case 59: goto tr631;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr725;
	goto tr724;
tr622:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st535;
st535:
	if ( ++p == pe )
		goto _test_eof535;
case 535:
#line 10572 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 10: goto tr630;
		case 50: goto tr726;
		case 51: goto tr727;
		case 59: goto tr631;
		case 61: goto tr632;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr628;
	goto tr612;
tr726:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st536;
st536:
	if ( ++p == pe )
		goto _test_eof536;
case 536:
#line 10594 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 10: goto tr630;
		case 59: goto tr631;
		case 61: goto tr729;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr628;
	goto tr728;
tr729:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st537;
st537:
	if ( ++p == pe )
		goto _test_eof537;
case 537:
#line 10614 "inc/vcf/validator_detail_v41.hpp"
	if ( 48 <= (*p) && (*p) <= 49 )
		goto tr731;
	goto tr730;
tr731:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st538;
st538:
	if ( ++p == pe )
		goto _test_eof538;
case 538:
#line 10628 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 10: goto tr630;
		case 59: goto tr631;
	}
	goto tr730;
tr727:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st539;
st539:
	if ( ++p == pe )
		goto _test_eof539;
case 539:
#line 10645 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 10: goto tr630;
		case 59: goto tr631;
		case 61: goto tr733;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr628;
	goto tr732;
tr733:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st540;
st540:
	if ( ++p == pe )
		goto _test_eof540;
case 540:
#line 10665 "inc/vcf/validator_detail_v41.hpp"
	if ( 48 <= (*p) && (*p) <= 49 )
		goto tr735;
	goto tr734;
tr735:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st541;
st541:
	if ( ++p == pe )
		goto _test_eof541;
case 541:
#line 10679 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 10: goto tr630;
		case 59: goto tr631;
	}
	goto tr734;
tr623:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st542;
st542:
	if ( ++p == pe )
		goto _test_eof542;
case 542:
#line 10700 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 10: goto tr630;
		case 59: goto tr631;
		case 61: goto tr632;
		case 81: goto tr736;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr628;
	goto tr612;
tr736:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st543;
st543:
	if ( ++p == pe )
		goto _test_eof543;
case 543:
#line 10721 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 48: goto tr737;
		case 61: goto tr738;
	}
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr628;
	} else if ( (*p) >= 33 )
		goto tr628;
	goto tr612;
tr737:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st544;
st544:
	if ( ++p == pe )
		goto _test_eof544;
case 544:
#line 10742 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 61 )
		goto tr739;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr628;
	} else if ( (*p) >= 33 )
		goto tr628;
	goto tr612;
tr739:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st545;
st545:
	if ( ++p == pe )
		goto _test_eof545;
case 545:
#line 10761 "inc/vcf/validator_detail_v41.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr741;
	goto tr740;
tr741:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st546;
st546:
	if ( ++p == pe )
		goto _test_eof546;
case 546:
#line 10775 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 10: goto tr630;
		case 59: goto tr631;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr741;
	goto tr740;
tr738:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st547;
st547:
	if ( ++p == pe )
		goto _test_eof547;
case 547:
#line 10794 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 43: goto tr743;
		case 45: goto tr743;
		case 73: goto tr745;
		case 78: goto tr746;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr744;
	goto tr742;
tr743:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st548;
st548:
	if ( ++p == pe )
		goto _test_eof548;
case 548:
#line 10814 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 73 )
		goto tr745;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr744;
	goto tr742;
tr744:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st549;
st549:
	if ( ++p == pe )
		goto _test_eof549;
case 549:
#line 10830 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 10: goto tr630;
		case 46: goto tr747;
		case 59: goto tr631;
		case 69: goto tr748;
		case 101: goto tr748;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr744;
	goto tr742;
tr747:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st550;
st550:
	if ( ++p == pe )
		goto _test_eof550;
case 550:
#line 10852 "inc/vcf/validator_detail_v41.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr749;
	goto tr742;
tr749:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st551;
st551:
	if ( ++p == pe )
		goto _test_eof551;
case 551:
#line 10866 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 10: goto tr630;
		case 59: goto tr631;
		case 69: goto tr748;
		case 101: goto tr748;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr749;
	goto tr742;
tr748:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st552;
st552:
	if ( ++p == pe )
		goto _test_eof552;
case 552:
#line 10887 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 43: goto tr750;
		case 45: goto tr750;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr751;
	goto tr742;
tr750:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st553;
st553:
	if ( ++p == pe )
		goto _test_eof553;
case 553:
#line 10905 "inc/vcf/validator_detail_v41.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr751;
	goto tr742;
tr751:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st554;
st554:
	if ( ++p == pe )
		goto _test_eof554;
case 554:
#line 10919 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 10: goto tr630;
		case 59: goto tr631;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr751;
	goto tr742;
tr745:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st555;
st555:
	if ( ++p == pe )
		goto _test_eof555;
case 555:
#line 10938 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 110 )
		goto tr752;
	goto tr742;
tr752:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st556;
st556:
	if ( ++p == pe )
		goto _test_eof556;
case 556:
#line 10952 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 102 )
		goto tr753;
	goto tr742;
tr753:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st557;
st557:
	if ( ++p == pe )
		goto _test_eof557;
case 557:
#line 10966 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 10: goto tr630;
		case 59: goto tr631;
	}
	goto tr742;
tr746:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st558;
st558:
	if ( ++p == pe )
		goto _test_eof558;
case 558:
#line 10983 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 97 )
		goto tr754;
	goto tr742;
tr754:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st559;
st559:
	if ( ++p == pe )
		goto _test_eof559;
case 559:
#line 10997 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 78 )
		goto tr753;
	goto tr742;
tr624:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st560;
st560:
	if ( ++p == pe )
		goto _test_eof560;
case 560:
#line 11015 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 10: goto tr630;
		case 59: goto tr631;
		case 61: goto tr632;
		case 83: goto tr755;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr628;
	goto tr612;
tr755:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st561;
st561:
	if ( ++p == pe )
		goto _test_eof561;
case 561:
#line 11036 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 61 )
		goto tr756;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr628;
	} else if ( (*p) >= 33 )
		goto tr628;
	goto tr612;
tr756:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st562;
st562:
	if ( ++p == pe )
		goto _test_eof562;
case 562:
#line 11055 "inc/vcf/validator_detail_v41.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr758;
	goto tr757;
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
#line 11069 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 10: goto tr630;
		case 59: goto tr631;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr758;
	goto tr757;
tr625:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st564;
st564:
	if ( ++p == pe )
		goto _test_eof564;
case 564:
#line 11092 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 10: goto tr630;
		case 59: goto tr631;
		case 61: goto tr632;
		case 66: goto tr759;
		case 79: goto tr760;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr628;
	goto tr612;
tr759:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st565;
st565:
	if ( ++p == pe )
		goto _test_eof565;
case 565:
#line 11114 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 61 )
		goto tr761;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr628;
	} else if ( (*p) >= 33 )
		goto tr628;
	goto tr612;
tr761:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st566;
st566:
	if ( ++p == pe )
		goto _test_eof566;
case 566:
#line 11133 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 43: goto tr763;
		case 45: goto tr763;
		case 73: goto tr765;
		case 78: goto tr766;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr764;
	goto tr762;
tr763:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st567;
st567:
	if ( ++p == pe )
		goto _test_eof567;
case 567:
#line 11153 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 73 )
		goto tr765;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr764;
	goto tr762;
tr764:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st568;
st568:
	if ( ++p == pe )
		goto _test_eof568;
case 568:
#line 11169 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 10: goto tr630;
		case 46: goto tr767;
		case 59: goto tr631;
		case 69: goto tr768;
		case 101: goto tr768;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr764;
	goto tr762;
tr767:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st569;
st569:
	if ( ++p == pe )
		goto _test_eof569;
case 569:
#line 11191 "inc/vcf/validator_detail_v41.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr769;
	goto tr762;
tr769:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st570;
st570:
	if ( ++p == pe )
		goto _test_eof570;
case 570:
#line 11205 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 10: goto tr630;
		case 59: goto tr631;
		case 69: goto tr768;
		case 101: goto tr768;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr769;
	goto tr762;
tr768:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st571;
st571:
	if ( ++p == pe )
		goto _test_eof571;
case 571:
#line 11226 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 43: goto tr770;
		case 45: goto tr770;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr771;
	goto tr762;
tr770:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st572;
st572:
	if ( ++p == pe )
		goto _test_eof572;
case 572:
#line 11244 "inc/vcf/validator_detail_v41.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr771;
	goto tr762;
tr771:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st573;
st573:
	if ( ++p == pe )
		goto _test_eof573;
case 573:
#line 11258 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 10: goto tr630;
		case 59: goto tr631;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr771;
	goto tr762;
tr765:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st574;
st574:
	if ( ++p == pe )
		goto _test_eof574;
case 574:
#line 11277 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 110 )
		goto tr772;
	goto tr762;
tr772:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st575;
st575:
	if ( ++p == pe )
		goto _test_eof575;
case 575:
#line 11291 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 102 )
		goto tr773;
	goto tr762;
tr773:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st576;
st576:
	if ( ++p == pe )
		goto _test_eof576;
case 576:
#line 11305 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 10: goto tr630;
		case 59: goto tr631;
	}
	goto tr762;
tr766:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st577;
st577:
	if ( ++p == pe )
		goto _test_eof577;
case 577:
#line 11322 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 97 )
		goto tr774;
	goto tr762;
tr774:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st578;
st578:
	if ( ++p == pe )
		goto _test_eof578;
case 578:
#line 11336 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 78 )
		goto tr773;
	goto tr762;
tr760:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st579;
st579:
	if ( ++p == pe )
		goto _test_eof579;
case 579:
#line 11350 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 10: goto tr630;
		case 59: goto tr631;
		case 61: goto tr632;
		case 77: goto tr775;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr628;
	goto tr612;
tr775:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st580;
st580:
	if ( ++p == pe )
		goto _test_eof580;
case 580:
#line 11371 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 10: goto tr630;
		case 59: goto tr631;
		case 61: goto tr632;
		case 65: goto tr776;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr628;
	goto tr612;
tr776:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st581;
st581:
	if ( ++p == pe )
		goto _test_eof581;
case 581:
#line 11392 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 10: goto tr630;
		case 59: goto tr631;
		case 61: goto tr632;
		case 84: goto tr777;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr628;
	goto tr612;
tr777:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st582;
st582:
	if ( ++p == pe )
		goto _test_eof582;
case 582:
#line 11413 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 10: goto tr630;
		case 59: goto tr631;
		case 61: goto tr632;
		case 73: goto tr778;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr628;
	goto tr612;
tr778:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st583;
st583:
	if ( ++p == pe )
		goto _test_eof583;
case 583:
#line 11434 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 10: goto tr630;
		case 59: goto tr631;
		case 61: goto tr632;
		case 67: goto tr779;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr628;
	goto tr612;
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
#line 11455 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 10: goto tr630;
		case 59: goto tr631;
		case 61: goto tr781;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr628;
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
#line 11475 "inc/vcf/validator_detail_v41.hpp"
	if ( 48 <= (*p) && (*p) <= 49 )
		goto tr783;
	goto tr782;
tr783:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st586;
st586:
	if ( ++p == pe )
		goto _test_eof586;
case 586:
#line 11489 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 10: goto tr630;
		case 59: goto tr631;
	}
	goto tr782;
tr626:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st587;
st587:
	if ( ++p == pe )
		goto _test_eof587;
case 587:
#line 11510 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 10: goto tr630;
		case 59: goto tr631;
		case 61: goto tr632;
		case 65: goto tr784;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr628;
	goto tr612;
tr784:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st588;
st588:
	if ( ++p == pe )
		goto _test_eof588;
case 588:
#line 11531 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 10: goto tr630;
		case 59: goto tr631;
		case 61: goto tr632;
		case 76: goto tr785;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr628;
	goto tr612;
tr785:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st589;
st589:
	if ( ++p == pe )
		goto _test_eof589;
case 589:
#line 11552 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 10: goto tr630;
		case 59: goto tr631;
		case 61: goto tr632;
		case 73: goto tr786;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr628;
	goto tr612;
tr786:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st590;
st590:
	if ( ++p == pe )
		goto _test_eof590;
case 590:
#line 11573 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 10: goto tr630;
		case 59: goto tr631;
		case 61: goto tr632;
		case 68: goto tr787;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr628;
	goto tr612;
tr787:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st591;
st591:
	if ( ++p == pe )
		goto _test_eof591;
case 591:
#line 11594 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 10: goto tr630;
		case 59: goto tr631;
		case 61: goto tr632;
		case 65: goto tr788;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr628;
	goto tr612;
tr788:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st592;
st592:
	if ( ++p == pe )
		goto _test_eof592;
case 592:
#line 11615 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 10: goto tr630;
		case 59: goto tr631;
		case 61: goto tr632;
		case 84: goto tr789;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr628;
	goto tr612;
tr789:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st593;
st593:
	if ( ++p == pe )
		goto _test_eof593;
case 593:
#line 11636 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 10: goto tr630;
		case 59: goto tr631;
		case 61: goto tr632;
		case 69: goto tr790;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr628;
	goto tr612;
tr790:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st594;
st594:
	if ( ++p == pe )
		goto _test_eof594;
case 594:
#line 11657 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 10: goto tr630;
		case 59: goto tr631;
		case 61: goto tr632;
		case 68: goto tr791;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr628;
	goto tr612;
tr791:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st595;
st595:
	if ( ++p == pe )
		goto _test_eof595;
case 595:
#line 11678 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 10: goto tr630;
		case 59: goto tr631;
		case 61: goto tr793;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr628;
	goto tr792;
tr793:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st596;
st596:
	if ( ++p == pe )
		goto _test_eof596;
case 596:
#line 11698 "inc/vcf/validator_detail_v41.hpp"
	if ( 48 <= (*p) && (*p) <= 49 )
		goto tr795;
	goto tr794;
tr795:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st597;
st597:
	if ( ++p == pe )
		goto _test_eof597;
case 597:
#line 11712 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 10: goto tr630;
		case 59: goto tr631;
	}
	goto tr794;
tr614:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st598;
st598:
	if ( ++p == pe )
		goto _test_eof598;
case 598:
#line 11733 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 10: goto tr630;
		case 58: goto tr627;
		case 60: goto tr627;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr627;
		} else if ( (*p) > 57 ) {
			if ( 62 <= (*p) && (*p) <= 64 )
				goto tr627;
		} else
			goto tr628;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr627;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr627;
		} else
			goto tr628;
	} else
		goto tr628;
	goto tr612;
tr611:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st599;
st599:
	if ( ++p == pe )
		goto _test_eof599;
case 599:
#line 11771 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 58 )
		goto tr605;
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr605;
		} else if ( (*p) > 57 ) {
			if ( 60 <= (*p) && (*p) <= 64 )
				goto tr605;
		} else
			goto tr607;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr605;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr605;
		} else
			goto tr607;
	} else
		goto tr607;
	goto tr604;
tr606:
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
#line 11809 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr610;
		case 58: goto st450;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto st450;
		} else if ( (*p) > 57 ) {
			if ( 60 <= (*p) && (*p) <= 64 )
				goto st450;
		} else
			goto tr609;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st450;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st450;
		} else
			goto tr609;
	} else
		goto tr609;
	goto tr604;
tr602:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st601;
st601:
	if ( ++p == pe )
		goto _test_eof601;
case 601:
#line 11845 "inc/vcf/validator_detail_v41.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr796;
	goto tr593;
tr796:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st602;
st602:
	if ( ++p == pe )
		goto _test_eof602;
case 602:
#line 11859 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr601;
		case 69: goto tr603;
		case 101: goto tr603;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr796;
	goto tr593;
tr603:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st603;
st603:
	if ( ++p == pe )
		goto _test_eof603;
case 603:
#line 11878 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 43: goto tr797;
		case 45: goto tr797;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr798;
	goto tr593;
tr797:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st604;
st604:
	if ( ++p == pe )
		goto _test_eof604;
case 604:
#line 11896 "inc/vcf/validator_detail_v41.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr798;
	goto tr593;
tr798:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st605;
st605:
	if ( ++p == pe )
		goto _test_eof605;
case 605:
#line 11910 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 9 )
		goto tr601;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr798;
	goto tr593;
tr597:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st606;
tr600:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st606;
st606:
	if ( ++p == pe )
		goto _test_eof606;
case 606:
#line 11936 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 110 )
		goto tr799;
	goto tr593;
tr799:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st607;
st607:
	if ( ++p == pe )
		goto _test_eof607;
case 607:
#line 11950 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 102 )
		goto tr800;
	goto tr593;
tr595:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st608;
tr800:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st608;
st608:
	if ( ++p == pe )
		goto _test_eof608;
case 608:
#line 11974 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 9 )
		goto tr601;
	goto tr593;
tr598:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st609;
st609:
	if ( ++p == pe )
		goto _test_eof609;
case 609:
#line 11992 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 97 )
		goto tr801;
	goto tr593;
tr801:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st610;
st610:
	if ( ++p == pe )
		goto _test_eof610;
case 610:
#line 12006 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 78 )
		goto tr800;
	goto tr593;
tr592:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st611;
st611:
	if ( ++p == pe )
		goto _test_eof611;
case 611:
#line 12020 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 42: goto tr585;
		case 46: goto tr802;
		case 60: goto tr587;
		case 65: goto tr588;
		case 67: goto tr588;
		case 71: goto tr588;
		case 78: goto tr588;
		case 84: goto tr588;
		case 91: goto tr589;
		case 93: goto tr590;
		case 97: goto tr588;
		case 99: goto tr588;
		case 103: goto tr588;
		case 110: goto tr588;
		case 116: goto tr588;
	}
	goto tr584;
tr802:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st612;
tr826:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st612;
st612:
	if ( ++p == pe )
		goto _test_eof612;
case 612:
#line 12059 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 65: goto tr803;
		case 67: goto tr803;
		case 71: goto tr803;
		case 78: goto tr803;
		case 84: goto tr803;
		case 97: goto tr803;
		case 99: goto tr803;
		case 103: goto tr803;
		case 110: goto tr803;
		case 116: goto tr803;
	}
	goto tr584;
tr803:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st613;
st613:
	if ( ++p == pe )
		goto _test_eof613;
case 613:
#line 12083 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr591;
		case 44: goto tr592;
		case 65: goto tr803;
		case 67: goto tr803;
		case 71: goto tr803;
		case 78: goto tr803;
		case 84: goto tr803;
		case 97: goto tr803;
		case 99: goto tr803;
		case 103: goto tr803;
		case 110: goto tr803;
		case 116: goto tr803;
	}
	goto tr584;
tr587:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st614;
tr804:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st614;
st614:
	if ( ++p == pe )
		goto _test_eof614;
case 614:
#line 12119 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 61 )
		goto tr804;
	if ( (*p) < 63 ) {
		if ( (*p) < 45 ) {
			if ( 33 <= (*p) && (*p) <= 43 )
				goto tr804;
		} else if ( (*p) > 47 ) {
			if ( (*p) > 57 ) {
				if ( 58 <= (*p) && (*p) <= 59 )
					goto tr804;
			} else if ( (*p) >= 48 )
				goto tr805;
		} else
			goto tr804;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr805;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr804;
			} else if ( (*p) >= 97 )
				goto tr805;
		} else
			goto tr804;
	} else
		goto tr804;
	goto tr584;
tr805:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st615;
st615:
	if ( ++p == pe )
		goto _test_eof615;
case 615:
#line 12159 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 62 )
		goto tr806;
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr805;
	} else if ( (*p) > 59 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr805;
	} else
		goto tr805;
	goto tr584;
tr588:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st616;
tr807:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st616;
st616:
	if ( ++p == pe )
		goto _test_eof616;
case 616:
#line 12191 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr591;
		case 44: goto tr592;
		case 46: goto tr806;
		case 65: goto tr807;
		case 67: goto tr807;
		case 71: goto tr807;
		case 78: goto tr807;
		case 84: goto tr807;
		case 91: goto tr808;
		case 93: goto tr809;
		case 97: goto tr807;
		case 99: goto tr807;
		case 103: goto tr807;
		case 110: goto tr807;
		case 116: goto tr807;
	}
	goto tr584;
tr808:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st617;
st617:
	if ( ++p == pe )
		goto _test_eof617;
case 617:
#line 12220 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 60 )
		goto tr811;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr810;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr810;
	} else
		goto tr810;
	goto tr584;
tr810:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st618;
st618:
	if ( ++p == pe )
		goto _test_eof618;
case 618:
#line 12242 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 58: goto tr812;
		case 61: goto tr810;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr810;
	} else if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr810;
	} else
		goto tr810;
	goto tr584;
tr812:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st619;
st619:
	if ( ++p == pe )
		goto _test_eof619;
case 619:
#line 12266 "inc/vcf/validator_detail_v41.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr813;
	goto tr584;
tr813:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st620;
st620:
	if ( ++p == pe )
		goto _test_eof620;
case 620:
#line 12280 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 91 )
		goto tr806;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr813;
	goto tr584;
tr811:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st621;
st621:
	if ( ++p == pe )
		goto _test_eof621;
case 621:
#line 12296 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr814;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr814;
	} else
		goto tr814;
	goto tr584;
tr814:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st622;
st622:
	if ( ++p == pe )
		goto _test_eof622;
case 622:
#line 12316 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 59: goto tr814;
		case 62: goto tr815;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr814;
	} else if ( (*p) > 57 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr814;
	} else
		goto tr814;
	goto tr584;
tr815:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st623;
st623:
	if ( ++p == pe )
		goto _test_eof623;
case 623:
#line 12340 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 58 )
		goto tr812;
	goto tr584;
tr809:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st624;
st624:
	if ( ++p == pe )
		goto _test_eof624;
case 624:
#line 12354 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 60 )
		goto tr817;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr816;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr816;
	} else
		goto tr816;
	goto tr584;
tr816:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st625;
st625:
	if ( ++p == pe )
		goto _test_eof625;
case 625:
#line 12376 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 58: goto tr818;
		case 61: goto tr816;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr816;
	} else if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr816;
	} else
		goto tr816;
	goto tr584;
tr818:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st626;
st626:
	if ( ++p == pe )
		goto _test_eof626;
case 626:
#line 12400 "inc/vcf/validator_detail_v41.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr819;
	goto tr584;
tr819:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st627;
st627:
	if ( ++p == pe )
		goto _test_eof627;
case 627:
#line 12414 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 93 )
		goto tr806;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr819;
	goto tr584;
tr817:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st628;
st628:
	if ( ++p == pe )
		goto _test_eof628;
case 628:
#line 12430 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr820;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr820;
	} else
		goto tr820;
	goto tr584;
tr820:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st629;
st629:
	if ( ++p == pe )
		goto _test_eof629;
case 629:
#line 12450 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 59: goto tr820;
		case 62: goto tr821;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr820;
	} else if ( (*p) > 57 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr820;
	} else
		goto tr820;
	goto tr584;
tr821:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st630;
st630:
	if ( ++p == pe )
		goto _test_eof630;
case 630:
#line 12474 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 58 )
		goto tr818;
	goto tr584;
tr589:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st631;
st631:
	if ( ++p == pe )
		goto _test_eof631;
case 631:
#line 12492 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 60 )
		goto tr823;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr822;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr822;
	} else
		goto tr822;
	goto tr584;
tr822:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st632;
st632:
	if ( ++p == pe )
		goto _test_eof632;
case 632:
#line 12514 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 58: goto tr824;
		case 61: goto tr822;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr822;
	} else if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr822;
	} else
		goto tr822;
	goto tr584;
tr824:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st633;
st633:
	if ( ++p == pe )
		goto _test_eof633;
case 633:
#line 12538 "inc/vcf/validator_detail_v41.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr825;
	goto tr584;
tr825:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st634;
st634:
	if ( ++p == pe )
		goto _test_eof634;
case 634:
#line 12552 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 91 )
		goto tr826;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr825;
	goto tr584;
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
#line 12568 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr827;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr827;
	} else
		goto tr827;
	goto tr584;
tr827:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st636;
st636:
	if ( ++p == pe )
		goto _test_eof636;
case 636:
#line 12588 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 59: goto tr827;
		case 62: goto tr828;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr827;
	} else if ( (*p) > 57 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr827;
	} else
		goto tr827;
	goto tr584;
tr828:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st637;
st637:
	if ( ++p == pe )
		goto _test_eof637;
case 637:
#line 12612 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 58 )
		goto tr824;
	goto tr584;
tr590:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st638;
st638:
	if ( ++p == pe )
		goto _test_eof638;
case 638:
#line 12630 "inc/vcf/validator_detail_v41.hpp"
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
	goto tr584;
tr829:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st639;
st639:
	if ( ++p == pe )
		goto _test_eof639;
case 639:
#line 12652 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 58: goto tr831;
		case 61: goto tr829;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr829;
	} else if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr829;
	} else
		goto tr829;
	goto tr584;
tr831:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st640;
st640:
	if ( ++p == pe )
		goto _test_eof640;
case 640:
#line 12676 "inc/vcf/validator_detail_v41.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr832;
	goto tr584;
tr832:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st641;
st641:
	if ( ++p == pe )
		goto _test_eof641;
case 641:
#line 12690 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 93 )
		goto tr826;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr832;
	goto tr584;
tr830:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st642;
st642:
	if ( ++p == pe )
		goto _test_eof642;
case 642:
#line 12706 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr833;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr833;
	} else
		goto tr833;
	goto tr584;
tr833:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st643;
st643:
	if ( ++p == pe )
		goto _test_eof643;
case 643:
#line 12726 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 59: goto tr833;
		case 62: goto tr834;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr833;
	} else if ( (*p) > 57 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr833;
	} else
		goto tr833;
	goto tr584;
tr834:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st644;
st644:
	if ( ++p == pe )
		goto _test_eof644;
case 644:
#line 12750 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 58 )
		goto tr831;
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
	goto st645;
st645:
	if ( ++p == pe )
		goto _test_eof645;
case 645:
#line 12768 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr591;
		case 65: goto tr803;
		case 67: goto tr803;
		case 71: goto tr803;
		case 78: goto tr803;
		case 84: goto tr803;
		case 97: goto tr803;
		case 99: goto tr803;
		case 103: goto tr803;
		case 110: goto tr803;
		case 116: goto tr803;
	}
	goto tr584;
st646:
	if ( ++p == pe )
		goto _test_eof646;
case 646:
	if ( (*p) == 10 )
		goto tr836;
	goto st646;
tr836:
#line 43 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
#line 765 "src/vcf/vcf_v41.ragel"
	{ {goto st28;} }
	goto st651;
st651:
	if ( ++p == pe )
		goto _test_eof651;
case 651:
#line 12808 "inc/vcf/validator_detail_v41.hpp"
	goto st0;
st647:
	if ( ++p == pe )
		goto _test_eof647;
case 647:
	if ( (*p) == 10 )
		goto tr838;
	goto st647;
tr838:
#line 43 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
#line 766 "src/vcf/vcf_v41.ragel"
	{ {goto st650;} }
	goto st652;
st652:
	if ( ++p == pe )
		goto _test_eof652;
case 652:
#line 12835 "inc/vcf/validator_detail_v41.hpp"
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
	_test_eof648: cs = 648; goto _test_eof; 
	_test_eof649: cs = 649; goto _test_eof; 
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
	_test_eof650: cs = 650; goto _test_eof; 
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
	_test_eof651: cs = 651; goto _test_eof; 
	_test_eof647: cs = 647; goto _test_eof; 
	_test_eof652: cs = 652; goto _test_eof; 

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
        ErrorPolicy::handle_error(*this, new FileformatError{n_lines});
        p--; {goto st646;}
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
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
    }
	break;
	case 648: 
#line 70 "src/vcf/vcf_v41.ragel"
	{
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (MetaSectionError *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
    }
	break;
	case 428: 
	case 429: 
	case 430: 
	case 431: 
	case 432: 
	case 433: 
	case 434: 
	case 435: 
	case 436: 
#line 78 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new HeaderSectionError{n_lines});
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (MetaSectionError *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
        
        p--; {goto st647;}
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
#line 227 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this,
            new FileformatError{n_lines, "The fileformat declaration is not 'fileformat=VCFv4.1'"});
        p--; {goto st646;}
    }
#line 60 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new FileformatError{n_lines});
        p--; {goto st646;}
    }
	break;
	case 73: 
	case 74: 
	case 75: 
	case 76: 
	case 77: 
	case 78: 
	case 79: 
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
	case 95: 
	case 99: 
#line 234 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {goto st646;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
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
#line 246 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in assembly metadata"});
        p--; {goto st646;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
    }
	break;
	case 329: 
	case 330: 
	case 331: 
	case 332: 
	case 333: 
	case 334: 
	case 335: 
	case 336: 
	case 337: 
	case 338: 
	case 341: 
	case 342: 
	case 343: 
	case 344: 
	case 345: 
	case 346: 
	case 347: 
	case 348: 
	case 349: 
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
#line 252 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in contig metadata"});
        p--; {goto st646;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
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
#line 258 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {goto st646;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
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
#line 264 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st646;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
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
#line 280 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st646;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
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
#line 296 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {goto st646;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
    }
	break;
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
#line 302 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in pedigreeDB metadata"});
        p--; {goto st646;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
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
#line 308 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st646;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
    }
	break;
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
	case 422: 
	case 423: 
	case 424: 
	case 425: 
	case 426: 
	case 427: 
#line 340 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new HeaderSectionError{n_lines,
            "The header line does not start with the mandatory columns: CHROM, POS, ID, REF, ALT, QUAL, FILTER and INFO"});
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (MetaSectionError *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
        
        p--; {goto st647;}
    }
#line 78 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new HeaderSectionError{n_lines});
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (MetaSectionError *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
        
        p--; {goto st647;}
    }
	break;
	case 437: 
	case 459: 
	case 460: 
	case 461: 
#line 357 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new ChromosomeBodyError{n_lines});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	break;
	case 438: 
	case 439: 
#line 363 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new PositionBodyError{n_lines});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	break;
	case 440: 
	case 441: 
#line 369 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new IdBodyError{n_lines});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	break;
	case 442: 
	case 443: 
#line 375 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new ReferenceAlleleBodyError{n_lines});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	break;
	case 444: 
	case 445: 
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
#line 381 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new AlternateAllelesBodyError{n_lines});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	break;
	case 446: 
	case 447: 
	case 448: 
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
#line 387 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new QualityBodyError{n_lines});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	break;
	case 449: 
	case 450: 
	case 451: 
	case 599: 
	case 600: 
#line 393 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new FilterBodyError{n_lines});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	break;
	case 455: 
	case 456: 
#line 505 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new FormatBodyError{n_lines});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	break;
	case 458: 
	case 462: 
#line 511 "src/vcf/vcf_v41.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " is not a valid string";
        ErrorPolicy::handle_error(*this, new SamplesBodyError{n_lines, message_stream.str()});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	break;
	case 23: 
	case 28: 
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
    }
#line 340 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new HeaderSectionError{n_lines,
            "The header line does not start with the mandatory columns: CHROM, POS, ID, REF, ALT, QUAL, FILTER and INFO"});
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (MetaSectionError *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
        
        p--; {goto st647;}
    }
#line 78 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new HeaderSectionError{n_lines});
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (MetaSectionError *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
        
        p--; {goto st647;}
    }
	break;
	case 80: 
	case 81: 
	case 82: 
#line 239 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines,
            "ALT metadata ID is not prefixed by DEL/INS/DUP/INV/CNV and suffixed by ':' and a text sequence"});
        p--; {goto st646;}
    }
#line 234 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {goto st646;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
    }
	break;
	case 103: 
#line 258 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {goto st646;}
    }
#line 264 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st646;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
    }
	break;
	case 155: 
	case 156: 
	case 184: 
#line 269 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "FORMAT metadata Number is not a number, A, G or dot"});
        p--; {goto st646;}
    }
#line 264 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st646;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
    }
	break;
	case 203: 
	case 204: 
	case 232: 
#line 285 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "INFO metadata Number is not a number, A, G or dot"});
        p--; {goto st646;}
    }
#line 280 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st646;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
    }
	break;
	case 162: 
	case 163: 
#line 290 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "INFO metadata Type is not a Integer, Float, Flag, Character or String"});
        p--; {goto st646;}
    }
#line 264 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st646;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
    }
	break;
	case 210: 
	case 211: 
#line 290 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "INFO metadata Type is not a Integer, Float, Flag, Character or String"});
        p--; {goto st646;}
    }
#line 280 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st646;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
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
#line 313 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "SAMPLE metadata Genomes is not a valid string (maybe it contains quotes?)"});
        p--; {goto st646;}
    }
#line 308 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st646;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
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
#line 318 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "SAMPLE metadata Mixture is not a valid string (maybe it contains quotes?)"});
        p--; {goto st646;}
    }
#line 308 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st646;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
    }
	break;
	case 339: 
	case 340: 
#line 324 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st646;}
    }
#line 252 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in contig metadata"});
        p--; {goto st646;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
    }
	break;
	case 113: 
	case 114: 
	case 115: 
#line 324 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st646;}
    }
#line 258 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {goto st646;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
    }
	break;
	case 145: 
	case 146: 
	case 147: 
#line 324 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st646;}
    }
#line 264 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st646;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
    }
	break;
	case 193: 
	case 194: 
	case 195: 
#line 324 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st646;}
    }
#line 280 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st646;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
    }
	break;
	case 242: 
	case 243: 
	case 244: 
	case 245: 
	case 246: 
	case 247: 
#line 324 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st646;}
    }
#line 296 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {goto st646;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
    }
	break;
	case 259: 
	case 260: 
#line 324 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st646;}
    }
#line 308 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st646;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
    }
	break;
	case 96: 
	case 97: 
	case 98: 
	case 100: 
	case 101: 
	case 102: 
#line 329 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st646;}
    }
#line 234 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {goto st646;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
    }
	break;
	case 129: 
	case 130: 
	case 131: 
	case 133: 
	case 134: 
	case 135: 
#line 329 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st646;}
    }
#line 258 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {goto st646;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
    }
	break;
	case 177: 
	case 178: 
	case 179: 
	case 181: 
	case 182: 
	case 183: 
#line 329 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st646;}
    }
#line 264 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st646;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
    }
	break;
	case 225: 
	case 226: 
	case 227: 
	case 229: 
	case 230: 
	case 231: 
#line 329 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st646;}
    }
#line 280 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st646;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
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
#line 329 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st646;}
    }
#line 308 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st646;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
    }
	break;
	case 310: 
	case 311: 
	case 312: 
	case 313: 
	case 314: 
	case 315: 
	case 316: 
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
	case 327: 
	case 328: 
#line 334 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata URL is not valid"});
        p--; {goto st646;}
    }
#line 246 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in assembly metadata"});
        p--; {goto st646;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
    }
	break;
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
#line 334 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata URL is not valid"});
        p--; {goto st646;}
    }
#line 302 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in pedigreeDB metadata"});
        p--; {goto st646;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
    }
	break;
	case 452: 
	case 453: 
	case 454: 
	case 466: 
	case 467: 
	case 468: 
	case 469: 
	case 470: 
	case 476: 
	case 477: 
	case 480: 
	case 483: 
	case 497: 
	case 500: 
	case 501: 
	case 515: 
	case 516: 
	case 517: 
	case 518: 
	case 519: 
	case 523: 
	case 527: 
	case 530: 
	case 531: 
	case 532: 
	case 535: 
	case 542: 
	case 543: 
	case 544: 
	case 560: 
	case 561: 
	case 564: 
	case 565: 
	case 579: 
	case 580: 
	case 581: 
	case 582: 
	case 583: 
	case 587: 
	case 588: 
	case 589: 
	case 590: 
	case 591: 
	case 592: 
	case 593: 
	case 594: 
	case 598: 
#line 404 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info key is not a sequence of alphanumeric and/or punctuation characters"});
        p--; {goto st647;}
    }
#line 399 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	break;
	case 471: 
	case 472: 
#line 409 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info field value is not a comma-separated list of valid strings (maybe it contains whitespaces?)"});
        p--; {goto st647;}
    }
#line 399 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	break;
	case 478: 
	case 479: 
#line 414 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info AA value is not a single dot or a string of bases"});
        p--; {goto st647;}
    }
#line 399 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	break;
	case 481: 
	case 482: 
#line 419 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info AC value is not a comma-separated list of numbers"});
        p--; {goto st647;}
    }
#line 399 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	break;
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
#line 424 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info AF value is not a comma-separated list of numbers"});
        p--; {goto st647;}
    }
#line 399 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	break;
	case 498: 
	case 499: 
#line 429 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info AN value is not an integer number"});
        p--; {goto st647;}
    }
#line 399 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
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
	case 511: 
	case 512: 
	case 513: 
	case 514: 
#line 434 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info BQ value is not a number"});
        p--; {goto st647;}
    }
#line 399 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	break;
	case 520: 
	case 521: 
	case 522: 
#line 439 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info CIGAR value is not an alphanumeric string compliant with the SAM specification"});
        p--; {goto st647;}
    }
#line 399 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	break;
	case 525: 
	case 526: 
#line 444 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info DB is not a flag (with 1/0/no value)"});
        p--; {goto st647;}
    }
#line 399 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	break;
	case 528: 
	case 529: 
#line 449 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info DP value is not an integer number"});
        p--; {goto st647;}
    }
#line 399 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	break;
	case 533: 
	case 534: 
#line 454 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info END value is not an integer number"});
        p--; {goto st647;}
    }
#line 399 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	break;
	case 537: 
	case 538: 
#line 459 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info H2 is not a flag (with 1/0/no value)"});
        p--; {goto st647;}
    }
#line 399 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	break;
	case 540: 
	case 541: 
#line 464 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info H3 is not a flag (with 1/0/no value)"});
        p--; {goto st647;}
    }
#line 399 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	break;
	case 547: 
	case 548: 
	case 549: 
	case 550: 
	case 551: 
	case 552: 
	case 553: 
	case 554: 
	case 555: 
	case 556: 
	case 557: 
	case 558: 
	case 559: 
#line 469 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info MQ value is not a number"});
        p--; {goto st647;}
    }
#line 399 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	break;
	case 545: 
	case 546: 
#line 474 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info MQ0 value is not an integer number"});
        p--; {goto st647;}
    }
#line 399 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	break;
	case 562: 
	case 563: 
#line 479 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info NS value is not an integer number"});
        p--; {goto st647;}
    }
#line 399 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	break;
	case 566: 
	case 567: 
	case 568: 
	case 569: 
	case 570: 
	case 571: 
	case 572: 
	case 573: 
	case 574: 
	case 575: 
	case 576: 
	case 577: 
	case 578: 
#line 484 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info SB value is not a number"});
        p--; {goto st647;}
    }
#line 399 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	break;
	case 585: 
	case 586: 
#line 489 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info SOMATIC is not a flag (with 1/0/no value)"});
        p--; {goto st647;}
    }
#line 399 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	break;
	case 596: 
	case 597: 
#line 494 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info VALIDATED is not a flag (with 1/0/no value)"});
        p--; {goto st647;}
    }
#line 399 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	break;
	case 474: 
	case 475: 
#line 499 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info 1000G is not a flag (with 1/0/no value)"});
        p--; {goto st647;}
    }
#line 399 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	break;
	case 457: 
	case 463: 
	case 464: 
	case 465: 
#line 518 "src/vcf/vcf_v41.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " does not start with a valid genotype";
        ErrorPolicy::handle_error(*this, new SamplesBodyError{n_lines, message_stream.str()});
        p--; {goto st647;}
    }
#line 511 "src/vcf/vcf_v41.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " is not a valid string";
        ErrorPolicy::handle_error(*this, new SamplesBodyError{n_lines, message_stream.str()});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	break;
	case 22: 
#line 60 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new FileformatError{n_lines});
        p--; {goto st646;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
    }
#line 340 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new HeaderSectionError{n_lines,
            "The header line does not start with the mandatory columns: CHROM, POS, ID, REF, ALT, QUAL, FILTER and INFO"});
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (MetaSectionError *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
        
        p--; {goto st647;}
    }
#line 78 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new HeaderSectionError{n_lines});
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (MetaSectionError *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
        
        p--; {goto st647;}
    }
	break;
	case 271: 
#line 313 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "SAMPLE metadata Genomes is not a valid string (maybe it contains quotes?)"});
        p--; {goto st646;}
    }
#line 318 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "SAMPLE metadata Mixture is not a valid string (maybe it contains quotes?)"});
        p--; {goto st646;}
    }
#line 308 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st646;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
    }
	break;
	case 281: 
#line 318 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "SAMPLE metadata Mixture is not a valid string (maybe it contains quotes?)"});
        p--; {goto st646;}
    }
#line 329 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st646;}
    }
#line 308 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st646;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
    }
	break;
	case 261: 
#line 324 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st646;}
    }
#line 313 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "SAMPLE metadata Genomes is not a valid string (maybe it contains quotes?)"});
        p--; {goto st646;}
    }
#line 308 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st646;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
    }
	break;
	case 524: 
#line 444 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info DB is not a flag (with 1/0/no value)"});
        p--; {goto st647;}
    }
#line 404 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info key is not a sequence of alphanumeric and/or punctuation characters"});
        p--; {goto st647;}
    }
#line 399 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	break;
	case 536: 
#line 459 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info H2 is not a flag (with 1/0/no value)"});
        p--; {goto st647;}
    }
#line 404 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info key is not a sequence of alphanumeric and/or punctuation characters"});
        p--; {goto st647;}
    }
#line 399 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	break;
	case 539: 
#line 464 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info H3 is not a flag (with 1/0/no value)"});
        p--; {goto st647;}
    }
#line 404 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info key is not a sequence of alphanumeric and/or punctuation characters"});
        p--; {goto st647;}
    }
#line 399 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	break;
	case 584: 
#line 489 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info SOMATIC is not a flag (with 1/0/no value)"});
        p--; {goto st647;}
    }
#line 404 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info key is not a sequence of alphanumeric and/or punctuation characters"});
        p--; {goto st647;}
    }
#line 399 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	break;
	case 595: 
#line 494 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info VALIDATED is not a flag (with 1/0/no value)"});
        p--; {goto st647;}
    }
#line 404 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info key is not a sequence of alphanumeric and/or punctuation characters"});
        p--; {goto st647;}
    }
#line 399 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	break;
	case 473: 
#line 499 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info 1000G is not a flag (with 1/0/no value)"});
        p--; {goto st647;}
    }
#line 404 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info key is not a sequence of alphanumeric and/or punctuation characters"});
        p--; {goto st647;}
    }
#line 399 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st647;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st647;}
    }
	break;
	case 24: 
#line 234 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {goto st646;}
    }
#line 258 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {goto st646;}
    }
#line 264 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st646;}
    }
#line 280 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st646;}
    }
#line 246 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in assembly metadata"});
        p--; {goto st646;}
    }
#line 252 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in contig metadata"});
        p--; {goto st646;}
    }
#line 308 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st646;}
    }
#line 296 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {goto st646;}
    }
#line 302 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in pedigreeDB metadata"});
        p--; {goto st646;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st646;}
    }
	break;
#line 15403 "inc/vcf/validator_detail_v41.hpp"
	}
	}

	_out: {}
	}

#line 797 "src/vcf/vcf_v41.ragel"

    }
   
  }
}
