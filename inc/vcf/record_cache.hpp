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

    class RecordCache
    {
      public:

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
        }

      private:
        std::set<RecordCore> cache;
    };
  }
}

#endif //VCF_VALIDATOR_RECORDCACHE_HPP
