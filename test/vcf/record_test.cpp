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
                vcf::Ploidy{2, {{"Y", 1}}},
                {},
                { "Sample1" }}};
            
        source->meta_entries.emplace("FORMAT",
            vcf::MetaEntry{
                1,
                "FORMAT",
                {
                    { "ID", "GT" },
                    { "Number", "1" },
                    { "Type", "String" },
                    { "Description", "Genotype" }
                },
                source
        });
           
        source->meta_entries.emplace("FORMAT",
            vcf::MetaEntry{
                1,
                "FORMAT",
                {
                    { "ID", "DP" },
                    { "Number", "1" },
                    { "Type", "Integer" },
                    { "Description", "Read depth" }
                },
                source
        });

        source->meta_entries.emplace("INFO",
            vcf::MetaEntry{
                1,
                "INFO",
                {
                    { "ID", "AN" },
                    { "Number", "1" },
                    { "Type", "Integer" },
                    { "Description", "Allele number" }
                },
                source
        });
           
        source->meta_entries.emplace("INFO",
            vcf::MetaEntry{
                1,
                "INFO",
                {
                    { "ID", "AF" },
                    { "Number", "A" },
                    { "Type", "Float" },
                    { "Description", "Allele frequency" }
                },
                source
        });

         
        SECTION("Correct arguments") 
        {
            CHECK_NOTHROW( (vcf::Record {
                                1,
                                "chr1", 
                                123456, 
                                { "id123", "id456" }, 
                                "A", 
                                { "AC", "AT" }, 
                                1.0, 
                                { "PASS" }, 
                                { {"AN", "12"}, {"AF", "0.5,0.3"} }, 
                                { "GT", "DP" }, 
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
                                { "PASS" }, 
                                { {"AN", "12"}, {"AF", "0.5,0.3"} }, 
                                { "GT", "DP" }, 
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
                                { "PASS" },
                                { {"AN", "12"}, {"AF", "0.5,0.3"} },
                                { "DP" },
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
                                { "PASS" }, 
                                { {"AN", "12"}, {"AF", "0.5,0.3"} }, 
                                { "GT", "DP" }, 
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
                                { "PASS" }, 
                                { {"AN", "12"}, {"AF", "0.5,0.3"} }, 
                                { "GT", "DP" }, 
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
                                { "PASS" }, 
                                { {"AN", "12"}, {"AF", "0.5,0.3"} }, 
                                { "GT", "DP" }, 
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
                                { "PASS" }, 
                                { {"AN", "12"}, {"AF", "0.5"} }, 
                                { "GT", "DP" }, 
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
                                { "PASS" }, 
                                { {"AN", "12"}, {"AF", "0.5"} }, 
                                { "GT", "DP" }, 
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
                                { "PASS" }, 
                                { {"AN", "12"}, {"AF", "0.5,0.3"} }, 
                                { "GT", "DP" }, 
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
                                { "PASS" }, 
                                { {"AN", "12"}, {"AF", "0.5"} }, 
                                { "GT", "DP" }, 
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
                                { "PASS" }, 
                                { {"AN", "12"}, {"AF", "0.5,0.3"} }, 
                                { "GT", "DP" }, 
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
                                { "PASS" }, 
                                { { ".", "." } }, 
                                { "GT", "DP" }, 
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
                                { "PASS" }, 
                                { {"AN", "12"}, {"AF", "0.5,0.3"} }, 
                                { "GT" }, 
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
                                { "PASS" }, 
                                { {"AN", "12"}, {"AF", "0.5,0.3"} }, 
                                { "DP" },
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
                                { "PASS" }, 
                                { {"AN", "12"}, {"AF", "0.5,0.3"} }, 
                                { "GT", "DP" }, 
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
                                { "PASS" }, 
                                { {"AN", "12"}, {"AF", "0.5,0.3"} }, 
                                { "DP", "GL" }, 
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
                                { "PASS" }, 
                                { {"AN", "12"}, {"AF", "0.5,0.3"} }, 
                                { "DP", "GT" }, 
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
                                { "PASS" },
                                { {"AN", "12"}, {"AF", "0.5,0.3"} },
                                { "GT", "DP" },
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
                                { "PASS" },
                                { {"AN", "12"}, {"AF", "0.5,0.3"} },
                                { "GT", "DP" },
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
//                                { "PASS" },
//                                { {"AN", "12"}, {"AF", "0.5,0.3"} },
//                                { "GT" },
//                                { "0|1|1" },
//                                source}),
//                            vcf::SamplesFieldBodyError*);
        }
    }

    TEST_CASE("Record constructor v43", "[constructor]")
    {            
        std::shared_ptr<vcf::Source> source{
            new vcf::Source{
                "Example VCF source",
                vcf::InputFormat::VCF_FILE_VCF | vcf::InputFormat::VCF_FILE_BGZIP,
                vcf::Version::v43,
                vcf::Ploidy{2, {{"Y", 1}}},
                {},
                { "Sample1" }}};

        source->meta_entries.emplace("FORMAT",
            vcf::MetaEntry{
                1,
                "FORMAT",
                {
                    { "ID", "GT" },
                    { "Number", "1" },
                    { "Type", "String" },
                    { "Description", "Genotype" }
                },
                source
        });
           
        source->meta_entries.emplace("FORMAT",
            vcf::MetaEntry{
                1,
                "FORMAT",
                {
                    { "ID", "DP" },
                    { "Number", "1" },
                    { "Type", "Integer" },
                    { "Description", "Read depth" }
                },
                source
        });

        source->meta_entries.emplace("FORMAT",
            vcf::MetaEntry{
                1,
                "FORMAT",
                {
                    { "ID", "FormatTag" },
                    { "Number", "2" },
                    { "Type", "Float" },
                    { "Description", "A custom format tag" }
                },
                source
        });

       source->meta_entries.emplace("INFO",
            vcf::MetaEntry{
                1,
                "INFO",
                {
                    { "ID", "AN" },
                    { "Number", "1" },
                    { "Type", "Integer" },
                    { "Description", "Allele number" }
                },
                source
        });
           
        source->meta_entries.emplace("INFO",
            vcf::MetaEntry{
                1,
                "INFO",
                {
                    { "ID", "AF" },
                    { "Number", "A" },
                    { "Type", "Float" },
                    { "Description", "Allele frequency" }
                },
                source
        });

        source->meta_entries.emplace("INFO",
            vcf::MetaEntry{
                1,
                "INFO",
                {
                    { "ID", "InfoTag" },
                    { "Number", "1" },
                    { "Type", "Integer" },
                    { "Description", "A custom info tag" }
                },
                source
        });

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
                                { "PASS" }, 
                                { {"AN", "12"}, {"AF", "0.5,0.3"} }, 
                                { "GT", "DP" }, 
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
                                { {"AN", "12"} },
                                { "GT" },
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
                                { {"AN", "12"} },
                                { "GT" },
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
                                { "PASS" }, 
                                { {"AN", "12"}, {"AN", "15"} }, 
                                { "DP" }, 
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
                                { "PASS" },
                                { {"AN", "12"}, {"AF", "0.5,0.3"} },
                                { "DP", "DP" },
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
                            { "PASS" },
                            { {"InfoTag", "1.89"}, { "AF", "0.5,0.3"} },
                            { "GT", "DP" },
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
                            { "PASS" },
                            { {"InfoTag", "1,2,3"}, { "AF", "0.5,0.3"} },
                            { "GT", "DP" },
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
                            { "PASS" },
                            { {"AN", "12"}, { "AF", "0.5,0.3"} },
                            { "GT", "FormatTag" },
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
                            { "PASS" },
                            { {"AN", "12"}, { "AF", "0.5,0.3"} },
                            { "GT", "FormatTag" },
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
                            { "PASS" },
                            { {"AN", "12"}, { "AF", "0.5,0.3"} },
                            { "GT", "DP" },
                            { "0|1:tags" },
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
                            { "PASS" },
                            { {"AN", "12"}, { "AF", "0.5"} },
                            { "GT", "DP" },
                            { "0|1:1" },
                            source}),
                        vcf::InfoBodyError*);
        }
    }

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
                            { {"1000G", "0,1,0"} },
                            { "GT" },
                            { "0|1" },
                            source}),
                        vcf::InfoBodyError*);
        }

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
                            { "CNP" },
                            { "1.34" },
                            source}),
                        vcf::SamplesFieldBodyError*);
        
        }
    }
}
