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
#include "file_structure.hpp"
#include "error.hpp"
#include "normalizer.hpp"

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
        std::unique_ptr<Record> record;
        std::vector<std::unique_ptr<Error>> errors;
        std::vector<std::unique_ptr<Error>> warnings;

        std::multimap<std::string, std::string> defined_metadata;
        std::multimap<std::string, std::string> undefined_metadata;
        
        ParsingState(std::shared_ptr<Source> source);
        
        void set_version(Version version);
        
        void add_meta(MetaEntry const & meta);

        void set_record(std::unique_ptr<Record> record);
        void unset_record();

        void add_error(std::unique_ptr<Error> error);
        void clear_errors();

        void add_warning(std::unique_ptr<Error> error);
        void clear_warnings();
        
        std::vector<std::string> const & samples() const;
        
        void set_samples(std::vector<std::string> & samples);
        
        bool is_well_defined_meta(std::string const & meta_type, std::string const & id) const;
        
        void add_well_defined_meta(std::string const & meta_type, std::string const & id);
        
        bool is_bad_defined_meta(std::string const & meta_type, std::string const & id) const;
        
        void add_bad_defined_meta(std::string const & meta_type, std::string const & id);
    };
  }
}

#endif	/* VCF_PARSING_UTILS_HPP */

