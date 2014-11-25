
#line 1 "vcf_v41.ragel"
#include <cstdio>
#include <string>

#include "vcf_validator.h"


#line 336 "vcf_v41.ragel"


namespace
{
  
#line 16 "vcf_validator.cpp"
static const int vcf_start = 1;
static const int vcf_first_final = 150;
static const int vcf_error = 0;

static const int vcf_en_main = 1;


#line 342 "vcf_v41.ragel"

}

namespace opencb 
{
  namespace vcf
  {
    Validator::Validator()
    : n_lines{0},
      n_batches{0}  
    {
      
#line 37 "vcf_validator.cpp"
	{
	cs = vcf_start;
	}

#line 355 "vcf_v41.ragel"

    }


    void Validator::parse_line(std::vector<char> const & line)
    {
      char const * p = &line[0];
      char const * pe = &line[0] + line.size();
      char const * eof = nullptr;

      parse_buffer(p, pe, eof);
    }

/*
    void Validator::parse_line(std::string const & line)
    {
      char const * p = line.data();
      char const * pe = line.data() + line.size();
      char const * eof = nullptr;

      parse_buffer(p, pe, eof);
    }
*/

    void Validator::end()
    {
      char const * empty = "";

      parse_buffer(empty, empty, empty);
    }

    bool Validator::is_valid() const
    {
      return cs >= 
#line 77 "vcf_validator.cpp"
150
#line 388 "vcf_v41.ragel"
;
    }

