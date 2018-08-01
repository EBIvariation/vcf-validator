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

#include <string>

namespace ebi
{
  namespace vcf
  {

    class VcfVariant
    {
      public:
        std::string chromosome;
        size_t position;
        std::string reference_allele;

        VcfVariant(std::string const &line);

      private:
        std::string format_chromosome(std::string const &chromosome);
    };
  }
}

#endif // VCF_VCF_FASTA_VARIANT_HPP
