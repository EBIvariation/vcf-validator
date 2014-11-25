
#line 1 "vcf_v41.ragel"
//#include "vcf_reader.h"
#include <cstdio>
#include <string>

using namespace std;


#line 11 "vcf_ragel.cpp"
static const int vcf_start = 143;
static const int vcf_first_final = 143;
static const int vcf_error = 0;

static const int vcf_en_main = 143;


#line 329 "vcf_v41.ragel"



int run_vcf_parser(const string & input_text) {
    int cs;
    const char *p = input_text.data();
    const char *pe = input_text.data() + input_text.size();
    const char *ts, *te;
    int stack[4];
    int top, act;
    const char *eof = pe;

    int lines = 0;
    int batches = 0;

//    status->current_batch->text = p;
//     printf("ragel - batch text = '%.*s'\n", 50, status->current_batch->text);

    
#line 39 "vcf_ragel.cpp"
	{
	cs = vcf_start;
	}

#line 44 "vcf_ragel.cpp"
	{
	if ( p == pe )
		goto _test_eof;
	switch ( cs )
	{
case 143:
	switch( (*p) ) {
		case 10: goto st144;
		case 35: goto tr177;
		case 44: goto tr178;
		case 46: goto tr178;
		case 95: goto tr178;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr178;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr178;
	} else
		goto tr178;
	goto tr55;
tr55:
#line 111 "vcf_v41.ragel"
	{
//        printf("Line %zu (%s): Error in 'chromosome' field\n", status->num_batches * batch_size + status->num_records, file->filename);
//        vcf_record_free(status->current_record);
    }
	goto st0;
tr58:
#line 126 "vcf_v41.ragel"
	{
//        printf("Line %zu (%s): Error in 'position' field\n", status->num_batches * batch_size + status->num_records, file->filename);
//        vcf_record_free(status->current_record);
    }
	goto st0;
tr62:
#line 139 "vcf_v41.ragel"
	{
//        printf("Line %zu (%s): Error in 'id' field\n", status->num_batches * batch_size + status->num_records, file->filename);
 //       vcf_record_free(status->current_record);
    }
	goto st0;
tr66:
#line 152 "vcf_v41.ragel"
	{
//        printf("Line %zu (%s): Error in 'reference' field\n", status->num_batches * batch_size + status->num_records, file->filename);
//        vcf_record_free(status->current_record);
    }
	goto st0;
tr70:
#line 181 "vcf_v41.ragel"
	{
//        printf("Line %zu (%s): Error in 'alternate' field\n", status->num_batches * batch_size + status->num_records, file->filename);
 //       vcf_record_free(status->current_record);
    }
	goto st0;
tr80:
#line 200 "vcf_v41.ragel"
	{
 //       printf("Line %zu (%s): Error in 'quality' field\n", status->num_batches * batch_size + status->num_records, file->filename);
 //       vcf_record_free(status->current_record);
    }
	goto st0;
tr84:
#line 213 "vcf_v41.ragel"
	{
 //       printf("Line %zu (%s): Error in 'filter' field\n", status->num_batches * batch_size + status->num_records, file->filename);
 //       vcf_record_free(status->current_record);
    }
	goto st0;
tr89:
#line 226 "vcf_v41.ragel"
	{
//        printf("Line %zu (%s): Error in 'info' field\n", status->num_batches * batch_size + status->num_records, file->filename);
 //       vcf_record_free(status->current_record);
    }
	goto st0;
tr95:
#line 239 "vcf_v41.ragel"
	{
 //       printf("Line %zu (%s): Error in 'format' field\n", status->num_batches * batch_size + status->num_records, file->filename);
 //       vcf_record_free(status->current_record);
    }
	goto st0;
tr100:
#line 252 "vcf_v41.ragel"
	{
//        printf("Line %zu (%s): Error in sample\n", status->num_batches * batch_size + status->num_records, file->filename);
//        vcf_record_free(status->current_record);
    }
	goto st0;
tr169:
#line 29 "vcf_v41.ragel"
	{
//        printf("Line %d (%s): Error in file format\n", lines, file->filename);
    }
	goto st0;
#line 143 "vcf_ragel.cpp"
st0:
cs = 0;
	goto _out;
tr171:
#line 25 "vcf_v41.ragel"
	{
//        set_vcf_file_format(ts, p-ts, file);
    }
#line 16 "vcf_v41.ragel"
	{
        lines++;
//        LOG_INFO_F("lines read = %d\n", lines);
    }
#line 57 "vcf_v41.ragel"
	{
/*        if (*ts == '<') {
            add_vcf_header_entry_value(ts+1, p-ts-1, status->current_header_entry);
        } else if (*(p-1) == '>') {
            add_vcf_header_entry_value(ts, p-ts-1, status->current_header_entry);
        } else {
            add_vcf_header_entry_value(ts, p-ts, status->current_header_entry);
        }*/
    }
#line 37 "vcf_v41.ragel"
	{
//        add_vcf_header_entry(status->current_header_entry, file);
    }
	goto st144;
st144:
	if ( ++p == pe )
		goto _test_eof144;
case 144:
#line 176 "vcf_ragel.cpp"
	switch( (*p) ) {
		case 10: goto st144;
		case 35: goto tr179;
		case 44: goto tr178;
		case 46: goto tr178;
		case 95: goto tr178;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr178;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr178;
	} else
		goto tr178;
	goto tr55;
tr179:
#line 33 "vcf_v41.ragel"
	{
//        status->current_header_entry = vcf_header_entry_new();
    }
	goto st1;
st1:
	if ( ++p == pe )
		goto _test_eof1;
case 1:
#line 203 "vcf_ragel.cpp"
	switch( (*p) ) {
		case 35: goto st2;
		case 67: goto st5;
	}
	goto st0;
st2:
	if ( ++p == pe )
		goto _test_eof2;
case 2:
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto tr3;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr3;
		} else
			goto tr4;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr3;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr3;
		} else
			goto tr4;
	} else
		goto tr4;
	goto st0;
tr3:
#line 53 "vcf_v41.ragel"
	{
        ts = p;
    }
	goto st3;
st3:
	if ( ++p == pe )
		goto _test_eof3;
case 3:
#line 244 "vcf_ragel.cpp"
	if ( (*p) == 10 )
		goto tr5;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto st3;
	goto st0;
