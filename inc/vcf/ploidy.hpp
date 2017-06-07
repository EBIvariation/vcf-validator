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

#ifndef VCF_VALIDATOR_PLOIDY_HPP
#define VCF_VALIDATOR_PLOIDY_HPP

#include<map>

namespace ebi
{
  namespace vcf
  {
    /**
     * Class that keeps track of the ploidy of every contig.
     *
     * Ploidy is the number of sets of chromosomes in a cell, or in the cells of an organism.
     * You can give a simple number if the ploidy is the same across all the contigs/chromosomes, and additionally
     * you can specify a map (contig to ploidy) to tell the exceptions to the ploidy. Examples:
     *
     * For a typical VCF with all variants with the same ploidy:
     *  Ploidy{2}
     *
     * For humans, with ploidy 2 except for chromosome Y which is haploid (assuming X as diploid even for males):
     *  Ploidy{2, {{"Y", 1}}}
     *
     * For a VCF of an organism that has 4 copies of chromosome "1", 1 copy of chromosome "Y"
     * and 3 copies of all the other chromosomes:
     *  Ploidy{3, {{"1", 4}, {"Y", 1}}};
     */
    class Ploidy
    {
      public:
        explicit Ploidy(size_t default_ploidy, const std::map<std::string, size_t> &contig_ploidies = {})
                : default_ploidy(default_ploidy), contig_ploidies(contig_ploidies) {}

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
