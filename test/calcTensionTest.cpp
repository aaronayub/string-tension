/* Test to calculate the tension of a string */

#include <gtest/gtest.h>
#include "../src/strlib/strlib.h"

/* Regression test to check if anything changes with final tension calculations. */
TEST(strlibTest,calcTensionTest) {
    EXPECT_NEAR(strlib::calcTension(strlib::getUnitWeight(46,strlib::NW),25.5,strlib::noteToFrequency(40)),17.4693,0.001);
    EXPECT_NEAR(strlib::calcTension(strlib::getUnitWeight(105,strlib::XLB),34,strlib::noteToFrequency(28)),40.3068,0.001);
    EXPECT_NEAR(strlib::calcTension(strlib::getUnitWeight(10,strlib::PL),24.75,strlib::noteToFrequency(64)),15.2613,0.001);
}