tr5:
#line 57 "vcf_v41.ragel"
	{
/*        if (*ts == '<') {
            add_vcf_header_entry_value(ts+1, p-ts-1, status->current_header_entry);
        } else if (*(p-1) == '>') {
            add_vcf_header_entry_value(ts, p-ts-1, status->current_header_entry);
        } else {
            add_vcf_header_entry_value(ts, p-ts, status->current_header_entry);
        }*/
    }
#line 37 "vcf_v41.ragel"
	{
//        add_vcf_header_entry(status->current_header_entry, file);
    }
#line 16 "vcf_v41.ragel"
	{
        lines++;
//        LOG_INFO_F("lines read = %d\n", lines);
    }
	goto st145;
st145:
	if ( ++p == pe )
		goto _test_eof145;
case 145:
#line 275 "vcf_ragel.cpp"
	switch( (*p) ) {
		case 10: goto st146;
		case 35: goto tr179;
		case 44: goto tr178;
		case 46: goto tr178;
		case 95: goto tr178;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr178;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr178;
	} else
		goto tr178;
	goto tr55;
st146:
	if ( ++p == pe )
		goto _test_eof146;
case 146:
	switch( (*p) ) {
		case 10: goto st146;
		case 35: goto st4;
		case 44: goto tr178;
		case 46: goto tr178;
		case 95: goto tr178;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr178;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr178;
	} else
		goto tr178;
	goto tr55;
st4:
	if ( ++p == pe )
		goto _test_eof4;
case 4:
	if ( (*p) == 67 )
		goto st5;
	goto st0;
st5:
	if ( ++p == pe )
		goto _test_eof5;
case 5:
	if ( (*p) == 72 )
		goto st6;
	goto st0;
st6:
	if ( ++p == pe )
		goto _test_eof6;
case 6:
	if ( (*p) == 82 )
		goto st7;
	goto st0;
st7:
	if ( ++p == pe )
		goto _test_eof7;
case 7:
	if ( (*p) == 79 )
		goto st8;
	goto st0;
st8:
	if ( ++p == pe )
		goto _test_eof8;
case 8:
	if ( (*p) == 77 )
		goto st9;
	goto st0;
st9:
	if ( ++p == pe )
		goto _test_eof9;
case 9:
	if ( (*p) == 9 )
		goto st10;
	goto st0;
st10:
	if ( ++p == pe )
		goto _test_eof10;
case 10:
	if ( (*p) == 80 )
		goto st11;
	goto st0;
st11:
	if ( ++p == pe )
		goto _test_eof11;
case 11:
	if ( (*p) == 79 )
		goto st12;
	goto st0;
st12:
	if ( ++p == pe )
		goto _test_eof12;
case 12:
	if ( (*p) == 83 )
		goto st13;
	goto st0;
st13:
	if ( ++p == pe )
		goto _test_eof13;
case 13:
	if ( (*p) == 9 )
		goto st14;
	goto st0;
st14:
	if ( ++p == pe )
		goto _test_eof14;
case 14:
	if ( (*p) == 73 )
		goto st15;
	goto st0;
st15:
	if ( ++p == pe )
		goto _test_eof15;
case 15:
	if ( (*p) == 68 )
		goto st16;
	goto st0;
st16:
	if ( ++p == pe )
		goto _test_eof16;
case 16:
	if ( (*p) == 9 )
		goto st17;
	goto st0;
st17:
	if ( ++p == pe )
		goto _test_eof17;
case 17:
	if ( (*p) == 82 )
		goto st18;
	goto st0;
st18:
	if ( ++p == pe )
		goto _test_eof18;
case 18:
	if ( (*p) == 69 )
		goto st19;
	goto st0;
st19:
	if ( ++p == pe )
		goto _test_eof19;
case 19:
	if ( (*p) == 70 )
		goto st20;
	goto st0;
st20:
	if ( ++p == pe )
		goto _test_eof20;
case 20:
	if ( (*p) == 9 )
		goto st21;
	goto st0;
st21:
	if ( ++p == pe )
		goto _test_eof21;
case 21:
	if ( (*p) == 65 )
		goto st22;
	goto st0;
st22:
	if ( ++p == pe )
		goto _test_eof22;
case 22:
	if ( (*p) == 76 )
		goto st23;
	goto st0;
st23:
	if ( ++p == pe )
		goto _test_eof23;
case 23:
	if ( (*p) == 84 )
		goto st24;
	goto st0;
st24:
	if ( ++p == pe )
		goto _test_eof24;
case 24:
	if ( (*p) == 9 )
		goto st25;
	goto st0;
st25:
	if ( ++p == pe )
		goto _test_eof25;
case 25:
	if ( (*p) == 81 )
		goto st26;
	goto st0;
st26:
	if ( ++p == pe )
		goto _test_eof26;
case 26:
	if ( (*p) == 85 )
		goto st27;
	goto st0;
st27:
	if ( ++p == pe )
		goto _test_eof27;
case 27:
	if ( (*p) == 65 )
		goto st28;
	goto st0;
st28:
	if ( ++p == pe )
		goto _test_eof28;
case 28:
	if ( (*p) == 76 )
		goto st29;
	goto st0;
st29:
	if ( ++p == pe )
		goto _test_eof29;
case 29:
	if ( (*p) == 9 )
		goto st30;
	goto st0;
st30:
	if ( ++p == pe )
		goto _test_eof30;
case 30:
	if ( (*p) == 70 )
		goto st31;
	goto st0;
st31:
	if ( ++p == pe )
		goto _test_eof31;
case 31:
	if ( (*p) == 73 )
		goto st32;
	goto st0;
st32:
	if ( ++p == pe )
		goto _test_eof32;
case 32:
	if ( (*p) == 76 )
		goto st33;
	goto st0;
st33:
	if ( ++p == pe )
		goto _test_eof33;
case 33:
	if ( (*p) == 84 )
		goto st34;
	goto st0;
st34:
	if ( ++p == pe )
		goto _test_eof34;
case 34:
	if ( (*p) == 69 )
		goto st35;
	goto st0;
st35:
	if ( ++p == pe )
		goto _test_eof35;
case 35:
	if ( (*p) == 82 )
		goto st36;
	goto st0;
st36:
	if ( ++p == pe )
		goto _test_eof36;
case 36:
	if ( (*p) == 9 )
		goto st37;
	goto st0;
st37:
	if ( ++p == pe )
		goto _test_eof37;
case 37:
	if ( (*p) == 73 )
		goto st38;
	goto st0;
