#include "Expense.h"

Expense::Expense()
{
    Money();
    type = OperationType::Expense;
}

void Expense::setExpenseId(int newExpenseId) {
    if (newExpenseId > 0 ) expenseId = newExpenseId;
}

int Expense::getExpenseId() const{
    return expenseId;
}
