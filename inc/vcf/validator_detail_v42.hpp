
#line 1 "src/vcf/vcf_v42.ragel"
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


#line 233 "src/vcf/vcf_v42.ragel"


namespace
{
  
#line 22 "inc/vcf/validator_detail_v42.hpp"
static const int vcf_v42_start = 1;
static const int vcf_v42_first_final = 506;
static const int vcf_v42_error = 0;

static const int vcf_v42_en_main = 1;
static const int vcf_v42_en_main_meta_section = 28;
static const int vcf_v42_en_main_body_section = 510;
static const int vcf_v42_en_meta_section_skip = 504;
static const int vcf_v42_en_body_section_skip = 505;


#line 239 "src/vcf/vcf_v42.ragel"

}

namespace ebi
{
  namespace vcf
  {

    template <typename Configuration>
    ParserImpl_v42<Configuration>::ParserImpl_v42(std::shared_ptr<Source> source, AdditionalChecks additionalChecks)
    : ParserImpl{source, additionalChecks}
    {
      
#line 44 "inc/vcf/validator_detail_v42.hpp"
	{
	cs = vcf_v42_start;
	}

#line 253 "src/vcf/vcf_v42.ragel"

    }

    template <typename Configuration>
    void ParserImpl_v42<Configuration>::parse_buffer(char const * p, char const * pe, char const * eof)
    {
      
#line 53 "inc/vcf/validator_detail_v42.hpp"
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
#line 60 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new FileformatError{n_lines});
        p--; {goto st504;}
    }
	goto st0;
tr14:
#line 29 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this,
                new FileformatError{n_lines, "The fileformat declaration is not 'fileformat=VCFv4.2'"});
        p--; {goto st504;}
    }
#line 60 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new FileformatError{n_lines});
        p--; {goto st504;}
    }
	goto st0;
tr24:
#line 60 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new FileformatError{n_lines});
        p--; {goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st504;}
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
        
        p--; {goto st505;}
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
        
        p--; {goto st505;}
    }
	goto st0;
tr26:
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st504;}
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
        
        p--; {goto st505;}
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
        
        p--; {goto st505;}
    }
	goto st0;
tr29:
#line 259 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {goto st504;}
    }
#line 283 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {goto st504;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st504;}
    }
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st504;}
    }
#line 271 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in assembly metadata"});
        p--; {goto st504;}
    }
#line 277 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in contig metadata"});
        p--; {goto st504;}
    }
#line 359 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st504;}
    }
#line 311 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {goto st504;}
    }
#line 332 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in pedigreeDB metadata"});
        p--; {goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st504;}
    }
	goto st0;
tr39:
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st504;}
    }
	goto st0;
tr81:
#line 259 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st504;}
    }
	goto st0;
tr89:
#line 264 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines,
               "ALT metadata ID is not prefixed by DEL/INS/DUP/INV/CNV" + (source->version < Version::v44 ? std::string("/BND") : std::string("")) + " and suffixed by ':' and a text sequence"});
        p--; {goto st504;}
    }
#line 259 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st504;}
    }
	goto st0;
tr108:
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st504;}
    }
#line 259 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st504;}
    }
	goto st0;
tr117:
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {goto st504;}
    }
#line 259 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st504;}
    }
	goto st0;
tr124:
#line 283 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {goto st504;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st504;}
    }
	goto st0;
tr127:
#line 283 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st504;}
    }
	goto st0;
tr137:
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {goto st504;}
    }
#line 283 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st504;}
    }
	goto st0;
tr156:
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st504;}
    }
#line 283 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st504;}
    }
	goto st0;
tr171:
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st504;}
    }
	goto st0;
tr181:
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {goto st504;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st504;}
    }
	goto st0;
tr194:
#line 36 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "FORMAT metadata Number is not a number, A, R, G or dot"});
        p--; {goto st504;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st504;}
    }
	goto st0;
tr203:
#line 305 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "INFO metadata Type is not Integer, Float, Flag, Character or String"});
        p--; {goto st504;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st504;}
    }
	goto st0;
tr220:
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st504;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st504;}
    }
	goto st0;
tr236:
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st504;}
    }
	goto st0;
tr245:
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {goto st504;}
    }
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st504;}
    }
	goto st0;
tr258:
#line 42 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "INFO metadata Number is not a number, A, R, G or dot"});
        p--; {goto st504;}
    }
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st504;}
    }
	goto st0;
tr267:
#line 305 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "INFO metadata Type is not Integer, Float, Flag, Character or String"});
        p--; {goto st504;}
    }
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st504;}
    }
	goto st0;
tr284:
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st504;}
    }
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st504;}
    }
	goto st0;
tr300:
#line 311 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st504;}
    }
	goto st0;
tr310:
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {goto st504;}
    }
#line 311 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st504;}
    }
	goto st0;
tr322:
#line 359 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st504;}
    }
	goto st0;
tr333:
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {goto st504;}
    }
#line 359 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st504;}
    }
	goto st0;
tr338:
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {goto st504;}
    }
#line 364 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "SAMPLE metadata Genomes is not a valid string (maybe it contains quotes?)"});
        p--; {goto st504;}
    }
#line 359 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st504;}
    }
	goto st0;
tr340:
#line 364 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "SAMPLE metadata Genomes is not a valid string (maybe it contains quotes?)"});
        p--; {goto st504;}
    }
#line 359 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st504;}
    }
	goto st0;
tr350:
#line 364 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "SAMPLE metadata Genomes is not a valid string (maybe it contains quotes?)"});
        p--; {goto st504;}
    }
#line 369 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "SAMPLE metadata Mixture is not a valid string (maybe it contains quotes?)"});
        p--; {goto st504;}
    }
#line 359 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st504;}
    }
	goto st0;
tr353:
#line 369 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "SAMPLE metadata Mixture is not a valid string (maybe it contains quotes?)"});
        p--; {goto st504;}
    }
#line 359 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st504;}
    }
	goto st0;
tr363:
#line 369 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "SAMPLE metadata Mixture is not a valid string (maybe it contains quotes?)"});
        p--; {goto st504;}
    }
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st504;}
    }
#line 359 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st504;}
    }
	goto st0;
tr366:
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st504;}
    }
#line 359 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st504;}
    }
	goto st0;
tr387:
#line 271 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in assembly metadata"});
        p--; {goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st504;}
    }
	goto st0;
tr396:
#line 385 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata URL is not valid"});
        p--; {goto st504;}
    }
#line 271 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in assembly metadata"});
        p--; {goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st504;}
    }
	goto st0;
tr417:
#line 277 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in contig metadata"});
        p--; {goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st504;}
    }
	goto st0;
tr428:
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {goto st504;}
    }
#line 277 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in contig metadata"});
        p--; {goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st504;}
    }
	goto st0;
tr449:
#line 332 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in pedigreeDB metadata"});
        p--; {goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st504;}
    }
	goto st0;
tr461:
#line 385 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata URL is not valid"});
        p--; {goto st504;}
    }
#line 332 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in pedigreeDB metadata"});
        p--; {goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st504;}
    }
	goto st0;
tr484:
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
        
        p--; {goto st505;}
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
        
        p--; {goto st505;}
    }
	goto st0;
tr524:
#line 78 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new HeaderSectionError{n_lines});
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (Error *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
        
        p--; {goto st505;}
    }
	goto st0;
tr539:
#line 408 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new ChromosomeBodyError{n_lines});
        p--; {goto st505;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st505;}
    }
	goto st0;
tr542:
#line 414 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new PositionBodyError{n_lines});
        p--; {goto st505;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st505;}
    }
	goto st0;
tr546:
#line 420 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new IdBodyError{n_lines});
        p--; {goto st505;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st505;}
    }
	goto st0;
tr551:
#line 426 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new ReferenceAlleleBodyError{n_lines});
        p--; {goto st505;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st505;}
    }
	goto st0;
tr555:
#line 432 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new AlternateAllelesBodyError{n_lines});
        p--; {goto st505;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st505;}
    }
	goto st0;
tr564:
#line 438 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new QualityBodyError{n_lines});
        p--; {goto st505;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st505;}
    }
	goto st0;
tr575:
#line 444 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new FilterBodyError{n_lines});
        p--; {goto st505;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st505;}
    }
	goto st0;
tr583:
#line 455 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info key is not a sequence of alphanumeric and/or punctuation characters"});
        p--; {goto st505;}
    }
#line 450 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st505;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st505;}
    }
	goto st0;
tr587:
#line 50 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new FormatBodyError{n_lines});
        p--; {goto st505;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st505;}
    }
	goto st0;
tr592:
#line 473 "src/vcf/vcf.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " does not start with a valid genotype";
        ErrorPolicy::handle_error(*this, new SamplesFieldBodyError{n_lines, message_stream.str(), "", "GT"});
        p--; {goto st505;}
    }
#line 466 "src/vcf/vcf.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " is not a valid string";
        ErrorPolicy::handle_error(*this, new SamplesBodyError{n_lines, message_stream.str()});
        p--; {goto st505;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st505;}
    }
	goto st0;
tr600:
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st505;}
    }
	goto st0;
tr602:
#line 466 "src/vcf/vcf.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " is not a valid string";
        ErrorPolicy::handle_error(*this, new SamplesBodyError{n_lines, message_stream.str()});
        p--; {goto st505;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st505;}
    }
	goto st0;
tr608:
#line 460 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info field value is not a comma-separated list of valid strings (maybe it contains whitespaces?)"});
        p--; {goto st505;}
    }
#line 450 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st505;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st505;}
    }
	goto st0;
tr671:
#line 78 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new HeaderSectionError{n_lines});
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (Error *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
        
        p--; {goto st505;}
    }
#line 408 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new ChromosomeBodyError{n_lines});
        p--; {goto st505;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st505;}
    }
	goto st0;
tr678:
#line 450 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st505;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st505;}
    }
	goto st0;
#line 863 "inc/vcf/validator_detail_v42.hpp"
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
case 15:
#line 969 "inc/vcf/validator_detail_v42.hpp"
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
case 16:
#line 981 "inc/vcf/validator_detail_v42.hpp"
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
case 17:
#line 993 "inc/vcf/validator_detail_v42.hpp"
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
case 18:
#line 1005 "inc/vcf/validator_detail_v42.hpp"
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
case 19:
#line 1017 "inc/vcf/validator_detail_v42.hpp"
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
case 20:
#line 1029 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 50 )
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
case 21:
#line 1041 "inc/vcf/validator_detail_v42.hpp"
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
          p--; {goto st504;}
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
case 22:
#line 1069 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 35 )
		goto st23;
	goto tr24;
st23:
	if ( ++p == pe )
		goto _test_eof23;
case 23:
	switch( (*p) ) {
		case 35: goto st24;
		case 67: goto st364;
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
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st25;
tr40:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st25;
st25:
	if ( ++p == pe )
		goto _test_eof25;
case 25:
#line 1118 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 61 )
		goto tr41;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr39;
tr41:
#line 188 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this);
    }
	goto st26;
st26:
	if ( ++p == pe )
		goto _test_eof26;
case 26:
#line 1132 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto st30;
		case 60: goto st34;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr42;
	goto tr39;
tr42:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st27;
tr47:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st27;
st27:
	if ( ++p == pe )
		goto _test_eof27;
case 27:
#line 1156 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 10: goto tr45;
		case 13: goto tr46;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr47;
	goto tr39;
tr45:
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
tr55:
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
case 28:
#line 1206 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 35 )
		goto st23;
	goto tr26;
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
	goto st29;
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
	goto st29;
st29:
	if ( ++p == pe )
		goto _test_eof29;
case 29:
#line 1252 "inc/vcf/validator_detail_v42.hpp"
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
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st31;
tr52:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st31;
st31:
	if ( ++p == pe )
		goto _test_eof31;
case 31:
#line 1283 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr53;
		case 92: goto tr54;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr52;
	goto tr39;
tr50:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st32;
tr53:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st32;
st32:
	if ( ++p == pe )
		goto _test_eof32;
case 32:
#line 1307 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 10: goto tr55;
		case 13: goto tr56;
	}
	goto tr39;
tr51:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st33;
tr54:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st33;
st33:
	if ( ++p == pe )
		goto _test_eof33;
case 33:
#line 1329 "inc/vcf/validator_detail_v42.hpp"
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr52;
	goto tr39;
st34:
	if ( ++p == pe )
		goto _test_eof34;
case 34:
	switch( (*p) ) {
		case 34: goto st35;
		case 95: goto tr58;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr58;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr59;
		} else if ( (*p) >= 65 )
			goto tr59;
	} else
		goto tr59;
	goto tr39;
st35:
	if ( ++p == pe )
		goto _test_eof35;
case 35:
	switch( (*p) ) {
		case 34: goto tr61;
		case 92: goto tr62;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr60;
	goto tr39;
tr60:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st36;
tr63:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st36;
st36:
	if ( ++p == pe )
		goto _test_eof36;
case 36:
#line 1380 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr64;
		case 92: goto tr65;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr63;
	goto tr39;
tr61:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st37;
tr64:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st37;
st37:
	if ( ++p == pe )
		goto _test_eof37;
case 37:
#line 1404 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 62 )
		goto st32;
	goto tr39;
tr62:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st38;
tr65:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st38;
st38:
	if ( ++p == pe )
		goto _test_eof38;
case 38:
#line 1424 "inc/vcf/validator_detail_v42.hpp"
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr63;
	goto tr39;
tr58:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st39;
st39:
	if ( ++p == pe )
		goto _test_eof39;
case 39:
#line 1436 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 95 )
		goto st39;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st39;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr68;
		} else if ( (*p) >= 65 )
			goto tr68;
	} else
		goto tr68;
	goto tr39;
tr59:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st40;
tr68:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st40;
st40:
	if ( ++p == pe )
		goto _test_eof40;
case 40:
#line 1467 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr69;
		case 95: goto tr68;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr68;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr68;
		} else if ( (*p) >= 65 )
			goto tr68;
	} else
		goto tr68;
	goto tr39;
tr69:
#line 192 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st41;
st41:
	if ( ++p == pe )
		goto _test_eof41;
case 41:
#line 1492 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 34 )
		goto st44;
	if ( (*p) < 45 ) {
		if ( 32 <= (*p) && (*p) <= 43 )
			goto tr70;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr70;
	} else
		goto tr70;
	goto tr39;
tr70:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st42;
tr72:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st42;
st42:
	if ( ++p == pe )
		goto _test_eof42;
case 42:
#line 1520 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 44: goto tr73;
		case 62: goto tr53;
	}
	if ( (*p) > 33 ) {
		if ( 35 <= (*p) && (*p) <= 126 )
			goto tr72;
	} else if ( (*p) >= 32 )
		goto tr72;
	goto tr39;
tr73:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st43;
st43:
	if ( ++p == pe )
		goto _test_eof43;
case 43:
#line 1539 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 95 )
		goto tr58;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr58;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr59;
		} else if ( (*p) >= 65 )
			goto tr59;
	} else
		goto tr59;
	goto tr39;
st44:
	if ( ++p == pe )
		goto _test_eof44;
case 44:
	switch( (*p) ) {
		case 34: goto tr75;
		case 92: goto tr76;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr74;
	goto tr39;
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
tr77:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st45;
st45:
	if ( ++p == pe )
		goto _test_eof45;
case 45:
#line 1581 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr78;
		case 92: goto tr79;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr77;
	goto tr39;
tr75:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st46;
tr78:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st46;
st46:
	if ( ++p == pe )
		goto _test_eof46;
case 46:
#line 1605 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 44: goto st43;
		case 62: goto st32;
	}
	goto tr39;
