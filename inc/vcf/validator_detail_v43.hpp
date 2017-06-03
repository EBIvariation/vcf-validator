
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


#line 371 "src/vcf/vcf_v43.ragel"


namespace
{
  
#line 27 "inc/vcf/validator_detail_v43.hpp"
static const int vcf_v43_start = 1;
static const int vcf_v43_first_final = 724;
static const int vcf_v43_error = 0;

static const int vcf_v43_en_main = 1;
static const int vcf_v43_en_main_meta_section = 28;
static const int vcf_v43_en_main_body_section = 728;
static const int vcf_v43_en_meta_section_skip = 722;
static const int vcf_v43_en_body_section_skip = 723;


#line 377 "src/vcf/vcf_v43.ragel"

}

namespace ebi
{
  namespace vcf
  {
    
    template <typename Configuration>
    ParserImpl_v43<Configuration>::ParserImpl_v43(std::shared_ptr<Source> source)
    : ParserImpl{source}
    {
      
#line 53 "inc/vcf/validator_detail_v43.hpp"
	{
	cs = vcf_v43_start;
	}

#line 391 "src/vcf/vcf_v43.ragel"

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
case 1:
	if ( (*p) == 35 )
		goto st2;
	goto tr0;
tr0:
#line 60 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new FileformatError{n_lines});
        p--; {goto st722;}
    }
	goto st0;
tr14:
#line 52 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this,
                new FileformatError{n_lines, "The fileformat declaration is not 'fileformat=VCFv4.3'"});
        p--; {goto st722;}
    }
#line 60 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new FileformatError{n_lines});
        p--; {goto st722;}
    }
	goto st0;
tr24:
#line 60 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new FileformatError{n_lines});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
#line 305 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new HeaderSectionError{n_lines,
            "The header line does not start with the mandatory columns: CHROM, POS, ID, REF, ALT, QUAL, FILTER and INFO"});
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (Error *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
        
        p--; {goto st723;}
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
        
        p--; {goto st723;}
    }
	goto st0;
tr26:
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
#line 305 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new HeaderSectionError{n_lines,
            "The header line does not start with the mandatory columns: CHROM, POS, ID, REF, ALT, QUAL, FILTER and INFO"});
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (Error *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
        
        p--; {goto st723;}
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
        
        p--; {goto st723;}
    }
	goto st0;
tr29:
#line 219 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {goto st722;}
    }
#line 243 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {goto st722;}
    }
#line 249 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st722;}
    }
#line 260 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st722;}
    }
#line 231 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in assembly metadata"});
        p--; {goto st722;}
    }
#line 237 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in contig metadata"});
        p--; {goto st722;}
    }
#line 87 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
        p--; {goto st722;}
    }
#line 283 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st722;}
    }
#line 271 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {goto st722;}
    }
#line 277 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in pedigreeDB metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	goto st0;
tr40:
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	goto st0;
tr126:
#line 219 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	goto st0;
tr134:
#line 224 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines,
            "ALT metadata ID is not prefixed by DEL/INS/DUP/INV/CNV and suffixed by ':' and a text sequence"});
        p--; {goto st722;}
    }
#line 219 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	goto st0;
tr153:
#line 294 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st722;}
    }
#line 219 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	goto st0;
tr162:
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st722;}
    }
#line 219 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	goto st0;
tr176:
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st722;}
    }
#line 294 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st722;}
    }
#line 219 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	goto st0;
tr188:
#line 294 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st722;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st722;}
    }
#line 219 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	goto st0;
tr194:
#line 243 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {goto st722;}
    }
#line 249 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	goto st0;
tr197:
#line 243 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	goto st0;
tr207:
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st722;}
    }
#line 243 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	goto st0;
tr226:
#line 294 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st722;}
    }
#line 243 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	goto st0;
tr248:
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st722;}
    }
#line 294 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st722;}
    }
#line 243 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	goto st0;
tr260:
#line 294 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st722;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st722;}
    }
#line 243 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	goto st0;
tr266:
#line 249 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	goto st0;
tr276:
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st722;}
    }
#line 249 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	goto st0;
tr289:
#line 59 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "FORMAT metadata Number is not a number, A, R, G or dot"});
        p--; {goto st722;}
    }
#line 249 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	goto st0;
tr298:
#line 265 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "INFO metadata Type is not Integer, Float, Flag, Character or String"});
        p--; {goto st722;}
    }
#line 249 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	goto st0;
tr315:
#line 294 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st722;}
    }
#line 249 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	goto st0;
tr337:
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st722;}
    }
#line 294 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st722;}
    }
#line 249 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	goto st0;
tr349:
#line 294 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st722;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st722;}
    }
#line 249 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	goto st0;
tr356:
#line 260 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	goto st0;
tr365:
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st722;}
    }
#line 260 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	goto st0;
tr378:
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "INFO metadata Number is not a number, A, R, G or dot"});
        p--; {goto st722;}
    }
#line 260 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	goto st0;
tr387:
#line 265 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "INFO metadata Type is not Integer, Float, Flag, Character or String"});
        p--; {goto st722;}
    }
#line 260 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	goto st0;
tr404:
#line 294 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st722;}
    }
#line 260 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	goto st0;
tr426:
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st722;}
    }
#line 294 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st722;}
    }
#line 260 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	goto st0;
tr438:
#line 294 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st722;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st722;}
    }
#line 260 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	goto st0;
tr445:
#line 87 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	goto st0;
tr454:
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st722;}
    }
#line 87 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	goto st0;
tr467:
#line 92 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "META metadata Number is not a dot"});
        p--; {goto st722;}
    }
#line 87 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	goto st0;
tr475:
#line 97 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "META metadata Type is not String"});
        p--; {goto st722;}
    }
#line 87 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	goto st0;
tr492:
#line 102 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "META metadata Values is not a square-bracket delimited list of values"});
        p--; {goto st722;}
    }
#line 87 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	goto st0;
tr498:
#line 271 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	goto st0;
tr511:
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st722;}
    }
#line 271 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	goto st0;
tr517:
#line 81 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "PEDIGREE metadata sequence of Name_N is not valid"});
        p--; {goto st722;}
    }
#line 271 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	goto st0;
tr527:
#line 76 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "PEDIGREE metadata Father or Mother is not valid"});
        p--; {goto st722;}
    }
#line 271 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	goto st0;
tr564:
#line 71 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "PEDIGREE metadata Original is not valid"});
        p--; {goto st722;}
    }
#line 271 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	goto st0;
tr569:
#line 283 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	goto st0;
tr580:
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st722;}
    }
#line 283 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	goto st0;
tr620:
#line 231 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in assembly metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	goto st0;
tr629:
#line 299 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata URL is not valid"});
        p--; {goto st722;}
    }
#line 231 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in assembly metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	goto st0;
tr650:
#line 237 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in contig metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	goto st0;
tr661:
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st722;}
    }
#line 237 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in contig metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	goto st0;
tr699:
#line 277 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in pedigreeDB metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	goto st0;
tr711:
#line 299 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata URL is not valid"});
        p--; {goto st722;}
    }
#line 277 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in pedigreeDB metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	goto st0;
tr734:
#line 305 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new HeaderSectionError{n_lines,
            "The header line does not start with the mandatory columns: CHROM, POS, ID, REF, ALT, QUAL, FILTER and INFO"});
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (Error *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
        
        p--; {goto st723;}
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
        
        p--; {goto st723;}
    }
	goto st0;
tr774:
#line 78 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new HeaderSectionError{n_lines});
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (Error *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
        
        p--; {goto st723;}
    }
	goto st0;
tr789:
#line 322 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new ChromosomeBodyError{n_lines});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	goto st0;
tr792:
#line 328 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new PositionBodyError{n_lines});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	goto st0;
tr796:
#line 334 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new IdBodyError{n_lines});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	goto st0;
tr801:
#line 340 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new ReferenceAlleleBodyError{n_lines});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	goto st0;
tr805:
#line 346 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new AlternateAllelesBodyError{n_lines});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	goto st0;
tr814:
#line 352 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new QualityBodyError{n_lines});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	goto st0;
tr825:
#line 358 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new FilterBodyError{n_lines});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	goto st0;
tr833:
#line 369 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info key is not a sequence of alphanumeric and/or punctuation characters"});
        p--; {goto st723;}
    }
#line 364 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	goto st0;
tr847:
#line 135 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new FormatBodyError{n_lines, "Format does not start with a letter/underscore followed by alphanumeric/underscore/dot characters"});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	goto st0;
tr852:
#line 531 "src/vcf/vcf.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " does not start with a valid genotype";
        ErrorPolicy::handle_error(*this, new SamplesFieldBodyError{n_lines, message_stream.str(), "GT"});
        p--; {goto st723;}
    }
#line 524 "src/vcf/vcf.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " is not a valid string";
        ErrorPolicy::handle_error(*this, new SamplesBodyError{n_lines, message_stream.str()});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	goto st0;
tr860:
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	goto st0;
tr862:
#line 524 "src/vcf/vcf.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " is not a valid string";
        ErrorPolicy::handle_error(*this, new SamplesBodyError{n_lines, message_stream.str()});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	goto st0;
tr864:
#line 374 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info field value is not a comma-separated list of valid strings (maybe it contains whitespaces?)"});
        p--; {goto st723;}
    }
#line 364 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	goto st0;
tr866:
#line 515 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{
                n_lines,
                "Info 1000G is not a flag (with 1/0/no value)",
                "1000G"});
        p--; {goto st723;}
    }
#line 364 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	goto st0;
tr870:
#line 379 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{
                n_lines,
                "Info AA value is not a single dot or a string of bases",
                "AA"});
        p--; {goto st723;}
    }
#line 364 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	goto st0;
tr873:
#line 387 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{
                n_lines,
                "Info AC value is not a comma-separated list of numbers",
                "AC"});
        p--; {goto st723;}
    }
#line 364 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	goto st0;
tr878:
#line 110 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{
                n_lines,
                "Info AD value is not a comma-separated list of numbers",
                "AD"});
        p--; {goto st723;}
    }
#line 364 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	goto st0;
tr881:
#line 118 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{
                n_lines,
                "Info ADF value is not a comma-separated list of numbers",
                "ADF"});
        p--; {goto st723;}
    }
#line 364 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	goto st0;
tr884:
#line 126 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{
                n_lines,
                "Info ADR value is not a comma-separated list of numbers",
                "ADR"});
        p--; {goto st723;}
    }
#line 364 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	goto st0;
tr887:
#line 395 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{
                n_lines,
                "Info AF value is not a comma-separated list of numbers",
                "AF"});
        p--; {goto st723;}
    }
#line 364 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	goto st0;
tr899:
#line 403 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{
                n_lines,
                "Info AN value is not an integer number",
                "AN"});
        p--; {goto st723;}
    }
#line 364 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	goto st0;
tr902:
#line 411 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{
                n_lines,
                "Info BQ value is not a number",
                "BQ"});
        p--; {goto st723;}
    }
#line 364 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	goto st0;
tr914:
#line 419 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{
                n_lines,
                "Info CIGAR value is not an alphanumeric string compliant with the SAM specification",
                "CIGAR"});
        p--; {goto st723;}
    }
#line 364 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	goto st0;
tr917:
#line 427 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{
                n_lines,
                "Info DB is not a flag (with 1/0/no value)",
                "DB"});
        p--; {goto st723;}
    }
#line 364 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	goto st0;
tr920:
#line 435 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{
                n_lines,
                "Info DP value is not an integer number",
                "DP"});
        p--; {goto st723;}
    }
#line 364 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	goto st0;
tr923:
#line 443 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{
                n_lines,
                "Info END value is not an integer number",
                "END"});
        p--; {goto st723;}
    }
#line 364 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	goto st0;
tr925:
#line 451 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{
                n_lines,
                "Info H2 is not a flag (with 1/0/no value)",
                "H2"});
        p--; {goto st723;}
    }
#line 364 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	goto st0;
tr927:
#line 459 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{
                n_lines,
                "Info H3 is not a flag (with 1/0/no value)",
                "H3"});
        p--; {goto st723;}
    }
#line 364 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	goto st0;
tr932:
#line 475 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{
                n_lines,
                "Info MQ0 value is not an integer number",
                "MQ0"});
        p--; {goto st723;}
    }
#line 364 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	goto st0;
tr934:
#line 467 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{
                n_lines,
                "Info MQ value is not a number",
                "MQ"});
        p--; {goto st723;}
    }
#line 364 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	goto st0;
tr946:
#line 483 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{
                n_lines,
                "Info NS value is not an integer number",
                "NS"});
        p--; {goto st723;}
    }
#line 364 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	goto st0;
tr949:
#line 491 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{
                n_lines,
                "Info SB value is not a number",
                "SB"});
        p--; {goto st723;}
    }
#line 364 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	goto st0;
tr960:
#line 499 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{
                n_lines,
                "Info SOMATIC is not a flag (with 1/0/no value)",
                "SOMATIC"});
        p--; {goto st723;}
    }
#line 364 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	goto st0;
tr962:
#line 507 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{
                n_lines,
                "Info VALIDATED is not a flag (with 1/0/no value)",
                "VALIDATED"});
        p--; {goto st723;}
    }
#line 364 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	goto st0;
tr1011:
#line 78 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new HeaderSectionError{n_lines});
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (Error *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
        
        p--; {goto st723;}
    }
#line 322 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new ChromosomeBodyError{n_lines});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	goto st0;
tr1018:
#line 364 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	goto st0;
tr1034:
#line 515 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{
                n_lines,
                "Info 1000G is not a flag (with 1/0/no value)",
                "1000G"});
        p--; {goto st723;}
    }
#line 369 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info key is not a sequence of alphanumeric and/or punctuation characters"});
        p--; {goto st723;}
    }
#line 364 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	goto st0;
tr1052:
#line 427 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{
                n_lines,
                "Info DB is not a flag (with 1/0/no value)",
                "DB"});
        p--; {goto st723;}
    }
#line 369 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info key is not a sequence of alphanumeric and/or punctuation characters"});
        p--; {goto st723;}
    }
#line 364 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	goto st0;
tr1058:
#line 451 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{
                n_lines,
                "Info H2 is not a flag (with 1/0/no value)",
                "H2"});
        p--; {goto st723;}
    }
#line 369 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info key is not a sequence of alphanumeric and/or punctuation characters"});
        p--; {goto st723;}
    }
#line 364 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	goto st0;
tr1060:
#line 459 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{
                n_lines,
                "Info H3 is not a flag (with 1/0/no value)",
                "H3"});
        p--; {goto st723;}
    }
#line 369 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info key is not a sequence of alphanumeric and/or punctuation characters"});
        p--; {goto st723;}
    }
#line 364 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	goto st0;
tr1075:
#line 499 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{
                n_lines,
                "Info SOMATIC is not a flag (with 1/0/no value)",
                "SOMATIC"});
        p--; {goto st723;}
    }
#line 369 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info key is not a sequence of alphanumeric and/or punctuation characters"});
        p--; {goto st723;}
    }
#line 364 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	goto st0;
tr1085:
#line 507 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{
                n_lines,
                "Info VALIDATED is not a flag (with 1/0/no value)",
                "VALIDATED"});
        p--; {goto st723;}
    }
#line 369 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info key is not a sequence of alphanumeric and/or punctuation characters"});
        p--; {goto st723;}
    }
#line 364 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	goto st0;
#line 1795 "inc/vcf/validator_detail_v43.hpp"
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
#line 1904 "inc/vcf/validator_detail_v43.hpp"
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
#line 1918 "inc/vcf/validator_detail_v43.hpp"
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
#line 1932 "inc/vcf/validator_detail_v43.hpp"
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
#line 1946 "inc/vcf/validator_detail_v43.hpp"
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
#line 1960 "inc/vcf/validator_detail_v43.hpp"
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
#line 1974 "inc/vcf/validator_detail_v43.hpp"
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
case 21:
#line 1988 "inc/vcf/validator_detail_v43.hpp"
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
          p--; {goto st722;}
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
#line 2019 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 35 )
		goto st23;
	goto tr24;
st23:
	if ( ++p == pe )
		goto _test_eof23;
case 23:
	switch( (*p) ) {
		case 35: goto st24;
		case 67: goto st531;
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
#line 2073 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 61 )
		goto tr42;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr40;
tr42:
#line 160 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this);
    }
	goto st26;
st26:
	if ( ++p == pe )
		goto _test_eof26;
case 26:
#line 2089 "inc/vcf/validator_detail_v43.hpp"
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
#line 2117 "inc/vcf/validator_detail_v43.hpp"
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
#line 168 "src/vcf/vcf.ragel"
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
#line 168 "src/vcf/vcf.ragel"
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
#line 2173 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 35 )
		goto st23;
	goto tr26;
tr47:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 168 "src/vcf/vcf.ragel"
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
#line 168 "src/vcf/vcf.ragel"
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
#line 2225 "inc/vcf/validator_detail_v43.hpp"
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
#line 2260 "inc/vcf/validator_detail_v43.hpp"
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
#line 2288 "inc/vcf/validator_detail_v43.hpp"
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
#line 2314 "inc/vcf/validator_detail_v43.hpp"
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
#line 2336 "inc/vcf/validator_detail_v43.hpp"
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
#line 2397 "inc/vcf/validator_detail_v43.hpp"
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
#line 2425 "inc/vcf/validator_detail_v43.hpp"
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
#line 2449 "inc/vcf/validator_detail_v43.hpp"
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
#line 2471 "inc/vcf/validator_detail_v43.hpp"
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
#line 2490 "inc/vcf/validator_detail_v43.hpp"
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
#line 2510 "inc/vcf/validator_detail_v43.hpp"
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
#line 2545 "inc/vcf/validator_detail_v43.hpp"
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
#line 164 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st44;
st44:
	if ( ++p == pe )
		goto _test_eof44;
case 44:
#line 2572 "inc/vcf/validator_detail_v43.hpp"
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
#line 2604 "inc/vcf/validator_detail_v43.hpp"
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
#line 2625 "inc/vcf/validator_detail_v43.hpp"
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
#line 2650 "inc/vcf/validator_detail_v43.hpp"
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
#line 2685 "inc/vcf/validator_detail_v43.hpp"
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
#line 164 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st49;
st49:
	if ( ++p == pe )
		goto _test_eof49;
case 49:
#line 2712 "inc/vcf/validator_detail_v43.hpp"
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
#line 2755 "inc/vcf/validator_detail_v43.hpp"
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
#line 2783 "inc/vcf/validator_detail_v43.hpp"
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
#line 2809 "inc/vcf/validator_detail_v43.hpp"
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
#line 2831 "inc/vcf/validator_detail_v43.hpp"
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
#line 2871 "inc/vcf/validator_detail_v43.hpp"
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
#line 2922 "inc/vcf/validator_detail_v43.hpp"
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
#line 2973 "inc/vcf/validator_detail_v43.hpp"
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
#line 164 "src/vcf/vcf.ragel"
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
#line 3016 "inc/vcf/validator_detail_v43.hpp"
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
#line 3046 "inc/vcf/validator_detail_v43.hpp"
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
#line 3086 "inc/vcf/validator_detail_v43.hpp"
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
#line 3116 "inc/vcf/validator_detail_v43.hpp"
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
#line 3136 "inc/vcf/validator_detail_v43.hpp"
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
#line 3177 "inc/vcf/validator_detail_v43.hpp"
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
#line 3205 "inc/vcf/validator_detail_v43.hpp"
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
#line 3227 "inc/vcf/validator_detail_v43.hpp"
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
#line 3257 "inc/vcf/validator_detail_v43.hpp"
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
#line 3308 "inc/vcf/validator_detail_v43.hpp"
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
#line 3359 "inc/vcf/validator_detail_v43.hpp"
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
#line 164 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st70;
st70:
	if ( ++p == pe )
		goto _test_eof70;
case 70:
#line 3402 "inc/vcf/validator_detail_v43.hpp"
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
#line 3432 "inc/vcf/validator_detail_v43.hpp"
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
#line 3462 "inc/vcf/validator_detail_v43.hpp"
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
#line 3492 "inc/vcf/validator_detail_v43.hpp"
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
#line 3516 "inc/vcf/validator_detail_v43.hpp"
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
#line 3534 "inc/vcf/validator_detail_v43.hpp"
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
#line 3561 "inc/vcf/validator_detail_v43.hpp"
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
#line 3633 "inc/vcf/validator_detail_v43.hpp"
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
#line 3687 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 44: goto tr139;
		case 61: goto tr138;
	}
	if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
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
#line 3708 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 68 )
		goto st85;
	goto tr126;
st85:
	if ( ++p == pe )
		goto _test_eof85;
case 85:
	if ( (*p) == 101 )
		goto st86;
	goto tr126;
st86:
	if ( ++p == pe )
		goto _test_eof86;
case 86:
	if ( (*p) == 115 )
		goto st87;
	goto tr126;
st87:
	if ( ++p == pe )
		goto _test_eof87;
case 87:
	if ( (*p) == 99 )
		goto st88;
	goto tr126;
st88:
	if ( ++p == pe )
		goto _test_eof88;
case 88:
	if ( (*p) == 114 )
		goto st89;
	goto tr126;
st89:
	if ( ++p == pe )
		goto _test_eof89;
case 89:
	if ( (*p) == 105 )
		goto st90;
	goto tr126;
st90:
	if ( ++p == pe )
		goto _test_eof90;
case 90:
	if ( (*p) == 112 )
		goto st91;
	goto tr126;
st91:
	if ( ++p == pe )
		goto _test_eof91;
case 91:
	if ( (*p) == 116 )
		goto st92;
	goto tr126;
st92:
	if ( ++p == pe )
		goto _test_eof92;
case 92:
	if ( (*p) == 105 )
		goto st93;
	goto tr126;
st93:
	if ( ++p == pe )
		goto _test_eof93;
case 93:
	if ( (*p) == 111 )
		goto st94;
	goto tr126;
st94:
	if ( ++p == pe )
		goto _test_eof94;
case 94:
	if ( (*p) == 110 )
		goto st95;
	goto tr126;
st95:
	if ( ++p == pe )
		goto _test_eof95;
case 95:
	if ( (*p) == 61 )
		goto st96;
	goto tr126;
st96:
	if ( ++p == pe )
		goto _test_eof96;
case 96:
	if ( (*p) == 34 )
		goto tr152;
	goto tr126;
tr152:
#line 156 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Description");
    }
	goto st97;
st97:
	if ( ++p == pe )
		goto _test_eof97;
case 97:
#line 3806 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr155;
		case 92: goto tr156;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr154;
	goto tr153;
tr154:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st98;
tr157:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st98;
st98:
	if ( ++p == pe )
		goto _test_eof98;
case 98:
#line 3834 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr158;
		case 92: goto tr159;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr157;
	goto tr153;
tr155:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st99;
tr158:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st99;
st99:
	if ( ++p == pe )
		goto _test_eof99;
case 99:
#line 3862 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 44: goto st100;
		case 62: goto st114;
	}
	goto tr153;
st100:
	if ( ++p == pe )
		goto _test_eof100;
case 100:
	if ( (*p) == 95 )
		goto tr163;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr163;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr164;
		} else if ( (*p) >= 65 )
			goto tr164;
	} else
		goto tr164;
	goto tr162;
tr163:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st101;
st101:
	if ( ++p == pe )
		goto _test_eof101;
case 101:
#line 3896 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 95 )
		goto st101;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st101;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr166;
		} else if ( (*p) >= 65 )
			goto tr166;
	} else
		goto tr166;
	goto tr162;
tr164:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st102;
tr166:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st102;
st102:
	if ( ++p == pe )
		goto _test_eof102;
case 102:
#line 3931 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr167;
		case 95: goto tr166;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr166;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr166;
		} else if ( (*p) >= 65 )
			goto tr166;
	} else
		goto tr166;
	goto tr162;
tr167:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st103;
st103:
	if ( ++p == pe )
		goto _test_eof103;
case 103:
#line 3958 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 34 )
		goto st104;
	goto tr126;
st104:
	if ( ++p == pe )
		goto _test_eof104;
case 104:
	switch( (*p) ) {
		case 34: goto tr155;
		case 92: goto tr170;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr169;
	goto tr153;
tr169:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st105;
tr171:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st105;
st105:
	if ( ++p == pe )
		goto _test_eof105;
case 105:
#line 3993 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr158;
		case 92: goto tr172;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr171;
	goto tr153;
tr170:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st106;
tr172:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st106;
st106:
	if ( ++p == pe )
		goto _test_eof106;
case 106:
#line 4021 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr173;
		case 92: goto tr172;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr171;
	goto tr153;
tr173:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st107;
st107:
	if ( ++p == pe )
		goto _test_eof107;
case 107:
#line 4043 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr158;
		case 44: goto tr174;
		case 62: goto tr175;
		case 92: goto tr172;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr171;
	goto tr153;
tr183:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st108;
tr174:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st108;
st108:
	if ( ++p == pe )
		goto _test_eof108;
case 108:
#line 4073 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr158;
		case 47: goto tr171;
		case 92: goto tr172;
		case 95: goto tr177;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr171;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr178;
		} else
			goto tr177;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr178;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr171;
			} else if ( (*p) >= 97 )
				goto tr178;
		} else
			goto tr171;
	} else
		goto tr171;
	goto tr176;
tr177:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st109;
tr179:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st109;
st109:
	if ( ++p == pe )
		goto _test_eof109;
case 109:
#line 4124 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr158;
		case 47: goto tr171;
		case 92: goto tr172;
		case 95: goto tr179;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr171;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr180;
		} else
			goto tr179;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr180;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr171;
			} else if ( (*p) >= 97 )
				goto tr180;
		} else
			goto tr171;
	} else
		goto tr171;
	goto tr176;
tr178:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st110;
tr180:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st110;
st110:
	if ( ++p == pe )
		goto _test_eof110;
case 110:
#line 4175 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr158;
		case 47: goto tr171;
		case 61: goto tr181;
		case 92: goto tr172;
		case 95: goto tr180;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr171;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr171;
		} else
			goto tr180;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr171;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr171;
		} else
			goto tr180;
	} else
		goto tr180;
	goto tr176;
tr181:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st111;
st111:
	if ( ++p == pe )
		goto _test_eof111;
case 111:
#line 4218 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr182;
		case 92: goto tr172;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr171;
	goto tr153;
tr182:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st112;
st112:
	if ( ++p == pe )
		goto _test_eof112;
case 112:
#line 4236 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr155;
		case 44: goto tr183;
		case 62: goto tr184;
		case 92: goto tr170;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr169;
	goto tr153;
tr184:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st113;
tr175:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st113;
st113:
	if ( ++p == pe )
		goto _test_eof113;
