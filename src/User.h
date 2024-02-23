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

    int getId() const;
    std::string getLogin() const;
    std::string getPassword() const;
    std::string getName() const;
    std::string getSurname() const;

};


#endif // USER_H

