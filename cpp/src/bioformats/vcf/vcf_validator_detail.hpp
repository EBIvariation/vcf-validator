
#line 1 "vcf_v41.ragel"
#include <cstdio>

#include "vcf_validator.hpp"


#line 529 "vcf_v41.ragel"


namespace
{
  
#line 15 "vcf_validator_detail.hpp"
static const int vcf_start = 1;
static const int vcf_first_final = 709;
static const int vcf_error = 0;

static const int vcf_en_main = 1;
static const int vcf_en_main_meta_section = 20;
static const int vcf_en_main_body_section = 710;
static const int vcf_en_meta_section_skip = 707;
static const int vcf_en_body_section_skip = 708;


#line 535 "vcf_v41.ragel"

}

namespace opencb
{
  namespace vcf
  {
    template <typename Configuration>
    Parser<Configuration>::Parser()
    {
      
#line 39 "vcf_validator_detail.hpp"
	{
	cs = vcf_start;
	}

#line 547 "vcf_v41.ragel"

    }

    template <typename Configuration>
    void Parser<Configuration>::parse(std::vector<char> const & text)
    {
      char const * p = &text[0];
      char const * pe = &text[0] + text.size();
      char const * eof = nullptr;

      parse_buffer(p, pe, eof);
    }

    template <typename Configuration>
    void Parser<Configuration>::parse(std::string const & text)
    {
      char const * p = text.data();
      char const * pe = text.data() + text.size();
      char const * eof = nullptr;

      parse_buffer(p, pe, eof);
    }

    template <typename Configuration>
    void Parser<Configuration>::end()
    {
      char const * empty = "";
      parse_buffer(empty, empty, empty);
    }

    template <typename Configuration>
    bool Parser<Configuration>::is_valid() const
    {
      return cs >= 
#line 79 "vcf_validator_detail.hpp"
709
#line 580 "vcf_v41.ragel"
;
    }

    template <typename Configuration>
    void Parser<Configuration>::parse_buffer(char const * p, char const * pe, char const * eof)
    {
      char const * ts = nullptr;
      char const * te = nullptr;

      
#line 92 "vcf_validator_detail.hpp"
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
#line 35 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this);
        p--; {goto st707;}
    }
	goto st0;
tr14:
#line 211 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this,
            "Fileformat is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st707;}
    }
#line 35 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this);
        p--; {goto st707;}
    }
	goto st0;
tr18:
#line 35 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this);
        p--; {goto st707;}
    }
#line 272 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in metadata");
        p--; {goto st707;}
    }
#line 218 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in ALT metadata");
        p--; {goto st707;}
    }
#line 234 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in FILTER metadata");
        p--; {goto st707;}
    }
#line 240 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st707;}
    }
#line 256 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in INFO metadata");
        p--; {goto st707;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st707;}
    }
#line 45 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        p--; {goto st708;}
    }
	goto st0;
tr20:
#line 272 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in metadata");
        p--; {goto st707;}
    }
#line 218 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in ALT metadata");
        p--; {goto st707;}
    }
#line 234 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in FILTER metadata");
        p--; {goto st707;}
    }
#line 240 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st707;}
    }
#line 256 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in INFO metadata");
        p--; {goto st707;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st707;}
    }
#line 45 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        p--; {goto st708;}
    }
	goto st0;
tr23:
#line 272 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in metadata");
        p--; {goto st707;}
    }
#line 218 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in ALT metadata");
        p--; {goto st707;}
    }
#line 234 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in FILTER metadata");
        p--; {goto st707;}
    }
#line 240 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st707;}
    }
#line 256 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in INFO metadata");
        p--; {goto st707;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st707;}
    }
	goto st0;
tr34:
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st707;}
    }
	goto st0;
tr37:
#line 272 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in metadata");
        p--; {goto st707;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st707;}
    }
	goto st0;
tr142:
#line 272 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in metadata");
        p--; {goto st707;}
    }
#line 218 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in ALT metadata");
        p--; {goto st707;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st707;}
    }
	goto st0;
tr146:
#line 218 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in ALT metadata");
        p--; {goto st707;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st707;}
    }
	goto st0;
tr151:
#line 223 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "ALT metadata ID does not begin with DEL/INS/DUP/INV/CNV");
        p--; {goto st707;}
    }
#line 218 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in ALT metadata");
        p--; {goto st707;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st707;}
    }
	goto st0;
tr157:
#line 223 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "ALT metadata ID does not begin with DEL/INS/DUP/INV/CNV");
        p--; {goto st707;}
    }
#line 228 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "ALT metadata ID suffix (after ':') is not valid");
        p--; {goto st707;}
    }
#line 218 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in ALT metadata");
        p--; {goto st707;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st707;}
    }
	goto st0;
tr174:
#line 282 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Metadata description string is not valid");
        p--; {goto st707;}
    }
#line 218 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in ALT metadata");
        p--; {goto st707;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st707;}
    }
	goto st0;
tr178:
#line 228 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "ALT metadata ID suffix (after ':') is not valid");
        p--; {goto st707;}
    }
#line 218 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in ALT metadata");
        p--; {goto st707;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st707;}
    }
	goto st0;
tr195:
#line 272 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in metadata");
        p--; {goto st707;}
    }
#line 234 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in FILTER metadata");
        p--; {goto st707;}
    }
#line 240 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st707;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st707;}
    }
	goto st0;
tr198:
#line 272 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in metadata");
        p--; {goto st707;}
    }
#line 234 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in FILTER metadata");
        p--; {goto st707;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st707;}
    }
	goto st0;
tr204:
#line 234 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in FILTER metadata");
        p--; {goto st707;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st707;}
    }
	goto st0;
tr209:
#line 277 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st707;}
    }
#line 234 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in FILTER metadata");
        p--; {goto st707;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st707;}
    }
	goto st0;
tr229:
#line 282 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Metadata description string is not valid");
        p--; {goto st707;}
    }
#line 234 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in FILTER metadata");
        p--; {goto st707;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st707;}
    }
	goto st0;
tr233:
#line 272 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in metadata");
        p--; {goto st707;}
    }
#line 240 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st707;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st707;}
    }
	goto st0;
tr239:
#line 240 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st707;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st707;}
    }
	goto st0;
tr244:
#line 277 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st707;}
    }
#line 240 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st707;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st707;}
    }
	goto st0;
tr257:
#line 245 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "FORMAT metadata Number is not a number, A, R, G or dot");
        p--; {goto st707;}
    }
#line 240 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st707;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st707;}
    }
	goto st0;
tr266:
#line 250 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "FORMAT metadata Type is not a Integer, Float, Character or String");
        p--; {goto st707;}
    }
#line 240 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st707;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st707;}
    }
	goto st0;
tr294:
#line 282 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Metadata description string is not valid");
        p--; {goto st707;}
    }
#line 240 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st707;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st707;}
    }
	goto st0;
tr308:
#line 272 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in metadata");
        p--; {goto st707;}
    }
#line 256 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in INFO metadata");
        p--; {goto st707;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st707;}
    }
	goto st0;
tr313:
#line 256 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in INFO metadata");
        p--; {goto st707;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st707;}
    }
	goto st0;
tr318:
#line 277 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st707;}
    }
#line 256 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in INFO metadata");
        p--; {goto st707;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st707;}
    }
	goto st0;
tr331:
#line 261 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "INFO metadata Number is not a number, A, R, G or dot");
        p--; {goto st707;}
    }
#line 256 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in INFO metadata");
        p--; {goto st707;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st707;}
    }
	goto st0;
tr340:
#line 266 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "INFO metadata Type is not a Integer, Float, Flag, Character or String");
        p--; {goto st707;}
    }
#line 256 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in INFO metadata");
        p--; {goto st707;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st707;}
    }
	goto st0;
tr368:
#line 282 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Metadata description string is not valid");
        p--; {goto st707;}
    }
#line 256 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in INFO metadata");
        p--; {goto st707;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st707;}
    }
	goto st0;
tr448:
#line 277 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st707;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st707;}
    }
	goto st0;
tr504:
#line 287 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Metadata URL is not valid");
        p--; {goto st707;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st707;}
    }
	goto st0;
tr547:
#line 45 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        p--; {goto st708;}
    }
	goto st0;
tr597:
#line 294 "vcf_v41.ragel"
	{
        printf("Line %zu: Error in 'chrom' field\n", n_lines);
        p--; {goto st708;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st708;}
    }
	goto st0;
tr600:
#line 299 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Position is not a positive number");
        p--; {goto st708;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st708;}
    }
	goto st0;
tr604:
#line 304 "vcf_v41.ragel"
	{
        printf("Line %zu: Error in 'id' field\n", n_lines);
        p--; {goto st708;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st708;}
    }
	goto st0;
tr609:
#line 309 "vcf_v41.ragel"
	{
        printf("Line %zu: Error in 'reference' field\n", n_lines);
        p--; {goto st708;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st708;}
    }
	goto st0;
tr613:
#line 314 "vcf_v41.ragel"
	{
        printf("Line %zu: Error in 'alternate' field\n", n_lines);
        p--; {goto st708;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st708;}
    }
	goto st0;
tr622:
#line 319 "vcf_v41.ragel"
	{
        printf("Line %zu: Error in 'quality' field\n", n_lines);
        p--; {goto st708;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st708;}
    }
	goto st0;
tr626:
#line 324 "vcf_v41.ragel"
	{
        printf("Line %zu: Error in 'filter' field\n", n_lines);
        p--; {goto st708;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st708;}
    }
	goto st0;
tr631:
#line 329 "vcf_v41.ragel"
	{
        printf("Line %zu: Error in 'info' field\n", n_lines);
        p--; {goto st708;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st708;}
    }
	goto st0;
tr649:
#line 334 "vcf_v41.ragel"
	{
        printf("Line %zu: Error in 'format' field\n", n_lines);
        p--; {goto st708;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st708;}
    }
	goto st0;
tr658:
#line 339 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Incorrect sample format");
        p--; {goto st708;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st708;}
    }
	goto st0;
tr797:
#line 45 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        p--; {goto st708;}
    }
#line 294 "vcf_v41.ragel"
	{
        printf("Line %zu: Error in 'chrom' field\n", n_lines);
        p--; {goto st708;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st708;}
    }
	goto st0;
#line 801 "vcf_validator_detail.hpp"
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
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st15;
st15:
	if ( ++p == pe )
		goto _test_eof15;
case 15:
#line 906 "vcf_validator_detail.hpp"
	if ( (*p) == 10 )
		goto tr16;
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st15;
	goto tr14;
tr16:
#line 58 "vcf_v41.ragel"
	{
//        set_vcf_file_format(ts, p-ts, file);
    }
#line 23 "vcf_v41.ragel"
	{
        ++n_lines;
        n_columns = 1;
    }
	goto st16;
st16:
	if ( ++p == pe )
		goto _test_eof16;
case 16:
#line 927 "vcf_validator_detail.hpp"
	if ( (*p) == 35 )
		goto tr19;
	goto tr18;
tr19:
#line 62 "vcf_v41.ragel"
	{
//        printf("Reading meta entry\n");
//        status->current_meta_entry = vcf_meta_entry_new();
    }
	goto st17;
st17:
	if ( ++p == pe )
		goto _test_eof17;
case 17:
#line 942 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 35: goto st18;
		case 67: goto st505;
	}
	goto tr20;
st18:
	if ( ++p == pe )
		goto _test_eof18;
case 18:
	switch( (*p) ) {
		case 65: goto tr26;
		case 70: goto tr27;
		case 73: goto tr28;
		case 80: goto tr29;
		case 83: goto tr30;
		case 95: goto tr25;
		case 97: goto tr31;
		case 99: goto tr32;
		case 112: goto tr33;
	}
	if ( (*p) < 62 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto tr24;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 60 )
				goto tr24;
		} else
			goto tr25;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 66 <= (*p) && (*p) <= 90 )
				goto tr25;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr24;
			} else if ( (*p) >= 98 )
				goto tr25;
		} else
			goto tr24;
	} else
		goto tr24;
	goto tr23;
tr24:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st19;
st19:
	if ( ++p == pe )
		goto _test_eof19;
case 19:
#line 997 "vcf_validator_detail.hpp"
	if ( (*p) == 10 )
		goto tr35;
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st19;
	} else if ( (*p) >= 32 )
		goto st19;
	goto tr34;
tr35:
#line 75 "vcf_v41.ragel"
	{
/*        if (*ts == '<') {
            add_vcf_meta_entry_value(ts+1, p-ts-1, status->current_meta_entry);
        } else if (*(p-1) == '>') {
            add_vcf_meta_entry_value(ts, p-ts-1, status->current_meta_entry);
        } else {
            add_vcf_meta_entry_value(ts, p-ts, status->current_meta_entry);
        }*/
    }
#line 67 "vcf_v41.ragel"
	{
//        add_vcf_meta_entry(status->current_meta_entry, file);
    }
#line 23 "vcf_v41.ragel"
	{
        ++n_lines;
        n_columns = 1;
    }
	goto st20;
tr65:
#line 101 "vcf_v41.ragel"
	{
        printf("Meta in line %zu\n", n_lines);
    }
#line 67 "vcf_v41.ragel"
	{
//        add_vcf_meta_entry(status->current_meta_entry, file);
    }
#line 23 "vcf_v41.ragel"
	{
        ++n_lines;
        n_columns = 1;
    }
	goto st20;
tr177:
#line 85 "vcf_v41.ragel"
	{
        printf("Meta ALT in line %zu\n", n_lines);
    }
#line 67 "vcf_v41.ragel"
	{
//        add_vcf_meta_entry(status->current_meta_entry, file);
    }
#line 23 "vcf_v41.ragel"
	{
        ++n_lines;
        n_columns = 1;
    }
	goto st20;
tr232:
#line 89 "vcf_v41.ragel"
	{
        printf("Meta FILTER in line %zu\n", n_lines);
    }
#line 67 "vcf_v41.ragel"
	{
//        add_vcf_meta_entry(status->current_meta_entry, file);
    }
#line 23 "vcf_v41.ragel"
	{
        ++n_lines;
        n_columns = 1;
    }
	goto st20;
tr297:
#line 93 "vcf_v41.ragel"
	{
        printf("Meta FORMAT in line %zu\n", n_lines);
    }
#line 67 "vcf_v41.ragel"
	{
//        add_vcf_meta_entry(status->current_meta_entry, file);
    }
#line 23 "vcf_v41.ragel"
	{
        ++n_lines;
        n_columns = 1;
    }
	goto st20;
tr397:
#line 97 "vcf_v41.ragel"
	{
        printf("Meta INFO in line %zu\n", n_lines);
    }
#line 67 "vcf_v41.ragel"
	{
//        add_vcf_meta_entry(status->current_meta_entry, file);
    }
#line 23 "vcf_v41.ragel"
	{
        ++n_lines;
        n_columns = 1;
    }
	goto st20;
tr437:
#line 67 "vcf_v41.ragel"
	{
//        add_vcf_meta_entry(status->current_meta_entry, file);
    }
#line 23 "vcf_v41.ragel"
	{
        ++n_lines;
        n_columns = 1;
    }
	goto st20;
st20:
	if ( ++p == pe )
		goto _test_eof20;
case 20:
#line 1117 "vcf_validator_detail.hpp"
	if ( (*p) == 35 )
		goto tr19;
	goto tr20;
tr25:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st21;
st21:
	if ( ++p == pe )
		goto _test_eof21;
case 21:
#line 1131 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr39;
		case 95: goto st21;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st21;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st21;
	} else
		goto st21;
	goto tr37;
tr39:
#line 71 "vcf_v41.ragel"
	{
//        set_vcf_meta_entry_name(ts, p-ts, status->current_meta_entry);
    }
	goto st22;
st22:
	if ( ++p == pe )
		goto _test_eof22;
case 22:
#line 1168 "vcf_validator_detail.hpp"
	if ( (*p) == 60 )
		goto st23;
	if ( (*p) > 59 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st19;
	} else if ( (*p) >= 32 )
		goto st19;
	goto tr37;
st23:
	if ( ++p == pe )
		goto _test_eof23;
case 23:
	switch( (*p) ) {
		case 10: goto tr35;
		case 65: goto tr42;
		case 70: goto tr43;
		case 73: goto tr44;
		case 80: goto tr45;
		case 83: goto tr46;
		case 95: goto tr41;
		case 97: goto tr47;
		case 99: goto tr48;
		case 112: goto tr49;
	}
	if ( (*p) < 62 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 60 )
				goto st19;
		} else
			goto tr41;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 66 <= (*p) && (*p) <= 90 )
				goto tr41;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto st19;
			} else if ( (*p) >= 98 )
				goto tr41;
		} else
			goto st19;
	} else
		goto st19;
	goto tr37;
tr41:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st24;
st24:
	if ( ++p == pe )
		goto _test_eof24;
case 24:
#line 1227 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto st25;
		case 95: goto st24;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st24;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st24;
	} else
		goto st24;
	goto tr37;
st25:
	if ( ++p == pe )
		goto _test_eof25;
case 25:
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st26;
	} else if ( (*p) >= 32 )
		goto st26;
	goto tr37;
st26:
	if ( ++p == pe )
		goto _test_eof26;
case 26:
	switch( (*p) ) {
		case 44: goto tr53;
		case 62: goto tr54;
	}
	if ( (*p) > 60 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto st26;
	} else if ( (*p) >= 32 )
		goto st26;
	goto tr37;
tr53:
#line 75 "vcf_v41.ragel"
	{
/*        if (*ts == '<') {
            add_vcf_meta_entry_value(ts+1, p-ts-1, status->current_meta_entry);
        } else if (*(p-1) == '>') {
            add_vcf_meta_entry_value(ts, p-ts-1, status->current_meta_entry);
        } else {
            add_vcf_meta_entry_value(ts, p-ts, status->current_meta_entry);
        }*/
    }
	goto st27;
st27:
	if ( ++p == pe )
		goto _test_eof27;
case 27:
#line 1294 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto tr53;
		case 62: goto tr54;
		case 65: goto tr56;
		case 70: goto tr57;
		case 73: goto tr58;
		case 80: goto tr59;
		case 83: goto tr60;
		case 95: goto tr55;
		case 97: goto tr61;
		case 99: goto tr62;
		case 112: goto tr63;
	}
	if ( (*p) < 63 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st26;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 60 )
				goto st26;
		} else
			goto tr55;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 66 <= (*p) && (*p) <= 90 )
				goto tr55;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto st26;
			} else if ( (*p) >= 98 )
				goto tr55;
		} else
			goto st26;
	} else
		goto st26;
	goto tr37;
tr55:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st28;
st28:
	if ( ++p == pe )
		goto _test_eof28;
case 28:
#line 1342 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto tr53;
		case 61: goto st25;
		case 62: goto tr54;
		case 95: goto st28;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st26;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st26;
		} else
			goto st28;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st26;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st26;
		} else
			goto st28;
	} else
		goto st28;
	goto tr37;
tr54:
#line 75 "vcf_v41.ragel"
	{
/*        if (*ts == '<') {
            add_vcf_meta_entry_value(ts+1, p-ts-1, status->current_meta_entry);
        } else if (*(p-1) == '>') {
            add_vcf_meta_entry_value(ts, p-ts-1, status->current_meta_entry);
        } else {
            add_vcf_meta_entry_value(ts, p-ts, status->current_meta_entry);
        }*/
    }
	goto st29;
st29:
	if ( ++p == pe )
		goto _test_eof29;
case 29:
#line 1386 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr65;
		case 44: goto tr53;
		case 62: goto tr54;
	}
	if ( (*p) > 60 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto st26;
	} else if ( (*p) >= 32 )
		goto st26;
	goto tr37;
tr56:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st30;
st30:
	if ( ++p == pe )
		goto _test_eof30;
case 30:
#line 1408 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto tr53;
		case 61: goto st25;
		case 62: goto tr54;
		case 76: goto st31;
		case 95: goto st28;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st26;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st26;
		} else
			goto st28;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st26;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st26;
		} else
			goto st28;
	} else
		goto st28;
	goto tr37;
st31:
	if ( ++p == pe )
		goto _test_eof31;
case 31:
	switch( (*p) ) {
		case 44: goto tr53;
		case 61: goto st25;
		case 62: goto tr54;
		case 84: goto st32;
		case 95: goto st28;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st26;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st26;
		} else
			goto st28;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st26;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st26;
		} else
			goto st28;
	} else
		goto st28;
	goto tr37;
st32:
	if ( ++p == pe )
		goto _test_eof32;
case 32:
	switch( (*p) ) {
		case 44: goto tr53;
		case 62: goto tr54;
		case 95: goto st28;
	}
	if ( (*p) < 63 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st26;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 60 )
				goto st26;
		} else
			goto st28;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto st28;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto st26;
			} else if ( (*p) >= 97 )
				goto st28;
		} else
			goto st26;
	} else
		goto st26;
	goto tr37;
tr57:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st33;
st33:
	if ( ++p == pe )
		goto _test_eof33;
case 33:
#line 1512 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto tr53;
		case 61: goto st25;
		case 62: goto tr54;
		case 73: goto st34;
		case 79: goto st38;
		case 95: goto st28;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st26;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st26;
		} else
			goto st28;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st26;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st26;
		} else
			goto st28;
	} else
		goto st28;
	goto tr37;
st34:
	if ( ++p == pe )
		goto _test_eof34;
case 34:
	switch( (*p) ) {
		case 44: goto tr53;
		case 61: goto st25;
		case 62: goto tr54;
		case 76: goto st35;
		case 95: goto st28;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st26;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st26;
		} else
			goto st28;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st26;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st26;
		} else
			goto st28;
	} else
		goto st28;
	goto tr37;
st35:
	if ( ++p == pe )
		goto _test_eof35;
case 35:
	switch( (*p) ) {
		case 44: goto tr53;
		case 61: goto st25;
		case 62: goto tr54;
		case 84: goto st36;
		case 95: goto st28;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st26;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st26;
		} else
			goto st28;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st26;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st26;
		} else
			goto st28;
	} else
		goto st28;
	goto tr37;
st36:
	if ( ++p == pe )
		goto _test_eof36;
case 36:
	switch( (*p) ) {
		case 44: goto tr53;
		case 61: goto st25;
		case 62: goto tr54;
		case 69: goto st37;
		case 95: goto st28;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st26;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st26;
		} else
			goto st28;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st26;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st26;
		} else
			goto st28;
	} else
		goto st28;
	goto tr37;
st37:
	if ( ++p == pe )
		goto _test_eof37;
case 37:
	switch( (*p) ) {
		case 44: goto tr53;
		case 61: goto st25;
		case 62: goto tr54;
		case 82: goto st32;
		case 95: goto st28;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st26;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st26;
		} else
			goto st28;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st26;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st26;
		} else
			goto st28;
	} else
		goto st28;
	goto tr37;
st38:
	if ( ++p == pe )
		goto _test_eof38;
case 38:
	switch( (*p) ) {
		case 44: goto tr53;
		case 61: goto st25;
		case 62: goto tr54;
		case 82: goto st39;
		case 95: goto st28;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st26;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st26;
		} else
			goto st28;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st26;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st26;
		} else
			goto st28;
	} else
		goto st28;
	goto tr37;
st39:
	if ( ++p == pe )
		goto _test_eof39;
case 39:
	switch( (*p) ) {
		case 44: goto tr53;
		case 61: goto st25;
		case 62: goto tr54;
		case 77: goto st40;
		case 95: goto st28;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st26;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st26;
		} else
			goto st28;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st26;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st26;
		} else
			goto st28;
	} else
		goto st28;
	goto tr37;
st40:
	if ( ++p == pe )
		goto _test_eof40;
case 40:
	switch( (*p) ) {
		case 44: goto tr53;
		case 61: goto st25;
		case 62: goto tr54;
		case 65: goto st31;
		case 95: goto st28;
	}
	if ( (*p) < 66 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st26;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st26;
		} else
			goto st28;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st26;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st26;
		} else
			goto st28;
	} else
		goto st28;
	goto tr37;
tr58:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st41;
st41:
	if ( ++p == pe )
		goto _test_eof41;