    void Validator::parse_buffer(char const * p, char const * pe, char const * eof)
    {
      char const * ts = nullptr;
      char const * te = nullptr;

      
#line 89 "vcf_validator.cpp"
	{
	if ( p == pe )
		goto _test_eof;
	switch ( cs )
	{
case 1:
	if ( (*p) == 35 )
		goto st2;
	goto st0;
tr14:
#line 26 "vcf_v41.ragel"
	{
        printf("Line %zu: Error in file format\n", n_lines);
    }
	goto st0;
tr70:
#line 115 "vcf_v41.ragel"
	{
//        printf("Line %zu: Error in 'chromosome' field\n", n_lines);
//        vcf_record_free(status->current_record);
    }
	goto st0;
tr73:
#line 130 "vcf_v41.ragel"
	{
        printf("Line %zu: Error in 'position' field\n", n_lines);
//        vcf_record_free(status->current_record);
    }
	goto st0;
tr77:
#line 143 "vcf_v41.ragel"
	{
        printf("Line %zu: Error in 'id' field\n", n_lines);
 //       vcf_record_free(status->current_record);
    }
	goto st0;
tr81:
#line 156 "vcf_v41.ragel"
	{
        printf("Line %zu: Error in 'reference' field\n", n_lines);
//        vcf_record_free(status->current_record);
    }
	goto st0;
tr85:
#line 185 "vcf_v41.ragel"
	{
        printf("Line %zu: Error in 'alternate' field\n", n_lines);
 //       vcf_record_free(status->current_record);
    }
	goto st0;
tr95:
#line 204 "vcf_v41.ragel"
	{
        printf("Line %zu: Error in 'quality' field\n", n_lines);
 //       vcf_record_free(status->current_record);
    }
	goto st0;
tr99:
#line 217 "vcf_v41.ragel"
	{
        printf("Line %zu: Error in 'filter' field\n", n_lines);
 //       vcf_record_free(status->current_record);
    }
	goto st0;
tr104:
#line 230 "vcf_v41.ragel"
	{
        printf("Line %zu: Error in 'info' field\n", n_lines);
 //       vcf_record_free(status->current_record);
    }
	goto st0;
tr110:
#line 243 "vcf_v41.ragel"
	{
        printf("Line %zu: Error in 'format' field\n", n_lines);
 //       vcf_record_free(status->current_record);
    }
	goto st0;
tr115:
#line 256 "vcf_v41.ragel"
	{
        printf("Line %zu: Error in sample\n", n_lines);
//        vcf_record_free(status->current_record);
    }
	goto st0;
#line 175 "vcf_validator.cpp"
st0:
cs = 0;
	goto _out;
st2:
	if ( ++p == pe )
		goto _test_eof2;
case 2:
	if ( (*p) == 35 )
		goto st3;
	goto st0;
st3:
	if ( ++p == pe )
		goto _test_eof3;
case 3:
	if ( (*p) == 102 )
		goto st4;
	goto st0;
st4:
	if ( ++p == pe )
		goto _test_eof4;
case 4:
	if ( (*p) == 105 )
		goto st5;
	goto st0;
st5:
	if ( ++p == pe )
		goto _test_eof5;
case 5:
	if ( (*p) == 108 )
		goto st6;
	goto st0;
st6:
	if ( ++p == pe )
		goto _test_eof6;
case 6:
	if ( (*p) == 101 )
		goto st7;
	goto st0;
st7:
	if ( ++p == pe )
		goto _test_eof7;
case 7:
	if ( (*p) == 102 )
		goto st8;
	goto st0;
st8:
	if ( ++p == pe )
		goto _test_eof8;
case 8:
	if ( (*p) == 111 )
		goto st9;
	goto st0;
st9:
	if ( ++p == pe )
		goto _test_eof9;
case 9:
	if ( (*p) == 114 )
		goto st10;
	goto st0;
st10:
	if ( ++p == pe )
		goto _test_eof10;
case 10:
	if ( (*p) == 109 )
		goto st11;
	goto st0;
st11:
	if ( ++p == pe )
		goto _test_eof11;
case 11:
	if ( (*p) == 97 )
		goto st12;
	goto st0;
st12:
	if ( ++p == pe )
		goto _test_eof12;
case 12:
	if ( (*p) == 116 )
		goto st13;
	goto st0;
st13:
	if ( ++p == pe )
		goto _test_eof13;
case 13:
	if ( (*p) == 61 )
		goto st14;
	goto st0;
st14:
	if ( ++p == pe )
		goto _test_eof14;
case 14:
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr15;
	goto tr14;
tr15:
#line 18 "vcf_v41.ragel"
	{
        ts = p;
    }
#line 13 "vcf_v41.ragel"
	{
        n_lines++;
//        LOG_INFO_F("lines read = %d\n", n_lines);
    }
	goto st15;
st15:
	if ( ++p == pe )
		goto _test_eof15;
case 15:
#line 285 "vcf_validator.cpp"
	if ( (*p) == 10 )
		goto tr16;
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st15;
	goto tr14;
tr16:
#line 22 "vcf_v41.ragel"
	{
//        set_vcf_file_format(ts, p-ts, file);
    }
	goto st16;
st16:
	if ( ++p == pe )
		goto _test_eof16;
case 16:
#line 301 "vcf_validator.cpp"
	switch( (*p) ) {
		case 10: goto st17;
		case 35: goto tr19;
	}
	goto st0;
st17:
	if ( ++p == pe )
		goto _test_eof17;
case 17:
	if ( (*p) == 35 )
		goto st18;
	goto st0;
st18:
	if ( ++p == pe )
		goto _test_eof18;
case 18:
	if ( (*p) == 67 )
		goto st19;
	goto st0;
st19:
	if ( ++p == pe )
		goto _test_eof19;
case 19:
	if ( (*p) == 72 )
		goto st20;
	goto st0;
st20:
	if ( ++p == pe )
		goto _test_eof20;
case 20:
	if ( (*p) == 82 )
		goto st21;
	goto st0;
st21:
	if ( ++p == pe )
		goto _test_eof21;
case 21:
	if ( (*p) == 79 )
		goto st22;
	goto st0;
st22:
	if ( ++p == pe )
		goto _test_eof22;
case 22:
	if ( (*p) == 77 )
		goto st23;
	goto st0;
st23:
	if ( ++p == pe )
		goto _test_eof23;
case 23:
	if ( (*p) == 9 )
		goto st24;
	goto st0;
st24:
	if ( ++p == pe )
		goto _test_eof24;
case 24:
	if ( (*p) == 80 )
		goto st25;
	goto st0;
st25:
	if ( ++p == pe )
		goto _test_eof25;
case 25:
	if ( (*p) == 79 )
		goto st26;
	goto st0;
st26:
	if ( ++p == pe )
		goto _test_eof26;
case 26:
	if ( (*p) == 83 )
		goto st27;
	goto st0;
st27:
	if ( ++p == pe )
		goto _test_eof27;
case 27:
	if ( (*p) == 9 )
		goto st28;
	goto st0;
st28:
	if ( ++p == pe )
		goto _test_eof28;
case 28:
	if ( (*p) == 73 )
		goto st29;
	goto st0;
st29:
	if ( ++p == pe )
		goto _test_eof29;
case 29:
	if ( (*p) == 68 )
		goto st30;
	goto st0;
st30:
	if ( ++p == pe )
		goto _test_eof30;
case 30:
	if ( (*p) == 9 )
		goto st31;
	goto st0;
st31:
	if ( ++p == pe )
		goto _test_eof31;
case 31:
	if ( (*p) == 82 )
		goto st32;
	goto st0;
st32:
	if ( ++p == pe )
		goto _test_eof32;
case 32:
	if ( (*p) == 69 )
		goto st33;
	goto st0;
st33:
	if ( ++p == pe )
		goto _test_eof33;
case 33:
	if ( (*p) == 70 )
		goto st34;
	goto st0;
st34:
	if ( ++p == pe )
		goto _test_eof34;
case 34:
	if ( (*p) == 9 )
		goto st35;
	goto st0;
st35:
	if ( ++p == pe )
		goto _test_eof35;
case 35:
	if ( (*p) == 65 )
		goto st36;
	goto st0;
st36:
	if ( ++p == pe )
		goto _test_eof36;
case 36:
	if ( (*p) == 76 )
		goto st37;
	goto st0;
st37:
	if ( ++p == pe )
		goto _test_eof37;
case 37:
	if ( (*p) == 84 )
		goto st38;
	goto st0;
st38:
	if ( ++p == pe )
		goto _test_eof38;
case 38:
	if ( (*p) == 9 )
		goto st39;
	goto st0;
st39:
	if ( ++p == pe )
		goto _test_eof39;
case 39:
	if ( (*p) == 81 )
		goto st40;
	goto st0;
st40:
	if ( ++p == pe )
		goto _test_eof40;
case 40:
	if ( (*p) == 85 )
		goto st41;
	goto st0;
st41:
	if ( ++p == pe )
		goto _test_eof41;
case 41:
	if ( (*p) == 65 )
		goto st42;
	goto st0;
st42:
	if ( ++p == pe )
		goto _test_eof42;
case 42:
	if ( (*p) == 76 )
		goto st43;
	goto st0;
st43:
	if ( ++p == pe )
		goto _test_eof43;
case 43:
	if ( (*p) == 9 )
		goto st44;
	goto st0;
st44:
	if ( ++p == pe )
		goto _test_eof44;
case 44:
	if ( (*p) == 70 )
		goto st45;
	goto st0;
st45:
	if ( ++p == pe )
		goto _test_eof45;
case 45:
	if ( (*p) == 73 )
		goto st46;
	goto st0;
st46:
	if ( ++p == pe )
		goto _test_eof46;
case 46:
	if ( (*p) == 76 )
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
	if ( (*p) == 69 )
		goto st49;
	goto st0;
st49:
	if ( ++p == pe )
		goto _test_eof49;
case 49:
	if ( (*p) == 82 )
		goto st50;
	goto st0;
st50:
	if ( ++p == pe )
		goto _test_eof50;
case 50:
	if ( (*p) == 9 )
		goto st51;
	goto st0;
st51:
	if ( ++p == pe )
		goto _test_eof51;
case 51:
	if ( (*p) == 73 )
		goto st52;
	goto st0;
st52:
	if ( ++p == pe )
		goto _test_eof52;
case 52:
	if ( (*p) == 78 )
		goto st53;
	goto st0;
st53:
	if ( ++p == pe )
		goto _test_eof53;
case 53:
	if ( (*p) == 70 )
		goto st54;
	goto st0;
st54:
	if ( ++p == pe )
		goto _test_eof54;
case 54:
	if ( (*p) == 79 )
		goto st55;
	goto st0;
st55:
	if ( ++p == pe )
		goto _test_eof55;
case 55:
	if ( (*p) == 9 )
		goto st56;
	goto st0;
st56:
	if ( ++p == pe )
		goto _test_eof56;
case 56:
	if ( (*p) == 70 )
		goto st57;
	goto st0;
st57:
	if ( ++p == pe )
		goto _test_eof57;
case 57:
	if ( (*p) == 79 )
		goto st58;
	goto st0;
st58:
	if ( ++p == pe )
		goto _test_eof58;
case 58:
	if ( (*p) == 82 )
		goto st59;
	goto st0;
st59:
	if ( ++p == pe )
		goto _test_eof59;
case 59:
	if ( (*p) == 77 )
		goto st60;
	goto st0;
st60:
	if ( ++p == pe )
		goto _test_eof60;
case 60:
	if ( (*p) == 65 )
		goto st61;
	goto st0;
st61:
	if ( ++p == pe )
		goto _test_eof61;
case 61:
	if ( (*p) == 84 )
		goto st62;
	goto st0;
st62:
	if ( ++p == pe )
		goto _test_eof62;
case 62:
	if ( (*p) == 9 )
		goto tr65;
	goto st0;
tr65:
#line 13 "vcf_v41.ragel"
	{
        n_lines++;
//        LOG_INFO_F("lines read = %d\n", n_lines);
    }
	goto st63;
tr67:
#line 74 "vcf_v41.ragel"
	{
//        add_vcf_sample_name(ts, p-ts, file);
    }
	goto st63;
st63:
	if ( ++p == pe )
		goto _test_eof63;
case 63:
#line 646 "vcf_validator.cpp"
	if ( 32 <= (*p) && (*p) <= 126 )
		goto tr66;
	goto st0;
tr66:
#line 70 "vcf_v41.ragel"
	{
        ts = p;
    }
	goto st64;
st64:
	if ( ++p == pe )
		goto _test_eof64;
case 64:
#line 660 "vcf_validator.cpp"
	switch( (*p) ) {
		case 9: goto tr67;
		case 10: goto tr68;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto st64;
	goto st0;
tr68:
#line 74 "vcf_v41.ragel"
	{
//        add_vcf_sample_name(ts, p-ts, file);
    }
	goto st150;
tr185:
#line 252 "vcf_v41.ragel"
	{
//        add_vcf_record_sample(ts, p-ts, status->current_record);
    }
#line 83 "vcf_v41.ragel"
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
#line 13 "vcf_v41.ragel"
	{
        n_lines++;
//        LOG_INFO_F("lines read = %d\n", n_lines);
    }
	goto st150;
st150:
	if ( ++p == pe )
		goto _test_eof150;
case 150:
#line 713 "vcf_validator.cpp"
	switch( (*p) ) {
		case 10: goto st151;
		case 44: goto tr183;
		case 46: goto tr183;
		case 95: goto tr183;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr183;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr183;
	} else
		goto tr183;
	goto tr70;
st151:
	if ( ++p == pe )
		goto _test_eof151;
case 151:
	if ( (*p) == 10 )
		goto st151;
	goto st0;
tr183:
#line 78 "vcf_v41.ragel"
	{
//        status->current_record = vcf_record_new();
        printf("Reading record\n");
    }
#line 107 "vcf_v41.ragel"
	{
        ts = p;
    }
	goto st65;
st65:
	if ( ++p == pe )
		goto _test_eof65;
case 65:
#line 751 "vcf_validator.cpp"
	switch( (*p) ) {
		case 9: goto tr71;
		case 44: goto st65;
		case 46: goto st65;
		case 95: goto st65;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st65;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st65;
	} else
		goto st65;
	goto tr70;
tr71:
#line 111 "vcf_v41.ragel"
	{
//        set_vcf_record_chromosome(ts, p-ts, status->current_record);
    }
	goto st66;
st66:
	if ( ++p == pe )
		goto _test_eof66;
case 66:
#line 777 "vcf_validator.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr74;
	goto tr73;
tr74:
#line 120 "vcf_v41.ragel"
	{
        ts = p;
    }
	goto st67;
st67:
	if ( ++p == pe )
		goto _test_eof67;
case 67:
#line 791 "vcf_validator.cpp"
	if ( (*p) == 9 )
		goto tr75;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st67;
	goto tr73;
tr75:
#line 124 "vcf_v41.ragel"
	{
//        char *field = strndup(ts, p-ts);
 //       set_vcf_record_position(atol(field), status->current_record);
 //       free(field);
    }
	goto st68;
st68:
	if ( ++p == pe )
		goto _test_eof68;
case 68:
#line 809 "vcf_validator.cpp"
	switch( (*p) ) {
		case 46: goto tr78;
		case 95: goto tr79;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr79;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr79;
	} else
		goto tr79;
	goto tr77;
tr78:
#line 135 "vcf_v41.ragel"
	{
        ts = p;
    }
	goto st69;
st69:
	if ( ++p == pe )
		goto _test_eof69;
case 69:
#line 833 "vcf_validator.cpp"
	if ( (*p) == 9 )
		goto tr80;
	goto tr77;
tr80:
#line 139 "vcf_v41.ragel"
	{
//        set_vcf_record_id(ts, p-ts, status->current_record);
    }
	goto st70;
st70:
	if ( ++p == pe )
		goto _test_eof70;
case 70:
#line 847 "vcf_validator.cpp"
	switch( (*p) ) {
		case 65: goto tr82;
		case 67: goto tr82;
		case 71: goto tr82;
		case 78: goto tr82;
		case 84: goto tr82;
	}
	goto tr81;
tr82:
#line 148 "vcf_v41.ragel"
	{
 //       ts = p;
    }
	goto st71;
st71:
	if ( ++p == pe )
		goto _test_eof71;
case 71:
#line 866 "vcf_validator.cpp"
	switch( (*p) ) {
		case 9: goto tr83;
		case 65: goto st71;
		case 67: goto st71;
		case 71: goto st71;
		case 78: goto st71;
		case 84: goto st71;
	}
	goto tr81;
tr83:
#line 152 "vcf_v41.ragel"
	{
 //       set_vcf_record_reference(ts, p-ts, status->current_record);
    }
	goto st72;
st72:
	if ( ++p == pe )
		goto _test_eof72;
case 72:
#line 886 "vcf_validator.cpp"
	switch( (*p) ) {
		case 46: goto tr86;
		case 48: goto tr87;
		case 60: goto tr88;
		case 65: goto tr89;
		case 67: goto tr89;
		case 71: goto tr89;
		case 78: goto tr89;
		case 84: goto tr89;
		case 91: goto tr90;
		case 93: goto tr91;
	}
	goto tr85;
tr86:
#line 161 "vcf_v41.ragel"
	{
        ts = p;
    }
	goto st73;
st73:
	if ( ++p == pe )
		goto _test_eof73;
case 73:
#line 910 "vcf_validator.cpp"
	switch( (*p) ) {
		case 9: goto tr92;
		case 44: goto st92;
		case 46: goto st73;
		case 65: goto st73;
		case 67: goto st73;
		case 71: goto st73;
		case 78: goto st73;
		case 84: goto st73;
	}
	goto tr85;
tr92:
#line 173 "vcf_v41.ragel"
	{ 
 //       set_vcf_record_type(VARIANT_SNV, status->current_record);
    }
#line 165 "vcf_v41.ragel"
	{
 /*       if (!strncmp("0", ts, 1)) {
            set_vcf_record_alternate(".", 1, status->current_record);
        } else {
            set_vcf_record_alternate(ts, p-ts, status->current_record);
        }*/
    }
	goto st74;
tr129:
#line 177 "vcf_v41.ragel"
	{
 //       set_vcf_record_type(VARIANT_INDEL, status->current_record);
    }
#line 165 "vcf_v41.ragel"
	{
 /*       if (!strncmp("0", ts, 1)) {
            set_vcf_record_alternate(".", 1, status->current_record);
        } else {
            set_vcf_record_alternate(ts, p-ts, status->current_record);
        }*/
    }
	goto st74;
tr153:
#line 181 "vcf_v41.ragel"
	{
 //       set_vcf_record_type(VARIANT_SV, status->current_record);
    }
#line 165 "vcf_v41.ragel"
	{
 /*       if (!strncmp("0", ts, 1)) {
            set_vcf_record_alternate(".", 1, status->current_record);
        } else {
            set_vcf_record_alternate(ts, p-ts, status->current_record);
        }*/
    }
	goto st74;
st74:
	if ( ++p == pe )
		goto _test_eof74;
case 74:
#line 968 "vcf_validator.cpp"
	if ( (*p) == 46 )
		goto tr96;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr97;
	goto tr95;
tr96:
#line 190 "vcf_v41.ragel"
	{
        ts = p;
    }
	goto st75;
st75:
	if ( ++p == pe )
		goto _test_eof75;
case 75:
#line 984 "vcf_validator.cpp"
	if ( (*p) == 9 )
		goto tr98;
	goto tr95;
tr98:
#line 194 "vcf_v41.ragel"
	{
/*        float quality = -1.0f;
        if (strncmp(".", ts, 1) != 0) {
            char *field = strndup(ts, p-ts);
            quality = atof(field);
            free(field);
        }
        set_vcf_record_quality(quality, status->current_record);*/
    }
	goto st76;
st76:
	if ( ++p == pe )
		goto _test_eof76;
case 76:
#line 1004 "vcf_validator.cpp"
	switch( (*p) ) {
		case 44: goto tr100;
		case 46: goto tr100;
		case 95: goto tr100;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr100;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr100;
	} else
		goto tr100;
	goto tr99;
tr100:
#line 209 "vcf_v41.ragel"
	{
        ts = p;
    }
	goto st77;
st77:
	if ( ++p == pe )
		goto _test_eof77;
case 77:
#line 1029 "vcf_validator.cpp"
	switch( (*p) ) {
		case 9: goto tr101;
		case 44: goto st77;
		case 46: goto st77;
		case 59: goto st88;
		case 95: goto st77;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st77;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st77;
	} else
		goto st77;
	goto tr99;
tr101:
#line 213 "vcf_v41.ragel"
	{
 //       set_vcf_record_filter(ts, p-ts, status->current_record);
    }
	goto st78;
st78:
	if ( ++p == pe )
		goto _test_eof78;
case 78:
#line 1056 "vcf_validator.cpp"
	switch( (*p) ) {
		case 46: goto tr105;
		case 95: goto tr106;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr106;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr106;
	} else
		goto tr106;
	goto tr104;
tr105:
#line 222 "vcf_v41.ragel"
	{
        ts = p;
    }
	goto st79;
st79:
	if ( ++p == pe )
		goto _test_eof79;
case 79:
#line 1080 "vcf_validator.cpp"
	switch( (*p) ) {
		case 9: goto tr107;
		case 59: goto st84;
		case 61: goto st86;
	}
	goto tr104;
tr107:
#line 226 "vcf_v41.ragel"
	{
//        set_vcf_record_info(ts, p-ts, status->current_record);
    }
	goto st80;
st80:
	if ( ++p == pe )
		goto _test_eof80;
case 80:
#line 1097 "vcf_validator.cpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr111;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr111;
	} else
		goto tr111;
	goto tr110;
tr111:
#line 235 "vcf_v41.ragel"
	{
        ts = p;
    }
	goto st81;
st81:
	if ( ++p == pe )
		goto _test_eof81;
case 81:
#line 1117 "vcf_validator.cpp"
	switch( (*p) ) {
		case 9: goto tr112;
		case 58: goto st83;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st81;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st81;
	} else
		goto st81;
	goto tr110;
tr112:
#line 239 "vcf_v41.ragel"
	{
 //       set_vcf_record_format(ts, p-ts, status->current_record);
    }
	goto st82;
tr184:
#line 252 "vcf_v41.ragel"
	{
//        add_vcf_record_sample(ts, p-ts, status->current_record);
    }
	goto st82;
st82:
	if ( ++p == pe )
		goto _test_eof82;
case 82:
#line 1147 "vcf_validator.cpp"
	if ( 33 <= (*p) && (*p) <= 126 )
		goto tr116;
	goto tr115;
tr116:
#line 248 "vcf_v41.ragel"
	{
        ts = p;
    }
	goto st152;
st152:
	if ( ++p == pe )
		goto _test_eof152;
case 152:
#line 1161 "vcf_validator.cpp"
	switch( (*p) ) {
		case 9: goto tr184;
		case 10: goto tr185;
	}
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st152;
	goto tr115;
st83:
	if ( ++p == pe )
		goto _test_eof83;
case 83:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st81;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st81;
	} else
		goto st81;
	goto tr110;
st84:
	if ( ++p == pe )
		goto _test_eof84;
case 84:
	switch( (*p) ) {
		case 46: goto st79;
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
	goto tr104;
tr106:
#line 222 "vcf_v41.ragel"
	{
        ts = p;
    }
	goto st85;
st85:
	if ( ++p == pe )
		goto _test_eof85;
case 85:
#line 1209 "vcf_validator.cpp"
	switch( (*p) ) {
		case 9: goto tr107;
		case 59: goto st84;
		case 61: goto st86;
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
	goto tr104;
st86:
	if ( ++p == pe )
		goto _test_eof86;
case 86:
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st87;
	goto tr104;
st87:
	if ( ++p == pe )
		goto _test_eof87;
case 87:
	if ( (*p) == 9 )
		goto tr107;
	if ( 33 <= (*p) && (*p) <= 126 )
		goto st87;
	goto tr104;
st88:
	if ( ++p == pe )
		goto _test_eof88;
case 88:
	switch( (*p) ) {
		case 44: goto st77;
		case 46: goto st77;
		case 95: goto st77;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st77;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st77;
	} else
		goto st77;
	goto tr99;
tr97:
#line 190 "vcf_v41.ragel"
	{
        ts = p;
    }
	goto st89;
st89:
	if ( ++p == pe )
		goto _test_eof89;
case 89:
#line 1269 "vcf_validator.cpp"
	switch( (*p) ) {
		case 9: goto tr98;
		case 46: goto st90;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st89;
	goto tr95;
st90:
	if ( ++p == pe )
		goto _test_eof90;
case 90:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st91;
	goto tr95;
st91:
	if ( ++p == pe )
		goto _test_eof91;
case 91:
	if ( (*p) == 9 )
		goto tr98;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st91;
	goto tr95;
st92:
	if ( ++p == pe )
		goto _test_eof92;
case 92:
	switch( (*p) ) {
		case 46: goto st73;
		case 65: goto st73;
		case 67: goto st73;
		case 71: goto st73;
		case 78: goto st73;
		case 84: goto st73;
	}
	goto tr85;
tr87:
#line 161 "vcf_v41.ragel"
	{
        ts = p;
    }
	goto st93;
st93:
	if ( ++p == pe )
		goto _test_eof93;
case 93:
#line 1316 "vcf_validator.cpp"
	if ( (*p) == 9 )
		goto tr92;
	goto tr85;
tr88:
#line 161 "vcf_v41.ragel"
	{
        ts = p;
    }
	goto st94;
st94:
	if ( ++p == pe )
		goto _test_eof94;
case 94:
#line 1330 "vcf_validator.cpp"
	switch( (*p) ) {
		case 67: goto st95;
		case 68: goto st99;
		case 73: goto st115;
	}
	goto tr85;
st95:
	if ( ++p == pe )
		goto _test_eof95;
case 95:
	if ( (*p) == 78 )
		goto st96;
	goto tr85;
st96:
	if ( ++p == pe )
		goto _test_eof96;
case 96:
	if ( (*p) == 86 )
		goto st97;
	goto tr85;
st97:
	if ( ++p == pe )
		goto _test_eof97;
case 97:
	if ( (*p) == 62 )
		goto st98;
	goto tr85;
st98:
	if ( ++p == pe )
		goto _test_eof98;
case 98:
	if ( (*p) == 9 )
		goto tr129;
	goto tr85;
st99:
	if ( ++p == pe )
		goto _test_eof99;
case 99:
	switch( (*p) ) {
		case 69: goto st100;
		case 85: goto st107;
	}
	goto tr85;
st100:
	if ( ++p == pe )
		goto _test_eof100;
case 100:
	if ( (*p) == 76 )
		goto st101;
	goto tr85;
st101:
	if ( ++p == pe )
		goto _test_eof101;
case 101:
	switch( (*p) ) {
		case 58: goto st102;
		case 62: goto st98;
	}
	goto tr85;
st102:
	if ( ++p == pe )
		goto _test_eof102;
case 102:
	if ( (*p) == 77 )
		goto st103;
	goto tr85;
st103:
	if ( ++p == pe )
		goto _test_eof103;
case 103:
	if ( (*p) == 69 )
		goto st104;
	goto tr85;
st104:
	if ( ++p == pe )
		goto _test_eof104;
case 104:
	if ( (*p) == 58 )
		goto st105;
	goto tr85;
st105:
	if ( ++p == pe )
		goto _test_eof105;
case 105:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st106;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st106;
	} else
		goto st106;
	goto tr85;
st106:
	if ( ++p == pe )
		goto _test_eof106;
case 106:
	if ( (*p) == 62 )
		goto st98;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st106;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st106;
	} else
		goto st106;
	goto tr85;
st107:
	if ( ++p == pe )
		goto _test_eof107;
case 107:
	if ( (*p) == 80 )
		goto st108;
	goto tr85;
st108:
	if ( ++p == pe )
		goto _test_eof108;
case 108:
	switch( (*p) ) {
		case 58: goto st109;
		case 62: goto st98;
	}
	goto tr85;
st109:
	if ( ++p == pe )
		goto _test_eof109;
case 109:
	if ( (*p) == 84 )
		goto st110;
	goto tr85;
st110:
	if ( ++p == pe )
		goto _test_eof110;
case 110:
	if ( (*p) == 65 )
		goto st111;
	goto tr85;
st111:
	if ( ++p == pe )
		goto _test_eof111;
case 111:
	if ( (*p) == 78 )
		goto st112;
	goto tr85;
st112:
	if ( ++p == pe )
		goto _test_eof112;
case 112:
	if ( (*p) == 68 )
		goto st113;
	goto tr85;
st113:
	if ( ++p == pe )
		goto _test_eof113;
case 113:
	if ( (*p) == 69 )
		goto st114;
	goto tr85;
st114:
	if ( ++p == pe )
		goto _test_eof114;
case 114:
	if ( (*p) == 77 )
		goto st97;
	goto tr85;
st115:
	if ( ++p == pe )
		goto _test_eof115;
case 115:
	if ( (*p) == 78 )
		goto st116;
	goto tr85;
st116:
	if ( ++p == pe )
		goto _test_eof116;
case 116:
	switch( (*p) ) {
		case 83: goto st101;
		case 86: goto st97;
	}
	goto tr85;
tr89:
#line 161 "vcf_v41.ragel"
	{
        ts = p;
    }
	goto st117;
st117:
	if ( ++p == pe )
		goto _test_eof117;
case 117:
#line 1523 "vcf_validator.cpp"
	switch( (*p) ) {
		case 9: goto tr92;
		case 44: goto st92;
		case 46: goto st73;
		case 65: goto st117;
		case 67: goto st117;
		case 71: goto st117;
		case 78: goto st117;
		case 84: goto st117;
		case 91: goto st118;
		case 93: goto st123;
	}
	goto tr85;
st118:
	if ( ++p == pe )
		goto _test_eof118;
case 118:
	switch( (*p) ) {
		case 44: goto st119;
		case 46: goto st119;
		case 95: goto st119;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st119;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st119;
	} else
		goto st119;
	goto tr85;
st119:
	if ( ++p == pe )
		goto _test_eof119;
case 119:
	switch( (*p) ) {
		case 44: goto st119;
		case 46: goto st119;
		case 58: goto st120;
		case 95: goto st119;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st119;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st119;
	} else
		goto st119;
	goto tr85;
st120:
	if ( ++p == pe )
		goto _test_eof120;
case 120:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st121;
	goto tr85;
st121:
	if ( ++p == pe )
		goto _test_eof121;
case 121:
	if ( (*p) == 91 )
		goto st122;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st121;
	goto tr85;
st122:
	if ( ++p == pe )
		goto _test_eof122;
case 122:
	if ( (*p) == 9 )
		goto tr153;
	goto tr85;
st123:
	if ( ++p == pe )
		goto _test_eof123;
case 123:
	switch( (*p) ) {
		case 44: goto st124;
		case 46: goto st124;
		case 95: goto st124;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st124;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st124;
	} else
		goto st124;
	goto tr85;
st124:
	if ( ++p == pe )
		goto _test_eof124;
case 124:
	switch( (*p) ) {
		case 44: goto st124;
		case 46: goto st124;
		case 58: goto st125;
		case 95: goto st124;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st124;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st124;
	} else
		goto st124;
	goto tr85;
st125:
	if ( ++p == pe )
		goto _test_eof125;
case 125:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st126;
	goto tr85;
st126:
	if ( ++p == pe )
		goto _test_eof126;
case 126:
	if ( (*p) == 93 )
		goto st122;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st126;
	goto tr85;
tr90:
#line 161 "vcf_v41.ragel"
	{
        ts = p;
    }
	goto st127;
st127:
	if ( ++p == pe )
		goto _test_eof127;
case 127:
#line 1660 "vcf_validator.cpp"
	switch( (*p) ) {
		case 44: goto st128;
		case 46: goto st128;
		case 95: goto st128;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st128;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st128;
	} else
		goto st128;
	goto tr85;
st128:
	if ( ++p == pe )
		goto _test_eof128;
case 128:
	switch( (*p) ) {
		case 44: goto st128;
		case 46: goto st128;
		case 58: goto st129;
		case 95: goto st128;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st128;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st128;
	} else
		goto st128;
	goto tr85;
st129:
	if ( ++p == pe )
		goto _test_eof129;
case 129:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st130;
	goto tr85;
st130:
	if ( ++p == pe )
		goto _test_eof130;
case 130:
	if ( (*p) == 91 )
		goto st131;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st130;
	goto tr85;
st131:
	if ( ++p == pe )
		goto _test_eof131;
case 131:
	switch( (*p) ) {
		case 65: goto st132;
		case 67: goto st132;
		case 71: goto st132;
		case 78: goto st132;
		case 84: goto st132;
	}
	goto tr85;
st132:
	if ( ++p == pe )
		goto _test_eof132;
case 132:
	switch( (*p) ) {
		case 9: goto tr153;
		case 65: goto st132;
		case 67: goto st132;
		case 71: goto st132;
		case 78: goto st132;
		case 84: goto st132;
	}
	goto tr85;
tr91:
#line 161 "vcf_v41.ragel"
	{
        ts = p;
    }
	goto st133;
st133:
	if ( ++p == pe )
		goto _test_eof133;
case 133:
#line 1745 "vcf_validator.cpp"
	switch( (*p) ) {
		case 44: goto st134;
		case 46: goto st134;
		case 95: goto st134;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st134;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st134;
	} else
		goto st134;
	goto tr85;
st134:
	if ( ++p == pe )
		goto _test_eof134;
case 134:
	switch( (*p) ) {
		case 44: goto st134;
		case 46: goto st134;
		case 58: goto st135;
		case 95: goto st134;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st134;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st134;
	} else
		goto st134;
	goto tr85;
st135:
	if ( ++p == pe )
		goto _test_eof135;
case 135:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st136;
	goto tr85;
st136:
	if ( ++p == pe )
		goto _test_eof136;
case 136:
	if ( (*p) == 93 )
		goto st131;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st136;
	goto tr85;
tr79:
#line 135 "vcf_v41.ragel"
	{
        ts = p;
    }
	goto st137;
st137:
	if ( ++p == pe )
		goto _test_eof137;
case 137:
#line 1805 "vcf_validator.cpp"
	switch( (*p) ) {
		case 9: goto tr80;
		case 95: goto st137;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st137;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st137;
	} else
		goto st137;
	goto tr77;
tr19:
#line 30 "vcf_v41.ragel"
	{
        printf("Reading header entry\n");
//        status->current_header_entry = vcf_header_entry_new();
    }
	goto st138;
st138:
	if ( ++p == pe )
		goto _test_eof138;
case 138:
#line 1830 "vcf_validator.cpp"
	if ( (*p) == 35 )
		goto st139;
	goto st0;
st139:
	if ( ++p == pe )
		goto _test_eof139;
case 139:
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto tr167;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto tr167;
		} else
			goto tr168;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto tr167;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto tr167;
		} else
			goto tr168;
	} else
		goto tr168;
	goto st0;
tr167:
#line 51 "vcf_v41.ragel"
	{
        ts = p;
    }
	goto st140;
st140:
	if ( ++p == pe )
		goto _test_eof140;
case 140:
#line 1869 "vcf_validator.cpp"
	if ( (*p) == 10 )
		goto tr169;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto st140;
	goto st0;
tr169:
#line 55 "vcf_v41.ragel"
	{
/*        if (*ts == '<') {
            add_vcf_header_entry_value(ts+1, p-ts-1, status->current_header_entry);
        } else if (*(p-1) == '>') {
            add_vcf_header_entry_value(ts, p-ts-1, status->current_header_entry);
        } else {
            add_vcf_header_entry_value(ts, p-ts, status->current_header_entry);
        }*/
    }
#line 35 "vcf_v41.ragel"
	{
//        add_vcf_header_entry(status->current_header_entry, file);
    }
	goto st141;
st141:
	if ( ++p == pe )
		goto _test_eof141;
case 141:
#line 1895 "vcf_validator.cpp"
	if ( (*p) == 35 )
		goto tr171;
	goto st0;
tr171:
#line 30 "vcf_v41.ragel"
	{
        printf("Reading header entry\n");
//        status->current_header_entry = vcf_header_entry_new();
    }
	goto st142;
st142:
	if ( ++p == pe )
		goto _test_eof142;
case 142:
#line 1910 "vcf_validator.cpp"
	switch( (*p) ) {
		case 35: goto st139;
		case 67: goto st19;
	}
	goto st0;
tr168:
#line 43 "vcf_v41.ragel"
	{
        ts = p;
    }
#line 51 "vcf_v41.ragel"
	{
        ts = p;
    }
	goto st143;
st143:
	if ( ++p == pe )
		goto _test_eof143;
case 143:
#line 1930 "vcf_validator.cpp"
	switch( (*p) ) {
		case 10: goto tr169;
		case 61: goto tr173;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st140;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st140;
		} else
			goto st143;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st140;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st140;
		} else
			goto st143;
	} else
		goto st143;
	goto st0;
