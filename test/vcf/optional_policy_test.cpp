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

        vcf::ParsingState parsing_state{source, vcf::AdditionalChecks()};

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

        SECTION("SVLEN test")
        {
            source->meta_entries.emplace(vcf::INFO,
                vcf::MetaEntry{
                    1,
                    vcf::INFO,
                    {
                        { vcf::ID, vcf::SVLEN },
                        { vcf::NUMBER, "2" },
                        { vcf::TYPE, vcf::INTEGER },
                        { vcf::DESCRIPTION, "Difference in length between REF and ALT alleles" }
                    },
                    source
            });

            CHECK_NOTHROW( (optional_policy.optional_check_body_entry(parsing_state, vcf::Record{
                                1,
                                "chr1",
                                123456,
                                { "id123" },
                                "A",
                                { "AC", "ACT" },
                                1.0,
                                { vcf::PASS },
                                { { vcf::SVLEN, "1,2" } },
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
                                { { vcf::SVLEN, "1,2" } },
                                { vcf::GT },
                                { "0|1" },
                                source})),
                            vcf::InfoBodyError*);
        }
    }

    TEST_CASE("Info predefined tags warnings v4.4", "[body info warnings]")
    {
        std::shared_ptr<vcf::Source> source{
            new vcf::Source{
                "Example VCF source",
                vcf::InputFormat::VCF_FILE_VCF | vcf::InputFormat::VCF_FILE_BGZIP,
                vcf::Version::v44,
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

        vcf::ParsingState parsing_state{source, vcf::AdditionalChecks()};

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

        SECTION("SVLEN test")
        {
            source->meta_entries.emplace(vcf::INFO,
                vcf::MetaEntry{
                    1,
                    vcf::INFO,
                    {
                        { vcf::ID, vcf::SVLEN },
                        { vcf::NUMBER, "2" },
                        { vcf::TYPE, vcf::INTEGER },
                        { vcf::DESCRIPTION, "Difference in length between REF and ALT alleles" }
                    },
                    source
            });

            CHECK_NOTHROW( (optional_policy.optional_check_body_entry(parsing_state, vcf::Record{
                                1,
                                "chr1",
                                123456,
                                { "id123" },
                                "A",
                                { "AC", "ACT" },
                                1.0,
                                { vcf::PASS },
                                { { vcf::SVLEN, "1,2" } },
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
                                { { vcf::SVLEN, "1,2" } },
                                { vcf::GT },
                                { "0|1" },
                                source})),
                            vcf::InfoBodyError*);
        }
    }

    TEST_CASE("Alternate allele warnings", "[body alt warnings]")
    {
        std::vector<std::shared_ptr<vcf::Source>> sources = {
            std::shared_ptr<vcf::Source>{new vcf::Source{
                "Example VCF source with ploidy 1",
                vcf::InputFormat::VCF_FILE_VCF | vcf::InputFormat::VCF_FILE_BGZIP,
                vcf::Version::v43,
                {},
                { "Sample1", "Sample2" }}},

            std::shared_ptr<vcf::Source>{new vcf::Source{
                "Example VCF source with ploidy 2",
                vcf::InputFormat::VCF_FILE_VCF | vcf::InputFormat::VCF_FILE_BGZIP,
                vcf::Version::v43,
                {},
                { "Sample1" }}},

            std::shared_ptr<vcf::Source>{new vcf::Source{
                "Example VCF source with ploidy 3",
                vcf::InputFormat::VCF_FILE_VCF | vcf::InputFormat::VCF_FILE_BGZIP,
                vcf::Version::v43,
                {},
                { "Sample1", "Sample2" }}}
        };

        for (auto & source : sources) {
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

            source->meta_entries.emplace(vcf::INFO,
                vcf::MetaEntry{
                    1,
                    vcf::INFO,
                    {
                        { vcf::ID, vcf::END },
                        { vcf::NUMBER, "1" },
                        { vcf::TYPE, vcf::INTEGER },
                        { vcf::DESCRIPTION, "End position" }
                    },
                    source
            });

            source->meta_entries.emplace(vcf::INFO,
                vcf::MetaEntry{
                    1,
                    vcf::INFO,
                    {
                        { vcf::ID, "ABC" },
                        { vcf::NUMBER, "1" },
                        { vcf::TYPE, vcf::INTEGER },
                        { vcf::DESCRIPTION, "random info tag" }
                    },
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

            source->meta_entries.emplace(vcf::FORMAT,
                vcf::MetaEntry{
                    1,
                    vcf::FORMAT,
                    {
                        { vcf::ID, "XYZ" },
                        { vcf::NUMBER, "1" },
                        { vcf::TYPE, vcf::INTEGER },
                        { vcf::DESCRIPTION, "random format tag" }
                    },
                    source
            });
        }

        vcf::ParsingState parsing_state1{sources[0], vcf::AdditionalChecks()};
        vcf::ParsingState parsing_state2{sources[1], vcf::AdditionalChecks()};
        vcf::ParsingState parsing_state3{sources[2], vcf::AdditionalChecks()};

        vcf::ValidateOptionalPolicy optional_policy;

        SECTION("gVCF fields should have INFO END")
        {
            CHECK_NOTHROW( (optional_policy.optional_check_body_entry(parsing_state2, vcf::Record{
                                1,
                                "chr1",
                                123456,
                                { "id123" },
                                "A",
                                { vcf::GVCF_NON_VARIANT_ALLELE },
                                1.0,
                                { vcf::PASS },
                                { { vcf::END, "2" } },
                                { "XYZ" },
                                { "11" },
                                sources[1]})) );

             CHECK_THROWS_AS( (optional_policy.optional_check_body_entry(parsing_state2, vcf::Record{
                                1,
                                "chr1",
                                123456,
                                { "id123" },
                                "A",
                                { vcf::GVCF_NON_VARIANT_ALLELE },
                                1.0,
                                { vcf::PASS },
                                { { "ABC", "7" } },
                                { "XYZ" },
                                { "7" },
                                sources[1]})),
                            vcf::InfoBodyError*);
        }

        SECTION("gVCF fields should have 0/0 genotype")
        {
            CHECK_NOTHROW( (optional_policy.optional_check_body_entry(parsing_state1, vcf::Record{
                                1,
                                "chr1",
                                123456,
                                { "id123" },
                                "A",
                                { "AC", vcf::GVCF_NON_VARIANT_ALLELE },
                                1.0,
                                { vcf::PASS },
                                { { vcf::END, "0" } },
                                { vcf::GT, "XYZ" },
                                { "0", "1:9" },
                                sources[0]})) );

            CHECK_NOTHROW( (optional_policy.optional_check_body_entry(parsing_state3, vcf::Record{
                                1,
                                "chr1",
                                123456,
                                { "id123" },
                                "A",
                                { vcf::GVCF_NON_VARIANT_ALLELE },
                                1.0,
                                { vcf::PASS },
                                { { vcf::END, "0" } },
                                { vcf::GT, "XYZ" },
                                { "0|0/0:12", "1|0|1:5" },
                                sources[2]})) );

            CHECK_NOTHROW( (optional_policy.optional_check_body_entry(parsing_state2, vcf::Record{
                                1,
                                "chr1",
                                123456,
                                { "id123" },
                                "A",
                                { vcf::GVCF_NON_VARIANT_ALLELE },
                                1.0,
                                { vcf::PASS },
                                { { vcf::END, "0" } },
                                { vcf::GT },
                                { "0/0" },
                                sources[1]})) );

            CHECK_NOTHROW( (optional_policy.optional_check_body_entry(parsing_state2, vcf::Record{
                                1,
                                "chr1",
                                123456,
                                { "id123" },
                                "A",
                                { "AC", vcf::GVCF_NON_VARIANT_ALLELE },
                                1.0,
                                { vcf::PASS },
                                { { vcf::END, "0" } },
                                { "XYZ" },
                                { "15" },
                                sources[1]})) );

            CHECK_THROWS_AS( (optional_policy.optional_check_body_entry(parsing_state2, vcf::Record{
                                1,
                                "chr1",
                                123456,
                                { "id123" },
                                "A",
                                { vcf::GVCF_NON_VARIANT_ALLELE },
                                1.0,
                                { vcf::PASS },
                                { { vcf::END, "0" } },
                                { vcf::GT },
                                { "0|1" },
                                sources[1]})),
                            vcf::AlternateAllelesBodyError*);
        }
    }

    TEST_CASE("Alternate allele warnings v4.4", "[body alt warnings]")
    {
        std::vector<std::shared_ptr<vcf::Source>> sources = {
            std::shared_ptr<vcf::Source>{new vcf::Source{
                "Example VCF source with ploidy 1",
                vcf::InputFormat::VCF_FILE_VCF | vcf::InputFormat::VCF_FILE_BGZIP,
                vcf::Version::v44,
                {},
                { "Sample1", "Sample2" }}},

            std::shared_ptr<vcf::Source>{new vcf::Source{
                "Example VCF source with ploidy 2",
                vcf::InputFormat::VCF_FILE_VCF | vcf::InputFormat::VCF_FILE_BGZIP,
                vcf::Version::v44,
                {},
                { "Sample1" }}},

            std::shared_ptr<vcf::Source>{new vcf::Source{
                "Example VCF source with ploidy 3",
                vcf::InputFormat::VCF_FILE_VCF | vcf::InputFormat::VCF_FILE_BGZIP,
                vcf::Version::v44,
                {},
                { "Sample1", "Sample2" }}}
        };

        for (auto & source : sources) {
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

            source->meta_entries.emplace(vcf::INFO,
                vcf::MetaEntry{
                    1,
                    vcf::INFO,
                    {
                        { vcf::ID, vcf::END },
                        { vcf::NUMBER, "1" },
                        { vcf::TYPE, vcf::INTEGER },
                        { vcf::DESCRIPTION, "End position" }
                    },
                    source
            });

            source->meta_entries.emplace(vcf::INFO,
                vcf::MetaEntry{
                    1,
                    vcf::INFO,
                    {
                        { vcf::ID, "ABC" },
                        { vcf::NUMBER, "1" },
                        { vcf::TYPE, vcf::INTEGER },
                        { vcf::DESCRIPTION, "random info tag" }
                    },
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

            source->meta_entries.emplace(vcf::FORMAT,
                vcf::MetaEntry{
                    1,
                    vcf::FORMAT,
                    {
                        { vcf::ID, "XYZ" },
                        { vcf::NUMBER, "1" },
                        { vcf::TYPE, vcf::INTEGER },
                        { vcf::DESCRIPTION, "random format tag" }
                    },
                    source
            });
        }

        vcf::ParsingState parsing_state1{sources[0], vcf::AdditionalChecks()};
        vcf::ParsingState parsing_state2{sources[1], vcf::AdditionalChecks()};
        vcf::ParsingState parsing_state3{sources[2], vcf::AdditionalChecks()};

        vcf::ValidateOptionalPolicy optional_policy;

        SECTION("gVCF fields should have INFO END")
        {
            CHECK_NOTHROW( (optional_policy.optional_check_body_entry(parsing_state2, vcf::Record{
                                1,
                                "chr1",
                                123456,
                                { "id123" },
                                "A",
                                { vcf::GVCF_NON_VARIANT_ALLELE },
                                1.0,
                                { vcf::PASS },
                                { { vcf::END, "2" } },
                                { "XYZ" },
                                { "11" },
                                sources[1]})) );

             CHECK_THROWS_AS( (optional_policy.optional_check_body_entry(parsing_state2, vcf::Record{
                                1,
                                "chr1",
                                123456,
                                { "id123" },
                                "A",
                                { vcf::GVCF_NON_VARIANT_ALLELE },
                                1.0,
                                { vcf::PASS },
                                { { "ABC", "7" } },
                                { "XYZ" },
                                { "7" },
                                sources[1]})),
                            vcf::InfoBodyError*);
        }

        SECTION("gVCF fields should have 0/0 genotype")
        {
            CHECK_NOTHROW( (optional_policy.optional_check_body_entry(parsing_state1, vcf::Record{
                                1,
                                "chr1",
                                123456,
                                { "id123" },
                                "A",
                                { "AC", vcf::GVCF_NON_VARIANT_ALLELE },
                                1.0,
                                { vcf::PASS },
                                { { vcf::END, "0" } },
                                { vcf::GT, "XYZ" },
                                { "0", "1:9" },
                                sources[0]})) );

            CHECK_NOTHROW( (optional_policy.optional_check_body_entry(parsing_state3, vcf::Record{
                                1,
                                "chr1",
                                123456,
                                { "id123" },
                                "A",
                                { vcf::GVCF_NON_VARIANT_ALLELE },
                                1.0,
                                { vcf::PASS },
                                { { vcf::END, "0" } },
                                { vcf::GT, "XYZ" },
                                { "0|0/0:12", "1|0|1:5" },
                                sources[2]})) );

            CHECK_NOTHROW( (optional_policy.optional_check_body_entry(parsing_state2, vcf::Record{
                                1,
                                "chr1",
                                123456,
                                { "id123" },
                                "A",
                                { vcf::GVCF_NON_VARIANT_ALLELE },
                                1.0,
                                { vcf::PASS },
                                { { vcf::END, "0" } },
                                { vcf::GT },
                                { "0/0" },
                                sources[1]})) );

            CHECK_NOTHROW( (optional_policy.optional_check_body_entry(parsing_state2, vcf::Record{
                                1,
                                "chr1",
                                123456,
                                { "id123" },
                                "A",
                                { "AC", vcf::GVCF_NON_VARIANT_ALLELE },
                                1.0,
                                { vcf::PASS },
                                { { vcf::END, "0" } },
                                { "XYZ" },
                                { "15" },
                                sources[1]})) );

            CHECK_THROWS_AS( (optional_policy.optional_check_body_entry(parsing_state2, vcf::Record{
                                1,
                                "chr1",
                                123456,
                                { "id123" },
                                "A",
                                { vcf::GVCF_NON_VARIANT_ALLELE },
                                1.0,
                                { vcf::PASS },
                                { { vcf::END, "0" } },
                                { vcf::GT },
                                { "0|1" },
                                sources[1]})),
                            vcf::AlternateAllelesBodyError*);
        }
    }

}
