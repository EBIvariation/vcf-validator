/**
 * Copyright 2014-2017 EMBL - European Bioinformatics Institute
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

#include <util/algo_utils.hpp>
#include "vcf/parsing_state.hpp"

namespace ebi
{
  namespace vcf
  {

    void valida();

    ParsingState::ParsingState(std::shared_ptr<Source> source, AdditionalChecks additionalChecks)
    : n_lines{1}, n_columns{1}, n_batches{0}, cs{0}, m_is_valid{true}, 
      source{source}, record{},
      errors{}, warnings{},
      defined_metadata{},
      additionalChecks{additionalChecks}
    {
    }

    void ParsingState::set_version(Version version)
    {
        source->version = version;
    }
    
    void ParsingState::add_meta(MetaEntry const & meta)
    {
        source->meta_entries.emplace(meta.id, meta);
    }
    
    void ParsingState::set_record(std::unique_ptr<Record> record)
    {
        this->record = std::move(record);
    }

    void ParsingState::add_error(std::unique_ptr<Error> error)
    {
        errors.push_back(std::move(error));
    }

    void ParsingState::add_warning(std::unique_ptr<Error> error)
    {
        warnings.push_back(std::move(error));
    }

    void ParsingState::clear()
    {
        record.reset();
        errors.clear();
        warnings.clear();
    }

    std::vector<std::string> const & ParsingState::samples() const
    {
        return source->samples_names;
    }
        
    void ParsingState::set_samples(std::vector<std::string> & samples)
    {
        source->samples_names = samples;
    }
    
    bool ParsingState::is_well_defined_meta(std::string const & meta_type, std::string const & id) const
    {
        typedef std::multimap<std::string,std::string>::const_iterator iter;
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

    void ParsingState::validate_additional_checks()
    {

        if (additionalChecks.checkEvidence) {
            //Check genotypes
            auto format = record->format;
            if (!format.empty() && util::contains(format, GT)) {
                return;
            }
            //Check allele frequencies
            auto info = record->info;
            for (auto &in : info) {
                if (in.first == vcf::AF) {
                    return;
                }
            }
            throw new InfoBodyError{record->line, "Genotypes or Allele frequencies are required"};
        }
    }

    void valida(){

    }
  }
}
