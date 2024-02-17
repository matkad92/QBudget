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

    while (true) {
        if (newAmount.size() >= 4 && newAmount[newAmount.size() - 3] == ',') {
            newAmount[newAmount.size() - 3] = '.';
        }

        if (chceckCorrectMoneyInput(newAmount)) {
            if (newAmount[0] == '.') {
                newAmount.insert(0, "0");
            }
            amountString = newAmount;
            amount = std::stod(amountString);
            return;
        }
        newAmount = takeNewAmountToCheck();
    }

}

bool Money::chceckCorrectMoneyInput(const std::string &input)
{
    bool valid{false};
    if(input.length() < 3){
        return valid;
    }
    size_t dotPosition = input.find('.');
    int dotCount = 0;
    if (dotPosition != std::string::npos && dotPosition == input.size() - 3) {
        valid = std::all_of(input.begin(), input.end(), [&dotCount](char c) ->bool {
            if (c == '.') {
                dotCount++;
                return dotCount <= 1;
            }
            return std::isdigit(c);
        });
    }
    return valid;
}

int Money::getUserId() const {
    return userId;
}

std::string Money::getDate() const {
    return date;
}

int Money::getDateToSort() const {
    return dateToSort;
}



std::string Money::getItem () const{
    return item;
}

double Money::getAmount() const {
    return amount;
}

std::string Money::getAmountString() const {
    return amountString;
}