tr76:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st47;
tr79:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st47;
st47:
	if ( ++p == pe )
		goto _test_eof47;
case 47:
#line 1627 "inc/vcf/validator_detail_v42.hpp"
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr77;
	goto tr39;
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
case 48:
#line 1642 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 76: goto tr82;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr81;
tr82:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st49;
st49:
	if ( ++p == pe )
		goto _test_eof49;
case 49:
#line 1658 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 84: goto st50;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr81;
st50:
	if ( ++p == pe )
		goto _test_eof50;
case 50:
	if ( (*p) == 61 )
		goto tr84;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr81;
tr84:
#line 108 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "ALT");
    }
	goto st51;
st51:
	if ( ++p == pe )
		goto _test_eof51;
case 51:
#line 1683 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 60 )
		goto st52;
	goto tr81;
st52:
	if ( ++p == pe )
		goto _test_eof52;
case 52:
	if ( (*p) == 73 )
		goto st53;
	goto tr81;
st53:
	if ( ++p == pe )
		goto _test_eof53;
case 53:
	if ( (*p) == 68 )
		goto st54;
	goto tr81;
st54:
	if ( ++p == pe )
		goto _test_eof54;
case 54:
	if ( (*p) == 61 )
		goto st55;
	goto tr81;
st55:
	if ( ++p == pe )
		goto _test_eof55;
case 55:
	if ( (*p) == 61 )
		goto tr90;
	if ( (*p) < 63 ) {
		if ( (*p) < 45 ) {
			if ( 33 <= (*p) && (*p) <= 43 )
				goto tr90;
		} else if ( (*p) > 47 ) {
			if ( (*p) > 57 ) {
				if ( 58 <= (*p) && (*p) <= 59 )
					goto tr90;
			} else if ( (*p) >= 48 )
				goto tr91;
		} else
			goto tr90;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr91;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr90;
			} else if ( (*p) >= 97 )
				goto tr91;
		} else
			goto tr90;
	} else
		goto tr90;
	goto tr89;
tr90:
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
case 56:
#line 1752 "inc/vcf/validator_detail_v42.hpp"
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
				goto tr93;
		} else
			goto st56;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr93;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto st56;
			} else if ( (*p) >= 97 )
				goto tr93;
		} else
			goto st56;
	} else
		goto st56;
	goto tr89;
tr93:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st57;
tr91:
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
case 57:
#line 1801 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 44: goto tr94;
		case 61: goto tr93;
	}
	if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr93;
	} else if ( (*p) >= 33 )
		goto tr93;
	goto tr89;
tr94:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st58;
st58:
	if ( ++p == pe )
		goto _test_eof58;
case 58:
#line 1820 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 68 )
		goto st59;
	goto tr81;
st59:
	if ( ++p == pe )
		goto _test_eof59;
case 59:
	if ( (*p) == 101 )
		goto st60;
	goto tr81;
st60:
	if ( ++p == pe )
		goto _test_eof60;
case 60:
	if ( (*p) == 115 )
		goto st61;
	goto tr81;
st61:
	if ( ++p == pe )
		goto _test_eof61;
case 61:
	if ( (*p) == 99 )
		goto st62;
	goto tr81;
st62:
	if ( ++p == pe )
		goto _test_eof62;
case 62:
	if ( (*p) == 114 )
		goto st63;
	goto tr81;
st63:
	if ( ++p == pe )
		goto _test_eof63;
case 63:
	if ( (*p) == 105 )
		goto st64;
	goto tr81;
st64:
	if ( ++p == pe )
		goto _test_eof64;
case 64:
	if ( (*p) == 112 )
		goto st65;
	goto tr81;
st65:
	if ( ++p == pe )
		goto _test_eof65;
case 65:
	if ( (*p) == 116 )
		goto st66;
	goto tr81;
st66:
	if ( ++p == pe )
		goto _test_eof66;
case 66:
	if ( (*p) == 105 )
		goto st67;
	goto tr81;
st67:
	if ( ++p == pe )
		goto _test_eof67;
case 67:
	if ( (*p) == 111 )
		goto st68;
	goto tr81;
st68:
	if ( ++p == pe )
		goto _test_eof68;
case 68:
	if ( (*p) == 110 )
		goto st69;
	goto tr81;
st69:
	if ( ++p == pe )
		goto _test_eof69;
case 69:
	if ( (*p) == 61 )
		goto st70;
	goto tr81;
st70:
	if ( ++p == pe )
		goto _test_eof70;
case 70:
	if ( (*p) == 34 )
		goto tr107;
	goto tr81;
tr107:
#line 156 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Description");
    }
	goto st71;
st71:
	if ( ++p == pe )
		goto _test_eof71;
case 71:
#line 1916 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr110;
		case 92: goto tr111;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr109;
	goto tr108;
tr109:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st72;
tr112:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st72;
st72:
	if ( ++p == pe )
		goto _test_eof72;
case 72:
#line 1940 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr113;
		case 92: goto tr114;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr112;
	goto tr108;
tr110:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st73;
tr113:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st73;
st73:
	if ( ++p == pe )
		goto _test_eof73;
case 73:
#line 1964 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 44: goto st74;
		case 62: goto st78;
	}
	goto tr108;
st74:
	if ( ++p == pe )
		goto _test_eof74;
case 74:
	switch( (*p) ) {
		case 43: goto tr118;
		case 95: goto tr118;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr118;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr119;
		} else if ( (*p) >= 65 )
			goto tr119;
	} else
		goto tr119;
	goto tr117;
tr118:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st75;
st75:
	if ( ++p == pe )
		goto _test_eof75;
case 75:
#line 1998 "inc/vcf/validator_detail_v42.hpp"
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
				goto tr121;
		} else if ( (*p) >= 65 )
			goto tr121;
	} else
		goto tr121;
	goto tr117;
tr119:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st76;
tr121:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st76;
st76:
	if ( ++p == pe )
		goto _test_eof76;
case 76:
#line 2031 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 43: goto tr121;
		case 61: goto tr122;
		case 95: goto tr121;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr121;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr121;
		} else if ( (*p) >= 65 )
			goto tr121;
	} else
		goto tr121;
	goto tr117;
tr122:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st77;
st77:
	if ( ++p == pe )
		goto _test_eof77;
case 77:
#line 2057 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 34 )
		goto st71;
	goto tr81;
st78:
	if ( ++p == pe )
		goto _test_eof78;
case 78:
	switch( (*p) ) {
		case 10: goto tr55;
		case 13: goto tr56;
	}
	goto tr81;
tr111:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st79;
tr114:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st79;
st79:
	if ( ++p == pe )
		goto _test_eof79;
case 79:
#line 2086 "inc/vcf/validator_detail_v42.hpp"
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr112;
	goto tr81;
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
case 80:
#line 2101 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 73: goto tr125;
		case 79: goto tr126;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr124;
tr125:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st81;
st81:
	if ( ++p == pe )
		goto _test_eof81;
case 81:
#line 2118 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 76: goto tr128;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr127;
tr128:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st82;
st82:
	if ( ++p == pe )
		goto _test_eof82;
case 82:
#line 2134 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 84: goto tr129;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr127;
tr129:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st83;
st83:
	if ( ++p == pe )
		goto _test_eof83;
case 83:
#line 2150 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 69: goto tr130;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr127;
tr130:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st84;
st84:
	if ( ++p == pe )
		goto _test_eof84;
case 84:
#line 2166 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 82: goto st85;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr127;
st85:
	if ( ++p == pe )
		goto _test_eof85;
case 85:
	if ( (*p) == 61 )
		goto tr132;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr127;
tr132:
#line 120 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "FILTER");
    }
	goto st86;
st86:
	if ( ++p == pe )
		goto _test_eof86;
case 86:
#line 2191 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 60 )
		goto st87;
	goto tr127;
st87:
	if ( ++p == pe )
		goto _test_eof87;
case 87:
	if ( (*p) == 73 )
		goto st88;
	goto tr127;
st88:
	if ( ++p == pe )
		goto _test_eof88;
case 88:
	if ( (*p) == 68 )
		goto st89;
	goto tr127;
st89:
	if ( ++p == pe )
		goto _test_eof89;
case 89:
	if ( (*p) == 61 )
		goto st90;
	goto tr127;
st90:
	if ( ++p == pe )
		goto _test_eof90;
case 90:
	switch( (*p) ) {
		case 43: goto tr138;
		case 95: goto tr138;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr138;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr139;
		} else if ( (*p) >= 65 )
			goto tr139;
	} else
		goto tr139;
	goto tr137;
tr138:
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
case 91:
#line 2247 "inc/vcf/validator_detail_v42.hpp"
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
				goto tr141;
		} else if ( (*p) >= 65 )
			goto tr141;
	} else
		goto tr141;
	goto tr137;
tr141:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st92;
tr139:
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
case 92:
#line 2283 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 44: goto tr142;
		case 95: goto tr141;
	}
	if ( (*p) < 48 ) {
		if ( 43 <= (*p) && (*p) <= 46 )
			goto tr141;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr141;
		} else if ( (*p) >= 65 )
			goto tr141;
	} else
		goto tr141;
	goto tr137;
tr142:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st93;
st93:
	if ( ++p == pe )
		goto _test_eof93;
case 93:
#line 2308 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 68 )
		goto st94;
	goto tr127;
st94:
	if ( ++p == pe )
		goto _test_eof94;
case 94:
	if ( (*p) == 101 )
		goto st95;
	goto tr127;
st95:
	if ( ++p == pe )
		goto _test_eof95;
case 95:
	if ( (*p) == 115 )
		goto st96;
	goto tr127;
st96:
	if ( ++p == pe )
		goto _test_eof96;
case 96:
	if ( (*p) == 99 )
		goto st97;
	goto tr127;
st97:
	if ( ++p == pe )
		goto _test_eof97;
case 97:
	if ( (*p) == 114 )
		goto st98;
	goto tr127;
st98:
	if ( ++p == pe )
		goto _test_eof98;
case 98:
	if ( (*p) == 105 )
		goto st99;
	goto tr127;
st99:
	if ( ++p == pe )
		goto _test_eof99;
case 99:
	if ( (*p) == 112 )
		goto st100;
	goto tr127;
st100:
	if ( ++p == pe )
		goto _test_eof100;
case 100:
	if ( (*p) == 116 )
		goto st101;
	goto tr127;
st101:
	if ( ++p == pe )
		goto _test_eof101;
case 101:
	if ( (*p) == 105 )
		goto st102;
	goto tr127;
st102:
	if ( ++p == pe )
		goto _test_eof102;
case 102:
	if ( (*p) == 111 )
		goto st103;
	goto tr127;
st103:
	if ( ++p == pe )
		goto _test_eof103;
case 103:
	if ( (*p) == 110 )
		goto st104;
	goto tr127;
st104:
	if ( ++p == pe )
		goto _test_eof104;
case 104:
	if ( (*p) == 61 )
		goto st105;
	goto tr127;
st105:
	if ( ++p == pe )
		goto _test_eof105;
case 105:
	if ( (*p) == 34 )
		goto tr155;
	goto tr127;
tr155:
#line 156 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Description");
    }
	goto st106;
st106:
	if ( ++p == pe )
		goto _test_eof106;
case 106:
#line 2404 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr158;
		case 92: goto tr159;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr157;
	goto tr156;
tr157:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st107;
tr160:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st107;
st107:
	if ( ++p == pe )
		goto _test_eof107;
case 107:
#line 2428 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr161;
		case 92: goto tr162;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr160;
	goto tr156;
tr158:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st108;
tr161:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st108;
st108:
	if ( ++p == pe )
		goto _test_eof108;
case 108:
#line 2452 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 44: goto st109;
		case 62: goto st113;
	}
	goto tr156;
st109:
	if ( ++p == pe )
		goto _test_eof109;
case 109:
	switch( (*p) ) {
		case 43: goto tr165;
		case 95: goto tr165;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr165;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr166;
		} else if ( (*p) >= 65 )
			goto tr166;
	} else
		goto tr166;
	goto tr137;
tr165:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st110;
st110:
	if ( ++p == pe )
		goto _test_eof110;
case 110:
#line 2486 "inc/vcf/validator_detail_v42.hpp"
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
				goto tr168;
		} else if ( (*p) >= 65 )
			goto tr168;
	} else
		goto tr168;
	goto tr137;
tr166:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st111;
tr168:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st111;
st111:
	if ( ++p == pe )
		goto _test_eof111;
case 111:
#line 2519 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 43: goto tr168;
		case 61: goto tr169;
		case 95: goto tr168;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr168;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr168;
		} else if ( (*p) >= 65 )
			goto tr168;
	} else
		goto tr168;
	goto tr137;
tr169:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st112;
st112:
	if ( ++p == pe )
		goto _test_eof112;
case 112:
#line 2545 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 34 )
		goto st106;
	goto tr127;
st113:
	if ( ++p == pe )
		goto _test_eof113;
case 113:
	switch( (*p) ) {
		case 10: goto tr55;
		case 13: goto tr56;
	}
	goto tr127;
tr159:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st114;
tr162:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st114;
st114:
	if ( ++p == pe )
		goto _test_eof114;
case 114:
#line 2574 "inc/vcf/validator_detail_v42.hpp"
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr160;
	goto tr127;
tr126:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st115;
st115:
	if ( ++p == pe )
		goto _test_eof115;
case 115:
#line 2586 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 82: goto tr172;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr171;
tr172:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st116;
st116:
	if ( ++p == pe )
		goto _test_eof116;
case 116:
#line 2602 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 77: goto tr173;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr171;
tr173:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st117;
st117:
	if ( ++p == pe )
		goto _test_eof117;
case 117:
#line 2618 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 65: goto tr174;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr171;
tr174:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st118;
st118:
	if ( ++p == pe )
		goto _test_eof118;
case 118:
#line 2634 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 84: goto st119;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr171;
st119:
	if ( ++p == pe )
		goto _test_eof119;
case 119:
	if ( (*p) == 61 )
		goto tr176;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr171;
tr176:
#line 124 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "FORMAT");
    }
	goto st120;
st120:
	if ( ++p == pe )
		goto _test_eof120;
case 120:
#line 2659 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 60 )
		goto st121;
	goto tr171;
st121:
	if ( ++p == pe )
		goto _test_eof121;
case 121:
	if ( (*p) == 73 )
		goto st122;
	goto tr171;
st122:
	if ( ++p == pe )
		goto _test_eof122;
case 122:
	if ( (*p) == 68 )
		goto st123;
	goto tr171;
st123:
	if ( ++p == pe )
		goto _test_eof123;
case 123:
	if ( (*p) == 61 )
		goto st124;
	goto tr171;
st124:
	if ( ++p == pe )
		goto _test_eof124;
case 124:
	switch( (*p) ) {
		case 43: goto tr182;
		case 95: goto tr182;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr182;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr183;
		} else if ( (*p) >= 65 )
			goto tr183;
	} else
		goto tr183;
	goto tr181;
tr182:
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
case 125:
#line 2715 "inc/vcf/validator_detail_v42.hpp"
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
				goto tr185;
		} else if ( (*p) >= 65 )
			goto tr185;
	} else
		goto tr185;
	goto tr181;
tr185:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st126;
tr183:
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
case 126:
#line 2751 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 44: goto tr186;
		case 95: goto tr185;
	}
	if ( (*p) < 48 ) {
		if ( 43 <= (*p) && (*p) <= 46 )
			goto tr185;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr185;
		} else if ( (*p) >= 65 )
			goto tr185;
	} else
		goto tr185;
	goto tr181;
tr186:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st127;
st127:
	if ( ++p == pe )
		goto _test_eof127;