case 113:
#line 4266 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
		case 34: goto tr158;
		case 92: goto tr172;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr171;
	goto tr153;
st114:
	if ( ++p == pe )
		goto _test_eof114;
case 114:
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
	}
	goto tr126;
tr156:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st115;
tr159:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st115;
st115:
	if ( ++p == pe )
		goto _test_eof115;
case 115:
#line 4305 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr185;
		case 92: goto tr159;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr157;
	goto tr153;
tr185:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st116;
st116:
	if ( ++p == pe )
		goto _test_eof116;
case 116:
#line 4327 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr158;
		case 44: goto tr186;
		case 62: goto tr187;
		case 92: goto tr159;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr157;
	goto tr153;
tr186:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st117;
st117:
	if ( ++p == pe )
		goto _test_eof117;
case 117:
#line 4347 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr158;
		case 47: goto tr157;
		case 92: goto tr159;
		case 95: goto tr189;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr157;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr190;
		} else
			goto tr189;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr190;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr157;
			} else if ( (*p) >= 97 )
				goto tr190;
		} else
			goto tr157;
	} else
		goto tr157;
	goto tr188;
tr191:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st118;
tr189:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st118;
st118:
	if ( ++p == pe )
		goto _test_eof118;
case 118:
#line 4398 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr158;
		case 47: goto tr157;
		case 92: goto tr159;
		case 95: goto tr191;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr157;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr192;
		} else
			goto tr191;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr192;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr157;
			} else if ( (*p) >= 97 )
				goto tr192;
		} else
			goto tr157;
	} else
		goto tr157;
	goto tr188;
tr192:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st119;
tr190:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st119;
st119:
	if ( ++p == pe )
		goto _test_eof119;
case 119:
#line 4449 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr158;
		case 47: goto tr157;
		case 61: goto tr193;
		case 92: goto tr159;
		case 95: goto tr192;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr157;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr157;
		} else
			goto tr192;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr157;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr157;
		} else
			goto tr192;
	} else
		goto tr192;
	goto tr188;
tr193:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st120;
st120:
	if ( ++p == pe )
		goto _test_eof120;
case 120:
#line 4492 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr182;
		case 92: goto tr159;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr157;
	goto tr153;
tr187:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st121;
st121:
	if ( ++p == pe )
		goto _test_eof121;
case 121:
#line 4510 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
		case 34: goto tr158;
		case 92: goto tr159;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr157;
	goto tr153;
tr32:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st122;
st122:
	if ( ++p == pe )
		goto _test_eof122;
case 122:
#line 4534 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 73: goto tr195;
		case 79: goto tr196;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr194;
tr195:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st123;
st123:
	if ( ++p == pe )
		goto _test_eof123;
case 123:
#line 4553 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 76: goto tr198;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr197;
tr198:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st124;
st124:
	if ( ++p == pe )
		goto _test_eof124;
case 124:
#line 4571 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 84: goto tr199;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr197;
tr199:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st125;
st125:
	if ( ++p == pe )
		goto _test_eof125;
case 125:
#line 4589 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 69: goto tr200;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr197;
tr200:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st126;
st126:
	if ( ++p == pe )
		goto _test_eof126;
case 126:
#line 4607 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 82: goto st127;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr197;
st127:
	if ( ++p == pe )
		goto _test_eof127;
case 127:
	if ( (*p) == 61 )
		goto tr202;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr197;
tr202:
#line 120 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "FILTER");
    }
	goto st128;
st128:
	if ( ++p == pe )
		goto _test_eof128;
case 128:
#line 4634 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 60 )
		goto st129;
	goto tr197;
st129:
	if ( ++p == pe )
		goto _test_eof129;
case 129:
	if ( (*p) == 73 )
		goto st130;
	goto tr197;
st130:
	if ( ++p == pe )
		goto _test_eof130;
case 130:
	if ( (*p) == 68 )
		goto st131;
	goto tr197;
st131:
	if ( ++p == pe )
		goto _test_eof131;
case 131:
	if ( (*p) == 61 )
		goto st132;
	goto tr197;
st132:
	if ( ++p == pe )
		goto _test_eof132;
case 132:
	if ( (*p) == 95 )
		goto tr208;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr208;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr209;
		} else if ( (*p) >= 65 )
			goto tr209;
	} else
		goto tr209;
	goto tr207;
tr208:
#line 144 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st133;
st133:
	if ( ++p == pe )
		goto _test_eof133;
case 133:
#line 4691 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 95 )
		goto st133;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st133;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr211;
		} else if ( (*p) >= 65 )
			goto tr211;
	} else
		goto tr211;
	goto tr207;
tr211:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st134;
tr209:
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
	goto st134;
st134:
	if ( ++p == pe )
		goto _test_eof134;
case 134:
#line 4730 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 44: goto tr212;
		case 95: goto tr211;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr211;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr211;
		} else if ( (*p) >= 65 )
			goto tr211;
	} else
		goto tr211;
	goto tr207;
tr212:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st135;
st135:
	if ( ++p == pe )
		goto _test_eof135;
case 135:
#line 4757 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 68 )
		goto st136;
	goto tr197;
st136:
	if ( ++p == pe )
		goto _test_eof136;
case 136:
	if ( (*p) == 101 )
		goto st137;
	goto tr197;
st137:
	if ( ++p == pe )
		goto _test_eof137;
case 137:
	if ( (*p) == 115 )
		goto st138;
	goto tr197;
st138:
	if ( ++p == pe )
		goto _test_eof138;
case 138:
	if ( (*p) == 99 )
		goto st139;
	goto tr197;
st139:
	if ( ++p == pe )
		goto _test_eof139;
case 139:
	if ( (*p) == 114 )
		goto st140;
	goto tr197;
st140:
	if ( ++p == pe )
		goto _test_eof140;
case 140:
	if ( (*p) == 105 )
		goto st141;
	goto tr197;
st141:
	if ( ++p == pe )
		goto _test_eof141;
case 141:
	if ( (*p) == 112 )
		goto st142;
	goto tr197;
st142:
	if ( ++p == pe )
		goto _test_eof142;
case 142:
	if ( (*p) == 116 )
		goto st143;
	goto tr197;
st143:
	if ( ++p == pe )
		goto _test_eof143;
case 143:
	if ( (*p) == 105 )
		goto st144;
	goto tr197;
st144:
	if ( ++p == pe )
		goto _test_eof144;
case 144:
	if ( (*p) == 111 )
		goto st145;
	goto tr197;
st145:
	if ( ++p == pe )
		goto _test_eof145;
case 145:
	if ( (*p) == 110 )
		goto st146;
	goto tr197;
st146:
	if ( ++p == pe )
		goto _test_eof146;
case 146:
	if ( (*p) == 61 )
		goto st147;
	goto tr197;
st147:
	if ( ++p == pe )
		goto _test_eof147;
case 147:
	if ( (*p) == 34 )
		goto tr225;
	goto tr197;
tr225:
#line 156 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Description");
    }
	goto st148;
st148:
	if ( ++p == pe )
		goto _test_eof148;
case 148:
#line 4855 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr228;
		case 92: goto tr229;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr227;
	goto tr226;
tr227:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st149;
tr230:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st149;
st149:
	if ( ++p == pe )
		goto _test_eof149;
case 149:
#line 4883 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr231;
		case 92: goto tr232;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr230;
	goto tr226;
tr228:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st150;
tr231:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st150;
st150:
	if ( ++p == pe )
		goto _test_eof150;
case 150:
#line 4911 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 44: goto st151;
		case 62: goto st165;
	}
	goto tr226;
st151:
	if ( ++p == pe )
		goto _test_eof151;
case 151:
	if ( (*p) == 95 )
		goto tr235;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr235;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr236;
		} else if ( (*p) >= 65 )
			goto tr236;
	} else
		goto tr236;
	goto tr207;
tr235:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st152;
st152:
	if ( ++p == pe )
		goto _test_eof152;
case 152:
#line 4945 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 95 )
		goto st152;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st152;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr238;
		} else if ( (*p) >= 65 )
			goto tr238;
	} else
		goto tr238;
	goto tr207;
tr236:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st153;
tr238:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st153;
st153:
	if ( ++p == pe )
		goto _test_eof153;
case 153:
#line 4980 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr239;
		case 95: goto tr238;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr238;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr238;
		} else if ( (*p) >= 65 )
			goto tr238;
	} else
		goto tr238;
	goto tr207;
tr239:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st154;
st154:
	if ( ++p == pe )
		goto _test_eof154;
case 154:
#line 5007 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 34 )
		goto st155;
	goto tr197;
st155:
	if ( ++p == pe )
		goto _test_eof155;
case 155:
	switch( (*p) ) {
		case 34: goto tr228;
		case 92: goto tr242;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr241;
	goto tr226;
tr241:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st156;
tr243:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st156;
st156:
	if ( ++p == pe )
		goto _test_eof156;
case 156:
#line 5042 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr231;
		case 92: goto tr244;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr243;
	goto tr226;
tr242:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st157;
tr244:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st157;
st157:
	if ( ++p == pe )
		goto _test_eof157;
case 157:
#line 5070 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr245;
		case 92: goto tr244;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr243;
	goto tr226;
tr245:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st158;
st158:
	if ( ++p == pe )
		goto _test_eof158;
case 158:
#line 5092 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr231;
		case 44: goto tr246;
		case 62: goto tr247;
		case 92: goto tr244;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr243;
	goto tr226;
tr255:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st159;
tr246:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st159;
st159:
	if ( ++p == pe )
		goto _test_eof159;
case 159:
#line 5122 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr231;
		case 47: goto tr243;
		case 92: goto tr244;
		case 95: goto tr249;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr243;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr250;
		} else
			goto tr249;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr250;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr243;
			} else if ( (*p) >= 97 )
				goto tr250;
		} else
			goto tr243;
	} else
		goto tr243;
	goto tr248;
tr249:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st160;
tr251:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st160;
st160:
	if ( ++p == pe )
		goto _test_eof160;
case 160:
#line 5173 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr231;
		case 47: goto tr243;
		case 92: goto tr244;
		case 95: goto tr251;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr243;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr252;
		} else
			goto tr251;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr252;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr243;
			} else if ( (*p) >= 97 )
				goto tr252;
		} else
			goto tr243;
	} else
		goto tr243;
	goto tr248;
tr250:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st161;
tr252:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st161;
st161:
	if ( ++p == pe )
		goto _test_eof161;
case 161:
#line 5224 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr231;
		case 47: goto tr243;
		case 61: goto tr253;
		case 92: goto tr244;
		case 95: goto tr252;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr243;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr243;
		} else
			goto tr252;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr243;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr243;
		} else
			goto tr252;
	} else
		goto tr252;
	goto tr248;
tr253:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st162;
st162:
	if ( ++p == pe )
		goto _test_eof162;
case 162:
#line 5267 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr254;
		case 92: goto tr244;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr243;
	goto tr226;
tr254:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st163;
st163:
	if ( ++p == pe )
		goto _test_eof163;
case 163:
#line 5285 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr228;
		case 44: goto tr255;
		case 62: goto tr256;
		case 92: goto tr242;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr241;
	goto tr226;
tr256:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st164;
tr247:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st164;
st164:
	if ( ++p == pe )
		goto _test_eof164;
case 164:
#line 5315 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
		case 34: goto tr231;
		case 92: goto tr244;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr243;
	goto tr226;
st165:
	if ( ++p == pe )
		goto _test_eof165;
case 165:
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
	}
	goto tr197;
tr229:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st166;
tr232:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st166;
st166:
	if ( ++p == pe )
		goto _test_eof166;
case 166:
#line 5354 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr257;
		case 92: goto tr232;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr230;
	goto tr226;
tr257:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st167;
st167:
	if ( ++p == pe )
		goto _test_eof167;
case 167:
#line 5376 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr231;
		case 44: goto tr258;
		case 62: goto tr259;
		case 92: goto tr232;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr230;
	goto tr226;
tr258:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st168;
st168:
	if ( ++p == pe )
		goto _test_eof168;
case 168:
#line 5396 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr231;
		case 47: goto tr230;
		case 92: goto tr232;
		case 95: goto tr261;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr230;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr262;
		} else
			goto tr261;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr262;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr230;
			} else if ( (*p) >= 97 )
				goto tr262;
		} else
			goto tr230;
	} else
		goto tr230;
	goto tr260;
tr263:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st169;
tr261:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st169;
st169:
	if ( ++p == pe )
		goto _test_eof169;
case 169:
#line 5447 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr231;
		case 47: goto tr230;
		case 92: goto tr232;
		case 95: goto tr263;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr230;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr264;
		} else
			goto tr263;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr264;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr230;
			} else if ( (*p) >= 97 )
				goto tr264;
		} else
			goto tr230;
	} else
		goto tr230;
	goto tr260;
tr264:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st170;
tr262:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st170;
st170:
	if ( ++p == pe )
		goto _test_eof170;
case 170:
#line 5498 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr231;
		case 47: goto tr230;
		case 61: goto tr265;
		case 92: goto tr232;
		case 95: goto tr264;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr230;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr230;
		} else
			goto tr264;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr230;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr230;
		} else
			goto tr264;
	} else
		goto tr264;
	goto tr260;
tr265:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st171;
st171:
	if ( ++p == pe )
		goto _test_eof171;
case 171:
#line 5541 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr254;
		case 92: goto tr232;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr230;
	goto tr226;
tr259:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st172;
st172:
	if ( ++p == pe )
		goto _test_eof172;
case 172:
#line 5559 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
		case 34: goto tr231;
		case 92: goto tr232;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr230;
	goto tr226;
tr196:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st173;
st173:
	if ( ++p == pe )
		goto _test_eof173;
case 173:
#line 5579 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 82: goto tr267;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr266;
tr267:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st174;
st174:
	if ( ++p == pe )
		goto _test_eof174;
case 174:
#line 5597 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 77: goto tr268;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr266;
tr268:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st175;
st175:
	if ( ++p == pe )
		goto _test_eof175;
case 175:
#line 5615 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 65: goto tr269;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr266;
tr269:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st176;
st176:
	if ( ++p == pe )
		goto _test_eof176;
case 176:
#line 5633 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 84: goto st177;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr266;
st177:
	if ( ++p == pe )
		goto _test_eof177;
case 177:
	if ( (*p) == 61 )
		goto tr271;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr266;
tr271:
#line 124 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "FORMAT");
    }
	goto st178;
st178:
	if ( ++p == pe )
		goto _test_eof178;
case 178:
#line 5660 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 60 )
		goto st179;
	goto tr266;
st179:
	if ( ++p == pe )
		goto _test_eof179;
case 179:
	if ( (*p) == 73 )
		goto st180;
	goto tr266;
st180:
	if ( ++p == pe )
		goto _test_eof180;
case 180:
	if ( (*p) == 68 )
		goto st181;
	goto tr266;
st181:
	if ( ++p == pe )
		goto _test_eof181;
case 181:
	if ( (*p) == 61 )
		goto st182;
	goto tr266;
st182:
	if ( ++p == pe )
		goto _test_eof182;
case 182:
	if ( (*p) == 95 )
		goto tr277;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr277;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr278;
		} else if ( (*p) >= 65 )
			goto tr278;
	} else
		goto tr278;
	goto tr276;
tr277:
#line 144 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st183;
st183:
	if ( ++p == pe )
		goto _test_eof183;
case 183:
#line 5717 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 95 )
		goto st183;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st183;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr280;
		} else if ( (*p) >= 65 )
			goto tr280;
	} else
		goto tr280;
	goto tr276;
tr280:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st184;
tr278:
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
	goto st184;
st184:
	if ( ++p == pe )
		goto _test_eof184;
case 184:
#line 5756 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 44: goto tr281;
		case 95: goto tr280;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr280;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr280;
		} else if ( (*p) >= 65 )
			goto tr280;
	} else
		goto tr280;
	goto tr276;
tr281:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st185;
st185:
	if ( ++p == pe )
		goto _test_eof185;
case 185:
#line 5783 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 78 )
		goto st186;
	goto tr266;
st186:
	if ( ++p == pe )
		goto _test_eof186;
case 186:
	if ( (*p) == 117 )
		goto st187;
	goto tr266;
st187:
	if ( ++p == pe )
		goto _test_eof187;
case 187:
	if ( (*p) == 109 )
		goto st188;
	goto tr266;
st188:
	if ( ++p == pe )
		goto _test_eof188;
case 188:
	if ( (*p) == 98 )
		goto st189;
	goto tr266;
st189:
	if ( ++p == pe )
		goto _test_eof189;
case 189:
	if ( (*p) == 101 )
		goto st190;
	goto tr266;
st190:
	if ( ++p == pe )
		goto _test_eof190;
case 190:
	if ( (*p) == 114 )
		goto st191;
	goto tr266;
st191:
	if ( ++p == pe )
		goto _test_eof191;
case 191:
	if ( (*p) == 61 )
		goto st192;
	goto tr266;
st192:
	if ( ++p == pe )
		goto _test_eof192;
case 192:
	switch( (*p) ) {
		case 46: goto tr290;
		case 65: goto tr290;
		case 71: goto tr290;
		case 82: goto tr290;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr291;
	goto tr289;
tr290:
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
	goto st193;
st193:
	if ( ++p == pe )
		goto _test_eof193;
case 193:
#line 5860 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 44 )
		goto tr292;
	goto tr289;
tr292:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st194;
st194:
	if ( ++p == pe )
		goto _test_eof194;
case 194:
#line 5874 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 84 )
		goto st195;
	goto tr266;
st195:
	if ( ++p == pe )
		goto _test_eof195;
case 195:
	if ( (*p) == 121 )
		goto st196;
	goto tr266;
st196:
	if ( ++p == pe )
		goto _test_eof196;
case 196:
	if ( (*p) == 112 )
		goto st197;
	goto tr266;
st197:
	if ( ++p == pe )
		goto _test_eof197;
case 197:
	if ( (*p) == 101 )
		goto st198;
	goto tr266;
st198:
	if ( ++p == pe )
		goto _test_eof198;
case 198:
	if ( (*p) == 61 )
		goto st199;
	goto tr266;
st199:
	if ( ++p == pe )
		goto _test_eof199;
case 199:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr299;
	} else if ( (*p) >= 65 )
		goto tr299;
	goto tr298;
tr301:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st200;
tr299:
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
	goto st200;
st200:
	if ( ++p == pe )
		goto _test_eof200;
case 200:
#line 5940 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 44 )
		goto tr300;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr301;
	} else if ( (*p) >= 65 )
		goto tr301;
	goto tr298;
tr300:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st201;
st201:
	if ( ++p == pe )
		goto _test_eof201;
case 201:
#line 5959 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 68 )
		goto st202;
	goto tr266;
st202:
	if ( ++p == pe )
		goto _test_eof202;
case 202:
	if ( (*p) == 101 )
		goto st203;
	goto tr266;
st203:
	if ( ++p == pe )
		goto _test_eof203;
case 203:
	if ( (*p) == 115 )
		goto st204;
	goto tr266;
st204:
	if ( ++p == pe )
		goto _test_eof204;
case 204:
	if ( (*p) == 99 )
		goto st205;
	goto tr266;
st205:
	if ( ++p == pe )
		goto _test_eof205;
case 205:
	if ( (*p) == 114 )
		goto st206;
	goto tr266;
st206:
	if ( ++p == pe )
		goto _test_eof206;
case 206:
	if ( (*p) == 105 )
		goto st207;
	goto tr266;
st207:
	if ( ++p == pe )
		goto _test_eof207;
case 207:
	if ( (*p) == 112 )
		goto st208;
	goto tr266;
st208:
	if ( ++p == pe )
		goto _test_eof208;
case 208:
	if ( (*p) == 116 )
		goto st209;
	goto tr266;
st209:
	if ( ++p == pe )
		goto _test_eof209;
case 209:
	if ( (*p) == 105 )
		goto st210;
	goto tr266;
st210:
	if ( ++p == pe )
		goto _test_eof210;
case 210:
	if ( (*p) == 111 )
		goto st211;
	goto tr266;
st211:
	if ( ++p == pe )
		goto _test_eof211;
case 211:
	if ( (*p) == 110 )
		goto st212;
	goto tr266;
st212:
	if ( ++p == pe )
		goto _test_eof212;
case 212:
	if ( (*p) == 61 )
		goto st213;
	goto tr266;
st213:
	if ( ++p == pe )
		goto _test_eof213;
case 213:
	if ( (*p) == 34 )
		goto tr314;
	goto tr266;
tr314:
#line 156 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Description");
    }
	goto st214;
st214:
	if ( ++p == pe )
		goto _test_eof214;
case 214:
#line 6057 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr317;
		case 92: goto tr318;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr316;
	goto tr315;
tr316:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st215;
tr319:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st215;
st215:
	if ( ++p == pe )
		goto _test_eof215;
case 215:
#line 6085 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr320;
		case 92: goto tr321;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr319;
	goto tr315;
tr317:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st216;
tr320:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st216;
st216:
	if ( ++p == pe )
		goto _test_eof216;
case 216:
#line 6113 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 44: goto st217;
		case 62: goto st231;
	}
	goto tr315;
st217:
	if ( ++p == pe )
		goto _test_eof217;
case 217:
	if ( (*p) == 95 )
		goto tr324;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr324;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr325;
		} else if ( (*p) >= 65 )
			goto tr325;
	} else
		goto tr325;
	goto tr276;
tr324:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st218;
st218:
	if ( ++p == pe )
		goto _test_eof218;
case 218:
#line 6147 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 95 )
		goto st218;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st218;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr327;
		} else if ( (*p) >= 65 )
			goto tr327;
	} else
		goto tr327;
	goto tr276;
tr325:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st219;
tr327:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st219;
st219:
	if ( ++p == pe )
		goto _test_eof219;
case 219:
#line 6182 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr328;
		case 95: goto tr327;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr327;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr327;
		} else if ( (*p) >= 65 )
			goto tr327;
	} else
		goto tr327;
	goto tr276;
tr328:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st220;
st220:
	if ( ++p == pe )
		goto _test_eof220;
case 220:
#line 6209 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 34 )
		goto st221;
	goto tr266;
st221:
	if ( ++p == pe )
		goto _test_eof221;
case 221:
	switch( (*p) ) {
		case 34: goto tr317;
		case 92: goto tr331;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr330;
	goto tr315;
tr330:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st222;
tr332:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st222;
st222:
	if ( ++p == pe )
		goto _test_eof222;
case 222:
#line 6244 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr320;
		case 92: goto tr333;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr332;
	goto tr315;
tr331:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st223;
tr333:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st223;
st223:
	if ( ++p == pe )
		goto _test_eof223;
case 223:
#line 6272 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr334;
		case 92: goto tr333;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr332;
	goto tr315;
tr334:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st224;
st224:
	if ( ++p == pe )
		goto _test_eof224;
case 224:
#line 6294 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr320;
		case 44: goto tr335;
		case 62: goto tr336;
		case 92: goto tr333;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr332;
	goto tr315;
tr344:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st225;
tr335:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st225;
st225:
	if ( ++p == pe )
		goto _test_eof225;
case 225:
#line 6324 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr320;
		case 47: goto tr332;
		case 92: goto tr333;
		case 95: goto tr338;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr332;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr339;
		} else
			goto tr338;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr339;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr332;
			} else if ( (*p) >= 97 )
				goto tr339;
		} else
			goto tr332;
	} else
		goto tr332;
	goto tr337;
tr338:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st226;
tr340:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st226;
st226:
	if ( ++p == pe )
		goto _test_eof226;
case 226:
#line 6375 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr320;
		case 47: goto tr332;
		case 92: goto tr333;
		case 95: goto tr340;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr332;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr341;
		} else
			goto tr340;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr341;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr332;
			} else if ( (*p) >= 97 )
				goto tr341;
		} else
			goto tr332;
	} else
		goto tr332;
	goto tr337;
tr339:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st227;
tr341:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st227;
st227:
	if ( ++p == pe )
		goto _test_eof227;
case 227:
#line 6426 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr320;
		case 47: goto tr332;
		case 61: goto tr342;
		case 92: goto tr333;
		case 95: goto tr341;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr332;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr332;
		} else
			goto tr341;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr332;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr332;
		} else
			goto tr341;
	} else
		goto tr341;
	goto tr337;
tr342:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st228;
st228:
	if ( ++p == pe )
		goto _test_eof228;
case 228:
#line 6469 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr343;
		case 92: goto tr333;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr332;
	goto tr315;
tr343:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st229;
st229:
	if ( ++p == pe )
		goto _test_eof229;
case 229:
#line 6487 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr317;
		case 44: goto tr344;
		case 62: goto tr345;
		case 92: goto tr331;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr330;
	goto tr315;
tr345:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st230;
tr336:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st230;
st230:
	if ( ++p == pe )
		goto _test_eof230;
case 230:
#line 6517 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
		case 34: goto tr320;
		case 92: goto tr333;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr332;
	goto tr315;
st231:
	if ( ++p == pe )
		goto _test_eof231;
case 231:
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
	}
	goto tr266;
tr318:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st232;
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
#line 6556 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr346;
		case 92: goto tr321;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr319;
	goto tr315;
tr346:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st233;
st233:
	if ( ++p == pe )
		goto _test_eof233;
case 233:
#line 6578 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr320;
		case 44: goto tr347;
		case 62: goto tr348;
		case 92: goto tr321;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr319;
	goto tr315;
tr347:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st234;
st234:
	if ( ++p == pe )
		goto _test_eof234;
case 234:
#line 6598 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr320;
		case 47: goto tr319;
		case 92: goto tr321;
		case 95: goto tr350;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr319;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr351;
		} else
			goto tr350;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr351;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr319;
			} else if ( (*p) >= 97 )
				goto tr351;
		} else
			goto tr319;
	} else
		goto tr319;
	goto tr349;
tr352:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st235;
tr350:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st235;
st235:
	if ( ++p == pe )
		goto _test_eof235;
case 235:
#line 6649 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr320;
		case 47: goto tr319;
		case 92: goto tr321;
		case 95: goto tr352;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr319;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr353;
		} else
			goto tr352;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr353;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr319;
			} else if ( (*p) >= 97 )
				goto tr353;
		} else
			goto tr319;
	} else
		goto tr319;
	goto tr349;
tr353:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st236;
tr351:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st236;
st236:
	if ( ++p == pe )
		goto _test_eof236;
case 236:
#line 6700 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr320;
		case 47: goto tr319;
		case 61: goto tr354;
		case 92: goto tr321;
		case 95: goto tr353;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr319;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr319;
		} else
			goto tr353;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr319;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr319;
		} else
			goto tr353;
	} else
		goto tr353;
	goto tr349;
