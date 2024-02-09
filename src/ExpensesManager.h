#ifndef EXPENSESMANAGER_H
#define EXPENSESMANAGER_H

#include <iostream>
#include <vector>
#include <conio.h>
#include "Expense.h"
#include "ExpensesFile.h"
#include "DateOperations.h"


using namespace std;

class ExpensesManager {



    vector <Expense> expenses;
    const string EXPENSES_FILE_NAME;
    const int LOGGED_IN_USER_ID;
    ExpensesFile expensesFile;
    void printExpense(Expense expense);

public:
    ExpensesManager (string expensesFileName, int loggedInUserId) : LOGGED_IN_USER_ID (loggedInUserId), EXPENSES_FILE_NAME(expensesFileName), expensesFile(expensesFileName) {
        expenses = expensesFile.loadLoggedInUserExpenses(LOGGED_IN_USER_ID);
    };
    void addExpense();
    Expense getNewExpenseData();
    void printAllExpenses();
    vector <Expense> getExpenses();

    friend class MoneyManager;



};


#endif // EXPENSESMANAGER_H
