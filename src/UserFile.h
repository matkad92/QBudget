#ifndef USERFILE_H
#define USERFILE_H

#include <iostream>
#include <vector>
#include <conio.h>
#include <string>
#include "FileXml.h"
#include "User.h"

using namespace std;


class UserFile: public FileXml {

    const string USER_FILE_NAME;

public:
    UserFile (string userFileName): USER_FILE_NAME(userFileName) {};
    void addUserToFile(User user);
    vector<User> loadUsersFromXml();
    void changePasswordInFile(int userId, string newPassword);

};



#endif // USERFILE_H