tr354:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st237;
st237:
	if ( ++p == pe )
		goto _test_eof237;
case 237:
#line 6743 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr343;
		case 92: goto tr321;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr319;
	goto tr315;
tr348:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st238;
st238:
	if ( ++p == pe )
		goto _test_eof238;
case 238:
#line 6761 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
		case 34: goto tr320;
		case 92: goto tr321;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr319;
	goto tr315;
tr355:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st239;
tr291:
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
	goto st239;
st239:
	if ( ++p == pe )
		goto _test_eof239;
case 239:
#line 6795 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 44 )
		goto tr292;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr355;
	goto tr289;
tr33:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st240;
st240:
	if ( ++p == pe )
		goto _test_eof240;
case 240:
#line 6815 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 78: goto tr357;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr356;
tr357:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st241;
st241:
	if ( ++p == pe )
		goto _test_eof241;
case 241:
#line 6833 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 70: goto tr358;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr356;
tr358:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st242;
st242:
	if ( ++p == pe )
		goto _test_eof242;
case 242:
#line 6851 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 79: goto st243;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr356;
st243:
	if ( ++p == pe )
		goto _test_eof243;
case 243:
	if ( (*p) == 61 )
		goto tr360;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr356;
tr360:
#line 128 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "INFO");
    }
	goto st244;
st244:
	if ( ++p == pe )
		goto _test_eof244;
case 244:
#line 6878 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 60 )
		goto st245;
	goto tr356;
st245:
	if ( ++p == pe )
		goto _test_eof245;
case 245:
	if ( (*p) == 73 )
		goto st246;
	goto tr356;
st246:
	if ( ++p == pe )
		goto _test_eof246;
case 246:
	if ( (*p) == 68 )
		goto st247;
	goto tr356;
st247:
	if ( ++p == pe )
		goto _test_eof247;
case 247:
	if ( (*p) == 61 )
		goto st248;
	goto tr356;
st248:
	if ( ++p == pe )
		goto _test_eof248;
case 248:
	if ( (*p) == 95 )
		goto tr366;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr366;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr367;
		} else if ( (*p) >= 65 )
			goto tr367;
	} else
		goto tr367;
	goto tr365;
tr366:
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
#line 6935 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 95 )
		goto st249;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st249;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr369;
		} else if ( (*p) >= 65 )
			goto tr369;
	} else
		goto tr369;
	goto tr365;
tr369:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st250;
tr367:
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
#line 6974 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 44: goto tr370;
		case 95: goto tr369;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr369;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr369;
		} else if ( (*p) >= 65 )
			goto tr369;
	} else
		goto tr369;
	goto tr365;
tr370:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st251;
st251:
	if ( ++p == pe )
		goto _test_eof251;
case 251:
#line 7001 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 78 )
		goto st252;
	goto tr356;
st252:
	if ( ++p == pe )
		goto _test_eof252;
case 252:
	if ( (*p) == 117 )
		goto st253;
	goto tr356;
st253:
	if ( ++p == pe )
		goto _test_eof253;
case 253:
	if ( (*p) == 109 )
		goto st254;
	goto tr356;
st254:
	if ( ++p == pe )
		goto _test_eof254;
case 254:
	if ( (*p) == 98 )
		goto st255;
	goto tr356;
st255:
	if ( ++p == pe )
		goto _test_eof255;
case 255:
	if ( (*p) == 101 )
		goto st256;
	goto tr356;
st256:
	if ( ++p == pe )
		goto _test_eof256;
case 256:
	if ( (*p) == 114 )
		goto st257;
	goto tr356;
st257:
	if ( ++p == pe )
		goto _test_eof257;
case 257:
	if ( (*p) == 61 )
		goto st258;
	goto tr356;
st258:
	if ( ++p == pe )
		goto _test_eof258;
case 258:
	switch( (*p) ) {
		case 46: goto tr379;
		case 65: goto tr379;
		case 71: goto tr379;
		case 82: goto tr379;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr380;
	goto tr378;
tr379:
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
	goto st259;
st259:
	if ( ++p == pe )
		goto _test_eof259;
case 259:
#line 7078 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 44 )
		goto tr381;
	goto tr378;
tr381:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st260;
st260:
	if ( ++p == pe )
		goto _test_eof260;
case 260:
#line 7092 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 84 )
		goto st261;
	goto tr356;
st261:
	if ( ++p == pe )
		goto _test_eof261;
case 261:
	if ( (*p) == 121 )
		goto st262;
	goto tr356;
st262:
	if ( ++p == pe )
		goto _test_eof262;
case 262:
	if ( (*p) == 112 )
		goto st263;
	goto tr356;
st263:
	if ( ++p == pe )
		goto _test_eof263;
case 263:
	if ( (*p) == 101 )
		goto st264;
	goto tr356;
st264:
	if ( ++p == pe )
		goto _test_eof264;
case 264:
	if ( (*p) == 61 )
		goto st265;
	goto tr356;
st265:
	if ( ++p == pe )
		goto _test_eof265;
case 265:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr388;
	} else if ( (*p) >= 65 )
		goto tr388;
	goto tr387;
tr390:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st266;
tr388:
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
	goto st266;
st266:
	if ( ++p == pe )
		goto _test_eof266;
case 266:
#line 7158 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 44 )
		goto tr389;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr390;
	} else if ( (*p) >= 65 )
		goto tr390;
	goto tr387;
tr389:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st267;
st267:
	if ( ++p == pe )
		goto _test_eof267;
case 267:
#line 7177 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 68 )
		goto st268;
	goto tr356;
st268:
	if ( ++p == pe )
		goto _test_eof268;
case 268:
	if ( (*p) == 101 )
		goto st269;
	goto tr356;
st269:
	if ( ++p == pe )
		goto _test_eof269;
case 269:
	if ( (*p) == 115 )
		goto st270;
	goto tr356;
st270:
	if ( ++p == pe )
		goto _test_eof270;
case 270:
	if ( (*p) == 99 )
		goto st271;
	goto tr356;
st271:
	if ( ++p == pe )
		goto _test_eof271;
case 271:
	if ( (*p) == 114 )
		goto st272;
	goto tr356;
st272:
	if ( ++p == pe )
		goto _test_eof272;
case 272:
	if ( (*p) == 105 )
		goto st273;
	goto tr356;
st273:
	if ( ++p == pe )
		goto _test_eof273;
case 273:
	if ( (*p) == 112 )
		goto st274;
	goto tr356;
st274:
	if ( ++p == pe )
		goto _test_eof274;
case 274:
	if ( (*p) == 116 )
		goto st275;
	goto tr356;
st275:
	if ( ++p == pe )
		goto _test_eof275;
case 275:
	if ( (*p) == 105 )
		goto st276;
	goto tr356;
st276:
	if ( ++p == pe )
		goto _test_eof276;
case 276:
	if ( (*p) == 111 )
		goto st277;
	goto tr356;
st277:
	if ( ++p == pe )
		goto _test_eof277;
case 277:
	if ( (*p) == 110 )
		goto st278;
	goto tr356;
st278:
	if ( ++p == pe )
		goto _test_eof278;
case 278:
	if ( (*p) == 61 )
		goto st279;
	goto tr356;
st279:
	if ( ++p == pe )
		goto _test_eof279;
case 279:
	if ( (*p) == 34 )
		goto tr403;
	goto tr356;
tr403:
#line 156 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Description");
    }
	goto st280;
st280:
	if ( ++p == pe )
		goto _test_eof280;
case 280:
#line 7275 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr406;
		case 92: goto tr407;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr405;
	goto tr404;
tr405:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st281;
tr408:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st281;
st281:
	if ( ++p == pe )
		goto _test_eof281;
case 281:
#line 7303 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr409;
		case 92: goto tr410;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr408;
	goto tr404;
tr406:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st282;
tr409:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st282;
st282:
	if ( ++p == pe )
		goto _test_eof282;
case 282:
#line 7331 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 44: goto st283;
		case 62: goto st297;
	}
	goto tr404;
st283:
	if ( ++p == pe )
		goto _test_eof283;
case 283:
	if ( (*p) == 95 )
		goto tr413;
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
	goto tr365;
tr413:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st284;
st284:
	if ( ++p == pe )
		goto _test_eof284;
case 284:
#line 7365 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 95 )
		goto st284;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st284;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr416;
		} else if ( (*p) >= 65 )
			goto tr416;
	} else
		goto tr416;
	goto tr365;
tr414:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st285;
tr416:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st285;
st285:
	if ( ++p == pe )
		goto _test_eof285;
case 285:
#line 7400 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr417;
		case 95: goto tr416;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr416;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr416;
		} else if ( (*p) >= 65 )
			goto tr416;
	} else
		goto tr416;
	goto tr365;
tr417:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st286;
st286:
	if ( ++p == pe )
		goto _test_eof286;
case 286:
#line 7427 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 34 )
		goto st287;
	goto tr356;
st287:
	if ( ++p == pe )
		goto _test_eof287;
case 287:
	switch( (*p) ) {
		case 34: goto tr406;
		case 92: goto tr420;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr419;
	goto tr404;
tr419:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st288;
tr421:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st288;
st288:
	if ( ++p == pe )
		goto _test_eof288;
case 288:
#line 7462 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr409;
		case 92: goto tr422;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr421;
	goto tr404;
tr420:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st289;
tr422:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st289;
st289:
	if ( ++p == pe )
		goto _test_eof289;
case 289:
#line 7490 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr423;
		case 92: goto tr422;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr421;
	goto tr404;
tr423:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st290;
st290:
	if ( ++p == pe )
		goto _test_eof290;
case 290:
#line 7512 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr409;
		case 44: goto tr424;
		case 62: goto tr425;
		case 92: goto tr422;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr421;
	goto tr404;
tr433:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st291;
tr424:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st291;
st291:
	if ( ++p == pe )
		goto _test_eof291;
case 291:
#line 7542 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr409;
		case 47: goto tr421;
		case 92: goto tr422;
		case 95: goto tr427;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr421;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr428;
		} else
			goto tr427;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr428;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr421;
			} else if ( (*p) >= 97 )
				goto tr428;
		} else
			goto tr421;
	} else
		goto tr421;
	goto tr426;
tr427:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st292;
tr429:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st292;
st292:
	if ( ++p == pe )
		goto _test_eof292;
case 292:
#line 7593 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr409;
		case 47: goto tr421;
		case 92: goto tr422;
		case 95: goto tr429;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr421;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr430;
		} else
			goto tr429;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr430;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr421;
			} else if ( (*p) >= 97 )
				goto tr430;
		} else
			goto tr421;
	} else
		goto tr421;
	goto tr426;
tr428:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st293;
tr430:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st293;
st293:
	if ( ++p == pe )
		goto _test_eof293;
case 293:
#line 7644 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr409;
		case 47: goto tr421;
		case 61: goto tr431;
		case 92: goto tr422;
		case 95: goto tr430;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr421;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr421;
		} else
			goto tr430;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr421;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr421;
		} else
			goto tr430;
	} else
		goto tr430;
	goto tr426;
tr431:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st294;
st294:
	if ( ++p == pe )
		goto _test_eof294;
case 294:
#line 7687 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr432;
		case 92: goto tr422;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr421;
	goto tr404;
tr432:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st295;
st295:
	if ( ++p == pe )
		goto _test_eof295;
case 295:
#line 7705 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr406;
		case 44: goto tr433;
		case 62: goto tr434;
		case 92: goto tr420;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr419;
	goto tr404;
tr434:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st296;
tr425:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st296;
st296:
	if ( ++p == pe )
		goto _test_eof296;
case 296:
#line 7735 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
		case 34: goto tr409;
		case 92: goto tr422;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr421;
	goto tr404;
st297:
	if ( ++p == pe )
		goto _test_eof297;
case 297:
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
	}
	goto tr356;
tr407:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st298;
tr410:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st298;
st298:
	if ( ++p == pe )
		goto _test_eof298;
case 298:
#line 7774 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr435;
		case 92: goto tr410;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr408;
	goto tr404;
tr435:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st299;
st299:
	if ( ++p == pe )
		goto _test_eof299;
case 299:
#line 7796 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr409;
		case 44: goto tr436;
		case 62: goto tr437;
		case 92: goto tr410;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr408;
	goto tr404;
tr436:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st300;
st300:
	if ( ++p == pe )
		goto _test_eof300;
case 300:
#line 7816 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr409;
		case 47: goto tr408;
		case 92: goto tr410;
		case 95: goto tr439;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr408;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr440;
		} else
			goto tr439;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr440;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr408;
			} else if ( (*p) >= 97 )
				goto tr440;
		} else
			goto tr408;
	} else
		goto tr408;
	goto tr438;
tr441:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st301;
tr439:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st301;
st301:
	if ( ++p == pe )
		goto _test_eof301;
case 301:
#line 7867 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr409;
		case 47: goto tr408;
		case 92: goto tr410;
		case 95: goto tr441;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr408;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr442;
		} else
			goto tr441;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr442;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr408;
			} else if ( (*p) >= 97 )
				goto tr442;
		} else
			goto tr408;
	} else
		goto tr408;
	goto tr438;
tr442:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st302;
tr440:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st302;
st302:
	if ( ++p == pe )
		goto _test_eof302;
case 302:
#line 7918 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr409;
		case 47: goto tr408;
		case 61: goto tr443;
		case 92: goto tr410;
		case 95: goto tr442;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr408;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr408;
		} else
			goto tr442;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr408;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr408;
		} else
			goto tr442;
	} else
		goto tr442;
	goto tr438;
tr443:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st303;
st303:
	if ( ++p == pe )
		goto _test_eof303;
case 303:
#line 7961 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr432;
		case 92: goto tr410;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr408;
	goto tr404;
tr437:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st304;
st304:
	if ( ++p == pe )
		goto _test_eof304;
case 304:
#line 7979 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
		case 34: goto tr409;
		case 92: goto tr410;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr408;
	goto tr404;
tr444:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st305;
tr380:
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
	goto st305;
st305:
	if ( ++p == pe )
		goto _test_eof305;
case 305:
#line 8013 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 44 )
		goto tr381;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr444;
	goto tr378;
tr34:
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
case 306:
#line 8033 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 69: goto tr446;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr445;
tr446:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st307;
st307:
	if ( ++p == pe )
		goto _test_eof307;
case 307:
#line 8051 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 84: goto tr447;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr445;
tr447:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st308;
st308:
	if ( ++p == pe )
		goto _test_eof308;
case 308:
#line 8069 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 65: goto st309;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr445;
st309:
	if ( ++p == pe )
		goto _test_eof309;
case 309:
	if ( (*p) == 61 )
		goto tr449;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr445;
tr449:
#line 28 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "META");
    }
	goto st310;
st310:
	if ( ++p == pe )
		goto _test_eof310;
case 310:
#line 8096 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 60 )
		goto st311;
	goto tr445;
st311:
	if ( ++p == pe )
		goto _test_eof311;
case 311:
	if ( (*p) == 73 )
		goto st312;
	goto tr445;
st312:
	if ( ++p == pe )
		goto _test_eof312;
case 312:
	if ( (*p) == 68 )
		goto st313;
	goto tr445;
st313:
	if ( ++p == pe )
		goto _test_eof313;
case 313:
	if ( (*p) == 61 )
		goto st314;
	goto tr445;
st314:
	if ( ++p == pe )
		goto _test_eof314;
case 314:
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
#line 144 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st315;
st315:
	if ( ++p == pe )
		goto _test_eof315;
case 315:
#line 8153 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 95 )
		goto st315;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st315;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr458;
		} else if ( (*p) >= 65 )
			goto tr458;
	} else
		goto tr458;
	goto tr454;
tr458:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st316;
tr456:
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
	goto st316;
st316:
	if ( ++p == pe )
		goto _test_eof316;
case 316:
#line 8192 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 44: goto tr459;
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
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st317;
st317:
	if ( ++p == pe )
		goto _test_eof317;
case 317:
#line 8219 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 78 )
		goto st318;
	goto tr445;
st318:
	if ( ++p == pe )
		goto _test_eof318;
case 318:
	if ( (*p) == 117 )
		goto st319;
	goto tr445;
st319:
	if ( ++p == pe )
		goto _test_eof319;
case 319:
	if ( (*p) == 109 )
		goto st320;
	goto tr445;
st320:
	if ( ++p == pe )
		goto _test_eof320;
case 320:
	if ( (*p) == 98 )
		goto st321;
	goto tr445;
st321:
	if ( ++p == pe )
		goto _test_eof321;
case 321:
	if ( (*p) == 101 )
		goto st322;
	goto tr445;
st322:
	if ( ++p == pe )
		goto _test_eof322;
case 322:
	if ( (*p) == 114 )
		goto st323;
	goto tr445;
st323:
	if ( ++p == pe )
		goto _test_eof323;
case 323:
	if ( (*p) == 61 )
		goto st324;
	goto tr445;
st324:
	if ( ++p == pe )
		goto _test_eof324;
case 324:
	if ( (*p) == 46 )
		goto tr468;
	goto tr467;
tr468:
#line 148 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Number");
    }
	goto st325;
st325:
	if ( ++p == pe )
		goto _test_eof325;
case 325:
#line 8282 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 44 )
		goto st326;
	goto tr467;
st326:
	if ( ++p == pe )
		goto _test_eof326;
case 326:
	if ( (*p) == 84 )
		goto st327;
	goto tr445;
st327:
	if ( ++p == pe )
		goto _test_eof327;
case 327:
	if ( (*p) == 121 )
		goto st328;
	goto tr445;
st328:
	if ( ++p == pe )
		goto _test_eof328;
case 328:
	if ( (*p) == 112 )
		goto st329;
	goto tr445;
st329:
	if ( ++p == pe )
		goto _test_eof329;
case 329:
	if ( (*p) == 101 )
		goto st330;
	goto tr445;
st330:
	if ( ++p == pe )
		goto _test_eof330;
case 330:
	if ( (*p) == 61 )
		goto st331;
	goto tr445;
st331:
	if ( ++p == pe )
		goto _test_eof331;
case 331:
	if ( (*p) == 83 )
		goto tr476;
	goto tr475;
tr476:
#line 152 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Type");
    }
	goto st332;
st332:
	if ( ++p == pe )
		goto _test_eof332;
case 332:
#line 8338 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 116 )
		goto st333;
	goto tr475;
st333:
	if ( ++p == pe )
		goto _test_eof333;
case 333:
	if ( (*p) == 114 )
		goto st334;
	goto tr475;
st334:
	if ( ++p == pe )
		goto _test_eof334;
case 334:
	if ( (*p) == 105 )
		goto st335;
	goto tr475;
st335:
	if ( ++p == pe )
		goto _test_eof335;
case 335:
	if ( (*p) == 110 )
		goto st336;
	goto tr475;
st336:
	if ( ++p == pe )
		goto _test_eof336;
case 336:
	if ( (*p) == 103 )
		goto st337;
	goto tr475;
st337:
	if ( ++p == pe )
		goto _test_eof337;
case 337:
	if ( (*p) == 44 )
		goto st338;
	goto tr475;
st338:
	if ( ++p == pe )
		goto _test_eof338;
case 338:
	if ( (*p) == 86 )
		goto st339;
	goto tr445;
st339:
	if ( ++p == pe )
		goto _test_eof339;
case 339:
	if ( (*p) == 97 )
		goto st340;
	goto tr445;
st340:
	if ( ++p == pe )
		goto _test_eof340;
case 340:
	if ( (*p) == 108 )
		goto st341;
	goto tr445;
st341:
	if ( ++p == pe )
		goto _test_eof341;
case 341:
	if ( (*p) == 117 )
		goto st342;
	goto tr445;
st342:
	if ( ++p == pe )
		goto _test_eof342;
case 342:
	if ( (*p) == 101 )
		goto st343;
	goto tr445;
st343:
	if ( ++p == pe )
		goto _test_eof343;
case 343:
	if ( (*p) == 115 )
		goto st344;
	goto tr445;
st344:
	if ( ++p == pe )
		goto _test_eof344;
case 344:
	if ( (*p) == 61 )
		goto st345;
	goto tr445;
st345:
	if ( ++p == pe )
		goto _test_eof345;
case 345:
	if ( (*p) == 91 )
		goto tr490;
	goto tr445;
tr490:
#line 32 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Values");
    }
	goto st346;
st346:
	if ( ++p == pe )
		goto _test_eof346;
case 346:
#line 8443 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 61 )
		goto tr491;
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr491;
	} else if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr491;
	} else
		goto tr491;
	goto tr445;
tr491:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st347;
tr493:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st347;
st347:
	if ( ++p == pe )
		goto _test_eof347;
case 347:
#line 8475 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 44: goto tr494;
		case 61: goto tr493;
		case 93: goto tr495;
	}
	if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr493;
	} else if ( (*p) >= 33 )
		goto tr493;
	goto tr492;
tr494:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st348;
st348:
	if ( ++p == pe )
		goto _test_eof348;
case 348:
#line 8497 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 32: goto tr496;
		case 61: goto tr493;
	}
	if ( (*p) < 33 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr496;
	} else if ( (*p) > 43 ) {
		if ( (*p) > 59 ) {
			if ( 63 <= (*p) && (*p) <= 126 )
				goto tr493;
		} else if ( (*p) >= 45 )
			goto tr493;
	} else
		goto tr493;
	goto tr445;
tr496:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st349;
st349:
	if ( ++p == pe )
		goto _test_eof349;
case 349:
#line 8524 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 61 )
		goto tr493;
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr493;
	} else if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr493;
	} else
		goto tr493;
	goto tr445;
tr495:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st350;
st350:
	if ( ++p == pe )
		goto _test_eof350;
case 350:
#line 8550 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 44: goto tr494;
		case 62: goto st351;
		case 93: goto tr495;
	}
	if ( (*p) > 59 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr493;
	} else if ( (*p) >= 33 )
		goto tr493;
	goto tr492;
st351:
	if ( ++p == pe )
		goto _test_eof351;
case 351:
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
	}
	goto tr445;
tr35:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st352;
st352:
	if ( ++p == pe )
		goto _test_eof352;
case 352:
#line 8585 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 69: goto tr499;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr498;
tr499:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st353;
st353:
	if ( ++p == pe )
		goto _test_eof353;
case 353:
#line 8603 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 68: goto tr500;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr498;
tr500:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st354;
st354:
	if ( ++p == pe )
		goto _test_eof354;
case 354:
#line 8621 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 73: goto tr501;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr498;
tr501:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st355;
st355:
	if ( ++p == pe )
		goto _test_eof355;
case 355:
#line 8639 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 71: goto tr502;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr498;
tr502:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st356;
st356:
	if ( ++p == pe )
		goto _test_eof356;
case 356:
#line 8657 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 82: goto tr503;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr498;
tr503:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st357;
st357:
	if ( ++p == pe )
		goto _test_eof357;
case 357:
#line 8675 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 69: goto tr504;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr498;
tr504:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st358;
st358:
	if ( ++p == pe )
		goto _test_eof358;
case 358:
#line 8693 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 69: goto st359;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr498;
st359:
	if ( ++p == pe )
		goto _test_eof359;
case 359:
	if ( (*p) == 61 )
		goto tr506;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr498;
tr506:
#line 132 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "PEDIGREE");
    }
	goto st360;
st360:
	if ( ++p == pe )
		goto _test_eof360;
case 360:
#line 8720 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 60 )
		goto st361;
	goto tr498;
st361:
	if ( ++p == pe )
		goto _test_eof361;
case 361:
	if ( (*p) == 73 )
		goto st362;
	goto tr498;
st362:
	if ( ++p == pe )
		goto _test_eof362;
case 362:
	if ( (*p) == 68 )
		goto st363;
	goto tr498;
st363:
	if ( ++p == pe )
		goto _test_eof363;
case 363:
	if ( (*p) == 61 )
		goto st364;
	goto tr498;
st364:
	if ( ++p == pe )
		goto _test_eof364;
case 364:
	if ( (*p) == 95 )
		goto tr512;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr512;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr513;
		} else if ( (*p) >= 65 )
			goto tr513;
	} else
		goto tr513;
	goto tr511;
tr512:
#line 144 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st365;
st365:
	if ( ++p == pe )
		goto _test_eof365;
case 365:
#line 8777 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 95 )
		goto st365;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st365;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr515;
		} else if ( (*p) >= 65 )
			goto tr515;
	} else
		goto tr515;
	goto tr511;
tr515:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st366;
tr513:
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
	goto st366;
st366:
	if ( ++p == pe )
		goto _test_eof366;
case 366:
#line 8816 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 44: goto tr516;
		case 95: goto tr515;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr515;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr515;
		} else if ( (*p) >= 65 )
			goto tr515;
	} else
		goto tr515;
	goto tr511;
tr516:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st367;
st367:
	if ( ++p == pe )
		goto _test_eof367;
case 367:
#line 8843 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 70: goto st368;
		case 78: goto tr519;
		case 79: goto st398;
	}
	goto tr517;
st368:
	if ( ++p == pe )
		goto _test_eof368;
case 368:
	if ( (*p) == 97 )
		goto st369;
	goto tr498;
st369:
	if ( ++p == pe )
		goto _test_eof369;
case 369:
	if ( (*p) == 116 )
		goto st370;
	goto tr498;
st370:
	if ( ++p == pe )
		goto _test_eof370;
case 370:
	if ( (*p) == 104 )
		goto st371;
	goto tr498;
st371:
	if ( ++p == pe )
		goto _test_eof371;
case 371:
	if ( (*p) == 101 )
		goto st372;
	goto tr498;
st372:
	if ( ++p == pe )
		goto _test_eof372;
case 372:
	if ( (*p) == 114 )
		goto st373;
	goto tr498;
st373:
	if ( ++p == pe )
		goto _test_eof373;
case 373:
	if ( (*p) == 61 )
		goto st374;
	goto tr498;
st374:
	if ( ++p == pe )
		goto _test_eof374;
case 374:
	if ( (*p) == 95 )
		goto tr528;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr528;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr529;
		} else if ( (*p) >= 65 )
			goto tr529;
	} else
		goto tr529;
	goto tr527;
tr528:
#line 40 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Father");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st375;
st375:
	if ( ++p == pe )
		goto _test_eof375;
case 375:
#line 8924 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 95 )
		goto st375;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st375;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr531;
		} else if ( (*p) >= 65 )
			goto tr531;
	} else
		goto tr531;
	goto tr527;
tr531:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st376;
tr529:
#line 40 "src/vcf/vcf_v43.ragel"
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
	goto st376;
st376:
	if ( ++p == pe )
		goto _test_eof376;
