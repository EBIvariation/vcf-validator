
#line 1 "src/vcf/vcf_v41.ragel"
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


#line 229 "src/vcf/vcf_v41.ragel"


namespace
{
  
#line 27 "inc/vcf/validator_detail_v41.hpp"
static const int vcf_v41_start = 1;
static const int vcf_v41_first_final = 535;
static const int vcf_v41_error = 0;

static const int vcf_v41_en_main = 1;
static const int vcf_v41_en_main_meta_section = 28;
static const int vcf_v41_en_main_body_section = 539;
static const int vcf_v41_en_meta_section_skip = 533;
static const int vcf_v41_en_body_section_skip = 534;


#line 235 "src/vcf/vcf_v41.ragel"

}

namespace ebi
{
  namespace vcf
  {
    
    template <typename Configuration>
    ParserImpl_v41<Configuration>::ParserImpl_v41(std::shared_ptr<Source> source, AdditionalChecks additionalChecks)
    : ParserImpl{source, additionalChecks}
    {
      
#line 53 "inc/vcf/validator_detail_v41.hpp"
	{
	cs = vcf_v41_start;
	}

#line 249 "src/vcf/vcf_v41.ragel"

    }

    template <typename Configuration>
    void ParserImpl_v41<Configuration>::parse_buffer(char const * p, char const * pe, char const * eof)
    {
      
#line 66 "inc/vcf/validator_detail_v41.hpp"
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
        p--; {goto st533;}
    }
	goto st0;
tr14:
#line 29 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this,
                new FileformatError{n_lines, "The fileformat declaration is not 'fileformat=VCFv4.1'"});
        p--; {goto st533;}
    }
#line 60 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new FileformatError{n_lines});
        p--; {goto st533;}
    }
	goto st0;
tr24:
#line 60 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new FileformatError{n_lines});
        p--; {goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st533;}
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
        
        p--; {goto st534;}
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
        
        p--; {goto st534;}
    }
	goto st0;
tr26:
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st533;}
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
        
        p--; {goto st534;}
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
        
        p--; {goto st534;}
    }
	goto st0;
tr29:
#line 259 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {goto st533;}
    }
#line 283 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {goto st533;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st533;}
    }
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st533;}
    }
#line 271 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in assembly metadata"});
        p--; {goto st533;}
    }
#line 277 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in contig metadata"});
        p--; {goto st533;}
    }
#line 359 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st533;}
    }
#line 311 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {goto st533;}
    }
#line 332 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in pedigreeDB metadata"});
        p--; {goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st533;}
    }
	goto st0;
tr39:
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st533;}
    }
	goto st0;
tr125:
#line 259 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st533;}
    }
	goto st0;
tr133:
#line 264 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines,
            "ALT metadata ID is not prefixed by DEL/INS/DUP/INV/CNV/BND and suffixed by ':' and a text sequence"});
        p--; {goto st533;}
    }
#line 259 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st533;}
    }
	goto st0;
tr152:
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st533;}
    }
#line 259 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st533;}
    }
	goto st0;
tr162:
#line 283 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {goto st533;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st533;}
    }
	goto st0;
tr165:
#line 283 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st533;}
    }
	goto st0;
tr175:
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st533;}
    }
#line 283 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st533;}
    }
	goto st0;
tr194:
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st533;}
    }
#line 283 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st533;}
    }
	goto st0;
tr204:
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st533;}
    }
	goto st0;
tr214:
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st533;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st533;}
    }
	goto st0;
tr227:
#line 36 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "FORMAT metadata Number is not a number, A, G or dot"});
        p--; {goto st533;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st533;}
    }
	goto st0;
tr236:
#line 305 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "INFO metadata Type is not Integer, Float, Flag, Character or String"});
        p--; {goto st533;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st533;}
    }
	goto st0;
tr253:
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st533;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st533;}
    }
	goto st0;
tr264:
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st533;}
    }
	goto st0;
tr273:
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st533;}
    }
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st533;}
    }
	goto st0;
tr286:
#line 42 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "INFO metadata Number is not a number, A, G or dot"});
        p--; {goto st533;}
    }
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st533;}
    }
	goto st0;
tr295:
#line 305 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "INFO metadata Type is not Integer, Float, Flag, Character or String"});
        p--; {goto st533;}
    }
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st533;}
    }
	goto st0;
tr312:
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st533;}
    }
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st533;}
    }
	goto st0;
tr323:
#line 311 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st533;}
    }
	goto st0;
tr333:
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st533;}
    }
#line 311 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st533;}
    }
	goto st0;
tr345:
#line 359 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st533;}
    }
	goto st0;
tr356:
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st533;}
    }
#line 359 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st533;}
    }
	goto st0;
tr361:
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st533;}
    }
#line 364 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "SAMPLE metadata Genomes is not a valid string (maybe it contains quotes?)"});
        p--; {goto st533;}
    }
#line 359 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st533;}
    }
	goto st0;
tr363:
#line 364 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "SAMPLE metadata Genomes is not a valid string (maybe it contains quotes?)"});
        p--; {goto st533;}
    }
#line 359 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st533;}
    }
	goto st0;
tr373:
#line 364 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "SAMPLE metadata Genomes is not a valid string (maybe it contains quotes?)"});
        p--; {goto st533;}
    }
#line 369 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "SAMPLE metadata Mixture is not a valid string (maybe it contains quotes?)"});
        p--; {goto st533;}
    }
#line 359 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st533;}
    }
	goto st0;
tr376:
#line 369 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "SAMPLE metadata Mixture is not a valid string (maybe it contains quotes?)"});
        p--; {goto st533;}
    }
#line 359 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st533;}
    }
	goto st0;
tr386:
#line 369 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "SAMPLE metadata Mixture is not a valid string (maybe it contains quotes?)"});
        p--; {goto st533;}
    }
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st533;}
    }
#line 359 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st533;}
    }
	goto st0;
tr389:
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st533;}
    }
#line 359 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st533;}
    }
	goto st0;
tr412:
#line 271 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in assembly metadata"});
        p--; {goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st533;}
    }
	goto st0;
tr421:
#line 385 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata URL is not valid"});
        p--; {goto st533;}
    }
#line 271 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in assembly metadata"});
        p--; {goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st533;}
    }
	goto st0;
tr442:
#line 277 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in contig metadata"});
        p--; {goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st533;}
    }
	goto st0;
tr453:
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st533;}
    }
#line 277 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in contig metadata"});
        p--; {goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st533;}
    }
	goto st0;
tr491:
#line 332 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in pedigreeDB metadata"});
        p--; {goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st533;}
    }
	goto st0;
tr503:
#line 385 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata URL is not valid"});
        p--; {goto st533;}
    }
#line 332 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in pedigreeDB metadata"});
        p--; {goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st533;}
    }
	goto st0;
tr526:
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
        
        p--; {goto st534;}
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
        
        p--; {goto st534;}
    }
	goto st0;
tr566:
#line 78 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new HeaderSectionError{n_lines});
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (Error *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
        
        p--; {goto st534;}
    }
	goto st0;
tr581:
#line 408 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new ChromosomeBodyError{n_lines});
        p--; {goto st534;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st534;}
    }
	goto st0;
tr584:
#line 414 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new PositionBodyError{n_lines});
        p--; {goto st534;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st534;}
    }
	goto st0;
tr588:
#line 420 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new IdBodyError{n_lines});
        p--; {goto st534;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st534;}
    }
	goto st0;
tr593:
#line 426 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new ReferenceAlleleBodyError{n_lines});
        p--; {goto st534;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st534;}
    }
	goto st0;
tr597:
#line 432 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new AlternateAllelesBodyError{n_lines});
        p--; {goto st534;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st534;}
    }
	goto st0;
tr606:
#line 438 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new QualityBodyError{n_lines});
        p--; {goto st534;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st534;}
    }
	goto st0;
tr617:
#line 444 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new FilterBodyError{n_lines});
        p--; {goto st534;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st534;}
    }
	goto st0;
tr625:
#line 455 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info key is not a sequence of alphanumeric and/or punctuation characters"});
        p--; {goto st534;}
    }
#line 450 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st534;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st534;}
    }
	goto st0;
tr629:
#line 50 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new FormatBodyError{n_lines});
        p--; {goto st534;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st534;}
    }
	goto st0;
tr634:
#line 473 "src/vcf/vcf.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " does not start with a valid genotype";
        ErrorPolicy::handle_error(*this, new SamplesFieldBodyError{n_lines, message_stream.str(), "", "GT"});
        p--; {goto st534;}
    }
#line 466 "src/vcf/vcf.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " is not a valid string";
        ErrorPolicy::handle_error(*this, new SamplesBodyError{n_lines, message_stream.str()});
        p--; {goto st534;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st534;}
    }
	goto st0;
tr642:
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st534;}
    }
	goto st0;
tr644:
#line 466 "src/vcf/vcf.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " is not a valid string";
        ErrorPolicy::handle_error(*this, new SamplesBodyError{n_lines, message_stream.str()});
        p--; {goto st534;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st534;}
    }
	goto st0;
tr650:
#line 460 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info field value is not a comma-separated list of valid strings (maybe it contains whitespaces?)"});
        p--; {goto st534;}
    }
#line 450 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st534;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st534;}
    }
	goto st0;
tr713:
#line 78 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new HeaderSectionError{n_lines});
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (Error *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
        
        p--; {goto st534;}
    }
#line 408 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new ChromosomeBodyError{n_lines});
        p--; {goto st534;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st534;}
    }
	goto st0;
tr720:
#line 450 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st534;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st534;}
    }
	goto st0;
#line 1013 "inc/vcf/validator_detail_v41.hpp"
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
#line 1122 "inc/vcf/validator_detail_v41.hpp"
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
#line 1136 "inc/vcf/validator_detail_v41.hpp"
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
#line 1150 "inc/vcf/validator_detail_v41.hpp"
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
#line 1164 "inc/vcf/validator_detail_v41.hpp"
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
#line 1178 "inc/vcf/validator_detail_v41.hpp"
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
#line 1192 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 49 )
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
#line 1206 "inc/vcf/validator_detail_v41.hpp"
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
          p--; {goto st533;}
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
#line 1237 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 35 )
		goto st23;
	goto tr24;
st23:
	if ( ++p == pe )
		goto _test_eof23;
case 23:
	switch( (*p) ) {
		case 35: goto st24;
		case 67: goto st393;
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
#line 1290 "inc/vcf/validator_detail_v41.hpp"
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
#line 1306 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto st30;
		case 60: goto st35;
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
#line 1334 "inc/vcf/validator_detail_v41.hpp"
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
#line 1390 "inc/vcf/validator_detail_v41.hpp"
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
#line 1442 "inc/vcf/validator_detail_v41.hpp"
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
#line 1477 "inc/vcf/validator_detail_v41.hpp"
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
#line 1505 "inc/vcf/validator_detail_v41.hpp"
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
#line 1531 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr57;
		case 92: goto tr54;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr52;
	goto tr39;
tr57:
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
case 34:
#line 1553 "inc/vcf/validator_detail_v41.hpp"
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
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st37;
tr64:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st37;
st37:
	if ( ++p == pe )
		goto _test_eof37;
case 37:
#line 1614 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr65;
		case 92: goto tr66;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr64;
	goto tr39;
tr62:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st38;
tr65:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st38;
st38:
	if ( ++p == pe )
		goto _test_eof38;
case 38:
#line 1642 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 62 )
		goto st32;
	goto tr39;
tr63:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st39;
tr66:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st39;
st39:
	if ( ++p == pe )
		goto _test_eof39;
case 39:
#line 1666 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr68;
		case 92: goto tr66;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr64;
	goto tr39;
tr68:
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
case 40:
#line 1688 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr65;
		case 62: goto tr69;
		case 92: goto tr66;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr64;
	goto tr39;
tr69:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st41;
st41:
	if ( ++p == pe )
		goto _test_eof41;
case 41:
#line 1707 "inc/vcf/validator_detail_v41.hpp"
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
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st42;
st42:
	if ( ++p == pe )
		goto _test_eof42;
case 42:
#line 1727 "inc/vcf/validator_detail_v41.hpp"
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
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st43;
tr71:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st43;
st43:
	if ( ++p == pe )
		goto _test_eof43;
case 43:
#line 1762 "inc/vcf/validator_detail_v41.hpp"
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
#line 192 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st44;
st44:
	if ( ++p == pe )
		goto _test_eof44;
case 44:
#line 1789 "inc/vcf/validator_detail_v41.hpp"
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
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st45;
tr75:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st45;
st45:
	if ( ++p == pe )
		goto _test_eof45;
case 45:
#line 1821 "inc/vcf/validator_detail_v41.hpp"
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
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st46;
st46:
	if ( ++p == pe )
		goto _test_eof46;
case 46:
#line 1842 "inc/vcf/validator_detail_v41.hpp"
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
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st47;
st47:
	if ( ++p == pe )
		goto _test_eof47;
case 47:
#line 1867 "inc/vcf/validator_detail_v41.hpp"
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
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st48;
tr80:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st48;
st48:
	if ( ++p == pe )
		goto _test_eof48;
case 48:
#line 1902 "inc/vcf/validator_detail_v41.hpp"
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
#line 192 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st49;
st49:
	if ( ++p == pe )
		goto _test_eof49;
case 49:
#line 1929 "inc/vcf/validator_detail_v41.hpp"
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
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st51;
tr86:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st51;
st51:
	if ( ++p == pe )
		goto _test_eof51;
case 51:
#line 1972 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr87;
		case 92: goto tr88;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr86;
	goto tr39;
tr84:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st52;
tr87:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st52;
st52:
	if ( ++p == pe )
		goto _test_eof52;
case 52:
#line 2000 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 44: goto st46;
		case 62: goto st32;
	}
	goto tr39;
tr85:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st53;
tr88:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st53;
st53:
	if ( ++p == pe )
		goto _test_eof53;
case 53:
#line 2026 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr90;
		case 92: goto tr88;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr86;
	goto tr39;
tr90:
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
case 54:
#line 2048 "inc/vcf/validator_detail_v41.hpp"
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
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st55;
tr91:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st55;
tr102:
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
case 55:
#line 2088 "inc/vcf/validator_detail_v41.hpp"
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
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st56;
tr95:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st56;
st56:
	if ( ++p == pe )
		goto _test_eof56;
case 56:
#line 2139 "inc/vcf/validator_detail_v41.hpp"
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
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st57;
tr96:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st57;
st57:
	if ( ++p == pe )
		goto _test_eof57;
case 57:
#line 2190 "inc/vcf/validator_detail_v41.hpp"
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
case 58:
#line 2233 "inc/vcf/validator_detail_v41.hpp"
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
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st59;
tr98:
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
case 59:
#line 2263 "inc/vcf/validator_detail_v41.hpp"
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
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st60;
tr92:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st60;
tr103:
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
case 60:
#line 2303 "inc/vcf/validator_detail_v41.hpp"
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
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st61;
tr100:
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
case 61:
#line 2333 "inc/vcf/validator_detail_v41.hpp"
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
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st62;
st62:
	if ( ++p == pe )
		goto _test_eof62;