st38:
	if ( ++p == pe )
		goto _test_eof38;
case 38:
	if ( (*p) == 78 )
		goto st39;
	goto st0;
st39:
	if ( ++p == pe )
		goto _test_eof39;
case 39:
	if ( (*p) == 70 )
		goto st40;
	goto st0;
st40:
	if ( ++p == pe )
		goto _test_eof40;
case 40:
	if ( (*p) == 79 )
		goto st41;
	goto st0;
st41:
	if ( ++p == pe )
		goto _test_eof41;
case 41:
	if ( (*p) == 9 )
		goto st42;
	goto st0;
st42:
	if ( ++p == pe )
		goto _test_eof42;
case 42:
	if ( (*p) == 70 )
		goto st43;
	goto st0;
st43:
	if ( ++p == pe )
		goto _test_eof43;
case 43:
	if ( (*p) == 79 )
		goto st44;
	goto st0;
st44:
	if ( ++p == pe )
		goto _test_eof44;
case 44:
	if ( (*p) == 82 )
		goto st45;
	goto st0;
st45:
	if ( ++p == pe )
		goto _test_eof45;
case 45:
	if ( (*p) == 77 )
		goto st46;
	goto st0;
st46:
	if ( ++p == pe )
		goto _test_eof46;
case 46:
	if ( (*p) == 65 )
		goto st47;
	goto st0;
st47:
	if ( ++p == pe )
		goto _test_eof47;
case 47:
	if ( (*p) == 84 )
		goto st48;
	goto st0;
st48:
	if ( ++p == pe )
		goto _test_eof48;
case 48:
	if ( (*p) == 9 )
		goto st49;
	goto st0;
tr52:
#line 71 "vcf_v41.ragel"
	{
//        add_vcf_sample_name(ts, p-ts, file);
    }
	goto st49;
st49:
	if ( ++p == pe )
		goto _test_eof49;
case 49:
#line 637 "vcf_ragel.cpp"
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr51;
	goto st0;
tr51:
#line 67 "vcf_v41.ragel"
	{
        ts = p;
    }
	goto st50;
st50:
	if ( ++p == pe )
		goto _test_eof50;
case 50:
#line 651 "vcf_ragel.cpp"
	switch( (*p) ) {
		case 9: goto tr52;
		case 10: goto tr53;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto st50;
	goto st0;
tr53:
#line 71 "vcf_v41.ragel"
	{
//        add_vcf_sample_name(ts, p-ts, file);
    }
#line 16 "vcf_v41.ragel"
	{
        lines++;
//        LOG_INFO_F("lines read = %d\n", lines);
    }
	goto st147;
st147:
	if ( ++p == pe )
		goto _test_eof147;
case 147:
#line 674 "vcf_ragel.cpp"
	switch( (*p) ) {
		case 10: goto st147;
		case 44: goto tr178;
		case 46: goto tr178;
		case 95: goto tr178;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr178;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr178;
	} else
		goto tr178;
	goto tr55;
tr178:
#line 75 "vcf_v41.ragel"
	{
//        status->current_record = vcf_record_new();
    }
#line 103 "vcf_v41.ragel"
	{
        ts = p;
    }
	goto st51;
st51:
	if ( ++p == pe )
		goto _test_eof51;
case 51:
#line 704 "vcf_ragel.cpp"
	switch( (*p) ) {
		case 9: goto tr56;
		case 44: goto st51;
		case 46: goto st51;
		case 95: goto st51;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st51;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st51;
	} else
		goto st51;
	goto tr55;
tr56:
#line 107 "vcf_v41.ragel"
	{
//        set_vcf_record_chromosome(ts, p-ts, status->current_record);
    }
	goto st52;
st52:
	if ( ++p == pe )
		goto _test_eof52;
case 52:
#line 730 "vcf_ragel.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr59;
	goto tr58;
tr59:
#line 116 "vcf_v41.ragel"
	{
        ts = p;
    }
	goto st53;
st53:
	if ( ++p == pe )
		goto _test_eof53;
case 53:
#line 744 "vcf_ragel.cpp"
	if ( (*p) == 9 )
		goto tr60;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st53;
	goto tr58;
tr60:
#line 120 "vcf_v41.ragel"
	{
//        char *field = strndup(ts, p-ts);
 //       set_vcf_record_position(atol(field), status->current_record);
 //       free(field);
    }
	goto st54;
st54:
	if ( ++p == pe )
		goto _test_eof54;
case 54:
#line 762 "vcf_ragel.cpp"
	switch( (*p) ) {
		case 46: goto tr63;
		case 95: goto tr64;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr64;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr64;
	} else
		goto tr64;
	goto tr62;
tr63:
#line 131 "vcf_v41.ragel"
	{
        ts = p;
    }
	goto st55;
st55:
	if ( ++p == pe )
		goto _test_eof55;
case 55:
#line 786 "vcf_ragel.cpp"
	if ( (*p) == 9 )
		goto tr65;
	goto tr62;
tr65:
#line 135 "vcf_v41.ragel"
	{
//        set_vcf_record_id(ts, p-ts, status->current_record);
    }
	goto st56;
st56:
	if ( ++p == pe )
		goto _test_eof56;
case 56:
#line 800 "vcf_ragel.cpp"
	switch( (*p) ) {
		case 65: goto tr67;
		case 67: goto tr67;
		case 71: goto tr67;
		case 78: goto tr67;
		case 84: goto tr67;
	}
	goto tr66;
tr67:
#line 144 "vcf_v41.ragel"
	{
 //       ts = p;
    }
	goto st57;
st57:
	if ( ++p == pe )
		goto _test_eof57;
case 57:
#line 819 "vcf_ragel.cpp"
	switch( (*p) ) {
		case 9: goto tr68;
		case 65: goto st57;
		case 67: goto st57;
		case 71: goto st57;
		case 78: goto st57;
		case 84: goto st57;
	}
	goto tr66;
tr68:
#line 148 "vcf_v41.ragel"
	{
 //       set_vcf_record_reference(ts, p-ts, status->current_record);
    }
	goto st58;
st58:
	if ( ++p == pe )
		goto _test_eof58;
case 58:
#line 839 "vcf_ragel.cpp"
	switch( (*p) ) {
		case 46: goto tr71;
		case 48: goto tr72;
		case 60: goto tr73;
		case 65: goto tr74;
		case 67: goto tr74;
		case 71: goto tr74;
		case 78: goto tr74;
		case 84: goto tr74;
		case 91: goto tr75;
		case 93: goto tr76;
	}
	goto tr70;
tr71:
#line 157 "vcf_v41.ragel"
	{
        ts = p;
    }
	goto st59;
st59:
	if ( ++p == pe )
		goto _test_eof59;
case 59:
#line 863 "vcf_ragel.cpp"
	switch( (*p) ) {
		case 9: goto tr77;
		case 44: goto st78;
		case 46: goto st59;
		case 65: goto st59;
		case 67: goto st59;
		case 71: goto st59;
		case 78: goto st59;
		case 84: goto st59;
	}
	goto tr70;
tr77:
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
	goto st60;
tr114:
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
	goto st60;
tr138:
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
	goto st60;
st60:
	if ( ++p == pe )
		goto _test_eof60;
case 60:
#line 921 "vcf_ragel.cpp"
	if ( (*p) == 46 )
		goto tr81;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr82;
	goto tr80;
tr81:
#line 186 "vcf_v41.ragel"
	{
        ts = p;
    }
	goto st61;
st61:
	if ( ++p == pe )
		goto _test_eof61;
case 61:
#line 937 "vcf_ragel.cpp"
	if ( (*p) == 9 )
		goto tr83;
	goto tr80;
tr83:
#line 190 "vcf_v41.ragel"
	{
/*        float quality = -1.0f;
        if (strncmp(".", ts, 1) != 0) {
            char *field = strndup(ts, p-ts);
            quality = atof(field);
            free(field);
        }
        set_vcf_record_quality(quality, status->current_record);*/
    }
	goto st62;
st62:
	if ( ++p == pe )
		goto _test_eof62;
case 62:
#line 957 "vcf_ragel.cpp"
	switch( (*p) ) {
		case 44: goto tr85;
		case 46: goto tr85;
		case 95: goto tr85;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr85;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr85;
	} else
		goto tr85;
	goto tr84;
tr85:
#line 205 "vcf_v41.ragel"
	{
        ts = p;
    }
	goto st63;
st63:
	if ( ++p == pe )
		goto _test_eof63;
case 63:
#line 982 "vcf_ragel.cpp"
	switch( (*p) ) {
		case 9: goto tr86;
		case 44: goto st63;
		case 46: goto st63;
		case 59: goto st74;
		case 95: goto st63;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st63;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st63;
	} else
		goto st63;
	goto tr84;
tr86:
#line 209 "vcf_v41.ragel"
	{
 //       set_vcf_record_filter(ts, p-ts, status->current_record);
    }
	goto st64;
st64:
	if ( ++p == pe )
		goto _test_eof64;
case 64:
#line 1009 "vcf_ragel.cpp"
	switch( (*p) ) {
		case 46: goto tr90;
		case 95: goto tr91;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr91;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr91;
	} else
		goto tr91;
	goto tr89;
tr90:
#line 218 "vcf_v41.ragel"
	{
        ts = p;
    }
	goto st65;
st65:
	if ( ++p == pe )
		goto _test_eof65;
case 65:
#line 1033 "vcf_ragel.cpp"
	switch( (*p) ) {
		case 9: goto tr92;
		case 59: goto st70;
		case 61: goto st72;
	}
	goto tr89;
tr92:
#line 222 "vcf_v41.ragel"
	{
//        set_vcf_record_info(ts, p-ts, status->current_record);
    }
	goto st66;
st66:
	if ( ++p == pe )
		goto _test_eof66;
case 66:
#line 1050 "vcf_ragel.cpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr96;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr96;
	} else
		goto tr96;
	goto tr95;
