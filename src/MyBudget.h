// #include <iostream>
#include "UserManager.h"
#include "MoneyManager.h"
#include <memory>
#include "dbmanager.h"


class MyBudget {
    std::shared_ptr<DbManager> dbManager;
    UserManager userManager;
    int loggedInUserId;
    std::unique_ptr<MoneyManager> moneyManager;
    const std::string EXPENSES_FILE_NAME;
    const std::string INCOMES_FILE_NAME;

public:
    MyBudget (std::string userFileName, std::string expensesFileName, std::string incomesFileName):
        dbManager(std::make_shared<DbManager>()), userManager(userFileName, dbManager), EXPENSES_FILE_NAME(expensesFileName), INCOMES_FILE_NAME (incomesFileName){
        loggedInUserId = 0;
        moneyManager.reset();
        // dbManager = std::make_unique<DbManager>();
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
