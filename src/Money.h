#ifndef MONEY_H
#define MONEY_H


#include <iostream>
#include "DateOperations.h"
#include "UnasignedMethods.h"

class Money {

    int userId;
    std::string date;
    int dateToSort;
    std::string item;
    double amount;
    std::string amountString;
    std::string takeNewAmountToCheck();


public:
    bool objectCorrectState{true};
    bool operator < (Money& money)
    {
        return (getDateToSort() < money.getDateToSort());
    }


    void setUserId( int newId);
    void setDate( std::string newDate);

    void setItem( std::string newItem);
    void setAmount(std::string newAmount);
    int getUserId();
    std::string getDate();
    int getDateToSort();
    std::string getItem();
    double getAmount();
    std::string getAmountString();


};

#endif // MONEY_H