case 41:
#line 1776 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto tr53;
		case 61: goto st25;
		case 62: goto tr54;
		case 78: goto st42;
		case 95: goto st28;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st26;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st26;
		} else
			goto st28;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st26;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st26;
		} else
			goto st28;
	} else
		goto st28;
	goto tr37;
st42:
	if ( ++p == pe )
		goto _test_eof42;
case 42:
	switch( (*p) ) {
		case 44: goto tr53;
		case 61: goto st25;
		case 62: goto tr54;
		case 70: goto st43;
		case 95: goto st28;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st26;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st26;
		} else
			goto st28;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st26;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st26;
		} else
			goto st28;
	} else
		goto st28;
	goto tr37;
st43:
	if ( ++p == pe )
		goto _test_eof43;
case 43:
	switch( (*p) ) {
		case 44: goto tr53;
		case 61: goto st25;
		case 62: goto tr54;
		case 79: goto st32;
		case 95: goto st28;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st26;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st26;
		} else
			goto st28;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st26;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st26;
		} else
			goto st28;
	} else
		goto st28;
	goto tr37;
tr59:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st44;
st44:
	if ( ++p == pe )
		goto _test_eof44;
case 44:
#line 1879 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto tr53;
		case 61: goto st25;
		case 62: goto tr54;
		case 69: goto st45;
		case 95: goto st28;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st26;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st26;
		} else
			goto st28;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st26;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st26;
		} else
			goto st28;
	} else
		goto st28;
	goto tr37;
st45:
	if ( ++p == pe )
		goto _test_eof45;
case 45:
	switch( (*p) ) {
		case 44: goto tr53;
		case 61: goto st25;
		case 62: goto tr54;
		case 68: goto st46;
		case 95: goto st28;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st26;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st26;
		} else
			goto st28;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st26;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st26;
		} else
			goto st28;
	} else
		goto st28;
	goto tr37;
st46:
	if ( ++p == pe )
		goto _test_eof46;
case 46:
	switch( (*p) ) {
		case 44: goto tr53;
		case 61: goto st25;
		case 62: goto tr54;
		case 73: goto st47;
		case 95: goto st28;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st26;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st26;
		} else
			goto st28;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st26;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st26;
		} else
			goto st28;
	} else
		goto st28;
	goto tr37;
st47:
	if ( ++p == pe )
		goto _test_eof47;
case 47:
	switch( (*p) ) {
		case 44: goto tr53;
		case 61: goto st25;
		case 62: goto tr54;
		case 71: goto st48;
		case 95: goto st28;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st26;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st26;
		} else
			goto st28;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st26;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st26;
		} else
			goto st28;
	} else
		goto st28;
	goto tr37;
st48:
	if ( ++p == pe )
		goto _test_eof48;
case 48:
	switch( (*p) ) {
		case 44: goto tr53;
		case 61: goto st25;
		case 62: goto tr54;
		case 82: goto st49;
		case 95: goto st28;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st26;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st26;
		} else
			goto st28;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st26;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st26;
		} else
			goto st28;
	} else
		goto st28;
	goto tr37;
st49:
	if ( ++p == pe )
		goto _test_eof49;
case 49:
	switch( (*p) ) {
		case 44: goto tr53;
		case 61: goto st25;
		case 62: goto tr54;
		case 69: goto st50;
		case 95: goto st28;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st26;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st26;
		} else
			goto st28;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st26;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st26;
		} else
			goto st28;
	} else
		goto st28;
	goto tr37;
st50:
	if ( ++p == pe )
		goto _test_eof50;
case 50:
	switch( (*p) ) {
		case 44: goto tr53;
		case 61: goto st25;
		case 62: goto tr54;
		case 69: goto st32;
		case 95: goto st28;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st26;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st26;
		} else
			goto st28;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st26;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st26;
		} else
			goto st28;
	} else
		goto st28;
	goto tr37;
tr60:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st51;
st51:
	if ( ++p == pe )
		goto _test_eof51;
case 51:
#line 2110 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto tr53;
		case 61: goto st25;
		case 62: goto tr54;
		case 65: goto st52;
		case 95: goto st28;
	}
	if ( (*p) < 66 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st26;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st26;
		} else
			goto st28;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st26;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st26;
		} else
			goto st28;
	} else
		goto st28;
	goto tr37;
st52:
	if ( ++p == pe )
		goto _test_eof52;
case 52:
	switch( (*p) ) {
		case 44: goto tr53;
		case 61: goto st25;
		case 62: goto tr54;
		case 77: goto st53;
		case 95: goto st28;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st26;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st26;
		} else
			goto st28;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st26;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st26;
		} else
			goto st28;
	} else
		goto st28;
	goto tr37;
st53:
	if ( ++p == pe )
		goto _test_eof53;
case 53:
	switch( (*p) ) {
		case 44: goto tr53;
		case 61: goto st25;
		case 62: goto tr54;
		case 80: goto st54;
		case 95: goto st28;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st26;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st26;
		} else
			goto st28;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st26;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st26;
		} else
			goto st28;
	} else
		goto st28;
	goto tr37;
st54:
	if ( ++p == pe )
		goto _test_eof54;
case 54:
	switch( (*p) ) {
		case 44: goto tr53;
		case 61: goto st25;
		case 62: goto tr54;
		case 76: goto st50;
		case 95: goto st28;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st26;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st26;
		} else
			goto st28;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st26;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st26;
		} else
			goto st28;
	} else
		goto st28;
	goto tr37;
tr61:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st55;
st55:
	if ( ++p == pe )
		goto _test_eof55;
case 55:
#line 2245 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto tr53;
		case 61: goto st25;
		case 62: goto tr54;
		case 95: goto st28;
		case 115: goto st56;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st26;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st26;
		} else
			goto st28;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st26;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st26;
		} else
			goto st28;
	} else
		goto st28;
	goto tr37;
st56:
	if ( ++p == pe )
		goto _test_eof56;
case 56:
	switch( (*p) ) {
		case 44: goto tr53;
		case 61: goto st25;
		case 62: goto tr54;
		case 95: goto st28;
		case 115: goto st57;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st26;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st26;
		} else
			goto st28;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st26;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st26;
		} else
			goto st28;
	} else
		goto st28;
	goto tr37;
st57:
	if ( ++p == pe )
		goto _test_eof57;
case 57:
	switch( (*p) ) {
		case 44: goto tr53;
		case 61: goto st25;
		case 62: goto tr54;
		case 95: goto st28;
		case 101: goto st58;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st26;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st26;
		} else
			goto st28;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st26;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st26;
		} else
			goto st28;
	} else
		goto st28;
	goto tr37;
st58:
	if ( ++p == pe )
		goto _test_eof58;
case 58:
	switch( (*p) ) {
		case 44: goto tr53;
		case 61: goto st25;
		case 62: goto tr54;
		case 95: goto st28;
		case 109: goto st59;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st26;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st26;
		} else
			goto st28;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st26;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st26;
		} else
			goto st28;
	} else
		goto st28;
	goto tr37;
st59:
	if ( ++p == pe )
		goto _test_eof59;
case 59:
	switch( (*p) ) {
		case 44: goto tr53;
		case 61: goto st25;
		case 62: goto tr54;
		case 95: goto st28;
		case 98: goto st60;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st26;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st26;
		} else
			goto st28;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st26;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st26;
		} else
			goto st28;
	} else
		goto st28;
	goto tr37;
st60:
	if ( ++p == pe )
		goto _test_eof60;
case 60:
	switch( (*p) ) {
		case 44: goto tr53;
		case 61: goto st25;
		case 62: goto tr54;
		case 95: goto st28;
		case 108: goto st61;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st26;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st26;
		} else
			goto st28;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st26;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st26;
		} else
			goto st28;
	} else
		goto st28;
	goto tr37;
st61:
	if ( ++p == pe )
		goto _test_eof61;
case 61:
	switch( (*p) ) {
		case 44: goto tr53;
		case 61: goto st25;
		case 62: goto tr54;
		case 95: goto st28;
		case 121: goto st32;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st26;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st26;
		} else
			goto st28;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st26;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st26;
		} else
			goto st28;
	} else
		goto st28;
	goto tr37;
tr62:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st62;
st62:
	if ( ++p == pe )
		goto _test_eof62;
case 62:
#line 2476 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto tr53;
		case 61: goto st25;
		case 62: goto tr54;
		case 95: goto st28;
		case 111: goto st63;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st26;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st26;
		} else
			goto st28;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st26;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st26;
		} else
			goto st28;
	} else
		goto st28;
	goto tr37;
st63:
	if ( ++p == pe )
		goto _test_eof63;
case 63:
	switch( (*p) ) {
		case 44: goto tr53;
		case 61: goto st25;
		case 62: goto tr54;
		case 95: goto st28;
		case 110: goto st64;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st26;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st26;
		} else
			goto st28;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st26;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st26;
		} else
			goto st28;
	} else
		goto st28;
	goto tr37;
st64:
	if ( ++p == pe )
		goto _test_eof64;
case 64:
	switch( (*p) ) {
		case 44: goto tr53;
		case 61: goto st25;
		case 62: goto tr54;
		case 95: goto st28;
		case 116: goto st65;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st26;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st26;
		} else
			goto st28;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st26;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st26;
		} else
			goto st28;
	} else
		goto st28;
	goto tr37;
st65:
	if ( ++p == pe )
		goto _test_eof65;
case 65:
	switch( (*p) ) {
		case 44: goto tr53;
		case 61: goto st25;
		case 62: goto tr54;
		case 95: goto st28;
		case 105: goto st66;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st26;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st26;
		} else
			goto st28;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st26;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st26;
		} else
			goto st28;
	} else
		goto st28;
	goto tr37;
st66:
	if ( ++p == pe )
		goto _test_eof66;
case 66:
	switch( (*p) ) {
		case 44: goto tr53;
		case 61: goto st25;
		case 62: goto tr54;
		case 95: goto st28;
		case 103: goto st32;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st26;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st26;
		} else
			goto st28;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st26;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st26;
		} else
			goto st28;
	} else
		goto st28;
	goto tr37;
tr63:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st67;
st67:
	if ( ++p == pe )
		goto _test_eof67;
case 67:
#line 2643 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto tr53;
		case 61: goto st25;
		case 62: goto tr54;
		case 95: goto st28;
		case 101: goto st68;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st26;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st26;
		} else
			goto st28;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st26;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st26;
		} else
			goto st28;
	} else
		goto st28;
	goto tr37;
st68:
	if ( ++p == pe )
		goto _test_eof68;
case 68:
	switch( (*p) ) {
		case 44: goto tr53;
		case 61: goto st25;
		case 62: goto tr54;
		case 95: goto st28;
		case 100: goto st69;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st26;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st26;
		} else
			goto st28;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st26;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st26;
		} else
			goto st28;
	} else
		goto st28;
	goto tr37;
st69:
	if ( ++p == pe )
		goto _test_eof69;
case 69:
	switch( (*p) ) {
		case 44: goto tr53;
		case 61: goto st25;
		case 62: goto tr54;
		case 95: goto st28;
		case 105: goto st70;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st26;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st26;
		} else
			goto st28;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st26;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st26;
		} else
			goto st28;
	} else
		goto st28;
	goto tr37;
st70:
	if ( ++p == pe )
		goto _test_eof70;
case 70:
	switch( (*p) ) {
		case 44: goto tr53;
		case 61: goto st25;
		case 62: goto tr54;
		case 95: goto st28;
		case 103: goto st71;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st26;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st26;
		} else
			goto st28;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st26;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st26;
		} else
			goto st28;
	} else
		goto st28;
	goto tr37;
st71:
	if ( ++p == pe )
		goto _test_eof71;
case 71:
	switch( (*p) ) {
		case 44: goto tr53;
		case 61: goto st25;
		case 62: goto tr54;
		case 95: goto st28;
		case 114: goto st72;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st26;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st26;
		} else
			goto st28;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st26;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st26;
		} else
			goto st28;
	} else
		goto st28;
	goto tr37;
st72:
	if ( ++p == pe )
		goto _test_eof72;
case 72:
	switch( (*p) ) {
		case 44: goto tr53;
		case 61: goto st25;
		case 62: goto tr54;
		case 95: goto st28;
		case 101: goto st73;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st26;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st26;
		} else
			goto st28;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st26;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st26;
		} else
			goto st28;
	} else
		goto st28;
	goto tr37;
st73:
	if ( ++p == pe )
		goto _test_eof73;
case 73:
	switch( (*p) ) {
		case 44: goto tr53;
		case 61: goto st25;
		case 62: goto tr54;
		case 95: goto st28;
		case 101: goto st74;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st26;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st26;
		} else
			goto st28;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st26;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st26;
		} else
			goto st28;
	} else
		goto st28;
	goto tr37;
st74:
	if ( ++p == pe )
		goto _test_eof74;
case 74:
	switch( (*p) ) {
		case 44: goto tr53;
		case 61: goto st25;
		case 62: goto tr54;
		case 68: goto st75;
		case 95: goto st28;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st26;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st26;
		} else
			goto st28;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st26;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st26;
		} else
			goto st28;
	} else
		goto st28;
	goto tr37;
st75:
	if ( ++p == pe )
		goto _test_eof75;
case 75:
	switch( (*p) ) {
		case 44: goto tr53;
		case 61: goto st25;
		case 62: goto tr54;
		case 66: goto st32;
		case 95: goto st28;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st26;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st26;
		} else
			goto st28;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st26;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st26;
		} else
			goto st28;
	} else
		goto st28;
	goto tr37;
tr42:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st76;
st76:
	if ( ++p == pe )
		goto _test_eof76;
case 76:
#line 2938 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto st25;
		case 76: goto st77;
		case 95: goto st24;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st24;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st24;
	} else
		goto st24;
	goto tr37;
st77:
	if ( ++p == pe )
		goto _test_eof77;
case 77:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto st25;
		case 84: goto st78;
		case 95: goto st24;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st24;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st24;
	} else
		goto st24;
	goto tr37;
st78:
	if ( ++p == pe )
		goto _test_eof78;
case 78:
	switch( (*p) ) {
		case 10: goto tr35;
		case 95: goto st24;
	}
	if ( (*p) < 62 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 60 )
				goto st19;
		} else
			goto st24;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto st24;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto st19;
			} else if ( (*p) >= 97 )
				goto st24;
		} else
			goto st19;
	} else
		goto st19;
	goto tr37;
tr43:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st79;
st79:
	if ( ++p == pe )
		goto _test_eof79;
case 79:
#line 3039 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto st25;
		case 73: goto st80;
		case 79: goto st84;
		case 95: goto st24;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st24;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st24;
	} else
		goto st24;
	goto tr37;
st80:
	if ( ++p == pe )
		goto _test_eof80;
case 80:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto st25;
		case 76: goto st81;
		case 95: goto st24;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st24;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st24;
	} else
		goto st24;
	goto tr37;
st81:
	if ( ++p == pe )
		goto _test_eof81;
case 81:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto st25;
		case 84: goto st82;
		case 95: goto st24;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st24;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st24;
	} else
		goto st24;
	goto tr37;
st82:
	if ( ++p == pe )
		goto _test_eof82;
case 82:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto st25;
		case 69: goto st83;
		case 95: goto st24;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st24;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st24;
	} else
		goto st24;
	goto tr37;
st83:
	if ( ++p == pe )
		goto _test_eof83;
case 83:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto st25;
		case 82: goto st78;
		case 95: goto st24;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st24;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st24;
	} else
		goto st24;
	goto tr37;
st84:
	if ( ++p == pe )
		goto _test_eof84;
case 84:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto st25;
		case 82: goto st85;
		case 95: goto st24;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st24;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st24;
	} else
		goto st24;
	goto tr37;
st85:
	if ( ++p == pe )
		goto _test_eof85;
case 85:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto st25;
		case 77: goto st86;
		case 95: goto st24;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st24;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st24;
	} else
		goto st24;
	goto tr37;
st86:
	if ( ++p == pe )
		goto _test_eof86;
case 86:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto st25;
		case 65: goto st77;
		case 95: goto st24;
	}
	if ( (*p) < 66 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st24;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st24;
	} else
		goto st24;
	goto tr37;
tr44:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st87;
st87:
	if ( ++p == pe )
		goto _test_eof87;
case 87:
#line 3295 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto st25;
		case 78: goto st88;
		case 95: goto st24;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st24;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st24;
	} else
		goto st24;
	goto tr37;
st88:
	if ( ++p == pe )
		goto _test_eof88;
case 88:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto st25;
		case 70: goto st89;
		case 95: goto st24;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st24;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st24;
	} else
		goto st24;
	goto tr37;
st89:
	if ( ++p == pe )
		goto _test_eof89;
case 89:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto st25;
		case 79: goto st78;
		case 95: goto st24;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st24;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st24;
	} else
		goto st24;
	goto tr37;
tr45:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st90;
st90:
	if ( ++p == pe )
		goto _test_eof90;
case 90:
#line 3395 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto st25;
		case 69: goto st91;
		case 95: goto st24;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st24;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st24;
	} else
		goto st24;
	goto tr37;
st91:
	if ( ++p == pe )
		goto _test_eof91;
case 91:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto st25;
		case 68: goto st92;
		case 95: goto st24;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st24;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st24;
	} else
		goto st24;
	goto tr37;
st92:
	if ( ++p == pe )
		goto _test_eof92;
case 92:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto st25;
		case 73: goto st93;
		case 95: goto st24;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st24;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st24;
	} else
		goto st24;
	goto tr37;
st93:
	if ( ++p == pe )
		goto _test_eof93;
case 93:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto st25;
		case 71: goto st94;
		case 95: goto st24;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st24;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st24;
	} else
		goto st24;
	goto tr37;
st94:
	if ( ++p == pe )
		goto _test_eof94;
case 94:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto st25;
		case 82: goto st95;
		case 95: goto st24;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st24;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st24;
	} else
		goto st24;
	goto tr37;
st95:
	if ( ++p == pe )
		goto _test_eof95;
case 95:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto st25;
		case 69: goto st96;
		case 95: goto st24;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st24;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st24;
	} else
		goto st24;
	goto tr37;
st96:
	if ( ++p == pe )
		goto _test_eof96;
case 96:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto st25;
		case 69: goto st78;
		case 95: goto st24;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st24;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st24;
	} else
		goto st24;
	goto tr37;
tr46:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st97;
st97:
	if ( ++p == pe )
		goto _test_eof97;
case 97:
#line 3619 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto st25;
		case 65: goto st98;
		case 95: goto st24;
	}
	if ( (*p) < 66 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st24;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st24;
	} else
		goto st24;
	goto tr37;
st98:
	if ( ++p == pe )
		goto _test_eof98;
case 98:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto st25;
		case 77: goto st99;
		case 95: goto st24;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st24;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st24;
	} else
		goto st24;
	goto tr37;
st99:
	if ( ++p == pe )
		goto _test_eof99;
case 99:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto st25;
		case 80: goto st100;
		case 95: goto st24;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st24;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st24;
	} else
		goto st24;
	goto tr37;
st100:
	if ( ++p == pe )
		goto _test_eof100;
case 100:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto st25;
		case 76: goto st96;
		case 95: goto st24;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st24;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st24;
	} else
		goto st24;
	goto tr37;
tr47:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st101;
st101:
	if ( ++p == pe )
		goto _test_eof101;
case 101:
#line 3750 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto st25;
		case 95: goto st24;
		case 115: goto st102;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st24;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st24;
	} else
		goto st24;
	goto tr37;
st102:
	if ( ++p == pe )
		goto _test_eof102;
case 102:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto st25;
		case 95: goto st24;
		case 115: goto st103;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st24;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st24;
	} else
		goto st24;
	goto tr37;
st103:
	if ( ++p == pe )
		goto _test_eof103;
case 103:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto st25;
		case 95: goto st24;
		case 101: goto st104;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st24;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st24;
	} else
		goto st24;
	goto tr37;
st104:
	if ( ++p == pe )
		goto _test_eof104;
case 104:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto st25;
		case 95: goto st24;
		case 109: goto st105;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st24;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st24;
	} else
		goto st24;
	goto tr37;
st105:
	if ( ++p == pe )
		goto _test_eof105;
case 105:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto st25;
		case 95: goto st24;
		case 98: goto st106;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st24;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st24;
	} else
		goto st24;
	goto tr37;
st106:
	if ( ++p == pe )
		goto _test_eof106;
case 106:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto st25;
		case 95: goto st24;
		case 108: goto st107;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st24;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st24;
	} else
		goto st24;
	goto tr37;
st107:
	if ( ++p == pe )
		goto _test_eof107;
case 107:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto st25;
		case 95: goto st24;
		case 121: goto st78;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st24;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st24;
	} else
		goto st24;
	goto tr37;
tr48:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st108;
st108:
	if ( ++p == pe )
		goto _test_eof108;
case 108:
#line 3974 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto st25;
		case 95: goto st24;
		case 111: goto st109;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st24;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st24;
	} else
		goto st24;
	goto tr37;
st109:
	if ( ++p == pe )
		goto _test_eof109;
case 109:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto st25;
		case 95: goto st24;
		case 110: goto st110;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st24;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st24;
	} else
		goto st24;
	goto tr37;
st110:
	if ( ++p == pe )
		goto _test_eof110;
case 110:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto st25;
		case 95: goto st24;
		case 116: goto st111;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st24;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st24;
	} else
		goto st24;
	goto tr37;
st111:
	if ( ++p == pe )
		goto _test_eof111;
case 111:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto st25;
		case 95: goto st24;
		case 105: goto st112;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st24;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st24;
	} else
		goto st24;
	goto tr37;
st112:
	if ( ++p == pe )
		goto _test_eof112;
case 112:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto st25;
		case 95: goto st24;
		case 103: goto st78;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st24;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st24;
	} else
		goto st24;
	goto tr37;
tr49:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st113;
st113:
	if ( ++p == pe )
		goto _test_eof113;
case 113:
#line 4136 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto st25;
		case 95: goto st24;
		case 101: goto st114;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st24;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st24;
	} else
		goto st24;
	goto tr37;
st114:
	if ( ++p == pe )
		goto _test_eof114;
case 114:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto st25;
		case 95: goto st24;
		case 100: goto st115;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st24;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st24;
	} else
		goto st24;
	goto tr37;
st115:
	if ( ++p == pe )
		goto _test_eof115;
case 115:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto st25;
		case 95: goto st24;
		case 105: goto st116;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st24;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st24;
	} else
		goto st24;
	goto tr37;
st116:
	if ( ++p == pe )
		goto _test_eof116;
case 116:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto st25;
		case 95: goto st24;
		case 103: goto st117;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st24;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st24;
	} else
		goto st24;
	goto tr37;
st117:
	if ( ++p == pe )
		goto _test_eof117;
case 117:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto st25;
		case 95: goto st24;
		case 114: goto st118;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st24;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st24;
	} else
		goto st24;
	goto tr37;
st118:
	if ( ++p == pe )
		goto _test_eof118;
case 118:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto st25;
		case 95: goto st24;
		case 101: goto st119;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st24;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st24;
	} else
		goto st24;
	goto tr37;
st119:
	if ( ++p == pe )
		goto _test_eof119;
case 119:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto st25;
		case 95: goto st24;
		case 101: goto st120;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st24;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st24;
	} else
		goto st24;
	goto tr37;
st120:
	if ( ++p == pe )
		goto _test_eof120;
case 120:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto st25;
		case 68: goto st121;
		case 95: goto st24;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st24;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st24;
	} else
		goto st24;
	goto tr37;
st121:
	if ( ++p == pe )
		goto _test_eof121;
case 121:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto st25;
		case 66: goto st78;
		case 95: goto st24;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st24;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st24;
	} else
		goto st24;
	goto tr37;
tr26:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st122;
st122:
	if ( ++p == pe )
		goto _test_eof122;
case 122:
#line 4422 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr39;
		case 76: goto st123;
		case 95: goto st21;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st21;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st21;
	} else
		goto st21;
	goto tr142;
st123:
	if ( ++p == pe )
		goto _test_eof123;
case 123:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr39;
		case 84: goto st124;
		case 95: goto st21;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st21;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st21;
	} else
		goto st21;
	goto tr142;
st124:
	if ( ++p == pe )
		goto _test_eof124;