tr96:
#line 231 "vcf_v41.ragel"
	{
        ts = p;
    }
	goto st67;
st67:
	if ( ++p == pe )
		goto _test_eof67;
case 67:
#line 1070 "vcf_ragel.cpp"
	switch( (*p) ) {
		case 9: goto tr97;
		case 58: goto st69;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st67;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st67;
	} else
		goto st67;
	goto tr95;
tr97:
#line 235 "vcf_v41.ragel"
	{
 //       set_vcf_record_format(ts, p-ts, status->current_record);
    }
	goto st68;
tr183:
#line 248 "vcf_v41.ragel"
	{
//        add_vcf_record_sample(ts, p-ts, status->current_record);
    }
	goto st68;
st68:
	if ( ++p == pe )
		goto _test_eof68;
case 68:
#line 1100 "vcf_ragel.cpp"
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr101;
	goto tr100;
tr101:
#line 244 "vcf_v41.ragel"
	{
        ts = p;
    }
	goto st148;
st148:
	if ( ++p == pe )
		goto _test_eof148;
case 148:
#line 1114 "vcf_ragel.cpp"
	switch( (*p) ) {
		case 9: goto tr183;
		case 10: goto tr184;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st148;
	goto tr100;
tr184:
#line 248 "vcf_v41.ragel"
	{
//        add_vcf_record_sample(ts, p-ts, status->current_record);
    }
#line 79 "vcf_v41.ragel"
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
#line 16 "vcf_v41.ragel"
	{
        lines++;
//        LOG_INFO_F("lines read = %d\n", lines);
    }
	goto st149;
st149:
	if ( ++p == pe )
		goto _test_eof149;
case 149:
#line 1161 "vcf_ragel.cpp"
	switch( (*p) ) {
		case 10: goto st150;
		case 44: goto tr178;
		case 46: goto tr178;
		case 95: goto tr178;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr178;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr178;
	} else
		goto tr178;
	goto tr55;
st150:
	if ( ++p == pe )
		goto _test_eof150;
case 150:
	if ( (*p) == 10 )
		goto st150;
	goto st0;
st69:
	if ( ++p == pe )
		goto _test_eof69;
case 69:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st67;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st67;
	} else
		goto st67;
	goto tr95;
st70:
	if ( ++p == pe )
		goto _test_eof70;
case 70:
	switch( (*p) ) {
		case 46: goto st65;
		case 95: goto st71;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st71;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st71;
	} else
		goto st71;
	goto tr89;
tr91:
#line 218 "vcf_v41.ragel"
	{
        ts = p;
    }
	goto st71;
st71:
	if ( ++p == pe )
		goto _test_eof71;
case 71:
#line 1224 "vcf_ragel.cpp"
	switch( (*p) ) {
		case 9: goto tr92;
		case 59: goto st70;
		case 61: goto st72;
		case 95: goto st71;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st71;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st71;
	} else
		goto st71;
	goto tr89;
