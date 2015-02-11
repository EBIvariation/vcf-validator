
#line 1 "cpp/src/bioformats/vcf/vcf_v41.ragel"
#include <cstdio>

#include "validator.hpp"


#line 667 "cpp/src/bioformats/vcf/vcf_v41.ragel"


namespace
{
  
#line 15 "cpp/src/bioformats/vcf/validator_detail.hpp"
static const int vcf_start = 1;
static const int vcf_first_final = 555;
static const int vcf_error = 0;

static const int vcf_en_main = 1;
static const int vcf_en_main_meta_section = 20;
static const int vcf_en_main_body_section = 556;
static const int vcf_en_meta_section_skip = 553;
static const int vcf_en_body_section_skip = 554;


#line 673 "cpp/src/bioformats/vcf/vcf_v41.ragel"

}

namespace opencb
{
  namespace vcf
  {
    template <typename Configuration>
    Parser<Configuration>::Parser(std::shared_ptr<Source> const & source)
    : ParsingState{source}
    {
      
#line 40 "cpp/src/bioformats/vcf/validator_detail.hpp"
	{
	cs = vcf_start;
	}

#line 686 "cpp/src/bioformats/vcf/vcf_v41.ragel"

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
#line 80 "cpp/src/bioformats/vcf/validator_detail.hpp"
555
#line 719 "cpp/src/bioformats/vcf/vcf_v41.ragel"
;
    }

    template <typename Configuration>
    void Parser<Configuration>::parse_buffer(char const * p, char const * pe, char const * eof)
    {
      
#line 90 "cpp/src/bioformats/vcf/validator_detail.hpp"
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
#line 42 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this);
        p--; {goto st553;}
    }
	goto st0;
tr14:
#line 165 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this,
            "Fileformat is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st553;}
    }
#line 42 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this);
        p--; {goto st553;}
    }
	goto st0;
tr18:
#line 42 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this);
        p--; {goto st553;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
#line 277 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this, "The header line does not start with the mandatory columns: CHROM, POS, ID, REF, ALT, QUAL, FILTER and INFO");
        p--; {goto st554;}
    }
#line 52 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr20:
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
#line 277 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this, "The header line does not start with the mandatory columns: CHROM, POS, ID, REF, ALT, QUAL, FILTER and INFO");
        p--; {goto st554;}
    }
#line 52 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr23:
#line 172 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st553;}
    }
#line 195 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st553;}
    }
#line 201 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st553;}
    }
#line 217 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st553;}
    }
#line 183 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in assembly metadata");
        p--; {goto st553;}
    }
#line 189 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in contig metadata");
        p--; {goto st553;}
    }
#line 245 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st553;}
    }
#line 233 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in PEDIGREE metadata");
        p--; {goto st553;}
    }
#line 239 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in pedigreeDB metadata");
        p--; {goto st553;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
	goto st0;
tr34:
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
	goto st0;
tr52:
#line 172 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st553;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
	goto st0;
tr60:
#line 177 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "ALT metadata ID is not prefixed by DEL/INS/DUP/INV/CNV and suffixed by ':' and a text sequence");
        p--; {goto st553;}
    }
#line 172 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st553;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
	goto st0;
tr78:
#line 266 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st553;}
    }
#line 172 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st553;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
	goto st0;
tr82:
#line 195 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st553;}
    }
#line 201 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st553;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
	goto st0;
tr85:
#line 195 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st553;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
	goto st0;
tr95:
#line 261 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st553;}
    }
#line 195 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st553;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
	goto st0;
tr115:
#line 266 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st553;}
    }
#line 195 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st553;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
	goto st0;
tr119:
#line 201 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st553;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
	goto st0;
tr129:
#line 261 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st553;}
    }
#line 201 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st553;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
	goto st0;
tr142:
#line 206 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "FORMAT metadata Number is not a number, A, R, G or dot");
        p--; {goto st553;}
    }
#line 201 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st553;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
	goto st0;
tr151:
#line 227 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "INFO metadata Type is not a Integer, Float, Flag, Character or String");
        p--; {goto st553;}
    }
#line 201 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st553;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
	goto st0;
tr169:
#line 266 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st553;}
    }
#line 201 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st553;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
	goto st0;
tr174:
#line 217 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st553;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
	goto st0;
tr183:
#line 261 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st553;}
    }
#line 217 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st553;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
	goto st0;
tr196:
#line 222 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "INFO metadata Number is not a number, A, R, G or dot");
        p--; {goto st553;}
    }
#line 217 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st553;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
	goto st0;
tr205:
#line 227 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "INFO metadata Type is not a Integer, Float, Flag, Character or String");
        p--; {goto st553;}
    }
#line 217 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st553;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
	goto st0;
tr223:
#line 266 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st553;}
    }
#line 217 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st553;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
	goto st0;
tr235:
#line 233 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in PEDIGREE metadata");
        p--; {goto st553;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
	goto st0;
tr245:
#line 261 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st553;}
    }
#line 233 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in PEDIGREE metadata");
        p--; {goto st553;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
	goto st0;
tr257:
#line 245 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st553;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
	goto st0;
tr268:
#line 261 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st553;}
    }
#line 245 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st553;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
	goto st0;
tr273:
#line 261 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st553;}
    }
#line 250 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Genomes is not a valid string (maybe it contains quotes?)");
        p--; {goto st553;}
    }
#line 245 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st553;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
	goto st0;
tr275:
#line 250 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Genomes is not a valid string (maybe it contains quotes?)");
        p--; {goto st553;}
    }
#line 245 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st553;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
	goto st0;
tr285:
#line 250 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Genomes is not a valid string (maybe it contains quotes?)");
        p--; {goto st553;}
    }
#line 255 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Mixture is not a valid string (maybe it contains quotes?)");
        p--; {goto st553;}
    }
#line 245 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st553;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
	goto st0;
tr288:
#line 255 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Mixture is not a valid string (maybe it contains quotes?)");
        p--; {goto st553;}
    }
#line 245 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st553;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
	goto st0;
tr298:
#line 255 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Mixture is not a valid string (maybe it contains quotes?)");
        p--; {goto st553;}
    }
#line 266 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st553;}
    }
#line 245 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st553;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
	goto st0;
tr301:
#line 266 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st553;}
    }
#line 245 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st553;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
	goto st0;
tr319:
#line 183 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in assembly metadata");
        p--; {goto st553;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
	goto st0;
tr328:
#line 271 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata URL is not valid");
        p--; {goto st553;}
    }
#line 183 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in assembly metadata");
        p--; {goto st553;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
	goto st0;
tr335:
#line 189 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in contig metadata");
        p--; {goto st553;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
	goto st0;
tr346:
#line 261 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st553;}
    }
#line 189 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in contig metadata");
        p--; {goto st553;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
	goto st0;
tr360:
#line 239 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in pedigreeDB metadata");
        p--; {goto st553;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
	goto st0;
tr372:
#line 271 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata URL is not valid");
        p--; {goto st553;}
    }
#line 239 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in pedigreeDB metadata");
        p--; {goto st553;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
	goto st0;
tr380:
#line 277 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this, "The header line does not start with the mandatory columns: CHROM, POS, ID, REF, ALT, QUAL, FILTER and INFO");
        p--; {goto st554;}
    }
#line 52 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr419:
#line 52 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr431:
#line 285 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Chromosome is not a string without colons or whitespaces, optionally wrapped with angle brackets (<>)");
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr435:
#line 291 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Position is not a positive number");
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr439:
#line 297 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "ID is not a single dot or a list of strings without semicolons or whitespaces");
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr444:
#line 303 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Reference is not a string of bases");
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr448:
#line 309 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Alternate is not a single dot or a comma-separated list of bases");
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr457:
#line 315 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Quality is not a single dot or a positive number");
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr461:
#line 321 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Filter is not a single dot or a semicolon-separated list of strings");
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr469:
#line 332 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st554;}
    }
#line 327 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr490:
#line 433 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Format is not a colon-separated list of alphanumeric strings");
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr495:
#line 446 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " does not start with a valid genotype";
        ErrorPolicy::handle_body_section_error(*this, message_stream.str());
        p--; {goto st554;}
    }
#line 439 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " is not a valid string";
        ErrorPolicy::handle_body_section_error(*this, message_stream.str());
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr504:
#line 439 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " is not a valid string";
        ErrorPolicy::handle_body_section_error(*this, message_stream.str());
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr521:
#line 337 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info field value is not a comma-separated list of valid strings (maybe it contains whitespaces?)");
        p--; {goto st554;}
    }
#line 327 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr523:
#line 427 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info 1000G is not a flag (with 1/0/no value)");
        p--; {goto st554;}
    }
#line 332 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st554;}
    }
#line 327 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr525:
#line 427 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info 1000G is not a flag (with 1/0/no value)");
        p--; {goto st554;}
    }
#line 327 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr532:
#line 342 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info AA value is not a single dot or a string of bases");
        p--; {goto st554;}
    }
#line 327 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr536:
#line 347 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info AC value is not a comma-separated list of numbers");
        p--; {goto st554;}
    }
#line 327 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr539:
#line 352 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info AF value is not a comma-separated list of numbers");
        p--; {goto st554;}
    }
#line 327 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr544:
#line 357 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info AN value is not an integer number");
        p--; {goto st554;}
    }
#line 327 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr548:
#line 362 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info BQ value is not a number");
        p--; {goto st554;}
    }
#line 327 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr557:
#line 367 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info CIGAR value is not an alphanumeric string");
        p--; {goto st554;}
    }
#line 327 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr561:
#line 372 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info DB is not a flag (with 1/0/no value)");
        p--; {goto st554;}
    }
#line 332 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st554;}
    }
#line 327 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr563:
#line 372 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info DB is not a flag (with 1/0/no value)");
        p--; {goto st554;}
    }
#line 327 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr566:
#line 377 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info DP value is not an integer number");
        p--; {goto st554;}
    }
#line 327 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr571:
#line 382 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info END value is not an integer number");
        p--; {goto st554;}
    }
#line 327 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr575:
#line 387 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info H2 is not a flag (with 1/0/no value)");
        p--; {goto st554;}
    }
#line 332 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st554;}
    }
#line 327 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr577:
#line 387 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info H2 is not a flag (with 1/0/no value)");
        p--; {goto st554;}
    }
#line 327 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr579:
#line 392 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info H3 is not a flag (with 1/0/no value)");
        p--; {goto st554;}
    }
#line 332 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st554;}
    }
#line 327 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr581:
#line 392 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info H3 is not a flag (with 1/0/no value)");
        p--; {goto st554;}
    }
#line 327 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr587:
#line 402 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info MQ0 value is not an integer number");
        p--; {goto st554;}
    }
#line 327 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr589:
#line 397 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info MQ value is not a number");
        p--; {goto st554;}
    }
#line 327 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr595:
#line 407 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info NS value is not an integer number");
        p--; {goto st554;}
    }
#line 327 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr600:
#line 412 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info SB value is not a number");
        p--; {goto st554;}
    }
#line 327 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr609:
#line 417 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info SOMATIC is not a flag (with 1/0/no value)");
        p--; {goto st554;}
    }
#line 332 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st554;}
    }
#line 327 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr611:
#line 417 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info SOMATIC is not a flag (with 1/0/no value)");
        p--; {goto st554;}
    }
#line 327 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr621:
#line 422 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info VALIDATED is not a flag (with 1/0/no value)");
        p--; {goto st554;}
    }
#line 332 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st554;}
    }
#line 327 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr623:
#line 422 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info VALIDATED is not a flag (with 1/0/no value)");
        p--; {goto st554;}
    }
#line 327 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr707:
#line 52 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        p--; {goto st554;}
    }
#line 285 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Chromosome is not a string without colons or whitespaces, optionally wrapped with angle brackets (<>)");
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
#line 1388 "cpp/src/bioformats/vcf/validator_detail.hpp"
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
#line 1503 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 10 )
		goto tr16;
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr17;
	goto tr14;
tr16:
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_fileformat(*this);
    }
#line 28 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;
    }
	goto st16;
st16:
	if ( ++p == pe )
		goto _test_eof16;
case 16:
#line 1525 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 35 )
		goto st17;
	goto tr18;
st17:
	if ( ++p == pe )
		goto _test_eof17;
case 17:
	switch( (*p) ) {
		case 35: goto st18;
		case 67: goto st300;
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
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st19;
tr36:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st19;
st19:
	if ( ++p == pe )
		goto _test_eof19;
case 19:
#line 1597 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 10 )
		goto tr35;
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto tr36;
	} else if ( (*p) >= 32 )
		goto tr36;
	goto tr34;
tr35:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
#line 137 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
      try {
        ParsePolicy::handle_meta_line(*this);
      } catch (ParsingError ex) {
        ErrorPolicy::handle_meta_section_error(*this, ex.what());
      }
    }
#line 28 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;
    }
	goto st20;
tr51:
#line 137 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
      try {
        ParsePolicy::handle_meta_line(*this);
      } catch (ParsingError ex) {
        ErrorPolicy::handle_meta_section_error(*this, ex.what());
      }
    }
#line 28 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;
    }
	goto st20;
st20:
	if ( ++p == pe )
		goto _test_eof20;
case 20:
#line 1647 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 35 )
		goto st17;
	goto tr20;
tr25:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st21;
tr37:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st21;
st21:
	if ( ++p == pe )
		goto _test_eof21;
case 21:
#line 1671 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 95: goto tr37;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto tr36;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr36;
		} else
			goto tr37;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr36;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr36;
		} else
			goto tr37;
	} else
		goto tr37;
	goto tr34;
tr38:
#line 129 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this);
    }
	goto st22;
st22:
	if ( ++p == pe )
		goto _test_eof22;
case 22:
#line 1708 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 60 )
		goto st24;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr39;
	goto tr34;
tr39:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st23;
tr41:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st23;
st23:
	if ( ++p == pe )
		goto _test_eof23;
case 23:
#line 1734 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 10 )
		goto tr35;
	if ( (*p) > 59 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr41;
	} else if ( (*p) >= 32 )
		goto tr41;
	goto tr34;
tr49:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
	goto st24;
st24:
	if ( ++p == pe )
		goto _test_eof24;
case 24:
#line 1754 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 95 )
		goto tr42;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr42;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr43;
		} else if ( (*p) >= 65 )
			goto tr43;
	} else
		goto tr43;
	goto tr34;
tr42:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st25;
st25:
	if ( ++p == pe )
		goto _test_eof25;
case 25:
#line 1779 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 95 )
		goto st25;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st25;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr45;
		} else if ( (*p) >= 65 )
			goto tr45;
	} else
		goto tr45;
	goto tr34;
tr43:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st26;
tr45:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st26;
st26:
	if ( ++p == pe )
		goto _test_eof26;
case 26:
#line 1814 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 61: goto tr46;
		case 95: goto tr45;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr45;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr45;
		} else if ( (*p) >= 65 )
			goto tr45;
	} else
		goto tr45;
	goto tr34;
tr46:
#line 133 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_key(*this);
    }
	goto st27;
st27:
	if ( ++p == pe )
		goto _test_eof27;
case 27:
#line 1841 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) < 45 ) {
		if ( 32 <= (*p) && (*p) <= 43 )
			goto tr47;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr47;
	} else
		goto tr47;
	goto tr34;
tr47:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st28;
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
#line 1871 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto tr49;
		case 62: goto tr50;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr48;
	goto tr34;
tr50:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
	goto st29;
st29:
	if ( ++p == pe )
		goto _test_eof29;
case 29:
#line 1890 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 10 )
		goto tr51;
	goto tr34;
tr26:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st30;
st30:
	if ( ++p == pe )
		goto _test_eof30;
case 30:
#line 1908 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 76: goto tr53;
		case 95: goto tr37;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto tr36;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr36;
		} else
			goto tr37;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr36;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr36;
		} else
			goto tr37;
	} else
		goto tr37;
	goto tr52;
tr53:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st31;
st31:
	if ( ++p == pe )
		goto _test_eof31;
case 31:
#line 1946 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 84: goto tr54;
		case 95: goto tr37;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto tr36;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr36;
		} else
			goto tr37;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr36;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr36;
		} else
			goto tr37;
	} else
		goto tr37;
	goto tr52;
tr54:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st32;
st32:
	if ( ++p == pe )
		goto _test_eof32;
case 32:
#line 1984 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr55;
		case 95: goto tr37;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto tr36;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr36;
		} else
			goto tr37;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr36;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr36;
		} else
			goto tr37;
	} else
		goto tr37;
	goto tr52;
tr55:
#line 69 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "ALT");
    }
	goto st33;
st33:
	if ( ++p == pe )
		goto _test_eof33;
case 33:
#line 2021 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 60 )
		goto st34;
	goto tr52;
st34:
	if ( ++p == pe )
		goto _test_eof34;
case 34:
	if ( (*p) == 73 )
		goto st35;
	goto tr52;
st35:
	if ( ++p == pe )
		goto _test_eof35;
case 35:
	if ( (*p) == 68 )
		goto st36;
	goto tr52;
st36:
	if ( ++p == pe )
		goto _test_eof36;
case 36:
	if ( (*p) == 61 )
		goto st37;
	goto tr52;
st37:
	if ( ++p == pe )
		goto _test_eof37;
case 37:
	if ( (*p) == 58 )
		goto tr61;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr61;
	} else if ( (*p) >= 65 )
		goto tr61;
	goto tr60;
tr63:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st38;
tr61:
#line 105 "cpp/src/bioformats/vcf/vcf_v41.ragel"
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
	goto st38;
st38:
	if ( ++p == pe )
		goto _test_eof38;
case 38:
#line 2082 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto tr62;
		case 58: goto tr63;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr63;
	} else if ( (*p) >= 65 )
		goto tr63;
	goto tr60;
tr62:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
	goto st39;
st39:
	if ( ++p == pe )
		goto _test_eof39;
case 39:
#line 2104 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 68 )
		goto st40;
	goto tr52;
st40:
	if ( ++p == pe )
		goto _test_eof40;
case 40:
	if ( (*p) == 101 )
		goto st41;
	goto tr52;
st41:
	if ( ++p == pe )
		goto _test_eof41;
case 41:
	if ( (*p) == 115 )
		goto st42;
	goto tr52;
st42:
	if ( ++p == pe )
		goto _test_eof42;
case 42:
	if ( (*p) == 99 )
		goto st43;
	goto tr52;
st43:
	if ( ++p == pe )
		goto _test_eof43;
case 43:
	if ( (*p) == 114 )
		goto st44;
	goto tr52;
st44:
	if ( ++p == pe )
		goto _test_eof44;
case 44:
	if ( (*p) == 105 )
		goto st45;
	goto tr52;
st45:
	if ( ++p == pe )
		goto _test_eof45;
case 45:
	if ( (*p) == 112 )
		goto st46;
	goto tr52;
st46:
	if ( ++p == pe )
		goto _test_eof46;
case 46:
	if ( (*p) == 116 )
		goto st47;
	goto tr52;
st47:
	if ( ++p == pe )
		goto _test_eof47;
case 47:
	if ( (*p) == 105 )
		goto st48;
	goto tr52;
st48:
	if ( ++p == pe )
		goto _test_eof48;
