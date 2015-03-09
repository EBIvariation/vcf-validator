
#line 1 "cpp/src/bioformats/vcf/vcf_v41.ragel"
#include <cstdio>

#include "validator.hpp"


#line 714 "cpp/src/bioformats/vcf/vcf_v41.ragel"


namespace
{
  
#line 15 "cpp/src/bioformats/vcf/validator_detail.hpp"
static const int vcf_start = 1;
static const int vcf_first_final = 598;
static const int vcf_error = 0;

static const int vcf_en_main = 1;
static const int vcf_en_main_meta_section = 20;
static const int vcf_en_main_body_section = 599;
static const int vcf_en_meta_section_skip = 596;
static const int vcf_en_body_section_skip = 597;


#line 720 "cpp/src/bioformats/vcf/vcf_v41.ragel"

}

namespace opencb
{
  namespace vcf
  {
    template <typename Configuration>
    Parser<Configuration>::Parser(std::shared_ptr<Source> const & source,
                                  std::shared_ptr<std::vector<Record>> const & records
    )
    : ParsingState{source, records}
    {
      
#line 42 "cpp/src/bioformats/vcf/validator_detail.hpp"
	{
	cs = vcf_start;
	}

#line 735 "cpp/src/bioformats/vcf/vcf_v41.ragel"

    }

    template <typename Configuration>
    void Parser<Configuration>::parse(std::vector<char> const & text)
    {
      char const * p = &text[0];
      char const * pe = &text[0] + text.size();
      char const * eof = nullptr;

      clear_records();
      parse_buffer(p, pe, eof);
    }

    template <typename Configuration>
    void Parser<Configuration>::parse(std::string const & text)
    {
      char const * p = text.data();
      char const * pe = text.data() + text.size();
      char const * eof = nullptr;

      clear_records();
      parse_buffer(p, pe, eof);
    }

    template <typename Configuration>
    void Parser<Configuration>::end()
    {
      char const * empty = "";
      clear_records();
      parse_buffer(empty, empty, empty);
    }

    template <typename Configuration>
    bool Parser<Configuration>::is_valid() const
    {
      return cs >= 
#line 85 "cpp/src/bioformats/vcf/validator_detail.hpp"
598
#line 771 "cpp/src/bioformats/vcf/vcf_v41.ragel"
;
    }

    template <typename Configuration>
    void Parser<Configuration>::parse_buffer(char const * p, char const * pe, char const * eof)
    {
      
#line 95 "cpp/src/bioformats/vcf/validator_detail.hpp"
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
#line 44 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this);
        p--; {goto st596;}
    }
	goto st0;
tr14:
#line 186 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this,
            "Fileformat is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st596;}
    }
#line 44 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this);
        p--; {goto st596;}
    }
	goto st0;
tr18:
#line 44 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this);
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
#line 298 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this, "The header line does not start with the mandatory columns: CHROM, POS, ID, REF, ALT, QUAL, FILTER and INFO");
        p--; {goto st597;}
    }
#line 62 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        p--; {goto st597;}
    }
	goto st0;
tr20:
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
#line 298 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this, "The header line does not start with the mandatory columns: CHROM, POS, ID, REF, ALT, QUAL, FILTER and INFO");
        p--; {goto st597;}
    }
#line 62 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        p--; {goto st597;}
    }
	goto st0;
tr23:
#line 193 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st596;}
    }
#line 216 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st596;}
    }
#line 222 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st596;}
    }
#line 238 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st596;}
    }
#line 204 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in assembly metadata");
        p--; {goto st596;}
    }
#line 210 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in contig metadata");
        p--; {goto st596;}
    }
#line 266 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st596;}
    }
#line 254 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in PEDIGREE metadata");
        p--; {goto st596;}
    }
#line 260 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in pedigreeDB metadata");
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
	goto st0;
tr33:
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
	goto st0;
tr72:
#line 193 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
	goto st0;
tr80:
#line 198 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "ALT metadata ID is not prefixed by DEL/INS/DUP/INV/CNV and suffixed by ':' and a text sequence");
        p--; {goto st596;}
    }
#line 193 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
	goto st0;
tr99:
#line 287 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st596;}
    }
#line 193 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
	goto st0;
tr104:
#line 282 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st596;}
    }
#line 193 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
	goto st0;
tr112:
#line 216 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st596;}
    }
#line 222 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
	goto st0;
tr115:
#line 216 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
	goto st0;
tr125:
#line 282 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st596;}
    }
#line 216 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
	goto st0;
tr145:
#line 287 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st596;}
    }
#line 216 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
	goto st0;
tr156:
#line 222 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
	goto st0;
tr166:
#line 282 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st596;}
    }
#line 222 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
	goto st0;
tr179:
#line 227 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "FORMAT metadata Number is not a number, A, R, G or dot");
        p--; {goto st596;}
    }
#line 222 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
	goto st0;
tr188:
#line 248 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "INFO metadata Type is not a Integer, Float, Flag, Character or String");
        p--; {goto st596;}
    }
#line 222 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
	goto st0;
tr206:
#line 287 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st596;}
    }
#line 222 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
	goto st0;
tr218:
#line 238 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
	goto st0;
tr227:
#line 282 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st596;}
    }
#line 238 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
	goto st0;
tr240:
#line 243 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "INFO metadata Number is not a number, A, R, G or dot");
        p--; {goto st596;}
    }
#line 238 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
	goto st0;
tr249:
#line 248 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "INFO metadata Type is not a Integer, Float, Flag, Character or String");
        p--; {goto st596;}
    }
#line 238 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
	goto st0;
tr267:
#line 287 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st596;}
    }
#line 238 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
	goto st0;
tr279:
#line 254 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in PEDIGREE metadata");
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
	goto st0;
tr289:
#line 282 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st596;}
    }
#line 254 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in PEDIGREE metadata");
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
	goto st0;
tr301:
#line 266 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
	goto st0;
tr312:
#line 282 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st596;}
    }
#line 266 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
	goto st0;
tr317:
#line 282 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st596;}
    }
#line 271 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Genomes is not a valid string (maybe it contains quotes?)");
        p--; {goto st596;}
    }
#line 266 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
	goto st0;
tr319:
#line 271 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Genomes is not a valid string (maybe it contains quotes?)");
        p--; {goto st596;}
    }
#line 266 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
	goto st0;
tr329:
#line 271 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Genomes is not a valid string (maybe it contains quotes?)");
        p--; {goto st596;}
    }
#line 276 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Mixture is not a valid string (maybe it contains quotes?)");
        p--; {goto st596;}
    }
#line 266 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
	goto st0;
tr332:
#line 276 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Mixture is not a valid string (maybe it contains quotes?)");
        p--; {goto st596;}
    }
#line 266 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
	goto st0;
tr342:
#line 276 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Mixture is not a valid string (maybe it contains quotes?)");
        p--; {goto st596;}
    }
#line 287 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st596;}
    }
#line 266 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
	goto st0;
tr345:
#line 287 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st596;}
    }
#line 266 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
	goto st0;
tr363:
#line 204 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in assembly metadata");
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
	goto st0;
tr372:
#line 292 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata URL is not valid");
        p--; {goto st596;}
    }
#line 204 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in assembly metadata");
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
	goto st0;
tr379:
#line 210 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in contig metadata");
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
	goto st0;
tr390:
#line 282 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st596;}
    }
#line 210 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in contig metadata");
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
	goto st0;
tr409:
#line 260 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in pedigreeDB metadata");
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
	goto st0;
tr421:
#line 292 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata URL is not valid");
        p--; {goto st596;}
    }
#line 260 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in pedigreeDB metadata");
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
	goto st0;
tr429:
#line 298 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this, "The header line does not start with the mandatory columns: CHROM, POS, ID, REF, ALT, QUAL, FILTER and INFO");
        p--; {goto st597;}
    }
#line 62 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        p--; {goto st597;}
    }
	goto st0;
tr468:
#line 62 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        p--; {goto st597;}
    }
	goto st0;
tr480:
#line 306 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Chromosome is not a string without colons or whitespaces, optionally wrapped with angle brackets (<>)");
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	goto st0;
tr484:
#line 312 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Position is not a positive number");
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	goto st0;
tr489:
#line 318 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "ID is not a single dot or a list of strings without semicolons or whitespaces");
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	goto st0;
tr494:
#line 324 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Reference is not a string of bases");
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	goto st0;
tr498:
#line 330 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Alternate is not a single dot or a comma-separated list of bases");
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	goto st0;
tr507:
#line 336 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Quality is not a single dot or a positive number");
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	goto st0;
tr517:
#line 342 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Filter is not a single dot or a semicolon-separated list of strings");
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	goto st0;
tr525:
#line 353 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st597;}
    }
#line 348 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	goto st0;
tr546:
#line 454 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Format is not a colon-separated list of alphanumeric strings");
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	goto st0;
tr551:
#line 467 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " does not start with a valid genotype";
        ErrorPolicy::handle_body_section_error(*this, message_stream.str());
        p--; {goto st597;}
    }
#line 460 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " is not a valid string";
        ErrorPolicy::handle_body_section_error(*this, message_stream.str());
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	goto st0;
tr563:
#line 460 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " is not a valid string";
        ErrorPolicy::handle_body_section_error(*this, message_stream.str());
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	goto st0;
tr569:
#line 358 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info field value is not a comma-separated list of valid strings (maybe it contains whitespaces?)");
        p--; {goto st597;}
    }
#line 348 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	goto st0;
tr571:
#line 448 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info 1000G is not a flag (with 1/0/no value)");
        p--; {goto st597;}
    }
#line 353 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st597;}
    }
#line 348 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	goto st0;
tr573:
#line 448 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info 1000G is not a flag (with 1/0/no value)");
        p--; {goto st597;}
    }
#line 348 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	goto st0;
tr580:
#line 363 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info AA value is not a single dot or a string of bases");
        p--; {goto st597;}
    }
#line 348 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	goto st0;
tr584:
#line 368 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info AC value is not a comma-separated list of numbers");
        p--; {goto st597;}
    }
#line 348 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	goto st0;
tr588:
#line 373 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info AF value is not a comma-separated list of numbers");
        p--; {goto st597;}
    }
#line 348 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	goto st0;
tr598:
#line 378 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info AN value is not an integer number");
        p--; {goto st597;}
    }
#line 348 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	goto st0;
tr603:
#line 383 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info BQ value is not a number");
        p--; {goto st597;}
    }
#line 348 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	goto st0;
tr617:
#line 388 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info CIGAR value is not an alphanumeric string");
        p--; {goto st597;}
    }
#line 348 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	goto st0;
tr621:
#line 393 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info DB is not a flag (with 1/0/no value)");
        p--; {goto st597;}
    }
#line 353 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st597;}
    }
#line 348 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	goto st0;
tr623:
#line 393 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info DB is not a flag (with 1/0/no value)");
        p--; {goto st597;}
    }
#line 348 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	goto st0;
tr626:
#line 398 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info DP value is not an integer number");
        p--; {goto st597;}
    }
#line 348 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	goto st0;
tr632:
#line 403 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info END value is not an integer number");
        p--; {goto st597;}
    }
#line 348 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	goto st0;
tr637:
#line 408 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info H2 is not a flag (with 1/0/no value)");
        p--; {goto st597;}
    }
#line 353 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st597;}
    }
#line 348 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	goto st0;
tr639:
#line 408 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info H2 is not a flag (with 1/0/no value)");
        p--; {goto st597;}
    }
#line 348 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	goto st0;
tr641:
#line 413 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info H3 is not a flag (with 1/0/no value)");
        p--; {goto st597;}
    }
#line 353 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st597;}
    }
#line 348 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	goto st0;
tr643:
#line 413 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info H3 is not a flag (with 1/0/no value)");
        p--; {goto st597;}
    }
#line 348 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	goto st0;
tr649:
#line 423 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info MQ0 value is not an integer number");
        p--; {goto st597;}
    }
#line 348 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	goto st0;
tr652:
#line 418 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info MQ value is not a number");
        p--; {goto st597;}
    }
#line 348 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	goto st0;
tr663:
#line 428 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info NS value is not an integer number");
        p--; {goto st597;}
    }
#line 348 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	goto st0;
tr669:
#line 433 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info SB value is not a number");
        p--; {goto st597;}
    }
#line 348 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	goto st0;
tr683:
#line 438 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info SOMATIC is not a flag (with 1/0/no value)");
        p--; {goto st597;}
    }
#line 353 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st597;}
    }
#line 348 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	goto st0;
tr685:
#line 438 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info SOMATIC is not a flag (with 1/0/no value)");
        p--; {goto st597;}
    }
#line 348 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	goto st0;
tr695:
#line 443 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info VALIDATED is not a flag (with 1/0/no value)");
        p--; {goto st597;}
    }
#line 353 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st597;}
    }
#line 348 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	goto st0;
tr697:
#line 443 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info VALIDATED is not a flag (with 1/0/no value)");
        p--; {goto st597;}
    }
#line 348 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	goto st0;
tr759:
#line 62 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        p--; {goto st597;}
    }
#line 306 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Chromosome is not a string without colons or whitespaces, optionally wrapped with angle brackets (<>)");
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	goto st0;
#line 1410 "cpp/src/bioformats/vcf/validator_detail.hpp"
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
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st15;
tr17:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st15;
st15:
	if ( ++p == pe )
		goto _test_eof15;
case 15:
#line 1525 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 10 )
		goto tr16;
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr17;
	goto tr14;
tr16:
#line 75 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_fileformat(*this);
    }
#line 27 "cpp/src/bioformats/vcf/vcf_v41.ragel"
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
#line 1551 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 35 )
		goto st17;
	goto tr18;
st17:
	if ( ++p == pe )
		goto _test_eof17;
case 17:
	switch( (*p) ) {
		case 35: goto st18;
		case 67: goto st329;
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
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st19;
tr35:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st19;
st19:
	if ( ++p == pe )
		goto _test_eof19;
case 19:
#line 1604 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr34;
		case 61: goto tr36;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr35;
	goto tr33;
tr34:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 147 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        try {
          ParsePolicy::handle_meta_line(*this);
        } catch (ParsingError ex) {
          ErrorPolicy::handle_meta_section_error(*this, ex.what());
        }
    }
#line 27 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st20;
tr47:
#line 147 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        try {
          ParsePolicy::handle_meta_line(*this);
        } catch (ParsingError ex) {
          ErrorPolicy::handle_meta_section_error(*this, ex.what());
        }
    }
#line 27 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st20;
st20:
	if ( ++p == pe )
		goto _test_eof20;
case 20:
#line 1660 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 35 )
		goto st17;
	goto tr20;
tr36:
#line 139 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this);
    }
	goto st21;
st21:
	if ( ++p == pe )
		goto _test_eof21;
case 21:
#line 1674 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 34: goto tr38;
		case 60: goto tr39;
	}
	if ( (*p) > 59 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto tr37;
	} else if ( (*p) >= 32 )
		goto tr37;
	goto tr33;
tr37:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st22;
tr40:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st22;
tr44:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st22;
st22:
	if ( ++p == pe )
		goto _test_eof22;
case 22:
#line 1715 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 10 )
		goto tr34;
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto tr40;
	} else if ( (*p) >= 32 )
		goto tr40;
	goto tr33;
tr38:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st23;
st23:
	if ( ++p == pe )
		goto _test_eof23;
case 23:
#line 1738 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr34;
		case 34: goto tr40;
		case 61: goto tr42;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr41;
	goto tr33;
tr41:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st24;
tr43:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st24;
st24:
	if ( ++p == pe )
		goto _test_eof24;
case 24:
#line 1767 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr34;
		case 34: goto tr44;
		case 61: goto tr45;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr43;
	goto tr33;
tr42:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st25;
tr45:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st25;
st25:
	if ( ++p == pe )
		goto _test_eof25;
case 25:
#line 1796 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 34 )
		goto tr46;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr45;
	goto tr33;
tr46:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st26;
st26:
	if ( ++p == pe )
		goto _test_eof26;
case 26:
#line 1812 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 10 )
		goto tr47;
	goto tr33;
tr39:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st27;
st27:
	if ( ++p == pe )
		goto _test_eof27;
case 27:
#line 1830 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr34;
		case 34: goto tr48;
		case 47: goto tr40;
		case 95: goto tr49;
	}
	if ( (*p) < 62 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr40;
		} else if ( (*p) > 46 ) {
			if ( (*p) > 57 ) {
				if ( 58 <= (*p) && (*p) <= 60 )
					goto tr40;
			} else if ( (*p) >= 48 )
				goto tr50;
		} else
			goto tr49;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr50;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr40;
			} else if ( (*p) >= 97 )
				goto tr50;
		} else
			goto tr40;
	} else
		goto tr40;
	goto tr33;
tr48:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st28;
st28:
	if ( ++p == pe )
		goto _test_eof28;
case 28:
#line 1874 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr34;
		case 34: goto tr40;
		case 61: goto tr52;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr51;
	goto tr33;
tr51:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st29;
tr53:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st29;
st29:
	if ( ++p == pe )
		goto _test_eof29;
case 29:
#line 1903 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr34;
		case 34: goto tr44;
		case 61: goto tr54;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr53;
	goto tr33;
tr52:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st30;
tr54:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st30;
st30:
	if ( ++p == pe )
		goto _test_eof30;
case 30:
#line 1932 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 34 )
		goto tr55;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr54;
	goto tr33;
tr55:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st31;
st31:
	if ( ++p == pe )
		goto _test_eof31;
case 31:
#line 1948 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 62 )
		goto st26;
	goto tr33;
tr49:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st32;
tr57:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st32;
st32:
	if ( ++p == pe )
		goto _test_eof32;
case 32:
#line 1972 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr34;
		case 47: goto tr40;
		case 95: goto tr57;
	}
	if ( (*p) < 62 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr40;
		} else if ( (*p) > 46 ) {
			if ( (*p) > 57 ) {
				if ( 58 <= (*p) && (*p) <= 60 )
					goto tr40;
			} else if ( (*p) >= 48 )
				goto tr58;
		} else
			goto tr57;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr58;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr40;
			} else if ( (*p) >= 97 )
				goto tr58;
		} else
			goto tr40;
	} else
		goto tr40;
	goto tr33;
tr50:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st33;
tr58:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st33;
st33:
	if ( ++p == pe )
		goto _test_eof33;
case 33:
#line 2025 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr34;
		case 47: goto tr40;
		case 61: goto tr59;
		case 95: goto tr58;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 45 ) {
			if ( 32 <= (*p) && (*p) <= 44 )
				goto tr40;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr40;
		} else
			goto tr58;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr40;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr40;
		} else
			goto tr58;
	} else
		goto tr58;
	goto tr33;
tr59:
#line 143 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_key(*this);
    }
	goto st34;
st34:
	if ( ++p == pe )
		goto _test_eof34;
case 34:
#line 2063 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 34 )
		goto st39;
	if ( (*p) < 45 ) {
		if ( 32 <= (*p) && (*p) <= 43 )
			goto tr60;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr60;
	} else
		goto tr60;
	goto tr33;
tr60:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st35;
tr62:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st35;
st35:
	if ( ++p == pe )
		goto _test_eof35;
case 35:
#line 2095 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto tr63;
		case 62: goto tr46;
	}
	if ( (*p) > 33 ) {
		if ( 35 <= (*p) && (*p) <= 126 )
			goto tr62;
	} else if ( (*p) >= 32 )
		goto tr62;
	goto tr33;
tr63:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st36;
st36:
	if ( ++p == pe )
		goto _test_eof36;
case 36:
#line 2116 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 95 )
		goto tr64;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr64;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr65;
		} else if ( (*p) >= 65 )
			goto tr65;
	} else
		goto tr65;
	goto tr33;
tr64:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st37;
st37:
	if ( ++p == pe )
		goto _test_eof37;
case 37:
#line 2141 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 95 )
		goto st37;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st37;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr67;
		} else if ( (*p) >= 65 )
			goto tr67;
	} else
		goto tr67;
	goto tr33;
