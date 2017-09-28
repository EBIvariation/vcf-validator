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

#include "catch/catch.hpp"

#include "vcf/error.hpp"
#include "vcf/optional_policy.hpp"

namespace ebi
{
    
    TEST_CASE("Info predefined tags warnings", "[body info warnings]")
    {            
        std::shared_ptr<vcf::Source> source{
            new vcf::Source{
                "Example VCF source",
                vcf::InputFormat::VCF_FILE_VCF | vcf::InputFormat::VCF_FILE_BGZIP,
                vcf::Version::v43,
                vcf::Ploidy{2, {{"Y", 1}}},
                {},
                { "Sample1" }}};

        source->meta_entries.emplace(vcf::REFERENCE,
            vcf::MetaEntry{
                1,
                vcf::REFERENCE,
                "file",
                source
        });

        source->meta_entries.emplace(vcf::CONTIG,
            vcf::MetaEntry{
                1,
                vcf::CONTIG,
                { { vcf::ID, "chr1" } },
                source
        });

        source->meta_entries.emplace(vcf::FORMAT,
            vcf::MetaEntry{
                1,
                vcf::FORMAT,
                {
                    { vcf::ID, vcf::GT },
                    { vcf::NUMBER, "1" },
                    { vcf::TYPE, vcf::STRING },
                    { vcf::DESCRIPTION, "Genotype" }
                },
                source
        });

        vcf::ParsingState parsing_state{source};

        vcf::ValidateOptionalPolicy optional_policy;

        SECTION("Confidence Interval Tags") 
        {
            std::vector<std::string> confidence_interval_tags = { 
                                                                    vcf::CICN,
                                                                    vcf::CICNADJ,
                                                                    vcf::CIEND,
                                                                    vcf::CILEN,
                                                                    vcf::CIPOS
                                                                };

            for (auto & confidence_interval_tag : confidence_interval_tags) {

                source->meta_entries.emplace(vcf::INFO,
                    vcf::MetaEntry{
                        1,
                        vcf::INFO,
                        {
                            { vcf::ID, confidence_interval_tag },
                            { vcf::NUMBER, "2" },
                            { vcf::TYPE, vcf::INTEGER },
                            { vcf::DESCRIPTION, "CI tag" }
                        },
                        source
                });

                CHECK_NOTHROW( (optional_policy.optional_check_body_entry(parsing_state, vcf::Record{
                                    1,
                                    "chr1",
                                    123456,
                                    { "id123" },
                                    "A",
                                    { "AC" },
                                    1.0,
                                    { vcf::PASS },
                                    { { confidence_interval_tag, "0,0" } },
                                    { vcf::GT },
                                    { "1|0" },
                                    source})) );

                CHECK_THROWS_AS( (optional_policy.optional_check_body_entry(parsing_state, vcf::Record{
                                    1,
                                    "chr1",
                                    123456,
                                    { "id123" },
                                    "A",
                                    { "AC" },
                                    1.0,
                                    { vcf::PASS },
                                    { { confidence_interval_tag, "1,2" } },
                                    { vcf::GT },
                                    { "0|1" },
                                    source})),
                                vcf::InfoBodyError*);

                CHECK_THROWS_AS( (optional_policy.optional_check_body_entry(parsing_state, vcf::Record{
                                    1,
                                    "chr1",
                                    123456,
                                    { "id123" },
                                    "A",
                                    { "AC" },
                                    1.0,
                                    { vcf::PASS },
                                    { { confidence_interval_tag, "-1,-2" } },
                                    { vcf::GT },
                                    { "0|1" },
                                    source})),
                                vcf::InfoBodyError*);
            }
        }
    }
}
