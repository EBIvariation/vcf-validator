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
    OdbReportRW::OdbReportRW(const std::string &db_name) : db_name(db_name)
    {
        using namespace odb::core;

        try {
            db = std::unique_ptr<odb::sqlite::database> (
                    new odb::sqlite::database{
                            db_name, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE});

            // Create the database schema. Due to bugs in SQLite foreign key
            // support for DDL statements, we need to temporarily disable
            // foreign keys.
            //
            {
                connection_ptr c (db->connection ());

                c->execute ("PRAGMA foreign_keys=OFF");

                transaction t (c->begin ());
                schema_catalog::create_schema (*db);
                t.commit ();

                c->execute ("PRAGMA foreign_keys=ON");
            }

            /*

            // Joe Dirt just had a birthday, so update his age.
            //
            {
                transaction t (db->begin ());

                auto_ptr<person> joe (db->load<person> (joe_id));
                joe->age (joe->age () + 1);
                db->update (*joe);

                t.commit ();
            }
*/
            // Alternative implementation without using the id.
            //
            /*
            {
              transaction t (db->begin ());

              // Here we know that there can be only one Joe Dirt in our
              // database so we use the query_one() shortcut instead of
              // manually iterating over the result returned by query().
              //
              auto_ptr<person> joe (
                db->query_one<person> (query::first == "Joe" &&
                                       query::last == "Dirt"));

              if (joe.get () != 0)
              {
                joe->age (joe->age () + 1);
                db->update (*joe);
              }

              t.commit ();
            }
            */

            /*
            // Print some statistics about all the people in our database.
            //
            {
                transaction t (db->begin ());

                // The result of this (aggregate) query always has exactly one element
                // so use the query_value() shortcut.
                //
                person_stat ps (db->query_value<person_stat> ());

                cout << endl
                << "count  : " << ps.count << endl
                << "min age: " << ps.min_age << endl
                << "max age: " << ps.max_age << endl;

                t.commit ();
            }

            // John Doe is no longer in our database.
            //
            {
                transaction t (db->begin ());
                db->erase<person> (john_id);
                t.commit ();
            }*/
        } catch (const odb::exception& e) {
            throw std::runtime_error{std::string{"ODB report: failed ODB initialization: "} + e.what()};
        }
    }


    void OdbReportRW::write_error(Error &error)
    {
        odb::core::transaction t{db->begin()};
        db->persist(error);
        t.commit();
    }
    void OdbReportRW::write_warning(Error &error)
    {
        std::cerr << "OdbReportRW::write_warning unimplemented" << std::endl;
    }
    size_t OdbReportRW::count_warnings()
    {
        return 0;
    }
    void OdbReportRW::for_each_warning(std::function<void(std::shared_ptr<Error>)> user_function)
    {

    }
    size_t OdbReportRW::count_errors()
    {
        odb::core::transaction t (db->begin ());
//        size_t count = db->execute("SELECT COUNT(*) FROM Error");
        ErrorCount count = db->query_value<ErrorCount>();
        t.commit ();

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
