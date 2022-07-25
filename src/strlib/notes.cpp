/* Functionality relating to the names and properties of notes*/
#include <string>
#include <cmath>

namespace strlib {
    /* Returns the frequency associated with a provided MIDI note number*/
    double noteToFrequency(int note) {
        double diff = static_cast<double>(note - 69); // Difference of the note from A4
        return 440 * std::pow(2,(diff / 12));
    }

    /* Const array for all notes in 12 tone equal temperament */
    const std::string NOTELIST[12] {
        "C",
        "C#/Db",
        "D",
        "D#/Eb",
        "E",
        "F",
        "F#/Gb",
        "G",
        "G#/Ab",
        "A",
        "A#/Bb",
        "B"
    };
}