st72:
	if ( ++p == pe )
		goto _test_eof72;
case 72:
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st73;
	goto tr89;
st73:
	if ( ++p == pe )
		goto _test_eof73;
case 73:
	if ( (*p) == 9 )
		goto tr92;
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st73;
	goto tr89;
st74:
	if ( ++p == pe )
		goto _test_eof74;
case 74:
	switch( (*p) ) {
		case 44: goto st63;
		case 46: goto st63;
		case 95: goto st63;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st63;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st63;
	} else
		goto st63;
	goto tr84;
tr82:
#line 186 "vcf_v41.ragel"
	{
        ts = p;
    }
	goto st75;
st75:
	if ( ++p == pe )
		goto _test_eof75;
case 75:
#line 1284 "vcf_ragel.cpp"
	switch( (*p) ) {
		case 9: goto tr83;
		case 46: goto st76;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st75;
	goto tr80;
st76:
	if ( ++p == pe )
		goto _test_eof76;
case 76:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st77;
	goto tr80;
st77:
	if ( ++p == pe )
		goto _test_eof77;
case 77:
	if ( (*p) == 9 )
		goto tr83;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st77;
	goto tr80;
st78:
	if ( ++p == pe )
		goto _test_eof78;
case 78:
	switch( (*p) ) {
		case 46: goto st59;
		case 65: goto st59;
		case 67: goto st59;
		case 71: goto st59;
		case 78: goto st59;
		case 84: goto st59;
	}
	goto tr70;
tr72:
#line 157 "vcf_v41.ragel"
	{
        ts = p;
    }
	goto st79;
st79:
	if ( ++p == pe )
		goto _test_eof79;
case 79:
#line 1331 "vcf_ragel.cpp"
	if ( (*p) == 9 )
		goto tr77;
	goto tr70;
tr73:
#line 157 "vcf_v41.ragel"
	{
        ts = p;
    }
	goto st80;
st80:
	if ( ++p == pe )
		goto _test_eof80;
case 80:
#line 1345 "vcf_ragel.cpp"
	switch( (*p) ) {
		case 67: goto st81;
		case 68: goto st85;
		case 73: goto st101;
	}
	goto tr70;
st81:
	if ( ++p == pe )
		goto _test_eof81;
case 81:
	if ( (*p) == 78 )
		goto st82;
	goto tr70;
st82:
	if ( ++p == pe )
		goto _test_eof82;
case 82:
	if ( (*p) == 86 )
		goto st83;
	goto tr70;
st83:
	if ( ++p == pe )
		goto _test_eof83;
case 83:
	if ( (*p) == 62 )
		goto st84;
	goto tr70;
st84:
	if ( ++p == pe )
		goto _test_eof84;
case 84:
	if ( (*p) == 9 )
		goto tr114;
	goto tr70;
st85:
	if ( ++p == pe )
		goto _test_eof85;
case 85:
	switch( (*p) ) {
		case 69: goto st86;
		case 85: goto st93;
	}
	goto tr70;
st86:
	if ( ++p == pe )
		goto _test_eof86;
case 86:
	if ( (*p) == 76 )
		goto st87;
	goto tr70;
st87:
	if ( ++p == pe )
		goto _test_eof87;
case 87:
	switch( (*p) ) {
		case 58: goto st88;
		case 62: goto st84;
	}
	goto tr70;
st88:
	if ( ++p == pe )
		goto _test_eof88;
case 88:
	if ( (*p) == 77 )
		goto st89;
	goto tr70;
st89:
	if ( ++p == pe )
		goto _test_eof89;
case 89:
	if ( (*p) == 69 )
		goto st90;
	goto tr70;
st90:
	if ( ++p == pe )
		goto _test_eof90;
case 90:
	if ( (*p) == 58 )
		goto st91;
	goto tr70;
st91:
	if ( ++p == pe )
		goto _test_eof91;
case 91:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st92;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st92;
	} else
		goto st92;
	goto tr70;
st92:
	if ( ++p == pe )
		goto _test_eof92;
case 92:
	if ( (*p) == 62 )
		goto st84;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st92;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st92;
	} else
		goto st92;
	goto tr70;
st93:
	if ( ++p == pe )
		goto _test_eof93;
case 93:
	if ( (*p) == 80 )
		goto st94;
	goto tr70;
st94:
	if ( ++p == pe )
		goto _test_eof94;
case 94:
	switch( (*p) ) {
		case 58: goto st95;
		case 62: goto st84;
	}
	goto tr70;
st95:
	if ( ++p == pe )
		goto _test_eof95;
case 95:
	if ( (*p) == 84 )
		goto st96;
	goto tr70;
st96:
	if ( ++p == pe )
		goto _test_eof96;
case 96:
	if ( (*p) == 65 )
		goto st97;
	goto tr70;
st97:
	if ( ++p == pe )
		goto _test_eof97;
case 97:
	if ( (*p) == 78 )
		goto st98;
	goto tr70;
st98:
	if ( ++p == pe )
		goto _test_eof98;
case 98:
	if ( (*p) == 68 )
		goto st99;
	goto tr70;
st99:
	if ( ++p == pe )
		goto _test_eof99;
case 99:
	if ( (*p) == 69 )
		goto st100;
	goto tr70;
st100:
	if ( ++p == pe )
		goto _test_eof100;
case 100:
	if ( (*p) == 77 )
		goto st83;
	goto tr70;
st101:
	if ( ++p == pe )
		goto _test_eof101;
case 101:
	if ( (*p) == 78 )
		goto st102;
	goto tr70;
st102:
	if ( ++p == pe )
		goto _test_eof102;
case 102:
	switch( (*p) ) {
		case 83: goto st87;
		case 86: goto st83;
	}
	goto tr70;
tr74:
#line 157 "vcf_v41.ragel"
	{
        ts = p;
    }
	goto st103;
st103:
	if ( ++p == pe )
		goto _test_eof103;
case 103:
#line 1538 "vcf_ragel.cpp"
	switch( (*p) ) {
		case 9: goto tr77;
		case 44: goto st78;
		case 46: goto st59;
		case 65: goto st103;
		case 67: goto st103;
		case 71: goto st103;
		case 78: goto st103;
		case 84: goto st103;
		case 91: goto st104;
		case 93: goto st109;
	}
	goto tr70;
