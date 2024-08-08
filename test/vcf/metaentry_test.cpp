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
#include <iostream>
#include <typeinfo>

#include "catch/catch.hpp"

#include "vcf/file_structure.hpp"
#include "vcf/error.hpp"

namespace ebi
{

    TEST_CASE("MetaEntry constructor (no value)", "[constructor][novalue]") 
    {       
        std::shared_ptr<vcf::Source> source{
            new vcf::Source{
                "Example VCF source",
                vcf::InputFormat::VCF_FILE_VCF | vcf::InputFormat::VCF_FILE_BGZIP,
                vcf::Version::v41,
                {},
                { "Sample1", "Sample2", "Sample3" }}};

        SECTION ("It should work with any ID and source")
        {
            CHECK_NOTHROW( (vcf::MetaEntry { 1, vcf::REFERENCE, source }) );
        }
        
        SECTION ("No value should be assigned")
        {
            auto meta = vcf::MetaEntry { 1, vcf::REFERENCE, source } ;
            
            CHECK( meta.id == vcf::REFERENCE );
            CHECK( meta.structure == vcf::MetaEntry::Structure::NoValue );
            CHECK( boost::get<std::string>(meta.value) == std::string {} );
            CHECK_THROWS_AS( (boost::get<std::map<std::string,std::string>>(meta.value)),
                            boost::bad_get);
        }
    }

    TEST_CASE("MetaEntry constructor (plain value)", "[constructor][plainvalue]") 
    {
        std::shared_ptr<vcf::Source> source{
            new vcf::Source{
                "Example VCF source",
                vcf::InputFormat::VCF_FILE_VCF | vcf::InputFormat::VCF_FILE_BGZIP,
                vcf::Version::v42,
                {},
                { "Sample1", "Sample2", "Sample3" }}};
        
        SECTION("Correct arguments")
        {
            CHECK_NOTHROW( (vcf::MetaEntry { 1, vcf::ASSEMBLY, "GRCh37", source }) );
        }
            
        SECTION("A one-line string value should be assigned")
        {
            auto meta = vcf::MetaEntry { 1, vcf::ASSEMBLY, "GRCh37", source } ;
                    
            CHECK( meta.structure == vcf::MetaEntry::Structure::PlainValue );
            CHECK( meta.id == vcf::ASSEMBLY );
            CHECK( boost::get<std::string>(meta.value) == std::string{"GRCh37"} );
            CHECK_THROWS_AS( (boost::get<std::map<std::string,std::string>>(meta.value)),
                            boost::bad_get);
        }
                
        SECTION("A multi-line string value should throw an error")
        {
            CHECK_THROWS_AS( (vcf::MetaEntry { 1, vcf::ASSEMBLY, "GRCh37\nGRCh37", source } ),
                            vcf::MetaSectionError* );
        }
    }

    TEST_CASE("MetaEntry constructor (key-value pairs)", "[constructor][keyvalue]") 
    {
        std::shared_ptr<vcf::Source> source{
            new vcf::Source{
                "Example VCF source",
                vcf::InputFormat::VCF_FILE_VCF | vcf::InputFormat::VCF_FILE_BGZIP,
                vcf::Version::v43,
                {},
                { "Sample1", "Sample2", "Sample3" }}};

        SECTION("Correct arguments")
        {
            CHECK_NOTHROW( (vcf::MetaEntry {
                            1,
                            vcf::CONTIG,
                            { {vcf::ID, "contig_1"} },
                            source } ) );
        }
            
        
        SECTION("A key-pair map should be assigned")
        {
            auto meta = vcf::MetaEntry {
                            1,
                            vcf::CONTIG,
                            { {vcf::ID, "contig_1"} },
                            source } ;

            CHECK( meta.id == vcf::CONTIG );
            CHECK( meta.structure == vcf::MetaEntry::Structure::KeyValue );
            CHECK_THROWS_AS( boost::get<std::string>(meta.value),
                            boost::bad_get);
            CHECK( (boost::get<std::map<std::string,std::string>>(meta.value)) == (std::map<std::string,std::string>{ {vcf::ID, "contig_1"} }) );
        }
        
    }

