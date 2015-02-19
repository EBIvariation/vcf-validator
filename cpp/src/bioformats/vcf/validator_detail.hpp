
#line 1 "cpp/src/bioformats/vcf/vcf_v41.ragel"
#include <cstdio>

#include "validator.hpp"


#line 695 "cpp/src/bioformats/vcf/vcf_v41.ragel"


namespace
{
  
#line 15 "cpp/src/bioformats/vcf/validator_detail.hpp"
static const int vcf_start = 1;
static const int vcf_first_final = 556;
static const int vcf_error = 0;

static const int vcf_en_main = 1;
static const int vcf_en_main_meta_section = 20;
static const int vcf_en_main_body_section = 557;
static const int vcf_en_meta_section_skip = 554;
static const int vcf_en_body_section_skip = 555;


#line 701 "cpp/src/bioformats/vcf/vcf_v41.ragel"

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

#line 716 "cpp/src/bioformats/vcf/vcf_v41.ragel"

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
#line 82 "cpp/src/bioformats/vcf/validator_detail.hpp"
556
#line 749 "cpp/src/bioformats/vcf/vcf_v41.ragel"
;
    }

    template <typename Configuration>
    void Parser<Configuration>::parse_buffer(char const * p, char const * pe, char const * eof)
    {
      
#line 92 "cpp/src/bioformats/vcf/validator_detail.hpp"
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
        p--; {goto st554;}
    }
	goto st0;
tr14:
#line 188 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this,
            "Fileformat is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st554;}
    }
#line 42 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr18:
#line 42 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this);
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
#line 300 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this, "The header line does not start with the mandatory columns: CHROM, POS, ID, REF, ALT, QUAL, FILTER and INFO");
        p--; {goto st555;}
    }
#line 60 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        p--; {goto st555;}
    }
	goto st0;
tr20:
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
#line 300 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this, "The header line does not start with the mandatory columns: CHROM, POS, ID, REF, ALT, QUAL, FILTER and INFO");
        p--; {goto st555;}
    }
#line 60 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        p--; {goto st555;}
    }
	goto st0;
tr23:
#line 195 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st554;}
    }
#line 218 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st554;}
    }
#line 224 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st554;}
    }
#line 240 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st554;}
    }
#line 206 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in assembly metadata");
        p--; {goto st554;}
    }
#line 212 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in contig metadata");
        p--; {goto st554;}
    }
#line 268 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st554;}
    }
#line 256 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in PEDIGREE metadata");
        p--; {goto st554;}
    }
#line 262 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in pedigreeDB metadata");
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr34:
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr52:
#line 195 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr60:
#line 200 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "ALT metadata ID is not prefixed by DEL/INS/DUP/INV/CNV and suffixed by ':' and a text sequence");
        p--; {goto st554;}
    }
#line 195 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr80:
#line 289 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st554;}
    }
#line 195 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr85:
#line 284 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st554;}
    }
#line 195 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr92:
#line 218 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st554;}
    }
#line 224 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr95:
#line 218 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr105:
#line 284 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st554;}
    }
#line 218 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr125:
#line 289 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st554;}
    }
#line 218 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr136:
#line 224 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr146:
#line 284 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st554;}
    }
#line 224 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr159:
#line 229 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "FORMAT metadata Number is not a number, A, R, G or dot");
        p--; {goto st554;}
    }
#line 224 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr168:
#line 250 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "INFO metadata Type is not a Integer, Float, Flag, Character or String");
        p--; {goto st554;}
    }
#line 224 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr186:
#line 289 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st554;}
    }
#line 224 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr198:
#line 240 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr207:
#line 284 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st554;}
    }
#line 240 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr220:
#line 245 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "INFO metadata Number is not a number, A, R, G or dot");
        p--; {goto st554;}
    }
#line 240 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr229:
#line 250 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "INFO metadata Type is not a Integer, Float, Flag, Character or String");
        p--; {goto st554;}
    }
#line 240 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr247:
#line 289 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st554;}
    }
#line 240 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr259:
#line 256 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in PEDIGREE metadata");
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr269:
#line 284 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st554;}
    }
#line 256 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in PEDIGREE metadata");
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr281:
#line 268 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr292:
#line 284 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st554;}
    }
#line 268 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr297:
#line 284 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st554;}
    }
#line 273 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Genomes is not a valid string (maybe it contains quotes?)");
        p--; {goto st554;}
    }
#line 268 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr299:
#line 273 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Genomes is not a valid string (maybe it contains quotes?)");
        p--; {goto st554;}
    }
#line 268 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr309:
#line 273 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Genomes is not a valid string (maybe it contains quotes?)");
        p--; {goto st554;}
    }
#line 278 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Mixture is not a valid string (maybe it contains quotes?)");
        p--; {goto st554;}
    }
#line 268 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr312:
#line 278 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Mixture is not a valid string (maybe it contains quotes?)");
        p--; {goto st554;}
    }
#line 268 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr322:
#line 278 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Mixture is not a valid string (maybe it contains quotes?)");
        p--; {goto st554;}
    }
#line 289 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st554;}
    }
#line 268 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr325:
#line 289 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st554;}
    }
#line 268 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr343:
#line 206 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in assembly metadata");
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr352:
#line 294 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata URL is not valid");
        p--; {goto st554;}
    }
#line 206 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in assembly metadata");
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr359:
#line 212 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in contig metadata");
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr370:
#line 284 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st554;}
    }
#line 212 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in contig metadata");
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr384:
#line 262 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in pedigreeDB metadata");
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr396:
#line 294 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata URL is not valid");
        p--; {goto st554;}
    }
#line 262 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in pedigreeDB metadata");
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
	goto st0;
tr404:
#line 300 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this, "The header line does not start with the mandatory columns: CHROM, POS, ID, REF, ALT, QUAL, FILTER and INFO");
        p--; {goto st555;}
    }
#line 60 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        p--; {goto st555;}
    }
	goto st0;
tr443:
#line 60 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        p--; {goto st555;}
    }
	goto st0;
tr455:
#line 308 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Chromosome is not a string without colons or whitespaces, optionally wrapped with angle brackets (<>)");
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	goto st0;
tr459:
#line 314 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Position is not a positive number");
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	goto st0;
tr463:
#line 320 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "ID is not a single dot or a list of strings without semicolons or whitespaces");
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	goto st0;
tr468:
#line 326 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Reference is not a string of bases");
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	goto st0;
tr472:
#line 332 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Alternate is not a single dot or a comma-separated list of bases");
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	goto st0;
tr481:
#line 338 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Quality is not a single dot or a positive number");
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	goto st0;
tr485:
#line 344 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Filter is not a single dot or a semicolon-separated list of strings");
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	goto st0;
tr493:
#line 355 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st555;}
    }
#line 350 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	goto st0;
tr514:
#line 456 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Format is not a colon-separated list of alphanumeric strings");
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	goto st0;
tr519:
#line 469 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " does not start with a valid genotype";
        ErrorPolicy::handle_body_section_error(*this, message_stream.str());
        p--; {goto st555;}
    }
#line 462 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " is not a valid string";
        ErrorPolicy::handle_body_section_error(*this, message_stream.str());
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	goto st0;
tr528:
#line 462 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " is not a valid string";
        ErrorPolicy::handle_body_section_error(*this, message_stream.str());
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	goto st0;
tr534:
#line 360 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info field value is not a comma-separated list of valid strings (maybe it contains whitespaces?)");
        p--; {goto st555;}
    }
#line 350 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	goto st0;
tr536:
#line 450 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info 1000G is not a flag (with 1/0/no value)");
        p--; {goto st555;}
    }
#line 355 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st555;}
    }
#line 350 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	goto st0;
tr538:
#line 450 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info 1000G is not a flag (with 1/0/no value)");
        p--; {goto st555;}
    }
#line 350 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	goto st0;
tr545:
#line 365 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info AA value is not a single dot or a string of bases");
        p--; {goto st555;}
    }
#line 350 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	goto st0;
tr549:
#line 370 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info AC value is not a comma-separated list of numbers");
        p--; {goto st555;}
    }
#line 350 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	goto st0;
tr552:
#line 375 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info AF value is not a comma-separated list of numbers");
        p--; {goto st555;}
    }
#line 350 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	goto st0;
tr557:
#line 380 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info AN value is not an integer number");
        p--; {goto st555;}
    }
#line 350 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	goto st0;
tr561:
#line 385 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info BQ value is not a number");
        p--; {goto st555;}
    }
#line 350 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	goto st0;
tr570:
#line 390 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info CIGAR value is not an alphanumeric string");
        p--; {goto st555;}
    }
#line 350 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	goto st0;
tr574:
#line 395 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info DB is not a flag (with 1/0/no value)");
        p--; {goto st555;}
    }
#line 355 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st555;}
    }
#line 350 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	goto st0;
tr576:
#line 395 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info DB is not a flag (with 1/0/no value)");
        p--; {goto st555;}
    }
#line 350 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	goto st0;
tr579:
#line 400 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info DP value is not an integer number");
        p--; {goto st555;}
    }
#line 350 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	goto st0;
tr584:
#line 405 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info END value is not an integer number");
        p--; {goto st555;}
    }
#line 350 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	goto st0;
tr588:
#line 410 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info H2 is not a flag (with 1/0/no value)");
        p--; {goto st555;}
    }
#line 355 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st555;}
    }
#line 350 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	goto st0;
tr590:
#line 410 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info H2 is not a flag (with 1/0/no value)");
        p--; {goto st555;}
    }
#line 350 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	goto st0;
tr592:
#line 415 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info H3 is not a flag (with 1/0/no value)");
        p--; {goto st555;}
    }
#line 355 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st555;}
    }
#line 350 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	goto st0;
tr594:
#line 415 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info H3 is not a flag (with 1/0/no value)");
        p--; {goto st555;}
    }
#line 350 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	goto st0;
tr600:
#line 425 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info MQ0 value is not an integer number");
        p--; {goto st555;}
    }
#line 350 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	goto st0;
tr602:
#line 420 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info MQ value is not a number");
        p--; {goto st555;}
    }
#line 350 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	goto st0;
tr608:
#line 430 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info NS value is not an integer number");
        p--; {goto st555;}
    }
#line 350 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	goto st0;
tr613:
#line 435 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info SB value is not a number");
        p--; {goto st555;}
    }
#line 350 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	goto st0;
tr622:
#line 440 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info SOMATIC is not a flag (with 1/0/no value)");
        p--; {goto st555;}
    }
#line 355 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st555;}
    }
#line 350 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	goto st0;
tr624:
#line 440 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info SOMATIC is not a flag (with 1/0/no value)");
        p--; {goto st555;}
    }
#line 350 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	goto st0;
tr634:
#line 445 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info VALIDATED is not a flag (with 1/0/no value)");
        p--; {goto st555;}
    }
#line 355 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st555;}
    }
#line 350 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	goto st0;
tr636:
#line 445 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info VALIDATED is not a flag (with 1/0/no value)");
        p--; {goto st555;}
    }
#line 350 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	goto st0;
tr704:
#line 60 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        p--; {goto st555;}
    }
#line 308 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Chromosome is not a string without colons or whitespaces, optionally wrapped with angle brackets (<>)");
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	goto st0;
#line 1407 "cpp/src/bioformats/vcf/validator_detail.hpp"
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
#line 1522 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 10 )
		goto tr16;
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr17;
	goto tr14;
tr16:
#line 73 "cpp/src/bioformats/vcf/vcf_v41.ragel"
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
#line 1544 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 35 )
		goto st17;
	goto tr18;
st17:
	if ( ++p == pe )
		goto _test_eof17;
case 17:
	switch( (*p) ) {
		case 35: goto st18;
		case 67: goto st313;
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
#line 1616 "cpp/src/bioformats/vcf/validator_detail.hpp"
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
#line 145 "cpp/src/bioformats/vcf/vcf_v41.ragel"
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
#line 145 "cpp/src/bioformats/vcf/vcf_v41.ragel"
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
#line 1666 "cpp/src/bioformats/vcf/validator_detail.hpp"
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
#line 1690 "cpp/src/bioformats/vcf/validator_detail.hpp"
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
#line 137 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this);
    }
	goto st22;
st22:
	if ( ++p == pe )
		goto _test_eof22;
case 22:
#line 1727 "cpp/src/bioformats/vcf/validator_detail.hpp"
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
#line 1753 "cpp/src/bioformats/vcf/validator_detail.hpp"
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
#line 1773 "cpp/src/bioformats/vcf/validator_detail.hpp"
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
#line 1798 "cpp/src/bioformats/vcf/validator_detail.hpp"
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
#line 1833 "cpp/src/bioformats/vcf/validator_detail.hpp"
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
#line 141 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_key(*this);
    }
	goto st27;
st27:
	if ( ++p == pe )
		goto _test_eof27;
case 27:
#line 1860 "cpp/src/bioformats/vcf/validator_detail.hpp"
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
#line 1890 "cpp/src/bioformats/vcf/validator_detail.hpp"
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
#line 1909 "cpp/src/bioformats/vcf/validator_detail.hpp"
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
#line 1927 "cpp/src/bioformats/vcf/validator_detail.hpp"
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
#line 1965 "cpp/src/bioformats/vcf/validator_detail.hpp"
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
#line 2003 "cpp/src/bioformats/vcf/validator_detail.hpp"
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
#line 77 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "ALT");
    }
	goto st33;
st33:
	if ( ++p == pe )
		goto _test_eof33;
case 33:
#line 2040 "cpp/src/bioformats/vcf/validator_detail.hpp"
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
	switch( (*p) ) {
		case 58: goto tr61;
		case 95: goto tr61;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr62;
	} else if ( (*p) >= 65 )
		goto tr62;
	goto tr60;
tr61:
#line 113 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_key(*this, "ID");
    }
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st38;
st38:
	if ( ++p == pe )
		goto _test_eof38;
case 38:
#line 2093 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 58: goto st38;
		case 95: goto st38;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr64;
	} else if ( (*p) >= 65 )
		goto tr64;
	goto tr60;
tr64:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st39;
tr62:
#line 113 "cpp/src/bioformats/vcf/vcf_v41.ragel"
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
	goto st39;
st39:
	if ( ++p == pe )
		goto _test_eof39;
case 39:
#line 2128 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto tr65;
		case 58: goto tr64;
		case 95: goto tr64;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr64;
	} else if ( (*p) >= 65 )
		goto tr64;
	goto tr60;
tr65:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
	goto st40;
st40:
	if ( ++p == pe )
		goto _test_eof40;
case 40:
#line 2151 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 68 )
		goto st41;
	goto tr52;
st41:
	if ( ++p == pe )
		goto _test_eof41;
case 41:
	if ( (*p) == 101 )
		goto st42;
	goto tr52;
st42:
	if ( ++p == pe )
		goto _test_eof42;
case 42:
	if ( (*p) == 115 )
		goto st43;
	goto tr52;
st43:
	if ( ++p == pe )
		goto _test_eof43;
case 43:
	if ( (*p) == 99 )
		goto st44;
	goto tr52;
st44:
	if ( ++p == pe )
		goto _test_eof44;
case 44:
	if ( (*p) == 114 )
		goto st45;
	goto tr52;
st45:
	if ( ++p == pe )
		goto _test_eof45;
case 45:
	if ( (*p) == 105 )
		goto st46;
	goto tr52;
st46:
	if ( ++p == pe )
		goto _test_eof46;
case 46:
	if ( (*p) == 112 )
		goto st47;
	goto tr52;
st47:
	if ( ++p == pe )
		goto _test_eof47;
case 47:
	if ( (*p) == 116 )
		goto st48;
	goto tr52;
st48:
	if ( ++p == pe )
		goto _test_eof48;
case 48:
	if ( (*p) == 105 )
		goto st49;
	goto tr52;
st49:
	if ( ++p == pe )
		goto _test_eof49;
case 49:
	if ( (*p) == 111 )
		goto st50;
	goto tr52;
st50:
	if ( ++p == pe )
		goto _test_eof50;
case 50:
	if ( (*p) == 110 )
		goto st51;
	goto tr52;
st51:
	if ( ++p == pe )
		goto _test_eof51;
case 51:
	if ( (*p) == 61 )
		goto st52;
	goto tr52;
st52:
	if ( ++p == pe )
		goto _test_eof52;
case 52:
	if ( (*p) == 34 )
		goto tr78;
	goto tr52;
tr78:
#line 125 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_key(*this, "Description");
    }
	goto st53;
st53:
	if ( ++p == pe )
		goto _test_eof53;
case 53:
#line 2249 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) > 33 ) {
		if ( 35 <= (*p) && (*p) <= 126 )
			goto tr79;
	} else if ( (*p) >= 32 )
		goto tr79;
	goto tr52;
tr79:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st54;
tr81:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st54;
st54:
	if ( ++p == pe )
		goto _test_eof54;
case 54:
#line 2276 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 34 )
		goto tr82;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr81;
	goto tr80;
tr82:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
	goto st55;
st55:
	if ( ++p == pe )
		goto _test_eof55;
case 55:
#line 2293 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto st56;
		case 62: goto st60;
	}
	goto tr80;
st56:
	if ( ++p == pe )
		goto _test_eof56;
case 56:
	if ( (*p) == 95 )
		goto tr86;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr86;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr87;
		} else if ( (*p) >= 65 )
			goto tr87;
	} else
		goto tr87;
	goto tr85;
tr86:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st57;
st57:
	if ( ++p == pe )
		goto _test_eof57;
case 57:
#line 2327 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 95 )
		goto st57;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st57;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr89;
		} else if ( (*p) >= 65 )
			goto tr89;
	} else
		goto tr89;
	goto tr85;
tr87:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st58;
tr89:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st58;
st58:
	if ( ++p == pe )
		goto _test_eof58;
case 58:
#line 2362 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 61: goto tr90;
		case 95: goto tr89;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr89;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr89;
		} else if ( (*p) >= 65 )
			goto tr89;
	} else
		goto tr89;
	goto tr85;
tr90:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
	goto st59;
st59:
	if ( ++p == pe )
		goto _test_eof59;
