
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
  
#line 27 "inc/vcf/validator_detail_v44.hpp"
static const int vcf_v44_start = 1;
static const int vcf_v44_first_final = 625;
static const int vcf_v44_error = 0;

static const int vcf_v44_en_main = 1;
static const int vcf_v44_en_main_meta_section = 28;
static const int vcf_v44_en_main_body_section = 629;
static const int vcf_v44_en_meta_section_skip = 623;
static const int vcf_v44_en_body_section_skip = 624;


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
      
#line 53 "inc/vcf/validator_detail_v44.hpp"
	{
	cs = vcf_v44_start;
	}

#line 287 "src/vcf/vcf_v44.ragel"

    }

    template <typename Configuration>
    void ParserImpl_v44<Configuration>::parse_buffer(char const * p, char const * pe, char const * eof)
    {
      
#line 66 "inc/vcf/validator_detail_v44.hpp"
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
        p--; {goto st623;}
    }
	goto st0;
tr14:
#line 29 "src/vcf/vcf_v44.ragel"
	{
        ErrorPolicy::handle_error(*this,
                new FileformatError{n_lines, "The fileformat declaration is not 'fileformat=VCFv4.4'"});
        p--; {goto st623;}
    }
#line 60 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new FileformatError{n_lines});
        p--; {goto st623;}
    }
	goto st0;
tr24:
#line 60 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new FileformatError{n_lines});
        p--; {goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st623;}
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
        
        p--; {goto st624;}
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
        
        p--; {goto st624;}
    }
	goto st0;
tr26:
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st623;}
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
        
        p--; {goto st624;}
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
        
        p--; {goto st624;}
    }
	goto st0;
tr29:
#line 259 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {goto st623;}
    }
#line 283 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {goto st623;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st623;}
    }
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st623;}
    }
#line 271 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in assembly metadata"});
        p--; {goto st623;}
    }
#line 277 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in contig metadata"});
        p--; {goto st623;}
    }
#line 338 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
        p--; {goto st623;}
    }
#line 359 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st623;}
    }
#line 311 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {goto st623;}
    }
#line 332 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in pedigreeDB metadata"});
        p--; {goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st623;}
    }
	goto st0;
tr40:
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st623;}
    }
	goto st0;
tr126:
#line 259 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st623;}
    }
	goto st0;
tr134:
#line 264 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines,
               "ALT metadata ID is not prefixed by DEL/INS/DUP/INV/CNV" + (source->version < Version::v44 ? std::string("/BND") : std::string("")) + " and suffixed by ':' and a text sequence"});
        p--; {goto st623;}
    }
#line 259 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st623;}
    }
	goto st0;
tr141:
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st623;}
    }
#line 259 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st623;}
    }
	goto st0;
tr148:
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st623;}
    }
#line 259 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st623;}
    }
	goto st0;
tr160:
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st623;}
    }
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st623;}
    }
#line 259 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st623;}
    }
	goto st0;
tr169:
#line 283 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {goto st623;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st623;}
    }
	goto st0;
tr172:
#line 283 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st623;}
    }
	goto st0;
tr182:
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st623;}
    }
#line 283 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st623;}
    }
	goto st0;
tr195:
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st623;}
    }
#line 283 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st623;}
    }
	goto st0;
tr207:
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st623;}
    }
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st623;}
    }
#line 283 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st623;}
    }
	goto st0;
tr216:
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st623;}
    }
	goto st0;
tr226:
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st623;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st623;}
    }
	goto st0;
tr239:
#line 36 "src/vcf/vcf_v44.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "FORMAT metadata Number is not a number, A, R, G, P or dot"});
        p--; {goto st623;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st623;}
    }
	goto st0;
tr248:
#line 305 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "INFO metadata Type is not Integer, Float, Flag, Character or String"});
        p--; {goto st623;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st623;}
    }
	goto st0;
tr265:
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st623;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st623;}
    }
	goto st0;
tr287:
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st623;}
    }
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st623;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st623;}
    }
	goto st0;
tr299:
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st623;}
    }
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st623;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st623;}
    }
	goto st0;
tr306:
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st623;}
    }
	goto st0;
tr315:
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st623;}
    }
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st623;}
    }
	goto st0;
tr328:
#line 42 "src/vcf/vcf_v44.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "INFO metadata Number is not a number, A, R, G or dot"});
        p--; {goto st623;}
    }
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st623;}
    }
	goto st0;
tr337:
#line 305 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "INFO metadata Type is not Integer, Float, Flag, Character or String"});
        p--; {goto st623;}
    }
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st623;}
    }
	goto st0;
tr354:
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st623;}
    }
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st623;}
    }
	goto st0;
tr376:
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st623;}
    }
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st623;}
    }
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st623;}
    }
	goto st0;
tr388:
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st623;}
    }
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st623;}
    }
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st623;}
    }
	goto st0;
tr395:
#line 338 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
        p--; {goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st623;}
    }
	goto st0;
tr404:
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st623;}
    }
#line 338 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
        p--; {goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st623;}
    }
	goto st0;
tr417:
#line 343 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "META metadata Number is not a dot"});
        p--; {goto st623;}
    }
#line 338 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
        p--; {goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st623;}
    }
	goto st0;
tr425:
#line 348 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "META metadata Type is not String"});
        p--; {goto st623;}
    }
#line 338 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
        p--; {goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st623;}
    }
	goto st0;
tr442:
#line 353 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "META metadata Values is not a square-bracket delimited list of values"});
        p--; {goto st623;}
    }
#line 338 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
        p--; {goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st623;}
    }
	goto st0;
tr448:
#line 311 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st623;}
    }
	goto st0;
tr461:
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st623;}
    }
#line 311 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st623;}
    }
	goto st0;
tr467:
#line 326 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "PEDIGREE metadata sequence of Name_N is not valid"});
        p--; {goto st623;}
    }
#line 311 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st623;}
    }
	goto st0;
tr477:
#line 321 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "PEDIGREE metadata Father or Mother is not valid"});
        p--; {goto st623;}
    }
#line 311 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st623;}
    }
	goto st0;
tr514:
#line 316 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "PEDIGREE metadata Original is not valid"});
        p--; {goto st623;}
    }
#line 311 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st623;}
    }
	goto st0;
tr519:
#line 359 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st623;}
    }
	goto st0;
tr530:
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st623;}
    }
#line 359 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st623;}
    }
	goto st0;
tr570:
#line 271 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in assembly metadata"});
        p--; {goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st623;}
    }
	goto st0;
tr579:
#line 385 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata URL is not valid"});
        p--; {goto st623;}
    }
#line 271 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in assembly metadata"});
        p--; {goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st623;}
    }
	goto st0;
tr600:
#line 277 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in contig metadata"});
        p--; {goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st623;}
    }
	goto st0;
tr611:
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st623;}
    }
#line 277 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in contig metadata"});
        p--; {goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st623;}
    }
	goto st0;
tr649:
#line 332 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in pedigreeDB metadata"});
        p--; {goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st623;}
    }
	goto st0;
tr661:
#line 385 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata URL is not valid"});
        p--; {goto st623;}
    }
#line 332 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in pedigreeDB metadata"});
        p--; {goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st623;}
    }
	goto st0;
tr684:
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
        
        p--; {goto st624;}
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
        
        p--; {goto st624;}
    }
	goto st0;
tr724:
#line 78 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new HeaderSectionError{n_lines});
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (Error *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
        
        p--; {goto st624;}
    }
	goto st0;
tr739:
#line 408 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new ChromosomeBodyError{n_lines});
        p--; {goto st624;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st624;}
    }
	goto st0;
tr742:
#line 414 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new PositionBodyError{n_lines});
        p--; {goto st624;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st624;}
    }
	goto st0;
tr746:
#line 420 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new IdBodyError{n_lines});
        p--; {goto st624;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st624;}
    }
	goto st0;
tr751:
#line 426 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new ReferenceAlleleBodyError{n_lines});
        p--; {goto st624;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st624;}
    }
	goto st0;
tr755:
#line 432 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new AlternateAllelesBodyError{n_lines});
        p--; {goto st624;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st624;}
    }
	goto st0;
tr764:
#line 438 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new QualityBodyError{n_lines});
        p--; {goto st624;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st624;}
    }
	goto st0;
tr775:
#line 444 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new FilterBodyError{n_lines});
        p--; {goto st624;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st624;}
    }
	goto st0;
tr783:
#line 455 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info key is not a sequence of alphanumeric and/or punctuation characters"});
        p--; {goto st624;}
    }
#line 450 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st624;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st624;}
    }
	goto st0;
tr787:
#line 50 "src/vcf/vcf_v44.ragel"
	{
        ErrorPolicy::handle_error(*this, new FormatBodyError{n_lines, "Format does not start with a letter/underscore followed by alphanumeric/underscore/dot characters"});
        p--; {goto st624;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st624;}
    }
	goto st0;
tr792:
#line 473 "src/vcf/vcf.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " does not start with a valid genotype";
        ErrorPolicy::handle_error(*this, new SamplesFieldBodyError{n_lines, message_stream.str(), "", "GT"});
        p--; {goto st624;}
    }
#line 466 "src/vcf/vcf.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " is not a valid string";
        ErrorPolicy::handle_error(*this, new SamplesBodyError{n_lines, message_stream.str()});
        p--; {goto st624;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st624;}
    }
	goto st0;
tr800:
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st624;}
    }
	goto st0;
tr802:
#line 466 "src/vcf/vcf.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " is not a valid string";
        ErrorPolicy::handle_error(*this, new SamplesBodyError{n_lines, message_stream.str()});
        p--; {goto st624;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st624;}
    }
	goto st0;
tr808:
#line 460 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info field value is not a comma-separated list of valid strings (maybe it contains whitespaces?)"});
        p--; {goto st624;}
    }
#line 450 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st624;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st624;}
    }
	goto st0;
tr866:
#line 78 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new HeaderSectionError{n_lines});
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (Error *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
        
        p--; {goto st624;}
    }
#line 408 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new ChromosomeBodyError{n_lines});
        p--; {goto st624;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st624;}
    }
	goto st0;
tr873:
#line 450 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st624;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st624;}
    }
	goto st0;
#line 1181 "inc/vcf/validator_detail_v44.hpp"
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
#line 1290 "inc/vcf/validator_detail_v44.hpp"
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
#line 1304 "inc/vcf/validator_detail_v44.hpp"
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
#line 1318 "inc/vcf/validator_detail_v44.hpp"
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
#line 1332 "inc/vcf/validator_detail_v44.hpp"
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
#line 1346 "inc/vcf/validator_detail_v44.hpp"
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
#line 1360 "inc/vcf/validator_detail_v44.hpp"
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
#line 1374 "inc/vcf/validator_detail_v44.hpp"
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
          p--; {goto st623;}
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
#line 1405 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 35 )
		goto st23;
	goto tr24;
st23:
	if ( ++p == pe )
		goto _test_eof23;
case 23:
	switch( (*p) ) {
		case 35: goto st24;
		case 67: goto st487;
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
#line 1459 "inc/vcf/validator_detail_v44.hpp"
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
#line 1475 "inc/vcf/validator_detail_v44.hpp"
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
case 27:
#line 1503 "inc/vcf/validator_detail_v44.hpp"
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
#line 1559 "inc/vcf/validator_detail_v44.hpp"
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
#line 1611 "inc/vcf/validator_detail_v44.hpp"
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
#line 1646 "inc/vcf/validator_detail_v44.hpp"
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
#line 1674 "inc/vcf/validator_detail_v44.hpp"
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
#line 1700 "inc/vcf/validator_detail_v44.hpp"
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
case 34:
#line 1722 "inc/vcf/validator_detail_v44.hpp"
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
case 37:
#line 1783 "inc/vcf/validator_detail_v44.hpp"
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
case 38:
#line 1811 "inc/vcf/validator_detail_v44.hpp"
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
case 39:
#line 1835 "inc/vcf/validator_detail_v44.hpp"
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
case 40:
#line 1857 "inc/vcf/validator_detail_v44.hpp"
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
case 41:
#line 1876 "inc/vcf/validator_detail_v44.hpp"
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
case 42:
#line 1896 "inc/vcf/validator_detail_v44.hpp"
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
case 43:
#line 1931 "inc/vcf/validator_detail_v44.hpp"
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
case 44:
#line 1958 "inc/vcf/validator_detail_v44.hpp"
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
case 45:
#line 1990 "inc/vcf/validator_detail_v44.hpp"
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
case 46:
#line 2011 "inc/vcf/validator_detail_v44.hpp"
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
case 47:
#line 2036 "inc/vcf/validator_detail_v44.hpp"
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
case 48:
#line 2071 "inc/vcf/validator_detail_v44.hpp"
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
case 49:
#line 2098 "inc/vcf/validator_detail_v44.hpp"
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
case 51:
#line 2141 "inc/vcf/validator_detail_v44.hpp"
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
case 52:
#line 2169 "inc/vcf/validator_detail_v44.hpp"
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
case 53:
#line 2195 "inc/vcf/validator_detail_v44.hpp"
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
case 54:
#line 2217 "inc/vcf/validator_detail_v44.hpp"
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
case 55:
#line 2257 "inc/vcf/validator_detail_v44.hpp"
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
case 56:
#line 2308 "inc/vcf/validator_detail_v44.hpp"
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
case 57:
#line 2359 "inc/vcf/validator_detail_v44.hpp"
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
case 58:
#line 2402 "inc/vcf/validator_detail_v44.hpp"
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
case 59:
#line 2432 "inc/vcf/validator_detail_v44.hpp"
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
case 60:
#line 2472 "inc/vcf/validator_detail_v44.hpp"
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
case 61:
#line 2502 "inc/vcf/validator_detail_v44.hpp"
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
case 62:
#line 2522 "inc/vcf/validator_detail_v44.hpp"
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
case 64:
#line 2563 "inc/vcf/validator_detail_v44.hpp"
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
case 65:
#line 2591 "inc/vcf/validator_detail_v44.hpp"
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
case 66:
#line 2613 "inc/vcf/validator_detail_v44.hpp"
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
case 67:
#line 2643 "inc/vcf/validator_detail_v44.hpp"
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
case 68:
#line 2694 "inc/vcf/validator_detail_v44.hpp"
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
case 69:
#line 2745 "inc/vcf/validator_detail_v44.hpp"
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
case 70:
#line 2788 "inc/vcf/validator_detail_v44.hpp"
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
case 71:
#line 2818 "inc/vcf/validator_detail_v44.hpp"
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
case 72:
#line 2848 "inc/vcf/validator_detail_v44.hpp"
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
case 73:
#line 2878 "inc/vcf/validator_detail_v44.hpp"
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
case 74:
#line 2902 "inc/vcf/validator_detail_v44.hpp"
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
case 75:
#line 2920 "inc/vcf/validator_detail_v44.hpp"
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
case 77:
#line 2947 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 60 )
		goto st78;
	goto tr126;
st78:
	if ( ++p == pe )
		goto _test_eof78;
case 78:
	if ( (*p) == 73 )
		goto st79;
	goto tr126;
st79:
	if ( ++p == pe )
		goto _test_eof79;
case 79:
	if ( (*p) == 68 )
		goto st80;
	goto tr126;
st80:
	if ( ++p == pe )
		goto _test_eof80;
case 80:
	if ( (*p) == 61 )
		goto st81;
	goto tr126;
st81:
	if ( ++p == pe )
		goto _test_eof81;
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
case 82:
#line 3019 "inc/vcf/validator_detail_v44.hpp"
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
case 83:
#line 3073 "inc/vcf/validator_detail_v44.hpp"
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
case 84:
#line 3094 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 95 )
		goto tr142;
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
case 85:
#line 3119 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 95 )
		goto st85;
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
case 86:
#line 3154 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
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
case 87:
#line 3181 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 34 )
		goto st88;
	goto tr126;
st88:
	if ( ++p == pe )
		goto _test_eof88;
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
case 89:
#line 3216 "inc/vcf/validator_detail_v44.hpp"
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
case 90:
#line 3244 "inc/vcf/validator_detail_v44.hpp"
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
case 91:
#line 3260 "inc/vcf/validator_detail_v44.hpp"
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
case 92:
#line 3286 "inc/vcf/validator_detail_v44.hpp"
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
case 93:
#line 3308 "inc/vcf/validator_detail_v44.hpp"
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
case 94:
#line 3338 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 34: goto tr153;
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
case 95:
#line 3389 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 34: goto tr153;
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
case 96:
#line 3440 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 34: goto tr153;
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
case 97:
#line 3483 "inc/vcf/validator_detail_v44.hpp"
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
case 98:
#line 3501 "inc/vcf/validator_detail_v44.hpp"
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
case 99:
#line 3531 "inc/vcf/validator_detail_v44.hpp"
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
case 100:
#line 3555 "inc/vcf/validator_detail_v44.hpp"
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
case 101:
#line 3574 "inc/vcf/validator_detail_v44.hpp"
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
case 102:
#line 3592 "inc/vcf/validator_detail_v44.hpp"
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
case 103:
#line 3610 "inc/vcf/validator_detail_v44.hpp"
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
case 104:
#line 3628 "inc/vcf/validator_detail_v44.hpp"
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
case 106:
#line 3655 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 60 )
		goto st107;
	goto tr172;
st107:
	if ( ++p == pe )
		goto _test_eof107;
case 107:
	if ( (*p) == 73 )
		goto st108;
	goto tr172;
st108:
	if ( ++p == pe )
		goto _test_eof108;
case 108:
	if ( (*p) == 68 )
		goto st109;
	goto tr172;
st109:
	if ( ++p == pe )
		goto _test_eof109;
case 109:
	if ( (*p) == 61 )
		goto st110;
	goto tr172;
st110:
	if ( ++p == pe )
		goto _test_eof110;
case 110:
	if ( (*p) == 95 )
		goto tr183;
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
case 111:
#line 3712 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 95 )
		goto st111;
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
case 112:
#line 3751 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 44: goto tr187;
		case 62: goto tr188;
		case 95: goto tr186;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
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
case 113:
#line 3779 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 95 )
		goto tr189;
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
case 114:
#line 3804 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 95 )
		goto st114;
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
case 115:
#line 3839 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
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
case 116:
#line 3866 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 34 )
		goto st117;
	goto tr172;
st117:
	if ( ++p == pe )
		goto _test_eof117;
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
case 118:
#line 3901 "inc/vcf/validator_detail_v44.hpp"
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
case 119:
#line 3929 "inc/vcf/validator_detail_v44.hpp"
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
case 120:
#line 3945 "inc/vcf/validator_detail_v44.hpp"
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
case 121:
#line 3971 "inc/vcf/validator_detail_v44.hpp"
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
case 122:
#line 3993 "inc/vcf/validator_detail_v44.hpp"
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
case 123:
#line 4023 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 34: goto tr200;
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
case 124:
#line 4074 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 34: goto tr200;
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
case 125:
#line 4125 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 34: goto tr200;
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
case 126:
#line 4168 "inc/vcf/validator_detail_v44.hpp"
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
case 127:
#line 4186 "inc/vcf/validator_detail_v44.hpp"
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
case 128:
#line 4216 "inc/vcf/validator_detail_v44.hpp"
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
case 129:
#line 4236 "inc/vcf/validator_detail_v44.hpp"
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
case 130:
#line 4254 "inc/vcf/validator_detail_v44.hpp"
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
case 131:
#line 4272 "inc/vcf/validator_detail_v44.hpp"
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
case 132:
#line 4290 "inc/vcf/validator_detail_v44.hpp"
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
case 134:
#line 4317 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 60 )
		goto st135;
	goto tr216;
st135:
	if ( ++p == pe )
		goto _test_eof135;
case 135:
	if ( (*p) == 73 )
		goto st136;
	goto tr216;
st136:
	if ( ++p == pe )
		goto _test_eof136;
case 136:
	if ( (*p) == 68 )
		goto st137;
	goto tr216;
st137:
	if ( ++p == pe )
		goto _test_eof137;
case 137:
	if ( (*p) == 61 )
		goto st138;
	goto tr216;
st138:
	if ( ++p == pe )
		goto _test_eof138;
case 138:
	if ( (*p) == 95 )
		goto tr227;
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
case 139:
#line 4374 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 95 )
		goto st139;
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
case 140:
#line 4413 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 44: goto tr231;
		case 95: goto tr230;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
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
case 141:
#line 4440 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 78 )
		goto st142;
	goto tr216;
st142:
	if ( ++p == pe )
		goto _test_eof142;
case 142:
	if ( (*p) == 117 )
		goto st143;
	goto tr216;
st143:
	if ( ++p == pe )
		goto _test_eof143;
case 143:
	if ( (*p) == 109 )
		goto st144;
	goto tr216;
st144:
	if ( ++p == pe )
		goto _test_eof144;
case 144:
	if ( (*p) == 98 )
		goto st145;
	goto tr216;
st145:
	if ( ++p == pe )
		goto _test_eof145;
case 145:
	if ( (*p) == 101 )
		goto st146;
	goto tr216;
st146:
	if ( ++p == pe )
		goto _test_eof146;
case 146:
	if ( (*p) == 114 )
		goto st147;
	goto tr216;
st147:
	if ( ++p == pe )
		goto _test_eof147;
case 147:
	if ( (*p) == 61 )
		goto st148;
	goto tr216;
st148:
	if ( ++p == pe )
		goto _test_eof148;
case 148:
	switch( (*p) ) {
		case 46: goto tr240;
		case 65: goto tr240;
		case 71: goto tr240;
		case 80: goto tr240;
		case 82: goto tr240;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr241;
	goto tr239;
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
case 149:
#line 4518 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 44 )
		goto tr242;
	goto tr239;
tr242:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st150;
st150:
	if ( ++p == pe )
		goto _test_eof150;
case 150:
#line 4532 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 84 )
		goto st151;
	goto tr216;
st151:
	if ( ++p == pe )
		goto _test_eof151;
case 151:
	if ( (*p) == 121 )
		goto st152;
	goto tr216;
st152:
	if ( ++p == pe )
		goto _test_eof152;
case 152:
	if ( (*p) == 112 )
		goto st153;
	goto tr216;
st153:
	if ( ++p == pe )
		goto _test_eof153;
case 153:
	if ( (*p) == 101 )
		goto st154;
	goto tr216;
st154:
	if ( ++p == pe )
		goto _test_eof154;
case 154:
	if ( (*p) == 61 )
		goto st155;
	goto tr216;
st155:
	if ( ++p == pe )
		goto _test_eof155;
case 155:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr249;
	} else if ( (*p) >= 65 )
		goto tr249;
	goto tr248;
tr251:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st156;
tr249:
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
case 156:
#line 4598 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 44 )
		goto tr250;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr251;
	} else if ( (*p) >= 65 )
		goto tr251;
	goto tr248;
