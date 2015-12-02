
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


#line 743 "src/vcf/vcf_v41.ragel"


namespace
{
  
#line 31 "inc/vcf/validator_detail.hpp"
static const int vcf_start = 1;
static const int vcf_first_final = 704;
static const int vcf_error = 0;

static const int vcf_en_main = 1;
static const int vcf_en_main_meta_section = 22;
static const int vcf_en_main_body_section = 705;
static const int vcf_en_meta_section_skip = 702;
static const int vcf_en_body_section_skip = 703;


#line 749 "src/vcf/vcf_v41.ragel"

}

namespace ebi
{
  namespace vcf
  {
    template <typename Configuration>
    ParserImpl_v42<Configuration>::ParserImpl_v42(std::shared_ptr<Source> const & source,
                                          std::shared_ptr<std::vector<Record>> const & records
    )
    : ParsingState{source, records}
    {
      
#line 58 "inc/vcf/validator_detail.hpp"
	{
	cs = vcf_start;
	}

#line 764 "src/vcf/vcf_v41.ragel"

    }

    template <typename Configuration>
    void ParserImpl_v42<Configuration>::parse(std::vector<char> const & text)
    {
      char const * p = &text[0];
      char const * pe = &text[0] + text.size();
      char const * eof = nullptr;

      clear_records();
      parse_buffer(p, pe, eof);
    }

    template <typename Configuration>
    void ParserImpl_v42<Configuration>::parse(std::string const & text)
    {
      char const * p = text.data();
      char const * pe = text.data() + text.size();
      char const * eof = nullptr;

      clear_records();
      parse_buffer(p, pe, eof);
    }

    template <typename Configuration>
    void ParserImpl_v42<Configuration>::end()
    {
      char const * empty = "";
      clear_records();
      parse_buffer(empty, empty, empty);
    }

    template <typename Configuration>
    bool ParserImpl_v42<Configuration>::is_valid() const
    {
      return m_is_valid;
    }

    template <typename Configuration>
    void ParserImpl_v42<Configuration>::parse_buffer(char const * p, char const * pe, char const * eof)
    {
      
#line 107 "inc/vcf/validator_detail.hpp"
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
        p--; {goto st702;}
    }
	goto st0;
tr14:
#line 210 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this,
            "Fileformat is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st702;}
    }
#line 60 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this);
        p--; {goto st702;}
    }
	goto st0;
tr18:
#line 60 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this);
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
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
        
        p--; {goto st703;}
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
        
        p--; {goto st703;}
    }
	goto st0;
tr20:
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
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
        
        p--; {goto st703;}
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
        
        p--; {goto st703;}
    }
	goto st0;
tr23:
#line 217 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st702;}
    }
#line 240 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st702;}
    }
#line 246 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st702;}
    }
#line 262 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st702;}
    }
#line 228 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in assembly metadata");
        p--; {goto st702;}
    }
#line 234 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in contig metadata");
        p--; {goto st702;}
    }
#line 290 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st702;}
    }
#line 278 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in PEDIGREE metadata");
        p--; {goto st702;}
    }
#line 284 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in pedigreeDB metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	goto st0;
tr33:
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	goto st0;
tr116:
#line 217 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	goto st0;
tr124:
#line 222 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "ALT metadata ID is not prefixed by DEL/INS/DUP/INV/CNV and suffixed by ':' and a text sequence");
        p--; {goto st702;}
    }
#line 217 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	goto st0;
tr142:
#line 311 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st702;}
    }
#line 217 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	goto st0;
tr151:
#line 306 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st702;}
    }
#line 217 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	goto st0;
tr165:
#line 306 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st702;}
    }
#line 311 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st702;}
    }
#line 217 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	goto st0;
tr177:
#line 311 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st702;}
    }
#line 306 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st702;}
    }
#line 217 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	goto st0;
tr184:
#line 240 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st702;}
    }
#line 246 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	goto st0;
tr187:
#line 240 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	goto st0;
tr197:
#line 306 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st702;}
    }
#line 240 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	goto st0;
tr216:
#line 311 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st702;}
    }
#line 240 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	goto st0;
tr238:
#line 306 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st702;}
    }
#line 311 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st702;}
    }
#line 240 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	goto st0;
tr250:
#line 311 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st702;}
    }
#line 306 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st702;}
    }
#line 240 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	goto st0;
tr256:
#line 246 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	goto st0;
tr266:
#line 306 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st702;}
    }
#line 246 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	goto st0;
tr279:
#line 251 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "FORMAT metadata Number is not a number, A, R, G or dot");
        p--; {goto st702;}
    }
#line 246 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	goto st0;
tr288:
#line 272 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "INFO metadata Type is not a Integer, Float, Flag, Character or String");
        p--; {goto st702;}
    }
#line 246 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	goto st0;
tr305:
#line 311 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st702;}
    }
#line 246 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	goto st0;
tr327:
#line 306 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st702;}
    }
#line 311 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st702;}
    }
#line 246 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	goto st0;
tr339:
#line 311 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st702;}
    }
#line 306 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st702;}
    }
#line 246 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	goto st0;
tr346:
#line 262 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	goto st0;
tr355:
#line 306 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st702;}
    }
#line 262 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	goto st0;
tr368:
#line 267 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "INFO metadata Number is not a number, A, R, G or dot");
        p--; {goto st702;}
    }
#line 262 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	goto st0;
tr377:
#line 272 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "INFO metadata Type is not a Integer, Float, Flag, Character or String");
        p--; {goto st702;}
    }
#line 262 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	goto st0;
tr394:
#line 311 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st702;}
    }
#line 262 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	goto st0;
tr416:
#line 306 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st702;}
    }
#line 311 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st702;}
    }
#line 262 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	goto st0;
tr428:
#line 311 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st702;}
    }
#line 306 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st702;}
    }
#line 262 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	goto st0;
tr435:
#line 278 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in PEDIGREE metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	goto st0;
tr445:
#line 306 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st702;}
    }
#line 278 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in PEDIGREE metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	goto st0;
tr457:
#line 290 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	goto st0;
tr468:
#line 306 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st702;}
    }
#line 290 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	goto st0;
tr473:
#line 306 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st702;}
    }
#line 295 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Genomes is not a valid string (maybe it contains quotes?)");
        p--; {goto st702;}
    }
#line 290 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	goto st0;
tr475:
#line 295 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Genomes is not a valid string (maybe it contains quotes?)");
        p--; {goto st702;}
    }
#line 290 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	goto st0;
tr485:
#line 295 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Genomes is not a valid string (maybe it contains quotes?)");
        p--; {goto st702;}
    }
#line 300 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Mixture is not a valid string (maybe it contains quotes?)");
        p--; {goto st702;}
    }
#line 290 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	goto st0;
tr488:
#line 300 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Mixture is not a valid string (maybe it contains quotes?)");
        p--; {goto st702;}
    }
#line 290 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	goto st0;
tr498:
#line 300 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Mixture is not a valid string (maybe it contains quotes?)");
        p--; {goto st702;}
    }
#line 311 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st702;}
    }
#line 290 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	goto st0;
tr501:
#line 311 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st702;}
    }
#line 290 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	goto st0;
tr524:
#line 228 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in assembly metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	goto st0;
tr533:
#line 316 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata URL is not valid");
        p--; {goto st702;}
    }
#line 228 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in assembly metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	goto st0;
tr540:
#line 234 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in contig metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	goto st0;
tr551:
#line 306 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st702;}
    }
#line 234 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in contig metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	goto st0;
tr590:
#line 284 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in pedigreeDB metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	goto st0;
tr602:
#line 316 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata URL is not valid");
        p--; {goto st702;}
    }
#line 284 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in pedigreeDB metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	goto st0;
tr610:
#line 322 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this, "The header line does not start with the mandatory columns: CHROM, POS, ID, REF, ALT, QUAL, FILTER and INFO");
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (ParsingWarning warn) {
          ErrorPolicy::handle_meta_section_warning(*this, warn.what());
        }
        
        p--; {goto st703;}
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
        
        p--; {goto st703;}
    }
	goto st0;
tr649:
#line 78 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (ParsingWarning warn) {
          ErrorPolicy::handle_meta_section_warning(*this, warn.what());
        }
        
        p--; {goto st703;}
    }
	goto st0;
tr661:
#line 338 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Chromosome is not a string without colons or whitespaces, optionally wrapped with angle brackets (<>)");
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	goto st0;
tr665:
#line 344 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Position is not a positive number");
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	goto st0;
tr670:
#line 350 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "ID is not a single dot or a list of strings without semicolons or whitespaces");
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	goto st0;
tr675:
#line 356 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Reference is not a string of bases");
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	goto st0;
tr679:
#line 362 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Alternate is not a single dot or a comma-separated list of bases");
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	goto st0;
tr688:
#line 368 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Quality is not a single dot or a positive number");
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	goto st0;
tr698:
#line 374 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Filter is not a single dot or a semicolon-separated list of strings");
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	goto st0;
tr706:
#line 385 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st703;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	goto st0;
tr727:
#line 486 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Format is not a colon-separated list of alphanumeric strings");
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	goto st0;
tr732:
#line 499 "src/vcf/vcf_v41.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " does not start with a valid genotype";
        ErrorPolicy::handle_body_section_error(*this, message_stream.str());
        p--; {goto st703;}
    }
#line 492 "src/vcf/vcf_v41.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " is not a valid string";
        ErrorPolicy::handle_body_section_error(*this, message_stream.str());
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	goto st0;
tr744:
#line 492 "src/vcf/vcf_v41.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " is not a valid string";
        ErrorPolicy::handle_body_section_error(*this, message_stream.str());
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	goto st0;
tr750:
#line 390 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info field value is not a comma-separated list of valid strings (maybe it contains whitespaces?)");
        p--; {goto st703;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	goto st0;
tr752:
#line 480 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info 1000G is not a flag (with 1/0/no value)");
        p--; {goto st703;}
    }
#line 385 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st703;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	goto st0;
tr754:
#line 480 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info 1000G is not a flag (with 1/0/no value)");
        p--; {goto st703;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	goto st0;
tr761:
#line 395 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info AA value is not a single dot or a string of bases");
        p--; {goto st703;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	goto st0;
tr765:
#line 400 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info AC value is not a comma-separated list of numbers");
        p--; {goto st703;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	goto st0;
tr769:
#line 405 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info AF value is not a comma-separated list of numbers");
        p--; {goto st703;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	goto st0;
tr779:
#line 410 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info AN value is not an integer number");
        p--; {goto st703;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	goto st0;
tr784:
#line 415 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info BQ value is not a number");
        p--; {goto st703;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	goto st0;
tr798:
#line 420 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info CIGAR value is not an alphanumeric string");
        p--; {goto st703;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	goto st0;
tr802:
#line 425 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info DB is not a flag (with 1/0/no value)");
        p--; {goto st703;}
    }
#line 385 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st703;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	goto st0;
tr804:
#line 425 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info DB is not a flag (with 1/0/no value)");
        p--; {goto st703;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	goto st0;
tr807:
#line 430 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info DP value is not an integer number");
        p--; {goto st703;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	goto st0;
tr813:
#line 435 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info END value is not an integer number");
        p--; {goto st703;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	goto st0;
tr818:
#line 440 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info H2 is not a flag (with 1/0/no value)");
        p--; {goto st703;}
    }
#line 385 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st703;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	goto st0;
tr820:
#line 440 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info H2 is not a flag (with 1/0/no value)");
        p--; {goto st703;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	goto st0;
tr822:
#line 445 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info H3 is not a flag (with 1/0/no value)");
        p--; {goto st703;}
    }
#line 385 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st703;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	goto st0;
tr824:
#line 445 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info H3 is not a flag (with 1/0/no value)");
        p--; {goto st703;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	goto st0;
tr830:
#line 455 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info MQ0 value is not an integer number");
        p--; {goto st703;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	goto st0;
tr833:
#line 450 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info MQ value is not a number");
        p--; {goto st703;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	goto st0;
tr844:
#line 460 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info NS value is not an integer number");
        p--; {goto st703;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	goto st0;
tr850:
#line 465 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info SB value is not a number");
        p--; {goto st703;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	goto st0;
tr864:
#line 470 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info SOMATIC is not a flag (with 1/0/no value)");
        p--; {goto st703;}
    }
#line 385 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st703;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	goto st0;
tr866:
#line 470 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info SOMATIC is not a flag (with 1/0/no value)");
        p--; {goto st703;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	goto st0;
tr876:
#line 475 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info VALIDATED is not a flag (with 1/0/no value)");
        p--; {goto st703;}
    }
#line 385 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st703;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	goto st0;
tr878:
#line 475 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info VALIDATED is not a flag (with 1/0/no value)");
        p--; {goto st703;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	goto st0;
tr940:
#line 78 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (ParsingWarning warn) {
          ErrorPolicy::handle_meta_section_warning(*this, warn.what());
        }
        
        p--; {goto st703;}
    }
#line 338 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Chromosome is not a string without colons or whitespaces, optionally wrapped with angle brackets (<>)");
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	goto st0;
#line 1662 "inc/vcf/validator_detail.hpp"
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
	if ( 33 <= (*p) && (*p) <= 126 )
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
tr17:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st15;
st15:
	if ( ++p == pe )
		goto _test_eof15;
case 15:
#line 1777 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 10 )
		goto tr16;
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr17;
	goto tr14;
tr16:
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
	goto st16;
st16:
	if ( ++p == pe )
		goto _test_eof16;
case 16:
#line 1803 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 35 )
		goto st17;
	goto tr18;
st17:
	if ( ++p == pe )
		goto _test_eof17;
case 17:
	switch( (*p) ) {
		case 35: goto st18;
		case 67: goto st435;
	}
	goto tr20;
st18:
	if ( ++p == pe )
		goto _test_eof18;
case 18:
	switch( (*p) ) {
		case 65: goto tr25;
		case 70: goto tr26;
		case 73: goto tr27;
		case 80: goto tr28;
		case 83: goto tr29;
		case 97: goto tr30;
		case 99: goto tr31;
		case 112: goto tr32;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto tr24;
	} else if ( (*p) >= 32 )
		goto tr24;
	goto tr23;
tr24:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st19;
tr34:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st19;
st19:
	if ( ++p == pe )
		goto _test_eof19;
case 19:
#line 1856 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 61 )
		goto tr35;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr34;
	goto tr33;
tr35:
#line 163 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this);
    }
	goto st20;
st20:
	if ( ++p == pe )
		goto _test_eof20;
case 20:
#line 1872 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto st23;
		case 60: goto st28;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr36;
	goto tr33;
tr36:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st21;
tr40:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st21;
st21:
	if ( ++p == pe )
		goto _test_eof21;
case 21:
#line 1900 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 10 )
		goto tr39;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr40;
	goto tr33;
tr39:
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
	goto st22;
tr47:
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
	goto st22;
st22:
	if ( ++p == pe )
		goto _test_eof22;
case 22:
#line 1954 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 35 )
		goto st17;
	goto tr20;
st23:
	if ( ++p == pe )
		goto _test_eof23;
case 23:
	switch( (*p) ) {
		case 34: goto tr42;
		case 92: goto tr43;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr33;
tr41:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st24;
tr44:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st24;
st24:
	if ( ++p == pe )
		goto _test_eof24;
case 24:
#line 1989 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr45;
		case 92: goto tr46;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr44;
	goto tr33;
tr42:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st25;
tr45:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st25;
st25:
	if ( ++p == pe )
		goto _test_eof25;
case 25:
#line 2017 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 10 )
		goto tr47;
	goto tr33;
tr43:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st26;
tr46:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st26;
st26:
	if ( ++p == pe )
		goto _test_eof26;
case 26:
#line 2041 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr48;
		case 92: goto tr46;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr44;
	goto tr33;
tr48:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st27;
st27:
	if ( ++p == pe )
		goto _test_eof27;
case 27:
#line 2063 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr47;
		case 34: goto tr45;
		case 92: goto tr46;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr44;
	goto tr33;
st28:
	if ( ++p == pe )
		goto _test_eof28;
case 28:
	switch( (*p) ) {
		case 34: goto st29;
		case 95: goto tr50;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr50;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr51;
		} else if ( (*p) >= 65 )
			goto tr51;
	} else
		goto tr51;
	goto tr33;
st29:
	if ( ++p == pe )
		goto _test_eof29;
case 29:
	switch( (*p) ) {
		case 34: goto tr53;
		case 92: goto tr54;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr52;
	goto tr33;
tr52:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st30;
tr55:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st30;
st30:
	if ( ++p == pe )
		goto _test_eof30;
case 30:
#line 2123 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr56;
		case 92: goto tr57;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr55;
	goto tr33;
tr53:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st31;
tr56:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st31;
st31:
	if ( ++p == pe )
		goto _test_eof31;
case 31:
#line 2151 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 62 )
		goto st25;
	goto tr33;
tr54:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st32;
tr57:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st32;
st32:
	if ( ++p == pe )
		goto _test_eof32;
case 32:
#line 2175 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr59;
		case 92: goto tr57;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr55;
	goto tr33;
tr59:
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
#line 2197 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr56;
		case 62: goto tr60;
		case 92: goto tr57;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr55;
	goto tr33;
tr60:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st34;
st34:
	if ( ++p == pe )
		goto _test_eof34;
case 34:
#line 2216 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr47;
		case 34: goto tr56;
		case 92: goto tr57;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr55;
	goto tr33;
tr50:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st35;
st35:
	if ( ++p == pe )
		goto _test_eof35;
case 35:
#line 2235 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 95 )
		goto st35;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st35;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr62;
		} else if ( (*p) >= 65 )
			goto tr62;
	} else
		goto tr62;
	goto tr33;
tr51:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st36;
tr62:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st36;
st36:
	if ( ++p == pe )
		goto _test_eof36;
case 36:
#line 2270 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 61: goto tr63;
		case 95: goto tr62;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr62;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr62;
		} else if ( (*p) >= 65 )
			goto tr62;
	} else
		goto tr62;
	goto tr33;
tr63:
#line 167 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st37;
st37:
	if ( ++p == pe )
		goto _test_eof37;
case 37:
#line 2297 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 34 )
		goto st56;
	if ( (*p) < 45 ) {
		if ( 32 <= (*p) && (*p) <= 43 )
			goto tr64;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr64;
	} else
		goto tr64;
	goto tr33;
tr64:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st38;
tr66:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st38;
st38:
	if ( ++p == pe )
		goto _test_eof38;
case 38:
#line 2329 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto tr67;
		case 62: goto tr45;
	}
	if ( (*p) > 33 ) {
		if ( 35 <= (*p) && (*p) <= 126 )
			goto tr66;
	} else if ( (*p) >= 32 )
		goto tr66;
	goto tr33;
tr67:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st39;
st39:
	if ( ++p == pe )
		goto _test_eof39;
case 39:
#line 2350 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 95 )
		goto tr68;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr68;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr69;
		} else if ( (*p) >= 65 )
			goto tr69;
	} else
		goto tr69;
	goto tr33;
tr68:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st40;
st40:
	if ( ++p == pe )
		goto _test_eof40;
case 40:
#line 2375 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 95 )
		goto st40;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st40;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr71;
		} else if ( (*p) >= 65 )
			goto tr71;
	} else
		goto tr71;
	goto tr33;
tr69:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st41;
tr71:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st41;
st41:
	if ( ++p == pe )
		goto _test_eof41;
case 41:
#line 2410 "inc/vcf/validator_detail.hpp"
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
	goto tr33;
tr72:
#line 167 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st42;
st42:
	if ( ++p == pe )
		goto _test_eof42;
case 42:
#line 2437 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 34 )
		goto st43;
	if ( (*p) < 45 ) {
		if ( 32 <= (*p) && (*p) <= 43 )
			goto tr64;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr64;
	} else
		goto tr64;
	goto tr33;
st43:
	if ( ++p == pe )
		goto _test_eof43;
case 43:
	switch( (*p) ) {
		case 34: goto tr75;
		case 92: goto tr76;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr74;
	goto tr33;
tr74:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st44;
tr77:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st44;
st44:
	if ( ++p == pe )
		goto _test_eof44;
case 44:
#line 2480 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr78;
		case 92: goto tr79;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr77;
	goto tr33;
tr75:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st45;
tr78:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st45;
st45:
	if ( ++p == pe )
		goto _test_eof45;
case 45:
#line 2508 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto st39;
		case 62: goto st25;
	}
	goto tr33;
tr76:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st46;
tr79:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st46;
st46:
	if ( ++p == pe )
		goto _test_eof46;
case 46:
#line 2534 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr81;
		case 92: goto tr79;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr77;
	goto tr33;
tr81:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st47;
st47:
	if ( ++p == pe )
		goto _test_eof47;
case 47:
#line 2556 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr78;
		case 44: goto tr82;
		case 62: goto tr83;
		case 92: goto tr79;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr77;
	goto tr33;
tr96:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st48;
tr82:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st48;
tr93:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st48;
st48:
	if ( ++p == pe )
		goto _test_eof48;
case 48:
#line 2596 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr78;
		case 47: goto tr77;
		case 92: goto tr79;
		case 95: goto tr84;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr77;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr85;
		} else
			goto tr84;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr85;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr77;
			} else if ( (*p) >= 97 )
				goto tr85;
		} else
			goto tr77;
	} else
		goto tr77;
	goto tr33;
tr84:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st49;
tr86:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st49;
st49:
	if ( ++p == pe )
		goto _test_eof49;
case 49:
#line 2647 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr78;
		case 47: goto tr77;
		case 92: goto tr79;
		case 95: goto tr86;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr77;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr87;
		} else
			goto tr86;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr87;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr77;
			} else if ( (*p) >= 97 )
				goto tr87;
		} else
			goto tr77;
	} else
		goto tr77;
	goto tr33;
tr85:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st50;
tr87:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st50;
st50:
	if ( ++p == pe )
		goto _test_eof50;
case 50:
#line 2698 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr78;
		case 47: goto tr77;
		case 61: goto tr88;
		case 92: goto tr79;
		case 95: goto tr87;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr77;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr77;
		} else
			goto tr87;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr77;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr77;
		} else
			goto tr87;
	} else
		goto tr87;
	goto tr33;
tr88:
#line 167 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st51;
st51:
	if ( ++p == pe )
		goto _test_eof51;
case 51:
#line 2741 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr90;
		case 44: goto tr77;
		case 62: goto tr77;
		case 92: goto tr91;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr89;
	goto tr33;
tr92:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st52;
tr89:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st52;
st52:
	if ( ++p == pe )
		goto _test_eof52;
case 52:
#line 2771 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr78;
		case 44: goto tr93;
		case 62: goto tr94;
		case 92: goto tr95;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr92;
	goto tr33;
tr97:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st53;
tr83:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st53;
tr94:
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
#line 2811 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr47;
		case 34: goto tr78;
		case 92: goto tr79;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr77;
	goto tr33;
tr95:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st54;
tr91:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st54;
st54:
	if ( ++p == pe )
		goto _test_eof54;
case 54:
#line 2840 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr81;
		case 44: goto tr93;
		case 62: goto tr94;
		case 92: goto tr95;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr92;
	goto tr33;
tr90:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st55;
st55:
	if ( ++p == pe )
		goto _test_eof55;
case 55:
#line 2860 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr75;
		case 44: goto tr96;
		case 62: goto tr97;
		case 92: goto tr76;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr74;
	goto tr33;
st56:
	if ( ++p == pe )
		goto _test_eof56;