case 62:
#line 2353 "inc/vcf/validator_detail_v41.hpp"
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
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st64;
tr109:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st64;
st64:
	if ( ++p == pe )
		goto _test_eof64;
case 64:
#line 2394 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr87;
		case 92: goto tr110;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr109;
	goto tr39;
tr108:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st65;
tr110:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st65;
st65:
	if ( ++p == pe )
		goto _test_eof65;
case 65:
#line 2422 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr111;
		case 92: goto tr110;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr109;
	goto tr39;
tr111:
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
case 66:
#line 2444 "inc/vcf/validator_detail_v41.hpp"
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
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st67;
tr122:
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
case 67:
#line 2474 "inc/vcf/validator_detail_v41.hpp"
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
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st68;
tr114:
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
case 68:
#line 2525 "inc/vcf/validator_detail_v41.hpp"
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
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st69;
tr115:
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
case 69:
#line 2576 "inc/vcf/validator_detail_v41.hpp"
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
case 70:
#line 2619 "inc/vcf/validator_detail_v41.hpp"
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
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st71;
tr119:
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
case 71:
#line 2649 "inc/vcf/validator_detail_v41.hpp"
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
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st72;
tr123:
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
case 72:
#line 2679 "inc/vcf/validator_detail_v41.hpp"
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
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st73;
tr120:
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
case 73:
#line 2709 "inc/vcf/validator_detail_v41.hpp"
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
case 74:
#line 2733 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 76: goto tr126;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr125;
tr126:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st75;
st75:
	if ( ++p == pe )
		goto _test_eof75;
case 75:
#line 2751 "inc/vcf/validator_detail_v41.hpp"
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
#line 108 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "ALT");
    }
	goto st77;
st77:
	if ( ++p == pe )
		goto _test_eof77;
case 77:
#line 2778 "inc/vcf/validator_detail_v41.hpp"
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
case 82:
#line 2850 "inc/vcf/validator_detail_v41.hpp"
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
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st83;
tr135:
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
case 83:
#line 2904 "inc/vcf/validator_detail_v41.hpp"
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
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st84;
st84:
	if ( ++p == pe )
		goto _test_eof84;
case 84:
#line 2925 "inc/vcf/validator_detail_v41.hpp"
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
#line 156 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Description");
    }
	goto st97;
st97:
	if ( ++p == pe )
		goto _test_eof97;
case 97:
#line 3023 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr154;
		case 92: goto tr155;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr153;
	goto tr152;
tr153:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st98;
tr156:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st98;
st98:
	if ( ++p == pe )
		goto _test_eof98;
case 98:
#line 3051 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr157;
		case 92: goto tr158;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr156;
	goto tr152;
tr154:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st99;
tr157:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st99;
st99:
	if ( ++p == pe )
		goto _test_eof99;
case 99:
#line 3079 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 62 )
		goto st100;
	goto tr152;
st100:
	if ( ++p == pe )
		goto _test_eof100;
case 100:
	switch( (*p) ) {
		case 10: goto tr55;
		case 13: goto tr56;
	}
	goto tr125;
tr155:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st101;
tr158:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st101;
st101:
	if ( ++p == pe )
		goto _test_eof101;
case 101:
#line 3112 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr160;
		case 92: goto tr158;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr156;
	goto tr152;
tr160:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st102;
st102:
	if ( ++p == pe )
		goto _test_eof102;
case 102:
#line 3134 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr157;
		case 62: goto tr161;
		case 92: goto tr158;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr156;
	goto tr152;
tr161:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st103;
st103:
	if ( ++p == pe )
		goto _test_eof103;
case 103:
#line 3153 "inc/vcf/validator_detail_v41.hpp"
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
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st104;
st104:
	if ( ++p == pe )
		goto _test_eof104;
case 104:
#line 3177 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 73: goto tr163;
		case 79: goto tr164;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr162;
tr163:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st105;
st105:
	if ( ++p == pe )
		goto _test_eof105;
case 105:
#line 3196 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 76: goto tr166;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr165;
tr166:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st106;
st106:
	if ( ++p == pe )
		goto _test_eof106;
case 106:
#line 3214 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 84: goto tr167;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr165;
tr167:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st107;
st107:
	if ( ++p == pe )
		goto _test_eof107;
case 107:
#line 3232 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 69: goto tr168;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr165;
tr168:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st108;
st108:
	if ( ++p == pe )
		goto _test_eof108;
case 108:
#line 3250 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 82: goto st109;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr165;
st109:
	if ( ++p == pe )
		goto _test_eof109;
case 109:
	if ( (*p) == 61 )
		goto tr170;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr165;
tr170:
#line 120 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "FILTER");
    }
	goto st110;
st110:
	if ( ++p == pe )
		goto _test_eof110;
case 110:
#line 3277 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 60 )
		goto st111;
	goto tr165;
st111:
	if ( ++p == pe )
		goto _test_eof111;
case 111:
	if ( (*p) == 73 )
		goto st112;
	goto tr165;
st112:
	if ( ++p == pe )
		goto _test_eof112;
case 112:
	if ( (*p) == 68 )
		goto st113;
	goto tr165;
st113:
	if ( ++p == pe )
		goto _test_eof113;
case 113:
	if ( (*p) == 61 )
		goto st114;
	goto tr165;
st114:
	if ( ++p == pe )
		goto _test_eof114;
case 114:
	if ( (*p) == 95 )
		goto tr176;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr176;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr177;
		} else if ( (*p) >= 65 )
			goto tr177;
	} else
		goto tr177;
	goto tr175;
tr176:
#line 144 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st115;
st115:
	if ( ++p == pe )
		goto _test_eof115;
case 115:
#line 3334 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 95 )
		goto st115;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st115;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr179;
		} else if ( (*p) >= 65 )
			goto tr179;
	} else
		goto tr179;
	goto tr175;
tr179:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st116;
tr177:
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
	goto st116;
st116:
	if ( ++p == pe )
		goto _test_eof116;
case 116:
#line 3373 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 44: goto tr180;
		case 95: goto tr179;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr179;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr179;
		} else if ( (*p) >= 65 )
			goto tr179;
	} else
		goto tr179;
	goto tr175;
tr180:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st117;
st117:
	if ( ++p == pe )
		goto _test_eof117;
case 117:
#line 3400 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 68 )
		goto st118;
	goto tr165;
st118:
	if ( ++p == pe )
		goto _test_eof118;
case 118:
	if ( (*p) == 101 )
		goto st119;
	goto tr165;
st119:
	if ( ++p == pe )
		goto _test_eof119;
case 119:
	if ( (*p) == 115 )
		goto st120;
	goto tr165;
st120:
	if ( ++p == pe )
		goto _test_eof120;
case 120:
	if ( (*p) == 99 )
		goto st121;
	goto tr165;
st121:
	if ( ++p == pe )
		goto _test_eof121;
case 121:
	if ( (*p) == 114 )
		goto st122;
	goto tr165;
st122:
	if ( ++p == pe )
		goto _test_eof122;
case 122:
	if ( (*p) == 105 )
		goto st123;
	goto tr165;
st123:
	if ( ++p == pe )
		goto _test_eof123;
case 123:
	if ( (*p) == 112 )
		goto st124;
	goto tr165;
st124:
	if ( ++p == pe )
		goto _test_eof124;
case 124:
	if ( (*p) == 116 )
		goto st125;
	goto tr165;
st125:
	if ( ++p == pe )
		goto _test_eof125;
case 125:
	if ( (*p) == 105 )
		goto st126;
	goto tr165;
st126:
	if ( ++p == pe )
		goto _test_eof126;
case 126:
	if ( (*p) == 111 )
		goto st127;
	goto tr165;
st127:
	if ( ++p == pe )
		goto _test_eof127;
case 127:
	if ( (*p) == 110 )
		goto st128;
	goto tr165;
st128:
	if ( ++p == pe )
		goto _test_eof128;
case 128:
	if ( (*p) == 61 )
		goto st129;
	goto tr165;
st129:
	if ( ++p == pe )
		goto _test_eof129;
case 129:
	if ( (*p) == 34 )
		goto tr193;
	goto tr165;
tr193:
#line 156 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Description");
    }
	goto st130;
st130:
	if ( ++p == pe )
		goto _test_eof130;
case 130:
#line 3498 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr196;
		case 92: goto tr197;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr195;
	goto tr194;
tr195:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st131;
tr198:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st131;
st131:
	if ( ++p == pe )
		goto _test_eof131;
case 131:
#line 3526 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr199;
		case 92: goto tr200;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr198;
	goto tr194;
tr196:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st132;
tr199:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st132;
st132:
	if ( ++p == pe )
		goto _test_eof132;
case 132:
#line 3554 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 62 )
		goto st133;
	goto tr194;
st133:
	if ( ++p == pe )
		goto _test_eof133;
case 133:
	switch( (*p) ) {
		case 10: goto tr55;
		case 13: goto tr56;
	}
	goto tr165;
tr197:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st134;
tr200:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st134;
st134:
	if ( ++p == pe )
		goto _test_eof134;
case 134:
#line 3587 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr202;
		case 92: goto tr200;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr198;
	goto tr194;
tr202:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st135;
st135:
	if ( ++p == pe )
		goto _test_eof135;
case 135:
#line 3609 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr199;
		case 62: goto tr203;
		case 92: goto tr200;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr198;
	goto tr194;
tr203:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st136;
st136:
	if ( ++p == pe )
		goto _test_eof136;
case 136:
#line 3628 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 10: goto tr55;
		case 13: goto tr56;
		case 34: goto tr199;
		case 92: goto tr200;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr198;
	goto tr194;
tr164:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st137;
st137:
	if ( ++p == pe )
		goto _test_eof137;
case 137:
#line 3648 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 82: goto tr205;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr204;
tr205:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st138;
st138:
	if ( ++p == pe )
		goto _test_eof138;
case 138:
#line 3666 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 77: goto tr206;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr204;
tr206:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st139;
st139:
	if ( ++p == pe )
		goto _test_eof139;
case 139:
#line 3684 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 65: goto tr207;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr204;
tr207:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st140;
st140:
	if ( ++p == pe )
		goto _test_eof140;
case 140:
#line 3702 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 84: goto st141;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr204;
st141:
	if ( ++p == pe )
		goto _test_eof141;
case 141:
	if ( (*p) == 61 )
		goto tr209;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr204;
tr209:
#line 124 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "FORMAT");
    }
	goto st142;
st142:
	if ( ++p == pe )
		goto _test_eof142;
case 142:
#line 3729 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 60 )
		goto st143;
	goto tr204;
st143:
	if ( ++p == pe )
		goto _test_eof143;
case 143:
	if ( (*p) == 73 )
		goto st144;
	goto tr204;
st144:
	if ( ++p == pe )
		goto _test_eof144;
case 144:
	if ( (*p) == 68 )
		goto st145;
	goto tr204;
st145:
	if ( ++p == pe )
		goto _test_eof145;
case 145:
	if ( (*p) == 61 )
		goto st146;
	goto tr204;
st146:
	if ( ++p == pe )
		goto _test_eof146;
case 146:
	if ( (*p) == 95 )
		goto tr215;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr215;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr216;
		} else if ( (*p) >= 65 )
			goto tr216;
	} else
		goto tr216;
	goto tr214;
tr215:
#line 144 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st147;
st147:
	if ( ++p == pe )
		goto _test_eof147;
case 147:
#line 3786 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 95 )
		goto st147;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st147;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr218;
		} else if ( (*p) >= 65 )
			goto tr218;
	} else
		goto tr218;
	goto tr214;
tr218:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st148;
tr216:
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
	goto st148;
st148:
	if ( ++p == pe )
		goto _test_eof148;
case 148:
#line 3825 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 44: goto tr219;
		case 95: goto tr218;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr218;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr218;
		} else if ( (*p) >= 65 )
			goto tr218;
	} else
		goto tr218;
	goto tr214;
tr219:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st149;
st149:
	if ( ++p == pe )
		goto _test_eof149;
case 149:
#line 3852 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 78 )
		goto st150;
	goto tr204;
st150:
	if ( ++p == pe )
		goto _test_eof150;
case 150:
	if ( (*p) == 117 )
		goto st151;
	goto tr204;
st151:
	if ( ++p == pe )
		goto _test_eof151;
case 151:
	if ( (*p) == 109 )
		goto st152;
	goto tr204;
st152:
	if ( ++p == pe )
		goto _test_eof152;
case 152:
	if ( (*p) == 98 )
		goto st153;
	goto tr204;
st153:
	if ( ++p == pe )
		goto _test_eof153;
case 153:
	if ( (*p) == 101 )
		goto st154;
	goto tr204;
st154:
	if ( ++p == pe )
		goto _test_eof154;
case 154:
	if ( (*p) == 114 )
		goto st155;
	goto tr204;
st155:
	if ( ++p == pe )
		goto _test_eof155;
case 155:
	if ( (*p) == 61 )
		goto st156;
	goto tr204;
st156:
	if ( ++p == pe )
		goto _test_eof156;
case 156:
	switch( (*p) ) {
		case 46: goto tr228;
		case 65: goto tr228;
		case 71: goto tr228;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr229;
	goto tr227;
tr228:
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
	goto st157;
st157:
	if ( ++p == pe )
		goto _test_eof157;
case 157:
#line 3928 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 44 )
		goto tr230;
	goto tr227;
tr230:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st158;
st158:
	if ( ++p == pe )
		goto _test_eof158;
case 158:
#line 3942 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 84 )
		goto st159;
	goto tr204;
st159:
	if ( ++p == pe )
		goto _test_eof159;
case 159:
	if ( (*p) == 121 )
		goto st160;
	goto tr204;
st160:
	if ( ++p == pe )
		goto _test_eof160;
case 160:
	if ( (*p) == 112 )
		goto st161;
	goto tr204;
st161:
	if ( ++p == pe )
		goto _test_eof161;
case 161:
	if ( (*p) == 101 )
		goto st162;
	goto tr204;
st162:
	if ( ++p == pe )
		goto _test_eof162;
case 162:
	if ( (*p) == 61 )
		goto st163;
	goto tr204;
st163:
	if ( ++p == pe )
		goto _test_eof163;
case 163:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr237;
	} else if ( (*p) >= 65 )
		goto tr237;
	goto tr236;
tr239:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st164;
tr237:
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
	goto st164;
st164:
	if ( ++p == pe )
		goto _test_eof164;
case 164:
#line 4008 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 44 )
		goto tr238;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr239;
	} else if ( (*p) >= 65 )
		goto tr239;
	goto tr236;
tr238:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st165;
st165:
	if ( ++p == pe )
		goto _test_eof165;
case 165:
#line 4027 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 68 )
		goto st166;
	goto tr204;
st166:
	if ( ++p == pe )
		goto _test_eof166;
case 166:
	if ( (*p) == 101 )
		goto st167;
	goto tr204;
st167:
	if ( ++p == pe )
		goto _test_eof167;
case 167:
	if ( (*p) == 115 )
		goto st168;
	goto tr204;
st168:
	if ( ++p == pe )
		goto _test_eof168;
case 168:
	if ( (*p) == 99 )
		goto st169;
	goto tr204;