case 48:
	if ( (*p) == 111 )
		goto st49;
	goto tr52;
st49:
	if ( ++p == pe )
		goto _test_eof49;
case 49:
	if ( (*p) == 110 )
		goto st50;
	goto tr52;
st50:
	if ( ++p == pe )
		goto _test_eof50;
case 50:
	if ( (*p) == 61 )
		goto st51;
	goto tr52;
st51:
	if ( ++p == pe )
		goto _test_eof51;
case 51:
	if ( (*p) == 34 )
		goto tr76;
	goto tr52;
tr76:
#line 117 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_key(*this, "Description");
    }
	goto st52;
st52:
	if ( ++p == pe )
		goto _test_eof52;
case 52:
#line 2202 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) > 33 ) {
		if ( 35 <= (*p) && (*p) <= 126 )
			goto tr77;
	} else if ( (*p) >= 32 )
		goto tr77;
	goto tr52;
tr77:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st53;
tr79:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st53;
st53:
	if ( ++p == pe )
		goto _test_eof53;
case 53:
#line 2229 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 34 )
		goto tr80;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr79;
	goto tr78;
tr80:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
	goto st54;
st54:
	if ( ++p == pe )
		goto _test_eof54;
case 54:
#line 2246 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 62 )
		goto st55;
	goto tr78;
st55:
	if ( ++p == pe )
		goto _test_eof55;
case 55:
	if ( (*p) == 10 )
		goto tr51;
	goto tr52;
tr27:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st56;
st56:
	if ( ++p == pe )
		goto _test_eof56;
case 56:
#line 2271 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 73: goto tr83;
		case 79: goto tr84;
		case 95: goto tr37;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto tr36;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr36;
		} else
			goto tr37;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr36;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr36;
		} else
			goto tr37;
	} else
		goto tr37;
	goto tr82;
tr83:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st57;
st57:
	if ( ++p == pe )
		goto _test_eof57;
case 57:
#line 2310 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 76: goto tr86;
		case 95: goto tr37;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto tr36;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr36;
		} else
			goto tr37;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr36;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr36;
		} else
			goto tr37;
	} else
		goto tr37;
	goto tr85;
tr86:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st58;
st58:
	if ( ++p == pe )
		goto _test_eof58;
case 58:
#line 2348 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 84: goto tr87;
		case 95: goto tr37;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto tr36;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr36;
		} else
			goto tr37;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr36;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr36;
		} else
			goto tr37;
	} else
		goto tr37;
	goto tr85;
tr87:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st59;
st59:
	if ( ++p == pe )
		goto _test_eof59;
case 59:
#line 2386 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 69: goto tr88;
		case 95: goto tr37;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto tr36;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr36;
		} else
			goto tr37;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr36;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr36;
		} else
			goto tr37;
	} else
		goto tr37;
	goto tr85;
tr88:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st60;
st60:
	if ( ++p == pe )
		goto _test_eof60;
case 60:
#line 2424 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 82: goto tr89;
		case 95: goto tr37;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto tr36;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr36;
		} else
			goto tr37;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr36;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr36;
		} else
			goto tr37;
	} else
		goto tr37;
	goto tr85;
tr89:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st61;
st61:
	if ( ++p == pe )
		goto _test_eof61;
case 61:
#line 2462 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr90;
		case 95: goto tr37;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto tr36;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr36;
		} else
			goto tr37;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr36;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr36;
		} else
			goto tr37;
	} else
		goto tr37;
	goto tr85;
tr90:
#line 81 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "FILTER");
    }
	goto st62;
st62:
	if ( ++p == pe )
		goto _test_eof62;
case 62:
#line 2499 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 60 )
		goto st63;
	goto tr85;
st63:
	if ( ++p == pe )
		goto _test_eof63;
case 63:
	if ( (*p) == 73 )
		goto st64;
	goto tr85;
st64:
	if ( ++p == pe )
		goto _test_eof64;
case 64:
	if ( (*p) == 68 )
		goto st65;
	goto tr85;
st65:
	if ( ++p == pe )
		goto _test_eof65;
case 65:
	if ( (*p) == 61 )
		goto st66;
	goto tr85;
st66:
	if ( ++p == pe )
		goto _test_eof66;
case 66:
	if ( (*p) == 95 )
		goto tr96;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr96;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr97;
		} else if ( (*p) >= 65 )
			goto tr97;
	} else
		goto tr97;
	goto tr95;
tr96:
#line 105 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_key(*this, "ID");
    }
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st67;
st67:
	if ( ++p == pe )
		goto _test_eof67;
case 67:
#line 2556 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 95 )
		goto st67;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st67;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr99;
		} else if ( (*p) >= 65 )
			goto tr99;
	} else
		goto tr99;
	goto tr95;
tr99:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st68;
tr97:
#line 105 "cpp/src/bioformats/vcf/vcf_v41.ragel"
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
	goto st68;
st68:
	if ( ++p == pe )
		goto _test_eof68;
case 68:
#line 2595 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto tr100;
		case 95: goto tr99;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr99;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr99;
		} else if ( (*p) >= 65 )
			goto tr99;
	} else
		goto tr99;
	goto tr95;
tr100:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
	goto st69;
st69:
	if ( ++p == pe )
		goto _test_eof69;
case 69:
#line 2623 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 68 )
		goto st70;
	goto tr85;
st70:
	if ( ++p == pe )
		goto _test_eof70;
case 70:
	if ( (*p) == 101 )
		goto st71;
	goto tr85;
st71:
	if ( ++p == pe )
		goto _test_eof71;
case 71:
	if ( (*p) == 115 )
		goto st72;
	goto tr85;
st72:
	if ( ++p == pe )
		goto _test_eof72;
case 72:
	if ( (*p) == 99 )
		goto st73;
	goto tr85;
st73:
	if ( ++p == pe )
		goto _test_eof73;
case 73:
	if ( (*p) == 114 )
		goto st74;
	goto tr85;
st74:
	if ( ++p == pe )
		goto _test_eof74;
case 74:
	if ( (*p) == 105 )
		goto st75;
	goto tr85;
st75:
	if ( ++p == pe )
		goto _test_eof75;
case 75:
	if ( (*p) == 112 )
		goto st76;
	goto tr85;
st76:
	if ( ++p == pe )
		goto _test_eof76;
case 76:
	if ( (*p) == 116 )
		goto st77;
	goto tr85;
st77:
	if ( ++p == pe )
		goto _test_eof77;
case 77:
	if ( (*p) == 105 )
		goto st78;
	goto tr85;
st78:
	if ( ++p == pe )
		goto _test_eof78;
case 78:
	if ( (*p) == 111 )
		goto st79;
	goto tr85;
st79:
	if ( ++p == pe )
		goto _test_eof79;
case 79:
	if ( (*p) == 110 )
		goto st80;
	goto tr85;
st80:
	if ( ++p == pe )
		goto _test_eof80;
case 80:
	if ( (*p) == 61 )
		goto st81;
	goto tr85;
st81:
	if ( ++p == pe )
		goto _test_eof81;
case 81:
	if ( (*p) == 34 )
		goto tr113;
	goto tr85;
tr113:
#line 117 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_key(*this, "Description");
    }
	goto st82;
st82:
	if ( ++p == pe )
		goto _test_eof82;
case 82:
#line 2721 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) > 33 ) {
		if ( 35 <= (*p) && (*p) <= 126 )
			goto tr114;
	} else if ( (*p) >= 32 )
		goto tr114;
	goto tr85;
tr114:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st83;
tr116:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st83;
st83:
	if ( ++p == pe )
		goto _test_eof83;
case 83:
#line 2748 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 34 )
		goto tr117;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr116;
	goto tr115;
tr117:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
	goto st84;
st84:
	if ( ++p == pe )
		goto _test_eof84;
case 84:
#line 2765 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 62 )
		goto st85;
	goto tr115;
st85:
	if ( ++p == pe )
		goto _test_eof85;
case 85:
	if ( (*p) == 10 )
		goto tr51;
	goto tr85;
tr84:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st86;
st86:
	if ( ++p == pe )
		goto _test_eof86;
case 86:
#line 2786 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 82: goto tr120;
		case 95: goto tr37;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto tr36;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr36;
		} else
			goto tr37;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr36;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr36;
		} else
			goto tr37;
	} else
		goto tr37;
	goto tr119;
tr120:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st87;
st87:
	if ( ++p == pe )
		goto _test_eof87;
case 87:
#line 2824 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 77: goto tr121;
		case 95: goto tr37;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto tr36;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr36;
		} else
			goto tr37;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr36;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr36;
		} else
			goto tr37;
	} else
		goto tr37;
	goto tr119;
tr121:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st88;
st88:
	if ( ++p == pe )
		goto _test_eof88;
case 88:
#line 2862 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 65: goto tr122;
		case 95: goto tr37;
	}
	if ( (*p) < 66 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto tr36;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr36;
		} else
			goto tr37;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr36;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr36;
		} else
			goto tr37;
	} else
		goto tr37;
	goto tr119;
tr122:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st89;
st89:
	if ( ++p == pe )
		goto _test_eof89;
case 89:
#line 2900 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 84: goto tr123;
		case 95: goto tr37;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto tr36;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr36;
		} else
			goto tr37;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr36;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr36;
		} else
			goto tr37;
	} else
		goto tr37;
	goto tr119;
tr123:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st90;
st90:
	if ( ++p == pe )
		goto _test_eof90;
case 90:
#line 2938 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr124;
		case 95: goto tr37;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto tr36;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr36;
		} else
			goto tr37;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr36;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr36;
		} else
			goto tr37;
	} else
		goto tr37;
	goto tr119;
tr124:
#line 85 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "FORMAT");
    }
	goto st91;
st91:
	if ( ++p == pe )
		goto _test_eof91;
case 91:
#line 2975 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 60 )
		goto st92;
	goto tr119;
st92:
	if ( ++p == pe )
		goto _test_eof92;
case 92:
	if ( (*p) == 73 )
		goto st93;
	goto tr119;
st93:
	if ( ++p == pe )
		goto _test_eof93;
case 93:
	if ( (*p) == 68 )
		goto st94;
	goto tr119;
st94:
	if ( ++p == pe )
		goto _test_eof94;
case 94:
	if ( (*p) == 61 )
		goto st95;
	goto tr119;
st95:
	if ( ++p == pe )
		goto _test_eof95;
case 95:
	if ( (*p) == 95 )
		goto tr130;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr130;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr131;
		} else if ( (*p) >= 65 )
			goto tr131;
	} else
		goto tr131;
	goto tr129;
tr130:
#line 105 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_key(*this, "ID");
    }
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st96;
st96:
	if ( ++p == pe )
		goto _test_eof96;
case 96:
#line 3032 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 95 )
		goto st96;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st96;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr133;
		} else if ( (*p) >= 65 )
			goto tr133;
	} else
		goto tr133;
	goto tr129;
tr133:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st97;
tr131:
#line 105 "cpp/src/bioformats/vcf/vcf_v41.ragel"
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
	goto st97;
st97:
	if ( ++p == pe )
		goto _test_eof97;
case 97:
#line 3071 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto tr134;
		case 95: goto tr133;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr133;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr133;
		} else if ( (*p) >= 65 )
			goto tr133;
	} else
		goto tr133;
	goto tr129;
tr134:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
	goto st98;
st98:
	if ( ++p == pe )
		goto _test_eof98;
case 98:
#line 3099 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 78 )
		goto st99;
	goto tr119;
st99:
	if ( ++p == pe )
		goto _test_eof99;
case 99:
	if ( (*p) == 117 )
		goto st100;
	goto tr119;
st100:
	if ( ++p == pe )
		goto _test_eof100;
case 100:
	if ( (*p) == 109 )
		goto st101;
	goto tr119;
st101:
	if ( ++p == pe )
		goto _test_eof101;
case 101:
	if ( (*p) == 98 )
		goto st102;
	goto tr119;
st102:
	if ( ++p == pe )
		goto _test_eof102;
case 102:
	if ( (*p) == 101 )
		goto st103;
	goto tr119;
st103:
	if ( ++p == pe )
		goto _test_eof103;
case 103:
	if ( (*p) == 114 )
		goto st104;
	goto tr119;
st104:
	if ( ++p == pe )
		goto _test_eof104;
case 104:
	if ( (*p) == 61 )
		goto st105;
	goto tr119;
st105:
	if ( ++p == pe )
		goto _test_eof105;
case 105:
	switch( (*p) ) {
		case 46: goto tr143;
		case 65: goto tr143;
		case 71: goto tr143;
		case 82: goto tr143;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr144;
	goto tr142;
tr143:
#line 109 "cpp/src/bioformats/vcf/vcf_v41.ragel"
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
	goto st106;
st106:
	if ( ++p == pe )
		goto _test_eof106;
case 106:
#line 3176 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 44 )
		goto tr145;
	goto tr142;
tr145:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
	goto st107;
st107:
	if ( ++p == pe )
		goto _test_eof107;
case 107:
#line 3191 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 84 )
		goto st108;
	goto tr119;
st108:
	if ( ++p == pe )
		goto _test_eof108;
case 108:
	if ( (*p) == 121 )
		goto st109;
	goto tr119;
st109:
	if ( ++p == pe )
		goto _test_eof109;
case 109:
	if ( (*p) == 112 )
		goto st110;
	goto tr119;
st110:
	if ( ++p == pe )
		goto _test_eof110;
case 110:
	if ( (*p) == 101 )
		goto st111;
	goto tr119;
st111:
	if ( ++p == pe )
		goto _test_eof111;
case 111:
	if ( (*p) == 61 )
		goto st112;
	goto tr119;
st112:
	if ( ++p == pe )
		goto _test_eof112;
case 112:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr152;
	} else if ( (*p) >= 65 )
		goto tr152;
	goto tr151;
tr154:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st113;
tr152:
#line 113 "cpp/src/bioformats/vcf/vcf_v41.ragel"
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
	goto st113;
st113:
	if ( ++p == pe )
		goto _test_eof113;
case 113:
#line 3257 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 44 )
		goto tr153;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr154;
	} else if ( (*p) >= 65 )
		goto tr154;
	goto tr151;
tr153:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
	goto st114;
st114:
	if ( ++p == pe )
		goto _test_eof114;
case 114:
#line 3277 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 68 )
		goto st115;
	goto tr119;
st115:
	if ( ++p == pe )
		goto _test_eof115;
case 115:
	if ( (*p) == 101 )
		goto st116;
	goto tr119;
st116:
	if ( ++p == pe )
		goto _test_eof116;
case 116:
	if ( (*p) == 115 )
		goto st117;
	goto tr119;
st117:
	if ( ++p == pe )
		goto _test_eof117;
case 117:
	if ( (*p) == 99 )
		goto st118;
	goto tr119;
st118:
	if ( ++p == pe )
		goto _test_eof118;
case 118:
	if ( (*p) == 114 )
		goto st119;
	goto tr119;
st119:
	if ( ++p == pe )
		goto _test_eof119;
case 119:
	if ( (*p) == 105 )
		goto st120;
	goto tr119;
st120:
	if ( ++p == pe )
		goto _test_eof120;
case 120:
	if ( (*p) == 112 )
		goto st121;
	goto tr119;
st121:
	if ( ++p == pe )
		goto _test_eof121;
case 121:
	if ( (*p) == 116 )
		goto st122;
	goto tr119;
st122:
	if ( ++p == pe )
		goto _test_eof122;
case 122:
	if ( (*p) == 105 )
		goto st123;
	goto tr119;
st123:
	if ( ++p == pe )
		goto _test_eof123;
case 123:
	if ( (*p) == 111 )
		goto st124;
	goto tr119;
st124:
	if ( ++p == pe )
		goto _test_eof124;
case 124:
	if ( (*p) == 110 )
		goto st125;
	goto tr119;
st125:
	if ( ++p == pe )
		goto _test_eof125;
case 125:
	if ( (*p) == 61 )
		goto st126;
	goto tr119;
st126:
	if ( ++p == pe )
		goto _test_eof126;
case 126:
	if ( (*p) == 34 )
		goto tr167;
	goto tr119;
tr167:
#line 117 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_key(*this, "Description");
    }
	goto st127;
st127:
	if ( ++p == pe )
		goto _test_eof127;
case 127:
#line 3375 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) > 33 ) {
		if ( 35 <= (*p) && (*p) <= 126 )
			goto tr168;
	} else if ( (*p) >= 32 )
		goto tr168;
	goto tr119;
tr168:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st128;
tr170:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st128;
st128:
	if ( ++p == pe )
		goto _test_eof128;
case 128:
#line 3402 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 34 )
		goto tr171;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr170;
	goto tr169;
tr171:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
	goto st129;
st129:
	if ( ++p == pe )
		goto _test_eof129;
case 129:
#line 3419 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 62 )
		goto st130;
	goto tr169;
st130:
	if ( ++p == pe )
		goto _test_eof130;
case 130:
	if ( (*p) == 10 )
		goto tr51;
	goto tr119;
tr173:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st131;
tr144:
#line 109 "cpp/src/bioformats/vcf/vcf_v41.ragel"
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
	goto st131;
st131:
	if ( ++p == pe )
		goto _test_eof131;
case 131:
#line 3454 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 44 )
		goto tr145;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr173;
	goto tr142;
tr28:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st132;
st132:
	if ( ++p == pe )
		goto _test_eof132;
case 132:
#line 3474 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 78: goto tr175;
		case 95: goto tr37;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto tr36;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr36;
		} else
			goto tr37;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr36;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr36;
		} else
			goto tr37;
	} else
		goto tr37;
	goto tr174;
tr175:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st133;
st133:
	if ( ++p == pe )
		goto _test_eof133;
case 133:
#line 3512 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 70: goto tr176;
		case 95: goto tr37;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto tr36;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr36;
		} else
			goto tr37;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr36;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr36;
		} else
			goto tr37;
	} else
		goto tr37;
	goto tr174;
tr176:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st134;
st134:
	if ( ++p == pe )
		goto _test_eof134;
case 134:
#line 3550 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 79: goto tr177;
		case 95: goto tr37;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto tr36;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr36;
		} else
			goto tr37;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr36;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr36;
		} else
			goto tr37;
	} else
		goto tr37;
	goto tr174;
tr177:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st135;
st135:
	if ( ++p == pe )
		goto _test_eof135;
case 135:
#line 3588 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr178;
		case 95: goto tr37;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto tr36;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr36;
		} else
			goto tr37;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr36;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr36;
		} else
			goto tr37;
	} else
		goto tr37;
	goto tr174;
tr178:
#line 89 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "INFO");
    }
	goto st136;
st136:
	if ( ++p == pe )
		goto _test_eof136;
case 136:
#line 3625 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 60 )
		goto st137;
	goto tr174;
st137:
	if ( ++p == pe )
		goto _test_eof137;
case 137:
	if ( (*p) == 73 )
		goto st138;
	goto tr174;
st138:
	if ( ++p == pe )
		goto _test_eof138;
case 138:
	if ( (*p) == 68 )
		goto st139;
	goto tr174;
st139:
	if ( ++p == pe )
		goto _test_eof139;
case 139:
	if ( (*p) == 61 )
		goto st140;
	goto tr174;
st140:
	if ( ++p == pe )
		goto _test_eof140;
