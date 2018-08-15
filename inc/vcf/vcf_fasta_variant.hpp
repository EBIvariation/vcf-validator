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
#include "file_structure.hpp"

namespace ebi
{
  namespace vcf
  {

    struct Record_Core
    {
        std::string line;
        size_t line_num;
        std::string chromosome;
        size_t position;
        std::string reference_allele;
        std::string alternate_allele;
        RecordType alternate_allele_type;

        Record_Core(const std::string & line,
                    size_t line_num,
                    const std::string & chromosome,
                    size_t position,
                    const std::string & reference_allele,
                    const std::string & alternate_alleles,
                    RecordType alternate_allele_types
                    ) : line(line),
                        line_num(line_num),
                        chromosome(chromosome),
                        position(position),
                        reference_allele(reference_allele),
                        alternate_allele(alternate_alleles),
                        alternate_allele_type(alternate_allele_types)
        {

        }

    };
  }
}

#endif // VCF_VCF_FASTA_VARIANT_HPP
