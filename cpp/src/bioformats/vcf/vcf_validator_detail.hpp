
#line 1 "vcf_v41.ragel"
#include <cstdio>

#include "vcf_validator.hpp"


#line 405 "vcf_v41.ragel"


namespace
{
  
#line 15 "vcf_validator_detail.hpp"
static const int vcf_start = 1;
static const int vcf_first_final = 497;
static const int vcf_error = 0;

static const int vcf_en_main = 1;
static const int vcf_en_main_meta_section = 29;
static const int vcf_en_main_body_section = 498;
static const int vcf_en_meta_section_skip = 495;
static const int vcf_en_body_section_skip = 496;


#line 411 "vcf_v41.ragel"

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

#line 423 "vcf_v41.ragel"

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
497
#line 456 "vcf_v41.ragel"
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
#line 29 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this);
        p--; {goto st495;}
    }
	goto st0;
tr14:
#line 53 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this,
            "Fileformat must be a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st495;}
    }
#line 29 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this);
        p--; {goto st495;}
    }
	goto st0;
tr18:
#line 29 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this);
        p--; {goto st495;}
    }
#line 277 "vcf_v41.ragel"
	{
        printf("Meta error in line %zu\n", n_lines);
        p--; {goto st495;}
    }
#line 257 "vcf_v41.ragel"
	{
        printf("Meta ALT error in line %zu\n", n_lines);
        p--; {goto st495;}
    }
#line 262 "vcf_v41.ragel"
	{
        printf("Meta FILTER error in line %zu\n", n_lines);
        p--; {goto st495;}
    }
#line 267 "vcf_v41.ragel"
	{
        printf("Meta FORMAT error in line %zu\n", n_lines);
        p--; {goto st495;}
    }
#line 272 "vcf_v41.ragel"
	{
        printf("Meta INFO error in line %zu\n", n_lines);
        p--; {goto st495;}
    }
#line 34 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st495;}
    }
#line 39 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        p--; {goto st496;}
    }
	goto st0;
tr20:
#line 277 "vcf_v41.ragel"
	{
        printf("Meta error in line %zu\n", n_lines);
        p--; {goto st495;}
    }
#line 257 "vcf_v41.ragel"
	{
        printf("Meta ALT error in line %zu\n", n_lines);
        p--; {goto st495;}
    }
#line 262 "vcf_v41.ragel"
	{
        printf("Meta FILTER error in line %zu\n", n_lines);
        p--; {goto st495;}
    }
#line 267 "vcf_v41.ragel"
	{
        printf("Meta FORMAT error in line %zu\n", n_lines);
        p--; {goto st495;}
    }
#line 272 "vcf_v41.ragel"
	{
        printf("Meta INFO error in line %zu\n", n_lines);
        p--; {goto st495;}
    }
#line 34 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st495;}
    }
#line 39 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        p--; {goto st496;}
    }
	goto st0;
tr36:
#line 277 "vcf_v41.ragel"
	{
        printf("Meta error in line %zu\n", n_lines);
        p--; {goto st495;}
    }
#line 34 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st495;}
    }
	goto st0;
tr50:
#line 34 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st495;}
    }
	goto st0;
tr62:
#line 257 "vcf_v41.ragel"
	{
        printf("Meta ALT error in line %zu\n", n_lines);
        p--; {goto st495;}
    }
#line 34 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st495;}
    }
	goto st0;
tr98:
#line 262 "vcf_v41.ragel"
	{
        printf("Meta FILTER error in line %zu\n", n_lines);
        p--; {goto st495;}
    }
#line 267 "vcf_v41.ragel"
	{
        printf("Meta FORMAT error in line %zu\n", n_lines);
        p--; {goto st495;}
    }
#line 34 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st495;}
    }
	goto st0;
tr101:
#line 262 "vcf_v41.ragel"
	{
        printf("Meta FILTER error in line %zu\n", n_lines);
        p--; {goto st495;}
    }
#line 34 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st495;}
    }
	goto st0;
tr130:
#line 267 "vcf_v41.ragel"
	{
        printf("Meta FORMAT error in line %zu\n", n_lines);
        p--; {goto st495;}
    }
#line 34 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st495;}
    }
	goto st0;
tr197:
#line 272 "vcf_v41.ragel"
	{
        printf("Meta INFO error in line %zu\n", n_lines);
        p--; {goto st495;}
    }
#line 34 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st495;}
    }
	goto st0;
tr400:
#line 39 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        p--; {goto st496;}
    }
	goto st0;
tr450:
#line 124 "vcf_v41.ragel"
	{
    }
#line 44 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st496;}
    }
	goto st0;
tr453:
#line 133 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Position must be a positive number");
        p--; {goto st496;}
    }
#line 44 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st496;}
    }
	goto st0;
tr457:
#line 142 "vcf_v41.ragel"
	{
        printf("Line %zu: Error in 'id' field\n", n_lines);
 //       vcf_record_free(status->current_record);
    }
#line 44 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st496;}
    }
	goto st0;
tr461:
#line 151 "vcf_v41.ragel"
	{
        printf("Line %zu: Error in 'reference' field\n", n_lines);
//        vcf_record_free(status->current_record);
    }
#line 44 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st496;}
    }
	goto st0;
tr465:
#line 176 "vcf_v41.ragel"
	{
        printf("Line %zu: Error in 'alternate' field\n", n_lines);
 //       vcf_record_free(status->current_record);
    }
#line 44 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st496;}
    }
	goto st0;
tr475:
#line 191 "vcf_v41.ragel"
	{
        printf("Line %zu: Error in 'quality' field\n", n_lines);
 //       vcf_record_free(status->current_record);
    }
#line 44 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st496;}
    }
	goto st0;
tr479:
#line 200 "vcf_v41.ragel"
	{
        printf("Line %zu: Error in 'filter' field\n", n_lines);
 //       vcf_record_free(status->current_record);
    }
#line 44 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st496;}
    }
	goto st0;
tr484:
#line 209 "vcf_v41.ragel"
	{
        printf("Line %zu: Error in 'info' field\n", n_lines);
 //       vcf_record_free(status->current_record);
    }
#line 44 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st496;}
    }
	goto st0;
tr491:
#line 218 "vcf_v41.ragel"
	{
        printf("Line %zu: Error in 'format' field\n", n_lines);
 //       vcf_record_free(status->current_record);
    }
#line 44 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st496;}
    }
	goto st0;
tr496:
#line 227 "vcf_v41.ragel"
	{
        printf("Line %zu: Error in sample\n", n_lines);
//        vcf_record_free(status->current_record);
    }
#line 44 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st496;}
    }
	goto st0;
tr554:
#line 39 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        p--; {goto st496;}
    }
#line 124 "vcf_v41.ragel"
	{
    }
#line 44 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st496;}
    }
	goto st0;
#line 425 "vcf_validator_detail.hpp"
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
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st15;
st15:
	if ( ++p == pe )
		goto _test_eof15;
case 15:
#line 530 "vcf_validator_detail.hpp"
	if ( (*p) == 10 )
		goto tr16;
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st15;
	goto tr14;
tr16:
#line 49 "vcf_v41.ragel"
	{
//        set_vcf_file_format(ts, p-ts, file);
    }
#line 20 "vcf_v41.ragel"
	{
        ++n_lines;
        n_columns = 1;
    }
	goto st16;
st16:
	if ( ++p == pe )
		goto _test_eof16;
case 16:
#line 551 "vcf_validator_detail.hpp"
	if ( (*p) == 35 )
		goto tr19;
	goto tr18;
tr19:
#line 59 "vcf_v41.ragel"
	{
//        printf("Reading meta entry\n");
//        status->current_meta_entry = vcf_meta_entry_new();
    }
	goto st17;
st17:
	if ( ++p == pe )
		goto _test_eof17;
case 17:
#line 566 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 35: goto st18;
		case 67: goto st375;
	}
	goto tr20;
st18:
	if ( ++p == pe )
		goto _test_eof18;
case 18:
	switch( (*p) ) {
		case 33: goto tr25;
		case 65: goto tr27;
		case 67: goto tr26;
		case 70: goto tr29;
		case 73: goto tr30;
		case 80: goto tr31;
		case 81: goto tr26;
		case 83: goto tr32;
		case 97: goto tr33;
		case 99: goto tr34;
		case 102: goto tr26;
		case 104: goto tr26;
		case 112: goto tr35;
		case 113: goto tr26;
		case 121: goto tr28;
		case 124: goto tr24;
	}
	if ( (*p) < 76 ) {
		if ( (*p) < 58 ) {
			if ( (*p) < 35 ) {
				if ( 32 <= (*p) && (*p) <= 34 )
					goto tr24;
			} else if ( (*p) > 47 ) {
				if ( 48 <= (*p) && (*p) <= 57 )
					goto tr26;
			} else
				goto tr25;
		} else if ( (*p) > 60 ) {
			if ( (*p) < 66 ) {
				if ( 62 <= (*p) && (*p) <= 64 )
					goto tr25;
			} else if ( (*p) > 71 ) {
				if ( 72 <= (*p) && (*p) <= 75 )
					goto tr26;
			} else
				goto tr28;
		} else
			goto tr25;
	} else if ( (*p) > 84 ) {
		if ( (*p) < 106 ) {
			if ( (*p) < 91 ) {
				if ( 85 <= (*p) && (*p) <= 90 )
					goto tr26;
			} else if ( (*p) > 96 ) {
				if ( 98 <= (*p) && (*p) <= 105 )
					goto tr28;
			} else
				goto tr25;
		} else if ( (*p) > 107 ) {
			if ( (*p) < 117 ) {
				if ( 108 <= (*p) && (*p) <= 116 )
					goto tr28;
			} else if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto tr25;
			} else
				goto tr26;
		} else
			goto tr26;
	} else
		goto tr28;
	goto st19;
st19:
	if ( ++p == pe )
		goto _test_eof19;
case 19:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr37;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr37;
	} else
		goto tr37;
	goto tr36;
tr37:
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st20;
st20:
	if ( ++p == pe )
		goto _test_eof20;
case 20:
#line 662 "vcf_validator_detail.hpp"
	if ( (*p) == 61 )
		goto tr39;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st20;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st20;
	} else
		goto st20;
	goto tr36;
tr39:
#line 68 "vcf_v41.ragel"
	{
//        set_vcf_meta_entry_name(ts, p-ts, status->current_meta_entry);
    }
	goto st21;
st21:
	if ( ++p == pe )
		goto _test_eof21;
case 21:
#line 684 "vcf_validator_detail.hpp"
	if ( (*p) == 60 )
		goto st22;
	goto tr36;
st22:
	if ( ++p == pe )
		goto _test_eof22;
case 22:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr41;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr41;
	} else
		goto tr41;
	goto tr36;
tr41:
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st23;
st23:
	if ( ++p == pe )
		goto _test_eof23;
case 23:
#line 711 "vcf_validator_detail.hpp"
	if ( (*p) == 61 )
		goto st24;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st23;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st23;
	} else
		goto st23;
	goto tr36;
st24:
	if ( ++p == pe )
		goto _test_eof24;
case 24:
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st25;
	} else if ( (*p) >= 32 )
		goto st25;
	goto tr36;
st25:
	if ( ++p == pe )
		goto _test_eof25;
case 25:
	switch( (*p) ) {
		case 44: goto tr45;
		case 62: goto tr46;
	}
	if ( (*p) > 60 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto st25;
	} else if ( (*p) >= 32 )
		goto st25;
	goto tr36;
tr45:
#line 72 "vcf_v41.ragel"
	{
/*        if (*ts == '<') {
            add_vcf_meta_entry_value(ts+1, p-ts-1, status->current_meta_entry);
        } else if (*(p-1) == '>') {
            add_vcf_meta_entry_value(ts, p-ts-1, status->current_meta_entry);
        } else {
            add_vcf_meta_entry_value(ts, p-ts, status->current_meta_entry);
        }*/
    }
	goto st26;
st26:
	if ( ++p == pe )
		goto _test_eof26;
case 26:
#line 763 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto tr45;
		case 62: goto tr46;
	}
	if ( (*p) < 63 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st25;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 60 )
				goto st25;
		} else
			goto tr47;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr47;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto st25;
			} else if ( (*p) >= 97 )
				goto tr47;
		} else
			goto st25;
	} else
		goto st25;
	goto tr36;
tr47:
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st27;
st27:
	if ( ++p == pe )
		goto _test_eof27;
case 27:
#line 802 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto tr45;
		case 61: goto st24;
		case 62: goto tr46;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st25;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st25;
		} else
			goto st27;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st25;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st25;
		} else
			goto st27;
	} else
		goto st27;
	goto tr36;
tr46:
#line 72 "vcf_v41.ragel"
	{
/*        if (*ts == '<') {
            add_vcf_meta_entry_value(ts+1, p-ts-1, status->current_meta_entry);
        } else if (*(p-1) == '>') {
            add_vcf_meta_entry_value(ts, p-ts-1, status->current_meta_entry);
        } else {
            add_vcf_meta_entry_value(ts, p-ts, status->current_meta_entry);
        }*/
    }
	goto st28;
st28:
	if ( ++p == pe )
		goto _test_eof28;
case 28:
#line 845 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr49;
		case 44: goto tr45;
		case 62: goto tr46;
	}
	if ( (*p) > 60 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto st25;
	} else if ( (*p) >= 32 )
		goto st25;
	goto tr36;
tr49:
#line 252 "vcf_v41.ragel"
	{
        printf("Meta in line %zu\n", n_lines);
    }
#line 64 "vcf_v41.ragel"
	{
//        add_vcf_meta_entry(status->current_meta_entry, file);
    }
#line 20 "vcf_v41.ragel"
	{
        ++n_lines;
        n_columns = 1;
    }
	goto st29;
tr51:
#line 72 "vcf_v41.ragel"
	{
/*        if (*ts == '<') {
            add_vcf_meta_entry_value(ts+1, p-ts-1, status->current_meta_entry);
        } else if (*(p-1) == '>') {
            add_vcf_meta_entry_value(ts, p-ts-1, status->current_meta_entry);
        } else {
            add_vcf_meta_entry_value(ts, p-ts, status->current_meta_entry);
        }*/
    }
#line 64 "vcf_v41.ragel"
	{
//        add_vcf_meta_entry(status->current_meta_entry, file);
    }
#line 20 "vcf_v41.ragel"
	{
        ++n_lines;
        n_columns = 1;
    }
	goto st29;
tr94:
#line 236 "vcf_v41.ragel"
	{
        printf("Meta ALT in line %zu\n", n_lines);
    }
#line 64 "vcf_v41.ragel"
	{
//        add_vcf_meta_entry(status->current_meta_entry, file);
    }
#line 20 "vcf_v41.ragel"
	{
        ++n_lines;
        n_columns = 1;
    }
	goto st29;
tr129:
#line 240 "vcf_v41.ragel"
	{
        printf("Meta FILTER in line %zu\n", n_lines);
    }
#line 64 "vcf_v41.ragel"
	{
//        add_vcf_meta_entry(status->current_meta_entry, file);
    }
#line 20 "vcf_v41.ragel"
	{
        ++n_lines;
        n_columns = 1;
    }
	goto st29;
tr186:
#line 244 "vcf_v41.ragel"
	{
        printf("Meta FORMAT in line %zu\n", n_lines);
    }
#line 64 "vcf_v41.ragel"
	{
//        add_vcf_meta_entry(status->current_meta_entry, file);
    }
#line 20 "vcf_v41.ragel"
	{
        ++n_lines;
        n_columns = 1;
    }
	goto st29;
tr278:
#line 248 "vcf_v41.ragel"
	{
        printf("Meta INFO in line %zu\n", n_lines);
    }
#line 64 "vcf_v41.ragel"
	{
//        add_vcf_meta_entry(status->current_meta_entry, file);
    }
#line 20 "vcf_v41.ragel"
	{
        ++n_lines;
        n_columns = 1;
    }
	goto st29;
tr309:
#line 64 "vcf_v41.ragel"
	{
//        add_vcf_meta_entry(status->current_meta_entry, file);
    }
#line 20 "vcf_v41.ragel"
	{
        ++n_lines;
        n_columns = 1;
    }
	goto st29;
st29:
	if ( ++p == pe )
		goto _test_eof29;
case 29:
#line 968 "vcf_validator_detail.hpp"
	if ( (*p) == 35 )
		goto tr19;
	goto tr20;
tr24:
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st30;
st30:
	if ( ++p == pe )
		goto _test_eof30;
