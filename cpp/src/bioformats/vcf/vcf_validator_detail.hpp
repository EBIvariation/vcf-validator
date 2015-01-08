
#line 1 "vcf_v41.ragel"
#include <cstdio>

#include "vcf_validator.hpp"


#line 709 "vcf_v41.ragel"


namespace
{
  
#line 15 "vcf_validator_detail.hpp"
static const int vcf_start = 1;
static const int vcf_first_final = 715;
static const int vcf_error = 0;

static const int vcf_en_main = 1;
static const int vcf_en_main_meta_section = 20;
static const int vcf_en_main_body_section = 716;
static const int vcf_en_meta_section_skip = 713;
static const int vcf_en_body_section_skip = 714;


#line 715 "vcf_v41.ragel"

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

#line 727 "vcf_v41.ragel"

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
715
#line 760 "vcf_v41.ragel"
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
        p--; {goto st713;}
    }
	goto st0;
tr14:
#line 211 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this,
            "Fileformat is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st713;}
    }
#line 35 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this);
        p--; {goto st713;}
    }
	goto st0;
tr18:
#line 35 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this);
        p--; {goto st713;}
    }
#line 322 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in metadata");
        p--; {goto st713;}
    }
#line 218 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st713;}
    }
#line 246 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st713;}
    }
#line 252 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st713;}
    }
#line 268 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st713;}
    }
#line 234 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in assembly metadata");
        p--; {goto st713;}
    }
#line 240 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in contig metadata");
        p--; {goto st713;}
    }
#line 306 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st713;}
    }
#line 294 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in PEDIGREE metadata");
        p--; {goto st713;}
    }
#line 300 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in pedigreeDB metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
#line 45 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        p--; {goto st714;}
    }
	goto st0;
tr20:
#line 322 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in metadata");
        p--; {goto st713;}
    }
#line 218 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st713;}
    }
#line 246 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st713;}
    }
#line 252 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st713;}
    }
#line 268 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st713;}
    }
#line 234 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in assembly metadata");
        p--; {goto st713;}
    }
#line 240 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in contig metadata");
        p--; {goto st713;}
    }
#line 306 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st713;}
    }
#line 294 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in PEDIGREE metadata");
        p--; {goto st713;}
    }
#line 300 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in pedigreeDB metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
#line 45 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        p--; {goto st714;}
    }
	goto st0;
tr23:
#line 322 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in metadata");
        p--; {goto st713;}
    }
#line 218 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st713;}
    }
#line 246 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st713;}
    }
#line 252 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st713;}
    }
#line 268 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st713;}
    }
#line 234 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in assembly metadata");
        p--; {goto st713;}
    }
#line 240 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in contig metadata");
        p--; {goto st713;}
    }
#line 306 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st713;}
    }
#line 294 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in PEDIGREE metadata");
        p--; {goto st713;}
    }
#line 300 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in pedigreeDB metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	goto st0;
tr34:
#line 322 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	goto st0;
tr141:
#line 322 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in metadata");
        p--; {goto st713;}
    }
#line 218 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	goto st0;
tr145:
#line 218 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	goto st0;
tr150:
#line 223 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "ALT metadata ID does not begin with DEL/INS/DUP/INV/CNV");
        p--; {goto st713;}
    }
#line 218 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	goto st0;
tr156:
#line 223 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "ALT metadata ID does not begin with DEL/INS/DUP/INV/CNV");
        p--; {goto st713;}
    }
#line 228 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "ALT metadata ID suffix (after ':') is not valid");
        p--; {goto st713;}
    }
#line 218 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	goto st0;
tr173:
#line 332 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st713;}
    }
#line 218 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	goto st0;
tr177:
#line 228 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "ALT metadata ID suffix (after ':') is not valid");
        p--; {goto st713;}
    }
#line 218 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	goto st0;
tr194:
#line 322 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in metadata");
        p--; {goto st713;}
    }
#line 246 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st713;}
    }
#line 252 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	goto st0;
tr197:
#line 322 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in metadata");
        p--; {goto st713;}
    }
#line 246 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	goto st0;
tr203:
#line 246 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	goto st0;
tr208:
#line 327 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st713;}
    }
#line 246 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	goto st0;
tr225:
#line 332 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st713;}
    }
#line 246 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	goto st0;
tr229:
#line 322 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in metadata");
        p--; {goto st713;}
    }
#line 252 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	goto st0;
tr235:
#line 252 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	goto st0;
tr240:
#line 327 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st713;}
    }
#line 252 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	goto st0;
tr250:
#line 257 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "FORMAT metadata Number is not a number, A, R, G or dot");
        p--; {goto st713;}
    }
#line 252 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	goto st0;
tr259:
#line 262 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "FORMAT metadata Type is not a Integer, Float, Character or String");
        p--; {goto st713;}
    }
#line 252 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	goto st0;
tr287:
#line 332 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st713;}
    }
#line 252 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	goto st0;
tr301:
#line 322 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in metadata");
        p--; {goto st713;}
    }
#line 268 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	goto st0;
tr306:
#line 268 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	goto st0;
tr311:
#line 327 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st713;}
    }
#line 268 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	goto st0;
tr321:
#line 273 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "INFO metadata Number is not a number, A, R, G or dot");
        p--; {goto st713;}
    }
#line 268 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	goto st0;
tr330:
#line 278 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "INFO metadata Type is not a Integer, Float, Flag, Character or String");
        p--; {goto st713;}
    }
#line 268 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	goto st0;
tr358:
#line 332 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st713;}
    }
#line 268 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	goto st0;
tr360:
#line 332 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st713;}
    }
#line 283 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "INFO metadata Source string is not valid");
        p--; {goto st713;}
    }
#line 288 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "INFO metadata Version string is not valid");
        p--; {goto st713;}
    }
#line 268 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	goto st0;
tr363:
#line 283 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "INFO metadata Source string is not valid");
        p--; {goto st713;}
    }
#line 288 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "INFO metadata Version string is not valid");
        p--; {goto st713;}
    }
#line 268 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	goto st0;
tr366:
#line 283 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "INFO metadata Source string is not valid");
        p--; {goto st713;}
    }
#line 268 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	goto st0;
tr377:
#line 288 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "INFO metadata Version string is not valid");
        p--; {goto st713;}
    }
#line 268 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	goto st0;
tr399:
#line 322 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in metadata");
        p--; {goto st713;}
    }
#line 294 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in PEDIGREE metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	goto st0;
tr408:
#line 294 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in PEDIGREE metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	goto st0;
tr410:
#line 327 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st713;}
    }
#line 294 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in PEDIGREE metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	goto st0;
tr416:
#line 322 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in metadata");
        p--; {goto st713;}
    }
#line 306 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	goto st0;
tr423:
#line 306 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	goto st0;
tr428:
#line 327 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st713;}
    }
#line 306 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	goto st0;
tr430:
#line 327 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st713;}
    }
#line 311 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Genomes contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st713;}
    }
#line 306 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	goto st0;
tr432:
#line 311 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Genomes contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st713;}
    }
#line 306 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	goto st0;
tr442:
#line 311 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Genomes contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st713;}
    }
#line 316 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Mixture contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st713;}
    }
#line 306 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	goto st0;
tr444:
#line 316 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Mixture contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st713;}
    }
#line 306 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	goto st0;
tr454:
#line 316 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Mixture contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st713;}
    }
#line 332 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st713;}
    }
#line 306 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	goto st0;
tr456:
#line 332 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st713;}
    }
#line 306 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	goto st0;
tr473:
#line 322 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in metadata");
        p--; {goto st713;}
    }
#line 234 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in assembly metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	goto st0;
tr482:
#line 337 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata URL is not valid");
        p--; {goto st713;}
    }
#line 234 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in assembly metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	goto st0;
tr489:
#line 322 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in metadata");
        p--; {goto st713;}
    }
#line 240 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in contig metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	goto st0;
tr496:
#line 240 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in contig metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	goto st0;
tr501:
#line 327 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st713;}
    }
#line 240 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in contig metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	goto st0;
tr508:
#line 337 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata URL is not valid");
        p--; {goto st713;}
    }
#line 240 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in contig metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	goto st0;
tr516:
#line 322 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in metadata");
        p--; {goto st713;}
    }
#line 300 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in pedigreeDB metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	goto st0;
tr527:
#line 300 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in pedigreeDB metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	goto st0;
tr529:
#line 337 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata URL is not valid");
        p--; {goto st713;}
    }
#line 300 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in pedigreeDB metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	goto st0;
tr537:
#line 45 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        p--; {goto st714;}
    }
	goto st0;
tr587:
#line 345 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Chromosome is not a string without colons or whitespaces, optionally wrapped with angle brackets (<>)");
        p--; {goto st714;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st714;}
    }
	goto st0;
tr590:
#line 351 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Position is not a positive number");
        p--; {goto st714;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st714;}
    }
	goto st0;
tr594:
#line 357 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "ID is not a single dot or a list of strings without semicolons or whitespaces");
        p--; {goto st714;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st714;}
    }
	goto st0;
tr599:
#line 363 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Reference is not a string of bases");
        p--; {goto st714;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st714;}
    }
	goto st0;
tr603:
#line 369 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Alternate is not a single dot or a comma-separated list of bases");
        p--; {goto st714;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st714;}
    }
	goto st0;
tr612:
#line 375 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Quality is not a single dot or a positive number");
        p--; {goto st714;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st714;}
    }
	goto st0;
tr616:
#line 381 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Filter is not a single dot or a semicolon-separated list of strings");
        p--; {goto st714;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st714;}
    }
	goto st0;
tr623:
#line 387 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st714;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st714;}
    }
	goto st0;
tr644:
#line 492 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Format first field is not GT");
        p--; {goto st714;}
    }
#line 487 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Format is not a colon-separated list of alphanumeric strings");
        p--; {goto st714;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st714;}
    }
	goto st0;
tr649:
#line 505 "vcf_v41.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " does not start with a valid genotype";
        ErrorPolicy::handle_body_section_error(*this, message_stream.str());
        p--; {goto st714;}
    }
#line 498 "vcf_v41.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " is not a valid string";
        ErrorPolicy::handle_body_section_error(*this, message_stream.str());
        p--; {goto st714;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st714;}
    }
	goto st0;
tr658:
#line 498 "vcf_v41.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " is not a valid string";
        ErrorPolicy::handle_body_section_error(*this, message_stream.str());
        p--; {goto st714;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st714;}
    }
	goto st0;
tr660:
#line 487 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Format is not a colon-separated list of alphanumeric strings");
        p--; {goto st714;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st714;}
    }
	goto st0;
tr678:
#line 481 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info 1000G is not a flag (with 1/0/no value)");
        p--; {goto st714;}
    }
#line 387 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st714;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st714;}
    }
	goto st0;
tr686:
#line 396 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info AA value is not a single dot or a string of bases");
        p--; {goto st714;}
    }
#line 387 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st714;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st714;}
    }
	goto st0;
tr690:
#line 401 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info AC value is not a comma-separated list of numbers");
        p--; {goto st714;}
    }
#line 387 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st714;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st714;}
    }
	goto st0;
tr693:
#line 406 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info AF value is not a comma-separated list of numbers");
        p--; {goto st714;}
    }
#line 387 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st714;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st714;}
    }
	goto st0;
tr698:
#line 411 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info AN value is not an integer number");
        p--; {goto st714;}
    }
#line 387 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st714;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st714;}
    }
	goto st0;
tr702:
#line 416 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info BQ value is not a number");
        p--; {goto st714;}
    }
#line 387 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st714;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st714;}
    }
	goto st0;
tr711:
#line 421 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info CIGAR value is not an alphanumeric string");
        p--; {goto st714;}
    }
#line 387 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st714;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st714;}
    }
	goto st0;
tr715:
#line 426 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info DB is not a flag (with 1/0/no value)");
        p--; {goto st714;}
    }
#line 387 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st714;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st714;}
    }
	goto st0;
tr719:
#line 431 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info DP value is not an integer number");
        p--; {goto st714;}
    }
#line 387 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st714;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st714;}
    }
	goto st0;
tr724:
#line 436 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info END value is not an integer number");
        p--; {goto st714;}
    }
#line 387 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st714;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st714;}
    }
	goto st0;
tr728:
#line 441 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info H2 is not a flag (with 1/0/no value)");
        p--; {goto st714;}
    }
#line 387 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st714;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st714;}
    }
	goto st0;
tr731:
#line 446 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info H3 is not a flag (with 1/0/no value)");
        p--; {goto st714;}
    }
#line 387 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st714;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st714;}
    }
	goto st0;
tr738:
#line 456 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info MQ0 value is not an integer number");
        p--; {goto st714;}
    }
#line 387 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st714;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st714;}
    }
	goto st0;
tr740:
#line 451 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info MQ value is not a number");
        p--; {goto st714;}
    }
#line 387 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st714;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st714;}
    }
	goto st0;
tr746:
#line 461 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info NS value is not an integer number");
        p--; {goto st714;}
    }
#line 387 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st714;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st714;}
    }
	goto st0;
tr751:
#line 466 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info SB value is not a number");
        p--; {goto st714;}
    }
#line 387 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st714;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st714;}
    }
	goto st0;
tr760:
#line 471 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info SOMATIC is not a flag (with 1/0/no value)");
        p--; {goto st714;}
    }
#line 387 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st714;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st714;}
    }
	goto st0;
tr771:
#line 476 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info VALIDATED is not a flag (with 1/0/no value)");
        p--; {goto st714;}
    }
#line 387 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st714;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st714;}
    }
	goto st0;
tr842:
#line 45 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        p--; {goto st714;}
    }
#line 345 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Chromosome is not a string without colons or whitespaces, optionally wrapped with angle brackets (<>)");
        p--; {goto st714;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st714;}
    }
	goto st0;
#line 1626 "vcf_validator_detail.hpp"
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
#line 1731 "vcf_validator_detail.hpp"
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
#line 1752 "vcf_validator_detail.hpp"
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
#line 1767 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 35: goto st18;
		case 67: goto st473;
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
#line 1822 "vcf_validator_detail.hpp"
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
tr64:
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
tr176:
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
tr228:
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
tr290:
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
tr388:
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
tr415:
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
#line 1942 "vcf_validator_detail.hpp"
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
#line 1956 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
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
	goto tr34;
tr38:
#line 71 "vcf_v41.ragel"
	{
//        set_vcf_meta_entry_name(ts, p-ts, status->current_meta_entry);
    }
	goto st22;
st22:
	if ( ++p == pe )
		goto _test_eof22;
case 22:
#line 1993 "vcf_validator_detail.hpp"
	if ( (*p) == 60 )
		goto st23;
	if ( (*p) > 59 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st19;
	} else if ( (*p) >= 32 )
		goto st19;
	goto tr34;
st23:
	if ( ++p == pe )
		goto _test_eof23;
case 23:
	switch( (*p) ) {
		case 10: goto tr35;
		case 65: goto tr41;
		case 70: goto tr42;
		case 73: goto tr43;
		case 80: goto tr44;
		case 83: goto tr45;
		case 95: goto tr40;
		case 97: goto tr46;
		case 99: goto tr47;
		case 112: goto tr48;
	}
	if ( (*p) < 62 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 60 )
				goto st19;
		} else
			goto tr40;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 66 <= (*p) && (*p) <= 90 )
				goto tr40;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto st19;
			} else if ( (*p) >= 98 )
				goto tr40;
		} else
			goto st19;
	} else
		goto st19;
	goto tr34;
tr40:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st24;
st24:
	if ( ++p == pe )
		goto _test_eof24;
case 24:
#line 2052 "vcf_validator_detail.hpp"
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
	goto tr34;
st25:
	if ( ++p == pe )
		goto _test_eof25;
case 25:
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st26;
	} else if ( (*p) >= 32 )
		goto st26;
	goto tr34;
st26:
	if ( ++p == pe )
		goto _test_eof26;
case 26:
	switch( (*p) ) {
		case 44: goto tr52;
		case 62: goto tr53;
	}
	if ( (*p) > 60 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto st26;
	} else if ( (*p) >= 32 )
		goto st26;
	goto tr34;
tr52:
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
#line 2119 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto tr52;
		case 62: goto tr53;
		case 65: goto tr55;
		case 70: goto tr56;
		case 73: goto tr57;
		case 80: goto tr58;
		case 83: goto tr59;
		case 95: goto tr54;
		case 97: goto tr60;
		case 99: goto tr61;
		case 112: goto tr62;
	}
	if ( (*p) < 63 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st26;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 60 )
				goto st26;
		} else
			goto tr54;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 66 <= (*p) && (*p) <= 90 )
				goto tr54;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto st26;
			} else if ( (*p) >= 98 )
				goto tr54;
		} else
			goto st26;
	} else
		goto st26;
	goto tr34;
tr54:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st28;
st28:
	if ( ++p == pe )
		goto _test_eof28;
case 28:
#line 2167 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto tr52;
		case 61: goto st25;
		case 62: goto tr53;
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
	goto tr34;
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
	goto st29;
st29:
	if ( ++p == pe )
		goto _test_eof29;
case 29:
#line 2211 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr64;
		case 44: goto tr52;
		case 62: goto tr53;
	}
	if ( (*p) > 60 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto st26;
	} else if ( (*p) >= 32 )
		goto st26;
	goto tr34;
tr55:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st30;
st30:
	if ( ++p == pe )
		goto _test_eof30;
case 30:
#line 2233 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto tr52;
		case 61: goto st25;
		case 62: goto tr53;
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
	goto tr34;
st31:
	if ( ++p == pe )
		goto _test_eof31;
