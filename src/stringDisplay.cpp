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
#include <charconv>

static constexpr int leftMargin = 40; 
static constexpr int topMargin = 100;
static constexpr int spacing = 10;
static constexpr int packHeight = 40;

StringDisplay::StringDisplay(strlib::String* string, int position): string_(string) {
  /* Initialize the pack which holds all widgets */
  pack_ = new Fl_Pack(leftMargin, topMargin + position * (packHeight + spacing), 100, packHeight);
  pack_->type(Fl_Pack::HORIZONTAL);
  pack_->spacing(spacing);

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
  length_->value(dtoaNoZeroes(string_->getLength()).c_str());
  gauge_->value(std::to_string(string_->getGauge()).c_str());
  type_->value(string_->getType());
  note_->value(string_->getNote());
  octave_->value(std::to_string(string_->getOctave()).c_str());
  frequency_->value(dtoaNoZeroes(string_->getFrequency()).c_str());
  tension_->value(dtoaNoZeroes(string_->getTension()).c_str());
}

/* Returns a pointer to the pack*/
Fl_Pack* StringDisplay::getPackPtr() {
  return pack_;
}

/* Memory-safe deletion of the widget */
void StringDisplay::remove() {
  Fl::delete_widget(pack_);
  delete(string_);
}

/* Repositioning / re-ordering the display for when a new string is added or deleted. */
void StringDisplay::reposition(int position) {
  pack_->position(leftMargin,topMargin + position * (packHeight + spacing));
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
  Fl_Input* input {static_cast<Fl_Input*>(w)};
  StringDisplay* display {static_cast<StringDisplay*>(v)};
  strlib::String* strptr = display->getStringPtr();

  double length = atoPosNum<double>(input->value());
  strptr->setLength(length);
  display->updateTension();
}

/* Callback for when a user changes string gauge */
void StringDisplay::gauge_cb(Fl_Widget* w, void* v) {
  Fl_Input* input {static_cast<Fl_Input*>(w)};
  StringDisplay* display {static_cast<StringDisplay*>(v)};
  strlib::String* strptr = display->getStringPtr();

  int gauge = atoPosNum<int>(input->value());
  strptr->setGauge(gauge);
  display->updateTension();
}

/* Callback for when a user changes string octave */
void StringDisplay::octave_cb(Fl_Widget* w, void* v) {
  Fl_Input* input {static_cast<Fl_Input*>(w)};
  StringDisplay* display {static_cast<StringDisplay*>(v)};
  strlib::String* strptr = display->getStringPtr();

  int octave = atoPosNum<int>(input->value());
  strptr->setOctave(octave);
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

/* Converts a c-style string to a positive number  */
template <typename T>
static T atoPosNum (const char * a) {
  std::string str = a;
  T out;
  auto [_, err] = std::from_chars(str.data(), str.data() + str.size(), out);
  if (err == std::errc::invalid_argument) { // Avoid undefined behaviour blank inputs
    return 0;
  }
  if (out < 0) out*=-1; // Do not allow negative numbers
  return out;
}