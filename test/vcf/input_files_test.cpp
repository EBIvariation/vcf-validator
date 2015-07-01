#include <iostream>
#include <fstream>
#include <memory>

#include <boost/filesystem.hpp>

#include "catch/catch.hpp"

#include "vcf/file_structure.hpp"
#include "vcf/validator.hpp"

namespace opencb
{
    
    size_t const default_line_buffer_size = 64 * 1024;
    
    template <typename Container>
    std::istream & readline(std::istream & stream, Container & container)
    {
        char c;
        bool not_eof;

        container.clear();

        do {
            not_eof = stream.get(c);
            container.push_back(c);
        } while (not_eof && c != '\n');

        return stream;
    }

    TEST_CASE("Files that fail the validation", "[failed]") 
    {
        auto folder = boost::filesystem::path("/home/cyenyxe/appl/vcf-validator/test/input_files/failed");
        
        typedef std::vector<boost::filesystem::path> vec;             // store paths,
        vec v;                                // so we can sort them later

        copy(boost::filesystem::directory_iterator(folder), boost::filesystem::directory_iterator(), back_inserter(v));

        sort(v.begin(), v.end());             // sort, since directory iteration
                                              // is not ordered on some file systems
  
        for (auto path : v)
        {
//        for (auto path : boost::filesystem::directory_iterator(folder)) {
//            auto path = "/home/cyenyxe/appl/vcf-validator/test/input_files/failed/failed_000.vcf";
            std::ifstream input{path.string()};
            auto source = opencb::vcf::Source{path.string(), opencb::vcf::InputFormat::VCF_FILE_VCF};
            auto records = std::vector<opencb::vcf::Record>{};

            auto validator = opencb::vcf::FullValidator{
                std::make_shared<opencb::vcf::Source>(source),
                std::make_shared<std::vector<opencb::vcf::Record>>(records)};

            std::vector<char> line;
            line.reserve(default_line_buffer_size);

            while (readline(input, line)) { 
               validator.parse(line);
            }

            validator.end();

            CHECK_FALSE(validator.is_valid());
        }
    }

}