case 376:
#line 8963 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 44: goto tr532;
		case 95: goto tr531;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr531;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr531;
		} else if ( (*p) >= 65 )
			goto tr531;
	} else
		goto tr531;
	goto tr527;
tr532:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st377;
st377:
	if ( ++p == pe )
		goto _test_eof377;
case 377:
#line 8990 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 77 )
		goto st378;
	goto tr498;
st378:
	if ( ++p == pe )
		goto _test_eof378;
case 378:
	if ( (*p) == 111 )
		goto st379;
	goto tr498;
st379:
	if ( ++p == pe )
		goto _test_eof379;
case 379:
	if ( (*p) == 116 )
		goto st380;
	goto tr498;
st380:
	if ( ++p == pe )
		goto _test_eof380;
case 380:
	if ( (*p) == 104 )
		goto st381;
	goto tr498;
st381:
	if ( ++p == pe )
		goto _test_eof381;
case 381:
	if ( (*p) == 101 )
		goto st382;
	goto tr498;
st382:
	if ( ++p == pe )
		goto _test_eof382;
case 382:
	if ( (*p) == 114 )
		goto st383;
	goto tr498;
st383:
	if ( ++p == pe )
		goto _test_eof383;
case 383:
	if ( (*p) == 61 )
		goto st384;
	goto tr498;
st384:
	if ( ++p == pe )
		goto _test_eof384;
case 384:
	if ( (*p) == 95 )
		goto tr540;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr540;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr541;
		} else if ( (*p) >= 65 )
			goto tr541;
	} else
		goto tr541;
	goto tr527;
tr540:
#line 44 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Mother");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st385;
st385:
	if ( ++p == pe )
		goto _test_eof385;
case 385:
#line 9068 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 95 )
		goto st385;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st385;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr543;
		} else if ( (*p) >= 65 )
			goto tr543;
	} else
		goto tr543;
	goto tr527;
tr543:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st386;
tr541:
#line 44 "src/vcf/vcf_v43.ragel"
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
	goto st386;
st386:
	if ( ++p == pe )
		goto _test_eof386;
case 386:
#line 9107 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 62: goto tr544;
		case 95: goto tr543;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr543;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr543;
		} else if ( (*p) >= 65 )
			goto tr543;
	} else
		goto tr543;
	goto tr527;
tr544:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st387;
st387:
	if ( ++p == pe )
		goto _test_eof387;
case 387:
#line 9134 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
	}
	goto tr498;
tr519:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
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
#line 9154 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 97 )
		goto tr545;
	goto tr517;
tr545:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st389;
st389:
	if ( ++p == pe )
		goto _test_eof389;
case 389:
#line 9168 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 109 )
		goto tr546;
	goto tr517;
tr546:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st390;
st390:
	if ( ++p == pe )
		goto _test_eof390;
case 390:
#line 9182 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 101 )
		goto tr547;
	goto tr517;
tr547:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st391;
st391:
	if ( ++p == pe )
		goto _test_eof391;
case 391:
#line 9196 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 95 )
		goto tr548;
	goto tr517;
tr548:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st392;
st392:
	if ( ++p == pe )
		goto _test_eof392;
case 392:
#line 9210 "inc/vcf/validator_detail_v43.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr549;
	goto tr517;
tr549:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st393;
st393:
	if ( ++p == pe )
		goto _test_eof393;
case 393:
#line 9224 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 61 )
		goto tr550;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr549;
	goto tr517;
tr550:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st394;
st394:
	if ( ++p == pe )
		goto _test_eof394;
case 394:
#line 9240 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 95 )
		goto tr551;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr551;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr552;
		} else if ( (*p) >= 65 )
			goto tr552;
	} else
		goto tr552;
	goto tr517;
tr551:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st395;
st395:
	if ( ++p == pe )
		goto _test_eof395;
case 395:
#line 9265 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 95 )
		goto st395;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st395;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr554;
		} else if ( (*p) >= 65 )
			goto tr554;
	} else
		goto tr554;
	goto tr517;
tr552:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st396;
tr554:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st396;
st396:
	if ( ++p == pe )
		goto _test_eof396;
case 396:
#line 9300 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 44: goto tr555;
		case 62: goto tr544;
		case 95: goto tr554;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr554;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr554;
		} else if ( (*p) >= 65 )
			goto tr554;
	} else
		goto tr554;
	goto tr517;
tr555:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st397;
st397:
	if ( ++p == pe )
		goto _test_eof397;
case 397:
#line 9328 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 78 )
		goto tr519;
	goto tr517;
st398:
	if ( ++p == pe )
		goto _test_eof398;
case 398:
	if ( (*p) == 114 )
		goto st399;
	goto tr498;
st399:
	if ( ++p == pe )
		goto _test_eof399;
case 399:
	if ( (*p) == 105 )
		goto st400;
	goto tr498;
st400:
	if ( ++p == pe )
		goto _test_eof400;
case 400:
	if ( (*p) == 103 )
		goto st401;
	goto tr498;
st401:
	if ( ++p == pe )
		goto _test_eof401;
case 401:
	if ( (*p) == 105 )
		goto st402;
	goto tr498;
st402:
	if ( ++p == pe )
		goto _test_eof402;
case 402:
	if ( (*p) == 110 )
		goto st403;
	goto tr498;
st403:
	if ( ++p == pe )
		goto _test_eof403;
case 403:
	if ( (*p) == 97 )
		goto st404;
	goto tr498;
st404:
	if ( ++p == pe )
		goto _test_eof404;
case 404:
	if ( (*p) == 108 )
		goto st405;
	goto tr498;
st405:
	if ( ++p == pe )
		goto _test_eof405;
case 405:
	if ( (*p) == 61 )
		goto st406;
	goto tr498;
st406:
	if ( ++p == pe )
		goto _test_eof406;
case 406:
	if ( (*p) == 95 )
		goto tr565;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr565;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr566;
		} else if ( (*p) >= 65 )
			goto tr566;
	} else
		goto tr566;
	goto tr564;
tr565:
#line 36 "src/vcf/vcf_v43.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Original");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st407;
st407:
	if ( ++p == pe )
		goto _test_eof407;
case 407:
#line 9420 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 95 )
		goto st407;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st407;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr568;
		} else if ( (*p) >= 65 )
			goto tr568;
	} else
		goto tr568;
	goto tr564;
tr568:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st408;
tr566:
#line 36 "src/vcf/vcf_v43.ragel"
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
	goto st408;
st408:
	if ( ++p == pe )
		goto _test_eof408;
case 408:
#line 9459 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 62: goto tr544;
		case 95: goto tr568;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr568;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr568;
		} else if ( (*p) >= 65 )
			goto tr568;
	} else
		goto tr568;
	goto tr564;
tr36:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st409;
st409:
	if ( ++p == pe )
		goto _test_eof409;
case 409:
#line 9490 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 65: goto tr570;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr569;
tr570:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st410;
st410:
	if ( ++p == pe )
		goto _test_eof410;
case 410:
#line 9508 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 77: goto tr571;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr569;
tr571:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st411;
st411:
	if ( ++p == pe )
		goto _test_eof411;
case 411:
#line 9526 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 80: goto tr572;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr569;
tr572:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st412;
st412:
	if ( ++p == pe )
		goto _test_eof412;
case 412:
#line 9544 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 76: goto tr573;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr569;
tr573:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st413;
st413:
	if ( ++p == pe )
		goto _test_eof413;
case 413:
#line 9562 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 69: goto st414;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr569;
st414:
	if ( ++p == pe )
		goto _test_eof414;
case 414:
	if ( (*p) == 61 )
		goto tr575;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr569;
tr575:
#line 140 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "SAMPLE");
    }
	goto st415;
st415:
	if ( ++p == pe )
		goto _test_eof415;
case 415:
#line 9589 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 60 )
		goto st416;
	goto tr569;
st416:
	if ( ++p == pe )
		goto _test_eof416;
case 416:
	if ( (*p) == 73 )
		goto st417;
	goto tr569;
st417:
	if ( ++p == pe )
		goto _test_eof417;
case 417:
	if ( (*p) == 68 )
		goto st418;
	goto tr569;
st418:
	if ( ++p == pe )
		goto _test_eof418;
case 418:
	if ( (*p) == 61 )
		goto st419;
	goto tr569;
st419:
	if ( ++p == pe )
		goto _test_eof419;
case 419:
	if ( (*p) == 95 )
		goto tr581;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr581;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr582;
		} else if ( (*p) >= 65 )
			goto tr582;
	} else
		goto tr582;
	goto tr580;
tr581:
#line 144 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st420;
st420:
	if ( ++p == pe )
		goto _test_eof420;
case 420:
#line 9646 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 95 )
		goto st420;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st420;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr584;
		} else if ( (*p) >= 65 )
			goto tr584;
	} else
		goto tr584;
	goto tr580;
tr584:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st421;
tr582:
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
	goto st421;
st421:
	if ( ++p == pe )
		goto _test_eof421;
case 421:
#line 9685 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 44: goto tr585;
		case 62: goto tr586;
		case 95: goto tr584;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr584;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr584;
		} else if ( (*p) >= 65 )
			goto tr584;
	} else
		goto tr584;
	goto tr580;
tr585:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st422;
st422:
	if ( ++p == pe )
		goto _test_eof422;
case 422:
#line 9713 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 95 )
		goto tr587;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr587;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr588;
		} else if ( (*p) >= 65 )
			goto tr588;
	} else
		goto tr588;
	goto tr569;
tr587:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st423;
st423:
	if ( ++p == pe )
		goto _test_eof423;
case 423:
#line 9738 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 95 )
		goto st423;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st423;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr590;
		} else if ( (*p) >= 65 )
			goto tr590;
	} else
		goto tr590;
	goto tr569;
tr588:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st424;
tr590:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st424;
st424:
	if ( ++p == pe )
		goto _test_eof424;
case 424:
#line 9773 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr591;
		case 95: goto tr590;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr590;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr590;
		} else if ( (*p) >= 65 )
			goto tr590;
	} else
		goto tr590;
	goto tr569;
tr591:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st425;
st425:
	if ( ++p == pe )
		goto _test_eof425;
case 425:
#line 9800 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 34 )
		goto st428;
	if ( (*p) < 45 ) {
		if ( 32 <= (*p) && (*p) <= 43 )
			goto tr592;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr592;
	} else
		goto tr592;
	goto tr569;
tr592:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st426;
tr594:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st426;
st426:
	if ( ++p == pe )
		goto _test_eof426;
case 426:
#line 9832 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 44: goto tr585;
		case 62: goto tr586;
	}
	if ( (*p) > 33 ) {
		if ( 35 <= (*p) && (*p) <= 126 )
			goto tr594;
	} else if ( (*p) >= 32 )
		goto tr594;
	goto tr569;
tr586:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st427;
st427:
	if ( ++p == pe )
		goto _test_eof427;
case 427:
#line 9853 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
	}
	goto tr569;
st428:
	if ( ++p == pe )
		goto _test_eof428;
case 428:
	switch( (*p) ) {
		case 34: goto tr596;
		case 92: goto tr597;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr595;
	goto tr569;
tr595:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st429;
tr598:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st429;
st429:
	if ( ++p == pe )
		goto _test_eof429;
case 429:
#line 9890 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr599;
		case 92: goto tr600;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr598;
	goto tr569;
tr596:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st430;
tr599:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st430;
st430:
	if ( ++p == pe )
		goto _test_eof430;
case 430:
#line 9918 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 44: goto st422;
		case 62: goto st427;
	}
	goto tr569;
tr597:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st431;
tr600:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st431;
st431:
	if ( ++p == pe )
		goto _test_eof431;
case 431:
#line 9944 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr603;
		case 92: goto tr600;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr598;
	goto tr569;
tr603:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st432;
st432:
	if ( ++p == pe )
		goto _test_eof432;
case 432:
#line 9966 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr599;
		case 44: goto tr604;
		case 62: goto tr605;
		case 92: goto tr600;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr598;
	goto tr569;
tr618:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st433;
tr604:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st433;
tr615:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st433;
st433:
	if ( ++p == pe )
		goto _test_eof433;
case 433:
#line 10006 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr599;
		case 47: goto tr598;
		case 92: goto tr600;
		case 95: goto tr606;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr598;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr607;
		} else
			goto tr606;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr607;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr598;
			} else if ( (*p) >= 97 )
				goto tr607;
		} else
			goto tr598;
	} else
		goto tr598;
	goto tr569;
tr606:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st434;
tr608:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st434;
st434:
	if ( ++p == pe )
		goto _test_eof434;
case 434:
#line 10057 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr599;
		case 47: goto tr598;
		case 92: goto tr600;
		case 95: goto tr608;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr598;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr609;
		} else
			goto tr608;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr609;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr598;
			} else if ( (*p) >= 97 )
				goto tr609;
		} else
			goto tr598;
	} else
		goto tr598;
	goto tr569;
tr607:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st435;
tr609:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st435;
st435:
	if ( ++p == pe )
		goto _test_eof435;
case 435:
#line 10108 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr599;
		case 47: goto tr598;
		case 61: goto tr610;
		case 92: goto tr600;
		case 95: goto tr609;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr598;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr598;
		} else
			goto tr609;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr598;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr598;
		} else
			goto tr609;
	} else
		goto tr609;
	goto tr569;
tr610:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st436;
st436:
	if ( ++p == pe )
		goto _test_eof436;
case 436:
#line 10151 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr612;
		case 44: goto tr598;
		case 62: goto tr598;
		case 92: goto tr613;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr611;
	goto tr569;
tr614:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st437;
tr611:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st437;
st437:
	if ( ++p == pe )
		goto _test_eof437;
case 437:
#line 10181 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr599;
		case 44: goto tr615;
		case 62: goto tr616;
		case 92: goto tr617;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr614;
	goto tr569;
tr619:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st438;
tr605:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st438;
tr616:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st438;
st438:
	if ( ++p == pe )
		goto _test_eof438;
case 438:
#line 10221 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
		case 34: goto tr599;
		case 92: goto tr600;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr598;
	goto tr569;
tr617:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st439;
tr613:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st439;
st439:
	if ( ++p == pe )
		goto _test_eof439;
case 439:
#line 10251 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr603;
		case 44: goto tr615;
		case 62: goto tr616;
		case 92: goto tr617;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr614;
	goto tr569;
tr612:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st440;
st440:
	if ( ++p == pe )
		goto _test_eof440;
case 440:
#line 10271 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr596;
		case 44: goto tr618;
		case 62: goto tr619;
		case 92: goto tr597;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr595;
	goto tr569;
tr37:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st441;
st441:
	if ( ++p == pe )
		goto _test_eof441;
case 441:
#line 10295 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 115: goto tr621;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr620;
tr621:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st442;
st442:
	if ( ++p == pe )
		goto _test_eof442;
case 442:
#line 10313 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 115: goto tr622;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr620;
tr622:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st443;
st443:
	if ( ++p == pe )
		goto _test_eof443;
case 443:
#line 10331 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 101: goto tr623;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr620;
tr623:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st444;
st444:
	if ( ++p == pe )
		goto _test_eof444;
case 444:
#line 10349 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 109: goto tr624;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr620;
tr624:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st445;
st445:
	if ( ++p == pe )
		goto _test_eof445;
case 445:
#line 10367 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 98: goto tr625;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr620;
tr625:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st446;
st446:
	if ( ++p == pe )
		goto _test_eof446;
case 446:
#line 10385 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 108: goto tr626;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr620;
tr626:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st447;
st447:
	if ( ++p == pe )
		goto _test_eof447;
case 447:
#line 10403 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 121: goto st448;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr620;
st448:
	if ( ++p == pe )
		goto _test_eof448;
case 448:
	if ( (*p) == 61 )
		goto tr628;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr620;
tr628:
#line 112 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "assembly");
    }
	goto st449;
st449:
	if ( ++p == pe )
		goto _test_eof449;
case 449:
#line 10430 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr630;
	} else if ( (*p) >= 65 )
		goto tr630;
	goto tr629;
tr630:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st450;
st450:
	if ( ++p == pe )
		goto _test_eof450;
case 450:
#line 10447 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 10: goto tr629;
		case 13: goto tr632;
		case 35: goto tr629;
		case 47: goto tr629;
		case 58: goto tr629;
		case 63: goto tr629;
	}
	goto st451;
tr632:
#line 43 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st451;
st451:
	if ( ++p == pe )
		goto _test_eof451;
case 451:
#line 10473 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 10: goto tr629;
		case 13: goto tr632;
		case 35: goto tr629;
		case 47: goto tr629;
		case 58: goto st452;
		case 63: goto tr629;
	}
	goto st451;
st452:
	if ( ++p == pe )
		goto _test_eof452;
case 452:
	if ( (*p) == 47 )
		goto st453;
	goto tr629;
st453:
	if ( ++p == pe )
		goto _test_eof453;
case 453:
	if ( (*p) == 47 )
		goto st454;
	goto tr629;
st454:
	if ( ++p == pe )
		goto _test_eof454;
case 454:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st455;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr637;
	} else
		goto tr637;
	goto tr629;
st455:
	if ( ++p == pe )
		goto _test_eof455;
case 455:
	if ( (*p) == 46 )
		goto st456;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st466;
	goto tr629;
st456:
	if ( ++p == pe )
		goto _test_eof456;
case 456:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st457;
	goto tr629;
st457:
	if ( ++p == pe )
		goto _test_eof457;
case 457:
	if ( (*p) == 46 )
		goto st458;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st464;
	goto tr629;
st458:
	if ( ++p == pe )
		goto _test_eof458;
case 458:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st459;
	goto tr629;
st459:
	if ( ++p == pe )
		goto _test_eof459;
case 459:
	if ( (*p) == 46 )
		goto st460;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st462;
	goto tr629;
st460:
	if ( ++p == pe )
		goto _test_eof460;
case 460:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr637;
	goto tr629;
tr637:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st461;
tr646:
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
#line 168 "src/vcf/vcf.ragel"
	{
        try {
          ParsePolicy::handle_meta_line(*this);
        } catch (Error *error) {
          ErrorPolicy::handle_error(*this, error);
        }
    }
	goto st461;
st461:
	if ( ++p == pe )
		goto _test_eof461;
case 461:
#line 10596 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 10: goto tr46;
		case 13: goto tr646;
	}
	goto tr637;
st462:
	if ( ++p == pe )
		goto _test_eof462;
case 462:
	if ( (*p) == 46 )
		goto st460;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st463;
	goto tr629;
st463:
	if ( ++p == pe )
		goto _test_eof463;
case 463:
	if ( (*p) == 46 )
		goto st460;
	goto tr629;
st464:
	if ( ++p == pe )
		goto _test_eof464;
case 464:
	if ( (*p) == 46 )
		goto st458;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st465;
	goto tr629;
st465:
	if ( ++p == pe )
		goto _test_eof465;
case 465:
	if ( (*p) == 46 )
		goto st458;
	goto tr629;
st466:
	if ( ++p == pe )
		goto _test_eof466;
case 466:
	if ( (*p) == 46 )
		goto st456;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st467;
	goto tr629;
st467:
	if ( ++p == pe )
		goto _test_eof467;
case 467:
	if ( (*p) == 46 )
		goto st456;
	goto tr629;
tr38:
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
#line 10664 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 111: goto tr651;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr650;
tr651:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st469;
st469:
	if ( ++p == pe )
		goto _test_eof469;
case 469:
#line 10682 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 110: goto tr652;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr650;
tr652:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st470;
st470:
	if ( ++p == pe )
		goto _test_eof470;
case 470:
#line 10700 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 116: goto tr653;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr650;
tr653:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st471;
st471:
	if ( ++p == pe )
		goto _test_eof471;
case 471:
#line 10718 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 105: goto tr654;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr650;
tr654:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st472;
st472:
	if ( ++p == pe )
		goto _test_eof472;
case 472:
#line 10736 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 103: goto st473;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr650;
st473:
	if ( ++p == pe )
		goto _test_eof473;
case 473:
	if ( (*p) == 61 )
		goto tr656;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr650;
tr656:
#line 116 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "contig");
    }
	goto st474;
st474:
	if ( ++p == pe )
		goto _test_eof474;
case 474:
#line 10763 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 60 )
		goto st475;
	goto tr650;
st475:
	if ( ++p == pe )
		goto _test_eof475;
case 475:
	if ( (*p) == 73 )
		goto st476;
	goto tr650;
st476:
	if ( ++p == pe )
		goto _test_eof476;
case 476:
	if ( (*p) == 68 )
		goto st477;
	goto tr650;
st477:
	if ( ++p == pe )
		goto _test_eof477;
case 477:
	if ( (*p) == 61 )
		goto st478;
	goto tr650;
st478:
	if ( ++p == pe )
		goto _test_eof478;
case 478:
	switch( (*p) ) {
		case 43: goto tr662;
		case 59: goto tr662;
		case 92: goto tr662;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr662;
		} else if ( (*p) >= 33 )
			goto tr662;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr662;
		} else if ( (*p) >= 63 )
			goto tr662;
	} else
		goto tr662;
	goto tr661;
tr663:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st479;
tr662:
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
	goto st479;
st479:
	if ( ++p == pe )
		goto _test_eof479;
case 479:
#line 10836 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 44: goto tr664;
		case 59: goto tr663;
		case 62: goto tr665;
		case 92: goto tr663;
	}
	if ( (*p) < 43 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr663;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr663;
		} else if ( (*p) >= 63 )
			goto tr663;
	} else
		goto tr663;
	goto tr661;
tr664:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st480;
st480:
	if ( ++p == pe )
		goto _test_eof480;
case 480:
#line 10865 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 95 )
		goto tr666;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr666;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr667;
		} else if ( (*p) >= 65 )
			goto tr667;
	} else
		goto tr667;
	goto tr650;
tr666:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st481;
st481:
	if ( ++p == pe )
		goto _test_eof481;
case 481:
#line 10890 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 95 )
		goto st481;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st481;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr669;
		} else if ( (*p) >= 65 )
			goto tr669;
	} else
		goto tr669;
	goto tr650;
tr667:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st482;
tr669:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st482;
st482:
	if ( ++p == pe )
		goto _test_eof482;
case 482:
#line 10925 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr670;
		case 95: goto tr669;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr669;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr669;
		} else if ( (*p) >= 65 )
			goto tr669;
	} else
		goto tr669;
	goto tr650;
tr670:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st483;
st483:
	if ( ++p == pe )
		goto _test_eof483;
case 483:
#line 10952 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 34 )
		goto st486;
	if ( (*p) < 45 ) {
		if ( 32 <= (*p) && (*p) <= 43 )
			goto tr671;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr671;
	} else
		goto tr671;
	goto tr650;
tr671:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st484;
tr673:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st484;
st484:
	if ( ++p == pe )
		goto _test_eof484;
case 484:
#line 10984 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 44: goto tr664;
		case 62: goto tr665;
	}
	if ( (*p) > 33 ) {
		if ( 35 <= (*p) && (*p) <= 126 )
			goto tr673;
	} else if ( (*p) >= 32 )
		goto tr673;
	goto tr650;
tr665:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st485;
st485:
	if ( ++p == pe )
		goto _test_eof485;
case 485:
#line 11005 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
	}
	goto tr650;
st486:
	if ( ++p == pe )
		goto _test_eof486;
case 486:
	switch( (*p) ) {
		case 34: goto tr675;
		case 92: goto tr676;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr674;
	goto tr650;
tr674:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st487;
tr677:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st487;
st487:
	if ( ++p == pe )
		goto _test_eof487;
case 487:
#line 11042 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr678;
		case 92: goto tr679;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr677;
	goto tr650;
tr675:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st488;
tr678:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st488;
st488:
	if ( ++p == pe )
		goto _test_eof488;
case 488:
#line 11070 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 44: goto st480;
		case 62: goto st485;
	}
	goto tr650;
tr676:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st489;
tr679:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st489;
st489:
	if ( ++p == pe )
		goto _test_eof489;
case 489:
#line 11096 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr682;
		case 92: goto tr679;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr677;
	goto tr650;
tr682:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st490;
st490:
	if ( ++p == pe )
		goto _test_eof490;
case 490:
#line 11118 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr678;
		case 44: goto tr683;
		case 62: goto tr684;
		case 92: goto tr679;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr677;
	goto tr650;
tr697:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st491;
tr683:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st491;
tr694:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st491;
st491:
	if ( ++p == pe )
		goto _test_eof491;
case 491:
#line 11158 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr678;
		case 47: goto tr677;
		case 92: goto tr679;
		case 95: goto tr685;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr677;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr686;
		} else
			goto tr685;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr686;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr677;
			} else if ( (*p) >= 97 )
				goto tr686;
		} else
			goto tr677;
	} else
		goto tr677;
	goto tr650;
tr685:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st492;
tr687:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st492;
st492:
	if ( ++p == pe )
		goto _test_eof492;
case 492:
#line 11209 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr678;
		case 47: goto tr677;
		case 92: goto tr679;
		case 95: goto tr687;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr677;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr688;
		} else
			goto tr687;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr688;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr677;
			} else if ( (*p) >= 97 )
				goto tr688;
		} else
			goto tr677;
	} else
		goto tr677;
	goto tr650;
tr686:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st493;
tr688:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st493;
st493:
	if ( ++p == pe )
		goto _test_eof493;
case 493:
#line 11260 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr678;
		case 47: goto tr677;
		case 61: goto tr689;
		case 92: goto tr679;
		case 95: goto tr688;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr677;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr677;
		} else
			goto tr688;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr677;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr677;
		} else
			goto tr688;
	} else
		goto tr688;
	goto tr650;
tr689:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st494;
st494:
	if ( ++p == pe )
		goto _test_eof494;
case 494:
#line 11303 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr691;
		case 44: goto tr677;
		case 62: goto tr677;
		case 92: goto tr692;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr690;
	goto tr650;
tr693:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st495;
tr690:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st495;
st495:
	if ( ++p == pe )
		goto _test_eof495;
case 495:
#line 11333 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr678;
		case 44: goto tr694;
		case 62: goto tr695;
		case 92: goto tr696;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr693;
	goto tr650;
tr698:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st496;
tr684:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st496;
tr695:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st496;
st496:
	if ( ++p == pe )
		goto _test_eof496;
case 496:
#line 11373 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr57;
		case 34: goto tr678;
		case 92: goto tr679;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr677;
	goto tr650;
tr696:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st497;
tr692:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st497;
st497:
	if ( ++p == pe )
		goto _test_eof497;
case 497:
#line 11403 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr682;
		case 44: goto tr694;
		case 62: goto tr695;
		case 92: goto tr696;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr693;
	goto tr650;