st169:
	if ( ++p == pe )
		goto _test_eof169;
case 169:
	if ( (*p) == 114 )
		goto st170;
	goto tr204;
st170:
	if ( ++p == pe )
		goto _test_eof170;
case 170:
	if ( (*p) == 105 )
		goto st171;
	goto tr204;
st171:
	if ( ++p == pe )
		goto _test_eof171;
case 171:
	if ( (*p) == 112 )
		goto st172;
	goto tr204;
st172:
	if ( ++p == pe )
		goto _test_eof172;
case 172:
	if ( (*p) == 116 )
		goto st173;
	goto tr204;
st173:
	if ( ++p == pe )
		goto _test_eof173;
case 173:
	if ( (*p) == 105 )
		goto st174;
	goto tr204;
st174:
	if ( ++p == pe )
		goto _test_eof174;
case 174:
	if ( (*p) == 111 )
		goto st175;
	goto tr204;
st175:
	if ( ++p == pe )
		goto _test_eof175;
case 175:
	if ( (*p) == 110 )
		goto st176;
	goto tr204;
st176:
	if ( ++p == pe )
		goto _test_eof176;
case 176:
	if ( (*p) == 61 )
		goto st177;
	goto tr204;
st177:
	if ( ++p == pe )
		goto _test_eof177;
case 177:
	if ( (*p) == 34 )
		goto tr252;
	goto tr204;
tr252:
#line 156 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Description");
    }
	goto st178;
st178:
	if ( ++p == pe )
		goto _test_eof178;
case 178:
#line 4125 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr255;
		case 92: goto tr256;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr254;
	goto tr253;
tr254:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st179;
tr257:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st179;
st179:
	if ( ++p == pe )
		goto _test_eof179;
case 179:
#line 4153 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr258;
		case 92: goto tr259;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr257;
	goto tr253;
tr255:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st180;
tr258:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st180;
st180:
	if ( ++p == pe )
		goto _test_eof180;
case 180:
#line 4181 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 62 )
		goto st181;
	goto tr253;
st181:
	if ( ++p == pe )
		goto _test_eof181;
case 181:
	switch( (*p) ) {
		case 10: goto tr55;
		case 13: goto tr56;
	}
	goto tr204;
tr256:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st182;
tr259:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st182;
st182:
	if ( ++p == pe )
		goto _test_eof182;
case 182:
#line 4214 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr261;
		case 92: goto tr259;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr257;
	goto tr253;
tr261:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st183;
st183:
	if ( ++p == pe )
		goto _test_eof183;
case 183:
#line 4236 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr258;
		case 62: goto tr262;
		case 92: goto tr259;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr257;
	goto tr253;
tr262:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st184;
st184:
	if ( ++p == pe )
		goto _test_eof184;
case 184:
#line 4255 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 10: goto tr55;
		case 13: goto tr56;
		case 34: goto tr258;
		case 92: goto tr259;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr257;
	goto tr253;
tr263:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st185;
tr229:
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
#line 4289 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 44 )
		goto tr230;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr263;
	goto tr227;
tr33:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st186;
st186:
	if ( ++p == pe )
		goto _test_eof186;
case 186:
#line 4309 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 78: goto tr265;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr264;
tr265:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st187;
st187:
	if ( ++p == pe )
		goto _test_eof187;
case 187:
#line 4327 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 70: goto tr266;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr264;
tr266:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st188;
st188:
	if ( ++p == pe )
		goto _test_eof188;
case 188:
#line 4345 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 79: goto st189;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr264;
st189:
	if ( ++p == pe )
		goto _test_eof189;
case 189:
	if ( (*p) == 61 )
		goto tr268;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr264;
tr268:
#line 128 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "INFO");
    }
	goto st190;
st190:
	if ( ++p == pe )
		goto _test_eof190;
case 190:
#line 4372 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 60 )
		goto st191;
	goto tr264;
st191:
	if ( ++p == pe )
		goto _test_eof191;
case 191:
	if ( (*p) == 73 )
		goto st192;
	goto tr264;
st192:
	if ( ++p == pe )
		goto _test_eof192;
case 192:
	if ( (*p) == 68 )
		goto st193;
	goto tr264;
st193:
	if ( ++p == pe )
		goto _test_eof193;
case 193:
	if ( (*p) == 61 )
		goto st194;
	goto tr264;
st194:
	if ( ++p == pe )
		goto _test_eof194;
case 194:
	if ( (*p) == 95 )
		goto tr274;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr274;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr275;
		} else if ( (*p) >= 65 )
			goto tr275;
	} else
		goto tr275;
	goto tr273;
tr274:
#line 144 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st195;
st195:
	if ( ++p == pe )
		goto _test_eof195;
case 195:
#line 4429 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 95 )
		goto st195;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st195;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr277;
		} else if ( (*p) >= 65 )
			goto tr277;
	} else
		goto tr277;
	goto tr273;
tr277:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st196;
tr275:
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
	goto st196;
st196:
	if ( ++p == pe )
		goto _test_eof196;
case 196:
#line 4468 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 44: goto tr278;
		case 95: goto tr277;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr277;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr277;
		} else if ( (*p) >= 65 )
			goto tr277;
	} else
		goto tr277;
	goto tr273;
tr278:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st197;
st197:
	if ( ++p == pe )
		goto _test_eof197;
case 197:
#line 4495 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 78 )
		goto st198;
	goto tr264;
st198:
	if ( ++p == pe )
		goto _test_eof198;
case 198:
	if ( (*p) == 117 )
		goto st199;
	goto tr264;
st199:
	if ( ++p == pe )
		goto _test_eof199;
case 199:
	if ( (*p) == 109 )
		goto st200;
	goto tr264;
st200:
	if ( ++p == pe )
		goto _test_eof200;
case 200:
	if ( (*p) == 98 )
		goto st201;
	goto tr264;
st201:
	if ( ++p == pe )
		goto _test_eof201;
case 201:
	if ( (*p) == 101 )
		goto st202;
	goto tr264;
st202:
	if ( ++p == pe )
		goto _test_eof202;
case 202:
	if ( (*p) == 114 )
		goto st203;
	goto tr264;
st203:
	if ( ++p == pe )
		goto _test_eof203;
case 203:
	if ( (*p) == 61 )
		goto st204;
	goto tr264;
st204:
	if ( ++p == pe )
		goto _test_eof204;
case 204:
	switch( (*p) ) {
		case 46: goto tr287;
		case 65: goto tr287;
		case 71: goto tr287;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr288;
	goto tr286;
tr287:
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
	goto st205;
st205:
	if ( ++p == pe )
		goto _test_eof205;
case 205:
#line 4571 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 44 )
		goto tr289;
	goto tr286;
tr289:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st206;
st206:
	if ( ++p == pe )
		goto _test_eof206;
case 206:
#line 4585 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 84 )
		goto st207;
	goto tr264;
st207:
	if ( ++p == pe )
		goto _test_eof207;
case 207:
	if ( (*p) == 121 )
		goto st208;
	goto tr264;
st208:
	if ( ++p == pe )
		goto _test_eof208;
case 208:
	if ( (*p) == 112 )
		goto st209;
	goto tr264;
st209:
	if ( ++p == pe )
		goto _test_eof209;
case 209:
	if ( (*p) == 101 )
		goto st210;
	goto tr264;
st210:
	if ( ++p == pe )
		goto _test_eof210;
case 210:
	if ( (*p) == 61 )
		goto st211;
	goto tr264;
st211:
	if ( ++p == pe )
		goto _test_eof211;
case 211:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr296;
	} else if ( (*p) >= 65 )
		goto tr296;
	goto tr295;
tr298:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st212;
tr296:
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
	goto st212;
st212:
	if ( ++p == pe )
		goto _test_eof212;
case 212:
#line 4651 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 44 )
		goto tr297;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr298;
	} else if ( (*p) >= 65 )
		goto tr298;
	goto tr295;
tr297:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st213;
st213:
	if ( ++p == pe )
		goto _test_eof213;
case 213:
#line 4670 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 68 )
		goto st214;
	goto tr264;
st214:
	if ( ++p == pe )
		goto _test_eof214;
case 214:
	if ( (*p) == 101 )
		goto st215;
	goto tr264;
st215:
	if ( ++p == pe )
		goto _test_eof215;
case 215:
	if ( (*p) == 115 )
		goto st216;
	goto tr264;
st216:
	if ( ++p == pe )
		goto _test_eof216;
case 216:
	if ( (*p) == 99 )
		goto st217;
	goto tr264;
st217:
	if ( ++p == pe )
		goto _test_eof217;
case 217:
	if ( (*p) == 114 )
		goto st218;
	goto tr264;
st218:
	if ( ++p == pe )
		goto _test_eof218;
case 218:
	if ( (*p) == 105 )
		goto st219;
	goto tr264;
st219:
	if ( ++p == pe )
		goto _test_eof219;
case 219:
	if ( (*p) == 112 )
		goto st220;
	goto tr264;
st220:
	if ( ++p == pe )
		goto _test_eof220;
case 220:
	if ( (*p) == 116 )
		goto st221;
	goto tr264;
st221:
	if ( ++p == pe )
		goto _test_eof221;
case 221:
	if ( (*p) == 105 )
		goto st222;
	goto tr264;
st222:
	if ( ++p == pe )
		goto _test_eof222;
case 222:
	if ( (*p) == 111 )
		goto st223;
	goto tr264;
st223:
	if ( ++p == pe )
		goto _test_eof223;
case 223:
	if ( (*p) == 110 )
		goto st224;
	goto tr264;
st224:
	if ( ++p == pe )
		goto _test_eof224;
case 224:
	if ( (*p) == 61 )
		goto st225;
	goto tr264;
st225:
	if ( ++p == pe )
		goto _test_eof225;
case 225:
	if ( (*p) == 34 )
		goto tr311;
	goto tr264;
tr311:
#line 156 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Description");
    }
	goto st226;
st226:
	if ( ++p == pe )
		goto _test_eof226;
case 226:
#line 4768 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr314;
		case 92: goto tr315;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr313;
	goto tr312;
tr313:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st227;
tr316:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st227;
st227:
	if ( ++p == pe )
		goto _test_eof227;
case 227:
#line 4796 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr317;
		case 92: goto tr318;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr316;
	goto tr312;
tr314:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st228;
tr317:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st228;
st228:
	if ( ++p == pe )
		goto _test_eof228;
case 228:
#line 4824 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 62 )
		goto st229;
	goto tr312;
st229:
	if ( ++p == pe )
		goto _test_eof229;
case 229:
	switch( (*p) ) {
		case 10: goto tr55;
		case 13: goto tr56;
	}
	goto tr264;
tr315:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st230;
tr318:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st230;
st230:
	if ( ++p == pe )
		goto _test_eof230;
case 230:
#line 4857 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr320;
		case 92: goto tr318;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr316;
	goto tr312;
tr320:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st231;
st231:
	if ( ++p == pe )
		goto _test_eof231;
case 231:
#line 4879 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr317;
		case 62: goto tr321;
		case 92: goto tr318;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr316;
	goto tr312;
tr321:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st232;
st232:
	if ( ++p == pe )
		goto _test_eof232;
case 232:
#line 4898 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 10: goto tr55;
		case 13: goto tr56;
		case 34: goto tr317;
		case 92: goto tr318;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr316;
	goto tr312;
tr322:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st233;
tr288:
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
	goto st233;
st233:
	if ( ++p == pe )
		goto _test_eof233;
case 233:
#line 4932 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 44 )
		goto tr289;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr322;
	goto tr286;
tr34:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st234;
st234:
	if ( ++p == pe )
		goto _test_eof234;
case 234:
#line 4952 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 69: goto tr324;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr323;
tr324:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st235;
st235:
	if ( ++p == pe )
		goto _test_eof235;
case 235:
#line 4970 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 68: goto tr325;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr323;
tr325:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st236;
st236:
	if ( ++p == pe )
		goto _test_eof236;
case 236:
#line 4988 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 73: goto tr326;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr323;
tr326:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st237;
st237:
	if ( ++p == pe )
		goto _test_eof237;
case 237:
#line 5006 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 71: goto tr327;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr323;
tr327:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st238;
st238:
	if ( ++p == pe )
		goto _test_eof238;
case 238:
#line 5024 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 82: goto tr328;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr323;
tr328:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st239;
st239:
	if ( ++p == pe )
		goto _test_eof239;
case 239:
#line 5042 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 69: goto tr329;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr323;
tr329:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st240;
st240:
	if ( ++p == pe )
		goto _test_eof240;
case 240:
#line 5060 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 69: goto st241;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr323;
st241:
	if ( ++p == pe )
		goto _test_eof241;
case 241:
	if ( (*p) == 61 )
		goto tr331;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr323;
tr331:
#line 132 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "PEDIGREE");
    }
	goto st242;
st242:
	if ( ++p == pe )
		goto _test_eof242;
case 242:
#line 5087 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 60 )
		goto st243;
	goto tr323;
tr343:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st243;
st243:
	if ( ++p == pe )
		goto _test_eof243;
case 243:
#line 5101 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 95 )
		goto tr334;
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
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st244;
st244:
	if ( ++p == pe )
		goto _test_eof244;
case 244:
#line 5126 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 95 )
		goto st244;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st244;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr337;
		} else if ( (*p) >= 65 )
			goto tr337;
	} else
		goto tr337;
	goto tr333;
tr335:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st245;
tr337:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st245;
st245:
	if ( ++p == pe )
		goto _test_eof245;
case 245:
#line 5161 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr338;
		case 95: goto tr337;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr337;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr337;
		} else if ( (*p) >= 65 )
			goto tr337;
	} else
		goto tr337;
	goto tr333;
tr338:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st246;
st246:
	if ( ++p == pe )
		goto _test_eof246;
case 246:
#line 5188 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 95 )
		goto tr339;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr339;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr340;
		} else if ( (*p) >= 65 )
			goto tr340;
	} else
		goto tr340;
	goto tr333;
tr339:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st247;
st247:
	if ( ++p == pe )
		goto _test_eof247;
case 247:
#line 5213 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 95 )
		goto st247;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st247;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr342;
		} else if ( (*p) >= 65 )
			goto tr342;
	} else
		goto tr342;
	goto tr333;
tr340:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st248;
tr342:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st248;
st248:
	if ( ++p == pe )
		goto _test_eof248;
case 248:
#line 5248 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 44: goto tr343;
		case 62: goto tr344;
		case 95: goto tr342;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr342;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr342;
		} else if ( (*p) >= 65 )
			goto tr342;
	} else
		goto tr342;
	goto tr333;
tr344:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st249;
st249:
	if ( ++p == pe )
		goto _test_eof249;
case 249:
#line 5276 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 10: goto tr55;
		case 13: goto tr56;
	}
	goto tr323;
tr35:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st250;
st250:
	if ( ++p == pe )
		goto _test_eof250;
case 250:
#line 5296 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 65: goto tr346;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr345;
tr346:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st251;
st251:
	if ( ++p == pe )
		goto _test_eof251;
case 251:
#line 5314 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 77: goto tr347;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr345;
tr347:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st252;
st252:
	if ( ++p == pe )
		goto _test_eof252;