case 124:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto st125;
		case 95: goto st21;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st21;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st21;
	} else
		goto st21;
	goto tr142;
st125:
	if ( ++p == pe )
		goto _test_eof125;
case 125:
	if ( (*p) == 60 )
		goto st126;
	goto tr146;
st126:
	if ( ++p == pe )
		goto _test_eof126;
case 126:
	if ( (*p) == 73 )
		goto st127;
	goto tr146;
st127:
	if ( ++p == pe )
		goto _test_eof127;
case 127:
	if ( (*p) == 68 )
		goto st128;
	goto tr146;
st128:
	if ( ++p == pe )
		goto _test_eof128;
case 128:
	if ( (*p) == 61 )
		goto st129;
	goto tr146;
st129:
	if ( ++p == pe )
		goto _test_eof129;
case 129:
	switch( (*p) ) {
		case 67: goto st130;
		case 68: goto st164;
		case 73: goto st167;
	}
	goto tr151;
st130:
	if ( ++p == pe )
		goto _test_eof130;
case 130:
	if ( (*p) == 78 )
		goto st131;
	goto tr151;
st131:
	if ( ++p == pe )
		goto _test_eof131;
case 131:
	if ( (*p) == 86 )
		goto st132;
	goto tr151;
st132:
	if ( ++p == pe )
		goto _test_eof132;
case 132:
	switch( (*p) ) {
		case 44: goto st133;
		case 58: goto st150;
	}
	goto tr157;
st133:
	if ( ++p == pe )
		goto _test_eof133;
case 133:
	if ( (*p) == 68 )
		goto st134;
	goto tr146;
st134:
	if ( ++p == pe )
		goto _test_eof134;
case 134:
	if ( (*p) == 101 )
		goto st135;
	goto tr146;
st135:
	if ( ++p == pe )
		goto _test_eof135;
case 135:
	if ( (*p) == 115 )
		goto st136;
	goto tr146;
st136:
	if ( ++p == pe )
		goto _test_eof136;
case 136:
	if ( (*p) == 99 )
		goto st137;
	goto tr146;
st137:
	if ( ++p == pe )
		goto _test_eof137;
case 137:
	if ( (*p) == 114 )
		goto st138;
	goto tr146;
st138:
	if ( ++p == pe )
		goto _test_eof138;
case 138:
	if ( (*p) == 105 )
		goto st139;
	goto tr146;
st139:
	if ( ++p == pe )
		goto _test_eof139;
case 139:
	if ( (*p) == 112 )
		goto st140;
	goto tr146;
st140:
	if ( ++p == pe )
		goto _test_eof140;
case 140:
	if ( (*p) == 116 )
		goto st141;
	goto tr146;
st141:
	if ( ++p == pe )
		goto _test_eof141;
case 141:
	if ( (*p) == 105 )
		goto st142;
	goto tr146;
st142:
	if ( ++p == pe )
		goto _test_eof142;
case 142:
	if ( (*p) == 111 )
		goto st143;
	goto tr146;
st143:
	if ( ++p == pe )
		goto _test_eof143;
case 143:
	if ( (*p) == 110 )
		goto st144;
	goto tr146;
st144:
	if ( ++p == pe )
		goto _test_eof144;
case 144:
	if ( (*p) == 61 )
		goto st145;
	goto tr146;
st145:
	if ( ++p == pe )
		goto _test_eof145;
case 145:
	if ( (*p) == 34 )
		goto st146;
	goto tr146;
st146:
	if ( ++p == pe )
		goto _test_eof146;
case 146:
	if ( (*p) > 33 ) {
		if ( 35 <= (*p) && (*p) <= 126 )
			goto st147;
	} else if ( (*p) >= 32 )
		goto st147;
	goto tr146;
st147:
	if ( ++p == pe )
		goto _test_eof147;
case 147:
	if ( (*p) == 34 )
		goto st148;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto st147;
	goto tr174;
st148:
	if ( ++p == pe )
		goto _test_eof148;
case 148:
	if ( (*p) == 62 )
		goto st149;
	goto tr174;
st149:
	if ( ++p == pe )
		goto _test_eof149;
case 149:
	if ( (*p) == 10 )
		goto tr177;
	goto tr146;
st150:
	if ( ++p == pe )
		goto _test_eof150;
case 150:
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st151;
	} else if ( (*p) >= 32 )
		goto st151;
	goto tr178;
st151:
	if ( ++p == pe )
		goto _test_eof151;
case 151:
	if ( (*p) == 44 )
		goto st152;
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st151;
	} else if ( (*p) >= 32 )
		goto st151;
	goto tr178;
st152:
	if ( ++p == pe )
		goto _test_eof152;
case 152:
	switch( (*p) ) {
		case 44: goto st152;
		case 68: goto st153;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st151;
	} else if ( (*p) >= 32 )
		goto st151;
	goto tr178;
st153:
	if ( ++p == pe )
		goto _test_eof153;
case 153:
	switch( (*p) ) {
		case 44: goto st152;
		case 101: goto st154;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st151;
	} else if ( (*p) >= 32 )
		goto st151;
	goto tr178;
st154:
	if ( ++p == pe )
		goto _test_eof154;
case 154:
	switch( (*p) ) {
		case 44: goto st152;
		case 115: goto st155;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st151;
	} else if ( (*p) >= 32 )
		goto st151;
	goto tr178;
st155:
	if ( ++p == pe )
		goto _test_eof155;
case 155:
	switch( (*p) ) {
		case 44: goto st152;
		case 99: goto st156;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st151;
	} else if ( (*p) >= 32 )
		goto st151;
	goto tr178;
st156:
	if ( ++p == pe )
		goto _test_eof156;
case 156:
	switch( (*p) ) {
		case 44: goto st152;
		case 114: goto st157;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st151;
	} else if ( (*p) >= 32 )
		goto st151;
	goto tr178;
st157:
	if ( ++p == pe )
		goto _test_eof157;
case 157:
	switch( (*p) ) {
		case 44: goto st152;
		case 105: goto st158;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st151;
	} else if ( (*p) >= 32 )
		goto st151;
	goto tr178;
st158:
	if ( ++p == pe )
		goto _test_eof158;
case 158:
	switch( (*p) ) {
		case 44: goto st152;
		case 112: goto st159;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st151;
	} else if ( (*p) >= 32 )
		goto st151;
	goto tr178;
st159:
	if ( ++p == pe )
		goto _test_eof159;
case 159:
	switch( (*p) ) {
		case 44: goto st152;
		case 116: goto st160;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st151;
	} else if ( (*p) >= 32 )
		goto st151;
	goto tr178;
st160:
	if ( ++p == pe )
		goto _test_eof160;
case 160:
	switch( (*p) ) {
		case 44: goto st152;
		case 105: goto st161;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st151;
	} else if ( (*p) >= 32 )
		goto st151;
	goto tr178;
st161:
	if ( ++p == pe )
		goto _test_eof161;
case 161:
	switch( (*p) ) {
		case 44: goto st152;
		case 111: goto st162;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st151;
	} else if ( (*p) >= 32 )
		goto st151;
	goto tr178;
st162:
	if ( ++p == pe )
		goto _test_eof162;
case 162:
	switch( (*p) ) {
		case 44: goto st152;
		case 110: goto st163;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st151;
	} else if ( (*p) >= 32 )
		goto st151;
	goto tr178;
st163:
	if ( ++p == pe )
		goto _test_eof163;
case 163:
	switch( (*p) ) {
		case 44: goto st152;
		case 61: goto st145;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto st151;
	goto tr178;
st164:
	if ( ++p == pe )
		goto _test_eof164;
case 164:
	switch( (*p) ) {
		case 69: goto st165;
		case 85: goto st166;
	}
	goto tr151;
st165:
	if ( ++p == pe )
		goto _test_eof165;
case 165:
	if ( (*p) == 76 )
		goto st132;
	goto tr151;
st166:
	if ( ++p == pe )
		goto _test_eof166;
case 166:
	if ( (*p) == 80 )
		goto st132;
	goto tr151;
st167:
	if ( ++p == pe )
		goto _test_eof167;
case 167:
	if ( (*p) == 78 )
		goto st168;
	goto tr151;
st168:
	if ( ++p == pe )
		goto _test_eof168;
case 168:
	switch( (*p) ) {
		case 83: goto st132;
		case 86: goto st132;
	}
	goto tr151;
tr27:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st169;
st169:
	if ( ++p == pe )
		goto _test_eof169;
case 169:
#line 4932 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr39;
		case 73: goto st170;
		case 79: goto st201;
		case 95: goto st21;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st21;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st21;
	} else
		goto st21;
	goto tr195;
st170:
	if ( ++p == pe )
		goto _test_eof170;
case 170:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr39;
		case 76: goto st171;
		case 95: goto st21;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st21;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st21;
	} else
		goto st21;
	goto tr198;
st171:
	if ( ++p == pe )
		goto _test_eof171;
case 171:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr39;
		case 84: goto st172;
		case 95: goto st21;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st21;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st21;
	} else
		goto st21;
	goto tr198;
st172:
	if ( ++p == pe )
		goto _test_eof172;
case 172:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr39;
		case 69: goto st173;
		case 95: goto st21;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st21;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st21;
	} else
		goto st21;
	goto tr198;
st173:
	if ( ++p == pe )
		goto _test_eof173;
case 173:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr39;
		case 82: goto st174;
		case 95: goto st21;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st21;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st21;
	} else
		goto st21;
	goto tr198;
st174:
	if ( ++p == pe )
		goto _test_eof174;
case 174:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto st175;
		case 95: goto st21;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st21;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st21;
	} else
		goto st21;
	goto tr198;
st175:
	if ( ++p == pe )
		goto _test_eof175;
case 175:
	if ( (*p) == 60 )
		goto st176;
	goto tr204;
st176:
	if ( ++p == pe )
		goto _test_eof176;
case 176:
	if ( (*p) == 73 )
		goto st177;
	goto tr204;
st177:
	if ( ++p == pe )
		goto _test_eof177;
case 177:
	if ( (*p) == 68 )
		goto st178;
	goto tr204;
st178:
	if ( ++p == pe )
		goto _test_eof178;
case 178:
	if ( (*p) == 61 )
		goto st179;
	goto tr204;
st179:
	if ( ++p == pe )
		goto _test_eof179;
case 179:
	switch( (*p) ) {
		case 45: goto st180;
		case 46: goto st199;
		case 95: goto st200;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st181;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st181;
	} else
		goto st181;
	goto tr209;
st180:
	if ( ++p == pe )
		goto _test_eof180;
case 180:
	switch( (*p) ) {
		case 45: goto st180;
		case 46: goto st181;
		case 95: goto st181;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st181;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st181;
	} else
		goto st181;
	goto tr209;
st181:
	if ( ++p == pe )
		goto _test_eof181;
case 181:
	switch( (*p) ) {
		case 44: goto st182;
		case 95: goto st181;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st181;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st181;
		} else if ( (*p) >= 65 )
			goto st181;
	} else
		goto st181;
	goto tr209;
st182:
	if ( ++p == pe )
		goto _test_eof182;
case 182:
	if ( (*p) == 68 )
		goto st183;
	goto tr204;
st183:
	if ( ++p == pe )
		goto _test_eof183;
case 183:
	if ( (*p) == 101 )
		goto st184;
	goto tr204;
st184:
	if ( ++p == pe )
		goto _test_eof184;
case 184:
	if ( (*p) == 115 )
		goto st185;
	goto tr204;
st185:
	if ( ++p == pe )
		goto _test_eof185;
case 185:
	if ( (*p) == 99 )
		goto st186;
	goto tr204;
st186:
	if ( ++p == pe )
		goto _test_eof186;
case 186:
	if ( (*p) == 114 )
		goto st187;
	goto tr204;
st187:
	if ( ++p == pe )
		goto _test_eof187;
case 187:
	if ( (*p) == 105 )
		goto st188;
	goto tr204;
st188:
	if ( ++p == pe )
		goto _test_eof188;
case 188:
	if ( (*p) == 112 )
		goto st189;
	goto tr204;
st189:
	if ( ++p == pe )
		goto _test_eof189;
case 189:
	if ( (*p) == 116 )
		goto st190;
	goto tr204;
st190:
	if ( ++p == pe )
		goto _test_eof190;
case 190:
	if ( (*p) == 105 )
		goto st191;
	goto tr204;
st191:
	if ( ++p == pe )
		goto _test_eof191;
case 191:
	if ( (*p) == 111 )
		goto st192;
	goto tr204;
st192:
	if ( ++p == pe )
		goto _test_eof192;
case 192:
	if ( (*p) == 110 )
		goto st193;
	goto tr204;
st193:
	if ( ++p == pe )
		goto _test_eof193;
case 193:
	if ( (*p) == 61 )
		goto st194;
	goto tr204;
st194:
	if ( ++p == pe )
		goto _test_eof194;
case 194:
	if ( (*p) == 34 )
		goto st195;
	goto tr204;
st195:
	if ( ++p == pe )
		goto _test_eof195;
case 195:
	if ( (*p) > 33 ) {
		if ( 35 <= (*p) && (*p) <= 126 )
			goto st196;
	} else if ( (*p) >= 32 )
		goto st196;
	goto tr204;
st196:
	if ( ++p == pe )
		goto _test_eof196;
case 196:
	if ( (*p) == 34 )
		goto st197;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto st196;
	goto tr229;
st197:
	if ( ++p == pe )
		goto _test_eof197;
case 197:
	if ( (*p) == 62 )
		goto st198;
	goto tr229;
st198:
	if ( ++p == pe )
		goto _test_eof198;
case 198:
	if ( (*p) == 10 )
		goto tr232;
	goto tr204;
st199:
	if ( ++p == pe )
		goto _test_eof199;
case 199:
	switch( (*p) ) {
		case 45: goto st181;
		case 46: goto st199;
		case 95: goto st181;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st181;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st181;
	} else
		goto st181;
	goto tr209;
st200:
	if ( ++p == pe )
		goto _test_eof200;
case 200:
	if ( (*p) == 95 )
		goto st200;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st181;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st181;
		} else if ( (*p) >= 65 )
			goto st181;
	} else
		goto st181;
	goto tr209;
st201:
	if ( ++p == pe )
		goto _test_eof201;
case 201:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr39;
		case 82: goto st202;
		case 95: goto st21;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st21;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st21;
	} else
		goto st21;
	goto tr233;
st202:
	if ( ++p == pe )
		goto _test_eof202;
case 202:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr39;
		case 77: goto st203;
		case 95: goto st21;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st21;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st21;
	} else
		goto st21;
	goto tr233;
st203:
	if ( ++p == pe )
		goto _test_eof203;
case 203:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr39;
		case 65: goto st204;
		case 95: goto st21;
	}
	if ( (*p) < 66 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st21;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st21;
	} else
		goto st21;
	goto tr233;
st204:
	if ( ++p == pe )
		goto _test_eof204;
case 204:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr39;
		case 84: goto st205;
		case 95: goto st21;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st21;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st21;
	} else
		goto st21;
	goto tr233;
st205:
	if ( ++p == pe )
		goto _test_eof205;
case 205:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto st206;
		case 95: goto st21;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st21;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st21;
	} else
		goto st21;
	goto tr233;
st206:
	if ( ++p == pe )
		goto _test_eof206;
case 206:
	if ( (*p) == 60 )
		goto st207;
	goto tr239;
st207:
	if ( ++p == pe )
		goto _test_eof207;
case 207:
	if ( (*p) == 73 )
		goto st208;
	goto tr239;
st208:
	if ( ++p == pe )
		goto _test_eof208;
case 208:
	if ( (*p) == 68 )
		goto st209;
	goto tr239;
st209:
	if ( ++p == pe )
		goto _test_eof209;
case 209:
	if ( (*p) == 61 )
		goto st210;
	goto tr239;
st210:
	if ( ++p == pe )
		goto _test_eof210;
case 210:
	switch( (*p) ) {
		case 45: goto st211;
		case 46: goto st268;
		case 95: goto st269;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st212;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st212;
	} else
		goto st212;
	goto tr244;
st211:
	if ( ++p == pe )
		goto _test_eof211;
case 211:
	switch( (*p) ) {
		case 45: goto st211;
		case 46: goto st212;
		case 95: goto st212;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st212;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st212;
	} else
		goto st212;
	goto tr244;
st212:
	if ( ++p == pe )
		goto _test_eof212;
case 212:
	switch( (*p) ) {
		case 44: goto st213;
		case 95: goto st212;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st212;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st212;
		} else if ( (*p) >= 65 )
			goto st212;
	} else
		goto st212;
	goto tr244;
st213:
	if ( ++p == pe )
		goto _test_eof213;
case 213:
	if ( (*p) == 78 )
		goto st214;
	goto tr239;
st214:
	if ( ++p == pe )
		goto _test_eof214;
case 214:
	if ( (*p) == 117 )
		goto st215;
	goto tr239;
st215:
	if ( ++p == pe )
		goto _test_eof215;
case 215:
	if ( (*p) == 109 )
		goto st216;
	goto tr239;
st216:
	if ( ++p == pe )
		goto _test_eof216;
case 216:
	if ( (*p) == 98 )
		goto st217;
	goto tr239;
st217:
	if ( ++p == pe )
		goto _test_eof217;
case 217:
	if ( (*p) == 101 )
		goto st218;
	goto tr239;
st218:
	if ( ++p == pe )
		goto _test_eof218;
case 218:
	if ( (*p) == 114 )
		goto st219;
	goto tr239;
st219:
	if ( ++p == pe )
		goto _test_eof219;
case 219:
	if ( (*p) == 61 )
		goto st220;
	goto tr239;
st220:
	if ( ++p == pe )
		goto _test_eof220;
case 220:
	switch( (*p) ) {
		case 46: goto st221;
		case 65: goto st221;
		case 71: goto st221;
		case 82: goto st221;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st267;
	goto tr257;
st221:
	if ( ++p == pe )
		goto _test_eof221;
case 221:
	if ( (*p) == 44 )
		goto st222;
	goto tr257;
st222:
	if ( ++p == pe )
		goto _test_eof222;
case 222:
	if ( (*p) == 84 )
		goto st223;
	goto tr239;
st223:
	if ( ++p == pe )
		goto _test_eof223;
case 223:
	if ( (*p) == 121 )
		goto st224;
	goto tr239;
st224:
	if ( ++p == pe )
		goto _test_eof224;
case 224:
	if ( (*p) == 112 )
		goto st225;
	goto tr239;
st225:
	if ( ++p == pe )
		goto _test_eof225;
case 225:
	if ( (*p) == 101 )
		goto st226;
	goto tr239;
st226:
	if ( ++p == pe )
		goto _test_eof226;
case 226:
	if ( (*p) == 61 )
		goto st227;
	goto tr239;
st227:
	if ( ++p == pe )
		goto _test_eof227;
case 227:
	switch( (*p) ) {
		case 67: goto st228;
		case 70: goto st254;
		case 73: goto st258;
		case 83: goto st262;
	}
	goto tr266;
st228:
	if ( ++p == pe )
		goto _test_eof228;
case 228:
	if ( (*p) == 104 )
		goto st229;
	goto tr266;
st229:
	if ( ++p == pe )
		goto _test_eof229;
case 229:
	if ( (*p) == 97 )
		goto st230;
	goto tr266;
st230:
	if ( ++p == pe )
		goto _test_eof230;
case 230:
	if ( (*p) == 114 )
		goto st231;
	goto tr266;
st231:
	if ( ++p == pe )
		goto _test_eof231;
case 231:
	if ( (*p) == 97 )
		goto st232;
	goto tr266;
st232:
	if ( ++p == pe )
		goto _test_eof232;
case 232:
	if ( (*p) == 99 )
		goto st233;
	goto tr266;
st233:
	if ( ++p == pe )
		goto _test_eof233;
case 233:
	if ( (*p) == 116 )
		goto st234;
	goto tr266;
st234:
	if ( ++p == pe )
		goto _test_eof234;
case 234:
	if ( (*p) == 101 )
		goto st235;
	goto tr266;
st235:
	if ( ++p == pe )
		goto _test_eof235;
case 235:
	if ( (*p) == 114 )
		goto st236;
	goto tr266;
st236:
	if ( ++p == pe )
		goto _test_eof236;
case 236:
	if ( (*p) == 44 )
		goto st237;
	goto tr266;
st237:
	if ( ++p == pe )
		goto _test_eof237;
case 237:
	if ( (*p) == 68 )
		goto st238;
	goto tr239;
st238:
	if ( ++p == pe )
		goto _test_eof238;
case 238:
	if ( (*p) == 101 )
		goto st239;
	goto tr239;
st239:
	if ( ++p == pe )
		goto _test_eof239;
case 239:
	if ( (*p) == 115 )
		goto st240;
	goto tr239;
st240:
	if ( ++p == pe )
		goto _test_eof240;
case 240:
	if ( (*p) == 99 )
		goto st241;
	goto tr239;
st241:
	if ( ++p == pe )
		goto _test_eof241;
case 241:
	if ( (*p) == 114 )
		goto st242;
	goto tr239;
st242:
	if ( ++p == pe )
		goto _test_eof242;
case 242:
	if ( (*p) == 105 )
		goto st243;
	goto tr239;
st243:
	if ( ++p == pe )
		goto _test_eof243;
case 243:
	if ( (*p) == 112 )
		goto st244;
	goto tr239;
st244:
	if ( ++p == pe )
		goto _test_eof244;
case 244:
	if ( (*p) == 116 )
		goto st245;
	goto tr239;
st245:
	if ( ++p == pe )
		goto _test_eof245;
case 245:
	if ( (*p) == 105 )
		goto st246;
	goto tr239;
st246:
	if ( ++p == pe )
		goto _test_eof246;
case 246:
	if ( (*p) == 111 )
		goto st247;
	goto tr239;
st247:
	if ( ++p == pe )
		goto _test_eof247;
case 247:
	if ( (*p) == 110 )
		goto st248;
	goto tr239;
st248:
	if ( ++p == pe )
		goto _test_eof248;
case 248:
	if ( (*p) == 61 )
		goto st249;
	goto tr239;
st249:
	if ( ++p == pe )
		goto _test_eof249;
case 249:
	if ( (*p) == 34 )
		goto st250;
	goto tr239;
st250:
	if ( ++p == pe )
		goto _test_eof250;
case 250:
	if ( (*p) > 33 ) {
		if ( 35 <= (*p) && (*p) <= 126 )
			goto st251;
	} else if ( (*p) >= 32 )
		goto st251;
	goto tr239;
st251:
	if ( ++p == pe )
		goto _test_eof251;
case 251:
	if ( (*p) == 34 )
		goto st252;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto st251;
	goto tr294;
st252:
	if ( ++p == pe )
		goto _test_eof252;
case 252:
	if ( (*p) == 62 )
		goto st253;
	goto tr294;
st253:
	if ( ++p == pe )
		goto _test_eof253;
case 253:
	if ( (*p) == 10 )
		goto tr297;
	goto tr239;
st254:
	if ( ++p == pe )
		goto _test_eof254;
case 254:
	if ( (*p) == 108 )
		goto st255;
	goto tr266;
st255:
	if ( ++p == pe )
		goto _test_eof255;
case 255:
	if ( (*p) == 111 )
		goto st256;
	goto tr266;
st256:
	if ( ++p == pe )
		goto _test_eof256;
case 256:
	if ( (*p) == 97 )
		goto st257;
	goto tr266;
st257:
	if ( ++p == pe )
		goto _test_eof257;
case 257:
	if ( (*p) == 116 )
		goto st236;
	goto tr266;
st258:
	if ( ++p == pe )
		goto _test_eof258;
case 258:
	if ( (*p) == 110 )
		goto st259;
	goto tr266;
st259:
	if ( ++p == pe )
		goto _test_eof259;
case 259:
	if ( (*p) == 116 )
		goto st260;
	goto tr266;
st260:
	if ( ++p == pe )
		goto _test_eof260;
case 260:
	if ( (*p) == 101 )
		goto st261;
	goto tr266;
st261:
	if ( ++p == pe )
		goto _test_eof261;
case 261:
	if ( (*p) == 103 )
		goto st234;
	goto tr266;
st262:
	if ( ++p == pe )
		goto _test_eof262;
case 262:
	if ( (*p) == 116 )
		goto st263;
	goto tr266;
st263:
	if ( ++p == pe )
		goto _test_eof263;
case 263:
	if ( (*p) == 114 )
		goto st264;
	goto tr266;
st264:
	if ( ++p == pe )
		goto _test_eof264;
case 264:
	if ( (*p) == 105 )
		goto st265;
	goto tr266;
st265:
	if ( ++p == pe )
		goto _test_eof265;
case 265:
	if ( (*p) == 110 )
		goto st266;
	goto tr266;
st266:
	if ( ++p == pe )
		goto _test_eof266;
case 266:
	if ( (*p) == 103 )
		goto st236;
	goto tr266;
st267:
	if ( ++p == pe )
		goto _test_eof267;
case 267:
	if ( (*p) == 44 )
		goto st222;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st267;
	goto tr257;
st268:
	if ( ++p == pe )
		goto _test_eof268;
case 268:
	switch( (*p) ) {
		case 45: goto st212;
		case 46: goto st268;
		case 95: goto st212;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st212;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st212;
	} else
		goto st212;
	goto tr244;
st269:
	if ( ++p == pe )
		goto _test_eof269;
case 269:
	if ( (*p) == 95 )
		goto st269;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st212;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st212;
		} else if ( (*p) >= 65 )
			goto st212;
	} else
		goto st212;
	goto tr244;