case 56:
	switch( (*p) ) {
		case 34: goto tr75;
		case 92: goto tr99;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr98;
	goto tr33;
tr98:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st57;
tr100:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st57;
st57:
	if ( ++p == pe )
		goto _test_eof57;
case 57:
#line 2901 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr78;
		case 92: goto tr101;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr100;
	goto tr33;
tr99:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st58;
tr101:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st58;
st58:
	if ( ++p == pe )
		goto _test_eof58;
case 58:
#line 2929 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr102;
		case 92: goto tr101;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr100;
	goto tr33;
tr102:
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
#line 2951 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr78;
		case 44: goto tr103;
		case 62: goto tr104;
		case 92: goto tr101;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr100;
	goto tr33;
tr103:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st60;
tr113:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st60;
st60:
	if ( ++p == pe )
		goto _test_eof60;
case 60:
#line 2981 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr78;
		case 47: goto tr100;
		case 92: goto tr101;
		case 95: goto tr105;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr100;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr106;
		} else
			goto tr105;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr106;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr100;
			} else if ( (*p) >= 97 )
				goto tr106;
		} else
			goto tr100;
	} else
		goto tr100;
	goto tr33;
tr107:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st61;
tr105:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st61;
st61:
	if ( ++p == pe )
		goto _test_eof61;
case 61:
#line 3032 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr78;
		case 47: goto tr100;
		case 92: goto tr101;
		case 95: goto tr107;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr100;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr108;
		} else
			goto tr107;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr108;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr100;
			} else if ( (*p) >= 97 )
				goto tr108;
		} else
			goto tr100;
	} else
		goto tr100;
	goto tr33;
tr108:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st62;
tr106:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st62;
st62:
	if ( ++p == pe )
		goto _test_eof62;
case 62:
#line 3083 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr78;
		case 47: goto tr100;
		case 61: goto tr109;
		case 92: goto tr101;
		case 95: goto tr108;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr100;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr100;
		} else
			goto tr108;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr100;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr100;
		} else
			goto tr108;
	} else
		goto tr108;
	goto tr33;
tr109:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 167 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st63;
st63:
	if ( ++p == pe )
		goto _test_eof63;
case 63:
#line 3126 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr90;
		case 44: goto tr100;
		case 62: goto tr100;
		case 92: goto tr111;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr110;
	goto tr33;
tr112:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st64;
tr110:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st64;
st64:
	if ( ++p == pe )
		goto _test_eof64;
case 64:
#line 3156 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr78;
		case 44: goto tr113;
		case 62: goto tr114;
		case 92: goto tr115;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr112;
	goto tr33;
tr104:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st65;
tr114:
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
#line 3186 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr47;
		case 34: goto tr78;
		case 92: goto tr101;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr100;
	goto tr33;
tr115:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st66;
tr111:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st66;
st66:
	if ( ++p == pe )
		goto _test_eof66;
case 66:
#line 3215 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr102;
		case 44: goto tr113;
		case 62: goto tr114;
		case 92: goto tr115;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr112;
	goto tr33;
tr25:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st67;
st67:
	if ( ++p == pe )
		goto _test_eof67;
case 67:
#line 3239 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 61: goto tr35;
		case 76: goto tr117;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr34;
	goto tr116;
tr117:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st68;
st68:
	if ( ++p == pe )
		goto _test_eof68;
case 68:
#line 3257 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 61: goto tr35;
		case 84: goto st69;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr34;
	goto tr116;
st69:
	if ( ++p == pe )
		goto _test_eof69;
case 69:
	if ( (*p) == 61 )
		goto tr119;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr34;
	goto tr116;
tr119:
#line 103 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "ALT");
    }
	goto st70;
st70:
	if ( ++p == pe )
		goto _test_eof70;
case 70:
#line 3284 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 60 )
		goto st71;
	goto tr116;
st71:
	if ( ++p == pe )
		goto _test_eof71;
case 71:
	if ( (*p) == 73 )
		goto st72;
	goto tr116;
st72:
	if ( ++p == pe )
		goto _test_eof72;
case 72:
	if ( (*p) == 68 )
		goto st73;
	goto tr116;
st73:
	if ( ++p == pe )
		goto _test_eof73;
case 73:
	if ( (*p) == 61 )
		goto st74;
	goto tr116;
st74:
	if ( ++p == pe )
		goto _test_eof74;
case 74:
	switch( (*p) ) {
		case 58: goto tr126;
		case 95: goto tr126;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr125;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr125;
	} else
		goto tr125;
	goto tr124;
tr128:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st75;
tr125:
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
	goto st75;
st75:
	if ( ++p == pe )
		goto _test_eof75;
case 75:
#line 3350 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto tr127;
		case 95: goto tr128;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 58 )
			goto tr128;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr128;
	} else
		goto tr128;
	goto tr124;
tr127:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st76;
st76:
	if ( ++p == pe )
		goto _test_eof76;
case 76:
#line 3374 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 68 )
		goto st77;
	goto tr116;
st77:
	if ( ++p == pe )
		goto _test_eof77;
case 77:
	if ( (*p) == 101 )
		goto st78;
	goto tr116;
st78:
	if ( ++p == pe )
		goto _test_eof78;
case 78:
	if ( (*p) == 115 )
		goto st79;
	goto tr116;
st79:
	if ( ++p == pe )
		goto _test_eof79;
case 79:
	if ( (*p) == 99 )
		goto st80;
	goto tr116;
st80:
	if ( ++p == pe )
		goto _test_eof80;
case 80:
	if ( (*p) == 114 )
		goto st81;
	goto tr116;
st81:
	if ( ++p == pe )
		goto _test_eof81;
case 81:
	if ( (*p) == 105 )
		goto st82;
	goto tr116;
st82:
	if ( ++p == pe )
		goto _test_eof82;
case 82:
	if ( (*p) == 112 )
		goto st83;
	goto tr116;
st83:
	if ( ++p == pe )
		goto _test_eof83;
case 83:
	if ( (*p) == 116 )
		goto st84;
	goto tr116;
st84:
	if ( ++p == pe )
		goto _test_eof84;
case 84:
	if ( (*p) == 105 )
		goto st85;
	goto tr116;
st85:
	if ( ++p == pe )
		goto _test_eof85;
case 85:
	if ( (*p) == 111 )
		goto st86;
	goto tr116;
st86:
	if ( ++p == pe )
		goto _test_eof86;
case 86:
	if ( (*p) == 110 )
		goto st87;
	goto tr116;
st87:
	if ( ++p == pe )
		goto _test_eof87;
case 87:
	if ( (*p) == 61 )
		goto st88;
	goto tr116;
st88:
	if ( ++p == pe )
		goto _test_eof88;
case 88:
	if ( (*p) == 34 )
		goto tr141;
	goto tr116;
tr141:
#line 151 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Description");
    }
	goto st89;
st89:
	if ( ++p == pe )
		goto _test_eof89;
case 89:
#line 3472 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr144;
		case 92: goto tr145;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr143;
	goto tr142;
tr143:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st90;
tr146:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st90;
st90:
	if ( ++p == pe )
		goto _test_eof90;
case 90:
#line 3500 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr147;
		case 92: goto tr148;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr146;
	goto tr142;
tr144:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st91;
tr147:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st91;
st91:
	if ( ++p == pe )
		goto _test_eof91;
case 91:
#line 3528 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto st92;
		case 62: goto st106;
	}
	goto tr142;
st92:
	if ( ++p == pe )
		goto _test_eof92;
case 92:
	if ( (*p) == 95 )
		goto tr152;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr152;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr153;
		} else if ( (*p) >= 65 )
			goto tr153;
	} else
		goto tr153;
	goto tr151;
tr152:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st93;
st93:
	if ( ++p == pe )
		goto _test_eof93;
case 93:
#line 3562 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 95 )
		goto st93;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st93;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr155;
		} else if ( (*p) >= 65 )
			goto tr155;
	} else
		goto tr155;
	goto tr151;
tr153:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st94;
tr155:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st94;
st94:
	if ( ++p == pe )
		goto _test_eof94;
case 94:
#line 3597 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 61: goto tr156;
		case 95: goto tr155;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr155;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr155;
		} else if ( (*p) >= 65 )
			goto tr155;
	} else
		goto tr155;
	goto tr151;
tr156:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st95;
st95:
	if ( ++p == pe )
		goto _test_eof95;
case 95:
#line 3624 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 34 )
		goto st96;
	goto tr116;
st96:
	if ( ++p == pe )
		goto _test_eof96;
case 96:
	switch( (*p) ) {
		case 34: goto tr144;
		case 92: goto tr159;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr158;
	goto tr142;
tr158:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st97;
tr160:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st97;
st97:
	if ( ++p == pe )
		goto _test_eof97;
case 97:
#line 3659 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr147;
		case 92: goto tr161;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr160;
	goto tr142;
tr159:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st98;
tr161:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st98;
st98:
	if ( ++p == pe )
		goto _test_eof98;
case 98:
#line 3687 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr162;
		case 92: goto tr161;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr160;
	goto tr142;
tr162:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st99;
st99:
	if ( ++p == pe )
		goto _test_eof99;
case 99:
#line 3709 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr147;
		case 44: goto tr163;
		case 62: goto tr164;
		case 92: goto tr161;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr160;
	goto tr142;
tr172:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st100;
tr163:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st100;
st100:
	if ( ++p == pe )
		goto _test_eof100;
case 100:
#line 3739 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr147;
		case 47: goto tr160;
		case 92: goto tr161;
		case 95: goto tr166;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr160;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr167;
		} else
			goto tr166;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr167;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr160;
			} else if ( (*p) >= 97 )
				goto tr167;
		} else
			goto tr160;
	} else
		goto tr160;
	goto tr165;
tr166:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st101;
tr168:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st101;
st101:
	if ( ++p == pe )
		goto _test_eof101;
case 101:
#line 3790 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr147;
		case 47: goto tr160;
		case 92: goto tr161;
		case 95: goto tr168;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr160;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr169;
		} else
			goto tr168;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr169;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr160;
			} else if ( (*p) >= 97 )
				goto tr169;
		} else
			goto tr160;
	} else
		goto tr160;
	goto tr165;
tr167:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st102;
tr169:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st102;
st102:
	if ( ++p == pe )
		goto _test_eof102;
case 102:
#line 3841 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr147;
		case 47: goto tr160;
		case 61: goto tr170;
		case 92: goto tr161;
		case 95: goto tr169;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr160;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr160;
		} else
			goto tr169;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr160;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr160;
		} else
			goto tr169;
	} else
		goto tr169;
	goto tr165;
tr170:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
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
#line 3884 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr171;
		case 92: goto tr161;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr160;
	goto tr142;
tr171:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st104;
st104:
	if ( ++p == pe )
		goto _test_eof104;
case 104:
#line 3902 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr144;
		case 44: goto tr172;
		case 62: goto tr173;
		case 92: goto tr159;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr158;
	goto tr142;
tr173:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st105;
tr164:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st105;
st105:
	if ( ++p == pe )
		goto _test_eof105;
case 105:
#line 3932 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr47;
		case 34: goto tr147;
		case 92: goto tr161;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr160;
	goto tr142;
st106:
	if ( ++p == pe )
		goto _test_eof106;
case 106:
	if ( (*p) == 10 )
		goto tr47;
	goto tr116;
tr145:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st107;
tr148:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st107;
st107:
	if ( ++p == pe )
		goto _test_eof107;
case 107:
#line 3968 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr174;
		case 92: goto tr148;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr146;
	goto tr142;
tr174:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st108;
st108:
	if ( ++p == pe )
		goto _test_eof108;
case 108:
#line 3990 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr147;
		case 44: goto tr175;
		case 62: goto tr176;
		case 92: goto tr148;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr146;
	goto tr142;
tr175:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st109;
st109:
	if ( ++p == pe )
		goto _test_eof109;
case 109:
#line 4010 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr147;
		case 47: goto tr146;
		case 92: goto tr148;
		case 95: goto tr178;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr146;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr179;
		} else
			goto tr178;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr179;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr146;
			} else if ( (*p) >= 97 )
				goto tr179;
		} else
			goto tr146;
	} else
		goto tr146;
	goto tr177;
tr180:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st110;
tr178:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st110;
st110:
	if ( ++p == pe )
		goto _test_eof110;
case 110:
#line 4061 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr147;
		case 47: goto tr146;
		case 92: goto tr148;
		case 95: goto tr180;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr146;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr181;
		} else
			goto tr180;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr181;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr146;
			} else if ( (*p) >= 97 )
				goto tr181;
		} else
			goto tr146;
	} else
		goto tr146;
	goto tr177;
tr181:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st111;
tr179:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st111;
st111:
	if ( ++p == pe )
		goto _test_eof111;
case 111:
#line 4112 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr147;
		case 47: goto tr146;
		case 61: goto tr182;
		case 92: goto tr148;
		case 95: goto tr181;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr146;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr146;
		} else
			goto tr181;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr146;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr146;
		} else
			goto tr181;
	} else
		goto tr181;
	goto tr177;
tr182:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st112;
st112:
	if ( ++p == pe )
		goto _test_eof112;
case 112:
#line 4155 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr171;
		case 92: goto tr148;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr146;
	goto tr142;
tr176:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st113;
st113:
	if ( ++p == pe )
		goto _test_eof113;
case 113:
#line 4173 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr47;
		case 34: goto tr147;
		case 92: goto tr148;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr146;
	goto tr142;
tr126:
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
#line 4196 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 58: goto st114;
		case 95: goto st114;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr128;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr128;
	} else
		goto tr128;
	goto tr124;
tr26:
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
#line 4224 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 61: goto tr35;
		case 73: goto tr185;
		case 79: goto tr186;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr34;
	goto tr184;
tr185:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st116;
st116:
	if ( ++p == pe )
		goto _test_eof116;
case 116:
#line 4243 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 61: goto tr35;
		case 76: goto tr188;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr34;
	goto tr187;
tr188:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st117;
st117:
	if ( ++p == pe )
		goto _test_eof117;
case 117:
#line 4261 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 61: goto tr35;
		case 84: goto tr189;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr34;
	goto tr187;
tr189:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st118;
st118:
	if ( ++p == pe )
		goto _test_eof118;
case 118:
#line 4279 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 61: goto tr35;
		case 69: goto tr190;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr34;
	goto tr187;
tr190:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st119;
st119:
	if ( ++p == pe )
		goto _test_eof119;
case 119:
#line 4297 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 61: goto tr35;
		case 82: goto st120;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr34;
	goto tr187;
st120:
	if ( ++p == pe )
		goto _test_eof120;
case 120:
	if ( (*p) == 61 )
		goto tr192;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr34;
	goto tr187;
tr192:
#line 115 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "FILTER");
    }
	goto st121;
st121:
	if ( ++p == pe )
		goto _test_eof121;
case 121:
#line 4324 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 60 )
		goto st122;
	goto tr187;
st122:
	if ( ++p == pe )
		goto _test_eof122;
case 122:
	if ( (*p) == 73 )
		goto st123;
	goto tr187;
st123:
	if ( ++p == pe )
		goto _test_eof123;
case 123:
	if ( (*p) == 68 )
		goto st124;
	goto tr187;
st124:
	if ( ++p == pe )
		goto _test_eof124;
case 124:
	if ( (*p) == 61 )
		goto st125;
	goto tr187;
st125:
	if ( ++p == pe )
		goto _test_eof125;
case 125:
	if ( (*p) == 95 )
		goto tr198;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr198;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr199;
		} else if ( (*p) >= 65 )
			goto tr199;
	} else
		goto tr199;
	goto tr197;
tr198:
#line 139 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st126;
st126:
	if ( ++p == pe )
		goto _test_eof126;
case 126:
#line 4381 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 95 )
		goto st126;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st126;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr201;
		} else if ( (*p) >= 65 )
			goto tr201;
	} else
		goto tr201;
	goto tr197;
tr201:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st127;
tr199:
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
	goto st127;
st127:
	if ( ++p == pe )
		goto _test_eof127;
case 127:
#line 4420 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto tr202;
		case 95: goto tr201;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr201;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr201;
		} else if ( (*p) >= 65 )
			goto tr201;
	} else
		goto tr201;
	goto tr197;
tr202:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st128;
st128:
	if ( ++p == pe )
		goto _test_eof128;
case 128:
#line 4447 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 68 )
		goto st129;
	goto tr187;
st129:
	if ( ++p == pe )
		goto _test_eof129;
case 129:
	if ( (*p) == 101 )
		goto st130;
	goto tr187;
st130:
	if ( ++p == pe )
		goto _test_eof130;
case 130:
	if ( (*p) == 115 )
		goto st131;
	goto tr187;
st131:
	if ( ++p == pe )
		goto _test_eof131;
case 131:
	if ( (*p) == 99 )
		goto st132;
	goto tr187;
st132:
	if ( ++p == pe )
		goto _test_eof132;
case 132:
	if ( (*p) == 114 )
		goto st133;
	goto tr187;
st133:
	if ( ++p == pe )
		goto _test_eof133;
case 133:
	if ( (*p) == 105 )
		goto st134;
	goto tr187;
st134:
	if ( ++p == pe )
		goto _test_eof134;
case 134:
	if ( (*p) == 112 )
		goto st135;
	goto tr187;
st135:
	if ( ++p == pe )
		goto _test_eof135;
case 135:
	if ( (*p) == 116 )
		goto st136;
	goto tr187;
st136:
	if ( ++p == pe )
		goto _test_eof136;
case 136:
	if ( (*p) == 105 )
		goto st137;
	goto tr187;
st137:
	if ( ++p == pe )
		goto _test_eof137;
case 137:
	if ( (*p) == 111 )
		goto st138;
	goto tr187;
st138:
	if ( ++p == pe )
		goto _test_eof138;
case 138:
	if ( (*p) == 110 )
		goto st139;
	goto tr187;
st139:
	if ( ++p == pe )
		goto _test_eof139;
case 139:
	if ( (*p) == 61 )
		goto st140;
	goto tr187;
st140:
	if ( ++p == pe )
		goto _test_eof140;
case 140:
	if ( (*p) == 34 )
		goto tr215;
	goto tr187;
tr215:
#line 151 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Description");
    }
	goto st141;
st141:
	if ( ++p == pe )
		goto _test_eof141;
case 141:
#line 4545 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr218;
		case 92: goto tr219;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr217;
	goto tr216;
tr217:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st142;
tr220:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st142;
st142:
	if ( ++p == pe )
		goto _test_eof142;
case 142:
#line 4573 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr221;
		case 92: goto tr222;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr220;
	goto tr216;
tr218:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st143;
tr221:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st143;
st143:
	if ( ++p == pe )
		goto _test_eof143;
case 143:
#line 4601 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto st144;
		case 62: goto st158;
	}
	goto tr216;
st144:
	if ( ++p == pe )
		goto _test_eof144;
case 144:
	if ( (*p) == 95 )
		goto tr225;
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
	goto tr197;
tr225:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st145;
st145:
	if ( ++p == pe )
		goto _test_eof145;
case 145:
#line 4635 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 95 )
		goto st145;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st145;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr228;
		} else if ( (*p) >= 65 )
			goto tr228;
	} else
		goto tr228;
	goto tr197;
tr226:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st146;
tr228:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st146;
st146:
	if ( ++p == pe )
		goto _test_eof146;
case 146:
#line 4670 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 61: goto tr229;
		case 95: goto tr228;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr228;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr228;
		} else if ( (*p) >= 65 )
			goto tr228;
	} else
		goto tr228;
	goto tr197;
tr229:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st147;
st147:
	if ( ++p == pe )
		goto _test_eof147;
case 147:
#line 4697 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 34 )
		goto st148;
	goto tr187;
st148:
	if ( ++p == pe )
		goto _test_eof148;
case 148:
	switch( (*p) ) {
		case 34: goto tr218;
		case 92: goto tr232;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr231;
	goto tr216;
tr231:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st149;
tr233:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st149;
st149:
	if ( ++p == pe )
		goto _test_eof149;
case 149:
#line 4732 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr221;
		case 92: goto tr234;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr233;
	goto tr216;
tr232:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st150;
tr234:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st150;
st150:
	if ( ++p == pe )
		goto _test_eof150;
case 150:
#line 4760 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr235;
		case 92: goto tr234;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr233;
	goto tr216;
tr235:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st151;
st151:
	if ( ++p == pe )
		goto _test_eof151;
case 151:
#line 4782 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr221;
		case 44: goto tr236;
		case 62: goto tr237;
		case 92: goto tr234;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr233;
	goto tr216;
tr245:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st152;
tr236:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st152;
st152:
	if ( ++p == pe )
		goto _test_eof152;
case 152:
#line 4812 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr221;
		case 47: goto tr233;
		case 92: goto tr234;
		case 95: goto tr239;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr233;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr240;
		} else
			goto tr239;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr240;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr233;
			} else if ( (*p) >= 97 )
				goto tr240;
		} else
			goto tr233;
	} else
		goto tr233;
	goto tr238;
tr239:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st153;
tr241:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st153;
st153:
	if ( ++p == pe )
		goto _test_eof153;
case 153:
#line 4863 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr221;
		case 47: goto tr233;
		case 92: goto tr234;
		case 95: goto tr241;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr233;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr242;
		} else
			goto tr241;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr242;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr233;
			} else if ( (*p) >= 97 )
				goto tr242;
		} else
			goto tr233;
	} else
		goto tr233;
	goto tr238;
tr240:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st154;
tr242:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st154;
st154:
	if ( ++p == pe )
		goto _test_eof154;
case 154:
#line 4914 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr221;
		case 47: goto tr233;
		case 61: goto tr243;
		case 92: goto tr234;
		case 95: goto tr242;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr233;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr233;
		} else
			goto tr242;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr233;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr233;
		} else
			goto tr242;
	} else
		goto tr242;
	goto tr238;
tr243:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st155;
st155:
	if ( ++p == pe )
		goto _test_eof155;
case 155:
#line 4957 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr244;
		case 92: goto tr234;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr233;
	goto tr216;
tr244:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st156;
st156:
	if ( ++p == pe )
		goto _test_eof156;
case 156:
#line 4975 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr218;
		case 44: goto tr245;
		case 62: goto tr246;
		case 92: goto tr232;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr231;
	goto tr216;
tr246:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st157;
tr237:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st157;
st157:
	if ( ++p == pe )
		goto _test_eof157;
case 157:
#line 5005 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr47;
		case 34: goto tr221;
		case 92: goto tr234;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr233;
	goto tr216;
st158:
	if ( ++p == pe )
		goto _test_eof158;
case 158:
	if ( (*p) == 10 )
		goto tr47;
	goto tr187;
tr219:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st159;
tr222:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st159;
st159:
	if ( ++p == pe )
		goto _test_eof159;
case 159:
#line 5041 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr247;
		case 92: goto tr222;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr220;
	goto tr216;
tr247:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st160;
st160:
	if ( ++p == pe )
		goto _test_eof160;
case 160:
#line 5063 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr221;
		case 44: goto tr248;
		case 62: goto tr249;
		case 92: goto tr222;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr220;
	goto tr216;
tr248:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st161;
st161:
	if ( ++p == pe )
		goto _test_eof161;
case 161:
#line 5083 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr221;
		case 47: goto tr220;
		case 92: goto tr222;
		case 95: goto tr251;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr220;
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
					goto tr220;
			} else if ( (*p) >= 97 )
				goto tr252;
		} else
			goto tr220;
	} else
		goto tr220;
	goto tr250;
tr253:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st162;
tr251:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st162;
st162:
	if ( ++p == pe )
		goto _test_eof162;
case 162:
#line 5134 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr221;
		case 47: goto tr220;
		case 92: goto tr222;
		case 95: goto tr253;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr220;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr254;
		} else
			goto tr253;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr254;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr220;
			} else if ( (*p) >= 97 )
				goto tr254;
		} else
			goto tr220;
	} else
		goto tr220;
	goto tr250;
