#include "UnasignedMethods.h"

std::string UnasignedMethods::takeLine(){
    std::string input = "";
    getline(std::cin, input);
    return input;
}

char UnasignedMethods::takeChar() {
    std::string input = "";
    char choice = {0};

    while (true) {
        getline(std::cin, input);

        if (input.length() == 1) {
            choice = input[0];
            break;
        }
        std::cout << "This is not correct choice. Choose again." << std::endl;
    }
        return choice;
}
