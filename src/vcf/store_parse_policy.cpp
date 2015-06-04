#include "validator.hpp"

namespace opencb
{
  namespace vcf
  {

    void StoreParsePolicy::handle_token_begin(ParsingState const & state)
    {
        m_current_token = std::string();
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
        state.set_version(m_current_token);
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
        try {
            if (m_line_typeid == "") { // Plain value
                state.add_meta(MetaEntry{m_grouped_tokens[0]});

            } else if (m_grouped_tokens.size() == 1) { // TypeID=value
                state.add_meta(MetaEntry{m_line_typeid, m_grouped_tokens[0]});

            } else if (m_grouped_tokens.size() % 2 == 0) { // TypeID=<Key-value pairs>
                auto key_values = std::map<std::string, std::string>{};
                for (size_t i = 0; i < m_grouped_tokens.size(); i += 2) {
                    key_values[m_grouped_tokens[i]] = m_grouped_tokens[i+1];
                }
                state.add_meta(MetaEntry{m_line_typeid, key_values});

            } else {
                // TODO Throw exception
            }
        } catch (std::invalid_argument ex) {
            throw ParsingError(ex.what());
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

    void StoreParsePolicy::handle_body_line(ParsingState const & state) 
    {
        try {
            // Transform the position token into a size_t
            auto position = static_cast<size_t>(std::stoi(m_line_tokens["POS"][0]));

            // Transform all the quality tokens into floating point numbers
            float quality;
            try {
                quality = std::stof(m_line_tokens["QUAL"][0]);
            } catch (std::invalid_argument ex) {
                quality = 0;
            }

            // Split the info tokens by the equals (=) symbol
            std::map<std::string, std::string> info;
            for (auto & field : m_line_tokens["INFO"]) {
                std::vector<std::string> subfields;
                boost::split(subfields, field, boost::is_any_of("="));
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
        } catch (std::invalid_argument ex) {
            throw ParsingError(ex.what());
        }
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