case 30:
#line 982 "vcf_validator_detail.hpp"
	if ( (*p) == 10 )
		goto tr51;
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st30;
	} else if ( (*p) >= 32 )
		goto st30;
	goto tr50;
tr25:
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st31;
st31:
	if ( ++p == pe )
		goto _test_eof31;
case 31:
#line 1001 "vcf_validator_detail.hpp"
	if ( (*p) == 10 )
		goto tr51;
	if ( (*p) < 62 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st30;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 60 )
				goto st30;
		} else
			goto tr53;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr53;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto st30;
			} else if ( (*p) >= 97 )
				goto tr53;
		} else
			goto st30;
	} else
		goto st30;
	goto tr36;
tr53:
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st32;
st32:
	if ( ++p == pe )
		goto _test_eof32;
case 32:
#line 1038 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr51;
		case 61: goto tr39;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st30;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st30;
		} else
			goto st32;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st30;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st30;
		} else
			goto st32;
	} else
		goto st32;
	goto tr36;
tr26:
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st33;
st33:
	if ( ++p == pe )
		goto _test_eof33;
case 33:
#line 1074 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr51;
		case 61: goto st38;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st30;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st30;
		} else
			goto tr55;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st30;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st30;
		} else
			goto tr55;
	} else
		goto tr55;
	goto tr36;
tr55:
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st34;
st34:
	if ( ++p == pe )
		goto _test_eof34;
case 34:
#line 1110 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr51;
		case 61: goto tr58;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st30;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st30;
		} else
			goto st34;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st30;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st30;
		} else
			goto st34;
	} else
		goto st34;
	goto tr36;
tr58:
#line 68 "vcf_v41.ragel"
	{
//        set_vcf_meta_entry_name(ts, p-ts, status->current_meta_entry);
    }
	goto st35;
st35:
	if ( ++p == pe )
		goto _test_eof35;
case 35:
#line 1146 "vcf_validator_detail.hpp"
	if ( (*p) == 60 )
		goto st36;
	if ( (*p) > 59 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st30;
	} else if ( (*p) >= 32 )
		goto st30;
	goto tr36;
st36:
	if ( ++p == pe )
		goto _test_eof36;
case 36:
	if ( (*p) == 10 )
		goto tr51;
	if ( (*p) < 62 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st30;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 60 )
				goto st30;
		} else
			goto tr60;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr60;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto st30;
			} else if ( (*p) >= 97 )
				goto tr60;
		} else
			goto st30;
	} else
		goto st30;
	goto tr36;
tr60:
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st37;
st37:
	if ( ++p == pe )
		goto _test_eof37;
case 37:
#line 1195 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr51;
		case 61: goto st24;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st30;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st30;
		} else
			goto st37;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st30;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st30;
		} else
			goto st37;
	} else
		goto st37;
	goto tr36;
st38:
	if ( ++p == pe )
		goto _test_eof38;
case 38:
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st30;
	} else if ( (*p) >= 32 )
		goto st30;
	goto tr50;
tr27:
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st39;
st39:
	if ( ++p == pe )
		goto _test_eof39;
case 39:
#line 1241 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr51;
		case 61: goto st38;
		case 76: goto st41;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st30;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st30;
		} else
			goto st40;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st30;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st30;
		} else
			goto st40;
	} else
		goto st40;
	goto tr62;
tr28:
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st40;
st40:
	if ( ++p == pe )
		goto _test_eof40;
case 40:
#line 1278 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr51;
		case 61: goto st38;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st30;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st30;
		} else
			goto st40;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st30;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st30;
		} else
			goto st40;
	} else
		goto st40;
	goto tr50;
st41:
	if ( ++p == pe )
		goto _test_eof41;
case 41:
	switch( (*p) ) {
		case 10: goto tr51;
		case 61: goto st38;
		case 84: goto st42;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st30;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st30;
		} else
			goto st40;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st30;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st30;
		} else
			goto st40;
	} else
		goto st40;
	goto tr62;
st42:
	if ( ++p == pe )
		goto _test_eof42;
case 42:
	switch( (*p) ) {
		case 10: goto tr51;
		case 61: goto st43;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st30;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st30;
		} else
			goto st40;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st30;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st30;
		} else
			goto st40;
	} else
		goto st40;
	goto tr62;
st43:
	if ( ++p == pe )
		goto _test_eof43;
case 43:
	if ( (*p) == 60 )
		goto st44;
	if ( (*p) > 59 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st30;
	} else if ( (*p) >= 32 )
		goto st30;
	goto tr62;
st44:
	if ( ++p == pe )
		goto _test_eof44;
case 44:
	switch( (*p) ) {
		case 10: goto tr51;
		case 73: goto st45;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st30;
	} else if ( (*p) >= 32 )
		goto st30;
	goto tr62;
st45:
	if ( ++p == pe )
		goto _test_eof45;
case 45:
	switch( (*p) ) {
		case 10: goto tr51;
		case 68: goto st46;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st30;
	} else if ( (*p) >= 32 )
		goto st30;
	goto tr62;
st46:
	if ( ++p == pe )
		goto _test_eof46;
case 46:
	switch( (*p) ) {
		case 10: goto tr51;
		case 61: goto st47;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto st30;
	goto tr62;
st47:
	if ( ++p == pe )
		goto _test_eof47;
case 47:
	switch( (*p) ) {
		case 67: goto st48;
		case 68: goto st69;
		case 73: goto st72;
	}
	goto tr62;
st48:
	if ( ++p == pe )
		goto _test_eof48;
case 48:
	if ( (*p) == 78 )
		goto st49;
	goto tr62;
st49:
	if ( ++p == pe )
		goto _test_eof49;
case 49:
	if ( (*p) == 86 )
		goto st50;
	goto tr62;
st50:
	if ( ++p == pe )
		goto _test_eof50;
case 50:
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st51;
	} else if ( (*p) >= 32 )
		goto st51;
	goto tr62;
st51:
	if ( ++p == pe )
		goto _test_eof51;
case 51:
	if ( (*p) == 44 )
		goto st52;
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st51;
	} else if ( (*p) >= 32 )
		goto st51;
	goto tr62;
st52:
	if ( ++p == pe )
		goto _test_eof52;
case 52:
	switch( (*p) ) {
		case 44: goto st52;
		case 68: goto st53;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st51;
	} else if ( (*p) >= 32 )
		goto st51;
	goto tr62;
st53:
	if ( ++p == pe )
		goto _test_eof53;
case 53:
	switch( (*p) ) {
		case 44: goto st52;
		case 101: goto st54;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st51;
	} else if ( (*p) >= 32 )
		goto st51;
	goto tr62;
st54:
	if ( ++p == pe )
		goto _test_eof54;
case 54:
	switch( (*p) ) {
		case 44: goto st52;
		case 115: goto st55;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st51;
	} else if ( (*p) >= 32 )
		goto st51;
	goto tr62;
st55:
	if ( ++p == pe )
		goto _test_eof55;
case 55:
	switch( (*p) ) {
		case 44: goto st52;
		case 99: goto st56;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st51;
	} else if ( (*p) >= 32 )
		goto st51;
	goto tr62;
st56:
	if ( ++p == pe )
		goto _test_eof56;
case 56:
	switch( (*p) ) {
		case 44: goto st52;
		case 114: goto st57;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st51;
	} else if ( (*p) >= 32 )
		goto st51;
	goto tr62;
st57:
	if ( ++p == pe )
		goto _test_eof57;
case 57:
	switch( (*p) ) {
		case 44: goto st52;
		case 105: goto st58;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st51;
	} else if ( (*p) >= 32 )
		goto st51;
	goto tr62;
st58:
	if ( ++p == pe )
		goto _test_eof58;
case 58:
	switch( (*p) ) {
		case 44: goto st52;
		case 112: goto st59;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st51;
	} else if ( (*p) >= 32 )
		goto st51;
	goto tr62;
st59:
	if ( ++p == pe )
		goto _test_eof59;
case 59:
	switch( (*p) ) {
		case 44: goto st52;
		case 116: goto st60;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st51;
	} else if ( (*p) >= 32 )
		goto st51;
	goto tr62;
st60:
	if ( ++p == pe )
		goto _test_eof60;
case 60:
	switch( (*p) ) {
		case 44: goto st52;
		case 105: goto st61;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st51;
	} else if ( (*p) >= 32 )
		goto st51;
	goto tr62;
st61:
	if ( ++p == pe )
		goto _test_eof61;
case 61:
	switch( (*p) ) {
		case 44: goto st52;
		case 111: goto st62;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st51;
	} else if ( (*p) >= 32 )
		goto st51;
	goto tr62;
st62:
	if ( ++p == pe )
		goto _test_eof62;
case 62:
	switch( (*p) ) {
		case 44: goto st52;
		case 110: goto st63;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st51;
	} else if ( (*p) >= 32 )
		goto st51;
	goto tr62;
st63:
	if ( ++p == pe )
		goto _test_eof63;
case 63:
	switch( (*p) ) {
		case 44: goto st52;
		case 61: goto st64;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto st51;
	goto tr62;
st64:
	if ( ++p == pe )
		goto _test_eof64;
case 64:
	if ( (*p) == 34 )
		goto st65;
	goto tr62;
st65:
	if ( ++p == pe )
		goto _test_eof65;
case 65:
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st66;
	} else if ( (*p) >= 32 )
		goto st66;
	goto tr62;
st66:
	if ( ++p == pe )
		goto _test_eof66;
case 66:
	if ( (*p) == 34 )
		goto st67;
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st66;
	} else if ( (*p) >= 32 )
		goto st66;
	goto tr62;
st67:
	if ( ++p == pe )
		goto _test_eof67;
case 67:
	switch( (*p) ) {
		case 34: goto st67;
		case 62: goto st68;
	}
	if ( (*p) > 60 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto st66;
	} else if ( (*p) >= 32 )
		goto st66;
	goto tr62;
st68:
	if ( ++p == pe )
		goto _test_eof68;
case 68:
	switch( (*p) ) {
		case 10: goto tr94;
		case 34: goto st67;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st66;
	} else if ( (*p) >= 32 )
		goto st66;
	goto tr62;
st69:
	if ( ++p == pe )
		goto _test_eof69;
case 69:
	switch( (*p) ) {
		case 69: goto st70;
		case 85: goto st71;
	}
	goto tr62;
st70:
	if ( ++p == pe )
		goto _test_eof70;
case 70:
	if ( (*p) == 76 )
		goto st50;
	goto tr62;
st71:
	if ( ++p == pe )
		goto _test_eof71;
case 71:
	if ( (*p) == 80 )
		goto st50;
	goto tr62;
st72:
	if ( ++p == pe )
		goto _test_eof72;
case 72:
	if ( (*p) == 78 )
		goto st73;
	goto tr62;
st73:
	if ( ++p == pe )
		goto _test_eof73;
case 73:
	switch( (*p) ) {
		case 83: goto st50;
		case 86: goto st50;
	}
	goto tr62;
tr29:
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st74;
st74:
	if ( ++p == pe )
		goto _test_eof74;
case 74:
#line 1731 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr51;
		case 61: goto st38;
		case 73: goto st75;
		case 79: goto st103;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st30;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st30;
		} else
			goto st40;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st30;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st30;
		} else
			goto st40;
	} else
		goto st40;
	goto tr98;
st75:
	if ( ++p == pe )
		goto _test_eof75;
case 75:
	switch( (*p) ) {
		case 10: goto tr51;
		case 61: goto st38;
		case 76: goto st76;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st30;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st30;
		} else
			goto st40;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st30;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st30;
		} else
			goto st40;
	} else
		goto st40;
	goto tr101;
st76:
	if ( ++p == pe )
		goto _test_eof76;
case 76:
	switch( (*p) ) {
		case 10: goto tr51;
		case 61: goto st38;
		case 84: goto st77;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st30;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st30;
		} else
			goto st40;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st30;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st30;
		} else
			goto st40;
	} else
		goto st40;
	goto tr101;
st77:
	if ( ++p == pe )
		goto _test_eof77;
case 77:
	switch( (*p) ) {
		case 10: goto tr51;
		case 61: goto st38;
		case 69: goto st78;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st30;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st30;
		} else
			goto st40;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st30;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st30;
		} else
			goto st40;
	} else
		goto st40;
	goto tr101;
st78:
	if ( ++p == pe )
		goto _test_eof78;
case 78:
	switch( (*p) ) {
		case 10: goto tr51;
		case 61: goto st38;
		case 82: goto st79;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st30;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st30;
		} else
			goto st40;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st30;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st30;
		} else
			goto st40;
	} else
		goto st40;
	goto tr101;
st79:
	if ( ++p == pe )
		goto _test_eof79;
case 79:
	switch( (*p) ) {
		case 10: goto tr51;
		case 61: goto st80;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st30;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st30;
		} else
			goto st40;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st30;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st30;
		} else
			goto st40;
	} else
		goto st40;
	goto tr101;
st80:
	if ( ++p == pe )
		goto _test_eof80;
case 80:
	if ( (*p) == 60 )
		goto st81;
	if ( (*p) > 59 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st30;
	} else if ( (*p) >= 32 )
		goto st30;
	goto tr101;
st81:
	if ( ++p == pe )
		goto _test_eof81;
case 81:
	switch( (*p) ) {
		case 10: goto tr51;
		case 73: goto st82;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st30;
	} else if ( (*p) >= 32 )
		goto st30;
	goto tr101;
st82:
	if ( ++p == pe )
		goto _test_eof82;
case 82:
	switch( (*p) ) {
		case 10: goto tr51;
		case 68: goto st83;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st30;
	} else if ( (*p) >= 32 )
		goto st30;
	goto tr101;
st83:
	if ( ++p == pe )
		goto _test_eof83;
case 83:
	switch( (*p) ) {
		case 10: goto tr51;
		case 61: goto st84;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto st30;
	goto tr101;
st84:
	if ( ++p == pe )
		goto _test_eof84;
case 84:
	switch( (*p) ) {
		case 46: goto st85;
		case 95: goto st85;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st85;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st85;
	} else
		goto st85;
	goto tr101;
st85:
	if ( ++p == pe )
		goto _test_eof85;
case 85:
	switch( (*p) ) {
		case 44: goto st86;
		case 46: goto st85;
		case 95: goto st85;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st85;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st85;
	} else
		goto st85;
	goto tr101;
st86:
	if ( ++p == pe )
		goto _test_eof86;
case 86:
	if ( (*p) == 68 )
		goto st87;
	goto tr101;
st87:
	if ( ++p == pe )
		goto _test_eof87;
case 87:
	if ( (*p) == 101 )
		goto st88;
	goto tr101;
st88:
	if ( ++p == pe )
		goto _test_eof88;
case 88:
	if ( (*p) == 115 )
		goto st89;
	goto tr101;
st89:
	if ( ++p == pe )
		goto _test_eof89;
case 89:
	if ( (*p) == 99 )
		goto st90;
	goto tr101;
st90:
	if ( ++p == pe )
		goto _test_eof90;
case 90:
	if ( (*p) == 114 )
		goto st91;
	goto tr101;
st91:
	if ( ++p == pe )
		goto _test_eof91;
case 91:
	if ( (*p) == 105 )
		goto st92;
	goto tr101;
st92:
	if ( ++p == pe )
		goto _test_eof92;
case 92:
	if ( (*p) == 112 )
		goto st93;
	goto tr101;
st93:
	if ( ++p == pe )
		goto _test_eof93;
case 93:
	if ( (*p) == 116 )
		goto st94;
	goto tr101;
st94:
	if ( ++p == pe )
		goto _test_eof94;
case 94:
	if ( (*p) == 105 )
		goto st95;
	goto tr101;
st95:
	if ( ++p == pe )
		goto _test_eof95;
case 95:
	if ( (*p) == 111 )
		goto st96;
	goto tr101;
st96:
	if ( ++p == pe )
		goto _test_eof96;
case 96:
	if ( (*p) == 110 )
		goto st97;
	goto tr101;
st97:
	if ( ++p == pe )
		goto _test_eof97;
case 97:
	if ( (*p) == 61 )
		goto st98;
	goto tr101;
st98:
	if ( ++p == pe )
		goto _test_eof98;
case 98:
	if ( (*p) == 34 )
		goto st99;
	goto tr101;
st99:
	if ( ++p == pe )
		goto _test_eof99;
case 99:
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st100;
	} else if ( (*p) >= 32 )
		goto st100;
	goto tr101;
st100:
	if ( ++p == pe )
		goto _test_eof100;