tr254:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st163;
tr252:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st163;
st163:
	if ( ++p == pe )
		goto _test_eof163;
case 163:
#line 5185 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr221;
		case 47: goto tr220;
		case 61: goto tr255;
		case 92: goto tr222;
		case 95: goto tr254;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr220;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr220;
		} else
			goto tr254;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr220;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr220;
		} else
			goto tr254;
	} else
		goto tr254;
	goto tr250;
tr255:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st164;
st164:
	if ( ++p == pe )
		goto _test_eof164;
case 164:
#line 5228 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr244;
		case 92: goto tr222;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr220;
	goto tr216;
tr249:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st165;
st165:
	if ( ++p == pe )
		goto _test_eof165;
case 165:
#line 5246 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr47;
		case 34: goto tr221;
		case 92: goto tr222;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr220;
	goto tr216;
tr186:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st166;
st166:
	if ( ++p == pe )
		goto _test_eof166;
case 166:
#line 5265 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 61: goto tr35;
		case 82: goto tr257;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr34;
	goto tr256;
tr257:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st167;
st167:
	if ( ++p == pe )
		goto _test_eof167;
case 167:
#line 5283 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 61: goto tr35;
		case 77: goto tr258;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr34;
	goto tr256;
tr258:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st168;
st168:
	if ( ++p == pe )
		goto _test_eof168;
case 168:
#line 5301 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 61: goto tr35;
		case 65: goto tr259;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr34;
	goto tr256;
tr259:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st169;
st169:
	if ( ++p == pe )
		goto _test_eof169;
case 169:
#line 5319 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 61: goto tr35;
		case 84: goto st170;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr34;
	goto tr256;
st170:
	if ( ++p == pe )
		goto _test_eof170;
case 170:
	if ( (*p) == 61 )
		goto tr261;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr34;
	goto tr256;
tr261:
#line 119 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "FORMAT");
    }
	goto st171;
st171:
	if ( ++p == pe )
		goto _test_eof171;
case 171:
#line 5346 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 60 )
		goto st172;
	goto tr256;
st172:
	if ( ++p == pe )
		goto _test_eof172;
case 172:
	if ( (*p) == 73 )
		goto st173;
	goto tr256;
st173:
	if ( ++p == pe )
		goto _test_eof173;
case 173:
	if ( (*p) == 68 )
		goto st174;
	goto tr256;
st174:
	if ( ++p == pe )
		goto _test_eof174;
case 174:
	if ( (*p) == 61 )
		goto st175;
	goto tr256;
st175:
	if ( ++p == pe )
		goto _test_eof175;
case 175:
	if ( (*p) == 95 )
		goto tr267;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr267;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr268;
		} else if ( (*p) >= 65 )
			goto tr268;
	} else
		goto tr268;
	goto tr266;
tr267:
#line 139 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st176;
st176:
	if ( ++p == pe )
		goto _test_eof176;
case 176:
#line 5403 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 95 )
		goto st176;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st176;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr270;
		} else if ( (*p) >= 65 )
			goto tr270;
	} else
		goto tr270;
	goto tr266;
tr270:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st177;
tr268:
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
	goto st177;
st177:
	if ( ++p == pe )
		goto _test_eof177;
case 177:
#line 5442 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto tr271;
		case 95: goto tr270;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr270;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr270;
		} else if ( (*p) >= 65 )
			goto tr270;
	} else
		goto tr270;
	goto tr266;
tr271:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st178;
st178:
	if ( ++p == pe )
		goto _test_eof178;
case 178:
#line 5469 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 78 )
		goto st179;
	goto tr256;
st179:
	if ( ++p == pe )
		goto _test_eof179;
case 179:
	if ( (*p) == 117 )
		goto st180;
	goto tr256;
st180:
	if ( ++p == pe )
		goto _test_eof180;
case 180:
	if ( (*p) == 109 )
		goto st181;
	goto tr256;
st181:
	if ( ++p == pe )
		goto _test_eof181;
case 181:
	if ( (*p) == 98 )
		goto st182;
	goto tr256;
st182:
	if ( ++p == pe )
		goto _test_eof182;
case 182:
	if ( (*p) == 101 )
		goto st183;
	goto tr256;
st183:
	if ( ++p == pe )
		goto _test_eof183;
case 183:
	if ( (*p) == 114 )
		goto st184;
	goto tr256;
st184:
	if ( ++p == pe )
		goto _test_eof184;
case 184:
	if ( (*p) == 61 )
		goto st185;
	goto tr256;
st185:
	if ( ++p == pe )
		goto _test_eof185;
case 185:
	switch( (*p) ) {
		case 46: goto tr280;
		case 65: goto tr280;
		case 71: goto tr280;
		case 82: goto tr280;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr281;
	goto tr279;
tr280:
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
	goto st186;
st186:
	if ( ++p == pe )
		goto _test_eof186;
case 186:
#line 5546 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 44 )
		goto tr282;
	goto tr279;
tr282:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st187;
st187:
	if ( ++p == pe )
		goto _test_eof187;
case 187:
#line 5560 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 84 )
		goto st188;
	goto tr256;
st188:
	if ( ++p == pe )
		goto _test_eof188;
case 188:
	if ( (*p) == 121 )
		goto st189;
	goto tr256;
st189:
	if ( ++p == pe )
		goto _test_eof189;
case 189:
	if ( (*p) == 112 )
		goto st190;
	goto tr256;
st190:
	if ( ++p == pe )
		goto _test_eof190;
case 190:
	if ( (*p) == 101 )
		goto st191;
	goto tr256;
st191:
	if ( ++p == pe )
		goto _test_eof191;
case 191:
	if ( (*p) == 61 )
		goto st192;
	goto tr256;
st192:
	if ( ++p == pe )
		goto _test_eof192;
case 192:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr289;
	} else if ( (*p) >= 65 )
		goto tr289;
	goto tr288;
tr291:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st193;
tr289:
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
	goto st193;
st193:
	if ( ++p == pe )
		goto _test_eof193;
case 193:
#line 5626 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 44 )
		goto tr290;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr291;
	} else if ( (*p) >= 65 )
		goto tr291;
	goto tr288;
tr290:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st194;
st194:
	if ( ++p == pe )
		goto _test_eof194;
case 194:
#line 5645 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 68 )
		goto st195;
	goto tr256;
st195:
	if ( ++p == pe )
		goto _test_eof195;
case 195:
	if ( (*p) == 101 )
		goto st196;
	goto tr256;
st196:
	if ( ++p == pe )
		goto _test_eof196;
case 196:
	if ( (*p) == 115 )
		goto st197;
	goto tr256;
st197:
	if ( ++p == pe )
		goto _test_eof197;
case 197:
	if ( (*p) == 99 )
		goto st198;
	goto tr256;
st198:
	if ( ++p == pe )
		goto _test_eof198;
case 198:
	if ( (*p) == 114 )
		goto st199;
	goto tr256;
st199:
	if ( ++p == pe )
		goto _test_eof199;
case 199:
	if ( (*p) == 105 )
		goto st200;
	goto tr256;
st200:
	if ( ++p == pe )
		goto _test_eof200;
case 200:
	if ( (*p) == 112 )
		goto st201;
	goto tr256;
st201:
	if ( ++p == pe )
		goto _test_eof201;
case 201:
	if ( (*p) == 116 )
		goto st202;
	goto tr256;
st202:
	if ( ++p == pe )
		goto _test_eof202;
case 202:
	if ( (*p) == 105 )
		goto st203;
	goto tr256;
st203:
	if ( ++p == pe )
		goto _test_eof203;
case 203:
	if ( (*p) == 111 )
		goto st204;
	goto tr256;
st204:
	if ( ++p == pe )
		goto _test_eof204;
case 204:
	if ( (*p) == 110 )
		goto st205;
	goto tr256;
st205:
	if ( ++p == pe )
		goto _test_eof205;
case 205:
	if ( (*p) == 61 )
		goto st206;
	goto tr256;
st206:
	if ( ++p == pe )
		goto _test_eof206;
case 206:
	if ( (*p) == 34 )
		goto tr304;
	goto tr256;
tr304:
#line 151 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Description");
    }
	goto st207;
st207:
	if ( ++p == pe )
		goto _test_eof207;
case 207:
#line 5743 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr307;
		case 92: goto tr308;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr306;
	goto tr305;
tr306:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st208;
tr309:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st208;
st208:
	if ( ++p == pe )
		goto _test_eof208;
case 208:
#line 5771 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr310;
		case 92: goto tr311;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr309;
	goto tr305;
tr307:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st209;
tr310:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st209;
st209:
	if ( ++p == pe )
		goto _test_eof209;
case 209:
#line 5799 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto st210;
		case 62: goto st224;
	}
	goto tr305;
st210:
	if ( ++p == pe )
		goto _test_eof210;
case 210:
	if ( (*p) == 95 )
		goto tr314;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr314;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr315;
		} else if ( (*p) >= 65 )
			goto tr315;
	} else
		goto tr315;
	goto tr266;
tr314:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st211;
st211:
	if ( ++p == pe )
		goto _test_eof211;
case 211:
#line 5833 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 95 )
		goto st211;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st211;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr317;
		} else if ( (*p) >= 65 )
			goto tr317;
	} else
		goto tr317;
	goto tr266;
tr315:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st212;
tr317:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st212;
st212:
	if ( ++p == pe )
		goto _test_eof212;
case 212:
#line 5868 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 61: goto tr318;
		case 95: goto tr317;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr317;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr317;
		} else if ( (*p) >= 65 )
			goto tr317;
	} else
		goto tr317;
	goto tr266;
tr318:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st213;
st213:
	if ( ++p == pe )
		goto _test_eof213;
case 213:
#line 5895 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 34 )
		goto st214;
	goto tr256;
st214:
	if ( ++p == pe )
		goto _test_eof214;
case 214:
	switch( (*p) ) {
		case 34: goto tr307;
		case 92: goto tr321;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr320;
	goto tr305;
tr320:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st215;
tr322:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st215;
st215:
	if ( ++p == pe )
		goto _test_eof215;
case 215:
#line 5930 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr310;
		case 92: goto tr323;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr322;
	goto tr305;
tr321:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st216;
tr323:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st216;
st216:
	if ( ++p == pe )
		goto _test_eof216;
case 216:
#line 5958 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr324;
		case 92: goto tr323;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr322;
	goto tr305;
tr324:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st217;
st217:
	if ( ++p == pe )
		goto _test_eof217;
case 217:
#line 5980 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr310;
		case 44: goto tr325;
		case 62: goto tr326;
		case 92: goto tr323;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr322;
	goto tr305;
tr334:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st218;
tr325:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st218;
st218:
	if ( ++p == pe )
		goto _test_eof218;
case 218:
#line 6010 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr310;
		case 47: goto tr322;
		case 92: goto tr323;
		case 95: goto tr328;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr322;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr329;
		} else
			goto tr328;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr329;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr322;
			} else if ( (*p) >= 97 )
				goto tr329;
		} else
			goto tr322;
	} else
		goto tr322;
	goto tr327;
tr328:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st219;
tr330:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st219;
st219:
	if ( ++p == pe )
		goto _test_eof219;
case 219:
#line 6061 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr310;
		case 47: goto tr322;
		case 92: goto tr323;
		case 95: goto tr330;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr322;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr331;
		} else
			goto tr330;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr331;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr322;
			} else if ( (*p) >= 97 )
				goto tr331;
		} else
			goto tr322;
	} else
		goto tr322;
	goto tr327;
tr329:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st220;
tr331:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st220;
st220:
	if ( ++p == pe )
		goto _test_eof220;
case 220:
#line 6112 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr310;
		case 47: goto tr322;
		case 61: goto tr332;
		case 92: goto tr323;
		case 95: goto tr331;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr322;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr322;
		} else
			goto tr331;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr322;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr322;
		} else
			goto tr331;
	} else
		goto tr331;
	goto tr327;
tr332:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st221;
st221:
	if ( ++p == pe )
		goto _test_eof221;
case 221:
#line 6155 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr333;
		case 92: goto tr323;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr322;
	goto tr305;
tr333:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st222;
st222:
	if ( ++p == pe )
		goto _test_eof222;
case 222:
#line 6173 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr307;
		case 44: goto tr334;
		case 62: goto tr335;
		case 92: goto tr321;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr320;
	goto tr305;
tr335:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st223;
tr326:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st223;
st223:
	if ( ++p == pe )
		goto _test_eof223;
case 223:
#line 6203 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr47;
		case 34: goto tr310;
		case 92: goto tr323;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr322;
	goto tr305;
st224:
	if ( ++p == pe )
		goto _test_eof224;
case 224:
	if ( (*p) == 10 )
		goto tr47;
	goto tr256;
tr308:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st225;
tr311:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st225;
st225:
	if ( ++p == pe )
		goto _test_eof225;
case 225:
#line 6239 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr336;
		case 92: goto tr311;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr309;
	goto tr305;
tr336:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st226;
st226:
	if ( ++p == pe )
		goto _test_eof226;
case 226:
#line 6261 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr310;
		case 44: goto tr337;
		case 62: goto tr338;
		case 92: goto tr311;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr309;
	goto tr305;
tr337:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st227;
st227:
	if ( ++p == pe )
		goto _test_eof227;
case 227:
#line 6281 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr310;
		case 47: goto tr309;
		case 92: goto tr311;
		case 95: goto tr340;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr309;
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
					goto tr309;
			} else if ( (*p) >= 97 )
				goto tr341;
		} else
			goto tr309;
	} else
		goto tr309;
	goto tr339;
tr342:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st228;
tr340:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st228;
st228:
	if ( ++p == pe )
		goto _test_eof228;
case 228:
#line 6332 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr310;
		case 47: goto tr309;
		case 92: goto tr311;
		case 95: goto tr342;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr309;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr343;
		} else
			goto tr342;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr343;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr309;
			} else if ( (*p) >= 97 )
				goto tr343;
		} else
			goto tr309;
	} else
		goto tr309;
	goto tr339;
tr343:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st229;
tr341:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st229;
st229:
	if ( ++p == pe )
		goto _test_eof229;
case 229:
#line 6383 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr310;
		case 47: goto tr309;
		case 61: goto tr344;
		case 92: goto tr311;
		case 95: goto tr343;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr309;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr309;
		} else
			goto tr343;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr309;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr309;
		} else
			goto tr343;
	} else
		goto tr343;
	goto tr339;
tr344:
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
#line 6426 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr333;
		case 92: goto tr311;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr309;
	goto tr305;
tr338:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st231;
st231:
	if ( ++p == pe )
		goto _test_eof231;
case 231:
#line 6444 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr47;
		case 34: goto tr310;
		case 92: goto tr311;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr309;
	goto tr305;
tr345:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st232;
tr281:
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
#line 6477 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 44 )
		goto tr282;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr345;
	goto tr279;
tr27:
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
#line 6497 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 61: goto tr35;
		case 78: goto tr347;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr34;
	goto tr346;
tr347:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st234;
st234:
	if ( ++p == pe )
		goto _test_eof234;
case 234:
#line 6515 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 61: goto tr35;
		case 70: goto tr348;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr34;
	goto tr346;
tr348:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st235;
st235:
	if ( ++p == pe )
		goto _test_eof235;
case 235:
#line 6533 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 61: goto tr35;
		case 79: goto st236;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr34;
	goto tr346;
st236:
	if ( ++p == pe )
		goto _test_eof236;
case 236:
	if ( (*p) == 61 )
		goto tr350;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr34;
	goto tr346;
tr350:
#line 123 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "INFO");
    }
	goto st237;
st237:
	if ( ++p == pe )
		goto _test_eof237;
case 237:
#line 6560 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 60 )
		goto st238;
	goto tr346;
st238:
	if ( ++p == pe )
		goto _test_eof238;
case 238:
	if ( (*p) == 73 )
		goto st239;
	goto tr346;
st239:
	if ( ++p == pe )
		goto _test_eof239;
case 239:
	if ( (*p) == 68 )
		goto st240;
	goto tr346;
st240:
	if ( ++p == pe )
		goto _test_eof240;
case 240:
	if ( (*p) == 61 )
		goto st241;
	goto tr346;
st241:
	if ( ++p == pe )
		goto _test_eof241;
case 241:
	if ( (*p) == 95 )
		goto tr356;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr356;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr357;
		} else if ( (*p) >= 65 )
			goto tr357;
	} else
		goto tr357;
	goto tr355;
tr356:
#line 139 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st242;
st242:
	if ( ++p == pe )
		goto _test_eof242;
case 242:
#line 6617 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 95 )
		goto st242;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st242;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr359;
		} else if ( (*p) >= 65 )
			goto tr359;
	} else
		goto tr359;
	goto tr355;
tr359:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st243;
tr357:
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
	goto st243;
st243:
	if ( ++p == pe )
		goto _test_eof243;
case 243:
#line 6656 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto tr360;
		case 95: goto tr359;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr359;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr359;
		} else if ( (*p) >= 65 )
			goto tr359;
	} else
		goto tr359;
	goto tr355;
tr360:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st244;
st244:
	if ( ++p == pe )
		goto _test_eof244;
case 244:
#line 6683 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 78 )
		goto st245;
	goto tr346;
st245:
	if ( ++p == pe )
		goto _test_eof245;
case 245:
	if ( (*p) == 117 )
		goto st246;
	goto tr346;
st246:
	if ( ++p == pe )
		goto _test_eof246;
case 246:
	if ( (*p) == 109 )
		goto st247;
	goto tr346;
st247:
	if ( ++p == pe )
		goto _test_eof247;
case 247:
	if ( (*p) == 98 )
		goto st248;
	goto tr346;
st248:
	if ( ++p == pe )
		goto _test_eof248;
case 248:
	if ( (*p) == 101 )
		goto st249;
	goto tr346;
st249:
	if ( ++p == pe )
		goto _test_eof249;
case 249:
	if ( (*p) == 114 )
		goto st250;
	goto tr346;
st250:
	if ( ++p == pe )
		goto _test_eof250;
case 250:
	if ( (*p) == 61 )
		goto st251;
	goto tr346;
st251:
	if ( ++p == pe )
		goto _test_eof251;
case 251:
	switch( (*p) ) {
		case 46: goto tr369;
		case 65: goto tr369;
		case 71: goto tr369;
		case 82: goto tr369;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr370;
	goto tr368;
tr369:
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
	goto st252;
st252:
	if ( ++p == pe )
		goto _test_eof252;
case 252:
#line 6760 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 44 )
		goto tr371;
	goto tr368;
tr371:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st253;
st253:
	if ( ++p == pe )
		goto _test_eof253;
case 253:
#line 6774 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 84 )
		goto st254;
	goto tr346;
st254:
	if ( ++p == pe )
		goto _test_eof254;
case 254:
	if ( (*p) == 121 )
		goto st255;
	goto tr346;
st255:
	if ( ++p == pe )
		goto _test_eof255;
case 255:
	if ( (*p) == 112 )
		goto st256;
	goto tr346;
st256:
	if ( ++p == pe )
		goto _test_eof256;
case 256:
	if ( (*p) == 101 )
		goto st257;
	goto tr346;
st257:
	if ( ++p == pe )
		goto _test_eof257;
case 257:
	if ( (*p) == 61 )
		goto st258;
	goto tr346;
st258:
	if ( ++p == pe )
		goto _test_eof258;
case 258:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr378;
	} else if ( (*p) >= 65 )
		goto tr378;
	goto tr377;
tr380:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st259;
tr378:
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
	goto st259;
st259:
	if ( ++p == pe )
		goto _test_eof259;
case 259:
#line 6840 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 44 )
		goto tr379;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr380;
	} else if ( (*p) >= 65 )
		goto tr380;
	goto tr377;
tr379:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st260;
st260:
	if ( ++p == pe )
		goto _test_eof260;
case 260:
#line 6859 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 68 )
		goto st261;
	goto tr346;
st261:
	if ( ++p == pe )
		goto _test_eof261;
case 261:
	if ( (*p) == 101 )
		goto st262;
	goto tr346;
st262:
	if ( ++p == pe )
		goto _test_eof262;
case 262:
	if ( (*p) == 115 )
		goto st263;
	goto tr346;
st263:
	if ( ++p == pe )
		goto _test_eof263;
case 263:
	if ( (*p) == 99 )
		goto st264;
	goto tr346;
st264:
	if ( ++p == pe )
		goto _test_eof264;
case 264:
	if ( (*p) == 114 )
		goto st265;
	goto tr346;
st265:
	if ( ++p == pe )
		goto _test_eof265;
case 265:
	if ( (*p) == 105 )
		goto st266;
	goto tr346;
st266:
	if ( ++p == pe )
		goto _test_eof266;
case 266:
	if ( (*p) == 112 )
		goto st267;
	goto tr346;
st267:
	if ( ++p == pe )
		goto _test_eof267;
case 267:
	if ( (*p) == 116 )
		goto st268;
	goto tr346;
st268:
	if ( ++p == pe )
		goto _test_eof268;
case 268:
	if ( (*p) == 105 )
		goto st269;
	goto tr346;
st269:
	if ( ++p == pe )
		goto _test_eof269;
case 269:
	if ( (*p) == 111 )
		goto st270;
	goto tr346;
st270:
	if ( ++p == pe )
		goto _test_eof270;
case 270:
	if ( (*p) == 110 )
		goto st271;
	goto tr346;
st271:
	if ( ++p == pe )
		goto _test_eof271;
case 271:
	if ( (*p) == 61 )
		goto st272;
	goto tr346;
st272:
	if ( ++p == pe )
		goto _test_eof272;
case 272:
	if ( (*p) == 34 )
		goto tr393;
	goto tr346;
tr393:
#line 151 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Description");
    }
	goto st273;
st273:
	if ( ++p == pe )
		goto _test_eof273;
case 273:
#line 6957 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr396;
		case 92: goto tr397;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr395;
	goto tr394;
tr395:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st274;
tr398:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st274;
st274:
	if ( ++p == pe )
		goto _test_eof274;
case 274:
#line 6985 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr399;
		case 92: goto tr400;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr398;
	goto tr394;
tr396:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st275;
tr399:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st275;
st275:
	if ( ++p == pe )
		goto _test_eof275;
case 275:
#line 7013 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto st276;
		case 62: goto st290;
	}
	goto tr394;
st276:
	if ( ++p == pe )
		goto _test_eof276;
case 276:
	if ( (*p) == 95 )
		goto tr403;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr403;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr404;
		} else if ( (*p) >= 65 )
			goto tr404;
	} else
		goto tr404;
	goto tr355;
tr403:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st277;
st277:
	if ( ++p == pe )
		goto _test_eof277;
case 277:
#line 7047 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 95 )
		goto st277;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st277;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr406;
		} else if ( (*p) >= 65 )
			goto tr406;
	} else
		goto tr406;
	goto tr355;
tr404:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st278;
tr406:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st278;
st278:
	if ( ++p == pe )
		goto _test_eof278;
case 278:
#line 7082 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 61: goto tr407;
		case 95: goto tr406;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr406;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr406;
		} else if ( (*p) >= 65 )
			goto tr406;
	} else
		goto tr406;
	goto tr355;
tr407:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st279;
st279:
	if ( ++p == pe )
		goto _test_eof279;
case 279:
#line 7109 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 34 )
		goto st280;
	goto tr346;
st280:
	if ( ++p == pe )
		goto _test_eof280;
