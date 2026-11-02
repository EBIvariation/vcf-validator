
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
static const int vcf_v45_first_final = 536;
static const int vcf_v45_error = 0;

static const int vcf_v45_en_main = 1;
static const int vcf_v45_en_main_meta_section = 28;
static const int vcf_v45_en_main_body_section = 540;
static const int vcf_v45_en_meta_section_skip = 534;
static const int vcf_v45_en_body_section_skip = 535;


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
        p--; {goto st534;}
    }
	goto st0;
tr14:
#line 29 "src/vcf/vcf_v45.ragel"
	{
        ErrorPolicy::handle_error(*this,
                new FileformatError{n_lines, "The fileformat declaration is not 'fileformat=VCFv4.5'"});
        p--; {goto st534;}
    }
#line 60 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new FileformatError{n_lines});
        p--; {goto st534;}
    }
	goto st0;
tr24:
#line 60 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new FileformatError{n_lines});
        p--; {goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st534;}
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
        
        p--; {goto st535;}
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
        
        p--; {goto st535;}
    }
	goto st0;
tr26:
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st534;}
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
        
        p--; {goto st535;}
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
        
        p--; {goto st535;}
    }
	goto st0;
tr29:
#line 259 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {goto st534;}
    }
#line 283 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {goto st534;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st534;}
    }
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st534;}
    }
#line 271 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in assembly metadata"});
        p--; {goto st534;}
    }
#line 277 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in contig metadata"});
        p--; {goto st534;}
    }
#line 338 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
        p--; {goto st534;}
    }
#line 359 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st534;}
    }
#line 311 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {goto st534;}
    }
#line 332 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in pedigreeDB metadata"});
        p--; {goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st534;}
    }
	goto st0;
tr40:
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st534;}
    }
	goto st0;
tr82:
#line 259 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st534;}
    }
	goto st0;
tr90:
#line 264 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines,
               "ALT metadata ID is not prefixed by DEL/INS/DUP/INV/CNV" + (source->version < Version::v44 ? std::string("/BND") : std::string("")) + " and suffixed by ':' and a text sequence"});
        p--; {goto st534;}
    }
#line 259 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st534;}
    }
	goto st0;
tr97:
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {goto st534;}
    }
#line 259 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st534;}
    }
	goto st0;
tr104:
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st534;}
    }
#line 259 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st534;}
    }
	goto st0;
tr113:
#line 283 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {goto st534;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st534;}
    }
	goto st0;
tr116:
#line 283 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st534;}
    }
	goto st0;
tr126:
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {goto st534;}
    }
#line 283 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st534;}
    }
	goto st0;
tr139:
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st534;}
    }
#line 283 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st534;}
    }
	goto st0;
tr148:
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st534;}
    }
	goto st0;
tr158:
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {goto st534;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st534;}
    }
	goto st0;
tr171:
#line 36 "src/vcf/vcf_v45.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "FORMAT metadata Number is not a number, A, R, G, P, LA, LR, LG, M or dot"});
        p--; {goto st534;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st534;}
    }
	goto st0;
tr181:
#line 305 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "INFO metadata Type is not Integer, Float, Flag, Character or String"});
        p--; {goto st534;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st534;}
    }
	goto st0;
tr198:
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st534;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st534;}
    }
	goto st0;
tr215:
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st534;}
    }
	goto st0;
tr224:
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {goto st534;}
    }
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st534;}
    }
	goto st0;
tr237:
#line 42 "src/vcf/vcf_v45.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "INFO metadata Number is not a number, A, R, G or dot"});
        p--; {goto st534;}
    }
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st534;}
    }
	goto st0;
tr246:
#line 305 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "INFO metadata Type is not Integer, Float, Flag, Character or String"});
        p--; {goto st534;}
    }
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st534;}
    }
	goto st0;
tr263:
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st534;}
    }
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st534;}
    }
	goto st0;
tr279:
#line 338 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
        p--; {goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st534;}
    }
	goto st0;
tr288:
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {goto st534;}
    }
#line 338 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
        p--; {goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st534;}
    }
	goto st0;
tr301:
#line 343 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "META metadata Number is not a dot"});
        p--; {goto st534;}
    }
#line 338 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
        p--; {goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st534;}
    }
	goto st0;
tr309:
#line 348 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "META metadata Type is not String"});
        p--; {goto st534;}
    }
#line 338 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
        p--; {goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st534;}
    }
	goto st0;
tr326:
#line 353 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "META metadata Values is not a square-bracket delimited list of values"});
        p--; {goto st534;}
    }
#line 338 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
        p--; {goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st534;}
    }
	goto st0;
tr332:
#line 311 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st534;}
    }
	goto st0;
tr345:
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {goto st534;}
    }
#line 311 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st534;}
    }
	goto st0;
tr351:
#line 326 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "PEDIGREE metadata sequence of Name_N is not valid"});
        p--; {goto st534;}
    }
#line 311 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st534;}
    }
	goto st0;
tr361:
#line 321 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "PEDIGREE metadata Father or Mother is not valid"});
        p--; {goto st534;}
    }
#line 311 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st534;}
    }
	goto st0;
tr398:
#line 316 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "PEDIGREE metadata Original is not valid"});
        p--; {goto st534;}
    }
#line 311 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st534;}
    }
	goto st0;
tr403:
#line 359 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st534;}
    }
	goto st0;
tr414:
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {goto st534;}
    }
#line 359 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st534;}
    }
	goto st0;
tr437:
#line 271 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in assembly metadata"});
        p--; {goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st534;}
    }
	goto st0;
tr446:
#line 385 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata URL is not valid"});
        p--; {goto st534;}
    }
#line 271 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in assembly metadata"});
        p--; {goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st534;}
    }
	goto st0;
tr467:
#line 277 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in contig metadata"});
        p--; {goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st534;}
    }
	goto st0;
tr478:
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {goto st534;}
    }
#line 277 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in contig metadata"});
        p--; {goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st534;}
    }
	goto st0;
tr499:
#line 332 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in pedigreeDB metadata"});
        p--; {goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st534;}
    }
	goto st0;
tr511:
#line 385 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata URL is not valid"});
        p--; {goto st534;}
    }
#line 332 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in pedigreeDB metadata"});
        p--; {goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st534;}
    }
	goto st0;
tr534:
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
        
        p--; {goto st535;}
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
        
        p--; {goto st535;}
    }
	goto st0;
tr574:
#line 78 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new HeaderSectionError{n_lines});
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (Error *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
        
        p--; {goto st535;}
    }
	goto st0;
tr589:
#line 408 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new ChromosomeBodyError{n_lines});
        p--; {goto st535;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st535;}
    }
	goto st0;
tr592:
#line 414 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new PositionBodyError{n_lines});
        p--; {goto st535;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st535;}
    }
	goto st0;
tr596:
#line 420 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new IdBodyError{n_lines});
        p--; {goto st535;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st535;}
    }
	goto st0;
tr601:
#line 426 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new ReferenceAlleleBodyError{n_lines});
        p--; {goto st535;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st535;}
    }
	goto st0;
tr605:
#line 432 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new AlternateAllelesBodyError{n_lines});
        p--; {goto st535;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st535;}
    }
	goto st0;
tr614:
#line 438 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new QualityBodyError{n_lines});
        p--; {goto st535;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st535;}
    }
	goto st0;
tr625:
#line 444 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new FilterBodyError{n_lines});
        p--; {goto st535;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st535;}
    }
	goto st0;
tr633:
#line 455 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info key is not a sequence of alphanumeric and/or punctuation characters"});
        p--; {goto st535;}
    }
#line 450 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st535;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st535;}
    }
	goto st0;
tr637:
#line 50 "src/vcf/vcf_v45.ragel"
	{
        ErrorPolicy::handle_error(*this, new FormatBodyError{n_lines, "Format does not start with a letter/underscore followed by alphanumeric/underscore/dot characters"});
        p--; {goto st535;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st535;}
    }
	goto st0;
tr642:
#line 473 "src/vcf/vcf.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " does not start with a valid genotype";
        ErrorPolicy::handle_error(*this, new SamplesFieldBodyError{n_lines, message_stream.str(), "", "GT"});
        p--; {goto st535;}
    }
#line 466 "src/vcf/vcf.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " is not a valid string";
        ErrorPolicy::handle_error(*this, new SamplesBodyError{n_lines, message_stream.str()});
        p--; {goto st535;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st535;}
    }
	goto st0;
tr650:
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st535;}
    }
	goto st0;
tr652:
#line 466 "src/vcf/vcf.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " is not a valid string";
        ErrorPolicy::handle_error(*this, new SamplesBodyError{n_lines, message_stream.str()});
        p--; {goto st535;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st535;}
    }
	goto st0;
tr658:
#line 460 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info field value is not a comma-separated list of valid strings (maybe it contains whitespaces?)"});
        p--; {goto st535;}
    }
#line 450 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st535;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st535;}
    }
	goto st0;
tr716:
#line 78 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new HeaderSectionError{n_lines});
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (Error *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
        
        p--; {goto st535;}
    }
#line 408 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new ChromosomeBodyError{n_lines});
        p--; {goto st535;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st535;}
    }
	goto st0;
tr723:
#line 450 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st535;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st535;}
    }
	goto st0;
#line 1050 "inc/vcf/validator_detail_v45.hpp"
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
#line 1173 "inc/vcf/validator_detail_v45.hpp"
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
#line 1188 "inc/vcf/validator_detail_v45.hpp"
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
#line 1203 "inc/vcf/validator_detail_v45.hpp"
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
#line 1218 "inc/vcf/validator_detail_v45.hpp"
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
#line 1233 "inc/vcf/validator_detail_v45.hpp"
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
#line 1248 "inc/vcf/validator_detail_v45.hpp"
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
#line 1263 "inc/vcf/validator_detail_v45.hpp"
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
          p--; {goto st534;}
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
#line 1295 "inc/vcf/validator_detail_v45.hpp"
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
		case 67: goto st398;
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
#line 1352 "inc/vcf/validator_detail_v45.hpp"
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
#line 1369 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto st30;
		case 60: goto st34;
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
#line 1398 "inc/vcf/validator_detail_v45.hpp"
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
#line 1455 "inc/vcf/validator_detail_v45.hpp"
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
#line 1508 "inc/vcf/validator_detail_v45.hpp"
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
#line 1545 "inc/vcf/validator_detail_v45.hpp"
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
#line 1574 "inc/vcf/validator_detail_v45.hpp"
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
#line 1601 "inc/vcf/validator_detail_v45.hpp"
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr53;
	goto tr40;
st34:
	if ( ++p == pe )
		goto _test_eof34;
	/* fall through */
case 34:
	switch( (*p) ) {
		case 34: goto st35;
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
	goto tr40;
st35:
	if ( ++p == pe )
		goto _test_eof35;
	/* fall through */
case 35:
	switch( (*p) ) {
		case 34: goto tr62;
		case 92: goto tr63;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr61;
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
	goto st36;
tr64:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st36;
st36:
	if ( ++p == pe )
		goto _test_eof36;
	/* fall through */
case 36:
#line 1659 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr65;
		case 92: goto tr66;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr64;
	goto tr40;
tr62:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st37;
tr65:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st37;
st37:
	if ( ++p == pe )
		goto _test_eof37;
	/* fall through */
case 37:
#line 1688 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 62 )
		goto st32;
	goto tr40;
tr63:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st38;
tr66:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st38;
st38:
	if ( ++p == pe )
		goto _test_eof38;
	/* fall through */
case 38:
#line 1713 "inc/vcf/validator_detail_v45.hpp"
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr64;
	goto tr40;
tr59:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st39;
st39:
	if ( ++p == pe )
		goto _test_eof39;
	/* fall through */
case 39:
#line 1728 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 95 )
		goto st39;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st39;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr69;
		} else if ( (*p) >= 65 )
			goto tr69;
	} else
		goto tr69;
	goto tr40;
tr60:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st40;
tr69:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st40;
st40:
	if ( ++p == pe )
		goto _test_eof40;
	/* fall through */
case 40:
#line 1764 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr70;
		case 95: goto tr69;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr69;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr69;
		} else if ( (*p) >= 65 )
			goto tr69;
	} else
		goto tr69;
	goto tr40;
tr70:
#line 192 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st41;
st41:
	if ( ++p == pe )
		goto _test_eof41;
	/* fall through */
case 41:
#line 1792 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 34 )
		goto st44;
	if ( (*p) < 45 ) {
		if ( 32 <= (*p) && (*p) <= 43 )
			goto tr71;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr71;
	} else
		goto tr71;
	goto tr40;
tr71:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st42;
tr73:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st42;
st42:
	if ( ++p == pe )
		goto _test_eof42;
	/* fall through */
case 42:
#line 1825 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 44: goto tr74;
		case 62: goto tr54;
	}
	if ( (*p) > 33 ) {
		if ( 35 <= (*p) && (*p) <= 126 )
			goto tr73;
	} else if ( (*p) >= 32 )
		goto tr73;
	goto tr40;
tr74:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st43;
st43:
	if ( ++p == pe )
		goto _test_eof43;
	/* fall through */
case 43:
#line 1847 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 95 )
		goto tr59;
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
	goto tr40;
st44:
	if ( ++p == pe )
		goto _test_eof44;
	/* fall through */
case 44:
	switch( (*p) ) {
		case 34: goto tr76;
		case 92: goto tr77;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr75;
	goto tr40;
tr75:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st45;
tr78:
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
#line 1895 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr79;
		case 92: goto tr80;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr78;
	goto tr40;
tr76:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st46;
tr79:
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
#line 1924 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 44: goto st43;
		case 62: goto st32;
	}
	goto tr40;
tr77:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st47;
tr80:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st47;
st47:
	if ( ++p == pe )
		goto _test_eof47;
	/* fall through */
case 47:
#line 1951 "inc/vcf/validator_detail_v45.hpp"
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr78;
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
	goto st48;
st48:
	if ( ++p == pe )
		goto _test_eof48;
	/* fall through */
case 48:
#line 1970 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 76: goto tr83;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr82;
tr83:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st49;
st49:
	if ( ++p == pe )
		goto _test_eof49;
	/* fall through */
case 49:
#line 1989 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 84: goto st50;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr82;
st50:
	if ( ++p == pe )
		goto _test_eof50;
	/* fall through */
case 50:
	if ( (*p) == 61 )
		goto tr85;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr82;
tr85:
#line 108 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "ALT");
    }
	goto st51;
st51:
	if ( ++p == pe )
		goto _test_eof51;
	/* fall through */
case 51:
#line 2018 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 60 )
		goto st52;
	goto tr82;
st52:
	if ( ++p == pe )
		goto _test_eof52;
	/* fall through */
case 52:
	if ( (*p) == 73 )
		goto st53;
	goto tr82;
st53:
	if ( ++p == pe )
		goto _test_eof53;
	/* fall through */
case 53:
	if ( (*p) == 68 )
		goto st54;
	goto tr82;
st54:
	if ( ++p == pe )
		goto _test_eof54;
	/* fall through */
case 54:
	if ( (*p) == 61 )
		goto st55;
	goto tr82;
st55:
	if ( ++p == pe )
		goto _test_eof55;
	/* fall through */
case 55:
	if ( (*p) == 61 )
		goto tr91;
	if ( (*p) < 63 ) {
		if ( (*p) < 45 ) {
			if ( 33 <= (*p) && (*p) <= 43 )
				goto tr91;
		} else if ( (*p) > 47 ) {
			if ( (*p) > 57 ) {
				if ( 58 <= (*p) && (*p) <= 59 )
					goto tr91;
			} else if ( (*p) >= 48 )
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
					goto tr91;
			} else if ( (*p) >= 97 )
				goto tr92;
		} else
			goto tr91;
	} else
		goto tr91;
	goto tr90;
tr91:
#line 144 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st56;
st56:
	if ( ++p == pe )
		goto _test_eof56;
	/* fall through */
case 56:
#line 2095 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 61 )
		goto st56;
	if ( (*p) < 63 ) {
		if ( (*p) < 45 ) {
			if ( 33 <= (*p) && (*p) <= 43 )
				goto st56;
		} else if ( (*p) > 47 ) {
			if ( (*p) > 57 ) {
				if ( 58 <= (*p) && (*p) <= 59 )
					goto st56;
			} else if ( (*p) >= 48 )
				goto tr94;
		} else
			goto st56;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr94;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto st56;
			} else if ( (*p) >= 97 )
				goto tr94;
		} else
			goto st56;
	} else
		goto st56;
	goto tr90;
tr94:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st57;
tr92:
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
	goto st57;
st57:
	if ( ++p == pe )
		goto _test_eof57;
	/* fall through */
case 57:
#line 2150 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 44: goto tr95;
		case 62: goto tr96;
	}
	if ( (*p) > 59 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr94;
	} else if ( (*p) >= 33 )
		goto tr94;
	goto tr90;
tr95:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st58;
st58:
	if ( ++p == pe )
		goto _test_eof58;
	/* fall through */
case 58:
#line 2172 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr98;
		case 95: goto tr98;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr98;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr99;
		} else if ( (*p) >= 65 )
			goto tr99;
	} else
		goto tr99;
	goto tr97;
tr98:
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
#line 2200 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto st59;
		case 95: goto st59;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st59;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr101;
		} else if ( (*p) >= 65 )
			goto tr101;
	} else
		goto tr101;
	goto tr97;
tr99:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st60;
tr101:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st60;
st60:
	if ( ++p == pe )
		goto _test_eof60;
	/* fall through */
case 60:
#line 2238 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr101;
		case 61: goto tr102;
		case 95: goto tr101;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr101;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr101;
		} else if ( (*p) >= 65 )
			goto tr101;
	} else
		goto tr101;
	goto tr97;
tr102:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st61;
st61:
	if ( ++p == pe )
		goto _test_eof61;
	/* fall through */
case 61:
#line 2267 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 34 )
		goto st62;
	goto tr82;
st62:
	if ( ++p == pe )
		goto _test_eof62;
	/* fall through */
