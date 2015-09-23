/**
 * Copyright 2014-2015 EMBL - European Bioinformatics Institute
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

namespace
{
    using namespace ebi::vcf;

    void throw_syntax_error(ParsingState const &)
    {
        throw ParsingError("Invalid VCF syntax");
    }

    void throw_syntax_error(std::string const & msg)
    {
        throw ParsingError(msg);
    }
}

namespace ebi
{
  namespace vcf
  {

    void AbortErrorPolicy::handle_fileformat_section_error(ParsingState & state, std::string message)
    {
        state.m_is_valid = false;
        throw_syntax_error("Line " + std::to_string(state.n_lines) + ": " + message);
    }

    void AbortErrorPolicy::handle_meta_section_error(ParsingState & state, std::string message)
    {
        state.m_is_valid = false;
        throw_syntax_error("Line " + std::to_string(state.n_lines) + ": " + message);
    }

    void AbortErrorPolicy::handle_header_section_error(ParsingState & state, std::string message)
    {
        state.m_is_valid = false;
        throw_syntax_error("Line " + std::to_string(state.n_lines) + ": " + message);
    }

    void AbortErrorPolicy::handle_body_section_error(ParsingState & state, std::string message)
    {
        state.m_is_valid = false;
        throw_syntax_error("Line " + std::to_string(state.n_lines) + ": " + message);
    }

    
    void AbortErrorPolicy::handle_fileformat_section_warning(ParsingState const & state, std::string message)
    {
        std::cerr << "Line " << state.n_lines << ": " << message << " (warning)" << std::endl;
    }

    void AbortErrorPolicy::handle_meta_section_warning(ParsingState const & state, std::string message)
    {
        std::cerr << "Line " << state.n_lines << ": " << message << " (warning)" << std::endl;
    }

    void AbortErrorPolicy::handle_header_section_warning(ParsingState const & state, std::string message)
    {
        std::cerr << "Line " << state.n_lines << ": " << message << " (warning)" << std::endl;
    }

    void AbortErrorPolicy::handle_body_section_warning(ParsingState const & state, std::string message)
    {
        std::cerr << "Line " << state.n_lines << ": " << message << " (warning)" << std::endl;
    }

  }
}