case 100:
	if ( (*p) == 34 )
		goto st101;
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st100;
	} else if ( (*p) >= 32 )
		goto st100;
	goto tr101;
st101:
	if ( ++p == pe )
		goto _test_eof101;
case 101:
	switch( (*p) ) {
		case 34: goto st101;
		case 62: goto st102;
	}
	if ( (*p) > 60 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto st100;
	} else if ( (*p) >= 32 )
		goto st100;
	goto tr101;
st102:
	if ( ++p == pe )
		goto _test_eof102;
case 102:
	switch( (*p) ) {
		case 10: goto tr129;
		case 34: goto st101;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st100;
	} else if ( (*p) >= 32 )
		goto st100;
	goto tr101;
st103:
	if ( ++p == pe )
		goto _test_eof103;
case 103:
	switch( (*p) ) {
		case 10: goto tr51;
		case 61: goto st38;
		case 82: goto st104;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st30;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st30;
		} else
			goto st40;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st30;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st30;
		} else
			goto st40;
	} else
		goto st40;
	goto tr130;
st104:
	if ( ++p == pe )
		goto _test_eof104;
case 104:
	switch( (*p) ) {
		case 10: goto tr51;
		case 61: goto st38;
		case 77: goto st105;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st30;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st30;
		} else
			goto st40;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st30;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st30;
		} else
			goto st40;
	} else
		goto st40;
	goto tr130;
st105:
	if ( ++p == pe )
		goto _test_eof105;
case 105:
	switch( (*p) ) {
		case 10: goto tr51;
		case 61: goto st38;
		case 65: goto st106;
	}
	if ( (*p) < 66 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st30;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st30;
		} else
			goto st40;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st30;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st30;
		} else
			goto st40;
	} else
		goto st40;
	goto tr130;
st106:
	if ( ++p == pe )
		goto _test_eof106;
case 106:
	switch( (*p) ) {
		case 10: goto tr51;
		case 61: goto st38;
		case 84: goto st107;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st30;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st30;
		} else
			goto st40;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st30;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st30;
		} else
			goto st40;
	} else
		goto st40;
	goto tr130;
st107:
	if ( ++p == pe )
		goto _test_eof107;
case 107:
	switch( (*p) ) {
		case 10: goto tr51;
		case 61: goto st108;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st30;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st30;
		} else
			goto st40;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st30;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st30;
		} else
			goto st40;
	} else
		goto st40;
	goto tr130;
st108:
	if ( ++p == pe )
		goto _test_eof108;
case 108:
	if ( (*p) == 60 )
		goto st109;
	if ( (*p) > 59 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st30;
	} else if ( (*p) >= 32 )
		goto st30;
	goto tr130;
st109:
	if ( ++p == pe )
		goto _test_eof109;
case 109:
	switch( (*p) ) {
		case 10: goto tr51;
		case 73: goto st110;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st30;
	} else if ( (*p) >= 32 )
		goto st30;
	goto tr130;
st110:
	if ( ++p == pe )
		goto _test_eof110;
case 110:
	switch( (*p) ) {
		case 10: goto tr51;
		case 68: goto st111;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st30;
	} else if ( (*p) >= 32 )
		goto st30;
	goto tr130;
st111:
	if ( ++p == pe )
		goto _test_eof111;
case 111:
	switch( (*p) ) {
		case 10: goto tr51;
		case 61: goto st112;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto st30;
	goto tr130;
st112:
	if ( ++p == pe )
		goto _test_eof112;
case 112:
	switch( (*p) ) {
		case 46: goto st113;
		case 95: goto st113;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st113;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st113;
	} else
		goto st113;
	goto tr130;
st113:
	if ( ++p == pe )
		goto _test_eof113;
case 113:
	switch( (*p) ) {
		case 44: goto st114;
		case 46: goto st113;
		case 95: goto st113;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st113;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st113;
	} else
		goto st113;
	goto tr130;
st114:
	if ( ++p == pe )
		goto _test_eof114;
case 114:
	if ( (*p) == 78 )
		goto st115;
	goto tr130;
st115:
	if ( ++p == pe )
		goto _test_eof115;
case 115:
	if ( (*p) == 117 )
		goto st116;
	goto tr130;
st116:
	if ( ++p == pe )
		goto _test_eof116;
case 116:
	if ( (*p) == 109 )
		goto st117;
	goto tr130;
st117:
	if ( ++p == pe )
		goto _test_eof117;
case 117:
	if ( (*p) == 98 )
		goto st118;
	goto tr130;
st118:
	if ( ++p == pe )
		goto _test_eof118;
case 118:
	if ( (*p) == 101 )
		goto st119;
	goto tr130;
st119:
	if ( ++p == pe )
		goto _test_eof119;
case 119:
	if ( (*p) == 114 )
		goto st120;
	goto tr130;
st120:
	if ( ++p == pe )
		goto _test_eof120;
case 120:
	if ( (*p) == 61 )
		goto st121;
	goto tr130;
st121:
	if ( ++p == pe )
		goto _test_eof121;
case 121:
	switch( (*p) ) {
		case 46: goto st122;
		case 65: goto st122;
		case 71: goto st122;
		case 82: goto st122;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st168;
	goto tr130;
st122:
	if ( ++p == pe )
		goto _test_eof122;
case 122:
	if ( (*p) == 44 )
		goto st123;
	goto tr130;
st123:
	if ( ++p == pe )
		goto _test_eof123;
case 123:
	if ( (*p) == 84 )
		goto st124;
	goto tr130;
st124:
	if ( ++p == pe )
		goto _test_eof124;
case 124:
	if ( (*p) == 121 )
		goto st125;
	goto tr130;
st125:
	if ( ++p == pe )
		goto _test_eof125;
case 125:
	if ( (*p) == 112 )
		goto st126;
	goto tr130;
st126:
	if ( ++p == pe )
		goto _test_eof126;
case 126:
	if ( (*p) == 101 )
		goto st127;
	goto tr130;
st127:
	if ( ++p == pe )
		goto _test_eof127;
case 127:
	if ( (*p) == 61 )
		goto st128;
	goto tr130;
st128:
	if ( ++p == pe )
		goto _test_eof128;
case 128:
	switch( (*p) ) {
		case 67: goto st129;
		case 70: goto st155;
		case 73: goto st159;
		case 83: goto st163;
	}
	goto tr130;
st129:
	if ( ++p == pe )
		goto _test_eof129;
case 129:
	if ( (*p) == 104 )
		goto st130;
	goto tr130;
st130:
	if ( ++p == pe )
		goto _test_eof130;
case 130:
	if ( (*p) == 97 )
		goto st131;
	goto tr130;
st131:
	if ( ++p == pe )
		goto _test_eof131;
case 131:
	if ( (*p) == 114 )
		goto st132;
	goto tr130;
st132:
	if ( ++p == pe )
		goto _test_eof132;
case 132:
	if ( (*p) == 97 )
		goto st133;
	goto tr130;
st133:
	if ( ++p == pe )
		goto _test_eof133;
case 133:
	if ( (*p) == 99 )
		goto st134;
	goto tr130;
st134:
	if ( ++p == pe )
		goto _test_eof134;
case 134:
	if ( (*p) == 116 )
		goto st135;
	goto tr130;
st135:
	if ( ++p == pe )
		goto _test_eof135;
case 135:
	if ( (*p) == 101 )
		goto st136;
	goto tr130;
st136:
	if ( ++p == pe )
		goto _test_eof136;
case 136:
	if ( (*p) == 114 )
		goto st137;
	goto tr130;
st137:
	if ( ++p == pe )
		goto _test_eof137;
case 137:
	if ( (*p) == 44 )
		goto st138;
	goto tr130;
st138:
	if ( ++p == pe )
		goto _test_eof138;
case 138:
	if ( (*p) == 68 )
		goto st139;
	goto tr130;
st139:
	if ( ++p == pe )
		goto _test_eof139;
case 139:
	if ( (*p) == 101 )
		goto st140;
	goto tr130;
st140:
	if ( ++p == pe )
		goto _test_eof140;
case 140:
	if ( (*p) == 115 )
		goto st141;
	goto tr130;
st141:
	if ( ++p == pe )
		goto _test_eof141;
case 141:
	if ( (*p) == 99 )
		goto st142;
	goto tr130;
st142:
	if ( ++p == pe )
		goto _test_eof142;
case 142:
	if ( (*p) == 114 )
		goto st143;
	goto tr130;
st143:
	if ( ++p == pe )
		goto _test_eof143;
case 143:
	if ( (*p) == 105 )
		goto st144;
	goto tr130;
st144:
	if ( ++p == pe )
		goto _test_eof144;
case 144:
	if ( (*p) == 112 )
		goto st145;
	goto tr130;
st145:
	if ( ++p == pe )
		goto _test_eof145;
case 145:
	if ( (*p) == 116 )
		goto st146;
	goto tr130;
st146:
	if ( ++p == pe )
		goto _test_eof146;
case 146:
	if ( (*p) == 105 )
		goto st147;
	goto tr130;
st147:
	if ( ++p == pe )
		goto _test_eof147;
case 147:
	if ( (*p) == 111 )
		goto st148;
	goto tr130;
st148:
	if ( ++p == pe )
		goto _test_eof148;
case 148:
	if ( (*p) == 110 )
		goto st149;
	goto tr130;
st149:
	if ( ++p == pe )
		goto _test_eof149;
case 149:
	if ( (*p) == 61 )
		goto st150;
	goto tr130;
st150:
	if ( ++p == pe )
		goto _test_eof150;
case 150:
	if ( (*p) == 34 )
		goto st151;
	goto tr130;
st151:
	if ( ++p == pe )
		goto _test_eof151;
case 151:
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st152;
	} else if ( (*p) >= 32 )
		goto st152;
	goto tr130;
st152:
	if ( ++p == pe )
		goto _test_eof152;
case 152:
	if ( (*p) == 34 )
		goto st153;
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st152;
	} else if ( (*p) >= 32 )
		goto st152;
	goto tr130;
st153:
	if ( ++p == pe )
		goto _test_eof153;
case 153:
	switch( (*p) ) {
		case 34: goto st153;
		case 62: goto st154;
	}
	if ( (*p) > 60 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto st152;
	} else if ( (*p) >= 32 )
		goto st152;
	goto tr130;
st154:
	if ( ++p == pe )
		goto _test_eof154;
case 154:
	switch( (*p) ) {
		case 10: goto tr186;
		case 34: goto st153;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st152;
	} else if ( (*p) >= 32 )
		goto st152;
	goto tr130;
st155:
	if ( ++p == pe )
		goto _test_eof155;
case 155:
	if ( (*p) == 108 )
		goto st156;
	goto tr130;
st156:
	if ( ++p == pe )
		goto _test_eof156;
case 156:
	if ( (*p) == 111 )
		goto st157;
	goto tr130;
st157:
	if ( ++p == pe )
		goto _test_eof157;
case 157:
	if ( (*p) == 97 )
		goto st158;
	goto tr130;
st158:
	if ( ++p == pe )
		goto _test_eof158;
case 158:
	if ( (*p) == 116 )
		goto st137;
	goto tr130;
st159:
	if ( ++p == pe )
		goto _test_eof159;
case 159:
	if ( (*p) == 110 )
		goto st160;
	goto tr130;
st160:
	if ( ++p == pe )
		goto _test_eof160;
case 160:
	if ( (*p) == 116 )
		goto st161;
	goto tr130;
st161:
	if ( ++p == pe )
		goto _test_eof161;
case 161:
	if ( (*p) == 101 )
		goto st162;
	goto tr130;
st162:
	if ( ++p == pe )
		goto _test_eof162;
case 162:
	if ( (*p) == 103 )
		goto st135;
	goto tr130;
st163:
	if ( ++p == pe )
		goto _test_eof163;
case 163:
	if ( (*p) == 116 )
		goto st164;
	goto tr130;
st164:
	if ( ++p == pe )
		goto _test_eof164;
case 164:
	if ( (*p) == 114 )
		goto st165;
	goto tr130;
st165:
	if ( ++p == pe )
		goto _test_eof165;
case 165:
	if ( (*p) == 105 )
		goto st166;
	goto tr130;
st166:
	if ( ++p == pe )
		goto _test_eof166;
case 166:
	if ( (*p) == 110 )
		goto st167;
	goto tr130;
st167:
	if ( ++p == pe )
		goto _test_eof167;
case 167:
	if ( (*p) == 103 )
		goto st137;
	goto tr130;
st168:
	if ( ++p == pe )
		goto _test_eof168;
case 168:
	if ( (*p) == 44 )
		goto st123;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st168;
	goto tr130;
tr30:
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st169;
st169:
	if ( ++p == pe )
		goto _test_eof169;
case 169:
#line 2799 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr51;
		case 61: goto st38;
		case 78: goto st170;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st30;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st30;
		} else
			goto st40;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st30;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st30;
		} else
			goto st40;
	} else
		goto st40;
	goto tr197;
st170:
	if ( ++p == pe )
		goto _test_eof170;
case 170:
	switch( (*p) ) {
		case 10: goto tr51;
		case 61: goto st38;
		case 70: goto st171;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st30;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st30;
		} else
			goto st40;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st30;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st30;
		} else
			goto st40;
	} else
		goto st40;
	goto tr197;
st171:
	if ( ++p == pe )
		goto _test_eof171;
case 171:
	switch( (*p) ) {
		case 10: goto tr51;
		case 61: goto st38;
		case 79: goto st172;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st30;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st30;
		} else
			goto st40;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st30;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st30;
		} else
			goto st40;
	} else
		goto st40;
	goto tr197;
st172:
	if ( ++p == pe )
		goto _test_eof172;
case 172:
	switch( (*p) ) {
		case 10: goto tr51;
		case 61: goto st173;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st30;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st30;
		} else
			goto st40;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st30;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st30;
		} else
			goto st40;
	} else
		goto st40;
	goto tr197;
st173:
	if ( ++p == pe )
		goto _test_eof173;
case 173:
	if ( (*p) == 60 )
		goto st174;
	if ( (*p) > 59 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st30;
	} else if ( (*p) >= 32 )
		goto st30;
	goto tr197;
st174:
	if ( ++p == pe )
		goto _test_eof174;
case 174:
	switch( (*p) ) {
		case 10: goto tr51;
		case 73: goto st175;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st30;
	} else if ( (*p) >= 32 )
		goto st30;
	goto tr197;
st175:
	if ( ++p == pe )
		goto _test_eof175;
case 175:
	switch( (*p) ) {
		case 10: goto tr51;
		case 68: goto st176;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st30;
	} else if ( (*p) >= 32 )
		goto st30;
	goto tr197;
st176:
	if ( ++p == pe )
		goto _test_eof176;