case 62:
	switch( (*p) ) {
		case 34: goto tr106;
		case 92: goto tr107;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr105;
	goto tr104;
tr105:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st63;
tr108:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st63;
st63:
	if ( ++p == pe )
		goto _test_eof63;
	/* fall through */
case 63:
#line 2304 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr109;
		case 92: goto tr110;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr108;
	goto tr104;
tr106:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st64;
tr109:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st64;
st64:
	if ( ++p == pe )
		goto _test_eof64;
	/* fall through */
case 64:
#line 2333 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 44: goto st58;
		case 62: goto st65;
	}
	goto tr104;
tr96:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st65;
st65:
	if ( ++p == pe )
		goto _test_eof65;
	/* fall through */
case 65:
#line 2350 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
	}
	goto tr82;
tr107:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st66;
tr110:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st66;
st66:
	if ( ++p == pe )
		goto _test_eof66;
	/* fall through */
case 66:
#line 2377 "inc/vcf/validator_detail_v45.hpp"
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr108;
	goto tr82;
tr32:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st67;
st67:
	if ( ++p == pe )
		goto _test_eof67;
	/* fall through */
case 67:
#line 2396 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 73: goto tr114;
		case 79: goto tr115;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr113;
tr114:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st68;
st68:
	if ( ++p == pe )
		goto _test_eof68;
	/* fall through */
case 68:
#line 2416 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 76: goto tr117;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr116;
tr117:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st69;
st69:
	if ( ++p == pe )
		goto _test_eof69;
	/* fall through */
case 69:
#line 2435 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 84: goto tr118;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr116;
tr118:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st70;
st70:
	if ( ++p == pe )
		goto _test_eof70;
	/* fall through */
case 70:
#line 2454 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 69: goto tr119;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr116;
tr119:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st71;
st71:
	if ( ++p == pe )
		goto _test_eof71;
	/* fall through */
case 71:
#line 2473 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 82: goto st72;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr116;
st72:
	if ( ++p == pe )
		goto _test_eof72;
	/* fall through */
case 72:
	if ( (*p) == 61 )
		goto tr121;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr116;
tr121:
#line 120 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "FILTER");
    }
	goto st73;
st73:
	if ( ++p == pe )
		goto _test_eof73;
	/* fall through */
case 73:
#line 2502 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 60 )
		goto st74;
	goto tr116;
st74:
	if ( ++p == pe )
		goto _test_eof74;
	/* fall through */
case 74:
	if ( (*p) == 73 )
		goto st75;
	goto tr116;
st75:
	if ( ++p == pe )
		goto _test_eof75;
	/* fall through */
case 75:
	if ( (*p) == 68 )
		goto st76;
	goto tr116;
st76:
	if ( ++p == pe )
		goto _test_eof76;
	/* fall through */
case 76:
	if ( (*p) == 61 )
		goto st77;
	goto tr116;
st77:
	if ( ++p == pe )
		goto _test_eof77;
	/* fall through */
case 77:
	switch( (*p) ) {
		case 43: goto tr127;
		case 95: goto tr127;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr127;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr128;
		} else if ( (*p) >= 65 )
			goto tr128;
	} else
		goto tr128;
	goto tr126;
tr127:
#line 144 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st78;
st78:
	if ( ++p == pe )
		goto _test_eof78;
	/* fall through */
case 78:
#line 2566 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto st78;
		case 95: goto st78;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st78;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr130;
		} else if ( (*p) >= 65 )
			goto tr130;
	} else
		goto tr130;
	goto tr126;
tr130:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st79;
tr128:
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
	goto st79;
st79:
	if ( ++p == pe )
		goto _test_eof79;
	/* fall through */
case 79:
#line 2608 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 44: goto tr131;
		case 62: goto tr132;
		case 95: goto tr130;
	}
	if ( (*p) < 48 ) {
		if ( 43 <= (*p) && (*p) <= 46 )
			goto tr130;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr130;
		} else if ( (*p) >= 65 )
			goto tr130;
	} else
		goto tr130;
	goto tr126;
tr131:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st80;
st80:
	if ( ++p == pe )
		goto _test_eof80;
	/* fall through */
case 80:
#line 2637 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr133;
		case 95: goto tr133;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr133;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr134;
		} else if ( (*p) >= 65 )
			goto tr134;
	} else
		goto tr134;
	goto tr126;
tr133:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st81;
st81:
	if ( ++p == pe )
		goto _test_eof81;
	/* fall through */
case 81:
#line 2665 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto st81;
		case 95: goto st81;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st81;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr136;
		} else if ( (*p) >= 65 )
			goto tr136;
	} else
		goto tr136;
	goto tr126;
tr134:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st82;
tr136:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st82;
st82:
	if ( ++p == pe )
		goto _test_eof82;
	/* fall through */
case 82:
#line 2703 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr136;
		case 61: goto tr137;
		case 95: goto tr136;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr136;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr136;
		} else if ( (*p) >= 65 )
			goto tr136;
	} else
		goto tr136;
	goto tr126;
tr137:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st83;
st83:
	if ( ++p == pe )
		goto _test_eof83;
	/* fall through */
case 83:
#line 2732 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 34 )
		goto st84;
	goto tr116;
st84:
	if ( ++p == pe )
		goto _test_eof84;
	/* fall through */
case 84:
	switch( (*p) ) {
		case 34: goto tr141;
		case 92: goto tr142;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr140;
	goto tr139;
tr140:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st85;
tr143:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st85;
st85:
	if ( ++p == pe )
		goto _test_eof85;
	/* fall through */
case 85:
#line 2769 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr144;
		case 92: goto tr145;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr143;
	goto tr139;
tr141:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st86;
tr144:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st86;
st86:
	if ( ++p == pe )
		goto _test_eof86;
	/* fall through */
case 86:
#line 2798 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 44: goto st80;
		case 62: goto st87;
	}
	goto tr139;
tr132:
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
#line 2815 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
	}
	goto tr116;
tr142:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st88;
tr145:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st88;
st88:
	if ( ++p == pe )
		goto _test_eof88;
	/* fall through */
case 88:
#line 2842 "inc/vcf/validator_detail_v45.hpp"
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr143;
	goto tr116;
tr115:
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
#line 2857 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 82: goto tr149;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr148;
tr149:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st90;
st90:
	if ( ++p == pe )
		goto _test_eof90;
	/* fall through */
case 90:
#line 2876 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 77: goto tr150;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr148;
tr150:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st91;
st91:
	if ( ++p == pe )
		goto _test_eof91;
	/* fall through */
case 91:
#line 2895 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 65: goto tr151;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr148;
tr151:
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
#line 2914 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 84: goto st93;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr148;
st93:
	if ( ++p == pe )
		goto _test_eof93;
	/* fall through */
case 93:
	if ( (*p) == 61 )
		goto tr153;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr148;
tr153:
#line 124 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "FORMAT");
    }
	goto st94;
st94:
	if ( ++p == pe )
		goto _test_eof94;
	/* fall through */
case 94:
#line 2943 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 60 )
		goto st95;
	goto tr148;
st95:
	if ( ++p == pe )
		goto _test_eof95;
	/* fall through */
case 95:
	if ( (*p) == 73 )
		goto st96;
	goto tr148;
st96:
	if ( ++p == pe )
		goto _test_eof96;
	/* fall through */
case 96:
	if ( (*p) == 68 )
		goto st97;
	goto tr148;
st97:
	if ( ++p == pe )
		goto _test_eof97;
	/* fall through */
case 97:
	if ( (*p) == 61 )
		goto st98;
	goto tr148;
st98:
	if ( ++p == pe )
		goto _test_eof98;
	/* fall through */
case 98:
	switch( (*p) ) {
		case 43: goto tr159;
		case 95: goto tr159;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr159;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr160;
		} else if ( (*p) >= 65 )
			goto tr160;
	} else
		goto tr160;
	goto tr158;
tr159:
#line 144 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st99;
st99:
	if ( ++p == pe )
		goto _test_eof99;
	/* fall through */
case 99:
#line 3007 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto st99;
		case 95: goto st99;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st99;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr162;
		} else if ( (*p) >= 65 )
			goto tr162;
	} else
		goto tr162;
	goto tr158;
tr162:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st100;
tr160:
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
	goto st100;
st100:
	if ( ++p == pe )
		goto _test_eof100;
	/* fall through */
case 100:
#line 3049 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 44: goto tr163;
		case 95: goto tr162;
	}
	if ( (*p) < 48 ) {
		if ( 43 <= (*p) && (*p) <= 46 )
			goto tr162;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr162;
		} else if ( (*p) >= 65 )
			goto tr162;
	} else
		goto tr162;
	goto tr158;
tr163:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st101;
st101:
	if ( ++p == pe )
		goto _test_eof101;
	/* fall through */
case 101:
#line 3077 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 78 )
		goto st102;
	goto tr148;
st102:
	if ( ++p == pe )
		goto _test_eof102;
	/* fall through */
case 102:
	if ( (*p) == 117 )
		goto st103;
	goto tr148;
st103:
	if ( ++p == pe )
		goto _test_eof103;
	/* fall through */
case 103:
	if ( (*p) == 109 )
		goto st104;
	goto tr148;
st104:
	if ( ++p == pe )
		goto _test_eof104;
	/* fall through */
case 104:
	if ( (*p) == 98 )
		goto st105;
	goto tr148;
st105:
	if ( ++p == pe )
		goto _test_eof105;
	/* fall through */
case 105:
	if ( (*p) == 101 )
		goto st106;
	goto tr148;
st106:
	if ( ++p == pe )
		goto _test_eof106;
	/* fall through */
case 106:
	if ( (*p) == 114 )
		goto st107;
	goto tr148;
st107:
	if ( ++p == pe )
		goto _test_eof107;
	/* fall through */
case 107:
	if ( (*p) == 61 )
		goto st108;
	goto tr148;
st108:
	if ( ++p == pe )
		goto _test_eof108;
	/* fall through */
case 108:
	switch( (*p) ) {
		case 46: goto tr172;
		case 65: goto tr172;
		case 71: goto tr172;
		case 76: goto tr174;
		case 77: goto tr172;
		case 80: goto tr172;
		case 82: goto tr172;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr173;
	goto tr171;
tr214:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st109;
tr172:
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
	goto st109;
st109:
	if ( ++p == pe )
		goto _test_eof109;
	/* fall through */
case 109:
#line 3171 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 44 )
		goto tr175;
	goto tr171;
tr175:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st110;
st110:
	if ( ++p == pe )
		goto _test_eof110;
	/* fall through */
case 110:
#line 3186 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 84 )
		goto st111;
	goto tr148;
st111:
	if ( ++p == pe )
		goto _test_eof111;
	/* fall through */
case 111:
	if ( (*p) == 121 )
		goto st112;
	goto tr148;
st112:
	if ( ++p == pe )
		goto _test_eof112;
	/* fall through */
case 112:
	if ( (*p) == 112 )
		goto st113;
	goto tr148;
st113:
	if ( ++p == pe )
		goto _test_eof113;
	/* fall through */
case 113:
	if ( (*p) == 101 )
		goto st114;
	goto tr148;
st114:
	if ( ++p == pe )
		goto _test_eof114;
	/* fall through */
case 114:
	if ( (*p) == 61 )
		goto st115;
	goto tr148;
st115:
	if ( ++p == pe )
		goto _test_eof115;
	/* fall through */
case 115:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr182;
	} else if ( (*p) >= 65 )
		goto tr182;
	goto tr181;
tr184:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st116;
tr182:
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
	goto st116;
st116:
	if ( ++p == pe )
		goto _test_eof116;
	/* fall through */
case 116:
#line 3258 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 44 )
		goto tr183;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr184;
	} else if ( (*p) >= 65 )
		goto tr184;
	goto tr181;
tr183:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st117;
st117:
	if ( ++p == pe )
		goto _test_eof117;
	/* fall through */
case 117:
#line 3278 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 68 )
		goto st118;
	goto tr148;
st118:
	if ( ++p == pe )
		goto _test_eof118;
	/* fall through */
case 118:
	if ( (*p) == 101 )
		goto st119;
	goto tr148;
st119:
	if ( ++p == pe )
		goto _test_eof119;
	/* fall through */
case 119:
	if ( (*p) == 115 )
		goto st120;
	goto tr148;
st120:
	if ( ++p == pe )
		goto _test_eof120;
	/* fall through */
case 120:
	if ( (*p) == 99 )
		goto st121;
	goto tr148;
st121:
	if ( ++p == pe )
		goto _test_eof121;
	/* fall through */
case 121:
	if ( (*p) == 114 )
		goto st122;
	goto tr148;
st122:
	if ( ++p == pe )
		goto _test_eof122;
	/* fall through */
case 122:
	if ( (*p) == 105 )
		goto st123;
	goto tr148;
st123:
	if ( ++p == pe )
		goto _test_eof123;
	/* fall through */
case 123:
	if ( (*p) == 112 )
		goto st124;
	goto tr148;
st124:
	if ( ++p == pe )
		goto _test_eof124;
	/* fall through */
case 124:
	if ( (*p) == 116 )
		goto st125;
	goto tr148;
st125:
	if ( ++p == pe )
		goto _test_eof125;
	/* fall through */
case 125:
	if ( (*p) == 105 )
		goto st126;
	goto tr148;
st126:
	if ( ++p == pe )
		goto _test_eof126;
	/* fall through */
case 126:
	if ( (*p) == 111 )
		goto st127;
	goto tr148;
st127:
	if ( ++p == pe )
		goto _test_eof127;
	/* fall through */
case 127:
	if ( (*p) == 110 )
		goto st128;
	goto tr148;
st128:
	if ( ++p == pe )
		goto _test_eof128;
	/* fall through */
case 128:
	if ( (*p) == 61 )
		goto st129;
	goto tr148;
st129:
	if ( ++p == pe )
		goto _test_eof129;
	/* fall through */
case 129:
	if ( (*p) == 34 )
		goto tr197;
	goto tr148;
tr197:
#line 156 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Description");
    }
	goto st130;
st130:
	if ( ++p == pe )
		goto _test_eof130;
	/* fall through */
case 130:
#line 3389 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr200;
		case 92: goto tr201;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr199;
	goto tr198;
tr199:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st131;
tr202:
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
#line 3418 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr203;
		case 92: goto tr204;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr202;
	goto tr198;
tr200:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st132;
tr203:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st132;
st132:
	if ( ++p == pe )
		goto _test_eof132;
	/* fall through */
case 132:
#line 3447 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 44: goto st133;
		case 62: goto st137;
	}
	goto tr198;
st133:
	if ( ++p == pe )
		goto _test_eof133;
	/* fall through */
case 133:
	switch( (*p) ) {
		case 43: goto tr207;
		case 95: goto tr207;
	}
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
	goto tr158;
tr207:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st134;
st134:
	if ( ++p == pe )
		goto _test_eof134;
	/* fall through */
case 134:
#line 3485 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto st134;
		case 95: goto st134;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st134;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr210;
		} else if ( (*p) >= 65 )
			goto tr210;
	} else
		goto tr210;
	goto tr158;
tr208:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st135;
tr210:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st135;
st135:
	if ( ++p == pe )
		goto _test_eof135;
	/* fall through */
case 135:
#line 3523 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr210;
		case 61: goto tr211;
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
	goto tr158;
tr211:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st136;
st136:
	if ( ++p == pe )
		goto _test_eof136;
	/* fall through */
case 136:
#line 3552 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 34 )
		goto st130;
	goto tr148;
st137:
	if ( ++p == pe )
		goto _test_eof137;
	/* fall through */
case 137:
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
	}
	goto tr148;
tr201:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st138;
tr204:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st138;
st138:
	if ( ++p == pe )
		goto _test_eof138;
	/* fall through */
case 138:
#line 3587 "inc/vcf/validator_detail_v45.hpp"
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr202;
	goto tr148;
tr213:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st139;
tr173:
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
	goto st139;
st139:
	if ( ++p == pe )
		goto _test_eof139;
	/* fall through */
case 139:
#line 3616 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 44 )
		goto tr175;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr213;
	goto tr171;
tr174:
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
	goto st140;
st140:
	if ( ++p == pe )
		goto _test_eof140;
	/* fall through */
case 140:
#line 3641 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 65: goto tr214;
		case 71: goto tr214;
		case 82: goto tr214;
	}
	goto tr171;
tr33:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st141;
st141:
	if ( ++p == pe )
		goto _test_eof141;
	/* fall through */
case 141:
#line 3663 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 78: goto tr216;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr215;
tr216:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st142;
st142:
	if ( ++p == pe )
		goto _test_eof142;
	/* fall through */
case 142:
#line 3682 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 70: goto tr217;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr215;
tr217:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st143;
st143:
	if ( ++p == pe )
		goto _test_eof143;
	/* fall through */
case 143:
#line 3701 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 79: goto st144;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr215;
st144:
	if ( ++p == pe )
		goto _test_eof144;
	/* fall through */
case 144:
	if ( (*p) == 61 )
		goto tr219;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr215;
tr219:
#line 128 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "INFO");
    }
	goto st145;
st145:
	if ( ++p == pe )
		goto _test_eof145;
	/* fall through */
case 145:
#line 3730 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 60 )
		goto st146;
	goto tr215;
st146:
	if ( ++p == pe )
		goto _test_eof146;
	/* fall through */
case 146:
	if ( (*p) == 73 )
		goto st147;
	goto tr215;
st147:
	if ( ++p == pe )
		goto _test_eof147;
	/* fall through */
case 147:
	if ( (*p) == 68 )
		goto st148;
	goto tr215;
st148:
	if ( ++p == pe )
		goto _test_eof148;
	/* fall through */
case 148:
	if ( (*p) == 61 )
		goto st149;
	goto tr215;
st149:
	if ( ++p == pe )
		goto _test_eof149;
	/* fall through */
case 149:
	switch( (*p) ) {
		case 43: goto tr225;
		case 95: goto tr225;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr225;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr226;
		} else if ( (*p) >= 65 )
			goto tr226;
	} else
		goto tr226;
	goto tr224;
