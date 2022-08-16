/** @file
 * @brief The StringView widget */
#pragma once

#include <FL/Fl.H>
#include <FL/Fl_Pack.H>
#include <FL/Fl_Scroll.H>
#include <deque>
#include <vector>

#include "./strlib/string.h"

#include "./stringDisplay.h"
/** @brief An Fl_Scroll which manages a variable amount of Strings, and the StringDisplays which represent them */
class StringView : public Fl_Scroll {
    public:
        /** Places an Fl_Scroll for the StringView with the specified location and dimensions */
        StringView(int x, int y, int w, int h, const char *label = 0);

        /** Replaces the current set of strings with a predefined string set
         * @param set The new set of strings to display
         */
        void applySet(std::vector<strlib::String*>& set);

        /** Add a string to the StringView
         * @param higher If true, a string tuned 5 semitones higher will be added at the front of the list. If false, the new string will be 5 tuned semitones lower, and at the bottom of the list.
         */
        void addString(bool higher);

        /** Shift all strings in the set by a specified amount
         * @param increment The number of semitones to tune all string up or down
         */
        void incrementAll(int increment);

        /** Set the scale lengths of all strings in the set
         * @param min The length of the shortest side of the neck.
         * @param max The length of the longest side of the neck. Is equal to min if not provided.
         */
        void setLengths(double min, double max);

        /** Removes the lowest string in the set */
        void removeString();

    private:
        std::deque<StringDisplay*> list_;
        Fl_Pack* pack;
};