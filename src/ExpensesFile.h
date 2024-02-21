#ifndef EXPENSESFILE_H
#define EXPENSESFILE_H

#include <iostream>
#include <vector>
#include <conio.h>
#include <string>

#include "Expense.h"
#include "FileXml.h"
#include "UnasignedMethods.h"


class ExpensesFile : public FileXml {

    int lastExpenseId;
    const std::string EXPENSES_FILE_NAME;

public:
    ExpensesFile (std::string expensesFileName) : EXPENSES_FILE_NAME(expensesFileName) {
    };
    int getLastExpenseId();
    void addExpenseToFile (Expense expense);
    std::vector<Expense> loadLoggedInUserExpenses(int loggedInUserId);
};


#endif // EXPENSESFILE_H
