#include "ExpensesManager.h"


void ExpensesManager::addExpense() {

    Expense expense;

    system ("cls");
    cout << " >>> ADDING NEW EXPENSE <<< " << endl;
    expense = getNewExpenseData ();
    expenses.push_back(expense);

    expensesFile.addExpenseToFile(expense);
    cout << endl << "Expense has been added successfully."<< endl << endl;
    system("pause");
    cout << endl;
}

Expense ExpensesManager::getNewExpenseData() {

    Expense expense;
    expense.setExpenseId((expensesFile.getLastExpenseId()+1));
    expense.setUserId(LOGGED_IN_USER_ID);

    cout << "Enter expense name: ";
    expense.setItem(UnasignedMethods::takeLine());

    cout << "Enter the amount in format _ _ _ _ _ _ _ _ ._ _ : ";

    expense.setAmount(UnasignedMethods::takeLine());

    cout << "To add expense with current date press '1', to add expense with custom date press '2'." <<endl;

    char choice = UnasignedMethods::takeChar();
    switch (choice) {
    case '1':
        expense.setDate(DateOperations::getSystemDate());
        break;
    case '2':
        cout << "Enter expense date in format yyyy-mm-dd (starting from 2000-01-01) : ";
        expense.setDate(UnasignedMethods::takeLine());
        break;
    default:
        cout << endl << "There is no such option - expense added with current date." << endl << endl;
        expense.setDate(DateOperations::getSystemDate());
        system("pause");
        break;
    }

    return expense;
}

void ExpensesManager::printAllExpenses() {

    system("cls");
    if(!expenses.empty()) {
        cout << "            >>>EXPENSES<<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector<Expense>::iterator itr = expenses.begin(), VecEnd = expenses.end(); itr!= VecEnd; itr++) {
            printExpense(*itr);
        }
        cout << endl;
    } else {
        cout << endl << "There are no expenses."<< endl << endl;
    }
    getch();
}

void ExpensesManager::printExpense(Expense expense) {

    cout << endl << "Expense Id:                " << expense.getExpenseId() << endl;
    //cout << "UserId:                    " << expense.getUserId() << endl;
    cout << "Expense name:              " << expense.getItem() << endl;
    cout << "Expense amount:            " << expense.getAmount() << endl;
    cout << "Date:                      " << expense.getDate() << endl;
    //cout << "Date to sort:              " << expense.getDateToSort() << endl;
}

vector<Expense> ExpensesManager::getExpenses() {
    return expenses;
}