tr28:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st270;
st270:
	if ( ++p == pe )
		goto _test_eof270;
case 270:
#line 6045 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr39;
		case 78: goto st271;
		case 95: goto st21;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st21;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st21;
	} else
		goto st21;
	goto tr308;
st271:
	if ( ++p == pe )
		goto _test_eof271;
case 271:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr39;
		case 70: goto st272;
		case 95: goto st21;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st21;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st21;
	} else
		goto st21;
	goto tr308;
st272:
	if ( ++p == pe )
		goto _test_eof272;
case 272:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr39;
		case 79: goto st273;
		case 95: goto st21;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st21;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st21;
	} else
		goto st21;
	goto tr308;
st273:
	if ( ++p == pe )
		goto _test_eof273;
case 273:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto st274;
		case 95: goto st21;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st21;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st21;
	} else
		goto st21;
	goto tr308;
st274:
	if ( ++p == pe )
		goto _test_eof274;
case 274:
	if ( (*p) == 60 )
		goto st275;
	goto tr313;
st275:
	if ( ++p == pe )
		goto _test_eof275;
case 275:
	if ( (*p) == 73 )
		goto st276;
	goto tr313;
st276:
	if ( ++p == pe )
		goto _test_eof276;
case 276:
	if ( (*p) == 68 )
		goto st277;
	goto tr313;
st277:
	if ( ++p == pe )
		goto _test_eof277;
case 277:
	if ( (*p) == 61 )
		goto st278;
	goto tr313;
st278:
	if ( ++p == pe )
		goto _test_eof278;
case 278:
	switch( (*p) ) {
		case 45: goto st279;
		case 46: goto st368;
		case 95: goto st369;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st280;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st280;
	} else
		goto st280;
	goto tr318;
st279:
	if ( ++p == pe )
		goto _test_eof279;
case 279:
	switch( (*p) ) {
		case 45: goto st279;
		case 46: goto st280;
		case 95: goto st280;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st280;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st280;
	} else
		goto st280;
	goto tr318;
st280:
	if ( ++p == pe )
		goto _test_eof280;
case 280:
	switch( (*p) ) {
		case 44: goto st281;
		case 95: goto st280;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st280;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st280;
		} else if ( (*p) >= 65 )
			goto st280;
	} else
		goto st280;
	goto tr318;
st281:
	if ( ++p == pe )
		goto _test_eof281;
case 281:
	if ( (*p) == 78 )
		goto st282;
	goto tr313;
st282:
	if ( ++p == pe )
		goto _test_eof282;
case 282:
	if ( (*p) == 117 )
		goto st283;
	goto tr313;
st283:
	if ( ++p == pe )
		goto _test_eof283;
case 283:
	if ( (*p) == 109 )
		goto st284;
	goto tr313;
st284:
	if ( ++p == pe )
		goto _test_eof284;
case 284:
	if ( (*p) == 98 )
		goto st285;
	goto tr313;
st285:
	if ( ++p == pe )
		goto _test_eof285;
case 285:
	if ( (*p) == 101 )
		goto st286;
	goto tr313;
st286:
	if ( ++p == pe )
		goto _test_eof286;
case 286:
	if ( (*p) == 114 )
		goto st287;
	goto tr313;
st287:
	if ( ++p == pe )
		goto _test_eof287;
case 287:
	if ( (*p) == 61 )
		goto st288;
	goto tr313;
st288:
	if ( ++p == pe )
		goto _test_eof288;
case 288:
	switch( (*p) ) {
		case 46: goto st289;
		case 65: goto st289;
		case 71: goto st289;
		case 82: goto st289;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st367;
	goto tr331;
st289:
	if ( ++p == pe )
		goto _test_eof289;
case 289:
	if ( (*p) == 44 )
		goto st290;
	goto tr331;
st290:
	if ( ++p == pe )
		goto _test_eof290;
case 290:
	if ( (*p) == 84 )
		goto st291;
	goto tr313;
st291:
	if ( ++p == pe )
		goto _test_eof291;
case 291:
	if ( (*p) == 121 )
		goto st292;
	goto tr313;
st292:
	if ( ++p == pe )
		goto _test_eof292;
case 292:
	if ( (*p) == 112 )
		goto st293;
	goto tr313;
st293:
	if ( ++p == pe )
		goto _test_eof293;
case 293:
	if ( (*p) == 101 )
		goto st294;
	goto tr313;
st294:
	if ( ++p == pe )
		goto _test_eof294;
case 294:
	if ( (*p) == 61 )
		goto st295;
	goto tr313;
st295:
	if ( ++p == pe )
		goto _test_eof295;
case 295:
	switch( (*p) ) {
		case 67: goto st296;
		case 70: goto st354;
		case 73: goto st359;
		case 83: goto st363;
	}
	goto tr340;
st296:
	if ( ++p == pe )
		goto _test_eof296;
case 296:
	if ( (*p) == 104 )
		goto st297;
	goto tr340;
st297:
	if ( ++p == pe )
		goto _test_eof297;
case 297:
	if ( (*p) == 97 )
		goto st298;
	goto tr340;
st298:
	if ( ++p == pe )
		goto _test_eof298;
case 298:
	if ( (*p) == 114 )
		goto st299;
	goto tr340;
st299:
	if ( ++p == pe )
		goto _test_eof299;
case 299:
	if ( (*p) == 97 )
		goto st300;
	goto tr340;
st300:
	if ( ++p == pe )
		goto _test_eof300;
case 300:
	if ( (*p) == 99 )
		goto st301;
	goto tr340;
st301:
	if ( ++p == pe )
		goto _test_eof301;
case 301:
	if ( (*p) == 116 )
		goto st302;
	goto tr340;
st302:
	if ( ++p == pe )
		goto _test_eof302;
case 302:
	if ( (*p) == 101 )
		goto st303;
	goto tr340;
st303:
	if ( ++p == pe )
		goto _test_eof303;
case 303:
	if ( (*p) == 114 )
		goto st304;
	goto tr340;
st304:
	if ( ++p == pe )
		goto _test_eof304;
case 304:
	if ( (*p) == 44 )
		goto st305;
	goto tr340;
st305:
	if ( ++p == pe )
		goto _test_eof305;
case 305:
	if ( (*p) == 68 )
		goto st306;
	goto tr313;
st306:
	if ( ++p == pe )
		goto _test_eof306;
case 306:
	if ( (*p) == 101 )
		goto st307;
	goto tr313;
st307:
	if ( ++p == pe )
		goto _test_eof307;
case 307:
	if ( (*p) == 115 )
		goto st308;
	goto tr313;
st308:
	if ( ++p == pe )
		goto _test_eof308;
case 308:
	if ( (*p) == 99 )
		goto st309;
	goto tr313;
st309:
	if ( ++p == pe )
		goto _test_eof309;
case 309:
	if ( (*p) == 114 )
		goto st310;
	goto tr313;
st310:
	if ( ++p == pe )
		goto _test_eof310;
case 310:
	if ( (*p) == 105 )
		goto st311;
	goto tr313;
st311:
	if ( ++p == pe )
		goto _test_eof311;
case 311:
	if ( (*p) == 112 )
		goto st312;
	goto tr313;
st312:
	if ( ++p == pe )
		goto _test_eof312;
case 312:
	if ( (*p) == 116 )
		goto st313;
	goto tr313;
st313:
	if ( ++p == pe )
		goto _test_eof313;
case 313:
	if ( (*p) == 105 )
		goto st314;
	goto tr313;
st314:
	if ( ++p == pe )
		goto _test_eof314;
case 314:
	if ( (*p) == 111 )
		goto st315;
	goto tr313;
st315:
	if ( ++p == pe )
		goto _test_eof315;
case 315:
	if ( (*p) == 110 )
		goto st316;
	goto tr313;
st316:
	if ( ++p == pe )
		goto _test_eof316;
case 316:
	if ( (*p) == 61 )
		goto st317;
	goto tr313;
st317:
	if ( ++p == pe )
		goto _test_eof317;
case 317:
	if ( (*p) == 34 )
		goto st318;
	goto tr313;
st318:
	if ( ++p == pe )
		goto _test_eof318;
case 318:
	if ( (*p) > 33 ) {
		if ( 35 <= (*p) && (*p) <= 126 )
			goto st319;
	} else if ( (*p) >= 32 )
		goto st319;
	goto tr313;
st319:
	if ( ++p == pe )
		goto _test_eof319;
case 319:
	if ( (*p) == 34 )
		goto st320;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto st319;
	goto tr368;
st320:
	if ( ++p == pe )
		goto _test_eof320;
case 320:
	switch( (*p) ) {
		case 44: goto st321;
		case 62: goto st353;
	}
	goto tr368;
st321:
	if ( ++p == pe )
		goto _test_eof321;
case 321:
	switch( (*p) ) {
		case 83: goto st322;
		case 86: goto st346;
	}
	goto tr313;
st322:
	if ( ++p == pe )
		goto _test_eof322;
case 322:
	if ( (*p) == 111 )
		goto st323;
	goto tr313;
st323:
	if ( ++p == pe )
		goto _test_eof323;
case 323:
	if ( (*p) == 117 )
		goto st324;
	goto tr313;
st324:
	if ( ++p == pe )
		goto _test_eof324;
case 324:
	if ( (*p) == 114 )
		goto st325;
	goto tr313;
st325:
	if ( ++p == pe )
		goto _test_eof325;
case 325:
	if ( (*p) == 99 )
		goto st326;
	goto tr313;
st326:
	if ( ++p == pe )
		goto _test_eof326;
case 326:
	if ( (*p) == 101 )
		goto st327;
	goto tr313;
st327:
	if ( ++p == pe )
		goto _test_eof327;
case 327:
	if ( (*p) == 61 )
		goto st328;
	goto tr313;
st328:
	if ( ++p == pe )
		goto _test_eof328;
case 328:
	if ( (*p) == 34 )
		goto st329;
	goto tr313;
st329:
	if ( ++p == pe )
		goto _test_eof329;
case 329:
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st330;
	} else if ( (*p) >= 32 )
		goto st330;
	goto tr313;
st330:
	if ( ++p == pe )
		goto _test_eof330;
case 330:
	if ( (*p) == 34 )
		goto st331;
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st330;
	} else if ( (*p) >= 32 )
		goto st330;
	goto tr313;
st331:
	if ( ++p == pe )
		goto _test_eof331;
case 331:
	switch( (*p) ) {
		case 34: goto st331;
		case 44: goto st332;
		case 62: goto st345;
	}
	if ( (*p) > 60 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto st330;
	} else if ( (*p) >= 32 )
		goto st330;
	goto tr313;
st332:
	if ( ++p == pe )
		goto _test_eof332;
case 332:
	switch( (*p) ) {
		case 34: goto st331;
		case 86: goto st333;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st330;
	} else if ( (*p) >= 32 )
		goto st330;
	goto tr313;
st333:
	if ( ++p == pe )
		goto _test_eof333;
case 333:
	switch( (*p) ) {
		case 34: goto st331;
		case 101: goto st334;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st330;
	} else if ( (*p) >= 32 )
		goto st330;
	goto tr313;
st334:
	if ( ++p == pe )
		goto _test_eof334;
case 334:
	switch( (*p) ) {
		case 34: goto st331;
		case 114: goto st335;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st330;
	} else if ( (*p) >= 32 )
		goto st330;
	goto tr313;
st335:
	if ( ++p == pe )
		goto _test_eof335;
case 335:
	switch( (*p) ) {
		case 34: goto st331;
		case 115: goto st336;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st330;
	} else if ( (*p) >= 32 )
		goto st330;
	goto tr313;
st336:
	if ( ++p == pe )
		goto _test_eof336;
case 336:
	switch( (*p) ) {
		case 34: goto st331;
		case 105: goto st337;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st330;
	} else if ( (*p) >= 32 )
		goto st330;
	goto tr313;
st337:
	if ( ++p == pe )
		goto _test_eof337;
case 337:
	switch( (*p) ) {
		case 34: goto st331;
		case 111: goto st338;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st330;
	} else if ( (*p) >= 32 )
		goto st330;
	goto tr313;
st338:
	if ( ++p == pe )
		goto _test_eof338;
case 338:
	switch( (*p) ) {
		case 34: goto st331;
		case 110: goto st339;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st330;
	} else if ( (*p) >= 32 )
		goto st330;
	goto tr313;
st339:
	if ( ++p == pe )
		goto _test_eof339;
case 339:
	switch( (*p) ) {
		case 34: goto st331;
		case 61: goto st340;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto st330;
	goto tr313;
st340:
	if ( ++p == pe )
		goto _test_eof340;
case 340:
	if ( (*p) == 34 )
		goto st341;
	goto tr313;
st341:
	if ( ++p == pe )
		goto _test_eof341;
case 341:
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st342;
	} else if ( (*p) >= 32 )
		goto st342;
	goto tr313;
st342:
	if ( ++p == pe )
		goto _test_eof342;
case 342:
	if ( (*p) == 34 )
		goto st343;
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st342;
	} else if ( (*p) >= 32 )
		goto st342;
	goto tr313;
st343:
	if ( ++p == pe )
		goto _test_eof343;
case 343:
	switch( (*p) ) {
		case 34: goto st343;
		case 62: goto st344;
	}
	if ( (*p) > 60 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto st342;
	} else if ( (*p) >= 32 )
		goto st342;
	goto tr313;
st344:
	if ( ++p == pe )
		goto _test_eof344;
case 344:
	switch( (*p) ) {
		case 10: goto tr397;
		case 34: goto st343;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st342;
	} else if ( (*p) >= 32 )
		goto st342;
	goto tr313;
st345:
	if ( ++p == pe )
		goto _test_eof345;
case 345:
	switch( (*p) ) {
		case 10: goto tr397;
		case 34: goto st331;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st330;
	} else if ( (*p) >= 32 )
		goto st330;
	goto tr313;
st346:
	if ( ++p == pe )
		goto _test_eof346;
case 346:
	if ( (*p) == 101 )
		goto st347;
	goto tr313;
st347:
	if ( ++p == pe )
		goto _test_eof347;
case 347:
	if ( (*p) == 114 )
		goto st348;
	goto tr313;
st348:
	if ( ++p == pe )
		goto _test_eof348;
case 348:
	if ( (*p) == 115 )
		goto st349;
	goto tr313;
st349:
	if ( ++p == pe )
		goto _test_eof349;
case 349:
	if ( (*p) == 105 )
		goto st350;
	goto tr313;
st350:
	if ( ++p == pe )
		goto _test_eof350;
case 350:
	if ( (*p) == 111 )
		goto st351;
	goto tr313;
st351:
	if ( ++p == pe )
		goto _test_eof351;
case 351:
	if ( (*p) == 110 )
		goto st352;
	goto tr313;
st352:
	if ( ++p == pe )
		goto _test_eof352;
case 352:
	if ( (*p) == 61 )
		goto st340;
	goto tr313;
st353:
	if ( ++p == pe )
		goto _test_eof353;
case 353:
	if ( (*p) == 10 )
		goto tr397;
	goto tr313;
st354:
	if ( ++p == pe )
		goto _test_eof354;
case 354:
	if ( (*p) == 108 )
		goto st355;
	goto tr340;
st355:
	if ( ++p == pe )
		goto _test_eof355;
case 355:
	switch( (*p) ) {
		case 97: goto st356;
		case 111: goto st357;
	}
	goto tr340;
st356:
	if ( ++p == pe )
		goto _test_eof356;
case 356:
	if ( (*p) == 103 )
		goto st304;
	goto tr340;
st357:
	if ( ++p == pe )
		goto _test_eof357;
case 357:
	if ( (*p) == 97 )
		goto st358;
	goto tr340;
st358:
	if ( ++p == pe )
		goto _test_eof358;
case 358:
	if ( (*p) == 116 )
		goto st304;
	goto tr340;
st359:
	if ( ++p == pe )
		goto _test_eof359;
case 359:
	if ( (*p) == 110 )
		goto st360;
	goto tr340;
st360:
	if ( ++p == pe )
		goto _test_eof360;
case 360:
	if ( (*p) == 116 )
		goto st361;
	goto tr340;
st361:
	if ( ++p == pe )
		goto _test_eof361;
case 361:
	if ( (*p) == 101 )
		goto st362;
	goto tr340;
st362:
	if ( ++p == pe )
		goto _test_eof362;
case 362:
	if ( (*p) == 103 )
		goto st302;
	goto tr340;
st363:
	if ( ++p == pe )
		goto _test_eof363;
case 363:
	if ( (*p) == 116 )
		goto st364;
	goto tr340;
st364:
	if ( ++p == pe )
		goto _test_eof364;
case 364:
	if ( (*p) == 114 )
		goto st365;
	goto tr340;
st365:
	if ( ++p == pe )
		goto _test_eof365;
case 365:
	if ( (*p) == 105 )
		goto st366;
	goto tr340;
st366:
	if ( ++p == pe )
		goto _test_eof366;
case 366:
	if ( (*p) == 110 )
		goto st356;
	goto tr340;
st367:
	if ( ++p == pe )
		goto _test_eof367;
case 367:
	if ( (*p) == 44 )
		goto st290;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st367;
	goto tr331;
st368:
	if ( ++p == pe )
		goto _test_eof368;
case 368:
	switch( (*p) ) {
		case 45: goto st280;
		case 46: goto st368;
		case 95: goto st280;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st280;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st280;
	} else
		goto st280;
	goto tr318;
st369:
	if ( ++p == pe )
		goto _test_eof369;
case 369:
	if ( (*p) == 95 )
		goto st369;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st280;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st280;
		} else if ( (*p) >= 65 )
			goto st280;
	} else
		goto st280;
	goto tr318;
tr29:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st370;
st370:
	if ( ++p == pe )
		goto _test_eof370;
case 370:
#line 7025 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr39;
		case 69: goto st371;
		case 95: goto st21;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st21;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st21;
	} else
		goto st21;
	goto tr37;
st371:
	if ( ++p == pe )
		goto _test_eof371;
case 371:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr39;
		case 68: goto st372;
		case 95: goto st21;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st21;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st21;
	} else
		goto st21;
	goto tr37;
st372:
	if ( ++p == pe )
		goto _test_eof372;
case 372:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr39;
		case 73: goto st373;
		case 95: goto st21;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st21;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st21;
	} else
		goto st21;
	goto tr37;
st373:
	if ( ++p == pe )
		goto _test_eof373;
case 373:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr39;
		case 71: goto st374;
		case 95: goto st21;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st21;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st21;
	} else
		goto st21;
	goto tr37;
st374:
	if ( ++p == pe )
		goto _test_eof374;
case 374:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr39;
		case 82: goto st375;
		case 95: goto st21;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st21;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st21;
	} else
		goto st21;
	goto tr37;
st375:
	if ( ++p == pe )
		goto _test_eof375;
case 375:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr39;
		case 69: goto st376;
		case 95: goto st21;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st21;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st21;
	} else
		goto st21;
	goto tr37;
st376:
	if ( ++p == pe )
		goto _test_eof376;
case 376:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr39;
		case 69: goto st377;
		case 95: goto st21;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st21;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st21;
	} else
		goto st21;
	goto tr37;
st377:
	if ( ++p == pe )
		goto _test_eof377;
case 377:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto st378;
		case 95: goto st21;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st21;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st21;
	} else
		goto st21;
	goto tr37;
st378:
	if ( ++p == pe )
		goto _test_eof378;
case 378:
	if ( (*p) == 60 )
		goto st379;
	goto tr34;
st379:
	if ( ++p == pe )
		goto _test_eof379;
case 379:
	switch( (*p) ) {
		case 45: goto st380;
		case 46: goto st392;
		case 95: goto st393;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st381;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st381;
	} else
		goto st381;
	goto tr34;
st380:
	if ( ++p == pe )
		goto _test_eof380;
case 380:
	switch( (*p) ) {
		case 45: goto st380;
		case 46: goto st381;
		case 95: goto st381;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st381;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st381;
	} else
		goto st381;
	goto tr34;
st381:
	if ( ++p == pe )
		goto _test_eof381;
case 381:
	switch( (*p) ) {
		case 61: goto st382;
		case 95: goto st381;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st381;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st381;
		} else if ( (*p) >= 65 )
			goto st381;
	} else
		goto st381;
	goto tr34;
st382:
	if ( ++p == pe )
		goto _test_eof382;
case 382:
	switch( (*p) ) {
		case 45: goto st383;
		case 46: goto st390;
		case 95: goto st391;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st384;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st384;
	} else
		goto st384;
	goto tr34;
st383:
	if ( ++p == pe )
		goto _test_eof383;
case 383:
	switch( (*p) ) {
		case 45: goto st383;
		case 46: goto st384;
		case 95: goto st384;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st384;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st384;
	} else
		goto st384;
	goto tr34;
st384:
	if ( ++p == pe )
		goto _test_eof384;
case 384:
	switch( (*p) ) {
		case 45: goto st385;
		case 46: goto st388;
		case 62: goto st387;
		case 95: goto st389;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st386;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st386;
	} else
		goto st386;
	goto tr34;
st385:
	if ( ++p == pe )
		goto _test_eof385;
case 385:
	switch( (*p) ) {
		case 45: goto st385;
		case 46: goto st386;
		case 62: goto st387;
		case 95: goto st386;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st386;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st386;
	} else
		goto st386;
	goto tr34;
st386:
	if ( ++p == pe )
		goto _test_eof386;
case 386:
	switch( (*p) ) {
		case 61: goto st382;
		case 62: goto st387;
		case 95: goto st386;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st386;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st386;
		} else if ( (*p) >= 65 )
			goto st386;
	} else
		goto st386;
	goto tr34;
st387:
	if ( ++p == pe )
		goto _test_eof387;
case 387:
	if ( (*p) == 10 )
		goto tr437;
	goto tr34;
st388:
	if ( ++p == pe )
		goto _test_eof388;
case 388:
	switch( (*p) ) {
		case 45: goto st386;
		case 46: goto st388;
		case 62: goto st387;
		case 95: goto st386;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st386;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st386;
	} else
		goto st386;
	goto tr34;
st389:
	if ( ++p == pe )
		goto _test_eof389;
case 389:
	switch( (*p) ) {
		case 62: goto st387;
		case 95: goto st389;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st386;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st386;
		} else if ( (*p) >= 65 )
			goto st386;
	} else
		goto st386;
	goto tr34;
st390:
	if ( ++p == pe )
		goto _test_eof390;
case 390:
	switch( (*p) ) {
		case 45: goto st384;
		case 46: goto st390;
		case 95: goto st384;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st384;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st384;
	} else
		goto st384;
	goto tr34;
st391:
	if ( ++p == pe )
		goto _test_eof391;
case 391:
	if ( (*p) == 95 )
		goto st391;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st384;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st384;
		} else if ( (*p) >= 65 )
			goto st384;
	} else
		goto st384;
	goto tr34;