tr65:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st38;
tr67:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st38;
st38:
	if ( ++p == pe )
		goto _test_eof38;
case 38:
#line 2176 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 61: goto tr59;
		case 95: goto tr67;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr67;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr67;
		} else if ( (*p) >= 65 )
			goto tr67;
	} else
		goto tr67;
	goto tr33;
st39:
	if ( ++p == pe )
		goto _test_eof39;
case 39:
	if ( (*p) > 33 ) {
		if ( 35 <= (*p) && (*p) <= 126 )
			goto tr68;
	} else if ( (*p) >= 32 )
		goto tr68;
	goto tr33;
tr68:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st40;
tr69:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st40;
st40:
	if ( ++p == pe )
		goto _test_eof40;
case 40:
#line 2223 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 34 )
		goto tr70;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr69;
	goto tr33;
tr70:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st41;
st41:
	if ( ++p == pe )
		goto _test_eof41;
case 41:
#line 2239 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto st36;
		case 62: goto st26;
	}
	goto tr33;
tr25:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st42;
st42:
	if ( ++p == pe )
		goto _test_eof42;
case 42:
#line 2259 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr34;
		case 61: goto tr36;
		case 76: goto tr73;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr35;
	goto tr72;
tr73:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st43;
st43:
	if ( ++p == pe )
		goto _test_eof43;
case 43:
#line 2278 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr34;
		case 61: goto tr36;
		case 84: goto tr74;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr35;
	goto tr72;
tr74:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st44;
st44:
	if ( ++p == pe )
		goto _test_eof44;
case 44:
#line 2297 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr34;
		case 61: goto tr75;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr35;
	goto tr72;
tr75:
#line 79 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "ALT");
    }
	goto st45;
st45:
	if ( ++p == pe )
		goto _test_eof45;
case 45:
#line 2315 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 60 )
		goto st46;
	goto tr72;
st46:
	if ( ++p == pe )
		goto _test_eof46;
case 46:
	if ( (*p) == 73 )
		goto st47;
	goto tr72;
st47:
	if ( ++p == pe )
		goto _test_eof47;
case 47:
	if ( (*p) == 68 )
		goto st48;
	goto tr72;
st48:
	if ( ++p == pe )
		goto _test_eof48;
case 48:
	if ( (*p) == 61 )
		goto st49;
	goto tr72;
st49:
	if ( ++p == pe )
		goto _test_eof49;
case 49:
	switch( (*p) ) {
		case 58: goto tr82;
		case 95: goto tr82;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr81;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr81;
	} else
		goto tr81;
	goto tr80;
tr84:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st50;
tr81:
#line 115 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_key(*this, "ID");
    }
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st50;
st50:
	if ( ++p == pe )
		goto _test_eof50;
case 50:
#line 2381 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto tr83;
		case 95: goto tr84;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 58 )
			goto tr84;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr84;
	} else
		goto tr84;
	goto tr80;
tr83:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st51;
st51:
	if ( ++p == pe )
		goto _test_eof51;
case 51:
#line 2405 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 68 )
		goto st52;
	goto tr72;
st52:
	if ( ++p == pe )
		goto _test_eof52;
case 52:
	if ( (*p) == 101 )
		goto st53;
	goto tr72;
st53:
	if ( ++p == pe )
		goto _test_eof53;
case 53:
	if ( (*p) == 115 )
		goto st54;
	goto tr72;
st54:
	if ( ++p == pe )
		goto _test_eof54;
case 54:
	if ( (*p) == 99 )
		goto st55;
	goto tr72;
st55:
	if ( ++p == pe )
		goto _test_eof55;
case 55:
	if ( (*p) == 114 )
		goto st56;
	goto tr72;
st56:
	if ( ++p == pe )
		goto _test_eof56;
case 56:
	if ( (*p) == 105 )
		goto st57;
	goto tr72;
st57:
	if ( ++p == pe )
		goto _test_eof57;
case 57:
	if ( (*p) == 112 )
		goto st58;
	goto tr72;
st58:
	if ( ++p == pe )
		goto _test_eof58;
case 58:
	if ( (*p) == 116 )
		goto st59;
	goto tr72;
st59:
	if ( ++p == pe )
		goto _test_eof59;
case 59:
	if ( (*p) == 105 )
		goto st60;
	goto tr72;
st60:
	if ( ++p == pe )
		goto _test_eof60;
case 60:
	if ( (*p) == 111 )
		goto st61;
	goto tr72;
st61:
	if ( ++p == pe )
		goto _test_eof61;
case 61:
	if ( (*p) == 110 )
		goto st62;
	goto tr72;
st62:
	if ( ++p == pe )
		goto _test_eof62;
case 62:
	if ( (*p) == 61 )
		goto st63;
	goto tr72;
st63:
	if ( ++p == pe )
		goto _test_eof63;
case 63:
	if ( (*p) == 34 )
		goto tr97;
	goto tr72;
tr97:
#line 127 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_key(*this, "Description");
    }
	goto st64;
st64:
	if ( ++p == pe )
		goto _test_eof64;
case 64:
#line 2503 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) > 33 ) {
		if ( 35 <= (*p) && (*p) <= 126 )
			goto tr98;
	} else if ( (*p) >= 32 )
		goto tr98;
	goto tr72;
tr98:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st65;
tr100:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st65;
st65:
	if ( ++p == pe )
		goto _test_eof65;
case 65:
#line 2530 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 34 )
		goto tr101;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr100;
	goto tr99;
tr101:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st66;
st66:
	if ( ++p == pe )
		goto _test_eof66;
case 66:
#line 2546 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto st67;
		case 62: goto st71;
	}
	goto tr99;
st67:
	if ( ++p == pe )
		goto _test_eof67;
case 67:
	if ( (*p) == 95 )
		goto tr105;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr105;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr106;
		} else if ( (*p) >= 65 )
			goto tr106;
	} else
		goto tr106;
	goto tr104;
tr105:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st68;
st68:
	if ( ++p == pe )
		goto _test_eof68;
case 68:
#line 2580 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 95 )
		goto st68;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st68;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr108;
		} else if ( (*p) >= 65 )
			goto tr108;
	} else
		goto tr108;
	goto tr104;
tr106:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st69;
tr108:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st69;
st69:
	if ( ++p == pe )
		goto _test_eof69;
case 69:
#line 2615 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 61: goto tr109;
		case 95: goto tr108;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr108;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr108;
		} else if ( (*p) >= 65 )
			goto tr108;
	} else
		goto tr108;
	goto tr104;
tr109:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st70;
st70:
	if ( ++p == pe )
		goto _test_eof70;
case 70:
#line 2642 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 34 )
		goto st64;
	goto tr72;
st71:
	if ( ++p == pe )
		goto _test_eof71;
case 71:
	if ( (*p) == 10 )
		goto tr47;
	goto tr72;
tr82:
#line 115 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_key(*this, "ID");
    }
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st72;
st72:
	if ( ++p == pe )
		goto _test_eof72;
case 72:
#line 2667 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 58: goto st72;
		case 95: goto st72;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr84;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr84;
	} else
		goto tr84;
	goto tr80;
tr26:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st73;
st73:
	if ( ++p == pe )
		goto _test_eof73;
case 73:
#line 2695 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr34;
		case 61: goto tr36;
		case 73: goto tr113;
		case 79: goto tr114;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr35;
	goto tr112;
tr113:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st74;
st74:
	if ( ++p == pe )
		goto _test_eof74;
case 74:
#line 2715 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr34;
		case 61: goto tr36;
		case 76: goto tr116;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr35;
	goto tr115;
tr116:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st75;
st75:
	if ( ++p == pe )
		goto _test_eof75;
case 75:
#line 2734 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr34;
		case 61: goto tr36;
		case 84: goto tr117;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr35;
	goto tr115;
tr117:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st76;
st76:
	if ( ++p == pe )
		goto _test_eof76;
case 76:
#line 2753 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr34;
		case 61: goto tr36;
		case 69: goto tr118;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr35;
	goto tr115;
tr118:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st77;
st77:
	if ( ++p == pe )
		goto _test_eof77;
case 77:
#line 2772 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr34;
		case 61: goto tr36;
		case 82: goto tr119;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr35;
	goto tr115;
tr119:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st78;
st78:
	if ( ++p == pe )
		goto _test_eof78;
case 78:
#line 2791 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr34;
		case 61: goto tr120;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr35;
	goto tr115;
tr120:
#line 91 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "FILTER");
    }
	goto st79;
st79:
	if ( ++p == pe )
		goto _test_eof79;
case 79:
#line 2809 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 60 )
		goto st80;
	goto tr115;
st80:
	if ( ++p == pe )
		goto _test_eof80;
case 80:
	if ( (*p) == 73 )
		goto st81;
	goto tr115;
st81:
	if ( ++p == pe )
		goto _test_eof81;
case 81:
	if ( (*p) == 68 )
		goto st82;
	goto tr115;
st82:
	if ( ++p == pe )
		goto _test_eof82;
case 82:
	if ( (*p) == 61 )
		goto st83;
	goto tr115;
st83:
	if ( ++p == pe )
		goto _test_eof83;
case 83:
	if ( (*p) == 95 )
		goto tr126;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr126;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr127;
		} else if ( (*p) >= 65 )
			goto tr127;
	} else
		goto tr127;
	goto tr125;
tr126:
#line 115 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_key(*this, "ID");
    }
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st84;
st84:
	if ( ++p == pe )
		goto _test_eof84;
case 84:
#line 2866 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 95 )
		goto st84;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st84;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr129;
		} else if ( (*p) >= 65 )
			goto tr129;
	} else
		goto tr129;
	goto tr125;
tr129:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st85;
tr127:
#line 115 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_key(*this, "ID");
    }
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st85;
st85:
	if ( ++p == pe )
		goto _test_eof85;
case 85:
#line 2905 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto tr130;
		case 95: goto tr129;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr129;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr129;
		} else if ( (*p) >= 65 )
			goto tr129;
	} else
		goto tr129;
	goto tr125;
tr130:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st86;
st86:
	if ( ++p == pe )
		goto _test_eof86;
case 86:
#line 2932 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 68 )
		goto st87;
	goto tr115;
st87:
	if ( ++p == pe )
		goto _test_eof87;
case 87:
	if ( (*p) == 101 )
		goto st88;
	goto tr115;
st88:
	if ( ++p == pe )
		goto _test_eof88;
case 88:
	if ( (*p) == 115 )
		goto st89;
	goto tr115;
st89:
	if ( ++p == pe )
		goto _test_eof89;
case 89:
	if ( (*p) == 99 )
		goto st90;
	goto tr115;
st90:
	if ( ++p == pe )
		goto _test_eof90;
case 90:
	if ( (*p) == 114 )
		goto st91;
	goto tr115;
st91:
	if ( ++p == pe )
		goto _test_eof91;
case 91:
	if ( (*p) == 105 )
		goto st92;
	goto tr115;
st92:
	if ( ++p == pe )
		goto _test_eof92;
case 92:
	if ( (*p) == 112 )
		goto st93;
	goto tr115;
st93:
	if ( ++p == pe )
		goto _test_eof93;
case 93:
	if ( (*p) == 116 )
		goto st94;
	goto tr115;
st94:
	if ( ++p == pe )
		goto _test_eof94;
case 94:
	if ( (*p) == 105 )
		goto st95;
	goto tr115;
st95:
	if ( ++p == pe )
		goto _test_eof95;
case 95:
	if ( (*p) == 111 )
		goto st96;
	goto tr115;
st96:
	if ( ++p == pe )
		goto _test_eof96;
case 96:
	if ( (*p) == 110 )
		goto st97;
	goto tr115;
st97:
	if ( ++p == pe )
		goto _test_eof97;
case 97:
	if ( (*p) == 61 )
		goto st98;
	goto tr115;
st98:
	if ( ++p == pe )
		goto _test_eof98;
case 98:
	if ( (*p) == 34 )
		goto tr143;
	goto tr115;
tr143:
#line 127 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_key(*this, "Description");
    }
	goto st99;
st99:
	if ( ++p == pe )
		goto _test_eof99;
case 99:
#line 3030 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) > 33 ) {
		if ( 35 <= (*p) && (*p) <= 126 )
			goto tr144;
	} else if ( (*p) >= 32 )
		goto tr144;
	goto tr115;
tr144:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st100;
tr146:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st100;
st100:
	if ( ++p == pe )
		goto _test_eof100;
case 100:
#line 3057 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 34 )
		goto tr147;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr146;
	goto tr145;
tr147:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st101;
st101:
	if ( ++p == pe )
		goto _test_eof101;
case 101:
#line 3073 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto st102;
		case 62: goto st106;
	}
	goto tr145;
st102:
	if ( ++p == pe )
		goto _test_eof102;
case 102:
	if ( (*p) == 95 )
		goto tr150;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr150;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr151;
		} else if ( (*p) >= 65 )
			goto tr151;
	} else
		goto tr151;
	goto tr125;
tr150:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st103;
st103:
	if ( ++p == pe )
		goto _test_eof103;
case 103:
#line 3107 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 95 )
		goto st103;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st103;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr153;
		} else if ( (*p) >= 65 )
			goto tr153;
	} else
		goto tr153;
	goto tr125;
tr151:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st104;
tr153:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st104;
st104:
	if ( ++p == pe )
		goto _test_eof104;
case 104:
#line 3142 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 61: goto tr154;
		case 95: goto tr153;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr153;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr153;
		} else if ( (*p) >= 65 )
			goto tr153;
	} else
		goto tr153;
	goto tr125;
tr154:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st105;
st105:
	if ( ++p == pe )
		goto _test_eof105;
case 105:
#line 3169 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 34 )
		goto st99;
	goto tr115;
st106:
	if ( ++p == pe )
		goto _test_eof106;
case 106:
	if ( (*p) == 10 )
		goto tr47;
	goto tr115;
tr114:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st107;
st107:
	if ( ++p == pe )
		goto _test_eof107;
case 107:
#line 3190 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr34;
		case 61: goto tr36;
		case 82: goto tr157;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr35;
	goto tr156;
tr157:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st108;
st108:
	if ( ++p == pe )
		goto _test_eof108;
case 108:
#line 3209 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr34;
		case 61: goto tr36;
		case 77: goto tr158;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr35;
	goto tr156;
tr158:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st109;
st109:
	if ( ++p == pe )
		goto _test_eof109;
case 109:
#line 3228 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr34;
		case 61: goto tr36;
		case 65: goto tr159;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr35;
	goto tr156;
tr159:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st110;
st110:
	if ( ++p == pe )
		goto _test_eof110;
case 110:
#line 3247 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr34;
		case 61: goto tr36;
		case 84: goto tr160;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr35;
	goto tr156;
tr160:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st111;
st111:
	if ( ++p == pe )
		goto _test_eof111;
case 111:
#line 3266 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr34;
		case 61: goto tr161;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr35;
	goto tr156;
tr161:
#line 95 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "FORMAT");
    }
	goto st112;
st112:
	if ( ++p == pe )
		goto _test_eof112;
case 112:
#line 3284 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 60 )
		goto st113;
	goto tr156;
st113:
	if ( ++p == pe )
		goto _test_eof113;
case 113:
	if ( (*p) == 73 )
		goto st114;
	goto tr156;
st114:
	if ( ++p == pe )
		goto _test_eof114;
case 114:
	if ( (*p) == 68 )
		goto st115;
	goto tr156;
st115:
	if ( ++p == pe )
		goto _test_eof115;
case 115:
	if ( (*p) == 61 )
		goto st116;
	goto tr156;
st116:
	if ( ++p == pe )
		goto _test_eof116;
case 116:
	if ( (*p) == 95 )
		goto tr167;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr167;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr168;
		} else if ( (*p) >= 65 )
			goto tr168;
	} else
		goto tr168;
	goto tr166;
tr167:
#line 115 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_key(*this, "ID");
    }
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st117;
st117:
	if ( ++p == pe )
		goto _test_eof117;
case 117:
#line 3341 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 95 )
		goto st117;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st117;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr170;
		} else if ( (*p) >= 65 )
			goto tr170;
	} else
		goto tr170;
	goto tr166;
tr170:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st118;
tr168:
#line 115 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_key(*this, "ID");
    }
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st118;
st118:
	if ( ++p == pe )
		goto _test_eof118;
case 118:
#line 3380 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto tr171;
		case 95: goto tr170;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr170;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr170;
		} else if ( (*p) >= 65 )
			goto tr170;
	} else
		goto tr170;
	goto tr166;
tr171:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st119;
st119:
	if ( ++p == pe )
		goto _test_eof119;
case 119:
#line 3407 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 78 )
		goto st120;
	goto tr156;
st120:
	if ( ++p == pe )
		goto _test_eof120;
case 120:
	if ( (*p) == 117 )
		goto st121;
	goto tr156;
st121:
	if ( ++p == pe )
		goto _test_eof121;
case 121:
	if ( (*p) == 109 )
		goto st122;
	goto tr156;
st122:
	if ( ++p == pe )
		goto _test_eof122;
case 122:
	if ( (*p) == 98 )
		goto st123;
	goto tr156;
st123:
	if ( ++p == pe )
		goto _test_eof123;
case 123:
	if ( (*p) == 101 )
		goto st124;
	goto tr156;
st124:
	if ( ++p == pe )
		goto _test_eof124;
case 124:
	if ( (*p) == 114 )
		goto st125;
	goto tr156;
st125:
	if ( ++p == pe )
		goto _test_eof125;
case 125:
	if ( (*p) == 61 )
		goto st126;
	goto tr156;
st126:
	if ( ++p == pe )
		goto _test_eof126;
case 126:
	switch( (*p) ) {
		case 46: goto tr180;
		case 65: goto tr180;
		case 71: goto tr180;
		case 82: goto tr180;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr181;
	goto tr179;
tr180:
#line 119 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_key(*this, "Number");
    }
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st127;
st127:
	if ( ++p == pe )
		goto _test_eof127;
case 127:
#line 3484 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 44 )
		goto tr182;
	goto tr179;
tr182:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st128;
st128:
	if ( ++p == pe )
		goto _test_eof128;
case 128:
#line 3498 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 84 )
		goto st129;
	goto tr156;
st129:
	if ( ++p == pe )
		goto _test_eof129;
case 129:
	if ( (*p) == 121 )
		goto st130;
	goto tr156;
st130:
	if ( ++p == pe )
		goto _test_eof130;
case 130:
	if ( (*p) == 112 )
		goto st131;
	goto tr156;
st131:
	if ( ++p == pe )
		goto _test_eof131;
case 131:
	if ( (*p) == 101 )
		goto st132;
	goto tr156;
st132:
	if ( ++p == pe )
		goto _test_eof132;
case 132:
	if ( (*p) == 61 )
		goto st133;
	goto tr156;
st133:
	if ( ++p == pe )
		goto _test_eof133;
case 133:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr189;
	} else if ( (*p) >= 65 )
		goto tr189;
	goto tr188;
tr191:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st134;
tr189:
#line 123 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_key(*this, "Type");
    }
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st134;
st134:
	if ( ++p == pe )
		goto _test_eof134;
case 134:
#line 3564 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 44 )
		goto tr190;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr191;
	} else if ( (*p) >= 65 )
		goto tr191;
	goto tr188;
tr190:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st135;
st135:
	if ( ++p == pe )
		goto _test_eof135;
case 135:
#line 3583 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 68 )
		goto st136;
	goto tr156;
st136:
	if ( ++p == pe )
		goto _test_eof136;
case 136:
	if ( (*p) == 101 )
		goto st137;
	goto tr156;
st137:
	if ( ++p == pe )
		goto _test_eof137;
case 137:
	if ( (*p) == 115 )
		goto st138;
	goto tr156;
st138:
	if ( ++p == pe )
		goto _test_eof138;
case 138:
	if ( (*p) == 99 )
		goto st139;
	goto tr156;
st139:
	if ( ++p == pe )
		goto _test_eof139;
