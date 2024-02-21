#ifndef EXPENSESMANAGER_H
#define EXPENSESMANAGER_H

#include <iostream>
#include <vector>
#include <conio.h>
#include "Expense.h"
#include "ExpensesFile.h"
#include "DateOperations.h"


class ExpensesManager {

    std::vector <Expense> expenses;
    const std::string EXPENSES_FILE_NAME;
    const int LOGGED_IN_USER_ID;
    ExpensesFile expensesFile;
    void printExpense(const Expense& expense);

public:
    ExpensesManager (std::string expensesFileName, int loggedInUserId) : LOGGED_IN_USER_ID (loggedInUserId), EXPENSES_FILE_NAME(expensesFileName), expensesFile(expensesFileName) {
        expenses = expensesFile.loadLoggedInUserExpenses(LOGGED_IN_USER_ID);
    };
    void addExpense();
    Expense getNewExpenseData();
    void printAllExpenses();
    std::vector <Expense> getExpenses();

    friend class MoneyManager;

};


#endif // EXPENSESMANAGER_H
