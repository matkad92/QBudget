#include "IncomesManager.h"

void IncomesManager::addIncome() {

    Income income;

    system ("cls");
    cout << " >>> ADDING NEW INCOME <<< " << endl;
    income = getNewIncomeData ();
    incomes.push_back(income);

    incomesFile.addIncomeToFile(income);
    cout << endl << "Income has been added successfully."<< endl << endl;
    system("pause");
    cout << endl;

}

Income IncomesManager::getNewIncomeData () {

    Income income;
    income.setIncomeId((incomesFile.getLastIncomeId()+1));
    income.setUserId(LOGGED_IN_USER_ID);

    cout << "Enter income name: ";
    income.setItem(UnasignedMethods::takeLine());

    cout << "Enter the amount in format _ _ _ _ _ _ _ _ ._ _ : ";

    income.setAmount(UnasignedMethods::takeLine());

    cout << "To add income with current date press '1', to add income with custom date press '2'." <<endl;

    char choice = UnasignedMethods::takeChar();
    switch (choice) {
    case '1':
        income.setDate(DateOperations::getSystemDate());
        break;
    case '2':
        cout << "Enter income date in format yyyy-mm-dd (starting from 2000-01-01) : ";
        income.setDate(UnasignedMethods::takeLine());
        break;
    default:
        cout << endl << "There is no such option - income added with current date." << endl << endl;
        income.setDate(DateOperations::getSystemDate());
        system("pause");
        break;
    }

    return income;
}

void IncomesManager::printAllIncomes() {

    system("cls");
    if(!incomes.empty()) {
        cout << "            >>>INCOMES<<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector<Income>::iterator itr = incomes.begin(), VecEnd = incomes.end(); itr!= VecEnd; itr++) {
            printIncome(*itr);
        }
        cout << endl;
    } else {
        cout << endl << "There are no incomes."<< endl << endl;
    }
    getch();
}

void IncomesManager::printIncome(Income income) {

    cout << endl << "Income Id:                 " << income.getIncomeId() << endl;
    //cout << "UserId:                    " << income.getUserId() << endl;
    cout << "Income name:               " << income.getItem() << endl;
    cout << "Income amount:             " << income.getAmount() << endl;
    cout << "Date:                      " << income.getDate() << endl;
    //cout << "Date to sort:              " << income.getDateToSort() << endl;
}

vector<Income> IncomesManager::getIncomes() {
    return incomes;
}