case 252:
#line 5332 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 80: goto tr348;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr345;
tr348:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st253;
st253:
	if ( ++p == pe )
		goto _test_eof253;
case 253:
#line 5350 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 76: goto tr349;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr345;
tr349:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st254;
st254:
	if ( ++p == pe )
		goto _test_eof254;
case 254:
#line 5368 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 69: goto st255;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr345;
st255:
	if ( ++p == pe )
		goto _test_eof255;
case 255:
	if ( (*p) == 61 )
		goto tr351;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr345;
tr351:
#line 140 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "SAMPLE");
    }
	goto st256;
st256:
	if ( ++p == pe )
		goto _test_eof256;
case 256:
#line 5395 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 60 )
		goto st257;
	goto tr345;
st257:
	if ( ++p == pe )
		goto _test_eof257;
case 257:
	if ( (*p) == 73 )
		goto st258;
	goto tr345;
st258:
	if ( ++p == pe )
		goto _test_eof258;
case 258:
	if ( (*p) == 68 )
		goto st259;
	goto tr345;
st259:
	if ( ++p == pe )
		goto _test_eof259;
case 259:
	if ( (*p) == 61 )
		goto st260;
	goto tr345;
st260:
	if ( ++p == pe )
		goto _test_eof260;
case 260:
	if ( (*p) == 95 )
		goto tr357;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr357;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr358;
		} else if ( (*p) >= 65 )
			goto tr358;
	} else
		goto tr358;
	goto tr356;
tr357:
#line 144 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st261;
st261:
	if ( ++p == pe )
		goto _test_eof261;
case 261:
#line 5452 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 95 )
		goto st261;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st261;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr360;
		} else if ( (*p) >= 65 )
			goto tr360;
	} else
		goto tr360;
	goto tr356;
tr360:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st262;
tr358:
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
	goto st262;
st262:
	if ( ++p == pe )
		goto _test_eof262;
case 262:
#line 5491 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 44: goto tr362;
		case 95: goto tr360;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr360;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr360;
		} else if ( (*p) >= 65 )
			goto tr360;
	} else
		goto tr360;
	goto tr361;
tr362:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st263;
st263:
	if ( ++p == pe )
		goto _test_eof263;
case 263:
#line 5518 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 71 )
		goto st264;
	goto tr363;
st264:
	if ( ++p == pe )
		goto _test_eof264;
case 264:
	if ( (*p) == 101 )
		goto st265;
	goto tr363;
st265:
	if ( ++p == pe )
		goto _test_eof265;
case 265:
	if ( (*p) == 110 )
		goto st266;
	goto tr363;
st266:
	if ( ++p == pe )
		goto _test_eof266;
case 266:
	if ( (*p) == 111 )
		goto st267;
	goto tr363;
st267:
	if ( ++p == pe )
		goto _test_eof267;
case 267:
	if ( (*p) == 109 )
		goto st268;
	goto tr363;
st268:
	if ( ++p == pe )
		goto _test_eof268;
case 268:
	if ( (*p) == 101 )
		goto st269;
	goto tr363;
st269:
	if ( ++p == pe )
		goto _test_eof269;
case 269:
	if ( (*p) == 115 )
		goto st270;
	goto tr363;
st270:
	if ( ++p == pe )
		goto _test_eof270;
case 270:
	if ( (*p) == 61 )
		goto st271;
	goto tr363;
st271:
	if ( ++p == pe )
		goto _test_eof271;
case 271:
	if ( (*p) < 35 ) {
		if ( 32 <= (*p) && (*p) <= 33 )
			goto tr372;
	} else if ( (*p) > 43 ) {
		if ( (*p) > 61 ) {
			if ( 63 <= (*p) && (*p) <= 126 )
				goto tr372;
		} else if ( (*p) >= 45 )
			goto tr372;
	} else
		goto tr372;
	goto tr363;
tr374:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st272;
tr372:
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
	goto st272;
st272:
	if ( ++p == pe )
		goto _test_eof272;
case 272:
#line 5611 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 44 )
		goto tr375;
	if ( (*p) < 35 ) {
		if ( 32 <= (*p) && (*p) <= 33 )
			goto tr374;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr374;
	} else
		goto tr374;
	goto tr373;
tr375:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st273;
st273:
	if ( ++p == pe )
		goto _test_eof273;
case 273:
#line 5633 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 77 )
		goto st274;
	goto tr376;
st274:
	if ( ++p == pe )
		goto _test_eof274;
case 274:
	if ( (*p) == 105 )
		goto st275;
	goto tr376;
st275:
	if ( ++p == pe )
		goto _test_eof275;
case 275:
	if ( (*p) == 120 )
		goto st276;
	goto tr376;
st276:
	if ( ++p == pe )
		goto _test_eof276;
case 276:
	if ( (*p) == 116 )
		goto st277;
	goto tr376;
st277:
	if ( ++p == pe )
		goto _test_eof277;
case 277:
	if ( (*p) == 117 )
		goto st278;
	goto tr376;
st278:
	if ( ++p == pe )
		goto _test_eof278;
case 278:
	if ( (*p) == 114 )
		goto st279;
	goto tr376;
st279:
	if ( ++p == pe )
		goto _test_eof279;
case 279:
	if ( (*p) == 101 )
		goto st280;
	goto tr376;
st280:
	if ( ++p == pe )
		goto _test_eof280;
case 280:
	if ( (*p) == 61 )
		goto st281;
	goto tr376;
st281:
	if ( ++p == pe )
		goto _test_eof281;
case 281:
	if ( (*p) < 35 ) {
		if ( 32 <= (*p) && (*p) <= 33 )
			goto tr385;
	} else if ( (*p) > 43 ) {
		if ( (*p) > 61 ) {
			if ( 63 <= (*p) && (*p) <= 126 )
				goto tr385;
		} else if ( (*p) >= 45 )
			goto tr385;
	} else
		goto tr385;
	goto tr376;
tr387:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st282;
tr385:
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
	goto st282;
st282:
	if ( ++p == pe )
		goto _test_eof282;
case 282:
#line 5726 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 44 )
		goto tr388;
	if ( (*p) < 35 ) {
		if ( 32 <= (*p) && (*p) <= 33 )
			goto tr387;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr387;
	} else
		goto tr387;
	goto tr386;
tr388:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st283;
st283:
	if ( ++p == pe )
		goto _test_eof283;
case 283:
#line 5748 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 68 )
		goto st284;
	goto tr389;
st284:
	if ( ++p == pe )
		goto _test_eof284;
case 284:
	if ( (*p) == 101 )
		goto st285;
	goto tr389;
st285:
	if ( ++p == pe )
		goto _test_eof285;
case 285:
	if ( (*p) == 115 )
		goto st286;
	goto tr389;
st286:
	if ( ++p == pe )
		goto _test_eof286;
case 286:
	if ( (*p) == 99 )
		goto st287;
	goto tr389;
st287:
	if ( ++p == pe )
		goto _test_eof287;
case 287:
	if ( (*p) == 114 )
		goto st288;
	goto tr389;
st288:
	if ( ++p == pe )
		goto _test_eof288;
case 288:
	if ( (*p) == 105 )
		goto st289;
	goto tr389;
st289:
	if ( ++p == pe )
		goto _test_eof289;
case 289:
	if ( (*p) == 112 )
		goto st290;
	goto tr389;
st290:
	if ( ++p == pe )
		goto _test_eof290;
case 290:
	if ( (*p) == 116 )
		goto st291;
	goto tr389;
st291:
	if ( ++p == pe )
		goto _test_eof291;
case 291:
	if ( (*p) == 105 )
		goto st292;
	goto tr389;
st292:
	if ( ++p == pe )
		goto _test_eof292;
case 292:
	if ( (*p) == 111 )
		goto st293;
	goto tr389;
st293:
	if ( ++p == pe )
		goto _test_eof293;
case 293:
	if ( (*p) == 110 )
		goto st294;
	goto tr389;
st294:
	if ( ++p == pe )
		goto _test_eof294;
case 294:
	if ( (*p) == 61 )
		goto st295;
	goto tr389;
st295:
	if ( ++p == pe )
		goto _test_eof295;
case 295:
	if ( (*p) == 34 )
		goto tr402;
	goto tr389;
tr402:
#line 156 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Description");
    }
	goto st296;
st296:
	if ( ++p == pe )
		goto _test_eof296;
case 296:
#line 5846 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr404;
		case 92: goto tr405;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr403;
	goto tr389;
tr403:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st297;
tr406:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st297;
st297:
	if ( ++p == pe )
		goto _test_eof297;
case 297:
#line 5874 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr407;
		case 92: goto tr408;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr406;
	goto tr389;
tr404:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st298;
tr407:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st298;
st298:
	if ( ++p == pe )
		goto _test_eof298;
case 298:
#line 5902 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 62 )
		goto st299;
	goto tr389;
st299:
	if ( ++p == pe )
		goto _test_eof299;
case 299:
	switch( (*p) ) {
		case 10: goto tr55;
		case 13: goto tr56;
	}
	goto tr345;
tr405:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st300;
tr408:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st300;
st300:
	if ( ++p == pe )
		goto _test_eof300;
case 300:
#line 5935 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr410;
		case 92: goto tr408;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr406;
	goto tr389;
tr410:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st301;
st301:
	if ( ++p == pe )
		goto _test_eof301;
case 301:
#line 5957 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr407;
		case 62: goto tr411;
		case 92: goto tr408;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr406;
	goto tr389;
tr411:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st302;
st302:
	if ( ++p == pe )
		goto _test_eof302;
case 302:
#line 5976 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 10: goto tr55;
		case 13: goto tr56;
		case 34: goto tr407;
		case 92: goto tr408;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr406;
	goto tr389;
tr36:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st303;
st303:
	if ( ++p == pe )
		goto _test_eof303;
case 303:
#line 6000 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 115: goto tr413;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr412;
tr413:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st304;
st304:
	if ( ++p == pe )
		goto _test_eof304;
case 304:
#line 6018 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 115: goto tr414;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr412;
tr414:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st305;
st305:
	if ( ++p == pe )
		goto _test_eof305;
case 305:
#line 6036 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 101: goto tr415;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr412;
tr415:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st306;
st306:
	if ( ++p == pe )
		goto _test_eof306;
case 306:
#line 6054 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 109: goto tr416;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr412;
tr416:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st307;
st307:
	if ( ++p == pe )
		goto _test_eof307;
case 307:
#line 6072 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 98: goto tr417;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr412;
tr417:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st308;
st308:
	if ( ++p == pe )
		goto _test_eof308;
case 308:
#line 6090 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 108: goto tr418;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr412;
tr418:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st309;
st309:
	if ( ++p == pe )
		goto _test_eof309;
case 309:
#line 6108 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 121: goto st310;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr412;
st310:
	if ( ++p == pe )
		goto _test_eof310;
case 310:
	if ( (*p) == 61 )
		goto tr420;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr412;
tr420:
#line 112 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "assembly");
    }
	goto st311;
st311:
	if ( ++p == pe )
		goto _test_eof311;
case 311:
#line 6135 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr422;
	} else if ( (*p) >= 65 )
		goto tr422;
	goto tr421;
tr422:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st312;
st312:
	if ( ++p == pe )
		goto _test_eof312;
case 312:
#line 6152 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 10: goto tr421;
		case 13: goto tr424;
		case 35: goto tr421;
		case 47: goto tr421;
		case 58: goto tr421;
		case 63: goto tr421;
	}
	goto st313;
tr424:
#line 43 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st313;
st313:
	if ( ++p == pe )
		goto _test_eof313;
case 313:
#line 6178 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 10: goto tr421;
		case 13: goto tr424;
		case 35: goto tr421;
		case 47: goto tr421;
		case 58: goto st314;
		case 63: goto tr421;
	}
	goto st313;
st314:
	if ( ++p == pe )
		goto _test_eof314;
case 314:
	if ( (*p) == 47 )
		goto st315;
	goto tr421;
st315:
	if ( ++p == pe )
		goto _test_eof315;
case 315:
	if ( (*p) == 47 )
		goto st316;
	goto tr421;
st316:
	if ( ++p == pe )
		goto _test_eof316;
case 316:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st317;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr429;
	} else
		goto tr429;
	goto tr421;
st317:
	if ( ++p == pe )
		goto _test_eof317;
case 317:
	if ( (*p) == 46 )
		goto st318;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st328;
	goto tr421;
st318:
	if ( ++p == pe )
		goto _test_eof318;
case 318:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st319;
	goto tr421;
st319:
	if ( ++p == pe )
		goto _test_eof319;
case 319:
	if ( (*p) == 46 )
		goto st320;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st326;
	goto tr421;
st320:
	if ( ++p == pe )
		goto _test_eof320;
case 320:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st321;
	goto tr421;
st321:
	if ( ++p == pe )
		goto _test_eof321;
case 321:
	if ( (*p) == 46 )
		goto st322;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st324;
	goto tr421;
st322:
	if ( ++p == pe )
		goto _test_eof322;
case 322:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr429;
	goto tr421;
tr429:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st323;
tr438:
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
	goto st323;
st323:
	if ( ++p == pe )
		goto _test_eof323;
case 323:
#line 6301 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 10: goto tr45;
		case 13: goto tr438;
	}
	goto tr429;
st324:
	if ( ++p == pe )
		goto _test_eof324;
case 324:
	if ( (*p) == 46 )
		goto st322;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st325;
	goto tr421;
st325:
	if ( ++p == pe )
		goto _test_eof325;
case 325:
	if ( (*p) == 46 )
		goto st322;
	goto tr421;
st326:
	if ( ++p == pe )
		goto _test_eof326;
case 326:
	if ( (*p) == 46 )
		goto st320;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st327;
	goto tr421;
st327:
	if ( ++p == pe )
		goto _test_eof327;
case 327:
	if ( (*p) == 46 )
		goto st320;
	goto tr421;
st328:
	if ( ++p == pe )
		goto _test_eof328;
case 328:
	if ( (*p) == 46 )
		goto st318;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st329;
	goto tr421;
st329:
	if ( ++p == pe )
		goto _test_eof329;
case 329:
	if ( (*p) == 46 )
		goto st318;
	goto tr421;
tr37:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st330;
st330:
	if ( ++p == pe )
		goto _test_eof330;
case 330:
#line 6369 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 111: goto tr443;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr442;
tr443:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st331;
st331:
	if ( ++p == pe )
		goto _test_eof331;
case 331:
#line 6387 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 110: goto tr444;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr442;
tr444:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st332;
st332:
	if ( ++p == pe )
		goto _test_eof332;
case 332:
#line 6405 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 116: goto tr445;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr442;
tr445:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st333;
st333:
	if ( ++p == pe )
		goto _test_eof333;
case 333:
#line 6423 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 105: goto tr446;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr442;
tr446:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st334;
st334:
	if ( ++p == pe )
		goto _test_eof334;
case 334:
#line 6441 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 103: goto st335;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr442;
st335:
	if ( ++p == pe )
		goto _test_eof335;
case 335:
	if ( (*p) == 61 )
		goto tr448;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr442;
tr448:
#line 116 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "contig");
    }
	goto st336;
