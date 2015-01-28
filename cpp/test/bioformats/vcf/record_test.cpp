#include <memory>

#include "main_test.hpp"

#include "bioformats/vcf/file_structure.hpp"

namespace opencb
{
    
    TEST_CASE("Record constructor", "[constructor]") 
    {
        auto source = vcf::Source {
            "Example VCF source",
            vcf::InputFormat::VCF_FILE_VCF | vcf::InputFormat::VCF_FILE_BGZIP,
            "v4.1",
            {},
            { "Sample1", "Sample2", "Sample3" }};

        SECTION("Correct arguments") 
        {
            CHECK_NOTHROW( (vcf::Record { 
                                "chr1", 
                                123456, 
                                { "id123", "id456" }, 
                                "A", 
                                { "AC", "AT" }, 
                                1.0, 
                                { "PASS" }, 
                                "AN=12,AF=0.5", 
                                "GT:DP", 
                                { "" },
                                std::make_shared<vcf::Source>(source)} ) );
                
            CHECK_NOTHROW( (vcf::Record{ 
                                "chr1", 
                                123456, 
                                { }, 
                                "A", 
                                { "AC", "AT" }, 
                                1.0, 
                                { "PASS" }, 
                                "AN=12,AF=0.5", 
                                "GT:DP", 
                                { "" },
                                std::make_shared<vcf::Source>(source)}) );
        }

        SECTION("Chromosome with whitespaces") 
        {
            CHECK_THROWS_AS( (vcf::Record{ 
                                "chr 1", 
                                123456, 
                                { "id123", "id456" }, 
                                "A", 
                                { "AC", "AT" }, 
                                1.0, 
                                { "PASS" }, 
                                "AN=12,AF=0.5", 
                                "GT:DP", 
                                { "" },
                                std::make_shared<vcf::Source>(source)}),
                            std::invalid_argument);
        }

        SECTION("Chromosome with colons") 
        {
            CHECK_THROWS_AS( (vcf::Record{ 
                                "chr:1", 
                                123456, 
                                { "id123", "id456" }, 
                                "A", 
                                { "AC", "AT" }, 
                                1.0, 
                                { "PASS" }, 
                                "AN=12,AF=0.5", 
                                "GT:DP", 
                                { "" },
                                std::make_shared<vcf::Source>(source)}),
                            std::invalid_argument);
        }

        SECTION("ID with whitespaces") 
        {
            CHECK_THROWS_AS( (vcf::Record{ 
                                "chr1", 
                                123456, 
                                { "id 123", "id456" }, 
                                "A", 
                                { "AC", "AT" }, 
                                1.0, 
                                { "PASS" }, 
                                "AN=12,AF=0.5", 
                                "GT:DP", 
                                { "" },
                                std::make_shared<vcf::Source>(source)}),
                            std::invalid_argument);
        }

        SECTION("Different length alleles")
        {
            CHECK_NOTHROW( (vcf::Record{ 
                                "chr1", 
                                123456, 
                                { "id123", "id456" }, 
                                "A", 
                                { "AT" }, 
                                1.0, 
                                { "PASS" }, 
                                "AN=12,AF=0.5", 
                                "GT:DP", 
                                { "" },
                                std::make_shared<vcf::Source>(source)}) );
                                
            CHECK_THROWS_AS( (vcf::Record{ 
                                "chr1", 
                                123456, 
                                { "id123", "id456" }, 
                                "A", 
                                { "CT" }, 
                                1.0, 
                                { "PASS" }, 
                                "AN=12,AF=0.5", 
                                "GT:DP", 
                                { "" },
                                std::make_shared<vcf::Source>(source)}),
                            std::invalid_argument);
        }
        
        SECTION("Same length alleles") 
        {
            CHECK_NOTHROW( (vcf::Record{ 
                                "chr1", 
                                123456, 
                                { "id123", "id456" }, 
                                "A", 
                                { "T", "C" }, 
                                1.0, 
                                { "PASS" }, 
                                "AN=12,AF=0.5", 
                                "GT:DP", 
                                { "" },
                                std::make_shared<vcf::Source>(source)}) );
        }

        SECTION("Same alleles") 
        {
            CHECK_THROWS_AS( (vcf::Record{ 
                                "chr1", 
                                123456, 
                                { "id123", "id456" }, 
                                "A", 
                                { "A" }, 
                                1.0, 
                                { "PASS" }, 
                                "AN=12,AF=0.5", 
                                "GT:DP", 
                                { "" },
                                std::make_shared<vcf::Source>(source)}),
                            std::invalid_argument);
        }

        SECTION("Less-than-zero quality") 
        {
            CHECK_THROWS_AS( (vcf::Record{ 
                                "chr1", 
                                123456, 
                                { "id123", "id456" }, 
                                "A", 
                                { "A", "C" }, 
                                -1.0, 
                                { "PASS" }, 
                                "AN=12,AF=0.5", 
                                "GT:DP", 
                                { "" },
                                std::make_shared<vcf::Source>(source)}),
                            std::invalid_argument);
        }

        SECTION("Single-field format") 
        {
            CHECK_NOTHROW( (vcf::Record{ 
                                "chr1", 
                                123456, 
                                { "id123", "id456" }, 
                                "A", 
                                { "T", "C" }, 
                                1.0, 
                                { "PASS" }, 
                                "AN=12,AF=0.5", 
                                "GT", 
                                { "" },
                                std::make_shared<vcf::Source>(source)}) );
                                
            CHECK_THROWS_AS( (vcf::Record{ 
                                "chr1", 
                                123456, 
                                { "id123", "id456" }, 
                                "A", 
                                { "A", "C" }, 
                                -1.0, 
                                { "PASS" }, 
                                "AN=12,AF=0.5", 
                                "DP", 
                                { "" },
                                std::make_shared<vcf::Source>(source)}),
                            std::invalid_argument);
        }
        
        SECTION("Multi-field format") 
        {
            CHECK_NOTHROW( (vcf::Record{ 
                                "chr1", 
                                123456, 
                                { "id123", "id456" }, 
                                "A", 
                                { "T", "C" }, 
                                1.0, 
                                { "PASS" }, 
                                "AN=12,AF=0.5", 
                                "GT:DP", 
                                { "" },
                                std::make_shared<vcf::Source>(source)}) );
                                
            CHECK_THROWS_AS( (vcf::Record{ 
                                "chr1", 
                                123456, 
                                { "id123", "id456" }, 
                                "A", 
                                { "A", "C" }, 
                                -1.0, 
                                { "PASS" }, 
                                "AN=12,AF=0.5", 
                                "DP:GT", 
                                { "" },
                                std::make_shared<vcf::Source>(source)}),
                            std::invalid_argument);
        }
        
    }

}