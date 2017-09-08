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

#include <algorithm>

#include "util/stream_utils.hpp"
#include "util/string_utils.hpp"
#include "util/logger.hpp"
#include "vcf/fixer.hpp"
#include "vcf/string_constants.hpp"

namespace ebi
{
  namespace vcf
  {

    void Fixer::fix(size_t line_number, std::vector<char> &line, Error &error)
    {
        this->line_number = line_number;
        this->line = &line; // this will be valid until this function returns
        error.apply_visitor(*this);
        this->line = nullptr;
    }

    size_t Fixer::get_ignored_errors()
    {
        return ignored_errors;
    }

    void Fixer::ignore_error()
    {
        util::writeline(output, *line);
        ignored_errors++;        
    }

    void Fixer::visit(Error &error)
    {
        ignore_error();
    }

    void Fixer::visit(MetaSectionError &error)
    {
        if (error.error_fix == ErrorFix::IRRECOVERABLE_VALUE) {
            ignore_error();
        } else if (error.error_fix == ErrorFix::RECOVERABLE_VALUE) {
            std::string string_line = {line->begin(), line->end()};

            // fixing meta header definition of INFO and FORMAT, the error.value is either Type or Number
            size_t meta_error_field_start_index = string_line.find(error.value + "=");
            size_t meta_error_field_end_index = string_line.find(",", meta_error_field_start_index);     // exclusive

            BOOST_LOG_TRIVIAL(debug) << "Line " << error.line << ": Fixing incorrect predefined tag meta definition " << error.value;

            std::string fixed_meta_header_line = string_line.substr(0, meta_error_field_start_index) + error.value + "=" + error.expected_value + string_line.substr(meta_error_field_end_index);
            util::writeline(output, fixed_meta_header_line);
        }
    }

    void Fixer::visit(HeaderSectionError &error)
    {
        ignore_error();
    }

    void Fixer::visit(BodySectionError &error)
    {
        ignore_error();
    }

    void Fixer::visit(NoMetaDefinitionError &error)
    {
        ignore_error();
    }

    void Fixer::visit(FileformatError &error)
    {
        ignore_error();
    }

    void Fixer::visit(ChromosomeBodyError &error)
    {
        ignore_error();
    }

    void Fixer::visit(PositionBodyError &error)
    {
        ignore_error();
    }

    void Fixer::visit(IdBodyError &error)
    {
        if (error.error_fix == ErrorFix::DUPLICATE_VALUES) {
            BOOST_LOG_TRIVIAL(debug) << "Line " << error.line << ": Fixing duplicate ID fields";
            const size_t id_column_index = 2;
            std::string string_line = {line->begin(), line->end()};

            fix_column(id_column_index, string_line, "\t", [&](std::string &id_column) {
                remove_duplicate_strings(id_column, ";");
            });
        } else {
            ignore_error();
        }
    }

    void Fixer::visit(ReferenceAlleleBodyError &error)
    {
        ignore_error();
    }

    void Fixer::visit(AlternateAllelesBodyError &error)
    {
        ignore_error();
    }

    void Fixer::visit(QualityBodyError &error)
    {
        ignore_error();
    }

    void Fixer::visit(FilterBodyError &error)
    {
        if (error.field == "" && error.error_fix != ErrorFix::DUPLICATE_VALUES) {
            ignore_error();
            return;
        }

        const size_t filter_column_index = 6;
        std::string string_line = {line->begin(), line->end()};

        fix_column(filter_column_index, string_line, "\t", [&](std::string &filter_column) {
            if (error.error_fix == ErrorFix::IRRECOVERABLE_VALUE && error.field == "0") {
                BOOST_LOG_TRIVIAL(debug) << "Line " << error.line << ": Fixing invalid FILTER field " << error.field;
                const std::string empty_filter_column = MISSING_VALUE;
                auto condition_to_remove_filter_field = [&](const std::string &filter_subfield, size_t index) -> bool {
                    return filter_subfield == error.field;
                };

                remove_fields(filter_column, ";", empty_filter_column, condition_to_remove_filter_field);
            } else if (error.error_fix == ErrorFix::DUPLICATE_VALUES) {
                BOOST_LOG_TRIVIAL(debug) << "Line " << error.line << ": Fixing duplicate FILTER fields";
                remove_duplicate_strings(filter_column, ";");
            }
        });
    }

