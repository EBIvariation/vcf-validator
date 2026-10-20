
#line 1 "src/vcf/vcf_v45.ragel"
/**
 * Copyright 2014-2026 EMBL - European Bioinformatics Institute
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


#line 267 "src/vcf/vcf_v45.ragel"


namespace
{
  
#line 27 "inc/vcf/validator_detail_v45.hpp"
static const int vcf_v45_start = 1;
static const int vcf_v45_first_final = 626;
static const int vcf_v45_error = 0;

static const int vcf_v45_en_main = 1;
static const int vcf_v45_en_main_meta_section = 28;
static const int vcf_v45_en_main_body_section = 630;
static const int vcf_v45_en_meta_section_skip = 624;
static const int vcf_v45_en_body_section_skip = 625;


#line 273 "src/vcf/vcf_v45.ragel"

}

namespace ebi
{
  namespace vcf
  {
    
    template <typename Configuration>
    ParserImpl_v45<Configuration>::ParserImpl_v45(std::shared_ptr<Source> source, AdditionalChecks additionalChecks)
    : ParserImpl{source, additionalChecks}
    {
      
#line 53 "inc/vcf/validator_detail_v45.hpp"
	{
	cs = vcf_v45_start;
	}

#line 287 "src/vcf/vcf_v45.ragel"

    }

    template <typename Configuration>
    void ParserImpl_v45<Configuration>::parse_buffer(char const * p, char const * pe, char const * eof)
    {
      
#line 66 "inc/vcf/validator_detail_v45.hpp"
	{
	if ( p == pe )
		goto _test_eof;
	switch ( cs )
	{
	/* fall through */
case 1:
	if ( (*p) == 35 )
		goto st2;
	goto tr0;
tr0:
#line 60 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new FileformatError{n_lines});
        p--; {goto st624;}
    }
	goto st0;
tr14:
#line 29 "src/vcf/vcf_v45.ragel"
	{
        ErrorPolicy::handle_error(*this,
                new FileformatError{n_lines, "The fileformat declaration is not 'fileformat=VCFv4.5'"});
        p--; {goto st624;}
    }
#line 60 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new FileformatError{n_lines});
        p--; {goto st624;}
    }
	goto st0;
tr24:
#line 60 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new FileformatError{n_lines});
        p--; {goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st624;}
    }
#line 391 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new HeaderSectionError{n_lines,
            "The header line does not start with the mandatory columns: CHROM, POS, ID, REF, ALT, QUAL, FILTER and INFO"});
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (Error *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
        
        p--; {goto st625;}
    }
#line 78 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new HeaderSectionError{n_lines});
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (Error *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
        
        p--; {goto st625;}
    }
	goto st0;
tr26:
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st624;}
    }
#line 391 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new HeaderSectionError{n_lines,
            "The header line does not start with the mandatory columns: CHROM, POS, ID, REF, ALT, QUAL, FILTER and INFO"});
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (Error *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
        
        p--; {goto st625;}
    }
#line 78 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new HeaderSectionError{n_lines});
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (Error *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
        
        p--; {goto st625;}
    }
	goto st0;
tr29:
#line 259 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {goto st624;}
    }
#line 283 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {goto st624;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st624;}
    }
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st624;}
    }
#line 271 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in assembly metadata"});
        p--; {goto st624;}
    }
#line 277 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in contig metadata"});
        p--; {goto st624;}
    }
#line 338 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
        p--; {goto st624;}
    }
#line 359 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st624;}
    }
#line 311 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {goto st624;}
    }
#line 332 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in pedigreeDB metadata"});
        p--; {goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st624;}
    }
	goto st0;
tr40:
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st624;}
    }
	goto st0;
tr126:
#line 259 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st624;}
    }
	goto st0;
tr134:
#line 264 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines,
               "ALT metadata ID is not prefixed by DEL/INS/DUP/INV/CNV" + (source->version < Version::v44 ? std::string("/BND") : std::string("")) + " and suffixed by ':' and a text sequence"});
        p--; {goto st624;}
    }
#line 259 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st624;}
    }
	goto st0;
tr141:
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {goto st624;}
    }
#line 259 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st624;}
    }
	goto st0;
tr148:
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st624;}
    }
#line 259 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st624;}
    }
	goto st0;
tr160:
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {goto st624;}
    }
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st624;}
    }
#line 259 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st624;}
    }
	goto st0;
tr169:
#line 283 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {goto st624;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st624;}
    }
	goto st0;
tr172:
#line 283 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st624;}
    }
	goto st0;
tr182:
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {goto st624;}
    }
#line 283 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st624;}
    }
	goto st0;
tr195:
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st624;}
    }
#line 283 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st624;}
    }
	goto st0;
tr207:
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {goto st624;}
    }
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st624;}
    }
#line 283 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st624;}
    }
	goto st0;
tr216:
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st624;}
    }
	goto st0;
tr226:
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {goto st624;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st624;}
    }
	goto st0;
tr239:
#line 36 "src/vcf/vcf_v45.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "FORMAT metadata Number is not a number, A, R, G, P, LA, LR, LG, M or dot"});
        p--; {goto st624;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st624;}
    }
	goto st0;
tr249:
#line 305 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "INFO metadata Type is not Integer, Float, Flag, Character or String"});
        p--; {goto st624;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st624;}
    }
	goto st0;
tr266:
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st624;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st624;}
    }
	goto st0;
tr288:
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {goto st624;}
    }
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st624;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st624;}
    }
	goto st0;
tr300:
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st624;}
    }
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {goto st624;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st624;}
    }
	goto st0;
tr308:
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st624;}
    }
	goto st0;
tr317:
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {goto st624;}
    }
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st624;}
    }
	goto st0;
tr330:
#line 42 "src/vcf/vcf_v45.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "INFO metadata Number is not a number, A, R, G or dot"});
        p--; {goto st624;}
    }
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st624;}
    }
	goto st0;
tr339:
#line 305 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "INFO metadata Type is not Integer, Float, Flag, Character or String"});
        p--; {goto st624;}
    }
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st624;}
    }
	goto st0;
tr356:
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st624;}
    }
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st624;}
    }
	goto st0;
tr378:
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {goto st624;}
    }
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st624;}
    }
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st624;}
    }
	goto st0;
tr390:
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st624;}
    }
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {goto st624;}
    }
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st624;}
    }
	goto st0;
tr397:
#line 338 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
        p--; {goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st624;}
    }
	goto st0;
tr406:
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {goto st624;}
    }
#line 338 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
        p--; {goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st624;}
    }
	goto st0;
tr419:
#line 343 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "META metadata Number is not a dot"});
        p--; {goto st624;}
    }
#line 338 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
        p--; {goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st624;}
    }
	goto st0;
tr427:
#line 348 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "META metadata Type is not String"});
        p--; {goto st624;}
    }
#line 338 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
        p--; {goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st624;}
    }
	goto st0;
tr444:
#line 353 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "META metadata Values is not a square-bracket delimited list of values"});
        p--; {goto st624;}
    }
#line 338 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
        p--; {goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st624;}
    }
	goto st0;
tr450:
#line 311 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st624;}
    }
	goto st0;
tr463:
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {goto st624;}
    }
#line 311 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st624;}
    }
	goto st0;
tr469:
#line 326 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "PEDIGREE metadata sequence of Name_N is not valid"});
        p--; {goto st624;}
    }
#line 311 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st624;}
    }
	goto st0;
tr479:
#line 321 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "PEDIGREE metadata Father or Mother is not valid"});
        p--; {goto st624;}
    }
#line 311 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st624;}
    }
	goto st0;
tr516:
#line 316 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "PEDIGREE metadata Original is not valid"});
        p--; {goto st624;}
    }
#line 311 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st624;}
    }
	goto st0;
tr521:
#line 359 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st624;}
    }
	goto st0;
tr532:
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {goto st624;}
    }
#line 359 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st624;}
    }
	goto st0;
tr572:
#line 271 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in assembly metadata"});
        p--; {goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st624;}
    }
	goto st0;
tr581:
#line 385 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata URL is not valid"});
        p--; {goto st624;}
    }
#line 271 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in assembly metadata"});
        p--; {goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st624;}
    }
	goto st0;
tr602:
#line 277 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in contig metadata"});
        p--; {goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st624;}
    }
	goto st0;
tr613:
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {goto st624;}
    }
#line 277 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in contig metadata"});
        p--; {goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st624;}
    }
	goto st0;
tr651:
#line 332 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in pedigreeDB metadata"});
        p--; {goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st624;}
    }
	goto st0;
tr663:
#line 385 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata URL is not valid"});
        p--; {goto st624;}
    }
#line 332 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in pedigreeDB metadata"});
        p--; {goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st624;}
    }
	goto st0;
tr686:
#line 391 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new HeaderSectionError{n_lines,
            "The header line does not start with the mandatory columns: CHROM, POS, ID, REF, ALT, QUAL, FILTER and INFO"});
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (Error *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
        
        p--; {goto st625;}
    }
#line 78 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new HeaderSectionError{n_lines});
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (Error *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
        
        p--; {goto st625;}
    }
	goto st0;
tr726:
#line 78 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new HeaderSectionError{n_lines});
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (Error *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
        
        p--; {goto st625;}
    }
	goto st0;
tr741:
#line 408 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new ChromosomeBodyError{n_lines});
        p--; {goto st625;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st625;}
    }
	goto st0;
tr744:
#line 414 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new PositionBodyError{n_lines});
        p--; {goto st625;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st625;}
    }
	goto st0;
tr748:
#line 420 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new IdBodyError{n_lines});
        p--; {goto st625;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st625;}
    }
	goto st0;
tr753:
#line 426 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new ReferenceAlleleBodyError{n_lines});
        p--; {goto st625;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st625;}
    }
	goto st0;
tr757:
#line 432 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new AlternateAllelesBodyError{n_lines});
        p--; {goto st625;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st625;}
    }
	goto st0;
tr766:
#line 438 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new QualityBodyError{n_lines});
        p--; {goto st625;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st625;}
    }
	goto st0;
tr777:
#line 444 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new FilterBodyError{n_lines});
        p--; {goto st625;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st625;}
    }
	goto st0;
tr785:
#line 455 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info key is not a sequence of alphanumeric and/or punctuation characters"});
        p--; {goto st625;}
    }
#line 450 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st625;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st625;}
    }
	goto st0;
tr789:
#line 50 "src/vcf/vcf_v45.ragel"
	{
        ErrorPolicy::handle_error(*this, new FormatBodyError{n_lines, "Format does not start with a letter/underscore followed by alphanumeric/underscore/dot characters"});
        p--; {goto st625;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st625;}
    }
	goto st0;
tr794:
#line 473 "src/vcf/vcf.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " does not start with a valid genotype";
        ErrorPolicy::handle_error(*this, new SamplesFieldBodyError{n_lines, message_stream.str(), "", "GT"});
        p--; {goto st625;}
    }
#line 466 "src/vcf/vcf.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " is not a valid string";
        ErrorPolicy::handle_error(*this, new SamplesBodyError{n_lines, message_stream.str()});
        p--; {goto st625;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st625;}
    }
	goto st0;
tr802:
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st625;}
    }
	goto st0;
tr804:
#line 466 "src/vcf/vcf.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " is not a valid string";
        ErrorPolicy::handle_error(*this, new SamplesBodyError{n_lines, message_stream.str()});
        p--; {goto st625;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st625;}
    }
	goto st0;
tr810:
#line 460 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info field value is not a comma-separated list of valid strings (maybe it contains whitespaces?)"});
        p--; {goto st625;}
    }
#line 450 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st625;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st625;}
    }
	goto st0;
tr868:
#line 78 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new HeaderSectionError{n_lines});
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (Error *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
        
        p--; {goto st625;}
    }
#line 408 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new ChromosomeBodyError{n_lines});
        p--; {goto st625;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st625;}
    }
	goto st0;
tr875:
#line 450 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st625;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st625;}
    }
	goto st0;
#line 1182 "inc/vcf/validator_detail_v45.hpp"
st0:
cs = 0;
	goto _out;
st2:
	if ( ++p == pe )
		goto _test_eof2;
	/* fall through */
case 2:
	if ( (*p) == 35 )
		goto st3;
	goto tr0;
st3:
	if ( ++p == pe )
		goto _test_eof3;
	/* fall through */
case 3:
	if ( (*p) == 102 )
		goto st4;
	goto tr0;
st4:
	if ( ++p == pe )
		goto _test_eof4;
	/* fall through */
case 4:
	if ( (*p) == 105 )
		goto st5;
	goto tr0;
st5:
	if ( ++p == pe )
		goto _test_eof5;
	/* fall through */
case 5:
	if ( (*p) == 108 )
		goto st6;
	goto tr0;
st6:
	if ( ++p == pe )
		goto _test_eof6;
	/* fall through */
case 6:
	if ( (*p) == 101 )
		goto st7;
	goto tr0;
st7:
	if ( ++p == pe )
		goto _test_eof7;
	/* fall through */
case 7:
	if ( (*p) == 102 )
		goto st8;
	goto tr0;
st8:
	if ( ++p == pe )
		goto _test_eof8;
	/* fall through */
case 8:
	if ( (*p) == 111 )
		goto st9;
	goto tr0;
st9:
	if ( ++p == pe )
		goto _test_eof9;
	/* fall through */
case 9:
	if ( (*p) == 114 )
		goto st10;
	goto tr0;
st10:
	if ( ++p == pe )
		goto _test_eof10;
	/* fall through */
case 10:
	if ( (*p) == 109 )
		goto st11;
	goto tr0;
st11:
	if ( ++p == pe )
		goto _test_eof11;
	/* fall through */
case 11:
	if ( (*p) == 97 )
		goto st12;
	goto tr0;
st12:
	if ( ++p == pe )
		goto _test_eof12;
	/* fall through */
case 12:
	if ( (*p) == 116 )
		goto st13;
	goto tr0;
st13:
	if ( ++p == pe )
		goto _test_eof13;
	/* fall through */
case 13:
	if ( (*p) == 61 )
		goto st14;
	goto tr0;
st14:
	if ( ++p == pe )
		goto _test_eof14;
	/* fall through */
case 14:
	if ( (*p) == 86 )
		goto tr15;
	goto tr14;
tr15:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st15;
st15:
	if ( ++p == pe )
		goto _test_eof15;
	/* fall through */
case 15:
#line 1305 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 67 )
		goto tr16;
	goto tr14;
tr16:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st16;
st16:
	if ( ++p == pe )
		goto _test_eof16;
	/* fall through */
case 16:
#line 1320 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 70 )
		goto tr17;
	goto tr14;
tr17:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st17;
st17:
	if ( ++p == pe )
		goto _test_eof17;
	/* fall through */
case 17:
#line 1335 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 118 )
		goto tr18;
	goto tr14;
tr18:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st18;
st18:
	if ( ++p == pe )
		goto _test_eof18;
	/* fall through */
case 18:
#line 1350 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 52 )
		goto tr19;
	goto tr14;
tr19:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st19;
st19:
	if ( ++p == pe )
		goto _test_eof19;
	/* fall through */
case 19:
#line 1365 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 46 )
		goto tr20;
	goto tr14;
tr20:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st20;
st20:
	if ( ++p == pe )
		goto _test_eof20;
	/* fall through */
case 20:
#line 1380 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 53 )
		goto tr21;
	goto tr14;
tr21:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st21;
st21:
	if ( ++p == pe )
		goto _test_eof21;
	/* fall through */
case 21:
#line 1395 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 10: goto tr22;
		case 13: goto tr23;
	}
	goto tr14;
tr22:
#line 99 "src/vcf/vcf.ragel"
	{
        try {
          ParsePolicy::handle_fileformat(*this);
        } catch (Error *error) {
          ErrorPolicy::handle_error(*this, error);
          p--; {goto st624;}
        }
    }
#line 43 "src/vcf/vcf.ragel"
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
	/* fall through */
case 22:
#line 1427 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 35 )
		goto st23;
	goto tr24;
st23:
	if ( ++p == pe )
		goto _test_eof23;
	/* fall through */
case 23:
	switch( (*p) ) {
		case 35: goto st24;
		case 67: goto st488;
	}
	goto tr26;
st24:
	if ( ++p == pe )
		goto _test_eof24;
	/* fall through */
case 24:
	switch( (*p) ) {
		case 65: goto tr31;
		case 70: goto tr32;
		case 73: goto tr33;
		case 77: goto tr34;
		case 80: goto tr35;
		case 83: goto tr36;
		case 97: goto tr37;
		case 99: goto tr38;
		case 112: goto tr39;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto tr30;
	} else if ( (*p) >= 32 )
		goto tr30;
	goto tr29;
tr30:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st25;
tr41:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st25;
st25:
	if ( ++p == pe )
		goto _test_eof25;
	/* fall through */
case 25:
#line 1484 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 61 )
		goto tr42;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr40;
tr42:
#line 188 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this);
    }
	goto st26;
st26:
	if ( ++p == pe )
		goto _test_eof26;
	/* fall through */
case 26:
#line 1501 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto st30;
		case 60: goto st35;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr43;
	goto tr40;
tr43:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st27;
tr48:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st27;
st27:
	if ( ++p == pe )
		goto _test_eof27;
	/* fall through */
case 27:
#line 1530 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 10: goto tr46;
		case 13: goto tr47;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr48;
	goto tr40;
tr46:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 196 "src/vcf/vcf.ragel"
	{
        try {
          ParsePolicy::handle_meta_line(*this);
        } catch (Error *error) {
          ErrorPolicy::handle_error(*this, error);
        }
    }
#line 43 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st28;
tr56:
#line 196 "src/vcf/vcf.ragel"
	{
        try {
          ParsePolicy::handle_meta_line(*this);
        } catch (Error *error) {
          ErrorPolicy::handle_error(*this, error);
        }
    }
#line 43 "src/vcf/vcf.ragel"
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
	/* fall through */
case 28:
#line 1587 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 35 )
		goto st23;
	goto tr26;
tr47:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 196 "src/vcf/vcf.ragel"
	{
        try {
          ParsePolicy::handle_meta_line(*this);
        } catch (Error *error) {
          ErrorPolicy::handle_error(*this, error);
        }
    }
#line 43 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st29;
tr57:
#line 196 "src/vcf/vcf.ragel"
	{
        try {
          ParsePolicy::handle_meta_line(*this);
        } catch (Error *error) {
          ErrorPolicy::handle_error(*this, error);
        }
    }
#line 43 "src/vcf/vcf.ragel"
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
	/* fall through */
case 29:
#line 1640 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 10 )
		goto st28;
	goto tr40;
st30:
	if ( ++p == pe )
		goto _test_eof30;
	/* fall through */
case 30:
	switch( (*p) ) {
		case 34: goto tr51;
		case 92: goto tr52;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr50;
	goto tr40;
tr50:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st31;
tr53:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st31;
st31:
	if ( ++p == pe )
		goto _test_eof31;
	/* fall through */
case 31:
#line 1677 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr54;
		case 92: goto tr55;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr53;
	goto tr40;
tr51:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st32;
tr54:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st32;
st32:
	if ( ++p == pe )
		goto _test_eof32;
	/* fall through */
case 32:
#line 1706 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
	}
	goto tr40;
tr52:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st33;
tr55:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st33;
st33:
	if ( ++p == pe )
		goto _test_eof33;
	/* fall through */
case 33:
#line 1733 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr58;
		case 92: goto tr55;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr53;
	goto tr40;
tr58:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st34;
st34:
	if ( ++p == pe )
		goto _test_eof34;
	/* fall through */
case 34:
#line 1756 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
		case 34: goto tr54;
		case 92: goto tr55;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr53;
	goto tr40;
st35:
	if ( ++p == pe )
		goto _test_eof35;
	/* fall through */
case 35:
	switch( (*p) ) {
		case 34: goto st36;
		case 95: goto tr60;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr60;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr61;
		} else if ( (*p) >= 65 )
			goto tr61;
	} else
		goto tr61;
	goto tr40;
st36:
	if ( ++p == pe )
		goto _test_eof36;
	/* fall through */
case 36:
	switch( (*p) ) {
		case 34: goto tr63;
		case 92: goto tr64;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr62;
	goto tr40;
tr62:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st37;
tr65:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st37;
st37:
	if ( ++p == pe )
		goto _test_eof37;
	/* fall through */
case 37:
#line 1820 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr66;
		case 92: goto tr67;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr65;
	goto tr40;
tr63:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st38;
tr66:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st38;
st38:
	if ( ++p == pe )
		goto _test_eof38;
	/* fall through */
case 38:
#line 1849 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 62 )
		goto st32;
	goto tr40;
tr64:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st39;
tr67:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st39;
st39:
	if ( ++p == pe )
		goto _test_eof39;
	/* fall through */
case 39:
#line 1874 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr69;
		case 92: goto tr67;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr65;
	goto tr40;
tr69:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st40;
st40:
	if ( ++p == pe )
		goto _test_eof40;
	/* fall through */
case 40:
#line 1897 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr66;
		case 62: goto tr70;
		case 92: goto tr67;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr65;
	goto tr40;
tr70:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st41;
st41:
	if ( ++p == pe )
		goto _test_eof41;
	/* fall through */
case 41:
#line 1917 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
		case 34: goto tr66;
		case 92: goto tr67;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr65;
	goto tr40;
tr60:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st42;
st42:
	if ( ++p == pe )
		goto _test_eof42;
	/* fall through */
case 42:
#line 1938 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 95 )
		goto st42;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st42;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr72;
		} else if ( (*p) >= 65 )
			goto tr72;
	} else
		goto tr72;
	goto tr40;
tr61:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st43;
tr72:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st43;
st43:
	if ( ++p == pe )
		goto _test_eof43;
	/* fall through */
case 43:
#line 1974 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr73;
		case 95: goto tr72;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr72;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr72;
		} else if ( (*p) >= 65 )
			goto tr72;
	} else
		goto tr72;
	goto tr40;
tr73:
#line 192 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st44;
st44:
	if ( ++p == pe )
		goto _test_eof44;
	/* fall through */
case 44:
#line 2002 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 34 )
		goto st63;
	if ( (*p) < 45 ) {
		if ( 32 <= (*p) && (*p) <= 43 )
			goto tr74;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr74;
	} else
		goto tr74;
	goto tr40;
tr74:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st45;
tr76:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st45;
st45:
	if ( ++p == pe )
		goto _test_eof45;
	/* fall through */
case 45:
#line 2035 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 44: goto tr77;
		case 62: goto tr54;
	}
	if ( (*p) > 33 ) {
		if ( 35 <= (*p) && (*p) <= 126 )
			goto tr76;
	} else if ( (*p) >= 32 )
		goto tr76;
	goto tr40;
tr77:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st46;
st46:
	if ( ++p == pe )
		goto _test_eof46;
	/* fall through */
case 46:
#line 2057 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 95 )
		goto tr78;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr78;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr79;
		} else if ( (*p) >= 65 )
			goto tr79;
	} else
		goto tr79;
	goto tr40;
tr78:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st47;
st47:
	if ( ++p == pe )
		goto _test_eof47;
	/* fall through */
case 47:
#line 2083 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 95 )
		goto st47;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st47;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr81;
		} else if ( (*p) >= 65 )
			goto tr81;
	} else
		goto tr81;
	goto tr40;
tr79:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st48;
tr81:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st48;
st48:
	if ( ++p == pe )
		goto _test_eof48;
	/* fall through */
case 48:
#line 2119 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr82;
		case 95: goto tr81;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr81;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr81;
		} else if ( (*p) >= 65 )
			goto tr81;
	} else
		goto tr81;
	goto tr40;
tr82:
#line 192 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st49;
st49:
	if ( ++p == pe )
		goto _test_eof49;
	/* fall through */
case 49:
#line 2147 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 34 )
		goto st50;
	if ( (*p) < 45 ) {
		if ( 32 <= (*p) && (*p) <= 43 )
			goto tr74;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr74;
	} else
		goto tr74;
	goto tr40;
st50:
	if ( ++p == pe )
		goto _test_eof50;
	/* fall through */
case 50:
	switch( (*p) ) {
		case 34: goto tr85;
		case 92: goto tr86;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr84;
	goto tr40;
tr84:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st51;
tr87:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st51;
st51:
	if ( ++p == pe )
		goto _test_eof51;
	/* fall through */
case 51:
#line 2192 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr88;
		case 92: goto tr89;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr87;
	goto tr40;
tr85:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st52;
tr88:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st52;
st52:
	if ( ++p == pe )
		goto _test_eof52;
	/* fall through */
case 52:
#line 2221 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 44: goto st46;
		case 62: goto st32;
	}
	goto tr40;
