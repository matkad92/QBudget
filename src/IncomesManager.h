#ifndef INCOMESMANAGER_H
#define INCOMESMANAGER_H

#include <iostream>
#include <vector>
#include <conio.h>


#include "Income.h"
#include "IncomesFile.h"
#include "DateOperations.h"

class IncomesManager {

    friend class MoneyManager;

    std::vector<Income> incomes;
    const std::string INCOMES_FILE_NAME;
    const int LOGGED_IN_USER_ID;
    IncomesFile incomesFile;
    void printIncome(const Income& income);


public:
    IncomesManager (std::string incomesFileName, int loggedInUserId) : LOGGED_IN_USER_ID (loggedInUserId), INCOMES_FILE_NAME(incomesFileName), incomesFile(incomesFileName) {
        // incomes = incomesFile.loadLoggedInUserIncomes(LOGGED_IN_USER_ID);
        incomesFile.loadLoggedInUserIncomes(LOGGED_IN_USER_ID, incomes);
    }
    void addIncome();
    Income getNewIncomeData();
    void printAllIncomes();
    std::vector <Income> getIncomes();

};



#endif // INCOMESMANAGER_H
