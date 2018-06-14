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
#include "vcf/error.hpp"
#include "vcf/vcf_fasta_variant.hpp"
#include "vcf/assembly_report_reader.hpp"
#include <odb/database.hxx>
#include <odb/sqlite/query.hxx>
#include <odb/schema-catalog.hxx>
#include <odb/sqlite/database.hxx>
#include "vcf/error-odb.hpp"
#include "util/logger.hpp"
#include "vcf/assembly_report_reader.hpp"

namespace ebi
{
  namespace vcf
  {   

    class AssemblyReportWriter
    {
      public:
        virtual void write_results() = 0;
        virtual void add_result(bool result, const vcf::VcfVariant &vcf_variant) = 0;

      private:
        virtual void write_mismatch(const vcf::VcfVariant &vcf_variant) = 0;
        virtual void write_match(const vcf::VcfVariant &vcf_variant) = 0;
        
    };

    class SummaryAssemblyReportWriter : public AssemblyReportWriter
    {
      public:
        virtual void write_results() override;
        virtual void add_result(bool result, const vcf::VcfVariant &vcf_variant) override;

      private:
        virtual void write_mismatch(const vcf::VcfVariant &vcf_variant) override;
        virtual void write_match(const vcf::VcfVariant &vcf_variant) override;
    	  
        MatchStats match_stats;
    };

    class OdbAssemblyReportRW : public AssemblyReportWriter, public AssemblyReportReader
    {
      public:
    	  OdbAssemblyReportRW(const std::string &db_name);
    	  ~OdbAssemblyReportRW();
        virtual void write_results() override;
        virtual void add_result(bool result, const vcf::VcfVariant &vcf_variant) override;
        virtual size_t count_entry() override;
        virtual void for_each_entry(std::function<void(std::shared_ptr<MatchStats>)> user_function) override;

      private:
        virtual void write_mismatch(const vcf::VcfVariant &vcf_variant) override;
        virtual void write_match(const vcf::VcfVariant &vcf_variant) override;
        void for_each(std::function<void(std::shared_ptr<MatchStats>)> user_function, odb::query<MatchStats> query);
        void flush();
        size_t count(odb::query<MatchStatsCount> query);
    	  
        MatchStats match_stats;
    	  std::string db_name;
        std::unique_ptr<odb::core::database> db;
        odb::core::transaction transaction;
        size_t current_transaction_size;
        const size_t transaction_size;
    };

  }
}


#endif // ASSEMBLY_REPORT_WRITER_HPP