case 140:
	if ( (*p) == 95 )
		goto tr184;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr184;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr185;
		} else if ( (*p) >= 65 )
			goto tr185;
	} else
		goto tr185;
	goto tr183;
tr184:
#line 105 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_key(*this, "ID");
    }
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st141;
st141:
	if ( ++p == pe )
		goto _test_eof141;
case 141:
#line 3682 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 95 )
		goto st141;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st141;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr187;
		} else if ( (*p) >= 65 )
			goto tr187;
	} else
		goto tr187;
	goto tr183;
tr187:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st142;
tr185:
#line 105 "cpp/src/bioformats/vcf/vcf_v41.ragel"
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
	goto st142;
st142:
	if ( ++p == pe )
		goto _test_eof142;
case 142:
#line 3721 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto tr188;
		case 95: goto tr187;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr187;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr187;
		} else if ( (*p) >= 65 )
			goto tr187;
	} else
		goto tr187;
	goto tr183;
tr188:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
	goto st143;
st143:
	if ( ++p == pe )
		goto _test_eof143;
case 143:
#line 3749 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 78 )
		goto st144;
	goto tr174;
st144:
	if ( ++p == pe )
		goto _test_eof144;
case 144:
	if ( (*p) == 117 )
		goto st145;
	goto tr174;
st145:
	if ( ++p == pe )
		goto _test_eof145;
case 145:
	if ( (*p) == 109 )
		goto st146;
	goto tr174;
st146:
	if ( ++p == pe )
		goto _test_eof146;
case 146:
	if ( (*p) == 98 )
		goto st147;
	goto tr174;
st147:
	if ( ++p == pe )
		goto _test_eof147;
case 147:
	if ( (*p) == 101 )
		goto st148;
	goto tr174;
st148:
	if ( ++p == pe )
		goto _test_eof148;
case 148:
	if ( (*p) == 114 )
		goto st149;
	goto tr174;
st149:
	if ( ++p == pe )
		goto _test_eof149;
case 149:
	if ( (*p) == 61 )
		goto st150;
	goto tr174;
st150:
	if ( ++p == pe )
		goto _test_eof150;
case 150:
	switch( (*p) ) {
		case 46: goto tr197;
		case 65: goto tr197;
		case 71: goto tr197;
		case 82: goto tr197;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr198;
	goto tr196;
tr197:
#line 109 "cpp/src/bioformats/vcf/vcf_v41.ragel"
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
	goto st151;
st151:
	if ( ++p == pe )
		goto _test_eof151;
case 151:
#line 3826 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 44 )
		goto tr199;
	goto tr196;
tr199:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
	goto st152;
st152:
	if ( ++p == pe )
		goto _test_eof152;
case 152:
#line 3841 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 84 )
		goto st153;
	goto tr174;
st153:
	if ( ++p == pe )
		goto _test_eof153;
case 153:
	if ( (*p) == 121 )
		goto st154;
	goto tr174;
st154:
	if ( ++p == pe )
		goto _test_eof154;
case 154:
	if ( (*p) == 112 )
		goto st155;
	goto tr174;
st155:
	if ( ++p == pe )
		goto _test_eof155;
case 155:
	if ( (*p) == 101 )
		goto st156;
	goto tr174;
st156:
	if ( ++p == pe )
		goto _test_eof156;
case 156:
	if ( (*p) == 61 )
		goto st157;
	goto tr174;
st157:
	if ( ++p == pe )
		goto _test_eof157;
case 157:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr206;
	} else if ( (*p) >= 65 )
		goto tr206;
	goto tr205;
tr208:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st158;
tr206:
#line 113 "cpp/src/bioformats/vcf/vcf_v41.ragel"
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
	goto st158;
st158:
	if ( ++p == pe )
		goto _test_eof158;
case 158:
#line 3907 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 44 )
		goto tr207;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr208;
	} else if ( (*p) >= 65 )
		goto tr208;
	goto tr205;
tr207:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
	goto st159;
st159:
	if ( ++p == pe )
		goto _test_eof159;
case 159:
#line 3927 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 68 )
		goto st160;
	goto tr174;
st160:
	if ( ++p == pe )
		goto _test_eof160;
case 160:
	if ( (*p) == 101 )
		goto st161;
	goto tr174;
st161:
	if ( ++p == pe )
		goto _test_eof161;
case 161:
	if ( (*p) == 115 )
		goto st162;
	goto tr174;
st162:
	if ( ++p == pe )
		goto _test_eof162;
case 162:
	if ( (*p) == 99 )
		goto st163;
	goto tr174;
st163:
	if ( ++p == pe )
		goto _test_eof163;
case 163:
	if ( (*p) == 114 )
		goto st164;
	goto tr174;
st164:
	if ( ++p == pe )
		goto _test_eof164;
case 164:
	if ( (*p) == 105 )
		goto st165;
	goto tr174;
st165:
	if ( ++p == pe )
		goto _test_eof165;
case 165:
	if ( (*p) == 112 )
		goto st166;
	goto tr174;
st166:
	if ( ++p == pe )
		goto _test_eof166;
case 166:
	if ( (*p) == 116 )
		goto st167;
	goto tr174;
st167:
	if ( ++p == pe )
		goto _test_eof167;
case 167:
	if ( (*p) == 105 )
		goto st168;
	goto tr174;
st168:
	if ( ++p == pe )
		goto _test_eof168;
case 168:
	if ( (*p) == 111 )
		goto st169;
	goto tr174;
st169:
	if ( ++p == pe )
		goto _test_eof169;
case 169:
	if ( (*p) == 110 )
		goto st170;
	goto tr174;
st170:
	if ( ++p == pe )
		goto _test_eof170;
case 170:
	if ( (*p) == 61 )
		goto st171;
	goto tr174;
st171:
	if ( ++p == pe )
		goto _test_eof171;
case 171:
	if ( (*p) == 34 )
		goto tr221;
	goto tr174;
tr221:
#line 117 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_key(*this, "Description");
    }
	goto st172;
st172:
	if ( ++p == pe )
		goto _test_eof172;
case 172:
#line 4025 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) > 33 ) {
		if ( 35 <= (*p) && (*p) <= 126 )
			goto tr222;
	} else if ( (*p) >= 32 )
		goto tr222;
	goto tr174;
tr222:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st173;
tr224:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st173;
st173:
	if ( ++p == pe )
		goto _test_eof173;
case 173:
#line 4052 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 34 )
		goto tr225;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr224;
	goto tr223;
tr225:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
	goto st174;
st174:
	if ( ++p == pe )
		goto _test_eof174;
case 174:
#line 4069 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto st175;
		case 62: goto st179;
	}
	goto tr223;
st175:
	if ( ++p == pe )
		goto _test_eof175;
case 175:
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
	goto tr183;
tr228:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st176;
st176:
	if ( ++p == pe )
		goto _test_eof176;
case 176:
#line 4103 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 95 )
		goto st176;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st176;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr231;
		} else if ( (*p) >= 65 )
			goto tr231;
	} else
		goto tr231;
	goto tr183;
tr229:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st177;
tr231:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st177;
st177:
	if ( ++p == pe )
		goto _test_eof177;
case 177:
#line 4138 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 61: goto tr232;
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
	goto tr183;
tr232:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
	goto st178;
st178:
	if ( ++p == pe )
		goto _test_eof178;
case 178:
#line 4166 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 34 )
		goto st172;
	goto tr174;
st179:
	if ( ++p == pe )
		goto _test_eof179;
case 179:
	if ( (*p) == 10 )
		goto tr51;
	goto tr174;
tr234:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st180;
tr198:
#line 109 "cpp/src/bioformats/vcf/vcf_v41.ragel"
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
	goto st180;
st180:
	if ( ++p == pe )
		goto _test_eof180;
case 180:
#line 4201 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 44 )
		goto tr199;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr234;
	goto tr196;
tr29:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st181;
st181:
	if ( ++p == pe )
		goto _test_eof181;
case 181:
#line 4221 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 69: goto tr236;
		case 95: goto tr37;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto tr36;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr36;
		} else
			goto tr37;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr36;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr36;
		} else
			goto tr37;
	} else
		goto tr37;
	goto tr235;
tr236:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st182;
st182:
	if ( ++p == pe )
		goto _test_eof182;
case 182:
#line 4259 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 68: goto tr237;
		case 95: goto tr37;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto tr36;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr36;
		} else
			goto tr37;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr36;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr36;
		} else
			goto tr37;
	} else
		goto tr37;
	goto tr235;
tr237:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st183;
st183:
	if ( ++p == pe )
		goto _test_eof183;
case 183:
#line 4297 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 73: goto tr238;
		case 95: goto tr37;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto tr36;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr36;
		} else
			goto tr37;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr36;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr36;
		} else
			goto tr37;
	} else
		goto tr37;
	goto tr235;
tr238:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st184;
st184:
	if ( ++p == pe )
		goto _test_eof184;
case 184:
#line 4335 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 71: goto tr239;
		case 95: goto tr37;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto tr36;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr36;
		} else
			goto tr37;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr36;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr36;
		} else
			goto tr37;
	} else
		goto tr37;
	goto tr235;
tr239:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st185;
st185:
	if ( ++p == pe )
		goto _test_eof185;
case 185:
#line 4373 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 82: goto tr240;
		case 95: goto tr37;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto tr36;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr36;
		} else
			goto tr37;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr36;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr36;
		} else
			goto tr37;
	} else
		goto tr37;
	goto tr235;
tr240:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st186;
st186:
	if ( ++p == pe )
		goto _test_eof186;
case 186:
#line 4411 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 69: goto tr241;
		case 95: goto tr37;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto tr36;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr36;
		} else
			goto tr37;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr36;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr36;
		} else
			goto tr37;
	} else
		goto tr37;
	goto tr235;
tr241:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st187;
st187:
	if ( ++p == pe )
		goto _test_eof187;
case 187:
#line 4449 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 69: goto tr242;
		case 95: goto tr37;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto tr36;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr36;
		} else
			goto tr37;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr36;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr36;
		} else
			goto tr37;
	} else
		goto tr37;
	goto tr235;
tr242:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st188;
st188:
	if ( ++p == pe )
		goto _test_eof188;
case 188:
#line 4487 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr243;
		case 95: goto tr37;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto tr36;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr36;
		} else
			goto tr37;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr36;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr36;
		} else
			goto tr37;
	} else
		goto tr37;
	goto tr235;
tr243:
#line 93 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "PEDIGREE");
    }
	goto st189;
st189:
	if ( ++p == pe )
		goto _test_eof189;
case 189:
#line 4524 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 60 )
		goto st190;
	goto tr235;
tr255:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
	goto st190;
st190:
	if ( ++p == pe )
		goto _test_eof190;
case 190:
#line 4539 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 95 )
		goto tr246;
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
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st191;
st191:
	if ( ++p == pe )
		goto _test_eof191;
case 191:
#line 4564 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 95 )
		goto st191;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st191;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr249;
		} else if ( (*p) >= 65 )
			goto tr249;
	} else
		goto tr249;
	goto tr245;
tr247:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st192;
tr249:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st192;
st192:
	if ( ++p == pe )
		goto _test_eof192;
case 192:
#line 4599 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 61: goto tr250;
		case 95: goto tr249;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
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
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
	goto st193;
st193:
	if ( ++p == pe )
		goto _test_eof193;
case 193:
#line 4627 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 95 )
		goto tr251;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr251;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr252;
		} else if ( (*p) >= 65 )
			goto tr252;
	} else
		goto tr252;
	goto tr245;
tr251:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st194;
st194:
	if ( ++p == pe )
		goto _test_eof194;
case 194:
#line 4652 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 95 )
		goto st194;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st194;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr254;
		} else if ( (*p) >= 65 )
			goto tr254;
	} else
		goto tr254;
	goto tr245;
tr252:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st195;
tr254:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st195;
st195:
	if ( ++p == pe )
		goto _test_eof195;
case 195:
#line 4687 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto tr255;
		case 62: goto tr256;
		case 95: goto tr254;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr254;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr254;
		} else if ( (*p) >= 65 )
			goto tr254;
	} else
		goto tr254;
	goto tr245;
tr256:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
	goto st196;
st196:
	if ( ++p == pe )
		goto _test_eof196;
case 196:
#line 4716 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 10 )
		goto tr51;
	goto tr235;
tr30:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st197;
st197:
	if ( ++p == pe )
		goto _test_eof197;
case 197:
#line 4734 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 65: goto tr258;
		case 95: goto tr37;
	}
	if ( (*p) < 66 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto tr36;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr36;
		} else
			goto tr37;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr36;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr36;
		} else
			goto tr37;
	} else
		goto tr37;
	goto tr257;
tr258:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st198;
st198:
	if ( ++p == pe )
		goto _test_eof198;
case 198:
#line 4772 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 77: goto tr259;
		case 95: goto tr37;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto tr36;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr36;
		} else
			goto tr37;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr36;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr36;
		} else
			goto tr37;
	} else
		goto tr37;
	goto tr257;
tr259:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st199;
st199:
	if ( ++p == pe )
		goto _test_eof199;
case 199:
#line 4810 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 80: goto tr260;
		case 95: goto tr37;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto tr36;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr36;
		} else
			goto tr37;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr36;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr36;
		} else
			goto tr37;
	} else
		goto tr37;
	goto tr257;
tr260:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st200;
st200:
	if ( ++p == pe )
		goto _test_eof200;
case 200:
#line 4848 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 76: goto tr261;
		case 95: goto tr37;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto tr36;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr36;
		} else
			goto tr37;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr36;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr36;
		} else
			goto tr37;
	} else
		goto tr37;
	goto tr257;
tr261:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st201;
st201:
	if ( ++p == pe )
		goto _test_eof201;
case 201:
#line 4886 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 69: goto tr262;
		case 95: goto tr37;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto tr36;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr36;
		} else
			goto tr37;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr36;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr36;
		} else
			goto tr37;
	} else
		goto tr37;
	goto tr257;
tr262:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st202;
st202:
	if ( ++p == pe )
		goto _test_eof202;
case 202:
#line 4924 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr263;
		case 95: goto tr37;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto tr36;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr36;
		} else
			goto tr37;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr36;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr36;
		} else
			goto tr37;
	} else
		goto tr37;
	goto tr257;
tr263:
#line 101 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "SAMPLE");
    }
	goto st203;
st203:
	if ( ++p == pe )
		goto _test_eof203;
case 203:
#line 4961 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 60 )
		goto st204;
	goto tr257;
st204:
	if ( ++p == pe )
		goto _test_eof204;
case 204:
	if ( (*p) == 73 )
		goto st205;
	goto tr257;
st205:
	if ( ++p == pe )
		goto _test_eof205;
case 205:
	if ( (*p) == 68 )
		goto st206;
	goto tr257;
st206:
	if ( ++p == pe )
		goto _test_eof206;
case 206:
	if ( (*p) == 61 )
		goto st207;
	goto tr257;
st207:
	if ( ++p == pe )
		goto _test_eof207;
case 207:
	if ( (*p) == 95 )
		goto tr269;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr269;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr270;
		} else if ( (*p) >= 65 )
			goto tr270;
	} else
		goto tr270;
	goto tr268;
tr269:
#line 105 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_key(*this, "ID");
    }
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st208;
st208:
	if ( ++p == pe )
		goto _test_eof208;
case 208:
#line 5018 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 95 )
		goto st208;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st208;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr272;
		} else if ( (*p) >= 65 )
			goto tr272;
	} else
		goto tr272;
	goto tr268;
tr272:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st209;
tr270:
#line 105 "cpp/src/bioformats/vcf/vcf_v41.ragel"
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
	goto st209;
st209:
	if ( ++p == pe )
		goto _test_eof209;
case 209:
#line 5057 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto tr274;
		case 95: goto tr272;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr272;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr272;
		} else if ( (*p) >= 65 )
			goto tr272;
	} else
		goto tr272;
	goto tr273;
tr274:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
	goto st210;
st210:
	if ( ++p == pe )
		goto _test_eof210;
case 210:
#line 5085 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 71 )
		goto st211;
	goto tr275;
st211:
	if ( ++p == pe )
		goto _test_eof211;
case 211:
	if ( (*p) == 101 )
		goto st212;
	goto tr275;
st212:
	if ( ++p == pe )
		goto _test_eof212;
case 212:
	if ( (*p) == 110 )
		goto st213;
	goto tr275;
st213:
	if ( ++p == pe )
		goto _test_eof213;
case 213:
	if ( (*p) == 111 )
		goto st214;
	goto tr275;
st214:
	if ( ++p == pe )
		goto _test_eof214;
case 214:
	if ( (*p) == 109 )
		goto st215;
	goto tr275;
st215:
	if ( ++p == pe )
		goto _test_eof215;
case 215:
	if ( (*p) == 101 )
		goto st216;
	goto tr275;
st216:
	if ( ++p == pe )
		goto _test_eof216;
case 216:
	if ( (*p) == 115 )
		goto st217;
	goto tr275;
st217:
	if ( ++p == pe )
		goto _test_eof217;
case 217:
	if ( (*p) == 61 )
		goto st218;
	goto tr275;
st218:
	if ( ++p == pe )
		goto _test_eof218;
case 218:
	if ( (*p) < 45 ) {
		if ( 32 <= (*p) && (*p) <= 43 )
			goto tr284;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr284;
	} else
		goto tr284;
	goto tr275;
tr286:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st219;
tr284:
#line 121 "cpp/src/bioformats/vcf/vcf_v41.ragel"
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
	goto st219;
st219:
	if ( ++p == pe )
		goto _test_eof219;
case 219:
#line 5175 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 44 )
		goto tr287;
	if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr286;
	} else if ( (*p) >= 32 )
		goto tr286;
	goto tr285;
tr287:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
	goto st220;
st220:
	if ( ++p == pe )
		goto _test_eof220;
case 220:
#line 5195 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 77 )
		goto st221;
	goto tr288;
st221:
	if ( ++p == pe )
		goto _test_eof221;
case 221:
	if ( (*p) == 105 )
		goto st222;
	goto tr288;
st222:
	if ( ++p == pe )
		goto _test_eof222;
case 222:
	if ( (*p) == 120 )
		goto st223;
	goto tr288;
st223:
	if ( ++p == pe )
		goto _test_eof223;
case 223:
	if ( (*p) == 116 )
		goto st224;
	goto tr288;
st224:
	if ( ++p == pe )
		goto _test_eof224;
case 224:
	if ( (*p) == 117 )
		goto st225;
	goto tr288;
st225:
	if ( ++p == pe )
		goto _test_eof225;
case 225:
	if ( (*p) == 114 )
		goto st226;
	goto tr288;
st226:
	if ( ++p == pe )
		goto _test_eof226;
case 226:
	if ( (*p) == 101 )
		goto st227;
	goto tr288;
st227:
	if ( ++p == pe )
		goto _test_eof227;
case 227:
	if ( (*p) == 61 )
		goto st228;
	goto tr288;
st228:
	if ( ++p == pe )
		goto _test_eof228;
case 228:
	if ( (*p) < 45 ) {
		if ( 32 <= (*p) && (*p) <= 43 )
			goto tr297;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr297;
	} else
		goto tr297;
	goto tr288;
