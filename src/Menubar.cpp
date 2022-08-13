#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Multiline_Output.H>
#include <stdlib.h>

#include "./Menubar.h"

Menubar::Menubar (int x, int y, int w, int h) : Fl_Menu_Bar (x,y,w,h) {
    Fl_Menu_Item menuItems[] = {
        {"&File",0,0,0,FL_SUBMENU},
            {"&Quit", FL_COMMAND + 'q', (Fl_Callback*)quit_cb,0},
            { 0 },
        {"&Help",0,0,0,FL_SUBMENU},
            {"&Help", FL_COMMAND + 'h', (Fl_Callback*)help_cb,0},
            {"About", 0, (Fl_Callback*)about_cb,0},
            { 0 },
        { 0 },
    };

    this->copy(menuItems);
}

/* Exits the program */
void quit_cb(Fl_Widget*, void*) {
    std::exit(0);
}

const char* helpText = R"HELPTEXT(This program is used to calculate the tension of guitar strings or bass strings.

When starting the program, a list of six strings are displayed. Each string occupies one row of values. You are able to adjust the length, gauge, string type, string note, and octave of each string., and the tension and frequency of the note will be adjusted automatically.

In detail, each string has the following.
Length: This is the scale length measured in inches. The scale length is the vibrating length of the string when it is not fretted.
Gauge: The diameter of the string in thousandths of inches (0.001").
Type: The type of string. Currently, the three supported types are plain steel (PL), nickel round-wound steel core guitar strings (NW), and nickel round-wound steel core bass strings (XLB).
Note: The musical note of the string. This uses the English naming convention in 12 tone equal temperament.
Octave: The octave of the note.
Tension: The tension of the string, measured in pounds.
Frequency: Frequency of the note in Hz.

Above the strings is a list of controls.
Presets: Discards the current set of strings, replacing it with a new set of preset strings.
Set Scale: Adjusts the length of all strings on a guitar. If the minimum and maximum length are set (e.g. 25.5 to 27), then all strings will have their lengths adjusted as a multi-scale instrument. If the maximum length is equal to or less than the minimum length, the lengths will be adjusted as a single-scale instrument.
Shift Notes: Shifts every string one semitone up or down.
Add string: Adds a new string 5 semitones above or below the first/last string of the set. The gauge and string type will be automatically calculated from the nearest string.
Remove string: Removes the lowest string in the set.

Press Esc to close this window.)HELPTEXT";

/* Shows a help dialog */
void help_cb(Fl_Widget*, void*) {
    Fl_Window* w = new Fl_Window(700,650, "Help");
    Fl_Multiline_Output* h = new Fl_Multiline_Output(0,0,700,650);
    h->wrap(FL_INPUT_WRAP);
    h->value(helpText);

    w->set_modal();
    w->show();
    while (w->shown()) Fl::wait();
}

const char* aboutText = R"ABOUTTEXT(This program is written by Aaron Ayub.

It is written in C++, and uses FLTK to render the GUI.

This program is open source, made available under the MIT License.

The source code can be found here: https://github.com/AaronAyub/string-tension

Press Esc to close this window.)ABOUTTEXT";

/* Shows dialog detailing the project */
void about_cb(Fl_Widget*, void*) {
    Fl_Window* w = new Fl_Window(700,200, "Help");
    Fl_Multiline_Output* h = new Fl_Multiline_Output(0,0,700,200);
    h->wrap(FL_INPUT_WRAP);
    h->value(aboutText);

    w->set_modal();
    w->show();
    while (w->shown()) Fl::wait();
}