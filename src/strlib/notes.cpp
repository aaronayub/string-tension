#include <string>
#include <cmath>

namespace strlib {
    double noteToFrequency(int note) {
        // Difference of the note from A4
        double diff = static_cast<double>(note - 69);
        
        return 440 * std::pow(2,(diff / 12));
    }
}