case 59:
#line 2390 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 34 )
		goto st53;
	goto tr52;
st60:
	if ( ++p == pe )
		goto _test_eof60;
case 60:
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
	goto st61;
st61:
	if ( ++p == pe )
		goto _test_eof61;
case 61:
#line 2415 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 73: goto tr93;
		case 79: goto tr94;
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
	goto tr92;
tr93:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st62;
st62:
	if ( ++p == pe )
		goto _test_eof62;
case 62:
#line 2454 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 76: goto tr96;
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
	goto tr95;
tr96:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st63;
st63:
	if ( ++p == pe )
		goto _test_eof63;
case 63:
#line 2492 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 84: goto tr97;
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
	goto tr95;
tr97:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st64;
st64:
	if ( ++p == pe )
		goto _test_eof64;
case 64:
#line 2530 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 69: goto tr98;
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
	goto tr95;
tr98:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st65;
st65:
	if ( ++p == pe )
		goto _test_eof65;
case 65:
#line 2568 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 82: goto tr99;
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
	goto tr95;
tr99:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st66;
st66:
	if ( ++p == pe )
		goto _test_eof66;
case 66:
#line 2606 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr100;
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
	goto tr95;
tr100:
#line 89 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "FILTER");
    }
	goto st67;
st67:
	if ( ++p == pe )
		goto _test_eof67;
case 67:
#line 2643 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 60 )
		goto st68;
	goto tr95;
st68:
	if ( ++p == pe )
		goto _test_eof68;
case 68:
	if ( (*p) == 73 )
		goto st69;
	goto tr95;
st69:
	if ( ++p == pe )
		goto _test_eof69;
case 69:
	if ( (*p) == 68 )
		goto st70;
	goto tr95;
st70:
	if ( ++p == pe )
		goto _test_eof70;
case 70:
	if ( (*p) == 61 )
		goto st71;
	goto tr95;
st71:
	if ( ++p == pe )
		goto _test_eof71;
case 71:
	if ( (*p) == 95 )
		goto tr106;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr106;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr107;
		} else if ( (*p) >= 65 )
			goto tr107;
	} else
		goto tr107;
	goto tr105;
tr106:
#line 113 "cpp/src/bioformats/vcf/vcf_v41.ragel"
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
#line 2700 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 95 )
		goto st72;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st72;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr109;
		} else if ( (*p) >= 65 )
			goto tr109;
	} else
		goto tr109;
	goto tr105;
tr109:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st73;
tr107:
#line 113 "cpp/src/bioformats/vcf/vcf_v41.ragel"
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
	goto st73;
st73:
	if ( ++p == pe )
		goto _test_eof73;
case 73:
#line 2739 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto tr110;
		case 95: goto tr109;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr109;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr109;
		} else if ( (*p) >= 65 )
			goto tr109;
	} else
		goto tr109;
	goto tr105;
tr110:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
	goto st74;
st74:
	if ( ++p == pe )
		goto _test_eof74;
case 74:
#line 2767 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 68 )
		goto st75;
	goto tr95;
st75:
	if ( ++p == pe )
		goto _test_eof75;
case 75:
	if ( (*p) == 101 )
		goto st76;
	goto tr95;
st76:
	if ( ++p == pe )
		goto _test_eof76;
case 76:
	if ( (*p) == 115 )
		goto st77;
	goto tr95;
st77:
	if ( ++p == pe )
		goto _test_eof77;
case 77:
	if ( (*p) == 99 )
		goto st78;
	goto tr95;
st78:
	if ( ++p == pe )
		goto _test_eof78;
case 78:
	if ( (*p) == 114 )
		goto st79;
	goto tr95;
st79:
	if ( ++p == pe )
		goto _test_eof79;
case 79:
	if ( (*p) == 105 )
		goto st80;
	goto tr95;
st80:
	if ( ++p == pe )
		goto _test_eof80;
case 80:
	if ( (*p) == 112 )
		goto st81;
	goto tr95;
st81:
	if ( ++p == pe )
		goto _test_eof81;
case 81:
	if ( (*p) == 116 )
		goto st82;
	goto tr95;
st82:
	if ( ++p == pe )
		goto _test_eof82;
case 82:
	if ( (*p) == 105 )
		goto st83;
	goto tr95;
st83:
	if ( ++p == pe )
		goto _test_eof83;
case 83:
	if ( (*p) == 111 )
		goto st84;
	goto tr95;
st84:
	if ( ++p == pe )
		goto _test_eof84;
case 84:
	if ( (*p) == 110 )
		goto st85;
	goto tr95;
st85:
	if ( ++p == pe )
		goto _test_eof85;
case 85:
	if ( (*p) == 61 )
		goto st86;
	goto tr95;
st86:
	if ( ++p == pe )
		goto _test_eof86;
case 86:
	if ( (*p) == 34 )
		goto tr123;
	goto tr95;
tr123:
#line 125 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_key(*this, "Description");
    }
	goto st87;
st87:
	if ( ++p == pe )
		goto _test_eof87;
case 87:
#line 2865 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) > 33 ) {
		if ( 35 <= (*p) && (*p) <= 126 )
			goto tr124;
	} else if ( (*p) >= 32 )
		goto tr124;
	goto tr95;
tr124:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st88;
tr126:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st88;
st88:
	if ( ++p == pe )
		goto _test_eof88;
case 88:
#line 2892 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 34 )
		goto tr127;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr126;
	goto tr125;
tr127:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
	goto st89;
st89:
	if ( ++p == pe )
		goto _test_eof89;
case 89:
#line 2909 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto st90;
		case 62: goto st94;
	}
	goto tr125;
st90:
	if ( ++p == pe )
		goto _test_eof90;
case 90:
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
	goto tr105;
tr130:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st91;
st91:
	if ( ++p == pe )
		goto _test_eof91;
case 91:
#line 2943 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 95 )
		goto st91;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st91;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr133;
		} else if ( (*p) >= 65 )
			goto tr133;
	} else
		goto tr133;
	goto tr105;
tr131:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st92;
tr133:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st92;
st92:
	if ( ++p == pe )
		goto _test_eof92;
case 92:
#line 2978 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 61: goto tr134;
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
	goto tr105;
tr134:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
	goto st93;
st93:
	if ( ++p == pe )
		goto _test_eof93;
case 93:
#line 3006 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 34 )
		goto st87;
	goto tr95;
st94:
	if ( ++p == pe )
		goto _test_eof94;
case 94:
	if ( (*p) == 10 )
		goto tr51;
	goto tr95;
tr94:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st95;
st95:
	if ( ++p == pe )
		goto _test_eof95;
case 95:
#line 3027 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 82: goto tr137;
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
	goto tr136;
tr137:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st96;
st96:
	if ( ++p == pe )
		goto _test_eof96;
case 96:
#line 3065 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 77: goto tr138;
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
	goto tr136;
tr138:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st97;
st97:
	if ( ++p == pe )
		goto _test_eof97;
case 97:
#line 3103 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 65: goto tr139;
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
	goto tr136;
tr139:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st98;
st98:
	if ( ++p == pe )
		goto _test_eof98;
case 98:
#line 3141 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 84: goto tr140;
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
	goto tr136;
tr140:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st99;
st99:
	if ( ++p == pe )
		goto _test_eof99;
case 99:
#line 3179 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr141;
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
	goto tr136;
tr141:
#line 93 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "FORMAT");
    }
	goto st100;
st100:
	if ( ++p == pe )
		goto _test_eof100;
case 100:
#line 3216 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 60 )
		goto st101;
	goto tr136;
st101:
	if ( ++p == pe )
		goto _test_eof101;
case 101:
	if ( (*p) == 73 )
		goto st102;
	goto tr136;
st102:
	if ( ++p == pe )
		goto _test_eof102;
case 102:
	if ( (*p) == 68 )
		goto st103;
	goto tr136;
st103:
	if ( ++p == pe )
		goto _test_eof103;
case 103:
	if ( (*p) == 61 )
		goto st104;
	goto tr136;
st104:
	if ( ++p == pe )
		goto _test_eof104;
case 104:
	if ( (*p) == 95 )
		goto tr147;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr147;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr148;
		} else if ( (*p) >= 65 )
			goto tr148;
	} else
		goto tr148;
	goto tr146;
tr147:
#line 113 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_key(*this, "ID");
    }
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st105;
st105:
	if ( ++p == pe )
		goto _test_eof105;
case 105:
#line 3273 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 95 )
		goto st105;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st105;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr150;
		} else if ( (*p) >= 65 )
			goto tr150;
	} else
		goto tr150;
	goto tr146;
tr150:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st106;
tr148:
#line 113 "cpp/src/bioformats/vcf/vcf_v41.ragel"
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
	goto st106;
st106:
	if ( ++p == pe )
		goto _test_eof106;
case 106:
#line 3312 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto tr151;
		case 95: goto tr150;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr150;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr150;
		} else if ( (*p) >= 65 )
			goto tr150;
	} else
		goto tr150;
	goto tr146;
tr151:
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
#line 3340 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 78 )
		goto st108;
	goto tr136;
st108:
	if ( ++p == pe )
		goto _test_eof108;
case 108:
	if ( (*p) == 117 )
		goto st109;
	goto tr136;
st109:
	if ( ++p == pe )
		goto _test_eof109;
case 109:
	if ( (*p) == 109 )
		goto st110;
	goto tr136;
st110:
	if ( ++p == pe )
		goto _test_eof110;
case 110:
	if ( (*p) == 98 )
		goto st111;
	goto tr136;
st111:
	if ( ++p == pe )
		goto _test_eof111;
case 111:
	if ( (*p) == 101 )
		goto st112;
	goto tr136;
st112:
	if ( ++p == pe )
		goto _test_eof112;
case 112:
	if ( (*p) == 114 )
		goto st113;
	goto tr136;
st113:
	if ( ++p == pe )
		goto _test_eof113;
case 113:
	if ( (*p) == 61 )
		goto st114;
	goto tr136;
st114:
	if ( ++p == pe )
		goto _test_eof114;
case 114:
	switch( (*p) ) {
		case 46: goto tr160;
		case 65: goto tr160;
		case 71: goto tr160;
		case 82: goto tr160;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr161;
	goto tr159;
tr160:
#line 117 "cpp/src/bioformats/vcf/vcf_v41.ragel"
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
	goto st115;
st115:
	if ( ++p == pe )
		goto _test_eof115;
case 115:
#line 3417 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 44 )
		goto tr162;
	goto tr159;
tr162:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
	goto st116;
st116:
	if ( ++p == pe )
		goto _test_eof116;
case 116:
#line 3432 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 84 )
		goto st117;
	goto tr136;
st117:
	if ( ++p == pe )
		goto _test_eof117;
case 117:
	if ( (*p) == 121 )
		goto st118;
	goto tr136;
st118:
	if ( ++p == pe )
		goto _test_eof118;
case 118:
	if ( (*p) == 112 )
		goto st119;
	goto tr136;
st119:
	if ( ++p == pe )
		goto _test_eof119;
case 119:
	if ( (*p) == 101 )
		goto st120;
	goto tr136;
st120:
	if ( ++p == pe )
		goto _test_eof120;
case 120:
	if ( (*p) == 61 )
		goto st121;
	goto tr136;
st121:
	if ( ++p == pe )
		goto _test_eof121;
case 121:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr169;
	} else if ( (*p) >= 65 )
		goto tr169;
	goto tr168;
tr171:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st122;
tr169:
#line 121 "cpp/src/bioformats/vcf/vcf_v41.ragel"
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
	goto st122;
st122:
	if ( ++p == pe )
		goto _test_eof122;
case 122:
#line 3498 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 44 )
		goto tr170;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr171;
	} else if ( (*p) >= 65 )
		goto tr171;
	goto tr168;
tr170:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
	goto st123;
st123:
	if ( ++p == pe )
		goto _test_eof123;
case 123:
#line 3518 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 68 )
		goto st124;
	goto tr136;
st124:
	if ( ++p == pe )
		goto _test_eof124;
case 124:
	if ( (*p) == 101 )
		goto st125;
	goto tr136;
st125:
	if ( ++p == pe )
		goto _test_eof125;
case 125:
	if ( (*p) == 115 )
		goto st126;
	goto tr136;
st126:
	if ( ++p == pe )
		goto _test_eof126;
case 126:
	if ( (*p) == 99 )
		goto st127;
	goto tr136;
st127:
	if ( ++p == pe )
		goto _test_eof127;
case 127:
	if ( (*p) == 114 )
		goto st128;
	goto tr136;
st128:
	if ( ++p == pe )
		goto _test_eof128;
case 128:
	if ( (*p) == 105 )
		goto st129;
	goto tr136;
st129:
	if ( ++p == pe )
		goto _test_eof129;
case 129:
	if ( (*p) == 112 )
		goto st130;
	goto tr136;
st130:
	if ( ++p == pe )
		goto _test_eof130;
case 130:
	if ( (*p) == 116 )
		goto st131;
	goto tr136;
st131:
	if ( ++p == pe )
		goto _test_eof131;
case 131:
	if ( (*p) == 105 )
		goto st132;
	goto tr136;
st132:
	if ( ++p == pe )
		goto _test_eof132;
case 132:
	if ( (*p) == 111 )
		goto st133;
	goto tr136;
st133:
	if ( ++p == pe )
		goto _test_eof133;
case 133:
	if ( (*p) == 110 )
		goto st134;
	goto tr136;
st134:
	if ( ++p == pe )
		goto _test_eof134;
case 134:
	if ( (*p) == 61 )
		goto st135;
	goto tr136;
st135:
	if ( ++p == pe )
		goto _test_eof135;
case 135:
	if ( (*p) == 34 )
		goto tr184;
	goto tr136;
tr184:
#line 125 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_key(*this, "Description");
    }
	goto st136;
st136:
	if ( ++p == pe )
		goto _test_eof136;
case 136:
#line 3616 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) > 33 ) {
		if ( 35 <= (*p) && (*p) <= 126 )
			goto tr185;
	} else if ( (*p) >= 32 )
		goto tr185;
	goto tr136;
tr185:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st137;
tr187:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st137;
st137:
	if ( ++p == pe )
		goto _test_eof137;
case 137:
#line 3643 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 34 )
		goto tr188;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr187;
	goto tr186;
tr188:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
	goto st138;
st138:
	if ( ++p == pe )
		goto _test_eof138;
case 138:
#line 3660 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto st139;
		case 62: goto st143;
	}
	goto tr186;
st139:
	if ( ++p == pe )
		goto _test_eof139;
case 139:
	if ( (*p) == 95 )
		goto tr191;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr191;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr192;
		} else if ( (*p) >= 65 )
			goto tr192;
	} else
		goto tr192;
	goto tr146;
tr191:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st140;
st140:
	if ( ++p == pe )
		goto _test_eof140;
case 140:
#line 3694 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 95 )
		goto st140;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st140;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr194;
		} else if ( (*p) >= 65 )
			goto tr194;
	} else
		goto tr194;
	goto tr146;
tr192:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st141;
tr194:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st141;
st141:
	if ( ++p == pe )
		goto _test_eof141;
case 141:
#line 3729 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 61: goto tr195;
		case 95: goto tr194;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr194;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr194;
		} else if ( (*p) >= 65 )
			goto tr194;
	} else
		goto tr194;
	goto tr146;
tr195:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
	goto st142;
st142:
	if ( ++p == pe )
		goto _test_eof142;
case 142:
#line 3757 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 34 )
		goto st136;
	goto tr136;
st143:
	if ( ++p == pe )
		goto _test_eof143;
case 143:
	if ( (*p) == 10 )
		goto tr51;
	goto tr136;
tr197:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st144;
tr161:
#line 117 "cpp/src/bioformats/vcf/vcf_v41.ragel"
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
	goto st144;
st144:
	if ( ++p == pe )
		goto _test_eof144;
case 144:
#line 3792 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 44 )
		goto tr162;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr197;
	goto tr159;
tr28:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st145;
st145:
	if ( ++p == pe )
		goto _test_eof145;
case 145:
#line 3812 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 78: goto tr199;
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
	goto tr198;
tr199:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st146;
st146:
	if ( ++p == pe )
		goto _test_eof146;
case 146:
#line 3850 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 70: goto tr200;
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
	goto tr198;
tr200:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st147;
st147:
	if ( ++p == pe )
		goto _test_eof147;
case 147:
#line 3888 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 79: goto tr201;
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
	goto tr198;
tr201:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st148;
st148:
	if ( ++p == pe )
		goto _test_eof148;
case 148:
#line 3926 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr202;
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
	goto tr198;
tr202:
#line 97 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "INFO");
    }
	goto st149;
st149:
	if ( ++p == pe )
		goto _test_eof149;
case 149:
#line 3963 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 60 )
		goto st150;
	goto tr198;
st150:
	if ( ++p == pe )
		goto _test_eof150;
case 150:
	if ( (*p) == 73 )
		goto st151;
	goto tr198;
st151:
	if ( ++p == pe )
		goto _test_eof151;
case 151:
	if ( (*p) == 68 )
		goto st152;
	goto tr198;
st152:
	if ( ++p == pe )
		goto _test_eof152;
case 152:
	if ( (*p) == 61 )
		goto st153;
	goto tr198;
st153:
	if ( ++p == pe )
		goto _test_eof153;
case 153:
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
#line 113 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_key(*this, "ID");
    }
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st154;
st154:
	if ( ++p == pe )
		goto _test_eof154;
case 154:
#line 4020 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 95 )
		goto st154;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st154;
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
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st155;
tr209:
#line 113 "cpp/src/bioformats/vcf/vcf_v41.ragel"
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
	goto st155;
st155:
	if ( ++p == pe )
		goto _test_eof155;
case 155:
#line 4059 "cpp/src/bioformats/vcf/validator_detail.hpp"
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
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
	goto st156;
st156:
	if ( ++p == pe )
		goto _test_eof156;
case 156:
#line 4087 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 78 )
		goto st157;
	goto tr198;
st157:
	if ( ++p == pe )
		goto _test_eof157;
case 157:
	if ( (*p) == 117 )
		goto st158;
	goto tr198;
