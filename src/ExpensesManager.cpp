#include "ExpensesManager.h"


void ExpensesManager::addExpense() {

    Expense expense;

    system ("cls");
    std::cout << " >>> ADDING NEW EXPENSE <<< " << std::endl;
    expense = getNewExpenseData ();
    expenses.push_back(expense);

    expensesFile.addExpenseToFile(expense);
    std::cout << std::endl << "Expense has been added successfully."<< std::endl << std::endl;
    system("pause");
    std::cout << std::endl;
}

Expense ExpensesManager::getNewExpenseData() {

    Expense expense;
    expense.setExpenseId((expensesFile.getLastExpenseId()+1));
    expense.setUserId(LOGGED_IN_USER_ID);

    std::cout << "Enter expense name: ";
    expense.setItem(UnasignedMethods::takeLine());

    std::cout << "Enter the amount in format _ _ _ _ _ _ _ _ ._ _ : ";

    expense.setAmount(UnasignedMethods::takeLine());

    std::cout << "To add expense with current date press '1', to add expense with custom date press '2'." <<std::endl;

    char choice = UnasignedMethods::takeChar();
    switch (choice) {
    case '1':
        expense.setDate(DateOperations::getSystemDate());
        break;
    case '2':
        std::cout << "Enter expense date in format yyyy-mm-dd (starting from 2000-01-01) : ";
        expense.setDate(UnasignedMethods::takeLine());
        break;
    default:
        std::cout << std::endl << "There is no such option - expense added with current date." << std::endl << std::endl;
        expense.setDate(DateOperations::getSystemDate());
        system("pause");
        break;
    }

    return expense;
}

void ExpensesManager::printAllExpenses() {

    system("cls");
    if(!expenses.empty()) {
        std::cout << "            >>>EXPENSES<<<" << std::endl;
        std::cout << "-----------------------------------------------" << std::endl;
        for (std::vector<Expense>::iterator itr = expenses.begin(), VecEnd = expenses.end(); itr!= VecEnd; itr++) {
            printExpense(*itr);
        }
        std::cout << std::endl;
    } else {
        std::cout << std::endl << "There are no expenses."<< std::endl << std::endl;
    }
    getch();
}

void ExpensesManager::printExpense(Expense expense) {

    std::cout << std::endl << "Expense Id:                " << expense.getExpenseId() << std::endl;
    //cout << "UserId:                    " << expense.getUserId() << endl;
    std::cout << "Expense name:              " << expense.getItem() << std::endl;
    std::cout << "Expense amount:            " << expense.getAmount() << std::endl;
    std::cout << "Date:                      " << expense.getDate() << std::endl;
    //cout << "Date to sort:              " << expense.getDateToSort() << endl;
}

std::vector<Expense> ExpensesManager::getExpenses() {
    return expenses;
}