tr225:
#line 144 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st150;
st150:
	if ( ++p == pe )
		goto _test_eof150;
	/* fall through */
case 150:
#line 3794 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto st150;
		case 95: goto st150;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st150;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr228;
		} else if ( (*p) >= 65 )
			goto tr228;
	} else
		goto tr228;
	goto tr224;
tr228:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st151;
tr226:
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
	goto st151;
st151:
	if ( ++p == pe )
		goto _test_eof151;
	/* fall through */
case 151:
#line 3836 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 44: goto tr229;
		case 95: goto tr228;
	}
	if ( (*p) < 48 ) {
		if ( 43 <= (*p) && (*p) <= 46 )
			goto tr228;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr228;
		} else if ( (*p) >= 65 )
			goto tr228;
	} else
		goto tr228;
	goto tr224;
tr229:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st152;
st152:
	if ( ++p == pe )
		goto _test_eof152;
	/* fall through */
case 152:
#line 3864 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 78 )
		goto st153;
	goto tr215;
st153:
	if ( ++p == pe )
		goto _test_eof153;
	/* fall through */
case 153:
	if ( (*p) == 117 )
		goto st154;
	goto tr215;
st154:
	if ( ++p == pe )
		goto _test_eof154;
	/* fall through */
case 154:
	if ( (*p) == 109 )
		goto st155;
	goto tr215;
st155:
	if ( ++p == pe )
		goto _test_eof155;
	/* fall through */
case 155:
	if ( (*p) == 98 )
		goto st156;
	goto tr215;
st156:
	if ( ++p == pe )
		goto _test_eof156;
	/* fall through */
case 156:
	if ( (*p) == 101 )
		goto st157;
	goto tr215;
st157:
	if ( ++p == pe )
		goto _test_eof157;
	/* fall through */
case 157:
	if ( (*p) == 114 )
		goto st158;
	goto tr215;
st158:
	if ( ++p == pe )
		goto _test_eof158;
	/* fall through */
case 158:
	if ( (*p) == 61 )
		goto st159;
	goto tr215;
st159:
	if ( ++p == pe )
		goto _test_eof159;
	/* fall through */
case 159:
	switch( (*p) ) {
		case 46: goto tr238;
		case 65: goto tr238;
		case 71: goto tr238;
		case 82: goto tr238;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr239;
	goto tr237;
tr238:
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
	goto st160;
st160:
	if ( ++p == pe )
		goto _test_eof160;
	/* fall through */
case 160:
#line 3949 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 44 )
		goto tr240;
	goto tr237;
tr240:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st161;
st161:
	if ( ++p == pe )
		goto _test_eof161;
	/* fall through */
case 161:
#line 3964 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 84 )
		goto st162;
	goto tr215;
st162:
	if ( ++p == pe )
		goto _test_eof162;
	/* fall through */
case 162:
	if ( (*p) == 121 )
		goto st163;
	goto tr215;
st163:
	if ( ++p == pe )
		goto _test_eof163;
	/* fall through */
case 163:
	if ( (*p) == 112 )
		goto st164;
	goto tr215;
st164:
	if ( ++p == pe )
		goto _test_eof164;
	/* fall through */
case 164:
	if ( (*p) == 101 )
		goto st165;
	goto tr215;
st165:
	if ( ++p == pe )
		goto _test_eof165;
	/* fall through */
case 165:
	if ( (*p) == 61 )
		goto st166;
	goto tr215;
st166:
	if ( ++p == pe )
		goto _test_eof166;
	/* fall through */
case 166:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr247;
	} else if ( (*p) >= 65 )
		goto tr247;
	goto tr246;
tr249:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st167;
tr247:
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
	goto st167;
st167:
	if ( ++p == pe )
		goto _test_eof167;
	/* fall through */
case 167:
#line 4036 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 44 )
		goto tr248;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr249;
	} else if ( (*p) >= 65 )
		goto tr249;
	goto tr246;
tr248:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st168;
st168:
	if ( ++p == pe )
		goto _test_eof168;
	/* fall through */
case 168:
#line 4056 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 68 )
		goto st169;
	goto tr215;
st169:
	if ( ++p == pe )
		goto _test_eof169;
	/* fall through */
case 169:
	if ( (*p) == 101 )
		goto st170;
	goto tr215;
st170:
	if ( ++p == pe )
		goto _test_eof170;
	/* fall through */
case 170:
	if ( (*p) == 115 )
		goto st171;
	goto tr215;
st171:
	if ( ++p == pe )
		goto _test_eof171;
	/* fall through */
case 171:
	if ( (*p) == 99 )
		goto st172;
	goto tr215;
st172:
	if ( ++p == pe )
		goto _test_eof172;
	/* fall through */
case 172:
	if ( (*p) == 114 )
		goto st173;
	goto tr215;
st173:
	if ( ++p == pe )
		goto _test_eof173;
	/* fall through */
case 173:
	if ( (*p) == 105 )
		goto st174;
	goto tr215;
st174:
	if ( ++p == pe )
		goto _test_eof174;
	/* fall through */
case 174:
	if ( (*p) == 112 )
		goto st175;
	goto tr215;
st175:
	if ( ++p == pe )
		goto _test_eof175;
	/* fall through */
case 175:
	if ( (*p) == 116 )
		goto st176;
	goto tr215;
st176:
	if ( ++p == pe )
		goto _test_eof176;
	/* fall through */
case 176:
	if ( (*p) == 105 )
		goto st177;
	goto tr215;
st177:
	if ( ++p == pe )
		goto _test_eof177;
	/* fall through */
case 177:
	if ( (*p) == 111 )
		goto st178;
	goto tr215;
st178:
	if ( ++p == pe )
		goto _test_eof178;
	/* fall through */
case 178:
	if ( (*p) == 110 )
		goto st179;
	goto tr215;
st179:
	if ( ++p == pe )
		goto _test_eof179;
	/* fall through */
case 179:
	if ( (*p) == 61 )
		goto st180;
	goto tr215;
st180:
	if ( ++p == pe )
		goto _test_eof180;
	/* fall through */
case 180:
	if ( (*p) == 34 )
		goto tr262;
	goto tr215;
tr262:
#line 156 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Description");
    }
	goto st181;
st181:
	if ( ++p == pe )
		goto _test_eof181;
	/* fall through */
case 181:
#line 4167 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr265;
		case 92: goto tr266;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr264;
	goto tr263;
tr264:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st182;
tr267:
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
#line 4196 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr268;
		case 92: goto tr269;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr267;
	goto tr263;
tr265:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st183;
tr268:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st183;
st183:
	if ( ++p == pe )
		goto _test_eof183;
	/* fall through */
case 183:
#line 4225 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 44: goto st184;
		case 62: goto st188;
	}
	goto tr263;
st184:
	if ( ++p == pe )
		goto _test_eof184;
	/* fall through */
case 184:
	switch( (*p) ) {
		case 43: goto tr272;
		case 95: goto tr272;
	}
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
	goto tr224;
tr272:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st185;
st185:
	if ( ++p == pe )
		goto _test_eof185;
	/* fall through */
case 185:
#line 4263 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto st185;
		case 95: goto st185;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st185;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr275;
		} else if ( (*p) >= 65 )
			goto tr275;
	} else
		goto tr275;
	goto tr224;
tr273:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st186;
tr275:
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
#line 4301 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr275;
		case 61: goto tr276;
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
	goto tr224;
tr276:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st187;
st187:
	if ( ++p == pe )
		goto _test_eof187;
	/* fall through */
case 187:
#line 4330 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 34 )
		goto st181;
	goto tr215;
st188:
	if ( ++p == pe )
		goto _test_eof188;
	/* fall through */
case 188:
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
	}
	goto tr215;
tr266:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st189;
tr269:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st189;
st189:
	if ( ++p == pe )
		goto _test_eof189;
	/* fall through */
case 189:
#line 4365 "inc/vcf/validator_detail_v45.hpp"
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr267;
	goto tr215;
tr278:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st190;
tr239:
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
	goto st190;
st190:
	if ( ++p == pe )
		goto _test_eof190;
	/* fall through */
case 190:
#line 4394 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 44 )
		goto tr240;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr278;
	goto tr237;
tr34:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st191;
st191:
	if ( ++p == pe )
		goto _test_eof191;
	/* fall through */
case 191:
#line 4415 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 69: goto tr280;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr279;
tr280:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st192;
st192:
	if ( ++p == pe )
		goto _test_eof192;
	/* fall through */
case 192:
#line 4434 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 84: goto tr281;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr279;
tr281:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st193;
st193:
	if ( ++p == pe )
		goto _test_eof193;
	/* fall through */
case 193:
#line 4453 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 65: goto st194;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr279;
st194:
	if ( ++p == pe )
		goto _test_eof194;
	/* fall through */
case 194:
	if ( (*p) == 61 )
		goto tr283;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr279;
tr283:
#line 168 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "META");
    }
	goto st195;
st195:
	if ( ++p == pe )
		goto _test_eof195;
	/* fall through */
case 195:
#line 4482 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 60 )
		goto st196;
	goto tr279;
st196:
	if ( ++p == pe )
		goto _test_eof196;
	/* fall through */
case 196:
	if ( (*p) == 73 )
		goto st197;
	goto tr279;
st197:
	if ( ++p == pe )
		goto _test_eof197;
	/* fall through */
case 197:
	if ( (*p) == 68 )
		goto st198;
	goto tr279;
st198:
	if ( ++p == pe )
		goto _test_eof198;
	/* fall through */
case 198:
	if ( (*p) == 61 )
		goto st199;
	goto tr279;
st199:
	if ( ++p == pe )
		goto _test_eof199;
	/* fall through */
case 199:
	switch( (*p) ) {
		case 43: goto tr289;
		case 95: goto tr289;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr289;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr290;
		} else if ( (*p) >= 65 )
			goto tr290;
	} else
		goto tr290;
	goto tr288;
tr289:
#line 144 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st200;
st200:
	if ( ++p == pe )
		goto _test_eof200;
	/* fall through */
case 200:
#line 4546 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto st200;
		case 95: goto st200;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st200;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr292;
		} else if ( (*p) >= 65 )
			goto tr292;
	} else
		goto tr292;
	goto tr288;
tr292:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st201;
tr290:
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
	goto st201;
st201:
	if ( ++p == pe )
		goto _test_eof201;
	/* fall through */
case 201:
#line 4588 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 44: goto tr293;
		case 95: goto tr292;
	}
	if ( (*p) < 48 ) {
		if ( 43 <= (*p) && (*p) <= 46 )
			goto tr292;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr292;
		} else if ( (*p) >= 65 )
			goto tr292;
	} else
		goto tr292;
	goto tr288;
tr293:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st202;
st202:
	if ( ++p == pe )
		goto _test_eof202;
	/* fall through */
case 202:
#line 4616 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 78 )
		goto st203;
	goto tr279;
st203:
	if ( ++p == pe )
		goto _test_eof203;
	/* fall through */
case 203:
	if ( (*p) == 117 )
		goto st204;
	goto tr279;
st204:
	if ( ++p == pe )
		goto _test_eof204;
	/* fall through */
case 204:
	if ( (*p) == 109 )
		goto st205;
	goto tr279;
st205:
	if ( ++p == pe )
		goto _test_eof205;
	/* fall through */
case 205:
	if ( (*p) == 98 )
		goto st206;
	goto tr279;
st206:
	if ( ++p == pe )
		goto _test_eof206;
	/* fall through */
case 206:
	if ( (*p) == 101 )
		goto st207;
	goto tr279;
st207:
	if ( ++p == pe )
		goto _test_eof207;
	/* fall through */
case 207:
	if ( (*p) == 114 )
		goto st208;
	goto tr279;
st208:
	if ( ++p == pe )
		goto _test_eof208;
	/* fall through */
case 208:
	if ( (*p) == 61 )
		goto st209;
	goto tr279;
st209:
	if ( ++p == pe )
		goto _test_eof209;
	/* fall through */
case 209:
	if ( (*p) == 46 )
		goto tr302;
	goto tr301;
tr302:
#line 148 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Number");
    }
	goto st210;
st210:
	if ( ++p == pe )
		goto _test_eof210;
	/* fall through */
case 210:
#line 4687 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 44 )
		goto st211;
	goto tr301;
st211:
	if ( ++p == pe )
		goto _test_eof211;
	/* fall through */
case 211:
	if ( (*p) == 84 )
		goto st212;
	goto tr279;
st212:
	if ( ++p == pe )
		goto _test_eof212;
	/* fall through */
case 212:
	if ( (*p) == 121 )
		goto st213;
	goto tr279;
st213:
	if ( ++p == pe )
		goto _test_eof213;
	/* fall through */
case 213:
	if ( (*p) == 112 )
		goto st214;
	goto tr279;
st214:
	if ( ++p == pe )
		goto _test_eof214;
	/* fall through */
case 214:
	if ( (*p) == 101 )
		goto st215;
	goto tr279;
st215:
	if ( ++p == pe )
		goto _test_eof215;
	/* fall through */
case 215:
	if ( (*p) == 61 )
		goto st216;
	goto tr279;
st216:
	if ( ++p == pe )
		goto _test_eof216;
	/* fall through */
case 216:
	if ( (*p) == 83 )
		goto tr310;
	goto tr309;
tr310:
#line 152 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Type");
    }
	goto st217;
st217:
	if ( ++p == pe )
		goto _test_eof217;
	/* fall through */
case 217:
#line 4750 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 116 )
		goto st218;
	goto tr309;
st218:
	if ( ++p == pe )
		goto _test_eof218;
	/* fall through */
case 218:
	if ( (*p) == 114 )
		goto st219;
	goto tr309;
st219:
	if ( ++p == pe )
		goto _test_eof219;
	/* fall through */
case 219:
	if ( (*p) == 105 )
		goto st220;
	goto tr309;
st220:
	if ( ++p == pe )
		goto _test_eof220;
	/* fall through */
case 220:
	if ( (*p) == 110 )
		goto st221;
	goto tr309;
st221:
	if ( ++p == pe )
		goto _test_eof221;
	/* fall through */
case 221:
	if ( (*p) == 103 )
		goto st222;
	goto tr309;
st222:
	if ( ++p == pe )
		goto _test_eof222;
	/* fall through */
case 222:
	if ( (*p) == 44 )
		goto st223;
	goto tr309;
st223:
	if ( ++p == pe )
		goto _test_eof223;
	/* fall through */
case 223:
	if ( (*p) == 86 )
		goto st224;
	goto tr279;
st224:
	if ( ++p == pe )
		goto _test_eof224;
	/* fall through */
case 224:
	if ( (*p) == 97 )
		goto st225;
	goto tr279;
st225:
	if ( ++p == pe )
		goto _test_eof225;
	/* fall through */
case 225:
	if ( (*p) == 108 )
		goto st226;
	goto tr279;
st226:
	if ( ++p == pe )
		goto _test_eof226;
	/* fall through */
case 226:
	if ( (*p) == 117 )
		goto st227;
	goto tr279;
st227:
	if ( ++p == pe )
		goto _test_eof227;
	/* fall through */
case 227:
	if ( (*p) == 101 )
		goto st228;
	goto tr279;
st228:
	if ( ++p == pe )
		goto _test_eof228;
	/* fall through */
case 228:
	if ( (*p) == 115 )
		goto st229;
	goto tr279;
st229:
	if ( ++p == pe )
		goto _test_eof229;
	/* fall through */
case 229:
	if ( (*p) == 61 )
		goto st230;
	goto tr279;
st230:
	if ( ++p == pe )
		goto _test_eof230;
	/* fall through */
case 230:
	if ( (*p) == 91 )
		goto tr324;
	goto tr279;
tr324:
#line 172 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Values");
    }
	goto st231;
st231:
	if ( ++p == pe )
		goto _test_eof231;
	/* fall through */
case 231:
#line 4869 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 61 )
		goto tr325;
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr325;
	} else if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr325;
	} else
		goto tr325;
	goto tr279;
tr325:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st232;
tr327:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st232;
st232:
	if ( ++p == pe )
		goto _test_eof232;
	/* fall through */
case 232:
#line 4902 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 44: goto tr328;
		case 61: goto tr327;
		case 93: goto tr329;
	}
	if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr327;
	} else if ( (*p) >= 33 )
		goto tr327;
	goto tr326;
tr328:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st233;
st233:
	if ( ++p == pe )
		goto _test_eof233;
	/* fall through */
case 233:
#line 4925 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 32: goto tr330;
		case 61: goto tr327;
	}
	if ( (*p) < 33 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr330;
	} else if ( (*p) > 43 ) {
		if ( (*p) > 59 ) {
			if ( 63 <= (*p) && (*p) <= 126 )
				goto tr327;
		} else if ( (*p) >= 45 )
			goto tr327;
	} else
		goto tr327;
	goto tr279;
tr330:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st234;
st234:
	if ( ++p == pe )
		goto _test_eof234;
	/* fall through */
case 234:
#line 4953 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 61 )
		goto tr327;
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr327;
	} else if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr327;
	} else
		goto tr327;
	goto tr279;
tr329:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st235;
st235:
	if ( ++p == pe )
		goto _test_eof235;
	/* fall through */
case 235:
#line 4980 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 44: goto tr328;
		case 62: goto st236;
		case 93: goto tr329;
	}
	if ( (*p) > 59 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr327;
	} else if ( (*p) >= 33 )
		goto tr327;
	goto tr326;
st236:
	if ( ++p == pe )
		goto _test_eof236;
	/* fall through */
case 236:
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
	}
	goto tr279;
tr35:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st237;
st237:
	if ( ++p == pe )
		goto _test_eof237;
	/* fall through */
case 237:
#line 5017 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 69: goto tr333;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr332;
tr333:
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
#line 5036 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 68: goto tr334;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr332;
tr334:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st239;
st239:
	if ( ++p == pe )
		goto _test_eof239;
	/* fall through */
case 239:
#line 5055 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 73: goto tr335;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr332;
tr335:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st240;
st240:
	if ( ++p == pe )
		goto _test_eof240;
	/* fall through */