tr691:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st498;
st498:
	if ( ++p == pe )
		goto _test_eof498;
case 498:
#line 11423 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 34: goto tr675;
		case 44: goto tr697;
		case 62: goto tr698;
		case 92: goto tr676;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr674;
	goto tr650;
tr39:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st499;
st499:
	if ( ++p == pe )
		goto _test_eof499;
case 499:
#line 11447 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 101: goto tr700;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr699;
tr700:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st500;
st500:
	if ( ++p == pe )
		goto _test_eof500;
case 500:
#line 11465 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 100: goto tr701;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr699;
tr701:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st501;
st501:
	if ( ++p == pe )
		goto _test_eof501;
case 501:
#line 11483 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 105: goto tr702;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr699;
tr702:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st502;
st502:
	if ( ++p == pe )
		goto _test_eof502;
case 502:
#line 11501 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 103: goto tr703;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr699;
tr703:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st503;
st503:
	if ( ++p == pe )
		goto _test_eof503;
case 503:
#line 11519 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 114: goto tr704;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr699;
tr704:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st504;
st504:
	if ( ++p == pe )
		goto _test_eof504;
case 504:
#line 11537 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 101: goto tr705;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr699;
tr705:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st505;
st505:
	if ( ++p == pe )
		goto _test_eof505;
case 505:
#line 11555 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 101: goto tr706;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr699;
tr706:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st506;
st506:
	if ( ++p == pe )
		goto _test_eof506;
case 506:
#line 11573 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 68: goto tr707;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr699;
tr707:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st507;
st507:
	if ( ++p == pe )
		goto _test_eof507;
case 507:
#line 11591 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 61: goto tr42;
		case 66: goto st508;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr699;
st508:
	if ( ++p == pe )
		goto _test_eof508;
case 508:
	if ( (*p) == 61 )
		goto tr709;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr699;
tr709:
#line 136 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "pedigreeDB");
    }
	goto st509;
st509:
	if ( ++p == pe )
		goto _test_eof509;
case 509:
#line 11618 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 60 )
		goto st510;
	goto tr699;
st510:
	if ( ++p == pe )
		goto _test_eof510;
case 510:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr712;
	} else if ( (*p) >= 65 )
		goto tr712;
	goto tr711;
tr712:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st511;
st511:
	if ( ++p == pe )
		goto _test_eof511;
case 511:
#line 11642 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 10: goto tr711;
		case 13: goto tr714;
		case 35: goto tr711;
		case 47: goto tr711;
		case 58: goto tr711;
		case 63: goto tr711;
	}
	goto st512;
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
	goto st512;
st512:
	if ( ++p == pe )
		goto _test_eof512;
case 512:
#line 11668 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 10: goto tr711;
		case 13: goto tr714;
		case 35: goto tr711;
		case 47: goto tr711;
		case 58: goto st513;
		case 63: goto tr711;
	}
	goto st512;
st513:
	if ( ++p == pe )
		goto _test_eof513;
case 513:
	if ( (*p) == 47 )
		goto st514;
	goto tr711;
st514:
	if ( ++p == pe )
		goto _test_eof514;
case 514:
	if ( (*p) == 47 )
		goto st515;
	goto tr711;
st515:
	if ( ++p == pe )
		goto _test_eof515;
case 515:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st516;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr719;
	} else
		goto tr719;
	goto tr711;
st516:
	if ( ++p == pe )
		goto _test_eof516;
case 516:
	if ( (*p) == 46 )
		goto st517;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st529;
	goto tr711;
st517:
	if ( ++p == pe )
		goto _test_eof517;
case 517:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st518;
	goto tr711;
st518:
	if ( ++p == pe )
		goto _test_eof518;
case 518:
	if ( (*p) == 46 )
		goto st519;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st527;
	goto tr711;
st519:
	if ( ++p == pe )
		goto _test_eof519;
case 519:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st520;
	goto tr711;
st520:
	if ( ++p == pe )
		goto _test_eof520;
case 520:
	if ( (*p) == 46 )
		goto st521;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st525;
	goto tr711;
st521:
	if ( ++p == pe )
		goto _test_eof521;
case 521:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr719;
	goto tr711;
tr719:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st522;
tr728:
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
	goto st522;
st522:
	if ( ++p == pe )
		goto _test_eof522;
case 522:
#line 11779 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 10: goto tr711;
		case 13: goto tr728;
		case 62: goto tr729;
	}
	goto tr719;
tr729:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st523;
st523:
	if ( ++p == pe )
		goto _test_eof523;
case 523:
#line 11800 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 10: goto tr56;
		case 13: goto tr730;
		case 62: goto tr729;
	}
	goto tr719;
tr730:
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
#line 168 "src/vcf/vcf.ragel"
	{
        try {
          ParsePolicy::handle_meta_line(*this);
        } catch (Error *error) {
          ErrorPolicy::handle_error(*this, error);
        }
    }
	goto st524;
st524:
	if ( ++p == pe )
		goto _test_eof524;
case 524:
#line 11835 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 10: goto st28;
		case 13: goto tr728;
		case 62: goto tr729;
	}
	goto tr719;
st525:
	if ( ++p == pe )
		goto _test_eof525;
case 525:
	if ( (*p) == 46 )
		goto st521;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st526;
	goto tr711;
st526:
	if ( ++p == pe )
		goto _test_eof526;
case 526:
	if ( (*p) == 46 )
		goto st521;
	goto tr711;
st527:
	if ( ++p == pe )
		goto _test_eof527;
case 527:
	if ( (*p) == 46 )
		goto st519;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st528;
	goto tr711;
st528:
	if ( ++p == pe )
		goto _test_eof528;
case 528:
	if ( (*p) == 46 )
		goto st519;
	goto tr711;
st529:
	if ( ++p == pe )
		goto _test_eof529;
case 529:
	if ( (*p) == 46 )
		goto st517;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st530;
	goto tr711;
st530:
	if ( ++p == pe )
		goto _test_eof530;
case 530:
	if ( (*p) == 46 )
		goto st517;
	goto tr711;
st531:
	if ( ++p == pe )
		goto _test_eof531;
case 531:
	if ( (*p) == 72 )
		goto st532;
	goto tr734;
st532:
	if ( ++p == pe )
		goto _test_eof532;
case 532:
	if ( (*p) == 82 )
		goto st533;
	goto tr734;
st533:
	if ( ++p == pe )
		goto _test_eof533;
case 533:
	if ( (*p) == 79 )
		goto st534;
	goto tr734;
st534:
	if ( ++p == pe )
		goto _test_eof534;
case 534:
	if ( (*p) == 77 )
		goto st535;
	goto tr734;
st535:
	if ( ++p == pe )
		goto _test_eof535;
case 535:
	if ( (*p) == 9 )
		goto tr739;
	goto tr734;
tr739:
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st536;
st536:
	if ( ++p == pe )
		goto _test_eof536;
case 536:
#line 11935 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 80 )
		goto st537;
	goto tr734;
st537:
	if ( ++p == pe )
		goto _test_eof537;
case 537:
	if ( (*p) == 79 )
		goto st538;
	goto tr734;
st538:
	if ( ++p == pe )
		goto _test_eof538;
case 538:
	if ( (*p) == 83 )
		goto st539;
	goto tr734;
st539:
	if ( ++p == pe )
		goto _test_eof539;
case 539:
	if ( (*p) == 9 )
		goto tr743;
	goto tr734;
tr743:
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st540;
st540:
	if ( ++p == pe )
		goto _test_eof540;
case 540:
#line 11970 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 73 )
		goto st541;
	goto tr734;
st541:
	if ( ++p == pe )
		goto _test_eof541;
case 541:
	if ( (*p) == 68 )
		goto st542;
	goto tr734;
st542:
	if ( ++p == pe )
		goto _test_eof542;
case 542:
	if ( (*p) == 9 )
		goto tr746;
	goto tr734;
tr746:
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st543;
st543:
	if ( ++p == pe )
		goto _test_eof543;
case 543:
#line 11998 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 82 )
		goto st544;
	goto tr734;
st544:
	if ( ++p == pe )
		goto _test_eof544;
case 544:
	if ( (*p) == 69 )
		goto st545;
	goto tr734;
st545:
	if ( ++p == pe )
		goto _test_eof545;
case 545:
	if ( (*p) == 70 )
		goto st546;
	goto tr734;
st546:
	if ( ++p == pe )
		goto _test_eof546;
case 546:
	if ( (*p) == 9 )
		goto tr750;
	goto tr734;
tr750:
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st547;
st547:
	if ( ++p == pe )
		goto _test_eof547;
case 547:
#line 12033 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 65 )
		goto st548;
	goto tr734;
st548:
	if ( ++p == pe )
		goto _test_eof548;
case 548:
	if ( (*p) == 76 )
		goto st549;
	goto tr734;
st549:
	if ( ++p == pe )
		goto _test_eof549;
case 549:
	if ( (*p) == 84 )
		goto st550;
	goto tr734;
st550:
	if ( ++p == pe )
		goto _test_eof550;
case 550:
	if ( (*p) == 9 )
		goto tr754;
	goto tr734;
tr754:
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st551;
st551:
	if ( ++p == pe )
		goto _test_eof551;
case 551:
#line 12068 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 81 )
		goto st552;
	goto tr734;
st552:
	if ( ++p == pe )
		goto _test_eof552;
case 552:
	if ( (*p) == 85 )
		goto st553;
	goto tr734;
st553:
	if ( ++p == pe )
		goto _test_eof553;
case 553:
	if ( (*p) == 65 )
		goto st554;
	goto tr734;
st554:
	if ( ++p == pe )
		goto _test_eof554;
case 554:
	if ( (*p) == 76 )
		goto st555;
	goto tr734;
st555:
	if ( ++p == pe )
		goto _test_eof555;
case 555:
	if ( (*p) == 9 )
		goto tr759;
	goto tr734;
tr759:
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st556;
st556:
	if ( ++p == pe )
		goto _test_eof556;
case 556:
#line 12110 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 70 )
		goto st557;
	goto tr734;
st557:
	if ( ++p == pe )
		goto _test_eof557;
case 557:
	if ( (*p) == 73 )
		goto st558;
	goto tr734;
st558:
	if ( ++p == pe )
		goto _test_eof558;
case 558:
	if ( (*p) == 76 )
		goto st559;
	goto tr734;
st559:
	if ( ++p == pe )
		goto _test_eof559;
case 559:
	if ( (*p) == 84 )
		goto st560;
	goto tr734;
st560:
	if ( ++p == pe )
		goto _test_eof560;
case 560:
	if ( (*p) == 69 )
		goto st561;
	goto tr734;
st561:
	if ( ++p == pe )
		goto _test_eof561;
case 561:
	if ( (*p) == 82 )
		goto st562;
	goto tr734;
st562:
	if ( ++p == pe )
		goto _test_eof562;
case 562:
	if ( (*p) == 9 )
		goto tr766;
	goto tr734;
tr766:
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st563;
st563:
	if ( ++p == pe )
		goto _test_eof563;
case 563:
#line 12166 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 73 )
		goto st564;
	goto tr734;
st564:
	if ( ++p == pe )
		goto _test_eof564;
case 564:
	if ( (*p) == 78 )
		goto st565;
	goto tr734;
st565:
	if ( ++p == pe )
		goto _test_eof565;
case 565:
	if ( (*p) == 70 )
		goto st566;
	goto tr734;
st566:
	if ( ++p == pe )
		goto _test_eof566;
case 566:
	if ( (*p) == 79 )
		goto st567;
	goto tr734;
st567:
	if ( ++p == pe )
		goto _test_eof567;
case 567:
	switch( (*p) ) {
		case 9: goto tr771;
		case 10: goto tr772;
		case 13: goto tr773;
	}
	goto tr734;
tr771:
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st568;
st568:
	if ( ++p == pe )
		goto _test_eof568;
case 568:
#line 12211 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 70 )
		goto st569;
	goto tr774;
st569:
	if ( ++p == pe )
		goto _test_eof569;
case 569:
	if ( (*p) == 79 )
		goto st570;
	goto tr774;
st570:
	if ( ++p == pe )
		goto _test_eof570;
case 570:
	if ( (*p) == 82 )
		goto st571;
	goto tr774;
st571:
	if ( ++p == pe )
		goto _test_eof571;
case 571:
	if ( (*p) == 77 )
		goto st572;
	goto tr774;
st572:
	if ( ++p == pe )
		goto _test_eof572;
case 572:
	if ( (*p) == 65 )
		goto st573;
	goto tr774;
st573:
	if ( ++p == pe )
		goto _test_eof573;
case 573:
	if ( (*p) == 84 )
		goto st574;
	goto tr774;
st574:
	if ( ++p == pe )
		goto _test_eof574;
case 574:
	if ( (*p) == 9 )
		goto tr781;
	goto tr774;
tr781:
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st575;
tr783:
#line 176 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_sample_name(*this);
    }
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st575;
st575:
	if ( ++p == pe )
		goto _test_eof575;
case 575:
#line 12277 "inc/vcf/validator_detail_v43.hpp"
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr782;
	goto tr774;
tr782:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st576;
tr786:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st576;
st576:
	if ( ++p == pe )
		goto _test_eof576;
case 576:
#line 12301 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr783;
		case 10: goto tr784;
		case 13: goto tr785;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr786;
	goto tr774;
tr772:
#line 180 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_header_line(*this);
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
	goto st724;
tr784:
#line 176 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_sample_name(*this);
    }
#line 180 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_header_line(*this);
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
	goto st724;
st724:
	if ( ++p == pe )
		goto _test_eof724;
case 724:
#line 12350 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 10: goto tr1012;
		case 13: goto tr1013;
		case 43: goto tr1014;
		case 59: goto tr1014;
		case 60: goto tr1015;
		case 92: goto tr1014;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr1014;
		} else if ( (*p) >= 33 )
			goto tr1014;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr1014;
		} else if ( (*p) >= 63 )
			goto tr1014;
	} else
		goto tr1014;
	goto tr1011;
tr1016:
#line 43 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st725;
tr1012:
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
	goto st725;
st725:
	if ( ++p == pe )
		goto _test_eof725;
case 725:
#line 12410 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 10: goto tr1016;
		case 13: goto tr1017;
	}
	goto st0;
tr1017:
#line 43 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st577;
tr1013:
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
	goto st577;
st577:
	if ( ++p == pe )
		goto _test_eof577;
case 577:
#line 12452 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 10 )
		goto st725;
	goto st0;
tr1023:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st578;
tr791:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st578;
tr1014:
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
	goto st578;
st578:
	if ( ++p == pe )
		goto _test_eof578;
case 578:
#line 12494 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr790;
		case 43: goto tr791;
		case 59: goto tr791;
		case 92: goto tr791;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr791;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr791;
		} else if ( (*p) >= 63 )
			goto tr791;
	} else
		goto tr791;
	goto tr789;
tr790:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 186 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st579;
tr859:
#line 186 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st579;
st579:
	if ( ++p == pe )
		goto _test_eof579;
case 579:
#line 12541 "inc/vcf/validator_detail_v43.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr793;
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
	goto st580;
tr795:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st580;
st580:
	if ( ++p == pe )
		goto _test_eof580;
case 580:
#line 12565 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 9 )
		goto tr794;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr795;
	goto tr792;
tr800:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st581;
tr794:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 186 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st581;
st581:
	if ( ++p == pe )
		goto _test_eof581;
case 581:
#line 12595 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr797;
	} else if ( (*p) >= 33 )
		goto tr797;
	goto tr796;
tr797:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st582;
tr799:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st582;
st582:
	if ( ++p == pe )
		goto _test_eof582;
case 582:
#line 12622 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr798;
		case 59: goto tr800;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr799;
	goto tr796;
tr798:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 186 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st583;
st583:
	if ( ++p == pe )
		goto _test_eof583;
case 583:
#line 12648 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 65: goto tr802;
		case 67: goto tr802;
		case 71: goto tr802;
		case 78: goto tr802;
		case 84: goto tr802;
		case 97: goto tr802;
		case 99: goto tr802;
		case 103: goto tr802;
		case 110: goto tr802;
		case 116: goto tr802;
	}
	goto tr801;
tr802:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st584;
tr804:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st584;
st584:
	if ( ++p == pe )
		goto _test_eof584;
case 584:
#line 12682 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr803;
		case 65: goto tr804;
		case 67: goto tr804;
		case 71: goto tr804;
		case 78: goto tr804;
		case 84: goto tr804;
		case 97: goto tr804;
		case 99: goto tr804;
		case 103: goto tr804;
		case 110: goto tr804;
		case 116: goto tr804;
	}
	goto tr801;
tr803:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 186 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st585;
st585:
	if ( ++p == pe )
		goto _test_eof585;
case 585:
#line 12715 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 42: goto tr806;
		case 46: goto tr807;
		case 60: goto tr808;
		case 65: goto tr809;
		case 67: goto tr809;
		case 71: goto tr809;
		case 78: goto tr809;
		case 84: goto tr809;
		case 91: goto tr810;
		case 93: goto tr811;
		case 97: goto tr809;
		case 99: goto tr809;
		case 103: goto tr809;
		case 110: goto tr809;
		case 116: goto tr809;
	}
	goto tr805;
tr806:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st586;
tr974:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st586;
st586:
	if ( ++p == pe )
		goto _test_eof586;
case 586:
#line 12754 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr812;
		case 44: goto tr813;
	}
	goto tr805;
tr812:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 186 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st587;
st587:
	if ( ++p == pe )
		goto _test_eof587;
case 587:
#line 12778 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr815;
		case 45: goto tr815;
		case 46: goto tr816;
		case 73: goto tr818;
		case 78: goto tr819;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr817;
	goto tr814;
tr815:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st588;
st588:
	if ( ++p == pe )
		goto _test_eof588;
case 588:
#line 12803 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 73 )
		goto tr821;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr820;
	goto tr814;
tr817:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st589;
tr820:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st589;
st589:
	if ( ++p == pe )
		goto _test_eof589;
case 589:
#line 12829 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr822;
		case 46: goto tr823;
		case 69: goto tr824;
		case 101: goto tr824;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr820;
	goto tr814;
tr822:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 186 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st590;
st590:
	if ( ++p == pe )
		goto _test_eof590;
case 590:
#line 12857 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 46: goto tr827;
		case 58: goto tr826;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr826;
		} else if ( (*p) > 57 ) {
			if ( 60 <= (*p) && (*p) <= 64 )
				goto tr826;
		} else
			goto tr828;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr826;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr826;
		} else
			goto tr828;
	} else
		goto tr828;
	goto tr825;
tr826:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st591;
st591:
	if ( ++p == pe )
		goto _test_eof591;
case 591:
#line 12893 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 58 )
		goto st591;
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto st591;
		} else if ( (*p) > 57 ) {
			if ( 60 <= (*p) && (*p) <= 64 )
				goto st591;
		} else
			goto tr830;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st591;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st591;
		} else
			goto tr830;
	} else
		goto tr830;
	goto tr825;
tr828:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st592;
tr830:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st592;
st592:
	if ( ++p == pe )
		goto _test_eof592;
case 592:
#line 12937 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr831;
		case 59: goto tr832;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr830;
	goto tr825;
tr831:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 186 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st593;
st593:
	if ( ++p == pe )
		goto _test_eof593;
case 593:
#line 12963 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 46: goto tr834;
		case 49: goto tr836;
		case 65: goto tr837;
		case 66: goto tr838;
		case 67: goto tr839;
		case 68: goto tr840;
		case 69: goto tr841;
		case 72: goto tr842;
		case 77: goto tr843;
		case 78: goto tr844;
		case 83: goto tr845;
		case 86: goto tr846;
		case 95: goto tr835;
	}
	if ( (*p) < 70 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr835;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr835;
	} else
		goto tr835;
	goto tr833;
tr834:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st726;
st726:
	if ( ++p == pe )
		goto _test_eof726;
case 726:
#line 13002 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
	}
	goto tr1018;
tr851:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st594;
tr1019:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 186 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st594;
st594:
	if ( ++p == pe )
		goto _test_eof594;
case 594:
#line 13033 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 95 )
		goto tr848;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr848;
	} else if ( (*p) >= 65 )
		goto tr848;
	goto tr847;
tr848:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st595;
tr850:
#line 35 "src/vcf/vcf.ragel"
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
		case 9: goto tr849;
		case 37: goto tr850;
		case 46: goto tr850;
		case 58: goto tr851;
		case 95: goto tr850;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr850;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr850;
	} else
		goto tr850;
	goto tr847;
tr849:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 186 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 53 "src/vcf/vcf.ragel"
	{
        ++n_columns;
    }
	goto st596;
st596:
	if ( ++p == pe )
		goto _test_eof596;
case 596:
#line 13097 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 46 )
		goto tr854;
	if ( (*p) < 48 ) {
		if ( 33 <= (*p) && (*p) <= 47 )
			goto tr853;
	} else if ( (*p) > 57 ) {
		if ( 59 <= (*p) && (*p) <= 126 )
			goto tr853;
	} else
		goto tr855;
	goto tr852;
tr853:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st727;
tr863:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st727;
st727:
	if ( ++p == pe )
		goto _test_eof727;
case 727:
#line 13129 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr849;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 58: goto tr1022;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr863;
	goto tr862;
tr1020:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 186 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 190 "src/vcf/vcf.ragel"
	{
        try {
            // Handle all columns and build record
            ParsePolicy::handle_body_line(*this);

            if (record != nullptr) {
                auto duplicated_errors = previous_records.check_duplicates(*record);
                for(auto &error_ptr : duplicated_errors) {
                    ErrorPolicy::handle_error(*this, error_ptr.release());
                }
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
	goto st728;
st728:
	if ( ++p == pe )
		goto _test_eof728;
case 728:
#line 13188 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 10: goto tr1016;
		case 13: goto tr1017;
		case 43: goto tr1023;
		case 59: goto tr1023;
		case 60: goto st597;
		case 92: goto tr1023;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr1023;
		} else if ( (*p) >= 33 )
			goto tr1023;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr1023;
		} else if ( (*p) >= 63 )
			goto tr1023;
	} else
		goto tr1023;
	goto tr789;
tr1015:
#line 70 "src/vcf/vcf.ragel"
	{
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (Error *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
    }
	goto st597;
st597:
	if ( ++p == pe )
		goto _test_eof597;
case 597:
#line 13226 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr856;
		case 59: goto tr856;
		case 92: goto tr856;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr856;
		} else if ( (*p) >= 33 )
			goto tr856;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr856;
		} else if ( (*p) >= 63 )
			goto tr856;
	} else
		goto tr856;
	goto tr789;
tr856:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st598;
tr857:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st598;
st598:
	if ( ++p == pe )
		goto _test_eof598;
case 598:
#line 13267 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr857;
		case 59: goto tr857;
		case 62: goto tr858;
		case 92: goto tr857;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr857;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr857;
		} else if ( (*p) >= 63 )
			goto tr857;
	} else
		goto tr857;
	goto tr789;
tr858:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st599;
st599:
	if ( ++p == pe )
		goto _test_eof599;
case 599:
#line 13296 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 9 )
		goto tr859;
	goto tr789;
tr1021:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 186 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 190 "src/vcf/vcf.ragel"
	{
        try {
            // Handle all columns and build record
            ParsePolicy::handle_body_line(*this);

            if (record != nullptr) {
                auto duplicated_errors = previous_records.check_duplicates(*record);
                for(auto &error_ptr : duplicated_errors) {
                    ErrorPolicy::handle_error(*this, error_ptr.release());
                }
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
	goto st600;
st600:
	if ( ++p == pe )
		goto _test_eof600;
case 600:
#line 13349 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 10 )
		goto st728;
	goto tr860;
tr1022:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st601;
st601:
	if ( ++p == pe )
		goto _test_eof601;
case 601:
#line 13363 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) > 57 ) {
		if ( 59 <= (*p) && (*p) <= 126 )
			goto tr863;
	} else if ( (*p) >= 33 )
		goto tr863;
	goto tr862;
tr854:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st729;
tr1026:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st729;
st729:
	if ( ++p == pe )
		goto _test_eof729;
case 729:
#line 13390 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr849;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 47: goto tr1025;
		case 58: goto tr1022;
		case 124: goto tr1025;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr863;
	goto tr852;
tr1025:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st730;
st730:
	if ( ++p == pe )
		goto _test_eof730;
case 730:
#line 13412 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr849;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 46: goto tr1026;
		case 58: goto tr1022;
	}
	if ( (*p) < 48 ) {
		if ( 33 <= (*p) && (*p) <= 47 )
			goto tr863;
	} else if ( (*p) > 57 ) {
		if ( 59 <= (*p) && (*p) <= 126 )
			goto tr863;
	} else
		goto tr1027;
	goto tr852;
tr855:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st731;
tr1027:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st731;
st731:
	if ( ++p == pe )
		goto _test_eof731;
case 731:
#line 13449 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr849;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 47: goto tr1025;
		case 58: goto tr1022;
		case 124: goto tr1025;
	}
	if ( (*p) < 48 ) {
		if ( 33 <= (*p) && (*p) <= 46 )
			goto tr863;
	} else if ( (*p) > 57 ) {
		if ( 59 <= (*p) && (*p) <= 126 )
			goto tr863;
	} else
		goto tr1027;
	goto tr852;
tr835:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st732;
tr868:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st732;
st732:
	if ( ++p == pe )
		goto _test_eof732;
case 732:
#line 13487 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 46: goto tr868;
		case 59: goto tr1028;
		case 61: goto tr1029;
		case 95: goto tr868;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr868;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr868;
	} else
		goto tr868;
	goto tr833;
tr1028:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st602;
st602:
	if ( ++p == pe )
		goto _test_eof602;
case 602:
#line 13516 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 49: goto tr836;
		case 65: goto tr837;
		case 66: goto tr838;
		case 67: goto tr839;
		case 68: goto tr840;
		case 69: goto tr841;
		case 72: goto tr842;
		case 77: goto tr843;
		case 78: goto tr844;
		case 83: goto tr845;
		case 86: goto tr846;
		case 95: goto tr835;
	}
	if ( (*p) < 70 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr835;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr835;
	} else
		goto tr835;
	goto tr833;
tr836:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st733;
st733:
	if ( ++p == pe )
		goto _test_eof733;
case 733:
#line 13554 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 46: goto tr868;
		case 48: goto tr1030;
		case 59: goto tr1028;
		case 61: goto tr1029;
		case 95: goto tr868;
	}
	if ( (*p) < 65 ) {
		if ( 49 <= (*p) && (*p) <= 57 )
			goto tr868;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr868;
	} else
		goto tr868;
	goto tr833;
