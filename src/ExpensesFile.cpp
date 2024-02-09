#include "ExpensesFile.h"

int ExpensesFile::getLastExpenseId() {
    return lastExpenseId;
}

void ExpensesFile::addExpenseToFile(Expense expense) {
    CMarkup expenses;
    bool fileExists = expenses.Load(EXPENSES_FILE_NAME);//zwraca true gdzy plik udalo sie otworzyc

    if (!fileExists) {
        expenses.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        expenses.AddElem("Expenses");//dodaje element na pozycji glownej
    }

    expenses.FindElem();//przestawia glowna pozycje na "rodzenstwo"
    expenses.IntoElem();//ustawia galaz jako glowna , na ktorej mozna pracowac
    expenses.AddElem("Expense");
    expenses.IntoElem();
    expenses.AddElem("ExpenseId", expense.getExpenseId());
    expenses.AddElem("UserId", expense.getUserId());
    expenses.AddElem("ExpenseName", expense.getItem());
    expenses.AddElem("Amount", expense.getAmountString());
    expenses.AddElem("Date", expense.getDate());
    expenses.AddElem("DateToSort", expense.getDateToSort());

    expenses.Save(EXPENSES_FILE_NAME);
    lastExpenseId++;
}

vector<Expense> ExpensesFile::loadLoggedInUserExpenses(int loggedInUserId) {

    Expense expense;
    vector<Expense> loadedExpenses;

    CMarkup expensesXml;
    string expenseIdString, userIdString, amountString;

    bool fileExists = expensesXml.Load(EXPENSES_FILE_NAME);
    if (!fileExists) {
        cout << "There is no file: " << EXPENSES_FILE_NAME << endl << "  No expenses loaded."<< endl;
        lastExpenseId = 0;
        getch();
    } else {
        expensesXml.ResetPos();
        expensesXml.FindElem();
        expensesXml.IntoElem();

        while (expensesXml.FindElem("Expense")) {
            expensesXml.IntoElem();

            expensesXml.FindElem("ExpenseId");
            expenseIdString = expensesXml.GetData();
            expense.setExpenseId(atoi(expenseIdString.c_str()));

            expensesXml.FindElem("UserId");
            userIdString = expensesXml.GetData();
            expense.setUserId(atoi(userIdString.c_str()));

            expensesXml.FindElem("ExpenseName");
            expense.setItem(expensesXml.GetData());

            expensesXml.FindElem("Amount");
            amountString = expensesXml.GetData();
            expense.setAmount(amountString);

            expensesXml.FindElem("Date");
            expense.setDate(expensesXml.GetData());

            expensesXml.OutOfElem();
            lastExpenseId = expense.getExpenseId();

            if (expense.getUserId() == loggedInUserId) loadedExpenses.push_back(expense);
        }
    }

    return loadedExpenses;
}