case 280:
	switch( (*p) ) {
		case 34: goto tr396;
		case 92: goto tr410;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr409;
	goto tr394;
tr409:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st281;
tr411:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st281;
st281:
	if ( ++p == pe )
		goto _test_eof281;
case 281:
#line 7144 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr399;
		case 92: goto tr412;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr411;
	goto tr394;
tr410:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st282;
tr412:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st282;
st282:
	if ( ++p == pe )
		goto _test_eof282;
case 282:
#line 7172 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr413;
		case 92: goto tr412;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr411;
	goto tr394;
tr413:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st283;
st283:
	if ( ++p == pe )
		goto _test_eof283;
case 283:
#line 7194 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr399;
		case 44: goto tr414;
		case 62: goto tr415;
		case 92: goto tr412;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr411;
	goto tr394;
tr423:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st284;
tr414:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st284;
st284:
	if ( ++p == pe )
		goto _test_eof284;
case 284:
#line 7224 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr399;
		case 47: goto tr411;
		case 92: goto tr412;
		case 95: goto tr417;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr411;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr418;
		} else
			goto tr417;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr418;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr411;
			} else if ( (*p) >= 97 )
				goto tr418;
		} else
			goto tr411;
	} else
		goto tr411;
	goto tr416;
tr417:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st285;
tr419:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st285;
st285:
	if ( ++p == pe )
		goto _test_eof285;
case 285:
#line 7275 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr399;
		case 47: goto tr411;
		case 92: goto tr412;
		case 95: goto tr419;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr411;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr420;
		} else
			goto tr419;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr420;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr411;
			} else if ( (*p) >= 97 )
				goto tr420;
		} else
			goto tr411;
	} else
		goto tr411;
	goto tr416;
tr418:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st286;
tr420:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st286;
st286:
	if ( ++p == pe )
		goto _test_eof286;
case 286:
#line 7326 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr399;
		case 47: goto tr411;
		case 61: goto tr421;
		case 92: goto tr412;
		case 95: goto tr420;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr411;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr411;
		} else
			goto tr420;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr411;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr411;
		} else
			goto tr420;
	} else
		goto tr420;
	goto tr416;
tr421:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st287;
st287:
	if ( ++p == pe )
		goto _test_eof287;
case 287:
#line 7369 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr422;
		case 92: goto tr412;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr411;
	goto tr394;
tr422:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st288;
st288:
	if ( ++p == pe )
		goto _test_eof288;
case 288:
#line 7387 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr396;
		case 44: goto tr423;
		case 62: goto tr424;
		case 92: goto tr410;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr409;
	goto tr394;
tr424:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st289;
tr415:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st289;
st289:
	if ( ++p == pe )
		goto _test_eof289;
case 289:
#line 7417 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr47;
		case 34: goto tr399;
		case 92: goto tr412;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr411;
	goto tr394;
st290:
	if ( ++p == pe )
		goto _test_eof290;
case 290:
	if ( (*p) == 10 )
		goto tr47;
	goto tr346;
tr397:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st291;
tr400:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st291;
st291:
	if ( ++p == pe )
		goto _test_eof291;
case 291:
#line 7453 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr425;
		case 92: goto tr400;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr398;
	goto tr394;
tr425:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st292;
st292:
	if ( ++p == pe )
		goto _test_eof292;
case 292:
#line 7475 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr399;
		case 44: goto tr426;
		case 62: goto tr427;
		case 92: goto tr400;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr398;
	goto tr394;
tr426:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st293;
st293:
	if ( ++p == pe )
		goto _test_eof293;
case 293:
#line 7495 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr399;
		case 47: goto tr398;
		case 92: goto tr400;
		case 95: goto tr429;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr398;
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
					goto tr398;
			} else if ( (*p) >= 97 )
				goto tr430;
		} else
			goto tr398;
	} else
		goto tr398;
	goto tr428;
tr431:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st294;
tr429:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st294;
st294:
	if ( ++p == pe )
		goto _test_eof294;
case 294:
#line 7546 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr399;
		case 47: goto tr398;
		case 92: goto tr400;
		case 95: goto tr431;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr398;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr432;
		} else
			goto tr431;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr432;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr398;
			} else if ( (*p) >= 97 )
				goto tr432;
		} else
			goto tr398;
	} else
		goto tr398;
	goto tr428;
tr432:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st295;
tr430:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st295;
st295:
	if ( ++p == pe )
		goto _test_eof295;
case 295:
#line 7597 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr399;
		case 47: goto tr398;
		case 61: goto tr433;
		case 92: goto tr400;
		case 95: goto tr432;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr398;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr398;
		} else
			goto tr432;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr398;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr398;
		} else
			goto tr432;
	} else
		goto tr432;
	goto tr428;
tr433:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st296;
st296:
	if ( ++p == pe )
		goto _test_eof296;
case 296:
#line 7640 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr422;
		case 92: goto tr400;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr398;
	goto tr394;
tr427:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st297;
st297:
	if ( ++p == pe )
		goto _test_eof297;
case 297:
#line 7658 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr47;
		case 34: goto tr399;
		case 92: goto tr400;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr398;
	goto tr394;
tr434:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st298;
tr370:
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
	goto st298;
st298:
	if ( ++p == pe )
		goto _test_eof298;
case 298:
#line 7691 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 44 )
		goto tr371;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr434;
	goto tr368;
tr28:
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
#line 7711 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 61: goto tr35;
		case 69: goto tr436;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr34;
	goto tr435;
tr436:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st300;
st300:
	if ( ++p == pe )
		goto _test_eof300;
case 300:
#line 7729 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 61: goto tr35;
		case 68: goto tr437;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr34;
	goto tr435;
tr437:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st301;
st301:
	if ( ++p == pe )
		goto _test_eof301;
case 301:
#line 7747 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 61: goto tr35;
		case 73: goto tr438;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr34;
	goto tr435;
tr438:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st302;
st302:
	if ( ++p == pe )
		goto _test_eof302;
case 302:
#line 7765 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 61: goto tr35;
		case 71: goto tr439;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr34;
	goto tr435;
tr439:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st303;
st303:
	if ( ++p == pe )
		goto _test_eof303;
case 303:
#line 7783 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 61: goto tr35;
		case 82: goto tr440;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr34;
	goto tr435;
tr440:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st304;
st304:
	if ( ++p == pe )
		goto _test_eof304;
case 304:
#line 7801 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 61: goto tr35;
		case 69: goto tr441;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr34;
	goto tr435;
tr441:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st305;
st305:
	if ( ++p == pe )
		goto _test_eof305;
case 305:
#line 7819 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 61: goto tr35;
		case 69: goto st306;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr34;
	goto tr435;
st306:
	if ( ++p == pe )
		goto _test_eof306;
case 306:
	if ( (*p) == 61 )
		goto tr443;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr34;
	goto tr435;
tr443:
#line 127 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "PEDIGREE");
    }
	goto st307;
st307:
	if ( ++p == pe )
		goto _test_eof307;
case 307:
#line 7846 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 60 )
		goto st308;
	goto tr435;
tr455:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st308;
st308:
	if ( ++p == pe )
		goto _test_eof308;
case 308:
#line 7860 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 95 )
		goto tr446;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr446;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr447;
		} else if ( (*p) >= 65 )
			goto tr447;
	} else
		goto tr447;
	goto tr445;
tr446:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st309;
st309:
	if ( ++p == pe )
		goto _test_eof309;
case 309:
#line 7885 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 95 )
		goto st309;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st309;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr449;
		} else if ( (*p) >= 65 )
			goto tr449;
	} else
		goto tr449;
	goto tr445;
tr447:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st310;
tr449:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st310;
st310:
	if ( ++p == pe )
		goto _test_eof310;
case 310:
#line 7920 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 61: goto tr450;
		case 95: goto tr449;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr449;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr449;
		} else if ( (*p) >= 65 )
			goto tr449;
	} else
		goto tr449;
	goto tr445;
tr450:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st311;
st311:
	if ( ++p == pe )
		goto _test_eof311;
case 311:
#line 7947 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 95 )
		goto tr451;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr451;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr452;
		} else if ( (*p) >= 65 )
			goto tr452;
	} else
		goto tr452;
	goto tr445;
tr451:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st312;
st312:
	if ( ++p == pe )
		goto _test_eof312;
case 312:
#line 7972 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 95 )
		goto st312;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st312;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr454;
		} else if ( (*p) >= 65 )
			goto tr454;
	} else
		goto tr454;
	goto tr445;
tr452:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st313;
tr454:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st313;
st313:
	if ( ++p == pe )
		goto _test_eof313;
case 313:
#line 8007 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto tr455;
		case 62: goto tr456;
		case 95: goto tr454;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr454;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr454;
		} else if ( (*p) >= 65 )
			goto tr454;
	} else
		goto tr454;
	goto tr445;
tr456:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st314;
st314:
	if ( ++p == pe )
		goto _test_eof314;
case 314:
#line 8035 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 10 )
		goto tr47;
	goto tr435;
tr29:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st315;
st315:
	if ( ++p == pe )
		goto _test_eof315;
case 315:
#line 8053 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 61: goto tr35;
		case 65: goto tr458;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr34;
	goto tr457;
tr458:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st316;
st316:
	if ( ++p == pe )
		goto _test_eof316;
case 316:
#line 8071 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 61: goto tr35;
		case 77: goto tr459;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr34;
	goto tr457;
tr459:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st317;
st317:
	if ( ++p == pe )
		goto _test_eof317;
case 317:
#line 8089 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 61: goto tr35;
		case 80: goto tr460;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr34;
	goto tr457;
tr460:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st318;
st318:
	if ( ++p == pe )
		goto _test_eof318;
case 318:
#line 8107 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 61: goto tr35;
		case 76: goto tr461;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr34;
	goto tr457;
tr461:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st319;
st319:
	if ( ++p == pe )
		goto _test_eof319;
case 319:
#line 8125 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 61: goto tr35;
		case 69: goto st320;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr34;
	goto tr457;
st320:
	if ( ++p == pe )
		goto _test_eof320;
case 320:
	if ( (*p) == 61 )
		goto tr463;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr34;
	goto tr457;
tr463:
#line 135 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "SAMPLE");
    }
	goto st321;
st321:
	if ( ++p == pe )
		goto _test_eof321;
case 321:
#line 8152 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 60 )
		goto st322;
	goto tr457;
st322:
	if ( ++p == pe )
		goto _test_eof322;
case 322:
	if ( (*p) == 73 )
		goto st323;
	goto tr457;
st323:
	if ( ++p == pe )
		goto _test_eof323;
case 323:
	if ( (*p) == 68 )
		goto st324;
	goto tr457;
st324:
	if ( ++p == pe )
		goto _test_eof324;
case 324:
	if ( (*p) == 61 )
		goto st325;
	goto tr457;
st325:
	if ( ++p == pe )
		goto _test_eof325;
case 325:
	if ( (*p) == 95 )
		goto tr469;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr469;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr470;
		} else if ( (*p) >= 65 )
			goto tr470;
	} else
		goto tr470;
	goto tr468;
tr469:
#line 139 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this, "ID");
    }
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st326;
st326:
	if ( ++p == pe )
		goto _test_eof326;
case 326:
#line 8209 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 95 )
		goto st326;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st326;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr472;
		} else if ( (*p) >= 65 )
			goto tr472;
	} else
		goto tr472;
	goto tr468;
tr472:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st327;
tr470:
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
	goto st327;
st327:
	if ( ++p == pe )
		goto _test_eof327;
case 327:
#line 8248 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto tr474;
		case 95: goto tr472;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr472;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr472;
		} else if ( (*p) >= 65 )
			goto tr472;
	} else
		goto tr472;
	goto tr473;
tr474:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st328;
st328:
	if ( ++p == pe )
		goto _test_eof328;
case 328:
#line 8275 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 71 )
		goto st329;
	goto tr475;
st329:
	if ( ++p == pe )
		goto _test_eof329;
case 329:
	if ( (*p) == 101 )
		goto st330;
	goto tr475;
st330:
	if ( ++p == pe )
		goto _test_eof330;
case 330:
	if ( (*p) == 110 )
		goto st331;
	goto tr475;
st331:
	if ( ++p == pe )
		goto _test_eof331;
case 331:
	if ( (*p) == 111 )
		goto st332;
	goto tr475;
st332:
	if ( ++p == pe )
		goto _test_eof332;
case 332:
	if ( (*p) == 109 )
		goto st333;
	goto tr475;
st333:
	if ( ++p == pe )
		goto _test_eof333;
case 333:
	if ( (*p) == 101 )
		goto st334;
	goto tr475;
st334:
	if ( ++p == pe )
		goto _test_eof334;
case 334:
	if ( (*p) == 115 )
		goto st335;
	goto tr475;
st335:
	if ( ++p == pe )
		goto _test_eof335;
case 335:
	if ( (*p) == 61 )
		goto st336;
	goto tr475;
st336:
	if ( ++p == pe )
		goto _test_eof336;
case 336:
	if ( (*p) < 35 ) {
		if ( 32 <= (*p) && (*p) <= 33 )
			goto tr484;
	} else if ( (*p) > 43 ) {
		if ( (*p) > 61 ) {
			if ( 63 <= (*p) && (*p) <= 126 )
				goto tr484;
		} else if ( (*p) >= 45 )
			goto tr484;
	} else
		goto tr484;
	goto tr475;
tr486:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st337;
tr484:
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
	goto st337;
st337:
	if ( ++p == pe )
		goto _test_eof337;
case 337:
#line 8368 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 44 )
		goto tr487;
	if ( (*p) < 35 ) {
		if ( 32 <= (*p) && (*p) <= 33 )
			goto tr486;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr486;
	} else
		goto tr486;
	goto tr485;
tr487:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st338;
st338:
	if ( ++p == pe )
		goto _test_eof338;
case 338:
#line 8390 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 77 )
		goto st339;
	goto tr488;
st339:
	if ( ++p == pe )
		goto _test_eof339;
case 339:
	if ( (*p) == 105 )
		goto st340;
	goto tr488;
st340:
	if ( ++p == pe )
		goto _test_eof340;
case 340:
	if ( (*p) == 120 )
		goto st341;
	goto tr488;
st341:
	if ( ++p == pe )
		goto _test_eof341;
case 341:
	if ( (*p) == 116 )
		goto st342;
	goto tr488;
st342:
	if ( ++p == pe )
		goto _test_eof342;
case 342:
	if ( (*p) == 117 )
		goto st343;
	goto tr488;
st343:
	if ( ++p == pe )
		goto _test_eof343;
case 343:
	if ( (*p) == 114 )
		goto st344;
	goto tr488;
st344:
	if ( ++p == pe )
		goto _test_eof344;
case 344:
	if ( (*p) == 101 )
		goto st345;
	goto tr488;
st345:
	if ( ++p == pe )
		goto _test_eof345;
case 345:
	if ( (*p) == 61 )
		goto st346;
	goto tr488;
st346:
	if ( ++p == pe )
		goto _test_eof346;
case 346:
	if ( (*p) < 35 ) {
		if ( 32 <= (*p) && (*p) <= 33 )
			goto tr497;
	} else if ( (*p) > 43 ) {
		if ( (*p) > 61 ) {
			if ( 63 <= (*p) && (*p) <= 126 )
				goto tr497;
		} else if ( (*p) >= 45 )
			goto tr497;
	} else
		goto tr497;
	goto tr488;
tr499:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st347;
tr497:
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
	goto st347;
st347:
	if ( ++p == pe )
		goto _test_eof347;
case 347:
#line 8483 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 44 )
		goto tr500;
	if ( (*p) < 35 ) {
		if ( 32 <= (*p) && (*p) <= 33 )
			goto tr499;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr499;
	} else
		goto tr499;
	goto tr498;
tr500:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st348;
st348:
	if ( ++p == pe )
		goto _test_eof348;
case 348:
#line 8505 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 68 )
		goto st349;
	goto tr501;
st349:
	if ( ++p == pe )
		goto _test_eof349;
case 349:
	if ( (*p) == 101 )
		goto st350;
	goto tr501;
st350:
	if ( ++p == pe )
		goto _test_eof350;
case 350:
	if ( (*p) == 115 )
		goto st351;
	goto tr501;
st351:
	if ( ++p == pe )
		goto _test_eof351;
case 351:
	if ( (*p) == 99 )
		goto st352;
	goto tr501;
st352:
	if ( ++p == pe )
		goto _test_eof352;
case 352:
	if ( (*p) == 114 )
		goto st353;
	goto tr501;
st353:
	if ( ++p == pe )
		goto _test_eof353;
case 353:
	if ( (*p) == 105 )
		goto st354;
	goto tr501;
st354:
	if ( ++p == pe )
		goto _test_eof354;
case 354:
	if ( (*p) == 112 )
		goto st355;
	goto tr501;
st355:
	if ( ++p == pe )
		goto _test_eof355;
case 355:
	if ( (*p) == 116 )
		goto st356;
	goto tr501;
st356:
	if ( ++p == pe )
		goto _test_eof356;
case 356:
	if ( (*p) == 105 )
		goto st357;
	goto tr501;
st357:
	if ( ++p == pe )
		goto _test_eof357;
case 357:
	if ( (*p) == 111 )
		goto st358;
	goto tr501;
st358:
	if ( ++p == pe )
		goto _test_eof358;
case 358:
	if ( (*p) == 110 )
		goto st359;
	goto tr501;
st359:
	if ( ++p == pe )
		goto _test_eof359;
case 359:
	if ( (*p) == 61 )
		goto st360;
	goto tr501;
st360:
	if ( ++p == pe )
		goto _test_eof360;
case 360:
	if ( (*p) == 34 )
		goto tr514;
	goto tr501;
tr514:
#line 151 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this, "Description");
    }
	goto st361;
st361:
	if ( ++p == pe )
		goto _test_eof361;
case 361:
#line 8603 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr516;
		case 92: goto tr517;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr515;
	goto tr501;
tr515:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st362;
tr518:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st362;
st362:
	if ( ++p == pe )
		goto _test_eof362;
case 362:
#line 8631 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr519;
		case 92: goto tr520;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr518;
	goto tr501;
tr516:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st363;
tr519:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st363;
st363:
	if ( ++p == pe )
		goto _test_eof363;
case 363:
#line 8659 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 62 )
		goto st364;
	goto tr501;
st364:
	if ( ++p == pe )
		goto _test_eof364;
case 364:
	if ( (*p) == 10 )
		goto tr47;
	goto tr457;
tr517:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st365;
tr520:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st365;
st365:
	if ( ++p == pe )
		goto _test_eof365;
case 365:
#line 8690 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr522;
		case 92: goto tr520;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr518;
	goto tr501;
tr522:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st366;
st366:
	if ( ++p == pe )
		goto _test_eof366;
case 366:
#line 8712 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr519;
		case 62: goto tr523;
		case 92: goto tr520;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr518;
	goto tr501;
tr523:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st367;
st367:
	if ( ++p == pe )
		goto _test_eof367;
case 367:
#line 8731 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr47;
		case 34: goto tr519;
		case 92: goto tr520;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr518;
	goto tr501;
tr30:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st368;
st368:
	if ( ++p == pe )
		goto _test_eof368;
case 368:
#line 8754 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 61: goto tr35;
		case 115: goto tr525;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr34;
	goto tr524;
tr525:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st369;
st369:
	if ( ++p == pe )
		goto _test_eof369;
case 369:
#line 8772 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 61: goto tr35;
		case 115: goto tr526;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr34;
	goto tr524;
tr526:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st370;
st370:
	if ( ++p == pe )
		goto _test_eof370;
case 370:
#line 8790 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 61: goto tr35;
		case 101: goto tr527;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr34;
	goto tr524;
tr527:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st371;
st371:
	if ( ++p == pe )
		goto _test_eof371;
case 371:
#line 8808 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 61: goto tr35;
		case 109: goto tr528;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr34;
	goto tr524;
tr528:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st372;
st372:
	if ( ++p == pe )
		goto _test_eof372;
case 372:
#line 8826 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 61: goto tr35;
		case 98: goto tr529;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr34;
	goto tr524;
tr529:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st373;
st373:
	if ( ++p == pe )
		goto _test_eof373;
case 373:
#line 8844 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 61: goto tr35;
		case 108: goto tr530;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr34;
	goto tr524;
tr530:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st374;
st374:
	if ( ++p == pe )
		goto _test_eof374;
case 374:
#line 8862 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 61: goto tr35;
		case 121: goto st375;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr34;
	goto tr524;
st375:
	if ( ++p == pe )
		goto _test_eof375;
case 375:
	if ( (*p) == 61 )
		goto tr532;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr34;
	goto tr524;
tr532:
#line 107 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "assembly");
    }
	goto st376;
st376:
	if ( ++p == pe )
		goto _test_eof376;
case 376:
#line 8889 "inc/vcf/validator_detail.hpp"
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr534;
	} else if ( (*p) >= 65 )
		goto tr534;
	goto tr533;
tr534:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st377;
st377:
	if ( ++p == pe )
		goto _test_eof377;
case 377:
#line 8906 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr533;
		case 35: goto tr533;
		case 47: goto tr533;
		case 58: goto tr533;
		case 63: goto tr533;
	}
	goto st378;
st378:
	if ( ++p == pe )
		goto _test_eof378;
case 378:
	switch( (*p) ) {
		case 10: goto tr533;
		case 35: goto tr533;
		case 47: goto tr533;
		case 58: goto st379;
		case 63: goto tr533;
	}
	goto st378;
st379:
	if ( ++p == pe )
		goto _test_eof379;
case 379:
	if ( (*p) == 47 )
		goto st380;
	goto tr533;
st380:
	if ( ++p == pe )
		goto _test_eof380;
case 380:
	if ( (*p) == 47 )
		goto st381;
	goto tr533;
st381:
	if ( ++p == pe )
		goto _test_eof381;
case 381:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr539;
	} else if ( (*p) >= 65 )
		goto tr539;
	goto tr533;
tr539:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st382;
st382:
	if ( ++p == pe )
		goto _test_eof382;
case 382:
#line 8961 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 10 )
		goto tr39;
	goto tr539;
tr31:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st383;
st383:
	if ( ++p == pe )
		goto _test_eof383;
case 383:
#line 8979 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 61: goto tr35;
		case 111: goto tr541;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr34;
	goto tr540;
tr541:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st384;
st384:
	if ( ++p == pe )
		goto _test_eof384;
case 384:
#line 8997 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 61: goto tr35;
		case 110: goto tr542;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr34;
	goto tr540;
tr542:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st385;
st385:
	if ( ++p == pe )
		goto _test_eof385;
case 385:
#line 9015 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 61: goto tr35;
		case 116: goto tr543;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr34;
	goto tr540;
tr543:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st386;
st386:
	if ( ++p == pe )
		goto _test_eof386;
case 386:
#line 9033 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 61: goto tr35;
		case 105: goto tr544;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr34;
	goto tr540;
tr544:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st387;
st387:
	if ( ++p == pe )
		goto _test_eof387;
case 387:
#line 9051 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 61: goto tr35;
		case 103: goto st388;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr34;
	goto tr540;
st388:
	if ( ++p == pe )
		goto _test_eof388;
case 388:
	if ( (*p) == 61 )
		goto tr546;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr34;
	goto tr540;
tr546:
#line 111 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "contig");
    }
	goto st389;
st389:
	if ( ++p == pe )
		goto _test_eof389;
case 389:
#line 9078 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 60 )
		goto st390;
	goto tr540;
st390:
	if ( ++p == pe )
		goto _test_eof390;
case 390:
	if ( (*p) == 73 )
		goto st391;
	goto tr540;
st391:
	if ( ++p == pe )
		goto _test_eof391;
