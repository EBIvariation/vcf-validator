
#line 1 "src/vcf/vcf_v43.ragel"
/**
 * Copyright 2014-2017 EMBL - European Bioinformatics Institute
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


#line 263 "src/vcf/vcf_v43.ragel"


namespace
{
  
#line 27 "inc/vcf/validator_detail_v43.hpp"
static const int vcf_v43_start = 1;
static const int vcf_v43_first_final = 561;
static const int vcf_v43_error = 0;

static const int vcf_v43_en_main = 1;
static const int vcf_v43_en_main_meta_section = 28;
static const int vcf_v43_en_main_body_section = 565;
static const int vcf_v43_en_meta_section_skip = 559;
static const int vcf_v43_en_body_section_skip = 560;


#line 269 "src/vcf/vcf_v43.ragel"

}

namespace ebi
{
  namespace vcf
  {

    template <typename Configuration>
    ParserImpl_v43<Configuration>::ParserImpl_v43(std::shared_ptr<Source> source, AdditionalChecks additionalChecks)
    : ParserImpl{source, additionalChecks}
    {
      
#line 53 "inc/vcf/validator_detail_v43.hpp"
	{
	cs = vcf_v43_start;
	}

#line 283 "src/vcf/vcf_v43.ragel"

    }

    template <typename Configuration>
    void ParserImpl_v43<Configuration>::parse_buffer(char const * p, char const * pe, char const * eof)
    {
      
#line 66 "inc/vcf/validator_detail_v43.hpp"
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
        p--; {goto st559;}
    }
	goto st0;
tr14:
#line 29 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this,
                new FileformatError{n_lines, "The fileformat declaration is not 'fileformat=VCFv4.3'"});
        p--; {goto st559;}
    }
#line 60 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new FileformatError{n_lines});
        p--; {goto st559;}
    }
	goto st0;
tr24:
#line 60 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new FileformatError{n_lines});
        p--; {goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st559;}
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
        
        p--; {goto st560;}
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
        
        p--; {goto st560;}
    }
	goto st0;
tr26:
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st559;}
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
        
        p--; {goto st560;}
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
        
        p--; {goto st560;}
    }
	goto st0;
tr29:
#line 259 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {goto st559;}
    }
#line 283 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {goto st559;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st559;}
    }
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st559;}
    }
#line 271 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in assembly metadata"});
        p--; {goto st559;}
    }
#line 277 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in contig metadata"});
        p--; {goto st559;}
    }
#line 338 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
        p--; {goto st559;}
    }
#line 359 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st559;}
    }
#line 311 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {goto st559;}
    }
#line 332 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in pedigreeDB metadata"});
        p--; {goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st559;}
    }
	goto st0;
tr40:
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st559;}
    }
	goto st0;
tr82:
#line 259 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st559;}
    }
	goto st0;
tr90:
#line 264 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines,
               "ALT metadata ID is not prefixed by DEL/INS/DUP/INV/CNV" + (source->version < Version::v44 ? std::string("/BND") : std::string("")) + " and suffixed by ':' and a text sequence"});
        p--; {goto st559;}
    }
#line 259 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st559;}
    }
	goto st0;
tr109:
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st559;}
    }
#line 259 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st559;}
    }
	goto st0;
tr118:
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {goto st559;}
    }
#line 259 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st559;}
    }
	goto st0;
tr125:
#line 283 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {goto st559;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st559;}
    }
	goto st0;
tr128:
#line 283 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st559;}
    }
	goto st0;
tr138:
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {goto st559;}
    }
#line 283 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st559;}
    }
	goto st0;
tr157:
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st559;}
    }
#line 283 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st559;}
    }
	goto st0;
tr172:
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st559;}
    }
	goto st0;
tr182:
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {goto st559;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st559;}
    }
	goto st0;
tr195:
#line 36 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "FORMAT metadata Number is not a number, A, R, G or dot"});
        p--; {goto st559;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st559;}
    }
	goto st0;
tr204:
#line 305 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "INFO metadata Type is not Integer, Float, Flag, Character or String"});
        p--; {goto st559;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st559;}
    }
	goto st0;
tr221:
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st559;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st559;}
    }
	goto st0;
tr237:
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st559;}
    }
	goto st0;
tr246:
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {goto st559;}
    }
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st559;}
    }
	goto st0;
tr259:
#line 42 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "INFO metadata Number is not a number, A, R, G or dot"});
        p--; {goto st559;}
    }
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st559;}
    }
	goto st0;
tr268:
#line 305 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "INFO metadata Type is not Integer, Float, Flag, Character or String"});
        p--; {goto st559;}
    }
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st559;}
    }
	goto st0;
tr285:
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st559;}
    }
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st559;}
    }
	goto st0;
tr301:
#line 338 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
        p--; {goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st559;}
    }
	goto st0;
tr310:
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {goto st559;}
    }
#line 338 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
        p--; {goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st559;}
    }
	goto st0;
tr323:
#line 343 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "META metadata Number is not a dot"});
        p--; {goto st559;}
    }
#line 338 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
        p--; {goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st559;}
    }
	goto st0;
tr331:
#line 348 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "META metadata Type is not String"});
        p--; {goto st559;}
    }
#line 338 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
        p--; {goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st559;}
    }
	goto st0;
tr348:
#line 353 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "META metadata Values is not a square-bracket delimited list of values"});
        p--; {goto st559;}
    }
#line 338 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
        p--; {goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st559;}
    }
	goto st0;
tr354:
#line 311 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st559;}
    }
	goto st0;
tr367:
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {goto st559;}
    }
#line 311 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st559;}
    }
	goto st0;
tr373:
#line 326 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "PEDIGREE metadata sequence of Name_N is not valid"});
        p--; {goto st559;}
    }
#line 311 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st559;}
    }
	goto st0;
tr383:
#line 321 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "PEDIGREE metadata Father or Mother is not valid"});
        p--; {goto st559;}
    }
#line 311 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st559;}
    }
	goto st0;
tr420:
#line 316 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "PEDIGREE metadata Original is not valid"});
        p--; {goto st559;}
    }
#line 311 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st559;}
    }
	goto st0;
tr425:
#line 359 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st559;}
    }
	goto st0;
tr436:
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {goto st559;}
    }
#line 359 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st559;}
    }
	goto st0;
tr459:
#line 271 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in assembly metadata"});
        p--; {goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st559;}
    }
	goto st0;
tr468:
#line 385 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata URL is not valid"});
        p--; {goto st559;}
    }
#line 271 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in assembly metadata"});
        p--; {goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st559;}
    }
	goto st0;
tr489:
#line 277 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in contig metadata"});
        p--; {goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st559;}
    }
	goto st0;
tr500:
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {goto st559;}
    }
#line 277 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in contig metadata"});
        p--; {goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st559;}
    }
	goto st0;
tr521:
#line 332 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in pedigreeDB metadata"});
        p--; {goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st559;}
    }
	goto st0;
tr533:
#line 385 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata URL is not valid"});
        p--; {goto st559;}
    }
#line 332 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in pedigreeDB metadata"});
        p--; {goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st559;}
    }
	goto st0;
tr556:
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
        
        p--; {goto st560;}
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
        
        p--; {goto st560;}
    }
	goto st0;
tr596:
#line 78 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new HeaderSectionError{n_lines});
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (Error *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
        
        p--; {goto st560;}
    }
	goto st0;
tr611:
#line 408 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new ChromosomeBodyError{n_lines});
        p--; {goto st560;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st560;}
    }
	goto st0;
tr614:
#line 414 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new PositionBodyError{n_lines});
        p--; {goto st560;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st560;}
    }
	goto st0;
tr618:
#line 420 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new IdBodyError{n_lines});
        p--; {goto st560;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st560;}
    }
	goto st0;
tr623:
#line 426 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new ReferenceAlleleBodyError{n_lines});
        p--; {goto st560;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st560;}
    }
	goto st0;
tr627:
#line 432 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new AlternateAllelesBodyError{n_lines});
        p--; {goto st560;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st560;}
    }
	goto st0;
tr636:
#line 438 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new QualityBodyError{n_lines});
        p--; {goto st560;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st560;}
    }
	goto st0;
tr647:
#line 444 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new FilterBodyError{n_lines});
        p--; {goto st560;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st560;}
    }
	goto st0;
tr655:
#line 455 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info key is not a sequence of alphanumeric and/or punctuation characters"});
        p--; {goto st560;}
    }
#line 450 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st560;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st560;}
    }
	goto st0;
tr659:
#line 50 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new FormatBodyError{n_lines, "Format does not start with a letter/underscore followed by alphanumeric/underscore/dot characters"});
        p--; {goto st560;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st560;}
    }
	goto st0;
tr664:
#line 473 "src/vcf/vcf.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " does not start with a valid genotype";
        ErrorPolicy::handle_error(*this, new SamplesFieldBodyError{n_lines, message_stream.str(), "", "GT"});
        p--; {goto st560;}
    }
#line 466 "src/vcf/vcf.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " is not a valid string";
        ErrorPolicy::handle_error(*this, new SamplesBodyError{n_lines, message_stream.str()});
        p--; {goto st560;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st560;}
    }
	goto st0;
tr672:
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st560;}
    }
	goto st0;
tr674:
#line 466 "src/vcf/vcf.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " is not a valid string";
        ErrorPolicy::handle_error(*this, new SamplesBodyError{n_lines, message_stream.str()});
        p--; {goto st560;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st560;}
    }
	goto st0;
tr680:
#line 460 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info field value is not a comma-separated list of valid strings (maybe it contains whitespaces?)"});
        p--; {goto st560;}
    }
#line 450 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st560;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st560;}
    }
	goto st0;
tr738:
#line 78 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new HeaderSectionError{n_lines});
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (Error *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
        
        p--; {goto st560;}
    }
#line 408 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new ChromosomeBodyError{n_lines});
        p--; {goto st560;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st560;}
    }
	goto st0;
tr745:
#line 450 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st560;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st560;}
    }
	goto st0;
#line 1050 "inc/vcf/validator_detail_v43.hpp"
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
#line 1173 "inc/vcf/validator_detail_v43.hpp"
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
#line 1188 "inc/vcf/validator_detail_v43.hpp"
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
#line 1203 "inc/vcf/validator_detail_v43.hpp"
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
#line 1218 "inc/vcf/validator_detail_v43.hpp"
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
#line 1233 "inc/vcf/validator_detail_v43.hpp"
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
#line 1248 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 51 )
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
#line 1263 "inc/vcf/validator_detail_v43.hpp"
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
          p--; {goto st559;}
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
#line 1295 "inc/vcf/validator_detail_v43.hpp"
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
		case 67: goto st423;
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
#line 1352 "inc/vcf/validator_detail_v43.hpp"
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
#line 1369 "inc/vcf/validator_detail_v43.hpp"
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
#line 1398 "inc/vcf/validator_detail_v43.hpp"
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
#line 1455 "inc/vcf/validator_detail_v43.hpp"
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
#line 1508 "inc/vcf/validator_detail_v43.hpp"
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
#line 1545 "inc/vcf/validator_detail_v43.hpp"
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
#line 1574 "inc/vcf/validator_detail_v43.hpp"
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
#line 1601 "inc/vcf/validator_detail_v43.hpp"
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
#line 1659 "inc/vcf/validator_detail_v43.hpp"
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
#line 1688 "inc/vcf/validator_detail_v43.hpp"
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
#line 1713 "inc/vcf/validator_detail_v43.hpp"
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
#line 1728 "inc/vcf/validator_detail_v43.hpp"
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
#line 1764 "inc/vcf/validator_detail_v43.hpp"
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
#line 1792 "inc/vcf/validator_detail_v43.hpp"
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
#line 1825 "inc/vcf/validator_detail_v43.hpp"
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
#line 1847 "inc/vcf/validator_detail_v43.hpp"
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
#line 1895 "inc/vcf/validator_detail_v43.hpp"
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
#line 1924 "inc/vcf/validator_detail_v43.hpp"
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
#line 1951 "inc/vcf/validator_detail_v43.hpp"
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
#line 1970 "inc/vcf/validator_detail_v43.hpp"
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
#line 1989 "inc/vcf/validator_detail_v43.hpp"
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
#line 2018 "inc/vcf/validator_detail_v43.hpp"
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
#line 2095 "inc/vcf/validator_detail_v43.hpp"
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
#line 2150 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 44: goto tr95;
		case 61: goto tr94;
	}
	if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
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
#line 2172 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 68 )
		goto st59;
	goto tr82;
st59:
	if ( ++p == pe )
		goto _test_eof59;
	/* fall through */
case 59:
	if ( (*p) == 101 )
		goto st60;
	goto tr82;
st60:
	if ( ++p == pe )
		goto _test_eof60;
	/* fall through */
case 60:
	if ( (*p) == 115 )
		goto st61;
	goto tr82;
st61:
	if ( ++p == pe )
		goto _test_eof61;
	/* fall through */
case 61:
	if ( (*p) == 99 )
		goto st62;
	goto tr82;
st62:
	if ( ++p == pe )
		goto _test_eof62;
	/* fall through */
case 62:
	if ( (*p) == 114 )
		goto st63;
	goto tr82;
st63:
	if ( ++p == pe )
		goto _test_eof63;
	/* fall through */
case 63:
	if ( (*p) == 105 )
		goto st64;
	goto tr82;
st64:
	if ( ++p == pe )
		goto _test_eof64;
	/* fall through */
case 64:
	if ( (*p) == 112 )
		goto st65;
	goto tr82;
st65:
	if ( ++p == pe )
		goto _test_eof65;
	/* fall through */
case 65:
	if ( (*p) == 116 )
		goto st66;
	goto tr82;
st66:
	if ( ++p == pe )
		goto _test_eof66;
	/* fall through */
case 66:
	if ( (*p) == 105 )
		goto st67;
	goto tr82;
st67:
	if ( ++p == pe )
		goto _test_eof67;
	/* fall through */
case 67:
	if ( (*p) == 111 )
		goto st68;
	goto tr82;
st68:
	if ( ++p == pe )
		goto _test_eof68;
	/* fall through */
case 68:
	if ( (*p) == 110 )
		goto st69;
	goto tr82;
st69:
	if ( ++p == pe )
		goto _test_eof69;
	/* fall through */
case 69:
	if ( (*p) == 61 )
		goto st70;
	goto tr82;
st70:
	if ( ++p == pe )
		goto _test_eof70;
	/* fall through */
case 70:
	if ( (*p) == 34 )
		goto tr108;
	goto tr82;
tr108:
#line 156 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Description");
    }
	goto st71;
st71:
	if ( ++p == pe )
		goto _test_eof71;
	/* fall through */
case 71:
#line 2283 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr111;
		case 92: goto tr112;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr110;
	goto tr109;
tr110:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st72;
tr113:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st72;
st72:
	if ( ++p == pe )
		goto _test_eof72;
	/* fall through */
case 72:
#line 2312 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr114;
		case 92: goto tr115;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr113;
	goto tr109;
tr111:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st73;
tr114:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st73;
st73:
	if ( ++p == pe )
		goto _test_eof73;
	/* fall through */
case 73:
#line 2341 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 44: goto st74;
		case 62: goto st78;
	}
	goto tr109;
st74:
	if ( ++p == pe )
		goto _test_eof74;
	/* fall through */
case 74:
	switch( (*p) ) {
		case 43: goto tr119;
		case 95: goto tr119;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr119;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr120;
		} else if ( (*p) >= 65 )
			goto tr120;
	} else
		goto tr120;
	goto tr118;
tr119:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st75;
st75:
	if ( ++p == pe )
		goto _test_eof75;
	/* fall through */
case 75:
#line 2379 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto st75;
		case 95: goto st75;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st75;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr122;
		} else if ( (*p) >= 65 )
			goto tr122;
	} else
		goto tr122;
	goto tr118;
tr120:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st76;
tr122:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st76;
st76:
	if ( ++p == pe )
		goto _test_eof76;
	/* fall through */
case 76:
#line 2417 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr122;
		case 61: goto tr123;
		case 95: goto tr122;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr122;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr122;
		} else if ( (*p) >= 65 )
			goto tr122;
	} else
		goto tr122;
	goto tr118;
tr123:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st77;
st77:
	if ( ++p == pe )
		goto _test_eof77;
	/* fall through */
case 77:
#line 2446 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 34 )
		goto st71;
	goto tr82;
st78:
	if ( ++p == pe )
		goto _test_eof78;
	/* fall through */
case 78:
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
	}
	goto tr82;
tr112:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st79;
tr115:
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
#line 2481 "inc/vcf/validator_detail_v43.hpp"
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr113;
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
	goto st80;
st80:
	if ( ++p == pe )
		goto _test_eof80;
	/* fall through */