st392:
	if ( ++p == pe )
		goto _test_eof392;
case 392:
	switch( (*p) ) {
		case 45: goto st381;
		case 46: goto st392;
		case 95: goto st381;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st381;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st381;
	} else
		goto st381;
	goto tr34;
st393:
	if ( ++p == pe )
		goto _test_eof393;
case 393:
	if ( (*p) == 95 )
		goto st393;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st381;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st381;
		} else if ( (*p) >= 65 )
			goto st381;
	} else
		goto st381;
	goto tr34;
tr30:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st394;
st394:
	if ( ++p == pe )
		goto _test_eof394;
case 394:
#line 7555 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr39;
		case 65: goto st395;
		case 95: goto st21;
	}
	if ( (*p) < 66 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st21;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st21;
	} else
		goto st21;
	goto tr37;
st395:
	if ( ++p == pe )
		goto _test_eof395;
case 395:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr39;
		case 77: goto st396;
		case 95: goto st21;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st21;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st21;
	} else
		goto st21;
	goto tr37;
st396:
	if ( ++p == pe )
		goto _test_eof396;
case 396:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr39;
		case 80: goto st397;
		case 95: goto st21;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st21;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st21;
	} else
		goto st21;
	goto tr37;
st397:
	if ( ++p == pe )
		goto _test_eof397;
case 397:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr39;
		case 76: goto st398;
		case 95: goto st21;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st21;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st21;
	} else
		goto st21;
	goto tr37;
st398:
	if ( ++p == pe )
		goto _test_eof398;
case 398:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr39;
		case 69: goto st399;
		case 95: goto st21;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st21;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st21;
	} else
		goto st21;
	goto tr37;
st399:
	if ( ++p == pe )
		goto _test_eof399;
case 399:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto st400;
		case 95: goto st21;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st21;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st21;
	} else
		goto st21;
	goto tr37;
st400:
	if ( ++p == pe )
		goto _test_eof400;
case 400:
	if ( (*p) == 60 )
		goto st401;
	goto tr34;
st401:
	if ( ++p == pe )
		goto _test_eof401;
case 401:
	if ( (*p) == 73 )
		goto st402;
	goto tr34;
st402:
	if ( ++p == pe )
		goto _test_eof402;
case 402:
	if ( (*p) == 68 )
		goto st403;
	goto tr34;
st403:
	if ( ++p == pe )
		goto _test_eof403;
case 403:
	if ( (*p) == 61 )
		goto st404;
	goto tr34;
st404:
	if ( ++p == pe )
		goto _test_eof404;
case 404:
	switch( (*p) ) {
		case 45: goto st405;
		case 46: goto st450;
		case 95: goto st451;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st406;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st406;
	} else
		goto st406;
	goto tr448;
st405:
	if ( ++p == pe )
		goto _test_eof405;
case 405:
	switch( (*p) ) {
		case 45: goto st405;
		case 46: goto st406;
		case 95: goto st406;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st406;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st406;
	} else
		goto st406;
	goto tr448;
st406:
	if ( ++p == pe )
		goto _test_eof406;
case 406:
	switch( (*p) ) {
		case 44: goto st407;
		case 95: goto st406;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st406;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st406;
		} else if ( (*p) >= 65 )
			goto st406;
	} else
		goto st406;
	goto tr448;
st407:
	if ( ++p == pe )
		goto _test_eof407;
case 407:
	if ( (*p) == 71 )
		goto st408;
	goto tr34;
st408:
	if ( ++p == pe )
		goto _test_eof408;
case 408:
	if ( (*p) == 101 )
		goto st409;
	goto tr34;
st409:
	if ( ++p == pe )
		goto _test_eof409;
case 409:
	if ( (*p) == 110 )
		goto st410;
	goto tr34;
st410:
	if ( ++p == pe )
		goto _test_eof410;
case 410:
	if ( (*p) == 111 )
		goto st411;
	goto tr34;
st411:
	if ( ++p == pe )
		goto _test_eof411;
case 411:
	if ( (*p) == 109 )
		goto st412;
	goto tr34;
st412:
	if ( ++p == pe )
		goto _test_eof412;
case 412:
	if ( (*p) == 101 )
		goto st413;
	goto tr34;
st413:
	if ( ++p == pe )
		goto _test_eof413;
case 413:
	if ( (*p) == 115 )
		goto st414;
	goto tr34;
st414:
	if ( ++p == pe )
		goto _test_eof414;
case 414:
	if ( (*p) == 61 )
		goto st415;
	goto tr34;
st415:
	if ( ++p == pe )
		goto _test_eof415;
case 415:
	switch( (*p) ) {
		case 45: goto st416;
		case 46: goto st419;
		case 95: goto st449;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st417;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st417;
	} else
		goto st417;
	goto tr34;
st416:
	if ( ++p == pe )
		goto _test_eof416;
case 416:
	switch( (*p) ) {
		case 45: goto st416;
		case 46: goto st417;
		case 95: goto st417;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st417;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st417;
	} else
		goto st417;
	goto tr34;
st417:
	if ( ++p == pe )
		goto _test_eof417;
case 417:
	switch( (*p) ) {
		case 44: goto st418;
		case 95: goto st417;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st417;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st417;
		} else if ( (*p) >= 65 )
			goto st417;
	} else
		goto st417;
	goto tr34;
st418:
	if ( ++p == pe )
		goto _test_eof418;
case 418:
	switch( (*p) ) {
		case 45: goto st416;
		case 46: goto st419;
		case 77: goto st420;
		case 95: goto st449;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st417;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st417;
	} else
		goto st417;
	goto tr34;
st419:
	if ( ++p == pe )
		goto _test_eof419;
case 419:
	switch( (*p) ) {
		case 45: goto st417;
		case 46: goto st419;
		case 95: goto st417;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st417;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st417;
	} else
		goto st417;
	goto tr34;
st420:
	if ( ++p == pe )
		goto _test_eof420;
case 420:
	switch( (*p) ) {
		case 44: goto st418;
		case 95: goto st417;
		case 105: goto st421;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st417;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st417;
		} else if ( (*p) >= 65 )
			goto st417;
	} else
		goto st417;
	goto tr34;
st421:
	if ( ++p == pe )
		goto _test_eof421;
case 421:
	switch( (*p) ) {
		case 44: goto st418;
		case 95: goto st417;
		case 120: goto st422;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st417;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st417;
		} else if ( (*p) >= 65 )
			goto st417;
	} else
		goto st417;
	goto tr34;
st422:
	if ( ++p == pe )
		goto _test_eof422;
case 422:
	switch( (*p) ) {
		case 44: goto st418;
		case 95: goto st417;
		case 116: goto st423;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st417;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st417;
		} else if ( (*p) >= 65 )
			goto st417;
	} else
		goto st417;
	goto tr34;
st423:
	if ( ++p == pe )
		goto _test_eof423;
case 423:
	switch( (*p) ) {
		case 44: goto st418;
		case 95: goto st417;
		case 117: goto st424;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st417;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st417;
		} else if ( (*p) >= 65 )
			goto st417;
	} else
		goto st417;
	goto tr34;
st424:
	if ( ++p == pe )
		goto _test_eof424;
case 424:
	switch( (*p) ) {
		case 44: goto st418;
		case 95: goto st417;
		case 114: goto st425;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st417;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st417;
		} else if ( (*p) >= 65 )
			goto st417;
	} else
		goto st417;
	goto tr34;
st425:
	if ( ++p == pe )
		goto _test_eof425;
case 425:
	switch( (*p) ) {
		case 44: goto st418;
		case 95: goto st417;
		case 101: goto st426;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st417;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st417;
		} else if ( (*p) >= 65 )
			goto st417;
	} else
		goto st417;
	goto tr34;
st426:
	if ( ++p == pe )
		goto _test_eof426;
case 426:
	switch( (*p) ) {
		case 44: goto st418;
		case 61: goto st427;
		case 95: goto st417;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st417;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st417;
		} else if ( (*p) >= 65 )
			goto st417;
	} else
		goto st417;
	goto tr34;
st427:
	if ( ++p == pe )
		goto _test_eof427;
case 427:
	switch( (*p) ) {
		case 45: goto st428;
		case 46: goto st431;
		case 95: goto st448;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st429;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st429;
	} else
		goto st429;
	goto tr34;
st428:
	if ( ++p == pe )
		goto _test_eof428;
case 428:
	switch( (*p) ) {
		case 45: goto st428;
		case 46: goto st429;
		case 95: goto st429;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st429;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st429;
	} else
		goto st429;
	goto tr34;
st429:
	if ( ++p == pe )
		goto _test_eof429;
case 429:
	switch( (*p) ) {
		case 44: goto st430;
		case 95: goto st429;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st429;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st429;
		} else if ( (*p) >= 65 )
			goto st429;
	} else
		goto st429;
	goto tr34;
st430:
	if ( ++p == pe )
		goto _test_eof430;
case 430:
	switch( (*p) ) {
		case 45: goto st428;
		case 46: goto st431;
		case 68: goto st432;
		case 95: goto st448;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st429;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st429;
	} else
		goto st429;
	goto tr34;
st431:
	if ( ++p == pe )
		goto _test_eof431;
case 431:
	switch( (*p) ) {
		case 45: goto st429;
		case 46: goto st431;
		case 95: goto st429;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st429;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st429;
	} else
		goto st429;
	goto tr34;
st432:
	if ( ++p == pe )
		goto _test_eof432;
case 432:
	switch( (*p) ) {
		case 44: goto st430;
		case 95: goto st429;
		case 101: goto st433;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st429;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st429;
		} else if ( (*p) >= 65 )
			goto st429;
	} else
		goto st429;
	goto tr34;
st433:
	if ( ++p == pe )
		goto _test_eof433;
case 433:
	switch( (*p) ) {
		case 44: goto st430;
		case 95: goto st429;
		case 115: goto st434;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st429;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st429;
		} else if ( (*p) >= 65 )
			goto st429;
	} else
		goto st429;
	goto tr34;
st434:
	if ( ++p == pe )
		goto _test_eof434;
case 434:
	switch( (*p) ) {
		case 44: goto st430;
		case 95: goto st429;
		case 99: goto st435;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st429;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st429;
		} else if ( (*p) >= 65 )
			goto st429;
	} else
		goto st429;
	goto tr34;
st435:
	if ( ++p == pe )
		goto _test_eof435;
case 435:
	switch( (*p) ) {
		case 44: goto st430;
		case 95: goto st429;
		case 114: goto st436;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st429;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st429;
		} else if ( (*p) >= 65 )
			goto st429;
	} else
		goto st429;
	goto tr34;
st436:
	if ( ++p == pe )
		goto _test_eof436;
case 436:
	switch( (*p) ) {
		case 44: goto st430;
		case 95: goto st429;
		case 105: goto st437;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st429;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st429;
		} else if ( (*p) >= 65 )
			goto st429;
	} else
		goto st429;
	goto tr34;
st437:
	if ( ++p == pe )
		goto _test_eof437;
case 437:
	switch( (*p) ) {
		case 44: goto st430;
		case 95: goto st429;
		case 112: goto st438;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st429;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st429;
		} else if ( (*p) >= 65 )
			goto st429;
	} else
		goto st429;
	goto tr34;
st438:
	if ( ++p == pe )
		goto _test_eof438;
case 438:
	switch( (*p) ) {
		case 44: goto st430;
		case 95: goto st429;
		case 116: goto st439;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st429;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st429;
		} else if ( (*p) >= 65 )
			goto st429;
	} else
		goto st429;
	goto tr34;
st439:
	if ( ++p == pe )
		goto _test_eof439;
case 439:
	switch( (*p) ) {
		case 44: goto st430;
		case 95: goto st429;
		case 105: goto st440;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st429;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st429;
		} else if ( (*p) >= 65 )
			goto st429;
	} else
		goto st429;
	goto tr34;
st440:
	if ( ++p == pe )
		goto _test_eof440;
case 440:
	switch( (*p) ) {
		case 44: goto st430;
		case 95: goto st429;
		case 111: goto st441;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st429;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st429;
		} else if ( (*p) >= 65 )
			goto st429;
	} else
		goto st429;
	goto tr34;
st441:
	if ( ++p == pe )
		goto _test_eof441;
case 441:
	switch( (*p) ) {
		case 44: goto st430;
		case 95: goto st429;
		case 110: goto st442;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st429;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st429;
		} else if ( (*p) >= 65 )
			goto st429;
	} else
		goto st429;
	goto tr34;
st442:
	if ( ++p == pe )
		goto _test_eof442;
case 442:
	switch( (*p) ) {
		case 44: goto st430;
		case 95: goto st429;
		case 115: goto st443;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st429;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st429;
		} else if ( (*p) >= 65 )
			goto st429;
	} else
		goto st429;
	goto tr34;
st443:
	if ( ++p == pe )
		goto _test_eof443;
case 443:
	switch( (*p) ) {
		case 44: goto st430;
		case 61: goto st444;
		case 95: goto st429;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st429;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st429;
		} else if ( (*p) >= 65 )
			goto st429;
	} else
		goto st429;
	goto tr34;
st444:
	if ( ++p == pe )
		goto _test_eof444;
case 444:
	if ( (*p) == 34 )
		goto st445;
	goto tr34;
st445:
	if ( ++p == pe )
		goto _test_eof445;
case 445:
	if ( (*p) > 33 ) {
		if ( 35 <= (*p) && (*p) <= 126 )
			goto st446;
	} else if ( (*p) >= 32 )
		goto st446;
	goto tr34;
st446:
	if ( ++p == pe )
		goto _test_eof446;
case 446:
	if ( (*p) == 34 )
		goto st447;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto st446;
	goto tr34;
st447:
	if ( ++p == pe )
		goto _test_eof447;
case 447:
	switch( (*p) ) {
		case 44: goto st444;
		case 62: goto st387;
	}
	goto tr34;
st448:
	if ( ++p == pe )
		goto _test_eof448;
case 448:
	if ( (*p) == 95 )
		goto st448;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st429;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st429;
		} else if ( (*p) >= 65 )
			goto st429;
	} else
		goto st429;
	goto tr34;
st449:
	if ( ++p == pe )
		goto _test_eof449;
case 449:
	if ( (*p) == 95 )
		goto st449;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st417;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st417;
		} else if ( (*p) >= 65 )
			goto st417;
	} else
		goto st417;
	goto tr34;
st450:
	if ( ++p == pe )
		goto _test_eof450;
case 450:
	switch( (*p) ) {
		case 45: goto st406;
		case 46: goto st450;
		case 95: goto st406;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st406;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st406;
	} else
		goto st406;
	goto tr448;
st451:
	if ( ++p == pe )
		goto _test_eof451;
case 451:
	if ( (*p) == 95 )
		goto st451;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st406;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st406;
		} else if ( (*p) >= 65 )
			goto st406;
	} else
		goto st406;
	goto tr448;
tr31:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st452;
st452:
	if ( ++p == pe )
		goto _test_eof452;
case 452:
#line 8579 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr39;
		case 95: goto st21;
		case 115: goto st453;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st21;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st21;
	} else
		goto st21;
	goto tr37;
st453:
	if ( ++p == pe )
		goto _test_eof453;
case 453:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr39;
		case 95: goto st21;
		case 115: goto st454;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st21;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st21;
	} else
		goto st21;
	goto tr37;
st454:
	if ( ++p == pe )
		goto _test_eof454;
case 454:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr39;
		case 95: goto st21;
		case 101: goto st455;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st21;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st21;
	} else
		goto st21;
	goto tr37;
st455:
	if ( ++p == pe )
		goto _test_eof455;
case 455:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr39;
		case 95: goto st21;
		case 109: goto st456;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st21;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st21;
	} else
		goto st21;
	goto tr37;
st456:
	if ( ++p == pe )
		goto _test_eof456;
case 456:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr39;
		case 95: goto st21;
		case 98: goto st457;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st21;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st21;
	} else
		goto st21;
	goto tr37;
st457:
	if ( ++p == pe )
		goto _test_eof457;
case 457:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr39;
		case 95: goto st21;
		case 108: goto st458;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st21;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st21;
	} else
		goto st21;
	goto tr37;
st458:
	if ( ++p == pe )
		goto _test_eof458;
case 458:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr39;
		case 95: goto st21;
		case 121: goto st459;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st21;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st21;
	} else
		goto st21;
	goto tr37;
st459:
	if ( ++p == pe )
		goto _test_eof459;
case 459:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto st460;
		case 95: goto st21;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st21;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st21;
	} else
		goto st21;
	goto tr37;
st460:
	if ( ++p == pe )
		goto _test_eof460;
case 460:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st461;
	} else if ( (*p) >= 65 )
		goto st461;
	goto tr504;
st461:
	if ( ++p == pe )
		goto _test_eof461;
case 461:
	switch( (*p) ) {
		case 10: goto tr504;
		case 35: goto tr504;
		case 47: goto tr504;
		case 58: goto tr504;
		case 63: goto tr504;
	}
	goto st462;
st462:
	if ( ++p == pe )
		goto _test_eof462;
case 462:
	switch( (*p) ) {
		case 10: goto tr504;
		case 35: goto tr504;
		case 47: goto tr504;
		case 58: goto st463;
		case 63: goto tr504;
	}
	goto st462;
st463:
	if ( ++p == pe )
		goto _test_eof463;
case 463:
	if ( (*p) == 47 )
		goto st464;
	goto tr504;
st464:
	if ( ++p == pe )
		goto _test_eof464;
case 464:
	if ( (*p) == 47 )
		goto st465;
	goto tr504;
st465:
	if ( ++p == pe )
		goto _test_eof465;
case 465:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st466;
	} else if ( (*p) >= 65 )
		goto st466;
	goto tr504;
st466:
	if ( ++p == pe )
		goto _test_eof466;
case 466:
	if ( (*p) == 10 )
		goto tr437;
	goto st466;
tr32:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st467;
st467:
	if ( ++p == pe )
		goto _test_eof467;
case 467:
#line 8898 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr39;
		case 95: goto st21;
		case 111: goto st468;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st21;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st21;
	} else
		goto st21;
	goto tr37;
st468:
	if ( ++p == pe )
		goto _test_eof468;
case 468:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr39;
		case 95: goto st21;
		case 110: goto st469;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st21;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st21;
	} else
		goto st21;
	goto tr37;
st469:
	if ( ++p == pe )
		goto _test_eof469;
case 469:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr39;
		case 95: goto st21;
		case 116: goto st470;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st21;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st21;
	} else
		goto st21;
	goto tr37;
st470:
	if ( ++p == pe )
		goto _test_eof470;
case 470:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr39;
		case 95: goto st21;
		case 105: goto st471;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st21;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st21;
	} else
		goto st21;
	goto tr37;
st471:
	if ( ++p == pe )
		goto _test_eof471;
case 471:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr39;
		case 95: goto st21;
		case 103: goto st472;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st21;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st21;
	} else
		goto st21;
	goto tr37;
st472:
	if ( ++p == pe )
		goto _test_eof472;
case 472:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto st473;
		case 95: goto st21;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st21;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st21;
	} else
		goto st21;
	goto tr37;
st473:
	if ( ++p == pe )
		goto _test_eof473;
case 473:
	if ( (*p) == 60 )
		goto st474;
	goto tr34;
st474:
	if ( ++p == pe )
		goto _test_eof474;
case 474:
	if ( (*p) == 73 )
		goto st475;
	goto tr34;
st475:
	if ( ++p == pe )
		goto _test_eof475;
case 475:
	if ( (*p) == 68 )
		goto st476;
	goto tr34;
st476:
	if ( ++p == pe )
		goto _test_eof476;
case 476:
	if ( (*p) == 61 )
		goto st477;
	goto tr34;
st477:
	if ( ++p == pe )
		goto _test_eof477;
case 477:
	switch( (*p) ) {
		case 45: goto st478;
		case 46: goto st492;
		case 95: goto st493;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st479;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st479;
	} else
		goto st479;
	goto tr448;
st478:
	if ( ++p == pe )
		goto _test_eof478;
case 478:
	switch( (*p) ) {
		case 45: goto st478;
		case 46: goto st479;
		case 95: goto st479;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st479;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st479;
	} else
		goto st479;
	goto tr448;
st479:
	if ( ++p == pe )
		goto _test_eof479;
case 479:
	switch( (*p) ) {
		case 44: goto st480;
		case 95: goto st479;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st479;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st479;
		} else if ( (*p) >= 65 )
			goto st479;
	} else
		goto st479;
	goto tr448;
st480:
	if ( ++p == pe )
		goto _test_eof480;
case 480:
	if ( (*p) == 85 )
		goto st481;
	goto tr34;
st481:
	if ( ++p == pe )
		goto _test_eof481;
case 481:
	if ( (*p) == 82 )
		goto st482;
	goto tr34;
st482:
	if ( ++p == pe )
		goto _test_eof482;
case 482:
	if ( (*p) == 76 )
		goto st483;
	goto tr34;
st483:
	if ( ++p == pe )
		goto _test_eof483;
case 483:
	if ( (*p) == 61 )
		goto st484;
	goto tr34;
st484:
	if ( ++p == pe )
		goto _test_eof484;
case 484:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st485;
	} else if ( (*p) >= 65 )
		goto st485;
	goto tr504;
st485:
	if ( ++p == pe )
		goto _test_eof485;
case 485:
	switch( (*p) ) {
		case 10: goto tr504;
		case 35: goto tr504;
		case 47: goto tr504;
		case 58: goto tr504;
		case 63: goto tr504;
	}
	goto st486;
st486:
	if ( ++p == pe )
		goto _test_eof486;
case 486:
	switch( (*p) ) {
		case 10: goto tr504;
		case 35: goto tr504;
		case 47: goto tr504;
		case 58: goto st487;
		case 63: goto tr504;
	}
	goto st486;
st487:
	if ( ++p == pe )
		goto _test_eof487;
case 487:
	if ( (*p) == 47 )
		goto st488;
	goto tr504;
st488:
	if ( ++p == pe )
		goto _test_eof488;
case 488:
	if ( (*p) == 47 )
		goto st489;
	goto tr504;
st489:
	if ( ++p == pe )
		goto _test_eof489;
case 489:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st490;
	} else if ( (*p) >= 65 )
		goto st490;
	goto tr504;
st490:
	if ( ++p == pe )
		goto _test_eof490;
case 490:
	switch( (*p) ) {
		case 10: goto tr504;
		case 62: goto st491;
	}
	goto st490;
st491:
	if ( ++p == pe )
		goto _test_eof491;
case 491:
	switch( (*p) ) {
		case 10: goto tr437;
		case 62: goto st491;
	}
	goto st490;
st492:
	if ( ++p == pe )
		goto _test_eof492;
case 492:
	switch( (*p) ) {
		case 45: goto st479;
		case 46: goto st492;
		case 95: goto st479;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st479;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st479;
	} else
		goto st479;
	goto tr448;
st493:
	if ( ++p == pe )
		goto _test_eof493;
case 493:
	if ( (*p) == 95 )
		goto st493;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st479;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st479;
		} else if ( (*p) >= 65 )
			goto st479;
	} else
		goto st479;
	goto tr448;
tr33:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st494;
st494:
	if ( ++p == pe )
		goto _test_eof494;
case 494:
#line 9314 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr39;
		case 95: goto st21;
		case 101: goto st495;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st21;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st21;
	} else
		goto st21;
	goto tr37;
st495:
	if ( ++p == pe )
		goto _test_eof495;
case 495:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr39;
		case 95: goto st21;
		case 100: goto st496;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st21;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st21;
	} else
		goto st21;
	goto tr37;
st496:
	if ( ++p == pe )
		goto _test_eof496;
case 496:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr39;
		case 95: goto st21;
		case 105: goto st497;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st21;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st21;
	} else
		goto st21;
	goto tr37;
st497:
	if ( ++p == pe )
		goto _test_eof497;
case 497:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr39;
		case 95: goto st21;
		case 103: goto st498;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st21;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st21;
	} else
		goto st21;
	goto tr37;
st498:
	if ( ++p == pe )
		goto _test_eof498;