tr86:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st53;
tr89:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st53;
st53:
	if ( ++p == pe )
		goto _test_eof53;
	/* fall through */
case 53:
#line 2248 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr91;
		case 92: goto tr89;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr87;
	goto tr40;
tr91:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st54;
st54:
	if ( ++p == pe )
		goto _test_eof54;
	/* fall through */
case 54:
#line 2271 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr88;
		case 44: goto tr92;
		case 62: goto tr93;
		case 92: goto tr89;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr87;
	goto tr40;
tr106:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st55;
tr92:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st55;
tr103:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st55;
st55:
	if ( ++p == pe )
		goto _test_eof55;
	/* fall through */
case 55:
#line 2312 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr88;
		case 47: goto tr87;
		case 92: goto tr89;
		case 95: goto tr94;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr87;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr95;
		} else
			goto tr94;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr95;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr87;
			} else if ( (*p) >= 97 )
				goto tr95;
		} else
			goto tr87;
	} else
		goto tr87;
	goto tr40;
tr94:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st56;
tr96:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st56;
st56:
	if ( ++p == pe )
		goto _test_eof56;
	/* fall through */
case 56:
#line 2364 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr88;
		case 47: goto tr87;
		case 92: goto tr89;
		case 95: goto tr96;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr87;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr97;
		} else
			goto tr96;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr97;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr87;
			} else if ( (*p) >= 97 )
				goto tr97;
		} else
			goto tr87;
	} else
		goto tr87;
	goto tr40;
tr95:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st57;
tr97:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st57;
st57:
	if ( ++p == pe )
		goto _test_eof57;
	/* fall through */
case 57:
#line 2416 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr88;
		case 47: goto tr87;
		case 61: goto tr98;
		case 92: goto tr89;
		case 95: goto tr97;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr87;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr87;
		} else
			goto tr97;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr87;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr87;
		} else
			goto tr97;
	} else
		goto tr97;
	goto tr40;
tr98:
#line 192 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st58;
st58:
	if ( ++p == pe )
		goto _test_eof58;
	/* fall through */
case 58:
#line 2460 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr100;
		case 44: goto tr87;
		case 62: goto tr87;
		case 92: goto tr101;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr99;
	goto tr40;
tr102:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st59;
tr99:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st59;
st59:
	if ( ++p == pe )
		goto _test_eof59;
	/* fall through */
case 59:
#line 2491 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr88;
		case 44: goto tr103;
		case 62: goto tr104;
		case 92: goto tr105;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr102;
	goto tr40;
tr107:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st60;
tr93:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st60;
tr104:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st60;
st60:
	if ( ++p == pe )
		goto _test_eof60;
	/* fall through */
case 60:
#line 2532 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
		case 34: goto tr88;
		case 92: goto tr89;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr87;
	goto tr40;
tr105:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st61;
tr101:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st61;
st61:
	if ( ++p == pe )
		goto _test_eof61;
	/* fall through */
case 61:
#line 2563 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr91;
		case 44: goto tr103;
		case 62: goto tr104;
		case 92: goto tr105;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr102;
	goto tr40;
tr100:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st62;
st62:
	if ( ++p == pe )
		goto _test_eof62;
	/* fall through */
case 62:
#line 2584 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr85;
		case 44: goto tr106;
		case 62: goto tr107;
		case 92: goto tr86;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr84;
	goto tr40;
st63:
	if ( ++p == pe )
		goto _test_eof63;
	/* fall through */
case 63:
	switch( (*p) ) {
		case 34: goto tr85;
		case 92: goto tr109;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr108;
	goto tr40;
tr108:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st64;
tr110:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st64;
st64:
	if ( ++p == pe )
		goto _test_eof64;
	/* fall through */
case 64:
#line 2627 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr88;
		case 92: goto tr111;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr110;
	goto tr40;
tr109:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st65;
tr111:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st65;
st65:
	if ( ++p == pe )
		goto _test_eof65;
	/* fall through */
case 65:
#line 2656 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr112;
		case 92: goto tr111;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr110;
	goto tr40;
tr112:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st66;
st66:
	if ( ++p == pe )
		goto _test_eof66;
	/* fall through */
case 66:
#line 2679 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr88;
		case 44: goto tr113;
		case 62: goto tr114;
		case 92: goto tr111;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr110;
	goto tr40;
tr113:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st67;
tr123:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st67;
st67:
	if ( ++p == pe )
		goto _test_eof67;
	/* fall through */
case 67:
#line 2710 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr88;
		case 47: goto tr110;
		case 92: goto tr111;
		case 95: goto tr115;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr110;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr116;
		} else
			goto tr115;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr116;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr110;
			} else if ( (*p) >= 97 )
				goto tr116;
		} else
			goto tr110;
	} else
		goto tr110;
	goto tr40;
tr117:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st68;
tr115:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st68;
st68:
	if ( ++p == pe )
		goto _test_eof68;
	/* fall through */
case 68:
#line 2762 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr88;
		case 47: goto tr110;
		case 92: goto tr111;
		case 95: goto tr117;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr110;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr118;
		} else
			goto tr117;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr118;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr110;
			} else if ( (*p) >= 97 )
				goto tr118;
		} else
			goto tr110;
	} else
		goto tr110;
	goto tr40;
tr118:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st69;
tr116:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st69;
st69:
	if ( ++p == pe )
		goto _test_eof69;
	/* fall through */
case 69:
#line 2814 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr88;
		case 47: goto tr110;
		case 61: goto tr119;
		case 92: goto tr111;
		case 95: goto tr118;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr110;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr110;
		} else
			goto tr118;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr110;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr110;
		} else
			goto tr118;
	} else
		goto tr118;
	goto tr40;
tr119:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 192 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st70;
st70:
	if ( ++p == pe )
		goto _test_eof70;
	/* fall through */
case 70:
#line 2858 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr100;
		case 44: goto tr110;
		case 62: goto tr110;
		case 92: goto tr121;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr120;
	goto tr40;
tr122:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st71;
tr120:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st71;
st71:
	if ( ++p == pe )
		goto _test_eof71;
	/* fall through */
case 71:
#line 2889 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr88;
		case 44: goto tr123;
		case 62: goto tr124;
		case 92: goto tr125;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr122;
	goto tr40;
tr114:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st72;
tr124:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st72;
st72:
	if ( ++p == pe )
		goto _test_eof72;
	/* fall through */
case 72:
#line 2920 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
		case 34: goto tr88;
		case 92: goto tr111;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr110;
	goto tr40;
tr125:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st73;
tr121:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st73;
st73:
	if ( ++p == pe )
		goto _test_eof73;
	/* fall through */
case 73:
#line 2951 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr112;
		case 44: goto tr123;
		case 62: goto tr124;
		case 92: goto tr125;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr122;
	goto tr40;
tr31:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st74;
st74:
	if ( ++p == pe )
		goto _test_eof74;
	/* fall through */
case 74:
#line 2976 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 76: goto tr127;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr126;
tr127:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st75;
st75:
	if ( ++p == pe )
		goto _test_eof75;
	/* fall through */
case 75:
#line 2995 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 84: goto st76;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr126;
st76:
	if ( ++p == pe )
		goto _test_eof76;
	/* fall through */
case 76:
	if ( (*p) == 61 )
		goto tr129;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr126;
tr129:
#line 108 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "ALT");
    }
	goto st77;
st77:
	if ( ++p == pe )
		goto _test_eof77;
	/* fall through */
case 77:
#line 3024 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 60 )
		goto st78;
	goto tr126;
st78:
	if ( ++p == pe )
		goto _test_eof78;
	/* fall through */
case 78:
	if ( (*p) == 73 )
		goto st79;
	goto tr126;
st79:
	if ( ++p == pe )
		goto _test_eof79;
	/* fall through */
case 79:
	if ( (*p) == 68 )
		goto st80;
	goto tr126;
st80:
	if ( ++p == pe )
		goto _test_eof80;
	/* fall through */
case 80:
	if ( (*p) == 61 )
		goto st81;
	goto tr126;
st81:
	if ( ++p == pe )
		goto _test_eof81;
	/* fall through */
case 81:
	if ( (*p) == 61 )
		goto tr135;
	if ( (*p) < 63 ) {
		if ( (*p) < 45 ) {
			if ( 33 <= (*p) && (*p) <= 43 )
				goto tr135;
		} else if ( (*p) > 47 ) {
			if ( (*p) > 57 ) {
				if ( 58 <= (*p) && (*p) <= 59 )
					goto tr135;
			} else if ( (*p) >= 48 )
				goto tr136;
		} else
			goto tr135;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr136;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr135;
			} else if ( (*p) >= 97 )
				goto tr136;
		} else
			goto tr135;
	} else
		goto tr135;
	goto tr134;
tr135:
#line 144 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st82;
st82:
	if ( ++p == pe )
		goto _test_eof82;
	/* fall through */
case 82:
#line 3101 "inc/vcf/validator_detail_v45.hpp"
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
				goto tr138;
		} else
			goto st82;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr138;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto st82;
			} else if ( (*p) >= 97 )
				goto tr138;
		} else
			goto st82;
	} else
		goto st82;
	goto tr134;
tr138:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st83;
tr136:
#line 144 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st83;
st83:
	if ( ++p == pe )
		goto _test_eof83;
	/* fall through */
case 83:
#line 3156 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 44: goto tr139;
		case 62: goto tr140;
	}
	if ( (*p) > 59 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr138;
	} else if ( (*p) >= 33 )
		goto tr138;
	goto tr134;
tr139:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st84;
st84:
	if ( ++p == pe )
		goto _test_eof84;
	/* fall through */
case 84:
#line 3178 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr142;
		case 95: goto tr142;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr142;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr143;
		} else if ( (*p) >= 65 )
			goto tr143;
	} else
		goto tr143;
	goto tr141;
tr142:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st85;
st85:
	if ( ++p == pe )
		goto _test_eof85;
	/* fall through */
case 85:
#line 3206 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto st85;
		case 95: goto st85;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st85;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr145;
		} else if ( (*p) >= 65 )
			goto tr145;
	} else
		goto tr145;
	goto tr141;
tr143:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st86;
tr145:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st86;
st86:
	if ( ++p == pe )
		goto _test_eof86;
	/* fall through */
case 86:
#line 3244 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr145;
		case 61: goto tr146;
		case 95: goto tr145;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr145;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr145;
		} else if ( (*p) >= 65 )
			goto tr145;
	} else
		goto tr145;
	goto tr141;
tr146:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st87;
st87:
	if ( ++p == pe )
		goto _test_eof87;
	/* fall through */
case 87:
#line 3273 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 34 )
		goto st88;
	goto tr126;
st88:
	if ( ++p == pe )
		goto _test_eof88;
	/* fall through */
case 88:
	switch( (*p) ) {
		case 34: goto tr150;
		case 92: goto tr151;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr149;
	goto tr148;
tr149:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st89;
tr152:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st89;
st89:
	if ( ++p == pe )
		goto _test_eof89;
	/* fall through */
case 89:
#line 3310 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr153;
		case 92: goto tr154;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr152;
	goto tr148;
tr150:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st90;
tr153:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st90;
st90:
	if ( ++p == pe )
		goto _test_eof90;
	/* fall through */
case 90:
#line 3339 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 44: goto st84;
		case 62: goto st91;
	}
	goto tr148;
tr140:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st91;
st91:
	if ( ++p == pe )
		goto _test_eof91;
	/* fall through */
case 91:
#line 3356 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
	}
	goto tr126;
tr151:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st92;
tr154:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st92;
st92:
	if ( ++p == pe )
		goto _test_eof92;
	/* fall through */
case 92:
#line 3383 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr157;
		case 92: goto tr154;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr152;
	goto tr148;
tr157:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st93;
st93:
	if ( ++p == pe )
		goto _test_eof93;
	/* fall through */
case 93:
#line 3406 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr153;
		case 44: goto tr158;
		case 62: goto tr159;
		case 92: goto tr154;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr152;
	goto tr148;
tr167:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st94;
tr158:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st94;
st94:
	if ( ++p == pe )
		goto _test_eof94;
	/* fall through */
case 94:
#line 3437 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr153;
		case 43: goto tr161;
		case 47: goto tr152;
		case 92: goto tr154;
		case 95: goto tr161;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr152;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr162;
		} else
			goto tr161;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr162;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr152;
			} else if ( (*p) >= 97 )
				goto tr162;
		} else
			goto tr152;
	} else
		goto tr152;
	goto tr160;
tr161:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st95;
tr163:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st95;
st95:
	if ( ++p == pe )
		goto _test_eof95;
	/* fall through */
case 95:
#line 3490 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr153;
		case 43: goto tr163;
		case 47: goto tr152;
		case 92: goto tr154;
		case 95: goto tr163;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr152;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr164;
		} else
			goto tr163;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr164;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr152;
			} else if ( (*p) >= 97 )
				goto tr164;
		} else
			goto tr152;
	} else
		goto tr152;
	goto tr160;
tr162:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st96;
tr164:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st96;
st96:
	if ( ++p == pe )
		goto _test_eof96;
	/* fall through */
case 96:
#line 3543 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr153;
		case 43: goto tr164;
		case 47: goto tr152;
		case 61: goto tr165;
		case 92: goto tr154;
		case 95: goto tr164;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr152;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr152;
		} else
			goto tr164;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr152;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr152;
		} else
			goto tr164;
	} else
		goto tr164;
	goto tr160;
tr165:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st97;
st97:
	if ( ++p == pe )
		goto _test_eof97;
	/* fall through */
case 97:
#line 3588 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr166;
		case 92: goto tr154;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr152;
	goto tr148;
tr166:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st98;
st98:
	if ( ++p == pe )
		goto _test_eof98;
	/* fall through */
case 98:
#line 3607 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr150;
		case 44: goto tr167;
		case 62: goto tr168;
		case 92: goto tr151;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr149;
	goto tr148;
tr168:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st99;
tr159:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st99;
st99:
	if ( ++p == pe )
		goto _test_eof99;
	/* fall through */
case 99:
#line 3638 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
		case 34: goto tr153;
		case 92: goto tr154;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr152;
	goto tr148;
tr32:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st100;
st100:
	if ( ++p == pe )
		goto _test_eof100;
	/* fall through */
case 100:
#line 3663 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 73: goto tr170;
		case 79: goto tr171;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr169;
tr170:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st101;
st101:
	if ( ++p == pe )
		goto _test_eof101;
	/* fall through */
case 101:
#line 3683 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 76: goto tr173;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr172;
tr173:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st102;
st102:
	if ( ++p == pe )
		goto _test_eof102;
	/* fall through */
case 102:
#line 3702 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 84: goto tr174;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr172;
tr174:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st103;
st103:
	if ( ++p == pe )
		goto _test_eof103;
	/* fall through */
case 103:
#line 3721 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 69: goto tr175;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr172;
tr175:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st104;
st104:
	if ( ++p == pe )
		goto _test_eof104;
	/* fall through */
case 104:
#line 3740 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 82: goto st105;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr172;
st105:
	if ( ++p == pe )
		goto _test_eof105;
	/* fall through */
case 105:
	if ( (*p) == 61 )
		goto tr177;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr172;
tr177:
#line 120 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "FILTER");
    }
	goto st106;
st106:
	if ( ++p == pe )
		goto _test_eof106;
	/* fall through */
case 106:
#line 3769 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 60 )
		goto st107;
	goto tr172;
st107:
	if ( ++p == pe )
		goto _test_eof107;
	/* fall through */
case 107:
	if ( (*p) == 73 )
		goto st108;
	goto tr172;
st108:
	if ( ++p == pe )
		goto _test_eof108;
	/* fall through */
case 108:
	if ( (*p) == 68 )
		goto st109;
	goto tr172;
st109:
	if ( ++p == pe )
		goto _test_eof109;
	/* fall through */
case 109:
	if ( (*p) == 61 )
		goto st110;
	goto tr172;
st110:
	if ( ++p == pe )
		goto _test_eof110;
	/* fall through */
case 110:
	switch( (*p) ) {
		case 43: goto tr183;
		case 95: goto tr183;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr183;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr184;
		} else if ( (*p) >= 65 )
			goto tr184;
	} else
		goto tr184;
	goto tr182;
tr183:
#line 144 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st111;
st111:
	if ( ++p == pe )
		goto _test_eof111;
	/* fall through */
case 111:
#line 3833 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto st111;
		case 95: goto st111;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st111;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr186;
		} else if ( (*p) >= 65 )
			goto tr186;
	} else
		goto tr186;
	goto tr182;
tr186:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st112;
tr184:
#line 144 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st112;
st112:
	if ( ++p == pe )
		goto _test_eof112;
	/* fall through */
case 112:
#line 3875 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 44: goto tr187;
		case 62: goto tr188;
		case 95: goto tr186;
	}
	if ( (*p) < 48 ) {
		if ( 43 <= (*p) && (*p) <= 46 )
			goto tr186;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr186;
		} else if ( (*p) >= 65 )
			goto tr186;
	} else
		goto tr186;
	goto tr182;
tr187:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st113;
st113:
	if ( ++p == pe )
		goto _test_eof113;
	/* fall through */
case 113:
#line 3904 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr189;
		case 95: goto tr189;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr189;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr190;
		} else if ( (*p) >= 65 )
			goto tr190;
	} else
		goto tr190;
	goto tr182;
tr189:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st114;
st114:
	if ( ++p == pe )
		goto _test_eof114;
	/* fall through */
case 114:
#line 3932 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto st114;
		case 95: goto st114;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st114;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr192;
		} else if ( (*p) >= 65 )
			goto tr192;
	} else
		goto tr192;
	goto tr182;
tr190:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st115;
tr192:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st115;
st115:
	if ( ++p == pe )
		goto _test_eof115;
	/* fall through */
case 115:
#line 3970 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr192;
		case 61: goto tr193;
		case 95: goto tr192;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr192;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr192;
		} else if ( (*p) >= 65 )
			goto tr192;
	} else
		goto tr192;
	goto tr182;
tr193:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st116;
st116:
	if ( ++p == pe )
		goto _test_eof116;
	/* fall through */
case 116:
#line 3999 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 34 )
		goto st117;
	goto tr172;
st117:
	if ( ++p == pe )
		goto _test_eof117;
	/* fall through */
case 117:
	switch( (*p) ) {
		case 34: goto tr197;
		case 92: goto tr198;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr196;
	goto tr195;
tr196:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st118;
tr199:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st118;
st118:
	if ( ++p == pe )
		goto _test_eof118;
	/* fall through */
case 118:
#line 4036 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr200;
		case 92: goto tr201;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr199;
	goto tr195;
tr197:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st119;
tr200:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st119;
st119:
	if ( ++p == pe )
		goto _test_eof119;
	/* fall through */
case 119:
#line 4065 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 44: goto st113;
		case 62: goto st120;
	}
	goto tr195;
tr188:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st120;
st120:
	if ( ++p == pe )
		goto _test_eof120;
	/* fall through */
case 120:
#line 4082 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
	}
	goto tr172;
tr198:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st121;
tr201:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st121;
st121:
	if ( ++p == pe )
		goto _test_eof121;
	/* fall through */
case 121:
#line 4109 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr204;
		case 92: goto tr201;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr199;
	goto tr195;
tr204:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st122;
st122:
	if ( ++p == pe )
		goto _test_eof122;
	/* fall through */
case 122:
#line 4132 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr200;
		case 44: goto tr205;
		case 62: goto tr206;
		case 92: goto tr201;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr199;
	goto tr195;
tr214:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st123;
tr205:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st123;
st123:
	if ( ++p == pe )
		goto _test_eof123;
	/* fall through */
case 123:
#line 4163 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr200;
		case 43: goto tr208;
		case 47: goto tr199;
		case 92: goto tr201;
		case 95: goto tr208;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr199;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr209;
		} else
			goto tr208;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr209;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr199;
			} else if ( (*p) >= 97 )
				goto tr209;
		} else
			goto tr199;
	} else
		goto tr199;
	goto tr207;
tr208:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st124;
tr210:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st124;
st124:
	if ( ++p == pe )
		goto _test_eof124;
	/* fall through */
case 124:
#line 4216 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr200;
		case 43: goto tr210;
		case 47: goto tr199;
		case 92: goto tr201;
		case 95: goto tr210;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr199;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr211;
		} else
			goto tr210;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr211;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr199;
			} else if ( (*p) >= 97 )
				goto tr211;
		} else
			goto tr199;
	} else
		goto tr199;
	goto tr207;
tr209:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st125;
tr211:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st125;
st125:
	if ( ++p == pe )
		goto _test_eof125;
	/* fall through */
case 125:
#line 4269 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr200;
		case 43: goto tr211;
		case 47: goto tr199;
		case 61: goto tr212;
		case 92: goto tr201;
		case 95: goto tr211;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr199;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr199;
		} else
			goto tr211;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr199;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr199;
		} else
			goto tr211;
	} else
		goto tr211;
	goto tr207;
tr212:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st126;
st126:
	if ( ++p == pe )
		goto _test_eof126;
	/* fall through */
case 126:
#line 4314 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr213;
		case 92: goto tr201;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr199;
	goto tr195;
tr213:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st127;
st127:
	if ( ++p == pe )
		goto _test_eof127;
	/* fall through */
case 127:
#line 4333 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr197;
		case 44: goto tr214;
		case 62: goto tr215;
		case 92: goto tr198;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr196;
	goto tr195;
tr215:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st128;
tr206:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st128;
st128:
	if ( ++p == pe )
		goto _test_eof128;
	/* fall through */
case 128:
#line 4364 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
		case 34: goto tr200;
		case 92: goto tr201;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr199;
	goto tr195;
tr171:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st129;
st129:
	if ( ++p == pe )
		goto _test_eof129;
	/* fall through */
case 129:
#line 4385 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 82: goto tr217;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr216;
tr217:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st130;
st130:
	if ( ++p == pe )
		goto _test_eof130;
	/* fall through */
case 130:
#line 4404 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 77: goto tr218;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr216;
tr218:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st131;
st131:
	if ( ++p == pe )
		goto _test_eof131;
	/* fall through */
case 131:
#line 4423 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 65: goto tr219;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr216;
tr219:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st132;
st132:
	if ( ++p == pe )
		goto _test_eof132;
	/* fall through */
case 132:
#line 4442 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 84: goto st133;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr216;
st133:
	if ( ++p == pe )
		goto _test_eof133;
	/* fall through */
case 133:
	if ( (*p) == 61 )
		goto tr221;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr216;
tr221:
#line 124 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "FORMAT");
    }
	goto st134;
st134:
	if ( ++p == pe )
		goto _test_eof134;
	/* fall through */
case 134:
#line 4471 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 60 )
		goto st135;
	goto tr216;
st135:
	if ( ++p == pe )
		goto _test_eof135;
	/* fall through */
case 135:
	if ( (*p) == 73 )
		goto st136;
	goto tr216;
st136:
	if ( ++p == pe )
		goto _test_eof136;
	/* fall through */
case 136:
	if ( (*p) == 68 )
		goto st137;
	goto tr216;
st137:
	if ( ++p == pe )
		goto _test_eof137;
	/* fall through */
case 137:
	if ( (*p) == 61 )
		goto st138;
	goto tr216;
st138:
	if ( ++p == pe )
		goto _test_eof138;
	/* fall through */
case 138:
	switch( (*p) ) {
		case 43: goto tr227;
		case 95: goto tr227;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr227;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr228;
		} else if ( (*p) >= 65 )
			goto tr228;
	} else
		goto tr228;
	goto tr226;
tr227:
#line 144 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st139;
st139:
	if ( ++p == pe )
		goto _test_eof139;
	/* fall through */
case 139:
#line 4535 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto st139;
		case 95: goto st139;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st139;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr230;
		} else if ( (*p) >= 65 )
			goto tr230;
	} else
		goto tr230;
	goto tr226;
tr230:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st140;
tr228:
#line 144 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st140;
st140:
	if ( ++p == pe )
		goto _test_eof140;
	/* fall through */
