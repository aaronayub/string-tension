#include <FL/Fl.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Pack.H>

#include "./strlib/string.h"
#include "./strlib/stringtype.h"
#include "./strlib/notes.h"

#include "./stringDisplay.h"

StringDisplay::StringDisplay(strlib::String& string, int position) {
    /* Initialize the pack which holds all widgets */
    pack = new Fl_Pack(40, 20 + position * (60 + 10), 100, 60);
    pack->type(Fl_Pack::HORIZONTAL);
    pack->spacing(10);

    /* Add all widgets as part of the pack*/
    pack->begin();
    length    = new Fl_Input(0,0,100,60,0);
    gauge     = new Fl_Input(0,0,60,60,0);
    type      = new Fl_Choice(0,0,80,60,0);
    note      = new Fl_Choice(0,0,100,60,0);
    octave    = new Fl_Input(0,0,100,60,0);
    tension   = new Fl_Output(0,0,100,60,0);
    frequency = new Fl_Output(0,0,100,60,0);
    pack->end();

    /* Add selections to the choice widgets*/
    type->add("PL");
    type->add("NW");
    type->add("XLB");

    for (std::string noteName : strlib::NOTELIST) {
      note->add(noteName.c_str());
    }

    /* Increase the font size of all widgets*/
    length   ->textsize(18);
    gauge    ->textsize(18);
    type     ->textsize(18);
    note     ->textsize(18);
    octave   ->textsize(18);
    tension  ->textsize(18);
    frequency->textsize(18);
  }

/* Memory-safe deletion of the widget */
void StringDisplay::remove() {
  Fl::delete_widget(pack);
}

/* Repositioning / re-ordering the display for when a new string is added or deleted. */
void StringDisplay::reposition(int position) {
  pack->position(40,20 + (position + 1) * (60 + 10));
}