#include <iostream>
#include <fstream>
#include <memory>

#include <boost/filesystem.hpp>

#include "catch/catch.hpp"

#include "vcf/file_structure.hpp"
#include "vcf/validator.hpp"

namespace ebi
{
    
    size_t const default_line_buffer_size = 64 * 1024;
    
    template <typename Container>
    std::istream & readline(std::istream & stream, Container & container)
    {
        char c;

        container.clear();

        do {
            stream.get(c);
            container.push_back(c);
        } while (!stream.eof() && c != '\n');
        
        return stream;
    }
    
    bool is_valid(std::string path)
    {
        std::ifstream input{path};
        auto source = ebi::vcf::Source{path, ebi::vcf::InputFormat::VCF_FILE_VCF, ebi::vcf::Version::v41};
        auto records = std::vector<ebi::vcf::Record>{};

        auto validator = ebi::vcf::FullValidator_v41{
            std::make_shared<ebi::vcf::Source>(source),
            std::make_shared<std::vector<ebi::vcf::Record>>(records)};

        std::vector<char> line;
        line.reserve(default_line_buffer_size);

        while (readline(input, line)) { 
           validator.parse(line);
        }

        validator.end();
        
        return validator.is_valid();
    }

    TEST_CASE("Files that fail the validation", "[failed]") 
    {
        auto folder = boost::filesystem::path("test/input_files/failed");
        std::vector<boost::filesystem::path> v;
        copy(boost::filesystem::directory_iterator(folder), boost::filesystem::directory_iterator(), back_inserter(v));
        
        for (auto path : v)
        {
            SECTION(path.string())
            {
                CHECK_FALSE(is_valid(path.string()));
            }
        }
    }

    TEST_CASE("Files that pass the validation", "[passed]") 
    {
        auto folder = boost::filesystem::path("test/input_files/passed");
        std::vector<boost::filesystem::path> v;
        copy(boost::filesystem::directory_iterator(folder), boost::filesystem::directory_iterator(), back_inserter(v));
        
        for (auto path : v)
        {
            SECTION(path.string())
            {
                CHECK(is_valid(path.string()));
            }
        }
    }

}