tr250:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st157;
st157:
	if ( ++p == pe )
		goto _test_eof157;
case 157:
#line 4617 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 68 )
		goto st158;
	goto tr216;
st158:
	if ( ++p == pe )
		goto _test_eof158;
case 158:
	if ( (*p) == 101 )
		goto st159;
	goto tr216;
st159:
	if ( ++p == pe )
		goto _test_eof159;
case 159:
	if ( (*p) == 115 )
		goto st160;
	goto tr216;
st160:
	if ( ++p == pe )
		goto _test_eof160;
case 160:
	if ( (*p) == 99 )
		goto st161;
	goto tr216;
st161:
	if ( ++p == pe )
		goto _test_eof161;
case 161:
	if ( (*p) == 114 )
		goto st162;
	goto tr216;
st162:
	if ( ++p == pe )
		goto _test_eof162;
case 162:
	if ( (*p) == 105 )
		goto st163;
	goto tr216;
st163:
	if ( ++p == pe )
		goto _test_eof163;
case 163:
	if ( (*p) == 112 )
		goto st164;
	goto tr216;
st164:
	if ( ++p == pe )
		goto _test_eof164;
case 164:
	if ( (*p) == 116 )
		goto st165;
	goto tr216;
st165:
	if ( ++p == pe )
		goto _test_eof165;
case 165:
	if ( (*p) == 105 )
		goto st166;
	goto tr216;
st166:
	if ( ++p == pe )
		goto _test_eof166;
case 166:
	if ( (*p) == 111 )
		goto st167;
	goto tr216;
st167:
	if ( ++p == pe )
		goto _test_eof167;
case 167:
	if ( (*p) == 110 )
		goto st168;
	goto tr216;
st168:
	if ( ++p == pe )
		goto _test_eof168;
case 168:
	if ( (*p) == 61 )
		goto st169;
	goto tr216;
st169:
	if ( ++p == pe )
		goto _test_eof169;
case 169:
	if ( (*p) == 34 )
		goto tr264;
	goto tr216;
tr264:
#line 156 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Description");
    }
	goto st170;
st170:
	if ( ++p == pe )
		goto _test_eof170;
case 170:
#line 4715 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 34: goto tr267;
		case 92: goto tr268;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr266;
	goto tr265;
tr266:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st171;
tr269:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st171;
st171:
	if ( ++p == pe )
		goto _test_eof171;
case 171:
#line 4743 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 34: goto tr270;
		case 92: goto tr271;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr269;
	goto tr265;
tr267:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st172;
tr270:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st172;
st172:
	if ( ++p == pe )
		goto _test_eof172;
case 172:
#line 4771 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 44: goto st173;
		case 62: goto st187;
	}
	goto tr265;
st173:
	if ( ++p == pe )
		goto _test_eof173;
case 173:
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
	goto tr226;
tr274:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st174;
st174:
	if ( ++p == pe )
		goto _test_eof174;
case 174:
#line 4805 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 95 )
		goto st174;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st174;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr277;
		} else if ( (*p) >= 65 )
			goto tr277;
	} else
		goto tr277;
	goto tr226;
tr275:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st175;
tr277:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st175;
st175:
	if ( ++p == pe )
		goto _test_eof175;
case 175:
#line 4840 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr278;
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
	goto tr226;
tr278:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st176;
st176:
	if ( ++p == pe )
		goto _test_eof176;
case 176:
#line 4867 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 34 )
		goto st177;
	goto tr216;
st177:
	if ( ++p == pe )
		goto _test_eof177;
case 177:
	switch( (*p) ) {
		case 34: goto tr267;
		case 92: goto tr281;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr280;
	goto tr265;
tr280:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st178;
tr282:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st178;
st178:
	if ( ++p == pe )
		goto _test_eof178;
case 178:
#line 4902 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 34: goto tr270;
		case 92: goto tr283;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr282;
	goto tr265;
tr281:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st179;
tr283:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st179;
st179:
	if ( ++p == pe )
		goto _test_eof179;
case 179:
#line 4930 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 34: goto tr284;
		case 92: goto tr283;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr282;
	goto tr265;
tr284:
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
case 180:
#line 4952 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 34: goto tr270;
		case 44: goto tr285;
		case 62: goto tr286;
		case 92: goto tr283;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr282;
	goto tr265;
tr294:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st181;
tr285:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st181;
st181:
	if ( ++p == pe )
		goto _test_eof181;
case 181:
#line 4982 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 34: goto tr270;
		case 47: goto tr282;
		case 92: goto tr283;
		case 95: goto tr288;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr282;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr289;
		} else
			goto tr288;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr289;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr282;
			} else if ( (*p) >= 97 )
				goto tr289;
		} else
			goto tr282;
	} else
		goto tr282;
	goto tr287;
tr288:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st182;
tr290:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st182;
st182:
	if ( ++p == pe )
		goto _test_eof182;
case 182:
#line 5033 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 34: goto tr270;
		case 47: goto tr282;
		case 92: goto tr283;
		case 95: goto tr290;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr282;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr291;
		} else
			goto tr290;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr291;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr282;
			} else if ( (*p) >= 97 )
				goto tr291;
		} else
			goto tr282;
	} else
		goto tr282;
	goto tr287;
tr289:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st183;
tr291:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st183;
st183:
	if ( ++p == pe )
		goto _test_eof183;
case 183:
#line 5084 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 34: goto tr270;
		case 47: goto tr282;
		case 61: goto tr292;
		case 92: goto tr283;
		case 95: goto tr291;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr282;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr282;
		} else
			goto tr291;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr282;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr282;
		} else
			goto tr291;
	} else
		goto tr291;
	goto tr287;
tr292:
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
case 184:
#line 5127 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 34: goto tr293;
		case 92: goto tr283;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr282;
	goto tr265;
tr293:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st185;
st185:
	if ( ++p == pe )
		goto _test_eof185;
case 185:
#line 5145 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 34: goto tr267;
		case 44: goto tr294;
		case 62: goto tr295;
		case 92: goto tr281;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr280;
	goto tr265;
tr295:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st186;
tr286:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st186;
st186:
	if ( ++p == pe )
		goto _test_eof186;
case 186:
#line 5175 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
		case 34: goto tr270;
		case 92: goto tr283;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr282;
	goto tr265;
st187:
	if ( ++p == pe )
		goto _test_eof187;
case 187:
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
	}
	goto tr216;
tr268:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st188;
tr271:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st188;
st188:
	if ( ++p == pe )
		goto _test_eof188;
case 188:
#line 5214 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 34: goto tr296;
		case 92: goto tr271;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr269;
	goto tr265;
tr296:
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
case 189:
#line 5236 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 34: goto tr270;
		case 44: goto tr297;
		case 62: goto tr298;
		case 92: goto tr271;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr269;
	goto tr265;
tr297:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st190;
st190:
	if ( ++p == pe )
		goto _test_eof190;
case 190:
#line 5256 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 34: goto tr270;
		case 47: goto tr269;
		case 92: goto tr271;
		case 95: goto tr300;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr269;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr301;
		} else
			goto tr300;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr301;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr269;
			} else if ( (*p) >= 97 )
				goto tr301;
		} else
			goto tr269;
	} else
		goto tr269;
	goto tr299;
tr302:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st191;
tr300:
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
case 191:
#line 5307 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 34: goto tr270;
		case 47: goto tr269;
		case 92: goto tr271;
		case 95: goto tr302;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr269;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr303;
		} else
			goto tr302;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr303;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr269;
			} else if ( (*p) >= 97 )
				goto tr303;
		} else
			goto tr269;
	} else
		goto tr269;
	goto tr299;
tr303:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st192;
tr301:
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
case 192:
#line 5358 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 34: goto tr270;
		case 47: goto tr269;
		case 61: goto tr304;
		case 92: goto tr271;
		case 95: goto tr303;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr269;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr269;
		} else
			goto tr303;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr269;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr269;
		} else
			goto tr303;
	} else
		goto tr303;
	goto tr299;
tr304:
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
case 193:
#line 5401 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 34: goto tr293;
		case 92: goto tr271;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr269;
	goto tr265;
tr298:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st194;
st194:
	if ( ++p == pe )
		goto _test_eof194;
case 194:
#line 5419 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
		case 34: goto tr270;
		case 92: goto tr271;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr269;
	goto tr265;
tr305:
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
case 195:
#line 5453 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 44 )
		goto tr242;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr305;
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
	goto st196;
st196:
	if ( ++p == pe )
		goto _test_eof196;
case 196:
#line 5473 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 78: goto tr307;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr306;
tr307:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st197;
st197:
	if ( ++p == pe )
		goto _test_eof197;
case 197:
#line 5491 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 70: goto tr308;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr306;
tr308:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st198;
st198:
	if ( ++p == pe )
		goto _test_eof198;
case 198:
#line 5509 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 79: goto st199;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr306;
st199:
	if ( ++p == pe )
		goto _test_eof199;
case 199:
	if ( (*p) == 61 )
		goto tr310;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr306;
tr310:
#line 128 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "INFO");
    }
	goto st200;
st200:
	if ( ++p == pe )
		goto _test_eof200;
case 200:
#line 5536 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 60 )
		goto st201;
	goto tr306;
st201:
	if ( ++p == pe )
		goto _test_eof201;
case 201:
	if ( (*p) == 73 )
		goto st202;
	goto tr306;
st202:
	if ( ++p == pe )
		goto _test_eof202;
case 202:
	if ( (*p) == 68 )
		goto st203;
	goto tr306;
st203:
	if ( ++p == pe )
		goto _test_eof203;
case 203:
	if ( (*p) == 61 )
		goto st204;
	goto tr306;
st204:
	if ( ++p == pe )
		goto _test_eof204;
case 204:
	if ( (*p) == 95 )
		goto tr316;
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
	goto tr315;
tr316:
#line 144 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st205;
st205:
	if ( ++p == pe )
		goto _test_eof205;
case 205:
#line 5593 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 95 )
		goto st205;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st205;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr319;
		} else if ( (*p) >= 65 )
			goto tr319;
	} else
		goto tr319;
	goto tr315;
tr319:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st206;
tr317:
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
	goto st206;
st206:
	if ( ++p == pe )
		goto _test_eof206;
case 206:
#line 5632 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 44: goto tr320;
		case 95: goto tr319;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr319;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr319;
		} else if ( (*p) >= 65 )
			goto tr319;
	} else
		goto tr319;
	goto tr315;
tr320:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st207;
st207:
	if ( ++p == pe )
		goto _test_eof207;
case 207:
#line 5659 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 78 )
		goto st208;
	goto tr306;
st208:
	if ( ++p == pe )
		goto _test_eof208;
case 208:
	if ( (*p) == 117 )
		goto st209;
	goto tr306;
st209:
	if ( ++p == pe )
		goto _test_eof209;
case 209:
	if ( (*p) == 109 )
		goto st210;
	goto tr306;
st210:
	if ( ++p == pe )
		goto _test_eof210;
case 210:
	if ( (*p) == 98 )
		goto st211;
	goto tr306;
st211:
	if ( ++p == pe )
		goto _test_eof211;
case 211:
	if ( (*p) == 101 )
		goto st212;
	goto tr306;
st212:
	if ( ++p == pe )
		goto _test_eof212;
case 212:
	if ( (*p) == 114 )
		goto st213;
	goto tr306;
st213:
	if ( ++p == pe )
		goto _test_eof213;
case 213:
	if ( (*p) == 61 )
		goto st214;
	goto tr306;
st214:
	if ( ++p == pe )
		goto _test_eof214;
case 214:
	switch( (*p) ) {
		case 46: goto tr329;
		case 65: goto tr329;
		case 71: goto tr329;
		case 82: goto tr329;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr330;
	goto tr328;
tr329:
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
#line 5736 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 44 )
		goto tr331;
	goto tr328;
tr331:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st216;
st216:
	if ( ++p == pe )
		goto _test_eof216;
case 216:
#line 5750 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 84 )
		goto st217;
	goto tr306;
st217:
	if ( ++p == pe )
		goto _test_eof217;
case 217:
	if ( (*p) == 121 )
		goto st218;
	goto tr306;
st218:
	if ( ++p == pe )
		goto _test_eof218;
case 218:
	if ( (*p) == 112 )
		goto st219;
	goto tr306;
st219:
	if ( ++p == pe )
		goto _test_eof219;
case 219:
	if ( (*p) == 101 )
		goto st220;
	goto tr306;
st220:
	if ( ++p == pe )
		goto _test_eof220;
case 220:
	if ( (*p) == 61 )
		goto st221;
	goto tr306;
st221:
	if ( ++p == pe )
		goto _test_eof221;
case 221:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr338;
	} else if ( (*p) >= 65 )
		goto tr338;
	goto tr337;
