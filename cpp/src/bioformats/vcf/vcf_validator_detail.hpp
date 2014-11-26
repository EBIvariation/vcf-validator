
#line 1 "vcf_v41.ragel"
#include <cstdio>

#include "vcf_validator.hpp"


#line 361 "vcf_v41.ragel"


namespace
{
  
#line 15 "vcf_validator_detail.hpp"
static const int vcf_start = 1;
static const int vcf_first_final = 465;
static const int vcf_error = 0;

static const int vcf_en_main = 1;
static const int vcf_en_main_meta_section = 20;
static const int vcf_en_main_body_section = 466;
static const int vcf_en_meta_section_skip = 463;
static const int vcf_en_body_section_skip = 464;


#line 367 "vcf_v41.ragel"

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

#line 379 "vcf_v41.ragel"

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
465
#line 412 "vcf_v41.ragel"
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
        p--; {goto st463;}
    }
	goto st0;
tr14:
#line 53 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this,
            "Fileformat must be a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st463;}
    }
#line 29 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this);
        p--; {goto st463;}
    }
	goto st0;
tr18:
#line 29 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this);
        p--; {goto st463;}
    }
#line 34 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st463;}
    }
#line 39 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        p--; {goto st464;}
    }
	goto st0;
tr20:
#line 34 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st463;}
    }
#line 39 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        p--; {goto st464;}
    }
	goto st0;
tr23:
#line 34 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st463;}
    }
	goto st0;
tr357:
#line 39 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        p--; {goto st464;}
    }
	goto st0;
tr407:
#line 124 "vcf_v41.ragel"
	{
    }
#line 44 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st464;}
    }
	goto st0;
tr410:
#line 133 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Position must be a positive number");
        p--; {goto st464;}
    }
#line 44 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st464;}
    }
	goto st0;
tr414:
#line 142 "vcf_v41.ragel"
	{
        printf("Line %zu: Error in 'id' field\n", n_lines);
 //       vcf_record_free(status->current_record);
    }
#line 44 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st464;}
    }
	goto st0;
tr418:
#line 151 "vcf_v41.ragel"
	{
        printf("Line %zu: Error in 'reference' field\n", n_lines);
//        vcf_record_free(status->current_record);
    }
#line 44 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st464;}
    }
	goto st0;
tr422:
#line 176 "vcf_v41.ragel"
	{
        printf("Line %zu: Error in 'alternate' field\n", n_lines);
 //       vcf_record_free(status->current_record);
    }
#line 44 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st464;}
    }
	goto st0;
tr432:
#line 191 "vcf_v41.ragel"
	{
        printf("Line %zu: Error in 'quality' field\n", n_lines);
 //       vcf_record_free(status->current_record);
    }
#line 44 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st464;}
    }
	goto st0;
tr436:
#line 200 "vcf_v41.ragel"
	{
        printf("Line %zu: Error in 'filter' field\n", n_lines);
 //       vcf_record_free(status->current_record);
    }
#line 44 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st464;}
    }
	goto st0;
tr441:
#line 209 "vcf_v41.ragel"
	{
        printf("Line %zu: Error in 'info' field\n", n_lines);
 //       vcf_record_free(status->current_record);
    }
#line 44 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st464;}
    }
	goto st0;
tr448:
#line 218 "vcf_v41.ragel"
	{
        printf("Line %zu: Error in 'format' field\n", n_lines);
 //       vcf_record_free(status->current_record);
    }
#line 44 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st464;}
    }
	goto st0;
tr453:
#line 227 "vcf_v41.ragel"
	{
        printf("Line %zu: Error in sample\n", n_lines);
//        vcf_record_free(status->current_record);
    }
#line 44 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st464;}
    }
	goto st0;
tr511:
#line 39 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        p--; {goto st464;}
    }
#line 124 "vcf_v41.ragel"
	{
    }
#line 44 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st464;}
    }
	goto st0;
#line 298 "vcf_validator_detail.hpp"
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
#line 403 "vcf_validator_detail.hpp"
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
#line 424 "vcf_validator_detail.hpp"
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
#line 439 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 35: goto st18;
		case 67: goto st343;
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
			} else if ( (*p) >= 97 )
				goto tr25;
		} else
			goto tr24;
	} else
		goto tr24;
	goto tr23;
tr24:
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st19;
st19:
	if ( ++p == pe )
		goto _test_eof19;
case 19:
#line 488 "vcf_validator_detail.hpp"
	if ( (*p) == 10 )
		goto tr29;
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st19;
	} else if ( (*p) >= 32 )
		goto st19;
	goto tr23;
tr29:
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
	goto st20;
tr42:
#line 64 "vcf_v41.ragel"
	{
//        add_vcf_meta_entry(status->current_meta_entry, file);
    }
#line 20 "vcf_v41.ragel"
	{
        ++n_lines;
        n_columns = 1;
    }
	goto st20;
st20:
	if ( ++p == pe )
		goto _test_eof20;
case 20:
#line 533 "vcf_validator_detail.hpp"
	if ( (*p) == 35 )
		goto tr19;
	goto tr20;
tr25:
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st21;
st21:
	if ( ++p == pe )
		goto _test_eof21;
case 21:
#line 547 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr29;
		case 61: goto tr32;
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
	goto tr23;
tr32:
#line 68 "vcf_v41.ragel"
	{
//        set_vcf_meta_entry_name(ts, p-ts, status->current_meta_entry);
    }
#line 252 "vcf_v41.ragel"
	{
        printf("Meta in line %zu\n", n_lines);
    }
	goto st22;
st22:
	if ( ++p == pe )
		goto _test_eof22;
case 22:
#line 587 "vcf_validator_detail.hpp"
	if ( (*p) == 60 )
		goto st23;
	if ( (*p) > 59 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st19;
	} else if ( (*p) >= 32 )
		goto st19;
	goto tr23;
st23:
	if ( ++p == pe )
		goto _test_eof23;
case 23:
	if ( (*p) == 10 )
		goto tr29;
	if ( (*p) < 62 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 60 )
				goto st19;
		} else
			goto tr34;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr34;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto st19;
			} else if ( (*p) >= 97 )
				goto tr34;
		} else
			goto st19;
	} else
		goto st19;
	goto tr23;
tr34:
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st24;
tr47:
#line 236 "vcf_v41.ragel"
	{
        printf("Meta ALT in line %zu\n", n_lines);
    }
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st24;
st24:
	if ( ++p == pe )
		goto _test_eof24;
case 24:
#line 646 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr29;
		case 61: goto st25;
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
	goto tr23;
st25:
	if ( ++p == pe )
		goto _test_eof25;
case 25:
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st26;
	} else if ( (*p) >= 32 )
		goto st26;
	goto tr23;
st26:
	if ( ++p == pe )
		goto _test_eof26;
case 26:
	switch( (*p) ) {
		case 44: goto tr38;
		case 62: goto tr39;
	}
	if ( (*p) > 60 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto st26;
	} else if ( (*p) >= 32 )
		goto st26;
	goto tr23;
tr38:
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
	goto st27;
st27:
	if ( ++p == pe )
		goto _test_eof27;
case 27:
#line 712 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto tr38;
		case 62: goto tr39;
	}
	if ( (*p) < 63 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st26;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 60 )
				goto st26;
		} else
			goto tr40;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr40;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto st26;
			} else if ( (*p) >= 97 )
				goto tr40;
		} else
			goto st26;
	} else
		goto st26;
	goto tr23;
tr40:
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st28;
st28:
	if ( ++p == pe )
		goto _test_eof28;
case 28:
#line 751 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto tr38;
		case 61: goto st25;
		case 62: goto tr39;
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
	goto tr23;
tr39:
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
	goto st29;
st29:
	if ( ++p == pe )
		goto _test_eof29;
case 29:
#line 794 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr42;
		case 44: goto tr38;
		case 62: goto tr39;
	}
	if ( (*p) > 60 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto st26;
	} else if ( (*p) >= 32 )
		goto st26;
	goto tr23;
tr26:
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st30;
st30:
	if ( ++p == pe )
		goto _test_eof30;
case 30:
#line 816 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr29;
		case 61: goto tr32;
		case 76: goto st31;
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
	goto tr23;
st31:
	if ( ++p == pe )
		goto _test_eof31;
case 31:
	switch( (*p) ) {
		case 10: goto tr29;
		case 61: goto tr32;
		case 84: goto st32;
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
	goto tr23;
st32:
	if ( ++p == pe )
		goto _test_eof32;
case 32:
	switch( (*p) ) {
		case 10: goto tr29;
		case 61: goto tr45;
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
	goto tr23;
tr45:
#line 68 "vcf_v41.ragel"
	{
//        set_vcf_meta_entry_name(ts, p-ts, status->current_meta_entry);
    }
#line 252 "vcf_v41.ragel"
	{
        printf("Meta in line %zu\n", n_lines);
    }
	goto st33;
st33:
	if ( ++p == pe )
		goto _test_eof33;
case 33:
#line 916 "vcf_validator_detail.hpp"
	if ( (*p) == 60 )
		goto st34;
	if ( (*p) > 59 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st19;
	} else if ( (*p) >= 32 )
		goto st19;
	goto tr23;
st34:
	if ( ++p == pe )
		goto _test_eof34;
case 34:
	switch( (*p) ) {
		case 10: goto tr29;
		case 73: goto tr47;
	}
	if ( (*p) < 62 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 60 )
				goto st19;
		} else
			goto tr34;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr34;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto st19;
			} else if ( (*p) >= 97 )
				goto tr34;
		} else
			goto st19;
	} else
		goto st19;
	goto tr23;
tr27:
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st35;
st35:
	if ( ++p == pe )
		goto _test_eof35;
case 35:
#line 967 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr29;
		case 61: goto tr32;
		case 73: goto st36;
		case 79: goto st96;
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
	goto tr23;
st36:
	if ( ++p == pe )
		goto _test_eof36;
case 36:
	switch( (*p) ) {
		case 10: goto tr29;
		case 61: goto tr32;
		case 76: goto st37;
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
	goto tr23;
st37:
	if ( ++p == pe )
		goto _test_eof37;
case 37:
	switch( (*p) ) {
		case 10: goto tr29;
		case 61: goto tr32;
		case 84: goto st38;
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
	goto tr23;
st38:
	if ( ++p == pe )
		goto _test_eof38;
case 38:
	switch( (*p) ) {
		case 10: goto tr29;
		case 61: goto tr32;
		case 69: goto st39;
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
	goto tr23;
st39:
	if ( ++p == pe )
		goto _test_eof39;
case 39:
	switch( (*p) ) {
		case 10: goto tr29;
		case 61: goto tr32;
		case 82: goto st40;
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
	goto tr23;
st40:
	if ( ++p == pe )
		goto _test_eof40;
case 40:
	switch( (*p) ) {
		case 10: goto tr29;
		case 61: goto tr54;
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
	goto tr23;
tr54:
#line 68 "vcf_v41.ragel"
	{
//        set_vcf_meta_entry_name(ts, p-ts, status->current_meta_entry);
    }
#line 252 "vcf_v41.ragel"
	{
        printf("Meta in line %zu\n", n_lines);
    }
	goto st41;
st41:
	if ( ++p == pe )
		goto _test_eof41;
case 41:
#line 1158 "vcf_validator_detail.hpp"
	if ( (*p) == 60 )
		goto st42;
	if ( (*p) > 59 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st19;
	} else if ( (*p) >= 32 )
		goto st19;
	goto tr23;
st42:
	if ( ++p == pe )
		goto _test_eof42;
case 42:
	switch( (*p) ) {
		case 10: goto tr29;
		case 73: goto tr56;
	}
	if ( (*p) < 62 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 60 )
				goto st19;
		} else
			goto tr34;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr34;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto st19;
			} else if ( (*p) >= 97 )
				goto tr34;
		} else
			goto st19;
	} else
		goto st19;
	goto tr23;
tr56:
#line 240 "vcf_v41.ragel"
	{
        printf("Meta FILTER in line %zu\n", n_lines);
    }
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st43;
st43:
	if ( ++p == pe )
		goto _test_eof43;
case 43:
#line 1213 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr29;
		case 61: goto st25;
		case 68: goto st44;
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
	goto tr23;
st44:
	if ( ++p == pe )
		goto _test_eof44;
case 44:
	switch( (*p) ) {
		case 10: goto tr29;
		case 61: goto st45;
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
	goto tr23;
st45:
	if ( ++p == pe )
		goto _test_eof45;
case 45:
	switch( (*p) ) {
		case 32: goto st26;
		case 61: goto st51;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st46;
	goto tr23;
st46:
	if ( ++p == pe )
		goto _test_eof46;
case 46:
	switch( (*p) ) {
		case 32: goto st26;
		case 44: goto tr61;
		case 61: goto st51;
		case 62: goto tr62;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st46;
	goto tr23;
tr61:
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
	goto st47;
st47:
	if ( ++p == pe )
		goto _test_eof47;
case 47:
#line 1309 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 32: goto st26;
		case 44: goto tr61;
		case 61: goto st51;
		case 62: goto tr62;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto st46;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st46;
		} else
			goto tr63;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st46;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st46;
		} else
			goto tr63;
	} else
		goto tr63;
	goto tr23;
tr63:
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st48;
st48:
	if ( ++p == pe )
		goto _test_eof48;
case 48:
#line 1347 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 32: goto st26;
		case 44: goto tr61;
		case 61: goto st49;
		case 62: goto tr62;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto st46;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st46;
		} else
			goto st48;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st46;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st46;
		} else
			goto st48;
	} else
		goto st48;
	goto tr23;
st49:
	if ( ++p == pe )
		goto _test_eof49;