case 498:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr39;
		case 95: goto st21;
		case 114: goto st499;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st21;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st21;
	} else
		goto st21;
	goto tr37;
st499:
	if ( ++p == pe )
		goto _test_eof499;
case 499:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr39;
		case 95: goto st21;
		case 101: goto st500;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st21;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st21;
	} else
		goto st21;
	goto tr37;
st500:
	if ( ++p == pe )
		goto _test_eof500;
case 500:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr39;
		case 95: goto st21;
		case 101: goto st501;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st21;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st21;
	} else
		goto st21;
	goto tr37;
st501:
	if ( ++p == pe )
		goto _test_eof501;
case 501:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr39;
		case 68: goto st502;
		case 95: goto st21;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st21;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st21;
	} else
		goto st21;
	goto tr37;
st502:
	if ( ++p == pe )
		goto _test_eof502;
case 502:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr39;
		case 66: goto st503;
		case 95: goto st21;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st21;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st21;
	} else
		goto st21;
	goto tr37;
st503:
	if ( ++p == pe )
		goto _test_eof503;
case 503:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto st504;
		case 95: goto st21;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st19;
		} else
			goto st21;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st19;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st19;
		} else
			goto st21;
	} else
		goto st21;
	goto tr37;
st504:
	if ( ++p == pe )
		goto _test_eof504;
case 504:
	if ( (*p) == 60 )
		goto st484;
	goto tr34;
st505:
	if ( ++p == pe )
		goto _test_eof505;
case 505:
	if ( (*p) == 72 )
		goto st506;
	goto tr547;
st506:
	if ( ++p == pe )
		goto _test_eof506;
case 506:
	if ( (*p) == 82 )
		goto st507;
	goto tr547;
st507:
	if ( ++p == pe )
		goto _test_eof507;
case 507:
	if ( (*p) == 79 )
		goto st508;
	goto tr547;
st508:
	if ( ++p == pe )
		goto _test_eof508;
case 508:
	if ( (*p) == 77 )
		goto st509;
	goto tr547;
st509:
	if ( ++p == pe )
		goto _test_eof509;
case 509:
	if ( (*p) == 9 )
		goto st510;
	goto tr547;
st510:
	if ( ++p == pe )
		goto _test_eof510;
case 510:
	if ( (*p) == 80 )
		goto st511;
	goto tr547;
st511:
	if ( ++p == pe )
		goto _test_eof511;
case 511:
	if ( (*p) == 79 )
		goto st512;
	goto tr547;
st512:
	if ( ++p == pe )
		goto _test_eof512;
case 512:
	if ( (*p) == 83 )
		goto st513;
	goto tr547;
st513:
	if ( ++p == pe )
		goto _test_eof513;
case 513:
	if ( (*p) == 9 )
		goto st514;
	goto tr547;
st514:
	if ( ++p == pe )
		goto _test_eof514;
case 514:
	if ( (*p) == 73 )
		goto st515;
	goto tr547;
st515:
	if ( ++p == pe )
		goto _test_eof515;
case 515:
	if ( (*p) == 68 )
		goto st516;
	goto tr547;
st516:
	if ( ++p == pe )
		goto _test_eof516;
case 516:
	if ( (*p) == 9 )
		goto st517;
	goto tr547;
st517:
	if ( ++p == pe )
		goto _test_eof517;
case 517:
	if ( (*p) == 82 )
		goto st518;
	goto tr547;
st518:
	if ( ++p == pe )
		goto _test_eof518;
case 518:
	if ( (*p) == 69 )
		goto st519;
	goto tr547;
st519:
	if ( ++p == pe )
		goto _test_eof519;
case 519:
	if ( (*p) == 70 )
		goto st520;
	goto tr547;
st520:
	if ( ++p == pe )
		goto _test_eof520;
case 520:
	if ( (*p) == 9 )
		goto st521;
	goto tr547;
st521:
	if ( ++p == pe )
		goto _test_eof521;
case 521:
	if ( (*p) == 65 )
		goto st522;
	goto tr547;
st522:
	if ( ++p == pe )
		goto _test_eof522;
case 522:
	if ( (*p) == 76 )
		goto st523;
	goto tr547;
st523:
	if ( ++p == pe )
		goto _test_eof523;
case 523:
	if ( (*p) == 84 )
		goto st524;
	goto tr547;
st524:
	if ( ++p == pe )
		goto _test_eof524;
case 524:
	if ( (*p) == 9 )
		goto st525;
	goto tr547;
st525:
	if ( ++p == pe )
		goto _test_eof525;
case 525:
	if ( (*p) == 81 )
		goto st526;
	goto tr547;
st526:
	if ( ++p == pe )
		goto _test_eof526;
case 526:
	if ( (*p) == 85 )
		goto st527;
	goto tr547;
st527:
	if ( ++p == pe )
		goto _test_eof527;
case 527:
	if ( (*p) == 65 )
		goto st528;
	goto tr547;
st528:
	if ( ++p == pe )
		goto _test_eof528;
case 528:
	if ( (*p) == 76 )
		goto st529;
	goto tr547;
st529:
	if ( ++p == pe )
		goto _test_eof529;
case 529:
	if ( (*p) == 9 )
		goto st530;
	goto tr547;
st530:
	if ( ++p == pe )
		goto _test_eof530;
case 530:
	if ( (*p) == 70 )
		goto st531;
	goto tr547;
st531:
	if ( ++p == pe )
		goto _test_eof531;
case 531:
	if ( (*p) == 73 )
		goto st532;
	goto tr547;
st532:
	if ( ++p == pe )
		goto _test_eof532;
case 532:
	if ( (*p) == 76 )
		goto st533;
	goto tr547;
st533:
	if ( ++p == pe )
		goto _test_eof533;
case 533:
	if ( (*p) == 84 )
		goto st534;
	goto tr547;
st534:
	if ( ++p == pe )
		goto _test_eof534;
case 534:
	if ( (*p) == 69 )
		goto st535;
	goto tr547;
st535:
	if ( ++p == pe )
		goto _test_eof535;
case 535:
	if ( (*p) == 82 )
		goto st536;
	goto tr547;
st536:
	if ( ++p == pe )
		goto _test_eof536;
case 536:
	if ( (*p) == 9 )
		goto st537;
	goto tr547;
st537:
	if ( ++p == pe )
		goto _test_eof537;
case 537:
	if ( (*p) == 73 )
		goto st538;
	goto tr547;
st538:
	if ( ++p == pe )
		goto _test_eof538;
case 538:
	if ( (*p) == 78 )
		goto st539;
	goto tr547;
st539:
	if ( ++p == pe )
		goto _test_eof539;
case 539:
	if ( (*p) == 70 )
		goto st540;
	goto tr547;
st540:
	if ( ++p == pe )
		goto _test_eof540;
case 540:
	if ( (*p) == 79 )
		goto st541;
	goto tr547;
st541:
	if ( ++p == pe )
		goto _test_eof541;
case 541:
	switch( (*p) ) {
		case 9: goto st542;
		case 10: goto tr585;
	}
	goto tr547;
st542:
	if ( ++p == pe )
		goto _test_eof542;
case 542:
	if ( (*p) == 70 )
		goto st543;
	goto tr547;
st543:
	if ( ++p == pe )
		goto _test_eof543;
case 543:
	if ( (*p) == 79 )
		goto st544;
	goto tr547;
st544:
	if ( ++p == pe )
		goto _test_eof544;
case 544:
	if ( (*p) == 82 )
		goto st545;
	goto tr547;
st545:
	if ( ++p == pe )
		goto _test_eof545;
case 545:
	if ( (*p) == 77 )
		goto st546;
	goto tr547;
st546:
	if ( ++p == pe )
		goto _test_eof546;
case 546:
	if ( (*p) == 65 )
		goto st547;
	goto tr547;
st547:
	if ( ++p == pe )
		goto _test_eof547;
case 547:
	if ( (*p) == 84 )
		goto st548;
	goto tr547;
st548:
	if ( ++p == pe )
		goto _test_eof548;
case 548:
	if ( (*p) == 9 )
		goto st549;
	goto tr547;
tr594:
#line 110 "vcf_v41.ragel"
	{
//        add_vcf_sample_name(ts, p-ts, file);
    }
	goto st549;
st549:
	if ( ++p == pe )
		goto _test_eof549;
case 549:
#line 9947 "vcf_validator_detail.hpp"
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr593;
	goto tr547;
tr593:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st550;
st550:
	if ( ++p == pe )
		goto _test_eof550;
case 550:
#line 9961 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr594;
		case 10: goto tr595;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto st550;
	goto tr547;
tr585:
#line 23 "vcf_v41.ragel"
	{
        ++n_lines;
        n_columns = 1;
    }
	goto st709;
tr595:
#line 110 "vcf_v41.ragel"
	{
//        add_vcf_sample_name(ts, p-ts, file);
    }
#line 23 "vcf_v41.ragel"
	{
        ++n_lines;
        n_columns = 1;
    }
	goto st709;
st709:
	if ( ++p == pe )
		goto _test_eof709;
case 709:
#line 9991 "vcf_validator_detail.hpp"
	if ( (*p) == 60 )
		goto tr799;
	if ( (*p) < 59 ) {
		if ( 33 <= (*p) && (*p) <= 57 )
			goto tr798;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr798;
	} else
		goto tr798;
	goto tr797;
tr798:
#line 114 "vcf_v41.ragel"
	{
//        status->current_record = vcf_record_new();
//        printf("Reading record\n");
    }
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st551;
st551:
	if ( ++p == pe )
		goto _test_eof551;
case 551:
#line 10018 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr598;
		case 59: goto st551;
		case 61: goto st551;
	}
	if ( (*p) > 57 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto st551;
	} else if ( (*p) >= 33 )
		goto st551;
	goto tr597;
tr598:
#line 143 "vcf_v41.ragel"
	{
//        set_vcf_record_chromosome(ts, p-ts, status->current_record);
    }
#line 28 "vcf_v41.ragel"
	{
        ++n_columns;
    }
	goto st552;
st552:
	if ( ++p == pe )
		goto _test_eof552;
case 552:
#line 10044 "vcf_validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr601;
	goto tr600;
tr601:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st553;
st553:
	if ( ++p == pe )
		goto _test_eof553;
case 553:
#line 10058 "vcf_validator_detail.hpp"
	if ( (*p) == 9 )
		goto tr602;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st553;
	goto tr600;
tr602:
#line 147 "vcf_v41.ragel"
	{
//        char *field = strndup(ts, p-ts);
 //       set_vcf_record_position(atol(field), status->current_record);
 //       free(field);
    }
#line 28 "vcf_v41.ragel"
	{
        ++n_columns;
    }
	goto st554;
st554:
	if ( ++p == pe )
		goto _test_eof554;
case 554:
#line 10080 "vcf_validator_detail.hpp"
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr605;
	} else if ( (*p) >= 33 )
		goto tr605;
	goto tr604;
tr605:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st555;
st555:
	if ( ++p == pe )
		goto _test_eof555;
case 555:
#line 10097 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr606;
		case 59: goto st706;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st555;
	goto tr604;
tr606:
#line 153 "vcf_v41.ragel"
	{
//        set_vcf_record_id(ts, p-ts, status->current_record);
    }
#line 28 "vcf_v41.ragel"
	{
        ++n_columns;
    }
	goto st556;
st556:
	if ( ++p == pe )
		goto _test_eof556;
case 556:
#line 10119 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 65: goto tr610;
		case 67: goto tr610;
		case 71: goto tr610;
		case 78: goto tr610;
		case 84: goto tr610;
		case 97: goto tr610;
		case 99: goto tr610;
		case 103: goto tr610;
		case 110: goto tr610;
		case 116: goto tr610;
	}
	goto tr609;
tr610:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st557;
st557:
	if ( ++p == pe )
		goto _test_eof557;
case 557:
#line 10143 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr611;
		case 65: goto st557;
		case 67: goto st557;
		case 71: goto st557;
		case 78: goto st557;
		case 84: goto st557;
		case 97: goto st557;
		case 99: goto st557;
		case 103: goto st557;
		case 110: goto st557;
		case 116: goto st557;
	}
	goto tr609;
tr611:
#line 157 "vcf_v41.ragel"
	{
 //       set_vcf_record_reference(ts, p-ts, status->current_record);
    }
#line 28 "vcf_v41.ragel"
	{
        ++n_columns;
    }
	goto st558;
st558:
	if ( ++p == pe )
		goto _test_eof558;
case 558:
#line 10172 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 42: goto tr614;
		case 46: goto tr615;
		case 48: goto tr616;
		case 60: goto tr617;
		case 65: goto tr618;
		case 67: goto tr618;
		case 71: goto tr618;
		case 78: goto tr618;
		case 84: goto tr618;
		case 91: goto tr619;
		case 93: goto tr620;
		case 97: goto tr618;
		case 99: goto tr618;
		case 103: goto tr618;
		case 110: goto tr618;
		case 116: goto tr618;
	}
	goto tr613;
tr614:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st559;
st559:
	if ( ++p == pe )
		goto _test_eof559;
case 559:
#line 10202 "vcf_validator_detail.hpp"
	if ( (*p) == 9 )
		goto tr621;
	goto tr613;
tr621:
#line 173 "vcf_v41.ragel"
	{
 //       set_vcf_record_type(VARIANT_INDEL, status->current_record);
    }
#line 161 "vcf_v41.ragel"
	{
 /*       if (!strncmp("0", ts, 1)) {
            set_vcf_record_alternate(".", 1, status->current_record);
        } else {
            set_vcf_record_alternate(ts, p-ts, status->current_record);
        }*/
    }
#line 28 "vcf_v41.ragel"
	{
        ++n_columns;
    }
	goto st560;
tr730:
#line 169 "vcf_v41.ragel"
	{
 //       set_vcf_record_type(VARIANT_SNV, status->current_record);
    }
#line 161 "vcf_v41.ragel"
	{
 /*       if (!strncmp("0", ts, 1)) {
            set_vcf_record_alternate(".", 1, status->current_record);
        } else {
            set_vcf_record_alternate(ts, p-ts, status->current_record);
        }*/
    }
#line 28 "vcf_v41.ragel"
	{
        ++n_columns;
    }
	goto st560;
tr732:
#line 177 "vcf_v41.ragel"
	{
 //       set_vcf_record_type(VARIANT_SV, status->current_record);
    }
#line 161 "vcf_v41.ragel"
	{
 /*       if (!strncmp("0", ts, 1)) {
            set_vcf_record_alternate(".", 1, status->current_record);
        } else {
            set_vcf_record_alternate(ts, p-ts, status->current_record);
        }*/
    }
#line 28 "vcf_v41.ragel"
	{
        ++n_columns;
    }
	goto st560;
tr741:
#line 161 "vcf_v41.ragel"
	{
 /*       if (!strncmp("0", ts, 1)) {
            set_vcf_record_alternate(".", 1, status->current_record);
        } else {
            set_vcf_record_alternate(ts, p-ts, status->current_record);
        }*/
    }
#line 28 "vcf_v41.ragel"
	{
        ++n_columns;
    }
	goto st560;
st560:
	if ( ++p == pe )
		goto _test_eof560;
case 560:
#line 10278 "vcf_validator_detail.hpp"
	if ( (*p) == 46 )
		goto tr623;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr624;
	goto tr622;
tr623:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st561;
st561:
	if ( ++p == pe )
		goto _test_eof561;
case 561:
#line 10294 "vcf_validator_detail.hpp"
	if ( (*p) == 9 )
		goto tr625;
	goto tr622;
tr625:
#line 181 "vcf_v41.ragel"
	{
/*        float quality = -1.0f;
        if (strncmp(".", ts, 1) != 0) {
            char *field = strndup(ts, p-ts);
            quality = atof(field);
            free(field);
        }
        set_vcf_record_quality(quality, status->current_record);*/
    }
#line 28 "vcf_v41.ragel"
	{
        ++n_columns;
    }
	goto st562;
st562:
	if ( ++p == pe )
		goto _test_eof562;
case 562:
#line 10318 "vcf_validator_detail.hpp"
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr627;
	} else if ( (*p) >= 33 )
		goto tr627;
	goto tr626;
tr627:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st563;
st563:
	if ( ++p == pe )
		goto _test_eof563;
case 563:
#line 10335 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr628;
		case 59: goto st638;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st563;
	goto tr626;
tr628:
#line 191 "vcf_v41.ragel"
	{
 //       set_vcf_record_filter(ts, p-ts, status->current_record);
    }
#line 28 "vcf_v41.ragel"
	{
        ++n_columns;
    }
	goto st564;
st564:
	if ( ++p == pe )
		goto _test_eof564;
case 564:
#line 10357 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 46: goto tr632;
		case 49: goto tr634;
		case 65: goto tr635;
		case 66: goto tr636;
		case 67: goto tr637;
		case 68: goto tr638;
		case 69: goto tr639;
		case 72: goto tr640;
		case 77: goto tr641;
		case 78: goto tr642;
		case 83: goto tr643;
		case 86: goto tr644;
		case 95: goto tr633;
	}
	if ( (*p) < 70 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr633;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr633;
	} else
		goto tr633;
	goto tr631;
tr632:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st565;
st565:
	if ( ++p == pe )
		goto _test_eof565;
case 565:
#line 10392 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr645;
		case 10: goto tr646;
		case 59: goto st580;
		case 61: goto st582;
	}
	goto tr631;
tr645:
#line 195 "vcf_v41.ragel"
	{
//        set_vcf_record_info(ts, p-ts, status->current_record);
    }
#line 28 "vcf_v41.ragel"
	{
        ++n_columns;
    }
	goto st566;
st566:
	if ( ++p == pe )
		goto _test_eof566;
case 566:
#line 10414 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 45: goto tr650;
		case 46: goto tr651;
		case 95: goto tr653;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr652;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr652;
	} else
		goto tr652;
	goto tr649;
tr650:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st567;
st567:
	if ( ++p == pe )
		goto _test_eof567;
case 567:
#line 10439 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 45: goto st567;
		case 46: goto st568;
		case 95: goto st568;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st568;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st568;
	} else
		goto st568;
	goto tr649;
tr652:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st568;
st568:
	if ( ++p == pe )
		goto _test_eof568;
case 568:
#line 10464 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr656;
		case 58: goto st577;
		case 95: goto st568;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st568;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st568;
		} else if ( (*p) >= 65 )
			goto st568;
	} else
		goto st568;
	goto tr649;
tr656:
#line 199 "vcf_v41.ragel"
	{
 //       set_vcf_record_format(ts, p-ts, status->current_record);
    }
#line 28 "vcf_v41.ragel"
	{
        ++n_columns;
    }
	goto st569;
tr660:
#line 203 "vcf_v41.ragel"
	{
//        add_vcf_record_sample(ts, p-ts, status->current_record);
    }
#line 28 "vcf_v41.ragel"
	{
        ++n_columns;
    }
	goto st569;
st569:
	if ( ++p == pe )
		goto _test_eof569;
case 569:
#line 10506 "vcf_validator_detail.hpp"
	if ( (*p) == 46 )
		goto tr659;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr659;
	goto tr658;
tr659:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st570;
st570:
	if ( ++p == pe )
		goto _test_eof570;
case 570:
#line 10522 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr660;
		case 10: goto tr661;
		case 47: goto st574;
		case 58: goto st575;
		case 124: goto st574;
	}
	goto tr658;
tr646:
#line 195 "vcf_v41.ragel"
	{
//        set_vcf_record_info(ts, p-ts, status->current_record);
    }
#line 119 "vcf_v41.ragel"
	{
/*        // If batch is full, add to the list of batches and create a new, empty one
        if (batch_size > 0 && status->current_batch->records->size == batch_size)
        {
            add_vcf_batch(status->current_batch, file);
            LOG_DEBUG_F("Batch %d added - %zu records\t", batches, status->current_batch->records->size);
            status->current_batch = vcf_batch_new(batch_size);

            if (p+1) {
                status->current_batch->text = p+1;
                LOG_DEBUG_F("batch text = '%.*s'\n", 50, status->current_batch->text);
            }
            batches++;
        }

        // If not a blank line, add status->current record to status->current batch
        add_record_to_vcf_batch(status->current_record, status->current_batch);
        // If the record is a structural variant, add it to the set in the VCF file
        add_structural_variant(status->current_record, file);
        status->num_records++;
        status->num_samples = 0;
*/
    }
#line 23 "vcf_v41.ragel"
	{
        ++n_lines;
        n_columns = 1;
    }
	goto st710;
tr661:
#line 203 "vcf_v41.ragel"
	{
//        add_vcf_record_sample(ts, p-ts, status->current_record);
    }
#line 119 "vcf_v41.ragel"
	{
/*        // If batch is full, add to the list of batches and create a new, empty one
        if (batch_size > 0 && status->current_batch->records->size == batch_size)
        {
            add_vcf_batch(status->current_batch, file);
            LOG_DEBUG_F("Batch %d added - %zu records\t", batches, status->current_batch->records->size);
            status->current_batch = vcf_batch_new(batch_size);

            if (p+1) {
                status->current_batch->text = p+1;
                LOG_DEBUG_F("batch text = '%.*s'\n", 50, status->current_batch->text);
            }
            batches++;
        }

        // If not a blank line, add status->current record to status->current batch
        add_record_to_vcf_batch(status->current_record, status->current_batch);
        // If the record is a structural variant, add it to the set in the VCF file
        add_structural_variant(status->current_record, file);
        status->num_records++;
        status->num_samples = 0;
*/
    }
#line 23 "vcf_v41.ragel"
	{
        ++n_lines;
        n_columns = 1;
    }
	goto st710;
st710:
	if ( ++p == pe )
		goto _test_eof710;
case 710:
#line 10605 "vcf_validator_detail.hpp"
	if ( (*p) == 60 )
		goto tr799;
	if ( (*p) < 59 ) {
		if ( 33 <= (*p) && (*p) <= 57 )
			goto tr798;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr798;
	} else
		goto tr798;
	goto tr597;
tr799:
#line 114 "vcf_v41.ragel"
	{
//        status->current_record = vcf_record_new();
//        printf("Reading record\n");
    }
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st571;
st571:
	if ( ++p == pe )
		goto _test_eof571;
case 571:
#line 10632 "vcf_validator_detail.hpp"
	if ( (*p) < 59 ) {
		if ( 33 <= (*p) && (*p) <= 57 )
			goto st572;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto st572;
	} else
		goto st572;
	goto tr597;
st572:
	if ( ++p == pe )
		goto _test_eof572;
case 572:
	if ( (*p) == 62 )
		goto st573;
	if ( (*p) > 57 ) {
		if ( 59 <= (*p) && (*p) <= 126 )
			goto st572;
	} else if ( (*p) >= 33 )
		goto st572;
	goto tr597;
st573:
	if ( ++p == pe )
		goto _test_eof573;
case 573:
	if ( (*p) == 9 )
		goto tr598;
	goto tr597;
st574:
	if ( ++p == pe )
		goto _test_eof574;
case 574:
	if ( (*p) == 46 )
		goto st570;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st570;
	goto tr658;
st575:
	if ( ++p == pe )
		goto _test_eof575;
case 575:
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st576;
	goto tr658;
st576:
	if ( ++p == pe )
		goto _test_eof576;
case 576:
	switch( (*p) ) {
		case 9: goto tr660;
		case 10: goto tr661;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st576;
	goto tr658;
st577:
	if ( ++p == pe )
		goto _test_eof577;
case 577:
	switch( (*p) ) {
		case 45: goto st567;
		case 46: goto st578;
		case 95: goto st579;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st568;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st568;
	} else
		goto st568;
	goto tr649;
tr651:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st578;
st578:
	if ( ++p == pe )
		goto _test_eof578;
case 578:
#line 10716 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 45: goto st568;
		case 46: goto st578;
		case 95: goto st568;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st568;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st568;
	} else
		goto st568;
	goto tr649;
tr653:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st579;
st579:
	if ( ++p == pe )
		goto _test_eof579;
case 579:
#line 10741 "vcf_validator_detail.hpp"
	if ( (*p) == 95 )
		goto st579;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st568;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st568;
		} else if ( (*p) >= 65 )
			goto st568;
	} else
		goto st568;
	goto tr649;