case 31:
	switch( (*p) ) {
		case 44: goto tr52;
		case 61: goto st25;
		case 62: goto tr53;
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
	goto tr34;
st32:
	if ( ++p == pe )
		goto _test_eof32;
case 32:
	switch( (*p) ) {
		case 44: goto tr52;
		case 62: goto tr53;
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
	goto tr34;
tr56:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st33;
st33:
	if ( ++p == pe )
		goto _test_eof33;
case 33:
#line 2337 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto tr52;
		case 61: goto st25;
		case 62: goto tr53;
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
	goto tr34;
st34:
	if ( ++p == pe )
		goto _test_eof34;
case 34:
	switch( (*p) ) {
		case 44: goto tr52;
		case 61: goto st25;
		case 62: goto tr53;
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
	goto tr34;
st35:
	if ( ++p == pe )
		goto _test_eof35;
case 35:
	switch( (*p) ) {
		case 44: goto tr52;
		case 61: goto st25;
		case 62: goto tr53;
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
	goto tr34;
st36:
	if ( ++p == pe )
		goto _test_eof36;
case 36:
	switch( (*p) ) {
		case 44: goto tr52;
		case 61: goto st25;
		case 62: goto tr53;
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
	goto tr34;
st37:
	if ( ++p == pe )
		goto _test_eof37;
case 37:
	switch( (*p) ) {
		case 44: goto tr52;
		case 61: goto st25;
		case 62: goto tr53;
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
	goto tr34;
st38:
	if ( ++p == pe )
		goto _test_eof38;
case 38:
	switch( (*p) ) {
		case 44: goto tr52;
		case 61: goto st25;
		case 62: goto tr53;
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
	goto tr34;
st39:
	if ( ++p == pe )
		goto _test_eof39;
case 39:
	switch( (*p) ) {
		case 44: goto tr52;
		case 61: goto st25;
		case 62: goto tr53;
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
	goto tr34;
st40:
	if ( ++p == pe )
		goto _test_eof40;
case 40:
	switch( (*p) ) {
		case 44: goto tr52;
		case 61: goto st25;
		case 62: goto tr53;
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
	goto tr34;
tr57:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st41;
st41:
	if ( ++p == pe )
		goto _test_eof41;
case 41:
#line 2601 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto tr52;
		case 61: goto st25;
		case 62: goto tr53;
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
	goto tr34;
st42:
	if ( ++p == pe )
		goto _test_eof42;
case 42:
	switch( (*p) ) {
		case 44: goto tr52;
		case 61: goto st25;
		case 62: goto tr53;
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
	goto tr34;
st43:
	if ( ++p == pe )
		goto _test_eof43;
case 43:
	switch( (*p) ) {
		case 44: goto tr52;
		case 61: goto st25;
		case 62: goto tr53;
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
	goto tr34;
tr58:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st44;
st44:
	if ( ++p == pe )
		goto _test_eof44;
case 44:
#line 2704 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto tr52;
		case 61: goto st25;
		case 62: goto tr53;
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
	goto tr34;
st45:
	if ( ++p == pe )
		goto _test_eof45;
case 45:
	switch( (*p) ) {
		case 44: goto tr52;
		case 61: goto st25;
		case 62: goto tr53;
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
	goto tr34;
st46:
	if ( ++p == pe )
		goto _test_eof46;
case 46:
	switch( (*p) ) {
		case 44: goto tr52;
		case 61: goto st25;
		case 62: goto tr53;
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
	goto tr34;
st47:
	if ( ++p == pe )
		goto _test_eof47;
case 47:
	switch( (*p) ) {
		case 44: goto tr52;
		case 61: goto st25;
		case 62: goto tr53;
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
	goto tr34;
st48:
	if ( ++p == pe )
		goto _test_eof48;
case 48:
	switch( (*p) ) {
		case 44: goto tr52;
		case 61: goto st25;
		case 62: goto tr53;
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
	goto tr34;
st49:
	if ( ++p == pe )
		goto _test_eof49;
case 49:
	switch( (*p) ) {
		case 44: goto tr52;
		case 61: goto st25;
		case 62: goto tr53;
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
	goto tr34;
st50:
	if ( ++p == pe )
		goto _test_eof50;
case 50:
	switch( (*p) ) {
		case 44: goto tr52;
		case 61: goto st25;
		case 62: goto tr53;
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
	goto tr34;
tr59:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st51;
st51:
	if ( ++p == pe )
		goto _test_eof51;
case 51:
#line 2935 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto tr52;
		case 61: goto st25;
		case 62: goto tr53;
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
	goto tr34;
st52:
	if ( ++p == pe )
		goto _test_eof52;
case 52:
	switch( (*p) ) {
		case 44: goto tr52;
		case 61: goto st25;
		case 62: goto tr53;
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
	goto tr34;
st53:
	if ( ++p == pe )
		goto _test_eof53;
case 53:
	switch( (*p) ) {
		case 44: goto tr52;
		case 61: goto st25;
		case 62: goto tr53;
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
	goto tr34;
st54:
	if ( ++p == pe )
		goto _test_eof54;
case 54:
	switch( (*p) ) {
		case 44: goto tr52;
		case 61: goto st25;
		case 62: goto tr53;
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
	goto tr34;
tr60:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st55;
st55:
	if ( ++p == pe )
		goto _test_eof55;
case 55:
#line 3070 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto tr52;
		case 61: goto st25;
		case 62: goto tr53;
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
	goto tr34;
st56:
	if ( ++p == pe )
		goto _test_eof56;
case 56:
	switch( (*p) ) {
		case 44: goto tr52;
		case 61: goto st25;
		case 62: goto tr53;
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
	goto tr34;
st57:
	if ( ++p == pe )
		goto _test_eof57;
case 57:
	switch( (*p) ) {
		case 44: goto tr52;
		case 61: goto st25;
		case 62: goto tr53;
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
	goto tr34;
st58:
	if ( ++p == pe )
		goto _test_eof58;
case 58:
	switch( (*p) ) {
		case 44: goto tr52;
		case 61: goto st25;
		case 62: goto tr53;
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
	goto tr34;
st59:
	if ( ++p == pe )
		goto _test_eof59;
case 59:
	switch( (*p) ) {
		case 44: goto tr52;
		case 61: goto st25;
		case 62: goto tr53;
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
	goto tr34;
st60:
	if ( ++p == pe )
		goto _test_eof60;
case 60:
	switch( (*p) ) {
		case 44: goto tr52;
		case 61: goto st25;
		case 62: goto tr53;
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
	goto tr34;
st61:
	if ( ++p == pe )
		goto _test_eof61;
case 61:
	switch( (*p) ) {
		case 44: goto tr52;
		case 61: goto st25;
		case 62: goto tr53;
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
	goto tr34;
tr61:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st62;
st62:
	if ( ++p == pe )
		goto _test_eof62;
case 62:
#line 3301 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto tr52;
		case 61: goto st25;
		case 62: goto tr53;
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
	goto tr34;
st63:
	if ( ++p == pe )
		goto _test_eof63;
case 63:
	switch( (*p) ) {
		case 44: goto tr52;
		case 61: goto st25;
		case 62: goto tr53;
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
	goto tr34;
st64:
	if ( ++p == pe )
		goto _test_eof64;
case 64:
	switch( (*p) ) {
		case 44: goto tr52;
		case 61: goto st25;
		case 62: goto tr53;
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
	goto tr34;
st65:
	if ( ++p == pe )
		goto _test_eof65;
case 65:
	switch( (*p) ) {
		case 44: goto tr52;
		case 61: goto st25;
		case 62: goto tr53;
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
	goto tr34;
st66:
	if ( ++p == pe )
		goto _test_eof66;
case 66:
	switch( (*p) ) {
		case 44: goto tr52;
		case 61: goto st25;
		case 62: goto tr53;
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
	goto tr34;
tr62:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st67;
st67:
	if ( ++p == pe )
		goto _test_eof67;
case 67:
#line 3468 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto tr52;
		case 61: goto st25;
		case 62: goto tr53;
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
	goto tr34;
st68:
	if ( ++p == pe )
		goto _test_eof68;
case 68:
	switch( (*p) ) {
		case 44: goto tr52;
		case 61: goto st25;
		case 62: goto tr53;
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
	goto tr34;
st69:
	if ( ++p == pe )
		goto _test_eof69;
case 69:
	switch( (*p) ) {
		case 44: goto tr52;
		case 61: goto st25;
		case 62: goto tr53;
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
	goto tr34;
st70:
	if ( ++p == pe )
		goto _test_eof70;
case 70:
	switch( (*p) ) {
		case 44: goto tr52;
		case 61: goto st25;
		case 62: goto tr53;
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
	goto tr34;
st71:
	if ( ++p == pe )
		goto _test_eof71;
case 71:
	switch( (*p) ) {
		case 44: goto tr52;
		case 61: goto st25;
		case 62: goto tr53;
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
	goto tr34;
st72:
	if ( ++p == pe )
		goto _test_eof72;
case 72:
	switch( (*p) ) {
		case 44: goto tr52;
		case 61: goto st25;
		case 62: goto tr53;
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
	goto tr34;
st73:
	if ( ++p == pe )
		goto _test_eof73;
case 73:
	switch( (*p) ) {
		case 44: goto tr52;
		case 61: goto st25;
		case 62: goto tr53;
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
	goto tr34;
st74:
	if ( ++p == pe )
		goto _test_eof74;
case 74:
	switch( (*p) ) {
		case 44: goto tr52;
		case 61: goto st25;
		case 62: goto tr53;
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
	goto tr34;
st75:
	if ( ++p == pe )
		goto _test_eof75;
case 75:
	switch( (*p) ) {
		case 44: goto tr52;
		case 61: goto st25;
		case 62: goto tr53;
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
	goto tr34;
tr41:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st76;
st76:
	if ( ++p == pe )
		goto _test_eof76;
case 76:
#line 3763 "vcf_validator_detail.hpp"
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
	goto tr34;
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
	goto tr34;
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
	goto tr34;
tr42:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st79;
st79:
	if ( ++p == pe )
		goto _test_eof79;
case 79:
#line 3864 "vcf_validator_detail.hpp"
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
	goto tr34;
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
	goto tr34;
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
	goto tr34;
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
	goto tr34;
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
	goto tr34;
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
	goto tr34;
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
	goto tr34;
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
	goto tr34;
tr43:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st87;
st87:
	if ( ++p == pe )
		goto _test_eof87;
case 87:
#line 4120 "vcf_validator_detail.hpp"
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
	goto tr34;
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
	goto tr34;
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
	goto tr34;
tr44:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st90;
st90:
	if ( ++p == pe )
		goto _test_eof90;
case 90:
#line 4220 "vcf_validator_detail.hpp"
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
	goto tr34;
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
	goto tr34;
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
	goto tr34;
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
	goto tr34;
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
	goto tr34;
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
	goto tr34;
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
	goto tr34;
tr45:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st97;
st97:
	if ( ++p == pe )
		goto _test_eof97;
case 97:
#line 4444 "vcf_validator_detail.hpp"
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
	goto tr34;
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
	goto tr34;
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
	goto tr34;
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
	goto tr34;
tr46:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st101;
st101:
	if ( ++p == pe )
		goto _test_eof101;
case 101:
#line 4575 "vcf_validator_detail.hpp"
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
	goto tr34;
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
	goto tr34;
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
	goto tr34;
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
	goto tr34;
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
	goto tr34;
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
	goto tr34;
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
	goto tr34;
tr47:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st108;
st108:
	if ( ++p == pe )
		goto _test_eof108;
case 108:
#line 4799 "vcf_validator_detail.hpp"
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
	goto tr34;
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
	goto tr34;
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
	goto tr34;
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
	goto tr34;
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
	goto tr34;
tr48:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st113;
st113:
	if ( ++p == pe )
		goto _test_eof113;
case 113:
#line 4961 "vcf_validator_detail.hpp"
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
	goto tr34;
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
	goto tr34;
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
	goto tr34;
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
	goto tr34;
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
	goto tr34;
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
	goto tr34;
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
	goto tr34;
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
	goto tr34;
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
	goto tr34;
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
#line 5247 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
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
	goto tr141;
st123:
	if ( ++p == pe )
		goto _test_eof123;
case 123:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
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
	goto tr141;
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
	goto tr141;
st125:
	if ( ++p == pe )
		goto _test_eof125;
case 125:
	if ( (*p) == 60 )
		goto st126;
	goto tr145;
st126:
	if ( ++p == pe )
		goto _test_eof126;
case 126:
	if ( (*p) == 73 )
		goto st127;
	goto tr145;
st127:
	if ( ++p == pe )
		goto _test_eof127;
case 127:
	if ( (*p) == 68 )
		goto st128;
	goto tr145;
st128:
	if ( ++p == pe )
		goto _test_eof128;
case 128:
	if ( (*p) == 61 )
		goto st129;
	goto tr145;
st129:
	if ( ++p == pe )
		goto _test_eof129;
case 129:
	switch( (*p) ) {
		case 67: goto st130;
		case 68: goto st164;
		case 73: goto st167;
	}
	goto tr150;
st130:
	if ( ++p == pe )
		goto _test_eof130;
case 130:
	if ( (*p) == 78 )
		goto st131;
	goto tr150;
st131:
	if ( ++p == pe )
		goto _test_eof131;
case 131:
	if ( (*p) == 86 )
		goto st132;
	goto tr150;
st132:
	if ( ++p == pe )
		goto _test_eof132;
case 132:
	switch( (*p) ) {
		case 44: goto st133;
		case 58: goto st150;
	}
	goto tr156;
st133:
	if ( ++p == pe )
		goto _test_eof133;
case 133:
	if ( (*p) == 68 )
		goto st134;
	goto tr145;
st134:
	if ( ++p == pe )
		goto _test_eof134;
case 134:
	if ( (*p) == 101 )
		goto st135;
	goto tr145;
st135:
	if ( ++p == pe )
		goto _test_eof135;
case 135:
	if ( (*p) == 115 )
		goto st136;
	goto tr145;
st136:
	if ( ++p == pe )
		goto _test_eof136;
case 136:
	if ( (*p) == 99 )
		goto st137;
	goto tr145;
st137:
	if ( ++p == pe )
		goto _test_eof137;
case 137:
	if ( (*p) == 114 )
		goto st138;
	goto tr145;
st138:
	if ( ++p == pe )
		goto _test_eof138;
case 138:
	if ( (*p) == 105 )
		goto st139;
	goto tr145;
st139:
	if ( ++p == pe )
		goto _test_eof139;
case 139:
	if ( (*p) == 112 )
		goto st140;
	goto tr145;
st140:
	if ( ++p == pe )
		goto _test_eof140;
case 140:
	if ( (*p) == 116 )
		goto st141;
	goto tr145;
st141:
	if ( ++p == pe )
		goto _test_eof141;
case 141:
	if ( (*p) == 105 )
		goto st142;
	goto tr145;
st142:
	if ( ++p == pe )
		goto _test_eof142;
case 142:
	if ( (*p) == 111 )
		goto st143;
	goto tr145;
st143:
	if ( ++p == pe )
		goto _test_eof143;
case 143:
	if ( (*p) == 110 )
		goto st144;
	goto tr145;
st144:
	if ( ++p == pe )
		goto _test_eof144;
case 144:
	if ( (*p) == 61 )
		goto st145;
	goto tr145;
st145:
	if ( ++p == pe )
		goto _test_eof145;
case 145:
	if ( (*p) == 34 )
		goto st146;
	goto tr145;
st146:
	if ( ++p == pe )
		goto _test_eof146;
case 146:
	if ( (*p) > 33 ) {
		if ( 35 <= (*p) && (*p) <= 126 )
			goto st147;
	} else if ( (*p) >= 32 )
		goto st147;
	goto tr145;
st147:
	if ( ++p == pe )
		goto _test_eof147;
case 147:
	if ( (*p) == 34 )
		goto st148;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto st147;
	goto tr173;
st148:
	if ( ++p == pe )
		goto _test_eof148;
case 148:
	if ( (*p) == 62 )
		goto st149;
	goto tr173;
st149:
	if ( ++p == pe )
		goto _test_eof149;
case 149:
	if ( (*p) == 10 )
		goto tr176;
	goto tr145;
st150:
	if ( ++p == pe )
		goto _test_eof150;
case 150:
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st151;
	} else if ( (*p) >= 32 )
		goto st151;
	goto tr177;
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
	goto tr177;
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
	goto tr177;
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
	goto tr177;
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
	goto tr177;
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
	goto tr177;
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
	goto tr177;
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
	goto tr177;
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
	goto tr177;
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
	goto tr177;
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
	goto tr177;
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
	goto tr177;
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
	goto tr177;
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
	goto tr177;
st164:
	if ( ++p == pe )
		goto _test_eof164;
case 164:
	switch( (*p) ) {
		case 69: goto st165;
		case 85: goto st166;
	}
	goto tr150;
st165:
	if ( ++p == pe )
		goto _test_eof165;
case 165:
	if ( (*p) == 76 )
		goto st132;
	goto tr150;
st166:
	if ( ++p == pe )
		goto _test_eof166;
case 166:
	if ( (*p) == 80 )
		goto st132;
	goto tr150;
st167:
	if ( ++p == pe )
		goto _test_eof167;
case 167:
	if ( (*p) == 78 )
		goto st168;
	goto tr150;
st168:
	if ( ++p == pe )
		goto _test_eof168;
case 168:
	switch( (*p) ) {
		case 83: goto st132;
		case 86: goto st132;
	}
	goto tr150;
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
#line 5757 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 73: goto st170;
		case 79: goto st198;
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
	goto tr194;
st170:
	if ( ++p == pe )
		goto _test_eof170;
case 170:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
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
	goto tr197;
st171:
	if ( ++p == pe )
		goto _test_eof171;
case 171:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
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
	goto tr197;
st172:
	if ( ++p == pe )
		goto _test_eof172;
case 172:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
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
	goto tr197;
st173:
	if ( ++p == pe )
		goto _test_eof173;
case 173:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
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
	goto tr197;
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
	goto tr197;
st175:
	if ( ++p == pe )
		goto _test_eof175;
case 175:
	if ( (*p) == 60 )
		goto st176;
	goto tr203;
st176:
	if ( ++p == pe )
		goto _test_eof176;
case 176:
	if ( (*p) == 73 )
		goto st177;
	goto tr203;
st177:
	if ( ++p == pe )
		goto _test_eof177;
case 177:
	if ( (*p) == 68 )
		goto st178;
	goto tr203;
st178:
	if ( ++p == pe )
		goto _test_eof178;
case 178:
	if ( (*p) == 61 )
		goto st179;
	goto tr203;
st179:
	if ( ++p == pe )
		goto _test_eof179;
case 179:
	if ( (*p) == 95 )
		goto st179;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st179;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st180;
		} else if ( (*p) >= 65 )
			goto st180;
	} else
		goto st180;
	goto tr208;
st180:
	if ( ++p == pe )
		goto _test_eof180;
case 180:
	switch( (*p) ) {
		case 44: goto st181;
		case 95: goto st180;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st180;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st180;
		} else if ( (*p) >= 65 )
			goto st180;
	} else
		goto st180;
	goto tr208;
st181:
	if ( ++p == pe )
		goto _test_eof181;
case 181:
	if ( (*p) == 68 )
		goto st182;
	goto tr203;
st182:
	if ( ++p == pe )
		goto _test_eof182;
case 182:
	if ( (*p) == 101 )
		goto st183;
	goto tr203;
st183:
	if ( ++p == pe )
		goto _test_eof183;
case 183:
	if ( (*p) == 115 )
		goto st184;
	goto tr203;
st184:
	if ( ++p == pe )
		goto _test_eof184;
case 184:
	if ( (*p) == 99 )
		goto st185;
	goto tr203;
st185:
	if ( ++p == pe )
		goto _test_eof185;
case 185:
	if ( (*p) == 114 )
		goto st186;
	goto tr203;
st186:
	if ( ++p == pe )
		goto _test_eof186;
case 186:
	if ( (*p) == 105 )
		goto st187;
	goto tr203;
st187:
	if ( ++p == pe )
		goto _test_eof187;
case 187:
	if ( (*p) == 112 )
		goto st188;
	goto tr203;
st188:
	if ( ++p == pe )
		goto _test_eof188;
case 188:
	if ( (*p) == 116 )
		goto st189;
	goto tr203;
st189:
	if ( ++p == pe )
		goto _test_eof189;
case 189:
	if ( (*p) == 105 )
		goto st190;
	goto tr203;
st190:
	if ( ++p == pe )
		goto _test_eof190;
case 190:
	if ( (*p) == 111 )
		goto st191;
	goto tr203;
st191:
	if ( ++p == pe )
		goto _test_eof191;
case 191:
	if ( (*p) == 110 )
		goto st192;
	goto tr203;
st192:
	if ( ++p == pe )
		goto _test_eof192;
case 192:
	if ( (*p) == 61 )
		goto st193;
	goto tr203;
st193:
	if ( ++p == pe )
		goto _test_eof193;
case 193:
	if ( (*p) == 34 )
		goto st194;
	goto tr203;
st194:
	if ( ++p == pe )
		goto _test_eof194;
case 194:
	if ( (*p) > 33 ) {
		if ( 35 <= (*p) && (*p) <= 126 )
			goto st195;
	} else if ( (*p) >= 32 )
		goto st195;
	goto tr203;
st195:
	if ( ++p == pe )
		goto _test_eof195;
case 195:
	if ( (*p) == 34 )
		goto st196;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto st195;
	goto tr225;
st196:
	if ( ++p == pe )
		goto _test_eof196;
case 196:
	if ( (*p) == 62 )
		goto st197;
	goto tr225;
st197:
	if ( ++p == pe )
		goto _test_eof197;
case 197:
	if ( (*p) == 10 )
		goto tr228;
	goto tr203;
st198:
	if ( ++p == pe )
		goto _test_eof198;
case 198:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 82: goto st199;
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
	goto tr229;
st199:
	if ( ++p == pe )
		goto _test_eof199;
case 199:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 77: goto st200;
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
	goto tr229;
st200:
	if ( ++p == pe )
		goto _test_eof200;
case 200:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 65: goto st201;
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
	goto tr229;
st201:
	if ( ++p == pe )
		goto _test_eof201;
case 201:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 84: goto st202;
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
	goto tr229;
st202:
	if ( ++p == pe )
		goto _test_eof202;
case 202:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto st203;
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
	goto tr229;
st203:
	if ( ++p == pe )
		goto _test_eof203;
case 203:
	if ( (*p) == 60 )
		goto st204;
	goto tr235;
st204:
	if ( ++p == pe )
		goto _test_eof204;
case 204:
	if ( (*p) == 73 )
		goto st205;
	goto tr235;
st205:
	if ( ++p == pe )
		goto _test_eof205;
case 205:
	if ( (*p) == 68 )
		goto st206;
	goto tr235;
st206:
	if ( ++p == pe )
		goto _test_eof206;
case 206:
	if ( (*p) == 61 )
		goto st207;
	goto tr235;
st207:
	if ( ++p == pe )
		goto _test_eof207;
case 207:
	if ( (*p) == 95 )
		goto st207;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st207;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st208;
		} else if ( (*p) >= 65 )
			goto st208;
	} else
		goto st208;
	goto tr240;
st208:
	if ( ++p == pe )
		goto _test_eof208;
case 208:
	switch( (*p) ) {
		case 44: goto st209;
		case 95: goto st208;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st208;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st208;
		} else if ( (*p) >= 65 )
			goto st208;
	} else
		goto st208;
	goto tr240;
st209:
	if ( ++p == pe )
		goto _test_eof209;
case 209:
	if ( (*p) == 78 )
		goto st210;
	goto tr235;
st210:
	if ( ++p == pe )
		goto _test_eof210;
case 210:
	if ( (*p) == 117 )
		goto st211;
	goto tr235;
st211:
	if ( ++p == pe )
		goto _test_eof211;
case 211:
	if ( (*p) == 109 )
		goto st212;
	goto tr235;
st212:
	if ( ++p == pe )
		goto _test_eof212;
case 212:
	if ( (*p) == 98 )
		goto st213;
	goto tr235;
st213:
	if ( ++p == pe )
		goto _test_eof213;
case 213:
	if ( (*p) == 101 )
		goto st214;
	goto tr235;
st214:
	if ( ++p == pe )
		goto _test_eof214;
case 214:
	if ( (*p) == 114 )
		goto st215;
	goto tr235;
st215:
	if ( ++p == pe )
		goto _test_eof215;
case 215:
	if ( (*p) == 61 )
		goto st216;
	goto tr235;
st216:
	if ( ++p == pe )
		goto _test_eof216;
case 216:
	switch( (*p) ) {
		case 46: goto st217;
		case 65: goto st217;
		case 71: goto st217;
		case 82: goto st217;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st263;
	goto tr250;
st217:
	if ( ++p == pe )
		goto _test_eof217;
case 217:
	if ( (*p) == 44 )
		goto st218;
	goto tr250;
st218:
	if ( ++p == pe )
		goto _test_eof218;
case 218:
	if ( (*p) == 84 )
		goto st219;
	goto tr235;
st219:
	if ( ++p == pe )
		goto _test_eof219;
case 219:
	if ( (*p) == 121 )
		goto st220;
	goto tr235;
st220:
	if ( ++p == pe )
		goto _test_eof220;
case 220:
	if ( (*p) == 112 )
		goto st221;
	goto tr235;
st221:
	if ( ++p == pe )
		goto _test_eof221;
case 221:
	if ( (*p) == 101 )
		goto st222;
	goto tr235;
st222:
	if ( ++p == pe )
		goto _test_eof222;
case 222:
	if ( (*p) == 61 )
		goto st223;
	goto tr235;
st223:
	if ( ++p == pe )
		goto _test_eof223;
case 223:
	switch( (*p) ) {
		case 67: goto st224;
		case 70: goto st250;
		case 73: goto st254;
		case 83: goto st258;
	}
	goto tr259;
st224:
	if ( ++p == pe )
		goto _test_eof224;
case 224:
	if ( (*p) == 104 )
		goto st225;
	goto tr259;
st225:
	if ( ++p == pe )
		goto _test_eof225;
case 225:
	if ( (*p) == 97 )
		goto st226;
	goto tr259;
st226:
	if ( ++p == pe )
		goto _test_eof226;
case 226:
	if ( (*p) == 114 )
		goto st227;
	goto tr259;
st227:
	if ( ++p == pe )
		goto _test_eof227;
case 227:
	if ( (*p) == 97 )
		goto st228;
	goto tr259;
st228:
	if ( ++p == pe )
		goto _test_eof228;
case 228:
	if ( (*p) == 99 )
		goto st229;
	goto tr259;
st229:
	if ( ++p == pe )
		goto _test_eof229;
case 229:
	if ( (*p) == 116 )
		goto st230;
	goto tr259;
st230:
	if ( ++p == pe )
		goto _test_eof230;
case 230:
	if ( (*p) == 101 )
		goto st231;
	goto tr259;
st231:
	if ( ++p == pe )
		goto _test_eof231;
case 231:
	if ( (*p) == 114 )
		goto st232;
	goto tr259;
st232:
	if ( ++p == pe )
		goto _test_eof232;
case 232:
	if ( (*p) == 44 )
		goto st233;
	goto tr259;
st233:
	if ( ++p == pe )
		goto _test_eof233;
case 233:
	if ( (*p) == 68 )
		goto st234;
	goto tr235;
st234:
	if ( ++p == pe )
		goto _test_eof234;
case 234:
	if ( (*p) == 101 )
		goto st235;
	goto tr235;
st235:
	if ( ++p == pe )
		goto _test_eof235;
case 235:
	if ( (*p) == 115 )
		goto st236;
	goto tr235;
st236:
	if ( ++p == pe )
		goto _test_eof236;
case 236:
	if ( (*p) == 99 )
		goto st237;
	goto tr235;
st237:
	if ( ++p == pe )
		goto _test_eof237;
case 237:
	if ( (*p) == 114 )
		goto st238;
	goto tr235;
st238:
	if ( ++p == pe )
		goto _test_eof238;
case 238:
	if ( (*p) == 105 )
		goto st239;
	goto tr235;
st239:
	if ( ++p == pe )
		goto _test_eof239;
case 239:
	if ( (*p) == 112 )
		goto st240;
	goto tr235;
st240:
	if ( ++p == pe )
		goto _test_eof240;
case 240:
	if ( (*p) == 116 )
		goto st241;
	goto tr235;
st241:
	if ( ++p == pe )
		goto _test_eof241;
case 241:
	if ( (*p) == 105 )
		goto st242;
	goto tr235;
st242:
	if ( ++p == pe )
		goto _test_eof242;
case 242:
	if ( (*p) == 111 )
		goto st243;
	goto tr235;
st243:
	if ( ++p == pe )
		goto _test_eof243;
case 243:
	if ( (*p) == 110 )
		goto st244;
	goto tr235;
st244:
	if ( ++p == pe )
		goto _test_eof244;
case 244:
	if ( (*p) == 61 )
		goto st245;
	goto tr235;
st245:
	if ( ++p == pe )
		goto _test_eof245;
case 245:
	if ( (*p) == 34 )
		goto st246;
	goto tr235;
st246:
	if ( ++p == pe )
		goto _test_eof246;
case 246:
	if ( (*p) > 33 ) {
		if ( 35 <= (*p) && (*p) <= 126 )
			goto st247;
	} else if ( (*p) >= 32 )
		goto st247;
	goto tr235;
st247:
	if ( ++p == pe )
		goto _test_eof247;
case 247:
	if ( (*p) == 34 )
		goto st248;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto st247;
	goto tr287;
st248:
	if ( ++p == pe )
		goto _test_eof248;
case 248:
	if ( (*p) == 62 )
		goto st249;
	goto tr287;
st249:
	if ( ++p == pe )
		goto _test_eof249;
case 249:
	if ( (*p) == 10 )
		goto tr290;
	goto tr235;
st250:
	if ( ++p == pe )
		goto _test_eof250;
case 250:
	if ( (*p) == 108 )
		goto st251;
	goto tr259;
st251:
	if ( ++p == pe )
		goto _test_eof251;
case 251:
	if ( (*p) == 111 )
		goto st252;
	goto tr259;
st252:
	if ( ++p == pe )
		goto _test_eof252;
case 252:
	if ( (*p) == 97 )
		goto st253;
	goto tr259;
st253:
	if ( ++p == pe )
		goto _test_eof253;
case 253:
	if ( (*p) == 116 )
		goto st232;
	goto tr259;
st254:
	if ( ++p == pe )
		goto _test_eof254;
case 254:
	if ( (*p) == 110 )
		goto st255;
	goto tr259;
st255:
	if ( ++p == pe )
		goto _test_eof255;
case 255:
	if ( (*p) == 116 )
		goto st256;
	goto tr259;
st256:
	if ( ++p == pe )
		goto _test_eof256;
case 256:
	if ( (*p) == 101 )
		goto st257;
	goto tr259;
st257:
	if ( ++p == pe )
		goto _test_eof257;
case 257:
	if ( (*p) == 103 )
		goto st230;
	goto tr259;
st258:
	if ( ++p == pe )
		goto _test_eof258;
case 258:
	if ( (*p) == 116 )
		goto st259;
	goto tr259;
st259:
	if ( ++p == pe )
		goto _test_eof259;
case 259:
	if ( (*p) == 114 )
		goto st260;
	goto tr259;
st260:
	if ( ++p == pe )
		goto _test_eof260;
case 260:
	if ( (*p) == 105 )
		goto st261;
	goto tr259;
st261:
	if ( ++p == pe )
		goto _test_eof261;
case 261:
	if ( (*p) == 110 )
		goto st262;
	goto tr259;
st262:
	if ( ++p == pe )
		goto _test_eof262;
case 262:
	if ( (*p) == 103 )
		goto st232;
	goto tr259;
st263:
	if ( ++p == pe )
		goto _test_eof263;
case 263:
	if ( (*p) == 44 )
		goto st218;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st263;
	goto tr250;
tr28:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st264;
st264:
	if ( ++p == pe )
		goto _test_eof264;
case 264:
#line 6762 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 78: goto st265;
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
	goto tr301;
st265:
	if ( ++p == pe )
		goto _test_eof265;
case 265:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 70: goto st266;
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
	goto tr301;
st266:
	if ( ++p == pe )
		goto _test_eof266;
case 266:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 79: goto st267;
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
	goto tr301;
st267:
	if ( ++p == pe )
		goto _test_eof267;
case 267:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto st268;
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
	goto tr301;
st268:
	if ( ++p == pe )
		goto _test_eof268;
case 268:
	if ( (*p) == 60 )
		goto st269;
	goto tr306;
st269:
	if ( ++p == pe )
		goto _test_eof269;
case 269:
	if ( (*p) == 73 )
		goto st270;
	goto tr306;
st270:
	if ( ++p == pe )
		goto _test_eof270;
case 270:
	if ( (*p) == 68 )
		goto st271;
	goto tr306;
st271:
	if ( ++p == pe )
		goto _test_eof271;
case 271:
	if ( (*p) == 61 )
		goto st272;
	goto tr306;
st272:
	if ( ++p == pe )
		goto _test_eof272;
case 272:
	if ( (*p) == 95 )
		goto st272;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st272;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st273;
		} else if ( (*p) >= 65 )
			goto st273;
	} else
		goto st273;
	goto tr311;
st273:
	if ( ++p == pe )
		goto _test_eof273;
case 273:
	switch( (*p) ) {
		case 44: goto st274;
		case 95: goto st273;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st273;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st273;
		} else if ( (*p) >= 65 )
			goto st273;
	} else
		goto st273;
	goto tr311;
st274:
	if ( ++p == pe )
		goto _test_eof274;
case 274:
	if ( (*p) == 78 )
		goto st275;
	goto tr306;
st275:
	if ( ++p == pe )
		goto _test_eof275;
case 275:
	if ( (*p) == 117 )
		goto st276;
	goto tr306;
st276:
	if ( ++p == pe )
		goto _test_eof276;
case 276:
	if ( (*p) == 109 )
		goto st277;
	goto tr306;
st277:
	if ( ++p == pe )
		goto _test_eof277;
case 277:
	if ( (*p) == 98 )
		goto st278;
	goto tr306;
st278:
	if ( ++p == pe )
		goto _test_eof278;
case 278:
	if ( (*p) == 101 )
		goto st279;
	goto tr306;
st279:
	if ( ++p == pe )
		goto _test_eof279;
case 279:
	if ( (*p) == 114 )
		goto st280;
	goto tr306;
st280:
	if ( ++p == pe )
		goto _test_eof280;
case 280:
	if ( (*p) == 61 )
		goto st281;
	goto tr306;
st281:
	if ( ++p == pe )
		goto _test_eof281;
case 281:
	switch( (*p) ) {
		case 46: goto st282;
		case 65: goto st282;
		case 71: goto st282;
		case 82: goto st282;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st351;
	goto tr321;
st282:
	if ( ++p == pe )
		goto _test_eof282;
case 282:
	if ( (*p) == 44 )
		goto st283;
	goto tr321;
st283:
	if ( ++p == pe )
		goto _test_eof283;
case 283:
	if ( (*p) == 84 )
		goto st284;
	goto tr306;
st284:
	if ( ++p == pe )
		goto _test_eof284;
case 284:
	if ( (*p) == 121 )
		goto st285;
	goto tr306;
st285:
	if ( ++p == pe )
		goto _test_eof285;
case 285:
	if ( (*p) == 112 )
		goto st286;
	goto tr306;
st286:
	if ( ++p == pe )
		goto _test_eof286;
case 286:
	if ( (*p) == 101 )
		goto st287;
	goto tr306;
st287:
	if ( ++p == pe )
		goto _test_eof287;
case 287:
	if ( (*p) == 61 )
		goto st288;
	goto tr306;
st288:
	if ( ++p == pe )
		goto _test_eof288;
case 288:
	switch( (*p) ) {
		case 67: goto st289;
		case 70: goto st338;
		case 73: goto st343;
		case 83: goto st347;
	}
	goto tr330;
st289:
	if ( ++p == pe )
		goto _test_eof289;
case 289:
	if ( (*p) == 104 )
		goto st290;
	goto tr330;
st290:
	if ( ++p == pe )
		goto _test_eof290;
case 290:
	if ( (*p) == 97 )
		goto st291;
	goto tr330;
st291:
	if ( ++p == pe )
		goto _test_eof291;
case 291:
	if ( (*p) == 114 )
		goto st292;
	goto tr330;
st292:
	if ( ++p == pe )
		goto _test_eof292;
case 292:
	if ( (*p) == 97 )
		goto st293;
	goto tr330;
st293:
	if ( ++p == pe )
		goto _test_eof293;
case 293:
	if ( (*p) == 99 )
		goto st294;
	goto tr330;
st294:
	if ( ++p == pe )
		goto _test_eof294;
case 294:
	if ( (*p) == 116 )
		goto st295;
	goto tr330;
st295:
	if ( ++p == pe )
		goto _test_eof295;
case 295:
	if ( (*p) == 101 )
		goto st296;
	goto tr330;
st296:
	if ( ++p == pe )
		goto _test_eof296;
case 296:
	if ( (*p) == 114 )
		goto st297;
	goto tr330;
st297:
	if ( ++p == pe )
		goto _test_eof297;
case 297:
	if ( (*p) == 44 )
		goto st298;
	goto tr330;
st298:
	if ( ++p == pe )
		goto _test_eof298;
case 298:
	if ( (*p) == 68 )
		goto st299;
	goto tr306;
st299:
	if ( ++p == pe )
		goto _test_eof299;
case 299:
	if ( (*p) == 101 )
		goto st300;
	goto tr306;
st300:
	if ( ++p == pe )
		goto _test_eof300;
case 300:
	if ( (*p) == 115 )
		goto st301;
	goto tr306;
st301:
	if ( ++p == pe )
		goto _test_eof301;
case 301:
	if ( (*p) == 99 )
		goto st302;
	goto tr306;
st302:
	if ( ++p == pe )
		goto _test_eof302;
case 302:
	if ( (*p) == 114 )
		goto st303;
	goto tr306;
st303:
	if ( ++p == pe )
		goto _test_eof303;
case 303:
	if ( (*p) == 105 )
		goto st304;
	goto tr306;
st304:
	if ( ++p == pe )
		goto _test_eof304;
case 304:
	if ( (*p) == 112 )
		goto st305;
	goto tr306;
st305:
	if ( ++p == pe )
		goto _test_eof305;
case 305:
	if ( (*p) == 116 )
		goto st306;
	goto tr306;
st306:
	if ( ++p == pe )
		goto _test_eof306;
case 306:
	if ( (*p) == 105 )
		goto st307;
	goto tr306;
st307:
	if ( ++p == pe )
		goto _test_eof307;
case 307:
	if ( (*p) == 111 )
		goto st308;
	goto tr306;
st308:
	if ( ++p == pe )
		goto _test_eof308;
case 308:
	if ( (*p) == 110 )
		goto st309;
	goto tr306;
st309:
	if ( ++p == pe )
		goto _test_eof309;
case 309:
	if ( (*p) == 61 )
		goto st310;
	goto tr306;
st310:
	if ( ++p == pe )
		goto _test_eof310;
case 310:
	if ( (*p) == 34 )
		goto st311;
	goto tr306;
st311:
	if ( ++p == pe )
		goto _test_eof311;
case 311:
	if ( (*p) > 33 ) {
		if ( 35 <= (*p) && (*p) <= 126 )
			goto st312;
	} else if ( (*p) >= 32 )
		goto st312;
	goto tr306;
st312:
	if ( ++p == pe )
		goto _test_eof312;
case 312:
	if ( (*p) == 34 )
		goto st313;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto st312;
	goto tr358;
st313:
	if ( ++p == pe )
		goto _test_eof313;
case 313:
	switch( (*p) ) {
		case 44: goto st314;
		case 62: goto st337;
	}
	goto tr360;
st314:
	if ( ++p == pe )
		goto _test_eof314;
case 314:
	switch( (*p) ) {
		case 83: goto st315;
		case 86: goto st326;
	}
	goto tr363;
st315:
	if ( ++p == pe )
		goto _test_eof315;
case 315:
	if ( (*p) == 111 )
		goto st316;
	goto tr366;
st316:
	if ( ++p == pe )
		goto _test_eof316;
case 316:
	if ( (*p) == 117 )
		goto st317;
	goto tr366;
st317:
	if ( ++p == pe )
		goto _test_eof317;
case 317:
	if ( (*p) == 114 )
		goto st318;
	goto tr366;
st318:
	if ( ++p == pe )
		goto _test_eof318;
case 318:
	if ( (*p) == 99 )
		goto st319;
	goto tr366;
st319:
	if ( ++p == pe )
		goto _test_eof319;
case 319:
	if ( (*p) == 101 )
		goto st320;
	goto tr366;
st320:
	if ( ++p == pe )
		goto _test_eof320;
case 320:
	if ( (*p) == 61 )
		goto st321;
	goto tr366;
st321:
	if ( ++p == pe )
		goto _test_eof321;
case 321:
	if ( (*p) == 34 )
		goto st322;
	goto tr366;
st322:
	if ( ++p == pe )
		goto _test_eof322;
case 322:
	if ( (*p) > 33 ) {
		if ( 35 <= (*p) && (*p) <= 126 )
			goto st323;
	} else if ( (*p) >= 32 )
		goto st323;
	goto tr366;
st323:
	if ( ++p == pe )
		goto _test_eof323;
case 323:
	if ( (*p) == 34 )
		goto st324;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto st323;
	goto tr366;
st324:
	if ( ++p == pe )
		goto _test_eof324;
case 324:
	switch( (*p) ) {
		case 44: goto st325;
		case 62: goto st337;
	}
	goto tr363;
st325:
	if ( ++p == pe )
		goto _test_eof325;
case 325:
	if ( (*p) == 86 )
		goto st326;
	goto tr377;
st326:
	if ( ++p == pe )
		goto _test_eof326;
case 326:
	if ( (*p) == 101 )
		goto st327;
	goto tr377;
st327:
	if ( ++p == pe )
		goto _test_eof327;
case 327:
	if ( (*p) == 114 )
		goto st328;
	goto tr377;
st328:
	if ( ++p == pe )
		goto _test_eof328;
case 328:
	if ( (*p) == 115 )
		goto st329;
	goto tr377;
st329:
	if ( ++p == pe )
		goto _test_eof329;
case 329:
	if ( (*p) == 105 )
		goto st330;
	goto tr377;
st330:
	if ( ++p == pe )
		goto _test_eof330;
case 330:
	if ( (*p) == 111 )
		goto st331;
	goto tr377;
st331:
	if ( ++p == pe )
		goto _test_eof331;
case 331:
	if ( (*p) == 110 )
		goto st332;
	goto tr377;
st332:
	if ( ++p == pe )
		goto _test_eof332;
case 332:
	if ( (*p) == 61 )
		goto st333;
	goto tr377;
st333:
	if ( ++p == pe )
		goto _test_eof333;
case 333:
	if ( (*p) == 34 )
		goto st334;
	goto tr377;
st334:
	if ( ++p == pe )
		goto _test_eof334;
case 334:
	if ( (*p) > 33 ) {
		if ( 35 <= (*p) && (*p) <= 126 )
			goto st335;
	} else if ( (*p) >= 32 )
		goto st335;
	goto tr377;
st335:
	if ( ++p == pe )
		goto _test_eof335;
case 335:
	if ( (*p) == 34 )
		goto st336;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto st335;
	goto tr377;
st336:
	if ( ++p == pe )
		goto _test_eof336;
case 336:
	if ( (*p) == 62 )
		goto st337;
	goto tr377;
st337:
	if ( ++p == pe )
		goto _test_eof337;
case 337:
	if ( (*p) == 10 )
		goto tr388;
	goto tr306;
st338:
	if ( ++p == pe )
		goto _test_eof338;
case 338:
	if ( (*p) == 108 )
		goto st339;
	goto tr330;
st339:
	if ( ++p == pe )
		goto _test_eof339;
case 339:
	switch( (*p) ) {
		case 97: goto st340;
		case 111: goto st341;
	}
	goto tr330;
st340:
	if ( ++p == pe )
		goto _test_eof340;
case 340:
	if ( (*p) == 103 )
		goto st297;
	goto tr330;
st341:
	if ( ++p == pe )
		goto _test_eof341;
case 341:
	if ( (*p) == 97 )
		goto st342;
	goto tr330;
st342:
	if ( ++p == pe )
		goto _test_eof342;
case 342:
	if ( (*p) == 116 )
		goto st297;
	goto tr330;
st343:
	if ( ++p == pe )
		goto _test_eof343;
case 343:
	if ( (*p) == 110 )
		goto st344;
	goto tr330;
st344:
	if ( ++p == pe )
		goto _test_eof344;
case 344:
	if ( (*p) == 116 )
		goto st345;
	goto tr330;
st345:
	if ( ++p == pe )
		goto _test_eof345;
case 345:
	if ( (*p) == 101 )
		goto st346;
	goto tr330;
st346:
	if ( ++p == pe )
		goto _test_eof346;
case 346:
	if ( (*p) == 103 )
		goto st295;
	goto tr330;
st347:
	if ( ++p == pe )
		goto _test_eof347;
case 347:
	if ( (*p) == 116 )
		goto st348;
	goto tr330;
st348:
	if ( ++p == pe )
		goto _test_eof348;
case 348:
	if ( (*p) == 114 )
		goto st349;
	goto tr330;
st349:
	if ( ++p == pe )
		goto _test_eof349;
case 349:
	if ( (*p) == 105 )
		goto st350;
	goto tr330;
st350:
	if ( ++p == pe )
		goto _test_eof350;
case 350:
	if ( (*p) == 110 )
		goto st340;
	goto tr330;
st351:
	if ( ++p == pe )
		goto _test_eof351;
case 351:
	if ( (*p) == 44 )
		goto st283;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st351;
	goto tr321;
tr29:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st352;
st352:
	if ( ++p == pe )
		goto _test_eof352;
case 352:
#line 7539 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 69: goto st353;
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
	goto tr399;
st353:
	if ( ++p == pe )
		goto _test_eof353;
case 353:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 68: goto st354;
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
	goto tr399;
st354:
	if ( ++p == pe )
		goto _test_eof354;
case 354:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 73: goto st355;
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
	goto tr399;
st355:
	if ( ++p == pe )
		goto _test_eof355;
case 355:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 71: goto st356;
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
	goto tr399;
st356:
	if ( ++p == pe )
		goto _test_eof356;
case 356:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 82: goto st357;
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
	goto tr399;
st357:
	if ( ++p == pe )
		goto _test_eof357;
case 357:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 69: goto st358;
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
	goto tr399;
st358:
	if ( ++p == pe )
		goto _test_eof358;
case 358:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 69: goto st359;
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
	goto tr399;
st359:
	if ( ++p == pe )
		goto _test_eof359;
case 359:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto st360;
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
	goto tr399;
st360:
	if ( ++p == pe )
		goto _test_eof360;
case 360:
	if ( (*p) == 60 )
		goto st361;
	goto tr408;
st361:
	if ( ++p == pe )
		goto _test_eof361;
case 361:
	if ( (*p) == 95 )
		goto st361;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st361;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st362;
		} else if ( (*p) >= 65 )
			goto st362;
	} else
		goto st362;
	goto tr410;
st362:
	if ( ++p == pe )
		goto _test_eof362;
case 362:
	switch( (*p) ) {
		case 61: goto st363;
		case 95: goto st362;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st362;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st362;
		} else if ( (*p) >= 65 )
			goto st362;
	} else
		goto st362;
	goto tr410;
st363:
	if ( ++p == pe )
		goto _test_eof363;
case 363:
	if ( (*p) == 95 )
		goto st363;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st363;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st364;
		} else if ( (*p) >= 65 )
			goto st364;
	} else
		goto st364;
	goto tr410;
st364:
	if ( ++p == pe )
		goto _test_eof364;
case 364:
	switch( (*p) ) {
		case 44: goto st361;
		case 62: goto st365;
		case 95: goto st364;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st364;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st364;
		} else if ( (*p) >= 65 )
			goto st364;
	} else
		goto st364;
	goto tr410;
st365:
	if ( ++p == pe )
		goto _test_eof365;
case 365:
	if ( (*p) == 10 )
		goto tr415;
	goto tr408;
tr30:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st366;
st366:
	if ( ++p == pe )
		goto _test_eof366;
case 366:
#line 7884 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 65: goto st367;
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
	goto tr416;
st367:
	if ( ++p == pe )
		goto _test_eof367;
case 367:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 77: goto st368;
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
	goto tr416;
st368:
	if ( ++p == pe )
		goto _test_eof368;
case 368:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 80: goto st369;
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
	goto tr416;
st369:
	if ( ++p == pe )
		goto _test_eof369;
case 369:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 76: goto st370;
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
	goto tr416;
st370:
	if ( ++p == pe )
		goto _test_eof370;
case 370:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
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
	goto tr416;
st371:
	if ( ++p == pe )
		goto _test_eof371;
case 371:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto st372;
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
	goto tr416;
st372:
	if ( ++p == pe )
		goto _test_eof372;
case 372:
	if ( (*p) == 60 )
		goto st373;
	goto tr423;
st373:
	if ( ++p == pe )
		goto _test_eof373;
case 373:
	if ( (*p) == 73 )
		goto st374;
	goto tr423;
st374:
	if ( ++p == pe )
		goto _test_eof374;
case 374:
	if ( (*p) == 68 )
		goto st375;
	goto tr423;
st375:
	if ( ++p == pe )
		goto _test_eof375;
case 375:
	if ( (*p) == 61 )
		goto st376;
	goto tr423;
st376:
	if ( ++p == pe )
		goto _test_eof376;
case 376:
	if ( (*p) == 95 )
		goto st376;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st376;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st377;
		} else if ( (*p) >= 65 )
			goto st377;
	} else
		goto st377;
	goto tr428;
st377:
	if ( ++p == pe )
		goto _test_eof377;
case 377:
	switch( (*p) ) {
		case 44: goto st378;
		case 95: goto st377;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st377;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st377;
		} else if ( (*p) >= 65 )
			goto st377;
	} else
		goto st377;
	goto tr430;
st378:
	if ( ++p == pe )
		goto _test_eof378;
case 378:
	if ( (*p) == 71 )
		goto st379;
	goto tr432;
st379:
	if ( ++p == pe )
		goto _test_eof379;
case 379:
	if ( (*p) == 101 )
		goto st380;
	goto tr432;
st380:
	if ( ++p == pe )
		goto _test_eof380;
case 380:
	if ( (*p) == 110 )
		goto st381;
	goto tr432;
st381:
	if ( ++p == pe )
		goto _test_eof381;
case 381:
	if ( (*p) == 111 )
		goto st382;
	goto tr432;
st382:
	if ( ++p == pe )
		goto _test_eof382;
case 382:
	if ( (*p) == 109 )
		goto st383;
	goto tr432;
st383:
	if ( ++p == pe )
		goto _test_eof383;
case 383:
	if ( (*p) == 101 )
		goto st384;
	goto tr432;
st384:
	if ( ++p == pe )
		goto _test_eof384;
case 384:
	if ( (*p) == 115 )
		goto st385;
	goto tr432;
st385:
	if ( ++p == pe )
		goto _test_eof385;
case 385:
	if ( (*p) == 61 )
		goto st386;
	goto tr432;
st386:
	if ( ++p == pe )
		goto _test_eof386;
case 386:
	if ( (*p) == 95 )
		goto st386;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st386;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st387;
		} else if ( (*p) >= 65 )
			goto st387;
	} else
		goto st387;
	goto tr432;
st387:
	if ( ++p == pe )
		goto _test_eof387;
case 387:
	switch( (*p) ) {
		case 44: goto st388;
		case 59: goto st386;
		case 95: goto st387;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st387;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st387;
		} else if ( (*p) >= 65 )
			goto st387;
	} else
		goto st387;
	goto tr442;
st388:
	if ( ++p == pe )
		goto _test_eof388;
case 388:
	if ( (*p) == 77 )
		goto st389;
	goto tr444;
st389:
	if ( ++p == pe )
		goto _test_eof389;
case 389:
	if ( (*p) == 105 )
		goto st390;
	goto tr444;
st390:
	if ( ++p == pe )
		goto _test_eof390;
case 390:
	if ( (*p) == 120 )
		goto st391;
	goto tr444;
st391:
	if ( ++p == pe )
		goto _test_eof391;
case 391:
	if ( (*p) == 116 )
		goto st392;
	goto tr444;
st392:
	if ( ++p == pe )
		goto _test_eof392;
case 392:
	if ( (*p) == 117 )
		goto st393;
	goto tr444;
st393:
	if ( ++p == pe )
		goto _test_eof393;
case 393:
	if ( (*p) == 114 )
		goto st394;
	goto tr444;
st394:
	if ( ++p == pe )
		goto _test_eof394;
case 394:
	if ( (*p) == 101 )
		goto st395;
	goto tr444;
st395:
	if ( ++p == pe )
		goto _test_eof395;
case 395:
	if ( (*p) == 61 )
		goto st396;
	goto tr444;
st396:
	if ( ++p == pe )
		goto _test_eof396;
case 396:
	if ( (*p) == 95 )
		goto st396;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st396;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st397;
		} else if ( (*p) >= 65 )
			goto st397;
	} else
		goto st397;
	goto tr444;
st397:
	if ( ++p == pe )
		goto _test_eof397;
case 397:
	switch( (*p) ) {
		case 44: goto st398;
		case 59: goto st396;
		case 95: goto st397;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st397;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st397;
		} else if ( (*p) >= 65 )
			goto st397;
	} else
		goto st397;
	goto tr454;
st398:
	if ( ++p == pe )
		goto _test_eof398;
case 398:
	if ( (*p) == 68 )
		goto st399;
	goto tr456;
st399:
	if ( ++p == pe )
		goto _test_eof399;
case 399:
	if ( (*p) == 101 )
		goto st400;
	goto tr456;
st400:
	if ( ++p == pe )
		goto _test_eof400;
case 400:
	if ( (*p) == 115 )
		goto st401;
	goto tr456;
st401:
	if ( ++p == pe )
		goto _test_eof401;
case 401:
	if ( (*p) == 99 )
		goto st402;
	goto tr456;
st402:
	if ( ++p == pe )
		goto _test_eof402;
case 402:
	if ( (*p) == 114 )
		goto st403;
	goto tr456;
st403:
	if ( ++p == pe )
		goto _test_eof403;
case 403:
	if ( (*p) == 105 )
		goto st404;
	goto tr456;
st404:
	if ( ++p == pe )
		goto _test_eof404;
case 404:
	if ( (*p) == 112 )
		goto st405;
	goto tr456;
st405:
	if ( ++p == pe )
		goto _test_eof405;
case 405:
	if ( (*p) == 116 )
		goto st406;
	goto tr456;
st406:
	if ( ++p == pe )
		goto _test_eof406;
case 406:
	if ( (*p) == 105 )
		goto st407;
	goto tr456;
st407:
	if ( ++p == pe )
		goto _test_eof407;
case 407:
	if ( (*p) == 111 )
		goto st408;
	goto tr456;
st408:
	if ( ++p == pe )
		goto _test_eof408;
case 408:
	if ( (*p) == 110 )
		goto st409;
	goto tr456;
st409:
	if ( ++p == pe )
		goto _test_eof409;
case 409:
	if ( (*p) == 61 )
		goto st410;
	goto tr456;
st410:
	if ( ++p == pe )
		goto _test_eof410;
case 410:
	if ( (*p) == 34 )
		goto st411;
	goto tr456;
st411:
	if ( ++p == pe )
		goto _test_eof411;
case 411:
	if ( (*p) > 33 ) {
		if ( 35 <= (*p) && (*p) <= 126 )
			goto st412;
	} else if ( (*p) >= 32 )
		goto st412;
	goto tr456;
st412:
	if ( ++p == pe )
		goto _test_eof412;
case 412:
	if ( (*p) == 34 )
		goto st413;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto st412;
	goto tr456;
st413:
	if ( ++p == pe )
		goto _test_eof413;
case 413:
	if ( (*p) == 62 )
		goto st414;
	goto tr456;
st414:
	if ( ++p == pe )
		goto _test_eof414;
case 414:
	if ( (*p) == 10 )
		goto tr415;
	goto tr423;
tr31:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st415;
st415:
	if ( ++p == pe )
		goto _test_eof415;
case 415:
#line 8456 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 95: goto st21;
		case 115: goto st416;
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
	goto tr473;
st416:
	if ( ++p == pe )
		goto _test_eof416;
case 416:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 95: goto st21;
		case 115: goto st417;
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
	goto tr473;
st417:
	if ( ++p == pe )
		goto _test_eof417;
case 417:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 95: goto st21;
		case 101: goto st418;
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
	goto tr473;
st418:
	if ( ++p == pe )
		goto _test_eof418;
case 418:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 95: goto st21;
		case 109: goto st419;
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
	goto tr473;
st419:
	if ( ++p == pe )
		goto _test_eof419;
case 419:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 95: goto st21;
		case 98: goto st420;
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
	goto tr473;
st420:
	if ( ++p == pe )
		goto _test_eof420;
case 420:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 95: goto st21;
		case 108: goto st421;
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
	goto tr473;
st421:
	if ( ++p == pe )
		goto _test_eof421;
case 421:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 95: goto st21;
		case 121: goto st422;
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
	goto tr473;
st422:
	if ( ++p == pe )
		goto _test_eof422;
case 422:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto st423;
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
	goto tr473;
st423:
	if ( ++p == pe )
		goto _test_eof423;
case 423:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st424;
	} else if ( (*p) >= 65 )
		goto st424;
	goto tr482;
st424:
	if ( ++p == pe )
		goto _test_eof424;
case 424:
	switch( (*p) ) {
		case 10: goto tr482;
		case 35: goto tr482;
		case 47: goto tr482;
		case 58: goto tr482;
		case 63: goto tr482;
	}
	goto st425;
st425:
	if ( ++p == pe )
		goto _test_eof425;
case 425:
	switch( (*p) ) {
		case 10: goto tr482;
		case 35: goto tr482;
		case 47: goto tr482;
		case 58: goto st426;
		case 63: goto tr482;
	}
	goto st425;
st426:
	if ( ++p == pe )
		goto _test_eof426;
case 426:
	if ( (*p) == 47 )
		goto st427;
	goto tr482;
st427:
	if ( ++p == pe )
		goto _test_eof427;
case 427:
	if ( (*p) == 47 )
		goto st428;
	goto tr482;
st428:
	if ( ++p == pe )
		goto _test_eof428;
case 428:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st429;
	} else if ( (*p) >= 65 )
		goto st429;
	goto tr482;
st429:
	if ( ++p == pe )
		goto _test_eof429;
case 429:
	if ( (*p) == 10 )
		goto tr415;
	goto st429;
tr32:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st430;
st430:
	if ( ++p == pe )
		goto _test_eof430;
case 430:
#line 8775 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 95: goto st21;
		case 111: goto st431;
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
	goto tr489;
st431:
	if ( ++p == pe )
		goto _test_eof431;
case 431:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 95: goto st21;
		case 110: goto st432;
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
	goto tr489;
st432:
	if ( ++p == pe )
		goto _test_eof432;
case 432:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 95: goto st21;
		case 116: goto st433;
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
	goto tr489;
st433:
	if ( ++p == pe )
		goto _test_eof433;
case 433:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 95: goto st21;
		case 105: goto st434;
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
	goto tr489;
st434:
	if ( ++p == pe )
		goto _test_eof434;
case 434:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 95: goto st21;
		case 103: goto st435;
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
	goto tr489;
st435:
	if ( ++p == pe )
		goto _test_eof435;
case 435:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto st436;
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
	goto tr489;
st436:
	if ( ++p == pe )
		goto _test_eof436;
case 436:
	if ( (*p) == 60 )
		goto st437;
	goto tr496;
st437:
	if ( ++p == pe )
		goto _test_eof437;
case 437:
	if ( (*p) == 73 )
		goto st438;
	goto tr496;
st438:
	if ( ++p == pe )
		goto _test_eof438;
case 438:
	if ( (*p) == 68 )
		goto st439;
	goto tr496;
st439:
	if ( ++p == pe )
		goto _test_eof439;
case 439:
	if ( (*p) == 61 )
		goto st440;
	goto tr496;
st440:
	if ( ++p == pe )
		goto _test_eof440;
case 440:
	if ( (*p) == 95 )
		goto st440;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st440;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st441;
		} else if ( (*p) >= 65 )
			goto st441;
	} else
		goto st441;
	goto tr501;
st441:
	if ( ++p == pe )
		goto _test_eof441;
case 441:
	switch( (*p) ) {
		case 44: goto st442;
		case 95: goto st441;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st441;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st441;
		} else if ( (*p) >= 65 )
			goto st441;
	} else
		goto st441;
	goto tr501;
st442:
	if ( ++p == pe )
		goto _test_eof442;
case 442:
	if ( (*p) == 85 )
		goto st443;
	goto tr496;
st443:
	if ( ++p == pe )
		goto _test_eof443;
case 443:
	if ( (*p) == 82 )
		goto st444;
	goto tr496;
st444:
	if ( ++p == pe )
		goto _test_eof444;
case 444:
	if ( (*p) == 76 )
		goto st445;
	goto tr496;
st445:
	if ( ++p == pe )
		goto _test_eof445;
case 445:
	if ( (*p) == 61 )
		goto st446;
	goto tr496;
st446:
	if ( ++p == pe )
		goto _test_eof446;
case 446:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st447;
	} else if ( (*p) >= 65 )
		goto st447;
	goto tr508;
st447:
	if ( ++p == pe )
		goto _test_eof447;
case 447:
	switch( (*p) ) {
		case 10: goto tr508;
		case 35: goto tr508;
		case 47: goto tr508;
		case 58: goto tr508;
		case 63: goto tr508;
	}
	goto st448;
st448:
	if ( ++p == pe )
		goto _test_eof448;
case 448:
	switch( (*p) ) {
		case 10: goto tr508;
		case 35: goto tr508;
		case 47: goto tr508;
		case 58: goto st449;
		case 63: goto tr508;
	}
	goto st448;
st449:
	if ( ++p == pe )
		goto _test_eof449;
case 449:
	if ( (*p) == 47 )
		goto st450;
	goto tr508;
st450:
	if ( ++p == pe )
		goto _test_eof450;
case 450:
	if ( (*p) == 47 )
		goto st451;
	goto tr508;
st451:
	if ( ++p == pe )
		goto _test_eof451;
case 451:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st452;
	} else if ( (*p) >= 65 )
		goto st452;
	goto tr508;
st452:
	if ( ++p == pe )
		goto _test_eof452;
case 452:
	switch( (*p) ) {
		case 10: goto tr508;
		case 62: goto st453;
	}
	goto st452;
st453:
	if ( ++p == pe )
		goto _test_eof453;
case 453:
	switch( (*p) ) {
		case 10: goto tr415;
		case 62: goto st453;
	}
	goto st452;
tr33:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st454;
st454:
	if ( ++p == pe )
		goto _test_eof454;
case 454:
#line 9137 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
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
	goto tr516;
st455:
	if ( ++p == pe )
		goto _test_eof455;
case 455:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 95: goto st21;
		case 100: goto st456;
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
	goto tr516;
st456:
	if ( ++p == pe )
		goto _test_eof456;
case 456:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 95: goto st21;
		case 105: goto st457;
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
	goto tr516;
st457:
	if ( ++p == pe )
		goto _test_eof457;
case 457:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 95: goto st21;
		case 103: goto st458;
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
	goto tr516;
st458:
	if ( ++p == pe )
		goto _test_eof458;
case 458:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 95: goto st21;
		case 114: goto st459;
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
	goto tr516;
st459:
	if ( ++p == pe )
		goto _test_eof459;
case 459:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 95: goto st21;
		case 101: goto st460;
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
	goto tr516;
st460:
	if ( ++p == pe )
		goto _test_eof460;
case 460:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 95: goto st21;
		case 101: goto st461;
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
	goto tr516;
st461:
	if ( ++p == pe )
		goto _test_eof461;
case 461:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 68: goto st462;
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
	goto tr516;
st462:
	if ( ++p == pe )
		goto _test_eof462;
case 462:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 66: goto st463;
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
	goto tr516;
st463:
	if ( ++p == pe )
		goto _test_eof463;
case 463:
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto st464;
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
	goto tr516;
st464:
	if ( ++p == pe )
		goto _test_eof464;
case 464:
	if ( (*p) == 60 )
		goto st465;
	goto tr527;
st465:
	if ( ++p == pe )
		goto _test_eof465;
case 465:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st466;
	} else if ( (*p) >= 65 )
		goto st466;
	goto tr529;
st466:
	if ( ++p == pe )
		goto _test_eof466;
case 466:
	switch( (*p) ) {
		case 10: goto tr529;
		case 35: goto tr529;
		case 47: goto tr529;
		case 58: goto tr529;
		case 63: goto tr529;
	}
	goto st467;
st467:
	if ( ++p == pe )
		goto _test_eof467;
case 467:
	switch( (*p) ) {
		case 10: goto tr529;
		case 35: goto tr529;
		case 47: goto tr529;
		case 58: goto st468;
		case 63: goto tr529;
	}
	goto st467;
st468:
	if ( ++p == pe )
		goto _test_eof468;
case 468:
	if ( (*p) == 47 )
		goto st469;
	goto tr529;
st469:
	if ( ++p == pe )
		goto _test_eof469;
case 469:
	if ( (*p) == 47 )
		goto st470;
	goto tr529;
st470:
	if ( ++p == pe )
		goto _test_eof470;
case 470:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st471;
	} else if ( (*p) >= 65 )
		goto st471;
	goto tr529;
st471:
	if ( ++p == pe )
		goto _test_eof471;
case 471:
	switch( (*p) ) {
		case 10: goto tr529;
		case 62: goto st472;
	}
	goto st471;
st472:
	if ( ++p == pe )
		goto _test_eof472;
case 472:
	switch( (*p) ) {
		case 10: goto tr415;
		case 62: goto st472;
	}
	goto st471;
st473:
	if ( ++p == pe )
		goto _test_eof473;
case 473:
	if ( (*p) == 72 )
		goto st474;
	goto tr537;
st474:
	if ( ++p == pe )
		goto _test_eof474;
case 474:
	if ( (*p) == 82 )
		goto st475;
	goto tr537;
st475:
	if ( ++p == pe )
		goto _test_eof475;
case 475:
	if ( (*p) == 79 )
		goto st476;
	goto tr537;
st476:
	if ( ++p == pe )
		goto _test_eof476;
case 476:
	if ( (*p) == 77 )
		goto st477;
	goto tr537;
st477:
	if ( ++p == pe )
		goto _test_eof477;
case 477:
	if ( (*p) == 9 )
		goto st478;
	goto tr537;
st478:
	if ( ++p == pe )
		goto _test_eof478;
case 478:
	if ( (*p) == 80 )
		goto st479;
	goto tr537;
st479:
	if ( ++p == pe )
		goto _test_eof479;
case 479:
	if ( (*p) == 79 )
		goto st480;
	goto tr537;
st480:
	if ( ++p == pe )
		goto _test_eof480;
case 480:
	if ( (*p) == 83 )
		goto st481;
	goto tr537;
st481:
	if ( ++p == pe )
		goto _test_eof481;
case 481:
	if ( (*p) == 9 )
		goto st482;
	goto tr537;
st482:
	if ( ++p == pe )
		goto _test_eof482;
case 482:
	if ( (*p) == 73 )
		goto st483;
	goto tr537;
st483:
	if ( ++p == pe )
		goto _test_eof483;
case 483:
	if ( (*p) == 68 )
		goto st484;
	goto tr537;
st484:
	if ( ++p == pe )
		goto _test_eof484;
case 484:
	if ( (*p) == 9 )
		goto st485;
	goto tr537;
st485:
	if ( ++p == pe )
		goto _test_eof485;
case 485:
	if ( (*p) == 82 )
		goto st486;
	goto tr537;
st486:
	if ( ++p == pe )
		goto _test_eof486;
case 486:
	if ( (*p) == 69 )
		goto st487;
	goto tr537;
st487:
	if ( ++p == pe )
		goto _test_eof487;
case 487:
	if ( (*p) == 70 )
		goto st488;
	goto tr537;
st488:
	if ( ++p == pe )
		goto _test_eof488;
case 488:
	if ( (*p) == 9 )
		goto st489;
	goto tr537;
st489:
	if ( ++p == pe )
		goto _test_eof489;
case 489:
	if ( (*p) == 65 )
		goto st490;
	goto tr537;
st490:
	if ( ++p == pe )
		goto _test_eof490;
case 490:
	if ( (*p) == 76 )
		goto st491;
	goto tr537;
st491:
	if ( ++p == pe )
		goto _test_eof491;
case 491:
	if ( (*p) == 84 )
		goto st492;
	goto tr537;
st492:
	if ( ++p == pe )
		goto _test_eof492;
case 492:
	if ( (*p) == 9 )
		goto st493;
	goto tr537;
st493:
	if ( ++p == pe )
		goto _test_eof493;
case 493:
	if ( (*p) == 81 )
		goto st494;
	goto tr537;
st494:
	if ( ++p == pe )
		goto _test_eof494;
case 494:
	if ( (*p) == 85 )
		goto st495;
	goto tr537;
st495:
	if ( ++p == pe )
		goto _test_eof495;
case 495:
	if ( (*p) == 65 )
		goto st496;
	goto tr537;
st496:
	if ( ++p == pe )
		goto _test_eof496;
case 496:
	if ( (*p) == 76 )
		goto st497;
	goto tr537;
st497:
	if ( ++p == pe )
		goto _test_eof497;
case 497:
	if ( (*p) == 9 )
		goto st498;
	goto tr537;
st498:
	if ( ++p == pe )
		goto _test_eof498;
case 498:
	if ( (*p) == 70 )
		goto st499;
	goto tr537;
st499:
	if ( ++p == pe )
		goto _test_eof499;
case 499:
	if ( (*p) == 73 )
		goto st500;
	goto tr537;
st500:
	if ( ++p == pe )
		goto _test_eof500;
case 500:
	if ( (*p) == 76 )
		goto st501;
	goto tr537;
st501:
	if ( ++p == pe )
		goto _test_eof501;
case 501:
	if ( (*p) == 84 )
		goto st502;
	goto tr537;
st502:
	if ( ++p == pe )
		goto _test_eof502;
case 502:
	if ( (*p) == 69 )
		goto st503;
	goto tr537;
st503:
	if ( ++p == pe )
		goto _test_eof503;
case 503:
	if ( (*p) == 82 )
		goto st504;
	goto tr537;
st504:
	if ( ++p == pe )
		goto _test_eof504;
case 504:
	if ( (*p) == 9 )
		goto st505;
	goto tr537;
st505:
	if ( ++p == pe )
		goto _test_eof505;
case 505:
	if ( (*p) == 73 )
		goto st506;
	goto tr537;
st506:
	if ( ++p == pe )
		goto _test_eof506;
case 506:
	if ( (*p) == 78 )
		goto st507;
	goto tr537;
st507:
	if ( ++p == pe )
		goto _test_eof507;
case 507:
	if ( (*p) == 70 )
		goto st508;
	goto tr537;
st508:
	if ( ++p == pe )
		goto _test_eof508;
case 508:
	if ( (*p) == 79 )
		goto st509;
	goto tr537;
st509:
	if ( ++p == pe )
		goto _test_eof509;
case 509:
	switch( (*p) ) {
		case 9: goto st510;
		case 10: goto tr575;
	}
	goto tr537;
st510:
	if ( ++p == pe )
		goto _test_eof510;
case 510:
	if ( (*p) == 70 )
		goto st511;
	goto tr537;
st511:
	if ( ++p == pe )
		goto _test_eof511;
case 511:
	if ( (*p) == 79 )
		goto st512;
	goto tr537;
st512:
	if ( ++p == pe )
		goto _test_eof512;
case 512:
	if ( (*p) == 82 )
		goto st513;
	goto tr537;
st513:
	if ( ++p == pe )
		goto _test_eof513;
case 513:
	if ( (*p) == 77 )
		goto st514;
	goto tr537;
st514:
	if ( ++p == pe )
		goto _test_eof514;
case 514:
	if ( (*p) == 65 )
		goto st515;
	goto tr537;
st515:
	if ( ++p == pe )
		goto _test_eof515;
case 515:
	if ( (*p) == 84 )
		goto st516;
	goto tr537;
st516:
	if ( ++p == pe )
		goto _test_eof516;
case 516:
	if ( (*p) == 9 )
		goto st517;
	goto tr537;
tr584:
#line 110 "vcf_v41.ragel"
	{
//        add_vcf_sample_name(ts, p-ts, file);
    }
	goto st517;
st517:
	if ( ++p == pe )
		goto _test_eof517;
case 517:
#line 9846 "vcf_validator_detail.hpp"
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr583;
	goto tr537;
tr583:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st518;
st518:
	if ( ++p == pe )
		goto _test_eof518;
case 518:
#line 9860 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr584;
		case 10: goto tr585;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto st518;
	goto tr537;
tr575:
#line 23 "vcf_v41.ragel"
	{
        ++n_lines;
        n_columns = 1;
    }
	goto st715;
tr585:
#line 110 "vcf_v41.ragel"
	{
//        add_vcf_sample_name(ts, p-ts, file);
    }
#line 23 "vcf_v41.ragel"
	{
        ++n_lines;
        n_columns = 1;
    }
	goto st715;
st715:
	if ( ++p == pe )
		goto _test_eof715;
case 715:
#line 9890 "vcf_validator_detail.hpp"
	if ( (*p) == 60 )
		goto tr844;
	if ( (*p) < 59 ) {
		if ( 33 <= (*p) && (*p) <= 57 )
			goto tr843;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr843;
	} else
		goto tr843;
	goto tr842;
tr843:
#line 114 "vcf_v41.ragel"
	{
//        status->current_record = vcf_record_new();
//        printf("Reading record\n");
    }
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st519;
st519:
	if ( ++p == pe )
		goto _test_eof519;
case 519:
#line 9917 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr588;
		case 59: goto st519;
		case 61: goto st519;
	}
	if ( (*p) > 57 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto st519;
	} else if ( (*p) >= 33 )
		goto st519;
	goto tr587;
tr588:
#line 143 "vcf_v41.ragel"
	{
//        set_vcf_record_chromosome(ts, p-ts, status->current_record);
    }
#line 28 "vcf_v41.ragel"
	{
        ++n_columns;
    }
	goto st520;
st520:
	if ( ++p == pe )
		goto _test_eof520;
case 520:
#line 9943 "vcf_validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr591;
	goto tr590;
tr591:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st521;
st521:
	if ( ++p == pe )
		goto _test_eof521;
case 521:
#line 9957 "vcf_validator_detail.hpp"
	if ( (*p) == 9 )
		goto tr592;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st521;
	goto tr590;
tr592:
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
	goto st522;
st522:
	if ( ++p == pe )
		goto _test_eof522;
case 522:
#line 9979 "vcf_validator_detail.hpp"
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr595;
	} else if ( (*p) >= 33 )
		goto tr595;
	goto tr594;
tr595:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st523;
st523:
	if ( ++p == pe )
		goto _test_eof523;
case 523:
#line 9996 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr596;
		case 59: goto st712;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st523;
	goto tr594;
tr596:
#line 153 "vcf_v41.ragel"
	{
//        set_vcf_record_id(ts, p-ts, status->current_record);
    }
#line 28 "vcf_v41.ragel"
	{
        ++n_columns;
    }
	goto st524;
st524:
	if ( ++p == pe )
		goto _test_eof524;
case 524:
#line 10018 "vcf_validator_detail.hpp"
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
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st525;
st525:
	if ( ++p == pe )
		goto _test_eof525;
case 525:
#line 10042 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr601;
		case 65: goto st525;
		case 67: goto st525;
		case 71: goto st525;
		case 78: goto st525;
		case 84: goto st525;
		case 97: goto st525;
		case 99: goto st525;
		case 103: goto st525;
		case 110: goto st525;
		case 116: goto st525;
	}
	goto tr599;
tr601:
#line 157 "vcf_v41.ragel"
	{
 //       set_vcf_record_reference(ts, p-ts, status->current_record);
    }
#line 28 "vcf_v41.ragel"
	{
        ++n_columns;
    }
	goto st526;
st526:
	if ( ++p == pe )
		goto _test_eof526;
case 526:
#line 10071 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 42: goto tr604;
		case 46: goto tr605;
		case 48: goto tr606;
		case 60: goto tr607;
		case 65: goto tr608;
		case 67: goto tr608;
		case 71: goto tr608;
		case 78: goto tr608;
		case 84: goto tr608;
		case 91: goto tr609;
		case 93: goto tr610;
		case 97: goto tr608;
		case 99: goto tr608;
		case 103: goto tr608;
		case 110: goto tr608;
		case 116: goto tr608;
	}
	goto tr603;
tr604:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st527;
st527:
	if ( ++p == pe )
		goto _test_eof527;
case 527:
#line 10101 "vcf_validator_detail.hpp"
	if ( (*p) == 9 )
		goto tr611;
	goto tr603;
tr611:
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
	goto st528;
tr777:
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
	goto st528;
tr779:
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
	goto st528;
tr786:
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
	goto st528;
st528:
	if ( ++p == pe )
		goto _test_eof528;
case 528:
#line 10177 "vcf_validator_detail.hpp"
	if ( (*p) == 46 )
		goto tr613;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr614;
	goto tr612;
tr613:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st529;
st529:
	if ( ++p == pe )
		goto _test_eof529;
case 529:
#line 10193 "vcf_validator_detail.hpp"
	if ( (*p) == 9 )
		goto tr615;
	goto tr612;
tr615:
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
	goto st530;
st530:
	if ( ++p == pe )
		goto _test_eof530;
case 530:
#line 10217 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 46: goto tr618;
		case 58: goto tr617;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr617;
		} else if ( (*p) > 57 ) {
			if ( 60 <= (*p) && (*p) <= 64 )
				goto tr617;
		} else
			goto tr619;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr617;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr617;
		} else
			goto tr619;
	} else
		goto tr619;
	goto tr616;
