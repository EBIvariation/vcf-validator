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
#ifndef VCF_NORMALIZER_HPP
#define VCF_NORMALIZER_HPP

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
        std::string alternate_allele;
        RecordType alternate_allele_type;

        RecordCore(size_t line,
                   const std::string &chromosome,
                   size_t position,
                   const std::string &reference_allele,
                   const std::string &alternate_alleles,
                   RecordType alternate_allele_types
                   ) : line(line),
                       chromosome(chromosome),
                       position(position),
                       reference_allele(reference_allele),
                       alternate_allele(alternate_alleles),
                       alternate_allele_type(alternate_allele_types)
        {

        }

        /** A record "a" is less than another "b" iff:
         * - the chromosome string from "a" is lexicographically less than the chromosome string from "b", or if they equal:
         * - the position from "a" is numerically less than the position from "b", or if they equal:
         * - the reference_allele string from "a" is lexicographically less than the reference_allele string from "b", or if they equal:
         * - the alternate_allele string from "a" is lexicographically less than the alternate_allele string from "b".
         */
        bool operator<(const RecordCore &other) const;

        /**
         * Equality test without taking into account the line number; only chromosome, position, reference and alternate.
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
     * This is NOT compliant with the VCF specification. See `normalize_right_alignment` for more information.
     *
     * Please note that this is a naive normalization, the best we can do without the FASTA file.
     */
    std::vector<RecordCore> normalize(const Record &record/* , ParsingState?*/);

    /**
     * This differs from the regular normalize, in that this is more VCF specification-compliant.
     *
     * The spec requires that in case of insertion or deletion where one allele (reference or alternate) would be empty,
     * it must be added a pad base *before* the insertion. If we remove the trailing context first
     * (as `normalize` does), we are interpreting that the context is *after*.
     *
     * This function `normalize_right_alignment` removes first the leading context, so that the pad is *before*,
     * according to the spec. The problem with this function is that some third parties perform as in `normalize`,
     * incoherently with the spec, doing alignment to the left. If the same data
     * is used in this function and those third parties, the same variant may appear as different positions.
     *
     * This function is equally naive as the `normalize` one, as it has not the FASTA file either.
     */
    std::vector<RecordCore> normalize_right_alignment(const Record &record/* , ParsingState?*/);
  }
}

#endif // VCF_NORMALIZER_HPP
