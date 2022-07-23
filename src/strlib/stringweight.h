#pragma once
#include "stringtype.h"

namespace strlib {
    struct StringWeight {
        int gauge;
        double unitWeight;
    };

    double getUnitWeight(int gauge, StringType type);
}

namespace {

}