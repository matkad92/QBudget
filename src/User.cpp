#include "User.h"

void User::setId(int newId) {
    if (newId >= 0) id = newId;
}
void User::setLogin(std::string newLogin) {
    login = newLogin;
}
void User::setPassword(std::string newPassword) {
    password = newPassword;
}
void User::setName(std::string newName) {
    name = newName;
}
void User::setSurname(std::string newSurname) {
    surname = newSurname;
}

int User::getId() const {
    return id;
}
std::string User::getLogin() const {
    return login;
}
std::string User::getPassword() const {
    return password;
}
std::string User::getName() const{
    return name;
}
std::string User::getSurname() const{
    return surname;
}