case 391:
	if ( (*p) == 68 )
		goto st392;
	goto tr540;
st392:
	if ( ++p == pe )
		goto _test_eof392;
case 392:
	if ( (*p) == 61 )
		goto st393;
	goto tr540;
st393:
	if ( ++p == pe )
		goto _test_eof393;
case 393:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr552;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr552;
	} else
		goto tr552;
	goto tr551;
tr552:
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
	goto st394;
st394:
	if ( ++p == pe )
		goto _test_eof394;
case 394:
#line 9134 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto tr554;
		case 59: goto tr553;
		case 62: goto tr556;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr553;
		} else if ( (*p) > 57 ) {
			if ( 61 <= (*p) && (*p) <= 64 )
				goto tr553;
		} else
			goto tr555;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr553;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr553;
		} else
			goto tr555;
	} else
		goto tr555;
	goto tr551;
tr553:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st395;
st395:
	if ( ++p == pe )
		goto _test_eof395;
case 395:
#line 9171 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr553;
		case 61: goto tr553;
	}
	if ( (*p) < 63 ) {
		if ( (*p) < 45 ) {
			if ( 33 <= (*p) && (*p) <= 43 )
				goto tr553;
		} else if ( (*p) > 47 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr555;
		} else
			goto tr553;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr555;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr553;
			} else if ( (*p) >= 97 )
				goto tr555;
		} else
			goto tr553;
	} else
		goto tr553;
	goto tr551;
tr555:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st396;
st396:
	if ( ++p == pe )
		goto _test_eof396;
case 396:
#line 9210 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto tr554;
		case 59: goto tr555;
		case 62: goto tr556;
	}
	if ( (*p) > 57 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr555;
	} else if ( (*p) >= 33 )
		goto tr555;
	goto tr551;
tr554:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st397;
st397:
	if ( ++p == pe )
		goto _test_eof397;
case 397:
#line 9232 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 95 )
		goto tr557;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr557;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr558;
		} else if ( (*p) >= 65 )
			goto tr558;
	} else
		goto tr558;
	goto tr540;
tr557:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st398;
st398:
	if ( ++p == pe )
		goto _test_eof398;
case 398:
#line 9257 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 95 )
		goto st398;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st398;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr560;
		} else if ( (*p) >= 65 )
			goto tr560;
	} else
		goto tr560;
	goto tr540;
tr558:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st399;
tr560:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st399;
st399:
	if ( ++p == pe )
		goto _test_eof399;
case 399:
#line 9292 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 61: goto tr561;
		case 95: goto tr560;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr560;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr560;
		} else if ( (*p) >= 65 )
			goto tr560;
	} else
		goto tr560;
	goto tr540;
tr561:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st400;
st400:
	if ( ++p == pe )
		goto _test_eof400;
case 400:
#line 9319 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 34 )
		goto st403;
	if ( (*p) < 45 ) {
		if ( 32 <= (*p) && (*p) <= 43 )
			goto tr562;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr562;
	} else
		goto tr562;
	goto tr540;
tr562:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st401;
tr564:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st401;
st401:
	if ( ++p == pe )
		goto _test_eof401;
case 401:
#line 9351 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto tr554;
		case 62: goto tr556;
	}
	if ( (*p) > 33 ) {
		if ( 35 <= (*p) && (*p) <= 126 )
			goto tr564;
	} else if ( (*p) >= 32 )
		goto tr564;
	goto tr540;
tr556:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st402;
st402:
	if ( ++p == pe )
		goto _test_eof402;
case 402:
#line 9372 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 10 )
		goto tr47;
	goto tr540;
st403:
	if ( ++p == pe )
		goto _test_eof403;
case 403:
	switch( (*p) ) {
		case 34: goto tr566;
		case 92: goto tr567;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr565;
	goto tr540;
tr565:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st404;
tr568:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st404;
st404:
	if ( ++p == pe )
		goto _test_eof404;
case 404:
#line 9407 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr569;
		case 92: goto tr570;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr568;
	goto tr540;
tr566:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st405;
tr569:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st405;
st405:
	if ( ++p == pe )
		goto _test_eof405;
case 405:
#line 9435 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto st397;
		case 62: goto st402;
	}
	goto tr540;
tr567:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st406;
tr570:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st406;
st406:
	if ( ++p == pe )
		goto _test_eof406;
case 406:
#line 9461 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr573;
		case 92: goto tr570;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr568;
	goto tr540;
tr573:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st407;
st407:
	if ( ++p == pe )
		goto _test_eof407;
case 407:
#line 9483 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr569;
		case 44: goto tr574;
		case 62: goto tr575;
		case 92: goto tr570;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr568;
	goto tr540;
tr588:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st408;
tr574:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st408;
tr585:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st408;
st408:
	if ( ++p == pe )
		goto _test_eof408;
case 408:
#line 9523 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr569;
		case 47: goto tr568;
		case 92: goto tr570;
		case 95: goto tr576;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr568;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr577;
		} else
			goto tr576;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr577;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr568;
			} else if ( (*p) >= 97 )
				goto tr577;
		} else
			goto tr568;
	} else
		goto tr568;
	goto tr540;
tr576:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st409;
tr578:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st409;
st409:
	if ( ++p == pe )
		goto _test_eof409;
case 409:
#line 9574 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr569;
		case 47: goto tr568;
		case 92: goto tr570;
		case 95: goto tr578;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr568;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr579;
		} else
			goto tr578;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr579;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr568;
			} else if ( (*p) >= 97 )
				goto tr579;
		} else
			goto tr568;
	} else
		goto tr568;
	goto tr540;
tr577:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st410;
tr579:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st410;
st410:
	if ( ++p == pe )
		goto _test_eof410;
case 410:
#line 9625 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr569;
		case 47: goto tr568;
		case 61: goto tr580;
		case 92: goto tr570;
		case 95: goto tr579;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr568;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr568;
		} else
			goto tr579;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr568;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr568;
		} else
			goto tr579;
	} else
		goto tr579;
	goto tr540;
tr580:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st411;
st411:
	if ( ++p == pe )
		goto _test_eof411;
case 411:
#line 9668 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr582;
		case 44: goto tr568;
		case 62: goto tr568;
		case 92: goto tr583;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr581;
	goto tr540;
tr584:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st412;
tr581:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st412;
st412:
	if ( ++p == pe )
		goto _test_eof412;
case 412:
#line 9698 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr569;
		case 44: goto tr585;
		case 62: goto tr586;
		case 92: goto tr587;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr584;
	goto tr540;
tr589:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st413;
tr575:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st413;
tr586:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st413;
st413:
	if ( ++p == pe )
		goto _test_eof413;
case 413:
#line 9738 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr47;
		case 34: goto tr569;
		case 92: goto tr570;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr568;
	goto tr540;
tr587:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st414;
tr583:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st414;
st414:
	if ( ++p == pe )
		goto _test_eof414;
case 414:
#line 9767 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr573;
		case 44: goto tr585;
		case 62: goto tr586;
		case 92: goto tr587;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr584;
	goto tr540;
tr582:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st415;
st415:
	if ( ++p == pe )
		goto _test_eof415;
case 415:
#line 9787 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr566;
		case 44: goto tr588;
		case 62: goto tr589;
		case 92: goto tr567;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr565;
	goto tr540;
tr32:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st416;
st416:
	if ( ++p == pe )
		goto _test_eof416;
case 416:
#line 9811 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 61: goto tr35;
		case 101: goto tr591;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr34;
	goto tr590;
tr591:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st417;
st417:
	if ( ++p == pe )
		goto _test_eof417;
case 417:
#line 9829 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 61: goto tr35;
		case 100: goto tr592;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr34;
	goto tr590;
tr592:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st418;
st418:
	if ( ++p == pe )
		goto _test_eof418;
case 418:
#line 9847 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 61: goto tr35;
		case 105: goto tr593;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr34;
	goto tr590;
tr593:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st419;
st419:
	if ( ++p == pe )
		goto _test_eof419;
case 419:
#line 9865 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 61: goto tr35;
		case 103: goto tr594;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr34;
	goto tr590;
tr594:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st420;
st420:
	if ( ++p == pe )
		goto _test_eof420;
case 420:
#line 9883 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 61: goto tr35;
		case 114: goto tr595;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr34;
	goto tr590;
tr595:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st421;
st421:
	if ( ++p == pe )
		goto _test_eof421;
case 421:
#line 9901 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 61: goto tr35;
		case 101: goto tr596;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr34;
	goto tr590;
tr596:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st422;
st422:
	if ( ++p == pe )
		goto _test_eof422;
case 422:
#line 9919 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 61: goto tr35;
		case 101: goto tr597;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr34;
	goto tr590;
tr597:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st423;
st423:
	if ( ++p == pe )
		goto _test_eof423;
case 423:
#line 9937 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 61: goto tr35;
		case 68: goto tr598;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr34;
	goto tr590;
tr598:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st424;
st424:
	if ( ++p == pe )
		goto _test_eof424;
case 424:
#line 9955 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 61: goto tr35;
		case 66: goto st425;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr34;
	goto tr590;
st425:
	if ( ++p == pe )
		goto _test_eof425;
case 425:
	if ( (*p) == 61 )
		goto tr600;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr34;
	goto tr590;
tr600:
#line 131 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "pedigreeDB");
    }
	goto st426;
st426:
	if ( ++p == pe )
		goto _test_eof426;
case 426:
#line 9982 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 60 )
		goto st427;
	goto tr590;
st427:
	if ( ++p == pe )
		goto _test_eof427;
case 427:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr603;
	} else if ( (*p) >= 65 )
		goto tr603;
	goto tr602;
tr603:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st428;
st428:
	if ( ++p == pe )
		goto _test_eof428;
case 428:
#line 10006 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr602;
		case 35: goto tr602;
		case 47: goto tr602;
		case 58: goto tr602;
		case 63: goto tr602;
	}
	goto st429;
st429:
	if ( ++p == pe )
		goto _test_eof429;
case 429:
	switch( (*p) ) {
		case 10: goto tr602;
		case 35: goto tr602;
		case 47: goto tr602;
		case 58: goto st430;
		case 63: goto tr602;
	}
	goto st429;
st430:
	if ( ++p == pe )
		goto _test_eof430;
case 430:
	if ( (*p) == 47 )
		goto st431;
	goto tr602;
st431:
	if ( ++p == pe )
		goto _test_eof431;
case 431:
	if ( (*p) == 47 )
		goto st432;
	goto tr602;
st432:
	if ( ++p == pe )
		goto _test_eof432;
case 432:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr608;
	} else if ( (*p) >= 65 )
		goto tr608;
	goto tr602;
tr608:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st433;
st433:
	if ( ++p == pe )
		goto _test_eof433;
case 433:
#line 10061 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr602;
		case 62: goto tr609;
	}
	goto tr608;
tr609:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st434;
st434:
	if ( ++p == pe )
		goto _test_eof434;
case 434:
#line 10081 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr47;
		case 62: goto tr609;
	}
	goto tr608;
st435:
	if ( ++p == pe )
		goto _test_eof435;
case 435:
	if ( (*p) == 72 )
		goto st436;
	goto tr610;
st436:
	if ( ++p == pe )
		goto _test_eof436;
case 436:
	if ( (*p) == 82 )
		goto st437;
	goto tr610;
st437:
	if ( ++p == pe )
		goto _test_eof437;
case 437:
	if ( (*p) == 79 )
		goto st438;
	goto tr610;
st438:
	if ( ++p == pe )
		goto _test_eof438;
case 438:
	if ( (*p) == 77 )
		goto st439;
	goto tr610;
st439:
	if ( ++p == pe )
		goto _test_eof439;
case 439:
	if ( (*p) == 9 )
		goto st440;
	goto tr610;
st440:
	if ( ++p == pe )
		goto _test_eof440;
case 440:
	if ( (*p) == 80 )
		goto st441;
	goto tr610;
st441:
	if ( ++p == pe )
		goto _test_eof441;
case 441:
	if ( (*p) == 79 )
		goto st442;
	goto tr610;
st442:
	if ( ++p == pe )
		goto _test_eof442;
case 442:
	if ( (*p) == 83 )
		goto st443;
	goto tr610;
st443:
	if ( ++p == pe )
		goto _test_eof443;
case 443:
	if ( (*p) == 9 )
		goto st444;
	goto tr610;
st444:
	if ( ++p == pe )
		goto _test_eof444;
case 444:
	if ( (*p) == 73 )
		goto st445;
	goto tr610;
st445:
	if ( ++p == pe )
		goto _test_eof445;
case 445:
	if ( (*p) == 68 )
		goto st446;
	goto tr610;
st446:
	if ( ++p == pe )
		goto _test_eof446;
case 446:
	if ( (*p) == 9 )
		goto st447;
	goto tr610;
st447:
	if ( ++p == pe )
		goto _test_eof447;
case 447:
	if ( (*p) == 82 )
		goto st448;
	goto tr610;
st448:
	if ( ++p == pe )
		goto _test_eof448;
case 448:
	if ( (*p) == 69 )
		goto st449;
	goto tr610;
st449:
	if ( ++p == pe )
		goto _test_eof449;
case 449:
	if ( (*p) == 70 )
		goto st450;
	goto tr610;
st450:
	if ( ++p == pe )
		goto _test_eof450;
case 450:
	if ( (*p) == 9 )
		goto st451;
	goto tr610;
st451:
	if ( ++p == pe )
		goto _test_eof451;
case 451:
	if ( (*p) == 65 )
		goto st452;
	goto tr610;
st452:
	if ( ++p == pe )
		goto _test_eof452;
case 452:
	if ( (*p) == 76 )
		goto st453;
	goto tr610;
st453:
	if ( ++p == pe )
		goto _test_eof453;
case 453:
	if ( (*p) == 84 )
		goto st454;
	goto tr610;
st454:
	if ( ++p == pe )
		goto _test_eof454;
case 454:
	if ( (*p) == 9 )
		goto st455;
	goto tr610;
st455:
	if ( ++p == pe )
		goto _test_eof455;
case 455:
	if ( (*p) == 81 )
		goto st456;
	goto tr610;
st456:
	if ( ++p == pe )
		goto _test_eof456;
case 456:
	if ( (*p) == 85 )
		goto st457;
	goto tr610;
st457:
	if ( ++p == pe )
		goto _test_eof457;
case 457:
	if ( (*p) == 65 )
		goto st458;
	goto tr610;
st458:
	if ( ++p == pe )
		goto _test_eof458;
case 458:
	if ( (*p) == 76 )
		goto st459;
	goto tr610;
st459:
	if ( ++p == pe )
		goto _test_eof459;
case 459:
	if ( (*p) == 9 )
		goto st460;
	goto tr610;
st460:
	if ( ++p == pe )
		goto _test_eof460;
case 460:
	if ( (*p) == 70 )
		goto st461;
	goto tr610;
st461:
	if ( ++p == pe )
		goto _test_eof461;
case 461:
	if ( (*p) == 73 )
		goto st462;
	goto tr610;
st462:
	if ( ++p == pe )
		goto _test_eof462;
case 462:
	if ( (*p) == 76 )
		goto st463;
	goto tr610;
st463:
	if ( ++p == pe )
		goto _test_eof463;
case 463:
	if ( (*p) == 84 )
		goto st464;
	goto tr610;
st464:
	if ( ++p == pe )
		goto _test_eof464;
case 464:
	if ( (*p) == 69 )
		goto st465;
	goto tr610;
st465:
	if ( ++p == pe )
		goto _test_eof465;
case 465:
	if ( (*p) == 82 )
		goto st466;
	goto tr610;
st466:
	if ( ++p == pe )
		goto _test_eof466;
case 466:
	if ( (*p) == 9 )
		goto st467;
	goto tr610;
st467:
	if ( ++p == pe )
		goto _test_eof467;
case 467:
	if ( (*p) == 73 )
		goto st468;
	goto tr610;
st468:
	if ( ++p == pe )
		goto _test_eof468;
case 468:
	if ( (*p) == 78 )
		goto st469;
	goto tr610;
st469:
	if ( ++p == pe )
		goto _test_eof469;
case 469:
	if ( (*p) == 70 )
		goto st470;
	goto tr610;
st470:
	if ( ++p == pe )
		goto _test_eof470;
case 470:
	if ( (*p) == 79 )
		goto st471;
	goto tr610;
st471:
	if ( ++p == pe )
		goto _test_eof471;
case 471:
	switch( (*p) ) {
		case 9: goto st472;
		case 10: goto tr648;
	}
	goto tr610;
st472:
	if ( ++p == pe )
		goto _test_eof472;
case 472:
	if ( (*p) == 70 )
		goto st473;
	goto tr649;
st473:
	if ( ++p == pe )
		goto _test_eof473;
case 473:
	if ( (*p) == 79 )
		goto st474;
	goto tr649;
st474:
	if ( ++p == pe )
		goto _test_eof474;
case 474:
	if ( (*p) == 82 )
		goto st475;
	goto tr649;
st475:
	if ( ++p == pe )
		goto _test_eof475;
case 475:
	if ( (*p) == 77 )
		goto st476;
	goto tr649;
st476:
	if ( ++p == pe )
		goto _test_eof476;
case 476:
	if ( (*p) == 65 )
		goto st477;
	goto tr649;
st477:
	if ( ++p == pe )
		goto _test_eof477;
case 477:
	if ( (*p) == 84 )
		goto st478;
	goto tr649;
st478:
	if ( ++p == pe )
		goto _test_eof478;
case 478:
	if ( (*p) == 9 )
		goto st479;
	goto tr649;
tr658:
#line 179 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_sample_name(*this);
    }
	goto st479;
st479:
	if ( ++p == pe )
		goto _test_eof479;
case 479:
#line 10407 "inc/vcf/validator_detail.hpp"
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr657;
	goto tr649;
tr657:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st480;
tr660:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st480;
st480:
	if ( ++p == pe )
		goto _test_eof480;
case 480:
#line 10431 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr658;
		case 10: goto tr659;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr660;
	goto tr649;
tr648:
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
	goto st704;
tr659:
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
	goto st704;
st704:
	if ( ++p == pe )
		goto _test_eof704;
case 704:
#line 10479 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 60 )
		goto tr942;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr941;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr941;
	} else
		goto tr941;
	goto tr940;
tr943:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st481;
tr941:
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
	goto st481;
st481:
	if ( ++p == pe )
		goto _test_eof481;
case 481:
#line 10523 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr662;
		case 59: goto tr663;
		case 61: goto tr663;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr663;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr663;
		} else
			goto tr664;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr663;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr663;
		} else
			goto tr664;
	} else
		goto tr664;
	goto tr661;
tr662:
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
	goto st482;
tr741:
#line 189 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 53 "src/vcf/vcf_v41.ragel"
	{
        ++n_columns;
    }
	goto st482;
st482:
	if ( ++p == pe )
		goto _test_eof482;
case 482:
#line 10578 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 45 )
		goto tr666;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr667;
	goto tr665;
tr666:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st483;
st483:
	if ( ++p == pe )
		goto _test_eof483;
case 483:
#line 10594 "inc/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr668;
	goto tr665;
tr667:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st484;
tr668:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st484;
st484:
	if ( ++p == pe )
		goto _test_eof484;
case 484:
#line 10618 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 9 )
		goto tr669;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr668;
	goto tr665;
tr674:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st485;
tr669:
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
	goto st485;
st485:
	if ( ++p == pe )
		goto _test_eof485;
case 485:
#line 10648 "inc/vcf/validator_detail.hpp"
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr671;
	} else if ( (*p) >= 33 )
		goto tr671;
	goto tr670;
tr671:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st486;
tr673:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st486;
st486:
	if ( ++p == pe )
		goto _test_eof486;
case 486:
#line 10675 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr672;
		case 59: goto tr674;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr673;
	goto tr670;
tr672:
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
	goto st487;
st487:
	if ( ++p == pe )
		goto _test_eof487;
case 487:
#line 10701 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 65: goto tr676;
		case 67: goto tr676;
		case 71: goto tr676;
		case 78: goto tr676;
		case 84: goto tr676;
		case 97: goto tr676;
		case 99: goto tr676;
		case 103: goto tr676;
		case 110: goto tr676;
		case 116: goto tr676;
	}
	goto tr675;
tr676:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st488;
tr678:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st488;
st488:
	if ( ++p == pe )
		goto _test_eof488;
case 488:
#line 10735 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr677;
		case 65: goto tr678;
		case 67: goto tr678;
		case 71: goto tr678;
		case 78: goto tr678;
		case 84: goto tr678;
		case 97: goto tr678;
		case 99: goto tr678;
		case 103: goto tr678;
		case 110: goto tr678;
		case 116: goto tr678;
	}
	goto tr675;
tr677:
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
	goto st489;
st489:
	if ( ++p == pe )
		goto _test_eof489;
case 489:
#line 10768 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 42: goto tr680;
		case 46: goto tr681;
		case 60: goto tr682;
		case 65: goto tr683;
		case 67: goto tr683;
		case 71: goto tr683;
		case 78: goto tr683;
		case 84: goto tr683;
		case 91: goto tr684;
		case 93: goto tr685;
		case 97: goto tr683;
		case 99: goto tr683;
		case 103: goto tr683;
		case 110: goto tr683;
		case 116: goto tr683;
	}
	goto tr679;
tr680:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st490;
tr887:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st490;
st490:
	if ( ++p == pe )
		goto _test_eof490;
case 490:
#line 10807 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr686;
		case 44: goto tr687;
	}
	goto tr679;
tr686:
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
	goto st491;
st491:
	if ( ++p == pe )
		goto _test_eof491;
case 491:
#line 10831 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 45: goto tr689;
		case 46: goto tr690;
		case 48: goto tr691;
	}
	if ( 49 <= (*p) && (*p) <= 57 )
		goto tr692;
	goto tr688;
tr689:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st492;
st492:
	if ( ++p == pe )
		goto _test_eof492;
case 492:
#line 10854 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 48 )
		goto tr693;
	if ( 49 <= (*p) && (*p) <= 57 )
		goto tr694;
	goto tr688;
tr691:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st493;
tr693:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st493;
st493:
	if ( ++p == pe )
		goto _test_eof493;
case 493:
#line 10880 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr695;
		case 46: goto tr696;
		case 69: goto tr697;
		case 101: goto tr697;
	}
	goto tr688;
tr695:
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
	goto st494;
st494:
	if ( ++p == pe )
		goto _test_eof494;
case 494:
#line 10906 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 46: goto tr700;
		case 58: goto tr699;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr699;
		} else if ( (*p) > 57 ) {
			if ( 60 <= (*p) && (*p) <= 64 )
				goto tr699;
		} else
			goto tr701;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr699;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr699;
		} else
			goto tr701;
	} else
		goto tr701;
	goto tr698;
tr699:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st495;
st495:
	if ( ++p == pe )
		goto _test_eof495;
case 495:
#line 10942 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 58 )
		goto st495;
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto st495;
		} else if ( (*p) > 57 ) {
			if ( 60 <= (*p) && (*p) <= 64 )
				goto st495;
		} else
			goto tr703;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st495;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st495;
		} else
			goto tr703;
	} else
		goto tr703;
	goto tr698;
tr701:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st496;
tr703:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st496;
st496:
	if ( ++p == pe )
		goto _test_eof496;
case 496:
#line 10986 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr704;
		case 59: goto tr705;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr703;
	goto tr698;
tr704:
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
	goto st497;
st497:
	if ( ++p == pe )
		goto _test_eof497;
