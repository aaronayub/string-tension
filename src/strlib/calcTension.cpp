#include <cmath>

namespace strlib {
    double calcTension(double unitWeight, double scaleLength, double frequency) {
        return unitWeight * std::pow((2 * scaleLength * frequency),2) / 386.4;
    }
}