case 240:
#line 5074 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 71: goto tr336;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr332;
tr336:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st241;
st241:
	if ( ++p == pe )
		goto _test_eof241;
	/* fall through */
case 241:
#line 5093 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 82: goto tr337;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr332;
tr337:
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
#line 5112 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 69: goto tr338;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr332;
tr338:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st243;
st243:
	if ( ++p == pe )
		goto _test_eof243;
	/* fall through */
case 243:
#line 5131 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 69: goto st244;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr332;
st244:
	if ( ++p == pe )
		goto _test_eof244;
	/* fall through */
case 244:
	if ( (*p) == 61 )
		goto tr340;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr332;
tr340:
#line 132 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "PEDIGREE");
    }
	goto st245;
st245:
	if ( ++p == pe )
		goto _test_eof245;
	/* fall through */
case 245:
#line 5160 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 60 )
		goto st246;
	goto tr332;
st246:
	if ( ++p == pe )
		goto _test_eof246;
	/* fall through */
case 246:
	if ( (*p) == 73 )
		goto st247;
	goto tr332;
st247:
	if ( ++p == pe )
		goto _test_eof247;
	/* fall through */
case 247:
	if ( (*p) == 68 )
		goto st248;
	goto tr332;
st248:
	if ( ++p == pe )
		goto _test_eof248;
	/* fall through */
case 248:
	if ( (*p) == 61 )
		goto st249;
	goto tr332;
st249:
	if ( ++p == pe )
		goto _test_eof249;
	/* fall through */
case 249:
	switch( (*p) ) {
		case 43: goto tr346;
		case 95: goto tr346;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr346;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr347;
		} else if ( (*p) >= 65 )
			goto tr347;
	} else
		goto tr347;
	goto tr345;
tr346:
#line 144 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st250;
st250:
	if ( ++p == pe )
		goto _test_eof250;
	/* fall through */
case 250:
#line 5224 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto st250;
		case 95: goto st250;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st250;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr349;
		} else if ( (*p) >= 65 )
			goto tr349;
	} else
		goto tr349;
	goto tr345;
tr349:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st251;
tr347:
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
	goto st251;
st251:
	if ( ++p == pe )
		goto _test_eof251;
	/* fall through */
case 251:
#line 5266 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 44: goto tr350;
		case 95: goto tr349;
	}
	if ( (*p) < 48 ) {
		if ( 43 <= (*p) && (*p) <= 46 )
			goto tr349;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr349;
		} else if ( (*p) >= 65 )
			goto tr349;
	} else
		goto tr349;
	goto tr345;
tr350:
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
#line 5294 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 70: goto st253;
		case 78: goto tr353;
		case 79: goto st283;
	}
	goto tr351;
st253:
	if ( ++p == pe )
		goto _test_eof253;
	/* fall through */
case 253:
	if ( (*p) == 97 )
		goto st254;
	goto tr332;
st254:
	if ( ++p == pe )
		goto _test_eof254;
	/* fall through */
case 254:
	if ( (*p) == 116 )
		goto st255;
	goto tr332;
st255:
	if ( ++p == pe )
		goto _test_eof255;
	/* fall through */
case 255:
	if ( (*p) == 104 )
		goto st256;
	goto tr332;
st256:
	if ( ++p == pe )
		goto _test_eof256;
	/* fall through */
case 256:
	if ( (*p) == 101 )
		goto st257;
	goto tr332;
st257:
	if ( ++p == pe )
		goto _test_eof257;
	/* fall through */
case 257:
	if ( (*p) == 114 )
		goto st258;
	goto tr332;
st258:
	if ( ++p == pe )
		goto _test_eof258;
	/* fall through */
case 258:
	if ( (*p) == 61 )
		goto st259;
	goto tr332;
st259:
	if ( ++p == pe )
		goto _test_eof259;
	/* fall through */
case 259:
	switch( (*p) ) {
		case 43: goto tr362;
		case 95: goto tr362;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr362;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr363;
		} else if ( (*p) >= 65 )
			goto tr363;
	} else
		goto tr363;
	goto tr361;
tr362:
#line 180 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Father");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st260;
st260:
	if ( ++p == pe )
		goto _test_eof260;
	/* fall through */
case 260:
#line 5385 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto st260;
		case 95: goto st260;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st260;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr365;
		} else if ( (*p) >= 65 )
			goto tr365;
	} else
		goto tr365;
	goto tr361;
tr365:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st261;
tr363:
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
	goto st261;
st261:
	if ( ++p == pe )
		goto _test_eof261;
	/* fall through */
case 261:
#line 5427 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 44: goto tr366;
		case 95: goto tr365;
	}
	if ( (*p) < 48 ) {
		if ( 43 <= (*p) && (*p) <= 46 )
			goto tr365;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr365;
		} else if ( (*p) >= 65 )
			goto tr365;
	} else
		goto tr365;
	goto tr361;
tr366:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st262;
st262:
	if ( ++p == pe )
		goto _test_eof262;
	/* fall through */
case 262:
#line 5455 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 77 )
		goto st263;
	goto tr332;
st263:
	if ( ++p == pe )
		goto _test_eof263;
	/* fall through */
case 263:
	if ( (*p) == 111 )
		goto st264;
	goto tr332;
st264:
	if ( ++p == pe )
		goto _test_eof264;
	/* fall through */
case 264:
	if ( (*p) == 116 )
		goto st265;
	goto tr332;
st265:
	if ( ++p == pe )
		goto _test_eof265;
	/* fall through */
case 265:
	if ( (*p) == 104 )
		goto st266;
	goto tr332;
st266:
	if ( ++p == pe )
		goto _test_eof266;
	/* fall through */
case 266:
	if ( (*p) == 101 )
		goto st267;
	goto tr332;
st267:
	if ( ++p == pe )
		goto _test_eof267;
	/* fall through */
case 267:
	if ( (*p) == 114 )
		goto st268;
	goto tr332;
st268:
	if ( ++p == pe )
		goto _test_eof268;
	/* fall through */
case 268:
	if ( (*p) == 61 )
		goto st269;
	goto tr332;
st269:
	if ( ++p == pe )
		goto _test_eof269;
	/* fall through */
case 269:
	switch( (*p) ) {
		case 43: goto tr374;
		case 95: goto tr374;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr374;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr375;
		} else if ( (*p) >= 65 )
			goto tr375;
	} else
		goto tr375;
	goto tr361;
tr374:
#line 184 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Mother");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st270;
st270:
	if ( ++p == pe )
		goto _test_eof270;
	/* fall through */
case 270:
#line 5543 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto st270;
		case 95: goto st270;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st270;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr377;
		} else if ( (*p) >= 65 )
			goto tr377;
	} else
		goto tr377;
	goto tr361;
tr377:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st271;
tr375:
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
	goto st271;
st271:
	if ( ++p == pe )
		goto _test_eof271;
	/* fall through */
case 271:
#line 5585 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr377;
		case 62: goto tr378;
		case 95: goto tr377;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr377;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr377;
		} else if ( (*p) >= 65 )
			goto tr377;
	} else
		goto tr377;
	goto tr361;
tr378:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st272;
st272:
	if ( ++p == pe )
		goto _test_eof272;
	/* fall through */
case 272:
#line 5614 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
	}
	goto tr332;
tr353:
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
#line 5635 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 97 )
		goto tr379;
	goto tr351;
tr379:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st274;
st274:
	if ( ++p == pe )
		goto _test_eof274;
	/* fall through */
case 274:
#line 5650 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 109 )
		goto tr380;
	goto tr351;
tr380:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st275;
st275:
	if ( ++p == pe )
		goto _test_eof275;
	/* fall through */
case 275:
#line 5665 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 101 )
		goto tr381;
	goto tr351;
tr381:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st276;
st276:
	if ( ++p == pe )
		goto _test_eof276;
	/* fall through */
case 276:
#line 5680 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 95 )
		goto tr382;
	goto tr351;
tr382:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st277;
st277:
	if ( ++p == pe )
		goto _test_eof277;
	/* fall through */
case 277:
#line 5695 "inc/vcf/validator_detail_v45.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr383;
	goto tr351;
tr383:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st278;
st278:
	if ( ++p == pe )
		goto _test_eof278;
	/* fall through */
case 278:
#line 5710 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 61 )
		goto tr384;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr383;
	goto tr351;
tr384:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st279;
st279:
	if ( ++p == pe )
		goto _test_eof279;
	/* fall through */
case 279:
#line 5727 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr385;
		case 95: goto tr385;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr385;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr386;
		} else if ( (*p) >= 65 )
			goto tr386;
	} else
		goto tr386;
	goto tr351;
tr385:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st280;
st280:
	if ( ++p == pe )
		goto _test_eof280;
	/* fall through */
case 280:
#line 5755 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto st280;
		case 95: goto st280;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st280;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr388;
		} else if ( (*p) >= 65 )
			goto tr388;
	} else
		goto tr388;
	goto tr351;
tr386:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st281;
tr388:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st281;
st281:
	if ( ++p == pe )
		goto _test_eof281;
	/* fall through */
case 281:
#line 5793 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 44: goto tr389;
		case 62: goto tr378;
		case 95: goto tr388;
	}
	if ( (*p) < 48 ) {
		if ( 43 <= (*p) && (*p) <= 46 )
			goto tr388;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr388;
		} else if ( (*p) >= 65 )
			goto tr388;
	} else
		goto tr388;
	goto tr351;
tr389:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st282;
st282:
	if ( ++p == pe )
		goto _test_eof282;
	/* fall through */
case 282:
#line 5822 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 78 )
		goto tr353;
	goto tr351;
st283:
	if ( ++p == pe )
		goto _test_eof283;
	/* fall through */
case 283:
	if ( (*p) == 114 )
		goto st284;
	goto tr332;
st284:
	if ( ++p == pe )
		goto _test_eof284;
	/* fall through */
case 284:
	if ( (*p) == 105 )
		goto st285;
	goto tr332;
st285:
	if ( ++p == pe )
		goto _test_eof285;
	/* fall through */
case 285:
	if ( (*p) == 103 )
		goto st286;
	goto tr332;
st286:
	if ( ++p == pe )
		goto _test_eof286;
	/* fall through */
case 286:
	if ( (*p) == 105 )
		goto st287;
	goto tr332;
st287:
	if ( ++p == pe )
		goto _test_eof287;
	/* fall through */
case 287:
	if ( (*p) == 110 )
		goto st288;
	goto tr332;
st288:
	if ( ++p == pe )
		goto _test_eof288;
	/* fall through */
case 288:
	if ( (*p) == 97 )
		goto st289;
	goto tr332;
st289:
	if ( ++p == pe )
		goto _test_eof289;
	/* fall through */
case 289:
	if ( (*p) == 108 )
		goto st290;
	goto tr332;
st290:
	if ( ++p == pe )
		goto _test_eof290;
	/* fall through */
case 290:
	if ( (*p) == 61 )
		goto st291;
	goto tr332;
st291:
	if ( ++p == pe )
		goto _test_eof291;
	/* fall through */
case 291:
	switch( (*p) ) {
		case 43: goto tr399;
		case 95: goto tr399;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr399;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr400;
		} else if ( (*p) >= 65 )
			goto tr400;
	} else
		goto tr400;
	goto tr398;
tr399:
#line 176 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Original");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st292;
st292:
	if ( ++p == pe )
		goto _test_eof292;
	/* fall through */
case 292:
#line 5926 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto st292;
		case 95: goto st292;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st292;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr402;
		} else if ( (*p) >= 65 )
			goto tr402;
	} else
		goto tr402;
	goto tr398;
tr402:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st293;
tr400:
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
	goto st293;
st293:
	if ( ++p == pe )
		goto _test_eof293;
	/* fall through */
case 293:
#line 5968 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr402;
		case 62: goto tr378;
		case 95: goto tr402;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr402;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr402;
		} else if ( (*p) >= 65 )
			goto tr402;
	} else
		goto tr402;
	goto tr398;
tr36:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st294;
st294:
	if ( ++p == pe )
		goto _test_eof294;
	/* fall through */
case 294:
#line 6001 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 65: goto tr404;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr403;
tr404:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st295;
st295:
	if ( ++p == pe )
		goto _test_eof295;
	/* fall through */
case 295:
#line 6020 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 77: goto tr405;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr403;
tr405:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st296;
st296:
	if ( ++p == pe )
		goto _test_eof296;
	/* fall through */
case 296:
#line 6039 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 80: goto tr406;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr403;
tr406:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st297;
st297:
	if ( ++p == pe )
		goto _test_eof297;
	/* fall through */
case 297:
#line 6058 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 76: goto tr407;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr403;
tr407:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st298;
st298:
	if ( ++p == pe )
		goto _test_eof298;
	/* fall through */
case 298:
#line 6077 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 69: goto st299;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr403;
st299:
	if ( ++p == pe )
		goto _test_eof299;
	/* fall through */
case 299:
	if ( (*p) == 61 )
		goto tr409;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr403;
tr409:
#line 140 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "SAMPLE");
    }
	goto st300;
st300:
	if ( ++p == pe )
		goto _test_eof300;
	/* fall through */
case 300:
#line 6106 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 60 )
		goto st301;
	goto tr403;
st301:
	if ( ++p == pe )
		goto _test_eof301;
	/* fall through */
case 301:
	if ( (*p) == 73 )
		goto st302;
	goto tr403;
st302:
	if ( ++p == pe )
		goto _test_eof302;
	/* fall through */
case 302:
	if ( (*p) == 68 )
		goto st303;
	goto tr403;
st303:
	if ( ++p == pe )
		goto _test_eof303;
	/* fall through */
case 303:
	if ( (*p) == 61 )
		goto st304;
	goto tr403;
st304:
	if ( ++p == pe )
		goto _test_eof304;
	/* fall through */
case 304:
	switch( (*p) ) {
		case 43: goto tr415;
		case 95: goto tr415;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr415;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr416;
		} else if ( (*p) >= 65 )
			goto tr416;
	} else
		goto tr416;
	goto tr414;
tr415:
#line 144 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st305;
st305:
	if ( ++p == pe )
		goto _test_eof305;
	/* fall through */
case 305:
#line 6170 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto st305;
		case 95: goto st305;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st305;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr418;
		} else if ( (*p) >= 65 )
			goto tr418;
	} else
		goto tr418;
	goto tr414;
tr418:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st306;
tr416:
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
	goto st306;
st306:
	if ( ++p == pe )
		goto _test_eof306;
	/* fall through */
case 306:
#line 6212 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 44: goto tr419;
		case 62: goto tr420;
		case 95: goto tr418;
	}
	if ( (*p) < 48 ) {
		if ( 43 <= (*p) && (*p) <= 46 )
			goto tr418;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr418;
		} else if ( (*p) >= 65 )
			goto tr418;
	} else
		goto tr418;
	goto tr414;
tr419:
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
#line 6241 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr421;
		case 95: goto tr421;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr421;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr422;
		} else if ( (*p) >= 65 )
			goto tr422;
	} else
		goto tr422;
	goto tr403;
tr421:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st308;
st308:
	if ( ++p == pe )
		goto _test_eof308;
	/* fall through */
case 308:
#line 6269 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto st308;
		case 95: goto st308;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st308;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr424;
		} else if ( (*p) >= 65 )
			goto tr424;
	} else
		goto tr424;
	goto tr403;
tr422:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st309;
tr424:
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
#line 6307 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr424;
		case 61: goto tr425;
		case 95: goto tr424;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr424;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr424;
		} else if ( (*p) >= 65 )
			goto tr424;
	} else
		goto tr424;
	goto tr403;
tr425:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st310;
st310:
	if ( ++p == pe )
		goto _test_eof310;
	/* fall through */
case 310:
#line 6336 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 34 )
		goto st313;
	if ( (*p) < 45 ) {
		if ( 32 <= (*p) && (*p) <= 43 )
			goto tr426;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr426;
	} else
		goto tr426;
	goto tr403;
tr426:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st311;
tr428:
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
#line 6369 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 44: goto tr419;
		case 62: goto tr420;
	}
	if ( (*p) > 33 ) {
		if ( 35 <= (*p) && (*p) <= 126 )
			goto tr428;
	} else if ( (*p) >= 32 )
		goto tr428;
	goto tr403;
tr420:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st312;
st312:
	if ( ++p == pe )
		goto _test_eof312;
	/* fall through */
case 312:
#line 6391 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
	}
	goto tr403;
st313:
	if ( ++p == pe )
		goto _test_eof313;
	/* fall through */
case 313:
	switch( (*p) ) {
		case 34: goto tr430;
		case 92: goto tr431;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr429;
	goto tr403;
tr429:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st314;
tr432:
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
#line 6430 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr433;
		case 92: goto tr434;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr432;
	goto tr403;
tr430:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st315;
tr433:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st315;
st315:
	if ( ++p == pe )
		goto _test_eof315;
	/* fall through */
case 315:
#line 6459 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 44: goto st307;
		case 62: goto st312;
	}
	goto tr403;
tr431:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st316;
tr434:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st316;
st316:
	if ( ++p == pe )
		goto _test_eof316;
	/* fall through */
case 316:
#line 6486 "inc/vcf/validator_detail_v45.hpp"
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr432;
	goto tr403;
tr37:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st317;
st317:
	if ( ++p == pe )
		goto _test_eof317;
	/* fall through */
case 317:
#line 6505 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 115: goto tr438;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr437;
tr438:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st318;
st318:
	if ( ++p == pe )
		goto _test_eof318;
	/* fall through */
case 318:
#line 6524 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 115: goto tr439;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr437;
tr439:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st319;
st319:
	if ( ++p == pe )
		goto _test_eof319;
	/* fall through */
case 319:
#line 6543 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 101: goto tr440;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr437;
tr440:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st320;
st320:
	if ( ++p == pe )
		goto _test_eof320;
	/* fall through */
case 320:
#line 6562 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 109: goto tr441;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr437;
tr441:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st321;
st321:
	if ( ++p == pe )
		goto _test_eof321;
	/* fall through */
