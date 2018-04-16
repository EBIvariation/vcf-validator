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

#ifndef VCF_ODB_REPORT_HPP
#define VCF_ODB_REPORT_HPP


#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>
#include <odb/database.hxx>
#include <odb/sqlite/query.hxx>
#include <odb/schema-catalog.hxx>
#include <odb/sqlite/database.hxx>

#include "vcf/report_writer.hpp"
#include "vcf/report_reader.hpp"
#include "vcf/error-odb.hpp"

namespace ebi
{
  namespace vcf
  {
    class OdbReportRW : public ReportWriter, public ReportReader
    {
      public:

        OdbReportRW(const std::string &db_name);
        virtual ~OdbReportRW();
        void flush();   // before reading, make sure you destroy or flush the writer OdbReportRW

        // ReportWriter implementation
        virtual void write_error(Error &error) override;
        virtual void write_warning(Error &error) override;
        virtual void write_message(const std::string &message) override;

        // ReportReader implementation
        virtual size_t count_warnings() override;
        virtual void for_each_warning(std::function<void(std::shared_ptr<Error>)> user_function) override;
        virtual size_t count_errors() override;
        virtual void for_each_error(std::function<void(std::shared_ptr<Error>)> user_function) override;

        virtual std::string get_filename() override;

      private:
        std::string db_name;
        std::unique_ptr<odb::core::database> db;
        odb::core::transaction transaction;
        size_t current_transaction_size;
        const size_t transaction_size;

        void write(Error &error);
        void for_each(std::function<void(std::shared_ptr<Error>)> user_function, odb::query<Error> query);
        size_t count(odb::query<ErrorCount> query);
    };
  }
}


#endif // VCF_ODB_REPORT_HPP