tr173:
#line 47 "vcf_v41.ragel"
	{
//        set_vcf_header_entry_name(ts, p-ts, status->current_header_entry);
    }
	goto st144;
st144:
	if ( ++p == pe )
		goto _test_eof144;
case 144:
#line 1966 "vcf_validator.cpp"
	switch( (*p) ) {
		case 10: goto tr169;
		case 60: goto st145;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto st140;
	goto st0;
st145:
	if ( ++p == pe )
		goto _test_eof145;
case 145:
	if ( (*p) == 10 )
		goto tr169;
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st140;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st140;
		} else
			goto tr175;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st140;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st140;
		} else
			goto tr175;
	} else
		goto tr175;
	goto st0;
tr175:
#line 51 "vcf_v41.ragel"
	{
        ts = p;
    }
	goto st146;
st146:
	if ( ++p == pe )
		goto _test_eof146;
case 146:
#line 2011 "vcf_validator.cpp"
	switch( (*p) ) {
		case 10: goto tr169;
		case 61: goto st147;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st140;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st140;
		} else
			goto st146;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st140;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st140;
		} else
			goto st146;
	} else
		goto st146;
	goto st0;
st147:
	if ( ++p == pe )
		goto _test_eof147;
case 147:
	if ( (*p) == 10 )
		goto tr169;
	if ( 32 <= (*p) && (*p) <= 126 )
		goto st148;
	goto st0;
