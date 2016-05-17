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
#include <iostream>
#include <typeinfo>

#include "catch/catch.hpp"

#include "vcf/file_structure.hpp"
#include "vcf/error.hpp"

namespace ebi
{

    TEST_CASE("MetaEntry constructor (no value)", "[constructor][novalue]") 
    {
        auto source = vcf::Source {
            "Example VCF source",
            vcf::InputFormat::VCF_FILE_VCF | vcf::InputFormat::VCF_FILE_BGZIP,
            vcf::Version::v41,
            {},
            { "Sample1", "Sample2", "Sample3" }};
            
            SECTION ("It should work with any ID and source")
            {
                CHECK_NOTHROW( (vcf::MetaEntry { 1, "reference" }) );
            }
            
            SECTION ("No value should be assigned")
            {
                auto meta = vcf::MetaEntry { 1, "reference" } ;
                
                CHECK( meta.id == "reference" );
                CHECK( meta.structure == vcf::MetaEntry::Structure::NoValue );
                CHECK( boost::get<std::string>(meta.value) == std::string {} );
                CHECK_THROWS_AS( (boost::get<std::map<std::string,std::string>>(meta.value)),
                                boost::bad_get);
            }
    }

    TEST_CASE("MetaEntry constructor (plain value)", "[constructor][plainvalue]") 
    {
        auto source = vcf::Source {
            "Example VCF source",
            vcf::InputFormat::VCF_FILE_VCF | vcf::InputFormat::VCF_FILE_BGZIP,
            vcf::Version::v42,
            {},
            { "Sample1", "Sample2", "Sample3" }};

            
            SECTION("Correct arguments")
            {
                CHECK_NOTHROW( (vcf::MetaEntry { 1, "assembly", "GRCh37" }) );
            }
            
            SECTION("A one-line string value should be assigned")
            {
                auto meta = vcf::MetaEntry { 1, "assembly", "GRCh37" } ;
                        
                CHECK( meta.structure == vcf::MetaEntry::Structure::PlainValue );
                CHECK( meta.id == "assembly" );
                CHECK( boost::get<std::string>(meta.value) == std::string{"GRCh37"} );
                CHECK_THROWS_AS( (boost::get<std::map<std::string,std::string>>(meta.value)),
                                boost::bad_get);
            }
                
            SECTION("A multi-line string value should throw an error")
            {
                CHECK_THROWS_AS( (vcf::MetaEntry { 1, "assembly", "GRCh37\nGRCh37" } ),
                                vcf::MetaSectionError);
            }
    }

