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

#ifndef VCF_VALIDATOR_SQLITE_REPORT_HPP
#define VCF_VALIDATOR_SQLITE_REPORT_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <chrono>
#include <thread>
#include "sqlite/sqlite3.h"
#include "vcf/error.hpp"
#include "report_writer.hpp"
#include "report_reader.hpp"

namespace ebi
{
  namespace vcf
  {
    class SqliteReportRW : public ReportWriter, public ReportReader
    {
      public:
        SqliteReportRW(std::string db_name);
        void close();
        ~SqliteReportRW();
        
        // ReportWriter implementation
        void write_error(const Error &error) override;
        void write_warning(const Error &error) override;
        
        // ReportReader implementation
        size_t count_errors() override;
        Error read_error() override;
        size_t count_warnings() override;
        Error read_warning() override;
        
      private:
        void write(const Error &error, std::string table);
        size_t count(std::string table);
        void start_transaction();
        void commit_transaction();
        void rollback_transaction();

        sqlite3* db;
        std::string db_name;
        size_t current_transaction_size;
        const size_t transaction_size;
        const std::chrono::milliseconds sleep_time;
    };
  }
}


#endif //VCF_VALIDATOR_SQLITE_REPORT_HPP
