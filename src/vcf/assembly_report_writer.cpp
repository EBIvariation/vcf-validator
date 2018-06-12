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

#include "vcf/assembly_report_writer.hpp"

namespace ebi
{
  namespace vcf
  {
    void SummaryAssemblyReportWriter::write_mismatch(const vcf::VcfVariant &vcf_variant) 
    {
        match_stats.num_variants++;
    }
    void SummaryAssemblyReportWriter::write_match(const vcf::VcfVariant &vcf_variant) 
    {
        match_stats.num_variants++;
        match_stats.num_matches++;
    }
    void SummaryAssemblyReportWriter::write_results() 
    {
    	BOOST_LOG_TRIVIAL(info) << "Number of matches: " << match_stats.num_matches << "/" << match_stats.num_variants;
    	BOOST_LOG_TRIVIAL(info) << "Percentage of matches: " << (static_cast<double>(match_stats.num_matches) / match_stats.num_variants) * 100 << "%";
    }
    void SummaryAssemblyReportWriter::add_result(bool result, const vcf::VcfVariant &vcf_variant) 
    {
        if(result) {
            write_match(vcf_variant);
        } else {
            write_mismatch(vcf_variant);
        }
    }

	OdbAssemblyReportWriter::OdbAssemblyReportWriter(const std::string &db_name) : db_name(db_name), current_transaction_size{0},
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
	OdbAssemblyReportWriter::~OdbAssemblyReportWriter()
	{
	    try {
	        flush();
	    } catch (std::exception &e) {
	        BOOST_LOG_TRIVIAL(error) << "An error occurred finalizing the error reporting: " << e.what();
	    }
	}
    void OdbAssemblyReportWriter::write_mismatch(const vcf::VcfVariant &vcf_variant) 
    {
        match_stats.num_variants++;
    }
    void OdbAssemblyReportWriter::write_match(const vcf::VcfVariant &vcf_variant) 
    {
        match_stats.num_variants++;
        match_stats.num_matches++;
    }
    void OdbAssemblyReportWriter::write_results() 
    {
        if (current_transaction_size == 0) {
            // start transaction
            transaction.reset(db->begin());
        }

        db->persist(match_stats);

        ++current_transaction_size;
        if (current_transaction_size == transaction_size) {
            // commit transaction
            flush();
            current_transaction_size = 0;
        }
    }
    void OdbAssemblyReportWriter::add_result(bool result, const vcf::VcfVariant &vcf_variant) 
    {
    	if(result) {
            write_match(vcf_variant);
        } else {
            write_mismatch(vcf_variant);
        }
    }
    void OdbAssemblyReportWriter::flush()
    {
        if (transaction.has_current()) {
            transaction.commit();
        }

        {
            odb::core::connection_ptr c{db->connection()};
            c->execute("PRAGMA shrink_memory");
        }
    }
  }
}