case 49:
	switch( (*p) ) {
		case 32: goto st26;
		case 44: goto st50;
		case 61: goto st51;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st46;
	goto tr23;
st50:
	if ( ++p == pe )
		goto _test_eof50;
case 50:
	switch( (*p) ) {
		case 32: goto st26;
		case 44: goto tr61;
		case 61: goto st51;
		case 62: goto tr62;
		case 68: goto st85;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st46;
	goto tr23;
st51:
	if ( ++p == pe )
		goto _test_eof51;
case 51:
	if ( (*p) == 44 )
		goto st52;
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st51;
	goto tr23;
st52:
	if ( ++p == pe )
		goto _test_eof52;
case 52:
	switch( (*p) ) {
		case 44: goto st52;
		case 68: goto st53;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st51;
	goto tr23;
st53:
	if ( ++p == pe )
		goto _test_eof53;
case 53:
	switch( (*p) ) {
		case 44: goto st52;
		case 101: goto st54;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st51;
	goto tr23;
st54:
	if ( ++p == pe )
		goto _test_eof54;
case 54:
	switch( (*p) ) {
		case 44: goto st52;
		case 115: goto st55;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st51;
	goto tr23;
st55:
	if ( ++p == pe )
		goto _test_eof55;
case 55:
	switch( (*p) ) {
		case 44: goto st52;
		case 99: goto st56;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st51;
	goto tr23;
st56:
	if ( ++p == pe )
		goto _test_eof56;
case 56:
	switch( (*p) ) {
		case 44: goto st52;
		case 114: goto st57;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st51;
	goto tr23;
st57:
	if ( ++p == pe )
		goto _test_eof57;
case 57:
	switch( (*p) ) {
		case 44: goto st52;
		case 105: goto st58;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st51;
	goto tr23;
st58:
	if ( ++p == pe )
		goto _test_eof58;
case 58:
	switch( (*p) ) {
		case 44: goto st52;
		case 112: goto st59;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st51;
	goto tr23;
st59:
	if ( ++p == pe )
		goto _test_eof59;
case 59:
	switch( (*p) ) {
		case 44: goto st52;
		case 116: goto st60;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st51;
	goto tr23;
st60:
	if ( ++p == pe )
		goto _test_eof60;
case 60:
	switch( (*p) ) {
		case 44: goto st52;
		case 105: goto st61;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st51;
	goto tr23;
st61:
	if ( ++p == pe )
		goto _test_eof61;
case 61:
	switch( (*p) ) {
		case 44: goto st52;
		case 111: goto st62;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st51;
	goto tr23;
st62:
	if ( ++p == pe )
		goto _test_eof62;
case 62:
	switch( (*p) ) {
		case 44: goto st52;
		case 110: goto st63;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st51;
	goto tr23;
st63:
	if ( ++p == pe )
		goto _test_eof63;
case 63:
	switch( (*p) ) {
		case 44: goto st52;
		case 61: goto st64;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st51;
	goto tr23;
st64:
	if ( ++p == pe )
		goto _test_eof64;
case 64:
	switch( (*p) ) {
		case 34: goto st65;
		case 44: goto st52;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st51;
	goto tr23;
st65:
	if ( ++p == pe )
		goto _test_eof65;
case 65:
	switch( (*p) ) {
		case 32: goto st66;
		case 44: goto st71;
		case 61: goto st51;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st69;
	goto tr23;
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
	goto tr23;
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
	goto tr23;
st68:
	if ( ++p == pe )
		goto _test_eof68;
case 68:
	switch( (*p) ) {
		case 10: goto tr42;
		case 34: goto st67;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st66;
	} else if ( (*p) >= 32 )
		goto st66;
	goto tr23;
st69:
	if ( ++p == pe )
		goto _test_eof69;
case 69:
	switch( (*p) ) {
		case 32: goto st66;
		case 34: goto st70;
		case 44: goto st71;
		case 61: goto st51;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st69;
	goto tr23;
st70:
	if ( ++p == pe )
		goto _test_eof70;
case 70:
	switch( (*p) ) {
		case 32: goto st66;
		case 34: goto st70;
		case 44: goto st71;
		case 61: goto st51;
		case 62: goto st83;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st69;
	goto tr23;
st71:
	if ( ++p == pe )
		goto _test_eof71;
case 71:
	switch( (*p) ) {
		case 32: goto st66;
		case 34: goto st70;
		case 44: goto st71;
		case 61: goto st51;
		case 68: goto st72;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st69;
	goto tr23;
st72:
	if ( ++p == pe )
		goto _test_eof72;
case 72:
	switch( (*p) ) {
		case 32: goto st66;
		case 34: goto st70;
		case 44: goto st71;
		case 61: goto st51;
		case 101: goto st73;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st69;
	goto tr23;
st73:
	if ( ++p == pe )
		goto _test_eof73;
case 73:
	switch( (*p) ) {
		case 32: goto st66;
		case 34: goto st70;
		case 44: goto st71;
		case 61: goto st51;
		case 115: goto st74;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st69;
	goto tr23;
st74:
	if ( ++p == pe )
		goto _test_eof74;
case 74:
	switch( (*p) ) {
		case 32: goto st66;
		case 34: goto st70;
		case 44: goto st71;
		case 61: goto st51;
		case 99: goto st75;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st69;
	goto tr23;
st75:
	if ( ++p == pe )
		goto _test_eof75;
case 75:
	switch( (*p) ) {
		case 32: goto st66;
		case 34: goto st70;
		case 44: goto st71;
		case 61: goto st51;
		case 114: goto st76;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st69;
	goto tr23;
st76:
	if ( ++p == pe )
		goto _test_eof76;
case 76:
	switch( (*p) ) {
		case 32: goto st66;
		case 34: goto st70;
		case 44: goto st71;
		case 61: goto st51;
		case 105: goto st77;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st69;
	goto tr23;
st77:
	if ( ++p == pe )
		goto _test_eof77;
case 77:
	switch( (*p) ) {
		case 32: goto st66;
		case 34: goto st70;
		case 44: goto st71;
		case 61: goto st51;
		case 112: goto st78;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st69;
	goto tr23;
st78:
	if ( ++p == pe )
		goto _test_eof78;
case 78:
	switch( (*p) ) {
		case 32: goto st66;
		case 34: goto st70;
		case 44: goto st71;
		case 61: goto st51;
		case 116: goto st79;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st69;
	goto tr23;
st79:
	if ( ++p == pe )
		goto _test_eof79;
case 79:
	switch( (*p) ) {
		case 32: goto st66;
		case 34: goto st70;
		case 44: goto st71;
		case 61: goto st51;
		case 105: goto st80;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st69;
	goto tr23;
st80:
	if ( ++p == pe )
		goto _test_eof80;
case 80:
	switch( (*p) ) {
		case 32: goto st66;
		case 34: goto st70;
		case 44: goto st71;
		case 61: goto st51;
		case 111: goto st81;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st69;
	goto tr23;
st81:
	if ( ++p == pe )
		goto _test_eof81;
case 81:
	switch( (*p) ) {
		case 32: goto st66;
		case 34: goto st70;
		case 44: goto st71;
		case 61: goto st51;
		case 110: goto st82;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st69;
	goto tr23;
st82:
	if ( ++p == pe )
		goto _test_eof82;
case 82:
	switch( (*p) ) {
		case 32: goto st66;
		case 34: goto st70;
		case 44: goto st71;
		case 61: goto st64;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st69;
	goto tr23;
st83:
	if ( ++p == pe )
		goto _test_eof83;
case 83:
	switch( (*p) ) {
		case 10: goto tr42;
		case 32: goto st66;
		case 34: goto st70;
		case 44: goto st71;
		case 61: goto st51;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st69;
	goto tr23;
tr62:
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
	goto st84;
st84:
	if ( ++p == pe )
		goto _test_eof84;
case 84:
#line 1829 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr42;
		case 32: goto st26;
		case 44: goto tr61;
		case 61: goto st51;
		case 62: goto tr62;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st46;
	goto tr23;
st85:
	if ( ++p == pe )
		goto _test_eof85;
case 85:
	switch( (*p) ) {
		case 32: goto st26;
		case 44: goto tr61;
		case 61: goto st51;
		case 62: goto tr62;
		case 101: goto st86;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st46;
	goto tr23;
st86:
	if ( ++p == pe )
		goto _test_eof86;
case 86:
	switch( (*p) ) {
		case 32: goto st26;
		case 44: goto tr61;
		case 61: goto st51;
		case 62: goto tr62;
		case 115: goto st87;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st46;
	goto tr23;
st87:
	if ( ++p == pe )
		goto _test_eof87;
case 87:
	switch( (*p) ) {
		case 32: goto st26;
		case 44: goto tr61;
		case 61: goto st51;
		case 62: goto tr62;
		case 99: goto st88;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st46;
	goto tr23;
st88:
	if ( ++p == pe )
		goto _test_eof88;
case 88:
	switch( (*p) ) {
		case 32: goto st26;
		case 44: goto tr61;
		case 61: goto st51;
		case 62: goto tr62;
		case 114: goto st89;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st46;
	goto tr23;
st89:
	if ( ++p == pe )
		goto _test_eof89;
case 89:
	switch( (*p) ) {
		case 32: goto st26;
		case 44: goto tr61;
		case 61: goto st51;
		case 62: goto tr62;
		case 105: goto st90;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st46;
	goto tr23;
st90:
	if ( ++p == pe )
		goto _test_eof90;
case 90:
	switch( (*p) ) {
		case 32: goto st26;
		case 44: goto tr61;
		case 61: goto st51;
		case 62: goto tr62;
		case 112: goto st91;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st46;
	goto tr23;
st91:
	if ( ++p == pe )
		goto _test_eof91;
case 91:
	switch( (*p) ) {
		case 32: goto st26;
		case 44: goto tr61;
		case 61: goto st51;
		case 62: goto tr62;
		case 116: goto st92;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st46;
	goto tr23;
st92:
	if ( ++p == pe )
		goto _test_eof92;
case 92:
	switch( (*p) ) {
		case 32: goto st26;
		case 44: goto tr61;
		case 61: goto st51;
		case 62: goto tr62;
		case 105: goto st93;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st46;
	goto tr23;
st93:
	if ( ++p == pe )
		goto _test_eof93;
case 93:
	switch( (*p) ) {
		case 32: goto st26;
		case 44: goto tr61;
		case 61: goto st51;
		case 62: goto tr62;
		case 111: goto st94;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st46;
	goto tr23;
st94:
	if ( ++p == pe )
		goto _test_eof94;
case 94:
	switch( (*p) ) {
		case 32: goto st26;
		case 44: goto tr61;
		case 61: goto st51;
		case 62: goto tr62;
		case 110: goto st95;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st46;
	goto tr23;
st95:
	if ( ++p == pe )
		goto _test_eof95;
case 95:
	switch( (*p) ) {
		case 32: goto st26;
		case 44: goto tr61;
		case 61: goto st64;
		case 62: goto tr62;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st46;
	goto tr23;
st96:
	if ( ++p == pe )
		goto _test_eof96;
case 96:
	switch( (*p) ) {
		case 10: goto tr29;
		case 61: goto tr32;
		case 82: goto st97;
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
	goto tr23;
st97:
	if ( ++p == pe )
		goto _test_eof97;
case 97:
	switch( (*p) ) {
		case 10: goto tr29;
		case 61: goto tr32;
		case 77: goto st98;
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
	goto tr23;
st98:
	if ( ++p == pe )
		goto _test_eof98;
case 98:
	switch( (*p) ) {
		case 10: goto tr29;
		case 61: goto tr32;
		case 65: goto st99;
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
	goto tr23;
st99:
	if ( ++p == pe )
		goto _test_eof99;
case 99:
	switch( (*p) ) {
		case 10: goto tr29;
		case 61: goto tr32;
		case 84: goto st100;
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
	goto tr23;
st100:
	if ( ++p == pe )
		goto _test_eof100;
case 100:
	switch( (*p) ) {
		case 10: goto tr29;
		case 61: goto tr114;
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
	goto tr23;
tr114:
#line 68 "vcf_v41.ragel"
	{
//        set_vcf_meta_entry_name(ts, p-ts, status->current_meta_entry);
    }
#line 252 "vcf_v41.ragel"
	{
        printf("Meta in line %zu\n", n_lines);
    }
	goto st101;
st101:
	if ( ++p == pe )
		goto _test_eof101;
case 101:
#line 2156 "vcf_validator_detail.hpp"
	if ( (*p) == 60 )
		goto st102;
	if ( (*p) > 59 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st19;
	} else if ( (*p) >= 32 )
		goto st19;
	goto tr23;
st102:
	if ( ++p == pe )
		goto _test_eof102;
case 102:
	switch( (*p) ) {
		case 10: goto tr29;
		case 73: goto tr116;
	}
	if ( (*p) < 62 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 60 )
				goto st19;
		} else
			goto tr34;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr34;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto st19;
			} else if ( (*p) >= 97 )
				goto tr34;
		} else
			goto st19;
	} else
		goto st19;
	goto tr23;
tr116:
#line 244 "vcf_v41.ragel"
	{
        printf("Meta FORMAT in line %zu\n", n_lines);
    }
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st103;
st103:
	if ( ++p == pe )
		goto _test_eof103;
case 103:
#line 2211 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr29;
		case 61: goto st25;
		case 68: goto st104;
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
	goto tr23;
st104:
	if ( ++p == pe )
		goto _test_eof104;
case 104:
	switch( (*p) ) {
		case 10: goto tr29;
		case 61: goto st105;
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
	goto tr23;
st105:
	if ( ++p == pe )
		goto _test_eof105;
case 105:
	switch( (*p) ) {
		case 32: goto st26;
		case 61: goto st111;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st106;
	goto tr23;
st106:
	if ( ++p == pe )
		goto _test_eof106;
case 106:
	switch( (*p) ) {
		case 32: goto st26;
		case 44: goto tr121;
		case 61: goto st111;
		case 62: goto tr122;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st106;
	goto tr23;
tr121:
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
	goto st107;
st107:
	if ( ++p == pe )
		goto _test_eof107;
case 107:
#line 2307 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 32: goto st26;
		case 44: goto tr121;
		case 61: goto st111;
		case 62: goto tr122;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto st106;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st106;
		} else
			goto tr123;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st106;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st106;
		} else
			goto tr123;
	} else
		goto tr123;
	goto tr23;
tr123:
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st108;
st108:
	if ( ++p == pe )
		goto _test_eof108;
case 108:
#line 2345 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 32: goto st26;
		case 44: goto tr121;
		case 61: goto st109;
		case 62: goto tr122;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto st106;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st106;
		} else
			goto st108;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st106;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st106;
		} else
			goto st108;
	} else
		goto st108;
	goto tr23;
st109:
	if ( ++p == pe )
		goto _test_eof109;
case 109:
	switch( (*p) ) {
		case 32: goto st26;
		case 44: goto st110;
		case 61: goto st111;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st106;
	goto tr23;
st110:
	if ( ++p == pe )
		goto _test_eof110;
case 110:
	switch( (*p) ) {
		case 32: goto st26;
		case 44: goto tr121;
		case 61: goto st111;
		case 62: goto tr122;
		case 78: goto st175;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st106;
	goto tr23;
st111:
	if ( ++p == pe )
		goto _test_eof111;
case 111:
	if ( (*p) == 44 )
		goto st112;
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st111;
	goto tr23;
st112:
	if ( ++p == pe )
		goto _test_eof112;
case 112:
	switch( (*p) ) {
		case 44: goto st112;
		case 78: goto st113;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st111;
	goto tr23;
st113:
	if ( ++p == pe )
		goto _test_eof113;
case 113:
	switch( (*p) ) {
		case 44: goto st112;
		case 117: goto st114;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st111;
	goto tr23;
st114:
	if ( ++p == pe )
		goto _test_eof114;
case 114:
	switch( (*p) ) {
		case 44: goto st112;
		case 109: goto st115;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st111;
	goto tr23;
st115:
	if ( ++p == pe )
		goto _test_eof115;
case 115:
	switch( (*p) ) {
		case 44: goto st112;
		case 98: goto st116;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st111;
	goto tr23;
st116:
	if ( ++p == pe )
		goto _test_eof116;
case 116:
	switch( (*p) ) {
		case 44: goto st112;
		case 101: goto st117;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st111;
	goto tr23;
st117:
	if ( ++p == pe )
		goto _test_eof117;
case 117:
	switch( (*p) ) {
		case 44: goto st112;
		case 114: goto st118;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st111;
	goto tr23;
st118:
	if ( ++p == pe )
		goto _test_eof118;
case 118:
	switch( (*p) ) {
		case 44: goto st112;
		case 61: goto st119;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st111;
	goto tr23;
st119:
	if ( ++p == pe )
		goto _test_eof119;
case 119:
	switch( (*p) ) {
		case 44: goto st112;
		case 46: goto st120;
		case 65: goto st120;
		case 71: goto st120;
		case 82: goto st120;
	}
	if ( (*p) < 48 ) {
		if ( 33 <= (*p) && (*p) <= 47 )
			goto st111;
	} else if ( (*p) > 57 ) {
		if ( 58 <= (*p) && (*p) <= 126 )
			goto st111;
	} else
		goto st173;
	goto tr23;
st120:
	if ( ++p == pe )
		goto _test_eof120;
case 120:
	if ( (*p) == 44 )
		goto st121;
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st111;
	goto tr23;
st121:
	if ( ++p == pe )
		goto _test_eof121;
case 121:
	switch( (*p) ) {
		case 44: goto st112;
		case 78: goto st113;
		case 84: goto st122;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st111;
	goto tr23;
st122:
	if ( ++p == pe )
		goto _test_eof122;
case 122:
	switch( (*p) ) {
		case 44: goto st112;
		case 121: goto st123;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st111;
	goto tr23;
st123:
	if ( ++p == pe )
		goto _test_eof123;
case 123:
	switch( (*p) ) {
		case 44: goto st112;
		case 112: goto st124;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st111;
	goto tr23;
st124:
	if ( ++p == pe )
		goto _test_eof124;
case 124:
	switch( (*p) ) {
		case 44: goto st112;
		case 101: goto st125;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st111;
	goto tr23;
st125:
	if ( ++p == pe )
		goto _test_eof125;
case 125:
	switch( (*p) ) {
		case 44: goto st112;
		case 61: goto st126;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st111;
	goto tr23;
st126:
	if ( ++p == pe )
		goto _test_eof126;
case 126:
	switch( (*p) ) {
		case 44: goto st112;
		case 67: goto st127;
		case 70: goto st160;
		case 73: goto st164;
		case 83: goto st168;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st111;
	goto tr23;
st127:
	if ( ++p == pe )
		goto _test_eof127;
case 127:
	switch( (*p) ) {
		case 44: goto st112;
		case 104: goto st128;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st111;
	goto tr23;
st128:
	if ( ++p == pe )
		goto _test_eof128;
case 128:
	switch( (*p) ) {
		case 44: goto st112;
		case 97: goto st129;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st111;
	goto tr23;
st129:
	if ( ++p == pe )
		goto _test_eof129;
case 129:
	switch( (*p) ) {
		case 44: goto st112;
		case 114: goto st130;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st111;
	goto tr23;
st130:
	if ( ++p == pe )
		goto _test_eof130;
case 130:
	switch( (*p) ) {
		case 44: goto st112;
		case 97: goto st131;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st111;
	goto tr23;
st131:
	if ( ++p == pe )
		goto _test_eof131;
case 131:
	switch( (*p) ) {
		case 44: goto st112;
		case 99: goto st132;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st111;
	goto tr23;
st132:
	if ( ++p == pe )
		goto _test_eof132;
case 132:
	switch( (*p) ) {
		case 44: goto st112;
		case 116: goto st133;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st111;
	goto tr23;
st133:
	if ( ++p == pe )
		goto _test_eof133;
case 133:
	switch( (*p) ) {
		case 44: goto st112;
		case 101: goto st134;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st111;
	goto tr23;
st134:
	if ( ++p == pe )
		goto _test_eof134;
case 134:
	switch( (*p) ) {
		case 44: goto st112;
		case 114: goto st135;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st111;
	goto tr23;
st135:
	if ( ++p == pe )
		goto _test_eof135;
case 135:
	if ( (*p) == 44 )
		goto st136;
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st111;
	goto tr23;
st136:
	if ( ++p == pe )
		goto _test_eof136;
case 136:
	switch( (*p) ) {
		case 44: goto st112;
		case 68: goto st137;
		case 78: goto st113;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st111;
	goto tr23;
st137:
	if ( ++p == pe )
		goto _test_eof137;
case 137:
	switch( (*p) ) {
		case 44: goto st112;
		case 101: goto st138;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st111;
	goto tr23;
st138:
	if ( ++p == pe )
		goto _test_eof138;
case 138:
	switch( (*p) ) {
		case 44: goto st112;
		case 115: goto st139;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st111;
	goto tr23;
st139:
	if ( ++p == pe )
		goto _test_eof139;
case 139:
	switch( (*p) ) {
		case 44: goto st112;
		case 99: goto st140;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st111;
	goto tr23;
st140:
	if ( ++p == pe )
		goto _test_eof140;
case 140:
	switch( (*p) ) {
		case 44: goto st112;
		case 114: goto st141;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st111;
	goto tr23;
st141:
	if ( ++p == pe )
		goto _test_eof141;
case 141:
	switch( (*p) ) {
		case 44: goto st112;
		case 105: goto st142;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st111;
	goto tr23;
st142:
	if ( ++p == pe )
		goto _test_eof142;
case 142:
	switch( (*p) ) {
		case 44: goto st112;
		case 112: goto st143;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st111;
	goto tr23;
st143:
	if ( ++p == pe )
		goto _test_eof143;
case 143:
	switch( (*p) ) {
		case 44: goto st112;
		case 116: goto st144;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st111;
	goto tr23;
st144:
	if ( ++p == pe )
		goto _test_eof144;
case 144:
	switch( (*p) ) {
		case 44: goto st112;
		case 105: goto st145;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st111;
	goto tr23;
st145:
	if ( ++p == pe )
		goto _test_eof145;
case 145:
	switch( (*p) ) {
		case 44: goto st112;
		case 111: goto st146;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st111;
	goto tr23;
st146:
	if ( ++p == pe )
		goto _test_eof146;
case 146:
	switch( (*p) ) {
		case 44: goto st112;
		case 110: goto st147;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st111;
	goto tr23;
st147:
	if ( ++p == pe )
		goto _test_eof147;
case 147:
	switch( (*p) ) {
		case 44: goto st112;
		case 61: goto st148;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st111;
	goto tr23;
st148:
	if ( ++p == pe )
		goto _test_eof148;
case 148:
	switch( (*p) ) {
		case 34: goto st149;
		case 44: goto st112;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st111;
	goto tr23;
st149:
	if ( ++p == pe )
		goto _test_eof149;
case 149:
	switch( (*p) ) {
		case 32: goto st66;
		case 44: goto st152;
		case 61: goto st111;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st150;
	goto tr23;
st150:
	if ( ++p == pe )
		goto _test_eof150;
case 150:
	switch( (*p) ) {
		case 32: goto st66;
		case 34: goto st151;
		case 44: goto st152;
		case 61: goto st111;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st150;
	goto tr23;
st151:
	if ( ++p == pe )
		goto _test_eof151;
case 151:
	switch( (*p) ) {
		case 32: goto st66;
		case 34: goto st151;
		case 44: goto st152;
		case 61: goto st111;
		case 62: goto st159;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st150;
	goto tr23;
st152:
	if ( ++p == pe )
		goto _test_eof152;
case 152:
	switch( (*p) ) {
		case 32: goto st66;
		case 34: goto st151;
		case 44: goto st152;
		case 61: goto st111;
		case 78: goto st153;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st150;
	goto tr23;
st153:
	if ( ++p == pe )
		goto _test_eof153;
case 153:
	switch( (*p) ) {
		case 32: goto st66;
		case 34: goto st151;
		case 44: goto st152;
		case 61: goto st111;
		case 117: goto st154;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st150;
	goto tr23;
st154:
	if ( ++p == pe )
		goto _test_eof154;
case 154:
	switch( (*p) ) {
		case 32: goto st66;
		case 34: goto st151;
		case 44: goto st152;
		case 61: goto st111;
		case 109: goto st155;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st150;
	goto tr23;
st155:
	if ( ++p == pe )
		goto _test_eof155;
case 155:
	switch( (*p) ) {
		case 32: goto st66;
		case 34: goto st151;
		case 44: goto st152;
		case 61: goto st111;
		case 98: goto st156;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st150;
	goto tr23;
st156:
	if ( ++p == pe )
		goto _test_eof156;
case 156:
	switch( (*p) ) {
		case 32: goto st66;
		case 34: goto st151;
		case 44: goto st152;
		case 61: goto st111;
		case 101: goto st157;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st150;
	goto tr23;
st157:
	if ( ++p == pe )
		goto _test_eof157;
case 157:
	switch( (*p) ) {
		case 32: goto st66;
		case 34: goto st151;
		case 44: goto st152;
		case 61: goto st111;
		case 114: goto st158;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st150;
	goto tr23;
st158:
	if ( ++p == pe )
		goto _test_eof158;
case 158:
	switch( (*p) ) {
		case 32: goto st66;
		case 34: goto st151;
		case 44: goto st152;
		case 61: goto st119;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st150;
	goto tr23;
st159:
	if ( ++p == pe )
		goto _test_eof159;
case 159:
	switch( (*p) ) {
		case 10: goto tr42;
		case 32: goto st66;
		case 34: goto st151;
		case 44: goto st152;
		case 61: goto st111;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st150;
	goto tr23;
st160:
	if ( ++p == pe )
		goto _test_eof160;
case 160:
	switch( (*p) ) {
		case 44: goto st112;
		case 108: goto st161;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st111;
	goto tr23;
st161:
	if ( ++p == pe )
		goto _test_eof161;
case 161:
	switch( (*p) ) {
		case 44: goto st112;
		case 111: goto st162;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st111;
	goto tr23;
st162:
	if ( ++p == pe )
		goto _test_eof162;
case 162:
	switch( (*p) ) {
		case 44: goto st112;
		case 97: goto st163;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st111;
	goto tr23;
st163:
	if ( ++p == pe )
		goto _test_eof163;
case 163:
	switch( (*p) ) {
		case 44: goto st112;
		case 116: goto st135;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st111;
	goto tr23;
st164:
	if ( ++p == pe )
		goto _test_eof164;
case 164:
	switch( (*p) ) {
		case 44: goto st112;
		case 110: goto st165;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st111;
	goto tr23;
st165:
	if ( ++p == pe )
		goto _test_eof165;
case 165:
	switch( (*p) ) {
		case 44: goto st112;
		case 116: goto st166;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st111;
	goto tr23;
st166:
	if ( ++p == pe )
		goto _test_eof166;
case 166:
	switch( (*p) ) {
		case 44: goto st112;
		case 101: goto st167;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st111;
	goto tr23;
st167:
	if ( ++p == pe )
		goto _test_eof167;
case 167:
	switch( (*p) ) {
		case 44: goto st112;
		case 103: goto st133;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st111;
	goto tr23;
st168:
	if ( ++p == pe )
		goto _test_eof168;
case 168:
	switch( (*p) ) {
		case 44: goto st112;
		case 116: goto st169;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st111;
	goto tr23;
st169:
	if ( ++p == pe )
		goto _test_eof169;
case 169:
	switch( (*p) ) {
		case 44: goto st112;
		case 114: goto st170;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st111;
	goto tr23;
st170:
	if ( ++p == pe )
		goto _test_eof170;
case 170:
	switch( (*p) ) {
		case 44: goto st112;
		case 105: goto st171;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st111;
	goto tr23;
st171:
	if ( ++p == pe )
		goto _test_eof171;
case 171:
	switch( (*p) ) {
		case 44: goto st112;
		case 110: goto st172;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st111;
	goto tr23;
st172:
	if ( ++p == pe )
		goto _test_eof172;
case 172:
	switch( (*p) ) {
		case 44: goto st112;
		case 103: goto st135;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st111;
	goto tr23;
st173:
	if ( ++p == pe )
		goto _test_eof173;
case 173:
	if ( (*p) == 44 )
		goto st121;
	if ( (*p) < 48 ) {
		if ( 33 <= (*p) && (*p) <= 47 )
			goto st111;
	} else if ( (*p) > 57 ) {
		if ( 58 <= (*p) && (*p) <= 126 )
			goto st111;
	} else
		goto st173;
	goto tr23;
tr122:
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
	goto st174;
st174:
	if ( ++p == pe )
		goto _test_eof174;
case 174:
#line 3149 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr42;
		case 32: goto st26;
		case 44: goto tr121;
		case 61: goto st111;
		case 62: goto tr122;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st106;
	goto tr23;
st175:
	if ( ++p == pe )
		goto _test_eof175;
case 175:
	switch( (*p) ) {
		case 32: goto st26;
		case 44: goto tr121;
		case 61: goto st111;
		case 62: goto tr122;
		case 117: goto st176;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st106;
	goto tr23;
st176:
	if ( ++p == pe )
		goto _test_eof176;
case 176:
	switch( (*p) ) {
		case 32: goto st26;
		case 44: goto tr121;
		case 61: goto st111;
		case 62: goto tr122;
		case 109: goto st177;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st106;
	goto tr23;
st177:
	if ( ++p == pe )
		goto _test_eof177;
case 177:
	switch( (*p) ) {
		case 32: goto st26;
		case 44: goto tr121;
		case 61: goto st111;
		case 62: goto tr122;
		case 98: goto st178;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st106;
	goto tr23;
st178:
	if ( ++p == pe )
		goto _test_eof178;
case 178:
	switch( (*p) ) {
		case 32: goto st26;
		case 44: goto tr121;
		case 61: goto st111;
		case 62: goto tr122;
		case 101: goto st179;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st106;
	goto tr23;
st179:
	if ( ++p == pe )
		goto _test_eof179;
case 179:
	switch( (*p) ) {
		case 32: goto st26;
		case 44: goto tr121;
		case 61: goto st111;
		case 62: goto tr122;
		case 114: goto st180;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st106;
	goto tr23;
st180:
	if ( ++p == pe )
		goto _test_eof180;
case 180:
	switch( (*p) ) {
		case 32: goto st26;
		case 44: goto tr121;
		case 61: goto st119;
		case 62: goto tr122;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st106;
	goto tr23;
tr28:
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st181;
st181:
	if ( ++p == pe )
		goto _test_eof181;
case 181:
#line 3253 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr29;
		case 61: goto tr32;
		case 78: goto st182;
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
	goto tr23;
st182:
	if ( ++p == pe )
		goto _test_eof182;
case 182:
	switch( (*p) ) {
		case 10: goto tr29;
		case 61: goto tr32;
		case 70: goto st183;
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
	goto tr23;
st183:
	if ( ++p == pe )
		goto _test_eof183;
case 183:
	switch( (*p) ) {
		case 10: goto tr29;
		case 61: goto tr32;
		case 79: goto st184;
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
	goto tr23;
st184:
	if ( ++p == pe )
		goto _test_eof184;
case 184:
	switch( (*p) ) {
		case 10: goto tr29;
		case 61: goto tr198;
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
	goto tr23;
tr198:
#line 68 "vcf_v41.ragel"
	{
//        set_vcf_meta_entry_name(ts, p-ts, status->current_meta_entry);
    }
#line 252 "vcf_v41.ragel"
	{
        printf("Meta in line %zu\n", n_lines);
    }
	goto st185;
st185:
	if ( ++p == pe )
		goto _test_eof185;
case 185:
#line 3383 "vcf_validator_detail.hpp"
	if ( (*p) == 60 )
		goto st186;
	if ( (*p) > 59 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st19;
	} else if ( (*p) >= 32 )
		goto st19;
	goto tr23;
st186:
	if ( ++p == pe )
		goto _test_eof186;
case 186:
	switch( (*p) ) {
		case 10: goto tr29;
		case 73: goto tr200;
	}
	if ( (*p) < 62 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st19;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 60 )
				goto st19;
		} else
			goto tr34;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr34;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) && (*p) <= 126 )
					goto st19;
			} else if ( (*p) >= 97 )
				goto tr34;
		} else
			goto st19;
	} else
		goto st19;
	goto tr23;
tr200:
#line 248 "vcf_v41.ragel"
	{
        printf("Meta INFO in line %zu\n", n_lines);
    }
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st187;
st187:
	if ( ++p == pe )
		goto _test_eof187;
case 187:
#line 3438 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr29;
		case 61: goto st25;
		case 68: goto st188;
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
	goto tr23;
st188:
	if ( ++p == pe )
		goto _test_eof188;
case 188:
	switch( (*p) ) {
		case 10: goto tr29;
		case 61: goto st189;
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
	goto tr23;
st189:
	if ( ++p == pe )
		goto _test_eof189;
case 189:
	switch( (*p) ) {
		case 32: goto st26;
		case 61: goto st195;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st190;
	goto tr23;
st190:
	if ( ++p == pe )
		goto _test_eof190;
case 190:
	switch( (*p) ) {
		case 32: goto st26;
		case 44: goto tr205;
		case 61: goto st195;
		case 62: goto tr206;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st190;
	goto tr23;
tr205:
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
	goto st191;
st191:
	if ( ++p == pe )
		goto _test_eof191;
case 191:
#line 3534 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 32: goto st26;
		case 44: goto tr205;
		case 61: goto st195;
		case 62: goto tr206;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto st190;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st190;
		} else
			goto tr207;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st190;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st190;
		} else
			goto tr207;
	} else
		goto tr207;
	goto tr23;
tr207:
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st192;
st192:
	if ( ++p == pe )
		goto _test_eof192;
case 192:
#line 3572 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 32: goto st26;
		case 44: goto tr205;
		case 61: goto st193;
		case 62: goto tr206;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto st190;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st190;
		} else
			goto st192;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st190;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st190;
		} else
			goto st192;
	} else
		goto st192;
	goto tr23;
st193:
	if ( ++p == pe )
		goto _test_eof193;
case 193:
	switch( (*p) ) {
		case 32: goto st26;
		case 44: goto st194;
		case 61: goto st195;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st190;
	goto tr23;
st194:
	if ( ++p == pe )
		goto _test_eof194;
case 194:
	switch( (*p) ) {
		case 32: goto st26;
		case 44: goto tr205;
		case 61: goto st195;
		case 62: goto tr206;
		case 78: goto st337;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st190;
	goto tr23;
st195:
	if ( ++p == pe )
		goto _test_eof195;
case 195:
	if ( (*p) == 44 )
		goto st196;
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st195;
	goto tr23;
st196:
	if ( ++p == pe )
		goto _test_eof196;
case 196:
	switch( (*p) ) {
		case 44: goto st196;
		case 78: goto st197;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st195;
	goto tr23;
st197:
	if ( ++p == pe )
		goto _test_eof197;
case 197:
	switch( (*p) ) {
		case 44: goto st196;
		case 117: goto st198;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st195;
	goto tr23;
st198:
	if ( ++p == pe )
		goto _test_eof198;
case 198:
	switch( (*p) ) {
		case 44: goto st196;
		case 109: goto st199;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st195;
	goto tr23;
st199:
	if ( ++p == pe )
		goto _test_eof199;
case 199:
	switch( (*p) ) {
		case 44: goto st196;
		case 98: goto st200;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st195;
	goto tr23;
st200:
	if ( ++p == pe )
		goto _test_eof200;
case 200:
	switch( (*p) ) {
		case 44: goto st196;
		case 101: goto st201;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st195;
	goto tr23;
st201:
	if ( ++p == pe )
		goto _test_eof201;
case 201:
	switch( (*p) ) {
		case 44: goto st196;
		case 114: goto st202;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st195;
	goto tr23;
st202:
	if ( ++p == pe )
		goto _test_eof202;
case 202:
	switch( (*p) ) {
		case 44: goto st196;
		case 61: goto st203;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st195;
	goto tr23;
st203:
	if ( ++p == pe )
		goto _test_eof203;
case 203:
	switch( (*p) ) {
		case 44: goto st196;
		case 46: goto st204;
		case 65: goto st204;
		case 71: goto st204;
		case 82: goto st204;
	}
	if ( (*p) < 48 ) {
		if ( 33 <= (*p) && (*p) <= 47 )
			goto st195;
	} else if ( (*p) > 57 ) {
		if ( 58 <= (*p) && (*p) <= 126 )
			goto st195;
	} else
		goto st335;
	goto tr23;
st204:
	if ( ++p == pe )
		goto _test_eof204;
case 204:
	if ( (*p) == 44 )
		goto st205;
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st195;
	goto tr23;
st205:
	if ( ++p == pe )
		goto _test_eof205;
case 205:
	switch( (*p) ) {
		case 44: goto st196;
		case 78: goto st197;
		case 84: goto st206;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st195;
	goto tr23;
st206:
	if ( ++p == pe )
		goto _test_eof206;
case 206:
	switch( (*p) ) {
		case 44: goto st196;
		case 121: goto st207;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st195;
	goto tr23;
st207:
	if ( ++p == pe )
		goto _test_eof207;
case 207:
	switch( (*p) ) {
		case 44: goto st196;
		case 112: goto st208;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st195;
	goto tr23;
st208:
	if ( ++p == pe )
		goto _test_eof208;
case 208:
	switch( (*p) ) {
		case 44: goto st196;
		case 101: goto st209;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st195;
	goto tr23;
st209:
	if ( ++p == pe )
		goto _test_eof209;
case 209:
	switch( (*p) ) {
		case 44: goto st196;
		case 61: goto st210;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st195;
	goto tr23;
st210:
	if ( ++p == pe )
		goto _test_eof210;
case 210:
	switch( (*p) ) {
		case 44: goto st196;
		case 67: goto st211;
		case 70: goto st322;
		case 73: goto st327;
		case 83: goto st331;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st195;
	goto tr23;
st211:
	if ( ++p == pe )
		goto _test_eof211;
case 211:
	switch( (*p) ) {
		case 44: goto st196;
		case 104: goto st212;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st195;
	goto tr23;
st212:
	if ( ++p == pe )
		goto _test_eof212;
case 212:
	switch( (*p) ) {
		case 44: goto st196;
		case 97: goto st213;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st195;
	goto tr23;
st213:
	if ( ++p == pe )
		goto _test_eof213;
case 213:
	switch( (*p) ) {
		case 44: goto st196;
		case 114: goto st214;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st195;
	goto tr23;
st214:
	if ( ++p == pe )
		goto _test_eof214;
case 214:
	switch( (*p) ) {
		case 44: goto st196;
		case 97: goto st215;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st195;
	goto tr23;
st215:
	if ( ++p == pe )
		goto _test_eof215;
case 215:
	switch( (*p) ) {
		case 44: goto st196;
		case 99: goto st216;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st195;
	goto tr23;
st216:
	if ( ++p == pe )
		goto _test_eof216;
case 216:
	switch( (*p) ) {
		case 44: goto st196;
		case 116: goto st217;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st195;
	goto tr23;
st217:
	if ( ++p == pe )
		goto _test_eof217;
case 217:
	switch( (*p) ) {
		case 44: goto st196;
		case 101: goto st218;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st195;
	goto tr23;
st218:
	if ( ++p == pe )
		goto _test_eof218;
case 218:
	switch( (*p) ) {
		case 44: goto st196;
		case 114: goto st219;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st195;
	goto tr23;
st219:
	if ( ++p == pe )
		goto _test_eof219;
case 219:
	if ( (*p) == 44 )
		goto st220;
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st195;
	goto tr23;
st220:
	if ( ++p == pe )
		goto _test_eof220;
case 220:
	switch( (*p) ) {
		case 44: goto st196;
		case 68: goto st221;
		case 78: goto st197;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st195;
	goto tr23;
st221:
	if ( ++p == pe )
		goto _test_eof221;
case 221:
	switch( (*p) ) {
		case 44: goto st196;
		case 101: goto st222;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st195;
	goto tr23;
st222:
	if ( ++p == pe )
		goto _test_eof222;
case 222:
	switch( (*p) ) {
		case 44: goto st196;
		case 115: goto st223;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st195;
	goto tr23;
st223:
	if ( ++p == pe )
		goto _test_eof223;
case 223:
	switch( (*p) ) {
		case 44: goto st196;
		case 99: goto st224;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st195;
	goto tr23;
st224:
	if ( ++p == pe )
		goto _test_eof224;
case 224:
	switch( (*p) ) {
		case 44: goto st196;
		case 114: goto st225;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st195;
	goto tr23;
st225:
	if ( ++p == pe )
		goto _test_eof225;
case 225:
	switch( (*p) ) {
		case 44: goto st196;
		case 105: goto st226;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st195;
	goto tr23;
st226:
	if ( ++p == pe )
		goto _test_eof226;
case 226:
	switch( (*p) ) {
		case 44: goto st196;
		case 112: goto st227;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st195;
	goto tr23;
st227:
	if ( ++p == pe )
		goto _test_eof227;
case 227:
	switch( (*p) ) {
		case 44: goto st196;
		case 116: goto st228;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st195;
	goto tr23;
st228:
	if ( ++p == pe )
		goto _test_eof228;
case 228:
	switch( (*p) ) {
		case 44: goto st196;
		case 105: goto st229;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st195;
	goto tr23;
st229:
	if ( ++p == pe )
		goto _test_eof229;
case 229:
	switch( (*p) ) {
		case 44: goto st196;
		case 111: goto st230;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st195;
	goto tr23;
st230:
	if ( ++p == pe )
		goto _test_eof230;
case 230:
	switch( (*p) ) {
		case 44: goto st196;
		case 110: goto st231;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st195;
	goto tr23;
st231:
	if ( ++p == pe )
		goto _test_eof231;
case 231:
	switch( (*p) ) {
		case 44: goto st196;
		case 61: goto st232;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st195;
	goto tr23;
st232:
	if ( ++p == pe )
		goto _test_eof232;
case 232:
	switch( (*p) ) {
		case 34: goto st233;
		case 44: goto st196;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st195;
	goto tr23;
st233:
	if ( ++p == pe )
		goto _test_eof233;
case 233:
	switch( (*p) ) {
		case 32: goto st234;
		case 44: goto st269;
		case 61: goto st195;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st266;
	goto tr23;
st234:
	if ( ++p == pe )
		goto _test_eof234;
case 234:
	if ( (*p) == 34 )
		goto st235;
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st234;
	} else if ( (*p) >= 32 )
		goto st234;
	goto tr23;
st235:
	if ( ++p == pe )
		goto _test_eof235;
case 235:
	switch( (*p) ) {
		case 34: goto st235;
		case 44: goto st236;
		case 62: goto st265;
	}
	if ( (*p) > 60 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto st234;
	} else if ( (*p) >= 32 )
		goto st234;
	goto tr23;
st236:
	if ( ++p == pe )
		goto _test_eof236;
case 236:
	switch( (*p) ) {
		case 34: goto st235;
		case 83: goto st237;
		case 86: goto st258;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st234;
	} else if ( (*p) >= 32 )
		goto st234;
	goto tr23;
st237:
	if ( ++p == pe )
		goto _test_eof237;
case 237:
	switch( (*p) ) {
		case 34: goto st235;
		case 111: goto st238;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st234;
	} else if ( (*p) >= 32 )
		goto st234;
	goto tr23;
st238:
	if ( ++p == pe )
		goto _test_eof238;
case 238:
	switch( (*p) ) {
		case 34: goto st235;
		case 117: goto st239;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st234;
	} else if ( (*p) >= 32 )
		goto st234;
	goto tr23;
st239:
	if ( ++p == pe )
		goto _test_eof239;
case 239:
	switch( (*p) ) {
		case 34: goto st235;
		case 114: goto st240;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st234;
	} else if ( (*p) >= 32 )
		goto st234;
	goto tr23;
st240:
	if ( ++p == pe )
		goto _test_eof240;
case 240:
	switch( (*p) ) {
		case 34: goto st235;
		case 99: goto st241;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st234;
	} else if ( (*p) >= 32 )
		goto st234;
	goto tr23;
st241:
	if ( ++p == pe )
		goto _test_eof241;
case 241:
	switch( (*p) ) {
		case 34: goto st235;
		case 101: goto st242;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st234;
	} else if ( (*p) >= 32 )
		goto st234;
	goto tr23;
st242:
	if ( ++p == pe )
		goto _test_eof242;
case 242:
	switch( (*p) ) {
		case 34: goto st235;
		case 61: goto st243;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto st234;
	goto tr23;
st243:
	if ( ++p == pe )
		goto _test_eof243;
case 243:
	if ( (*p) == 34 )
		goto st244;
	goto tr23;
st244:
	if ( ++p == pe )
		goto _test_eof244;
case 244:
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st245;
	} else if ( (*p) >= 32 )
		goto st245;
	goto tr23;
st245:
	if ( ++p == pe )
		goto _test_eof245;
case 245:
	if ( (*p) == 34 )
		goto st246;
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st245;
	} else if ( (*p) >= 32 )
		goto st245;
	goto tr23;
st246:
	if ( ++p == pe )
		goto _test_eof246;
case 246:
	switch( (*p) ) {
		case 34: goto st246;
		case 44: goto st247;
		case 62: goto st257;
	}
	if ( (*p) > 60 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto st245;
	} else if ( (*p) >= 32 )
		goto st245;
	goto tr23;
st247:
	if ( ++p == pe )
		goto _test_eof247;
case 247:
	switch( (*p) ) {
		case 34: goto st246;
		case 86: goto st248;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st245;
	} else if ( (*p) >= 32 )
		goto st245;
	goto tr23;
st248:
	if ( ++p == pe )
		goto _test_eof248;
case 248:
	switch( (*p) ) {
		case 34: goto st246;
		case 101: goto st249;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st245;
	} else if ( (*p) >= 32 )
		goto st245;
	goto tr23;
st249:
	if ( ++p == pe )
		goto _test_eof249;
case 249:
	switch( (*p) ) {
		case 34: goto st246;
		case 114: goto st250;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st245;
	} else if ( (*p) >= 32 )
		goto st245;
	goto tr23;
st250:
	if ( ++p == pe )
		goto _test_eof250;
case 250:
	switch( (*p) ) {
		case 34: goto st246;
		case 115: goto st251;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st245;
	} else if ( (*p) >= 32 )
		goto st245;
	goto tr23;
st251:
	if ( ++p == pe )
		goto _test_eof251;
case 251:
	switch( (*p) ) {
		case 34: goto st246;
		case 105: goto st252;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st245;
	} else if ( (*p) >= 32 )
		goto st245;
	goto tr23;
st252:
	if ( ++p == pe )
		goto _test_eof252;
case 252:
	switch( (*p) ) {
		case 34: goto st246;
		case 111: goto st253;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st245;
	} else if ( (*p) >= 32 )
		goto st245;
	goto tr23;
st253:
	if ( ++p == pe )
		goto _test_eof253;
case 253:
	switch( (*p) ) {
		case 34: goto st246;
		case 110: goto st254;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st245;
	} else if ( (*p) >= 32 )
		goto st245;
	goto tr23;
st254:
	if ( ++p == pe )
		goto _test_eof254;
case 254:
	switch( (*p) ) {
		case 34: goto st246;
		case 61: goto st255;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto st245;
	goto tr23;
st255:
	if ( ++p == pe )
		goto _test_eof255;
case 255:
	if ( (*p) == 34 )
		goto st256;
	goto tr23;
st256:
	if ( ++p == pe )
		goto _test_eof256;
case 256:
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st66;
	} else if ( (*p) >= 32 )
		goto st66;
	goto tr23;
st257:
	if ( ++p == pe )
		goto _test_eof257;
case 257:
	switch( (*p) ) {
		case 10: goto tr42;
		case 34: goto st246;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st245;
	} else if ( (*p) >= 32 )
		goto st245;
	goto tr23;
st258:
	if ( ++p == pe )
		goto _test_eof258;
case 258:
	switch( (*p) ) {
		case 34: goto st235;
		case 101: goto st259;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st234;
	} else if ( (*p) >= 32 )
		goto st234;
	goto tr23;
st259:
	if ( ++p == pe )
		goto _test_eof259;
case 259:
	switch( (*p) ) {
		case 34: goto st235;
		case 114: goto st260;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st234;
	} else if ( (*p) >= 32 )
		goto st234;
	goto tr23;
st260:
	if ( ++p == pe )
		goto _test_eof260;
case 260:
	switch( (*p) ) {
		case 34: goto st235;
		case 115: goto st261;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st234;
	} else if ( (*p) >= 32 )
		goto st234;
	goto tr23;
st261:
	if ( ++p == pe )
		goto _test_eof261;
case 261:
	switch( (*p) ) {
		case 34: goto st235;
		case 105: goto st262;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st234;
	} else if ( (*p) >= 32 )
		goto st234;
	goto tr23;
st262:
	if ( ++p == pe )
		goto _test_eof262;
case 262:
	switch( (*p) ) {
		case 34: goto st235;
		case 111: goto st263;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st234;
	} else if ( (*p) >= 32 )
		goto st234;
	goto tr23;
st263:
	if ( ++p == pe )
		goto _test_eof263;
case 263:
	switch( (*p) ) {
		case 34: goto st235;
		case 110: goto st264;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st234;
	} else if ( (*p) >= 32 )
		goto st234;
	goto tr23;
st264:
	if ( ++p == pe )
		goto _test_eof264;
case 264:
	switch( (*p) ) {
		case 34: goto st235;
		case 61: goto st255;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto st234;
	goto tr23;
st265:
	if ( ++p == pe )
		goto _test_eof265;
case 265:
	switch( (*p) ) {
		case 10: goto tr42;
		case 34: goto st235;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st234;
	} else if ( (*p) >= 32 )
		goto st234;
	goto tr23;
st266:
	if ( ++p == pe )
		goto _test_eof266;
case 266:
	switch( (*p) ) {
		case 32: goto st234;
		case 34: goto st267;
		case 44: goto st269;
		case 61: goto st195;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st266;
	goto tr23;
st267:
	if ( ++p == pe )
		goto _test_eof267;
case 267:
	switch( (*p) ) {
		case 32: goto st234;
		case 34: goto st267;
		case 44: goto st268;
		case 61: goto st195;
		case 62: goto st321;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st266;
	goto tr23;
st268:
	if ( ++p == pe )
		goto _test_eof268;
case 268:
	switch( (*p) ) {
		case 32: goto st234;
		case 34: goto st267;
		case 44: goto st269;
		case 61: goto st195;
		case 78: goto st270;
		case 83: goto st276;
		case 86: goto st314;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st266;
	goto tr23;
st269:
	if ( ++p == pe )
		goto _test_eof269;
case 269:
	switch( (*p) ) {
		case 32: goto st234;
		case 34: goto st267;
		case 44: goto st269;
		case 61: goto st195;
		case 78: goto st270;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st266;
	goto tr23;
st270:
	if ( ++p == pe )
		goto _test_eof270;
case 270:
	switch( (*p) ) {
		case 32: goto st234;
		case 34: goto st267;
		case 44: goto st269;
		case 61: goto st195;
		case 117: goto st271;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st266;
	goto tr23;
st271:
	if ( ++p == pe )
		goto _test_eof271;
case 271:
	switch( (*p) ) {
		case 32: goto st234;
		case 34: goto st267;
		case 44: goto st269;
		case 61: goto st195;
		case 109: goto st272;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st266;
	goto tr23;
st272:
	if ( ++p == pe )
		goto _test_eof272;
case 272:
	switch( (*p) ) {
		case 32: goto st234;
		case 34: goto st267;
		case 44: goto st269;
		case 61: goto st195;
		case 98: goto st273;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st266;
	goto tr23;
st273:
	if ( ++p == pe )
		goto _test_eof273;
case 273:
	switch( (*p) ) {
		case 32: goto st234;
		case 34: goto st267;
		case 44: goto st269;
		case 61: goto st195;
		case 101: goto st274;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st266;
	goto tr23;
st274:
	if ( ++p == pe )
		goto _test_eof274;
case 274:
	switch( (*p) ) {
		case 32: goto st234;
		case 34: goto st267;
		case 44: goto st269;
		case 61: goto st195;
		case 114: goto st275;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st266;
	goto tr23;
st275:
	if ( ++p == pe )
		goto _test_eof275;
case 275:
	switch( (*p) ) {
		case 32: goto st234;
		case 34: goto st267;
		case 44: goto st269;
		case 61: goto st203;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st266;
	goto tr23;
st276:
	if ( ++p == pe )
		goto _test_eof276;
case 276:
	switch( (*p) ) {
		case 32: goto st234;
		case 34: goto st267;
		case 44: goto st269;
		case 61: goto st195;
		case 111: goto st277;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st266;
	goto tr23;
st277:
	if ( ++p == pe )
		goto _test_eof277;
case 277:
	switch( (*p) ) {
		case 32: goto st234;
		case 34: goto st267;
		case 44: goto st269;
		case 61: goto st195;
		case 117: goto st278;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st266;
	goto tr23;
st278:
	if ( ++p == pe )
		goto _test_eof278;
case 278:
	switch( (*p) ) {
		case 32: goto st234;
		case 34: goto st267;
		case 44: goto st269;
		case 61: goto st195;
		case 114: goto st279;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st266;
	goto tr23;
st279:
	if ( ++p == pe )
		goto _test_eof279;
case 279:
	switch( (*p) ) {
		case 32: goto st234;
		case 34: goto st267;
		case 44: goto st269;
		case 61: goto st195;
		case 99: goto st280;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st266;
	goto tr23;
st280:
	if ( ++p == pe )
		goto _test_eof280;
case 280:
	switch( (*p) ) {
		case 32: goto st234;
		case 34: goto st267;
		case 44: goto st269;
		case 61: goto st195;
		case 101: goto st281;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st266;
	goto tr23;
st281:
	if ( ++p == pe )
		goto _test_eof281;
case 281:
	switch( (*p) ) {
		case 32: goto st234;
		case 34: goto st267;
		case 44: goto st269;
		case 61: goto st282;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st266;
	goto tr23;
st282:
	if ( ++p == pe )
		goto _test_eof282;
case 282:
	switch( (*p) ) {
		case 34: goto st283;
		case 44: goto st196;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st195;
	goto tr23;
st283:
	if ( ++p == pe )
		goto _test_eof283;
case 283:
	switch( (*p) ) {
		case 32: goto st245;
		case 44: goto st287;
		case 61: goto st195;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st284;
	goto tr23;
st284:
	if ( ++p == pe )
		goto _test_eof284;
case 284:
	switch( (*p) ) {
		case 32: goto st245;
		case 34: goto st285;
		case 44: goto st287;
		case 61: goto st195;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st284;
	goto tr23;
st285:
	if ( ++p == pe )
		goto _test_eof285;
case 285:
	switch( (*p) ) {
		case 32: goto st245;
		case 34: goto st285;
		case 44: goto st286;
		case 61: goto st195;
		case 62: goto st313;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st284;
	goto tr23;
st286:
	if ( ++p == pe )
		goto _test_eof286;
case 286:
	switch( (*p) ) {
		case 32: goto st245;
		case 34: goto st285;
		case 44: goto st287;
		case 61: goto st195;
		case 78: goto st288;
		case 86: goto st294;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st284;
	goto tr23;
st287:
	if ( ++p == pe )
		goto _test_eof287;
case 287:
	switch( (*p) ) {
		case 32: goto st245;
		case 34: goto st285;
		case 44: goto st287;
		case 61: goto st195;
		case 78: goto st288;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st284;
	goto tr23;
st288:
	if ( ++p == pe )
		goto _test_eof288;
case 288:
	switch( (*p) ) {
		case 32: goto st245;
		case 34: goto st285;
		case 44: goto st287;
		case 61: goto st195;
		case 117: goto st289;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st284;
	goto tr23;
st289:
	if ( ++p == pe )
		goto _test_eof289;
case 289:
	switch( (*p) ) {
		case 32: goto st245;
		case 34: goto st285;
		case 44: goto st287;
		case 61: goto st195;
		case 109: goto st290;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st284;
	goto tr23;
st290:
	if ( ++p == pe )
		goto _test_eof290;
case 290:
	switch( (*p) ) {
		case 32: goto st245;
		case 34: goto st285;
		case 44: goto st287;
		case 61: goto st195;
		case 98: goto st291;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st284;
	goto tr23;
st291:
	if ( ++p == pe )
		goto _test_eof291;
case 291:
	switch( (*p) ) {
		case 32: goto st245;
		case 34: goto st285;
		case 44: goto st287;
		case 61: goto st195;
		case 101: goto st292;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st284;
	goto tr23;
st292:
	if ( ++p == pe )
		goto _test_eof292;
case 292:
	switch( (*p) ) {
		case 32: goto st245;
		case 34: goto st285;
		case 44: goto st287;
		case 61: goto st195;
		case 114: goto st293;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st284;
	goto tr23;
st293:
	if ( ++p == pe )
		goto _test_eof293;
case 293:
	switch( (*p) ) {
		case 32: goto st245;
		case 34: goto st285;
		case 44: goto st287;
		case 61: goto st203;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st284;
	goto tr23;
st294:
	if ( ++p == pe )
		goto _test_eof294;
case 294:
	switch( (*p) ) {
		case 32: goto st245;
		case 34: goto st285;
		case 44: goto st287;
		case 61: goto st195;
		case 101: goto st295;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st284;
	goto tr23;
st295:
	if ( ++p == pe )
		goto _test_eof295;
case 295:
	switch( (*p) ) {
		case 32: goto st245;
		case 34: goto st285;
		case 44: goto st287;
		case 61: goto st195;
		case 114: goto st296;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st284;
	goto tr23;
st296:
	if ( ++p == pe )
		goto _test_eof296;
case 296:
	switch( (*p) ) {
		case 32: goto st245;
		case 34: goto st285;
		case 44: goto st287;
		case 61: goto st195;
		case 115: goto st297;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st284;
	goto tr23;
st297:
	if ( ++p == pe )
		goto _test_eof297;
case 297:
	switch( (*p) ) {
		case 32: goto st245;
		case 34: goto st285;
		case 44: goto st287;
		case 61: goto st195;
		case 105: goto st298;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st284;
	goto tr23;
st298:
	if ( ++p == pe )
		goto _test_eof298;
case 298:
	switch( (*p) ) {
		case 32: goto st245;
		case 34: goto st285;
		case 44: goto st287;
		case 61: goto st195;
		case 111: goto st299;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st284;
	goto tr23;
st299:
	if ( ++p == pe )
		goto _test_eof299;
case 299:
	switch( (*p) ) {
		case 32: goto st245;
		case 34: goto st285;
		case 44: goto st287;
		case 61: goto st195;
		case 110: goto st300;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st284;
	goto tr23;
st300:
	if ( ++p == pe )
		goto _test_eof300;
case 300:
	switch( (*p) ) {
		case 32: goto st245;
		case 34: goto st285;
		case 44: goto st287;
		case 61: goto st301;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st284;
	goto tr23;
st301:
	if ( ++p == pe )
		goto _test_eof301;
case 301:
	switch( (*p) ) {
		case 34: goto st302;
		case 44: goto st196;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st195;
	goto tr23;
st302:
	if ( ++p == pe )
		goto _test_eof302;
case 302:
	switch( (*p) ) {
		case 32: goto st66;
		case 44: goto st305;
		case 61: goto st195;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st303;
	goto tr23;
st303:
	if ( ++p == pe )
		goto _test_eof303;
case 303:
	switch( (*p) ) {
		case 32: goto st66;
		case 34: goto st304;
		case 44: goto st305;
		case 61: goto st195;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st303;
	goto tr23;
st304:
	if ( ++p == pe )
		goto _test_eof304;
case 304:
	switch( (*p) ) {
		case 32: goto st66;
		case 34: goto st304;
		case 44: goto st305;
		case 61: goto st195;
		case 62: goto st312;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st303;
	goto tr23;
st305:
	if ( ++p == pe )
		goto _test_eof305;
case 305:
	switch( (*p) ) {
		case 32: goto st66;
		case 34: goto st304;
		case 44: goto st305;
		case 61: goto st195;
		case 78: goto st306;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st303;
	goto tr23;
st306:
	if ( ++p == pe )
		goto _test_eof306;
case 306:
	switch( (*p) ) {
		case 32: goto st66;
		case 34: goto st304;
		case 44: goto st305;
		case 61: goto st195;
		case 117: goto st307;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st303;
	goto tr23;
st307:
	if ( ++p == pe )
		goto _test_eof307;
case 307:
	switch( (*p) ) {
		case 32: goto st66;
		case 34: goto st304;
		case 44: goto st305;
		case 61: goto st195;
		case 109: goto st308;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st303;
	goto tr23;
st308:
	if ( ++p == pe )
		goto _test_eof308;
case 308:
	switch( (*p) ) {
		case 32: goto st66;
		case 34: goto st304;
		case 44: goto st305;
		case 61: goto st195;
		case 98: goto st309;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st303;
	goto tr23;
st309:
	if ( ++p == pe )
		goto _test_eof309;
case 309:
	switch( (*p) ) {
		case 32: goto st66;
		case 34: goto st304;
		case 44: goto st305;
		case 61: goto st195;
		case 101: goto st310;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st303;
	goto tr23;
st310:
	if ( ++p == pe )
		goto _test_eof310;
case 310:
	switch( (*p) ) {
		case 32: goto st66;
		case 34: goto st304;
		case 44: goto st305;
		case 61: goto st195;
		case 114: goto st311;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st303;
	goto tr23;
st311:
	if ( ++p == pe )
		goto _test_eof311;
case 311:
	switch( (*p) ) {
		case 32: goto st66;
		case 34: goto st304;
		case 44: goto st305;
		case 61: goto st203;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st303;
	goto tr23;
st312:
	if ( ++p == pe )
		goto _test_eof312;
case 312:
	switch( (*p) ) {
		case 10: goto tr42;
		case 32: goto st66;
		case 34: goto st304;
		case 44: goto st305;
		case 61: goto st195;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st303;
	goto tr23;
st313:
	if ( ++p == pe )
		goto _test_eof313;
case 313:
	switch( (*p) ) {
		case 10: goto tr42;
		case 32: goto st245;
		case 34: goto st285;
		case 44: goto st287;
		case 61: goto st195;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st284;
	goto tr23;
st314:
	if ( ++p == pe )
		goto _test_eof314;
case 314:
	switch( (*p) ) {
		case 32: goto st234;
		case 34: goto st267;
		case 44: goto st269;
		case 61: goto st195;
		case 101: goto st315;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st266;
	goto tr23;
st315:
	if ( ++p == pe )
		goto _test_eof315;
case 315:
	switch( (*p) ) {
		case 32: goto st234;
		case 34: goto st267;
		case 44: goto st269;
		case 61: goto st195;
		case 114: goto st316;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st266;
	goto tr23;
st316:
	if ( ++p == pe )
		goto _test_eof316;
case 316:
	switch( (*p) ) {
		case 32: goto st234;
		case 34: goto st267;
		case 44: goto st269;
		case 61: goto st195;
		case 115: goto st317;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st266;
	goto tr23;
st317:
	if ( ++p == pe )
		goto _test_eof317;
case 317:
	switch( (*p) ) {
		case 32: goto st234;
		case 34: goto st267;
		case 44: goto st269;
		case 61: goto st195;
		case 105: goto st318;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st266;
	goto tr23;
st318:
	if ( ++p == pe )
		goto _test_eof318;
case 318:
	switch( (*p) ) {
		case 32: goto st234;
		case 34: goto st267;
		case 44: goto st269;
		case 61: goto st195;
		case 111: goto st319;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st266;
	goto tr23;
st319:
	if ( ++p == pe )
		goto _test_eof319;
case 319:
	switch( (*p) ) {
		case 32: goto st234;
		case 34: goto st267;
		case 44: goto st269;
		case 61: goto st195;
		case 110: goto st320;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st266;
	goto tr23;
st320:
	if ( ++p == pe )
		goto _test_eof320;
case 320:
	switch( (*p) ) {
		case 32: goto st234;
		case 34: goto st267;
		case 44: goto st269;
		case 61: goto st301;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st266;
	goto tr23;
st321:
	if ( ++p == pe )
		goto _test_eof321;
case 321:
	switch( (*p) ) {
		case 10: goto tr42;
		case 32: goto st234;
		case 34: goto st267;
		case 44: goto st269;
		case 61: goto st195;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st266;
	goto tr23;
st322:
	if ( ++p == pe )
		goto _test_eof322;
case 322:
	switch( (*p) ) {
		case 44: goto st196;
		case 108: goto st323;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st195;
	goto tr23;
st323:
	if ( ++p == pe )
		goto _test_eof323;
case 323:
	switch( (*p) ) {
		case 44: goto st196;
		case 97: goto st324;
		case 111: goto st325;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st195;
	goto tr23;
st324:
	if ( ++p == pe )
		goto _test_eof324;
case 324:
	switch( (*p) ) {
		case 44: goto st196;
		case 103: goto st219;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st195;
	goto tr23;
st325:
	if ( ++p == pe )
		goto _test_eof325;
case 325:
	switch( (*p) ) {
		case 44: goto st196;
		case 97: goto st326;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st195;
	goto tr23;
st326:
	if ( ++p == pe )
		goto _test_eof326;
case 326:
	switch( (*p) ) {
		case 44: goto st196;
		case 116: goto st219;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st195;
	goto tr23;
st327:
	if ( ++p == pe )
		goto _test_eof327;
case 327:
	switch( (*p) ) {
		case 44: goto st196;
		case 110: goto st328;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st195;
	goto tr23;
st328:
	if ( ++p == pe )
		goto _test_eof328;
case 328:
	switch( (*p) ) {
		case 44: goto st196;
		case 116: goto st329;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st195;
	goto tr23;
st329:
	if ( ++p == pe )
		goto _test_eof329;
case 329:
	switch( (*p) ) {
		case 44: goto st196;
		case 101: goto st330;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st195;
	goto tr23;
st330:
	if ( ++p == pe )
		goto _test_eof330;
case 330:
	switch( (*p) ) {
		case 44: goto st196;
		case 103: goto st217;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st195;
	goto tr23;
st331:
	if ( ++p == pe )
		goto _test_eof331;
case 331:
	switch( (*p) ) {
		case 44: goto st196;
		case 116: goto st332;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st195;
	goto tr23;
st332:
	if ( ++p == pe )
		goto _test_eof332;
case 332:
	switch( (*p) ) {
		case 44: goto st196;
		case 114: goto st333;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st195;
	goto tr23;
st333:
	if ( ++p == pe )
		goto _test_eof333;
case 333:
	switch( (*p) ) {
		case 44: goto st196;
		case 105: goto st334;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st195;
	goto tr23;
st334:
	if ( ++p == pe )
		goto _test_eof334;
case 334:
	switch( (*p) ) {
		case 44: goto st196;
		case 110: goto st324;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st195;
	goto tr23;
st335:
	if ( ++p == pe )
		goto _test_eof335;
case 335:
	if ( (*p) == 44 )
		goto st205;
	if ( (*p) < 48 ) {
		if ( 33 <= (*p) && (*p) <= 47 )
			goto st195;
	} else if ( (*p) > 57 ) {
		if ( 58 <= (*p) && (*p) <= 126 )
			goto st195;
	} else
		goto st335;
	goto tr23;
tr206:
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
	goto st336;
st336:
	if ( ++p == pe )
		goto _test_eof336;
case 336:
#line 5423 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 10: goto tr42;
		case 32: goto st26;
		case 44: goto tr205;
		case 61: goto st195;
		case 62: goto tr206;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st190;
	goto tr23;
st337:
	if ( ++p == pe )
		goto _test_eof337;
case 337:
	switch( (*p) ) {
		case 32: goto st26;
		case 44: goto tr205;
		case 61: goto st195;
		case 62: goto tr206;
		case 117: goto st338;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st190;
	goto tr23;
st338:
	if ( ++p == pe )
		goto _test_eof338;
case 338:
	switch( (*p) ) {
		case 32: goto st26;
		case 44: goto tr205;
		case 61: goto st195;
		case 62: goto tr206;
		case 109: goto st339;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st190;
	goto tr23;
st339:
	if ( ++p == pe )
		goto _test_eof339;
case 339:
	switch( (*p) ) {
		case 32: goto st26;
		case 44: goto tr205;
		case 61: goto st195;
		case 62: goto tr206;
		case 98: goto st340;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st190;
	goto tr23;
st340:
	if ( ++p == pe )
		goto _test_eof340;
case 340:
	switch( (*p) ) {
		case 32: goto st26;
		case 44: goto tr205;
		case 61: goto st195;
		case 62: goto tr206;
		case 101: goto st341;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st190;
	goto tr23;
st341:
	if ( ++p == pe )
		goto _test_eof341;
case 341:
	switch( (*p) ) {
		case 32: goto st26;
		case 44: goto tr205;
		case 61: goto st195;
		case 62: goto tr206;
		case 114: goto st342;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st190;
	goto tr23;
st342:
	if ( ++p == pe )
		goto _test_eof342;
case 342:
	switch( (*p) ) {
		case 32: goto st26;
		case 44: goto tr205;
		case 61: goto st203;
		case 62: goto tr206;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st190;
	goto tr23;
st343:
	if ( ++p == pe )
		goto _test_eof343;
case 343:
	if ( (*p) == 72 )
		goto st344;
	goto tr357;
st344:
	if ( ++p == pe )
		goto _test_eof344;
case 344:
	if ( (*p) == 82 )
		goto st345;
	goto tr357;
st345:
	if ( ++p == pe )
		goto _test_eof345;
case 345:
	if ( (*p) == 79 )
		goto st346;
	goto tr357;
st346:
	if ( ++p == pe )
		goto _test_eof346;
case 346:
	if ( (*p) == 77 )
		goto st347;
	goto tr357;
st347:
	if ( ++p == pe )
		goto _test_eof347;
case 347:
	if ( (*p) == 9 )
		goto st348;
	goto tr357;
st348:
	if ( ++p == pe )
		goto _test_eof348;
case 348:
	if ( (*p) == 80 )
		goto st349;
	goto tr357;
st349:
	if ( ++p == pe )
		goto _test_eof349;
case 349:
	if ( (*p) == 79 )
		goto st350;
	goto tr357;
st350:
	if ( ++p == pe )
		goto _test_eof350;
case 350:
	if ( (*p) == 83 )
		goto st351;
	goto tr357;
st351:
	if ( ++p == pe )
		goto _test_eof351;
case 351:
	if ( (*p) == 9 )
		goto st352;
	goto tr357;
st352:
	if ( ++p == pe )
		goto _test_eof352;
case 352:
	if ( (*p) == 73 )
		goto st353;
	goto tr357;
st353:
	if ( ++p == pe )
		goto _test_eof353;
case 353:
	if ( (*p) == 68 )
		goto st354;
	goto tr357;
st354:
	if ( ++p == pe )
		goto _test_eof354;
case 354:
	if ( (*p) == 9 )
		goto st355;
	goto tr357;
st355:
	if ( ++p == pe )
		goto _test_eof355;
case 355:
	if ( (*p) == 82 )
		goto st356;
	goto tr357;
st356:
	if ( ++p == pe )
		goto _test_eof356;
case 356:
	if ( (*p) == 69 )
		goto st357;
	goto tr357;
st357:
	if ( ++p == pe )
		goto _test_eof357;
case 357:
	if ( (*p) == 70 )
		goto st358;
	goto tr357;
st358:
	if ( ++p == pe )
		goto _test_eof358;
case 358:
	if ( (*p) == 9 )
		goto st359;
	goto tr357;
st359:
	if ( ++p == pe )
		goto _test_eof359;
case 359:
	if ( (*p) == 65 )
		goto st360;
	goto tr357;
st360:
	if ( ++p == pe )
		goto _test_eof360;
case 360:
	if ( (*p) == 76 )
		goto st361;
	goto tr357;
st361:
	if ( ++p == pe )
		goto _test_eof361;
case 361:
	if ( (*p) == 84 )
		goto st362;
	goto tr357;
st362:
	if ( ++p == pe )
		goto _test_eof362;
case 362:
	if ( (*p) == 9 )
		goto st363;
	goto tr357;
st363:
	if ( ++p == pe )
		goto _test_eof363;
case 363:
	if ( (*p) == 81 )
		goto st364;
	goto tr357;
st364:
	if ( ++p == pe )
		goto _test_eof364;
case 364:
	if ( (*p) == 85 )
		goto st365;
	goto tr357;
st365:
	if ( ++p == pe )
		goto _test_eof365;
case 365:
	if ( (*p) == 65 )
		goto st366;
	goto tr357;
st366:
	if ( ++p == pe )
		goto _test_eof366;
case 366:
	if ( (*p) == 76 )
		goto st367;
	goto tr357;
st367:
	if ( ++p == pe )
		goto _test_eof367;
case 367:
	if ( (*p) == 9 )
		goto st368;
	goto tr357;
st368:
	if ( ++p == pe )
		goto _test_eof368;
case 368:
	if ( (*p) == 70 )
		goto st369;
	goto tr357;
st369:
	if ( ++p == pe )
		goto _test_eof369;
case 369:
	if ( (*p) == 73 )
		goto st370;
	goto tr357;
st370:
	if ( ++p == pe )
		goto _test_eof370;
case 370:
	if ( (*p) == 76 )
		goto st371;
	goto tr357;
st371:
	if ( ++p == pe )
		goto _test_eof371;
case 371:
	if ( (*p) == 84 )
		goto st372;
	goto tr357;
st372:
	if ( ++p == pe )
		goto _test_eof372;
case 372:
	if ( (*p) == 69 )
		goto st373;
	goto tr357;
st373:
	if ( ++p == pe )
		goto _test_eof373;
case 373:
	if ( (*p) == 82 )
		goto st374;
	goto tr357;
st374:
	if ( ++p == pe )
		goto _test_eof374;
case 374:
	if ( (*p) == 9 )
		goto st375;
	goto tr357;
st375:
	if ( ++p == pe )
		goto _test_eof375;
case 375:
	if ( (*p) == 73 )
		goto st376;
	goto tr357;
st376:
	if ( ++p == pe )
		goto _test_eof376;
case 376:
	if ( (*p) == 78 )
		goto st377;
	goto tr357;
st377:
	if ( ++p == pe )
		goto _test_eof377;
case 377:
	if ( (*p) == 70 )
		goto st378;
	goto tr357;
st378:
	if ( ++p == pe )
		goto _test_eof378;
case 378:
	if ( (*p) == 79 )
		goto st379;
	goto tr357;
st379:
	if ( ++p == pe )
		goto _test_eof379;
case 379:
	switch( (*p) ) {
		case 9: goto st380;
		case 10: goto tr395;
	}
	goto tr357;
st380:
	if ( ++p == pe )
		goto _test_eof380;
case 380:
	if ( (*p) == 70 )
		goto st381;
	goto tr357;
st381:
	if ( ++p == pe )
		goto _test_eof381;
case 381:
	if ( (*p) == 79 )
		goto st382;
	goto tr357;
st382:
	if ( ++p == pe )
		goto _test_eof382;
case 382:
	if ( (*p) == 82 )
		goto st383;
	goto tr357;
st383:
	if ( ++p == pe )
		goto _test_eof383;
case 383:
	if ( (*p) == 77 )
		goto st384;
	goto tr357;
st384:
	if ( ++p == pe )
		goto _test_eof384;
case 384:
	if ( (*p) == 65 )
		goto st385;
	goto tr357;
st385:
	if ( ++p == pe )
		goto _test_eof385;
case 385:
	if ( (*p) == 84 )
		goto st386;
	goto tr357;
st386:
	if ( ++p == pe )
		goto _test_eof386;
case 386:
	if ( (*p) == 9 )
		goto st387;
	goto tr357;
tr404:
#line 87 "vcf_v41.ragel"
	{
//        add_vcf_sample_name(ts, p-ts, file);
    }
	goto st387;
st387:
	if ( ++p == pe )
		goto _test_eof387;
case 387:
#line 5837 "vcf_validator_detail.hpp"
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr403;
	goto tr357;
tr403:
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st388;
st388:
	if ( ++p == pe )
		goto _test_eof388;
case 388:
#line 5851 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr404;
		case 10: goto tr405;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto st388;
	goto tr357;
tr395:
#line 20 "vcf_v41.ragel"
	{
        ++n_lines;
        n_columns = 1;
    }
	goto st465;
tr405:
#line 87 "vcf_v41.ragel"
	{
//        add_vcf_sample_name(ts, p-ts, file);
    }
#line 20 "vcf_v41.ragel"
	{
        ++n_lines;
        n_columns = 1;
    }
	goto st465;
st465:
	if ( ++p == pe )
		goto _test_eof465;
case 465:
#line 5881 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto tr512;
		case 46: goto tr512;
		case 95: goto tr512;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr512;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr512;
	} else
		goto tr512;
	goto tr511;
tr512:
#line 91 "vcf_v41.ragel"
	{
//        status->current_record = vcf_record_new();
//        printf("Reading record\n");
    }
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st389;
st389:
	if ( ++p == pe )
		goto _test_eof389;
case 389:
#line 5911 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr408;
		case 44: goto st389;
		case 46: goto st389;
		case 95: goto st389;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st389;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st389;
	} else
		goto st389;
	goto tr407;
tr408:
#line 120 "vcf_v41.ragel"
	{
//        set_vcf_record_chromosome(ts, p-ts, status->current_record);
    }
#line 25 "vcf_v41.ragel"
	{
        ++n_columns;
    }
	goto st390;
st390:
	if ( ++p == pe )
		goto _test_eof390;
case 390:
#line 5941 "vcf_validator_detail.hpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr411;
	goto tr410;
tr411:
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st391;
st391:
	if ( ++p == pe )
		goto _test_eof391;
case 391:
#line 5955 "vcf_validator_detail.hpp"
	if ( (*p) == 9 )
		goto tr412;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st391;
	goto tr410;
tr412:
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
	goto st392;
st392:
	if ( ++p == pe )
		goto _test_eof392;
case 392:
#line 5977 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 46: goto tr415;
		case 95: goto tr416;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr416;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr416;
	} else
		goto tr416;
	goto tr414;
tr415:
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st393;
st393:
	if ( ++p == pe )
		goto _test_eof393;
case 393:
#line 6001 "vcf_validator_detail.hpp"
	if ( (*p) == 9 )
		goto tr417;
	goto tr414;
tr417:
#line 138 "vcf_v41.ragel"
	{
//        set_vcf_record_id(ts, p-ts, status->current_record);
    }
#line 25 "vcf_v41.ragel"
	{
        ++n_columns;
    }
	goto st394;
st394:
	if ( ++p == pe )
		goto _test_eof394;
case 394:
#line 6019 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 65: goto tr419;
		case 67: goto tr419;
		case 71: goto tr419;
		case 78: goto tr419;
		case 84: goto tr419;
	}
	goto tr418;
tr419:
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st395;
st395:
	if ( ++p == pe )
		goto _test_eof395;
case 395:
#line 6038 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr420;
		case 65: goto st395;
		case 67: goto st395;
		case 71: goto st395;
		case 78: goto st395;
		case 84: goto st395;
	}
	goto tr418;
tr420:
#line 147 "vcf_v41.ragel"
	{
 //       set_vcf_record_reference(ts, p-ts, status->current_record);
    }
#line 25 "vcf_v41.ragel"
	{
        ++n_columns;
    }
	goto st396;
st396:
	if ( ++p == pe )
		goto _test_eof396;
case 396:
#line 6062 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 46: goto tr423;
		case 48: goto tr424;
		case 60: goto tr425;
		case 65: goto tr426;
		case 67: goto tr426;
		case 71: goto tr426;
		case 78: goto tr426;
		case 84: goto tr426;
		case 91: goto tr427;
		case 93: goto tr428;
	}
	goto tr422;
tr423:
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st397;
st397:
	if ( ++p == pe )
		goto _test_eof397;
case 397:
#line 6086 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr429;
		case 44: goto st417;
		case 46: goto st397;
		case 65: goto st397;
		case 67: goto st397;
		case 71: goto st397;
		case 78: goto st397;
		case 84: goto st397;
	}
	goto tr422;
tr429:
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
	goto st398;
tr470:
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
	goto st398;
tr494:
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
	goto st398;
st398:
	if ( ++p == pe )
		goto _test_eof398;
case 398:
#line 6156 "vcf_validator_detail.hpp"
	if ( (*p) == 46 )
		goto tr433;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr434;
	goto tr432;
tr433:
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st399;
st399:
	if ( ++p == pe )
		goto _test_eof399;
case 399:
#line 6172 "vcf_validator_detail.hpp"
	if ( (*p) == 9 )
		goto tr435;
	goto tr432;
tr435:
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
	goto st400;
st400:
	if ( ++p == pe )
		goto _test_eof400;
case 400:
#line 6196 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto tr437;
		case 46: goto tr437;
		case 95: goto tr437;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr437;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr437;
	} else
		goto tr437;
	goto tr436;
tr437:
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st401;
st401:
	if ( ++p == pe )
		goto _test_eof401;
case 401:
#line 6221 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr438;
		case 44: goto st401;
		case 46: goto st401;
		case 59: goto st413;
		case 95: goto st401;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st401;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st401;
	} else
		goto st401;
	goto tr436;
tr438:
#line 196 "vcf_v41.ragel"
	{
 //       set_vcf_record_filter(ts, p-ts, status->current_record);
    }
#line 25 "vcf_v41.ragel"
	{
        ++n_columns;
    }
	goto st402;
st402:
	if ( ++p == pe )
		goto _test_eof402;
case 402:
#line 6252 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 46: goto tr442;
		case 95: goto tr443;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr443;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr443;
	} else
		goto tr443;
	goto tr441;
tr442:
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st403;
st403:
	if ( ++p == pe )
		goto _test_eof403;
case 403:
#line 6276 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr444;
		case 10: goto tr445;
		case 59: goto st409;
		case 61: goto st411;
	}
	goto tr441;
tr444:
#line 205 "vcf_v41.ragel"
	{
//        set_vcf_record_info(ts, p-ts, status->current_record);
    }
#line 25 "vcf_v41.ragel"
	{
        ++n_columns;
    }
	goto st404;
st404:
	if ( ++p == pe )
		goto _test_eof404;
case 404:
#line 6298 "vcf_validator_detail.hpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr449;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr449;
	} else
		goto tr449;
	goto tr448;
tr449:
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st405;
st405:
	if ( ++p == pe )
		goto _test_eof405;
case 405:
#line 6318 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr450;
		case 58: goto st408;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st405;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st405;
	} else
		goto st405;
	goto tr448;
tr450:
#line 214 "vcf_v41.ragel"
	{
 //       set_vcf_record_format(ts, p-ts, status->current_record);
    }
#line 25 "vcf_v41.ragel"
	{
        ++n_columns;
    }
	goto st406;
tr455:
#line 223 "vcf_v41.ragel"
	{
//        add_vcf_record_sample(ts, p-ts, status->current_record);
    }
#line 25 "vcf_v41.ragel"
	{
        ++n_columns;
    }
	goto st406;
st406:
	if ( ++p == pe )
		goto _test_eof406;
case 406:
#line 6356 "vcf_validator_detail.hpp"
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr454;
	goto tr453;
tr454:
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st407;
st407:
	if ( ++p == pe )
		goto _test_eof407;
case 407:
#line 6370 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr455;
		case 10: goto tr456;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st407;
	goto tr453;
tr445:
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
	goto st466;
tr456:
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
	goto st466;
st466:
	if ( ++p == pe )
		goto _test_eof466;
case 466:
#line 6452 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto tr512;
		case 46: goto tr512;
		case 95: goto tr512;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr512;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr512;
	} else
		goto tr512;
	goto tr407;
st408:
	if ( ++p == pe )
		goto _test_eof408;
case 408:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st405;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st405;
	} else
		goto st405;
	goto tr448;
st409:
	if ( ++p == pe )
		goto _test_eof409;
case 409:
	switch( (*p) ) {
		case 46: goto st403;
		case 95: goto st410;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st410;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st410;
	} else
		goto st410;
	goto tr441;
tr443:
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st410;
st410:
	if ( ++p == pe )
		goto _test_eof410;
case 410:
#line 6507 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr444;
		case 10: goto tr445;
		case 59: goto st409;
		case 61: goto st411;
		case 95: goto st410;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st410;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st410;
	} else
		goto st410;
	goto tr441;
st411:
	if ( ++p == pe )
		goto _test_eof411;
case 411:
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st412;
	goto tr441;
st412:
	if ( ++p == pe )
		goto _test_eof412;
case 412:
	switch( (*p) ) {
		case 9: goto tr444;
		case 10: goto tr445;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st412;
	goto tr441;
st413:
	if ( ++p == pe )
		goto _test_eof413;
case 413:
	switch( (*p) ) {
		case 44: goto st401;
		case 46: goto st401;
		case 95: goto st401;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st401;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st401;
	} else
		goto st401;
	goto tr436;
tr434:
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st414;
st414:
	if ( ++p == pe )
		goto _test_eof414;
case 414:
#line 6570 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr435;
		case 46: goto st415;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st414;
	goto tr432;
st415:
	if ( ++p == pe )
		goto _test_eof415;
case 415:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st416;
	goto tr432;
st416:
	if ( ++p == pe )
		goto _test_eof416;
case 416:
	if ( (*p) == 9 )
		goto tr435;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st416;
	goto tr432;
st417:
	if ( ++p == pe )
		goto _test_eof417;
case 417:
	switch( (*p) ) {
		case 46: goto st397;
		case 65: goto st397;
		case 67: goto st397;
		case 71: goto st397;
		case 78: goto st397;
		case 84: goto st397;
	}
	goto tr422;
tr424:
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st418;
st418:
	if ( ++p == pe )
		goto _test_eof418;
case 418:
#line 6617 "vcf_validator_detail.hpp"
	if ( (*p) == 9 )
		goto tr429;
	goto tr422;
tr425:
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st419;
st419:
	if ( ++p == pe )
		goto _test_eof419;
case 419:
#line 6631 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 67: goto st420;
		case 68: goto st424;
		case 73: goto st440;
	}
	goto tr422;
st420:
	if ( ++p == pe )
		goto _test_eof420;
case 420:
	if ( (*p) == 78 )
		goto st421;
	goto tr422;
st421:
	if ( ++p == pe )
		goto _test_eof421;
case 421:
	if ( (*p) == 86 )
		goto st422;
	goto tr422;
st422:
	if ( ++p == pe )
		goto _test_eof422;
case 422:
	if ( (*p) == 62 )
		goto st423;
	goto tr422;
st423:
	if ( ++p == pe )
		goto _test_eof423;
case 423:
	if ( (*p) == 9 )
		goto tr470;
	goto tr422;
st424:
	if ( ++p == pe )
		goto _test_eof424;
case 424:
	switch( (*p) ) {
		case 69: goto st425;
		case 85: goto st432;
	}
	goto tr422;
st425:
	if ( ++p == pe )
		goto _test_eof425;
case 425:
	if ( (*p) == 76 )
		goto st426;
	goto tr422;
st426:
	if ( ++p == pe )
		goto _test_eof426;
case 426:
	switch( (*p) ) {
		case 58: goto st427;
		case 62: goto st423;
	}
	goto tr422;
st427:
	if ( ++p == pe )
		goto _test_eof427;
case 427:
	if ( (*p) == 77 )
		goto st428;
	goto tr422;
st428:
	if ( ++p == pe )
		goto _test_eof428;
case 428:
	if ( (*p) == 69 )
		goto st429;
	goto tr422;
st429:
	if ( ++p == pe )
		goto _test_eof429;
case 429:
	if ( (*p) == 58 )
		goto st430;
	goto tr422;
st430:
	if ( ++p == pe )
		goto _test_eof430;
case 430:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st431;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st431;
	} else
		goto st431;
	goto tr422;
st431:
	if ( ++p == pe )
		goto _test_eof431;
case 431:
	if ( (*p) == 62 )
		goto st423;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st431;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st431;
	} else
		goto st431;
	goto tr422;
st432:
	if ( ++p == pe )
		goto _test_eof432;
case 432:
	if ( (*p) == 80 )
		goto st433;
	goto tr422;
st433:
	if ( ++p == pe )
		goto _test_eof433;
case 433:
	switch( (*p) ) {
		case 58: goto st434;
		case 62: goto st423;
	}
	goto tr422;
st434:
	if ( ++p == pe )
		goto _test_eof434;
case 434:
	if ( (*p) == 84 )
		goto st435;
	goto tr422;
st435:
	if ( ++p == pe )
		goto _test_eof435;
case 435:
	if ( (*p) == 65 )
		goto st436;
	goto tr422;
st436:
	if ( ++p == pe )
		goto _test_eof436;
case 436:
	if ( (*p) == 78 )
		goto st437;
	goto tr422;
st437:
	if ( ++p == pe )
		goto _test_eof437;
case 437:
	if ( (*p) == 68 )
		goto st438;
	goto tr422;
st438:
	if ( ++p == pe )
		goto _test_eof438;
case 438:
	if ( (*p) == 69 )
		goto st439;
	goto tr422;
st439:
	if ( ++p == pe )
		goto _test_eof439;
case 439:
	if ( (*p) == 77 )
		goto st422;
	goto tr422;
st440:
	if ( ++p == pe )
		goto _test_eof440;
case 440:
	if ( (*p) == 78 )
		goto st441;
	goto tr422;
st441:
	if ( ++p == pe )
		goto _test_eof441;
case 441:
	switch( (*p) ) {
		case 83: goto st426;
		case 86: goto st422;
	}
	goto tr422;
tr426:
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st442;
st442:
	if ( ++p == pe )
		goto _test_eof442;
case 442:
#line 6824 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr429;
		case 44: goto st417;
		case 46: goto st397;
		case 65: goto st442;
		case 67: goto st442;
		case 71: goto st442;
		case 78: goto st442;
		case 84: goto st442;
		case 91: goto st443;
		case 93: goto st448;
	}
	goto tr422;
st443:
	if ( ++p == pe )
		goto _test_eof443;
case 443:
	switch( (*p) ) {
		case 44: goto st444;
		case 46: goto st444;
		case 95: goto st444;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st444;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st444;
	} else
		goto st444;
	goto tr422;
st444:
	if ( ++p == pe )
		goto _test_eof444;
case 444:
	switch( (*p) ) {
		case 44: goto st444;
		case 46: goto st444;
		case 58: goto st445;
		case 95: goto st444;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st444;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st444;
	} else
		goto st444;
	goto tr422;
st445:
	if ( ++p == pe )
		goto _test_eof445;
case 445:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st446;
	goto tr422;
st446:
	if ( ++p == pe )
		goto _test_eof446;
case 446:
	if ( (*p) == 91 )
		goto st447;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st446;
	goto tr422;
st447:
	if ( ++p == pe )
		goto _test_eof447;
case 447:
	if ( (*p) == 9 )
		goto tr494;
	goto tr422;
st448:
	if ( ++p == pe )
		goto _test_eof448;
case 448:
	switch( (*p) ) {
		case 44: goto st449;
		case 46: goto st449;
		case 95: goto st449;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st449;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st449;
	} else
		goto st449;
	goto tr422;
st449:
	if ( ++p == pe )
		goto _test_eof449;
case 449:
	switch( (*p) ) {
		case 44: goto st449;
		case 46: goto st449;
		case 58: goto st450;
		case 95: goto st449;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st449;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st449;
	} else
		goto st449;
	goto tr422;
st450:
	if ( ++p == pe )
		goto _test_eof450;
case 450:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st451;
	goto tr422;
st451:
	if ( ++p == pe )
		goto _test_eof451;
case 451:
	if ( (*p) == 93 )
		goto st447;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st451;
	goto tr422;
tr427:
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st452;
st452:
	if ( ++p == pe )
		goto _test_eof452;
case 452:
#line 6961 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto st453;
		case 46: goto st453;
		case 95: goto st453;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st453;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st453;
	} else
		goto st453;
	goto tr422;
st453:
	if ( ++p == pe )
		goto _test_eof453;
case 453:
	switch( (*p) ) {
		case 44: goto st453;
		case 46: goto st453;
		case 58: goto st454;
		case 95: goto st453;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st453;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st453;
	} else
		goto st453;
	goto tr422;
st454:
	if ( ++p == pe )
		goto _test_eof454;
case 454:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st455;
	goto tr422;
st455:
	if ( ++p == pe )
		goto _test_eof455;
case 455:
	if ( (*p) == 91 )
		goto st456;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st455;
	goto tr422;
st456:
	if ( ++p == pe )
		goto _test_eof456;
case 456:
	switch( (*p) ) {
		case 65: goto st457;
		case 67: goto st457;
		case 71: goto st457;
		case 78: goto st457;
		case 84: goto st457;
	}
	goto tr422;
st457:
	if ( ++p == pe )
		goto _test_eof457;
case 457:
	switch( (*p) ) {
		case 9: goto tr494;
		case 65: goto st457;
		case 67: goto st457;
		case 71: goto st457;
		case 78: goto st457;
		case 84: goto st457;
	}
	goto tr422;
tr428:
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st458;
st458:
	if ( ++p == pe )
		goto _test_eof458;
case 458:
#line 7046 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 44: goto st459;
		case 46: goto st459;
		case 95: goto st459;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st459;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st459;
	} else
		goto st459;
	goto tr422;
st459:
	if ( ++p == pe )
		goto _test_eof459;
case 459:
	switch( (*p) ) {
		case 44: goto st459;
		case 46: goto st459;
		case 58: goto st460;
		case 95: goto st459;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st459;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st459;
	} else
		goto st459;
	goto tr422;
st460:
	if ( ++p == pe )
		goto _test_eof460;
case 460:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st461;
	goto tr422;
st461:
	if ( ++p == pe )
		goto _test_eof461;
case 461:
	if ( (*p) == 93 )
		goto st456;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st461;
	goto tr422;
tr416:
#line 12 "vcf_v41.ragel"
	{
        ParsePolicy::handle_token_begin(*this);
    }
	goto st462;
st462:
	if ( ++p == pe )
		goto _test_eof462;
case 462:
#line 7106 "vcf_validator_detail.hpp"
	switch( (*p) ) {
		case 9: goto tr417;
		case 95: goto st462;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st462;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st462;
	} else
		goto st462;
	goto tr414;
st463:
	if ( ++p == pe )
		goto _test_eof463;
case 463:
	if ( (*p) == 10 )
		goto tr508;
	goto st463;
tr508:
#line 20 "vcf_v41.ragel"
	{
        ++n_lines;
        n_columns = 1;
    }
#line 359 "vcf_v41.ragel"
	{ {goto st20;} }
	goto st467;
st467:
	if ( ++p == pe )
		goto _test_eof467;
case 467:
#line 7140 "vcf_validator_detail.hpp"
	goto st0;
st464:
	if ( ++p == pe )
		goto _test_eof464;
case 464:
	if ( (*p) == 10 )
		goto tr510;
	goto st464;
tr510:
#line 20 "vcf_v41.ragel"
	{
        ++n_lines;
        n_columns = 1;
    }
#line 360 "vcf_v41.ragel"
	{ {goto st466;} }
	goto st468;
st468:
	if ( ++p == pe )
		goto _test_eof468;
case 468:
#line 7162 "vcf_validator_detail.hpp"
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
	_test_eof465: cs = 465; goto _test_eof; 
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
	_test_eof466: cs = 466; goto _test_eof; 
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
	_test_eof467: cs = 467; goto _test_eof; 
	_test_eof464: cs = 464; goto _test_eof; 
	_test_eof468: cs = 468; goto _test_eof; 

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
        p--; {goto st463;}
    }
	break;
	case 18: 
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
#line 34 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st463;}
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
#line 39 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        p--; {goto st464;}
    }
	break;
	case 17: 
	case 20: 
#line 34 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st463;}
    }
#line 39 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        p--; {goto st464;}
    }
	break;
	case 14: 
	case 15: 
#line 53 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this,
            "Fileformat must be a sequence of alphanumeric and/or punctuation characters");
        p--; {goto st463;}
    }
#line 29 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this);
        p--; {goto st463;}
    }
	break;
	case 389: 
#line 124 "vcf_v41.ragel"
	{
    }
#line 44 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st464;}
    }
	break;
	case 390: 
	case 391: 
#line 133 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this, "Position must be a positive number");
        p--; {goto st464;}
    }
#line 44 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st464;}
    }
	break;
	case 392: 
	case 393: 
	case 462: 
#line 142 "vcf_v41.ragel"
	{
        printf("Line %zu: Error in 'id' field\n", n_lines);
 //       vcf_record_free(status->current_record);
    }
#line 44 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st464;}
    }
	break;
	case 394: 
	case 395: 
#line 151 "vcf_v41.ragel"
	{
        printf("Line %zu: Error in 'reference' field\n", n_lines);
//        vcf_record_free(status->current_record);
    }
#line 44 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st464;}
    }
	break;
	case 396: 
	case 397: 
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
#line 176 "vcf_v41.ragel"
	{
        printf("Line %zu: Error in 'alternate' field\n", n_lines);
 //       vcf_record_free(status->current_record);
    }
#line 44 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st464;}
    }
	break;
	case 398: 
	case 399: 
	case 414: 
	case 415: 
	case 416: 
#line 191 "vcf_v41.ragel"
	{
        printf("Line %zu: Error in 'quality' field\n", n_lines);
 //       vcf_record_free(status->current_record);
    }
#line 44 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st464;}
    }
	break;
	case 400: 
	case 401: 
	case 413: 
#line 200 "vcf_v41.ragel"
	{
        printf("Line %zu: Error in 'filter' field\n", n_lines);
 //       vcf_record_free(status->current_record);
    }
#line 44 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st464;}
    }
	break;
	case 402: 
	case 403: 
	case 409: 
	case 410: 
	case 411: 
	case 412: 
#line 209 "vcf_v41.ragel"
	{
        printf("Line %zu: Error in 'info' field\n", n_lines);
 //       vcf_record_free(status->current_record);
    }
#line 44 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st464;}
    }
	break;
	case 404: 
	case 405: 
	case 408: 
#line 218 "vcf_v41.ragel"
	{
        printf("Line %zu: Error in 'format' field\n", n_lines);
 //       vcf_record_free(status->current_record);
    }
#line 44 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st464;}
    }
	break;
	case 406: 
	case 407: 
#line 227 "vcf_v41.ragel"
	{
        printf("Line %zu: Error in sample\n", n_lines);
//        vcf_record_free(status->current_record);
    }
#line 44 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_body_section_error(*this);
        p--; {goto st464;}
    }
	break;
	case 16: 
#line 29 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_fileformat_section_error(*this);
        p--; {goto st463;}
    }
#line 34 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_meta_section_error(*this);
        p--; {goto st463;}
    }
#line 39 "vcf_v41.ragel"
	{
        ErrorPolicy::handle_header_section_error(*this);
        p--; {goto st464;}
    }
	break;
#line 8264 "vcf_validator_detail.hpp"
	}
	}

	_out: {}
	}

#line 423 "vcf_v41.ragel"

    }

  }
}
