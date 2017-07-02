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

#include <functional>
#include "vcf/file_structure.hpp"
#include "vcf/record.hpp"

namespace ebi
{
  namespace vcf
  {

    Record::Record(size_t const line,
            std::string const & chromosome,
            size_t const position,
            std::vector<std::string> const & ids,
            std::string const & reference_allele,
            std::vector<std::string> const & alternate_alleles,
            float const quality,
            std::vector<std::string> const & filters,
            std::map<std::string, std::string> const & info,
            std::vector<std::string> const & format,
            std::vector<std::string> const & samples,
            std::shared_ptr<Source> source)
    : line(line),
        chromosome{chromosome},
        position{position},
        ids{ids},
        reference_allele{reference_allele}, 
        alternate_alleles{alternate_alleles}, 
        types{},
        quality{quality}, 
        filters{filters}, 
        info{info}, 
        format{format}, 
        samples{samples},
        source{source}
    {
        set_types();
        check_chromosome();
        check_ids();
        check_alternate_alleles();
        check_quality();
        check_filter();
        check_info();
        check_format();
        check_samples();
    }

    bool Record::operator==(Record const & other) const
    {
        return chromosome == other.chromosome &&
                position == other.position &&
                ids == other.ids &&
                reference_allele == other.reference_allele &&
                alternate_alleles == other.alternate_alleles &&
                quality == other.quality &&
                filters == other.filters &&
                info == other.info &&
                format == other.format &&
                samples == other.samples;
    }

    bool Record::operator!=(Record const & other) const
    {
        return !(*this == other);
    }

    void Record::set_types()
    {
        for (std::vector<std::string>::iterator it = alternate_alleles.begin(); it != alternate_alleles.end(); ++it) {
            auto & alternate = *it;
            if (alternate == ".") {
                types.push_back(RecordType::NO_VARIATION);
            } else if (alternate[0] == '<') {
                types.push_back(RecordType::STRUCTURAL);
            } else if (std::count(alternate.begin(), alternate.end(), '[') == 2 || 
                   std::count(alternate.begin(), alternate.end(), ']') == 2) { 
                types.push_back(RecordType::STRUCTURAL_BREAKEND);
            } else if (alternate.size() != reference_allele.size()) {
                types.push_back(RecordType::INDEL);
            } else {
                types.push_back(alternate.size() == 1 ? RecordType::SNV : RecordType::MNV);
            }
        }
    }
    
    void Record::check_chromosome() const
    {
        check_chromosome_no_colons();
        check_chromosome_no_whitespaces();
    }

    void Record::check_chromosome_no_colons() const
    {
        if (chromosome.find(':') != std::string::npos) {
            throw new ChromosomeBodyError{line, "Chromosome must not contain colons"};
        }
    }

    void Record::check_chromosome_no_whitespaces() const
    {
        if (chromosome.find(' ') != std::string::npos) {
            throw new ChromosomeBodyError{line, "Chromosome must not contain white-spaces"};
        }
    }

    void Record::check_ids() const
    {
        if (ids.size() == 1 && ids[0] == ".") {
            return; // No need to check if no IDs are provided
        }
        
        check_ids_no_semicolons_whitespaces();
        check_ids_no_duplicates();
    }

    void Record::check_ids_no_semicolons_whitespaces() const
    {
        for (auto & id : ids) {
            if (std::find_if(id.begin(), id.end(), [](char c) { return c == ' ' || c == ';'; }) != id.end()) {
                throw new IdBodyError{line, "ID must not contain semicolons or whitespaces"};
            }
        }
    }

    void Record::check_ids_no_duplicates() const
    {
        if (source->version == Version::v43) {
            try {
                check_no_duplicates(ids);
            } catch (const std::invalid_argument &ex) {
                throw new IdBodyError{line, "ID" + std::string(ex.what()) + "values"};
            }
        }
    }

    void Record::check_alternate_alleles() const
    {        
        for (size_t i = 0 ; i < alternate_alleles.size(); ++i) {
            auto & alternate = alternate_alleles[i];
            auto & type = types[i];
            
            check_alternate_allele_structure(alternate, type);
            check_alternate_allele_symbolic_prefix(alternate);
        }
        
    }
    