    void Fixer::visit(InfoBodyError &error)
    {
        const size_t info_column_index = 7;
        std::string string_line = {line->begin(), line->end()};

        fix_column(info_column_index, string_line, "\t", [&](std::string &info_column) {
            const std::string empty_info_column = MISSING_VALUE;

            auto condition_to_modify_info_field = [&](const std::string &info_subfield, size_t index) -> bool {
                std::vector<std::string> key_value;
                util::string_split(info_subfield, "=", key_value);
                return key_value[0] == error.field;
            };

            if (error.error_fix == ErrorFix::DUPLICATE_VALUES) {
                BOOST_LOG_TRIVIAL(debug) << "Line " << error.line << ": Fixing duplicate INFO fields";
                remove_duplicate_key_value_pairs(info_column, ";", "=", empty_info_column);
            } else if (error.error_fix == ErrorFix::RECOVERABLE_VALUE) {
                BOOST_LOG_TRIVIAL(debug) << "Line " << error.line << ": Fixing invalid INFO field " << error.field;
                replace_fields(info_column, ";", error.field + "=" + error.expected_value, condition_to_modify_info_field);
            } else if (error.error_fix == ErrorFix::IRRECOVERABLE_VALUE) {
                BOOST_LOG_TRIVIAL(debug) << "Line " << error.line << ": Removing invalid INFO field " << error.field;
                remove_fields(info_column, ";", empty_info_column, condition_to_modify_info_field);
            }
        });
    }

    void Fixer::visit(FormatBodyError &error)
    {
        if (error.error_fix == ErrorFix::DUPLICATE_VALUES) {
            BOOST_LOG_TRIVIAL(debug) << "Line " << error.line << ": Fixing duplicate FORMAT fields";
            std::string string_line = {line->begin(), line->end()};
            remove_duplicate_format_sample_pairs(string_line);
        } else {
            ignore_error();
        }
    }

    void Fixer::visit(SamplesBodyError &error)
    {
        ignore_error();
    }

    void Fixer::visit(SamplesFieldBodyError &error)
    {
        BOOST_LOG_TRIVIAL(debug) << "Line " << error.line << ": Fixing invalid sample field " << error.field;

        const size_t format_column_index = 8;
        // size_t first_samples_column_index = 9;
        std::string string_line = {line->begin(), line->end()};

        size_t fixed_samples;
        std::string message;
        try {
            using iter = std::vector<std::string>::iterator;
            fixed_samples = fix_columns(format_column_index, -1, string_line, "\t", [&](iter first, iter last) {
                if (error.field == GT) {
                    fix_format_gt(first, last, error);
                } else {
                    remove_format(first, last, error);
                }
            });
        } catch (std::out_of_range bad_range) {
            // there were not enough columns. maybe an aggregate vcf without genotypes?
            fixed_samples = 0;
            message = bad_range.what();
        }

        if (fixed_samples <= 1) {   // 1 because we started counting since the FORMAT column
            BOOST_LOG_TRIVIAL(warning) << "Line " << error.line << ": Tried to fix field " << error.field
                                       << " in the samples column, but sample columns are not present. " << message;
            ignore_error();
            return;
        }
    }

    void Fixer::visit(NormalizationError &error)
    {
        ignore_error();
    }

    void Fixer::visit(DuplicationError &error)
    {
        BOOST_LOG_TRIVIAL(debug) << "Line " << line_number << ": Fixing duplicate: removing variant: "
                                 << std::string{line->begin(), line->end()};
    }

    size_t Fixer::remove_duplicate_strings(const std::string &column,
                                           const std::string &separator)
    {
        std::set<std::string> already_present;
        auto is_value_duplicated = [&](const std::string &value, size_t index) -> bool {
            bool first_appearance = already_present.insert(value).second;
            return not first_appearance;
        };
        return remove_fields(column, separator, is_value_duplicated);
    }

