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

#ifndef EBI_PARSER_TEST_AUX_HPP
#define EBI_PARSER_TEST_AUX_HPP

#include <iostream>
#include <fstream>
#include <memory>

#include <boost/filesystem.hpp>

#include "catch/catch.hpp"

#include "util/stream_utils.hpp"
#include "vcf/file_structure.hpp"
#include "vcf/validator.hpp"

namespace ebi
{
    inline bool is_valid(std::string path, vcf::Version version)
    {
        std::ifstream input{path};
        auto validator = vcf::build_parser(path, vcf::ValidationLevel::warning, version, 2);
        std::vector<std::unique_ptr<ebi::vcf::ReportWriter>> outputs;

        return vcf::is_valid_vcf_file(input, *validator, outputs);
    }
}

#endif // EBI_PARSER_TEST_AUX_HPP

