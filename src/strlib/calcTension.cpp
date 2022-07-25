#include <cmath>

namespace strlib {
    /* Calculate a string's tension. Returns the tension in pounds. */
    double calcTension(double unitWeight, double scaleLength, double frequency) {
        return unitWeight * std::pow((2 * scaleLength * frequency),2) / 386.4;
    }
}