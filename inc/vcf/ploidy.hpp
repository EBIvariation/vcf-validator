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

#ifndef VCF_VALIDATOR_PLOIDY_HPP
#define VCF_VALIDATOR_PLOIDY_HPP

#include<map>

namespace ebi
{
  namespace vcf
  {
    class Ploidy
    {
      public:
        Ploidy(size_t default_ploidy) : Ploidy(default_ploidy, {})
        {}
        Ploidy(size_t default_ploidy, const std::map<std::string, size_t> &contig_ploidies)
                : default_ploidy(default_ploidy), contig_ploidies(contig_ploidies)
        {}

        size_t get_ploidy()
        {
            return default_ploidy;
        }

        size_t get_ploidy(std::string contig)
        {
            auto it = contig_ploidies.find(contig);
            if (it != contig_ploidies.end()) {
                return it->second;
            } else {
                return get_ploidy();
            }
        }

      private:
        size_t default_ploidy;
        std::map<std::string, size_t> contig_ploidies;
    };
  }
}


#endif //VCF_VALIDATOR_PLOIDY_HPP
