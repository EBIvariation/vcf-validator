/* 
 * File:   string_utils.hpp
 * Author: Cristina Yenyxe Gonzalez Garcia <cyenyxe@ebi.ac.uk>
 *
 * Created on 08 June 2015, 16:22
 */

#ifndef STRING_UTILS_HPP
#define	STRING_UTILS_HPP

#include <string>
#include <vector>

namespace opencb
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