st104:
	if ( ++p == pe )
		goto _test_eof104;
case 104:
	switch( (*p) ) {
		case 44: goto st105;
		case 46: goto st105;
		case 95: goto st105;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st105;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st105;
	} else
		goto st105;
	goto tr70;
st105:
	if ( ++p == pe )
		goto _test_eof105;
case 105:
	switch( (*p) ) {
		case 44: goto st105;
		case 46: goto st105;
		case 58: goto st106;
		case 95: goto st105;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st105;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st105;
	} else
		goto st105;
	goto tr70;
st106:
	if ( ++p == pe )
		goto _test_eof106;
case 106:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st107;
	goto tr70;
st107:
	if ( ++p == pe )
		goto _test_eof107;
case 107:
	if ( (*p) == 91 )
		goto st108;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st107;
	goto tr70;
st108:
	if ( ++p == pe )
		goto _test_eof108;
case 108:
	if ( (*p) == 9 )
		goto tr138;
	goto tr70;
st109:
	if ( ++p == pe )
		goto _test_eof109;
case 109:
	switch( (*p) ) {
		case 44: goto st110;
		case 46: goto st110;
		case 95: goto st110;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st110;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st110;
	} else
		goto st110;
	goto tr70;
st110:
	if ( ++p == pe )
		goto _test_eof110;
case 110:
	switch( (*p) ) {
		case 44: goto st110;
		case 46: goto st110;
		case 58: goto st111;
		case 95: goto st110;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st110;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st110;
	} else
		goto st110;
	goto tr70;
st111:
	if ( ++p == pe )
		goto _test_eof111;
case 111:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st112;
	goto tr70;
st112:
	if ( ++p == pe )
		goto _test_eof112;
case 112:
	if ( (*p) == 93 )
		goto st108;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st112;
	goto tr70;
tr75:
#line 157 "vcf_v41.ragel"
	{
        ts = p;
    }
	goto st113;
st113:
	if ( ++p == pe )
		goto _test_eof113;
case 113:
#line 1675 "vcf_ragel.cpp"
	switch( (*p) ) {
		case 44: goto st114;
		case 46: goto st114;
		case 95: goto st114;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st114;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st114;
	} else
		goto st114;
	goto tr70;
st114:
	if ( ++p == pe )
		goto _test_eof114;
case 114:
	switch( (*p) ) {
		case 44: goto st114;
		case 46: goto st114;
		case 58: goto st115;
		case 95: goto st114;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st114;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st114;
	} else
		goto st114;
	goto tr70;
st115:
	if ( ++p == pe )
		goto _test_eof115;
case 115:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st116;
	goto tr70;
st116:
	if ( ++p == pe )
		goto _test_eof116;
case 116:
	if ( (*p) == 91 )
		goto st117;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st116;
	goto tr70;
st117:
	if ( ++p == pe )
		goto _test_eof117;
case 117:
	switch( (*p) ) {
		case 65: goto st118;
		case 67: goto st118;
		case 71: goto st118;
		case 78: goto st118;
		case 84: goto st118;
	}
	goto tr70;
st118:
	if ( ++p == pe )
		goto _test_eof118;
case 118:
	switch( (*p) ) {
		case 9: goto tr138;
		case 65: goto st118;
		case 67: goto st118;
		case 71: goto st118;
		case 78: goto st118;
		case 84: goto st118;
	}
	goto tr70;
tr76:
#line 157 "vcf_v41.ragel"
	{
        ts = p;
    }
	goto st119;
st119:
	if ( ++p == pe )
		goto _test_eof119;
case 119:
#line 1760 "vcf_ragel.cpp"
	switch( (*p) ) {
		case 44: goto st120;
		case 46: goto st120;
		case 95: goto st120;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st120;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st120;
	} else
		goto st120;
	goto tr70;
st120:
	if ( ++p == pe )
		goto _test_eof120;
case 120:
	switch( (*p) ) {
		case 44: goto st120;
		case 46: goto st120;
		case 58: goto st121;
		case 95: goto st120;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st120;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st120;
	} else
		goto st120;
	goto tr70;
st121:
	if ( ++p == pe )
		goto _test_eof121;
case 121:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st122;
	goto tr70;
st122:
	if ( ++p == pe )
		goto _test_eof122;
case 122:
	if ( (*p) == 93 )
		goto st117;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st122;
	goto tr70;
tr64:
#line 131 "vcf_v41.ragel"
	{
        ts = p;
    }
	goto st123;
st123:
	if ( ++p == pe )
		goto _test_eof123;
case 123:
#line 1820 "vcf_ragel.cpp"
	switch( (*p) ) {
		case 9: goto tr65;
		case 95: goto st123;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st123;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st123;
	} else
		goto st123;
	goto tr62;
tr4:
#line 45 "vcf_v41.ragel"
	{
        ts = p;
    }
#line 53 "vcf_v41.ragel"
	{
        ts = p;
    }
	goto st124;
st124:
	if ( ++p == pe )
		goto _test_eof124;
case 124:
#line 1848 "vcf_ragel.cpp"
	switch( (*p) ) {
		case 10: goto tr5;
		case 61: goto tr152;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st3;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st3;
		} else
			goto st124;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st3;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st3;
		} else
			goto st124;
	} else
		goto st124;
	goto st0;
tr152:
#line 49 "vcf_v41.ragel"
	{
//        set_vcf_header_entry_name(ts, p-ts, status->current_header_entry);
    }
	goto st125;
st125:
	if ( ++p == pe )
		goto _test_eof125;
case 125:
#line 1884 "vcf_ragel.cpp"
	if ( (*p) == 10 )
		goto tr5;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr153;
	goto st0;
tr153:
#line 53 "vcf_v41.ragel"
	{
        ts = p;
    }
	goto st126;
st126:
	if ( ++p == pe )
		goto _test_eof126;
