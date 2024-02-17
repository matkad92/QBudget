#include "IncomesManager.h"

void IncomesManager::addIncome() {

    Income income;

    system ("cls");
    std::cout << " >>> ADDING NEW INCOME <<< " << std::endl;
    income = getNewIncomeData ();
    if(income.objectCorrectState){
        incomes.push_back(income);

        incomesFile.addIncomeToFile(income);
        std::cout << std::endl << "Income has been added successfully."<< std::endl << std::endl;
        system("pause");
        std::cout << std::endl;
    }
    else {
        std::cout << std::endl << "Income not added."<< std::endl << std::endl;
        system("pause");
        std::cout << std::endl;
    }

}

Income IncomesManager::getNewIncomeData () {

    Income income;
    income.setIncomeId((incomesFile.getLastIncomeId()+1));
    income.setUserId(LOGGED_IN_USER_ID);

    std::cout << "Enter income name: ";
    income.setItem(UnasignedMethods::takeLine());

    std::cout << "Enter the amount in format _ _ _ _ _ _ _ _ ._ _ : ";

    income.setAmount(UnasignedMethods::takeLine());

    std::cout << "To add income with current date press '1', to add income with custom date press '2'." << std::endl;

    char choice = UnasignedMethods::takeChar();
    switch (choice) {
    case '1':
        income.setDate(DateOperations::getSystemDate());
        break;
    case '2':
        std::cout << "Enter income date in format yyyy-mm-dd (starting from 2000-01-01) : ";
        income.setDate(UnasignedMethods::takeLine());
        break;
    default:
        std::cout << std::endl << "There is no such option - income added with current date." << std::endl << std::endl;
        income.objectCorrectState = false;
        system("pause");
        break;
    }

    return income;
}

void IncomesManager::printAllIncomes() {

    system("cls");
    if(!incomes.empty()) {
        std::cout << "            >>>INCOMES<<<" << std::endl;
        std::cout << "-----------------------------------------------" << std::endl;
        for (std::vector<Income>::iterator itr = incomes.begin(), VecEnd = incomes.end(); itr!= VecEnd; itr++) {
            printIncome(*itr);
        }
        std::cout << std::endl;
    } else {
        std::cout << std::endl << "There are no incomes."<< std::endl << std::endl;
    }
    getch();
}

void IncomesManager::printIncome(Income income) {

    std::cout << std::endl << "Income Id:                 " << income.getIncomeId() << std::endl;
    //cout << "UserId:                    " << income.getUserId() << endl;
    std::cout << "Income name:               " << income.getItem() << std::endl;
    std::cout << "Income amount:             " << income.getAmount() << std::endl;
    std::cout << "Date:                      " << income.getDate() << std::endl;
    //cout << "Date to sort:              " << income.getDateToSort() << endl;
}

std::vector<Income> IncomesManager::getIncomes() {
    return incomes;
}

