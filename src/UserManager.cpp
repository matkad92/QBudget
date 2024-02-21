#include "UserManager.h"

void UserManager::userRegister() {
    User user = getNewUserData();
    users.push_back(user);
    userFile.addUserToFile(user);

    std::cout << std::endl << "User has been created successfully."<< std::endl << std::endl;
    system("pause");
    std::cout << std::endl;
}
User UserManager::getNewUserData() {
    User user;
    std::string login;

    do {
        std::cout << "Enter login: ";
        std::cin >> login;
        user.setLogin(login);
    } while (isLoginOccupied(user.getLogin()) == true);

    user.setId(getNewUserId());

    std::cout << "Enter Password: ";
    std::string password;//Mozna dodac opcje sprawdzania formatu hasla
    std::cin.sync();
    password = UnasignedMethods::takeLine();
    user.setPassword(password);

    std::cout <<  "Enter Name: ";
    std::string name;
    name = UnasignedMethods::takeLine();
    user.setName(name);

    std::cout << "Enter Surname: ";
    std::string surname;
    surname = UnasignedMethods::takeLine();
    user.setSurname(surname);

    return user;
}

bool UserManager::isLoginOccupied(std::string login) {
    for (int i = 0; i < users.size(); i++) {
        if (users[i].getLogin() == login) {
            std::cout << std::endl << "User with this login already exists!" << std::endl;
            return true;
        }
    }
    return false;
}

int UserManager::getNewUserId() {

    return (users.empty()) ? 1 : users.back().getId() + 1;
}

void UserManager::printAllUsers() {
    for ( int i = 0; i < users.size(); i++) {
        std::cout << users[i].getId() << std::endl;
        std::cout << users[i].getLogin() << std::endl;
        std::cout << users[i].getPassword() << std::endl;
        std::cout << users[i].getName() << std::endl;
        std::cout << users[i].getSurname() << std::endl;
    }
}

int UserManager::login() {
    User user;
    std::string inputLogin = "", inputPassword = "";

    std::cout << std::endl << "Enter login: ";
    inputLogin = UnasignedMethods::takeLine();

    for (std::vector<User>::iterator itr = users.begin(), vecEnd = users.end(); itr < vecEnd; itr++) {
        if (itr -> getLogin() == inputLogin) {
            for (int numberOfTries = 3; numberOfTries > 0; numberOfTries--) {
                std::cout << "Enter password. (Number of tries left: " << numberOfTries << ") : ";
                inputPassword = UnasignedMethods::takeLine();
                if (itr -> getPassword() == inputPassword) {
                    std::cout << "You have successfully logged in."<< std::endl << std::endl;
                    system("pause");
                    loggedInUserId = itr -> getId();
                    return loggedInUserId;
                }
            }
            std::cout << "You entered wrong password 3 times." << std::endl;
            system("pause");
            return 0;
        }
    }
    std::cout << "There is no User with this login!" << std::endl << std::endl;
    system("pause");
    return 0;

}

bool UserManager::isUserLoggedIn() {
    if (loggedInUserId > 0) return true;
    else return false;
}

int UserManager::getLoggedInUserId() {
    return loggedInUserId;
}

void UserManager::logout() {
    loggedInUserId = 0;
}

void UserManager::changePassword() {

    std::string newPassword;
    std::string oldPassword;
    std::cout << "Enter new password: ";
    newPassword = UnasignedMethods::takeLine();
    std::cout << "Enter old password: ";
    oldPassword = UnasignedMethods::takeLine();

    for (std::vector<User>::iterator itr = users.begin(), vecEnd = users.end(); itr!= vecEnd; itr++) {
        if (itr->getId() == loggedInUserId) {
            if (itr->getPassword() != oldPassword){
                std::cout << "Old password wrong!" << std::endl;
                getch();
                return;
            }
            itr->setPassword(newPassword);
            std::cout << "Password has been changed. "<< std::endl << std::endl;

            userFile.changePasswordInFile(loggedInUserId, newPassword);
            system("pause");
        }
    }


}