case 139:
	if ( (*p) == 114 )
		goto st140;
	goto tr156;
st140:
	if ( ++p == pe )
		goto _test_eof140;
case 140:
	if ( (*p) == 105 )
		goto st141;
	goto tr156;
st141:
	if ( ++p == pe )
		goto _test_eof141;
case 141:
	if ( (*p) == 112 )
		goto st142;
	goto tr156;
st142:
	if ( ++p == pe )
		goto _test_eof142;
case 142:
	if ( (*p) == 116 )
		goto st143;
	goto tr156;
st143:
	if ( ++p == pe )
		goto _test_eof143;
case 143:
	if ( (*p) == 105 )
		goto st144;
	goto tr156;
st144:
	if ( ++p == pe )
		goto _test_eof144;
case 144:
	if ( (*p) == 111 )
		goto st145;
	goto tr156;
st145:
	if ( ++p == pe )
		goto _test_eof145;
case 145:
	if ( (*p) == 110 )
		goto st146;
	goto tr156;
st146:
	if ( ++p == pe )
		goto _test_eof146;
case 146:
	if ( (*p) == 61 )
		goto st147;
	goto tr156;
st147:
	if ( ++p == pe )
		goto _test_eof147;
case 147:
	if ( (*p) == 34 )
		goto tr204;
	goto tr156;
tr204:
#line 127 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_key(*this, "Description");
    }
	goto st148;
st148:
	if ( ++p == pe )
		goto _test_eof148;
case 148:
#line 3681 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) > 33 ) {
		if ( 35 <= (*p) && (*p) <= 126 )
			goto tr205;
	} else if ( (*p) >= 32 )
		goto tr205;
	goto tr156;
tr205:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st149;
tr207:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st149;
st149:
	if ( ++p == pe )
		goto _test_eof149;
case 149:
#line 3708 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 34 )
		goto tr208;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr207;
	goto tr206;
tr208:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st150;
st150:
	if ( ++p == pe )
		goto _test_eof150;
case 150:
#line 3724 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto st151;
		case 62: goto st155;
	}
	goto tr206;
st151:
	if ( ++p == pe )
		goto _test_eof151;
case 151:
	if ( (*p) == 95 )
		goto tr211;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr211;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr212;
		} else if ( (*p) >= 65 )
			goto tr212;
	} else
		goto tr212;
	goto tr166;
tr211:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st152;
st152:
	if ( ++p == pe )
		goto _test_eof152;
case 152:
#line 3758 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 95 )
		goto st152;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st152;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr214;
		} else if ( (*p) >= 65 )
			goto tr214;
	} else
		goto tr214;
	goto tr166;
tr212:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st153;
tr214:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st153;
st153:
	if ( ++p == pe )
		goto _test_eof153;
case 153:
#line 3793 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 61: goto tr215;
		case 95: goto tr214;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr214;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr214;
		} else if ( (*p) >= 65 )
			goto tr214;
	} else
		goto tr214;
	goto tr166;
tr215:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st154;
st154:
	if ( ++p == pe )
		goto _test_eof154;
case 154:
#line 3820 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 34 )
		goto st148;
	goto tr156;
st155:
	if ( ++p == pe )
		goto _test_eof155;
case 155:
	if ( (*p) == 10 )
		goto tr47;
	goto tr156;
tr217:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st156;
tr181:
#line 119 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_key(*this, "Number");
    }
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st156;
st156:
	if ( ++p == pe )
		goto _test_eof156;
case 156:
#line 3855 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 44 )
		goto tr182;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr217;
	goto tr179;
tr27:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st157;
st157:
	if ( ++p == pe )
		goto _test_eof157;
case 157:
#line 3875 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr34;
		case 61: goto tr36;
		case 78: goto tr219;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr35;
	goto tr218;
tr219:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st158;
st158:
	if ( ++p == pe )
		goto _test_eof158;
case 158:
#line 3894 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr34;
		case 61: goto tr36;
		case 70: goto tr220;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr35;
	goto tr218;
tr220:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st159;
st159:
	if ( ++p == pe )
		goto _test_eof159;
case 159:
#line 3913 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr34;
		case 61: goto tr36;
		case 79: goto tr221;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr35;
	goto tr218;
tr221:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st160;
st160:
	if ( ++p == pe )
		goto _test_eof160;
case 160:
#line 3932 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr34;
		case 61: goto tr222;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr35;
	goto tr218;
tr222:
#line 99 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "INFO");
    }
	goto st161;
st161:
	if ( ++p == pe )
		goto _test_eof161;
case 161:
#line 3950 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 60 )
		goto st162;
	goto tr218;
st162:
	if ( ++p == pe )
		goto _test_eof162;
case 162:
	if ( (*p) == 73 )
		goto st163;
	goto tr218;
st163:
	if ( ++p == pe )
		goto _test_eof163;
case 163:
	if ( (*p) == 68 )
		goto st164;
	goto tr218;
st164:
	if ( ++p == pe )
		goto _test_eof164;
case 164:
	if ( (*p) == 61 )
		goto st165;
	goto tr218;
st165:
	if ( ++p == pe )
		goto _test_eof165;
case 165:
	if ( (*p) == 95 )
		goto tr228;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr228;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr229;
		} else if ( (*p) >= 65 )
			goto tr229;
	} else
		goto tr229;
	goto tr227;
tr228:
#line 115 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_key(*this, "ID");
    }
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st166;
st166:
	if ( ++p == pe )
		goto _test_eof166;
case 166:
#line 4007 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 95 )
		goto st166;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st166;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr231;
		} else if ( (*p) >= 65 )
			goto tr231;
	} else
		goto tr231;
	goto tr227;
tr231:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st167;
tr229:
#line 115 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_key(*this, "ID");
    }
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st167;
st167:
	if ( ++p == pe )
		goto _test_eof167;
case 167:
#line 4046 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto tr232;
		case 95: goto tr231;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr231;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr231;
		} else if ( (*p) >= 65 )
			goto tr231;
	} else
		goto tr231;
	goto tr227;
tr232:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st168;
st168:
	if ( ++p == pe )
		goto _test_eof168;
case 168:
#line 4073 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 78 )
		goto st169;
	goto tr218;
st169:
	if ( ++p == pe )
		goto _test_eof169;
case 169:
	if ( (*p) == 117 )
		goto st170;
	goto tr218;
st170:
	if ( ++p == pe )
		goto _test_eof170;
case 170:
	if ( (*p) == 109 )
		goto st171;
	goto tr218;
st171:
	if ( ++p == pe )
		goto _test_eof171;
case 171:
	if ( (*p) == 98 )
		goto st172;
	goto tr218;
st172:
	if ( ++p == pe )
		goto _test_eof172;
case 172:
	if ( (*p) == 101 )
		goto st173;
	goto tr218;
st173:
	if ( ++p == pe )
		goto _test_eof173;
case 173:
	if ( (*p) == 114 )
		goto st174;
	goto tr218;
st174:
	if ( ++p == pe )
		goto _test_eof174;
case 174:
	if ( (*p) == 61 )
		goto st175;
	goto tr218;
st175:
	if ( ++p == pe )
		goto _test_eof175;
case 175:
	switch( (*p) ) {
		case 46: goto tr241;
		case 65: goto tr241;
		case 71: goto tr241;
		case 82: goto tr241;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr242;
	goto tr240;
tr241:
#line 119 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_key(*this, "Number");
    }
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st176;
st176:
	if ( ++p == pe )
		goto _test_eof176;
case 176:
#line 4150 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 44 )
		goto tr243;
	goto tr240;
tr243:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st177;
st177:
	if ( ++p == pe )
		goto _test_eof177;
case 177:
#line 4164 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 84 )
		goto st178;
	goto tr218;
st178:
	if ( ++p == pe )
		goto _test_eof178;
case 178:
	if ( (*p) == 121 )
		goto st179;
	goto tr218;
st179:
	if ( ++p == pe )
		goto _test_eof179;
case 179:
	if ( (*p) == 112 )
		goto st180;
	goto tr218;
st180:
	if ( ++p == pe )
		goto _test_eof180;
case 180:
	if ( (*p) == 101 )
		goto st181;
	goto tr218;
st181:
	if ( ++p == pe )
		goto _test_eof181;
case 181:
	if ( (*p) == 61 )
		goto st182;
	goto tr218;
st182:
	if ( ++p == pe )
		goto _test_eof182;
case 182:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr250;
	} else if ( (*p) >= 65 )
		goto tr250;
	goto tr249;
tr252:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st183;
tr250:
#line 123 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_key(*this, "Type");
    }
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st183;
st183:
	if ( ++p == pe )
		goto _test_eof183;
case 183:
#line 4230 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 44 )
		goto tr251;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr252;
	} else if ( (*p) >= 65 )
		goto tr252;
	goto tr249;
tr251:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st184;
st184:
	if ( ++p == pe )
		goto _test_eof184;
case 184:
#line 4249 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 68 )
		goto st185;
	goto tr218;
st185:
	if ( ++p == pe )
		goto _test_eof185;
case 185:
	if ( (*p) == 101 )
		goto st186;
	goto tr218;
st186:
	if ( ++p == pe )
		goto _test_eof186;
case 186:
	if ( (*p) == 115 )
		goto st187;
	goto tr218;
st187:
	if ( ++p == pe )
		goto _test_eof187;
case 187:
	if ( (*p) == 99 )
		goto st188;
	goto tr218;
st188:
	if ( ++p == pe )
		goto _test_eof188;
case 188:
	if ( (*p) == 114 )
		goto st189;
	goto tr218;
st189:
	if ( ++p == pe )
		goto _test_eof189;
case 189:
	if ( (*p) == 105 )
		goto st190;
	goto tr218;
st190:
	if ( ++p == pe )
		goto _test_eof190;
case 190:
	if ( (*p) == 112 )
		goto st191;
	goto tr218;
st191:
	if ( ++p == pe )
		goto _test_eof191;
case 191:
	if ( (*p) == 116 )
		goto st192;
	goto tr218;
st192:
	if ( ++p == pe )
		goto _test_eof192;
case 192:
	if ( (*p) == 105 )
		goto st193;
	goto tr218;
st193:
	if ( ++p == pe )
		goto _test_eof193;
case 193:
	if ( (*p) == 111 )
		goto st194;
	goto tr218;
st194:
	if ( ++p == pe )
		goto _test_eof194;
case 194:
	if ( (*p) == 110 )
		goto st195;
	goto tr218;
st195:
	if ( ++p == pe )
		goto _test_eof195;
case 195:
	if ( (*p) == 61 )
		goto st196;
	goto tr218;
st196:
	if ( ++p == pe )
		goto _test_eof196;
case 196:
	if ( (*p) == 34 )
		goto tr265;
	goto tr218;
tr265:
#line 127 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_key(*this, "Description");
    }
	goto st197;
st197:
	if ( ++p == pe )
		goto _test_eof197;
case 197:
#line 4347 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) > 33 ) {
		if ( 35 <= (*p) && (*p) <= 126 )
			goto tr266;
	} else if ( (*p) >= 32 )
		goto tr266;
	goto tr218;
tr266:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st198;
tr268:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st198;
st198:
	if ( ++p == pe )
		goto _test_eof198;
case 198:
#line 4374 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 34 )
		goto tr269;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr268;
	goto tr267;
tr269:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st199;
st199:
	if ( ++p == pe )
		goto _test_eof199;
case 199:
#line 4390 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto st200;
		case 62: goto st204;
	}
	goto tr267;
st200:
	if ( ++p == pe )
		goto _test_eof200;
case 200:
	if ( (*p) == 95 )
		goto tr272;
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
	goto tr227;
tr272:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st201;
st201:
	if ( ++p == pe )
		goto _test_eof201;
case 201:
#line 4424 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 95 )
		goto st201;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st201;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr275;
		} else if ( (*p) >= 65 )
			goto tr275;
	} else
		goto tr275;
	goto tr227;
tr273:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st202;
tr275:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st202;
st202:
	if ( ++p == pe )
		goto _test_eof202;
case 202:
#line 4459 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
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
	goto tr227;
tr276:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st203;
st203:
	if ( ++p == pe )
		goto _test_eof203;
case 203:
#line 4486 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 34 )
		goto st197;
	goto tr218;
st204:
	if ( ++p == pe )
		goto _test_eof204;
case 204:
	if ( (*p) == 10 )
		goto tr47;
	goto tr218;
tr278:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st205;
tr242:
#line 119 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_key(*this, "Number");
    }
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st205;
st205:
	if ( ++p == pe )
		goto _test_eof205;
case 205:
#line 4521 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 44 )
		goto tr243;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr278;
	goto tr240;
tr28:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st206;
st206:
	if ( ++p == pe )
		goto _test_eof206;
case 206:
#line 4541 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr34;
		case 61: goto tr36;
		case 69: goto tr280;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr35;
	goto tr279;
tr280:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st207;
st207:
	if ( ++p == pe )
		goto _test_eof207;
case 207:
#line 4560 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr34;
		case 61: goto tr36;
		case 68: goto tr281;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr35;
	goto tr279;
tr281:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st208;
st208:
	if ( ++p == pe )
		goto _test_eof208;
case 208:
#line 4579 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr34;
		case 61: goto tr36;
		case 73: goto tr282;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr35;
	goto tr279;
tr282:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st209;
st209:
	if ( ++p == pe )
		goto _test_eof209;
case 209:
#line 4598 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr34;
		case 61: goto tr36;
		case 71: goto tr283;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr35;
	goto tr279;
tr283:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st210;
st210:
	if ( ++p == pe )
		goto _test_eof210;
case 210:
#line 4617 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr34;
		case 61: goto tr36;
		case 82: goto tr284;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr35;
	goto tr279;
tr284:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st211;
st211:
	if ( ++p == pe )
		goto _test_eof211;
case 211:
#line 4636 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr34;
		case 61: goto tr36;
		case 69: goto tr285;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr35;
	goto tr279;
tr285:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st212;
st212:
	if ( ++p == pe )
		goto _test_eof212;
case 212:
#line 4655 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr34;
		case 61: goto tr36;
		case 69: goto tr286;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr35;
	goto tr279;
tr286:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st213;
st213:
	if ( ++p == pe )
		goto _test_eof213;
case 213:
#line 4674 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr34;
		case 61: goto tr287;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr35;
	goto tr279;
tr287:
#line 103 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "PEDIGREE");
    }
	goto st214;
st214:
	if ( ++p == pe )
		goto _test_eof214;
case 214:
#line 4692 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 60 )
		goto st215;
	goto tr279;
tr299:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st215;
st215:
	if ( ++p == pe )
		goto _test_eof215;
case 215:
#line 4706 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 95 )
		goto tr290;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr290;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr291;
		} else if ( (*p) >= 65 )
			goto tr291;
	} else
		goto tr291;
	goto tr289;
tr290:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st216;
st216:
	if ( ++p == pe )
		goto _test_eof216;
case 216:
#line 4731 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 95 )
		goto st216;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st216;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr293;
		} else if ( (*p) >= 65 )
			goto tr293;
	} else
		goto tr293;
	goto tr289;
tr291:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st217;
tr293:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st217;
st217:
	if ( ++p == pe )
		goto _test_eof217;
case 217:
#line 4766 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 61: goto tr294;
		case 95: goto tr293;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr293;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr293;
		} else if ( (*p) >= 65 )
			goto tr293;
	} else
		goto tr293;
	goto tr289;
tr294:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st218;
st218:
	if ( ++p == pe )
		goto _test_eof218;
case 218:
#line 4793 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 95 )
		goto tr295;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr295;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr296;
		} else if ( (*p) >= 65 )
			goto tr296;
	} else
		goto tr296;
	goto tr289;
tr295:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st219;
st219:
	if ( ++p == pe )
		goto _test_eof219;
case 219:
#line 4818 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 95 )
		goto st219;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st219;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr298;
		} else if ( (*p) >= 65 )
			goto tr298;
	} else
		goto tr298;
	goto tr289;
tr296:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st220;
tr298:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st220;
st220:
	if ( ++p == pe )
		goto _test_eof220;
case 220:
#line 4853 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto tr299;
		case 62: goto tr300;
		case 95: goto tr298;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr298;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr298;
		} else if ( (*p) >= 65 )
			goto tr298;
	} else
		goto tr298;
	goto tr289;
tr300:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st221;
st221:
	if ( ++p == pe )
		goto _test_eof221;
case 221:
#line 4881 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 10 )
		goto tr47;
	goto tr279;
tr29:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st222;
st222:
	if ( ++p == pe )
		goto _test_eof222;
case 222:
#line 4899 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr34;
		case 61: goto tr36;
		case 65: goto tr302;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr35;
	goto tr301;
tr302:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st223;
st223:
	if ( ++p == pe )
		goto _test_eof223;
case 223:
#line 4918 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr34;
		case 61: goto tr36;
		case 77: goto tr303;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr35;
	goto tr301;
tr303:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st224;
st224:
	if ( ++p == pe )
		goto _test_eof224;
case 224:
#line 4937 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr34;
		case 61: goto tr36;
		case 80: goto tr304;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr35;
	goto tr301;
tr304:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st225;
st225:
	if ( ++p == pe )
		goto _test_eof225;
case 225:
#line 4956 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr34;
		case 61: goto tr36;
		case 76: goto tr305;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr35;
	goto tr301;
tr305:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st226;
st226:
	if ( ++p == pe )
		goto _test_eof226;
case 226:
#line 4975 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr34;
		case 61: goto tr36;
		case 69: goto tr306;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr35;
	goto tr301;
tr306:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st227;
st227:
	if ( ++p == pe )
		goto _test_eof227;
case 227:
#line 4994 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr34;
		case 61: goto tr307;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr35;
	goto tr301;
tr307:
#line 111 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "SAMPLE");
    }
	goto st228;
st228:
	if ( ++p == pe )
		goto _test_eof228;
case 228:
#line 5012 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 60 )
		goto st229;
	goto tr301;
st229:
	if ( ++p == pe )
		goto _test_eof229;
case 229:
	if ( (*p) == 73 )
		goto st230;
	goto tr301;
st230:
	if ( ++p == pe )
		goto _test_eof230;
case 230:
	if ( (*p) == 68 )
		goto st231;
	goto tr301;
st231:
	if ( ++p == pe )
		goto _test_eof231;
case 231:
	if ( (*p) == 61 )
		goto st232;
	goto tr301;
st232:
	if ( ++p == pe )
		goto _test_eof232;
case 232:
	if ( (*p) == 95 )
		goto tr313;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr313;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr314;
		} else if ( (*p) >= 65 )
			goto tr314;
	} else
		goto tr314;
	goto tr312;
tr313:
#line 115 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_key(*this, "ID");
    }
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st233;
st233:
	if ( ++p == pe )
		goto _test_eof233;
case 233:
#line 5069 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 95 )
		goto st233;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st233;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr316;
		} else if ( (*p) >= 65 )
			goto tr316;
	} else
		goto tr316;
	goto tr312;
tr316:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st234;
tr314:
#line 115 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_key(*this, "ID");
    }
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st234;
st234:
	if ( ++p == pe )
		goto _test_eof234;
case 234:
#line 5108 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto tr318;
		case 95: goto tr316;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr316;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr316;
		} else if ( (*p) >= 65 )
			goto tr316;
	} else
		goto tr316;
	goto tr317;
tr318:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st235;
st235:
	if ( ++p == pe )
		goto _test_eof235;
case 235:
#line 5135 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 71 )
		goto st236;
	goto tr319;
st236:
	if ( ++p == pe )
		goto _test_eof236;
case 236:
	if ( (*p) == 101 )
		goto st237;
	goto tr319;
st237:
	if ( ++p == pe )
		goto _test_eof237;
case 237:
	if ( (*p) == 110 )
		goto st238;
	goto tr319;
st238:
	if ( ++p == pe )
		goto _test_eof238;
case 238:
	if ( (*p) == 111 )
		goto st239;
	goto tr319;