case 140:
#line 4577 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 44: goto tr231;
		case 95: goto tr230;
	}
	if ( (*p) < 48 ) {
		if ( 43 <= (*p) && (*p) <= 46 )
			goto tr230;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr230;
		} else if ( (*p) >= 65 )
			goto tr230;
	} else
		goto tr230;
	goto tr226;
tr231:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st141;
st141:
	if ( ++p == pe )
		goto _test_eof141;
	/* fall through */
case 141:
#line 4605 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 78 )
		goto st142;
	goto tr216;
st142:
	if ( ++p == pe )
		goto _test_eof142;
	/* fall through */
case 142:
	if ( (*p) == 117 )
		goto st143;
	goto tr216;
st143:
	if ( ++p == pe )
		goto _test_eof143;
	/* fall through */
case 143:
	if ( (*p) == 109 )
		goto st144;
	goto tr216;
st144:
	if ( ++p == pe )
		goto _test_eof144;
	/* fall through */
case 144:
	if ( (*p) == 98 )
		goto st145;
	goto tr216;
st145:
	if ( ++p == pe )
		goto _test_eof145;
	/* fall through */
case 145:
	if ( (*p) == 101 )
		goto st146;
	goto tr216;
st146:
	if ( ++p == pe )
		goto _test_eof146;
	/* fall through */
case 146:
	if ( (*p) == 114 )
		goto st147;
	goto tr216;
st147:
	if ( ++p == pe )
		goto _test_eof147;
	/* fall through */
case 147:
	if ( (*p) == 61 )
		goto st148;
	goto tr216;
st148:
	if ( ++p == pe )
		goto _test_eof148;
	/* fall through */
case 148:
	switch( (*p) ) {
		case 46: goto tr240;
		case 65: goto tr240;
		case 71: goto tr240;
		case 76: goto tr242;
		case 77: goto tr240;
		case 80: goto tr240;
		case 82: goto tr240;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr241;
	goto tr239;
tr307:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st149;
tr240:
#line 148 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Number");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st149;
st149:
	if ( ++p == pe )
		goto _test_eof149;
	/* fall through */
case 149:
#line 4699 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 44 )
		goto tr243;
	goto tr239;
tr243:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st150;
st150:
	if ( ++p == pe )
		goto _test_eof150;
	/* fall through */
case 150:
#line 4714 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 84 )
		goto st151;
	goto tr216;
st151:
	if ( ++p == pe )
		goto _test_eof151;
	/* fall through */
case 151:
	if ( (*p) == 121 )
		goto st152;
	goto tr216;
st152:
	if ( ++p == pe )
		goto _test_eof152;
	/* fall through */
case 152:
	if ( (*p) == 112 )
		goto st153;
	goto tr216;
st153:
	if ( ++p == pe )
		goto _test_eof153;
	/* fall through */
case 153:
	if ( (*p) == 101 )
		goto st154;
	goto tr216;
st154:
	if ( ++p == pe )
		goto _test_eof154;
	/* fall through */
case 154:
	if ( (*p) == 61 )
		goto st155;
	goto tr216;
st155:
	if ( ++p == pe )
		goto _test_eof155;
	/* fall through */
case 155:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr250;
	} else if ( (*p) >= 65 )
		goto tr250;
	goto tr249;
tr252:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st156;
tr250:
#line 152 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Type");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st156;
st156:
	if ( ++p == pe )
		goto _test_eof156;
	/* fall through */
case 156:
#line 4786 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 44 )
		goto tr251;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr252;
	} else if ( (*p) >= 65 )
		goto tr252;
	goto tr249;
tr251:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st157;
st157:
	if ( ++p == pe )
		goto _test_eof157;
	/* fall through */
case 157:
#line 4806 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 68 )
		goto st158;
	goto tr216;
st158:
	if ( ++p == pe )
		goto _test_eof158;
	/* fall through */
case 158:
	if ( (*p) == 101 )
		goto st159;
	goto tr216;
st159:
	if ( ++p == pe )
		goto _test_eof159;
	/* fall through */
case 159:
	if ( (*p) == 115 )
		goto st160;
	goto tr216;
st160:
	if ( ++p == pe )
		goto _test_eof160;
	/* fall through */
case 160:
	if ( (*p) == 99 )
		goto st161;
	goto tr216;
st161:
	if ( ++p == pe )
		goto _test_eof161;
	/* fall through */
case 161:
	if ( (*p) == 114 )
		goto st162;
	goto tr216;
st162:
	if ( ++p == pe )
		goto _test_eof162;
	/* fall through */
case 162:
	if ( (*p) == 105 )
		goto st163;
	goto tr216;
st163:
	if ( ++p == pe )
		goto _test_eof163;
	/* fall through */
case 163:
	if ( (*p) == 112 )
		goto st164;
	goto tr216;
st164:
	if ( ++p == pe )
		goto _test_eof164;
	/* fall through */
case 164:
	if ( (*p) == 116 )
		goto st165;
	goto tr216;
st165:
	if ( ++p == pe )
		goto _test_eof165;
	/* fall through */
case 165:
	if ( (*p) == 105 )
		goto st166;
	goto tr216;
st166:
	if ( ++p == pe )
		goto _test_eof166;
	/* fall through */
case 166:
	if ( (*p) == 111 )
		goto st167;
	goto tr216;
st167:
	if ( ++p == pe )
		goto _test_eof167;
	/* fall through */
case 167:
	if ( (*p) == 110 )
		goto st168;
	goto tr216;
st168:
	if ( ++p == pe )
		goto _test_eof168;
	/* fall through */
case 168:
	if ( (*p) == 61 )
		goto st169;
	goto tr216;
st169:
	if ( ++p == pe )
		goto _test_eof169;
	/* fall through */
case 169:
	if ( (*p) == 34 )
		goto tr265;
	goto tr216;
tr265:
#line 156 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Description");
    }
	goto st170;
st170:
	if ( ++p == pe )
		goto _test_eof170;
	/* fall through */
case 170:
#line 4917 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr268;
		case 92: goto tr269;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr267;
	goto tr266;
tr267:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st171;
tr270:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st171;
st171:
	if ( ++p == pe )
		goto _test_eof171;
	/* fall through */
case 171:
#line 4946 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr271;
		case 92: goto tr272;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr270;
	goto tr266;
tr268:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st172;
tr271:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st172;
st172:
	if ( ++p == pe )
		goto _test_eof172;
	/* fall through */
case 172:
#line 4975 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 44: goto st173;
		case 62: goto st187;
	}
	goto tr266;
st173:
	if ( ++p == pe )
		goto _test_eof173;
	/* fall through */
case 173:
	switch( (*p) ) {
		case 43: goto tr275;
		case 95: goto tr275;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr275;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr276;
		} else if ( (*p) >= 65 )
			goto tr276;
	} else
		goto tr276;
	goto tr226;
tr275:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st174;
st174:
	if ( ++p == pe )
		goto _test_eof174;
	/* fall through */
case 174:
#line 5013 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto st174;
		case 95: goto st174;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st174;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr278;
		} else if ( (*p) >= 65 )
			goto tr278;
	} else
		goto tr278;
	goto tr226;
tr276:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st175;
tr278:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st175;
st175:
	if ( ++p == pe )
		goto _test_eof175;
	/* fall through */
case 175:
#line 5051 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr278;
		case 61: goto tr279;
		case 95: goto tr278;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr278;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr278;
		} else if ( (*p) >= 65 )
			goto tr278;
	} else
		goto tr278;
	goto tr226;
tr279:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st176;
st176:
	if ( ++p == pe )
		goto _test_eof176;
	/* fall through */
case 176:
#line 5080 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 34 )
		goto st177;
	goto tr216;
st177:
	if ( ++p == pe )
		goto _test_eof177;
	/* fall through */
case 177:
	switch( (*p) ) {
		case 34: goto tr268;
		case 92: goto tr282;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr281;
	goto tr266;
tr281:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st178;
tr283:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st178;
st178:
	if ( ++p == pe )
		goto _test_eof178;
	/* fall through */
case 178:
#line 5117 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr271;
		case 92: goto tr284;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr283;
	goto tr266;
tr282:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st179;
tr284:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st179;
st179:
	if ( ++p == pe )
		goto _test_eof179;
	/* fall through */
case 179:
#line 5146 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr285;
		case 92: goto tr284;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr283;
	goto tr266;
tr285:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st180;
st180:
	if ( ++p == pe )
		goto _test_eof180;
	/* fall through */
case 180:
#line 5169 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr271;
		case 44: goto tr286;
		case 62: goto tr287;
		case 92: goto tr284;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr283;
	goto tr266;
tr295:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st181;
tr286:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st181;
st181:
	if ( ++p == pe )
		goto _test_eof181;
	/* fall through */
case 181:
#line 5200 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr271;
		case 43: goto tr289;
		case 47: goto tr283;
		case 92: goto tr284;
		case 95: goto tr289;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr283;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr290;
		} else
			goto tr289;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr290;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr283;
			} else if ( (*p) >= 97 )
				goto tr290;
		} else
			goto tr283;
	} else
		goto tr283;
	goto tr288;
tr289:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st182;
tr291:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st182;
st182:
	if ( ++p == pe )
		goto _test_eof182;
	/* fall through */
case 182:
#line 5253 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr271;
		case 43: goto tr291;
		case 47: goto tr283;
		case 92: goto tr284;
		case 95: goto tr291;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr283;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr292;
		} else
			goto tr291;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr292;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr283;
			} else if ( (*p) >= 97 )
				goto tr292;
		} else
			goto tr283;
	} else
		goto tr283;
	goto tr288;
tr290:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st183;
tr292:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st183;
st183:
	if ( ++p == pe )
		goto _test_eof183;
	/* fall through */
case 183:
#line 5306 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr271;
		case 43: goto tr292;
		case 47: goto tr283;
		case 61: goto tr293;
		case 92: goto tr284;
		case 95: goto tr292;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr283;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr283;
		} else
			goto tr292;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr283;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr283;
		} else
			goto tr292;
	} else
		goto tr292;
	goto tr288;
tr293:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st184;
st184:
	if ( ++p == pe )
		goto _test_eof184;
	/* fall through */
case 184:
#line 5351 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr294;
		case 92: goto tr284;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr283;
	goto tr266;
tr294:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st185;
st185:
	if ( ++p == pe )
		goto _test_eof185;
	/* fall through */
case 185:
#line 5370 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr268;
		case 44: goto tr295;
		case 62: goto tr296;
		case 92: goto tr282;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr281;
	goto tr266;
tr296:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st186;
tr287:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st186;
st186:
	if ( ++p == pe )
		goto _test_eof186;
	/* fall through */
case 186:
#line 5401 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
		case 34: goto tr271;
		case 92: goto tr284;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr283;
	goto tr266;
st187:
	if ( ++p == pe )
		goto _test_eof187;
	/* fall through */
case 187:
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
	}
	goto tr216;
tr269:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st188;
tr272:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st188;
st188:
	if ( ++p == pe )
		goto _test_eof188;
	/* fall through */
case 188:
#line 5442 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr297;
		case 92: goto tr272;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr270;
	goto tr266;
tr297:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st189;
st189:
	if ( ++p == pe )
		goto _test_eof189;
	/* fall through */
case 189:
#line 5465 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr271;
		case 44: goto tr298;
		case 62: goto tr299;
		case 92: goto tr272;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr270;
	goto tr266;
tr298:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st190;
st190:
	if ( ++p == pe )
		goto _test_eof190;
	/* fall through */
case 190:
#line 5486 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr271;
		case 43: goto tr301;
		case 47: goto tr270;
		case 92: goto tr272;
		case 95: goto tr301;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr270;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr302;
		} else
			goto tr301;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr302;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr270;
			} else if ( (*p) >= 97 )
				goto tr302;
		} else
			goto tr270;
	} else
		goto tr270;
	goto tr300;
tr303:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st191;
tr301:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st191;
st191:
	if ( ++p == pe )
		goto _test_eof191;
	/* fall through */
case 191:
#line 5539 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr271;
		case 43: goto tr303;
		case 47: goto tr270;
		case 92: goto tr272;
		case 95: goto tr303;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr270;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr304;
		} else
			goto tr303;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr304;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr270;
			} else if ( (*p) >= 97 )
				goto tr304;
		} else
			goto tr270;
	} else
		goto tr270;
	goto tr300;
tr304:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st192;
tr302:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st192;
st192:
	if ( ++p == pe )
		goto _test_eof192;
	/* fall through */
case 192:
#line 5592 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr271;
		case 43: goto tr304;
		case 47: goto tr270;
		case 61: goto tr305;
		case 92: goto tr272;
		case 95: goto tr304;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr270;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr270;
		} else
			goto tr304;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr270;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr270;
		} else
			goto tr304;
	} else
		goto tr304;
	goto tr300;
tr305:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st193;
st193:
	if ( ++p == pe )
		goto _test_eof193;
	/* fall through */
case 193:
#line 5637 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr294;
		case 92: goto tr272;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr270;
	goto tr266;
tr299:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st194;
st194:
	if ( ++p == pe )
		goto _test_eof194;
	/* fall through */
case 194:
#line 5656 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
		case 34: goto tr271;
		case 92: goto tr272;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr270;
	goto tr266;
tr306:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st195;
tr241:
#line 148 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Number");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st195;
st195:
	if ( ++p == pe )
		goto _test_eof195;
	/* fall through */
case 195:
#line 5691 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 44 )
		goto tr243;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr306;
	goto tr239;
tr242:
#line 148 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Number");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st196;
st196:
	if ( ++p == pe )
		goto _test_eof196;
	/* fall through */
case 196:
#line 5716 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 65: goto tr307;
		case 71: goto tr307;
		case 82: goto tr307;
	}
	goto tr239;
tr33:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st197;
st197:
	if ( ++p == pe )
		goto _test_eof197;
	/* fall through */
case 197:
#line 5738 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 78: goto tr309;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr308;
tr309:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st198;
st198:
	if ( ++p == pe )
		goto _test_eof198;
	/* fall through */
case 198:
#line 5757 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 70: goto tr310;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr308;
tr310:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st199;
st199:
	if ( ++p == pe )
		goto _test_eof199;
	/* fall through */
case 199:
#line 5776 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 79: goto st200;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr308;
st200:
	if ( ++p == pe )
		goto _test_eof200;
	/* fall through */
case 200:
	if ( (*p) == 61 )
		goto tr312;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr308;
tr312:
#line 128 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "INFO");
    }
	goto st201;
st201:
	if ( ++p == pe )
		goto _test_eof201;
	/* fall through */
case 201:
#line 5805 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 60 )
		goto st202;
	goto tr308;
st202:
	if ( ++p == pe )
		goto _test_eof202;
	/* fall through */
case 202:
	if ( (*p) == 73 )
		goto st203;
	goto tr308;
st203:
	if ( ++p == pe )
		goto _test_eof203;
	/* fall through */
case 203:
	if ( (*p) == 68 )
		goto st204;
	goto tr308;
st204:
	if ( ++p == pe )
		goto _test_eof204;
	/* fall through */
case 204:
	if ( (*p) == 61 )
		goto st205;
	goto tr308;
st205:
	if ( ++p == pe )
		goto _test_eof205;
	/* fall through */
case 205:
	switch( (*p) ) {
		case 43: goto tr318;
		case 95: goto tr318;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr318;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr319;
		} else if ( (*p) >= 65 )
			goto tr319;
	} else
		goto tr319;
	goto tr317;
tr318:
#line 144 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st206;
st206:
	if ( ++p == pe )
		goto _test_eof206;
	/* fall through */
case 206:
#line 5869 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto st206;
		case 95: goto st206;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st206;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr321;
		} else if ( (*p) >= 65 )
			goto tr321;
	} else
		goto tr321;
	goto tr317;
tr321:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st207;
tr319:
#line 144 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st207;
st207:
	if ( ++p == pe )
		goto _test_eof207;
	/* fall through */
case 207:
#line 5911 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 44: goto tr322;
		case 95: goto tr321;
	}
	if ( (*p) < 48 ) {
		if ( 43 <= (*p) && (*p) <= 46 )
			goto tr321;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr321;
		} else if ( (*p) >= 65 )
			goto tr321;
	} else
		goto tr321;
	goto tr317;
tr322:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st208;
st208:
	if ( ++p == pe )
		goto _test_eof208;
	/* fall through */
case 208:
#line 5939 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 78 )
		goto st209;
	goto tr308;
st209:
	if ( ++p == pe )
		goto _test_eof209;
	/* fall through */
case 209:
	if ( (*p) == 117 )
		goto st210;
	goto tr308;
st210:
	if ( ++p == pe )
		goto _test_eof210;
	/* fall through */
case 210:
	if ( (*p) == 109 )
		goto st211;
	goto tr308;
st211:
	if ( ++p == pe )
		goto _test_eof211;
	/* fall through */
case 211:
	if ( (*p) == 98 )
		goto st212;
	goto tr308;
st212:
	if ( ++p == pe )
		goto _test_eof212;
	/* fall through */
case 212:
	if ( (*p) == 101 )
		goto st213;
	goto tr308;
st213:
	if ( ++p == pe )
		goto _test_eof213;
	/* fall through */
case 213:
	if ( (*p) == 114 )
		goto st214;
	goto tr308;
st214:
	if ( ++p == pe )
		goto _test_eof214;
	/* fall through */
case 214:
	if ( (*p) == 61 )
		goto st215;
	goto tr308;
st215:
	if ( ++p == pe )
		goto _test_eof215;
	/* fall through */
case 215:
	switch( (*p) ) {
		case 46: goto tr331;
		case 65: goto tr331;
		case 71: goto tr331;
		case 82: goto tr331;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr332;
	goto tr330;
tr331:
#line 148 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Number");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st216;
st216:
	if ( ++p == pe )
		goto _test_eof216;
	/* fall through */
case 216:
#line 6024 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 44 )
		goto tr333;
	goto tr330;
tr333:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st217;
st217:
	if ( ++p == pe )
		goto _test_eof217;
	/* fall through */
case 217:
#line 6039 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 84 )
		goto st218;
	goto tr308;
st218:
	if ( ++p == pe )
		goto _test_eof218;
	/* fall through */
case 218:
	if ( (*p) == 121 )
		goto st219;
	goto tr308;
st219:
	if ( ++p == pe )
		goto _test_eof219;
	/* fall through */
case 219:
	if ( (*p) == 112 )
		goto st220;
	goto tr308;
st220:
	if ( ++p == pe )
		goto _test_eof220;
	/* fall through */
case 220:
	if ( (*p) == 101 )
		goto st221;
	goto tr308;
st221:
	if ( ++p == pe )
		goto _test_eof221;
	/* fall through */
case 221:
	if ( (*p) == 61 )
		goto st222;
	goto tr308;
st222:
	if ( ++p == pe )
		goto _test_eof222;
	/* fall through */
case 222:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr340;
	} else if ( (*p) >= 65 )
		goto tr340;
	goto tr339;
tr342:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st223;
tr340:
#line 152 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Type");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st223;
st223:
	if ( ++p == pe )
		goto _test_eof223;
	/* fall through */
case 223:
#line 6111 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 44 )
		goto tr341;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr342;
	} else if ( (*p) >= 65 )
		goto tr342;
	goto tr339;
tr341:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st224;
st224:
	if ( ++p == pe )
		goto _test_eof224;
	/* fall through */
case 224:
#line 6131 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 68 )
		goto st225;
	goto tr308;
st225:
	if ( ++p == pe )
		goto _test_eof225;
	/* fall through */
case 225:
	if ( (*p) == 101 )
		goto st226;
	goto tr308;
st226:
	if ( ++p == pe )
		goto _test_eof226;
	/* fall through */
case 226:
	if ( (*p) == 115 )
		goto st227;
	goto tr308;
st227:
	if ( ++p == pe )
		goto _test_eof227;
	/* fall through */
case 227:
	if ( (*p) == 99 )
		goto st228;
	goto tr308;
st228:
	if ( ++p == pe )
		goto _test_eof228;
	/* fall through */
case 228:
	if ( (*p) == 114 )
		goto st229;
	goto tr308;
st229:
	if ( ++p == pe )
		goto _test_eof229;
	/* fall through */
case 229:
	if ( (*p) == 105 )
		goto st230;
	goto tr308;
st230:
	if ( ++p == pe )
		goto _test_eof230;
	/* fall through */
case 230:
	if ( (*p) == 112 )
		goto st231;
	goto tr308;
st231:
	if ( ++p == pe )
		goto _test_eof231;
	/* fall through */
case 231:
	if ( (*p) == 116 )
		goto st232;
	goto tr308;
st232:
	if ( ++p == pe )
		goto _test_eof232;
	/* fall through */
case 232:
	if ( (*p) == 105 )
		goto st233;
	goto tr308;
st233:
	if ( ++p == pe )
		goto _test_eof233;
	/* fall through */
case 233:
	if ( (*p) == 111 )
		goto st234;
	goto tr308;
st234:
	if ( ++p == pe )
		goto _test_eof234;
	/* fall through */
case 234:
	if ( (*p) == 110 )
		goto st235;
	goto tr308;
st235:
	if ( ++p == pe )
		goto _test_eof235;
	/* fall through */
case 235:
	if ( (*p) == 61 )
		goto st236;
	goto tr308;
st236:
	if ( ++p == pe )
		goto _test_eof236;
	/* fall through */
case 236:
	if ( (*p) == 34 )
		goto tr355;
	goto tr308;
tr355:
#line 156 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Description");
    }
	goto st237;
st237:
	if ( ++p == pe )
		goto _test_eof237;
	/* fall through */
case 237:
#line 6242 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr358;
		case 92: goto tr359;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr357;
	goto tr356;
tr357:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st238;
tr360:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st238;
st238:
	if ( ++p == pe )
		goto _test_eof238;
	/* fall through */
case 238:
#line 6271 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr361;
		case 92: goto tr362;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr360;
	goto tr356;
tr358:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st239;
tr361:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st239;
st239:
	if ( ++p == pe )
		goto _test_eof239;
	/* fall through */
case 239:
#line 6300 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 44: goto st240;
		case 62: goto st254;
	}
	goto tr356;
st240:
	if ( ++p == pe )
		goto _test_eof240;
	/* fall through */
case 240:
	switch( (*p) ) {
		case 43: goto tr365;
		case 95: goto tr365;
	}
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
	goto tr317;
tr365:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st241;
st241:
	if ( ++p == pe )
		goto _test_eof241;
	/* fall through */
case 241:
#line 6338 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto st241;
		case 95: goto st241;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st241;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr368;
		} else if ( (*p) >= 65 )
			goto tr368;
	} else
		goto tr368;
	goto tr317;
tr366:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st242;
tr368:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st242;
st242:
	if ( ++p == pe )
		goto _test_eof242;
	/* fall through */
case 242:
#line 6376 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr368;
		case 61: goto tr369;
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
	goto tr317;
tr369:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st243;
st243:
	if ( ++p == pe )
		goto _test_eof243;
	/* fall through */
case 243:
#line 6405 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 34 )
		goto st244;
	goto tr308;
st244:
	if ( ++p == pe )
		goto _test_eof244;
	/* fall through */
case 244:
	switch( (*p) ) {
		case 34: goto tr358;
		case 92: goto tr372;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr371;
	goto tr356;
tr371:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st245;
tr373:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st245;
st245:
	if ( ++p == pe )
		goto _test_eof245;
	/* fall through */
case 245:
#line 6442 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr361;
		case 92: goto tr374;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr373;
	goto tr356;
tr372:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st246;
tr374:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st246;
st246:
	if ( ++p == pe )
		goto _test_eof246;
	/* fall through */
case 246:
#line 6471 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr375;
		case 92: goto tr374;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr373;
	goto tr356;
tr375:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st247;
st247:
	if ( ++p == pe )
		goto _test_eof247;
	/* fall through */
case 247:
#line 6494 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr361;
		case 44: goto tr376;
		case 62: goto tr377;
		case 92: goto tr374;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr373;
	goto tr356;
tr385:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st248;
tr376:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st248;
st248:
	if ( ++p == pe )
		goto _test_eof248;
	/* fall through */
case 248:
#line 6525 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr361;
		case 43: goto tr379;
		case 47: goto tr373;
		case 92: goto tr374;
		case 95: goto tr379;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr373;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr380;
		} else
			goto tr379;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr380;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr373;
			} else if ( (*p) >= 97 )
				goto tr380;
		} else
			goto tr373;
	} else
		goto tr373;
	goto tr378;