    void Record::check_alternate_allele_structure(std::string const & alternate, RecordType type) const
    {
        switch (type) {
            case RecordType::NO_VARIATION:
                if (alternate_alleles.size() > 1) {
                    throw new AlternateAllelesBodyError{line,
                            "The no-alternate alleles symbol (dot) can not be combined with others"};
                }
                break;
            case RecordType::SNV:
            case RecordType::MNV:
                if (alternate == reference_allele) {
                    throw new AlternateAllelesBodyError{line, "Reference and alternate alleles must not be the same"};
                }
            case RecordType::INDEL:
                // Nothing to check
                break;
            case RecordType::STRUCTURAL:
            case RecordType::STRUCTURAL_BREAKEND:
                // Custom ALTs (STRUCTURAL) and break-ends (STRUCTURAL_BREAKEND) can't be checked against the reference
                break;
        }
        
    }
    
    void Record::check_alternate_allele_symbolic_prefix(std::string const & alternate) const
    {
        static boost::regex square_brackets_regex("<([a-zA-Z0-9:_]+)>");
        boost::cmatch pieces_match;

        if (alternate[0] == '<' && boost::regex_match(alternate.c_str(), pieces_match, square_brackets_regex)) {
            std::string alt_id = pieces_match[1];
            if (!boost::starts_with(alt_id, "DEL") && 
                !boost::starts_with(alt_id, "INS") && 
                !boost::starts_with(alt_id, "DUP") && 
                !boost::starts_with(alt_id, "INV") && 
                !boost::starts_with(alt_id, "CNV")) {
                throw new AlternateAllelesBodyError{line,
                        "Alternate ID is not prefixed by DEL/INS/DUP/INV/CNV and suffixed by ':' and a text sequence"};
            }
        }
    }
    void Record::check_quality() const
    {
        if (quality < 0) {
            throw new QualityBodyError{line, "Quality is not equal or greater than zero"};
        }
    }
    
    void Record::check_filter() const
    {
    }

    void Record::check_info() const
    {
        typedef std::multimap<std::string, MetaEntry>::iterator iter;
        std::pair<iter, iter> range = source->meta_entries.equal_range("INFO");
        std::vector<std::string> values;

        // Check that INFO fields listed in the meta section
        // match the Number and Type specified in there
        for (auto & field : info) {
            if (field.first == ".") { continue; } // No need to check missing data

            util::string_split(field.second, ",", values);
            bool found_in_meta = false;
            for (iter current = range.first; current != range.second; ++current) {
                auto & key_values = boost::get<std::map < std::string, std::string >> ((current->second).value);
                if (key_values["ID"] == field.first) {
                    found_in_meta = true;
                    try {
                        check_field_cardinality(field.second, values, key_values["Number"]);
                        check_field_type(values, key_values["Type"]);
                    } catch (std::shared_ptr<Error> ex) {
                        std::string message = "INFO " + key_values["ID"] + "=" + field.second
                                + " does not match the meta" + ex->message;
                        throw new InfoBodyError{line, message, key_values["ID"]};
                    }
                    
                    break;
                }
            }
            
            if (!found_in_meta) {
                try {
                    if (source->version == Version::v41 || source->version == Version::v42) {
                        check_predefined_tag(field.first, field.second, values, info_v41_v42);
                    } else {
                        check_predefined_tag(field.first, field.second, values, info_v43);
                    }
                } catch (std::shared_ptr<Error> ex) {
                    throw new InfoBodyError{line, "INFO " + ex->message, field.first};
                }
            }

            strict_validation_info_predefined_tags(field.first, field.second);
       }
    }
    
    void Record::check_format() const
    {
        if (format.size() == 0) {
            return; // Nothing to check
        }
        
        check_format_GT();
        check_format_no_duplicates();
    }

    void Record::check_format_GT() const
    {
        if (std::find(format.begin(), format.end(), "GT") != format.end() && format[0] != "GT") {
            throw new FormatBodyError{line, "GT must be the first field in the FORMAT column"};
        }
    }

