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

#include <iostream>

#include "util/algo_utils.hpp"
#include "vcf/error.hpp"
#include "vcf/file_structure.hpp"
#include "vcf/meta_entry_visitor.hpp"

namespace ebi
{
  namespace vcf
  {
  
    MetaEntry::MetaEntry(size_t line,
                         std::string const & id,
                         std::shared_ptr<Source> source)
    : line{line}, id{id}, structure{Structure::NoValue}, source{source}
    {
    }
        
    MetaEntry::MetaEntry(size_t line,
                         std::string const & id,
                         std::string const & plain_value,
                         std::shared_ptr<Source> source)
    : line{line}, id{id}, structure{Structure::PlainValue}, value{plain_value}, source{source}
    {
        check_value();
    }

    MetaEntry::MetaEntry(size_t line,
                         std::string const & id,
                         std::map<std::string, std::string> const & key_values,
                         std::shared_ptr<Source> source)
    : line{line}, id{id}, structure{Structure::KeyValue}, value{key_values}, source{source}
    {
        check_value();
    }
    
    bool MetaEntry::operator==(MetaEntry const & other) const
    {
        return id == other.id &&
               value == other.value;
    }

    bool MetaEntry::operator!=(MetaEntry const & other) const
    {
        return !(*this == other);
    }

    bool MetaEntry::is_defined_in_header() const
    {
        return !this->id.empty();
    }

    void MetaEntry::check_value()
    {
        MetaEntryVisitor visitor = MetaEntryVisitor { *this }; 
        boost::apply_visitor(visitor, value);
    }
     
    
    MetaEntryVisitor::MetaEntryVisitor(MetaEntry const & entry)
    : entry{entry}
    {
        
    }
       
    void MetaEntryVisitor::operator()(std::string & value) const
    {
        if (util::contains_if(value, [](char c) { return c == '\n'; })) {
            throw new MetaSectionError{entry.line, "Metadata value contains a line break"};
        }
    }
    
    void MetaEntryVisitor::operator()(std::map<std::string, std::string> & value) const
    {
        auto & id = entry.id;
        if (id == ALT) {
            check_alt(value);
        } else if (id == ASSEMBLY) {
            // TODO May check URL correctness (regexp?)
        } else if (id == CONTIG) {
            check_contig(value);
        } else if (id == FILTER) {
            check_filter(value);
        } else if (id == FORMAT) {
            check_format(value);
        } else if (id == INFO) {
            check_info(value);
        } else if (id == PEDIGREE) {
            // Nothing to check
        } else if (id == PEDIGREEDB) {
            // Nothing to check
        } else if (id == SAMPLE) {
            check_sample(value);
        }
    }

    inline void MetaEntryVisitor::check_key_is_present(std::string const & field, std::string const & key, int key_count) const
    {
        if (key_count == 0) {
            throw new MetaSectionError{entry.line, field + " metadata does not contain a key called '" + key + "'"};
        }
    }
    
    void MetaEntryVisitor::check_alt(std::map<std::string, std::string> & value) const
    {
        // It must contain an ID and Description
        check_key_is_present(ALT, ID, value.count(ID));
        if (entry.source->version < Version::v44) {     //description optional since v44
            check_key_is_present(ALT, DESCRIPTION, value.count(DESCRIPTION));
        }

        check_alt_id(value[ID]);
    }

    void MetaEntryVisitor::check_alt_id(std::string const & id_field) const
    {
        // Check ID main type (prefix before ':') is one of the predefined ones
        auto main_type_position_end = id_field.find(':');
        bool colon_present = main_type_position_end != std::string::npos;
        if (colon_present) {
            auto main_type = id_field.substr(0, main_type_position_end);
            const std::set<std::string> &validAlt = (entry.source->version < Version::v44) ? PREDEFINED_INFO_SVTYPES : PREDEFINED_INFO_SV_v44;
            if (!ebi::util::contains(validAlt, main_type)) {
                std::stringstream message;
                message << "In ALT metadata IDs containing colon-separated type and subtypes, the top level type "
                            "must be one of: ";
                ebi::util::print_container(message, validAlt, "", ", ", "");
                throw new MetaSectionError{entry.line, message.str(), "Found ID was '" + id_field + "'"};
            }
        }
    }

    void MetaEntryVisitor::check_contig(std::map<std::string, std::string> & value) const
    {
        // It must contain an ID
        check_key_is_present(CONTIG, ID, value.count(ID));
    }
    
    void MetaEntryVisitor::check_filter(std::map<std::string, std::string> & value) const
    {
        // It must contain an ID and Description
        check_key_is_present(FILTER, ID, value.count(ID));
        if (entry.source->version < Version::v44) {     //this is optional v44 onwards
            check_key_is_present(FILTER, DESCRIPTION, value.count(DESCRIPTION));
        }

        check_filter_id(value[ID]);
    }

    void MetaEntryVisitor::check_filter_id(std::string const & id_field) const
    {
        if (id_field == "0") {
            throw new MetaSectionError{entry.line, "FILTER metadata ID must not be 0"};
        }
    }

