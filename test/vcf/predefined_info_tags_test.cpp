/**
 * Copyright 2017 EMBL - European Bioinformatics Institute
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

#include <memory>

#include "catch/catch.hpp"

#include "vcf/file_structure.hpp"
#include "vcf/error.hpp"

namespace ebi
{

    TEST_CASE("Record predefined tags checks", "[record][keyvalue]")
    {
        std::shared_ptr<vcf::Source> source{
            new vcf::Source{
                "Example VCF source",
                vcf::InputFormat::VCF_FILE_VCF | vcf::InputFormat::VCF_FILE_BGZIP,
                vcf::Version::v43,
                vcf::Ploidy{2, {{"Y", 1}}},
                {},
                { "Sample1" }}};

        SECTION("Predefined INFO tags not in meta header")
        {
            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"AA", "1,2.43"} },
                            { "GT" },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"AC", "1.89"} },
                            { "GT" },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"AC", "1,8,9"} },
                            { "GT" },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"AD", "1.43"} },
                            { "GT" },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"AD", "1,4,3"} },
                            { "GT" },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"ADF", "1.89"} },
                            { "GT" },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"ADF", "1,8,9"} },
                            { "GT" },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"ADR", "46.5"} },
                            { "GT" },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"ADR", "4,6,5"} },
                            { "GT" },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"AF", "tag"} },
                            { "GT" },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"AF", "2,3,5"} },
                            { "GT" },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"AN", "ing"} },
                            { "GT" },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"AN", "1,9"} },
                            { "GT" },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"BQ", "val"} },
                            { "GT" },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"CIGAR", "M1F2D2"} },
                            { "GT" },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"CIGAR", "M,I"} },
                            { "GT" },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"DB", "2"} },
                            { "GT" },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"DB", "0,1"} },
                            { "GT" },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"DP", "1.5"} },
                            { "GT" },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"DP", "1,5"} },
                            { "GT" },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"END", "1,8"} },
                            { "GT" },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"END", "3.45"} },
                            { "GT" },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"END", "123455"}, {"IMPRECISE", "0"} },
                            { "GT" },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_NOTHROW( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"END", "123456"}, {"IMPRECISE", "0"} },
                            { "GT" },
                            { "0|1" },
                            source} ) );

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"H2", "5"} },
                            { "GT" },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"H2", "1,0,1"} },
                            { "GT" },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"H3", "23"} },
                            { "GT" },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"H3", "0,1"} },
                            { "GT" },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"MQ", "8,9"} },
                            { "GT" },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"MQ0", "1.89"} },
                            { "GT" },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"MQ0", "1,89"} },
                            { "GT" },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"NS", "value"} },
                            { "GT" },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"NS", "5,6,7"} },
                            { "GT" },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"SOMATIC", "1.89"} },
                            { "GT" },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"SOMATIC", "1,0"} },
                            { "GT" },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"VALIDATED", "1.01"} },
                            { "GT" },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"VALIDATED", "1,0"} },
                            { "GT" },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"1000G", "9"} },
                            { "GT" },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"1000G", "9"} },
                            { "GT" },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"IMPRECISE", "9"} },
                            { "GT" },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"IMPRECISE", "1,0,1"} },
                            { "GT" },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"NOVEL", "-3"} },
                            { "GT" },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"NOVEL", "0,1"} },
                            { "GT" },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"SVTYPE", "9,5"} },
                            { "GT" },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"SVLEN", "9.89"} },
                            { "GT" },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_NOTHROW( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "ACT",
                            { "ATCTTGG" },
                            1.0,
                            { "PASS" },
                            { {"SVLEN", "4"} },
                            { "GT" },
                            { "0|1" },
                            source} ) );

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "ACT",
                            { "ATCTTGG" },
                            1.0,
                            { "PASS" },
                            { {"SVLEN", "3"} },
                            { "GT" },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "<INS>" },
                            1.0,
                            { "PASS" },
                            { {"SVLEN", "-1"} },
                            { "GT" },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "<DUP:TANDEM>" },
                            1.0,
                            { "PASS" },
                            { {"SVLEN", "-5"} },
                            { "GT" },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "<DEL>" },
                            1.0,
                            { "PASS" },
                            { {"SVLEN", "10"} },
                            { "GT" },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);


            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"CIPOS", "-1,1.45"} },
                            { "GT" },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"CIPOS", "1,2,3"} },
                            { "GT" },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"CIEND", "9,end"} },
                            { "GT" },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"CIEND", "9"} },
                            { "GT" },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"HOMLEN", "len"} },
                            { "GT" },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"MEINFO", "9,8,7"} },
                            { "GT" },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"METRANS", "9,8,7,6,5"} },
                            { "GT" },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"DGVID", "2,5"} },
                            { "GT" },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"DBVARID", "0,9"} },
                            { "GT" },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"DBRIPID", "0,1,0"} },
                            { "GT" },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"PARID", "l,en"} },
                            { "GT" },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"EVENT", "9,8,7"} },
                            { "GT" },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"CILEN", "-1.25,2.5"} },
                            { "GT" },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"CILEN", "-2,1,5"} },
                            { "GT" },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"DPADJ", "0.09"} },
                            { "GT" },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"CN", "1.10"} },
                            { "GT" },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"CN", "2,4,5"} },
                            { "GT" },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"CNADJ", "9.87"} },
                            { "GT" },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"CICN", "9.87,6.5"} },
                            { "GT" },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"CICN", "1,3,5"} },
                            { "GT" },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"CICNADJ", "9.99"} },
                            { "GT" },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);
        }
    }
}
