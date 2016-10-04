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

#ifndef VCF_REPORT_READER_HPP
#define VCF_REPORT_READER_HPP

#include <memory>
#include "vcf/error.hpp"

namespace ebi
{
  namespace vcf
  {
    class ReportReader
    {
      public:
        virtual ~ReportReader() {}  // needed if inheriting classes use raw pointers, instead of references or shared_ptrs
        virtual size_t count_errors() = 0;
        virtual void for_each_error(std::function<void(std::shared_ptr<Error>)> user_function) = 0;
        
        virtual size_t count_warnings() = 0;
        virtual void for_each_warning(std::function<void(std::shared_ptr<Error>)> user_function) = 0;
    };

  }
}


#endif // VCF_REPORT_READER_HPP
