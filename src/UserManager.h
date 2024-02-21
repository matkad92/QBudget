#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <vector>

#include "User.h"
#include "UserFile.h"
#include "UnasignedMethods.h"

class UserManager {
    std::vector<User> users;
    UserFile userFile;
    int loggedInUserId{0};

    User getNewUserData();
    bool isLoginOccupied(std::string login);
    int getNewUserId();

public:
    UserManager(std::string userFileName): userFile (userFileName) {
        users = userFile.loadUsersFromXml();
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