st336:
	if ( ++p == pe )
		goto _test_eof336;
case 336:
#line 6468 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 60 )
		goto st337;
	goto tr442;
st337:
	if ( ++p == pe )
		goto _test_eof337;
case 337:
	if ( (*p) == 73 )
		goto st338;
	goto tr442;
st338:
	if ( ++p == pe )
		goto _test_eof338;
case 338:
	if ( (*p) == 68 )
		goto st339;
	goto tr442;
st339:
	if ( ++p == pe )
		goto _test_eof339;
case 339:
	if ( (*p) == 61 )
		goto st340;
	goto tr442;
st340:
	if ( ++p == pe )
		goto _test_eof340;
case 340:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr454;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr454;
	} else
		goto tr454;
	goto tr453;
tr455:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st341;
tr454:
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
	goto st341;
st341:
	if ( ++p == pe )
		goto _test_eof341;
case 341:
#line 6530 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 44: goto tr456;
		case 62: goto tr457;
	}
	if ( (*p) > 59 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr455;
	} else if ( (*p) >= 33 )
		goto tr455;
	goto tr453;
tr456:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st342;
st342:
	if ( ++p == pe )
		goto _test_eof342;
case 342:
#line 6551 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 95 )
		goto tr458;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr458;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr459;
		} else if ( (*p) >= 65 )
			goto tr459;
	} else
		goto tr459;
	goto tr442;
tr458:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st343;
st343:
	if ( ++p == pe )
		goto _test_eof343;
case 343:
#line 6576 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 95 )
		goto st343;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st343;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr461;
		} else if ( (*p) >= 65 )
			goto tr461;
	} else
		goto tr461;
	goto tr442;
tr459:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st344;
tr461:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st344;
st344:
	if ( ++p == pe )
		goto _test_eof344;
case 344:
#line 6611 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr462;
		case 95: goto tr461;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr461;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr461;
		} else if ( (*p) >= 65 )
			goto tr461;
	} else
		goto tr461;
	goto tr442;
tr462:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st345;
st345:
	if ( ++p == pe )
		goto _test_eof345;
case 345:
#line 6638 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 34 )
		goto st348;
	if ( (*p) < 45 ) {
		if ( 32 <= (*p) && (*p) <= 43 )
			goto tr463;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr463;
	} else
		goto tr463;
	goto tr442;
tr463:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st346;
tr465:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st346;
st346:
	if ( ++p == pe )
		goto _test_eof346;
case 346:
#line 6670 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 44: goto tr456;
		case 62: goto tr457;
	}
	if ( (*p) > 33 ) {
		if ( 35 <= (*p) && (*p) <= 126 )
			goto tr465;
	} else if ( (*p) >= 32 )
		goto tr465;
	goto tr442;
tr457:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st347;
st347:
	if ( ++p == pe )
		goto _test_eof347;
case 347:
#line 6691 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 10: goto tr55;
		case 13: goto tr56;
	}
	goto tr442;
st348:
	if ( ++p == pe )
		goto _test_eof348;
case 348:
	switch( (*p) ) {
		case 34: goto tr467;
		case 92: goto tr468;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr466;
	goto tr442;
tr466:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st349;
tr469:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st349;
st349:
	if ( ++p == pe )
		goto _test_eof349;
case 349:
#line 6728 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr470;
		case 92: goto tr471;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr469;
	goto tr442;
tr467:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st350;
tr470:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st350;
st350:
	if ( ++p == pe )
		goto _test_eof350;
case 350:
#line 6756 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 44: goto st342;
		case 62: goto st347;
	}
	goto tr442;
tr468:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st351;
tr471:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st351;
st351:
	if ( ++p == pe )
		goto _test_eof351;
case 351:
#line 6782 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr474;
		case 92: goto tr471;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr469;
	goto tr442;
tr474:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st352;
st352:
	if ( ++p == pe )
		goto _test_eof352;
case 352:
#line 6804 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr470;
		case 44: goto tr475;
		case 62: goto tr476;
		case 92: goto tr471;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr469;
	goto tr442;
tr489:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st353;
tr475:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st353;
tr486:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st353;
st353:
	if ( ++p == pe )
		goto _test_eof353;
case 353:
#line 6844 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr470;
		case 47: goto tr469;
		case 92: goto tr471;
		case 95: goto tr477;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr469;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr478;
		} else
			goto tr477;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr478;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr469;
			} else if ( (*p) >= 97 )
				goto tr478;
		} else
			goto tr469;
	} else
		goto tr469;
	goto tr442;
tr477:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st354;
tr479:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st354;
st354:
	if ( ++p == pe )
		goto _test_eof354;
case 354:
#line 6895 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr470;
		case 47: goto tr469;
		case 92: goto tr471;
		case 95: goto tr479;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr469;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr480;
		} else
			goto tr479;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr480;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr469;
			} else if ( (*p) >= 97 )
				goto tr480;
		} else
			goto tr469;
	} else
		goto tr469;
	goto tr442;
tr478:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st355;
tr480:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st355;
st355:
	if ( ++p == pe )
		goto _test_eof355;
case 355:
#line 6946 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr470;
		case 47: goto tr469;
		case 61: goto tr481;
		case 92: goto tr471;
		case 95: goto tr480;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr469;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr469;
		} else
			goto tr480;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr469;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr469;
		} else
			goto tr480;
	} else
		goto tr480;
	goto tr442;
tr481:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st356;
st356:
	if ( ++p == pe )
		goto _test_eof356;
case 356:
#line 6989 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr483;
		case 44: goto tr469;
		case 62: goto tr469;
		case 92: goto tr484;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr482;
	goto tr442;
tr485:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st357;
tr482:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st357;
st357:
	if ( ++p == pe )
		goto _test_eof357;
case 357:
#line 7019 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr470;
		case 44: goto tr486;
		case 62: goto tr487;
		case 92: goto tr488;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr485;
	goto tr442;
tr490:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st358;
tr476:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st358;
tr487:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st358;
st358:
	if ( ++p == pe )
		goto _test_eof358;
case 358:
#line 7059 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 10: goto tr55;
		case 13: goto tr56;
		case 34: goto tr470;
		case 92: goto tr471;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr469;
	goto tr442;
tr488:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st359;
tr484:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st359;
st359:
	if ( ++p == pe )
		goto _test_eof359;
case 359:
#line 7089 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr474;
		case 44: goto tr486;
		case 62: goto tr487;
		case 92: goto tr488;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr485;
	goto tr442;
tr483:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st360;
st360:
	if ( ++p == pe )
		goto _test_eof360;
case 360:
#line 7109 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 34: goto tr467;
		case 44: goto tr489;
		case 62: goto tr490;
		case 92: goto tr468;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr466;
	goto tr442;
tr38:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st361;
st361:
	if ( ++p == pe )
		goto _test_eof361;
case 361:
#line 7133 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 101: goto tr492;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr491;
tr492:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st362;
st362:
	if ( ++p == pe )
		goto _test_eof362;
case 362:
#line 7151 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 100: goto tr493;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr491;
tr493:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st363;
st363:
	if ( ++p == pe )
		goto _test_eof363;
case 363:
#line 7169 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 105: goto tr494;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr491;
tr494:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st364;
st364:
	if ( ++p == pe )
		goto _test_eof364;
case 364:
#line 7187 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 103: goto tr495;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr491;
tr495:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st365;
st365:
	if ( ++p == pe )
		goto _test_eof365;
case 365:
#line 7205 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 114: goto tr496;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr491;
tr496:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st366;
st366:
	if ( ++p == pe )
		goto _test_eof366;
case 366:
#line 7223 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 101: goto tr497;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr491;
tr497:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st367;
st367:
	if ( ++p == pe )
		goto _test_eof367;
case 367:
#line 7241 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 101: goto tr498;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr491;
tr498:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st368;
st368:
	if ( ++p == pe )
		goto _test_eof368;
case 368:
#line 7259 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 68: goto tr499;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr491;
tr499:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st369;
st369:
	if ( ++p == pe )
		goto _test_eof369;
case 369:
#line 7277 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 61: goto tr41;
		case 66: goto st370;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr491;
st370:
	if ( ++p == pe )
		goto _test_eof370;
case 370:
	if ( (*p) == 61 )
		goto tr501;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr491;
tr501:
#line 136 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "pedigreeDB");
    }
	goto st371;
st371:
	if ( ++p == pe )
		goto _test_eof371;
case 371:
#line 7304 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 60 )
		goto st372;
	goto tr491;
st372:
	if ( ++p == pe )
		goto _test_eof372;
case 372:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr504;
	} else if ( (*p) >= 65 )
		goto tr504;
	goto tr503;
tr504:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st373;
st373:
	if ( ++p == pe )
		goto _test_eof373;
case 373:
#line 7328 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 10: goto tr503;
		case 13: goto tr506;
		case 35: goto tr503;
		case 47: goto tr503;
		case 58: goto tr503;
		case 63: goto tr503;
	}
	goto st374;
tr506:
#line 43 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st374;
st374:
	if ( ++p == pe )
		goto _test_eof374;
case 374:
#line 7354 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 10: goto tr503;
		case 13: goto tr506;
		case 35: goto tr503;
		case 47: goto tr503;
		case 58: goto st375;
		case 63: goto tr503;
	}
	goto st374;
st375:
	if ( ++p == pe )
		goto _test_eof375;
case 375:
	if ( (*p) == 47 )
		goto st376;
	goto tr503;
st376:
	if ( ++p == pe )
		goto _test_eof376;
case 376:
	if ( (*p) == 47 )
		goto st377;
	goto tr503;
st377:
	if ( ++p == pe )
		goto _test_eof377;
case 377:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st378;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr511;
	} else
		goto tr511;
	goto tr503;
st378:
	if ( ++p == pe )
		goto _test_eof378;
case 378:
	if ( (*p) == 46 )
		goto st379;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st391;
	goto tr503;
st379:
	if ( ++p == pe )
		goto _test_eof379;
case 379:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st380;
	goto tr503;
st380:
	if ( ++p == pe )
		goto _test_eof380;
case 380:
	if ( (*p) == 46 )
		goto st381;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st389;
	goto tr503;
st381:
	if ( ++p == pe )
		goto _test_eof381;
case 381:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st382;
	goto tr503;
st382:
	if ( ++p == pe )
		goto _test_eof382;
case 382:
	if ( (*p) == 46 )
		goto st383;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st387;
	goto tr503;
st383:
	if ( ++p == pe )
		goto _test_eof383;
case 383:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr511;
	goto tr503;
tr511:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st384;
tr520:
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
	goto st384;
st384:
	if ( ++p == pe )
		goto _test_eof384;
case 384:
#line 7465 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 10: goto tr503;
		case 13: goto tr520;
		case 62: goto tr521;
	}
	goto tr511;
tr521:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st385;
st385:
	if ( ++p == pe )
		goto _test_eof385;
case 385:
#line 7486 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 10: goto tr55;
		case 13: goto tr522;
		case 62: goto tr521;
	}
	goto tr511;
tr522:
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
	goto st386;
st386:
	if ( ++p == pe )
		goto _test_eof386;
case 386:
#line 7521 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 10: goto st28;
		case 13: goto tr520;
		case 62: goto tr521;
	}
	goto tr511;
st387:
	if ( ++p == pe )
		goto _test_eof387;
case 387:
	if ( (*p) == 46 )
		goto st383;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st388;
	goto tr503;
st388:
	if ( ++p == pe )
		goto _test_eof388;
case 388:
	if ( (*p) == 46 )
		goto st383;
	goto tr503;
st389:
	if ( ++p == pe )
		goto _test_eof389;
case 389:
	if ( (*p) == 46 )
		goto st381;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st390;
	goto tr503;
st390:
	if ( ++p == pe )
		goto _test_eof390;
case 390:
	if ( (*p) == 46 )
		goto st381;
	goto tr503;
st391:
	if ( ++p == pe )
		goto _test_eof391;
case 391:
	if ( (*p) == 46 )
		goto st379;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st392;
	goto tr503;
st392:
	if ( ++p == pe )
		goto _test_eof392;
case 392:
	if ( (*p) == 46 )
		goto st379;
	goto tr503;
st393:
	if ( ++p == pe )
		goto _test_eof393;
case 393:
	if ( (*p) == 72 )
		goto st394;
	goto tr526;
st394:
	if ( ++p == pe )
		goto _test_eof394;
case 394:
	if ( (*p) == 82 )
		goto st395;
	goto tr526;
st395:
	if ( ++p == pe )
		goto _test_eof395;
case 395:
	if ( (*p) == 79 )
		goto st396;
	goto tr526;
st396:
	if ( ++p == pe )
		goto _test_eof396;
case 396:
	if ( (*p) == 77 )
		goto st397;
	goto tr526;
st397:
	if ( ++p == pe )
		goto _test_eof397;
case 397:
	if ( (*p) == 9 )
		goto tr531;
	goto tr526;
tr531:
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st398;
st398:
	if ( ++p == pe )
		goto _test_eof398;
case 398:
#line 7621 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 80 )
		goto st399;
	goto tr526;
st399:
	if ( ++p == pe )
		goto _test_eof399;
case 399:
	if ( (*p) == 79 )
		goto st400;
	goto tr526;
st400:
	if ( ++p == pe )
		goto _test_eof400;
case 400:
	if ( (*p) == 83 )
		goto st401;
	goto tr526;
st401:
	if ( ++p == pe )
		goto _test_eof401;
case 401:
	if ( (*p) == 9 )
		goto tr535;
	goto tr526;
tr535:
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st402;
st402:
	if ( ++p == pe )
		goto _test_eof402;
case 402:
#line 7656 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 73 )
		goto st403;
	goto tr526;
st403:
	if ( ++p == pe )
		goto _test_eof403;
case 403:
	if ( (*p) == 68 )
		goto st404;
	goto tr526;
st404:
	if ( ++p == pe )
		goto _test_eof404;
case 404:
	if ( (*p) == 9 )
		goto tr538;
	goto tr526;
tr538:
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st405;
st405:
	if ( ++p == pe )
		goto _test_eof405;
case 405:
#line 7684 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 82 )
		goto st406;
	goto tr526;
st406:
	if ( ++p == pe )
		goto _test_eof406;
case 406:
	if ( (*p) == 69 )
		goto st407;
	goto tr526;
st407:
	if ( ++p == pe )
		goto _test_eof407;
case 407:
	if ( (*p) == 70 )
		goto st408;
	goto tr526;
st408:
	if ( ++p == pe )
		goto _test_eof408;
case 408:
	if ( (*p) == 9 )
		goto tr542;
	goto tr526;
tr542:
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st409;
st409:
	if ( ++p == pe )
		goto _test_eof409;
case 409:
#line 7719 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 65 )
		goto st410;
	goto tr526;
st410:
	if ( ++p == pe )
		goto _test_eof410;
case 410:
	if ( (*p) == 76 )
		goto st411;
	goto tr526;
st411:
	if ( ++p == pe )
		goto _test_eof411;
case 411:
	if ( (*p) == 84 )
		goto st412;
	goto tr526;
st412:
	if ( ++p == pe )
		goto _test_eof412;
case 412:
	if ( (*p) == 9 )
		goto tr546;
	goto tr526;
