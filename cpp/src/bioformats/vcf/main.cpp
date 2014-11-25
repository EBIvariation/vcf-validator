/* 
 * File:   main.cpp
 * Author: Cristina Yenyxe Gonzalez Garcia <cyenyxe@ebi.ac.uk>
 *
 * Created on 19 November 2014, 15:54
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "vcf_validator.h"

namespace
{
  bool is_valid_vcf_file(char const * path)
  {
    size_t const default_buffer_size = 64 * 1024;
 
    std::ifstream input{path};
    auto validator = opencb::vcf::Validator{};    

//    for ( std::string line; std::getline(input, line); )
//    {
//        validator.parse_line(line);
////        std::cout << "Valid line: " << validator.is_valid() << std::endl;
//    }
    
    std::vector<char> line;
    char ch;
    
    while (input.get(ch)) {
        line.push_back(ch);
        if (ch == '\n') {
            validator.parse_line(line);
//        std::cout << "Valid line: " << validator.is_valid() << std::endl;
            line.clear();
        }
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

  return !is_valid_vcf_file(path);
}