    TEST_CASE("ALT MetaEntry checks", "[checks][keyvalue]") 
    {
        std::shared_ptr<vcf::Source> source{
            new vcf::Source{
                "Example VCF source",
                vcf::InputFormat::VCF_FILE_VCF | vcf::InputFormat::VCF_FILE_BGZIP,
                vcf::Version::v41,
                {},
                { "Sample1", "Sample2", "Sample3" }}};
        std::shared_ptr<vcf::Source> source44{
            new vcf::Source{
                "Example VCF source v44",
                vcf::InputFormat::VCF_FILE_VCF | vcf::InputFormat::VCF_FILE_BGZIP,
                vcf::Version::v44,
                {},
                { "Sample1", "Sample2", "Sample3" }}};
            
        SECTION("ID and Description presence")
        {
            auto sources = {source, source44};
            for (auto &src : sources) {
                CHECK_NOTHROW( (vcf::MetaEntry {
                                    1,
                                    vcf::ALT,
                                    { {vcf::ID, vcf::INS}, {vcf::DESCRIPTION, "tag_description"} },
                                    src
                                } ) );
                                    
                CHECK_THROWS_AS( (vcf::MetaEntry {
                                    1,
                                    vcf::ALT,
                                    { {vcf::DESCRIPTION, "tag_description"} },
                                    src
                                }),
                                vcf::MetaSectionError* );
            }

            CHECK_THROWS_AS( (vcf::MetaEntry {  //description must upto v44
                                1,
                                vcf::ALT,
                                { {vcf::ID, "TAG_ID"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {    //description optional since v44
                                1,
                                vcf::ALT,
                                { {vcf::ID, vcf::INS} },
                                source44
                            } ) );
        }
        
        SECTION("ID prefixes")
        {
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::ALT,
                                { {vcf::ID, vcf::DEL}, {vcf::DESCRIPTION, "tag_description"} },
                                source
                            } ) );
                              
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::ALT,
                                { {vcf::ID, vcf::INS}, {vcf::DESCRIPTION, "tag_description"} },
                                source
                            } ) );
                             
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::ALT,
                                { {vcf::ID, vcf::DUP}, {vcf::DESCRIPTION, "tag_description"} },
                                source
                            } ) );
                             
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::ALT,
                                { {vcf::ID, vcf::INV}, {vcf::DESCRIPTION, "tag_description"} },
                                source
                            } ) );
                             
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::ALT,
                                { {vcf::ID, vcf::CNV}, {vcf::DESCRIPTION, "tag_description"} },
                                source
                            } ) );
                               
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::ALT,
                                { {vcf::ID, "DEL:FOO"}, {vcf::DESCRIPTION, "tag_description"} },
                                source
                            } ) );
                                
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::ALT,
                                { {vcf::ID, "INS:FOO"}, {vcf::DESCRIPTION, "tag_description"} },
                                source
                            } ) );
                                
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::ALT,
                                { {vcf::ID, "DUP:FOO"}, {vcf::DESCRIPTION, "tag_description"} },
                                source
                            } ) );
                                
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::ALT,
                                { {vcf::ID, "INV:FOO"}, {vcf::DESCRIPTION, "tag_description"} },
                                source
                            } ) );
                                
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::ALT,
                                { {vcf::ID, "CNV:FOO"}, {vcf::DESCRIPTION, "tag_description"} },
                                source
                            } ) );
                                  
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::ALT,
                                { {vcf::ID, "CNV:FOO:BAR"}, {vcf::DESCRIPTION, "tag_description"} },
                                source
                            } ) );
                                
        }
    }

    TEST_CASE("contig MetaEntry checks", "[checks][keyvalue]") 
    {
        std::shared_ptr<vcf::Source> source{
            new vcf::Source{
                "Example VCF source",
                vcf::InputFormat::VCF_FILE_VCF | vcf::InputFormat::VCF_FILE_BGZIP,
                vcf::Version::v42,
                {},
                { "Sample1", "Sample2", "Sample3" }}};
            
        SECTION("ID presence")
        {
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::CONTIG,
                                { {vcf::ID, "contig_1"} },
                                source
                            } ) );
                                
            CHECK_NOTHROW( (vcf::MetaEntry { 
                                1,
                                vcf::CONTIG,
                                { {vcf::ID, "contig_2"}, {vcf::DESCRIPTION, "tag_description"} },
                                source
                            } ) );
                                
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::CONTIG,
                                { {vcf::DESCRIPTION, "tag_description"} },
                                source
                            }),
                            vcf::MetaSectionError* );
        }
    }
    
    TEST_CASE("FILTER MetaEntry checks", "[checks][keyvalue]") 
    {
        std::shared_ptr<vcf::Source> source{
            new vcf::Source{
                "Example VCF source",
                vcf::InputFormat::VCF_FILE_VCF | vcf::InputFormat::VCF_FILE_BGZIP,
                vcf::Version::v43,
                {},
                { "Sample1", "Sample2", "Sample3" }}};
        std::shared_ptr<vcf::Source> source44{
            new vcf::Source{
                "Example VCF source",
                vcf::InputFormat::VCF_FILE_VCF | vcf::InputFormat::VCF_FILE_BGZIP,
                vcf::Version::v44,
                {},
                { "Sample1", "Sample2", "Sample3" }}};

        auto sources = { source, source44 };

        SECTION("ID and Description presence")
        {
            for (auto & src : sources) {
                CHECK_NOTHROW( (vcf::MetaEntry {
                                    1,
                                    vcf::FILTER,
                                    { {vcf::ID, "Filter1"}, {vcf::DESCRIPTION, "tag_description"} },
                                    src
                                } ) );

                CHECK_THROWS_AS( (vcf::MetaEntry {
                                    1,
                                    vcf::FILTER,
                                    { {vcf::DESCRIPTION, "tag_description"} },
                                    src
                                }),
                                vcf::MetaSectionError* );
            }

            CHECK_THROWS_AS( (vcf::MetaEntry {      //description required upto v43
                                1,
                                vcf::FILTER,
                                { {vcf::ID, "TAG_ID"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {        //description optional since v44
                                1,
                                vcf::FILTER,
                                { {vcf::ID, "TAG_ID"} },
                                source44
                            } ) );
        }

        SECTION("Non zero ID")
        {
            for (auto & src : sources) {
                CHECK_THROWS_AS( (vcf::MetaEntry {
                                    1,
                                    vcf::FILTER,
                                    { {vcf::ID, "0"}, {vcf::DESCRIPTION, "tag with id 0"} },
                                    src
                                }),
                                vcf::MetaSectionError* );
            }
        }
    }

    TEST_CASE("FORMAT MetaEntry checks", "[checks][keyvalue]") 
    {
        std::shared_ptr<vcf::Source> source{
            new vcf::Source{
                "Example VCF source",
                vcf::InputFormat::VCF_FILE_VCF | vcf::InputFormat::VCF_FILE_BGZIP,
                vcf::Version::v41,
                {},
                { "Sample1", "Sample2", "Sample3" }}};

        std::shared_ptr<vcf::Source> source_v43{
            new vcf::Source{
                "Example VCF source",
                vcf::InputFormat::VCF_FILE_VCF | vcf::InputFormat::VCF_FILE_BGZIP,
                vcf::Version::v43,
                {},
                { "Sample1", "Sample2", "Sample3" }}};

        std::shared_ptr<vcf::Source> source_v44{
            new vcf::Source{
                "Example VCF source",
                vcf::InputFormat::VCF_FILE_VCF | vcf::InputFormat::VCF_FILE_BGZIP,
                vcf::Version::v44,
                {},
                { "Sample1", "Sample2", "Sample3" }}};

        SECTION("ID, Number, Type and Description presence")
        {
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::GT}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Genotype"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Genotype"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::GT}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Genotype"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::GT}, {vcf::NUMBER, "1"}, {vcf::DESCRIPTION, "Genotype"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::GT}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::STRING} },
                                source
                            }),
                            vcf::MetaSectionError* );
        }

        SECTION("Number field values")
        {
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, "customTag"}, {vcf::NUMBER, "10"}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Genotype"} },
                                source
                            } ) );
                                
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, "customTag"}, {vcf::NUMBER, vcf::A}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Genotype"} },
                                source
                            } ) );
                                
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, "customTag"}, {vcf::NUMBER, vcf::R}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Genotype"} },
                                source
                            } ) );
                                
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, "customTag"}, {vcf::NUMBER, vcf::G}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Genotype"} },
                                source
                            } ) );
                            
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, "customTag"}, {vcf::NUMBER, vcf::UNKNOWN_CARDINALITY}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Genotype"} },
                                source
                            } ) );
                            
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, "customTag"}, {vcf::NUMBER, "10a"}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Genotype"} },
                                source
                            }),
                            vcf::MetaSectionError* );
                                
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, "customTag"}, {vcf::NUMBER, "D"}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Genotype"} },
                                source
                            }),
                            vcf::MetaSectionError* );
        }

        SECTION("Type field values")
        {
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, "customTag"}, {vcf::NUMBER, "10"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Genotype"} },
                                source
                            } ) );
                                
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, "customTag"}, {vcf::NUMBER, "10"}, {vcf::TYPE, vcf::FLOAT}, {vcf::DESCRIPTION, "Genotype"} },
                                source
                            } ) );
                                
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, "customTag"}, {vcf::NUMBER, "10"}, {vcf::TYPE, vcf::CHARACTER}, {vcf::DESCRIPTION, "Genotype"} },
                                source
                            } ) );
                                
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, "customTag"}, {vcf::NUMBER, "10"}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Genotype"} },
                                source
                            } ) );
                            
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, "customTag"}, {vcf::NUMBER, "10"}, {vcf::TYPE, vcf::MISSING_VALUE}, {vcf::DESCRIPTION, "Genotype"} },
                                source
                            }),
                            vcf::MetaSectionError* );
                                
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, "customTag"}, {vcf::NUMBER, "10"}, {vcf::TYPE, "int"}, {vcf::DESCRIPTION, "Genotype"} },
                                source
                            }),
                            vcf::MetaSectionError* );
        }

        SECTION("FORMAT predefined tags")
        {
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::DP}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Read depth"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::DP}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Read depth"} },
                                source
                            }),
                            vcf::MetaSectionError* );
                                
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::DP}, {vcf::NUMBER, "2"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Read depth"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::EC}, {vcf::NUMBER, vcf::A}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Expected alternate allele counts"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::EC}, {vcf::NUMBER, vcf::A}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Expected alternate allele counts"} },
                                source
                            }),
                            vcf::MetaSectionError* );
                                
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::EC}, {vcf::NUMBER, "2"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Expected alternate allele counts"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::FT}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Filter indicating if this genotype was “called”"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::FT}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::FLOAT}, {vcf::DESCRIPTION, "Filter indicating if this genotype was “called”"} },
                                source
                            }),
                            vcf::MetaSectionError* );
                                
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::FT}, {vcf::NUMBER, "2"}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Filter indicating if this genotype was “called”"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::GL}, {vcf::NUMBER, vcf::G}, {vcf::TYPE, vcf::FLOAT}, {vcf::DESCRIPTION, "Genotype likelihoods"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::GL}, {vcf::NUMBER, vcf::G}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Genotype likelihoods"} },
                                source
                            }),
                            vcf::MetaSectionError* );
                                
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::GP}, {vcf::NUMBER, vcf::G}, {vcf::TYPE, vcf::FLOAT}, {vcf::DESCRIPTION, "Genotype posterior probabilities"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::GP}, {vcf::NUMBER, vcf::G}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Genotype posterior probabilities"} },
                                source
                            }),
                            vcf::MetaSectionError* );
                                
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::GP}, {vcf::NUMBER, "2"}, {vcf::TYPE, vcf::FLOAT}, {vcf::DESCRIPTION, "Genotype posterior probabilities"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::GQ}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Conditional genotype quality"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::GQ}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Conditional genotype quality"} },
                                source
                            }),
                            vcf::MetaSectionError* );
                                
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::GQ}, {vcf::NUMBER, "2"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Conditional genotype quality"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::GT}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Genotype"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::GT}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::FLAG}, {vcf::DESCRIPTION, "Genotype"} },
                                source
                            }),
                            vcf::MetaSectionError* );
                                
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::GT}, {vcf::NUMBER, vcf::G}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Genotype"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::HQ}, {vcf::NUMBER, "2"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Haplotype quality"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::HQ}, {vcf::NUMBER, "2"}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Haplotype quality"} },
                                source
                            }),
                            vcf::MetaSectionError* );
                                
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::HQ}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Haplotype quality"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::MQ}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "RMS mapping quality"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::MQ}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "RMS mapping quality"} },
                                source
                            }),
                            vcf::MetaSectionError* );
                                
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::MQ}, {vcf::NUMBER, "2"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "RMS mapping quality"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::PL}, {vcf::NUMBER, vcf::G}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Phred-scaled genotype likelihoods rounded to the closest integer"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::PL}, {vcf::NUMBER, vcf::G}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Phred-scaled genotype likelihoods rounded to the closest integer"} },
                                source
                            }),
                            vcf::MetaSectionError* );
                                
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::PQ}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Phasing quality"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::PQ}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Phasing quality"} },
                                source
                            }),
                            vcf::MetaSectionError* );
                                
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::PQ}, {vcf::NUMBER, "2"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Phasing quality"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::PS}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Phase set"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::PS}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Phase set"} },
                                source
                            }),
                            vcf::MetaSectionError* );
                                
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::PS}, {vcf::NUMBER, "2"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Phase set"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::CN}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Copy number genotype for imprecise events"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::CN}, {vcf::NUMBER, "5"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Copy number genotype for imprecise events"} },
                                source
                            }),
                            vcf::MetaSectionError* );
                                
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::CN}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::FLOAT}, {vcf::DESCRIPTION, "Copy number genotype for imprecise events"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::CNQ}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::FLOAT}, {vcf::DESCRIPTION, "Copy number genotype quality for imprecise events"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::CNQ}, {vcf::NUMBER, vcf::A}, {vcf::TYPE, vcf::FLOAT}, {vcf::DESCRIPTION, "Copy number genotype quality for imprecise events"} },
                                source
                            }),
                            vcf::MetaSectionError* );
                                
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::CNQ}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Copy number genotype quality for imprecise events"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::CNL}, {vcf::NUMBER, vcf::UNKNOWN_CARDINALITY}, {vcf::TYPE, vcf::FLOAT}, {vcf::DESCRIPTION, "Copy number genotype likelihood for imprecise events"} },
                                source
                            } ) );
                                
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::CNL}, {vcf::NUMBER, "2"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Copy number genotype likelihood for imprecise events"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::NQ}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Phred style probability score that the variant is novel"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::NQ}, {vcf::NUMBER, "0"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Phred style probability score that the variant is novel"} },
                                source
                            }),
                            vcf::MetaSectionError* );
                                
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::NQ}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Phred style probability score that the variant is novel"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::HAP}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Unique haplotype identifier"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::HAP}, {vcf::NUMBER, vcf::A}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Unique haplotype identifier"} },
                                source
                            }),
                            vcf::MetaSectionError* );
                                
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::HAP}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::FLAG}, {vcf::DESCRIPTION, "Unique haplotype identifier"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::AHAP}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Unique identifier of ancestral haplotype"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::AHAP}, {vcf::NUMBER, "2"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Unique identifier of ancestral haplotype"} },
                                source
                            }),
                            vcf::MetaSectionError* );
                                
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::AHAP}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::CHARACTER}, {vcf::DESCRIPTION, "Unique identifier of ancestral haplotype"} },
                                source
                            }),
                            vcf::MetaSectionError* );
        }

        SECTION("FORMAT 4.3 predefined tags")
        {
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::CNL}, {vcf::NUMBER, vcf::G}, {vcf::TYPE, vcf::FLOAT}, {vcf::DESCRIPTION, "Copy number genotype likelihood for imprecise events"} },
                                source_v43
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::CNL}, {vcf::NUMBER, vcf::G}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Copy number genotype likelihood for imprecise events"} },
                                source_v43
                            }),
                            vcf::MetaSectionError* );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::CNL}, {vcf::NUMBER, "2"}, {vcf::TYPE, vcf::FLOAT}, {vcf::DESCRIPTION, "Copy number genotype likelihood for imprecise events"} },
                                source_v43
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::CNP}, {vcf::NUMBER, vcf::G}, {vcf::TYPE, vcf::FLOAT}, {vcf::DESCRIPTION, "Copy number posterior probabilities"} },
                                source_v43
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::CNP}, {vcf::NUMBER, vcf::G}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Copy number posterior probabilities"} },
                                source_v43
                            }),
                            vcf::MetaSectionError* );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::CNP}, {vcf::NUMBER, "2"}, {vcf::TYPE, vcf::FLOAT}, {vcf::DESCRIPTION, "Copy number posterior probabilities"} },
                                source_v43
                            }),
                            vcf::MetaSectionError* );
        }

        SECTION("FORMAT 4.4 predefined tags")
        {
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::CNL}, {vcf::NUMBER, vcf::G}, {vcf::TYPE, vcf::FLOAT}, {vcf::DESCRIPTION, "Copy number genotype likelihood for imprecise events"} },
                                source_v44
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::CNL}, {vcf::NUMBER, vcf::G}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Copy number genotype likelihood for imprecise events"} },
                                source_v44
                            }),
                            vcf::MetaSectionError* );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::CNL}, {vcf::NUMBER, "2"}, {vcf::TYPE, vcf::FLOAT}, {vcf::DESCRIPTION, "Copy number genotype likelihood for imprecise events"} },
                                source_v44
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::CNP}, {vcf::NUMBER, vcf::G}, {vcf::TYPE, vcf::FLOAT}, {vcf::DESCRIPTION, "Copy number posterior probabilities"} },
                                source_v44
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::CNP}, {vcf::NUMBER, vcf::G}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Copy number posterior probabilities"} },
                                source_v44
                            }),
                            vcf::MetaSectionError* );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::CNP}, {vcf::NUMBER, "2"}, {vcf::TYPE, vcf::FLOAT}, {vcf::DESCRIPTION, "Copy number posterior probabilities"} },
                                source_v44
                            }),
                            vcf::MetaSectionError* );
            //v4.4 updates
            CHECK_NOTHROW( (vcf::MetaEntry {    //valid definition
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::CN}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::FLOAT}, {vcf::DESCRIPTION, "Copy number"} },
                                source_v44
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {  //invalid number
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::CN}, {vcf::NUMBER, "5"}, {vcf::TYPE, vcf::FLOAT}, {vcf::DESCRIPTION, "Copy number"} },
                                source_v44
                            }),
                            vcf::MetaSectionError* );

            CHECK_THROWS_AS( (vcf::MetaEntry {  //invalid type
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::CN}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Copy number"} },
                                source_v44
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {    //valid definition
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::CICN}, {vcf::NUMBER, "2"}, {vcf::TYPE, vcf::FLOAT}, {vcf::DESCRIPTION, "CI Copy number"} },
                                source_v44
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {  //invalid number
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::CICN}, {vcf::NUMBER, "5"}, {vcf::TYPE, vcf::FLOAT}, {vcf::DESCRIPTION, "CI Copy number"} },
                                source_v44
                            }),
                            vcf::MetaSectionError* );

            CHECK_THROWS_AS( (vcf::MetaEntry {  //invalid type
                                1,
                                vcf::FORMAT,
                                { {vcf::ID, vcf::CICN}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "CI Copy number"} },
                                source_v44
                            }),
                            vcf::MetaSectionError* );
        }
    }

    TEST_CASE("INFO MetaEntry checks", "[checks][keyvalue]") 
    {
        std::shared_ptr<vcf::Source> source{
            new vcf::Source{
                "Example VCF source",
                vcf::InputFormat::VCF_FILE_VCF | vcf::InputFormat::VCF_FILE_BGZIP,
                vcf::Version::v43,
                {},
                { "Sample1", "Sample2", "Sample3" }}};

        SECTION("ID, Number, Type and Description presence")
        {
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::GT}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Genotype"} },
                                source
                            } ) );
                                
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Genotype"} },
                                source
                            }),
                            vcf::MetaSectionError* );
                                
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::GT}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Genotype"} },
                                source
                            }),
                            vcf::MetaSectionError* );
                                
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::GT}, {vcf::NUMBER, "1"}, {vcf::DESCRIPTION, "Genotype"} },
                                source
                            }),
                            vcf::MetaSectionError* );
                                
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::GT}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::STRING} },
                                source
                            }),
                            vcf::MetaSectionError* );
        }
        
        SECTION("Number field values")
        {
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::GT}, {vcf::NUMBER, "10"}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Genotype"} },
                                source
                            } ) );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::GT}, {vcf::NUMBER, vcf::A}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Genotype"} },
                                source
                            } ) );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::GT}, {vcf::NUMBER, vcf::R}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Genotype"} },
                                source
                            } ) );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::GT}, {vcf::NUMBER, vcf::G}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Genotype"} },
                                source
                            } ) );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::GT}, {vcf::NUMBER, vcf::UNKNOWN_CARDINALITY}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Genotype"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::GT}, {vcf::NUMBER, "10a"}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Genotype"} },
                                source
                            }),
                            vcf::MetaSectionError* );
                                
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::GT}, {vcf::NUMBER, "D"}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Genotype"} },
                                source
                            }),
                            vcf::MetaSectionError* );
        }

        SECTION("Type field values")
        {
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::GT}, {vcf::NUMBER, "10"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Genotype"} },
                                source
                            } ) );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::GT}, {vcf::NUMBER, vcf::A}, {vcf::TYPE, vcf::FLOAT}, {vcf::DESCRIPTION, "Genotype"} },
                                source
                            } ) );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::GT}, {vcf::NUMBER, vcf::A}, {vcf::TYPE, vcf::FLAG}, {vcf::DESCRIPTION, "Genotype"} },
                                source
                            } ) );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::GT}, {vcf::NUMBER, vcf::R}, {vcf::TYPE, vcf::CHARACTER}, {vcf::DESCRIPTION, "Genotype"} },
                                source
                            } ) );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::GT}, {vcf::NUMBER, vcf::G}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Genotype"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::GT}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::MISSING_VALUE}, {vcf::DESCRIPTION, "Genotype"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::GT}, {vcf::NUMBER, "1"}, {vcf::TYPE, "int"}, {vcf::DESCRIPTION, "Genotype"} },
                                source
                            }),
                            vcf::MetaSectionError* );
        }

        SECTION("INFO predefined tags") {
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::AA}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Ancestral Allele"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::AA}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Ancestral Allele"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::AA}, {vcf::NUMBER, vcf::R}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Ancestral Allele"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::AC}, {vcf::NUMBER, vcf::A}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Allele count in genotypes, for each ALT allele, in the same order as listed"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::AC}, {vcf::NUMBER, vcf::A}, {vcf::TYPE, vcf::FLOAT}, {vcf::DESCRIPTION, "Allele count in genotypes, for each ALT allele, in the same order as listed"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::AC}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Allele count in genotypes, for each ALT allele, in the same order as listed"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::AD}, {vcf::NUMBER, vcf::R}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Total read depth for each allele"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::AD}, {vcf::NUMBER, vcf::R}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Total read depth for each allele"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::AD}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Total read depth for each allele"} },
                                source
                            }),
                            vcf::MetaSectionError* );
 
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::ADF}, {vcf::NUMBER, vcf::R}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Read depth for each allele on the forward strand"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::ADF}, {vcf::NUMBER, vcf::R}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Read depth for each allele on the forward strand"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::ADF}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Read depth for each allele on the forward strand"} },
                                source
                            }),
                            vcf::MetaSectionError* );
  
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::ADR}, {vcf::NUMBER, vcf::R}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Read depth for each allele on the reverse strand"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::ADR}, {vcf::NUMBER, vcf::R}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Read depth for each allele on the reverse strand"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::ADR}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Read depth for each allele on the reverse strand"} },
                                source
                            }),
                            vcf::MetaSectionError* );
 
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::AF}, {vcf::NUMBER, vcf::A}, {vcf::TYPE, vcf::FLOAT}, {vcf::DESCRIPTION, "Allele frequency for each ALT allele in the same order as listed (estimated from primary data, not called genotypes)"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::AF}, {vcf::NUMBER, vcf::A}, {vcf::TYPE, vcf::FLAG}, {vcf::DESCRIPTION, "Allele frequency for each ALT allele in the same order as listed (estimated from primary data, not called genotypes)"} },
                                source
                            }),
                            vcf::MetaSectionError* );
 
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::AF}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::FLOAT}, {vcf::DESCRIPTION, "Allele frequency for each ALT allele in the same order as listed (estimated from primary data, not called genotypes)"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::AN}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Total number of alleles in called genotypes"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::AN}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::FLOAT}, {vcf::DESCRIPTION, "Total number of alleles in called genotypes"} },
                                source
                            }),
                            vcf::MetaSectionError* );
 
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::AN}, {vcf::NUMBER, vcf::A}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Total number of alleles in called genotypes"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::BQ}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::FLOAT}, {vcf::DESCRIPTION, "RMS base quality"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::BQ}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::FLAG}, {vcf::DESCRIPTION, "RMS base quality"} },
                                source
                            }),
                            vcf::MetaSectionError* );
 
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::BQ}, {vcf::NUMBER, vcf::A}, {vcf::TYPE, vcf::FLOAT}, {vcf::DESCRIPTION, "RMS base quality"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::CIGAR}, {vcf::NUMBER, vcf::A}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Cigar string describing how to align an alternate allele to the reference allele"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::CIGAR}, {vcf::NUMBER, vcf::A}, {vcf::TYPE, vcf::FLAG}, {vcf::DESCRIPTION, "Cigar string describing how to align an alternate allele to the reference allele"} },
                                source
                            }),
                            vcf::MetaSectionError* );
 
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::CIGAR}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Cigar string describing how to align an alternate allele to the reference allele"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::DB}, {vcf::NUMBER, "0"}, {vcf::TYPE, vcf::FLAG}, {vcf::DESCRIPTION, "dbSNP membership"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::DB}, {vcf::NUMBER, "0"}, {vcf::TYPE, vcf::FLOAT}, {vcf::DESCRIPTION, "dbSNP membership"} },
                                source
                            }),
                            vcf::MetaSectionError* );
 
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::DB}, {vcf::NUMBER, vcf::A}, {vcf::TYPE, vcf::FLAG}, {vcf::DESCRIPTION, "dbSNP membership"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::DP}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Combined depth across samples"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::DP}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::FLAG}, {vcf::DESCRIPTION, "Combined depth across samples"} },
                                source
                            }),
                            vcf::MetaSectionError* );
 
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::DP}, {vcf::NUMBER, vcf::A}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Combined depth across samples"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::END}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "End position (for use with symbolic alleles)"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::END}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::FLAG}, {vcf::DESCRIPTION, "End position (for use with symbolic alleles)"} },
                                source
                            }),
                            vcf::MetaSectionError* );
 
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::END}, {vcf::NUMBER, vcf::A}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "End position (for use with symbolic alleles)"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::H2}, {vcf::NUMBER, "0"}, {vcf::TYPE, vcf::FLAG}, {vcf::DESCRIPTION, "HapMap2 membership"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::H2}, {vcf::NUMBER, "0"}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "HapMap2 membership"} },
                                source
                            }),
                            vcf::MetaSectionError* );
 
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::H2}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::FLAG}, {vcf::DESCRIPTION, "HapMap2 membership"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::H3}, {vcf::NUMBER, "0"}, {vcf::TYPE, vcf::FLAG}, {vcf::DESCRIPTION, "HapMap3 membership"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::H3}, {vcf::NUMBER, "0"}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "HapMap3 membership"} },
                                source
                            }),
                            vcf::MetaSectionError* );
 
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::H3}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::FLAG}, {vcf::DESCRIPTION, "HapMap3 membership"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::MQ0}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Number of MAPQ == 0 reads"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::MQ0}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Number of MAPQ == 0 reads"} },
                                source
                            }),
                            vcf::MetaSectionError* );
 
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::MQ0}, {vcf::NUMBER, "0"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Number of MAPQ == 0 reads"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::NS}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Number of samples with data"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::NS}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Number of samples with data"} },
                                source
                            }),
                            vcf::MetaSectionError* );
 
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::NS}, {vcf::NUMBER, "0"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Number of samples with data"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::SOMATIC}, {vcf::NUMBER, "0"}, {vcf::TYPE, vcf::FLAG}, {vcf::DESCRIPTION, "Somatic mutation (for cancer genomics)"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::SOMATIC}, {vcf::NUMBER, "0"}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Somatic mutation (for cancer genomics)"} },
                                source
                            }),
                            vcf::MetaSectionError* );
 
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::SOMATIC}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::FLAG}, {vcf::DESCRIPTION, "Somatic mutation (for cancer genomics)"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::VALIDATED}, {vcf::NUMBER, "0"}, {vcf::TYPE, vcf::FLAG}, {vcf::DESCRIPTION, "Validated by follow-up experiment"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::VALIDATED}, {vcf::NUMBER, "0"}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Validated by follow-up experiment"} },
                                source
                            }),
                            vcf::MetaSectionError* );
 
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::VALIDATED}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::FLAG}, {vcf::DESCRIPTION, "Validated by follow-up experiment"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::THOUSAND_G}, {vcf::NUMBER, "0"}, {vcf::TYPE, vcf::FLAG}, {vcf::DESCRIPTION, "1000 Genomes membership"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::THOUSAND_G}, {vcf::NUMBER, "0"}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "1000 Genomes membership"} },
                                source
                            }),
                            vcf::MetaSectionError* );
 
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::THOUSAND_G}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::FLAG}, {vcf::DESCRIPTION, "1000 Genomes membership"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::IMPRECISE}, {vcf::NUMBER, "0"}, {vcf::TYPE, vcf::FLAG}, {vcf::DESCRIPTION, "Imprecise structural variation"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::IMPRECISE}, {vcf::NUMBER, vcf::R}, {vcf::TYPE, vcf::FLAG}, {vcf::DESCRIPTION, "Imprecise structural variation"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::IMPRECISE}, {vcf::NUMBER, "0"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Imprecise structural variation"} },
                                source
                            }),
                            vcf::MetaSectionError* );
  
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::NOVEL}, {vcf::NUMBER, "0"}, {vcf::TYPE, vcf::FLAG}, {vcf::DESCRIPTION, "Indicates a novel structural variation"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::NOVEL}, {vcf::NUMBER, vcf::R}, {vcf::TYPE, vcf::FLAG}, {vcf::DESCRIPTION, "Indicates a novel structural variation"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::NOVEL}, {vcf::NUMBER, "0"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Indicates a novel structural variation"} },
                                source
                            }),
                            vcf::MetaSectionError* );
  
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::SVTYPE}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Type of structural variant"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::SVTYPE}, {vcf::NUMBER, vcf::R}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Type of structural variant"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::SVTYPE}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Type of structural variant"} },
                                source
                            }),
                            vcf::MetaSectionError* );
  
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::SVLEN}, {vcf::NUMBER, vcf::UNKNOWN_CARDINALITY}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Difference in length between REF and ALT alleles"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::SVLEN}, {vcf::NUMBER, vcf::R}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Difference in length between REF and ALT alleles"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::CIPOS}, {vcf::NUMBER, "2"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Confidence interval around POS for imprecise variants"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::CIPOS}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Confidence interval around POS for imprecise variants"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::CIPOS}, {vcf::NUMBER, "2"}, {vcf::TYPE, vcf::FLOAT}, {vcf::DESCRIPTION, "Confidence interval around POS for imprecise variants"} },
                                source
                            }),
                            vcf::MetaSectionError* );
  
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::CIEND}, {vcf::NUMBER, "2"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Confidence interval around END for imprecise variants"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::CIEND}, {vcf::NUMBER, vcf::A}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Confidence interval around END for imprecise variants"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::CIEND}, {vcf::NUMBER, "2"}, {vcf::TYPE, vcf::CHARACTER}, {vcf::DESCRIPTION, "Confidence interval around END for imprecise variants"} },
                                source
                            }),
                            vcf::MetaSectionError* );
  
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::HOMLEN}, {vcf::NUMBER, vcf::UNKNOWN_CARDINALITY}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Length of base pair identical micro-homology at event breakpoints"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::HOMLEN}, {vcf::NUMBER, "2"}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Length of base pair identical micro-homology at event breakpoints"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::HOMSEQ}, {vcf::NUMBER, vcf::UNKNOWN_CARDINALITY}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Sequence of base pair identical micro-homology at event breakpoints"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::HOMSEQ}, {vcf::NUMBER, vcf::A}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Sequence of base pair identical micro-homology at event breakpoints"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::BKPTID}, {vcf::NUMBER, vcf::UNKNOWN_CARDINALITY}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "ID of the assembled alternate allele in the assembly file"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::BKPTID}, {vcf::NUMBER, "2"}, {vcf::TYPE, vcf::CHARACTER}, {vcf::DESCRIPTION, "ID of the assembled alternate allele in the assembly file"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::MEINFO}, {vcf::NUMBER, "4"}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Mobile element info of the form NAME,START,END,POLARITY"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::MEINFO}, {vcf::NUMBER, vcf::R}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Mobile element info of the form NAME,START,END,POLARITY"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::MEINFO}, {vcf::NUMBER, "4"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Mobile element info of the form NAME,START,END,POLARITY"} },
                                source
                            }),
                            vcf::MetaSectionError* );
  
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::METRANS}, {vcf::NUMBER, "4"}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Mobile element transduction info of the form CHR,START,END,POLARITY"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::METRANS}, {vcf::NUMBER, vcf::R}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Mobile element transduction info of the form CHR,START,END,POLARITY"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::METRANS}, {vcf::NUMBER, "4"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Mobile element transduction info of the form CHR,START,END,POLARITY"} },
                                source
                            }),
                            vcf::MetaSectionError* );
  
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::DGVID}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "ID of this element in Database of Genomic Variation"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::DGVID}, {vcf::NUMBER, vcf::R}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "ID of this element in Database of Genomic Variation"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::DGVID}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "ID of this element in Database of Genomic Variation"} },
                                source
                            }),
                            vcf::MetaSectionError* );
  
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::DBVARID}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "ID of this element in DBVAR"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::DBVARID}, {vcf::NUMBER, vcf::R}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "ID of this element in DBVAR"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::DBVARID}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "ID of this element in DBVAR"} },
                                source
                            }),
                            vcf::MetaSectionError* );
  
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::DBRIPID}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "ID of this element in DBRIP"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::DBRIPID}, {vcf::NUMBER, vcf::R}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "ID of this element in DBRIP"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::DBRIPID}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "ID of this element in DBRIP"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::MATEID}, {vcf::NUMBER, vcf::UNKNOWN_CARDINALITY}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "ID of mate breakends"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::MATEID}, {vcf::NUMBER, "2"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "ID of mate breakends"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::PARID}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "ID of partner breakend"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::PARID}, {vcf::NUMBER, vcf::R}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "ID of partner breakend"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::PARID}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "ID of partner breakend"} },
                                source
                            }),
                            vcf::MetaSectionError* );
  
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::EVENT}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "ID of event associated to breakend"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::EVENT}, {vcf::NUMBER, vcf::R}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "ID of event associated to breakend"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::EVENT}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "ID of event associated to breakend"} },
                                source
                            }),
                            vcf::MetaSectionError* );
  
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::CILEN}, {vcf::NUMBER, "2"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Confidence interval around the inserted material between breakends"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::CILEN}, {vcf::NUMBER, vcf::R}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Confidence interval around the inserted material between breakends"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::CILEN}, {vcf::NUMBER, "2"}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Confidence interval around the inserted material between breakends"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::DPADJ}, {vcf::NUMBER, vcf::UNKNOWN_CARDINALITY}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Read Depth of adjacency"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::DPADJ}, {vcf::NUMBER, "3"}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Read Depth of adjacency"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::CN}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Copy number of segment containing breakend"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::CN}, {vcf::NUMBER, vcf::R}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Copy number of segment containing breakend"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::CN}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::FLOAT}, {vcf::DESCRIPTION, "Copy number of segment containing breakend"} },
                                source
                            }),
                            vcf::MetaSectionError* );
  
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::CNADJ}, {vcf::NUMBER, vcf::UNKNOWN_CARDINALITY}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Copy number of adjacency"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::CNADJ}, {vcf::NUMBER, vcf::R}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Copy number of adjacency"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::CICN}, {vcf::NUMBER, "2"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Confidence interval around copy number for the segment"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::CICN}, {vcf::NUMBER, vcf::A}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Confidence interval around copy number for the segment"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::CICN}, {vcf::NUMBER, "2"}, {vcf::TYPE, vcf::FLAG}, {vcf::DESCRIPTION, "Confidence interval around copy number for the segment"} },
                                source
                            }),
                            vcf::MetaSectionError* );
  
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::CICNADJ}, {vcf::NUMBER, vcf::UNKNOWN_CARDINALITY}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Confidence interval around copy number for the adjacency"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::CICNADJ}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::CHARACTER}, {vcf::DESCRIPTION, "Confidence interval around copy number for the adjacency"} },
                                source
                            }),
                            vcf::MetaSectionError* );
        }
    }

    TEST_CASE("INFO MetaEntry checks v4.4", "[checks][keyvalue]")
    {
        //should this go as part / section in earlier test case or as a different test?
        std::shared_ptr<vcf::Source> source{
            new vcf::Source{
                "Example VCF source",
                vcf::InputFormat::VCF_FILE_VCF | vcf::InputFormat::VCF_FILE_BGZIP,
                vcf::Version::v44,
                {},
                { "Sample1", "Sample2", "Sample3" }}};
            
        SECTION("ID, Number, Type and Description presence")
        {
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::GT}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Genotype"} },
                                source
                            } ) );
                                
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Genotype"} },
                                source
                            }),
                            vcf::MetaSectionError* );
                                
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::GT}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Genotype"} },
                                source
                            }),
                            vcf::MetaSectionError* );
                                
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::GT}, {vcf::NUMBER, "1"}, {vcf::DESCRIPTION, "Genotype"} },
                                source
                            }),
                            vcf::MetaSectionError* );
                                
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::GT}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::STRING} },
                                source
                            }),
                            vcf::MetaSectionError* );
        }

        SECTION("Number field values")
        {
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::GT}, {vcf::NUMBER, "10"}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Genotype"} },
                                source
                            } ) );
                                
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::GT}, {vcf::NUMBER, vcf::A}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Genotype"} },
                                source
                            } ) );
                                
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::GT}, {vcf::NUMBER, vcf::R}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Genotype"} },
                                source
                            } ) );
                                
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::GT}, {vcf::NUMBER, vcf::G}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Genotype"} },
                                source
                            } ) );
                            
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::GT}, {vcf::NUMBER, vcf::UNKNOWN_CARDINALITY}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Genotype"} },
                                source
                            } ) );
                            
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::GT}, {vcf::NUMBER, "10a"}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Genotype"} },
                                source
                            }),
                            vcf::MetaSectionError* );
                                
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::GT}, {vcf::NUMBER, "D"}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Genotype"} },
                                source
                            }),
                            vcf::MetaSectionError* );
        }

        SECTION("Type field values")
        {
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::GT}, {vcf::NUMBER, "10"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Genotype"} },
                                source
                            } ) );
                                
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::GT}, {vcf::NUMBER, vcf::A}, {vcf::TYPE, vcf::FLOAT}, {vcf::DESCRIPTION, "Genotype"} },
                                source
                            } ) );
                                     
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::GT}, {vcf::NUMBER, vcf::A}, {vcf::TYPE, vcf::FLAG}, {vcf::DESCRIPTION, "Genotype"} },
                                source
                            } ) );
                               
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::GT}, {vcf::NUMBER, vcf::R}, {vcf::TYPE, vcf::CHARACTER}, {vcf::DESCRIPTION, "Genotype"} },
                                source
                            } ) );
                                
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::GT}, {vcf::NUMBER, vcf::G}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Genotype"} },
                                source
                            } ) );
                            
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::GT}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::MISSING_VALUE}, {vcf::DESCRIPTION, "Genotype"} },
                                source
                            }),
                            vcf::MetaSectionError* );
                                
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::GT}, {vcf::NUMBER, "1"}, {vcf::TYPE, "int"}, {vcf::DESCRIPTION, "Genotype"} },
                                source
                            }),
                            vcf::MetaSectionError* );
        }

        SECTION("INFO predefined tags") {
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::AA}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Ancestral Allele"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::AA}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Ancestral Allele"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::AA}, {vcf::NUMBER, vcf::R}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Ancestral Allele"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::AC}, {vcf::NUMBER, vcf::A}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Allele count in genotypes, for each ALT allele, in the same order as listed"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::AC}, {vcf::NUMBER, vcf::A}, {vcf::TYPE, vcf::FLOAT}, {vcf::DESCRIPTION, "Allele count in genotypes, for each ALT allele, in the same order as listed"} },
                                source
                            }),
                            vcf::MetaSectionError* );
 
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::AC}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Allele count in genotypes, for each ALT allele, in the same order as listed"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::AD}, {vcf::NUMBER, vcf::R}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Total read depth for each allele"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::AD}, {vcf::NUMBER, vcf::R}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Total read depth for each allele"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::AD}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Total read depth for each allele"} },
                                source
                            }),
                            vcf::MetaSectionError* );
 
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::ADF}, {vcf::NUMBER, vcf::R}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Read depth for each allele on the forward strand"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::ADF}, {vcf::NUMBER, vcf::R}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Read depth for each allele on the forward strand"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::ADF}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Read depth for each allele on the forward strand"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::ADR}, {vcf::NUMBER, vcf::R}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Read depth for each allele on the reverse strand"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::ADR}, {vcf::NUMBER, vcf::R}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Read depth for each allele on the reverse strand"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::ADR}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Read depth for each allele on the reverse strand"} },
                                source
                            }),
                            vcf::MetaSectionError* );
 
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::AF}, {vcf::NUMBER, vcf::A}, {vcf::TYPE, vcf::FLOAT}, {vcf::DESCRIPTION, "Allele frequency for each ALT allele in the same order as listed (estimated from primary data, not called genotypes)"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::AF}, {vcf::NUMBER, vcf::A}, {vcf::TYPE, vcf::FLAG}, {vcf::DESCRIPTION, "Allele frequency for each ALT allele in the same order as listed (estimated from primary data, not called genotypes)"} },
                                source
                            }),
                            vcf::MetaSectionError* );
 
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::AF}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::FLOAT}, {vcf::DESCRIPTION, "Allele frequency for each ALT allele in the same order as listed (estimated from primary data, not called genotypes)"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::AN}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Total number of alleles in called genotypes"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::AN}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::FLOAT}, {vcf::DESCRIPTION, "Total number of alleles in called genotypes"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::AN}, {vcf::NUMBER, vcf::A}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Total number of alleles in called genotypes"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::BQ}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::FLOAT}, {vcf::DESCRIPTION, "RMS base quality"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::BQ}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::FLAG}, {vcf::DESCRIPTION, "RMS base quality"} },
                                source
                            }),
                            vcf::MetaSectionError* );
 
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::BQ}, {vcf::NUMBER, vcf::A}, {vcf::TYPE, vcf::FLOAT}, {vcf::DESCRIPTION, "RMS base quality"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::CIGAR}, {vcf::NUMBER, vcf::A}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Cigar string describing how to align an alternate allele to the reference allele"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::CIGAR}, {vcf::NUMBER, vcf::A}, {vcf::TYPE, vcf::FLAG}, {vcf::DESCRIPTION, "Cigar string describing how to align an alternate allele to the reference allele"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::CIGAR}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Cigar string describing how to align an alternate allele to the reference allele"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::DB}, {vcf::NUMBER, "0"}, {vcf::TYPE, vcf::FLAG}, {vcf::DESCRIPTION, "dbSNP membership"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::DB}, {vcf::NUMBER, "0"}, {vcf::TYPE, vcf::FLOAT}, {vcf::DESCRIPTION, "dbSNP membership"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::DB}, {vcf::NUMBER, vcf::A}, {vcf::TYPE, vcf::FLAG}, {vcf::DESCRIPTION, "dbSNP membership"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::DP}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Combined depth across samples"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::DP}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::FLAG}, {vcf::DESCRIPTION, "Combined depth across samples"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::DP}, {vcf::NUMBER, vcf::A}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Combined depth across samples"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::END}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "End position (for use with symbolic alleles)"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::END}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::FLAG}, {vcf::DESCRIPTION, "End position (for use with symbolic alleles)"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::END}, {vcf::NUMBER, vcf::A}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "End position (for use with symbolic alleles)"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::H2}, {vcf::NUMBER, "0"}, {vcf::TYPE, vcf::FLAG}, {vcf::DESCRIPTION, "HapMap2 membership"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::H2}, {vcf::NUMBER, "0"}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "HapMap2 membership"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::H2}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::FLAG}, {vcf::DESCRIPTION, "HapMap2 membership"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::H3}, {vcf::NUMBER, "0"}, {vcf::TYPE, vcf::FLAG}, {vcf::DESCRIPTION, "HapMap3 membership"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::H3}, {vcf::NUMBER, "0"}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "HapMap3 membership"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::H3}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::FLAG}, {vcf::DESCRIPTION, "HapMap3 membership"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::MQ0}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Number of MAPQ == 0 reads"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::MQ0}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Number of MAPQ == 0 reads"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::MQ0}, {vcf::NUMBER, "0"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Number of MAPQ == 0 reads"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::NS}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Number of samples with data"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::NS}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Number of samples with data"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::NS}, {vcf::NUMBER, "0"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Number of samples with data"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::SOMATIC}, {vcf::NUMBER, "0"}, {vcf::TYPE, vcf::FLAG}, {vcf::DESCRIPTION, "Somatic mutation (for cancer genomics)"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::SOMATIC}, {vcf::NUMBER, "0"}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Somatic mutation (for cancer genomics)"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::SOMATIC}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::FLAG}, {vcf::DESCRIPTION, "Somatic mutation (for cancer genomics)"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::VALIDATED}, {vcf::NUMBER, "0"}, {vcf::TYPE, vcf::FLAG}, {vcf::DESCRIPTION, "Validated by follow-up experiment"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::VALIDATED}, {vcf::NUMBER, "0"}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Validated by follow-up experiment"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::VALIDATED}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::FLAG}, {vcf::DESCRIPTION, "Validated by follow-up experiment"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::THOUSAND_G}, {vcf::NUMBER, "0"}, {vcf::TYPE, vcf::FLAG}, {vcf::DESCRIPTION, "1000 Genomes membership"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::THOUSAND_G}, {vcf::NUMBER, "0"}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "1000 Genomes membership"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::THOUSAND_G}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::FLAG}, {vcf::DESCRIPTION, "1000 Genomes membership"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::IMPRECISE}, {vcf::NUMBER, "0"}, {vcf::TYPE, vcf::FLAG}, {vcf::DESCRIPTION, "Imprecise structural variation"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::IMPRECISE}, {vcf::NUMBER, vcf::R}, {vcf::TYPE, vcf::FLAG}, {vcf::DESCRIPTION, "Imprecise structural variation"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::IMPRECISE}, {vcf::NUMBER, "0"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Imprecise structural variation"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::NOVEL}, {vcf::NUMBER, "0"}, {vcf::TYPE, vcf::FLAG}, {vcf::DESCRIPTION, "Indicates a novel structural variation"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::NOVEL}, {vcf::NUMBER, vcf::R}, {vcf::TYPE, vcf::FLAG}, {vcf::DESCRIPTION, "Indicates a novel structural variation"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::NOVEL}, {vcf::NUMBER, "0"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Indicates a novel structural variation"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::SVTYPE}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Type of structural variant"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::SVTYPE}, {vcf::NUMBER, vcf::R}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Type of structural variant"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::SVTYPE}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Type of structural variant"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {    //valid definition
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::SVLEN}, {vcf::NUMBER, vcf::A}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Difference in length between REF and ALT alleles"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {  //invalid number
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::SVLEN}, {vcf::NUMBER, vcf::R}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Difference in length between REF and ALT alleles"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::CIPOS}, {vcf::NUMBER, vcf::UNKNOWN_CARDINALITY}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Confidence interval around POS for imprecise variants"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::CIPOS}, {vcf::NUMBER, vcf::UNKNOWN_CARDINALITY}, {vcf::TYPE, vcf::FLOAT}, {vcf::DESCRIPTION, "Confidence interval around POS for imprecise variants"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {    //valid
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::CIEND}, {vcf::NUMBER, vcf::UNKNOWN_CARDINALITY}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Confidence interval around END for imprecise variants"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {  //invalid type
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::CIEND}, {vcf::NUMBER, vcf::UNKNOWN_CARDINALITY}, {vcf::TYPE, vcf::CHARACTER}, {vcf::DESCRIPTION, "Confidence interval around END for imprecise variants"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {    //valid
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::HOMLEN}, {vcf::NUMBER, vcf::A}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Length of base pair identical micro-homology at event breakpoints"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {  //invalid number
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::HOMLEN}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Length of base pair identical micro-homology at event breakpoints"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_THROWS_AS( (vcf::MetaEntry {  //invalid type
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::HOMLEN}, {vcf::NUMBER, vcf::A}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Length of base pair identical micro-homology at event breakpoints"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {    //valid
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::HOMSEQ}, {vcf::NUMBER, vcf::A}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Sequence of base pair identical micro-homology at event breakpoints"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {  //invalid number
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::HOMSEQ}, {vcf::NUMBER, vcf::R}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Sequence of base pair identical micro-homology at event breakpoints"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_THROWS_AS( (vcf::MetaEntry {  //invalid type
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::HOMSEQ}, {vcf::NUMBER, vcf::A}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Sequence of base pair identical micro-homology at event breakpoints"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {    //valid
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::BKPTID}, {vcf::NUMBER, vcf::A}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "ID of the assembled alternate allele in the assembly file"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {  //invalid number
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::BKPTID}, {vcf::NUMBER, "2"}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "ID of the assembled alternate allele in the assembly file"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_THROWS_AS( (vcf::MetaEntry {  //invalid type
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::BKPTID}, {vcf::NUMBER, vcf::A}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "ID of the assembled alternate allele in the assembly file"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {    //valid
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::MEINFO}, {vcf::NUMBER, vcf::UNKNOWN_CARDINALITY}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Mobile element info of the form NAME,START,END,POLARITY"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {  //invalid type
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::MEINFO}, {vcf::NUMBER, vcf::UNKNOWN_CARDINALITY}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Mobile element info of the form NAME,START,END,POLARITY"} },
                                source
                            }),
                            vcf::MetaSectionError* );
  
            CHECK_NOTHROW( (vcf::MetaEntry {    //valid
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::METRANS}, {vcf::NUMBER, vcf::UNKNOWN_CARDINALITY}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Mobile element transduction info of the form CHR,START,END,POLARITY"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {  //invalid type
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::METRANS}, {vcf::NUMBER, vcf::UNKNOWN_CARDINALITY}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Mobile element transduction info of the form CHR,START,END,POLARITY"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {    //valid
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::DGVID}, {vcf::NUMBER, vcf::A}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "ID of this element in Database of Genomic Variation"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {  //invalid number
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::DGVID}, {vcf::NUMBER, vcf::R}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "ID of this element in Database of Genomic Variation"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_THROWS_AS( (vcf::MetaEntry {  //invalid type
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::DGVID}, {vcf::NUMBER, vcf::A}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "ID of this element in Database of Genomic Variation"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {    //valid
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::DBVARID}, {vcf::NUMBER, vcf::A}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "ID of this element in DBVAR"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {  //invalid number
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::DBVARID}, {vcf::NUMBER, vcf::R}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "ID of this element in DBVAR"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_THROWS_AS( (vcf::MetaEntry {  //invalid type
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::DBVARID}, {vcf::NUMBER, vcf::A}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "ID of this element in DBVAR"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {    //valid
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::DBRIPID}, {vcf::NUMBER, vcf::A}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "ID of this element in DBRIP"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {  //invalid number
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::DBRIPID}, {vcf::NUMBER, vcf::R}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "ID of this element in DBRIP"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_THROWS_AS( (vcf::MetaEntry {  //invalid type
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::DBRIPID}, {vcf::NUMBER, vcf::A}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "ID of this element in DBRIP"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {    //valid
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::MATEID}, {vcf::NUMBER, vcf::A}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "ID of mate breakends"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {  //invalid number
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::MATEID}, {vcf::NUMBER, vcf::R}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "ID of mate breakends"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_THROWS_AS( (vcf::MetaEntry {  //invalid type
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::MATEID}, {vcf::NUMBER, vcf::A}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "ID of mate breakends"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {    //valid
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::PARID}, {vcf::NUMBER, vcf::A}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "ID of partner breakend"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {  //invalid number
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::PARID}, {vcf::NUMBER, vcf::R}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "ID of partner breakend"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_THROWS_AS( (vcf::MetaEntry {  //invalid type
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::PARID}, {vcf::NUMBER, vcf::A}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "ID of partner breakend"} },
                                source
                            }),
                            vcf::MetaSectionError* );
  
            CHECK_NOTHROW( (vcf::MetaEntry {    //valid
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::EVENT}, {vcf::NUMBER, vcf::A}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "ID of event associated to breakend"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {  //invalid number
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::EVENT}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "ID of event associated to breakend"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_THROWS_AS( (vcf::MetaEntry {  //invalid tpye
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::EVENT}, {vcf::NUMBER, vcf::A}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "ID of event associated to breakend"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {    //valid
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::CILEN}, {vcf::NUMBER, vcf::UNKNOWN_CARDINALITY}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Confidence interval around the inserted material between breakends"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {  //invalid type
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::CILEN}, {vcf::NUMBER, vcf::UNKNOWN_CARDINALITY}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Confidence interval around the inserted material between breakends"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {    //valid definition
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::CN}, {vcf::NUMBER, "A"}, {vcf::TYPE, vcf::FLOAT}, {vcf::DESCRIPTION, "Copy number of CNV/breakpoint"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {  //invalid number
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::CN}, {vcf::NUMBER, vcf::R}, {vcf::TYPE, vcf::FLOAT}, {vcf::DESCRIPTION, "Copy number of CNV/breakpoint"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_THROWS_AS( (vcf::MetaEntry {  //invalid type
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::CN}, {vcf::NUMBER, "A"}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Copy number of CNV/breakpoint"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {    //valid
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::CICN}, {vcf::NUMBER, vcf::UNKNOWN_CARDINALITY}, {vcf::TYPE, vcf::FLOAT}, {vcf::DESCRIPTION, "Confidence interval around copy number for the segment"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {  //invalid type
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::CICN}, {vcf::NUMBER, vcf::UNKNOWN_CARDINALITY}, {vcf::TYPE, vcf::FLAG}, {vcf::DESCRIPTION, "Confidence interval around copy number for the segment"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {    //valid definition
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::SVCLAIM}, {vcf::NUMBER, vcf::A}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Claim by SV call. Valid are D,J,D,."} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {  //invalid number
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::SVCLAIM}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Claim by SV call. Valid are D,J,D,."} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_THROWS_AS( (vcf::MetaEntry {  //invalid type
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::SVCLAIM}, {vcf::NUMBER, vcf::A}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Claim by SV call. Valid are D,J,D,."} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {    //valid definition
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::RN}, {vcf::NUMBER, vcf::A}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Total num. of repeat seq. in this allele."} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {  //invalid number
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::RN}, {vcf::NUMBER, vcf::R}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Total num. of repeat seq. in this allele."} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_THROWS_AS( (vcf::MetaEntry {  //invalid type
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::RN}, {vcf::NUMBER, vcf::A}, {vcf::TYPE, vcf::FLOAT}, {vcf::DESCRIPTION, "Total num. of repeat seq. in this allele."} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {    //valid definition
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::RUS}, {vcf::NUMBER, vcf::UNKNOWN_CARDINALITY}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "A Repeat unit sequence"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {  //invalid type
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::RUS}, {vcf::NUMBER, vcf::UNKNOWN_CARDINALITY}, {vcf::TYPE, vcf::FLOAT}, {vcf::DESCRIPTION, "A Repeat unit sequence"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {    //valid definition
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::RUL}, {vcf::NUMBER, vcf::UNKNOWN_CARDINALITY}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Length of repeating unit"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {  //invalid type
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::RUL}, {vcf::NUMBER, vcf::UNKNOWN_CARDINALITY}, {vcf::TYPE, vcf::FLOAT}, {vcf::DESCRIPTION, "Length of repeating unit"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {    //valid definition
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::RUC}, {vcf::NUMBER, vcf::UNKNOWN_CARDINALITY}, {vcf::TYPE, vcf::FLOAT}, {vcf::DESCRIPTION, "Count of repeating unit"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {  //invalid type
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::RUC}, {vcf::NUMBER, vcf::UNKNOWN_CARDINALITY}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Count of repeating unit"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {    //valid definition
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::RB}, {vcf::NUMBER, vcf::UNKNOWN_CARDINALITY}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Total num. of bases in repeat seq."} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {  //invalid type
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::RB}, {vcf::NUMBER, vcf::UNKNOWN_CARDINALITY}, {vcf::TYPE, vcf::FLOAT}, {vcf::DESCRIPTION, "Total num. of bases in repeat seq."} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {    //valid definition
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::CIRUC}, {vcf::NUMBER, vcf::UNKNOWN_CARDINALITY}, {vcf::TYPE, vcf::FLOAT}, {vcf::DESCRIPTION, "Confidence interval for RUC"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {  //invalid type
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::CIRUC}, {vcf::NUMBER, vcf::UNKNOWN_CARDINALITY}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Confidence interval for RUC"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {    //valid definition
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::CIRB}, {vcf::NUMBER, vcf::UNKNOWN_CARDINALITY}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Confidence interval for RB"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {  //invalid type
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::CIRB}, {vcf::NUMBER, vcf::UNKNOWN_CARDINALITY}, {vcf::TYPE, vcf::FLOAT}, {vcf::DESCRIPTION, "Confidence interval for RB"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {    //valid definition
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::RUB}, {vcf::NUMBER, vcf::UNKNOWN_CARDINALITY}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Number of bases in repeat unit"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {  //invalid type
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::RUB}, {vcf::NUMBER, vcf::UNKNOWN_CARDINALITY}, {vcf::TYPE, vcf::FLOAT}, {vcf::DESCRIPTION, "Number of bases in repeat unit"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::EVENTTYPE}, {vcf::NUMBER, vcf::A}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Type of associated event"} },
                                source
                            } ) );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::EVENTTYPE}, {vcf::NUMBER, "1"}, {vcf::TYPE, vcf::STRING}, {vcf::DESCRIPTION, "Type of associated event"} },
                                source
                            }),
                            vcf::MetaSectionError* );

            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::INFO,
                                { {vcf::ID, vcf::EVENTTYPE}, {vcf::NUMBER, vcf::A}, {vcf::TYPE, vcf::INTEGER}, {vcf::DESCRIPTION, "Type of associated event"} },
                                source
                            }),
                            vcf::MetaSectionError* );

       }
    }

    TEST_CASE("SAMPLE MetaEntry checks", "[checks][keyvalue]") 
    {
        std::shared_ptr<vcf::Source> source{
            new vcf::Source{
                "Example VCF source",
                vcf::InputFormat::VCF_FILE_VCF | vcf::InputFormat::VCF_FILE_BGZIP,
                vcf::Version::v43,
                {},
                { "Sample1", "Sample2", "Sample3" }}};
            
        SECTION("ID presence")
        {
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::SAMPLE,
                                { {vcf::ID, "Sample_1"} },
                                source
                            } ) );
                                
            CHECK_NOTHROW( (vcf::MetaEntry {
                                1,
                                vcf::SAMPLE,
                                { {vcf::ID, "Sample_2"}, {"Genomes", "genome_1,genome_2"}, {"Mixtures", "mixture_1"} },
                                source
                            } ) );
                                
            CHECK_THROWS_AS( (vcf::MetaEntry {
                                1,
                                vcf::SAMPLE,
                                { {"Genomes", "genome_1,genome_2"} },
                                source
                            }),
                            vcf::MetaSectionError* );
        }
    }
}