case 497:
#line 11012 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 46: goto tr708;
		case 49: goto tr710;
		case 58: goto tr707;
		case 60: goto tr707;
		case 65: goto tr711;
		case 66: goto tr712;
		case 67: goto tr713;
		case 68: goto tr714;
		case 69: goto tr715;
		case 72: goto tr716;
		case 77: goto tr717;
		case 78: goto tr718;
		case 83: goto tr719;
		case 86: goto tr720;
	}
	if ( (*p) < 70 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr707;
		} else if ( (*p) > 57 ) {
			if ( 62 <= (*p) && (*p) <= 64 )
				goto tr707;
		} else
			goto tr709;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr707;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr707;
		} else
			goto tr709;
	} else
		goto tr709;
	goto tr706;
tr707:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st498;
tr721:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st498;
st498:
	if ( ++p == pe )
		goto _test_eof498;
case 498:
#line 11070 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 58: goto tr721;
		case 60: goto tr721;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr721;
		} else if ( (*p) > 57 ) {
			if ( 62 <= (*p) && (*p) <= 64 )
				goto tr721;
		} else
			goto tr722;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr721;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr721;
		} else
			goto tr722;
	} else
		goto tr722;
	goto tr706;
tr709:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st499;
tr722:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st499;
st499:
	if ( ++p == pe )
		goto _test_eof499;
case 499:
#line 11116 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 59: goto tr725;
		case 61: goto tr726;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr722;
	goto tr706;
tr731:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st500;
tr723:
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
	goto st500;
st500:
	if ( ++p == pe )
		goto _test_eof500;
case 500:
#line 11150 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 95 )
		goto tr728;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr728;
	} else if ( (*p) >= 65 )
		goto tr728;
	goto tr727;
tr728:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st501;
tr730:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st501;
st501:
	if ( ++p == pe )
		goto _test_eof501;
case 501:
#line 11179 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr729;
		case 46: goto tr730;
		case 58: goto tr731;
		case 95: goto tr730;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr730;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr730;
	} else
		goto tr730;
	goto tr727;
tr729:
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
	goto st502;
st502:
	if ( ++p == pe )
		goto _test_eof502;
case 502:
#line 11213 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 46 )
		goto tr733;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr734;
	goto tr732;
tr733:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st503;
tr742:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st503;
st503:
	if ( ++p == pe )
		goto _test_eof503;
case 503:
#line 11239 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr729;
		case 10: goto tr724;
		case 47: goto tr735;
		case 58: goto tr736;
		case 124: goto tr735;
	}
	goto tr732;
tr724:
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
	goto st705;
st705:
	if ( ++p == pe )
		goto _test_eof705;
case 705:
#line 11285 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 60 )
		goto st504;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr943;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr943;
	} else
		goto tr943;
	goto tr661;
tr942:
#line 70 "src/vcf/vcf_v41.ragel"
	{
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (ParsingWarning warn) {
          ErrorPolicy::handle_meta_section_warning(*this, warn.what());
        }
    }
	goto st504;
st504:
	if ( ++p == pe )
		goto _test_eof504;
case 504:
#line 11311 "inc/vcf/validator_detail.hpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr737;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr737;
	} else
		goto tr737;
	goto tr661;
tr737:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st505;
st505:
	if ( ++p == pe )
		goto _test_eof505;
case 505:
#line 11335 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr738;
		case 62: goto tr740;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr738;
		} else if ( (*p) > 57 ) {
			if ( 61 <= (*p) && (*p) <= 64 )
				goto tr738;
		} else
			goto tr739;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr738;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr738;
		} else
			goto tr739;
	} else
		goto tr739;
	goto tr661;
tr738:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st506;
st506:
	if ( ++p == pe )
		goto _test_eof506;
case 506:
#line 11371 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr738;
		case 61: goto tr738;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr738;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr738;
		} else
			goto tr739;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr738;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr738;
		} else
			goto tr739;
	} else
		goto tr739;
	goto tr661;
tr739:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st507;
st507:
	if ( ++p == pe )
		goto _test_eof507;
case 507:
#line 11407 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr739;
		case 62: goto tr740;
	}
	if ( (*p) > 57 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr739;
	} else if ( (*p) >= 33 )
		goto tr739;
	goto tr661;
tr740:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st508;
st508:
	if ( ++p == pe )
		goto _test_eof508;
case 508:
#line 11428 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 9 )
		goto tr741;
	goto tr661;
tr735:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st509;
st509:
	if ( ++p == pe )
		goto _test_eof509;
case 509:
#line 11442 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 46 )
		goto tr742;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr743;
	goto tr732;
tr734:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st510;
tr743:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st510;
st510:
	if ( ++p == pe )
		goto _test_eof510;
case 510:
#line 11468 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr729;
		case 10: goto tr724;
		case 47: goto tr735;
		case 58: goto tr736;
		case 124: goto tr735;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr743;
	goto tr732;
tr736:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st511;
st511:
	if ( ++p == pe )
		goto _test_eof511;
case 511:
#line 11489 "inc/vcf/validator_detail.hpp"
	if ( (*p) > 57 ) {
		if ( 59 <= (*p) && (*p) <= 126 )
			goto tr745;
	} else if ( (*p) >= 33 )
		goto tr745;
	goto tr744;
tr745:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st512;
st512:
	if ( ++p == pe )
		goto _test_eof512;
case 512:
#line 11506 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr729;
		case 10: goto tr724;
		case 58: goto tr736;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr745;
	goto tr744;
tr725:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st513;
st513:
	if ( ++p == pe )
		goto _test_eof513;
case 513:
#line 11525 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 49: goto tr710;
		case 58: goto tr707;
		case 60: goto tr707;
		case 65: goto tr711;
		case 66: goto tr712;
		case 67: goto tr713;
		case 68: goto tr714;
		case 69: goto tr715;
		case 72: goto tr716;
		case 77: goto tr717;
		case 78: goto tr718;
		case 83: goto tr719;
		case 86: goto tr720;
	}
	if ( (*p) < 70 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr707;
		} else if ( (*p) > 57 ) {
			if ( 62 <= (*p) && (*p) <= 64 )
				goto tr707;
		} else
			goto tr709;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr707;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr707;
		} else
			goto tr709;
	} else
		goto tr709;
	goto tr706;
tr710:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st514;
st514:
	if ( ++p == pe )
		goto _test_eof514;
case 514:
#line 11576 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 48: goto tr746;
		case 59: goto tr725;
		case 61: goto tr726;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr722;
	goto tr706;
tr746:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st515;
st515:
	if ( ++p == pe )
		goto _test_eof515;
case 515:
#line 11597 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 48: goto tr747;
		case 59: goto tr725;
		case 61: goto tr726;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr722;
	goto tr706;
tr747:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st516;
st516:
	if ( ++p == pe )
		goto _test_eof516;
case 516:
#line 11618 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 48: goto tr748;
		case 59: goto tr725;
		case 61: goto tr726;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr722;
	goto tr706;
tr748:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st517;
st517:
	if ( ++p == pe )
		goto _test_eof517;
case 517:
#line 11639 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 59: goto tr725;
		case 61: goto tr726;
		case 71: goto tr749;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr722;
	goto tr706;
tr726:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st518;
st518:
	if ( ++p == pe )
		goto _test_eof518;
case 518:
#line 11660 "inc/vcf/validator_detail.hpp"
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr751;
	} else if ( (*p) >= 33 )
		goto tr751;
	goto tr750;
tr751:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st519;
st519:
	if ( ++p == pe )
		goto _test_eof519;
case 519:
#line 11677 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 59: goto tr725;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr751;
	goto tr750;
tr749:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st520;
st520:
	if ( ++p == pe )
		goto _test_eof520;
case 520:
#line 11696 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 59: goto tr725;
		case 61: goto tr753;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr722;
	goto tr752;
tr753:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st521;
st521:
	if ( ++p == pe )
		goto _test_eof521;
case 521:
#line 11716 "inc/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 49 )
		goto tr755;
	goto tr754;
tr755:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st522;
st522:
	if ( ++p == pe )
		goto _test_eof522;
case 522:
#line 11730 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 59: goto tr725;
	}
	goto tr754;
tr711:
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
#line 11751 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 59: goto tr725;
		case 61: goto tr726;
		case 65: goto tr756;
		case 67: goto tr757;
		case 70: goto tr758;
		case 78: goto tr759;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr722;
	goto tr706;
tr756:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st524;
st524:
	if ( ++p == pe )
		goto _test_eof524;
case 524:
#line 11775 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 61 )
		goto tr760;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr722;
	} else if ( (*p) >= 33 )
		goto tr722;
	goto tr706;
tr760:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st525;
st525:
	if ( ++p == pe )
		goto _test_eof525;
case 525:
#line 11794 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 65: goto tr763;
		case 67: goto tr763;
		case 71: goto tr763;
		case 78: goto tr763;
		case 84: goto tr763;
		case 97: goto tr763;
		case 99: goto tr763;
		case 103: goto tr763;
		case 110: goto tr763;
		case 116: goto tr763;
	}
	if ( 45 <= (*p) && (*p) <= 46 )
		goto tr762;
	goto tr761;
tr762:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st526;
st526:
	if ( ++p == pe )
		goto _test_eof526;
case 526:
#line 11820 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 59: goto tr725;
	}
	goto tr761;
tr763:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st527;
st527:
	if ( ++p == pe )
		goto _test_eof527;
case 527:
#line 11837 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 59: goto tr725;
		case 65: goto tr763;
		case 67: goto tr763;
		case 71: goto tr763;
		case 78: goto tr763;
		case 84: goto tr763;
		case 97: goto tr763;
		case 99: goto tr763;
		case 103: goto tr763;
		case 110: goto tr763;
		case 116: goto tr763;
	}
	goto tr761;
tr757:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st528;
st528:
	if ( ++p == pe )
		goto _test_eof528;
case 528:
#line 11864 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 61 )
		goto tr764;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr722;
	} else if ( (*p) >= 33 )
		goto tr722;
	goto tr706;
tr764:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st529;
st529:
	if ( ++p == pe )
		goto _test_eof529;
case 529:
#line 11883 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 45 )
		goto tr766;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr767;
	goto tr765;
tr766:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st530;
st530:
	if ( ++p == pe )
		goto _test_eof530;
case 530:
#line 11899 "inc/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr767;
	goto tr765;
tr767:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st531;
st531:
	if ( ++p == pe )
		goto _test_eof531;
case 531:
#line 11913 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 44: goto tr764;
		case 59: goto tr725;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr767;
	goto tr765;
tr758:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st532;
st532:
	if ( ++p == pe )
		goto _test_eof532;
case 532:
#line 11933 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 61 )
		goto tr768;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr722;
	} else if ( (*p) >= 33 )
		goto tr722;
	goto tr706;
tr768:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st533;
st533:
	if ( ++p == pe )
		goto _test_eof533;
case 533:
#line 11952 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 45: goto tr770;
		case 48: goto tr771;
	}
	if ( 49 <= (*p) && (*p) <= 57 )
		goto tr772;
	goto tr769;
tr770:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st534;
st534:
	if ( ++p == pe )
		goto _test_eof534;
case 534:
#line 11970 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 48 )
		goto tr771;
	if ( 49 <= (*p) && (*p) <= 57 )
		goto tr772;
	goto tr769;
tr771:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st535;
st535:
	if ( ++p == pe )
		goto _test_eof535;
case 535:
#line 11986 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 44: goto tr768;
		case 46: goto tr773;
		case 59: goto tr725;
		case 69: goto tr774;
		case 101: goto tr774;
	}
	goto tr769;
tr773:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st536;
st536:
	if ( ++p == pe )
		goto _test_eof536;
case 536:
#line 12007 "inc/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr775;
	goto tr769;
tr775:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st537;
st537:
	if ( ++p == pe )
		goto _test_eof537;
case 537:
#line 12021 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 44: goto tr768;
		case 59: goto tr725;
		case 69: goto tr774;
		case 101: goto tr774;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr775;
	goto tr769;
tr774:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st538;
st538:
	if ( ++p == pe )
		goto _test_eof538;
case 538:
#line 12043 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 43: goto tr776;
		case 45: goto tr776;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr777;
	goto tr769;
tr776:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st539;
st539:
	if ( ++p == pe )
		goto _test_eof539;
case 539:
#line 12061 "inc/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr777;
	goto tr769;
tr777:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st540;
st540:
	if ( ++p == pe )
		goto _test_eof540;
case 540:
#line 12075 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 44: goto tr768;
		case 59: goto tr725;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr777;
	goto tr769;
tr772:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st541;
st541:
	if ( ++p == pe )
		goto _test_eof541;
case 541:
#line 12095 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 44: goto tr768;
		case 46: goto tr773;
		case 59: goto tr725;
		case 69: goto tr774;
		case 101: goto tr774;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr772;
	goto tr769;
tr759:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st542;
st542:
	if ( ++p == pe )
		goto _test_eof542;
case 542:
#line 12118 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 61 )
		goto tr778;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr722;
	} else if ( (*p) >= 33 )
		goto tr722;
	goto tr706;
tr778:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st543;
st543:
	if ( ++p == pe )
		goto _test_eof543;
case 543:
#line 12137 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 45 )
		goto tr780;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr781;
	goto tr779;
tr780:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st544;
st544:
	if ( ++p == pe )
		goto _test_eof544;
case 544:
#line 12153 "inc/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr781;
	goto tr779;
tr781:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st545;
st545:
	if ( ++p == pe )
		goto _test_eof545;
case 545:
#line 12167 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 59: goto tr725;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr781;
	goto tr779;
tr712:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st546;
st546:
	if ( ++p == pe )
		goto _test_eof546;
case 546:
#line 12190 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 59: goto tr725;
		case 61: goto tr726;
		case 81: goto tr782;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr722;
	goto tr706;
tr782:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st547;
st547:
	if ( ++p == pe )
		goto _test_eof547;
case 547:
#line 12211 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 61 )
		goto tr783;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr722;
	} else if ( (*p) >= 33 )
		goto tr722;
	goto tr706;
tr783:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st548;
st548:
	if ( ++p == pe )
		goto _test_eof548;
case 548:
#line 12230 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 45: goto tr785;
		case 48: goto tr786;
	}
	if ( 49 <= (*p) && (*p) <= 57 )
		goto tr787;
	goto tr784;
tr785:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st549;
st549:
	if ( ++p == pe )
		goto _test_eof549;
case 549:
#line 12248 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 48 )
		goto tr786;
	if ( 49 <= (*p) && (*p) <= 57 )
		goto tr787;
	goto tr784;
tr786:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st550;
st550:
	if ( ++p == pe )
		goto _test_eof550;
case 550:
#line 12264 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 46: goto tr788;
		case 59: goto tr725;
		case 69: goto tr789;
		case 101: goto tr789;
	}
	goto tr784;
tr788:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st551;
st551:
	if ( ++p == pe )
		goto _test_eof551;
case 551:
#line 12284 "inc/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr790;
	goto tr784;
tr790:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st552;
st552:
	if ( ++p == pe )
		goto _test_eof552;
case 552:
#line 12298 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 59: goto tr725;
		case 69: goto tr789;
		case 101: goto tr789;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr790;
	goto tr784;
tr789:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st553;
st553:
	if ( ++p == pe )
		goto _test_eof553;
case 553:
#line 12319 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 43: goto tr791;
		case 45: goto tr791;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr792;
	goto tr784;
tr791:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st554;
st554:
	if ( ++p == pe )
		goto _test_eof554;
case 554:
#line 12337 "inc/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr792;
	goto tr784;
tr792:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st555;
st555:
	if ( ++p == pe )
		goto _test_eof555;
case 555:
#line 12351 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 59: goto tr725;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr792;
	goto tr784;
tr787:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st556;
st556:
	if ( ++p == pe )
		goto _test_eof556;
case 556:
#line 12370 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 46: goto tr788;
		case 59: goto tr725;
		case 69: goto tr789;
		case 101: goto tr789;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr787;
	goto tr784;
tr713:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st557;
st557:
	if ( ++p == pe )
		goto _test_eof557;
case 557:
#line 12396 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 59: goto tr725;
		case 61: goto tr726;
		case 73: goto tr793;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr722;
	goto tr706;
tr793:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st558;
st558:
	if ( ++p == pe )
		goto _test_eof558;
case 558:
#line 12417 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 59: goto tr725;
		case 61: goto tr726;
		case 71: goto tr794;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr722;
	goto tr706;
tr794:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st559;
st559:
	if ( ++p == pe )
		goto _test_eof559;
case 559:
#line 12438 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 59: goto tr725;
		case 61: goto tr726;
		case 65: goto tr795;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr722;
	goto tr706;
tr795:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st560;
st560:
	if ( ++p == pe )
		goto _test_eof560;
case 560:
#line 12459 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 59: goto tr725;
		case 61: goto tr726;
		case 82: goto tr796;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr722;
	goto tr706;
tr796:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st561;
st561:
	if ( ++p == pe )
		goto _test_eof561;
case 561:
#line 12480 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 61 )
		goto tr797;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr722;
	} else if ( (*p) >= 33 )
		goto tr722;
	goto tr706;
tr797:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st562;
st562:
	if ( ++p == pe )
		goto _test_eof562;
case 562:
#line 12499 "inc/vcf/validator_detail.hpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr799;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr799;
	} else
		goto tr799;
	goto tr798;
tr799:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st563;
st563:
	if ( ++p == pe )
		goto _test_eof563;
case 563:
#line 12519 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 59: goto tr725;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr799;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr799;
	} else
		goto tr799;
	goto tr798;
tr714:
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
#line 12548 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 59: goto tr725;
		case 61: goto tr726;
		case 66: goto tr800;
		case 80: goto tr801;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr722;
	goto tr706;
tr800:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st565;
st565:
	if ( ++p == pe )
		goto _test_eof565;
case 565:
#line 12570 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 59: goto tr725;
		case 61: goto tr803;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr722;
	goto tr802;
tr803:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st566;
st566:
	if ( ++p == pe )
		goto _test_eof566;
case 566:
#line 12590 "inc/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 49 )
		goto tr805;
	goto tr804;
tr805:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st567;
st567:
	if ( ++p == pe )
		goto _test_eof567;
case 567:
#line 12604 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 59: goto tr725;
	}
	goto tr804;
tr801:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st568;
st568:
	if ( ++p == pe )
		goto _test_eof568;
case 568:
#line 12621 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 61 )
		goto tr806;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr722;
	} else if ( (*p) >= 33 )
		goto tr722;
	goto tr706;
tr806:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st569;
st569:
	if ( ++p == pe )
		goto _test_eof569;
case 569:
#line 12640 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 45 )
		goto tr808;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr809;
	goto tr807;
tr808:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st570;
st570:
	if ( ++p == pe )
		goto _test_eof570;
case 570:
#line 12656 "inc/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr809;
	goto tr807;
tr809:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st571;
st571:
	if ( ++p == pe )
		goto _test_eof571;
case 571:
#line 12670 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 59: goto tr725;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr809;
	goto tr807;
tr715:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st572;
st572:
	if ( ++p == pe )
		goto _test_eof572;
case 572:
#line 12693 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 59: goto tr725;
		case 61: goto tr726;
		case 78: goto tr810;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr722;
	goto tr706;
tr810:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st573;
st573:
	if ( ++p == pe )
		goto _test_eof573;
case 573:
#line 12714 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 59: goto tr725;
		case 61: goto tr726;
		case 68: goto tr811;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr722;
	goto tr706;
tr811:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st574;
st574:
	if ( ++p == pe )
		goto _test_eof574;
case 574:
#line 12735 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 61 )
		goto tr812;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr722;
	} else if ( (*p) >= 33 )
		goto tr722;
	goto tr706;
tr812:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st575;
st575:
	if ( ++p == pe )
		goto _test_eof575;
case 575:
#line 12754 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 45 )
		goto tr814;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr815;
	goto tr813;
tr814:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st576;
st576:
	if ( ++p == pe )
		goto _test_eof576;
case 576:
#line 12770 "inc/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr815;
	goto tr813;
tr815:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st577;
st577:
	if ( ++p == pe )
		goto _test_eof577;
case 577:
#line 12784 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 59: goto tr725;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr815;
	goto tr813;
tr716:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st578;
st578:
	if ( ++p == pe )
		goto _test_eof578;
case 578:
#line 12807 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 50: goto tr816;
		case 51: goto tr817;
		case 59: goto tr725;
		case 61: goto tr726;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr722;
	goto tr706;
tr816:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st579;
st579:
	if ( ++p == pe )
		goto _test_eof579;
case 579:
#line 12829 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 59: goto tr725;
		case 61: goto tr819;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr722;
	goto tr818;
tr819:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st580;
st580:
	if ( ++p == pe )
		goto _test_eof580;
case 580:
#line 12849 "inc/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 49 )
		goto tr821;
	goto tr820;
tr821:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st581;
st581:
	if ( ++p == pe )
		goto _test_eof581;
case 581:
#line 12863 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 59: goto tr725;
	}
	goto tr820;
tr817:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st582;
st582:
	if ( ++p == pe )
		goto _test_eof582;
case 582:
#line 12880 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 59: goto tr725;
		case 61: goto tr823;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr722;
	goto tr822;
tr823:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st583;
st583:
	if ( ++p == pe )
		goto _test_eof583;
case 583:
#line 12900 "inc/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 49 )
		goto tr825;
	goto tr824;
tr825:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st584;
st584:
	if ( ++p == pe )
		goto _test_eof584;
case 584:
#line 12914 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 59: goto tr725;
	}
	goto tr824;
tr717:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st585;
st585:
	if ( ++p == pe )
		goto _test_eof585;
case 585:
#line 12935 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 59: goto tr725;
		case 61: goto tr726;
		case 81: goto tr826;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr722;
	goto tr706;
tr826:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st586;
st586:
	if ( ++p == pe )
		goto _test_eof586;
case 586:
#line 12956 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 48: goto tr827;
		case 61: goto tr828;
	}
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr722;
	} else if ( (*p) >= 33 )
		goto tr722;
	goto tr706;
tr827:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st587;
st587:
	if ( ++p == pe )
		goto _test_eof587;
case 587:
#line 12977 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 61 )
		goto tr829;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr722;
	} else if ( (*p) >= 33 )
		goto tr722;
	goto tr706;
tr829:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st588;
st588:
	if ( ++p == pe )
		goto _test_eof588;
case 588:
#line 12996 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 45 )
		goto tr831;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr832;
	goto tr830;
tr831:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st589;
st589:
	if ( ++p == pe )
		goto _test_eof589;
case 589:
#line 13012 "inc/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr832;
	goto tr830;
tr832:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st590;
st590:
	if ( ++p == pe )
		goto _test_eof590;
case 590:
#line 13026 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 59: goto tr725;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr832;
	goto tr830;
tr828:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st591;
st591:
	if ( ++p == pe )
		goto _test_eof591;
case 591:
#line 13045 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 45: goto tr834;
		case 48: goto tr835;
	}
	if ( 49 <= (*p) && (*p) <= 57 )
		goto tr836;
	goto tr833;
tr834:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st592;
st592:
	if ( ++p == pe )
		goto _test_eof592;
case 592:
#line 13063 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 48 )
		goto tr835;
	if ( 49 <= (*p) && (*p) <= 57 )
		goto tr836;
	goto tr833;
tr835:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st593;
st593:
	if ( ++p == pe )
		goto _test_eof593;
case 593:
#line 13079 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 46: goto tr837;
		case 59: goto tr725;
		case 69: goto tr838;
		case 101: goto tr838;
	}
	goto tr833;
tr837:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st594;
st594:
	if ( ++p == pe )
		goto _test_eof594;
case 594:
#line 13099 "inc/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr839;
	goto tr833;
