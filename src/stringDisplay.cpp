#include <FL/Fl.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Pack.H>
#include <string>

#include "./strlib/string.h"
#include "./strlib/stringtype.h"
#include "./strlib/notes.h"

#include "./stringDisplay.h"

StringDisplay::StringDisplay(strlib::String* string, int position): string_(string) {
  /* Initialize the pack which holds all widgets */
  pack_ = new Fl_Pack(40, 20 + position * (60 + 10), 100, 60);
  pack_->type(Fl_Pack::HORIZONTAL);
  pack_->spacing(10);

  /* Add all widgets as part of the pack*/
  pack_->begin();
  length_   = new Fl_Input(0,0,100,60,0);
  gauge_    = new Fl_Input(0,0,60,60,0);
  type_     = new Fl_Choice(0,0,80,60,0);
  note_     = new Fl_Choice(0,0,100,60,0);
  octave_   = new Fl_Input(0,0,100,60,0);
  tension_  = new Fl_Output(0,0,100,60,0);
  frequency_= new Fl_Output(0,0,100,60,0);
  pack_->end();

  /* Add selections to the choice widgets*/
  type_->add("PL");
  type_->add("NW");
  type_->add("XLB");

  type_->callback(type_cb, this);

  for (std::string noteName : strlib::NOTELIST) {
    note_->add(noteName.c_str());
  }

  /* Increase the font size of all widgets*/
  length_   ->textsize(18);
  gauge_    ->textsize(18);
  type_     ->textsize(18);
  note_     ->textsize(18);
  octave_   ->textsize(18);
  tension_  ->textsize(18);
  frequency_->textsize(18);

  /* Updates all the widgets to display values from the string */
  length_->value(dtoaNoZeroes(string_->getLength()).c_str());
  gauge_->value(std::to_string(string_->getGauge()).c_str());
  type_->value(string_->getType());
  note_->value(string_->getNote());
  octave_->value(std::to_string(string_->getOctave()).c_str());
  frequency_->value(dtoaNoZeroes(string_->getFrequency()).c_str());
  tension_->value(dtoaNoZeroes(string_->getTension()).c_str());
}

/* Memory-safe deletion of the widget */
void StringDisplay::remove() {
  Fl::delete_widget(pack_);
  delete(string_);
}

/* Repositioning / re-ordering the display for when a new string is added or deleted. */
void StringDisplay::reposition(int position) {
  pack_->position(40,20 + (position + 1) * (60 + 10));
}

/* Callback for when a user changes string type*/
void StringDisplay::type_cb(Fl_Widget* w, void* v) {
  Fl_Choice* choice {static_cast<Fl_Choice*>(w)};
  StringDisplay* display {static_cast<StringDisplay*>(v)};
  strlib::String* strptr = display->getStringPtr();
  strptr->setType(static_cast<strlib::StringType>(choice->value()));
  display->updateFrequency();
  display->updateTension();
}

void StringDisplay::updateFrequency() {
  frequency_->value(dtoaNoZeroes(string_->getFrequency()).c_str());
}
void StringDisplay::updateTension() {
  tension_->value(dtoaNoZeroes(string_->getTension()).c_str());
}

strlib::String* StringDisplay::getStringPtr() {
  return string_;
}

/* Convert double to string, removing trailing 0's, and the decimal point if it's an integer. */
static std::string dtoaNoZeroes(double number) {
  std::string str = std::to_string(number);
  str.erase(str.find_last_not_of('0') + 1);
  if (str.back() == '.') {
    str.pop_back();
  }
  return str;
}