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

#ifndef STRING_UTILS_HPP
#define	STRING_UTILS_HPP

#include <cstring>
#include <string>
#include <vector>

namespace ebi
{
  namespace util
  {
    
    template<typename C>
    void string_split(std::string const & s, char const * delims, C & ret)
    {
        C output;
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
        
        output.swap(ret);
    }
    
  }
}

#endif	/* STRING_UTILS_HPP */

