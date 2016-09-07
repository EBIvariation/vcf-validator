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

#ifndef VCF_VALIDATOR_FIXER_HPP
#define VCF_VALIDATOR_FIXER_HPP

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
            std::cerr << "DEBUG: line " << error.get_line() << ": fixing invalid INFO field " << error.get_field()
                      << std::endl;
            const size_t info_column_index = 7;
            const std::string empty_info_column = ".";

            size_t num_removed_subfields = 0;
            std::string string_line = {line->begin(), line->end()};

            fix_column(info_column_index, string_line, "\t", [&](std::string &info_column) {
                std::vector<std::string> info_subfields, keys_values;
                util::string_split(info_column, ";", info_subfields);

                for (size_t j = 0; j < info_subfields.size(); ++j) {
                    util::string_split(info_subfields[j], "=", keys_values);
                    if (keys_values[0] != error.get_field()) {
                        if (num_removed_subfields != j) {
                            // if this is not the first field we don't remove, then write the separator
                            output << ";";
                        }
                        output << info_subfields[j];
                    } else {
                        num_removed_subfields++;
                    }
                }

                if (num_removed_subfields == info_subfields.size()) {
                    // we removed all the subfields there were: write empty column
                    output << empty_info_column;
                }
            });

            if (num_removed_subfields != 1) {
                std::cerr << "WARNING: line " << error.get_line() << ": field " << error.get_field() << " appeared "
                          << num_removed_subfields << " times " << std::endl;
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
         * - skip fix (copy the line as-is) if error.get_field() is empty
         * - get the index in the FORMAT column of error.get_field(), e.g. in GT:AC:AN, the index of AC is 1.
         *      if the field is not found, skip fix (copy as-is)
         * - for each sample column
         *      - put a "missing value" instead of the value in the index-th position after splitting by ":".
         *      - the "missing value" is a `.` repeated `n` times, where `n` is the cardinality of the field,
         *          with "," as separators, or "/" if the field is "GT"
         * - if there were no sample columns, skip fix (copy as-is)
         *
         * complete example:
         * field "AC", FORMAT: "GT:AC:AN", sample: "0/0:3,5:4"; becomes 0/0:.,.:4. (index = 1, cardinality = 2)
         * @param error
         */
        virtual void visit(SamplesFieldBodyError &error) override
        {
            if (error.get_field().empty()) {
                util::writeline(output, *line);
                ignored_errors++;
            } else {
                std::cerr << "DEBUG: line " << error.get_line() << ": fixing invalid sample field " << error.get_field()
                          << std::endl;

                const size_t format_column_index = 8;
//                size_t first_samples_column_index = 9;
                std::string string_line = {line->begin(), line->end()};

                size_t fixed_samples;
                std::string message;
                try {
                    using iter = std::vector<std::string>::iterator;
                    fixed_samples = fix_columns(
                            format_column_index, -1, string_line, "\t",
                            [&](iter first, iter last) {

                                size_t subfield_index = split_and_find(*first, ":", error.get_field());
                                if (subfield_index == first->npos) {
                                    std::cerr << "WARNING: line " << error.get_line() << ": tried to fix field "
                                              << error.get_field() << " but it was not present in the FORMAT column"
                                              << std::endl;
                                    ignored_errors++;
                                    util::print_container(output, std::vector<std::string>{first, last}, "", "\t", "");
                                    return;
                                }

                                if (subfield_index == 0) {
                                    fix_format_gt(first, last, error.get_field_cardinality());
                                } else {
                                    remove_format(first, last, subfield_index);
                                }
                            });
                } catch (std::out_of_range bad_range) {
                    // there were not enough lines
                    fixed_samples = 0;
                    message = bad_range.what();
                }

                if (fixed_samples <= 1) {   // 1 because we started counting since the FORMAT column
                    std::cerr << "WARNING: line " << error.get_line() << ": tried to fix field " << error.get_field()
                              << " in the samples column, but sample columns are not present. " << message << std::endl;
                    util::writeline(output, *line);
                    ignored_errors++;
                    return;
                }
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

        void fix_format_gt(std::vector<std::string>::iterator first,
                           std::vector<std::string>::iterator last,
                           long cardinality)
        {
            output << *first;   // write the FORMAT column

            const std::string field_separator = ":";
            size_t gt_column_index = 0;
            // if the field is GT, the values must use "/", as in "./."
            const std::string subfield_separator = "/";
            const char empty_subfield = '.';

            // `cardinality` should be -1 if the cardinality is unknown, and any positive number otherwise
            // so, if unknown, put 1, so that a single "." is written
            size_t repeat = cardinality <= -1 ? 1 : static_cast<size_t>(cardinality);

            // now `it` will point to each SAMPLE column
            for (auto it = ++first; it != last; ++it) {
                output << "\t";
                fix_column(gt_column_index, *it, field_separator, [&](std::string wrong_subfield) {
                    util::print_container(output, std::string(repeat, empty_subfield), "", subfield_separator, "");
                });
            }
        }

        void remove_format(std::vector<std::string>::iterator first,
                           std::vector<std::string>::iterator last,
                           size_t subfield_index)
        {

            const std::string field_separator = ":";
            std::vector<std::string> fields;

            for (; first != last; ++first) {
                util::string_split(*first, field_separator.c_str(), fields);

                auto it = fields.begin() + subfield_index;
                if (it >= fields.end()) {
                    throw std::out_of_range{"remove_format: asked to remove column " + std::to_string(subfield_index)
                                                    + " in string \"" + *first + "\" which has only "
                                                    + std::to_string(fields.size()) + " columns"};
                }
                fields.erase(it);

                util::print_container(output, fields, "", field_separator, "");

                if (first + 1 != last) {    // don't print separator in the last column
                    output << "\t";
                }
            }
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
                        std::string separator,
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
                        std::string separator,
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
                        std::string separator,
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

#endif //VCF_VALIDATOR_FIXER_HPP