tr340:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st222;
tr338:
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
	goto st222;
st222:
	if ( ++p == pe )
		goto _test_eof222;
case 222:
#line 5816 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 44 )
		goto tr339;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr340;
	} else if ( (*p) >= 65 )
		goto tr340;
	goto tr337;
tr339:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st223;
st223:
	if ( ++p == pe )
		goto _test_eof223;
case 223:
#line 5835 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 68 )
		goto st224;
	goto tr306;
st224:
	if ( ++p == pe )
		goto _test_eof224;
case 224:
	if ( (*p) == 101 )
		goto st225;
	goto tr306;
st225:
	if ( ++p == pe )
		goto _test_eof225;
case 225:
	if ( (*p) == 115 )
		goto st226;
	goto tr306;
st226:
	if ( ++p == pe )
		goto _test_eof226;
case 226:
	if ( (*p) == 99 )
		goto st227;
	goto tr306;
st227:
	if ( ++p == pe )
		goto _test_eof227;
case 227:
	if ( (*p) == 114 )
		goto st228;
	goto tr306;
st228:
	if ( ++p == pe )
		goto _test_eof228;
case 228:
	if ( (*p) == 105 )
		goto st229;
	goto tr306;
st229:
	if ( ++p == pe )
		goto _test_eof229;
case 229:
	if ( (*p) == 112 )
		goto st230;
	goto tr306;
st230:
	if ( ++p == pe )
		goto _test_eof230;
case 230:
	if ( (*p) == 116 )
		goto st231;
	goto tr306;
st231:
	if ( ++p == pe )
		goto _test_eof231;
case 231:
	if ( (*p) == 105 )
		goto st232;
	goto tr306;
st232:
	if ( ++p == pe )
		goto _test_eof232;
case 232:
	if ( (*p) == 111 )
		goto st233;
	goto tr306;
st233:
	if ( ++p == pe )
		goto _test_eof233;
case 233:
	if ( (*p) == 110 )
		goto st234;
	goto tr306;
st234:
	if ( ++p == pe )
		goto _test_eof234;
case 234:
	if ( (*p) == 61 )
		goto st235;
	goto tr306;
st235:
	if ( ++p == pe )
		goto _test_eof235;
case 235:
	if ( (*p) == 34 )
		goto tr353;
	goto tr306;
tr353:
#line 156 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Description");
    }
	goto st236;
st236:
	if ( ++p == pe )
		goto _test_eof236;
case 236:
#line 5933 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 34: goto tr356;
		case 92: goto tr357;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr355;
	goto tr354;
tr355:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st237;
tr358:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st237;
st237:
	if ( ++p == pe )
		goto _test_eof237;
case 237:
#line 5961 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 34: goto tr359;
		case 92: goto tr360;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr358;
	goto tr354;
tr356:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st238;
tr359:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st238;
st238:
	if ( ++p == pe )
		goto _test_eof238;
case 238:
#line 5989 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 44: goto st239;
		case 62: goto st253;
	}
	goto tr354;
st239:
	if ( ++p == pe )
		goto _test_eof239;
case 239:
	if ( (*p) == 95 )
		goto tr363;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr363;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr364;
		} else if ( (*p) >= 65 )
			goto tr364;
	} else
		goto tr364;
	goto tr315;
tr363:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st240;
st240:
	if ( ++p == pe )
		goto _test_eof240;
case 240:
#line 6023 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 95 )
		goto st240;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st240;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr366;
		} else if ( (*p) >= 65 )
			goto tr366;
	} else
		goto tr366;
	goto tr315;
tr364:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st241;
tr366:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st241;
st241:
	if ( ++p == pe )
		goto _test_eof241;
case 241:
#line 6058 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr367;
		case 95: goto tr366;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr366;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr366;
		} else if ( (*p) >= 65 )
			goto tr366;
	} else
		goto tr366;
	goto tr315;
tr367:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st242;
st242:
	if ( ++p == pe )
		goto _test_eof242;
case 242:
#line 6085 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 34 )
		goto st243;
	goto tr306;
st243:
	if ( ++p == pe )
		goto _test_eof243;
case 243:
	switch( (*p) ) {
		case 34: goto tr356;
		case 92: goto tr370;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr369;
	goto tr354;
tr369:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st244;
tr371:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st244;
st244:
	if ( ++p == pe )
		goto _test_eof244;
case 244:
#line 6120 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 34: goto tr359;
		case 92: goto tr372;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr371;
	goto tr354;
tr370:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st245;
tr372:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st245;
st245:
	if ( ++p == pe )
		goto _test_eof245;
case 245:
#line 6148 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 34: goto tr373;
		case 92: goto tr372;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr371;
	goto tr354;
tr373:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st246;
st246:
	if ( ++p == pe )
		goto _test_eof246;
case 246:
#line 6170 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 34: goto tr359;
		case 44: goto tr374;
		case 62: goto tr375;
		case 92: goto tr372;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr371;
	goto tr354;
tr383:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st247;
tr374:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st247;
st247:
	if ( ++p == pe )
		goto _test_eof247;
case 247:
#line 6200 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 34: goto tr359;
		case 47: goto tr371;
		case 92: goto tr372;
		case 95: goto tr377;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr371;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr378;
		} else
			goto tr377;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr378;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr371;
			} else if ( (*p) >= 97 )
				goto tr378;
		} else
			goto tr371;
	} else
		goto tr371;
	goto tr376;
tr377:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st248;
tr379:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st248;
st248:
	if ( ++p == pe )
		goto _test_eof248;
case 248:
#line 6251 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 34: goto tr359;
		case 47: goto tr371;
		case 92: goto tr372;
		case 95: goto tr379;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr371;
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
					goto tr371;
			} else if ( (*p) >= 97 )
				goto tr380;
		} else
			goto tr371;
	} else
		goto tr371;
	goto tr376;
tr378:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st249;
tr380:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st249;
st249:
	if ( ++p == pe )
		goto _test_eof249;
case 249:
#line 6302 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 34: goto tr359;
		case 47: goto tr371;
		case 61: goto tr381;
		case 92: goto tr372;
		case 95: goto tr380;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr371;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr371;
		} else
			goto tr380;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr371;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr371;
		} else
			goto tr380;
	} else
		goto tr380;
	goto tr376;
tr381:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
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
#line 6345 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 34: goto tr382;
		case 92: goto tr372;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr371;
	goto tr354;
tr382:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st251;
st251:
	if ( ++p == pe )
		goto _test_eof251;
case 251:
#line 6363 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 34: goto tr356;
		case 44: goto tr383;
		case 62: goto tr384;
		case 92: goto tr370;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr369;
	goto tr354;
tr384:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st252;
tr375:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st252;
st252:
	if ( ++p == pe )
		goto _test_eof252;
case 252:
#line 6393 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
		case 34: goto tr359;
		case 92: goto tr372;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr371;
	goto tr354;
st253:
	if ( ++p == pe )
		goto _test_eof253;
case 253:
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
	}
	goto tr306;
tr357:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st254;
tr360:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st254;
st254:
	if ( ++p == pe )
		goto _test_eof254;
case 254:
#line 6432 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 34: goto tr385;
		case 92: goto tr360;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr358;
	goto tr354;
tr385:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st255;
st255:
	if ( ++p == pe )
		goto _test_eof255;
case 255:
#line 6454 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 34: goto tr359;
		case 44: goto tr386;
		case 62: goto tr387;
		case 92: goto tr360;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr358;
	goto tr354;
tr386:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st256;
st256:
	if ( ++p == pe )
		goto _test_eof256;
case 256:
#line 6474 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 34: goto tr359;
		case 47: goto tr358;
		case 92: goto tr360;
		case 95: goto tr389;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr358;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr390;
		} else
			goto tr389;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr390;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr358;
			} else if ( (*p) >= 97 )
				goto tr390;
		} else
			goto tr358;
	} else
		goto tr358;
	goto tr388;
tr391:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st257;
tr389:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st257;
st257:
	if ( ++p == pe )
		goto _test_eof257;
case 257:
#line 6525 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 34: goto tr359;
		case 47: goto tr358;
		case 92: goto tr360;
		case 95: goto tr391;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr358;
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
					goto tr358;
			} else if ( (*p) >= 97 )
				goto tr392;
		} else
			goto tr358;
	} else
		goto tr358;
	goto tr388;
tr392:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st258;
tr390:
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
case 258:
#line 6576 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 34: goto tr359;
		case 47: goto tr358;
		case 61: goto tr393;
		case 92: goto tr360;
		case 95: goto tr392;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr358;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr358;
		} else
			goto tr392;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr358;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr358;
		} else
			goto tr392;
	} else
		goto tr392;
	goto tr388;
tr393:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st259;
st259:
	if ( ++p == pe )
		goto _test_eof259;
case 259:
#line 6619 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 34: goto tr382;
		case 92: goto tr360;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr358;
	goto tr354;
tr387:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st260;
st260:
	if ( ++p == pe )
		goto _test_eof260;
case 260:
#line 6637 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
		case 34: goto tr359;
		case 92: goto tr360;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr358;
	goto tr354;
tr394:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st261;
tr330:
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
	goto st261;
st261:
	if ( ++p == pe )
		goto _test_eof261;
case 261:
#line 6671 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 44 )
		goto tr331;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr394;
	goto tr328;
tr34:
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
#line 6691 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 69: goto tr396;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr395;
tr396:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st263;
st263:
	if ( ++p == pe )
		goto _test_eof263;
case 263:
#line 6709 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 84: goto tr397;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr395;
tr397:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st264;
st264:
	if ( ++p == pe )
		goto _test_eof264;
case 264:
#line 6727 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 65: goto st265;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr395;
st265:
	if ( ++p == pe )
		goto _test_eof265;
case 265:
	if ( (*p) == 61 )
		goto tr399;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr395;
tr399:
#line 168 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "META");
    }
	goto st266;
st266:
	if ( ++p == pe )
		goto _test_eof266;
case 266:
#line 6754 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 60 )
		goto st267;
	goto tr395;
st267:
	if ( ++p == pe )
		goto _test_eof267;
case 267:
	if ( (*p) == 73 )
		goto st268;
	goto tr395;
st268:
	if ( ++p == pe )
		goto _test_eof268;
case 268:
	if ( (*p) == 68 )
		goto st269;
	goto tr395;
st269:
	if ( ++p == pe )
		goto _test_eof269;
case 269:
	if ( (*p) == 61 )
		goto st270;
	goto tr395;
st270:
	if ( ++p == pe )
		goto _test_eof270;
case 270:
	if ( (*p) == 95 )
		goto tr405;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr405;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr406;
		} else if ( (*p) >= 65 )
			goto tr406;
	} else
		goto tr406;
	goto tr404;
tr405:
#line 144 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st271;
st271:
	if ( ++p == pe )
		goto _test_eof271;
case 271:
#line 6811 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 95 )
		goto st271;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st271;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr408;
		} else if ( (*p) >= 65 )
			goto tr408;
	} else
		goto tr408;
	goto tr404;
tr408:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st272;
tr406:
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
	goto st272;
st272:
	if ( ++p == pe )
		goto _test_eof272;
case 272:
#line 6850 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 44: goto tr409;
		case 95: goto tr408;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr408;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr408;
		} else if ( (*p) >= 65 )
			goto tr408;
	} else
		goto tr408;
	goto tr404;
tr409:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st273;
st273:
	if ( ++p == pe )
		goto _test_eof273;
case 273:
#line 6877 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 78 )
		goto st274;
	goto tr395;
st274:
	if ( ++p == pe )
		goto _test_eof274;
case 274:
	if ( (*p) == 117 )
		goto st275;
	goto tr395;
st275:
	if ( ++p == pe )
		goto _test_eof275;
case 275:
	if ( (*p) == 109 )
		goto st276;
	goto tr395;
st276:
	if ( ++p == pe )
		goto _test_eof276;
case 276:
	if ( (*p) == 98 )
		goto st277;
	goto tr395;
st277:
	if ( ++p == pe )
		goto _test_eof277;
case 277:
	if ( (*p) == 101 )
		goto st278;
	goto tr395;
st278:
	if ( ++p == pe )
		goto _test_eof278;
case 278:
	if ( (*p) == 114 )
		goto st279;
	goto tr395;
st279:
	if ( ++p == pe )
		goto _test_eof279;
case 279:
	if ( (*p) == 61 )
		goto st280;
	goto tr395;
st280:
	if ( ++p == pe )
		goto _test_eof280;
case 280:
	if ( (*p) == 46 )
		goto tr418;
	goto tr417;
tr418:
#line 148 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Number");
    }
	goto st281;
st281:
	if ( ++p == pe )
		goto _test_eof281;
case 281:
#line 6940 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 44 )
		goto st282;
	goto tr417;
st282:
	if ( ++p == pe )
		goto _test_eof282;
case 282:
	if ( (*p) == 84 )
		goto st283;
	goto tr395;
st283:
	if ( ++p == pe )
		goto _test_eof283;
case 283:
	if ( (*p) == 121 )
		goto st284;
	goto tr395;
st284:
	if ( ++p == pe )
		goto _test_eof284;
case 284:
	if ( (*p) == 112 )
		goto st285;
	goto tr395;
st285:
	if ( ++p == pe )
		goto _test_eof285;
case 285:
	if ( (*p) == 101 )
		goto st286;
	goto tr395;
st286:
	if ( ++p == pe )
		goto _test_eof286;
case 286:
	if ( (*p) == 61 )
		goto st287;
	goto tr395;
st287:
	if ( ++p == pe )
		goto _test_eof287;
case 287:
	if ( (*p) == 83 )
		goto tr426;
	goto tr425;
tr426:
#line 152 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Type");
    }
	goto st288;
st288:
	if ( ++p == pe )
		goto _test_eof288;
case 288:
#line 6996 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 116 )
		goto st289;
	goto tr425;
st289:
	if ( ++p == pe )
		goto _test_eof289;
case 289:
	if ( (*p) == 114 )
		goto st290;
	goto tr425;
st290:
	if ( ++p == pe )
		goto _test_eof290;
case 290:
	if ( (*p) == 105 )
		goto st291;
	goto tr425;
st291:
	if ( ++p == pe )
		goto _test_eof291;
case 291:
	if ( (*p) == 110 )
		goto st292;
	goto tr425;
st292:
	if ( ++p == pe )
		goto _test_eof292;
case 292:
	if ( (*p) == 103 )
		goto st293;
	goto tr425;
st293:
	if ( ++p == pe )
		goto _test_eof293;
case 293:
	if ( (*p) == 44 )
		goto st294;
	goto tr425;
st294:
	if ( ++p == pe )
		goto _test_eof294;
case 294:
	if ( (*p) == 86 )
		goto st295;
	goto tr395;
st295:
	if ( ++p == pe )
		goto _test_eof295;
case 295:
	if ( (*p) == 97 )
		goto st296;
	goto tr395;
st296:
	if ( ++p == pe )
		goto _test_eof296;
case 296:
	if ( (*p) == 108 )
		goto st297;
	goto tr395;
st297:
	if ( ++p == pe )
		goto _test_eof297;
case 297:
	if ( (*p) == 117 )
		goto st298;
	goto tr395;
st298:
	if ( ++p == pe )
		goto _test_eof298;
case 298:
	if ( (*p) == 101 )
		goto st299;
	goto tr395;
st299:
	if ( ++p == pe )
		goto _test_eof299;
case 299:
	if ( (*p) == 115 )
		goto st300;
	goto tr395;
st300:
	if ( ++p == pe )
		goto _test_eof300;
case 300:
	if ( (*p) == 61 )
		goto st301;
	goto tr395;
st301:
	if ( ++p == pe )
		goto _test_eof301;
case 301:
	if ( (*p) == 91 )
		goto tr440;
	goto tr395;
tr440:
#line 172 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Values");
    }
	goto st302;
st302:
	if ( ++p == pe )
		goto _test_eof302;
case 302:
#line 7101 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 61 )
		goto tr441;
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr441;
	} else if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr441;
	} else
		goto tr441;
	goto tr395;
tr441:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st303;
tr443:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st303;
st303:
	if ( ++p == pe )
		goto _test_eof303;
case 303:
#line 7133 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 44: goto tr444;
		case 61: goto tr443;
		case 93: goto tr445;
	}
	if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr443;
	} else if ( (*p) >= 33 )
		goto tr443;
	goto tr442;
tr444:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st304;
st304:
	if ( ++p == pe )
		goto _test_eof304;
case 304:
#line 7155 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 32: goto tr446;
		case 61: goto tr443;
	}
	if ( (*p) < 33 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr446;
	} else if ( (*p) > 43 ) {
		if ( (*p) > 59 ) {
			if ( 63 <= (*p) && (*p) <= 126 )
				goto tr443;
		} else if ( (*p) >= 45 )
			goto tr443;
	} else
		goto tr443;
	goto tr395;
tr446:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st305;
st305:
	if ( ++p == pe )
		goto _test_eof305;
case 305:
#line 7182 "inc/vcf/validator_detail_v44.hpp"
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
	goto tr395;
tr445:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st306;
st306:
	if ( ++p == pe )
		goto _test_eof306;
case 306:
#line 7208 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 44: goto tr444;
		case 62: goto st307;
		case 93: goto tr445;
	}
	if ( (*p) > 59 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr443;
	} else if ( (*p) >= 33 )
		goto tr443;
	goto tr442;
