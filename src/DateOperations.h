#ifndef DATEOPERATIONS_H
#define DATEOPERATIONS_H

#include <iostream>
#include <time.h>
#include <string>

#include "UnasignedMethods.h"

using namespace std;

class DateOperations {

    string correctDateString;
    int dateToSort;
    static string takeNewDateToCheck();
    static int dayPerMonth (int year, int numberOfMonth);


public:

    static string getSystemDate();
    static string inputCorrectDateFormat(); //returns correct date
    static bool isDateSmallerThanEndingDate(string date, string endingDate);
    static bool isDateBiggerThanStartingDate(string date, string startingDate);
    bool checkDateFormat(string checkedDate);
    int getDateToSort();
    string getCorrectDateString ();

};
#endif // DATEOPERATIONS_H

