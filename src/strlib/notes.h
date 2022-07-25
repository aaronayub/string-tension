#pragma once
#include <string>

namespace strlib {
    double noteToFrequency(int note);
    const std::string NOTELIST[12];

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