tr1030:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st734;
st734:
	if ( ++p == pe )
		goto _test_eof734;
case 734:
#line 13584 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 46: goto tr868;
		case 48: goto tr1031;
		case 59: goto tr1028;
		case 61: goto tr1029;
		case 95: goto tr868;
	}
	if ( (*p) < 65 ) {
		if ( 49 <= (*p) && (*p) <= 57 )
			goto tr868;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr868;
	} else
		goto tr868;
	goto tr833;
tr1031:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st735;
st735:
	if ( ++p == pe )
		goto _test_eof735;
case 735:
#line 13614 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 46: goto tr868;
		case 48: goto tr1032;
		case 59: goto tr1028;
		case 61: goto tr1029;
		case 95: goto tr868;
	}
	if ( (*p) < 65 ) {
		if ( 49 <= (*p) && (*p) <= 57 )
			goto tr868;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr868;
	} else
		goto tr868;
	goto tr833;
tr1032:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st736;
st736:
	if ( ++p == pe )
		goto _test_eof736;
case 736:
#line 13644 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 46: goto tr868;
		case 59: goto tr1028;
		case 61: goto tr1029;
		case 71: goto tr1033;
		case 95: goto tr868;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr868;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr868;
	} else
		goto tr868;
	goto tr833;
tr1029:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st603;
st603:
	if ( ++p == pe )
		goto _test_eof603;
case 603:
#line 13674 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr865;
	} else if ( (*p) >= 32 )
		goto tr865;
	goto tr864;
tr865:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st737;
st737:
	if ( ++p == pe )
		goto _test_eof737;
case 737:
#line 13691 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 59: goto tr1028;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr865;
	goto tr864;
tr1033:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st738;
st738:
	if ( ++p == pe )
		goto _test_eof738;
case 738:
#line 13711 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 46: goto tr868;
		case 59: goto tr1028;
		case 61: goto tr1035;
		case 95: goto tr868;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr868;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr868;
	} else
		goto tr868;
	goto tr1034;
tr1035:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st604;
st604:
	if ( ++p == pe )
		goto _test_eof604;
case 604:
#line 13740 "inc/vcf/validator_detail_v43.hpp"
	if ( 48 <= (*p) && (*p) <= 49 )
		goto tr867;
	goto tr866;
tr867:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st739;
st739:
	if ( ++p == pe )
		goto _test_eof739;
case 739:
#line 13754 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 59: goto tr1028;
	}
	goto tr866;
tr837:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st740;
st740:
	if ( ++p == pe )
		goto _test_eof740;
case 740:
#line 13776 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 46: goto tr868;
		case 59: goto tr1028;
		case 61: goto tr1029;
		case 65: goto tr1036;
		case 67: goto tr1037;
		case 68: goto tr1038;
		case 70: goto tr1039;
		case 78: goto tr1040;
		case 95: goto tr868;
	}
	if ( (*p) < 66 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr868;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr868;
	} else
		goto tr868;
	goto tr833;
tr1036:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st605;
st605:
	if ( ++p == pe )
		goto _test_eof605;
case 605:
#line 13810 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 46: goto tr868;
		case 61: goto tr869;
		case 95: goto tr868;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr868;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr868;
	} else
		goto tr868;
	goto tr833;
tr869:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st606;
st606:
	if ( ++p == pe )
		goto _test_eof606;
case 606:
#line 13835 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 60 )
		goto tr871;
	if ( (*p) < 45 ) {
		if ( 32 <= (*p) && (*p) <= 43 )
			goto tr871;
	} else if ( (*p) > 58 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto tr871;
	} else
		goto tr871;
	goto tr870;
tr871:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st741;
st741:
	if ( ++p == pe )
		goto _test_eof741;
case 741:
#line 13857 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 59: goto tr1028;
	}
	if ( (*p) < 45 ) {
		if ( 32 <= (*p) && (*p) <= 43 )
			goto tr871;
	} else if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto tr871;
	} else
		goto tr871;
	goto tr870;
tr1037:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st607;
st607:
	if ( ++p == pe )
		goto _test_eof607;
case 607:
#line 13883 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 46: goto tr868;
		case 61: goto tr872;
		case 95: goto tr868;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr868;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr868;
	} else
		goto tr868;
	goto tr833;
tr872:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st608;
st608:
	if ( ++p == pe )
		goto _test_eof608;
case 608:
#line 13908 "inc/vcf/validator_detail_v43.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr874;
	goto tr873;
tr874:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st742;
st742:
	if ( ++p == pe )
		goto _test_eof742;
case 742:
#line 13922 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 44: goto tr872;
		case 59: goto tr1028;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr874;
	goto tr873;
tr1038:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st609;
st609:
	if ( ++p == pe )
		goto _test_eof609;
case 609:
#line 13943 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 46: goto tr868;
		case 61: goto tr875;
		case 70: goto tr876;
		case 82: goto tr877;
		case 95: goto tr868;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr868;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr868;
	} else
		goto tr868;
	goto tr833;
tr875:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st610;
st610:
	if ( ++p == pe )
		goto _test_eof610;
case 610:
#line 13970 "inc/vcf/validator_detail_v43.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr879;
	goto tr878;
tr879:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st743;
st743:
	if ( ++p == pe )
		goto _test_eof743;
case 743:
#line 13984 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 44: goto tr875;
		case 59: goto tr1028;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr879;
	goto tr878;
tr876:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st611;
st611:
	if ( ++p == pe )
		goto _test_eof611;
case 611:
#line 14005 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 46: goto tr868;
		case 61: goto tr880;
		case 95: goto tr868;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr868;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr868;
	} else
		goto tr868;
	goto tr833;
tr880:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st612;
st612:
	if ( ++p == pe )
		goto _test_eof612;
case 612:
#line 14030 "inc/vcf/validator_detail_v43.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr882;
	goto tr881;
tr882:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st744;
st744:
	if ( ++p == pe )
		goto _test_eof744;
case 744:
#line 14044 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 44: goto tr880;
		case 59: goto tr1028;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr882;
	goto tr881;
tr877:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st613;
st613:
	if ( ++p == pe )
		goto _test_eof613;
case 613:
#line 14065 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 46: goto tr868;
		case 61: goto tr883;
		case 95: goto tr868;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr868;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr868;
	} else
		goto tr868;
	goto tr833;
tr883:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st614;
st614:
	if ( ++p == pe )
		goto _test_eof614;
case 614:
#line 14090 "inc/vcf/validator_detail_v43.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr885;
	goto tr884;
tr885:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st745;
st745:
	if ( ++p == pe )
		goto _test_eof745;
case 745:
#line 14104 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 44: goto tr883;
		case 59: goto tr1028;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr885;
	goto tr884;
tr1039:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st615;
st615:
	if ( ++p == pe )
		goto _test_eof615;
case 615:
#line 14125 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 46: goto tr868;
		case 61: goto tr886;
		case 95: goto tr868;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr868;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr868;
	} else
		goto tr868;
	goto tr833;
tr886:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st616;
st616:
	if ( ++p == pe )
		goto _test_eof616;
case 616:
#line 14150 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr888;
		case 45: goto tr888;
		case 73: goto tr890;
		case 78: goto tr891;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr889;
	goto tr887;
tr888:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st617;
st617:
	if ( ++p == pe )
		goto _test_eof617;
case 617:
#line 14170 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 73 )
		goto tr890;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr889;
	goto tr887;
tr889:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st746;
st746:
	if ( ++p == pe )
		goto _test_eof746;
case 746:
#line 14186 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 44: goto tr886;
		case 46: goto tr1041;
		case 59: goto tr1028;
		case 69: goto tr1042;
		case 101: goto tr1042;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr889;
	goto tr887;
tr1041:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st618;
st618:
	if ( ++p == pe )
		goto _test_eof618;
case 618:
#line 14210 "inc/vcf/validator_detail_v43.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr892;
	goto tr887;
tr892:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st747;
st747:
	if ( ++p == pe )
		goto _test_eof747;
case 747:
#line 14224 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 44: goto tr886;
		case 59: goto tr1028;
		case 69: goto tr1042;
		case 101: goto tr1042;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr892;
	goto tr887;
tr1042:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st619;
st619:
	if ( ++p == pe )
		goto _test_eof619;
case 619:
#line 14247 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr893;
		case 45: goto tr893;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr894;
	goto tr887;
tr893:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st620;
st620:
	if ( ++p == pe )
		goto _test_eof620;
case 620:
#line 14265 "inc/vcf/validator_detail_v43.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr894;
	goto tr887;
tr894:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st748;
st748:
	if ( ++p == pe )
		goto _test_eof748;
case 748:
#line 14279 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 44: goto tr886;
		case 59: goto tr1028;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr894;
	goto tr887;
tr890:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st621;
st621:
	if ( ++p == pe )
		goto _test_eof621;
case 621:
#line 14300 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 110 )
		goto tr895;
	goto tr887;
tr895:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st622;
st622:
	if ( ++p == pe )
		goto _test_eof622;
case 622:
#line 14314 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 102 )
		goto tr896;
	goto tr887;
tr896:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st749;
st749:
	if ( ++p == pe )
		goto _test_eof749;
case 749:
#line 14328 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 44: goto tr886;
		case 59: goto tr1028;
	}
	goto tr887;
tr891:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st623;
st623:
	if ( ++p == pe )
		goto _test_eof623;
case 623:
#line 14347 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 97 )
		goto tr897;
	goto tr887;
tr897:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st624;
st624:
	if ( ++p == pe )
		goto _test_eof624;
case 624:
#line 14361 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 78 )
		goto tr896;
	goto tr887;
tr1040:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st625;
st625:
	if ( ++p == pe )
		goto _test_eof625;
case 625:
#line 14375 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 46: goto tr868;
		case 61: goto tr898;
		case 95: goto tr868;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr868;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr868;
	} else
		goto tr868;
	goto tr833;
tr898:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st626;
st626:
	if ( ++p == pe )
		goto _test_eof626;
case 626:
#line 14400 "inc/vcf/validator_detail_v43.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr900;
	goto tr899;
tr900:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st750;
st750:
	if ( ++p == pe )
		goto _test_eof750;
case 750:
#line 14414 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 59: goto tr1028;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr900;
	goto tr899;
tr838:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st751;
st751:
	if ( ++p == pe )
		goto _test_eof751;
case 751:
#line 14438 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 46: goto tr868;
		case 59: goto tr1028;
		case 61: goto tr1029;
		case 81: goto tr1043;
		case 95: goto tr868;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr868;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr868;
	} else
		goto tr868;
	goto tr833;
tr1043:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st627;
st627:
	if ( ++p == pe )
		goto _test_eof627;
case 627:
#line 14468 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 46: goto tr868;
		case 61: goto tr901;
		case 95: goto tr868;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr868;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr868;
	} else
		goto tr868;
	goto tr833;
tr901:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st628;
st628:
	if ( ++p == pe )
		goto _test_eof628;
case 628:
#line 14493 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr903;
		case 45: goto tr903;
		case 73: goto tr905;
		case 78: goto tr906;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr904;
	goto tr902;
tr903:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st629;
st629:
	if ( ++p == pe )
		goto _test_eof629;
case 629:
#line 14513 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 73 )
		goto tr905;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr904;
	goto tr902;
tr904:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st752;
st752:
	if ( ++p == pe )
		goto _test_eof752;
case 752:
#line 14529 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 46: goto tr1044;
		case 59: goto tr1028;
		case 69: goto tr1045;
		case 101: goto tr1045;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr904;
	goto tr902;
tr1044:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st630;
st630:
	if ( ++p == pe )
		goto _test_eof630;
case 630:
#line 14552 "inc/vcf/validator_detail_v43.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr907;
	goto tr902;
tr907:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st753;
st753:
	if ( ++p == pe )
		goto _test_eof753;
case 753:
#line 14566 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 59: goto tr1028;
		case 69: goto tr1045;
		case 101: goto tr1045;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr907;
	goto tr902;
tr1045:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st631;
st631:
	if ( ++p == pe )
		goto _test_eof631;
case 631:
#line 14588 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr908;
		case 45: goto tr908;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr909;
	goto tr902;
tr908:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st632;
st632:
	if ( ++p == pe )
		goto _test_eof632;
case 632:
#line 14606 "inc/vcf/validator_detail_v43.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr909;
	goto tr902;
tr909:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st754;
st754:
	if ( ++p == pe )
		goto _test_eof754;
case 754:
#line 14620 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 59: goto tr1028;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr909;
	goto tr902;
tr905:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st633;
st633:
	if ( ++p == pe )
		goto _test_eof633;
case 633:
#line 14640 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 110 )
		goto tr910;
	goto tr902;
tr910:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st634;
st634:
	if ( ++p == pe )
		goto _test_eof634;
case 634:
#line 14654 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 102 )
		goto tr911;
	goto tr902;
tr911:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st755;
st755:
	if ( ++p == pe )
		goto _test_eof755;
case 755:
#line 14668 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 59: goto tr1028;
	}
	goto tr902;
tr906:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st635;
st635:
	if ( ++p == pe )
		goto _test_eof635;
case 635:
#line 14686 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 97 )
		goto tr912;
	goto tr902;
tr912:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st636;
st636:
	if ( ++p == pe )
		goto _test_eof636;
case 636:
#line 14700 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 78 )
		goto tr911;
	goto tr902;
tr839:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st756;
st756:
	if ( ++p == pe )
		goto _test_eof756;
case 756:
#line 14718 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 46: goto tr868;
		case 59: goto tr1028;
		case 61: goto tr1029;
		case 73: goto tr1046;
		case 95: goto tr868;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr868;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr868;
	} else
		goto tr868;
	goto tr833;
tr1046:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st757;
st757:
	if ( ++p == pe )
		goto _test_eof757;
case 757:
#line 14748 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 46: goto tr868;
		case 59: goto tr1028;
		case 61: goto tr1029;
		case 71: goto tr1047;
		case 95: goto tr868;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr868;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr868;
	} else
		goto tr868;
	goto tr833;
tr1047:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st758;
st758:
	if ( ++p == pe )
		goto _test_eof758;
case 758:
#line 14778 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 46: goto tr868;
		case 59: goto tr1028;
		case 61: goto tr1029;
		case 65: goto tr1048;
		case 95: goto tr868;
	}
	if ( (*p) < 66 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr868;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr868;
	} else
		goto tr868;
	goto tr833;
tr1048:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st759;
st759:
	if ( ++p == pe )
		goto _test_eof759;
case 759:
#line 14808 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 46: goto tr868;
		case 59: goto tr1028;
		case 61: goto tr1029;
		case 82: goto tr1049;
		case 95: goto tr868;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr868;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr868;
	} else
		goto tr868;
	goto tr833;
tr1049:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st637;
st637:
	if ( ++p == pe )
		goto _test_eof637;
case 637:
#line 14838 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 46: goto tr868;
		case 61: goto tr913;
		case 95: goto tr868;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr868;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr868;
	} else
		goto tr868;
	goto tr833;
tr913:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st638;
st638:
	if ( ++p == pe )
		goto _test_eof638;
case 638:
#line 14863 "inc/vcf/validator_detail_v43.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr915;
	goto tr914;
tr915:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st639;
st639:
	if ( ++p == pe )
		goto _test_eof639;
case 639:
#line 14877 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 68: goto tr916;
		case 80: goto tr916;
		case 83: goto tr916;
		case 88: goto tr916;
	}
	if ( (*p) < 72 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr915;
	} else if ( (*p) > 73 ) {
		if ( 77 <= (*p) && (*p) <= 78 )
			goto tr916;
	} else
		goto tr916;
	goto tr914;
tr916:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st760;
st760:
	if ( ++p == pe )
		goto _test_eof760;
case 760:
#line 14903 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 44: goto tr913;
		case 59: goto tr1028;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr915;
	goto tr914;
tr840:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st761;
st761:
	if ( ++p == pe )
		goto _test_eof761;
case 761:
#line 14928 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 46: goto tr868;
		case 59: goto tr1028;
		case 61: goto tr1029;
		case 66: goto tr1050;
		case 80: goto tr1051;
		case 95: goto tr868;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr868;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr868;
	} else
		goto tr868;
	goto tr833;
tr1050:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st762;
st762:
	if ( ++p == pe )
		goto _test_eof762;
case 762:
#line 14959 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 46: goto tr868;
		case 59: goto tr1028;
		case 61: goto tr1053;
		case 95: goto tr868;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr868;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr868;
	} else
		goto tr868;
	goto tr1052;
tr1053:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st640;
st640:
	if ( ++p == pe )
		goto _test_eof640;
case 640:
#line 14988 "inc/vcf/validator_detail_v43.hpp"
	if ( 48 <= (*p) && (*p) <= 49 )
		goto tr918;
	goto tr917;
tr918:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st763;
st763:
	if ( ++p == pe )
		goto _test_eof763;
case 763:
#line 15002 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 59: goto tr1028;
	}
	goto tr917;
tr1051:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st641;
st641:
	if ( ++p == pe )
		goto _test_eof641;
case 641:
#line 15020 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 46: goto tr868;
		case 61: goto tr919;
		case 95: goto tr868;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr868;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr868;
	} else
		goto tr868;
	goto tr833;
tr919:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st642;
st642:
	if ( ++p == pe )
		goto _test_eof642;
case 642:
#line 15045 "inc/vcf/validator_detail_v43.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr921;
	goto tr920;
tr921:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st764;
st764:
	if ( ++p == pe )
		goto _test_eof764;
case 764:
#line 15059 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 59: goto tr1028;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr921;
	goto tr920;
tr841:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st765;
st765:
	if ( ++p == pe )
		goto _test_eof765;
case 765:
#line 15083 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 46: goto tr868;
		case 59: goto tr1028;
		case 61: goto tr1029;
		case 78: goto tr1054;
		case 95: goto tr868;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr868;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr868;
	} else
		goto tr868;
	goto tr833;
tr1054:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st766;
st766:
	if ( ++p == pe )
		goto _test_eof766;
case 766:
#line 15113 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 46: goto tr868;
		case 59: goto tr1028;
		case 61: goto tr1029;
		case 68: goto tr1055;
		case 95: goto tr868;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr868;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr868;
	} else
		goto tr868;
	goto tr833;
tr1055:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st643;
st643:
	if ( ++p == pe )
		goto _test_eof643;
case 643:
#line 15143 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 46: goto tr868;
		case 61: goto tr922;
		case 95: goto tr868;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr868;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr868;
	} else
		goto tr868;
	goto tr833;
tr922:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st644;
st644:
	if ( ++p == pe )
		goto _test_eof644;
case 644:
#line 15168 "inc/vcf/validator_detail_v43.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr924;
	goto tr923;
tr924:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st767;
st767:
	if ( ++p == pe )
		goto _test_eof767;
case 767:
#line 15182 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 59: goto tr1028;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr924;
	goto tr923;
tr842:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st768;
st768:
	if ( ++p == pe )
		goto _test_eof768;
case 768:
#line 15206 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 46: goto tr868;
		case 50: goto tr1056;
		case 51: goto tr1057;
		case 59: goto tr1028;
		case 61: goto tr1029;
		case 95: goto tr868;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr868;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr868;
	} else
		goto tr868;
	goto tr833;
tr1056:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st769;
st769:
	if ( ++p == pe )
		goto _test_eof769;
case 769:
#line 15237 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 46: goto tr868;
		case 59: goto tr1028;
		case 61: goto tr1059;
		case 95: goto tr868;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr868;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr868;
	} else
		goto tr868;
	goto tr1058;
tr1059:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st645;
st645:
	if ( ++p == pe )
		goto _test_eof645;
case 645:
#line 15266 "inc/vcf/validator_detail_v43.hpp"
	if ( 48 <= (*p) && (*p) <= 49 )
		goto tr926;
	goto tr925;
tr926:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st770;
st770:
	if ( ++p == pe )
		goto _test_eof770;
case 770:
#line 15280 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 59: goto tr1028;
	}
	goto tr925;
tr1057:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st771;
st771:
	if ( ++p == pe )
		goto _test_eof771;
case 771:
#line 15298 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 46: goto tr868;
		case 59: goto tr1028;
		case 61: goto tr1061;
		case 95: goto tr868;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr868;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr868;
	} else
		goto tr868;
	goto tr1060;
tr1061:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st646;
st646:
	if ( ++p == pe )
		goto _test_eof646;
case 646:
#line 15327 "inc/vcf/validator_detail_v43.hpp"
	if ( 48 <= (*p) && (*p) <= 49 )
		goto tr928;
	goto tr927;
tr928:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st772;
st772:
	if ( ++p == pe )
		goto _test_eof772;
case 772:
#line 15341 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 59: goto tr1028;
	}
	goto tr927;
tr843:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st773;
st773:
	if ( ++p == pe )
		goto _test_eof773;
case 773:
#line 15363 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 46: goto tr868;
		case 59: goto tr1028;
		case 61: goto tr1029;
		case 81: goto tr1062;
		case 95: goto tr868;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr868;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr868;
	} else
		goto tr868;
	goto tr833;
tr1062:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st647;
st647:
	if ( ++p == pe )
		goto _test_eof647;
case 647:
#line 15393 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 46: goto tr868;
		case 48: goto tr929;
		case 61: goto tr930;
		case 95: goto tr868;
	}
	if ( (*p) < 65 ) {
		if ( 49 <= (*p) && (*p) <= 57 )
			goto tr868;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr868;
	} else
		goto tr868;
	goto tr833;
tr929:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st648;
st648:
	if ( ++p == pe )
		goto _test_eof648;
case 648:
#line 15419 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 46: goto tr868;
		case 61: goto tr931;
		case 95: goto tr868;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr868;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr868;
	} else
		goto tr868;
	goto tr833;
tr931:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st649;
st649:
	if ( ++p == pe )
		goto _test_eof649;
case 649:
#line 15444 "inc/vcf/validator_detail_v43.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr933;
	goto tr932;
tr933:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st774;
st774:
	if ( ++p == pe )
		goto _test_eof774;
case 774:
#line 15458 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 59: goto tr1028;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr933;
	goto tr932;
tr930:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st650;
st650:
	if ( ++p == pe )
		goto _test_eof650;
case 650:
#line 15478 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr935;
		case 45: goto tr935;
		case 73: goto tr937;
		case 78: goto tr938;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr936;
	goto tr934;
tr935:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st651;
st651:
	if ( ++p == pe )
		goto _test_eof651;
case 651:
#line 15498 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 73 )
		goto tr937;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr936;
	goto tr934;
tr936:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st775;
st775:
	if ( ++p == pe )
		goto _test_eof775;
case 775:
#line 15514 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 46: goto tr1063;
		case 59: goto tr1028;
		case 69: goto tr1064;
		case 101: goto tr1064;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr936;
	goto tr934;
tr1063:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st652;
st652:
	if ( ++p == pe )
		goto _test_eof652;
case 652:
#line 15537 "inc/vcf/validator_detail_v43.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr939;
	goto tr934;
tr939:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st776;
st776:
	if ( ++p == pe )
		goto _test_eof776;
case 776:
#line 15551 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 59: goto tr1028;
		case 69: goto tr1064;
		case 101: goto tr1064;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr939;
	goto tr934;
tr1064:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st653;
st653:
	if ( ++p == pe )
		goto _test_eof653;
case 653:
#line 15573 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr940;
		case 45: goto tr940;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr941;
	goto tr934;
tr940:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st654;
st654:
	if ( ++p == pe )
		goto _test_eof654;
case 654:
#line 15591 "inc/vcf/validator_detail_v43.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr941;
	goto tr934;
tr941:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st777;
st777:
	if ( ++p == pe )
		goto _test_eof777;
case 777:
#line 15605 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 59: goto tr1028;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr941;
	goto tr934;
tr937:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st655;
st655:
	if ( ++p == pe )
		goto _test_eof655;
case 655:
#line 15625 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 110 )
		goto tr942;
	goto tr934;
tr942:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st656;
st656:
	if ( ++p == pe )
		goto _test_eof656;
case 656:
#line 15639 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 102 )
		goto tr943;
	goto tr934;
tr943:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st778;
st778:
	if ( ++p == pe )
		goto _test_eof778;
case 778:
#line 15653 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 59: goto tr1028;
	}
	goto tr934;
tr938:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st657;
st657:
	if ( ++p == pe )
		goto _test_eof657;
case 657:
#line 15671 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 97 )
		goto tr944;
	goto tr934;
tr944:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st658;
st658:
	if ( ++p == pe )
		goto _test_eof658;
case 658:
#line 15685 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 78 )
		goto tr943;
	goto tr934;
tr844:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st779;
st779:
	if ( ++p == pe )
		goto _test_eof779;
case 779:
#line 15703 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 46: goto tr868;
		case 59: goto tr1028;
		case 61: goto tr1029;
		case 83: goto tr1065;
		case 95: goto tr868;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr868;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr868;
	} else
		goto tr868;
	goto tr833;
tr1065:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st659;
st659:
	if ( ++p == pe )
		goto _test_eof659;
case 659:
#line 15733 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 46: goto tr868;
		case 61: goto tr945;
		case 95: goto tr868;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr868;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr868;
	} else
		goto tr868;
	goto tr833;
tr945:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st660;
st660:
	if ( ++p == pe )
		goto _test_eof660;
case 660:
#line 15758 "inc/vcf/validator_detail_v43.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr947;
	goto tr946;
tr947:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st780;
st780:
	if ( ++p == pe )
		goto _test_eof780;
case 780:
#line 15772 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 59: goto tr1028;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr947;
	goto tr946;
tr845:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st781;
st781:
	if ( ++p == pe )
		goto _test_eof781;
case 781:
#line 15796 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 46: goto tr868;
		case 59: goto tr1028;
		case 61: goto tr1029;
		case 66: goto tr1066;
		case 79: goto tr1067;
		case 95: goto tr868;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr868;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr868;
	} else
		goto tr868;
	goto tr833;
tr1066:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st661;
st661:
	if ( ++p == pe )
		goto _test_eof661;
case 661:
#line 15827 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 46: goto tr868;
		case 61: goto tr948;
		case 95: goto tr868;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr868;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr868;
	} else
		goto tr868;
	goto tr833;
tr948:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st662;
st662:
	if ( ++p == pe )
		goto _test_eof662;
case 662:
#line 15852 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr950;
		case 45: goto tr950;
		case 73: goto tr952;
		case 78: goto tr953;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr951;
	goto tr949;
tr950:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st663;
st663:
	if ( ++p == pe )
		goto _test_eof663;
case 663:
#line 15872 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 73 )
		goto tr952;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr951;
	goto tr949;
tr951:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st782;
st782:
	if ( ++p == pe )
		goto _test_eof782;
