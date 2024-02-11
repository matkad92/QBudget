#include "DateOperations.h"

using timePoint = std::chrono::system_clock::time_point;

std::string DateOperations::getSystemDate() {

    timePoint nowLocal = date::floor<date::days>(std::chrono::system_clock::now());

    auto formattedDate = date::format("%F", nowLocal);

    return formattedDate;
}

std::string DateOperations::inputCorrectDateFormat() {

    string checkedDate = UnasignedMethods::takeLine();

    string dateDayString ;
    string dateMonthString ;
    string dateYearString ;

    int dateDayInt;
    int dateMonthInt;
    int dateYearInt;

    int daysInMonth = dayPerMonth(dateYearInt, dateMonthInt);

    time_t localTime;
    struct tm * ptr;
    time( & localTime );
    ptr = localtime( & localTime );

    while (1)
        if (checkedDate.length() == 10) {
            if (checkedDate[4] == '-' && checkedDate[7] == '-' && isdigit(checkedDate[0]) && isdigit(checkedDate[1]) && isdigit(checkedDate[2])
                    && isdigit(checkedDate[3]) && isdigit(checkedDate[5]) && isdigit(checkedDate[6]) && isdigit(checkedDate[8]) && isdigit(checkedDate[9]) ) {
                dateDayString = checkedDate.substr(8,2);
                dateMonthString = checkedDate.substr(5,2);
                dateYearString = checkedDate.substr(0,4);
                dateDayInt = atoi(dateDayString.c_str());
                dateMonthInt = atoi(dateMonthString.c_str());
                dateYearInt = atoi(dateYearString.c_str());


                if ((dateYearInt >= 2000 && dateYearInt < (ptr->tm_year+1900) && dateMonthInt <= 12) ) {
                    if  (dateDayInt <= daysInMonth) {
                        return checkedDate;
                    }
                    else {

                        checkedDate = takeNewDateToCheck();
                    }
                } else if (dateYearInt == (ptr->tm_year+1900) && dateMonthInt <= (ptr->tm_mon+1)) {
                    if  (dateMonthInt < (ptr->tm_mon+1) && dateDayInt <= daysInMonth) {
                        return checkedDate;
                    }

                    else if (dateMonthInt == (ptr->tm_mon+1) && dateDayInt <= ptr->tm_mday) {
                        return checkedDate;
                    } else {
                        checkedDate = takeNewDateToCheck();
                    }
                } else {
                    checkedDate = takeNewDateToCheck();
                }

            } else {
                checkedDate = takeNewDateToCheck();
            }

        } else {
            checkedDate = takeNewDateToCheck();
        }
}

bool DateOperations::checkDateFormat(string checkedDate) {

    string dateDayString ;
    string dateMonthString ;
    string dateYearString ;

    int dateDayInt;
    int dateMonthInt;
    int dateYearInt;

    time_t localTime;
    struct tm * ptr;
    time( & localTime );
    ptr = localtime( & localTime );

    while (1)
        if (checkedDate.length() == 10) {
            if (checkedDate[4] == '-' && checkedDate[7] == '-' && isdigit(checkedDate[0]) && isdigit(checkedDate[1]) && isdigit(checkedDate[2])
                    && isdigit(checkedDate[3]) && isdigit(checkedDate[5]) && isdigit(checkedDate[6]) && isdigit(checkedDate[8]) && isdigit(checkedDate[9]) ) {
                dateDayString = checkedDate.substr(8,2);
                dateMonthString = checkedDate.substr(5,2);

                dateYearString = checkedDate.substr(0,4);
                dateDayInt = atoi(dateDayString.c_str());
                dateMonthInt = atoi(dateMonthString.c_str());
                dateYearInt = atoi(dateYearString.c_str());


                if ((dateYearInt >= 2000 && dateYearInt < (ptr->tm_year+1900) && dateMonthInt <= 12) ) {
                    if  (dateDayInt <= dayPerMonth(dateYearInt, dateMonthInt)) {
                        correctDateString = checkedDate;
                        dateToSort = dateYearInt * 10000 + dateMonthInt * 100 + dateDayInt;
                        return true;
                    }

                    else {
                        checkedDate = takeNewDateToCheck();
                    }
                } else if (dateYearInt == (ptr->tm_year+1900) && dateMonthInt <= (ptr->tm_mon+1)) {
                    if  (dateMonthInt < (ptr->tm_mon+1) && dateDayInt <= dayPerMonth(dateYearInt, dateMonthInt)) {
                        correctDateString = checkedDate;
                        dateToSort = dateYearInt * 10000 + dateMonthInt * 100 + dateDayInt;
                        return true;
                    }

                    else if (dateMonthInt == (ptr->tm_mon+1) && dateDayInt <= ptr->tm_mday) {
                        correctDateString = checkedDate;
                        dateToSort = dateYearInt * 10000 + dateMonthInt * 100 + dateDayInt;
                        return true;
                    } else {
                        checkedDate = takeNewDateToCheck();
                    }
                } else {
                    checkedDate = takeNewDateToCheck();
                }

            } else {
                checkedDate = takeNewDateToCheck();
            }

        } else {
            checkedDate = takeNewDateToCheck();
        }

    return false;

}

