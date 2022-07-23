/* Code for retrieving the unit weight of a string */
#include <vector>
#include "stringweight.h"
#include "stringtype.h"
#include <iostream>
namespace strlib {
    extern const std::vector<strlib::StringWeight> stringsPL;
    extern const std::vector<strlib::StringWeight> stringsNW;
    extern const std::vector<strlib::StringWeight> stringsXLB;
    
    /* Calculates unit weight from a given string type*/
    double getUnitWeight(int gauge, StringType type) {
        // Prevent the user from entering invalid gauges
        if (gauge <= 0) {
            return 0;
        }

        // Pick the list of strings to estimate weight from
        std::vector<StringWeight> list;
        switch (type) {
            case PL:
                list = stringsPL;
                break;
            case NW:
                list = stringsNW;
                break;
            case XLB:
                list = stringsXLB;
                break;
        }
    }
}