case 176:
	switch( (*p) ) {
		case 10: goto tr51;
		case 61: goto st177;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto st30;
	goto tr197;
st177:
	if ( ++p == pe )
		goto _test_eof177;
case 177:
	switch( (*p) ) {
		case 46: goto st178;
		case 95: goto st178;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st178;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st178;
	} else
		goto st178;
	goto tr197;
st178:
	if ( ++p == pe )
		goto _test_eof178;
case 178:
	switch( (*p) ) {
		case 44: goto st179;
		case 46: goto st178;
		case 95: goto st178;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st178;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st178;
	} else
		goto st178;
	goto tr197;
st179:
	if ( ++p == pe )
		goto _test_eof179;
case 179:
	if ( (*p) == 78 )
		goto st180;
	goto tr197;
st180:
	if ( ++p == pe )
		goto _test_eof180;
case 180:
	if ( (*p) == 117 )
		goto st181;
	goto tr197;
st181:
	if ( ++p == pe )
		goto _test_eof181;
case 181:
	if ( (*p) == 109 )
		goto st182;
	goto tr197;
st182:
	if ( ++p == pe )
		goto _test_eof182;
case 182:
	if ( (*p) == 98 )
		goto st183;
	goto tr197;
st183:
	if ( ++p == pe )
		goto _test_eof183;
case 183:
	if ( (*p) == 101 )
		goto st184;
	goto tr197;
st184:
	if ( ++p == pe )
		goto _test_eof184;
case 184:
	if ( (*p) == 114 )
		goto st185;
	goto tr197;
st185:
	if ( ++p == pe )
		goto _test_eof185;
case 185:
	if ( (*p) == 61 )
		goto st186;
	goto tr197;
st186:
	if ( ++p == pe )
		goto _test_eof186;
case 186:
	switch( (*p) ) {
		case 46: goto st187;
		case 65: goto st187;
		case 71: goto st187;
		case 82: goto st187;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st265;
	goto tr197;
st187:
	if ( ++p == pe )
		goto _test_eof187;
case 187:
	if ( (*p) == 44 )
		goto st188;
	goto tr197;
st188:
	if ( ++p == pe )
		goto _test_eof188;
case 188:
	if ( (*p) == 84 )
		goto st189;
	goto tr197;
st189:
	if ( ++p == pe )
		goto _test_eof189;
case 189:
	if ( (*p) == 121 )
		goto st190;
	goto tr197;
st190:
	if ( ++p == pe )
		goto _test_eof190;
case 190:
	if ( (*p) == 112 )
		goto st191;
	goto tr197;
st191:
	if ( ++p == pe )
		goto _test_eof191;
case 191:
	if ( (*p) == 101 )
		goto st192;
	goto tr197;
st192:
	if ( ++p == pe )
		goto _test_eof192;
case 192:
	if ( (*p) == 61 )
		goto st193;
	goto tr197;
st193:
	if ( ++p == pe )
		goto _test_eof193;
case 193:
	switch( (*p) ) {
		case 67: goto st194;
		case 70: goto st252;
		case 73: goto st257;
		case 83: goto st261;
	}
	goto tr197;
st194:
	if ( ++p == pe )
		goto _test_eof194;
case 194:
	if ( (*p) == 104 )
		goto st195;
	goto tr197;
st195:
	if ( ++p == pe )
		goto _test_eof195;
case 195:
	if ( (*p) == 97 )
		goto st196;
	goto tr197;
st196:
	if ( ++p == pe )
		goto _test_eof196;
case 196:
	if ( (*p) == 114 )
		goto st197;
	goto tr197;
st197:
	if ( ++p == pe )
		goto _test_eof197;
case 197:
	if ( (*p) == 97 )
		goto st198;
	goto tr197;
st198:
	if ( ++p == pe )
		goto _test_eof198;
case 198:
	if ( (*p) == 99 )
		goto st199;
	goto tr197;
st199:
	if ( ++p == pe )
		goto _test_eof199;
case 199:
	if ( (*p) == 116 )
		goto st200;
	goto tr197;
st200:
	if ( ++p == pe )
		goto _test_eof200;
case 200:
	if ( (*p) == 101 )
		goto st201;
	goto tr197;
st201:
	if ( ++p == pe )
		goto _test_eof201;
case 201:
	if ( (*p) == 114 )
		goto st202;
	goto tr197;
st202:
	if ( ++p == pe )
		goto _test_eof202;
case 202:
	if ( (*p) == 44 )
		goto st203;
	goto tr197;
st203:
	if ( ++p == pe )
		goto _test_eof203;
case 203:
	if ( (*p) == 68 )
		goto st204;
	goto tr197;
st204:
	if ( ++p == pe )
		goto _test_eof204;
case 204:
	if ( (*p) == 101 )
		goto st205;
	goto tr197;
st205:
	if ( ++p == pe )
		goto _test_eof205;
case 205:
	if ( (*p) == 115 )
		goto st206;
	goto tr197;
st206:
	if ( ++p == pe )
		goto _test_eof206;
case 206:
	if ( (*p) == 99 )
		goto st207;
	goto tr197;
st207:
	if ( ++p == pe )
		goto _test_eof207;
case 207:
	if ( (*p) == 114 )
		goto st208;
	goto tr197;
st208:
	if ( ++p == pe )
		goto _test_eof208;
case 208:
	if ( (*p) == 105 )
		goto st209;
	goto tr197;
st209:
	if ( ++p == pe )
		goto _test_eof209;
case 209:
	if ( (*p) == 112 )
		goto st210;
	goto tr197;
st210:
	if ( ++p == pe )
		goto _test_eof210;
case 210:
	if ( (*p) == 116 )
		goto st211;
	goto tr197;
st211:
	if ( ++p == pe )
		goto _test_eof211;
case 211:
	if ( (*p) == 105 )
		goto st212;
	goto tr197;
st212:
	if ( ++p == pe )
		goto _test_eof212;
case 212:
	if ( (*p) == 111 )
		goto st213;
	goto tr197;
st213:
	if ( ++p == pe )
		goto _test_eof213;
case 213:
	if ( (*p) == 110 )
		goto st214;
	goto tr197;
st214:
	if ( ++p == pe )
		goto _test_eof214;
case 214:
	if ( (*p) == 61 )
		goto st215;
	goto tr197;
st215:
	if ( ++p == pe )
		goto _test_eof215;
case 215:
	if ( (*p) == 34 )
		goto st216;
	goto tr197;
st216:
	if ( ++p == pe )
		goto _test_eof216;
case 216:
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st217;
	} else if ( (*p) >= 32 )
		goto st217;
	goto tr197;
st217:
	if ( ++p == pe )
		goto _test_eof217;
case 217:
	if ( (*p) == 34 )
		goto st218;
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st217;
	} else if ( (*p) >= 32 )
		goto st217;
	goto tr197;
st218:
	if ( ++p == pe )
		goto _test_eof218;
case 218:
	switch( (*p) ) {
		case 34: goto st218;
		case 44: goto st219;
		case 62: goto st251;
	}
	if ( (*p) > 60 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto st217;
	} else if ( (*p) >= 32 )
		goto st217;
	goto tr197;
st219:
	if ( ++p == pe )
		goto _test_eof219;
case 219:
	switch( (*p) ) {
		case 34: goto st218;
		case 83: goto st220;
		case 86: goto st244;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st217;
	} else if ( (*p) >= 32 )
		goto st217;
	goto tr197;
st220:
	if ( ++p == pe )
		goto _test_eof220;
case 220:
	switch( (*p) ) {
		case 34: goto st218;
		case 111: goto st221;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st217;
	} else if ( (*p) >= 32 )
		goto st217;
	goto tr197;
st221:
	if ( ++p == pe )
		goto _test_eof221;
case 221:
	switch( (*p) ) {
		case 34: goto st218;
		case 117: goto st222;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st217;
	} else if ( (*p) >= 32 )
		goto st217;
	goto tr197;
st222:
	if ( ++p == pe )
		goto _test_eof222;
case 222:
	switch( (*p) ) {
		case 34: goto st218;
		case 114: goto st223;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st217;
	} else if ( (*p) >= 32 )
		goto st217;
	goto tr197;
st223:
	if ( ++p == pe )
		goto _test_eof223;
case 223:
	switch( (*p) ) {
		case 34: goto st218;
		case 99: goto st224;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st217;
	} else if ( (*p) >= 32 )
		goto st217;
	goto tr197;
st224:
	if ( ++p == pe )
		goto _test_eof224;
case 224:
	switch( (*p) ) {
		case 34: goto st218;
		case 101: goto st225;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st217;
	} else if ( (*p) >= 32 )
		goto st217;
	goto tr197;
st225:
	if ( ++p == pe )
		goto _test_eof225;
case 225:
	switch( (*p) ) {
		case 34: goto st218;
		case 61: goto st226;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto st217;
	goto tr197;
st226:
	if ( ++p == pe )
		goto _test_eof226;
case 226:
	if ( (*p) == 34 )
		goto st227;
	goto tr197;
st227:
	if ( ++p == pe )
		goto _test_eof227;
case 227:
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st228;
	} else if ( (*p) >= 32 )
		goto st228;
	goto tr197;
st228:
	if ( ++p == pe )
		goto _test_eof228;
case 228:
	if ( (*p) == 34 )
		goto st229;
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st228;
	} else if ( (*p) >= 32 )
		goto st228;
	goto tr197;
st229:
	if ( ++p == pe )
		goto _test_eof229;
case 229:
	switch( (*p) ) {
		case 34: goto st229;
		case 44: goto st230;
		case 62: goto st243;
	}
	if ( (*p) > 60 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto st228;
	} else if ( (*p) >= 32 )
		goto st228;
	goto tr197;
st230:
	if ( ++p == pe )
		goto _test_eof230;
case 230:
	switch( (*p) ) {
		case 34: goto st229;
		case 86: goto st231;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st228;
	} else if ( (*p) >= 32 )
		goto st228;
	goto tr197;
st231:
	if ( ++p == pe )
		goto _test_eof231;
case 231:
	switch( (*p) ) {
		case 34: goto st229;
		case 101: goto st232;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st228;
	} else if ( (*p) >= 32 )
		goto st228;
	goto tr197;
st232:
	if ( ++p == pe )
		goto _test_eof232;
case 232:
	switch( (*p) ) {
		case 34: goto st229;
		case 114: goto st233;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st228;
	} else if ( (*p) >= 32 )
		goto st228;
	goto tr197;
st233:
	if ( ++p == pe )
		goto _test_eof233;
case 233:
	switch( (*p) ) {
		case 34: goto st229;
		case 115: goto st234;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st228;
	} else if ( (*p) >= 32 )
		goto st228;
	goto tr197;
st234:
	if ( ++p == pe )
		goto _test_eof234;
case 234:
	switch( (*p) ) {
		case 34: goto st229;
		case 105: goto st235;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st228;
	} else if ( (*p) >= 32 )
		goto st228;
	goto tr197;
st235:
	if ( ++p == pe )
		goto _test_eof235;
case 235:
	switch( (*p) ) {
		case 34: goto st229;
		case 111: goto st236;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st228;
	} else if ( (*p) >= 32 )
		goto st228;
	goto tr197;
st236:
	if ( ++p == pe )
		goto _test_eof236;
case 236:
	switch( (*p) ) {
		case 34: goto st229;
		case 110: goto st237;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st228;
	} else if ( (*p) >= 32 )
		goto st228;
	goto tr197;
st237:
	if ( ++p == pe )
		goto _test_eof237;
case 237:
	switch( (*p) ) {
		case 34: goto st229;
		case 61: goto st238;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto st228;
	goto tr197;
st238:
	if ( ++p == pe )
		goto _test_eof238;
case 238:
	if ( (*p) == 34 )
		goto st239;
	goto tr197;
st239:
	if ( ++p == pe )
		goto _test_eof239;
case 239:
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st240;
	} else if ( (*p) >= 32 )
		goto st240;
	goto tr197;
st240:
	if ( ++p == pe )
		goto _test_eof240;
case 240:
	if ( (*p) == 34 )
		goto st241;
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st240;
	} else if ( (*p) >= 32 )
		goto st240;
	goto tr197;
st241:
	if ( ++p == pe )
		goto _test_eof241;
case 241:
	switch( (*p) ) {
		case 34: goto st241;
		case 62: goto st242;
	}
	if ( (*p) > 60 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto st240;
	} else if ( (*p) >= 32 )
		goto st240;
	goto tr197;
st242:
	if ( ++p == pe )
		goto _test_eof242;
case 242:
	switch( (*p) ) {
		case 10: goto tr278;
		case 34: goto st241;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st240;
	} else if ( (*p) >= 32 )
		goto st240;
	goto tr197;
st243:
	if ( ++p == pe )
		goto _test_eof243;
case 243:
	switch( (*p) ) {
		case 10: goto tr278;
		case 34: goto st229;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st228;
	} else if ( (*p) >= 32 )
		goto st228;
	goto tr197;
st244:
	if ( ++p == pe )
		goto _test_eof244;
case 244:
	switch( (*p) ) {
		case 34: goto st218;
		case 101: goto st245;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st217;
	} else if ( (*p) >= 32 )
		goto st217;
	goto tr197;
st245:
	if ( ++p == pe )
		goto _test_eof245;
case 245:
	switch( (*p) ) {
		case 34: goto st218;
		case 114: goto st246;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st217;
	} else if ( (*p) >= 32 )
		goto st217;
	goto tr197;
st246:
	if ( ++p == pe )
		goto _test_eof246;
case 246:
	switch( (*p) ) {
		case 34: goto st218;
		case 115: goto st247;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st217;
	} else if ( (*p) >= 32 )
		goto st217;
	goto tr197;
st247:
	if ( ++p == pe )
		goto _test_eof247;
case 247:
	switch( (*p) ) {
		case 34: goto st218;
		case 105: goto st248;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st217;
	} else if ( (*p) >= 32 )
		goto st217;
	goto tr197;
st248:
	if ( ++p == pe )
		goto _test_eof248;
case 248:
	switch( (*p) ) {
		case 34: goto st218;
		case 111: goto st249;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st217;
	} else if ( (*p) >= 32 )
		goto st217;
	goto tr197;
st249:
	if ( ++p == pe )
		goto _test_eof249;
case 249:
	switch( (*p) ) {
		case 34: goto st218;
		case 110: goto st250;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st217;
	} else if ( (*p) >= 32 )
		goto st217;
	goto tr197;
st250:
	if ( ++p == pe )
		goto _test_eof250;
case 250:
	switch( (*p) ) {
		case 34: goto st218;
		case 61: goto st238;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto st217;
	goto tr197;
st251:
	if ( ++p == pe )
		goto _test_eof251;
case 251:
	switch( (*p) ) {
		case 10: goto tr278;
		case 34: goto st218;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st217;
	} else if ( (*p) >= 32 )
		goto st217;
	goto tr197;
st252:
	if ( ++p == pe )
		goto _test_eof252;
case 252:
	if ( (*p) == 108 )
		goto st253;
	goto tr197;
st253:
	if ( ++p == pe )
		goto _test_eof253;
case 253:
	switch( (*p) ) {
		case 97: goto st254;
		case 111: goto st255;
	}
	goto tr197;
st254:
	if ( ++p == pe )
		goto _test_eof254;
case 254:
	if ( (*p) == 103 )
		goto st202;
	goto tr197;
st255:
	if ( ++p == pe )
		goto _test_eof255;
case 255:
	if ( (*p) == 97 )
		goto st256;
	goto tr197;
st256:
	if ( ++p == pe )
		goto _test_eof256;
case 256:
	if ( (*p) == 116 )
		goto st202;
	goto tr197;
st257:
	if ( ++p == pe )
		goto _test_eof257;
case 257:
	if ( (*p) == 110 )
		goto st258;
	goto tr197;
st258:
	if ( ++p == pe )
		goto _test_eof258;
case 258:
	if ( (*p) == 116 )
		goto st259;
	goto tr197;
st259:
	if ( ++p == pe )
		goto _test_eof259;
case 259:
	if ( (*p) == 101 )
		goto st260;
	goto tr197;
st260:
	if ( ++p == pe )
		goto _test_eof260;
case 260:
	if ( (*p) == 103 )
		goto st200;
	goto tr197;
st261:
	if ( ++p == pe )
		goto _test_eof261;
case 261:
	if ( (*p) == 116 )
		goto st262;
	goto tr197;
st262:
	if ( ++p == pe )
		goto _test_eof262;
case 262:
	if ( (*p) == 114 )
		goto st263;
	goto tr197;
st263:
	if ( ++p == pe )
		goto _test_eof263;
case 263:
	if ( (*p) == 105 )
		goto st264;
	goto tr197;
st264:
	if ( ++p == pe )
		goto _test_eof264;
case 264:
	if ( (*p) == 110 )
		goto st254;
	goto tr197;
st265:
	if ( ++p == pe )
		goto _test_eof265;
case 265:
	if ( (*p) == 44 )
		goto st188;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st265;
	goto tr197;
tr31:
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st266;
st266:
	if ( ++p == pe )
		goto _test_eof266;
case 266:
#line 3848 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr51;
		case 61: goto st38;
		case 69: goto st267;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st30;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st30;
		} else
			goto st40;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st30;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st30;
		} else
			goto st40;
	} else
		goto st40;
	goto tr50;
st267:
	if ( ++p == pe )
		goto _test_eof267;
case 267:
	switch( (*p) ) {
		case 10: goto tr51;
		case 61: goto st38;
		case 68: goto st268;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st30;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st30;
		} else
			goto st40;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st30;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st30;
		} else
			goto st40;
	} else
		goto st40;
	goto tr50;
st268:
	if ( ++p == pe )
		goto _test_eof268;
case 268:
	switch( (*p) ) {
		case 10: goto tr51;
		case 61: goto st38;
		case 73: goto st269;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st30;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st30;
		} else
			goto st40;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st30;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st30;
		} else
			goto st40;
	} else
		goto st40;
	goto tr50;
st269:
	if ( ++p == pe )
		goto _test_eof269;
case 269:
	switch( (*p) ) {
		case 10: goto tr51;
		case 61: goto st38;
		case 71: goto st270;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st30;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st30;
		} else
			goto st40;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st30;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st30;
		} else
			goto st40;
	} else
		goto st40;
	goto tr50;
