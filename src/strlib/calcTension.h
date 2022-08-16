/** @file
 * @brief Function to calculate the tension of a string */

#pragma once
namespace strlib {
    /**
     * Calculates the tension of a string
     * @param unitWeight The unit weight of the string in lb/in
     * @param scaleLength The length of the string in inches
     * @param frequency The frequency of the string in Hz
     * @return The tension of the string in pounds
     */
    double calcTension(double unitWeight, double scaleLength, double frequency);
}