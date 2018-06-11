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
#include <odb/database.hxx>
#include <odb/sqlite/query.hxx>
#include <odb/schema-catalog.hxx>
#include <odb/sqlite/database.hxx>
#include "vcf/error-odb.hpp"

namespace ebi
{
  namespace vcf
  {   

    class AssemblyReportWriter
    {
      public:
        virtual void add_result(bool result) = 0;
        virtual void write_number_matches() = 0;
        virtual void write_percentage() = 0;
        virtual void write_results() = 0;
    };

    class StdoutAssemblyReportWriter : public AssemblyReportWriter
    {
      public:
        virtual void write_number_matches() override
        {
            BOOST_LOG_TRIVIAL(info) << "Number of matches: " << match_stats.num_matches << "/" << match_stats.num_variants;
        }

        virtual void write_percentage() override
        {
            BOOST_LOG_TRIVIAL(info) << "Percentage of matches: " << (static_cast<double>(match_stats.num_matches) / match_stats.num_variants) * 100 << "%";
        }

        virtual void write_results() override
        {
        	write_number_matches();
        	write_percentage();
        }

        virtual void add_result(bool result) override
        {
			match_stats.add_match_result(result);
        }

      private:
    	MatchStats match_stats;

    };

    class OdbAssemblyReportWriter : public AssemblyReportWriter
    {
      public:

    	OdbAssemblyReportWriter(const std::string &db_name) : db_name(db_name), current_transaction_size{0},
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
    	~OdbAssemblyReportWriter()
    	{
		    try {
		        flush();
		    } catch (std::exception &e) {
		        BOOST_LOG_TRIVIAL(error) << "An error occurred finalizing the error reporting: " << e.what();
		    }
		}
        virtual void write_number_matches() override
        {

        }
        virtual void write_percentage() override
        {
        	
        }
        virtual void write_results() override
        {
        	write_db(match_stats);
        }
        void write_db(MatchStats &result)
        {
        	if (current_transaction_size == 0) {
	            // start transaction
	            transaction.reset(db->begin());
	        }

	        db->persist(result);

	        ++current_transaction_size;
	        if (current_transaction_size == transaction_size) {
	            // commit transaction
	            flush();
	            current_transaction_size = 0;
	        }
        }
        virtual void add_result(bool result) override
        {
        	match_stats.add_match_result(result);
        }
        void flush()
	    {
	        if (transaction.has_current()) {
	            transaction.commit();
	        }

	        {
	            odb::core::connection_ptr c{db->connection()};
	            c->execute("PRAGMA shrink_memory");
	        }
	    }

      private:
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