st270:
	if ( ++p == pe )
		goto _test_eof270;
case 270:
	switch( (*p) ) {
		case 10: goto tr51;
		case 61: goto st38;
		case 82: goto st271;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st30;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st30;
		} else
			goto st40;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st30;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st30;
		} else
			goto st40;
	} else
		goto st40;
	goto tr50;
st271:
	if ( ++p == pe )
		goto _test_eof271;
case 271:
	switch( (*p) ) {
		case 10: goto tr51;
		case 61: goto st38;
		case 69: goto st272;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st30;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st30;
		} else
			goto st40;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st30;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st30;
		} else
			goto st40;
	} else
		goto st40;
	goto tr50;
st272:
	if ( ++p == pe )
		goto _test_eof272;
case 272:
	switch( (*p) ) {
		case 10: goto tr51;
		case 61: goto st38;
		case 69: goto st273;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st30;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st30;
		} else
			goto st40;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st30;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st30;
		} else
			goto st40;
	} else
		goto st40;
	goto tr50;
st273:
	if ( ++p == pe )
		goto _test_eof273;
case 273:
	switch( (*p) ) {
		case 10: goto tr51;
		case 61: goto st274;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st30;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st30;
		} else
			goto st40;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st30;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st30;
		} else
			goto st40;
	} else
		goto st40;
	goto tr50;
st274:
	if ( ++p == pe )
		goto _test_eof274;
case 274:
	if ( (*p) == 60 )
		goto st275;
	if ( (*p) > 59 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st30;
	} else if ( (*p) >= 32 )
		goto st30;
	goto tr50;
st275:
	if ( ++p == pe )
		goto _test_eof275;
case 275:
	switch( (*p) ) {
		case 10: goto tr51;
		case 46: goto st276;
		case 95: goto st276;
	}
	if ( (*p) < 62 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st30;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 60 )
				goto st30;
		} else
			goto st276;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto st276;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto st30;
			} else if ( (*p) >= 97 )
				goto st276;
		} else
			goto st30;
	} else
		goto st30;
	goto tr50;
st276:
	if ( ++p == pe )
		goto _test_eof276;
case 276:
	switch( (*p) ) {
		case 10: goto tr51;
		case 46: goto st276;
		case 61: goto st277;
		case 95: goto st276;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st30;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st30;
		} else
			goto st276;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st30;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st30;
		} else
			goto st276;
	} else
		goto st276;
	goto tr50;
st277:
	if ( ++p == pe )
		goto _test_eof277;
case 277:
	switch( (*p) ) {
		case 46: goto st278;
		case 95: goto st278;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st278;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st278;
	} else
		goto st278;
	goto tr50;
st278:
	if ( ++p == pe )
		goto _test_eof278;
case 278:
	switch( (*p) ) {
		case 46: goto st279;
		case 62: goto st280;
		case 95: goto st279;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st279;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st279;
	} else
		goto st279;
	goto tr50;
st279:
	if ( ++p == pe )
		goto _test_eof279;
case 279:
	switch( (*p) ) {
		case 46: goto st279;
		case 61: goto st277;
		case 62: goto st280;
		case 95: goto st279;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st279;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st279;
	} else
		goto st279;
	goto tr50;
st280:
	if ( ++p == pe )
		goto _test_eof280;
case 280:
	if ( (*p) == 10 )
		goto tr309;
	goto tr50;
tr32:
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st281;
st281:
	if ( ++p == pe )
		goto _test_eof281;
case 281:
#line 4231 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr51;
		case 61: goto st38;
		case 65: goto st282;
	}
	if ( (*p) < 66 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st30;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st30;
		} else
			goto st40;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st30;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st30;
		} else
			goto st40;
	} else
		goto st40;
	goto tr50;
st282:
	if ( ++p == pe )
		goto _test_eof282;
case 282:
	switch( (*p) ) {
		case 10: goto tr51;
		case 61: goto st38;
		case 77: goto st283;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st30;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st30;
		} else
			goto st40;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st30;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st30;
		} else
			goto st40;
	} else
		goto st40;
	goto tr50;
st283:
	if ( ++p == pe )
		goto _test_eof283;
case 283:
	switch( (*p) ) {
		case 10: goto tr51;
		case 61: goto st38;
		case 80: goto st284;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st30;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st30;
		} else
			goto st40;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st30;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st30;
		} else
			goto st40;
	} else
		goto st40;
	goto tr50;
st284:
	if ( ++p == pe )
		goto _test_eof284;
case 284:
	switch( (*p) ) {
		case 10: goto tr51;
		case 61: goto st38;
		case 76: goto st285;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st30;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st30;
		} else
			goto st40;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st30;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st30;
		} else
			goto st40;
	} else
		goto st40;
	goto tr50;
st285:
	if ( ++p == pe )
		goto _test_eof285;
case 285:
	switch( (*p) ) {
		case 10: goto tr51;
		case 61: goto st38;
		case 69: goto st286;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st30;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st30;
		} else
			goto st40;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st30;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st30;
		} else
			goto st40;
	} else
		goto st40;
	goto tr50;
st286:
	if ( ++p == pe )
		goto _test_eof286;
case 286:
	switch( (*p) ) {
		case 10: goto tr51;
		case 61: goto st287;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st30;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st30;
		} else
			goto st40;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st30;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st30;
		} else
			goto st40;
	} else
		goto st40;
	goto tr50;
st287:
	if ( ++p == pe )
		goto _test_eof287;
case 287:
	if ( (*p) == 60 )
		goto st288;
	if ( (*p) > 59 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st30;
	} else if ( (*p) >= 32 )
		goto st30;
	goto tr50;
st288:
	if ( ++p == pe )
		goto _test_eof288;
case 288:
	switch( (*p) ) {
		case 10: goto tr51;
		case 73: goto st289;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st30;
	} else if ( (*p) >= 32 )
		goto st30;
	goto tr50;
st289:
	if ( ++p == pe )
		goto _test_eof289;
case 289:
	switch( (*p) ) {
		case 10: goto tr51;
		case 68: goto st290;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st30;
	} else if ( (*p) >= 32 )
		goto st30;
	goto tr50;
st290:
	if ( ++p == pe )
		goto _test_eof290;
case 290:
	switch( (*p) ) {
		case 10: goto tr51;
		case 61: goto st291;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto st30;
	goto tr50;
st291:
	if ( ++p == pe )
		goto _test_eof291;
case 291:
	switch( (*p) ) {
		case 46: goto st292;
		case 95: goto st292;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st292;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st292;
	} else
		goto st292;
	goto tr50;
st292:
	if ( ++p == pe )
		goto _test_eof292;
case 292:
	switch( (*p) ) {
		case 44: goto st293;
		case 46: goto st292;
		case 95: goto st292;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st292;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st292;
	} else
		goto st292;
	goto tr50;
st293:
	if ( ++p == pe )
		goto _test_eof293;
case 293:
	if ( (*p) == 71 )
		goto st294;
	goto tr50;
st294:
	if ( ++p == pe )
		goto _test_eof294;
case 294:
	if ( (*p) == 101 )
		goto st295;
	goto tr50;
st295:
	if ( ++p == pe )
		goto _test_eof295;
case 295:
	if ( (*p) == 110 )
		goto st296;
	goto tr50;
st296:
	if ( ++p == pe )
		goto _test_eof296;
case 296:
	if ( (*p) == 111 )
		goto st297;
	goto tr50;
st297:
	if ( ++p == pe )
		goto _test_eof297;
case 297:
	if ( (*p) == 109 )
		goto st298;
	goto tr50;
st298:
	if ( ++p == pe )
		goto _test_eof298;
case 298:
	if ( (*p) == 101 )
		goto st299;
	goto tr50;
st299:
	if ( ++p == pe )
		goto _test_eof299;
case 299:
	if ( (*p) == 115 )
		goto st300;
	goto tr50;
st300:
	if ( ++p == pe )
		goto _test_eof300;
case 300:
	if ( (*p) == 61 )
		goto st301;
	goto tr50;
st301:
	if ( ++p == pe )
		goto _test_eof301;
case 301:
	switch( (*p) ) {
		case 46: goto st302;
		case 95: goto st302;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st302;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st302;
	} else
		goto st302;
	goto tr50;
st302:
	if ( ++p == pe )
		goto _test_eof302;
case 302:
	switch( (*p) ) {
		case 44: goto st303;
		case 46: goto st302;
		case 95: goto st302;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st302;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st302;
	} else
		goto st302;
	goto tr50;
st303:
	if ( ++p == pe )
		goto _test_eof303;
case 303:
	switch( (*p) ) {
		case 46: goto st302;
		case 77: goto st304;
		case 95: goto st302;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st302;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st302;
	} else
		goto st302;
	goto tr50;
st304:
	if ( ++p == pe )
		goto _test_eof304;
case 304:
	switch( (*p) ) {
		case 44: goto st303;
		case 46: goto st302;
		case 95: goto st302;
		case 105: goto st305;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st302;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st302;
	} else
		goto st302;
	goto tr50;
st305:
	if ( ++p == pe )
		goto _test_eof305;
case 305:
	switch( (*p) ) {
		case 44: goto st303;
		case 46: goto st302;
		case 95: goto st302;
		case 120: goto st306;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st302;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st302;
	} else
		goto st302;
	goto tr50;
st306:
	if ( ++p == pe )
		goto _test_eof306;
case 306:
	switch( (*p) ) {
		case 44: goto st303;
		case 46: goto st302;
		case 95: goto st302;
		case 116: goto st307;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st302;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st302;
	} else
		goto st302;
	goto tr50;
st307:
	if ( ++p == pe )
		goto _test_eof307;
case 307:
	switch( (*p) ) {
		case 44: goto st303;
		case 46: goto st302;
		case 95: goto st302;
		case 117: goto st308;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st302;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st302;
	} else
		goto st302;
	goto tr50;
st308:
	if ( ++p == pe )
		goto _test_eof308;
case 308:
	switch( (*p) ) {
		case 44: goto st303;
		case 46: goto st302;
		case 95: goto st302;
		case 114: goto st309;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st302;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st302;
	} else
		goto st302;
	goto tr50;
st309:
	if ( ++p == pe )
		goto _test_eof309;
case 309:
	switch( (*p) ) {
		case 44: goto st303;
		case 46: goto st302;
		case 95: goto st302;
		case 101: goto st310;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st302;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st302;
	} else
		goto st302;
	goto tr50;
st310:
	if ( ++p == pe )
		goto _test_eof310;
case 310:
	switch( (*p) ) {
		case 44: goto st303;
		case 46: goto st302;
		case 61: goto st311;
		case 95: goto st302;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st302;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st302;
	} else
		goto st302;
	goto tr50;
st311:
	if ( ++p == pe )
		goto _test_eof311;
case 311:
	switch( (*p) ) {
		case 46: goto st312;
		case 95: goto st312;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st312;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st312;
	} else
		goto st312;
	goto tr50;
st312:
	if ( ++p == pe )
		goto _test_eof312;
case 312:
	switch( (*p) ) {
		case 44: goto st313;
		case 46: goto st312;
		case 95: goto st312;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st312;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st312;
	} else
		goto st312;
	goto tr50;
st313:
	if ( ++p == pe )
		goto _test_eof313;
case 313:
	switch( (*p) ) {
		case 46: goto st312;
		case 68: goto st314;
		case 95: goto st312;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st312;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st312;
	} else
		goto st312;
	goto tr50;
st314:
	if ( ++p == pe )
		goto _test_eof314;
case 314:
	switch( (*p) ) {
		case 44: goto st313;
		case 46: goto st312;
		case 95: goto st312;
		case 101: goto st315;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st312;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st312;
	} else
		goto st312;
	goto tr50;
st315:
	if ( ++p == pe )
		goto _test_eof315;
case 315:
	switch( (*p) ) {
		case 44: goto st313;
		case 46: goto st312;
		case 95: goto st312;
		case 115: goto st316;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st312;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st312;
	} else
		goto st312;
	goto tr50;
st316:
	if ( ++p == pe )
		goto _test_eof316;
case 316:
	switch( (*p) ) {
		case 44: goto st313;
		case 46: goto st312;
		case 95: goto st312;
		case 99: goto st317;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st312;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st312;
	} else
		goto st312;
	goto tr50;
st317:
	if ( ++p == pe )
		goto _test_eof317;
case 317:
	switch( (*p) ) {
		case 44: goto st313;
		case 46: goto st312;
		case 95: goto st312;
		case 114: goto st318;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st312;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st312;
	} else
		goto st312;
	goto tr50;
st318:
	if ( ++p == pe )
		goto _test_eof318;
case 318:
	switch( (*p) ) {
		case 44: goto st313;
		case 46: goto st312;
		case 95: goto st312;
		case 105: goto st319;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st312;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st312;
	} else
		goto st312;
	goto tr50;
st319:
	if ( ++p == pe )
		goto _test_eof319;
case 319:
	switch( (*p) ) {
		case 44: goto st313;
		case 46: goto st312;
		case 95: goto st312;
		case 112: goto st320;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st312;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st312;
	} else
		goto st312;
	goto tr50;
st320:
	if ( ++p == pe )
		goto _test_eof320;
case 320:
	switch( (*p) ) {
		case 44: goto st313;
		case 46: goto st312;
		case 95: goto st312;
		case 116: goto st321;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st312;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st312;
	} else
		goto st312;
	goto tr50;
st321:
	if ( ++p == pe )
		goto _test_eof321;
case 321:
	switch( (*p) ) {
		case 44: goto st313;
		case 46: goto st312;
		case 95: goto st312;
		case 105: goto st322;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st312;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st312;
	} else
		goto st312;
	goto tr50;
st322:
	if ( ++p == pe )
		goto _test_eof322;
case 322:
	switch( (*p) ) {
		case 44: goto st313;
		case 46: goto st312;
		case 95: goto st312;
		case 111: goto st323;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st312;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st312;
	} else
		goto st312;
	goto tr50;
st323:
	if ( ++p == pe )
		goto _test_eof323;
case 323:
	switch( (*p) ) {
		case 44: goto st313;
		case 46: goto st312;
		case 95: goto st312;
		case 110: goto st324;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st312;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st312;
	} else
		goto st312;
	goto tr50;
st324:
	if ( ++p == pe )
		goto _test_eof324;
case 324:
	switch( (*p) ) {
		case 44: goto st313;
		case 46: goto st312;
		case 95: goto st312;
		case 115: goto st325;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st312;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st312;
	} else
		goto st312;
	goto tr50;
st325:
	if ( ++p == pe )
		goto _test_eof325;
case 325:
	switch( (*p) ) {
		case 44: goto st313;
		case 46: goto st312;
		case 61: goto st326;
		case 95: goto st312;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st312;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st312;
	} else
		goto st312;
	goto tr50;
st326:
	if ( ++p == pe )
		goto _test_eof326;
case 326:
	if ( (*p) == 34 )
		goto st327;
	goto tr50;
st327:
	if ( ++p == pe )
		goto _test_eof327;
case 327:
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st328;
	} else if ( (*p) >= 32 )
		goto st328;
	goto tr50;
st328:
	if ( ++p == pe )
		goto _test_eof328;
case 328:
	if ( (*p) == 34 )
		goto st329;
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st328;
	} else if ( (*p) >= 32 )
		goto st328;
	goto tr50;
st329:
	if ( ++p == pe )
		goto _test_eof329;
case 329:
	switch( (*p) ) {
		case 34: goto st329;
		case 62: goto st330;
	}
	if ( (*p) > 60 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto st328;
	} else if ( (*p) >= 32 )
		goto st328;
	goto tr50;
st330:
	if ( ++p == pe )
		goto _test_eof330;
case 330:
	switch( (*p) ) {
		case 10: goto tr309;
		case 34: goto st329;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st328;
	} else if ( (*p) >= 32 )
		goto st328;
	goto tr50;
tr33:
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st331;
st331:
	if ( ++p == pe )
		goto _test_eof331;
case 331:
#line 5083 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr51;
		case 61: goto st38;
		case 115: goto st332;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st30;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st30;
		} else
			goto st40;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st30;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st30;
		} else
			goto st40;
	} else
		goto st40;
	goto tr50;
st332:
	if ( ++p == pe )
		goto _test_eof332;
case 332:
	switch( (*p) ) {
		case 10: goto tr51;
		case 61: goto st38;
		case 115: goto st333;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st30;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st30;
		} else
			goto st40;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st30;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st30;
		} else
			goto st40;
	} else
		goto st40;
	goto tr50;
