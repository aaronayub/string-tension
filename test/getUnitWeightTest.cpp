/* Testing for functions for getUnitWeight on strlib */

#include <gtest/gtest.h>
#include "../src/strlib/strlib.h"

TEST(strlibTest, getUnitWeightTest) {
    // Test negative or 0 value inputs
    EXPECT_DOUBLE_EQ(strlib::getUnitWeight(0,strlib::PL),0);
    EXPECT_DOUBLE_EQ(strlib::getUnitWeight(-100,strlib::PL),0);
    // Test finding values which are present in the string lists
    EXPECT_DOUBLE_EQ(strlib::getUnitWeight(7,strlib::PL),0.00001085);
    EXPECT_DOUBLE_EQ(strlib::getUnitWeight(8,strlib::PL),0.00001418);
    EXPECT_DOUBLE_EQ(strlib::getUnitWeight(24,strlib::PL),0.00012760);
    EXPECT_DOUBLE_EQ(strlib::getUnitWeight(26,strlib::PL),0.00014975);

    // Test extrapolation
    EXPECT_GT(strlib::getUnitWeight(7,strlib::PL),strlib::getUnitWeight(6,strlib::PL));
    EXPECT_GT(strlib::getUnitWeight(6,strlib::PL),strlib::getUnitWeight(5,strlib::PL));
    EXPECT_LT(strlib::getUnitWeight(26,strlib::PL),strlib::getUnitWeight(28,strlib::PL));
    EXPECT_LT(strlib::getUnitWeight(28,strlib::PL),strlib::getUnitWeight(30,strlib::PL));

    EXPECT_GT(strlib::getUnitWeight(17,strlib::NW),strlib::getUnitWeight(16,strlib::NW));
    EXPECT_GT(strlib::getUnitWeight(16,strlib::NW),strlib::getUnitWeight(14,strlib::NW));
    EXPECT_LT(strlib::getUnitWeight(80,strlib::NW),strlib::getUnitWeight(82,strlib::NW));
    EXPECT_LT(strlib::getUnitWeight(81,strlib::NW),strlib::getUnitWeight(85,strlib::NW));

    EXPECT_GT(strlib::getUnitWeight(28,strlib::XLB),strlib::getUnitWeight(26,strlib::XLB));
    EXPECT_GT(strlib::getUnitWeight(27,strlib::XLB),strlib::getUnitWeight(25,strlib::XLB));
    EXPECT_LT(strlib::getUnitWeight(145,strlib::XLB),strlib::getUnitWeight(150,strlib::XLB));
    EXPECT_LT(strlib::getUnitWeight(147,strlib::XLB),strlib::getUnitWeight(160,strlib::XLB));

    // Test interpolation
    double interpolatedWeight = strlib::getUnitWeight(21,strlib::PL);
    EXPECT_GT(interpolatedWeight,strlib::getUnitWeight(20,strlib::PL));
    EXPECT_LT(interpolatedWeight,strlib::getUnitWeight(22,strlib::PL));

    interpolatedWeight = strlib::getUnitWeight(23,strlib::PL);
    EXPECT_GT(interpolatedWeight,strlib::getUnitWeight(22,strlib::PL));
    EXPECT_LT(interpolatedWeight,strlib::getUnitWeight(24,strlib::PL));

    interpolatedWeight = strlib::getUnitWeight(23,strlib::NW);
    EXPECT_GT(interpolatedWeight,strlib::getUnitWeight(22,strlib::NW));
    EXPECT_LT(interpolatedWeight,strlib::getUnitWeight(24,strlib::NW));

    interpolatedWeight = strlib::getUnitWeight(77,strlib::NW);
    EXPECT_GT(interpolatedWeight,strlib::getUnitWeight(74,strlib::NW));
    EXPECT_LT(interpolatedWeight,strlib::getUnitWeight(80,strlib::NW));

    interpolatedWeight = strlib::getUnitWeight(37,strlib::XLB);
    EXPECT_GT(interpolatedWeight,strlib::getUnitWeight(35,strlib::XLB));
    EXPECT_LT(interpolatedWeight,strlib::getUnitWeight(40,strlib::XLB));

    interpolatedWeight = strlib::getUnitWeight(132,strlib::XLB);
    EXPECT_GT(interpolatedWeight,strlib::getUnitWeight(130,strlib::XLB));
    EXPECT_LT(interpolatedWeight,strlib::getUnitWeight(145,strlib::XLB));
}