case 80:
#line 2500 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 73: goto tr126;
		case 79: goto tr127;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr125;
tr126:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st81;
st81:
	if ( ++p == pe )
		goto _test_eof81;
	/* fall through */
case 81:
#line 2520 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 76: goto tr129;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr128;
tr129:
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
#line 2539 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 84: goto tr130;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr128;
tr130:
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
#line 2558 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 69: goto tr131;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr128;
tr131:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st84;
st84:
	if ( ++p == pe )
		goto _test_eof84;
	/* fall through */
case 84:
#line 2577 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 82: goto st85;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr128;
st85:
	if ( ++p == pe )
		goto _test_eof85;
	/* fall through */
case 85:
	if ( (*p) == 61 )
		goto tr133;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr128;
tr133:
#line 120 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "FILTER");
    }
	goto st86;
st86:
	if ( ++p == pe )
		goto _test_eof86;
	/* fall through */
case 86:
#line 2606 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 60 )
		goto st87;
	goto tr128;
st87:
	if ( ++p == pe )
		goto _test_eof87;
	/* fall through */
case 87:
	if ( (*p) == 73 )
		goto st88;
	goto tr128;
st88:
	if ( ++p == pe )
		goto _test_eof88;
	/* fall through */
case 88:
	if ( (*p) == 68 )
		goto st89;
	goto tr128;
st89:
	if ( ++p == pe )
		goto _test_eof89;
	/* fall through */
case 89:
	if ( (*p) == 61 )
		goto st90;
	goto tr128;
st90:
	if ( ++p == pe )
		goto _test_eof90;
	/* fall through */
case 90:
	switch( (*p) ) {
		case 43: goto tr139;
		case 95: goto tr139;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr139;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr140;
		} else if ( (*p) >= 65 )
			goto tr140;
	} else
		goto tr140;
	goto tr138;
tr139:
#line 144 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st91;
st91:
	if ( ++p == pe )
		goto _test_eof91;
	/* fall through */
case 91:
#line 2670 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto st91;
		case 95: goto st91;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st91;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr142;
		} else if ( (*p) >= 65 )
			goto tr142;
	} else
		goto tr142;
	goto tr138;
tr142:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st92;
tr140:
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
	goto st92;
st92:
	if ( ++p == pe )
		goto _test_eof92;
	/* fall through */
case 92:
#line 2712 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 44: goto tr143;
		case 95: goto tr142;
	}
	if ( (*p) < 48 ) {
		if ( 43 <= (*p) && (*p) <= 46 )
			goto tr142;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr142;
		} else if ( (*p) >= 65 )
			goto tr142;
	} else
		goto tr142;
	goto tr138;
tr143:
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
#line 2740 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 68 )
		goto st94;
	goto tr128;
st94:
	if ( ++p == pe )
		goto _test_eof94;
	/* fall through */
case 94:
	if ( (*p) == 101 )
		goto st95;
	goto tr128;
st95:
	if ( ++p == pe )
		goto _test_eof95;
	/* fall through */
case 95:
	if ( (*p) == 115 )
		goto st96;
	goto tr128;
st96:
	if ( ++p == pe )
		goto _test_eof96;
	/* fall through */
case 96:
	if ( (*p) == 99 )
		goto st97;
	goto tr128;
st97:
	if ( ++p == pe )
		goto _test_eof97;
	/* fall through */
case 97:
	if ( (*p) == 114 )
		goto st98;
	goto tr128;
st98:
	if ( ++p == pe )
		goto _test_eof98;
	/* fall through */
case 98:
	if ( (*p) == 105 )
		goto st99;
	goto tr128;
st99:
	if ( ++p == pe )
		goto _test_eof99;
	/* fall through */
case 99:
	if ( (*p) == 112 )
		goto st100;
	goto tr128;
st100:
	if ( ++p == pe )
		goto _test_eof100;
	/* fall through */
case 100:
	if ( (*p) == 116 )
		goto st101;
	goto tr128;
st101:
	if ( ++p == pe )
		goto _test_eof101;
	/* fall through */
case 101:
	if ( (*p) == 105 )
		goto st102;
	goto tr128;
st102:
	if ( ++p == pe )
		goto _test_eof102;
	/* fall through */
case 102:
	if ( (*p) == 111 )
		goto st103;
	goto tr128;
st103:
	if ( ++p == pe )
		goto _test_eof103;
	/* fall through */
case 103:
	if ( (*p) == 110 )
		goto st104;
	goto tr128;
st104:
	if ( ++p == pe )
		goto _test_eof104;
	/* fall through */
case 104:
	if ( (*p) == 61 )
		goto st105;
	goto tr128;
st105:
	if ( ++p == pe )
		goto _test_eof105;
	/* fall through */
case 105:
	if ( (*p) == 34 )
		goto tr156;
	goto tr128;
tr156:
#line 156 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Description");
    }
	goto st106;
st106:
	if ( ++p == pe )
		goto _test_eof106;
	/* fall through */
case 106:
#line 2851 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr159;
		case 92: goto tr160;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr158;
	goto tr157;
tr158:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st107;
tr161:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st107;
st107:
	if ( ++p == pe )
		goto _test_eof107;
	/* fall through */
case 107:
#line 2880 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr162;
		case 92: goto tr163;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr161;
	goto tr157;
tr159:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st108;
tr162:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st108;
st108:
	if ( ++p == pe )
		goto _test_eof108;
	/* fall through */
case 108:
#line 2909 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 44: goto st109;
		case 62: goto st113;
	}
	goto tr157;
st109:
	if ( ++p == pe )
		goto _test_eof109;
	/* fall through */
case 109:
	switch( (*p) ) {
		case 43: goto tr166;
		case 95: goto tr166;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr166;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr167;
		} else if ( (*p) >= 65 )
			goto tr167;
	} else
		goto tr167;
	goto tr138;
tr166:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st110;
st110:
	if ( ++p == pe )
		goto _test_eof110;
	/* fall through */
case 110:
#line 2947 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto st110;
		case 95: goto st110;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st110;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr169;
		} else if ( (*p) >= 65 )
			goto tr169;
	} else
		goto tr169;
	goto tr138;
tr167:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st111;
tr169:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st111;
st111:
	if ( ++p == pe )
		goto _test_eof111;
	/* fall through */
case 111:
#line 2985 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr169;
		case 61: goto tr170;
		case 95: goto tr169;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr169;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr169;
		} else if ( (*p) >= 65 )
			goto tr169;
	} else
		goto tr169;
	goto tr138;
tr170:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st112;
st112:
	if ( ++p == pe )
		goto _test_eof112;
	/* fall through */
case 112:
#line 3014 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 34 )
		goto st106;
	goto tr128;
st113:
	if ( ++p == pe )
		goto _test_eof113;
	/* fall through */
case 113:
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
	}
	goto tr128;
tr160:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st114;
tr163:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st114;
st114:
	if ( ++p == pe )
		goto _test_eof114;
	/* fall through */
case 114:
#line 3049 "inc/vcf/validator_detail_v43.hpp"
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr161;
	goto tr128;
tr127:
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
#line 3064 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 82: goto tr173;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr172;
tr173:
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
#line 3083 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 77: goto tr174;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr172;
tr174:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st117;
st117:
	if ( ++p == pe )
		goto _test_eof117;
	/* fall through */
case 117:
#line 3102 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 65: goto tr175;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr172;
tr175:
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
#line 3121 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 84: goto st119;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr172;
st119:
	if ( ++p == pe )
		goto _test_eof119;
	/* fall through */
case 119:
	if ( (*p) == 61 )
		goto tr177;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr172;
tr177:
#line 124 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "FORMAT");
    }
	goto st120;
st120:
	if ( ++p == pe )
		goto _test_eof120;
	/* fall through */
case 120:
#line 3150 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 60 )
		goto st121;
	goto tr172;
st121:
	if ( ++p == pe )
		goto _test_eof121;
	/* fall through */
case 121:
	if ( (*p) == 73 )
		goto st122;
	goto tr172;
st122:
	if ( ++p == pe )
		goto _test_eof122;
	/* fall through */
case 122:
	if ( (*p) == 68 )
		goto st123;
	goto tr172;
st123:
	if ( ++p == pe )
		goto _test_eof123;
	/* fall through */
case 123:
	if ( (*p) == 61 )
		goto st124;
	goto tr172;
st124:
	if ( ++p == pe )
		goto _test_eof124;
	/* fall through */
case 124:
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
	goto st125;
st125:
	if ( ++p == pe )
		goto _test_eof125;
	/* fall through */
case 125:
#line 3214 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto st125;
		case 95: goto st125;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st125;
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
	goto st126;
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
	goto st126;
st126:
	if ( ++p == pe )
		goto _test_eof126;
	/* fall through */
case 126:
#line 3256 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 44: goto tr187;
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
	goto st127;
st127:
	if ( ++p == pe )
		goto _test_eof127;
	/* fall through */
case 127:
#line 3284 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 78 )
		goto st128;
	goto tr172;
st128:
	if ( ++p == pe )
		goto _test_eof128;
	/* fall through */
case 128:
	if ( (*p) == 117 )
		goto st129;
	goto tr172;
st129:
	if ( ++p == pe )
		goto _test_eof129;
	/* fall through */
case 129:
	if ( (*p) == 109 )
		goto st130;
	goto tr172;
st130:
	if ( ++p == pe )
		goto _test_eof130;
	/* fall through */
case 130:
	if ( (*p) == 98 )
		goto st131;
	goto tr172;
st131:
	if ( ++p == pe )
		goto _test_eof131;
	/* fall through */
case 131:
	if ( (*p) == 101 )
		goto st132;
	goto tr172;
st132:
	if ( ++p == pe )
		goto _test_eof132;
	/* fall through */
case 132:
	if ( (*p) == 114 )
		goto st133;
	goto tr172;
st133:
	if ( ++p == pe )
		goto _test_eof133;
	/* fall through */
case 133:
	if ( (*p) == 61 )
		goto st134;
	goto tr172;
st134:
	if ( ++p == pe )
		goto _test_eof134;
	/* fall through */
case 134:
	switch( (*p) ) {
		case 46: goto tr196;
		case 65: goto tr196;
		case 71: goto tr196;
		case 82: goto tr196;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr197;
	goto tr195;
tr196:
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
	goto st135;
st135:
	if ( ++p == pe )
		goto _test_eof135;
	/* fall through */
case 135:
#line 3369 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 44 )
		goto tr198;
	goto tr195;
tr198:
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
#line 3384 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 84 )
		goto st137;
	goto tr172;
st137:
	if ( ++p == pe )
		goto _test_eof137;
	/* fall through */
case 137:
	if ( (*p) == 121 )
		goto st138;
	goto tr172;
st138:
	if ( ++p == pe )
		goto _test_eof138;
	/* fall through */
case 138:
	if ( (*p) == 112 )
		goto st139;
	goto tr172;
st139:
	if ( ++p == pe )
		goto _test_eof139;
	/* fall through */
case 139:
	if ( (*p) == 101 )
		goto st140;
	goto tr172;
st140:
	if ( ++p == pe )
		goto _test_eof140;
	/* fall through */
case 140:
	if ( (*p) == 61 )
		goto st141;
	goto tr172;
st141:
	if ( ++p == pe )
		goto _test_eof141;
	/* fall through */
case 141:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr205;
	} else if ( (*p) >= 65 )
		goto tr205;
	goto tr204;
tr207:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st142;
tr205:
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
	goto st142;
st142:
	if ( ++p == pe )
		goto _test_eof142;
	/* fall through */
case 142:
#line 3456 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 44 )
		goto tr206;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr207;
	} else if ( (*p) >= 65 )
		goto tr207;
	goto tr204;
tr206:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st143;
st143:
	if ( ++p == pe )
		goto _test_eof143;
	/* fall through */
case 143:
#line 3476 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 68 )
		goto st144;
	goto tr172;
st144:
	if ( ++p == pe )
		goto _test_eof144;
	/* fall through */
case 144:
	if ( (*p) == 101 )
		goto st145;
	goto tr172;
st145:
	if ( ++p == pe )
		goto _test_eof145;
	/* fall through */
case 145:
	if ( (*p) == 115 )
		goto st146;
	goto tr172;
st146:
	if ( ++p == pe )
		goto _test_eof146;
	/* fall through */
case 146:
	if ( (*p) == 99 )
		goto st147;
	goto tr172;
st147:
	if ( ++p == pe )
		goto _test_eof147;
	/* fall through */
case 147:
	if ( (*p) == 114 )
		goto st148;
	goto tr172;
st148:
	if ( ++p == pe )
		goto _test_eof148;
	/* fall through */
case 148:
	if ( (*p) == 105 )
		goto st149;
	goto tr172;
st149:
	if ( ++p == pe )
		goto _test_eof149;
	/* fall through */
case 149:
	if ( (*p) == 112 )
		goto st150;
	goto tr172;
st150:
	if ( ++p == pe )
		goto _test_eof150;
	/* fall through */
case 150:
	if ( (*p) == 116 )
		goto st151;
	goto tr172;
st151:
	if ( ++p == pe )
		goto _test_eof151;
	/* fall through */
case 151:
	if ( (*p) == 105 )
		goto st152;
	goto tr172;
st152:
	if ( ++p == pe )
		goto _test_eof152;
	/* fall through */
case 152:
	if ( (*p) == 111 )
		goto st153;
	goto tr172;
st153:
	if ( ++p == pe )
		goto _test_eof153;
	/* fall through */
case 153:
	if ( (*p) == 110 )
		goto st154;
	goto tr172;
st154:
	if ( ++p == pe )
		goto _test_eof154;
	/* fall through */
case 154:
	if ( (*p) == 61 )
		goto st155;
	goto tr172;
st155:
	if ( ++p == pe )
		goto _test_eof155;
	/* fall through */
case 155:
	if ( (*p) == 34 )
		goto tr220;
	goto tr172;
tr220:
#line 156 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Description");
    }
	goto st156;
st156:
	if ( ++p == pe )
		goto _test_eof156;
	/* fall through */
case 156:
#line 3587 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr223;
		case 92: goto tr224;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr222;
	goto tr221;
tr222:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st157;
tr225:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st157;
st157:
	if ( ++p == pe )
		goto _test_eof157;
	/* fall through */
case 157:
#line 3616 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr226;
		case 92: goto tr227;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr225;
	goto tr221;
tr223:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st158;
tr226:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st158;
st158:
	if ( ++p == pe )
		goto _test_eof158;
	/* fall through */
case 158:
#line 3645 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 44: goto st159;
		case 62: goto st163;
	}
	goto tr221;
st159:
	if ( ++p == pe )
		goto _test_eof159;
	/* fall through */
case 159:
	switch( (*p) ) {
		case 43: goto tr230;
		case 95: goto tr230;
	}
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
	goto tr182;
tr230:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st160;
st160:
	if ( ++p == pe )
		goto _test_eof160;
	/* fall through */
case 160:
#line 3683 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto st160;
		case 95: goto st160;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st160;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr233;
		} else if ( (*p) >= 65 )
			goto tr233;
	} else
		goto tr233;
	goto tr182;
tr231:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st161;
tr233:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st161;
st161:
	if ( ++p == pe )
		goto _test_eof161;
	/* fall through */
case 161:
#line 3721 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr233;
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
	goto tr182;
tr234:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st162;
st162:
	if ( ++p == pe )
		goto _test_eof162;
	/* fall through */
case 162:
#line 3750 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 34 )
		goto st156;
	goto tr172;
st163:
	if ( ++p == pe )
		goto _test_eof163;
	/* fall through */
case 163:
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
	}
	goto tr172;
tr224:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st164;
tr227:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st164;
st164:
	if ( ++p == pe )
		goto _test_eof164;
	/* fall through */
case 164:
#line 3785 "inc/vcf/validator_detail_v43.hpp"
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr225;
	goto tr172;
tr236:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st165;
tr197:
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
	goto st165;
st165:
	if ( ++p == pe )
		goto _test_eof165;
	/* fall through */
case 165:
#line 3814 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 44 )
		goto tr198;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr236;
	goto tr195;
tr33:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st166;
st166:
	if ( ++p == pe )
		goto _test_eof166;
	/* fall through */
case 166:
#line 3835 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 78: goto tr238;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr237;
tr238:
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
#line 3854 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 70: goto tr239;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr237;
tr239:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st168;
st168:
	if ( ++p == pe )
		goto _test_eof168;
	/* fall through */
case 168:
#line 3873 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 79: goto st169;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr237;
st169:
	if ( ++p == pe )
		goto _test_eof169;
	/* fall through */
case 169:
	if ( (*p) == 61 )
		goto tr241;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr237;
