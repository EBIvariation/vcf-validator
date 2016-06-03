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

#include "vcf/validator.hpp"

namespace ebi
{
  namespace vcf
  {
  
    ParserImpl::ParserImpl(std::shared_ptr<Source> const & source,
                           std::shared_ptr<std::vector<Record>> const & records
    )
    : ParsingState{source, records}
    {
        
    }

    void ParserImpl::parse(std::vector<char> const & text)
    {
      char const * p = &text[0];
      char const * pe = &text[0] + text.size();
      char const * eof = nullptr;

      clear_records();
      clear_errors();
      clear_warnings();
      parse_buffer(p, pe, eof);
    }

    void ParserImpl::parse(std::string const & text)
    {
      char const * p = text.data();
      char const * pe = text.data() + text.size();
      char const * eof = nullptr;

      clear_records();
      clear_errors();
      clear_warnings();
      parse_buffer(p, pe, eof);
    }

    void ParserImpl::end()
    {
      char const * empty = "";
      clear_records();
      clear_errors();
      clear_warnings();
      parse_buffer(empty, empty, empty);
    }

    bool ParserImpl::is_valid() const
    {
      return m_is_valid;
    }

    const std::shared_ptr<std::vector<std::unique_ptr<Error>>> ParserImpl::errors() const
    {
      return ParsingState::errors;
    }
    
    const std::shared_ptr<std::vector<std::unique_ptr<Error>>> ParserImpl::warnings() const
    {
      return ParsingState::warnings;
    }

  }
}