tr546:
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st413;
st413:
	if ( ++p == pe )
		goto _test_eof413;
case 413:
#line 7754 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 81 )
		goto st414;
	goto tr526;
st414:
	if ( ++p == pe )
		goto _test_eof414;
case 414:
	if ( (*p) == 85 )
		goto st415;
	goto tr526;
st415:
	if ( ++p == pe )
		goto _test_eof415;
case 415:
	if ( (*p) == 65 )
		goto st416;
	goto tr526;
st416:
	if ( ++p == pe )
		goto _test_eof416;
case 416:
	if ( (*p) == 76 )
		goto st417;
	goto tr526;
st417:
	if ( ++p == pe )
		goto _test_eof417;
case 417:
	if ( (*p) == 9 )
		goto tr551;
	goto tr526;
tr551:
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st418;
st418:
	if ( ++p == pe )
		goto _test_eof418;
case 418:
#line 7796 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 70 )
		goto st419;
	goto tr526;
st419:
	if ( ++p == pe )
		goto _test_eof419;
case 419:
	if ( (*p) == 73 )
		goto st420;
	goto tr526;
st420:
	if ( ++p == pe )
		goto _test_eof420;
case 420:
	if ( (*p) == 76 )
		goto st421;
	goto tr526;
st421:
	if ( ++p == pe )
		goto _test_eof421;
case 421:
	if ( (*p) == 84 )
		goto st422;
	goto tr526;
st422:
	if ( ++p == pe )
		goto _test_eof422;
case 422:
	if ( (*p) == 69 )
		goto st423;
	goto tr526;
st423:
	if ( ++p == pe )
		goto _test_eof423;
case 423:
	if ( (*p) == 82 )
		goto st424;
	goto tr526;
st424:
	if ( ++p == pe )
		goto _test_eof424;
case 424:
	if ( (*p) == 9 )
		goto tr558;
	goto tr526;
tr558:
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st425;
st425:
	if ( ++p == pe )
		goto _test_eof425;
case 425:
#line 7852 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 73 )
		goto st426;
	goto tr526;
st426:
	if ( ++p == pe )
		goto _test_eof426;
case 426:
	if ( (*p) == 78 )
		goto st427;
	goto tr526;
st427:
	if ( ++p == pe )
		goto _test_eof427;
case 427:
	if ( (*p) == 70 )
		goto st428;
	goto tr526;
st428:
	if ( ++p == pe )
		goto _test_eof428;
case 428:
	if ( (*p) == 79 )
		goto st429;
	goto tr526;
st429:
	if ( ++p == pe )
		goto _test_eof429;
case 429:
	switch( (*p) ) {
		case 9: goto tr563;
		case 10: goto tr564;
		case 13: goto tr565;
	}
	goto tr526;
tr563:
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st430;
st430:
	if ( ++p == pe )
		goto _test_eof430;
case 430:
#line 7897 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 70 )
		goto st431;
	goto tr566;
st431:
	if ( ++p == pe )
		goto _test_eof431;
case 431:
	if ( (*p) == 79 )
		goto st432;
	goto tr566;
st432:
	if ( ++p == pe )
		goto _test_eof432;
case 432:
	if ( (*p) == 82 )
		goto st433;
	goto tr566;
st433:
	if ( ++p == pe )
		goto _test_eof433;
case 433:
	if ( (*p) == 77 )
		goto st434;
	goto tr566;
st434:
	if ( ++p == pe )
		goto _test_eof434;
case 434:
	if ( (*p) == 65 )
		goto st435;
	goto tr566;
st435:
	if ( ++p == pe )
		goto _test_eof435;
case 435:
	if ( (*p) == 84 )
		goto st436;
	goto tr566;
st436:
	if ( ++p == pe )
		goto _test_eof436;
case 436:
	if ( (*p) == 9 )
		goto tr573;
	goto tr566;
tr573:
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st437;
tr575:
#line 204 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_sample_name(*this);
    }
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st437;
st437:
	if ( ++p == pe )
		goto _test_eof437;
case 437:
#line 7963 "inc/vcf/validator_detail_v41.hpp"
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr574;
	goto tr566;
tr574:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st438;
tr578:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st438;
st438:
	if ( ++p == pe )
		goto _test_eof438;
case 438:
#line 7987 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr575;
		case 10: goto tr576;
		case 13: goto tr577;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr578;
	goto tr566;
tr564:
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
	goto st535;
tr576:
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
	goto st535;
st535:
	if ( ++p == pe )
		goto _test_eof535;
case 535:
#line 8044 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 10: goto tr714;
		case 13: goto tr715;
		case 60: goto tr717;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr716;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr716;
	} else
		goto tr716;
	goto tr713;
tr718:
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
tr714:
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
	goto st536;
st536:
	if ( ++p == pe )
		goto _test_eof536;
case 536:
#line 8095 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 10: goto tr718;
		case 13: goto tr719;
	}
	goto st0;
tr719:
#line 43 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st439;
tr715:
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
	goto st439;
st439:
	if ( ++p == pe )
		goto _test_eof439;
case 439:
#line 8137 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 10 )
		goto st536;
	goto st0;
tr725:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st440;
tr583:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st440;
tr716:
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
	goto st440;
st440:
	if ( ++p == pe )
		goto _test_eof440;
case 440:
#line 8179 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr582;
		case 61: goto tr583;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr583;
	} else if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr583;
	} else
		goto tr583;
	goto tr581;
tr582:
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
	goto st441;
tr641:
#line 218 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st441;
st441:
	if ( ++p == pe )
		goto _test_eof441;
case 441:
#line 8221 "inc/vcf/validator_detail_v41.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr585;
	goto tr584;
tr585:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st442;
tr587:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st442;
st442:
	if ( ++p == pe )
		goto _test_eof442;
case 442:
#line 8245 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 9 )
		goto tr586;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr587;
	goto tr584;
tr592:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st443;
tr586:
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
	goto st443;
st443:
	if ( ++p == pe )
		goto _test_eof443;
case 443:
#line 8275 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr589;
	} else if ( (*p) >= 33 )
		goto tr589;
	goto tr588;
tr589:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st444;
tr591:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st444;
st444:
	if ( ++p == pe )
		goto _test_eof444;
case 444:
#line 8302 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr590;
		case 59: goto tr592;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr591;
	goto tr588;
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
	goto st445;
st445:
	if ( ++p == pe )
		goto _test_eof445;
case 445:
#line 8328 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 65: goto tr594;
		case 67: goto tr594;
		case 71: goto tr594;
		case 78: goto tr594;
		case 84: goto tr594;
		case 97: goto tr594;
		case 99: goto tr594;
		case 103: goto tr594;
		case 110: goto tr594;
		case 116: goto tr594;
	}
	goto tr593;
tr594:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st446;
tr596:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st446;
st446:
	if ( ++p == pe )
		goto _test_eof446;
case 446:
#line 8362 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr595;
		case 65: goto tr596;
		case 67: goto tr596;
		case 71: goto tr596;
		case 78: goto tr596;
		case 84: goto tr596;
		case 97: goto tr596;
		case 99: goto tr596;
		case 103: goto tr596;
		case 110: goto tr596;
		case 116: goto tr596;
	}
	goto tr593;
tr595:
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
	goto st447;
st447:
	if ( ++p == pe )
		goto _test_eof447;
case 447:
#line 8395 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 42: goto tr598;
		case 46: goto tr599;
		case 60: goto tr600;
		case 65: goto tr601;
		case 67: goto tr601;
		case 71: goto tr601;
		case 78: goto tr601;
		case 84: goto tr601;
		case 91: goto tr602;
		case 93: goto tr603;
		case 97: goto tr601;
		case 99: goto tr601;
		case 103: goto tr601;
		case 110: goto tr601;
		case 116: goto tr601;
	}
	goto tr597;
tr598:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st448;
tr662:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st448;
st448:
	if ( ++p == pe )
		goto _test_eof448;
case 448:
#line 8434 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr604;
		case 44: goto tr605;
	}
	goto tr597;
tr604:
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
	goto st449;
st449:
	if ( ++p == pe )
		goto _test_eof449;
case 449:
#line 8458 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 43: goto tr607;
		case 45: goto tr607;
		case 46: goto tr608;
		case 73: goto tr610;
		case 78: goto tr611;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr609;
	goto tr606;
tr607:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st450;
st450:
	if ( ++p == pe )
		goto _test_eof450;
case 450:
#line 8483 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 73 )
		goto tr613;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr612;
	goto tr606;
tr609:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st451;
tr612:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st451;
st451:
	if ( ++p == pe )
		goto _test_eof451;
case 451:
#line 8509 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr614;
		case 46: goto tr615;
		case 69: goto tr616;
		case 101: goto tr616;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr612;
	goto tr606;
tr614:
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
case 452:
#line 8537 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 46: goto tr619;
		case 58: goto tr618;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr618;
		} else if ( (*p) > 57 ) {
			if ( 60 <= (*p) && (*p) <= 64 )
				goto tr618;
		} else
			goto tr620;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr618;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr618;
		} else
			goto tr620;
	} else
		goto tr620;
	goto tr617;
tr618:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st453;
st453:
	if ( ++p == pe )
		goto _test_eof453;
case 453:
#line 8573 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 58 )
		goto st453;
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto st453;
		} else if ( (*p) > 57 ) {
			if ( 60 <= (*p) && (*p) <= 64 )
				goto st453;
		} else
			goto tr622;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st453;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st453;
		} else
			goto tr622;
	} else
		goto tr622;
	goto tr617;
tr620:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st454;
tr622:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st454;
st454:
	if ( ++p == pe )
		goto _test_eof454;
case 454:
#line 8617 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr623;
		case 59: goto tr624;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr622;
	goto tr617;
tr623:
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
	goto st455;
st455:
	if ( ++p == pe )
		goto _test_eof455;
case 455:
#line 8643 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 46: goto tr626;
		case 49: goto tr627;
		case 95: goto tr628;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr628;
	} else if ( (*p) >= 65 )
		goto tr628;
	goto tr625;
tr626:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st537;
st537:
	if ( ++p == pe )
		goto _test_eof537;
case 537:
#line 8669 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr721;
		case 10: goto tr722;
		case 13: goto tr723;
	}
	goto tr720;
tr633:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st456;
tr721:
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
	goto st456;
st456:
	if ( ++p == pe )
		goto _test_eof456;
case 456:
#line 8700 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr630;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr630;
	} else
		goto tr630;
	goto tr629;
tr630:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st457;
tr632:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st457;
st457:
	if ( ++p == pe )
		goto _test_eof457;
case 457:
#line 8730 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr631;
		case 58: goto tr633;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr632;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr632;
	} else
		goto tr632;
	goto tr629;
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
	goto st458;
st458:
	if ( ++p == pe )
		goto _test_eof458;
case 458:
#line 8762 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 46 )
		goto tr636;
	if ( (*p) < 48 ) {
		if ( 33 <= (*p) && (*p) <= 47 )
			goto tr635;
	} else if ( (*p) > 57 ) {
		if ( 59 <= (*p) && (*p) <= 126 )
			goto tr635;
	} else
		goto tr637;
	goto tr634;
tr635:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st538;
tr645:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st538;
st538:
	if ( ++p == pe )
		goto _test_eof538;
case 538:
#line 8794 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr631;
		case 10: goto tr722;
		case 13: goto tr723;
		case 58: goto tr724;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr645;
	goto tr644;
tr722:
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
	goto st539;
st539:
	if ( ++p == pe )
		goto _test_eof539;
case 539:
#line 8861 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 10: goto tr718;
		case 13: goto tr719;
		case 60: goto st459;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr725;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr725;
	} else
		goto tr725;
	goto tr581;
tr717:
#line 70 "src/vcf/vcf.ragel"
	{
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (Error *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
    }
	goto st459;
st459:
	if ( ++p == pe )
		goto _test_eof459;
case 459:
#line 8890 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr638;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr638;
	} else
		goto tr638;
	goto tr581;
tr638:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st460;
tr639:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st460;
st460:
	if ( ++p == pe )
		goto _test_eof460;
case 460:
#line 8920 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 62 )
		goto tr640;
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr639;
	} else if ( (*p) > 59 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr639;
	} else
		goto tr639;
	goto tr581;
tr640:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st461;
st461:
	if ( ++p == pe )
		goto _test_eof461;
case 461:
#line 8942 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 9 )
		goto tr641;
	goto tr581;
tr723:
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
	goto st462;
st462:
	if ( ++p == pe )
		goto _test_eof462;
case 462:
#line 9003 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 10 )
		goto st539;
	goto tr642;
tr724:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st463;
st463:
	if ( ++p == pe )
		goto _test_eof463;
case 463:
#line 9017 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) > 57 ) {
		if ( 59 <= (*p) && (*p) <= 126 )
			goto tr645;
	} else if ( (*p) >= 33 )
		goto tr645;
	goto tr644;
tr636:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st540;
tr728:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st540;
st540:
	if ( ++p == pe )
		goto _test_eof540;
case 540:
#line 9044 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr631;
		case 10: goto tr722;
		case 13: goto tr723;
		case 47: goto tr727;
		case 58: goto tr724;
		case 124: goto tr727;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr645;
	goto tr634;
tr727:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st541;
st541:
	if ( ++p == pe )
		goto _test_eof541;
case 541:
#line 9066 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr631;
		case 10: goto tr722;
		case 13: goto tr723;
		case 46: goto tr728;
		case 58: goto tr724;
	}
	if ( (*p) < 48 ) {
		if ( 33 <= (*p) && (*p) <= 47 )
			goto tr645;
	} else if ( (*p) > 57 ) {
		if ( 59 <= (*p) && (*p) <= 126 )
			goto tr645;
	} else
		goto tr729;
	goto tr634;
tr637:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st542;
tr729:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st542;
st542:
	if ( ++p == pe )
		goto _test_eof542;
case 542:
#line 9103 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr631;
		case 10: goto tr722;
		case 13: goto tr723;
		case 47: goto tr727;
		case 58: goto tr724;
		case 124: goto tr727;
	}
	if ( (*p) < 48 ) {
		if ( 33 <= (*p) && (*p) <= 46 )
			goto tr645;
	} else if ( (*p) > 57 ) {
		if ( 59 <= (*p) && (*p) <= 126 )
			goto tr645;
	} else
		goto tr729;
	goto tr634;
tr627:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st464;
st464:
	if ( ++p == pe )
		goto _test_eof464;
case 464:
#line 9135 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 48 )
		goto tr646;
	goto tr625;
tr646:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st465;
st465:
	if ( ++p == pe )
		goto _test_eof465;
case 465:
#line 9149 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 48 )
		goto tr647;
	goto tr625;
tr647:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st466;
st466:
	if ( ++p == pe )
		goto _test_eof466;
case 466:
#line 9163 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 48 )
		goto tr648;
	goto tr625;
tr648:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st467;
st467:
	if ( ++p == pe )
		goto _test_eof467;
case 467:
#line 9177 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 71 )
		goto tr649;
	goto tr625;
tr649:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st543;
st543:
	if ( ++p == pe )
		goto _test_eof543;