st307:
	if ( ++p == pe )
		goto _test_eof307;
case 307:
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
	}
	goto tr395;
tr35:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st308;
st308:
	if ( ++p == pe )
		goto _test_eof308;
case 308:
#line 7243 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 69: goto tr449;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr448;
tr449:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st309;
st309:
	if ( ++p == pe )
		goto _test_eof309;
case 309:
#line 7261 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 68: goto tr450;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr448;
tr450:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st310;
st310:
	if ( ++p == pe )
		goto _test_eof310;
case 310:
#line 7279 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 73: goto tr451;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr448;
tr451:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st311;
st311:
	if ( ++p == pe )
		goto _test_eof311;
case 311:
#line 7297 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 71: goto tr452;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr448;
tr452:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st312;
st312:
	if ( ++p == pe )
		goto _test_eof312;
case 312:
#line 7315 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 82: goto tr453;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr448;
tr453:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st313;
st313:
	if ( ++p == pe )
		goto _test_eof313;
case 313:
#line 7333 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 69: goto tr454;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr448;
tr454:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st314;
st314:
	if ( ++p == pe )
		goto _test_eof314;
case 314:
#line 7351 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 69: goto st315;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr448;
st315:
	if ( ++p == pe )
		goto _test_eof315;
case 315:
	if ( (*p) == 61 )
		goto tr456;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr448;
tr456:
#line 132 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "PEDIGREE");
    }
	goto st316;
st316:
	if ( ++p == pe )
		goto _test_eof316;
case 316:
#line 7378 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 60 )
		goto st317;
	goto tr448;
st317:
	if ( ++p == pe )
		goto _test_eof317;
case 317:
	if ( (*p) == 73 )
		goto st318;
	goto tr448;
st318:
	if ( ++p == pe )
		goto _test_eof318;
case 318:
	if ( (*p) == 68 )
		goto st319;
	goto tr448;
st319:
	if ( ++p == pe )
		goto _test_eof319;
case 319:
	if ( (*p) == 61 )
		goto st320;
	goto tr448;
st320:
	if ( ++p == pe )
		goto _test_eof320;
case 320:
	if ( (*p) == 95 )
		goto tr462;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr462;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr463;
		} else if ( (*p) >= 65 )
			goto tr463;
	} else
		goto tr463;
	goto tr461;
tr462:
#line 144 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st321;
st321:
	if ( ++p == pe )
		goto _test_eof321;
case 321:
#line 7435 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 95 )
		goto st321;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st321;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr465;
		} else if ( (*p) >= 65 )
			goto tr465;
	} else
		goto tr465;
	goto tr461;
tr465:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st322;
tr463:
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
	goto st322;
st322:
	if ( ++p == pe )
		goto _test_eof322;
case 322:
#line 7474 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 44: goto tr466;
		case 95: goto tr465;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr465;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr465;
		} else if ( (*p) >= 65 )
			goto tr465;
	} else
		goto tr465;
	goto tr461;
tr466:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st323;
st323:
	if ( ++p == pe )
		goto _test_eof323;
case 323:
#line 7501 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 70: goto st324;
		case 78: goto tr469;
		case 79: goto st354;
	}
	goto tr467;
st324:
	if ( ++p == pe )
		goto _test_eof324;
case 324:
	if ( (*p) == 97 )
		goto st325;
	goto tr448;
st325:
	if ( ++p == pe )
		goto _test_eof325;
case 325:
	if ( (*p) == 116 )
		goto st326;
	goto tr448;
st326:
	if ( ++p == pe )
		goto _test_eof326;
case 326:
	if ( (*p) == 104 )
		goto st327;
	goto tr448;
st327:
	if ( ++p == pe )
		goto _test_eof327;
case 327:
	if ( (*p) == 101 )
		goto st328;
	goto tr448;
st328:
	if ( ++p == pe )
		goto _test_eof328;
case 328:
	if ( (*p) == 114 )
		goto st329;
	goto tr448;
st329:
	if ( ++p == pe )
		goto _test_eof329;
case 329:
	if ( (*p) == 61 )
		goto st330;
	goto tr448;
st330:
	if ( ++p == pe )
		goto _test_eof330;
case 330:
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
#line 180 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Father");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st331;
st331:
	if ( ++p == pe )
		goto _test_eof331;
case 331:
#line 7582 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 95 )
		goto st331;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st331;
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
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st332;
tr479:
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
	goto st332;
st332:
	if ( ++p == pe )
		goto _test_eof332;
case 332:
#line 7621 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 44: goto tr482;
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
	goto tr477;
tr482:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st333;
st333:
	if ( ++p == pe )
		goto _test_eof333;
case 333:
#line 7648 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 77 )
		goto st334;
	goto tr448;
st334:
	if ( ++p == pe )
		goto _test_eof334;
case 334:
	if ( (*p) == 111 )
		goto st335;
	goto tr448;
st335:
	if ( ++p == pe )
		goto _test_eof335;
case 335:
	if ( (*p) == 116 )
		goto st336;
	goto tr448;
st336:
	if ( ++p == pe )
		goto _test_eof336;
case 336:
	if ( (*p) == 104 )
		goto st337;
	goto tr448;
st337:
	if ( ++p == pe )
		goto _test_eof337;
case 337:
	if ( (*p) == 101 )
		goto st338;
	goto tr448;
st338:
	if ( ++p == pe )
		goto _test_eof338;
case 338:
	if ( (*p) == 114 )
		goto st339;
	goto tr448;
st339:
	if ( ++p == pe )
		goto _test_eof339;
case 339:
	if ( (*p) == 61 )
		goto st340;
	goto tr448;
st340:
	if ( ++p == pe )
		goto _test_eof340;
case 340:
	if ( (*p) == 95 )
		goto tr490;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr490;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr491;
		} else if ( (*p) >= 65 )
			goto tr491;
	} else
		goto tr491;
	goto tr477;
tr490:
#line 184 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Mother");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st341;
st341:
	if ( ++p == pe )
		goto _test_eof341;
case 341:
#line 7726 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 95 )
		goto st341;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st341;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr493;
		} else if ( (*p) >= 65 )
			goto tr493;
	} else
		goto tr493;
	goto tr477;
tr493:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st342;
tr491:
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
	goto st342;
st342:
	if ( ++p == pe )
		goto _test_eof342;
case 342:
#line 7765 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 62: goto tr494;
		case 95: goto tr493;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr493;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr493;
		} else if ( (*p) >= 65 )
			goto tr493;
	} else
		goto tr493;
	goto tr477;
tr494:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st343;
st343:
	if ( ++p == pe )
		goto _test_eof343;
case 343:
#line 7792 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
	}
	goto tr448;
tr469:
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
case 344:
#line 7812 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 97 )
		goto tr495;
	goto tr467;
tr495:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st345;
st345:
	if ( ++p == pe )
		goto _test_eof345;
case 345:
#line 7826 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 109 )
		goto tr496;
	goto tr467;
tr496:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st346;
st346:
	if ( ++p == pe )
		goto _test_eof346;
case 346:
#line 7840 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 101 )
		goto tr497;
	goto tr467;
tr497:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st347;
st347:
	if ( ++p == pe )
		goto _test_eof347;
case 347:
#line 7854 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 95 )
		goto tr498;
	goto tr467;
tr498:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st348;
st348:
	if ( ++p == pe )
		goto _test_eof348;
case 348:
#line 7868 "inc/vcf/validator_detail_v44.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr499;
	goto tr467;
tr499:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st349;
st349:
	if ( ++p == pe )
		goto _test_eof349;
case 349:
#line 7882 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 61 )
		goto tr500;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr499;
	goto tr467;
tr500:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st350;
st350:
	if ( ++p == pe )
		goto _test_eof350;
case 350:
#line 7898 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 95 )
		goto tr501;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr501;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr502;
		} else if ( (*p) >= 65 )
			goto tr502;
	} else
		goto tr502;
	goto tr467;
tr501:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st351;
st351:
	if ( ++p == pe )
		goto _test_eof351;
case 351:
#line 7923 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 95 )
		goto st351;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st351;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr504;
		} else if ( (*p) >= 65 )
			goto tr504;
	} else
		goto tr504;
	goto tr467;
tr502:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st352;
tr504:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st352;
st352:
	if ( ++p == pe )
		goto _test_eof352;
case 352:
#line 7958 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 44: goto tr505;
		case 62: goto tr494;
		case 95: goto tr504;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr504;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr504;
		} else if ( (*p) >= 65 )
			goto tr504;
	} else
		goto tr504;
	goto tr467;
tr505:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st353;
st353:
	if ( ++p == pe )
		goto _test_eof353;
case 353:
#line 7986 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 78 )
		goto tr469;
	goto tr467;
st354:
	if ( ++p == pe )
		goto _test_eof354;
case 354:
	if ( (*p) == 114 )
		goto st355;
	goto tr448;
st355:
	if ( ++p == pe )
		goto _test_eof355;
case 355:
	if ( (*p) == 105 )
		goto st356;
	goto tr448;
st356:
	if ( ++p == pe )
		goto _test_eof356;
case 356:
	if ( (*p) == 103 )
		goto st357;
	goto tr448;
st357:
	if ( ++p == pe )
		goto _test_eof357;
case 357:
	if ( (*p) == 105 )
		goto st358;
	goto tr448;
st358:
	if ( ++p == pe )
		goto _test_eof358;
case 358:
	if ( (*p) == 110 )
		goto st359;
	goto tr448;
st359:
	if ( ++p == pe )
		goto _test_eof359;
case 359:
	if ( (*p) == 97 )
		goto st360;
	goto tr448;
st360:
	if ( ++p == pe )
		goto _test_eof360;
case 360:
	if ( (*p) == 108 )
		goto st361;
	goto tr448;
st361:
	if ( ++p == pe )
		goto _test_eof361;
case 361:
	if ( (*p) == 61 )
		goto st362;
	goto tr448;
st362:
	if ( ++p == pe )
		goto _test_eof362;
case 362:
	if ( (*p) == 95 )
		goto tr515;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr515;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr516;
		} else if ( (*p) >= 65 )
			goto tr516;
	} else
		goto tr516;
	goto tr514;
tr515:
#line 176 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Original");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st363;
st363:
	if ( ++p == pe )
		goto _test_eof363;
case 363:
#line 8078 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 95 )
		goto st363;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st363;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr518;
		} else if ( (*p) >= 65 )
			goto tr518;
	} else
		goto tr518;
	goto tr514;
tr518:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st364;
tr516:
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
	goto st364;
st364:
	if ( ++p == pe )
		goto _test_eof364;
case 364:
#line 8117 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 62: goto tr494;
		case 95: goto tr518;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr518;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr518;
		} else if ( (*p) >= 65 )
			goto tr518;
	} else
		goto tr518;
	goto tr514;
tr36:
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
#line 8148 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 65: goto tr520;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr519;
tr520:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st366;
st366:
	if ( ++p == pe )
		goto _test_eof366;
case 366:
#line 8166 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 77: goto tr521;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr519;
tr521:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st367;
st367:
	if ( ++p == pe )
		goto _test_eof367;
case 367:
#line 8184 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 80: goto tr522;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr519;
tr522:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st368;
st368:
	if ( ++p == pe )
		goto _test_eof368;
case 368:
#line 8202 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 76: goto tr523;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr519;
tr523:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st369;
st369:
	if ( ++p == pe )
		goto _test_eof369;
case 369:
#line 8220 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 69: goto st370;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr519;
st370:
	if ( ++p == pe )
		goto _test_eof370;
case 370:
	if ( (*p) == 61 )
		goto tr525;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr519;
tr525:
#line 140 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "SAMPLE");
    }
	goto st371;
st371:
	if ( ++p == pe )
		goto _test_eof371;
case 371:
#line 8247 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 60 )
		goto st372;
	goto tr519;
st372:
	if ( ++p == pe )
		goto _test_eof372;
case 372:
	if ( (*p) == 73 )
		goto st373;
	goto tr519;
st373:
	if ( ++p == pe )
		goto _test_eof373;
case 373:
	if ( (*p) == 68 )
		goto st374;
	goto tr519;
st374:
	if ( ++p == pe )
		goto _test_eof374;
case 374:
	if ( (*p) == 61 )
		goto st375;
	goto tr519;
st375:
	if ( ++p == pe )
		goto _test_eof375;
case 375:
	if ( (*p) == 95 )
		goto tr531;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr531;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr532;
		} else if ( (*p) >= 65 )
			goto tr532;
	} else
		goto tr532;
	goto tr530;
tr531:
#line 144 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st376;
st376:
	if ( ++p == pe )
		goto _test_eof376;
case 376:
#line 8304 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 95 )
		goto st376;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st376;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr534;
		} else if ( (*p) >= 65 )
			goto tr534;
	} else
		goto tr534;
	goto tr530;
tr534:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st377;
tr532:
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
	goto st377;
st377:
	if ( ++p == pe )
		goto _test_eof377;
case 377:
#line 8343 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 44: goto tr535;
		case 62: goto tr536;
		case 95: goto tr534;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr534;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr534;
		} else if ( (*p) >= 65 )
			goto tr534;
	} else
		goto tr534;
	goto tr530;
tr535:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st378;
st378:
	if ( ++p == pe )
		goto _test_eof378;
case 378:
#line 8371 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 95 )
		goto tr537;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr537;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr538;
		} else if ( (*p) >= 65 )
			goto tr538;
	} else
		goto tr538;
	goto tr519;
tr537:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st379;
st379:
	if ( ++p == pe )
		goto _test_eof379;
case 379:
#line 8396 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 95 )
		goto st379;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st379;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr540;
		} else if ( (*p) >= 65 )
			goto tr540;
	} else
		goto tr540;
	goto tr519;
tr538:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st380;
tr540:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st380;
st380:
	if ( ++p == pe )
		goto _test_eof380;
case 380:
#line 8431 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr541;
		case 95: goto tr540;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr540;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr540;
		} else if ( (*p) >= 65 )
			goto tr540;
	} else
		goto tr540;
	goto tr519;
tr541:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st381;
st381:
	if ( ++p == pe )
		goto _test_eof381;
case 381:
#line 8458 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 34 )
		goto st384;
	if ( (*p) < 45 ) {
		if ( 32 <= (*p) && (*p) <= 43 )
			goto tr542;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr542;
	} else
		goto tr542;
	goto tr519;
tr542:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st382;
tr544:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st382;
st382:
	if ( ++p == pe )
		goto _test_eof382;
case 382:
#line 8490 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 44: goto tr535;
		case 62: goto tr536;
	}
	if ( (*p) > 33 ) {
		if ( 35 <= (*p) && (*p) <= 126 )
			goto tr544;
	} else if ( (*p) >= 32 )
		goto tr544;
	goto tr519;
tr536:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st383;
st383:
	if ( ++p == pe )
		goto _test_eof383;
case 383:
#line 8511 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
	}
	goto tr519;
st384:
	if ( ++p == pe )
		goto _test_eof384;
case 384:
	switch( (*p) ) {
		case 34: goto tr546;
		case 92: goto tr547;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr545;
	goto tr519;
tr545:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st385;
tr548:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st385;
st385:
	if ( ++p == pe )
		goto _test_eof385;
case 385:
#line 8548 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 34: goto tr549;
		case 92: goto tr550;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr548;
	goto tr519;
tr546:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st386;
tr549:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st386;
st386:
	if ( ++p == pe )
		goto _test_eof386;
case 386:
#line 8576 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 44: goto st378;
		case 62: goto st383;
	}
	goto tr519;
tr547:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st387;
tr550:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st387;
st387:
	if ( ++p == pe )
		goto _test_eof387;
case 387:
#line 8602 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 34: goto tr553;
		case 92: goto tr550;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr548;
	goto tr519;
tr553:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st388;
st388:
	if ( ++p == pe )
		goto _test_eof388;
case 388:
#line 8624 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 34: goto tr549;
		case 44: goto tr554;
		case 62: goto tr555;
		case 92: goto tr550;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr548;
	goto tr519;
tr568:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st389;
tr554:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st389;
tr565:
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
#line 8664 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 34: goto tr549;
		case 47: goto tr548;
		case 92: goto tr550;
		case 95: goto tr556;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr548;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr557;
		} else
			goto tr556;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr557;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr548;
			} else if ( (*p) >= 97 )
				goto tr557;
		} else
			goto tr548;
	} else
		goto tr548;
	goto tr519;
tr556:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st390;
tr558:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st390;
st390:
	if ( ++p == pe )
		goto _test_eof390;
case 390:
#line 8715 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 34: goto tr549;
		case 47: goto tr548;
		case 92: goto tr550;
		case 95: goto tr558;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr548;
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
					goto tr548;
			} else if ( (*p) >= 97 )
				goto tr559;
		} else
			goto tr548;
	} else
		goto tr548;
	goto tr519;
tr557:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st391;
tr559:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st391;
st391:
	if ( ++p == pe )
		goto _test_eof391;
case 391:
#line 8766 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 34: goto tr549;
		case 47: goto tr548;
		case 61: goto tr560;
		case 92: goto tr550;
		case 95: goto tr559;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr548;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr548;
		} else
			goto tr559;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr548;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr548;
		} else
			goto tr559;
	} else
		goto tr559;
	goto tr519;
tr560:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st392;
st392:
	if ( ++p == pe )
		goto _test_eof392;
case 392:
#line 8809 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 34: goto tr562;
		case 44: goto tr548;
		case 62: goto tr548;
		case 92: goto tr563;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr561;
	goto tr519;
tr564:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st393;
tr561:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st393;
st393:
	if ( ++p == pe )
		goto _test_eof393;