case 321:
#line 6581 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 98: goto tr442;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr437;
tr442:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st322;
st322:
	if ( ++p == pe )
		goto _test_eof322;
	/* fall through */
case 322:
#line 6600 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 108: goto tr443;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr437;
tr443:
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
#line 6619 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 121: goto st324;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr437;
st324:
	if ( ++p == pe )
		goto _test_eof324;
	/* fall through */
case 324:
	if ( (*p) == 61 )
		goto tr445;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr437;
tr445:
#line 112 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "assembly");
    }
	goto st325;
st325:
	if ( ++p == pe )
		goto _test_eof325;
	/* fall through */
case 325:
#line 6648 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr447;
	} else if ( (*p) >= 65 )
		goto tr447;
	goto tr446;
tr447:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st326;
st326:
	if ( ++p == pe )
		goto _test_eof326;
	/* fall through */
case 326:
#line 6666 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 10: goto tr446;
		case 13: goto tr449;
		case 35: goto tr446;
		case 47: goto tr446;
		case 58: goto tr446;
		case 63: goto tr446;
	}
	goto st327;
tr449:
#line 43 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st327;
st327:
	if ( ++p == pe )
		goto _test_eof327;
	/* fall through */
case 327:
#line 6693 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 10: goto tr446;
		case 13: goto tr449;
		case 35: goto tr446;
		case 47: goto tr446;
		case 58: goto st328;
		case 63: goto tr446;
	}
	goto st327;
st328:
	if ( ++p == pe )
		goto _test_eof328;
	/* fall through */
case 328:
	if ( (*p) == 47 )
		goto st329;
	goto tr446;
st329:
	if ( ++p == pe )
		goto _test_eof329;
	/* fall through */
case 329:
	if ( (*p) == 47 )
		goto st330;
	goto tr446;
st330:
	if ( ++p == pe )
		goto _test_eof330;
	/* fall through */
case 330:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st331;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr454;
	} else
		goto tr454;
	goto tr446;
st331:
	if ( ++p == pe )
		goto _test_eof331;
	/* fall through */
case 331:
	if ( (*p) == 46 )
		goto st332;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st342;
	goto tr446;
st332:
	if ( ++p == pe )
		goto _test_eof332;
	/* fall through */
case 332:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st333;
	goto tr446;
st333:
	if ( ++p == pe )
		goto _test_eof333;
	/* fall through */
case 333:
	if ( (*p) == 46 )
		goto st334;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st340;
	goto tr446;
st334:
	if ( ++p == pe )
		goto _test_eof334;
	/* fall through */
case 334:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st335;
	goto tr446;
st335:
	if ( ++p == pe )
		goto _test_eof335;
	/* fall through */
case 335:
	if ( (*p) == 46 )
		goto st336;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st338;
	goto tr446;
st336:
	if ( ++p == pe )
		goto _test_eof336;
	/* fall through */
case 336:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr454;
	goto tr446;
tr454:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st337;
tr463:
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
	goto st337;
st337:
	if ( ++p == pe )
		goto _test_eof337;
	/* fall through */
case 337:
#line 6826 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 10: goto tr46;
		case 13: goto tr463;
	}
	goto tr454;
st338:
	if ( ++p == pe )
		goto _test_eof338;
	/* fall through */
case 338:
	if ( (*p) == 46 )
		goto st336;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st339;
	goto tr446;
st339:
	if ( ++p == pe )
		goto _test_eof339;
	/* fall through */
case 339:
	if ( (*p) == 46 )
		goto st336;
	goto tr446;
st340:
	if ( ++p == pe )
		goto _test_eof340;
	/* fall through */
case 340:
	if ( (*p) == 46 )
		goto st334;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st341;
	goto tr446;
st341:
	if ( ++p == pe )
		goto _test_eof341;
	/* fall through */
case 341:
	if ( (*p) == 46 )
		goto st334;
	goto tr446;
st342:
	if ( ++p == pe )
		goto _test_eof342;
	/* fall through */
case 342:
	if ( (*p) == 46 )
		goto st332;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st343;
	goto tr446;
st343:
	if ( ++p == pe )
		goto _test_eof343;
	/* fall through */
case 343:
	if ( (*p) == 46 )
		goto st332;
	goto tr446;
tr38:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st344;
st344:
	if ( ++p == pe )
		goto _test_eof344;
	/* fall through */
case 344:
#line 6901 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 111: goto tr468;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr467;
tr468:
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
#line 6920 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 110: goto tr469;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr467;
tr469:
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
#line 6939 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 116: goto tr470;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr467;
tr470:
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
#line 6958 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 105: goto tr471;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr467;
tr471:
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
#line 6977 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 103: goto st349;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr467;
st349:
	if ( ++p == pe )
		goto _test_eof349;
	/* fall through */
case 349:
	if ( (*p) == 61 )
		goto tr473;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr467;
tr473:
#line 116 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "contig");
    }
	goto st350;
st350:
	if ( ++p == pe )
		goto _test_eof350;
	/* fall through */
case 350:
#line 7006 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 60 )
		goto st351;
	goto tr467;
st351:
	if ( ++p == pe )
		goto _test_eof351;
	/* fall through */
case 351:
	if ( (*p) == 73 )
		goto st352;
	goto tr467;
st352:
	if ( ++p == pe )
		goto _test_eof352;
	/* fall through */
case 352:
	if ( (*p) == 68 )
		goto st353;
	goto tr467;
st353:
	if ( ++p == pe )
		goto _test_eof353;
	/* fall through */
case 353:
	if ( (*p) == 61 )
		goto st354;
	goto tr467;
st354:
	if ( ++p == pe )
		goto _test_eof354;
	/* fall through */
case 354:
	switch( (*p) ) {
		case 43: goto tr479;
		case 92: goto tr479;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr479;
		} else if ( (*p) >= 33 )
			goto tr479;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr479;
		} else if ( (*p) >= 63 )
			goto tr479;
	} else
		goto tr479;
	goto tr478;
tr480:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st355;
tr479:
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
	goto st355;
st355:
	if ( ++p == pe )
		goto _test_eof355;
	/* fall through */
case 355:
#line 7083 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 44: goto tr481;
		case 62: goto tr482;
		case 92: goto tr480;
	}
	if ( (*p) < 43 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr480;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr480;
		} else if ( (*p) >= 63 )
			goto tr480;
	} else
		goto tr480;
	goto tr478;
tr481:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st356;
st356:
	if ( ++p == pe )
		goto _test_eof356;
	/* fall through */
case 356:
#line 7112 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr483;
		case 95: goto tr483;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr483;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr484;
		} else if ( (*p) >= 65 )
			goto tr484;
	} else
		goto tr484;
	goto tr467;
tr483:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st357;
st357:
	if ( ++p == pe )
		goto _test_eof357;
	/* fall through */
case 357:
#line 7140 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto st357;
		case 95: goto st357;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st357;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr486;
		} else if ( (*p) >= 65 )
			goto tr486;
	} else
		goto tr486;
	goto tr467;
tr484:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st358;
tr486:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st358;
st358:
	if ( ++p == pe )
		goto _test_eof358;
	/* fall through */
case 358:
#line 7178 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr486;
		case 61: goto tr487;
		case 95: goto tr486;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr486;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr486;
		} else if ( (*p) >= 65 )
			goto tr486;
	} else
		goto tr486;
	goto tr467;
tr487:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st359;
st359:
	if ( ++p == pe )
		goto _test_eof359;
	/* fall through */
case 359:
#line 7207 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 34 )
		goto st362;
	if ( (*p) < 45 ) {
		if ( 32 <= (*p) && (*p) <= 43 )
			goto tr488;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr488;
	} else
		goto tr488;
	goto tr467;
tr488:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st360;
tr490:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st360;
st360:
	if ( ++p == pe )
		goto _test_eof360;
	/* fall through */
case 360:
#line 7240 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 44: goto tr481;
		case 62: goto tr482;
	}
	if ( (*p) > 33 ) {
		if ( 35 <= (*p) && (*p) <= 126 )
			goto tr490;
	} else if ( (*p) >= 32 )
		goto tr490;
	goto tr467;
tr482:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st361;
st361:
	if ( ++p == pe )
		goto _test_eof361;
	/* fall through */
case 361:
#line 7262 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
	}
	goto tr467;
st362:
	if ( ++p == pe )
		goto _test_eof362;
	/* fall through */
case 362:
	switch( (*p) ) {
		case 34: goto tr492;
		case 92: goto tr493;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr491;
	goto tr467;
tr491:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st363;
tr494:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st363;
st363:
	if ( ++p == pe )
		goto _test_eof363;
	/* fall through */
case 363:
#line 7301 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 34: goto tr495;
		case 92: goto tr496;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr494;
	goto tr467;
tr492:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st364;
tr495:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st364;
st364:
	if ( ++p == pe )
		goto _test_eof364;
	/* fall through */
case 364:
#line 7330 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 44: goto st356;
		case 62: goto st361;
	}
	goto tr467;
tr493:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st365;
tr496:
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
#line 7357 "inc/vcf/validator_detail_v45.hpp"
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr494;
	goto tr467;
tr39:
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
#line 7376 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 101: goto tr500;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr499;
tr500:
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
#line 7395 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 100: goto tr501;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr499;
tr501:
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
#line 7414 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 105: goto tr502;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr499;
tr502:
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
#line 7433 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 103: goto tr503;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr499;
tr503:
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
#line 7452 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 114: goto tr504;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr499;
tr504:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st371;
st371:
	if ( ++p == pe )
		goto _test_eof371;
	/* fall through */
case 371:
#line 7471 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 101: goto tr505;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr499;
tr505:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st372;
st372:
	if ( ++p == pe )
		goto _test_eof372;
	/* fall through */
case 372:
#line 7490 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 101: goto tr506;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr499;
tr506:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st373;
st373:
	if ( ++p == pe )
		goto _test_eof373;
	/* fall through */
case 373:
#line 7509 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 68: goto tr507;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr499;
tr507:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st374;
st374:
	if ( ++p == pe )
		goto _test_eof374;
	/* fall through */
case 374:
#line 7528 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 66: goto st375;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr499;
st375:
	if ( ++p == pe )
		goto _test_eof375;
	/* fall through */
case 375:
	if ( (*p) == 61 )
		goto tr509;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr499;
tr509:
#line 136 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "pedigreeDB");
    }
	goto st376;
st376:
	if ( ++p == pe )
		goto _test_eof376;
	/* fall through */
case 376:
#line 7557 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 60 )
		goto st377;
	goto tr499;
st377:
	if ( ++p == pe )
		goto _test_eof377;
	/* fall through */
case 377:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr512;
	} else if ( (*p) >= 65 )
		goto tr512;
	goto tr511;
tr512:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st378;
st378:
	if ( ++p == pe )
		goto _test_eof378;
	/* fall through */
case 378:
#line 7583 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 10: goto tr511;
		case 13: goto tr514;
		case 35: goto tr511;
		case 47: goto tr511;
		case 58: goto tr511;
		case 63: goto tr511;
	}
	goto st379;
tr514:
#line 43 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st379;
st379:
	if ( ++p == pe )
		goto _test_eof379;
	/* fall through */
case 379:
#line 7610 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 10: goto tr511;
		case 13: goto tr514;
		case 35: goto tr511;
		case 47: goto tr511;
		case 58: goto st380;
		case 63: goto tr511;
	}
	goto st379;
st380:
	if ( ++p == pe )
		goto _test_eof380;
	/* fall through */
case 380:
	if ( (*p) == 47 )
		goto st381;
	goto tr511;
st381:
	if ( ++p == pe )
		goto _test_eof381;
	/* fall through */
case 381:
	if ( (*p) == 47 )
		goto st382;
	goto tr511;
st382:
	if ( ++p == pe )
		goto _test_eof382;
	/* fall through */
case 382:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st383;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr519;
	} else
		goto tr519;
	goto tr511;
st383:
	if ( ++p == pe )
		goto _test_eof383;
	/* fall through */
case 383:
	if ( (*p) == 46 )
		goto st384;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st396;
	goto tr511;
st384:
	if ( ++p == pe )
		goto _test_eof384;
	/* fall through */
case 384:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st385;
	goto tr511;
st385:
	if ( ++p == pe )
		goto _test_eof385;
	/* fall through */
case 385:
	if ( (*p) == 46 )
		goto st386;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st394;
	goto tr511;
st386:
	if ( ++p == pe )
		goto _test_eof386;
	/* fall through */
case 386:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st387;
	goto tr511;
st387:
	if ( ++p == pe )
		goto _test_eof387;
	/* fall through */
case 387:
	if ( (*p) == 46 )
		goto st388;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st392;
	goto tr511;
st388:
	if ( ++p == pe )
		goto _test_eof388;
	/* fall through */
case 388:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr519;
	goto tr511;
tr519:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st389;
tr528:
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
	goto st389;
st389:
	if ( ++p == pe )
		goto _test_eof389;
	/* fall through */
case 389:
#line 7731 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 10: goto tr511;
		case 13: goto tr528;
		case 62: goto tr529;
	}
	goto tr519;
tr529:
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
#line 7753 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr530;
		case 62: goto tr529;
	}
	goto tr519;
tr530:
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
	goto st391;
st391:
	if ( ++p == pe )
		goto _test_eof391;
	/* fall through */
case 391:
#line 7789 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 10: goto st28;
		case 13: goto tr528;
		case 62: goto tr529;
	}
	goto tr519;
st392:
	if ( ++p == pe )
		goto _test_eof392;
	/* fall through */
case 392:
	if ( (*p) == 46 )
		goto st388;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st393;
	goto tr511;
st393:
	if ( ++p == pe )
		goto _test_eof393;
	/* fall through */
case 393:
	if ( (*p) == 46 )
		goto st388;
	goto tr511;
st394:
	if ( ++p == pe )
		goto _test_eof394;
	/* fall through */
case 394:
	if ( (*p) == 46 )
		goto st386;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st395;
	goto tr511;
st395:
	if ( ++p == pe )
		goto _test_eof395;
	/* fall through */
case 395:
	if ( (*p) == 46 )
		goto st386;
	goto tr511;
st396:
	if ( ++p == pe )
		goto _test_eof396;
	/* fall through */
case 396:
	if ( (*p) == 46 )
		goto st384;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st397;
	goto tr511;
st397:
	if ( ++p == pe )
		goto _test_eof397;
	/* fall through */
case 397:
	if ( (*p) == 46 )
		goto st384;
	goto tr511;
st398:
	if ( ++p == pe )
		goto _test_eof398;
	/* fall through */
case 398:
	if ( (*p) == 72 )
		goto st399;
	goto tr534;
st399:
	if ( ++p == pe )
		goto _test_eof399;
	/* fall through */
case 399:
	if ( (*p) == 82 )
		goto st400;
	goto tr534;
st400:
	if ( ++p == pe )
		goto _test_eof400;
	/* fall through */
case 400:
	if ( (*p) == 79 )
		goto st401;
	goto tr534;
st401:
	if ( ++p == pe )
		goto _test_eof401;
	/* fall through */
case 401:
	if ( (*p) == 77 )
		goto st402;
	goto tr534;
st402:
	if ( ++p == pe )
		goto _test_eof402;
	/* fall through */
case 402:
	if ( (*p) == 9 )
		goto tr539;
	goto tr534;
tr539:
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st403;
st403:
	if ( ++p == pe )
		goto _test_eof403;
	/* fall through */
case 403:
#line 7901 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 80 )
		goto st404;
	goto tr534;
st404:
	if ( ++p == pe )
		goto _test_eof404;
	/* fall through */
case 404:
	if ( (*p) == 79 )
		goto st405;
	goto tr534;
st405:
	if ( ++p == pe )
		goto _test_eof405;
	/* fall through */
case 405:
	if ( (*p) == 83 )
		goto st406;
	goto tr534;
st406:
	if ( ++p == pe )
		goto _test_eof406;
	/* fall through */
case 406:
	if ( (*p) == 9 )
		goto tr543;
	goto tr534;
tr543:
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st407;
st407:
	if ( ++p == pe )
		goto _test_eof407;
	/* fall through */
case 407:
#line 7940 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 73 )
		goto st408;
	goto tr534;
st408:
	if ( ++p == pe )
		goto _test_eof408;
	/* fall through */
case 408:
	if ( (*p) == 68 )
		goto st409;
	goto tr534;
st409:
	if ( ++p == pe )
		goto _test_eof409;
	/* fall through */
case 409:
	if ( (*p) == 9 )
		goto tr546;
	goto tr534;
tr546:
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st410;
st410:
	if ( ++p == pe )
		goto _test_eof410;
	/* fall through */
case 410:
#line 7971 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 82 )
		goto st411;
	goto tr534;
st411:
	if ( ++p == pe )
		goto _test_eof411;
	/* fall through */
case 411:
	if ( (*p) == 69 )
		goto st412;
	goto tr534;
st412:
	if ( ++p == pe )
		goto _test_eof412;
	/* fall through */
case 412:
	if ( (*p) == 70 )
		goto st413;
	goto tr534;
st413:
	if ( ++p == pe )
		goto _test_eof413;
	/* fall through */
case 413:
	if ( (*p) == 9 )
		goto tr550;
	goto tr534;
tr550:
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st414;
st414:
	if ( ++p == pe )
		goto _test_eof414;
	/* fall through */
case 414:
#line 8010 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 65 )
		goto st415;
	goto tr534;
st415:
	if ( ++p == pe )
		goto _test_eof415;
	/* fall through */
case 415:
	if ( (*p) == 76 )
		goto st416;
	goto tr534;
st416:
	if ( ++p == pe )
		goto _test_eof416;
	/* fall through */
case 416:
	if ( (*p) == 84 )
		goto st417;
	goto tr534;
st417:
	if ( ++p == pe )
		goto _test_eof417;
	/* fall through */
case 417:
	if ( (*p) == 9 )
		goto tr554;
	goto tr534;
tr554:
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st418;
st418:
	if ( ++p == pe )
		goto _test_eof418;
	/* fall through */
case 418:
#line 8049 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 81 )
		goto st419;
	goto tr534;