st580:
	if ( ++p == pe )
		goto _test_eof580;
case 580:
	switch( (*p) ) {
		case 46: goto st565;
		case 49: goto st584;
		case 65: goto st591;
		case 66: goto st606;
		case 67: goto st610;
		case 68: goto st617;
		case 69: goto st618;
		case 72: goto st620;
		case 77: goto st621;
		case 78: goto st623;
		case 83: goto st624;
		case 86: goto st630;
		case 95: goto st581;
	}
	if ( (*p) < 70 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st581;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st581;
	} else
		goto st581;
	goto tr631;
tr633:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st581;
st581:
	if ( ++p == pe )
		goto _test_eof581;
case 581:
#line 10794 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr645;
		case 10: goto tr646;
		case 59: goto st580;
		case 61: goto st582;
		case 95: goto st581;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st581;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st581;
	} else
		goto st581;
	goto tr631;
st582:
	if ( ++p == pe )
		goto _test_eof582;
case 582:
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st583;
	goto tr631;
st583:
	if ( ++p == pe )
		goto _test_eof583;
case 583:
	switch( (*p) ) {
		case 9: goto tr645;
		case 10: goto tr646;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st583;
	goto tr631;
tr634:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st584;
st584:
	if ( ++p == pe )
		goto _test_eof584;
case 584:
#line 10839 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr645;
		case 10: goto tr646;
		case 48: goto st585;
		case 59: goto st580;
		case 61: goto st582;
		case 95: goto st581;
	}
	if ( (*p) < 65 ) {
		if ( 49 <= (*p) && (*p) <= 57 )
			goto st581;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st581;
	} else
		goto st581;
	goto tr631;
st585:
	if ( ++p == pe )
		goto _test_eof585;
case 585:
	switch( (*p) ) {
		case 9: goto tr645;
		case 10: goto tr646;
		case 48: goto st586;
		case 59: goto st580;
		case 61: goto st582;
		case 95: goto st581;
	}
	if ( (*p) < 65 ) {
		if ( 49 <= (*p) && (*p) <= 57 )
			goto st581;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st581;
	} else
		goto st581;
	goto tr631;
st586:
	if ( ++p == pe )
		goto _test_eof586;
case 586:
	switch( (*p) ) {
		case 9: goto tr645;
		case 10: goto tr646;
		case 48: goto st587;
		case 59: goto st580;
		case 61: goto st582;
		case 95: goto st581;
	}
	if ( (*p) < 65 ) {
		if ( 49 <= (*p) && (*p) <= 57 )
			goto st581;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st581;
	} else
		goto st581;
	goto tr631;
st587:
	if ( ++p == pe )
		goto _test_eof587;
case 587:
	switch( (*p) ) {
		case 9: goto tr645;
		case 10: goto tr646;
		case 59: goto st580;
		case 61: goto st582;
		case 71: goto st588;
		case 95: goto st581;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st581;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st581;
	} else
		goto st581;
	goto tr631;
st588:
	if ( ++p == pe )
		goto _test_eof588;
case 588:
	switch( (*p) ) {
		case 9: goto tr645;
		case 10: goto tr646;
		case 59: goto st580;
		case 61: goto st589;
		case 95: goto st581;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st581;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st581;
	} else
		goto st581;
	goto tr631;
st589:
	if ( ++p == pe )
		goto _test_eof589;
case 589:
	if ( 48 <= (*p) && (*p) <= 49 )
		goto st590;
	goto tr631;
st590:
	if ( ++p == pe )
		goto _test_eof590;
case 590:
	switch( (*p) ) {
		case 9: goto tr645;
		case 10: goto tr646;
		case 59: goto st580;
	}
	goto tr631;
tr635:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st591;
st591:
	if ( ++p == pe )
		goto _test_eof591;
case 591:
#line 10967 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr645;
		case 10: goto tr646;
		case 59: goto st580;
		case 61: goto st582;
		case 65: goto st592;
		case 67: goto st595;
		case 70: goto st598;
		case 78: goto st603;
		case 95: goto st581;
	}
	if ( (*p) < 66 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st581;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st581;
	} else
		goto st581;
	goto tr631;
st592:
	if ( ++p == pe )
		goto _test_eof592;
case 592:
	switch( (*p) ) {
		case 61: goto st593;
		case 95: goto st581;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st581;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st581;
	} else
		goto st581;
	goto tr631;
st593:
	if ( ++p == pe )
		goto _test_eof593;
case 593:
	switch( (*p) ) {
		case 46: goto st590;
		case 65: goto st594;
		case 67: goto st594;
		case 71: goto st594;
		case 78: goto st594;
		case 84: goto st594;
		case 97: goto st594;
		case 99: goto st594;
		case 103: goto st594;
		case 110: goto st594;
		case 116: goto st594;
	}
	goto tr631;
st594:
	if ( ++p == pe )
		goto _test_eof594;
case 594:
	switch( (*p) ) {
		case 9: goto tr645;
		case 10: goto tr646;
		case 59: goto st580;
		case 65: goto st594;
		case 67: goto st594;
		case 71: goto st594;
		case 78: goto st594;
		case 84: goto st594;
		case 97: goto st594;
		case 99: goto st594;
		case 103: goto st594;
		case 110: goto st594;
		case 116: goto st594;
	}
	goto tr631;
st595:
	if ( ++p == pe )
		goto _test_eof595;
case 595:
	switch( (*p) ) {
		case 61: goto st596;
		case 95: goto st581;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st581;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st581;
	} else
		goto st581;
	goto tr631;
st596:
	if ( ++p == pe )
		goto _test_eof596;
case 596:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st597;
	goto tr631;
st597:
	if ( ++p == pe )
		goto _test_eof597;
case 597:
	switch( (*p) ) {
		case 9: goto tr645;
		case 10: goto tr646;
		case 44: goto st596;
		case 59: goto st580;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st597;
	goto tr631;
st598:
	if ( ++p == pe )
		goto _test_eof598;
case 598:
	switch( (*p) ) {
		case 61: goto st599;
		case 95: goto st581;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st581;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st581;
	} else
		goto st581;
	goto tr631;
st599:
	if ( ++p == pe )
		goto _test_eof599;
case 599:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st600;
	goto tr631;
st600:
	if ( ++p == pe )
		goto _test_eof600;
case 600:
	switch( (*p) ) {
		case 9: goto tr645;
		case 10: goto tr646;
		case 44: goto st599;
		case 46: goto st601;
		case 59: goto st580;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st600;
	goto tr631;
st601:
	if ( ++p == pe )
		goto _test_eof601;
case 601:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st602;
	goto tr631;
st602:
	if ( ++p == pe )
		goto _test_eof602;
case 602:
	switch( (*p) ) {
		case 9: goto tr645;
		case 10: goto tr646;
		case 44: goto st599;
		case 59: goto st580;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st602;
	goto tr631;
st603:
	if ( ++p == pe )
		goto _test_eof603;
case 603:
	switch( (*p) ) {
		case 61: goto st604;
		case 95: goto st581;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st581;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st581;
	} else
		goto st581;
	goto tr631;
st604:
	if ( ++p == pe )
		goto _test_eof604;
case 604:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st605;
	goto tr631;
st605:
	if ( ++p == pe )
		goto _test_eof605;
case 605:
	switch( (*p) ) {
		case 9: goto tr645;
		case 10: goto tr646;
		case 59: goto st580;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st605;
	goto tr631;
tr636:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st606;
st606:
	if ( ++p == pe )
		goto _test_eof606;
case 606:
#line 11184 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr645;
		case 10: goto tr646;
		case 59: goto st580;
		case 61: goto st582;
		case 81: goto st607;
		case 95: goto st581;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st581;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st581;
	} else
		goto st581;
	goto tr631;
st607:
	if ( ++p == pe )
		goto _test_eof607;
case 607:
	switch( (*p) ) {
		case 61: goto st608;
		case 95: goto st581;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st581;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st581;
	} else
		goto st581;
	goto tr631;
st608:
	if ( ++p == pe )
		goto _test_eof608;
case 608:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st609;
	goto tr631;
st609:
	if ( ++p == pe )
		goto _test_eof609;
case 609:
	switch( (*p) ) {
		case 9: goto tr645;
		case 10: goto tr646;
		case 46: goto st604;
		case 59: goto st580;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st609;
	goto tr631;
tr637:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st610;
st610:
	if ( ++p == pe )
		goto _test_eof610;
case 610:
#line 11249 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr645;
		case 10: goto tr646;
		case 59: goto st580;
		case 61: goto st582;
		case 73: goto st611;
		case 95: goto st581;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st581;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st581;
	} else
		goto st581;
	goto tr631;
st611:
	if ( ++p == pe )
		goto _test_eof611;
case 611:
	switch( (*p) ) {
		case 9: goto tr645;
		case 10: goto tr646;
		case 59: goto st580;
		case 61: goto st582;
		case 71: goto st612;
		case 95: goto st581;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st581;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st581;
	} else
		goto st581;
	goto tr631;
st612:
	if ( ++p == pe )
		goto _test_eof612;
case 612:
	switch( (*p) ) {
		case 9: goto tr645;
		case 10: goto tr646;
		case 59: goto st580;
		case 61: goto st582;
		case 65: goto st613;
		case 95: goto st581;
	}
	if ( (*p) < 66 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st581;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st581;
	} else
		goto st581;
	goto tr631;
st613:
	if ( ++p == pe )
		goto _test_eof613;
case 613:
	switch( (*p) ) {
		case 9: goto tr645;
		case 10: goto tr646;
		case 59: goto st580;
		case 61: goto st582;
		case 82: goto st614;
		case 95: goto st581;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st581;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st581;
	} else
		goto st581;
	goto tr631;
st614:
	if ( ++p == pe )
		goto _test_eof614;
case 614:
	switch( (*p) ) {
		case 61: goto st615;
		case 95: goto st581;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st581;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st581;
	} else
		goto st581;
	goto tr631;
st615:
	if ( ++p == pe )
		goto _test_eof615;
case 615:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st616;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st616;
	} else
		goto st616;
	goto tr631;
st616:
	if ( ++p == pe )
		goto _test_eof616;
case 616:
	switch( (*p) ) {
		case 9: goto tr645;
		case 10: goto tr646;
		case 59: goto st580;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st616;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st616;
	} else
		goto st616;
	goto tr631;
tr638:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st617;
st617:
	if ( ++p == pe )
		goto _test_eof617;
case 617:
#line 11388 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr645;
		case 10: goto tr646;
		case 59: goto st580;
		case 61: goto st582;
		case 66: goto st588;
		case 80: goto st603;
		case 95: goto st581;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st581;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st581;
	} else
		goto st581;
	goto tr631;
tr639:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st618;
st618:
	if ( ++p == pe )
		goto _test_eof618;
case 618:
#line 11417 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr645;
		case 10: goto tr646;
		case 59: goto st580;
		case 61: goto st582;
		case 78: goto st619;
		case 95: goto st581;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st581;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st581;
	} else
		goto st581;
	goto tr631;
st619:
	if ( ++p == pe )
		goto _test_eof619;
case 619:
	switch( (*p) ) {
		case 9: goto tr645;
		case 10: goto tr646;
		case 59: goto st580;
		case 61: goto st582;
		case 68: goto st603;
		case 95: goto st581;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st581;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st581;
	} else
		goto st581;
	goto tr631;
tr640:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st620;
st620:
	if ( ++p == pe )
		goto _test_eof620;
case 620:
#line 11466 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr645;
		case 10: goto tr646;
		case 59: goto st580;
		case 61: goto st582;
		case 95: goto st581;
	}
	if ( (*p) < 52 ) {
		if ( (*p) > 49 ) {
			if ( 50 <= (*p) && (*p) <= 51 )
				goto st588;
		} else if ( (*p) >= 48 )
			goto st581;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st581;
		} else if ( (*p) >= 65 )
			goto st581;
	} else
		goto st581;
	goto tr631;
tr641:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st621;
st621:
	if ( ++p == pe )
		goto _test_eof621;
case 621:
#line 11499 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr645;
		case 10: goto tr646;
		case 59: goto st580;
		case 61: goto st582;
		case 81: goto st622;
		case 95: goto st581;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st581;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st581;
	} else
		goto st581;
	goto tr631;
st622:
	if ( ++p == pe )
		goto _test_eof622;
case 622:
	switch( (*p) ) {
		case 48: goto st603;
		case 61: goto st608;
		case 95: goto st581;
	}
	if ( (*p) < 65 ) {
		if ( 49 <= (*p) && (*p) <= 57 )
			goto st581;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st581;
	} else
		goto st581;
	goto tr631;
tr642:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st623;
st623:
	if ( ++p == pe )
		goto _test_eof623;
case 623:
#line 11545 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr645;
		case 10: goto tr646;
		case 59: goto st580;
		case 61: goto st582;
		case 83: goto st603;
		case 95: goto st581;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st581;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st581;
	} else
		goto st581;
	goto tr631;
tr643:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st624;
st624:
	if ( ++p == pe )
		goto _test_eof624;
case 624:
#line 11573 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr645;
		case 10: goto tr646;
		case 59: goto st580;
		case 61: goto st582;
		case 66: goto st607;
		case 79: goto st625;
		case 95: goto st581;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st581;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st581;
	} else
		goto st581;
	goto tr631;
st625:
	if ( ++p == pe )
		goto _test_eof625;
case 625:
	switch( (*p) ) {
		case 9: goto tr645;
		case 10: goto tr646;
		case 59: goto st580;
		case 61: goto st582;
		case 77: goto st626;
		case 95: goto st581;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st581;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st581;
	} else
		goto st581;
	goto tr631;
st626:
	if ( ++p == pe )
		goto _test_eof626;
case 626:
	switch( (*p) ) {
		case 9: goto tr645;
		case 10: goto tr646;
		case 59: goto st580;
		case 61: goto st582;
		case 65: goto st627;
		case 95: goto st581;
	}
	if ( (*p) < 66 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st581;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st581;
	} else
		goto st581;
	goto tr631;
st627:
	if ( ++p == pe )
		goto _test_eof627;
case 627:
	switch( (*p) ) {
		case 9: goto tr645;
		case 10: goto tr646;
		case 59: goto st580;
		case 61: goto st582;
		case 84: goto st628;
		case 95: goto st581;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st581;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st581;
	} else
		goto st581;
	goto tr631;
st628:
	if ( ++p == pe )
		goto _test_eof628;
case 628:
	switch( (*p) ) {
		case 9: goto tr645;
		case 10: goto tr646;
		case 59: goto st580;
		case 61: goto st582;
		case 73: goto st629;
		case 95: goto st581;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st581;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st581;
	} else
		goto st581;
	goto tr631;
st629:
	if ( ++p == pe )
		goto _test_eof629;
case 629:
	switch( (*p) ) {
		case 9: goto tr645;
		case 10: goto tr646;
		case 59: goto st580;
		case 61: goto st582;
		case 67: goto st588;
		case 95: goto st581;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st581;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st581;
	} else
		goto st581;
	goto tr631;
tr644:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st630;
st630:
	if ( ++p == pe )
		goto _test_eof630;
case 630:
#line 11707 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr645;
		case 10: goto tr646;
		case 59: goto st580;
		case 61: goto st582;
		case 65: goto st631;
		case 95: goto st581;
	}
	if ( (*p) < 66 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st581;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st581;
	} else
		goto st581;
	goto tr631;
st631:
	if ( ++p == pe )
		goto _test_eof631;
case 631:
	switch( (*p) ) {
		case 9: goto tr645;
		case 10: goto tr646;
		case 59: goto st580;
		case 61: goto st582;
		case 76: goto st632;
		case 95: goto st581;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st581;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st581;
	} else
		goto st581;
	goto tr631;
st632:
	if ( ++p == pe )
		goto _test_eof632;
case 632:
	switch( (*p) ) {
		case 9: goto tr645;
		case 10: goto tr646;
		case 59: goto st580;
		case 61: goto st582;
		case 73: goto st633;
		case 95: goto st581;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st581;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st581;
	} else
		goto st581;
	goto tr631;
st633:
	if ( ++p == pe )
		goto _test_eof633;
case 633:
	switch( (*p) ) {
		case 9: goto tr645;
		case 10: goto tr646;
		case 59: goto st580;
		case 61: goto st582;
		case 68: goto st634;
		case 95: goto st581;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st581;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st581;
	} else
		goto st581;
	goto tr631;
st634:
	if ( ++p == pe )
		goto _test_eof634;
case 634:
	switch( (*p) ) {
		case 9: goto tr645;
		case 10: goto tr646;
		case 59: goto st580;
		case 61: goto st582;
		case 65: goto st635;
		case 95: goto st581;
	}
	if ( (*p) < 66 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st581;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st581;
	} else
		goto st581;
	goto tr631;
st635:
	if ( ++p == pe )
		goto _test_eof635;
case 635:
	switch( (*p) ) {
		case 9: goto tr645;
		case 10: goto tr646;
		case 59: goto st580;
		case 61: goto st582;
		case 84: goto st636;
		case 95: goto st581;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st581;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st581;
	} else
		goto st581;
	goto tr631;
st636:
	if ( ++p == pe )
		goto _test_eof636;
case 636:
	switch( (*p) ) {
		case 9: goto tr645;
		case 10: goto tr646;
		case 59: goto st580;
		case 61: goto st582;
		case 69: goto st637;
		case 95: goto st581;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st581;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st581;
	} else
		goto st581;
	goto tr631;
st637:
	if ( ++p == pe )
		goto _test_eof637;
case 637:
	switch( (*p) ) {
		case 9: goto tr645;
		case 10: goto tr646;
		case 59: goto st580;
		case 61: goto st582;
		case 68: goto st588;
		case 95: goto st581;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st581;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st581;
	} else
		goto st581;
	goto tr631;
st638:
	if ( ++p == pe )
		goto _test_eof638;
case 638:
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto st563;
	} else if ( (*p) >= 33 )
		goto st563;
	goto tr626;
tr624:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st639;
st639:
	if ( ++p == pe )
		goto _test_eof639;
case 639:
#line 11892 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr625;
		case 46: goto st640;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st639;
	goto tr622;
st640:
	if ( ++p == pe )
		goto _test_eof640;
case 640:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st641;
	goto tr622;
st641:
	if ( ++p == pe )
		goto _test_eof641;
case 641:
	if ( (*p) == 9 )
		goto tr625;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st641;
	goto tr622;
tr615:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st642;
st642:
	if ( ++p == pe )
		goto _test_eof642;
case 642:
#line 11926 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 65: goto st643;
		case 67: goto st643;
		case 71: goto st643;
		case 78: goto st643;
		case 84: goto st643;
		case 97: goto st643;
		case 99: goto st643;
		case 103: goto st643;
		case 110: goto st643;
		case 116: goto st643;
	}
	goto tr613;
st643:
	if ( ++p == pe )
		goto _test_eof643;
case 643:
	switch( (*p) ) {
		case 9: goto tr732;
		case 65: goto st643;
		case 67: goto st643;
		case 71: goto st643;
		case 78: goto st643;
		case 84: goto st643;
		case 97: goto st643;
		case 99: goto st643;
		case 103: goto st643;
		case 110: goto st643;
		case 116: goto st643;
	}
	goto tr613;
tr616:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st644;
st644:
	if ( ++p == pe )
		goto _test_eof644;
case 644:
#line 11969 "vcf_validator_detail.hpp"
	if ( (*p) == 9 )
		goto tr730;
	goto tr613;
tr617:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st645;
st645:
	if ( ++p == pe )
		goto _test_eof645;
case 645:
#line 11983 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 45: goto st646;
		case 46: goto st649;
		case 67: goto st650;
		case 68: goto st653;
		case 73: goto st670;
		case 95: goto st672;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st647;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st647;
	} else
		goto st647;
	goto tr613;
st646:
	if ( ++p == pe )
		goto _test_eof646;
case 646:
	switch( (*p) ) {
		case 45: goto st646;
		case 46: goto st647;
		case 95: goto st647;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st647;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st647;
	} else
		goto st647;
	goto tr613;
st647:
	if ( ++p == pe )
		goto _test_eof647;
case 647:
	switch( (*p) ) {
		case 62: goto st648;
		case 95: goto st647;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st647;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st647;
		} else if ( (*p) >= 65 )
			goto st647;
	} else
		goto st647;
	goto tr613;
st648:
	if ( ++p == pe )
		goto _test_eof648;
case 648:
	if ( (*p) == 9 )
		goto tr741;
	goto tr613;
st649:
	if ( ++p == pe )
		goto _test_eof649;
case 649:
	switch( (*p) ) {
		case 45: goto st647;
		case 46: goto st649;
		case 95: goto st647;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st647;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st647;
	} else
		goto st647;
	goto tr613;
st650:
	if ( ++p == pe )
		goto _test_eof650;
case 650:
	switch( (*p) ) {
		case 62: goto st648;
		case 78: goto st651;
		case 95: goto st647;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st647;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st647;
		} else if ( (*p) >= 65 )
			goto st647;
	} else
		goto st647;
	goto tr613;
st651:
	if ( ++p == pe )
		goto _test_eof651;
case 651:
	switch( (*p) ) {
		case 62: goto st648;
		case 86: goto st652;
		case 95: goto st647;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st647;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st647;
		} else if ( (*p) >= 65 )
			goto st647;
	} else
		goto st647;
	goto tr613;
st652:
	if ( ++p == pe )
		goto _test_eof652;
case 652:
	switch( (*p) ) {
		case 62: goto st559;
		case 95: goto st647;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st647;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st647;
		} else if ( (*p) >= 65 )
			goto st647;
	} else
		goto st647;
	goto tr613;
st653:
	if ( ++p == pe )
		goto _test_eof653;
case 653:
	switch( (*p) ) {
		case 62: goto st648;
		case 69: goto st654;
		case 85: goto st661;
		case 95: goto st647;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st647;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st647;
		} else if ( (*p) >= 65 )
			goto st647;
	} else
		goto st647;
	goto tr613;
st654:
	if ( ++p == pe )
		goto _test_eof654;
case 654:
	switch( (*p) ) {
		case 62: goto st648;
		case 76: goto st655;
		case 95: goto st647;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st647;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st647;
		} else if ( (*p) >= 65 )
			goto st647;
	} else
		goto st647;
	goto tr613;
st655:
	if ( ++p == pe )
		goto _test_eof655;
case 655:
	switch( (*p) ) {
		case 58: goto st656;
		case 62: goto st559;
		case 95: goto st647;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st647;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st647;
		} else if ( (*p) >= 65 )
			goto st647;
	} else
		goto st647;
	goto tr613;
st656:
	if ( ++p == pe )
		goto _test_eof656;
case 656:
	if ( (*p) == 77 )
		goto st657;
	goto tr613;
st657:
	if ( ++p == pe )
		goto _test_eof657;
case 657:
	if ( (*p) == 69 )
		goto st658;
	goto tr613;
st658:
	if ( ++p == pe )
		goto _test_eof658;
case 658:
	if ( (*p) == 58 )
		goto st659;
	goto tr613;
st659:
	if ( ++p == pe )
		goto _test_eof659;
case 659:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st660;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st660;
	} else
		goto st660;
	goto tr613;
st660:
	if ( ++p == pe )
		goto _test_eof660;
case 660:
	if ( (*p) == 62 )
		goto st559;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st660;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st660;
	} else
		goto st660;
	goto tr613;
st661:
	if ( ++p == pe )
		goto _test_eof661;
case 661:
	switch( (*p) ) {
		case 62: goto st648;
		case 80: goto st662;
		case 95: goto st647;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st647;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st647;
		} else if ( (*p) >= 65 )
			goto st647;
	} else
		goto st647;
	goto tr613;
st662:
	if ( ++p == pe )
		goto _test_eof662;
case 662:
	switch( (*p) ) {
		case 58: goto st663;
		case 62: goto st559;
		case 95: goto st647;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st647;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st647;
		} else if ( (*p) >= 65 )
			goto st647;
	} else
		goto st647;
	goto tr613;
st663:
	if ( ++p == pe )
		goto _test_eof663;
case 663:
	if ( (*p) == 84 )
		goto st664;
	goto tr613;
st664:
	if ( ++p == pe )
		goto _test_eof664;