case 127:
#line 2776 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 78 )
		goto st128;
	goto tr171;
st128:
	if ( ++p == pe )
		goto _test_eof128;
case 128:
	if ( (*p) == 117 )
		goto st129;
	goto tr171;
st129:
	if ( ++p == pe )
		goto _test_eof129;
case 129:
	if ( (*p) == 109 )
		goto st130;
	goto tr171;
st130:
	if ( ++p == pe )
		goto _test_eof130;
case 130:
	if ( (*p) == 98 )
		goto st131;
	goto tr171;
st131:
	if ( ++p == pe )
		goto _test_eof131;
case 131:
	if ( (*p) == 101 )
		goto st132;
	goto tr171;
st132:
	if ( ++p == pe )
		goto _test_eof132;
case 132:
	if ( (*p) == 114 )
		goto st133;
	goto tr171;
st133:
	if ( ++p == pe )
		goto _test_eof133;
case 133:
	if ( (*p) == 61 )
		goto st134;
	goto tr171;
st134:
	if ( ++p == pe )
		goto _test_eof134;
case 134:
	switch( (*p) ) {
		case 46: goto tr195;
		case 65: goto tr195;
		case 71: goto tr195;
		case 82: goto tr195;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr196;
	goto tr194;
tr195:
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
case 135:
#line 2849 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 44 )
		goto tr197;
	goto tr194;
tr197:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st136;
st136:
	if ( ++p == pe )
		goto _test_eof136;
case 136:
#line 2861 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 84 )
		goto st137;
	goto tr171;
st137:
	if ( ++p == pe )
		goto _test_eof137;
case 137:
	if ( (*p) == 121 )
		goto st138;
	goto tr171;
st138:
	if ( ++p == pe )
		goto _test_eof138;
case 138:
	if ( (*p) == 112 )
		goto st139;
	goto tr171;
st139:
	if ( ++p == pe )
		goto _test_eof139;
case 139:
	if ( (*p) == 101 )
		goto st140;
	goto tr171;
st140:
	if ( ++p == pe )
		goto _test_eof140;
case 140:
	if ( (*p) == 61 )
		goto st141;
	goto tr171;
st141:
	if ( ++p == pe )
		goto _test_eof141;
case 141:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr204;
	} else if ( (*p) >= 65 )
		goto tr204;
	goto tr203;
tr206:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st142;
tr204:
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
case 142:
#line 2922 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 44 )
		goto tr205;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr206;
	} else if ( (*p) >= 65 )
		goto tr206;
	goto tr203;
tr205:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st143;
st143:
	if ( ++p == pe )
		goto _test_eof143;
case 143:
#line 2939 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 68 )
		goto st144;
	goto tr171;
st144:
	if ( ++p == pe )
		goto _test_eof144;
case 144:
	if ( (*p) == 101 )
		goto st145;
	goto tr171;
st145:
	if ( ++p == pe )
		goto _test_eof145;
case 145:
	if ( (*p) == 115 )
		goto st146;
	goto tr171;
st146:
	if ( ++p == pe )
		goto _test_eof146;
case 146:
	if ( (*p) == 99 )
		goto st147;
	goto tr171;
st147:
	if ( ++p == pe )
		goto _test_eof147;
case 147:
	if ( (*p) == 114 )
		goto st148;
	goto tr171;
st148:
	if ( ++p == pe )
		goto _test_eof148;
case 148:
	if ( (*p) == 105 )
		goto st149;
	goto tr171;
st149:
	if ( ++p == pe )
		goto _test_eof149;
case 149:
	if ( (*p) == 112 )
		goto st150;
	goto tr171;
st150:
	if ( ++p == pe )
		goto _test_eof150;
case 150:
	if ( (*p) == 116 )
		goto st151;
	goto tr171;
st151:
	if ( ++p == pe )
		goto _test_eof151;
case 151:
	if ( (*p) == 105 )
		goto st152;
	goto tr171;
st152:
	if ( ++p == pe )
		goto _test_eof152;
case 152:
	if ( (*p) == 111 )
		goto st153;
	goto tr171;
st153:
	if ( ++p == pe )
		goto _test_eof153;
case 153:
	if ( (*p) == 110 )
		goto st154;
	goto tr171;
st154:
	if ( ++p == pe )
		goto _test_eof154;
case 154:
	if ( (*p) == 61 )
		goto st155;
	goto tr171;
st155:
	if ( ++p == pe )
		goto _test_eof155;
case 155:
	if ( (*p) == 34 )
		goto tr219;
	goto tr171;
tr219:
#line 156 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Description");
    }
	goto st156;
st156:
	if ( ++p == pe )
		goto _test_eof156;
case 156:
#line 3035 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr222;
		case 92: goto tr223;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr221;
	goto tr220;
tr221:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st157;
tr224:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st157;
st157:
	if ( ++p == pe )
		goto _test_eof157;
case 157:
#line 3059 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr225;
		case 92: goto tr226;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr224;
	goto tr220;
tr222:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st158;
tr225:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st158;
st158:
	if ( ++p == pe )
		goto _test_eof158;
case 158:
#line 3083 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 44: goto st159;
		case 62: goto st163;
	}
	goto tr220;
st159:
	if ( ++p == pe )
		goto _test_eof159;
case 159:
	switch( (*p) ) {
		case 43: goto tr229;
		case 95: goto tr229;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr229;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr230;
		} else if ( (*p) >= 65 )
			goto tr230;
	} else
		goto tr230;
	goto tr181;
tr229:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st160;
st160:
	if ( ++p == pe )
		goto _test_eof160;
case 160:
#line 3117 "inc/vcf/validator_detail_v42.hpp"
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
				goto tr232;
		} else if ( (*p) >= 65 )
			goto tr232;
	} else
		goto tr232;
	goto tr181;
tr230:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st161;
tr232:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st161;
st161:
	if ( ++p == pe )
		goto _test_eof161;
case 161:
#line 3150 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 43: goto tr232;
		case 61: goto tr233;
		case 95: goto tr232;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr232;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr232;
		} else if ( (*p) >= 65 )
			goto tr232;
	} else
		goto tr232;
	goto tr181;
tr233:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st162;
st162:
	if ( ++p == pe )
		goto _test_eof162;
case 162:
#line 3176 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 34 )
		goto st156;
	goto tr171;
st163:
	if ( ++p == pe )
		goto _test_eof163;
case 163:
	switch( (*p) ) {
		case 10: goto tr55;
		case 13: goto tr56;
	}
	goto tr171;
tr223:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st164;
tr226:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st164;
st164:
	if ( ++p == pe )
		goto _test_eof164;
case 164:
#line 3205 "inc/vcf/validator_detail_v42.hpp"
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr224;
	goto tr171;
tr235:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st165;
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
	goto st165;
st165:
	if ( ++p == pe )
		goto _test_eof165;
case 165:
#line 3228 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 44 )
		goto tr197;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr235;
	goto tr194;
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
case 166:
#line 3245 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 78: goto tr237;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr236;
tr237:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st167;
st167:
	if ( ++p == pe )
		goto _test_eof167;
case 167:
#line 3261 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 70: goto tr238;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr236;
tr238:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st168;
st168:
	if ( ++p == pe )
		goto _test_eof168;
case 168:
#line 3277 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 79: goto st169;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr236;
st169:
	if ( ++p == pe )
		goto _test_eof169;
case 169:
	if ( (*p) == 61 )
		goto tr240;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr236;
tr240:
#line 128 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "INFO");
    }
	goto st170;
st170:
	if ( ++p == pe )
		goto _test_eof170;
case 170:
#line 3302 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 60 )
		goto st171;
	goto tr236;
st171:
	if ( ++p == pe )
		goto _test_eof171;
case 171:
	if ( (*p) == 73 )
		goto st172;
	goto tr236;
st172:
	if ( ++p == pe )
		goto _test_eof172;
case 172:
	if ( (*p) == 68 )
		goto st173;
	goto tr236;
st173:
	if ( ++p == pe )
		goto _test_eof173;
case 173:
	if ( (*p) == 61 )
		goto st174;
	goto tr236;
st174:
	if ( ++p == pe )
		goto _test_eof174;
case 174:
	switch( (*p) ) {
		case 43: goto tr246;
		case 95: goto tr246;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr246;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr247;
		} else if ( (*p) >= 65 )
			goto tr247;
	} else
		goto tr247;
	goto tr245;
tr246:
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
case 175:
#line 3358 "inc/vcf/validator_detail_v42.hpp"
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
				goto tr249;
		} else if ( (*p) >= 65 )
			goto tr249;
	} else
		goto tr249;
	goto tr245;
tr249:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st176;
tr247:
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
case 176:
#line 3394 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 44: goto tr250;
		case 95: goto tr249;
	}
	if ( (*p) < 48 ) {
		if ( 43 <= (*p) && (*p) <= 46 )
			goto tr249;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr249;
		} else if ( (*p) >= 65 )
			goto tr249;
	} else
		goto tr249;
	goto tr245;
tr250:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st177;
st177:
	if ( ++p == pe )
		goto _test_eof177;
case 177:
#line 3419 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 78 )
		goto st178;
	goto tr236;
st178:
	if ( ++p == pe )
		goto _test_eof178;
case 178:
	if ( (*p) == 117 )
		goto st179;
	goto tr236;
st179:
	if ( ++p == pe )
		goto _test_eof179;
case 179:
	if ( (*p) == 109 )
		goto st180;
	goto tr236;
st180:
	if ( ++p == pe )
		goto _test_eof180;
case 180:
	if ( (*p) == 98 )
		goto st181;
	goto tr236;
st181:
	if ( ++p == pe )
		goto _test_eof181;
case 181:
	if ( (*p) == 101 )
		goto st182;
	goto tr236;
st182:
	if ( ++p == pe )
		goto _test_eof182;
case 182:
	if ( (*p) == 114 )
		goto st183;
	goto tr236;
st183:
	if ( ++p == pe )
		goto _test_eof183;
case 183:
	if ( (*p) == 61 )
		goto st184;
	goto tr236;
st184:
	if ( ++p == pe )
		goto _test_eof184;
case 184:
	switch( (*p) ) {
		case 46: goto tr259;
		case 65: goto tr259;
		case 71: goto tr259;
		case 82: goto tr259;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr260;
	goto tr258;
tr259:
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
case 185:
#line 3492 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 44 )
		goto tr261;
	goto tr258;
tr261:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st186;
st186:
	if ( ++p == pe )
		goto _test_eof186;
case 186:
#line 3504 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 84 )
		goto st187;
	goto tr236;
st187:
	if ( ++p == pe )
		goto _test_eof187;
case 187:
	if ( (*p) == 121 )
		goto st188;
	goto tr236;
st188:
	if ( ++p == pe )
		goto _test_eof188;
case 188:
	if ( (*p) == 112 )
		goto st189;
	goto tr236;
st189:
	if ( ++p == pe )
		goto _test_eof189;
case 189:
	if ( (*p) == 101 )
		goto st190;
	goto tr236;
st190:
	if ( ++p == pe )
		goto _test_eof190;
case 190:
	if ( (*p) == 61 )
		goto st191;
	goto tr236;
st191:
	if ( ++p == pe )
		goto _test_eof191;
case 191:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr268;
	} else if ( (*p) >= 65 )
		goto tr268;
	goto tr267;
tr270:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st192;
tr268:
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
case 192:
#line 3565 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 44 )
		goto tr269;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr270;
	} else if ( (*p) >= 65 )
		goto tr270;
	goto tr267;
tr269:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st193;
st193:
	if ( ++p == pe )
		goto _test_eof193;
case 193:
#line 3582 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 68 )
		goto st194;
	goto tr236;
st194:
	if ( ++p == pe )
		goto _test_eof194;
case 194:
	if ( (*p) == 101 )
		goto st195;
	goto tr236;
st195:
	if ( ++p == pe )
		goto _test_eof195;
case 195:
	if ( (*p) == 115 )
		goto st196;
	goto tr236;
st196:
	if ( ++p == pe )
		goto _test_eof196;
case 196:
	if ( (*p) == 99 )
		goto st197;
	goto tr236;
st197:
	if ( ++p == pe )
		goto _test_eof197;
case 197:
	if ( (*p) == 114 )
		goto st198;
	goto tr236;
st198:
	if ( ++p == pe )
		goto _test_eof198;
case 198:
	if ( (*p) == 105 )
		goto st199;
	goto tr236;
st199:
	if ( ++p == pe )
		goto _test_eof199;
case 199:
	if ( (*p) == 112 )
		goto st200;
	goto tr236;
st200:
	if ( ++p == pe )
		goto _test_eof200;
case 200:
	if ( (*p) == 116 )
		goto st201;
	goto tr236;
st201:
	if ( ++p == pe )
		goto _test_eof201;
case 201:
	if ( (*p) == 105 )
		goto st202;
	goto tr236;
st202:
	if ( ++p == pe )
		goto _test_eof202;
case 202:
	if ( (*p) == 111 )
		goto st203;
	goto tr236;
st203:
	if ( ++p == pe )
		goto _test_eof203;
case 203:
	if ( (*p) == 110 )
		goto st204;
	goto tr236;
st204:
	if ( ++p == pe )
		goto _test_eof204;
case 204:
	if ( (*p) == 61 )
		goto st205;
	goto tr236;
st205:
	if ( ++p == pe )
		goto _test_eof205;
case 205:
	if ( (*p) == 34 )
		goto tr283;
	goto tr236;
tr283:
#line 156 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Description");
    }
	goto st206;
st206:
	if ( ++p == pe )
		goto _test_eof206;
case 206:
#line 3678 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr286;
		case 92: goto tr287;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr285;
	goto tr284;
tr285:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st207;
tr288:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st207;
st207:
	if ( ++p == pe )
		goto _test_eof207;
case 207:
#line 3702 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr289;
		case 92: goto tr290;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr288;
	goto tr284;
tr286:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st208;
tr289:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st208;
st208:
	if ( ++p == pe )
		goto _test_eof208;
case 208:
#line 3726 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 44: goto st209;
		case 62: goto st213;
	}
	goto tr284;
st209:
	if ( ++p == pe )
		goto _test_eof209;
case 209:
	switch( (*p) ) {
		case 43: goto tr293;
		case 95: goto tr293;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr293;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr294;
		} else if ( (*p) >= 65 )
			goto tr294;
	} else
		goto tr294;
	goto tr245;
tr293:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st210;
st210:
	if ( ++p == pe )
		goto _test_eof210;
case 210:
#line 3760 "inc/vcf/validator_detail_v42.hpp"
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
				goto tr296;
		} else if ( (*p) >= 65 )
			goto tr296;
	} else
		goto tr296;
	goto tr245;
tr294:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st211;
tr296:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st211;
st211:
	if ( ++p == pe )
		goto _test_eof211;
case 211:
#line 3793 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 43: goto tr296;
		case 61: goto tr297;
		case 95: goto tr296;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr296;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr296;
		} else if ( (*p) >= 65 )
			goto tr296;
	} else
		goto tr296;
	goto tr245;
tr297:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st212;
st212:
	if ( ++p == pe )
		goto _test_eof212;
case 212:
#line 3819 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 34 )
		goto st206;
	goto tr236;
st213:
	if ( ++p == pe )
		goto _test_eof213;
case 213:
	switch( (*p) ) {
		case 10: goto tr55;
		case 13: goto tr56;
	}
	goto tr236;
tr287:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st214;
tr290:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st214;
st214:
	if ( ++p == pe )
		goto _test_eof214;
case 214:
#line 3848 "inc/vcf/validator_detail_v42.hpp"
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr288;
	goto tr236;