st333:
	if ( ++p == pe )
		goto _test_eof333;
case 333:
	switch( (*p) ) {
		case 10: goto tr51;
		case 61: goto st38;
		case 101: goto st334;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st30;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st30;
		} else
			goto st40;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st30;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st30;
		} else
			goto st40;
	} else
		goto st40;
	goto tr50;
st334:
	if ( ++p == pe )
		goto _test_eof334;
case 334:
	switch( (*p) ) {
		case 10: goto tr51;
		case 61: goto st38;
		case 109: goto st335;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st30;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st30;
		} else
			goto st40;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st30;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st30;
		} else
			goto st40;
	} else
		goto st40;
	goto tr50;
st335:
	if ( ++p == pe )
		goto _test_eof335;
case 335:
	switch( (*p) ) {
		case 10: goto tr51;
		case 61: goto st38;
		case 98: goto st336;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st30;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st30;
		} else
			goto st40;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st30;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st30;
		} else
			goto st40;
	} else
		goto st40;
	goto tr50;
st336:
	if ( ++p == pe )
		goto _test_eof336;
case 336:
	switch( (*p) ) {
		case 10: goto tr51;
		case 61: goto st38;
		case 108: goto st337;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st30;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st30;
		} else
			goto st40;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st30;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st30;
		} else
			goto st40;
	} else
		goto st40;
	goto tr50;
st337:
	if ( ++p == pe )
		goto _test_eof337;
case 337:
	switch( (*p) ) {
		case 10: goto tr51;
		case 61: goto st38;
		case 121: goto st338;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st30;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st30;
		} else
			goto st40;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st30;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st30;
		} else
			goto st40;
	} else
		goto st40;
	goto tr50;
st338:
	if ( ++p == pe )
		goto _test_eof338;
case 338:
	switch( (*p) ) {
		case 10: goto tr51;
		case 61: goto st339;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st30;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st30;
		} else
			goto st40;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st30;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st30;
		} else
			goto st40;
	} else
		goto st40;
	goto tr50;
st339:
	if ( ++p == pe )
		goto _test_eof339;
case 339:
	if ( (*p) == 61 )
		goto st341;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto st340;
	goto tr50;
st340:
	if ( ++p == pe )
		goto _test_eof340;
case 340:
	switch( (*p) ) {
		case 10: goto tr51;
		case 61: goto st341;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto st340;
	goto tr50;
st341:
	if ( ++p == pe )
		goto _test_eof341;
case 341:
	if ( (*p) == 10 )
		goto tr309;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto st341;
	goto tr50;
tr34:
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st342;
st342:
	if ( ++p == pe )
		goto _test_eof342;
case 342:
#line 5358 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr51;
		case 61: goto st38;
		case 111: goto st343;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st30;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st30;
		} else
			goto st40;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st30;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st30;
		} else
			goto st40;
	} else
		goto st40;
	goto tr50;
st343:
	if ( ++p == pe )
		goto _test_eof343;
case 343:
	switch( (*p) ) {
		case 10: goto tr51;
		case 61: goto st38;
		case 110: goto st344;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st30;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st30;
		} else
			goto st40;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st30;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st30;
		} else
			goto st40;
	} else
		goto st40;
	goto tr50;
st344:
	if ( ++p == pe )
		goto _test_eof344;
case 344:
	switch( (*p) ) {
		case 10: goto tr51;
		case 61: goto st38;
		case 116: goto st345;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st30;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st30;
		} else
			goto st40;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st30;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st30;
		} else
			goto st40;
	} else
		goto st40;
	goto tr50;
st345:
	if ( ++p == pe )
		goto _test_eof345;
case 345:
	switch( (*p) ) {
		case 10: goto tr51;
		case 61: goto st38;
		case 105: goto st346;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st30;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st30;
		} else
			goto st40;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st30;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st30;
		} else
			goto st40;
	} else
		goto st40;
	goto tr50;
st346:
	if ( ++p == pe )
		goto _test_eof346;
case 346:
	switch( (*p) ) {
		case 10: goto tr51;
		case 61: goto st38;
		case 103: goto st347;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st30;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st30;
		} else
			goto st40;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st30;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st30;
		} else
			goto st40;
	} else
		goto st40;
	goto tr50;
st347:
	if ( ++p == pe )
		goto _test_eof347;
case 347:
	switch( (*p) ) {
		case 10: goto tr51;
		case 61: goto st348;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st30;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st30;
		} else
			goto st40;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st30;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st30;
		} else
			goto st40;
	} else
		goto st40;
	goto tr50;
st348:
	if ( ++p == pe )
		goto _test_eof348;
case 348:
	if ( (*p) == 60 )
		goto st349;
	if ( (*p) > 59 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st30;
	} else if ( (*p) >= 32 )
		goto st30;
	goto tr50;
st349:
	if ( ++p == pe )
		goto _test_eof349;
case 349:
	switch( (*p) ) {
		case 10: goto tr51;
		case 73: goto st350;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st30;
	} else if ( (*p) >= 32 )
		goto st30;
	goto tr50;
st350:
	if ( ++p == pe )
		goto _test_eof350;
case 350:
	switch( (*p) ) {
		case 10: goto tr51;
		case 68: goto st351;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st30;
	} else if ( (*p) >= 32 )
		goto st30;
	goto tr50;
st351:
	if ( ++p == pe )
		goto _test_eof351;
case 351:
	switch( (*p) ) {
		case 10: goto tr51;
		case 61: goto st352;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto st30;
	goto tr50;
st352:
	if ( ++p == pe )
		goto _test_eof352;
case 352:
	switch( (*p) ) {
		case 46: goto st353;
		case 95: goto st353;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st353;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st353;
	} else
		goto st353;
	goto tr50;
st353:
	if ( ++p == pe )
		goto _test_eof353;
case 353:
	switch( (*p) ) {
		case 44: goto st354;
		case 46: goto st353;
		case 95: goto st353;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st353;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st353;
	} else
		goto st353;
	goto tr50;
st354:
	if ( ++p == pe )
		goto _test_eof354;
case 354:
	if ( (*p) == 85 )
		goto st355;
	goto tr50;
st355:
	if ( ++p == pe )
		goto _test_eof355;
case 355:
	if ( (*p) == 82 )
		goto st356;
	goto tr50;
st356:
	if ( ++p == pe )
		goto _test_eof356;
case 356:
	if ( (*p) == 76 )
		goto st357;
	goto tr50;
st357:
	if ( ++p == pe )
		goto _test_eof357;
case 357:
	if ( (*p) == 61 )
		goto st358;
	goto tr50;
st358:
	if ( ++p == pe )
		goto _test_eof358;
case 358:
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st359;
	} else if ( (*p) >= 32 )
		goto st359;
	goto tr50;
st359:
	if ( ++p == pe )
		goto _test_eof359;
case 359:
	if ( (*p) == 62 )
		goto st360;
	if ( (*p) > 60 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto st359;
	} else if ( (*p) >= 32 )
		goto st359;
	goto tr50;
st360:
	if ( ++p == pe )
		goto _test_eof360;
case 360:
	switch( (*p) ) {
		case 10: goto tr309;
		case 62: goto st360;
	}
	if ( (*p) > 60 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto st359;
	} else if ( (*p) >= 32 )
		goto st359;
	goto tr50;
tr35:
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st361;
st361:
	if ( ++p == pe )
		goto _test_eof361;
case 361:
#line 5694 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr51;
		case 61: goto st38;
		case 101: goto st362;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st30;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st30;
		} else
			goto st40;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st30;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st30;
		} else
			goto st40;
	} else
		goto st40;
	goto tr50;
st362:
	if ( ++p == pe )
		goto _test_eof362;
case 362:
	switch( (*p) ) {
		case 10: goto tr51;
		case 61: goto st38;
		case 100: goto st363;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st30;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st30;
		} else
			goto st40;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st30;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st30;
		} else
			goto st40;
	} else
		goto st40;
	goto tr50;
st363:
	if ( ++p == pe )
		goto _test_eof363;
case 363:
	switch( (*p) ) {
		case 10: goto tr51;
		case 61: goto st38;
		case 105: goto st364;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st30;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st30;
		} else
			goto st40;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st30;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st30;
		} else
			goto st40;
	} else
		goto st40;
	goto tr50;
st364:
	if ( ++p == pe )
		goto _test_eof364;
case 364:
	switch( (*p) ) {
		case 10: goto tr51;
		case 61: goto st38;
		case 103: goto st365;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st30;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st30;
		} else
			goto st40;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st30;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st30;
		} else
			goto st40;
	} else
		goto st40;
	goto tr50;
st365:
	if ( ++p == pe )
		goto _test_eof365;
case 365:
	switch( (*p) ) {
		case 10: goto tr51;
		case 61: goto st38;
		case 114: goto st366;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st30;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st30;
		} else
			goto st40;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st30;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st30;
		} else
			goto st40;
	} else
		goto st40;
	goto tr50;
st366:
	if ( ++p == pe )
		goto _test_eof366;
case 366:
	switch( (*p) ) {
		case 10: goto tr51;
		case 61: goto st38;
		case 101: goto st367;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st30;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st30;
		} else
			goto st40;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st30;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st30;
		} else
			goto st40;
	} else
		goto st40;
	goto tr50;
st367:
	if ( ++p == pe )
		goto _test_eof367;
case 367:
	switch( (*p) ) {
		case 10: goto tr51;
		case 61: goto st38;
		case 101: goto st368;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st30;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st30;
		} else
			goto st40;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st30;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st30;
		} else
			goto st40;
	} else
		goto st40;
	goto tr50;
st368:
	if ( ++p == pe )
		goto _test_eof368;
case 368:
	switch( (*p) ) {
		case 10: goto tr51;
		case 61: goto st38;
		case 68: goto st369;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st30;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st30;
		} else
			goto st40;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st30;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st30;
		} else
			goto st40;
	} else
		goto st40;
	goto tr50;
st369:
	if ( ++p == pe )
		goto _test_eof369;
case 369:
	switch( (*p) ) {
		case 10: goto tr51;
		case 61: goto st38;
		case 66: goto st370;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st30;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st30;
		} else
			goto st40;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st30;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st30;
		} else
			goto st40;
	} else
		goto st40;
	goto tr50;
st370:
	if ( ++p == pe )
		goto _test_eof370;
case 370:
	switch( (*p) ) {
		case 10: goto tr51;
		case 61: goto st371;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st30;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st30;
		} else
			goto st40;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st30;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st30;
		} else
			goto st40;
	} else
		goto st40;
	goto tr50;
st371:
	if ( ++p == pe )
		goto _test_eof371;
case 371:
	if ( (*p) == 60 )
		goto st372;
	if ( (*p) > 59 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st30;
	} else if ( (*p) >= 32 )
		goto st30;
	goto tr50;
st372:
	if ( ++p == pe )
		goto _test_eof372;
case 372:
	switch( (*p) ) {
		case 10: goto tr51;
		case 61: goto st373;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto st372;
	goto tr50;
st373:
	if ( ++p == pe )
		goto _test_eof373;
case 373:
	if ( (*p) == 62 )
		goto st374;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto st373;
	goto tr50;
st374:
	if ( ++p == pe )
		goto _test_eof374;
case 374:
	switch( (*p) ) {
		case 10: goto tr309;
		case 62: goto st374;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto st373;
	goto tr50;
st375:
	if ( ++p == pe )
		goto _test_eof375;
case 375:
	if ( (*p) == 72 )
		goto st376;
	goto tr400;
st376:
	if ( ++p == pe )
		goto _test_eof376;
case 376:
	if ( (*p) == 82 )
		goto st377;
	goto tr400;
st377:
	if ( ++p == pe )
		goto _test_eof377;
case 377:
	if ( (*p) == 79 )
		goto st378;
	goto tr400;
st378:
	if ( ++p == pe )
		goto _test_eof378;
case 378:
	if ( (*p) == 77 )
		goto st379;
	goto tr400;
st379:
	if ( ++p == pe )
		goto _test_eof379;
case 379:
	if ( (*p) == 9 )
		goto st380;
	goto tr400;
st380:
	if ( ++p == pe )
		goto _test_eof380;
case 380:
	if ( (*p) == 80 )
		goto st381;
	goto tr400;
st381:
	if ( ++p == pe )
		goto _test_eof381;
case 381:
	if ( (*p) == 79 )
		goto st382;
	goto tr400;
st382:
	if ( ++p == pe )
		goto _test_eof382;
case 382:
	if ( (*p) == 83 )
		goto st383;
	goto tr400;
st383:
	if ( ++p == pe )
		goto _test_eof383;
case 383:
	if ( (*p) == 9 )
		goto st384;
	goto tr400;
st384:
	if ( ++p == pe )
		goto _test_eof384;
case 384:
	if ( (*p) == 73 )
		goto st385;
	goto tr400;
st385:
	if ( ++p == pe )
		goto _test_eof385;
case 385:
	if ( (*p) == 68 )
		goto st386;
	goto tr400;
st386:
	if ( ++p == pe )
		goto _test_eof386;
case 386:
	if ( (*p) == 9 )
		goto st387;
	goto tr400;
st387:
	if ( ++p == pe )
		goto _test_eof387;
case 387:
	if ( (*p) == 82 )
		goto st388;
	goto tr400;
st388:
	if ( ++p == pe )
		goto _test_eof388;
case 388:
	if ( (*p) == 69 )
		goto st389;
	goto tr400;
st389:
	if ( ++p == pe )
		goto _test_eof389;
case 389:
	if ( (*p) == 70 )
		goto st390;
	goto tr400;
st390:
	if ( ++p == pe )
		goto _test_eof390;
case 390:
	if ( (*p) == 9 )
		goto st391;
	goto tr400;
st391:
	if ( ++p == pe )
		goto _test_eof391;
case 391:
	if ( (*p) == 65 )
		goto st392;
	goto tr400;
st392:
	if ( ++p == pe )
		goto _test_eof392;
case 392:
	if ( (*p) == 76 )
		goto st393;
	goto tr400;
st393:
	if ( ++p == pe )
		goto _test_eof393;
case 393:
	if ( (*p) == 84 )
		goto st394;
	goto tr400;
st394:
	if ( ++p == pe )
		goto _test_eof394;
case 394:
	if ( (*p) == 9 )
		goto st395;
	goto tr400;
st395:
	if ( ++p == pe )
		goto _test_eof395;
case 395:
	if ( (*p) == 81 )
		goto st396;
	goto tr400;
st396:
	if ( ++p == pe )
		goto _test_eof396;
case 396:
	if ( (*p) == 85 )
		goto st397;
	goto tr400;
st397:
	if ( ++p == pe )
		goto _test_eof397;
case 397:
	if ( (*p) == 65 )
		goto st398;
	goto tr400;
st398:
	if ( ++p == pe )
		goto _test_eof398;
case 398:
	if ( (*p) == 76 )
		goto st399;
	goto tr400;
st399:
	if ( ++p == pe )
		goto _test_eof399;
case 399:
	if ( (*p) == 9 )
		goto st400;
	goto tr400;
st400:
	if ( ++p == pe )
		goto _test_eof400;
case 400:
	if ( (*p) == 70 )
		goto st401;
	goto tr400;
st401:
	if ( ++p == pe )
		goto _test_eof401;
case 401:
	if ( (*p) == 73 )
		goto st402;
	goto tr400;
st402:
	if ( ++p == pe )
		goto _test_eof402;
case 402:
	if ( (*p) == 76 )
		goto st403;
	goto tr400;
st403:
	if ( ++p == pe )
		goto _test_eof403;
case 403:
	if ( (*p) == 84 )
		goto st404;
	goto tr400;
st404:
	if ( ++p == pe )
		goto _test_eof404;
case 404:
	if ( (*p) == 69 )
		goto st405;
	goto tr400;
st405:
	if ( ++p == pe )
		goto _test_eof405;
case 405:
	if ( (*p) == 82 )
		goto st406;
	goto tr400;
st406:
	if ( ++p == pe )
		goto _test_eof406;
case 406:
	if ( (*p) == 9 )
		goto st407;
	goto tr400;
st407:
	if ( ++p == pe )
		goto _test_eof407;
case 407:
	if ( (*p) == 73 )
		goto st408;
	goto tr400;
st408:
	if ( ++p == pe )
		goto _test_eof408;
case 408:
	if ( (*p) == 78 )
		goto st409;
	goto tr400;
st409:
	if ( ++p == pe )
		goto _test_eof409;
case 409:
	if ( (*p) == 70 )
		goto st410;
	goto tr400;
st410:
	if ( ++p == pe )
		goto _test_eof410;
case 410:
	if ( (*p) == 79 )
		goto st411;
	goto tr400;
st411:
	if ( ++p == pe )
		goto _test_eof411;
case 411:
	switch( (*p) ) {
		case 9: goto st412;
		case 10: goto tr438;
	}
	goto tr400;
st412:
	if ( ++p == pe )
		goto _test_eof412;
case 412:
	if ( (*p) == 70 )
		goto st413;
	goto tr400;
st413:
	if ( ++p == pe )
		goto _test_eof413;
case 413:
	if ( (*p) == 79 )
		goto st414;
	goto tr400;
st414:
	if ( ++p == pe )
		goto _test_eof414;
case 414:
	if ( (*p) == 82 )
		goto st415;
	goto tr400;
st415:
	if ( ++p == pe )
		goto _test_eof415;
case 415:
	if ( (*p) == 77 )
		goto st416;
	goto tr400;
st416:
	if ( ++p == pe )
		goto _test_eof416;
case 416:
	if ( (*p) == 65 )
		goto st417;
	goto tr400;
st417:
	if ( ++p == pe )
		goto _test_eof417;
case 417:
	if ( (*p) == 84 )
		goto st418;
	goto tr400;
st418:
	if ( ++p == pe )
		goto _test_eof418;
case 418:
	if ( (*p) == 9 )
		goto st419;
	goto tr400;
tr447:
#line 87 "vcf_v41.ragel"
	{
//        add_vcf_sample_name(ts, p-ts, file);
    }
	goto st419;
st419:
	if ( ++p == pe )
		goto _test_eof419;
case 419:
#line 6353 "vcf_validator_detail.hpp"
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr446;
	goto tr400;
tr446:
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st420;
st420:
	if ( ++p == pe )
		goto _test_eof420;
case 420:
#line 6367 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr447;
		case 10: goto tr448;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto st420;
	goto tr400;
tr438:
#line 20 "vcf_v41.ragel"
	{
        ++n_lines;
        n_columns = 1;
    }
	goto st497;
tr448:
#line 87 "vcf_v41.ragel"
	{
//        add_vcf_sample_name(ts, p-ts, file);
    }
#line 20 "vcf_v41.ragel"
	{
        ++n_lines;
        n_columns = 1;
    }
	goto st497;
st497:
	if ( ++p == pe )
		goto _test_eof497;
case 497:
#line 6397 "vcf_validator_detail.hpp"
	if ( (*p) > 57 ) {
		if ( 59 <= (*p) && (*p) <= 126 )
			goto tr555;
	} else if ( (*p) >= 33 )
		goto tr555;
	goto tr554;
tr555:
#line 91 "vcf_v41.ragel"
	{
//        status->current_record = vcf_record_new();
//        printf("Reading record\n");
    }
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st421;
st421:
	if ( ++p == pe )
		goto _test_eof421;
case 421:
#line 6419 "vcf_validator_detail.hpp"
	if ( (*p) == 9 )
		goto tr451;
	if ( (*p) > 57 ) {
		if ( 59 <= (*p) && (*p) <= 126 )
			goto st421;
	} else if ( (*p) >= 33 )
		goto st421;
	goto tr450;
tr451:
#line 120 "vcf_v41.ragel"
	{
//        set_vcf_record_chromosome(ts, p-ts, status->current_record);
    }
#line 25 "vcf_v41.ragel"
	{
        ++n_columns;
    }
	goto st422;
st422:
	if ( ++p == pe )
		goto _test_eof422;
case 422:
#line 6442 "vcf_validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr454;
	goto tr453;
tr454:
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st423;
st423:
	if ( ++p == pe )
		goto _test_eof423;
case 423:
#line 6456 "vcf_validator_detail.hpp"
	if ( (*p) == 9 )
		goto tr455;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st423;
	goto tr453;
tr455:
#line 127 "vcf_v41.ragel"
	{
//        char *field = strndup(ts, p-ts);
 //       set_vcf_record_position(atol(field), status->current_record);
 //       free(field);
    }
#line 25 "vcf_v41.ragel"
	{
        ++n_columns;
    }
	goto st424;
st424:
	if ( ++p == pe )
		goto _test_eof424;
case 424:
#line 6478 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 46: goto tr458;
		case 95: goto tr459;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr459;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr459;
	} else
		goto tr459;
	goto tr457;
tr458:
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st425;
st425:
	if ( ++p == pe )
		goto _test_eof425;
case 425:
#line 6502 "vcf_validator_detail.hpp"
	if ( (*p) == 9 )
		goto tr460;
	goto tr457;
tr460:
#line 138 "vcf_v41.ragel"
	{
//        set_vcf_record_id(ts, p-ts, status->current_record);
    }
#line 25 "vcf_v41.ragel"
	{
        ++n_columns;
    }
	goto st426;
st426:
	if ( ++p == pe )
		goto _test_eof426;
case 426:
#line 6520 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 65: goto tr462;
		case 67: goto tr462;
		case 71: goto tr462;
		case 78: goto tr462;
		case 84: goto tr462;
		case 97: goto tr462;
		case 99: goto tr462;
		case 103: goto tr462;
		case 110: goto tr462;
		case 116: goto tr462;
	}
	goto tr461;
