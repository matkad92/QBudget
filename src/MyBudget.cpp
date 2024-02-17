#include "MyBudget.h"

void MyBudget::userRegister() {
    userManager.userRegister();
}

void MyBudget::printAllUsers() {
    userManager.printAllUsers();
}

void MyBudget::changePassword() {
    userManager.changePassword();
}

void MyBudget::userLogin() {
    userManager.login();
    if (userManager.isUserLoggedIn()) {
        moneyManager =  new MoneyManager (EXPENSES_FILE_NAME , INCOMES_FILE_NAME, userManager.getLoggedInUserId());
    }
}

void MyBudget::logout() {
    userManager.logout();
    delete moneyManager;
    moneyManager = NULL;
}

bool MyBudget::isUserLoggedOut() {
    if (userManager.getLoggedInUserId() == 0) return true;
    else return false;
}

char MyBudget::chooseMainMenuOption() {
    char choice;

    system("cls");
    std::cout << "    >>> MAIN MENU <<<" << std::endl;
    std::cout << "---------------------------" << std::endl;
    std::cout << "1. User register" << std::endl;
    std::cout << "2. User login" << std::endl;
    std::cout << "9. Exite" << std::endl;
    std::cout << "---------------------------" << std::endl;
    std::cout << "Your choice: ";
    choice = UnasignedMethods::takeChar();

    return choice;
}

char MyBudget::chooseUserMenuOption() {
    char choice;

    system("cls");
    std::cout << "    >>> USER MENU <<<" << std::endl; //mozna dodac wyswietlanie imienia uzytkownika
    std::cout << "---------------------------" << std::endl;
    std::cout << "1. Add income" << std::endl;
    std::cout << "2. Add expense" << std::endl;
    std::cout << "3. Current month balance" << std::endl;
    std::cout << "4. Last month balance" << std::endl;
    std::cout << "5. Chosen period balance" << std::endl;
    std::cout << "6. Change password" << std::endl;
    std::cout << "9. Log out" << std::endl;
    std::cout << "---------------------------" << std::endl;
    std::cout << "Your choice: ";
    choice = UnasignedMethods::takeChar();

    return choice;
}

void MyBudget::addIncome() {
    moneyManager->addIncome();
}

void MyBudget::printAllIncomes() {
    moneyManager->printAllIncomes();
}

void MyBudget::addExpense() {
    moneyManager->addExpense();
}

void MyBudget::printAllExpenses() {
    moneyManager->printAllExpenses();
}

void MyBudget::balanceForTheCurrentMonth() {
    moneyManager->balanceForTheCurrentMonth();
}

void MyBudget::balanceForTheLastMonth() {
    moneyManager->balanceForTheLastMonth();
}

void MyBudget::balanceFromChoosenPeriod() {
    moneyManager->balanceFromChoosenPeriod();
}