tr299:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st215;
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
	goto st215;
st215:
	if ( ++p == pe )
		goto _test_eof215;
case 215:
#line 3871 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 44 )
		goto tr261;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr299;
	goto tr258;
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
case 216:
#line 3888 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 69: goto tr301;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr300;
tr301:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st217;
st217:
	if ( ++p == pe )
		goto _test_eof217;
case 217:
#line 3904 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 68: goto tr302;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr300;
tr302:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st218;
st218:
	if ( ++p == pe )
		goto _test_eof218;
case 218:
#line 3920 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 73: goto tr303;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr300;
tr303:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st219;
st219:
	if ( ++p == pe )
		goto _test_eof219;
case 219:
#line 3936 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 71: goto tr304;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr300;
tr304:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st220;
st220:
	if ( ++p == pe )
		goto _test_eof220;
case 220:
#line 3952 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 82: goto tr305;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr300;
tr305:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st221;
st221:
	if ( ++p == pe )
		goto _test_eof221;
case 221:
#line 3968 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 69: goto tr306;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr300;
tr306:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st222;
st222:
	if ( ++p == pe )
		goto _test_eof222;
case 222:
#line 3984 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 69: goto st223;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr300;
st223:
	if ( ++p == pe )
		goto _test_eof223;
case 223:
	if ( (*p) == 61 )
		goto tr308;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr300;
tr308:
#line 132 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "PEDIGREE");
    }
	goto st224;
st224:
	if ( ++p == pe )
		goto _test_eof224;
case 224:
#line 4009 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 60 )
		goto st225;
	goto tr300;
tr320:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st225;
st225:
	if ( ++p == pe )
		goto _test_eof225;
case 225:
#line 4021 "inc/vcf/validator_detail_v42.hpp"
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
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st226;
st226:
	if ( ++p == pe )
		goto _test_eof226;
case 226:
#line 4046 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 43: goto st226;
		case 95: goto st226;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st226;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr314;
		} else if ( (*p) >= 65 )
			goto tr314;
	} else
		goto tr314;
	goto tr310;
tr312:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st227;
tr314:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st227;
st227:
	if ( ++p == pe )
		goto _test_eof227;
case 227:
#line 4079 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 43: goto tr314;
		case 61: goto tr315;
		case 95: goto tr314;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
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
	goto st228;
st228:
	if ( ++p == pe )
		goto _test_eof228;
case 228:
#line 4105 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 43: goto tr316;
		case 95: goto tr316;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr316;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr317;
		} else if ( (*p) >= 65 )
			goto tr317;
	} else
		goto tr317;
	goto tr310;
tr316:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st229;
st229:
	if ( ++p == pe )
		goto _test_eof229;
case 229:
#line 4130 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 43: goto st229;
		case 95: goto st229;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st229;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr319;
		} else if ( (*p) >= 65 )
			goto tr319;
	} else
		goto tr319;
	goto tr310;
tr317:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st230;
tr319:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st230;
st230:
	if ( ++p == pe )
		goto _test_eof230;
case 230:
#line 4163 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 44: goto tr320;
		case 62: goto tr321;
		case 95: goto tr319;
	}
	if ( (*p) < 48 ) {
		if ( 43 <= (*p) && (*p) <= 46 )
			goto tr319;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr319;
		} else if ( (*p) >= 65 )
			goto tr319;
	} else
		goto tr319;
	goto tr310;
tr321:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st231;
st231:
	if ( ++p == pe )
		goto _test_eof231;
case 231:
#line 4189 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 10: goto tr55;
		case 13: goto tr56;
	}
	goto tr300;
tr35:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st232;
st232:
	if ( ++p == pe )
		goto _test_eof232;
case 232:
#line 4206 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 65: goto tr323;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr322;
tr323:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st233;
st233:
	if ( ++p == pe )
		goto _test_eof233;
case 233:
#line 4222 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 77: goto tr324;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr322;
tr324:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st234;
st234:
	if ( ++p == pe )
		goto _test_eof234;
case 234:
#line 4238 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 80: goto tr325;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr322;
tr325:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st235;
st235:
	if ( ++p == pe )
		goto _test_eof235;
case 235:
#line 4254 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 76: goto tr326;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr322;
tr326:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st236;
st236:
	if ( ++p == pe )
		goto _test_eof236;
case 236:
#line 4270 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 69: goto st237;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr322;
st237:
	if ( ++p == pe )
		goto _test_eof237;
case 237:
	if ( (*p) == 61 )
		goto tr328;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr322;
tr328:
#line 140 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "SAMPLE");
    }
	goto st238;
st238:
	if ( ++p == pe )
		goto _test_eof238;
case 238:
#line 4295 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 60 )
		goto st239;
	goto tr322;
st239:
	if ( ++p == pe )
		goto _test_eof239;
case 239:
	if ( (*p) == 73 )
		goto st240;
	goto tr322;
st240:
	if ( ++p == pe )
		goto _test_eof240;
case 240:
	if ( (*p) == 68 )
		goto st241;
	goto tr322;
st241:
	if ( ++p == pe )
		goto _test_eof241;
case 241:
	if ( (*p) == 61 )
		goto st242;
	goto tr322;
st242:
	if ( ++p == pe )
		goto _test_eof242;
case 242:
	switch( (*p) ) {
		case 43: goto tr334;
		case 95: goto tr334;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr334;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr335;
		} else if ( (*p) >= 65 )
			goto tr335;
	} else
		goto tr335;
	goto tr333;
tr334:
#line 144 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st243;
st243:
	if ( ++p == pe )
		goto _test_eof243;
case 243:
#line 4351 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 43: goto st243;
		case 95: goto st243;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st243;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr337;
		} else if ( (*p) >= 65 )
			goto tr337;
	} else
		goto tr337;
	goto tr333;
tr337:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st244;
tr335:
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
	goto st244;
st244:
	if ( ++p == pe )
		goto _test_eof244;
case 244:
#line 4387 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 44: goto tr339;
		case 95: goto tr337;
	}
	if ( (*p) < 48 ) {
		if ( 43 <= (*p) && (*p) <= 46 )
			goto tr337;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr337;
		} else if ( (*p) >= 65 )
			goto tr337;
	} else
		goto tr337;
	goto tr338;
tr339:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st245;
st245:
	if ( ++p == pe )
		goto _test_eof245;
case 245:
#line 4412 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 71 )
		goto st246;
	goto tr340;
st246:
	if ( ++p == pe )
		goto _test_eof246;
case 246:
	if ( (*p) == 101 )
		goto st247;
	goto tr340;
st247:
	if ( ++p == pe )
		goto _test_eof247;
case 247:
	if ( (*p) == 110 )
		goto st248;
	goto tr340;
st248:
	if ( ++p == pe )
		goto _test_eof248;
case 248:
	if ( (*p) == 111 )
		goto st249;
	goto tr340;
st249:
	if ( ++p == pe )
		goto _test_eof249;
case 249:
	if ( (*p) == 109 )
		goto st250;
	goto tr340;
st250:
	if ( ++p == pe )
		goto _test_eof250;
case 250:
	if ( (*p) == 101 )
		goto st251;
	goto tr340;
st251:
	if ( ++p == pe )
		goto _test_eof251;
case 251:
	if ( (*p) == 115 )
		goto st252;
	goto tr340;
st252:
	if ( ++p == pe )
		goto _test_eof252;
case 252:
	if ( (*p) == 61 )
		goto st253;
	goto tr340;
st253:
	if ( ++p == pe )
		goto _test_eof253;
case 253:
	if ( (*p) < 35 ) {
		if ( 32 <= (*p) && (*p) <= 33 )
			goto tr349;
	} else if ( (*p) > 43 ) {
		if ( (*p) > 61 ) {
			if ( 63 <= (*p) && (*p) <= 126 )
				goto tr349;
		} else if ( (*p) >= 45 )
			goto tr349;
	} else
		goto tr349;
	goto tr340;
tr351:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st254;
tr349:
#line 160 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Genomes");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st254;
st254:
	if ( ++p == pe )
		goto _test_eof254;
case 254:
#line 4500 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 44 )
		goto tr352;
	if ( (*p) < 35 ) {
		if ( 32 <= (*p) && (*p) <= 33 )
			goto tr351;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr351;
	} else
		goto tr351;
	goto tr350;
tr352:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st255;
st255:
	if ( ++p == pe )
		goto _test_eof255;
case 255:
#line 4520 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 77 )
		goto st256;
	goto tr353;
st256:
	if ( ++p == pe )
		goto _test_eof256;
case 256:
	if ( (*p) == 105 )
		goto st257;
	goto tr353;
st257:
	if ( ++p == pe )
		goto _test_eof257;
case 257:
	if ( (*p) == 120 )
		goto st258;
	goto tr353;
st258:
	if ( ++p == pe )
		goto _test_eof258;
case 258:
	if ( (*p) == 116 )
		goto st259;
	goto tr353;
st259:
	if ( ++p == pe )
		goto _test_eof259;
case 259:
	if ( (*p) == 117 )
		goto st260;
	goto tr353;
st260:
	if ( ++p == pe )
		goto _test_eof260;
case 260:
	if ( (*p) == 114 )
		goto st261;
	goto tr353;
st261:
	if ( ++p == pe )
		goto _test_eof261;
case 261:
	if ( (*p) == 101 )
		goto st262;
	goto tr353;
st262:
	if ( ++p == pe )
		goto _test_eof262;
case 262:
	if ( (*p) == 61 )
		goto st263;
	goto tr353;
st263:
	if ( ++p == pe )
		goto _test_eof263;
case 263:
	if ( (*p) < 35 ) {
		if ( 32 <= (*p) && (*p) <= 33 )
			goto tr362;
	} else if ( (*p) > 43 ) {
		if ( (*p) > 61 ) {
			if ( 63 <= (*p) && (*p) <= 126 )
				goto tr362;
		} else if ( (*p) >= 45 )
			goto tr362;
	} else
		goto tr362;
	goto tr353;
tr364:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st264;
tr362:
#line 164 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Mixture");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st264;
st264:
	if ( ++p == pe )
		goto _test_eof264;
case 264:
#line 4608 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 44 )
		goto tr365;
	if ( (*p) < 35 ) {
		if ( 32 <= (*p) && (*p) <= 33 )
			goto tr364;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr364;
	} else
		goto tr364;
	goto tr363;
tr365:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st265;
st265:
	if ( ++p == pe )
		goto _test_eof265;
case 265:
#line 4628 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 68 )
		goto st266;
	goto tr366;
st266:
	if ( ++p == pe )
		goto _test_eof266;
case 266:
	if ( (*p) == 101 )
		goto st267;
	goto tr366;
st267:
	if ( ++p == pe )
		goto _test_eof267;
case 267:
	if ( (*p) == 115 )
		goto st268;
	goto tr366;
st268:
	if ( ++p == pe )
		goto _test_eof268;
case 268:
	if ( (*p) == 99 )
		goto st269;
	goto tr366;
st269:
	if ( ++p == pe )
		goto _test_eof269;
case 269:
	if ( (*p) == 114 )
		goto st270;
	goto tr366;
st270:
	if ( ++p == pe )
		goto _test_eof270;
case 270:
	if ( (*p) == 105 )
		goto st271;
	goto tr366;
st271:
	if ( ++p == pe )
		goto _test_eof271;
case 271:
	if ( (*p) == 112 )
		goto st272;
	goto tr366;
st272:
	if ( ++p == pe )
		goto _test_eof272;
case 272:
	if ( (*p) == 116 )
		goto st273;
	goto tr366;
st273:
	if ( ++p == pe )
		goto _test_eof273;
case 273:
	if ( (*p) == 105 )
		goto st274;
	goto tr366;
st274:
	if ( ++p == pe )
		goto _test_eof274;
case 274:
	if ( (*p) == 111 )
		goto st275;
	goto tr366;
st275:
	if ( ++p == pe )
		goto _test_eof275;
case 275:
	if ( (*p) == 110 )
		goto st276;
	goto tr366;
st276:
	if ( ++p == pe )
		goto _test_eof276;
case 276:
	if ( (*p) == 61 )
		goto st277;
	goto tr366;
st277:
	if ( ++p == pe )
		goto _test_eof277;
case 277:
	if ( (*p) == 34 )
		goto tr379;
	goto tr366;
tr379:
#line 156 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Description");
    }
	goto st278;
st278:
	if ( ++p == pe )
		goto _test_eof278;
case 278:
#line 4724 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr381;
		case 92: goto tr382;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr380;
	goto tr366;
tr380:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st279;
tr383:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st279;
st279:
	if ( ++p == pe )
		goto _test_eof279;
case 279:
#line 4748 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr384;
		case 92: goto tr385;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr383;
	goto tr366;
tr381:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st280;
tr384:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st280;
st280:
	if ( ++p == pe )
		goto _test_eof280;
case 280:
#line 4772 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 62 )
		goto st281;
	goto tr366;
st281:
	if ( ++p == pe )
		goto _test_eof281;
case 281:
	switch( (*p) ) {
		case 10: goto tr55;
		case 13: goto tr56;
	}
	goto tr322;
tr382:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st282;
tr385:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st282;
st282:
	if ( ++p == pe )
		goto _test_eof282;
case 282:
#line 4801 "inc/vcf/validator_detail_v42.hpp"
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr383;
	goto tr366;
tr36:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st283;
st283:
	if ( ++p == pe )
		goto _test_eof283;
case 283:
#line 4816 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 115: goto tr388;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr387;
tr388:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st284;
st284:
	if ( ++p == pe )
		goto _test_eof284;
case 284:
#line 4832 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 115: goto tr389;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr387;
tr389:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st285;
st285:
	if ( ++p == pe )
		goto _test_eof285;
case 285:
#line 4848 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 101: goto tr390;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr387;
tr390:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st286;
st286:
	if ( ++p == pe )
		goto _test_eof286;
case 286:
#line 4864 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 109: goto tr391;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr387;
tr391:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st287;
st287:
	if ( ++p == pe )
		goto _test_eof287;
case 287:
#line 4880 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 98: goto tr392;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr387;
tr392:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st288;
st288:
	if ( ++p == pe )
		goto _test_eof288;
case 288:
#line 4896 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 108: goto tr393;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr387;
tr393:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st289;
st289:
	if ( ++p == pe )
		goto _test_eof289;
case 289:
#line 4912 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 121: goto st290;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr387;
st290:
	if ( ++p == pe )
		goto _test_eof290;
case 290:
	if ( (*p) == 61 )
		goto tr395;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr387;
tr395:
#line 112 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "assembly");
    }
	goto st291;
st291:
	if ( ++p == pe )
		goto _test_eof291;
case 291:
#line 4937 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr397;
	} else if ( (*p) >= 65 )
		goto tr397;
	goto tr396;
tr397:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st292;
st292:
	if ( ++p == pe )
		goto _test_eof292;
case 292:
#line 4952 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 10: goto tr396;
		case 13: goto tr399;
		case 35: goto tr396;
		case 47: goto tr396;
		case 58: goto tr396;
		case 63: goto tr396;
	}
	goto st293;
tr399:
#line 43 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st293;
st293:
	if ( ++p == pe )
		goto _test_eof293;
case 293:
#line 4976 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 10: goto tr396;
		case 13: goto tr399;
		case 35: goto tr396;
		case 47: goto tr396;
		case 58: goto st294;
		case 63: goto tr396;
	}
	goto st293;
st294:
	if ( ++p == pe )
		goto _test_eof294;
case 294:
	if ( (*p) == 47 )
		goto st295;
	goto tr396;
