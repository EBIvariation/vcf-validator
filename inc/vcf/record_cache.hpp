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
     * For memory reasons, this class can be configured to store only the last `n` elements. This will only detect
     * duplicates if the input is sorted with a
     */
    class RecordCache
    {
      public:
        RecordCache() : RecordCache{1000} { }

        /**
         * @param capacity: maximum amount of RecordCores to store at any time. Default is 1000. A value of 0 is valid
         * but is useless. A negative value disables the limit, thus storing every RecordCore received, use with caution.
         */
        RecordCache(long capacity)
        {
            if (capacity >= 0) {
                this->capacity = static_cast<size_t>(capacity);
                unlimited = false;
            } else {
                this->capacity = 0;
                unlimited = true;
            }
        }

        void check_duplicates(const Record &record)
        {
            auto record_cores = normalize(record);
            for (RecordCore &record_core: record_cores) {
                std::pair<std::set<RecordCore>::iterator, bool> unique = cache.insert(record_core);
                if(not unique.second) {
                    std::stringstream ss;
                    ss << "Duplicated record detected: first occurrence: " << *unique.first
                    << ", second occurrence: " << record_core;
                    throw new BodySectionError{record_core.line, ss.str()};
                }
            }
            shrink_to_fit();
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
        std::set<RecordCore> cache;
        size_t capacity;    ///< max size of the cache
        bool unlimited; ///< if true, the set is not capped and will not erase any RecordCore
    };
  }
}

#endif //VCF_VALIDATOR_RECORDCACHE_HPP