    size_t Fixer::remove_duplicate_key_value_pairs(const std::string &column,
                                                   const std::string &separator,
                                                   const std::string &key_value_separator,
                                                   const std::string &empty_value)
    {
        std::map<std::string, std::string> first_key_occurrence;
        std::vector<std::string> ordered_keys;
        std::set<std::string> fields_to_remove;

        std::vector<std::string> fields;
        util::string_split(column, separator.c_str(), fields);

        for (auto & field : fields) {
            std::vector<std::string> subfields;
            util::string_split(field, key_value_separator.c_str(), subfields);
            auto first_key_iterator = first_key_occurrence.find(subfields[0]);
            if (first_key_iterator == first_key_occurrence.end()) {
                ordered_keys.push_back(subfields[0]);
                first_key_occurrence[subfields[0]] = subfields[1];
            } else if (first_key_occurrence[subfields[0]] != subfields[1]) {
                fields_to_remove.insert(subfields[0]);
            }
        }

        std::vector<std::string> fixed_column;
        size_t num_removed_duplicates = 0;

        for (auto & ordered_key : ordered_keys) {
            if (fields_to_remove.find(ordered_key) == fields_to_remove.end()) {
                fixed_column.push_back(ordered_key + key_value_separator + first_key_occurrence[ordered_key]);
            } else {
                num_removed_duplicates++;
            }
        }

        if (fixed_column.size() == 0) {       // all the fields were removed
            output << empty_value;
        } else {
            util::print_container(output, fixed_column, "", separator, "");
        }

        return num_removed_duplicates;
    }

    size_t Fixer::remove_duplicate_format_sample_pairs(const std::string &string_line) {
        const size_t format_column_index = 8;
        size_t num_removed_duplicates = 0;

        using iter = std::vector<std::string>::iterator;
        fix_columns(format_column_index, -1, string_line, "\t", [&](iter first, iter last) {
            std::map<std::string, std::vector<size_t>> format_fields_indexes;
            std::vector<std::string> ordered_fields;
            std::vector<std::string> format_keys;
            util::string_split(*first, ":", format_keys);

            for (size_t i = 0; i < format_keys.size(); i++) {
                format_fields_indexes[format_keys[i]].push_back(i);
                if (format_fields_indexes[format_keys[i]].size() == 1) {
                    ordered_fields.push_back(format_keys[i]);
                }
            }

            std::vector<std::vector<std::string>> samples;
            for (auto it = first + 1; it != last; it++) {
                std::vector<std::string> sample_fields;
                util::string_split(*it, ":", sample_fields);
                samples.push_back(sample_fields);
            }

            std::set<std::string> fields_to_remove = get_format_fields_to_remove(format_fields_indexes, samples);

            std::vector<std::string> fixed_format;
            for (auto & ordered_field : ordered_fields) {
                if (fields_to_remove.find(ordered_field) == fields_to_remove.end()) {
                    // keep first occurrence, discard the rest if present
                    fixed_format.push_back(ordered_field);
                } else {
                    num_removed_duplicates++;
                }
            }

            if (fixed_format.empty()) {
                throw std::runtime_error("Could not fix FORMAT duplicate fields: All fields had to be removed, but missing value is not permitted");
            }
            util::print_container(output, fixed_format, "", ":","");

            for (auto sample : samples) {
                std::vector<std::string> fixed_sample;
                for (auto & ordered_field : ordered_fields) {
                    if (fields_to_remove.find(ordered_field) == fields_to_remove.end()) {
                        // keep first occurrence, discard the rest if present
                        if (sample.size() > format_fields_indexes[ordered_field][0]) {
                            fixed_sample.push_back(sample[format_fields_indexes[ordered_field][0]]);
                        }
                    }
                }
                output << "\t";
                if (fixed_sample.empty()) {
                    output << MISSING_VALUE;         // all the sample fields were removed, so write missing value to output
                } else {
                    util::print_container(output, fixed_sample, "", ":", "");
                }
            }
        });

        return num_removed_duplicates;
    }

