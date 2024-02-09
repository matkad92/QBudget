#ifndef MONEYMANAGER_H
#define MONEYMANAGER_H

#include <iostream>
#include <algorithm>
#include <iomanip>

#include "ExpensesManager.h"
#include "IncomesManager.h"

using namespace std;

class MoneyManager {

    const int LOGGED_IN_USER_ID;

    ExpensesManager expensesManager;
    IncomesManager incomesManager;
    int takeMonthFromDate(string dateFromVector);
    int takeYearFromDate(string dateFromVector);
    void printChosenIncomesAndExpenses(vector<Income> incomes, vector<Expense> expenses);
    void printBalance (vector<Income> incomes, vector<Expense> expenses);



public:
    MoneyManager (string expensesFileName, string incomesFileName, int loggedInUserId) :
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