tr299:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st229;
tr297:
#line 125 "cpp/src/bioformats/vcf/vcf_v41.ragel"
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
	goto st229;
st229:
	if ( ++p == pe )
		goto _test_eof229;
case 229:
#line 5285 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 44 )
		goto tr300;
	if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr299;
	} else if ( (*p) >= 32 )
		goto tr299;
	goto tr298;
tr300:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
	goto st230;
st230:
	if ( ++p == pe )
		goto _test_eof230;
case 230:
#line 5305 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 68 )
		goto st231;
	goto tr301;
st231:
	if ( ++p == pe )
		goto _test_eof231;
case 231:
	if ( (*p) == 101 )
		goto st232;
	goto tr301;
st232:
	if ( ++p == pe )
		goto _test_eof232;
case 232:
	if ( (*p) == 115 )
		goto st233;
	goto tr301;
st233:
	if ( ++p == pe )
		goto _test_eof233;
case 233:
	if ( (*p) == 99 )
		goto st234;
	goto tr301;
st234:
	if ( ++p == pe )
		goto _test_eof234;
case 234:
	if ( (*p) == 114 )
		goto st235;
	goto tr301;
st235:
	if ( ++p == pe )
		goto _test_eof235;
case 235:
	if ( (*p) == 105 )
		goto st236;
	goto tr301;
st236:
	if ( ++p == pe )
		goto _test_eof236;
case 236:
	if ( (*p) == 112 )
		goto st237;
	goto tr301;
st237:
	if ( ++p == pe )
		goto _test_eof237;
case 237:
	if ( (*p) == 116 )
		goto st238;
	goto tr301;
st238:
	if ( ++p == pe )
		goto _test_eof238;
case 238:
	if ( (*p) == 105 )
		goto st239;
	goto tr301;
st239:
	if ( ++p == pe )
		goto _test_eof239;
case 239:
	if ( (*p) == 111 )
		goto st240;
	goto tr301;
st240:
	if ( ++p == pe )
		goto _test_eof240;
case 240:
	if ( (*p) == 110 )
		goto st241;
	goto tr301;
st241:
	if ( ++p == pe )
		goto _test_eof241;
case 241:
	if ( (*p) == 61 )
		goto st242;
	goto tr301;
st242:
	if ( ++p == pe )
		goto _test_eof242;
case 242:
	if ( (*p) == 34 )
		goto tr314;
	goto tr301;
tr314:
#line 117 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_key(*this, "Description");
    }
	goto st243;
st243:
	if ( ++p == pe )
		goto _test_eof243;
case 243:
#line 5403 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) > 33 ) {
		if ( 35 <= (*p) && (*p) <= 126 )
			goto tr315;
	} else if ( (*p) >= 32 )
		goto tr315;
	goto tr301;
tr315:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st244;
tr316:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st244;
st244:
	if ( ++p == pe )
		goto _test_eof244;
case 244:
#line 5430 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 34 )
		goto tr317;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr316;
	goto tr301;
tr317:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
	goto st245;
st245:
	if ( ++p == pe )
		goto _test_eof245;
case 245:
#line 5447 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 62 )
		goto st246;
	goto tr301;
st246:
	if ( ++p == pe )
		goto _test_eof246;
case 246:
	if ( (*p) == 10 )
		goto tr51;
	goto tr257;
tr31:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st247;
st247:
	if ( ++p == pe )
		goto _test_eof247;
case 247:
#line 5472 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 95: goto tr37;
		case 115: goto tr320;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto tr36;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr36;
		} else
			goto tr37;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr36;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr36;
		} else
			goto tr37;
	} else
		goto tr37;
	goto tr319;
tr320:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st248;
st248:
	if ( ++p == pe )
		goto _test_eof248;
case 248:
#line 5510 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 95: goto tr37;
		case 115: goto tr321;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto tr36;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr36;
		} else
			goto tr37;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr36;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr36;
		} else
			goto tr37;
	} else
		goto tr37;
	goto tr319;
tr321:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st249;
st249:
	if ( ++p == pe )
		goto _test_eof249;
case 249:
#line 5548 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 95: goto tr37;
		case 101: goto tr322;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto tr36;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr36;
		} else
			goto tr37;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr36;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr36;
		} else
			goto tr37;
	} else
		goto tr37;
	goto tr319;
tr322:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st250;
st250:
	if ( ++p == pe )
		goto _test_eof250;
case 250:
#line 5586 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 95: goto tr37;
		case 109: goto tr323;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto tr36;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr36;
		} else
			goto tr37;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr36;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr36;
		} else
			goto tr37;
	} else
		goto tr37;
	goto tr319;
tr323:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st251;
st251:
	if ( ++p == pe )
		goto _test_eof251;
case 251:
#line 5624 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 95: goto tr37;
		case 98: goto tr324;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto tr36;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr36;
		} else
			goto tr37;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr36;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr36;
		} else
			goto tr37;
	} else
		goto tr37;
	goto tr319;
tr324:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st252;
st252:
	if ( ++p == pe )
		goto _test_eof252;
case 252:
#line 5662 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 95: goto tr37;
		case 108: goto tr325;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto tr36;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr36;
		} else
			goto tr37;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr36;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr36;
		} else
			goto tr37;
	} else
		goto tr37;
	goto tr319;
tr325:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st253;
st253:
	if ( ++p == pe )
		goto _test_eof253;
case 253:
#line 5700 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 95: goto tr37;
		case 121: goto tr326;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto tr36;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr36;
		} else
			goto tr37;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr36;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr36;
		} else
			goto tr37;
	} else
		goto tr37;
	goto tr319;
tr326:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st254;
st254:
	if ( ++p == pe )
		goto _test_eof254;
case 254:
#line 5738 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr327;
		case 95: goto tr37;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto tr36;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr36;
		} else
			goto tr37;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr36;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr36;
		} else
			goto tr37;
	} else
		goto tr37;
	goto tr319;
tr327:
#line 73 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "assembly");
    }
	goto st255;
st255:
	if ( ++p == pe )
		goto _test_eof255;
case 255:
#line 5775 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr329;
	} else if ( (*p) >= 65 )
		goto tr329;
	goto tr328;
tr329:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st256;
st256:
	if ( ++p == pe )
		goto _test_eof256;
case 256:
#line 5792 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr328;
		case 35: goto tr328;
		case 47: goto tr328;
		case 58: goto tr328;
		case 63: goto tr328;
	}
	goto st257;
st257:
	if ( ++p == pe )
		goto _test_eof257;
case 257:
	switch( (*p) ) {
		case 10: goto tr328;
		case 35: goto tr328;
		case 47: goto tr328;
		case 58: goto st258;
		case 63: goto tr328;
	}
	goto st257;
st258:
	if ( ++p == pe )
		goto _test_eof258;
case 258:
	if ( (*p) == 47 )
		goto st259;
	goto tr328;
st259:
	if ( ++p == pe )
		goto _test_eof259;
case 259:
	if ( (*p) == 47 )
		goto st260;
	goto tr328;
st260:
	if ( ++p == pe )
		goto _test_eof260;
case 260:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr334;
	} else if ( (*p) >= 65 )
		goto tr334;
	goto tr328;
tr334:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st261;
st261:
	if ( ++p == pe )
		goto _test_eof261;
case 261:
#line 5847 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 10 )
		goto tr35;
	goto tr334;
tr32:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st262;
st262:
	if ( ++p == pe )
		goto _test_eof262;
case 262:
#line 5865 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 95: goto tr37;
		case 111: goto tr336;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto tr36;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr36;
		} else
			goto tr37;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr36;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr36;
		} else
			goto tr37;
	} else
		goto tr37;
	goto tr335;
tr336:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st263;
st263:
	if ( ++p == pe )
		goto _test_eof263;
case 263:
#line 5903 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 95: goto tr37;
		case 110: goto tr337;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto tr36;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr36;
		} else
			goto tr37;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr36;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr36;
		} else
			goto tr37;
	} else
		goto tr37;
	goto tr335;
tr337:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st264;
st264:
	if ( ++p == pe )
		goto _test_eof264;
case 264:
#line 5941 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 95: goto tr37;
		case 116: goto tr338;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto tr36;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr36;
		} else
			goto tr37;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr36;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr36;
		} else
			goto tr37;
	} else
		goto tr37;
	goto tr335;
tr338:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st265;
st265:
	if ( ++p == pe )
		goto _test_eof265;
case 265:
#line 5979 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 95: goto tr37;
		case 105: goto tr339;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto tr36;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr36;
		} else
			goto tr37;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr36;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr36;
		} else
			goto tr37;
	} else
		goto tr37;
	goto tr335;
tr339:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st266;
st266:
	if ( ++p == pe )
		goto _test_eof266;
case 266:
#line 6017 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 95: goto tr37;
		case 103: goto tr340;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto tr36;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr36;
		} else
			goto tr37;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr36;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr36;
		} else
			goto tr37;
	} else
		goto tr37;
	goto tr335;
tr340:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st267;
st267:
	if ( ++p == pe )
		goto _test_eof267;
case 267:
#line 6055 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr341;
		case 95: goto tr37;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto tr36;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr36;
		} else
			goto tr37;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr36;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr36;
		} else
			goto tr37;
	} else
		goto tr37;
	goto tr335;
tr341:
#line 77 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "contig");
    }
	goto st268;
st268:
	if ( ++p == pe )
		goto _test_eof268;
case 268:
#line 6092 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 60 )
		goto st269;
	goto tr335;
st269:
	if ( ++p == pe )
		goto _test_eof269;
case 269:
	if ( (*p) == 73 )
		goto st270;
	goto tr335;
st270:
	if ( ++p == pe )
		goto _test_eof270;
case 270:
	if ( (*p) == 68 )
		goto st271;
	goto tr335;
st271:
	if ( ++p == pe )
		goto _test_eof271;
case 271:
	if ( (*p) == 61 )
		goto st272;
	goto tr335;
st272:
	if ( ++p == pe )
		goto _test_eof272;
case 272:
	if ( (*p) == 95 )
		goto tr347;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr347;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr348;
		} else if ( (*p) >= 65 )
			goto tr348;
	} else
		goto tr348;
	goto tr346;
tr347:
#line 105 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_key(*this, "ID");
    }
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st273;
st273:
	if ( ++p == pe )
		goto _test_eof273;
case 273:
#line 6149 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 95 )
		goto st273;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st273;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr350;
		} else if ( (*p) >= 65 )
			goto tr350;
	} else
		goto tr350;
	goto tr346;
tr350:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st274;
tr348:
#line 105 "cpp/src/bioformats/vcf/vcf_v41.ragel"
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
	goto st274;
st274:
	if ( ++p == pe )
		goto _test_eof274;
case 274:
#line 6188 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto tr351;
		case 62: goto tr352;
		case 95: goto tr350;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr350;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr350;
		} else if ( (*p) >= 65 )
			goto tr350;
	} else
		goto tr350;
	goto tr346;
tr351:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
	goto st275;
st275:
	if ( ++p == pe )
		goto _test_eof275;
case 275:
#line 6217 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 95 )
		goto tr353;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr353;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr354;
		} else if ( (*p) >= 65 )
			goto tr354;
	} else
		goto tr354;
	goto tr335;
tr353:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st276;
st276:
	if ( ++p == pe )
		goto _test_eof276;
case 276:
#line 6242 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 95 )
		goto st276;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st276;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr356;
		} else if ( (*p) >= 65 )
			goto tr356;
	} else
		goto tr356;
	goto tr335;
tr354:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st277;
tr356:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st277;
st277:
	if ( ++p == pe )
		goto _test_eof277;
case 277:
#line 6277 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 61: goto tr357;
		case 95: goto tr356;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr356;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr356;
		} else if ( (*p) >= 65 )
			goto tr356;
	} else
		goto tr356;
	goto tr335;
tr357:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
	goto st278;
st278:
	if ( ++p == pe )
		goto _test_eof278;
case 278:
#line 6305 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) < 45 ) {
		if ( 32 <= (*p) && (*p) <= 43 )
			goto tr358;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr358;
	} else
		goto tr358;
	goto tr335;
tr358:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st279;
tr359:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st279;
st279:
	if ( ++p == pe )
		goto _test_eof279;
case 279:
#line 6335 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto tr351;
		case 62: goto tr352;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr359;
	goto tr335;
tr352:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
	goto st280;
st280:
	if ( ++p == pe )
		goto _test_eof280;
case 280:
#line 6354 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 10 )
		goto tr51;
	goto tr335;
tr33:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st281;
st281:
	if ( ++p == pe )
		goto _test_eof281;
case 281:
#line 6372 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 95: goto tr37;
		case 101: goto tr361;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto tr36;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr36;
		} else
			goto tr37;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr36;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr36;
		} else
			goto tr37;
	} else
		goto tr37;
	goto tr360;
tr361:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st282;
st282:
	if ( ++p == pe )
		goto _test_eof282;
case 282:
#line 6410 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 95: goto tr37;
		case 100: goto tr362;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto tr36;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr36;
		} else
			goto tr37;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr36;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr36;
		} else
			goto tr37;
	} else
		goto tr37;
	goto tr360;
tr362:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st283;
st283:
	if ( ++p == pe )
		goto _test_eof283;
case 283:
#line 6448 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 95: goto tr37;
		case 105: goto tr363;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto tr36;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr36;
		} else
			goto tr37;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr36;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr36;
		} else
			goto tr37;
	} else
		goto tr37;
	goto tr360;
tr363:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st284;
st284:
	if ( ++p == pe )
		goto _test_eof284;
case 284:
#line 6486 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 95: goto tr37;
		case 103: goto tr364;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto tr36;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr36;
		} else
			goto tr37;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr36;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr36;
		} else
			goto tr37;
	} else
		goto tr37;
	goto tr360;
tr364:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st285;
st285:
	if ( ++p == pe )
		goto _test_eof285;
case 285:
#line 6524 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 95: goto tr37;
		case 114: goto tr365;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto tr36;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr36;
		} else
			goto tr37;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr36;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr36;
		} else
			goto tr37;
	} else
		goto tr37;
	goto tr360;
tr365:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st286;
st286:
	if ( ++p == pe )
		goto _test_eof286;
case 286:
#line 6562 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 95: goto tr37;
		case 101: goto tr366;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto tr36;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr36;
		} else
			goto tr37;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr36;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr36;
		} else
			goto tr37;
	} else
		goto tr37;
	goto tr360;
tr366:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st287;
st287:
	if ( ++p == pe )
		goto _test_eof287;
case 287:
#line 6600 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 95: goto tr37;
		case 101: goto tr367;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto tr36;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr36;
		} else
			goto tr37;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr36;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr36;
		} else
			goto tr37;
	} else
		goto tr37;
	goto tr360;
tr367:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st288;
st288:
	if ( ++p == pe )
		goto _test_eof288;
case 288:
#line 6638 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 68: goto tr368;
		case 95: goto tr37;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto tr36;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr36;
		} else
			goto tr37;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr36;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr36;
		} else
			goto tr37;
	} else
		goto tr37;
	goto tr360;
tr368:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st289;
st289:
	if ( ++p == pe )
		goto _test_eof289;
case 289:
#line 6676 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 66: goto tr369;
		case 95: goto tr37;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto tr36;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr36;
		} else
			goto tr37;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr36;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr36;
		} else
			goto tr37;
	} else
		goto tr37;
	goto tr360;
tr369:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st290;
st290:
	if ( ++p == pe )
		goto _test_eof290;
case 290:
#line 6714 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr370;
		case 95: goto tr37;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto tr36;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr36;
		} else
			goto tr37;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr36;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr36;
		} else
			goto tr37;
	} else
		goto tr37;
	goto tr360;
tr370:
#line 97 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "pedigreeDB");
    }
	goto st291;
st291:
	if ( ++p == pe )
		goto _test_eof291;
case 291:
#line 6751 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 60 )
		goto st292;
	goto tr360;
st292:
	if ( ++p == pe )
		goto _test_eof292;
case 292:
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
	goto st293;
st293:
	if ( ++p == pe )
		goto _test_eof293;
case 293:
#line 6775 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr372;
		case 35: goto tr372;
		case 47: goto tr372;
		case 58: goto tr372;
		case 63: goto tr372;
	}
	goto st294;
st294:
	if ( ++p == pe )
		goto _test_eof294;
case 294:
	switch( (*p) ) {
		case 10: goto tr372;
		case 35: goto tr372;
		case 47: goto tr372;
		case 58: goto st295;
		case 63: goto tr372;
	}
	goto st294;
st295:
	if ( ++p == pe )
		goto _test_eof295;
case 295:
	if ( (*p) == 47 )
		goto st296;
	goto tr372;
st296:
	if ( ++p == pe )
		goto _test_eof296;
case 296:
	if ( (*p) == 47 )
		goto st297;
	goto tr372;
st297:
	if ( ++p == pe )
		goto _test_eof297;
case 297:
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
	goto st298;
st298:
	if ( ++p == pe )
		goto _test_eof298;
case 298:
#line 6830 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr372;
		case 62: goto tr379;
	}
	goto tr378;
tr379:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
	goto st299;
st299:
	if ( ++p == pe )
		goto _test_eof299;
case 299:
#line 6851 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr51;
		case 62: goto tr379;
	}
	goto tr378;
st300:
	if ( ++p == pe )
		goto _test_eof300;
case 300:
	if ( (*p) == 72 )
		goto st301;
	goto tr380;
st301:
	if ( ++p == pe )
		goto _test_eof301;
case 301:
	if ( (*p) == 82 )
		goto st302;
	goto tr380;
st302:
	if ( ++p == pe )
		goto _test_eof302;
case 302:
	if ( (*p) == 79 )
		goto st303;
	goto tr380;
st303:
	if ( ++p == pe )
		goto _test_eof303;
case 303:
	if ( (*p) == 77 )
		goto st304;
	goto tr380;
st304:
	if ( ++p == pe )
		goto _test_eof304;
case 304:
	if ( (*p) == 9 )
		goto st305;
	goto tr380;
st305:
	if ( ++p == pe )
		goto _test_eof305;
case 305:
	if ( (*p) == 80 )
		goto st306;
	goto tr380;
st306:
	if ( ++p == pe )
		goto _test_eof306;
case 306:
	if ( (*p) == 79 )
		goto st307;
	goto tr380;
st307:
	if ( ++p == pe )
		goto _test_eof307;
case 307:
	if ( (*p) == 83 )
		goto st308;
	goto tr380;
st308:
	if ( ++p == pe )
		goto _test_eof308;
case 308:
	if ( (*p) == 9 )
		goto st309;
	goto tr380;
st309:
	if ( ++p == pe )
		goto _test_eof309;
case 309:
	if ( (*p) == 73 )
		goto st310;
	goto tr380;
st310:
	if ( ++p == pe )
		goto _test_eof310;
case 310:
	if ( (*p) == 68 )
		goto st311;
	goto tr380;
st311:
	if ( ++p == pe )
		goto _test_eof311;
case 311:
	if ( (*p) == 9 )
		goto st312;
	goto tr380;
st312:
	if ( ++p == pe )
		goto _test_eof312;
case 312:
	if ( (*p) == 82 )
		goto st313;
	goto tr380;
st313:
	if ( ++p == pe )
		goto _test_eof313;
