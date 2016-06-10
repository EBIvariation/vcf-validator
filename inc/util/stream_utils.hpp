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

#ifndef STREAM_UTILS_HPP
#define STREAM_UTILS_HPP

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <functional>

namespace ebi
{
  namespace util
  {
    template <typename Container>
    std::istream & readline(std::istream & stream, Container & container)
    {
        char c;
        container.clear();

        // using operator bool: http://www.cplusplus.com/reference/ios/ios/fail/
        // `stream.get()` sets failbit as well on eof
        while (stream && stream.get(c)) {
            container.push_back(c);
            if (c == '\n') {
                break;
            }
        }

        return stream;
    }

    /**
     * This is a generic method that prints a collection if it has the operations ".size()", ".begin()", ".end()" 
     * defined and they provide iterators, and the inner type has an overloaded "operator<<"
     */
    template <typename T>
    std::ostream &print_container(std::ostream &os, const T &container) {
        size_t size = container.size();
        os << "[";
        if (size > 0) {
            auto it = container.begin();
            os << *it;
            it++;
            for (; it != container.end(); ++it) {
                os << ", " << *it;
            }
        }
        os << "]";
        return os;
    }
    
    // the next functions allow using the previous print_container in a easier syntax
    std::ostream &operator<<(std::ostream &os, const std::vector<std::string> &container);
    std::ostream &operator<<(std::ostream &os, const std::pair<std::string, std::string> &container);
    std::ostream &operator<<(std::ostream &os, const std::map<std::string, std::string> &container);
  }
}

#endif  /* STREAM_UTILS_HPP */