case 664:
	if ( (*p) == 65 )
		goto st665;
	goto tr613;
st665:
	if ( ++p == pe )
		goto _test_eof665;
case 665:
	if ( (*p) == 78 )
		goto st666;
	goto tr613;
st666:
	if ( ++p == pe )
		goto _test_eof666;
case 666:
	if ( (*p) == 68 )
		goto st667;
	goto tr613;
st667:
	if ( ++p == pe )
		goto _test_eof667;
case 667:
	if ( (*p) == 69 )
		goto st668;
	goto tr613;
st668:
	if ( ++p == pe )
		goto _test_eof668;
case 668:
	if ( (*p) == 77 )
		goto st669;
	goto tr613;
st669:
	if ( ++p == pe )
		goto _test_eof669;
case 669:
	if ( (*p) == 62 )
		goto st559;
	goto tr613;
st670:
	if ( ++p == pe )
		goto _test_eof670;
case 670:
	switch( (*p) ) {
		case 62: goto st648;
		case 78: goto st671;
		case 95: goto st647;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st647;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st647;
		} else if ( (*p) >= 65 )
			goto st647;
	} else
		goto st647;
	goto tr613;
st671:
	if ( ++p == pe )
		goto _test_eof671;
case 671:
	switch( (*p) ) {
		case 62: goto st648;
		case 83: goto st655;
		case 86: goto st652;
		case 95: goto st647;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st647;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st647;
		} else if ( (*p) >= 65 )
			goto st647;
	} else
		goto st647;
	goto tr613;
st672:
	if ( ++p == pe )
		goto _test_eof672;
case 672:
	if ( (*p) == 95 )
		goto st672;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st647;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st647;
		} else if ( (*p) >= 65 )
			goto st647;
	} else
		goto st647;
	goto tr613;
tr618:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st673;
st673:
	if ( ++p == pe )
		goto _test_eof673;
case 673:
#line 12401 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr730;
		case 44: goto st674;
		case 46: goto st676;
		case 65: goto st673;
		case 67: goto st673;
		case 71: goto st673;
		case 78: goto st673;
		case 84: goto st673;
		case 91: goto st677;
		case 93: goto st684;
		case 97: goto st673;
		case 99: goto st673;
		case 103: goto st673;
		case 110: goto st673;
		case 116: goto st673;
	}
	goto tr613;
st674:
	if ( ++p == pe )
		goto _test_eof674;
case 674:
	switch( (*p) ) {
		case 65: goto st675;
		case 67: goto st675;
		case 71: goto st675;
		case 78: goto st675;
		case 84: goto st675;
		case 97: goto st675;
		case 99: goto st675;
		case 103: goto st675;
		case 110: goto st675;
		case 116: goto st675;
	}
	goto tr613;
st675:
	if ( ++p == pe )
		goto _test_eof675;
case 675:
	switch( (*p) ) {
		case 9: goto tr730;
		case 44: goto st674;
		case 65: goto st675;
		case 67: goto st675;
		case 71: goto st675;
		case 78: goto st675;
		case 84: goto st675;
		case 97: goto st675;
		case 99: goto st675;
		case 103: goto st675;
		case 110: goto st675;
		case 116: goto st675;
	}
	goto tr613;
st676:
	if ( ++p == pe )
		goto _test_eof676;
case 676:
	if ( (*p) == 9 )
		goto tr732;
	goto tr613;
st677:
	if ( ++p == pe )
		goto _test_eof677;
case 677:
	if ( (*p) == 60 )
		goto st681;
	if ( (*p) < 59 ) {
		if ( 33 <= (*p) && (*p) <= 57 )
			goto st678;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto st678;
	} else
		goto st678;
	goto tr613;
st678:
	if ( ++p == pe )
		goto _test_eof678;
case 678:
	switch( (*p) ) {
		case 58: goto st679;
		case 61: goto st678;
	}
	if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto st678;
	} else if ( (*p) >= 33 )
		goto st678;
	goto tr613;
st679:
	if ( ++p == pe )
		goto _test_eof679;
case 679:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st680;
	goto tr613;
st680:
	if ( ++p == pe )
		goto _test_eof680;
case 680:
	if ( (*p) == 91 )
		goto st676;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st680;
	goto tr613;
st681:
	if ( ++p == pe )
		goto _test_eof681;
case 681:
	if ( (*p) < 59 ) {
		if ( 33 <= (*p) && (*p) <= 57 )
			goto st682;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto st682;
	} else
		goto st682;
	goto tr613;
st682:
	if ( ++p == pe )
		goto _test_eof682;
case 682:
	if ( (*p) == 62 )
		goto st683;
	if ( (*p) > 57 ) {
		if ( 59 <= (*p) && (*p) <= 126 )
			goto st682;
	} else if ( (*p) >= 33 )
		goto st682;
	goto tr613;
st683:
	if ( ++p == pe )
		goto _test_eof683;
case 683:
	if ( (*p) == 58 )
		goto st679;
	goto tr613;
st684:
	if ( ++p == pe )
		goto _test_eof684;
case 684:
	if ( (*p) == 60 )
		goto st688;
	if ( (*p) < 59 ) {
		if ( 33 <= (*p) && (*p) <= 57 )
			goto st685;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto st685;
	} else
		goto st685;
	goto tr613;
st685:
	if ( ++p == pe )
		goto _test_eof685;
case 685:
	switch( (*p) ) {
		case 58: goto st686;
		case 61: goto st685;
	}
	if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto st685;
	} else if ( (*p) >= 33 )
		goto st685;
	goto tr613;
st686:
	if ( ++p == pe )
		goto _test_eof686;
case 686:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st687;
	goto tr613;
st687:
	if ( ++p == pe )
		goto _test_eof687;
case 687:
	if ( (*p) == 93 )
		goto st676;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st687;
	goto tr613;
st688:
	if ( ++p == pe )
		goto _test_eof688;
case 688:
	if ( (*p) < 59 ) {
		if ( 33 <= (*p) && (*p) <= 57 )
			goto st689;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto st689;
	} else
		goto st689;
	goto tr613;
st689:
	if ( ++p == pe )
		goto _test_eof689;
case 689:
	if ( (*p) == 62 )
		goto st690;
	if ( (*p) > 57 ) {
		if ( 59 <= (*p) && (*p) <= 126 )
			goto st689;
	} else if ( (*p) >= 33 )
		goto st689;
	goto tr613;
st690:
	if ( ++p == pe )
		goto _test_eof690;
case 690:
	if ( (*p) == 58 )
		goto st686;
	goto tr613;
tr619:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st691;
st691:
	if ( ++p == pe )
		goto _test_eof691;
case 691:
#line 12627 "vcf_validator_detail.hpp"
	if ( (*p) == 60 )
		goto st696;
	if ( (*p) < 59 ) {
		if ( 33 <= (*p) && (*p) <= 57 )
			goto st692;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto st692;
	} else
		goto st692;
	goto tr613;
st692:
	if ( ++p == pe )
		goto _test_eof692;
case 692:
	switch( (*p) ) {
		case 58: goto st693;
		case 61: goto st692;
	}
	if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto st692;
	} else if ( (*p) >= 33 )
		goto st692;
	goto tr613;
st693:
	if ( ++p == pe )
		goto _test_eof693;
case 693:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st694;
	goto tr613;
st694:
	if ( ++p == pe )
		goto _test_eof694;
case 694:
	if ( (*p) == 91 )
		goto st695;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st694;
	goto tr613;
st695:
	if ( ++p == pe )
		goto _test_eof695;
case 695:
	switch( (*p) ) {
		case 65: goto st643;
		case 67: goto st643;
		case 71: goto st643;
		case 78: goto st643;
		case 84: goto st643;
		case 97: goto st643;
		case 99: goto st643;
		case 103: goto st643;
		case 110: goto st643;
		case 116: goto st643;
	}
	goto tr613;
st696:
	if ( ++p == pe )
		goto _test_eof696;
case 696:
	if ( (*p) < 59 ) {
		if ( 33 <= (*p) && (*p) <= 57 )
			goto st697;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto st697;
	} else
		goto st697;
	goto tr613;
st697:
	if ( ++p == pe )
		goto _test_eof697;
case 697:
	if ( (*p) == 62 )
		goto st698;
	if ( (*p) > 57 ) {
		if ( 59 <= (*p) && (*p) <= 126 )
			goto st697;
	} else if ( (*p) >= 33 )
		goto st697;
	goto tr613;
st698:
	if ( ++p == pe )
		goto _test_eof698;
case 698:
	if ( (*p) == 58 )
		goto st693;
	goto tr613;
tr620:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st699;
st699:
	if ( ++p == pe )
		goto _test_eof699;
case 699:
#line 12728 "vcf_validator_detail.hpp"
	if ( (*p) == 60 )
		goto st703;
	if ( (*p) < 59 ) {
		if ( 33 <= (*p) && (*p) <= 57 )
			goto st700;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto st700;
	} else
		goto st700;
	goto tr613;
st700:
	if ( ++p == pe )
		goto _test_eof700;
case 700:
	switch( (*p) ) {
		case 58: goto st701;
		case 61: goto st700;
	}
	if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto st700;
	} else if ( (*p) >= 33 )
		goto st700;
	goto tr613;
st701:
	if ( ++p == pe )
		goto _test_eof701;
case 701:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st702;
	goto tr613;
st702:
	if ( ++p == pe )
		goto _test_eof702;
case 702:
	if ( (*p) == 93 )
		goto st695;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st702;
	goto tr613;
st703:
	if ( ++p == pe )
		goto _test_eof703;
case 703:
	if ( (*p) < 59 ) {
		if ( 33 <= (*p) && (*p) <= 57 )
			goto st704;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto st704;
	} else
		goto st704;
	goto tr613;
st704:
	if ( ++p == pe )
		goto _test_eof704;
case 704:
	if ( (*p) == 62 )
		goto st705;
	if ( (*p) > 57 ) {
		if ( 59 <= (*p) && (*p) <= 126 )
			goto st704;
	} else if ( (*p) >= 33 )
		goto st704;
	goto tr613;
st705:
	if ( ++p == pe )
		goto _test_eof705;
case 705:
	if ( (*p) == 58 )
		goto st701;
	goto tr613;
st706:
	if ( ++p == pe )
		goto _test_eof706;
case 706:
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto st555;
	} else if ( (*p) >= 33 )
		goto st555;
	goto tr604;
st707:
	if ( ++p == pe )
		goto _test_eof707;
case 707:
	if ( (*p) == 10 )
		goto tr794;
	goto st707;
tr794:
#line 23 "vcf_v41.ragel"
	{
        ++n_lines;
        n_columns = 1;
    }
#line 527 "vcf_v41.ragel"
	{ {goto st20;} }
	goto st711;
st711:
	if ( ++p == pe )
		goto _test_eof711;
case 711:
#line 12832 "vcf_validator_detail.hpp"
	goto st0;
st708:
	if ( ++p == pe )
		goto _test_eof708;
case 708:
	if ( (*p) == 10 )
		goto tr796;
	goto st708;
tr796:
#line 23 "vcf_v41.ragel"
	{
        ++n_lines;
        n_columns = 1;
    }
#line 528 "vcf_v41.ragel"
	{ {goto st710;} }
	goto st712;
st712:
	if ( ++p == pe )
		goto _test_eof712;
case 712:
#line 12854 "vcf_validator_detail.hpp"
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
	_test_eof709: cs = 709; goto _test_eof; 
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
	_test_eof710: cs = 710; goto _test_eof; 
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
	_test_eof703: cs = 703; goto _test_eof; 
	_test_eof704: cs = 704; goto _test_eof; 
	_test_eof705: cs = 705; goto _test_eof; 
	_test_eof706: cs = 706; goto _test_eof; 
	_test_eof707: cs = 707; goto _test_eof; 
	_test_eof711: cs = 711; goto _test_eof; 
	_test_eof708: cs = 708; goto _test_eof; 
	_test_eof712: cs = 712; goto _test_eof; 

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
#line 35 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this);
        p--; {goto st707;}
    }
	break;
	case 19: 
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
	case 400: 
	case 401: 
	case 402: 
	case 403: 
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
	case 473: 
	case 474: 
	case 475: 
	case 476: 
	case 480: 
	case 481: 
	case 482: 
	case 483: 
	case 504: 
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st707;}
    }
	break;
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
#line 45 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        p--; {goto st708;}
    }
	break;
	case 14: 
	case 15: 
#line 211 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this,
            "Fileformat is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st707;}
    }
#line 35 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this);
        p--; {goto st707;}
    }
	break;
	case 125: 
	case 126: 
	case 127: 
	case 128: 
	case 133: 
	case 134: 
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
	case 149: 
#line 218 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in ALT metadata");
        p--; {goto st707;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st707;}
    }
	break;
	case 175: 
	case 176: 
	case 177: 
	case 178: 
	case 182: 
	case 183: 
	case 184: 
	case 185: 
	case 186: 
	case 187: 
	case 188: 
	case 189: 
	case 190: 
	case 191: 
	case 192: 
	case 193: 
	case 194: 
	case 195: 
	case 198: 
#line 234 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in FILTER metadata");
        p--; {goto st707;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st707;}
    }
	break;
	case 206: 
	case 207: 
	case 208: 
	case 209: 
	case 213: 
	case 214: 
	case 215: 
	case 216: 
	case 217: 
	case 218: 
	case 219: 
	case 222: 
	case 223: 
	case 224: 
	case 225: 
	case 226: 
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
	case 249: 
	case 250: 
	case 253: 
#line 240 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st707;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st707;}
    }
	break;
	case 274: 
	case 275: 
	case 276: 
	case 277: 
	case 281: 
	case 282: 
	case 283: 
	case 284: 
	case 285: 
	case 286: 
	case 287: 
	case 290: 
	case 291: 
	case 292: 
	case 293: 
	case 294: 
	case 305: 
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
	case 316: 
	case 317: 
	case 318: 
	case 321: 
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
#line 256 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in INFO metadata");
        p--; {goto st707;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st707;}
    }
	break;
	case 21: 
	case 22: 
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
	case 67: 
	case 68: 
	case 69: 
	case 70: 
	case 71: 
	case 72: 
	case 73: 
	case 74: 
	case 75: 
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
	case 89: 
	case 90: 
	case 91: 
	case 92: 
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
	case 106: 
	case 107: 
	case 108: 
	case 109: 
	case 110: 
	case 111: 
	case 112: 
	case 113: 
	case 114: 
	case 115: 
	case 116: 
	case 117: 
	case 118: 
	case 119: 
	case 120: 
	case 121: 
	case 370: 
	case 371: 
	case 372: 
	case 373: 
	case 374: 
	case 375: 
	case 376: 
	case 377: 
	case 394: 
	case 395: 
	case 396: 
	case 397: 
	case 398: 
	case 399: 
	case 452: 
	case 453: 
	case 454: 
	case 455: 
	case 456: 
	case 457: 
	case 458: 
	case 459: 
	case 467: 
	case 468: 
	case 469: 
	case 470: 
	case 471: 
	case 472: 
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
#line 272 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in metadata");
        p--; {goto st707;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st707;}
    }
	break;
	case 404: 
	case 405: 
	case 406: 
	case 450: 
	case 451: 
	case 477: 
	case 478: 
	case 479: 
	case 492: 
	case 493: 
#line 277 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st707;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st707;}
    }
	break;
	case 460: 
	case 461: 
	case 462: 
	case 463: 
	case 464: 
	case 465: 
	case 466: 
	case 484: 
	case 485: 
	case 486: 
	case 487: 
	case 488: 
	case 489: 
	case 490: 
	case 491: 
#line 287 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Metadata URL is not valid");
        p--; {goto st707;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st707;}
    }
	break;
	case 551: 
	case 571: 
	case 572: 
	case 573: 
#line 294 "vcf_v41.ragel"
	{
        printf("Line %zu: Error in 'chrom' field\n", n_lines);
        p--; {goto st708;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st708;}
    }
	break;
	case 552: 
	case 553: 
#line 299 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Position is not a positive number");
        p--; {goto st708;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st708;}
    }
	break;
	case 554: 
	case 555: 
	case 706: 
#line 304 "vcf_v41.ragel"
	{
        printf("Line %zu: Error in 'id' field\n", n_lines);
        p--; {goto st708;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st708;}
    }
	break;
	case 556: 
	case 557: 
#line 309 "vcf_v41.ragel"
	{
        printf("Line %zu: Error in 'reference' field\n", n_lines);
        p--; {goto st708;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st708;}
    }
	break;
	case 558: 
	case 559: 
	case 642: 
	case 643: 
	case 644: 
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
	case 700: 
	case 701: 
	case 702: 
	case 703: 
	case 704: 
	case 705: 
#line 314 "vcf_v41.ragel"
	{
        printf("Line %zu: Error in 'alternate' field\n", n_lines);
        p--; {goto st708;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st708;}
    }
	break;
	case 560: 
	case 561: 
	case 639: 
	case 640: 
	case 641: 
#line 319 "vcf_v41.ragel"
	{
        printf("Line %zu: Error in 'quality' field\n", n_lines);
        p--; {goto st708;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st708;}
    }
	break;
	case 562: 
	case 563: 
	case 638: 
#line 324 "vcf_v41.ragel"
	{
        printf("Line %zu: Error in 'filter' field\n", n_lines);
        p--; {goto st708;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st708;}
    }
	break;
	case 564: 
	case 565: 
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
#line 329 "vcf_v41.ragel"
	{
        printf("Line %zu: Error in 'info' field\n", n_lines);
        p--; {goto st708;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st708;}
    }
	break;
	case 566: 
	case 567: 
	case 568: 
	case 577: 
	case 578: 
	case 579: 
#line 334 "vcf_v41.ragel"
	{
        printf("Line %zu: Error in 'format' field\n", n_lines);
        p--; {goto st708;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st708;}
    }
	break;
	case 569: 
	case 570: 
	case 574: 
	case 575: 
	case 576: 
#line 339 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Incorrect sample format");
        p--; {goto st708;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st708;}
    }
	break;
	case 129: 
	case 130: 
	case 131: 
	case 164: 
	case 165: 
	case 166: 
	case 167: 
	case 168: 
#line 223 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "ALT metadata ID does not begin with DEL/INS/DUP/INV/CNV");
        p--; {goto st707;}
    }
#line 218 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in ALT metadata");
        p--; {goto st707;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st707;}
    }
	break;
	case 150: 
	case 151: 
	case 152: 
	case 153: 
	case 154: 
	case 155: 
	case 156: 
	case 157: 
	case 158: 
	case 159: 
	case 160: 
	case 161: 
	case 162: 
	case 163: 
#line 228 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "ALT metadata ID suffix (after ':') is not valid");
        p--; {goto st707;}
    }
#line 218 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in ALT metadata");
        p--; {goto st707;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st707;}
    }
	break;
	case 220: 
	case 221: 
	case 267: 
#line 245 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "FORMAT metadata Number is not a number, A, R, G or dot");
        p--; {goto st707;}
    }
#line 240 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st707;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st707;}
    }
	break;
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
	case 254: 
	case 255: 
	case 256: 
	case 257: 
	case 258: 
	case 259: 
	case 260: 
	case 261: 
	case 262: 
	case 263: 
	case 264: 
	case 265: 
	case 266: 
#line 250 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "FORMAT metadata Type is not a Integer, Float, Character or String");
        p--; {goto st707;}
    }
#line 240 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st707;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st707;}
    }
	break;
	case 288: 
	case 289: 
	case 367: 
#line 261 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "INFO metadata Number is not a number, A, R, G or dot");
        p--; {goto st707;}
    }
#line 256 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in INFO metadata");
        p--; {goto st707;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st707;}
    }
	break;
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
#line 266 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "INFO metadata Type is not a Integer, Float, Flag, Character or String");
        p--; {goto st707;}
    }
#line 256 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in INFO metadata");
        p--; {goto st707;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st707;}
    }
	break;
	case 122: 
	case 123: 
	case 124: 
#line 272 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in metadata");
        p--; {goto st707;}
    }
#line 218 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in ALT metadata");
        p--; {goto st707;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st707;}
    }
	break;
	case 170: 
	case 171: 
	case 172: 
	case 173: 
	case 174: 
#line 272 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in metadata");
        p--; {goto st707;}
    }
#line 234 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in FILTER metadata");
        p--; {goto st707;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st707;}
    }
	break;
	case 201: 
	case 202: 
	case 203: 
	case 204: 
	case 205: 
#line 272 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in metadata");
        p--; {goto st707;}
    }
#line 240 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st707;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st707;}
    }
	break;
	case 270: 
	case 271: 
	case 272: 
	case 273: 
#line 272 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in metadata");
        p--; {goto st707;}
    }
#line 256 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in INFO metadata");
        p--; {goto st707;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st707;}
    }
	break;
	case 179: 
	case 180: 
	case 181: 
	case 199: 
	case 200: 
#line 277 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st707;}
    }
#line 234 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in FILTER metadata");
        p--; {goto st707;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st707;}
    }
	break;
	case 210: 
	case 211: 
	case 212: 
	case 268: 
	case 269: 
#line 277 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st707;}
    }
#line 240 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st707;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st707;}
    }
	break;
	case 278: 
	case 279: 
	case 280: 
	case 368: 
	case 369: 
#line 277 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st707;}
    }
#line 256 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in INFO metadata");
        p--; {goto st707;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st707;}
    }
	break;
	case 147: 
	case 148: 
#line 282 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Metadata description string is not valid");
        p--; {goto st707;}
    }
#line 218 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in ALT metadata");
        p--; {goto st707;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st707;}
    }
	break;
	case 196: 
	case 197: 
#line 282 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Metadata description string is not valid");
        p--; {goto st707;}
    }
#line 234 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in FILTER metadata");
        p--; {goto st707;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st707;}
    }
	break;
	case 251: 
	case 252: 
#line 282 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Metadata description string is not valid");
        p--; {goto st707;}
    }
#line 240 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st707;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st707;}
    }
	break;
	case 319: 
	case 320: 
#line 282 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Metadata description string is not valid");
        p--; {goto st707;}
    }
#line 256 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in INFO metadata");
        p--; {goto st707;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st707;}
    }
	break;
	case 132: 
#line 223 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "ALT metadata ID does not begin with DEL/INS/DUP/INV/CNV");
        p--; {goto st707;}
    }
#line 228 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "ALT metadata ID suffix (after ':') is not valid");
        p--; {goto st707;}
    }
#line 218 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in ALT metadata");
        p--; {goto st707;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st707;}
    }
	break;
	case 169: 
#line 272 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in metadata");
        p--; {goto st707;}
    }
#line 234 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in FILTER metadata");
        p--; {goto st707;}
    }
#line 240 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st707;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st707;}
    }
	break;
	case 18: 
#line 272 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in metadata");
        p--; {goto st707;}
    }
#line 218 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in ALT metadata");
        p--; {goto st707;}
    }
#line 234 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in FILTER metadata");
        p--; {goto st707;}
    }
#line 240 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st707;}
    }
#line 256 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in INFO metadata");
        p--; {goto st707;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st707;}
    }
	break;
	case 17: 
	case 20: 
#line 272 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in metadata");
        p--; {goto st707;}
    }
#line 218 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in ALT metadata");
        p--; {goto st707;}
    }
#line 234 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in FILTER metadata");
        p--; {goto st707;}
    }
#line 240 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st707;}
    }
#line 256 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in INFO metadata");
        p--; {goto st707;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st707;}
    }
#line 45 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        p--; {goto st708;}
    }
	break;
	case 16: 
#line 35 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this);
        p--; {goto st707;}
    }
#line 272 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in metadata");
        p--; {goto st707;}
    }
#line 218 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in ALT metadata");
        p--; {goto st707;}
    }
#line 234 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in FILTER metadata");
        p--; {goto st707;}
    }
#line 240 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st707;}
    }
#line 256 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this, "Error in INFO metadata");
        p--; {goto st707;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st707;}
    }
#line 45 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        p--; {goto st708;}
    }
	break;
#line 14918 "vcf_validator_detail.hpp"
	}
	}

	_out: {}
	}

#line 591 "vcf_v41.ragel"

    }

  }
}
