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

#ifndef VCF_RECORD_HPP
#define VCF_RECORD_HPP

#include <iostream>

#include <boost/algorithm/string/predicate.hpp>
#include <boost/math/special_functions/binomial.hpp>
#include <boost/regex.hpp>

#include "util/string_utils.hpp"

namespace ebi
{
  namespace vcf
  {
    
    bool is_record_subfield_in_header(std::string const & field_value,
                                      std::multimap<std::string, MetaEntry>::iterator begin,
                                      std::multimap<std::string, MetaEntry>::iterator end);
    
  }
}

#endif // VCF_RECORD_HPP