st158:
	if ( ++p == pe )
		goto _test_eof158;
case 158:
	if ( (*p) == 109 )
		goto st159;
	goto tr198;
st159:
	if ( ++p == pe )
		goto _test_eof159;
case 159:
	if ( (*p) == 98 )
		goto st160;
	goto tr198;
st160:
	if ( ++p == pe )
		goto _test_eof160;
case 160:
	if ( (*p) == 101 )
		goto st161;
	goto tr198;
st161:
	if ( ++p == pe )
		goto _test_eof161;
case 161:
	if ( (*p) == 114 )
		goto st162;
	goto tr198;
st162:
	if ( ++p == pe )
		goto _test_eof162;
case 162:
	if ( (*p) == 61 )
		goto st163;
	goto tr198;
st163:
	if ( ++p == pe )
		goto _test_eof163;
case 163:
	switch( (*p) ) {
		case 46: goto tr221;
		case 65: goto tr221;
		case 71: goto tr221;
		case 82: goto tr221;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr222;
	goto tr220;
tr221:
#line 117 "cpp/src/bioformats/vcf/vcf_v41.ragel"
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
	goto st164;
st164:
	if ( ++p == pe )
		goto _test_eof164;
case 164:
#line 4164 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 44 )
		goto tr223;
	goto tr220;
tr223:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
	goto st165;
st165:
	if ( ++p == pe )
		goto _test_eof165;
case 165:
#line 4179 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 84 )
		goto st166;
	goto tr198;
st166:
	if ( ++p == pe )
		goto _test_eof166;
case 166:
	if ( (*p) == 121 )
		goto st167;
	goto tr198;
st167:
	if ( ++p == pe )
		goto _test_eof167;
case 167:
	if ( (*p) == 112 )
		goto st168;
	goto tr198;
st168:
	if ( ++p == pe )
		goto _test_eof168;
case 168:
	if ( (*p) == 101 )
		goto st169;
	goto tr198;
st169:
	if ( ++p == pe )
		goto _test_eof169;
case 169:
	if ( (*p) == 61 )
		goto st170;
	goto tr198;
st170:
	if ( ++p == pe )
		goto _test_eof170;
case 170:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr230;
	} else if ( (*p) >= 65 )
		goto tr230;
	goto tr229;
tr232:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st171;
tr230:
#line 121 "cpp/src/bioformats/vcf/vcf_v41.ragel"
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
	goto st171;
st171:
	if ( ++p == pe )
		goto _test_eof171;
case 171:
#line 4245 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 44 )
		goto tr231;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else if ( (*p) >= 65 )
		goto tr232;
	goto tr229;
tr231:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
	goto st172;
st172:
	if ( ++p == pe )
		goto _test_eof172;
case 172:
#line 4265 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 68 )
		goto st173;
	goto tr198;
st173:
	if ( ++p == pe )
		goto _test_eof173;
case 173:
	if ( (*p) == 101 )
		goto st174;
	goto tr198;
st174:
	if ( ++p == pe )
		goto _test_eof174;
case 174:
	if ( (*p) == 115 )
		goto st175;
	goto tr198;
st175:
	if ( ++p == pe )
		goto _test_eof175;
case 175:
	if ( (*p) == 99 )
		goto st176;
	goto tr198;
st176:
	if ( ++p == pe )
		goto _test_eof176;
case 176:
	if ( (*p) == 114 )
		goto st177;
	goto tr198;
st177:
	if ( ++p == pe )
		goto _test_eof177;
case 177:
	if ( (*p) == 105 )
		goto st178;
	goto tr198;
st178:
	if ( ++p == pe )
		goto _test_eof178;
case 178:
	if ( (*p) == 112 )
		goto st179;
	goto tr198;
st179:
	if ( ++p == pe )
		goto _test_eof179;
case 179:
	if ( (*p) == 116 )
		goto st180;
	goto tr198;
st180:
	if ( ++p == pe )
		goto _test_eof180;
case 180:
	if ( (*p) == 105 )
		goto st181;
	goto tr198;
st181:
	if ( ++p == pe )
		goto _test_eof181;
case 181:
	if ( (*p) == 111 )
		goto st182;
	goto tr198;
st182:
	if ( ++p == pe )
		goto _test_eof182;
case 182:
	if ( (*p) == 110 )
		goto st183;
	goto tr198;
st183:
	if ( ++p == pe )
		goto _test_eof183;
case 183:
	if ( (*p) == 61 )
		goto st184;
	goto tr198;
st184:
	if ( ++p == pe )
		goto _test_eof184;
case 184:
	if ( (*p) == 34 )
		goto tr245;
	goto tr198;
tr245:
#line 125 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_key(*this, "Description");
    }
	goto st185;
st185:
	if ( ++p == pe )
		goto _test_eof185;
case 185:
#line 4363 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) > 33 ) {
		if ( 35 <= (*p) && (*p) <= 126 )
			goto tr246;
	} else if ( (*p) >= 32 )
		goto tr246;
	goto tr198;
tr246:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st186;
tr248:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st186;
st186:
	if ( ++p == pe )
		goto _test_eof186;
case 186:
#line 4390 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 34 )
		goto tr249;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr248;
	goto tr247;
tr249:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
	goto st187;
st187:
	if ( ++p == pe )
		goto _test_eof187;
case 187:
#line 4407 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto st188;
		case 62: goto st192;
	}
	goto tr247;
st188:
	if ( ++p == pe )
		goto _test_eof188;
case 188:
	if ( (*p) == 95 )
		goto tr252;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr252;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr253;
		} else if ( (*p) >= 65 )
			goto tr253;
	} else
		goto tr253;
	goto tr207;
tr252:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st189;
st189:
	if ( ++p == pe )
		goto _test_eof189;
case 189:
#line 4441 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 95 )
		goto st189;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st189;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr255;
		} else if ( (*p) >= 65 )
			goto tr255;
	} else
		goto tr255;
	goto tr207;
tr253:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st190;
tr255:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st190;
st190:
	if ( ++p == pe )
		goto _test_eof190;
case 190:
#line 4476 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 61: goto tr256;
		case 95: goto tr255;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr255;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr255;
		} else if ( (*p) >= 65 )
			goto tr255;
	} else
		goto tr255;
	goto tr207;
tr256:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
	goto st191;
st191:
	if ( ++p == pe )
		goto _test_eof191;
case 191:
#line 4504 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 34 )
		goto st185;
	goto tr198;
st192:
	if ( ++p == pe )
		goto _test_eof192;
case 192:
	if ( (*p) == 10 )
		goto tr51;
	goto tr198;
tr258:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st193;
tr222:
#line 117 "cpp/src/bioformats/vcf/vcf_v41.ragel"
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
	goto st193;
st193:
	if ( ++p == pe )
		goto _test_eof193;
case 193:
#line 4539 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 44 )
		goto tr223;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr258;
	goto tr220;
tr29:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st194;
st194:
	if ( ++p == pe )
		goto _test_eof194;
case 194:
#line 4559 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 69: goto tr260;
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
	goto tr259;
tr260:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st195;
st195:
	if ( ++p == pe )
		goto _test_eof195;
case 195:
#line 4597 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 68: goto tr261;
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
	goto tr259;
tr261:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st196;
st196:
	if ( ++p == pe )
		goto _test_eof196;
case 196:
#line 4635 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 73: goto tr262;
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
	goto tr259;
tr262:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st197;
st197:
	if ( ++p == pe )
		goto _test_eof197;
case 197:
#line 4673 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 71: goto tr263;
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
	goto tr259;
tr263:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st198;
st198:
	if ( ++p == pe )
		goto _test_eof198;
case 198:
#line 4711 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 82: goto tr264;
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
	goto tr259;
tr264:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st199;
st199:
	if ( ++p == pe )
		goto _test_eof199;
case 199:
#line 4749 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 69: goto tr265;
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
	goto tr259;
tr265:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st200;
st200:
	if ( ++p == pe )
		goto _test_eof200;
case 200:
#line 4787 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 69: goto tr266;
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
	goto tr259;
tr266:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st201;
st201:
	if ( ++p == pe )
		goto _test_eof201;
case 201:
#line 4825 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr267;
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
	goto tr259;
tr267:
#line 101 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "PEDIGREE");
    }
	goto st202;
st202:
	if ( ++p == pe )
		goto _test_eof202;
case 202:
#line 4862 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 60 )
		goto st203;
	goto tr259;
tr279:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
	goto st203;
st203:
	if ( ++p == pe )
		goto _test_eof203;
case 203:
#line 4877 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 95 )
		goto tr270;
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
	goto tr269;
tr270:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st204;
st204:
	if ( ++p == pe )
		goto _test_eof204;
case 204:
#line 4902 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 95 )
		goto st204;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st204;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr273;
		} else if ( (*p) >= 65 )
			goto tr273;
	} else
		goto tr273;
	goto tr269;
tr271:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st205;
tr273:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st205;
st205:
	if ( ++p == pe )
		goto _test_eof205;
case 205:
#line 4937 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
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
	goto tr269;
tr274:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
	goto st206;
st206:
	if ( ++p == pe )
		goto _test_eof206;
case 206:
#line 4965 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 95 )
		goto tr275;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr275;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr276;
		} else if ( (*p) >= 65 )
			goto tr276;
	} else
		goto tr276;
	goto tr269;
tr275:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st207;
st207:
	if ( ++p == pe )
		goto _test_eof207;
case 207:
#line 4990 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 95 )
		goto st207;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st207;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr278;
		} else if ( (*p) >= 65 )
			goto tr278;
	} else
		goto tr278;
	goto tr269;
tr276:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st208;
tr278:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st208;
st208:
	if ( ++p == pe )
		goto _test_eof208;
case 208:
#line 5025 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto tr279;
		case 62: goto tr280;
		case 95: goto tr278;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr278;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr278;
		} else if ( (*p) >= 65 )
			goto tr278;
	} else
		goto tr278;
	goto tr269;
tr280:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
	goto st209;
st209:
	if ( ++p == pe )
		goto _test_eof209;
case 209:
#line 5054 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 10 )
		goto tr51;
	goto tr259;
tr30:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st210;
st210:
	if ( ++p == pe )
		goto _test_eof210;
case 210:
#line 5072 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 65: goto tr282;
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
	goto tr281;
tr282:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st211;
st211:
	if ( ++p == pe )
		goto _test_eof211;
case 211:
#line 5110 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 77: goto tr283;
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
	goto tr281;
tr283:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st212;
st212:
	if ( ++p == pe )
		goto _test_eof212;
case 212:
#line 5148 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 80: goto tr284;
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
	goto tr281;
tr284:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st213;
st213:
	if ( ++p == pe )
		goto _test_eof213;
case 213:
#line 5186 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 76: goto tr285;
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
	goto tr281;
tr285:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st214;
st214:
	if ( ++p == pe )
		goto _test_eof214;
case 214:
#line 5224 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 69: goto tr286;
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
	goto tr281;
tr286:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st215;
st215:
	if ( ++p == pe )
		goto _test_eof215;
case 215:
#line 5262 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr287;
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
	goto tr281;
tr287:
#line 109 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "SAMPLE");
    }
	goto st216;
st216:
	if ( ++p == pe )
		goto _test_eof216;
case 216:
#line 5299 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 60 )
		goto st217;
	goto tr281;
st217:
	if ( ++p == pe )
		goto _test_eof217;
case 217:
	if ( (*p) == 73 )
		goto st218;
	goto tr281;
st218:
	if ( ++p == pe )
		goto _test_eof218;
case 218:
	if ( (*p) == 68 )
		goto st219;
	goto tr281;
st219:
	if ( ++p == pe )
		goto _test_eof219;
case 219:
	if ( (*p) == 61 )
		goto st220;
	goto tr281;
st220:
	if ( ++p == pe )
		goto _test_eof220;
case 220:
	if ( (*p) == 95 )
		goto tr293;
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
	goto tr292;
tr293:
#line 113 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_key(*this, "ID");
    }
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st221;
st221:
	if ( ++p == pe )
		goto _test_eof221;
case 221:
#line 5356 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 95 )
		goto st221;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st221;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr296;
		} else if ( (*p) >= 65 )
			goto tr296;
	} else
		goto tr296;
	goto tr292;
tr296:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st222;
tr294:
#line 113 "cpp/src/bioformats/vcf/vcf_v41.ragel"
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
	goto st222;
st222:
	if ( ++p == pe )
		goto _test_eof222;
case 222:
#line 5395 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto tr298;
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
	goto tr297;
tr298:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
	goto st223;
st223:
	if ( ++p == pe )
		goto _test_eof223;
case 223:
#line 5423 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 71 )
		goto st224;
	goto tr299;
st224:
	if ( ++p == pe )
		goto _test_eof224;
case 224:
	if ( (*p) == 101 )
		goto st225;
	goto tr299;
st225:
	if ( ++p == pe )
		goto _test_eof225;
case 225:
	if ( (*p) == 110 )
		goto st226;
	goto tr299;
st226:
	if ( ++p == pe )
		goto _test_eof226;
case 226:
	if ( (*p) == 111 )
		goto st227;
	goto tr299;
st227:
	if ( ++p == pe )
		goto _test_eof227;
case 227:
	if ( (*p) == 109 )
		goto st228;
	goto tr299;
st228:
	if ( ++p == pe )
		goto _test_eof228;
case 228:
	if ( (*p) == 101 )
		goto st229;
	goto tr299;
st229:
	if ( ++p == pe )
		goto _test_eof229;
case 229:
	if ( (*p) == 115 )
		goto st230;
	goto tr299;
st230:
	if ( ++p == pe )
		goto _test_eof230;
case 230:
	if ( (*p) == 61 )
		goto st231;
	goto tr299;
st231:
	if ( ++p == pe )
		goto _test_eof231;
case 231:
	if ( (*p) < 45 ) {
		if ( 32 <= (*p) && (*p) <= 43 )
			goto tr308;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr308;
	} else
		goto tr308;
	goto tr299;
tr310:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st232;
tr308:
#line 129 "cpp/src/bioformats/vcf/vcf_v41.ragel"
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
	goto st232;
st232:
	if ( ++p == pe )
		goto _test_eof232;
case 232:
#line 5513 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 44 )
		goto tr311;
	if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr310;
	} else if ( (*p) >= 32 )
		goto tr310;
	goto tr309;
tr311:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
	goto st233;
st233:
	if ( ++p == pe )
		goto _test_eof233;
case 233:
#line 5533 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 77 )
		goto st234;
	goto tr312;
st234:
	if ( ++p == pe )
		goto _test_eof234;
case 234:
	if ( (*p) == 105 )
		goto st235;
	goto tr312;
st235:
	if ( ++p == pe )
		goto _test_eof235;
case 235:
	if ( (*p) == 120 )
		goto st236;
	goto tr312;
st236:
	if ( ++p == pe )
		goto _test_eof236;
case 236:
	if ( (*p) == 116 )
		goto st237;
	goto tr312;
st237:
	if ( ++p == pe )
		goto _test_eof237;
case 237:
	if ( (*p) == 117 )
		goto st238;
	goto tr312;
st238:
	if ( ++p == pe )
		goto _test_eof238;
case 238:
	if ( (*p) == 114 )
		goto st239;
	goto tr312;
st239:
	if ( ++p == pe )
		goto _test_eof239;
case 239:
	if ( (*p) == 101 )
		goto st240;
	goto tr312;
st240:
	if ( ++p == pe )
		goto _test_eof240;
case 240:
	if ( (*p) == 61 )
		goto st241;
	goto tr312;
st241:
	if ( ++p == pe )
		goto _test_eof241;
case 241:
	if ( (*p) < 45 ) {
		if ( 32 <= (*p) && (*p) <= 43 )
			goto tr321;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr321;
	} else
		goto tr321;
	goto tr312;
tr323:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st242;
tr321:
#line 133 "cpp/src/bioformats/vcf/vcf_v41.ragel"
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
	goto st242;
st242:
	if ( ++p == pe )
		goto _test_eof242;
case 242:
#line 5623 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 44 )
		goto tr324;
	if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr323;
	} else if ( (*p) >= 32 )
		goto tr323;
	goto tr322;
tr324:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
	goto st243;
st243:
	if ( ++p == pe )
		goto _test_eof243;
case 243:
#line 5643 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 68 )
		goto st244;
	goto tr325;
st244:
	if ( ++p == pe )
		goto _test_eof244;
case 244:
	if ( (*p) == 101 )
		goto st245;
	goto tr325;
st245:
	if ( ++p == pe )
		goto _test_eof245;
case 245:
	if ( (*p) == 115 )
		goto st246;
	goto tr325;
st246:
	if ( ++p == pe )
		goto _test_eof246;
case 246:
	if ( (*p) == 99 )
		goto st247;
	goto tr325;
st247:
	if ( ++p == pe )
		goto _test_eof247;
case 247:
	if ( (*p) == 114 )
		goto st248;
	goto tr325;
st248:
	if ( ++p == pe )
		goto _test_eof248;
case 248:
	if ( (*p) == 105 )
		goto st249;
	goto tr325;
st249:
	if ( ++p == pe )
		goto _test_eof249;
case 249:
	if ( (*p) == 112 )
		goto st250;
	goto tr325;
st250:
	if ( ++p == pe )
		goto _test_eof250;
case 250:
	if ( (*p) == 116 )
		goto st251;
	goto tr325;
st251:
	if ( ++p == pe )
		goto _test_eof251;
case 251:
	if ( (*p) == 105 )
		goto st252;
	goto tr325;
st252:
	if ( ++p == pe )
		goto _test_eof252;
case 252:
	if ( (*p) == 111 )
		goto st253;
	goto tr325;
st253:
	if ( ++p == pe )
		goto _test_eof253;
case 253:
	if ( (*p) == 110 )
		goto st254;
	goto tr325;
st254:
	if ( ++p == pe )
		goto _test_eof254;
case 254:
	if ( (*p) == 61 )
		goto st255;
	goto tr325;
st255:
	if ( ++p == pe )
		goto _test_eof255;
case 255:
	if ( (*p) == 34 )
		goto tr338;
	goto tr325;
