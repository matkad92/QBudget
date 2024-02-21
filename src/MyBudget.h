// #include <iostream>
#include "UserManager.h"
#include "MoneyManager.h"
#include<memory>

class MyBudget {
    UserManager userManager;
    int loggedInUserId;
    std::unique_ptr<MoneyManager> moneyManager;
    const std::string EXPENSES_FILE_NAME;
    const std::string INCOMES_FILE_NAME;

public:
    MyBudget(std::string userFileName, std::string expensesFileName, std::string incomesFileName): userManager(userFileName), EXPENSES_FILE_NAME(expensesFileName), INCOMES_FILE_NAME (incomesFileName){
        loggedInUserId = 0;
        moneyManager.reset();
    }
    void userRegister();
    void printAllUsers();
    void userLogin();
    bool isUserLoggedOut();
    char chooseMainMenuOption();
    char chooseUserMenuOption();
    void changePassword();
    void logout();
    void addIncome();
    void printAllIncomes();
    void addExpense();
    void printAllExpenses();
    void balanceForTheCurrentMonth();
    void balanceForTheLastMonth();
    void balanceFromChoosenPeriod();
};
