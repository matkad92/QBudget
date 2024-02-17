#include "Money.h"

void Money::setUserId(int newId) {
    if (newId >= 0) userId = newId;
}

void Money::setDate(std::string newDate) {
    DateOperations dateOperation;
    if (dateOperation.checkDateFormat(newDate) == true) {
        date = newDate;
        dateToSort = dateOperation.getDateToSort(newDate);
    } else {
        objectCorrectState = false;
        std::cout << "Wrond date format." <<std::endl;
    }
}


void Money::setItem(std::string newItem) {
    item = newItem;
}

std::string Money::takeNewAmountToCheck() {
    std::string newAmount;
    std::cout << "Amount format is wrong, try again using format _ _ _ _ _ _ _ _ ._ _ " << std::endl;
    std::cout << "Amount: ";
    std::cin.sync();
    newAmount = UnasignedMethods::takeLine();
    return newAmount;
}

void Money::setAmount(std::string newAmount) {

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

std::string Money::getDate() {
    return date;
}

int Money::getDateToSort() {
    return dateToSort;
}

std::string Money::getItem() {
    return item;
}

double Money::getAmount() {
    return amount;
}

std::string Money::getAmountString() {
    return amountString;
}