case 313:
	if ( (*p) == 69 )
		goto st314;
	goto tr380;
st314:
	if ( ++p == pe )
		goto _test_eof314;
case 314:
	if ( (*p) == 70 )
		goto st315;
	goto tr380;
st315:
	if ( ++p == pe )
		goto _test_eof315;
case 315:
	if ( (*p) == 9 )
		goto st316;
	goto tr380;
st316:
	if ( ++p == pe )
		goto _test_eof316;
case 316:
	if ( (*p) == 65 )
		goto st317;
	goto tr380;
st317:
	if ( ++p == pe )
		goto _test_eof317;
case 317:
	if ( (*p) == 76 )
		goto st318;
	goto tr380;
st318:
	if ( ++p == pe )
		goto _test_eof318;
case 318:
	if ( (*p) == 84 )
		goto st319;
	goto tr380;
st319:
	if ( ++p == pe )
		goto _test_eof319;
case 319:
	if ( (*p) == 9 )
		goto st320;
	goto tr380;
st320:
	if ( ++p == pe )
		goto _test_eof320;
case 320:
	if ( (*p) == 81 )
		goto st321;
	goto tr380;
st321:
	if ( ++p == pe )
		goto _test_eof321;
case 321:
	if ( (*p) == 85 )
		goto st322;
	goto tr380;
st322:
	if ( ++p == pe )
		goto _test_eof322;
case 322:
	if ( (*p) == 65 )
		goto st323;
	goto tr380;
st323:
	if ( ++p == pe )
		goto _test_eof323;
case 323:
	if ( (*p) == 76 )
		goto st324;
	goto tr380;
st324:
	if ( ++p == pe )
		goto _test_eof324;
case 324:
	if ( (*p) == 9 )
		goto st325;
	goto tr380;
st325:
	if ( ++p == pe )
		goto _test_eof325;
case 325:
	if ( (*p) == 70 )
		goto st326;
	goto tr380;
st326:
	if ( ++p == pe )
		goto _test_eof326;
case 326:
	if ( (*p) == 73 )
		goto st327;
	goto tr380;
st327:
	if ( ++p == pe )
		goto _test_eof327;
case 327:
	if ( (*p) == 76 )
		goto st328;
	goto tr380;
st328:
	if ( ++p == pe )
		goto _test_eof328;
case 328:
	if ( (*p) == 84 )
		goto st329;
	goto tr380;
st329:
	if ( ++p == pe )
		goto _test_eof329;
case 329:
	if ( (*p) == 69 )
		goto st330;
	goto tr380;
st330:
	if ( ++p == pe )
		goto _test_eof330;
case 330:
	if ( (*p) == 82 )
		goto st331;
	goto tr380;
st331:
	if ( ++p == pe )
		goto _test_eof331;
case 331:
	if ( (*p) == 9 )
		goto st332;
	goto tr380;
st332:
	if ( ++p == pe )
		goto _test_eof332;
case 332:
	if ( (*p) == 73 )
		goto st333;
	goto tr380;
st333:
	if ( ++p == pe )
		goto _test_eof333;
case 333:
	if ( (*p) == 78 )
		goto st334;
	goto tr380;
st334:
	if ( ++p == pe )
		goto _test_eof334;
case 334:
	if ( (*p) == 70 )
		goto st335;
	goto tr380;
st335:
	if ( ++p == pe )
		goto _test_eof335;
case 335:
	if ( (*p) == 79 )
		goto st336;
	goto tr380;
st336:
	if ( ++p == pe )
		goto _test_eof336;
case 336:
	switch( (*p) ) {
		case 9: goto st337;
		case 10: goto tr418;
	}
	goto tr380;
st337:
	if ( ++p == pe )
		goto _test_eof337;
case 337:
	if ( (*p) == 70 )
		goto st338;
	goto tr419;
st338:
	if ( ++p == pe )
		goto _test_eof338;
case 338:
	if ( (*p) == 79 )
		goto st339;
	goto tr419;
st339:
	if ( ++p == pe )
		goto _test_eof339;
case 339:
	if ( (*p) == 82 )
		goto st340;
	goto tr419;
st340:
	if ( ++p == pe )
		goto _test_eof340;
case 340:
	if ( (*p) == 77 )
		goto st341;
	goto tr419;
st341:
	if ( ++p == pe )
		goto _test_eof341;
case 341:
	if ( (*p) == 65 )
		goto st342;
	goto tr419;
st342:
	if ( ++p == pe )
		goto _test_eof342;
case 342:
	if ( (*p) == 84 )
		goto st343;
	goto tr419;
st343:
	if ( ++p == pe )
		goto _test_eof343;
case 343:
	if ( (*p) == 9 )
		goto st344;
	goto tr419;
tr428:
#line 145 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_sample_name(*this);
    }
	goto st344;
st344:
	if ( ++p == pe )
		goto _test_eof344;
case 344:
#line 7177 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr427;
	goto tr419;
tr427:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st345;
tr430:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st345;
st345:
	if ( ++p == pe )
		goto _test_eof345;
case 345:
#line 7201 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr428;
		case 10: goto tr429;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr430;
	goto tr419;
tr418:
#line 149 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_header_line(*this);
    }
#line 28 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;
    }
	goto st555;
tr429:
#line 145 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_sample_name(*this);
    }
#line 149 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_header_line(*this);
    }
#line 28 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;
    }
	goto st555;
st555:
	if ( ++p == pe )
		goto _test_eof555;
case 555:
#line 7241 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 60 )
		goto tr709;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr708;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr708;
	} else
		goto tr708;
	goto tr707;
tr708:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st346;
st346:
	if ( ++p == pe )
		goto _test_eof346;
case 346:
#line 7267 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr432;
		case 59: goto tr433;
		case 61: goto tr433;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr433;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr433;
		} else
			goto tr434;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr433;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr433;
		} else
			goto tr434;
	} else
		goto tr434;
	goto tr431;
tr432:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
#line 34 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
        ++n_columns;
    }
	goto st347;
st347:
	if ( ++p == pe )
		goto _test_eof347;
case 347:
#line 7310 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr436;
	goto tr435;
tr436:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st348;
tr438:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st348;
st348:
	if ( ++p == pe )
		goto _test_eof348;
case 348:
#line 7334 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 9 )
		goto tr437;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr438;
	goto tr435;
tr443:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
	goto st349;
tr437:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
#line 34 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
        ++n_columns;
    }
	goto st349;
st349:
	if ( ++p == pe )
		goto _test_eof349;
case 349:
#line 7363 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr440;
	} else if ( (*p) >= 33 )
		goto tr440;
	goto tr439;
tr440:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st350;
tr442:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st350;
st350:
	if ( ++p == pe )
		goto _test_eof350;
case 350:
#line 7390 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr441;
		case 59: goto tr443;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr442;
	goto tr439;
tr441:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
#line 34 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
        ++n_columns;
    }
	goto st351;
st351:
	if ( ++p == pe )
		goto _test_eof351;
case 351:
#line 7414 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 65: goto tr445;
		case 67: goto tr445;
		case 71: goto tr445;
		case 78: goto tr445;
		case 84: goto tr445;
		case 97: goto tr445;
		case 99: goto tr445;
		case 103: goto tr445;
		case 110: goto tr445;
		case 116: goto tr445;
	}
	goto tr444;
tr445:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st352;
tr447:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st352;
st352:
	if ( ++p == pe )
		goto _test_eof352;
case 352:
#line 7448 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr446;
		case 65: goto tr447;
		case 67: goto tr447;
		case 71: goto tr447;
		case 78: goto tr447;
		case 84: goto tr447;
		case 97: goto tr447;
		case 99: goto tr447;
		case 103: goto tr447;
		case 110: goto tr447;
		case 116: goto tr447;
	}
	goto tr444;
tr446:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
#line 34 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
        ++n_columns;
    }
	goto st353;
st353:
	if ( ++p == pe )
		goto _test_eof353;
case 353:
#line 7479 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 42: goto tr449;
		case 46: goto tr450;
		case 60: goto tr451;
		case 65: goto tr452;
		case 67: goto tr452;
		case 71: goto tr452;
		case 78: goto tr452;
		case 84: goto tr452;
		case 91: goto tr453;
		case 93: goto tr454;
		case 97: goto tr452;
		case 99: goto tr452;
		case 103: goto tr452;
		case 110: goto tr452;
		case 116: goto tr452;
	}
	goto tr448;
tr449:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st354;
tr640:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st354;
tr637:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st354;
st354:
	if ( ++p == pe )
		goto _test_eof354;
case 354:
#line 7529 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr455;
		case 44: goto tr456;
	}
	goto tr448;
tr455:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
#line 34 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
        ++n_columns;
    }
	goto st355;
tr702:
#line 34 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
        ++n_columns;
    }
	goto st355;
st355:
	if ( ++p == pe )
		goto _test_eof355;
case 355:
#line 7558 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 46 )
		goto tr458;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr459;
	goto tr457;
tr458:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st356;
st356:
	if ( ++p == pe )
		goto _test_eof356;
case 356:
#line 7578 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 9 )
		goto tr460;
	goto tr457;
tr460:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
#line 34 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
        ++n_columns;
    }
	goto st357;
st357:
	if ( ++p == pe )
		goto _test_eof357;
case 357:
#line 7598 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 46: goto tr463;
		case 58: goto tr462;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr462;
		} else if ( (*p) > 57 ) {
			if ( 60 <= (*p) && (*p) <= 64 )
				goto tr462;
		} else
			goto tr464;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr462;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr462;
		} else
			goto tr464;
	} else
		goto tr464;
	goto tr461;
tr462:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st358;
st358:
	if ( ++p == pe )
		goto _test_eof358;
case 358:
#line 7634 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 58 )
		goto st358;
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto st358;
		} else if ( (*p) > 57 ) {
			if ( 60 <= (*p) && (*p) <= 64 )
				goto st358;
		} else
			goto tr466;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st358;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st358;
		} else
			goto tr466;
	} else
		goto tr466;
	goto tr461;
tr464:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st359;
tr466:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st359;
st359:
	if ( ++p == pe )
		goto _test_eof359;
case 359:
#line 7678 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr467;
		case 59: goto tr468;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr466;
	goto tr461;
tr467:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
#line 34 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
        ++n_columns;
    }
	goto st360;
st360:
	if ( ++p == pe )
		goto _test_eof360;
case 360:
#line 7702 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 46: goto tr471;
		case 49: goto tr473;
		case 58: goto tr470;
		case 60: goto tr470;
		case 65: goto tr474;
		case 66: goto tr475;
		case 67: goto tr476;
		case 68: goto tr477;
		case 69: goto tr478;
		case 72: goto tr479;
		case 77: goto tr480;
		case 78: goto tr481;
		case 83: goto tr482;
		case 86: goto tr483;
	}
	if ( (*p) < 70 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr470;
		} else if ( (*p) > 57 ) {
			if ( 62 <= (*p) && (*p) <= 64 )
				goto tr470;
		} else
			goto tr472;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr470;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr470;
		} else
			goto tr472;
	} else
		goto tr472;
	goto tr469;
tr470:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st361;
st361:
	if ( ++p == pe )
		goto _test_eof361;
case 361:
#line 7750 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 58: goto st361;
		case 60: goto st361;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto st361;
		} else if ( (*p) > 57 ) {
			if ( 62 <= (*p) && (*p) <= 64 )
				goto st361;
		} else
			goto tr485;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st361;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st361;
		} else
			goto tr485;
	} else
		goto tr485;
	goto tr469;
tr472:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st362;
tr485:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st362;
st362:
	if ( ++p == pe )
		goto _test_eof362;
case 362:
#line 7796 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr486;
		case 10: goto tr487;
		case 59: goto st375;
		case 61: goto st380;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr485;
	goto tr469;
tr494:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
	goto st363;
tr486:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
#line 34 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
        ++n_columns;
    }
	goto st363;
st363:
	if ( ++p == pe )
		goto _test_eof363;
case 363:
#line 7829 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr491;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr491;
	} else
		goto tr491;
	goto tr490;
tr491:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st364;
tr493:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st364;
st364:
	if ( ++p == pe )
		goto _test_eof364;
case 364:
#line 7859 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr492;
		case 58: goto tr494;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr493;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr493;
	} else
		goto tr493;
	goto tr490;
tr492:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
#line 34 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_column_end(*this, n_columns);
        ++n_columns;
    }
	goto st365;
st365:
	if ( ++p == pe )
		goto _test_eof365;
case 365:
#line 7889 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 46 )
		goto tr496;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr496;
	goto tr495;
tr496:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st366;
tr503:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st366;
st366:
	if ( ++p == pe )
		goto _test_eof366;
case 366:
#line 7915 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr492;
		case 10: goto tr487;
		case 47: goto tr497;
		case 58: goto tr498;
		case 124: goto tr497;
	}
	goto tr495;
tr487:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
#line 156 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        std::cout << "Finished reading record" << std::endl;
        ParsePolicy::handle_body_line(*this);
    }
#line 28 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;
    }
	goto st556;
st556:
	if ( ++p == pe )
		goto _test_eof556;
case 556:
#line 7946 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 60 )
		goto tr709;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr708;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr708;
	} else
		goto tr708;
	goto tr431;
tr709:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st367;
st367:
	if ( ++p == pe )
		goto _test_eof367;
case 367:
#line 7972 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr499;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr499;
	} else
		goto tr499;
	goto tr431;
tr499:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st368;
st368:
	if ( ++p == pe )
		goto _test_eof368;
case 368:
#line 7992 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr500;
		case 62: goto tr502;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr500;
		} else if ( (*p) > 57 ) {
			if ( 61 <= (*p) && (*p) <= 64 )
				goto tr500;
		} else
			goto tr501;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr500;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr500;
		} else
			goto tr501;
	} else
		goto tr501;
	goto tr431;
tr500:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st369;
st369:
	if ( ++p == pe )
		goto _test_eof369;
case 369:
#line 8028 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr500;
		case 61: goto tr500;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr500;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr500;
		} else
			goto tr501;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr500;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr500;
		} else
			goto tr501;
	} else
		goto tr501;
	goto tr431;
tr501:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st370;
st370:
	if ( ++p == pe )
		goto _test_eof370;
case 370:
#line 8064 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr501;
		case 62: goto tr502;
	}
	if ( (*p) > 57 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr501;
	} else if ( (*p) >= 33 )
		goto tr501;
	goto tr431;
tr502:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st371;
st371:
	if ( ++p == pe )
		goto _test_eof371;
case 371:
#line 8085 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 9 )
		goto tr432;
	goto tr431;
tr497:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st372;
st372:
	if ( ++p == pe )
		goto _test_eof372;
case 372:
#line 8099 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 46 )
		goto tr503;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr503;
	goto tr495;
tr498:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st373;
st373:
	if ( ++p == pe )
		goto _test_eof373;
case 373:
#line 8115 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) > 57 ) {
		if ( 59 <= (*p) && (*p) <= 126 )
			goto tr505;
	} else if ( (*p) >= 33 )
		goto tr505;
	goto tr504;
tr505:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st374;
st374:
	if ( ++p == pe )
		goto _test_eof374;
case 374:
#line 8132 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr492;
		case 10: goto tr487;
		case 58: goto tr498;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr505;
	goto tr504;
st375:
	if ( ++p == pe )
		goto _test_eof375;
case 375:
	switch( (*p) ) {
		case 49: goto tr506;
		case 58: goto st361;
		case 60: goto st361;
		case 65: goto tr507;
		case 66: goto tr508;
		case 67: goto tr509;
		case 68: goto tr510;
		case 69: goto tr511;
		case 72: goto tr512;
		case 77: goto tr513;
		case 78: goto tr514;
		case 83: goto tr515;
		case 86: goto tr516;
	}
	if ( (*p) < 70 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto st361;
		} else if ( (*p) > 57 ) {
			if ( 62 <= (*p) && (*p) <= 64 )
				goto st361;
		} else
			goto tr485;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st361;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st361;
		} else
			goto tr485;
	} else
		goto tr485;
	goto tr469;
tr473:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st376;
tr506:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st376;
st376:
	if ( ++p == pe )
		goto _test_eof376;
case 376:
#line 8201 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr486;
		case 10: goto tr487;
		case 48: goto tr517;
		case 59: goto st375;
		case 61: goto st380;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr485;
	goto tr469;
tr517:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st377;
st377:
	if ( ++p == pe )
		goto _test_eof377;
case 377:
#line 8222 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr486;
		case 10: goto tr487;
		case 48: goto tr518;
		case 59: goto st375;
		case 61: goto st380;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr485;
	goto tr469;
tr518:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st378;
st378:
	if ( ++p == pe )
		goto _test_eof378;
case 378:
#line 8243 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr486;
		case 10: goto tr487;
		case 48: goto tr519;
		case 59: goto st375;
		case 61: goto st380;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr485;
	goto tr469;
tr519:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st379;
st379:
	if ( ++p == pe )
		goto _test_eof379;
case 379:
#line 8264 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr486;
		case 10: goto tr487;
		case 59: goto st375;
		case 61: goto st380;
		case 71: goto tr520;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr485;
	goto tr469;
st380:
	if ( ++p == pe )
		goto _test_eof380;
case 380:
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr522;
	} else if ( (*p) >= 33 )
		goto tr522;
	goto tr521;
tr522:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st381;
st381:
	if ( ++p == pe )
		goto _test_eof381;
case 381:
#line 8295 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr486;
		case 10: goto tr487;
		case 59: goto st375;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr522;
	goto tr521;
tr520:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st382;
st382:
	if ( ++p == pe )
		goto _test_eof382;
case 382:
#line 8314 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr486;
		case 10: goto tr487;
		case 59: goto st375;
		case 61: goto st383;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr485;
	goto tr523;
st383:
	if ( ++p == pe )
		goto _test_eof383;
case 383:
	if ( 48 <= (*p) && (*p) <= 49 )
		goto tr526;
	goto tr525;
tr526:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st384;
st384:
	if ( ++p == pe )
		goto _test_eof384;
case 384:
#line 8341 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr486;
		case 10: goto tr487;
		case 59: goto st375;
	}
	goto tr525;
tr474:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st385;
tr507:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st385;
st385:
	if ( ++p == pe )
		goto _test_eof385;
case 385:
#line 8368 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr486;
		case 10: goto tr487;
		case 59: goto st375;
		case 61: goto st380;
		case 65: goto st386;
		case 67: goto st390;
		case 70: goto st393;
		case 78: goto st398;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr485;
	goto tr469;
st386:
	if ( ++p == pe )
		goto _test_eof386;
case 386:
	if ( (*p) == 61 )
		goto st387;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr485;
	} else if ( (*p) >= 33 )
		goto tr485;
	goto tr469;
st387:
	if ( ++p == pe )
		goto _test_eof387;
case 387:
	switch( (*p) ) {
		case 46: goto tr533;
		case 65: goto tr534;
		case 67: goto tr534;
		case 71: goto tr534;
		case 78: goto tr534;
		case 84: goto tr534;
		case 97: goto tr534;
		case 99: goto tr534;
		case 103: goto tr534;
		case 110: goto tr534;
		case 116: goto tr534;
	}
	goto tr532;
tr533:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st388;
st388:
	if ( ++p == pe )
		goto _test_eof388;
