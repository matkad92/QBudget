#include <iostream>
#include "UserManager.h"
#include "MoneyManager.h"


using namespace std;

class MyBudget {
    UserManager userManager;
    int loggedInUserId;
    MoneyManager *moneyManager;
    const string EXPENSES_FILE_NAME;
    const string INCOMES_FILE_NAME;

public:
    MyBudget(string userFileName, string expensesFileName, string incomesFileName): userManager(userFileName), EXPENSES_FILE_NAME(expensesFileName), INCOMES_FILE_NAME (incomesFileName){
        loggedInUserId = 0;
        moneyManager =  NULL;
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
