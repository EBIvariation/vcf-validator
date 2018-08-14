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

    struct Record_Core
    {
        std::string line;
        std::string chromosome;
        size_t position;
        std::string reference_allele;
        std::string alternate_allele;

        Record_Core(const std::string & line, const std::string & chromosome, size_t position,
                   const std::string & reference_allele, const std::string & alternate_alleles)
            : line(line), chromosome(chromosome), position(position), reference_allele(reference_allele),
              alternate_allele(alternate_alleles) { }

    };
  }
}

#endif // VCF_VCF_FASTA_VARIANT_HPP