tr839:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st595;
st595:
	if ( ++p == pe )
		goto _test_eof595;
case 595:
#line 13113 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 59: goto tr725;
		case 69: goto tr838;
		case 101: goto tr838;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr839;
	goto tr833;
tr838:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st596;
st596:
	if ( ++p == pe )
		goto _test_eof596;
case 596:
#line 13134 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 43: goto tr840;
		case 45: goto tr840;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr841;
	goto tr833;
tr840:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st597;
st597:
	if ( ++p == pe )
		goto _test_eof597;
case 597:
#line 13152 "inc/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr841;
	goto tr833;
tr841:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st598;
st598:
	if ( ++p == pe )
		goto _test_eof598;
case 598:
#line 13166 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 59: goto tr725;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr841;
	goto tr833;
tr836:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st599;
st599:
	if ( ++p == pe )
		goto _test_eof599;
case 599:
#line 13185 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 46: goto tr837;
		case 59: goto tr725;
		case 69: goto tr838;
		case 101: goto tr838;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr836;
	goto tr833;
tr718:
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
#line 13211 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 59: goto tr725;
		case 61: goto tr726;
		case 83: goto tr842;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr722;
	goto tr706;
tr842:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st601;
st601:
	if ( ++p == pe )
		goto _test_eof601;
case 601:
#line 13232 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 61 )
		goto tr843;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr722;
	} else if ( (*p) >= 33 )
		goto tr722;
	goto tr706;
tr843:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st602;
st602:
	if ( ++p == pe )
		goto _test_eof602;
case 602:
#line 13251 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 45 )
		goto tr845;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr846;
	goto tr844;
tr845:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st603;
st603:
	if ( ++p == pe )
		goto _test_eof603;
case 603:
#line 13267 "inc/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr846;
	goto tr844;
tr846:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st604;
st604:
	if ( ++p == pe )
		goto _test_eof604;
case 604:
#line 13281 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 59: goto tr725;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr846;
	goto tr844;
tr719:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st605;
st605:
	if ( ++p == pe )
		goto _test_eof605;
case 605:
#line 13304 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 59: goto tr725;
		case 61: goto tr726;
		case 66: goto tr847;
		case 79: goto tr848;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr722;
	goto tr706;
tr847:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st606;
st606:
	if ( ++p == pe )
		goto _test_eof606;
case 606:
#line 13326 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 61 )
		goto tr849;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr722;
	} else if ( (*p) >= 33 )
		goto tr722;
	goto tr706;
tr849:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st607;
st607:
	if ( ++p == pe )
		goto _test_eof607;
case 607:
#line 13345 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 45: goto tr851;
		case 48: goto tr852;
	}
	if ( 49 <= (*p) && (*p) <= 57 )
		goto tr853;
	goto tr850;
tr851:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st608;
st608:
	if ( ++p == pe )
		goto _test_eof608;
case 608:
#line 13363 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 48 )
		goto tr852;
	if ( 49 <= (*p) && (*p) <= 57 )
		goto tr853;
	goto tr850;
tr852:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st609;
st609:
	if ( ++p == pe )
		goto _test_eof609;
case 609:
#line 13379 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 46: goto tr854;
		case 59: goto tr725;
		case 69: goto tr855;
		case 101: goto tr855;
	}
	goto tr850;
tr854:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st610;
st610:
	if ( ++p == pe )
		goto _test_eof610;
case 610:
#line 13399 "inc/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr856;
	goto tr850;
tr856:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st611;
st611:
	if ( ++p == pe )
		goto _test_eof611;
case 611:
#line 13413 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 59: goto tr725;
		case 69: goto tr855;
		case 101: goto tr855;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr856;
	goto tr850;
tr855:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st612;
st612:
	if ( ++p == pe )
		goto _test_eof612;
case 612:
#line 13434 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 43: goto tr857;
		case 45: goto tr857;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr858;
	goto tr850;
tr857:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st613;
st613:
	if ( ++p == pe )
		goto _test_eof613;
case 613:
#line 13452 "inc/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr858;
	goto tr850;
tr858:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st614;
st614:
	if ( ++p == pe )
		goto _test_eof614;
case 614:
#line 13466 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 59: goto tr725;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr858;
	goto tr850;
tr853:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st615;
st615:
	if ( ++p == pe )
		goto _test_eof615;
case 615:
#line 13485 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 46: goto tr854;
		case 59: goto tr725;
		case 69: goto tr855;
		case 101: goto tr855;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr853;
	goto tr850;
tr848:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st616;
st616:
	if ( ++p == pe )
		goto _test_eof616;
case 616:
#line 13507 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 59: goto tr725;
		case 61: goto tr726;
		case 77: goto tr859;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr722;
	goto tr706;
tr859:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st617;
st617:
	if ( ++p == pe )
		goto _test_eof617;
case 617:
#line 13528 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 59: goto tr725;
		case 61: goto tr726;
		case 65: goto tr860;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr722;
	goto tr706;
tr860:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st618;
st618:
	if ( ++p == pe )
		goto _test_eof618;
case 618:
#line 13549 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 59: goto tr725;
		case 61: goto tr726;
		case 84: goto tr861;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr722;
	goto tr706;
tr861:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st619;
st619:
	if ( ++p == pe )
		goto _test_eof619;
case 619:
#line 13570 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 59: goto tr725;
		case 61: goto tr726;
		case 73: goto tr862;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr722;
	goto tr706;
tr862:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st620;
st620:
	if ( ++p == pe )
		goto _test_eof620;
case 620:
#line 13591 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 59: goto tr725;
		case 61: goto tr726;
		case 67: goto tr863;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr722;
	goto tr706;
tr863:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st621;
st621:
	if ( ++p == pe )
		goto _test_eof621;
case 621:
#line 13612 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 59: goto tr725;
		case 61: goto tr865;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr722;
	goto tr864;
tr865:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st622;
st622:
	if ( ++p == pe )
		goto _test_eof622;
case 622:
#line 13632 "inc/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 49 )
		goto tr867;
	goto tr866;
tr867:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st623;
st623:
	if ( ++p == pe )
		goto _test_eof623;
case 623:
#line 13646 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 59: goto tr725;
	}
	goto tr866;
tr720:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st624;
st624:
	if ( ++p == pe )
		goto _test_eof624;
case 624:
#line 13667 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 59: goto tr725;
		case 61: goto tr726;
		case 65: goto tr868;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr722;
	goto tr706;
tr868:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st625;
st625:
	if ( ++p == pe )
		goto _test_eof625;
case 625:
#line 13688 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 59: goto tr725;
		case 61: goto tr726;
		case 76: goto tr869;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr722;
	goto tr706;
tr869:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st626;
st626:
	if ( ++p == pe )
		goto _test_eof626;
case 626:
#line 13709 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 59: goto tr725;
		case 61: goto tr726;
		case 73: goto tr870;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr722;
	goto tr706;
tr870:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st627;
st627:
	if ( ++p == pe )
		goto _test_eof627;
case 627:
#line 13730 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 59: goto tr725;
		case 61: goto tr726;
		case 68: goto tr871;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr722;
	goto tr706;
tr871:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st628;
st628:
	if ( ++p == pe )
		goto _test_eof628;
case 628:
#line 13751 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 59: goto tr725;
		case 61: goto tr726;
		case 65: goto tr872;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr722;
	goto tr706;
tr872:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st629;
st629:
	if ( ++p == pe )
		goto _test_eof629;
case 629:
#line 13772 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 59: goto tr725;
		case 61: goto tr726;
		case 84: goto tr873;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr722;
	goto tr706;
tr873:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st630;
st630:
	if ( ++p == pe )
		goto _test_eof630;
case 630:
#line 13793 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 59: goto tr725;
		case 61: goto tr726;
		case 69: goto tr874;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr722;
	goto tr706;
tr874:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st631;
st631:
	if ( ++p == pe )
		goto _test_eof631;
case 631:
#line 13814 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 59: goto tr725;
		case 61: goto tr726;
		case 68: goto tr875;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr722;
	goto tr706;
tr875:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st632;
st632:
	if ( ++p == pe )
		goto _test_eof632;
case 632:
#line 13835 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 59: goto tr725;
		case 61: goto tr877;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr722;
	goto tr876;
tr877:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st633;
st633:
	if ( ++p == pe )
		goto _test_eof633;
case 633:
#line 13855 "inc/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 49 )
		goto tr879;
	goto tr878;
tr879:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st634;
st634:
	if ( ++p == pe )
		goto _test_eof634;
case 634:
#line 13869 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 59: goto tr725;
	}
	goto tr878;
tr708:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st635;
st635:
	if ( ++p == pe )
		goto _test_eof635;
case 635:
#line 13890 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr723;
		case 10: goto tr724;
		case 58: goto tr721;
		case 60: goto tr721;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr721;
		} else if ( (*p) > 57 ) {
			if ( 62 <= (*p) && (*p) <= 64 )
				goto tr721;
		} else
			goto tr722;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr721;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr721;
		} else
			goto tr722;
	} else
		goto tr722;
	goto tr706;
tr705:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st636;
st636:
	if ( ++p == pe )
		goto _test_eof636;
case 636:
#line 13928 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 58 )
		goto tr699;
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr699;
		} else if ( (*p) > 57 ) {
			if ( 60 <= (*p) && (*p) <= 64 )
				goto tr699;
		} else
			goto tr701;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr699;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr699;
		} else
			goto tr701;
	} else
		goto tr701;
	goto tr698;
tr700:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st637;
st637:
	if ( ++p == pe )
		goto _test_eof637;
case 637:
#line 13966 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr704;
		case 58: goto st495;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto st495;
		} else if ( (*p) > 57 ) {
			if ( 60 <= (*p) && (*p) <= 64 )
				goto st495;
		} else
			goto tr703;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st495;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st495;
		} else
			goto tr703;
	} else
		goto tr703;
	goto tr698;
tr696:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st638;
st638:
	if ( ++p == pe )
		goto _test_eof638;
case 638:
#line 14002 "inc/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr880;
	goto tr688;
tr880:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st639;
st639:
	if ( ++p == pe )
		goto _test_eof639;
case 639:
#line 14016 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr695;
		case 69: goto tr697;
		case 101: goto tr697;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr880;
	goto tr688;
tr697:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st640;
st640:
	if ( ++p == pe )
		goto _test_eof640;
case 640:
#line 14035 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 43: goto tr881;
		case 45: goto tr881;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr882;
	goto tr688;
tr881:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st641;
st641:
	if ( ++p == pe )
		goto _test_eof641;
case 641:
#line 14053 "inc/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr882;
	goto tr688;
tr882:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st642;
st642:
	if ( ++p == pe )
		goto _test_eof642;
case 642:
#line 14067 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 9 )
		goto tr695;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr882;
	goto tr688;
tr692:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st643;
tr694:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st643;
st643:
	if ( ++p == pe )
		goto _test_eof643;
case 643:
#line 14093 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr695;
		case 46: goto tr696;
		case 69: goto tr697;
		case 101: goto tr697;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr694;
	goto tr688;
tr690:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st644;
st644:
	if ( ++p == pe )
		goto _test_eof644;
case 644:
#line 14117 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 9 )
		goto tr695;
	goto tr688;
tr687:
#line 39 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st645;
st645:
	if ( ++p == pe )
		goto _test_eof645;
case 645:
#line 14131 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 42: goto tr680;
		case 46: goto tr883;
		case 60: goto tr682;
		case 65: goto tr683;
		case 67: goto tr683;
		case 71: goto tr683;
		case 78: goto tr683;
		case 84: goto tr683;
		case 91: goto tr684;
		case 93: goto tr685;
		case 97: goto tr683;
		case 99: goto tr683;
		case 103: goto tr683;
		case 110: goto tr683;
		case 116: goto tr683;
	}
	goto tr679;
tr883:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st646;
tr920:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st646;
st646:
	if ( ++p == pe )
		goto _test_eof646;
case 646:
#line 14170 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 65: goto tr884;
		case 67: goto tr884;
		case 71: goto tr884;
		case 78: goto tr884;
		case 84: goto tr884;
		case 97: goto tr884;
		case 99: goto tr884;
		case 103: goto tr884;
		case 110: goto tr884;
		case 116: goto tr884;
	}
	goto tr679;
tr884:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st647;
st647:
	if ( ++p == pe )
		goto _test_eof647;
case 647:
#line 14194 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr686;
		case 44: goto tr687;
		case 65: goto tr884;
		case 67: goto tr884;
		case 71: goto tr884;
		case 78: goto tr884;
		case 84: goto tr884;
		case 97: goto tr884;
		case 99: goto tr884;
		case 103: goto tr884;
		case 110: goto tr884;
		case 116: goto tr884;
	}
	goto tr679;
tr682:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st648;
tr886:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st648;
st648:
	if ( ++p == pe )
		goto _test_eof648;
case 648:
#line 14230 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 58: goto tr886;
		case 95: goto tr886;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr885;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr885;
	} else
		goto tr885;
	goto tr679;
tr885:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st649;
st649:
	if ( ++p == pe )
		goto _test_eof649;
case 649:
#line 14254 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 62: goto tr887;
		case 95: goto tr885;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 58 )
			goto tr885;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr885;
	} else
		goto tr885;
	goto tr679;
tr683:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st650;
tr888:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st650;
st650:
	if ( ++p == pe )
		goto _test_eof650;
case 650:
#line 14288 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr686;
		case 44: goto tr687;
		case 46: goto tr887;
		case 65: goto tr888;
		case 67: goto tr888;
		case 71: goto tr888;
		case 78: goto tr888;
		case 84: goto tr888;
		case 91: goto tr889;
		case 93: goto tr890;
		case 97: goto tr888;
		case 99: goto tr888;
		case 103: goto tr888;
		case 110: goto tr888;
		case 116: goto tr888;
	}
	goto tr679;
tr889:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st651;
st651:
	if ( ++p == pe )
		goto _test_eof651;
case 651:
#line 14317 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 60 )
		goto tr892;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr891;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr891;
	} else
		goto tr891;
	goto tr679;
tr891:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st652;
st652:
	if ( ++p == pe )
		goto _test_eof652;
case 652:
#line 14339 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 58: goto tr895;
		case 59: goto tr893;
		case 61: goto tr893;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr893;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr893;
		} else
			goto tr894;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr893;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr893;
		} else
			goto tr894;
	} else
		goto tr894;
	goto tr679;
tr893:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st653;
st653:
	if ( ++p == pe )
		goto _test_eof653;
case 653:
#line 14376 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr893;
		case 61: goto tr893;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr893;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr893;
		} else
			goto tr894;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr893;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr893;
		} else
			goto tr894;
	} else
		goto tr894;
	goto tr679;
tr894:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st654;
st654:
	if ( ++p == pe )
		goto _test_eof654;
case 654:
#line 14412 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 58: goto tr895;
		case 61: goto tr894;
	}
	if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr894;
	} else if ( (*p) >= 33 )
		goto tr894;
	goto tr679;
tr895:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st655;
st655:
	if ( ++p == pe )
		goto _test_eof655;
case 655:
#line 14433 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 45 )
		goto tr896;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr897;
	goto tr679;
tr896:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st656;
st656:
	if ( ++p == pe )
		goto _test_eof656;
case 656:
#line 14449 "inc/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr897;
	goto tr679;
tr897:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st657;
st657:
	if ( ++p == pe )
		goto _test_eof657;
case 657:
#line 14463 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 91 )
		goto tr887;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr897;
	goto tr679;
tr892:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st658;
st658:
	if ( ++p == pe )
		goto _test_eof658;
case 658:
#line 14479 "inc/vcf/validator_detail.hpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr898;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr898;
	} else
		goto tr898;
	goto tr679;
tr898:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st659;
st659:
	if ( ++p == pe )
		goto _test_eof659;
case 659:
#line 14499 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr899;
		case 62: goto tr901;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr899;
		} else if ( (*p) > 57 ) {
			if ( 61 <= (*p) && (*p) <= 64 )
				goto tr899;
		} else
			goto tr900;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr899;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr899;
		} else
			goto tr900;
	} else
		goto tr900;
	goto tr679;
tr899:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st660;
st660:
	if ( ++p == pe )
		goto _test_eof660;
case 660:
#line 14535 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr899;
		case 61: goto tr899;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr899;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr899;
		} else
			goto tr900;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr899;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr899;
		} else
			goto tr900;
	} else
		goto tr900;
	goto tr679;
tr900:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st661;
st661:
	if ( ++p == pe )
		goto _test_eof661;
case 661:
#line 14571 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr900;
		case 62: goto tr901;
	}
	if ( (*p) > 57 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr900;
	} else if ( (*p) >= 33 )
		goto tr900;
	goto tr679;
tr901:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st662;
st662:
	if ( ++p == pe )
		goto _test_eof662;
case 662:
#line 14592 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 58 )
		goto tr895;
	goto tr679;
tr890:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st663;
st663:
	if ( ++p == pe )
		goto _test_eof663;
case 663:
#line 14606 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 60 )
		goto tr903;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr902;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr902;
	} else
		goto tr902;
	goto tr679;
tr902:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st664;
st664:
	if ( ++p == pe )
		goto _test_eof664;
case 664:
#line 14628 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 58: goto tr906;
		case 59: goto tr904;
		case 61: goto tr904;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr904;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr904;
		} else
			goto tr905;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr904;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr904;
		} else
			goto tr905;
	} else
		goto tr905;
	goto tr679;
tr904:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st665;
st665:
	if ( ++p == pe )
		goto _test_eof665;
case 665:
#line 14665 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr904;
		case 61: goto tr904;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr904;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr904;
		} else
			goto tr905;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr904;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr904;
		} else
			goto tr905;
	} else
		goto tr905;
	goto tr679;
tr905:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st666;
st666:
	if ( ++p == pe )
		goto _test_eof666;
case 666:
#line 14701 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 58: goto tr906;
		case 61: goto tr905;
	}
	if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr905;
	} else if ( (*p) >= 33 )
		goto tr905;
	goto tr679;
tr906:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st667;
st667:
	if ( ++p == pe )
		goto _test_eof667;
case 667:
#line 14722 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 45 )
		goto tr907;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr908;
	goto tr679;
tr907:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st668;
st668:
	if ( ++p == pe )
		goto _test_eof668;
case 668:
#line 14738 "inc/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr908;
	goto tr679;
tr908:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st669;
st669:
	if ( ++p == pe )
		goto _test_eof669;
case 669:
#line 14752 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 93 )
		goto tr887;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr908;
	goto tr679;
tr903:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st670;
st670:
	if ( ++p == pe )
		goto _test_eof670;
case 670:
#line 14768 "inc/vcf/validator_detail.hpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr909;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr909;
	} else
		goto tr909;
	goto tr679;
tr909:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st671;
st671:
	if ( ++p == pe )
		goto _test_eof671;
case 671:
#line 14788 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr910;
		case 62: goto tr912;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr910;
		} else if ( (*p) > 57 ) {
			if ( 61 <= (*p) && (*p) <= 64 )
				goto tr910;
		} else
			goto tr911;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr910;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr910;
		} else
			goto tr911;
	} else
		goto tr911;
	goto tr679;
tr910:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st672;
st672:
	if ( ++p == pe )
		goto _test_eof672;
case 672:
#line 14824 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr910;
		case 61: goto tr910;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr910;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr910;
		} else
			goto tr911;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr910;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr910;
		} else
			goto tr911;
	} else
		goto tr911;
	goto tr679;
tr911:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st673;
st673:
	if ( ++p == pe )
		goto _test_eof673;
case 673:
#line 14860 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr911;
		case 62: goto tr912;
	}
	if ( (*p) > 57 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr911;
	} else if ( (*p) >= 33 )
		goto tr911;
	goto tr679;
tr912:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st674;
st674:
	if ( ++p == pe )
		goto _test_eof674;
case 674:
#line 14881 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 58 )
		goto tr906;
	goto tr679;
tr684:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st675;
st675:
	if ( ++p == pe )
		goto _test_eof675;
case 675:
#line 14899 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 60 )
		goto tr914;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr913;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr913;
	} else
		goto tr913;
	goto tr679;
tr913:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st676;
st676:
	if ( ++p == pe )
		goto _test_eof676;
case 676:
#line 14921 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 58: goto tr917;
		case 59: goto tr915;
		case 61: goto tr915;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr915;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr915;
		} else
			goto tr916;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr915;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr915;
		} else
			goto tr916;
	} else
		goto tr916;
	goto tr679;
tr915:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st677;
st677:
	if ( ++p == pe )
		goto _test_eof677;
case 677:
#line 14958 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr915;
		case 61: goto tr915;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr915;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr915;
		} else
			goto tr916;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr915;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr915;
		} else
			goto tr916;
	} else
		goto tr916;
	goto tr679;
tr916:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st678;
st678:
	if ( ++p == pe )
		goto _test_eof678;
case 678:
#line 14994 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 58: goto tr917;
		case 61: goto tr916;
	}
	if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr916;
	} else if ( (*p) >= 33 )
		goto tr916;
	goto tr679;
tr917:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st679;
st679:
	if ( ++p == pe )
		goto _test_eof679;
case 679:
#line 15015 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 45 )
		goto tr918;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr919;
	goto tr679;
tr918:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st680;
st680:
	if ( ++p == pe )
		goto _test_eof680;
case 680:
#line 15031 "inc/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr919;
	goto tr679;
tr919:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st681;
st681:
	if ( ++p == pe )
		goto _test_eof681;
case 681:
#line 15045 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 91 )
		goto tr920;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr919;
	goto tr679;
tr914:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st682;
st682:
	if ( ++p == pe )
		goto _test_eof682;
case 682:
#line 15061 "inc/vcf/validator_detail.hpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr921;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr921;
	} else
		goto tr921;
	goto tr679;
tr921:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st683;
st683:
	if ( ++p == pe )
		goto _test_eof683;
case 683:
#line 15081 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr922;
		case 62: goto tr924;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr922;
		} else if ( (*p) > 57 ) {
			if ( 61 <= (*p) && (*p) <= 64 )
				goto tr922;
		} else
			goto tr923;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr922;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr922;
		} else
			goto tr923;
	} else
		goto tr923;
	goto tr679;
tr922:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st684;
st684:
	if ( ++p == pe )
		goto _test_eof684;
case 684:
#line 15117 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr922;
		case 61: goto tr922;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr922;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr922;
		} else
			goto tr923;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr922;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr922;
		} else
			goto tr923;
	} else
		goto tr923;
	goto tr679;
tr923:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st685;
st685:
	if ( ++p == pe )
		goto _test_eof685;
case 685:
#line 15153 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr923;
		case 62: goto tr924;
	}
	if ( (*p) > 57 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr923;
	} else if ( (*p) >= 33 )
		goto tr923;
	goto tr679;
tr924:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st686;
st686:
	if ( ++p == pe )
		goto _test_eof686;
case 686:
#line 15174 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 58 )
		goto tr917;
	goto tr679;
tr685:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st687;
st687:
	if ( ++p == pe )
		goto _test_eof687;
case 687:
#line 15192 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 60 )
		goto tr926;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr925;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr925;
	} else
		goto tr925;
	goto tr679;
tr925:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st688;
st688:
	if ( ++p == pe )
		goto _test_eof688;
case 688:
#line 15214 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 58: goto tr929;
		case 59: goto tr927;
		case 61: goto tr927;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr927;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr927;
		} else
			goto tr928;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr927;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr927;
		} else
			goto tr928;
	} else
		goto tr928;
	goto tr679;
tr927:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st689;
st689:
	if ( ++p == pe )
		goto _test_eof689;
