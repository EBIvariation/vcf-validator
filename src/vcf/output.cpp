//
// Created by jmmut on 25/05/16.
//

#include "vcf/output.hpp"

namespace ebi
{
  namespace vcf
  {
    SqliteOutput::SqliteOutput(std::string db_name)
    {
        int rc = sqlite3_open(db_name.c_str(), &db);
        if(rc != SQLITE_OK) {
            sqlite3_close(db);
            throw std::runtime_error(std::string("Can't open database: ") + sqlite3_errmsg(db));
        }

        char *zErrMsg = NULL;
        rc = sqlite3_exec(db, "CREATE TABLE if not exists Errors ( line int, message varchar(255));", NULL, 0, &zErrMsg);
        if(rc != SQLITE_OK) {
            std::string errorMessage{std::string("Can't use table: ") + zErrMsg};
            sqlite3_free(zErrMsg);
            sqlite3_close(db);
            throw std::runtime_error(errorMessage);
        }
    }

    void SqliteOutput::write(Error &error)
    {
        // TODO do with transactions
        std::stringstream ss;
        ss << "INSERT INTO Errors ( line , message ) VALUES (";
        ss << error.get_line() << " , \"" << error.get_raw_message() << "\");";

        char *zErrMsg = NULL;
        int rc = sqlite3_exec(db, ss.str().c_str(), NULL, 0, &zErrMsg);
        if (rc != SQLITE_OK) {
            std::string errorMessage{std::string("Can't write: ") + zErrMsg};
            sqlite3_free(zErrMsg);
            throw std::runtime_error(errorMessage);
        }
    }

    SqliteOutput::~SqliteOutput()
    {
        sqlite3_close(db);
    }
  }
}