tr241:
#line 128 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "INFO");
    }
	goto st170;
st170:
	if ( ++p == pe )
		goto _test_eof170;
	/* fall through */
case 170:
#line 3902 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 60 )
		goto st171;
	goto tr237;
st171:
	if ( ++p == pe )
		goto _test_eof171;
	/* fall through */
case 171:
	if ( (*p) == 73 )
		goto st172;
	goto tr237;
st172:
	if ( ++p == pe )
		goto _test_eof172;
	/* fall through */
case 172:
	if ( (*p) == 68 )
		goto st173;
	goto tr237;
st173:
	if ( ++p == pe )
		goto _test_eof173;
	/* fall through */
case 173:
	if ( (*p) == 61 )
		goto st174;
	goto tr237;
st174:
	if ( ++p == pe )
		goto _test_eof174;
	/* fall through */
case 174:
	switch( (*p) ) {
		case 43: goto tr247;
		case 95: goto tr247;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr247;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr248;
		} else if ( (*p) >= 65 )
			goto tr248;
	} else
		goto tr248;
	goto tr246;
tr247:
#line 144 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st175;
st175:
	if ( ++p == pe )
		goto _test_eof175;
	/* fall through */
case 175:
#line 3966 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto st175;
		case 95: goto st175;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st175;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr250;
		} else if ( (*p) >= 65 )
			goto tr250;
	} else
		goto tr250;
	goto tr246;
tr250:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st176;
tr248:
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
	goto st176;
st176:
	if ( ++p == pe )
		goto _test_eof176;
	/* fall through */
case 176:
#line 4008 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 44: goto tr251;
		case 95: goto tr250;
	}
	if ( (*p) < 48 ) {
		if ( 43 <= (*p) && (*p) <= 46 )
			goto tr250;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr250;
		} else if ( (*p) >= 65 )
			goto tr250;
	} else
		goto tr250;
	goto tr246;
tr251:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st177;
st177:
	if ( ++p == pe )
		goto _test_eof177;
	/* fall through */
case 177:
#line 4036 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 78 )
		goto st178;
	goto tr237;
st178:
	if ( ++p == pe )
		goto _test_eof178;
	/* fall through */
case 178:
	if ( (*p) == 117 )
		goto st179;
	goto tr237;
st179:
	if ( ++p == pe )
		goto _test_eof179;
	/* fall through */
case 179:
	if ( (*p) == 109 )
		goto st180;
	goto tr237;
st180:
	if ( ++p == pe )
		goto _test_eof180;
	/* fall through */
case 180:
	if ( (*p) == 98 )
		goto st181;
	goto tr237;
st181:
	if ( ++p == pe )
		goto _test_eof181;
	/* fall through */
case 181:
	if ( (*p) == 101 )
		goto st182;
	goto tr237;
st182:
	if ( ++p == pe )
		goto _test_eof182;
	/* fall through */
case 182:
	if ( (*p) == 114 )
		goto st183;
	goto tr237;
st183:
	if ( ++p == pe )
		goto _test_eof183;
	/* fall through */
case 183:
	if ( (*p) == 61 )
		goto st184;
	goto tr237;
st184:
	if ( ++p == pe )
		goto _test_eof184;
	/* fall through */
case 184:
	switch( (*p) ) {
		case 46: goto tr260;
		case 65: goto tr260;
		case 71: goto tr260;
		case 82: goto tr260;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr261;
	goto tr259;
tr260:
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
	goto st185;
st185:
	if ( ++p == pe )
		goto _test_eof185;
	/* fall through */
case 185:
#line 4121 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 44 )
		goto tr262;
	goto tr259;
tr262:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st186;
st186:
	if ( ++p == pe )
		goto _test_eof186;
	/* fall through */
case 186:
#line 4136 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 84 )
		goto st187;
	goto tr237;
st187:
	if ( ++p == pe )
		goto _test_eof187;
	/* fall through */
case 187:
	if ( (*p) == 121 )
		goto st188;
	goto tr237;
st188:
	if ( ++p == pe )
		goto _test_eof188;
	/* fall through */
case 188:
	if ( (*p) == 112 )
		goto st189;
	goto tr237;
st189:
	if ( ++p == pe )
		goto _test_eof189;
	/* fall through */
case 189:
	if ( (*p) == 101 )
		goto st190;
	goto tr237;
st190:
	if ( ++p == pe )
		goto _test_eof190;
	/* fall through */
case 190:
	if ( (*p) == 61 )
		goto st191;
	goto tr237;
st191:
	if ( ++p == pe )
		goto _test_eof191;
	/* fall through */
case 191:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr269;
	} else if ( (*p) >= 65 )
		goto tr269;
	goto tr268;
tr271:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st192;
tr269:
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
	goto st192;
st192:
	if ( ++p == pe )
		goto _test_eof192;
	/* fall through */
case 192:
#line 4208 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 44 )
		goto tr270;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr271;
	} else if ( (*p) >= 65 )
		goto tr271;
	goto tr268;
tr270:
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
#line 4228 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 68 )
		goto st194;
	goto tr237;
st194:
	if ( ++p == pe )
		goto _test_eof194;
	/* fall through */
case 194:
	if ( (*p) == 101 )
		goto st195;
	goto tr237;
st195:
	if ( ++p == pe )
		goto _test_eof195;
	/* fall through */
case 195:
	if ( (*p) == 115 )
		goto st196;
	goto tr237;
st196:
	if ( ++p == pe )
		goto _test_eof196;
	/* fall through */
case 196:
	if ( (*p) == 99 )
		goto st197;
	goto tr237;
st197:
	if ( ++p == pe )
		goto _test_eof197;
	/* fall through */
case 197:
	if ( (*p) == 114 )
		goto st198;
	goto tr237;
st198:
	if ( ++p == pe )
		goto _test_eof198;
	/* fall through */
case 198:
	if ( (*p) == 105 )
		goto st199;
	goto tr237;
st199:
	if ( ++p == pe )
		goto _test_eof199;
	/* fall through */
case 199:
	if ( (*p) == 112 )
		goto st200;
	goto tr237;
st200:
	if ( ++p == pe )
		goto _test_eof200;
	/* fall through */
case 200:
	if ( (*p) == 116 )
		goto st201;
	goto tr237;
st201:
	if ( ++p == pe )
		goto _test_eof201;
	/* fall through */
case 201:
	if ( (*p) == 105 )
		goto st202;
	goto tr237;
st202:
	if ( ++p == pe )
		goto _test_eof202;
	/* fall through */
case 202:
	if ( (*p) == 111 )
		goto st203;
	goto tr237;
st203:
	if ( ++p == pe )
		goto _test_eof203;
	/* fall through */
case 203:
	if ( (*p) == 110 )
		goto st204;
	goto tr237;
st204:
	if ( ++p == pe )
		goto _test_eof204;
	/* fall through */
case 204:
	if ( (*p) == 61 )
		goto st205;
	goto tr237;
st205:
	if ( ++p == pe )
		goto _test_eof205;
	/* fall through */
case 205:
	if ( (*p) == 34 )
		goto tr284;
	goto tr237;
tr284:
#line 156 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Description");
    }
	goto st206;
st206:
	if ( ++p == pe )
		goto _test_eof206;
	/* fall through */
case 206:
#line 4339 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr287;
		case 92: goto tr288;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr286;
	goto tr285;
tr286:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st207;
tr289:
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
#line 4368 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr290;
		case 92: goto tr291;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr289;
	goto tr285;
tr287:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st208;
tr290:
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
#line 4397 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 44: goto st209;
		case 62: goto st213;
	}
	goto tr285;
st209:
	if ( ++p == pe )
		goto _test_eof209;
	/* fall through */
case 209:
	switch( (*p) ) {
		case 43: goto tr294;
		case 95: goto tr294;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr294;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr295;
		} else if ( (*p) >= 65 )
			goto tr295;
	} else
		goto tr295;
	goto tr246;
tr294:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st210;
st210:
	if ( ++p == pe )
		goto _test_eof210;
	/* fall through */
case 210:
#line 4435 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto st210;
		case 95: goto st210;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st210;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr297;
		} else if ( (*p) >= 65 )
			goto tr297;
	} else
		goto tr297;
	goto tr246;
tr295:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st211;
tr297:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st211;
st211:
	if ( ++p == pe )
		goto _test_eof211;
	/* fall through */
case 211:
#line 4473 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr297;
		case 61: goto tr298;
		case 95: goto tr297;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr297;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr297;
		} else if ( (*p) >= 65 )
			goto tr297;
	} else
		goto tr297;
	goto tr246;
tr298:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st212;
st212:
	if ( ++p == pe )
		goto _test_eof212;
	/* fall through */
case 212:
#line 4502 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 34 )
		goto st206;
	goto tr237;
st213:
	if ( ++p == pe )
		goto _test_eof213;
	/* fall through */
case 213:
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
	}
	goto tr237;
tr288:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st214;
tr291:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st214;
st214:
	if ( ++p == pe )
		goto _test_eof214;
	/* fall through */
case 214:
#line 4537 "inc/vcf/validator_detail_v43.hpp"
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr289;
	goto tr237;
tr300:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st215;
tr261:
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
	goto st215;
st215:
	if ( ++p == pe )
		goto _test_eof215;
	/* fall through */
case 215:
#line 4566 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 44 )
		goto tr262;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr300;
	goto tr259;
tr34:
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
#line 4587 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 69: goto tr302;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr301;
tr302:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st217;
st217:
	if ( ++p == pe )
		goto _test_eof217;
	/* fall through */
case 217:
#line 4606 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 84: goto tr303;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr301;
tr303:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st218;
st218:
	if ( ++p == pe )
		goto _test_eof218;
	/* fall through */
case 218:
#line 4625 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 65: goto st219;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr301;
st219:
	if ( ++p == pe )
		goto _test_eof219;
	/* fall through */
case 219:
	if ( (*p) == 61 )
		goto tr305;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr301;
tr305:
#line 168 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "META");
    }
	goto st220;
st220:
	if ( ++p == pe )
		goto _test_eof220;
	/* fall through */
case 220:
#line 4654 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 60 )
		goto st221;
	goto tr301;
st221:
	if ( ++p == pe )
		goto _test_eof221;
	/* fall through */
case 221:
	if ( (*p) == 73 )
		goto st222;
	goto tr301;
st222:
	if ( ++p == pe )
		goto _test_eof222;
	/* fall through */
case 222:
	if ( (*p) == 68 )
		goto st223;
	goto tr301;
st223:
	if ( ++p == pe )
		goto _test_eof223;
	/* fall through */
case 223:
	if ( (*p) == 61 )
		goto st224;
	goto tr301;
st224:
	if ( ++p == pe )
		goto _test_eof224;
	/* fall through */
case 224:
	switch( (*p) ) {
		case 43: goto tr311;
		case 95: goto tr311;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr311;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr312;
		} else if ( (*p) >= 65 )
			goto tr312;
	} else
		goto tr312;
	goto tr310;
tr311:
#line 144 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st225;
st225:
	if ( ++p == pe )
		goto _test_eof225;
	/* fall through */
case 225:
#line 4718 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto st225;
		case 95: goto st225;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st225;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr314;
		} else if ( (*p) >= 65 )
			goto tr314;
	} else
		goto tr314;
	goto tr310;
tr314:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st226;
tr312:
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
	goto st226;
st226:
	if ( ++p == pe )
		goto _test_eof226;
	/* fall through */
case 226:
#line 4760 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 44: goto tr315;
		case 95: goto tr314;
	}
	if ( (*p) < 48 ) {
		if ( 43 <= (*p) && (*p) <= 46 )
			goto tr314;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr314;
		} else if ( (*p) >= 65 )
			goto tr314;
	} else
		goto tr314;
	goto tr310;
tr315:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st227;
st227:
	if ( ++p == pe )
		goto _test_eof227;
	/* fall through */
case 227:
#line 4788 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 78 )
		goto st228;
	goto tr301;
st228:
	if ( ++p == pe )
		goto _test_eof228;
	/* fall through */
case 228:
	if ( (*p) == 117 )
		goto st229;
	goto tr301;
st229:
	if ( ++p == pe )
		goto _test_eof229;
	/* fall through */
case 229:
	if ( (*p) == 109 )
		goto st230;
	goto tr301;
st230:
	if ( ++p == pe )
		goto _test_eof230;
	/* fall through */
case 230:
	if ( (*p) == 98 )
		goto st231;
	goto tr301;
st231:
	if ( ++p == pe )
		goto _test_eof231;
	/* fall through */
case 231:
	if ( (*p) == 101 )
		goto st232;
	goto tr301;
st232:
	if ( ++p == pe )
		goto _test_eof232;
	/* fall through */
case 232:
	if ( (*p) == 114 )
		goto st233;
	goto tr301;
st233:
	if ( ++p == pe )
		goto _test_eof233;
	/* fall through */
case 233:
	if ( (*p) == 61 )
		goto st234;
	goto tr301;
st234:
	if ( ++p == pe )
		goto _test_eof234;
	/* fall through */
case 234:
	if ( (*p) == 46 )
		goto tr324;
	goto tr323;
tr324:
#line 148 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Number");
    }
	goto st235;
st235:
	if ( ++p == pe )
		goto _test_eof235;
	/* fall through */
case 235:
#line 4859 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 44 )
		goto st236;
	goto tr323;
st236:
	if ( ++p == pe )
		goto _test_eof236;
	/* fall through */
case 236:
	if ( (*p) == 84 )
		goto st237;
	goto tr301;
st237:
	if ( ++p == pe )
		goto _test_eof237;
	/* fall through */
case 237:
	if ( (*p) == 121 )
		goto st238;
	goto tr301;
st238:
	if ( ++p == pe )
		goto _test_eof238;
	/* fall through */
case 238:
	if ( (*p) == 112 )
		goto st239;
	goto tr301;
st239:
	if ( ++p == pe )
		goto _test_eof239;
	/* fall through */
case 239:
	if ( (*p) == 101 )
		goto st240;
	goto tr301;
st240:
	if ( ++p == pe )
		goto _test_eof240;
	/* fall through */
case 240:
	if ( (*p) == 61 )
		goto st241;
	goto tr301;
st241:
	if ( ++p == pe )
		goto _test_eof241;
	/* fall through */
case 241:
	if ( (*p) == 83 )
		goto tr332;
	goto tr331;
tr332:
#line 152 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Type");
    }
	goto st242;
st242:
	if ( ++p == pe )
		goto _test_eof242;
	/* fall through */
case 242:
#line 4922 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 116 )
		goto st243;
	goto tr331;
st243:
	if ( ++p == pe )
		goto _test_eof243;
	/* fall through */
case 243:
	if ( (*p) == 114 )
		goto st244;
	goto tr331;
st244:
	if ( ++p == pe )
		goto _test_eof244;
	/* fall through */
case 244:
	if ( (*p) == 105 )
		goto st245;
	goto tr331;
st245:
	if ( ++p == pe )
		goto _test_eof245;
	/* fall through */
case 245:
	if ( (*p) == 110 )
		goto st246;
	goto tr331;
st246:
	if ( ++p == pe )
		goto _test_eof246;
	/* fall through */
case 246:
	if ( (*p) == 103 )
		goto st247;
	goto tr331;
st247:
	if ( ++p == pe )
		goto _test_eof247;
	/* fall through */
case 247:
	if ( (*p) == 44 )
		goto st248;
	goto tr331;
st248:
	if ( ++p == pe )
		goto _test_eof248;
	/* fall through */
case 248:
	if ( (*p) == 86 )
		goto st249;
	goto tr301;
st249:
	if ( ++p == pe )
		goto _test_eof249;
	/* fall through */
case 249:
	if ( (*p) == 97 )
		goto st250;
	goto tr301;
st250:
	if ( ++p == pe )
		goto _test_eof250;
	/* fall through */
case 250:
	if ( (*p) == 108 )
		goto st251;
	goto tr301;
st251:
	if ( ++p == pe )
		goto _test_eof251;
	/* fall through */
case 251:
	if ( (*p) == 117 )
		goto st252;
	goto tr301;
st252:
	if ( ++p == pe )
		goto _test_eof252;
	/* fall through */
case 252:
	if ( (*p) == 101 )
		goto st253;
	goto tr301;
st253:
	if ( ++p == pe )
		goto _test_eof253;
	/* fall through */
case 253:
	if ( (*p) == 115 )
		goto st254;
	goto tr301;
st254:
	if ( ++p == pe )
		goto _test_eof254;
	/* fall through */
case 254:
	if ( (*p) == 61 )
		goto st255;
	goto tr301;
st255:
	if ( ++p == pe )
		goto _test_eof255;
	/* fall through */
case 255:
	if ( (*p) == 91 )
		goto tr346;
	goto tr301;
