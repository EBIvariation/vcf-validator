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

#include "util/logger.hpp"
#include "vcf/odb_report.hpp"

namespace ebi
{
  namespace vcf
  {
    OdbReportRW::OdbReportRW(const std::string &db_name) : db_name(db_name), current_transaction_size{0},
                                                           transaction_size{1000000}
    {
        try {
            boost::filesystem::path db_file{db_name};
            if (boost::filesystem::exists(db_file)) {
                db = std::unique_ptr<odb::sqlite::database> (
                        new odb::sqlite::database{
                                db_name, SQLITE_OPEN_READWRITE});
            } else {
                // if the file doesn't exist, create database and schema
                db = std::unique_ptr<odb::sqlite::database>(
                        new odb::sqlite::database{
                                db_name, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE});

                // Create the database schema. Due to bugs in SQLite foreign key
                // support for DDL statements, we need to temporarily disable
                // foreign keys.
                //
                {
                    odb::core::connection_ptr c{db->connection()};

                    c->execute("PRAGMA foreign_keys=OFF");

                    odb::core::transaction t{c->begin()};
                    odb::core::schema_catalog::create_schema(*db);
                    t.commit();

                    c->execute("PRAGMA foreign_keys=ON");
                }
            }
        } catch (const odb::exception& e) {
            throw std::runtime_error{std::string{"ODB report: Can't initialize database: "} + e.what()};
        }

    }

    OdbReportRW::~OdbReportRW()
    {
        try {
            flush();
        } catch (std::exception &e) {
            BOOST_LOG_TRIVIAL(error) << "An error occurred finalizing the error reporting: " << e.what();
        }
    }

    void OdbReportRW::flush()
    {
        // possible recovery can be done here, ODB rollbacks automatically on error, and throws.
        if (transaction.has_current()) {
            transaction.commit();
        }

        {
            odb::core::connection_ptr c{db->connection()};
            c->execute("PRAGMA shrink_memory");
        }
    }

    // ReportWriter implementation
    void OdbReportRW::write_error(Error &error)
    {
        error.severity = Severity::ERROR;
        write(error);
    }
    void OdbReportRW::write_warning(Error &error)
    {
        error.severity = Severity::WARNING;
        write(error);
    }

    void OdbReportRW::write(Error &error)
    {
        if (current_transaction_size == 0) {
            // start transaction
            transaction.reset(db->begin());
        }

        db->persist(error);

        ++current_transaction_size;
        if (current_transaction_size == transaction_size) {
            // commit transaction
            flush();
            current_transaction_size = 0;
        }
    }

    // ReportReader implementation
    size_t OdbReportRW::count_warnings()
    {
        return count(odb::query<ErrorCount>::severity == Severity::WARNING);
    }
    void OdbReportRW::for_each_warning(std::function<void(std::shared_ptr<Error>)> user_function)
    {
        for_each(user_function, odb::query<Error>::severity == Severity::WARNING);
    }

    size_t OdbReportRW::count_errors()
    {
        return count(odb::query<ErrorCount>::severity == Severity::ERROR);
    }
    void OdbReportRW::for_each_error(std::function<void(std::shared_ptr<Error>)> user_function)
    {
        for_each(user_function, odb::query<Error>::severity == Severity::ERROR);
    }

    size_t OdbReportRW::count(odb::query<ErrorCount> query)
    {
        ErrorCount count;
        if (transaction.has_current()) {
            throw std::logic_error{"There's another transaction active. You can only read if the changes were flushed"};
        } else {
            transaction.reset(db->begin());
//        size_t count = db->execute("SELECT COUNT(*) FROM Error");
            count = db->query_value<ErrorCount>(query);
            flush();
        }
        return count.count;
    }
    void OdbReportRW::for_each(std::function<void(std::shared_ptr<Error>)> user_function, odb::query<Error> query)
    {
        typedef odb::result<Error> result_t;

        if (transaction.has_current()) {
            throw std::logic_error{"There's another transaction active. You can only read if the changes were flushed"};
        } else {
            transaction.reset(db->begin());

            result_t result{db->query<Error>(query + " ORDER BY " + odb::query<Error>::line)};

            for (result_t::iterator it{result.begin()}; it != result.end(); ++it) {
                user_function(std::shared_ptr<ebi::vcf::Error>{it.load()});
            }

            transaction.commit();
        }
    }
  }
}
