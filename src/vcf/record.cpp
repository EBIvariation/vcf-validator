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
#include <unordered_set>



#include<iostream>

#include "util/logger.hpp"
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
            std::multimap<std::string, std::string> const & info,
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
        for (auto & alternate : alternate_alleles) {
            if (alternate == MISSING_VALUE || alternate == GVCF_NON_VARIANT_ALLELE) {
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
        if (ids.size() == 1 && ids[0] == MISSING_VALUE) {
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
                throw new IdBodyError{line, "ID must not have duplicate values", ErrorFix::DUPLICATE_VALUES};
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
                if (alternate == MISSING_VALUE && alternate_alleles.size() > 1) {
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
            if (!boost::starts_with(alt_id, DEL) && 
                !boost::starts_with(alt_id, INS) && 
                !boost::starts_with(alt_id, DUP) && 
                !boost::starts_with(alt_id, INV) && 
                !boost::starts_with(alt_id, CNV)) {
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
        check_filter_no_duplicates();
        check_filter_not_zero();
    }

    void Record::check_filter_no_duplicates() const
    {
        if (source->version == Version::v43) {
            try {
                check_no_duplicates(filters);
            } catch (const std::invalid_argument &ex) {
                throw new FilterBodyError{line, "FILTER must not have duplicate filters", ErrorFix::DUPLICATE_VALUES};
            }
        }
    }

    void Record::check_filter_not_zero() const
    {
        for (auto & filter : filters) {
            if (filter == "0") {
                throw new FilterBodyError{line, "FILTER string must not be 0 (reserved value)", ErrorFix::IRRECOVERABLE_VALUE, filter};
            }
        }
    }

    void Record::check_info() const
    {
        check_info_no_duplicates();

        typedef std::multimap<std::string, MetaEntry>::iterator iter;
        std::pair<iter, iter> range = source->meta_entries.equal_range(INFO);
        std::vector<std::string> values;

        // Check that INFO fields listed in the meta section
        // match the Number and Type specified in there
        for (auto & field : info) {
            if (field.first == MISSING_VALUE) { continue; } // No need to check missing data

            util::string_split(field.second, ",", values);
            bool found_in_meta = false;
            for (iter current = range.first; current != range.second; ++current) {
                auto & key_values = boost::get<std::map < std::string, std::string >> ((current->second).value);
                if (key_values[ID] == field.first) {
                    found_in_meta = true;
                    try {
                        check_field_cardinality(field.second, values, key_values[NUMBER]);
                        check_field_type(values, key_values[TYPE]);
                    } catch (std::shared_ptr<Error> ex) {
                        std::string message = "INFO " + key_values[ID] + " does not match the meta" + ex->message;
                        throw new InfoBodyError{line, message, key_values[ID] + "=" + field.second,
                                ErrorFix::IRRECOVERABLE_VALUE, key_values[ID]};
                    }

                    break;
                }
            }

            if (!found_in_meta) {
                try {
                    if (source->version == Version::v41 || source->version == Version::v42) {
                        check_predefined_tag(field.first, values, info_v41_v42);
                    } else {
                        check_predefined_tag(field.first, values, info_v43);
                    }
                } catch (std::shared_ptr<Error> ex) {
                    throw new InfoBodyError{line, "INFO " + ex->message, field.first + "=" + field.second, ErrorFix::IRRECOVERABLE_VALUE, field.first};
                }
            }

            strict_validation_info_predefined_tags(field.first, field.second, values);
       }
    }
    
    void Record::check_info_no_duplicates() const
    {
        if (source->version == Version::v43 && info.size() > 1) {
            for (auto & in : info) {
                if (info.count(in.first) > 1) {
                    throw new InfoBodyError{line, "INFO must not have duplicate keys", "", ErrorFix::DUPLICATE_VALUES};
                }
            }
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
        if (std::find(format.begin(), format.end(), GT) != format.end() && format[0] != GT) {
            throw new FormatBodyError{line, "GT must be the first field in the FORMAT column"};
        }
    }

    void Record::check_format_no_duplicates() const
    {
        if (source->version == Version::v43) {
            try {
                check_no_duplicates(format);
            } catch (const std::invalid_argument &ex) {
                throw new FormatBodyError{line, "FORMAT must not have duplicate fields", ErrorFix::DUPLICATE_VALUES};
            }
        }
    }

    void Record::check_predefined_tag(std::string const & field_key, std::vector<std::string> const & values,
                                      std::map<std::string, std::pair<std::string, std::string>> const & tags) const
    {
        auto iterator = tags.find(field_key);
        if (iterator != tags.end()) {
            try {
                if (field_key != GL && field_key != PL && field_key != GP && field_key != CNL && field_key != CNP)
                    check_field_cardinality(field_key, values, iterator->second.second);
                check_field_type(values, iterator->second.first);
            } catch (std::shared_ptr<Error> ex) {
                raise(std::make_shared<Error>(line, field_key + " does not match the" + ex->message));
            }
            if (iterator->second.first == INTEGER) {
                check_field_integer_range(field_key, values);
            }
        }
    }

    void Record::strict_validation_info_predefined_tags(std::string const & field_key, std::string const & field_value,
                                                        std::vector<std::string> const & values) const
    {
        if (field_key == AA) {
            static boost::regex aa_regex("((?![,;=])[[:print:]])+");
            if (!boost::regex_match(field_value, aa_regex)) {
                throw new InfoBodyError{line, "INFO AA value is not a single dot or a string of bases", "AA=" + field_value,
                        ErrorFix::IRRECOVERABLE_VALUE, field_key};
            }
        } else if (field_key == AF) {
            for (auto & value : values) {
                if (std::stold(value) < 0 || std::stold(value) > 1) {
                    throw new InfoBodyError{line, "INFO AF value does not lie in the interval [0,1]", "AA=" + field_value,
                            ErrorFix::IRRECOVERABLE_VALUE, field_key};
                }
            }
        } else if (field_key == CIGAR) {
            static boost::regex cigar_string("([0-9]+[MIDNSHPX])+");
            for (auto & value : values) {
                if (!boost::regex_match(value, cigar_string)) {
                    throw new InfoBodyError{line, "INFO CIGAR value is not an alphanumeric string compliant with the SAM specification",
                            "CIGAR=" + field_value, ErrorFix::IRRECOVERABLE_VALUE, field_key};
                }
            }
        } else if (field_key == END) {
            auto it = info.find(IMPRECISE);
            if (it != info.end() && it->second == "0") {
                auto expected = std::to_string(position + reference_allele.length() - 1);
                if (field_value != expected) {
                    throw new InfoBodyError{line, "INFO END value must be equal to \"POS + length of REF - 1\" for a "
                            "precise variant (where IMPRECISE is set to 0)",
                            "END=" + field_value + ", expected value=" + expected,
                            ErrorFix::RECOVERABLE_VALUE, field_key, expected};
                }
            }
        } else if (field_key == SVLEN && values.size() == alternate_alleles.size()) {
            for (size_t i = 0; i < alternate_alleles.size(); i++) {
                if (check_alt_not_symbolic(i)) {
                    std::string expected = std::to_string(static_cast<long>(alternate_alleles[i].size()) - static_cast<long>(reference_allele.size()));
                    if (values[i] != expected) {
                        throw new InfoBodyError{line, "INFO SVLEN must be equal to \"length of ALT - length of REF\" for "
                                "non-symbolic alternate alleles", "SVLEN=" + field_value + ", expected value=" + expected,
                                ErrorFix::RECOVERABLE_VALUE, field_key, expected};
                    }
                } else {
                    std::string first_field = alternate_alleles[i].substr(0, 4);
                    if (first_field == "<" + INS || first_field == "<" + DUP) {
                        if (std::stoi(values[i]) < 0) {
                            throw new InfoBodyError{line, "INFO SVLEN must be a positive integer for longer ALT alleles", "SVLEN="
                                    + field_value + ", ALT allele=" + first_field.substr(1, 3),
                                    ErrorFix::IRRECOVERABLE_VALUE, field_key};
                        }
                    } else if (first_field == "<" + DEL) {
                        if (std::stoi(values[i]) > 0) {
                            throw new InfoBodyError{line, "INFO SVLEN must be a negative integer for shorter ALT alleles"
                                    + first_field.substr(1,3), "SVLEN=" + field_value + ", ALT allele=" + first_field.substr(1, 3),
                                    ErrorFix::IRRECOVERABLE_VALUE, field_key};
                        }
                    }
                }
            }
        }
    }

    bool Record::check_alt_not_symbolic(size_t allele_index) const
    {
        static boost::regex non_symbolic_alt_regex("[ACGTN]+", boost::regex::icase);
        return boost::regex_match(alternate_alleles[allele_index], non_symbolic_alt_regex);
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
        std::pair<iter, iter> range = source->meta_entries.equal_range(FORMAT);
        std::vector<MetaEntry> format_meta;

        for (auto & fm : format) {
            bool found_in_header = false;
            
            for (iter current = range.first; current != range.second; ++current) {
                auto & key_values = boost::get<std::map<std::string, std::string>>((current->second).value);

                if (key_values[ID] == fm) {
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

    size_t Record::get_ploidy_from_GT(std::string const & sample) const
    {
        if (format[0] == GT) {
            std::string::size_type pos = sample.find(':');
            std::string GT_subfield = sample;
            if (pos != std::string::npos) {
                GT_subfield = sample.substr(0, pos);
            }
            return 1 + count_if(GT_subfield.begin(), GT_subfield.end(), [](char c) { return c == '/' || c == '|'; });
        } else {
            BOOST_LOG_TRIVIAL(error) << "Cannot fetch ploidy from GT as GT is not present in the FORMAT";
            return 0;
        }
    }

    void Record::check_sample(size_t i, std::vector<MetaEntry> const & format_meta) const
    {
        std::vector<std::string> subfields;
        util::string_split(samples[i], ":", subfields);
        
        check_sample_subfields_count(i, subfields);

        // If the first format field is not a GT, then no alleles need to be checked
        if (format[0] == GT) {
            check_sample_alleles(subfields);
        }

        check_sample_subfields_cardinality_type(i, subfields, format_meta);
    }

    void Record::check_sample_subfields_count(size_t i, std::vector<std::string> const & subfields) const
    {
        if (subfields.size() > format.size()) {
            throw new SamplesBodyError{line, "Sample #" + std::to_string(i + 1) +
                    " has more fields than specified in the FORMAT column"};
        }
    }

    void Record::check_sample_subfields_cardinality_type(size_t i, std::vector<std::string> const & subfields,
                                                         std::vector<MetaEntry> const & format_meta) const
    {
        std::vector<std::string> values;

        for (size_t j = 0; j < subfields.size(); ++j) {
            MetaEntry meta = format_meta[j];
            auto & subfield = subfields[j];

            util::string_split(subfield, ",", values);

            if (format[j] == GL || format[j] == PL || format[j] == GP || format[j] == CNL || format[j] == CNP) {
                bool valid;
                long cardinality;
                size_t ploidy;

                try {
                    check_field_cardinality(valid, subfield, values, G, cardinality, ploidy, samples[i]);
                } catch (std::shared_ptr<Error> ex) {
                    long number = valid ? cardinality : -1;
                    std::string detailed_message = ". It must derive its number of values from the ploidy of GT (if present), or "
                                                   "assume a diploidy. Contains " + std::to_string(values.size()) + " value(s), "
                                                   "expected " + std::to_string(cardinality) + " (derived from ploidy " +
                                                   std::to_string(ploidy) + ")";
                    std::string message = "Sample #" + std::to_string(i + 1) + " does not match the meta" + ex->message;
                    throw new SamplesFieldBodyError{line, message, format[j] + "=" + subfield + detailed_message, format[j], number};
                }
            }

            if (meta.id == "") {
                try {
                    if (source->version == Version::v41 || source->version == Version::v42) {
                        check_predefined_tag(format[j], values, format_v41_v42);
                    } else {
                        check_predefined_tag(format[j], values, format_v43);
                    }
                } catch (std::shared_ptr<Error> ex) {
                    throw new SamplesFieldBodyError{line, "Sample #" + std::to_string(i + 1) + ", " + ex->message,
                                                    format[j] + "=" + subfield, format[j]};
                }

                // FORMAT fields not described in the meta section can't be checked

            } else {
                auto & key_values = boost::get<std::map<std::string, std::string>>(meta.value);
                bool valid;
                long cardinality;

                try {
                    if (format[j] != GL && format[j] != PL && format[j] != GP && format[j] != CNL && format[j] != CNP)
                        check_field_cardinality(valid, subfield, values, key_values[NUMBER], cardinality);
                    check_field_type(values, key_values[TYPE]);
                } catch (std::shared_ptr<Error> ex) {
                    long number = valid ? cardinality : -1;
                    std::string message = "Sample #" + std::to_string(i + 1) + " does not match the meta" + ex->message;
                    throw new SamplesFieldBodyError{line, message, key_values[ID] + "=" + subfield, key_values[ID], number};
                }
            }

            strict_validation_format_predefined_tags(i, format[j], subfield, values);
        }
    }

    void Record::strict_validation_format_predefined_tags(size_t i, std::string const & field_key, std::string const & field_value,
                                                          std::vector<std::string> const & values) const
    {
        std::string message = "Sample #" + std::to_string(i + 1) + ", " + field_key + "=" + field_value + " value";
        if (field_key == GP || (field_key == CNP && source->version == Version::v43)) {
            for (auto & value : values) {
                if (std::stold(value) < 0 || std::stold(value) > 1) {
                    throw new SamplesFieldBodyError{line, message + " does not lie in the interval [0,1]", "", field_key};
                }
            }
        }
    }

    void Record::check_sample_alleles(std::vector<std::string> const & subfields) const
    {
        std::vector<std::string> alleles;
        util::string_split(subfields[0], "|/", alleles);
        long ploidy = static_cast<long>(source->ploidy.get_ploidy(chromosome));
        for (auto & allele : alleles) {
            if (allele == "") {
                throw new SamplesFieldBodyError{line, "Allele index must not be empty", "", GT, ploidy};
            }

            if (allele == MISSING_VALUE) { continue; } // No need to check missing alleles

            check_sample_alleles_is_integer(allele, ploidy);

            check_sample_alleles_range(allele, ploidy);
        }
    }

    void Record::check_sample_alleles_is_integer(std::string const & allele, long ploidy) const
    {
        if (std::find_if_not(allele.begin(), allele.end(), isdigit) != allele.end()) {
            throw new SamplesFieldBodyError{line, "Allele must be a non-negative integer number",
                                            "Index=" + allele, GT, ploidy};
        }
    }

    void Record::check_sample_alleles_range(std::string const & allele, long ploidy) const
    {
        size_t num_allele = std::stoi(allele);
        if (num_allele > alternate_alleles.size()) {
            throw new SamplesFieldBodyError{line,
                                            "Allele is greater than the maximum allowed",
                                            "Index=" + std::to_string(num_allele) + ", maximum allowed=" + std::to_string(alternate_alleles.size()),
                                            GT, ploidy};
        }
    }

    void Record::check_no_duplicates(std::vector<std::string> const & values) const
    {
        if (values.size() > 1) {
            std::set<std::string> counter(values.begin(), values.end());
            if (values.size() > counter.size()) {
                throw std::invalid_argument("Duplicate fields");
            }
        }
    }

    bool Record::is_valid_cardinality(std::string const & number, size_t alternate_allele_number, long & cardinality,
                                      size_t ploidy) const
    {
        bool valid = true;

        if (number == A) {
            // ...the number of alternate alleles
            cardinality = alternate_allele_number;
        } else if (number == R) {
            // ...the number of alternate alleles + reference
            cardinality = alternate_allele_number + 1;
        } else if (number == G) {
            // ...the number of possible genotypes
            // The binomial coefficient is calculated considering the ploidy of the sample
            cardinality = boost::math::binomial_coefficient<float>(alternate_alleles.size() + ploidy, ploidy);
        } else if (number == UNKNOWN_CARDINALITY) {
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

    void Record::check_field_cardinality(std::string const & field, std::vector<std::string> const & values,
                                         std::string const & number) const
    {
        bool valid;
        long cardinality;
        size_t ploidy;
        std::string sample;
        check_field_cardinality(valid, field, values, number, cardinality, ploidy, sample);
    }

    void Record::check_field_cardinality(bool & valid, std::string const & field, std::vector<std::string> const & values,
                                         std::string const & number, long & cardinality) const
    {
        size_t ploidy;
        std::string sample;
        check_field_cardinality(valid, field, values, number, cardinality, ploidy, sample);
    }

    void Record::check_field_cardinality(bool & valid, std::string const & field, std::vector<std::string> const & values,
                                         std::string const & number, long & cardinality, size_t & ploidy,
                                         std::string const & sample) const
    {
        ploidy = source->ploidy.get_ploidy(chromosome);
        if (number == G) {
            ploidy = 2;  // diploidy is assumed
            if (format[0] == GT) {
                ploidy = get_ploidy_from_GT(sample);
            }
        }
        valid = is_valid_cardinality(number, alternate_alleles.size(), cardinality, ploidy);
        if (not valid) {
            raise(std::make_shared<Error>(line, field + " meta specification Number=" + number + " is not one of [A, R, G, ., <non-negative number>]"));
        }

        bool number_matches = true;
        if (cardinality > 0) {
            // The number of values must match the expected cardinality
            number_matches = (values.size() == static_cast<size_t>(cardinality));
        } else if (cardinality == 0) {
            // There will be one empty value that needs to be specifically checked
            number_matches = values.size() == 0 || values.size() == 1;
        } else {
            // if number=".", then `cardinality` was set to -1, and it should always match, letting `number_matches` as true
        }

        if (!number_matches) {
            raise(std::make_shared<Error>(line, " specification Number=" + number + " (expected " + std::to_string(cardinality) + " value(s))"));
        }
    }

    void Record::check_value_type(std::string const & type, std::string const & value, std::string & message) const {
        if (type == INTEGER) {
            // ...try to cast to int
            std::stoi(value);
            // ...and also check it's not a float
            if (std::fmod(std::stof(value), 1) != 0) {
                message = " (an integer must not contain decimal digits)";
                throw std::invalid_argument(message);
            }
        } else if (type == FLOAT) {
            // ...try to cast to float
            try {
                std::stof(value);
            } catch (std::out_of_range) {
                // It maybe a subnormal number
                std::stold(value);
            }
        } else if (type == FLAG) {
            int numeric_value = std::stoi(value);
            if (value.size() > 1 || (numeric_value != 0 && numeric_value != 1)) {
                message = " (a flag value must be \"0, 1 or none\")";
                throw std::invalid_argument(message);
            }
            // If no flag is provided then there is nothing to check
        } else if (type == CHARACTER) {
            // ...check the length is 1
            if (value.size() > 1) {
                message = " (there can be only one character)";
                throw std::invalid_argument(message);
            }
        } else if (type == STRING) {
            // ...do nothing, it is guaranteed it will be a string
        }
    }

    void Record::check_field_type(std::vector<std::string> const & values,
                                  std::string const & type) const
    {
        // To check the field type...
        for (auto & value : values) {
            if (value == MISSING_VALUE) { continue; }

            std::string message;
            try {
                check_value_type(type, value, message);
            } catch (const std::exception &typeError) {
                raise(std::make_shared<Error>(line, " specification Type=" + type + message));
            }
        }
    }

    void Record::check_field_integer_range(std::string const & field, std::vector<std::string> const & values) const {
        if (field == SVLEN || field == CIPOS || field == CIEND || field == CILEN || field == CICN || field == CICNADJ) {
            // to ignore predefined tag fields which permit negative integral values
            return;
        }
        for (auto & value : values) {
            if (value == MISSING_VALUE) { continue; }

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

            if (key_values[ID] == field_value) {
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
