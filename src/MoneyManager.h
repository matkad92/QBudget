#ifndef MONEYMANAGER_H
#define MONEYMANAGER_H

#include <iostream>
#include <algorithm>
#include <iomanip>

#include "ExpensesManager.h"
#include "IncomesManager.h"

class MoneyManager {

    const int LOGGED_IN_USER_ID;

    ExpensesManager expensesManager;
    IncomesManager incomesManager;
    DateOperations dateOperations;
    int takeMonthFromDate(const std::string& dateFromVector);
    int takeYearFromDate(const std::string& dateFromVector);
    void printChosenIncomesAndExpenses(const std::vector<Income>& incomes, const std::vector<Expense>& expenses);
    void printBalances (const std::vector<Income>& incomes, const std::vector<Expense>& expenses);
    template<typename TransactionType>
    std::vector<TransactionType> filterByMonth(const std::vector<TransactionType>& transactions, int month, int year);
    template<typename TransactionType>
    std::vector<TransactionType> filterByDateRange(const std::vector<TransactionType>& transactions, const std::string& startDate, const std::string& endDate);
    // template<typename TransactionType>
    // void printTransactions(const std::vector<TransactionType>& transactions, const std::string& transactionTypeLabel);

public:
    MoneyManager (std::string expensesFileName, std::string incomesFileName, int loggedInUserId) :
        LOGGED_IN_USER_ID (loggedInUserId), expensesManager(expensesFileName, loggedInUserId), incomesManager(incomesFileName, loggedInUserId) {
    };

    void addIncome();
    void printAllIncomes();
    void addExpense();
    void printAllExpenses();
    void balanceForTheCurrentMonth();
    void balanceForTheLastMonth();
    void balanceFromChoosenPeriod();

};


#endif // MONEYMANAGER_H