case 393:
#line 8839 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 34: goto tr549;
		case 44: goto tr565;
		case 62: goto tr566;
		case 92: goto tr567;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr564;
	goto tr519;
tr569:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st394;
tr555:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st394;
tr566:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st394;
st394:
	if ( ++p == pe )
		goto _test_eof394;
case 394:
#line 8879 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
		case 34: goto tr549;
		case 92: goto tr550;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr548;
	goto tr519;
tr567:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st395;
tr563:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st395;
st395:
	if ( ++p == pe )
		goto _test_eof395;
case 395:
#line 8909 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 34: goto tr553;
		case 44: goto tr565;
		case 62: goto tr566;
		case 92: goto tr567;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr564;
	goto tr519;
tr562:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st396;
st396:
	if ( ++p == pe )
		goto _test_eof396;
case 396:
#line 8929 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 34: goto tr546;
		case 44: goto tr568;
		case 62: goto tr569;
		case 92: goto tr547;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr545;
	goto tr519;
tr37:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st397;
st397:
	if ( ++p == pe )
		goto _test_eof397;
case 397:
#line 8953 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 115: goto tr571;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr570;
tr571:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st398;
st398:
	if ( ++p == pe )
		goto _test_eof398;
case 398:
#line 8971 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 115: goto tr572;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr570;
tr572:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st399;
st399:
	if ( ++p == pe )
		goto _test_eof399;
case 399:
#line 8989 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 101: goto tr573;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr570;
tr573:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st400;
st400:
	if ( ++p == pe )
		goto _test_eof400;
case 400:
#line 9007 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 109: goto tr574;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr570;
tr574:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st401;
st401:
	if ( ++p == pe )
		goto _test_eof401;
case 401:
#line 9025 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 98: goto tr575;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr570;
tr575:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st402;
st402:
	if ( ++p == pe )
		goto _test_eof402;
case 402:
#line 9043 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 108: goto tr576;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr570;
tr576:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st403;
st403:
	if ( ++p == pe )
		goto _test_eof403;
case 403:
#line 9061 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 121: goto st404;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr570;
st404:
	if ( ++p == pe )
		goto _test_eof404;
case 404:
	if ( (*p) == 61 )
		goto tr578;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr570;
tr578:
#line 112 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "assembly");
    }
	goto st405;
st405:
	if ( ++p == pe )
		goto _test_eof405;
case 405:
#line 9088 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr580;
	} else if ( (*p) >= 65 )
		goto tr580;
	goto tr579;
tr580:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st406;
st406:
	if ( ++p == pe )
		goto _test_eof406;
case 406:
#line 9105 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 10: goto tr579;
		case 13: goto tr582;
		case 35: goto tr579;
		case 47: goto tr579;
		case 58: goto tr579;
		case 63: goto tr579;
	}
	goto st407;
tr582:
#line 43 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st407;
st407:
	if ( ++p == pe )
		goto _test_eof407;
case 407:
#line 9131 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 10: goto tr579;
		case 13: goto tr582;
		case 35: goto tr579;
		case 47: goto tr579;
		case 58: goto st408;
		case 63: goto tr579;
	}
	goto st407;
st408:
	if ( ++p == pe )
		goto _test_eof408;
case 408:
	if ( (*p) == 47 )
		goto st409;
	goto tr579;
st409:
	if ( ++p == pe )
		goto _test_eof409;
case 409:
	if ( (*p) == 47 )
		goto st410;
	goto tr579;
st410:
	if ( ++p == pe )
		goto _test_eof410;
case 410:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st411;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr587;
	} else
		goto tr587;
	goto tr579;
st411:
	if ( ++p == pe )
		goto _test_eof411;
case 411:
	if ( (*p) == 46 )
		goto st412;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st422;
	goto tr579;
st412:
	if ( ++p == pe )
		goto _test_eof412;
case 412:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st413;
	goto tr579;
st413:
	if ( ++p == pe )
		goto _test_eof413;
case 413:
	if ( (*p) == 46 )
		goto st414;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st420;
	goto tr579;
st414:
	if ( ++p == pe )
		goto _test_eof414;
case 414:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st415;
	goto tr579;
st415:
	if ( ++p == pe )
		goto _test_eof415;
case 415:
	if ( (*p) == 46 )
		goto st416;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st418;
	goto tr579;
st416:
	if ( ++p == pe )
		goto _test_eof416;
case 416:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr587;
	goto tr579;
tr587:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st417;
tr596:
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
	goto st417;
st417:
	if ( ++p == pe )
		goto _test_eof417;
case 417:
#line 9254 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 10: goto tr46;
		case 13: goto tr596;
	}
	goto tr587;
st418:
	if ( ++p == pe )
		goto _test_eof418;
case 418:
	if ( (*p) == 46 )
		goto st416;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st419;
	goto tr579;
st419:
	if ( ++p == pe )
		goto _test_eof419;
case 419:
	if ( (*p) == 46 )
		goto st416;
	goto tr579;
st420:
	if ( ++p == pe )
		goto _test_eof420;
case 420:
	if ( (*p) == 46 )
		goto st414;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st421;
	goto tr579;
st421:
	if ( ++p == pe )
		goto _test_eof421;
case 421:
	if ( (*p) == 46 )
		goto st414;
	goto tr579;
st422:
	if ( ++p == pe )
		goto _test_eof422;
case 422:
	if ( (*p) == 46 )
		goto st412;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st423;
	goto tr579;
st423:
	if ( ++p == pe )
		goto _test_eof423;
case 423:
	if ( (*p) == 46 )
		goto st412;
	goto tr579;
tr38:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st424;
st424:
	if ( ++p == pe )
		goto _test_eof424;
case 424:
#line 9322 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 111: goto tr601;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr600;
tr601:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st425;
st425:
	if ( ++p == pe )
		goto _test_eof425;
case 425:
#line 9340 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 110: goto tr602;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr600;
tr602:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st426;
st426:
	if ( ++p == pe )
		goto _test_eof426;
case 426:
#line 9358 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 116: goto tr603;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr600;
tr603:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st427;
st427:
	if ( ++p == pe )
		goto _test_eof427;
case 427:
#line 9376 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 105: goto tr604;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr600;
tr604:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st428;
st428:
	if ( ++p == pe )
		goto _test_eof428;
case 428:
#line 9394 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 103: goto st429;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr600;
st429:
	if ( ++p == pe )
		goto _test_eof429;
case 429:
	if ( (*p) == 61 )
		goto tr606;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr600;
tr606:
#line 116 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "contig");
    }
	goto st430;
st430:
	if ( ++p == pe )
		goto _test_eof430;
case 430:
#line 9421 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 60 )
		goto st431;
	goto tr600;
st431:
	if ( ++p == pe )
		goto _test_eof431;
case 431:
	if ( (*p) == 73 )
		goto st432;
	goto tr600;
st432:
	if ( ++p == pe )
		goto _test_eof432;
case 432:
	if ( (*p) == 68 )
		goto st433;
	goto tr600;
st433:
	if ( ++p == pe )
		goto _test_eof433;
case 433:
	if ( (*p) == 61 )
		goto st434;
	goto tr600;
st434:
	if ( ++p == pe )
		goto _test_eof434;
case 434:
	switch( (*p) ) {
		case 43: goto tr612;
		case 92: goto tr612;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr612;
		} else if ( (*p) >= 33 )
			goto tr612;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr612;
		} else if ( (*p) >= 63 )
			goto tr612;
	} else
		goto tr612;
	goto tr611;
tr613:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st435;
tr612:
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
	goto st435;
st435:
	if ( ++p == pe )
		goto _test_eof435;
case 435:
#line 9493 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 44: goto tr614;
		case 62: goto tr615;
		case 92: goto tr613;
	}
	if ( (*p) < 43 ) {
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
tr614:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st436;
st436:
	if ( ++p == pe )
		goto _test_eof436;
case 436:
#line 9521 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 95 )
		goto tr616;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr616;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr617;
		} else if ( (*p) >= 65 )
			goto tr617;
	} else
		goto tr617;
	goto tr600;
tr616:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st437;
st437:
	if ( ++p == pe )
		goto _test_eof437;
case 437:
#line 9546 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 95 )
		goto st437;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st437;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr619;
		} else if ( (*p) >= 65 )
			goto tr619;
	} else
		goto tr619;
	goto tr600;
tr617:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st438;
tr619:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st438;
st438:
	if ( ++p == pe )
		goto _test_eof438;
case 438:
#line 9581 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr620;
		case 95: goto tr619;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr619;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr619;
		} else if ( (*p) >= 65 )
			goto tr619;
	} else
		goto tr619;
	goto tr600;
tr620:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st439;
st439:
	if ( ++p == pe )
		goto _test_eof439;
case 439:
#line 9608 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 34 )
		goto st442;
	if ( (*p) < 45 ) {
		if ( 32 <= (*p) && (*p) <= 43 )
			goto tr621;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr621;
	} else
		goto tr621;
	goto tr600;
tr621:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st440;
tr623:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st440;
st440:
	if ( ++p == pe )
		goto _test_eof440;
case 440:
#line 9640 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 44: goto tr614;
		case 62: goto tr615;
	}
	if ( (*p) > 33 ) {
		if ( 35 <= (*p) && (*p) <= 126 )
			goto tr623;
	} else if ( (*p) >= 32 )
		goto tr623;
	goto tr600;
tr615:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st441;
st441:
	if ( ++p == pe )
		goto _test_eof441;
case 441:
#line 9661 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
	}
	goto tr600;
st442:
	if ( ++p == pe )
		goto _test_eof442;
case 442:
	switch( (*p) ) {
		case 34: goto tr625;
		case 92: goto tr626;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr624;
	goto tr600;
tr624:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st443;
tr627:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st443;
st443:
	if ( ++p == pe )
		goto _test_eof443;
case 443:
#line 9698 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 34: goto tr628;
		case 92: goto tr629;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr627;
	goto tr600;
tr625:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st444;
tr628:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st444;
st444:
	if ( ++p == pe )
		goto _test_eof444;
case 444:
#line 9726 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 44: goto st436;
		case 62: goto st441;
	}
	goto tr600;
tr626:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st445;
tr629:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st445;
st445:
	if ( ++p == pe )
		goto _test_eof445;
case 445:
#line 9752 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 34: goto tr632;
		case 92: goto tr629;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr627;
	goto tr600;
tr632:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st446;
st446:
	if ( ++p == pe )
		goto _test_eof446;
case 446:
#line 9774 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 34: goto tr628;
		case 44: goto tr633;
		case 62: goto tr634;
		case 92: goto tr629;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr627;
	goto tr600;
tr647:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st447;
tr633:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st447;
tr644:
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
case 447:
#line 9814 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 34: goto tr628;
		case 47: goto tr627;
		case 92: goto tr629;
		case 95: goto tr635;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr627;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr636;
		} else
			goto tr635;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr636;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr627;
			} else if ( (*p) >= 97 )
				goto tr636;
		} else
			goto tr627;
	} else
		goto tr627;
	goto tr600;
tr635:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st448;
tr637:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st448;
st448:
	if ( ++p == pe )
		goto _test_eof448;
case 448:
#line 9865 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 34: goto tr628;
		case 47: goto tr627;
		case 92: goto tr629;
		case 95: goto tr637;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr627;
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
					goto tr627;
			} else if ( (*p) >= 97 )
				goto tr638;
		} else
			goto tr627;
	} else
		goto tr627;
	goto tr600;
tr636:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st449;
tr638:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st449;
st449:
	if ( ++p == pe )
		goto _test_eof449;
case 449:
#line 9916 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 34: goto tr628;
		case 47: goto tr627;
		case 61: goto tr639;
		case 92: goto tr629;
		case 95: goto tr638;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr627;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr627;
		} else
			goto tr638;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr627;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr627;
		} else
			goto tr638;
	} else
		goto tr638;
	goto tr600;
tr639:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
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
#line 9959 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 34: goto tr641;
		case 44: goto tr627;
		case 62: goto tr627;
		case 92: goto tr642;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr640;
	goto tr600;
tr643:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st451;
tr640:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st451;
st451:
	if ( ++p == pe )
		goto _test_eof451;
case 451:
#line 9989 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 34: goto tr628;
		case 44: goto tr644;
		case 62: goto tr645;
		case 92: goto tr646;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr643;
	goto tr600;
tr648:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st452;
tr634:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st452;
tr645:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st452;
st452:
	if ( ++p == pe )
		goto _test_eof452;
case 452:
#line 10029 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
		case 34: goto tr628;
		case 92: goto tr629;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr627;
	goto tr600;
tr646:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st453;
tr642:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st453;
st453:
	if ( ++p == pe )
		goto _test_eof453;
case 453:
#line 10059 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 34: goto tr632;
		case 44: goto tr644;
		case 62: goto tr645;
		case 92: goto tr646;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr643;
	goto tr600;
tr641:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st454;
st454:
	if ( ++p == pe )
		goto _test_eof454;
case 454:
#line 10079 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 34: goto tr625;
		case 44: goto tr647;
		case 62: goto tr648;
		case 92: goto tr626;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr624;
	goto tr600;
tr39:
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
case 455:
#line 10103 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 101: goto tr650;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr649;
tr650:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st456;
st456:
	if ( ++p == pe )
		goto _test_eof456;
case 456:
#line 10121 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 100: goto tr651;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr649;
tr651:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st457;
st457:
	if ( ++p == pe )
		goto _test_eof457;
case 457:
#line 10139 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 105: goto tr652;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr649;
tr652:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st458;
st458:
	if ( ++p == pe )
		goto _test_eof458;
case 458:
#line 10157 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 103: goto tr653;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr649;
tr653:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st459;
st459:
	if ( ++p == pe )
		goto _test_eof459;
case 459:
#line 10175 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 114: goto tr654;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr649;
tr654:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st460;
st460:
	if ( ++p == pe )
		goto _test_eof460;
case 460:
#line 10193 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 101: goto tr655;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr649;
tr655:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st461;
st461:
	if ( ++p == pe )
		goto _test_eof461;
case 461:
#line 10211 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 101: goto tr656;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr649;
tr656:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st462;
st462:
	if ( ++p == pe )
		goto _test_eof462;
case 462:
#line 10229 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 68: goto tr657;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr649;
tr657:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st463;
st463:
	if ( ++p == pe )
		goto _test_eof463;
case 463:
#line 10247 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 66: goto st464;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr649;
st464:
	if ( ++p == pe )
		goto _test_eof464;
case 464:
	if ( (*p) == 61 )
		goto tr659;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr649;
tr659:
#line 136 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "pedigreeDB");
    }
	goto st465;
st465:
	if ( ++p == pe )
		goto _test_eof465;
case 465:
#line 10274 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 60 )
		goto st466;
	goto tr649;
st466:
	if ( ++p == pe )
		goto _test_eof466;
case 466:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr662;
	} else if ( (*p) >= 65 )
		goto tr662;
	goto tr661;
tr662:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st467;
st467:
	if ( ++p == pe )
		goto _test_eof467;
case 467:
#line 10298 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 10: goto tr661;
		case 13: goto tr664;
		case 35: goto tr661;
		case 47: goto tr661;
		case 58: goto tr661;
		case 63: goto tr661;
	}
	goto st468;
tr664:
#line 43 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st468;
st468:
	if ( ++p == pe )
		goto _test_eof468;
case 468:
#line 10324 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 10: goto tr661;
		case 13: goto tr664;
		case 35: goto tr661;
		case 47: goto tr661;
		case 58: goto st469;
		case 63: goto tr661;
	}
	goto st468;
st469:
	if ( ++p == pe )
		goto _test_eof469;
case 469:
	if ( (*p) == 47 )
		goto st470;
	goto tr661;
st470:
	if ( ++p == pe )
		goto _test_eof470;
case 470:
	if ( (*p) == 47 )
		goto st471;
	goto tr661;
st471:
	if ( ++p == pe )
		goto _test_eof471;
case 471:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st472;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr669;
	} else
		goto tr669;
	goto tr661;
st472:
	if ( ++p == pe )
		goto _test_eof472;
case 472:
	if ( (*p) == 46 )
		goto st473;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st485;
	goto tr661;
st473:
	if ( ++p == pe )
		goto _test_eof473;
case 473:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st474;
	goto tr661;
st474:
	if ( ++p == pe )
		goto _test_eof474;
case 474:
	if ( (*p) == 46 )
		goto st475;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st483;
	goto tr661;
st475:
	if ( ++p == pe )
		goto _test_eof475;
case 475:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st476;
	goto tr661;
st476:
	if ( ++p == pe )
		goto _test_eof476;
case 476:
	if ( (*p) == 46 )
		goto st477;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st481;
	goto tr661;
st477:
	if ( ++p == pe )
		goto _test_eof477;
case 477:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr669;
	goto tr661;
tr669:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st478;
tr678:
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
	goto st478;
st478:
	if ( ++p == pe )
		goto _test_eof478;
case 478:
#line 10435 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 10: goto tr661;
		case 13: goto tr678;
		case 62: goto tr679;
	}
	goto tr669;
tr679:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st479;
st479:
	if ( ++p == pe )
		goto _test_eof479;
case 479:
#line 10456 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr680;
		case 62: goto tr679;
	}
	goto tr669;
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
#line 196 "src/vcf/vcf.ragel"
	{
        try {
          ParsePolicy::handle_meta_line(*this);
        } catch (Error *error) {
          ErrorPolicy::handle_error(*this, error);
        }
    }
	goto st480;
st480:
	if ( ++p == pe )
		goto _test_eof480;