st239:
	if ( ++p == pe )
		goto _test_eof239;
case 239:
	if ( (*p) == 109 )
		goto st240;
	goto tr319;
st240:
	if ( ++p == pe )
		goto _test_eof240;
case 240:
	if ( (*p) == 101 )
		goto st241;
	goto tr319;
st241:
	if ( ++p == pe )
		goto _test_eof241;
case 241:
	if ( (*p) == 115 )
		goto st242;
	goto tr319;
st242:
	if ( ++p == pe )
		goto _test_eof242;
case 242:
	if ( (*p) == 61 )
		goto st243;
	goto tr319;
st243:
	if ( ++p == pe )
		goto _test_eof243;
case 243:
	if ( (*p) < 35 ) {
		if ( 32 <= (*p) && (*p) <= 33 )
			goto tr328;
	} else if ( (*p) > 43 ) {
		if ( (*p) > 61 ) {
			if ( 63 <= (*p) && (*p) <= 126 )
				goto tr328;
		} else if ( (*p) >= 45 )
			goto tr328;
	} else
		goto tr328;
	goto tr319;
tr330:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st244;
tr328:
#line 131 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_key(*this, "Genomes");
    }
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st244;
st244:
	if ( ++p == pe )
		goto _test_eof244;
case 244:
#line 5228 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 44 )
		goto tr331;
	if ( (*p) < 35 ) {
		if ( 32 <= (*p) && (*p) <= 33 )
			goto tr330;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr330;
	} else
		goto tr330;
	goto tr329;
tr331:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st245;
st245:
	if ( ++p == pe )
		goto _test_eof245;
case 245:
#line 5250 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 77 )
		goto st246;
	goto tr332;
st246:
	if ( ++p == pe )
		goto _test_eof246;
case 246:
	if ( (*p) == 105 )
		goto st247;
	goto tr332;
st247:
	if ( ++p == pe )
		goto _test_eof247;
case 247:
	if ( (*p) == 120 )
		goto st248;
	goto tr332;
st248:
	if ( ++p == pe )
		goto _test_eof248;
case 248:
	if ( (*p) == 116 )
		goto st249;
	goto tr332;
st249:
	if ( ++p == pe )
		goto _test_eof249;
case 249:
	if ( (*p) == 117 )
		goto st250;
	goto tr332;
st250:
	if ( ++p == pe )
		goto _test_eof250;
case 250:
	if ( (*p) == 114 )
		goto st251;
	goto tr332;
st251:
	if ( ++p == pe )
		goto _test_eof251;
case 251:
	if ( (*p) == 101 )
		goto st252;
	goto tr332;
st252:
	if ( ++p == pe )
		goto _test_eof252;
case 252:
	if ( (*p) == 61 )
		goto st253;
	goto tr332;
st253:
	if ( ++p == pe )
		goto _test_eof253;
case 253:
	if ( (*p) < 35 ) {
		if ( 32 <= (*p) && (*p) <= 33 )
			goto tr341;
	} else if ( (*p) > 43 ) {
		if ( (*p) > 61 ) {
			if ( 63 <= (*p) && (*p) <= 126 )
				goto tr341;
		} else if ( (*p) >= 45 )
			goto tr341;
	} else
		goto tr341;
	goto tr332;
tr343:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st254;
tr341:
#line 135 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_key(*this, "Mixture");
    }
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st254;
st254:
	if ( ++p == pe )
		goto _test_eof254;
case 254:
#line 5343 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 44 )
		goto tr344;
	if ( (*p) < 35 ) {
		if ( 32 <= (*p) && (*p) <= 33 )
			goto tr343;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr343;
	} else
		goto tr343;
	goto tr342;
tr344:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st255;
st255:
	if ( ++p == pe )
		goto _test_eof255;
case 255:
#line 5365 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 68 )
		goto st256;
	goto tr345;
st256:
	if ( ++p == pe )
		goto _test_eof256;
case 256:
	if ( (*p) == 101 )
		goto st257;
	goto tr345;
st257:
	if ( ++p == pe )
		goto _test_eof257;
case 257:
	if ( (*p) == 115 )
		goto st258;
	goto tr345;
st258:
	if ( ++p == pe )
		goto _test_eof258;
case 258:
	if ( (*p) == 99 )
		goto st259;
	goto tr345;
st259:
	if ( ++p == pe )
		goto _test_eof259;
case 259:
	if ( (*p) == 114 )
		goto st260;
	goto tr345;
st260:
	if ( ++p == pe )
		goto _test_eof260;
case 260:
	if ( (*p) == 105 )
		goto st261;
	goto tr345;
st261:
	if ( ++p == pe )
		goto _test_eof261;
case 261:
	if ( (*p) == 112 )
		goto st262;
	goto tr345;
st262:
	if ( ++p == pe )
		goto _test_eof262;
case 262:
	if ( (*p) == 116 )
		goto st263;
	goto tr345;
st263:
	if ( ++p == pe )
		goto _test_eof263;
case 263:
	if ( (*p) == 105 )
		goto st264;
	goto tr345;
st264:
	if ( ++p == pe )
		goto _test_eof264;
case 264:
	if ( (*p) == 111 )
		goto st265;
	goto tr345;
st265:
	if ( ++p == pe )
		goto _test_eof265;
case 265:
	if ( (*p) == 110 )
		goto st266;
	goto tr345;
st266:
	if ( ++p == pe )
		goto _test_eof266;
case 266:
	if ( (*p) == 61 )
		goto st267;
	goto tr345;
st267:
	if ( ++p == pe )
		goto _test_eof267;
case 267:
	if ( (*p) == 34 )
		goto tr358;
	goto tr345;
tr358:
#line 127 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_key(*this, "Description");
    }
	goto st268;
st268:
	if ( ++p == pe )
		goto _test_eof268;
case 268:
#line 5463 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) > 33 ) {
		if ( 35 <= (*p) && (*p) <= 126 )
			goto tr359;
	} else if ( (*p) >= 32 )
		goto tr359;
	goto tr345;
tr359:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st269;
tr360:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st269;
st269:
	if ( ++p == pe )
		goto _test_eof269;
case 269:
#line 5490 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 34 )
		goto tr361;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr360;
	goto tr345;
tr361:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st270;
st270:
	if ( ++p == pe )
		goto _test_eof270;
case 270:
#line 5506 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 62 )
		goto st271;
	goto tr345;
st271:
	if ( ++p == pe )
		goto _test_eof271;
case 271:
	if ( (*p) == 10 )
		goto tr47;
	goto tr301;
tr30:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st272;
st272:
	if ( ++p == pe )
		goto _test_eof272;
case 272:
#line 5531 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr34;
		case 61: goto tr36;
		case 115: goto tr364;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr35;
	goto tr363;
tr364:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st273;
st273:
	if ( ++p == pe )
		goto _test_eof273;
case 273:
#line 5550 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr34;
		case 61: goto tr36;
		case 115: goto tr365;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr35;
	goto tr363;
tr365:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st274;
st274:
	if ( ++p == pe )
		goto _test_eof274;
case 274:
#line 5569 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr34;
		case 61: goto tr36;
		case 101: goto tr366;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr35;
	goto tr363;
tr366:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st275;
st275:
	if ( ++p == pe )
		goto _test_eof275;
case 275:
#line 5588 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr34;
		case 61: goto tr36;
		case 109: goto tr367;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr35;
	goto tr363;
tr367:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st276;
st276:
	if ( ++p == pe )
		goto _test_eof276;
case 276:
#line 5607 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr34;
		case 61: goto tr36;
		case 98: goto tr368;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr35;
	goto tr363;
tr368:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st277;
st277:
	if ( ++p == pe )
		goto _test_eof277;
case 277:
#line 5626 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr34;
		case 61: goto tr36;
		case 108: goto tr369;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr35;
	goto tr363;
tr369:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st278;
st278:
	if ( ++p == pe )
		goto _test_eof278;
case 278:
#line 5645 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr34;
		case 61: goto tr36;
		case 121: goto tr370;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr35;
	goto tr363;
tr370:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st279;
st279:
	if ( ++p == pe )
		goto _test_eof279;
case 279:
#line 5664 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr34;
		case 61: goto tr371;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr35;
	goto tr363;
tr371:
#line 83 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "assembly");
    }
	goto st280;
st280:
	if ( ++p == pe )
		goto _test_eof280;
case 280:
#line 5682 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr373;
	} else if ( (*p) >= 65 )
		goto tr373;
	goto tr372;
tr373:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st281;
st281:
	if ( ++p == pe )
		goto _test_eof281;
case 281:
#line 5699 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr372;
		case 35: goto tr372;
		case 47: goto tr372;
		case 58: goto tr372;
		case 63: goto tr372;
	}
	goto st282;
st282:
	if ( ++p == pe )
		goto _test_eof282;
case 282:
	switch( (*p) ) {
		case 10: goto tr372;
		case 35: goto tr372;
		case 47: goto tr372;
		case 58: goto st283;
		case 63: goto tr372;
	}
	goto st282;
st283:
	if ( ++p == pe )
		goto _test_eof283;
case 283:
	if ( (*p) == 47 )
		goto st284;
	goto tr372;
st284:
	if ( ++p == pe )
		goto _test_eof284;
case 284:
	if ( (*p) == 47 )
		goto st285;
	goto tr372;
st285:
	if ( ++p == pe )
		goto _test_eof285;
case 285:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr378;
	} else if ( (*p) >= 65 )
		goto tr378;
	goto tr372;
tr378:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st286;
st286:
	if ( ++p == pe )
		goto _test_eof286;
case 286:
#line 5754 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 10 )
		goto tr34;
	goto tr378;
tr31:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st287;
st287:
	if ( ++p == pe )
		goto _test_eof287;
case 287:
#line 5772 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr34;
		case 61: goto tr36;
		case 111: goto tr380;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr35;
	goto tr379;
tr380:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st288;
st288:
	if ( ++p == pe )
		goto _test_eof288;
case 288:
#line 5791 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr34;
		case 61: goto tr36;
		case 110: goto tr381;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr35;
	goto tr379;
tr381:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st289;
st289:
	if ( ++p == pe )
		goto _test_eof289;
case 289:
#line 5810 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr34;
		case 61: goto tr36;
		case 116: goto tr382;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr35;
	goto tr379;
tr382:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st290;
st290:
	if ( ++p == pe )
		goto _test_eof290;
case 290:
#line 5829 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr34;
		case 61: goto tr36;
		case 105: goto tr383;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr35;
	goto tr379;
tr383:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st291;
st291:
	if ( ++p == pe )
		goto _test_eof291;
case 291:
#line 5848 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr34;
		case 61: goto tr36;
		case 103: goto tr384;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr35;
	goto tr379;
tr384:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st292;
st292:
	if ( ++p == pe )
		goto _test_eof292;
case 292:
#line 5867 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr34;
		case 61: goto tr385;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr35;
	goto tr379;
tr385:
#line 87 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "contig");
    }
	goto st293;
st293:
	if ( ++p == pe )
		goto _test_eof293;
case 293:
#line 5885 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 60 )
		goto st294;
	goto tr379;
st294:
	if ( ++p == pe )
		goto _test_eof294;
case 294:
	if ( (*p) == 73 )
		goto st295;
	goto tr379;
st295:
	if ( ++p == pe )
		goto _test_eof295;
case 295:
	if ( (*p) == 68 )
		goto st296;
	goto tr379;
st296:
	if ( ++p == pe )
		goto _test_eof296;
case 296:
	if ( (*p) == 61 )
		goto st297;
	goto tr379;
st297:
	if ( ++p == pe )
		goto _test_eof297;
case 297:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr391;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr391;
	} else
		goto tr391;
	goto tr390;
tr391:
#line 115 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_key(*this, "ID");
    }
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st298;
st298:
	if ( ++p == pe )
		goto _test_eof298;
case 298:
#line 5941 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto tr393;
		case 59: goto tr392;
		case 62: goto tr395;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr392;
		} else if ( (*p) > 57 ) {
			if ( 61 <= (*p) && (*p) <= 64 )
				goto tr392;
		} else
			goto tr394;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr392;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr392;
		} else
			goto tr394;
	} else
		goto tr394;
	goto tr390;
tr392:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st299;
st299:
	if ( ++p == pe )
		goto _test_eof299;
case 299:
#line 5978 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr392;
		case 61: goto tr392;
	}
	if ( (*p) < 63 ) {
		if ( (*p) < 45 ) {
			if ( 33 <= (*p) && (*p) <= 43 )
				goto tr392;
		} else if ( (*p) > 47 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr394;
		} else
			goto tr392;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr394;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr392;
			} else if ( (*p) >= 97 )
				goto tr394;
		} else
			goto tr392;
	} else
		goto tr392;
	goto tr390;
tr394:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st300;
st300:
	if ( ++p == pe )
		goto _test_eof300;
case 300:
#line 6017 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto tr393;
		case 59: goto tr394;
		case 62: goto tr395;
	}
	if ( (*p) > 57 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr394;
	} else if ( (*p) >= 33 )
		goto tr394;
	goto tr390;
tr393:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st301;
st301:
	if ( ++p == pe )
		goto _test_eof301;
case 301:
#line 6039 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 95 )
		goto tr396;
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
	goto tr379;
tr396:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st302;
st302:
	if ( ++p == pe )
		goto _test_eof302;
case 302:
#line 6064 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 95 )
		goto st302;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st302;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr399;
		} else if ( (*p) >= 65 )
			goto tr399;
	} else
		goto tr399;
	goto tr379;
tr397:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st303;
tr399:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st303;
st303:
	if ( ++p == pe )
		goto _test_eof303;
case 303:
#line 6099 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 61: goto tr400;
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
	goto tr379;
tr400:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st304;
st304:
	if ( ++p == pe )
		goto _test_eof304;
case 304:
#line 6126 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 34 )
		goto st307;
	if ( (*p) < 45 ) {
		if ( 32 <= (*p) && (*p) <= 43 )
			goto tr401;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr401;
	} else
		goto tr401;
	goto tr379;
tr401:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st305;
tr403:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st305;
st305:
	if ( ++p == pe )
		goto _test_eof305;
case 305:
#line 6158 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto tr393;
		case 62: goto tr395;
	}
	if ( (*p) > 33 ) {
		if ( 35 <= (*p) && (*p) <= 126 )
			goto tr403;
	} else if ( (*p) >= 32 )
		goto tr403;
	goto tr379;
tr395:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st306;
st306:
	if ( ++p == pe )
		goto _test_eof306;
case 306:
#line 6179 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 10 )
		goto tr47;
	goto tr379;
st307:
	if ( ++p == pe )
		goto _test_eof307;
case 307:
	if ( (*p) > 33 ) {
		if ( 35 <= (*p) && (*p) <= 126 )
			goto tr404;
	} else if ( (*p) >= 32 )
		goto tr404;
	goto tr379;
tr404:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st308;
tr405:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st308;
st308:
	if ( ++p == pe )
		goto _test_eof308;
case 308:
#line 6213 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 34 )
		goto tr406;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr405;
	goto tr379;
tr406:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st309;
st309:
	if ( ++p == pe )
		goto _test_eof309;
case 309:
#line 6229 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto st301;
		case 62: goto st306;
	}
	goto tr379;
tr32:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st310;
st310:
	if ( ++p == pe )
		goto _test_eof310;
case 310:
#line 6249 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr34;
		case 61: goto tr36;
		case 101: goto tr410;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr35;
	goto tr409;
tr410:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st311;
st311:
	if ( ++p == pe )
		goto _test_eof311;
case 311:
#line 6268 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr34;
		case 61: goto tr36;
		case 100: goto tr411;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr35;
	goto tr409;
tr411:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st312;
st312:
	if ( ++p == pe )
		goto _test_eof312;
case 312:
#line 6287 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr34;
		case 61: goto tr36;
		case 105: goto tr412;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr35;
	goto tr409;
tr412:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st313;
st313:
	if ( ++p == pe )
		goto _test_eof313;
case 313:
#line 6306 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr34;
		case 61: goto tr36;
		case 103: goto tr413;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr35;
	goto tr409;
tr413:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st314;
st314:
	if ( ++p == pe )
		goto _test_eof314;
case 314:
#line 6325 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr34;
		case 61: goto tr36;
		case 114: goto tr414;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr35;
	goto tr409;
tr414:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st315;
st315:
	if ( ++p == pe )
		goto _test_eof315;
case 315:
#line 6344 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr34;
		case 61: goto tr36;
		case 101: goto tr415;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr35;
	goto tr409;
tr415:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st316;
st316:
	if ( ++p == pe )
		goto _test_eof316;
case 316:
#line 6363 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr34;
		case 61: goto tr36;
		case 101: goto tr416;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr35;
	goto tr409;
tr416:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st317;
st317:
	if ( ++p == pe )
		goto _test_eof317;
case 317:
#line 6382 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr34;
		case 61: goto tr36;
		case 68: goto tr417;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr35;
	goto tr409;
tr417:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st318;
st318:
	if ( ++p == pe )
		goto _test_eof318;
case 318:
#line 6401 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr34;
		case 61: goto tr36;
		case 66: goto tr418;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr35;
	goto tr409;
tr418:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st319;
st319:
	if ( ++p == pe )
		goto _test_eof319;
case 319:
#line 6420 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr34;
		case 61: goto tr419;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr35;
	goto tr409;
tr419:
#line 107 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "pedigreeDB");
    }
	goto st320;
st320:
	if ( ++p == pe )
		goto _test_eof320;
case 320:
#line 6438 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 60 )
		goto st321;
	goto tr409;
st321:
	if ( ++p == pe )
		goto _test_eof321;
case 321:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr422;
	} else if ( (*p) >= 65 )
		goto tr422;
	goto tr421;
tr422:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st322;
st322:
	if ( ++p == pe )
		goto _test_eof322;
case 322:
#line 6462 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr421;
		case 35: goto tr421;
		case 47: goto tr421;
		case 58: goto tr421;
		case 63: goto tr421;
	}
	goto st323;
st323:
	if ( ++p == pe )
		goto _test_eof323;
case 323:
	switch( (*p) ) {
		case 10: goto tr421;
		case 35: goto tr421;
		case 47: goto tr421;
		case 58: goto st324;
		case 63: goto tr421;
	}
	goto st323;
st324:
	if ( ++p == pe )
		goto _test_eof324;
case 324:
	if ( (*p) == 47 )
		goto st325;
	goto tr421;
st325:
	if ( ++p == pe )
		goto _test_eof325;
case 325:
	if ( (*p) == 47 )
		goto st326;
	goto tr421;
st326:
	if ( ++p == pe )
		goto _test_eof326;
case 326:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr427;
	} else if ( (*p) >= 65 )
		goto tr427;
	goto tr421;
tr427:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st327;
st327:
	if ( ++p == pe )
		goto _test_eof327;
case 327:
#line 6517 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr421;
		case 62: goto tr428;
	}
	goto tr427;
tr428:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st328;
st328:
	if ( ++p == pe )
		goto _test_eof328;
case 328:
#line 6537 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr47;
		case 62: goto tr428;
	}
	goto tr427;
st329:
	if ( ++p == pe )
		goto _test_eof329;
case 329:
	if ( (*p) == 72 )
		goto st330;
	goto tr429;
st330:
	if ( ++p == pe )
		goto _test_eof330;
case 330:
	if ( (*p) == 82 )
		goto st331;
	goto tr429;
st331:
	if ( ++p == pe )
		goto _test_eof331;
case 331:
	if ( (*p) == 79 )
		goto st332;
	goto tr429;
st332:
	if ( ++p == pe )
		goto _test_eof332;
case 332:
	if ( (*p) == 77 )
		goto st333;
	goto tr429;
st333:
	if ( ++p == pe )
		goto _test_eof333;
case 333:
	if ( (*p) == 9 )
		goto st334;
	goto tr429;
st334:
	if ( ++p == pe )
		goto _test_eof334;
