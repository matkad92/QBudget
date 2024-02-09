#include "UnasignedMethods.h"

string UnasignedMethods::takeLine(){
    string input = "";
    getline(cin, input);
    return input;
}

char UnasignedMethods::takeChar() {
    string input = "";
    char choice = {0};

    while (true) {
        getline(cin, input);

        if (input.length() == 1) {
            choice = input[0];
            break;
        }
        cout << "This is not correct choice. Choose again." << endl;
    }
        return choice;
}