tr617:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st531;
st531:
	if ( ++p == pe )
		goto _test_eof531;
case 531:
#line 10253 "vcf_validator_detail.hpp"
	if ( (*p) == 58 )
		goto st531;
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto st531;
		} else if ( (*p) > 57 ) {
			if ( 60 <= (*p) && (*p) <= 64 )
				goto st531;
		} else
			goto st532;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st531;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st531;
		} else
			goto st532;
	} else
		goto st532;
	goto tr616;
tr619:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st532;
st532:
	if ( ++p == pe )
		goto _test_eof532;
case 532:
#line 10287 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr622;
		case 59: goto st531;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st532;
	goto tr616;
tr622:
#line 191 "vcf_v41.ragel"
	{
 //       set_vcf_record_filter(ts, p-ts, status->current_record);
    }
#line 28 "vcf_v41.ragel"
	{
        ++n_columns;
    }
	goto st533;
st533:
	if ( ++p == pe )
		goto _test_eof533;
case 533:
#line 10309 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 46: goto tr625;
		case 49: goto tr627;
		case 58: goto tr624;
		case 60: goto tr624;
		case 65: goto tr628;
		case 66: goto tr629;
		case 67: goto tr630;
		case 68: goto tr631;
		case 69: goto tr632;
		case 72: goto tr633;
		case 77: goto tr634;
		case 78: goto tr635;
		case 83: goto tr636;
		case 86: goto tr637;
	}
	if ( (*p) < 70 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr624;
		} else if ( (*p) > 57 ) {
			if ( 62 <= (*p) && (*p) <= 64 )
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
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st534;
st534:
	if ( ++p == pe )
		goto _test_eof534;
case 534:
#line 10357 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 58: goto st534;
		case 60: goto st534;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto st534;
		} else if ( (*p) > 57 ) {
			if ( 62 <= (*p) && (*p) <= 64 )
				goto st534;
		} else
			goto st535;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st534;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st534;
		} else
			goto st535;
	} else
		goto st535;
	goto tr623;
