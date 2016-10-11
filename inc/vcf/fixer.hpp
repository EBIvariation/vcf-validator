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

#ifndef VCF_FIXER_HPP
#define VCF_FIXER_HPP

#include <vector>
#include <iostream>
#include <algorithm>

#include "util/stream_utils.hpp"
#include "util/string_utils.hpp"
#include "error.hpp"

namespace ebi
{
  namespace vcf
  {
    class Fixer : public ErrorVisitor {
      public:
        Fixer(std::ostream &output)
                : line_number{0}, line{nullptr}, output(output), ignored_errors{0} { }

        void fix(size_t line_number, std::vector<char> &line, Error &error)
        {
            this->line_number = line_number;
            this->line = &line; // this will be valid until this function returns
            error.apply_visitor(*this);
            this->line = nullptr;
        }

        size_t get_ignored_errors() {return ignored_errors;}

      private:
        size_t line_number;
        std::vector<char> *line;
        std::ostream &output;
        size_t ignored_errors;

        virtual void visit(Error &error) override
        {
            util::writeline(output, *line);
            ignored_errors++;
        }
        virtual void visit(MetaSectionError &error) override
        {
            util::writeline(output, *line);
            ignored_errors++;
        }
        virtual void visit(HeaderSectionError &error) override
        {
            util::writeline(output, *line);
            ignored_errors++;
        }
        virtual void visit(BodySectionError &error) override
        {
            util::writeline(output, *line);
            ignored_errors++;
        }
        virtual void visit(NoMetaDefinitionError &error)
        {
            util::writeline(output, *line);
            ignored_errors++;
        }
        virtual void visit(FileformatError &error) override
        {
            util::writeline(output, *line);
            ignored_errors++;
        }
        virtual void visit(ChromosomeBodyError &error) override
        {
            util::writeline(output, *line);
            ignored_errors++;
        }
        virtual void visit(PositionBodyError &error) override
        {
            util::writeline(output, *line);
            ignored_errors++;
        }
        virtual void visit(IdBodyError &error) override
        {
            util::writeline(output, *line);
            ignored_errors++;
        }
        virtual void visit(ReferenceAlleleBodyError &error) override
        {
            util::writeline(output, *line);
            ignored_errors++;
        }
        virtual void visit(AlternateAllelesBodyError &error) override
        {
            util::writeline(output, *line);
            ignored_errors++;
        }
        virtual void visit(QualityBodyError &error) override
        {
            util::writeline(output, *line);
            ignored_errors++;
        }
        virtual void visit(FilterBodyError &error) override
        {
            util::writeline(output, *line);
            ignored_errors++;
        }
        /**
         * fix: remove the info field that caused the error
         */
        virtual void visit(InfoBodyError &error) override
        {
            // TODO better log system, if any
            std::cerr << "DEBUG: line " << error.line << ": fixing invalid INFO field " << error.field << std::endl;
            const size_t info_column_index = 7;
            const std::string empty_info_column = ".";

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
        virtual void visit(FormatBodyError &error) override
        {
            util::writeline(output, *line);
            ignored_errors++;
        }
        virtual void visit(SamplesBodyError &error) override
        {
            util::writeline(output, *line);
            ignored_errors++;
        }

        /**
         * explanation of the fix:
         * - in error.get_field there will be the field name as it appears in the FORMAT column, e.g. "GT".
         * - if error.field is empty, skip fix (copy the line as-is)
         * - get the index in the FORMAT column of error.field, e.g. in GT:AC:AN, the index of AC is 1.
         *      if the field is not found, skip fix (copy as-is)
         * - for each sample column
         *      - if the field is GT
         *          - put a "missing value" instead of the value in the index-th position after splitting by ":".
         *          - the "missing value" is a `.` repeated `n` times, where `n` is the cardinality of the field,
         *              with "/" as separators
         *      - if the field is not GT
         *          - remove it from the FORMAT and samples columns
         * - if there were no sample columns, skip fix (copy as-is)
         *
         * complete example:
         * field "GT", FORMAT: "GT:AC:AN", sample: "0/0:3,5:4"; becomes "./.:3,5:4". (index = 0, cardinality = 2)
         * field "AC", FORMAT: "GT:AC:AN", sample: "0/0:3,5:4"; becomes "GT:AN   0/0:4". (index = 1)
         * @param error
         */
        virtual void visit(SamplesFieldBodyError &error) override
        {
            std::cerr << "DEBUG: line " << error.line << ": fixing invalid sample field " << error.field
                      << std::endl;

            const size_t format_column_index = 8;
//                size_t first_samples_column_index = 9;
            std::string string_line = {line->begin(), line->end()};

            size_t fixed_samples;
            std::string message;
            try {
                using iter = std::vector<std::string>::iterator;
                fixed_samples = fix_columns(format_column_index, -1, string_line, "\t", [&](iter first, iter last) {
                    if (error.field == "GT") {
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

        virtual void visit(NormalizationError &error) override
        {
            util::writeline(output, *line);
            ignored_errors++;
        }
        virtual void visit(DuplicationError &error) override
        {
            // TODO better log system, if any
            std::cerr << "DEBUG: line " << line_number << ": fixing duplicate: removing variant: "
            << std::string{line->begin(), line->end()} << std::endl;
        }

      protected:

        /**
         * puts the genotype as missing. if the error.cardinality is know, it uses the proper ploidy
         * @param first iterator to the FORMAT column string
         * @param last iterator past the last sample column
         * @param error needed for the field (that must be "GT") the cardinality, and the line number
         */
        void fix_format_gt(std::vector<std::string>::iterator first,
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

        /**
         * remove a field from the FORMAT column and the samples columns
         * @param first iterator to the FORMAT column string
         * @param last iterator past the last sample column
         * @param error needed for the field the cardinality, and the line number
         */
        void remove_format(std::vector<std::string>::iterator first,
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

        size_t remove_column(const std::string &line,
                             const std::string &separator,
                             std::function<bool(std::string &column, size_t index)> condition_to_remove)
        {
            return remove_column(line, separator, "", condition_to_remove);
        }

        /**
         * don't write to output the columns in `line` that satisfy the `condition_to_remove`
         * @param line: some of its columns will not be written into output
         * @param separator to be used to split `line`
         * @param empty_column in case all the columns were remove, write an especial empty column
         * @param condition_to_remove return true if the column has to be removed. can decide using the column and its index
         * @return amount of columns removed
         */
        size_t remove_column(const std::string &line,
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

        /**
         * returns an index (NOT an iterator) to the column in `line` (split by `separator`) where `value` is found. Or `line.npos`
         * if value is not found.
         * @param line to be split
         * @param separator to use when splitting the line
         * @param value to search
         * @return an index (not an iterator) if found, or `line.npos` if not found.
         */
        size_t split_and_find(const std::string &line, const std::string &separator, const std::string &value) {
            std::vector<std::string> columns;
            util::string_split(line, separator.c_str(), columns);
            auto found = std::find(columns.begin(), columns.end(), value);
            return found == columns.end()? line.npos : found - columns.begin();
        }

        /**
         * splits a line and allows to rewrite one of the columns, copying the other columns into "output"
         * @param column_index: index to the column to modify
         * @param line: whole line that will be split
         * @param separator: will be used to split the line
         * @param fix_function: takes a string, which is the column to fix. `fix_function` must write to
         * the member "output". `fix_function` will be called once
         * @return the number of times `fix_function` was called, that should be 1 if ranges were valid
         */
        size_t fix_column(size_t column_index,
                        const std::string &line,
                        const std::string &separator,
                        std::function<void(std::string &column)> fix_function) {

            using iter = std::vector<std::string>::iterator;
            return fix_columns(column_index, column_index +1, line, separator, [fix_function](iter first, iter last) {
                for (auto it = first; it != last; ++it) {
                    fix_function(*it);
                }
            });
        }

        /**
         * splits a line and allows to rewrite one of the columns, copying the other columns into "output"
         * @param column_index: index to the column to modify
         * @param column_index_last: NON-INCLUSIVE index. points to the column after the last column to modify.
         * to write all the remaining columns, pass -1
         * @param line: whole line that will be split
         * @param separator: will be used to split the line
         * @param fix_function: takes a string, which is the column to fix. `fix_function` must write to the member
         * "output". `fix_function` will be called (column_index_last - column_index) times
         * (or less if the range is invalid)
         * @return the number of times `fix_function` was called, that should be (column_index_last - column_index)
         * if ranges were valid
         */
        size_t fix_foreach_column(size_t column_index,
                        long column_index_last,
                        const std::string &line,
                        const std::string &separator,
                        std::function<void(std::string &column)> fix_function) {

            using iter = std::vector<std::string>::iterator;
            return fix_columns(column_index, column_index_last, line, separator, [fix_function](iter first, iter last) {
                fix_function(*first);
            });
        }

        /**
         * splits a line and allows to rewrite one of the columns, copying the other columns into "output".
         * If column_index* specify an empty range or a past-the-end range, a std::out_of_range is thrown without
         * writing anything.
         * @param column_index: index to the column to modify
         * @param column_index_last: NON-INCLUSIVE index. points to the column after the last column to modify.
         * to write all the remaining columns, pass -1
         * @param line: whole line that will be split
         * @param separator: will be used to split the line
         * @param fix_function: takes a range [first, last)  of strings, which is the column to fix. `fix_function` must
         * write to the member "output". `fix_function` will be called once
         * @return the number of columns passed to `fix_function`, that should be (column_index_last - column_index)
         * if ranges were valid
         */
        size_t fix_columns(size_t column_index,
                        long column_index_last,
                        const std::string &line,
                        const std::string &separator,
                        std::function<void(std::vector<std::string>::iterator begin,
                                           std::vector<std::string>::iterator end)> fix_function) {

            std::vector<std::string> columns;
            util::string_split(line, separator.c_str(), columns);
            std::string eol;
            if (columns.back().back() == '\n') {
                //remove (and add it later) the newline so that the `fix_function` doesn't have to deal with it.
                columns.back().pop_back();
                if (columns.back().back() == '\r') {
                    columns.back().pop_back();
                    eol += "\r";
                }
                eol += "\n";
            }

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
    };
  }
}

#endif // VCF_FIXER_HPP
