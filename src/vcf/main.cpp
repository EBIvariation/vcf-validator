/**
 * Copyright 2014-2015 EMBL - European Bioinformatics Institute
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

#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <vector>
#include <stdexcept>

#include "vcf/file_structure.hpp"
#include "vcf/validator.hpp"

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
        auto source = ebi::vcf::Source{path, ebi::vcf::InputFormat::VCF_FILE_VCF};
        auto records = std::vector<ebi::vcf::Record>{};

        auto validator = ebi::vcf::FullValidator{
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
  
    bool is_valid_vcf_file(std::istream & input)
    {
        auto source = ebi::vcf::Source{"stdin", ebi::vcf::InputFormat::VCF_FILE_VCF};
        auto records = std::vector<ebi::vcf::Record>{};

        auto validator = ebi::vcf::FullValidator{
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
}

int main(int argc, char** argv)
{
    if (argc < 2) {
        std::cerr << "Please provide an input VCF file" << std::endl;
        return 1;
    }

    const char * path = argv[1];
    bool is_valid;

    try {
        if (std::string{path} == "stdin") {
            is_valid = is_valid_vcf_file(std::cin);
        } else {
            is_valid = is_valid_vcf_file(path);
        }

        std::cout << "The input file is " << (is_valid ? "valid" : "not valid") << std::endl;
        return !is_valid; // A valid file returns an exit code 0
        
    } catch (std::runtime_error const & ex) {
        std::cout << "The input file is not valid" << std::endl;
        std::cerr << ex.what() << std::endl;
        return 1;
    }
}
