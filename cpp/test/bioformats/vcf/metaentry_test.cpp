#include <memory>
#include <iostream>
#include <typeinfo>

#include "main_test.hpp"

#include "bioformats/vcf/file_structure.hpp"

namespace opencb
{

    TEST_CASE("MetaEntry constructor (no value)", "[constructor][novalue]") 
    {
        auto source = vcf::Source {
            "Example VCF source",
            'r',
            vcf::InputFormat::VCF_FILE_VCF | vcf::InputFormat::VCF_FILE_BGZIP,
            "v4.1",
            {},
            { "Sample1", "Sample2", "Sample3" }};
            
            SECTION ("It should work with any ID and source")
            {
                CHECK_NOTHROW( (vcf::MetaEntry { 
                                "reference",
                                std::make_shared<vcf::Source>(source)} ) );
            }
            
            SECTION ("No value should be assigned")
            {
                auto meta = vcf::MetaEntry { 
                                "reference",
                                std::make_shared<vcf::Source>(source)} ;
                
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
            'r',
            vcf::InputFormat::VCF_FILE_VCF | vcf::InputFormat::VCF_FILE_BGZIP,
            "v4.1",
            {},
            { "Sample1", "Sample2", "Sample3" }};

            
            SECTION("Correct arguments")
            {
                CHECK_NOTHROW( (vcf::MetaEntry { 
                                "assembly",
                                "GRCh37",
                                std::make_shared<vcf::Source>(source)} ) );
            }
            
            SECTION("A one-line string value should be assigned")
            {
                auto meta = vcf::MetaEntry { 
                                "assembly",
                                "GRCh37",
                                std::make_shared<vcf::Source>(source)} ;
                        
                CHECK( meta.structure == vcf::MetaEntry::Structure::PlainValue );
                CHECK( meta.id == "assembly" );
                CHECK( boost::get<std::string>(meta.value) == std::string{"GRCh37"} );
                CHECK_THROWS_AS( (boost::get<std::map<std::string,std::string>>(meta.value)),
                                boost::bad_get);
            }
                
            SECTION("A multi-line string value should throw an error")
            {
                CHECK_THROWS_AS( (vcf::MetaEntry { 
                                    "assembly",
                                    "GRCh37\nGRCh37",
                                    std::make_shared<vcf::Source>(source)} ),
                                std::invalid_argument);
            }
    }

    TEST_CASE("MetaEntry constructor (key-value pairs)", "[constructor][keyvalue]") 
    {
        auto source = vcf::Source {
            "Example VCF source",
            'r',
            vcf::InputFormat::VCF_FILE_VCF | vcf::InputFormat::VCF_FILE_BGZIP,
            "v4.1",
            {},
            { "Sample1", "Sample2", "Sample3" }};
            
        SECTION("Correct arguments")
        {
            CHECK_NOTHROW( (vcf::MetaEntry { 
                            "contig",
                            { {"ID", "contig_1"} },
                            std::make_shared<vcf::Source>(source)} ) );
        }
            
        
        SECTION("A key-pair map should be assigned")
        {
            auto meta = vcf::MetaEntry {  
                            "contig",
                            { {"ID", "contig_1"} },
                            std::make_shared<vcf::Source>(source)} ;

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
            'r',
            vcf::InputFormat::VCF_FILE_VCF | vcf::InputFormat::VCF_FILE_BGZIP,
            "v4.1",
            {},
            { "Sample1", "Sample2", "Sample3" }};
            
        SECTION("ID and Description presence")
        {
            CHECK_NOTHROW( (vcf::MetaEntry { 
                                "ALT",
                                { {"ID", "INS"}, {"Description", "tag_description"} },
                                std::make_shared<vcf::Source>(source)} ) );
                                
            CHECK_THROWS_AS( (vcf::MetaEntry {  
                                "ALT",
                                { {"Description", "tag_description"} },
                                std::make_shared<vcf::Source>(source)}),
                            std::invalid_argument );
                                
            CHECK_THROWS_AS( (vcf::MetaEntry {  
                                "ALT",
                                { {"ID", "TAG_ID"} },
                                std::make_shared<vcf::Source>(source)}),
                            std::invalid_argument );
        }
        
        SECTION("ID prefixes")
        {
            CHECK_NOTHROW( (vcf::MetaEntry { 
                                "ALT",
                                { {"ID", "DEL"}, {"Description", "tag_description"} },
                                std::make_shared<vcf::Source>(source)} ) );
                              
            CHECK_NOTHROW( (vcf::MetaEntry { 
                                "ALT",
                                { {"ID", "INS"}, {"Description", "tag_description"} },
                                std::make_shared<vcf::Source>(source)} ) );
                             
            CHECK_NOTHROW( (vcf::MetaEntry { 
                                "ALT",
                                { {"ID", "DUP"}, {"Description", "tag_description"} },
                                std::make_shared<vcf::Source>(source)} ) );
                             
            CHECK_NOTHROW( (vcf::MetaEntry { 
                                "ALT",
                                { {"ID", "INV"}, {"Description", "tag_description"} },
                                std::make_shared<vcf::Source>(source)} ) );
                             
            CHECK_NOTHROW( (vcf::MetaEntry { 
                                "ALT",
                                { {"ID", "CNV"}, {"Description", "tag_description"} },
                                std::make_shared<vcf::Source>(source)} ) );
                               
            CHECK_NOTHROW( (vcf::MetaEntry { 
                                "ALT",
                                { {"ID", "DEL:FOO"}, {"Description", "tag_description"} },
                                std::make_shared<vcf::Source>(source)} ) );
                                
            CHECK_NOTHROW( (vcf::MetaEntry { 
                                "ALT",
                                { {"ID", "INS:FOO"}, {"Description", "tag_description"} },
                                std::make_shared<vcf::Source>(source)} ) );
                                
            CHECK_NOTHROW( (vcf::MetaEntry { 
                                "ALT",
                                { {"ID", "DUP:FOO"}, {"Description", "tag_description"} },
                                std::make_shared<vcf::Source>(source)} ) );
                                
            CHECK_NOTHROW( (vcf::MetaEntry { 
                                "ALT",
                                { {"ID", "INV:FOO"}, {"Description", "tag_description"} },
                                std::make_shared<vcf::Source>(source)} ) );
                                
            CHECK_NOTHROW( (vcf::MetaEntry { 
                                "ALT",
                                { {"ID", "CNV:FOO"}, {"Description", "tag_description"} },
                                std::make_shared<vcf::Source>(source)} ) );
                                  
            CHECK_NOTHROW( (vcf::MetaEntry { 
                                "ALT",
                                { {"ID", "CNV:FOO:BAR"}, {"Description", "tag_description"} },
                                std::make_shared<vcf::Source>(source)} ) );
                                
        }
    }

}