case 334:
	if ( (*p) == 80 )
		goto st335;
	goto tr429;
st335:
	if ( ++p == pe )
		goto _test_eof335;
case 335:
	if ( (*p) == 79 )
		goto st336;
	goto tr429;
st336:
	if ( ++p == pe )
		goto _test_eof336;
case 336:
	if ( (*p) == 83 )
		goto st337;
	goto tr429;
st337:
	if ( ++p == pe )
		goto _test_eof337;
case 337:
	if ( (*p) == 9 )
		goto st338;
	goto tr429;
st338:
	if ( ++p == pe )
		goto _test_eof338;
case 338:
	if ( (*p) == 73 )
		goto st339;
	goto tr429;
st339:
	if ( ++p == pe )
		goto _test_eof339;
case 339:
	if ( (*p) == 68 )
		goto st340;
	goto tr429;
st340:
	if ( ++p == pe )
		goto _test_eof340;
case 340:
	if ( (*p) == 9 )
		goto st341;
	goto tr429;
st341:
	if ( ++p == pe )
		goto _test_eof341;
case 341:
	if ( (*p) == 82 )
		goto st342;
	goto tr429;
st342:
	if ( ++p == pe )
		goto _test_eof342;
case 342:
	if ( (*p) == 69 )
		goto st343;
	goto tr429;
st343:
	if ( ++p == pe )
		goto _test_eof343;
case 343:
	if ( (*p) == 70 )
		goto st344;
	goto tr429;
st344:
	if ( ++p == pe )
		goto _test_eof344;
case 344:
	if ( (*p) == 9 )
		goto st345;
	goto tr429;
st345:
	if ( ++p == pe )
		goto _test_eof345;
case 345:
	if ( (*p) == 65 )
		goto st346;
	goto tr429;
st346:
	if ( ++p == pe )
		goto _test_eof346;
case 346:
	if ( (*p) == 76 )
		goto st347;
	goto tr429;
st347:
	if ( ++p == pe )
		goto _test_eof347;
case 347:
	if ( (*p) == 84 )
		goto st348;
	goto tr429;
st348:
	if ( ++p == pe )
		goto _test_eof348;
case 348:
	if ( (*p) == 9 )
		goto st349;
	goto tr429;
st349:
	if ( ++p == pe )
		goto _test_eof349;
case 349:
	if ( (*p) == 81 )
		goto st350;
	goto tr429;
st350:
	if ( ++p == pe )
		goto _test_eof350;
case 350:
	if ( (*p) == 85 )
		goto st351;
	goto tr429;
st351:
	if ( ++p == pe )
		goto _test_eof351;
case 351:
	if ( (*p) == 65 )
		goto st352;
	goto tr429;
st352:
	if ( ++p == pe )
		goto _test_eof352;
case 352:
	if ( (*p) == 76 )
		goto st353;
	goto tr429;
st353:
	if ( ++p == pe )
		goto _test_eof353;
case 353:
	if ( (*p) == 9 )
		goto st354;
	goto tr429;
st354:
	if ( ++p == pe )
		goto _test_eof354;
case 354:
	if ( (*p) == 70 )
		goto st355;
	goto tr429;
st355:
	if ( ++p == pe )
		goto _test_eof355;
case 355:
	if ( (*p) == 73 )
		goto st356;
	goto tr429;
st356:
	if ( ++p == pe )
		goto _test_eof356;
case 356:
	if ( (*p) == 76 )
		goto st357;
	goto tr429;
st357:
	if ( ++p == pe )
		goto _test_eof357;
case 357:
	if ( (*p) == 84 )
		goto st358;
	goto tr429;
st358:
	if ( ++p == pe )
		goto _test_eof358;
case 358:
	if ( (*p) == 69 )
		goto st359;
	goto tr429;
st359:
	if ( ++p == pe )
		goto _test_eof359;
case 359:
	if ( (*p) == 82 )
		goto st360;
	goto tr429;
st360:
	if ( ++p == pe )
		goto _test_eof360;
case 360:
	if ( (*p) == 9 )
		goto st361;
	goto tr429;
st361:
	if ( ++p == pe )
		goto _test_eof361;
case 361:
	if ( (*p) == 73 )
		goto st362;
	goto tr429;
st362:
	if ( ++p == pe )
		goto _test_eof362;
case 362:
	if ( (*p) == 78 )
		goto st363;
	goto tr429;
st363:
	if ( ++p == pe )
		goto _test_eof363;
case 363:
	if ( (*p) == 70 )
		goto st364;
	goto tr429;
st364:
	if ( ++p == pe )
		goto _test_eof364;
case 364:
	if ( (*p) == 79 )
		goto st365;
	goto tr429;
st365:
	if ( ++p == pe )
		goto _test_eof365;
case 365:
	switch( (*p) ) {
		case 9: goto st366;
		case 10: goto tr467;
	}
	goto tr429;
st366:
	if ( ++p == pe )
		goto _test_eof366;
case 366:
	if ( (*p) == 70 )
		goto st367;
	goto tr468;
st367:
	if ( ++p == pe )
		goto _test_eof367;
case 367:
	if ( (*p) == 79 )
		goto st368;
	goto tr468;
st368:
	if ( ++p == pe )
		goto _test_eof368;
case 368:
	if ( (*p) == 82 )
		goto st369;
	goto tr468;
st369:
	if ( ++p == pe )
		goto _test_eof369;
case 369:
	if ( (*p) == 77 )
		goto st370;
	goto tr468;
st370:
	if ( ++p == pe )
		goto _test_eof370;
case 370:
	if ( (*p) == 65 )
		goto st371;
	goto tr468;
st371:
	if ( ++p == pe )
		goto _test_eof371;
case 371:
	if ( (*p) == 84 )
		goto st372;
	goto tr468;
st372:
	if ( ++p == pe )
		goto _test_eof372;
case 372:
	if ( (*p) == 9 )
		goto st373;
	goto tr468;
tr477:
#line 155 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_sample_name(*this);
    }
	goto st373;
st373:
	if ( ++p == pe )
		goto _test_eof373;
case 373:
#line 6863 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr476;
	goto tr468;
tr476:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st374;
tr479:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st374;
st374:
	if ( ++p == pe )
		goto _test_eof374;
case 374:
#line 6887 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr477;
		case 10: goto tr478;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr479;
	goto tr468;
tr467:
#line 159 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_header_line(*this);
    }
#line 27 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st598;
tr478:
#line 155 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_sample_name(*this);
    }
#line 159 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_header_line(*this);
    }
#line 27 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st598;
st598:
	if ( ++p == pe )
		goto _test_eof598;
case 598:
#line 6935 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 60 )
		goto st398;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr760;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr760;
	} else
		goto tr760;
	goto tr759;
tr760:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st375;
st375:
	if ( ++p == pe )
		goto _test_eof375;
case 375:
#line 6961 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr481;
		case 59: goto tr482;
		case 61: goto tr482;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr482;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr482;
		} else
			goto tr483;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr482;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr482;
		} else
			goto tr483;
	} else
		goto tr483;
	goto tr480;
tr481:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 165 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 37 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ++n_columns;
    }
	goto st376;
tr560:
#line 165 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 37 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ++n_columns;
    }
	goto st376;
st376:
	if ( ++p == pe )
		goto _test_eof376;
case 376:
#line 7016 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 45 )
		goto tr485;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr486;
	goto tr484;
tr485:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st377;
st377:
	if ( ++p == pe )
		goto _test_eof377;
case 377:
#line 7032 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr487;
	goto tr484;
tr486:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st378;
tr487:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st378;
st378:
	if ( ++p == pe )
		goto _test_eof378;
case 378:
#line 7056 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 9 )
		goto tr488;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr487;
	goto tr484;
tr493:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st379;
tr488:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 165 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 37 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ++n_columns;
    }
	goto st379;
st379:
	if ( ++p == pe )
		goto _test_eof379;
case 379:
#line 7086 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr490;
	} else if ( (*p) >= 33 )
		goto tr490;
	goto tr489;
tr490:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st380;
tr492:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st380;
st380:
	if ( ++p == pe )
		goto _test_eof380;
case 380:
#line 7113 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr491;
		case 59: goto tr493;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr492;
	goto tr489;
tr491:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 165 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 37 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ++n_columns;
    }
	goto st381;
st381:
	if ( ++p == pe )
		goto _test_eof381;
case 381:
#line 7139 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 65: goto tr495;
		case 67: goto tr495;
		case 71: goto tr495;
		case 78: goto tr495;
		case 84: goto tr495;
		case 97: goto tr495;
		case 99: goto tr495;
		case 103: goto tr495;
		case 110: goto tr495;
		case 116: goto tr495;
	}
	goto tr494;
tr495:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st382;
tr497:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st382;
st382:
	if ( ++p == pe )
		goto _test_eof382;
case 382:
#line 7173 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr496;
		case 65: goto tr497;
		case 67: goto tr497;
		case 71: goto tr497;
		case 78: goto tr497;
		case 84: goto tr497;
		case 97: goto tr497;
		case 99: goto tr497;
		case 103: goto tr497;
		case 110: goto tr497;
		case 116: goto tr497;
	}
	goto tr494;
tr496:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 165 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 37 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ++n_columns;
    }
	goto st383;
st383:
	if ( ++p == pe )
		goto _test_eof383;
case 383:
#line 7206 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 42: goto tr499;
		case 46: goto tr500;
		case 60: goto tr501;
		case 65: goto tr502;
		case 67: goto tr502;
		case 71: goto tr502;
		case 78: goto tr502;
		case 84: goto tr502;
		case 91: goto tr503;
		case 93: goto tr504;
		case 97: goto tr502;
		case 99: goto tr502;
		case 103: goto tr502;
		case 110: goto tr502;
		case 116: goto tr502;
	}
	goto tr498;
tr499:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st384;
tr706:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st384;
st384:
	if ( ++p == pe )
		goto _test_eof384;
case 384:
#line 7245 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr505;
		case 44: goto tr506;
	}
	goto tr498;
tr505:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 165 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 37 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ++n_columns;
    }
	goto st385;
st385:
	if ( ++p == pe )
		goto _test_eof385;
case 385:
#line 7269 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 45: goto tr508;
		case 46: goto tr509;
		case 48: goto tr510;
	}
	if ( 49 <= (*p) && (*p) <= 57 )
		goto tr511;
	goto tr507;
tr508:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st386;
st386:
	if ( ++p == pe )
		goto _test_eof386;
case 386:
#line 7292 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 48 )
		goto tr512;
	if ( 49 <= (*p) && (*p) <= 57 )
		goto tr513;
	goto tr507;
tr510:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st387;
tr512:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st387;
st387:
	if ( ++p == pe )
		goto _test_eof387;
case 387:
#line 7318 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr514;
		case 46: goto tr515;
		case 69: goto tr516;
		case 101: goto tr516;
	}
	goto tr507;
tr514:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 165 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 37 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ++n_columns;
    }
	goto st388;
st388:
	if ( ++p == pe )
		goto _test_eof388;
case 388:
#line 7344 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 46: goto tr519;
		case 58: goto tr518;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr518;
		} else if ( (*p) > 57 ) {
			if ( 60 <= (*p) && (*p) <= 64 )
				goto tr518;
		} else
			goto tr520;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr518;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr518;
		} else
			goto tr520;
	} else
		goto tr520;
	goto tr517;
tr518:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st389;
st389:
	if ( ++p == pe )
		goto _test_eof389;
case 389:
#line 7380 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 58 )
		goto st389;
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto st389;
		} else if ( (*p) > 57 ) {
			if ( 60 <= (*p) && (*p) <= 64 )
				goto st389;
		} else
			goto tr522;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st389;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st389;
		} else
			goto tr522;
	} else
		goto tr522;
	goto tr517;
tr520:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st390;
tr522:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st390;
st390:
	if ( ++p == pe )
		goto _test_eof390;
case 390:
#line 7424 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr523;
		case 59: goto tr524;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr522;
	goto tr517;
tr523:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 165 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 37 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ++n_columns;
    }
	goto st391;
st391:
	if ( ++p == pe )
		goto _test_eof391;
case 391:
#line 7450 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 46: goto tr527;
		case 49: goto tr529;
		case 58: goto tr526;
		case 60: goto tr526;
		case 65: goto tr530;
		case 66: goto tr531;
		case 67: goto tr532;
		case 68: goto tr533;
		case 69: goto tr534;
		case 72: goto tr535;
		case 77: goto tr536;
		case 78: goto tr537;
		case 83: goto tr538;
		case 86: goto tr539;
	}
	if ( (*p) < 70 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr526;
		} else if ( (*p) > 57 ) {
			if ( 62 <= (*p) && (*p) <= 64 )
				goto tr526;
		} else
			goto tr528;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr526;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr526;
		} else
			goto tr528;
	} else
		goto tr528;
	goto tr525;
tr526:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st392;
tr540:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st392;
st392:
	if ( ++p == pe )
		goto _test_eof392;
case 392:
#line 7508 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 58: goto tr540;
		case 60: goto tr540;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr540;
		} else if ( (*p) > 57 ) {
			if ( 62 <= (*p) && (*p) <= 64 )
				goto tr540;
		} else
			goto tr541;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr540;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr540;
		} else
			goto tr541;
	} else
		goto tr541;
	goto tr525;
tr528:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st393;
tr541:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st393;
st393:
	if ( ++p == pe )
		goto _test_eof393;
case 393:
#line 7554 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
		case 59: goto tr544;
		case 61: goto tr545;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr541;
	goto tr525;
tr550:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st394;
tr542:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 165 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 37 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ++n_columns;
    }
	goto st394;
st394:
	if ( ++p == pe )
		goto _test_eof394;
case 394:
#line 7588 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 95 )
		goto tr547;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr547;
	} else if ( (*p) >= 65 )
		goto tr547;
	goto tr546;
tr547:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st395;
tr549:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st395;
st395:
	if ( ++p == pe )
		goto _test_eof395;
case 395:
#line 7617 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr548;
		case 46: goto tr549;
		case 58: goto tr550;
		case 95: goto tr549;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr549;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr549;
	} else
		goto tr549;
	goto tr546;
tr548:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 165 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 37 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ++n_columns;
    }
	goto st396;
st396:
	if ( ++p == pe )
		goto _test_eof396;
case 396:
#line 7651 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 46 )
		goto tr552;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr553;
	goto tr551;
tr552:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st397;
tr561:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st397;
st397:
	if ( ++p == pe )
		goto _test_eof397;
case 397:
#line 7677 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr548;
		case 10: goto tr543;
		case 47: goto tr554;
		case 58: goto tr555;
		case 124: goto tr554;
	}
	goto tr551;
tr543:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
#line 165 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
    }
#line 169 "cpp/src/bioformats/vcf/vcf_v41.ragel"
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
#line 27 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
	goto st599;
st599:
	if ( ++p == pe )
		goto _test_eof599;
case 599:
#line 7723 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 60 )
		goto st398;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr760;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr760;
	} else
		goto tr760;
	goto tr480;
st398:
	if ( ++p == pe )
		goto _test_eof398;
case 398:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr556;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr556;
	} else
		goto tr556;
	goto tr480;
tr556:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st399;
st399:
	if ( ++p == pe )
		goto _test_eof399;
case 399:
#line 7762 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr557;
		case 62: goto tr559;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr557;
		} else if ( (*p) > 57 ) {
			if ( 61 <= (*p) && (*p) <= 64 )
				goto tr557;
		} else
			goto tr558;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr557;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr557;
		} else
			goto tr558;
	} else
		goto tr558;
	goto tr480;
tr557:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st400;
st400:
	if ( ++p == pe )
		goto _test_eof400;
case 400:
#line 7798 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr557;
		case 61: goto tr557;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr557;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr557;
		} else
			goto tr558;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr557;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr557;
		} else
			goto tr558;
	} else
		goto tr558;
	goto tr480;
tr558:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st401;
st401:
	if ( ++p == pe )
		goto _test_eof401;
case 401:
#line 7834 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr558;
		case 62: goto tr559;
	}
	if ( (*p) > 57 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr558;
	} else if ( (*p) >= 33 )
		goto tr558;
	goto tr480;
tr559:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st402;
st402:
	if ( ++p == pe )
		goto _test_eof402;
case 402:
#line 7855 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 9 )
		goto tr560;
	goto tr480;
tr554:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st403;
st403:
	if ( ++p == pe )
		goto _test_eof403;
case 403:
#line 7869 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 46 )
		goto tr561;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr562;
	goto tr551;
tr553:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st404;
tr562:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st404;
st404:
	if ( ++p == pe )
		goto _test_eof404;
case 404:
#line 7895 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr548;
		case 10: goto tr543;
		case 47: goto tr554;
		case 58: goto tr555;
		case 124: goto tr554;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr562;
	goto tr551;
tr555:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st405;
st405:
	if ( ++p == pe )
		goto _test_eof405;
case 405:
#line 7916 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) > 57 ) {
		if ( 59 <= (*p) && (*p) <= 126 )
			goto tr564;
	} else if ( (*p) >= 33 )
		goto tr564;
	goto tr563;
tr564:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st406;
st406:
	if ( ++p == pe )
		goto _test_eof406;
case 406:
#line 7933 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr548;
		case 10: goto tr543;
		case 58: goto tr555;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr564;
	goto tr563;
tr544:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st407;
st407:
	if ( ++p == pe )
		goto _test_eof407;
case 407:
#line 7952 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 49: goto tr529;
		case 58: goto tr526;
		case 60: goto tr526;
		case 65: goto tr530;
		case 66: goto tr531;
		case 67: goto tr532;
		case 68: goto tr533;
		case 69: goto tr534;
		case 72: goto tr535;
		case 77: goto tr536;
		case 78: goto tr537;
		case 83: goto tr538;
		case 86: goto tr539;
	}
	if ( (*p) < 70 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr526;
		} else if ( (*p) > 57 ) {
			if ( 62 <= (*p) && (*p) <= 64 )
				goto tr526;
		} else
			goto tr528;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr526;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr526;
		} else
			goto tr528;
	} else
		goto tr528;
	goto tr525;
tr529:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st408;
st408:
	if ( ++p == pe )
		goto _test_eof408;
case 408:
#line 8003 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
		case 48: goto tr565;
		case 59: goto tr544;
		case 61: goto tr545;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr541;
	goto tr525;
tr565:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st409;
st409:
	if ( ++p == pe )
		goto _test_eof409;
case 409:
#line 8024 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
		case 48: goto tr566;
		case 59: goto tr544;
		case 61: goto tr545;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr541;
	goto tr525;
tr566:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st410;
st410:
	if ( ++p == pe )
		goto _test_eof410;
case 410:
#line 8045 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
		case 48: goto tr567;
		case 59: goto tr544;
		case 61: goto tr545;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr541;
	goto tr525;
tr567:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st411;
st411:
	if ( ++p == pe )
		goto _test_eof411;
case 411:
#line 8066 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
		case 59: goto tr544;
		case 61: goto tr545;
		case 71: goto tr568;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr541;
	goto tr525;
tr545:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st412;
st412:
	if ( ++p == pe )
		goto _test_eof412;
case 412:
#line 8087 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr570;
	} else if ( (*p) >= 33 )
		goto tr570;
	goto tr569;
tr570:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st413;
st413:
	if ( ++p == pe )
		goto _test_eof413;
case 413:
#line 8104 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
		case 59: goto tr544;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr570;
	goto tr569;
tr568:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st414;
st414:
	if ( ++p == pe )
		goto _test_eof414;
case 414:
#line 8123 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
		case 59: goto tr544;
		case 61: goto tr572;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr541;
	goto tr571;
tr572:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st415;
st415:
	if ( ++p == pe )
		goto _test_eof415;
case 415:
#line 8143 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 49 )
		goto tr574;
	goto tr573;
tr574:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st416;
st416:
	if ( ++p == pe )
		goto _test_eof416;
case 416:
#line 8157 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
		case 59: goto tr544;
	}
	goto tr573;
tr530:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st417;
st417:
	if ( ++p == pe )
		goto _test_eof417;