case 388:
#line 8422 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr486;
		case 10: goto tr487;
		case 59: goto st375;
	}
	goto tr532;
tr534:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st389;
st389:
	if ( ++p == pe )
		goto _test_eof389;
case 389:
#line 8439 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr486;
		case 10: goto tr487;
		case 59: goto st375;
		case 65: goto tr534;
		case 67: goto tr534;
		case 71: goto tr534;
		case 78: goto tr534;
		case 84: goto tr534;
		case 97: goto tr534;
		case 99: goto tr534;
		case 103: goto tr534;
		case 110: goto tr534;
		case 116: goto tr534;
	}
	goto tr532;
st390:
	if ( ++p == pe )
		goto _test_eof390;
case 390:
	if ( (*p) == 61 )
		goto st391;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr485;
	} else if ( (*p) >= 33 )
		goto tr485;
	goto tr469;
st391:
	if ( ++p == pe )
		goto _test_eof391;
case 391:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr537;
	goto tr536;
tr537:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st392;
st392:
	if ( ++p == pe )
		goto _test_eof392;
case 392:
#line 8485 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr486;
		case 10: goto tr487;
		case 44: goto st391;
		case 59: goto st375;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr537;
	goto tr536;
st393:
	if ( ++p == pe )
		goto _test_eof393;
case 393:
	if ( (*p) == 61 )
		goto st394;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr485;
	} else if ( (*p) >= 33 )
		goto tr485;
	goto tr469;
st394:
	if ( ++p == pe )
		goto _test_eof394;
case 394:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr540;
	goto tr539;
tr540:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st395;
st395:
	if ( ++p == pe )
		goto _test_eof395;
case 395:
#line 8524 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr486;
		case 10: goto tr487;
		case 44: goto st394;
		case 46: goto st396;
		case 59: goto st375;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr540;
	goto tr539;
st396:
	if ( ++p == pe )
		goto _test_eof396;
case 396:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr542;
	goto tr539;
tr542:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st397;
st397:
	if ( ++p == pe )
		goto _test_eof397;
case 397:
#line 8552 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr486;
		case 10: goto tr487;
		case 44: goto st394;
		case 59: goto st375;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr542;
	goto tr539;
st398:
	if ( ++p == pe )
		goto _test_eof398;
case 398:
	if ( (*p) == 61 )
		goto st399;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr485;
	} else if ( (*p) >= 33 )
		goto tr485;
	goto tr469;
st399:
	if ( ++p == pe )
		goto _test_eof399;
case 399:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr545;
	goto tr544;
tr545:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st400;
st400:
	if ( ++p == pe )
		goto _test_eof400;
case 400:
#line 8591 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr486;
		case 10: goto tr487;
		case 59: goto st375;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr545;
	goto tr544;
tr475:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st401;
tr508:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st401;
st401:
	if ( ++p == pe )
		goto _test_eof401;
case 401:
#line 8620 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr486;
		case 10: goto tr487;
		case 59: goto st375;
		case 61: goto st380;
		case 81: goto st402;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr485;
	goto tr469;
st402:
	if ( ++p == pe )
		goto _test_eof402;
case 402:
	if ( (*p) == 61 )
		goto st403;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr485;
	} else if ( (*p) >= 33 )
		goto tr485;
	goto tr469;
st403:
	if ( ++p == pe )
		goto _test_eof403;
case 403:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr549;
	goto tr548;
tr549:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st404;
st404:
	if ( ++p == pe )
		goto _test_eof404;
case 404:
#line 8660 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr486;
		case 10: goto tr487;
		case 46: goto st405;
		case 59: goto st375;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr549;
	goto tr548;
st405:
	if ( ++p == pe )
		goto _test_eof405;
case 405:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr551;
	goto tr548;
tr551:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st406;
st406:
	if ( ++p == pe )
		goto _test_eof406;
case 406:
#line 8687 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr486;
		case 10: goto tr487;
		case 59: goto st375;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr551;
	goto tr548;
tr476:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st407;
tr509:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st407;
st407:
	if ( ++p == pe )
		goto _test_eof407;
case 407:
#line 8716 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr486;
		case 10: goto tr487;
		case 59: goto st375;
		case 61: goto st380;
		case 73: goto tr552;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr485;
	goto tr469;
tr552:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st408;
st408:
	if ( ++p == pe )
		goto _test_eof408;
case 408:
#line 8737 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr486;
		case 10: goto tr487;
		case 59: goto st375;
		case 61: goto st380;
		case 71: goto tr553;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr485;
	goto tr469;
tr553:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st409;
st409:
	if ( ++p == pe )
		goto _test_eof409;
case 409:
#line 8758 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr486;
		case 10: goto tr487;
		case 59: goto st375;
		case 61: goto st380;
		case 65: goto tr554;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr485;
	goto tr469;
tr554:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st410;
st410:
	if ( ++p == pe )
		goto _test_eof410;
case 410:
#line 8779 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr486;
		case 10: goto tr487;
		case 59: goto st375;
		case 61: goto st380;
		case 82: goto st411;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr485;
	goto tr469;
st411:
	if ( ++p == pe )
		goto _test_eof411;
case 411:
	if ( (*p) == 61 )
		goto st412;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr485;
	} else if ( (*p) >= 33 )
		goto tr485;
	goto tr469;
st412:
	if ( ++p == pe )
		goto _test_eof412;
case 412:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr558;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr558;
	} else
		goto tr558;
	goto tr557;
tr558:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st413;
st413:
	if ( ++p == pe )
		goto _test_eof413;
case 413:
#line 8825 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr486;
		case 10: goto tr487;
		case 59: goto st375;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr558;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr558;
	} else
		goto tr558;
	goto tr557;
tr477:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st414;
tr510:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st414;
st414:
	if ( ++p == pe )
		goto _test_eof414;
case 414:
#line 8860 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr486;
		case 10: goto tr487;
		case 59: goto st375;
		case 61: goto st380;
		case 66: goto tr559;
		case 80: goto st418;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr485;
	goto tr469;
tr559:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st415;
st415:
	if ( ++p == pe )
		goto _test_eof415;
case 415:
#line 8882 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr486;
		case 10: goto tr487;
		case 59: goto st375;
		case 61: goto st416;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr485;
	goto tr561;
st416:
	if ( ++p == pe )
		goto _test_eof416;
case 416:
	if ( 48 <= (*p) && (*p) <= 49 )
		goto tr564;
	goto tr563;
tr564:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st417;
st417:
	if ( ++p == pe )
		goto _test_eof417;
case 417:
#line 8909 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr486;
		case 10: goto tr487;
		case 59: goto st375;
	}
	goto tr563;
st418:
	if ( ++p == pe )
		goto _test_eof418;
case 418:
	if ( (*p) == 61 )
		goto st419;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr485;
	} else if ( (*p) >= 33 )
		goto tr485;
	goto tr469;
st419:
	if ( ++p == pe )
		goto _test_eof419;
case 419:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr567;
	goto tr566;
tr567:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st420;
st420:
	if ( ++p == pe )
		goto _test_eof420;
case 420:
#line 8945 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr486;
		case 10: goto tr487;
		case 59: goto st375;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr567;
	goto tr566;
tr478:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st421;
tr511:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st421;
st421:
	if ( ++p == pe )
		goto _test_eof421;
case 421:
#line 8974 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr486;
		case 10: goto tr487;
		case 59: goto st375;
		case 61: goto st380;
		case 78: goto tr568;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr485;
	goto tr469;
tr568:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st422;
st422:
	if ( ++p == pe )
		goto _test_eof422;
case 422:
#line 8995 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr486;
		case 10: goto tr487;
		case 59: goto st375;
		case 61: goto st380;
		case 68: goto st423;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr485;
	goto tr469;
st423:
	if ( ++p == pe )
		goto _test_eof423;
case 423:
	if ( (*p) == 61 )
		goto st424;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr485;
	} else if ( (*p) >= 33 )
		goto tr485;
	goto tr469;
st424:
	if ( ++p == pe )
		goto _test_eof424;
case 424:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr572;
	goto tr571;
tr572:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st425;
st425:
	if ( ++p == pe )
		goto _test_eof425;
case 425:
#line 9035 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr486;
		case 10: goto tr487;
		case 59: goto st375;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr572;
	goto tr571;
tr479:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st426;
tr512:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st426;
st426:
	if ( ++p == pe )
		goto _test_eof426;
case 426:
#line 9064 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr486;
		case 10: goto tr487;
		case 50: goto tr573;
		case 51: goto tr574;
		case 59: goto st375;
		case 61: goto st380;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr485;
	goto tr469;
tr573:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st427;
st427:
	if ( ++p == pe )
		goto _test_eof427;
case 427:
#line 9086 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr486;
		case 10: goto tr487;
		case 59: goto st375;
		case 61: goto st428;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr485;
	goto tr575;
st428:
	if ( ++p == pe )
		goto _test_eof428;
case 428:
	if ( 48 <= (*p) && (*p) <= 49 )
		goto tr578;
	goto tr577;
tr578:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st429;
st429:
	if ( ++p == pe )
		goto _test_eof429;
case 429:
#line 9113 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr486;
		case 10: goto tr487;
		case 59: goto st375;
	}
	goto tr577;
tr574:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st430;
st430:
	if ( ++p == pe )
		goto _test_eof430;
case 430:
#line 9130 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr486;
		case 10: goto tr487;
		case 59: goto st375;
		case 61: goto st431;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr485;
	goto tr579;
st431:
	if ( ++p == pe )
		goto _test_eof431;
case 431:
	if ( 48 <= (*p) && (*p) <= 49 )
		goto tr582;
	goto tr581;
tr582:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st432;
st432:
	if ( ++p == pe )
		goto _test_eof432;
case 432:
#line 9157 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr486;
		case 10: goto tr487;
		case 59: goto st375;
	}
	goto tr581;
tr480:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st433;
tr513:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st433;
st433:
	if ( ++p == pe )
		goto _test_eof433;
case 433:
#line 9184 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr486;
		case 10: goto tr487;
		case 59: goto st375;
		case 61: goto st380;
		case 81: goto st434;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr485;
	goto tr469;
st434:
	if ( ++p == pe )
		goto _test_eof434;
case 434:
	switch( (*p) ) {
		case 48: goto st435;
		case 61: goto st438;
	}
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr485;
	} else if ( (*p) >= 33 )
		goto tr485;
	goto tr469;
st435:
	if ( ++p == pe )
		goto _test_eof435;
case 435:
	if ( (*p) == 61 )
		goto st436;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr485;
	} else if ( (*p) >= 33 )
		goto tr485;
	goto tr469;
st436:
	if ( ++p == pe )
		goto _test_eof436;
case 436:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr588;
	goto tr587;
tr588:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st437;
st437:
	if ( ++p == pe )
		goto _test_eof437;
case 437:
#line 9238 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr486;
		case 10: goto tr487;
		case 59: goto st375;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr588;
	goto tr587;
st438:
	if ( ++p == pe )
		goto _test_eof438;
case 438:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr590;
	goto tr589;
tr590:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st439;
st439:
	if ( ++p == pe )
		goto _test_eof439;
case 439:
#line 9264 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr486;
		case 10: goto tr487;
		case 46: goto st440;
		case 59: goto st375;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr590;
	goto tr589;
st440:
	if ( ++p == pe )
		goto _test_eof440;
case 440:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr592;
	goto tr589;
tr592:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st441;
st441:
	if ( ++p == pe )
		goto _test_eof441;
case 441:
#line 9291 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr486;
		case 10: goto tr487;
		case 59: goto st375;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr592;
	goto tr589;
tr481:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st442;
tr514:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st442;
st442:
	if ( ++p == pe )
		goto _test_eof442;
case 442:
#line 9320 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr486;
		case 10: goto tr487;
		case 59: goto st375;
		case 61: goto st380;
		case 83: goto st443;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr485;
	goto tr469;
st443:
	if ( ++p == pe )
		goto _test_eof443;
case 443:
	if ( (*p) == 61 )
		goto st444;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr485;
	} else if ( (*p) >= 33 )
		goto tr485;
	goto tr469;
st444:
	if ( ++p == pe )
		goto _test_eof444;
case 444:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr596;
	goto tr595;
tr596:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st445;
st445:
	if ( ++p == pe )
		goto _test_eof445;
case 445:
#line 9360 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr486;
		case 10: goto tr487;
		case 59: goto st375;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr596;
	goto tr595;
tr482:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st446;
tr515:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st446;
st446:
	if ( ++p == pe )
		goto _test_eof446;
case 446:
#line 9389 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr486;
		case 10: goto tr487;
		case 59: goto st375;
		case 61: goto st380;
		case 66: goto st447;
		case 79: goto tr598;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr485;
	goto tr469;
st447:
	if ( ++p == pe )
		goto _test_eof447;
case 447:
	if ( (*p) == 61 )
		goto st448;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr485;
	} else if ( (*p) >= 33 )
		goto tr485;
	goto tr469;
st448:
	if ( ++p == pe )
		goto _test_eof448;
case 448:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr601;
	goto tr600;
tr601:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st449;
st449:
	if ( ++p == pe )
		goto _test_eof449;
case 449:
#line 9430 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr486;
		case 10: goto tr487;
		case 46: goto st450;
		case 59: goto st375;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr601;
	goto tr600;
st450:
	if ( ++p == pe )
		goto _test_eof450;
case 450:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr603;
	goto tr600;
tr603:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st451;
st451:
	if ( ++p == pe )
		goto _test_eof451;
case 451:
#line 9457 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr486;
		case 10: goto tr487;
		case 59: goto st375;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr603;
	goto tr600;
tr598:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st452;
st452:
	if ( ++p == pe )
		goto _test_eof452;
case 452:
#line 9476 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr486;
		case 10: goto tr487;
		case 59: goto st375;
		case 61: goto st380;
		case 77: goto tr604;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr485;
	goto tr469;
tr604:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st453;
st453:
	if ( ++p == pe )
		goto _test_eof453;
case 453:
#line 9497 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr486;
		case 10: goto tr487;
		case 59: goto st375;
		case 61: goto st380;
		case 65: goto tr605;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr485;
	goto tr469;
tr605:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st454;
st454:
	if ( ++p == pe )
		goto _test_eof454;
case 454:
#line 9518 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr486;
		case 10: goto tr487;
		case 59: goto st375;
		case 61: goto st380;
		case 84: goto tr606;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr485;
	goto tr469;
tr606:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st455;
st455:
	if ( ++p == pe )
		goto _test_eof455;
case 455:
#line 9539 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr486;
		case 10: goto tr487;
		case 59: goto st375;
		case 61: goto st380;
		case 73: goto tr607;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr485;
	goto tr469;
tr607:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st456;
st456:
	if ( ++p == pe )
		goto _test_eof456;
case 456:
#line 9560 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr486;
		case 10: goto tr487;
		case 59: goto st375;
		case 61: goto st380;
		case 67: goto tr608;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr485;
	goto tr469;
tr608:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st457;
st457:
	if ( ++p == pe )
		goto _test_eof457;
case 457:
#line 9581 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr486;
		case 10: goto tr487;
		case 59: goto st375;
		case 61: goto st458;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr485;
	goto tr609;
st458:
	if ( ++p == pe )
		goto _test_eof458;
case 458:
	if ( 48 <= (*p) && (*p) <= 49 )
		goto tr612;
	goto tr611;
tr612:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st459;
st459:
	if ( ++p == pe )
		goto _test_eof459;
case 459:
#line 9608 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr486;
		case 10: goto tr487;
		case 59: goto st375;
	}
	goto tr611;
tr483:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st460;
tr516:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st460;
st460:
	if ( ++p == pe )
		goto _test_eof460;
case 460:
#line 9635 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr486;
		case 10: goto tr487;
		case 59: goto st375;
		case 61: goto st380;
		case 65: goto tr613;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr485;
	goto tr469;
tr613:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st461;
st461:
	if ( ++p == pe )
		goto _test_eof461;
case 461:
#line 9656 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr486;
		case 10: goto tr487;
		case 59: goto st375;
		case 61: goto st380;
		case 76: goto tr614;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr485;
	goto tr469;
tr614:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st462;
st462:
	if ( ++p == pe )
		goto _test_eof462;
case 462:
#line 9677 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr486;
		case 10: goto tr487;
		case 59: goto st375;
		case 61: goto st380;
		case 73: goto tr615;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr485;
	goto tr469;
tr615:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st463;
st463:
	if ( ++p == pe )
		goto _test_eof463;
case 463:
#line 9698 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr486;
		case 10: goto tr487;
		case 59: goto st375;
		case 61: goto st380;
		case 68: goto tr616;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr485;
	goto tr469;
tr616:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st464;
st464:
	if ( ++p == pe )
		goto _test_eof464;
case 464:
#line 9719 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr486;
		case 10: goto tr487;
		case 59: goto st375;
		case 61: goto st380;
		case 65: goto tr617;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr485;
	goto tr469;
tr617:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st465;
st465:
	if ( ++p == pe )
		goto _test_eof465;
case 465:
#line 9740 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr486;
		case 10: goto tr487;
		case 59: goto st375;
		case 61: goto st380;
		case 84: goto tr618;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr485;
	goto tr469;
tr618:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st466;
st466:
	if ( ++p == pe )
		goto _test_eof466;
case 466:
#line 9761 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr486;
		case 10: goto tr487;
		case 59: goto st375;
		case 61: goto st380;
		case 69: goto tr619;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr485;
	goto tr469;
tr619:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st467;
st467:
	if ( ++p == pe )
		goto _test_eof467;
case 467:
#line 9782 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr486;
		case 10: goto tr487;
		case 59: goto st375;
		case 61: goto st380;
		case 68: goto tr620;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr485;
	goto tr469;
tr620:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st468;
st468:
	if ( ++p == pe )
		goto _test_eof468;
case 468:
#line 9803 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr486;
		case 10: goto tr487;
		case 59: goto st375;
		case 61: goto st469;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr485;
	goto tr621;
st469:
	if ( ++p == pe )
		goto _test_eof469;
case 469:
	if ( 48 <= (*p) && (*p) <= 49 )
		goto tr624;
	goto tr623;
tr624:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st470;
st470:
	if ( ++p == pe )
		goto _test_eof470;
case 470:
#line 9830 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr486;
		case 10: goto tr487;
		case 59: goto st375;
	}
	goto tr623;
tr471:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st471;
st471:
	if ( ++p == pe )
		goto _test_eof471;
case 471:
#line 9851 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr486;
		case 10: goto tr487;
		case 58: goto st361;
		case 60: goto st361;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto st361;
		} else if ( (*p) > 57 ) {
			if ( 62 <= (*p) && (*p) <= 64 )
				goto st361;
		} else
			goto tr485;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st361;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st361;
		} else
			goto tr485;
	} else
		goto tr485;
	goto tr469;
tr468:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
	goto st472;
st472:
	if ( ++p == pe )
		goto _test_eof472;
case 472:
#line 9890 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 58 )
		goto tr462;
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr462;
		} else if ( (*p) > 57 ) {
			if ( 60 <= (*p) && (*p) <= 64 )
				goto tr462;
		} else
			goto tr464;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr462;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr462;
		} else
			goto tr464;
	} else
		goto tr464;
	goto tr461;
