#include "MoneyManager.h"

void MoneyManager::addIncome() {
    incomesManager.addIncome();
}

void MoneyManager::printAllIncomes() {
    incomesManager.printAllIncomes();
}

void MoneyManager::addExpense() {
    expensesManager.addExpense();
}

void MoneyManager::printAllExpenses() {
    expensesManager.printAllExpenses();
}

void MoneyManager::balanceForTheCurrentMonth() {

    std::vector<Income> currentMonthIncomes;
    std::vector<Expense> currentMonthExpenses;

    std::string dateFromVector;
    int monthToCompare;
    int yearToCompare;

    time_t localTime;
    struct tm * ptr;
    time( & localTime );
    ptr = localtime( & localTime );

    for (int i = 0; i < expensesManager.expenses.size(); i++) {
        dateFromVector = expensesManager.expenses[i].getDate();

        monthToCompare = takeMonthFromDate(dateFromVector);
        yearToCompare = takeYearFromDate(dateFromVector);

        if (yearToCompare == (ptr->tm_year+1900) && monthToCompare == (ptr->tm_mon+1)) {
            currentMonthExpenses.push_back(expensesManager.expenses[i]);

        }
    }

    for (int i = 0; i < incomesManager.incomes.size(); i++) {
        dateFromVector = incomesManager.incomes[i].getDate();

        monthToCompare = takeMonthFromDate(dateFromVector);
        yearToCompare = takeYearFromDate(dateFromVector);

        if (yearToCompare == (ptr->tm_year+1900) && monthToCompare == (ptr->tm_mon+1)) {
            currentMonthIncomes.push_back(incomesManager.incomes[i]);

        }
    }


    std::sort(currentMonthIncomes.begin(), currentMonthIncomes.end());
    std::sort(currentMonthExpenses.begin(), currentMonthExpenses.end());

    printChosenIncomesAndExpenses(currentMonthIncomes, currentMonthExpenses);
    printBalance (currentMonthIncomes, currentMonthExpenses);
}

void MoneyManager::balanceForTheLastMonth() {

    std::vector<Income> lastMonthIncomes;
    std::vector<Expense> lastMonthExpenses;

    std::string dateFromVector;
    int monthToCompare;
    int yearToCompare;

    time_t localTime;
    struct tm * ptr;
    time( & localTime );
    ptr = localtime( & localTime );

    int prevoiusMonth;
    int previousMonthYear;

    if ((ptr->tm_mon+1) > 1) {
        prevoiusMonth = (ptr->tm_mon);
        previousMonthYear = (ptr->tm_year+1900);
    } else if ((ptr->tm_mon+1) == 1) {
        prevoiusMonth = 12;
        previousMonthYear = (ptr->tm_year+1900) - 1;
    }

    for (int i = 0; i < expensesManager.expenses.size(); i++) {
        dateFromVector = expensesManager.expenses[i].getDate();

        monthToCompare = takeMonthFromDate(dateFromVector);
        yearToCompare = takeYearFromDate(dateFromVector);

        if (yearToCompare == previousMonthYear && monthToCompare == prevoiusMonth) {
            lastMonthExpenses.push_back(expensesManager.expenses[i]);
        }
    }

    for (int i = 0; i < incomesManager.incomes.size(); i++) {
        dateFromVector = incomesManager.incomes[i].getDate();

        monthToCompare = takeMonthFromDate(dateFromVector);
        yearToCompare = takeYearFromDate(dateFromVector);

        if (yearToCompare == previousMonthYear && monthToCompare == prevoiusMonth) {
            lastMonthIncomes.push_back(incomesManager.incomes[i]);
        }
    }


    sort(lastMonthIncomes.begin(), lastMonthIncomes.end());
    sort(lastMonthExpenses.begin(), lastMonthExpenses.end());

    printChosenIncomesAndExpenses(lastMonthIncomes, lastMonthExpenses);
    printBalance (lastMonthIncomes, lastMonthExpenses);
}

