/**
 * Copyright 2017 EMBL - European Bioinformatics Institute
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

#ifndef VCF_META_ENTRY_VISITOR_HPP
#define VCF_META_ENTRY_VISITOR_HPP

#include <map>
#include <string>

#include <boost/variant/static_visitor.hpp>

#include "file_structure.hpp"

namespace ebi
{
  namespace vcf 
  {
    class MetaEntryVisitor : public boost::static_visitor<>
    {
        MetaEntry entry;

    public:
        MetaEntryVisitor(MetaEntry const & entry);

        void operator()(std::string & value) const;
        void operator()(std::map<std::string, std::string> & value) const;

    private:

        void check_key_is_present(std::string const & field, std::string const & key, int key_count) const;
        void check_alt(std::map<std::string, std::string> & value) const;
        void check_alt_id(std::string const & id_field) const;
        void check_contig(std::map<std::string, std::string> & value) const;
        void check_filter(std::map<std::string, std::string> & value) const;
        void check_filter_id(std::string const & id_field) const;
        void check_format(std::map<std::string, std::string> & value) const;
        void check_format_or_info_number(std::string const & number_field, std::string const & field, bool isinfo) const;
        void check_format_type(std::string const & type_field) const;
        void check_info(std::map<std::string, std::string> & value) const;
        void check_info_type(std::string const & type_field) const;
        void check_predefined_tag(std::string const & tag_field, std::string const & meta_entry_property,
                                  std::map<std::string, std::string> & meta_entry,
                                  std::map<std::string, std::pair<std::string, std::string>> const & predefined_meta_entries) const;
        void check_sample(std::map<std::string, std::string> & value) const;
    };

  }
}

#endif // VCF_META_ENTRY_VISITOR_HPP

