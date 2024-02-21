#include "UserFile.h"

void UserFile::addUserToFile(User user) {

    CMarkup users;
    bool fileExists = users.Load(USER_FILE_NAME);//zwraca true gdzy plik udalo sie otworzyc

    if (!fileExists) {
        users.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        users.AddElem("Users");//dodaje element na pozycji glownej
    }

    users.FindElem();//przestawia glowna pozycje na "rodzenstwo"
    users.IntoElem();//ustawia galaz jako glowna , na ktorej mozna pracowac
    users.AddElem("User");
    users.IntoElem();
    users.AddElem("UserId", user.getId());
    users.AddElem("Login", user.getLogin());
    users.AddElem("Password", user.getPassword());
    users.AddElem("Name", user.getName());
    users.AddElem("Surname", user.getSurname());

    users.Save(USER_FILE_NAME);
}

std::vector<User> UserFile::loadUsersFromXml() {

    User user;
    std::vector<User> loadedUsers;
    CMarkup usersXml;
    std::string IdString;
    bool fileExists = usersXml.Load(USER_FILE_NAME);//zwraca true gdzy plik udalo sie otworzyc
    if (!fileExists) {
        std::cout << "There is no file: " << USER_FILE_NAME << std::endl << "If You want to continue, create new user."<< std::endl;
        getch();
    } else {
        usersXml.ResetPos();
        usersXml.FindElem();
        usersXml.IntoElem();

        while (usersXml.FindElem("User")) {
            usersXml.IntoElem();
            usersXml.FindElem("UserId");
            IdString = usersXml.GetData();
            user.setId(atoi(IdString.c_str()));
            usersXml.FindElem("Login");
            user.setLogin(usersXml.GetData());
            usersXml.FindElem("Password");
            user.setPassword(usersXml.GetData());
            usersXml.FindElem("Name");
            user.setName(usersXml.GetData());
            usersXml.FindElem("Surname");
            user.setSurname(usersXml.GetData());
            usersXml.OutOfElem();

            loadedUsers.push_back(user);

        }
    }
    return loadedUsers;
}

void UserFile::changePasswordInFile(int userId, std::string newPassword) {

    std::string loggedInUserIdString = std::to_string(userId);
    std::string idStringFromFile;
    CMarkup usersXml;

    bool fileExists = usersXml.Load(USER_FILE_NAME);//zwraca true gdzy plik udalo sie otworzyc
    if (!fileExists) {
        std::cout << "No " << USER_FILE_NAME << "file found."<< std::endl;
        getch();
    } else {
        usersXml.ResetPos();
        usersXml.FindElem();
        usersXml.IntoElem();

        while (usersXml.FindElem("User")) {
            usersXml.IntoElem();
            usersXml.FindElem("UserId");
            idStringFromFile = usersXml.GetData();

            if (loggedInUserIdString == idStringFromFile){
                usersXml.FindElem("Password");
                usersXml.SetData(newPassword);
            }

            usersXml.OutOfElem();

        }
    }
    usersXml.Save(USER_FILE_NAME);
}
