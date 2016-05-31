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
        do {
            stream.get(c);
            container.push_back(c);
        } while (stream && c != '\n');

        return stream;
    }
  }
}

#endif  /* STREAM_UTILS_HPP */