case 782:
#line 15888 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 46: goto tr1068;
		case 59: goto tr1028;
		case 69: goto tr1069;
		case 101: goto tr1069;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr951;
	goto tr949;
tr1068:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st664;
st664:
	if ( ++p == pe )
		goto _test_eof664;
case 664:
#line 15911 "inc/vcf/validator_detail_v43.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr954;
	goto tr949;
tr954:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st783;
st783:
	if ( ++p == pe )
		goto _test_eof783;
case 783:
#line 15925 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 59: goto tr1028;
		case 69: goto tr1069;
		case 101: goto tr1069;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr954;
	goto tr949;
tr1069:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st665;
st665:
	if ( ++p == pe )
		goto _test_eof665;
case 665:
#line 15947 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr955;
		case 45: goto tr955;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr956;
	goto tr949;
tr955:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st666;
st666:
	if ( ++p == pe )
		goto _test_eof666;
case 666:
#line 15965 "inc/vcf/validator_detail_v43.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr956;
	goto tr949;
tr956:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st784;
st784:
	if ( ++p == pe )
		goto _test_eof784;
case 784:
#line 15979 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 59: goto tr1028;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr956;
	goto tr949;
tr952:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st667;
st667:
	if ( ++p == pe )
		goto _test_eof667;
case 667:
#line 15999 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 110 )
		goto tr957;
	goto tr949;
tr957:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st668;
st668:
	if ( ++p == pe )
		goto _test_eof668;
case 668:
#line 16013 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 102 )
		goto tr958;
	goto tr949;
tr958:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st785;
st785:
	if ( ++p == pe )
		goto _test_eof785;
case 785:
#line 16027 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 59: goto tr1028;
	}
	goto tr949;
tr953:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st669;
st669:
	if ( ++p == pe )
		goto _test_eof669;
case 669:
#line 16045 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 97 )
		goto tr959;
	goto tr949;
tr959:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st670;
st670:
	if ( ++p == pe )
		goto _test_eof670;
case 670:
#line 16059 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 78 )
		goto tr958;
	goto tr949;
tr1067:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st786;
st786:
	if ( ++p == pe )
		goto _test_eof786;
case 786:
#line 16073 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 46: goto tr868;
		case 59: goto tr1028;
		case 61: goto tr1029;
		case 77: goto tr1070;
		case 95: goto tr868;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr868;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr868;
	} else
		goto tr868;
	goto tr833;
tr1070:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st787;
st787:
	if ( ++p == pe )
		goto _test_eof787;
case 787:
#line 16103 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 46: goto tr868;
		case 59: goto tr1028;
		case 61: goto tr1029;
		case 65: goto tr1071;
		case 95: goto tr868;
	}
	if ( (*p) < 66 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr868;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr868;
	} else
		goto tr868;
	goto tr833;
tr1071:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st788;
st788:
	if ( ++p == pe )
		goto _test_eof788;
case 788:
#line 16133 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 46: goto tr868;
		case 59: goto tr1028;
		case 61: goto tr1029;
		case 84: goto tr1072;
		case 95: goto tr868;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr868;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr868;
	} else
		goto tr868;
	goto tr833;
tr1072:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st789;
st789:
	if ( ++p == pe )
		goto _test_eof789;
case 789:
#line 16163 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 46: goto tr868;
		case 59: goto tr1028;
		case 61: goto tr1029;
		case 73: goto tr1073;
		case 95: goto tr868;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr868;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr868;
	} else
		goto tr868;
	goto tr833;
tr1073:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st790;
st790:
	if ( ++p == pe )
		goto _test_eof790;
case 790:
#line 16193 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 46: goto tr868;
		case 59: goto tr1028;
		case 61: goto tr1029;
		case 67: goto tr1074;
		case 95: goto tr868;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr868;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr868;
	} else
		goto tr868;
	goto tr833;
tr1074:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st791;
st791:
	if ( ++p == pe )
		goto _test_eof791;
case 791:
#line 16223 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 46: goto tr868;
		case 59: goto tr1028;
		case 61: goto tr1076;
		case 95: goto tr868;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr868;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr868;
	} else
		goto tr868;
	goto tr1075;
tr1076:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st671;
st671:
	if ( ++p == pe )
		goto _test_eof671;
case 671:
#line 16252 "inc/vcf/validator_detail_v43.hpp"
	if ( 48 <= (*p) && (*p) <= 49 )
		goto tr961;
	goto tr960;
tr961:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st792;
st792:
	if ( ++p == pe )
		goto _test_eof792;
case 792:
#line 16266 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 59: goto tr1028;
	}
	goto tr960;
tr846:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st793;
st793:
	if ( ++p == pe )
		goto _test_eof793;
case 793:
#line 16288 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 46: goto tr868;
		case 59: goto tr1028;
		case 61: goto tr1029;
		case 65: goto tr1077;
		case 95: goto tr868;
	}
	if ( (*p) < 66 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr868;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr868;
	} else
		goto tr868;
	goto tr833;
tr1077:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st794;
st794:
	if ( ++p == pe )
		goto _test_eof794;
case 794:
#line 16318 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 46: goto tr868;
		case 59: goto tr1028;
		case 61: goto tr1029;
		case 76: goto tr1078;
		case 95: goto tr868;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr868;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr868;
	} else
		goto tr868;
	goto tr833;
tr1078:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st795;
st795:
	if ( ++p == pe )
		goto _test_eof795;
case 795:
#line 16348 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 46: goto tr868;
		case 59: goto tr1028;
		case 61: goto tr1029;
		case 73: goto tr1079;
		case 95: goto tr868;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr868;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr868;
	} else
		goto tr868;
	goto tr833;
tr1079:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st796;
st796:
	if ( ++p == pe )
		goto _test_eof796;
case 796:
#line 16378 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 46: goto tr868;
		case 59: goto tr1028;
		case 61: goto tr1029;
		case 68: goto tr1080;
		case 95: goto tr868;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr868;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr868;
	} else
		goto tr868;
	goto tr833;
tr1080:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st797;
st797:
	if ( ++p == pe )
		goto _test_eof797;
case 797:
#line 16408 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 46: goto tr868;
		case 59: goto tr1028;
		case 61: goto tr1029;
		case 65: goto tr1081;
		case 95: goto tr868;
	}
	if ( (*p) < 66 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr868;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr868;
	} else
		goto tr868;
	goto tr833;
tr1081:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st798;
st798:
	if ( ++p == pe )
		goto _test_eof798;
case 798:
#line 16438 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 46: goto tr868;
		case 59: goto tr1028;
		case 61: goto tr1029;
		case 84: goto tr1082;
		case 95: goto tr868;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr868;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr868;
	} else
		goto tr868;
	goto tr833;
tr1082:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st799;
st799:
	if ( ++p == pe )
		goto _test_eof799;
case 799:
#line 16468 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 46: goto tr868;
		case 59: goto tr1028;
		case 61: goto tr1029;
		case 69: goto tr1083;
		case 95: goto tr868;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr868;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr868;
	} else
		goto tr868;
	goto tr833;
tr1083:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st800;
st800:
	if ( ++p == pe )
		goto _test_eof800;
case 800:
#line 16498 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 46: goto tr868;
		case 59: goto tr1028;
		case 61: goto tr1029;
		case 68: goto tr1084;
		case 95: goto tr868;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr868;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr868;
	} else
		goto tr868;
	goto tr833;
tr1084:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st801;
st801:
	if ( ++p == pe )
		goto _test_eof801;
case 801:
#line 16528 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 46: goto tr868;
		case 59: goto tr1028;
		case 61: goto tr1086;
		case 95: goto tr868;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr868;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr868;
	} else
		goto tr868;
	goto tr1085;
tr1086:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st672;
st672:
	if ( ++p == pe )
		goto _test_eof672;
case 672:
#line 16557 "inc/vcf/validator_detail_v43.hpp"
	if ( 48 <= (*p) && (*p) <= 49 )
		goto tr963;
	goto tr962;
tr963:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st802;
st802:
	if ( ++p == pe )
		goto _test_eof802;
case 802:
#line 16571 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr1019;
		case 10: goto tr1020;
		case 13: goto tr1021;
		case 59: goto tr1028;
	}
	goto tr962;
tr832:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st673;
st673:
	if ( ++p == pe )
		goto _test_eof673;
case 673:
#line 16589 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 58 )
		goto tr826;
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr826;
		} else if ( (*p) > 57 ) {
			if ( 60 <= (*p) && (*p) <= 64 )
				goto tr826;
		} else
			goto tr828;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr826;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr826;
		} else
			goto tr828;
	} else
		goto tr828;
	goto tr825;
tr827:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st674;
st674:
	if ( ++p == pe )
		goto _test_eof674;
case 674:
#line 16627 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr831;
		case 58: goto st591;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto st591;
		} else if ( (*p) > 57 ) {
			if ( 60 <= (*p) && (*p) <= 64 )
				goto st591;
		} else
			goto tr830;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st591;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st591;
		} else
			goto tr830;
	} else
		goto tr830;
	goto tr825;
tr823:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st675;
st675:
	if ( ++p == pe )
		goto _test_eof675;
case 675:
#line 16663 "inc/vcf/validator_detail_v43.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr964;
	goto tr814;
tr964:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st676;
st676:
	if ( ++p == pe )
		goto _test_eof676;
case 676:
#line 16677 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr822;
		case 69: goto tr824;
		case 101: goto tr824;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr964;
	goto tr814;
tr824:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st677;
st677:
	if ( ++p == pe )
		goto _test_eof677;
case 677:
#line 16696 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr965;
		case 45: goto tr965;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr966;
	goto tr814;
tr965:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st678;
st678:
	if ( ++p == pe )
		goto _test_eof678;
case 678:
#line 16714 "inc/vcf/validator_detail_v43.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr966;
	goto tr814;
tr966:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st679;
st679:
	if ( ++p == pe )
		goto _test_eof679;
case 679:
#line 16728 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 9 )
		goto tr822;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr966;
	goto tr814;
tr818:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st680;
tr821:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st680;
st680:
	if ( ++p == pe )
		goto _test_eof680;
case 680:
#line 16754 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 110 )
		goto tr967;
	goto tr814;
tr967:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st681;
st681:
	if ( ++p == pe )
		goto _test_eof681;
case 681:
#line 16768 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 102 )
		goto tr968;
	goto tr814;
tr816:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st682;
tr968:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st682;
st682:
	if ( ++p == pe )
		goto _test_eof682;
case 682:
#line 16792 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 9 )
		goto tr822;
	goto tr814;
tr819:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st683;
st683:
	if ( ++p == pe )
		goto _test_eof683;
case 683:
#line 16810 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 97 )
		goto tr969;
	goto tr814;
tr969:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st684;
st684:
	if ( ++p == pe )
		goto _test_eof684;
case 684:
#line 16824 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 78 )
		goto tr968;
	goto tr814;
tr813:
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st685;
st685:
	if ( ++p == pe )
		goto _test_eof685;
case 685:
#line 16838 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 42: goto tr806;
		case 46: goto tr970;
		case 60: goto tr808;
		case 65: goto tr809;
		case 67: goto tr809;
		case 71: goto tr809;
		case 78: goto tr809;
		case 84: goto tr809;
		case 91: goto tr810;
		case 93: goto tr811;
		case 97: goto tr809;
		case 99: goto tr809;
		case 103: goto tr809;
		case 110: goto tr809;
		case 116: goto tr809;
	}
	goto tr805;
tr970:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st686;
tr994:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st686;
st686:
	if ( ++p == pe )
		goto _test_eof686;
case 686:
#line 16877 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 65: goto tr971;
		case 67: goto tr971;
		case 71: goto tr971;
		case 78: goto tr971;
		case 84: goto tr971;
		case 97: goto tr971;
		case 99: goto tr971;
		case 103: goto tr971;
		case 110: goto tr971;
		case 116: goto tr971;
	}
	goto tr805;
tr971:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st687;
st687:
	if ( ++p == pe )
		goto _test_eof687;
case 687:
#line 16901 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr812;
		case 44: goto tr813;
		case 65: goto tr971;
		case 67: goto tr971;
		case 71: goto tr971;
		case 78: goto tr971;
		case 84: goto tr971;
		case 97: goto tr971;
		case 99: goto tr971;
		case 103: goto tr971;
		case 110: goto tr971;
		case 116: goto tr971;
	}
	goto tr805;
tr808:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st688;
tr972:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st688;
st688:
	if ( ++p == pe )
		goto _test_eof688;
case 688:
#line 16937 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 61 )
		goto tr972;
	if ( (*p) < 63 ) {
		if ( (*p) < 45 ) {
			if ( 33 <= (*p) && (*p) <= 43 )
				goto tr972;
		} else if ( (*p) > 47 ) {
			if ( (*p) > 57 ) {
				if ( 58 <= (*p) && (*p) <= 59 )
					goto tr972;
			} else if ( (*p) >= 48 )
				goto tr973;
		} else
			goto tr972;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr973;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr972;
			} else if ( (*p) >= 97 )
				goto tr973;
		} else
			goto tr972;
	} else
		goto tr972;
	goto tr805;
tr973:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st689;
st689:
	if ( ++p == pe )
		goto _test_eof689;
case 689:
#line 16977 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 62 )
		goto tr974;
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 43 )
			goto tr973;
	} else if ( (*p) > 59 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr973;
	} else
		goto tr973;
	goto tr805;
tr809:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st690;
tr975:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st690;
st690:
	if ( ++p == pe )
		goto _test_eof690;
case 690:
#line 17009 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr812;
		case 44: goto tr813;
		case 46: goto tr974;
		case 65: goto tr975;
		case 67: goto tr975;
		case 71: goto tr975;
		case 78: goto tr975;
		case 84: goto tr975;
		case 91: goto tr976;
		case 93: goto tr977;
		case 97: goto tr975;
		case 99: goto tr975;
		case 103: goto tr975;
		case 110: goto tr975;
		case 116: goto tr975;
	}
	goto tr805;
tr976:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st691;
st691:
	if ( ++p == pe )
		goto _test_eof691;
case 691:
#line 17038 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr978;
		case 59: goto tr978;
		case 60: goto tr979;
		case 92: goto tr978;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr978;
		} else if ( (*p) >= 33 )
			goto tr978;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr978;
		} else if ( (*p) >= 63 )
			goto tr978;
	} else
		goto tr978;
	goto tr805;
tr978:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st692;
st692:
	if ( ++p == pe )
		goto _test_eof692;
case 692:
#line 17070 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr978;
		case 58: goto tr980;
		case 92: goto tr978;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr978;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr978;
		} else if ( (*p) >= 63 )
			goto tr978;
	} else
		goto tr978;
	goto tr805;
tr980:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st693;
st693:
	if ( ++p == pe )
		goto _test_eof693;
case 693:
#line 17098 "inc/vcf/validator_detail_v43.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr981;
	goto tr805;
tr981:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st694;
st694:
	if ( ++p == pe )
		goto _test_eof694;
case 694:
#line 17112 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 91 )
		goto tr974;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr981;
	goto tr805;
tr979:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st695;
st695:
	if ( ++p == pe )
		goto _test_eof695;
case 695:
#line 17128 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr982;
		case 59: goto tr982;
		case 92: goto tr982;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr982;
		} else if ( (*p) >= 33 )
			goto tr982;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr982;
		} else if ( (*p) >= 63 )
			goto tr982;
	} else
		goto tr982;
	goto tr805;
tr982:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st696;
st696:
	if ( ++p == pe )
		goto _test_eof696;
case 696:
#line 17159 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr982;
		case 59: goto tr982;
		case 62: goto tr983;
		case 92: goto tr982;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr982;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr982;
		} else if ( (*p) >= 63 )
			goto tr982;
	} else
		goto tr982;
	goto tr805;
tr983:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st697;
st697:
	if ( ++p == pe )
		goto _test_eof697;
case 697:
#line 17188 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 58 )
		goto tr980;
	goto tr805;
tr977:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st698;
st698:
	if ( ++p == pe )
		goto _test_eof698;
case 698:
#line 17202 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr984;
		case 59: goto tr984;
		case 60: goto tr985;
		case 92: goto tr984;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr984;
		} else if ( (*p) >= 33 )
			goto tr984;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr984;
		} else if ( (*p) >= 63 )
			goto tr984;
	} else
		goto tr984;
	goto tr805;
tr984:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st699;
st699:
	if ( ++p == pe )
		goto _test_eof699;
case 699:
#line 17234 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr984;
		case 58: goto tr986;
		case 92: goto tr984;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr984;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr984;
		} else if ( (*p) >= 63 )
			goto tr984;
	} else
		goto tr984;
	goto tr805;
tr986:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st700;
st700:
	if ( ++p == pe )
		goto _test_eof700;
case 700:
#line 17262 "inc/vcf/validator_detail_v43.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr987;
	goto tr805;
tr987:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st701;
st701:
	if ( ++p == pe )
		goto _test_eof701;
case 701:
#line 17276 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 93 )
		goto tr974;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr987;
	goto tr805;
tr985:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st702;
st702:
	if ( ++p == pe )
		goto _test_eof702;
case 702:
#line 17292 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr988;
		case 59: goto tr988;
		case 92: goto tr988;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr988;
		} else if ( (*p) >= 33 )
			goto tr988;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr988;
		} else if ( (*p) >= 63 )
			goto tr988;
	} else
		goto tr988;
	goto tr805;
tr988:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st703;
st703:
	if ( ++p == pe )
		goto _test_eof703;
case 703:
#line 17323 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr988;
		case 59: goto tr988;
		case 62: goto tr989;
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
	goto tr805;
tr989:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st704;
st704:
	if ( ++p == pe )
		goto _test_eof704;
case 704:
#line 17352 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 58 )
		goto tr986;
	goto tr805;
tr810:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st705;
st705:
	if ( ++p == pe )
		goto _test_eof705;
case 705:
#line 17370 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr990;
		case 59: goto tr990;
		case 60: goto tr991;
		case 92: goto tr990;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr990;
		} else if ( (*p) >= 33 )
			goto tr990;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr990;
		} else if ( (*p) >= 63 )
			goto tr990;
	} else
		goto tr990;
	goto tr805;
tr990:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st706;
st706:
	if ( ++p == pe )
		goto _test_eof706;
case 706:
#line 17402 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr990;
		case 58: goto tr992;
		case 92: goto tr990;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr990;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr990;
		} else if ( (*p) >= 63 )
			goto tr990;
	} else
		goto tr990;
	goto tr805;
tr992:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st707;
st707:
	if ( ++p == pe )
		goto _test_eof707;
case 707:
#line 17430 "inc/vcf/validator_detail_v43.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr993;
	goto tr805;
tr993:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st708;
st708:
	if ( ++p == pe )
		goto _test_eof708;
case 708:
#line 17444 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 91 )
		goto tr994;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr993;
	goto tr805;
tr991:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st709;
st709:
	if ( ++p == pe )
		goto _test_eof709;
case 709:
#line 17460 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr995;
		case 59: goto tr995;
		case 92: goto tr995;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr995;
		} else if ( (*p) >= 33 )
			goto tr995;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr995;
		} else if ( (*p) >= 63 )
			goto tr995;
	} else
		goto tr995;
	goto tr805;
tr995:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st710;
st710:
	if ( ++p == pe )
		goto _test_eof710;
case 710:
#line 17491 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr995;
		case 59: goto tr995;
		case 62: goto tr996;
		case 92: goto tr995;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr995;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr995;
		} else if ( (*p) >= 63 )
			goto tr995;
	} else
		goto tr995;
	goto tr805;
tr996:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st711;
st711:
	if ( ++p == pe )
		goto _test_eof711;
case 711:
#line 17520 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 58 )
		goto tr992;
	goto tr805;
tr811:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st712;
st712:
	if ( ++p == pe )
		goto _test_eof712;
case 712:
#line 17538 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr997;
		case 59: goto tr997;
		case 60: goto tr998;
		case 92: goto tr997;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr997;
		} else if ( (*p) >= 33 )
			goto tr997;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr997;
		} else if ( (*p) >= 63 )
			goto tr997;
	} else
		goto tr997;
	goto tr805;
tr997:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st713;
st713:
	if ( ++p == pe )
		goto _test_eof713;
case 713:
#line 17570 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr997;
		case 58: goto tr999;
		case 92: goto tr997;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr997;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr997;
		} else if ( (*p) >= 63 )
			goto tr997;
	} else
		goto tr997;
	goto tr805;
tr999:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st714;
st714:
	if ( ++p == pe )
		goto _test_eof714;
case 714:
#line 17598 "inc/vcf/validator_detail_v43.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr1000;
	goto tr805;
tr1000:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st715;
st715:
	if ( ++p == pe )
		goto _test_eof715;
case 715:
#line 17612 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 93 )
		goto tr994;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr1000;
	goto tr805;
tr998:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st716;
st716:
	if ( ++p == pe )
		goto _test_eof716;
case 716:
#line 17628 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr1001;
		case 59: goto tr1001;
		case 92: goto tr1001;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 41 )
				goto tr1001;
		} else if ( (*p) >= 33 )
			goto tr1001;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr1001;
		} else if ( (*p) >= 63 )
			goto tr1001;
	} else
		goto tr1001;
	goto tr805;
tr1001:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st717;
st717:
	if ( ++p == pe )
		goto _test_eof717;
case 717:
#line 17659 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 43: goto tr1001;
		case 59: goto tr1001;
		case 62: goto tr1002;
		case 92: goto tr1001;
	}
	if ( (*p) < 45 ) {
		if ( 33 <= (*p) && (*p) <= 41 )
			goto tr1001;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 126 )
				goto tr1001;
		} else if ( (*p) >= 63 )
			goto tr1001;
	} else
		goto tr1001;
	goto tr805;
tr1002:
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st718;
st718:
	if ( ++p == pe )
		goto _test_eof718;
case 718:
#line 17688 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 58 )
		goto tr999;
	goto tr805;
tr807:
#line 31 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st719;
st719:
	if ( ++p == pe )
		goto _test_eof719;
case 719:
#line 17706 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 9: goto tr812;
		case 65: goto tr971;
		case 67: goto tr971;
		case 71: goto tr971;
		case 78: goto tr971;
		case 84: goto tr971;
		case 97: goto tr971;
		case 99: goto tr971;
		case 103: goto tr971;
		case 110: goto tr971;
		case 116: goto tr971;
	}
	goto tr805;
tr773:
#line 180 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_header_line(*this);
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
	goto st720;
tr785:
#line 176 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_sample_name(*this);
    }
#line 180 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_header_line(*this);
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
	goto st720;
st720:
	if ( ++p == pe )
		goto _test_eof720;
case 720:
#line 17761 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 10 )
		goto st724;
	goto tr774;