tr346:
#line 172 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Values");
    }
	goto st256;
st256:
	if ( ++p == pe )
		goto _test_eof256;
	/* fall through */
case 256:
#line 5041 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 61 )
		goto tr347;
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr347;
	} else if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr347;
	} else
		goto tr347;
	goto tr301;
tr347:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st257;
tr349:
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
#line 5074 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 44: goto tr350;
		case 61: goto tr349;
		case 93: goto tr351;
	}
	if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr349;
	} else if ( (*p) >= 33 )
		goto tr349;
	goto tr348;
tr350:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st258;
st258:
	if ( ++p == pe )
		goto _test_eof258;
	/* fall through */
case 258:
#line 5097 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 32: goto tr352;
		case 61: goto tr349;
	}
	if ( (*p) < 33 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr352;
	} else if ( (*p) > 43 ) {
		if ( (*p) > 59 ) {
			if ( 63 <= (*p) && (*p) <= 126 )
				goto tr349;
		} else if ( (*p) >= 45 )
			goto tr349;
	} else
		goto tr349;
	goto tr301;
tr352:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st259;
st259:
	if ( ++p == pe )
		goto _test_eof259;
	/* fall through */
case 259:
#line 5125 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 61 )
		goto tr349;
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr349;
	} else if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr349;
	} else
		goto tr349;
	goto tr301;
tr351:
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
#line 5152 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 44: goto tr350;
		case 62: goto st261;
		case 93: goto tr351;
	}
	if ( (*p) > 59 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr349;
	} else if ( (*p) >= 33 )
		goto tr349;
	goto tr348;
st261:
	if ( ++p == pe )
		goto _test_eof261;
	/* fall through */
case 261:
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
	}
	goto tr301;
tr35:
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
#line 5189 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 69: goto tr355;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr354;
tr355:
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
#line 5208 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 68: goto tr356;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr354;
tr356:
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
#line 5227 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 73: goto tr357;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr354;
tr357:
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
#line 5246 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 71: goto tr358;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr354;
tr358:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st266;
st266:
	if ( ++p == pe )
		goto _test_eof266;
	/* fall through */
case 266:
#line 5265 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 82: goto tr359;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr354;
tr359:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st267;
st267:
	if ( ++p == pe )
		goto _test_eof267;
	/* fall through */
case 267:
#line 5284 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 69: goto tr360;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr354;
tr360:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st268;
st268:
	if ( ++p == pe )
		goto _test_eof268;
	/* fall through */
case 268:
#line 5303 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 69: goto st269;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr354;
st269:
	if ( ++p == pe )
		goto _test_eof269;
	/* fall through */
case 269:
	if ( (*p) == 61 )
		goto tr362;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr354;
tr362:
#line 132 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "PEDIGREE");
    }
	goto st270;
st270:
	if ( ++p == pe )
		goto _test_eof270;
	/* fall through */
case 270:
#line 5332 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 60 )
		goto st271;
	goto tr354;
st271:
	if ( ++p == pe )
		goto _test_eof271;
	/* fall through */
case 271:
	if ( (*p) == 73 )
		goto st272;
	goto tr354;
st272:
	if ( ++p == pe )
		goto _test_eof272;
	/* fall through */
case 272:
	if ( (*p) == 68 )
		goto st273;
	goto tr354;
st273:
	if ( ++p == pe )
		goto _test_eof273;
	/* fall through */
case 273:
	if ( (*p) == 61 )
		goto st274;
	goto tr354;
st274:
	if ( ++p == pe )
		goto _test_eof274;
	/* fall through */
case 274:
	switch( (*p) ) {
		case 43: goto tr368;
		case 95: goto tr368;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr368;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr369;
		} else if ( (*p) >= 65 )
			goto tr369;
	} else
		goto tr369;
	goto tr367;
tr368:
#line 144 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st275;
st275:
	if ( ++p == pe )
		goto _test_eof275;
	/* fall through */
case 275:
#line 5396 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto st275;
		case 95: goto st275;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st275;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr371;
		} else if ( (*p) >= 65 )
			goto tr371;
	} else
		goto tr371;
	goto tr367;
tr371:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st276;
tr369:
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
	goto st276;
st276:
	if ( ++p == pe )
		goto _test_eof276;
	/* fall through */
case 276:
#line 5438 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 44: goto tr372;
		case 95: goto tr371;
	}
	if ( (*p) < 48 ) {
		if ( 43 <= (*p) && (*p) <= 46 )
			goto tr371;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr371;
		} else if ( (*p) >= 65 )
			goto tr371;
	} else
		goto tr371;
	goto tr367;
tr372:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st277;
st277:
	if ( ++p == pe )
		goto _test_eof277;
	/* fall through */
case 277:
#line 5466 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 70: goto st278;
		case 78: goto tr375;
		case 79: goto st308;
	}
	goto tr373;
st278:
	if ( ++p == pe )
		goto _test_eof278;
	/* fall through */
case 278:
	if ( (*p) == 97 )
		goto st279;
	goto tr354;
st279:
	if ( ++p == pe )
		goto _test_eof279;
	/* fall through */
case 279:
	if ( (*p) == 116 )
		goto st280;
	goto tr354;
st280:
	if ( ++p == pe )
		goto _test_eof280;
	/* fall through */
case 280:
	if ( (*p) == 104 )
		goto st281;
	goto tr354;
st281:
	if ( ++p == pe )
		goto _test_eof281;
	/* fall through */
case 281:
	if ( (*p) == 101 )
		goto st282;
	goto tr354;
st282:
	if ( ++p == pe )
		goto _test_eof282;
	/* fall through */
case 282:
	if ( (*p) == 114 )
		goto st283;
	goto tr354;
st283:
	if ( ++p == pe )
		goto _test_eof283;
	/* fall through */
case 283:
	if ( (*p) == 61 )
		goto st284;
	goto tr354;
st284:
	if ( ++p == pe )
		goto _test_eof284;
	/* fall through */
case 284:
	switch( (*p) ) {
		case 43: goto tr384;
		case 95: goto tr384;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr384;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr385;
		} else if ( (*p) >= 65 )
			goto tr385;
	} else
		goto tr385;
	goto tr383;
tr384:
#line 180 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Father");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st285;
st285:
	if ( ++p == pe )
		goto _test_eof285;
	/* fall through */
case 285:
#line 5557 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto st285;
		case 95: goto st285;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st285;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr387;
		} else if ( (*p) >= 65 )
			goto tr387;
	} else
		goto tr387;
	goto tr383;
tr387:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st286;
tr385:
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
	goto st286;
st286:
	if ( ++p == pe )
		goto _test_eof286;
	/* fall through */
case 286:
#line 5599 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 44: goto tr388;
		case 95: goto tr387;
	}
	if ( (*p) < 48 ) {
		if ( 43 <= (*p) && (*p) <= 46 )
			goto tr387;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr387;
		} else if ( (*p) >= 65 )
			goto tr387;
	} else
		goto tr387;
	goto tr383;
tr388:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st287;
st287:
	if ( ++p == pe )
		goto _test_eof287;
	/* fall through */
case 287:
#line 5627 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 77 )
		goto st288;
	goto tr354;
st288:
	if ( ++p == pe )
		goto _test_eof288;
	/* fall through */
case 288:
	if ( (*p) == 111 )
		goto st289;
	goto tr354;
st289:
	if ( ++p == pe )
		goto _test_eof289;
	/* fall through */
case 289:
	if ( (*p) == 116 )
		goto st290;
	goto tr354;
st290:
	if ( ++p == pe )
		goto _test_eof290;
	/* fall through */
case 290:
	if ( (*p) == 104 )
		goto st291;
	goto tr354;
st291:
	if ( ++p == pe )
		goto _test_eof291;
	/* fall through */
case 291:
	if ( (*p) == 101 )
		goto st292;
	goto tr354;
st292:
	if ( ++p == pe )
		goto _test_eof292;
	/* fall through */
case 292:
	if ( (*p) == 114 )
		goto st293;
	goto tr354;
st293:
	if ( ++p == pe )
		goto _test_eof293;
	/* fall through */
case 293:
	if ( (*p) == 61 )
		goto st294;
	goto tr354;
st294:
	if ( ++p == pe )
		goto _test_eof294;
	/* fall through */
case 294:
	switch( (*p) ) {
		case 43: goto tr396;
		case 95: goto tr396;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr396;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr397;
		} else if ( (*p) >= 65 )
			goto tr397;
	} else
		goto tr397;
	goto tr383;
tr396:
#line 184 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Mother");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st295;
st295:
	if ( ++p == pe )
		goto _test_eof295;
	/* fall through */
case 295:
#line 5715 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto st295;
		case 95: goto st295;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st295;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr399;
		} else if ( (*p) >= 65 )
			goto tr399;
	} else
		goto tr399;
	goto tr383;
tr399:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st296;
tr397:
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
	goto st296;
st296:
	if ( ++p == pe )
		goto _test_eof296;
	/* fall through */
case 296:
#line 5757 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr399;
		case 62: goto tr400;
		case 95: goto tr399;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr399;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr399;
		} else if ( (*p) >= 65 )
			goto tr399;
	} else
		goto tr399;
	goto tr383;
tr400:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st297;
st297:
	if ( ++p == pe )
		goto _test_eof297;
	/* fall through */
case 297:
#line 5786 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
	}
	goto tr354;
tr375:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
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
#line 5807 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 97 )
		goto tr401;
	goto tr373;
tr401:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st299;
st299:
	if ( ++p == pe )
		goto _test_eof299;
	/* fall through */
case 299:
#line 5822 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 109 )
		goto tr402;
	goto tr373;
tr402:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st300;
st300:
	if ( ++p == pe )
		goto _test_eof300;
	/* fall through */
case 300:
#line 5837 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 101 )
		goto tr403;
	goto tr373;
tr403:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st301;
st301:
	if ( ++p == pe )
		goto _test_eof301;
	/* fall through */
case 301:
#line 5852 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 95 )
		goto tr404;
	goto tr373;
tr404:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st302;
st302:
	if ( ++p == pe )
		goto _test_eof302;
	/* fall through */
case 302:
#line 5867 "inc/vcf/validator_detail_v43.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr405;
	goto tr373;
tr405:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st303;
st303:
	if ( ++p == pe )
		goto _test_eof303;
	/* fall through */
case 303:
#line 5882 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 61 )
		goto tr406;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr405;
	goto tr373;
tr406:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st304;
st304:
	if ( ++p == pe )
		goto _test_eof304;
	/* fall through */
case 304:
#line 5899 "inc/vcf/validator_detail_v43.hpp"
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
	goto tr373;
tr407:
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
#line 5927 "inc/vcf/validator_detail_v43.hpp"
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
				goto tr410;
		} else if ( (*p) >= 65 )
			goto tr410;
	} else
		goto tr410;
	goto tr373;
tr408:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st306;
tr410:
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
#line 5965 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 44: goto tr411;
		case 62: goto tr400;
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
	goto tr373;
tr411:
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
#line 5994 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 78 )
		goto tr375;
	goto tr373;
st308:
	if ( ++p == pe )
		goto _test_eof308;
	/* fall through */
case 308:
	if ( (*p) == 114 )
		goto st309;
	goto tr354;
st309:
	if ( ++p == pe )
		goto _test_eof309;
	/* fall through */
case 309:
	if ( (*p) == 105 )
		goto st310;
	goto tr354;
st310:
	if ( ++p == pe )
		goto _test_eof310;
	/* fall through */
case 310:
	if ( (*p) == 103 )
		goto st311;
	goto tr354;
st311:
	if ( ++p == pe )
		goto _test_eof311;
	/* fall through */
case 311:
	if ( (*p) == 105 )
		goto st312;
	goto tr354;
st312:
	if ( ++p == pe )
		goto _test_eof312;
	/* fall through */
case 312:
	if ( (*p) == 110 )
		goto st313;
	goto tr354;
st313:
	if ( ++p == pe )
		goto _test_eof313;
	/* fall through */
case 313:
	if ( (*p) == 97 )
		goto st314;
	goto tr354;
st314:
	if ( ++p == pe )
		goto _test_eof314;
	/* fall through */
case 314:
	if ( (*p) == 108 )
		goto st315;
	goto tr354;
st315:
	if ( ++p == pe )
		goto _test_eof315;
	/* fall through */
case 315:
	if ( (*p) == 61 )
		goto st316;
	goto tr354;
st316:
	if ( ++p == pe )
		goto _test_eof316;
	/* fall through */
case 316:
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
	goto tr420;
tr421:
#line 176 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Original");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st317;
st317:
	if ( ++p == pe )
		goto _test_eof317;
	/* fall through */
case 317:
#line 6098 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto st317;
		case 95: goto st317;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st317;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr424;
		} else if ( (*p) >= 65 )
			goto tr424;
	} else
		goto tr424;
	goto tr420;
tr424:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st318;
tr422:
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
	goto st318;
st318:
	if ( ++p == pe )
		goto _test_eof318;
	/* fall through */
case 318:
#line 6140 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr424;
		case 62: goto tr400;
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
	goto tr420;
tr36:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
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
#line 6173 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 65: goto tr426;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr425;
tr426:
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
#line 6192 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 77: goto tr427;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr425;
tr427:
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
#line 6211 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 80: goto tr428;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr425;
tr428:
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
#line 6230 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 76: goto tr429;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr425;
tr429:
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
#line 6249 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 69: goto st324;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr425;
st324:
	if ( ++p == pe )
		goto _test_eof324;
	/* fall through */
case 324:
	if ( (*p) == 61 )
		goto tr431;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr425;
tr431:
#line 140 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "SAMPLE");
    }
	goto st325;
st325:
	if ( ++p == pe )
		goto _test_eof325;
	/* fall through */
case 325:
#line 6278 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 60 )
		goto st326;
	goto tr425;
st326:
	if ( ++p == pe )
		goto _test_eof326;
	/* fall through */
case 326:
	if ( (*p) == 73 )
		goto st327;
	goto tr425;
st327:
	if ( ++p == pe )
		goto _test_eof327;
	/* fall through */
case 327:
	if ( (*p) == 68 )
		goto st328;
	goto tr425;
st328:
	if ( ++p == pe )
		goto _test_eof328;
	/* fall through */
case 328:
	if ( (*p) == 61 )
		goto st329;
	goto tr425;
st329:
	if ( ++p == pe )
		goto _test_eof329;
	/* fall through */
case 329:
	switch( (*p) ) {
		case 43: goto tr437;
		case 95: goto tr437;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr437;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr438;
		} else if ( (*p) >= 65 )
			goto tr438;
	} else
		goto tr438;
	goto tr436;
tr437:
#line 144 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st330;
st330:
	if ( ++p == pe )
		goto _test_eof330;
	/* fall through */
case 330:
#line 6342 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto st330;
		case 95: goto st330;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st330;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr440;
		} else if ( (*p) >= 65 )
			goto tr440;
	} else
		goto tr440;
	goto tr436;
tr440:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st331;
tr438:
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
	goto st331;
st331:
	if ( ++p == pe )
		goto _test_eof331;
	/* fall through */
case 331:
#line 6384 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 44: goto tr441;
		case 62: goto tr442;
		case 95: goto tr440;
	}
	if ( (*p) < 48 ) {
		if ( 43 <= (*p) && (*p) <= 46 )
			goto tr440;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr440;
		} else if ( (*p) >= 65 )
			goto tr440;
	} else
		goto tr440;
	goto tr436;
tr441:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st332;
st332:
	if ( ++p == pe )
		goto _test_eof332;
	/* fall through */
case 332:
#line 6413 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr443;
		case 95: goto tr443;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr443;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr444;
		} else if ( (*p) >= 65 )
			goto tr444;
	} else
		goto tr444;
	goto tr425;
tr443:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st333;
st333:
	if ( ++p == pe )
		goto _test_eof333;
	/* fall through */
case 333:
#line 6441 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto st333;
		case 95: goto st333;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st333;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr446;
		} else if ( (*p) >= 65 )
			goto tr446;
	} else
		goto tr446;
	goto tr425;
tr444:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st334;
tr446:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st334;
st334:
	if ( ++p == pe )
		goto _test_eof334;
	/* fall through */
case 334:
#line 6479 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr446;
		case 61: goto tr447;
		case 95: goto tr446;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr446;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr446;
		} else if ( (*p) >= 65 )
			goto tr446;
	} else
		goto tr446;
	goto tr425;
tr447:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st335;
st335:
	if ( ++p == pe )
		goto _test_eof335;
	/* fall through */
case 335:
#line 6508 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 34 )
		goto st338;
	if ( (*p) < 45 ) {
		if ( 32 <= (*p) && (*p) <= 43 )
			goto tr448;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr448;
	} else
		goto tr448;
	goto tr425;
