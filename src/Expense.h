#ifndef EXPENSE_H
#define EXPENSE_H

#include "Money.h"

using namespace std;

class Expense : public Money {

    int expenseId;
public:
    void setExpenseId(int newExpenseId);
    int getExpenseId();

};
#endif // EXPENSE_H