tr23:
#line 99 "src/vcf/vcf.ragel"
	{
        try {
          ParsePolicy::handle_fileformat(*this);
        } catch (Error *error) {
          ErrorPolicy::handle_error(*this, error);
          p--; {goto st722;}
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
	goto st721;
st721:
	if ( ++p == pe )
		goto _test_eof721;
case 721:
#line 17790 "inc/vcf/validator_detail_v43.hpp"
	if ( (*p) == 10 )
		goto st22;
	goto tr0;
tr1007:
#line 43 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st722;
st722:
	if ( ++p == pe )
		goto _test_eof722;
case 722:
#line 17810 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 10: goto tr1006;
		case 13: goto tr1007;
	}
	goto st722;
tr1006:
#line 43 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
#line 369 "src/vcf/vcf_v43.ragel"
	{ {goto st28;} }
	goto st803;
st803:
	if ( ++p == pe )
		goto _test_eof803;
case 803:
#line 17834 "inc/vcf/validator_detail_v43.hpp"
	goto st0;
tr1010:
#line 43 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st723;
st723:
	if ( ++p == pe )
		goto _test_eof723;
case 723:
#line 17852 "inc/vcf/validator_detail_v43.hpp"
	switch( (*p) ) {
		case 10: goto tr1009;
		case 13: goto tr1010;
	}
	goto st723;
tr1009:
#line 43 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
#line 370 "src/vcf/vcf_v43.ragel"
	{ {goto st728;} }
	goto st804;
st804:
	if ( ++p == pe )
		goto _test_eof804;
case 804:
#line 17876 "inc/vcf/validator_detail_v43.hpp"
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
	_test_eof724: cs = 724; goto _test_eof; 
	_test_eof725: cs = 725; goto _test_eof; 
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
	_test_eof726: cs = 726; goto _test_eof; 
	_test_eof594: cs = 594; goto _test_eof; 
	_test_eof595: cs = 595; goto _test_eof; 
	_test_eof596: cs = 596; goto _test_eof; 
	_test_eof727: cs = 727; goto _test_eof; 
	_test_eof728: cs = 728; goto _test_eof; 
	_test_eof597: cs = 597; goto _test_eof; 
	_test_eof598: cs = 598; goto _test_eof; 
	_test_eof599: cs = 599; goto _test_eof; 
	_test_eof600: cs = 600; goto _test_eof; 
	_test_eof601: cs = 601; goto _test_eof; 
	_test_eof729: cs = 729; goto _test_eof; 
	_test_eof730: cs = 730; goto _test_eof; 
	_test_eof731: cs = 731; goto _test_eof; 
	_test_eof732: cs = 732; goto _test_eof; 
	_test_eof602: cs = 602; goto _test_eof; 
	_test_eof733: cs = 733; goto _test_eof; 
	_test_eof734: cs = 734; goto _test_eof; 
	_test_eof735: cs = 735; goto _test_eof; 
	_test_eof736: cs = 736; goto _test_eof; 
	_test_eof603: cs = 603; goto _test_eof; 
	_test_eof737: cs = 737; goto _test_eof; 
	_test_eof738: cs = 738; goto _test_eof; 
	_test_eof604: cs = 604; goto _test_eof; 
	_test_eof739: cs = 739; goto _test_eof; 
	_test_eof740: cs = 740; goto _test_eof; 
	_test_eof605: cs = 605; goto _test_eof; 
	_test_eof606: cs = 606; goto _test_eof; 
	_test_eof741: cs = 741; goto _test_eof; 
	_test_eof607: cs = 607; goto _test_eof; 
	_test_eof608: cs = 608; goto _test_eof; 
	_test_eof742: cs = 742; goto _test_eof; 
	_test_eof609: cs = 609; goto _test_eof; 
	_test_eof610: cs = 610; goto _test_eof; 
	_test_eof743: cs = 743; goto _test_eof; 
	_test_eof611: cs = 611; goto _test_eof; 
	_test_eof612: cs = 612; goto _test_eof; 
	_test_eof744: cs = 744; goto _test_eof; 
	_test_eof613: cs = 613; goto _test_eof; 
	_test_eof614: cs = 614; goto _test_eof; 
	_test_eof745: cs = 745; goto _test_eof; 
	_test_eof615: cs = 615; goto _test_eof; 
	_test_eof616: cs = 616; goto _test_eof; 
	_test_eof617: cs = 617; goto _test_eof; 
	_test_eof746: cs = 746; goto _test_eof; 
	_test_eof618: cs = 618; goto _test_eof; 
	_test_eof747: cs = 747; goto _test_eof; 
	_test_eof619: cs = 619; goto _test_eof; 
	_test_eof620: cs = 620; goto _test_eof; 
	_test_eof748: cs = 748; goto _test_eof; 
	_test_eof621: cs = 621; goto _test_eof; 
	_test_eof622: cs = 622; goto _test_eof; 
	_test_eof749: cs = 749; goto _test_eof; 
	_test_eof623: cs = 623; goto _test_eof; 
	_test_eof624: cs = 624; goto _test_eof; 
	_test_eof625: cs = 625; goto _test_eof; 
	_test_eof626: cs = 626; goto _test_eof; 
	_test_eof750: cs = 750; goto _test_eof; 
	_test_eof751: cs = 751; goto _test_eof; 
	_test_eof627: cs = 627; goto _test_eof; 
	_test_eof628: cs = 628; goto _test_eof; 
	_test_eof629: cs = 629; goto _test_eof; 
	_test_eof752: cs = 752; goto _test_eof; 
	_test_eof630: cs = 630; goto _test_eof; 
	_test_eof753: cs = 753; goto _test_eof; 
	_test_eof631: cs = 631; goto _test_eof; 
	_test_eof632: cs = 632; goto _test_eof; 
	_test_eof754: cs = 754; goto _test_eof; 
	_test_eof633: cs = 633; goto _test_eof; 
	_test_eof634: cs = 634; goto _test_eof; 
	_test_eof755: cs = 755; goto _test_eof; 
	_test_eof635: cs = 635; goto _test_eof; 
	_test_eof636: cs = 636; goto _test_eof; 
	_test_eof756: cs = 756; goto _test_eof; 
	_test_eof757: cs = 757; goto _test_eof; 
	_test_eof758: cs = 758; goto _test_eof; 
	_test_eof759: cs = 759; goto _test_eof; 
	_test_eof637: cs = 637; goto _test_eof; 
	_test_eof638: cs = 638; goto _test_eof; 
	_test_eof639: cs = 639; goto _test_eof; 
	_test_eof760: cs = 760; goto _test_eof; 
	_test_eof761: cs = 761; goto _test_eof; 
	_test_eof762: cs = 762; goto _test_eof; 
	_test_eof640: cs = 640; goto _test_eof; 
	_test_eof763: cs = 763; goto _test_eof; 
	_test_eof641: cs = 641; goto _test_eof; 
	_test_eof642: cs = 642; goto _test_eof; 
	_test_eof764: cs = 764; goto _test_eof; 
	_test_eof765: cs = 765; goto _test_eof; 
	_test_eof766: cs = 766; goto _test_eof; 
	_test_eof643: cs = 643; goto _test_eof; 
	_test_eof644: cs = 644; goto _test_eof; 
	_test_eof767: cs = 767; goto _test_eof; 
	_test_eof768: cs = 768; goto _test_eof; 
	_test_eof769: cs = 769; goto _test_eof; 
	_test_eof645: cs = 645; goto _test_eof; 
	_test_eof770: cs = 770; goto _test_eof; 
	_test_eof771: cs = 771; goto _test_eof; 
	_test_eof646: cs = 646; goto _test_eof; 
	_test_eof772: cs = 772; goto _test_eof; 
	_test_eof773: cs = 773; goto _test_eof; 
	_test_eof647: cs = 647; goto _test_eof; 
	_test_eof648: cs = 648; goto _test_eof; 
	_test_eof649: cs = 649; goto _test_eof; 
	_test_eof774: cs = 774; goto _test_eof; 
	_test_eof650: cs = 650; goto _test_eof; 
	_test_eof651: cs = 651; goto _test_eof; 
	_test_eof775: cs = 775; goto _test_eof; 
	_test_eof652: cs = 652; goto _test_eof; 
	_test_eof776: cs = 776; goto _test_eof; 
	_test_eof653: cs = 653; goto _test_eof; 
	_test_eof654: cs = 654; goto _test_eof; 
	_test_eof777: cs = 777; goto _test_eof; 
	_test_eof655: cs = 655; goto _test_eof; 
	_test_eof656: cs = 656; goto _test_eof; 
	_test_eof778: cs = 778; goto _test_eof; 
	_test_eof657: cs = 657; goto _test_eof; 
	_test_eof658: cs = 658; goto _test_eof; 
	_test_eof779: cs = 779; goto _test_eof; 
	_test_eof659: cs = 659; goto _test_eof; 
	_test_eof660: cs = 660; goto _test_eof; 
	_test_eof780: cs = 780; goto _test_eof; 
	_test_eof781: cs = 781; goto _test_eof; 
	_test_eof661: cs = 661; goto _test_eof; 
	_test_eof662: cs = 662; goto _test_eof; 
	_test_eof663: cs = 663; goto _test_eof; 
	_test_eof782: cs = 782; goto _test_eof; 
	_test_eof664: cs = 664; goto _test_eof; 
	_test_eof783: cs = 783; goto _test_eof; 
	_test_eof665: cs = 665; goto _test_eof; 
	_test_eof666: cs = 666; goto _test_eof; 
	_test_eof784: cs = 784; goto _test_eof; 
	_test_eof667: cs = 667; goto _test_eof; 
	_test_eof668: cs = 668; goto _test_eof; 
	_test_eof785: cs = 785; goto _test_eof; 
	_test_eof669: cs = 669; goto _test_eof; 
	_test_eof670: cs = 670; goto _test_eof; 
	_test_eof786: cs = 786; goto _test_eof; 
	_test_eof787: cs = 787; goto _test_eof; 
	_test_eof788: cs = 788; goto _test_eof; 
	_test_eof789: cs = 789; goto _test_eof; 
	_test_eof790: cs = 790; goto _test_eof; 
	_test_eof791: cs = 791; goto _test_eof; 
	_test_eof671: cs = 671; goto _test_eof; 
	_test_eof792: cs = 792; goto _test_eof; 
	_test_eof793: cs = 793; goto _test_eof; 
	_test_eof794: cs = 794; goto _test_eof; 
	_test_eof795: cs = 795; goto _test_eof; 
	_test_eof796: cs = 796; goto _test_eof; 
	_test_eof797: cs = 797; goto _test_eof; 
	_test_eof798: cs = 798; goto _test_eof; 
	_test_eof799: cs = 799; goto _test_eof; 
	_test_eof800: cs = 800; goto _test_eof; 
	_test_eof801: cs = 801; goto _test_eof; 
	_test_eof672: cs = 672; goto _test_eof; 
	_test_eof802: cs = 802; goto _test_eof; 
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
	_test_eof803: cs = 803; goto _test_eof; 
	_test_eof723: cs = 723; goto _test_eof; 
	_test_eof804: cs = 804; goto _test_eof; 

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
	case 721: 
#line 60 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new FileformatError{n_lines});
        p--; {goto st722;}
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
        p--; {goto st722;}
    }
	break;
	case 724: 
#line 70 "src/vcf/vcf.ragel"
	{
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (Error *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
    }
	break;
	case 720: 
#line 78 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new HeaderSectionError{n_lines});
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (Error *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
        
        p--; {goto st723;}
    }
	break;
	case 600: 
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
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
#line 219 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	break;
	case 441: 
	case 442: 
	case 443: 
	case 444: 
	case 445: 
	case 446: 
	case 447: 
	case 448: 
#line 231 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in assembly metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
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
#line 237 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in contig metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
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
#line 243 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
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
#line 249 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
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
#line 260 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	break;
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
	case 368: 
	case 369: 
	case 370: 
	case 371: 
	case 372: 
	case 373: 
	case 377: 
	case 378: 
	case 379: 
	case 380: 
	case 381: 
	case 382: 
	case 383: 
	case 387: 
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
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	break;
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
#line 277 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in pedigreeDB metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	break;
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
	case 435: 
	case 436: 
	case 437: 
	case 438: 
	case 439: 
	case 440: 
#line 283 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	break;
	case 578: 
	case 597: 
	case 598: 
	case 599: 
#line 322 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new ChromosomeBodyError{n_lines});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	break;
	case 579: 
	case 580: 
#line 328 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new PositionBodyError{n_lines});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	break;
	case 581: 
	case 582: 
#line 334 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new IdBodyError{n_lines});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	break;
	case 583: 
	case 584: 
#line 340 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new ReferenceAlleleBodyError{n_lines});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	break;
	case 585: 
	case 586: 
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
#line 346 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new AlternateAllelesBodyError{n_lines});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	break;
	case 587: 
	case 588: 
	case 589: 
	case 675: 
	case 676: 
	case 677: 
	case 678: 
	case 679: 
	case 680: 
	case 681: 
	case 682: 
	case 683: 
	case 684: 
#line 352 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new QualityBodyError{n_lines});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	break;
	case 590: 
	case 591: 
	case 592: 
	case 673: 
	case 674: 
#line 358 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new FilterBodyError{n_lines});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
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
#line 52 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this,
                new FileformatError{n_lines, "The fileformat declaration is not 'fileformat=VCFv4.3'"});
        p--; {goto st722;}
    }
#line 60 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new FileformatError{n_lines});
        p--; {goto st722;}
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
	case 317: 
	case 318: 
	case 319: 
	case 320: 
	case 321: 
	case 322: 
	case 323: 
	case 326: 
	case 327: 
	case 328: 
	case 329: 
	case 330: 
	case 338: 
	case 339: 
	case 340: 
	case 341: 
	case 342: 
	case 343: 
	case 344: 
	case 345: 
	case 346: 
	case 348: 
	case 349: 
	case 351: 
#line 87 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	break;
	case 594: 
	case 595: 
#line 135 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new FormatBodyError{n_lines, "Format does not start with a letter/underscore followed by alphanumeric/underscore/dot characters"});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	break;
	case 568: 
	case 569: 
	case 570: 
	case 571: 
	case 572: 
	case 573: 
	case 574: 
	case 575: 
	case 576: 
#line 140 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {goto st723;}
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
        
        p--; {goto st723;}
    }
	break;
	case 81: 
	case 82: 
	case 83: 
#line 224 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines,
            "ALT metadata ID is not prefixed by DEL/INS/DUP/INV/CNV and suffixed by ':' and a text sequence"});
        p--; {goto st722;}
    }
#line 219 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	break;
	case 122: 
#line 243 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {goto st722;}
    }
#line 249 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	break;
	case 199: 
	case 200: 
#line 265 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "INFO metadata Type is not Integer, Float, Flag, Character or String"});
        p--; {goto st722;}
    }
#line 249 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	break;
	case 265: 
	case 266: 
#line 265 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "INFO metadata Type is not Integer, Float, Flag, Character or String"});
        p--; {goto st722;}
    }
#line 260 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	break;
	case 100: 
	case 101: 
	case 102: 
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st722;}
    }
#line 219 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	break;
	case 478: 
	case 479: 
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st722;}
    }
#line 237 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in contig metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	break;
	case 132: 
	case 133: 
	case 134: 
	case 151: 
	case 152: 
	case 153: 
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st722;}
    }
#line 243 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	break;
	case 182: 
	case 183: 
	case 184: 
	case 217: 
	case 218: 
	case 219: 
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st722;}
    }
#line 249 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	break;
	case 248: 
	case 249: 
	case 250: 
	case 283: 
	case 284: 
	case 285: 
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st722;}
    }
#line 260 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	break;
	case 364: 
	case 365: 
	case 366: 
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st722;}
    }
#line 271 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	break;
	case 419: 
	case 420: 
	case 421: 
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st722;}
    }
#line 283 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	break;
	case 314: 
	case 315: 
	case 316: 
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st722;}
    }
#line 87 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
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
#line 294 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st722;}
    }
#line 219 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
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
#line 294 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st722;}
    }
#line 243 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
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
#line 294 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st722;}
    }
#line 249 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
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
#line 294 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st722;}
    }
#line 260 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	break;
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
	case 465: 
	case 466: 
	case 467: 
#line 299 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata URL is not valid"});
        p--; {goto st722;}
    }
#line 231 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in assembly metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	break;
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
#line 299 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata URL is not valid"});
        p--; {goto st722;}
    }
#line 277 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in pedigreeDB metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	break;
	case 192: 
	case 193: 
	case 239: 
#line 59 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "FORMAT metadata Number is not a number, A, R, G or dot"});
        p--; {goto st722;}
    }
#line 249 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	break;
	case 258: 
	case 259: 
	case 305: 
#line 65 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "INFO metadata Number is not a number, A, R, G or dot"});
        p--; {goto st722;}
    }
#line 260 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	break;
	case 406: 
	case 407: 
	case 408: 
#line 71 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "PEDIGREE metadata Original is not valid"});
        p--; {goto st722;}
    }
#line 271 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	break;
	case 374: 
	case 375: 
	case 376: 
	case 384: 
	case 385: 
	case 386: 
#line 76 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "PEDIGREE metadata Father or Mother is not valid"});
        p--; {goto st722;}
    }
#line 271 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	break;
	case 367: 
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
#line 81 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "PEDIGREE metadata sequence of Name_N is not valid"});
        p--; {goto st722;}
    }
#line 271 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	break;
	case 324: 
	case 325: 
#line 92 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "META metadata Number is not a dot"});
        p--; {goto st722;}
    }
#line 87 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	break;
	case 331: 
	case 332: 
	case 333: 
	case 334: 
	case 335: 
	case 336: 
	case 337: 
#line 97 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "META metadata Type is not String"});
        p--; {goto st722;}
    }
#line 87 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	break;
	case 347: 
	case 350: 
#line 102 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "META metadata Values is not a square-bracket delimited list of values"});
        p--; {goto st722;}
    }
#line 87 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	break;
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
	case 567: 
#line 140 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {goto st723;}
    }
#line 305 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new HeaderSectionError{n_lines,
            "The header line does not start with the mandatory columns: CHROM, POS, ID, REF, ALT, QUAL, FILTER and INFO"});
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (Error *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
        
        p--; {goto st723;}
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
        
        p--; {goto st723;}
    }
	break;
	case 601: 
#line 140 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {goto st723;}
    }
#line 524 "src/vcf/vcf.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " is not a valid string";
        ErrorPolicy::handle_error(*this, new SamplesBodyError{n_lines, message_stream.str()});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	break;
	case 726: 
	case 727: 
	case 732: 
	case 733: 
	case 734: 
	case 735: 
	case 736: 
	case 737: 
	case 738: 
	case 739: 
	case 740: 
	case 741: 
	case 742: 
	case 743: 
	case 744: 
	case 745: 
	case 746: 
	case 747: 
	case 748: 
	case 749: 
	case 750: 
	case 751: 
	case 752: 
	case 753: 
	case 754: 
	case 755: 
	case 756: 
	case 757: 
	case 758: 
	case 759: 
	case 760: 
	case 761: 
	case 762: 
	case 763: 
	case 764: 
	case 765: 
	case 766: 
	case 767: 
	case 768: 
	case 769: 
	case 770: 
	case 771: 
	case 772: 
	case 773: 
	case 774: 
	case 775: 
	case 776: 
	case 777: 
	case 778: 
	case 779: 
	case 780: 
	case 781: 
	case 782: 
	case 783: 
	case 784: 
	case 785: 
	case 786: 
	case 787: 
	case 788: 
	case 789: 
	case 790: 
	case 791: 
	case 792: 
	case 793: 
	case 794: 
	case 795: 
	case 796: 
	case 797: 
	case 798: 
	case 799: 
	case 800: 
	case 801: 
	case 802: 
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 186 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 140 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {goto st723;}
    }
#line 190 "src/vcf/vcf.ragel"
	{
        try {
            // Handle all columns and build record
            ParsePolicy::handle_body_line(*this);

            if (record != nullptr) {
                auto duplicated_errors = previous_records.check_duplicates(*record);
                for(auto &error_ptr : duplicated_errors) {
                    ErrorPolicy::handle_error(*this, error_ptr.release());
                }
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
        p--; {goto st722;}
    }
#line 140 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {goto st723;}
    }
#line 305 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new HeaderSectionError{n_lines,
            "The header line does not start with the mandatory columns: CHROM, POS, ID, REF, ALT, QUAL, FILTER and INFO"});
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (Error *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
        
        p--; {goto st723;}
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
        
        p--; {goto st723;}
    }
	break;
	case 108: 
	case 109: 
	case 110: 
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st722;}
    }
#line 294 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st722;}
    }
#line 219 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	break;
	case 159: 
	case 160: 
	case 161: 
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st722;}
    }
#line 294 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st722;}
    }
#line 243 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	break;
	case 225: 
	case 226: 
	case 227: 
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st722;}
    }
#line 294 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st722;}
    }
#line 249 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	break;
	case 291: 
	case 292: 
	case 293: 
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st722;}
    }
#line 294 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st722;}
    }
#line 260 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	break;
	case 117: 
	case 118: 
	case 119: 
#line 294 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st722;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st722;}
    }
#line 219 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	break;
	case 168: 
	case 169: 
	case 170: 
#line 294 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st722;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st722;}
    }
#line 243 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	break;
	case 234: 
	case 235: 
	case 236: 
#line 294 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st722;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st722;}
    }
#line 249 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	break;
	case 300: 
	case 301: 
	case 302: 
#line 294 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata description string is not valid"});
        p--; {goto st722;}
    }
#line 289 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash"});
        p--; {goto st722;}
    }
#line 260 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	break;
	case 593: 
	case 602: 
	case 605: 
	case 607: 
	case 609: 
	case 611: 
	case 613: 
	case 615: 
	case 625: 
	case 627: 
	case 637: 
	case 641: 
	case 643: 
	case 647: 
	case 648: 
	case 659: 
	case 661: 
#line 369 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info key is not a sequence of alphanumeric and/or punctuation characters"});
        p--; {goto st723;}
    }
#line 140 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {goto st723;}
    }
#line 364 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	break;
	case 603: 
#line 374 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info field value is not a comma-separated list of valid strings (maybe it contains whitespaces?)"});
        p--; {goto st723;}
    }
#line 140 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {goto st723;}
    }
#line 364 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	break;
	case 606: 
#line 379 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{
                n_lines,
                "Info AA value is not a single dot or a string of bases",
                "AA"});
        p--; {goto st723;}
    }
#line 140 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {goto st723;}
    }
#line 364 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	break;
	case 608: 
#line 387 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{
                n_lines,
                "Info AC value is not a comma-separated list of numbers",
                "AC"});
        p--; {goto st723;}
    }
#line 140 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {goto st723;}
    }
#line 364 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	break;
	case 616: 
	case 617: 
	case 618: 
	case 619: 
	case 620: 
	case 621: 
	case 622: 
	case 623: 
	case 624: 
#line 395 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{
                n_lines,
                "Info AF value is not a comma-separated list of numbers",
                "AF"});
        p--; {goto st723;}
    }
#line 140 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {goto st723;}
    }
#line 364 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	break;
	case 626: 
#line 403 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{
                n_lines,
                "Info AN value is not an integer number",
                "AN"});
        p--; {goto st723;}
    }
#line 140 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {goto st723;}
    }
#line 364 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	break;
	case 628: 
	case 629: 
	case 630: 
	case 631: 
	case 632: 
	case 633: 
	case 634: 
	case 635: 
	case 636: 
#line 411 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{
                n_lines,
                "Info BQ value is not a number",
                "BQ"});
        p--; {goto st723;}
    }
#line 140 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {goto st723;}
    }
#line 364 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	break;
	case 638: 
	case 639: 
#line 419 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{
                n_lines,
                "Info CIGAR value is not an alphanumeric string compliant with the SAM specification",
                "CIGAR"});
        p--; {goto st723;}
    }
#line 140 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {goto st723;}
    }
#line 364 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	break;
	case 640: 
#line 427 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{
                n_lines,
                "Info DB is not a flag (with 1/0/no value)",
                "DB"});
        p--; {goto st723;}
    }
#line 140 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {goto st723;}
    }
#line 364 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	break;
	case 642: 
#line 435 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{
                n_lines,
                "Info DP value is not an integer number",
                "DP"});
        p--; {goto st723;}
    }
#line 140 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {goto st723;}
    }
#line 364 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	break;
	case 644: 
#line 443 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{
                n_lines,
                "Info END value is not an integer number",
                "END"});
        p--; {goto st723;}
    }
#line 140 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {goto st723;}
    }
#line 364 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	break;
	case 645: 
#line 451 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{
                n_lines,
                "Info H2 is not a flag (with 1/0/no value)",
                "H2"});
        p--; {goto st723;}
    }
#line 140 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {goto st723;}
    }
#line 364 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	break;
	case 646: 
#line 459 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{
                n_lines,
                "Info H3 is not a flag (with 1/0/no value)",
                "H3"});
        p--; {goto st723;}
    }
#line 140 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {goto st723;}
    }
#line 364 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	break;
	case 650: 
	case 651: 
	case 652: 
	case 653: 
	case 654: 
	case 655: 
	case 656: 
	case 657: 
	case 658: 
#line 467 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{
                n_lines,
                "Info MQ value is not a number",
                "MQ"});
        p--; {goto st723;}
    }
#line 140 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {goto st723;}
    }
#line 364 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	break;
	case 649: 
#line 475 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{
                n_lines,
                "Info MQ0 value is not an integer number",
                "MQ0"});
        p--; {goto st723;}
    }
#line 140 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {goto st723;}
    }
#line 364 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	break;
	case 660: 
#line 483 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{
                n_lines,
                "Info NS value is not an integer number",
                "NS"});
        p--; {goto st723;}
    }
#line 140 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {goto st723;}
    }
#line 364 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	break;
	case 662: 
	case 663: 
	case 664: 
	case 665: 
	case 666: 
	case 667: 
	case 668: 
	case 669: 
	case 670: 
#line 491 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{
                n_lines,
                "Info SB value is not a number",
                "SB"});
        p--; {goto st723;}
    }
#line 140 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {goto st723;}
    }
#line 364 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	break;
	case 671: 
#line 499 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{
                n_lines,
                "Info SOMATIC is not a flag (with 1/0/no value)",
                "SOMATIC"});
        p--; {goto st723;}
    }
#line 140 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {goto st723;}
    }
#line 364 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	break;
	case 672: 
#line 507 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{
                n_lines,
                "Info VALIDATED is not a flag (with 1/0/no value)",
                "VALIDATED"});
        p--; {goto st723;}
    }
#line 140 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {goto st723;}
    }
#line 364 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	break;
	case 604: 
#line 515 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{
                n_lines,
                "Info 1000G is not a flag (with 1/0/no value)",
                "1000G"});
        p--; {goto st723;}
    }
#line 140 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {goto st723;}
    }
#line 364 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	break;
	case 610: 
#line 110 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{
                n_lines,
                "Info AD value is not a comma-separated list of numbers",
                "AD"});
        p--; {goto st723;}
    }
#line 140 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {goto st723;}
    }
#line 364 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	break;
	case 612: 
#line 118 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{
                n_lines,
                "Info ADF value is not a comma-separated list of numbers",
                "ADF"});
        p--; {goto st723;}
    }
#line 140 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {goto st723;}
    }
#line 364 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	break;
	case 614: 
#line 126 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{
                n_lines,
                "Info ADR value is not a comma-separated list of numbers",
                "ADR"});
        p--; {goto st723;}
    }
#line 140 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {goto st723;}
    }
#line 364 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new InfoBodyError{n_lines, "Info is not a single dot or a semicolon-separated list of key-value pairs"});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	break;
	case 729: 
	case 730: 
	case 731: 
#line 140 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {goto st723;}
    }
#line 39 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 186 "src/vcf/vcf.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 190 "src/vcf/vcf.ragel"
	{
        try {
            // Handle all columns and build record
            ParsePolicy::handle_body_line(*this);

            if (record != nullptr) {
                auto duplicated_errors = previous_records.check_duplicates(*record);
                for(auto &error_ptr : duplicated_errors) {
                    ErrorPolicy::handle_error(*this, error_ptr.release());
                }
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
	case 596: 
#line 140 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {goto st723;}
    }
#line 531 "src/vcf/vcf.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " does not start with a valid genotype";
        ErrorPolicy::handle_error(*this, new SamplesFieldBodyError{n_lines, message_stream.str(), "GT"});
        p--; {goto st723;}
    }
#line 524 "src/vcf/vcf.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " is not a valid string";
        ErrorPolicy::handle_error(*this, new SamplesBodyError{n_lines, message_stream.str()});
        p--; {goto st723;}
    }
#line 91 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines});
        p--; {goto st723;}
    }
	break;
	case 22: 
#line 60 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new FileformatError{n_lines});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
#line 140 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new BodySectionError{n_lines, "There is no newline at the end of the file"});
        p--; {goto st723;}
    }
#line 305 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new HeaderSectionError{n_lines,
            "The header line does not start with the mandatory columns: CHROM, POS, ID, REF, ALT, QUAL, FILTER and INFO"});
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (Error *warn) {
          ErrorPolicy::handle_warning(*this, warn);
        }
        
        p--; {goto st723;}
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
        
        p--; {goto st723;}
    }
	break;
	case 24: 
#line 219 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in ALT metadata"});
        p--; {goto st722;}
    }
#line 243 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FILTER metadata"});
        p--; {goto st722;}
    }
#line 249 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in FORMAT metadata"});
        p--; {goto st722;}
    }
#line 260 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in INFO metadata"});
        p--; {goto st722;}
    }
#line 231 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in assembly metadata"});
        p--; {goto st722;}
    }
#line 237 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in contig metadata"});
        p--; {goto st722;}
    }
#line 87 "src/vcf/vcf_v43.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in META metadata"});
        p--; {goto st722;}
    }
#line 283 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in SAMPLE metadata"});
        p--; {goto st722;}
    }
#line 271 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in PEDIGREE metadata"});
        p--; {goto st722;}
    }
#line 277 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines, "Error in pedigreeDB metadata"});
        p--; {goto st722;}
    }
#line 65 "src/vcf/vcf.ragel"
	{
        ErrorPolicy::handle_error(*this, new MetaSectionError{n_lines});
        p--; {goto st722;}
    }
	break;
#line 21176 "inc/vcf/validator_detail_v43.hpp"
	}
	}

	_out: {}
	}

#line 399 "src/vcf/vcf_v43.ragel"

    }
    
  }
}