case 480:
#line 10491 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 10: goto st28;
		case 13: goto tr678;
		case 62: goto tr679;
	}
	goto tr669;
st481:
	if ( ++p == pe )
		goto _test_eof481;
case 481:
	if ( (*p) == 46 )
		goto st477;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st482;
	goto tr661;
st482:
	if ( ++p == pe )
		goto _test_eof482;
case 482:
	if ( (*p) == 46 )
		goto st477;
	goto tr661;
st483:
	if ( ++p == pe )
		goto _test_eof483;
case 483:
	if ( (*p) == 46 )
		goto st475;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st484;
	goto tr661;
st484:
	if ( ++p == pe )
		goto _test_eof484;
case 484:
	if ( (*p) == 46 )
		goto st475;
	goto tr661;
st485:
	if ( ++p == pe )
		goto _test_eof485;
case 485:
	if ( (*p) == 46 )
		goto st473;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st486;
	goto tr661;
st486:
	if ( ++p == pe )
		goto _test_eof486;
case 486:
	if ( (*p) == 46 )
		goto st473;
	goto tr661;
st487:
	if ( ++p == pe )
		goto _test_eof487;
case 487:
	if ( (*p) == 72 )
		goto st488;
	goto tr684;
st488:
	if ( ++p == pe )
		goto _test_eof488;
case 488:
	if ( (*p) == 82 )
		goto st489;
	goto tr684;
st489:
	if ( ++p == pe )
		goto _test_eof489;
case 489:
	if ( (*p) == 79 )
		goto st490;
	goto tr684;
st490:
	if ( ++p == pe )
		goto _test_eof490;
case 490:
	if ( (*p) == 77 )
		goto st491;
	goto tr684;
st491:
	if ( ++p == pe )
		goto _test_eof491;
case 491:
	if ( (*p) == 9 )
		goto tr689;
	goto tr684;
tr689:
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st492;
st492:
	if ( ++p == pe )
		goto _test_eof492;
case 492:
#line 10591 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 80 )
		goto st493;
	goto tr684;
st493:
	if ( ++p == pe )
		goto _test_eof493;
case 493:
	if ( (*p) == 79 )
		goto st494;
	goto tr684;
st494:
	if ( ++p == pe )
		goto _test_eof494;
case 494:
	if ( (*p) == 83 )
		goto st495;
	goto tr684;
st495:
	if ( ++p == pe )
		goto _test_eof495;
case 495:
	if ( (*p) == 9 )
		goto tr693;
	goto tr684;
tr693:
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st496;
st496:
	if ( ++p == pe )
		goto _test_eof496;
case 496:
#line 10626 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 73 )
		goto st497;
	goto tr684;
st497:
	if ( ++p == pe )
		goto _test_eof497;
case 497:
	if ( (*p) == 68 )
		goto st498;
	goto tr684;
st498:
	if ( ++p == pe )
		goto _test_eof498;
case 498:
	if ( (*p) == 9 )
		goto tr696;
	goto tr684;
tr696:
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st499;
st499:
	if ( ++p == pe )
		goto _test_eof499;
case 499:
#line 10654 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 82 )
		goto st500;
	goto tr684;
st500:
	if ( ++p == pe )
		goto _test_eof500;
case 500:
	if ( (*p) == 69 )
		goto st501;
	goto tr684;
st501:
	if ( ++p == pe )
		goto _test_eof501;
case 501:
	if ( (*p) == 70 )
		goto st502;
	goto tr684;
st502:
	if ( ++p == pe )
		goto _test_eof502;
case 502:
	if ( (*p) == 9 )
		goto tr700;
	goto tr684;
tr700:
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st503;
st503:
	if ( ++p == pe )
		goto _test_eof503;
case 503:
#line 10689 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 65 )
		goto st504;
	goto tr684;
st504:
	if ( ++p == pe )
		goto _test_eof504;
case 504:
	if ( (*p) == 76 )
		goto st505;
	goto tr684;
st505:
	if ( ++p == pe )
		goto _test_eof505;
case 505:
	if ( (*p) == 84 )
		goto st506;
	goto tr684;
st506:
	if ( ++p == pe )
		goto _test_eof506;
case 506:
	if ( (*p) == 9 )
		goto tr704;
	goto tr684;
tr704:
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st507;
st507:
	if ( ++p == pe )
		goto _test_eof507;
case 507:
#line 10724 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 81 )
		goto st508;
	goto tr684;
st508:
	if ( ++p == pe )
		goto _test_eof508;
case 508:
	if ( (*p) == 85 )
		goto st509;
	goto tr684;
st509:
	if ( ++p == pe )
		goto _test_eof509;
case 509:
	if ( (*p) == 65 )
		goto st510;
	goto tr684;
st510:
	if ( ++p == pe )
		goto _test_eof510;
case 510:
	if ( (*p) == 76 )
		goto st511;
	goto tr684;
st511:
	if ( ++p == pe )
		goto _test_eof511;
case 511:
	if ( (*p) == 9 )
		goto tr709;
	goto tr684;
tr709:
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st512;
st512:
	if ( ++p == pe )
		goto _test_eof512;
case 512:
#line 10766 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 70 )
		goto st513;
	goto tr684;
st513:
	if ( ++p == pe )
		goto _test_eof513;
case 513:
	if ( (*p) == 73 )
		goto st514;
	goto tr684;
st514:
	if ( ++p == pe )
		goto _test_eof514;
case 514:
	if ( (*p) == 76 )
		goto st515;
	goto tr684;
st515:
	if ( ++p == pe )
		goto _test_eof515;
case 515:
	if ( (*p) == 84 )
		goto st516;
	goto tr684;
st516:
	if ( ++p == pe )
		goto _test_eof516;
case 516:
	if ( (*p) == 69 )
		goto st517;
	goto tr684;
st517:
	if ( ++p == pe )
		goto _test_eof517;
case 517:
	if ( (*p) == 82 )
		goto st518;
	goto tr684;
st518:
	if ( ++p == pe )
		goto _test_eof518;
case 518:
	if ( (*p) == 9 )
		goto tr716;
	goto tr684;
tr716:
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st519;
st519:
	if ( ++p == pe )
		goto _test_eof519;
case 519:
#line 10822 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 73 )
		goto st520;
	goto tr684;
st520:
	if ( ++p == pe )
		goto _test_eof520;
case 520:
	if ( (*p) == 78 )
		goto st521;
	goto tr684;
st521:
	if ( ++p == pe )
		goto _test_eof521;
case 521:
	if ( (*p) == 70 )
		goto st522;
	goto tr684;
st522:
	if ( ++p == pe )
		goto _test_eof522;
case 522:
	if ( (*p) == 79 )
		goto st523;
	goto tr684;
st523:
	if ( ++p == pe )
		goto _test_eof523;
case 523:
	switch( (*p) ) {
		case 9: goto tr721;
		case 10: goto tr722;
		case 13: goto tr723;
	}
	goto tr684;
tr721:
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st524;
st524:
	if ( ++p == pe )
		goto _test_eof524;
case 524:
#line 10867 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 70 )
		goto st525;
	goto tr724;
st525:
	if ( ++p == pe )
		goto _test_eof525;
case 525:
	if ( (*p) == 79 )
		goto st526;
	goto tr724;
st526:
	if ( ++p == pe )
		goto _test_eof526;
case 526:
	if ( (*p) == 82 )
		goto st527;
	goto tr724;
st527:
	if ( ++p == pe )
		goto _test_eof527;
case 527:
	if ( (*p) == 77 )
		goto st528;
	goto tr724;
st528:
	if ( ++p == pe )
		goto _test_eof528;
case 528:
	if ( (*p) == 65 )
		goto st529;
	goto tr724;
st529:
	if ( ++p == pe )
		goto _test_eof529;
case 529:
	if ( (*p) == 84 )
		goto st530;
	goto tr724;
st530:
	if ( ++p == pe )
		goto _test_eof530;
case 530:
	if ( (*p) == 9 )
		goto tr731;
	goto tr724;
tr731:
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st531;
tr733:
#line 204 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_sample_name(*this);
    }
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st531;
st531:
	if ( ++p == pe )
		goto _test_eof531;
case 531:
#line 10933 "inc/vcf/validator_detail_v44.hpp"
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr732;
	goto tr724;
tr732:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st532;
tr736:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st532;
st532:
	if ( ++p == pe )
		goto _test_eof532;
case 532:
#line 10957 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 9: goto tr733;
		case 10: goto tr734;
		case 13: goto tr735;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr736;
	goto tr724;
tr722:
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
	goto st625;
tr734:
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
	goto st625;
st625:
	if ( ++p == pe )
		goto _test_eof625;
case 625:
#line 11014 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 10: goto tr867;
		case 13: goto tr868;
		case 43: goto tr869;
		case 60: goto tr870;
		case 92: goto tr869;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr869;
		} else if ( (*p) >= 33 )
			goto tr869;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr869;
		} else if ( (*p) >= 63 )
			goto tr869;
	} else
		goto tr869;
	goto tr866;
tr871:
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
tr867:
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
	goto st626;
st626:
	if ( ++p == pe )
		goto _test_eof626;
case 626:
#line 11073 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 10: goto tr871;
		case 13: goto tr872;
	}
	goto st0;
tr872:
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
tr868:
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
	goto st533;
st533:
	if ( ++p == pe )
		goto _test_eof533;
case 533:
#line 11115 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 10 )
		goto st626;
	goto st0;
tr878:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st534;
tr741:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st534;
tr869:
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
	goto st534;
st534:
	if ( ++p == pe )
		goto _test_eof534;
case 534:
#line 11157 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 9: goto tr740;
		case 43: goto tr741;
		case 92: goto tr741;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr741;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr741;
		} else if ( (*p) >= 63 )
			goto tr741;
	} else
		goto tr741;
	goto tr739;
tr740:
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
	goto st535;
tr799:
#line 218 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st535;
st535:
	if ( ++p == pe )
		goto _test_eof535;
case 535:
#line 11203 "inc/vcf/validator_detail_v44.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr743;
	goto tr742;
tr743:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st536;
tr745:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st536;
st536:
	if ( ++p == pe )
		goto _test_eof536;
case 536:
#line 11227 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 9 )
		goto tr744;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr745;
	goto tr742;
tr750:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st537;
tr744:
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
	goto st537;
st537:
	if ( ++p == pe )
		goto _test_eof537;
case 537:
#line 11257 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr747;
	} else if ( (*p) >= 33 )
		goto tr747;
	goto tr746;
tr747:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st538;
tr749:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st538;
st538:
	if ( ++p == pe )
		goto _test_eof538;
case 538:
#line 11284 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 9: goto tr748;
		case 59: goto tr750;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr749;
	goto tr746;
tr748:
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
	goto st539;
st539:
	if ( ++p == pe )
		goto _test_eof539;
case 539:
#line 11310 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 65: goto tr752;
		case 67: goto tr752;
		case 71: goto tr752;
		case 78: goto tr752;
		case 84: goto tr752;
		case 97: goto tr752;
		case 99: goto tr752;
		case 103: goto tr752;
		case 110: goto tr752;
		case 116: goto tr752;
	}
	goto tr751;
tr752:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st540;
tr754:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st540;
st540:
	if ( ++p == pe )
		goto _test_eof540;
case 540:
#line 11344 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 9: goto tr753;
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
	goto tr751;
tr753:
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
	goto st541;
st541:
	if ( ++p == pe )
		goto _test_eof541;
case 541:
#line 11377 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 42: goto tr756;
		case 46: goto tr757;
		case 60: goto tr758;
		case 65: goto tr759;
		case 67: goto tr759;
		case 71: goto tr759;
		case 78: goto tr759;
		case 84: goto tr759;
		case 91: goto tr760;
		case 93: goto tr761;
		case 97: goto tr759;
		case 99: goto tr759;
		case 103: goto tr759;
		case 110: goto tr759;
		case 116: goto tr759;
	}
	goto tr755;
tr756:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st542;
tr821:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st542;
st542:
	if ( ++p == pe )
		goto _test_eof542;
case 542:
#line 11416 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 9: goto tr762;
		case 44: goto tr763;
	}
	goto tr755;
tr762:
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
	goto st543;
st543:
	if ( ++p == pe )
		goto _test_eof543;
case 543:
#line 11440 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto tr765;
		case 45: goto tr765;
		case 46: goto tr766;
		case 73: goto tr768;
		case 78: goto tr769;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr767;
	goto tr764;
tr765:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st544;
st544:
	if ( ++p == pe )
		goto _test_eof544;
case 544:
#line 11465 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 73 )
		goto tr771;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr770;
	goto tr764;
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
tr770:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st545;
st545:
	if ( ++p == pe )
		goto _test_eof545;
case 545:
#line 11491 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 9: goto tr772;
		case 46: goto tr773;
		case 69: goto tr774;
		case 101: goto tr774;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr770;
	goto tr764;
tr772:
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
	goto st546;
st546:
	if ( ++p == pe )
		goto _test_eof546;
case 546:
#line 11519 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 46: goto tr777;
		case 58: goto tr776;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr776;
		} else if ( (*p) > 57 ) {
			if ( 60 <= (*p) && (*p) <= 64 )
				goto tr776;
		} else
			goto tr778;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr776;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr776;
		} else
			goto tr778;
	} else
		goto tr778;
	goto tr775;
tr776:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st547;
st547:
	if ( ++p == pe )
		goto _test_eof547;
case 547:
#line 11555 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 58 )
		goto st547;
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto st547;
		} else if ( (*p) > 57 ) {
			if ( 60 <= (*p) && (*p) <= 64 )
				goto st547;
		} else
			goto tr780;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st547;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st547;
		} else
			goto tr780;
	} else
		goto tr780;
	goto tr775;
tr778:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st548;
tr780:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st548;
st548:
	if ( ++p == pe )
		goto _test_eof548;
case 548:
#line 11599 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 9: goto tr781;
		case 59: goto tr782;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr780;
	goto tr775;
tr781:
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
	goto st549;
st549:
	if ( ++p == pe )
		goto _test_eof549;
case 549:
#line 11625 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 46: goto tr784;
		case 49: goto tr785;
		case 95: goto tr786;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr786;
	} else if ( (*p) >= 65 )
		goto tr786;
	goto tr783;
tr784:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st627;
st627:
	if ( ++p == pe )
		goto _test_eof627;
case 627:
#line 11651 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 9: goto tr874;
		case 10: goto tr875;
		case 13: goto tr876;
	}
	goto tr873;
tr791:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st550;
tr874:
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
case 550:
#line 11682 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 95 )
		goto tr788;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr788;
	} else if ( (*p) >= 65 )
		goto tr788;
	goto tr787;
tr788:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st551;
tr790:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st551;
st551:
	if ( ++p == pe )
		goto _test_eof551;
case 551:
#line 11711 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 9: goto tr789;
		case 37: goto tr790;
		case 46: goto tr790;
		case 58: goto tr791;
		case 95: goto tr790;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr790;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr790;
	} else
		goto tr790;
	goto tr787;
tr789:
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
	goto st552;
st552:
	if ( ++p == pe )
		goto _test_eof552;
case 552:
#line 11746 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 46 )
		goto tr794;
	if ( (*p) < 48 ) {
		if ( 33 <= (*p) && (*p) <= 47 )
			goto tr793;
	} else if ( (*p) > 57 ) {
		if ( 59 <= (*p) && (*p) <= 126 )
			goto tr793;
	} else
		goto tr795;
	goto tr792;
tr793:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st628;
tr803:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st628;
st628:
	if ( ++p == pe )
		goto _test_eof628;
case 628:
#line 11778 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 9: goto tr789;
		case 10: goto tr875;
		case 13: goto tr876;
		case 58: goto tr877;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr803;
	goto tr802;
tr875:
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
	goto st629;
st629:
	if ( ++p == pe )
		goto _test_eof629;
case 629:
#line 11845 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 10: goto tr871;
		case 13: goto tr872;
		case 43: goto tr878;
		case 60: goto st553;
		case 92: goto tr878;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr878;
		} else if ( (*p) >= 33 )
			goto tr878;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr878;
		} else if ( (*p) >= 63 )
			goto tr878;
	} else
		goto tr878;
	goto tr739;
tr870:
#line 70 "src/vcf/vcf.ragel"
	{
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (Error *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
    }
	goto st553;
st553:
	if ( ++p == pe )
		goto _test_eof553;
case 553:
#line 11882 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto tr796;
		case 92: goto tr796;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr796;
		} else if ( (*p) >= 33 )
			goto tr796;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr796;
		} else if ( (*p) >= 63 )
			goto tr796;
	} else
		goto tr796;
	goto tr739;
tr796:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st554;
tr797:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st554;
st554:
	if ( ++p == pe )
		goto _test_eof554;
case 554:
#line 11922 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto tr797;
		case 62: goto tr798;
		case 92: goto tr797;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr797;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr797;
		} else if ( (*p) >= 63 )
			goto tr797;
	} else
		goto tr797;
	goto tr739;
tr798:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st555;
st555:
	if ( ++p == pe )
		goto _test_eof555;
case 555:
#line 11950 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 9 )
		goto tr799;
	goto tr739;
tr876:
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
	goto st556;
st556:
	if ( ++p == pe )
		goto _test_eof556;
case 556:
#line 12011 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 10 )
		goto st629;
	goto tr800;
tr877:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st557;
st557:
	if ( ++p == pe )
		goto _test_eof557;
case 557:
#line 12025 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) > 57 ) {
		if ( 59 <= (*p) && (*p) <= 126 )
			goto tr803;
	} else if ( (*p) >= 33 )
		goto tr803;
	goto tr802;
