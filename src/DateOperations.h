#ifndef DATEOPERATIONS_H
#define DATEOPERATIONS_H

// #include <iostream>
// #include <time.h>
// #include <string>
#include "date.h"

#include "UnasignedMethods.h"

// using namespace std;

class DateOperations {

    std::string correctDateString;
    int dateToSort;
    static std::string takeNewDateToCheck();
    int dayPerMonth(int year, int numberOfMonth);
    int isLeapYear(int year);
    using SysDaysTimePoint = std::chrono::sys_days;
    static SysDaysTimePoint getTimePointFromYmdString(const std::string& ymd);

public:

    static std::string getSystemDate();
    static bool isDateSmallerThanEndingDate(const std::string& date, const std::string& endingDate);
    static bool isDateBiggerOrEqualThanStartingDate(const std::string& date, const std::string& startingDate);
    bool getDateIncorrectFormatToString(std::string& output);
    bool checkDateFormat(const std::string& checkedDate);
    int getDateToSort();
    std::string getCorrectDateString ();

};
#endif // DATEOPERATIONS_H