    void Record::check_format_no_duplicates() const
    {
        if (source->version == Version::v43) {
            try {
                check_no_duplicates(format);
            } catch (const std::invalid_argument &ex) {
                throw new FormatBodyError{line, "FORMAT" + std::string(ex.what()) + "fields"};
            }
        }
    }

    void Record::check_predefined_tag(std::string const & field_key, std::string const & field_value, std::vector<std::string> const & values,
                                      std::map<std::string, std::pair<std::string, std::string>> const & tags) const
    {
        auto iterator = tags.find(field_key);
        if (iterator != tags.end()) {
            try {
                check_field_cardinality(field_key, values, iterator->second.second);
                check_field_type(values, iterator->second.first);
            } catch (std::shared_ptr<Error> ex) {
                raise(std::make_shared<Error>(line, field_key + "=" + field_value
                                + " does not match the" + ex->message));
            }
            if (iterator->second.first == "Integer") {
                check_field_integer_range(field_key, values);
            }
        }
    }

    void Record::strict_validation_info_predefined_tags(std::string const & field_key, std::string const & field_value) const
    {
        if (field_key == "AA") {
            static boost::regex aa_regex("((?![,;=])[[:print:]])+");
            if (!boost::regex_match(field_value, aa_regex)) {
                throw new InfoBodyError{line, "INFO AA=" + field_value + " value is not a single dot or a string of bases", field_key};
            }
        } else if (field_key == "AF") {
            std::vector<std::string> values;
            util::string_split(field_value, ",", values);
            for (auto & value : values) {
                if (std::stold(value) < 0 || std::stold(value) > 1) {
                    throw new InfoBodyError{line, "INFO AF=" + field_value + " value does not lie in the interval [0,1]", field_key};
                }
            }
        } else if (field_key == "CIGAR") {
            std::vector<std::string> values;
            util::string_split(field_value, ",", values);
            static boost::regex cigar_string("([0-9]+[MIDNSHPX])+");
            for (auto & value : values) {
                if (!boost::regex_match(value, cigar_string)) {
                    throw new InfoBodyError{line, "INFO CIGAR=" + field_value + " value is not an alphanumeric string compliant with the SAM specification", field_key};
                }
            }
        }
    }

    void Record::check_samples() const
    {
        check_samples_count();
        
        if (samples.size() == 0) {
            return; // Nothing to check if no samples are listed in the file
        }
        
        std::vector<MetaEntry> format_meta = get_meta_entry_objects();

        for (size_t i = 0; i < samples.size(); ++i) {
            check_sample(i, format_meta);
        }
    }
    
    void Record::check_samples_count() const
    {
        if (samples.size() != source->samples_names.size()) {
            throw new SamplesBodyError{line, "The number of samples must match those listed in the header line"};
        }
    }

    std::vector<MetaEntry> Record::get_meta_entry_objects() const
    {
        typedef std::multimap<std::string, MetaEntry>::iterator iter;
        std::pair<iter, iter> range = source->meta_entries.equal_range("FORMAT");
        std::vector<MetaEntry> format_meta;

        for (auto & fm : format) {
            bool found_in_header = false;
            
            for (iter current = range.first; current != range.second; ++current) {
                auto & key_values = boost::get<std::map < std::string, std::string>>((current->second).value);

                if (key_values["ID"] == fm) {
                    format_meta.push_back(current->second);
                    found_in_header = true;
                    break;
                }
            }
            
            if (!found_in_header) {
                // If not found in header, a null-value meta entry must be created to make sizes match
                format_meta.push_back(MetaEntry{line, "", source});
            }
        }

        return format_meta;
    }

    void Record::check_sample(size_t i, std::vector<MetaEntry> const & format_meta) const
    {
        std::vector<std::string> subfields;
        util::string_split(samples[i], ":", subfields);
        
        check_sample_subfields_count(i, subfields);
        
        // If the first format field is not a GT, then no alleles need to be checked
        if (format[0] == "GT") {
            check_sample_alleles(subfields);
        }        
        
        check_sample_subfields_cardinality_type(i, subfields, format_meta);
    }