tr626:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st535;
st535:
	if ( ++p == pe )
		goto _test_eof535;
case 535:
#line 10393 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr640;
		case 10: goto tr641;
		case 59: goto st549;
		case 61: goto st554;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st535;
	goto tr623;
tr640:
#line 195 "vcf_v41.ragel"
	{
//        set_vcf_record_info(ts, p-ts, status->current_record);
    }
#line 28 "vcf_v41.ragel"
	{
        ++n_columns;
    }
	goto st536;
st536:
	if ( ++p == pe )
		goto _test_eof536;
case 536:
#line 10417 "vcf_validator_detail.hpp"
	if ( (*p) == 71 )
		goto tr645;
	goto tr644;
tr645:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st537;
st537:
	if ( ++p == pe )
		goto _test_eof537;
case 537:
#line 10431 "vcf_validator_detail.hpp"
	if ( (*p) == 84 )
		goto st538;
	goto tr644;
st538:
	if ( ++p == pe )
		goto _test_eof538;
case 538:
	switch( (*p) ) {
		case 9: goto tr647;
		case 58: goto st547;
	}
	goto tr644;
tr647:
#line 199 "vcf_v41.ragel"
	{
 //       set_vcf_record_format(ts, p-ts, status->current_record);
    }
#line 28 "vcf_v41.ragel"
	{
        ++n_columns;
    }
	goto st539;