tr794:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st630;
tr881:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st630;
st630:
	if ( ++p == pe )
		goto _test_eof630;
case 630:
#line 12052 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 9: goto tr789;
		case 10: goto tr875;
		case 13: goto tr876;
		case 47: goto tr880;
		case 58: goto tr877;
		case 124: goto tr880;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr803;
	goto tr792;
tr880:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st631;
st631:
	if ( ++p == pe )
		goto _test_eof631;
case 631:
#line 12074 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 9: goto tr789;
		case 10: goto tr875;
		case 13: goto tr876;
		case 46: goto tr881;
		case 58: goto tr877;
	}
	if ( (*p) < 48 ) {
		if ( 33 <= (*p) && (*p) <= 47 )
			goto tr803;
	} else if ( (*p) > 57 ) {
		if ( 59 <= (*p) && (*p) <= 126 )
			goto tr803;
	} else
		goto tr882;
	goto tr792;
tr795:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st632;
tr882:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st632;
st632:
	if ( ++p == pe )
		goto _test_eof632;
case 632:
#line 12111 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 9: goto tr789;
		case 10: goto tr875;
		case 13: goto tr876;
		case 47: goto tr880;
		case 58: goto tr877;
		case 124: goto tr880;
	}
	if ( (*p) < 48 ) {
		if ( 33 <= (*p) && (*p) <= 46 )
			goto tr803;
	} else if ( (*p) > 57 ) {
		if ( 59 <= (*p) && (*p) <= 126 )
			goto tr803;
	} else
		goto tr882;
	goto tr792;
tr785:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st558;
st558:
	if ( ++p == pe )
		goto _test_eof558;
case 558:
#line 12143 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 48 )
		goto tr804;
	goto tr783;
tr804:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st559;
st559:
	if ( ++p == pe )
		goto _test_eof559;
case 559:
#line 12157 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 48 )
		goto tr805;
	goto tr783;
tr805:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st560;
st560:
	if ( ++p == pe )
		goto _test_eof560;
case 560:
#line 12171 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 48 )
		goto tr806;
	goto tr783;
tr806:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st561;
st561:
	if ( ++p == pe )
		goto _test_eof561;
case 561:
#line 12185 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 71 )
		goto tr807;
	goto tr783;
tr807:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st633;
st633:
	if ( ++p == pe )
		goto _test_eof633;
case 633:
#line 12199 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 9: goto tr874;
		case 10: goto tr875;
		case 13: goto tr876;
		case 59: goto tr883;
		case 61: goto tr884;
	}
	goto tr783;
tr883:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st562;
st562:
	if ( ++p == pe )
		goto _test_eof562;
case 562:
#line 12218 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 49: goto tr785;
		case 95: goto tr786;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr786;
	} else if ( (*p) >= 65 )
		goto tr786;
	goto tr783;
tr786:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st634;
tr885:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st634;
st634:
	if ( ++p == pe )
		goto _test_eof634;
case 634:
#line 12249 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 9: goto tr874;
		case 10: goto tr875;
		case 13: goto tr876;
		case 46: goto tr885;
		case 59: goto tr883;
		case 61: goto tr884;
		case 95: goto tr885;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr885;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr885;
	} else
		goto tr885;
	goto tr783;
tr884:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st563;
st563:
	if ( ++p == pe )
		goto _test_eof563;
case 563:
#line 12278 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr809;
	} else if ( (*p) >= 32 )
		goto tr809;
	goto tr808;
tr809:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st635;
st635:
	if ( ++p == pe )
		goto _test_eof635;
case 635:
#line 12295 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 9: goto tr874;
		case 10: goto tr875;
		case 13: goto tr876;
		case 59: goto tr883;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr809;
	goto tr808;
tr782:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st564;
st564:
	if ( ++p == pe )
		goto _test_eof564;
case 564:
#line 12315 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 58 )
		goto tr776;
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr776;
		} else if ( (*p) > 57 ) {
			if ( 60 <= (*p) && (*p) <= 64 )
				goto tr776;
		} else
			goto tr778;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr776;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr776;
		} else
			goto tr778;
	} else
		goto tr778;
	goto tr775;
tr777:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st565;
st565:
	if ( ++p == pe )
		goto _test_eof565;
case 565:
#line 12353 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 9: goto tr781;
		case 58: goto st547;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto st547;
		} else if ( (*p) > 57 ) {
			if ( 60 <= (*p) && (*p) <= 64 )
				goto st547;
		} else
			goto tr780;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st547;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st547;
		} else
			goto tr780;
	} else
		goto tr780;
	goto tr775;
tr773:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st566;
st566:
	if ( ++p == pe )
		goto _test_eof566;
case 566:
#line 12389 "inc/vcf/validator_detail_v44.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr810;
	goto tr764;
tr810:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st567;
st567:
	if ( ++p == pe )
		goto _test_eof567;
case 567:
#line 12403 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 9: goto tr772;
		case 69: goto tr774;
		case 101: goto tr774;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr810;
	goto tr764;
tr774:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st568;
st568:
	if ( ++p == pe )
		goto _test_eof568;
case 568:
#line 12422 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto tr811;
		case 45: goto tr811;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr812;
	goto tr764;
tr811:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st569;
st569:
	if ( ++p == pe )
		goto _test_eof569;
case 569:
#line 12440 "inc/vcf/validator_detail_v44.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr812;
	goto tr764;
tr812:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st570;
st570:
	if ( ++p == pe )
		goto _test_eof570;
case 570:
#line 12454 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 9 )
		goto tr772;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr812;
	goto tr764;
tr768:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st571;
tr771:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st571;
st571:
	if ( ++p == pe )
		goto _test_eof571;
case 571:
#line 12480 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 110 )
		goto tr813;
	goto tr764;
tr813:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st572;
st572:
	if ( ++p == pe )
		goto _test_eof572;
case 572:
#line 12494 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 102 )
		goto tr814;
	goto tr764;
tr766:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st573;
tr814:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st573;
st573:
	if ( ++p == pe )
		goto _test_eof573;
case 573:
#line 12518 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 9 )
		goto tr772;
	goto tr764;
tr769:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st574;
st574:
	if ( ++p == pe )
		goto _test_eof574;
case 574:
#line 12536 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 97 )
		goto tr815;
	goto tr764;
tr815:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st575;
st575:
	if ( ++p == pe )
		goto _test_eof575;
case 575:
#line 12550 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 78 )
		goto tr814;
	goto tr764;
tr763:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st576;
st576:
	if ( ++p == pe )
		goto _test_eof576;
case 576:
#line 12564 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 42: goto tr756;
		case 46: goto tr816;
		case 60: goto tr758;
		case 65: goto tr759;
		case 67: goto tr759;
		case 71: goto tr759;
		case 78: goto tr759;
		case 84: goto tr759;
		case 91: goto tr760;
		case 93: goto tr761;
		case 97: goto tr759;
		case 99: goto tr759;
		case 103: goto tr759;
		case 110: goto tr759;
		case 116: goto tr759;
	}
	goto tr755;
tr816:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st577;
tr845:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st577;
st577:
	if ( ++p == pe )
		goto _test_eof577;
case 577:
#line 12603 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 65: goto tr817;
		case 67: goto tr817;
		case 71: goto tr817;
		case 78: goto tr817;
		case 84: goto tr817;
		case 97: goto tr817;
		case 99: goto tr817;
		case 103: goto tr817;
		case 110: goto tr817;
		case 116: goto tr817;
	}
	goto tr755;
tr817:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st578;
st578:
	if ( ++p == pe )
		goto _test_eof578;
case 578:
#line 12627 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 9: goto tr762;
		case 44: goto tr763;
		case 65: goto tr817;
		case 67: goto tr817;
		case 71: goto tr817;
		case 78: goto tr817;
		case 84: goto tr817;
		case 97: goto tr817;
		case 99: goto tr817;
		case 103: goto tr817;
		case 110: goto tr817;
		case 116: goto tr817;
	}
	goto tr755;
tr758:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st579;
st579:
	if ( ++p == pe )
		goto _test_eof579;
case 579:
#line 12657 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 42: goto tr819;
		case 61: goto tr818;
	}
	if ( (*p) < 63 ) {
		if ( (*p) < 45 ) {
			if ( 33 <= (*p) && (*p) <= 43 )
				goto tr818;
		} else if ( (*p) > 47 ) {
			if ( (*p) > 57 ) {
				if ( 58 <= (*p) && (*p) <= 59 )
					goto tr818;
			} else if ( (*p) >= 48 )
				goto tr820;
		} else
			goto tr818;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr820;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr818;
			} else if ( (*p) >= 97 )
				goto tr820;
		} else
			goto tr818;
	} else
		goto tr818;
	goto tr755;
tr818:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st580;
st580:
	if ( ++p == pe )
		goto _test_eof580;
case 580:
#line 12699 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 61 )
		goto tr818;
	if ( (*p) < 63 ) {
		if ( (*p) < 45 ) {
			if ( 33 <= (*p) && (*p) <= 43 )
				goto tr818;
		} else if ( (*p) > 47 ) {
			if ( (*p) > 57 ) {
				if ( 58 <= (*p) && (*p) <= 59 )
					goto tr818;
			} else if ( (*p) >= 48 )
				goto tr820;
		} else
			goto tr818;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr820;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr818;
			} else if ( (*p) >= 97 )
				goto tr820;
		} else
			goto tr818;
	} else
		goto tr818;
	goto tr755;
tr820:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st581;
st581:
	if ( ++p == pe )
		goto _test_eof581;
case 581:
#line 12739 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 62 )
		goto tr821;
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr820;
	} else if ( (*p) > 59 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr820;
	} else
		goto tr820;
	goto tr755;
tr819:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st582;
st582:
	if ( ++p == pe )
		goto _test_eof582;
case 582:
#line 12761 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 62 )
		goto tr821;
	if ( (*p) < 61 ) {
		if ( (*p) < 45 ) {
			if ( 33 <= (*p) && (*p) <= 43 )
				goto tr818;
		} else if ( (*p) > 47 ) {
			if ( (*p) > 57 ) {
				if ( 58 <= (*p) && (*p) <= 59 )
					goto tr818;
			} else if ( (*p) >= 48 )
				goto tr820;
		} else
			goto tr818;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr820;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr818;
			} else if ( (*p) >= 97 )
				goto tr820;
		} else
			goto tr818;
	} else
		goto tr818;
	goto tr755;
tr759:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st583;
tr822:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st583;
st583:
	if ( ++p == pe )
		goto _test_eof583;
case 583:
#line 12811 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 9: goto tr762;
		case 44: goto tr763;
		case 46: goto tr821;
		case 65: goto tr822;
		case 67: goto tr822;
		case 71: goto tr822;
		case 78: goto tr822;
		case 84: goto tr822;
		case 91: goto tr823;
		case 93: goto tr824;
		case 97: goto tr822;
		case 99: goto tr822;
		case 103: goto tr822;
		case 110: goto tr822;
		case 116: goto tr822;
	}
	goto tr755;
tr823:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st584;
st584:
	if ( ++p == pe )
		goto _test_eof584;
case 584:
#line 12840 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto tr825;
		case 60: goto tr826;
		case 92: goto tr825;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr825;
		} else if ( (*p) >= 33 )
			goto tr825;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr825;
		} else if ( (*p) >= 63 )
			goto tr825;
	} else
		goto tr825;
	goto tr755;
tr825:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st585;
st585:
	if ( ++p == pe )
		goto _test_eof585;
case 585:
#line 12871 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto tr825;
		case 58: goto tr827;
		case 92: goto tr825;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr825;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr825;
		} else if ( (*p) >= 63 )
			goto tr825;
	} else
		goto tr825;
	goto tr755;
tr827:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st586;
st586:
	if ( ++p == pe )
		goto _test_eof586;
case 586:
#line 12899 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto tr825;
		case 58: goto tr827;
		case 59: goto tr825;
		case 92: goto tr825;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 41 ) {
			if ( 45 <= (*p) && (*p) <= 47 )
				goto tr825;
		} else if ( (*p) >= 33 )
			goto tr825;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr825;
		} else if ( (*p) >= 63 )
			goto tr825;
	} else
		goto tr828;
	goto tr755;
tr828:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st587;
st587:
	if ( ++p == pe )
		goto _test_eof587;
case 587:
#line 12931 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto tr825;
		case 58: goto tr827;
		case 59: goto tr825;
		case 91: goto tr821;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 41 ) {
			if ( 45 <= (*p) && (*p) <= 47 )
				goto tr825;
		} else if ( (*p) >= 33 )
			goto tr825;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 92 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr825;
		} else if ( (*p) >= 63 )
			goto tr825;
	} else
		goto tr828;
	goto tr755;
tr826:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st588;
st588:
	if ( ++p == pe )
		goto _test_eof588;
case 588:
#line 12963 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto tr829;
		case 92: goto tr829;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr829;
		} else if ( (*p) >= 33 )
			goto tr829;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr829;
		} else if ( (*p) >= 63 )
			goto tr829;
	} else
		goto tr829;
	goto tr755;
tr829:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st589;
st589:
	if ( ++p == pe )
		goto _test_eof589;
case 589:
#line 12993 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto tr829;
		case 62: goto tr830;
		case 92: goto tr829;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr829;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr829;
		} else if ( (*p) >= 63 )
			goto tr829;
	} else
		goto tr829;
	goto tr755;
tr830:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st590;
st590:
	if ( ++p == pe )
		goto _test_eof590;
case 590:
#line 13021 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 58 )
		goto tr831;
	goto tr755;
tr831:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st591;
st591:
	if ( ++p == pe )
		goto _test_eof591;
case 591:
#line 13035 "inc/vcf/validator_detail_v44.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr832;
	goto tr755;
tr832:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st592;
st592:
	if ( ++p == pe )
		goto _test_eof592;
case 592:
#line 13049 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 91 )
		goto tr821;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr832;
	goto tr755;
tr824:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st593;
st593:
	if ( ++p == pe )
		goto _test_eof593;
case 593:
#line 13065 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto tr833;
		case 60: goto tr834;
		case 92: goto tr833;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr833;
		} else if ( (*p) >= 33 )
			goto tr833;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr833;
		} else if ( (*p) >= 63 )
			goto tr833;
	} else
		goto tr833;
	goto tr755;
tr833:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st594;
st594:
	if ( ++p == pe )
		goto _test_eof594;
case 594:
#line 13096 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto tr833;
		case 58: goto tr835;
		case 92: goto tr833;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr833;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr833;
		} else if ( (*p) >= 63 )
			goto tr833;
	} else
		goto tr833;
	goto tr755;
tr835:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st595;
st595:
	if ( ++p == pe )
		goto _test_eof595;
case 595:
#line 13124 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto tr833;
		case 58: goto tr835;
		case 59: goto tr833;
		case 92: goto tr833;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 41 ) {
			if ( 45 <= (*p) && (*p) <= 47 )
				goto tr833;
		} else if ( (*p) >= 33 )
			goto tr833;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr833;
		} else if ( (*p) >= 63 )
			goto tr833;
	} else
		goto tr836;
	goto tr755;
tr836:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st596;
st596:
	if ( ++p == pe )
		goto _test_eof596;
case 596:
#line 13156 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto tr833;
		case 58: goto tr835;
		case 59: goto tr833;
		case 93: goto tr821;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 41 ) {
			if ( 45 <= (*p) && (*p) <= 47 )
				goto tr833;
		} else if ( (*p) >= 33 )
			goto tr833;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 92 <= (*p) && (*p) <= 126 )
				goto tr833;
		} else if ( (*p) >= 63 )
			goto tr833;
	} else
		goto tr836;
	goto tr755;
tr834:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st597;
st597:
	if ( ++p == pe )
		goto _test_eof597;
case 597:
#line 13188 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto tr837;
		case 92: goto tr837;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr837;
		} else if ( (*p) >= 33 )
			goto tr837;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr837;
		} else if ( (*p) >= 63 )
			goto tr837;
	} else
		goto tr837;
	goto tr755;
tr837:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st598;
st598:
	if ( ++p == pe )
		goto _test_eof598;
case 598:
#line 13218 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto tr837;
		case 62: goto tr838;
		case 92: goto tr837;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr837;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr837;
		} else if ( (*p) >= 63 )
			goto tr837;
	} else
		goto tr837;
	goto tr755;
tr838:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st599;
st599:
	if ( ++p == pe )
		goto _test_eof599;
case 599:
#line 13246 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 58 )
		goto tr839;
	goto tr755;
tr839:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st600;
st600:
	if ( ++p == pe )
		goto _test_eof600;
case 600:
#line 13260 "inc/vcf/validator_detail_v44.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr840;
	goto tr755;
tr840:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st601;
st601:
	if ( ++p == pe )
		goto _test_eof601;
case 601:
#line 13274 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 93 )
		goto tr821;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr840;
	goto tr755;
tr760:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st602;
st602:
	if ( ++p == pe )
		goto _test_eof602;
case 602:
#line 13294 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto tr841;
		case 60: goto tr842;
		case 92: goto tr841;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr841;
		} else if ( (*p) >= 33 )
			goto tr841;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr841;
		} else if ( (*p) >= 63 )
			goto tr841;
	} else
		goto tr841;
	goto tr755;
tr841:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st603;
st603:
	if ( ++p == pe )
		goto _test_eof603;
case 603:
#line 13325 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto tr841;
		case 58: goto tr843;
		case 92: goto tr841;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr841;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr841;
		} else if ( (*p) >= 63 )
			goto tr841;
	} else
		goto tr841;
	goto tr755;
tr843:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st604;
st604:
	if ( ++p == pe )
		goto _test_eof604;