tr448:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st336;
tr450:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st336;
st336:
	if ( ++p == pe )
		goto _test_eof336;
	/* fall through */
case 336:
#line 6541 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 44: goto tr441;
		case 62: goto tr442;
	}
	if ( (*p) > 33 ) {
		if ( 35 <= (*p) && (*p) <= 126 )
			goto tr450;
	} else if ( (*p) >= 32 )
		goto tr450;
	goto tr425;
tr442:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st337;
st337:
	if ( ++p == pe )
		goto _test_eof337;
	/* fall through */
case 337:
#line 6563 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
	}
	goto tr425;
st338:
	if ( ++p == pe )
		goto _test_eof338;
	/* fall through */
case 338:
	switch( (*p) ) {
		case 34: goto tr452;
		case 92: goto tr453;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr451;
	goto tr425;
tr451:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st339;
tr454:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st339;
st339:
	if ( ++p == pe )
		goto _test_eof339;
	/* fall through */
case 339:
#line 6602 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr455;
		case 92: goto tr456;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr454;
	goto tr425;
tr452:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st340;
tr455:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st340;
st340:
	if ( ++p == pe )
		goto _test_eof340;
	/* fall through */
case 340:
#line 6631 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 44: goto st332;
		case 62: goto st337;
	}
	goto tr425;
tr453:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st341;
tr456:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st341;
st341:
	if ( ++p == pe )
		goto _test_eof341;
	/* fall through */
case 341:
#line 6658 "inc/vcf/validator_detail_v43.hpp"
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr454;
	goto tr425;
tr37:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st342;
st342:
	if ( ++p == pe )
		goto _test_eof342;
	/* fall through */
case 342:
#line 6677 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 115: goto tr460;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr459;
tr460:
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
#line 6696 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 115: goto tr461;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr459;
tr461:
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
#line 6715 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 101: goto tr462;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr459;
tr462:
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
#line 6734 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 109: goto tr463;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr459;
tr463:
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
#line 6753 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 98: goto tr464;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr459;
tr464:
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
#line 6772 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 108: goto tr465;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr459;
tr465:
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
#line 6791 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 121: goto st349;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr459;
st349:
	if ( ++p == pe )
		goto _test_eof349;
	/* fall through */
case 349:
	if ( (*p) == 61 )
		goto tr467;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr459;
tr467:
#line 112 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "assembly");
    }
	goto st350;
st350:
	if ( ++p == pe )
		goto _test_eof350;
	/* fall through */
case 350:
#line 6820 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr469;
	} else if ( (*p) >= 65 )
		goto tr469;
	goto tr468;
tr469:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st351;
st351:
	if ( ++p == pe )
		goto _test_eof351;
	/* fall through */
case 351:
#line 6838 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 10: goto tr468;
		case 13: goto tr471;
		case 35: goto tr468;
		case 47: goto tr468;
		case 58: goto tr468;
		case 63: goto tr468;
	}
	goto st352;
tr471:
#line 43 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st352;
st352:
	if ( ++p == pe )
		goto _test_eof352;
	/* fall through */
case 352:
#line 6865 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 10: goto tr468;
		case 13: goto tr471;
		case 35: goto tr468;
		case 47: goto tr468;
		case 58: goto st353;
		case 63: goto tr468;
	}
	goto st352;
st353:
	if ( ++p == pe )
		goto _test_eof353;
	/* fall through */
case 353:
	if ( (*p) == 47 )
		goto st354;
	goto tr468;
st354:
	if ( ++p == pe )
		goto _test_eof354;
	/* fall through */
case 354:
	if ( (*p) == 47 )
		goto st355;
	goto tr468;
st355:
	if ( ++p == pe )
		goto _test_eof355;
	/* fall through */
case 355:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st356;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr476;
	} else
		goto tr476;
	goto tr468;
st356:
	if ( ++p == pe )
		goto _test_eof356;
	/* fall through */
case 356:
	if ( (*p) == 46 )
		goto st357;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st367;
	goto tr468;
st357:
	if ( ++p == pe )
		goto _test_eof357;
	/* fall through */
case 357:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st358;
	goto tr468;
st358:
	if ( ++p == pe )
		goto _test_eof358;
	/* fall through */
case 358:
	if ( (*p) == 46 )
		goto st359;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st365;
	goto tr468;
st359:
	if ( ++p == pe )
		goto _test_eof359;
	/* fall through */
case 359:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st360;
	goto tr468;
st360:
	if ( ++p == pe )
		goto _test_eof360;
	/* fall through */
case 360:
	if ( (*p) == 46 )
		goto st361;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st363;
	goto tr468;
st361:
	if ( ++p == pe )
		goto _test_eof361;
	/* fall through */
case 361:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr476;
	goto tr468;
tr476:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st362;
tr485:
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
	goto st362;
st362:
	if ( ++p == pe )
		goto _test_eof362;
	/* fall through */
case 362:
#line 6998 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 10: goto tr46;
		case 13: goto tr485;
	}
	goto tr476;
st363:
	if ( ++p == pe )
		goto _test_eof363;
	/* fall through */
case 363:
	if ( (*p) == 46 )
		goto st361;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st364;
	goto tr468;
st364:
	if ( ++p == pe )
		goto _test_eof364;
	/* fall through */
case 364:
	if ( (*p) == 46 )
		goto st361;
	goto tr468;
st365:
	if ( ++p == pe )
		goto _test_eof365;
	/* fall through */
case 365:
	if ( (*p) == 46 )
		goto st359;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st366;
	goto tr468;
st366:
	if ( ++p == pe )
		goto _test_eof366;
	/* fall through */
case 366:
	if ( (*p) == 46 )
		goto st359;
	goto tr468;
st367:
	if ( ++p == pe )
		goto _test_eof367;
	/* fall through */
case 367:
	if ( (*p) == 46 )
		goto st357;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st368;
	goto tr468;
st368:
	if ( ++p == pe )
		goto _test_eof368;
	/* fall through */
case 368:
	if ( (*p) == 46 )
		goto st357;
	goto tr468;
tr38:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
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
#line 7073 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 111: goto tr490;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr489;
tr490:
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
#line 7092 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 110: goto tr491;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr489;
tr491:
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
#line 7111 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 116: goto tr492;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr489;
tr492:
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
#line 7130 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 105: goto tr493;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr489;
tr493:
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
#line 7149 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 103: goto st374;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr489;
st374:
	if ( ++p == pe )
		goto _test_eof374;
	/* fall through */
case 374:
	if ( (*p) == 61 )
		goto tr495;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr489;
tr495:
#line 116 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "contig");
    }
	goto st375;
st375:
	if ( ++p == pe )
		goto _test_eof375;
	/* fall through */
case 375:
#line 7178 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 60 )
		goto st376;
	goto tr489;
st376:
	if ( ++p == pe )
		goto _test_eof376;
	/* fall through */
case 376:
	if ( (*p) == 73 )
		goto st377;
	goto tr489;
st377:
	if ( ++p == pe )
		goto _test_eof377;
	/* fall through */
case 377:
	if ( (*p) == 68 )
		goto st378;
	goto tr489;
st378:
	if ( ++p == pe )
		goto _test_eof378;
	/* fall through */
case 378:
	if ( (*p) == 61 )
		goto st379;
	goto tr489;
st379:
	if ( ++p == pe )
		goto _test_eof379;
	/* fall through */
case 379:
	switch( (*p) ) {
		case 43: goto tr501;
		case 92: goto tr501;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr501;
		} else if ( (*p) >= 33 )
			goto tr501;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr501;
		} else if ( (*p) >= 63 )
			goto tr501;
	} else
		goto tr501;
	goto tr500;
tr502:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st380;
tr501:
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
	goto st380;
st380:
	if ( ++p == pe )
		goto _test_eof380;
	/* fall through */
case 380:
#line 7255 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 44: goto tr503;
		case 62: goto tr504;
		case 92: goto tr502;
	}
	if ( (*p) < 43 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr502;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr502;
		} else if ( (*p) >= 63 )
			goto tr502;
	} else
		goto tr502;
	goto tr500;
tr503:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st381;
st381:
	if ( ++p == pe )
		goto _test_eof381;
	/* fall through */
case 381:
#line 7284 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr505;
		case 95: goto tr505;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr505;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr506;
		} else if ( (*p) >= 65 )
			goto tr506;
	} else
		goto tr506;
	goto tr489;
tr505:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st382;
st382:
	if ( ++p == pe )
		goto _test_eof382;
	/* fall through */
case 382:
#line 7312 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto st382;
		case 95: goto st382;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st382;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr508;
		} else if ( (*p) >= 65 )
			goto tr508;
	} else
		goto tr508;
	goto tr489;
tr506:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st383;
tr508:
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
#line 7350 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr508;
		case 61: goto tr509;
		case 95: goto tr508;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr508;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr508;
		} else if ( (*p) >= 65 )
			goto tr508;
	} else
		goto tr508;
	goto tr489;
tr509:
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
#line 7379 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 34 )
		goto st387;
	if ( (*p) < 45 ) {
		if ( 32 <= (*p) && (*p) <= 43 )
			goto tr510;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr510;
	} else
		goto tr510;
	goto tr489;
tr510:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st385;
tr512:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st385;
st385:
	if ( ++p == pe )
		goto _test_eof385;
	/* fall through */
case 385:
#line 7412 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 44: goto tr503;
		case 62: goto tr504;
	}
	if ( (*p) > 33 ) {
		if ( 35 <= (*p) && (*p) <= 126 )
			goto tr512;
	} else if ( (*p) >= 32 )
		goto tr512;
	goto tr489;
tr504:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st386;
st386:
	if ( ++p == pe )
		goto _test_eof386;
	/* fall through */
case 386:
#line 7434 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
	}
	goto tr489;
st387:
	if ( ++p == pe )
		goto _test_eof387;
	/* fall through */
case 387:
	switch( (*p) ) {
		case 34: goto tr514;
		case 92: goto tr515;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr513;
	goto tr489;
tr513:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st388;
tr516:
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
#line 7473 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr517;
		case 92: goto tr518;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr516;
	goto tr489;
tr514:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st389;
tr517:
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
#line 7502 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 44: goto st381;
		case 62: goto st386;
	}
	goto tr489;
tr515:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st390;
tr518:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st390;
st390:
	if ( ++p == pe )
		goto _test_eof390;
	/* fall through */
case 390:
#line 7529 "inc/vcf/validator_detail_v43.hpp"
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr516;
	goto tr489;
tr39:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
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
#line 7548 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 101: goto tr522;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr521;
tr522:
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
#line 7567 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 100: goto tr523;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr521;
tr523:
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
#line 7586 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 105: goto tr524;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr521;
tr524:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st394;
st394:
	if ( ++p == pe )
		goto _test_eof394;
	/* fall through */
case 394:
#line 7605 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 103: goto tr525;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr521;
tr525:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st395;
st395:
	if ( ++p == pe )
		goto _test_eof395;
	/* fall through */
case 395:
#line 7624 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 114: goto tr526;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr521;
tr526:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st396;
st396:
	if ( ++p == pe )
		goto _test_eof396;
	/* fall through */
case 396:
#line 7643 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 101: goto tr527;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr521;
tr527:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st397;
st397:
	if ( ++p == pe )
		goto _test_eof397;
	/* fall through */
case 397:
#line 7662 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 101: goto tr528;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr521;
tr528:
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
#line 7681 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 68: goto tr529;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr521;
tr529:
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
#line 7700 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 66: goto st400;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr521;
st400:
	if ( ++p == pe )
		goto _test_eof400;
	/* fall through */
case 400:
	if ( (*p) == 61 )
		goto tr531;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr521;
tr531:
#line 136 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "pedigreeDB");
    }
	goto st401;
st401:
	if ( ++p == pe )
		goto _test_eof401;
	/* fall through */
case 401:
#line 7729 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 60 )
		goto st402;
	goto tr521;
st402:
	if ( ++p == pe )
		goto _test_eof402;
	/* fall through */
case 402:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr534;
	} else if ( (*p) >= 65 )
		goto tr534;
	goto tr533;
tr534:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st403;
st403:
	if ( ++p == pe )
		goto _test_eof403;
	/* fall through */
case 403:
#line 7755 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 10: goto tr533;
		case 13: goto tr536;
		case 35: goto tr533;
		case 47: goto tr533;
		case 58: goto tr533;
		case 63: goto tr533;
	}
	goto st404;
tr536:
#line 43 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st404;
st404:
	if ( ++p == pe )
		goto _test_eof404;
	/* fall through */
case 404:
#line 7782 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 10: goto tr533;
		case 13: goto tr536;
		case 35: goto tr533;
		case 47: goto tr533;
		case 58: goto st405;
		case 63: goto tr533;
	}
	goto st404;
st405:
	if ( ++p == pe )
		goto _test_eof405;
	/* fall through */
case 405:
	if ( (*p) == 47 )
		goto st406;
	goto tr533;
st406:
	if ( ++p == pe )
		goto _test_eof406;
	/* fall through */
case 406:
	if ( (*p) == 47 )
		goto st407;
	goto tr533;
st407:
	if ( ++p == pe )
		goto _test_eof407;
	/* fall through */
case 407:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st408;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr541;
	} else
		goto tr541;
	goto tr533;
st408:
	if ( ++p == pe )
		goto _test_eof408;
	/* fall through */
case 408:
	if ( (*p) == 46 )
		goto st409;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st421;
	goto tr533;
st409:
	if ( ++p == pe )
		goto _test_eof409;
	/* fall through */
case 409:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st410;
	goto tr533;
st410:
	if ( ++p == pe )
		goto _test_eof410;
	/* fall through */
case 410:
	if ( (*p) == 46 )
		goto st411;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st419;
	goto tr533;
st411:
	if ( ++p == pe )
		goto _test_eof411;
	/* fall through */
case 411:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st412;
	goto tr533;
st412:
	if ( ++p == pe )
		goto _test_eof412;
	/* fall through */
case 412:
	if ( (*p) == 46 )
		goto st413;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st417;
	goto tr533;
st413:
	if ( ++p == pe )
		goto _test_eof413;
	/* fall through */
case 413:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr541;
	goto tr533;
tr541:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st414;
tr550:
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
	goto st414;
st414:
	if ( ++p == pe )
		goto _test_eof414;
	/* fall through */
case 414:
#line 7903 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 10: goto tr533;
		case 13: goto tr550;
		case 62: goto tr551;
	}
	goto tr541;
tr551:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st415;
st415:
	if ( ++p == pe )
		goto _test_eof415;
	/* fall through */
case 415:
#line 7925 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr552;
		case 62: goto tr551;
	}
	goto tr541;
tr552:
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
	goto st416;
st416:
	if ( ++p == pe )
		goto _test_eof416;
	/* fall through */
case 416:
#line 7961 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 10: goto st28;
		case 13: goto tr550;
		case 62: goto tr551;
	}
	goto tr541;
st417:
	if ( ++p == pe )
		goto _test_eof417;
	/* fall through */
case 417:
	if ( (*p) == 46 )
		goto st413;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st418;
	goto tr533;
st418:
	if ( ++p == pe )
		goto _test_eof418;
	/* fall through */
case 418:
	if ( (*p) == 46 )
		goto st413;
	goto tr533;
st419:
	if ( ++p == pe )
		goto _test_eof419;
	/* fall through */
case 419:
	if ( (*p) == 46 )
		goto st411;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st420;
	goto tr533;
st420:
	if ( ++p == pe )
		goto _test_eof420;
	/* fall through */
case 420:
	if ( (*p) == 46 )
		goto st411;
	goto tr533;
st421:
	if ( ++p == pe )
		goto _test_eof421;
	/* fall through */
case 421:
	if ( (*p) == 46 )
		goto st409;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st422;
	goto tr533;
st422:
	if ( ++p == pe )
		goto _test_eof422;
	/* fall through */
case 422:
	if ( (*p) == 46 )
		goto st409;
	goto tr533;
st423:
	if ( ++p == pe )
		goto _test_eof423;
	/* fall through */
case 423:
	if ( (*p) == 72 )
		goto st424;
	goto tr556;
st424:
	if ( ++p == pe )
		goto _test_eof424;
	/* fall through */
case 424:
	if ( (*p) == 82 )
		goto st425;
	goto tr556;
st425:
	if ( ++p == pe )
		goto _test_eof425;
	/* fall through */
case 425:
	if ( (*p) == 79 )
		goto st426;
	goto tr556;
st426:
	if ( ++p == pe )
		goto _test_eof426;
	/* fall through */
case 426:
	if ( (*p) == 77 )
		goto st427;
	goto tr556;