tr651:
#line 203 "vcf_v41.ragel"
	{
//        add_vcf_record_sample(ts, p-ts, status->current_record);
    }
#line 28 "vcf_v41.ragel"
	{
        ++n_columns;
    }
	goto st539;
st539:
	if ( ++p == pe )
		goto _test_eof539;
case 539:
#line 10468 "vcf_validator_detail.hpp"
	if ( (*p) == 46 )
		goto tr650;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr650;
	goto tr649;
tr650:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st540;
st540:
	if ( ++p == pe )
		goto _test_eof540;
case 540:
#line 10484 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr651;
		case 10: goto tr652;
		case 47: goto st544;
		case 58: goto st545;
		case 124: goto st544;
	}
	goto tr649;
tr641:
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
	goto st716;
tr652:
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
	goto st716;
st716:
	if ( ++p == pe )
		goto _test_eof716;
case 716:
#line 10567 "vcf_validator_detail.hpp"
	if ( (*p) == 60 )
		goto tr844;
	if ( (*p) < 59 ) {
		if ( 33 <= (*p) && (*p) <= 57 )
			goto tr843;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr843;
	} else
		goto tr843;
	goto tr587;
tr844:
#line 114 "vcf_v41.ragel"
	{
//        status->current_record = vcf_record_new();
//        printf("Reading record\n");
    }
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st541;
st541:
	if ( ++p == pe )
		goto _test_eof541;
