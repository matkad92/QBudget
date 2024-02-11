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
    static int dayPerMonth (int year, int numberOfMonth);


public:

    static std::string getSystemDate();
    static std::string inputCorrectDateFormat(); //returns correct date
    static bool isDateSmallerThanEndingDate(std::string date, std::string endingDate);
    static bool isDateBiggerThanStartingDate(std::string date, std::string startingDate);
    bool checkDateFormat(std::string checkedDate);
    int getDateToSort();
    std::string getCorrectDateString ();

};
#endif // DATEOPERATIONS_H

