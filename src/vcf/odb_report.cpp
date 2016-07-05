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


#include "vcf/odb_report.hpp"

#include <memory>
#include <odb/database.hxx>
#include <odb/transaction.hxx>
#include <odb/connection.hxx>
#include <odb/transaction.hxx>
#include <odb/schema-catalog.hxx>
#include <odb/sqlite/database.hxx>
#include "vcf/error-odb.hxx"

namespace ebi
{
  namespace vcf
  {
    OdbReportRW::OdbReportRW(const std::string &db_name) : db_name(db_name), current_transaction_size{0},
                                                          transaction_size{1000000}
    {
        try {
            db = std::unique_ptr<odb::sqlite::database> (
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
        } catch (const odb::exception& e) {
            throw std::runtime_error{std::string{"ODB report: failed ODB initialization: "} + e.what()};
        }
    }

    OdbReportRW::~OdbReportRW()
    {
        try {
            flush();
        } catch (std::exception &e) {
            std::cerr << "An error occurred finalizing the error reporting: " << e.what() << std::endl;
        }
    }

    void OdbReportRW::flush()
    {
        // possible recovery can be done here
        if (transaction.has_current()) {
            transaction.commit();
        }
    }

    // ReportWriter implementation
    void OdbReportRW::write_error(Error &error)
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
    void OdbReportRW::write_warning(Error &error)
    {
        std::cerr << "OdbReportRW::write_warning unimplemented" << std::endl;
    }

    // ReportReader implementation
    size_t OdbReportRW::count_warnings()
    {
        return 0;
    }
    void OdbReportRW::for_each_warning(std::function<void(std::shared_ptr<Error>)> user_function)
    {

    }
    size_t OdbReportRW::count_errors()
    {
        ErrorCount count;
        if (transaction.has_current()) {
            throw std::logic_error{"There's another transaction active. You can only read if the changes were flushed"};
        } else {
            transaction.reset(db->begin());
//        size_t count = db->execute("SELECT COUNT(*) FROM Error");
            count = db->query_value<ErrorCount>();
            flush();
        }
        return count.count;
    }

    void OdbReportRW::for_each_error(std::function<void(std::shared_ptr<Error>)> user_function)
    {
        typedef odb::result<Error> result;

        odb::core::transaction t (db->begin ());

        result r{db->query<Error>((odb::query<Error>::line > 0) + " ORDER BY " + odb::query<Error>::line)};

        // TODO if result::iterator has operator*, operator!=, operator++, then use ranged for. not if we use shared_ptr
        for (result::iterator i (r.begin ()); i != r.end (); ++i) {
            user_function(std::shared_ptr<ebi::vcf::Error>{i.load()});
        }

        t.commit ();
    }

  }
}
