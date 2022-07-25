/* Tests conversion of notes from name to MIDI, and MIDI to frequency.*/

#include <gtest/gtest.h>
#include "../src/strlib/notes.h"

TEST(strlibTest, noteToFrequencyTest) {
    EXPECT_DOUBLE_EQ(strlib::noteToFrequency(69),440); // Concert Pitch
    EXPECT_DOUBLE_EQ(strlib::noteToFrequency(57),220); // An octave down
    EXPECT_DOUBLE_EQ(strlib::noteToFrequency(81),880); // An octave up
    
    EXPECT_NEAR(strlib::noteToFrequency(60),261.6256,0.001); // Middle C
    EXPECT_NEAR(strlib::noteToFrequency(36),65.40639,0.001); // C2
    EXPECT_NEAR(strlib::noteToFrequency(28),41.20344,0.001); // E1
}