case 417:
#line 8178 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
		case 59: goto tr544;
		case 61: goto tr545;
		case 65: goto tr575;
		case 67: goto tr576;
		case 70: goto tr577;
		case 78: goto tr578;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr541;
	goto tr525;
tr575:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st418;
st418:
	if ( ++p == pe )
		goto _test_eof418;
case 418:
#line 8202 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 61 )
		goto tr579;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr541;
	} else if ( (*p) >= 33 )
		goto tr541;
	goto tr525;
tr579:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st419;
st419:
	if ( ++p == pe )
		goto _test_eof419;
case 419:
#line 8221 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 46: goto tr581;
		case 65: goto tr582;
		case 67: goto tr582;
		case 71: goto tr582;
		case 78: goto tr582;
		case 84: goto tr582;
		case 97: goto tr582;
		case 99: goto tr582;
		case 103: goto tr582;
		case 110: goto tr582;
		case 116: goto tr582;
	}
	goto tr580;
tr581:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st420;
st420:
	if ( ++p == pe )
		goto _test_eof420;
case 420:
#line 8246 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
		case 59: goto tr544;
	}
	goto tr580;
tr582:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st421;
st421:
	if ( ++p == pe )
		goto _test_eof421;
case 421:
#line 8263 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
		case 59: goto tr544;
		case 65: goto tr582;
		case 67: goto tr582;
		case 71: goto tr582;
		case 78: goto tr582;
		case 84: goto tr582;
		case 97: goto tr582;
		case 99: goto tr582;
		case 103: goto tr582;
		case 110: goto tr582;
		case 116: goto tr582;
	}
	goto tr580;
tr576:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st422;
st422:
	if ( ++p == pe )
		goto _test_eof422;
case 422:
#line 8290 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 61 )
		goto tr583;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr541;
	} else if ( (*p) >= 33 )
		goto tr541;
	goto tr525;
tr583:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st423;
st423:
	if ( ++p == pe )
		goto _test_eof423;
case 423:
#line 8309 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 45 )
		goto tr585;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr586;
	goto tr584;
tr585:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st424;
st424:
	if ( ++p == pe )
		goto _test_eof424;
case 424:
#line 8325 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr586;
	goto tr584;
tr586:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st425;
st425:
	if ( ++p == pe )
		goto _test_eof425;
case 425:
#line 8339 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
		case 44: goto tr583;
		case 59: goto tr544;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr586;
	goto tr584;
tr577:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st426;
st426:
	if ( ++p == pe )
		goto _test_eof426;
case 426:
#line 8359 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 61 )
		goto tr587;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr541;
	} else if ( (*p) >= 33 )
		goto tr541;
	goto tr525;
tr587:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st427;
st427:
	if ( ++p == pe )
		goto _test_eof427;
case 427:
#line 8378 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 45: goto tr589;
		case 48: goto tr590;
	}
	if ( 49 <= (*p) && (*p) <= 57 )
		goto tr591;
	goto tr588;
tr589:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st428;
st428:
	if ( ++p == pe )
		goto _test_eof428;
case 428:
#line 8396 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 48 )
		goto tr590;
	if ( 49 <= (*p) && (*p) <= 57 )
		goto tr591;
	goto tr588;
tr590:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st429;
st429:
	if ( ++p == pe )
		goto _test_eof429;
case 429:
#line 8412 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
		case 44: goto tr587;
		case 46: goto tr592;
		case 59: goto tr544;
		case 69: goto tr593;
		case 101: goto tr593;
	}
	goto tr588;
tr592:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st430;
st430:
	if ( ++p == pe )
		goto _test_eof430;
case 430:
#line 8433 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr594;
	goto tr588;
tr594:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st431;
st431:
	if ( ++p == pe )
		goto _test_eof431;
case 431:
#line 8447 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
		case 44: goto tr587;
		case 59: goto tr544;
		case 69: goto tr593;
		case 101: goto tr593;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr594;
	goto tr588;
tr593:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st432;
st432:
	if ( ++p == pe )
		goto _test_eof432;
case 432:
#line 8469 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 43: goto tr595;
		case 45: goto tr595;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr596;
	goto tr588;
tr595:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st433;
st433:
	if ( ++p == pe )
		goto _test_eof433;
case 433:
#line 8487 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr596;
	goto tr588;
tr596:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st434;
st434:
	if ( ++p == pe )
		goto _test_eof434;
case 434:
#line 8501 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
		case 44: goto tr587;
		case 59: goto tr544;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr596;
	goto tr588;
tr591:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st435;
st435:
	if ( ++p == pe )
		goto _test_eof435;
case 435:
#line 8521 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
		case 44: goto tr587;
		case 46: goto tr592;
		case 59: goto tr544;
		case 69: goto tr593;
		case 101: goto tr593;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr591;
	goto tr588;
tr578:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st436;
st436:
	if ( ++p == pe )
		goto _test_eof436;
case 436:
#line 8544 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 61 )
		goto tr597;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr541;
	} else if ( (*p) >= 33 )
		goto tr541;
	goto tr525;
tr597:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st437;
st437:
	if ( ++p == pe )
		goto _test_eof437;
case 437:
#line 8563 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 45 )
		goto tr599;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr600;
	goto tr598;
tr599:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st438;
st438:
	if ( ++p == pe )
		goto _test_eof438;
case 438:
#line 8579 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr600;
	goto tr598;
tr600:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st439;
st439:
	if ( ++p == pe )
		goto _test_eof439;
case 439:
#line 8593 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
		case 59: goto tr544;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr600;
	goto tr598;
tr531:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st440;
st440:
	if ( ++p == pe )
		goto _test_eof440;
case 440:
#line 8616 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
		case 59: goto tr544;
		case 61: goto tr545;
		case 81: goto tr601;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr541;
	goto tr525;
tr601:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st441;
st441:
	if ( ++p == pe )
		goto _test_eof441;
case 441:
#line 8637 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 61 )
		goto tr602;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr541;
	} else if ( (*p) >= 33 )
		goto tr541;
	goto tr525;
tr602:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st442;
st442:
	if ( ++p == pe )
		goto _test_eof442;
case 442:
#line 8656 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 45: goto tr604;
		case 48: goto tr605;
	}
	if ( 49 <= (*p) && (*p) <= 57 )
		goto tr606;
	goto tr603;
tr604:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st443;
st443:
	if ( ++p == pe )
		goto _test_eof443;
case 443:
#line 8674 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 48 )
		goto tr605;
	if ( 49 <= (*p) && (*p) <= 57 )
		goto tr606;
	goto tr603;
tr605:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st444;
st444:
	if ( ++p == pe )
		goto _test_eof444;
case 444:
#line 8690 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
		case 46: goto tr607;
		case 59: goto tr544;
		case 69: goto tr608;
		case 101: goto tr608;
	}
	goto tr603;
tr607:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st445;
st445:
	if ( ++p == pe )
		goto _test_eof445;
case 445:
#line 8710 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr609;
	goto tr603;
tr609:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st446;
st446:
	if ( ++p == pe )
		goto _test_eof446;
case 446:
#line 8724 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
		case 59: goto tr544;
		case 69: goto tr608;
		case 101: goto tr608;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr609;
	goto tr603;
tr608:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st447;
st447:
	if ( ++p == pe )
		goto _test_eof447;
case 447:
#line 8745 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 43: goto tr610;
		case 45: goto tr610;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr611;
	goto tr603;
tr610:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st448;
st448:
	if ( ++p == pe )
		goto _test_eof448;
case 448:
#line 8763 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr611;
	goto tr603;
tr611:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st449;
st449:
	if ( ++p == pe )
		goto _test_eof449;
case 449:
#line 8777 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
		case 59: goto tr544;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr611;
	goto tr603;
tr606:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st450;
st450:
	if ( ++p == pe )
		goto _test_eof450;
case 450:
#line 8796 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
		case 46: goto tr607;
		case 59: goto tr544;
		case 69: goto tr608;
		case 101: goto tr608;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr606;
	goto tr603;
tr532:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st451;
st451:
	if ( ++p == pe )
		goto _test_eof451;
case 451:
#line 8822 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
		case 59: goto tr544;
		case 61: goto tr545;
		case 73: goto tr612;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr541;
	goto tr525;
tr612:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st452;
st452:
	if ( ++p == pe )
		goto _test_eof452;
case 452:
#line 8843 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
		case 59: goto tr544;
		case 61: goto tr545;
		case 71: goto tr613;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr541;
	goto tr525;
tr613:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st453;
st453:
	if ( ++p == pe )
		goto _test_eof453;
case 453:
#line 8864 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
		case 59: goto tr544;
		case 61: goto tr545;
		case 65: goto tr614;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr541;
	goto tr525;
tr614:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st454;
st454:
	if ( ++p == pe )
		goto _test_eof454;
case 454:
#line 8885 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
		case 59: goto tr544;
		case 61: goto tr545;
		case 82: goto tr615;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr541;
	goto tr525;
tr615:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st455;
st455:
	if ( ++p == pe )
		goto _test_eof455;
case 455:
#line 8906 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 61 )
		goto tr616;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr541;
	} else if ( (*p) >= 33 )
		goto tr541;
	goto tr525;
tr616:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st456;
st456:
	if ( ++p == pe )
		goto _test_eof456;
case 456:
#line 8925 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr618;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr618;
	} else
		goto tr618;
	goto tr617;
tr618:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st457;
st457:
	if ( ++p == pe )
		goto _test_eof457;
case 457:
#line 8945 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
		case 59: goto tr544;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr618;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr618;
	} else
		goto tr618;
	goto tr617;
tr533:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st458;
st458:
	if ( ++p == pe )
		goto _test_eof458;
case 458:
#line 8974 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
		case 59: goto tr544;
		case 61: goto tr545;
		case 66: goto tr619;
		case 80: goto tr620;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr541;
	goto tr525;
tr619:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st459;
st459:
	if ( ++p == pe )
		goto _test_eof459;
case 459:
#line 8996 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
		case 59: goto tr544;
		case 61: goto tr622;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr541;
	goto tr621;
tr622:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st460;
st460:
	if ( ++p == pe )
		goto _test_eof460;
case 460:
#line 9016 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 49 )
		goto tr624;
	goto tr623;
tr624:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st461;
st461:
	if ( ++p == pe )
		goto _test_eof461;
case 461:
#line 9030 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
		case 59: goto tr544;
	}
	goto tr623;
tr620:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st462;
st462:
	if ( ++p == pe )
		goto _test_eof462;
case 462:
#line 9047 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 61 )
		goto tr625;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr541;
	} else if ( (*p) >= 33 )
		goto tr541;
	goto tr525;
tr625:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st463;
st463:
	if ( ++p == pe )
		goto _test_eof463;
case 463:
#line 9066 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 45 )
		goto tr627;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr628;
	goto tr626;
tr627:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st464;
st464:
	if ( ++p == pe )
		goto _test_eof464;
case 464:
#line 9082 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr628;
	goto tr626;
tr628:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st465;
st465:
	if ( ++p == pe )
		goto _test_eof465;
case 465:
#line 9096 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
		case 59: goto tr544;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr628;
	goto tr626;
tr534:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st466;
st466:
	if ( ++p == pe )
		goto _test_eof466;
case 466:
#line 9119 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
		case 59: goto tr544;
		case 61: goto tr545;
		case 78: goto tr629;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr541;
	goto tr525;
tr629:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st467;
st467:
	if ( ++p == pe )
		goto _test_eof467;
case 467:
#line 9140 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
		case 59: goto tr544;
		case 61: goto tr545;
		case 68: goto tr630;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr541;
	goto tr525;
tr630:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st468;
st468:
	if ( ++p == pe )
		goto _test_eof468;
case 468:
#line 9161 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 61 )
		goto tr631;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr541;
	} else if ( (*p) >= 33 )
		goto tr541;
	goto tr525;
tr631:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st469;
st469:
	if ( ++p == pe )
		goto _test_eof469;
case 469:
#line 9180 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 45 )
		goto tr633;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr634;
	goto tr632;
tr633:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st470;
st470:
	if ( ++p == pe )
		goto _test_eof470;
case 470:
#line 9196 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr634;
	goto tr632;
tr634:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st471;
st471:
	if ( ++p == pe )
		goto _test_eof471;
case 471:
#line 9210 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
		case 59: goto tr544;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr634;
	goto tr632;
tr535:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st472;
st472:
	if ( ++p == pe )
		goto _test_eof472;
case 472:
#line 9233 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
		case 50: goto tr635;
		case 51: goto tr636;
		case 59: goto tr544;
		case 61: goto tr545;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr541;
	goto tr525;
tr635:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st473;
st473:
	if ( ++p == pe )
		goto _test_eof473;
case 473:
#line 9255 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
		case 59: goto tr544;
		case 61: goto tr638;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr541;
	goto tr637;
tr638:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st474;
st474:
	if ( ++p == pe )
		goto _test_eof474;
case 474:
#line 9275 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 49 )
		goto tr640;
	goto tr639;
tr640:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st475;
st475:
	if ( ++p == pe )
		goto _test_eof475;
case 475:
#line 9289 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
		case 59: goto tr544;
	}
	goto tr639;
tr636:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st476;
st476:
	if ( ++p == pe )
		goto _test_eof476;
case 476:
#line 9306 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
		case 59: goto tr544;
		case 61: goto tr642;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr541;
	goto tr641;
tr642:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st477;
st477:
	if ( ++p == pe )
		goto _test_eof477;
case 477:
#line 9326 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 49 )
		goto tr644;
	goto tr643;
tr644:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st478;
st478:
	if ( ++p == pe )
		goto _test_eof478;
case 478:
#line 9340 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
		case 59: goto tr544;
	}
	goto tr643;
tr536:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st479;
st479:
	if ( ++p == pe )
		goto _test_eof479;
case 479:
#line 9361 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
		case 59: goto tr544;
		case 61: goto tr545;
		case 81: goto tr645;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr541;
	goto tr525;
tr645:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st480;
st480:
	if ( ++p == pe )
		goto _test_eof480;
case 480:
#line 9382 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 48: goto tr646;
		case 61: goto tr647;
	}
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr541;
	} else if ( (*p) >= 33 )
		goto tr541;
	goto tr525;
tr646:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st481;
st481:
	if ( ++p == pe )
		goto _test_eof481;
case 481:
#line 9403 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 61 )
		goto tr648;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr541;
	} else if ( (*p) >= 33 )
		goto tr541;
	goto tr525;
tr648:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st482;
st482:
	if ( ++p == pe )
		goto _test_eof482;
case 482:
#line 9422 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 45 )
		goto tr650;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr651;
	goto tr649;
tr650:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st483;
st483:
	if ( ++p == pe )
		goto _test_eof483;
case 483:
#line 9438 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr651;
	goto tr649;
tr651:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st484;
st484:
	if ( ++p == pe )
		goto _test_eof484;
case 484:
#line 9452 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
		case 59: goto tr544;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr651;
	goto tr649;
tr647:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st485;
st485:
	if ( ++p == pe )
		goto _test_eof485;
case 485:
#line 9471 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 45: goto tr653;
		case 48: goto tr654;
	}
	if ( 49 <= (*p) && (*p) <= 57 )
		goto tr655;
	goto tr652;
tr653:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st486;
st486:
	if ( ++p == pe )
		goto _test_eof486;
case 486:
#line 9489 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 48 )
		goto tr654;
	if ( 49 <= (*p) && (*p) <= 57 )
		goto tr655;
	goto tr652;
tr654:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st487;
st487:
	if ( ++p == pe )
		goto _test_eof487;
case 487:
#line 9505 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
		case 46: goto tr656;
		case 59: goto tr544;
		case 69: goto tr657;
		case 101: goto tr657;
	}
	goto tr652;
tr656:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st488;
st488:
	if ( ++p == pe )
		goto _test_eof488;
case 488:
#line 9525 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr658;
	goto tr652;
tr658:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st489;
st489:
	if ( ++p == pe )
		goto _test_eof489;
case 489:
#line 9539 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
		case 59: goto tr544;
		case 69: goto tr657;
		case 101: goto tr657;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr658;
	goto tr652;
tr657:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st490;
st490:
	if ( ++p == pe )
		goto _test_eof490;
case 490:
#line 9560 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 43: goto tr659;
		case 45: goto tr659;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr660;
	goto tr652;
tr659:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st491;
st491:
	if ( ++p == pe )
		goto _test_eof491;
case 491:
#line 9578 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr660;
	goto tr652;
tr660:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st492;
st492:
	if ( ++p == pe )
		goto _test_eof492;
case 492:
#line 9592 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
		case 59: goto tr544;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr660;
	goto tr652;
tr655:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st493;
st493:
	if ( ++p == pe )
		goto _test_eof493;
case 493:
#line 9611 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
		case 46: goto tr656;
		case 59: goto tr544;
		case 69: goto tr657;
		case 101: goto tr657;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr655;
	goto tr652;
tr537:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st494;
st494:
	if ( ++p == pe )
		goto _test_eof494;
case 494:
#line 9637 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
		case 59: goto tr544;
		case 61: goto tr545;
		case 83: goto tr661;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr541;
	goto tr525;
tr661:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st495;
st495:
	if ( ++p == pe )
		goto _test_eof495;
case 495:
#line 9658 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 61 )
		goto tr662;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr541;
	} else if ( (*p) >= 33 )
		goto tr541;
	goto tr525;
tr662:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st496;
st496:
	if ( ++p == pe )
		goto _test_eof496;
case 496:
#line 9677 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 45 )
		goto tr664;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr665;
	goto tr663;
tr664:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st497;
st497:
	if ( ++p == pe )
		goto _test_eof497;
case 497:
#line 9693 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr665;
	goto tr663;
tr665:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st498;
st498:
	if ( ++p == pe )
		goto _test_eof498;
case 498:
#line 9707 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
		case 59: goto tr544;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr665;
	goto tr663;
tr538:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st499;
st499:
	if ( ++p == pe )
		goto _test_eof499;
case 499:
#line 9730 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
		case 59: goto tr544;
		case 61: goto tr545;
		case 66: goto tr666;
		case 79: goto tr667;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr541;
	goto tr525;
tr666:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st500;
st500:
	if ( ++p == pe )
		goto _test_eof500;
case 500:
#line 9752 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 61 )
		goto tr668;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr541;
	} else if ( (*p) >= 33 )
		goto tr541;
	goto tr525;
tr668:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st501;
st501:
	if ( ++p == pe )
		goto _test_eof501;
case 501:
#line 9771 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 45: goto tr670;
		case 48: goto tr671;
	}
	if ( 49 <= (*p) && (*p) <= 57 )
		goto tr672;
	goto tr669;
tr670:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st502;
st502:
	if ( ++p == pe )
		goto _test_eof502;
case 502:
#line 9789 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 48 )
		goto tr671;
	if ( 49 <= (*p) && (*p) <= 57 )
		goto tr672;
	goto tr669;
tr671:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st503;
st503:
	if ( ++p == pe )
		goto _test_eof503;
case 503:
#line 9805 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
		case 46: goto tr673;
		case 59: goto tr544;
		case 69: goto tr674;
		case 101: goto tr674;
	}
	goto tr669;
tr673:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st504;
st504:
	if ( ++p == pe )
		goto _test_eof504;
case 504:
#line 9825 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr675;
	goto tr669;
tr675:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st505;
st505:
	if ( ++p == pe )
		goto _test_eof505;
case 505:
#line 9839 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
		case 59: goto tr544;
		case 69: goto tr674;
		case 101: goto tr674;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr675;
	goto tr669;
tr674:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st506;
st506:
	if ( ++p == pe )
		goto _test_eof506;
case 506:
#line 9860 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 43: goto tr676;
		case 45: goto tr676;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr677;
	goto tr669;
tr676:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st507;
st507:
	if ( ++p == pe )
		goto _test_eof507;
case 507:
#line 9878 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr677;
	goto tr669;
