/** @file
 * @brief Tests functionality of the string object */

#include <gtest/gtest.h>
#include "../src/strlib/string.h"
#include "../src/strlib/stringweight.h"
#include "../src/strlib/notes.h"

/** Tests the constructor, and validate its values */
TEST(stringObjectTest, constructString) {
    strlib::String str = strlib::String(25.5,46,strlib::NW,strlib::notes::E,2);
    
    EXPECT_NEAR(str.getLength(),25.5,0.0001);
    EXPECT_EQ(str.getGauge(),46);
    EXPECT_EQ(str.getType(),strlib::NW);
    EXPECT_EQ(str.getNote(),strlib::notes::E);
    EXPECT_EQ(str.getOctave(),2);
    EXPECT_NEAR(str.getFrequency(),82.4069,0.0001);
    EXPECT_NEAR(str.getTension(),17.4693,0.0001);
}

/** Creates a string, updates the values and confirms that the values are properly changed */
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
    EXPECT_EQ(str.getGauge(),9);
    EXPECT_EQ(str.getType(),strlib::PL);
    EXPECT_EQ(str.getNote(),strlib::notes::F);
    EXPECT_EQ(str.getOctave(),4);
    EXPECT_NEAR(str.getFrequency(),349.2282,0.0001);
    EXPECT_NEAR(str.getTension(),13.8744,0.0001);
}

/** Tests adding a string higher than the highest string in the set */
TEST(stringObjectTest, higherString) {
    strlib::String oldStr = strlib::String(25.5,46,strlib::NW,strlib::notes::E,2);
    strlib::String str = strlib::String(oldStr,true);

    EXPECT_NEAR(str.getLength(),25.5,0.0001);
    EXPECT_EQ(str.getGauge(),35);
    EXPECT_EQ(str.getType(),strlib::NW);
    EXPECT_EQ(str.getNote(),strlib::notes::A);
    EXPECT_EQ(str.getOctave(),2);
    EXPECT_NEAR(str.getFrequency(),110,0.0001);
    EXPECT_NEAR(str.getTension(),18.5517,0.0001);
}

/** Tests adding a lower than the lowest string in the set */
TEST(stringObjectTest, lowerString) {
    strlib::String oldStr = strlib::String(25.5,26,strlib::NW,strlib::notes::D,3);
    strlib::String str = strlib::String(oldStr,false);

    EXPECT_NEAR(str.getLength(),25.5,0.0001);
    EXPECT_EQ(str.getGauge(),34);
    EXPECT_EQ(str.getType(),strlib::NW);
    EXPECT_EQ(str.getNote(),strlib::notes::A);
    EXPECT_EQ(str.getOctave(),2);
    EXPECT_NEAR(str.getFrequency(),110,0.0001);
    EXPECT_NEAR(str.getTension(),17.5849,0.0001);
}