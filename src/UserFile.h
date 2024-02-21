#ifndef USERFILE_H
#define USERFILE_H

#include <iostream>
#include <vector>
#include <conio.h>
#include <string>
#include "FileXml.h"
#include "User.h"


class UserFile: public FileXml {

    const std::string USER_FILE_NAME;

public:
    UserFile (std::string userFileName): USER_FILE_NAME(userFileName) {};
    void addUserToFile(User user);
    std::vector<User> loadUsersFromXml();
    void changePasswordInFile(int userId, std::string newPassword);

};



#endif // USERFILE_H


