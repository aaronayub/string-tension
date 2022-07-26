/* Testing the String object. */

#include <gtest/gtest.h>
#include "../src/strlib/string.h"
#include "../src/strlib/stringweight.h"
#include "../src/strlib/notes.h"

/* Test an object's values after it is created */
TEST(stringObjectTest, constructString) {
    strlib::String str = strlib::String(25.5,46,strlib::NW,strlib::notes::E,2);
    
    EXPECT_NEAR(str.getLength(),25.5,0.0001);
    EXPECT_NEAR(str.getGauge(),46,0.0001);
    EXPECT_EQ(str.getType(),strlib::NW);
    EXPECT_EQ(str.getNote(),strlib::notes::E);
    EXPECT_EQ(str.getOctave(),2);
    EXPECT_NEAR(str.getFrequency(),82.4069,0.0001);
    EXPECT_NEAR(str.getTension(),17.4693,0.0001);
}

/* Test updating an object's values */
TEST(stringObjectTest, updateString) {
    // Create a string, then change all of it's values.
    strlib::String str = strlib::String(25.5,46,strlib::NW,strlib::notes::E,2);
    str.setGauge(9);
    str.setType(strlib::PL);
    str.setLength(24.75);
    str.setNote(strlib::notes::F);
    str.setOctave(4);

    // Check that the values are changed properly.
    EXPECT_NEAR(str.getLength(),24.75,0.0001);
    EXPECT_NEAR(str.getGauge(),9,0.0001);
    EXPECT_EQ(str.getType(),strlib::PL);
    EXPECT_EQ(str.getNote(),strlib::notes::F);
    EXPECT_EQ(str.getOctave(),4);
    EXPECT_NEAR(str.getFrequency(),349.2282,0.0001);
    EXPECT_NEAR(str.getTension(),13.8744,0.0001);
}