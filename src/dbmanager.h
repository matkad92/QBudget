#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <sqlite3.h>
#include <string>
#include "User.h"

class DbManager
{
    sqlite3* db;
    bool executeQuery(const std::string& query);
    bool createUserTable();

public:
    DbManager();
    ~DbManager();

    bool openDatabase(const std::string& dbName);
    bool closeDatabase();
    bool addUserToDatabase(const User& user);
};

#endif // DBMANAGER_H