case 543:
#line 9191 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr721;
		case 10: goto tr722;
		case 13: goto tr723;
		case 59: goto tr730;
		case 61: goto tr731;
	}
	goto tr625;
tr730:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st468;
st468:
	if ( ++p == pe )
		goto _test_eof468;
case 468:
#line 9210 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 49: goto tr627;
		case 95: goto tr628;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr628;
	} else if ( (*p) >= 65 )
		goto tr628;
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
	goto st544;
tr732:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st544;
st544:
	if ( ++p == pe )
		goto _test_eof544;
case 544:
#line 9241 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr721;
		case 10: goto tr722;
		case 13: goto tr723;
		case 46: goto tr732;
		case 59: goto tr730;
		case 61: goto tr731;
		case 95: goto tr732;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr732;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr732;
	} else
		goto tr732;
	goto tr625;
tr731:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st469;
st469:
	if ( ++p == pe )
		goto _test_eof469;
case 469:
#line 9270 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr651;
	} else if ( (*p) >= 33 )
		goto tr651;
	goto tr650;
tr651:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st545;
st545:
	if ( ++p == pe )
		goto _test_eof545;
case 545:
#line 9287 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr721;
		case 10: goto tr722;
		case 13: goto tr723;
		case 59: goto tr730;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr651;
	goto tr650;
tr624:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st470;
st470:
	if ( ++p == pe )
		goto _test_eof470;
case 470:
#line 9307 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 58 )
		goto tr618;
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr618;
		} else if ( (*p) > 57 ) {
			if ( 60 <= (*p) && (*p) <= 64 )
				goto tr618;
		} else
			goto tr620;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr618;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr618;
		} else
			goto tr620;
	} else
		goto tr620;
	goto tr617;
tr619:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st471;
st471:
	if ( ++p == pe )
		goto _test_eof471;
case 471:
#line 9345 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr623;
		case 58: goto st453;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto st453;
		} else if ( (*p) > 57 ) {
			if ( 60 <= (*p) && (*p) <= 64 )
				goto st453;
		} else
			goto tr622;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st453;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st453;
		} else
			goto tr622;
	} else
		goto tr622;
	goto tr617;
tr615:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st472;
st472:
	if ( ++p == pe )
		goto _test_eof472;
case 472:
#line 9381 "inc/vcf/validator_detail_v41.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr652;
	goto tr606;
tr652:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st473;
st473:
	if ( ++p == pe )
		goto _test_eof473;
case 473:
#line 9395 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr614;
		case 69: goto tr616;
		case 101: goto tr616;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr652;
	goto tr606;
tr616:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st474;
st474:
	if ( ++p == pe )
		goto _test_eof474;
case 474:
#line 9414 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 43: goto tr653;
		case 45: goto tr653;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr654;
	goto tr606;
tr653:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st475;
st475:
	if ( ++p == pe )
		goto _test_eof475;
case 475:
#line 9432 "inc/vcf/validator_detail_v41.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr654;
	goto tr606;
tr654:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st476;
st476:
	if ( ++p == pe )
		goto _test_eof476;
case 476:
#line 9446 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 9 )
		goto tr614;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr654;
	goto tr606;
tr610:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st477;
tr613:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st477;
st477:
	if ( ++p == pe )
		goto _test_eof477;
case 477:
#line 9472 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 110 )
		goto tr655;
	goto tr606;
tr655:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st478;
st478:
	if ( ++p == pe )
		goto _test_eof478;
case 478:
#line 9486 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 102 )
		goto tr656;
	goto tr606;
tr608:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st479;
tr656:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st479;
st479:
	if ( ++p == pe )
		goto _test_eof479;
case 479:
#line 9510 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 9 )
		goto tr614;
	goto tr606;
tr611:
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
case 480:
#line 9528 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 97 )
		goto tr657;
	goto tr606;
tr657:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st481;
st481:
	if ( ++p == pe )
		goto _test_eof481;
case 481:
#line 9542 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 78 )
		goto tr656;
	goto tr606;
tr605:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st482;
st482:
	if ( ++p == pe )
		goto _test_eof482;
case 482:
#line 9556 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 42: goto tr598;
		case 46: goto tr658;
		case 60: goto tr600;
		case 65: goto tr601;
		case 67: goto tr601;
		case 71: goto tr601;
		case 78: goto tr601;
		case 84: goto tr601;
		case 91: goto tr602;
		case 93: goto tr603;
		case 97: goto tr601;
		case 99: goto tr601;
		case 103: goto tr601;
		case 110: goto tr601;
		case 116: goto tr601;
	}
	goto tr597;
tr658:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st483;
tr694:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st483;
st483:
	if ( ++p == pe )
		goto _test_eof483;
case 483:
#line 9595 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 65: goto tr659;
		case 67: goto tr659;
		case 71: goto tr659;
		case 78: goto tr659;
		case 84: goto tr659;
		case 97: goto tr659;
		case 99: goto tr659;
		case 103: goto tr659;
		case 110: goto tr659;
		case 116: goto tr659;
	}
	goto tr597;
tr659:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st484;
st484:
	if ( ++p == pe )
		goto _test_eof484;
case 484:
#line 9619 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr604;
		case 44: goto tr605;
		case 65: goto tr659;
		case 67: goto tr659;
		case 71: goto tr659;
		case 78: goto tr659;
		case 84: goto tr659;
		case 97: goto tr659;
		case 99: goto tr659;
		case 103: goto tr659;
		case 110: goto tr659;
		case 116: goto tr659;
	}
	goto tr597;
tr600:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st485;
tr660:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st485;
st485:
	if ( ++p == pe )
		goto _test_eof485;
case 485:
#line 9655 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 61 )
		goto tr660;
	if ( (*p) < 63 ) {
		if ( (*p) < 45 ) {
			if ( 33 <= (*p) && (*p) <= 43 )
				goto tr660;
		} else if ( (*p) > 47 ) {
			if ( (*p) > 57 ) {
				if ( 58 <= (*p) && (*p) <= 59 )
					goto tr660;
			} else if ( (*p) >= 48 )
				goto tr661;
		} else
			goto tr660;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr661;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr660;
			} else if ( (*p) >= 97 )
				goto tr661;
		} else
			goto tr660;
	} else
		goto tr660;
	goto tr597;
tr661:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st486;
st486:
	if ( ++p == pe )
		goto _test_eof486;
case 486:
#line 9695 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 62 )
		goto tr662;
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr661;
	} else if ( (*p) > 59 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr661;
	} else
		goto tr661;
	goto tr597;
tr601:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st487;
tr663:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st487;
st487:
	if ( ++p == pe )
		goto _test_eof487;
case 487:
#line 9727 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr604;
		case 44: goto tr605;
		case 46: goto tr662;
		case 65: goto tr663;
		case 67: goto tr663;
		case 71: goto tr663;
		case 78: goto tr663;
		case 84: goto tr663;
		case 91: goto tr664;
		case 93: goto tr665;
		case 97: goto tr663;
		case 99: goto tr663;
		case 103: goto tr663;
		case 110: goto tr663;
		case 116: goto tr663;
	}
	goto tr597;
tr664:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st488;
st488:
	if ( ++p == pe )
		goto _test_eof488;
case 488:
#line 9756 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 60 )
		goto tr667;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr666;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr666;
	} else
		goto tr666;
	goto tr597;
tr666:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st489;
st489:
	if ( ++p == pe )
		goto _test_eof489;
case 489:
#line 9778 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 58: goto tr668;
		case 61: goto tr666;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr666;
	} else if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr666;
	} else
		goto tr666;
	goto tr597;
tr668:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st490;
st490:
	if ( ++p == pe )
		goto _test_eof490;
case 490:
#line 9802 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 58: goto tr668;
		case 59: goto tr666;
		case 61: goto tr666;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr666;
	} else if ( (*p) > 47 ) {
		if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 126 )
				goto tr666;
		} else if ( (*p) >= 48 )
			goto tr669;
	} else
		goto tr666;
	goto tr597;
tr669:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st491;
st491:
	if ( ++p == pe )
		goto _test_eof491;
case 491:
#line 9830 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 58: goto tr668;
		case 59: goto tr666;
		case 61: goto tr666;
		case 91: goto tr670;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr666;
	} else if ( (*p) > 47 ) {
		if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 126 )
				goto tr666;
		} else if ( (*p) >= 48 )
			goto tr669;
	} else
		goto tr666;
	goto tr597;
tr670:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st492;
st492:
	if ( ++p == pe )
		goto _test_eof492;
case 492:
#line 9859 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr604;
		case 44: goto tr605;
		case 58: goto tr668;
		case 61: goto tr666;
	}
	if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr666;
	} else if ( (*p) >= 33 )
		goto tr666;
	goto tr597;
tr667:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st493;
st493:
	if ( ++p == pe )
		goto _test_eof493;
case 493:
#line 9882 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr671;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr671;
	} else
		goto tr671;
	goto tr597;
tr671:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st494;
st494:
	if ( ++p == pe )
		goto _test_eof494;
case 494:
#line 9902 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 62 )
		goto tr672;
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr671;
	} else if ( (*p) > 59 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr671;
	} else
		goto tr671;
	goto tr597;
tr672:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st495;
st495:
	if ( ++p == pe )
		goto _test_eof495;
case 495:
#line 9924 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 58 )
		goto tr673;
	goto tr597;
tr673:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st496;
st496:
	if ( ++p == pe )
		goto _test_eof496;
case 496:
#line 9938 "inc/vcf/validator_detail_v41.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr674;
	goto tr597;
tr674:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st497;
st497:
	if ( ++p == pe )
		goto _test_eof497;
case 497:
#line 9952 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 91 )
		goto tr662;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr674;
	goto tr597;
tr665:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st498;
st498:
	if ( ++p == pe )
		goto _test_eof498;
case 498:
#line 9968 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 60 )
		goto tr676;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr675;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr675;
	} else
		goto tr675;
	goto tr597;
tr675:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st499;
st499:
	if ( ++p == pe )
		goto _test_eof499;
case 499:
#line 9990 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 58: goto tr677;
		case 61: goto tr675;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr675;
	} else if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr675;
	} else
		goto tr675;
	goto tr597;
tr677:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st500;
st500:
	if ( ++p == pe )
		goto _test_eof500;
case 500:
#line 10014 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 58: goto tr677;
		case 59: goto tr675;
		case 61: goto tr675;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr675;
	} else if ( (*p) > 47 ) {
		if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 126 )
				goto tr675;
		} else if ( (*p) >= 48 )
			goto tr678;
	} else
		goto tr675;
	goto tr597;
tr678:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st501;
st501:
	if ( ++p == pe )
		goto _test_eof501;
case 501:
#line 10042 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 58: goto tr677;
		case 59: goto tr675;
		case 61: goto tr675;
		case 93: goto tr679;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr675;
	} else if ( (*p) > 47 ) {
		if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 126 )
				goto tr675;
		} else if ( (*p) >= 48 )
			goto tr678;
	} else
		goto tr675;
	goto tr597;
tr679:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st502;
st502:
	if ( ++p == pe )
		goto _test_eof502;
case 502:
#line 10071 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr604;
		case 44: goto tr605;
		case 58: goto tr677;
		case 61: goto tr675;
	}
	if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr675;
	} else if ( (*p) >= 33 )
		goto tr675;
	goto tr597;
tr676:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st503;
st503:
	if ( ++p == pe )
		goto _test_eof503;
case 503:
#line 10094 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr680;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr680;
	} else
		goto tr680;
	goto tr597;
tr680:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st504;
st504:
	if ( ++p == pe )
		goto _test_eof504;
case 504:
#line 10114 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 62 )
		goto tr681;
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr680;
	} else if ( (*p) > 59 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr680;
	} else
		goto tr680;
	goto tr597;
tr681:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st505;
st505:
	if ( ++p == pe )
		goto _test_eof505;
case 505:
#line 10136 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 58 )
		goto tr682;
	goto tr597;
tr682:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st506;
st506:
	if ( ++p == pe )
		goto _test_eof506;
case 506:
#line 10150 "inc/vcf/validator_detail_v41.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr683;
	goto tr597;
tr683:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st507;
st507:
	if ( ++p == pe )
		goto _test_eof507;
case 507:
#line 10164 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 93 )
		goto tr662;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr683;
	goto tr597;
tr602:
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
#line 10184 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 60 )
		goto tr685;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr684;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr684;
	} else
		goto tr684;
	goto tr597;
tr684:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st509;
st509:
	if ( ++p == pe )
		goto _test_eof509;
case 509:
#line 10206 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 58: goto tr686;
		case 61: goto tr684;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr684;
	} else if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr684;
	} else
		goto tr684;
	goto tr597;
tr686:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st510;
st510:
	if ( ++p == pe )
		goto _test_eof510;
case 510:
#line 10230 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 58: goto tr686;
		case 59: goto tr684;
		case 61: goto tr684;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr684;
	} else if ( (*p) > 47 ) {
		if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 126 )
				goto tr684;
		} else if ( (*p) >= 48 )
			goto tr687;
	} else
		goto tr684;
	goto tr597;
tr687:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st511;
st511:
	if ( ++p == pe )
		goto _test_eof511;
case 511:
#line 10258 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 58: goto tr686;
		case 59: goto tr684;
		case 61: goto tr684;
		case 91: goto tr688;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr684;
	} else if ( (*p) > 47 ) {
		if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 126 )
				goto tr684;
		} else if ( (*p) >= 48 )
			goto tr687;
	} else
		goto tr684;
	goto tr597;
tr688:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st512;
st512:
	if ( ++p == pe )
		goto _test_eof512;
case 512:
#line 10287 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 58: goto tr686;
		case 61: goto tr684;
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
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr684;
	} else if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr684;
	} else
		goto tr684;
	goto tr597;
tr689:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st513;
st513:
	if ( ++p == pe )
		goto _test_eof513;
case 513:
#line 10321 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr604;
		case 44: goto tr605;
		case 58: goto tr686;
		case 61: goto tr684;
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
	if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr684;
	} else if ( (*p) >= 33 )
		goto tr684;
	goto tr597;
tr685:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st514;
st514:
	if ( ++p == pe )
		goto _test_eof514;
case 514:
#line 10354 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr690;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr690;
	} else
		goto tr690;
	goto tr597;
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
#line 10374 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 62 )
		goto tr691;
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr690;
	} else if ( (*p) > 59 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr690;
	} else
		goto tr690;
	goto tr597;
tr691:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st516;
st516:
	if ( ++p == pe )
		goto _test_eof516;
case 516:
#line 10396 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 58 )
		goto tr692;
	goto tr597;
tr692:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st517;
st517:
	if ( ++p == pe )
		goto _test_eof517;
case 517:
#line 10410 "inc/vcf/validator_detail_v41.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr693;
	goto tr597;
tr693:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st518;
st518:
	if ( ++p == pe )
		goto _test_eof518;
case 518:
#line 10424 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 91 )
		goto tr694;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr693;
	goto tr597;
tr603:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st519;
st519:
	if ( ++p == pe )
		goto _test_eof519;
case 519:
#line 10444 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 60 )
		goto tr696;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr695;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr695;
	} else
		goto tr695;
	goto tr597;
