#include <sqlite3.h>
#include <sstream>
#include <iostream>
#include <thread>
#include <chrono>

static const int TOTAL_ROWS = 1000000;
using namespace std;

void producer(std::string dbName) {
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc; // return code
    
    rc = sqlite3_open(dbName.c_str(), &db);
    if( rc!=SQLITE_OK ){
        cout << "Can't open database: " << zErrMsg << endl;
        sqlite3_free(zErrMsg);
    }
    
    rc = sqlite3_exec(db, "CREATE TABLE Errors ( line int, message varchar(255));", NULL, 0, &zErrMsg);
    while(rc == SQLITE_BUSY) {
        cout << "producer SQL error(" << rc << "): " << zErrMsg << endl;
        sqlite3_free(zErrMsg);
        rc = sqlite3_exec(db, "CREATE TABLE Errors ( line int, message varchar(255));", NULL, 0, &zErrMsg);
    }
    if (rc != SQLITE_OK) {
        cout << "producer SQL error(" << rc << "): " << zErrMsg << endl;
        sqlite3_free(zErrMsg);
    }
    
    
    int transactionSize = 100000;
    int currentTransactionSize = 0;
    
    for (int i = 0; i < TOTAL_ROWS; ++i) {
        if (currentTransactionSize == 0) {
            cout << "\\  starting transaction" << endl;
            rc = sqlite3_exec(db, "BEGIN", NULL, 0, &zErrMsg);
            if( rc!=SQLITE_OK ){
                cout << "producer SQL error: " << zErrMsg << endl;
                sqlite3_free(zErrMsg);
            }
            cout << " \\ started transaction" << endl;
        }
        
        std::stringstream ss;
        ss << "INSERT INTO Errors ( line , message ) VALUES (";
        ss << i << " , \"Generic error message\");";
        
        rc = sqlite3_exec(db, ss.str().c_str(), NULL, 0, &zErrMsg);
        if( rc!=SQLITE_OK ){
            cout << "producer SQL error: " << zErrMsg << endl;
            sqlite3_free(zErrMsg);
        }
        
        ++currentTransactionSize;
        if (currentTransactionSize == transactionSize) {
            cout << " / finishing transaction" << endl;
            rc = sqlite3_exec(db, "COMMIT", NULL, 0, &zErrMsg);
            if( rc!=SQLITE_OK ){
                cout << "producer SQL error: " << zErrMsg << endl;
                sqlite3_free(zErrMsg);
            }
            cout << "/  finished transaction" << endl;
            currentTransactionSize = 0;
        }
    }
    
    // in case the amount of inserts is not a multiple of the transaction size, do the leftover inserts in a smaller transaction
    if (currentTransactionSize != 0) {
        cout << " / finishing transaction" << endl;
        rc = sqlite3_exec(db, "COMMIT", NULL, 0, &zErrMsg);
        if( rc!=SQLITE_OK ){
            cout << "producer SQL error: " << zErrMsg << endl;
            sqlite3_free(zErrMsg);
        }
        cout << "/  finished transaction" << endl;
    }
    
    sqlite3_close(db);
    
    cout << "producer finished " << endl;
}

int callback(void *written, int argc, char **argv, char **azColName){
    int i;
    if(*(int*)written % 100000 == 0) {
        for(i=0; i<argc; i++){
            cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << endl;
        }
        printf("\n");
    }
    (*(int*)written)++;
    return 0;
}

void consumer(std::string dbName) {
    
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc; // return code
    
    rc = sqlite3_open(dbName.c_str(), &db);
    if( rc!=SQLITE_OK ){
        cout << "consumer Can't open database: " << zErrMsg << endl;
        sqlite3_free(zErrMsg);
    }
    
    int consumerIterations = 0;
    int written = 0;

    while (written < TOTAL_ROWS) {
        stringstream ss;
        ss << "SELECT * FROM Errors WHERE line >= " << written;

//        cout <<"consumer: trying to read" << endl;
        rc = sqlite3_exec(db, ss.str().c_str(), callback, &written, &zErrMsg);
        if (rc != SQLITE_OK) {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        if( rc!=SQLITE_OK ){
            cout << "consumer SQL error(" << rc << "): " << zErrMsg << endl;
            sqlite3_free(zErrMsg);
        }
        consumerIterations++;
    }
    
    sqlite3_close(db);
    
    cout << "consumer finished in " << consumerIterations << " consumer iterations" << endl;
}

int main(int argc, char **argv) {
    
    if( argc!=2 ){
        cout << "Usage: " << argv[0] << " DATABASE \n";
        return(1);
    }

    std::string dbName = argv[1];
    std::thread prod(producer, dbName);
    std::thread consum(consumer, dbName);

    prod.join();
    consum.join();
    return 0;
}

