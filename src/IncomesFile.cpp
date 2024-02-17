#include "IncomesFile.h"

int IncomesFile::getLastIncomeId() {
    return lastIncomeId;
}

void IncomesFile::addIncomeToFile(Income income) {
    CMarkup incomes;
    bool fileExists = incomes.Load(INCOMES_FILE_NAME);//zwraca true gdzy plik udalo sie otworzyc

    if (!fileExists) {
        incomes.SetDoc(R"(<?xml version="1.0" encoding="UTF-8"?>\r\n)");
        incomes.AddElem("Incomes");//dodaje element na pozycji glownej
    }

    incomes.FindElem();//przestawia glowna pozycje na "rodzenstwo"
    incomes.IntoElem();//ustawia galaz jako glowna , na ktorej mozna pracowac
    incomes.AddElem("Income");
    incomes.IntoElem();
    incomes.AddElem("IncomeId", income.getIncomeId());
    incomes.AddElem("UserId", income.getUserId());
    incomes.AddElem("IncomeName", income.getItem());
    incomes.AddElem("Amount", income.getAmountString());
    incomes.AddElem("Date", income.getDate());
    incomes.AddElem("DateToSort", income.getDateToSort());

    if (!incomes.Save(INCOMES_FILE_NAME)) {
        std::cerr << "Error: Failed to save the XML file." << std::endl;
        return;
    }
    lastIncomeId++;
}

std::vector<Income> IncomesFile::loadLoggedInUserIncomes(int loggedInUserId) {

    Income income;
    std::vector<Income> loadedIncomes;

    CMarkup incomesXml;
    std::string incomeIdString, userIdString, amountString;

    bool fileExists = incomesXml.Load(INCOMES_FILE_NAME);
    if (!fileExists) {
        std::cout << "There is no file: " << INCOMES_FILE_NAME << std::endl << "  No incomes loaded."<< std::endl;
        lastIncomeId = 0;
        getch();
    } else {
        incomesXml.ResetPos();
        incomesXml.FindElem();
        incomesXml.IntoElem();

        while (incomesXml.FindElem("Income")) {
            incomesXml.IntoElem();

            incomesXml.FindElem("IncomeId");
            incomeIdString = incomesXml.GetData();
            income.setIncomeId(atoi(incomeIdString.c_str()));

            incomesXml.FindElem("UserId");
            userIdString = incomesXml.GetData();
            income.setUserId(atoi(userIdString.c_str()));

            incomesXml.FindElem("IncomeName");
            income.setItem(incomesXml.GetData());

            incomesXml.FindElem("Amount");
            amountString = incomesXml.GetData();
            income.setAmount(amountString);

            incomesXml.FindElem("Date");
            income.setDate(incomesXml.GetData());

            incomesXml.OutOfElem();
            lastIncomeId = income.getIncomeId();

            if (income.getUserId() == loggedInUserId) loadedIncomes.push_back(income);
        }

    }


    return loadedIncomes;
}