tr695:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st520;
st520:
	if ( ++p == pe )
		goto _test_eof520;
case 520:
#line 10466 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 58: goto tr697;
		case 61: goto tr695;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr695;
	} else if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr695;
	} else
		goto tr695;
	goto tr597;
tr697:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st521;
st521:
	if ( ++p == pe )
		goto _test_eof521;
case 521:
#line 10490 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 58: goto tr697;
		case 59: goto tr695;
		case 61: goto tr695;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr695;
	} else if ( (*p) > 47 ) {
		if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 126 )
				goto tr695;
		} else if ( (*p) >= 48 )
			goto tr698;
	} else
		goto tr695;
	goto tr597;
tr698:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st522;
st522:
	if ( ++p == pe )
		goto _test_eof522;
case 522:
#line 10518 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 58: goto tr697;
		case 59: goto tr695;
		case 61: goto tr695;
		case 93: goto tr699;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr695;
	} else if ( (*p) > 47 ) {
		if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 126 )
				goto tr695;
		} else if ( (*p) >= 48 )
			goto tr698;
	} else
		goto tr695;
	goto tr597;
tr699:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st523;
st523:
	if ( ++p == pe )
		goto _test_eof523;
case 523:
#line 10547 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 58: goto tr697;
		case 61: goto tr695;
		case 65: goto tr700;
		case 67: goto tr700;
		case 71: goto tr700;
		case 78: goto tr700;
		case 84: goto tr700;
		case 97: goto tr700;
		case 99: goto tr700;
		case 103: goto tr700;
		case 110: goto tr700;
		case 116: goto tr700;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr695;
	} else if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr695;
	} else
		goto tr695;
	goto tr597;
tr700:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st524;
st524:
	if ( ++p == pe )
		goto _test_eof524;
case 524:
#line 10581 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr604;
		case 44: goto tr605;
		case 58: goto tr697;
		case 61: goto tr695;
		case 65: goto tr700;
		case 67: goto tr700;
		case 71: goto tr700;
		case 78: goto tr700;
		case 84: goto tr700;
		case 97: goto tr700;
		case 99: goto tr700;
		case 103: goto tr700;
		case 110: goto tr700;
		case 116: goto tr700;
	}
	if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr695;
	} else if ( (*p) >= 33 )
		goto tr695;
	goto tr597;
tr696:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st525;
st525:
	if ( ++p == pe )
		goto _test_eof525;
case 525:
#line 10614 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr701;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr701;
	} else
		goto tr701;
	goto tr597;
tr701:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st526;
st526:
	if ( ++p == pe )
		goto _test_eof526;
case 526:
#line 10634 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 62 )
		goto tr702;
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr701;
	} else if ( (*p) > 59 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr701;
	} else
		goto tr701;
	goto tr597;
tr702:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st527;
st527:
	if ( ++p == pe )
		goto _test_eof527;
case 527:
#line 10656 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 58 )
		goto tr703;
	goto tr597;
tr703:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st528;
st528:
	if ( ++p == pe )
		goto _test_eof528;
case 528:
#line 10670 "inc/vcf/validator_detail_v41.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr704;
	goto tr597;
tr704:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st529;
st529:
	if ( ++p == pe )
		goto _test_eof529;
case 529:
#line 10684 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 93 )
		goto tr694;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr704;
	goto tr597;
tr599:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st530;
st530:
	if ( ++p == pe )
		goto _test_eof530;
case 530:
#line 10704 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 9: goto tr604;
		case 65: goto tr659;
		case 67: goto tr659;
		case 71: goto tr659;
		case 78: goto tr659;
		case 84: goto tr659;
		case 97: goto tr659;
		case 99: goto tr659;
		case 103: goto tr659;
		case 110: goto tr659;
		case 116: goto tr659;
	}
	goto tr597;
tr565:
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
	goto st531;
tr577:
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
	goto st531;
st531:
	if ( ++p == pe )
		goto _test_eof531;
case 531:
#line 10767 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 10 )
		goto st535;
	goto tr566;
tr23:
#line 99 "src/vcf/vcf.ragel"
	{
        try {
          ParsePolicy::handle_fileformat(*this);
        } catch (Error *error) {
          ErrorPolicy::handle_error(*this, error);
          p--; {goto st533;}
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
case 532:
#line 10796 "inc/vcf/validator_detail_v41.hpp"
	if ( (*p) == 10 )
		goto st22;
	goto tr0;
tr709:
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
case 533:
#line 10816 "inc/vcf/validator_detail_v41.hpp"
	switch( (*p) ) {
		case 10: goto tr708;
		case 13: goto tr709;
	}
	goto st533;
tr708:
#line 43 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
#line 227 "src/vcf/vcf_v41.ragel"
	{ {goto st28;} }
	goto st546;
st546:
	if ( ++p == pe )
		goto _test_eof546;
case 546:
#line 10840 "inc/vcf/validator_detail_v41.hpp"
	goto st0;
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
case 534:
#line 10858 "inc/vcf/validator_detail_v41.hpp"
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
#line 228 "src/vcf/vcf_v41.ragel"
	{ {goto st539;} }
	goto st547;
st547:
	if ( ++p == pe )
		goto _test_eof547;
case 547:
#line 10882 "inc/vcf/validator_detail_v41.hpp"
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
	_test_eof535: cs = 535; goto _test_eof; 
	_test_eof536: cs = 536; goto _test_eof; 
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
	_test_eof537: cs = 537; goto _test_eof; 
	_test_eof456: cs = 456; goto _test_eof; 
	_test_eof457: cs = 457; goto _test_eof; 
	_test_eof458: cs = 458; goto _test_eof; 
	_test_eof538: cs = 538; goto _test_eof; 
	_test_eof539: cs = 539; goto _test_eof; 
	_test_eof459: cs = 459; goto _test_eof; 
	_test_eof460: cs = 460; goto _test_eof; 
	_test_eof461: cs = 461; goto _test_eof; 
	_test_eof462: cs = 462; goto _test_eof; 
	_test_eof463: cs = 463; goto _test_eof; 
	_test_eof540: cs = 540; goto _test_eof; 
	_test_eof541: cs = 541; goto _test_eof; 
	_test_eof542: cs = 542; goto _test_eof; 
	_test_eof464: cs = 464; goto _test_eof; 
	_test_eof465: cs = 465; goto _test_eof; 
	_test_eof466: cs = 466; goto _test_eof; 
	_test_eof467: cs = 467; goto _test_eof; 
	_test_eof543: cs = 543; goto _test_eof; 
	_test_eof468: cs = 468; goto _test_eof; 
	_test_eof544: cs = 544; goto _test_eof; 
	_test_eof469: cs = 469; goto _test_eof; 
	_test_eof545: cs = 545; goto _test_eof; 
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
	_test_eof546: cs = 546; goto _test_eof; 
	_test_eof534: cs = 534; goto _test_eof; 
	_test_eof547: cs = 547; goto _test_eof; 

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
	case 532: 
#line 60 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new FileformatError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
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
               goto _test_eof533;
goto st533;}
    }
	break;
	case 535: 
#line 70 "src/vcf/vcf.ragel"
	{
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (Error *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
    }
	break;
	case 430: 
	case 431: 
	case 432: 
	case 433: 
	case 434: 
	case 435: 
	case 436: 
	case 437: 
	case 438: 
	case 531: 
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
               goto _test_eof534;
goto st534;}
    }
	break;
	case 462: 
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
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
	case 100: 
#line 259 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
	break;
	case 303: 
	case 304: 
	case 305: 
	case 306: 
	case 307: 
	case 308: 
	case 309: 
	case 310: 
#line 271 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in assembly metadata"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
	break;
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
	case 360: 
#line 277 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in contig metadata"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
	break;
	case 105: 
	case 106: 
	case 107: 
	case 108: 
	case 109: 
	case 110: 
	case 111: 
	case 112: 
	case 113: 
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
	case 133: 
#line 283 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
	break;
	case 137: 
	case 138: 
	case 139: 
	case 140: 
	case 141: 
	case 142: 
	case 143: 
	case 144: 
	case 145: 
	case 149: 
	case 150: 
	case 151: 
	case 152: 
	case 153: 
	case 154: 
	case 155: 
	case 158: 
	case 159: 
	case 160: 
	case 161: 
	case 162: 
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
	case 177: 
	case 181: 
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
	break;
	case 186: 
	case 187: 
	case 188: 
	case 189: 
	case 190: 
	case 191: 
	case 192: 
	case 193: 
	case 197: 
	case 198: 
	case 199: 
	case 200: 
	case 201: 
	case 202: 
	case 203: 
	case 206: 
	case 207: 
	case 208: 
	case 209: 
	case 210: 
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
	case 225: 
	case 229: 
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
	break;
	case 234: 
	case 235: 
	case 236: 
	case 237: 
	case 238: 
	case 239: 
	case 240: 
	case 241: 
	case 242: 
	case 249: 
#line 311 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
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
	case 369: 
	case 370: 
	case 371: 
#line 332 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in pedigreeDB metadata"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
	break;
	case 250: 
	case 251: 
	case 252: 
	case 253: 
	case 254: 
	case 255: 
	case 256: 
	case 257: 
	case 258: 
	case 259: 
	case 299: 
#line 359 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
	break;
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
	case 428: 
	case 429: 
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
               goto _test_eof534;
goto st534;}
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
               goto _test_eof534;
goto st534;}
    }
	break;
	case 440: 
	case 459: 
	case 460: 
	case 461: 
#line 408 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new ChromosomeBodyError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
	break;
	case 441: 
	case 442: 
#line 414 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new PositionBodyError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
	break;
	case 443: 
	case 444: 
#line 420 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new IdBodyError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
	break;
	case 445: 
	case 446: 
#line 426 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new ReferenceAlleleBodyError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
	break;
	case 447: 
	case 448: 
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
#line 432 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new AlternateAllelesBodyError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
	break;
	case 449: 
	case 450: 
	case 451: 
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
#line 438 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new QualityBodyError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
	break;
	case 452: 
	case 453: 
	case 454: 
	case 470: 
	case 471: 
#line 444 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new FilterBodyError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
	break;
	case 463: 
#line 466 "src/vcf/vcf.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " is not a valid string";
        ErrorPolicy::handle_error(*this, new SamplesBodyError{n_lines, message_stream.str()});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
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
#line 29 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this,
                new FileformatError{n_lines, "The fileformat declaration is not 'fileformat=VCFv4.1'"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 60 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new FileformatError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
	break;
	case 456: 
	case 457: 
#line 50 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new FormatBodyError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
	break;
	case 537: 
	case 538: 
	case 540: 
	case 541: 
	case 542: 
	case 543: 
	case 544: 
	case 545: 
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
               goto _test_eof533;
goto st533;}
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
               goto _test_eof534;
goto st534;}
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
               goto _test_eof534;
goto st534;}
    }
	break;
	case 81: 
	case 82: 
	case 83: 
#line 264 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines,
            "ALT metadata ID is not prefixed by DEL/INS/DUP/INV/CNV/BND and suffixed by ':' and a text sequence"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 259 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
	break;
	case 104: 
#line 283 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
	break;
	case 163: 
	case 164: 
#line 305 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "INFO metadata Type is not Integer, Float, Flag, Character or String"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
	break;
	case 211: 
	case 212: 
#line 305 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "INFO metadata Type is not Integer, Float, Flag, Character or String"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
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
	case 271: 
#line 364 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "SAMPLE metadata Genomes is not a valid string (maybe it contains quotes?)"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 359 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
	break;
	case 273: 
	case 274: 
	case 275: 
	case 276: 
	case 277: 
	case 278: 
	case 279: 
	case 280: 
	case 281: 
#line 369 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "SAMPLE metadata Mixture is not a valid string (maybe it contains quotes?)"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 359 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
	break;
	case 340: 
	case 341: 
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 277 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in contig metadata"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
	break;
	case 114: 
	case 115: 
	case 116: 
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 283 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
	break;
	case 146: 
	case 147: 
	case 148: 
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
	break;
	case 194: 
	case 195: 
	case 196: 
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
	break;
	case 243: 
	case 244: 
	case 245: 
	case 246: 
	case 247: 
	case 248: 
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 311 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
	break;
	case 260: 
	case 261: 
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 359 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
	break;
	case 97: 
	case 98: 
	case 99: 
	case 101: 
	case 102: 
	case 103: 
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 259 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
	break;
	case 130: 
	case 131: 
	case 132: 
	case 134: 
	case 135: 
	case 136: 
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 283 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
	break;
	case 178: 
	case 179: 
	case 180: 
	case 182: 
	case 183: 
	case 184: 
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
	break;
	case 226: 
	case 227: 
	case 228: 
	case 230: 
	case 231: 
	case 232: 
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
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
	case 291: 
	case 292: 
	case 293: 
	case 294: 
	case 295: 
	case 296: 
	case 297: 
	case 298: 
	case 300: 
	case 301: 
	case 302: 
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 359 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
	break;
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
	case 329: 
#line 385 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata URL is not valid"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 271 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in assembly metadata"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
	break;
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
#line 385 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata URL is not valid"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 332 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in pedigreeDB metadata"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
	break;
	case 455: 
	case 464: 
	case 465: 
	case 466: 
	case 467: 
	case 468: 
#line 455 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info key is not a sequence of alphanumeric and/or punctuation characters"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 450 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
	break;
	case 469: 
#line 460 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info field value is not a comma-separated list of valid strings (maybe it contains whitespaces?)"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 450 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
	break;
	case 458: 
#line 473 "src/vcf/vcf.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " does not start with a valid genotype";
        ErrorPolicy::handle_error(*this, new SamplesFieldBodyError{n_lines, message_stream.str(), "", "GT"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 466 "src/vcf/vcf.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " is not a valid string";
        ErrorPolicy::handle_error(*this, new SamplesBodyError{n_lines, message_stream.str()});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
	break;
	case 156: 
	case 157: 
	case 185: 
#line 36 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "FORMAT metadata Number is not a number, A, G or dot"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
	break;
	case 204: 
	case 205: 
	case 233: 
#line 42 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "INFO metadata Number is not a number, A, G or dot"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
	break;
	case 22: 
#line 60 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new FileformatError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
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
               goto _test_eof534;
goto st534;}
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
               goto _test_eof534;
goto st534;}
    }
	break;
	case 272: 
#line 364 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "SAMPLE metadata Genomes is not a valid string (maybe it contains quotes?)"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 369 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "SAMPLE metadata Mixture is not a valid string (maybe it contains quotes?)"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 359 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
	break;
	case 282: 
#line 369 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "SAMPLE metadata Mixture is not a valid string (maybe it contains quotes?)"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 359 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
	break;
	case 262: 
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 364 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "SAMPLE metadata Genomes is not a valid string (maybe it contains quotes?)"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 359 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
	break;
	case 24: 
#line 259 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 283 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 271 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in assembly metadata"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 277 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in contig metadata"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 359 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 311 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 332 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in pedigreeDB metadata"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
	break;
#line 13163 "inc/vcf/validator_detail_v41.hpp"
	}
	}

	_out: {}
	}

#line 257 "src/vcf/vcf_v41.ragel"

    }
   
  }
}
