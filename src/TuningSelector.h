/** @file
 * @brief The TuningSelector choice widget */

#pragma once

#include <FL/Fl.H>
#include <FL/Fl_Choice.H>

#include "./strlib/string.h"
#include "SetSelector.h"
#include "StringView.h"

/** @brief A choive widget which controls which tuning a string set will be in */
class TuningSelector : public Fl_Choice {
    public:
        /** Places the selector widget at the specified position */
        TuningSelector(int x, int y, int w, int h, const char *label = 0);
        /** Associates a SetSelector with this widget, and sets up a callback for it.
         @param setSelector The SetSelector to trigger on this widget's callback
         */
        void init(SetSelector* setSelector);
};

/** Re-creates the string set and tuning
 @param w The TuningSelector widget
 @param v The SetSelector widget whose callback is activated. */
static void tuningSelector_cb(Fl_Widget* w, void* v);