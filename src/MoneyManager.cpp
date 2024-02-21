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

    auto today = date::year_month_day(date::floor<date::days>(std::chrono::system_clock::now()));
    int month = static_cast<int>(static_cast<unsigned>(today.month()));
    int year = static_cast<int>(today.year());

    std::vector<Income> currentMonthIncomes = filterByMonth(incomesManager.incomes, month, year);
    std::vector<Expense> currentMonthExpenses = filterByMonth(expensesManager.expenses, month, year);

    std::sort(currentMonthIncomes.begin(), currentMonthIncomes.end());
    std::sort(currentMonthExpenses.begin(), currentMonthExpenses.end());

    printChosenIncomesAndExpenses(currentMonthIncomes, currentMonthExpenses);
    printBalances (currentMonthIncomes, currentMonthExpenses);
}

template<typename TransactionType>
std::vector<TransactionType> MoneyManager::filterByMonth(const std::vector<TransactionType> &transactions, int month, int year) {

    std::vector<TransactionType> result;
    for (const auto& transaction : transactions) {
        if (takeMonthFromDate(transaction.getDate()) == month &&
            takeYearFromDate(transaction.getDate()) == year) {
            result.push_back(transaction);
        }
    }
    return result;
}


void MoneyManager::balanceForTheLastMonth() {

    auto today = date::year_month_day(date::floor<date::days>(std::chrono::system_clock::now()));
    int currentMonth = static_cast<int>(static_cast<unsigned>(today.month()));
    int currentYear = static_cast<int>(today.year());

    int previousMonth, previousYear;
    if (currentMonth > 1) {
        previousMonth = currentMonth - 1;
        previousYear = currentYear;
    } else {
        previousMonth = 12;
        previousYear = currentYear - 1;
    }

    std::vector<Income> lastMonthIncomes = filterByMonth(incomesManager.incomes, previousMonth, previousYear);
    std::vector<Expense> lastMonthExpenses = filterByMonth(expensesManager.expenses, previousMonth, previousYear);


    sort(lastMonthIncomes.begin(), lastMonthIncomes.end());
    sort(lastMonthExpenses.begin(), lastMonthExpenses.end());

    printChosenIncomesAndExpenses(lastMonthIncomes, lastMonthExpenses);
    printBalances (lastMonthIncomes, lastMonthExpenses);
}

void MoneyManager::balanceFromChoosenPeriod() {

    std::string startingDate, endingDate;

    std::cout << "Choose starting date ( rrrr-mm-dd ):";
    if(!dateOperations.getDateIncorrectFormatToString(startingDate)){
        return;
    }

    std::cout << std::endl << "Choose ending date ( rrrr-mm-dd ):";
    if(!dateOperations.getDateIncorrectFormatToString(endingDate)){
        return;
    }

    if (!(DateOperations::isDateSmallerThanEndingDate(startingDate,endingDate))) {
        std::cout << "Wrong dates! Starting date can not be more recent than ending date.";
        getch();
        return;
    }

    auto ChoosenPeriodExpenses = filterByDateRange(expensesManager.expenses, startingDate, endingDate);
    auto ChoosenPeriodIncomes = filterByDateRange(incomesManager.incomes, startingDate, endingDate);

    sort(ChoosenPeriodIncomes.begin(), ChoosenPeriodIncomes.end());
    sort(ChoosenPeriodExpenses.begin(), ChoosenPeriodExpenses.end());

    printChosenIncomesAndExpenses(ChoosenPeriodIncomes, ChoosenPeriodExpenses);
    printBalances (ChoosenPeriodIncomes, ChoosenPeriodExpenses);

}

template<typename TransactionType>
std::vector<TransactionType> MoneyManager::filterByDateRange(const std::vector<TransactionType> &transactions, const std::string &startDate, const std::string &endDate)
{
    std::vector<TransactionType> result;
    for (const auto& transaction : transactions) {
        std::string date = transaction.getDate();
        if (DateOperations::isDateSmallerThanEndingDate(date, endDate) && DateOperations::isDateBiggerOrEqualThanStartingDate(date, startDate)) {
            result.push_back(transaction);
        }
    }
    return result;
}


int MoneyManager::takeMonthFromDate(const std::string& dateFromVector) {
    return std::stoi(dateFromVector.substr(5, 2));
}

int MoneyManager::takeYearFromDate(const std::string& dateFromVector) {
    return std::stoi(dateFromVector.substr(0, 4));
}

void MoneyManager::printChosenIncomesAndExpenses(const std::vector<Income> &incomes, const std::vector<Expense> &expenses) {

    system("cls");

    if(!incomes.empty()) {
        std::cout << "            >>>INCOMES<<<" << std::endl;
        std::cout << "-----------------------------------------------" << std::endl;
        for (const auto& income : incomes) {
            incomesManager.printIncome(income);
        }
        std::cout << std::endl << std::endl << std::endl;
    } else {
        std::cout << std::endl << "There are no incomes."<< std::endl << std::endl;
    }

    if(!expenses.empty()) {
        std::cout << "            >>>EXPENSES<<<" << std::endl;
        std::cout << "-----------------------------------------------" << std::endl;
        for (const auto& expense : expenses) {
            expensesManager.printExpense(expense);
        }
        std::cout << std::endl;
    } else {
        std::cout << std::endl << "There are no expenses."<< std::endl << std::endl;
    }

}

void MoneyManager::printBalances (const std::vector<Income> &incomes, const std::vector<Expense> &expenses) {

    double incomesSum = 0,  expensesSum = 0;

    for (const auto& income : incomes) {
        incomesSum += income.getAmount();
    }
    for (const auto& expense : expenses) {
        expensesSum += expense.getAmount();
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





