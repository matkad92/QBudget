#ifndef USERMANAGER_H
#define USERMANAGER_H

// #include <iostream>
#include <vector>
// #include <cstdlib>

#include "User.h"
#include "UserFile.h"
#include "UnasignedMethods.h"

using namespace std;

class UserManager {
    vector<User> users;
    UserFile userFile;
    int loggedInUserId{0};

    User getNewUserData();
    bool isLoginOccupied(string login);
    int getNewUserId();

public:
    UserManager(string userFileName): userFile (userFileName) {
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