tr181:
#line 51 "vcf_v41.ragel"
	{
        ts = p;
    }
	goto st148;
tr180:
#line 55 "vcf_v41.ragel"
	{
/*        if (*ts == '<') {
            add_vcf_header_entry_value(ts+1, p-ts-1, status->current_header_entry);
        } else if (*(p-1) == '>') {
            add_vcf_header_entry_value(ts, p-ts-1, status->current_header_entry);
        } else {
            add_vcf_header_entry_value(ts, p-ts, status->current_header_entry);
        }*/
    }
	goto st148;
st148:
	if ( ++p == pe )
		goto _test_eof148;
case 148:
#line 2068 "vcf_validator.cpp"
	switch( (*p) ) {
		case 10: goto tr169;
		case 44: goto tr179;
		case 62: goto tr180;
	}
	if ( 32 <= (*p) && (*p) <= 126 )
		goto st148;
	goto st0;
tr179:
#line 55 "vcf_v41.ragel"
	{
/*        if (*ts == '<') {
            add_vcf_header_entry_value(ts+1, p-ts-1, status->current_header_entry);
        } else if (*(p-1) == '>') {
            add_vcf_header_entry_value(ts, p-ts-1, status->current_header_entry);
        } else {
            add_vcf_header_entry_value(ts, p-ts, status->current_header_entry);
        }*/
    }
	goto st149;
