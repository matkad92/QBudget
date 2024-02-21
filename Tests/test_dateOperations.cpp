#include <gtest/gtest.h>

#include "../DateOperations.h"

TEST(DateOperationsTest, getSystemDate_CorrectStringLenghtReturned) {
    std::string systemDate = DateOperations::getSystemDate();
    ASSERT_EQ(systemDate.length(), 10);
}


TEST(DateOperationsTest, DateFormatValidationTest) {

    DateOperations dateOP;

    bool result = dateOP.checkDateFormat("2023-12-31");
    EXPECT_TRUE(result);

    EXPECT_FALSE(dateOP.checkDateFormat("2023-13-31"));

    EXPECT_FALSE(dateOP.checkDateFormat("2023-11-21-10"));
}

TEST(DateOperationsTest, IsLeapYear_ValidLeapYear_ReturnsTrue) {
    DateOperations dateOP;

    bool isLeapYear = dateOP.isLeapYear(2020);
    EXPECT_TRUE(isLeapYear);
}

TEST(DateOperationsTest, IsLeapYear_ValidNonLeapYear_ReturnsFalse) {
    DateOperations dateOP;

    bool isLeapYear = dateOP.isLeapYear(2023);
    EXPECT_FALSE(isLeapYear);
}

TEST(DateOperationsTest, getDateToSort_ValidDate_ReturnsExpectedResult) {
    DateOperations dateOP;
    std::string validDate = "2023-12-31";

    int dateToSort = dateOP.getDateToSort(validDate);

    EXPECT_EQ(dateToSort, 20231231);
}

TEST(DateOperationsTest, getDateToSort_InvalidDate_ReturnsZero) {
    DateOperations dateOP;
    std::string invalidDate = "2023-13-31";

    int dateToSort = dateOP.getDateToSort(invalidDate);

    EXPECT_EQ(dateToSort, 0);
}

TEST(DateOperationsTest, isDateSmallerThanEndingDate_SameDate_ReturnsFalse) {
    DateOperations dateOP;
    std::string date = "2023-12-31";
    std::string endingDate = "2023-12-31";

    bool result = dateOP.isDateSmallerThanEndingDate(date, endingDate);

    EXPECT_FALSE(result);
}

TEST(DateOperationsTest, isDateBiggerOrEqualThanStartingDate_SameDate_ReturnsTrue) {
    DateOperations dateOP;
    std::string date = "2023-12-31";
    std::string startingDate = "2023-12-31";

    bool result = dateOP.isDateBiggerOrEqualThanStartingDate(date, startingDate);

    EXPECT_TRUE(result);
}

TEST(DateOperationsTest, isDateSmallerThanEndingDate_DifferentYears_ReturnsTrue) {
    DateOperations dateOP;
    std::string date = "2022-12-31";
    std::string endingDate = "2023-01-01";

    bool result = dateOP.isDateSmallerThanEndingDate(date, endingDate);

    EXPECT_TRUE(result);
}

TEST(DateOperationsTest, isDateBiggerOrEqualThanStartingDate_DifferentYears_ReturnsFalse) {
    DateOperations dateOP;
    std::string date = "2022-12-31";
    std::string startingDate = "2023-01-01";

    bool result = dateOP.isDateBiggerOrEqualThanStartingDate(date, startingDate);

    EXPECT_FALSE(result);
}
