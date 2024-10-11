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

        source->meta_entries.emplace(vcf::ALT,
            vcf::MetaEntry{
                1,
                vcf::ALT,
                {
                    { vcf::ID, vcf::DEL },
                    { vcf::DESCRIPTION, "Deletion" }
                },
                source
            });
        source->meta_entries.emplace(vcf::ALT,
            vcf::MetaEntry{
                1,
                vcf::ALT,
                {
                    { vcf::ID, vcf::DUP },
                    { vcf::DESCRIPTION, "Duplication" }
                },
                source
            });
        source->meta_entries.emplace(vcf::ALT,
            vcf::MetaEntry{
                1,
                vcf::ALT,
                {
                    { vcf::ID, "CNV:TR" },
                    { vcf::DESCRIPTION, "Cnv-TR" }
                },
                source
            });

        vcf::ParsingState parsing_state{source, vcf::AdditionalChecks()};

        vcf::ValidateOptionalPolicy optional_policy;

        SECTION("Confidence Interval Tags")
        {
            std::vector<std::string> confidence_interval_tags = {
                                                                    vcf::CICN,
                                                                    vcf::CIEND,
                                                                    vcf::CILEN,
                                                                    vcf::CIPOS
                                                                };
            std::vector<std::string> confidence_interval_types = {
                                                                    vcf::FLOAT,
                                                                    vcf::INTEGER,
                                                                    vcf::INTEGER,
                                                                    vcf::INTEGER
                                                                };

            for (size_t i = 0; i < confidence_interval_tags.size() && i < confidence_interval_types.size(); ++i) {

                source->meta_entries.emplace(vcf::INFO,
                    vcf::MetaEntry{
                        1,
                        vcf::INFO,
                        {
                            { vcf::ID, confidence_interval_tags[i] },
                            { vcf::NUMBER, vcf::UNKNOWN_CARDINALITY },
                            { vcf::TYPE, confidence_interval_types[i] },
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
                                    { { confidence_interval_tags[i], "0,0" } },
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
                                    { { confidence_interval_tags[i], "1" } },
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
                                    { { confidence_interval_tags[i], "-1,-2" } },
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
                        { vcf::NUMBER, "A" },
                        { vcf::TYPE, vcf::INTEGER },
                        { vcf::DESCRIPTION, "Difference in length between REF and ALT alleles" }
                    },
                    source
            });
            source->meta_entries.emplace(vcf::INFO,
                vcf::MetaEntry{
                    1,
                    vcf::INFO,
                    {
                        { vcf::ID, vcf::SVCLAIM },
                        { vcf::NUMBER, "A" },
                        { vcf::TYPE, vcf::STRING },
                        { vcf::DESCRIPTION, "svclaim" }
                    },
                    source
            });
            source->meta_entries.emplace(vcf::FORMAT,
                vcf::MetaEntry{
                    1,
                    vcf::FORMAT,
                    {
                        { vcf::ID, vcf::CN },
                        { vcf::NUMBER, "1" },
                        { vcf::TYPE, vcf::FLOAT },
                        { vcf::DESCRIPTION, "fmt cn" }
                    },
                    source
            });

            //fail as svlen is not . for non-symbolic alleles
            CHECK_THROWS_AS( (optional_policy.optional_check_body_entry(parsing_state, vcf::Record{
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
                                source})),
                            vcf::InfoBodyError*);
            //valid
            CHECK_NOTHROW( (optional_policy.optional_check_body_entry(parsing_state, vcf::Record{
                                1,
                                "chr1",
                                123456,
                                { "id123" },
                                "A",
                                { "AC", "ACT" },
                                1.0,
                                { vcf::PASS },
                                { { vcf::SVLEN, ".,." } },
                                { vcf::GT },
                                { "0|1" },
                                source})) );
            //fail as cardinality is different
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

        SECTION("CNV:TR test")
        {
            source->meta_entries.emplace(vcf::INFO,
                vcf::MetaEntry{
                    1,
                    vcf::INFO,
                    {
                        { vcf::ID, vcf::SVLEN },
                        { vcf::NUMBER, "A" },
                        { vcf::TYPE, vcf::INTEGER },
                        { vcf::DESCRIPTION, "Difference in length between REF and ALT alleles" }
                    },
                    source
            });
            source->meta_entries.emplace(vcf::INFO,
                vcf::MetaEntry{
                    1,
                    vcf::INFO,
                    {
                        { vcf::ID, vcf::RN }, { vcf::NUMBER, "A" }, { vcf::TYPE, vcf::INTEGER }, { vcf::DESCRIPTION, "RN" }
                    },
                    source
            });
            source->meta_entries.emplace(vcf::INFO,
                vcf::MetaEntry{
                    1,
                    vcf::INFO,
                    {
                        { vcf::ID, vcf::RUS }, { vcf::NUMBER, vcf::UNKNOWN_CARDINALITY }, { vcf::TYPE, vcf::STRING }, { vcf::DESCRIPTION, "RUS" }
                    },
                    source
            });
            source->meta_entries.emplace(vcf::INFO,
                vcf::MetaEntry{
                    1,
                    vcf::INFO,
                    {
                        { vcf::ID, vcf::RUC }, { vcf::NUMBER, vcf::UNKNOWN_CARDINALITY }, { vcf::TYPE, vcf::FLOAT }, { vcf::DESCRIPTION, "RUC" }
                    },
                    source
            });
            source->meta_entries.emplace(vcf::INFO,
                vcf::MetaEntry{
                    1,
                    vcf::INFO,
                    {
                        { vcf::ID, vcf::RUL }, { vcf::NUMBER, vcf::UNKNOWN_CARDINALITY }, { vcf::TYPE, vcf::INTEGER }, { vcf::DESCRIPTION, "RUL" }
                    },
                    source
            });
            source->meta_entries.emplace(vcf::INFO,
                vcf::MetaEntry{
                    1,
                    vcf::INFO,
                    {
                        { vcf::ID, vcf::CIRUC }, { vcf::NUMBER, vcf::UNKNOWN_CARDINALITY }, { vcf::TYPE, vcf::FLOAT }, { vcf::DESCRIPTION, "CIRUC" }
                    },
                    source
            });
            source->meta_entries.emplace(vcf::INFO,
                vcf::MetaEntry{
                    1,
                    vcf::INFO,
                    {
                        { vcf::ID, vcf::CIRB }, { vcf::NUMBER, vcf::UNKNOWN_CARDINALITY }, { vcf::TYPE, vcf::INTEGER }, { vcf::DESCRIPTION, "CIRB" }
                    },
                    source
            });

            CHECK_THROWS_AS( (optional_policy.optional_check_body_entry(parsing_state, vcf::Record{  //warning as RUS RUL together is redundant
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "<CNV:TR>" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::SVLEN, "1"}, {vcf::RUS, "AT"}, {vcf::RUC, "2.0"}, {vcf::RB, "4"}, {vcf::RUL, "2"}},
                            { vcf::GT },
                            { "0|1" },
                            source})),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (optional_policy.optional_check_body_entry(parsing_state, vcf::Record{  //invalid CIRB
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "<CNV:TR>" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::SVLEN, "1"}, {vcf::RUC, "2.0"}, {vcf::RB, "4"}, {vcf::RUL, "2"}, {vcf::CIRB, "1,0"}},
                            { vcf::GT },
                            { "0|1" },
                            source})),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (optional_policy.optional_check_body_entry(parsing_state, vcf::Record{  //invalid CIRUC
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "<CNV:TR>" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::SVLEN, "1"}, {vcf::RUC, "2.0"}, {vcf::RUL, "2"}, {vcf::CIRUC, "-1,-1"}},
                            { vcf::GT },
                            { "0|1" },
                            source})),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (optional_policy.optional_check_body_entry(parsing_state, vcf::Record{  //invalid CIRUC 2
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "<CNV:TR>" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::SVLEN, "1"}, {vcf::RN, "2"}, {vcf::RUC, "2.0,2"}, {vcf::RUL, "2,2"}, {vcf::CIRUC, "-1,1,1,1"}},
                            { vcf::GT },
                            { "0|1" },
                            source})),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (optional_policy.optional_check_body_entry(parsing_state, vcf::Record{  //invalid CIRUC
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "<CNV:TR>" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::SVLEN, "1"}, {vcf::RN, "2"}, {vcf::RUL, "2,2"}, {vcf::CIRUC, "-1,1,1,1"}},
                            { vcf::GT },
                            { "0|1" },
                            source})),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (optional_policy.optional_check_body_entry(parsing_state, vcf::Record{  //invalid CIRB
                            1,
                            "chr1",
                            123456,
                            { "id123" },
                            "A",
                            { "<CNV:TR>" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::SVLEN, "1"}, {vcf::RUC, "2.0"}, {vcf::RUL, "2"}, {vcf::CIRB, "1,0"}},
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

    TEST_CASE("Sample value warnings v4.4", "[sample warnings]")
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
                        { vcf::ID, "SVLEN" },
                        { vcf::NUMBER, "A" },
                        { vcf::TYPE, vcf::INTEGER },
                        { vcf::DESCRIPTION, "svlen" }
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
                        { vcf::ID, "CN" },
                        { vcf::NUMBER, "1" },
                        { vcf::TYPE, vcf::FLOAT },
                        { vcf::DESCRIPTION, "CN" }
                    },
                    source
            });

            source->meta_entries.emplace(vcf::FORMAT,
                vcf::MetaEntry{
                    1,
                    vcf::FORMAT,
                    {
                        { vcf::ID, "CICN" },
                        { vcf::NUMBER, "2" },
                        { vcf::TYPE, vcf::FLOAT },
                        { vcf::DESCRIPTION, "CICN" }
                    },
                    source
            });

            source->meta_entries.emplace(vcf::ALT,
            vcf::MetaEntry{
                1,
                vcf::ALT,
                {
                    { vcf::ID, "CNV" },
                    { vcf::DESCRIPTION, "Cnv" }
                },
                source
            });
        }

        vcf::ParsingState parsing_state1{sources[0], vcf::AdditionalChecks()};
        vcf::ParsingState parsing_state2{sources[1], vcf::AdditionalChecks()};
        vcf::ParsingState parsing_state3{sources[2], vcf::AdditionalChecks()};

        vcf::ValidateOptionalPolicy optional_policy;

        SECTION("confidence interval")
        {
            CHECK_NOTHROW( (optional_policy.optional_check_body_entry(parsing_state2, vcf::Record{  //valid cicn
                                1,
                                "chr1",
                                123456,
                                { "id123" },
                                "A",
                                { "<CNV>" },
                                1.0,
                                { vcf::PASS },
                                { { vcf::END, "2" }, {vcf::SVLEN, "100"} },
                                { vcf::CN, vcf::CICN },
                                { {"1.1:-1,2.2"} },
                                sources[1]})) );

             CHECK_THROWS_AS( (optional_policy.optional_check_body_entry(parsing_state2, vcf::Record{   //invalid cicn
                                1,
                                "chr1",
                                123456,
                                { "id123" },
                                "A",
                                { "<CNV>" },
                                1.0,
                                { vcf::PASS },
                                { {vcf::END, "2"}, {vcf::SVLEN, "100"} },
                                { vcf::CN, vcf::CICN },
                                { "1.1:2,-3" },
                                sources[1]})),
                            vcf::SamplesFieldBodyError*);

            CHECK_THROWS_AS( (optional_policy.optional_check_body_entry(parsing_state2, vcf::Record{   //invalid cicn
                                1,
                                "chr1",
                                123456,
                                { "id123" },
                                "A",
                                { "<CNV>" },
                                1.0,
                                { vcf::PASS },
                                { {vcf::END, "2"}, {vcf::SVLEN, "100"} },
                                { vcf::CN, vcf::CICN },
                                { "1.1:-2,3,4" },
                                sources[1]})),
                            vcf::SamplesFieldBodyError*);
        }
   }

}