st149:
	if ( ++p == pe )
		goto _test_eof149;
case 149:
#line 2093 "vcf_validator.cpp"
	switch( (*p) ) {
		case 10: goto tr169;
		case 44: goto tr179;
		case 62: goto tr180;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 32 <= (*p) && (*p) <= 47 )
				goto st148;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st148;
		} else
			goto tr181;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st148;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st148;
		} else
			goto tr181;
	} else
		goto tr181;
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
	_test_eof150: cs = 150; goto _test_eof; 
	_test_eof151: cs = 151; goto _test_eof; 
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
	_test_eof152: cs = 152; goto _test_eof; 
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

	_test_eof: {}
	if ( p == eof )
	{
	switch ( cs ) {
	case 14: 
	case 15: 
#line 26 "vcf_v41.ragel"
	{
        printf("Line %zu: Error in file format\n", n_lines);
    }
	break;
	case 65: 
#line 115 "vcf_v41.ragel"
	{
//        printf("Line %zu: Error in 'chromosome' field\n", n_lines);
//        vcf_record_free(status->current_record);
    }
	break;
	case 66: 
	case 67: 
#line 130 "vcf_v41.ragel"
	{
        printf("Line %zu: Error in 'position' field\n", n_lines);
//        vcf_record_free(status->current_record);
    }
	break;
	case 68: 
	case 69: 
	case 137: 
#line 143 "vcf_v41.ragel"
	{
        printf("Line %zu: Error in 'id' field\n", n_lines);
 //       vcf_record_free(status->current_record);
    }
	break;
	case 70: 
	case 71: 
#line 156 "vcf_v41.ragel"
	{
        printf("Line %zu: Error in 'reference' field\n", n_lines);
//        vcf_record_free(status->current_record);
    }
	break;
	case 72: 
	case 73: 
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
#line 185 "vcf_v41.ragel"
	{
        printf("Line %zu: Error in 'alternate' field\n", n_lines);
 //       vcf_record_free(status->current_record);
    }
	break;
	case 74: 
	case 75: 
	case 89: 
	case 90: 
	case 91: 
#line 204 "vcf_v41.ragel"
	{
        printf("Line %zu: Error in 'quality' field\n", n_lines);
 //       vcf_record_free(status->current_record);
    }
	break;
	case 76: 
	case 77: 
	case 88: 
#line 217 "vcf_v41.ragel"
	{
        printf("Line %zu: Error in 'filter' field\n", n_lines);
 //       vcf_record_free(status->current_record);
    }
	break;
	case 78: 
	case 79: 
	case 84: 
	case 85: 
	case 86: 
	case 87: 
#line 230 "vcf_v41.ragel"
	{
        printf("Line %zu: Error in 'info' field\n", n_lines);
 //       vcf_record_free(status->current_record);
    }
	break;
	case 80: 
	case 81: 
	case 83: 
#line 243 "vcf_v41.ragel"
	{
        printf("Line %zu: Error in 'format' field\n", n_lines);
 //       vcf_record_free(status->current_record);
    }
	break;
	case 82: 
#line 256 "vcf_v41.ragel"
	{
        printf("Line %zu: Error in sample\n", n_lines);
//        vcf_record_free(status->current_record);
    }
	break;
	case 152: 
#line 252 "vcf_v41.ragel"
	{
//        add_vcf_record_sample(ts, p-ts, status->current_record);
    }
#line 83 "vcf_v41.ragel"
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
#line 2447 "vcf_validator.cpp"
	}
	}

	_out: {}
	}

#line 398 "vcf_v41.ragel"

    }
  }
}