case 541:
#line 10594 "vcf_validator_detail.hpp"
	if ( (*p) < 59 ) {
		if ( 33 <= (*p) && (*p) <= 57 )
			goto st542;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto st542;
	} else
		goto st542;
	goto tr587;
st542:
	if ( ++p == pe )
		goto _test_eof542;
case 542:
	if ( (*p) == 62 )
		goto st543;
	if ( (*p) > 57 ) {
		if ( 59 <= (*p) && (*p) <= 126 )
			goto st542;
	} else if ( (*p) >= 33 )
		goto st542;
	goto tr587;
st543:
	if ( ++p == pe )
		goto _test_eof543;
case 543:
	if ( (*p) == 9 )
		goto tr588;
	goto tr587;
st544:
	if ( ++p == pe )
		goto _test_eof544;
case 544:
	if ( (*p) == 46 )
		goto st540;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st540;
	goto tr649;
st545:
	if ( ++p == pe )
		goto _test_eof545;
case 545:
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st546;
	goto tr658;
st546:
	if ( ++p == pe )
		goto _test_eof546;
case 546:
	switch( (*p) ) {
		case 9: goto tr651;
		case 10: goto tr652;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st546;
	goto tr658;
st547:
	if ( ++p == pe )
		goto _test_eof547;
case 547:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st548;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st548;
	} else
		goto st548;
	goto tr660;
st548:
	if ( ++p == pe )
		goto _test_eof548;
case 548:
	switch( (*p) ) {
		case 9: goto tr647;
		case 58: goto st547;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st548;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st548;
	} else
		goto st548;
	goto tr660;
st549:
	if ( ++p == pe )
		goto _test_eof549;
case 549:
	switch( (*p) ) {
		case 49: goto st550;
		case 58: goto st534;
		case 60: goto st534;
		case 65: goto st559;
		case 66: goto st575;
		case 67: goto st581;
		case 68: goto st588;
		case 69: goto st595;
		case 72: goto st600;
		case 77: goto st607;
		case 78: goto st616;
		case 83: goto st620;
		case 86: goto st634;
	}
	if ( (*p) < 70 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto st534;
		} else if ( (*p) > 57 ) {
			if ( 62 <= (*p) && (*p) <= 64 )
				goto st534;
		} else
			goto st535;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st534;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st534;
		} else
			goto st535;
	} else
		goto st535;
	goto tr623;
tr627:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st550;
st550:
	if ( ++p == pe )
		goto _test_eof550;
case 550:
#line 10730 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr640;
		case 10: goto tr641;
		case 48: goto st551;
		case 59: goto st549;
		case 61: goto st554;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st535;
	goto tr623;
st551:
	if ( ++p == pe )
		goto _test_eof551;
case 551:
	switch( (*p) ) {
		case 9: goto tr640;
		case 10: goto tr641;
		case 48: goto st552;
		case 59: goto st549;
		case 61: goto st554;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st535;
	goto tr623;
st552:
	if ( ++p == pe )
		goto _test_eof552;
case 552:
	switch( (*p) ) {
		case 9: goto tr640;
		case 10: goto tr641;
		case 48: goto st553;
		case 59: goto st549;
		case 61: goto st554;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st535;
	goto tr623;
st553:
	if ( ++p == pe )
		goto _test_eof553;
case 553:
	switch( (*p) ) {
		case 9: goto tr640;
		case 10: goto tr641;
		case 59: goto st549;
		case 61: goto st554;
		case 71: goto st556;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st535;
	goto tr623;
st554:
	if ( ++p == pe )
		goto _test_eof554;
case 554:
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto st555;
	} else if ( (*p) >= 33 )
		goto st555;
	goto tr623;
st555:
	if ( ++p == pe )
		goto _test_eof555;
case 555:
	switch( (*p) ) {
		case 9: goto tr640;
		case 10: goto tr641;
		case 59: goto st549;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st555;
	goto tr623;
st556:
	if ( ++p == pe )
		goto _test_eof556;
case 556:
	switch( (*p) ) {
		case 9: goto tr640;
		case 10: goto tr641;
		case 59: goto st549;
		case 61: goto st557;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st535;
	goto tr678;
st557:
	if ( ++p == pe )
		goto _test_eof557;
case 557:
	if ( 48 <= (*p) && (*p) <= 49 )
		goto st558;
	goto tr678;
st558:
	if ( ++p == pe )
		goto _test_eof558;
case 558:
	switch( (*p) ) {
		case 9: goto tr640;
		case 10: goto tr641;
		case 59: goto st549;
	}
	goto tr678;
tr628:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st559;
st559:
	if ( ++p == pe )
		goto _test_eof559;
case 559:
#line 10845 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr640;
		case 10: goto tr641;
		case 59: goto st549;
		case 61: goto st554;
		case 65: goto st560;
		case 67: goto st564;
		case 70: goto st567;
		case 78: goto st572;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st535;
	goto tr623;
st560:
	if ( ++p == pe )
		goto _test_eof560;
case 560:
	if ( (*p) == 61 )
		goto st561;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto st535;
	} else if ( (*p) >= 33 )
		goto st535;
	goto tr623;
st561:
	if ( ++p == pe )
		goto _test_eof561;
case 561:
	switch( (*p) ) {
		case 46: goto st562;
		case 65: goto st563;
		case 67: goto st563;
		case 71: goto st563;
		case 78: goto st563;
		case 84: goto st563;
		case 97: goto st563;
		case 99: goto st563;
		case 103: goto st563;
		case 110: goto st563;
		case 116: goto st563;
	}
	goto tr686;
st562:
	if ( ++p == pe )
		goto _test_eof562;
case 562:
	switch( (*p) ) {
		case 9: goto tr640;
		case 10: goto tr641;
		case 59: goto st549;
	}
	goto tr686;
st563:
	if ( ++p == pe )
		goto _test_eof563;
case 563:
	switch( (*p) ) {
		case 9: goto tr640;
		case 10: goto tr641;
		case 59: goto st549;
		case 65: goto st563;
		case 67: goto st563;
		case 71: goto st563;
		case 78: goto st563;
		case 84: goto st563;
		case 97: goto st563;
		case 99: goto st563;
		case 103: goto st563;
		case 110: goto st563;
		case 116: goto st563;
	}
	goto tr686;
st564:
	if ( ++p == pe )
		goto _test_eof564;
case 564:
	if ( (*p) == 61 )
		goto st565;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto st535;
	} else if ( (*p) >= 33 )
		goto st535;
	goto tr623;
st565:
	if ( ++p == pe )
		goto _test_eof565;
case 565:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st566;
	goto tr690;
st566:
	if ( ++p == pe )
		goto _test_eof566;
case 566:
	switch( (*p) ) {
		case 9: goto tr640;
		case 10: goto tr641;
		case 44: goto st565;
		case 59: goto st549;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st566;
	goto tr690;
st567:
	if ( ++p == pe )
		goto _test_eof567;
case 567:
	if ( (*p) == 61 )
		goto st568;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto st535;
	} else if ( (*p) >= 33 )
		goto st535;
	goto tr623;
st568:
	if ( ++p == pe )
		goto _test_eof568;
case 568:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st569;
	goto tr693;
st569:
	if ( ++p == pe )
		goto _test_eof569;
case 569:
	switch( (*p) ) {
		case 9: goto tr640;
		case 10: goto tr641;
		case 44: goto st568;
		case 46: goto st570;
		case 59: goto st549;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st569;
	goto tr693;
st570:
	if ( ++p == pe )
		goto _test_eof570;
case 570:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st571;
	goto tr693;
st571:
	if ( ++p == pe )
		goto _test_eof571;
case 571:
	switch( (*p) ) {
		case 9: goto tr640;
		case 10: goto tr641;
		case 44: goto st568;
		case 59: goto st549;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st571;
	goto tr693;
st572:
	if ( ++p == pe )
		goto _test_eof572;
case 572:
	if ( (*p) == 61 )
		goto st573;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto st535;
	} else if ( (*p) >= 33 )
		goto st535;
	goto tr623;
st573:
	if ( ++p == pe )
		goto _test_eof573;
case 573:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st574;
	goto tr698;
st574:
	if ( ++p == pe )
		goto _test_eof574;
case 574:
	switch( (*p) ) {
		case 9: goto tr640;
		case 10: goto tr641;
		case 59: goto st549;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st574;
	goto tr698;
tr629:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st575;
st575:
	if ( ++p == pe )
		goto _test_eof575;
case 575:
#line 11045 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr640;
		case 10: goto tr641;
		case 59: goto st549;
		case 61: goto st554;
		case 81: goto st576;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st535;
	goto tr623;
st576:
	if ( ++p == pe )
		goto _test_eof576;
case 576:
	if ( (*p) == 61 )
		goto st577;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto st535;
	} else if ( (*p) >= 33 )
		goto st535;
	goto tr623;
st577:
	if ( ++p == pe )
		goto _test_eof577;
case 577:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st578;
	goto tr702;
st578:
	if ( ++p == pe )
		goto _test_eof578;
case 578:
	switch( (*p) ) {
		case 9: goto tr640;
		case 10: goto tr641;
		case 46: goto st579;
		case 59: goto st549;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st578;
	goto tr702;
st579:
	if ( ++p == pe )
		goto _test_eof579;
case 579:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st580;
	goto tr702;
st580:
	if ( ++p == pe )
		goto _test_eof580;
case 580:
	switch( (*p) ) {
		case 9: goto tr640;
		case 10: goto tr641;
		case 59: goto st549;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st580;
	goto tr702;
tr630:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st581;
st581:
	if ( ++p == pe )
		goto _test_eof581;
case 581:
#line 11117 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr640;
		case 10: goto tr641;
		case 59: goto st549;
		case 61: goto st554;
		case 73: goto st582;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st535;
	goto tr623;
st582:
	if ( ++p == pe )
		goto _test_eof582;
case 582:
	switch( (*p) ) {
		case 9: goto tr640;
		case 10: goto tr641;
		case 59: goto st549;
		case 61: goto st554;
		case 71: goto st583;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st535;
	goto tr623;
st583:
	if ( ++p == pe )
		goto _test_eof583;
case 583:
	switch( (*p) ) {
		case 9: goto tr640;
		case 10: goto tr641;
		case 59: goto st549;
		case 61: goto st554;
		case 65: goto st584;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st535;
	goto tr623;
st584:
	if ( ++p == pe )
		goto _test_eof584;
case 584:
	switch( (*p) ) {
		case 9: goto tr640;
		case 10: goto tr641;
		case 59: goto st549;
		case 61: goto st554;
		case 82: goto st585;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st535;
	goto tr623;
st585:
	if ( ++p == pe )
		goto _test_eof585;
case 585:
	if ( (*p) == 61 )
		goto st586;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto st535;
	} else if ( (*p) >= 33 )
		goto st535;
	goto tr623;
st586:
	if ( ++p == pe )
		goto _test_eof586;
case 586:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st587;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st587;
	} else
		goto st587;
	goto tr711;
st587:
	if ( ++p == pe )
		goto _test_eof587;
case 587:
	switch( (*p) ) {
		case 9: goto tr640;
		case 10: goto tr641;
		case 59: goto st549;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st587;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st587;
	} else
		goto st587;
	goto tr711;
tr631:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st588;
st588:
	if ( ++p == pe )
		goto _test_eof588;
case 588:
#line 11223 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr640;
		case 10: goto tr641;
		case 59: goto st549;
		case 61: goto st554;
		case 66: goto st589;
		case 80: goto st592;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st535;
	goto tr623;
st589:
	if ( ++p == pe )
		goto _test_eof589;
case 589:
	switch( (*p) ) {
		case 9: goto tr640;
		case 10: goto tr641;
		case 59: goto st549;
		case 61: goto st590;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st535;
	goto tr715;
st590:
	if ( ++p == pe )
		goto _test_eof590;
case 590:
	if ( 48 <= (*p) && (*p) <= 49 )
		goto st591;
	goto tr715;
st591:
	if ( ++p == pe )
		goto _test_eof591;
case 591:
	switch( (*p) ) {
		case 9: goto tr640;
		case 10: goto tr641;
		case 59: goto st549;
	}
	goto tr715;
st592:
	if ( ++p == pe )
		goto _test_eof592;
case 592:
	if ( (*p) == 61 )
		goto st593;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto st535;
	} else if ( (*p) >= 33 )
		goto st535;
	goto tr623;
st593:
	if ( ++p == pe )
		goto _test_eof593;
case 593:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st594;
	goto tr719;
st594:
	if ( ++p == pe )
		goto _test_eof594;
case 594:
	switch( (*p) ) {
		case 9: goto tr640;
		case 10: goto tr641;
		case 59: goto st549;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st594;
	goto tr719;
tr632:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st595;
st595:
	if ( ++p == pe )
		goto _test_eof595;
case 595:
#line 11306 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr640;
		case 10: goto tr641;
		case 59: goto st549;
		case 61: goto st554;
		case 78: goto st596;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st535;
	goto tr623;
st596:
	if ( ++p == pe )
		goto _test_eof596;
case 596:
	switch( (*p) ) {
		case 9: goto tr640;
		case 10: goto tr641;
		case 59: goto st549;
		case 61: goto st554;
		case 68: goto st597;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st535;
	goto tr623;
st597:
	if ( ++p == pe )
		goto _test_eof597;
case 597:
	if ( (*p) == 61 )
		goto st598;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto st535;
	} else if ( (*p) >= 33 )
		goto st535;
	goto tr623;
st598:
	if ( ++p == pe )
		goto _test_eof598;
case 598:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st599;
	goto tr724;
st599:
	if ( ++p == pe )
		goto _test_eof599;
case 599:
	switch( (*p) ) {
		case 9: goto tr640;
		case 10: goto tr641;
		case 59: goto st549;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st599;
	goto tr724;
tr633:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st600;
st600:
	if ( ++p == pe )
		goto _test_eof600;
case 600:
#line 11372 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr640;
		case 10: goto tr641;
		case 50: goto st601;
		case 51: goto st604;
		case 59: goto st549;
		case 61: goto st554;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st535;
	goto tr623;
st601:
	if ( ++p == pe )
		goto _test_eof601;
case 601:
	switch( (*p) ) {
		case 9: goto tr640;
		case 10: goto tr641;
		case 59: goto st549;
		case 61: goto st602;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st535;
	goto tr728;
st602:
	if ( ++p == pe )
		goto _test_eof602;
case 602:
	if ( 48 <= (*p) && (*p) <= 49 )
		goto st603;
	goto tr728;
st603:
	if ( ++p == pe )
		goto _test_eof603;
case 603:
	switch( (*p) ) {
		case 9: goto tr640;
		case 10: goto tr641;
		case 59: goto st549;
	}
	goto tr728;
st604:
	if ( ++p == pe )
		goto _test_eof604;
case 604:
	switch( (*p) ) {
		case 9: goto tr640;
		case 10: goto tr641;
		case 59: goto st549;
		case 61: goto st605;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st535;
	goto tr731;
st605:
	if ( ++p == pe )
		goto _test_eof605;
case 605:
	if ( 48 <= (*p) && (*p) <= 49 )
		goto st606;
	goto tr731;
st606:
	if ( ++p == pe )
		goto _test_eof606;
case 606:
	switch( (*p) ) {
		case 9: goto tr640;
		case 10: goto tr641;
		case 59: goto st549;
	}
	goto tr731;
tr634:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st607;
st607:
	if ( ++p == pe )
		goto _test_eof607;
case 607:
#line 11454 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr640;
		case 10: goto tr641;
		case 59: goto st549;
		case 61: goto st554;
		case 81: goto st608;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st535;
	goto tr623;
st608:
	if ( ++p == pe )
		goto _test_eof608;
case 608:
	switch( (*p) ) {
		case 48: goto st609;
		case 61: goto st612;
	}
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto st535;
	} else if ( (*p) >= 33 )
		goto st535;
	goto tr623;
st609:
	if ( ++p == pe )
		goto _test_eof609;
case 609:
	if ( (*p) == 61 )
		goto st610;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto st535;
	} else if ( (*p) >= 33 )
		goto st535;
	goto tr623;
st610:
	if ( ++p == pe )
		goto _test_eof610;
case 610:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st611;
	goto tr738;
st611:
	if ( ++p == pe )
		goto _test_eof611;
case 611:
	switch( (*p) ) {
		case 9: goto tr640;
		case 10: goto tr641;
		case 59: goto st549;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st611;
	goto tr738;
st612:
	if ( ++p == pe )
		goto _test_eof612;
case 612:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st613;
	goto tr740;
st613:
	if ( ++p == pe )
		goto _test_eof613;
case 613:
	switch( (*p) ) {
		case 9: goto tr640;
		case 10: goto tr641;
		case 46: goto st614;
		case 59: goto st549;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st613;
	goto tr740;
st614:
	if ( ++p == pe )
		goto _test_eof614;
case 614:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st615;
	goto tr740;
st615:
	if ( ++p == pe )
		goto _test_eof615;
case 615:
	switch( (*p) ) {
		case 9: goto tr640;
		case 10: goto tr641;
		case 59: goto st549;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st615;
	goto tr740;
tr635:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st616;
st616:
	if ( ++p == pe )
		goto _test_eof616;
case 616:
#line 11559 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr640;
		case 10: goto tr641;
		case 59: goto st549;
		case 61: goto st554;
		case 83: goto st617;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st535;
	goto tr623;
st617:
	if ( ++p == pe )
		goto _test_eof617;
case 617:
	if ( (*p) == 61 )
		goto st618;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto st535;
	} else if ( (*p) >= 33 )
		goto st535;
	goto tr623;
st618:
	if ( ++p == pe )
		goto _test_eof618;
case 618:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st619;
	goto tr746;
st619:
	if ( ++p == pe )
		goto _test_eof619;
case 619:
	switch( (*p) ) {
		case 9: goto tr640;
		case 10: goto tr641;
		case 59: goto st549;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st619;
	goto tr746;
tr636:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st620;
st620:
	if ( ++p == pe )
		goto _test_eof620;
case 620:
#line 11611 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr640;
		case 10: goto tr641;
		case 59: goto st549;
		case 61: goto st554;
		case 66: goto st621;
		case 79: goto st626;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st535;
	goto tr623;
st621:
	if ( ++p == pe )
		goto _test_eof621;
case 621:
	if ( (*p) == 61 )
		goto st622;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto st535;
	} else if ( (*p) >= 33 )
		goto st535;
	goto tr623;
st622:
	if ( ++p == pe )
		goto _test_eof622;
case 622:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st623;
	goto tr751;
st623:
	if ( ++p == pe )
		goto _test_eof623;
case 623:
	switch( (*p) ) {
		case 9: goto tr640;
		case 10: goto tr641;
		case 46: goto st624;
		case 59: goto st549;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st623;
	goto tr751;
st624:
	if ( ++p == pe )
		goto _test_eof624;
case 624:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st625;
	goto tr751;
st625:
	if ( ++p == pe )
		goto _test_eof625;
case 625:
	switch( (*p) ) {
		case 9: goto tr640;
		case 10: goto tr641;
		case 59: goto st549;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st625;
	goto tr751;
st626:
	if ( ++p == pe )
		goto _test_eof626;
case 626:
	switch( (*p) ) {
		case 9: goto tr640;
		case 10: goto tr641;
		case 59: goto st549;
		case 61: goto st554;
		case 77: goto st627;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st535;
	goto tr623;
st627:
	if ( ++p == pe )
		goto _test_eof627;
case 627:
	switch( (*p) ) {
		case 9: goto tr640;
		case 10: goto tr641;
		case 59: goto st549;
		case 61: goto st554;
		case 65: goto st628;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st535;
	goto tr623;
st628:
	if ( ++p == pe )
		goto _test_eof628;
case 628:
	switch( (*p) ) {
		case 9: goto tr640;
		case 10: goto tr641;
		case 59: goto st549;
		case 61: goto st554;
		case 84: goto st629;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st535;
	goto tr623;
st629:
	if ( ++p == pe )
		goto _test_eof629;
case 629:
	switch( (*p) ) {
		case 9: goto tr640;
		case 10: goto tr641;
		case 59: goto st549;
		case 61: goto st554;
		case 73: goto st630;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st535;
	goto tr623;
st630:
	if ( ++p == pe )
		goto _test_eof630;
case 630:
	switch( (*p) ) {
		case 9: goto tr640;
		case 10: goto tr641;
		case 59: goto st549;
		case 61: goto st554;
		case 67: goto st631;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st535;
	goto tr623;
st631:
	if ( ++p == pe )
		goto _test_eof631;
case 631:
	switch( (*p) ) {
		case 9: goto tr640;
		case 10: goto tr641;
		case 59: goto st549;
		case 61: goto st632;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st535;
	goto tr760;
st632:
	if ( ++p == pe )
		goto _test_eof632;
case 632:
	if ( 48 <= (*p) && (*p) <= 49 )
		goto st633;
	goto tr760;
st633:
	if ( ++p == pe )
		goto _test_eof633;
case 633:
	switch( (*p) ) {
		case 9: goto tr640;
		case 10: goto tr641;
		case 59: goto st549;
	}
	goto tr760;
tr637:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st634;
st634:
	if ( ++p == pe )
		goto _test_eof634;
case 634:
#line 11784 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr640;
		case 10: goto tr641;
		case 59: goto st549;
		case 61: goto st554;
		case 65: goto st635;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st535;
	goto tr623;
st635:
	if ( ++p == pe )
		goto _test_eof635;
case 635:
	switch( (*p) ) {
		case 9: goto tr640;
		case 10: goto tr641;
		case 59: goto st549;
		case 61: goto st554;
		case 76: goto st636;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st535;
	goto tr623;
st636:
	if ( ++p == pe )
		goto _test_eof636;
case 636:
	switch( (*p) ) {
		case 9: goto tr640;
		case 10: goto tr641;
		case 59: goto st549;
		case 61: goto st554;
		case 73: goto st637;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st535;
	goto tr623;
st637:
	if ( ++p == pe )
		goto _test_eof637;
case 637:
	switch( (*p) ) {
		case 9: goto tr640;
		case 10: goto tr641;
		case 59: goto st549;
		case 61: goto st554;
		case 68: goto st638;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st535;
	goto tr623;
st638:
	if ( ++p == pe )
		goto _test_eof638;
case 638:
	switch( (*p) ) {
		case 9: goto tr640;
		case 10: goto tr641;
		case 59: goto st549;
		case 61: goto st554;
		case 65: goto st639;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st535;
	goto tr623;
st639:
	if ( ++p == pe )
		goto _test_eof639;
case 639:
	switch( (*p) ) {
		case 9: goto tr640;
		case 10: goto tr641;
		case 59: goto st549;
		case 61: goto st554;
		case 84: goto st640;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st535;
	goto tr623;
st640:
	if ( ++p == pe )
		goto _test_eof640;
case 640:
	switch( (*p) ) {
		case 9: goto tr640;
		case 10: goto tr641;
		case 59: goto st549;
		case 61: goto st554;
		case 69: goto st641;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st535;
	goto tr623;
st641:
	if ( ++p == pe )
		goto _test_eof641;
case 641:
	switch( (*p) ) {
		case 9: goto tr640;
		case 10: goto tr641;
		case 59: goto st549;
		case 61: goto st554;
		case 68: goto st642;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st535;
	goto tr623;
st642:
	if ( ++p == pe )
		goto _test_eof642;
case 642:
	switch( (*p) ) {
		case 9: goto tr640;
		case 10: goto tr641;
		case 59: goto st549;
		case 61: goto st643;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st535;
	goto tr771;
st643:
	if ( ++p == pe )
		goto _test_eof643;
case 643:
	if ( 48 <= (*p) && (*p) <= 49 )
		goto st644;
	goto tr771;
st644:
	if ( ++p == pe )
		goto _test_eof644;
case 644:
	switch( (*p) ) {
		case 9: goto tr640;
		case 10: goto tr641;
		case 59: goto st549;
	}
	goto tr771;
tr625:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st645;
st645:
	if ( ++p == pe )
		goto _test_eof645;
case 645:
#line 11933 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr640;
		case 10: goto tr641;
		case 58: goto st534;
		case 60: goto st534;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto st534;
		} else if ( (*p) > 57 ) {
			if ( 62 <= (*p) && (*p) <= 64 )
				goto st534;
		} else
			goto st535;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st534;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st534;
		} else
			goto st535;
	} else
		goto st535;
	goto tr623;
tr618:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st646;
st646:
	if ( ++p == pe )
		goto _test_eof646;
case 646:
#line 11971 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr622;
		case 58: goto st531;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto st531;
		} else if ( (*p) > 57 ) {
			if ( 60 <= (*p) && (*p) <= 64 )
				goto st531;
		} else
			goto st532;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st531;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st531;
		} else
			goto st532;
	} else
		goto st532;
	goto tr616;
tr614:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st647;
st647:
	if ( ++p == pe )
		goto _test_eof647;
case 647:
#line 12007 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr615;
		case 46: goto st648;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st647;
	goto tr612;
st648:
	if ( ++p == pe )
		goto _test_eof648;
case 648:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st649;
	goto tr612;
st649:
	if ( ++p == pe )
		goto _test_eof649;
case 649:
	if ( (*p) == 9 )
		goto tr615;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st649;
	goto tr612;
tr605:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st650;
st650:
	if ( ++p == pe )
		goto _test_eof650;
case 650:
#line 12041 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr777;
		case 65: goto st651;
		case 67: goto st651;
		case 71: goto st651;
		case 78: goto st651;
		case 84: goto st651;
		case 97: goto st651;
		case 99: goto st651;
		case 103: goto st651;
		case 110: goto st651;
		case 116: goto st651;
	}
	goto tr603;
st651:
	if ( ++p == pe )
		goto _test_eof651;
case 651:
	switch( (*p) ) {
		case 9: goto tr779;
		case 65: goto st651;
		case 67: goto st651;
		case 71: goto st651;
		case 78: goto st651;
		case 84: goto st651;
		case 97: goto st651;
		case 99: goto st651;
		case 103: goto st651;
		case 110: goto st651;
		case 116: goto st651;
	}
	goto tr603;
tr606:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st652;
st652:
	if ( ++p == pe )
		goto _test_eof652;
case 652:
#line 12084 "vcf_validator_detail.hpp"
	if ( (*p) == 9 )
		goto tr777;
	goto tr603;
tr607:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st653;
st653:
	if ( ++p == pe )
		goto _test_eof653;
case 653:
#line 12098 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 67: goto st657;
		case 68: goto st660;
		case 73: goto st677;
		case 95: goto st654;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st654;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st655;
		} else if ( (*p) >= 65 )
			goto st655;
	} else
		goto st655;
	goto tr603;
st654:
	if ( ++p == pe )
		goto _test_eof654;
case 654:
	if ( (*p) == 95 )
		goto st654;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st654;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st655;
		} else if ( (*p) >= 65 )
			goto st655;
	} else
		goto st655;
	goto tr603;
st655:
	if ( ++p == pe )
		goto _test_eof655;
case 655:
	switch( (*p) ) {
		case 62: goto st656;
		case 95: goto st655;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st655;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st655;
		} else if ( (*p) >= 65 )
			goto st655;
	} else
		goto st655;
	goto tr603;
st656:
	if ( ++p == pe )
		goto _test_eof656;
case 656:
	if ( (*p) == 9 )
		goto tr786;
	goto tr603;
st657:
	if ( ++p == pe )
		goto _test_eof657;
case 657:
	switch( (*p) ) {
		case 62: goto st656;
		case 78: goto st658;
		case 95: goto st655;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st655;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st655;
		} else if ( (*p) >= 65 )
			goto st655;
	} else
		goto st655;
	goto tr603;
st658:
	if ( ++p == pe )
		goto _test_eof658;
case 658:
	switch( (*p) ) {
		case 62: goto st656;
		case 86: goto st659;
		case 95: goto st655;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st655;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st655;
		} else if ( (*p) >= 65 )
			goto st655;
	} else
		goto st655;
	goto tr603;
st659:
	if ( ++p == pe )
		goto _test_eof659;
case 659:
	switch( (*p) ) {
		case 62: goto st527;
		case 95: goto st655;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st655;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st655;
		} else if ( (*p) >= 65 )
			goto st655;
	} else
		goto st655;
	goto tr603;
st660:
	if ( ++p == pe )
		goto _test_eof660;
case 660:
	switch( (*p) ) {
		case 62: goto st656;
		case 69: goto st661;
		case 85: goto st668;
		case 95: goto st655;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st655;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st655;
		} else if ( (*p) >= 65 )
			goto st655;
	} else
		goto st655;
	goto tr603;
st661:
	if ( ++p == pe )
		goto _test_eof661;
case 661:
	switch( (*p) ) {
		case 62: goto st656;
		case 76: goto st662;
		case 95: goto st655;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st655;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st655;
		} else if ( (*p) >= 65 )
			goto st655;
	} else
		goto st655;
	goto tr603;
st662:
	if ( ++p == pe )
		goto _test_eof662;
case 662:
	switch( (*p) ) {
		case 58: goto st663;
		case 62: goto st527;
		case 95: goto st655;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st655;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st655;
		} else if ( (*p) >= 65 )
			goto st655;
	} else
		goto st655;
	goto tr603;
st663:
	if ( ++p == pe )
		goto _test_eof663;
case 663:
	if ( (*p) == 77 )
		goto st664;
	goto tr603;
st664:
	if ( ++p == pe )
		goto _test_eof664;
case 664:
	if ( (*p) == 69 )
		goto st665;
	goto tr603;
st665:
	if ( ++p == pe )
		goto _test_eof665;
case 665:
	if ( (*p) == 58 )
		goto st666;
	goto tr603;
st666:
	if ( ++p == pe )
		goto _test_eof666;
case 666:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st667;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st667;
	} else
		goto st667;
	goto tr603;
st667:
	if ( ++p == pe )
		goto _test_eof667;
case 667:
	if ( (*p) == 62 )
		goto st527;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st667;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st667;
	} else
		goto st667;
	goto tr603;
st668:
	if ( ++p == pe )
		goto _test_eof668;
case 668:
	switch( (*p) ) {
		case 62: goto st656;
		case 80: goto st669;
		case 95: goto st655;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st655;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st655;
		} else if ( (*p) >= 65 )
			goto st655;
	} else
		goto st655;
	goto tr603;
st669:
	if ( ++p == pe )
		goto _test_eof669;
case 669:
	switch( (*p) ) {
		case 58: goto st670;
		case 62: goto st527;
		case 95: goto st655;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st655;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st655;
		} else if ( (*p) >= 65 )
			goto st655;
	} else
		goto st655;
	goto tr603;
st670:
	if ( ++p == pe )
		goto _test_eof670;
case 670:
	if ( (*p) == 84 )
		goto st671;
	goto tr603;
st671:
	if ( ++p == pe )
		goto _test_eof671;
case 671:
	if ( (*p) == 65 )
		goto st672;
	goto tr603;
st672:
	if ( ++p == pe )
		goto _test_eof672;
case 672:
	if ( (*p) == 78 )
		goto st673;
	goto tr603;
st673:
	if ( ++p == pe )
		goto _test_eof673;
case 673:
	if ( (*p) == 68 )
		goto st674;
	goto tr603;
st674:
	if ( ++p == pe )
		goto _test_eof674;
case 674:
	if ( (*p) == 69 )
		goto st675;
	goto tr603;
st675:
	if ( ++p == pe )
		goto _test_eof675;
case 675:
	if ( (*p) == 77 )
		goto st676;
	goto tr603;
st676:
	if ( ++p == pe )
		goto _test_eof676;
case 676:
	if ( (*p) == 62 )
		goto st527;
	goto tr603;
st677:
	if ( ++p == pe )
		goto _test_eof677;
case 677:
	switch( (*p) ) {
		case 62: goto st656;
		case 78: goto st678;
		case 95: goto st655;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st655;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st655;
		} else if ( (*p) >= 65 )
			goto st655;
	} else
		goto st655;
	goto tr603;
st678:
	if ( ++p == pe )
		goto _test_eof678;
case 678:
	switch( (*p) ) {
		case 62: goto st656;
		case 83: goto st662;
		case 86: goto st659;
		case 95: goto st655;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st655;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st655;
		} else if ( (*p) >= 65 )
			goto st655;
	} else
		goto st655;
	goto tr603;
tr608:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st679;
st679:
	if ( ++p == pe )
		goto _test_eof679;
case 679:
#line 12481 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr777;
		case 44: goto st680;
		case 46: goto st682;
		case 65: goto st679;
		case 67: goto st679;
		case 71: goto st679;
		case 78: goto st679;
		case 84: goto st679;
		case 91: goto st683;
		case 93: goto st690;
		case 97: goto st679;
		case 99: goto st679;
		case 103: goto st679;
		case 110: goto st679;
		case 116: goto st679;
	}
	goto tr603;
st680:
	if ( ++p == pe )
		goto _test_eof680;
case 680:
	switch( (*p) ) {
		case 65: goto st681;
		case 67: goto st681;
		case 71: goto st681;
		case 78: goto st681;
		case 84: goto st681;
		case 97: goto st681;
		case 99: goto st681;
		case 103: goto st681;
		case 110: goto st681;
		case 116: goto st681;
	}
	goto tr603;
st681:
	if ( ++p == pe )
		goto _test_eof681;
case 681:
	switch( (*p) ) {
		case 9: goto tr777;
		case 44: goto st680;
		case 65: goto st681;
		case 67: goto st681;
		case 71: goto st681;
		case 78: goto st681;
		case 84: goto st681;
		case 97: goto st681;
		case 99: goto st681;
		case 103: goto st681;
		case 110: goto st681;
		case 116: goto st681;
	}
	goto tr603;
st682:
	if ( ++p == pe )
		goto _test_eof682;
case 682:
	if ( (*p) == 9 )
		goto tr779;
	goto tr603;
st683:
	if ( ++p == pe )
		goto _test_eof683;
case 683:
	if ( (*p) == 60 )
		goto st687;
	if ( (*p) < 59 ) {
		if ( 33 <= (*p) && (*p) <= 57 )
			goto st684;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto st684;
	} else
		goto st684;
	goto tr603;
st684:
	if ( ++p == pe )
		goto _test_eof684;
case 684:
	switch( (*p) ) {
		case 58: goto st685;
		case 61: goto st684;
	}
	if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto st684;
	} else if ( (*p) >= 33 )
		goto st684;
	goto tr603;