tr462:
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st427;
st427:
	if ( ++p == pe )
		goto _test_eof427;
case 427:
#line 6544 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr463;
		case 65: goto st427;
		case 67: goto st427;
		case 71: goto st427;
		case 78: goto st427;
		case 84: goto st427;
		case 97: goto st427;
		case 99: goto st427;
		case 103: goto st427;
		case 110: goto st427;
		case 116: goto st427;
	}
	goto tr461;
tr463:
#line 147 "vcf_v41.ragel"
	{
 //       set_vcf_record_reference(ts, p-ts, status->current_record);
    }
#line 25 "vcf_v41.ragel"
	{
        ++n_columns;
    }
	goto st428;
st428:
	if ( ++p == pe )
		goto _test_eof428;
case 428:
#line 6573 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 46: goto tr466;
		case 48: goto tr467;
		case 60: goto tr468;
		case 65: goto tr469;
		case 67: goto tr469;
		case 71: goto tr469;
		case 78: goto tr469;
		case 84: goto tr469;
		case 91: goto tr470;
		case 93: goto tr471;
		case 97: goto tr469;
		case 99: goto tr469;
		case 103: goto tr469;
		case 110: goto tr469;
		case 116: goto tr469;
	}
	goto tr465;
tr466:
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st429;
st429:
	if ( ++p == pe )
		goto _test_eof429;
case 429:
#line 6602 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr472;
		case 44: goto st449;
		case 46: goto st429;
		case 65: goto st429;
		case 67: goto st429;
		case 71: goto st429;
		case 78: goto st429;
		case 84: goto st429;
		case 97: goto st429;
		case 99: goto st429;
		case 103: goto st429;
		case 110: goto st429;
		case 116: goto st429;
	}
	goto tr465;
tr472:
#line 164 "vcf_v41.ragel"
	{
 //       set_vcf_record_type(VARIANT_SNV, status->current_record);
    }
#line 156 "vcf_v41.ragel"
	{
 /*       if (!strncmp("0", ts, 1)) {
            set_vcf_record_alternate(".", 1, status->current_record);
        } else {
            set_vcf_record_alternate(ts, p-ts, status->current_record);
        }*/
    }
#line 25 "vcf_v41.ragel"
	{
        ++n_columns;
    }
	goto st430;
tr513:
#line 168 "vcf_v41.ragel"
	{
 //       set_vcf_record_type(VARIANT_INDEL, status->current_record);
    }
#line 156 "vcf_v41.ragel"
	{
 /*       if (!strncmp("0", ts, 1)) {
            set_vcf_record_alternate(".", 1, status->current_record);
        } else {
            set_vcf_record_alternate(ts, p-ts, status->current_record);
        }*/
    }
#line 25 "vcf_v41.ragel"
	{
        ++n_columns;
    }
	goto st430;
tr537:
#line 172 "vcf_v41.ragel"
	{
 //       set_vcf_record_type(VARIANT_SV, status->current_record);
    }
#line 156 "vcf_v41.ragel"
	{
 /*       if (!strncmp("0", ts, 1)) {
            set_vcf_record_alternate(".", 1, status->current_record);
        } else {
            set_vcf_record_alternate(ts, p-ts, status->current_record);
        }*/
    }
#line 25 "vcf_v41.ragel"
	{
        ++n_columns;
    }
	goto st430;
st430:
	if ( ++p == pe )
		goto _test_eof430;
case 430:
#line 6677 "vcf_validator_detail.hpp"
	if ( (*p) == 46 )
		goto tr476;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr477;
	goto tr475;
tr476:
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st431;
st431:
	if ( ++p == pe )
		goto _test_eof431;
case 431:
#line 6693 "vcf_validator_detail.hpp"
	if ( (*p) == 9 )
		goto tr478;
	goto tr475;
tr478:
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
#line 25 "vcf_v41.ragel"
	{
        ++n_columns;
    }
	goto st432;
st432:
	if ( ++p == pe )
		goto _test_eof432;
case 432:
#line 6717 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto tr480;
		case 46: goto tr480;
		case 95: goto tr480;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr480;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr480;
	} else
		goto tr480;
	goto tr479;
tr480:
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st433;
st433:
	if ( ++p == pe )
		goto _test_eof433;
case 433:
#line 6742 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr481;
		case 44: goto st433;
		case 46: goto st433;
		case 59: goto st445;
		case 95: goto st433;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st433;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st433;
	} else
		goto st433;
	goto tr479;
tr481:
#line 196 "vcf_v41.ragel"
	{
 //       set_vcf_record_filter(ts, p-ts, status->current_record);
    }
#line 25 "vcf_v41.ragel"
	{
        ++n_columns;
    }
	goto st434;
st434:
	if ( ++p == pe )
		goto _test_eof434;
case 434:
#line 6773 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 46: goto tr485;
		case 95: goto tr486;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr486;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr486;
	} else
		goto tr486;
	goto tr484;
tr485:
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st435;
st435:
	if ( ++p == pe )
		goto _test_eof435;
case 435:
#line 6797 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr487;
		case 10: goto tr488;
		case 59: goto st441;
		case 61: goto st443;
	}
	goto tr484;
tr487:
#line 205 "vcf_v41.ragel"
	{
//        set_vcf_record_info(ts, p-ts, status->current_record);
    }
#line 25 "vcf_v41.ragel"
	{
        ++n_columns;
    }
	goto st436;
st436:
	if ( ++p == pe )
		goto _test_eof436;
case 436:
#line 6819 "vcf_validator_detail.hpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr492;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr492;
	} else
		goto tr492;
	goto tr491;
tr492:
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st437;
st437:
	if ( ++p == pe )
		goto _test_eof437;
case 437:
#line 6839 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr493;
		case 58: goto st440;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st437;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st437;
	} else
		goto st437;
	goto tr491;
tr493:
#line 214 "vcf_v41.ragel"
	{
 //       set_vcf_record_format(ts, p-ts, status->current_record);
    }
#line 25 "vcf_v41.ragel"
	{
        ++n_columns;
    }
	goto st438;
tr498:
#line 223 "vcf_v41.ragel"
	{
//        add_vcf_record_sample(ts, p-ts, status->current_record);
    }
#line 25 "vcf_v41.ragel"
	{
        ++n_columns;
    }
	goto st438;
st438:
	if ( ++p == pe )
		goto _test_eof438;
case 438:
#line 6877 "vcf_validator_detail.hpp"
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr497;
	goto tr496;
tr497:
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st439;
st439:
	if ( ++p == pe )
		goto _test_eof439;
case 439:
#line 6891 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr498;
		case 10: goto tr499;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st439;
	goto tr496;
tr488:
#line 205 "vcf_v41.ragel"
	{
//        set_vcf_record_info(ts, p-ts, status->current_record);
    }
#line 96 "vcf_v41.ragel"
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
#line 20 "vcf_v41.ragel"
	{
        ++n_lines;
        n_columns = 1;
    }
	goto st498;
tr499:
#line 223 "vcf_v41.ragel"
	{
//        add_vcf_record_sample(ts, p-ts, status->current_record);
    }
#line 96 "vcf_v41.ragel"
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
#line 20 "vcf_v41.ragel"
	{
        ++n_lines;
        n_columns = 1;
    }
	goto st498;
st498:
	if ( ++p == pe )
		goto _test_eof498;
case 498:
#line 6973 "vcf_validator_detail.hpp"
	if ( (*p) > 57 ) {
		if ( 59 <= (*p) && (*p) <= 126 )
			goto tr555;
	} else if ( (*p) >= 33 )
		goto tr555;
	goto tr450;
st440:
	if ( ++p == pe )
		goto _test_eof440;
case 440:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st437;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st437;
	} else
		goto st437;
	goto tr491;
st441:
	if ( ++p == pe )
		goto _test_eof441;
case 441:
	switch( (*p) ) {
		case 46: goto st435;
		case 95: goto st442;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st442;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st442;
	} else
		goto st442;
	goto tr484;
tr486:
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st442;
st442:
	if ( ++p == pe )
		goto _test_eof442;
case 442:
#line 7020 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr487;
		case 10: goto tr488;
		case 59: goto st441;
		case 61: goto st443;
		case 95: goto st442;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st442;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st442;
	} else
		goto st442;
	goto tr484;
st443:
	if ( ++p == pe )
		goto _test_eof443;
case 443:
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st444;
	goto tr484;
st444:
	if ( ++p == pe )
		goto _test_eof444;
case 444:
	switch( (*p) ) {
		case 9: goto tr487;
		case 10: goto tr488;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st444;
	goto tr484;
st445:
	if ( ++p == pe )
		goto _test_eof445;
case 445:
	switch( (*p) ) {
		case 44: goto st433;
		case 46: goto st433;
		case 95: goto st433;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st433;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st433;
	} else
		goto st433;
	goto tr479;
tr477:
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st446;
st446:
	if ( ++p == pe )
		goto _test_eof446;
case 446:
#line 7083 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr478;
		case 46: goto st447;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st446;
	goto tr475;
st447:
	if ( ++p == pe )
		goto _test_eof447;
case 447:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st448;
	goto tr475;
st448:
	if ( ++p == pe )
		goto _test_eof448;
case 448:
	if ( (*p) == 9 )
		goto tr478;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st448;
	goto tr475;
st449:
	if ( ++p == pe )
		goto _test_eof449;
case 449:
	switch( (*p) ) {
		case 46: goto st429;
		case 65: goto st429;
		case 67: goto st429;
		case 71: goto st429;
		case 78: goto st429;
		case 84: goto st429;
		case 97: goto st429;
		case 99: goto st429;
		case 103: goto st429;
		case 110: goto st429;
		case 116: goto st429;
	}
	goto tr465;
tr467:
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st450;
st450:
	if ( ++p == pe )
		goto _test_eof450;
case 450:
#line 7135 "vcf_validator_detail.hpp"
	if ( (*p) == 9 )
		goto tr472;
	goto tr465;
tr468:
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st451;
st451:
	if ( ++p == pe )
		goto _test_eof451;
case 451:
#line 7149 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 67: goto st452;
		case 68: goto st456;
		case 73: goto st472;
	}
	goto tr465;
st452:
	if ( ++p == pe )
		goto _test_eof452;
case 452:
	if ( (*p) == 78 )
		goto st453;
	goto tr465;
st453:
	if ( ++p == pe )
		goto _test_eof453;
case 453:
	if ( (*p) == 86 )
		goto st454;
	goto tr465;
st454:
	if ( ++p == pe )
		goto _test_eof454;
case 454:
	if ( (*p) == 62 )
		goto st455;
	goto tr465;
st455:
	if ( ++p == pe )
		goto _test_eof455;
case 455:
	if ( (*p) == 9 )
		goto tr513;
	goto tr465;
st456:
	if ( ++p == pe )
		goto _test_eof456;
case 456:
	switch( (*p) ) {
		case 69: goto st457;
		case 85: goto st464;
	}
	goto tr465;
st457:
	if ( ++p == pe )
		goto _test_eof457;
case 457:
	if ( (*p) == 76 )
		goto st458;
	goto tr465;
st458:
	if ( ++p == pe )
		goto _test_eof458;
