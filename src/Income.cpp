
#include "Income.h"


Income::Income()
{
    Money();
    type = OperationType::Income;
}

void Income::setIncomeId(int newIncomeId) {
    if (newIncomeId > 0 ) incomeId = newIncomeId;
}

int Income::getIncomeId() const {
    return incomeId;
}
