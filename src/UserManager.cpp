#include "UserManager.h"

void UserManager::userRegister() {
    User user = getNewUserData();
    users.push_back(user);
    userFile.addUserToFile(user);

    cout << endl << "User has been created successfully."<< endl << endl;
    system("pause");
    cout << endl;
}
User UserManager::getNewUserData() {
    User user;
    string login;

    do {
        cout << "Enter login: ";
        cin >> login;
        user.setLogin(login);
    } while (isLoginOccupied(user.getLogin()) == true);

    user.setId(getNewUserId());

    cout << "Enter Password: ";
    string password;//Mozna dodac opcje sprawdzania formatu hasla
    cin.sync();
    password = UnasignedMethods::takeLine();
    user.setPassword(password);

    cout <<  "Enter Name: ";
    string name;
    name = UnasignedMethods::takeLine();
    user.setName(name);

    cout << "Enter Surname: ";
    string surname;
    surname = UnasignedMethods::takeLine();
    user.setSurname(surname);

    return user;
}

bool UserManager::isLoginOccupied(string login) {
    for (int i = 0; i < users.size(); i++) {
        if (users[i].getLogin() == login) {
            cout << endl << "User with this login already exists!" << endl;
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
        cout << users[i].getId() << endl;
        cout << users[i].getLogin() << endl;
        cout << users[i].getPassword() << endl;
        cout << users[i].getName() << endl;
        cout << users[i].getSurname() << endl;
    }
}

int UserManager::login() {
    User user;
    string inputLogin = "", inputPassword = "";

    cout << endl << "Enter login: ";
    inputLogin = UnasignedMethods::takeLine();

    for (vector<User>::iterator itr = users.begin(), vecEnd = users.end(); itr < vecEnd; itr++) {
        if (itr -> getLogin() == inputLogin) {
            for (int numberOfTries = 3; numberOfTries > 0; numberOfTries--) {
                cout << "Enter password. (Number of tries left: " << numberOfTries << ") : ";
                inputPassword = UnasignedMethods::takeLine();
                if (itr -> getPassword() == inputPassword) {
                    cout << "You have successfully logged in."<< endl << endl;
                    system("pause");
                    loggedInUserId = itr -> getId();
                    return loggedInUserId;
                }
            }
            cout << "You entered wrong password 3 times." << endl;
            system("pause");
            return 0;
        }
    }
    cout << "There is no User with this login!" << endl << endl;
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

    string newPassword;
    string oldPassword;
    cout << "Enter new password: ";
    newPassword = UnasignedMethods::takeLine();
    cout << "Enter old password: ";
    oldPassword = UnasignedMethods::takeLine();

    for (vector<User>::iterator itr = users.begin(), vecEnd = users.end(); itr!= vecEnd; itr++) {
        if (itr->getId() == loggedInUserId) {
            if (itr->getPassword() != oldPassword){
                cout << "Old password wrong!" << endl;
                getch();
                return;
            }
            itr->setPassword(newPassword);
            cout << "Password has been changed. "<< endl << endl;

            userFile.changePasswordInFile(loggedInUserId, newPassword);
            system("pause");
        }
    }


}
