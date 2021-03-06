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

#ifndef VCF_RECORD_CACHE_HPP
#define VCF_RECORD_CACHE_HPP


#include <set>
#include <sstream>
#include "normalizer.hpp"
#include "file_structure.hpp"

namespace ebi
{
  namespace vcf
  {

    /**
     * Stores a summary of a Record to check that there are no duplicates.
     *
     * To limit memory usage, this class can be configured to store only the last `n` elements. This will only detect
     * duplicates if the input is almost sorted (i.e. if no element is unsorted out of its place more than `n` elements)
     */
    class RecordCache
    {
      public:

        /**
         * Creates a cache that can hold at most 1000 entries.
         */
        RecordCache() : RecordCache{1000} { }

        /**
         * @param capacity: maximum amount of RecordCores that this instance can hold at any time.
         * A value of 0 disables the limit, thus storing every RecordCore received. Use with caution.
         */
        explicit RecordCache(size_t capacity) : capacity{capacity}, unlimited{capacity == 0} { }

         /**
         * Getter function which returns a vector of Errors.
         * For a given Record, returned Errors correspond to the duplicates found that aren't symbolic alleles.
         *
         * Even if more than one duplicate is found for the same variant during the file validation, each occurrence
         * is reported only once:
         * - If just one processed record is equivalent to the parameter, both are reported in 2 different errors.
         * - If more than one processed record is equivalent to the new one, only the new one is reported.
         *
         * Nonetheless, if the capacity is too small, it may cause incorrect reporting, such as reporting several times
         * the first occurrence or failing to report duplicates that are farther apart than the capacity.
         */
        std::vector<std::unique_ptr<Error>> get_duplicates()
        {
            return std::move(list_duplicates);
        }

        /**
         * Getter function which returns a vector of Errors.
         * For a given Record, returned Errors correspond to the duplicates found that are symbolic alleles.
         *
         * Even if more than one duplicate is found for the same variant during the file validation, each occurrence
         * is reported only once:
         * - If just one processed record is equivalent to the parameter, both are reported in 2 different errors.
         * - If more than one processed record is equivalent to the new one, only the new one is reported.
         *
         * Nonetheless, if the capacity is too small, it may cause incorrect reporting, such as reporting several times
         * the first occurrence or failing to report duplicates that are farther apart than the capacity.
         */
        std::vector<std::unique_ptr<Error>> get_symbolic_duplicates()
        {
            return std::move(list_symbolic_duplicates);
        }


        /**
         * This function serves as the data generator to be used before utilizing get_duplicates() and
         * get_symbolic_duplicates() functions.
         *
         * For a given Record, populates the list_duplicates and list_symbolic_duplicates vectors with
         * non symbolic and symbolic duplicates respectively
         *
         * Even if more than one duplicate is found for the same variant during the file validation, each occurrence
         * is reported only once:
         * - If just one processed record is equivalent to the parameter, both are reported in 2 different errors.
         * - If more than one processed record is equivalent to the new one, only the new one is reported.
         *
         * Nonetheless, if the capacity is too small, it may cause incorrect reporting, such as reporting several times
         * the first occurrence or failing to report duplicates that are farther apart than the capacity.
         */
        void check_duplicates(const Record &record)
        {
            auto record_cores = normalize(record);

            list_duplicates.clear();
            list_symbolic_duplicates.clear();

            clear_cache_if_we_moved_to_the_next_chromosome(record.chromosome);

            for (RecordCore &record_core: record_cores) {

                // create references to the appropriate data structures for th alternate allele type
                auto & cache = (record_core.alternate_allele_type == RecordType::STRUCTURAL) ? cache_symbolic_duplicates : cache_duplicates;
                auto & duplicates = (record_core.alternate_allele_type == RecordType::STRUCTURAL) ? list_symbolic_duplicates : list_duplicates;

                auto range = cache.equal_range(record_core);

                if (range.first == range.second) {
                    // no matches found
                } else {
                    // one or more matches found
                    std::stringstream ss;
                    ss << "Duplicated variant " << record_core.chromosome << ":" << record_core.position << ":"
                    << record_core.reference_allele << ">" << record_core.alternate_allele << " found";

                    std::string duplicate_variant_lines = "It occurs in lines " + std::to_string(range.first->line_num)
                                                          + " and " + std::to_string(record_core.line_num);
                    size_t first_occurence_line{range.first->line_num};

                    if (++range.first == range.second) {
                        // if only one match, return an extra error for the first occurrence
                        duplicates.emplace_back(new DuplicationError{first_occurence_line, ss.str()});
                    }

                    duplicates.emplace_back(new DuplicationError{record_core.line_num, ss.str(), duplicate_variant_lines});
                }

                cache.insert(range.second, record_core);
            }

            shrink_to_fit(cache_symbolic_duplicates);
            shrink_to_fit(cache_duplicates);
        }

        /**
         * EVA-1950: the cache removes "lexicographically lower" chromosomes when the cache is full, but with
         * that sorting, "chr10" is lower than "chr2", so new variants in "chr10" get deleted to keep the ones
         * in "chr2", and duplicates in "chr10" will go undetected.
         *
         * **The chosen solution was to keep in the cache variants from only one chromosome at a time.**
         *
         * The next solutions were considered and **DISCARDED**:
         *
         * 1. Using Least Recently Used cache. This would require using esoteric data structures and/or dependencies,
         * or keeping several simpler structures in sync, like a map and a queue that point to each other's contents.
         * 2. A poor solution could be changing the ordering to "numerically lower", but that will be very tricky
         * to get right with weird chrs like (versioned) accessions. e.g.: NC_01.1 is a chr, which is likely to
         * appear before a contig GK_01.1, and we would need a sorting method that evaluates NC_01.1 < GK_01.1.
         * 3. Using the line number (Record::line) as sorting criteria. This wouldn't work because we need to group the
         * same conceptual variants together to detect duplicates, and the multiset uses the comparator function to
         * group the variants, which would never be grouped because the lines would be different.
         */
        void clear_cache_if_we_moved_to_the_next_chromosome(const std::string &chromosome) {
            if (current_chromosome != chromosome) {
                cache_duplicates.clear();
                cache_symbolic_duplicates.clear();
                current_chromosome = chromosome;
            }
        }

        /**
         * reduce cache size to this->capacity unless this->unlimited is true
         */
        void shrink_to_fit(std::multiset<RecordCore> &cache)
        {
            if (!unlimited) {
                size_t count = cache.size();
                if (count > capacity) {
                    auto erase_until = cache.begin();
                    for (size_t j = 0; j < count - capacity; ++j) {
                        erase_until++;
                    }
                    cache.erase(cache.begin(), erase_until);
                }
            }
        }

      private:
        std::multiset<RecordCore> cache_duplicates;
        std::multiset<RecordCore> cache_symbolic_duplicates;
        std::vector<std::unique_ptr<Error>> list_duplicates;
        std::vector<std::unique_ptr<Error>> list_symbolic_duplicates;
        std::string current_chromosome;
        size_t capacity;    ///< max amount of RecordCores that the cache can hold
        bool unlimited; ///< if true, the set is not capped and will not erase any RecordCore
    };
  }
}

#endif // VCF_RECORD_CACHE_HPP