tr379:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st249;
tr381:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st249;
st249:
	if ( ++p == pe )
		goto _test_eof249;
	/* fall through */
case 249:
#line 6578 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr361;
		case 43: goto tr381;
		case 47: goto tr373;
		case 92: goto tr374;
		case 95: goto tr381;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr373;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr382;
		} else
			goto tr381;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr382;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr373;
			} else if ( (*p) >= 97 )
				goto tr382;
		} else
			goto tr373;
	} else
		goto tr373;
	goto tr378;
tr380:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st250;
tr382:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st250;
st250:
	if ( ++p == pe )
		goto _test_eof250;
	/* fall through */
case 250:
#line 6631 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr361;
		case 43: goto tr382;
		case 47: goto tr373;
		case 61: goto tr383;
		case 92: goto tr374;
		case 95: goto tr382;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr373;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr373;
		} else
			goto tr382;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr373;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr373;
		} else
			goto tr382;
	} else
		goto tr382;
	goto tr378;
tr383:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st251;
st251:
	if ( ++p == pe )
		goto _test_eof251;
	/* fall through */
case 251:
#line 6676 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr384;
		case 92: goto tr374;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr373;
	goto tr356;
tr384:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st252;
st252:
	if ( ++p == pe )
		goto _test_eof252;
	/* fall through */
case 252:
#line 6695 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr358;
		case 44: goto tr385;
		case 62: goto tr386;
		case 92: goto tr372;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr371;
	goto tr356;
tr386:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st253;
tr377:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st253;
st253:
	if ( ++p == pe )
		goto _test_eof253;
	/* fall through */
case 253:
#line 6726 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
		case 34: goto tr361;
		case 92: goto tr374;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr373;
	goto tr356;
st254:
	if ( ++p == pe )
		goto _test_eof254;
	/* fall through */
case 254:
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
	}
	goto tr308;
tr359:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st255;
tr362:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st255;
st255:
	if ( ++p == pe )
		goto _test_eof255;
	/* fall through */
case 255:
#line 6767 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr387;
		case 92: goto tr362;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr360;
	goto tr356;
tr387:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st256;
st256:
	if ( ++p == pe )
		goto _test_eof256;
	/* fall through */
case 256:
#line 6790 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr361;
		case 44: goto tr388;
		case 62: goto tr389;
		case 92: goto tr362;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr360;
	goto tr356;
tr388:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st257;
st257:
	if ( ++p == pe )
		goto _test_eof257;
	/* fall through */
case 257:
#line 6811 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr361;
		case 43: goto tr391;
		case 47: goto tr360;
		case 92: goto tr362;
		case 95: goto tr391;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr360;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr392;
		} else
			goto tr391;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr392;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr360;
			} else if ( (*p) >= 97 )
				goto tr392;
		} else
			goto tr360;
	} else
		goto tr360;
	goto tr390;
tr393:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st258;
tr391:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st258;
st258:
	if ( ++p == pe )
		goto _test_eof258;
	/* fall through */
case 258:
#line 6864 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr361;
		case 43: goto tr393;
		case 47: goto tr360;
		case 92: goto tr362;
		case 95: goto tr393;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr360;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr394;
		} else
			goto tr393;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr394;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr360;
			} else if ( (*p) >= 97 )
				goto tr394;
		} else
			goto tr360;
	} else
		goto tr360;
	goto tr390;
tr394:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st259;
tr392:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st259;
st259:
	if ( ++p == pe )
		goto _test_eof259;
	/* fall through */
case 259:
#line 6917 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr361;
		case 43: goto tr394;
		case 47: goto tr360;
		case 61: goto tr395;
		case 92: goto tr362;
		case 95: goto tr394;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr360;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr360;
		} else
			goto tr394;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr360;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr360;
		} else
			goto tr394;
	} else
		goto tr394;
	goto tr390;
tr395:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st260;
st260:
	if ( ++p == pe )
		goto _test_eof260;
	/* fall through */
case 260:
#line 6962 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr384;
		case 92: goto tr362;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr360;
	goto tr356;
tr389:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st261;
st261:
	if ( ++p == pe )
		goto _test_eof261;
	/* fall through */
case 261:
#line 6981 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
		case 34: goto tr361;
		case 92: goto tr362;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr360;
	goto tr356;
tr396:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st262;
tr332:
#line 148 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Number");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st262;
st262:
	if ( ++p == pe )
		goto _test_eof262;
	/* fall through */
case 262:
#line 7016 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 44 )
		goto tr333;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr396;
	goto tr330;
tr34:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st263;
st263:
	if ( ++p == pe )
		goto _test_eof263;
	/* fall through */
case 263:
#line 7037 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 69: goto tr398;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr397;
tr398:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st264;
st264:
	if ( ++p == pe )
		goto _test_eof264;
	/* fall through */
case 264:
#line 7056 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 84: goto tr399;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr397;
tr399:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st265;
st265:
	if ( ++p == pe )
		goto _test_eof265;
	/* fall through */
case 265:
#line 7075 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 65: goto st266;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr397;
st266:
	if ( ++p == pe )
		goto _test_eof266;
	/* fall through */
case 266:
	if ( (*p) == 61 )
		goto tr401;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr397;
tr401:
#line 168 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "META");
    }
	goto st267;
st267:
	if ( ++p == pe )
		goto _test_eof267;
	/* fall through */
case 267:
#line 7104 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 60 )
		goto st268;
	goto tr397;
st268:
	if ( ++p == pe )
		goto _test_eof268;
	/* fall through */
case 268:
	if ( (*p) == 73 )
		goto st269;
	goto tr397;
st269:
	if ( ++p == pe )
		goto _test_eof269;
	/* fall through */
case 269:
	if ( (*p) == 68 )
		goto st270;
	goto tr397;
st270:
	if ( ++p == pe )
		goto _test_eof270;
	/* fall through */
case 270:
	if ( (*p) == 61 )
		goto st271;
	goto tr397;
st271:
	if ( ++p == pe )
		goto _test_eof271;
	/* fall through */
case 271:
	switch( (*p) ) {
		case 43: goto tr407;
		case 95: goto tr407;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr407;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr408;
		} else if ( (*p) >= 65 )
			goto tr408;
	} else
		goto tr408;
	goto tr406;
tr407:
#line 144 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st272;
st272:
	if ( ++p == pe )
		goto _test_eof272;
	/* fall through */
case 272:
#line 7168 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto st272;
		case 95: goto st272;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st272;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr410;
		} else if ( (*p) >= 65 )
			goto tr410;
	} else
		goto tr410;
	goto tr406;
tr410:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st273;
tr408:
#line 144 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st273;
st273:
	if ( ++p == pe )
		goto _test_eof273;
	/* fall through */
case 273:
#line 7210 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 44: goto tr411;
		case 95: goto tr410;
	}
	if ( (*p) < 48 ) {
		if ( 43 <= (*p) && (*p) <= 46 )
			goto tr410;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr410;
		} else if ( (*p) >= 65 )
			goto tr410;
	} else
		goto tr410;
	goto tr406;
tr411:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st274;
st274:
	if ( ++p == pe )
		goto _test_eof274;
	/* fall through */
case 274:
#line 7238 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 78 )
		goto st275;
	goto tr397;
st275:
	if ( ++p == pe )
		goto _test_eof275;
	/* fall through */
case 275:
	if ( (*p) == 117 )
		goto st276;
	goto tr397;
st276:
	if ( ++p == pe )
		goto _test_eof276;
	/* fall through */
case 276:
	if ( (*p) == 109 )
		goto st277;
	goto tr397;
st277:
	if ( ++p == pe )
		goto _test_eof277;
	/* fall through */
case 277:
	if ( (*p) == 98 )
		goto st278;
	goto tr397;
st278:
	if ( ++p == pe )
		goto _test_eof278;
	/* fall through */
case 278:
	if ( (*p) == 101 )
		goto st279;
	goto tr397;
st279:
	if ( ++p == pe )
		goto _test_eof279;
	/* fall through */
case 279:
	if ( (*p) == 114 )
		goto st280;
	goto tr397;
st280:
	if ( ++p == pe )
		goto _test_eof280;
	/* fall through */
case 280:
	if ( (*p) == 61 )
		goto st281;
	goto tr397;
st281:
	if ( ++p == pe )
		goto _test_eof281;
	/* fall through */
case 281:
	if ( (*p) == 46 )
		goto tr420;
	goto tr419;
tr420:
#line 148 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Number");
    }
	goto st282;
st282:
	if ( ++p == pe )
		goto _test_eof282;
	/* fall through */
case 282:
#line 7309 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 44 )
		goto st283;
	goto tr419;
st283:
	if ( ++p == pe )
		goto _test_eof283;
	/* fall through */
case 283:
	if ( (*p) == 84 )
		goto st284;
	goto tr397;
st284:
	if ( ++p == pe )
		goto _test_eof284;
	/* fall through */
case 284:
	if ( (*p) == 121 )
		goto st285;
	goto tr397;
st285:
	if ( ++p == pe )
		goto _test_eof285;
	/* fall through */
case 285:
	if ( (*p) == 112 )
		goto st286;
	goto tr397;
st286:
	if ( ++p == pe )
		goto _test_eof286;
	/* fall through */
case 286:
	if ( (*p) == 101 )
		goto st287;
	goto tr397;
st287:
	if ( ++p == pe )
		goto _test_eof287;
	/* fall through */
case 287:
	if ( (*p) == 61 )
		goto st288;
	goto tr397;
st288:
	if ( ++p == pe )
		goto _test_eof288;
	/* fall through */
case 288:
	if ( (*p) == 83 )
		goto tr428;
	goto tr427;
tr428:
#line 152 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Type");
    }
	goto st289;
st289:
	if ( ++p == pe )
		goto _test_eof289;
	/* fall through */
case 289:
#line 7372 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 116 )
		goto st290;
	goto tr427;
st290:
	if ( ++p == pe )
		goto _test_eof290;
	/* fall through */
case 290:
	if ( (*p) == 114 )
		goto st291;
	goto tr427;
st291:
	if ( ++p == pe )
		goto _test_eof291;
	/* fall through */
case 291:
	if ( (*p) == 105 )
		goto st292;
	goto tr427;
st292:
	if ( ++p == pe )
		goto _test_eof292;
	/* fall through */
case 292:
	if ( (*p) == 110 )
		goto st293;
	goto tr427;
st293:
	if ( ++p == pe )
		goto _test_eof293;
	/* fall through */
case 293:
	if ( (*p) == 103 )
		goto st294;
	goto tr427;
st294:
	if ( ++p == pe )
		goto _test_eof294;
	/* fall through */
case 294:
	if ( (*p) == 44 )
		goto st295;
	goto tr427;
st295:
	if ( ++p == pe )
		goto _test_eof295;
	/* fall through */
case 295:
	if ( (*p) == 86 )
		goto st296;
	goto tr397;
st296:
	if ( ++p == pe )
		goto _test_eof296;
	/* fall through */
case 296:
	if ( (*p) == 97 )
		goto st297;
	goto tr397;
st297:
	if ( ++p == pe )
		goto _test_eof297;
	/* fall through */
case 297:
	if ( (*p) == 108 )
		goto st298;
	goto tr397;
st298:
	if ( ++p == pe )
		goto _test_eof298;
	/* fall through */
case 298:
	if ( (*p) == 117 )
		goto st299;
	goto tr397;
st299:
	if ( ++p == pe )
		goto _test_eof299;
	/* fall through */
case 299:
	if ( (*p) == 101 )
		goto st300;
	goto tr397;
st300:
	if ( ++p == pe )
		goto _test_eof300;
	/* fall through */
case 300:
	if ( (*p) == 115 )
		goto st301;
	goto tr397;
st301:
	if ( ++p == pe )
		goto _test_eof301;
	/* fall through */
case 301:
	if ( (*p) == 61 )
		goto st302;
	goto tr397;
st302:
	if ( ++p == pe )
		goto _test_eof302;
	/* fall through */
case 302:
	if ( (*p) == 91 )
		goto tr442;
	goto tr397;
tr442:
#line 172 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Values");
    }
	goto st303;
st303:
	if ( ++p == pe )
		goto _test_eof303;
	/* fall through */
case 303:
#line 7491 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 61 )
		goto tr443;
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr443;
	} else if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr443;
	} else
		goto tr443;
	goto tr397;
tr443:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st304;
tr445:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st304;
st304:
	if ( ++p == pe )
		goto _test_eof304;
	/* fall through */
case 304:
#line 7524 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 44: goto tr446;
		case 61: goto tr445;
		case 93: goto tr447;
	}
	if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr445;
	} else if ( (*p) >= 33 )
		goto tr445;
	goto tr444;
tr446:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st305;
st305:
	if ( ++p == pe )
		goto _test_eof305;
	/* fall through */
case 305:
#line 7547 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 32: goto tr448;
		case 61: goto tr445;
	}
	if ( (*p) < 33 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr448;
	} else if ( (*p) > 43 ) {
		if ( (*p) > 59 ) {
			if ( 63 <= (*p) && (*p) <= 126 )
				goto tr445;
		} else if ( (*p) >= 45 )
			goto tr445;
	} else
		goto tr445;
	goto tr397;
tr448:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st306;
st306:
	if ( ++p == pe )
		goto _test_eof306;
	/* fall through */
case 306:
#line 7575 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 61 )
		goto tr445;
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr445;
	} else if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr445;
	} else
		goto tr445;
	goto tr397;
tr447:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st307;
st307:
	if ( ++p == pe )
		goto _test_eof307;
	/* fall through */
case 307:
#line 7602 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 44: goto tr446;
		case 62: goto st308;
		case 93: goto tr447;
	}
	if ( (*p) > 59 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr445;
	} else if ( (*p) >= 33 )
		goto tr445;
	goto tr444;
st308:
	if ( ++p == pe )
		goto _test_eof308;
	/* fall through */
case 308:
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
	}
	goto tr397;
tr35:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st309;
st309:
	if ( ++p == pe )
		goto _test_eof309;
	/* fall through */
case 309:
#line 7639 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 69: goto tr451;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr450;
tr451:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st310;
st310:
	if ( ++p == pe )
		goto _test_eof310;
	/* fall through */
case 310:
#line 7658 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 68: goto tr452;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr450;
tr452:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st311;
st311:
	if ( ++p == pe )
		goto _test_eof311;
	/* fall through */
case 311:
#line 7677 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 73: goto tr453;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr450;
tr453:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st312;
st312:
	if ( ++p == pe )
		goto _test_eof312;
	/* fall through */
case 312:
#line 7696 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 71: goto tr454;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr450;
tr454:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st313;
st313:
	if ( ++p == pe )
		goto _test_eof313;
	/* fall through */
case 313:
#line 7715 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 82: goto tr455;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr450;
tr455:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st314;
st314:
	if ( ++p == pe )
		goto _test_eof314;
	/* fall through */
case 314:
#line 7734 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 69: goto tr456;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr450;
tr456:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st315;
st315:
	if ( ++p == pe )
		goto _test_eof315;
	/* fall through */
case 315:
#line 7753 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 69: goto st316;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr450;
st316:
	if ( ++p == pe )
		goto _test_eof316;
	/* fall through */
case 316:
	if ( (*p) == 61 )
		goto tr458;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr450;
tr458:
#line 132 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "PEDIGREE");
    }
	goto st317;
st317:
	if ( ++p == pe )
		goto _test_eof317;
	/* fall through */
case 317:
#line 7782 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 60 )
		goto st318;
	goto tr450;
st318:
	if ( ++p == pe )
		goto _test_eof318;
	/* fall through */
case 318:
	if ( (*p) == 73 )
		goto st319;
	goto tr450;
st319:
	if ( ++p == pe )
		goto _test_eof319;
	/* fall through */
case 319:
	if ( (*p) == 68 )
		goto st320;
	goto tr450;
st320:
	if ( ++p == pe )
		goto _test_eof320;
	/* fall through */
case 320:
	if ( (*p) == 61 )
		goto st321;
	goto tr450;
st321:
	if ( ++p == pe )
		goto _test_eof321;
	/* fall through */
case 321:
	switch( (*p) ) {
		case 43: goto tr464;
		case 95: goto tr464;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr464;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr465;
		} else if ( (*p) >= 65 )
			goto tr465;
	} else
		goto tr465;
	goto tr463;
tr464:
#line 144 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st322;
st322:
	if ( ++p == pe )
		goto _test_eof322;
	/* fall through */
case 322:
#line 7846 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto st322;
		case 95: goto st322;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st322;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr467;
		} else if ( (*p) >= 65 )
			goto tr467;
	} else
		goto tr467;
	goto tr463;
tr467:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st323;
tr465:
#line 144 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st323;
st323:
	if ( ++p == pe )
		goto _test_eof323;
	/* fall through */
case 323:
#line 7888 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 44: goto tr468;
		case 95: goto tr467;
	}
	if ( (*p) < 48 ) {
		if ( 43 <= (*p) && (*p) <= 46 )
			goto tr467;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr467;
		} else if ( (*p) >= 65 )
			goto tr467;
	} else
		goto tr467;
	goto tr463;
tr468:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st324;
st324:
	if ( ++p == pe )
		goto _test_eof324;
	/* fall through */
case 324:
#line 7916 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 70: goto st325;
		case 78: goto tr471;
		case 79: goto st355;
	}
	goto tr469;
st325:
	if ( ++p == pe )
		goto _test_eof325;
	/* fall through */
case 325:
	if ( (*p) == 97 )
		goto st326;
	goto tr450;
st326:
	if ( ++p == pe )
		goto _test_eof326;
	/* fall through */
case 326:
	if ( (*p) == 116 )
		goto st327;
	goto tr450;
st327:
	if ( ++p == pe )
		goto _test_eof327;
	/* fall through */
case 327:
	if ( (*p) == 104 )
		goto st328;
	goto tr450;
st328:
	if ( ++p == pe )
		goto _test_eof328;
	/* fall through */
case 328:
	if ( (*p) == 101 )
		goto st329;
	goto tr450;
st329:
	if ( ++p == pe )
		goto _test_eof329;
	/* fall through */
case 329:
	if ( (*p) == 114 )
		goto st330;
	goto tr450;
st330:
	if ( ++p == pe )
		goto _test_eof330;
	/* fall through */
case 330:
	if ( (*p) == 61 )
		goto st331;
	goto tr450;
st331:
	if ( ++p == pe )
		goto _test_eof331;
	/* fall through */
case 331:
	switch( (*p) ) {
		case 43: goto tr480;
		case 95: goto tr480;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr480;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr481;
		} else if ( (*p) >= 65 )
			goto tr481;
	} else
		goto tr481;
	goto tr479;
tr480:
#line 180 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Father");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st332;
st332:
	if ( ++p == pe )
		goto _test_eof332;
	/* fall through */
case 332:
#line 8007 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto st332;
		case 95: goto st332;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st332;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr483;
		} else if ( (*p) >= 65 )
			goto tr483;
	} else
		goto tr483;
	goto tr479;
tr483:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st333;
tr481:
#line 180 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Father");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st333;
st333:
	if ( ++p == pe )
		goto _test_eof333;
	/* fall through */
case 333:
#line 8049 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 44: goto tr484;
		case 95: goto tr483;
	}
	if ( (*p) < 48 ) {
		if ( 43 <= (*p) && (*p) <= 46 )
			goto tr483;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr483;
		} else if ( (*p) >= 65 )
			goto tr483;
	} else
		goto tr483;
	goto tr479;
tr484:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st334;
st334:
	if ( ++p == pe )
		goto _test_eof334;
	/* fall through */
case 334:
#line 8077 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 77 )
		goto st335;
	goto tr450;
st335:
	if ( ++p == pe )
		goto _test_eof335;
	/* fall through */
case 335:
	if ( (*p) == 111 )
		goto st336;
	goto tr450;
st336:
	if ( ++p == pe )
		goto _test_eof336;
	/* fall through */
case 336:
	if ( (*p) == 116 )
		goto st337;
	goto tr450;
st337:
	if ( ++p == pe )
		goto _test_eof337;
	/* fall through */
case 337:
	if ( (*p) == 104 )
		goto st338;
	goto tr450;
st338:
	if ( ++p == pe )
		goto _test_eof338;
	/* fall through */
case 338:
	if ( (*p) == 101 )
		goto st339;
	goto tr450;
st339:
	if ( ++p == pe )
		goto _test_eof339;
	/* fall through */
case 339:
	if ( (*p) == 114 )
		goto st340;
	goto tr450;
st340:
	if ( ++p == pe )
		goto _test_eof340;
	/* fall through */
case 340:
	if ( (*p) == 61 )
		goto st341;
	goto tr450;
st341:
	if ( ++p == pe )
		goto _test_eof341;
	/* fall through */
case 341:
	switch( (*p) ) {
		case 43: goto tr492;
		case 95: goto tr492;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr492;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr493;
		} else if ( (*p) >= 65 )
			goto tr493;
	} else
		goto tr493;
	goto tr479;
tr492:
#line 184 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Mother");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st342;
st342:
	if ( ++p == pe )
		goto _test_eof342;
	/* fall through */
case 342:
#line 8165 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto st342;
		case 95: goto st342;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st342;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr495;
		} else if ( (*p) >= 65 )
			goto tr495;
	} else
		goto tr495;
	goto tr479;
tr495:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st343;
tr493:
#line 184 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Mother");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st343;
st343:
	if ( ++p == pe )
		goto _test_eof343;
	/* fall through */
case 343:
#line 8207 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr495;
		case 62: goto tr496;
		case 95: goto tr495;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr495;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr495;
		} else if ( (*p) >= 65 )
			goto tr495;
	} else
		goto tr495;
	goto tr479;
tr496:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st344;
st344:
	if ( ++p == pe )
		goto _test_eof344;
	/* fall through */
case 344:
#line 8236 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
	}
	goto tr450;
tr471:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st345;
st345:
	if ( ++p == pe )
		goto _test_eof345;
	/* fall through */
case 345:
#line 8257 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 97 )
		goto tr497;
	goto tr469;
tr497:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st346;
st346:
	if ( ++p == pe )
		goto _test_eof346;
	/* fall through */
case 346:
#line 8272 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 109 )
		goto tr498;
	goto tr469;
tr498:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st347;
st347:
	if ( ++p == pe )
		goto _test_eof347;
	/* fall through */
case 347:
#line 8287 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 101 )
		goto tr499;
	goto tr469;
tr499:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st348;
st348:
	if ( ++p == pe )
		goto _test_eof348;
	/* fall through */
case 348:
#line 8302 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 95 )
		goto tr500;
	goto tr469;
tr500:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st349;
st349:
	if ( ++p == pe )
		goto _test_eof349;
	/* fall through */
case 349:
#line 8317 "inc/vcf/validator_detail_v45.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr501;
	goto tr469;
tr501:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st350;
st350:
	if ( ++p == pe )
		goto _test_eof350;
	/* fall through */
case 350:
#line 8332 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 61 )
		goto tr502;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr501;
	goto tr469;
tr502:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st351;
st351:
	if ( ++p == pe )
		goto _test_eof351;
	/* fall through */
case 351:
#line 8349 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr503;
		case 95: goto tr503;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr503;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr504;
		} else if ( (*p) >= 65 )
			goto tr504;
	} else
		goto tr504;
	goto tr469;
tr503:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st352;
st352:
	if ( ++p == pe )
		goto _test_eof352;
	/* fall through */
case 352:
#line 8377 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto st352;
		case 95: goto st352;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st352;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr506;
		} else if ( (*p) >= 65 )
			goto tr506;
	} else
		goto tr506;
	goto tr469;
tr504:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st353;
tr506:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st353;
st353:
	if ( ++p == pe )
		goto _test_eof353;
	/* fall through */
case 353:
#line 8415 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 44: goto tr507;
		case 62: goto tr496;
		case 95: goto tr506;
	}
	if ( (*p) < 48 ) {
		if ( 43 <= (*p) && (*p) <= 46 )
			goto tr506;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr506;
		} else if ( (*p) >= 65 )
			goto tr506;
	} else
		goto tr506;
	goto tr469;
tr507:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st354;
st354:
	if ( ++p == pe )
		goto _test_eof354;
	/* fall through */
case 354:
#line 8444 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 78 )
		goto tr471;
	goto tr469;
st355:
	if ( ++p == pe )
		goto _test_eof355;
	/* fall through */
