#ifndef MONEY_H
#define MONEY_H


#include <iostream>
#include "DateOperations.h"
#include "UnasignedMethods.h"

using namespace std;

class Money {

    int userId;
    string date;
    int dateToSort;
    string item;
    double amount;
    string amountString;
    string takeNewAmountToCheck();



public:

    bool operator < (Money& money)
    {
        return (getDateToSort() < money.getDateToSort());
    }


    void setUserId( int newId);
    void setDate( string newDate);

    void setItem( string newItem);
    void setAmount(string newAmount);
    int getUserId();
    string getDate();
    int getDateToSort();
    string getItem();
    double getAmount();
    string getAmountString();


};

#endif // MONEY_H
