#ifndef INCOME_H
#define INCOME_H

#include "Money.h"

class Income : public Money {

    int incomeId;

public:
    void setIncomeId(int newIncomeId);
    int getIncomeId() const;

};
#endif // INCOME_H
