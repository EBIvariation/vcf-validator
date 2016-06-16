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
#ifndef VCF_VALIDATOR_NORMALIZER_HPP
#define VCF_VALIDATOR_NORMALIZER_HPP

#include "file_structure.hpp"

namespace ebi
{
  namespace vcf
  {
    /**
     * Subset of a Record, used to detect duplicates.
     */
    struct RecordCore
    {
        size_t line;
        std::string chromosome;
        size_t position;
        std::string reference_allele;
        std::string alternate_alleles;
        
        RecordCore(size_t line, const std::string &chromosome, size_t position, 
                   const std::string &reference_allele, const std::string &alternate_alleles) 
            : line(line), chromosome(chromosome), position(position), 
              reference_allele(reference_allele), alternate_alleles(alternate_alleles)
        { }
        
        /** A record "a" is less than another "b" if: 
         * - the chromosome string from "a" is less than the chromosome string from "b", or if they equal:
         * - the position from "a" is less than the position from "b", or if they equal:
         * - the reference_allele string from "a" is less than the reference_allele string from "b", or if they equal:
         * - the alternate_alleles string from "a" is less than the alternate_alleles string from "b".
         */
        bool operator<(const RecordCore &other) const;
        
        /**
         * Equality test without taking into account the line number, only chromosome, position, reference and alternate.
         */
        bool operator==(const RecordCore &other) const;
    };
    std::ostream &operator<<(std::ostream &os, const RecordCore &record);
    
    /**
     * normalizes a record and returns a vector of RecordCores.
     * 
     * the normalization performs two actions:
     * - split the multiallelic variants into several individual ones. They are NOT sorted by position, but by allele as
     *      listed in the original variant.
     * - the repeated bases (which serve as context) in both reference and alternate alleles are removed 
     * 
     * These actions are performed trimming the trailing context first, and then the leading context. 
     * This is NOT compliant with the VCF specification. See normalize_pad_at_left for more information.
     */
    std::vector<RecordCore> normalize(const Record &record/* , ParsingState?*/);
    
    /**
     * This differs from the regular normalize, in that this is more VCF specification-compliant.
     * 
     * The spec requires that in case of insertion or deletion where one allele (reference or alternate) would be empty,
     * it must be added a pad base *before* the insertion. If we remove the trailing context first 
     * (as `normalize` does), we are interpreting that the context is *after*.
     * 
     * This function `normalize_pad_at_left` removes first the leading context, so that the pad is *before*, 
     * according to the spec. The problem with this function is that some third parties perform as in `normalize`, 
     * incoherently with the spec, trying to move the position of the variant as few bases as possible. If the same data
     * is used in this function and those third parties, the same variant may appear as different positions. 
     */
    std::vector<RecordCore> normalize_pad_at_left(const Record &record/* , ParsingState?*/);
  }
}

#endif //VCF_VALIDATOR_NORMALIZER_HPP