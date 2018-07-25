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

#ifndef ASSEMBLY_REPORT_READER_HPP
#define ASSEMBLY_REPORT_READER_HPP

#include <memory>
#include "vcf/error.hpp"

namespace ebi
{
  namespace vcf
  {
    class AssemblyReportReader
    {
      public:
        virtual ~AssemblyReportReader() {}

        virtual MatchStats count_entry() = 0;
        virtual void for_each_entry(std::function<void(std::shared_ptr<MatchStats>)> user_function) = 0;
    };

  }
}


#endif // ASSEMBLY_REPORT_READER_HPP
