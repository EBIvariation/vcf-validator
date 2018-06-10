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

#ifndef ASSEMBLY_REPORT_WRITER_HPP
#define ASSEMBLY_REPORT_WRITER_HPP

#include <boost/filesystem/operations.hpp>
#include "vcf/assembly_checker.hpp"

namespace ebi
{
  namespace vcf
  {
    class AssemblyReportWriter
    {
        public:
            virtual void write_number_matches(ebi::vcf::assembly_checker::MatchStats &match_stats) = 0;
            virtual void write_percentage(ebi::vcf::assembly_checker::MatchStats &match_stats) = 0;
    };

    class StdoutAssemblyReportWriter : public AssemblyReportWriter
    {
        public:

            virtual void write_number_matches(ebi::vcf::assembly_checker::MatchStats &match_stats) override
            {
                BOOST_LOG_TRIVIAL(info) << "Number of matches: " << match_stats.num_matches << "/" << match_stats.num_variants;
            }

            virtual void write_percentage(ebi::vcf::assembly_checker::MatchStats &match_stats) override
            {
                BOOST_LOG_TRIVIAL(info) << "Percentage of matches: " << (static_cast<double>(match_stats.num_matches) / match_stats.num_variants) * 100 << "%";
            }

    };

    class OdbAssemblyReportWriter : public AssemblyReportWriter
    {
        public:

        	OdbAssemblyReportWriter(const std::string &db_name)
        	{

        	}
            virtual void write_number_matches(ebi::vcf::assembly_checker::MatchStats &match_stats) override
            {

            }
            virtual void write_percentage(ebi::vcf::assembly_checker::MatchStats &match_stats) override
            {

            }

    };

  }
}


#endif // ASSEMBLY_REPORT_WRITER_HPP