st295:
	if ( ++p == pe )
		goto _test_eof295;
case 295:
	if ( (*p) == 47 )
		goto st296;
	goto tr396;
st296:
	if ( ++p == pe )
		goto _test_eof296;
case 296:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st297;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr404;
	} else
		goto tr404;
	goto tr396;
st297:
	if ( ++p == pe )
		goto _test_eof297;
case 297:
	if ( (*p) == 46 )
		goto st298;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st308;
	goto tr396;
st298:
	if ( ++p == pe )
		goto _test_eof298;
case 298:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st299;
	goto tr396;
st299:
	if ( ++p == pe )
		goto _test_eof299;
case 299:
	if ( (*p) == 46 )
		goto st300;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st306;
	goto tr396;
st300:
	if ( ++p == pe )
		goto _test_eof300;
case 300:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st301;
	goto tr396;
st301:
	if ( ++p == pe )
		goto _test_eof301;
case 301:
	if ( (*p) == 46 )
		goto st302;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st304;
	goto tr396;
st302:
	if ( ++p == pe )
		goto _test_eof302;
case 302:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr404;
	goto tr396;
tr404:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st303;
tr413:
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
	goto st303;
st303:
	if ( ++p == pe )
		goto _test_eof303;
case 303:
#line 5093 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 10: goto tr45;
		case 13: goto tr413;
	}
	goto tr404;
st304:
	if ( ++p == pe )
		goto _test_eof304;
case 304:
	if ( (*p) == 46 )
		goto st302;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st305;
	goto tr396;
st305:
	if ( ++p == pe )
		goto _test_eof305;
case 305:
	if ( (*p) == 46 )
		goto st302;
	goto tr396;
st306:
	if ( ++p == pe )
		goto _test_eof306;
case 306:
	if ( (*p) == 46 )
		goto st300;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st307;
	goto tr396;
st307:
	if ( ++p == pe )
		goto _test_eof307;
case 307:
	if ( (*p) == 46 )
		goto st300;
	goto tr396;
st308:
	if ( ++p == pe )
		goto _test_eof308;
case 308:
	if ( (*p) == 46 )
		goto st298;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st309;
	goto tr396;
st309:
	if ( ++p == pe )
		goto _test_eof309;
case 309:
	if ( (*p) == 46 )
		goto st298;
	goto tr396;
tr37:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st310;
st310:
	if ( ++p == pe )
		goto _test_eof310;
case 310:
#line 5158 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 111: goto tr418;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr417;
tr418:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st311;
st311:
	if ( ++p == pe )
		goto _test_eof311;
case 311:
#line 5174 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 110: goto tr419;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr417;
tr419:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st312;
st312:
	if ( ++p == pe )
		goto _test_eof312;
case 312:
#line 5190 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 116: goto tr420;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr417;
tr420:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st313;
st313:
	if ( ++p == pe )
		goto _test_eof313;
case 313:
#line 5206 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 105: goto tr421;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr417;
tr421:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st314;
st314:
	if ( ++p == pe )
		goto _test_eof314;
case 314:
#line 5222 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 103: goto st315;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr417;
st315:
	if ( ++p == pe )
		goto _test_eof315;
case 315:
	if ( (*p) == 61 )
		goto tr423;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr417;
tr423:
#line 116 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "contig");
    }
	goto st316;
st316:
	if ( ++p == pe )
		goto _test_eof316;
case 316:
#line 5247 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 60 )
		goto st317;
	goto tr417;
st317:
	if ( ++p == pe )
		goto _test_eof317;
case 317:
	if ( (*p) == 73 )
		goto st318;
	goto tr417;
st318:
	if ( ++p == pe )
		goto _test_eof318;
case 318:
	if ( (*p) == 68 )
		goto st319;
	goto tr417;
st319:
	if ( ++p == pe )
		goto _test_eof319;
case 319:
	if ( (*p) == 61 )
		goto st320;
	goto tr417;
st320:
	if ( ++p == pe )
		goto _test_eof320;
case 320:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr429;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr429;
	} else
		goto tr429;
	goto tr428;
tr430:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st321;
tr429:
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
	goto st321;
st321:
	if ( ++p == pe )
		goto _test_eof321;
case 321:
#line 5304 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 44: goto tr431;
		case 62: goto tr432;
	}
	if ( (*p) > 59 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr430;
	} else if ( (*p) >= 33 )
		goto tr430;
	goto tr428;
tr431:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st322;
st322:
	if ( ++p == pe )
		goto _test_eof322;
case 322:
#line 5323 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 43: goto tr433;
		case 95: goto tr433;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr433;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr434;
		} else if ( (*p) >= 65 )
			goto tr434;
	} else
		goto tr434;
	goto tr417;
tr433:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st323;
st323:
	if ( ++p == pe )
		goto _test_eof323;
case 323:
#line 5348 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 43: goto st323;
		case 95: goto st323;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st323;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr436;
		} else if ( (*p) >= 65 )
			goto tr436;
	} else
		goto tr436;
	goto tr417;
tr434:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st324;
tr436:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st324;
st324:
	if ( ++p == pe )
		goto _test_eof324;
case 324:
#line 5381 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 43: goto tr436;
		case 61: goto tr437;
		case 95: goto tr436;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr436;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr436;
		} else if ( (*p) >= 65 )
			goto tr436;
	} else
		goto tr436;
	goto tr417;
tr437:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st325;
st325:
	if ( ++p == pe )
		goto _test_eof325;
case 325:
#line 5407 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 34 )
		goto st328;
	if ( (*p) < 45 ) {
		if ( 32 <= (*p) && (*p) <= 43 )
			goto tr438;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr438;
	} else
		goto tr438;
	goto tr417;
tr438:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st326;
tr440:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st326;
st326:
	if ( ++p == pe )
		goto _test_eof326;
case 326:
#line 5435 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 44: goto tr431;
		case 62: goto tr432;
	}
	if ( (*p) > 33 ) {
		if ( 35 <= (*p) && (*p) <= 126 )
			goto tr440;
	} else if ( (*p) >= 32 )
		goto tr440;
	goto tr417;
tr432:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st327;
st327:
	if ( ++p == pe )
		goto _test_eof327;
case 327:
#line 5454 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 10: goto tr55;
		case 13: goto tr56;
	}
	goto tr417;
st328:
	if ( ++p == pe )
		goto _test_eof328;
case 328:
	switch( (*p) ) {
		case 34: goto tr442;
		case 92: goto tr443;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr441;
	goto tr417;
tr441:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st329;
tr444:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st329;
st329:
	if ( ++p == pe )
		goto _test_eof329;
case 329:
#line 5487 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 34: goto tr445;
		case 92: goto tr446;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr444;
	goto tr417;
tr442:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st330;
tr445:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st330;
st330:
	if ( ++p == pe )
		goto _test_eof330;
case 330:
#line 5511 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 44: goto st322;
		case 62: goto st327;
	}
	goto tr417;
tr443:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st331;
tr446:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st331;
st331:
	if ( ++p == pe )
		goto _test_eof331;
case 331:
#line 5533 "inc/vcf/validator_detail_v42.hpp"
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr444;
	goto tr417;
tr38:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st332;
st332:
	if ( ++p == pe )
		goto _test_eof332;
case 332:
#line 5548 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 101: goto tr450;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr449;
tr450:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st333;
st333:
	if ( ++p == pe )
		goto _test_eof333;
case 333:
#line 5564 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 100: goto tr451;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr449;
tr451:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st334;
st334:
	if ( ++p == pe )
		goto _test_eof334;
case 334:
#line 5580 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 105: goto tr452;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr449;
tr452:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st335;
st335:
	if ( ++p == pe )
		goto _test_eof335;
case 335:
#line 5596 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 103: goto tr453;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr449;
tr453:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st336;
st336:
	if ( ++p == pe )
		goto _test_eof336;
case 336:
#line 5612 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 114: goto tr454;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr449;
tr454:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st337;
st337:
	if ( ++p == pe )
		goto _test_eof337;
case 337:
#line 5628 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 101: goto tr455;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr449;
tr455:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st338;
st338:
	if ( ++p == pe )
		goto _test_eof338;
case 338:
#line 5644 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 101: goto tr456;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr449;
tr456:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st339;
st339:
	if ( ++p == pe )
		goto _test_eof339;
case 339:
#line 5660 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 68: goto tr457;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr449;
tr457:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st340;
st340:
	if ( ++p == pe )
		goto _test_eof340;
case 340:
#line 5676 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 66: goto st341;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr449;
st341:
	if ( ++p == pe )
		goto _test_eof341;
case 341:
	if ( (*p) == 61 )
		goto tr459;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr449;
tr459:
#line 136 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "pedigreeDB");
    }
	goto st342;
st342:
	if ( ++p == pe )
		goto _test_eof342;
case 342:
#line 5701 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 60 )
		goto st343;
	goto tr449;
st343:
	if ( ++p == pe )
		goto _test_eof343;
case 343:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr462;
	} else if ( (*p) >= 65 )
		goto tr462;
	goto tr461;
tr462:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st344;
st344:
	if ( ++p == pe )
		goto _test_eof344;
case 344:
#line 5723 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 10: goto tr461;
		case 13: goto tr464;
		case 35: goto tr461;
		case 47: goto tr461;
		case 58: goto tr461;
		case 63: goto tr461;
	}
	goto st345;
tr464:
#line 43 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st345;
st345:
	if ( ++p == pe )
		goto _test_eof345;
case 345:
#line 5747 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 10: goto tr461;
		case 13: goto tr464;
		case 35: goto tr461;
		case 47: goto tr461;
		case 58: goto st346;
		case 63: goto tr461;
	}
	goto st345;
st346:
	if ( ++p == pe )
		goto _test_eof346;
case 346:
	if ( (*p) == 47 )
		goto st347;
	goto tr461;
st347:
	if ( ++p == pe )
		goto _test_eof347;
case 347:
	if ( (*p) == 47 )
		goto st348;
	goto tr461;
st348:
	if ( ++p == pe )
		goto _test_eof348;
case 348:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st349;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr469;
	} else
		goto tr469;
	goto tr461;
st349:
	if ( ++p == pe )
		goto _test_eof349;
case 349:
	if ( (*p) == 46 )
		goto st350;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st362;
	goto tr461;
st350:
	if ( ++p == pe )
		goto _test_eof350;
case 350:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st351;
	goto tr461;
st351:
	if ( ++p == pe )
		goto _test_eof351;
case 351:
	if ( (*p) == 46 )
		goto st352;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st360;
	goto tr461;
st352:
	if ( ++p == pe )
		goto _test_eof352;
case 352:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st353;
	goto tr461;
st353:
	if ( ++p == pe )
		goto _test_eof353;
case 353:
	if ( (*p) == 46 )
		goto st354;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st358;
	goto tr461;
st354:
	if ( ++p == pe )
		goto _test_eof354;
case 354:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr469;
	goto tr461;
tr469:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st355;
tr478:
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
	goto st355;
st355:
	if ( ++p == pe )
		goto _test_eof355;
case 355:
#line 5854 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 10: goto tr461;
		case 13: goto tr478;
		case 62: goto tr479;
	}
	goto tr469;
tr479:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st356;
st356:
	if ( ++p == pe )
		goto _test_eof356;
case 356:
#line 5872 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 10: goto tr55;
		case 13: goto tr480;
		case 62: goto tr479;
	}
	goto tr469;
tr480:
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
	goto st357;
st357:
	if ( ++p == pe )
		goto _test_eof357;
case 357:
#line 5903 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 10: goto st28;
		case 13: goto tr478;
		case 62: goto tr479;
	}
	goto tr469;
st358:
	if ( ++p == pe )
		goto _test_eof358;
case 358:
	if ( (*p) == 46 )
		goto st354;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st359;
	goto tr461;
st359:
	if ( ++p == pe )
		goto _test_eof359;
case 359:
	if ( (*p) == 46 )
		goto st354;
	goto tr461;
st360:
	if ( ++p == pe )
		goto _test_eof360;
case 360:
	if ( (*p) == 46 )
		goto st352;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st361;
	goto tr461;
st361:
	if ( ++p == pe )
		goto _test_eof361;
case 361:
	if ( (*p) == 46 )
		goto st352;
	goto tr461;
st362:
	if ( ++p == pe )
		goto _test_eof362;
case 362:
	if ( (*p) == 46 )
		goto st350;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st363;
	goto tr461;
st363:
	if ( ++p == pe )
		goto _test_eof363;
case 363:
	if ( (*p) == 46 )
		goto st350;
	goto tr461;
st364:
	if ( ++p == pe )
		goto _test_eof364;
case 364:
	if ( (*p) == 72 )
		goto st365;
	goto tr484;
st365:
	if ( ++p == pe )
		goto _test_eof365;
case 365:
	if ( (*p) == 82 )
		goto st366;
	goto tr484;
st366:
	if ( ++p == pe )
		goto _test_eof366;
case 366:
	if ( (*p) == 79 )
		goto st367;
	goto tr484;
st367:
	if ( ++p == pe )
		goto _test_eof367;
case 367:
	if ( (*p) == 77 )
		goto st368;
	goto tr484;
st368:
	if ( ++p == pe )
		goto _test_eof368;
case 368:
	if ( (*p) == 9 )
		goto tr489;
	goto tr484;
tr489:
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st369;
st369:
	if ( ++p == pe )
		goto _test_eof369;
case 369:
#line 6001 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 80 )
		goto st370;
	goto tr484;
st370:
	if ( ++p == pe )
		goto _test_eof370;
case 370:
	if ( (*p) == 79 )
		goto st371;
	goto tr484;
st371:
	if ( ++p == pe )
		goto _test_eof371;
case 371:
	if ( (*p) == 83 )
		goto st372;
	goto tr484;
st372:
	if ( ++p == pe )
		goto _test_eof372;
case 372:
	if ( (*p) == 9 )
		goto tr493;
	goto tr484;
tr493:
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st373;
st373:
	if ( ++p == pe )
		goto _test_eof373;
case 373:
#line 6034 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 73 )
		goto st374;
	goto tr484;
st374:
	if ( ++p == pe )
		goto _test_eof374;
case 374:
	if ( (*p) == 68 )
		goto st375;
	goto tr484;
st375:
	if ( ++p == pe )
		goto _test_eof375;
case 375:
	if ( (*p) == 9 )
		goto tr496;
	goto tr484;
tr496:
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st376;
st376:
	if ( ++p == pe )
		goto _test_eof376;
case 376:
#line 6060 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 82 )
		goto st377;
	goto tr484;
st377:
	if ( ++p == pe )
		goto _test_eof377;
case 377:
	if ( (*p) == 69 )
		goto st378;
	goto tr484;
st378:
	if ( ++p == pe )
		goto _test_eof378;
case 378:
	if ( (*p) == 70 )
		goto st379;
	goto tr484;
st379:
	if ( ++p == pe )
		goto _test_eof379;
case 379:
	if ( (*p) == 9 )
		goto tr500;
	goto tr484;
tr500:
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st380;
st380:
	if ( ++p == pe )
		goto _test_eof380;
case 380:
#line 6093 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 65 )
		goto st381;
	goto tr484;
st381:
	if ( ++p == pe )
		goto _test_eof381;
case 381:
	if ( (*p) == 76 )
		goto st382;
	goto tr484;
st382:
	if ( ++p == pe )
		goto _test_eof382;
case 382:
	if ( (*p) == 84 )
		goto st383;
	goto tr484;
st383:
	if ( ++p == pe )
		goto _test_eof383;
case 383:
	if ( (*p) == 9 )
		goto tr504;
	goto tr484;
