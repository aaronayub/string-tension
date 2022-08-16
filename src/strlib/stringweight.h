/**
 * @file
 * @brief Functions to retrieve and estimate unit weights of strings
 */
#pragma once
#include "stringtype.h"

namespace strlib {
    /** A correlation of unit weight to a string of a given gauge */
    struct StringWeight {
        int gauge;
        double unitWeight;
    };

    /**
     * Calculates the unit weight of a string
     * @param gauge Diameter of the string in thousandths of an inch
     * @param type Type of string construction or material
     * @return The unit weight in lbs/in
     */
    double getUnitWeight(int gauge, StringType type);

    /**
     * Interpolates or extrapolates the unit weight of a string
     * @param gauge Gauge of the string to estimate unit weight for
     * @param low A lower gauge string of the same type to use for estimation
     * @param high A higher gauge string of the same type to use for estimation
     * @return The estimated unit weight
     */
    double estimateWeight(int gauge, const StringWeight& low, const StringWeight& high);
}