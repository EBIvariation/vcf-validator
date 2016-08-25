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
            int fixed = 0;

            std::vector<std::string> columns;
            std::string string_line{line->begin(), line->end()};
            util::string_split(string_line, "\t", columns);
            std::vector<std::string> infos;
            util::string_split(columns[7], ";", infos);

            for (size_t i = 0; i < 7; ++i) {
                output << columns[i] << "\t";
            }
            std::vector<std::string> key_value;
            for (size_t j = 0; j < infos.size(); ++j) {
                util::string_split(infos[j], "=", key_value);
                if (key_value[0] != error.get_field()) {
                    if ((fixed - j) != 0) { // if this is not the first field we don't remove, then write the separator
                        output << ";";
                    }
                    output << infos[j];
                } else {
                    fixed++;
                }
            }

            if (fixed == infos.size()) {
                output << ".";
            }
            for (size_t i = 8; i < columns.size(); ++i) {
                output << "\t" << columns[i];
            }
            if (fixed != 1) {
                std::cerr << "WARNING: line " << error.get_line() << ": field " << error.get_field() << " appeared "
                          << fixed << " times " << std::endl;
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
    };
  }
}

#endif //VCF_VALIDATOR_FIXER_HPP