tr504:
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st384;
st384:
	if ( ++p == pe )
		goto _test_eof384;
case 384:
#line 6126 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 81 )
		goto st385;
	goto tr484;
st385:
	if ( ++p == pe )
		goto _test_eof385;
case 385:
	if ( (*p) == 85 )
		goto st386;
	goto tr484;
st386:
	if ( ++p == pe )
		goto _test_eof386;
case 386:
	if ( (*p) == 65 )
		goto st387;
	goto tr484;
st387:
	if ( ++p == pe )
		goto _test_eof387;
case 387:
	if ( (*p) == 76 )
		goto st388;
	goto tr484;
st388:
	if ( ++p == pe )
		goto _test_eof388;
case 388:
	if ( (*p) == 9 )
		goto tr509;
	goto tr484;
tr509:
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st389;
st389:
	if ( ++p == pe )
		goto _test_eof389;
case 389:
#line 6166 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 70 )
		goto st390;
	goto tr484;
st390:
	if ( ++p == pe )
		goto _test_eof390;
case 390:
	if ( (*p) == 73 )
		goto st391;
	goto tr484;
st391:
	if ( ++p == pe )
		goto _test_eof391;
case 391:
	if ( (*p) == 76 )
		goto st392;
	goto tr484;
st392:
	if ( ++p == pe )
		goto _test_eof392;
case 392:
	if ( (*p) == 84 )
		goto st393;
	goto tr484;
st393:
	if ( ++p == pe )
		goto _test_eof393;
case 393:
	if ( (*p) == 69 )
		goto st394;
	goto tr484;
st394:
	if ( ++p == pe )
		goto _test_eof394;
case 394:
	if ( (*p) == 82 )
		goto st395;
	goto tr484;
st395:
	if ( ++p == pe )
		goto _test_eof395;
case 395:
	if ( (*p) == 9 )
		goto tr516;
	goto tr484;
tr516:
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st396;
st396:
	if ( ++p == pe )
		goto _test_eof396;
case 396:
#line 6220 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 73 )
		goto st397;
	goto tr484;
st397:
	if ( ++p == pe )
		goto _test_eof397;
case 397:
	if ( (*p) == 78 )
		goto st398;
	goto tr484;
st398:
	if ( ++p == pe )
		goto _test_eof398;
case 398:
	if ( (*p) == 70 )
		goto st399;
	goto tr484;
st399:
	if ( ++p == pe )
		goto _test_eof399;
case 399:
	if ( (*p) == 79 )
		goto st400;
	goto tr484;
st400:
	if ( ++p == pe )
		goto _test_eof400;
case 400:
	switch( (*p) ) {
		case 9: goto tr521;
		case 10: goto tr522;
		case 13: goto tr523;
	}
	goto tr484;
tr521:
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st401;
st401:
	if ( ++p == pe )
		goto _test_eof401;
case 401:
#line 6263 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 70 )
		goto st402;
	goto tr524;
st402:
	if ( ++p == pe )
		goto _test_eof402;
case 402:
	if ( (*p) == 79 )
		goto st403;
	goto tr524;
st403:
	if ( ++p == pe )
		goto _test_eof403;
case 403:
	if ( (*p) == 82 )
		goto st404;
	goto tr524;
st404:
	if ( ++p == pe )
		goto _test_eof404;
case 404:
	if ( (*p) == 77 )
		goto st405;
	goto tr524;
st405:
	if ( ++p == pe )
		goto _test_eof405;
case 405:
	if ( (*p) == 65 )
		goto st406;
	goto tr524;
st406:
	if ( ++p == pe )
		goto _test_eof406;
case 406:
	if ( (*p) == 84 )
		goto st407;
	goto tr524;
st407:
	if ( ++p == pe )
		goto _test_eof407;
case 407:
	if ( (*p) == 9 )
		goto tr531;
	goto tr524;
tr531:
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st408;
tr533:
#line 204 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_sample_name(*this);
    }
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st408;
st408:
	if ( ++p == pe )
		goto _test_eof408;
case 408:
#line 6325 "inc/vcf/validator_detail_v42.hpp"
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr532;
	goto tr524;
tr532:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st409;
tr536:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st409;
st409:
	if ( ++p == pe )
		goto _test_eof409;
case 409:
#line 6345 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr533;
		case 10: goto tr534;
		case 13: goto tr535;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr536;
	goto tr524;
tr522:
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
	goto st506;
tr534:
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
	goto st506;
st506:
	if ( ++p == pe )
		goto _test_eof506;
case 506:
#line 6396 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 10: goto tr672;
		case 13: goto tr673;
		case 60: goto tr675;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr674;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr674;
	} else
		goto tr674;
	goto tr671;
tr676:
#line 43 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st507;
tr672:
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
	goto st507;
st507:
	if ( ++p == pe )
		goto _test_eof507;
case 507:
#line 6443 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 10: goto tr676;
		case 13: goto tr677;
	}
	goto st0;
tr677:
#line 43 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st410;
tr673:
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
	goto st410;
st410:
	if ( ++p == pe )
		goto _test_eof410;
case 410:
#line 6481 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 10 )
		goto st507;
	goto st0;
tr683:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st411;
tr541:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st411;
tr674:
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
	goto st411;
st411:
	if ( ++p == pe )
		goto _test_eof411;
case 411:
#line 6516 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr540;
		case 61: goto tr541;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr541;
	} else if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr541;
	} else
		goto tr541;
	goto tr539;
tr540:
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
	goto st412;
tr599:
#line 218 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st412;
st412:
	if ( ++p == pe )
		goto _test_eof412;
case 412:
#line 6552 "inc/vcf/validator_detail_v42.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr543;
	goto tr542;
tr543:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st413;
tr545:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st413;
st413:
	if ( ++p == pe )
		goto _test_eof413;
case 413:
#line 6572 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 9 )
		goto tr544;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr545;
	goto tr542;
tr550:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st414;
tr544:
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
	goto st414;
st414:
	if ( ++p == pe )
		goto _test_eof414;
case 414:
#line 6597 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr547;
	} else if ( (*p) >= 33 )
		goto tr547;
	goto tr546;
tr547:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st415;
tr549:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st415;
st415:
	if ( ++p == pe )
		goto _test_eof415;
case 415:
#line 6620 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr548;
		case 59: goto tr550;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr549;
	goto tr546;
tr548:
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
	goto st416;
st416:
	if ( ++p == pe )
		goto _test_eof416;
case 416:
#line 6642 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 65: goto tr552;
		case 67: goto tr552;
		case 71: goto tr552;
		case 78: goto tr552;
		case 84: goto tr552;
		case 97: goto tr552;
		case 99: goto tr552;
		case 103: goto tr552;
		case 110: goto tr552;
		case 116: goto tr552;
	}
	goto tr551;
tr552:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st417;
tr554:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st417;
st417:
	if ( ++p == pe )
		goto _test_eof417;
case 417:
#line 6672 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr553;
		case 65: goto tr554;
		case 67: goto tr554;
		case 71: goto tr554;
		case 78: goto tr554;
		case 84: goto tr554;
		case 97: goto tr554;
		case 99: goto tr554;
		case 103: goto tr554;
		case 110: goto tr554;
		case 116: goto tr554;
	}
	goto tr551;
tr553:
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
	goto st418;
st418:
	if ( ++p == pe )
		goto _test_eof418;
case 418:
#line 6701 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 42: goto tr556;
		case 46: goto tr557;
		case 60: goto tr558;
		case 65: goto tr559;
		case 67: goto tr559;
		case 71: goto tr559;
		case 78: goto tr559;
		case 84: goto tr559;
		case 91: goto tr560;
		case 93: goto tr561;
		case 97: goto tr559;
		case 99: goto tr559;
		case 103: goto tr559;
		case 110: goto tr559;
		case 116: goto tr559;
	}
	goto tr555;
tr556:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st419;
tr620:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st419;
st419:
	if ( ++p == pe )
		goto _test_eof419;
case 419:
#line 6736 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr562;
		case 44: goto tr563;
	}
	goto tr555;
tr562:
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
	goto st420;
st420:
	if ( ++p == pe )
		goto _test_eof420;
case 420:
#line 6756 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 43: goto tr565;
		case 45: goto tr565;
		case 46: goto tr566;
		case 73: goto tr568;
		case 78: goto tr569;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr567;
	goto tr564;
tr565:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st421;
st421:
	if ( ++p == pe )
		goto _test_eof421;
case 421:
#line 6778 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 73 )
		goto tr571;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr570;
	goto tr564;
tr567:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st422;
tr570:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st422;
st422:
	if ( ++p == pe )
		goto _test_eof422;
case 422:
#line 6800 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr572;
		case 46: goto tr573;
		case 69: goto tr574;
		case 101: goto tr574;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr570;
	goto tr564;
tr572:
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
	goto st423;
st423:
	if ( ++p == pe )
		goto _test_eof423;
case 423:
#line 6824 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 46: goto tr577;
		case 58: goto tr576;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr576;
		} else if ( (*p) > 57 ) {
			if ( 60 <= (*p) && (*p) <= 64 )
				goto tr576;
		} else
			goto tr578;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr576;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr576;
		} else
			goto tr578;
	} else
		goto tr578;
	goto tr575;
tr576:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st424;
st424:
	if ( ++p == pe )
		goto _test_eof424;
case 424:
#line 6858 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 58 )
		goto st424;
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto st424;
		} else if ( (*p) > 57 ) {
			if ( 60 <= (*p) && (*p) <= 64 )
				goto st424;
		} else
			goto tr580;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st424;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st424;
		} else
			goto tr580;
	} else
		goto tr580;
	goto tr575;
tr578:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st425;
tr580:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st425;
st425:
	if ( ++p == pe )
		goto _test_eof425;
case 425:
#line 6898 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr581;
		case 59: goto tr582;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr580;
	goto tr575;
tr581:
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
	goto st426;
st426:
	if ( ++p == pe )
		goto _test_eof426;
case 426:
#line 6920 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 46: goto tr584;
		case 49: goto tr585;
		case 95: goto tr586;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr586;
	} else if ( (*p) >= 65 )
		goto tr586;
	goto tr583;
tr584:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st508;
st508:
	if ( ++p == pe )
		goto _test_eof508;
case 508:
#line 6943 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr679;
		case 10: goto tr680;
		case 13: goto tr681;
	}
	goto tr678;
tr591:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st427;
tr679:
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
	goto st427;
st427:
	if ( ++p == pe )
		goto _test_eof427;
case 427:
#line 6969 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr588;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr588;
	} else
		goto tr588;
	goto tr587;
tr588:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st428;
tr590:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st428;
st428:
	if ( ++p == pe )
		goto _test_eof428;
case 428:
#line 6995 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr589;
		case 58: goto tr591;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr590;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr590;
	} else
		goto tr590;
	goto tr587;
tr589:
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
	goto st429;
st429:
	if ( ++p == pe )
		goto _test_eof429;
case 429:
#line 7023 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 46 )
		goto tr594;
	if ( (*p) < 48 ) {
		if ( 33 <= (*p) && (*p) <= 47 )
			goto tr593;
	} else if ( (*p) > 57 ) {
		if ( 59 <= (*p) && (*p) <= 126 )
			goto tr593;
	} else
		goto tr595;
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
	goto st509;
tr603:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st509;
st509:
	if ( ++p == pe )
		goto _test_eof509;
case 509:
#line 7051 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr589;
		case 10: goto tr680;
		case 13: goto tr681;
		case 58: goto tr682;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr603;
	goto tr602;
tr680:
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
	goto st510;
st510:
	if ( ++p == pe )
		goto _test_eof510;
case 510:
#line 7113 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 10: goto tr676;
		case 13: goto tr677;
		case 60: goto st430;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr683;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr683;
	} else
		goto tr683;
	goto tr539;
tr675:
#line 70 "src/vcf/vcf.ragel"
	{
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (Error *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
    }
	goto st430;
st430:
	if ( ++p == pe )
		goto _test_eof430;
case 430:
#line 7140 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr596;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr596;
	} else
		goto tr596;
	goto tr539;
tr596:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st431;
tr597:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st431;
st431:
	if ( ++p == pe )
		goto _test_eof431;
case 431:
#line 7166 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 62 )
		goto tr598;
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr597;
	} else if ( (*p) > 59 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr597;
	} else
		goto tr597;
	goto tr539;
tr598:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st432;
st432:
	if ( ++p == pe )
		goto _test_eof432;
case 432:
#line 7186 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 9 )
		goto tr599;
	goto tr539;
tr681:
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
	goto st433;
st433:
	if ( ++p == pe )
		goto _test_eof433;
case 433:
#line 7242 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 10 )
		goto st510;
	goto tr600;
tr682:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st434;
st434:
	if ( ++p == pe )
		goto _test_eof434;
case 434:
#line 7254 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) > 57 ) {
		if ( 59 <= (*p) && (*p) <= 126 )
			goto tr603;
	} else if ( (*p) >= 33 )
		goto tr603;
	goto tr602;
tr594:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st511;
tr686:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st511;
st511:
	if ( ++p == pe )
		goto _test_eof511;
case 511:
#line 7277 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr589;
		case 10: goto tr680;
		case 13: goto tr681;
		case 47: goto tr685;
		case 58: goto tr682;
		case 124: goto tr685;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr603;
	goto tr592;
tr685:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st512;
st512:
	if ( ++p == pe )
		goto _test_eof512;
case 512:
#line 7297 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr589;
		case 10: goto tr680;
		case 13: goto tr681;
		case 46: goto tr686;
		case 58: goto tr682;
	}
	if ( (*p) < 48 ) {
		if ( 33 <= (*p) && (*p) <= 47 )
			goto tr603;
	} else if ( (*p) > 57 ) {
		if ( 59 <= (*p) && (*p) <= 126 )
			goto tr603;
	} else
		goto tr687;
	goto tr592;
tr595:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st513;
tr687:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st513;
st513:
	if ( ++p == pe )
		goto _test_eof513;
case 513:
#line 7330 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr589;
		case 10: goto tr680;
		case 13: goto tr681;
		case 47: goto tr685;
		case 58: goto tr682;
		case 124: goto tr685;
	}
	if ( (*p) < 48 ) {
		if ( 33 <= (*p) && (*p) <= 46 )
			goto tr603;
	} else if ( (*p) > 57 ) {
		if ( 59 <= (*p) && (*p) <= 126 )
			goto tr603;
	} else
		goto tr687;
	goto tr592;
tr585:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st435;
st435:
	if ( ++p == pe )
		goto _test_eof435;
case 435:
#line 7359 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 48 )
		goto tr604;
	goto tr583;
tr604:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st436;
st436:
	if ( ++p == pe )
		goto _test_eof436;
case 436:
#line 7371 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 48 )
		goto tr605;
	goto tr583;
tr605:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st437;
st437:
	if ( ++p == pe )
		goto _test_eof437;
case 437:
#line 7383 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 48 )
		goto tr606;
	goto tr583;
tr606:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st438;
st438:
	if ( ++p == pe )
		goto _test_eof438;
case 438:
#line 7395 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 71 )
		goto tr607;
	goto tr583;
tr607:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st514;
st514:
	if ( ++p == pe )
		goto _test_eof514;
case 514:
#line 7407 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr679;
		case 10: goto tr680;
		case 13: goto tr681;
		case 59: goto tr688;
		case 61: goto tr689;
	}
	goto tr583;
tr688:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st439;
st439:
	if ( ++p == pe )
		goto _test_eof439;
case 439:
#line 7424 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 49: goto tr585;
		case 95: goto tr586;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr586;
	} else if ( (*p) >= 65 )
		goto tr586;
	goto tr583;
