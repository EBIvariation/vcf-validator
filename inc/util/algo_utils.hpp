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

#ifndef UTIL_ALGO_UTILS_HPP
#define UTIL_ALGO_UTILS_HPP

#include <algorithm>

namespace ebi
{
  namespace util
  {
    /**
     * Wrapper function for STL's `find` algorithm, simplifies its usage
     * Searches for the element from the beginning till the end of the container
     * @param container input STL container
     * @param element to be searched in the container
     * @return result of search, i.e., `true` if element is found and `false` if not
     */
    template<typename Container, typename Element>
    bool contains(Container const & container, Element const & element)
    {
        return std::find(container.begin(), container.end(), element) != container.end();
    }

    /**
     * Wrapper function for STL's `find_if` algorithm, simplifies its usage
     * Searches for an element for which `predicate` returns `true`, from the beginning till the end of the container
     * @param container input STL container
     * @param predicate function that takes elements of the container and returns a bool that tells if the element 
     * matches the condition of the function
     * @return result of the search, i.e., `true` if there is an element in `container` for which `predicate` returns
     * true and `false` if there is no such element
     */
    template<typename Container, typename Predicate>
    bool contains_if(Container const & container, Predicate const & predicate)
    {
       return std::find_if(container.begin(), container.end(), predicate) != container.end();
    }

    /**
     * Wrapper function for STL's `find_if_not` algorithm, simplifies its usage
     * Searches for an element for which `predicate` returns `false`, from the beginning till the end of the container
     * @param container input STL container
     * @param predicate function that takes elements of the container and returns a bool that tells if the element 
     * matches the condition of the function
     * @return result of the search, i.e., `true` if there is no element in `container` for which `predicate` returns
     * true and `false` if there is any such element
     */
    template<typename Container, typename Predicate>
    bool contains_if_not(Container const & container, Predicate const & predicate)
    {
       return std::find_if_not(container.begin(), container.end(), predicate) != container.end();
    }
 
  }
}

#endif // UTIL_ALGO_UTILS_HPP