tr463:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st473;
st473:
	if ( ++p == pe )
		goto _test_eof473;
case 473:
#line 9928 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr467;
		case 58: goto st358;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto st358;
		} else if ( (*p) > 57 ) {
			if ( 60 <= (*p) && (*p) <= 64 )
				goto st358;
		} else
			goto tr466;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st358;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st358;
		} else
			goto tr466;
	} else
		goto tr466;
	goto tr461;
tr459:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st474;
tr626:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st474;
st474:
	if ( ++p == pe )
		goto _test_eof474;
case 474:
#line 9974 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr460;
		case 46: goto tr625;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr626;
	goto tr457;
tr625:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st475;
st475:
	if ( ++p == pe )
		goto _test_eof475;
case 475:
#line 9992 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr627;
	goto tr457;
tr627:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st476;
st476:
	if ( ++p == pe )
		goto _test_eof476;
case 476:
#line 10006 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 9 )
		goto tr460;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr627;
	goto tr457;
tr456:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
	goto st477;
st477:
	if ( ++p == pe )
		goto _test_eof477;
case 477:
#line 10023 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 42: goto tr449;
		case 46: goto tr628;
		case 60: goto tr451;
		case 65: goto tr452;
		case 67: goto tr452;
		case 71: goto tr452;
		case 78: goto tr452;
		case 84: goto tr452;
		case 91: goto tr453;
		case 93: goto tr454;
		case 97: goto tr452;
		case 99: goto tr452;
		case 103: goto tr452;
		case 110: goto tr452;
		case 116: goto tr452;
	}
	goto tr448;
tr628:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st478;
tr687:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st478;
st478:
	if ( ++p == pe )
		goto _test_eof478;
case 478:
#line 10062 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 65: goto tr629;
		case 67: goto tr629;
		case 71: goto tr629;
		case 78: goto tr629;
		case 84: goto tr629;
		case 97: goto tr629;
		case 99: goto tr629;
		case 103: goto tr629;
		case 110: goto tr629;
		case 116: goto tr629;
	}
	goto tr448;
tr629:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st479;
st479:
	if ( ++p == pe )
		goto _test_eof479;
case 479:
#line 10086 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr455;
		case 44: goto tr456;
		case 65: goto tr629;
		case 67: goto tr629;
		case 71: goto tr629;
		case 78: goto tr629;
		case 84: goto tr629;
		case 97: goto tr629;
		case 99: goto tr629;
		case 103: goto tr629;
		case 110: goto tr629;
		case 116: goto tr629;
	}
	goto tr448;
tr451:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st480;
st480:
	if ( ++p == pe )
		goto _test_eof480;
case 480:
#line 10116 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 67: goto tr632;
		case 68: goto tr633;
		case 73: goto tr634;
		case 95: goto tr630;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr630;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr631;
		} else if ( (*p) >= 65 )
			goto tr631;
	} else
		goto tr631;
	goto tr448;
tr630:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st481;
tr635:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st481;
st481:
	if ( ++p == pe )
		goto _test_eof481;
case 481:
#line 10155 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 95 )
		goto tr635;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr635;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr636;
		} else if ( (*p) >= 65 )
			goto tr636;
	} else
		goto tr636;
	goto tr448;
tr631:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st482;
tr636:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st482;
st482:
	if ( ++p == pe )
		goto _test_eof482;
case 482:
#line 10190 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 62: goto tr637;
		case 95: goto tr636;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr636;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr636;
		} else if ( (*p) >= 65 )
			goto tr636;
	} else
		goto tr636;
	goto tr448;
tr632:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st483;
st483:
	if ( ++p == pe )
		goto _test_eof483;
case 483:
#line 10221 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 62: goto tr637;
		case 78: goto tr638;
		case 95: goto tr636;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr636;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr636;
		} else if ( (*p) >= 65 )
			goto tr636;
	} else
		goto tr636;
	goto tr448;
tr638:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st484;
st484:
	if ( ++p == pe )
		goto _test_eof484;
case 484:
#line 10249 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 62: goto tr637;
		case 86: goto tr639;
		case 95: goto tr636;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr636;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr636;
		} else if ( (*p) >= 65 )
			goto tr636;
	} else
		goto tr636;
	goto tr448;
tr639:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st485;
st485:
	if ( ++p == pe )
		goto _test_eof485;
case 485:
#line 10277 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 62: goto tr640;
		case 95: goto tr636;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr636;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr636;
		} else if ( (*p) >= 65 )
			goto tr636;
	} else
		goto tr636;
	goto tr448;
tr633:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st486;
st486:
	if ( ++p == pe )
		goto _test_eof486;
case 486:
#line 10308 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 62: goto tr637;
		case 69: goto tr641;
		case 85: goto tr642;
		case 95: goto tr636;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr636;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr636;
		} else if ( (*p) >= 65 )
			goto tr636;
	} else
		goto tr636;
	goto tr448;
tr641:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st487;
st487:
	if ( ++p == pe )
		goto _test_eof487;
case 487:
#line 10337 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 62: goto tr637;
		case 76: goto tr643;
		case 95: goto tr636;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr636;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr636;
		} else if ( (*p) >= 65 )
			goto tr636;
	} else
		goto tr636;
	goto tr448;
tr643:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st488;
st488:
	if ( ++p == pe )
		goto _test_eof488;
case 488:
#line 10365 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 58: goto tr644;
		case 62: goto tr640;
		case 95: goto tr636;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr636;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr636;
		} else if ( (*p) >= 65 )
			goto tr636;
	} else
		goto tr636;
	goto tr448;
tr644:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st489;
st489:
	if ( ++p == pe )
		goto _test_eof489;
case 489:
#line 10393 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 77 )
		goto tr645;
	goto tr448;
tr645:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st490;
st490:
	if ( ++p == pe )
		goto _test_eof490;
case 490:
#line 10407 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 69 )
		goto tr646;
	goto tr448;
tr646:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st491;
st491:
	if ( ++p == pe )
		goto _test_eof491;
case 491:
#line 10421 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 58 )
		goto tr647;
	goto tr448;
tr647:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st492;
st492:
	if ( ++p == pe )
		goto _test_eof492;
case 492:
#line 10435 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr648;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr648;
	} else
		goto tr648;
	goto tr448;
tr648:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st493;
st493:
	if ( ++p == pe )
		goto _test_eof493;
case 493:
#line 10455 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 62 )
		goto tr640;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr648;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr648;
	} else
		goto tr648;
	goto tr448;
tr642:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st494;
st494:
	if ( ++p == pe )
		goto _test_eof494;
case 494:
#line 10477 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 62: goto tr637;
		case 80: goto tr649;
		case 95: goto tr636;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr636;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr636;
		} else if ( (*p) >= 65 )
			goto tr636;
	} else
		goto tr636;
	goto tr448;
tr649:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st495;
st495:
	if ( ++p == pe )
		goto _test_eof495;
case 495:
#line 10505 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 58: goto tr650;
		case 62: goto tr640;
		case 95: goto tr636;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr636;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr636;
		} else if ( (*p) >= 65 )
			goto tr636;
	} else
		goto tr636;
	goto tr448;
tr650:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st496;
st496:
	if ( ++p == pe )
		goto _test_eof496;
case 496:
#line 10533 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 84 )
		goto tr651;
	goto tr448;
tr651:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st497;
st497:
	if ( ++p == pe )
		goto _test_eof497;
case 497:
#line 10547 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 65 )
		goto tr652;
	goto tr448;
tr652:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st498;
st498:
	if ( ++p == pe )
		goto _test_eof498;
case 498:
#line 10561 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 78 )
		goto tr653;
	goto tr448;
tr653:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st499;
st499:
	if ( ++p == pe )
		goto _test_eof499;
case 499:
#line 10575 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 68 )
		goto tr654;
	goto tr448;
tr654:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st500;
st500:
	if ( ++p == pe )
		goto _test_eof500;
case 500:
#line 10589 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 69 )
		goto tr655;
	goto tr448;
tr655:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st501;
st501:
	if ( ++p == pe )
		goto _test_eof501;
case 501:
#line 10603 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 77 )
		goto tr656;
	goto tr448;
tr656:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st502;
st502:
	if ( ++p == pe )
		goto _test_eof502;
case 502:
#line 10617 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 62 )
		goto tr640;
	goto tr448;
tr634:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st503;
st503:
	if ( ++p == pe )
		goto _test_eof503;
case 503:
#line 10635 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 62: goto tr637;
		case 78: goto tr657;
		case 95: goto tr636;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr636;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr636;
		} else if ( (*p) >= 65 )
			goto tr636;
	} else
		goto tr636;
	goto tr448;
tr657:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st504;
st504:
	if ( ++p == pe )
		goto _test_eof504;
case 504:
#line 10663 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 62: goto tr637;
		case 83: goto tr643;
		case 86: goto tr639;
		case 95: goto tr636;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr636;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr636;
		} else if ( (*p) >= 65 )
			goto tr636;
	} else
		goto tr636;
	goto tr448;
tr452:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st505;
tr658:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st505;
st505:
	if ( ++p == pe )
		goto _test_eof505;
case 505:
#line 10702 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr455;
		case 44: goto tr456;
		case 46: goto tr640;
		case 65: goto tr658;
		case 67: goto tr658;
		case 71: goto tr658;
		case 78: goto tr658;
		case 84: goto tr658;
		case 91: goto tr659;
		case 93: goto tr660;
		case 97: goto tr658;
		case 99: goto tr658;
		case 103: goto tr658;
		case 110: goto tr658;
		case 116: goto tr658;
	}
	goto tr448;
tr659:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st506;
st506:
	if ( ++p == pe )
		goto _test_eof506;
case 506:
#line 10731 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 60 )
		goto tr662;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr661;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr661;
	} else
		goto tr661;
	goto tr448;
tr661:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st507;
st507:
	if ( ++p == pe )
		goto _test_eof507;
case 507:
#line 10753 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 58: goto tr665;
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
	goto tr448;
tr663:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st508;
st508:
	if ( ++p == pe )
		goto _test_eof508;
case 508:
#line 10790 "cpp/src/bioformats/vcf/validator_detail.hpp"
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
	goto tr448;
tr664:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st509;
st509:
	if ( ++p == pe )
		goto _test_eof509;
case 509:
#line 10826 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 58: goto tr665;
		case 61: goto tr664;
	}
	if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr664;
	} else if ( (*p) >= 33 )
		goto tr664;
	goto tr448;
tr665:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st510;
st510:
	if ( ++p == pe )
		goto _test_eof510;
case 510:
#line 10847 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr666;
	goto tr448;
tr666:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st511;
st511:
	if ( ++p == pe )
		goto _test_eof511;
case 511:
#line 10861 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 91 )
		goto tr640;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr666;
	goto tr448;
tr662:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st512;
st512:
	if ( ++p == pe )
		goto _test_eof512;
case 512:
#line 10877 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr667;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr667;
	} else
		goto tr667;
	goto tr448;
tr667:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st513;
st513:
	if ( ++p == pe )
		goto _test_eof513;
case 513:
#line 10897 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr668;
		case 62: goto tr670;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr668;
		} else if ( (*p) > 57 ) {
			if ( 61 <= (*p) && (*p) <= 64 )
				goto tr668;
		} else
			goto tr669;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr668;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr668;
		} else
			goto tr669;
	} else
		goto tr669;
	goto tr448;
tr668:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st514;
st514:
	if ( ++p == pe )
		goto _test_eof514;
case 514:
#line 10933 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr668;
		case 61: goto tr668;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr668;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr668;
		} else
			goto tr669;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr668;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr668;
		} else
			goto tr669;
	} else
		goto tr669;
	goto tr448;
tr669:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st515;
st515:
	if ( ++p == pe )
		goto _test_eof515;
case 515:
#line 10969 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr669;
		case 62: goto tr670;
	}
	if ( (*p) > 57 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr669;
	} else if ( (*p) >= 33 )
		goto tr669;
	goto tr448;
tr670:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st516;
st516:
	if ( ++p == pe )
		goto _test_eof516;
case 516:
#line 10990 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 58 )
		goto tr665;
	goto tr448;
tr660:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st517;
st517:
	if ( ++p == pe )
		goto _test_eof517;
case 517:
#line 11004 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 60 )
		goto tr672;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr671;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr671;
	} else
		goto tr671;
	goto tr448;
tr671:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st518;
st518:
	if ( ++p == pe )
		goto _test_eof518;
case 518:
#line 11026 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 58: goto tr675;
		case 59: goto tr673;
		case 61: goto tr673;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr673;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr673;
		} else
			goto tr674;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr673;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr673;
		} else
			goto tr674;
	} else
		goto tr674;
	goto tr448;
tr673:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st519;
st519:
	if ( ++p == pe )
		goto _test_eof519;
case 519:
#line 11063 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr673;
		case 61: goto tr673;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr673;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr673;
		} else
			goto tr674;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr673;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr673;
		} else
			goto tr674;
	} else
		goto tr674;
	goto tr448;
tr674:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st520;
st520:
	if ( ++p == pe )
		goto _test_eof520;
case 520:
#line 11099 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 58: goto tr675;
		case 61: goto tr674;
	}
	if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr674;
	} else if ( (*p) >= 33 )
		goto tr674;
	goto tr448;
tr675:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st521;
st521:
	if ( ++p == pe )
		goto _test_eof521;
case 521:
#line 11120 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr676;
	goto tr448;
tr676:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st522;
st522:
	if ( ++p == pe )
		goto _test_eof522;
case 522:
#line 11134 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 93 )
		goto tr640;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr676;
	goto tr448;
tr672:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st523;
st523:
	if ( ++p == pe )
		goto _test_eof523;
case 523:
#line 11150 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr677;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr677;
	} else
		goto tr677;
	goto tr448;
tr677:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st524;
st524:
	if ( ++p == pe )
		goto _test_eof524;
case 524:
#line 11170 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr678;
		case 62: goto tr680;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr678;
		} else if ( (*p) > 57 ) {
			if ( 61 <= (*p) && (*p) <= 64 )
				goto tr678;
		} else
			goto tr679;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr678;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr678;
		} else
			goto tr679;
	} else
		goto tr679;
	goto tr448;
tr678:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st525;
st525:
	if ( ++p == pe )
		goto _test_eof525;
case 525:
#line 11206 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr678;
		case 61: goto tr678;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr678;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr678;
		} else
			goto tr679;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr678;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr678;
		} else
			goto tr679;
	} else
		goto tr679;
	goto tr448;
tr679:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st526;
st526:
	if ( ++p == pe )
		goto _test_eof526;
case 526:
#line 11242 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr679;
		case 62: goto tr680;
	}
	if ( (*p) > 57 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr679;
	} else if ( (*p) >= 33 )
		goto tr679;
	goto tr448;
tr680:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st527;
st527:
	if ( ++p == pe )
		goto _test_eof527;
case 527:
#line 11263 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 58 )
		goto tr675;
	goto tr448;
tr453:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st528;
st528:
	if ( ++p == pe )
		goto _test_eof528;
case 528:
#line 11281 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 60 )
		goto tr682;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr681;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr681;
	} else
		goto tr681;
	goto tr448;
tr681:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st529;
st529:
	if ( ++p == pe )
		goto _test_eof529;
case 529:
#line 11303 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 58: goto tr685;
		case 59: goto tr683;
		case 61: goto tr683;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr683;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr683;
		} else
			goto tr684;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr683;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr683;
		} else
			goto tr684;
	} else
		goto tr684;
	goto tr448;
tr683:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st530;
st530:
	if ( ++p == pe )
		goto _test_eof530;
case 530:
#line 11340 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr683;
		case 61: goto tr683;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr683;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr683;
		} else
			goto tr684;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr683;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr683;
		} else
			goto tr684;
	} else
		goto tr684;
	goto tr448;
tr684:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st531;
st531:
	if ( ++p == pe )
		goto _test_eof531;
case 531:
#line 11376 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 58: goto tr685;
		case 61: goto tr684;
	}
	if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr684;
	} else if ( (*p) >= 33 )
		goto tr684;
	goto tr448;
tr685:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st532;
st532:
	if ( ++p == pe )
		goto _test_eof532;
case 532:
#line 11397 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr686;
	goto tr448;
tr686:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st533;
st533:
	if ( ++p == pe )
		goto _test_eof533;
case 533:
#line 11411 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 91 )
		goto tr687;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr686;
	goto tr448;
tr682:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st534;
st534:
	if ( ++p == pe )
		goto _test_eof534;
case 534:
#line 11427 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr688;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr688;
	} else
		goto tr688;
	goto tr448;
tr688:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st535;
st535:
	if ( ++p == pe )
		goto _test_eof535;
case 535:
#line 11447 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr689;
		case 62: goto tr691;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr689;
		} else if ( (*p) > 57 ) {
			if ( 61 <= (*p) && (*p) <= 64 )
				goto tr689;
		} else
			goto tr690;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr689;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr689;
		} else
			goto tr690;
	} else
		goto tr690;
	goto tr448;
tr689:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st536;
st536:
	if ( ++p == pe )
		goto _test_eof536;
case 536:
#line 11483 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr689;
		case 61: goto tr689;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr689;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr689;
		} else
			goto tr690;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr689;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr689;
		} else
			goto tr690;
	} else
		goto tr690;
	goto tr448;
tr690:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st537;
st537:
	if ( ++p == pe )
		goto _test_eof537;
case 537:
#line 11519 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr690;
		case 62: goto tr691;
	}
	if ( (*p) > 57 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr690;
	} else if ( (*p) >= 33 )
		goto tr690;
	goto tr448;
tr691:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st538;
st538:
	if ( ++p == pe )
		goto _test_eof538;
case 538:
#line 11540 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 58 )
		goto tr685;
	goto tr448;
tr454:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st539;
st539:
	if ( ++p == pe )
		goto _test_eof539;
case 539:
#line 11558 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 60 )
		goto tr693;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr692;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr692;
	} else
		goto tr692;
	goto tr448;
tr692:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st540;
st540:
	if ( ++p == pe )
		goto _test_eof540;
case 540:
#line 11580 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 58: goto tr696;
		case 59: goto tr694;
		case 61: goto tr694;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr694;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr694;
		} else
			goto tr695;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr694;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr694;
		} else
			goto tr695;
	} else
		goto tr695;
	goto tr448;
tr694:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st541;
st541:
	if ( ++p == pe )
		goto _test_eof541;
case 541:
#line 11617 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr694;
		case 61: goto tr694;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr694;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr694;
		} else
			goto tr695;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr694;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr694;
		} else
			goto tr695;
	} else
		goto tr695;
	goto tr448;
tr695:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st542;
st542:
	if ( ++p == pe )
		goto _test_eof542;
case 542:
#line 11653 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 58: goto tr696;
		case 61: goto tr695;
	}
	if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr695;
	} else if ( (*p) >= 33 )
		goto tr695;
	goto tr448;
tr696:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st543;
st543:
	if ( ++p == pe )
		goto _test_eof543;
case 543:
#line 11674 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr697;
	goto tr448;
tr697:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st544;
st544:
	if ( ++p == pe )
		goto _test_eof544;
case 544:
#line 11688 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 93 )
		goto tr687;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr697;
	goto tr448;
