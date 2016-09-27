/**
 * Copyright 2015-2016 EMBL - European Bioinformatics Institute
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

#include "parser_test_aux.hpp"

namespace ebi
{
    
    bool is_valid_v43(std::string path)
    {
        std::ifstream input{path};

        auto validator = ebi::vcf::FullValidator_v43{
                std::make_shared<ebi::vcf::Source>(path, ebi::vcf::InputFormat::VCF_FILE_VCF, ebi::vcf::Version::v43, 2)
        };

        std::vector<char> line;
        line.reserve(default_line_buffer_size);

        while (ebi::util::readline(input, line)) { 
            validator.parse(line);
        }
        
        validator.end();
        
        return validator.is_valid();
    }

    TEST_CASE("Files that fail the validation under specification v4.3", "[failed]") 
    {
        auto folder = boost::filesystem::path("test/input_files/v4.3/failed");
        std::vector<boost::filesystem::path> v;
        copy(boost::filesystem::directory_iterator(folder), boost::filesystem::directory_iterator(), back_inserter(v));
        
        for (auto path : v)
        {
            SECTION(path.string())
            {
                CHECK_FALSE(is_valid_v43(path.string()));
            }
        }
    }

    TEST_CASE("Files that pass the validation under specification v4.3", "[passed]") 
    {
        auto folder = boost::filesystem::path("test/input_files/v4.3/passed");
        std::vector<boost::filesystem::path> v;
        copy(boost::filesystem::directory_iterator(folder), boost::filesystem::directory_iterator(), back_inserter(v));
        
        for (auto path : v)
        {
            SECTION(path.string())
            {
                CHECK(is_valid_v43(path.string()));
            }
        }
    }

}

