/** @file
 * @brief The Menubar widget */
#pragma once

#include <FL/Fl.H>
#include <FL/Fl_Menu_Bar.H>

/** @brief A menu bar at the top of the main window. */
class Menubar : public Fl_Menu_Bar {
    public:
        /** @brief Constructs a Menubar at the given position */
        Menubar (int x, int y, int w, int h);
};

/** Exits the program */
static void quit_cb(Fl_Widget*, void*);

/** Displays a dialog offering users instructions on how to use the program */
static void help_cb(Fl_Widget*, void*);

/** Displays a dialog detailing information on the program */
static void about_cb(Fl_Widget*, void*);