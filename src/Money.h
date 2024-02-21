#ifndef MONEY_H
#define MONEY_H


#include <iostream>
#include "DateOperations.h"
#include "UnasignedMethods.h"



class Money {
public:
    enum class OperationType{
        Undefined,
        Income,
        Expense,
    };

private:

    int userId;
    std::string date;
    int dateToSort;
    std::string item;
    double amount;
    std::string amountString;
    std::string takeNewAmountToCheck();

protected:
    OperationType  type;

public:
    Money();

    virtual ~Money();
    bool objectCorrectState{true};
    bool operator < (Money& money)
    {
        return (getDateToSort() < money.getDateToSort());
    }

    OperationType getOperationType() const;
    void setUserId( int newId);
    void setDate( std::string newDate);

    void setItem( std::string newItem);
    void setAmount(std::string newAmount);
    int getUserId() const;
    std::string getDate() const;
    int getDateToSort() const;
    bool chceckCorrectMoneyInput(const std::string& input);
    std::string getItem() const;
    double getAmount() const;
    std::string getAmountString() const;


};

#endif // MONEY_H
