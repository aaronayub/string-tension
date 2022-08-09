/* A set of controls to manage a StringView*/
#pragma once

#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Value_Input.H>

#include "./StringView.h"
#include "./SetSelector.h"

class ControlPanel {
    public:
        ControlPanel();
        void init(StringView* view);
    private:
        SetSelector* selector_;
        Fl_Value_Input* scaleMin_;
        Fl_Value_Input* scaleMax_;
        Fl_Button* notesUp_;
        Fl_Button* notesDown_;
        Fl_Button* addUp_;
        Fl_Button* addDown_;
        Fl_Button* scaleButton_;
};

// Set of pointers needed to adjust the scale length of all strings
struct ScaleLengthSet {
    Fl_Value_Input* min;
    Fl_Value_Input* max;
    StringView* sv;
};

static void addUp_cb(Fl_Widget* w, void* v);
static void addDown_cb(Fl_Widget* w, void* v);
static void notesUp_cb(Fl_Widget* w, void* v);
static void notesDown_cb(Fl_Widget* w, void* v);
static void setScale_cb(Fl_Widget* w, void* v);