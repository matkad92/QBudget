#include <gtest/gtest.h>

#include "../DateOperations.h"

TEST(DateOperationsTest, getSystemDate_CorrectStringLenghtReturned) {
    std::string systemDate = DateOperations::getSystemDate();
    ASSERT_EQ(systemDate.length(), 10);
}


TEST(DateOperationsTest, CheckDateFormat_IsValidDate) {

    DateOperations dateOP;

    bool result = dateOP.checkDateFormat("2023-12-31");
    EXPECT_TRUE(result);

    result = dateOP.checkDateFormat("2023-13-31");
    EXPECT_FALSE(result);
}
