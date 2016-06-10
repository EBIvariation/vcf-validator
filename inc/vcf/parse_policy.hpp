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

#ifndef VCF_PARSE_POLICY_HPP
#define	VCF_PARSE_POLICY_HPP

#include <map>
#include <string>
#include <vector>

#include "parsing_state.hpp"
#include "file_structure.hpp"
#include "util/string_utils.hpp"
#include "error.hpp"
#include "normalizer.hpp"

namespace ebi
{
  namespace vcf
  {
          
    /**
     * Parsing policy that ignores the parsed tokens
     */
    class IgnoreParsePolicy
    {
      public:
        void handle_token_begin(ParsingState const & state) {}
        void handle_token_char(ParsingState const & state, char c) {}
        void handle_token_end(ParsingState const & state) {}
        void handle_token_end(ParsingState const & state, std::string token) {}
        void handle_newline(ParsingState const & state) {}
        
        void handle_fileformat(ParsingState const & state) {}
        
        void handle_meta_typeid(ParsingState const & state) {}
        void handle_meta_typeid(ParsingState const & state, std::string type_id) {}
        void handle_meta_line(ParsingState const & state) {}
        
        void handle_sample_name(ParsingState const & state) {}
        void handle_header_line(ParsingState const & state) {}
        
        void handle_column_end(ParsingState const & state, size_t n_columns) {}
        void handle_body_line(ParsingState & state) {}
        
        std::string current_token() const { return ""; }
        
        std::vector<std::string> column_tokens(std::string const & column) const { return {}; }
    };

    /**
     * Parsing policy that stores the parsed tokens for more thorough validations or future usage
     */
    class StoreParsePolicy
    {
      public:
        void handle_token_begin(ParsingState const & state);
        void handle_token_char(ParsingState const & state, char c);
        void handle_token_end(ParsingState const & state);
        void handle_token_end(ParsingState const & state, std::string token);
        void handle_newline(ParsingState const & state);
        
        void handle_fileformat(ParsingState const & state);
        
        void handle_meta_typeid(ParsingState const & state);
        void handle_meta_typeid(ParsingState const & state, std::string type_id);
        void handle_meta_line(ParsingState const & state);
        
        
        void handle_sample_name(ParsingState const & state);
        void handle_header_line(ParsingState const & state);
        
        void handle_column_end(ParsingState const & state, size_t n_columns);
        void handle_body_line(ParsingState const & state);
        
        std::string current_token() const;
        
        std::vector<std::string> column_tokens(std::string const & column) const;

      private:
        /**
         * Token being currently parsed
         */
        std::string m_current_token;
        
        /**
         * Token that acts as type ID for the whole line, like ALT/FILTER in meta entries
         */
        std::string m_line_typeid;
        
        /**
         * Tokens that must be grouped, like all key-value pairs in the INFO column
         */
        std::vector<std::string> m_grouped_tokens;
        
        /**
         * Tokens read in a line and grouped by an ID
         */
        std::map<std::string, std::vector<std::string>> m_line_tokens;
    };
      
  }
}

#endif	/* PARSE_POLICY_HPP */

