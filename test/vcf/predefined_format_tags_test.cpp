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

    TEST_CASE("Record predefined SV tags checks", "[record][keyvalue]")
    {
        std::shared_ptr<vcf::Source> source{
            new vcf::Source{
                "Example VCF source",
                vcf::InputFormat::VCF_FILE_VCF | vcf::InputFormat::VCF_FILE_BGZIP,
                vcf::Version::v43,
                vcf::Ploidy{2, {{"Y", 1}}},
                {},
                { "Sample1" }}};

        SECTION("Predefined FORMAT tags not in meta header")
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
                            { {"AA", "243"} },
                            { "AD" },
                            { "0.98" },
                            source}),
                        vcf::SamplesFieldBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"AA", "243"} },
                            { "AD" },
                            { "0,9,8" },
                            source}),
                        vcf::SamplesFieldBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"AA", "243"} },
                            { "ADF" },
                            { "val1" },
                            source}),
                        vcf::SamplesFieldBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"AA", "243"} },
                            { "ADF" },
                            { "9,1,8" },
                            source}),
                        vcf::SamplesFieldBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"AA", "243"} },
                            { "ADR" },
                            { "val" },
                            source}),
                        vcf::SamplesFieldBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"AA", "243"} },
                            { "ADR" },
                            { "1,2,1" },
                            source}),
                        vcf::SamplesFieldBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"AA", "243"} },
                            { "DP" },
                            { "9.18" },
                            source}),
                        vcf::SamplesFieldBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"AA", "243"} },
                            { "DP" },
                            { "9,8" },
                            source}),
                        vcf::SamplesFieldBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"AA", "243"} },
                            { "EC" },
                            { "0.498" },
                            source}),
                        vcf::SamplesFieldBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"AA", "243"} },
                            { "EC" },
                            { "4,8" },
                            source}),
                        vcf::SamplesFieldBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"AA", "243"} },
                            { "FT" },
                            { "8,9" },
                            source}),
                        vcf::SamplesFieldBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"AA", "243"} },
                            { "GL" },
                            { "val" },
                            source}),
                        vcf::SamplesFieldBodyError*);

           CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"AA", "243"} },
                            { "GL" },
                            { "1.3,2.4" },
                            source}),
                        vcf::SamplesFieldBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"AA", "243"} },
                            { "GP" },
                            { "val12s" },
                            source}),
                        vcf::SamplesFieldBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"AA", "243"} },
                            { "GP" },
                            { "0.98,0.87,0.57,1.0" },
                            source}),
                        vcf::SamplesFieldBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"AA", "243"} },
                            { "GP" },
                            { "1.98" },
                            source}),
                        vcf::SamplesFieldBodyError*);

           CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"AA", "243"} },
                            { "GQ" },
                            { "2.38" },
                            source}),
                        vcf::SamplesFieldBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"AA", "243"} },
                            { "GQ" },
                            { "2,38" },
                            source}),
                        vcf::SamplesFieldBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"AA", "243"} },
                            { "GT" },
                            { "va,lue" },
                            source}),
                        vcf::SamplesFieldBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"AA", "243"} },
                            { "HQ" },
                            { "9.08" },
                            source}),
                        vcf::SamplesFieldBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"AA", "243"} },
                            { "HQ" },
                            { "9,8,1" },
                            source}),
                        vcf::SamplesFieldBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"AA", "243"} },
                            { "MQ" },
                            { "0.76" },
                            source}),
                        vcf::SamplesFieldBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"AA", "243"} },
                            { "MQ" },
                            { "0,8" },
                            source}),
                        vcf::SamplesFieldBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"AA", "243"} },
                            { "PL" },
                            { "0.76" },
                            source}),
                        vcf::SamplesFieldBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"AA", "243"} },
                            { "PL" },
                            { "7,5" },
                            source}),
                        vcf::SamplesFieldBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"AA", "243"} },
                            { "PQ" },
                            { "tag" },
                            source}),
                        vcf::SamplesFieldBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"AA", "243"} },
                            { "PQ" },
                            { "5,6,9" },
                            source}),
                        vcf::SamplesFieldBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"AA", "243"} },
                            { "PS" },
                            { "set" },
                            source}),
                        vcf::SamplesFieldBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"AA", "243"} },
                            { "PS" },
                            { "4,5,6" },
                            source}),
                        vcf::SamplesFieldBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"AA", "243"} },
                            { "CN" },
                            { "4.56" },
                            source}),
                        vcf::SamplesFieldBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"AA", "243"} },
                            { "CN" },
                            { "4,5,6" },
                            source}),
                        vcf::SamplesFieldBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"AA", "243"} },
                            { "CNQ" },
                            { "tag" },
                            source}),
                        vcf::SamplesFieldBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"AA", "243"} },
                            { "CNQ" },
                            { "4,5,6" },
                            source}),
                        vcf::SamplesFieldBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"AA", "243"} },
                            { "CNL" },
                            { "ta,g" },
                            source}),
                        vcf::SamplesFieldBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"AA", "243"} },
                            { "CNL" },
                            { "4.5" },
                            source}),
                        vcf::SamplesFieldBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"AA", "243"} },
                            { "CNP" },
                            { "val,ue" },
                            source}),
                        vcf::SamplesFieldBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"AA", "243"} },
                            { "CNP" },
                            { "4,5,6" },
                            source}),
                        vcf::SamplesFieldBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"AA", "243"} },
                            { "CNP" },
                            { "1.34" },
                            source}),
                        vcf::SamplesFieldBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"AA", "243"} },
                            { "NQ" },
                            { "45.6" },
                            source}),
                        vcf::SamplesFieldBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"AA", "243"} },
                            { "NQ" },
                            { "4,5,6" },
                            source}),
                        vcf::SamplesFieldBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"AA", "243"} },
                            { "HAP" },
                            { "val" },
                            source}),
                        vcf::SamplesFieldBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"AA", "243"} },
                            { "HAP" },
                            { "1,2" },
                            source}),
                        vcf::SamplesFieldBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"AA", "243"} },
                            { "AHAP" },
                            { "val" },
                            source}),
                        vcf::SamplesFieldBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { "PASS" },
                            { {"AA", "243"} },
                            { "AHAP" },
                            { "3,4,5" },
                            source}),
                        vcf::SamplesFieldBodyError*);
        }
    }
}
