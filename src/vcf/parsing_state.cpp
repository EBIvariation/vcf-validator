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

#include "vcf/parsing_utils.hpp"

namespace ebi
{
  namespace vcf
  {

    ParsingState::ParsingState(
        std::shared_ptr<Source> source,
        std::shared_ptr<std::vector<Record>> records)
    : n_lines{1}, n_columns{1}, n_batches{0}, cs{0}, m_is_valid{true}, 
      source{source}, records{records}, undefined_metadata{}
    {
    }

    void ParsingState::set_version(Version version) const
    {
        source->version = version;
    }
    
    void ParsingState::add_meta(MetaEntry const & meta) const
    {
        source->meta_entries.emplace(meta.id, meta);
    }
    
    void ParsingState::add_record(Record const & record) const
    {
        records->push_back(record);
    }
    
    void ParsingState::clear_records() const
    {
        records->clear();
    }
    
    std::vector<std::string> const & ParsingState::samples() const
    {
        return source->samples_names;
    }
        
    void ParsingState::set_samples(std::vector<std::string> & samples) const
    {
        source->samples_names = samples;
    }
    
    bool ParsingState::is_well_defined_meta(std::string const & meta_type, std::string const & id)
    {
        typedef std::multimap<std::string,std::string>::iterator iter;
        std::pair<iter, iter> range = defined_metadata.equal_range(meta_type);
        for (auto & current = range.first; current != range.second; ++current) {
            if (current->second == id) {
                return true;
            }
        }
        return false;
    }
    
    void ParsingState::add_well_defined_meta(std::string const & meta_type, std::string const & id)
    {
        defined_metadata.emplace(meta_type, id);
    }
    
    bool ParsingState::is_bad_defined_meta(std::string const & meta_type, std::string const & id)
    {
        typedef std::multimap<std::string,std::string>::iterator iter;
        std::pair<iter, iter> range = undefined_metadata.equal_range(meta_type);
        for (auto & current = range.first; current != range.second; ++current) {
            if (current->second == id) {
                return true;
            }
        }
        return false;
    }
    
    void ParsingState::add_bad_defined_meta(std::string const & meta_type, std::string const & id)
    {
        undefined_metadata.emplace(meta_type, id);
    }
  }
}