case 604:
#line 13353 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto tr841;
		case 58: goto tr843;
		case 59: goto tr841;
		case 92: goto tr841;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 41 ) {
			if ( 45 <= (*p) && (*p) <= 47 )
				goto tr841;
		} else if ( (*p) >= 33 )
			goto tr841;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr841;
		} else if ( (*p) >= 63 )
			goto tr841;
	} else
		goto tr844;
	goto tr755;
tr844:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st605;
st605:
	if ( ++p == pe )
		goto _test_eof605;
case 605:
#line 13385 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto tr841;
		case 58: goto tr843;
		case 59: goto tr841;
		case 91: goto tr845;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 41 ) {
			if ( 45 <= (*p) && (*p) <= 47 )
				goto tr841;
		} else if ( (*p) >= 33 )
			goto tr841;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 92 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr841;
		} else if ( (*p) >= 63 )
			goto tr841;
	} else
		goto tr844;
	goto tr755;
tr842:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st606;
st606:
	if ( ++p == pe )
		goto _test_eof606;
case 606:
#line 13417 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto tr846;
		case 92: goto tr846;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr846;
		} else if ( (*p) >= 33 )
			goto tr846;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr846;
		} else if ( (*p) >= 63 )
			goto tr846;
	} else
		goto tr846;
	goto tr755;
tr846:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st607;
st607:
	if ( ++p == pe )
		goto _test_eof607;
case 607:
#line 13447 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto tr846;
		case 62: goto tr847;
		case 92: goto tr846;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr846;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr846;
		} else if ( (*p) >= 63 )
			goto tr846;
	} else
		goto tr846;
	goto tr755;
tr847:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st608;
st608:
	if ( ++p == pe )
		goto _test_eof608;
case 608:
#line 13475 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 58 )
		goto tr848;
	goto tr755;
tr848:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st609;
st609:
	if ( ++p == pe )
		goto _test_eof609;
case 609:
#line 13489 "inc/vcf/validator_detail_v44.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr849;
	goto tr755;
tr849:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st610;
st610:
	if ( ++p == pe )
		goto _test_eof610;
case 610:
#line 13503 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 91 )
		goto tr845;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr849;
	goto tr755;
tr761:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st611;
st611:
	if ( ++p == pe )
		goto _test_eof611;
case 611:
#line 13523 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto tr850;
		case 60: goto tr851;
		case 92: goto tr850;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr850;
		} else if ( (*p) >= 33 )
			goto tr850;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr850;
		} else if ( (*p) >= 63 )
			goto tr850;
	} else
		goto tr850;
	goto tr755;
tr850:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st612;
st612:
	if ( ++p == pe )
		goto _test_eof612;
case 612:
#line 13554 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto tr850;
		case 58: goto tr852;
		case 92: goto tr850;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr850;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr850;
		} else if ( (*p) >= 63 )
			goto tr850;
	} else
		goto tr850;
	goto tr755;
tr852:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st613;
st613:
	if ( ++p == pe )
		goto _test_eof613;
case 613:
#line 13582 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto tr850;
		case 58: goto tr852;
		case 59: goto tr850;
		case 92: goto tr850;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 41 ) {
			if ( 45 <= (*p) && (*p) <= 47 )
				goto tr850;
		} else if ( (*p) >= 33 )
			goto tr850;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr850;
		} else if ( (*p) >= 63 )
			goto tr850;
	} else
		goto tr853;
	goto tr755;
tr853:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st614;
st614:
	if ( ++p == pe )
		goto _test_eof614;
case 614:
#line 13614 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto tr850;
		case 58: goto tr852;
		case 59: goto tr850;
		case 93: goto tr845;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 41 ) {
			if ( 45 <= (*p) && (*p) <= 47 )
				goto tr850;
		} else if ( (*p) >= 33 )
			goto tr850;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 92 <= (*p) && (*p) <= 126 )
				goto tr850;
		} else if ( (*p) >= 63 )
			goto tr850;
	} else
		goto tr853;
	goto tr755;
tr851:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st615;
st615:
	if ( ++p == pe )
		goto _test_eof615;
case 615:
#line 13646 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto tr854;
		case 92: goto tr854;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr854;
		} else if ( (*p) >= 33 )
			goto tr854;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr854;
		} else if ( (*p) >= 63 )
			goto tr854;
	} else
		goto tr854;
	goto tr755;
tr854:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st616;
st616:
	if ( ++p == pe )
		goto _test_eof616;
case 616:
#line 13676 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 43: goto tr854;
		case 62: goto tr855;
		case 92: goto tr854;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr854;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr854;
		} else if ( (*p) >= 63 )
			goto tr854;
	} else
		goto tr854;
	goto tr755;
tr855:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st617;
st617:
	if ( ++p == pe )
		goto _test_eof617;
case 617:
#line 13704 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 58 )
		goto tr856;
	goto tr755;
tr856:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st618;
st618:
	if ( ++p == pe )
		goto _test_eof618;
case 618:
#line 13718 "inc/vcf/validator_detail_v44.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr857;
	goto tr755;
tr857:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st619;
st619:
	if ( ++p == pe )
		goto _test_eof619;
case 619:
#line 13732 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 93 )
		goto tr845;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr857;
	goto tr755;
tr757:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st620;
st620:
	if ( ++p == pe )
		goto _test_eof620;
case 620:
#line 13752 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 9: goto tr762;
		case 65: goto tr817;
		case 67: goto tr817;
		case 71: goto tr817;
		case 78: goto tr817;
		case 84: goto tr817;
		case 97: goto tr817;
		case 99: goto tr817;
		case 103: goto tr817;
		case 110: goto tr817;
		case 116: goto tr817;
	}
	goto tr755;
tr723:
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
	goto st621;
tr735:
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
	goto st621;
st621:
	if ( ++p == pe )
		goto _test_eof621;
case 621:
#line 13815 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 10 )
		goto st625;
	goto tr724;
tr23:
#line 99 "src/vcf/vcf.ragel"
	{
        try {
          ParsePolicy::handle_fileformat(*this);
        } catch (Error *error) {
          ErrorPolicy::handle_error(*this, error);
          p--; {goto st623;}
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
case 622:
#line 13844 "inc/vcf/validator_detail_v44.hpp"
	if ( (*p) == 10 )
		goto st22;
	goto tr0;
tr862:
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
case 623:
#line 13864 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 10: goto tr861;
		case 13: goto tr862;
	}
	goto st623;
tr861:
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
	goto st636;
st636:
	if ( ++p == pe )
		goto _test_eof636;
case 636:
#line 13888 "inc/vcf/validator_detail_v44.hpp"
	goto st0;
tr865:
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
case 624:
#line 13906 "inc/vcf/validator_detail_v44.hpp"
	switch( (*p) ) {
		case 10: goto tr864;
		case 13: goto tr865;
	}
	goto st624;
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
#line 266 "src/vcf/vcf_v44.ragel"
	{ {goto st629;} }
	goto st637;
st637:
	if ( ++p == pe )
		goto _test_eof637;
case 637:
#line 13930 "inc/vcf/validator_detail_v44.hpp"
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
	_test_eof625: cs = 625; goto _test_eof; 
	_test_eof626: cs = 626; goto _test_eof; 
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
	_test_eof627: cs = 627; goto _test_eof; 
	_test_eof550: cs = 550; goto _test_eof; 
	_test_eof551: cs = 551; goto _test_eof; 
	_test_eof552: cs = 552; goto _test_eof; 
	_test_eof628: cs = 628; goto _test_eof; 
	_test_eof629: cs = 629; goto _test_eof; 
	_test_eof553: cs = 553; goto _test_eof; 
	_test_eof554: cs = 554; goto _test_eof; 
	_test_eof555: cs = 555; goto _test_eof; 
	_test_eof556: cs = 556; goto _test_eof; 
	_test_eof557: cs = 557; goto _test_eof; 
	_test_eof630: cs = 630; goto _test_eof; 
	_test_eof631: cs = 631; goto _test_eof; 
	_test_eof632: cs = 632; goto _test_eof; 
	_test_eof558: cs = 558; goto _test_eof; 
	_test_eof559: cs = 559; goto _test_eof; 
	_test_eof560: cs = 560; goto _test_eof; 
	_test_eof561: cs = 561; goto _test_eof; 
	_test_eof633: cs = 633; goto _test_eof; 
	_test_eof562: cs = 562; goto _test_eof; 
	_test_eof634: cs = 634; goto _test_eof; 
	_test_eof563: cs = 563; goto _test_eof; 
	_test_eof635: cs = 635; goto _test_eof; 
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
	_test_eof636: cs = 636; goto _test_eof; 
	_test_eof624: cs = 624; goto _test_eof; 
	_test_eof637: cs = 637; goto _test_eof; 

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
	case 622: 
#line 60 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new FileformatError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
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
               goto _test_eof623;
goto st623;}
    }
	break;
	case 625: 
#line 70 "src/vcf/vcf.ragel"
	{
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (Error *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
    }
	break;
	case 621: 
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
               goto _test_eof624;
goto st624;}
    }
	break;
	case 556: 
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
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
               goto _test_eof623;
goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
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
#line 271 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in assembly metadata"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
	break;
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
#line 277 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in contig metadata"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
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
               goto _test_eof623;
goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
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
               goto _test_eof623;
goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
	break;
	case 196: 
	case 197: 
	case 198: 
	case 199: 
	case 200: 
	case 201: 
	case 202: 
	case 203: 
	case 207: 
	case 208: 
	case 209: 
	case 210: 
	case 211: 
	case 212: 
	case 213: 
	case 216: 
	case 217: 
	case 218: 
	case 219: 
	case 220: 
	case 223: 
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
	case 242: 
	case 253: 
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
	break;
	case 308: 
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
	case 324: 
	case 325: 
	case 326: 
	case 327: 
	case 328: 
	case 329: 
	case 333: 
	case 334: 
	case 335: 
	case 336: 
	case 337: 
	case 338: 
	case 339: 
	case 343: 
	case 354: 
	case 355: 
	case 356: 
	case 357: 
	case 358: 
	case 359: 
	case 360: 
	case 361: 
#line 311 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
	break;
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
#line 332 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in pedigreeDB metadata"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
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
	case 273: 
	case 274: 
	case 275: 
	case 276: 
	case 277: 
	case 278: 
	case 279: 
	case 282: 
	case 283: 
	case 284: 
	case 285: 
	case 286: 
	case 294: 
	case 295: 
	case 296: 
	case 297: 
	case 298: 
	case 299: 
	case 300: 
	case 301: 
	case 302: 
	case 304: 
	case 305: 
	case 307: 
#line 338 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
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
#line 359 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
	break;
	case 534: 
	case 553: 
	case 554: 
	case 555: 
#line 408 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new ChromosomeBodyError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
	break;
	case 535: 
	case 536: 
#line 414 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new PositionBodyError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
	break;
	case 537: 
	case 538: 
#line 420 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new IdBodyError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
	break;
	case 539: 
	case 540: 
#line 426 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new ReferenceAlleleBodyError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
	break;
	case 541: 
	case 542: 
	case 576: 
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
#line 432 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new AlternateAllelesBodyError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
	break;
	case 543: 
	case 544: 
	case 545: 
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
#line 438 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new QualityBodyError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
	break;
	case 546: 
	case 547: 
	case 548: 
	case 564: 
	case 565: 
#line 444 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new FilterBodyError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
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
               goto _test_eof623;
goto st623;}
    }
#line 60 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new FileformatError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
	break;
	case 550: 
	case 551: 
#line 50 "src/vcf/vcf_v44.ragel"
	{
        ErrorPolicy::handle_error(*this, new FormatBodyError{n_lines, "Format does not start with a letter/underscore followed by alphanumeric/underscore/dot characters"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
	break;
	case 524: 
	case 525: 
	case 526: 
	case 527: 
	case 528: 
	case 529: 
	case 530: 
	case 531: 
	case 532: 
#line 55 "src/vcf/vcf_v44.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
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
               goto _test_eof624;
goto st624;}
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
               goto _test_eof623;
goto st623;}
    }
#line 259 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
	break;
	case 100: 
#line 283 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
	break;
	case 155: 
	case 156: 
#line 305 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "INFO metadata Type is not Integer, Float, Flag, Character or String"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
	break;
	case 221: 
	case 222: 
#line 305 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "INFO metadata Type is not Integer, Float, Flag, Character or String"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
	break;
	case 362: 
	case 363: 
	case 364: 
#line 316 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "PEDIGREE metadata Original is not valid"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 311 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
	break;
	case 330: 
	case 331: 
	case 332: 
	case 340: 
	case 341: 
	case 342: 
#line 321 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "PEDIGREE metadata Father or Mother is not valid"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 311 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
	break;
	case 323: 
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
#line 326 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "PEDIGREE metadata sequence of Name_N is not valid"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 311 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
	break;
	case 280: 
	case 281: 
#line 343 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "META metadata Number is not a dot"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 338 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
	break;
	case 287: 
	case 288: 
	case 289: 
	case 290: 
	case 291: 
	case 292: 
	case 293: 
#line 348 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "META metadata Type is not String"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 338 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
	break;
	case 303: 
	case 306: 
#line 353 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "META metadata Values is not a square-bracket delimited list of values"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 338 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
	break;
	case 84: 
	case 85: 
	case 86: 
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 259 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
	break;
	case 434: 
	case 435: 
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 277 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in contig metadata"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
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
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 283 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
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
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
	break;
	case 204: 
	case 205: 
	case 206: 
	case 239: 
	case 240: 
	case 241: 
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
	break;
	case 320: 
	case 321: 
	case 322: 
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 311 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
	break;
	case 270: 
	case 271: 
	case 272: 
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 338 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
	break;
	case 375: 
	case 376: 
	case 377: 
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 359 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
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
               goto _test_eof623;
goto st623;}
    }
#line 259 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
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
               goto _test_eof623;
goto st623;}
    }
#line 283 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
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
               goto _test_eof623;
goto st623;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
	break;
	case 236: 
	case 237: 
	case 238: 
	case 243: 
	case 244: 
	case 245: 
	case 246: 
	case 250: 
	case 251: 
	case 252: 
	case 254: 
	case 255: 
	case 259: 
	case 260: 
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
	break;
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
#line 385 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata URL is not valid"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 271 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in assembly metadata"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
	break;
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
#line 385 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata URL is not valid"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 332 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in pedigreeDB metadata"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
	break;
	case 148: 
	case 149: 
	case 195: 
#line 36 "src/vcf/vcf_v44.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "FORMAT metadata Number is not a number, A, R, G, P or dot"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
	break;
	case 214: 
	case 215: 
	case 261: 
#line 42 "src/vcf/vcf_v44.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "INFO metadata Number is not a number, A, R, G or dot"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
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
#line 55 "src/vcf/vcf_v44.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
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
               goto _test_eof624;
goto st624;}
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
               goto _test_eof624;
goto st624;}
    }
	break;
	case 557: 
#line 55 "src/vcf/vcf_v44.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 466 "src/vcf/vcf.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " is not a valid string";
        ErrorPolicy::handle_error(*this, new SamplesBodyError{n_lines, message_stream.str()});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
	break;
	case 627: 
	case 628: 
	case 633: 
	case 634: 
	case 635: 
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
               goto _test_eof624;
goto st624;}
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
               goto _test_eof623;
goto st623;}
    }
#line 55 "src/vcf/vcf_v44.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
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
               goto _test_eof624;
goto st624;}
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
               goto _test_eof624;
goto st624;}
    }
	break;
	case 94: 
	case 95: 
	case 96: 
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 259 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
	break;
	case 123: 
	case 124: 
	case 125: 
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 283 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
	break;
	case 181: 
	case 182: 
	case 183: 
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
	break;
	case 247: 
	case 248: 
	case 249: 
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
	break;
	case 190: 
	case 191: 
	case 192: 
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
	break;
	case 256: 
	case 257: 
	case 258: 
#line 380 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 375 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
	break;
	case 549: 
	case 558: 
	case 559: 
	case 560: 
	case 561: 
	case 562: 
#line 455 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info key is not a sequence of alphanumeric and/or punctuation characters"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 55 "src/vcf/vcf_v44.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 450 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
	break;
	case 563: 
#line 460 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info field value is not a comma-separated list of valid strings (maybe it contains whitespaces?)"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 55 "src/vcf/vcf_v44.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 450 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
	break;
	case 630: 
	case 631: 
	case 632: 
#line 55 "src/vcf/vcf_v44.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
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
	case 552: 
#line 55 "src/vcf/vcf_v44.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 473 "src/vcf/vcf.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " does not start with a valid genotype";
        ErrorPolicy::handle_error(*this, new SamplesFieldBodyError{n_lines, message_stream.str(), "", "GT"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 466 "src/vcf/vcf.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " is not a valid string";
        ErrorPolicy::handle_error(*this, new SamplesBodyError{n_lines, message_stream.str()});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
    }
	break;
	case 22: 
#line 60 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new FileformatError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 55 "src/vcf/vcf_v44.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {       if ( p == pe )
               goto _test_eof624;
goto st624;}
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
               goto _test_eof624;
goto st624;}
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
               goto _test_eof624;
goto st624;}
    }
	break;
	case 24: 
#line 259 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 283 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 300 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 271 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in assembly metadata"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 277 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in contig metadata"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 338 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 359 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 311 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 332 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in pedigreeDB metadata"});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {       if ( p == pe )
               goto _test_eof623;
goto st623;}
    }
	break;
#line 16738 "inc/vcf/validator_detail_v44.hpp"
	}
	}

	_out: {}
	}

#line 295 "src/vcf/vcf_v44.ragel"

    }
    
  }
}
