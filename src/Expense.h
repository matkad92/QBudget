#ifndef EXPENSE_H
#define EXPENSE_H

#include "Money.h"

class Expense : public Money {

    int expenseId;
public:
    Expense();
    void setExpenseId(int newExpenseId);
    int getExpenseId() const;

};
#endif // EXPENSE_H
