#ifndef INCOMESFILE_H
#define INCOMESFILE_H

#include <iostream>
#include <vector>
#include <conio.h>
#include <string>

#include "Income.h"
#include "FileXml.h"
#include "UnasignedMethods.h"

using namespace std;

class IncomesFile : public FileXml {

    int lastIncomeId;
    const string INCOMES_FILE_NAME;
public:
    IncomesFile (string incomesFileName) : INCOMES_FILE_NAME (incomesFileName) {
    };
    int getLastIncomeId();
    void addIncomeToFile(Income income);
    vector<Income> loadLoggedInUserIncomes(int loggedInUserId);

};


#endif // INCOMESFILE_H