case 355:
	if ( (*p) == 114 )
		goto st356;
	goto tr450;
st356:
	if ( ++p == pe )
		goto _test_eof356;
	/* fall through */
case 356:
	if ( (*p) == 105 )
		goto st357;
	goto tr450;
st357:
	if ( ++p == pe )
		goto _test_eof357;
	/* fall through */
case 357:
	if ( (*p) == 103 )
		goto st358;
	goto tr450;
st358:
	if ( ++p == pe )
		goto _test_eof358;
	/* fall through */
case 358:
	if ( (*p) == 105 )
		goto st359;
	goto tr450;
st359:
	if ( ++p == pe )
		goto _test_eof359;
	/* fall through */
case 359:
	if ( (*p) == 110 )
		goto st360;
	goto tr450;
st360:
	if ( ++p == pe )
		goto _test_eof360;
	/* fall through */
case 360:
	if ( (*p) == 97 )
		goto st361;
	goto tr450;
st361:
	if ( ++p == pe )
		goto _test_eof361;
	/* fall through */
case 361:
	if ( (*p) == 108 )
		goto st362;
	goto tr450;
st362:
	if ( ++p == pe )
		goto _test_eof362;
	/* fall through */
case 362:
	if ( (*p) == 61 )
		goto st363;
	goto tr450;
st363:
	if ( ++p == pe )
		goto _test_eof363;
	/* fall through */
case 363:
	switch( (*p) ) {
		case 43: goto tr517;
		case 95: goto tr517;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr517;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr518;
		} else if ( (*p) >= 65 )
			goto tr518;
	} else
		goto tr518;
	goto tr516;
tr517:
#line 176 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Original");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st364;
st364:
	if ( ++p == pe )
		goto _test_eof364;
	/* fall through */
case 364:
#line 8548 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto st364;
		case 95: goto st364;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st364;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr520;
		} else if ( (*p) >= 65 )
			goto tr520;
	} else
		goto tr520;
	goto tr516;
tr520:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st365;
tr518:
#line 176 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Original");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st365;
st365:
	if ( ++p == pe )
		goto _test_eof365;
	/* fall through */
case 365:
#line 8590 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr520;
		case 62: goto tr496;
		case 95: goto tr520;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr520;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr520;
		} else if ( (*p) >= 65 )
			goto tr520;
	} else
		goto tr520;
	goto tr516;
tr36:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st366;
st366:
	if ( ++p == pe )
		goto _test_eof366;
	/* fall through */
case 366:
#line 8623 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 65: goto tr522;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr521;
tr522:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st367;
st367:
	if ( ++p == pe )
		goto _test_eof367;
	/* fall through */
case 367:
#line 8642 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 77: goto tr523;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr521;
tr523:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st368;
st368:
	if ( ++p == pe )
		goto _test_eof368;
	/* fall through */
case 368:
#line 8661 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 80: goto tr524;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr521;
tr524:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st369;
st369:
	if ( ++p == pe )
		goto _test_eof369;
	/* fall through */
case 369:
#line 8680 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 76: goto tr525;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr521;
tr525:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st370;
st370:
	if ( ++p == pe )
		goto _test_eof370;
	/* fall through */
case 370:
#line 8699 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 69: goto st371;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr521;
st371:
	if ( ++p == pe )
		goto _test_eof371;
	/* fall through */
case 371:
	if ( (*p) == 61 )
		goto tr527;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr521;
tr527:
#line 140 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "SAMPLE");
    }
	goto st372;
st372:
	if ( ++p == pe )
		goto _test_eof372;
	/* fall through */
case 372:
#line 8728 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 60 )
		goto st373;
	goto tr521;
st373:
	if ( ++p == pe )
		goto _test_eof373;
	/* fall through */
case 373:
	if ( (*p) == 73 )
		goto st374;
	goto tr521;
st374:
	if ( ++p == pe )
		goto _test_eof374;
	/* fall through */
case 374:
	if ( (*p) == 68 )
		goto st375;
	goto tr521;
st375:
	if ( ++p == pe )
		goto _test_eof375;
	/* fall through */
case 375:
	if ( (*p) == 61 )
		goto st376;
	goto tr521;
st376:
	if ( ++p == pe )
		goto _test_eof376;
	/* fall through */
case 376:
	switch( (*p) ) {
		case 43: goto tr533;
		case 95: goto tr533;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr533;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr534;
		} else if ( (*p) >= 65 )
			goto tr534;
	} else
		goto tr534;
	goto tr532;
tr533:
#line 144 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st377;
st377:
	if ( ++p == pe )
		goto _test_eof377;
	/* fall through */
case 377:
#line 8792 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto st377;
		case 95: goto st377;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st377;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr536;
		} else if ( (*p) >= 65 )
			goto tr536;
	} else
		goto tr536;
	goto tr532;
tr536:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st378;
tr534:
#line 144 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st378;
st378:
	if ( ++p == pe )
		goto _test_eof378;
	/* fall through */
case 378:
#line 8834 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 44: goto tr537;
		case 62: goto tr538;
		case 95: goto tr536;
	}
	if ( (*p) < 48 ) {
		if ( 43 <= (*p) && (*p) <= 46 )
			goto tr536;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr536;
		} else if ( (*p) >= 65 )
			goto tr536;
	} else
		goto tr536;
	goto tr532;
tr537:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st379;
st379:
	if ( ++p == pe )
		goto _test_eof379;
	/* fall through */
case 379:
#line 8863 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr539;
		case 95: goto tr539;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr539;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr540;
		} else if ( (*p) >= 65 )
			goto tr540;
	} else
		goto tr540;
	goto tr521;
tr539:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st380;
st380:
	if ( ++p == pe )
		goto _test_eof380;
	/* fall through */
case 380:
#line 8891 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto st380;
		case 95: goto st380;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st380;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr542;
		} else if ( (*p) >= 65 )
			goto tr542;
	} else
		goto tr542;
	goto tr521;
tr540:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st381;
tr542:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st381;
st381:
	if ( ++p == pe )
		goto _test_eof381;
	/* fall through */
case 381:
#line 8929 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr542;
		case 61: goto tr543;
		case 95: goto tr542;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr542;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr542;
		} else if ( (*p) >= 65 )
			goto tr542;
	} else
		goto tr542;
	goto tr521;
tr543:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st382;
st382:
	if ( ++p == pe )
		goto _test_eof382;
	/* fall through */
case 382:
#line 8958 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 34 )
		goto st385;
	if ( (*p) < 45 ) {
		if ( 32 <= (*p) && (*p) <= 43 )
			goto tr544;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr544;
	} else
		goto tr544;
	goto tr521;
tr544:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st383;
tr546:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st383;
st383:
	if ( ++p == pe )
		goto _test_eof383;
	/* fall through */
case 383:
#line 8991 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 44: goto tr537;
		case 62: goto tr538;
	}
	if ( (*p) > 33 ) {
		if ( 35 <= (*p) && (*p) <= 126 )
			goto tr546;
	} else if ( (*p) >= 32 )
		goto tr546;
	goto tr521;
tr538:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st384;
st384:
	if ( ++p == pe )
		goto _test_eof384;
	/* fall through */
case 384:
#line 9013 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
	}
	goto tr521;
st385:
	if ( ++p == pe )
		goto _test_eof385;
	/* fall through */
case 385:
	switch( (*p) ) {
		case 34: goto tr548;
		case 92: goto tr549;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr547;
	goto tr521;
tr547:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st386;
tr550:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st386;
st386:
	if ( ++p == pe )
		goto _test_eof386;
	/* fall through */
case 386:
#line 9052 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr551;
		case 92: goto tr552;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr550;
	goto tr521;
tr548:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st387;
tr551:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st387;
st387:
	if ( ++p == pe )
		goto _test_eof387;
	/* fall through */
case 387:
#line 9081 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 44: goto st379;
		case 62: goto st384;
	}
	goto tr521;
tr549:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st388;
tr552:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st388;
st388:
	if ( ++p == pe )
		goto _test_eof388;
	/* fall through */
case 388:
#line 9108 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr555;
		case 92: goto tr552;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr550;
	goto tr521;
tr555:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st389;
st389:
	if ( ++p == pe )
		goto _test_eof389;
	/* fall through */
case 389:
#line 9131 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr551;
		case 44: goto tr556;
		case 62: goto tr557;
		case 92: goto tr552;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr550;
	goto tr521;
tr570:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st390;
tr556:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st390;
tr567:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st390;
st390:
	if ( ++p == pe )
		goto _test_eof390;
	/* fall through */
case 390:
#line 9172 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr551;
		case 43: goto tr558;
		case 47: goto tr550;
		case 92: goto tr552;
		case 95: goto tr558;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr550;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr559;
		} else
			goto tr558;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr559;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr550;
			} else if ( (*p) >= 97 )
				goto tr559;
		} else
			goto tr550;
	} else
		goto tr550;
	goto tr521;
tr558:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st391;
tr560:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st391;
st391:
	if ( ++p == pe )
		goto _test_eof391;
	/* fall through */
case 391:
#line 9225 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr551;
		case 43: goto tr560;
		case 47: goto tr550;
		case 92: goto tr552;
		case 95: goto tr560;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr550;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr561;
		} else
			goto tr560;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr561;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr550;
			} else if ( (*p) >= 97 )
				goto tr561;
		} else
			goto tr550;
	} else
		goto tr550;
	goto tr521;
tr559:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st392;
tr561:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st392;
st392:
	if ( ++p == pe )
		goto _test_eof392;
	/* fall through */
case 392:
#line 9278 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr551;
		case 43: goto tr561;
		case 47: goto tr550;
		case 61: goto tr562;
		case 92: goto tr552;
		case 95: goto tr561;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr550;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr550;
		} else
			goto tr561;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr550;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr550;
		} else
			goto tr561;
	} else
		goto tr561;
	goto tr521;
tr562:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st393;
st393:
	if ( ++p == pe )
		goto _test_eof393;
	/* fall through */
case 393:
#line 9323 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr564;
		case 44: goto tr550;
		case 62: goto tr550;
		case 92: goto tr565;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr563;
	goto tr521;
tr566:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st394;
tr563:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st394;
st394:
	if ( ++p == pe )
		goto _test_eof394;
	/* fall through */
case 394:
#line 9354 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr551;
		case 44: goto tr567;
		case 62: goto tr568;
		case 92: goto tr569;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr566;
	goto tr521;
tr571:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st395;
tr557:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st395;
tr568:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st395;
st395:
	if ( ++p == pe )
		goto _test_eof395;
	/* fall through */
case 395:
#line 9395 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
		case 34: goto tr551;
		case 92: goto tr552;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr550;
	goto tr521;
tr569:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st396;
tr565:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st396;
st396:
	if ( ++p == pe )
		goto _test_eof396;
	/* fall through */
case 396:
#line 9426 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr555;
		case 44: goto tr567;
		case 62: goto tr568;
		case 92: goto tr569;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr566;
	goto tr521;
tr564:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st397;
st397:
	if ( ++p == pe )
		goto _test_eof397;
	/* fall through */
case 397:
#line 9447 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr548;
		case 44: goto tr570;
		case 62: goto tr571;
		case 92: goto tr549;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr547;
	goto tr521;
tr37:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st398;
st398:
	if ( ++p == pe )
		goto _test_eof398;
	/* fall through */
case 398:
#line 9472 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 115: goto tr573;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr572;
tr573:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st399;
st399:
	if ( ++p == pe )
		goto _test_eof399;
	/* fall through */
case 399:
#line 9491 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 115: goto tr574;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr572;
tr574:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st400;
st400:
	if ( ++p == pe )
		goto _test_eof400;
	/* fall through */
case 400:
#line 9510 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 101: goto tr575;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr572;
tr575:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st401;
st401:
	if ( ++p == pe )
		goto _test_eof401;
	/* fall through */
case 401:
#line 9529 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 109: goto tr576;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr572;
tr576:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st402;
st402:
	if ( ++p == pe )
		goto _test_eof402;
	/* fall through */
case 402:
#line 9548 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 98: goto tr577;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr572;
tr577:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st403;
st403:
	if ( ++p == pe )
		goto _test_eof403;
	/* fall through */
case 403:
#line 9567 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 108: goto tr578;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr572;
tr578:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st404;
st404:
	if ( ++p == pe )
		goto _test_eof404;
	/* fall through */
case 404:
#line 9586 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 121: goto st405;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr572;
st405:
	if ( ++p == pe )
		goto _test_eof405;
	/* fall through */
case 405:
	if ( (*p) == 61 )
		goto tr580;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr572;
tr580:
#line 112 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "assembly");
    }
	goto st406;
st406:
	if ( ++p == pe )
		goto _test_eof406;
	/* fall through */
case 406:
#line 9615 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr582;
	} else if ( (*p) >= 65 )
		goto tr582;
	goto tr581;
tr582:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st407;
st407:
	if ( ++p == pe )
		goto _test_eof407;
	/* fall through */
case 407:
#line 9633 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 10: goto tr581;
		case 13: goto tr584;
		case 35: goto tr581;
		case 47: goto tr581;
		case 58: goto tr581;
		case 63: goto tr581;
	}
	goto st408;
tr584:
#line 43 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st408;
st408:
	if ( ++p == pe )
		goto _test_eof408;
	/* fall through */
case 408:
#line 9660 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 10: goto tr581;
		case 13: goto tr584;
		case 35: goto tr581;
		case 47: goto tr581;
		case 58: goto st409;
		case 63: goto tr581;
	}
	goto st408;
st409:
	if ( ++p == pe )
		goto _test_eof409;
	/* fall through */
case 409:
	if ( (*p) == 47 )
		goto st410;
	goto tr581;
st410:
	if ( ++p == pe )
		goto _test_eof410;
	/* fall through */
case 410:
	if ( (*p) == 47 )
		goto st411;
	goto tr581;
st411:
	if ( ++p == pe )
		goto _test_eof411;
	/* fall through */
case 411:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st412;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr589;
	} else
		goto tr589;
	goto tr581;
st412:
	if ( ++p == pe )
		goto _test_eof412;
	/* fall through */
case 412:
	if ( (*p) == 46 )
		goto st413;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st423;
	goto tr581;
st413:
	if ( ++p == pe )
		goto _test_eof413;
	/* fall through */
case 413:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st414;
	goto tr581;
st414:
	if ( ++p == pe )
		goto _test_eof414;
	/* fall through */
case 414:
	if ( (*p) == 46 )
		goto st415;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st421;
	goto tr581;
st415:
	if ( ++p == pe )
		goto _test_eof415;
	/* fall through */
case 415:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st416;
	goto tr581;
st416:
	if ( ++p == pe )
		goto _test_eof416;
	/* fall through */
case 416:
	if ( (*p) == 46 )
		goto st417;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st419;
	goto tr581;
st417:
	if ( ++p == pe )
		goto _test_eof417;
	/* fall through */
case 417:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr589;
	goto tr581;
tr589:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st418;
tr598:
#line 43 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 196 "src/vcf/vcf.ragel"
	{
        try {
          ParsePolicy::handle_meta_line(*this);
        } catch (Error *error) {
          ErrorPolicy::handle_error(*this, error);
        }
    }
	goto st418;
st418:
	if ( ++p == pe )
		goto _test_eof418;
	/* fall through */
case 418:
#line 9793 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 10: goto tr46;
		case 13: goto tr598;
	}
	goto tr589;
st419:
	if ( ++p == pe )
		goto _test_eof419;
	/* fall through */
case 419:
	if ( (*p) == 46 )
		goto st417;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st420;
	goto tr581;
st420:
	if ( ++p == pe )
		goto _test_eof420;
	/* fall through */
case 420:
	if ( (*p) == 46 )
		goto st417;
	goto tr581;
st421:
	if ( ++p == pe )
		goto _test_eof421;
	/* fall through */
case 421:
	if ( (*p) == 46 )
		goto st415;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st422;
	goto tr581;
st422:
	if ( ++p == pe )
		goto _test_eof422;
	/* fall through */
case 422:
	if ( (*p) == 46 )
		goto st415;
	goto tr581;
st423:
	if ( ++p == pe )
		goto _test_eof423;
	/* fall through */
case 423:
	if ( (*p) == 46 )
		goto st413;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st424;
	goto tr581;
st424:
	if ( ++p == pe )
		goto _test_eof424;
	/* fall through */
case 424:
	if ( (*p) == 46 )
		goto st413;
	goto tr581;
tr38:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st425;
st425:
	if ( ++p == pe )
		goto _test_eof425;
	/* fall through */
case 425:
#line 9868 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 111: goto tr603;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr602;
tr603:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st426;
st426:
	if ( ++p == pe )
		goto _test_eof426;
	/* fall through */
case 426:
#line 9887 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 110: goto tr604;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr602;
tr604:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st427;
st427:
	if ( ++p == pe )
		goto _test_eof427;
	/* fall through */
case 427:
#line 9906 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 116: goto tr605;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr602;
tr605:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st428;
st428:
	if ( ++p == pe )
		goto _test_eof428;
	/* fall through */
case 428:
#line 9925 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 105: goto tr606;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr602;
tr606:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st429;
st429:
	if ( ++p == pe )
		goto _test_eof429;
	/* fall through */
case 429:
#line 9944 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 103: goto st430;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr602;
st430:
	if ( ++p == pe )
		goto _test_eof430;
	/* fall through */
case 430:
	if ( (*p) == 61 )
		goto tr608;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr602;
tr608:
#line 116 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "contig");
    }
	goto st431;
st431:
	if ( ++p == pe )
		goto _test_eof431;
	/* fall through */
case 431:
#line 9973 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 60 )
		goto st432;
	goto tr602;
st432:
	if ( ++p == pe )
		goto _test_eof432;
	/* fall through */
case 432:
	if ( (*p) == 73 )
		goto st433;
	goto tr602;
st433:
	if ( ++p == pe )
		goto _test_eof433;
	/* fall through */
case 433:
	if ( (*p) == 68 )
		goto st434;
	goto tr602;
st434:
	if ( ++p == pe )
		goto _test_eof434;
	/* fall through */
case 434:
	if ( (*p) == 61 )
		goto st435;
	goto tr602;
st435:
	if ( ++p == pe )
		goto _test_eof435;
	/* fall through */
case 435:
	switch( (*p) ) {
		case 43: goto tr614;
		case 92: goto tr614;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr614;
		} else if ( (*p) >= 33 )
			goto tr614;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr614;
		} else if ( (*p) >= 63 )
			goto tr614;
	} else
		goto tr614;
	goto tr613;
tr615:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st436;
tr614:
#line 144 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st436;
st436:
	if ( ++p == pe )
		goto _test_eof436;
	/* fall through */
case 436:
#line 10050 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 44: goto tr616;
		case 62: goto tr617;
		case 92: goto tr615;
	}
	if ( (*p) < 43 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr615;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr615;
		} else if ( (*p) >= 63 )
			goto tr615;
	} else
		goto tr615;
	goto tr613;
tr616:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st437;
st437:
	if ( ++p == pe )
		goto _test_eof437;
	/* fall through */
case 437:
#line 10079 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr618;
		case 95: goto tr618;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr618;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr619;
		} else if ( (*p) >= 65 )
			goto tr619;
	} else
		goto tr619;
	goto tr602;
tr618:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st438;
st438:
	if ( ++p == pe )
		goto _test_eof438;
	/* fall through */
case 438:
#line 10107 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto st438;
		case 95: goto st438;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st438;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr621;
		} else if ( (*p) >= 65 )
			goto tr621;
	} else
		goto tr621;
	goto tr602;
tr619:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st439;
tr621:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st439;
st439:
	if ( ++p == pe )
		goto _test_eof439;
	/* fall through */
case 439:
#line 10145 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr621;
		case 61: goto tr622;
		case 95: goto tr621;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr621;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr621;
		} else if ( (*p) >= 65 )
			goto tr621;
	} else
		goto tr621;
	goto tr602;
tr622:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st440;
st440:
	if ( ++p == pe )
		goto _test_eof440;
	/* fall through */
case 440:
#line 10174 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 34 )
		goto st443;
	if ( (*p) < 45 ) {
		if ( 32 <= (*p) && (*p) <= 43 )
			goto tr623;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr623;
	} else
		goto tr623;
	goto tr602;
tr623:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st441;
tr625:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st441;
st441:
	if ( ++p == pe )
		goto _test_eof441;
	/* fall through */
case 441:
#line 10207 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 44: goto tr616;
		case 62: goto tr617;
	}
	if ( (*p) > 33 ) {
		if ( 35 <= (*p) && (*p) <= 126 )
			goto tr625;
	} else if ( (*p) >= 32 )
		goto tr625;
	goto tr602;
tr617:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st442;
st442:
	if ( ++p == pe )
		goto _test_eof442;
	/* fall through */
case 442:
#line 10229 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
	}
	goto tr602;
st443:
	if ( ++p == pe )
		goto _test_eof443;
	/* fall through */
case 443:
	switch( (*p) ) {
		case 34: goto tr627;
		case 92: goto tr628;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr626;
	goto tr602;
tr626:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st444;
tr629:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st444;
st444:
	if ( ++p == pe )
		goto _test_eof444;
	/* fall through */
case 444:
#line 10268 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr630;
		case 92: goto tr631;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr629;
	goto tr602;
tr627:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st445;
tr630:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st445;
st445:
	if ( ++p == pe )
		goto _test_eof445;
	/* fall through */
case 445:
#line 10297 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 44: goto st437;
		case 62: goto st442;
	}
	goto tr602;
tr628:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st446;
tr631:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st446;
st446:
	if ( ++p == pe )
		goto _test_eof446;
	/* fall through */
case 446:
#line 10324 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr634;
		case 92: goto tr631;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr629;
	goto tr602;
tr634:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st447;
st447:
	if ( ++p == pe )
		goto _test_eof447;
	/* fall through */
case 447:
#line 10347 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr630;
		case 44: goto tr635;
		case 62: goto tr636;
		case 92: goto tr631;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr629;
	goto tr602;
tr649:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st448;
tr635:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st448;
tr646:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st448;
st448:
	if ( ++p == pe )
		goto _test_eof448;
	/* fall through */
case 448:
#line 10388 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr630;
		case 43: goto tr637;
		case 47: goto tr629;
		case 92: goto tr631;
		case 95: goto tr637;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr629;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr638;
		} else
			goto tr637;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr638;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr629;
			} else if ( (*p) >= 97 )
				goto tr638;
		} else
			goto tr629;
	} else
		goto tr629;
	goto tr602;
tr637:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st449;
tr639:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st449;
st449:
	if ( ++p == pe )
		goto _test_eof449;
	/* fall through */
case 449:
#line 10441 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr630;
		case 43: goto tr639;
		case 47: goto tr629;
		case 92: goto tr631;
		case 95: goto tr639;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr629;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr640;
		} else
			goto tr639;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr640;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr629;
			} else if ( (*p) >= 97 )
				goto tr640;
		} else
			goto tr629;
	} else
		goto tr629;
	goto tr602;
tr638:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st450;
tr640:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st450;
st450:
	if ( ++p == pe )
		goto _test_eof450;
	/* fall through */
case 450:
#line 10494 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr630;
		case 43: goto tr640;
		case 47: goto tr629;
		case 61: goto tr641;
		case 92: goto tr631;
		case 95: goto tr640;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr629;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr629;
		} else
			goto tr640;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr629;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr629;
		} else
			goto tr640;
	} else
		goto tr640;
	goto tr602;
tr641:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st451;
st451:
	if ( ++p == pe )
		goto _test_eof451;
	/* fall through */
case 451:
#line 10539 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr643;
		case 44: goto tr629;
		case 62: goto tr629;
		case 92: goto tr644;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr642;
	goto tr602;
tr645:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st452;
tr642:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st452;
st452:
	if ( ++p == pe )
		goto _test_eof452;
	/* fall through */
case 452:
#line 10570 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr630;
		case 44: goto tr646;
		case 62: goto tr647;
		case 92: goto tr648;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr645;
	goto tr602;
tr650:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st453;
tr636:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st453;
tr647:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st453;
st453:
	if ( ++p == pe )
		goto _test_eof453;
	/* fall through */
case 453:
#line 10611 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
		case 34: goto tr630;
		case 92: goto tr631;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr629;
	goto tr602;
tr648:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st454;
tr644:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st454;
st454:
	if ( ++p == pe )
		goto _test_eof454;
	/* fall through */
