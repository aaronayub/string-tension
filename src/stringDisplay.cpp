#include <FL/Fl.H>
#include <FL/Fl_Value_Input.H>
#include <FL/Fl_Value_Output.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Pack.H>
#include <string>

#include "./strlib/string.h"
#include "./strlib/stringtype.h"
#include "./strlib/notes.h"

#include "./stringDisplay.h"

static constexpr int itemSpacing = 10;
static constexpr int packHeight = 40;

StringDisplay::StringDisplay(strlib::String* string) : Fl_Pack(0, 0, 0, packHeight, 0) {
  this->type(Fl_Pack::HORIZONTAL);
  this->spacing(itemSpacing);

  string_ = string;
  
  /* Add all widgets as part of the pack*/
  length_   = new Fl_Value_Input(0,0,100,60,0);
  gauge_    = new Fl_Value_Input(0,0,80,60,0);
  type_     = new Fl_Choice(0,0,80,60,0);
  note_     = new Fl_Choice(0,0,90,60,0);
  octave_   = new Fl_Value_Input(0,0,60,60,0);
  tension_  = new Fl_Value_Output(0,0,100,60,0);
  frequency_= new Fl_Value_Output(0,0,100,60,0);
  this->end();

  /* Add selections to the choice widgets*/
  type_->add("PL");
  type_->add("NW");
  type_->add("XLB");

  for (std::string noteName : strlib::NOTELIST) {
    note_->add(noteName.c_str());
  }

  /* Add callbacks to widgets*/
  type_->callback(type_cb, this);
  note_->callback(note_cb, this);
  length_->callback(length_cb, this);
  gauge_->callback(gauge_cb, this);
  octave_->callback(octave_cb, this);

  length_->when(FL_WHEN_CHANGED);
  gauge_->when(FL_WHEN_CHANGED);
  octave_->when(FL_WHEN_CHANGED);

  /* Increase the font size of all widgets*/
  length_   ->textsize(18);
  gauge_    ->textsize(18);
  type_     ->textsize(18);
  note_     ->textsize(18);
  octave_   ->textsize(18);
  tension_  ->textsize(18);
  frequency_->textsize(18);

  /* Updates all the widgets to display values from the string */
  length_->value(string_->getLength());
  gauge_->value(string_->getGauge());
  type_->value(string_->getType());
  note_->value(string_->getNote());
  octave_->value(string_->getOctave());
  updateTension();
  updateFrequency();
}

/* Memory-safe deletion of the widget */
void StringDisplay::remove() {
  delete(string_);
  Fl::delete_widget(this);
}

/* Callback for when a user changes string type */
void StringDisplay::type_cb(Fl_Widget* w, void* v) {
  Fl_Choice* choice {static_cast<Fl_Choice*>(w)};
  StringDisplay* display {static_cast<StringDisplay*>(v)};
  strlib::String* strptr = display->getStringPtr();
  strptr->setType(static_cast<strlib::StringType>(choice->value()));
  display->updateTension();
}

/* Callback for when a user changes string note */
void StringDisplay::note_cb(Fl_Widget* w, void* v) {
  Fl_Choice* choice {static_cast<Fl_Choice*>(w)};
  StringDisplay* display {static_cast<StringDisplay*>(v)};
  strlib::String* strptr = display->getStringPtr();
  strptr->setNote(static_cast<strlib::notes::Notename>(choice->value()));
  display->updateFrequency();
  display->updateTension();
}

/* Callback for when a user changes string length */
void StringDisplay::length_cb(Fl_Widget* w, void* v) {
  Fl_Value_Input* input {static_cast<Fl_Value_Input*>(w)};
  StringDisplay* display {static_cast<StringDisplay*>(v)};
  strlib::String* strptr = display->getStringPtr();

  double length = input->value();
  length = length < 0 ? -length : length;
  strptr->setLength(length);
  display->updateTension();
}

/* Callback for when a user changes string gauge */
void StringDisplay::gauge_cb(Fl_Widget* w, void* v) {
  Fl_Value_Input* input {static_cast<Fl_Value_Input*>(w)};
  StringDisplay* display {static_cast<StringDisplay*>(v)};
  strlib::String* strptr = display->getStringPtr();

  int gauge = input->value();
  gauge = gauge < 0 ? -gauge : gauge;
  strptr->setGauge(gauge);
  display->updateTension();
}

/* Callback for when a user changes string octave */
void StringDisplay::octave_cb(Fl_Widget* w, void* v) {
  Fl_Value_Input* input {static_cast<Fl_Value_Input*>(w)};
  StringDisplay* display {static_cast<StringDisplay*>(v)};
  strlib::String* strptr = display->getStringPtr();

  int octave = input->value();
  octave = octave < 0 ? -octave : octave;
  strptr->setOctave(octave);
  display->updateFrequency();
  display->updateTension();
}

// Update the note of the string by a specified amount
void StringDisplay::incrementNote(int increment) {
  string_->incrementNote(increment);
  note_->value(string_->getNote());
  octave_->value(string_->getOctave());
  updateFrequency();
  updateTension();
}

// Sets the string length, and updates widgets.
void StringDisplay::setLength(double length) {
  string_->setLength(length);
  length_->value(string_->getLength());
  updateTension();
}

void StringDisplay::updateFrequency() {
  frequency_->value(string_->getFrequency());
}
void StringDisplay::updateTension() {
  tension_->value(string_->getTension());
}

strlib::String* StringDisplay::getStringPtr() {
  return string_;
}