    std::set<std::string> Fixer::get_format_fields_to_remove(std::map<std::string, std::vector<size_t>> &format_fields_indexes,
                                                             std::vector<std::vector<std::string>> &samples)
    {
        std::set<std::string> fields_to_remove;

        for (auto sample_it = samples.begin(); sample_it != samples.end(); sample_it++) {
            for (auto & format_field : format_fields_indexes) {
                if (format_field.second.size() > 1) {
                    for (auto & format_field_index : format_field.second) {
                        if ((*sample_it).size() > format_field_index && (*sample_it)[format_field_index] != (*sample_it)[format_field.second[0]]) {
                            fields_to_remove.insert(format_field.first);
                            sample_it = samples.end() - 1;
                            break;
                        }
                    }
                }
            }
        }

        return fields_to_remove;
    }

    void Fixer::fix_format_gt(std::vector<std::string>::iterator first,
                              std::vector<std::string>::iterator last,
                              SamplesFieldBodyError &error)
    {
        const std::string field_separator = ":";
        size_t gt_column_index = 0;
        // if the field is GT, the values must use "/", as in "./."
        const std::string subfield_separator = "/";
        const char empty_subfield = '.';

        // check that GT is present and is the first field
        size_t subfield_index = split_and_find(*first, field_separator, error.field);
        if (subfield_index != gt_column_index) {
            BOOST_LOG_TRIVIAL(warning) << "Line " << error.line << ": Tried to fix field \"" << error.field
                                       << "\" but it was not present in the FORMAT column \"" << *first << "\"";
            ignored_errors++;
            util::print_container(output, std::vector<std::string>{first, last}, "", "\t", "");
            return;
        }

        // write the FORMAT column
        output << *first;

        // `cardinality` should be -1 if the cardinality is unknown, and any positive number otherwise
        // so, if unknown, put 1, so that a single "." is written
        size_t repeat = error.field_cardinality <= -1 ? 1 : static_cast<size_t>(error.field_cardinality);

        // now `it` will point to each SAMPLE column
        for (auto it = ++first; it != last; ++it) {
            output << "\t";
            fix_column(gt_column_index, *it, field_separator, [&](std::string wrong_subfield) {
                util::print_container(output, std::string(repeat, empty_subfield), "", subfield_separator, "");
            });
        }
    }

    void Fixer::remove_format(std::vector<std::string>::iterator first,
                              std::vector<std::string>::iterator last,
                              SamplesFieldBodyError &error)
    {
        // remove from FORMAT column
        const std::string field_separator = ":";
        size_t field_index;
        size_t removed = remove_fields(*first, field_separator, [&](const std::string &field, size_t index) {
            if (field == error.field) {
                field_index = index;
                return field == error.field;
            } else {
                return false;
            }
        });
        if (removed == 0) {
            BOOST_LOG_TRIVIAL(warning) << "Line " << error.line << ": Tried to fix field \"" << error.field
                                       << "\" but it was not present in the FORMAT column \"" << *first << "\"";
            ignored_errors++;
            util::print_container(output, std::vector<std::string>{++first, last}, "\t", "\t", "");
            return;
        }

        // remove from the samples columns
        for (++first; first != last; ++first) {
            output << "\t";
            removed = remove_fields(*first, field_separator, [&](const std::string &field, size_t index) {
                return index == field_index;
            });
            if (removed == 0) {
                BOOST_LOG_TRIVIAL(warning) << "Tried to remove field with index " << field_index << " in \"" << *first
                                           << "\" but couldn't do it, this is likely to happen in all samples";
                ignored_errors++;
                // copy the rest of samples, as we already copied one and don't want to repeat the log for everyone
                util::print_container(output, std::vector<std::string>{++first, last}, "\t", "\t", "");
                return;
            }
        }
    }

    size_t Fixer::remove_fields(const std::string &line,
                                const std::string &separators,
                                std::function<bool(const std::string &column, size_t index)> condition_to_remove)
    {
        return remove_fields(line, separators, "", condition_to_remove);
    }