    TEST_CASE("MetaEntry constructor (key-value pairs)", "[constructor][keyvalue]") 
    {
        auto source = vcf::Source {
            "Example VCF source",
            vcf::InputFormat::VCF_FILE_VCF | vcf::InputFormat::VCF_FILE_BGZIP,
            vcf::Version::v43,
            {},
            { "Sample1", "Sample2", "Sample3" }};
            
        SECTION("Correct arguments")
        {
            CHECK_NOTHROW( (vcf::MetaEntry {
                            1,
                            "contig",
                            { {"ID", "contig_1"} }} ) );
        }
            
        
        SECTION("A key-pair map should be assigned")
        {
            auto meta = vcf::MetaEntry {
                            1,
                            "contig",
                            { {"ID", "contig_1"} }} ;

            CHECK( meta.id == "contig" );
            CHECK( meta.structure == vcf::MetaEntry::Structure::KeyValue );
            CHECK_THROWS_AS( boost::get<std::string>(meta.value),
                            boost::bad_get);
            CHECK( (boost::get<std::map<std::string,std::string>>(meta.value)) == (std::map<std::string,std::string>{ {"ID", "contig_1"} }) );
        }
        
    }
    
    
    TEST_CASE("ALT MetaEntry checks", "[checks][keyvalue]") 
    {
        auto source = vcf::Source {
            "Example VCF source",
            vcf::InputFormat::VCF_FILE_VCF | vcf::InputFormat::VCF_FILE_BGZIP,
            vcf::Version::v41,
            {},
            { "Sample1", "Sample2", "Sample3" }};
            
        SECTION("ID and Description presence")
        {
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                "ALT",
                                { {"ID", "INS"}, {"Description", "tag_description"} }
                            } ) );
                                
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                "ALT",
                                { {"Description", "tag_description"} }
                            }),
                            vcf::MetaSectionError );
                                
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                "ALT",
                                { {"ID", "TAG_ID"} }
                            }),
                            vcf::MetaSectionError );
        }
        
        SECTION("ID prefixes")
        {
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                "ALT",
                                { {"ID", "DEL"}, {"Description", "tag_description"} }
                            } ) );
                              
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                "ALT",
                                { {"ID", "INS"}, {"Description", "tag_description"} }
                            } ) );
                             
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                "ALT",
                                { {"ID", "DUP"}, {"Description", "tag_description"} }
                            } ) );
                             
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                "ALT",
                                { {"ID", "INV"}, {"Description", "tag_description"} }
                            } ) );
                             
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                "ALT",
                                { {"ID", "CNV"}, {"Description", "tag_description"} }
                            } ) );
                               
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                "ALT",
                                { {"ID", "DEL:FOO"}, {"Description", "tag_description"} }
                            } ) );
                                
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                "ALT",
                                { {"ID", "INS:FOO"}, {"Description", "tag_description"} }
                            } ) );
                                
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                "ALT",
                                { {"ID", "DUP:FOO"}, {"Description", "tag_description"} }
                            } ) );
                                
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                "ALT",
                                { {"ID", "INV:FOO"}, {"Description", "tag_description"} }
                            } ) );
                                
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                "ALT",
                                { {"ID", "CNV:FOO"}, {"Description", "tag_description"} }
                            } ) );
                                  
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                "ALT",
                                { {"ID", "CNV:FOO:BAR"}, {"Description", "tag_description"} }
                            } ) );
                                
        }
    }

    TEST_CASE("contig MetaEntry checks", "[checks][keyvalue]") 
    {
        auto source = vcf::Source {
            "Example VCF source",
            vcf::InputFormat::VCF_FILE_VCF | vcf::InputFormat::VCF_FILE_BGZIP,
            vcf::Version::v42,
            {},
            { "Sample1", "Sample2", "Sample3" }};
            
        SECTION("ID presence")
        {
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                "contig",
                                { {"ID", "contig_1"} }
                            } ) );
                                
            CHECK_NOTHROW( (vcf::MetaEntry { 
                                1,
                                "contig",
                                { {"ID", "contig_2"}, {"Description", "tag_description"} }
                            } ) );
                                
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                "contig",
                                { {"Description", "tag_description"} }
                            }),
                            vcf::MetaSectionError );
        }
    }
    
    TEST_CASE("FILTER MetaEntry checks", "[checks][keyvalue]") 
    {
        auto source = vcf::Source {
            "Example VCF source",
            vcf::InputFormat::VCF_FILE_VCF | vcf::InputFormat::VCF_FILE_BGZIP,
            vcf::Version::v43,
            {},
            { "Sample1", "Sample2", "Sample3" }};
            
        SECTION("ID and Description presence")
        {
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                "FILTER",
                                { {"ID", "Filter1"}, {"Description", "tag_description"} }
                            } ) );
                                
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                "FILTER",
                                { {"Description", "tag_description"} }
                            }),
                            vcf::MetaSectionError );
                                
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                "FILTER",
                                { {"ID", "TAG_ID"} }
                            }),
                            vcf::MetaSectionError );
        }
    }
    
    TEST_CASE("FORMAT MetaEntry checks", "[checks][keyvalue]") 
    {
        auto source = vcf::Source {
            "Example VCF source",
            vcf::InputFormat::VCF_FILE_VCF | vcf::InputFormat::VCF_FILE_BGZIP,
            vcf::Version::v41,
            {},
            { "Sample1", "Sample2", "Sample3" }};
            
        SECTION("ID, Number, Type and Description presence")
        {
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                "FORMAT",
                                { {"ID", "GT"}, {"Number", "1"}, {"Type", "String"}, {"Description", "Genotype"} }
                            } ) );
                                
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                "FORMAT",
                                { {"Number", "1"}, {"Type", "String"}, {"Description", "Genotype"} }
                            }),
                            vcf::MetaSectionError );
                                
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                "FORMAT",
                                { {"ID", "GT"}, {"Type", "String"}, {"Description", "Genotype"} }
                            }),
                            vcf::MetaSectionError );
                                
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                "FORMAT",
                                { {"ID", "GT"}, {"Number", "1"}, {"Description", "Genotype"} }
                            }),
                            vcf::MetaSectionError );
                                
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                "FORMAT",
                                { {"ID", "GT"}, {"Number", "1"}, {"Type", "String"} }
                            }),
                            vcf::MetaSectionError );
        }
        
        SECTION("Number field values")
        {
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                "FORMAT",
                                { {"ID", "GT"}, {"Number", "10"}, {"Type", "String"}, {"Description", "Genotype"} }
                            } ) );
                                
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                "FORMAT",
                                { {"ID", "GT"}, {"Number", "A"}, {"Type", "String"}, {"Description", "Genotype"} }
                            } ) );
                                
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                "FORMAT",
                                { {"ID", "GT"}, {"Number", "R"}, {"Type", "String"}, {"Description", "Genotype"} }
                            } ) );
                                
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                "FORMAT",
                                { {"ID", "GT"}, {"Number", "G"}, {"Type", "String"}, {"Description", "Genotype"} }
                            } ) );
                            
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                "FORMAT",
                                { {"ID", "GT"}, {"Number", "."}, {"Type", "String"}, {"Description", "Genotype"} }
                            } ) );
                            
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                "FORMAT",
                                { {"ID", "GT"}, {"Number", "10a"}, {"Type", "String"}, {"Description", "Genotype"} }
                            }),
                            vcf::MetaSectionError );
                                
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                "FORMAT",
                                { {"ID", "GT"}, {"Number", "D"}, {"Type", "String"}, {"Description", "Genotype"} }
                            }),
                            vcf::MetaSectionError );
        }
        
        SECTION("Type field values")
        {
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                "FORMAT",
                                { {"ID", "GT"}, {"Number", "10"}, {"Type", "Integer"}, {"Description", "Genotype"} }
                            } ) );
                                
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                "FORMAT",
                                { {"ID", "GT"}, {"Number", "A"}, {"Type", "Float"}, {"Description", "Genotype"} }
                            } ) );
                                
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                "FORMAT",
                                { {"ID", "GT"}, {"Number", "R"}, {"Type", "Character"}, {"Description", "Genotype"} }
                            } ) );
                                
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                "FORMAT",
                                { {"ID", "GT"}, {"Number", "G"}, {"Type", "String"}, {"Description", "Genotype"} }
                            } ) );
                            
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                "FORMAT",
                                { {"ID", "GT"}, {"Number", "1"}, {"Type", "."}, {"Description", "Genotype"} }
                            }),
                            vcf::MetaSectionError );
                                
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                "FORMAT",
                                { {"ID", "GT"}, {"Number", "1"}, {"Type", "int"}, {"Description", "Genotype"} }
                            }),
                            vcf::MetaSectionError );
        }
    }
    
    TEST_CASE("INFO MetaEntry checks", "[checks][keyvalue]") 
    {
        auto source = vcf::Source {
            "Example VCF source",
            vcf::InputFormat::VCF_FILE_VCF | vcf::InputFormat::VCF_FILE_BGZIP,
            vcf::Version::v42,
            {},
            { "Sample1", "Sample2", "Sample3" }};
            
        SECTION("ID, Number, Type and Description presence")
        {
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                "INFO",
                                { {"ID", "GT"}, {"Number", "1"}, {"Type", "String"}, {"Description", "Genotype"} }
                            } ) );
                                
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                "INFO",
                                { {"Number", "1"}, {"Type", "String"}, {"Description", "Genotype"} }
                            }),
                            vcf::MetaSectionError );
                                
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                "INFO",
                                { {"ID", "GT"}, {"Type", "String"}, {"Description", "Genotype"} }
                            }),
                            vcf::MetaSectionError );
                                
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                "INFO",
                                { {"ID", "GT"}, {"Number", "1"}, {"Description", "Genotype"} }
                            }),
                            vcf::MetaSectionError );
                                
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                "INFO",
                                { {"ID", "GT"}, {"Number", "1"}, {"Type", "String"} }
                            }),
                            vcf::MetaSectionError );
        }
        
        SECTION("Number field values")
        {
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                "INFO",
                                { {"ID", "GT"}, {"Number", "10"}, {"Type", "String"}, {"Description", "Genotype"} }
                            } ) );
                                
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                "INFO",
                                { {"ID", "GT"}, {"Number", "A"}, {"Type", "String"}, {"Description", "Genotype"} }
                            } ) );
                                
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                "INFO",
                                { {"ID", "GT"}, {"Number", "R"}, {"Type", "String"}, {"Description", "Genotype"} }
                            } ) );
                                
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                "INFO",
                                { {"ID", "GT"}, {"Number", "G"}, {"Type", "String"}, {"Description", "Genotype"} }
                            } ) );
                            
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                "INFO",
                                { {"ID", "GT"}, {"Number", "."}, {"Type", "String"}, {"Description", "Genotype"} }
                            } ) );
                            
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                "INFO",
                                { {"ID", "GT"}, {"Number", "10a"}, {"Type", "String"}, {"Description", "Genotype"} }
                            }),
                            vcf::MetaSectionError );
                                
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                "INFO",
                                { {"ID", "GT"}, {"Number", "D"}, {"Type", "String"}, {"Description", "Genotype"} }
                            }),
                            vcf::MetaSectionError );
        }
        
        SECTION("Type field values")
        {
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                "INFO",
                                { {"ID", "GT"}, {"Number", "10"}, {"Type", "Integer"}, {"Description", "Genotype"} }
                            } ) );
                                
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                "INFO",
                                { {"ID", "GT"}, {"Number", "A"}, {"Type", "Float"}, {"Description", "Genotype"} }
                            } ) );
                                     
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                "INFO",
                                { {"ID", "GT"}, {"Number", "A"}, {"Type", "Flag"}, {"Description", "Genotype"} }
                            } ) );
                               
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                "INFO",
                                { {"ID", "GT"}, {"Number", "R"}, {"Type", "Character"}, {"Description", "Genotype"} }
                            } ) );
                                
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                "INFO",
                                { {"ID", "GT"}, {"Number", "G"}, {"Type", "String"}, {"Description", "Genotype"} }
                            } ) );
                            
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                "INFO",
                                { {"ID", "GT"}, {"Number", "1"}, {"Type", "."}, {"Description", "Genotype"} }
                            }),
                            vcf::MetaSectionError );
                                
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                "INFO",
                                { {"ID", "GT"}, {"Number", "1"}, {"Type", "int"}, {"Description", "Genotype"} }
                            }),
                            vcf::MetaSectionError );
        }
    }
    
    TEST_CASE("SAMPLE MetaEntry checks", "[checks][keyvalue]") 
    {
        auto source = vcf::Source {
            "Example VCF source",
            vcf::InputFormat::VCF_FILE_VCF | vcf::InputFormat::VCF_FILE_BGZIP,
            vcf::Version::v43,
            {},
            { "Sample1", "Sample2", "Sample3" }};
            
        SECTION("ID presence")
        {
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                "SAMPLE",
                                { {"ID", "Sample_1"} }
                            } ) );
                                
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                "SAMPLE",
                                { {"ID", "Sample_2"}, {"Genomes", "genome_1,genome_2"}, {"Mixtures", "mixture_1"} }
                            } ) );
                                
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                "SAMPLE",
                                { {"Genomes", "genome_1,genome_2"} }
                            }),
                            vcf::MetaSectionError );
        }
    }
}