st427:
	if ( ++p == pe )
		goto _test_eof427;
	/* fall through */
case 427:
	if ( (*p) == 9 )
		goto tr561;
	goto tr556;
tr561:
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st428;
st428:
	if ( ++p == pe )
		goto _test_eof428;
	/* fall through */
case 428:
#line 8073 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 80 )
		goto st429;
	goto tr556;
st429:
	if ( ++p == pe )
		goto _test_eof429;
	/* fall through */
case 429:
	if ( (*p) == 79 )
		goto st430;
	goto tr556;
st430:
	if ( ++p == pe )
		goto _test_eof430;
	/* fall through */
case 430:
	if ( (*p) == 83 )
		goto st431;
	goto tr556;
st431:
	if ( ++p == pe )
		goto _test_eof431;
	/* fall through */
case 431:
	if ( (*p) == 9 )
		goto tr565;
	goto tr556;
tr565:
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st432;
st432:
	if ( ++p == pe )
		goto _test_eof432;
	/* fall through */
case 432:
#line 8112 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 73 )
		goto st433;
	goto tr556;
st433:
	if ( ++p == pe )
		goto _test_eof433;
	/* fall through */
case 433:
	if ( (*p) == 68 )
		goto st434;
	goto tr556;
st434:
	if ( ++p == pe )
		goto _test_eof434;
	/* fall through */
case 434:
	if ( (*p) == 9 )
		goto tr568;
	goto tr556;
tr568:
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
#line 8143 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 82 )
		goto st436;
	goto tr556;
st436:
	if ( ++p == pe )
		goto _test_eof436;
	/* fall through */
case 436:
	if ( (*p) == 69 )
		goto st437;
	goto tr556;
st437:
	if ( ++p == pe )
		goto _test_eof437;
	/* fall through */
case 437:
	if ( (*p) == 70 )
		goto st438;
	goto tr556;
st438:
	if ( ++p == pe )
		goto _test_eof438;
	/* fall through */
case 438:
	if ( (*p) == 9 )
		goto tr572;
	goto tr556;
tr572:
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st439;
st439:
	if ( ++p == pe )
		goto _test_eof439;
	/* fall through */
case 439:
#line 8182 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 65 )
		goto st440;
	goto tr556;
st440:
	if ( ++p == pe )
		goto _test_eof440;
	/* fall through */
case 440:
	if ( (*p) == 76 )
		goto st441;
	goto tr556;
st441:
	if ( ++p == pe )
		goto _test_eof441;
	/* fall through */
case 441:
	if ( (*p) == 84 )
		goto st442;
	goto tr556;
st442:
	if ( ++p == pe )
		goto _test_eof442;
	/* fall through */
case 442:
	if ( (*p) == 9 )
		goto tr576;
	goto tr556;
tr576:
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st443;
st443:
	if ( ++p == pe )
		goto _test_eof443;
	/* fall through */
case 443:
#line 8221 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 81 )
		goto st444;
	goto tr556;
st444:
	if ( ++p == pe )
		goto _test_eof444;
	/* fall through */
case 444:
	if ( (*p) == 85 )
		goto st445;
	goto tr556;
st445:
	if ( ++p == pe )
		goto _test_eof445;
	/* fall through */
case 445:
	if ( (*p) == 65 )
		goto st446;
	goto tr556;
st446:
	if ( ++p == pe )
		goto _test_eof446;
	/* fall through */
case 446:
	if ( (*p) == 76 )
		goto st447;
	goto tr556;
st447:
	if ( ++p == pe )
		goto _test_eof447;
	/* fall through */
case 447:
	if ( (*p) == 9 )
		goto tr581;
	goto tr556;
tr581:
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
#line 8268 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 70 )
		goto st449;
	goto tr556;
st449:
	if ( ++p == pe )
		goto _test_eof449;
	/* fall through */
case 449:
	if ( (*p) == 73 )
		goto st450;
	goto tr556;
st450:
	if ( ++p == pe )
		goto _test_eof450;
	/* fall through */
case 450:
	if ( (*p) == 76 )
		goto st451;
	goto tr556;
st451:
	if ( ++p == pe )
		goto _test_eof451;
	/* fall through */
case 451:
	if ( (*p) == 84 )
		goto st452;
	goto tr556;
st452:
	if ( ++p == pe )
		goto _test_eof452;
	/* fall through */
case 452:
	if ( (*p) == 69 )
		goto st453;
	goto tr556;
st453:
	if ( ++p == pe )
		goto _test_eof453;
	/* fall through */
case 453:
	if ( (*p) == 82 )
		goto st454;
	goto tr556;
st454:
	if ( ++p == pe )
		goto _test_eof454;
	/* fall through */
case 454:
	if ( (*p) == 9 )
		goto tr588;
	goto tr556;
tr588:
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st455;
st455:
	if ( ++p == pe )
		goto _test_eof455;
	/* fall through */
case 455:
#line 8331 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 73 )
		goto st456;
	goto tr556;
st456:
	if ( ++p == pe )
		goto _test_eof456;
	/* fall through */
case 456:
	if ( (*p) == 78 )
		goto st457;
	goto tr556;
st457:
	if ( ++p == pe )
		goto _test_eof457;
	/* fall through */
case 457:
	if ( (*p) == 70 )
		goto st458;
	goto tr556;
st458:
	if ( ++p == pe )
		goto _test_eof458;
	/* fall through */
case 458:
	if ( (*p) == 79 )
		goto st459;
	goto tr556;
st459:
	if ( ++p == pe )
		goto _test_eof459;
	/* fall through */
case 459:
	switch( (*p) ) {
		case 9: goto tr593;
		case 10: goto tr594;
		case 13: goto tr595;
	}
	goto tr556;
tr593:
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
#line 8381 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 70 )
		goto st461;
	goto tr596;
st461:
	if ( ++p == pe )
		goto _test_eof461;
	/* fall through */
case 461:
	if ( (*p) == 79 )
		goto st462;
	goto tr596;
st462:
	if ( ++p == pe )
		goto _test_eof462;
	/* fall through */
case 462:
	if ( (*p) == 82 )
		goto st463;
	goto tr596;
st463:
	if ( ++p == pe )
		goto _test_eof463;
	/* fall through */
case 463:
	if ( (*p) == 77 )
		goto st464;
	goto tr596;
st464:
	if ( ++p == pe )
		goto _test_eof464;
	/* fall through */
case 464:
	if ( (*p) == 65 )
		goto st465;
	goto tr596;
st465:
	if ( ++p == pe )
		goto _test_eof465;
	/* fall through */
case 465:
	if ( (*p) == 84 )
		goto st466;
	goto tr596;
st466:
	if ( ++p == pe )
		goto _test_eof466;
	/* fall through */
case 466:
	if ( (*p) == 9 )
		goto tr603;
	goto tr596;
tr603:
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st467;
tr605:
#line 204 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_sample_name(*this);
    }
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st467;
st467:
	if ( ++p == pe )
		goto _test_eof467;
	/* fall through */
case 467:
#line 8454 "inc/vcf/validator_detail_v43.hpp"
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr604;
	goto tr596;
tr604:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st468;
tr608:
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
#line 8479 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr605;
		case 10: goto tr606;
		case 13: goto tr607;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr608;
	goto tr596;
tr594:
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
	goto st561;
tr606:
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
	goto st561;
st561:
	if ( ++p == pe )
		goto _test_eof561;
	/* fall through */
case 561:
#line 8537 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 10: goto tr739;
		case 13: goto tr740;
		case 43: goto tr741;
		case 60: goto tr742;
		case 92: goto tr741;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr741;
		} else if ( (*p) >= 33 )
			goto tr741;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr741;
		} else if ( (*p) >= 63 )
			goto tr741;
	} else
		goto tr741;
	goto tr738;
tr743:
#line 43 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st562;
tr739:
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
	goto st562;
st562:
	if ( ++p == pe )
		goto _test_eof562;
	/* fall through */
case 562:
#line 8597 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 10: goto tr743;
		case 13: goto tr744;
	}
	goto st0;
tr744:
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
tr740:
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
	goto st469;
st469:
	if ( ++p == pe )
		goto _test_eof469;
	/* fall through */
case 469:
#line 8640 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 10 )
		goto st562;
	goto st0;
tr750:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st470;
tr613:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st470;
tr741:
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
	goto st470;
st470:
	if ( ++p == pe )
		goto _test_eof470;
	/* fall through */
case 470:
#line 8683 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr612;
		case 43: goto tr613;
		case 92: goto tr613;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr613;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr613;
		} else if ( (*p) >= 63 )
			goto tr613;
	} else
		goto tr613;
	goto tr611;
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
	goto st471;
tr671:
#line 218 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st471;
st471:
	if ( ++p == pe )
		goto _test_eof471;
	/* fall through */
case 471:
#line 8730 "inc/vcf/validator_detail_v43.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr615;
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
	goto st472;
tr617:
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
#line 8755 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 9 )
		goto tr616;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr617;
	goto tr614;
tr622:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st473;
tr616:
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
	goto st473;
st473:
	if ( ++p == pe )
		goto _test_eof473;
	/* fall through */
case 473:
#line 8786 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr619;
	} else if ( (*p) >= 33 )
		goto tr619;
	goto tr618;
tr619:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st474;
tr621:
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
#line 8814 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr620;
		case 59: goto tr622;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr621;
	goto tr618;
tr620:
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
	goto st475;
st475:
	if ( ++p == pe )
		goto _test_eof475;
	/* fall through */
case 475:
#line 8841 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 65: goto tr624;
		case 67: goto tr624;
		case 71: goto tr624;
		case 78: goto tr624;
		case 84: goto tr624;
		case 97: goto tr624;
		case 99: goto tr624;
		case 103: goto tr624;
		case 110: goto tr624;
		case 116: goto tr624;
	}
	goto tr623;
tr624:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st476;
tr626:
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
#line 8876 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr625;
		case 65: goto tr626;
		case 67: goto tr626;
		case 71: goto tr626;
		case 78: goto tr626;
		case 84: goto tr626;
		case 97: goto tr626;
		case 99: goto tr626;
		case 103: goto tr626;
		case 110: goto tr626;
		case 116: goto tr626;
	}
	goto tr623;
tr625:
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
	goto st477;
st477:
	if ( ++p == pe )
		goto _test_eof477;
	/* fall through */
case 477:
#line 8910 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 42: goto tr628;
		case 46: goto tr629;
		case 60: goto tr630;
		case 65: goto tr631;
		case 67: goto tr631;
		case 71: goto tr631;
		case 78: goto tr631;
		case 84: goto tr631;
		case 91: goto tr632;
		case 93: goto tr633;
		case 97: goto tr631;
		case 99: goto tr631;
		case 103: goto tr631;
		case 110: goto tr631;
		case 116: goto tr631;
	}
	goto tr627;
tr628:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st478;
tr693:
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
#line 8950 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr634;
		case 44: goto tr635;
	}
	goto tr627;
tr634:
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
	goto st479;
st479:
	if ( ++p == pe )
		goto _test_eof479;
	/* fall through */
case 479:
#line 8975 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr637;
		case 45: goto tr637;
		case 46: goto tr638;
		case 73: goto tr640;
		case 78: goto tr641;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr639;
	goto tr636;
tr637:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
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
#line 9001 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 73 )
		goto tr643;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr642;
	goto tr636;
tr639:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st481;
tr642:
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
#line 9028 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr644;
		case 46: goto tr645;
		case 69: goto tr646;
		case 101: goto tr646;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr642;
	goto tr636;
tr644:
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
	goto st482;
st482:
	if ( ++p == pe )
		goto _test_eof482;
	/* fall through */
case 482:
#line 9057 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 46: goto tr649;
		case 58: goto tr648;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr648;
		} else if ( (*p) > 57 ) {
			if ( 60 <= (*p) && (*p) <= 64 )
				goto tr648;
		} else
			goto tr650;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr648;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr648;
		} else
			goto tr650;
	} else
		goto tr650;
	goto tr647;
tr648:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st483;
st483:
	if ( ++p == pe )
		goto _test_eof483;
	/* fall through */
case 483:
#line 9094 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 58 )
		goto st483;
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto st483;
		} else if ( (*p) > 57 ) {
			if ( 60 <= (*p) && (*p) <= 64 )
				goto st483;
		} else
			goto tr652;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st483;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st483;
		} else
			goto tr652;
	} else
		goto tr652;
	goto tr647;
tr650:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st484;
tr652:
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
#line 9139 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr653;
		case 59: goto tr654;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr652;
	goto tr647;
tr653:
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
	goto st485;
st485:
	if ( ++p == pe )
		goto _test_eof485;
	/* fall through */
case 485:
#line 9166 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 46: goto tr656;
		case 49: goto tr657;
		case 95: goto tr658;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr658;
	} else if ( (*p) >= 65 )
		goto tr658;
	goto tr655;
tr656:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st563;
st563:
	if ( ++p == pe )
		goto _test_eof563;
	/* fall through */
case 563:
#line 9193 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr746;
		case 10: goto tr747;
		case 13: goto tr748;
	}
	goto tr745;
tr663:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st486;
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
	goto st486;
st486:
	if ( ++p == pe )
		goto _test_eof486;
	/* fall through */
case 486:
#line 9225 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 95 )
		goto tr660;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr660;
	} else if ( (*p) >= 65 )
		goto tr660;
	goto tr659;
tr660:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st487;
tr662:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st487;
st487:
	if ( ++p == pe )
		goto _test_eof487;
	/* fall through */
case 487:
#line 9255 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr661;
		case 37: goto tr662;
		case 46: goto tr662;
		case 58: goto tr663;
		case 95: goto tr662;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr662;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr662;
	} else
		goto tr662;
	goto tr659;
tr661:
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
	goto st488;
st488:
	if ( ++p == pe )
		goto _test_eof488;
	/* fall through */
case 488:
#line 9291 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 46 )
		goto tr666;
	if ( (*p) < 48 ) {
		if ( 33 <= (*p) && (*p) <= 47 )
			goto tr665;
	} else if ( (*p) > 57 ) {
		if ( 59 <= (*p) && (*p) <= 126 )
			goto tr665;
	} else
		goto tr667;
	goto tr664;
tr665:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st564;
tr675:
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
#line 9324 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr661;
		case 10: goto tr747;
		case 13: goto tr748;
		case 58: goto tr749;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr675;
	goto tr674;
tr747:
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
	goto st565;
st565:
	if ( ++p == pe )
		goto _test_eof565;
	/* fall through */
case 565:
#line 9392 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 10: goto tr743;
		case 13: goto tr744;
		case 43: goto tr750;
		case 60: goto st489;
		case 92: goto tr750;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr750;
		} else if ( (*p) >= 33 )
			goto tr750;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr750;
		} else if ( (*p) >= 63 )
			goto tr750;
	} else
		goto tr750;
	goto tr611;
tr742:
#line 70 "src/vcf/vcf.ragel"
	{
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (Error *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
    }
	goto st489;
st489:
	if ( ++p == pe )
		goto _test_eof489;
	/* fall through */
case 489:
#line 9430 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr668;
		case 92: goto tr668;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr668;
		} else if ( (*p) >= 33 )
			goto tr668;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr668;
		} else if ( (*p) >= 63 )
			goto tr668;
	} else
		goto tr668;
	goto tr611;
tr668:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st490;
tr669:
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
#line 9471 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr669;
		case 62: goto tr670;
		case 92: goto tr669;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr669;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr669;
		} else if ( (*p) >= 63 )
			goto tr669;
	} else
		goto tr669;
	goto tr611;
tr670:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st491;
st491:
	if ( ++p == pe )
		goto _test_eof491;
	/* fall through */
case 491:
#line 9500 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 9 )
		goto tr671;
	goto tr611;
tr748:
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
	goto st492;
st492:
	if ( ++p == pe )
		goto _test_eof492;
	/* fall through */
case 492:
#line 9562 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 10 )
		goto st565;
	goto tr672;
tr749:
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
#line 9577 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) > 57 ) {
		if ( 59 <= (*p) && (*p) <= 126 )
			goto tr675;
	} else if ( (*p) >= 33 )
		goto tr675;
	goto tr674;
tr666:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st566;
tr753:
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
#line 9605 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr661;
		case 10: goto tr747;
		case 13: goto tr748;
		case 47: goto tr752;
		case 58: goto tr749;
		case 124: goto tr752;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr675;
	goto tr664;
tr752:
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
#line 9628 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr661;
		case 10: goto tr747;
		case 13: goto tr748;
		case 46: goto tr753;
		case 58: goto tr749;
	}
	if ( (*p) < 48 ) {
		if ( 33 <= (*p) && (*p) <= 47 )
			goto tr675;
	} else if ( (*p) > 57 ) {
		if ( 59 <= (*p) && (*p) <= 126 )
			goto tr675;
	} else
		goto tr754;
	goto tr664;
