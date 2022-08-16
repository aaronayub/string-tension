/** @file
 * @brief Functionality relating to the names and properties of notes */

#pragma once
#include <string>

namespace strlib {
    /**
     * Calculates the frequency of a given note
     * @param note The MIDI value of the note
     * @return The frequency of the note in Hz
     */
    double noteToFrequency(int note);

    /** Const array for all notes in 12 tone equal temperament */
    const std::string NOTELIST[12] {
        "C",
        "C#, Db",
        "D",
        "D#, Eb",
        "E",
        "F",
        "F#, Gb",
        "G",
        "G#, Ab",
        "A",
        "A#, Bb",
        "B"
    };

    namespace notes {
        /** Enum of notes in 12 tone equal temperament */
        enum Notename {
            C,
            Db,
            D,
            Eb,
            E,
            F,
            Gb,
            G,
            Ab,
            A,
            Bb,
            B
        };
    }
}