st419:
	if ( ++p == pe )
		goto _test_eof419;
	/* fall through */
case 419:
	if ( (*p) == 85 )
		goto st420;
	goto tr534;
st420:
	if ( ++p == pe )
		goto _test_eof420;
	/* fall through */
case 420:
	if ( (*p) == 65 )
		goto st421;
	goto tr534;
st421:
	if ( ++p == pe )
		goto _test_eof421;
	/* fall through */
case 421:
	if ( (*p) == 76 )
		goto st422;
	goto tr534;
st422:
	if ( ++p == pe )
		goto _test_eof422;
	/* fall through */
case 422:
	if ( (*p) == 9 )
		goto tr559;
	goto tr534;
tr559:
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st423;
st423:
	if ( ++p == pe )
		goto _test_eof423;
	/* fall through */
case 423:
#line 8096 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 70 )
		goto st424;
	goto tr534;
st424:
	if ( ++p == pe )
		goto _test_eof424;
	/* fall through */
case 424:
	if ( (*p) == 73 )
		goto st425;
	goto tr534;
st425:
	if ( ++p == pe )
		goto _test_eof425;
	/* fall through */
case 425:
	if ( (*p) == 76 )
		goto st426;
	goto tr534;
st426:
	if ( ++p == pe )
		goto _test_eof426;
	/* fall through */
case 426:
	if ( (*p) == 84 )
		goto st427;
	goto tr534;
st427:
	if ( ++p == pe )
		goto _test_eof427;
	/* fall through */
case 427:
	if ( (*p) == 69 )
		goto st428;
	goto tr534;
st428:
	if ( ++p == pe )
		goto _test_eof428;
	/* fall through */
case 428:
	if ( (*p) == 82 )
		goto st429;
	goto tr534;
st429:
	if ( ++p == pe )
		goto _test_eof429;
	/* fall through */
case 429:
	if ( (*p) == 9 )
		goto tr566;
	goto tr534;
tr566:
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st430;
st430:
	if ( ++p == pe )
		goto _test_eof430;
	/* fall through */
case 430:
#line 8159 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 73 )
		goto st431;
	goto tr534;
st431:
	if ( ++p == pe )
		goto _test_eof431;
	/* fall through */
case 431:
	if ( (*p) == 78 )
		goto st432;
	goto tr534;
st432:
	if ( ++p == pe )
		goto _test_eof432;
	/* fall through */
case 432:
	if ( (*p) == 70 )
		goto st433;
	goto tr534;
st433:
	if ( ++p == pe )
		goto _test_eof433;
	/* fall through */
case 433:
	if ( (*p) == 79 )
		goto st434;
	goto tr534;
st434:
	if ( ++p == pe )
		goto _test_eof434;
	/* fall through */
case 434:
	switch( (*p) ) {
		case 9: goto tr571;
		case 10: goto tr572;
		case 13: goto tr573;
	}
	goto tr534;
tr571:
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st435;
st435:
	if ( ++p == pe )
		goto _test_eof435;
	/* fall through */
case 435:
#line 8209 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 70 )
		goto st436;
	goto tr574;
st436:
	if ( ++p == pe )
		goto _test_eof436;
	/* fall through */
case 436:
	if ( (*p) == 79 )
		goto st437;
	goto tr574;
st437:
	if ( ++p == pe )
		goto _test_eof437;
	/* fall through */
case 437:
	if ( (*p) == 82 )
		goto st438;
	goto tr574;
st438:
	if ( ++p == pe )
		goto _test_eof438;
	/* fall through */
case 438:
	if ( (*p) == 77 )
		goto st439;
	goto tr574;
st439:
	if ( ++p == pe )
		goto _test_eof439;
	/* fall through */
case 439:
	if ( (*p) == 65 )
		goto st440;
	goto tr574;
st440:
	if ( ++p == pe )
		goto _test_eof440;
	/* fall through */
case 440:
	if ( (*p) == 84 )
		goto st441;
	goto tr574;
st441:
	if ( ++p == pe )
		goto _test_eof441;
	/* fall through */
case 441:
	if ( (*p) == 9 )
		goto tr581;
	goto tr574;
tr581:
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st442;
tr583:
#line 204 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_sample_name(*this);
    }
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st442;
st442:
	if ( ++p == pe )
		goto _test_eof442;
	/* fall through */
case 442:
#line 8282 "inc/vcf/validator_detail_v45.hpp"
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr582;
	goto tr574;
tr582:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st443;
tr586:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st443;
st443:
	if ( ++p == pe )
		goto _test_eof443;
	/* fall through */
case 443:
#line 8307 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 9: goto tr583;
		case 10: goto tr584;
		case 13: goto tr585;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr586;
	goto tr574;
tr572:
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
	goto st536;
tr584:
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
	goto st536;
st536:
	if ( ++p == pe )
		goto _test_eof536;
	/* fall through */
case 536:
#line 8365 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 10: goto tr717;
		case 13: goto tr718;
		case 43: goto tr719;
		case 60: goto tr720;
		case 92: goto tr719;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr719;
		} else if ( (*p) >= 33 )
			goto tr719;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr719;
		} else if ( (*p) >= 63 )
			goto tr719;
	} else
		goto tr719;
	goto tr716;
tr721:
#line 43 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st537;
tr717:
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
	goto st537;
st537:
	if ( ++p == pe )
		goto _test_eof537;
	/* fall through */
case 537:
#line 8425 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 10: goto tr721;
		case 13: goto tr722;
	}
	goto st0;
tr722:
#line 43 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st444;
tr718:
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
	goto st444;
st444:
	if ( ++p == pe )
		goto _test_eof444;
	/* fall through */
case 444:
#line 8468 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 10 )
		goto st537;
	goto st0;
tr728:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st445;
tr591:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st445;
tr719:
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
	goto st445;
st445:
	if ( ++p == pe )
		goto _test_eof445;
	/* fall through */
case 445:
#line 8511 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 9: goto tr590;
		case 43: goto tr591;
		case 92: goto tr591;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr591;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr591;
		} else if ( (*p) >= 63 )
			goto tr591;
	} else
		goto tr591;
	goto tr589;
tr590:
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
	goto st446;
tr649:
#line 218 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st446;
st446:
	if ( ++p == pe )
		goto _test_eof446;
	/* fall through */
case 446:
#line 8558 "inc/vcf/validator_detail_v45.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr593;
	goto tr592;
tr593:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st447;
tr595:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st447;
st447:
	if ( ++p == pe )
		goto _test_eof447;
	/* fall through */
case 447:
#line 8583 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 9 )
		goto tr594;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr595;
	goto tr592;
tr600:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st448;
tr594:
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
	goto st448;
st448:
	if ( ++p == pe )
		goto _test_eof448;
	/* fall through */
case 448:
#line 8614 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr597;
	} else if ( (*p) >= 33 )
		goto tr597;
	goto tr596;
tr597:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st449;
tr599:
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
#line 8642 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 9: goto tr598;
		case 59: goto tr600;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr599;
	goto tr596;
tr598:
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
	goto st450;
st450:
	if ( ++p == pe )
		goto _test_eof450;
	/* fall through */
case 450:
#line 8669 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 65: goto tr602;
		case 67: goto tr602;
		case 71: goto tr602;
		case 78: goto tr602;
		case 84: goto tr602;
		case 97: goto tr602;
		case 99: goto tr602;
		case 103: goto tr602;
		case 110: goto tr602;
		case 116: goto tr602;
	}
	goto tr601;
tr602:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st451;
tr604:
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
#line 8704 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 9: goto tr603;
		case 65: goto tr604;
		case 67: goto tr604;
		case 71: goto tr604;
		case 78: goto tr604;
		case 84: goto tr604;
		case 97: goto tr604;
		case 99: goto tr604;
		case 103: goto tr604;
		case 110: goto tr604;
		case 116: goto tr604;
	}
	goto tr601;
tr603:
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
	goto st452;
st452:
	if ( ++p == pe )
		goto _test_eof452;
	/* fall through */
case 452:
#line 8738 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 42: goto tr606;
		case 46: goto tr607;
		case 60: goto tr608;
		case 65: goto tr609;
		case 67: goto tr609;
		case 71: goto tr609;
		case 78: goto tr609;
		case 84: goto tr609;
		case 91: goto tr610;
		case 93: goto tr611;
		case 97: goto tr609;
		case 99: goto tr609;
		case 103: goto tr609;
		case 110: goto tr609;
		case 116: goto tr609;
	}
	goto tr605;
tr606:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st453;
tr671:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st453;
st453:
	if ( ++p == pe )
		goto _test_eof453;
	/* fall through */
case 453:
#line 8778 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 9: goto tr612;
		case 44: goto tr613;
	}
	goto tr605;
tr612:
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
	goto st454;
st454:
	if ( ++p == pe )
		goto _test_eof454;
	/* fall through */
case 454:
#line 8803 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr615;
		case 45: goto tr615;
		case 46: goto tr616;
		case 73: goto tr618;
		case 78: goto tr619;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr617;
	goto tr614;
tr615:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st455;
st455:
	if ( ++p == pe )
		goto _test_eof455;
	/* fall through */
case 455:
#line 8829 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 73 )
		goto tr621;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr620;
	goto tr614;
tr617:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st456;
tr620:
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
#line 8856 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 9: goto tr622;
		case 46: goto tr623;
		case 69: goto tr624;
		case 101: goto tr624;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr620;
	goto tr614;
tr622:
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
	goto st457;
st457:
	if ( ++p == pe )
		goto _test_eof457;
	/* fall through */
case 457:
#line 8885 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 46: goto tr627;
		case 58: goto tr626;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr626;
		} else if ( (*p) > 57 ) {
			if ( 60 <= (*p) && (*p) <= 64 )
				goto tr626;
		} else
			goto tr628;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr626;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr626;
		} else
			goto tr628;
	} else
		goto tr628;
	goto tr625;
tr626:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st458;
st458:
	if ( ++p == pe )
		goto _test_eof458;
	/* fall through */
case 458:
#line 8922 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 58 )
		goto st458;
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto st458;
		} else if ( (*p) > 57 ) {
			if ( 60 <= (*p) && (*p) <= 64 )
				goto st458;
		} else
			goto tr630;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st458;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st458;
		} else
			goto tr630;
	} else
		goto tr630;
	goto tr625;
tr628:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st459;
tr630:
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
#line 8967 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 9: goto tr631;
		case 59: goto tr632;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr630;
	goto tr625;
tr631:
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
	goto st460;
st460:
	if ( ++p == pe )
		goto _test_eof460;
	/* fall through */
case 460:
#line 8994 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 46: goto tr634;
		case 49: goto tr635;
		case 95: goto tr636;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr636;
	} else if ( (*p) >= 65 )
		goto tr636;
	goto tr633;
tr634:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st538;
st538:
	if ( ++p == pe )
		goto _test_eof538;
	/* fall through */
case 538:
#line 9021 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 9: goto tr724;
		case 10: goto tr725;
		case 13: goto tr726;
	}
	goto tr723;
tr641:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st461;
tr724:
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
	goto st461;
st461:
	if ( ++p == pe )
		goto _test_eof461;
	/* fall through */
case 461:
#line 9053 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 95 )
		goto tr638;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr638;
	} else if ( (*p) >= 65 )
		goto tr638;
	goto tr637;
tr638:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st462;
tr640:
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
#line 9083 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 9: goto tr639;
		case 37: goto tr640;
		case 46: goto tr640;
		case 58: goto tr641;
		case 95: goto tr640;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr640;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr640;
	} else
		goto tr640;
	goto tr637;
tr639:
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
	goto st463;
st463:
	if ( ++p == pe )
		goto _test_eof463;
	/* fall through */
case 463:
#line 9119 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 46 )
		goto tr644;
	if ( (*p) < 48 ) {
		if ( 33 <= (*p) && (*p) <= 47 )
			goto tr643;
	} else if ( (*p) > 57 ) {
		if ( 59 <= (*p) && (*p) <= 126 )
			goto tr643;
	} else
		goto tr645;
	goto tr642;
tr643:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st539;
tr653:
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
#line 9152 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 9: goto tr639;
		case 10: goto tr725;
		case 13: goto tr726;
		case 58: goto tr727;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr653;
	goto tr652;
tr725:
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
	goto st540;
st540:
	if ( ++p == pe )
		goto _test_eof540;
	/* fall through */
case 540:
#line 9220 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 10: goto tr721;
		case 13: goto tr722;
		case 43: goto tr728;
		case 60: goto st464;
		case 92: goto tr728;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr728;
		} else if ( (*p) >= 33 )
			goto tr728;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr728;
		} else if ( (*p) >= 63 )
			goto tr728;
	} else
		goto tr728;
	goto tr589;
tr720:
#line 70 "src/vcf/vcf.ragel"
	{
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (Error *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
    }
	goto st464;
st464:
	if ( ++p == pe )
		goto _test_eof464;
	/* fall through */
case 464:
#line 9258 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr646;
		case 92: goto tr646;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr646;
		} else if ( (*p) >= 33 )
			goto tr646;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr646;
		} else if ( (*p) >= 63 )
			goto tr646;
	} else
		goto tr646;
	goto tr589;
tr646:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st465;
tr647:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st465;
st465:
	if ( ++p == pe )
		goto _test_eof465;
	/* fall through */
case 465:
#line 9299 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr647;
		case 62: goto tr648;
		case 92: goto tr647;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr647;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr647;
		} else if ( (*p) >= 63 )
			goto tr647;
	} else
		goto tr647;
	goto tr589;
tr648:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st466;
st466:
	if ( ++p == pe )
		goto _test_eof466;
	/* fall through */
case 466:
#line 9328 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 9 )
		goto tr649;
	goto tr589;
tr726:
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
	goto st467;
st467:
	if ( ++p == pe )
		goto _test_eof467;
	/* fall through */
case 467:
#line 9390 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 10 )
		goto st540;
	goto tr650;
tr727:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st468;
st468:
	if ( ++p == pe )
		goto _test_eof468;
	/* fall through */
case 468:
#line 9405 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) > 57 ) {
		if ( 59 <= (*p) && (*p) <= 126 )
			goto tr653;
	} else if ( (*p) >= 33 )
		goto tr653;
	goto tr652;
tr644:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st541;
tr731:
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
#line 9433 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 9: goto tr639;
		case 10: goto tr725;
		case 13: goto tr726;
		case 47: goto tr730;
		case 58: goto tr727;
		case 124: goto tr730;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr653;
	goto tr642;
tr730:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st542;
st542:
	if ( ++p == pe )
		goto _test_eof542;
	/* fall through */
case 542:
#line 9456 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 9: goto tr639;
		case 10: goto tr725;
		case 13: goto tr726;
		case 46: goto tr731;
		case 58: goto tr727;
	}
	if ( (*p) < 48 ) {
		if ( 33 <= (*p) && (*p) <= 47 )
			goto tr653;
	} else if ( (*p) > 57 ) {
		if ( 59 <= (*p) && (*p) <= 126 )
			goto tr653;
	} else
		goto tr732;
	goto tr642;
tr645:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st543;
tr732:
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
#line 9494 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 9: goto tr639;
		case 10: goto tr725;
		case 13: goto tr726;
		case 47: goto tr730;
		case 58: goto tr727;
		case 124: goto tr730;
	}
	if ( (*p) < 48 ) {
		if ( 33 <= (*p) && (*p) <= 46 )
			goto tr653;
	} else if ( (*p) > 57 ) {
		if ( 59 <= (*p) && (*p) <= 126 )
			goto tr653;
	} else
		goto tr732;
	goto tr642;
tr635:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st469;
st469:
	if ( ++p == pe )
		goto _test_eof469;
	/* fall through */
case 469:
#line 9527 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 48 )
		goto tr654;
	goto tr633;
tr654:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st470;
st470:
	if ( ++p == pe )
		goto _test_eof470;
	/* fall through */
case 470:
#line 9542 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 48 )
		goto tr655;
	goto tr633;
tr655:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st471;
st471:
	if ( ++p == pe )
		goto _test_eof471;
	/* fall through */
case 471:
#line 9557 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 48 )
		goto tr656;
	goto tr633;
tr656:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st472;
st472:
	if ( ++p == pe )
		goto _test_eof472;
	/* fall through */
case 472:
#line 9572 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 71 )
		goto tr657;
	goto tr633;
tr657:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st544;
st544:
	if ( ++p == pe )
		goto _test_eof544;
	/* fall through */
case 544:
#line 9587 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 9: goto tr724;
		case 10: goto tr725;
		case 13: goto tr726;
		case 59: goto tr733;
		case 61: goto tr734;
	}
	goto tr633;
tr733:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st473;
st473:
	if ( ++p == pe )
		goto _test_eof473;
	/* fall through */
case 473:
#line 9607 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 49: goto tr635;
		case 95: goto tr636;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr636;
	} else if ( (*p) >= 65 )
		goto tr636;
	goto tr633;
tr636:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st545;
tr735:
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
#line 9639 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 9: goto tr724;
		case 10: goto tr725;
		case 13: goto tr726;
		case 46: goto tr735;
		case 59: goto tr733;
		case 61: goto tr734;
		case 95: goto tr735;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr735;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr735;
	} else
		goto tr735;
	goto tr633;
tr734:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st474;
st474:
	if ( ++p == pe )
		goto _test_eof474;
	/* fall through */
case 474:
#line 9669 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr659;
	} else if ( (*p) >= 32 )
		goto tr659;
	goto tr658;
tr659:
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
#line 9687 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 9: goto tr724;
		case 10: goto tr725;
		case 13: goto tr726;
		case 59: goto tr733;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr659;
	goto tr658;
tr632:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st475;
st475:
	if ( ++p == pe )
		goto _test_eof475;
	/* fall through */
case 475:
#line 9708 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 58 )
		goto tr626;
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr626;
		} else if ( (*p) > 57 ) {
			if ( 60 <= (*p) && (*p) <= 64 )
				goto tr626;
		} else
			goto tr628;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr626;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr626;
		} else
			goto tr628;
	} else
		goto tr628;
	goto tr625;
