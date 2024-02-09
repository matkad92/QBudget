#include "Money.h"

void Money::setUserId(int newId) {
    if (newId >= 0) userId = newId;
}

void Money::setDate(string newDate) {
    DateOperations dateOperation;
    if (dateOperation.checkDateFormat(newDate) == true) {
        date = dateOperation.getCorrectDateString();
        dateToSort = dateOperation.getDateToSort();
    } else cout << "Date can not be set.";
}


void Money::setItem(string newItem) {
    item = newItem;
}

string Money::takeNewAmountToCheck() {
    string newAmount;
    cout << "Amount format is wrong, try again using format _ _ _ _ _ _ _ _ ._ _ " << endl;
    cout << "Amount: ";
    cin.sync();
    newAmount = UnasignedMethods::takeLine();
    return newAmount;
}

void Money::setAmount(string newAmount) {

    int wrongChars ;
    while (1) {
        wrongChars = 0;
        if (newAmount[newAmount.length()-3] == ',') {
            newAmount[newAmount.length()-3] = '.';
        }
        if ((newAmount[newAmount.length()-3] == '.') && (newAmount.length() >= 4)) {
            for ( int i = 0; i < (newAmount.length()-3) ; i++ ) {
                if ( isdigit(newAmount[i]) && isdigit(newAmount[newAmount.length()-1]) && isdigit(newAmount[newAmount.length()-2]) ) {
                    continue;
                } else wrongChars ++;
            }
            if (wrongChars == 0) {
                amountString = newAmount;
                amount = atof(amountString.c_str());
                return;
            } else newAmount = takeNewAmountToCheck();

        } else {
            newAmount = takeNewAmountToCheck();
        }
    }


}

int Money::getUserId() {
    return userId;
}

string Money::getDate() {
    return date;
}

int Money::getDateToSort() {
    return dateToSort;
}

string Money::getItem() {
    return item;
}

double Money::getAmount() {
    return amount;
}

string Money::getAmountString() {
    return amountString;
}


