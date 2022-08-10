#include <FL/Fl.H>
#include <FL/Fl_Menu_Bar.H>
#include <stdlib.h>

#include "./Menubar.h"

Menubar::Menubar (int x, int y, int w, int h) : Fl_Menu_Bar (x,y,w,h) {
    Fl_Menu_Item menuItems[] = {
        {"&File",0,0,0,FL_SUBMENU},
            {"&Quit", FL_COMMAND + 'q', (Fl_Callback*)quit_cb,0},
            { 0 },
        { 0 },
    };

    this->copy(menuItems);
}

/* Exits the program */
void quit_cb(Fl_Widget* w, void* v) {
    std::exit(0);
}