tr627:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st476;
st476:
	if ( ++p == pe )
		goto _test_eof476;
	/* fall through */
case 476:
#line 9747 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 9: goto tr631;
		case 58: goto st458;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto st458;
		} else if ( (*p) > 57 ) {
			if ( 60 <= (*p) && (*p) <= 64 )
				goto st458;
		} else
			goto tr630;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st458;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st458;
		} else
			goto tr630;
	} else
		goto tr630;
	goto tr625;
tr623:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st477;
st477:
	if ( ++p == pe )
		goto _test_eof477;
	/* fall through */
case 477:
#line 9784 "inc/vcf/validator_detail_v45.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr660;
	goto tr614;
tr660:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st478;
st478:
	if ( ++p == pe )
		goto _test_eof478;
	/* fall through */
case 478:
#line 9799 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 9: goto tr622;
		case 69: goto tr624;
		case 101: goto tr624;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr660;
	goto tr614;
tr624:
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
#line 9819 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr661;
		case 45: goto tr661;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr662;
	goto tr614;
tr661:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st480;
st480:
	if ( ++p == pe )
		goto _test_eof480;
	/* fall through */
case 480:
#line 9838 "inc/vcf/validator_detail_v45.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr662;
	goto tr614;
tr662:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st481;
st481:
	if ( ++p == pe )
		goto _test_eof481;
	/* fall through */
case 481:
#line 9853 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 9 )
		goto tr622;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr662;
	goto tr614;
tr618:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st482;
tr621:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st482;
st482:
	if ( ++p == pe )
		goto _test_eof482;
	/* fall through */
case 482:
#line 9880 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 110 )
		goto tr663;
	goto tr614;
tr663:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st483;
st483:
	if ( ++p == pe )
		goto _test_eof483;
	/* fall through */
case 483:
#line 9895 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 102 )
		goto tr664;
	goto tr614;
tr616:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st484;
tr664:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st484;
st484:
	if ( ++p == pe )
		goto _test_eof484;
	/* fall through */
case 484:
#line 9920 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 9 )
		goto tr622;
	goto tr614;
tr619:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st485;
st485:
	if ( ++p == pe )
		goto _test_eof485;
	/* fall through */
case 485:
#line 9939 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 97 )
		goto tr665;
	goto tr614;
tr665:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st486;
st486:
	if ( ++p == pe )
		goto _test_eof486;
	/* fall through */
case 486:
#line 9954 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 78 )
		goto tr664;
	goto tr614;
tr613:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st487;
st487:
	if ( ++p == pe )
		goto _test_eof487;
	/* fall through */
case 487:
#line 9969 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 42: goto tr606;
		case 46: goto tr666;
		case 60: goto tr608;
		case 65: goto tr609;
		case 67: goto tr609;
		case 71: goto tr609;
		case 78: goto tr609;
		case 84: goto tr609;
		case 91: goto tr610;
		case 93: goto tr611;
		case 97: goto tr609;
		case 99: goto tr609;
		case 103: goto tr609;
		case 110: goto tr609;
		case 116: goto tr609;
	}
	goto tr605;
tr666:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st488;
tr695:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st488;
st488:
	if ( ++p == pe )
		goto _test_eof488;
	/* fall through */
case 488:
#line 10009 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 65: goto tr667;
		case 67: goto tr667;
		case 71: goto tr667;
		case 78: goto tr667;
		case 84: goto tr667;
		case 97: goto tr667;
		case 99: goto tr667;
		case 103: goto tr667;
		case 110: goto tr667;
		case 116: goto tr667;
	}
	goto tr605;
tr667:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st489;
st489:
	if ( ++p == pe )
		goto _test_eof489;
	/* fall through */
case 489:
#line 10034 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 9: goto tr612;
		case 44: goto tr613;
		case 65: goto tr667;
		case 67: goto tr667;
		case 71: goto tr667;
		case 78: goto tr667;
		case 84: goto tr667;
		case 97: goto tr667;
		case 99: goto tr667;
		case 103: goto tr667;
		case 110: goto tr667;
		case 116: goto tr667;
	}
	goto tr605;
tr608:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st490;
st490:
	if ( ++p == pe )
		goto _test_eof490;
	/* fall through */
case 490:
#line 10065 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 42: goto tr669;
		case 61: goto tr668;
	}
	if ( (*p) < 63 ) {
		if ( (*p) < 45 ) {
			if ( 33 <= (*p) && (*p) <= 43 )
				goto tr668;
		} else if ( (*p) > 47 ) {
			if ( (*p) > 57 ) {
				if ( 58 <= (*p) && (*p) <= 59 )
					goto tr668;
			} else if ( (*p) >= 48 )
				goto tr670;
		} else
			goto tr668;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr670;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr668;
			} else if ( (*p) >= 97 )
				goto tr670;
		} else
			goto tr668;
	} else
		goto tr668;
	goto tr605;
tr668:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st491;
st491:
	if ( ++p == pe )
		goto _test_eof491;
	/* fall through */
case 491:
#line 10108 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 61 )
		goto tr668;
	if ( (*p) < 63 ) {
		if ( (*p) < 45 ) {
			if ( 33 <= (*p) && (*p) <= 43 )
				goto tr668;
		} else if ( (*p) > 47 ) {
			if ( (*p) > 57 ) {
				if ( 58 <= (*p) && (*p) <= 59 )
					goto tr668;
			} else if ( (*p) >= 48 )
				goto tr670;
		} else
			goto tr668;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr670;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr668;
			} else if ( (*p) >= 97 )
				goto tr670;
		} else
			goto tr668;
	} else
		goto tr668;
	goto tr605;
tr670:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st492;
st492:
	if ( ++p == pe )
		goto _test_eof492;
	/* fall through */
case 492:
#line 10149 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 62 )
		goto tr671;
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr670;
	} else if ( (*p) > 59 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr670;
	} else
		goto tr670;
	goto tr605;
tr669:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st493;
st493:
	if ( ++p == pe )
		goto _test_eof493;
	/* fall through */
case 493:
#line 10172 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 62 )
		goto tr671;
	if ( (*p) < 61 ) {
		if ( (*p) < 45 ) {
			if ( 33 <= (*p) && (*p) <= 43 )
				goto tr668;
		} else if ( (*p) > 47 ) {
			if ( (*p) > 57 ) {
				if ( 58 <= (*p) && (*p) <= 59 )
					goto tr668;
			} else if ( (*p) >= 48 )
				goto tr670;
		} else
			goto tr668;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr670;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr668;
			} else if ( (*p) >= 97 )
				goto tr670;
		} else
			goto tr668;
	} else
		goto tr668;
	goto tr605;
tr609:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st494;
tr672:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st494;
st494:
	if ( ++p == pe )
		goto _test_eof494;
	/* fall through */
case 494:
#line 10223 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 9: goto tr612;
		case 44: goto tr613;
		case 46: goto tr671;
		case 65: goto tr672;
		case 67: goto tr672;
		case 71: goto tr672;
		case 78: goto tr672;
		case 84: goto tr672;
		case 91: goto tr673;
		case 93: goto tr674;
		case 97: goto tr672;
		case 99: goto tr672;
		case 103: goto tr672;
		case 110: goto tr672;
		case 116: goto tr672;
	}
	goto tr605;
tr673:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st495;
st495:
	if ( ++p == pe )
		goto _test_eof495;
	/* fall through */
case 495:
#line 10253 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr675;
		case 60: goto tr676;
		case 92: goto tr675;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr675;
		} else if ( (*p) >= 33 )
			goto tr675;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr675;
		} else if ( (*p) >= 63 )
			goto tr675;
	} else
		goto tr675;
	goto tr605;
tr675:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st496;
st496:
	if ( ++p == pe )
		goto _test_eof496;
	/* fall through */
case 496:
#line 10285 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr675;
		case 58: goto tr677;
		case 92: goto tr675;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr675;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr675;
		} else if ( (*p) >= 63 )
			goto tr675;
	} else
		goto tr675;
	goto tr605;
tr677:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st497;
st497:
	if ( ++p == pe )
		goto _test_eof497;
	/* fall through */
case 497:
#line 10314 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr675;
		case 58: goto tr677;
		case 59: goto tr675;
		case 92: goto tr675;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 41 ) {
			if ( 45 <= (*p) && (*p) <= 47 )
				goto tr675;
		} else if ( (*p) >= 33 )
			goto tr675;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr675;
		} else if ( (*p) >= 63 )
			goto tr675;
	} else
		goto tr678;
	goto tr605;
tr678:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st498;
st498:
	if ( ++p == pe )
		goto _test_eof498;
	/* fall through */
case 498:
#line 10347 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr675;
		case 58: goto tr677;
		case 59: goto tr675;
		case 91: goto tr671;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 41 ) {
			if ( 45 <= (*p) && (*p) <= 47 )
				goto tr675;
		} else if ( (*p) >= 33 )
			goto tr675;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 92 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr675;
		} else if ( (*p) >= 63 )
			goto tr675;
	} else
		goto tr678;
	goto tr605;
tr676:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st499;
st499:
	if ( ++p == pe )
		goto _test_eof499;
	/* fall through */
case 499:
#line 10380 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr679;
		case 92: goto tr679;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr679;
		} else if ( (*p) >= 33 )
			goto tr679;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr679;
		} else if ( (*p) >= 63 )
			goto tr679;
	} else
		goto tr679;
	goto tr605;
tr679:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st500;
st500:
	if ( ++p == pe )
		goto _test_eof500;
	/* fall through */
case 500:
#line 10411 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr679;
		case 62: goto tr680;
		case 92: goto tr679;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr679;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr679;
		} else if ( (*p) >= 63 )
			goto tr679;
	} else
		goto tr679;
	goto tr605;
tr680:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st501;
st501:
	if ( ++p == pe )
		goto _test_eof501;
	/* fall through */
case 501:
#line 10440 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 58 )
		goto tr681;
	goto tr605;
tr681:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st502;
st502:
	if ( ++p == pe )
		goto _test_eof502;
	/* fall through */
case 502:
#line 10455 "inc/vcf/validator_detail_v45.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr682;
	goto tr605;
tr682:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st503;
st503:
	if ( ++p == pe )
		goto _test_eof503;
	/* fall through */
case 503:
#line 10470 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 91 )
		goto tr671;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr682;
	goto tr605;
tr674:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st504;
st504:
	if ( ++p == pe )
		goto _test_eof504;
	/* fall through */
case 504:
#line 10487 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr683;
		case 60: goto tr684;
		case 92: goto tr683;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr683;
		} else if ( (*p) >= 33 )
			goto tr683;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr683;
		} else if ( (*p) >= 63 )
			goto tr683;
	} else
		goto tr683;
	goto tr605;
tr683:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st505;
st505:
	if ( ++p == pe )
		goto _test_eof505;
	/* fall through */
case 505:
#line 10519 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr683;
		case 58: goto tr685;
		case 92: goto tr683;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr683;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr683;
		} else if ( (*p) >= 63 )
			goto tr683;
	} else
		goto tr683;
	goto tr605;
tr685:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st506;
st506:
	if ( ++p == pe )
		goto _test_eof506;
	/* fall through */
case 506:
#line 10548 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr683;
		case 58: goto tr685;
		case 59: goto tr683;
		case 92: goto tr683;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 41 ) {
			if ( 45 <= (*p) && (*p) <= 47 )
				goto tr683;
		} else if ( (*p) >= 33 )
			goto tr683;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr683;
		} else if ( (*p) >= 63 )
			goto tr683;
	} else
		goto tr686;
	goto tr605;
tr686:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st507;
st507:
	if ( ++p == pe )
		goto _test_eof507;
	/* fall through */
case 507:
#line 10581 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr683;
		case 58: goto tr685;
		case 59: goto tr683;
		case 93: goto tr671;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 41 ) {
			if ( 45 <= (*p) && (*p) <= 47 )
				goto tr683;
		} else if ( (*p) >= 33 )
			goto tr683;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 92 <= (*p) && (*p) <= 126 )
				goto tr683;
		} else if ( (*p) >= 63 )
			goto tr683;
	} else
		goto tr686;
	goto tr605;
tr684:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st508;
st508:
	if ( ++p == pe )
		goto _test_eof508;
	/* fall through */
case 508:
#line 10614 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr687;
		case 92: goto tr687;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr687;
		} else if ( (*p) >= 33 )
			goto tr687;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr687;
		} else if ( (*p) >= 63 )
			goto tr687;
	} else
		goto tr687;
	goto tr605;
tr687:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st509;
st509:
	if ( ++p == pe )
		goto _test_eof509;
	/* fall through */
case 509:
#line 10645 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr687;
		case 62: goto tr688;
		case 92: goto tr687;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr687;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr687;
		} else if ( (*p) >= 63 )
			goto tr687;
	} else
		goto tr687;
	goto tr605;
tr688:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st510;
st510:
	if ( ++p == pe )
		goto _test_eof510;
	/* fall through */
case 510:
#line 10674 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 58 )
		goto tr689;
	goto tr605;
tr689:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st511;
st511:
	if ( ++p == pe )
		goto _test_eof511;
	/* fall through */
case 511:
#line 10689 "inc/vcf/validator_detail_v45.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr690;
	goto tr605;
tr690:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st512;
st512:
	if ( ++p == pe )
		goto _test_eof512;
	/* fall through */
case 512:
#line 10704 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 93 )
		goto tr671;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr690;
	goto tr605;
tr610:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st513;
st513:
	if ( ++p == pe )
		goto _test_eof513;
	/* fall through */
case 513:
#line 10725 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr691;
		case 60: goto tr692;
		case 92: goto tr691;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr691;
		} else if ( (*p) >= 33 )
			goto tr691;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr691;
		} else if ( (*p) >= 63 )
			goto tr691;
	} else
		goto tr691;
	goto tr605;
tr691:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st514;
st514:
	if ( ++p == pe )
		goto _test_eof514;
	/* fall through */
case 514:
#line 10757 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr691;
		case 58: goto tr693;
		case 92: goto tr691;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr691;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr691;
		} else if ( (*p) >= 63 )
			goto tr691;
	} else
		goto tr691;
	goto tr605;
tr693:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st515;
st515:
	if ( ++p == pe )
		goto _test_eof515;
	/* fall through */
case 515:
#line 10786 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr691;
		case 58: goto tr693;
		case 59: goto tr691;
		case 92: goto tr691;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 41 ) {
			if ( 45 <= (*p) && (*p) <= 47 )
				goto tr691;
		} else if ( (*p) >= 33 )
			goto tr691;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr691;
		} else if ( (*p) >= 63 )
			goto tr691;
	} else
		goto tr694;
	goto tr605;
tr694:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st516;
st516:
	if ( ++p == pe )
		goto _test_eof516;
	/* fall through */
case 516:
#line 10819 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr691;
		case 58: goto tr693;
		case 59: goto tr691;
		case 91: goto tr695;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 41 ) {
			if ( 45 <= (*p) && (*p) <= 47 )
				goto tr691;
		} else if ( (*p) >= 33 )
			goto tr691;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 92 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr691;
		} else if ( (*p) >= 63 )
			goto tr691;
	} else
		goto tr694;
	goto tr605;
tr692:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st517;
st517:
	if ( ++p == pe )
		goto _test_eof517;
	/* fall through */
case 517:
#line 10852 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr696;
		case 92: goto tr696;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr696;
		} else if ( (*p) >= 33 )
			goto tr696;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr696;
		} else if ( (*p) >= 63 )
			goto tr696;
	} else
		goto tr696;
	goto tr605;
tr696:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st518;
st518:
	if ( ++p == pe )
		goto _test_eof518;
	/* fall through */
case 518:
#line 10883 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr696;
		case 62: goto tr697;
		case 92: goto tr696;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr696;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr696;
		} else if ( (*p) >= 63 )
			goto tr696;
	} else
		goto tr696;
	goto tr605;
tr697:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st519;
st519:
	if ( ++p == pe )
		goto _test_eof519;
	/* fall through */
case 519:
#line 10912 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 58 )
		goto tr698;
	goto tr605;
tr698:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st520;
st520:
	if ( ++p == pe )
		goto _test_eof520;
	/* fall through */
case 520:
#line 10927 "inc/vcf/validator_detail_v45.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr699;
	goto tr605;
tr699:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st521;
st521:
	if ( ++p == pe )
		goto _test_eof521;
	/* fall through */
case 521:
#line 10942 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 91 )
		goto tr695;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr699;
	goto tr605;
tr611:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st522;
st522:
	if ( ++p == pe )
		goto _test_eof522;
	/* fall through */
case 522:
#line 10963 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr700;
		case 60: goto tr701;
		case 92: goto tr700;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr700;
		} else if ( (*p) >= 33 )
			goto tr700;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr700;
		} else if ( (*p) >= 63 )
			goto tr700;
	} else
		goto tr700;
	goto tr605;
tr700:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st523;
st523:
	if ( ++p == pe )
		goto _test_eof523;
	/* fall through */
case 523:
#line 10995 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr700;
		case 58: goto tr702;
		case 92: goto tr700;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr700;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr700;
		} else if ( (*p) >= 63 )
			goto tr700;
	} else
		goto tr700;
	goto tr605;
tr702:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st524;
st524:
	if ( ++p == pe )
		goto _test_eof524;
	/* fall through */
case 524:
#line 11024 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr700;
		case 58: goto tr702;
		case 59: goto tr700;
		case 92: goto tr700;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 41 ) {
			if ( 45 <= (*p) && (*p) <= 47 )
				goto tr700;
		} else if ( (*p) >= 33 )
			goto tr700;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr700;
		} else if ( (*p) >= 63 )
			goto tr700;
	} else
		goto tr703;
	goto tr605;
tr703:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st525;
st525:
	if ( ++p == pe )
		goto _test_eof525;
	/* fall through */
case 525:
#line 11057 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr700;
		case 58: goto tr702;
		case 59: goto tr700;
		case 93: goto tr695;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 41 ) {
			if ( 45 <= (*p) && (*p) <= 47 )
				goto tr700;
		} else if ( (*p) >= 33 )
			goto tr700;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 92 <= (*p) && (*p) <= 126 )
				goto tr700;
		} else if ( (*p) >= 63 )
			goto tr700;
	} else
		goto tr703;
	goto tr605;