tr667:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st568;
tr754:
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
#line 9666 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr661;
		case 10: goto tr747;
		case 13: goto tr748;
		case 47: goto tr752;
		case 58: goto tr749;
		case 124: goto tr752;
	}
	if ( (*p) < 48 ) {
		if ( 33 <= (*p) && (*p) <= 46 )
			goto tr675;
	} else if ( (*p) > 57 ) {
		if ( 59 <= (*p) && (*p) <= 126 )
			goto tr675;
	} else
		goto tr754;
	goto tr664;
tr657:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
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
#line 9699 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 48 )
		goto tr676;
	goto tr655;
tr676:
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
#line 9714 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 48 )
		goto tr677;
	goto tr655;
tr677:
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
#line 9729 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 48 )
		goto tr678;
	goto tr655;
tr678:
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
#line 9744 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 71 )
		goto tr679;
	goto tr655;
tr679:
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
#line 9759 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr746;
		case 10: goto tr747;
		case 13: goto tr748;
		case 59: goto tr755;
		case 61: goto tr756;
	}
	goto tr655;
tr755:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st498;
st498:
	if ( ++p == pe )
		goto _test_eof498;
	/* fall through */
case 498:
#line 9779 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 49: goto tr657;
		case 95: goto tr658;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr658;
	} else if ( (*p) >= 65 )
		goto tr658;
	goto tr655;
tr658:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st570;
tr757:
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
#line 9811 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr746;
		case 10: goto tr747;
		case 13: goto tr748;
		case 46: goto tr757;
		case 59: goto tr755;
		case 61: goto tr756;
		case 95: goto tr757;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr757;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr757;
	} else
		goto tr757;
	goto tr655;
tr756:
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
#line 9841 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr681;
	} else if ( (*p) >= 32 )
		goto tr681;
	goto tr680;
tr681:
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
#line 9859 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr746;
		case 10: goto tr747;
		case 13: goto tr748;
		case 59: goto tr755;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr681;
	goto tr680;
tr654:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st500;
st500:
	if ( ++p == pe )
		goto _test_eof500;
	/* fall through */
case 500:
#line 9880 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 58 )
		goto tr648;
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr648;
		} else if ( (*p) > 57 ) {
			if ( 60 <= (*p) && (*p) <= 64 )
				goto tr648;
		} else
			goto tr650;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr648;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr648;
		} else
			goto tr650;
	} else
		goto tr650;
	goto tr647;
tr649:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
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
#line 9919 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr653;
		case 58: goto st483;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto st483;
		} else if ( (*p) > 57 ) {
			if ( 60 <= (*p) && (*p) <= 64 )
				goto st483;
		} else
			goto tr652;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st483;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st483;
		} else
			goto tr652;
	} else
		goto tr652;
	goto tr647;
tr645:
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
#line 9956 "inc/vcf/validator_detail_v43.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr682;
	goto tr636;
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
#line 9971 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr644;
		case 69: goto tr646;
		case 101: goto tr646;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr682;
	goto tr636;
tr646:
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
#line 9991 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr683;
		case 45: goto tr683;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr684;
	goto tr636;
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
#line 10010 "inc/vcf/validator_detail_v43.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr684;
	goto tr636;
tr684:
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
#line 10025 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 9 )
		goto tr644;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr684;
	goto tr636;
tr640:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st507;
tr643:
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
#line 10052 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 110 )
		goto tr685;
	goto tr636;
tr685:
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
#line 10067 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 102 )
		goto tr686;
	goto tr636;
tr638:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st509;
tr686:
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
#line 10092 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 9 )
		goto tr644;
	goto tr636;
tr641:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
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
#line 10111 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 97 )
		goto tr687;
	goto tr636;
tr687:
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
#line 10126 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 78 )
		goto tr686;
	goto tr636;
tr635:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st512;
st512:
	if ( ++p == pe )
		goto _test_eof512;
	/* fall through */
case 512:
#line 10141 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 42: goto tr628;
		case 46: goto tr688;
		case 60: goto tr630;
		case 65: goto tr631;
		case 67: goto tr631;
		case 71: goto tr631;
		case 78: goto tr631;
		case 84: goto tr631;
		case 91: goto tr632;
		case 93: goto tr633;
		case 97: goto tr631;
		case 99: goto tr631;
		case 103: goto tr631;
		case 110: goto tr631;
		case 116: goto tr631;
	}
	goto tr627;
tr688:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st513;
tr717:
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
#line 10181 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 65: goto tr689;
		case 67: goto tr689;
		case 71: goto tr689;
		case 78: goto tr689;
		case 84: goto tr689;
		case 97: goto tr689;
		case 99: goto tr689;
		case 103: goto tr689;
		case 110: goto tr689;
		case 116: goto tr689;
	}
	goto tr627;
tr689:
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
#line 10206 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr634;
		case 44: goto tr635;
		case 65: goto tr689;
		case 67: goto tr689;
		case 71: goto tr689;
		case 78: goto tr689;
		case 84: goto tr689;
		case 97: goto tr689;
		case 99: goto tr689;
		case 103: goto tr689;
		case 110: goto tr689;
		case 116: goto tr689;
	}
	goto tr627;
tr630:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
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
#line 10237 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 42: goto tr691;
		case 61: goto tr690;
	}
	if ( (*p) < 63 ) {
		if ( (*p) < 45 ) {
			if ( 33 <= (*p) && (*p) <= 43 )
				goto tr690;
		} else if ( (*p) > 47 ) {
			if ( (*p) > 57 ) {
				if ( 58 <= (*p) && (*p) <= 59 )
					goto tr690;
			} else if ( (*p) >= 48 )
				goto tr692;
		} else
			goto tr690;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr692;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr690;
			} else if ( (*p) >= 97 )
				goto tr692;
		} else
			goto tr690;
	} else
		goto tr690;
	goto tr627;
tr690:
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
#line 10280 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 61 )
		goto tr690;
	if ( (*p) < 63 ) {
		if ( (*p) < 45 ) {
			if ( 33 <= (*p) && (*p) <= 43 )
				goto tr690;
		} else if ( (*p) > 47 ) {
			if ( (*p) > 57 ) {
				if ( 58 <= (*p) && (*p) <= 59 )
					goto tr690;
			} else if ( (*p) >= 48 )
				goto tr692;
		} else
			goto tr690;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr692;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr690;
			} else if ( (*p) >= 97 )
				goto tr692;
		} else
			goto tr690;
	} else
		goto tr690;
	goto tr627;
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
#line 10321 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 62 )
		goto tr693;
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr692;
	} else if ( (*p) > 59 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr692;
	} else
		goto tr692;
	goto tr627;
tr691:
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
#line 10344 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 62 )
		goto tr693;
	if ( (*p) < 61 ) {
		if ( (*p) < 45 ) {
			if ( 33 <= (*p) && (*p) <= 43 )
				goto tr690;
		} else if ( (*p) > 47 ) {
			if ( (*p) > 57 ) {
				if ( 58 <= (*p) && (*p) <= 59 )
					goto tr690;
			} else if ( (*p) >= 48 )
				goto tr692;
		} else
			goto tr690;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr692;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr690;
			} else if ( (*p) >= 97 )
				goto tr692;
		} else
			goto tr690;
	} else
		goto tr690;
	goto tr627;
tr631:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st519;
tr694:
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
#line 10395 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr634;
		case 44: goto tr635;
		case 46: goto tr693;
		case 65: goto tr694;
		case 67: goto tr694;
		case 71: goto tr694;
		case 78: goto tr694;
		case 84: goto tr694;
		case 91: goto tr695;
		case 93: goto tr696;
		case 97: goto tr694;
		case 99: goto tr694;
		case 103: goto tr694;
		case 110: goto tr694;
		case 116: goto tr694;
	}
	goto tr627;
tr695:
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
#line 10425 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr697;
		case 60: goto tr698;
		case 92: goto tr697;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr697;
		} else if ( (*p) >= 33 )
			goto tr697;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr697;
		} else if ( (*p) >= 63 )
			goto tr697;
	} else
		goto tr697;
	goto tr627;
tr697:
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
#line 10457 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr697;
		case 58: goto tr699;
		case 92: goto tr697;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr697;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr697;
		} else if ( (*p) >= 63 )
			goto tr697;
	} else
		goto tr697;
	goto tr627;
tr699:
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
#line 10486 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr697;
		case 58: goto tr699;
		case 59: goto tr697;
		case 92: goto tr697;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 41 ) {
			if ( 45 <= (*p) && (*p) <= 47 )
				goto tr697;
		} else if ( (*p) >= 33 )
			goto tr697;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr697;
		} else if ( (*p) >= 63 )
			goto tr697;
	} else
		goto tr700;
	goto tr627;
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
#line 10519 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr697;
		case 58: goto tr699;
		case 59: goto tr697;
		case 91: goto tr693;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 41 ) {
			if ( 45 <= (*p) && (*p) <= 47 )
				goto tr697;
		} else if ( (*p) >= 33 )
			goto tr697;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 92 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr697;
		} else if ( (*p) >= 63 )
			goto tr697;
	} else
		goto tr700;
	goto tr627;
tr698:
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
#line 10552 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr701;
		case 92: goto tr701;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr701;
		} else if ( (*p) >= 33 )
			goto tr701;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr701;
		} else if ( (*p) >= 63 )
			goto tr701;
	} else
		goto tr701;
	goto tr627;
tr701:
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
#line 10583 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr701;
		case 62: goto tr702;
		case 92: goto tr701;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr701;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr701;
		} else if ( (*p) >= 63 )
			goto tr701;
	} else
		goto tr701;
	goto tr627;
tr702:
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
#line 10612 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 58 )
		goto tr703;
	goto tr627;
tr703:
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
#line 10627 "inc/vcf/validator_detail_v43.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr704;
	goto tr627;
tr704:
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
#line 10642 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 91 )
		goto tr693;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr704;
	goto tr627;
tr696:
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
#line 10659 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr705;
		case 60: goto tr706;
		case 92: goto tr705;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr705;
		} else if ( (*p) >= 33 )
			goto tr705;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr705;
		} else if ( (*p) >= 63 )
			goto tr705;
	} else
		goto tr705;
	goto tr627;
tr705:
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
#line 10691 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr705;
		case 58: goto tr707;
		case 92: goto tr705;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr705;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr705;
		} else if ( (*p) >= 63 )
			goto tr705;
	} else
		goto tr705;
	goto tr627;
tr707:
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
#line 10720 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr705;
		case 58: goto tr707;
		case 59: goto tr705;
		case 92: goto tr705;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 41 ) {
			if ( 45 <= (*p) && (*p) <= 47 )
				goto tr705;
		} else if ( (*p) >= 33 )
			goto tr705;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr705;
		} else if ( (*p) >= 63 )
			goto tr705;
	} else
		goto tr708;
	goto tr627;
tr708:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st532;
st532:
	if ( ++p == pe )
		goto _test_eof532;
	/* fall through */
case 532:
#line 10753 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr705;
		case 58: goto tr707;
		case 59: goto tr705;
		case 93: goto tr693;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 41 ) {
			if ( 45 <= (*p) && (*p) <= 47 )
				goto tr705;
		} else if ( (*p) >= 33 )
			goto tr705;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 92 <= (*p) && (*p) <= 126 )
				goto tr705;
		} else if ( (*p) >= 63 )
			goto tr705;
	} else
		goto tr708;
	goto tr627;
tr706:
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
#line 10786 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr709;
		case 92: goto tr709;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr709;
		} else if ( (*p) >= 33 )
			goto tr709;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr709;
		} else if ( (*p) >= 63 )
			goto tr709;
	} else
		goto tr709;
	goto tr627;
tr709:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st534;
st534:
	if ( ++p == pe )
		goto _test_eof534;
	/* fall through */
case 534:
#line 10817 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr709;
		case 62: goto tr710;
		case 92: goto tr709;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr709;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr709;
		} else if ( (*p) >= 63 )
			goto tr709;
	} else
		goto tr709;
	goto tr627;
tr710:
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
#line 10846 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 58 )
		goto tr711;
	goto tr627;
tr711:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st536;
st536:
	if ( ++p == pe )
		goto _test_eof536;
	/* fall through */
case 536:
#line 10861 "inc/vcf/validator_detail_v43.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr712;
	goto tr627;
tr712:
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
#line 10876 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 93 )
		goto tr693;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr712;
	goto tr627;
tr632:
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
#line 10897 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr713;
		case 60: goto tr714;
		case 92: goto tr713;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr713;
		} else if ( (*p) >= 33 )
			goto tr713;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr713;
		} else if ( (*p) >= 63 )
			goto tr713;
	} else
		goto tr713;
	goto tr627;
tr713:
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
#line 10929 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr713;
		case 58: goto tr715;
		case 92: goto tr713;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr713;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr713;
		} else if ( (*p) >= 63 )
			goto tr713;
	} else
		goto tr713;
	goto tr627;
tr715:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st540;
st540:
	if ( ++p == pe )
		goto _test_eof540;
	/* fall through */
case 540:
#line 10958 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr713;
		case 58: goto tr715;
		case 59: goto tr713;
		case 92: goto tr713;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 41 ) {
			if ( 45 <= (*p) && (*p) <= 47 )
				goto tr713;
		} else if ( (*p) >= 33 )
			goto tr713;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr713;
		} else if ( (*p) >= 63 )
			goto tr713;
	} else
		goto tr716;
	goto tr627;
tr716:
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
#line 10991 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr713;
		case 58: goto tr715;
		case 59: goto tr713;
		case 91: goto tr717;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 41 ) {
			if ( 45 <= (*p) && (*p) <= 47 )
				goto tr713;
		} else if ( (*p) >= 33 )
			goto tr713;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 92 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr713;
		} else if ( (*p) >= 63 )
			goto tr713;
	} else
		goto tr716;
	goto tr627;
tr714:
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
#line 11024 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr718;
		case 92: goto tr718;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr718;
		} else if ( (*p) >= 33 )
			goto tr718;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr718;
		} else if ( (*p) >= 63 )
			goto tr718;
	} else
		goto tr718;
	goto tr627;
tr718:
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
#line 11055 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr718;
		case 62: goto tr719;
		case 92: goto tr718;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr718;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr718;
		} else if ( (*p) >= 63 )
			goto tr718;
	} else
		goto tr718;
	goto tr627;
tr719:
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
#line 11084 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 58 )
		goto tr720;
	goto tr627;
tr720:
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
#line 11099 "inc/vcf/validator_detail_v43.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr721;
	goto tr627;
tr721:
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
#line 11114 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 91 )
		goto tr717;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr721;
	goto tr627;
tr633:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st547;
st547:
	if ( ++p == pe )
		goto _test_eof547;
	/* fall through */
case 547:
#line 11135 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr722;
		case 60: goto tr723;
		case 92: goto tr722;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr722;
		} else if ( (*p) >= 33 )
			goto tr722;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr722;
		} else if ( (*p) >= 63 )
			goto tr722;
	} else
		goto tr722;
	goto tr627;
tr722:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st548;
st548:
	if ( ++p == pe )
		goto _test_eof548;
	/* fall through */
case 548:
#line 11167 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr722;
		case 58: goto tr724;
		case 92: goto tr722;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr722;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr722;
		} else if ( (*p) >= 63 )
			goto tr722;
	} else
		goto tr722;
	goto tr627;
tr724:
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
#line 11196 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr722;
		case 58: goto tr724;
		case 59: goto tr722;
		case 92: goto tr722;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 41 ) {
			if ( 45 <= (*p) && (*p) <= 47 )
				goto tr722;
		} else if ( (*p) >= 33 )
			goto tr722;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr722;
		} else if ( (*p) >= 63 )
			goto tr722;
	} else
		goto tr725;
	goto tr627;
tr725:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st550;
st550:
	if ( ++p == pe )
		goto _test_eof550;
	/* fall through */
case 550:
#line 11229 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr722;
		case 58: goto tr724;
		case 59: goto tr722;
		case 93: goto tr717;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 41 ) {
			if ( 45 <= (*p) && (*p) <= 47 )
				goto tr722;
		} else if ( (*p) >= 33 )
			goto tr722;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 92 <= (*p) && (*p) <= 126 )
				goto tr722;
		} else if ( (*p) >= 63 )
			goto tr722;
	} else
		goto tr725;
	goto tr627;
tr723:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st551;
st551:
	if ( ++p == pe )
		goto _test_eof551;
	/* fall through */
case 551:
#line 11262 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr726;
		case 92: goto tr726;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr726;
		} else if ( (*p) >= 33 )
			goto tr726;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr726;
		} else if ( (*p) >= 63 )
			goto tr726;
	} else
		goto tr726;
	goto tr627;