tr677:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st508;
st508:
	if ( ++p == pe )
		goto _test_eof508;
case 508:
#line 9892 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
		case 59: goto tr544;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr677;
	goto tr669;
tr672:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st509;
st509:
	if ( ++p == pe )
		goto _test_eof509;
case 509:
#line 9911 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
		case 46: goto tr673;
		case 59: goto tr544;
		case 69: goto tr674;
		case 101: goto tr674;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr672;
	goto tr669;
tr667:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st510;
st510:
	if ( ++p == pe )
		goto _test_eof510;
case 510:
#line 9933 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
		case 59: goto tr544;
		case 61: goto tr545;
		case 77: goto tr678;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr541;
	goto tr525;
tr678:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st511;
st511:
	if ( ++p == pe )
		goto _test_eof511;
case 511:
#line 9954 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
		case 59: goto tr544;
		case 61: goto tr545;
		case 65: goto tr679;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr541;
	goto tr525;
tr679:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st512;
st512:
	if ( ++p == pe )
		goto _test_eof512;
case 512:
#line 9975 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
		case 59: goto tr544;
		case 61: goto tr545;
		case 84: goto tr680;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr541;
	goto tr525;
tr680:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st513;
st513:
	if ( ++p == pe )
		goto _test_eof513;
case 513:
#line 9996 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
		case 59: goto tr544;
		case 61: goto tr545;
		case 73: goto tr681;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr541;
	goto tr525;
tr681:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st514;
st514:
	if ( ++p == pe )
		goto _test_eof514;
case 514:
#line 10017 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
		case 59: goto tr544;
		case 61: goto tr545;
		case 67: goto tr682;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr541;
	goto tr525;
tr682:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st515;
st515:
	if ( ++p == pe )
		goto _test_eof515;
case 515:
#line 10038 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
		case 59: goto tr544;
		case 61: goto tr684;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr541;
	goto tr683;
tr684:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st516;
st516:
	if ( ++p == pe )
		goto _test_eof516;
case 516:
#line 10058 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 49 )
		goto tr686;
	goto tr685;
tr686:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st517;
st517:
	if ( ++p == pe )
		goto _test_eof517;
case 517:
#line 10072 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
		case 59: goto tr544;
	}
	goto tr685;
tr539:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st518;
st518:
	if ( ++p == pe )
		goto _test_eof518;
case 518:
#line 10093 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
		case 59: goto tr544;
		case 61: goto tr545;
		case 65: goto tr687;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr541;
	goto tr525;
tr687:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st519;
st519:
	if ( ++p == pe )
		goto _test_eof519;
case 519:
#line 10114 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
		case 59: goto tr544;
		case 61: goto tr545;
		case 76: goto tr688;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr541;
	goto tr525;
tr688:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st520;
st520:
	if ( ++p == pe )
		goto _test_eof520;
case 520:
#line 10135 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
		case 59: goto tr544;
		case 61: goto tr545;
		case 73: goto tr689;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr541;
	goto tr525;
tr689:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st521;
st521:
	if ( ++p == pe )
		goto _test_eof521;
case 521:
#line 10156 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
		case 59: goto tr544;
		case 61: goto tr545;
		case 68: goto tr690;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr541;
	goto tr525;
tr690:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st522;
st522:
	if ( ++p == pe )
		goto _test_eof522;
case 522:
#line 10177 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
		case 59: goto tr544;
		case 61: goto tr545;
		case 65: goto tr691;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr541;
	goto tr525;
tr691:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st523;
st523:
	if ( ++p == pe )
		goto _test_eof523;
case 523:
#line 10198 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
		case 59: goto tr544;
		case 61: goto tr545;
		case 84: goto tr692;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr541;
	goto tr525;
tr692:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st524;
st524:
	if ( ++p == pe )
		goto _test_eof524;
case 524:
#line 10219 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
		case 59: goto tr544;
		case 61: goto tr545;
		case 69: goto tr693;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr541;
	goto tr525;
tr693:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st525;
st525:
	if ( ++p == pe )
		goto _test_eof525;
case 525:
#line 10240 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
		case 59: goto tr544;
		case 61: goto tr545;
		case 68: goto tr694;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr541;
	goto tr525;
tr694:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st526;
st526:
	if ( ++p == pe )
		goto _test_eof526;
case 526:
#line 10261 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
		case 59: goto tr544;
		case 61: goto tr696;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr541;
	goto tr695;
tr696:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st527;
st527:
	if ( ++p == pe )
		goto _test_eof527;
case 527:
#line 10281 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 49 )
		goto tr698;
	goto tr697;
tr698:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st528;
st528:
	if ( ++p == pe )
		goto _test_eof528;
case 528:
#line 10295 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
		case 59: goto tr544;
	}
	goto tr697;
tr527:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st529;
st529:
	if ( ++p == pe )
		goto _test_eof529;
case 529:
#line 10316 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr542;
		case 10: goto tr543;
		case 58: goto tr540;
		case 60: goto tr540;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr540;
		} else if ( (*p) > 57 ) {
			if ( 62 <= (*p) && (*p) <= 64 )
				goto tr540;
		} else
			goto tr541;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr540;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr540;
		} else
			goto tr541;
	} else
		goto tr541;
	goto tr525;
tr524:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st530;
st530:
	if ( ++p == pe )
		goto _test_eof530;
case 530:
#line 10354 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 58 )
		goto tr518;
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr518;
		} else if ( (*p) > 57 ) {
			if ( 60 <= (*p) && (*p) <= 64 )
				goto tr518;
		} else
			goto tr520;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr518;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr518;
		} else
			goto tr520;
	} else
		goto tr520;
	goto tr517;
tr519:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st531;
st531:
	if ( ++p == pe )
		goto _test_eof531;
case 531:
#line 10392 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr523;
		case 58: goto st389;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto st389;
		} else if ( (*p) > 57 ) {
			if ( 60 <= (*p) && (*p) <= 64 )
				goto st389;
		} else
			goto tr522;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st389;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st389;
		} else
			goto tr522;
	} else
		goto tr522;
	goto tr517;
tr515:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st532;
st532:
	if ( ++p == pe )
		goto _test_eof532;
case 532:
#line 10428 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr699;
	goto tr507;
tr699:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st533;
st533:
	if ( ++p == pe )
		goto _test_eof533;
case 533:
#line 10442 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr514;
		case 69: goto tr516;
		case 101: goto tr516;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr699;
	goto tr507;
tr516:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st534;
st534:
	if ( ++p == pe )
		goto _test_eof534;
case 534:
#line 10461 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 43: goto tr700;
		case 45: goto tr700;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr701;
	goto tr507;
tr700:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st535;
st535:
	if ( ++p == pe )
		goto _test_eof535;
case 535:
#line 10479 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr701;
	goto tr507;
tr701:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st536;
st536:
	if ( ++p == pe )
		goto _test_eof536;
case 536:
#line 10493 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 9 )
		goto tr514;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr701;
	goto tr507;
tr511:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st537;
tr513:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st537;
st537:
	if ( ++p == pe )
		goto _test_eof537;
case 537:
#line 10519 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr514;
		case 46: goto tr515;
		case 69: goto tr516;
		case 101: goto tr516;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr513;
	goto tr507;
tr509:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st538;
st538:
	if ( ++p == pe )
		goto _test_eof538;
case 538:
#line 10543 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 9 )
		goto tr514;
	goto tr507;
tr506:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_end(*this);
    }
	goto st539;
st539:
	if ( ++p == pe )
		goto _test_eof539;
case 539:
#line 10557 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 42: goto tr499;
		case 46: goto tr702;
		case 60: goto tr501;
		case 65: goto tr502;
		case 67: goto tr502;
		case 71: goto tr502;
		case 78: goto tr502;
		case 84: goto tr502;
		case 91: goto tr503;
		case 93: goto tr504;
		case 97: goto tr502;
		case 99: goto tr502;
		case 103: goto tr502;
		case 110: goto tr502;
		case 116: goto tr502;
	}
	goto tr498;
tr702:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st540;
tr739:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st540;
st540:
	if ( ++p == pe )
		goto _test_eof540;
case 540:
#line 10596 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 65: goto tr703;
		case 67: goto tr703;
		case 71: goto tr703;
		case 78: goto tr703;
		case 84: goto tr703;
		case 97: goto tr703;
		case 99: goto tr703;
		case 103: goto tr703;
		case 110: goto tr703;
		case 116: goto tr703;
	}
	goto tr498;
tr703:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st541;
st541:
	if ( ++p == pe )
		goto _test_eof541;
case 541:
#line 10620 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr505;
		case 44: goto tr506;
		case 65: goto tr703;
		case 67: goto tr703;
		case 71: goto tr703;
		case 78: goto tr703;
		case 84: goto tr703;
		case 97: goto tr703;
		case 99: goto tr703;
		case 103: goto tr703;
		case 110: goto tr703;
		case 116: goto tr703;
	}
	goto tr498;
tr501:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st542;
tr705:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st542;
st542:
	if ( ++p == pe )
		goto _test_eof542;
case 542:
#line 10656 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 58: goto tr705;
		case 95: goto tr705;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr704;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr704;
	} else
		goto tr704;
	goto tr498;
tr704:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st543;
st543:
	if ( ++p == pe )
		goto _test_eof543;
case 543:
#line 10680 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 62: goto tr706;
		case 95: goto tr704;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 58 )
			goto tr704;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr704;
	} else
		goto tr704;
	goto tr498;
tr502:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st544;
tr707:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st544;
st544:
	if ( ++p == pe )
		goto _test_eof544;
case 544:
#line 10714 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr505;
		case 44: goto tr506;
		case 46: goto tr706;
		case 65: goto tr707;
		case 67: goto tr707;
		case 71: goto tr707;
		case 78: goto tr707;
		case 84: goto tr707;
		case 91: goto tr708;
		case 93: goto tr709;
		case 97: goto tr707;
		case 99: goto tr707;
		case 103: goto tr707;
		case 110: goto tr707;
		case 116: goto tr707;
	}
	goto tr498;
tr708:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st545;
st545:
	if ( ++p == pe )
		goto _test_eof545;
case 545:
#line 10743 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 60 )
		goto tr711;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr710;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr710;
	} else
		goto tr710;
	goto tr498;
tr710:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st546;
st546:
	if ( ++p == pe )
		goto _test_eof546;
case 546:
#line 10765 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 58: goto tr714;
		case 59: goto tr712;
		case 61: goto tr712;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr712;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr712;
		} else
			goto tr713;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr712;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr712;
		} else
			goto tr713;
	} else
		goto tr713;
	goto tr498;
tr712:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st547;
st547:
	if ( ++p == pe )
		goto _test_eof547;
case 547:
#line 10802 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr712;
		case 61: goto tr712;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr712;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr712;
		} else
			goto tr713;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr712;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr712;
		} else
			goto tr713;
	} else
		goto tr713;
	goto tr498;
tr713:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st548;
st548:
	if ( ++p == pe )
		goto _test_eof548;
case 548:
#line 10838 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 58: goto tr714;
		case 61: goto tr713;
	}
	if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr713;
	} else if ( (*p) >= 33 )
		goto tr713;
	goto tr498;
tr714:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st549;
st549:
	if ( ++p == pe )
		goto _test_eof549;
case 549:
#line 10859 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 45 )
		goto tr715;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr716;
	goto tr498;
tr715:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st550;
st550:
	if ( ++p == pe )
		goto _test_eof550;
case 550:
#line 10875 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr716;
	goto tr498;
tr716:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st551;
st551:
	if ( ++p == pe )
		goto _test_eof551;
case 551:
#line 10889 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 91 )
		goto tr706;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr716;
	goto tr498;
tr711:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st552;
st552:
	if ( ++p == pe )
		goto _test_eof552;
case 552:
#line 10905 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr717;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr717;
	} else
		goto tr717;
	goto tr498;
tr717:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st553;
st553:
	if ( ++p == pe )
		goto _test_eof553;
case 553:
#line 10925 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr718;
		case 62: goto tr720;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr718;
		} else if ( (*p) > 57 ) {
			if ( 61 <= (*p) && (*p) <= 64 )
				goto tr718;
		} else
			goto tr719;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr718;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr718;
		} else
			goto tr719;
	} else
		goto tr719;
	goto tr498;
tr718:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st554;
st554:
	if ( ++p == pe )
		goto _test_eof554;
case 554:
#line 10961 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr718;
		case 61: goto tr718;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr718;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr718;
		} else
			goto tr719;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr718;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr718;
		} else
			goto tr719;
	} else
		goto tr719;
	goto tr498;
tr719:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st555;
st555:
	if ( ++p == pe )
		goto _test_eof555;
case 555:
#line 10997 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr719;
		case 62: goto tr720;
	}
	if ( (*p) > 57 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr719;
	} else if ( (*p) >= 33 )
		goto tr719;
	goto tr498;
tr720:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st556;
st556:
	if ( ++p == pe )
		goto _test_eof556;
case 556:
#line 11018 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 58 )
		goto tr714;
	goto tr498;
tr709:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st557;
st557:
	if ( ++p == pe )
		goto _test_eof557;
case 557:
#line 11032 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 60 )
		goto tr722;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr721;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr721;
	} else
		goto tr721;
	goto tr498;
tr721:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st558;
st558:
	if ( ++p == pe )
		goto _test_eof558;
case 558:
#line 11054 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 58: goto tr725;
		case 59: goto tr723;
		case 61: goto tr723;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr723;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr723;
		} else
			goto tr724;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr723;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr723;
		} else
			goto tr724;
	} else
		goto tr724;
	goto tr498;
tr723:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st559;
st559:
	if ( ++p == pe )
		goto _test_eof559;
case 559:
#line 11091 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr723;
		case 61: goto tr723;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr723;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr723;
		} else
			goto tr724;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr723;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr723;
		} else
			goto tr724;
	} else
		goto tr724;
	goto tr498;
tr724:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st560;
st560:
	if ( ++p == pe )
		goto _test_eof560;
case 560:
#line 11127 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 58: goto tr725;
		case 61: goto tr724;
	}
	if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr724;
	} else if ( (*p) >= 33 )
		goto tr724;
	goto tr498;
tr725:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st561;
st561:
	if ( ++p == pe )
		goto _test_eof561;
case 561:
#line 11148 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 45 )
		goto tr726;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr727;
	goto tr498;
tr726:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st562;
st562:
	if ( ++p == pe )
		goto _test_eof562;
case 562:
#line 11164 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr727;
	goto tr498;
tr727:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st563;
st563:
	if ( ++p == pe )
		goto _test_eof563;
case 563:
#line 11178 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 93 )
		goto tr706;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr727;
	goto tr498;
tr722:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st564;
st564:
	if ( ++p == pe )
		goto _test_eof564;
case 564:
#line 11194 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr728;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr728;
	} else
		goto tr728;
	goto tr498;
tr728:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st565;
st565:
	if ( ++p == pe )
		goto _test_eof565;
case 565:
#line 11214 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr729;
		case 62: goto tr731;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr729;
		} else if ( (*p) > 57 ) {
			if ( 61 <= (*p) && (*p) <= 64 )
				goto tr729;
		} else
			goto tr730;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr729;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr729;
		} else
			goto tr730;
	} else
		goto tr730;
	goto tr498;
tr729:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st566;
st566:
	if ( ++p == pe )
		goto _test_eof566;
case 566:
#line 11250 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr729;
		case 61: goto tr729;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr729;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr729;
		} else
			goto tr730;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr729;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr729;
		} else
			goto tr730;
	} else
		goto tr730;
	goto tr498;
tr730:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st567;
st567:
	if ( ++p == pe )
		goto _test_eof567;
case 567:
#line 11286 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr730;
		case 62: goto tr731;
	}
	if ( (*p) > 57 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr730;
	} else if ( (*p) >= 33 )
		goto tr730;
	goto tr498;
tr731:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st568;
st568:
	if ( ++p == pe )
		goto _test_eof568;
case 568:
#line 11307 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 58 )
		goto tr725;
	goto tr498;
tr503:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st569;
st569:
	if ( ++p == pe )
		goto _test_eof569;
case 569:
#line 11325 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 60 )
		goto tr733;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr732;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr732;
	} else
		goto tr732;
	goto tr498;
tr732:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st570;
st570:
	if ( ++p == pe )
		goto _test_eof570;
case 570:
#line 11347 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 58: goto tr736;
		case 59: goto tr734;
		case 61: goto tr734;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr734;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr734;
		} else
			goto tr735;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr734;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr734;
		} else
			goto tr735;
	} else
		goto tr735;
	goto tr498;
tr734:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st571;
st571:
	if ( ++p == pe )
		goto _test_eof571;
case 571:
#line 11384 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr734;
		case 61: goto tr734;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr734;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr734;
		} else
			goto tr735;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr734;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr734;
		} else
			goto tr735;
	} else
		goto tr735;
	goto tr498;
tr735:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st572;
st572:
	if ( ++p == pe )
		goto _test_eof572;
case 572:
#line 11420 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 58: goto tr736;
		case 61: goto tr735;
	}
	if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr735;
	} else if ( (*p) >= 33 )
		goto tr735;
	goto tr498;
tr736:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st573;
st573:
	if ( ++p == pe )
		goto _test_eof573;
case 573:
#line 11441 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 45 )
		goto tr737;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr738;
	goto tr498;
tr737:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st574;
st574:
	if ( ++p == pe )
		goto _test_eof574;
case 574:
#line 11457 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr738;
	goto tr498;
tr738:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st575;
st575:
	if ( ++p == pe )
		goto _test_eof575;
case 575:
#line 11471 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 91 )
		goto tr739;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr738;
	goto tr498;
tr733:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st576;
st576:
	if ( ++p == pe )
		goto _test_eof576;
case 576:
#line 11487 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr740;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr740;
	} else
		goto tr740;
	goto tr498;
tr740:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st577;
st577:
	if ( ++p == pe )
		goto _test_eof577;
case 577:
#line 11507 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr741;
		case 62: goto tr743;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr741;
		} else if ( (*p) > 57 ) {
			if ( 61 <= (*p) && (*p) <= 64 )
				goto tr741;
		} else
			goto tr742;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr741;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr741;
		} else
			goto tr742;
	} else
		goto tr742;
	goto tr498;
tr741:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st578;
st578:
	if ( ++p == pe )
		goto _test_eof578;
case 578:
#line 11543 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr741;
		case 61: goto tr741;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr741;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr741;
		} else
			goto tr742;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr741;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr741;
		} else
			goto tr742;
	} else
		goto tr742;
	goto tr498;
tr742:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st579;
st579:
	if ( ++p == pe )
		goto _test_eof579;
case 579:
#line 11579 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr742;
		case 62: goto tr743;
	}
	if ( (*p) > 57 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr742;
	} else if ( (*p) >= 33 )
		goto tr742;
	goto tr498;
tr743:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st580;
st580:
	if ( ++p == pe )
		goto _test_eof580;
case 580:
#line 11600 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 58 )
		goto tr736;
	goto tr498;
tr504:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st581;
st581:
	if ( ++p == pe )
		goto _test_eof581;
case 581:
#line 11618 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 60 )
		goto tr745;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr744;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr744;
	} else
		goto tr744;
	goto tr498;
tr744:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st582;
st582:
	if ( ++p == pe )
		goto _test_eof582;
case 582:
#line 11640 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 58: goto tr748;
		case 59: goto tr746;
		case 61: goto tr746;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr746;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr746;
		} else
			goto tr747;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr746;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr746;
		} else
			goto tr747;
	} else
		goto tr747;
	goto tr498;
tr746:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st583;
st583:
	if ( ++p == pe )
		goto _test_eof583;
case 583:
#line 11677 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr746;
		case 61: goto tr746;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr746;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr746;
		} else
			goto tr747;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr746;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr746;
		} else
			goto tr747;
	} else
		goto tr747;
	goto tr498;
tr747:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st584;
st584:
	if ( ++p == pe )
		goto _test_eof584;
