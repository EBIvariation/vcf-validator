//
// Created by jmmut on 25/05/16.
//

#include "vcf/report_writer.hpp"

namespace ebi
{
  namespace vcf
  {
    SqliteReportWriter::SqliteReportWriter(std::string db_name) : db_name{db_name}, current_transaction_size{0},
                                                      transaction_size{1000000}, sleep_time{500}
    {
        int rc = sqlite3_open(db_name.c_str(), &db);
        if (rc != SQLITE_OK) {
            sqlite3_close(db);
            throw std::runtime_error(std::string("Can't open database: ") + sqlite3_errmsg(db));
        }

        char *zErrMsg = NULL;
        rc = sqlite3_exec(db, "CREATE TABLE if not exists Errors (line int, message varchar(255));", NULL, 0,
                          &zErrMsg);
        if (rc != SQLITE_OK) {
            std::string error_message{std::string("Can't use table: ") + zErrMsg};
            sqlite3_free(zErrMsg);
            sqlite3_close(db);
            throw std::runtime_error{error_message};
        }
        
        rc = sqlite3_exec(db, "CREATE TABLE if not exists Warnings (line int, message varchar(255));", NULL, 0,
                          &zErrMsg);
        if (rc != SQLITE_OK) {
            std::string error_message{std::string("Can't use table: ") + zErrMsg};
            sqlite3_free(zErrMsg);
            sqlite3_close(db);
            throw std::runtime_error{error_message};
        }
    }

    void SqliteReportWriter::write_error(Error &error)
    {
        write(error, "Errors");
    }

    void SqliteReportWriter::write_warning(Error &error)
    {
        write(error, "Warnings");
    }

    void SqliteReportWriter::write(Error &error, std::string table)
    {
        char *zErrMsg = NULL;
        int rc;
        if (current_transaction_size == 0) {
            start_transaction();
        }
        std::stringstream ss;
        ss << "INSERT INTO " << table << " ( line , message ) VALUES (";
        ss << error.get_line() << " , \"" << error.get_raw_message() << "\");";

        rc = sqlite3_exec(db, ss.str().c_str(), NULL, 0, &zErrMsg);
        if (rc != SQLITE_OK) {
            std::string error_message{std::string("Can't write: ") + zErrMsg};
            sqlite3_free(zErrMsg);
            throw std::runtime_error{error_message};
        }

        ++current_transaction_size;
        if (current_transaction_size == transaction_size) {
            finish_transaction();
            current_transaction_size = 0;
        }
    }

    void SqliteReportWriter::start_transaction()
    {
        char *zErrMsg = NULL;
        int rc = sqlite3_exec(db, "BEGIN", NULL, 0, &zErrMsg);
        if (rc != SQLITE_OK) {
            std::string error_message{std::string("Can't start transaction: ") + zErrMsg};
            sqlite3_free(zErrMsg);
            throw std::runtime_error{error_message};
        }
    }

    void SqliteReportWriter::finish_transaction()
    {
        char *zErrMsg = NULL;
        int rc = sqlite3_exec(db, "COMMIT", NULL, 0, &zErrMsg);
        if (rc != SQLITE_OK) {
            std::string error_message{std::string("Can't finish transaction: ") + zErrMsg};
            sqlite3_free(zErrMsg);
            throw std::runtime_error{error_message};
        }
    }

    SqliteReportWriter::~SqliteReportWriter()
    {
        // in case the amount of inserts is not a multiple of the transaction size, do the leftover inserts in a smaller transaction
        if (current_transaction_size != 0) {
            finish_transaction();
            current_transaction_size = 0;
        }

        int rc = sqlite3_close(db);
        if (rc != SQLITE_OK) {
            int remaining_tries = 10;
            while (rc == SQLITE_BUSY && remaining_tries-- > 0) {
                // maybe sqlite is still writing the last transaction
                std::cerr << "waiting to finish transactions" << std::endl;
                std::this_thread::sleep_for(sleep_time);
                rc = sqlite3_close(db);
            }
            if (rc != SQLITE_OK) {
                throw std::runtime_error{"can not close database " + db_name};
            }
        }
    }
  }
}
