/* Library for calculating dimensions of a guitar/bass string, and related note properties. */
#include <cmath>
#include "stringweight.h"

namespace strlib {
    double calcTension(double unitWeight, double scaleLength, double frequency);
    double noteToFrequency(int note);
}