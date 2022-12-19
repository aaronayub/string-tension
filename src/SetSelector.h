/** @file
 * @brief The SetSelector choice widget */

#pragma once

#include <FL/Fl.H>
#include <FL/Fl_Choice.H>

#include "./StringView.h"

/** @brief A choice widget which applies predefined string sets to a StringView */
class SetSelector : public Fl_Choice {
    public:
        /** Places the selector widget at the specified position */
        SetSelector(int x, int y, int w, int h, const char* label = 0);

        /** Associates a StringView with the selector, and sets up a callback for it
         * @param view The StringView that the selector controls
         */
        void init(StringView* view);

        /** Gets the value of the currentSet
         @return The numerical value of the last selected set */
        int getCurrentSet();

        /** Sets the value of the currentSet
         * @param set The numerical value of the set
         */
        void setCurrentSet(int set);

        /** Gets the value of the currentTuning
         @return The numerical value of the last selected tuning */
        int getCurrentTuning();

        /** Sets the value of the currentTuning
         * @param tuning The numerical value of the tuning
         */
        void setCurrentTuning(int set);

        /** Tunes a string set based on whether it is a guitar or bass
         * @param set The string set to tune
         * @param tuning The numerical value of the tuning
         * @param isGuitar True if the set is for a guitar, false if it is for a bass
         */
        static void tuneSet(std::vector<strlib::String*>&, int tuning, bool isGuitar);

    private:
        StringView* view_;
        int currentSet_; // Choice value of the last selected set. This needs to be stored to allow the callback to be usable externally
        int currentTuning_; // Choice value of the last selected tuning.
};

/** Replaces the set of strings in the StringView with the new set chosen by the SetSelector
 * @param w The SetSelector widget
 * @param v The StringView
 */
static void applySet_cb(Fl_Widget* w, void* v);