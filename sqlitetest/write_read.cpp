#include <sqlite3.h>
#include <sstream>
#include <iostream>

using namespace std;

static int callback(void *written, int argc, char **argv, char **azColName){
    int i;
    if(*(int*)written % 1000 == 0) {
        for(i=0; i<argc; i++){
            cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << endl;
        }
        printf("\n");
    }
    (*(int*)written)++;
    return 0;
}

int main(int argc, char **argv){
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;

    if( argc!=2 ){
        cout << "Usage: " << argv[0] << " DATABASE \n";
        return(1);
    }

    rc = sqlite3_open(argv[1], &db);
    if( rc ){
        cout << "Can't open database: " << sqlite3_errmsg(db) << endl;
        sqlite3_close(db);
        return(1);
    }

    rc = sqlite3_exec(db, "CREATE TABLE Errors ( line int, message varchar(255));", NULL, 0, &zErrMsg);
    if( rc!=SQLITE_OK ){
        cout << "SQL error: " << zErrMsg << endl;
        sqlite3_free(zErrMsg);
    }
//


    int transactionSize = 1000000;
    int currentTransactionSize = 0;

    for (int i = 0; i < 1000000; ++i) {
        if (currentTransactionSize == 0) {
            rc = sqlite3_exec(db, "BEGIN", NULL, 0, &zErrMsg);
            if( rc!=SQLITE_OK ){
                cout << "SQL error: " << zErrMsg << endl;
                sqlite3_free(zErrMsg);
            }
        }

        std::stringstream ss;
        ss << "INSERT INTO Errors ( line , message ) VALUES (";
        ss << i << " , \"Generic error message\");";

        rc = sqlite3_exec(db, ss.str().c_str(), NULL, 0, &zErrMsg);
        if( rc!=SQLITE_OK ){
            cout << "SQL error: " << zErrMsg << endl;
            sqlite3_free(zErrMsg);
        }

        ++currentTransactionSize;
        if (currentTransactionSize == transactionSize) {
            rc = sqlite3_exec(db, "COMMIT", NULL, 0, &zErrMsg);
            if( rc!=SQLITE_OK ){
                cout << "SQL error: " << zErrMsg << endl;
                sqlite3_free(zErrMsg);
            }
            cerr << "finished transaction" << endl;
            currentTransactionSize = 0;
        }
    }

    // in case the amount of inserts is not a multiple of the transaction size, do the leftover inserts in a smaller transaction
    if (currentTransactionSize != 0) {
        rc = sqlite3_exec(db, "COMMIT", NULL, 0, &zErrMsg);
        if( rc!=SQLITE_OK ){
            cout << "SQL error: " << zErrMsg << endl;
            sqlite3_free(zErrMsg);
        }
        cerr << "finished transaction" << endl;
    }

//    cout << "finished writing" << endl;

    int written = 0;
    rc = sqlite3_exec(db, "SELECT * FROM Errors", callback, &written, &zErrMsg);
    if( rc!=SQLITE_OK ){
        cout << "SQL error: " << zErrMsg << endl;
        sqlite3_free(zErrMsg);
    }

    sqlite3_close(db);
    return 0;
}

