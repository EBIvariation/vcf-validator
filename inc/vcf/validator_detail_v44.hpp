
#line 1 "src/vcf/vcf_v44.ragel"
/**
 * Copyright 2014-2024 EMBL - European Bioinformatics Institute
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


#line 267 "src/vcf/vcf_v44.ragel"


namespace
{
  
#line 22 "inc/vcf/validator_detail_v44.hpp"
static const int vcf_v44_start = 1;
static const int vcf_v44_first_final = 535;
static const int vcf_v44_error = 0;

static const int vcf_v44_en_main = 1;
static const int vcf_v44_en_main_meta_section = 28;
static const int vcf_v44_en_main_body_section = 539;
static const int vcf_v44_en_meta_section_skip = 533;
static const int vcf_v44_en_body_section_skip = 534;


#line 273 "src/vcf/vcf_v44.ragel"

}

namespace ebi
{
  namespace vcf
  {

    template <typename Configuration>
    ParserImpl_v44<Configuration>::ParserImpl_v44(std::shared_ptr<Source> source, AdditionalChecks additionalChecks)
    : ParserImpl{source, additionalChecks}
    {
      
#line 44 "inc/vcf/validator_detail_v44.hpp"
	{
	cs = vcf_v44_start;
	}

#line 287 "src/vcf/vcf_v44.ragel"

    }

    template <typename Configuration>
    void ParserImpl_v44<Configuration>::parse_buffer(char const * p, char const * pe, char const * eof)
    {
      
#line 53 "inc/vcf/validator_detail_v44.hpp"
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
#line 29 "src/vcf/vcf_v44.ragel"
	{
        ErrorPolicy::handle_error(*this,
                new FileformatError{n_lines, "The fileformat declaration is not 'fileformat=VCFv4.4'"});
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
#line 338 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
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
tr40:
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st533;}
    }
	goto st0;
tr82:
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
tr90:
#line 264 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines,
               "ALT metadata ID is not prefixed by DEL/INS/DUP/INV/CNV" + (source->version < Version::v44 ? std::string("/BND") : std::string("")) + " and suffixed by ':' and a text sequence"});
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
tr97:
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
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
tr104:
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
tr113:
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
tr116:
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
tr126:
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
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
tr139:
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
tr148:
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
tr158:
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
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
tr171:
#line 36 "src/vcf/vcf_v44.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "FORMAT metadata Number is not a number, A, R, G, P or dot"});
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
tr180:
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
tr197:
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
tr213:
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
tr222:
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
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
tr235:
#line 42 "src/vcf/vcf_v44.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "INFO metadata Number is not a number, A, R, G or dot"});
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
tr244:
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
tr261:
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
tr277:
#line 338 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
        p--; {goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st533;}
    }
	goto st0;
tr286:
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {goto st533;}
    }
#line 338 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
        p--; {goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st533;}
    }
	goto st0;
tr299:
#line 343 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "META metadata Number is not a dot"});
        p--; {goto st533;}
    }
#line 338 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
        p--; {goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st533;}
    }
	goto st0;
tr307:
#line 348 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "META metadata Type is not String"});
        p--; {goto st533;}
    }
#line 338 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
        p--; {goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st533;}
    }
	goto st0;
tr324:
#line 353 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "META metadata Values is not a square-bracket delimited list of values"});
        p--; {goto st533;}
    }
#line 338 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
        p--; {goto st533;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st533;}
    }
	goto st0;
tr330:
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
tr343:
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
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
tr349:
#line 326 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "PEDIGREE metadata sequence of Name_N is not valid"});
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
tr359:
#line 321 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "PEDIGREE metadata Father or Mother is not valid"});
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
tr396:
#line 316 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "PEDIGREE metadata Original is not valid"});
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
tr401:
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
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
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
tr435:
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
tr444:
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
tr465:
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
tr476:
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
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
tr497:
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
tr509:
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
tr532:
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
tr572:
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
tr587:
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
tr590:
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
tr594:
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
tr599:
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
tr603:
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
tr612:
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
tr623:
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
tr631:
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
tr635:
#line 50 "src/vcf/vcf_v44.ragel"
	{
        ErrorPolicy::handle_error(*this, new FormatBodyError{n_lines, "Format does not start with a letter/underscore followed by alphanumeric/underscore/dot characters"});
        p--; {goto st534;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st534;}
    }
	goto st0;
tr640:
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
tr648:
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st534;}
    }
	goto st0;
tr650:
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
tr656:
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
tr714:
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
tr721:
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
#line 879 "inc/vcf/validator_detail_v44.hpp"
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
#line 985 "inc/vcf/validator_detail_v44.hpp"
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
#line 997 "inc/vcf/validator_detail_v44.hpp"
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
#line 1009 "inc/vcf/validator_detail_v44.hpp"
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
#line 1021 "inc/vcf/validator_detail_v44.hpp"
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
#line 1033 "inc/vcf/validator_detail_v44.hpp"
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
#line 1045 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 52 )
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
#line 1057 "inc/vcf/validator_detail_v44.hpp"
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
#line 1085 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 35 )
		goto st23;
	goto tr24;
st23:
	if ( ++p == pe )
		goto _test_eof23;
case 23:
	switch( (*p) ) {
		case 35: goto st24;
		case 67: goto st397;
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
case 25:
#line 1135 "inc/vcf/validator_detail_v44.hpp"
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
case 26:
#line 1149 "inc/vcf/validator_detail_v44.hpp"
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
case 27:
#line 1173 "inc/vcf/validator_detail_v44.hpp"
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
case 28:
#line 1223 "inc/vcf/validator_detail_v44.hpp"
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
case 29:
#line 1269 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 10 )
		goto st28;
	goto tr40;
st30:
	if ( ++p == pe )
		goto _test_eof30;
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
case 31:
#line 1300 "inc/vcf/validator_detail_v44.hpp"
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
case 32:
#line 1324 "inc/vcf/validator_detail_v44.hpp"
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
case 33:
#line 1346 "inc/vcf/validator_detail_v44.hpp"
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr53;
	goto tr40;
st34:
	if ( ++p == pe )
		goto _test_eof34;
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
case 36:
#line 1397 "inc/vcf/validator_detail_v44.hpp"
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
case 37:
#line 1421 "inc/vcf/validator_detail_v44.hpp"
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
case 38:
#line 1441 "inc/vcf/validator_detail_v44.hpp"
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
case 39:
#line 1453 "inc/vcf/validator_detail_v44.hpp"
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
case 40:
#line 1484 "inc/vcf/validator_detail_v44.hpp"
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
case 41:
#line 1509 "inc/vcf/validator_detail_v44.hpp"
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
case 42:
#line 1537 "inc/vcf/validator_detail_v44.hpp"
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
case 43:
#line 1556 "inc/vcf/validator_detail_v44.hpp"
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
case 45:
#line 1598 "inc/vcf/validator_detail_v44.hpp"
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
case 46:
#line 1622 "inc/vcf/validator_detail_v44.hpp"
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
case 47:
#line 1644 "inc/vcf/validator_detail_v44.hpp"
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
case 48:
#line 1659 "inc/vcf/validator_detail_v44.hpp"
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
case 49:
#line 1675 "inc/vcf/validator_detail_v44.hpp"
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
case 51:
#line 1700 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 60 )
		goto st52;
	goto tr82;
st52:
	if ( ++p == pe )
		goto _test_eof52;
case 52:
	if ( (*p) == 73 )
		goto st53;
	goto tr82;
st53:
	if ( ++p == pe )
		goto _test_eof53;
case 53:
	if ( (*p) == 68 )
		goto st54;
	goto tr82;
st54:
	if ( ++p == pe )
		goto _test_eof54;
case 54:
	if ( (*p) == 61 )
		goto st55;
	goto tr82;
st55:
	if ( ++p == pe )
		goto _test_eof55;
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
case 56:
#line 1769 "inc/vcf/validator_detail_v44.hpp"
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
case 57:
#line 1818 "inc/vcf/validator_detail_v44.hpp"
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
case 58:
#line 1837 "inc/vcf/validator_detail_v44.hpp"
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
case 59:
#line 1862 "inc/vcf/validator_detail_v44.hpp"
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
case 60:
#line 1895 "inc/vcf/validator_detail_v44.hpp"
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
case 61:
#line 1921 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 34 )
		goto st62;
	goto tr82;
st62:
	if ( ++p == pe )
		goto _test_eof62;
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
case 63:
#line 1952 "inc/vcf/validator_detail_v44.hpp"
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
case 64:
#line 1976 "inc/vcf/validator_detail_v44.hpp"
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
case 65:
#line 1990 "inc/vcf/validator_detail_v44.hpp"
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
case 66:
#line 2012 "inc/vcf/validator_detail_v44.hpp"
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
case 67:
#line 2027 "inc/vcf/validator_detail_v44.hpp"
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
case 68:
#line 2044 "inc/vcf/validator_detail_v44.hpp"
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
case 69:
#line 2060 "inc/vcf/validator_detail_v44.hpp"
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
case 70:
#line 2076 "inc/vcf/validator_detail_v44.hpp"
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
case 71:
#line 2092 "inc/vcf/validator_detail_v44.hpp"
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
case 73:
#line 2117 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 60 )
		goto st74;
	goto tr116;
st74:
	if ( ++p == pe )
		goto _test_eof74;
case 74:
	if ( (*p) == 73 )
		goto st75;
	goto tr116;
st75:
	if ( ++p == pe )
		goto _test_eof75;
case 75:
	if ( (*p) == 68 )
		goto st76;
	goto tr116;
st76:
	if ( ++p == pe )
		goto _test_eof76;
case 76:
	if ( (*p) == 61 )
		goto st77;
	goto tr116;
st77:
	if ( ++p == pe )
		goto _test_eof77;
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
case 78:
#line 2173 "inc/vcf/validator_detail_v44.hpp"
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
case 79:
#line 2209 "inc/vcf/validator_detail_v44.hpp"
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
case 80:
#line 2235 "inc/vcf/validator_detail_v44.hpp"
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
case 81:
#line 2260 "inc/vcf/validator_detail_v44.hpp"
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
case 82:
#line 2293 "inc/vcf/validator_detail_v44.hpp"
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
case 83:
#line 2319 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 34 )
		goto st84;
	goto tr116;
st84:
	if ( ++p == pe )
		goto _test_eof84;
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
case 85:
#line 2350 "inc/vcf/validator_detail_v44.hpp"
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
case 86:
#line 2374 "inc/vcf/validator_detail_v44.hpp"
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
case 87:
#line 2388 "inc/vcf/validator_detail_v44.hpp"
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
case 88:
#line 2410 "inc/vcf/validator_detail_v44.hpp"
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
case 89:
#line 2422 "inc/vcf/validator_detail_v44.hpp"
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
case 90:
#line 2438 "inc/vcf/validator_detail_v44.hpp"
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
case 91:
#line 2454 "inc/vcf/validator_detail_v44.hpp"
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
case 92:
#line 2470 "inc/vcf/validator_detail_v44.hpp"
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
case 94:
#line 2495 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 60 )
		goto st95;
	goto tr148;
st95:
	if ( ++p == pe )
		goto _test_eof95;
case 95:
	if ( (*p) == 73 )
		goto st96;
	goto tr148;
st96:
	if ( ++p == pe )
		goto _test_eof96;
case 96:
	if ( (*p) == 68 )
		goto st97;
	goto tr148;
st97:
	if ( ++p == pe )
		goto _test_eof97;
case 97:
	if ( (*p) == 61 )
		goto st98;
	goto tr148;
st98:
	if ( ++p == pe )
		goto _test_eof98;
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
case 99:
#line 2551 "inc/vcf/validator_detail_v44.hpp"
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
case 100:
#line 2587 "inc/vcf/validator_detail_v44.hpp"
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
case 101:
#line 2612 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 78 )
		goto st102;
	goto tr148;
st102:
	if ( ++p == pe )
		goto _test_eof102;
case 102:
	if ( (*p) == 117 )
		goto st103;
	goto tr148;
st103:
	if ( ++p == pe )
		goto _test_eof103;
case 103:
	if ( (*p) == 109 )
		goto st104;
	goto tr148;
st104:
	if ( ++p == pe )
		goto _test_eof104;
case 104:
	if ( (*p) == 98 )
		goto st105;
	goto tr148;
st105:
	if ( ++p == pe )
		goto _test_eof105;
case 105:
	if ( (*p) == 101 )
		goto st106;
	goto tr148;
st106:
	if ( ++p == pe )
		goto _test_eof106;
case 106:
	if ( (*p) == 114 )
		goto st107;
	goto tr148;
st107:
	if ( ++p == pe )
		goto _test_eof107;
case 107:
	if ( (*p) == 61 )
		goto st108;
	goto tr148;
st108:
	if ( ++p == pe )
		goto _test_eof108;
case 108:
	switch( (*p) ) {
		case 46: goto tr172;
		case 65: goto tr172;
		case 71: goto tr172;
		case 80: goto tr172;
		case 82: goto tr172;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr173;
	goto tr171;
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
case 109:
#line 2686 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 44 )
		goto tr174;
	goto tr171;
tr174:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st110;
st110:
	if ( ++p == pe )
		goto _test_eof110;
case 110:
#line 2698 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 84 )
		goto st111;
	goto tr148;
st111:
	if ( ++p == pe )
		goto _test_eof111;
case 111:
	if ( (*p) == 121 )
		goto st112;
	goto tr148;
st112:
	if ( ++p == pe )
		goto _test_eof112;
case 112:
	if ( (*p) == 112 )
		goto st113;
	goto tr148;
st113:
	if ( ++p == pe )
		goto _test_eof113;
case 113:
	if ( (*p) == 101 )
		goto st114;
	goto tr148;
st114:
	if ( ++p == pe )
		goto _test_eof114;
case 114:
	if ( (*p) == 61 )
		goto st115;
	goto tr148;
st115:
	if ( ++p == pe )
		goto _test_eof115;
case 115:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr181;
	} else if ( (*p) >= 65 )
		goto tr181;
	goto tr180;
tr183:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st116;
tr181:
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
case 116:
#line 2759 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 44 )
		goto tr182;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr183;
	} else if ( (*p) >= 65 )
		goto tr183;
	goto tr180;
tr182:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st117;
st117:
	if ( ++p == pe )
		goto _test_eof117;
case 117:
#line 2776 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 68 )
		goto st118;
	goto tr148;
st118:
	if ( ++p == pe )
		goto _test_eof118;
case 118:
	if ( (*p) == 101 )
		goto st119;
	goto tr148;
st119:
	if ( ++p == pe )
		goto _test_eof119;
case 119:
	if ( (*p) == 115 )
		goto st120;
	goto tr148;
st120:
	if ( ++p == pe )
		goto _test_eof120;
case 120:
	if ( (*p) == 99 )
		goto st121;
	goto tr148;
st121:
	if ( ++p == pe )
		goto _test_eof121;
case 121:
	if ( (*p) == 114 )
		goto st122;
	goto tr148;
st122:
	if ( ++p == pe )
		goto _test_eof122;
case 122:
	if ( (*p) == 105 )
		goto st123;
	goto tr148;
st123:
	if ( ++p == pe )
		goto _test_eof123;
case 123:
	if ( (*p) == 112 )
		goto st124;
	goto tr148;
st124:
	if ( ++p == pe )
		goto _test_eof124;
case 124:
	if ( (*p) == 116 )
		goto st125;
	goto tr148;
st125:
	if ( ++p == pe )
		goto _test_eof125;
case 125:
	if ( (*p) == 105 )
		goto st126;
	goto tr148;
st126:
	if ( ++p == pe )
		goto _test_eof126;
case 126:
	if ( (*p) == 111 )
		goto st127;
	goto tr148;
st127:
	if ( ++p == pe )
		goto _test_eof127;
case 127:
	if ( (*p) == 110 )
		goto st128;
	goto tr148;
st128:
	if ( ++p == pe )
		goto _test_eof128;
case 128:
	if ( (*p) == 61 )
		goto st129;
	goto tr148;
st129:
	if ( ++p == pe )
		goto _test_eof129;
case 129:
	if ( (*p) == 34 )
		goto tr196;
	goto tr148;
tr196:
#line 156 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Description");
    }
	goto st130;
st130:
	if ( ++p == pe )
		goto _test_eof130;
case 130:
#line 2872 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 34: goto tr199;
		case 92: goto tr200;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr198;
	goto tr197;
tr198:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st131;
tr201:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st131;
st131:
	if ( ++p == pe )
		goto _test_eof131;
case 131:
#line 2896 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 34: goto tr202;
		case 92: goto tr203;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr201;
	goto tr197;
tr199:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st132;
tr202:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st132;
st132:
	if ( ++p == pe )
		goto _test_eof132;
case 132:
#line 2920 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 44: goto st133;
		case 62: goto st137;
	}
	goto tr197;
st133:
	if ( ++p == pe )
		goto _test_eof133;
case 133:
	switch( (*p) ) {
		case 43: goto tr206;
		case 95: goto tr206;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr206;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr207;
		} else if ( (*p) >= 65 )
			goto tr207;
	} else
		goto tr207;
	goto tr158;
tr206:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st134;
st134:
	if ( ++p == pe )
		goto _test_eof134;
case 134:
#line 2954 "inc/vcf/validator_detail_v44.hpp"
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
				goto tr209;
		} else if ( (*p) >= 65 )
			goto tr209;
	} else
		goto tr209;
	goto tr158;
tr207:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st135;
tr209:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st135;
st135:
	if ( ++p == pe )
		goto _test_eof135;
case 135:
#line 2987 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto tr209;
		case 61: goto tr210;
		case 95: goto tr209;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr209;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr209;
		} else if ( (*p) >= 65 )
			goto tr209;
	} else
		goto tr209;
	goto tr158;
tr210:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st136;
st136:
	if ( ++p == pe )
		goto _test_eof136;
case 136:
#line 3013 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 34 )
		goto st130;
	goto tr148;
st137:
	if ( ++p == pe )
		goto _test_eof137;
case 137:
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
	}
	goto tr148;
tr200:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st138;
tr203:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st138;
st138:
	if ( ++p == pe )
		goto _test_eof138;
case 138:
#line 3042 "inc/vcf/validator_detail_v44.hpp"
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr201;
	goto tr148;
tr212:
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
case 139:
#line 3065 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 44 )
		goto tr174;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr212;
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
	goto st140;
st140:
	if ( ++p == pe )
		goto _test_eof140;
case 140:
#line 3082 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 78: goto tr214;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr213;
tr214:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st141;
st141:
	if ( ++p == pe )
		goto _test_eof141;
case 141:
#line 3098 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 70: goto tr215;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr213;
tr215:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st142;
st142:
	if ( ++p == pe )
		goto _test_eof142;
case 142:
#line 3114 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 79: goto st143;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr213;
st143:
	if ( ++p == pe )
		goto _test_eof143;
case 143:
	if ( (*p) == 61 )
		goto tr217;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr213;
tr217:
#line 128 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "INFO");
    }
	goto st144;
st144:
	if ( ++p == pe )
		goto _test_eof144;
case 144:
#line 3139 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 60 )
		goto st145;
	goto tr213;
st145:
	if ( ++p == pe )
		goto _test_eof145;
case 145:
	if ( (*p) == 73 )
		goto st146;
	goto tr213;
st146:
	if ( ++p == pe )
		goto _test_eof146;
case 146:
	if ( (*p) == 68 )
		goto st147;
	goto tr213;
st147:
	if ( ++p == pe )
		goto _test_eof147;
case 147:
	if ( (*p) == 61 )
		goto st148;
	goto tr213;
st148:
	if ( ++p == pe )
		goto _test_eof148;
case 148:
	switch( (*p) ) {
		case 43: goto tr223;
		case 95: goto tr223;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr223;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr224;
		} else if ( (*p) >= 65 )
			goto tr224;
	} else
		goto tr224;
	goto tr222;
tr223:
#line 144 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st149;
st149:
	if ( ++p == pe )
		goto _test_eof149;
case 149:
#line 3195 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto st149;
		case 95: goto st149;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st149;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr226;
		} else if ( (*p) >= 65 )
			goto tr226;
	} else
		goto tr226;
	goto tr222;
tr226:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st150;
tr224:
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
	goto st150;
st150:
	if ( ++p == pe )
		goto _test_eof150;
case 150:
#line 3231 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 44: goto tr227;
		case 95: goto tr226;
	}
	if ( (*p) < 48 ) {
		if ( 43 <= (*p) && (*p) <= 46 )
			goto tr226;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr226;
		} else if ( (*p) >= 65 )
			goto tr226;
	} else
		goto tr226;
	goto tr222;
tr227:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st151;
st151:
	if ( ++p == pe )
		goto _test_eof151;
case 151:
#line 3256 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 78 )
		goto st152;
	goto tr213;
st152:
	if ( ++p == pe )
		goto _test_eof152;
case 152:
	if ( (*p) == 117 )
		goto st153;
	goto tr213;
st153:
	if ( ++p == pe )
		goto _test_eof153;
case 153:
	if ( (*p) == 109 )
		goto st154;
	goto tr213;
st154:
	if ( ++p == pe )
		goto _test_eof154;
case 154:
	if ( (*p) == 98 )
		goto st155;
	goto tr213;
st155:
	if ( ++p == pe )
		goto _test_eof155;
case 155:
	if ( (*p) == 101 )
		goto st156;
	goto tr213;
st156:
	if ( ++p == pe )
		goto _test_eof156;
case 156:
	if ( (*p) == 114 )
		goto st157;
	goto tr213;
st157:
	if ( ++p == pe )
		goto _test_eof157;
case 157:
	if ( (*p) == 61 )
		goto st158;
	goto tr213;
st158:
	if ( ++p == pe )
		goto _test_eof158;
case 158:
	switch( (*p) ) {
		case 46: goto tr236;
		case 65: goto tr236;
		case 71: goto tr236;
		case 82: goto tr236;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr237;
	goto tr235;
tr236:
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
	goto st159;
st159:
	if ( ++p == pe )
		goto _test_eof159;
case 159:
#line 3329 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 44 )
		goto tr238;
	goto tr235;
tr238:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st160;
st160:
	if ( ++p == pe )
		goto _test_eof160;
case 160:
#line 3341 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 84 )
		goto st161;
	goto tr213;
st161:
	if ( ++p == pe )
		goto _test_eof161;
case 161:
	if ( (*p) == 121 )
		goto st162;
	goto tr213;
st162:
	if ( ++p == pe )
		goto _test_eof162;
case 162:
	if ( (*p) == 112 )
		goto st163;
	goto tr213;
st163:
	if ( ++p == pe )
		goto _test_eof163;
case 163:
	if ( (*p) == 101 )
		goto st164;
	goto tr213;
st164:
	if ( ++p == pe )
		goto _test_eof164;
case 164:
	if ( (*p) == 61 )
		goto st165;
	goto tr213;
st165:
	if ( ++p == pe )
		goto _test_eof165;
case 165:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr245;
	} else if ( (*p) >= 65 )
		goto tr245;
	goto tr244;
tr247:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st166;
tr245:
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
	goto st166;
st166:
	if ( ++p == pe )
		goto _test_eof166;
case 166:
#line 3402 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 44 )
		goto tr246;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr247;
	} else if ( (*p) >= 65 )
		goto tr247;
	goto tr244;
tr246:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st167;
st167:
	if ( ++p == pe )
		goto _test_eof167;
case 167:
#line 3419 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 68 )
		goto st168;
	goto tr213;
st168:
	if ( ++p == pe )
		goto _test_eof168;
case 168:
	if ( (*p) == 101 )
		goto st169;
	goto tr213;
st169:
	if ( ++p == pe )
		goto _test_eof169;
case 169:
	if ( (*p) == 115 )
		goto st170;
	goto tr213;
st170:
	if ( ++p == pe )
		goto _test_eof170;
case 170:
	if ( (*p) == 99 )
		goto st171;
	goto tr213;
st171:
	if ( ++p == pe )
		goto _test_eof171;
case 171:
	if ( (*p) == 114 )
		goto st172;
	goto tr213;
st172:
	if ( ++p == pe )
		goto _test_eof172;
case 172:
	if ( (*p) == 105 )
		goto st173;
	goto tr213;
st173:
	if ( ++p == pe )
		goto _test_eof173;
case 173:
	if ( (*p) == 112 )
		goto st174;
	goto tr213;
st174:
	if ( ++p == pe )
		goto _test_eof174;
case 174:
	if ( (*p) == 116 )
		goto st175;
	goto tr213;
st175:
	if ( ++p == pe )
		goto _test_eof175;
case 175:
	if ( (*p) == 105 )
		goto st176;
	goto tr213;
st176:
	if ( ++p == pe )
		goto _test_eof176;
case 176:
	if ( (*p) == 111 )
		goto st177;
	goto tr213;
st177:
	if ( ++p == pe )
		goto _test_eof177;
case 177:
	if ( (*p) == 110 )
		goto st178;
	goto tr213;
st178:
	if ( ++p == pe )
		goto _test_eof178;
case 178:
	if ( (*p) == 61 )
		goto st179;
	goto tr213;
st179:
	if ( ++p == pe )
		goto _test_eof179;
case 179:
	if ( (*p) == 34 )
		goto tr260;
	goto tr213;
tr260:
#line 156 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Description");
    }
	goto st180;
st180:
	if ( ++p == pe )
		goto _test_eof180;
case 180:
#line 3515 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 34: goto tr263;
		case 92: goto tr264;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr262;
	goto tr261;
tr262:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st181;
tr265:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st181;
st181:
	if ( ++p == pe )
		goto _test_eof181;
case 181:
#line 3539 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 34: goto tr266;
		case 92: goto tr267;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr265;
	goto tr261;
tr263:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st182;
tr266:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st182;
st182:
	if ( ++p == pe )
		goto _test_eof182;
case 182:
#line 3563 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 44: goto st183;
		case 62: goto st187;
	}
	goto tr261;
st183:
	if ( ++p == pe )
		goto _test_eof183;
case 183:
	switch( (*p) ) {
		case 43: goto tr270;
		case 95: goto tr270;
	}
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
	goto tr222;
tr270:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st184;
st184:
	if ( ++p == pe )
		goto _test_eof184;
case 184:
#line 3597 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto st184;
		case 95: goto st184;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st184;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr273;
		} else if ( (*p) >= 65 )
			goto tr273;
	} else
		goto tr273;
	goto tr222;
tr271:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st185;
tr273:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st185;
st185:
	if ( ++p == pe )
		goto _test_eof185;
case 185:
#line 3630 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto tr273;
		case 61: goto tr274;
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
	goto tr222;
tr274:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st186;
st186:
	if ( ++p == pe )
		goto _test_eof186;
case 186:
#line 3656 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 34 )
		goto st180;
	goto tr213;
st187:
	if ( ++p == pe )
		goto _test_eof187;
case 187:
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
	}
	goto tr213;
tr264:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st188;
tr267:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st188;
st188:
	if ( ++p == pe )
		goto _test_eof188;
case 188:
#line 3685 "inc/vcf/validator_detail_v44.hpp"
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr265;
	goto tr213;
tr276:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st189;
tr237:
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
	goto st189;
st189:
	if ( ++p == pe )
		goto _test_eof189;
case 189:
#line 3708 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 44 )
		goto tr238;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr276;
	goto tr235;
tr34:
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
case 190:
#line 3725 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 69: goto tr278;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr277;
tr278:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st191;
st191:
	if ( ++p == pe )
		goto _test_eof191;
case 191:
#line 3741 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 84: goto tr279;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr277;
tr279:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st192;
st192:
	if ( ++p == pe )
		goto _test_eof192;
case 192:
#line 3757 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 65: goto st193;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr277;
st193:
	if ( ++p == pe )
		goto _test_eof193;
case 193:
	if ( (*p) == 61 )
		goto tr281;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr277;
tr281:
#line 168 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "META");
    }
	goto st194;
st194:
	if ( ++p == pe )
		goto _test_eof194;
case 194:
#line 3782 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 60 )
		goto st195;
	goto tr277;
st195:
	if ( ++p == pe )
		goto _test_eof195;
case 195:
	if ( (*p) == 73 )
		goto st196;
	goto tr277;
st196:
	if ( ++p == pe )
		goto _test_eof196;
case 196:
	if ( (*p) == 68 )
		goto st197;
	goto tr277;
st197:
	if ( ++p == pe )
		goto _test_eof197;
case 197:
	if ( (*p) == 61 )
		goto st198;
	goto tr277;
st198:
	if ( ++p == pe )
		goto _test_eof198;
case 198:
	switch( (*p) ) {
		case 43: goto tr287;
		case 95: goto tr287;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr287;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr288;
		} else if ( (*p) >= 65 )
			goto tr288;
	} else
		goto tr288;
	goto tr286;
tr287:
#line 144 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st199;
st199:
	if ( ++p == pe )
		goto _test_eof199;
case 199:
#line 3838 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto st199;
		case 95: goto st199;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st199;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr290;
		} else if ( (*p) >= 65 )
			goto tr290;
	} else
		goto tr290;
	goto tr286;
tr290:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st200;
tr288:
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
	goto st200;
st200:
	if ( ++p == pe )
		goto _test_eof200;
case 200:
#line 3874 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 44: goto tr291;
		case 95: goto tr290;
	}
	if ( (*p) < 48 ) {
		if ( 43 <= (*p) && (*p) <= 46 )
			goto tr290;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr290;
		} else if ( (*p) >= 65 )
			goto tr290;
	} else
		goto tr290;
	goto tr286;
tr291:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st201;
st201:
	if ( ++p == pe )
		goto _test_eof201;
case 201:
#line 3899 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 78 )
		goto st202;
	goto tr277;
st202:
	if ( ++p == pe )
		goto _test_eof202;
case 202:
	if ( (*p) == 117 )
		goto st203;
	goto tr277;
st203:
	if ( ++p == pe )
		goto _test_eof203;
case 203:
	if ( (*p) == 109 )
		goto st204;
	goto tr277;
st204:
	if ( ++p == pe )
		goto _test_eof204;
case 204:
	if ( (*p) == 98 )
		goto st205;
	goto tr277;
st205:
	if ( ++p == pe )
		goto _test_eof205;
case 205:
	if ( (*p) == 101 )
		goto st206;
	goto tr277;
st206:
	if ( ++p == pe )
		goto _test_eof206;
case 206:
	if ( (*p) == 114 )
		goto st207;
	goto tr277;
st207:
	if ( ++p == pe )
		goto _test_eof207;
case 207:
	if ( (*p) == 61 )
		goto st208;
	goto tr277;
st208:
	if ( ++p == pe )
		goto _test_eof208;
case 208:
	if ( (*p) == 46 )
		goto tr300;
	goto tr299;
tr300:
#line 148 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Number");
    }
	goto st209;
st209:
	if ( ++p == pe )
		goto _test_eof209;
case 209:
#line 3960 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 44 )
		goto st210;
	goto tr299;
st210:
	if ( ++p == pe )
		goto _test_eof210;
case 210:
	if ( (*p) == 84 )
		goto st211;
	goto tr277;
st211:
	if ( ++p == pe )
		goto _test_eof211;
case 211:
	if ( (*p) == 121 )
		goto st212;
	goto tr277;
st212:
	if ( ++p == pe )
		goto _test_eof212;
case 212:
	if ( (*p) == 112 )
		goto st213;
	goto tr277;
st213:
	if ( ++p == pe )
		goto _test_eof213;
case 213:
	if ( (*p) == 101 )
		goto st214;
	goto tr277;
st214:
	if ( ++p == pe )
		goto _test_eof214;
case 214:
	if ( (*p) == 61 )
		goto st215;
	goto tr277;
st215:
	if ( ++p == pe )
		goto _test_eof215;
case 215:
	if ( (*p) == 83 )
		goto tr308;
	goto tr307;
tr308:
#line 152 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Type");
    }
	goto st216;
st216:
	if ( ++p == pe )
		goto _test_eof216;
case 216:
#line 4014 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 116 )
		goto st217;
	goto tr307;
st217:
	if ( ++p == pe )
		goto _test_eof217;
case 217:
	if ( (*p) == 114 )
		goto st218;
	goto tr307;
st218:
	if ( ++p == pe )
		goto _test_eof218;
case 218:
	if ( (*p) == 105 )
		goto st219;
	goto tr307;
st219:
	if ( ++p == pe )
		goto _test_eof219;
case 219:
	if ( (*p) == 110 )
		goto st220;
	goto tr307;
st220:
	if ( ++p == pe )
		goto _test_eof220;
case 220:
	if ( (*p) == 103 )
		goto st221;
	goto tr307;
st221:
	if ( ++p == pe )
		goto _test_eof221;
case 221:
	if ( (*p) == 44 )
		goto st222;
	goto tr307;
st222:
	if ( ++p == pe )
		goto _test_eof222;
case 222:
	if ( (*p) == 86 )
		goto st223;
	goto tr277;
st223:
	if ( ++p == pe )
		goto _test_eof223;
case 223:
	if ( (*p) == 97 )
		goto st224;
	goto tr277;
st224:
	if ( ++p == pe )
		goto _test_eof224;
case 224:
	if ( (*p) == 108 )
		goto st225;
	goto tr277;
st225:
	if ( ++p == pe )
		goto _test_eof225;
case 225:
	if ( (*p) == 117 )
		goto st226;
	goto tr277;
st226:
	if ( ++p == pe )
		goto _test_eof226;
case 226:
	if ( (*p) == 101 )
		goto st227;
	goto tr277;
st227:
	if ( ++p == pe )
		goto _test_eof227;
case 227:
	if ( (*p) == 115 )
		goto st228;
	goto tr277;
st228:
	if ( ++p == pe )
		goto _test_eof228;
case 228:
	if ( (*p) == 61 )
		goto st229;
	goto tr277;
st229:
	if ( ++p == pe )
		goto _test_eof229;
case 229:
	if ( (*p) == 91 )
		goto tr322;
	goto tr277;
tr322:
#line 172 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Values");
    }
	goto st230;
st230:
	if ( ++p == pe )
		goto _test_eof230;
case 230:
#line 4117 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 61 )
		goto tr323;
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr323;
	} else if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr323;
	} else
		goto tr323;
	goto tr277;
tr323:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st231;
tr325:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st231;
st231:
	if ( ++p == pe )
		goto _test_eof231;
case 231:
#line 4145 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 44: goto tr326;
		case 61: goto tr325;
		case 93: goto tr327;
	}
	if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr325;
	} else if ( (*p) >= 33 )
		goto tr325;
	goto tr324;
tr326:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st232;
st232:
	if ( ++p == pe )
		goto _test_eof232;
case 232:
#line 4165 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 32: goto tr328;
		case 61: goto tr325;
	}
	if ( (*p) < 33 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr328;
	} else if ( (*p) > 43 ) {
		if ( (*p) > 59 ) {
			if ( 63 <= (*p) && (*p) <= 126 )
				goto tr325;
		} else if ( (*p) >= 45 )
			goto tr325;
	} else
		goto tr325;
	goto tr277;
tr328:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st233;
st233:
	if ( ++p == pe )
		goto _test_eof233;
case 233:
#line 4190 "inc/vcf/validator_detail_v44.hpp"
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
	goto tr277;
tr327:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st234;
st234:
	if ( ++p == pe )
		goto _test_eof234;
case 234:
#line 4213 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 44: goto tr326;
		case 62: goto st235;
		case 93: goto tr327;
	}
	if ( (*p) > 59 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr325;
	} else if ( (*p) >= 33 )
		goto tr325;
	goto tr324;
st235:
	if ( ++p == pe )
		goto _test_eof235;
case 235:
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
	}
	goto tr277;
tr35:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st236;
st236:
	if ( ++p == pe )
		goto _test_eof236;
case 236:
#line 4245 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 69: goto tr331;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr330;
tr331:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st237;
st237:
	if ( ++p == pe )
		goto _test_eof237;
case 237:
#line 4261 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 68: goto tr332;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr330;
tr332:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st238;
st238:
	if ( ++p == pe )
		goto _test_eof238;
case 238:
#line 4277 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 73: goto tr333;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr330;
tr333:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st239;
st239:
	if ( ++p == pe )
		goto _test_eof239;
case 239:
#line 4293 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 71: goto tr334;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr330;
tr334:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st240;
st240:
	if ( ++p == pe )
		goto _test_eof240;
case 240:
#line 4309 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 82: goto tr335;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr330;
tr335:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st241;
st241:
	if ( ++p == pe )
		goto _test_eof241;
case 241:
#line 4325 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 69: goto tr336;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr330;
tr336:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st242;
st242:
	if ( ++p == pe )
		goto _test_eof242;
case 242:
#line 4341 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 69: goto st243;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr330;
st243:
	if ( ++p == pe )
		goto _test_eof243;
case 243:
	if ( (*p) == 61 )
		goto tr338;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr330;
tr338:
#line 132 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "PEDIGREE");
    }
	goto st244;
st244:
	if ( ++p == pe )
		goto _test_eof244;
case 244:
#line 4366 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 60 )
		goto st245;
	goto tr330;
st245:
	if ( ++p == pe )
		goto _test_eof245;
case 245:
	if ( (*p) == 73 )
		goto st246;
	goto tr330;
st246:
	if ( ++p == pe )
		goto _test_eof246;
case 246:
	if ( (*p) == 68 )
		goto st247;
	goto tr330;
st247:
	if ( ++p == pe )
		goto _test_eof247;
case 247:
	if ( (*p) == 61 )
		goto st248;
	goto tr330;
st248:
	if ( ++p == pe )
		goto _test_eof248;
case 248:
	switch( (*p) ) {
		case 43: goto tr344;
		case 95: goto tr344;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr344;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr345;
		} else if ( (*p) >= 65 )
			goto tr345;
	} else
		goto tr345;
	goto tr343;
tr344:
#line 144 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st249;
st249:
	if ( ++p == pe )
		goto _test_eof249;
case 249:
#line 4422 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto st249;
		case 95: goto st249;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st249;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr347;
		} else if ( (*p) >= 65 )
			goto tr347;
	} else
		goto tr347;
	goto tr343;
tr347:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st250;
tr345:
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
	goto st250;
st250:
	if ( ++p == pe )
		goto _test_eof250;
case 250:
#line 4458 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 44: goto tr348;
		case 95: goto tr347;
	}
	if ( (*p) < 48 ) {
		if ( 43 <= (*p) && (*p) <= 46 )
			goto tr347;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr347;
		} else if ( (*p) >= 65 )
			goto tr347;
	} else
		goto tr347;
	goto tr343;
tr348:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st251;
st251:
	if ( ++p == pe )
		goto _test_eof251;
case 251:
#line 4483 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 70: goto st252;
		case 78: goto tr351;
		case 79: goto st282;
	}
	goto tr349;
st252:
	if ( ++p == pe )
		goto _test_eof252;
case 252:
	if ( (*p) == 97 )
		goto st253;
	goto tr330;
st253:
	if ( ++p == pe )
		goto _test_eof253;
case 253:
	if ( (*p) == 116 )
		goto st254;
	goto tr330;
st254:
	if ( ++p == pe )
		goto _test_eof254;
case 254:
	if ( (*p) == 104 )
		goto st255;
	goto tr330;
st255:
	if ( ++p == pe )
		goto _test_eof255;
case 255:
	if ( (*p) == 101 )
		goto st256;
	goto tr330;
st256:
	if ( ++p == pe )
		goto _test_eof256;
case 256:
	if ( (*p) == 114 )
		goto st257;
	goto tr330;
st257:
	if ( ++p == pe )
		goto _test_eof257;
case 257:
	if ( (*p) == 61 )
		goto st258;
	goto tr330;
st258:
	if ( ++p == pe )
		goto _test_eof258;
case 258:
	switch( (*p) ) {
		case 43: goto tr360;
		case 95: goto tr360;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr360;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr361;
		} else if ( (*p) >= 65 )
			goto tr361;
	} else
		goto tr361;
	goto tr359;
tr360:
#line 180 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Father");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st259;
st259:
	if ( ++p == pe )
		goto _test_eof259;
case 259:
#line 4563 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto st259;
		case 95: goto st259;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st259;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr363;
		} else if ( (*p) >= 65 )
			goto tr363;
	} else
		goto tr363;
	goto tr359;
tr363:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st260;
tr361:
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
	goto st260;
st260:
	if ( ++p == pe )
		goto _test_eof260;
case 260:
#line 4599 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 44: goto tr364;
		case 95: goto tr363;
	}
	if ( (*p) < 48 ) {
		if ( 43 <= (*p) && (*p) <= 46 )
			goto tr363;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr363;
		} else if ( (*p) >= 65 )
			goto tr363;
	} else
		goto tr363;
	goto tr359;
tr364:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st261;
st261:
	if ( ++p == pe )
		goto _test_eof261;
case 261:
#line 4624 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 77 )
		goto st262;
	goto tr330;
st262:
	if ( ++p == pe )
		goto _test_eof262;
case 262:
	if ( (*p) == 111 )
		goto st263;
	goto tr330;
st263:
	if ( ++p == pe )
		goto _test_eof263;
case 263:
	if ( (*p) == 116 )
		goto st264;
	goto tr330;
st264:
	if ( ++p == pe )
		goto _test_eof264;
case 264:
	if ( (*p) == 104 )
		goto st265;
	goto tr330;
st265:
	if ( ++p == pe )
		goto _test_eof265;
case 265:
	if ( (*p) == 101 )
		goto st266;
	goto tr330;
st266:
	if ( ++p == pe )
		goto _test_eof266;
case 266:
	if ( (*p) == 114 )
		goto st267;
	goto tr330;
st267:
	if ( ++p == pe )
		goto _test_eof267;
case 267:
	if ( (*p) == 61 )
		goto st268;
	goto tr330;
st268:
	if ( ++p == pe )
		goto _test_eof268;
case 268:
	switch( (*p) ) {
		case 43: goto tr372;
		case 95: goto tr372;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr372;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr373;
		} else if ( (*p) >= 65 )
			goto tr373;
	} else
		goto tr373;
	goto tr359;
tr372:
#line 184 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Mother");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st269;
st269:
	if ( ++p == pe )
		goto _test_eof269;
case 269:
#line 4701 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto st269;
		case 95: goto st269;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st269;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr375;
		} else if ( (*p) >= 65 )
			goto tr375;
	} else
		goto tr375;
	goto tr359;
tr375:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st270;
tr373:
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
	goto st270;
st270:
	if ( ++p == pe )
		goto _test_eof270;
case 270:
#line 4737 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto tr375;
		case 62: goto tr376;
		case 95: goto tr375;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr375;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr375;
		} else if ( (*p) >= 65 )
			goto tr375;
	} else
		goto tr375;
	goto tr359;
tr376:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st271;
st271:
	if ( ++p == pe )
		goto _test_eof271;
case 271:
#line 4763 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
	}
	goto tr330;
tr351:
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
#line 4780 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 97 )
		goto tr377;
	goto tr349;
tr377:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st273;
st273:
	if ( ++p == pe )
		goto _test_eof273;
case 273:
#line 4792 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 109 )
		goto tr378;
	goto tr349;
tr378:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st274;
st274:
	if ( ++p == pe )
		goto _test_eof274;
case 274:
#line 4804 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 101 )
		goto tr379;
	goto tr349;
tr379:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st275;
st275:
	if ( ++p == pe )
		goto _test_eof275;
case 275:
#line 4816 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 95 )
		goto tr380;
	goto tr349;
tr380:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st276;
st276:
	if ( ++p == pe )
		goto _test_eof276;
case 276:
#line 4828 "inc/vcf/validator_detail_v44.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr381;
	goto tr349;
tr381:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st277;
st277:
	if ( ++p == pe )
		goto _test_eof277;
case 277:
#line 4840 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 61 )
		goto tr382;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr381;
	goto tr349;
tr382:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st278;
st278:
	if ( ++p == pe )
		goto _test_eof278;
case 278:
#line 4854 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto tr383;
		case 95: goto tr383;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr383;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr384;
		} else if ( (*p) >= 65 )
			goto tr384;
	} else
		goto tr384;
	goto tr349;
tr383:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st279;
st279:
	if ( ++p == pe )
		goto _test_eof279;
case 279:
#line 4879 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto st279;
		case 95: goto st279;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st279;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr386;
		} else if ( (*p) >= 65 )
			goto tr386;
	} else
		goto tr386;
	goto tr349;
tr384:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st280;
tr386:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st280;
st280:
	if ( ++p == pe )
		goto _test_eof280;
case 280:
#line 4912 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 44: goto tr387;
		case 62: goto tr376;
		case 95: goto tr386;
	}
	if ( (*p) < 48 ) {
		if ( 43 <= (*p) && (*p) <= 46 )
			goto tr386;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr386;
		} else if ( (*p) >= 65 )
			goto tr386;
	} else
		goto tr386;
	goto tr349;
tr387:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st281;
st281:
	if ( ++p == pe )
		goto _test_eof281;
case 281:
#line 4938 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 78 )
		goto tr351;
	goto tr349;
st282:
	if ( ++p == pe )
		goto _test_eof282;
case 282:
	if ( (*p) == 114 )
		goto st283;
	goto tr330;
st283:
	if ( ++p == pe )
		goto _test_eof283;
case 283:
	if ( (*p) == 105 )
		goto st284;
	goto tr330;
st284:
	if ( ++p == pe )
		goto _test_eof284;
case 284:
	if ( (*p) == 103 )
		goto st285;
	goto tr330;
st285:
	if ( ++p == pe )
		goto _test_eof285;
case 285:
	if ( (*p) == 105 )
		goto st286;
	goto tr330;
st286:
	if ( ++p == pe )
		goto _test_eof286;
case 286:
	if ( (*p) == 110 )
		goto st287;
	goto tr330;
st287:
	if ( ++p == pe )
		goto _test_eof287;
case 287:
	if ( (*p) == 97 )
		goto st288;
	goto tr330;
st288:
	if ( ++p == pe )
		goto _test_eof288;
case 288:
	if ( (*p) == 108 )
		goto st289;
	goto tr330;
st289:
	if ( ++p == pe )
		goto _test_eof289;
case 289:
	if ( (*p) == 61 )
		goto st290;
	goto tr330;
st290:
	if ( ++p == pe )
		goto _test_eof290;
case 290:
	switch( (*p) ) {
		case 43: goto tr397;
		case 95: goto tr397;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr397;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr398;
		} else if ( (*p) >= 65 )
			goto tr398;
	} else
		goto tr398;
	goto tr396;
tr397:
#line 176 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Original");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st291;
st291:
	if ( ++p == pe )
		goto _test_eof291;
case 291:
#line 5029 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto st291;
		case 95: goto st291;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st291;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr400;
		} else if ( (*p) >= 65 )
			goto tr400;
	} else
		goto tr400;
	goto tr396;
tr400:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st292;
tr398:
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
	goto st292;
st292:
	if ( ++p == pe )
		goto _test_eof292;
case 292:
#line 5065 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto tr400;
		case 62: goto tr376;
		case 95: goto tr400;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr400;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr400;
		} else if ( (*p) >= 65 )
			goto tr400;
	} else
		goto tr400;
	goto tr396;
tr36:
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
case 293:
#line 5094 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 65: goto tr402;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr401;
tr402:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st294;
st294:
	if ( ++p == pe )
		goto _test_eof294;
case 294:
#line 5110 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 77: goto tr403;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr401;
tr403:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st295;
st295:
	if ( ++p == pe )
		goto _test_eof295;
case 295:
#line 5126 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 80: goto tr404;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr401;
tr404:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st296;
st296:
	if ( ++p == pe )
		goto _test_eof296;
case 296:
#line 5142 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 76: goto tr405;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr401;
tr405:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st297;
st297:
	if ( ++p == pe )
		goto _test_eof297;
case 297:
#line 5158 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 69: goto st298;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr401;
st298:
	if ( ++p == pe )
		goto _test_eof298;
case 298:
	if ( (*p) == 61 )
		goto tr407;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr401;
tr407:
#line 140 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "SAMPLE");
    }
	goto st299;
st299:
	if ( ++p == pe )
		goto _test_eof299;
case 299:
#line 5183 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 60 )
		goto st300;
	goto tr401;
st300:
	if ( ++p == pe )
		goto _test_eof300;
case 300:
	if ( (*p) == 73 )
		goto st301;
	goto tr401;
st301:
	if ( ++p == pe )
		goto _test_eof301;
case 301:
	if ( (*p) == 68 )
		goto st302;
	goto tr401;
st302:
	if ( ++p == pe )
		goto _test_eof302;
case 302:
	if ( (*p) == 61 )
		goto st303;
	goto tr401;
st303:
	if ( ++p == pe )
		goto _test_eof303;
case 303:
	switch( (*p) ) {
		case 43: goto tr413;
		case 95: goto tr413;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr413;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr414;
		} else if ( (*p) >= 65 )
			goto tr414;
	} else
		goto tr414;
	goto tr412;
tr413:
#line 144 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st304;
st304:
	if ( ++p == pe )
		goto _test_eof304;
case 304:
#line 5239 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto st304;
		case 95: goto st304;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st304;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr416;
		} else if ( (*p) >= 65 )
			goto tr416;
	} else
		goto tr416;
	goto tr412;
tr416:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st305;
tr414:
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
	goto st305;
st305:
	if ( ++p == pe )
		goto _test_eof305;
case 305:
#line 5275 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 44: goto tr417;
		case 62: goto tr418;
		case 95: goto tr416;
	}
	if ( (*p) < 48 ) {
		if ( 43 <= (*p) && (*p) <= 46 )
			goto tr416;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr416;
		} else if ( (*p) >= 65 )
			goto tr416;
	} else
		goto tr416;
	goto tr412;
tr417:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st306;
st306:
	if ( ++p == pe )
		goto _test_eof306;
case 306:
#line 5301 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto tr419;
		case 95: goto tr419;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr419;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr420;
		} else if ( (*p) >= 65 )
			goto tr420;
	} else
		goto tr420;
	goto tr401;
tr419:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st307;
st307:
	if ( ++p == pe )
		goto _test_eof307;
case 307:
#line 5326 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto st307;
		case 95: goto st307;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st307;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr422;
		} else if ( (*p) >= 65 )
			goto tr422;
	} else
		goto tr422;
	goto tr401;
tr420:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st308;
tr422:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st308;
st308:
	if ( ++p == pe )
		goto _test_eof308;
case 308:
#line 5359 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto tr422;
		case 61: goto tr423;
		case 95: goto tr422;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr422;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr422;
		} else if ( (*p) >= 65 )
			goto tr422;
	} else
		goto tr422;
	goto tr401;
tr423:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st309;
st309:
	if ( ++p == pe )
		goto _test_eof309;
case 309:
#line 5385 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 34 )
		goto st312;
	if ( (*p) < 45 ) {
		if ( 32 <= (*p) && (*p) <= 43 )
			goto tr424;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr424;
	} else
		goto tr424;
	goto tr401;
tr424:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st310;
tr426:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st310;
st310:
	if ( ++p == pe )
		goto _test_eof310;
case 310:
#line 5413 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 44: goto tr417;
		case 62: goto tr418;
	}
	if ( (*p) > 33 ) {
		if ( 35 <= (*p) && (*p) <= 126 )
			goto tr426;
	} else if ( (*p) >= 32 )
		goto tr426;
	goto tr401;
tr418:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st311;
st311:
	if ( ++p == pe )
		goto _test_eof311;
case 311:
#line 5432 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
	}
	goto tr401;
st312:
	if ( ++p == pe )
		goto _test_eof312;
case 312:
	switch( (*p) ) {
		case 34: goto tr428;
		case 92: goto tr429;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr427;
	goto tr401;
tr427:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st313;
tr430:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st313;
st313:
	if ( ++p == pe )
		goto _test_eof313;
case 313:
#line 5465 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 34: goto tr431;
		case 92: goto tr432;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr430;
	goto tr401;
tr428:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st314;
tr431:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st314;
st314:
	if ( ++p == pe )
		goto _test_eof314;
case 314:
#line 5489 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 44: goto st306;
		case 62: goto st311;
	}
	goto tr401;
tr429:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st315;
tr432:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st315;
st315:
	if ( ++p == pe )
		goto _test_eof315;
case 315:
#line 5511 "inc/vcf/validator_detail_v44.hpp"
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr430;
	goto tr401;
tr37:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st316;
st316:
	if ( ++p == pe )
		goto _test_eof316;
case 316:
#line 5526 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 115: goto tr436;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr435;
tr436:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st317;
st317:
	if ( ++p == pe )
		goto _test_eof317;
case 317:
#line 5542 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 115: goto tr437;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr435;
tr437:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st318;
st318:
	if ( ++p == pe )
		goto _test_eof318;
case 318:
#line 5558 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 101: goto tr438;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr435;
tr438:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st319;
st319:
	if ( ++p == pe )
		goto _test_eof319;
case 319:
#line 5574 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 109: goto tr439;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr435;
tr439:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st320;
st320:
	if ( ++p == pe )
		goto _test_eof320;
case 320:
#line 5590 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 98: goto tr440;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr435;
tr440:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st321;
st321:
	if ( ++p == pe )
		goto _test_eof321;
case 321:
#line 5606 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 108: goto tr441;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr435;
tr441:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st322;
st322:
	if ( ++p == pe )
		goto _test_eof322;
case 322:
#line 5622 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 121: goto st323;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr435;
st323:
	if ( ++p == pe )
		goto _test_eof323;
case 323:
	if ( (*p) == 61 )
		goto tr443;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr435;
tr443:
#line 112 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "assembly");
    }
	goto st324;
st324:
	if ( ++p == pe )
		goto _test_eof324;
case 324:
#line 5647 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr445;
	} else if ( (*p) >= 65 )
		goto tr445;
	goto tr444;
tr445:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st325;
st325:
	if ( ++p == pe )
		goto _test_eof325;
case 325:
#line 5662 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 10: goto tr444;
		case 13: goto tr447;
		case 35: goto tr444;
		case 47: goto tr444;
		case 58: goto tr444;
		case 63: goto tr444;
	}
	goto st326;
tr447:
#line 43 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st326;
st326:
	if ( ++p == pe )
		goto _test_eof326;
case 326:
#line 5686 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 10: goto tr444;
		case 13: goto tr447;
		case 35: goto tr444;
		case 47: goto tr444;
		case 58: goto st327;
		case 63: goto tr444;
	}
	goto st326;
st327:
	if ( ++p == pe )
		goto _test_eof327;
case 327:
	if ( (*p) == 47 )
		goto st328;
	goto tr444;
st328:
	if ( ++p == pe )
		goto _test_eof328;
case 328:
	if ( (*p) == 47 )
		goto st329;
	goto tr444;
st329:
	if ( ++p == pe )
		goto _test_eof329;
case 329:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st330;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr452;
	} else
		goto tr452;
	goto tr444;
st330:
	if ( ++p == pe )
		goto _test_eof330;
case 330:
	if ( (*p) == 46 )
		goto st331;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st341;
	goto tr444;
st331:
	if ( ++p == pe )
		goto _test_eof331;
case 331:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st332;
	goto tr444;
st332:
	if ( ++p == pe )
		goto _test_eof332;
case 332:
	if ( (*p) == 46 )
		goto st333;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st339;
	goto tr444;
st333:
	if ( ++p == pe )
		goto _test_eof333;
case 333:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st334;
	goto tr444;
st334:
	if ( ++p == pe )
		goto _test_eof334;
case 334:
	if ( (*p) == 46 )
		goto st335;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st337;
	goto tr444;
st335:
	if ( ++p == pe )
		goto _test_eof335;
case 335:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr452;
	goto tr444;
tr452:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st336;
tr461:
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
	goto st336;
st336:
	if ( ++p == pe )
		goto _test_eof336;
case 336:
#line 5803 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 10: goto tr46;
		case 13: goto tr461;
	}
	goto tr452;
st337:
	if ( ++p == pe )
		goto _test_eof337;
case 337:
	if ( (*p) == 46 )
		goto st335;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st338;
	goto tr444;
st338:
	if ( ++p == pe )
		goto _test_eof338;
case 338:
	if ( (*p) == 46 )
		goto st335;
	goto tr444;
st339:
	if ( ++p == pe )
		goto _test_eof339;
case 339:
	if ( (*p) == 46 )
		goto st333;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st340;
	goto tr444;
st340:
	if ( ++p == pe )
		goto _test_eof340;
case 340:
	if ( (*p) == 46 )
		goto st333;
	goto tr444;
st341:
	if ( ++p == pe )
		goto _test_eof341;
case 341:
	if ( (*p) == 46 )
		goto st331;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st342;
	goto tr444;
st342:
	if ( ++p == pe )
		goto _test_eof342;
case 342:
	if ( (*p) == 46 )
		goto st331;
	goto tr444;
tr38:
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
case 343:
#line 5868 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 111: goto tr466;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr465;
tr466:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st344;
st344:
	if ( ++p == pe )
		goto _test_eof344;
case 344:
#line 5884 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 110: goto tr467;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr465;
tr467:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st345;
st345:
	if ( ++p == pe )
		goto _test_eof345;
case 345:
#line 5900 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 116: goto tr468;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr465;
tr468:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st346;
st346:
	if ( ++p == pe )
		goto _test_eof346;
case 346:
#line 5916 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 105: goto tr469;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr465;
tr469:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st347;
st347:
	if ( ++p == pe )
		goto _test_eof347;
case 347:
#line 5932 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 103: goto st348;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr465;
st348:
	if ( ++p == pe )
		goto _test_eof348;
case 348:
	if ( (*p) == 61 )
		goto tr471;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr465;
tr471:
#line 116 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "contig");
    }
	goto st349;
st349:
	if ( ++p == pe )
		goto _test_eof349;
case 349:
#line 5957 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 60 )
		goto st350;
	goto tr465;
st350:
	if ( ++p == pe )
		goto _test_eof350;
case 350:
	if ( (*p) == 73 )
		goto st351;
	goto tr465;
st351:
	if ( ++p == pe )
		goto _test_eof351;
case 351:
	if ( (*p) == 68 )
		goto st352;
	goto tr465;
st352:
	if ( ++p == pe )
		goto _test_eof352;
case 352:
	if ( (*p) == 61 )
		goto st353;
	goto tr465;
st353:
	if ( ++p == pe )
		goto _test_eof353;
case 353:
	switch( (*p) ) {
		case 43: goto tr477;
		case 92: goto tr477;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr477;
		} else if ( (*p) >= 33 )
			goto tr477;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr477;
		} else if ( (*p) >= 63 )
			goto tr477;
	} else
		goto tr477;
	goto tr476;
tr478:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st354;
tr477:
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
	goto st354;
st354:
	if ( ++p == pe )
		goto _test_eof354;
case 354:
#line 6024 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 44: goto tr479;
		case 62: goto tr480;
		case 92: goto tr478;
	}
	if ( (*p) < 43 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr478;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr478;
		} else if ( (*p) >= 63 )
			goto tr478;
	} else
		goto tr478;
	goto tr476;
tr479:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st355;
st355:
	if ( ++p == pe )
		goto _test_eof355;
case 355:
#line 6050 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto tr481;
		case 95: goto tr481;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr481;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr482;
		} else if ( (*p) >= 65 )
			goto tr482;
	} else
		goto tr482;
	goto tr465;
tr481:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st356;
st356:
	if ( ++p == pe )
		goto _test_eof356;
case 356:
#line 6075 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto st356;
		case 95: goto st356;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st356;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr484;
		} else if ( (*p) >= 65 )
			goto tr484;
	} else
		goto tr484;
	goto tr465;
tr482:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st357;
tr484:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st357;
st357:
	if ( ++p == pe )
		goto _test_eof357;
case 357:
#line 6108 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto tr484;
		case 61: goto tr485;
		case 95: goto tr484;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr484;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr484;
		} else if ( (*p) >= 65 )
			goto tr484;
	} else
		goto tr484;
	goto tr465;
tr485:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st358;
st358:
	if ( ++p == pe )
		goto _test_eof358;
case 358:
#line 6134 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 34 )
		goto st361;
	if ( (*p) < 45 ) {
		if ( 32 <= (*p) && (*p) <= 43 )
			goto tr486;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr486;
	} else
		goto tr486;
	goto tr465;
tr486:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st359;
tr488:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st359;
st359:
	if ( ++p == pe )
		goto _test_eof359;
case 359:
#line 6162 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 44: goto tr479;
		case 62: goto tr480;
	}
	if ( (*p) > 33 ) {
		if ( 35 <= (*p) && (*p) <= 126 )
			goto tr488;
	} else if ( (*p) >= 32 )
		goto tr488;
	goto tr465;
tr480:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st360;
st360:
	if ( ++p == pe )
		goto _test_eof360;
case 360:
#line 6181 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
	}
	goto tr465;
st361:
	if ( ++p == pe )
		goto _test_eof361;
case 361:
	switch( (*p) ) {
		case 34: goto tr490;
		case 92: goto tr491;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr489;
	goto tr465;
tr489:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st362;
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
#line 6214 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 34: goto tr493;
		case 92: goto tr494;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr492;
	goto tr465;
tr490:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st363;
tr493:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st363;
st363:
	if ( ++p == pe )
		goto _test_eof363;
case 363:
#line 6238 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 44: goto st355;
		case 62: goto st360;
	}
	goto tr465;
tr491:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st364;
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
#line 6260 "inc/vcf/validator_detail_v44.hpp"
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr492;
	goto tr465;
tr39:
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
case 365:
#line 6275 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 101: goto tr498;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr497;
tr498:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st366;
st366:
	if ( ++p == pe )
		goto _test_eof366;
case 366:
#line 6291 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 100: goto tr499;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr497;
tr499:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st367;
st367:
	if ( ++p == pe )
		goto _test_eof367;
case 367:
#line 6307 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 105: goto tr500;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr497;
tr500:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st368;
st368:
	if ( ++p == pe )
		goto _test_eof368;
case 368:
#line 6323 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 103: goto tr501;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr497;
tr501:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st369;
st369:
	if ( ++p == pe )
		goto _test_eof369;
case 369:
#line 6339 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 114: goto tr502;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr497;
tr502:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st370;
st370:
	if ( ++p == pe )
		goto _test_eof370;
case 370:
#line 6355 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 101: goto tr503;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr497;
tr503:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st371;
st371:
	if ( ++p == pe )
		goto _test_eof371;
case 371:
#line 6371 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 101: goto tr504;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr497;
tr504:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st372;
st372:
	if ( ++p == pe )
		goto _test_eof372;
case 372:
#line 6387 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 68: goto tr505;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr497;
tr505:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st373;
st373:
	if ( ++p == pe )
		goto _test_eof373;
case 373:
#line 6403 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 66: goto st374;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr497;
st374:
	if ( ++p == pe )
		goto _test_eof374;
case 374:
	if ( (*p) == 61 )
		goto tr507;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr497;
tr507:
#line 136 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "pedigreeDB");
    }
	goto st375;
st375:
	if ( ++p == pe )
		goto _test_eof375;
case 375:
#line 6428 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 60 )
		goto st376;
	goto tr497;
st376:
	if ( ++p == pe )
		goto _test_eof376;
case 376:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr510;
	} else if ( (*p) >= 65 )
		goto tr510;
	goto tr509;
tr510:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st377;
st377:
	if ( ++p == pe )
		goto _test_eof377;
case 377:
#line 6450 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 10: goto tr509;
		case 13: goto tr512;
		case 35: goto tr509;
		case 47: goto tr509;
		case 58: goto tr509;
		case 63: goto tr509;
	}
	goto st378;
tr512:
#line 43 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st378;
st378:
	if ( ++p == pe )
		goto _test_eof378;
case 378:
#line 6474 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 10: goto tr509;
		case 13: goto tr512;
		case 35: goto tr509;
		case 47: goto tr509;
		case 58: goto st379;
		case 63: goto tr509;
	}
	goto st378;
st379:
	if ( ++p == pe )
		goto _test_eof379;
case 379:
	if ( (*p) == 47 )
		goto st380;
	goto tr509;
st380:
	if ( ++p == pe )
		goto _test_eof380;
case 380:
	if ( (*p) == 47 )
		goto st381;
	goto tr509;
st381:
	if ( ++p == pe )
		goto _test_eof381;
case 381:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st382;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr517;
	} else
		goto tr517;
	goto tr509;
st382:
	if ( ++p == pe )
		goto _test_eof382;
case 382:
	if ( (*p) == 46 )
		goto st383;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st395;
	goto tr509;
st383:
	if ( ++p == pe )
		goto _test_eof383;
case 383:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st384;
	goto tr509;
st384:
	if ( ++p == pe )
		goto _test_eof384;
case 384:
	if ( (*p) == 46 )
		goto st385;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st393;
	goto tr509;
st385:
	if ( ++p == pe )
		goto _test_eof385;
case 385:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st386;
	goto tr509;
st386:
	if ( ++p == pe )
		goto _test_eof386;
case 386:
	if ( (*p) == 46 )
		goto st387;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st391;
	goto tr509;
st387:
	if ( ++p == pe )
		goto _test_eof387;
case 387:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr517;
	goto tr509;
tr517:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st388;
tr526:
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
	goto st388;
st388:
	if ( ++p == pe )
		goto _test_eof388;
case 388:
#line 6581 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 10: goto tr509;
		case 13: goto tr526;
		case 62: goto tr527;
	}
	goto tr517;
tr527:
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
case 389:
#line 6599 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr528;
		case 62: goto tr527;
	}
	goto tr517;
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
#line 196 "src/vcf/vcf.ragel"
	{
        try {
          ParsePolicy::handle_meta_line(*this);
        } catch (Error *error) {
          ErrorPolicy::handle_error(*this, error);
        }
    }
	goto st390;
st390:
	if ( ++p == pe )
		goto _test_eof390;
case 390:
#line 6630 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 10: goto st28;
		case 13: goto tr526;
		case 62: goto tr527;
	}
	goto tr517;
st391:
	if ( ++p == pe )
		goto _test_eof391;
case 391:
	if ( (*p) == 46 )
		goto st387;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st392;
	goto tr509;
st392:
	if ( ++p == pe )
		goto _test_eof392;
case 392:
	if ( (*p) == 46 )
		goto st387;
	goto tr509;
st393:
	if ( ++p == pe )
		goto _test_eof393;
case 393:
	if ( (*p) == 46 )
		goto st385;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st394;
	goto tr509;
st394:
	if ( ++p == pe )
		goto _test_eof394;
case 394:
	if ( (*p) == 46 )
		goto st385;
	goto tr509;
st395:
	if ( ++p == pe )
		goto _test_eof395;
case 395:
	if ( (*p) == 46 )
		goto st383;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st396;
	goto tr509;
st396:
	if ( ++p == pe )
		goto _test_eof396;
case 396:
	if ( (*p) == 46 )
		goto st383;
	goto tr509;
st397:
	if ( ++p == pe )
		goto _test_eof397;
case 397:
	if ( (*p) == 72 )
		goto st398;
	goto tr532;
st398:
	if ( ++p == pe )
		goto _test_eof398;
case 398:
	if ( (*p) == 82 )
		goto st399;
	goto tr532;
st399:
	if ( ++p == pe )
		goto _test_eof399;
case 399:
	if ( (*p) == 79 )
		goto st400;
	goto tr532;
st400:
	if ( ++p == pe )
		goto _test_eof400;
case 400:
	if ( (*p) == 77 )
		goto st401;
	goto tr532;
st401:
	if ( ++p == pe )
		goto _test_eof401;
case 401:
	if ( (*p) == 9 )
		goto tr537;
	goto tr532;
tr537:
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st402;
st402:
	if ( ++p == pe )
		goto _test_eof402;
case 402:
#line 6728 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 80 )
		goto st403;
	goto tr532;
st403:
	if ( ++p == pe )
		goto _test_eof403;
case 403:
	if ( (*p) == 79 )
		goto st404;
	goto tr532;
st404:
	if ( ++p == pe )
		goto _test_eof404;
case 404:
	if ( (*p) == 83 )
		goto st405;
	goto tr532;
st405:
	if ( ++p == pe )
		goto _test_eof405;
case 405:
	if ( (*p) == 9 )
		goto tr541;
	goto tr532;
tr541:
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st406;
st406:
	if ( ++p == pe )
		goto _test_eof406;
case 406:
#line 6761 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 73 )
		goto st407;
	goto tr532;
st407:
	if ( ++p == pe )
		goto _test_eof407;
case 407:
	if ( (*p) == 68 )
		goto st408;
	goto tr532;
st408:
	if ( ++p == pe )
		goto _test_eof408;
case 408:
	if ( (*p) == 9 )
		goto tr544;
	goto tr532;
tr544:
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st409;
st409:
	if ( ++p == pe )
		goto _test_eof409;
case 409:
#line 6787 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 82 )
		goto st410;
	goto tr532;
st410:
	if ( ++p == pe )
		goto _test_eof410;
case 410:
	if ( (*p) == 69 )
		goto st411;
	goto tr532;
st411:
	if ( ++p == pe )
		goto _test_eof411;
case 411:
	if ( (*p) == 70 )
		goto st412;
	goto tr532;
st412:
	if ( ++p == pe )
		goto _test_eof412;
case 412:
	if ( (*p) == 9 )
		goto tr548;
	goto tr532;
tr548:
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st413;
st413:
	if ( ++p == pe )
		goto _test_eof413;
case 413:
#line 6820 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 65 )
		goto st414;
	goto tr532;
st414:
	if ( ++p == pe )
		goto _test_eof414;
case 414:
	if ( (*p) == 76 )
		goto st415;
	goto tr532;
st415:
	if ( ++p == pe )
		goto _test_eof415;
case 415:
	if ( (*p) == 84 )
		goto st416;
	goto tr532;
st416:
	if ( ++p == pe )
		goto _test_eof416;
case 416:
	if ( (*p) == 9 )
		goto tr552;
	goto tr532;
tr552:
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st417;
st417:
	if ( ++p == pe )
		goto _test_eof417;
case 417:
#line 6853 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 81 )
		goto st418;
	goto tr532;
st418:
	if ( ++p == pe )
		goto _test_eof418;
case 418:
	if ( (*p) == 85 )
		goto st419;
	goto tr532;
st419:
	if ( ++p == pe )
		goto _test_eof419;
case 419:
	if ( (*p) == 65 )
		goto st420;
	goto tr532;
st420:
	if ( ++p == pe )
		goto _test_eof420;
case 420:
	if ( (*p) == 76 )
		goto st421;
	goto tr532;
st421:
	if ( ++p == pe )
		goto _test_eof421;
case 421:
	if ( (*p) == 9 )
		goto tr557;
	goto tr532;
tr557:
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st422;
st422:
	if ( ++p == pe )
		goto _test_eof422;
case 422:
#line 6893 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 70 )
		goto st423;
	goto tr532;
st423:
	if ( ++p == pe )
		goto _test_eof423;
case 423:
	if ( (*p) == 73 )
		goto st424;
	goto tr532;
st424:
	if ( ++p == pe )
		goto _test_eof424;
case 424:
	if ( (*p) == 76 )
		goto st425;
	goto tr532;
st425:
	if ( ++p == pe )
		goto _test_eof425;
case 425:
	if ( (*p) == 84 )
		goto st426;
	goto tr532;
st426:
	if ( ++p == pe )
		goto _test_eof426;
case 426:
	if ( (*p) == 69 )
		goto st427;
	goto tr532;
st427:
	if ( ++p == pe )
		goto _test_eof427;
case 427:
	if ( (*p) == 82 )
		goto st428;
	goto tr532;
st428:
	if ( ++p == pe )
		goto _test_eof428;
case 428:
	if ( (*p) == 9 )
		goto tr564;
	goto tr532;
tr564:
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st429;
st429:
	if ( ++p == pe )
		goto _test_eof429;
case 429:
#line 6947 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 73 )
		goto st430;
	goto tr532;
st430:
	if ( ++p == pe )
		goto _test_eof430;
case 430:
	if ( (*p) == 78 )
		goto st431;
	goto tr532;
st431:
	if ( ++p == pe )
		goto _test_eof431;
case 431:
	if ( (*p) == 70 )
		goto st432;
	goto tr532;
st432:
	if ( ++p == pe )
		goto _test_eof432;
case 432:
	if ( (*p) == 79 )
		goto st433;
	goto tr532;
st433:
	if ( ++p == pe )
		goto _test_eof433;
case 433:
	switch( (*p) ) {
		case 9: goto tr569;
		case 10: goto tr570;
		case 13: goto tr571;
	}
	goto tr532;
tr569:
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st434;
st434:
	if ( ++p == pe )
		goto _test_eof434;
case 434:
#line 6990 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 70 )
		goto st435;
	goto tr572;
st435:
	if ( ++p == pe )
		goto _test_eof435;
case 435:
	if ( (*p) == 79 )
		goto st436;
	goto tr572;
st436:
	if ( ++p == pe )
		goto _test_eof436;
case 436:
	if ( (*p) == 82 )
		goto st437;
	goto tr572;
st437:
	if ( ++p == pe )
		goto _test_eof437;
case 437:
	if ( (*p) == 77 )
		goto st438;
	goto tr572;
st438:
	if ( ++p == pe )
		goto _test_eof438;
case 438:
	if ( (*p) == 65 )
		goto st439;
	goto tr572;
st439:
	if ( ++p == pe )
		goto _test_eof439;
case 439:
	if ( (*p) == 84 )
		goto st440;
	goto tr572;
st440:
	if ( ++p == pe )
		goto _test_eof440;
case 440:
	if ( (*p) == 9 )
		goto tr579;
	goto tr572;
tr579:
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st441;
tr581:
#line 204 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_sample_name(*this);
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
#line 7052 "inc/vcf/validator_detail_v44.hpp"
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr580;
	goto tr572;
tr580:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st442;
tr584:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st442;
st442:
	if ( ++p == pe )
		goto _test_eof442;
case 442:
#line 7072 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 9: goto tr581;
		case 10: goto tr582;
		case 13: goto tr583;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr584;
	goto tr572;
tr570:
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
tr582:
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
#line 7123 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 10: goto tr715;
		case 13: goto tr716;
		case 43: goto tr717;
		case 60: goto tr718;
		case 92: goto tr717;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr717;
		} else if ( (*p) >= 33 )
			goto tr717;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr717;
		} else if ( (*p) >= 63 )
			goto tr717;
	} else
		goto tr717;
	goto tr714;
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
	goto st536;
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
	goto st536;
st536:
	if ( ++p == pe )
		goto _test_eof536;
case 536:
#line 7178 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 10: goto tr719;
		case 13: goto tr720;
	}
	goto st0;
tr720:
#line 43 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st443;
tr716:
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
	goto st443;
st443:
	if ( ++p == pe )
		goto _test_eof443;
case 443:
#line 7216 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 10 )
		goto st536;
	goto st0;
tr726:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st444;
tr589:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st444;
tr717:
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
	goto st444;
st444:
	if ( ++p == pe )
		goto _test_eof444;
case 444:
#line 7251 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 9: goto tr588;
		case 43: goto tr589;
		case 92: goto tr589;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr589;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr589;
		} else if ( (*p) >= 63 )
			goto tr589;
	} else
		goto tr589;
	goto tr587;
tr588:
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
tr647:
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
#line 7291 "inc/vcf/validator_detail_v44.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr591;
	goto tr590;
tr591:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st446;
tr593:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st446;
st446:
	if ( ++p == pe )
		goto _test_eof446;
case 446:
#line 7311 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 9 )
		goto tr592;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr593;
	goto tr590;
tr598:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st447;
tr592:
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
#line 7336 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr595;
	} else if ( (*p) >= 33 )
		goto tr595;
	goto tr594;
tr595:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st448;
tr597:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st448;
st448:
	if ( ++p == pe )
		goto _test_eof448;
case 448:
#line 7359 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 9: goto tr596;
		case 59: goto tr598;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr597;
	goto tr594;
tr596:
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
#line 7381 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 65: goto tr600;
		case 67: goto tr600;
		case 71: goto tr600;
		case 78: goto tr600;
		case 84: goto tr600;
		case 97: goto tr600;
		case 99: goto tr600;
		case 103: goto tr600;
		case 110: goto tr600;
		case 116: goto tr600;
	}
	goto tr599;
tr600:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st450;
tr602:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st450;
st450:
	if ( ++p == pe )
		goto _test_eof450;
case 450:
#line 7411 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 9: goto tr601;
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
	goto tr599;
tr601:
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
	goto st451;
st451:
	if ( ++p == pe )
		goto _test_eof451;
case 451:
#line 7440 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 42: goto tr604;
		case 46: goto tr605;
		case 60: goto tr606;
		case 65: goto tr607;
		case 67: goto tr607;
		case 71: goto tr607;
		case 78: goto tr607;
		case 84: goto tr607;
		case 91: goto tr608;
		case 93: goto tr609;
		case 97: goto tr607;
		case 99: goto tr607;
		case 103: goto tr607;
		case 110: goto tr607;
		case 116: goto tr607;
	}
	goto tr603;
tr604:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st452;
tr669:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st452;
st452:
	if ( ++p == pe )
		goto _test_eof452;
case 452:
#line 7475 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 9: goto tr610;
		case 44: goto tr611;
	}
	goto tr603;
tr610:
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
	goto st453;
st453:
	if ( ++p == pe )
		goto _test_eof453;
case 453:
#line 7495 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto tr613;
		case 45: goto tr613;
		case 46: goto tr614;
		case 73: goto tr616;
		case 78: goto tr617;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr615;
	goto tr612;
tr613:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st454;
st454:
	if ( ++p == pe )
		goto _test_eof454;
case 454:
#line 7517 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 73 )
		goto tr619;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr618;
	goto tr612;
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
tr618:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st455;
st455:
	if ( ++p == pe )
		goto _test_eof455;
case 455:
#line 7539 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 9: goto tr620;
		case 46: goto tr621;
		case 69: goto tr622;
		case 101: goto tr622;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr618;
	goto tr612;
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
	goto st456;
st456:
	if ( ++p == pe )
		goto _test_eof456;
case 456:
#line 7563 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 46: goto tr625;
		case 58: goto tr624;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr624;
		} else if ( (*p) > 57 ) {
			if ( 60 <= (*p) && (*p) <= 64 )
				goto tr624;
		} else
			goto tr626;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr624;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr624;
		} else
			goto tr626;
	} else
		goto tr626;
	goto tr623;
tr624:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st457;
st457:
	if ( ++p == pe )
		goto _test_eof457;
case 457:
#line 7597 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 58 )
		goto st457;
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto st457;
		} else if ( (*p) > 57 ) {
			if ( 60 <= (*p) && (*p) <= 64 )
				goto st457;
		} else
			goto tr628;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st457;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st457;
		} else
			goto tr628;
	} else
		goto tr628;
	goto tr623;
tr626:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st458;
tr628:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st458;
st458:
	if ( ++p == pe )
		goto _test_eof458;
case 458:
#line 7637 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 59: goto tr630;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr628;
	goto tr623;
tr629:
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
	goto st459;
st459:
	if ( ++p == pe )
		goto _test_eof459;
case 459:
#line 7659 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 46: goto tr632;
		case 49: goto tr633;
		case 95: goto tr634;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr634;
	} else if ( (*p) >= 65 )
		goto tr634;
	goto tr631;
tr632:
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
#line 7682 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 9: goto tr722;
		case 10: goto tr723;
		case 13: goto tr724;
	}
	goto tr721;
tr639:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st460;
tr722:
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
case 460:
#line 7708 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 95 )
		goto tr636;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr636;
	} else if ( (*p) >= 65 )
		goto tr636;
	goto tr635;
tr636:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st461;
tr638:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st461;
st461:
	if ( ++p == pe )
		goto _test_eof461;
case 461:
#line 7733 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 9: goto tr637;
		case 37: goto tr638;
		case 46: goto tr638;
		case 58: goto tr639;
		case 95: goto tr638;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr638;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr638;
	} else
		goto tr638;
	goto tr635;
tr637:
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
	goto st462;
st462:
	if ( ++p == pe )
		goto _test_eof462;
case 462:
#line 7764 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 46 )
		goto tr642;
	if ( (*p) < 48 ) {
		if ( 33 <= (*p) && (*p) <= 47 )
			goto tr641;
	} else if ( (*p) > 57 ) {
		if ( 59 <= (*p) && (*p) <= 126 )
			goto tr641;
	} else
		goto tr643;
	goto tr640;
tr641:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st538;
tr651:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st538;
st538:
	if ( ++p == pe )
		goto _test_eof538;
case 538:
#line 7792 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 9: goto tr637;
		case 10: goto tr723;
		case 13: goto tr724;
		case 58: goto tr725;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr651;
	goto tr650;
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
	goto st539;
st539:
	if ( ++p == pe )
		goto _test_eof539;
case 539:
#line 7854 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 10: goto tr719;
		case 13: goto tr720;
		case 43: goto tr726;
		case 60: goto st463;
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
	goto tr587;
tr718:
#line 70 "src/vcf/vcf.ragel"
	{
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (Error *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
    }
	goto st463;
st463:
	if ( ++p == pe )
		goto _test_eof463;
case 463:
#line 7889 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto tr644;
		case 92: goto tr644;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr644;
		} else if ( (*p) >= 33 )
			goto tr644;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr644;
		} else if ( (*p) >= 63 )
			goto tr644;
	} else
		goto tr644;
	goto tr587;
tr644:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st464;
tr645:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st464;
st464:
	if ( ++p == pe )
		goto _test_eof464;
case 464:
#line 7925 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto tr645;
		case 62: goto tr646;
		case 92: goto tr645;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr645;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr645;
		} else if ( (*p) >= 63 )
			goto tr645;
	} else
		goto tr645;
	goto tr587;
tr646:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st465;
st465:
	if ( ++p == pe )
		goto _test_eof465;
case 465:
#line 7951 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 9 )
		goto tr647;
	goto tr587;
tr724:
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
	goto st466;
st466:
	if ( ++p == pe )
		goto _test_eof466;
case 466:
#line 8007 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 10 )
		goto st539;
	goto tr648;
tr725:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st467;
st467:
	if ( ++p == pe )
		goto _test_eof467;
case 467:
#line 8019 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) > 57 ) {
		if ( 59 <= (*p) && (*p) <= 126 )
			goto tr651;
	} else if ( (*p) >= 33 )
		goto tr651;
	goto tr650;
tr642:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st540;
tr729:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st540;
st540:
	if ( ++p == pe )
		goto _test_eof540;
case 540:
#line 8042 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 9: goto tr637;
		case 10: goto tr723;
		case 13: goto tr724;
		case 47: goto tr728;
		case 58: goto tr725;
		case 124: goto tr728;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr651;
	goto tr640;
tr728:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st541;
st541:
	if ( ++p == pe )
		goto _test_eof541;
case 541:
#line 8062 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 9: goto tr637;
		case 10: goto tr723;
		case 13: goto tr724;
		case 46: goto tr729;
		case 58: goto tr725;
	}
	if ( (*p) < 48 ) {
		if ( 33 <= (*p) && (*p) <= 47 )
			goto tr651;
	} else if ( (*p) > 57 ) {
		if ( 59 <= (*p) && (*p) <= 126 )
			goto tr651;
	} else
		goto tr730;
	goto tr640;
tr643:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st542;
tr730:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st542;
st542:
	if ( ++p == pe )
		goto _test_eof542;
case 542:
#line 8095 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 9: goto tr637;
		case 10: goto tr723;
		case 13: goto tr724;
		case 47: goto tr728;
		case 58: goto tr725;
		case 124: goto tr728;
	}
	if ( (*p) < 48 ) {
		if ( 33 <= (*p) && (*p) <= 46 )
			goto tr651;
	} else if ( (*p) > 57 ) {
		if ( 59 <= (*p) && (*p) <= 126 )
			goto tr651;
	} else
		goto tr730;
	goto tr640;
tr633:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st468;
st468:
	if ( ++p == pe )
		goto _test_eof468;
case 468:
#line 8124 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 48 )
		goto tr652;
	goto tr631;
tr652:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st469;
st469:
	if ( ++p == pe )
		goto _test_eof469;
case 469:
#line 8136 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 48 )
		goto tr653;
	goto tr631;
tr653:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st470;
st470:
	if ( ++p == pe )
		goto _test_eof470;
case 470:
#line 8148 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 48 )
		goto tr654;
	goto tr631;
tr654:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st471;
st471:
	if ( ++p == pe )
		goto _test_eof471;
case 471:
#line 8160 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 71 )
		goto tr655;
	goto tr631;
tr655:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st543;
st543:
	if ( ++p == pe )
		goto _test_eof543;
case 543:
#line 8172 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 9: goto tr722;
		case 10: goto tr723;
		case 13: goto tr724;
		case 59: goto tr731;
		case 61: goto tr732;
	}
	goto tr631;
tr731:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st472;
st472:
	if ( ++p == pe )
		goto _test_eof472;
case 472:
#line 8189 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 49: goto tr633;
		case 95: goto tr634;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr634;
	} else if ( (*p) >= 65 )
		goto tr634;
	goto tr631;
tr634:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st544;
tr733:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st544;
st544:
	if ( ++p == pe )
		goto _test_eof544;
case 544:
#line 8216 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 9: goto tr722;
		case 10: goto tr723;
		case 13: goto tr724;
		case 46: goto tr733;
		case 59: goto tr731;
		case 61: goto tr732;
		case 95: goto tr733;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr733;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr733;
	} else
		goto tr733;
	goto tr631;
tr732:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st473;
st473:
	if ( ++p == pe )
		goto _test_eof473;
case 473:
#line 8243 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr657;
	} else if ( (*p) >= 32 )
		goto tr657;
	goto tr656;
tr657:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st545;
st545:
	if ( ++p == pe )
		goto _test_eof545;
case 545:
#line 8258 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 9: goto tr722;
		case 10: goto tr723;
		case 13: goto tr724;
		case 59: goto tr731;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr657;
	goto tr656;
tr630:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st474;
st474:
	if ( ++p == pe )
		goto _test_eof474;
case 474:
#line 8276 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 58 )
		goto tr624;
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr624;
		} else if ( (*p) > 57 ) {
			if ( 60 <= (*p) && (*p) <= 64 )
				goto tr624;
		} else
			goto tr626;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr624;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr624;
		} else
			goto tr626;
	} else
		goto tr626;
	goto tr623;
tr625:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st475;
st475:
	if ( ++p == pe )
		goto _test_eof475;
case 475:
#line 8311 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 9: goto tr629;
		case 58: goto st457;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto st457;
		} else if ( (*p) > 57 ) {
			if ( 60 <= (*p) && (*p) <= 64 )
				goto st457;
		} else
			goto tr628;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st457;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st457;
		} else
			goto tr628;
	} else
		goto tr628;
	goto tr623;
tr621:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st476;
st476:
	if ( ++p == pe )
		goto _test_eof476;
case 476:
#line 8345 "inc/vcf/validator_detail_v44.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr658;
	goto tr612;
tr658:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st477;
st477:
	if ( ++p == pe )
		goto _test_eof477;
case 477:
#line 8357 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 9: goto tr620;
		case 69: goto tr622;
		case 101: goto tr622;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr658;
	goto tr612;
tr622:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st478;
st478:
	if ( ++p == pe )
		goto _test_eof478;
case 478:
#line 8374 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto tr659;
		case 45: goto tr659;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr660;
	goto tr612;
tr659:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st479;
st479:
	if ( ++p == pe )
		goto _test_eof479;
case 479:
#line 8390 "inc/vcf/validator_detail_v44.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr660;
	goto tr612;
tr660:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st480;
st480:
	if ( ++p == pe )
		goto _test_eof480;
case 480:
#line 8402 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 9 )
		goto tr620;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr660;
	goto tr612;
tr616:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st481;
tr619:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st481;
st481:
	if ( ++p == pe )
		goto _test_eof481;
case 481:
#line 8424 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 110 )
		goto tr661;
	goto tr612;
tr661:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st482;
st482:
	if ( ++p == pe )
		goto _test_eof482;
case 482:
#line 8436 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 102 )
		goto tr662;
	goto tr612;
tr614:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st483;
tr662:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st483;
st483:
	if ( ++p == pe )
		goto _test_eof483;
case 483:
#line 8456 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 9 )
		goto tr620;
	goto tr612;
tr617:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st484;
st484:
	if ( ++p == pe )
		goto _test_eof484;
case 484:
#line 8471 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 97 )
		goto tr663;
	goto tr612;
tr663:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st485;
st485:
	if ( ++p == pe )
		goto _test_eof485;
case 485:
#line 8483 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 78 )
		goto tr662;
	goto tr612;
tr611:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st486;
st486:
	if ( ++p == pe )
		goto _test_eof486;
case 486:
#line 8495 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 42: goto tr604;
		case 46: goto tr664;
		case 60: goto tr606;
		case 65: goto tr607;
		case 67: goto tr607;
		case 71: goto tr607;
		case 78: goto tr607;
		case 84: goto tr607;
		case 91: goto tr608;
		case 93: goto tr609;
		case 97: goto tr607;
		case 99: goto tr607;
		case 103: goto tr607;
		case 110: goto tr607;
		case 116: goto tr607;
	}
	goto tr603;
tr664:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st487;
tr693:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st487;
st487:
	if ( ++p == pe )
		goto _test_eof487;
case 487:
#line 8530 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 65: goto tr665;
		case 67: goto tr665;
		case 71: goto tr665;
		case 78: goto tr665;
		case 84: goto tr665;
		case 97: goto tr665;
		case 99: goto tr665;
		case 103: goto tr665;
		case 110: goto tr665;
		case 116: goto tr665;
	}
	goto tr603;
tr665:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st488;
st488:
	if ( ++p == pe )
		goto _test_eof488;
case 488:
#line 8552 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 9: goto tr610;
		case 44: goto tr611;
		case 65: goto tr665;
		case 67: goto tr665;
		case 71: goto tr665;
		case 78: goto tr665;
		case 84: goto tr665;
		case 97: goto tr665;
		case 99: goto tr665;
		case 103: goto tr665;
		case 110: goto tr665;
		case 116: goto tr665;
	}
	goto tr603;
tr606:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st489;
st489:
	if ( ++p == pe )
		goto _test_eof489;
case 489:
#line 8579 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 42: goto tr667;
		case 61: goto tr666;
	}
	if ( (*p) < 63 ) {
		if ( (*p) < 45 ) {
			if ( 33 <= (*p) && (*p) <= 43 )
				goto tr666;
		} else if ( (*p) > 47 ) {
			if ( (*p) > 57 ) {
				if ( 58 <= (*p) && (*p) <= 59 )
					goto tr666;
			} else if ( (*p) >= 48 )
				goto tr668;
		} else
			goto tr666;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr668;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr666;
			} else if ( (*p) >= 97 )
				goto tr668;
		} else
			goto tr666;
	} else
		goto tr666;
	goto tr603;
tr666:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st490;
st490:
	if ( ++p == pe )
		goto _test_eof490;
case 490:
#line 8619 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 61 )
		goto tr666;
	if ( (*p) < 63 ) {
		if ( (*p) < 45 ) {
			if ( 33 <= (*p) && (*p) <= 43 )
				goto tr666;
		} else if ( (*p) > 47 ) {
			if ( (*p) > 57 ) {
				if ( 58 <= (*p) && (*p) <= 59 )
					goto tr666;
			} else if ( (*p) >= 48 )
				goto tr668;
		} else
			goto tr666;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr668;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr666;
			} else if ( (*p) >= 97 )
				goto tr668;
		} else
			goto tr666;
	} else
		goto tr666;
	goto tr603;
tr668:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st491;
st491:
	if ( ++p == pe )
		goto _test_eof491;
case 491:
#line 8657 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 62 )
		goto tr669;
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr668;
	} else if ( (*p) > 59 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr668;
	} else
		goto tr668;
	goto tr603;
tr667:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st492;
st492:
	if ( ++p == pe )
		goto _test_eof492;
case 492:
#line 8677 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 62 )
		goto tr669;
	if ( (*p) < 61 ) {
		if ( (*p) < 45 ) {
			if ( 33 <= (*p) && (*p) <= 43 )
				goto tr666;
		} else if ( (*p) > 47 ) {
			if ( (*p) > 57 ) {
				if ( 58 <= (*p) && (*p) <= 59 )
					goto tr666;
			} else if ( (*p) >= 48 )
				goto tr668;
		} else
			goto tr666;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr668;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr666;
			} else if ( (*p) >= 97 )
				goto tr668;
		} else
			goto tr666;
	} else
		goto tr666;
	goto tr603;
tr607:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st493;
tr670:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st493;
st493:
	if ( ++p == pe )
		goto _test_eof493;
case 493:
#line 8723 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 9: goto tr610;
		case 44: goto tr611;
		case 46: goto tr669;
		case 65: goto tr670;
		case 67: goto tr670;
		case 71: goto tr670;
		case 78: goto tr670;
		case 84: goto tr670;
		case 91: goto tr671;
		case 93: goto tr672;
		case 97: goto tr670;
		case 99: goto tr670;
		case 103: goto tr670;
		case 110: goto tr670;
		case 116: goto tr670;
	}
	goto tr603;
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
#line 8750 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto tr673;
		case 60: goto tr674;
		case 92: goto tr673;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr673;
		} else if ( (*p) >= 33 )
			goto tr673;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr673;
		} else if ( (*p) >= 63 )
			goto tr673;
	} else
		goto tr673;
	goto tr603;
tr673:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st495;
st495:
	if ( ++p == pe )
		goto _test_eof495;
case 495:
#line 8779 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto tr673;
		case 58: goto tr675;
		case 92: goto tr673;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr673;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr673;
		} else if ( (*p) >= 63 )
			goto tr673;
	} else
		goto tr673;
	goto tr603;
tr675:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st496;
st496:
	if ( ++p == pe )
		goto _test_eof496;
case 496:
#line 8805 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto tr673;
		case 58: goto tr675;
		case 59: goto tr673;
		case 92: goto tr673;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 41 ) {
			if ( 45 <= (*p) && (*p) <= 47 )
				goto tr673;
		} else if ( (*p) >= 33 )
			goto tr673;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr673;
		} else if ( (*p) >= 63 )
			goto tr673;
	} else
		goto tr676;
	goto tr603;
tr676:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st497;
st497:
	if ( ++p == pe )
		goto _test_eof497;
case 497:
#line 8835 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto tr673;
		case 58: goto tr675;
		case 59: goto tr673;
		case 91: goto tr669;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 41 ) {
			if ( 45 <= (*p) && (*p) <= 47 )
				goto tr673;
		} else if ( (*p) >= 33 )
			goto tr673;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 92 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr673;
		} else if ( (*p) >= 63 )
			goto tr673;
	} else
		goto tr676;
	goto tr603;
tr674:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st498;
st498:
	if ( ++p == pe )
		goto _test_eof498;
case 498:
#line 8865 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto tr677;
		case 92: goto tr677;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr677;
		} else if ( (*p) >= 33 )
			goto tr677;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr677;
		} else if ( (*p) >= 63 )
			goto tr677;
	} else
		goto tr677;
	goto tr603;
tr677:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st499;
st499:
	if ( ++p == pe )
		goto _test_eof499;
case 499:
#line 8893 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto tr677;
		case 62: goto tr678;
		case 92: goto tr677;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr677;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr677;
		} else if ( (*p) >= 63 )
			goto tr677;
	} else
		goto tr677;
	goto tr603;
tr678:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st500;
st500:
	if ( ++p == pe )
		goto _test_eof500;
case 500:
#line 8919 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 58 )
		goto tr679;
	goto tr603;
tr679:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st501;
st501:
	if ( ++p == pe )
		goto _test_eof501;
case 501:
#line 8931 "inc/vcf/validator_detail_v44.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr680;
	goto tr603;
tr680:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st502;
st502:
	if ( ++p == pe )
		goto _test_eof502;
case 502:
#line 8943 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 91 )
		goto tr669;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr680;
	goto tr603;
tr672:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st503;
st503:
	if ( ++p == pe )
		goto _test_eof503;
case 503:
#line 8957 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto tr681;
		case 60: goto tr682;
		case 92: goto tr681;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr681;
		} else if ( (*p) >= 33 )
			goto tr681;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr681;
		} else if ( (*p) >= 63 )
			goto tr681;
	} else
		goto tr681;
	goto tr603;
tr681:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st504;
st504:
	if ( ++p == pe )
		goto _test_eof504;
case 504:
#line 8986 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto tr681;
		case 58: goto tr683;
		case 92: goto tr681;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr681;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr681;
		} else if ( (*p) >= 63 )
			goto tr681;
	} else
		goto tr681;
	goto tr603;
tr683:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st505;
st505:
	if ( ++p == pe )
		goto _test_eof505;
case 505:
#line 9012 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto tr681;
		case 58: goto tr683;
		case 59: goto tr681;
		case 92: goto tr681;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 41 ) {
			if ( 45 <= (*p) && (*p) <= 47 )
				goto tr681;
		} else if ( (*p) >= 33 )
			goto tr681;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr681;
		} else if ( (*p) >= 63 )
			goto tr681;
	} else
		goto tr684;
	goto tr603;
tr684:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st506;
st506:
	if ( ++p == pe )
		goto _test_eof506;
case 506:
#line 9042 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto tr681;
		case 58: goto tr683;
		case 59: goto tr681;
		case 93: goto tr669;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 41 ) {
			if ( 45 <= (*p) && (*p) <= 47 )
				goto tr681;
		} else if ( (*p) >= 33 )
			goto tr681;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 92 <= (*p) && (*p) <= 126 )
				goto tr681;
		} else if ( (*p) >= 63 )
			goto tr681;
	} else
		goto tr684;
	goto tr603;
tr682:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st507;
st507:
	if ( ++p == pe )
		goto _test_eof507;
case 507:
#line 9072 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto tr685;
		case 92: goto tr685;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr685;
		} else if ( (*p) >= 33 )
			goto tr685;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr685;
		} else if ( (*p) >= 63 )
			goto tr685;
	} else
		goto tr685;
	goto tr603;
tr685:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st508;
st508:
	if ( ++p == pe )
		goto _test_eof508;
case 508:
#line 9100 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto tr685;
		case 62: goto tr686;
		case 92: goto tr685;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr685;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr685;
		} else if ( (*p) >= 63 )
			goto tr685;
	} else
		goto tr685;
	goto tr603;
tr686:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st509;
st509:
	if ( ++p == pe )
		goto _test_eof509;
case 509:
#line 9126 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 58 )
		goto tr687;
	goto tr603;
tr687:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st510;
st510:
	if ( ++p == pe )
		goto _test_eof510;
case 510:
#line 9138 "inc/vcf/validator_detail_v44.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr688;
	goto tr603;
tr688:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st511;
st511:
	if ( ++p == pe )
		goto _test_eof511;
case 511:
#line 9150 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 93 )
		goto tr669;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr688;
	goto tr603;
tr608:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st512;
st512:
	if ( ++p == pe )
		goto _test_eof512;
case 512:
#line 9167 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto tr689;
		case 60: goto tr690;
		case 92: goto tr689;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr689;
		} else if ( (*p) >= 33 )
			goto tr689;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr689;
		} else if ( (*p) >= 63 )
			goto tr689;
	} else
		goto tr689;
	goto tr603;
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
#line 9196 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto tr689;
		case 58: goto tr691;
		case 92: goto tr689;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr689;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr689;
		} else if ( (*p) >= 63 )
			goto tr689;
	} else
		goto tr689;
	goto tr603;
tr691:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st514;
st514:
	if ( ++p == pe )
		goto _test_eof514;
case 514:
#line 9222 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto tr689;
		case 58: goto tr691;
		case 59: goto tr689;
		case 92: goto tr689;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 41 ) {
			if ( 45 <= (*p) && (*p) <= 47 )
				goto tr689;
		} else if ( (*p) >= 33 )
			goto tr689;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr689;
		} else if ( (*p) >= 63 )
			goto tr689;
	} else
		goto tr692;
	goto tr603;
tr692:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st515;
st515:
	if ( ++p == pe )
		goto _test_eof515;
case 515:
#line 9252 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto tr689;
		case 58: goto tr691;
		case 59: goto tr689;
		case 91: goto tr693;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 41 ) {
			if ( 45 <= (*p) && (*p) <= 47 )
				goto tr689;
		} else if ( (*p) >= 33 )
			goto tr689;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 92 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr689;
		} else if ( (*p) >= 63 )
			goto tr689;
	} else
		goto tr692;
	goto tr603;
tr690:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st516;
st516:
	if ( ++p == pe )
		goto _test_eof516;
case 516:
#line 9282 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto tr694;
		case 92: goto tr694;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr694;
		} else if ( (*p) >= 33 )
			goto tr694;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr694;
		} else if ( (*p) >= 63 )
			goto tr694;
	} else
		goto tr694;
	goto tr603;
tr694:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st517;
st517:
	if ( ++p == pe )
		goto _test_eof517;
case 517:
#line 9310 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto tr694;
		case 62: goto tr695;
		case 92: goto tr694;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr694;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr694;
		} else if ( (*p) >= 63 )
			goto tr694;
	} else
		goto tr694;
	goto tr603;
tr695:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st518;
st518:
	if ( ++p == pe )
		goto _test_eof518;
case 518:
#line 9336 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 58 )
		goto tr696;
	goto tr603;
tr696:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st519;
st519:
	if ( ++p == pe )
		goto _test_eof519;
case 519:
#line 9348 "inc/vcf/validator_detail_v44.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr697;
	goto tr603;
tr697:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st520;
st520:
	if ( ++p == pe )
		goto _test_eof520;
case 520:
#line 9360 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 91 )
		goto tr693;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr697;
	goto tr603;
tr609:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st521;
st521:
	if ( ++p == pe )
		goto _test_eof521;
case 521:
#line 9377 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto tr698;
		case 60: goto tr699;
		case 92: goto tr698;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr698;
		} else if ( (*p) >= 33 )
			goto tr698;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr698;
		} else if ( (*p) >= 63 )
			goto tr698;
	} else
		goto tr698;
	goto tr603;
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
#line 9406 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto tr698;
		case 58: goto tr700;
		case 92: goto tr698;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr698;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr698;
		} else if ( (*p) >= 63 )
			goto tr698;
	} else
		goto tr698;
	goto tr603;
tr700:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st523;
st523:
	if ( ++p == pe )
		goto _test_eof523;
case 523:
#line 9432 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto tr698;
		case 58: goto tr700;
		case 59: goto tr698;
		case 92: goto tr698;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 41 ) {
			if ( 45 <= (*p) && (*p) <= 47 )
				goto tr698;
		} else if ( (*p) >= 33 )
			goto tr698;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr698;
		} else if ( (*p) >= 63 )
			goto tr698;
	} else
		goto tr701;
	goto tr603;
tr701:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st524;
st524:
	if ( ++p == pe )
		goto _test_eof524;
case 524:
#line 9462 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto tr698;
		case 58: goto tr700;
		case 59: goto tr698;
		case 93: goto tr693;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 41 ) {
			if ( 45 <= (*p) && (*p) <= 47 )
				goto tr698;
		} else if ( (*p) >= 33 )
			goto tr698;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 92 <= (*p) && (*p) <= 126 )
				goto tr698;
		} else if ( (*p) >= 63 )
			goto tr698;
	} else
		goto tr701;
	goto tr603;
tr699:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st525;
st525:
	if ( ++p == pe )
		goto _test_eof525;
case 525:
#line 9492 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto tr702;
		case 92: goto tr702;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr702;
		} else if ( (*p) >= 33 )
			goto tr702;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr702;
		} else if ( (*p) >= 63 )
			goto tr702;
	} else
		goto tr702;
	goto tr603;
tr702:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st526;
st526:
	if ( ++p == pe )
		goto _test_eof526;
case 526:
#line 9520 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto tr702;
		case 62: goto tr703;
		case 92: goto tr702;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr702;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr702;
		} else if ( (*p) >= 63 )
			goto tr702;
	} else
		goto tr702;
	goto tr603;
tr703:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st527;
st527:
	if ( ++p == pe )
		goto _test_eof527;
case 527:
#line 9546 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 58 )
		goto tr704;
	goto tr603;
tr704:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st528;
st528:
	if ( ++p == pe )
		goto _test_eof528;
case 528:
#line 9558 "inc/vcf/validator_detail_v44.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr705;
	goto tr603;
tr705:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st529;
st529:
	if ( ++p == pe )
		goto _test_eof529;
case 529:
#line 9570 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 93 )
		goto tr693;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr705;
	goto tr603;
tr605:
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
#line 9587 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 9: goto tr610;
		case 65: goto tr665;
		case 67: goto tr665;
		case 71: goto tr665;
		case 78: goto tr665;
		case 84: goto tr665;
		case 97: goto tr665;
		case 99: goto tr665;
		case 103: goto tr665;
		case 110: goto tr665;
		case 116: goto tr665;
	}
	goto tr603;
tr571:
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
tr583:
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
#line 9644 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 10 )
		goto st535;
	goto tr572;
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
#line 9670 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 10 )
		goto st22;
	goto tr0;
tr710:
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
#line 9688 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 10: goto tr709;
		case 13: goto tr710;
	}
	goto st533;
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
#line 265 "src/vcf/vcf_v44.ragel"
	{ {goto st28;} }
	goto st546;
st546:
	if ( ++p == pe )
		goto _test_eof546;
case 546:
#line 9709 "inc/vcf/validator_detail_v44.hpp"
	goto st0;
tr713:
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
#line 9725 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 10: goto tr712;
		case 13: goto tr713;
	}
	goto st534;
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
#line 266 "src/vcf/vcf_v44.ragel"
	{ {goto st539;} }
	goto st547;
st547:
	if ( ++p == pe )
		goto _test_eof547;
case 547:
#line 9746 "inc/vcf/validator_detail_v44.hpp"
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
	_test_eof535: cs = 535; goto _test_eof; 
	_test_eof536: cs = 536; goto _test_eof; 
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
	_test_eof537: cs = 537; goto _test_eof; 
	_test_eof460: cs = 460; goto _test_eof; 
	_test_eof461: cs = 461; goto _test_eof; 
	_test_eof462: cs = 462; goto _test_eof; 
	_test_eof538: cs = 538; goto _test_eof; 
	_test_eof539: cs = 539; goto _test_eof; 
	_test_eof463: cs = 463; goto _test_eof; 
	_test_eof464: cs = 464; goto _test_eof; 
	_test_eof465: cs = 465; goto _test_eof; 
	_test_eof466: cs = 466; goto _test_eof; 
	_test_eof467: cs = 467; goto _test_eof; 
	_test_eof540: cs = 540; goto _test_eof; 
	_test_eof541: cs = 541; goto _test_eof; 
	_test_eof542: cs = 542; goto _test_eof; 
	_test_eof468: cs = 468; goto _test_eof; 
	_test_eof469: cs = 469; goto _test_eof; 
	_test_eof470: cs = 470; goto _test_eof; 
	_test_eof471: cs = 471; goto _test_eof; 
	_test_eof543: cs = 543; goto _test_eof; 
	_test_eof472: cs = 472; goto _test_eof; 
	_test_eof544: cs = 544; goto _test_eof; 
	_test_eof473: cs = 473; goto _test_eof; 
	_test_eof545: cs = 545; goto _test_eof; 
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
	case 466: 
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
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
	case 316: 
	case 317: 
	case 318: 
	case 319: 
	case 320: 
	case 321: 
	case 322: 
	case 323: 
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
	case 140: 
	case 141: 
	case 142: 
	case 143: 
	case 144: 
	case 145: 
	case 146: 
	case 147: 
	case 151: 
	case 152: 
	case 153: 
	case 154: 
	case 155: 
	case 156: 
	case 157: 
	case 160: 
	case 161: 
	case 162: 
	case 163: 
	case 164: 
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
	case 178: 
	case 179: 
	case 186: 
	case 187: 
	case 188: 
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
	case 236: 
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
	case 252: 
	case 253: 
	case 254: 
	case 255: 
	case 256: 
	case 257: 
	case 261: 
	case 262: 
	case 263: 
	case 264: 
	case 265: 
	case 266: 
	case 267: 
	case 271: 
	case 282: 
	case 283: 
	case 284: 
	case 285: 
	case 286: 
	case 287: 
	case 288: 
	case 289: 
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
	case 190: 
	case 191: 
	case 192: 
	case 193: 
	case 194: 
	case 195: 
	case 196: 
	case 197: 
	case 201: 
	case 202: 
	case 203: 
	case 204: 
	case 205: 
	case 206: 
	case 207: 
	case 210: 
	case 211: 
	case 212: 
	case 213: 
	case 214: 
	case 222: 
	case 223: 
	case 224: 
	case 225: 
	case 226: 
	case 227: 
	case 228: 
	case 229: 
	case 230: 
	case 232: 
	case 233: 
	case 235: 
#line 338 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
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
	case 306: 
	case 307: 
	case 308: 
	case 309: 
	case 310: 
	case 311: 
	case 312: 
	case 313: 
	case 314: 
	case 315: 
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
	case 444: 
	case 463: 
	case 464: 
	case 465: 
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
	case 445: 
	case 446: 
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
	case 447: 
	case 448: 
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
	case 449: 
	case 450: 
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
	case 451: 
	case 452: 
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
	case 453: 
	case 454: 
	case 455: 
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
	case 456: 
	case 457: 
	case 458: 
	case 474: 
	case 475: 
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
	case 14: 
	case 15: 
	case 16: 
	case 17: 
	case 18: 
	case 19: 
	case 20: 
	case 21: 
#line 29 "src/vcf/vcf_v44.ragel"
	{
        ErrorPolicy::handle_error(*this,
                new FileformatError{n_lines, "The fileformat declaration is not 'fileformat=VCFv4.4'"});
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
	case 460: 
	case 461: 
#line 50 "src/vcf/vcf_v44.ragel"
	{
        ErrorPolicy::handle_error(*this, new FormatBodyError{n_lines, "Format does not start with a letter/underscore followed by alphanumeric/underscore/dot characters"});
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
	case 434: 
	case 435: 
	case 436: 
	case 437: 
	case 438: 
	case 439: 
	case 440: 
	case 441: 
	case 442: 
#line 55 "src/vcf/vcf_v44.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
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
	case 55: 
	case 56: 
	case 57: 
#line 264 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines,
               "ALT metadata ID is not prefixed by DEL/INS/DUP/INV/CNV" + (source->version < Version::v44 ? std::string("/BND") : std::string("")) + " and suffixed by ':' and a text sequence"});
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
	case 67: 
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
	case 115: 
	case 116: 
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
	case 165: 
	case 166: 
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
	case 290: 
	case 291: 
	case 292: 
#line 316 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "PEDIGREE metadata Original is not valid"});
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
	case 258: 
	case 259: 
	case 260: 
	case 268: 
	case 269: 
	case 270: 
#line 321 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "PEDIGREE metadata Father or Mother is not valid"});
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
	case 251: 
	case 272: 
	case 273: 
	case 274: 
	case 275: 
	case 276: 
	case 277: 
	case 278: 
	case 279: 
	case 280: 
	case 281: 
#line 326 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "PEDIGREE metadata sequence of Name_N is not valid"});
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
	case 208: 
	case 209: 
#line 343 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "META metadata Number is not a dot"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 338 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
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
	case 215: 
	case 216: 
	case 217: 
	case 218: 
	case 219: 
	case 220: 
	case 221: 
#line 348 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "META metadata Type is not String"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 338 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
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
	case 231: 
	case 234: 
#line 353 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "META metadata Values is not a square-bracket delimited list of values"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 338 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
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
	case 58: 
	case 59: 
	case 60: 
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
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
	case 353: 
	case 354: 
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
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
	case 148: 
	case 149: 
	case 150: 
	case 183: 
	case 184: 
	case 185: 
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
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
	case 248: 
	case 249: 
	case 250: 
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
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
	case 198: 
	case 199: 
	case 200: 
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
        p--; {       if ( p == pe )
               goto _test_eof533;
goto st533;}
    }
#line 338 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
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
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore, dash and plus"});
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
	case 62: 
	case 63: 
	case 64: 
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
	case 84: 
	case 85: 
	case 86: 
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
	case 130: 
	case 131: 
	case 132: 
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
	case 180: 
	case 181: 
	case 182: 
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
	case 324: 
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
	case 108: 
	case 109: 
	case 139: 
#line 36 "src/vcf/vcf_v44.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "FORMAT metadata Number is not a number, A, R, G, P or dot"});
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
	case 158: 
	case 159: 
	case 189: 
#line 42 "src/vcf/vcf_v44.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "INFO metadata Number is not a number, A, R, G or dot"});
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
	case 430: 
	case 431: 
	case 432: 
	case 433: 
#line 55 "src/vcf/vcf_v44.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
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
	case 467: 
#line 55 "src/vcf/vcf_v44.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
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
	case 537: 
	case 538: 
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
#line 55 "src/vcf/vcf_v44.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
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
#line 55 "src/vcf/vcf_v44.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
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
	case 459: 
	case 468: 
	case 469: 
	case 470: 
	case 471: 
	case 472: 
#line 455 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info key is not a sequence of alphanumeric and/or punctuation characters"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 55 "src/vcf/vcf_v44.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
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
	case 473: 
#line 460 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info field value is not a comma-separated list of valid strings (maybe it contains whitespaces?)"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
#line 55 "src/vcf/vcf_v44.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
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
	case 540: 
	case 541: 
	case 542: 
#line 55 "src/vcf/vcf_v44.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
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
	case 462: 
#line 55 "src/vcf/vcf_v44.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
    }
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
#line 55 "src/vcf/vcf_v44.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {       if ( p == pe )
               goto _test_eof534;
goto st534;}
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
#line 338 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
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
#line 12030 "inc/vcf/validator_detail_v44.hpp"
	}
	}

	_out: {}
	}

#line 295 "src/vcf/vcf_v44.ragel"

    }

  }
}