tr726:
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
#line 11293 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr726;
		case 62: goto tr727;
		case 92: goto tr726;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr726;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr726;
		} else if ( (*p) >= 63 )
			goto tr726;
	} else
		goto tr726;
	goto tr627;
tr727:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st553;
st553:
	if ( ++p == pe )
		goto _test_eof553;
	/* fall through */
case 553:
#line 11322 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 58 )
		goto tr728;
	goto tr627;
tr728:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st554;
st554:
	if ( ++p == pe )
		goto _test_eof554;
	/* fall through */
case 554:
#line 11337 "inc/vcf/validator_detail_v43.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr729;
	goto tr627;
tr729:
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
#line 11352 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 93 )
		goto tr717;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr729;
	goto tr627;
tr629:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st556;
st556:
	if ( ++p == pe )
		goto _test_eof556;
	/* fall through */
case 556:
#line 11373 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr634;
		case 65: goto tr689;
		case 67: goto tr689;
		case 71: goto tr689;
		case 78: goto tr689;
		case 84: goto tr689;
		case 97: goto tr689;
		case 99: goto tr689;
		case 103: goto tr689;
		case 110: goto tr689;
		case 116: goto tr689;
	}
	goto tr627;
tr595:
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
	goto st557;
tr607:
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
	goto st557;
st557:
	if ( ++p == pe )
		goto _test_eof557;
	/* fall through */
case 557:
#line 11437 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 10 )
		goto st561;
	goto tr596;
tr23:
#line 99 "src/vcf/vcf.ragel"
	{
        try {
          ParsePolicy::handle_fileformat(*this);
        } catch (Error *error) {
          ErrorPolicy::handle_error(*this, error);
          p--; {goto st559;}
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
	goto st558;
st558:
	if ( ++p == pe )
		goto _test_eof558;
	/* fall through */
case 558:
#line 11467 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 10 )
		goto st22;
	goto tr0;
tr734:
#line 43 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st559;
st559:
	if ( ++p == pe )
		goto _test_eof559;
	/* fall through */
case 559:
#line 11488 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 10: goto tr733;
		case 13: goto tr734;
	}
	goto st559;
tr733:
#line 43 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
#line 261 "src/vcf/vcf_v43.ragel"
	{ {goto st28;} }
	goto st572;
st572:
	if ( ++p == pe )
		goto _test_eof572;
	/* fall through */
case 572:
#line 11513 "inc/vcf/validator_detail_v43.hpp"
	goto st0;
tr737:
#line 43 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st560;
st560:
	if ( ++p == pe )
		goto _test_eof560;
	/* fall through */
case 560:
#line 11532 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 10: goto tr736;
		case 13: goto tr737;
	}
	goto st560;
tr736:
#line 43 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
#line 262 "src/vcf/vcf_v43.ragel"
	{ {goto st565;} }
	goto st573;
st573:
	if ( ++p == pe )
		goto _test_eof573;
	/* fall through */
case 573:
#line 11557 "inc/vcf/validator_detail_v43.hpp"
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
	_test_eof561: cs = 561; goto _test_eof; 
	_test_eof562: cs = 562; goto _test_eof; 
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
	_test_eof563: cs = 563; goto _test_eof; 
	_test_eof486: cs = 486; goto _test_eof; 
	_test_eof487: cs = 487; goto _test_eof; 
	_test_eof488: cs = 488; goto _test_eof; 
	_test_eof564: cs = 564; goto _test_eof; 
	_test_eof565: cs = 565; goto _test_eof; 
	_test_eof489: cs = 489; goto _test_eof; 
	_test_eof490: cs = 490; goto _test_eof; 
	_test_eof491: cs = 491; goto _test_eof; 
	_test_eof492: cs = 492; goto _test_eof; 
	_test_eof493: cs = 493; goto _test_eof; 
	_test_eof566: cs = 566; goto _test_eof; 
	_test_eof567: cs = 567; goto _test_eof; 
	_test_eof568: cs = 568; goto _test_eof; 
	_test_eof494: cs = 494; goto _test_eof; 
	_test_eof495: cs = 495; goto _test_eof; 
	_test_eof496: cs = 496; goto _test_eof; 
	_test_eof497: cs = 497; goto _test_eof; 
	_test_eof569: cs = 569; goto _test_eof; 
	_test_eof498: cs = 498; goto _test_eof; 
	_test_eof570: cs = 570; goto _test_eof; 
	_test_eof499: cs = 499; goto _test_eof; 
	_test_eof571: cs = 571; goto _test_eof; 
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
	_test_eof572: cs = 572; goto _test_eof; 
	_test_eof560: cs = 560; goto _test_eof; 
	_test_eof573: cs = 573; goto _test_eof; 

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
	case 558: 
#line 60 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new FileformatError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
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
               goto _test_eof559;
goto st559;}
    }
	break;
	case 561: 
#line 70 "src/vcf/vcf.ragel"
	{
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (Error *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
    }
	break;
	case 557: 
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
               goto _test_eof560;
goto st560;}
    }
	break;
	case 492: 
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof560;
goto st560;}
    }
	break;
	case 48: 
	case 49: 
	case 50: 
	case 51: 
	case 52: 
	case 53: 
	case 54: 
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
	case 77: 
	case 78: 
	case 79: 
#line 259 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
	break;
	case 342: 
	case 343: 
	case 344: 
	case 345: 
	case 346: 
	case 347: 
	case 348: 
	case 349: 
#line 271 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in assembly metadata"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
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
#line 277 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in contig metadata"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
	break;
	case 81: 
	case 82: 
	case 83: 
	case 84: 
	case 85: 
	case 86: 
	case 87: 
	case 88: 
	case 89: 
	case 93: 
	case 94: 
	case 95: 
	case 96: 
	case 97: 
	case 98: 
	case 99: 
	case 100: 
	case 101: 
	case 102: 
	case 103: 
	case 104: 
	case 105: 
	case 112: 
	case 113: 
	case 114: 
#line 283 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
	break;
	case 115: 
	case 116: 
	case 117: 
	case 118: 
	case 119: 
	case 120: 
	case 121: 
	case 122: 
	case 123: 
	case 127: 
	case 128: 
	case 129: 
	case 130: 
	case 131: 
	case 132: 
	case 133: 
	case 136: 
	case 137: 
	case 138: 
	case 139: 
	case 140: 
	case 143: 
	case 144: 
	case 145: 
	case 146: 
	case 147: 
	case 148: 
	case 149: 
	case 150: 
	case 151: 
	case 152: 
	case 153: 
	case 154: 
	case 155: 
	case 162: 
	case 163: 
	case 164: 
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
	break;
	case 166: 
	case 167: 
	case 168: 
	case 169: 
	case 170: 
	case 171: 
	case 172: 
	case 173: 
	case 177: 
	case 178: 
	case 179: 
	case 180: 
	case 181: 
	case 182: 
	case 183: 
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
	case 198: 
	case 199: 
	case 200: 
	case 201: 
	case 202: 
	case 203: 
	case 204: 
	case 205: 
	case 212: 
	case 213: 
	case 214: 
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
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
	case 271: 
	case 272: 
	case 273: 
	case 278: 
	case 279: 
	case 280: 
	case 281: 
	case 282: 
	case 283: 
	case 287: 
	case 288: 
	case 289: 
	case 290: 
	case 291: 
	case 292: 
	case 293: 
	case 297: 
	case 308: 
	case 309: 
	case 310: 
	case 311: 
	case 312: 
	case 313: 
	case 314: 
	case 315: 
#line 311 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
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
#line 332 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in pedigreeDB metadata"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
	break;
	case 216: 
	case 217: 
	case 218: 
	case 219: 
	case 220: 
	case 221: 
	case 222: 
	case 223: 
	case 227: 
	case 228: 
	case 229: 
	case 230: 
	case 231: 
	case 232: 
	case 233: 
	case 236: 
	case 237: 
	case 238: 
	case 239: 
	case 240: 
	case 248: 
	case 249: 
	case 250: 
	case 251: 
	case 252: 
	case 253: 
	case 254: 
	case 255: 
	case 256: 
	case 258: 
	case 259: 
	case 261: 
#line 338 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
	break;
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
#line 359 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
	break;
	case 470: 
	case 489: 
	case 490: 
	case 491: 
#line 408 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new ChromosomeBodyError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof560;
goto st560;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof560;
goto st560;}
    }
	break;
	case 471: 
	case 472: 
#line 414 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new PositionBodyError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof560;
goto st560;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof560;
goto st560;}
    }
	break;
	case 473: 
	case 474: 
#line 420 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new IdBodyError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof560;
goto st560;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof560;
goto st560;}
    }
	break;
	case 475: 
	case 476: 
#line 426 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new ReferenceAlleleBodyError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof560;
goto st560;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof560;
goto st560;}
    }
	break;
	case 477: 
	case 478: 
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
	case 532: 
	case 533: 
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
#line 432 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new AlternateAllelesBodyError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof560;
goto st560;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof560;
goto st560;}
    }
	break;
	case 479: 
	case 480: 
	case 481: 
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
#line 438 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new QualityBodyError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof560;
goto st560;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof560;
goto st560;}
    }
	break;
	case 482: 
	case 483: 
	case 484: 
	case 500: 
	case 501: 
#line 444 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new FilterBodyError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof560;
goto st560;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof560;
goto st560;}
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
#line 29 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this,
                new FileformatError{n_lines, "The fileformat declaration is not 'fileformat=VCFv4.3'"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 60 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new FileformatError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
	break;
	case 486: 
	case 487: 
#line 50 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new FormatBodyError{n_lines, "Format does not start with a letter/underscore followed by alphanumeric/underscore/dot characters"});
        p--; {       if ( p == pe )
               goto _test_eof560;
goto st560;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof560;
goto st560;}
    }
	break;
	case 460: 
	case 461: 
	case 462: 
	case 463: 
	case 464: 
	case 465: 
	case 466: 
	case 467: 
	case 468: 
#line 55 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {       if ( p == pe )
               goto _test_eof560;
goto st560;}
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
               goto _test_eof560;
goto st560;}
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
               goto _test_eof559;
goto st559;}
    }
#line 259 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
	break;
	case 80: 
#line 283 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
	break;
	case 141: 
	case 142: 
#line 305 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "INFO metadata Type is not Integer, Float, Flag, Character or String"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
	break;
	case 191: 
	case 192: 
#line 305 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "INFO metadata Type is not Integer, Float, Flag, Character or String"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
	break;
	case 316: 
	case 317: 
	case 318: 
#line 316 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "PEDIGREE metadata Original is not valid"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 311 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
	break;
	case 284: 
	case 285: 
	case 286: 
	case 294: 
	case 295: 
	case 296: 
#line 321 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "PEDIGREE metadata Father or Mother is not valid"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 311 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
	break;
	case 277: 
	case 298: 
	case 299: 
	case 300: 
	case 301: 
	case 302: 
	case 303: 
	case 304: 
	case 305: 
	case 306: 
	case 307: 
#line 326 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "PEDIGREE metadata sequence of Name_N is not valid"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 311 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
	break;
	case 234: 
	case 235: 
#line 343 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "META metadata Number is not a dot"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 338 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
	break;
	case 241: 
	case 242: 
	case 243: 
	case 244: 
	case 245: 
	case 246: 
	case 247: 
#line 348 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "META metadata Type is not String"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 338 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
	break;
	case 257: 
	case 260: 
#line 353 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "META metadata Values is not a square-bracket delimited list of values"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 338 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
	break;
	case 74: 
	case 75: 
	case 76: 
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 259 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
	break;
	case 379: 
	case 380: 
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 277 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in contig metadata"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
	break;
	case 90: 
	case 91: 
	case 92: 
	case 109: 
	case 110: 
	case 111: 
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 283 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
	break;
	case 124: 
	case 125: 
	case 126: 
	case 159: 
	case 160: 
	case 161: 
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
	break;
	case 174: 
	case 175: 
	case 176: 
	case 209: 
	case 210: 
	case 211: 
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
	break;
	case 274: 
	case 275: 
	case 276: 
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 311 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
	break;
	case 224: 
	case 225: 
	case 226: 
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 338 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
	break;
	case 329: 
	case 330: 
	case 331: 
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 359 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
	break;
	case 71: 
	case 72: 
	case 73: 
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 259 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
	break;
	case 106: 
	case 107: 
	case 108: 
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 283 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
	break;
	case 156: 
	case 157: 
	case 158: 
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
	break;
	case 206: 
	case 207: 
	case 208: 
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
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
	case 361: 
	case 362: 
	case 363: 
	case 364: 
	case 365: 
	case 366: 
	case 367: 
	case 368: 
#line 385 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata URL is not valid"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 271 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in assembly metadata"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
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
#line 385 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata URL is not valid"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 332 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in pedigreeDB metadata"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
	break;
	case 134: 
	case 135: 
	case 165: 
#line 36 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "FORMAT metadata Number is not a number, A, R, G or dot"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
	break;
	case 184: 
	case 185: 
	case 215: 
#line 42 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "INFO metadata Number is not a number, A, R, G or dot"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
	break;
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
	case 435: 
	case 436: 
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
	case 456: 
	case 457: 
	case 458: 
	case 459: 
#line 55 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {       if ( p == pe )
               goto _test_eof560;
goto st560;}
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
               goto _test_eof560;
goto st560;}
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
               goto _test_eof560;
goto st560;}
    }
	break;
	case 493: 
#line 55 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {       if ( p == pe )
               goto _test_eof560;
goto st560;}
    }
#line 466 "src/vcf/vcf.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " is not a valid string";
        ErrorPolicy::handle_error(*this, new SamplesBodyError{n_lines, message_stream.str()});
        p--; {       if ( p == pe )
               goto _test_eof560;
goto st560;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof560;
goto st560;}
    }
	break;
	case 563: 
	case 564: 
	case 569: 
	case 570: 
	case 571: 
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 218 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 55 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {       if ( p == pe )
               goto _test_eof560;
goto st560;}
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
               goto _test_eof559;
goto st559;}
    }
#line 55 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {       if ( p == pe )
               goto _test_eof560;
goto st560;}
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
               goto _test_eof560;
goto st560;}
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
               goto _test_eof560;
goto st560;}
    }
	break;
	case 485: 
	case 494: 
	case 495: 
	case 496: 
	case 497: 
	case 498: 
#line 455 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info key is not a sequence of alphanumeric and/or punctuation characters"});
        p--; {       if ( p == pe )
               goto _test_eof560;
goto st560;}
    }
#line 55 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {       if ( p == pe )
               goto _test_eof560;
goto st560;}
    }
#line 450 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {       if ( p == pe )
               goto _test_eof560;
goto st560;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof560;
goto st560;}
    }
	break;
	case 499: 
#line 460 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info field value is not a comma-separated list of valid strings (maybe it contains whitespaces?)"});
        p--; {       if ( p == pe )
               goto _test_eof560;
goto st560;}
    }
#line 55 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {       if ( p == pe )
               goto _test_eof560;
goto st560;}
    }
#line 450 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {       if ( p == pe )
               goto _test_eof560;
goto st560;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof560;
goto st560;}
    }
	break;
	case 566: 
	case 567: 
	case 568: 
#line 55 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {       if ( p == pe )
               goto _test_eof560;
goto st560;}
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
	case 488: 
#line 55 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {       if ( p == pe )
               goto _test_eof560;
goto st560;}
    }
#line 473 "src/vcf/vcf.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " does not start with a valid genotype";
        ErrorPolicy::handle_error(*this, new SamplesFieldBodyError{n_lines, message_stream.str(), "", "GT"});
        p--; {       if ( p == pe )
               goto _test_eof560;
goto st560;}
    }
#line 466 "src/vcf/vcf.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " is not a valid string";
        ErrorPolicy::handle_error(*this, new SamplesBodyError{n_lines, message_stream.str()});
        p--; {       if ( p == pe )
               goto _test_eof560;
goto st560;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof560;
goto st560;}
    }
	break;
	case 22: 
#line 60 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new FileformatError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 55 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {       if ( p == pe )
               goto _test_eof560;
goto st560;}
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
               goto _test_eof560;
goto st560;}
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
               goto _test_eof560;
goto st560;}
    }
	break;
	case 24: 
#line 259 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 283 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 271 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in assembly metadata"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 277 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in contig metadata"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 338 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 359 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 311 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 332 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in pedigreeDB metadata"});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof559;
goto st559;}
    }
	break;
#line 14063 "inc/vcf/validator_detail_v43.hpp"
	}
	}

	_out: {}
	}

#line 291 "src/vcf/vcf_v43.ragel"

    }

  }
}