st685:
	if ( ++p == pe )
		goto _test_eof685;
case 685:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st686;
	goto tr603;
st686:
	if ( ++p == pe )
		goto _test_eof686;
case 686:
	if ( (*p) == 91 )
		goto st682;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st686;
	goto tr603;
st687:
	if ( ++p == pe )
		goto _test_eof687;
case 687:
	if ( (*p) < 59 ) {
		if ( 33 <= (*p) && (*p) <= 57 )
			goto st688;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto st688;
	} else
		goto st688;
	goto tr603;
st688:
	if ( ++p == pe )
		goto _test_eof688;
case 688:
	if ( (*p) == 62 )
		goto st689;
	if ( (*p) > 57 ) {
		if ( 59 <= (*p) && (*p) <= 126 )
			goto st688;
	} else if ( (*p) >= 33 )
		goto st688;
	goto tr603;
st689:
	if ( ++p == pe )
		goto _test_eof689;
case 689:
	if ( (*p) == 58 )
		goto st685;
	goto tr603;
st690:
	if ( ++p == pe )
		goto _test_eof690;
case 690:
	if ( (*p) == 60 )
		goto st694;
	if ( (*p) < 59 ) {
		if ( 33 <= (*p) && (*p) <= 57 )
			goto st691;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto st691;
	} else
		goto st691;
	goto tr603;
st691:
	if ( ++p == pe )
		goto _test_eof691;
case 691:
	switch( (*p) ) {
		case 58: goto st692;
		case 61: goto st691;
	}
	if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto st691;
	} else if ( (*p) >= 33 )
		goto st691;
	goto tr603;
st692:
	if ( ++p == pe )
		goto _test_eof692;
case 692:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st693;
	goto tr603;
st693:
	if ( ++p == pe )
		goto _test_eof693;
case 693:
	if ( (*p) == 93 )
		goto st682;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st693;
	goto tr603;
st694:
	if ( ++p == pe )
		goto _test_eof694;
case 694:
	if ( (*p) < 59 ) {
		if ( 33 <= (*p) && (*p) <= 57 )
			goto st695;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto st695;
	} else
		goto st695;
	goto tr603;
st695:
	if ( ++p == pe )
		goto _test_eof695;
case 695:
	if ( (*p) == 62 )
		goto st696;
	if ( (*p) > 57 ) {
		if ( 59 <= (*p) && (*p) <= 126 )
			goto st695;
	} else if ( (*p) >= 33 )
		goto st695;
	goto tr603;
st696:
	if ( ++p == pe )
		goto _test_eof696;
case 696:
	if ( (*p) == 58 )
		goto st692;
	goto tr603;
tr609:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st697;
st697:
	if ( ++p == pe )
		goto _test_eof697;
case 697:
#line 12707 "vcf_validator_detail.hpp"
	if ( (*p) == 60 )
		goto st702;
	if ( (*p) < 59 ) {
		if ( 33 <= (*p) && (*p) <= 57 )
			goto st698;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto st698;
	} else
		goto st698;
	goto tr603;
st698:
	if ( ++p == pe )
		goto _test_eof698;
case 698:
	switch( (*p) ) {
		case 58: goto st699;
		case 61: goto st698;
	}
	if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto st698;
	} else if ( (*p) >= 33 )
		goto st698;
	goto tr603;
st699:
	if ( ++p == pe )
		goto _test_eof699;
case 699:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st700;
	goto tr603;
st700:
	if ( ++p == pe )
		goto _test_eof700;
case 700:
	if ( (*p) == 91 )
		goto st701;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st700;
	goto tr603;
st701:
	if ( ++p == pe )
		goto _test_eof701;
case 701:
	switch( (*p) ) {
		case 65: goto st651;
		case 67: goto st651;
		case 71: goto st651;
		case 78: goto st651;
		case 84: goto st651;
		case 97: goto st651;
		case 99: goto st651;
		case 103: goto st651;
		case 110: goto st651;
		case 116: goto st651;
	}
	goto tr603;
st702:
	if ( ++p == pe )
		goto _test_eof702;
case 702:
	if ( (*p) < 59 ) {
		if ( 33 <= (*p) && (*p) <= 57 )
			goto st703;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto st703;
	} else
		goto st703;
	goto tr603;
st703:
	if ( ++p == pe )
		goto _test_eof703;
case 703:
	if ( (*p) == 62 )
		goto st704;
	if ( (*p) > 57 ) {
		if ( 59 <= (*p) && (*p) <= 126 )
			goto st703;
	} else if ( (*p) >= 33 )
		goto st703;
	goto tr603;