case 454:
#line 10642 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr634;
		case 44: goto tr646;
		case 62: goto tr647;
		case 92: goto tr648;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr645;
	goto tr602;
tr643:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st455;
st455:
	if ( ++p == pe )
		goto _test_eof455;
	/* fall through */
case 455:
#line 10663 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr627;
		case 44: goto tr649;
		case 62: goto tr650;
		case 92: goto tr628;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr626;
	goto tr602;
tr39:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st456;
st456:
	if ( ++p == pe )
		goto _test_eof456;
	/* fall through */
case 456:
#line 10688 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 101: goto tr652;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr651;
tr652:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st457;
st457:
	if ( ++p == pe )
		goto _test_eof457;
	/* fall through */
case 457:
#line 10707 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 100: goto tr653;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr651;
tr653:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st458;
st458:
	if ( ++p == pe )
		goto _test_eof458;
	/* fall through */
case 458:
#line 10726 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 105: goto tr654;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr651;
tr654:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st459;
st459:
	if ( ++p == pe )
		goto _test_eof459;
	/* fall through */
case 459:
#line 10745 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 103: goto tr655;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr651;
tr655:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st460;
st460:
	if ( ++p == pe )
		goto _test_eof460;
	/* fall through */
case 460:
#line 10764 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 114: goto tr656;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr651;
tr656:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st461;
st461:
	if ( ++p == pe )
		goto _test_eof461;
	/* fall through */
case 461:
#line 10783 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 101: goto tr657;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr651;
tr657:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st462;
st462:
	if ( ++p == pe )
		goto _test_eof462;
	/* fall through */
case 462:
#line 10802 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 101: goto tr658;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr651;
tr658:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st463;
st463:
	if ( ++p == pe )
		goto _test_eof463;
	/* fall through */
case 463:
#line 10821 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 68: goto tr659;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr651;
tr659:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st464;
st464:
	if ( ++p == pe )
		goto _test_eof464;
	/* fall through */
case 464:
#line 10840 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 66: goto st465;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr651;
st465:
	if ( ++p == pe )
		goto _test_eof465;
	/* fall through */
case 465:
	if ( (*p) == 61 )
		goto tr661;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr651;
tr661:
#line 136 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "pedigreeDB");
    }
	goto st466;
st466:
	if ( ++p == pe )
		goto _test_eof466;
	/* fall through */
case 466:
#line 10869 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 60 )
		goto st467;
	goto tr651;
st467:
	if ( ++p == pe )
		goto _test_eof467;
	/* fall through */
case 467:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr664;
	} else if ( (*p) >= 65 )
		goto tr664;
	goto tr663;
tr664:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st468;
st468:
	if ( ++p == pe )
		goto _test_eof468;
	/* fall through */
case 468:
#line 10895 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 10: goto tr663;
		case 13: goto tr666;
		case 35: goto tr663;
		case 47: goto tr663;
		case 58: goto tr663;
		case 63: goto tr663;
	}
	goto st469;
tr666:
#line 43 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st469;
st469:
	if ( ++p == pe )
		goto _test_eof469;
	/* fall through */
case 469:
#line 10922 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 10: goto tr663;
		case 13: goto tr666;
		case 35: goto tr663;
		case 47: goto tr663;
		case 58: goto st470;
		case 63: goto tr663;
	}
	goto st469;
st470:
	if ( ++p == pe )
		goto _test_eof470;
	/* fall through */
case 470:
	if ( (*p) == 47 )
		goto st471;
	goto tr663;
st471:
	if ( ++p == pe )
		goto _test_eof471;
	/* fall through */
case 471:
	if ( (*p) == 47 )
		goto st472;
	goto tr663;
st472:
	if ( ++p == pe )
		goto _test_eof472;
	/* fall through */
case 472:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st473;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr671;
	} else
		goto tr671;
	goto tr663;
st473:
	if ( ++p == pe )
		goto _test_eof473;
	/* fall through */
case 473:
	if ( (*p) == 46 )
		goto st474;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st486;
	goto tr663;
st474:
	if ( ++p == pe )
		goto _test_eof474;
	/* fall through */
case 474:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st475;
	goto tr663;
st475:
	if ( ++p == pe )
		goto _test_eof475;
	/* fall through */
case 475:
	if ( (*p) == 46 )
		goto st476;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st484;
	goto tr663;
st476:
	if ( ++p == pe )
		goto _test_eof476;
	/* fall through */
case 476:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st477;
	goto tr663;
st477:
	if ( ++p == pe )
		goto _test_eof477;
	/* fall through */
case 477:
	if ( (*p) == 46 )
		goto st478;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st482;
	goto tr663;
st478:
	if ( ++p == pe )
		goto _test_eof478;
	/* fall through */
case 478:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr671;
	goto tr663;
tr671:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st479;
tr680:
#line 43 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st479;
st479:
	if ( ++p == pe )
		goto _test_eof479;
	/* fall through */
case 479:
#line 11043 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 10: goto tr663;
		case 13: goto tr680;
		case 62: goto tr681;
	}
	goto tr671;
tr681:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st480;
st480:
	if ( ++p == pe )
		goto _test_eof480;
	/* fall through */
case 480:
#line 11065 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr682;
		case 62: goto tr681;
	}
	goto tr671;
tr682:
#line 43 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 196 "src/vcf/vcf.ragel"
	{
        try {
          ParsePolicy::handle_meta_line(*this);
        } catch (Error *error) {
          ErrorPolicy::handle_error(*this, error);
        }
    }
	goto st481;
st481:
	if ( ++p == pe )
		goto _test_eof481;
	/* fall through */
case 481:
#line 11101 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 10: goto st28;
		case 13: goto tr680;
		case 62: goto tr681;
	}
	goto tr671;
st482:
	if ( ++p == pe )
		goto _test_eof482;
	/* fall through */
case 482:
	if ( (*p) == 46 )
		goto st478;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st483;
	goto tr663;
st483:
	if ( ++p == pe )
		goto _test_eof483;
	/* fall through */
case 483:
	if ( (*p) == 46 )
		goto st478;
	goto tr663;
st484:
	if ( ++p == pe )
		goto _test_eof484;
	/* fall through */
case 484:
	if ( (*p) == 46 )
		goto st476;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st485;
	goto tr663;
st485:
	if ( ++p == pe )
		goto _test_eof485;
	/* fall through */
case 485:
	if ( (*p) == 46 )
		goto st476;
	goto tr663;
st486:
	if ( ++p == pe )
		goto _test_eof486;
	/* fall through */
case 486:
	if ( (*p) == 46 )
		goto st474;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st487;
	goto tr663;
st487:
	if ( ++p == pe )
		goto _test_eof487;
	/* fall through */
case 487:
	if ( (*p) == 46 )
		goto st474;
	goto tr663;
st488:
	if ( ++p == pe )
		goto _test_eof488;
	/* fall through */
case 488:
	if ( (*p) == 72 )
		goto st489;
	goto tr686;
st489:
	if ( ++p == pe )
		goto _test_eof489;
	/* fall through */
case 489:
	if ( (*p) == 82 )
		goto st490;
	goto tr686;
st490:
	if ( ++p == pe )
		goto _test_eof490;
	/* fall through */
case 490:
	if ( (*p) == 79 )
		goto st491;
	goto tr686;
st491:
	if ( ++p == pe )
		goto _test_eof491;
	/* fall through */
case 491:
	if ( (*p) == 77 )
		goto st492;
	goto tr686;
st492:
	if ( ++p == pe )
		goto _test_eof492;
	/* fall through */
case 492:
	if ( (*p) == 9 )
		goto tr691;
	goto tr686;
tr691:
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st493;
st493:
	if ( ++p == pe )
		goto _test_eof493;
	/* fall through */
case 493:
#line 11213 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 80 )
		goto st494;
	goto tr686;
st494:
	if ( ++p == pe )
		goto _test_eof494;
	/* fall through */
case 494:
	if ( (*p) == 79 )
		goto st495;
	goto tr686;
st495:
	if ( ++p == pe )
		goto _test_eof495;
	/* fall through */
case 495:
	if ( (*p) == 83 )
		goto st496;
	goto tr686;
st496:
	if ( ++p == pe )
		goto _test_eof496;
	/* fall through */
case 496:
	if ( (*p) == 9 )
		goto tr695;
	goto tr686;
tr695:
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st497;
st497:
	if ( ++p == pe )
		goto _test_eof497;
	/* fall through */
case 497:
#line 11252 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 73 )
		goto st498;
	goto tr686;
st498:
	if ( ++p == pe )
		goto _test_eof498;
	/* fall through */
case 498:
	if ( (*p) == 68 )
		goto st499;
	goto tr686;
st499:
	if ( ++p == pe )
		goto _test_eof499;
	/* fall through */
case 499:
	if ( (*p) == 9 )
		goto tr698;
	goto tr686;
tr698:
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st500;
st500:
	if ( ++p == pe )
		goto _test_eof500;
	/* fall through */
case 500:
#line 11283 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 82 )
		goto st501;
	goto tr686;
st501:
	if ( ++p == pe )
		goto _test_eof501;
	/* fall through */
case 501:
	if ( (*p) == 69 )
		goto st502;
	goto tr686;
st502:
	if ( ++p == pe )
		goto _test_eof502;
	/* fall through */
case 502:
	if ( (*p) == 70 )
		goto st503;
	goto tr686;
st503:
	if ( ++p == pe )
		goto _test_eof503;
	/* fall through */
case 503:
	if ( (*p) == 9 )
		goto tr702;
	goto tr686;
tr702:
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st504;
st504:
	if ( ++p == pe )
		goto _test_eof504;
	/* fall through */
case 504:
#line 11322 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 65 )
		goto st505;
	goto tr686;
st505:
	if ( ++p == pe )
		goto _test_eof505;
	/* fall through */
case 505:
	if ( (*p) == 76 )
		goto st506;
	goto tr686;
st506:
	if ( ++p == pe )
		goto _test_eof506;
	/* fall through */
case 506:
	if ( (*p) == 84 )
		goto st507;
	goto tr686;
st507:
	if ( ++p == pe )
		goto _test_eof507;
	/* fall through */
case 507:
	if ( (*p) == 9 )
		goto tr706;
	goto tr686;
tr706:
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st508;
st508:
	if ( ++p == pe )
		goto _test_eof508;
	/* fall through */
case 508:
#line 11361 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 81 )
		goto st509;
	goto tr686;
st509:
	if ( ++p == pe )
		goto _test_eof509;
	/* fall through */
case 509:
	if ( (*p) == 85 )
		goto st510;
	goto tr686;
st510:
	if ( ++p == pe )
		goto _test_eof510;
	/* fall through */
case 510:
	if ( (*p) == 65 )
		goto st511;
	goto tr686;
st511:
	if ( ++p == pe )
		goto _test_eof511;
	/* fall through */
case 511:
	if ( (*p) == 76 )
		goto st512;
	goto tr686;
st512:
	if ( ++p == pe )
		goto _test_eof512;
	/* fall through */
case 512:
	if ( (*p) == 9 )
		goto tr711;
	goto tr686;
tr711:
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st513;
st513:
	if ( ++p == pe )
		goto _test_eof513;
	/* fall through */
case 513:
#line 11408 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 70 )
		goto st514;
	goto tr686;
st514:
	if ( ++p == pe )
		goto _test_eof514;
	/* fall through */
case 514:
	if ( (*p) == 73 )
		goto st515;
	goto tr686;
st515:
	if ( ++p == pe )
		goto _test_eof515;
	/* fall through */
case 515:
	if ( (*p) == 76 )
		goto st516;
	goto tr686;
st516:
	if ( ++p == pe )
		goto _test_eof516;
	/* fall through */
case 516:
	if ( (*p) == 84 )
		goto st517;
	goto tr686;
st517:
	if ( ++p == pe )
		goto _test_eof517;
	/* fall through */
case 517:
	if ( (*p) == 69 )
		goto st518;
	goto tr686;
st518:
	if ( ++p == pe )
		goto _test_eof518;
	/* fall through */
case 518:
	if ( (*p) == 82 )
		goto st519;
	goto tr686;
st519:
	if ( ++p == pe )
		goto _test_eof519;
	/* fall through */
case 519:
	if ( (*p) == 9 )
		goto tr718;
	goto tr686;
tr718:
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st520;
st520:
	if ( ++p == pe )
		goto _test_eof520;
	/* fall through */
case 520:
#line 11471 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 73 )
		goto st521;
	goto tr686;
st521:
	if ( ++p == pe )
		goto _test_eof521;
	/* fall through */
case 521:
	if ( (*p) == 78 )
		goto st522;
	goto tr686;
st522:
	if ( ++p == pe )
		goto _test_eof522;
	/* fall through */
case 522:
	if ( (*p) == 70 )
		goto st523;
	goto tr686;
st523:
	if ( ++p == pe )
		goto _test_eof523;
	/* fall through */
case 523:
	if ( (*p) == 79 )
		goto st524;
	goto tr686;
st524:
	if ( ++p == pe )
		goto _test_eof524;
	/* fall through */
case 524:
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 13: goto tr725;
	}
	goto tr686;
tr723:
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st525;
st525:
	if ( ++p == pe )
		goto _test_eof525;
	/* fall through */
case 525:
#line 11521 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 70 )
		goto st526;
	goto tr726;
st526:
	if ( ++p == pe )
		goto _test_eof526;
	/* fall through */
case 526:
	if ( (*p) == 79 )
		goto st527;
	goto tr726;
st527:
	if ( ++p == pe )
		goto _test_eof527;
	/* fall through */
case 527:
	if ( (*p) == 82 )
		goto st528;
	goto tr726;
st528:
	if ( ++p == pe )
		goto _test_eof528;
	/* fall through */
case 528:
	if ( (*p) == 77 )
		goto st529;
	goto tr726;
st529:
	if ( ++p == pe )
		goto _test_eof529;
	/* fall through */
case 529:
	if ( (*p) == 65 )
		goto st530;
	goto tr726;
st530:
	if ( ++p == pe )
		goto _test_eof530;
	/* fall through */
case 530:
	if ( (*p) == 84 )
		goto st531;
	goto tr726;
st531:
	if ( ++p == pe )
		goto _test_eof531;
	/* fall through */
case 531:
	if ( (*p) == 9 )
		goto tr733;
	goto tr726;
tr733:
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st532;
tr735:
#line 204 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_sample_name(*this);
    }
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st532;
st532:
	if ( ++p == pe )
		goto _test_eof532;
	/* fall through */
case 532:
#line 11594 "inc/vcf/validator_detail_v45.hpp"
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr734;
	goto tr726;
tr734:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st533;
tr738:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st533;
st533:
	if ( ++p == pe )
		goto _test_eof533;
	/* fall through */
case 533:
#line 11619 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 9: goto tr735;
		case 10: goto tr736;
		case 13: goto tr737;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr738;
	goto tr726;
tr724:
#line 208 "src/vcf/vcf.ragel"
	{
        try {
            ParsePolicy::handle_header_line(*this);
        } catch (Error *error) {
            ErrorPolicy::handle_error(*this, error);
        }
    }
#line 43 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st626;
tr736:
#line 204 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_sample_name(*this);
    }
#line 208 "src/vcf/vcf.ragel"
	{
        try {
            ParsePolicy::handle_header_line(*this);
        } catch (Error *error) {
            ErrorPolicy::handle_error(*this, error);
        }
    }
#line 43 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st626;
st626:
	if ( ++p == pe )
		goto _test_eof626;
	/* fall through */
case 626:
#line 11677 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 10: goto tr869;
		case 13: goto tr870;
		case 43: goto tr871;
		case 60: goto tr872;
		case 92: goto tr871;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr871;
		} else if ( (*p) >= 33 )
			goto tr871;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr871;
		} else if ( (*p) >= 63 )
			goto tr871;
	} else
		goto tr871;
	goto tr868;
tr873:
#line 43 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st627;
tr869:
#line 70 "src/vcf/vcf.ragel"
	{
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (Error *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
    }
#line 43 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st627;
st627:
	if ( ++p == pe )
		goto _test_eof627;
	/* fall through */
case 627:
#line 11737 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 10: goto tr873;
		case 13: goto tr874;
	}
	goto st0;
tr874:
#line 43 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st534;
tr870:
#line 70 "src/vcf/vcf.ragel"
	{
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (Error *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
    }
#line 43 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st534;
st534:
	if ( ++p == pe )
		goto _test_eof534;
	/* fall through */
case 534:
#line 11780 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 10 )
		goto st627;
	goto st0;
tr880:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st535;
tr743:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st535;
tr871:
#line 70 "src/vcf/vcf.ragel"
	{
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (Error *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st535;
st535:
	if ( ++p == pe )
		goto _test_eof535;
	/* fall through */
case 535:
#line 11823 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 9: goto tr742;
		case 43: goto tr743;
		case 92: goto tr743;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr743;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr743;
		} else if ( (*p) >= 63 )
			goto tr743;
	} else
		goto tr743;
	goto tr741;
tr742:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 218 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st536;
tr801:
#line 218 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st536;
st536:
	if ( ++p == pe )
		goto _test_eof536;
	/* fall through */
case 536:
#line 11870 "inc/vcf/validator_detail_v45.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr745;
	goto tr744;
tr745:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st537;
tr747:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st537;
st537:
	if ( ++p == pe )
		goto _test_eof537;
	/* fall through */
case 537:
#line 11895 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 9 )
		goto tr746;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr747;
	goto tr744;
tr752:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st538;
tr746:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 218 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st538;
st538:
	if ( ++p == pe )
		goto _test_eof538;
	/* fall through */
case 538:
#line 11926 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr749;
	} else if ( (*p) >= 33 )
		goto tr749;
	goto tr748;
tr749:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st539;
tr751:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st539;
st539:
	if ( ++p == pe )
		goto _test_eof539;
	/* fall through */
case 539:
#line 11954 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 9: goto tr750;
		case 59: goto tr752;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr751;
	goto tr748;
tr750:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 218 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st540;
st540:
	if ( ++p == pe )
		goto _test_eof540;
	/* fall through */
case 540:
#line 11981 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 65: goto tr754;
		case 67: goto tr754;
		case 71: goto tr754;
		case 78: goto tr754;
		case 84: goto tr754;
		case 97: goto tr754;
		case 99: goto tr754;
		case 103: goto tr754;
		case 110: goto tr754;
		case 116: goto tr754;
	}
	goto tr753;
tr754:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st541;
tr756:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st541;
st541:
	if ( ++p == pe )
		goto _test_eof541;
	/* fall through */
case 541:
#line 12016 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 9: goto tr755;
		case 65: goto tr756;
		case 67: goto tr756;
		case 71: goto tr756;
		case 78: goto tr756;
		case 84: goto tr756;
		case 97: goto tr756;
		case 99: goto tr756;
		case 103: goto tr756;
		case 110: goto tr756;
		case 116: goto tr756;
	}
	goto tr753;
tr755:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 218 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st542;
st542:
	if ( ++p == pe )
		goto _test_eof542;
	/* fall through */
case 542:
#line 12050 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 42: goto tr758;
		case 46: goto tr759;
		case 60: goto tr760;
		case 65: goto tr761;
		case 67: goto tr761;
		case 71: goto tr761;
		case 78: goto tr761;
		case 84: goto tr761;
		case 91: goto tr762;
		case 93: goto tr763;
		case 97: goto tr761;
		case 99: goto tr761;
		case 103: goto tr761;
		case 110: goto tr761;
		case 116: goto tr761;
	}
	goto tr757;
tr758:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st543;
tr823:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st543;
st543:
	if ( ++p == pe )
		goto _test_eof543;
	/* fall through */
case 543:
#line 12090 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 9: goto tr764;
		case 44: goto tr765;
	}
	goto tr757;
tr764:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 218 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st544;
st544:
	if ( ++p == pe )
		goto _test_eof544;
	/* fall through */
case 544:
#line 12115 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr767;
		case 45: goto tr767;
		case 46: goto tr768;
		case 73: goto tr770;
		case 78: goto tr771;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr769;
	goto tr766;
tr767:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st545;
st545:
	if ( ++p == pe )
		goto _test_eof545;
	/* fall through */
case 545:
#line 12141 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 73 )
		goto tr773;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr772;
	goto tr766;
tr769:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st546;
tr772:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st546;
st546:
	if ( ++p == pe )
		goto _test_eof546;
	/* fall through */
case 546:
#line 12168 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 9: goto tr774;
		case 46: goto tr775;
		case 69: goto tr776;
		case 101: goto tr776;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr772;
	goto tr766;
tr774:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 218 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st547;
st547:
	if ( ++p == pe )
		goto _test_eof547;
	/* fall through */
case 547:
#line 12197 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 46: goto tr779;
		case 58: goto tr778;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr778;
		} else if ( (*p) > 57 ) {
			if ( 60 <= (*p) && (*p) <= 64 )
				goto tr778;
		} else
			goto tr780;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr778;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr778;
		} else
			goto tr780;
	} else
		goto tr780;
	goto tr777;
tr778:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st548;
st548:
	if ( ++p == pe )
		goto _test_eof548;
	/* fall through */
case 548:
#line 12234 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 58 )
		goto st548;
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto st548;
		} else if ( (*p) > 57 ) {
			if ( 60 <= (*p) && (*p) <= 64 )
				goto st548;
		} else
			goto tr782;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st548;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st548;
		} else
			goto tr782;
	} else
		goto tr782;
	goto tr777;
tr780:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st549;
tr782:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st549;
st549:
	if ( ++p == pe )
		goto _test_eof549;
	/* fall through */
case 549:
#line 12279 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 9: goto tr783;
		case 59: goto tr784;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr782;
	goto tr777;
tr783:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 218 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st550;
st550:
	if ( ++p == pe )
		goto _test_eof550;
	/* fall through */
case 550:
#line 12306 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 46: goto tr786;
		case 49: goto tr787;
		case 95: goto tr788;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr788;
	} else if ( (*p) >= 65 )
		goto tr788;
	goto tr785;
tr786:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st628;
st628:
	if ( ++p == pe )
		goto _test_eof628;
	/* fall through */
case 628:
#line 12333 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 9: goto tr876;
		case 10: goto tr877;
		case 13: goto tr878;
	}
	goto tr875;
tr793:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st551;
tr876:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 218 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st551;
st551:
	if ( ++p == pe )
		goto _test_eof551;
	/* fall through */
case 551:
#line 12365 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 95 )
		goto tr790;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr790;
	} else if ( (*p) >= 65 )
		goto tr790;
	goto tr789;
tr790:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st552;
tr792:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st552;
st552:
	if ( ++p == pe )
		goto _test_eof552;
	/* fall through */
case 552:
#line 12395 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 9: goto tr791;
		case 37: goto tr792;
		case 46: goto tr792;
		case 58: goto tr793;
		case 95: goto tr792;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr792;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr792;
	} else
		goto tr792;
	goto tr789;
tr791:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 218 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st553;
st553:
	if ( ++p == pe )
		goto _test_eof553;
	/* fall through */
case 553:
#line 12431 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 46 )
		goto tr796;
	if ( (*p) < 48 ) {
		if ( 33 <= (*p) && (*p) <= 47 )
			goto tr795;
	} else if ( (*p) > 57 ) {
		if ( 59 <= (*p) && (*p) <= 126 )
			goto tr795;
	} else
		goto tr797;
	goto tr794;
tr795:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st629;
tr805:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st629;
st629:
	if ( ++p == pe )
		goto _test_eof629;
	/* fall through */
case 629:
#line 12464 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 9: goto tr791;
		case 10: goto tr877;
		case 13: goto tr878;
		case 58: goto tr879;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr805;
	goto tr804;
tr877:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 218 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 222 "src/vcf/vcf.ragel"
	{
        try {
            // Handle all columns and build record
            ParsePolicy::handle_body_line(*this);

            if (record != nullptr) {
                previous_records.check_duplicates(*record);
                
                auto duplicates = previous_records.get_duplicates();
                for(auto &error_ptr : duplicates) {
                    ErrorPolicy::handle_error(*this, error_ptr.release());
                }
                
                auto symbolic_duplicates = previous_records.get_symbolic_duplicates();
                for(auto &error_ptr : symbolic_duplicates) {
                    ErrorPolicy::handle_warning(*this, error_ptr.release());
                }
                validate_additional_checks();
            }

            try {
                // Check warnings (non-blocking errors but potential mistakes anyway, only makes sense if the last record parsed was correct)
                if (record != nullptr) {
                    OptionalPolicy::optional_check_body_entry(*this, *record);
                }
            } catch (Error *warn) {
                ErrorPolicy::handle_warning(*this, warn);
            }
        } catch (Error *error) {
            ErrorPolicy::handle_error(*this, error);
        }
    }
