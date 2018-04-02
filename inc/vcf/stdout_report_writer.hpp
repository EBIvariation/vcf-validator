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

#ifndef VCF_STDOUT_REPORT_WRITER_HPP
#define VCF_STDOUT_REPORT_WRITER_HPP

#include <string>

#include "report_writer.hpp"
#include "vcf/error.hpp"


namespace ebi
{
  namespace vcf
  {
    class StdoutReportWriter : public ReportWriter
    {
        public:
            StdoutReportWriter() {}

            ~StdoutReportWriter() {}

            virtual void write_error(Error &error) override
            {
                std::cout << error.what() << std::endl;
            }

            virtual void write_warning(Error &error) override
            {
                std::cout << error.what() << " (warning)" << std::endl;
            }

            virtual void write_message(const std::string &report_result) override
            {
                std::cout << report_result << std::endl;
            }

            virtual void show_report_message() override
            {

            }
    };
  }
}

#endif // VCF_STDOUT_REPORT_WRITER_HPP
