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
        
        virtual ~Fixer() { }

        void fix(size_t line_number, std::vector<char> &line, Error &error);

        size_t get_ignored_errors();

      private:
        size_t line_number;
        std::vector<char> *line;
        std::ostream &output;
        size_t ignored_errors;

        virtual void visit(Error &error) override;
        virtual void visit(MetaSectionError &error) override;
        virtual void visit(HeaderSectionError &error) override;
        virtual void visit(BodySectionError &error) override;
        virtual void visit(NoMetaDefinitionError &error) override;
        virtual void visit(FileformatError &error) override;
        virtual void visit(ChromosomeBodyError &error) override;
        virtual void visit(PositionBodyError &error) override;
        virtual void visit(IdBodyError &error) override;
        virtual void visit(ReferenceAlleleBodyError &error) override;
        virtual void visit(AlternateAllelesBodyError &error) override;
        virtual void visit(QualityBodyError &error) override;
        virtual void visit(FilterBodyError &error) override;
        /**
         * fix: remove the info field that caused the error
         */
        virtual void visit(InfoBodyError &error) override;
        virtual void visit(FormatBodyError &error) override;
        virtual void visit(SamplesBodyError &error) override;

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
        virtual void visit(SamplesFieldBodyError &error) override;
        virtual void visit(NormalizationError &error) override;
        virtual void visit(DuplicationError &error) override;

      protected:

        /**
         * puts the genotype as missing. if the error.cardinality is know, it uses the proper ploidy
         * @param first iterator to the FORMAT column string
         * @param last iterator past the last sample column
         * @param error needed for the field (that must be "GT") the cardinality, and the line number
         */
        void fix_format_gt(std::vector<std::string>::iterator first,
                           std::vector<std::string>::iterator last,
                           SamplesFieldBodyError &error);
        /**
         * remove a field from the FORMAT column and the samples columns
         * @param first iterator to the FORMAT column string
         * @param last iterator past the last sample column
         * @param error needed for the field the cardinality, and the line number
         */
        void remove_format(std::vector<std::string>::iterator first,
                           std::vector<std::string>::iterator last,
                           SamplesFieldBodyError &error);

        size_t remove_column(const std::string &line,
                             const std::string &separator,
                             std::function<bool(std::string &column, size_t index)> condition_to_remove);

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
                             std::function<bool(std::string &column, size_t index)> condition_to_remove);

        /**
         * returns an index (NOT an iterator) to the column in `line` (split by `separator`) where `value` is found. Or `line.npos`
         * if value is not found.
         * @param line to be split
         * @param separator to use when splitting the line
         * @param value to search
         * @return an index (not an iterator) if found, or `line.npos` if not found.
         */
        size_t split_and_find(const std::string &line, const std::string &separator, const std::string &value);

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
                        std::function<void(std::string &column)> fix_function);

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
                        std::function<void(std::string &column)> fix_function);

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
                                           std::vector<std::string>::iterator end)> fix_function);
    };
  }
}

#endif // VCF_FIXER_HPP