case 689:
#line 15251 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr927;
		case 61: goto tr927;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr927;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr927;
		} else
			goto tr928;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr927;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr927;
		} else
			goto tr928;
	} else
		goto tr928;
	goto tr679;
tr928:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st690;
st690:
	if ( ++p == pe )
		goto _test_eof690;
case 690:
#line 15287 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 58: goto tr929;
		case 61: goto tr928;
	}
	if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr928;
	} else if ( (*p) >= 33 )
		goto tr928;
	goto tr679;
tr929:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st691;
st691:
	if ( ++p == pe )
		goto _test_eof691;
case 691:
#line 15308 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 45 )
		goto tr930;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr931;
	goto tr679;
tr930:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st692;
st692:
	if ( ++p == pe )
		goto _test_eof692;
case 692:
#line 15324 "inc/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr931;
	goto tr679;
tr931:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st693;
st693:
	if ( ++p == pe )
		goto _test_eof693;
case 693:
#line 15338 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 93 )
		goto tr920;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr931;
	goto tr679;
tr926:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st694;
st694:
	if ( ++p == pe )
		goto _test_eof694;
case 694:
#line 15354 "inc/vcf/validator_detail.hpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr932;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr932;
	} else
		goto tr932;
	goto tr679;
tr932:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st695;
st695:
	if ( ++p == pe )
		goto _test_eof695;
case 695:
#line 15374 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr933;
		case 62: goto tr935;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr933;
		} else if ( (*p) > 57 ) {
			if ( 61 <= (*p) && (*p) <= 64 )
				goto tr933;
		} else
			goto tr934;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr933;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr933;
		} else
			goto tr934;
	} else
		goto tr934;
	goto tr679;
tr933:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st696;
st696:
	if ( ++p == pe )
		goto _test_eof696;
case 696:
#line 15410 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr933;
		case 61: goto tr933;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr933;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr933;
		} else
			goto tr934;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr933;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr933;
		} else
			goto tr934;
	} else
		goto tr934;
	goto tr679;
tr934:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st697;
st697:
	if ( ++p == pe )
		goto _test_eof697;
case 697:
#line 15446 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr934;
		case 62: goto tr935;
	}
	if ( (*p) > 57 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr934;
	} else if ( (*p) >= 33 )
		goto tr934;
	goto tr679;
tr935:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st698;
st698:
	if ( ++p == pe )
		goto _test_eof698;
case 698:
#line 15467 "inc/vcf/validator_detail.hpp"
	if ( (*p) == 58 )
		goto tr929;
	goto tr679;
tr681:
#line 31 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st699;
st699:
	if ( ++p == pe )
		goto _test_eof699;
case 699:
#line 15485 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr686;
		case 65: goto tr884;
		case 67: goto tr884;
		case 71: goto tr884;
		case 78: goto tr884;
		case 84: goto tr884;
		case 97: goto tr884;
		case 99: goto tr884;
		case 103: goto tr884;
		case 110: goto tr884;
		case 116: goto tr884;
	}
	goto tr679;
tr663:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st700;
st700:
	if ( ++p == pe )
		goto _test_eof700;
case 700:
#line 15510 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr663;
		case 61: goto tr663;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr663;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr663;
		} else
			goto tr664;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr663;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr663;
		} else
			goto tr664;
	} else
		goto tr664;
	goto tr661;
tr664:
#line 35 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st701;
st701:
	if ( ++p == pe )
		goto _test_eof701;
case 701:
#line 15546 "inc/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr662;
		case 59: goto tr664;
		case 61: goto tr664;
	}
	if ( (*p) > 57 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr664;
	} else if ( (*p) >= 33 )
		goto tr664;
	goto tr661;
st702:
	if ( ++p == pe )
		goto _test_eof702;
case 702:
	if ( (*p) == 10 )
		goto tr937;
	goto st702;
tr937:
#line 43 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
#line 741 "src/vcf/vcf_v41.ragel"
	{ {goto st22;} }
	goto st706;
st706:
	if ( ++p == pe )
		goto _test_eof706;
case 706:
#line 15583 "inc/vcf/validator_detail.hpp"
	goto st0;
st703:
	if ( ++p == pe )
		goto _test_eof703;
case 703:
	if ( (*p) == 10 )
		goto tr939;
	goto st703;
tr939:
#line 43 "src/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
#line 742 "src/vcf/vcf_v41.ragel"
	{ {goto st705;} }
	goto st707;
st707:
	if ( ++p == pe )
		goto _test_eof707;
case 707:
#line 15610 "inc/vcf/validator_detail.hpp"
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
	_test_eof704: cs = 704; goto _test_eof; 
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
	_test_eof705: cs = 705; goto _test_eof; 
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
	_test_eof657: cs = 657; goto _test_eof; 
	_test_eof658: cs = 658; goto _test_eof; 
	_test_eof659: cs = 659; goto _test_eof; 
	_test_eof660: cs = 660; goto _test_eof; 
	_test_eof661: cs = 661; goto _test_eof; 
	_test_eof662: cs = 662; goto _test_eof; 
	_test_eof663: cs = 663; goto _test_eof; 
	_test_eof664: cs = 664; goto _test_eof; 
	_test_eof665: cs = 665; goto _test_eof; 
	_test_eof666: cs = 666; goto _test_eof; 
	_test_eof667: cs = 667; goto _test_eof; 
	_test_eof668: cs = 668; goto _test_eof; 
	_test_eof669: cs = 669; goto _test_eof; 
	_test_eof670: cs = 670; goto _test_eof; 
	_test_eof671: cs = 671; goto _test_eof; 
	_test_eof672: cs = 672; goto _test_eof; 
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
	_test_eof706: cs = 706; goto _test_eof; 
	_test_eof703: cs = 703; goto _test_eof; 
	_test_eof707: cs = 707; goto _test_eof; 

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
        p--; {goto st702;}
    }
	break;
	case 19: 
	case 20: 
	case 21: 
	case 23: 
	case 24: 
	case 25: 
	case 26: 
	case 27: 
	case 28: 
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
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	break;
	case 704: 
#line 70 "src/vcf/vcf_v41.ragel"
	{
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (ParsingWarning warn) {
          ErrorPolicy::handle_meta_section_warning(*this, warn.what());
        }
    }
	break;
	case 472: 
	case 473: 
	case 474: 
	case 475: 
	case 476: 
	case 477: 
	case 478: 
	case 479: 
	case 480: 
#line 78 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (ParsingWarning warn) {
          ErrorPolicy::handle_meta_section_warning(*this, warn.what());
        }
        
        p--; {goto st703;}
    }
	break;
	case 14: 
	case 15: 
#line 210 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this,
            "Fileformat is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st702;}
    }
#line 60 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this);
        p--; {goto st702;}
    }
	break;
	case 67: 
	case 68: 
	case 69: 
	case 70: 
	case 71: 
	case 72: 
	case 73: 
	case 76: 
	case 77: 
	case 78: 
	case 79: 
	case 80: 
	case 81: 
	case 82: 
	case 83: 
	case 84: 
	case 85: 
	case 86: 
	case 87: 
	case 88: 
	case 95: 
	case 106: 
#line 217 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	break;
	case 368: 
	case 369: 
	case 370: 
	case 371: 
	case 372: 
	case 373: 
	case 374: 
	case 375: 
#line 228 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in assembly metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	break;
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
#line 234 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in contig metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	break;
	case 116: 
	case 117: 
	case 118: 
	case 119: 
	case 120: 
	case 121: 
	case 122: 
	case 123: 
	case 124: 
	case 128: 
	case 129: 
	case 130: 
	case 131: 
	case 132: 
	case 133: 
	case 134: 
	case 135: 
	case 136: 
	case 137: 
	case 138: 
	case 139: 
	case 140: 
	case 147: 
	case 158: 
#line 240 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
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
	case 174: 
	case 178: 
	case 179: 
	case 180: 
	case 181: 
	case 182: 
	case 183: 
	case 184: 
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
	case 199: 
	case 200: 
	case 201: 
	case 202: 
	case 203: 
	case 204: 
	case 205: 
	case 206: 
	case 213: 
	case 224: 
#line 246 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
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
	case 244: 
	case 245: 
	case 246: 
	case 247: 
	case 248: 
	case 249: 
	case 250: 
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
	case 265: 
	case 266: 
	case 267: 
	case 268: 
	case 269: 
	case 270: 
	case 271: 
	case 272: 
	case 279: 
	case 290: 
#line 262 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	break;
	case 299: 
	case 300: 
	case 301: 
	case 302: 
	case 303: 
	case 304: 
	case 305: 
	case 306: 
	case 307: 
	case 314: 
#line 278 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in PEDIGREE metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	break;
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
#line 284 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in pedigreeDB metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	break;
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
	case 364: 
#line 290 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
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
#line 322 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this, "The header line does not start with the mandatory columns: CHROM, POS, ID, REF, ALT, QUAL, FILTER and INFO");
        
        // If an error occurs in the header, meta_section_end won't be triggered and the meta and header optional validations must be run here
        try {
          OptionalPolicy::optional_check_meta_section(*this);
        } catch (ParsingWarning warn) {
          ErrorPolicy::handle_meta_section_warning(*this, warn.what());
        }
        
        p--; {goto st703;}
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
        
        p--; {goto st703;}
    }
	break;
	case 481: 
	case 504: 
	case 505: 
	case 506: 
	case 507: 
	case 508: 
	case 700: 
	case 701: 
#line 338 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Chromosome is not a string without colons or whitespaces, optionally wrapped with angle brackets (<>)");
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	break;
	case 482: 
	case 483: 
	case 484: 
#line 344 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Position is not a positive number");
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	break;
	case 485: 
	case 486: 
#line 350 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "ID is not a single dot or a list of strings without semicolons or whitespaces");
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	break;
	case 487: 
	case 488: 
#line 356 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Reference is not a string of bases");
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	break;
	case 489: 
	case 490: 
	case 645: 
	case 646: 
	case 647: 
	case 648: 
	case 649: 
	case 650: 
	case 651: 
	case 652: 
	case 653: 
	case 654: 
	case 655: 
	case 656: 
	case 657: 
	case 658: 
	case 659: 
	case 660: 
	case 661: 
	case 662: 
	case 663: 
	case 664: 
	case 665: 
	case 666: 
	case 667: 
	case 668: 
	case 669: 
	case 670: 
	case 671: 
	case 672: 
	case 673: 
	case 674: 
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
#line 362 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Alternate is not a single dot or a comma-separated list of bases");
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	break;
	case 491: 
	case 492: 
	case 493: 
	case 638: 
	case 639: 
	case 640: 
	case 641: 
	case 642: 
	case 643: 
	case 644: 
#line 368 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Quality is not a single dot or a positive number");
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	break;
	case 494: 
	case 495: 
	case 496: 
	case 636: 
	case 637: 
#line 374 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Filter is not a single dot or a semicolon-separated list of strings");
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	break;
	case 500: 
	case 501: 
#line 486 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Format is not a colon-separated list of alphanumeric strings");
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	break;
	case 511: 
	case 512: 
#line 492 "src/vcf/vcf_v41.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " is not a valid string";
        ErrorPolicy::handle_body_section_error(*this, message_stream.str());
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	break;
	case 17: 
	case 22: 
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
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
        
        p--; {goto st703;}
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
        
        p--; {goto st703;}
    }
	break;
	case 74: 
	case 75: 
	case 114: 
#line 222 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "ALT metadata ID is not prefixed by DEL/INS/DUP/INV/CNV and suffixed by ':' and a text sequence");
        p--; {goto st702;}
    }
#line 217 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	break;
	case 115: 
#line 240 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st702;}
    }
#line 246 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	break;
	case 185: 
	case 186: 
	case 232: 
#line 251 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "FORMAT metadata Number is not a number, A, R, G or dot");
        p--; {goto st702;}
    }
#line 246 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	break;
	case 251: 
	case 252: 
	case 298: 
#line 267 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "INFO metadata Number is not a number, A, R, G or dot");
        p--; {goto st702;}
    }
#line 262 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	break;
	case 192: 
	case 193: 
#line 272 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "INFO metadata Type is not a Integer, Float, Flag, Character or String");
        p--; {goto st702;}
    }
#line 246 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	break;
	case 258: 
	case 259: 
#line 272 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "INFO metadata Type is not a Integer, Float, Flag, Character or String");
        p--; {goto st702;}
    }
#line 262 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	break;
	case 328: 
	case 329: 
	case 330: 
	case 331: 
	case 332: 
	case 333: 
	case 334: 
	case 335: 
	case 336: 
#line 295 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Genomes is not a valid string (maybe it contains quotes?)");
        p--; {goto st702;}
    }
#line 290 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	break;
	case 338: 
	case 339: 
	case 340: 
	case 341: 
	case 342: 
	case 343: 
	case 344: 
	case 345: 
	case 346: 
#line 300 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Mixture is not a valid string (maybe it contains quotes?)");
        p--; {goto st702;}
    }
#line 290 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	break;
	case 92: 
	case 93: 
	case 94: 
#line 306 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st702;}
    }
#line 217 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	break;
	case 393: 
	case 394: 
	case 395: 
	case 396: 
#line 306 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st702;}
    }
#line 234 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in contig metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	break;
	case 125: 
	case 126: 
	case 127: 
	case 144: 
	case 145: 
	case 146: 
#line 306 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st702;}
    }
#line 240 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	break;
	case 175: 
	case 176: 
	case 177: 
	case 210: 
	case 211: 
	case 212: 
#line 306 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st702;}
    }
#line 246 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	break;
	case 241: 
	case 242: 
	case 243: 
	case 276: 
	case 277: 
	case 278: 
#line 306 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st702;}
    }
#line 262 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	break;
	case 308: 
	case 309: 
	case 310: 
	case 311: 
	case 312: 
	case 313: 
#line 306 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st702;}
    }
#line 278 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in PEDIGREE metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	break;
	case 325: 
	case 326: 
#line 306 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st702;}
    }
#line 290 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	break;
	case 89: 
	case 90: 
	case 91: 
	case 96: 
	case 97: 
	case 98: 
	case 99: 
	case 103: 
	case 104: 
	case 105: 
	case 107: 
	case 108: 
	case 112: 
	case 113: 
#line 311 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st702;}
    }
#line 217 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	break;
	case 141: 
	case 142: 
	case 143: 
	case 148: 
	case 149: 
	case 150: 
	case 151: 
	case 155: 
	case 156: 
	case 157: 
	case 159: 
	case 160: 
	case 164: 
	case 165: 
#line 311 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st702;}
    }
#line 240 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	break;
	case 207: 
	case 208: 
	case 209: 
	case 214: 
	case 215: 
	case 216: 
	case 217: 
	case 221: 
	case 222: 
	case 223: 
	case 225: 
	case 226: 
	case 230: 
	case 231: 
#line 311 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st702;}
    }
#line 246 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	break;
	case 273: 
	case 274: 
	case 275: 
	case 280: 
	case 281: 
	case 282: 
	case 283: 
	case 287: 
	case 288: 
	case 289: 
	case 291: 
	case 292: 
	case 296: 
	case 297: 
#line 311 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st702;}
    }
#line 262 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	break;
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
	case 365: 
	case 366: 
	case 367: 
#line 311 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st702;}
    }
#line 290 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	break;
	case 376: 
	case 377: 
	case 378: 
	case 379: 
	case 380: 
	case 381: 
	case 382: 
#line 316 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata URL is not valid");
        p--; {goto st702;}
    }
#line 228 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in assembly metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	break;
	case 427: 
	case 428: 
	case 429: 
	case 430: 
	case 431: 
	case 432: 
	case 433: 
	case 434: 
#line 316 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata URL is not valid");
        p--; {goto st702;}
    }
#line 284 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in pedigreeDB metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	break;
	case 497: 
	case 498: 
	case 499: 
	case 513: 
	case 514: 
	case 515: 
	case 516: 
	case 517: 
	case 523: 
	case 524: 
	case 528: 
	case 532: 
	case 542: 
	case 546: 
	case 547: 
	case 557: 
	case 558: 
	case 559: 
	case 560: 
	case 561: 
	case 564: 
	case 568: 
	case 572: 
	case 573: 
	case 574: 
	case 578: 
	case 585: 
	case 586: 
	case 587: 
	case 600: 
	case 601: 
	case 605: 
	case 606: 
	case 616: 
	case 617: 
	case 618: 
	case 619: 
	case 620: 
	case 624: 
	case 625: 
	case 626: 
	case 627: 
	case 628: 
	case 629: 
	case 630: 
	case 631: 
	case 635: 
#line 385 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st703;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	break;
	case 518: 
	case 519: 
#line 390 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info field value is not a comma-separated list of valid strings (maybe it contains whitespaces?)");
        p--; {goto st703;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	break;
	case 525: 
	case 526: 
	case 527: 
#line 395 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info AA value is not a single dot or a string of bases");
        p--; {goto st703;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	break;
	case 529: 
	case 530: 
	case 531: 
#line 400 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info AC value is not a comma-separated list of numbers");
        p--; {goto st703;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	break;
	case 533: 
	case 534: 
	case 535: 
	case 536: 
	case 537: 
	case 538: 
	case 539: 
	case 540: 
	case 541: 
#line 405 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info AF value is not a comma-separated list of numbers");
        p--; {goto st703;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	break;
	case 543: 
	case 544: 
	case 545: 
#line 410 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info AN value is not an integer number");
        p--; {goto st703;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	break;
	case 548: 
	case 549: 
	case 550: 
	case 551: 
	case 552: 
	case 553: 
	case 554: 
	case 555: 
	case 556: 
#line 415 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info BQ value is not a number");
        p--; {goto st703;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	break;
	case 562: 
	case 563: 
#line 420 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info CIGAR value is not an alphanumeric string");
        p--; {goto st703;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	break;
	case 566: 
	case 567: 
#line 425 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info DB is not a flag (with 1/0/no value)");
        p--; {goto st703;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	break;
	case 569: 
	case 570: 
	case 571: 
#line 430 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info DP value is not an integer number");
        p--; {goto st703;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	break;
	case 575: 
	case 576: 
	case 577: 
#line 435 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info END value is not an integer number");
        p--; {goto st703;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	break;
	case 580: 
	case 581: 
#line 440 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info H2 is not a flag (with 1/0/no value)");
        p--; {goto st703;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	break;
	case 583: 
	case 584: 
#line 445 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info H3 is not a flag (with 1/0/no value)");
        p--; {goto st703;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	break;
	case 591: 
	case 592: 
	case 593: 
	case 594: 
	case 595: 
	case 596: 
	case 597: 
	case 598: 
	case 599: 
#line 450 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info MQ value is not a number");
        p--; {goto st703;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	break;
	case 588: 
	case 589: 
	case 590: 
#line 455 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info MQ0 value is not an integer number");
        p--; {goto st703;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	break;
	case 602: 
	case 603: 
	case 604: 
#line 460 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info NS value is not an integer number");
        p--; {goto st703;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	break;
	case 607: 
	case 608: 
	case 609: 
	case 610: 
	case 611: 
	case 612: 
	case 613: 
	case 614: 
	case 615: 
#line 465 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info SB value is not a number");
        p--; {goto st703;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	break;
	case 622: 
	case 623: 
#line 470 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info SOMATIC is not a flag (with 1/0/no value)");
        p--; {goto st703;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	break;
	case 633: 
	case 634: 
#line 475 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info VALIDATED is not a flag (with 1/0/no value)");
        p--; {goto st703;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	break;
	case 521: 
	case 522: 
#line 480 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info 1000G is not a flag (with 1/0/no value)");
        p--; {goto st703;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	break;
	case 502: 
	case 503: 
	case 509: 
	case 510: 
#line 499 "src/vcf/vcf_v41.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " does not start with a valid genotype";
        ErrorPolicy::handle_body_section_error(*this, message_stream.str());
        p--; {goto st703;}
    }
#line 492 "src/vcf/vcf_v41.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " is not a valid string";
        ErrorPolicy::handle_body_section_error(*this, message_stream.str());
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	break;
	case 16: 
#line 60 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this);
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
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
        
        p--; {goto st703;}
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
        
        p--; {goto st703;}
    }
	break;
	case 337: 
#line 295 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Genomes is not a valid string (maybe it contains quotes?)");
        p--; {goto st702;}
    }
#line 300 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Mixture is not a valid string (maybe it contains quotes?)");
        p--; {goto st702;}
    }
#line 290 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	break;
	case 347: 
#line 300 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Mixture is not a valid string (maybe it contains quotes?)");
        p--; {goto st702;}
    }
#line 311 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st702;}
    }
#line 290 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	break;
	case 327: 
#line 306 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st702;}
    }
#line 295 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Genomes is not a valid string (maybe it contains quotes?)");
        p--; {goto st702;}
    }
#line 290 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	break;
	case 100: 
	case 101: 
	case 102: 
#line 306 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st702;}
    }
#line 311 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st702;}
    }
#line 217 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	break;
	case 152: 
	case 153: 
	case 154: 
#line 306 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st702;}
    }
#line 311 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st702;}
    }
#line 240 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	break;
	case 218: 
	case 219: 
	case 220: 
#line 306 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st702;}
    }
#line 311 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st702;}
    }
#line 246 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	break;
	case 284: 
	case 285: 
	case 286: 
#line 306 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st702;}
    }
#line 311 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st702;}
    }
#line 262 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	break;
	case 109: 
	case 110: 
	case 111: 
#line 311 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st702;}
    }
#line 306 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st702;}
    }
#line 217 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	break;
	case 161: 
	case 162: 
	case 163: 
#line 311 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st702;}
    }
#line 306 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st702;}
    }
#line 240 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	break;
	case 227: 
	case 228: 
	case 229: 
#line 311 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st702;}
    }
#line 306 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st702;}
    }
#line 246 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	break;
	case 293: 
	case 294: 
	case 295: 
#line 311 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st702;}
    }
#line 306 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st702;}
    }
#line 262 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	break;
	case 565: 
#line 425 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info DB is not a flag (with 1/0/no value)");
        p--; {goto st703;}
    }
#line 385 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st703;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	break;
	case 579: 
#line 440 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info H2 is not a flag (with 1/0/no value)");
        p--; {goto st703;}
    }
#line 385 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st703;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	break;
	case 582: 
#line 445 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info H3 is not a flag (with 1/0/no value)");
        p--; {goto st703;}
    }
#line 385 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st703;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	break;
	case 621: 
#line 470 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info SOMATIC is not a flag (with 1/0/no value)");
        p--; {goto st703;}
    }
#line 385 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st703;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	break;
	case 632: 
#line 475 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info VALIDATED is not a flag (with 1/0/no value)");
        p--; {goto st703;}
    }
#line 385 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st703;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	break;
	case 520: 
#line 480 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info 1000G is not a flag (with 1/0/no value)");
        p--; {goto st703;}
    }
#line 385 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st703;}
    }
#line 380 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st703;}
    }
#line 91 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st703;}
    }
	break;
	case 18: 
#line 217 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st702;}
    }
#line 240 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st702;}
    }
#line 246 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st702;}
    }
#line 262 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st702;}
    }
#line 228 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in assembly metadata");
        p--; {goto st702;}
    }
#line 234 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in contig metadata");
        p--; {goto st702;}
    }
#line 290 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st702;}
    }
#line 278 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in PEDIGREE metadata");
        p--; {goto st702;}
    }
#line 284 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in pedigreeDB metadata");
        p--; {goto st702;}
    }
#line 65 "src/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st702;}
    }
	break;
#line 18469 "inc/vcf/validator_detail.hpp"
	}
	}

	_out: {}
	}

#line 808 "src/vcf/vcf_v41.ragel"

    }
    
  }
}
