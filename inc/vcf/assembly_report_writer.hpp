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

#include <fstream>

#include <boost/filesystem/operations.hpp>

#include <odb/database.hxx>
#include <odb/sqlite/query.hxx>
#include <odb/schema-catalog.hxx>
#include <odb/sqlite/database.hxx>


#include "vcf/error.hpp"
#include "vcf/error-odb.hpp"
#include "vcf/normalizer.hpp"
#include "vcf/string_constants.hpp"
#include "util/logger.hpp"

namespace ebi
{
  namespace vcf
  {

    class AssemblyReportWriter
    {
      public:
        virtual ~AssemblyReportWriter()
        {

        }

        virtual void match(std::string &vcf_line)
        {

        }

        virtual void mismatch(const vcf::RecordCore &record_core,
                              std::string &vcf_line,
                              size_t line_num,
                              std::string &fasta_sequence)
        {

        }

        virtual void write_warning(std::string &warning)
        {

        }

      protected:
        /*
         * creating protected constructor to make class abstract instead of using pure virtual functions
         */
        AssemblyReportWriter()
        {

        }
    };

    class SummaryAssemblyReportWriter : public AssemblyReportWriter
    {
      public:
        SummaryAssemblyReportWriter()
        {

        }

        ~SummaryAssemblyReportWriter()
        {
            BOOST_LOG_TRIVIAL(info) << "Number of matches: "
                << match_stats.get_num_matches() << "/" << match_stats.get_num_variants();
            BOOST_LOG_TRIVIAL(info) << "Percentage of matches: "
                << (static_cast<double>(match_stats.get_num_matches()) / match_stats.get_num_variants()) * 100 << "%";
        }

        virtual void match(std::string &vcf_line) override
        {
            match_stats.add_match_result(true);
        }

        virtual void mismatch(const vcf::RecordCore &record_core,
                              std::string &vcf_line,
                              size_t line_num,
                              std::string &fasta_sequence) override
        {
            match_stats.add_match_result(false);
        }

      private:
        MatchStats match_stats;
    };

    // TODO: the "valid" report should include the header. this report should not be used until then.
    class ValidAssemblyReportWriter : public AssemblyReportWriter
    {
      public:
        ValidAssemblyReportWriter(std::string filename) : file_name(filename)
        {
            file.open(filename, std::ios::out);
            if(!file) {
                throw std::runtime_error{"Unable to write output file " + file_name};
            }
        }

        ~ValidAssemblyReportWriter()
        {
            file.close();
        }

        virtual void match(std::string &vcf_line) override
        {
            file << vcf_line;
        }

      private:
        std::ofstream file;
        std::string file_name;
    };

    class TextAssemblyReportWriter : public AssemblyReportWriter
    {
      public:
        TextAssemblyReportWriter(std::string filename) : file_name(filename)
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

        virtual void mismatch(const vcf::RecordCore &record_core,
                              std::string &vcf_line,
                              size_t line_num,
                              std::string &fasta_sequence) override
        {
            std::string mismatch_result = "Line " + std::to_string(line_num)
                + ": Chromosome " + record_core.chromosome
                + ", position " + std::to_string(record_core.position)
                + ", reference allele \'" + record_core.reference_allele
                + "\' does not match the reference sequence, expected \'"
                + fasta_sequence + "\'";
            file << mismatch_result << std::endl;
        }

        virtual void write_warning(std::string &warning) override
        {
            file << warning << std::endl;
        }

      private:
        std::ofstream file;
        std::string file_name;
    };
  }
}


#endif // ASSEMBLY_REPORT_WRITER_HPP