    size_t Fixer::remove_fields(const std::string &line,
                                const std::string &separators,
                                const std::string &empty_column,
                                std::function<bool(const std::string &column, size_t index)> condition_to_remove)
    {
        std::vector<std::string> columns;
        util::string_split(line, separators.c_str(), columns);
        size_t written = 0;

        if (columns.size() > 0) {
            size_t j = 0;
            if (not condition_to_remove(columns[j], j)) {
                written++;
                output << columns[j];
            }
            for (j = 1; j < columns.size(); ++j) {
                if (not condition_to_remove(columns[j], j)) {
                    if (written > 0) {
                        output << separators;
                    }
                    written++;
                    output << columns[j];
                }
            }
        }
        if (written == 0) {
            output << empty_column;
        }
        return columns.size() - written;
    }

    size_t Fixer::replace_fields(const std::string &line,
                                 const std::string &separators,
                                 const std::string &expected_field,
                                 std::function<bool(const std::string &column, size_t index)> condition_to_replace)
    {
        std::vector<std::string> columns;
        util::string_split(line, separators.c_str(), columns);
        size_t num_replaced_columns = 0;

        for (size_t j = 0; j < columns.size(); ++j) {
            if (condition_to_replace(columns[j], j)) {
                num_replaced_columns++;
                output << expected_field;
            } else {
                output << columns[j];
            }
            if (j < columns.size() - 1) {
                output << separators;
            }
        }

        return num_replaced_columns;
    }

    size_t Fixer::split_and_find(const std::string &line, const std::string &separator, const std::string &value)
    {
        std::vector<std::string> columns;
        util::string_split(line, separator.c_str(), columns);
        auto found = std::find(columns.begin(), columns.end(), value);
        return found == columns.end()? line.npos : found - columns.begin();
    }

    size_t Fixer::fix_column(size_t column_index,
                             const std::string &line,
                             const std::string &separator,
                             std::function<void(std::string &column)> fix_function)
    {
        using iter = std::vector<std::string>::iterator;
        return fix_columns(column_index, column_index + 1, line, separator, [fix_function](iter first, iter last) {
            for (auto it = first; it != last; ++it) {
                fix_function(*it);
            }
        });
    }

    size_t Fixer::fix_foreach_column(size_t column_index,
                                     long column_index_last,
                                     const std::string &line,
                                     const std::string &separator,
                                     std::function<void(std::string &column)> fix_function)
    {
        using iter = std::vector<std::string>::iterator;
        return fix_columns(column_index, column_index_last, line, separator, [fix_function](iter first, iter last) {
            fix_function(*first);
        });
    }

    size_t Fixer::fix_columns(size_t column_index,
                              long column_index_last,
                              const std::string &line,
                              const std::string &separator,
                              std::function<void(std::vector<std::string>::iterator begin,
                                                 std::vector<std::string>::iterator end)> fix_function)
    {
        std::vector<std::string> columns;
        util::string_split(line, separator.c_str(), columns);

        //remove (and add it later) the newline so that the `fix_function` doesn't have to deal with it.
        std::string eol = util::remove_end_of_line(columns.back());

        // check ranges. don't allow an empty range, the fix_function should be called at least once
        size_t column_index_last_unsigned;
        if (column_index_last < 0) {
            column_index_last_unsigned = columns.size();
        } else {
            column_index_last_unsigned = static_cast<size_t>(column_index_last);
        }

        if (column_index >= columns.size()) {
            std::string message{"fix_columns requires a non-empty range: asked to fix columns["};
            message += std::to_string(column_index) + "] (0-based index) but there are only "
                    + std::to_string(columns.size()) + " columns: \"" + line + "\"";
            throw std::out_of_range{message};
        }
        if (column_index_last_unsigned > columns.size()) {
            std::string message{"fix_columns: asked to fix until past-the end, until (non-including) columns["};
            message += std::to_string(column_index_last_unsigned) + "] (0-based index) but there are only "
                    + std::to_string(columns.size()) + " columns: \"" + line + "\"";
            throw std::out_of_range{message};
        }

        // write before, call fix_function, write after
        for (size_t i = 0; i < column_index; ++i) {
            output << columns[i] << separator;
        }

        fix_function(columns.begin() + column_index, columns.begin() + column_index_last_unsigned);

        for (size_t i = column_index_last_unsigned; i < columns.size(); ++i) {
            output << separator << columns[i];
        }

        output << eol;

        return column_index_last_unsigned - column_index;
    }
  }
}