#line 43 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st630;
st630:
	if ( ++p == pe )
		goto _test_eof630;
	/* fall through */
case 630:
#line 12532 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 10: goto tr873;
		case 13: goto tr874;
		case 43: goto tr880;
		case 60: goto st554;
		case 92: goto tr880;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr880;
		} else if ( (*p) >= 33 )
			goto tr880;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr880;
		} else if ( (*p) >= 63 )
			goto tr880;
	} else
		goto tr880;
	goto tr741;
tr872:
#line 70 "src/vcf/vcf.ragel"
	{
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (Error *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
    }
	goto st554;
st554:
	if ( ++p == pe )
		goto _test_eof554;
	/* fall through */
case 554:
#line 12570 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr798;
		case 92: goto tr798;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr798;
		} else if ( (*p) >= 33 )
			goto tr798;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr798;
		} else if ( (*p) >= 63 )
			goto tr798;
	} else
		goto tr798;
	goto tr741;
tr798:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st555;
tr799:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st555;
st555:
	if ( ++p == pe )
		goto _test_eof555;
	/* fall through */
case 555:
#line 12611 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr799;
		case 62: goto tr800;
		case 92: goto tr799;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr799;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr799;
		} else if ( (*p) >= 63 )
			goto tr799;
	} else
		goto tr799;
	goto tr741;
tr800:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st556;
st556:
	if ( ++p == pe )
		goto _test_eof556;
	/* fall through */
case 556:
#line 12640 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 9 )
		goto tr801;
	goto tr741;
tr878:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 218 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 222 "src/vcf/vcf.ragel"
	{
        try {
            // Handle all columns and build record
            ParsePolicy::handle_body_line(*this);

            if (record != nullptr) {
                previous_records.check_duplicates(*record);
                
                auto duplicates = previous_records.get_duplicates();
                for(auto &error_ptr : duplicates) {
                    ErrorPolicy::handle_error(*this, error_ptr.release());
                }
                
                auto symbolic_duplicates = previous_records.get_symbolic_duplicates();
                for(auto &error_ptr : symbolic_duplicates) {
                    ErrorPolicy::handle_warning(*this, error_ptr.release());
                }
                validate_additional_checks();
            }

            try {
                // Check warnings (non-blocking errors but potential mistakes anyway, only makes sense if the last record parsed was correct)
                if (record != nullptr) {
                    OptionalPolicy::optional_check_body_entry(*this, *record);
                }
            } catch (Error *warn) {
                ErrorPolicy::handle_warning(*this, warn);
            }
        } catch (Error *error) {
            ErrorPolicy::handle_error(*this, error);
        }
    }
#line 43 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st557;
st557:
	if ( ++p == pe )
		goto _test_eof557;
	/* fall through */
case 557:
#line 12702 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 10 )
		goto st630;
	goto tr802;
tr879:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st558;
st558:
	if ( ++p == pe )
		goto _test_eof558;
	/* fall through */
case 558:
#line 12717 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) > 57 ) {
		if ( 59 <= (*p) && (*p) <= 126 )
			goto tr805;
	} else if ( (*p) >= 33 )
		goto tr805;
	goto tr804;
tr796:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st631;
tr883:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st631;
st631:
	if ( ++p == pe )
		goto _test_eof631;
	/* fall through */
case 631:
#line 12745 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 9: goto tr791;
		case 10: goto tr877;
		case 13: goto tr878;
		case 47: goto tr882;
		case 58: goto tr879;
		case 124: goto tr882;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr805;
	goto tr794;
tr882:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st632;
st632:
	if ( ++p == pe )
		goto _test_eof632;
	/* fall through */
case 632:
#line 12768 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 9: goto tr791;
		case 10: goto tr877;
		case 13: goto tr878;
		case 46: goto tr883;
		case 58: goto tr879;
	}
	if ( (*p) < 48 ) {
		if ( 33 <= (*p) && (*p) <= 47 )
			goto tr805;
	} else if ( (*p) > 57 ) {
		if ( 59 <= (*p) && (*p) <= 126 )
			goto tr805;
	} else
		goto tr884;
	goto tr794;
tr797:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st633;
tr884:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st633;
st633:
	if ( ++p == pe )
		goto _test_eof633;
	/* fall through */
case 633:
#line 12806 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 9: goto tr791;
		case 10: goto tr877;
		case 13: goto tr878;
		case 47: goto tr882;
		case 58: goto tr879;
		case 124: goto tr882;
	}
	if ( (*p) < 48 ) {
		if ( 33 <= (*p) && (*p) <= 46 )
			goto tr805;
	} else if ( (*p) > 57 ) {
		if ( 59 <= (*p) && (*p) <= 126 )
			goto tr805;
	} else
		goto tr884;
	goto tr794;
tr787:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st559;
st559:
	if ( ++p == pe )
		goto _test_eof559;
	/* fall through */
case 559:
#line 12839 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 48 )
		goto tr806;
	goto tr785;
tr806:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st560;
st560:
	if ( ++p == pe )
		goto _test_eof560;
	/* fall through */
case 560:
#line 12854 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 48 )
		goto tr807;
	goto tr785;
tr807:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st561;
st561:
	if ( ++p == pe )
		goto _test_eof561;
	/* fall through */
case 561:
#line 12869 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 48 )
		goto tr808;
	goto tr785;
tr808:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st562;
st562:
	if ( ++p == pe )
		goto _test_eof562;
	/* fall through */
case 562:
#line 12884 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 71 )
		goto tr809;
	goto tr785;
tr809:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st634;
st634:
	if ( ++p == pe )
		goto _test_eof634;
	/* fall through */
case 634:
#line 12899 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 9: goto tr876;
		case 10: goto tr877;
		case 13: goto tr878;
		case 59: goto tr885;
		case 61: goto tr886;
	}
	goto tr785;
tr885:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st563;
st563:
	if ( ++p == pe )
		goto _test_eof563;
	/* fall through */
case 563:
#line 12919 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 49: goto tr787;
		case 95: goto tr788;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr788;
	} else if ( (*p) >= 65 )
		goto tr788;
	goto tr785;
tr788:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st635;
tr887:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st635;
st635:
	if ( ++p == pe )
		goto _test_eof635;
	/* fall through */
case 635:
#line 12951 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 9: goto tr876;
		case 10: goto tr877;
		case 13: goto tr878;
		case 46: goto tr887;
		case 59: goto tr885;
		case 61: goto tr886;
		case 95: goto tr887;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr887;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr887;
	} else
		goto tr887;
	goto tr785;
tr886:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st564;
st564:
	if ( ++p == pe )
		goto _test_eof564;
	/* fall through */
case 564:
#line 12981 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr811;
	} else if ( (*p) >= 32 )
		goto tr811;
	goto tr810;
tr811:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st636;
st636:
	if ( ++p == pe )
		goto _test_eof636;
	/* fall through */
case 636:
#line 12999 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 9: goto tr876;
		case 10: goto tr877;
		case 13: goto tr878;
		case 59: goto tr885;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr811;
	goto tr810;
tr784:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st565;
st565:
	if ( ++p == pe )
		goto _test_eof565;
	/* fall through */
case 565:
#line 13020 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 58 )
		goto tr778;
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr778;
		} else if ( (*p) > 57 ) {
			if ( 60 <= (*p) && (*p) <= 64 )
				goto tr778;
		} else
			goto tr780;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr778;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr778;
		} else
			goto tr780;
	} else
		goto tr780;
	goto tr777;
tr779:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st566;
st566:
	if ( ++p == pe )
		goto _test_eof566;
	/* fall through */
case 566:
#line 13059 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 9: goto tr783;
		case 58: goto st548;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto st548;
		} else if ( (*p) > 57 ) {
			if ( 60 <= (*p) && (*p) <= 64 )
				goto st548;
		} else
			goto tr782;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st548;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st548;
		} else
			goto tr782;
	} else
		goto tr782;
	goto tr777;
tr775:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st567;
st567:
	if ( ++p == pe )
		goto _test_eof567;
	/* fall through */
case 567:
#line 13096 "inc/vcf/validator_detail_v45.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr812;
	goto tr766;
tr812:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st568;
st568:
	if ( ++p == pe )
		goto _test_eof568;
	/* fall through */
case 568:
#line 13111 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 9: goto tr774;
		case 69: goto tr776;
		case 101: goto tr776;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr812;
	goto tr766;
tr776:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st569;
st569:
	if ( ++p == pe )
		goto _test_eof569;
	/* fall through */
case 569:
#line 13131 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr813;
		case 45: goto tr813;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr814;
	goto tr766;
tr813:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st570;
st570:
	if ( ++p == pe )
		goto _test_eof570;
	/* fall through */
case 570:
#line 13150 "inc/vcf/validator_detail_v45.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr814;
	goto tr766;
tr814:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st571;
st571:
	if ( ++p == pe )
		goto _test_eof571;
	/* fall through */
case 571:
#line 13165 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 9 )
		goto tr774;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr814;
	goto tr766;
tr770:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st572;
tr773:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st572;
st572:
	if ( ++p == pe )
		goto _test_eof572;
	/* fall through */
case 572:
#line 13192 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 110 )
		goto tr815;
	goto tr766;
tr815:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st573;
st573:
	if ( ++p == pe )
		goto _test_eof573;
	/* fall through */
case 573:
#line 13207 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 102 )
		goto tr816;
	goto tr766;
tr768:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st574;
tr816:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st574;
st574:
	if ( ++p == pe )
		goto _test_eof574;
	/* fall through */
case 574:
#line 13232 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 9 )
		goto tr774;
	goto tr766;
tr771:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st575;
st575:
	if ( ++p == pe )
		goto _test_eof575;
	/* fall through */
case 575:
#line 13251 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 97 )
		goto tr817;
	goto tr766;
tr817:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st576;
st576:
	if ( ++p == pe )
		goto _test_eof576;
	/* fall through */
case 576:
#line 13266 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 78 )
		goto tr816;
	goto tr766;
tr765:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st577;
st577:
	if ( ++p == pe )
		goto _test_eof577;
	/* fall through */
case 577:
#line 13281 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 42: goto tr758;
		case 46: goto tr818;
		case 60: goto tr760;
		case 65: goto tr761;
		case 67: goto tr761;
		case 71: goto tr761;
		case 78: goto tr761;
		case 84: goto tr761;
		case 91: goto tr762;
		case 93: goto tr763;
		case 97: goto tr761;
		case 99: goto tr761;
		case 103: goto tr761;
		case 110: goto tr761;
		case 116: goto tr761;
	}
	goto tr757;
tr818:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st578;
tr847:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st578;
st578:
	if ( ++p == pe )
		goto _test_eof578;
	/* fall through */
case 578:
#line 13321 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 65: goto tr819;
		case 67: goto tr819;
		case 71: goto tr819;
		case 78: goto tr819;
		case 84: goto tr819;
		case 97: goto tr819;
		case 99: goto tr819;
		case 103: goto tr819;
		case 110: goto tr819;
		case 116: goto tr819;
	}
	goto tr757;
tr819:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st579;
st579:
	if ( ++p == pe )
		goto _test_eof579;
	/* fall through */
case 579:
#line 13346 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 9: goto tr764;
		case 44: goto tr765;
		case 65: goto tr819;
		case 67: goto tr819;
		case 71: goto tr819;
		case 78: goto tr819;
		case 84: goto tr819;
		case 97: goto tr819;
		case 99: goto tr819;
		case 103: goto tr819;
		case 110: goto tr819;
		case 116: goto tr819;
	}
	goto tr757;
tr760:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st580;
st580:
	if ( ++p == pe )
		goto _test_eof580;
	/* fall through */
case 580:
#line 13377 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 42: goto tr821;
		case 61: goto tr820;
	}
	if ( (*p) < 63 ) {
		if ( (*p) < 45 ) {
			if ( 33 <= (*p) && (*p) <= 43 )
				goto tr820;
		} else if ( (*p) > 47 ) {
			if ( (*p) > 57 ) {
				if ( 58 <= (*p) && (*p) <= 59 )
					goto tr820;
			} else if ( (*p) >= 48 )
				goto tr822;
		} else
			goto tr820;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr822;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr820;
			} else if ( (*p) >= 97 )
				goto tr822;
		} else
			goto tr820;
	} else
		goto tr820;
	goto tr757;
tr820:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st581;
st581:
	if ( ++p == pe )
		goto _test_eof581;
	/* fall through */
case 581:
#line 13420 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 61 )
		goto tr820;
	if ( (*p) < 63 ) {
		if ( (*p) < 45 ) {
			if ( 33 <= (*p) && (*p) <= 43 )
				goto tr820;
		} else if ( (*p) > 47 ) {
			if ( (*p) > 57 ) {
				if ( 58 <= (*p) && (*p) <= 59 )
					goto tr820;
			} else if ( (*p) >= 48 )
				goto tr822;
		} else
			goto tr820;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr822;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr820;
			} else if ( (*p) >= 97 )
				goto tr822;
		} else
			goto tr820;
	} else
		goto tr820;
	goto tr757;
tr822:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st582;
st582:
	if ( ++p == pe )
		goto _test_eof582;
	/* fall through */
case 582:
#line 13461 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 62 )
		goto tr823;
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr822;
	} else if ( (*p) > 59 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr822;
	} else
		goto tr822;
	goto tr757;
tr821:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st583;
st583:
	if ( ++p == pe )
		goto _test_eof583;
	/* fall through */
case 583:
#line 13484 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 62 )
		goto tr823;
	if ( (*p) < 61 ) {
		if ( (*p) < 45 ) {
			if ( 33 <= (*p) && (*p) <= 43 )
				goto tr820;
		} else if ( (*p) > 47 ) {
			if ( (*p) > 57 ) {
				if ( 58 <= (*p) && (*p) <= 59 )
					goto tr820;
			} else if ( (*p) >= 48 )
				goto tr822;
		} else
			goto tr820;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr822;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr820;
			} else if ( (*p) >= 97 )
				goto tr822;
		} else
			goto tr820;
	} else
		goto tr820;
	goto tr757;
tr761:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st584;
tr824:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st584;
st584:
	if ( ++p == pe )
		goto _test_eof584;
	/* fall through */
case 584:
#line 13535 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 9: goto tr764;
		case 44: goto tr765;
		case 46: goto tr823;
		case 65: goto tr824;
		case 67: goto tr824;
		case 71: goto tr824;
		case 78: goto tr824;
		case 84: goto tr824;
		case 91: goto tr825;
		case 93: goto tr826;
		case 97: goto tr824;
		case 99: goto tr824;
		case 103: goto tr824;
		case 110: goto tr824;
		case 116: goto tr824;
	}
	goto tr757;
tr825:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st585;
st585:
	if ( ++p == pe )
		goto _test_eof585;
	/* fall through */
case 585:
#line 13565 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr827;
		case 60: goto tr828;
		case 92: goto tr827;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr827;
		} else if ( (*p) >= 33 )
			goto tr827;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr827;
		} else if ( (*p) >= 63 )
			goto tr827;
	} else
		goto tr827;
	goto tr757;
tr827:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st586;
st586:
	if ( ++p == pe )
		goto _test_eof586;
	/* fall through */
case 586:
#line 13597 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr827;
		case 58: goto tr829;
		case 92: goto tr827;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr827;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr827;
		} else if ( (*p) >= 63 )
			goto tr827;
	} else
		goto tr827;
	goto tr757;
tr829:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st587;
st587:
	if ( ++p == pe )
		goto _test_eof587;
	/* fall through */
case 587:
#line 13626 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr827;
		case 58: goto tr829;
		case 59: goto tr827;
		case 92: goto tr827;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 41 ) {
			if ( 45 <= (*p) && (*p) <= 47 )
				goto tr827;
		} else if ( (*p) >= 33 )
			goto tr827;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr827;
		} else if ( (*p) >= 63 )
			goto tr827;
	} else
		goto tr830;
	goto tr757;
tr830:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st588;
st588:
	if ( ++p == pe )
		goto _test_eof588;
	/* fall through */
case 588:
#line 13659 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr827;
		case 58: goto tr829;
		case 59: goto tr827;
		case 91: goto tr823;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 41 ) {
			if ( 45 <= (*p) && (*p) <= 47 )
				goto tr827;
		} else if ( (*p) >= 33 )
			goto tr827;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 92 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr827;
		} else if ( (*p) >= 63 )
			goto tr827;
	} else
		goto tr830;
	goto tr757;
tr828:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st589;
st589:
	if ( ++p == pe )
		goto _test_eof589;
	/* fall through */
case 589:
#line 13692 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr831;
		case 92: goto tr831;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr831;
		} else if ( (*p) >= 33 )
			goto tr831;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr831;
		} else if ( (*p) >= 63 )
			goto tr831;
	} else
		goto tr831;
	goto tr757;
tr831:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st590;
st590:
	if ( ++p == pe )
		goto _test_eof590;
	/* fall through */
case 590:
#line 13723 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr831;
		case 62: goto tr832;
		case 92: goto tr831;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr831;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr831;
		} else if ( (*p) >= 63 )
			goto tr831;
	} else
		goto tr831;
	goto tr757;
tr832:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st591;
st591:
	if ( ++p == pe )
		goto _test_eof591;
	/* fall through */
case 591:
#line 13752 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 58 )
		goto tr833;
	goto tr757;
tr833:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st592;
st592:
	if ( ++p == pe )
		goto _test_eof592;
	/* fall through */
case 592:
#line 13767 "inc/vcf/validator_detail_v45.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr834;
	goto tr757;
tr834:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st593;
st593:
	if ( ++p == pe )
		goto _test_eof593;
	/* fall through */
case 593:
#line 13782 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 91 )
		goto tr823;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr834;
	goto tr757;
tr826:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st594;
st594:
	if ( ++p == pe )
		goto _test_eof594;
	/* fall through */
case 594:
#line 13799 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr835;
		case 60: goto tr836;
		case 92: goto tr835;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr835;
		} else if ( (*p) >= 33 )
			goto tr835;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr835;
		} else if ( (*p) >= 63 )
			goto tr835;
	} else
		goto tr835;
	goto tr757;
tr835:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st595;
st595:
	if ( ++p == pe )
		goto _test_eof595;
	/* fall through */
case 595:
#line 13831 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr835;
		case 58: goto tr837;
		case 92: goto tr835;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr835;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr835;
		} else if ( (*p) >= 63 )
			goto tr835;
	} else
		goto tr835;
	goto tr757;
tr837:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st596;
st596:
	if ( ++p == pe )
		goto _test_eof596;
	/* fall through */
case 596:
#line 13860 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr835;
		case 58: goto tr837;
		case 59: goto tr835;
		case 92: goto tr835;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 41 ) {
			if ( 45 <= (*p) && (*p) <= 47 )
				goto tr835;
		} else if ( (*p) >= 33 )
			goto tr835;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr835;
		} else if ( (*p) >= 63 )
			goto tr835;
	} else
		goto tr838;
	goto tr757;
tr838:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st597;
st597:
	if ( ++p == pe )
		goto _test_eof597;
	/* fall through */
case 597:
#line 13893 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr835;
		case 58: goto tr837;
		case 59: goto tr835;
		case 93: goto tr823;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 41 ) {
			if ( 45 <= (*p) && (*p) <= 47 )
				goto tr835;
		} else if ( (*p) >= 33 )
			goto tr835;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 92 <= (*p) && (*p) <= 126 )
				goto tr835;
		} else if ( (*p) >= 63 )
			goto tr835;
	} else
		goto tr838;
	goto tr757;
tr836:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st598;
st598:
	if ( ++p == pe )
		goto _test_eof598;
	/* fall through */
case 598:
#line 13926 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr839;
		case 92: goto tr839;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr839;
		} else if ( (*p) >= 33 )
			goto tr839;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr839;
		} else if ( (*p) >= 63 )
			goto tr839;
	} else
		goto tr839;
	goto tr757;
tr839:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st599;
st599:
	if ( ++p == pe )
		goto _test_eof599;
	/* fall through */
case 599:
#line 13957 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr839;
		case 62: goto tr840;
		case 92: goto tr839;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr839;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr839;
		} else if ( (*p) >= 63 )
			goto tr839;
	} else
		goto tr839;
	goto tr757;
tr840:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st600;
st600:
	if ( ++p == pe )
		goto _test_eof600;
	/* fall through */
case 600:
#line 13986 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 58 )
		goto tr841;
	goto tr757;
tr841:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st601;
st601:
	if ( ++p == pe )
		goto _test_eof601;
	/* fall through */
case 601:
#line 14001 "inc/vcf/validator_detail_v45.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr842;
	goto tr757;
tr842:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st602;
st602:
	if ( ++p == pe )
		goto _test_eof602;
	/* fall through */
case 602:
#line 14016 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 93 )
		goto tr823;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr842;
	goto tr757;
tr762:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st603;
st603:
	if ( ++p == pe )
		goto _test_eof603;
	/* fall through */
case 603:
#line 14037 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr843;
		case 60: goto tr844;
		case 92: goto tr843;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr843;
		} else if ( (*p) >= 33 )
			goto tr843;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr843;
		} else if ( (*p) >= 63 )
			goto tr843;
	} else
		goto tr843;
	goto tr757;
tr843:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st604;
st604:
	if ( ++p == pe )
		goto _test_eof604;
	/* fall through */
case 604:
#line 14069 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr843;
		case 58: goto tr845;
		case 92: goto tr843;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr843;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr843;
		} else if ( (*p) >= 63 )
			goto tr843;
	} else
		goto tr843;
	goto tr757;
tr845:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st605;
st605:
	if ( ++p == pe )
		goto _test_eof605;
	/* fall through */
case 605:
#line 14098 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr843;
		case 58: goto tr845;
		case 59: goto tr843;
		case 92: goto tr843;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 41 ) {
			if ( 45 <= (*p) && (*p) <= 47 )
				goto tr843;
		} else if ( (*p) >= 33 )
			goto tr843;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr843;
		} else if ( (*p) >= 63 )
			goto tr843;
	} else
		goto tr846;
	goto tr757;
tr846:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st606;
st606:
	if ( ++p == pe )
		goto _test_eof606;
	/* fall through */
case 606:
#line 14131 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr843;
		case 58: goto tr845;
		case 59: goto tr843;
		case 91: goto tr847;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 41 ) {
			if ( 45 <= (*p) && (*p) <= 47 )
				goto tr843;
		} else if ( (*p) >= 33 )
			goto tr843;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 92 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr843;
		} else if ( (*p) >= 63 )
			goto tr843;
	} else
		goto tr846;
	goto tr757;
tr844:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st607;
st607:
	if ( ++p == pe )
		goto _test_eof607;
	/* fall through */
case 607:
#line 14164 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr848;
		case 92: goto tr848;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr848;
		} else if ( (*p) >= 33 )
			goto tr848;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr848;
		} else if ( (*p) >= 63 )
			goto tr848;
	} else
		goto tr848;
	goto tr757;
tr848:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st608;
st608:
	if ( ++p == pe )
		goto _test_eof608;
	/* fall through */
case 608:
#line 14195 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr848;
		case 62: goto tr849;
		case 92: goto tr848;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr848;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr848;
		} else if ( (*p) >= 63 )
			goto tr848;
	} else
		goto tr848;
	goto tr757;
tr849:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st609;
st609:
	if ( ++p == pe )
		goto _test_eof609;
	/* fall through */
case 609:
#line 14224 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 58 )
		goto tr850;
	goto tr757;
tr850:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st610;
st610:
	if ( ++p == pe )
		goto _test_eof610;
	/* fall through */
case 610:
#line 14239 "inc/vcf/validator_detail_v45.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr851;
	goto tr757;
tr851:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st611;
st611:
	if ( ++p == pe )
		goto _test_eof611;
	/* fall through */
case 611:
#line 14254 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 91 )
		goto tr847;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr851;
	goto tr757;
tr763:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st612;
st612:
	if ( ++p == pe )
		goto _test_eof612;
	/* fall through */
case 612:
#line 14275 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr852;
		case 60: goto tr853;
		case 92: goto tr852;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr852;
		} else if ( (*p) >= 33 )
			goto tr852;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr852;
		} else if ( (*p) >= 63 )
			goto tr852;
	} else
		goto tr852;
	goto tr757;
