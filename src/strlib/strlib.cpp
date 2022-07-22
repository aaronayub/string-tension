/* Library for calculating dimensions of a guitar/bass string, and related note properties. */
#include <cmath>

namespace strlib {
    /* Calculate a string's tension. Returns the tension in pounds. */
    double calcTension(double unitWeight, double scaleLength, double frequency) {
        return unitWeight * std::pow((2 * scaleLength * frequency),2) / 386.4;
    }

    /* Returns the frequency associated with a provided MIDI note number*/
    double noteToFrequency(int note) {
        double diff = static_cast<double>(note - 69); // Difference of the note from A4
        return 440 * std::pow(2,(diff / 12));
    }

}