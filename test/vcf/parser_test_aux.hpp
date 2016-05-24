/**
 * Copyright 2016 EMBL - European Bioinformatics Institute
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

#ifndef TEST_AUX_HPP
#define	TEST_AUX_HPP

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

        while (!stream.eof() && stream.get(c)) {
            container.push_back(c);
            if (c == '\n') {
                break;
            }
        }

        return stream;
    }
    
}

#endif

