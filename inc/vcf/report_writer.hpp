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

#ifndef VCF_REPORT_WRITER_HPP
#define VCF_REPORT_WRITER_HPP

#include <iostream>
#include <string>
#include <stdexcept>

#include "vcf/error.hpp"

namespace ebi
{
  namespace vcf
  {
    class ReportWriter
    {
      public:
        virtual ~ReportWriter() {}  // needed if using raw pointers, instead of references or shared_ptrs in children
        virtual void write_error(Error &error) = 0;
        virtual void write_warning(Error &error) = 0;
    };

    class StdoutReportWriter : public ReportWriter
    {
      public:
        virtual void write_error(Error &error) override
        {
          std::cout << error.what() << std::endl;
        }
        virtual void write_warning(Error &error) override
        {
          std::cout << error.what() << " (warning)" << std::endl;
        }
    };
  }
}


#endif // VCF_REPORT_WRITER_HPP
