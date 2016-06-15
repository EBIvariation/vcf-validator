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

#include "vcf/parse_policy.hpp"

namespace ebi
{
  namespace vcf
  {

    void StoreParsePolicy::handle_token_begin(ParsingState const & state)
    {
        m_current_token = std::string{};
    }

    void StoreParsePolicy::handle_token_char(ParsingState const & state, char c)
    {
        m_current_token.push_back(c);
    }

    void StoreParsePolicy::handle_token_end(ParsingState const & state) 
    {
        m_grouped_tokens.push_back(m_current_token);
    }
    
    void StoreParsePolicy::handle_token_end(ParsingState const & state, std::string token) 
    {
        m_grouped_tokens.push_back(token);
    }
    
    void StoreParsePolicy::handle_newline(ParsingState const & state) 
    {
        m_current_token.clear();
        m_grouped_tokens.clear();
        m_line_tokens.clear();
    }

    void StoreParsePolicy::handle_fileformat(ParsingState const & state)
    {
        Version fileformat_version = Version::v41;

        if (m_current_token == "VCFv4.1") {
            fileformat_version = Version::v41;
        } else if (m_current_token == "VCFv4.2") {
            fileformat_version = Version::v42;
        } else if (m_current_token == "VCFv4.3") {
            fileformat_version = Version::v43;
        } else {
            throw new FileformatError{state.n_lines, "Not allowed VCF fileformat version"};
        }
        
        if (fileformat_version != state.source->version) {
            throw new FileformatError{state.n_lines, "Unexpected VCF fileformat version found"};
        } else {
            state.set_version(fileformat_version);
        }
    }

    void StoreParsePolicy::handle_meta_typeid(ParsingState const & state)
    {
        m_line_typeid = m_current_token;
    }

    void StoreParsePolicy::handle_meta_typeid(ParsingState const & state, std::string type_id) 
    {
        m_line_typeid = type_id;
    }

    
    void StoreParsePolicy::handle_meta_line(ParsingState const & state) 
    {
        // Put together m_line_typeid and m_grouped_tokens in a single MetaEntry object
        // Add MetaEntry to Source

        if (m_line_typeid == "") { // Plain value
            state.add_meta(MetaEntry{state.n_lines, m_grouped_tokens[0]});

        } else if (m_grouped_tokens.size() == 1) { // TypeID=value
            state.add_meta(MetaEntry{state.n_lines, m_line_typeid, m_grouped_tokens[0]});

        } else if (m_grouped_tokens.size() % 2 == 0) { // TypeID=<Key-value pairs>
            auto key_values = std::map<std::string, std::string>{};
            for (size_t i = 0; i < m_grouped_tokens.size(); i += 2) {
                key_values[m_grouped_tokens[i]] = m_grouped_tokens[i+1];
            }
            state.add_meta(MetaEntry{state.n_lines, m_line_typeid, key_values});

        } else {
            throw new MetaSectionError{state.n_lines, "Meta line description is not a value, nor a TypeID=value, nor a TypeID=<Key-value pairs>"};
        }
    }


    void StoreParsePolicy::handle_sample_name(ParsingState const & state)
    {
        m_grouped_tokens.push_back(m_current_token);
    }

    void StoreParsePolicy::handle_header_line(ParsingState const & state) 
    {
        state.set_samples(m_grouped_tokens);
    }


    void StoreParsePolicy::handle_column_end(ParsingState const & state, size_t n_columns) 
    {
        switch(n_columns) {
            case 1:
                m_line_tokens["CHROM"] = m_grouped_tokens;
                break;
            case 2:
                m_line_tokens["POS"] = m_grouped_tokens;
                break;
            case 3:
                m_line_tokens["ID"] = m_grouped_tokens;
                break;
            case 4:
                m_line_tokens["REF"] = m_grouped_tokens;
                break;
            case 5:
                m_line_tokens["ALT"] = m_grouped_tokens;
                break;
            case 6:
                m_line_tokens["QUAL"] = m_grouped_tokens;
                break;
            case 7:
                m_line_tokens["FILTER"] = m_grouped_tokens;
                break;
            case 8:
                m_line_tokens["INFO"] = m_grouped_tokens;
                break;
            case 9:
                m_line_tokens["FORMAT"] = m_grouped_tokens;
                break;
            default:
                // Collection of samples
                if (m_line_tokens.find("SAMPLES") == m_line_tokens.end()) {
                    m_line_tokens["SAMPLES"] = std::vector<std::string>{};
                }
                // Samples are stored as a single string
                m_line_tokens["SAMPLES"].push_back(m_grouped_tokens[0]);
        }
        m_grouped_tokens = std::vector<std::string>{};
    }

    void StoreParsePolicy::handle_body_line(ParsingState & state)
    {
        size_t position;
        try {
            // Transform the position token into a size_t
            position = static_cast<size_t>(std::stoi(m_line_tokens["POS"][0]));
        } catch (std::invalid_argument ex) {
            throw new PositionBodyError{state.n_lines};
        }

        // Transform all the quality tokens into floating point numbers
        float quality = 0;
        if (m_line_tokens["QUAL"][0] != ".") {
            try {
                quality = std::stof(m_line_tokens["QUAL"][0]);
            } catch (std::invalid_argument ex) {
                throw new QualityBodyError{state.n_lines};
            }
        }

        // Split the info tokens by the equals (=) symbol
        std::map<std::string, std::string> info;
        for (auto & field : m_line_tokens["INFO"]) {
            std::vector<std::string> subfields;
            util::string_split(field, "=", subfields);
            if (subfields.size() > 1) {
                info.emplace(subfields[0], subfields[1]);
            } else {
                info.emplace(subfields[0], "");
            }
        }

        // Format and samples are optional
        auto format = m_line_tokens.find("FORMAT") != m_line_tokens.end() ?
                      m_line_tokens["FORMAT"] : std::vector<std::string>{} ;
        auto samples = m_line_tokens.find("SAMPLES") != m_line_tokens.end() ?
                       m_line_tokens["SAMPLES"] : std::vector<std::string>{} ;
        
        state.add_record(Record {
                state.n_lines,
                m_line_tokens["CHROM"][0],
                position,
                m_line_tokens["ID"],
                m_line_tokens["REF"][0],
                m_line_tokens["ALT"],
                quality,
                m_line_tokens["FILTER"],
                info,
                format,
                samples,
                state.source
        });
    }
    
    std::string StoreParsePolicy::current_token() const
    {
        return m_current_token;
    }

    std::vector<std::string> StoreParsePolicy::column_tokens(std::string const & column) const
    {
        try {
            return m_line_tokens.at(column);
        } catch (std::out_of_range) {
            return {};
        }
    }
    
  }
}
