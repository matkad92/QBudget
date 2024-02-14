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

    vector<Income> currentMonthIncomes;
    vector<Expense> currentMonthExpenses;

    string dateFromVector;
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


    sort(currentMonthIncomes.begin(), currentMonthIncomes.end());
    sort(currentMonthExpenses.begin(), currentMonthExpenses.end());

    printChosenIncomesAndExpenses(currentMonthIncomes, currentMonthExpenses);
    printBalance (currentMonthIncomes, currentMonthExpenses);
}

void MoneyManager::balanceForTheLastMonth() {

    vector<Income> lastMonthIncomes;
    vector<Expense> lastMonthExpenses;

    string dateFromVector;
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

    vector<Income> ChoosenPeriodIncomes;
    vector<Expense> ChoosenPeriodExpenses;



    string dateFromVector, startingDate, endingDate;
    cout << "Choose starting date ( rrrr-mm-dd ):";
    // string startingDate = DateOperations::inputCorrectDateFormat();
    if(!dateOperations.getDateIncorrectFormatToString(startingDate)){
        // std::cout << "";
        // getch();
        return;
    }
    cout << endl << "Choose ending date ( rrrr-mm-dd ):";
    // string endingDate = DateOperations::inputCorrectDateFormat();
    if(!dateOperations.getDateIncorrectFormatToString(endingDate)){
        // std::cout << "";
        // getch();
        return;
    }
    if (!(DateOperations::isDateSmallerThanEndingDate(startingDate,endingDate))) {
        cout << "Wrong dates! Starting date can not be more recent than ending date.";
        getch();
        return;
    }


    for (int i = 0; i < expensesManager.expenses.size(); i++) {
        dateFromVector = expensesManager.expenses[i].getDate();


        if (DateOperations::isDateSmallerThanEndingDate(dateFromVector,endingDate) && DateOperations::isDateBiggerThanStartingDate(dateFromVector,startingDate)) {
            ChoosenPeriodExpenses.push_back(expensesManager.expenses[i]);
        }
    }

    for (int i = 0; i < incomesManager.incomes.size(); i++) {
        dateFromVector = incomesManager.incomes[i].getDate();


        if (DateOperations::isDateSmallerThanEndingDate(dateFromVector,endingDate) && DateOperations::isDateBiggerThanStartingDate(dateFromVector,startingDate)) {
            ChoosenPeriodIncomes.push_back(incomesManager.incomes[i]);
        }
    }


    sort(ChoosenPeriodIncomes.begin(), ChoosenPeriodIncomes.end());
    sort(ChoosenPeriodExpenses.begin(), ChoosenPeriodExpenses.end());

    printChosenIncomesAndExpenses(ChoosenPeriodIncomes, ChoosenPeriodExpenses);
    printBalance (ChoosenPeriodIncomes, ChoosenPeriodExpenses);

}

int MoneyManager::takeMonthFromDate(string dateFromVector) {

    int month;
    string monthString;

    monthString = dateFromVector.substr(5,2);
    month = atoi(monthString.c_str());

    return month;
}

int MoneyManager::takeYearFromDate(string dateFromVector) {

    int year;
    string yearString;

    yearString = dateFromVector.substr(0,4);
    year = atoi(yearString.c_str());

    return year;
}

void MoneyManager::printChosenIncomesAndExpenses(vector<Income> incomes, vector<Expense> expenses) {

    system("cls");

    if(!incomes.empty()) {
        cout << "            >>>INCOMES<<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector<Income>::iterator itr = incomes.begin(), VecEnd = incomes.end(); itr!= VecEnd; itr++) {
            incomesManager.printIncome(*itr);
        }
        cout << endl << endl << endl;
    } else {
        cout << endl << "There are no incomes."<< endl << endl;
    }

    if(!expenses.empty()) {
        cout << "            >>>EXPENSES<<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector<Expense>::iterator itr = expenses.begin(), VecEnd = expenses.end(); itr != VecEnd; itr++) {
            expensesManager.printExpense(*itr);
        }
        cout << endl;
    } else {
        cout << endl << "There are no expenses."<< endl << endl;
    }

}

void MoneyManager::printBalance (vector<Income> incomes, vector<Expense> expenses) {

    double incomesSum = 0,  expensesSum = 0;

    for (vector<Income>::iterator itr = incomes.begin(), vecEnd = incomes.end(); itr != vecEnd; itr++) {
        incomesSum += itr->getAmount();
    }
    for (vector<Expense>::iterator itr = expenses.begin(), vecEnd = expenses.end(); itr != vecEnd; itr++) {
        expensesSum += itr->getAmount();
    }

    double balance = incomesSum - expensesSum;

    cout << "-----------------------------------------------" << endl;
    cout << "INCOMES SUM : " << fixed << setprecision(2) << incomesSum << endl;
    cout << "EXPENSES SUM : " << fixed << setprecision(2) << expensesSum << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "BALANCE : " << fixed << setprecision(2) << balance << endl;

    if (balance <= 0) cout << endl << "YOU SHOULD HAVE SAVED MORE! " << endl;

    getch();

}