case 458:
	switch( (*p) ) {
		case 58: goto st459;
		case 62: goto st455;
	}
	goto tr465;
st459:
	if ( ++p == pe )
		goto _test_eof459;
case 459:
	if ( (*p) == 77 )
		goto st460;
	goto tr465;
st460:
	if ( ++p == pe )
		goto _test_eof460;
case 460:
	if ( (*p) == 69 )
		goto st461;
	goto tr465;
st461:
	if ( ++p == pe )
		goto _test_eof461;
case 461:
	if ( (*p) == 58 )
		goto st462;
	goto tr465;
st462:
	if ( ++p == pe )
		goto _test_eof462;
case 462:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st463;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st463;
	} else
		goto st463;
	goto tr465;
st463:
	if ( ++p == pe )
		goto _test_eof463;
case 463:
	if ( (*p) == 62 )
		goto st455;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st463;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st463;
	} else
		goto st463;
	goto tr465;
st464:
	if ( ++p == pe )
		goto _test_eof464;
case 464:
	if ( (*p) == 80 )
		goto st465;
	goto tr465;
st465:
	if ( ++p == pe )
		goto _test_eof465;
case 465:
	switch( (*p) ) {
		case 58: goto st466;
		case 62: goto st455;
	}
	goto tr465;
st466:
	if ( ++p == pe )
		goto _test_eof466;
case 466:
	if ( (*p) == 84 )
		goto st467;
	goto tr465;
st467:
	if ( ++p == pe )
		goto _test_eof467;
case 467:
	if ( (*p) == 65 )
		goto st468;
	goto tr465;
st468:
	if ( ++p == pe )
		goto _test_eof468;
case 468:
	if ( (*p) == 78 )
		goto st469;
	goto tr465;
st469:
	if ( ++p == pe )
		goto _test_eof469;
case 469:
	if ( (*p) == 68 )
		goto st470;
	goto tr465;
st470:
	if ( ++p == pe )
		goto _test_eof470;
case 470:
	if ( (*p) == 69 )
		goto st471;
	goto tr465;
st471:
	if ( ++p == pe )
		goto _test_eof471;
case 471:
	if ( (*p) == 77 )
		goto st454;
	goto tr465;
st472:
	if ( ++p == pe )
		goto _test_eof472;
case 472:
	if ( (*p) == 78 )
		goto st473;
	goto tr465;
st473:
	if ( ++p == pe )
		goto _test_eof473;
case 473:
	switch( (*p) ) {
		case 83: goto st458;
		case 86: goto st454;
	}
	goto tr465;
tr469:
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st474;
st474:
	if ( ++p == pe )
		goto _test_eof474;
case 474:
#line 7342 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr472;
		case 44: goto st449;
		case 46: goto st429;
		case 65: goto st474;
		case 67: goto st474;
		case 71: goto st474;
		case 78: goto st474;
		case 84: goto st474;
		case 91: goto st475;
		case 93: goto st480;
		case 97: goto st474;
		case 99: goto st474;
		case 103: goto st474;
		case 110: goto st474;
		case 116: goto st474;
	}
	goto tr465;
st475:
	if ( ++p == pe )
		goto _test_eof475;
case 475:
	if ( (*p) > 57 ) {
		if ( 59 <= (*p) && (*p) <= 126 )
			goto st476;
	} else if ( (*p) >= 33 )
		goto st476;
	goto tr465;
st476:
	if ( ++p == pe )
		goto _test_eof476;
case 476:
	if ( (*p) == 58 )
		goto st477;
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st476;
	goto tr465;
st477:
	if ( ++p == pe )
		goto _test_eof477;
case 477:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st478;
	goto tr465;
st478:
	if ( ++p == pe )
		goto _test_eof478;
case 478:
	if ( (*p) == 91 )
		goto st479;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st478;
	goto tr465;
st479:
	if ( ++p == pe )
		goto _test_eof479;
case 479:
	if ( (*p) == 9 )
		goto tr537;
	goto tr465;
st480:
	if ( ++p == pe )
		goto _test_eof480;
case 480:
	if ( (*p) > 57 ) {
		if ( 59 <= (*p) && (*p) <= 126 )
			goto st481;
	} else if ( (*p) >= 33 )
		goto st481;
	goto tr465;
st481:
	if ( ++p == pe )
		goto _test_eof481;
case 481:
	if ( (*p) == 58 )
		goto st482;
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st481;
	goto tr465;
st482:
	if ( ++p == pe )
		goto _test_eof482;
case 482:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st483;
	goto tr465;
st483:
	if ( ++p == pe )
		goto _test_eof483;
case 483:
	if ( (*p) == 93 )
		goto st479;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st483;
	goto tr465;
tr470:
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st484;
st484:
	if ( ++p == pe )
		goto _test_eof484;
case 484:
#line 7448 "vcf_validator_detail.hpp"
	if ( (*p) > 57 ) {
		if ( 59 <= (*p) && (*p) <= 126 )
			goto st485;
	} else if ( (*p) >= 33 )
		goto st485;
	goto tr465;
st485:
	if ( ++p == pe )
		goto _test_eof485;
case 485:
	if ( (*p) == 58 )
		goto st486;
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st485;
	goto tr465;
st486:
	if ( ++p == pe )
		goto _test_eof486;
case 486:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st487;
	goto tr465;
st487:
	if ( ++p == pe )
		goto _test_eof487;
case 487:
	if ( (*p) == 91 )
		goto st488;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st487;
	goto tr465;
st488:
	if ( ++p == pe )
		goto _test_eof488;
case 488:
	switch( (*p) ) {
		case 65: goto st489;
		case 67: goto st489;
		case 71: goto st489;
		case 78: goto st489;
		case 84: goto st489;
		case 97: goto st489;
		case 99: goto st489;
		case 103: goto st489;
		case 110: goto st489;
		case 116: goto st489;
	}
	goto tr465;
st489:
	if ( ++p == pe )
		goto _test_eof489;
case 489:
	switch( (*p) ) {
		case 9: goto tr537;
		case 65: goto st489;
		case 67: goto st489;
		case 71: goto st489;
		case 78: goto st489;
		case 84: goto st489;
		case 97: goto st489;
		case 99: goto st489;
		case 103: goto st489;
		case 110: goto st489;
		case 116: goto st489;
	}
	goto tr465;
tr471:
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st490;
st490:
	if ( ++p == pe )
		goto _test_eof490;
case 490:
#line 7525 "vcf_validator_detail.hpp"
	if ( (*p) > 57 ) {
		if ( 59 <= (*p) && (*p) <= 126 )
			goto st491;
	} else if ( (*p) >= 33 )
		goto st491;
	goto tr465;
st491:
	if ( ++p == pe )
		goto _test_eof491;
case 491:
	if ( (*p) == 58 )
		goto st492;
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st491;
	goto tr465;
st492:
	if ( ++p == pe )
		goto _test_eof492;
case 492:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st493;
	goto tr465;
st493:
	if ( ++p == pe )
		goto _test_eof493;
case 493:
	if ( (*p) == 93 )
		goto st488;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st493;
	goto tr465;
tr459:
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st494;
st494:
	if ( ++p == pe )
		goto _test_eof494;
case 494:
#line 7567 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr460;
		case 95: goto st494;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st494;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st494;
	} else
		goto st494;
	goto tr457;
st495:
	if ( ++p == pe )
		goto _test_eof495;
case 495:
	if ( (*p) == 10 )
		goto tr551;
	goto st495;
tr551:
#line 20 "vcf_v41.ragel"
	{
        ++n_lines;
        n_columns = 1;
    }
#line 403 "vcf_v41.ragel"
	{ {goto st29;} }
	goto st499;
st499:
	if ( ++p == pe )
		goto _test_eof499;
case 499:
#line 7601 "vcf_validator_detail.hpp"
	goto st0;
st496:
	if ( ++p == pe )
		goto _test_eof496;
case 496:
	if ( (*p) == 10 )
		goto tr553;
	goto st496;
tr553:
#line 20 "vcf_v41.ragel"
	{
        ++n_lines;
        n_columns = 1;
    }
#line 404 "vcf_v41.ragel"
	{ {goto st498;} }
	goto st500;
st500:
	if ( ++p == pe )
		goto _test_eof500;
case 500:
#line 7623 "vcf_validator_detail.hpp"
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
	_test_eof497: cs = 497; goto _test_eof; 
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
	_test_eof498: cs = 498; goto _test_eof; 
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
	_test_eof499: cs = 499; goto _test_eof; 
	_test_eof496: cs = 496; goto _test_eof; 
	_test_eof500: cs = 500; goto _test_eof; 

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
#line 29 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this);
        p--; {goto st495;}
    }
	break;
	case 30: 
	case 38: 
	case 40: 
	case 266: 
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
	case 280: 
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
	case 292: 
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
	case 366: 
	case 367: 
	case 368: 
	case 369: 
	case 370: 
	case 371: 
	case 372: 
	case 373: 
	case 374: 
#line 34 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st495;}
    }
	break;
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
#line 39 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        p--; {goto st496;}
    }
	break;
	case 14: 
	case 15: 
#line 53 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this,
            "Fileformat must be a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st495;}
    }
#line 29 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this);
        p--; {goto st495;}
    }
	break;
	case 421: 
#line 124 "vcf_v41.ragel"
	{
    }
#line 44 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st496;}
    }
	break;
	case 422: 
	case 423: 
#line 133 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Position must be a positive number");
        p--; {goto st496;}
    }
#line 44 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st496;}
    }
	break;
	case 424: 
	case 425: 
	case 494: 
#line 142 "vcf_v41.ragel"
	{
        printf("Line %zu: Error in 'id' field\n", n_lines);
 //       vcf_record_free(status->current_record);
    }
#line 44 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st496;}
    }
	break;
	case 426: 
	case 427: 
#line 151 "vcf_v41.ragel"
	{
        printf("Line %zu: Error in 'reference' field\n", n_lines);
//        vcf_record_free(status->current_record);
    }
#line 44 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st496;}
    }
	break;
	case 428: 
	case 429: 
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
	case 487: 
	case 488: 
	case 489: 
	case 490: 
	case 491: 
	case 492: 
	case 493: 
#line 176 "vcf_v41.ragel"
	{
        printf("Line %zu: Error in 'alternate' field\n", n_lines);
 //       vcf_record_free(status->current_record);
    }
#line 44 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st496;}
    }
	break;
	case 430: 
	case 431: 
	case 446: 
	case 447: 
	case 448: 
#line 191 "vcf_v41.ragel"
	{
        printf("Line %zu: Error in 'quality' field\n", n_lines);
 //       vcf_record_free(status->current_record);
    }
#line 44 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st496;}
    }
	break;
	case 432: 
	case 433: 
	case 445: 
#line 200 "vcf_v41.ragel"
	{
        printf("Line %zu: Error in 'filter' field\n", n_lines);
 //       vcf_record_free(status->current_record);
    }
#line 44 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st496;}
    }
	break;
	case 434: 
	case 435: 
	case 441: 
	case 442: 
	case 443: 
	case 444: 
#line 209 "vcf_v41.ragel"
	{
        printf("Line %zu: Error in 'info' field\n", n_lines);
 //       vcf_record_free(status->current_record);
    }
#line 44 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st496;}
    }
	break;
	case 436: 
	case 437: 
	case 440: 
#line 218 "vcf_v41.ragel"
	{
        printf("Line %zu: Error in 'format' field\n", n_lines);
 //       vcf_record_free(status->current_record);
    }
#line 44 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st496;}
    }
	break;
	case 438: 
	case 439: 
#line 227 "vcf_v41.ragel"
	{
        printf("Line %zu: Error in sample\n", n_lines);
//        vcf_record_free(status->current_record);
    }
#line 44 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st496;}
    }
	break;
	case 39: 
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
#line 257 "vcf_v41.ragel"
	{
        printf("Meta ALT error in line %zu\n", n_lines);
        p--; {goto st495;}
    }
#line 34 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st495;}
    }
	break;
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
#line 262 "vcf_v41.ragel"
	{
        printf("Meta FILTER error in line %zu\n", n_lines);
        p--; {goto st495;}
    }
#line 34 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st495;}
    }
	break;
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
	case 122: 
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
	case 149: 
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
	case 164: 
	case 165: 
	case 166: 
	case 167: 
	case 168: 
#line 267 "vcf_v41.ragel"
	{
        printf("Meta FORMAT error in line %zu\n", n_lines);
        p--; {goto st495;}
    }
#line 34 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st495;}
    }
	break;
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
	case 180: 
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
	case 207: 
	case 208: 
	case 209: 
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
	case 220: 
	case 221: 
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
	case 259: 
	case 260: 
	case 261: 
	case 262: 
	case 263: 
	case 264: 
	case 265: 
#line 272 "vcf_v41.ragel"
	{
        printf("Meta INFO error in line %zu\n", n_lines);
        p--; {goto st495;}
    }
#line 34 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st495;}
    }
	break;
	case 19: 
	case 20: 
	case 21: 
	case 22: 
	case 23: 
	case 24: 
	case 25: 
	case 26: 
	case 27: 
	case 28: 
	case 31: 
	case 32: 
	case 33: 
	case 34: 
	case 35: 
	case 36: 
	case 37: 
#line 277 "vcf_v41.ragel"
	{
        printf("Meta error in line %zu\n", n_lines);
        p--; {goto st495;}
    }
#line 34 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st495;}
    }
	break;
	case 74: 
#line 262 "vcf_v41.ragel"
	{
        printf("Meta FILTER error in line %zu\n", n_lines);
        p--; {goto st495;}
    }
#line 267 "vcf_v41.ragel"
	{
        printf("Meta FORMAT error in line %zu\n", n_lines);
        p--; {goto st495;}
    }
#line 34 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st495;}
    }
	break;
	case 18: 
#line 277 "vcf_v41.ragel"
	{
        printf("Meta error in line %zu\n", n_lines);
        p--; {goto st495;}
    }
#line 257 "vcf_v41.ragel"
	{
        printf("Meta ALT error in line %zu\n", n_lines);
        p--; {goto st495;}
    }
#line 262 "vcf_v41.ragel"
	{
        printf("Meta FILTER error in line %zu\n", n_lines);
        p--; {goto st495;}
    }
#line 267 "vcf_v41.ragel"
	{
        printf("Meta FORMAT error in line %zu\n", n_lines);
        p--; {goto st495;}
    }
#line 272 "vcf_v41.ragel"
	{
        printf("Meta INFO error in line %zu\n", n_lines);
        p--; {goto st495;}
    }
#line 34 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st495;}
    }
	break;
	case 17: 
	case 29: 
#line 277 "vcf_v41.ragel"
	{
        printf("Meta error in line %zu\n", n_lines);
        p--; {goto st495;}
    }
#line 257 "vcf_v41.ragel"
	{
        printf("Meta ALT error in line %zu\n", n_lines);
        p--; {goto st495;}
    }
#line 262 "vcf_v41.ragel"
	{
        printf("Meta FILTER error in line %zu\n", n_lines);
        p--; {goto st495;}
    }
#line 267 "vcf_v41.ragel"
	{
        printf("Meta FORMAT error in line %zu\n", n_lines);
        p--; {goto st495;}
    }
#line 272 "vcf_v41.ragel"
	{
        printf("Meta INFO error in line %zu\n", n_lines);
        p--; {goto st495;}
    }
#line 34 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st495;}
    }
#line 39 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        p--; {goto st496;}
    }
	break;
	case 16: 
#line 29 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this);
        p--; {goto st495;}
    }
#line 277 "vcf_v41.ragel"
	{
        printf("Meta error in line %zu\n", n_lines);
        p--; {goto st495;}
    }
#line 257 "vcf_v41.ragel"
	{
        printf("Meta ALT error in line %zu\n", n_lines);
        p--; {goto st495;}
    }
#line 262 "vcf_v41.ragel"
	{
        printf("Meta FILTER error in line %zu\n", n_lines);
        p--; {goto st495;}
    }
#line 267 "vcf_v41.ragel"
	{
        printf("Meta FORMAT error in line %zu\n", n_lines);
        p--; {goto st495;}
    }
#line 272 "vcf_v41.ragel"
	{
        printf("Meta INFO error in line %zu\n", n_lines);
        p--; {goto st495;}
    }
#line 34 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st495;}
    }
#line 39 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        p--; {goto st496;}
    }
	break;
#line 8941 "vcf_validator_detail.hpp"
	}
	}

	_out: {}
	}

#line 467 "vcf_v41.ragel"

    }

  }
}
