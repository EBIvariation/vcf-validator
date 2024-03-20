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
    
    TEST_CASE("Record constructor v41", "[constructor]")
    {
        std::shared_ptr<vcf::Source> source{
            new vcf::Source{
                "Example VCF source",
                vcf::InputFormat::VCF_FILE_VCF | vcf::InputFormat::VCF_FILE_BGZIP,
                vcf::Version::v41,
                {},
                { "Sample1" }}};
            
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
                    { vcf::ID, vcf::DP },
                    { vcf::NUMBER, "1" },
                    { vcf::TYPE, vcf::INTEGER },
                    { vcf::DESCRIPTION, "Read depth" }
                },
                source
        });

        source->meta_entries.emplace(vcf::INFO,
            vcf::MetaEntry{
                1,
                vcf::INFO,
                {
                    { vcf::ID, vcf::AN },
                    { vcf::NUMBER, "1" },
                    { vcf::TYPE, vcf::INTEGER },
                    { vcf::DESCRIPTION, "Allele number" }
                },
                source
        });
           
        source->meta_entries.emplace(vcf::INFO,
            vcf::MetaEntry{
                1,
                vcf::INFO,
                {
                    { vcf::ID, vcf::AF },
                    { vcf::NUMBER, vcf::A },
                    { vcf::TYPE, vcf::FLOAT },
                    { vcf::DESCRIPTION, "Allele frequency" }
                },
                source
        });

         
        SECTION("Correct arguments") 
        {
            CHECK_NOTHROW( (vcf::Record{
                                1,
                                "chr1", 
                                123456, 
                                { "id123", "id456" }, 
                                "A", 
                                { "AC", "AT" }, 
                                1.0, 
                                { vcf::PASS }, 
                                { {vcf::AN, "12"}, {vcf::AF, "0.5,0.3"} }, 
                                { vcf::GT, vcf::DP }, 
                                { "0|1" },
                                source} ) );
                
            CHECK_NOTHROW( (vcf::Record{
                                1,
                                "chr1", 
                                123456, 
                                { }, 
                                "A", 
                                { "AC", "AT" }, 
                                1.0, 
                                { vcf::PASS }, 
                                { {vcf::AN, "12"}, {vcf::AF, "0.5,0.3"} }, 
                                { vcf::GT, vcf::DP }, 
                                { "0|1" },
                                source}) );

            CHECK_NOTHROW( (vcf::Record{
                                1,
                                "chr1",
                                123456,
                                { },
                                "A",
                                { "AC", "AT" },
                                1.0,
                                { vcf::PASS },
                                { {vcf::AN, "12"}, {vcf::AF, "0.5,0.3"} },
                                { vcf::DP },
                                { "1" },
                                source}) );
        }

        SECTION("Chromosome with whitespaces") 
        {
            CHECK_THROWS_AS( (vcf::Record{
                                1,
                                "chr 1", 
                                123456, 
                                { "id123", "id456" }, 
                                "A", 
                                { "AC", "AT" }, 
                                1.0, 
                                { vcf::PASS }, 
                                { {vcf::AN, "12"}, {vcf::AF, "0.5,0.3"} }, 
                                { vcf::GT, vcf::DP }, 
                                { "0|1" },
                                source}),
                            vcf::ChromosomeBodyError*);
        }

        SECTION("Chromosome with colons") 
        {
            CHECK_THROWS_AS( (vcf::Record{
                                1,
                                "chr:1", 
                                123456, 
                                { "id123", "id456" }, 
                                "A", 
                                { "AC", "AT" }, 
                                1.0, 
                                { vcf::PASS }, 
                                { {vcf::AN, "12"}, {vcf::AF, "0.5,0.3"} }, 
                                { vcf::GT, vcf::DP }, 
                                { "0|1" },
                                source}),
                            vcf::ChromosomeBodyError*);
        }

        SECTION("ID with whitespaces") 
        {
            CHECK_THROWS_AS( (vcf::Record{
                                1,
                                "chr1", 
                                123456, 
                                { "id 123", "id456" }, 
                                "A", 
                                { "AC", "AT" }, 
                                1.0, 
                                { vcf::PASS }, 
                                { {vcf::AN, "12"}, {vcf::AF, "0.5,0.3"} }, 
                                { vcf::GT, vcf::DP }, 
                                { "0|1" },
                                source}),
                            vcf::IdBodyError*);
        }

        SECTION("Different length alleles")
        {
            CHECK_NOTHROW( (vcf::Record{
                                1,
                                "chr1", 
                                123456, 
                                { "id123", "id456" }, 
                                "A", 
                                { "AT" }, 
                                1.0, 
                                { vcf::PASS }, 
                                { {vcf::AN, "12"}, {vcf::AF, "0.5"} }, 
                                { vcf::GT, vcf::DP }, 
                                { "0|1" },
                                source}) );
                                
            CHECK_NOTHROW( (vcf::Record{
                                1,
                                "chr1", 
                                123456, 
                                { "id123", "id456" }, 
                                "A", 
                                { "CT" }, 
                                1.0, 
                                { vcf::PASS }, 
                                { {vcf::AN, "12"}, {vcf::AF, "0.5"} }, 
                                { vcf::GT, vcf::DP }, 
                                { "0|1" },
                                source}) );
        }
        
        SECTION("Same length alleles") 
        {
            CHECK_NOTHROW( (vcf::Record{
                                1,
                                "chr1",
                                123456, 
                                { "id123", "id456" }, 
                                "A", 
                                { "T", "C" }, 
                                1.0, 
                                { vcf::PASS }, 
                                { {vcf::AN, "12"}, {vcf::AF, "0.5,0.3"} }, 
                                { vcf::GT, vcf::DP }, 
                                { "0|1" },
                                source}) );
        }

        SECTION("Same alleles") 
        {
            CHECK_THROWS_AS( (vcf::Record{
                                1,
                                "chr1",
                                123456, 
                                { "id123", "id456" }, 
                                "A", 
                                { "A" }, 
                                1.0, 
                                { vcf::PASS }, 
                                { {vcf::AN, "12"}, {vcf::AF, "0.5"} }, 
                                { vcf::GT, vcf::DP }, 
                                { "0|1" },
                                source}),
                            vcf::AlternateAllelesBodyError*);
        }

        SECTION("Less-than-zero quality") 
        {
            CHECK_THROWS_AS( (vcf::Record{
                                1,
                                "chr1", 
                                123456, 
                                { "id123", "id456" }, 
                                "A", 
                                { "C" }, 
                                -1.0, 
                                { vcf::PASS }, 
                                { {vcf::AN, "12"}, {vcf::AF, "0.5,0.3"} }, 
                                { vcf::GT, vcf::DP }, 
                                { "0|1" },
                                source}),
                            vcf::QualityBodyError*);
        }

        SECTION("Empty INFO") 
        {
            CHECK_NOTHROW( (vcf::Record{
                                1,
                                "chr1", 
                                123456, 
                                { "id123", "id456" }, 
                                "A", 
                                { "T", "C" }, 
                                1.0, 
                                { vcf::PASS },
                                { { vcf::MISSING_VALUE, vcf::MISSING_VALUE } }, 
                                { vcf::GT, vcf::DP }, 
                                { "0|1" },
                                source}) );
        }

        SECTION("Single-field format") 
        {
            CHECK_NOTHROW( (vcf::Record{
                                1,
                                "chr1", 
                                123456, 
                                { "id123", "id456" }, 
                                "A", 
                                { "T", "C" }, 
                                1.0, 
                                { vcf::PASS }, 
                                { {vcf::AN, "12"}, {vcf::AF, "0.5,0.3"} }, 
                                { vcf::GT }, 
                                { "0|1" },
                                source}) );
                                
            CHECK_NOTHROW( (vcf::Record{
                                1,
                                "chr1", 
                                123456, 
                                { "id123", "id456" }, 
                                "A", 
                                { "T", "C" }, 
                                1.0, 
                                { vcf::PASS }, 
                                { {vcf::AN, "12"}, {vcf::AF, "0.5,0.3"} }, 
                                { vcf::DP },
                                { "13" },
                                source}) );
        }
        
        SECTION("Multi-field format") 
        {
            CHECK_NOTHROW( (vcf::Record{
                                1,
                                "chr1", 
                                123456, 
                                { "id123", "id456" }, 
                                "A", 
                                { "T", "C" }, 
                                1.0, 
                                { vcf::PASS }, 
                                { {vcf::AN, "12"}, {vcf::AF, "0.5,0.3"} }, 
                                { vcf::GT, vcf::DP }, 
                                { "0|1" },
                                source}) );
            
            CHECK_NOTHROW( (vcf::Record{
                                1,
                                "chr1", 
                                123456, 
                                { "id123", "id456" }, 
                                "A", 
                                { "T", "C" }, 
                                1.0, 
                                { vcf::PASS }, 
                                { {vcf::AN, "12"}, {vcf::AF, "0.5,0.3"} }, 
                                { vcf::DP, vcf::GL }, 
                                { "12:0.5,0.7,0.9,0.11,0.15,0.17" },
                                source}) );
                                
            CHECK_THROWS_AS( (vcf::Record{
                                1,
                                "chr1", 
                                123456, 
                                { "id123", "id456" }, 
                                "A",
                                { "T", "C" },
                                1.0, 
                                { vcf::PASS }, 
                                { {vcf::AN, "12"}, {vcf::AF, "0.5,0.3"} }, 
                                { vcf::DP, vcf::GT }, 
                                { "12:0|1" },
                                source}),
                            vcf::FormatBodyError*);
        }

        SECTION("Unusual ploidy")
        {
            CHECK_NOTHROW( (vcf::Record{
                                1,
                                "chr1",
                                123456,
                                { "id123", "id456" },
                                "A",
                                { "T", "C" },
                                1.0,
                                { vcf::PASS },
                                { {vcf::AN, "12"}, {vcf::AF, "0.5,0.3"} },
                                { vcf::GT, vcf::DP },
                                { "0|1" },
                                source}) );

            CHECK_NOTHROW( (vcf::Record{
                                1,
                                "Y",
                                123456,
                                { "id123", "id456" },
                                "A",
                                { "T", "C" },
                                1.0,
                                { vcf::PASS },
                                { {vcf::AN, "12"}, {vcf::AF, "0.5,0.3"} },
                                { vcf::GT, vcf::DP },
                                { "0" },
                                source}) );

// The next check is commented because a mismatch is currently only a warning, but we will process it as an error in the future
//            CHECK_THROWS_AS( (vcf::Record{
//                                1,
//                                "UnspecifiedTriploid",
//                                123456,
//                                { "id123", "id456" },
//                                "A",
//                                { "T", "C" },
//                                1.0,
//                                { vcf::PASS },
//                                { {vcf::AN, "12"}, {vcf::AF, "0.5,0.3"} },
//                                { vcf::GT },
//                                { "0|1|1" },
//                                source}),
//                            vcf::SamplesFieldBodyError*);
        }

        SECTION("Duplicate IDs")
        {
            CHECK_NOTHROW( (vcf::Record{
                                1,
                                "chr1",
                                123456,
                                { "id123", "id123" },
                                "A",
                                { "AC", "AT" },
                                1.0,
                                { vcf::PASS },
                                { {vcf::AN, "12"}, {vcf::AF, "0.5,0.3"} },
                                { vcf::GT, vcf::DP },
                                { "0|1" },
                                source}) );
        }

        SECTION("Duplicate FILTERs")
        {
            CHECK_NOTHROW( (vcf::Record{
                                1,
                                "chr1",
                                123456,
                                { "id123" },
                                "A",
                                { "AC" },
                                1.0,
                                { "q10", "q10" },
                                { {vcf::AN, "12"} },
                                { vcf::GT },
                                { "0|1" },
                                source}) );
        }

        SECTION("Duplicate INFOs")
        {
            CHECK_NOTHROW( (vcf::Record{
                                1,
                                "chr1",
                                123456,
                                { "id123", "id456" },
                                "A",
                                { "T", "C" },
                                1.0,
                                { vcf::PASS },
                                { {vcf::AN, "12"}, {vcf::AN, "15"} },
                                { vcf::DP },
                                { "12" },
                                source}) );
        }

        SECTION("Duplicate FORMATs")
        {
            CHECK_NOTHROW( (vcf::Record{
                                1,
                                "chr1",
                                123456,
                                { "id123", "id456" },
                                "A",
                                { "T", "C" },
                                1.0,
                                { vcf::PASS },
                                { {vcf::AN, "12"}, {vcf::AF, "0.5,0.3"} },
                                { vcf::DP, vcf::DP },
                                { "12:13" },
                                source}) );
        }
    }

    TEST_CASE("Record constructor v42", "[constructor]")
    {
        std::shared_ptr<vcf::Source> source{
            new vcf::Source{
                "Example VCF source",
                vcf::InputFormat::VCF_FILE_VCF | vcf::InputFormat::VCF_FILE_BGZIP,
                vcf::Version::v42,
                {},
                { "Sample1" }}};

        SECTION("Duplicate IDs")
        {
            CHECK_NOTHROW( (vcf::Record{
                                1,
                                "chr1",
                                123456,
                                { "id123", "id123" },
                                "A",
                                { "AC", "AT" },
                                1.0,
                                { vcf::PASS },
                                { {vcf::AN, "12"}, {vcf::AF, "0.5,0.3"} },
                                { vcf::GT, vcf::DP },
                                { "0|1" },
                                source}) );
        }

        SECTION("Duplicate FILTERs")
        {
            CHECK_NOTHROW( (vcf::Record{
                                1,
                                "chr1",
                                123456,
                                { "id123" },
                                "A",
                                { "AC" },
                                1.0,
                                { "q10", "q10" },
                                { {vcf::AN, "12"} },
                                { vcf::GT },
                                { "0|1" },
                                source}) );
        }

        SECTION("Duplicate INFOs")
        {
            CHECK_NOTHROW( (vcf::Record{
                                1,
                                "chr1",
                                123456,
                                { "id123", "id456" },
                                "A",
                                { "T", "C" },
                                1.0,
                                { vcf::PASS },
                                { {vcf::AN, "12"}, {vcf::AN, "15"} },
                                { vcf::DP },
                                { "12" },
                                source}) );
        }

        SECTION("Duplicate FORMATs")
        {
            CHECK_NOTHROW( (vcf::Record{
                                1,
                                "chr1",
                                123456,
                                { "id123", "id456" },
                                "A",
                                { "T", "C" },
                                1.0,
                                { vcf::PASS },
                                { {vcf::AN, "12"}, {vcf::AF, "0.5,0.3"} },
                                { vcf::DP, vcf::DP },
                                { "12:13" },
                                source}) );
        }
    }

    TEST_CASE("Record constructor v43", "[constructor]")
    {            
        std::shared_ptr<vcf::Source> source{
            new vcf::Source{
                "Example VCF source",
                vcf::InputFormat::VCF_FILE_VCF | vcf::InputFormat::VCF_FILE_BGZIP,
                vcf::Version::v43,
                {},
                { "Sample1" }}};

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
                    { vcf::ID, vcf::CN },
                    { vcf::NUMBER, "1" },
                    { vcf::TYPE, vcf::INTEGER },
                    { vcf::DESCRIPTION, "Copy Number Genotype" }
                },
                source
            });
           
        source->meta_entries.emplace(vcf::FORMAT,
            vcf::MetaEntry{
                1,
                vcf::FORMAT,
                {
                    { vcf::ID, vcf::DP },
                    { vcf::NUMBER, "1" },
                    { vcf::TYPE, vcf::INTEGER },
                    { vcf::DESCRIPTION, "Read depth" }
                },
                source
        });

        source->meta_entries.emplace(vcf::FORMAT,
            vcf::MetaEntry{
                1,
                vcf::FORMAT,
                {
                    { vcf::ID, "FormatTag" },
                    { vcf::NUMBER, "2" },
                    { vcf::TYPE, vcf::FLOAT },
                    { vcf::DESCRIPTION, "A custom format tag" }
                },
                source
        });

       source->meta_entries.emplace(vcf::INFO,
            vcf::MetaEntry{
                1,
                vcf::INFO,
                {
                    { vcf::ID, vcf::AN },
                    { vcf::NUMBER, "1" },
                    { vcf::TYPE, vcf::INTEGER },
                    { vcf::DESCRIPTION, "Allele number" }
                },
                source
        });
           
        source->meta_entries.emplace(vcf::INFO,
            vcf::MetaEntry{
                1,
                vcf::INFO,
                {
                    { vcf::ID, vcf::AF },
                    { vcf::NUMBER, vcf::A },
                    { vcf::TYPE, vcf::FLOAT },
                    { vcf::DESCRIPTION, "Allele frequency" }
                },
                source
        });

        source->meta_entries.emplace(vcf::INFO,
            vcf::MetaEntry{
                1,
                vcf::INFO,
                {
                    { vcf::ID, "InfoTag" },
                    { vcf::NUMBER, "1" },
                    { vcf::TYPE, vcf::INTEGER },
                    { vcf::DESCRIPTION, "A custom info tag" }
                },
                source
        });

        SECTION("gVCF allowed in v4.3") 
        {
            CHECK_NOTHROW( (vcf::Record{
                                1,
                                "chr1",
                                123456,
                                { "id123", "id456" },
                                "A",
                                { vcf:: GVCF_NON_VARIANT_ALLELE },
                                1.0,
                                { vcf::PASS },
                                { {vcf::AN, "12"} },
                                { "XY" },
                                { "11" },
                                source}) );
 
            CHECK_NOTHROW( (vcf::Record{
                                1,
                                "chr1",
                                123456,
                                { "id123", "id456" },
                                "A",
                                { vcf::GVCF_NON_VARIANT_ALLELE, "AC" },
                                1.0,
                                { vcf::PASS },
                                { {vcf::AN, "12"} },
                                { "XY" },
                                { "12" },
                                source}) );
       }

        SECTION("Duplicate IDs") 
        {
            CHECK_THROWS_AS( (vcf::Record{
                                1,
                                "chr1", 
                                123456, 
                                { "id123", "id123" }, 
                                "A", 
                                { "AC", "AT" }, 
                                1.0, 
                                { vcf::PASS }, 
                                { {vcf::AN, "12"}, {vcf::AF, "0.5,0.3"} }, 
                                { vcf::GT, vcf::DP }, 
                                { "0|1" },
                                source}),
                            vcf::IdBodyError*);
        }

        SECTION("Duplicate FILTERs")
        {
            CHECK_THROWS_AS( (vcf::Record{
                                1,
                                "chr1",
                                123456,
                                { "id123" },
                                "A",
                                { "AC" },
                                1.0,
                                { "q10", "q10" },
                                { {vcf::AN, "12"} },
                                { vcf::GT },
                                { "0|1" },
                                source}),
                            vcf::FilterBodyError*);
        }

        SECTION("FILTER with value 0")
        {
            CHECK_THROWS_AS( (vcf::Record{
                                1,
                                "chr1",
                                123456,
                                { "id123" },
                                "A",
                                { "AC" },
                                1.0,
                                { "q1", "0" },
                                { {vcf::AN, "12"} },
                                { vcf::GT },
                                { "0|1" },
                                source}),
                            vcf::FilterBodyError*);
        }

        SECTION("Duplicate INFOs") 
        {
            CHECK_THROWS_AS( (vcf::Record{
                                1,
                                "chr1", 
                                123456, 
                                { "id123", "id456" }, 
                                "A",
                                { "T", "C" },
                                1.0, 
                                { vcf::PASS }, 
                                { {vcf::AN, "12"}, {vcf::AN, "15"} }, 
                                { vcf::DP }, 
                                { "12" },
                                source}),
                            vcf::InfoBodyError*);
        }

        SECTION("Duplicate FORMATs")
        {
            CHECK_THROWS_AS( (vcf::Record{
                                1,
                                "chr1",
                                123456,
                                { "id123", "id456" },
                                "A",
                                { "T", "C" },
                                1.0,
                                { vcf::PASS },
                                { {vcf::AN, "12"}, {vcf::AF, "0.5,0.3"} },
                                { vcf::DP, vcf::DP },
                                { "12:13" },
                                source}),
                            vcf::FormatBodyError*);
        }

        SECTION("Conflicting data line values and meta header definition")
        {
            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123", "id456" },
                            "A",
                            { "AC", "AT" },
                            1.0,
                            { vcf::PASS },
                            { {"InfoTag", "1.89"}, { vcf::AF, "0.5,0.3"} },
                            { vcf::GT, vcf::DP },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123", "id456" },
                            "A",
                            { "AC", "AT" },
                            1.0,
                            { vcf::PASS },
                            { {"InfoTag", "1,2,3"}, { vcf::AF, "0.5,0.3"} },
                            { vcf::GT, vcf::DP },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123", "id456" },
                            "A",
                            { "AC", "AT" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::AN, "12"}, { vcf::AF, "0.5,0.3"} },
                            { vcf::GT, "FormatTag" },
                            { "0|1:ta,gs" },
                            source}),
                        vcf::SamplesFieldBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123", "id456" },
                            "A",
                            { "AC", "AT" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::AN, "12"}, { vcf::AF, "0.5,0.3"} },
                            { vcf::GT, "FormatTag" },
                            { "0|1:1.5" },
                            source}),
                        vcf::SamplesFieldBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123", "id456" },
                            "A",
                            { "AC", "AT" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::AN, "12"}, { vcf::AF, "0.5,0.3"} },
                            { vcf::GT, vcf::DP },
                            { "0|1:tags" },
                            source}),
                        vcf::SamplesFieldBodyError*);

            // Copy number genotypes should have a genotype representation with just an Integer
            CHECK_THROWS_AS((vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123", "id456" },
                            "A",
                            { "AC", "AT" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::AN, "12"}, { vcf::AF, "0.5,0.3"} },
                            { vcf::CN },
                            { "0|0" },
                            source }),
                            vcf::SamplesFieldBodyError*);


            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123", "id456" },
                            "A",
                            { "AC", "AT" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::AN, "12"}, { vcf::AF, "0.5"} },
                            { vcf::GT, vcf::DP },
                            { "0|1:1" },
                            source}),
                        vcf::InfoBodyError*);
        }
    }

    TEST_CASE("Record constructor v44", "[constructor]")
    {
        std::shared_ptr<vcf::Source> source{
            new vcf::Source{
                "Example VCF source",
                vcf::InputFormat::VCF_FILE_VCF | vcf::InputFormat::VCF_FILE_BGZIP,
                vcf::Version::v44,
                {},
                { "Sample1" }}};

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
                    { vcf::ID, vcf::CN },
                    { vcf::NUMBER, "1" },
                    { vcf::TYPE, vcf::INTEGER },
                    { vcf::DESCRIPTION, "Copy Number Genotype" }
                },
                source
            });

        source->meta_entries.emplace(vcf::FORMAT,
            vcf::MetaEntry{
                1,
                vcf::FORMAT,
                {
                    { vcf::ID, vcf::DP },
                    { vcf::NUMBER, "1" },
                    { vcf::TYPE, vcf::INTEGER },
                    { vcf::DESCRIPTION, "Read depth" }
                },
                source
        });

        source->meta_entries.emplace(vcf::FORMAT,
            vcf::MetaEntry{
                1,
                vcf::FORMAT,
                {
                    { vcf::ID, "FormatTag" },
                    { vcf::NUMBER, "2" },
                    { vcf::TYPE, vcf::FLOAT },
                    { vcf::DESCRIPTION, "A custom format tag" }
                },
                source
        });

       source->meta_entries.emplace(vcf::INFO,
            vcf::MetaEntry{
                1,
                vcf::INFO,
                {
                    { vcf::ID, vcf::AN },
                    { vcf::NUMBER, "1" },
                    { vcf::TYPE, vcf::INTEGER },
                    { vcf::DESCRIPTION, "Allele number" }
                },
                source
        });

        source->meta_entries.emplace(vcf::INFO,
            vcf::MetaEntry{
                1,
                vcf::INFO,
                {
                    { vcf::ID, vcf::AF },
                    { vcf::NUMBER, vcf::A },
                    { vcf::TYPE, vcf::FLOAT },
                    { vcf::DESCRIPTION, "Allele frequency" }
                },
                source
        });

        source->meta_entries.emplace(vcf::INFO,
            vcf::MetaEntry{
                1,
                vcf::INFO,
                {
                    { vcf::ID, "InfoTag" },
                    { vcf::NUMBER, "1" },
                    { vcf::TYPE, vcf::INTEGER },
                    { vcf::DESCRIPTION, "A custom info tag" }
                },
                source
        });

        SECTION("gVCF allowed in v4.4")
        {
            CHECK_NOTHROW( (vcf::Record{
                                1,
                                "chr1",
                                123456,
                                { "id123", "id456" },
                                "A",
                                { vcf:: GVCF_NON_VARIANT_ALLELE },
                                1.0,
                                { vcf::PASS },
                                { {vcf::AN, "12"} },
                                { "XY" },
                                { "11" },
                                source}) );

            CHECK_NOTHROW( (vcf::Record{
                                1,
                                "chr1",
                                123456,
                                { "id123", "id456" },
                                "A",
                                { vcf::GVCF_NON_VARIANT_ALLELE, "AC" },
                                1.0,
                                { vcf::PASS },
                                { {vcf::AN, "12"} },
                                { "XY" },
                                { "12" },
                                source}) );
       }

        SECTION("Duplicate IDs")
        {
            CHECK_THROWS_AS( (vcf::Record{
                                1,
                                "chr1",
                                123456,
                                { "id123", "id123" },
                                "A",
                                { "AC", "AT" },
                                1.0,
                                { vcf::PASS },
                                { {vcf::AN, "12"}, {vcf::AF, "0.5,0.3"} },
                                { vcf::GT, vcf::DP },
                                { "0|1" },
                                source}),
                            vcf::IdBodyError*);
        }

        SECTION("Duplicate FILTERs")
        {
            CHECK_THROWS_AS( (vcf::Record{
                                1,
                                "chr1",
                                123456,
                                { "id123" },
                                "A",
                                { "AC" },
                                1.0,
                                { "q10", "q10" },
                                { {vcf::AN, "12"} },
                                { vcf::GT },
                                { "0|1" },
                                source}),
                            vcf::FilterBodyError*);
        }

        SECTION("FILTER with value 0")
        {
            CHECK_THROWS_AS( (vcf::Record{
                                1,
                                "chr1",
                                123456,
                                { "id123" },
                                "A",
                                { "AC" },
                                1.0,
                                { "q1", "0" },
                                { {vcf::AN, "12"} },
                                { vcf::GT },
                                { "0|1" },
                                source}),
                            vcf::FilterBodyError*);
        }

        SECTION("Duplicate INFOs")
        {
            CHECK_THROWS_AS( (vcf::Record{
                                1,
                                "chr1",
                                123456,
                                { "id123", "id456" },
                                "A",
                                { "T", "C" },
                                1.0,
                                { vcf::PASS },
                                { {vcf::AN, "12"}, {vcf::AN, "15"} },
                                { vcf::DP },
                                { "12" },
                                source}),
                            vcf::InfoBodyError*);
        }

        SECTION("Duplicate FORMATs")
        {
            CHECK_THROWS_AS( (vcf::Record{
                                1,
                                "chr1",
                                123456,
                                { "id123", "id456" },
                                "A",
                                { "T", "C" },
                                1.0,
                                { vcf::PASS },
                                { {vcf::AN, "12"}, {vcf::AF, "0.5,0.3"} },
                                { vcf::DP, vcf::DP },
                                { "12:13" },
                                source}),
                            vcf::FormatBodyError*);
        }

        SECTION("Conflicting data line values and meta header definition")
        {
            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123", "id456" },
                            "A",
                            { "AC", "AT" },
                            1.0,
                            { vcf::PASS },
                            { {"InfoTag", "1.89"}, { vcf::AF, "0.5,0.3"} },
                            { vcf::GT, vcf::DP },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123", "id456" },
                            "A",
                            { "AC", "AT" },
                            1.0,
                            { vcf::PASS },
                            { {"InfoTag", "1,2,3"}, { vcf::AF, "0.5,0.3"} },
                            { vcf::GT, vcf::DP },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123", "id456" },
                            "A",
                            { "AC", "AT" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::AN, "12"}, { vcf::AF, "0.5,0.3"} },
                            { vcf::GT, "FormatTag" },
                            { "0|1:ta,gs" },
                            source}),
                        vcf::SamplesFieldBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123", "id456" },
                            "A",
                            { "AC", "AT" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::AN, "12"}, { vcf::AF, "0.5,0.3"} },
                            { vcf::GT, "FormatTag" },
                            { "0|1:1.5" },
                            source}),
                        vcf::SamplesFieldBodyError*);

            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123", "id456" },
                            "A",
                            { "AC", "AT" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::AN, "12"}, { vcf::AF, "0.5,0.3"} },
                            { vcf::GT, vcf::DP },
                            { "0|1:tags" },
                            source}),
                        vcf::SamplesFieldBodyError*);

            // Copy number genotypes should have a genotype representation with just an Integer
            CHECK_THROWS_AS((vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123", "id456" },
                            "A",
                            { "AC", "AT" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::AN, "12"}, { vcf::AF, "0.5,0.3"} },
                            { vcf::CN },
                            { "0|0" },
                            source }),
                            vcf::SamplesFieldBodyError*);


            CHECK_THROWS_AS( (vcf::Record{
                            1,
                            "chr1",
                            123456,
                            { "id123", "id456" },
                            "A",
                            { "AC", "AT" },
                            1.0,
                            { vcf::PASS },
                            { {vcf::AN, "12"}, { vcf::AF, "0.5"} },
                            { vcf::GT, vcf::DP },
                            { "0|1:1" },
                            source}),
                        vcf::InfoBodyError*);
        }
    }

}
