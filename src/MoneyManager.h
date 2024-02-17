#ifndef MONEYMANAGER_H
#define MONEYMANAGER_H

#include <iostream>
#include <algorithm>
#include <iomanip>

#include "ExpensesManager.h"
#include "IncomesManager.h"

class MoneyManager {

    const int LOGGED_IN_USER_ID;

    ExpensesManager expensesManager;
    IncomesManager incomesManager;
    DateOperations dateOperations;
    int takeMonthFromDate(std::string dateFromVector);
    int takeYearFromDate(std::string dateFromVector);
    void printChosenIncomesAndExpenses(std::vector<Income> incomes, std::vector<Expense> expenses);
    void printBalance (std::vector<Income> incomes, std::vector<Expense> expenses);



public:
    MoneyManager (std::string expensesFileName, std::string incomesFileName, int loggedInUserId) :
        LOGGED_IN_USER_ID (loggedInUserId), expensesManager(expensesFileName, loggedInUserId), incomesManager(incomesFileName, loggedInUserId) {
    };

    void addIncome();
    void printAllIncomes();
    void addExpense();
    void printAllExpenses();
    void balanceForTheCurrentMonth();
    void balanceForTheLastMonth();
    void balanceFromChoosenPeriod();

};


#endif // MONEYMANAGER_H
