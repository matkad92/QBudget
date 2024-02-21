#ifndef DATEOPERATIONS_H
#define DATEOPERATIONS_H

#include "date.h"

#include "UnasignedMethods.h"

class DateOperations {

    static std::string takeNewDateToCheck();
    int dayPerMonth(int year, int numberOfMonth);
    using SysDaysTimePoint = std::chrono::sys_days;
    static SysDaysTimePoint getTimePointFromYmdString(const std::string& ymd);

public:

    static std::string getSystemDate();
    static bool isDateSmallerThanEndingDate(const std::string& date, const std::string& endingDate);
    static bool isDateBiggerOrEqualThanStartingDate(const std::string& date, const std::string& startingDate);
    bool getDateIncorrectFormatToString(std::string& output);
    bool checkDateFormat(const std::string& checkedDate);
    int getDateToSort(const std::string& toConvert);
    int isLeapYear(int year);

};
#endif // DATEOPERATIONS_H

