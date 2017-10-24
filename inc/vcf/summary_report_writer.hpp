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

#ifndef VCF_SUMMARY_REPORT_WRITER_HPP
#define VCF_SUMMARY_REPORT_WRITER_HPP

#include <map>
#include "report_writer.hpp"

namespace ebi
{
  namespace vcf
  {
    /**
     * Class that tells whether an error should be written or skipped.
     *
     * The intended algorithm is that all errors will be printed the first time they appear, but some of them won't
     * be printed again.
     *
     * To differentiate the Error dynamic type, this class implements ErrorVisitor. As the visitor interface returns
     * `void`, we have to store the decision in the class' state, in the variable `skip`.
     *
     * Use this class like this:
     * ~~~
     * if (summary.should_write_report(error)) {
     *     std::cout << error.what() << " (warning)" << std::endl;
     * }
     * ~~~
     */
    class SummaryTracker : public ErrorVisitor
    {
      public:
        SummaryTracker() : already_reported{}, skip{false} {}

        bool should_write_report(Error &error)
        {
            error.apply_visitor(*this);
            return not skip;
        }


        virtual void visit(Error &error) {}
        virtual void visit(MetaSectionError &error) {}
        virtual void visit(HeaderSectionError &error) {}
        virtual void visit(BodySectionError &error) {}
        virtual void visit(NoMetaDefinitionError &error)
        {
            if (is_already_reported(error.column, error.field)) {
                skip = true;
            } else {
                add_already_reported(error.column, error.field);
                skip = false;
            }
        }
        virtual void visit(FileformatError &error) {}
        virtual void visit(ChromosomeBodyError &error) {}
        virtual void visit(PositionBodyError &error) {}
        virtual void visit(IdBodyError &error) {}
        virtual void visit(ReferenceAlleleBodyError &error) {}
        virtual void visit(AlternateAllelesBodyError &error) {}
        virtual void visit(QualityBodyError &error) {}
        virtual void visit(FilterBodyError &error) {}
        virtual void visit(InfoBodyError &error) {}
        virtual void visit(FormatBodyError &error) {}
        virtual void visit(SamplesBodyError &error) {}
        virtual void visit(SamplesFieldBodyError &error) {}
        virtual void visit(NormalizationError &error) {}
        virtual void visit(DuplicationError &error) {}

      private:
        bool is_already_reported(std::string const &meta_type, std::string const &id) const
        {
            typedef std::multimap<std::string,std::string>::const_iterator iter;
            std::pair<iter, iter> range = already_reported.equal_range(meta_type);
            for (auto & current = range.first; current != range.second; ++current) {
                if (current->second == id) {
                    return true;
                }
            }
            return false;
        }

        void add_already_reported(std::string const &meta_type, std::string const &id)
        {
            already_reported.emplace(meta_type, id);
        }

        std::multimap<std::string, std::string> already_reported;
        bool skip;
    };



    /**
     * Implements a ReportWriter that writes to a file, but small warnings are written only once.
     */
    class SummaryReportWriter : public ReportWriter
    {
      public:
        SummaryReportWriter(std::string filename)
        {
            fout.open(filename, std::ios::out);
        }

        ~SummaryReportWriter()
        {
            fout.close();
        }

        virtual void write_error(Error &error)
        {
            fout << error.what() << std::endl;
        }

        virtual void write_warning(Error &error)
        {
            if (summary.should_write_report(error)) {
                fout << error.what() << " (warning)" << std::endl;
            }
        }

      private:
        SummaryTracker summary;
        std::ofstream fout;
    };
  }
}

#endif // VCF_SUMMARY_REPORT_WRITER_HPP
