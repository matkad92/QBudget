#include "DateOperations.h"

using timePoint = std::chrono::system_clock::time_point;

std::string DateOperations::getSystemDate() {

    timePoint nowLocal = date::floor<date::days>(std::chrono::system_clock::now());

    auto formattedDate = date::format("%F", nowLocal);

    return formattedDate;
}


bool DateOperations::getDateIncorrectFormatToString(std::string &output){

    std::string checkedDate = UnasignedMethods::takeLine();
    for(int i = 0; i < 3; i++){
        if(checkDateFormat(checkedDate)){
            output = checkedDate;
            return true;
        }
        else {
            checkedDate = takeNewDateToCheck();
        }
    }
    output = "";
    return false;
}

bool DateOperations::checkDateFormat(const std::string& checkedDate){

    std::istringstream iss(checkedDate);
    date::year_month_day ymd;
    iss >> date::parse("%F", ymd);

    if(ymd.year() < date::year{2000})
        return false;

    bool returnVal = !iss.fail();

    return returnVal;

}

int DateOperations::dayPerMonth (int year, int numberOfMonth) {

    if (numberOfMonth < 1 || numberOfMonth > 12) {
        return -1;
    }

    const int daysInMonth[] = {31, 28 + isLeapYear(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return daysInMonth[numberOfMonth - 1];
}

int DateOperations::isLeapYear(int year){

    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? 1 : 0;
}

std::string DateOperations::takeNewDateToCheck() {

    std::string newDate;
    std::cout << "Date format is wrong, try again using yyyy-mm-dd format, starting from 2000-01-01." << std::endl;
    std::cout << "Date: ";
    std::cin.sync();
    newDate = UnasignedMethods::takeLine();
    return newDate;
}


int DateOperations::getDateToSort(const std::string& toConvert) {

    int year, month, day;

    std::istringstream iss(toConvert);

    char dash;
    iss >> year >> dash >> month >> dash >> day;

    int dateToSort = year * 10000 + month * 100 + day;

    return dateToSort;
}


DateOperations::SysDaysTimePoint DateOperations::getTimePointFromYmdString(const std::string &ymd) {

    std::istringstream iss(ymd);
    date::year_month_day ymdDate;
    iss >> date::parse("%F", ymdDate);

    return date::sys_days{ymdDate};
}

bool DateOperations::isDateSmallerThanEndingDate (const std::string& date, const std::string& endingDate) {

    auto sysDaysDate = getTimePointFromYmdString(date);
    auto sysDaysEndingDate = getTimePointFromYmdString(endingDate);

    return sysDaysDate < sysDaysEndingDate;
}


bool DateOperations::isDateBiggerOrEqualThanStartingDate (const std::string& date, const std::string& startingDate) {

    auto sysDaysDate = getTimePointFromYmdString(date);
    auto sysDaysStartingDate = getTimePointFromYmdString(startingDate);

    return sysDaysDate >= sysDaysStartingDate;
}