    void Record::check_sample_subfields_count(size_t i, std::vector<std::string> const & subfields) const
    {
        if (subfields.size() > format.size()) {
            throw new SamplesBodyError{line, "Sample #" + std::to_string(i+1) +
                    " has more fields than specified in the FORMAT column"};
        }
    }

    void Record::check_sample_subfields_cardinality_type(size_t i, std::vector<std::string> const & subfields, std::vector<MetaEntry> const & format_meta) const
    {
        for (size_t j = 0; j < subfields.size(); ++j) {
            MetaEntry meta = format_meta[j];
            auto & subfield = subfields[j];
            
            if (meta.id == "") {
                // FORMAT fields not described in the meta section can't be checked
                continue;
            }
            
            auto & key_values = boost::get<std::map < std::string, std::string>>(meta.value);

            std::vector<std::string> values;
            util::string_split(subfield, ",", values);

            try {
                check_field_cardinality(subfield, values, key_values["Number"]);
                check_field_type(values, key_values["Type"]);
            } catch (std::shared_ptr<Error> ex) {
                long cardinality;
                bool valid = is_valid_cardinality(key_values["Number"], alternate_alleles.size(), cardinality);
                long number = valid ? cardinality : -1;
 
                std::string message = "Sample #" + std::to_string(i + 1) + ", " + key_values["ID"] + "=" + subfield
                        + " does not match the meta" + ex->message;
                throw new SamplesFieldBodyError{line, message, key_values["ID"], number};
            }
        }
    }

    void Record::check_sample_alleles(std::vector<std::string> const & subfields) const
    {
        std::vector<std::string> alleles;
        util::string_split(subfields[0], "|/", alleles);
        long ploidy = static_cast<long>(source->ploidy.get_ploidy(chromosome));
        for (auto & allele : alleles) {
            if (allele == ".") { continue; } // No need to check missing alleles

            check_sample_alleles_is_integer(allele, ploidy);

            check_sample_alleles_range(allele, ploidy);
        }
    }

    void Record::check_sample_alleles_is_integer(std::string const & allele, long ploidy) const
    {
        if (std::find_if_not(allele.begin(), allele.end(), isdigit) != allele.end()) {
            throw new SamplesFieldBodyError{line, "Allele index " + allele + " is not an integer number",
                                            "GT", ploidy};
        }        
    }

    void Record::check_sample_alleles_range(std::string const & allele, long ploidy) const
    {
        size_t num_allele = std::stoi(allele);
        if (num_allele > alternate_alleles.size()) {
            throw new SamplesFieldBodyError{line,
                                            "Allele index " + std::to_string(num_allele)
                                                    + " is greater than the maximum allowed "
                                                    + std::to_string(alternate_alleles.size()),
                                            "GT", ploidy};
        }
    }

    void Record::check_no_duplicates(std::vector<std::string> const & values) const
    {
        if (values.size() > 1) {
            std::map<std::string, int> counter;
            for (auto & value : values) {
                counter[value]++;
                if (counter[value] >= 2) {
                    throw std::invalid_argument(" must not have duplicate ");
                }
            }
        }
    }

    bool Record::is_valid_cardinality(std::string const & number, size_t alternate_allele_number, long & cardinality) const
    {
        bool valid = true;
        size_t ploidy = source->ploidy.get_ploidy(chromosome);

        if (number == "A") {
            // ...the number of alternate alleles
            cardinality = alternate_allele_number;
        } else if (number == "R") {
            // ...the number of alternate alleles + reference
            cardinality = alternate_allele_number + 1;
        } else if (number == "G") {
            // ...the number of possible genotypes
            // The binomial coefficient is calculated considering the ploidy of the sample
            cardinality = boost::math::binomial_coefficient<float>(alternate_allele_number + ploidy, ploidy);
        } else if (number == ".") {
            // ...it is unspecified
            cardinality = -1;
        } else {
            // ...specified as a number in range [0, +MAX_LONG)
            try {
                cardinality = stoi(number);
                if (cardinality < 0) {
                    valid = false;
                }
            } catch (...) {
                valid = false;
            }
        }
        return valid;
    }

