/** @file
 * @brief Control Panel class */
#pragma once

#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Value_Input.H>

#include "./StringView.h"
#include "./SetSelector.h"
#include "./TuningSelector.h"

/**
 * \brief A set of controls to manage a StringView
 * The panel only instantiates a set of widgets, and is not an FLTK widget itself.
 */
class ControlPanel {
    public:
        /**
         * Initializes a set of Fl_Widgets at the specified height.
         * @param y Highest point of the set of Fl_Widgets
        */
        ControlPanel(int y);
        /** Sets up callbacks for all control widgets
         * @param view A StringView that the ControlPanel controls.
        */
        void init(StringView* view);
    private:
        SetSelector* setSelector_;
        TuningSelector* tuningSelector_;
        Fl_Value_Input* scaleMin_;
        Fl_Value_Input* scaleMax_;
        Fl_Button* notesUp_;
        Fl_Button* notesDown_;
        Fl_Button* addUp_;
        Fl_Button* addDown_;
        Fl_Button* remove_;
        Fl_Button* scaleButton_;
};

/** @brief Set of pointers needed to adjust the scale length of all strings */
struct ScaleLengthSet {
    Fl_Value_Input* min;
    Fl_Value_Input* max;
    StringView* sv;
};

/** Adds a new string to the StringView, tuned higher than the highest string
 * @param v The StringView pointer
 */
static void addUp_cb(Fl_Widget* w, void* v);

/** Adds a new string to the StringView, tuned lower than the lowest string
 * @param v The StringView pointer
 */
static void addDown_cb(Fl_Widget* w, void* v);

/** Tunes all notes a semitone higher
 * @param v The StringView pointer
 */
static void notesUp_cb(Fl_Widget* w, void* v);

/** Tunes all notes a semitone lower
 * @param v The StringView pointer
 */
static void notesDown_cb(Fl_Widget* w, void* v);

/** Set the scale length of all strings in the StringView
 * @param v The ScaleLengthSet
 */
static void setScale_cb(Fl_Widget* w, void* v);

/** Removes the lowest string in the StringView
 * @param v The StringView pointer
 */
static void remove_cb(Fl_Widget* w, void* v);