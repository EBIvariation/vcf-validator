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
#include <iostream>

#include "util/algo_utils.hpp"
#include "util/stream_utils.hpp"
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
        check_chromosome_no_whitespaces();
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
            if (util::contains_if(id, [](char c) { return c == ' ' || c == ';'; })) {
                throw new IdBodyError{line, "ID must not contain semicolons or whitespaces"};
            }
        }
    }

    void Record::check_ids_no_duplicates() const
    {
        if (source->version == Version::v43 || source->version == Version::v44) {
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
        static boost::regex angle_brackets_regex("<([^>]+)>");
        boost::cmatch pieces_match;

        if (alternate[0] == '<' && boost::regex_match(alternate.c_str(), pieces_match, angle_brackets_regex)) {
            std::string alt_id = pieces_match[1];
            // Check ID prefix is "DEL" | "INS" | "DUP" | "INV" | "CNV"
            auto main_type_position_end = alt_id.find(':');
            bool colon_present = main_type_position_end != std::string::npos;
            if (colon_present) {
                const std::set<std::string> &validAlt = (source->version < Version::v44) ? PREDEFINED_INFO_SVTYPES : PREDEFINED_INFO_SV_v44;
                auto main_type = alt_id.substr(0, main_type_position_end);
                if (!ebi::util::contains(validAlt, main_type)) {
                    std::stringstream message;
                    message << "In ALT metadata IDs containing colon-separated type and subtypes, the top level type "
                               "must be one of: ";
                    ebi::util::print_container(message, validAlt, "", ", ", "");
                    throw new AlternateAllelesBodyError{line, message.str(), "Found ID was '" + alt_id + "'"};
                }
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
        if (source->version == Version::v43 || source->version == Version::v44) {
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
        check_info_have_mandatory();

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
                        check_info_field_cardinality(values, key_values[NUMBER]);
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
                        check_predefined_tag_info(field.first, values, info_v41_v42);
                    } else if (source->version == Version::v43) {
                        check_predefined_tag_info(field.first, values, info_v43);
                    } else {
                        check_predefined_tag_info(field.first, values, info_v44);
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
        if ((source->version == Version::v43 || source->version == Version::v44) && info.size() > 1) {
            for (auto & in : info) {
                if (info.count(in.first) > 1) {
                    throw new InfoBodyError{line, "INFO must not have duplicate keys", "", ErrorFix::DUPLICATE_VALUES};
                }
            }
        }
    }

    void Record::check_info_have_mandatory() const
    {
        static boost::regex deldup_regex("(<(DUP|DEL)(:[^>]+)*>)+");
        static boost::regex cnvtr_regex("(<CNV:TR>)");
        bool svlencheck = false;
        bool svclaimcheck = false;
        bool cnvtrcheck = false;

        if (source->version < Version::v44) {              //not applicable for 4.1/2/3
            return;
        }
        for (size_t i = 0; i < alternate_alleles.size(); ++i ) {
            //SVLEN must be present for symbolic SV
            auto & alternate = alternate_alleles[i];
            if (types[i] == RecordType::STRUCTURAL) {
                if (!svlencheck && info.find(SVLEN) == info.end()) {
                    std::stringstream message;
                    message << "INFO " << SVLEN << " must be present for symbolic structural variants";
                    throw new InfoBodyError{line, message.str()};
                }
                svlencheck = true;

                if (!svclaimcheck && boost::regex_match(alternate, deldup_regex)) {
                    //del/dup tags must have svclaim
                    if (info.find(SVCLAIM) == info.end()) {
                        std::stringstream message;
                        message << "INFO " << SVCLAIM << " must be present for DEL/DUP";
                        throw new InfoBodyError{line, message.str()};
                    }
                    svclaimcheck = true;
                }
                if (!cnvtrcheck && boost::regex_match(alternate, cnvtr_regex)) {
                    //cnv:tr must have either RUS/RUL
                    if (info.find(RUS) == info.end() && info.find(RUL) == info.end()) {
                        std::stringstream message;
                        message << "INFO " << RUS << " or " << RUL << " must be present for CNV:TR";
                        throw new InfoBodyError{line, message.str()};
                    }
                    cnvtrcheck = true;
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
        if (util::contains(format, GT) && format[0] != GT) {
            throw new FormatBodyError{line, "GT must be the first field in the FORMAT column"};
        }
    }

    void Record::check_format_no_duplicates() const
    {
        if (source->version == Version::v43 || source->version == Version::v44) {
            try {
                check_no_duplicates(format);
            } catch (const std::invalid_argument &ex) {
                throw new FormatBodyError{line, "FORMAT must not have duplicate fields", ErrorFix::DUPLICATE_VALUES};
            }
        }
    }

    void Record::check_predefined_tag_info(std::string const & field_key, std::vector<std::string> const & values,
                                           std::map<std::string, std::pair<std::string, std::string>> const & tags
                                          ) const
    {
        auto iterator = tags.find(field_key);
        if (iterator != tags.end()) {
            try {
                check_info_field_cardinality(values, get_predefined_number(iterator));
                check_field_type(values, get_predefined_type(iterator));
            } catch (std::shared_ptr<Error> ex) {
                raise(std::make_shared<Error>(line, field_key + " does not match the" + ex->message));
            }
            if (get_predefined_type(iterator) == INTEGER) {
                check_field_integer_range(field_key, values);
            }
        }
    }

    void Record::check_predefined_tag_format(std::string const &field_key, std::vector<std::string> const &values,
                                             std::map<std::string, std::pair<std::string, std::string>> const &tags,
                                             size_t ploidy) const
    {
        auto iterator = tags.find(field_key);
        if (iterator != tags.end()) {
            try {
                long cardinality;
                check_sample_field_cardinality(values, get_predefined_number(iterator), ploidy, cardinality);
                check_field_type(values, get_predefined_type(iterator));
            } catch (std::shared_ptr<Error> ex) {
                raise(std::make_shared<Error>(line, field_key + " does not match the" + ex->message,
                                              ex->detailed_message));
            }
            if (get_predefined_type(iterator) == INTEGER) {
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
        } else if (field_key == SVLEN) {
            if (source->version >= Version::v44) {
               return;         //nothing to do as val can be +/- ve and abs val is in use
            }
            if (values.size() != alternate_alleles.size()) {    //has unknown cardinality, not matching to allele count - nothing to do
                return;
            }
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
                        size_t scanned_value_length;
                        int value = std::stoi(values[i], &scanned_value_length);
                        if (value < 0 || scanned_value_length != values[i].size()) {
                            throw new InfoBodyError{line, "INFO SVLEN must be a positive integer for longer ALT alleles", "SVLEN="
                                    + field_value + ", ALT allele=" + first_field.substr(1, 3),
                                    ErrorFix::IRRECOVERABLE_VALUE, field_key};
                        }
                    } else if (first_field == "<" + DEL) {
                        size_t scanned_value_length;
                        int value = std::stoi(values[i], &scanned_value_length);
                        if (value > 0 || scanned_value_length != values[i].size()) {
                            throw new InfoBodyError{line, "INFO SVLEN must be a negative integer for shorter ALT alleles "
                                    + first_field.substr(1,3), "SVLEN=" + field_value + ", ALT allele=" + first_field.substr(1, 3),
                                    ErrorFix::IRRECOVERABLE_VALUE, field_key};
                        }
                    }
                }
            }
        } else if (field_key == SVTYPE) {
            if (!ebi::util::contains(PREDEFINED_INFO_SVTYPES, field_value)) {
                std::stringstream message;
                message << "INFO " << SVTYPE << " must be one of: ";
                ebi::util::print_container(message, PREDEFINED_INFO_SVTYPES, "", ", ", "");
                throw new InfoBodyError{line, message.str(), "Found " + SVTYPE + " was '" + field_value + "'"};
            }
        } else if (field_key == SVCLAIM) {
            if (source->version < Version::v44) {   //not applicable for anything < v4.4
                return;
            }
            static boost::regex allele_regex("<(DUP|DEL|INS|INV|CNV)(:[^>]+)*>");
            boost::cmatch pieces_match;

            //number is A and will have matching number of entries as alleles
            for (size_t i = 0; i < alternate_alleles.size(); ++i) {
                std::string key = _OTHER;
                auto & allele = alternate_alleles[i];
                if (types[i] == RecordType::STRUCTURAL) {
                    if (boost::regex_match(allele.c_str(), pieces_match, allele_regex)) {
                        key = pieces_match[1];      //one of the tokens from allele_regex
                    }
                } else if (types[i] == RecordType::STRUCTURAL_BREAKEND) {
                    key = _BRKEND;
                } else {
                    //others should have '.', checked at optional checks
                    continue;
                }
                const auto & iter = PREDEFINED_INFO_ALLELE_SVCLAIM.find(key);
                if (iter != PREDEFINED_INFO_ALLELE_SVCLAIM.end()) {
                    auto & validvals = iter->second;
                    if (!ebi::util::contains(validvals, values[i])) {
                        std::stringstream message;
                        message << "INFO " << SVCLAIM << " for allele " << alternate_alleles[i] << " must be one of: ";
                        ebi::util::print_container(message, validvals, "", ", ", "");
                        throw new InfoBodyError{line, message.str(), "Found " + SVCLAIM + " was '" + values[i] + "'"};
                    }
                }
                else {
                    BOOST_LOG_TRIVIAL(error) << "Invalid symbolic allele" << key << std::endl;
                }
            }
        } else if (field_key == RUS) {  //repeat unit sequence
            if (source->version < Version::v44) {   //not applicable for anything < v4.4
                return;
            }
            int rnCount = getRNvalue();             //get repeat no, it must match to RUS count
            if (rnCount != values.size()) {
                std::stringstream message;
                message << "INFO " << RUS << " for record at " << line << " must have " << rnCount << " value(s)";
                throw new InfoBodyError{line, message.str(), "Found " + std::to_string(values.size()) + " value(s)"};
            }
            //RUL - RUS matching check made below with RUL
        } else if (field_key == RUL) {    //repeat unit length
            if (source->version < Version::v44) {                       //not applicable for anything < v4.4
                return;
            }
            int rnCount = getRNvalue();                                 //get repeat no, it must match to RUL count
            if (rnCount != values.size()) {
                std::stringstream message;
                message << "INFO " << RUL << " for record at " << line << " must have " << rnCount << " value(s)";
                throw new InfoBodyError{line, message.str(), "Found " + std::to_string(values.size()) + " value(s)"};
            }
            auto itRUS = info.find(RUS);
            if (itRUS != info.end() && itRUS->second != MISSING_VALUE) {    //both RUL and RUS present, must match in count
                std::vector<std::string> RUSval;
                util::string_split(itRUS->second, ",", RUSval);
                if (values.size() != RUSval.size()) {
                    std::stringstream message;
                    message << "INFO " << RUL << " and " << RUS << " for record at " << line << " count must match";
                    throw new InfoBodyError{line, message.str(), "Found " + std::to_string(values.size()) + " and " +
                     std::to_string(RUSval.size()) + " value(s)"};
                }
                for (int i = 0; i < values.size(); ++i) {
                    if (std::stoi(values[i]) != RUSval[i].length()) {       //must match to RUS length
                        std::stringstream message;
                        message << "INFO " << RUL << " not matching to " << RUS << " for record at " << line;
                    throw new InfoBodyError{line, message.str(), "Found length " + values[i] + " for " + RUSval[i]};
                    }
                }
            }
        } else if (field_key == RUC) {    //repeat unit count
            if (source->version < Version::v44) {   //not applicable for anything < v4.4
                return;
            }
            int rnCount = getRNvalue();                                 //get repeat no, it must match to RUC count
            if (rnCount != values.size()) {
                std::stringstream message;
                message << "INFO " << RUC << " for record at " << line << " must have " << rnCount << " value(s)";
                throw new InfoBodyError{line, message.str(), "Found " + std::to_string(values.size()) + " value(s)"};
            }
        } else if (field_key == RB) {     //repeat bases
            if (source->version < Version::v44) {   //not applicable for anything < v4.4
                return;
            }
            int rnCount = getRNvalue();                                 //get repeat no, it must match to RB count
            if (rnCount != values.size()) {
                std::stringstream message;
                message << "INFO " << RB << " for record at " << line << " must have " << rnCount << " value(s)";
                throw new InfoBodyError{line, message.str(), "Found " + std::to_string(values.size()) + " value(s)"};
            }
        } else if (field_key == CIRUC) {  //conf.interval repeat unit count
            if (source->version < Version::v44) {   //not applicable for anything < v4.4
                return;
            }
            auto it = info.find(RUC);
            if (it != info.end()) {
                std::vector<std::string> RUCval;
                util::string_split(it->second, ",", RUCval);
                //ciruc count must be 2 * RUC count
                check_info_field_cardinality_explicit(values, 2 * RUCval.size(), CIRUC);
                for (int i = 0; i < values.size(); ++i) {
                    if (RUCval[i / 2] == MISSING_VALUE) {
                        if (values[i] != MISSING_VALUE) {               //ciruc must be missing with ruc missing
                            std::stringstream message;
                            message << "INFO " << CIRUC << " for record at " << line << " pos " << i+1 << " must be \'" << MISSING_VALUE << "\'";
                            throw new InfoBodyError{line, message.str(), "Found " + values[i]};
                        }
                    }
                }
            } else if (values.size()) {
                //CIRUC values without RUC!
                std::stringstream message;
                message << "INFO " << CIRUC << " at " << line << " can not have values without " << RUC;
                throw new InfoBodyError{line, message.str(), "Found " + std::to_string(values.size()) + "value(s)"};
            }
        } else if (field_key == CIRB) {
            if (source->version < Version::v44) {   //not applicable for anything < v4.4
                return;
            }
            auto it = info.find(RB);
            if (it != info.end()) {
                std::vector<std::string> RBval;
                util::string_split(it->second, ",", RBval);
                //cirb count must be 2 * RB count
                check_info_field_cardinality_explicit(values, 2 * RBval.size(), CIRB);
                for (int i = 0; i < values.size(); ++i) {
                    if (RBval[i / 2] == MISSING_VALUE) {
                        if (values[i] != MISSING_VALUE) {               //cirb must be missing with RB missing
                            std::stringstream message;
                            message << "INFO " << CIRB << " for record at " << line << " pos " << i+1 << " must be \'" << MISSING_VALUE << "\'";
                            throw new InfoBodyError{line, message.str(), "Found " + values[i]};
                        }
                    }
                }
            } else if (values.size()) {
                //CIRB values without RB!
                std::stringstream message;
                message << "INFO " << CIRB << " at " << line << " can not have values without " << RB;
                throw new InfoBodyError{line, message.str(), "Found " + std::to_string(values.size()) + "value(s)"};
            }
        } else if (field_key == RUB) {
            if (source->version < Version::v44) {   //not applicable for anything < v4.4
                return;
            }
            auto it = info.find(RUC);
            if (it != info.end()) {
                std::string message;
                std::vector<std::string> RUCval;
                util::string_split(it->second, ",", RUCval);
                int cnt = 0;
                for (int i = 0; i < RUCval.size(); ++i) {   //RUC must be integer with RUB
                    if (RUCval[i] == MISSING_VALUE) {
                        continue;
                    }
                    try {
                        check_value_type(INTEGER, RUCval[i], message);
                    } catch (const std::exception &typeError) {
                        std::stringstream message;
                        message << "INFO " << RUC << " for record at " << line << " must be integer with " + RUB;
                        throw new InfoBodyError{line, message.str()};
                    }
                    cnt += std::stoi(RUCval[i]);
                }
                //RUB size must be sum(RUC[i])
                check_info_field_cardinality_explicit(values, cnt, RUB);
            }
            else {
                //must be present
                std::stringstream message;
                message << "INFO " << RUB << " for record at " << line << " must have " + RUC;
                throw new InfoBodyError{line, message.str()};
            }
        } else if (field_key == MEINFO) {
            if (source->version < Version::v44) {   //not applicable for anything < v4.4
                return;
            }
            //MEINFO must be 4 * ALT allele count
            check_info_field_cardinality_explicit(values, 4 * alternate_alleles.size(), MEINFO);
        } else if (field_key == METRANS) {
            if (source->version < Version::v44) {   //not applicable for anything < v4.4
                return;
            }
            //METRANS must be 4 * ALT allele count
            check_info_field_cardinality_explicit(values, 4 * alternate_alleles.size(), METRANS);
        } else if (field_key == CICN) {
            if (source->version < Version::v44) {   //fixed size and already checked when < v44
                return;
            }
            //CICN must be 2 * ALT allele count
            check_info_field_cardinality_explicit(values, 2 * alternate_alleles.size(), CICN);
        } else if (field_key == CIPOS) {
            if (source->version < Version::v44) {   //fixed size and already checked when < v44
                return;
            }
            //CIPOS must be 2 * ALT allele count
            check_info_field_cardinality_explicit(values, 2 * alternate_alleles.size(), CIPOS);
        } else if (field_key == CIEND) {
            if (source->version < Version::v44) {   //fixed size and already checked when < v44
                return;
            }
            //CIEND must be 2 * ALT allele count
            check_info_field_cardinality_explicit(values, 2 * alternate_alleles.size(), CIEND);
        } else if (field_key == CILEN) {
            if (source->version < Version::v44) {   //fixed size and already checked when < v44
                return;
            }
            //CILEN must be 2 * ALT allele count
            check_info_field_cardinality_explicit(values, 2 * alternate_alleles.size(), CILEN);
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
            //with v44, there can be optional leading phasing info, remove it and use
            bool checkprefix = source->version < Version::v44? false : true;
            if (checkprefix && !GT_subfield.empty()) {
                if (GT_subfield.at(0) == '/' || GT_subfield.at(0) == '|') {
                    GT_subfield.erase(0,1);
                }
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
            //with v44, there can be optional leading phasing info, remove it and use
            bool checkprefix = source->version < Version::v44? false : true;
            if (checkprefix && !subfields.empty()) {
                if (!subfields[0].empty()) {
                    if (subfields[0].at(0) == '/' || subfields[0].at(0) == '|') {
                        subfields[0].erase(0,1);
                    }
                }
            }
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
        size_t ploidy = 2;  // diploidy is assumed if no GT present. spec: v4.3 at 1.6.2 Genotype fields, GL, applies to FORMAT fields with Number=G
        if (format[0] == GT) {
            ploidy = get_ploidy_from_GT(samples[i]);
        }

        for (size_t j = 0; j < subfields.size(); ++j) {
            MetaEntry meta = format_meta[j];
            const std::string & subfield = subfields[j];
            util::string_split(subfield, ",", values);

            if (meta.is_defined_in_header()) {
                auto &meta_entry_properties = boost::get<std::map<std::string, std::string>>(meta.value);
                long expected_cardinality;

                try {
                    check_sample_field_cardinality(values, meta_entry_properties[NUMBER], ploidy, expected_cardinality);
                    check_field_type(values, meta_entry_properties[TYPE]);
                } catch (std::shared_ptr<Error> ex) {
                    std::string message = "Sample #" + std::to_string(i + 1) + ", field " + meta_entry_properties[ID]
                                          + " does not match the meta" + ex->message;
                    std::string detailed_message = meta_entry_properties[ID] + "=" + subfield + ex->detailed_message;
                    throw new SamplesFieldBodyError{line, message, detailed_message, meta_entry_properties[ID],
                                                    expected_cardinality};
                }
            } else {
                try {
                    if (source->version == Version::v41 || source->version == Version::v42) {
                        check_predefined_tag_format(format[j], values, format_v41_v42, ploidy);
                    } else if (source->version == Version::v43) {
                        check_predefined_tag_format(format[j], values, format_v43, ploidy);
                    } else {
                        check_predefined_tag_format(format[j], values, format_v44, ploidy);
                    }
                } catch (std::shared_ptr<Error> ex) {
                    throw new SamplesFieldBodyError{line, "Sample #" + std::to_string(i + 1) + ", " + ex->message,
                                                    format[j] + "=" + subfield, format[j]};
                }
            }

            strict_validation_format_predefined_tags(i, format[j], subfield, values);
        }
    }

    void Record::strict_validation_format_predefined_tags(size_t i, std::string const & field_key, std::string const & field_value,
                                                          std::vector<std::string> const & values) const
    {
        std::string message = "Sample #" + std::to_string(i + 1) + ", " + field_key + "=" + field_value + " value";
        if (field_key == GP || (field_key == CNP && (source->version == Version::v43 || source->version == Version::v44))) {
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
        long ploidy = alleles.size();
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
        if (util::contains_if_not(allele, isdigit)) {
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

    bool Record::is_valid_cardinality(std::string const &number, size_t alternate_allele_number, size_t ploidy,
                                      long &expected_cardinality) const
    {
        bool valid = true;

        if (number == A) {
            // ...the number of alternate alleles
            expected_cardinality = alternate_allele_number;
        } else if (number == R) {
            // ...the number of alternate alleles + reference
            expected_cardinality = alternate_allele_number + 1;
        } else if (number == G) {
            // ...the number of possible genotypes
            // The binomial coefficient is calculated considering the ploidy of the sample
            expected_cardinality = boost::math::binomial_coefficient<float>(alternate_alleles.size() + ploidy, ploidy);
        } else if (number == UNKNOWN_CARDINALITY) {
            // ...it is unspecified
            expected_cardinality = -1;
        } else {
            // ...specified as a number in range [0, +MAX_LONG)
            try {
                size_t scanned_number_length;
                expected_cardinality = stoi(number, &scanned_number_length);
                if (expected_cardinality < 0 || number.size() != scanned_number_length) {
                    expected_cardinality = -1;
                    valid = false;
                }
            } catch (...) {
                expected_cardinality = -1;
                valid = false;
            }
        }
        return valid;
    }

    void Record::check_info_field_cardinality(std::vector<std::string> const &values, std::string const &number) const
    {
        if (number != G) {
            long cardinality;
            size_t ploidy = 0;
            check_sample_field_cardinality(values, number, ploidy, cardinality);
        } else {
            // this case is not well defined, we just skip this check and allow any cardinality
            // for further discussion see https://github.com/samtools/hts-specs/issues/272
        }
    }

    void Record::check_sample_field_cardinality(std::vector<std::string> const &values, std::string const &number,
                                                size_t ploidy, long &expected_cardinality) const
    {
        if (!is_valid_cardinality(number, alternate_alleles.size(), ploidy, expected_cardinality)) {
            raise(std::make_shared<Error>(line, " meta specification Number=" + number
                    + " is not one of [A, R, G, ., <non-negative number>]"));
        }
        if(!values.empty()) {
            if (values.front() == MISSING_VALUE && values.size() == 1) { return; } // No need to check missing data
        }

        bool number_matches = true;
        if (expected_cardinality > 0) {
            // The number of values must match the expected cardinality
            number_matches = (values.size() == static_cast<size_t>(expected_cardinality));
        } else if (expected_cardinality == 0) {
            // There will be one empty value that needs to be specifically checked
            number_matches = values.size() == 0 || values.size() == 1;
        } else {
            // if number=".", then `expected_cardinality` was set to -1, and it should always match, letting `number_matches` as true
        }

        if (!number_matches) {
            std::string message = " specification Number=" + number + " (expected "
                    + std::to_string(expected_cardinality) + " value(s))";
            std::string detailed_message;
            if (number == G) {
                detailed_message = ". It must derive its number of values from the ploidy of GT (if present), or "
                        "assume diploidy. Contains " + std::to_string(values.size()) + " value(s), expected "
                        + std::to_string(expected_cardinality) + " (derived from ploidy " + std::to_string(ploidy)
                        + ")";
            }
            raise(std::make_shared<Error>(line, message, detailed_message));
        }
    }

    void Record::check_value_type(std::string const & type, std::string const & value, std::string & message) const {
        if (type == INTEGER) {
            // ...try to cast to int
            std::size_t scanned_value_length;
            std::stoi(value, &scanned_value_length);
            if (value.size() != scanned_value_length) {
                message = " (not in integer format)";
                throw std::invalid_argument(message);
            }
            // ...and also check it's not a float
            if (std::fmod(std::stof(value), 1) != 0) {
                message = " (an integer must not contain a decimal point)";
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
            size_t scanned_value_length;
            int numeric_value = std::stoi(value, &scanned_value_length);
            if (value.size() != scanned_value_length || value.size() > 1 || (numeric_value != 0 && numeric_value != 1)) {
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
        if (field == SVLEN || field == CIPOS || field == CIEND || field == CILEN || field == CIRB ||
            (field == CICNADJ && source->version < Version::v44)) {
            // to ignore predefined tag fields which permit negative integral values
            return;
        }
        for (auto & value : values) {
            if (value == MISSING_VALUE) { continue; }
            size_t scanned_value_length;
            int numeric_value = std::stoi(value, &scanned_value_length);
            if (value.size() != scanned_value_length || numeric_value < 0) {
                raise(std::make_shared<Error>(line, field + " value must be a non-negative integer number"));
            }
        }
    }

    int Record::getRNvalue() const {
        static boost::regex cnvtr_regex("<CNV:TR>");
        auto it = info.find(RN);
        int rnCnt = 0;
        std::vector<std::string> values;

        if (it != info.end()) {                     //spilt RN field
            util::string_split(it->second, ",", values);
        }

        for (int i = 0; i < alternate_alleles.size(); ++i) {
            if (values.size()) {                   //RN present
                rnCnt += (values[i] == MISSING_VALUE) ? 0 : std::stoi(values[i]);
            } else if (types[i] == RecordType::STRUCTURAL && boost::regex_match(alternate_alleles[i], cnvtr_regex)) {
                //CNV:TR with no RN, consider as 1
                rnCnt++;
            }
        }
        return rnCnt;
    }

    int Record::check_info_field_cardinality_explicit(std::vector<std::string> const & values, size_t expected,
                const std::string field) const {
        if (values.size() != expected) {
            std::stringstream message;
            message << "INFO " << field << " for record at " << line << " must have " << expected << " value(s)";
            throw new InfoBodyError{line, message.str(), "Found " + std::to_string(values.size()) + " value(s)"};
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