tr338:
#line 125 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_key(*this, "Description");
    }
	goto st256;
st256:
	if ( ++p == pe )
		goto _test_eof256;
case 256:
#line 5741 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) > 33 ) {
		if ( 35 <= (*p) && (*p) <= 126 )
			goto tr339;
	} else if ( (*p) >= 32 )
		goto tr339;
	goto tr325;
tr339:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st257;
tr340:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st257;
st257:
	if ( ++p == pe )
		goto _test_eof257;
case 257:
#line 5768 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 34 )
		goto tr341;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr340;
	goto tr325;
tr341:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
	goto st258;
st258:
	if ( ++p == pe )
		goto _test_eof258;
case 258:
#line 5785 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 62 )
		goto st259;
	goto tr325;
st259:
	if ( ++p == pe )
		goto _test_eof259;
case 259:
	if ( (*p) == 10 )
		goto tr51;
	goto tr281;
tr31:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st260;
st260:
	if ( ++p == pe )
		goto _test_eof260;
case 260:
#line 5810 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 95: goto tr37;
		case 115: goto tr344;
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
	goto tr343;
tr344:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st261;
st261:
	if ( ++p == pe )
		goto _test_eof261;
case 261:
#line 5848 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 95: goto tr37;
		case 115: goto tr345;
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
	goto tr343;
tr345:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st262;
st262:
	if ( ++p == pe )
		goto _test_eof262;
case 262:
#line 5886 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 95: goto tr37;
		case 101: goto tr346;
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
	goto tr343;
tr346:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st263;
st263:
	if ( ++p == pe )
		goto _test_eof263;
case 263:
#line 5924 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 95: goto tr37;
		case 109: goto tr347;
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
	goto tr343;
tr347:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st264;
st264:
	if ( ++p == pe )
		goto _test_eof264;
case 264:
#line 5962 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 95: goto tr37;
		case 98: goto tr348;
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
	goto tr343;
tr348:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st265;
st265:
	if ( ++p == pe )
		goto _test_eof265;
case 265:
#line 6000 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 95: goto tr37;
		case 108: goto tr349;
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
	goto tr343;
tr349:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st266;
st266:
	if ( ++p == pe )
		goto _test_eof266;
case 266:
#line 6038 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 95: goto tr37;
		case 121: goto tr350;
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
	goto tr343;
tr350:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st267;
st267:
	if ( ++p == pe )
		goto _test_eof267;
case 267:
#line 6076 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr351;
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
	goto tr343;
tr351:
#line 81 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "assembly");
    }
	goto st268;
st268:
	if ( ++p == pe )
		goto _test_eof268;
case 268:
#line 6113 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr353;
	} else if ( (*p) >= 65 )
		goto tr353;
	goto tr352;
tr353:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st269;
st269:
	if ( ++p == pe )
		goto _test_eof269;
case 269:
#line 6130 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr352;
		case 35: goto tr352;
		case 47: goto tr352;
		case 58: goto tr352;
		case 63: goto tr352;
	}
	goto st270;
st270:
	if ( ++p == pe )
		goto _test_eof270;
case 270:
	switch( (*p) ) {
		case 10: goto tr352;
		case 35: goto tr352;
		case 47: goto tr352;
		case 58: goto st271;
		case 63: goto tr352;
	}
	goto st270;
st271:
	if ( ++p == pe )
		goto _test_eof271;
case 271:
	if ( (*p) == 47 )
		goto st272;
	goto tr352;
st272:
	if ( ++p == pe )
		goto _test_eof272;
case 272:
	if ( (*p) == 47 )
		goto st273;
	goto tr352;
st273:
	if ( ++p == pe )
		goto _test_eof273;
case 273:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr358;
	} else if ( (*p) >= 65 )
		goto tr358;
	goto tr352;
tr358:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st274;
st274:
	if ( ++p == pe )
		goto _test_eof274;
case 274:
#line 6185 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 10 )
		goto tr35;
	goto tr358;
tr32:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st275;
st275:
	if ( ++p == pe )
		goto _test_eof275;
case 275:
#line 6203 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 95: goto tr37;
		case 111: goto tr360;
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
	goto tr359;
tr360:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st276;
st276:
	if ( ++p == pe )
		goto _test_eof276;
case 276:
#line 6241 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 95: goto tr37;
		case 110: goto tr361;
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
	goto tr359;
tr361:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st277;
st277:
	if ( ++p == pe )
		goto _test_eof277;
case 277:
#line 6279 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 95: goto tr37;
		case 116: goto tr362;
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
	goto tr359;
tr362:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st278;
st278:
	if ( ++p == pe )
		goto _test_eof278;
case 278:
#line 6317 "cpp/src/bioformats/vcf/validator_detail.hpp"
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
	goto tr359;
tr363:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st279;
st279:
	if ( ++p == pe )
		goto _test_eof279;
case 279:
#line 6355 "cpp/src/bioformats/vcf/validator_detail.hpp"
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
	goto tr359;
tr364:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st280;
st280:
	if ( ++p == pe )
		goto _test_eof280;
case 280:
#line 6393 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr365;
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
	goto tr359;
tr365:
#line 85 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "contig");
    }
	goto st281;
st281:
	if ( ++p == pe )
		goto _test_eof281;
case 281:
#line 6430 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 60 )
		goto st282;
	goto tr359;
st282:
	if ( ++p == pe )
		goto _test_eof282;
case 282:
	if ( (*p) == 73 )
		goto st283;
	goto tr359;
st283:
	if ( ++p == pe )
		goto _test_eof283;
case 283:
	if ( (*p) == 68 )
		goto st284;
	goto tr359;
st284:
	if ( ++p == pe )
		goto _test_eof284;
case 284:
	if ( (*p) == 61 )
		goto st285;
	goto tr359;
st285:
	if ( ++p == pe )
		goto _test_eof285;
case 285:
	if ( (*p) == 95 )
		goto tr371;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr371;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr372;
		} else if ( (*p) >= 65 )
			goto tr372;
	} else
		goto tr372;
	goto tr370;
tr371:
#line 113 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_key(*this, "ID");
    }
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st286;
st286:
	if ( ++p == pe )
		goto _test_eof286;
case 286:
#line 6487 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 95 )
		goto st286;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st286;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr374;
		} else if ( (*p) >= 65 )
			goto tr374;
	} else
		goto tr374;
	goto tr370;
tr374:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st287;
tr372:
#line 113 "cpp/src/bioformats/vcf/vcf_v41.ragel"
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
	goto st287;
st287:
	if ( ++p == pe )
		goto _test_eof287;
case 287:
#line 6526 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto tr375;
		case 62: goto tr376;
		case 95: goto tr374;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr374;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr374;
		} else if ( (*p) >= 65 )
			goto tr374;
	} else
		goto tr374;
	goto tr370;
tr375:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
	goto st288;
st288:
	if ( ++p == pe )
		goto _test_eof288;
case 288:
#line 6555 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 95 )
		goto tr377;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr377;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr378;
		} else if ( (*p) >= 65 )
			goto tr378;
	} else
		goto tr378;
	goto tr359;
tr377:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st289;
st289:
	if ( ++p == pe )
		goto _test_eof289;
case 289:
#line 6580 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 95 )
		goto st289;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st289;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr380;
		} else if ( (*p) >= 65 )
			goto tr380;
	} else
		goto tr380;
	goto tr359;
tr378:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st290;
tr380:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st290;
st290:
	if ( ++p == pe )
		goto _test_eof290;
case 290:
#line 6615 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 61: goto tr381;
		case 95: goto tr380;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr380;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr380;
		} else if ( (*p) >= 65 )
			goto tr380;
	} else
		goto tr380;
	goto tr359;
tr381:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
	goto st291;
st291:
	if ( ++p == pe )
		goto _test_eof291;
case 291:
#line 6643 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) < 45 ) {
		if ( 32 <= (*p) && (*p) <= 43 )
			goto tr382;
	} else if ( (*p) > 61 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr382;
	} else
		goto tr382;
	goto tr359;
tr382:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st292;
tr383:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st292;
st292:
	if ( ++p == pe )
		goto _test_eof292;
case 292:
#line 6673 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto tr375;
		case 62: goto tr376;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr383;
	goto tr359;
tr376:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
	goto st293;
st293:
	if ( ++p == pe )
		goto _test_eof293;
case 293:
#line 6692 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 10 )
		goto tr51;
	goto tr359;
tr33:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st294;
st294:
	if ( ++p == pe )
		goto _test_eof294;
case 294:
#line 6710 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 95: goto tr37;
		case 101: goto tr385;
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
	goto tr384;
tr385:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st295;
st295:
	if ( ++p == pe )
		goto _test_eof295;
case 295:
#line 6748 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 95: goto tr37;
		case 100: goto tr386;
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
	goto tr384;
tr386:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st296;
st296:
	if ( ++p == pe )
		goto _test_eof296;
case 296:
#line 6786 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 95: goto tr37;
		case 105: goto tr387;
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
	goto tr384;
tr387:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st297;
st297:
	if ( ++p == pe )
		goto _test_eof297;
case 297:
#line 6824 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 95: goto tr37;
		case 103: goto tr388;
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
	goto tr384;
tr388:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st298;
st298:
	if ( ++p == pe )
		goto _test_eof298;
case 298:
#line 6862 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 95: goto tr37;
		case 114: goto tr389;
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
	goto tr384;
tr389:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st299;
st299:
	if ( ++p == pe )
		goto _test_eof299;
case 299:
#line 6900 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 95: goto tr37;
		case 101: goto tr390;
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
	goto tr384;
tr390:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st300;
st300:
	if ( ++p == pe )
		goto _test_eof300;
case 300:
#line 6938 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 95: goto tr37;
		case 101: goto tr391;
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
	goto tr384;
tr391:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st301;
st301:
	if ( ++p == pe )
		goto _test_eof301;
case 301:
#line 6976 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 68: goto tr392;
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
	goto tr384;
tr392:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st302;
st302:
	if ( ++p == pe )
		goto _test_eof302;
case 302:
#line 7014 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr38;
		case 66: goto tr393;
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
	goto tr384;
tr393:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st303;
st303:
	if ( ++p == pe )
		goto _test_eof303;
case 303:
#line 7052 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr35;
		case 61: goto tr394;
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
	goto tr384;
tr394:
#line 105 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_meta_typeid(*this, "pedigreeDB");
    }
	goto st304;
st304:
	if ( ++p == pe )
		goto _test_eof304;
case 304:
#line 7089 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 60 )
		goto st305;
	goto tr384;
st305:
	if ( ++p == pe )
		goto _test_eof305;
case 305:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr397;
	} else if ( (*p) >= 65 )
		goto tr397;
	goto tr396;
tr397:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st306;
st306:
	if ( ++p == pe )
		goto _test_eof306;
case 306:
#line 7113 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr396;
		case 35: goto tr396;
		case 47: goto tr396;
		case 58: goto tr396;
		case 63: goto tr396;
	}
	goto st307;
st307:
	if ( ++p == pe )
		goto _test_eof307;
case 307:
	switch( (*p) ) {
		case 10: goto tr396;
		case 35: goto tr396;
		case 47: goto tr396;
		case 58: goto st308;
		case 63: goto tr396;
	}
	goto st307;
st308:
	if ( ++p == pe )
		goto _test_eof308;
case 308:
	if ( (*p) == 47 )
		goto st309;
	goto tr396;
st309:
	if ( ++p == pe )
		goto _test_eof309;
case 309:
	if ( (*p) == 47 )
		goto st310;
	goto tr396;
st310:
	if ( ++p == pe )
		goto _test_eof310;
case 310:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr402;
	} else if ( (*p) >= 65 )
		goto tr402;
	goto tr396;
tr402:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st311;
st311:
	if ( ++p == pe )
		goto _test_eof311;
case 311:
#line 7168 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr396;
		case 62: goto tr403;
	}
	goto tr402;
tr403:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
	goto st312;
st312:
	if ( ++p == pe )
		goto _test_eof312;
case 312:
#line 7189 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr51;
		case 62: goto tr403;
	}
	goto tr402;
st313:
	if ( ++p == pe )
		goto _test_eof313;
case 313:
	if ( (*p) == 72 )
		goto st314;
	goto tr404;
st314:
	if ( ++p == pe )
		goto _test_eof314;
case 314:
	if ( (*p) == 82 )
		goto st315;
	goto tr404;
st315:
	if ( ++p == pe )
		goto _test_eof315;
case 315:
	if ( (*p) == 79 )
		goto st316;
	goto tr404;
st316:
	if ( ++p == pe )
		goto _test_eof316;
case 316:
	if ( (*p) == 77 )
		goto st317;
	goto tr404;
st317:
	if ( ++p == pe )
		goto _test_eof317;
case 317:
	if ( (*p) == 9 )
		goto st318;
	goto tr404;
st318:
	if ( ++p == pe )
		goto _test_eof318;
case 318:
	if ( (*p) == 80 )
		goto st319;
	goto tr404;
st319:
	if ( ++p == pe )
		goto _test_eof319;
case 319:
	if ( (*p) == 79 )
		goto st320;
	goto tr404;
st320:
	if ( ++p == pe )
		goto _test_eof320;
case 320:
	if ( (*p) == 83 )
		goto st321;
	goto tr404;
st321:
	if ( ++p == pe )
		goto _test_eof321;
case 321:
	if ( (*p) == 9 )
		goto st322;
	goto tr404;
st322:
	if ( ++p == pe )
		goto _test_eof322;
case 322:
	if ( (*p) == 73 )
		goto st323;
	goto tr404;
st323:
	if ( ++p == pe )
		goto _test_eof323;
case 323:
	if ( (*p) == 68 )
		goto st324;
	goto tr404;
st324:
	if ( ++p == pe )
		goto _test_eof324;
case 324:
	if ( (*p) == 9 )
		goto st325;
	goto tr404;
st325:
	if ( ++p == pe )
		goto _test_eof325;
case 325:
	if ( (*p) == 82 )
		goto st326;
	goto tr404;
st326:
	if ( ++p == pe )
		goto _test_eof326;
case 326:
	if ( (*p) == 69 )
		goto st327;
	goto tr404;
st327:
	if ( ++p == pe )
		goto _test_eof327;
case 327:
	if ( (*p) == 70 )
		goto st328;
	goto tr404;
st328:
	if ( ++p == pe )
		goto _test_eof328;
case 328:
	if ( (*p) == 9 )
		goto st329;
	goto tr404;
st329:
	if ( ++p == pe )
		goto _test_eof329;
case 329:
	if ( (*p) == 65 )
		goto st330;
	goto tr404;
st330:
	if ( ++p == pe )
		goto _test_eof330;
case 330:
	if ( (*p) == 76 )
		goto st331;
	goto tr404;
st331:
	if ( ++p == pe )
		goto _test_eof331;
case 331:
	if ( (*p) == 84 )
		goto st332;
	goto tr404;
st332:
	if ( ++p == pe )
		goto _test_eof332;
case 332:
	if ( (*p) == 9 )
		goto st333;
	goto tr404;
st333:
	if ( ++p == pe )
		goto _test_eof333;
case 333:
	if ( (*p) == 81 )
		goto st334;
	goto tr404;
st334:
	if ( ++p == pe )
		goto _test_eof334;
case 334:
	if ( (*p) == 85 )
		goto st335;
	goto tr404;
st335:
	if ( ++p == pe )
		goto _test_eof335;
case 335:
	if ( (*p) == 65 )
		goto st336;
	goto tr404;
st336:
	if ( ++p == pe )
		goto _test_eof336;
case 336:
	if ( (*p) == 76 )
		goto st337;
	goto tr404;
st337:
	if ( ++p == pe )
		goto _test_eof337;
case 337:
	if ( (*p) == 9 )
		goto st338;
	goto tr404;
st338:
	if ( ++p == pe )
		goto _test_eof338;
case 338:
	if ( (*p) == 70 )
		goto st339;
	goto tr404;
st339:
	if ( ++p == pe )
		goto _test_eof339;
case 339:
	if ( (*p) == 73 )
		goto st340;
	goto tr404;
st340:
	if ( ++p == pe )
		goto _test_eof340;
case 340:
	if ( (*p) == 76 )
		goto st341;
	goto tr404;
st341:
	if ( ++p == pe )
		goto _test_eof341;
case 341:
	if ( (*p) == 84 )
		goto st342;
	goto tr404;
st342:
	if ( ++p == pe )
		goto _test_eof342;
case 342:
	if ( (*p) == 69 )
		goto st343;
	goto tr404;
st343:
	if ( ++p == pe )
		goto _test_eof343;
case 343:
	if ( (*p) == 82 )
		goto st344;
	goto tr404;
st344:
	if ( ++p == pe )
		goto _test_eof344;
case 344:
	if ( (*p) == 9 )
		goto st345;
	goto tr404;
st345:
	if ( ++p == pe )
		goto _test_eof345;
case 345:
	if ( (*p) == 73 )
		goto st346;
	goto tr404;
st346:
	if ( ++p == pe )
		goto _test_eof346;
case 346:
	if ( (*p) == 78 )
		goto st347;
	goto tr404;
st347:
	if ( ++p == pe )
		goto _test_eof347;
case 347:
	if ( (*p) == 70 )
		goto st348;
	goto tr404;
st348:
	if ( ++p == pe )
		goto _test_eof348;
case 348:
	if ( (*p) == 79 )
		goto st349;
	goto tr404;
st349:
	if ( ++p == pe )
		goto _test_eof349;
case 349:
	switch( (*p) ) {
		case 9: goto st350;
		case 10: goto tr442;
	}
	goto tr404;
st350:
	if ( ++p == pe )
		goto _test_eof350;
case 350:
	if ( (*p) == 70 )
		goto st351;
	goto tr443;
st351:
	if ( ++p == pe )
		goto _test_eof351;
case 351:
	if ( (*p) == 79 )
		goto st352;
	goto tr443;
st352:
	if ( ++p == pe )
		goto _test_eof352;
case 352:
	if ( (*p) == 82 )
		goto st353;
	goto tr443;
st353:
	if ( ++p == pe )
		goto _test_eof353;
