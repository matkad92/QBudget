#ifndef EXPENSE_H
#define EXPENSE_H

#include "Money.h"

class Expense : public Money {

    int expenseId;
public:
    void setExpenseId(int newExpenseId);
    int getExpenseId();

};
#endif // EXPENSE_H
