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
    cout << "    >>> MAIN MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. User register" << endl;
    cout << "2. User login" << endl;
    cout << "9. Exite" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = UnasignedMethods::takeChar();

    return choice;
}

char MyBudget::chooseUserMenuOption() {
    char choice;

    system("cls");
    cout << "    >>> USER MENU <<<" << endl; //mozna dodac wyswietlanie imienia uzytkownika
    cout << "---------------------------" << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add expense" << endl;
    cout << "3. Current month balance" << endl;
    cout << "4. Last month balance" << endl;
    cout << "5. Chosen period balance" << endl;
    cout << "6. Change password" << endl;
    cout << "9. Log out" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
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
