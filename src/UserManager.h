#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <memory>
#include <vector>

#include "User.h"
#include "UserFile.h"
#include "dbmanager.h"
#include "UnasignedMethods.h"

class UserManager {
    std::vector<User> users;
    UserFile userFile;
    int loggedInUserId{0};

    std::shared_ptr<DbManager> dbManager;

    User getNewUserData();
    bool isLoginOccupied(std::string login);
    int getNewUserId();

public:
    UserManager(std::string userFileName, std::shared_ptr<DbManager> db): userFile (userFileName) {
        users = userFile.loadUsersFromXml();
        dbManager = db;
    };
    void userRegister();
    void printAllUsers();
    int login();
    bool isUserLoggedIn();
    int getLoggedInUserId();
    void logout();
    void changePassword();

};


#endif // USERMANAGER_H


