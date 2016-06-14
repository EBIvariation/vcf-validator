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
            throw std::runtime_error{std::string{"Can't open database: "} + sqlite3_errmsg(db)};
        }

        char *zErrMsg = NULL;
        rc = sqlite3_exec(db, "CREATE TABLE if not exists errors (line int, code int, message varchar(255));", NULL, 0,
                          &zErrMsg);
        if (rc != SQLITE_OK) {
            std::string error_message{std::string{"Can't use table: "} + zErrMsg};
            sqlite3_free(zErrMsg);
            sqlite3_close(db);
            throw std::runtime_error{error_message};
        }

        rc = sqlite3_exec(db, "CREATE TABLE if not exists warnings (line int, code int, message varchar(255));", NULL, 0,
                          &zErrMsg);
        if (rc != SQLITE_OK) {
            std::string error_message{std::string{"Can't use table: "} + zErrMsg};
            sqlite3_free(zErrMsg);
            sqlite3_close(db);
            throw std::runtime_error{error_message};
        }
        
        // preparing statements
        std::string sql = "INSERT INTO errors ( line , code , message ) VALUES ( ? , ? , ? )";
        rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &statement_error, NULL);
        if (rc != SQLITE_OK) {
            throw std::runtime_error{std::string{"Can't write, failed sqlite3_prepare_v2 with code: "} + std::to_string(rc)};
        }
        sql = "INSERT INTO warnings ( line , code , message ) VALUES ( ? , ? , ? )";
        rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &statement_warning, NULL);
        if (rc != SQLITE_OK) {
            throw std::runtime_error{std::string{"Can't write, failed sqlite3_prepare_v2 with code: "} + std::to_string(rc)};
        }
    }

    void SqliteReportRW::flush()
    {
        // in case the amount of inserts is not a multiple of the transaction size, do the leftover inserts in a smaller transaction
        if (current_transaction_size != 0) {
            commit_transaction();
            current_transaction_size = 0;
        }
    }
    
    void SqliteReportRW::close()
    {
        flush();
        
        if (db != nullptr) {
            int rc = sqlite3_close_v2(db);
            if (rc != SQLITE_OK) {
                int remaining_tries = 10;
                while (rc == SQLITE_BUSY && remaining_tries-- > 0) {
                    // maybe sqlite is still writing the last transaction
                    std::cerr << "Waiting to finish transactions" << std::endl;
                    std::this_thread::sleep_for(sleep_time);
                    rc = sqlite3_close_v2(db);
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
            
            int rc = sqlite3_finalize(statement_error);
            if (rc != SQLITE_OK) {
                throw std::runtime_error{std::string{"Failed sqlite3_finalize with code: "} + std::to_string(rc)};
            }
            rc = sqlite3_finalize(statement_warning);
            if (rc != SQLITE_OK) {
                throw std::runtime_error{std::string{"Failed sqlite3_finalize with code: "} + std::to_string(rc)};
            }
        } catch (std::runtime_error e) {
            std::cerr << "An error occurred finalizing the error reporting: " << e.what() << std::endl;
        }
    }

    void SqliteReportRW::write_error(const Error &error)
    {
        write(error, statement_error);
    }

    void SqliteReportRW::write_warning(const Error &error)
    {
        write(error, statement_warning);
    }

    void SqliteReportRW::write(const Error &error, sqlite3_stmt * statement)
    {
        int rc;
        if (current_transaction_size == 0) {
            start_transaction();
        }
        
        rc = sqlite3_bind_int64(statement, 1, error.get_line());
        if (rc != SQLITE_OK) {
            rollback_transaction();
            throw std::runtime_error{std::string{"Can't write, failed sqlite3_bind_int64 with code: "} + std::to_string(rc)};
        }
        rc = sqlite3_bind_int64(statement, 2, static_cast<long>(error.get_code()));
        if (rc != SQLITE_OK) {
            rollback_transaction();
            throw std::runtime_error{std::string{"Can't write, failed sqlite3_bind_int64 with code: "} + std::to_string(rc)};
        }
        rc = sqlite3_bind_text(statement, 3, error.get_raw_message().c_str(), -1, SQLITE_TRANSIENT);
        if (rc != SQLITE_OK) {
            rollback_transaction();
            throw std::runtime_error{std::string{"Can't write, failed sqlite3_bind_text with code: "} + std::to_string(rc)};
        }
        rc = sqlite3_step(statement);
        if (rc != SQLITE_DONE) {
            rollback_transaction();
            throw std::runtime_error{std::string{"Can't write, failed sqlite_step with code: "} + std::to_string(rc)};
        }
        rc = sqlite3_reset(statement);
        if (rc != SQLITE_OK) {
            rollback_transaction();
            throw std::runtime_error{std::string{"Can't write, failed sqlite3_reset with code: "} + std::to_string(rc)};
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

    void SqliteReportRW::for_each_error(std::function<void(std::shared_ptr<Error>)> user_function)
    {
        for_each("errors", user_function);
    }
    void SqliteReportRW::for_each_warning(std::function<void(std::shared_ptr<Error>)> user_function)
    {
        for_each("warnings", user_function);
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
        
        ErrorCode code;
        if (azColName[1] != std::string{"code"}) {
            return 1;
        }
        code = static_cast<ErrorCode>(std::stoul(argv[1]));
        

        std::string message;
        if (azColName[2] != std::string{"message"}) {
            return 1;
        }
        message = argv[2];
        
        // no reflection :(
        switch (code) {
            default:
            case ErrorCode::error:
                (*user_function)(std::shared_ptr<Error>(new Error{line, message}));
                break;
            case ErrorCode::meta_section:
                (*user_function)(std::shared_ptr<Error>(new MetaSectionError{line, message}));
                break;
            case ErrorCode::header_section:
                (*user_function)(std::shared_ptr<Error>(new HeaderSectionError{line, message}));
                break;
            case ErrorCode::body_section:
                (*user_function)(std::shared_ptr<Error>(new BodySectionError{line, message}));
                break;
            case ErrorCode::fileformat:
                (*user_function)(std::shared_ptr<Error>(new FormatBodyError{line, message}));
                break;
            case ErrorCode::chromosome_body:
                (*user_function)(std::shared_ptr<Error>(new ChromosomeBodyError{line, message}));
                break;
            case ErrorCode::position_body:
                (*user_function)(std::shared_ptr<Error>(new PositionBodyError{line, message}));
                break;
            case ErrorCode::id_body:
                (*user_function)(std::shared_ptr<Error>(new IdBodyError{line, message}));
                break;
            case ErrorCode::reference_allele_body:
                (*user_function)(std::shared_ptr<Error>(new ReferenceAlleleBodyError{line, message}));
                break;
            case ErrorCode::alternate_alleles_body:
                (*user_function)(std::shared_ptr<Error>(new AlternateAllelesBodyError{line, message}));
                break;
            case ErrorCode::quality_body:
                (*user_function)(std::shared_ptr<Error>(new QualityBodyError{line, message}));
                break;
            case ErrorCode::filter_body:
                (*user_function)(std::shared_ptr<Error>(new FilterBodyError{line, message}));
                break;
            case ErrorCode::info_body:
                (*user_function)(std::shared_ptr<Error>(new InfoBodyError{line, message}));
                break;
            case ErrorCode::format_body:
                (*user_function)(std::shared_ptr<Error>(new FormatBodyError{line, message}));
                break;
            case ErrorCode::samples_body:
                (*user_function)(std::shared_ptr<Error>(new SamplesBodyError{line, message}));
                break;
        }

        return 0;
    }

    void SqliteReportRW::for_each(std::string table, std::function<void(std::shared_ptr<Error>)> user_function)
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