case 126:
#line 1900 "vcf_ragel.cpp"
	switch( (*p) ) {
		case 10: goto tr5;
		case 44: goto tr155;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto st126;
	goto st0;
tr155:
#line 57 "vcf_v41.ragel"
	{
/*        if (*ts == '<') {
            add_vcf_header_entry_value(ts+1, p-ts-1, status->current_header_entry);
        } else if (*(p-1) == '>') {
            add_vcf_header_entry_value(ts, p-ts-1, status->current_header_entry);
        } else {
            add_vcf_header_entry_value(ts, p-ts, status->current_header_entry);
        }*/
    }
	goto st127;
tr156:
#line 57 "vcf_v41.ragel"
	{
/*        if (*ts == '<') {
            add_vcf_header_entry_value(ts+1, p-ts-1, status->current_header_entry);
        } else if (*(p-1) == '>') {
            add_vcf_header_entry_value(ts, p-ts-1, status->current_header_entry);
        } else {
            add_vcf_header_entry_value(ts, p-ts, status->current_header_entry);
        }*/
    }
#line 53 "vcf_v41.ragel"
	{
        ts = p;
    }
	goto st127;
st127:
	if ( ++p == pe )
		goto _test_eof127;
case 127:
#line 1940 "vcf_ragel.cpp"
	switch( (*p) ) {
		case 10: goto tr5;
		case 44: goto tr156;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr153;
	goto st0;
tr177:
#line 33 "vcf_v41.ragel"
	{
//        status->current_header_entry = vcf_header_entry_new();
    }
	goto st128;
st128:
	if ( ++p == pe )
		goto _test_eof128;
case 128:
#line 1958 "vcf_ragel.cpp"
	switch( (*p) ) {
		case 35: goto st129;
		case 67: goto st5;
	}
	goto st0;
st129:
	if ( ++p == pe )
		goto _test_eof129;
case 129:
	if ( (*p) == 102 )
		goto tr158;
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto tr3;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr3;
		} else
			goto tr4;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr3;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr3;
		} else
			goto tr4;
	} else
		goto tr4;
	goto st0;
tr158:
#line 45 "vcf_v41.ragel"
	{
        ts = p;
    }
#line 53 "vcf_v41.ragel"
	{
        ts = p;
    }
	goto st130;
st130:
	if ( ++p == pe )
		goto _test_eof130;
case 130:
#line 2005 "vcf_ragel.cpp"
	switch( (*p) ) {
		case 10: goto tr5;
		case 61: goto tr152;
		case 105: goto st131;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st3;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st3;
		} else
			goto st124;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st3;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st3;
		} else
			goto st124;
	} else
		goto st124;
	goto st0;
st131:
	if ( ++p == pe )
		goto _test_eof131;
case 131:
	switch( (*p) ) {
		case 10: goto tr5;
		case 61: goto tr152;
		case 108: goto st132;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st3;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st3;
		} else
			goto st124;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st3;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st3;
		} else
			goto st124;
	} else
		goto st124;
	goto st0;
st132:
	if ( ++p == pe )
		goto _test_eof132;
case 132:
	switch( (*p) ) {
		case 10: goto tr5;
		case 61: goto tr152;
		case 101: goto st133;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st3;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st3;
		} else
			goto st124;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st3;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st3;
		} else
			goto st124;
	} else
		goto st124;
	goto st0;
st133:
	if ( ++p == pe )
		goto _test_eof133;
case 133:
	switch( (*p) ) {
		case 10: goto tr5;
		case 61: goto tr152;
		case 102: goto st134;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st3;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st3;
		} else
			goto st124;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st3;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st3;
		} else
			goto st124;
	} else
		goto st124;
	goto st0;
st134:
	if ( ++p == pe )
		goto _test_eof134;
case 134:
	switch( (*p) ) {
		case 10: goto tr5;
		case 61: goto tr152;
		case 111: goto st135;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st3;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st3;
		} else
			goto st124;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st3;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st3;
		} else
			goto st124;
	} else
		goto st124;
	goto st0;
st135:
	if ( ++p == pe )
		goto _test_eof135;
case 135:
	switch( (*p) ) {
		case 10: goto tr5;
		case 61: goto tr152;
		case 114: goto st136;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st3;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st3;
		} else
			goto st124;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st3;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st3;
		} else
			goto st124;
	} else
		goto st124;
	goto st0;
st136:
	if ( ++p == pe )
		goto _test_eof136;
case 136:
	switch( (*p) ) {
		case 10: goto tr5;
		case 61: goto tr152;
		case 109: goto st137;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st3;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st3;
		} else
			goto st124;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st3;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st3;
		} else
			goto st124;
	} else
		goto st124;
	goto st0;
st137:
	if ( ++p == pe )
		goto _test_eof137;
case 137:
	switch( (*p) ) {
		case 10: goto tr5;
		case 61: goto tr152;
		case 97: goto st138;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st3;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st3;
		} else
			goto st124;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 98 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st3;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st3;
		} else
			goto st124;
	} else
		goto st124;
	goto st0;
st138:
	if ( ++p == pe )
		goto _test_eof138;
case 138:
	switch( (*p) ) {
		case 10: goto tr5;
		case 61: goto tr152;
		case 116: goto st139;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st3;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st3;
		} else
			goto st124;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st3;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st3;
		} else
			goto st124;
	} else
		goto st124;
	goto st0;
st139:
	if ( ++p == pe )
		goto _test_eof139;
case 139:
	switch( (*p) ) {
		case 10: goto tr5;
		case 61: goto tr168;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st3;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st3;
		} else
			goto st124;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st3;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st3;
		} else
			goto st124;
	} else
		goto st124;
	goto st0;
tr168:
#line 49 "vcf_v41.ragel"
	{
//        set_vcf_header_entry_name(ts, p-ts, status->current_header_entry);
    }
	goto st140;
st140:
	if ( ++p == pe )
		goto _test_eof140;
