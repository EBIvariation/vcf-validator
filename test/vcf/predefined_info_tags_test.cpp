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
                            { vcf::PASS },
                            { {vcf::AA, "1,2.43"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::AC, "1.89"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::AC, "1,8,9"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::AD, "1.43"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::AD, "1,4,3"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::ADF, "1.89"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::ADF, "1,8,9"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::ADR, "46.5"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::ADR, "4,6,5"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::AF, "tag"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::AF, "2,3,5"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::AN, "ing"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::AN, "1,9"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::BQ, "val"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::CIGAR, "M1F2D2"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::CIGAR, "M,I"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::DB, "2"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::DB, "0,1"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::DP, "1.5"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::DP, "1,5"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::END, "1,8"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::END, "3.45"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::END, "123455"}, {vcf::IMPRECISE, "0"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::END, "123456"}, {vcf::IMPRECISE, "0"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::H2, "5"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::H2, "1,0,1"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::H3, "23"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::H3, "0,1"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::MQ, "8,9"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::MQ0, "1.89"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::MQ0, "1,89"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::NS, "value"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::NS, "5,6,7"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::SOMATIC, "1.89"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::SOMATIC, "1,0"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::VALIDATED, "1.01"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::VALIDATED, "1,0"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::THOUSAND_G, "9"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::THOUSAND_G, "9"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::IMPRECISE, "9"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::IMPRECISE, "1,0,1"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::NOVEL, "-3"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::NOVEL, "0,1"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::SVTYPE, "9,5"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::SVTYPE, "UNK"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::SVLEN, "9.89"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::SVLEN, "4"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::SVLEN, "3"} },
                            { vcf::GT },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_NOTHROW( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "ACTGNGCN",
                            { "ATC" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::SVLEN, "-5"} },
                            { vcf::GT },
                            { "0|1" },
                            source} ) );

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "ACTGNGCN",
                            { "ATC" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::SVLEN, "-4"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::SVLEN, "-1"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::SVLEN, "-5"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::SVLEN, "10"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::CIPOS, "-1,1.45"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::CIPOS, "1,2,3"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::CIEND, "9,end"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::CIEND, "9"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::HOMLEN, "len"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::MEINFO, "9,8,7"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::METRANS, "9,8,7,6,5"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::DGVID, "2,5"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::DBVARID, "0,9"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::DBRIPID, "0,1,0"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::PARID, "l,en"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::EVENT, "9,8,7"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::CILEN, "-1.25,2.5"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::CILEN, "-2,1,5"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::DPADJ, "0.09"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::CN, "1.10"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::CN, "2,4,5"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::CNADJ, "9.87"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::CICN, "9.87,6.5"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::CICN, "1,3,5"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::CICNADJ, "9.99"} },
                            { vcf::GT },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);
        }
    }

    TEST_CASE("Record predefined tags checks v4.4", "[record][keyvalue]")
    {
        std::shared_ptr<vcf::Source> source{
            new vcf::Source{
                "Example VCF source",
                vcf::InputFormat::VCF_FILE_VCF | vcf::InputFormat::VCF_FILE_BGZIP,
                vcf::Version::v44,
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
                            { vcf::PASS },
                            { {vcf::AA, "1,2.43"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::AC, "1.89"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::AC, "1,8,9"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::AD, "1.43"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::AD, "1,4,3"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::ADF, "1.89"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::ADF, "1,8,9"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::ADR, "46.5"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::ADR, "4,6,5"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::AF, "tag"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::AF, "2,3,5"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::AN, "ing"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::AN, "1,9"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::BQ, "val"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::CIGAR, "M1F2D2"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::CIGAR, "M,I"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::DB, "2"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::DB, "0,1"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::DP, "1.5"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::DP, "1,5"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::END, "1,8"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::END, "3.45"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::END, "123455"}, {vcf::IMPRECISE, "0"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::END, "123456"}, {vcf::IMPRECISE, "0"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::H2, "5"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::H2, "1,0,1"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::H3, "23"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::H3, "0,1"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::MQ, "8,9"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::MQ0, "1.89"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::MQ0, "1,89"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::NS, "value"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::NS, "5,6,7"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::SOMATIC, "1.89"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::SOMATIC, "1,0"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::VALIDATED, "1.01"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::VALIDATED, "1,0"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::THOUSAND_G, "9"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::THOUSAND_G, "9"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::IMPRECISE, "9"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::IMPRECISE, "1,0,1"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::NOVEL, "-3"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::NOVEL, "0,1"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::SVTYPE, "9,5"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::SVTYPE, "UNK"} },
                            { vcf::GT },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{  //invalid, svlen float type
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::SVLEN, "9.89"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::SVLEN, "."} },
                            { vcf::GT },
                            { "0|1" },
                            source} ) );

            CHECK_NOTHROW( (vcf::Record{  //valid as no svlen validation made on obj creation on v44
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "ACT",
                            { "ATCTTGG" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::SVLEN, "3"} },
                            { vcf::GT },
                            { "0|1" },
                            source}) );

            CHECK_NOTHROW( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "ACTGNGCN",
                            { "ATC" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::SVLEN, "."} },
                            { vcf::GT },
                            { "0|1" },
                            source} ) );

            CHECK_NOTHROW( (vcf::Record{    //no svlen validation made on obj creation on v44
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "ACTGNGCN",
                            { "ATC" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::SVLEN, "-4"} },
                            { vcf::GT },
                            { "0|1" },
                            source}) );

            CHECK_NOTHROW( (vcf::Record{    //svlen -ve is valid for backward compatibility
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "<INS>" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::SVLEN, "-1"} },
                            { vcf::GT },
                            { "0|1" },
                            source}) );

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "<DUP:TANDEM>" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::SVLEN, "-5"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::SVLEN, "10"} },
                            { vcf::GT },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_NOTHROW( (vcf::Record{  //non-sv alt allele should have svlen as .
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "<UNK>" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::SVLEN, "."} },
                            { vcf::GT },
                            { "0|1" },
                            source}) );

            CHECK_NOTHROW( (vcf::Record{  //breakend alt allele should have svlen as .
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "G]chr1:198982]" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::SVLEN, "."} },
                            { vcf::GT },
                            { "0|1" },
                            source}) );

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::CIPOS, "-1,1.45"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::CIPOS, "1,2,3"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::CIEND, "9,end"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::CIEND, "9"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::HOMLEN, "len"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::MEINFO, "9,8,7"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::METRANS, "9,8,7,6,5"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::DGVID, "2,5"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::DBVARID, "0,9"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::DBRIPID, "0,1,0"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::PARID, "l,en"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::EVENT, "9,8,7"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::CILEN, "-1.25,2.5"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::CILEN, "-2,1,5"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::DPADJ, "0.09"} },
                            { vcf::GT },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{  //should be valid float
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::CN, "/1.10"} },
                            { vcf::GT },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{  //invalid cardinality
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::CN, "2.0,4.0,5.0"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::CNADJ, "9.87"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::CICN, "9.87,6.5"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::CICN, "1,3,5"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::CICNADJ, "9.99"} },
                            { vcf::GT },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_NOTHROW( (vcf::Record{  //valid DEL/DUP can have D/J/DJ
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "<DEL>","<DUP>","<DEL>" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::SVLEN, "1,1,1"}, {vcf::SVCLAIM, "D,J,DJ"} },
                            { vcf::GT },
                            { "0|1" },
                            source}) );

            CHECK_NOTHROW( (vcf::Record{  //valid CNV can have D,. and nonSV to be .
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "<CNV>","<CNV>","AT" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::SVLEN, "1,1,."}, {vcf::SVCLAIM, "D,.,."} },
                            { vcf::GT },
                            { "0|1" },
                            source}) );

            CHECK_NOTHROW( (vcf::Record{  //valid INS/INV can have J,DJ,.
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "<INS>","<INV>","<INS>" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::SVLEN, "1,1,1"}, {vcf::SVCLAIM, "J,DJ,."} },
                            { vcf::GT },
                            { "0|1" },
                            source}) );

            CHECK_NOTHROW( (vcf::Record{  //valid breakends with J, .
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "G]chr1:198982]" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::SVCLAIM, "J"} },
                            { vcf::GT },
                            { "0|1" },
                            source}) );

            CHECK_THROWS_AS( (vcf::Record{  //invalid missing svclaim
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "<DEL>","<DUP>" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::SVLEN, "1,1"} },
                            { vcf::GT },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_NOTHROW( (vcf::Record{  //valid
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "<CNV:TR>" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::SVLEN, "1"}, {vcf::RN, "1"}, {vcf::RUS, "AT"}, {vcf::RUC, "2.0"}, {vcf::RB, "4"}, {vcf::CIRUC, "-1,1"}, {vcf::CIRB, "-1,1"}},
                            { vcf::GT },
                            { "0|1" },
                            source}) );

            CHECK_NOTHROW( (vcf::Record{  //valid with non-cnv:tr as well
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "T" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::RN, "1"}, {vcf::RUS, "AT"}, {vcf::RUC, "2.0"}, {vcf::RB, "4"}},
                            { vcf::GT },
                            { "0|1" },
                            source}) );

            CHECK_THROWS_AS( (vcf::Record{  //invalid as RUS not matching to assumed RN = 1
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "<CNV:TR>" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::SVLEN, "1"}, {vcf::RUS, "AT,CG"}, {vcf::RUC, "2.0"}, {vcf::RB, "4"}},
                            { vcf::GT },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{  //invalid as RUS not matching to RUL
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "<CNV:TR>" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::SVLEN, "1"}, {vcf::RUS, "AT"}, {vcf::RUC, "2.0"}, {vcf::RB, "4"}, {vcf::RUL, "3"}},
                            { vcf::GT },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{  //invalid as RUS and RUL missing
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "<CNV:TR>" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::SVLEN, "1"}, {vcf::RUC, "2.0"}, {vcf::RB, "4"}},
                            { vcf::GT },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{  //invalid as CIRB not matching to RB
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "<CNV:TR>" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::SVLEN, "1"}, {vcf::RUC, "2.0"}, {vcf::RB, "4"}, {vcf::RUL, "2"}, {vcf::CIRB, "-1,0,-1,1"}},
                            { vcf::GT },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{  //invalid as CIRUC not matching to RUC
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "<CNV:TR>" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::SVLEN, "1"}, {vcf::RUC, "2.0"}, {vcf::RUL, "2"}, {vcf::CIRUC, "-1,0,-1,1"}},
                            { vcf::GT },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{  //invalid as RUC has missing val and not so in CIRUC
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "<CNV:TR>" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::SVLEN, "1"}, {vcf::RN, "3"}, {vcf::RUC, "2.0,.,1.5"}, {vcf::RUL, "2,10,2"}, {vcf::CIRUC, "-1,1,-1,0,-1,."}},
                            { vcf::GT },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{  //invalid as RB has missing val and not so in CIRRB
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "<CNV:TR>" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::SVLEN, "1"}, {vcf::RN, "3"}, {vcf::RUC, "2.0,.,2.05"}, {vcf::RUL, "2,10,2"}, {vcf::RB, "4,.,4"}, {vcf::CIRB, "-1,1,-1,.,-1,."}},
                            { vcf::GT },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_NOTHROW( (vcf::Record{  //valid with RUB, RUC
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "<CNV:TR>" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::SVLEN, "1"}, {vcf::RN, "3"}, {vcf::RUS, "AT,TTG,CA"}, {vcf::RUC, "2,3,2"}, {vcf::RUB, "2,2,3,3,3,2,2"}},
                            { vcf::GT },
                            { "0|1" },
                            source}) );

            CHECK_THROWS_AS( (vcf::Record{  //invalid as RUC is missing with RUB
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "<CNV:TR>" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::SVLEN, "1"}, {vcf::RN, "3"}, {vcf::RUL, "2,3,2"}, {vcf::RUB, "2,2,3,3,3,2,2"}},
                            { vcf::GT },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{  //invalid as RUC unmatched to RUB
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "<CNV:TR>" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::SVLEN, "1"}, {vcf::RN, "3"}, {vcf::RUL, "2,3,2"}, {vcf::RUB, "2,3,3,3,2,2"}},
                            { vcf::GT },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{  //invalid as RUC is not integer
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "<CNV:TR>" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::SVLEN, "1"}, {vcf::RN, "3"}, {vcf::RUS, "AT,TTG,CA"}, {vcf::RUC, "2.2,3,2"}, {vcf::RUB, "2,2,3,3,3,2,2"}},
                            { vcf::GT },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_NOTHROW( (vcf::Record{  //RN with missing data
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "<DEL>","T","<CNV:TR>" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::SVLEN, "1,.,1"}, {vcf::SVCLAIM, "D,.,D"}, {vcf::RN, ".,3,1"}, {vcf::RUS, "AT,TTG,CA,TAC"}, {vcf::RUC, "2,3,2,2"}, {vcf::RUB, "2,2,3,3,3,2,2,3,3"}},
                            { vcf::GT },
                            { "0|1" },
                            source}) );
        }
    }

}