    void MetaEntryVisitor::check_format(std::map<std::string, std::string> & value) const
    {
        // It must contain an ID, Number, Type and Description
        check_key_is_present(FORMAT, ID, value.count(ID));
        check_key_is_present(FORMAT, NUMBER, value.count(NUMBER));
        check_key_is_present(FORMAT, TYPE, value.count(TYPE));
        check_key_is_present(FORMAT, DESCRIPTION, value.count(DESCRIPTION));
        
        check_format_or_info_number(value[NUMBER], FORMAT, false);
        check_format_type(value[TYPE]);

        if (entry.source->version == Version::v41 || entry.source->version == Version::v42) {
            check_predefined_tag(FORMAT, NUMBER, value, format_v41_v42);
            check_predefined_tag(FORMAT, TYPE, value, format_v41_v42);
        } else if (entry.source->version == Version::v43 ) {
            check_predefined_tag(FORMAT, NUMBER, value, format_v43);
            check_predefined_tag(FORMAT, TYPE, value, format_v43);
        } else {
            check_predefined_tag(FORMAT, NUMBER, value, format_v44);
            check_predefined_tag(FORMAT, TYPE, value, format_v44);
        }
    }

    void MetaEntryVisitor::check_format_or_info_number(std::string const & number_field, std::string const & field, bool isinfo) const
    {
        bool checkP = entry.source->version >= Version::v44;
        if (util::contains_if(number_field, [](char c) { return !isdigit(c); }) &&
            number_field != A &&
            number_field != R &&
            number_field != G &&
            number_field != UNKNOWN_CARDINALITY &&
            (isinfo || !checkP || (number_field != P && !isinfo && checkP))) {
            throw new MetaSectionError{entry.line, field + " metadata Number is not a number, A, R, G" +
                ((!isinfo && checkP) ? ", P" : "") + " or dot"};
        }
    }

    void MetaEntryVisitor::check_format_type(std::string const & type_field) const
    {
        if (type_field != INTEGER &&
            type_field != FLOAT &&
            type_field != CHARACTER &&
            type_field != STRING) {
            throw new MetaSectionError{entry.line, "FORMAT metadata Type is not a Integer, Float, Character or String"};
        }
    }

    void MetaEntryVisitor::check_info(std::map<std::string, std::string> & value) const
    {
        // It must contain an ID, Number, Type and Description
        check_key_is_present(INFO, ID, value.count(ID));
        check_key_is_present(INFO, NUMBER, value.count(NUMBER));
        check_key_is_present(INFO, TYPE, value.count(TYPE));
        check_key_is_present(INFO, DESCRIPTION, value.count(DESCRIPTION));

        check_format_or_info_number(value[NUMBER], INFO, true);
        check_info_type(value[TYPE]);

        if (entry.source->version == Version::v41 || entry.source->version == Version::v42) {
            check_predefined_tag(INFO, NUMBER, value, info_v41_v42);
            check_predefined_tag(INFO, TYPE, value, info_v41_v42);
        } else if (entry.source->version == Version::v43) {
            check_predefined_tag(INFO, NUMBER, value, info_v43);
            check_predefined_tag(INFO, TYPE, value, info_v43);
        } else {
            check_predefined_tag(INFO, NUMBER, value, info_v44);
            check_predefined_tag(INFO, TYPE, value, info_v44);
        }
    }

    void MetaEntryVisitor::check_info_type(std::string const & type_field) const
    {
        if (type_field != INTEGER &&
            type_field != FLOAT &&
            type_field != FLAG &&
            type_field != CHARACTER &&
            type_field != STRING) {
            throw new MetaSectionError{entry.line, "INFO metadata Type is not a Integer, Float, Flag, Character or String"};
        }
    }

    void MetaEntryVisitor::check_predefined_tag(std::string const & tag_field, std::string const & meta_entry_property,
                                                std::map<std::string, std::string> & meta_entry,
                                                std::map<std::string, std::pair<std::string, std::string>> const & predefined_meta_entries) const
    {
        auto iterator = predefined_meta_entries.find(meta_entry[ID]);
        if (iterator != predefined_meta_entries.end()) {
            // Determine the required value of the key based on whether we are checking for Type or Number
            std::string predefined_value = (meta_entry_property == TYPE ? get_predefined_type(iterator)
                                                                        : get_predefined_number(iterator));
            // If the required value is a "." (dot), do nothing
            // Or if the required value does not match the value provided in the vcf file, throw an error
            if (predefined_value != MISSING_VALUE && predefined_value != meta_entry[meta_entry_property]) {
                std::string message = tag_field + " " + meta_entry[ID] + " metadata " + meta_entry_property + " is not " + predefined_value;
                throw new MetaSectionError{entry.line, message, ErrorFix::RECOVERABLE_VALUE, meta_entry_property, predefined_value};
            }
        }
    }

    void MetaEntryVisitor::check_sample(std::map<std::string, std::string> & value) const
    {
        // It must contain an ID
        check_key_is_present(SAMPLE, ID, value.count(ID));
    }
    
  }
}
