/**
 * Copyright 2015 EMBL - European Bioinformatics Institute
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
    
    TEST_CASE("Record constructor", "[constructor]")
    {
        auto source = vcf::Source {
            "Example VCF source",
            vcf::InputFormat::VCF_FILE_VCF | vcf::InputFormat::VCF_FILE_BGZIP,
            vcf::Version::v41,
            {},
            { "Sample1" }};
            
        source.meta_entries.emplace("FORMAT",
            vcf::MetaEntry{
                1,
                "FORMAT",
                {
                    { "ID", "GT" },
                    { "Number", "1" },
                    { "Type", "String" },
                    { "Description", "Genotype" }
                }
        });
           
        source.meta_entries.emplace("FORMAT",
            vcf::MetaEntry{
                1,
                "FORMAT",
                {
                    { "ID", "DP" },
                    { "Number", "1" },
                    { "Type", "Integer" },
                    { "Description", "Read depth" }
                }
            });

        source.meta_entries.emplace("INFO",
            vcf::MetaEntry{
                1,
                "INFO",
                {
                    { "ID", "AN" },
                    { "Number", "A" },
                    { "Type", "Integer" },
                    { "Description", "Allele number" }
                }
        });
           
        source.meta_entries.emplace("INFO",
            vcf::MetaEntry{
                1,
                "INFO",
                {
                    { "ID", "AF" },
                    { "Number", "A" },
                    { "Type", "Float" },
                    { "Description", "Allele frequency" }
                }
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
                                { {"AN", "12,7"}, {"AF", "0.5,0.3"} }, 
                                { "GT", "DP" }, 
                                { "0|1" },
                                std::make_shared<vcf::Source>(source)} ) );
                
            CHECK_NOTHROW( (vcf::Record{
                                1,
                                "chr1", 
                                123456, 
                                { }, 
                                "A", 
                                { "AC", "AT" }, 
                                1.0, 
                                { "PASS" }, 
                                { {"AN", "12,7"}, {"AF", "0.5,0.3"} }, 
                                { "GT", "DP" }, 
                                { "0|1" },
                                std::make_shared<vcf::Source>(source)}) );
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
                                { {"AN", "12,7"}, {"AF", "0.5,0.3"} }, 
                                { "GT", "DP" }, 
                                { "0|1" },
                                std::make_shared<vcf::Source>(source)}),
                            vcf::ChromosomeBodyError);
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
                                { {"AN", "12,7"}, {"AF", "0.5,0.3"} }, 
                                { "GT", "DP" }, 
                                { "0|1" },
                                std::make_shared<vcf::Source>(source)}),
                            vcf::ChromosomeBodyError);
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
                                { {"AN", "12,7"}, {"AF", "0.5,0.3"} }, 
                                { "GT", "DP" }, 
                                { "0|1" },
                                std::make_shared<vcf::Source>(source)}),
                            vcf::IdBodyError);
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
                                std::make_shared<vcf::Source>(source)}) );
                                
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
                                std::make_shared<vcf::Source>(source)}) );
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
                                { {"AN", "12,7"}, {"AF", "0.5,0.3"} }, 
                                { "GT", "DP" }, 
                                { "0|1" },
                                std::make_shared<vcf::Source>(source)}) );
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
                                std::make_shared<vcf::Source>(source)}),
                            vcf::AlternateAllelesBodyError);
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
                                { {"AN", "12,7"}, {"AF", "0.5,0.3"} }, 
                                { "GT", "DP" }, 
                                { "0|1" },
                                std::make_shared<vcf::Source>(source)}),
                            vcf::QualityBodyError);
        }

        SECTION("Emtpy INFO") 
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
                                std::make_shared<vcf::Source>(source)}) );
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
                                { {"AN", "12,7"}, {"AF", "0.5,0.3"} }, 
                                { "GT", "DP" }, 
                                { "0|1" },
                                std::make_shared<vcf::Source>(source)}) );
                                
            CHECK_THROWS_AS( (vcf::Record{
                                1,
                                "chr1", 
                                123456, 
                                { "id123", "id456" }, 
                                "A", 
                                { "T", "C" }, 
                                1.0, 
                                { "PASS" }, 
                                { {"AN", "12,7"}, {"AF", "0.5,0.3"} }, 
                                { "DP" }, 
                                { "0|1" },
                                std::make_shared<vcf::Source>(source)}),
                            vcf::FormatBodyError);
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
                                { {"AN", "12,7"}, {"AF", "0.5,0.3"} }, 
                                { "GT", "DP" }, 
                                { "0|1" },
                                std::make_shared<vcf::Source>(source)}) );
                                
            CHECK_THROWS_AS( (vcf::Record{
                                1,
                                "chr1", 
                                123456, 
                                { "id123", "id456" }, 
                                "A", 
                                { "T", "C" },
                                1.0, 
                                { "PASS" }, 
                                { {"AN", "12,7"}, {"AF", "0.5,0.3"} }, 
                                { "DP", "GT" }, 
                                { "0|1" },
                                std::make_shared<vcf::Source>(source)}),
                            vcf::FormatBodyError);
        }
        
    }

}
