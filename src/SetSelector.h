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
         @return The numerical value of the last selected set*/
        int getCurrentSet();

        /** Sets the value of the currentSet
         * @param The numerical value of the set
         */
        void setCurrentSet(int set);

    private:
        StringView* view_;
        int currentSet_; // Choice value of the last selected set. This needs to be stored to allow the callback to be usable externally
};

/** Replaces the set of strings in the StringView with the new set chosen by the SetSelector
 * @param w The SetSelector widget
 * @param v The StringView
 */
static void applySet_cb(Fl_Widget* w, void* v);