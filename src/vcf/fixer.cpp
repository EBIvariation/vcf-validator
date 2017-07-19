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

        void Fixer::visit(Error &error)
        {
            util::writeline(output, *line);
            ignored_errors++;
        }

        void Fixer::visit(MetaSectionError &error)
        {
            util::writeline(output, *line);
            ignored_errors++;
        }

        void Fixer::visit(HeaderSectionError &error)
        {
            util::writeline(output, *line);
            ignored_errors++;
        }

        void Fixer::visit(BodySectionError &error)
        {
            util::writeline(output, *line);
            ignored_errors++;
        }

        void Fixer::visit(NoMetaDefinitionError &error)
        {
            util::writeline(output, *line);
            ignored_errors++;
        }

        void Fixer::visit(FileformatError &error)
        {
            util::writeline(output, *line);
            ignored_errors++;
        }

        void Fixer::visit(ChromosomeBodyError &error)
        {
            util::writeline(output, *line);
            ignored_errors++;
        }

        void Fixer::visit(PositionBodyError &error)
        {
            util::writeline(output, *line);
            ignored_errors++;
        }

        void Fixer::visit(IdBodyError &error)
        {
            util::writeline(output, *line);
            ignored_errors++;
        }

        void Fixer::visit(ReferenceAlleleBodyError &error)
        {
            util::writeline(output, *line);
            ignored_errors++;
        }

        void Fixer::visit(AlternateAllelesBodyError &error)
        {
            util::writeline(output, *line);
            ignored_errors++;
        }

        void Fixer::visit(QualityBodyError &error)
        {
            util::writeline(output, *line);
            ignored_errors++;
        }

        void Fixer::visit(FilterBodyError &error)
        {
            util::writeline(output, *line);
            ignored_errors++;
        }

        void Fixer::visit(InfoBodyError &error)
        {
            // TODO better log system, if any
            std::cerr << "DEBUG: line " << error.line << ": fixing invalid INFO field " << error.field << std::endl;
            const size_t info_column_index = 7;
            const std::string empty_info_column = MISSING_VALUE;

            size_t num_removed_fields = 0;
            std::string string_line = {line->begin(), line->end()};

            auto condition_to_remove_info_field = [&](std::string &info_subfield, size_t index) -> bool {
                std::vector<std::string> key_value;
                util::string_split(info_subfield, "=", key_value);
                return key_value[0] == error.field;
            };

            fix_column(info_column_index, string_line, "\t", [&](std::string &info_column) {
                num_removed_fields = remove_column(info_column, ";", empty_info_column, condition_to_remove_info_field);
            });

            if (num_removed_fields != 1) {
                std::cerr << "WARNING: line " << error.line << ": field " << error.field << " appeared "
                          << num_removed_fields << " times " << std::endl;
            }
        }

        void Fixer::visit(FormatBodyError &error)
        {
            util::writeline(output, *line);
            ignored_errors++;
        }

        void Fixer::visit(SamplesBodyError &error)
        {
            util::writeline(output, *line);
            ignored_errors++;
        }

        void Fixer::visit(SamplesFieldBodyError &error)
        {
            std::cerr << "DEBUG: line " << error.line << ": fixing invalid sample field " << error.field
                      << std::endl;

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
                std::cerr << "WARNING: line " << error.line << ": tried to fix field " << error.field
                          << " in the samples column, but sample columns are not present. " << message << std::endl;
                util::writeline(output, *line);
                ignored_errors++;
                return;
            }
        }

        void Fixer::visit(NormalizationError &error)
        {
            util::writeline(output, *line);
            ignored_errors++;
        }

        void Fixer::visit(DuplicationError &error)
        {
            // TODO better log system, if any
            std::cerr << "DEBUG: line " << line_number << ": fixing duplicate: removing variant: "
            << std::string{line->begin(), line->end()} << std::endl;
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
                std::cerr << "WARNING: line " << error.line << ": tried to fix field \"" << error.field
                          << "\" but it was not present in the FORMAT column \"" + *first + "\"" << std::endl;
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
            size_t removed = remove_column(*first, field_separator, [&](std::string &field, size_t index) {
                if (field == error.field) {
                    field_index = index;
                    return field == error.field;
                } else {
                    return false;
                }
            });
            if (removed == 0) {
                std::cerr << "WARNING: line " << error.line << ": tried to fix field \"" << error.field
                          << "\" but it was not present in the FORMAT column \"" + *first + "\"" << std::endl;
                ignored_errors++;
                util::print_container(output, std::vector<std::string>{++first, last}, "\t", "\t", "");
                return;
            }

            // remove from the samples columns
            for (++first; first != last; ++first) {
                output << "\t";
                removed = remove_column(*first, field_separator, [&](std::string &field, size_t index) {
                    return index == field_index;
                });
                if (removed == 0) {
                    std::cerr << "WARNING: tried to remove field with index " << field_index << " in \"" << *first
                              << "\" but couldn't do it, this is likely to happen in all samples" << std::endl;
                    ignored_errors++;
                    // copy the rest of samples, as we already copied one and don't want to repeat the log for everyone
                    util::print_container(output, std::vector<std::string>{++first, last}, "\t", "\t", "");
                    return;
                }
            }
        }

        size_t Fixer::remove_column(const std::string &line,
                             const std::string &separator,
                             std::function<bool(std::string &column, size_t index)> condition_to_remove)
        {
            return remove_column(line, separator, "", condition_to_remove);
        }

        size_t Fixer::remove_column(const std::string &line,
                             const std::string &separator,
                             const std::string &empty_column,
                             std::function<bool(std::string &column, size_t index)> condition_to_remove)
        {
            std::vector<std::string> columns;
            util::string_split(line, separator.c_str(), columns);
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
                            output << separator;
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
            return fix_columns(column_index, column_index +1, line, separator, [fix_function](iter first, iter last) {
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