case 584:
#line 11713 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 58: goto tr748;
		case 61: goto tr747;
	}
	if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr747;
	} else if ( (*p) >= 33 )
		goto tr747;
	goto tr498;
tr748:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st585;
st585:
	if ( ++p == pe )
		goto _test_eof585;
case 585:
#line 11734 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 45 )
		goto tr749;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr750;
	goto tr498;
tr749:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st586;
st586:
	if ( ++p == pe )
		goto _test_eof586;
case 586:
#line 11750 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr750;
	goto tr498;
tr750:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st587;
st587:
	if ( ++p == pe )
		goto _test_eof587;
case 587:
#line 11764 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 93 )
		goto tr739;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr750;
	goto tr498;
tr745:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st588;
st588:
	if ( ++p == pe )
		goto _test_eof588;
case 588:
#line 11780 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr751;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr751;
	} else
		goto tr751;
	goto tr498;
tr751:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st589;
st589:
	if ( ++p == pe )
		goto _test_eof589;
case 589:
#line 11800 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr752;
		case 62: goto tr754;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr752;
		} else if ( (*p) > 57 ) {
			if ( 61 <= (*p) && (*p) <= 64 )
				goto tr752;
		} else
			goto tr753;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr752;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr752;
		} else
			goto tr753;
	} else
		goto tr753;
	goto tr498;
tr752:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st590;
st590:
	if ( ++p == pe )
		goto _test_eof590;
case 590:
#line 11836 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr752;
		case 61: goto tr752;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr752;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr752;
		} else
			goto tr753;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr752;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr752;
		} else
			goto tr753;
	} else
		goto tr753;
	goto tr498;
tr753:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st591;
st591:
	if ( ++p == pe )
		goto _test_eof591;
case 591:
#line 11872 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr753;
		case 62: goto tr754;
	}
	if ( (*p) > 57 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr753;
	} else if ( (*p) >= 33 )
		goto tr753;
	goto tr498;
tr754:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st592;
st592:
	if ( ++p == pe )
		goto _test_eof592;
case 592:
#line 11893 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 58 )
		goto tr748;
	goto tr498;
tr500:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st593;
st593:
	if ( ++p == pe )
		goto _test_eof593;
case 593:
#line 11911 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr505;
		case 65: goto tr703;
		case 67: goto tr703;
		case 71: goto tr703;
		case 78: goto tr703;
		case 84: goto tr703;
		case 97: goto tr703;
		case 99: goto tr703;
		case 103: goto tr703;
		case 110: goto tr703;
		case 116: goto tr703;
	}
	goto tr498;
tr482:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st594;
st594:
	if ( ++p == pe )
		goto _test_eof594;
case 594:
#line 11936 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr482;
		case 61: goto tr482;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr482;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr482;
		} else
			goto tr483;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr482;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr482;
		} else
			goto tr483;
	} else
		goto tr483;
	goto tr480;
tr483:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st595;
st595:
	if ( ++p == pe )
		goto _test_eof595;
case 595:
#line 11972 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr481;
		case 59: goto tr483;
		case 61: goto tr483;
	}
	if ( (*p) > 57 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr483;
	} else if ( (*p) >= 33 )
		goto tr483;
	goto tr480;
st596:
	if ( ++p == pe )
		goto _test_eof596;
case 596:
	if ( (*p) == 10 )
		goto tr756;
	goto st596;
tr756:
#line 27 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
#line 712 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{ {goto st20;} }
	goto st600;
st600:
	if ( ++p == pe )
		goto _test_eof600;
case 600:
#line 12009 "cpp/src/bioformats/vcf/validator_detail.hpp"
	goto st0;
st597:
	if ( ++p == pe )
		goto _test_eof597;
case 597:
	if ( (*p) == 10 )
		goto tr758;
	goto st597;
tr758:
#line 27 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;

        if (n_lines % 10000 == 0) {
            std::cout << "Lines read: " << n_lines << std::endl;
        }
    }
#line 713 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{ {goto st599;} }
	goto st601;
st601:
	if ( ++p == pe )
		goto _test_eof601;
case 601:
#line 12036 "cpp/src/bioformats/vcf/validator_detail.hpp"
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
	_test_eof598: cs = 598; goto _test_eof; 
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
	_test_eof599: cs = 599; goto _test_eof; 
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
	_test_eof600: cs = 600; goto _test_eof; 
	_test_eof597: cs = 597; goto _test_eof; 
	_test_eof601: cs = 601; goto _test_eof; 

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
#line 44 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this);
        p--; {goto st596;}
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
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
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
#line 62 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        p--; {goto st597;}
    }
	break;
	case 14: 
	case 15: 
#line 186 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this,
            "Fileformat is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st596;}
    }
#line 44 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this);
        p--; {goto st596;}
    }
	break;
	case 42: 
	case 43: 
	case 44: 
	case 45: 
	case 46: 
	case 47: 
	case 48: 
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
	case 70: 
	case 71: 
#line 193 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
	break;
	case 272: 
	case 273: 
	case 274: 
	case 275: 
	case 276: 
	case 277: 
	case 278: 
	case 279: 
#line 204 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in assembly metadata");
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
	break;
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
	case 301: 
	case 302: 
	case 303: 
	case 304: 
	case 305: 
	case 306: 
	case 307: 
	case 308: 
	case 309: 
#line 210 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in contig metadata");
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
	break;
	case 74: 
	case 75: 
	case 76: 
	case 77: 
	case 78: 
	case 79: 
	case 80: 
	case 81: 
	case 82: 
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
	case 105: 
	case 106: 
#line 216 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
	break;
	case 107: 
	case 108: 
	case 109: 
	case 110: 
	case 111: 
	case 112: 
	case 113: 
	case 114: 
	case 115: 
	case 119: 
	case 120: 
	case 121: 
	case 122: 
	case 123: 
	case 124: 
	case 125: 
	case 128: 
	case 129: 
	case 130: 
	case 131: 
	case 132: 
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
	case 148: 
	case 154: 
	case 155: 
#line 222 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
	break;
	case 157: 
	case 158: 
	case 159: 
	case 160: 
	case 161: 
	case 162: 
	case 163: 
	case 164: 
	case 168: 
	case 169: 
	case 170: 
	case 171: 
	case 172: 
	case 173: 
	case 174: 
	case 177: 
	case 178: 
	case 179: 
	case 180: 
	case 181: 
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
	case 196: 
	case 197: 
	case 203: 
	case 204: 
#line 238 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
	break;
	case 206: 
	case 207: 
	case 208: 
	case 209: 
	case 210: 
	case 211: 
	case 212: 
	case 213: 
	case 214: 
	case 221: 
#line 254 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in PEDIGREE metadata");
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
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
	case 320: 
#line 260 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in pedigreeDB metadata");
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
	break;
	case 222: 
	case 223: 
	case 224: 
	case 225: 
	case 226: 
	case 227: 
	case 228: 
	case 229: 
	case 230: 
	case 231: 
	case 271: 
#line 266 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
	break;
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
#line 298 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this, "The header line does not start with the mandatory columns: CHROM, POS, ID, REF, ALT, QUAL, FILTER and INFO");
        p--; {goto st597;}
    }
#line 62 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        p--; {goto st597;}
    }
	break;
	case 375: 
	case 398: 
	case 399: 
	case 400: 
	case 401: 
	case 402: 
	case 594: 
	case 595: 
#line 306 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Chromosome is not a string without colons or whitespaces, optionally wrapped with angle brackets (<>)");
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	break;
	case 376: 
	case 377: 
	case 378: 
#line 312 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Position is not a positive number");
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	break;
	case 379: 
	case 380: 
#line 318 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "ID is not a single dot or a list of strings without semicolons or whitespaces");
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	break;
	case 381: 
	case 382: 
#line 324 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Reference is not a string of bases");
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	break;
	case 383: 
	case 384: 
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
	case 568: 
	case 569: 
	case 570: 
	case 571: 
	case 572: 
	case 573: 
	case 574: 
	case 575: 
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
#line 330 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Alternate is not a single dot or a comma-separated list of bases");
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	break;
	case 385: 
	case 386: 
	case 387: 
	case 532: 
	case 533: 
	case 534: 
	case 535: 
	case 536: 
	case 537: 
	case 538: 
#line 336 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Quality is not a single dot or a positive number");
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	break;
	case 388: 
	case 389: 
	case 390: 
	case 530: 
	case 531: 
#line 342 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Filter is not a single dot or a semicolon-separated list of strings");
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	break;
	case 394: 
	case 395: 
#line 454 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Format is not a colon-separated list of alphanumeric strings");
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	break;
	case 405: 
	case 406: 
#line 460 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " is not a valid string";
        ErrorPolicy::handle_body_section_error(*this, message_stream.str());
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	break;
	case 17: 
	case 20: 
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
#line 298 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this, "The header line does not start with the mandatory columns: CHROM, POS, ID, REF, ALT, QUAL, FILTER and INFO");
        p--; {goto st597;}
    }
#line 62 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        p--; {goto st597;}
    }
	break;
	case 49: 
	case 50: 
	case 72: 
#line 198 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "ALT metadata ID is not prefixed by DEL/INS/DUP/INV/CNV and suffixed by ':' and a text sequence");
        p--; {goto st596;}
    }
#line 193 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
	break;
	case 73: 
#line 216 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st596;}
    }
#line 222 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
	break;
	case 126: 
	case 127: 
	case 156: 
#line 227 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "FORMAT metadata Number is not a number, A, R, G or dot");
        p--; {goto st596;}
    }
#line 222 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
	break;
	case 175: 
	case 176: 
	case 205: 
#line 243 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "INFO metadata Number is not a number, A, R, G or dot");
        p--; {goto st596;}
    }
#line 238 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
	break;
	case 133: 
	case 134: 
#line 248 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "INFO metadata Type is not a Integer, Float, Flag, Character or String");
        p--; {goto st596;}
    }
#line 222 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
	break;
	case 182: 
	case 183: 
#line 248 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "INFO metadata Type is not a Integer, Float, Flag, Character or String");
        p--; {goto st596;}
    }
#line 238 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
	break;
	case 235: 
	case 236: 
	case 237: 
	case 238: 
	case 239: 
	case 240: 
	case 241: 
	case 242: 
	case 243: 
#line 271 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Genomes is not a valid string (maybe it contains quotes?)");
        p--; {goto st596;}
    }
#line 266 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
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
#line 276 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Mixture is not a valid string (maybe it contains quotes?)");
        p--; {goto st596;}
    }
#line 266 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
	break;
	case 67: 
	case 68: 
	case 69: 
#line 282 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st596;}
    }
#line 193 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
	break;
	case 297: 
	case 298: 
	case 299: 
	case 300: 
#line 282 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st596;}
    }
#line 210 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in contig metadata");
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
	break;
	case 83: 
	case 84: 
	case 85: 
	case 102: 
	case 103: 
	case 104: 
#line 282 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st596;}
    }
#line 216 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
	break;
	case 116: 
	case 117: 
	case 118: 
	case 151: 
	case 152: 
	case 153: 
#line 282 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st596;}
    }
#line 222 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
	break;
	case 165: 
	case 166: 
	case 167: 
	case 200: 
	case 201: 
	case 202: 
#line 282 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st596;}
    }
#line 238 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
	break;
	case 215: 
	case 216: 
	case 217: 
	case 218: 
	case 219: 
	case 220: 
#line 282 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st596;}
    }
#line 254 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in PEDIGREE metadata");
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
	break;
	case 232: 
	case 233: 
#line 282 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st596;}
    }
#line 266 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
	break;
	case 65: 
	case 66: 
#line 287 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st596;}
    }
#line 193 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
	break;
	case 100: 
	case 101: 
#line 287 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st596;}
    }
#line 216 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
	break;
	case 149: 
	case 150: 
#line 287 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st596;}
    }
#line 222 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
	break;
	case 198: 
	case 199: 
#line 287 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st596;}
    }
#line 238 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
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
	case 264: 
	case 265: 
	case 266: 
	case 267: 
	case 268: 
	case 269: 
	case 270: 
#line 287 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st596;}
    }
#line 266 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
	break;
	case 280: 
	case 281: 
	case 282: 
	case 283: 
	case 284: 
	case 285: 
	case 286: 
#line 292 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata URL is not valid");
        p--; {goto st596;}
    }
#line 204 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in assembly metadata");
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
	break;
	case 321: 
	case 322: 
	case 323: 
	case 324: 
	case 325: 
	case 326: 
	case 327: 
	case 328: 
#line 292 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata URL is not valid");
        p--; {goto st596;}
    }
#line 260 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in pedigreeDB metadata");
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
	break;
	case 391: 
	case 392: 
	case 393: 
	case 407: 
	case 408: 
	case 409: 
	case 410: 
	case 411: 
	case 417: 
	case 418: 
	case 422: 
	case 426: 
	case 436: 
	case 440: 
	case 441: 
	case 451: 
	case 452: 
	case 453: 
	case 454: 
	case 455: 
	case 458: 
	case 462: 
	case 466: 
	case 467: 
	case 468: 
	case 472: 
	case 479: 
	case 480: 
	case 481: 
	case 494: 
	case 495: 
	case 499: 
	case 500: 
	case 510: 
	case 511: 
	case 512: 
	case 513: 
	case 514: 
	case 518: 
	case 519: 
	case 520: 
	case 521: 
	case 522: 
	case 523: 
	case 524: 
	case 525: 
	case 529: 
#line 353 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st597;}
    }
#line 348 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	break;
	case 412: 
	case 413: 
#line 358 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info field value is not a comma-separated list of valid strings (maybe it contains whitespaces?)");
        p--; {goto st597;}
    }
#line 348 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	break;
	case 419: 
	case 420: 
	case 421: 
#line 363 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info AA value is not a single dot or a string of bases");
        p--; {goto st597;}
    }
#line 348 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	break;
	case 423: 
	case 424: 
	case 425: 
#line 368 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info AC value is not a comma-separated list of numbers");
        p--; {goto st597;}
    }
#line 348 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
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
	case 435: 
#line 373 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info AF value is not a comma-separated list of numbers");
        p--; {goto st597;}
    }
#line 348 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	break;
	case 437: 
	case 438: 
	case 439: 
#line 378 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info AN value is not an integer number");
        p--; {goto st597;}
    }
#line 348 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	break;
	case 442: 
	case 443: 
	case 444: 
	case 445: 
	case 446: 
	case 447: 
	case 448: 
	case 449: 
	case 450: 
#line 383 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info BQ value is not a number");
        p--; {goto st597;}
    }
#line 348 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	break;
	case 456: 
	case 457: 
#line 388 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info CIGAR value is not an alphanumeric string");
        p--; {goto st597;}
    }
#line 348 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	break;
	case 460: 
	case 461: 
#line 393 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info DB is not a flag (with 1/0/no value)");
        p--; {goto st597;}
    }
#line 348 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	break;
	case 463: 
	case 464: 
	case 465: 
#line 398 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info DP value is not an integer number");
        p--; {goto st597;}
    }
#line 348 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	break;
	case 469: 
	case 470: 
	case 471: 
#line 403 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info END value is not an integer number");
        p--; {goto st597;}
    }
#line 348 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	break;
	case 474: 
	case 475: 
#line 408 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info H2 is not a flag (with 1/0/no value)");
        p--; {goto st597;}
    }
#line 348 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	break;
	case 477: 
	case 478: 
#line 413 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info H3 is not a flag (with 1/0/no value)");
        p--; {goto st597;}
    }
#line 348 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	break;
	case 485: 
	case 486: 
	case 487: 
	case 488: 
	case 489: 
	case 490: 
	case 491: 
	case 492: 
	case 493: 
#line 418 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info MQ value is not a number");
        p--; {goto st597;}
    }
#line 348 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	break;
	case 482: 
	case 483: 
	case 484: 
#line 423 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info MQ0 value is not an integer number");
        p--; {goto st597;}
    }
#line 348 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	break;
	case 496: 
	case 497: 
	case 498: 
#line 428 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info NS value is not an integer number");
        p--; {goto st597;}
    }
#line 348 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	break;
	case 501: 
	case 502: 
	case 503: 
	case 504: 
	case 505: 
	case 506: 
	case 507: 
	case 508: 
	case 509: 
#line 433 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info SB value is not a number");
        p--; {goto st597;}
    }
#line 348 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	break;
	case 516: 
	case 517: 
#line 438 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info SOMATIC is not a flag (with 1/0/no value)");
        p--; {goto st597;}
    }
#line 348 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	break;
	case 527: 
	case 528: 
#line 443 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info VALIDATED is not a flag (with 1/0/no value)");
        p--; {goto st597;}
    }
#line 348 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	break;
	case 415: 
	case 416: 
#line 448 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info 1000G is not a flag (with 1/0/no value)");
        p--; {goto st597;}
    }
#line 348 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	break;
	case 396: 
	case 397: 
	case 403: 
	case 404: 
#line 467 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " does not start with a valid genotype";
        ErrorPolicy::handle_body_section_error(*this, message_stream.str());
        p--; {goto st597;}
    }
#line 460 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " is not a valid string";
        ErrorPolicy::handle_body_section_error(*this, message_stream.str());
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	break;
	case 16: 
#line 44 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this);
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
#line 298 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this, "The header line does not start with the mandatory columns: CHROM, POS, ID, REF, ALT, QUAL, FILTER and INFO");
        p--; {goto st597;}
    }
#line 62 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        p--; {goto st597;}
    }
	break;
	case 244: 
#line 271 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Genomes is not a valid string (maybe it contains quotes?)");
        p--; {goto st596;}
    }
#line 276 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Mixture is not a valid string (maybe it contains quotes?)");
        p--; {goto st596;}
    }
#line 266 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
	break;
	case 254: 
#line 276 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Mixture is not a valid string (maybe it contains quotes?)");
        p--; {goto st596;}
    }
#line 287 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st596;}
    }
#line 266 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
	break;
	case 234: 
#line 282 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st596;}
    }
#line 271 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Genomes is not a valid string (maybe it contains quotes?)");
        p--; {goto st596;}
    }
#line 266 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
	break;
	case 459: 
#line 393 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info DB is not a flag (with 1/0/no value)");
        p--; {goto st597;}
    }
#line 353 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st597;}
    }
#line 348 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	break;
	case 473: 
#line 408 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info H2 is not a flag (with 1/0/no value)");
        p--; {goto st597;}
    }
#line 353 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st597;}
    }
#line 348 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	break;
	case 476: 
#line 413 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info H3 is not a flag (with 1/0/no value)");
        p--; {goto st597;}
    }
#line 353 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st597;}
    }
#line 348 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	break;
	case 515: 
#line 438 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info SOMATIC is not a flag (with 1/0/no value)");
        p--; {goto st597;}
    }
#line 353 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st597;}
    }
#line 348 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	break;
	case 526: 
#line 443 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info VALIDATED is not a flag (with 1/0/no value)");
        p--; {goto st597;}
    }
#line 353 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st597;}
    }
#line 348 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	break;
	case 414: 
#line 448 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info 1000G is not a flag (with 1/0/no value)");
        p--; {goto st597;}
    }
#line 353 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st597;}
    }
#line 348 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st597;}
    }
#line 67 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st597;}
    }
	break;
	case 18: 
#line 193 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st596;}
    }
#line 216 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st596;}
    }
#line 222 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st596;}
    }
#line 238 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st596;}
    }
#line 204 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in assembly metadata");
        p--; {goto st596;}
    }
#line 210 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in contig metadata");
        p--; {goto st596;}
    }
#line 266 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st596;}
    }
#line 254 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in PEDIGREE metadata");
        p--; {goto st596;}
    }
#line 260 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in pedigreeDB metadata");
        p--; {goto st596;}
    }
#line 49 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st596;}
    }
	break;
#line 14449 "cpp/src/bioformats/vcf/validator_detail.hpp"
	}
	}

	_out: {}
	}

#line 779 "cpp/src/bioformats/vcf/vcf_v41.ragel"

    }
    
  }
}
