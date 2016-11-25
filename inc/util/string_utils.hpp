/**
 * Copyright 2015 EMBL - European Bioinformatics Institute
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

#ifndef UTIL_STRING_UTILS_HPP
#define UTIL_STRING_UTILS_HPP

#include <cstring>
#include <string>
#include <vector>

namespace ebi
{
  namespace util
  {
    /**
     * Splits `s` using `delims` as separator and fills the container `ret` with the parts.
     * An empty string results in an empty container `ret`.
     * @param s input string to split
     * @param delims any character here acts as a separator
     * @param ret return by reference the container filled with the string split.
     */
    template<typename C>
    void string_split(std::string const & s, char const * delims, C & ret)
    {
        C output;

        if (s.size() > 0) {
            char const* p = s.c_str();
            char const* q = strpbrk(p+1, delims);

            // Insert first to last-1 elements
            for( ; q != NULL; q = strpbrk(p, delims) )
            {
                output.push_back(typename C::value_type(p, q));
                p = q + 1;
            }

            // Insert last element
            if (p < &(s.back()) + 1) {
                output.push_back(typename C::value_type(p));
            }
        }

        output.swap(ret);
    }

    /**
     * Temporal implementation for mismatch with 2 starts and 2 ends. It is not in STL for c++11, but it will in c++14.
     *
     * reference: Third version at http://en.cppreference.com/w/cpp/algorithm/mismatch#Possible_implementation
     */
    template<class InputIt1, class InputIt2>
    std::pair<InputIt1, InputIt2>
    mismatch(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2)
    {
        while (first1 != last1 && first2 != last2 && *first1 == *first2) {
            ++first1, ++first2;
        }
        return std::make_pair(first1, first2);
    }
  }
}

#endif // UTIL_STRING_UTILS_HPP