tr586:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st515;
tr690:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st515;
st515:
	if ( ++p == pe )
		goto _test_eof515;
case 515:
#line 7451 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr679;
		case 10: goto tr680;
		case 13: goto tr681;
		case 46: goto tr690;
		case 59: goto tr688;
		case 61: goto tr689;
		case 95: goto tr690;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr690;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr690;
	} else
		goto tr690;
	goto tr583;
tr689:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st440;
st440:
	if ( ++p == pe )
		goto _test_eof440;
case 440:
#line 7478 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr609;
	} else if ( (*p) >= 33 )
		goto tr609;
	goto tr608;
tr609:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st516;
st516:
	if ( ++p == pe )
		goto _test_eof516;
case 516:
#line 7493 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr679;
		case 10: goto tr680;
		case 13: goto tr681;
		case 59: goto tr688;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr609;
	goto tr608;
tr582:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st441;
st441:
	if ( ++p == pe )
		goto _test_eof441;
case 441:
#line 7511 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 58 )
		goto tr576;
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr576;
		} else if ( (*p) > 57 ) {
			if ( 60 <= (*p) && (*p) <= 64 )
				goto tr576;
		} else
			goto tr578;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr576;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr576;
		} else
			goto tr578;
	} else
		goto tr578;
	goto tr575;
tr577:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st442;
st442:
	if ( ++p == pe )
		goto _test_eof442;
case 442:
#line 7546 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr581;
		case 58: goto st424;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto st424;
		} else if ( (*p) > 57 ) {
			if ( 60 <= (*p) && (*p) <= 64 )
				goto st424;
		} else
			goto tr580;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st424;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st424;
		} else
			goto tr580;
	} else
		goto tr580;
	goto tr575;
tr573:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st443;
st443:
	if ( ++p == pe )
		goto _test_eof443;
case 443:
#line 7580 "inc/vcf/validator_detail_v42.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr610;
	goto tr564;
tr610:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st444;
st444:
	if ( ++p == pe )
		goto _test_eof444;
case 444:
#line 7592 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr572;
		case 69: goto tr574;
		case 101: goto tr574;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr610;
	goto tr564;
tr574:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st445;
st445:
	if ( ++p == pe )
		goto _test_eof445;
case 445:
#line 7609 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 43: goto tr611;
		case 45: goto tr611;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr612;
	goto tr564;
tr611:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st446;
st446:
	if ( ++p == pe )
		goto _test_eof446;
case 446:
#line 7625 "inc/vcf/validator_detail_v42.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr612;
	goto tr564;
tr612:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st447;
st447:
	if ( ++p == pe )
		goto _test_eof447;
case 447:
#line 7637 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 9 )
		goto tr572;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr612;
	goto tr564;
tr568:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st448;
tr571:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st448;
st448:
	if ( ++p == pe )
		goto _test_eof448;
case 448:
#line 7659 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 110 )
		goto tr613;
	goto tr564;
tr613:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st449;
st449:
	if ( ++p == pe )
		goto _test_eof449;
case 449:
#line 7671 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 102 )
		goto tr614;
	goto tr564;
tr566:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st450;
tr614:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st450;
st450:
	if ( ++p == pe )
		goto _test_eof450;
case 450:
#line 7691 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 9 )
		goto tr572;
	goto tr564;
tr569:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st451;
st451:
	if ( ++p == pe )
		goto _test_eof451;
case 451:
#line 7706 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 97 )
		goto tr615;
	goto tr564;
tr615:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st452;
st452:
	if ( ++p == pe )
		goto _test_eof452;
case 452:
#line 7718 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 78 )
		goto tr614;
	goto tr564;
tr563:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st453;
st453:
	if ( ++p == pe )
		goto _test_eof453;
case 453:
#line 7730 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 42: goto tr556;
		case 46: goto tr616;
		case 60: goto tr558;
		case 65: goto tr559;
		case 67: goto tr559;
		case 71: goto tr559;
		case 78: goto tr559;
		case 84: goto tr559;
		case 91: goto tr560;
		case 93: goto tr561;
		case 97: goto tr559;
		case 99: goto tr559;
		case 103: goto tr559;
		case 110: goto tr559;
		case 116: goto tr559;
	}
	goto tr555;
tr616:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st454;
tr652:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st454;
st454:
	if ( ++p == pe )
		goto _test_eof454;
case 454:
#line 7765 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 65: goto tr617;
		case 67: goto tr617;
		case 71: goto tr617;
		case 78: goto tr617;
		case 84: goto tr617;
		case 97: goto tr617;
		case 99: goto tr617;
		case 103: goto tr617;
		case 110: goto tr617;
		case 116: goto tr617;
	}
	goto tr555;
tr617:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st455;
st455:
	if ( ++p == pe )
		goto _test_eof455;
case 455:
#line 7787 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr562;
		case 44: goto tr563;
		case 65: goto tr617;
		case 67: goto tr617;
		case 71: goto tr617;
		case 78: goto tr617;
		case 84: goto tr617;
		case 97: goto tr617;
		case 99: goto tr617;
		case 103: goto tr617;
		case 110: goto tr617;
		case 116: goto tr617;
	}
	goto tr555;
tr558:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st456;
tr618:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st456;
st456:
	if ( ++p == pe )
		goto _test_eof456;
case 456:
#line 7819 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 61 )
		goto tr618;
	if ( (*p) < 63 ) {
		if ( (*p) < 45 ) {
			if ( 33 <= (*p) && (*p) <= 43 )
				goto tr618;
		} else if ( (*p) > 47 ) {
			if ( (*p) > 57 ) {
				if ( 58 <= (*p) && (*p) <= 59 )
					goto tr618;
			} else if ( (*p) >= 48 )
				goto tr619;
		} else
			goto tr618;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr619;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr618;
			} else if ( (*p) >= 97 )
				goto tr619;
		} else
			goto tr618;
	} else
		goto tr618;
	goto tr555;
tr619:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st457;
st457:
	if ( ++p == pe )
		goto _test_eof457;
case 457:
#line 7857 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 62 )
		goto tr620;
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr619;
	} else if ( (*p) > 59 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr619;
	} else
		goto tr619;
	goto tr555;
tr559:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st458;
tr621:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st458;
st458:
	if ( ++p == pe )
		goto _test_eof458;
case 458:
#line 7885 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr562;
		case 44: goto tr563;
		case 46: goto tr620;
		case 65: goto tr621;
		case 67: goto tr621;
		case 71: goto tr621;
		case 78: goto tr621;
		case 84: goto tr621;
		case 91: goto tr622;
		case 93: goto tr623;
		case 97: goto tr621;
		case 99: goto tr621;
		case 103: goto tr621;
		case 110: goto tr621;
		case 116: goto tr621;
	}
	goto tr555;
tr622:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st459;
st459:
	if ( ++p == pe )
		goto _test_eof459;
case 459:
#line 7912 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 60 )
		goto tr625;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr624;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr624;
	} else
		goto tr624;
	goto tr555;
tr624:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st460;
st460:
	if ( ++p == pe )
		goto _test_eof460;
case 460:
#line 7932 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 58: goto tr626;
		case 61: goto tr624;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr624;
	} else if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr624;
	} else
		goto tr624;
	goto tr555;
tr626:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st461;
st461:
	if ( ++p == pe )
		goto _test_eof461;
case 461:
#line 7954 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 58: goto tr626;
		case 59: goto tr624;
		case 61: goto tr624;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr624;
	} else if ( (*p) > 47 ) {
		if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 126 )
				goto tr624;
		} else if ( (*p) >= 48 )
			goto tr627;
	} else
		goto tr624;
	goto tr555;
tr627:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st462;
st462:
	if ( ++p == pe )
		goto _test_eof462;
case 462:
#line 7980 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 58: goto tr626;
		case 59: goto tr624;
		case 61: goto tr624;
		case 91: goto tr628;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr624;
	} else if ( (*p) > 47 ) {
		if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 126 )
				goto tr624;
		} else if ( (*p) >= 48 )
			goto tr627;
	} else
		goto tr624;
	goto tr555;
tr628:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st463;
st463:
	if ( ++p == pe )
		goto _test_eof463;
case 463:
#line 8007 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr562;
		case 44: goto tr563;
		case 58: goto tr626;
		case 61: goto tr624;
	}
	if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr624;
	} else if ( (*p) >= 33 )
		goto tr624;
	goto tr555;
tr625:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st464;
st464:
	if ( ++p == pe )
		goto _test_eof464;
case 464:
#line 8028 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr629;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr629;
	} else
		goto tr629;
	goto tr555;
tr629:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st465;
st465:
	if ( ++p == pe )
		goto _test_eof465;
case 465:
#line 8046 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 62 )
		goto tr630;
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr629;
	} else if ( (*p) > 59 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr629;
	} else
		goto tr629;
	goto tr555;
tr630:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st466;
st466:
	if ( ++p == pe )
		goto _test_eof466;
case 466:
#line 8066 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 58 )
		goto tr631;
	goto tr555;
tr631:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st467;
st467:
	if ( ++p == pe )
		goto _test_eof467;
case 467:
#line 8078 "inc/vcf/validator_detail_v42.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr632;
	goto tr555;
tr632:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st468;
st468:
	if ( ++p == pe )
		goto _test_eof468;
case 468:
#line 8090 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 91 )
		goto tr620;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr632;
	goto tr555;
tr623:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st469;
st469:
	if ( ++p == pe )
		goto _test_eof469;
case 469:
#line 8104 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 60 )
		goto tr634;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr633;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr633;
	} else
		goto tr633;
	goto tr555;
tr633:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st470;
st470:
	if ( ++p == pe )
		goto _test_eof470;
case 470:
#line 8124 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 58: goto tr635;
		case 61: goto tr633;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr633;
	} else if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr633;
	} else
		goto tr633;
	goto tr555;
tr635:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st471;
st471:
	if ( ++p == pe )
		goto _test_eof471;
case 471:
#line 8146 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 58: goto tr635;
		case 59: goto tr633;
		case 61: goto tr633;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr633;
	} else if ( (*p) > 47 ) {
		if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 126 )
				goto tr633;
		} else if ( (*p) >= 48 )
			goto tr636;
	} else
		goto tr633;
	goto tr555;
tr636:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st472;
st472:
	if ( ++p == pe )
		goto _test_eof472;
case 472:
#line 8172 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 58: goto tr635;
		case 59: goto tr633;
		case 61: goto tr633;
		case 93: goto tr637;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr633;
	} else if ( (*p) > 47 ) {
		if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 126 )
				goto tr633;
		} else if ( (*p) >= 48 )
			goto tr636;
	} else
		goto tr633;
	goto tr555;
tr637:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st473;
st473:
	if ( ++p == pe )
		goto _test_eof473;
case 473:
#line 8199 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr562;
		case 44: goto tr563;
		case 58: goto tr635;
		case 61: goto tr633;
	}
	if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr633;
	} else if ( (*p) >= 33 )
		goto tr633;
	goto tr555;
tr634:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st474;
st474:
	if ( ++p == pe )
		goto _test_eof474;
case 474:
#line 8220 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr638;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr638;
	} else
		goto tr638;
	goto tr555;
tr638:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st475;
st475:
	if ( ++p == pe )
		goto _test_eof475;
case 475:
#line 8238 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 62 )
		goto tr639;
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr638;
	} else if ( (*p) > 59 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr638;
	} else
		goto tr638;
	goto tr555;
tr639:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st476;
st476:
	if ( ++p == pe )
		goto _test_eof476;
case 476:
#line 8258 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 58 )
		goto tr640;
	goto tr555;
tr640:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st477;
st477:
	if ( ++p == pe )
		goto _test_eof477;
case 477:
#line 8270 "inc/vcf/validator_detail_v42.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr641;
	goto tr555;
tr641:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st478;
st478:
	if ( ++p == pe )
		goto _test_eof478;
case 478:
#line 8282 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 93 )
		goto tr620;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr641;
	goto tr555;
tr560:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st479;
st479:
	if ( ++p == pe )
		goto _test_eof479;
case 479:
#line 8299 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 60 )
		goto tr643;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr642;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr642;
	} else
		goto tr642;
	goto tr555;
tr642:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st480;
st480:
	if ( ++p == pe )
		goto _test_eof480;
case 480:
#line 8319 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 58: goto tr644;
		case 61: goto tr642;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr642;
	} else if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr642;
	} else
		goto tr642;
	goto tr555;
tr644:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st481;
st481:
	if ( ++p == pe )
		goto _test_eof481;
case 481:
#line 8341 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 58: goto tr644;
		case 59: goto tr642;
		case 61: goto tr642;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr642;
	} else if ( (*p) > 47 ) {
		if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 126 )
				goto tr642;
		} else if ( (*p) >= 48 )
			goto tr645;
	} else
		goto tr642;
	goto tr555;
tr645:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st482;
st482:
	if ( ++p == pe )
		goto _test_eof482;
case 482:
#line 8367 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 58: goto tr644;
		case 59: goto tr642;
		case 61: goto tr642;
		case 91: goto tr646;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr642;
	} else if ( (*p) > 47 ) {
		if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 126 )
				goto tr642;
		} else if ( (*p) >= 48 )
			goto tr645;
	} else
		goto tr642;
	goto tr555;
tr646:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st483;
st483:
	if ( ++p == pe )
		goto _test_eof483;
case 483:
#line 8394 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 58: goto tr644;
		case 61: goto tr642;
		case 65: goto tr647;
		case 67: goto tr647;
		case 71: goto tr647;
		case 78: goto tr647;
		case 84: goto tr647;
		case 97: goto tr647;
		case 99: goto tr647;
		case 103: goto tr647;
		case 110: goto tr647;
		case 116: goto tr647;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr642;
	} else if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr642;
	} else
		goto tr642;
	goto tr555;
tr647:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st484;
st484:
	if ( ++p == pe )
		goto _test_eof484;
case 484:
#line 8426 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr562;
		case 44: goto tr563;
		case 58: goto tr644;
		case 61: goto tr642;
		case 65: goto tr647;
		case 67: goto tr647;
		case 71: goto tr647;
		case 78: goto tr647;
		case 84: goto tr647;
		case 97: goto tr647;
		case 99: goto tr647;
		case 103: goto tr647;
		case 110: goto tr647;
		case 116: goto tr647;
	}
	if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr642;
	} else if ( (*p) >= 33 )
		goto tr642;
	goto tr555;
tr643:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st485;
st485:
	if ( ++p == pe )
		goto _test_eof485;
case 485:
#line 8457 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr648;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr648;
	} else
		goto tr648;
	goto tr555;
tr648:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st486;
st486:
	if ( ++p == pe )
		goto _test_eof486;
case 486:
#line 8475 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 62 )
		goto tr649;
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr648;
	} else if ( (*p) > 59 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr648;
	} else
		goto tr648;
	goto tr555;
tr649:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st487;
st487:
	if ( ++p == pe )
		goto _test_eof487;
case 487:
#line 8495 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 58 )
		goto tr650;
	goto tr555;
tr650:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st488;
st488:
	if ( ++p == pe )
		goto _test_eof488;
case 488:
#line 8507 "inc/vcf/validator_detail_v42.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr651;
	goto tr555;
tr651:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st489;
st489:
	if ( ++p == pe )
		goto _test_eof489;
case 489:
#line 8519 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 91 )
		goto tr652;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr651;
	goto tr555;
tr561:
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
case 490:
#line 8536 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 60 )
		goto tr654;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr653;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr653;
	} else
		goto tr653;
	goto tr555;
tr653:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st491;
st491:
	if ( ++p == pe )
		goto _test_eof491;