tr693:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st545;
st545:
	if ( ++p == pe )
		goto _test_eof545;
case 545:
#line 11704 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr698;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr698;
	} else
		goto tr698;
	goto tr448;
tr698:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st546;
st546:
	if ( ++p == pe )
		goto _test_eof546;
case 546:
#line 11724 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr699;
		case 62: goto tr701;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr699;
		} else if ( (*p) > 57 ) {
			if ( 61 <= (*p) && (*p) <= 64 )
				goto tr699;
		} else
			goto tr700;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr699;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr699;
		} else
			goto tr700;
	} else
		goto tr700;
	goto tr448;
tr699:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st547;
st547:
	if ( ++p == pe )
		goto _test_eof547;
case 547:
#line 11760 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr699;
		case 61: goto tr699;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr699;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr699;
		} else
			goto tr700;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr699;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr699;
		} else
			goto tr700;
	} else
		goto tr700;
	goto tr448;
tr700:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st548;
st548:
	if ( ++p == pe )
		goto _test_eof548;
case 548:
#line 11796 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr700;
		case 62: goto tr701;
	}
	if ( (*p) > 57 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr700;
	} else if ( (*p) >= 33 )
		goto tr700;
	goto tr448;
tr701:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st549;
st549:
	if ( ++p == pe )
		goto _test_eof549;
case 549:
#line 11817 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 58 )
		goto tr696;
	goto tr448;
tr450:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st550;
st550:
	if ( ++p == pe )
		goto _test_eof550;
case 550:
#line 11835 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr702;
		case 65: goto tr629;
		case 67: goto tr629;
		case 71: goto tr629;
		case 78: goto tr629;
		case 84: goto tr629;
		case 97: goto tr629;
		case 99: goto tr629;
		case 103: goto tr629;
		case 110: goto tr629;
		case 116: goto tr629;
	}
	goto tr448;
tr433:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st551;
st551:
	if ( ++p == pe )
		goto _test_eof551;
case 551:
#line 11860 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr433;
		case 61: goto tr433;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr433;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr433;
		} else
			goto tr434;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr433;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr433;
		} else
			goto tr434;
	} else
		goto tr434;
	goto tr431;
tr434:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st552;
st552:
	if ( ++p == pe )
		goto _test_eof552;
case 552:
#line 11896 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr432;
		case 59: goto tr434;
		case 61: goto tr434;
	}
	if ( (*p) > 57 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr434;
	} else if ( (*p) >= 33 )
		goto tr434;
	goto tr431;
st553:
	if ( ++p == pe )
		goto _test_eof553;
case 553:
	if ( (*p) == 10 )
		goto tr704;
	goto st553;
tr704:
#line 28 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;
    }
#line 665 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{ {goto st20;} }
	goto st557;
st557:
	if ( ++p == pe )
		goto _test_eof557;
case 557:
#line 11929 "cpp/src/bioformats/vcf/validator_detail.hpp"
	goto st0;
st554:
	if ( ++p == pe )
		goto _test_eof554;
case 554:
	if ( (*p) == 10 )
		goto tr706;
	goto st554;
tr706:
#line 28 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;
    }
#line 666 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{ {goto st556;} }
	goto st558;
st558:
	if ( ++p == pe )
		goto _test_eof558;
case 558:
#line 11952 "cpp/src/bioformats/vcf/validator_detail.hpp"
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
	_test_eof555: cs = 555; goto _test_eof; 
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
	_test_eof556: cs = 556; goto _test_eof; 
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
	_test_eof557: cs = 557; goto _test_eof; 
	_test_eof554: cs = 554; goto _test_eof; 
	_test_eof558: cs = 558; goto _test_eof; 

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
#line 42 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this);
        p--; {goto st553;}
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
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
	break;
	case 337: 
	case 338: 
	case 339: 
	case 340: 
	case 341: 
	case 342: 
	case 343: 
	case 344: 
	case 345: 
#line 52 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        p--; {goto st554;}
    }
	break;
	case 14: 
	case 15: 
#line 165 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this,
            "Fileformat is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st553;}
    }
#line 42 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this);
        p--; {goto st553;}
    }
	break;
	case 30: 
	case 31: 
	case 32: 
	case 33: 
	case 34: 
	case 35: 
	case 36: 
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
	case 55: 
#line 172 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st553;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
	break;
	case 247: 
	case 248: 
	case 249: 
	case 250: 
	case 251: 
	case 252: 
	case 253: 
	case 254: 
#line 183 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in assembly metadata");
        p--; {goto st553;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
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
	case 275: 
	case 276: 
	case 277: 
	case 278: 
	case 279: 
	case 280: 
#line 189 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in contig metadata");
        p--; {goto st553;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
	break;
	case 57: 
	case 58: 
	case 59: 
	case 60: 
	case 61: 
	case 62: 
	case 63: 
	case 64: 
	case 65: 
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
	case 85: 
#line 195 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st553;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
	break;
	case 86: 
	case 87: 
	case 88: 
	case 89: 
	case 90: 
	case 91: 
	case 92: 
	case 93: 
	case 94: 
	case 98: 
	case 99: 
	case 100: 
	case 101: 
	case 102: 
	case 103: 
	case 104: 
	case 107: 
	case 108: 
	case 109: 
	case 110: 
	case 111: 
	case 114: 
	case 115: 
	case 116: 
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
	case 130: 
#line 201 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st553;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
	break;
	case 132: 
	case 133: 
	case 134: 
	case 135: 
	case 136: 
	case 137: 
	case 138: 
	case 139: 
	case 143: 
	case 144: 
	case 145: 
	case 146: 
	case 147: 
	case 148: 
	case 149: 
	case 152: 
	case 153: 
	case 154: 
	case 155: 
	case 156: 
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
	case 170: 
	case 171: 
	case 172: 
	case 178: 
	case 179: 
#line 217 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st553;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
	break;
	case 181: 
	case 182: 
	case 183: 
	case 184: 
	case 185: 
	case 186: 
	case 187: 
	case 188: 
	case 189: 
	case 196: 
#line 233 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in PEDIGREE metadata");
        p--; {goto st553;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
	break;
	case 281: 
	case 282: 
	case 283: 
	case 284: 
	case 285: 
	case 286: 
	case 287: 
	case 288: 
	case 289: 
	case 290: 
	case 291: 
#line 239 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in pedigreeDB metadata");
        p--; {goto st553;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
	break;
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
	case 246: 
#line 245 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st553;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
	break;
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
	case 330: 
	case 331: 
	case 332: 
	case 333: 
	case 334: 
	case 335: 
	case 336: 
#line 277 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this, "The header line does not start with the mandatory columns: CHROM, POS, ID, REF, ALT, QUAL, FILTER and INFO");
        p--; {goto st554;}
    }
#line 52 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        p--; {goto st554;}
    }
	break;
	case 346: 
	case 367: 
	case 368: 
	case 369: 
	case 370: 
	case 371: 
	case 551: 
	case 552: 
#line 285 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Chromosome is not a string without colons or whitespaces, optionally wrapped with angle brackets (<>)");
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	break;
	case 347: 
	case 348: 
#line 291 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Position is not a positive number");
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	break;
	case 349: 
	case 350: 
#line 297 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "ID is not a single dot or a list of strings without semicolons or whitespaces");
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	break;
	case 351: 
	case 352: 
#line 303 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Reference is not a string of bases");
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	break;
	case 353: 
	case 354: 
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
#line 309 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Alternate is not a single dot or a comma-separated list of bases");
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	break;
	case 355: 
	case 356: 
	case 474: 
	case 475: 
	case 476: 
#line 315 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Quality is not a single dot or a positive number");
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	break;
	case 357: 
	case 358: 
	case 359: 
	case 472: 
	case 473: 
#line 321 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Filter is not a single dot or a semicolon-separated list of strings");
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	break;
	case 363: 
	case 364: 
#line 433 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Format is not a colon-separated list of alphanumeric strings");
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	break;
	case 373: 
	case 374: 
#line 439 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " is not a valid string";
        ErrorPolicy::handle_body_section_error(*this, message_stream.str());
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	break;
	case 17: 
	case 20: 
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
#line 277 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this, "The header line does not start with the mandatory columns: CHROM, POS, ID, REF, ALT, QUAL, FILTER and INFO");
        p--; {goto st554;}
    }
#line 52 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        p--; {goto st554;}
    }
	break;
	case 37: 
	case 38: 
#line 177 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "ALT metadata ID is not prefixed by DEL/INS/DUP/INV/CNV and suffixed by ':' and a text sequence");
        p--; {goto st553;}
    }
#line 172 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st553;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
	break;
	case 56: 
#line 195 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st553;}
    }
#line 201 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st553;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
	break;
	case 105: 
	case 106: 
	case 131: 
#line 206 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "FORMAT metadata Number is not a number, A, R, G or dot");
        p--; {goto st553;}
    }
#line 201 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st553;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
	break;
	case 150: 
	case 151: 
	case 180: 
#line 222 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "INFO metadata Number is not a number, A, R, G or dot");
        p--; {goto st553;}
    }
#line 217 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st553;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
	break;
	case 112: 
	case 113: 
#line 227 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "INFO metadata Type is not a Integer, Float, Flag, Character or String");
        p--; {goto st553;}
    }
#line 201 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st553;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
	break;
	case 157: 
	case 158: 
#line 227 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "INFO metadata Type is not a Integer, Float, Flag, Character or String");
        p--; {goto st553;}
    }
#line 217 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st553;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
	break;
	case 210: 
	case 211: 
	case 212: 
	case 213: 
	case 214: 
	case 215: 
	case 216: 
	case 217: 
	case 218: 
#line 250 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Genomes is not a valid string (maybe it contains quotes?)");
        p--; {goto st553;}
    }
#line 245 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st553;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
	break;
	case 220: 
	case 221: 
	case 222: 
	case 223: 
	case 224: 
	case 225: 
	case 226: 
	case 227: 
	case 228: 
#line 255 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Mixture is not a valid string (maybe it contains quotes?)");
        p--; {goto st553;}
    }
#line 245 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st553;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
	break;
	case 272: 
	case 273: 
	case 274: 
#line 261 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st553;}
    }
#line 189 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in contig metadata");
        p--; {goto st553;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
	break;
	case 66: 
	case 67: 
	case 68: 
#line 261 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st553;}
    }
#line 195 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st553;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
	break;
	case 95: 
	case 96: 
	case 97: 
#line 261 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st553;}
    }
#line 201 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st553;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
	break;
	case 140: 
	case 141: 
	case 142: 
	case 175: 
	case 176: 
	case 177: 
#line 261 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st553;}
    }
#line 217 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st553;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
	break;
	case 190: 
	case 191: 
	case 192: 
	case 193: 
	case 194: 
	case 195: 
#line 261 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st553;}
    }
#line 233 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in PEDIGREE metadata");
        p--; {goto st553;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
	break;
	case 207: 
	case 208: 
#line 261 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st553;}
    }
#line 245 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st553;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
	break;
	case 53: 
	case 54: 
#line 266 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st553;}
    }
#line 172 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st553;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
	break;
	case 83: 
	case 84: 
#line 266 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st553;}
    }
#line 195 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st553;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
	break;
	case 128: 
	case 129: 
#line 266 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st553;}
    }
#line 201 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st553;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
	break;
	case 173: 
	case 174: 
#line 266 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st553;}
    }
#line 217 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st553;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
	break;
	case 230: 
	case 231: 
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
	case 242: 
	case 243: 
	case 244: 
	case 245: 
#line 266 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st553;}
    }
#line 245 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st553;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
	break;
	case 255: 
	case 256: 
	case 257: 
	case 258: 
	case 259: 
	case 260: 
	case 261: 
#line 271 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata URL is not valid");
        p--; {goto st553;}
    }
#line 183 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in assembly metadata");
        p--; {goto st553;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
	break;
	case 292: 
	case 293: 
	case 294: 
	case 295: 
	case 296: 
	case 297: 
	case 298: 
	case 299: 
#line 271 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata URL is not valid");
        p--; {goto st553;}
    }
#line 239 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in pedigreeDB metadata");
        p--; {goto st553;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
	break;
	case 360: 
	case 361: 
	case 362: 
	case 375: 
	case 376: 
	case 377: 
	case 378: 
	case 379: 
	case 385: 
	case 386: 
	case 390: 
	case 393: 
	case 398: 
	case 401: 
	case 402: 
	case 407: 
	case 408: 
	case 409: 
	case 410: 
	case 411: 
	case 414: 
	case 418: 
	case 421: 
	case 422: 
	case 423: 
	case 426: 
	case 433: 
	case 434: 
	case 435: 
	case 442: 
	case 443: 
	case 446: 
	case 447: 
	case 452: 
	case 453: 
	case 454: 
	case 455: 
	case 456: 
	case 460: 
	case 461: 
	case 462: 
	case 463: 
	case 464: 
	case 465: 
	case 466: 
	case 467: 
	case 471: 
#line 332 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st554;}
    }
#line 327 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	break;
	case 380: 
	case 381: 
#line 337 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info field value is not a comma-separated list of valid strings (maybe it contains whitespaces?)");
        p--; {goto st554;}
    }
#line 327 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	break;
	case 387: 
	case 388: 
	case 389: 
#line 342 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info AA value is not a single dot or a string of bases");
        p--; {goto st554;}
    }
#line 327 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	break;
	case 391: 
	case 392: 
#line 347 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info AC value is not a comma-separated list of numbers");
        p--; {goto st554;}
    }
#line 327 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	break;
	case 394: 
	case 395: 
	case 396: 
	case 397: 
#line 352 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info AF value is not a comma-separated list of numbers");
        p--; {goto st554;}
    }
#line 327 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	break;
	case 399: 
	case 400: 
#line 357 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info AN value is not an integer number");
        p--; {goto st554;}
    }
#line 327 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	break;
	case 403: 
	case 404: 
	case 405: 
	case 406: 
#line 362 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info BQ value is not a number");
        p--; {goto st554;}
    }
#line 327 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	break;
	case 412: 
	case 413: 
#line 367 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info CIGAR value is not an alphanumeric string");
        p--; {goto st554;}
    }
#line 327 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	break;
	case 416: 
	case 417: 
#line 372 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info DB is not a flag (with 1/0/no value)");
        p--; {goto st554;}
    }
#line 327 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	break;
	case 419: 
	case 420: 
#line 377 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info DP value is not an integer number");
        p--; {goto st554;}
    }
#line 327 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	break;
	case 424: 
	case 425: 
#line 382 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info END value is not an integer number");
        p--; {goto st554;}
    }
#line 327 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	break;
	case 428: 
	case 429: 
#line 387 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info H2 is not a flag (with 1/0/no value)");
        p--; {goto st554;}
    }
#line 327 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	break;
	case 431: 
	case 432: 
#line 392 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info H3 is not a flag (with 1/0/no value)");
        p--; {goto st554;}
    }
#line 327 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	break;
	case 438: 
	case 439: 
	case 440: 
	case 441: 
#line 397 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info MQ value is not a number");
        p--; {goto st554;}
    }
#line 327 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	break;
	case 436: 
	case 437: 
#line 402 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info MQ0 value is not an integer number");
        p--; {goto st554;}
    }
#line 327 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	break;
	case 444: 
	case 445: 
#line 407 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info NS value is not an integer number");
        p--; {goto st554;}
    }
#line 327 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	break;
	case 448: 
	case 449: 
	case 450: 
	case 451: 
#line 412 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info SB value is not a number");
        p--; {goto st554;}
    }
#line 327 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	break;
	case 458: 
	case 459: 
#line 417 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info SOMATIC is not a flag (with 1/0/no value)");
        p--; {goto st554;}
    }
#line 327 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	break;
	case 469: 
	case 470: 
#line 422 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info VALIDATED is not a flag (with 1/0/no value)");
        p--; {goto st554;}
    }
#line 327 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	break;
	case 383: 
	case 384: 
#line 427 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info 1000G is not a flag (with 1/0/no value)");
        p--; {goto st554;}
    }
#line 327 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	break;
	case 365: 
	case 366: 
	case 372: 
#line 446 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " does not start with a valid genotype";
        ErrorPolicy::handle_body_section_error(*this, message_stream.str());
        p--; {goto st554;}
    }
#line 439 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " is not a valid string";
        ErrorPolicy::handle_body_section_error(*this, message_stream.str());
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	break;
	case 16: 
#line 42 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this);
        p--; {goto st553;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
#line 277 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this, "The header line does not start with the mandatory columns: CHROM, POS, ID, REF, ALT, QUAL, FILTER and INFO");
        p--; {goto st554;}
    }
#line 52 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        p--; {goto st554;}
    }
	break;
	case 219: 
#line 250 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Genomes is not a valid string (maybe it contains quotes?)");
        p--; {goto st553;}
    }
#line 255 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Mixture is not a valid string (maybe it contains quotes?)");
        p--; {goto st553;}
    }
#line 245 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st553;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
	break;
	case 229: 
#line 255 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Mixture is not a valid string (maybe it contains quotes?)");
        p--; {goto st553;}
    }
#line 266 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st553;}
    }
#line 245 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st553;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
	break;
	case 209: 
#line 261 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st553;}
    }
#line 250 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Genomes is not a valid string (maybe it contains quotes?)");
        p--; {goto st553;}
    }
#line 245 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st553;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
	break;
	case 415: 
#line 372 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info DB is not a flag (with 1/0/no value)");
        p--; {goto st554;}
    }
#line 332 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st554;}
    }
#line 327 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	break;
	case 427: 
#line 387 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info H2 is not a flag (with 1/0/no value)");
        p--; {goto st554;}
    }
#line 332 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st554;}
    }
#line 327 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	break;
	case 430: 
#line 392 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info H3 is not a flag (with 1/0/no value)");
        p--; {goto st554;}
    }
#line 332 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st554;}
    }
#line 327 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	break;
	case 457: 
#line 417 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info SOMATIC is not a flag (with 1/0/no value)");
        p--; {goto st554;}
    }
#line 332 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st554;}
    }
#line 327 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	break;
	case 468: 
#line 422 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info VALIDATED is not a flag (with 1/0/no value)");
        p--; {goto st554;}
    }
#line 332 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st554;}
    }
#line 327 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	break;
	case 382: 
#line 427 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info 1000G is not a flag (with 1/0/no value)");
        p--; {goto st554;}
    }
#line 332 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st554;}
    }
#line 327 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st554;}
    }
#line 57 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st554;}
    }
	break;
	case 18: 
#line 172 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st553;}
    }
#line 195 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st553;}
    }
#line 201 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st553;}
    }
#line 217 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st553;}
    }
#line 183 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in assembly metadata");
        p--; {goto st553;}
    }
#line 189 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in contig metadata");
        p--; {goto st553;}
    }
#line 245 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st553;}
    }
#line 233 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in PEDIGREE metadata");
        p--; {goto st553;}
    }
#line 239 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in pedigreeDB metadata");
        p--; {goto st553;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st553;}
    }
	break;
#line 14263 "cpp/src/bioformats/vcf/validator_detail.hpp"
	}
	}

	_out: {}
	}

#line 727 "cpp/src/bioformats/vcf/vcf_v41.ragel"

    }

  }
}
