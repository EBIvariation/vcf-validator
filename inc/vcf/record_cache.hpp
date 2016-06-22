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

#ifndef VCF_VALIDATOR_RECORDCACHE_HPP
#define VCF_VALIDATOR_RECORDCACHE_HPP


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
        RecordCache(size_t capacity) : capacity{capacity}, unlimited{capacity == 0} { }

        /**
         * For a given Record, returns a vector of RecordCores that are duplicates.
         *
         * Even if more than one duplicate is found for the same variant during the file validation, each occurrence 
         * is reported only once:
         * - If just one processed record is equivalent to the parameter, both are reported in 2 different errors.
         * - If more than one processed record is equivalent to the new one, only the new one is reported.
         * 
         * Nonetheless, if the capacity is too small, it may cause incorrect reporting, such as reporting several times
         * the first occurrence or failing to report duplicates that are farther apart than the capacity.
         */
        std::vector<std::unique_ptr<Error>> check_duplicates(const Record &record)
        {
            auto record_cores = normalize(record);
            std::vector<std::unique_ptr<Error>> duplicates{};

            for (RecordCore &record_core: record_cores) {
                std::pair<std::multiset<RecordCore>::iterator, std::multiset<RecordCore>::iterator> range =
                        cache.equal_range(record_core);

                if (range.first == range.second) {
                    // no matches found
                } else {
                    // one or more matches found
                    std::stringstream ss;
                    ss << "Duplicated variant " << record_core.chromosome << ":" << record_core.position << ":"
                    << record_core.reference_allele << ">" << record_core.alternate_allele << " found in lines "
                    << range.first->line << " and " << record_core.line;
                    size_t first_occurence_line{range.first->line};

                    if (++range.first == range.second) {
                        // if only one match, return an extra error for the first occurrence
                        duplicates.emplace_back(new DuplicationError{first_occurence_line, ss.str()});
                    }

                    duplicates.emplace_back(new DuplicationError{record_core.line, ss.str()});
                }

                cache.insert(range.second, record_core);
            }

            shrink_to_fit();
            return duplicates;
        }

        /**
         * reduce cache size to this->capacity unless this->unlimited is true
         */
        void shrink_to_fit()
        {
            if (not unlimited) {
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
        std::multiset<RecordCore> cache;
        size_t capacity;    ///< max amount of RecorCores that the cache can hold
        bool unlimited; ///< if true, the set is not capped and will not erase any RecordCore
    };
  }
}

#endif //VCF_VALIDATOR_RECORDCACHE_HPP