case 140:
#line 2311 "vcf_ragel.cpp"
	switch( (*p) ) {
		case 10: goto tr5;
		case 32: goto tr153;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr170;
	goto tr169;
tr174:
#line 53 "vcf_v41.ragel"
	{
        ts = p;
    }
	goto st141;
tr170:
#line 21 "vcf_v41.ragel"
	{
        ts = p;
    }
#line 53 "vcf_v41.ragel"
	{
        ts = p;
    }
	goto st141;
st141:
	if ( ++p == pe )
		goto _test_eof141;
case 141:
#line 2339 "vcf_ragel.cpp"
	switch( (*p) ) {
		case 10: goto tr171;
		case 32: goto st126;
		case 44: goto tr173;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st141;
	goto tr169;
tr173:
#line 57 "vcf_v41.ragel"
	{
/*        if (*ts == '<') {
            add_vcf_header_entry_value(ts+1, p-ts-1, status->current_header_entry);
        } else if (*(p-1) == '>') {
            add_vcf_header_entry_value(ts, p-ts-1, status->current_header_entry);
        } else {
            add_vcf_header_entry_value(ts, p-ts, status->current_header_entry);
        }*/
    }
	goto st142;
tr175:
#line 57 "vcf_v41.ragel"
	{
/*        if (*ts == '<') {
            add_vcf_header_entry_value(ts+1, p-ts-1, status->current_header_entry);
        } else if (*(p-1) == '>') {
            add_vcf_header_entry_value(ts, p-ts-1, status->current_header_entry);
        } else {
            add_vcf_header_entry_value(ts, p-ts, status->current_header_entry);
        }*/
    }
#line 53 "vcf_v41.ragel"
	{
        ts = p;
    }
	goto st142;
st142:
	if ( ++p == pe )
		goto _test_eof142;
case 142:
#line 2380 "vcf_ragel.cpp"
	switch( (*p) ) {
		case 10: goto tr171;
		case 32: goto tr153;
		case 44: goto tr175;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr174;
	goto tr169;
	}
	_test_eof144: cs = 144; goto _test_eof; 
	_test_eof1: cs = 1; goto _test_eof; 
	_test_eof2: cs = 2; goto _test_eof; 
	_test_eof3: cs = 3; goto _test_eof; 
	_test_eof145: cs = 145; goto _test_eof; 
	_test_eof146: cs = 146; goto _test_eof; 
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
	_test_eof147: cs = 147; goto _test_eof; 
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
	_test_eof148: cs = 148; goto _test_eof; 
	_test_eof149: cs = 149; goto _test_eof; 
	_test_eof150: cs = 150; goto _test_eof; 
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

	_test_eof: {}
	if ( p == eof )
	{
	switch ( cs ) {
	case 140: 
	case 141: 
	case 142: 
#line 29 "vcf_v41.ragel"
	{
//        printf("Line %d (%s): Error in file format\n", lines, file->filename);
    }
	break;
	case 51: 
#line 111 "vcf_v41.ragel"
	{
//        printf("Line %zu (%s): Error in 'chromosome' field\n", status->num_batches * batch_size + status->num_records, file->filename);
//        vcf_record_free(status->current_record);
    }
	break;
	case 52: 
	case 53: 
#line 126 "vcf_v41.ragel"
	{
//        printf("Line %zu (%s): Error in 'position' field\n", status->num_batches * batch_size + status->num_records, file->filename);
//        vcf_record_free(status->current_record);
    }
	break;
	case 54: 
	case 55: 
	case 123: 
#line 139 "vcf_v41.ragel"
	{
//        printf("Line %zu (%s): Error in 'id' field\n", status->num_batches * batch_size + status->num_records, file->filename);
 //       vcf_record_free(status->current_record);
    }
	break;
	case 56: 
	case 57: 
#line 152 "vcf_v41.ragel"
	{
//        printf("Line %zu (%s): Error in 'reference' field\n", status->num_batches * batch_size + status->num_records, file->filename);
//        vcf_record_free(status->current_record);
    }
	break;
	case 58: 
	case 59: 
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
#line 181 "vcf_v41.ragel"
	{
//        printf("Line %zu (%s): Error in 'alternate' field\n", status->num_batches * batch_size + status->num_records, file->filename);
 //       vcf_record_free(status->current_record);
    }
	break;
	case 60: 
	case 61: 
	case 75: 
	case 76: 
	case 77: 
#line 200 "vcf_v41.ragel"
	{
 //       printf("Line %zu (%s): Error in 'quality' field\n", status->num_batches * batch_size + status->num_records, file->filename);
 //       vcf_record_free(status->current_record);
    }
	break;
	case 62: 
	case 63: 
	case 74: 
#line 213 "vcf_v41.ragel"
	{
 //       printf("Line %zu (%s): Error in 'filter' field\n", status->num_batches * batch_size + status->num_records, file->filename);
 //       vcf_record_free(status->current_record);
    }
	break;
	case 64: 
	case 65: 
	case 70: 
	case 71: 
	case 72: 
	case 73: 
#line 226 "vcf_v41.ragel"
	{
//        printf("Line %zu (%s): Error in 'info' field\n", status->num_batches * batch_size + status->num_records, file->filename);
 //       vcf_record_free(status->current_record);
    }
	break;
	case 66: 
	case 67: 
	case 69: 
#line 239 "vcf_v41.ragel"
	{
 //       printf("Line %zu (%s): Error in 'format' field\n", status->num_batches * batch_size + status->num_records, file->filename);
 //       vcf_record_free(status->current_record);
    }
	break;
	case 68: 
#line 252 "vcf_v41.ragel"
	{
//        printf("Line %zu (%s): Error in sample\n", status->num_batches * batch_size + status->num_records, file->filename);
//        vcf_record_free(status->current_record);
    }
	break;
	case 148: 
#line 248 "vcf_v41.ragel"
	{
//        add_vcf_record_sample(ts, p-ts, status->current_record);
    }
#line 79 "vcf_v41.ragel"
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
	break;
#line 2715 "vcf_ragel.cpp"
	}
	}

	_out: {}
	}

#line 350 "vcf_v41.ragel"

    
//    if (!vcf_batch_is_empty(status->current_batch)) {
//        add_vcf_batch(status->current_batch, file);
//         printf("Batch added - %zu records\n", status->current_batch->records->size);
//    } else {
//        vcf_batch_free(status->current_batch);
//    }

//     printf("final state should be a minimum of %d, was %d\n",  %%{ write first_final; }%%, cs);
    return cs < 
#line 2734 "vcf_ragel.cpp"
143
#line 360 "vcf_v41.ragel"
;
}

/*
int run_vcf_parser(char *p, char *pe, size_t batch_size, vcf_file_t *file, vcf_reader_status *status) {
    int cs;
    char *ts, *te;
    int stack[4];
    int top, act;
    char *eof = pe;

    int lines = 0;
    int batches = 0;

    status->current_batch->text = p;
//     printf("ragel - batch text = '%.*s'\n", 50, status->current_batch->text);

    %%{
        write init;
        write exec;
    }%%
    
    if (!vcf_batch_is_empty(status->current_batch)) {
        add_vcf_batch(status->current_batch, file);
//         printf("Batch added - %zu records\n", status->current_batch->records->size);
    } else {
        vcf_batch_free(status->current_batch);
    }

//     printf("final state should be a minimum of %d, was %d\n",  %%{ write first_final; }%%, cs);
    return cs < %%{ write first_final; }%%;
}
*/