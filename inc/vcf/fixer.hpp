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
            const int info_column_index = 7;
            const std::string empty_info_column = ".";

            int num_removed_subfields = 0;
            std::string string_line = {line->begin(), line->end()};

            fix_column(info_column_index, string_line, "\t", [&](std::string &info_column) {
                std::vector<std::string> info_subfields, keys_values;
                util::string_split(info_column, ";", info_subfields);

                for (size_t j = 0; j < info_subfields.size(); ++j) {
                    util::string_split(info_subfields[j], "=", keys_values);
                    if (keys_values[0] != error.get_field()) {
                        if ((num_removed_subfields - j) != 0) {
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
         * splits a line and allows to rewrite one of the columns, copying the other columns into "output"
         * @param column_index: index to the column to modify
         * @param line: whole line that will be split
         * @param separator: will be used to split the line
         * @param fix_function: takes a string, which is the column to fix. this function must write to the member "output"
         */
        void fix_column(size_t column_index,
                        const std::string &line,
                        std::string separator,
                        std::function<void(std::string &column)> fix_function) {

            std::vector<std::string> columns;
            util::string_split(line, "\t", columns);
            for (size_t i = 0; i < column_index; ++i) {
                output << columns[i] << "\t";
            }

            fix_function(columns[column_index]);

            for (size_t i = column_index+1; i < columns.size(); ++i) {
                output << "\t" << columns[i];
            }
        }
    };
  }
}

#endif //VCF_VALIDATOR_FIXER_HPP
