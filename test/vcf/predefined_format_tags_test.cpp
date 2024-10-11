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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::AD },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::AD },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::ADF },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::ADF },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::ADR },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::ADR },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::DP },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::DP },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::EC },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::EC },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::FT },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::GL },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::GL },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::GT, vcf::GL },
                            { "1/0:1.3,2.4" },
                            source}),
                        vcf::SamplesFieldBodyError*);

            CHECK_NOTHROW( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::GT, vcf::GL },
                            { "1:1.3,2.4" },
                            source}));

            CHECK_NOTHROW( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::GL },
                            { "1.3,2.4,2.3" },
                            source}));

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::GP },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::GP },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::GP },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::GQ },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::GQ },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::HQ },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::HQ },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::MQ },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::MQ },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::PL },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::PL },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::GT, vcf::PL },
                            { "1/0:1,2" },
                            source}),
                        vcf::SamplesFieldBodyError*);

            CHECK_NOTHROW( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::GT, vcf::PL },
                            { "1:1,2" },
                            source}));

            CHECK_NOTHROW( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::PL },
                            { "1,2,5" },
                            source}));

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::PQ },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::PQ },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::PS },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::PS },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::CN },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::CN },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::CNQ },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::CNQ },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::CNL },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::CNL },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::CNP },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::CNP },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::CNP },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::NQ },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::NQ },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::HAP },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::HAP },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::AHAP },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::AHAP },
                            { "3,4,5" },
                            source}),
                        vcf::SamplesFieldBodyError*);
        }
    }

    TEST_CASE("Record predefined SV tags checks v4.4", "[record][keyvalue]")
    {
        std::shared_ptr<vcf::Source> source{
            new vcf::Source{
                "Example VCF source",
                vcf::InputFormat::VCF_FILE_VCF | vcf::InputFormat::VCF_FILE_BGZIP,
                vcf::Version::v44,
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::AD },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::AD },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::ADF },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::ADF },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::ADR },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::ADR },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::DP },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::DP },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::EC },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::EC },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::FT },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::GL },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::GL },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::GT, vcf::GL },
                            { "1/0:1.3,2.4" },
                            source}),
                        vcf::SamplesFieldBodyError*);

            CHECK_NOTHROW( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::GT, vcf::GL },
                            { "1:1.3,2.4" },
                            source}));

            CHECK_NOTHROW( (vcf::Record{    //valid with leading phasing info
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::GT},
                            { "/1" },
                            source}));

            CHECK_NOTHROW( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::GL },
                            { "1.3,2.4,2.3" },
                            source}));

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::GP },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::GP },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::GP },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::GQ },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::GQ },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::GT },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::HQ },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::HQ },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::MQ },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::MQ },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::PL },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::PL },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::GT, vcf::PL },
                            { "1/0:1,2" },
                            source}),
                        vcf::SamplesFieldBodyError*);

            CHECK_NOTHROW( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::GT, vcf::PL },
                            { "1:1,2" },
                            source}));

            CHECK_NOTHROW( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::PL },
                            { "1,2,5" },
                            source}));

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::PQ },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::PQ },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::PS },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::PS },
                            { "4,5,6" },
                            source}),
                        vcf::SamplesFieldBodyError*);

            CHECK_NOTHROW( (vcf::Record{    //float CN is valid
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::CN },
                            { "4.56" },
                            source}) );

            CHECK_THROWS_AS( (vcf::Record{  //with invalid value
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::CN },
                            { "/4.56" },
                            source}),
                            vcf::SamplesFieldBodyError*);

            CHECK_THROWS_AS( (vcf::Record{  //with invalid cardinality
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::CN },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::CNQ },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::CNQ },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::CNL },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::CNL },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::CNP },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::CNP },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::CNP },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::NQ },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::NQ },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::HAP },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::HAP },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::AHAP },
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
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::AHAP },
                            { "3,4,5" },
                            source}),
                        vcf::SamplesFieldBodyError*);

            CHECK_NOTHROW( (vcf::Record{    //valid CICN
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::CN, vcf::CICN },
                            { "1.2:-1.2,1.2" },
                            source}));

            CHECK_THROWS_AS( (vcf::Record{  //invalid cicn
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::CICN },
                            { "-3,4" },
                            source}),
                            vcf::FormatBodyError*);

            CHECK_NOTHROW( (vcf::Record{    //valid PSL
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::GT, vcf::PSL },
                            { "|0/1:chr1*123456*1,." },
                            source}));

            CHECK_NOTHROW( (vcf::Record{    //valid PSL
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::GT, vcf::PSL },
                            { "0|1:chr1*123456*1,." },
                            source}));

            CHECK_NOTHROW( (vcf::Record{    //valid PSL
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::GT, vcf::PSL },
                            { "0/1:.,." },
                            source}));

            CHECK_THROWS_AS( (vcf::Record{  //invalid psl
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::GT, vcf::PSL },
                            { "/0:chr1*123456*1" },
                            source}),
                        vcf::SamplesFieldBodyError*);

            CHECK_THROWS_AS( (vcf::Record{  //invalid psl
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::GT, vcf::PSL },
                            { "|0:chr1*123456*1,." },
                            source}),
                        vcf::SamplesFieldBodyError*);

            CHECK_NOTHROW( (vcf::Record{    //valid PSO
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::GT, vcf::PSL, vcf::PSO },
                            { "0/1:.,.:.,." },
                            source}));

            CHECK_THROWS_AS( (vcf::Record{  //invalid pso
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::GT, vcf::PSL, vcf::PSO },
                            { "|0:chr1*123456*1:1,2" },
                            source}),
                        vcf::SamplesFieldBodyError*);

            CHECK_THROWS_AS( (vcf::Record{  //invalid pso
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::GT, vcf::PSL, vcf::PSO },
                            { "|0:.:1" },
                            source}),
                        vcf::SamplesFieldBodyError*);

            CHECK_NOTHROW( (vcf::Record{    //valid PSQ
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::GT, vcf::PSL, vcf::PSQ },
                            { "|0:chr1*123456*1:1" },
                            source}));

            CHECK_NOTHROW( (vcf::Record{    //valid PSQ
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::GT, vcf::PSL, vcf::PSQ },
                            { ".:.:." },
                            source}));

            CHECK_THROWS_AS( (vcf::Record{  //invalid psq
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "AT" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::AA, "243"} },
                            { vcf::GT, vcf::PSL, vcf::PSQ },
                            { "|0:chr1*123456*1:1,2" },
                            source}),
                        vcf::SamplesFieldBodyError*);

        }
    }

}
