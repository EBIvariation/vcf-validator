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
#include <odb/database.hxx>
#include <odb/sqlite/query.hxx>
#include <odb/schema-catalog.hxx>
#include <odb/sqlite/database.hxx>
#include <fstream>

#include "util/logger.hpp"
#include "vcf/error.hpp"
#include "vcf/error-odb.hpp"
#include "vcf/string_constants.hpp"
#include "vcf/vcf_fasta_variant.hpp"

namespace ebi
{
  namespace vcf
  {

    class AssemblyReportWriter
    {
      public:
        virtual void write_mismatch(const vcf::Record_Core &record_core) = 0;
        virtual void write_match(const vcf::Record_Core &record_core) = 0;

        virtual void finish_report()
        {
            BOOST_LOG_TRIVIAL(info) << "Number of matches: " << match_stats.get_num_matches() << "/" << match_stats.get_num_variants();
            BOOST_LOG_TRIVIAL(info) << "Percentage of matches: " << (static_cast<double>(match_stats.get_num_matches()) / match_stats.get_num_variants()) * 100 << "%";
        }

        bool is_valid_report() {
            return match_stats.is_assembly_match();
        }

      protected:
        MatchStats match_stats;
    };

    class SummaryAssemblyReportWriter : public AssemblyReportWriter
    {
      public:
        SummaryAssemblyReportWriter(){}

        void write_mismatch(const vcf::Record_Core &record_core)
        {
            match_stats.add_match_result(false);
        }

        void write_match(const vcf::Record_Core &record_core)
        {
            match_stats.add_match_result(true);
        }
    };

    class TextAssemblyReportWriter : public AssemblyReportWriter
    {
      public:
        TextAssemblyReportWriter(std::string filename, std::string type) : file_name(filename) , report_type(type)
        {
            file.open(filename, std::ios::out);
            if(!file) {
                throw std::runtime_error{"Unable to write output file " + file_name};
            }
        }

        ~TextAssemblyReportWriter()
        {
            file.close();
        }

        virtual void write_mismatch(const vcf::Record_Core &record_core) override
        {
            match_stats.add_match_result(false);
            if(report_type == ebi::vcf::INVALID) {
                file << record_core.line;
            }
        }

        virtual void write_match(const vcf::Record_Core &record_core) override
        {
            match_stats.add_match_result(true);
            if(report_type == ebi::vcf::VALID) {
                file << record_core.line;
            }
        }

      private:
        std::ofstream file;
        std::string file_name;
        std::string report_type;
    };
  }
}


#endif // ASSEMBLY_REPORT_WRITER_HPP
