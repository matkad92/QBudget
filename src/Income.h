#ifndef INCOME_H
#define INCOME_H

#include "Money.h"

using namespace std;

class Income : public Money {

    int incomeId;

public:
    void setIncomeId(int newIncomeId);
    int getIncomeId();

};
#endif // INCOME_H