void MoneyManager::balanceFromChoosenPeriod() {

    std::vector<Income> ChoosenPeriodIncomes;
    std::vector<Expense> ChoosenPeriodExpenses;



    std::string dateFromVector, startingDate, endingDate;
    std::cout << "Choose starting date ( rrrr-mm-dd ):";
    // string startingDate = DateOperations::inputCorrectDateFormat();
    if(!dateOperations.getDateIncorrectFormatToString(startingDate)){
        // std::cout << "";
        // getch();
        return;
    }
    std::cout << std::endl << "Choose ending date ( rrrr-mm-dd ):";
    // string endingDate = DateOperations::inputCorrectDateFormat();
    if(!dateOperations.getDateIncorrectFormatToString(endingDate)){
        // std::cout << "";
        // getch();
        return;
    }
    if (!(DateOperations::isDateSmallerThanEndingDate(startingDate,endingDate))) {
        std::cout << "Wrong dates! Starting date can not be more recent than ending date.";
        getch();
        return;
    }


    for (int i = 0; i < expensesManager.expenses.size(); i++) {
        dateFromVector = expensesManager.expenses[i].getDate();


        if (DateOperations::isDateSmallerThanEndingDate(dateFromVector,endingDate) && DateOperations::isDateBiggerOrEqualThanStartingDate(dateFromVector,startingDate)) {
            ChoosenPeriodExpenses.push_back(expensesManager.expenses[i]);
        }
    }

    for (int i = 0; i < incomesManager.incomes.size(); i++) {
        dateFromVector = incomesManager.incomes[i].getDate();


        if (DateOperations::isDateSmallerThanEndingDate(dateFromVector,endingDate) && DateOperations::isDateBiggerOrEqualThanStartingDate(dateFromVector,startingDate)) {
            ChoosenPeriodIncomes.push_back(incomesManager.incomes[i]);
        }
    }


    sort(ChoosenPeriodIncomes.begin(), ChoosenPeriodIncomes.end());
    sort(ChoosenPeriodExpenses.begin(), ChoosenPeriodExpenses.end());

    printChosenIncomesAndExpenses(ChoosenPeriodIncomes, ChoosenPeriodExpenses);
    printBalance (ChoosenPeriodIncomes, ChoosenPeriodExpenses);

}

int MoneyManager::takeMonthFromDate(std::string dateFromVector) {

    int month;
    std::string monthString;

    monthString = dateFromVector.substr(5,2);
    month = atoi(monthString.c_str());

    return month;
}

int MoneyManager::takeYearFromDate(std::string dateFromVector) {

    int year;
    std::string yearString;

    yearString = dateFromVector.substr(0,4);
    year = atoi(yearString.c_str());

    return year;
}

void MoneyManager::printChosenIncomesAndExpenses(std::vector<Income> incomes, std::vector<Expense> expenses) {

    system("cls");

    if(!incomes.empty()) {
        std::cout << "            >>>INCOMES<<<" << std::endl;
        std::cout << "-----------------------------------------------" << std::endl;
        for (std::vector<Income>::iterator itr = incomes.begin(), VecEnd = incomes.end(); itr!= VecEnd; itr++) {
            incomesManager.printIncome(*itr);
        }
        std::cout << std::endl << std::endl << std::endl;
    } else {
        std::cout << std::endl << "There are no incomes."<< std::endl << std::endl;
    }

    if(!expenses.empty()) {
        std::cout << "            >>>EXPENSES<<<" << std::endl;
        std::cout << "-----------------------------------------------" << std::endl;
        for (std::vector<Expense>::iterator itr = expenses.begin(), VecEnd = expenses.end(); itr != VecEnd; itr++) {
            expensesManager.printExpense(*itr);
        }
        std::cout << std::endl;
    } else {
        std::cout << std::endl << "There are no expenses."<< std::endl << std::endl;
    }

}

void MoneyManager::printBalance (const std::vector<Income> &incomes, const std::vector<Expense> &expenses) {

    double incomesSum = 0,  expensesSum = 0;

    for (std::vector<Income>::iterator itr = incomes.begin(), vecEnd = incomes.end(); itr != vecEnd; itr++) {
        incomesSum += itr->getAmount();
    }
    for (std::vector<Expense>::iterator itr = expenses.begin(), vecEnd = expenses.end(); itr != vecEnd; itr++) {
        expensesSum += itr->getAmount();
    }

    double balance = incomesSum - expensesSum;

    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << "INCOMES SUM : " << std::fixed << std::setprecision(2) << incomesSum << std::endl;
    std::cout << "EXPENSES SUM : " << std::fixed << std::setprecision(2) << expensesSum << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << "BALANCE : " << std::fixed << std::setprecision(2) << balance << std::endl;

    if (balance <= 0) std::cout << std::endl << "YOU SHOULD HAVE SAVED MORE! " << std::endl;

    getch();

}

