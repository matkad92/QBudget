#include "dbmanager.h"
#include <iostream>
#include <sqlite3.h>

bool DbManager::executeQuery(const std::string &query)
{
    char* errorMessage = nullptr;
    int result = sqlite3_exec(db, query.c_str(), nullptr, nullptr, &errorMessage);
    if (result != SQLITE_OK) {
        std::cerr << "Error executing query: " << errorMessage << std::endl;
        sqlite3_free(errorMessage);
        return false;
    }
    return true;
}

bool DbManager::createUserTable()
{
    std::string query = "CREATE TABLE IF NOT EXISTS users ("
                        "    UserId INTEGER PRIMARY KEY,"
                        "    Login TEXT,"
                        "    Password TEXT,"
                        "    Name TEXT,"
                        "    Surname TEXT"
                        ");";

    return executeQuery(query);
}

DbManager::DbManager()
{
    db = nullptr;
    openDatabase("qbudgetdb");
    if(db)
        createUserTable();
}

DbManager::~DbManager()
{
    if (db)
    {
        closeDatabase();
    }
}

bool DbManager::openDatabase(const std::string& dbName)
{
    sqlite3* tempDb = nullptr;

    if (sqlite3_open(dbName.c_str(), &db) != SQLITE_OK)
    {
        std::cerr << "Error opening database: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return false;
    }

    std::cout << "Database opened successfully." << std::endl;
    return true;
}


bool DbManager::closeDatabase()
{
    if (db)
    {
        if (sqlite3_close(db) != SQLITE_OK)
        {
            std::cerr << "Error closing database: " << sqlite3_errmsg(db) << std::endl;
            return false;
        }
        std::cout << "Database closed successfully." << std::endl;
          db = nullptr;
    }
    return true;
}

bool DbManager::addUserToDatabase(const User &user)
{

    std::string query = "INSERT INTO users (UserId, Login, Password, Name, Surname) VALUES (?, ?, ?, ?, ?)";


    sqlite3_stmt* stmt = nullptr;
    if (sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Error preparing SQL statement: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }

    int paramIndex = 1;
    sqlite3_bind_int(stmt, paramIndex++, user.getId());
    sqlite3_bind_text(stmt, paramIndex++, user.getLogin().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, paramIndex++, user.getPassword().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, paramIndex++, user.getName().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, paramIndex++, user.getSurname().c_str(), -1, SQLITE_TRANSIENT);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        std::cerr << "Error executing SQL statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        return false;
    }

    sqlite3_finalize(stmt);

    return true;
}