case 353:
	if ( (*p) == 77 )
		goto st354;
	goto tr443;
st354:
	if ( ++p == pe )
		goto _test_eof354;
case 354:
	if ( (*p) == 65 )
		goto st355;
	goto tr443;
st355:
	if ( ++p == pe )
		goto _test_eof355;
case 355:
	if ( (*p) == 84 )
		goto st356;
	goto tr443;
st356:
	if ( ++p == pe )
		goto _test_eof356;
case 356:
	if ( (*p) == 9 )
		goto st357;
	goto tr443;
tr452:
#line 153 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_sample_name(*this);
    }
	goto st357;
st357:
	if ( ++p == pe )
		goto _test_eof357;
case 357:
#line 7515 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr451;
	goto tr443;
tr451:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st358;
tr454:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st358;
st358:
	if ( ++p == pe )
		goto _test_eof358;
case 358:
#line 7539 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr452;
		case 10: goto tr453;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr454;
	goto tr443;
tr442:
#line 157 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_header_line(*this);
    }
#line 28 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;
    }
	goto st556;
tr453:
#line 153 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_sample_name(*this);
    }
#line 157 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_header_line(*this);
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
#line 7579 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 60 )
		goto tr706;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr705;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr705;
	} else
		goto tr705;
	goto tr704;
tr705:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st359;
st359:
	if ( ++p == pe )
		goto _test_eof359;
case 359:
#line 7605 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr456;
		case 59: goto tr457;
		case 61: goto tr457;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr457;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr457;
		} else
			goto tr458;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr457;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr457;
		} else
			goto tr458;
	} else
		goto tr458;
	goto tr455;
tr456:
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
#line 7648 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr460;
	goto tr459;
tr460:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st361;
tr462:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st361;
st361:
	if ( ++p == pe )
		goto _test_eof361;
case 361:
#line 7672 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 9 )
		goto tr461;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr462;
	goto tr459;
tr467:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
	goto st362;
tr461:
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
	goto st362;
st362:
	if ( ++p == pe )
		goto _test_eof362;
case 362:
#line 7701 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr464;
	} else if ( (*p) >= 33 )
		goto tr464;
	goto tr463;
tr464:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st363;
tr466:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st363;
st363:
	if ( ++p == pe )
		goto _test_eof363;
case 363:
#line 7728 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr465;
		case 59: goto tr467;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr466;
	goto tr463;
tr465:
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
	goto st364;
st364:
	if ( ++p == pe )
		goto _test_eof364;
case 364:
#line 7752 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 65: goto tr469;
		case 67: goto tr469;
		case 71: goto tr469;
		case 78: goto tr469;
		case 84: goto tr469;
		case 97: goto tr469;
		case 99: goto tr469;
		case 103: goto tr469;
		case 110: goto tr469;
		case 116: goto tr469;
	}
	goto tr468;
tr469:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st365;
tr471:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st365;
st365:
	if ( ++p == pe )
		goto _test_eof365;
case 365:
#line 7786 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr470;
		case 65: goto tr471;
		case 67: goto tr471;
		case 71: goto tr471;
		case 78: goto tr471;
		case 84: goto tr471;
		case 97: goto tr471;
		case 99: goto tr471;
		case 103: goto tr471;
		case 110: goto tr471;
		case 116: goto tr471;
	}
	goto tr468;
tr470:
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
	goto st366;
st366:
	if ( ++p == pe )
		goto _test_eof366;
case 366:
#line 7817 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 42: goto tr473;
		case 46: goto tr474;
		case 60: goto tr475;
		case 65: goto tr476;
		case 67: goto tr476;
		case 71: goto tr476;
		case 78: goto tr476;
		case 84: goto tr476;
		case 91: goto tr477;
		case 93: goto tr478;
		case 97: goto tr476;
		case 99: goto tr476;
		case 103: goto tr476;
		case 110: goto tr476;
		case 116: goto tr476;
	}
	goto tr472;
tr473:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st367;
tr647:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st367;
st367:
	if ( ++p == pe )
		goto _test_eof367;
case 367:
#line 7856 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr479;
		case 44: goto tr480;
	}
	goto tr472;
tr479:
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
	goto st368;
st368:
	if ( ++p == pe )
		goto _test_eof368;
case 368:
#line 7878 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 46 )
		goto tr482;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr483;
	goto tr481;
tr482:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st369;
st369:
	if ( ++p == pe )
		goto _test_eof369;
case 369:
#line 7898 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 9 )
		goto tr484;
	goto tr481;
tr484:
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
	goto st370;
st370:
	if ( ++p == pe )
		goto _test_eof370;
case 370:
#line 7918 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 46: goto tr487;
		case 58: goto tr486;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr486;
		} else if ( (*p) > 57 ) {
			if ( 60 <= (*p) && (*p) <= 64 )
				goto tr486;
		} else
			goto tr488;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr486;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr486;
		} else
			goto tr488;
	} else
		goto tr488;
	goto tr485;
tr486:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st371;
st371:
	if ( ++p == pe )
		goto _test_eof371;
case 371:
#line 7954 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 58 )
		goto st371;
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto st371;
		} else if ( (*p) > 57 ) {
			if ( 60 <= (*p) && (*p) <= 64 )
				goto st371;
		} else
			goto tr490;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st371;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st371;
		} else
			goto tr490;
	} else
		goto tr490;
	goto tr485;
tr488:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st372;
tr490:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st372;
st372:
	if ( ++p == pe )
		goto _test_eof372;
case 372:
#line 7998 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr491;
		case 59: goto tr492;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr490;
	goto tr485;
tr491:
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
	goto st373;
st373:
	if ( ++p == pe )
		goto _test_eof373;
case 373:
#line 8022 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 46: goto tr495;
		case 49: goto tr497;
		case 58: goto tr494;
		case 60: goto tr494;
		case 65: goto tr498;
		case 66: goto tr499;
		case 67: goto tr500;
		case 68: goto tr501;
		case 69: goto tr502;
		case 72: goto tr503;
		case 77: goto tr504;
		case 78: goto tr505;
		case 83: goto tr506;
		case 86: goto tr507;
	}
	if ( (*p) < 70 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr494;
		} else if ( (*p) > 57 ) {
			if ( 62 <= (*p) && (*p) <= 64 )
				goto tr494;
		} else
			goto tr496;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr494;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr494;
		} else
			goto tr496;
	} else
		goto tr496;
	goto tr493;
tr494:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st374;
tr508:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st374;
st374:
	if ( ++p == pe )
		goto _test_eof374;
case 374:
#line 8080 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 58: goto tr508;
		case 60: goto tr508;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr508;
		} else if ( (*p) > 57 ) {
			if ( 62 <= (*p) && (*p) <= 64 )
				goto tr508;
		} else
			goto tr509;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr508;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr508;
		} else
			goto tr509;
	} else
		goto tr509;
	goto tr493;
tr496:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st375;
tr509:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st375;
st375:
	if ( ++p == pe )
		goto _test_eof375;
case 375:
#line 8126 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr510;
		case 10: goto tr511;
		case 59: goto tr512;
		case 61: goto tr513;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr509;
	goto tr493;
tr518:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
	goto st376;
tr510:
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
	goto st376;
st376:
	if ( ++p == pe )
		goto _test_eof376;
case 376:
#line 8159 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr515;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr515;
	} else
		goto tr515;
	goto tr514;
tr515:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st377;
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
#line 8189 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr516;
		case 58: goto tr518;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr517;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr517;
	} else
		goto tr517;
	goto tr514;
tr516:
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
	goto st378;
st378:
	if ( ++p == pe )
		goto _test_eof378;
case 378:
#line 8219 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 46 )
		goto tr520;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr520;
	goto tr519;
tr520:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st379;
tr527:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st379;
st379:
	if ( ++p == pe )
		goto _test_eof379;
case 379:
#line 8245 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr516;
		case 10: goto tr511;
		case 47: goto tr521;
		case 58: goto tr522;
		case 124: goto tr521;
	}
	goto tr519;
tr511:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
#line 163 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        // Handle last sample if proceeds
        if (n_columns > 9) {
          ParsePolicy::handle_column_end(*this, n_columns);
        }
        
        // Check warnings (non-blocking errors but potential mistakes anyway)
        try {
          optional_check_body_entry();
        } catch (ParsingWarning ex) {
          ErrorPolicy::handle_body_section_warning(*this, ex.what());
        }
        
        // Handle all columns in the record
        try {
          ParsePolicy::handle_body_line(*this);
        } catch (ParsingError ex) {
          ErrorPolicy::handle_body_section_error(*this, ex.what());
        }
    }
#line 28 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;
    }
	goto st557;
st557:
	if ( ++p == pe )
		goto _test_eof557;
case 557:
#line 8292 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 60 )
		goto tr706;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr705;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr705;
	} else
		goto tr705;
	goto tr455;
tr706:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st380;
st380:
	if ( ++p == pe )
		goto _test_eof380;
case 380:
#line 8318 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr523;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr523;
	} else
		goto tr523;
	goto tr455;
tr523:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st381;
st381:
	if ( ++p == pe )
		goto _test_eof381;
case 381:
#line 8338 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr524;
		case 62: goto tr526;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr524;
		} else if ( (*p) > 57 ) {
			if ( 61 <= (*p) && (*p) <= 64 )
				goto tr524;
		} else
			goto tr525;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr524;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr524;
		} else
			goto tr525;
	} else
		goto tr525;
	goto tr455;
tr524:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st382;
st382:
	if ( ++p == pe )
		goto _test_eof382;
case 382:
#line 8374 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr524;
		case 61: goto tr524;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr524;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr524;
		} else
			goto tr525;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr524;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr524;
		} else
			goto tr525;
	} else
		goto tr525;
	goto tr455;
tr525:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st383;
st383:
	if ( ++p == pe )
		goto _test_eof383;
case 383:
#line 8410 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr525;
		case 62: goto tr526;
	}
	if ( (*p) > 57 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr525;
	} else if ( (*p) >= 33 )
		goto tr525;
	goto tr455;
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
#line 8431 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 9 )
		goto tr456;
	goto tr455;
tr521:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st385;
st385:
	if ( ++p == pe )
		goto _test_eof385;
case 385:
#line 8445 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 46 )
		goto tr527;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr527;
	goto tr519;
tr522:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st386;
st386:
	if ( ++p == pe )
		goto _test_eof386;
case 386:
#line 8461 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) > 57 ) {
		if ( 59 <= (*p) && (*p) <= 126 )
			goto tr529;
	} else if ( (*p) >= 33 )
		goto tr529;
	goto tr528;
tr529:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st387;
st387:
	if ( ++p == pe )
		goto _test_eof387;
case 387:
#line 8478 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr516;
		case 10: goto tr511;
		case 58: goto tr522;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr529;
	goto tr528;
tr512:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
	goto st388;
st388:
	if ( ++p == pe )
		goto _test_eof388;
case 388:
#line 8498 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 49: goto tr497;
		case 58: goto tr494;
		case 60: goto tr494;
		case 65: goto tr498;
		case 66: goto tr499;
		case 67: goto tr500;
		case 68: goto tr501;
		case 69: goto tr502;
		case 72: goto tr503;
		case 77: goto tr504;
		case 78: goto tr505;
		case 83: goto tr506;
		case 86: goto tr507;
	}
	if ( (*p) < 70 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr494;
		} else if ( (*p) > 57 ) {
			if ( 62 <= (*p) && (*p) <= 64 )
				goto tr494;
		} else
			goto tr496;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr494;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr494;
		} else
			goto tr496;
	} else
		goto tr496;
	goto tr493;
tr497:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st389;
st389:
	if ( ++p == pe )
		goto _test_eof389;
case 389:
#line 8549 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr510;
		case 10: goto tr511;
		case 48: goto tr530;
		case 59: goto tr512;
		case 61: goto tr513;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr509;
	goto tr493;
tr530:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st390;
st390:
	if ( ++p == pe )
		goto _test_eof390;
case 390:
#line 8570 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr510;
		case 10: goto tr511;
		case 48: goto tr531;
		case 59: goto tr512;
		case 61: goto tr513;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr509;
	goto tr493;
tr531:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st391;
st391:
	if ( ++p == pe )
		goto _test_eof391;
case 391:
#line 8591 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr510;
		case 10: goto tr511;
		case 48: goto tr532;
		case 59: goto tr512;
		case 61: goto tr513;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr509;
	goto tr493;
tr532:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st392;
st392:
	if ( ++p == pe )
		goto _test_eof392;
case 392:
#line 8612 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr510;
		case 10: goto tr511;
		case 59: goto tr512;
		case 61: goto tr513;
		case 71: goto tr533;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr509;
	goto tr493;
tr513:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st393;
st393:
	if ( ++p == pe )
		goto _test_eof393;
case 393:
#line 8633 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr535;
	} else if ( (*p) >= 33 )
		goto tr535;
	goto tr534;
tr535:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st394;
st394:
	if ( ++p == pe )
		goto _test_eof394;
case 394:
#line 8650 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr510;
		case 10: goto tr511;
		case 59: goto tr512;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr535;
	goto tr534;
tr533:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st395;
st395:
	if ( ++p == pe )
		goto _test_eof395;
case 395:
#line 8669 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr510;
		case 10: goto tr511;
		case 59: goto tr512;
		case 61: goto tr537;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr509;
	goto tr536;
tr537:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st396;
st396:
	if ( ++p == pe )
		goto _test_eof396;
case 396:
#line 8689 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 49 )
		goto tr539;
	goto tr538;
tr539:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st397;
st397:
	if ( ++p == pe )
		goto _test_eof397;
case 397:
#line 8703 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr510;
		case 10: goto tr511;
		case 59: goto tr512;
	}
	goto tr538;
tr498:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st398;
st398:
	if ( ++p == pe )
		goto _test_eof398;
case 398:
#line 8724 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr510;
		case 10: goto tr511;
		case 59: goto tr512;
		case 61: goto tr513;
		case 65: goto tr540;
		case 67: goto tr541;
		case 70: goto tr542;
		case 78: goto tr543;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr509;
	goto tr493;
tr540:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st399;
st399:
	if ( ++p == pe )
		goto _test_eof399;
case 399:
#line 8748 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 61 )
		goto tr544;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr509;
	} else if ( (*p) >= 33 )
		goto tr509;
	goto tr493;
tr544:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st400;
st400:
	if ( ++p == pe )
		goto _test_eof400;
case 400:
#line 8767 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 46: goto tr546;
		case 65: goto tr547;
		case 67: goto tr547;
		case 71: goto tr547;
		case 78: goto tr547;
		case 84: goto tr547;
		case 97: goto tr547;
		case 99: goto tr547;
		case 103: goto tr547;
		case 110: goto tr547;
		case 116: goto tr547;
	}
	goto tr545;
tr546:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st401;
st401:
	if ( ++p == pe )
		goto _test_eof401;
case 401:
#line 8792 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr510;
		case 10: goto tr511;
		case 59: goto tr512;
	}
	goto tr545;
tr547:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st402;
st402:
	if ( ++p == pe )
		goto _test_eof402;
case 402:
#line 8809 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr510;
		case 10: goto tr511;
		case 59: goto tr512;
		case 65: goto tr547;
		case 67: goto tr547;
		case 71: goto tr547;
		case 78: goto tr547;
		case 84: goto tr547;
		case 97: goto tr547;
		case 99: goto tr547;
		case 103: goto tr547;
		case 110: goto tr547;
		case 116: goto tr547;
	}
	goto tr545;
tr541:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st403;
st403:
	if ( ++p == pe )
		goto _test_eof403;
case 403:
#line 8836 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 61 )
		goto tr548;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr509;
	} else if ( (*p) >= 33 )
		goto tr509;
	goto tr493;
tr548:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st404;
st404:
	if ( ++p == pe )
		goto _test_eof404;
case 404:
#line 8855 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr550;
	goto tr549;
tr550:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st405;
st405:
	if ( ++p == pe )
		goto _test_eof405;
case 405:
#line 8869 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr510;
		case 10: goto tr511;
		case 44: goto tr548;
		case 59: goto tr512;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr550;
	goto tr549;
tr542:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st406;
st406:
	if ( ++p == pe )
		goto _test_eof406;
case 406:
#line 8889 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 61 )
		goto tr551;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr509;
	} else if ( (*p) >= 33 )
		goto tr509;
	goto tr493;
tr551:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st407;
st407:
	if ( ++p == pe )
		goto _test_eof407;
case 407:
#line 8908 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr553;
	goto tr552;
tr553:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st408;
st408:
	if ( ++p == pe )
		goto _test_eof408;
case 408:
#line 8922 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr510;
		case 10: goto tr511;
		case 44: goto tr551;
		case 46: goto tr554;
		case 59: goto tr512;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr553;
	goto tr552;
tr554:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st409;
st409:
	if ( ++p == pe )
		goto _test_eof409;
case 409:
#line 8943 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr555;
	goto tr552;
tr555:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st410;
st410:
	if ( ++p == pe )
		goto _test_eof410;
case 410:
#line 8957 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr510;
		case 10: goto tr511;
		case 44: goto tr551;
		case 59: goto tr512;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr555;
	goto tr552;
tr543:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st411;
st411:
	if ( ++p == pe )
		goto _test_eof411;
case 411:
#line 8977 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 61 )
		goto tr556;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr509;
	} else if ( (*p) >= 33 )
		goto tr509;
	goto tr493;
tr556:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st412;
st412:
	if ( ++p == pe )
		goto _test_eof412;
case 412:
#line 8996 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
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
#line 9010 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr510;
		case 10: goto tr511;
		case 59: goto tr512;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr558;
	goto tr557;
tr499:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st414;
st414:
	if ( ++p == pe )
		goto _test_eof414;
case 414:
#line 9033 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr510;
		case 10: goto tr511;
		case 59: goto tr512;
		case 61: goto tr513;
		case 81: goto tr559;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr509;
	goto tr493;
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
#line 9054 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 61 )
		goto tr560;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr509;
	} else if ( (*p) >= 33 )
		goto tr509;
	goto tr493;
tr560:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st416;
st416:
	if ( ++p == pe )
		goto _test_eof416;
