/**
 * Copyright 2018 EMBL - European Bioinformatics Institute
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

#ifndef VCF_VCF_FASTA_VARIANT_HPP
#define VCF_VCF_FASTA_VARIANT_HPP

#include <algorithm>
#include <string>
#include <vector>

#include "util/string_utils.hpp"
#include "vcf/string_constants.hpp"
#include "vcf/vcf_fasta_variant.hpp"

namespace ebi
{
  namespace vcf
  {

    struct RecordCore
    {
        std::string chromosome;
        size_t position;
        std::string reference_allele;
        std::string line;

        RecordCore(std::string const &line) : line(line)
        {
            std::vector<std::string> record_columns;
            util::string_split(line, "\t", record_columns);

            chromosome = record_columns[0];
            position = static_cast<size_t>(std::stoi(record_columns[1]));
            reference_allele = record_columns[3];
        }

    };
  }
}

#endif // VCF_VCF_FASTA_VARIANT_HPP
