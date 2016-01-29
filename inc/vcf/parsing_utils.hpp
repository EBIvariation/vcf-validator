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

#ifndef VCF_PARSING_UTILS_HPP
#define	VCF_PARSING_UTILS_HPP

#include <map>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

namespace ebi
{
  namespace vcf
  {
    
    struct ParsingState
    {
        size_t n_lines;
        size_t n_columns;
        size_t n_batches;

        int cs;
        bool m_is_valid;
        
        std::shared_ptr<Source> source;
        std::shared_ptr<std::vector<Record>> records;
     
        std::multimap<std::string, std::string> defined_metadata;
        std::multimap<std::string, std::string> undefined_metadata;
        
        ParsingState(std::shared_ptr<Source> source,
                     std::shared_ptr<std::vector<Record>> records);
        
        void set_version(Version version) const;
        
        void add_meta(MetaEntry const & meta) const;
        
        void add_record(Record const & record) const;
        
        void clear_records() const;
        
        std::vector<std::string> const & samples() const;
        
        void set_samples(std::vector<std::string> & samples) const;
        
        bool is_well_defined_meta(std::string const & meta_type, std::string const & id);
        
        void add_well_defined_meta(std::string const & meta_type, std::string const & id);
	
        bool is_bad_defined_meta(std::string const & meta_type, std::string const & id);
        
        void add_bad_defined_meta(std::string const & meta_type, std::string const & id);
    };

    class ParsingError : public std::runtime_error
    {
        using runtime_error::runtime_error;
    };

    class ParsingWarning : public std::runtime_error
    {
        using runtime_error::runtime_error;
    };

  }
}

#endif	/* VCF_PARSING_UTILS_HPP */

