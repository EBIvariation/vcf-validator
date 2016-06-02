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

#include "vcf/sqlite_report.hpp"

namespace ebi
{
  namespace vcf
  {
    SqliteReportRW::SqliteReportRW(std::string db_name) : db_name{db_name}, current_transaction_size{0},
                                                          transaction_size{1000000}, sleep_time{500}
    {
        int rc = sqlite3_open(db_name.c_str(), &db);
        if (rc != SQLITE_OK) {
            sqlite3_close(db);
            throw std::runtime_error(std::string{"Can't open database: "} + sqlite3_errmsg(db));
        }

        char *zErrMsg = NULL;
        rc = sqlite3_exec(db, "CREATE TABLE if not exists errors (line int, message varchar(255));", NULL, 0,
                          &zErrMsg);
        if (rc != SQLITE_OK) {
            std::string error_message{std::string{"Can't use table: "} + zErrMsg};
            sqlite3_free(zErrMsg);
            sqlite3_close(db);
            throw std::runtime_error{error_message};
        }

        rc = sqlite3_exec(db, "CREATE TABLE if not exists warnings (line int, message varchar(255));", NULL, 0,
                          &zErrMsg);
        if (rc != SQLITE_OK) {
            std::string error_message{std::string{"Can't use table: "} + zErrMsg};
            sqlite3_free(zErrMsg);
            sqlite3_close(db);
            throw std::runtime_error{error_message};
        }
    }

    void SqliteReportRW::close()
    {
        // in case the amount of inserts is not a multiple of the transaction size, do the leftover inserts in a smaller transaction
        if (current_transaction_size != 0) {
            commit_transaction();
            current_transaction_size = 0;
        }

        if (db != nullptr) {
            int rc = sqlite3_close(db);
            if (rc != SQLITE_OK) {
                int remaining_tries = 10;
                while (rc == SQLITE_BUSY && remaining_tries-- > 0) {
                    // maybe sqlite is still writing the last transaction
                    std::cerr << "Waiting to finish transactions" << std::endl;
                    std::this_thread::sleep_for(sleep_time);
                    rc = sqlite3_close(db);
                }
                if (rc != SQLITE_OK) {
                    throw std::runtime_error{"Can not close database " + db_name};
                }
            }
            db = nullptr;
        }
    }

    SqliteReportRW::~SqliteReportRW()
    {
        try {
            close();
        } catch (std::runtime_error e) {
            std::cerr << "An error occurred finalizing the error reporting: " << e.what() << std::endl;
        }
    }

    void SqliteReportRW::write_error(const Error &error)
    {
        write(error, "errors");
    }

    void SqliteReportRW::write_warning(const Error &error)
    {
        write(error, "warnings");
    }

    void SqliteReportRW::write(const Error &error, std::string table)
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
            rollback_transaction();
            std::string error_message{std::string{"Can't write: "} + zErrMsg};
            sqlite3_free(zErrMsg);
            throw std::runtime_error{error_message};
        }

        ++current_transaction_size;
        if (current_transaction_size == transaction_size) {
            commit_transaction();
            current_transaction_size = 0;
        }
    }

    void SqliteReportRW::start_transaction()
    {
        char *zErrMsg = NULL;
        int rc = sqlite3_exec(db, "BEGIN", NULL, 0, &zErrMsg);
        if (rc != SQLITE_OK) {
            std::string error_message{std::string{"Can't start transaction: "} + zErrMsg};
            sqlite3_free(zErrMsg);
            throw std::runtime_error{error_message};
        }
    }

    void SqliteReportRW::commit_transaction()
    {
        char *zErrMsg = NULL;
        int rc = sqlite3_exec(db, "COMMIT", NULL, 0, &zErrMsg);
        if (rc != SQLITE_OK) {
            try {
                rollback_transaction();
            } catch (std::runtime_error &rollback_error) {
                std::string message{"Can't rollback (was trying to recover a failed commit: "};
                message += zErrMsg;
                message += "): ";
                sqlite3_free(zErrMsg);
                throw std::runtime_error{message + rollback_error.what()};
            }
            std::string error_message{std::string{"Rollback performed: Couldn't commit transaction: "} + zErrMsg};
            sqlite3_free(zErrMsg);
            throw std::runtime_error{error_message};
        }
    }

    void SqliteReportRW::rollback_transaction()
    {
        char *zErrMsg = NULL;
        int rc = sqlite3_exec(db, "ROLLBACK", NULL, 0, &zErrMsg);
        if (rc != SQLITE_OK) {
            std::string error_message{std::string{"Can't rollback transaction: "} + zErrMsg};
            sqlite3_free(zErrMsg);
            throw std::runtime_error{error_message};
        }
    }

    // ReportReader implementation

    size_t SqliteReportRW::count(std::string table)
    {
        char *zErrMsg = NULL;
        size_t count_errors = 0;

        std::string query{"SELECT count(*) FROM " + table};

        int rc = sqlite3_exec(db, query.c_str(), [](void *count, int columns, char **values, char **names) {
            if (values[0] != NULL) {
                *(size_t *) count = std::stoul(values[0]);
            }
            return 0;
        }, &count_errors, &zErrMsg);

        if (rc != SQLITE_OK) {
            std::string error_message = std::string("Can't read database: ") + zErrMsg;
            sqlite3_free(zErrMsg);
            throw std::runtime_error(error_message);
        }

        return count_errors;
    }

    size_t SqliteReportRW::count_errors()
    {
        return count("errors");
    }
    size_t SqliteReportRW::count_warnings()
    {
        return count("warnings");
    }

    Error SqliteReportRW::read_error()
    {
        return vcf::Error(0);
    }
    Error SqliteReportRW::read_warning()
    {
        return vcf::Error(0);
    }

    void SqliteReportRW::read_errors(std::function<void(std::shared_ptr<Error>)> user_function)
    {
        read("errors", user_function);
    }
    void SqliteReportRW::read_warnings(std::function<void(std::shared_ptr<Error>)> user_function)
    {
        read("warnings", user_function);
    }

    static int converter_callback(void *user_function_ptr, int argc, char **argv, char **azColName)
    {
        std::function<void(std::shared_ptr<Error>)> *user_function =
            static_cast<std::function<void(std::shared_ptr<Error>)> *>(user_function_ptr);

        if (argc < 2) {
            return 1;
        }

        size_t line;
        if (azColName[0] != std::string{"line"}) {
            return 1;
        }
        line = std::stoul(argv[0]);

        std::string message;
        if (azColName[1] != std::string{"message"}) {
            return 1;
        }
        message = argv[1];

        // TODO: add a field in the table to choose which child to instantiate
        (*user_function)(std::shared_ptr<Error>(new Error{line, message}));

        return 0;
    }

    void SqliteReportRW::read(std::string table, std::function<void(std::shared_ptr<Error>)> user_function)
    {
        char *zErrMsg = NULL;
        std::string query{"SELECT * FROM " + table};

        int rc = sqlite3_exec(db, query.c_str(), converter_callback, &user_function, &zErrMsg);
        if (rc != SQLITE_OK) {
            std::string error_message{std::string("Can't continue reading: ") + zErrMsg};
            sqlite3_free(zErrMsg);
            throw std::runtime_error{error_message};
        }
    }
  }
}

