#pragma once
#include <string>

namespace strlib {
    double noteToFrequency(int note);

    /* Const array for all notes in 12 tone equal temperament */
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

    /* Enum of notes in 12 tone equal temperament */
    namespace notes {
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