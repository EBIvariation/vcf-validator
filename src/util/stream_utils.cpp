/**
 * Copyright 2014-2015 EMBL - European Bioinformatics Institute
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

#include "util/stream_utils.hpp"

namespace ebi
{
  namespace util
  {
    std::ostream &operator<<(std::ostream &os, const std::vector<std::string> &container)
    {
        return print_container<std::vector<std::string>>(os, container);
    }
    
    std::ostream &operator<<(std::ostream &os, const std::pair<std::string, std::string> &container)
    {
        return os << "{" << container.first << ", " << container.second << "}";
    }
    
    std::ostream &operator<<(std::ostream &os, const std::map<std::string, std::string> &container)
    {
        return print_container<std::map<std::string, std::string>>(os, container);
    }
  }
}