    void Record::check_field_cardinality(std::string const & field,
                                         std::vector<std::string> const & values,
                                         std::string const & number) const
    {
        long expected;
        if(not is_valid_cardinality(number, alternate_alleles.size(), expected)) {
            raise(std::make_shared<Error>(line, field + " meta specification Number=" + number + " is not one of [A, R, G, ., <non-negative number>]"));
        }

        bool number_matches = true;
        if (expected > 0) {
            // The number of values must match the expected
            number_matches = (values.size() == static_cast<size_t>(expected));
        } else if (expected == 0) {
            // There will be one empty value that needs to be specifically checked
            number_matches = values.size() == 0 || values.size() == 1;
        } else {
            // if number=".", then `expected` was set to -1, and it should always match, letting `number_matches` as true
        }

        if (!number_matches) {
            raise(std::make_shared<Error>(line, " specification Number=" + number + " (contains " + std::to_string(values.size()) + " values, expected " + std::to_string(expected) + ")"));
        }
    }

    void Record::check_value_type(std::string const & type, std::string const & value, std::string & message) const {
        if (type == "Integer") {
            // ...try to cast to int
            std::stoi(value);
            // ...and also check it's not a float
            if (std::fmod(std::stof(value), 1) != 0) {
                message = " (an integer must not contain decimal digits)";
                throw std::invalid_argument(message);
            }
        } else if (type == "Float") {
            // ...try to cast to float
            try {
                std::stof(value);
            } catch (std::out_of_range) {
                // It maybe a subnormal number
                std::stold(value);
            }
        } else if (type == "Flag") {
            int numeric_value = std::stoi(value);
            if (numeric_value != 0 && numeric_value != 1) {
                message = " (a flag value must be \"0, 1 or none\")";
                throw std::invalid_argument(message);
            }
            // If no flag is provided then there is nothing to check
        } else if (type == "Character") {
            // ...check the length is 1
            if (value.size() > 1) {
                message = " (there can be only one character)";
                throw std::invalid_argument(message);
            }
        } else if (type == "String") {
            // ...do nothing, it is guaranteed it will be a string
        }
    }

    void Record::check_field_type(std::vector<std::string> const & values,
                                  std::string const & type) const
    {
        // To check the field type...
        for (auto & value : values) {
            if (value == ".") { continue; }

            std::string message;
            try {
                check_value_type(type, value, message);
            } catch (const std::exception &typeError) {
                raise(std::make_shared<Error>(line, " specification Type=" + type + message));
            }
        }
    }

    void Record::check_field_integer_range(std::string const & field, std::vector<std::string> const & values) const {
        for (auto & value : values) {
            if (value == ".") { continue; }

            if (std::stoi(value) < 0) {
                raise(std::make_shared<Error>(line, field + " value must be a non-negative integer number"));
            }
        }
    }

    bool is_record_subfield_in_header(std::string const & field_value,
                                      std::multimap<std::string, MetaEntry>::iterator begin,
                                      std::multimap<std::string, MetaEntry>::iterator end)
    {
        for (std::multimap<std::string, MetaEntry>::iterator current = begin; current != end; ++current) {
            auto & key_values = boost::get<std::map < std::string, std::string >> ((current->second).value);

            if (key_values["ID"] == field_value) {
                return true;
            }
        }
        
        return false;
    }
    
    std::ostream &operator<<(std::ostream &os, const Record &record)
    {
        using util::operator<<;
        os << "{";
        os << record.line << ", " << record.chromosome << ", " << record.position << ", ";
        os << record.ids << ", " << record.reference_allele << ", " << record.alternate_alleles;
        
        os << ", [";
        if (record.types.size() > 0) {
            auto type_it = record.types.begin();
            os << static_cast<int>(*type_it);
            type_it++;
            for (; type_it != record.types.end(); ++type_it) {
                os << ", " << static_cast<int>(*type_it);
            }
        }
        os << "]";
        
        os << ", " << record.quality;
        os << ", " << record.filters;
        os << ", " << record.info;
        os << ", " << record.format;
        os << ", " << record.samples;
        
        os << "}";
        return os;
    }

  }
}
