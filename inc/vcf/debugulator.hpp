/**
 * Copyright 2017 EMBL - European Bioinformatics Institute
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

#ifndef VCF_DEBUGULATOR_HPP
#define VCF_DEBUGULATOR_HPP


#include <iostream>
#include <memory>
#include <vector>
#include <stdexcept>

#include "util/stream_utils.hpp"
#include "vcf/fixer.hpp"
#include "vcf/report_reader.hpp"

namespace ebi
{
  namespace vcf
  {
    namespace debugulator
    {

      size_t const default_line_buffer_size = 64 * 1024;

      size_t fix_vcf_file(std::istream &input,
                        ebi::vcf::ReportReader &errorDAO,
                        std::ostream &output);
    }
  }
}

#endif // VCF_DEBUGULATOR_HPP