case 416:
#line 9073 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr562;
	goto tr561;
tr562:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st417;
st417:
	if ( ++p == pe )
		goto _test_eof417;
case 417:
#line 9087 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr510;
		case 10: goto tr511;
		case 46: goto tr563;
		case 59: goto tr512;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr562;
	goto tr561;
tr563:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st418;
st418:
	if ( ++p == pe )
		goto _test_eof418;
case 418:
#line 9107 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr564;
	goto tr561;
tr564:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st419;
st419:
	if ( ++p == pe )
		goto _test_eof419;
case 419:
#line 9121 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr510;
		case 10: goto tr511;
		case 59: goto tr512;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr564;
	goto tr561;
tr500:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st420;
st420:
	if ( ++p == pe )
		goto _test_eof420;
case 420:
#line 9144 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr510;
		case 10: goto tr511;
		case 59: goto tr512;
		case 61: goto tr513;
		case 73: goto tr565;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr509;
	goto tr493;
tr565:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st421;
st421:
	if ( ++p == pe )
		goto _test_eof421;
case 421:
#line 9165 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr510;
		case 10: goto tr511;
		case 59: goto tr512;
		case 61: goto tr513;
		case 71: goto tr566;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr509;
	goto tr493;
tr566:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st422;
st422:
	if ( ++p == pe )
		goto _test_eof422;
case 422:
#line 9186 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr510;
		case 10: goto tr511;
		case 59: goto tr512;
		case 61: goto tr513;
		case 65: goto tr567;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr509;
	goto tr493;
tr567:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st423;
st423:
	if ( ++p == pe )
		goto _test_eof423;
case 423:
#line 9207 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr510;
		case 10: goto tr511;
		case 59: goto tr512;
		case 61: goto tr513;
		case 82: goto tr568;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr509;
	goto tr493;
tr568:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st424;
st424:
	if ( ++p == pe )
		goto _test_eof424;
case 424:
#line 9228 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 61 )
		goto tr569;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr509;
	} else if ( (*p) >= 33 )
		goto tr509;
	goto tr493;
tr569:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st425;
st425:
	if ( ++p == pe )
		goto _test_eof425;
case 425:
#line 9247 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr571;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr571;
	} else
		goto tr571;
	goto tr570;
tr571:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st426;
st426:
	if ( ++p == pe )
		goto _test_eof426;
case 426:
#line 9267 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr510;
		case 10: goto tr511;
		case 59: goto tr512;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr571;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr571;
	} else
		goto tr571;
	goto tr570;
tr501:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st427;
st427:
	if ( ++p == pe )
		goto _test_eof427;
case 427:
#line 9296 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr510;
		case 10: goto tr511;
		case 59: goto tr512;
		case 61: goto tr513;
		case 66: goto tr572;
		case 80: goto tr573;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr509;
	goto tr493;
tr572:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st428;
st428:
	if ( ++p == pe )
		goto _test_eof428;
case 428:
#line 9318 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr510;
		case 10: goto tr511;
		case 59: goto tr512;
		case 61: goto tr575;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr509;
	goto tr574;
tr575:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st429;
st429:
	if ( ++p == pe )
		goto _test_eof429;
case 429:
#line 9338 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 49 )
		goto tr577;
	goto tr576;
tr577:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st430;
st430:
	if ( ++p == pe )
		goto _test_eof430;
case 430:
#line 9352 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr510;
		case 10: goto tr511;
		case 59: goto tr512;
	}
	goto tr576;
tr573:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st431;
st431:
	if ( ++p == pe )
		goto _test_eof431;
case 431:
#line 9369 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 61 )
		goto tr578;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr509;
	} else if ( (*p) >= 33 )
		goto tr509;
	goto tr493;
tr578:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st432;
st432:
	if ( ++p == pe )
		goto _test_eof432;
case 432:
#line 9388 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr580;
	goto tr579;
tr580:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st433;
st433:
	if ( ++p == pe )
		goto _test_eof433;
case 433:
#line 9402 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr510;
		case 10: goto tr511;
		case 59: goto tr512;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr580;
	goto tr579;
tr502:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st434;
st434:
	if ( ++p == pe )
		goto _test_eof434;
case 434:
#line 9425 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr510;
		case 10: goto tr511;
		case 59: goto tr512;
		case 61: goto tr513;
		case 78: goto tr581;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr509;
	goto tr493;
tr581:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st435;
st435:
	if ( ++p == pe )
		goto _test_eof435;
case 435:
#line 9446 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr510;
		case 10: goto tr511;
		case 59: goto tr512;
		case 61: goto tr513;
		case 68: goto tr582;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr509;
	goto tr493;
tr582:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st436;
st436:
	if ( ++p == pe )
		goto _test_eof436;
case 436:
#line 9467 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 61 )
		goto tr583;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr509;
	} else if ( (*p) >= 33 )
		goto tr509;
	goto tr493;
tr583:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st437;
st437:
	if ( ++p == pe )
		goto _test_eof437;
case 437:
#line 9486 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr585;
	goto tr584;
tr585:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st438;
st438:
	if ( ++p == pe )
		goto _test_eof438;
case 438:
#line 9500 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr510;
		case 10: goto tr511;
		case 59: goto tr512;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr585;
	goto tr584;
tr503:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st439;
st439:
	if ( ++p == pe )
		goto _test_eof439;
case 439:
#line 9523 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr510;
		case 10: goto tr511;
		case 50: goto tr586;
		case 51: goto tr587;
		case 59: goto tr512;
		case 61: goto tr513;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr509;
	goto tr493;
tr586:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st440;
st440:
	if ( ++p == pe )
		goto _test_eof440;
case 440:
#line 9545 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr510;
		case 10: goto tr511;
		case 59: goto tr512;
		case 61: goto tr589;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr509;
	goto tr588;
tr589:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st441;
st441:
	if ( ++p == pe )
		goto _test_eof441;
case 441:
#line 9565 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 49 )
		goto tr591;
	goto tr590;
tr591:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st442;
st442:
	if ( ++p == pe )
		goto _test_eof442;
case 442:
#line 9579 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr510;
		case 10: goto tr511;
		case 59: goto tr512;
	}
	goto tr590;
tr587:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st443;
st443:
	if ( ++p == pe )
		goto _test_eof443;
case 443:
#line 9596 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr510;
		case 10: goto tr511;
		case 59: goto tr512;
		case 61: goto tr593;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr509;
	goto tr592;
tr593:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st444;
st444:
	if ( ++p == pe )
		goto _test_eof444;
case 444:
#line 9616 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 49 )
		goto tr595;
	goto tr594;
tr595:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st445;
st445:
	if ( ++p == pe )
		goto _test_eof445;
case 445:
#line 9630 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr510;
		case 10: goto tr511;
		case 59: goto tr512;
	}
	goto tr594;
tr504:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st446;
st446:
	if ( ++p == pe )
		goto _test_eof446;
case 446:
#line 9651 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr510;
		case 10: goto tr511;
		case 59: goto tr512;
		case 61: goto tr513;
		case 81: goto tr596;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr509;
	goto tr493;
tr596:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st447;
st447:
	if ( ++p == pe )
		goto _test_eof447;
case 447:
#line 9672 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 48: goto tr597;
		case 61: goto tr598;
	}
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr509;
	} else if ( (*p) >= 33 )
		goto tr509;
	goto tr493;
tr597:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st448;
st448:
	if ( ++p == pe )
		goto _test_eof448;
case 448:
#line 9693 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 61 )
		goto tr599;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr509;
	} else if ( (*p) >= 33 )
		goto tr509;
	goto tr493;
tr599:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st449;
st449:
	if ( ++p == pe )
		goto _test_eof449;
case 449:
#line 9712 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr601;
	goto tr600;
tr601:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st450;
st450:
	if ( ++p == pe )
		goto _test_eof450;
case 450:
#line 9726 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr510;
		case 10: goto tr511;
		case 59: goto tr512;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr601;
	goto tr600;
tr598:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st451;
st451:
	if ( ++p == pe )
		goto _test_eof451;
case 451:
#line 9745 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr603;
	goto tr602;
tr603:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st452;
st452:
	if ( ++p == pe )
		goto _test_eof452;
case 452:
#line 9759 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr510;
		case 10: goto tr511;
		case 46: goto tr604;
		case 59: goto tr512;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr603;
	goto tr602;
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
#line 9779 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr605;
	goto tr602;
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
#line 9793 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr510;
		case 10: goto tr511;
		case 59: goto tr512;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr605;
	goto tr602;
tr505:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st455;
st455:
	if ( ++p == pe )
		goto _test_eof455;
case 455:
#line 9816 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr510;
		case 10: goto tr511;
		case 59: goto tr512;
		case 61: goto tr513;
		case 83: goto tr606;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr509;
	goto tr493;
tr606:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st456;
st456:
	if ( ++p == pe )
		goto _test_eof456;
case 456:
#line 9837 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 61 )
		goto tr607;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr509;
	} else if ( (*p) >= 33 )
		goto tr509;
	goto tr493;
tr607:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st457;
st457:
	if ( ++p == pe )
		goto _test_eof457;
case 457:
#line 9856 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr609;
	goto tr608;
tr609:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st458;
st458:
	if ( ++p == pe )
		goto _test_eof458;
case 458:
#line 9870 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr510;
		case 10: goto tr511;
		case 59: goto tr512;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr609;
	goto tr608;
tr506:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st459;
st459:
	if ( ++p == pe )
		goto _test_eof459;
case 459:
#line 9893 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr510;
		case 10: goto tr511;
		case 59: goto tr512;
		case 61: goto tr513;
		case 66: goto tr610;
		case 79: goto tr611;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr509;
	goto tr493;
tr610:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st460;
st460:
	if ( ++p == pe )
		goto _test_eof460;
case 460:
#line 9915 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 61 )
		goto tr612;
	if ( (*p) > 58 ) {
		if ( 60 <= (*p) && (*p) <= 126 )
			goto tr509;
	} else if ( (*p) >= 33 )
		goto tr509;
	goto tr493;
tr612:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st461;
st461:
	if ( ++p == pe )
		goto _test_eof461;
case 461:
#line 9934 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr614;
	goto tr613;
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
#line 9948 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr510;
		case 10: goto tr511;
		case 46: goto tr615;
		case 59: goto tr512;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr614;
	goto tr613;
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
#line 9968 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr616;
	goto tr613;
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
#line 9982 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr510;
		case 10: goto tr511;
		case 59: goto tr512;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr616;
	goto tr613;
tr611:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st465;
st465:
	if ( ++p == pe )
		goto _test_eof465;
case 465:
#line 10001 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr510;
		case 10: goto tr511;
		case 59: goto tr512;
		case 61: goto tr513;
		case 77: goto tr617;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr509;
	goto tr493;
tr617:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st466;
st466:
	if ( ++p == pe )
		goto _test_eof466;
case 466:
#line 10022 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr510;
		case 10: goto tr511;
		case 59: goto tr512;
		case 61: goto tr513;
		case 65: goto tr618;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr509;
	goto tr493;
tr618:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st467;
st467:
	if ( ++p == pe )
		goto _test_eof467;
case 467:
#line 10043 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr510;
		case 10: goto tr511;
		case 59: goto tr512;
		case 61: goto tr513;
		case 84: goto tr619;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr509;
	goto tr493;
tr619:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st468;
st468:
	if ( ++p == pe )
		goto _test_eof468;
case 468:
#line 10064 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr510;
		case 10: goto tr511;
		case 59: goto tr512;
		case 61: goto tr513;
		case 73: goto tr620;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr509;
	goto tr493;
tr620:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st469;
st469:
	if ( ++p == pe )
		goto _test_eof469;
case 469:
#line 10085 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr510;
		case 10: goto tr511;
		case 59: goto tr512;
		case 61: goto tr513;
		case 67: goto tr621;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr509;
	goto tr493;
tr621:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st470;
st470:
	if ( ++p == pe )
		goto _test_eof470;
case 470:
#line 10106 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr510;
		case 10: goto tr511;
		case 59: goto tr512;
		case 61: goto tr623;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr509;
	goto tr622;
tr623:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st471;
st471:
	if ( ++p == pe )
		goto _test_eof471;
case 471:
#line 10126 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 49 )
		goto tr625;
	goto tr624;
tr625:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st472;
st472:
	if ( ++p == pe )
		goto _test_eof472;
case 472:
#line 10140 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr510;
		case 10: goto tr511;
		case 59: goto tr512;
	}
	goto tr624;
tr507:
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
#line 10161 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr510;
		case 10: goto tr511;
		case 59: goto tr512;
		case 61: goto tr513;
		case 65: goto tr626;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr509;
	goto tr493;
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
#line 10182 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr510;
		case 10: goto tr511;
		case 59: goto tr512;
		case 61: goto tr513;
		case 76: goto tr627;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr509;
	goto tr493;
tr627:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st475;
st475:
	if ( ++p == pe )
		goto _test_eof475;
case 475:
#line 10203 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr510;
		case 10: goto tr511;
		case 59: goto tr512;
		case 61: goto tr513;
		case 73: goto tr628;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr509;
	goto tr493;
tr628:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st476;
st476:
	if ( ++p == pe )
		goto _test_eof476;
case 476:
#line 10224 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr510;
		case 10: goto tr511;
		case 59: goto tr512;
		case 61: goto tr513;
		case 68: goto tr629;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr509;
	goto tr493;
tr629:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st477;
st477:
	if ( ++p == pe )
		goto _test_eof477;
case 477:
#line 10245 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr510;
		case 10: goto tr511;
		case 59: goto tr512;
		case 61: goto tr513;
		case 65: goto tr630;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr509;
	goto tr493;
tr630:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st478;
st478:
	if ( ++p == pe )
		goto _test_eof478;
case 478:
#line 10266 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr510;
		case 10: goto tr511;
		case 59: goto tr512;
		case 61: goto tr513;
		case 84: goto tr631;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr509;
	goto tr493;
tr631:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st479;
st479:
	if ( ++p == pe )
		goto _test_eof479;
case 479:
#line 10287 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr510;
		case 10: goto tr511;
		case 59: goto tr512;
		case 61: goto tr513;
		case 69: goto tr632;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr509;
	goto tr493;
tr632:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st480;
st480:
	if ( ++p == pe )
		goto _test_eof480;
case 480:
#line 10308 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr510;
		case 10: goto tr511;
		case 59: goto tr512;
		case 61: goto tr513;
		case 68: goto tr633;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr509;
	goto tr493;
tr633:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st481;
st481:
	if ( ++p == pe )
		goto _test_eof481;
case 481:
#line 10329 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr510;
		case 10: goto tr511;
		case 59: goto tr512;
		case 61: goto tr635;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr509;
	goto tr634;
tr635:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st482;
st482:
	if ( ++p == pe )
		goto _test_eof482;
case 482:
#line 10349 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 49 )
		goto tr637;
	goto tr636;
tr637:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st483;
st483:
	if ( ++p == pe )
		goto _test_eof483;
case 483:
#line 10363 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr510;
		case 10: goto tr511;
		case 59: goto tr512;
	}
	goto tr636;
tr495:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st484;
st484:
	if ( ++p == pe )
		goto _test_eof484;
case 484:
#line 10384 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr510;
		case 10: goto tr511;
		case 58: goto tr508;
		case 60: goto tr508;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr508;
		} else if ( (*p) > 57 ) {
			if ( 62 <= (*p) && (*p) <= 64 )
				goto tr508;
		} else
			goto tr509;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr508;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr508;
		} else
			goto tr509;
	} else
		goto tr509;
	goto tr493;
tr492:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
	goto st485;
st485:
	if ( ++p == pe )
		goto _test_eof485;
case 485:
#line 10423 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 58 )
		goto tr486;
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr486;
		} else if ( (*p) > 57 ) {
			if ( 60 <= (*p) && (*p) <= 64 )
				goto tr486;
		} else
			goto tr488;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr486;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr486;
		} else
			goto tr488;
	} else
		goto tr488;
	goto tr485;
tr487:
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
#line 10461 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr491;
		case 58: goto st371;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto st371;
		} else if ( (*p) > 57 ) {
			if ( 60 <= (*p) && (*p) <= 64 )
				goto st371;
		} else
			goto tr490;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st371;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st371;
		} else
			goto tr490;
	} else
		goto tr490;
	goto tr485;
tr483:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st487;
tr639:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st487;
st487:
	if ( ++p == pe )
		goto _test_eof487;
case 487:
#line 10507 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr484;
		case 46: goto tr638;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr639;
	goto tr481;
tr638:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st488;
st488:
	if ( ++p == pe )
		goto _test_eof488;
case 488:
#line 10525 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr640;
	goto tr481;
tr640:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st489;
st489:
	if ( ++p == pe )
		goto _test_eof489;
case 489:
#line 10539 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 9 )
		goto tr484;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr640;
	goto tr481;
tr480:
#line 23 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        //std::cout << "m_current_token '" << ParsePolicy::current_token() << "'" << std::endl;
        ParsePolicy::handle_token_end(*this);
    }
	goto st490;
st490:
	if ( ++p == pe )
		goto _test_eof490;
case 490:
#line 10556 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 42: goto tr473;
		case 46: goto tr641;
		case 60: goto tr475;
		case 65: goto tr476;
		case 67: goto tr476;
		case 71: goto tr476;
		case 78: goto tr476;
		case 84: goto tr476;
		case 91: goto tr477;
		case 93: goto tr478;
		case 97: goto tr476;
		case 99: goto tr476;
		case 103: goto tr476;
		case 110: goto tr476;
		case 116: goto tr476;
	}
	goto tr472;
tr641:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st491;
tr685:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st491;
st491:
	if ( ++p == pe )
		goto _test_eof491;
case 491:
#line 10595 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 65: goto tr642;
		case 67: goto tr642;
		case 71: goto tr642;
		case 78: goto tr642;
		case 84: goto tr642;
		case 97: goto tr642;
		case 99: goto tr642;
		case 103: goto tr642;
		case 110: goto tr642;
		case 116: goto tr642;
	}
	goto tr472;
