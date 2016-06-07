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

#ifndef VCF_ERROR_POLICY_HPP
#define	VCF_ERROR_POLICY_HPP

#include <string>

#include "parsing_state.hpp"
#include "error.hpp"

namespace ebi
{
  namespace vcf
  {
    
    /**
     * Error management policy that aborts execution when an error is found
     */
    class AbortErrorPolicy
    {
      public:
        void handle_error(ParsingState &state, Error *error);
        void handle_warning(ParsingState &state, Error *error);
    };

    /**
     * Error management policy that reports when an error is found but continues execution
     */
    class ReportErrorPolicy
    {
      public:
        void handle_error(ParsingState &state, Error *error);
        void handle_warning(ParsingState &state, Error *error);
    };

  }
}

#endif	/* VCF_ERROR_POLICY_HPP */

