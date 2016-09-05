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

        /**
         * explanation of the fix:
         * - in error.get_field there will be the field name as it appears in the FORMAT column, e.g. "GT".
         * - don't do anything if error.get_field() is empty
         * - get the index in the FORMAT column of error.get_field(), e.g. in GT:AC:AN, the index of AC is 1.
         * - for each sample column
         *      - put a "." instead of the value in the index-th position of ":" e.g. 0/0:3:4 becomes 0/0:.:4 for index = 1
         * @param error
         */
        virtual void visit(SamplesBodyError &error) override
        {
            if (error.get_field().empty()) {
                util::writeline(output, *line);
                ignored_errors++;
            } else {
                std::cerr << "DEBUG: line " << error.get_line() << ": fixing invalid sample field " << error.get_field()
                          << std::endl;

                const size_t format_column = 8;
//                size_t first_samples_column = 9;
                const char empty_subfield = '.';
                std::string string_line = {line->begin(), line->end()};

                using iter = std::vector<std::string>::iterator;
                size_t fixed_samples = fix_columns(format_column, -1, string_line, "\t", [&](iter first, iter last) {

                    size_t subfield_index = split_and_find(*first, ":", error.get_field());
                    if (subfield_index == first->npos) {
                        std::cerr << "WARNING: line " << error.get_line() << ": tried to fix field "
                                  << error.get_field() << " but it was not present in the FORMAT column";
                        ignored_errors++;
                        return;
                    }
                    output << *first;   // write the FORMAT column

                    // if the field is GT, the values must use "/", as in "./."
                    const std::string subfield_separator = subfield_index == 0? "/" : ",";

                    // error.number should be -1 if the cardinality is unknown, and any positive number otherwise
                    // so, if unknown, put 1, so that a single "." is written
                    size_t number = error.get_field_cardinality() <= -1? 1 : static_cast<size_t>(error.get_field_cardinality());

                    // now `it` will point to each SAMPLE column
                    for(auto it = ++first; it != last; ++it) {
                        output << "\t";
                        fix_column(subfield_index, *it, ":", [&](std::string wrong_subfield) {
                            util::print_container(output, std::string(number, empty_subfield), "", subfield_separator, "");
                        });
                    }
                });

                if (fixed_samples <= 1) {   // 1 because we started counting since the FORMAT column
                    std::cerr << "WARNING: line " << error.get_line() << ": tried to fix field " << error.get_field()
                              << " in the samples column, but sample columns are not present" << std::endl;
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

        size_t split_and_find(std::string line, std::string separator, std::string value) {
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

            return fix_foreach_column(column_index, column_index + 1, line, separator, fix_function);
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
                eol = "\n";
            }

            size_t column_index_last_unsigned;
            if (column_index_last < 0) {
                column_index_last_unsigned = columns.size();
            } else {
                // column_index_last is non-negative. ensure the requested index is in a valid range
                column_index_last_unsigned = std::min(static_cast<size_t>(column_index_last), columns.size());
            }
            column_index = std::min(column_index, columns.size());  // ensure the requested index is in a valid range

            for (size_t i = 0; i < column_index; ++i) {
                output << columns[i] << separator;
            }

            fix_function(columns.begin() + column_index, columns.begin() + column_index_last_unsigned);

            for (size_t i = column_index_last_unsigned; i < columns.size(); ++i) {
                output << separator << columns[i];
            }

            output << eol;

            return column_index_last - column_index;
        }
    };
  }
}

#endif //VCF_VALIDATOR_FIXER_HPP
