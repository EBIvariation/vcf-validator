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


#include <boost/shared_ptr.hpp>
#include "error.hpp"

namespace ebi
{
  namespace vcf
  {
    class Fixer : ErrorVisitor {
      public:
        Fixer(size_t line_number, std::vector<char> &line, std::ostream &output)
                : line_number(line_number), line(line), output(output) { }

        void fix(Error &error)
        {
            error.apply_visitor(*this);
        }

      private:
        size_t line_number;
        std::vector<char> &line;
        std::ostream &output;

        virtual void visit(Error &error) override
        {
            throw std::runtime_error{"visit(Error &error) unimplemented"};
        }
        virtual void visit(MetaSectionError &error) override
        {
            throw std::runtime_error{"visit(MetaSectionError &error) unimplemented"};
        }
        virtual void visit(HeaderSectionError &error) override
        {
            throw std::runtime_error{"visit(HeaderSectionError &error) unimplemented"};
        }
        virtual void visit(BodySectionError &error) override
        {
            throw std::runtime_error{"visit(BodySectionError &error) unimplemented"};
        }
        virtual void visit(FileformatError &error) override
        {
            throw std::runtime_error{"visit(FileformatError &error) unimplemented"};
        }
        virtual void visit(ChromosomeBodyError &error) override
        {
            throw std::runtime_error{"visit(ChromosomeBodyError &error) unimplemented"};
        }
        virtual void visit(PositionBodyError &error) override
        {
            throw std::runtime_error{"visit(PositionBodyError &error) unimplemented"};
        }
        virtual void visit(IdBodyError &error) override
        {
            throw std::runtime_error{"visit(IdBodyError &error) unimplemented"};
        }
        virtual void visit(ReferenceAlleleBodyError &error) override
        {
            throw std::runtime_error{"visit(ReferenceAlleleBodyError &error) unimplemented"};
        }
        virtual void visit(AlternateAllelesBodyError &error) override
        {
            throw std::runtime_error{"visit(AlternateAllelesBodyError &error) unimplemented"};
        }
        virtual void visit(QualityBodyError &error) override
        {
            throw std::runtime_error{"visit(QualityBodyError &error) unimplemented"};
        }
        virtual void visit(FilterBodyError &error) override
        {
            throw std::runtime_error{"visit(FilterBodyError &error) unimplemented"};
        }
        virtual void visit(InfoBodyError &error) override
        {
            throw std::runtime_error{"visit(InfoBodyError &error) unimplemented"};
        }
        virtual void visit(FormatBodyError &error) override
        {
            throw std::runtime_error{"visit(FormatBodyError &error) unimplemented"};
        }
        virtual void visit(SamplesBodyError &error) override
        {
            throw std::runtime_error{"visit(SamplesBodyError &error) unimplemented"};
        }
        virtual void visit(NormalizationError &error) override
        {
            throw std::runtime_error{"visit(NormalizationError &error) unimplemented"};
        }
        virtual void visit(DuplicationError &error) override
        {
            std::cout << "fixing duplicate: removing line " << line_number << std::endl;
        }
    };
  }
}

#endif //VCF_VALIDATOR_FIXER_HPP