tr701:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st526;
st526:
	if ( ++p == pe )
		goto _test_eof526;
	/* fall through */
case 526:
#line 11090 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr704;
		case 92: goto tr704;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr704;
		} else if ( (*p) >= 33 )
			goto tr704;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr704;
		} else if ( (*p) >= 63 )
			goto tr704;
	} else
		goto tr704;
	goto tr605;
tr704:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st527;
st527:
	if ( ++p == pe )
		goto _test_eof527;
	/* fall through */
case 527:
#line 11121 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 43: goto tr704;
		case 62: goto tr705;
		case 92: goto tr704;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr704;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr704;
		} else if ( (*p) >= 63 )
			goto tr704;
	} else
		goto tr704;
	goto tr605;
tr705:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st528;
st528:
	if ( ++p == pe )
		goto _test_eof528;
	/* fall through */
case 528:
#line 11150 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 58 )
		goto tr706;
	goto tr605;
tr706:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st529;
st529:
	if ( ++p == pe )
		goto _test_eof529;
	/* fall through */
case 529:
#line 11165 "inc/vcf/validator_detail_v45.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr707;
	goto tr605;
tr707:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st530;
st530:
	if ( ++p == pe )
		goto _test_eof530;
	/* fall through */
case 530:
#line 11180 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 93 )
		goto tr695;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr707;
	goto tr605;
tr607:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st531;
st531:
	if ( ++p == pe )
		goto _test_eof531;
	/* fall through */
case 531:
#line 11201 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 9: goto tr612;
		case 65: goto tr667;
		case 67: goto tr667;
		case 71: goto tr667;
		case 78: goto tr667;
		case 84: goto tr667;
		case 97: goto tr667;
		case 99: goto tr667;
		case 103: goto tr667;
		case 110: goto tr667;
		case 116: goto tr667;
	}
	goto tr605;
tr573:
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
	goto st532;
tr585:
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
	goto st532;
st532:
	if ( ++p == pe )
		goto _test_eof532;
	/* fall through */
case 532:
#line 11265 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 10 )
		goto st536;
	goto tr574;
tr23:
#line 99 "src/vcf/vcf.ragel"
	{
        try {
          ParsePolicy::handle_fileformat(*this);
        } catch (Error *error) {
          ErrorPolicy::handle_error(*this, error);
          p--; {goto st534;}
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
	goto st533;
st533:
	if ( ++p == pe )
		goto _test_eof533;
	/* fall through */
case 533:
#line 11295 "inc/vcf/validator_detail_v45.hpp"
	if ( (*p) == 10 )
		goto st22;
	goto tr0;
tr712:
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
#line 11316 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 10: goto tr711;
		case 13: goto tr712;
	}
	goto st534;
tr711:
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
	goto st547;
st547:
	if ( ++p == pe )
		goto _test_eof547;
	/* fall through */
case 547:
#line 11341 "inc/vcf/validator_detail_v45.hpp"
	goto st0;
tr715:
#line 43 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st535;
st535:
	if ( ++p == pe )
		goto _test_eof535;
	/* fall through */
case 535:
#line 11360 "inc/vcf/validator_detail_v45.hpp"
	switch( (*p) ) {
		case 10: goto tr714;
		case 13: goto tr715;
	}
	goto st535;
tr714:
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
	{ {goto st540;} }
	goto st548;
st548:
	if ( ++p == pe )
		goto _test_eof548;
	/* fall through */
case 548:
#line 11385 "inc/vcf/validator_detail_v45.hpp"
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
	_test_eof536: cs = 536; goto _test_eof; 
	_test_eof537: cs = 537; goto _test_eof; 
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
	_test_eof538: cs = 538; goto _test_eof; 
	_test_eof461: cs = 461; goto _test_eof; 
	_test_eof462: cs = 462; goto _test_eof; 
	_test_eof463: cs = 463; goto _test_eof; 
	_test_eof539: cs = 539; goto _test_eof; 
	_test_eof540: cs = 540; goto _test_eof; 
	_test_eof464: cs = 464; goto _test_eof; 
	_test_eof465: cs = 465; goto _test_eof; 
	_test_eof466: cs = 466; goto _test_eof; 
	_test_eof467: cs = 467; goto _test_eof; 
	_test_eof468: cs = 468; goto _test_eof; 
	_test_eof541: cs = 541; goto _test_eof; 
	_test_eof542: cs = 542; goto _test_eof; 
	_test_eof543: cs = 543; goto _test_eof; 
	_test_eof469: cs = 469; goto _test_eof; 
	_test_eof470: cs = 470; goto _test_eof; 
	_test_eof471: cs = 471; goto _test_eof; 
	_test_eof472: cs = 472; goto _test_eof; 
	_test_eof544: cs = 544; goto _test_eof; 
	_test_eof473: cs = 473; goto _test_eof; 
	_test_eof545: cs = 545; goto _test_eof; 
	_test_eof474: cs = 474; goto _test_eof; 
	_test_eof546: cs = 546; goto _test_eof; 
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
	_test_eof547: cs = 547; goto _test_eof; 
	_test_eof535: cs = 535; goto _test_eof; 
	_test_eof548: cs = 548; goto _test_eof; 

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
	case 533: 
#line 60 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new FileformatError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
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
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
	break;
	case 536: 
#line 70 "src/vcf/vcf.ragel"
	{
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (Error *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
    }
	break;
	case 532: 
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
               goto _test_eof535;
goto st535;}
    }
	break;
	case 467: 
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof535;
goto st535;}
    }
	break;
	case 48: 
	case 49: 
	case 50: 
	case 51: 
	case 52: 
	case 53: 
	case 54: 
	case 61: 
	case 65: 
	case 66: 
#line 259 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
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
#line 271 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in assembly metadata"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
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
	case 353: 
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
#line 277 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in contig metadata"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
	break;
	case 68: 
	case 69: 
	case 70: 
	case 71: 
	case 72: 
	case 73: 
	case 74: 
	case 75: 
	case 76: 
	case 83: 
	case 87: 
	case 88: 
#line 283 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
	break;
	case 89: 
	case 90: 
	case 91: 
	case 92: 
	case 93: 
	case 94: 
	case 95: 
	case 96: 
	case 97: 
	case 101: 
	case 102: 
	case 103: 
	case 104: 
	case 105: 
	case 106: 
	case 107: 
	case 110: 
	case 111: 
	case 112: 
	case 113: 
	case 114: 
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
	case 129: 
	case 136: 
	case 137: 
	case 138: 
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
	break;
	case 141: 
	case 142: 
	case 143: 
	case 144: 
	case 145: 
	case 146: 
	case 147: 
	case 148: 
	case 152: 
	case 153: 
	case 154: 
	case 155: 
	case 156: 
	case 157: 
	case 158: 
	case 161: 
	case 162: 
	case 163: 
	case 164: 
	case 165: 
	case 168: 
	case 169: 
	case 170: 
	case 171: 
	case 172: 
	case 173: 
	case 174: 
	case 175: 
	case 176: 
	case 177: 
	case 178: 
	case 179: 
	case 180: 
	case 187: 
	case 188: 
	case 189: 
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
	break;
	case 237: 
	case 238: 
	case 239: 
	case 240: 
	case 241: 
	case 242: 
	case 243: 
	case 244: 
	case 245: 
	case 246: 
	case 247: 
	case 248: 
	case 253: 
	case 254: 
	case 255: 
	case 256: 
	case 257: 
	case 258: 
	case 262: 
	case 263: 
	case 264: 
	case 265: 
	case 266: 
	case 267: 
	case 268: 
	case 272: 
	case 283: 
	case 284: 
	case 285: 
	case 286: 
	case 287: 
	case 288: 
	case 289: 
	case 290: 
#line 311 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
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
	case 376: 
#line 332 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in pedigreeDB metadata"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
	break;
	case 191: 
	case 192: 
	case 193: 
	case 194: 
	case 195: 
	case 196: 
	case 197: 
	case 198: 
	case 202: 
	case 203: 
	case 204: 
	case 205: 
	case 206: 
	case 207: 
	case 208: 
	case 211: 
	case 212: 
	case 213: 
	case 214: 
	case 215: 
	case 223: 
	case 224: 
	case 225: 
	case 226: 
	case 227: 
	case 228: 
	case 229: 
	case 230: 
	case 231: 
	case 233: 
	case 234: 
	case 236: 
#line 338 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
	break;
	case 294: 
	case 295: 
	case 296: 
	case 297: 
	case 298: 
	case 299: 
	case 300: 
	case 301: 
	case 302: 
	case 303: 
	case 307: 
	case 308: 
	case 309: 
	case 310: 
	case 311: 
	case 312: 
	case 313: 
	case 314: 
	case 315: 
	case 316: 
#line 359 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
	break;
	case 445: 
	case 464: 
	case 465: 
	case 466: 
#line 408 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new ChromosomeBodyError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof535;
goto st535;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof535;
goto st535;}
    }
	break;
	case 446: 
	case 447: 
#line 414 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new PositionBodyError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof535;
goto st535;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof535;
goto st535;}
    }
	break;
	case 448: 
	case 449: 
#line 420 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new IdBodyError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof535;
goto st535;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof535;
goto st535;}
    }
	break;
	case 450: 
	case 451: 
#line 426 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new ReferenceAlleleBodyError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof535;
goto st535;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof535;
goto st535;}
    }
	break;
	case 452: 
	case 453: 
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
	case 525: 
	case 526: 
	case 527: 
	case 528: 
	case 529: 
	case 530: 
	case 531: 
#line 432 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new AlternateAllelesBodyError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof535;
goto st535;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof535;
goto st535;}
    }
	break;
	case 454: 
	case 455: 
	case 456: 
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
#line 438 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new QualityBodyError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof535;
goto st535;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof535;
goto st535;}
    }
	break;
	case 457: 
	case 458: 
	case 459: 
	case 475: 
	case 476: 
#line 444 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new FilterBodyError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof535;
goto st535;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof535;
goto st535;}
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
               goto _test_eof534;
goto st534;}
    }
#line 60 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new FileformatError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
	break;
	case 461: 
	case 462: 
#line 50 "src/vcf/vcf_v45.ragel"
	{
        ErrorPolicy::handle_error(*this, new FormatBodyError{n_lines, "Format does not start with a letter/underscore followed by alphanumeric/underscore/dot characters"});
        p--; {       if ( p == pe )
               goto _test_eof535;
goto st535;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof535;
goto st535;}
    }
	break;
	case 435: 
	case 436: 
	case 437: 
	case 438: 
	case 439: 
	case 440: 
	case 441: 
	case 442: 
	case 443: 
#line 55 "src/vcf/vcf_v45.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {       if ( p == pe )
               goto _test_eof535;
goto st535;}
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
               goto _test_eof535;
goto st535;}
    }
	break;
	case 55: 
	case 56: 
	case 57: 
#line 264 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines,
               "ALT metadata ID is not prefixed by DEL/INS/DUP/INV/CNV" + (source->version < Version::v44 ? std::string("/BND") : std::string("")) + " and suffixed by ':' and a text sequence"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 259 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
	break;
	case 67: 
#line 283 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
	break;
	case 115: 
	case 116: 
#line 305 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "INFO metadata Type is not Integer, Float, Flag, Character or String"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
	break;
	case 166: 
	case 167: 
#line 305 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "INFO metadata Type is not Integer, Float, Flag, Character or String"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
	break;
	case 291: 
	case 292: 
	case 293: 
#line 316 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "PEDIGREE metadata Original is not valid"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 311 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
	break;
	case 259: 
	case 260: 
	case 261: 
	case 269: 
	case 270: 
	case 271: 
#line 321 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "PEDIGREE metadata Father or Mother is not valid"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 311 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
	break;
	case 252: 
	case 273: 
	case 274: 
	case 275: 
	case 276: 
	case 277: 
	case 278: 
	case 279: 
	case 280: 
	case 281: 
	case 282: 
#line 326 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "PEDIGREE metadata sequence of Name_N is not valid"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 311 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
	break;
	case 209: 
	case 210: 
#line 343 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "META metadata Number is not a dot"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 338 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
	break;
	case 216: 
	case 217: 
	case 218: 
	case 219: 
	case 220: 
	case 221: 
	case 222: 
#line 348 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "META metadata Type is not String"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 338 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
	break;
	case 232: 
	case 235: 
#line 353 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "META metadata Values is not a square-bracket delimited list of values"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 338 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
	break;
	case 58: 
	case 59: 
	case 60: 
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 259 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
	break;
	case 354: 
	case 355: 
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 277 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in contig metadata"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
	break;
	case 77: 
	case 78: 
	case 79: 
	case 80: 
	case 81: 
	case 82: 
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 283 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
	break;
	case 98: 
	case 99: 
	case 100: 
	case 133: 
	case 134: 
	case 135: 
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
	break;
	case 149: 
	case 150: 
	case 151: 
	case 184: 
	case 185: 
	case 186: 
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
	break;
	case 249: 
	case 250: 
	case 251: 
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 311 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
	break;
	case 199: 
	case 200: 
	case 201: 
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 338 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
	break;
	case 304: 
	case 305: 
	case 306: 
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 359 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
	break;
	case 62: 
	case 63: 
	case 64: 
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 259 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
	break;
	case 84: 
	case 85: 
	case 86: 
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 283 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
	break;
	case 130: 
	case 131: 
	case 132: 
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
	break;
	case 181: 
	case 182: 
	case 183: 
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
	break;
	case 325: 
	case 326: 
	case 327: 
	case 328: 
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
	case 339: 
	case 340: 
	case 341: 
	case 342: 
	case 343: 
#line 385 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata URL is not valid"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 271 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in assembly metadata"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
	break;
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
#line 385 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata URL is not valid"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 332 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in pedigreeDB metadata"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
	break;
	case 108: 
	case 109: 
	case 139: 
	case 140: 
#line 36 "src/vcf/vcf_v45.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "FORMAT metadata Number is not a number, A, R, G, P, LA, LR, LG, M or dot"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
	break;
	case 159: 
	case 160: 
	case 190: 
#line 42 "src/vcf/vcf_v45.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "INFO metadata Number is not a number, A, R, G or dot"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
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
	case 428: 
	case 429: 
	case 430: 
	case 431: 
	case 432: 
	case 433: 
	case 434: 
#line 55 "src/vcf/vcf_v45.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {       if ( p == pe )
               goto _test_eof535;
goto st535;}
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
               goto _test_eof535;
goto st535;}
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
               goto _test_eof535;
goto st535;}
    }
	break;
	case 468: 
#line 55 "src/vcf/vcf_v45.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {       if ( p == pe )
               goto _test_eof535;
goto st535;}
    }
#line 466 "src/vcf/vcf.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " is not a valid string";
        ErrorPolicy::handle_error(*this, new SamplesBodyError{n_lines, message_stream.str()});
        p--; {       if ( p == pe )
               goto _test_eof535;
goto st535;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof535;
goto st535;}
    }
	break;
	case 538: 
	case 539: 
	case 544: 
	case 545: 
	case 546: 
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
               goto _test_eof535;
goto st535;}
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
               goto _test_eof534;
goto st534;}
    }
#line 55 "src/vcf/vcf_v45.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {       if ( p == pe )
               goto _test_eof535;
goto st535;}
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
               goto _test_eof535;
goto st535;}
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
               goto _test_eof535;
goto st535;}
    }
	break;
	case 460: 
	case 469: 
	case 470: 
	case 471: 
	case 472: 
	case 473: 
#line 455 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info key is not a sequence of alphanumeric and/or punctuation characters"});
        p--; {       if ( p == pe )
               goto _test_eof535;
goto st535;}
    }
#line 55 "src/vcf/vcf_v45.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {       if ( p == pe )
               goto _test_eof535;
goto st535;}
    }
#line 450 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {       if ( p == pe )
               goto _test_eof535;
goto st535;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof535;
goto st535;}
    }
	break;
	case 474: 
#line 460 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info field value is not a comma-separated list of valid strings (maybe it contains whitespaces?)"});
        p--; {       if ( p == pe )
               goto _test_eof535;
goto st535;}
    }
#line 55 "src/vcf/vcf_v45.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {       if ( p == pe )
               goto _test_eof535;
goto st535;}
    }
#line 450 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {       if ( p == pe )
               goto _test_eof535;
goto st535;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof535;
goto st535;}
    }
	break;
	case 541: 
	case 542: 
	case 543: 
#line 55 "src/vcf/vcf_v45.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {       if ( p == pe )
               goto _test_eof535;
goto st535;}
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
	case 463: 
#line 55 "src/vcf/vcf_v45.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {       if ( p == pe )
               goto _test_eof535;
goto st535;}
    }
#line 473 "src/vcf/vcf.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " does not start with a valid genotype";
        ErrorPolicy::handle_error(*this, new SamplesFieldBodyError{n_lines, message_stream.str(), "", "GT"});
        p--; {       if ( p == pe )
               goto _test_eof535;
goto st535;}
    }
#line 466 "src/vcf/vcf.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " is not a valid string";
        ErrorPolicy::handle_error(*this, new SamplesBodyError{n_lines, message_stream.str()});
        p--; {       if ( p == pe )
               goto _test_eof535;
goto st535;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof535;
goto st535;}
    }
	break;
	case 22: 
#line 60 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new FileformatError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 55 "src/vcf/vcf_v45.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {       if ( p == pe )
               goto _test_eof535;
goto st535;}
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
               goto _test_eof535;
goto st535;}
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
               goto _test_eof535;
goto st535;}
    }
	break;
	case 24: 
#line 259 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 283 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 271 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in assembly metadata"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 277 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in contig metadata"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 338 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 359 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 311 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 332 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in pedigreeDB metadata"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
	break;
#line 13841 "inc/vcf/validator_detail_v45.hpp"
	}
	}

	_out: {}
	}

#line 295 "src/vcf/vcf_v45.ragel"

    }
    
  }
}
