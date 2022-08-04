#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Text_Display.H>
#include <vector>

#include "./strlib/string.h"
#include "./strlib/stringtype.h"
#include "./strlib/notes.h"

#include "./stringDisplay.h"
#include "./StringView.h"

Fl_Window* window;

// Adds a string to the top of the list.
void addUp_cb(Fl_Widget* w, void* v) {
  StringView* view = static_cast<StringView*>(v);
  view->addString(true);
}

// Adds a string to the bottom of the list.
void addDown_cb(Fl_Widget* w, void* v) {
  StringView* view = static_cast<StringView*>(v);
  view->addString(false);
}

int main() {
  window = new Fl_Window(900,900, "String Tension Calculator");
  Fl::scheme("gtk+");
  
  Fl_Pack* controls = new Fl_Pack(40,20,100,40);
  controls->type(Fl_Pack::HORIZONTAL);
  controls->spacing(10);
  controls->begin();
  Fl_Button* addUp = new Fl_Button(0,0,160,0,"Add higher string");
  Fl_Button* addDown = new Fl_Button(0,0,160,0,"Add lower string");
  controls->end();

  Fl_Pack* labels = new Fl_Pack(40,90,100,40);
  labels->type(Fl_Pack::HORIZONTAL);
  labels->spacing(10);
  labels->begin();
  Fl_Text_Display* length   = new Fl_Text_Display(0,0,100,40,"Length (in)");
  Fl_Text_Display* gauge    = new Fl_Text_Display(0,0,80,40,"Gauge");
  Fl_Text_Display* type     = new Fl_Text_Display(0,0,80,40,"Type");
  Fl_Text_Display* note     = new Fl_Text_Display(0,0,100,40,"Note");
  Fl_Text_Display* octave   = new Fl_Text_Display(0,0,60,40,"Octave");
  Fl_Text_Display* tension  = new Fl_Text_Display(0,0,100,40,"Tension (lbs)");
  Fl_Text_Display* frequency= new Fl_Text_Display(0,0,100,40,"Frequency (Hz)");
  
  length   ->box(FL_NO_BOX);
  gauge    ->box(FL_NO_BOX);
  type     ->box(FL_NO_BOX);
  note     ->box(FL_NO_BOX);
  octave   ->box(FL_NO_BOX);
  tension  ->box(FL_NO_BOX);
  frequency->box(FL_NO_BOX);
  labels->end();


  std::vector<strlib::String*> strList = {};
  strList.push_back(new strlib::String(25.5,10,strlib::PL,strlib::notes::E, 4));
  strList.push_back(new strlib::String(25.5,13,strlib::PL,strlib::notes::B, 3));
  strList.push_back(new strlib::String(25.5,17,strlib::PL,strlib::notes::G, 3));
  strList.push_back(new strlib::String(25.5,26,strlib::NW,strlib::notes::D, 3));
  strList.push_back(new strlib::String(25.5,36,strlib::NW,strlib::notes::A, 2));
  strList.push_back(new strlib::String(25.5,46,strlib::NW,strlib::notes::E, 2));

  StringView* view = new StringView(40,100,860,800);
  view->applySet(strList);

  addUp->callback(addUp_cb,view);
  addDown->callback(addDown_cb,view);

  window->resizable(view);
  window->end();
  window->show();
  return Fl::run();
}