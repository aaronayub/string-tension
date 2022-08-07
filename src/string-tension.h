#pragma once

#include <FL/Fl.H>
#include <FL/Fl_Value_Input.H>

#include "StringView.h"

struct ScaleLengthSet {
    Fl_Value_Input* min;
    Fl_Value_Input* max;
    StringView* sv;
};

static void addUp_cb(Fl_Widget* w, void* v);
static void addDown_cb(Fl_Widget* w, void* v);
static void notesUp_cb(Fl_Widget* w, void* v);
static void notesDown_cb(Fl_Widget* w, void* v);
static void scaleLength_cb(Fl_Widget* w, void* v);