tr642:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st492;
st492:
	if ( ++p == pe )
		goto _test_eof492;
case 492:
#line 10619 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr479;
		case 44: goto tr480;
		case 65: goto tr642;
		case 67: goto tr642;
		case 71: goto tr642;
		case 78: goto tr642;
		case 84: goto tr642;
		case 97: goto tr642;
		case 99: goto tr642;
		case 103: goto tr642;
		case 110: goto tr642;
		case 116: goto tr642;
	}
	goto tr472;
tr475:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st493;
st493:
	if ( ++p == pe )
		goto _test_eof493;
case 493:
#line 10649 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 58: goto tr643;
		case 68: goto tr645;
		case 73: goto tr646;
		case 95: goto tr643;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr644;
	} else if ( (*p) >= 65 )
		goto tr644;
	goto tr472;
tr643:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st494;
st494:
	if ( ++p == pe )
		goto _test_eof494;
case 494:
#line 10672 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 58: goto tr643;
		case 95: goto tr643;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr644;
	} else if ( (*p) >= 65 )
		goto tr644;
	goto tr472;
tr644:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st495;
st495:
	if ( ++p == pe )
		goto _test_eof495;
case 495:
#line 10693 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 58: goto tr644;
		case 62: goto tr647;
		case 95: goto tr644;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr644;
	} else if ( (*p) >= 65 )
		goto tr644;
	goto tr472;
tr645:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st496;
st496:
	if ( ++p == pe )
		goto _test_eof496;
case 496:
#line 10715 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 58: goto tr644;
		case 62: goto tr647;
		case 69: goto tr648;
		case 95: goto tr644;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr644;
	} else if ( (*p) >= 65 )
		goto tr644;
	goto tr472;
tr648:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st497;
st497:
	if ( ++p == pe )
		goto _test_eof497;
case 497:
#line 10738 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 58: goto tr644;
		case 62: goto tr647;
		case 76: goto tr649;
		case 95: goto tr644;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr644;
	} else if ( (*p) >= 65 )
		goto tr644;
	goto tr472;
tr649:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st498;
st498:
	if ( ++p == pe )
		goto _test_eof498;
case 498:
#line 10761 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 58: goto tr650;
		case 62: goto tr647;
		case 95: goto tr644;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr644;
	} else if ( (*p) >= 65 )
		goto tr644;
	goto tr472;
tr650:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st499;
st499:
	if ( ++p == pe )
		goto _test_eof499;
case 499:
#line 10783 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 58: goto tr644;
		case 62: goto tr647;
		case 77: goto tr651;
		case 95: goto tr644;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr644;
	} else if ( (*p) >= 65 )
		goto tr644;
	goto tr472;
tr651:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st500;
st500:
	if ( ++p == pe )
		goto _test_eof500;
case 500:
#line 10806 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 58: goto tr644;
		case 62: goto tr647;
		case 69: goto tr652;
		case 95: goto tr644;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr644;
	} else if ( (*p) >= 65 )
		goto tr644;
	goto tr472;
tr652:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st501;
st501:
	if ( ++p == pe )
		goto _test_eof501;
case 501:
#line 10829 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 58: goto tr653;
		case 62: goto tr647;
		case 95: goto tr644;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr644;
	} else if ( (*p) >= 65 )
		goto tr644;
	goto tr472;
tr653:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st502;
st502:
	if ( ++p == pe )
		goto _test_eof502;
case 502:
#line 10851 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 58: goto tr644;
		case 62: goto tr647;
		case 95: goto tr644;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr654;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr653;
	} else
		goto tr653;
	goto tr472;
tr654:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st503;
st503:
	if ( ++p == pe )
		goto _test_eof503;
case 503:
#line 10876 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 62 )
		goto tr647;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr654;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr654;
	} else
		goto tr654;
	goto tr472;
tr646:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st504;
st504:
	if ( ++p == pe )
		goto _test_eof504;
case 504:
#line 10898 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 58: goto tr644;
		case 62: goto tr647;
		case 78: goto tr655;
		case 95: goto tr644;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr644;
	} else if ( (*p) >= 65 )
		goto tr644;
	goto tr472;
tr655:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st505;
st505:
	if ( ++p == pe )
		goto _test_eof505;
case 505:
#line 10921 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 58: goto tr644;
		case 62: goto tr647;
		case 83: goto tr649;
		case 95: goto tr644;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr644;
	} else if ( (*p) >= 65 )
		goto tr644;
	goto tr472;
tr476:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st506;
tr656:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st506;
st506:
	if ( ++p == pe )
		goto _test_eof506;
case 506:
#line 10954 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr479;
		case 44: goto tr480;
		case 46: goto tr647;
		case 65: goto tr656;
		case 67: goto tr656;
		case 71: goto tr656;
		case 78: goto tr656;
		case 84: goto tr656;
		case 91: goto tr657;
		case 93: goto tr658;
		case 97: goto tr656;
		case 99: goto tr656;
		case 103: goto tr656;
		case 110: goto tr656;
		case 116: goto tr656;
	}
	goto tr472;
tr657:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st507;
st507:
	if ( ++p == pe )
		goto _test_eof507;
case 507:
#line 10983 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 60 )
		goto tr660;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr659;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr659;
	} else
		goto tr659;
	goto tr472;
tr659:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st508;
st508:
	if ( ++p == pe )
		goto _test_eof508;
case 508:
#line 11005 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 58: goto tr663;
		case 59: goto tr661;
		case 61: goto tr661;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr661;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr661;
		} else
			goto tr662;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr661;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr661;
		} else
			goto tr662;
	} else
		goto tr662;
	goto tr472;
tr661:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st509;
st509:
	if ( ++p == pe )
		goto _test_eof509;
case 509:
#line 11042 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr661;
		case 61: goto tr661;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr661;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr661;
		} else
			goto tr662;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr661;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr661;
		} else
			goto tr662;
	} else
		goto tr662;
	goto tr472;
tr662:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st510;
st510:
	if ( ++p == pe )
		goto _test_eof510;
case 510:
#line 11078 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 58: goto tr663;
		case 61: goto tr662;
	}
	if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr662;
	} else if ( (*p) >= 33 )
		goto tr662;
	goto tr472;
tr663:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st511;
st511:
	if ( ++p == pe )
		goto _test_eof511;
case 511:
#line 11099 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr664;
	goto tr472;
tr664:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st512;
st512:
	if ( ++p == pe )
		goto _test_eof512;
case 512:
#line 11113 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 91 )
		goto tr647;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr664;
	goto tr472;
tr660:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st513;
st513:
	if ( ++p == pe )
		goto _test_eof513;
case 513:
#line 11129 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr665;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr665;
	} else
		goto tr665;
	goto tr472;
tr665:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st514;
st514:
	if ( ++p == pe )
		goto _test_eof514;
case 514:
#line 11149 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr666;
		case 62: goto tr668;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr666;
		} else if ( (*p) > 57 ) {
			if ( 61 <= (*p) && (*p) <= 64 )
				goto tr666;
		} else
			goto tr667;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr666;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr666;
		} else
			goto tr667;
	} else
		goto tr667;
	goto tr472;
tr666:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st515;
st515:
	if ( ++p == pe )
		goto _test_eof515;
case 515:
#line 11185 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr666;
		case 61: goto tr666;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr666;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr666;
		} else
			goto tr667;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr666;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr666;
		} else
			goto tr667;
	} else
		goto tr667;
	goto tr472;
tr667:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st516;
st516:
	if ( ++p == pe )
		goto _test_eof516;
case 516:
#line 11221 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr667;
		case 62: goto tr668;
	}
	if ( (*p) > 57 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr667;
	} else if ( (*p) >= 33 )
		goto tr667;
	goto tr472;
tr668:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st517;
st517:
	if ( ++p == pe )
		goto _test_eof517;
case 517:
#line 11242 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 58 )
		goto tr663;
	goto tr472;
tr658:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st518;
st518:
	if ( ++p == pe )
		goto _test_eof518;
case 518:
#line 11256 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 60 )
		goto tr670;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr669;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr669;
	} else
		goto tr669;
	goto tr472;
tr669:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st519;
st519:
	if ( ++p == pe )
		goto _test_eof519;
case 519:
#line 11278 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 58: goto tr673;
		case 59: goto tr671;
		case 61: goto tr671;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr671;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr671;
		} else
			goto tr672;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr671;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr671;
		} else
			goto tr672;
	} else
		goto tr672;
	goto tr472;
tr671:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st520;
st520:
	if ( ++p == pe )
		goto _test_eof520;
case 520:
#line 11315 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr671;
		case 61: goto tr671;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr671;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr671;
		} else
			goto tr672;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr671;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr671;
		} else
			goto tr672;
	} else
		goto tr672;
	goto tr472;
tr672:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st521;
st521:
	if ( ++p == pe )
		goto _test_eof521;
case 521:
#line 11351 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 58: goto tr673;
		case 61: goto tr672;
	}
	if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr672;
	} else if ( (*p) >= 33 )
		goto tr672;
	goto tr472;
tr673:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st522;
st522:
	if ( ++p == pe )
		goto _test_eof522;
case 522:
#line 11372 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr674;
	goto tr472;
tr674:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st523;
st523:
	if ( ++p == pe )
		goto _test_eof523;
case 523:
#line 11386 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 93 )
		goto tr647;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr674;
	goto tr472;
tr670:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st524;
st524:
	if ( ++p == pe )
		goto _test_eof524;
case 524:
#line 11402 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr675;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr675;
	} else
		goto tr675;
	goto tr472;
tr675:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st525;
st525:
	if ( ++p == pe )
		goto _test_eof525;
case 525:
#line 11422 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr676;
		case 62: goto tr678;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr676;
		} else if ( (*p) > 57 ) {
			if ( 61 <= (*p) && (*p) <= 64 )
				goto tr676;
		} else
			goto tr677;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr676;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr676;
		} else
			goto tr677;
	} else
		goto tr677;
	goto tr472;
tr676:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st526;
st526:
	if ( ++p == pe )
		goto _test_eof526;
case 526:
#line 11458 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr676;
		case 61: goto tr676;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr676;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr676;
		} else
			goto tr677;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr676;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr676;
		} else
			goto tr677;
	} else
		goto tr677;
	goto tr472;
tr677:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st527;
st527:
	if ( ++p == pe )
		goto _test_eof527;
case 527:
#line 11494 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr677;
		case 62: goto tr678;
	}
	if ( (*p) > 57 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr677;
	} else if ( (*p) >= 33 )
		goto tr677;
	goto tr472;
tr678:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st528;
st528:
	if ( ++p == pe )
		goto _test_eof528;
case 528:
#line 11515 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 58 )
		goto tr673;
	goto tr472;
tr477:
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
#line 11533 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 60 )
		goto tr680;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr679;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr679;
	} else
		goto tr679;
	goto tr472;
tr679:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st530;
st530:
	if ( ++p == pe )
		goto _test_eof530;
case 530:
#line 11555 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 58: goto tr683;
		case 59: goto tr681;
		case 61: goto tr681;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr681;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr681;
		} else
			goto tr682;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr681;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr681;
		} else
			goto tr682;
	} else
		goto tr682;
	goto tr472;
tr681:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st531;
st531:
	if ( ++p == pe )
		goto _test_eof531;
case 531:
#line 11592 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr681;
		case 61: goto tr681;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr681;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr681;
		} else
			goto tr682;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr681;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr681;
		} else
			goto tr682;
	} else
		goto tr682;
	goto tr472;
tr682:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st532;
st532:
	if ( ++p == pe )
		goto _test_eof532;
case 532:
#line 11628 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 58: goto tr683;
		case 61: goto tr682;
	}
	if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr682;
	} else if ( (*p) >= 33 )
		goto tr682;
	goto tr472;
tr683:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st533;
st533:
	if ( ++p == pe )
		goto _test_eof533;
case 533:
#line 11649 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr684;
	goto tr472;
tr684:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st534;
st534:
	if ( ++p == pe )
		goto _test_eof534;
case 534:
#line 11663 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 91 )
		goto tr685;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr684;
	goto tr472;
tr680:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st535;
st535:
	if ( ++p == pe )
		goto _test_eof535;
case 535:
#line 11679 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr686;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr686;
	} else
		goto tr686;
	goto tr472;
tr686:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st536;
st536:
	if ( ++p == pe )
		goto _test_eof536;
case 536:
#line 11699 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr687;
		case 62: goto tr689;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr687;
		} else if ( (*p) > 57 ) {
			if ( 61 <= (*p) && (*p) <= 64 )
				goto tr687;
		} else
			goto tr688;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr687;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr687;
		} else
			goto tr688;
	} else
		goto tr688;
	goto tr472;
tr687:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st537;
st537:
	if ( ++p == pe )
		goto _test_eof537;
case 537:
#line 11735 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr687;
		case 61: goto tr687;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr687;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr687;
		} else
			goto tr688;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr687;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr687;
		} else
			goto tr688;
	} else
		goto tr688;
	goto tr472;
tr688:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st538;
st538:
	if ( ++p == pe )
		goto _test_eof538;
case 538:
#line 11771 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr688;
		case 62: goto tr689;
	}
	if ( (*p) > 57 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr688;
	} else if ( (*p) >= 33 )
		goto tr688;
	goto tr472;
tr689:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st539;
st539:
	if ( ++p == pe )
		goto _test_eof539;
case 539:
#line 11792 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 58 )
		goto tr683;
	goto tr472;
tr478:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st540;
st540:
	if ( ++p == pe )
		goto _test_eof540;
case 540:
#line 11810 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 60 )
		goto tr691;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr690;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr690;
	} else
		goto tr690;
	goto tr472;
tr690:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st541;
st541:
	if ( ++p == pe )
		goto _test_eof541;
case 541:
#line 11832 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 58: goto tr694;
		case 59: goto tr692;
		case 61: goto tr692;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr692;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr692;
		} else
			goto tr693;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr692;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr692;
		} else
			goto tr693;
	} else
		goto tr693;
	goto tr472;
tr692:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st542;
st542:
	if ( ++p == pe )
		goto _test_eof542;
case 542:
#line 11869 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr692;
		case 61: goto tr692;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr692;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr692;
		} else
			goto tr693;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr692;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr692;
		} else
			goto tr693;
	} else
		goto tr693;
	goto tr472;
tr693:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st543;
st543:
	if ( ++p == pe )
		goto _test_eof543;
case 543:
#line 11905 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 58: goto tr694;
		case 61: goto tr693;
	}
	if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr693;
	} else if ( (*p) >= 33 )
		goto tr693;
	goto tr472;
tr694:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st544;
st544:
	if ( ++p == pe )
		goto _test_eof544;
case 544:
#line 11926 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr695;
	goto tr472;
tr695:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st545;
st545:
	if ( ++p == pe )
		goto _test_eof545;
case 545:
#line 11940 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 93 )
		goto tr685;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr695;
	goto tr472;
tr691:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st546;
st546:
	if ( ++p == pe )
		goto _test_eof546;
case 546:
#line 11956 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr696;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr696;
	} else
		goto tr696;
	goto tr472;
tr696:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st547;
st547:
	if ( ++p == pe )
		goto _test_eof547;
case 547:
#line 11976 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr697;
		case 62: goto tr699;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr697;
		} else if ( (*p) > 57 ) {
			if ( 61 <= (*p) && (*p) <= 64 )
				goto tr697;
		} else
			goto tr698;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr697;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr697;
		} else
			goto tr698;
	} else
		goto tr698;
	goto tr472;
tr697:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st548;
st548:
	if ( ++p == pe )
		goto _test_eof548;
case 548:
#line 12012 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr697;
		case 61: goto tr697;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr697;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr697;
		} else
			goto tr698;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr697;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr697;
		} else
			goto tr698;
	} else
		goto tr698;
	goto tr472;
tr698:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st549;
st549:
	if ( ++p == pe )
		goto _test_eof549;
case 549:
#line 12048 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr698;
		case 62: goto tr699;
	}
	if ( (*p) > 57 ) {
		if ( 61 <= (*p) && (*p) <= 126 )
			goto tr698;
	} else if ( (*p) >= 33 )
		goto tr698;
	goto tr472;
tr699:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st550;
st550:
	if ( ++p == pe )
		goto _test_eof550;
case 550:
#line 12069 "cpp/src/bioformats/vcf/validator_detail.hpp"
	if ( (*p) == 58 )
		goto tr694;
	goto tr472;
tr474:
#line 15 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st551;
st551:
	if ( ++p == pe )
		goto _test_eof551;
case 551:
#line 12087 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr479;
		case 65: goto tr642;
		case 67: goto tr642;
		case 71: goto tr642;
		case 78: goto tr642;
		case 84: goto tr642;
		case 97: goto tr642;
		case 99: goto tr642;
		case 103: goto tr642;
		case 110: goto tr642;
		case 116: goto tr642;
	}
	goto tr472;
tr457:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st552;
st552:
	if ( ++p == pe )
		goto _test_eof552;
case 552:
#line 12112 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 59: goto tr457;
		case 61: goto tr457;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto tr457;
		} else if ( (*p) > 57 ) {
			if ( 63 <= (*p) && (*p) <= 64 )
				goto tr457;
		} else
			goto tr458;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr457;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr457;
		} else
			goto tr458;
	} else
		goto tr458;
	goto tr455;
tr458:
#line 19 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_token_char(*this, *p);
    }
	goto st553;
st553:
	if ( ++p == pe )
		goto _test_eof553;
case 553:
#line 12148 "cpp/src/bioformats/vcf/validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr456;
		case 59: goto tr458;
		case 61: goto tr458;
	}
	if ( (*p) > 57 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr458;
	} else if ( (*p) >= 33 )
		goto tr458;
	goto tr455;
st554:
	if ( ++p == pe )
		goto _test_eof554;
case 554:
	if ( (*p) == 10 )
		goto tr701;
	goto st554;
tr701:
#line 28 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;
    }
#line 693 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{ {goto st20;} }
	goto st558;
st558:
	if ( ++p == pe )
		goto _test_eof558;
case 558:
#line 12181 "cpp/src/bioformats/vcf/validator_detail.hpp"
	goto st0;
