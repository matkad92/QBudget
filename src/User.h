#ifndef USER_H
#define USER_H


#include <iostream>

class User {
    int id;
    std::string login;
    std::string password;
    std::string name;
    std::string surname;

public:
    void setId(int newId);
    void setLogin(std::string newLogin);
    void setPassword(std::string newPassword);
    void setName(std::string newName);
    void setSurname(std::string newSurname);

    int getId();
    std::string getLogin();
    std::string getPassword();
    std::string getName();
    std::string getSurname();

};


#endif // USER_H

