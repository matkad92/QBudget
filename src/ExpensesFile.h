#ifndef EXPENSESFILE_H
#define EXPENSESFILE_H

#include <iostream>
#include <vector>
#include <conio.h>
#include <string>

#include "Expense.h"
#include "FileXml.h"
#include "UnasignedMethods.h"

using namespace std;

class ExpensesFile : public FileXml {

    int lastExpenseId;
    const string EXPENSES_FILE_NAME;

public:
    ExpensesFile (string expensesFileName) : EXPENSES_FILE_NAME(expensesFileName) {
    };
    int getLastExpenseId();
    void addExpenseToFile (Expense expense);
    vector<Expense> loadLoggedInUserExpenses(int loggedInUserId);
};


#endif // EXPENSESFILE_H
