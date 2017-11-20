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
     * Stores the count and first line of occurrence of an error message
     */
    struct ErrorSummary
    {
      size_t occurrences;
      size_t first_occurrence_line;
    };

    /**
     * Class that ensures similar kind of errors are reported only once.
     *
     * The intended algorithm is that errors and warnings will be printed only the first time they occur, and won't
     * be printed again.
     *
     * The summary displays the count(number of times it occurs) of the error, and the line number of its first
     * occurrence. We distinguish between different types of errors based on their simple error message (which contains
     * no details). The `error_order` basically maintains the order in which these errors appear for the first time.
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
                error_summary_report[error_message].occurrences++;
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

        virtual void write_error(Error &error) override
        {
            summary.add_to_summary("Error: " + error.message, error.line);
        }

        virtual void write_warning(Error &error) override
        {
            summary.add_to_summary("Warning: " + error.message, error.line);
        }

        virtual void write_message(const std::string &report_result) override
        {
            this->report_result = report_result;
        }

      private:
        SummaryTracker summary;
        std::string report_result;
        std::ofstream file;

        void write_summary()
        {
            file << report_result << std::endl;

            for (auto & error_message : summary.error_order) {
                file << error_message << ". This occurs " << summary.error_summary_report[error_message].occurrences
                     << " time(s), first time in line " << summary.error_summary_report[error_message].first_occurrence_line << "." << std::endl;
            }
        }
    };
  }
}

#endif // VCF_SUMMARY_REPORT_WRITER_HPP
