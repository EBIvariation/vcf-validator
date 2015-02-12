/* 
 * File:   main.cpp
 * Author: Cristina Yenyxe Gonzalez Garcia <cyenyxe@ebi.ac.uk>
 *
 * Created on 19 November 2014, 15:54
 */

#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <vector>
#include <stdexcept>

#include "file_structure.hpp"
#include "validator.hpp"

namespace
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

  bool is_valid_vcf_file(char const * path)
  {
    std::ifstream input{path};
    auto source = opencb::vcf::Source{path, opencb::vcf::InputFormat::VCF_FILE_VCF};
    auto records = std::vector<opencb::vcf::Record>{};
    
    auto validator = opencb::vcf::FullValidator{
        std::make_shared<opencb::vcf::Source>(source),
        std::make_shared<std::vector<opencb::vcf::Record>>(records)};

//    for ( std::string line; std::getline(input, line); )
//    {
//        validator.parse_line(line);
////        std::cout << "Valid line: " << validator.is_valid() << std::endl;
//    }
    std::vector<char> line;
    line.reserve(default_line_buffer_size);
    
    while (readline(input, line)) { 
       validator.parse(line);
//        std::cout << "Valid line: " << validator.is_valid() << std::endl;
    }
    
    validator.end();

    std::cout << "Valid: " << validator.is_valid() << std::endl;

    return validator.is_valid();
  }
}

int main(int argc, char** argv)
{
  if (argc < 2)
  {
    std::cerr << "Please provide an input VCF file" << std::endl;
    return 1;
  }

  const char * path = argv[1];

  try
  {
    return !is_valid_vcf_file(path);
  }
  catch (std::runtime_error const & ex)
  {
    std::cerr << "ERROR: " << ex.what() << std::endl;
    return 1;
  }
}