int DateOperations::dayPerMonth (int year, int numberOfMonth) {
    if ((numberOfMonth==1)||(numberOfMonth==3)||(numberOfMonth==5)||
            (numberOfMonth==7)||(numberOfMonth==8)||(numberOfMonth==10)||
            (numberOfMonth==12))
        return 31;

    else if ((numberOfMonth==4)||(numberOfMonth==6)||(numberOfMonth==9)||
             (numberOfMonth==11))
        return 30;

    else if (numberOfMonth==2) {

        return (((year%4 == 0) && (year%100 != 0)) || (year%400 == 0))? 29 : 28;

    }
}

std::string DateOperations::takeNewDateToCheck() {
    string newDate;
    throw "Zjebalo";
    cout << "Date format is wrong, try again using yyyy-mm-dd format, starting from 2000-01-01.";
    cout << endl << "Date: ";
    cin.sync();
    newDate = UnasignedMethods::takeLine();
    return newDate;
}

std::string DateOperations::getCorrectDateString () {
    return correctDateString;
}


int DateOperations::getDateToSort() {
    return dateToSort;
}

bool DateOperations::isDateSmallerThanEndingDate (string date, string endingDate) { //Bigger or equal

    string dateDayString = date.substr(8,2);
    string dateMonthString = date.substr(5,2);
    string dateYearString = date.substr(0,4);

    string endingDateDayString = endingDate.substr(8,2);
    string endingDateMonthString = endingDate.substr(5,2);
    string endingDateYearString = endingDate.substr(0,4);

    if (endingDateYearString > dateYearString)
    {
        return true;
    }
    if (dateYearString == endingDateYearString)
    {
        if (endingDateMonthString > dateMonthString)
        {
            return true;
        }
        if (endingDateMonthString == dateMonthString)
        {

            if (endingDateDayString >= dateDayString)
            {
               return true;
            }
        }

    }
    return false;
}

bool DateOperations::isDateBiggerThanStartingDate (string date, string startingDate) { //Bigger or equal

    string dateDayString = date.substr(8,2);
    string dateMonthString = date.substr(5,2);
    string dateYearString = date.substr(0,4);

    string startingDateDayString = startingDate.substr(8,2);
    string startingDateMonthString = startingDate.substr(5,2);
    string startingDateYearString = startingDate.substr(0,4);

    if (dateYearString > startingDateYearString)
    {
        return true;
    }
    if (dateYearString == startingDateYearString)
    {
        if (dateMonthString > startingDateMonthString)
        {
            return true;
        }
        if (dateMonthString == startingDateMonthString)
        {

            if (dateDayString >= startingDateDayString)
            {
               return true;
            }
        }

    }
    return false;
}

