#ifndef INCOMESFILE_H
#define INCOMESFILE_H

#include <iostream>
#include <vector>
#include <conio.h>
#include <string>

#include "Income.h"
#include "FileXml.h"
#include "UnasignedMethods.h"

class IncomesFile : public FileXml {

    int lastIncomeId;
    const std::string INCOMES_FILE_NAME;
public:
    IncomesFile (std::string incomesFileName) : INCOMES_FILE_NAME (incomesFileName) {
    };
    int getLastIncomeId();
    void addIncomeToFile(Income income);
    std::vector<Income> loadLoggedInUserIncomes(int loggedInUserId);

};


#endif // INCOMESFILE_H