tr852:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st613;
st613:
	if ( ++p == pe )
		goto _test_eof613;
	/* fall through */
case 613:
#line 14307 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr852;
		case 58: goto tr854;
		case 92: goto tr852;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr852;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr852;
		} else if ( (*p) >= 63 )
			goto tr852;
	} else
		goto tr852;
	goto tr757;
tr854:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st614;
st614:
	if ( ++p == pe )
		goto _test_eof614;
	/* fall through */
case 614:
#line 14336 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr852;
		case 58: goto tr854;
		case 59: goto tr852;
		case 92: goto tr852;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 41 ) {
			if ( 45 <= (*p) && (*p) <= 47 )
				goto tr852;
		} else if ( (*p) >= 33 )
			goto tr852;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr852;
		} else if ( (*p) >= 63 )
			goto tr852;
	} else
		goto tr855;
	goto tr757;
tr855:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st615;
st615:
	if ( ++p == pe )
		goto _test_eof615;
	/* fall through */
case 615:
#line 14369 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr852;
		case 58: goto tr854;
		case 59: goto tr852;
		case 93: goto tr847;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 41 ) {
			if ( 45 <= (*p) && (*p) <= 47 )
				goto tr852;
		} else if ( (*p) >= 33 )
			goto tr852;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 92 <= (*p) && (*p) <= 126 )
				goto tr852;
		} else if ( (*p) >= 63 )
			goto tr852;
	} else
		goto tr855;
	goto tr757;
tr853:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st616;
st616:
	if ( ++p == pe )
		goto _test_eof616;
	/* fall through */
case 616:
#line 14402 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr856;
		case 92: goto tr856;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr856;
		} else if ( (*p) >= 33 )
			goto tr856;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr856;
		} else if ( (*p) >= 63 )
			goto tr856;
	} else
		goto tr856;
	goto tr757;
tr856:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st617;
st617:
	if ( ++p == pe )
		goto _test_eof617;
	/* fall through */
case 617:
#line 14433 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr856;
		case 62: goto tr857;
		case 92: goto tr856;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr856;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr856;
		} else if ( (*p) >= 63 )
			goto tr856;
	} else
		goto tr856;
	goto tr757;
tr857:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st618;
st618:
	if ( ++p == pe )
		goto _test_eof618;
	/* fall through */
case 618:
#line 14462 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 58 )
		goto tr858;
	goto tr757;
tr858:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st619;
st619:
	if ( ++p == pe )
		goto _test_eof619;
	/* fall through */
case 619:
#line 14477 "inc/vcf/validator_detail_v45.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr859;
	goto tr757;
tr859:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st620;
st620:
	if ( ++p == pe )
		goto _test_eof620;
	/* fall through */
case 620:
#line 14492 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 93 )
		goto tr847;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr859;
	goto tr757;
tr759:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st621;
st621:
	if ( ++p == pe )
		goto _test_eof621;
	/* fall through */
case 621:
#line 14513 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 9: goto tr764;
		case 65: goto tr819;
		case 67: goto tr819;
		case 71: goto tr819;
		case 78: goto tr819;
		case 84: goto tr819;
		case 97: goto tr819;
		case 99: goto tr819;
		case 103: goto tr819;
		case 110: goto tr819;
		case 116: goto tr819;
	}
	goto tr757;
tr725:
#line 208 "src/vcf/vcf.ragel"
	{
        try {
            ParsePolicy::handle_header_line(*this);
        } catch (Error *error) {
            ErrorPolicy::handle_error(*this, error);
        }
    }
#line 43 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st622;
tr737:
#line 204 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_sample_name(*this);
    }
#line 208 "src/vcf/vcf.ragel"
	{
        try {
            ParsePolicy::handle_header_line(*this);
        } catch (Error *error) {
            ErrorPolicy::handle_error(*this, error);
        }
    }
#line 43 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st622;
st622:
	if ( ++p == pe )
		goto _test_eof622;
	/* fall through */
case 622:
#line 14577 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 10 )
		goto st626;
	goto tr726;
tr23:
#line 99 "src/vcf/vcf.ragel"
	{
        try {
          ParsePolicy::handle_fileformat(*this);
        } catch (Error *error) {
          ErrorPolicy::handle_error(*this, error);
          p--; {goto st624;}
        }
    }
#line 43 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st623;
st623:
	if ( ++p == pe )
		goto _test_eof623;
	/* fall through */
case 623:
#line 14607 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 10 )
		goto st22;
	goto tr0;
tr864:
#line 43 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st624;
st624:
	if ( ++p == pe )
		goto _test_eof624;
	/* fall through */
case 624:
#line 14628 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 10: goto tr863;
		case 13: goto tr864;
	}
	goto st624;
tr863:
#line 43 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
#line 265 "src/vcf/vcf_v45.ragel"
	{ {goto st28;} }
	goto st637;
st637:
	if ( ++p == pe )
		goto _test_eof637;
	/* fall through */
case 637:
#line 14653 "inc/vcf/validator_detail_v45.hpp"
	goto st0;
tr867:
#line 43 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st625;
st625:
	if ( ++p == pe )
		goto _test_eof625;
	/* fall through */
case 625:
#line 14672 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 10: goto tr866;
		case 13: goto tr867;
	}
	goto st625;
tr866:
#line 43 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
#line 266 "src/vcf/vcf_v45.ragel"
	{ {goto st630;} }
	goto st638;
st638:
	if ( ++p == pe )
		goto _test_eof638;
	/* fall through */
case 638:
#line 14697 "inc/vcf/validator_detail_v45.hpp"
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
	_test_eof626: cs = 626; goto _test_eof; 
	_test_eof627: cs = 627; goto _test_eof; 
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
	_test_eof628: cs = 628; goto _test_eof; 
	_test_eof551: cs = 551; goto _test_eof; 
	_test_eof552: cs = 552; goto _test_eof; 
	_test_eof553: cs = 553; goto _test_eof; 
	_test_eof629: cs = 629; goto _test_eof; 
	_test_eof630: cs = 630; goto _test_eof; 
	_test_eof554: cs = 554; goto _test_eof; 
	_test_eof555: cs = 555; goto _test_eof; 
	_test_eof556: cs = 556; goto _test_eof; 
	_test_eof557: cs = 557; goto _test_eof; 
	_test_eof558: cs = 558; goto _test_eof; 
	_test_eof631: cs = 631; goto _test_eof; 
	_test_eof632: cs = 632; goto _test_eof; 
	_test_eof633: cs = 633; goto _test_eof; 
	_test_eof559: cs = 559; goto _test_eof; 
	_test_eof560: cs = 560; goto _test_eof; 
	_test_eof561: cs = 561; goto _test_eof; 
	_test_eof562: cs = 562; goto _test_eof; 
	_test_eof634: cs = 634; goto _test_eof; 
	_test_eof563: cs = 563; goto _test_eof; 
	_test_eof635: cs = 635; goto _test_eof; 
	_test_eof564: cs = 564; goto _test_eof; 
	_test_eof636: cs = 636; goto _test_eof; 
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
	_test_eof637: cs = 637; goto _test_eof; 
	_test_eof625: cs = 625; goto _test_eof; 
	_test_eof638: cs = 638; goto _test_eof; 

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
	case 623: 
#line 60 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new FileformatError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
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
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
	break;
	case 626: 
#line 70 "src/vcf/vcf.ragel"
	{
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (Error *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
    }
	break;
	case 622: 
#line 78 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new HeaderSectionError{n_lines});
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (Error *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
        
        p--; {       if ( p == pe )
               goto _test_eof625;
goto st625;}
    }
	break;
	case 557: 
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof625;
goto st625;}
    }
	break;
	case 74: 
	case 75: 
	case 76: 
	case 77: 
	case 78: 
	case 79: 
	case 80: 
	case 87: 
	case 91: 
#line 259 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
	break;
	case 398: 
	case 399: 
	case 400: 
	case 401: 
	case 402: 
	case 403: 
	case 404: 
	case 405: 
#line 271 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in assembly metadata"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
	break;
	case 425: 
	case 426: 
	case 427: 
	case 428: 
	case 429: 
	case 430: 
	case 431: 
	case 432: 
	case 433: 
	case 434: 
	case 437: 
	case 438: 
	case 439: 
	case 440: 
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
#line 277 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in contig metadata"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
	break;
	case 101: 
	case 102: 
	case 103: 
	case 104: 
	case 105: 
	case 106: 
	case 107: 
	case 108: 
	case 109: 
	case 116: 
	case 120: 
#line 283 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
	break;
	case 129: 
	case 130: 
	case 131: 
	case 132: 
	case 133: 
	case 134: 
	case 135: 
	case 136: 
	case 137: 
	case 141: 
	case 142: 
	case 143: 
	case 144: 
	case 145: 
	case 146: 
	case 147: 
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
	case 162: 
	case 163: 
	case 164: 
	case 165: 
	case 166: 
	case 167: 
	case 168: 
	case 169: 
	case 176: 
	case 187: 
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
	break;
	case 197: 
	case 198: 
	case 199: 
	case 200: 
	case 201: 
	case 202: 
	case 203: 
	case 204: 
	case 208: 
	case 209: 
	case 210: 
	case 211: 
	case 212: 
	case 213: 
	case 214: 
	case 217: 
	case 218: 
	case 219: 
	case 220: 
	case 221: 
	case 224: 
	case 225: 
	case 226: 
	case 227: 
	case 228: 
	case 229: 
	case 230: 
	case 231: 
	case 232: 
	case 233: 
	case 234: 
	case 235: 
	case 236: 
	case 243: 
	case 254: 
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
	break;
	case 309: 
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
	case 325: 
	case 326: 
	case 327: 
	case 328: 
	case 329: 
	case 330: 
	case 334: 
	case 335: 
	case 336: 
	case 337: 
	case 338: 
	case 339: 
	case 340: 
	case 344: 
	case 355: 
	case 356: 
	case 357: 
	case 358: 
	case 359: 
	case 360: 
	case 361: 
	case 362: 
#line 311 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
	break;
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
#line 332 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in pedigreeDB metadata"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
	break;
	case 263: 
	case 264: 
	case 265: 
	case 266: 
	case 267: 
	case 268: 
	case 269: 
	case 270: 
	case 274: 
	case 275: 
	case 276: 
	case 277: 
	case 278: 
	case 279: 
	case 280: 
	case 283: 
	case 284: 
	case 285: 
	case 286: 
	case 287: 
	case 295: 
	case 296: 
	case 297: 
	case 298: 
	case 299: 
	case 300: 
	case 301: 
	case 302: 
	case 303: 
	case 305: 
	case 306: 
	case 308: 
#line 338 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
	break;
	case 366: 
	case 367: 
	case 368: 
	case 369: 
	case 370: 
	case 371: 
	case 372: 
	case 373: 
	case 374: 
	case 375: 
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
#line 359 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
	break;
	case 535: 
	case 554: 
	case 555: 
	case 556: 
#line 408 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new ChromosomeBodyError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof625;
goto st625;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof625;
goto st625;}
    }
	break;
	case 536: 
	case 537: 
#line 414 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new PositionBodyError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof625;
goto st625;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof625;
goto st625;}
    }
	break;
	case 538: 
	case 539: 
#line 420 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new IdBodyError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof625;
goto st625;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof625;
goto st625;}
    }
	break;
	case 540: 
	case 541: 
#line 426 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new ReferenceAlleleBodyError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof625;
goto st625;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof625;
goto st625;}
    }
	break;
	case 542: 
	case 543: 
	case 577: 
	case 578: 
	case 579: 
	case 580: 
	case 581: 
	case 582: 
	case 583: 
	case 584: 
	case 585: 
	case 586: 
	case 587: 
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
#line 432 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new AlternateAllelesBodyError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof625;
goto st625;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof625;
goto st625;}
    }
	break;
	case 544: 
	case 545: 
	case 546: 
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
#line 438 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new QualityBodyError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof625;
goto st625;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof625;
goto st625;}
    }
	break;
	case 547: 
	case 548: 
	case 549: 
	case 565: 
	case 566: 
#line 444 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new FilterBodyError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof625;
goto st625;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof625;
goto st625;}
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
#line 29 "src/vcf/vcf_v45.ragel"
	{
        ErrorPolicy::handle_error(*this,
                new FileformatError{n_lines, "The fileformat declaration is not 'fileformat=VCFv4.5'"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 60 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new FileformatError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
	break;
	case 551: 
	case 552: 
#line 50 "src/vcf/vcf_v45.ragel"
	{
        ErrorPolicy::handle_error(*this, new FormatBodyError{n_lines, "Format does not start with a letter/underscore followed by alphanumeric/underscore/dot characters"});
        p--; {       if ( p == pe )
               goto _test_eof625;
goto st625;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof625;
goto st625;}
    }
	break;
	case 525: 
	case 526: 
	case 527: 
	case 528: 
	case 529: 
	case 530: 
	case 531: 
	case 532: 
	case 533: 
#line 55 "src/vcf/vcf_v45.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {       if ( p == pe )
               goto _test_eof625;
goto st625;}
    }
#line 78 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new HeaderSectionError{n_lines});
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (Error *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
        
        p--; {       if ( p == pe )
               goto _test_eof625;
goto st625;}
    }
	break;
	case 81: 
	case 82: 
	case 83: 
#line 264 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines,
               "ALT metadata ID is not prefixed by DEL/INS/DUP/INV/CNV" + (source->version < Version::v44 ? std::string("/BND") : std::string("")) + " and suffixed by ':' and a text sequence"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 259 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
	break;
	case 100: 
#line 283 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
	break;
	case 155: 
	case 156: 
#line 305 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "INFO metadata Type is not Integer, Float, Flag, Character or String"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
	break;
	case 222: 
	case 223: 
#line 305 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "INFO metadata Type is not Integer, Float, Flag, Character or String"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
	break;
	case 363: 
	case 364: 
	case 365: 
#line 316 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "PEDIGREE metadata Original is not valid"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 311 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
	break;
	case 331: 
	case 332: 
	case 333: 
	case 341: 
	case 342: 
	case 343: 
#line 321 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "PEDIGREE metadata Father or Mother is not valid"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 311 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
	break;
	case 324: 
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
#line 326 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "PEDIGREE metadata sequence of Name_N is not valid"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 311 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
	break;
	case 281: 
	case 282: 
#line 343 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "META metadata Number is not a dot"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 338 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
	break;
	case 288: 
	case 289: 
	case 290: 
	case 291: 
	case 292: 
	case 293: 
	case 294: 
#line 348 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "META metadata Type is not String"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 338 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
	break;
	case 304: 
	case 307: 
#line 353 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "META metadata Values is not a square-bracket delimited list of values"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 338 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
	break;
	case 84: 
	case 85: 
	case 86: 
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 259 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
	break;
	case 435: 
	case 436: 
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 277 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in contig metadata"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
	break;
	case 110: 
	case 111: 
	case 112: 
	case 113: 
	case 114: 
	case 115: 
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 283 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
	break;
	case 138: 
	case 139: 
	case 140: 
	case 173: 
	case 174: 
	case 175: 
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
	break;
	case 205: 
	case 206: 
	case 207: 
	case 240: 
	case 241: 
	case 242: 
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
	break;
	case 321: 
	case 322: 
	case 323: 
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 311 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
	break;
	case 271: 
	case 272: 
	case 273: 
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 338 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
	break;
	case 376: 
	case 377: 
	case 378: 
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 359 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
	break;
	case 88: 
	case 89: 
	case 90: 
	case 92: 
	case 93: 
	case 97: 
	case 98: 
	case 99: 
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 259 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
	break;
	case 117: 
	case 118: 
	case 119: 
	case 121: 
	case 122: 
	case 126: 
	case 127: 
	case 128: 
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 283 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
	break;
	case 170: 
	case 171: 
	case 172: 
	case 177: 
	case 178: 
	case 179: 
	case 180: 
	case 184: 
	case 185: 
	case 186: 
	case 188: 
	case 189: 
	case 193: 
	case 194: 
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
	break;
	case 237: 
	case 238: 
	case 239: 
	case 244: 
	case 245: 
	case 246: 
	case 247: 
	case 251: 
	case 252: 
	case 253: 
	case 255: 
	case 256: 
	case 260: 
	case 261: 
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
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
#line 385 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata URL is not valid"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 271 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in assembly metadata"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
	break;
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
#line 385 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata URL is not valid"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 332 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in pedigreeDB metadata"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
	break;
	case 148: 
	case 149: 
	case 195: 
	case 196: 
#line 36 "src/vcf/vcf_v45.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "FORMAT metadata Number is not a number, A, R, G, P, LA, LR, LG, M or dot"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
	break;
	case 215: 
	case 216: 
	case 262: 
#line 42 "src/vcf/vcf_v45.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "INFO metadata Number is not a number, A, R, G or dot"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
	break;
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
	case 515: 
	case 516: 
	case 517: 
	case 518: 
	case 519: 
	case 520: 
	case 521: 
	case 522: 
	case 523: 
	case 524: 
#line 55 "src/vcf/vcf_v45.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {       if ( p == pe )
               goto _test_eof625;
goto st625;}
    }
#line 391 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new HeaderSectionError{n_lines,
            "The header line does not start with the mandatory columns: CHROM, POS, ID, REF, ALT, QUAL, FILTER and INFO"});
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (Error *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
        
        p--; {       if ( p == pe )
               goto _test_eof625;
goto st625;}
    }
#line 78 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new HeaderSectionError{n_lines});
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (Error *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
        
        p--; {       if ( p == pe )
               goto _test_eof625;
goto st625;}
    }
	break;
	case 558: 
#line 55 "src/vcf/vcf_v45.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {       if ( p == pe )
               goto _test_eof625;
goto st625;}
    }
#line 466 "src/vcf/vcf.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " is not a valid string";
        ErrorPolicy::handle_error(*this, new SamplesBodyError{n_lines, message_stream.str()});
        p--; {       if ( p == pe )
               goto _test_eof625;
goto st625;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof625;
goto st625;}
    }
	break;
	case 628: 
	case 629: 
	case 634: 
	case 635: 
	case 636: 
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 218 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 55 "src/vcf/vcf_v45.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {       if ( p == pe )
               goto _test_eof625;
goto st625;}
    }
#line 222 "src/vcf/vcf.ragel"
	{
        try {
            // Handle all columns and build record
            ParsePolicy::handle_body_line(*this);

            if (record != nullptr) {
                previous_records.check_duplicates(*record);
                
                auto duplicates = previous_records.get_duplicates();
                for(auto &error_ptr : duplicates) {
                    ErrorPolicy::handle_error(*this, error_ptr.release());
                }
                
                auto symbolic_duplicates = previous_records.get_symbolic_duplicates();
                for(auto &error_ptr : symbolic_duplicates) {
                    ErrorPolicy::handle_warning(*this, error_ptr.release());
                }
                validate_additional_checks();
            }

            try {
                // Check warnings (non-blocking errors but potential mistakes anyway, only makes sense if the last record parsed was correct)
                if (record != nullptr) {
                    OptionalPolicy::optional_check_body_entry(*this, *record);
                }
            } catch (Error *warn) {
                ErrorPolicy::handle_warning(*this, warn);
            }
        } catch (Error *error) {
            ErrorPolicy::handle_error(*this, error);
        }
    }
	break;
	case 23: 
	case 28: 
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 55 "src/vcf/vcf_v45.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {       if ( p == pe )
               goto _test_eof625;
goto st625;}
    }
#line 391 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new HeaderSectionError{n_lines,
            "The header line does not start with the mandatory columns: CHROM, POS, ID, REF, ALT, QUAL, FILTER and INFO"});
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (Error *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
        
        p--; {       if ( p == pe )
               goto _test_eof625;
goto st625;}
    }
#line 78 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new HeaderSectionError{n_lines});
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (Error *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
        
        p--; {       if ( p == pe )
               goto _test_eof625;
goto st625;}
    }
	break;
	case 94: 
	case 95: 
	case 96: 
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 259 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
	break;
	case 123: 
	case 124: 
	case 125: 
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 283 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
	break;
	case 181: 
	case 182: 
	case 183: 
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
	break;
	case 248: 
	case 249: 
	case 250: 
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
	break;
	case 190: 
	case 191: 
	case 192: 
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
	break;
	case 257: 
	case 258: 
	case 259: 
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
	break;
	case 550: 
	case 559: 
	case 560: 
	case 561: 
	case 562: 
	case 563: 
#line 455 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info key is not a sequence of alphanumeric and/or punctuation characters"});
        p--; {       if ( p == pe )
               goto _test_eof625;
goto st625;}
    }
#line 55 "src/vcf/vcf_v45.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {       if ( p == pe )
               goto _test_eof625;
goto st625;}
    }
#line 450 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {       if ( p == pe )
               goto _test_eof625;
goto st625;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof625;
goto st625;}
    }
	break;
	case 564: 
#line 460 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info field value is not a comma-separated list of valid strings (maybe it contains whitespaces?)"});
        p--; {       if ( p == pe )
               goto _test_eof625;
goto st625;}
    }
#line 55 "src/vcf/vcf_v45.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {       if ( p == pe )
               goto _test_eof625;
goto st625;}
    }
#line 450 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {       if ( p == pe )
               goto _test_eof625;
goto st625;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof625;
goto st625;}
    }
	break;
	case 631: 
	case 632: 
	case 633: 
#line 55 "src/vcf/vcf_v45.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {       if ( p == pe )
               goto _test_eof625;
goto st625;}
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 218 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 222 "src/vcf/vcf.ragel"
	{
        try {
            // Handle all columns and build record
            ParsePolicy::handle_body_line(*this);

            if (record != nullptr) {
                previous_records.check_duplicates(*record);
                
                auto duplicates = previous_records.get_duplicates();
                for(auto &error_ptr : duplicates) {
                    ErrorPolicy::handle_error(*this, error_ptr.release());
                }
                
                auto symbolic_duplicates = previous_records.get_symbolic_duplicates();
                for(auto &error_ptr : symbolic_duplicates) {
                    ErrorPolicy::handle_warning(*this, error_ptr.release());
                }
                validate_additional_checks();
            }

            try {
                // Check warnings (non-blocking errors but potential mistakes anyway, only makes sense if the last record parsed was correct)
                if (record != nullptr) {
                    OptionalPolicy::optional_check_body_entry(*this, *record);
                }
            } catch (Error *warn) {
                ErrorPolicy::handle_warning(*this, warn);
            }
        } catch (Error *error) {
            ErrorPolicy::handle_error(*this, error);
        }
    }
	break;
	case 553: 
#line 55 "src/vcf/vcf_v45.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {       if ( p == pe )
               goto _test_eof625;
goto st625;}
    }
#line 473 "src/vcf/vcf.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " does not start with a valid genotype";
        ErrorPolicy::handle_error(*this, new SamplesFieldBodyError{n_lines, message_stream.str(), "", "GT"});
        p--; {       if ( p == pe )
               goto _test_eof625;
goto st625;}
    }
#line 466 "src/vcf/vcf.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " is not a valid string";
        ErrorPolicy::handle_error(*this, new SamplesBodyError{n_lines, message_stream.str()});
        p--; {       if ( p == pe )
               goto _test_eof625;
goto st625;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof625;
goto st625;}
    }
	break;
	case 22: 
#line 60 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new FileformatError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 55 "src/vcf/vcf_v45.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {       if ( p == pe )
               goto _test_eof625;
goto st625;}
    }
#line 391 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new HeaderSectionError{n_lines,
            "The header line does not start with the mandatory columns: CHROM, POS, ID, REF, ALT, QUAL, FILTER and INFO"});
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (Error *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
        
        p--; {       if ( p == pe )
               goto _test_eof625;
goto st625;}
    }
#line 78 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new HeaderSectionError{n_lines});
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (Error *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
        
        p--; {       if ( p == pe )
               goto _test_eof625;
goto st625;}
    }
	break;
	case 24: 
#line 259 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 283 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 271 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in assembly metadata"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 277 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in contig metadata"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 338 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 359 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 311 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 332 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in pedigreeDB metadata"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
	break;
#line 17507 "inc/vcf/validator_detail_v45.hpp"
	}
	}

	_out: {}
	}

#line 295 "src/vcf/vcf_v45.ragel"

    }
    
  }
}