st555:
	if ( ++p == pe )
		goto _test_eof555;
case 555:
	if ( (*p) == 10 )
		goto tr703;
	goto st555;
tr703:
#line 28 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ParsePolicy::handle_newline(*this);
        ++n_lines;
        n_columns = 1;
    }
#line 694 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{ {goto st557;} }
	goto st559;
st559:
	if ( ++p == pe )
		goto _test_eof559;
case 559:
#line 12204 "cpp/src/bioformats/vcf/validator_detail.hpp"
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
	_test_eof556: cs = 556; goto _test_eof; 
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
	_test_eof557: cs = 557; goto _test_eof; 
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
	_test_eof558: cs = 558; goto _test_eof; 
	_test_eof555: cs = 555; goto _test_eof; 
	_test_eof559: cs = 559; goto _test_eof; 

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
        p--; {goto st554;}
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
        p--; {goto st554;}
    }
	break;
	case 350: 
	case 351: 
	case 352: 
	case 353: 
	case 354: 
	case 355: 
	case 356: 
	case 357: 
	case 358: 
#line 60 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        p--; {goto st555;}
    }
	break;
	case 14: 
	case 15: 
#line 188 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this,
            "Fileformat is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st554;}
    }
#line 42 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this);
        p--; {goto st554;}
    }
	break;
	case 30: 
	case 31: 
	case 32: 
	case 33: 
	case 34: 
	case 35: 
	case 36: 
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
	case 59: 
	case 60: 
#line 195 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
	break;
	case 260: 
	case 261: 
	case 262: 
	case 263: 
	case 264: 
	case 265: 
	case 266: 
	case 267: 
#line 206 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in assembly metadata");
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
	break;
	case 275: 
	case 276: 
	case 277: 
	case 278: 
	case 279: 
	case 280: 
	case 281: 
	case 282: 
	case 283: 
	case 284: 
	case 288: 
	case 289: 
	case 290: 
	case 291: 
	case 292: 
	case 293: 
#line 212 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in contig metadata");
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
	break;
	case 62: 
	case 63: 
	case 64: 
	case 65: 
	case 66: 
	case 67: 
	case 68: 
	case 69: 
	case 70: 
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
	case 93: 
	case 94: 
#line 218 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
	break;
	case 95: 
	case 96: 
	case 97: 
	case 98: 
	case 99: 
	case 100: 
	case 101: 
	case 102: 
	case 103: 
	case 107: 
	case 108: 
	case 109: 
	case 110: 
	case 111: 
	case 112: 
	case 113: 
	case 116: 
	case 117: 
	case 118: 
	case 119: 
	case 120: 
	case 123: 
	case 124: 
	case 125: 
	case 126: 
	case 127: 
	case 128: 
	case 129: 
	case 130: 
	case 131: 
	case 132: 
	case 133: 
	case 134: 
	case 135: 
	case 136: 
	case 142: 
	case 143: 
#line 224 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
	break;
	case 145: 
	case 146: 
	case 147: 
	case 148: 
	case 149: 
	case 150: 
	case 151: 
	case 152: 
	case 156: 
	case 157: 
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
	case 172: 
	case 173: 
	case 174: 
	case 175: 
	case 176: 
	case 177: 
	case 178: 
	case 179: 
	case 180: 
	case 181: 
	case 182: 
	case 183: 
	case 184: 
	case 185: 
	case 191: 
	case 192: 
#line 240 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
	break;
	case 194: 
	case 195: 
	case 196: 
	case 197: 
	case 198: 
	case 199: 
	case 200: 
	case 201: 
	case 202: 
	case 209: 
#line 256 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in PEDIGREE metadata");
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
	break;
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
#line 262 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in pedigreeDB metadata");
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
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
	case 219: 
	case 259: 
#line 268 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
	break;
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
#line 300 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this, "The header line does not start with the mandatory columns: CHROM, POS, ID, REF, ALT, QUAL, FILTER and INFO");
        p--; {goto st555;}
    }
#line 60 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        p--; {goto st555;}
    }
	break;
	case 359: 
	case 380: 
	case 381: 
	case 382: 
	case 383: 
	case 384: 
	case 552: 
	case 553: 
#line 308 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Chromosome is not a string without colons or whitespaces, optionally wrapped with angle brackets (<>)");
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	break;
	case 360: 
	case 361: 
#line 314 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Position is not a positive number");
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	break;
	case 362: 
	case 363: 
#line 320 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "ID is not a single dot or a list of strings without semicolons or whitespaces");
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	break;
	case 364: 
	case 365: 
#line 326 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Reference is not a string of bases");
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	break;
	case 366: 
	case 367: 
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
	case 551: 
#line 332 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Alternate is not a single dot or a comma-separated list of bases");
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	break;
	case 368: 
	case 369: 
	case 487: 
	case 488: 
	case 489: 
#line 338 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Quality is not a single dot or a positive number");
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	break;
	case 370: 
	case 371: 
	case 372: 
	case 485: 
	case 486: 
#line 344 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Filter is not a single dot or a semicolon-separated list of strings");
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	break;
	case 376: 
	case 377: 
#line 456 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Format is not a colon-separated list of alphanumeric strings");
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	break;
	case 386: 
	case 387: 
#line 462 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " is not a valid string";
        ErrorPolicy::handle_body_section_error(*this, message_stream.str());
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	break;
	case 17: 
	case 20: 
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
#line 300 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this, "The header line does not start with the mandatory columns: CHROM, POS, ID, REF, ALT, QUAL, FILTER and INFO");
        p--; {goto st555;}
    }
#line 60 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        p--; {goto st555;}
    }
	break;
	case 37: 
	case 38: 
	case 39: 
#line 200 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "ALT metadata ID is not prefixed by DEL/INS/DUP/INV/CNV and suffixed by ':' and a text sequence");
        p--; {goto st554;}
    }
#line 195 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
	break;
	case 61: 
#line 218 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st554;}
    }
#line 224 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
	break;
	case 114: 
	case 115: 
	case 144: 
#line 229 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "FORMAT metadata Number is not a number, A, R, G or dot");
        p--; {goto st554;}
    }
#line 224 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
	break;
	case 163: 
	case 164: 
	case 193: 
#line 245 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "INFO metadata Number is not a number, A, R, G or dot");
        p--; {goto st554;}
    }
#line 240 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
	break;
	case 121: 
	case 122: 
#line 250 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "INFO metadata Type is not a Integer, Float, Flag, Character or String");
        p--; {goto st554;}
    }
#line 224 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
	break;
	case 170: 
	case 171: 
#line 250 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "INFO metadata Type is not a Integer, Float, Flag, Character or String");
        p--; {goto st554;}
    }
#line 240 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
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
#line 273 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Genomes is not a valid string (maybe it contains quotes?)");
        p--; {goto st554;}
    }
#line 268 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
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
	case 241: 
#line 278 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Mixture is not a valid string (maybe it contains quotes?)");
        p--; {goto st554;}
    }
#line 268 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
	break;
	case 56: 
	case 57: 
	case 58: 
#line 284 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st554;}
    }
#line 195 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
	break;
	case 285: 
	case 286: 
	case 287: 
#line 284 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st554;}
    }
#line 212 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in contig metadata");
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
	break;
	case 71: 
	case 72: 
	case 73: 
	case 90: 
	case 91: 
	case 92: 
#line 284 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st554;}
    }
#line 218 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
	break;
	case 104: 
	case 105: 
	case 106: 
	case 139: 
	case 140: 
	case 141: 
#line 284 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st554;}
    }
#line 224 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
	break;
	case 153: 
	case 154: 
	case 155: 
	case 188: 
	case 189: 
	case 190: 
#line 284 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st554;}
    }
#line 240 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
	break;
	case 203: 
	case 204: 
	case 205: 
	case 206: 
	case 207: 
	case 208: 
#line 284 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st554;}
    }
#line 256 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in PEDIGREE metadata");
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
	break;
	case 220: 
	case 221: 
#line 284 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st554;}
    }
#line 268 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
	break;
	case 54: 
	case 55: 
#line 289 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st554;}
    }
#line 195 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
	break;
	case 88: 
	case 89: 
#line 289 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st554;}
    }
#line 218 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
	break;
	case 137: 
	case 138: 
#line 289 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st554;}
    }
#line 224 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
	break;
	case 186: 
	case 187: 
#line 289 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st554;}
    }
#line 240 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
	break;
	case 243: 
	case 244: 
	case 245: 
	case 246: 
	case 247: 
	case 248: 
	case 249: 
	case 250: 
	case 251: 
	case 252: 
	case 253: 
	case 254: 
	case 255: 
	case 256: 
	case 257: 
	case 258: 
#line 289 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st554;}
    }
#line 268 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
	break;
	case 268: 
	case 269: 
	case 270: 
	case 271: 
	case 272: 
	case 273: 
	case 274: 
#line 294 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata URL is not valid");
        p--; {goto st554;}
    }
#line 206 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in assembly metadata");
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
	break;
	case 305: 
	case 306: 
	case 307: 
	case 308: 
	case 309: 
	case 310: 
	case 311: 
	case 312: 
#line 294 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata URL is not valid");
        p--; {goto st554;}
    }
#line 262 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in pedigreeDB metadata");
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
	break;
	case 373: 
	case 374: 
	case 375: 
	case 388: 
	case 389: 
	case 390: 
	case 391: 
	case 392: 
	case 398: 
	case 399: 
	case 403: 
	case 406: 
	case 411: 
	case 414: 
	case 415: 
	case 420: 
	case 421: 
	case 422: 
	case 423: 
	case 424: 
	case 427: 
	case 431: 
	case 434: 
	case 435: 
	case 436: 
	case 439: 
	case 446: 
	case 447: 
	case 448: 
	case 455: 
	case 456: 
	case 459: 
	case 460: 
	case 465: 
	case 466: 
	case 467: 
	case 468: 
	case 469: 
	case 473: 
	case 474: 
	case 475: 
	case 476: 
	case 477: 
	case 478: 
	case 479: 
	case 480: 
	case 484: 
#line 355 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st555;}
    }
#line 350 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	break;
	case 393: 
	case 394: 
#line 360 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info field value is not a comma-separated list of valid strings (maybe it contains whitespaces?)");
        p--; {goto st555;}
    }
#line 350 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	break;
	case 400: 
	case 401: 
	case 402: 
#line 365 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info AA value is not a single dot or a string of bases");
        p--; {goto st555;}
    }
#line 350 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	break;
	case 404: 
	case 405: 
#line 370 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info AC value is not a comma-separated list of numbers");
        p--; {goto st555;}
    }
#line 350 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	break;
	case 407: 
	case 408: 
	case 409: 
	case 410: 
#line 375 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info AF value is not a comma-separated list of numbers");
        p--; {goto st555;}
    }
#line 350 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	break;
	case 412: 
	case 413: 
#line 380 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info AN value is not an integer number");
        p--; {goto st555;}
    }
#line 350 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	break;
	case 416: 
	case 417: 
	case 418: 
	case 419: 
#line 385 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info BQ value is not a number");
        p--; {goto st555;}
    }
#line 350 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	break;
	case 425: 
	case 426: 
#line 390 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info CIGAR value is not an alphanumeric string");
        p--; {goto st555;}
    }
#line 350 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	break;
	case 429: 
	case 430: 
#line 395 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info DB is not a flag (with 1/0/no value)");
        p--; {goto st555;}
    }
#line 350 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	break;
	case 432: 
	case 433: 
#line 400 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info DP value is not an integer number");
        p--; {goto st555;}
    }
#line 350 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	break;
	case 437: 
	case 438: 
#line 405 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info END value is not an integer number");
        p--; {goto st555;}
    }
#line 350 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	break;
	case 441: 
	case 442: 
#line 410 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info H2 is not a flag (with 1/0/no value)");
        p--; {goto st555;}
    }
#line 350 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	break;
	case 444: 
	case 445: 
#line 415 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info H3 is not a flag (with 1/0/no value)");
        p--; {goto st555;}
    }
#line 350 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	break;
	case 451: 
	case 452: 
	case 453: 
	case 454: 
#line 420 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info MQ value is not a number");
        p--; {goto st555;}
    }
#line 350 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	break;
	case 449: 
	case 450: 
#line 425 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info MQ0 value is not an integer number");
        p--; {goto st555;}
    }
#line 350 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	break;
	case 457: 
	case 458: 
#line 430 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info NS value is not an integer number");
        p--; {goto st555;}
    }
#line 350 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	break;
	case 461: 
	case 462: 
	case 463: 
	case 464: 
#line 435 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info SB value is not a number");
        p--; {goto st555;}
    }
#line 350 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	break;
	case 471: 
	case 472: 
#line 440 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info SOMATIC is not a flag (with 1/0/no value)");
        p--; {goto st555;}
    }
#line 350 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	break;
	case 482: 
	case 483: 
#line 445 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info VALIDATED is not a flag (with 1/0/no value)");
        p--; {goto st555;}
    }
#line 350 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	break;
	case 396: 
	case 397: 
#line 450 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info 1000G is not a flag (with 1/0/no value)");
        p--; {goto st555;}
    }
#line 350 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	break;
	case 378: 
	case 379: 
	case 385: 
#line 469 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " does not start with a valid genotype";
        ErrorPolicy::handle_body_section_error(*this, message_stream.str());
        p--; {goto st555;}
    }
#line 462 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        std::ostringstream message_stream;
        message_stream << "Sample #" << (n_columns - 9) << " is not a valid string";
        ErrorPolicy::handle_body_section_error(*this, message_stream.str());
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	break;
	case 16: 
#line 42 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this);
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
#line 300 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this, "The header line does not start with the mandatory columns: CHROM, POS, ID, REF, ALT, QUAL, FILTER and INFO");
        p--; {goto st555;}
    }
#line 60 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        p--; {goto st555;}
    }
	break;
	case 232: 
#line 273 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Genomes is not a valid string (maybe it contains quotes?)");
        p--; {goto st554;}
    }
#line 278 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Mixture is not a valid string (maybe it contains quotes?)");
        p--; {goto st554;}
    }
#line 268 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
	break;
	case 242: 
#line 278 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Mixture is not a valid string (maybe it contains quotes?)");
        p--; {goto st554;}
    }
#line 289 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata description string is not valid");
        p--; {goto st554;}
    }
#line 268 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
	break;
	case 222: 
#line 284 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Metadata ID contains a character different from alphanumeric, dot, underscore and dash");
        p--; {goto st554;}
    }
#line 273 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "SAMPLE metadata Genomes is not a valid string (maybe it contains quotes?)");
        p--; {goto st554;}
    }
#line 268 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
	break;
	case 428: 
#line 395 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info DB is not a flag (with 1/0/no value)");
        p--; {goto st555;}
    }
#line 355 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st555;}
    }
#line 350 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	break;
	case 440: 
#line 410 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info H2 is not a flag (with 1/0/no value)");
        p--; {goto st555;}
    }
#line 355 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st555;}
    }
#line 350 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	break;
	case 443: 
#line 415 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info H3 is not a flag (with 1/0/no value)");
        p--; {goto st555;}
    }
#line 355 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st555;}
    }
#line 350 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	break;
	case 470: 
#line 440 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info SOMATIC is not a flag (with 1/0/no value)");
        p--; {goto st555;}
    }
#line 355 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st555;}
    }
#line 350 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	break;
	case 481: 
#line 445 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info VALIDATED is not a flag (with 1/0/no value)");
        p--; {goto st555;}
    }
#line 355 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st555;}
    }
#line 350 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	break;
	case 395: 
#line 450 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info 1000G is not a flag (with 1/0/no value)");
        p--; {goto st555;}
    }
#line 355 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info key is not a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st555;}
    }
#line 350 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Info is not a single dot or a semicolon-separated list of key-value pairs");
        p--; {goto st555;}
    }
#line 65 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st555;}
    }
	break;
	case 18: 
#line 195 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in ALT metadata");
        p--; {goto st554;}
    }
#line 218 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FILTER metadata");
        p--; {goto st554;}
    }
#line 224 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in FORMAT metadata");
        p--; {goto st554;}
    }
#line 240 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in INFO metadata");
        p--; {goto st554;}
    }
#line 206 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in assembly metadata");
        p--; {goto st554;}
    }
#line 212 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in contig metadata");
        p--; {goto st554;}
    }
#line 268 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in SAMPLE metadata");
        p--; {goto st554;}
    }
#line 256 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in PEDIGREE metadata");
        p--; {goto st554;}
    }
#line 262 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this, "Error in pedigreeDB metadata");
        p--; {goto st554;}
    }
#line 47 "cpp/src/bioformats/vcf/vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st554;}
    }
	break;
#line 14533 "cpp/src/bioformats/vcf/validator_detail.hpp"
	}
	}

	_out: {}
	}

#line 757 "cpp/src/bioformats/vcf/vcf_v41.ragel"

    }

    
    template <typename Configuration>
    void Parser<Configuration>::optional_check_meta_section() const
    {
      if (source->meta_entries.find("reference") == source->meta_entries.end()) {
        throw ParsingWarning("It is recommended to include a 'reference' entry in the meta section");
      }
    }
    
    template <typename Configuration>
    void Parser<Configuration>::optional_check_body_entry() const
    {
      // All samples should have the same ploidy
      int ploidy = -1;
      auto samples = ParsePolicy::column_tokens("SAMPLES");
      for (size_t i = 0; i < samples.size(); ++i) {
        auto & sample = samples[i];
        std::vector<std::string> subfields;
        boost::split(subfields, sample, boost::is_any_of(":"));
        std::vector<std::string> alleles;
        boost::split(alleles, subfields[0], boost::is_any_of("|,/"));

        if (ploidy > 0) {
          if (alleles.size() != ploidy) {
            throw ParsingWarning("Sample #" + std::to_string(i) + " has " + std::to_string(alleles.size()) + 
                                 " allele(s), but " + std::to_string(ploidy) + " were found in others");
          }
        } else {
          ploidy = alleles.size();
        }
      }
    }
    
    template <typename Configuration>
    void Parser<Configuration>::optional_check_body_section() const
    {
      
    }
    
  }
}