st704:
	if ( ++p == pe )
		goto _test_eof704;
case 704:
	if ( (*p) == 58 )
		goto st699;
	goto tr603;
tr610:
#line 15 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st705;
st705:
	if ( ++p == pe )
		goto _test_eof705;
case 705:
#line 12808 "vcf_validator_detail.hpp"
	if ( (*p) == 60 )
		goto st709;
	if ( (*p) < 59 ) {
		if ( 33 <= (*p) && (*p) <= 57 )
			goto st706;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto st706;
	} else
		goto st706;
	goto tr603;
st706:
	if ( ++p == pe )
		goto _test_eof706;
case 706:
	switch( (*p) ) {
		case 58: goto st707;
		case 61: goto st706;
	}
	if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto st706;
	} else if ( (*p) >= 33 )
		goto st706;
	goto tr603;
st707:
	if ( ++p == pe )
		goto _test_eof707;
case 707:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st708;
	goto tr603;
st708:
	if ( ++p == pe )
		goto _test_eof708;
case 708:
	if ( (*p) == 93 )
		goto st701;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st708;
	goto tr603;
st709:
	if ( ++p == pe )
		goto _test_eof709;
case 709:
	if ( (*p) < 59 ) {
		if ( 33 <= (*p) && (*p) <= 57 )
			goto st710;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto st710;
	} else
		goto st710;
	goto tr603;
st710:
	if ( ++p == pe )
		goto _test_eof710;
case 710:
	if ( (*p) == 62 )
		goto st711;
	if ( (*p) > 57 ) {
		if ( 59 <= (*p) && (*p) <= 126 )
			goto st710;
	} else if ( (*p) >= 33 )
		goto st710;
	goto tr603;
st711:
	if ( ++p == pe )
		goto _test_eof711;
case 711:
	if ( (*p) == 58 )
		goto st707;
	goto tr603;
st712:
	if ( ++p == pe )
		goto _test_eof712;
case 712:
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto st523;
	} else if ( (*p) >= 33 )
		goto st523;
	goto tr594;
st713:
	if ( ++p == pe )
		goto _test_eof713;
case 713:
	if ( (*p) == 10 )
		goto tr839;
	goto st713;
tr839:
#line 23 "vcf_v41.ragel"
	{
        ++n_lines;
        n_columns = 1;
    }
#line 707 "vcf_v41.ragel"
	{ {goto st20;} }
	goto st717;
st717:
	if ( ++p == pe )
		goto _test_eof717;
case 717:
#line 12912 "vcf_validator_detail.hpp"
	goto st0;
st714:
	if ( ++p == pe )
		goto _test_eof714;
case 714:
	if ( (*p) == 10 )
		goto tr841;
	goto st714;
tr841:
#line 23 "vcf_v41.ragel"
	{
        ++n_lines;
        n_columns = 1;
    }
#line 708 "vcf_v41.ragel"
	{ {goto st716;} }
	goto st718;
st718:
	if ( ++p == pe )
		goto _test_eof718;
case 718:
#line 12934 "vcf_validator_detail.hpp"
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
	_test_eof715: cs = 715; goto _test_eof; 
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
	_test_eof716: cs = 716; goto _test_eof; 
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
	_test_eof717: cs = 717; goto _test_eof; 
	_test_eof714: cs = 714; goto _test_eof; 
	_test_eof718: cs = 718; goto _test_eof; 

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
        p--; {goto st713;}
    }
	break;
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
#line 45 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        p--; {goto st714;}
    }
	break;
	case 14: 
	case 15: 
#line 211 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this,
            "Fileformat is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st713;}
    }
#line 35 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this);
        p--; {goto st713;}
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
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	break;
	case 436: 
	case 437: 
	case 438: 
	case 439: 
	case 442: 
	case 443: 
	case 444: 
	case 445: 
#line 240 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in contig metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	break;
	case 175: 
	case 176: 
	case 177: 
	case 178: 
	case 181: 
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
	case 197: 
#line 246 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	break;
	case 203: 
	case 204: 
	case 205: 
	case 206: 
	case 209: 
	case 210: 
	case 211: 
	case 212: 
	case 213: 
	case 214: 
	case 215: 
	case 218: 
	case 219: 
	case 220: 
	case 221: 
	case 222: 
	case 233: 
	case 234: 
	case 235: 
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
	case 249: 
#line 252 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	break;
	case 268: 
	case 269: 
	case 270: 
	case 271: 
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
	case 310: 
	case 311: 
	case 337: 
#line 268 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	break;
	case 360: 
	case 365: 
#line 294 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in PEDIGREE metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	break;
	case 464: 
#line 300 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in pedigreeDB metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	break;
	case 372: 
	case 373: 
	case 374: 
	case 375: 
	case 414: 
#line 306 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	break;
	case 19: 
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
#line 322 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	break;
	case 519: 
	case 541: 
	case 542: 
	case 543: 
#line 345 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Chromosome is not a string without colons or whitespaces, optionally wrapped with angle brackets (<>)");
        p--; {goto st714;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st714;}
    }
	break;
	case 520: 
	case 521: 
#line 351 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Position is not a positive number");
        p--; {goto st714;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st714;}
    }
	break;
	case 522: 
	case 523: 
	case 712: 
#line 357 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "ID is not a single dot or a list of strings without semicolons or whitespaces");
        p--; {goto st714;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st714;}
    }
	break;
	case 524: 
	case 525: 
#line 363 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Reference is not a string of bases");
        p--; {goto st714;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st714;}
    }
	break;
	case 526: 
	case 527: 
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
	case 706: 
	case 707: 
	case 708: 
	case 709: 
	case 710: 
	case 711: 
#line 369 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Alternate is not a single dot or a comma-separated list of bases");
        p--; {goto st714;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st714;}
    }
	break;
	case 528: 
	case 529: 
	case 647: 
	case 648: 
	case 649: 
#line 375 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Quality is not a single dot or a positive number");
        p--; {goto st714;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st714;}
    }
	break;
	case 530: 
	case 531: 
	case 532: 
	case 646: 
#line 381 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Filter is not a single dot or a semicolon-separated list of strings");
        p--; {goto st714;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st714;}
    }
	break;
	case 533: 
	case 534: 
	case 535: 
	case 549: 
	case 550: 
	case 551: 
	case 552: 
	case 553: 
	case 554: 
	case 555: 
	case 559: 
	case 560: 
	case 564: 
	case 567: 
	case 572: 
	case 575: 
	case 576: 
	case 581: 
	case 582: 
	case 583: 
	case 584: 
	case 585: 
	case 588: 
	case 592: 
	case 595: 
	case 596: 
	case 597: 
	case 600: 
	case 607: 
	case 608: 
	case 609: 
	case 616: 
	case 617: 
	case 620: 
	case 621: 
	case 626: 
	case 627: 
	case 628: 
	case 629: 
	case 630: 
	case 634: 
	case 635: 
	case 636: 
	case 637: 
	case 638: 
	case 639: 
	case 640: 
	case 641: 
	case 645: 
#line 387 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st714;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st714;}
    }
	break;
	case 547: 
	case 548: 
#line 487 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Format is not a colon-separated list of alphanumeric strings");
        p--; {goto st714;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st714;}
    }
	break;
	case 545: 
	case 546: 
#line 498 "vcf_v41.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " is not a valid string";
        ErrorPolicy::handle_body_section_error(*this, message_stream.str());
        p--; {goto st714;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st714;}
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
        ErrorPolicy::handle_meta_section_error(*this, "ALT metadata ID does not begin with DEL/INS/DUP/INV/CNV");
        p--; {goto st713;}
    }
#line 218 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
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
        ErrorPolicy::handle_meta_section_error(*this, "ALT metadata ID suffix (after ':') is not valid");
        p--; {goto st713;}
    }
#line 218 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	break;
	case 216: 
	case 217: 
	case 263: 
#line 257 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "FORMAT metadata Number is not a number, A, R, G or dot");
        p--; {goto st713;}
    }
#line 252 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	break;
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
	case 260: 
	case 261: 
	case 262: 
#line 262 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "FORMAT metadata Type is not a Integer, Float, Character or String");
        p--; {goto st713;}
    }
#line 252 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	break;
	case 281: 
	case 282: 
	case 351: 
#line 273 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "INFO metadata Number is not a number, A, R, G or dot");
        p--; {goto st713;}
    }
#line 268 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	break;
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
#line 278 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "INFO metadata Type is not a Integer, Float, Flag, Character or String");
        p--; {goto st713;}
    }
#line 268 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
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
#line 283 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "INFO metadata Source string is not valid");
        p--; {goto st713;}
    }
#line 268 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
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
#line 288 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "INFO metadata Version string is not valid");
        p--; {goto st713;}
    }
#line 268 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	break;
	case 378: 
	case 379: 
	case 380: 
	case 381: 
	case 382: 
	case 383: 
	case 384: 
	case 385: 
	case 386: 
#line 311 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Genomes contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st713;}
    }
#line 306 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	break;
	case 388: 
	case 389: 
	case 390: 
	case 391: 
	case 392: 
	case 393: 
	case 394: 
	case 395: 
	case 396: 
#line 316 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Mixture contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st713;}
    }
#line 306 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	break;
	case 122: 
	case 123: 
	case 124: 
#line 322 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in metadata");
        p--; {goto st713;}
    }
#line 218 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	break;
	case 415: 
	case 416: 
	case 417: 
	case 418: 
	case 419: 
	case 420: 
	case 421: 
	case 422: 
#line 322 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in metadata");
        p--; {goto st713;}
    }
#line 234 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in assembly metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	break;
	case 430: 
	case 431: 
	case 432: 
	case 433: 
	case 434: 
	case 435: 
#line 322 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in metadata");
        p--; {goto st713;}
    }
#line 240 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in contig metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	break;
	case 170: 
	case 171: 
	case 172: 
	case 173: 
	case 174: 
#line 322 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in metadata");
        p--; {goto st713;}
    }
#line 246 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	break;
	case 198: 
	case 199: 
	case 200: 
	case 201: 
	case 202: 
#line 322 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in metadata");
        p--; {goto st713;}
    }
#line 252 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	break;
	case 264: 
	case 265: 
	case 266: 
	case 267: 
#line 322 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in metadata");
        p--; {goto st713;}
    }
#line 268 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
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
#line 322 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in metadata");
        p--; {goto st713;}
    }
#line 294 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in PEDIGREE metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	break;
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
#line 322 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in metadata");
        p--; {goto st713;}
    }
#line 300 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in pedigreeDB metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	break;
	case 366: 
	case 367: 
	case 368: 
	case 369: 
	case 370: 
	case 371: 
#line 322 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in metadata");
        p--; {goto st713;}
    }
#line 306 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	break;
	case 440: 
	case 441: 
#line 327 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st713;}
    }
#line 240 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in contig metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	break;
	case 179: 
	case 180: 
#line 327 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st713;}
    }
#line 246 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	break;
	case 207: 
	case 208: 
#line 327 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st713;}
    }
#line 252 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	break;
	case 272: 
	case 273: 
#line 327 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st713;}
    }
#line 268 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	break;
	case 361: 
	case 362: 
	case 363: 
	case 364: 
#line 327 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st713;}
    }
#line 294 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in PEDIGREE metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	break;
	case 376: 
#line 327 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st713;}
    }
#line 306 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	break;
	case 147: 
	case 148: 
#line 332 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st713;}
    }
#line 218 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	break;
	case 195: 
	case 196: 
#line 332 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st713;}
    }
#line 246 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	break;
	case 247: 
	case 248: 
#line 332 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st713;}
    }
#line 252 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	break;
	case 312: 
#line 332 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st713;}
    }
#line 268 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
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
#line 332 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st713;}
    }
#line 306 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	break;
	case 423: 
	case 424: 
	case 425: 
	case 426: 
	case 427: 
	case 428: 
	case 429: 
#line 337 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata URL is not valid");
        p--; {goto st713;}
    }
#line 234 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in assembly metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	break;
	case 446: 
	case 447: 
	case 448: 
	case 449: 
	case 450: 
	case 451: 
	case 452: 
	case 453: 
#line 337 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata URL is not valid");
        p--; {goto st713;}
    }
#line 240 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in contig metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	break;
	case 465: 
	case 466: 
	case 467: 
	case 468: 
	case 469: 
	case 470: 
	case 471: 
	case 472: 
#line 337 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata URL is not valid");
        p--; {goto st713;}
    }
#line 300 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in pedigreeDB metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	break;
	case 561: 
	case 562: 
	case 563: 
#line 396 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info AA value is not a single dot or a string of bases");
        p--; {goto st714;}
    }
#line 387 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st714;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st714;}
    }
	break;
	case 565: 
	case 566: 
#line 401 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info AC value is not a comma-separated list of numbers");
        p--; {goto st714;}
    }
#line 387 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st714;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st714;}
    }
	break;
	case 568: 
	case 569: 
	case 570: 
	case 571: 
#line 406 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info AF value is not a comma-separated list of numbers");
        p--; {goto st714;}
    }
#line 387 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st714;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st714;}
    }
	break;
	case 573: 
	case 574: 
#line 411 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info AN value is not an integer number");
        p--; {goto st714;}
    }
#line 387 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st714;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st714;}
    }
	break;
	case 577: 
	case 578: 
	case 579: 
	case 580: 
#line 416 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info BQ value is not a number");
        p--; {goto st714;}
    }
#line 387 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st714;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st714;}
    }
	break;
	case 586: 
	case 587: 
#line 421 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info CIGAR value is not an alphanumeric string");
        p--; {goto st714;}
    }
#line 387 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st714;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st714;}
    }
	break;
	case 589: 
	case 590: 
	case 591: 
#line 426 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info DB is not a flag (with 1/0/no value)");
        p--; {goto st714;}
    }
#line 387 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st714;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st714;}
    }
	break;
	case 593: 
	case 594: 
#line 431 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info DP value is not an integer number");
        p--; {goto st714;}
    }
#line 387 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st714;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st714;}
    }
	break;
	case 598: 
	case 599: 
#line 436 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info END value is not an integer number");
        p--; {goto st714;}
    }
#line 387 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st714;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st714;}
    }
	break;
	case 601: 
	case 602: 
	case 603: 
#line 441 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info H2 is not a flag (with 1/0/no value)");
        p--; {goto st714;}
    }
#line 387 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st714;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st714;}
    }
	break;
	case 604: 
	case 605: 
	case 606: 
#line 446 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info H3 is not a flag (with 1/0/no value)");
        p--; {goto st714;}
    }
#line 387 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st714;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st714;}
    }
	break;
	case 612: 
	case 613: 
	case 614: 
	case 615: 
#line 451 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info MQ value is not a number");
        p--; {goto st714;}
    }
#line 387 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st714;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st714;}
    }
	break;
	case 610: 
	case 611: 
#line 456 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info MQ0 value is not an integer number");
        p--; {goto st714;}
    }
#line 387 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st714;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st714;}
    }
	break;
	case 618: 
	case 619: 
#line 461 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info NS value is not an integer number");
        p--; {goto st714;}
    }
#line 387 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st714;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st714;}
    }
	break;
	case 622: 
	case 623: 
	case 624: 
	case 625: 
#line 466 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info SB value is not a number");
        p--; {goto st714;}
    }
#line 387 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st714;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st714;}
    }
	break;
	case 631: 
	case 632: 
	case 633: 
#line 471 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info SOMATIC is not a flag (with 1/0/no value)");
        p--; {goto st714;}
    }
#line 387 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st714;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st714;}
    }
	break;
	case 642: 
	case 643: 
	case 644: 
#line 476 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info VALIDATED is not a flag (with 1/0/no value)");
        p--; {goto st714;}
    }
#line 387 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st714;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st714;}
    }
	break;
	case 556: 
	case 557: 
	case 558: 
#line 481 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info 1000G is not a flag (with 1/0/no value)");
        p--; {goto st714;}
    }
#line 387 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st714;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st714;}
    }
	break;
	case 536: 
	case 537: 
	case 538: 
#line 492 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Format first field is not GT");
        p--; {goto st714;}
    }
#line 487 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Format is not a colon-separated list of alphanumeric strings");
        p--; {goto st714;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st714;}
    }
	break;
	case 539: 
	case 540: 
	case 544: 
#line 505 "vcf_v41.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " does not start with a valid genotype";
        ErrorPolicy::handle_body_section_error(*this, message_stream.str());
        p--; {goto st714;}
    }
#line 498 "vcf_v41.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " is not a valid string";
        ErrorPolicy::handle_body_section_error(*this, message_stream.str());
        p--; {goto st714;}
    }
#line 50 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st714;}
    }
	break;
	case 132: 
#line 223 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "ALT metadata ID does not begin with DEL/INS/DUP/INV/CNV");
        p--; {goto st713;}
    }
#line 228 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "ALT metadata ID suffix (after ':') is not valid");
        p--; {goto st713;}
    }
#line 218 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	break;
	case 314: 
	case 324: 
#line 283 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "INFO metadata Source string is not valid");
        p--; {goto st713;}
    }
#line 288 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "INFO metadata Version string is not valid");
        p--; {goto st713;}
    }
#line 268 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	break;
	case 387: 
#line 311 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Genomes contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st713;}
    }
#line 316 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Mixture contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st713;}
    }
#line 306 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	break;
	case 397: 
#line 316 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Mixture contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st713;}
    }
#line 332 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st713;}
    }
#line 306 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	break;
	case 169: 
#line 322 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in metadata");
        p--; {goto st713;}
    }
#line 246 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st713;}
    }
#line 252 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	break;
	case 377: 
#line 327 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st713;}
    }
#line 311 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Genomes contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st713;}
    }
#line 306 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	break;
	case 313: 
#line 332 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st713;}
    }
#line 283 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "INFO metadata Source string is not valid");
        p--; {goto st713;}
    }
#line 288 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "INFO metadata Version string is not valid");
        p--; {goto st713;}
    }
#line 268 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	break;
	case 18: 
#line 322 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in metadata");
        p--; {goto st713;}
    }
#line 218 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st713;}
    }
#line 246 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st713;}
    }
#line 252 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st713;}
    }
#line 268 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st713;}
    }
#line 234 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in assembly metadata");
        p--; {goto st713;}
    }
#line 240 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in contig metadata");
        p--; {goto st713;}
    }
#line 306 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st713;}
    }
#line 294 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in PEDIGREE metadata");
        p--; {goto st713;}
    }
#line 300 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in pedigreeDB metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
	break;
	case 17: 
	case 20: 
#line 322 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in metadata");
        p--; {goto st713;}
    }
#line 218 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st713;}
    }
#line 246 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st713;}
    }
#line 252 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st713;}
    }
#line 268 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st713;}
    }
#line 234 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in assembly metadata");
        p--; {goto st713;}
    }
#line 240 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in contig metadata");
        p--; {goto st713;}
    }
#line 306 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st713;}
    }
#line 294 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in PEDIGREE metadata");
        p--; {goto st713;}
    }
#line 300 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in pedigreeDB metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
#line 45 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        p--; {goto st714;}
    }
	break;
	case 16: 
#line 35 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this);
        p--; {goto st713;}
    }
#line 322 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in metadata");
        p--; {goto st713;}
    }
#line 218 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st713;}
    }
#line 246 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st713;}
    }
#line 252 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st713;}
    }
#line 268 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st713;}
    }
#line 234 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in assembly metadata");
        p--; {goto st713;}
    }
#line 240 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in contig metadata");
        p--; {goto st713;}
    }
#line 306 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st713;}
    }
#line 294 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in PEDIGREE metadata");
        p--; {goto st713;}
    }
#line 300 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in pedigreeDB metadata");
        p--; {goto st713;}
    }
#line 40 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st713;}
    }
#line 45 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        p--; {goto st714;}
    }
	break;
#line 15793 "vcf_validator_detail.hpp"
	}
	}

	_out: {}
	}

#line 771 "vcf_v41.ragel"

    }

  }
}
