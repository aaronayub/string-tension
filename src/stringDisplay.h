/* A StringDisplay holds information about a string in the calculator,
as well as how it is displayed in the GUI. */
#pragma once

#include <FL/Fl.H>
#include <FL/Fl_Value_Input.H>
#include <FL/Fl_Value_Output.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Pack.H>

#include "./strlib/string.h"

class StringDisplay : public Fl_Pack {
  public:
    StringDisplay(strlib::String* string, int position, int topMargin);
    void remove();
    void reposition(int position);
    
    strlib::String* getStringPtr();
    void updateFrequency();
    void updateTension();
    void incrementNote(int increment);
    void setLength(double length);

  private:
    Fl_Value_Input *length_;
    Fl_Value_Input *gauge_;
    Fl_Value_Input *octave_;
    Fl_Choice *note_;
    Fl_Choice *type_;
    Fl_Value_Output *frequency_;
    Fl_Value_Output *tension_;

    strlib::String* string_;
    static void type_cb(Fl_Widget* w, void* v);
    static void note_cb(Fl_Widget* w, void* v);
    static void length_cb(Fl_Widget* w, void* v);
    static void gauge_cb(Fl_Widget* w, void* v);
    static void octave_cb(Fl_Widget* w, void* v);
    int topMargin_;
};