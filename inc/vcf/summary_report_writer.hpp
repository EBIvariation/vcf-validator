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
     * Stores the count and first line of appearance of an error message
     */
    struct ErrorSummary
    {
      size_t appearances;
      size_t first_appearance_line;
    };

    /**
     * Class that ensures similar kind of errors are reported only once.
     *
     * The intended algorithm is that errors and warnings will be printed only the first time they appear, and won't
     * be printed again.
     *
     * The summary diplays the count(number of times it appears) of the error, and the line number of it's first
     * occurrence. We distinguish between different types of errors based on their simple error message (which contains
     * no details). The `error_order` basically maintains the order in which these errors appaer for the first time.
     *
     * Use this class like this:
     * ~~~
     * summary.add_to_summary(error.message, error.line);
     * ~~~
     */
    class SummaryTracker
    {
      public:
        std::map<std::string, ErrorSummary> error_summary_report;
        std::vector<std::string> error_order;

        void add_to_summary(std::string const & error_message, size_t error_line)
        {
            if (error_summary_report.find(error_message) == error_summary_report.end()) {
                error_order.push_back(error_message);
                error_summary_report[error_message] = ErrorSummary{1, error_line};
            } else {
                error_summary_report[error_message].appearances++;
            }
        }
   };

    /**
     * Implements a ReportWriter that writes to a file, but only the summary is written
     */
    class SummaryReportWriter : public ReportWriter
    {
      public:
        SummaryReportWriter(std::string filename)
        {
            file.open(filename, std::ios::out);
        }

        ~SummaryReportWriter()
        {
            write_summary();
            file.close();
        }

        virtual void write_error(Error &error)
        {
            summary.add_to_summary(error.message, error.line);
        }

        virtual void write_warning(Error &error)
        {
            summary.add_to_summary(error.message + " (warning)", error.line);
        }

      private:
        SummaryTracker summary;
        std::ofstream file;

        void write_summary()
        {
            for (auto & error_message : summary.error_order) {
                file << error_message << ". This occurs " << summary.error_summary_report[error_message].appearances
                     << " time(s), first time in line " << summary.error_summary_report[error_message].first_appearance_line << std::endl;
            }
        }
    };
  }
}

#endif // VCF_SUMMARY_REPORT_WRITER_HPP