case 491:
#line 8556 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 58: goto tr655;
		case 61: goto tr653;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr653;
	} else if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr653;
	} else
		goto tr653;
	goto tr555;
tr655:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st492;
st492:
	if ( ++p == pe )
		goto _test_eof492;
case 492:
#line 8578 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 58: goto tr655;
		case 59: goto tr653;
		case 61: goto tr653;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr653;
	} else if ( (*p) > 47 ) {
		if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 126 )
				goto tr653;
		} else if ( (*p) >= 48 )
			goto tr656;
	} else
		goto tr653;
	goto tr555;
tr656:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st493;
st493:
	if ( ++p == pe )
		goto _test_eof493;
case 493:
#line 8604 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 58: goto tr655;
		case 59: goto tr653;
		case 61: goto tr653;
		case 93: goto tr657;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr653;
	} else if ( (*p) > 47 ) {
		if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 126 )
				goto tr653;
		} else if ( (*p) >= 48 )
			goto tr656;
	} else
		goto tr653;
	goto tr555;
tr657:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st494;
st494:
	if ( ++p == pe )
		goto _test_eof494;
case 494:
#line 8631 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 58: goto tr655;
		case 61: goto tr653;
		case 65: goto tr658;
		case 67: goto tr658;
		case 71: goto tr658;
		case 78: goto tr658;
		case 84: goto tr658;
		case 97: goto tr658;
		case 99: goto tr658;
		case 103: goto tr658;
		case 110: goto tr658;
		case 116: goto tr658;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr653;
	} else if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr653;
	} else
		goto tr653;
	goto tr555;
tr658:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st495;
st495:
	if ( ++p == pe )
		goto _test_eof495;
case 495:
#line 8663 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr562;
		case 44: goto tr563;
		case 58: goto tr655;
		case 61: goto tr653;
		case 65: goto tr658;
		case 67: goto tr658;
		case 71: goto tr658;
		case 78: goto tr658;
		case 84: goto tr658;
		case 97: goto tr658;
		case 99: goto tr658;
		case 103: goto tr658;
		case 110: goto tr658;
		case 116: goto tr658;
	}
	if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr653;
	} else if ( (*p) >= 33 )
		goto tr653;
	goto tr555;
tr654:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st496;
st496:
	if ( ++p == pe )
		goto _test_eof496;
case 496:
#line 8694 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr659;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr659;
	} else
		goto tr659;
	goto tr555;
tr659:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st497;
st497:
	if ( ++p == pe )
		goto _test_eof497;
case 497:
#line 8712 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 62 )
		goto tr660;
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr659;
	} else if ( (*p) > 59 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr659;
	} else
		goto tr659;
	goto tr555;
tr660:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st498;
st498:
	if ( ++p == pe )
		goto _test_eof498;
case 498:
#line 8732 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 58 )
		goto tr661;
	goto tr555;
tr661:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st499;
st499:
	if ( ++p == pe )
		goto _test_eof499;
case 499:
#line 8744 "inc/vcf/validator_detail_v42.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr662;
	goto tr555;
tr662:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st500;
st500:
	if ( ++p == pe )
		goto _test_eof500;
case 500:
#line 8756 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 93 )
		goto tr652;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr662;
	goto tr555;
tr557:
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
case 501:
#line 8773 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 9: goto tr562;
		case 65: goto tr617;
		case 67: goto tr617;
		case 71: goto tr617;
		case 78: goto tr617;
		case 84: goto tr617;
		case 97: goto tr617;
		case 99: goto tr617;
		case 103: goto tr617;
		case 110: goto tr617;
		case 116: goto tr617;
	}
	goto tr555;
tr523:
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
	goto st502;
tr535:
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
	goto st502;
st502:
	if ( ++p == pe )
		goto _test_eof502;
case 502:
#line 8830 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 10 )
		goto st506;
	goto tr524;
tr23:
#line 99 "src/vcf/vcf.ragel"
	{
        try {
          ParsePolicy::handle_fileformat(*this);
        } catch (Error *error) {
          ErrorPolicy::handle_error(*this, error);
          p--; {goto st504;}
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
	goto st503;
st503:
	if ( ++p == pe )
		goto _test_eof503;
case 503:
#line 8856 "inc/vcf/validator_detail_v42.hpp"
	if ( (*p) == 10 )
		goto st22;
	goto tr0;
tr667:
#line 43 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st504;
st504:
	if ( ++p == pe )
		goto _test_eof504;
case 504:
#line 8874 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 10: goto tr666;
		case 13: goto tr667;
	}
	goto st504;
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
#line 231 "src/vcf/vcf_v42.ragel"
	{ {goto st28;} }
	goto st517;
st517:
	if ( ++p == pe )
		goto _test_eof517;
case 517:
#line 8895 "inc/vcf/validator_detail_v42.hpp"
	goto st0;
tr670:
#line 43 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st505;
st505:
	if ( ++p == pe )
		goto _test_eof505;
case 505:
#line 8911 "inc/vcf/validator_detail_v42.hpp"
	switch( (*p) ) {
		case 10: goto tr669;
		case 13: goto tr670;
	}
	goto st505;
tr669:
#line 43 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
#line 232 "src/vcf/vcf_v42.ragel"
	{ {goto st510;} }
	goto st518;
st518:
	if ( ++p == pe )
		goto _test_eof518;
case 518:
#line 8932 "inc/vcf/validator_detail_v42.hpp"
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
	_test_eof506: cs = 506; goto _test_eof; 
	_test_eof507: cs = 507; goto _test_eof; 
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
	_test_eof508: cs = 508; goto _test_eof; 
	_test_eof427: cs = 427; goto _test_eof; 
	_test_eof428: cs = 428; goto _test_eof; 
	_test_eof429: cs = 429; goto _test_eof; 
	_test_eof509: cs = 509; goto _test_eof; 
	_test_eof510: cs = 510; goto _test_eof; 
	_test_eof430: cs = 430; goto _test_eof; 
	_test_eof431: cs = 431; goto _test_eof; 
	_test_eof432: cs = 432; goto _test_eof; 
	_test_eof433: cs = 433; goto _test_eof; 
	_test_eof434: cs = 434; goto _test_eof; 
	_test_eof511: cs = 511; goto _test_eof; 
	_test_eof512: cs = 512; goto _test_eof; 
	_test_eof513: cs = 513; goto _test_eof; 
	_test_eof435: cs = 435; goto _test_eof; 
	_test_eof436: cs = 436; goto _test_eof; 
	_test_eof437: cs = 437; goto _test_eof; 
	_test_eof438: cs = 438; goto _test_eof; 
	_test_eof514: cs = 514; goto _test_eof; 
	_test_eof439: cs = 439; goto _test_eof; 
	_test_eof515: cs = 515; goto _test_eof; 
	_test_eof440: cs = 440; goto _test_eof; 
	_test_eof516: cs = 516; goto _test_eof; 
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
	_test_eof517: cs = 517; goto _test_eof; 
	_test_eof505: cs = 505; goto _test_eof; 
	_test_eof518: cs = 518; goto _test_eof; 

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
	case 503: 
#line 60 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new FileformatError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
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
               goto _test_eof504;
goto st504;}
    }
	break;
	case 506: 
#line 70 "src/vcf/vcf.ragel"
	{
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (Error *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
    }
	break;
	case 401: 
	case 402: 
	case 403: 
	case 404: 
	case 405: 
	case 406: 
	case 407: 
	case 408: 
	case 409: 
	case 502: 
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
               goto _test_eof505;
goto st505;}
    }
	break;
	case 433: 
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof505;
goto st505;}
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
               goto _test_eof504;
goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
	break;
	case 283: 
	case 284: 
	case 285: 
	case 286: 
	case 287: 
	case 288: 
	case 289: 
	case 290: 
#line 271 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in assembly metadata"});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
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
#line 277 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in contig metadata"});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
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
               goto _test_eof504;
goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
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
               goto _test_eof504;
goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
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
               goto _test_eof504;
goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
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
	case 224: 
	case 231: 
#line 311 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
	break;
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
#line 332 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in pedigreeDB metadata"});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
	break;
	case 232: 
	case 233: 
	case 234: 
	case 235: 
	case 236: 
	case 237: 
	case 238: 
	case 239: 
	case 240: 
	case 241: 
	case 281: 
#line 359 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
	break;
	case 364: 
	case 365: 
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
               goto _test_eof505;
goto st505;}
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
               goto _test_eof505;
goto st505;}
    }
	break;
	case 411: 
	case 430: 
	case 431: 
	case 432: 
#line 408 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new ChromosomeBodyError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof505;
goto st505;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof505;
goto st505;}
    }
	break;
	case 412: 
	case 413: 
#line 414 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new PositionBodyError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof505;
goto st505;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof505;
goto st505;}
    }
	break;
	case 414: 
	case 415: 
#line 420 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new IdBodyError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof505;
goto st505;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof505;
goto st505;}
    }
	break;
	case 416: 
	case 417: 
#line 426 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new ReferenceAlleleBodyError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof505;
goto st505;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof505;
goto st505;}
    }
	break;
	case 418: 
	case 419: 
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
#line 432 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new AlternateAllelesBodyError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof505;
goto st505;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof505;
goto st505;}
    }
	break;
	case 420: 
	case 421: 
	case 422: 
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
#line 438 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new QualityBodyError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof505;
goto st505;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof505;
goto st505;}
    }
	break;
	case 423: 
	case 424: 
	case 425: 
	case 441: 
	case 442: 
#line 444 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new FilterBodyError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof505;
goto st505;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof505;
goto st505;}
    }
	break;
	case 434: 
#line 466 "src/vcf/vcf.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " is not a valid string";
        ErrorPolicy::handle_error(*this, new SamplesBodyError{n_lines, message_stream.str()});
        p--; {       if ( p == pe )
               goto _test_eof505;
goto st505;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof505;
goto st505;}
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
#line 29 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this,
                new FileformatError{n_lines, "The fileformat declaration is not 'fileformat=VCFv4.2'"});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
#line 60 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new FileformatError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
	break;
	case 427: 
	case 428: 
#line 50 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new FormatBodyError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof505;
goto st505;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof505;
goto st505;}
    }
	break;
	case 508: 
	case 509: 
	case 511: 
	case 512: 
	case 513: 
	case 514: 
	case 515: 
	case 516: 
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
	case 23: 
	case 28: 
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
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
               goto _test_eof505;
goto st505;}
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
               goto _test_eof505;
goto st505;}
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
               goto _test_eof504;
goto st504;}
    }
#line 259 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
	break;
	case 80: 
#line 283 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
	break;
	case 141: 
	case 142: 
#line 305 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "INFO metadata Type is not Integer, Float, Flag, Character or String"});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
	break;
	case 191: 
	case 192: 
#line 305 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "INFO metadata Type is not Integer, Float, Flag, Character or String"});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
	break;
	case 245: 
	case 246: 
	case 247: 
	case 248: 
	case 249: 
	case 250: 
	case 251: 
	case 252: 
	case 253: 
#line 364 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "SAMPLE metadata Genomes is not a valid string (maybe it contains quotes?)"});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
#line 359 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
	break;
	case 255: 
	case 256: 
	case 257: 
	case 258: 
	case 259: 
	case 260: 
	case 261: 
	case 262: 
	case 263: 
#line 369 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "SAMPLE metadata Mixture is not a valid string (maybe it contains quotes?)"});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
#line 359 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
	break;
	case 74: 
	case 75: 
	case 76: 
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
#line 259 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
	break;
	case 320: 
	case 321: 
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
#line 277 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in contig metadata"});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
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
               goto _test_eof504;
goto st504;}
    }
#line 283 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
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
               goto _test_eof504;
goto st504;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
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
               goto _test_eof504;
goto st504;}
    }
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
	break;
	case 225: 
	case 226: 
	case 227: 
	case 228: 
	case 229: 
	case 230: 
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
#line 311 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
	break;
	case 242: 
	case 243: 
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
#line 359 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
	break;
	case 71: 
	case 72: 
	case 73: 
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
#line 259 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
	break;
	case 106: 
	case 107: 
	case 108: 
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
#line 283 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
	break;
	case 156: 
	case 157: 
	case 158: 
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
	break;
	case 206: 
	case 207: 
	case 208: 
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
	break;
	case 265: 
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
	case 279: 
	case 280: 
	case 282: 
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
#line 359 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
	break;
	case 291: 
	case 292: 
	case 293: 
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
	case 304: 
	case 305: 
	case 306: 
	case 307: 
	case 308: 
	case 309: 
#line 385 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata URL is not valid"});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
#line 271 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in assembly metadata"});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
	break;
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
	case 360: 
	case 361: 
	case 362: 
	case 363: 
#line 385 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata URL is not valid"});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
#line 332 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in pedigreeDB metadata"});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
	break;
	case 426: 
	case 435: 
	case 436: 
	case 437: 
	case 438: 
	case 439: 
#line 455 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info key is not a sequence of alphanumeric and/or punctuation characters"});
        p--; {       if ( p == pe )
               goto _test_eof505;
goto st505;}
    }
#line 450 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {       if ( p == pe )
               goto _test_eof505;
goto st505;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof505;
goto st505;}
    }
	break;
	case 440: 
#line 460 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info field value is not a comma-separated list of valid strings (maybe it contains whitespaces?)"});
        p--; {       if ( p == pe )
               goto _test_eof505;
goto st505;}
    }
#line 450 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {       if ( p == pe )
               goto _test_eof505;
goto st505;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof505;
goto st505;}
    }
	break;
	case 429: 
#line 473 "src/vcf/vcf.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " does not start with a valid genotype";
        ErrorPolicy::handle_error(*this, new SamplesFieldBodyError{n_lines, message_stream.str(), "", "GT"});
        p--; {       if ( p == pe )
               goto _test_eof505;
goto st505;}
    }
#line 466 "src/vcf/vcf.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " is not a valid string";
        ErrorPolicy::handle_error(*this, new SamplesBodyError{n_lines, message_stream.str()});
        p--; {       if ( p == pe )
               goto _test_eof505;
goto st505;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof505;
goto st505;}
    }
	break;
	case 134: 
	case 135: 
	case 165: 
#line 36 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "FORMAT metadata Number is not a number, A, R, G or dot"});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
	break;
	case 184: 
	case 185: 
	case 215: 
#line 42 "src/vcf/vcf_v42.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "INFO metadata Number is not a number, A, R, G or dot"});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
	break;
	case 22: 
#line 60 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new FileformatError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
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
               goto _test_eof505;
goto st505;}
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
               goto _test_eof505;
goto st505;}
    }
	break;
	case 254: 
#line 364 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "SAMPLE metadata Genomes is not a valid string (maybe it contains quotes?)"});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
#line 369 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "SAMPLE metadata Mixture is not a valid string (maybe it contains quotes?)"});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
#line 359 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
	break;
	case 264: 
#line 369 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "SAMPLE metadata Mixture is not a valid string (maybe it contains quotes?)"});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
#line 359 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
	break;
	case 244: 
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
#line 364 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "SAMPLE metadata Genomes is not a valid string (maybe it contains quotes?)"});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
#line 359 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
	break;
	case 24: 
#line 259 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
#line 283 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
#line 271 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in assembly metadata"});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
#line 277 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in contig metadata"});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
#line 359 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
#line 311 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
#line 332 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in pedigreeDB metadata"});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof504;
goto st504;}
    }
	break;
#line 11024 "inc/vcf/validator_detail_v42.hpp"
	}
	}

	_out: {}
	}

#line 261 "src/vcf/vcf_v42.ragel"

    }

  }
}
