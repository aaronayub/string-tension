/* Functionality relating to the names and properties of notes*/
#include <string>
#include <cmath>

namespace strlib {
    /* Returns the frequency associated with a provided MIDI note number*/
    double noteToFrequency(int note) {
        double diff = static_cast<double>(note - 69); // Difference of the note from A4
        return 440 * std::pow(2,(diff / 12));
    }
}