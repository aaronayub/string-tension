#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <deque>

#include "./strlib/string.h"
#include "./strlib/stringtype.h"
#include "./strlib/notes.h"

#include "./stringDisplay.h"

Fl_Window* window;

// Add's a string to the top of the list.
void addUp_cb(Fl_Widget* w, void* v) {
  std::deque<StringDisplay*>* list = static_cast<std::deque<StringDisplay*>*>(v);
  if (list->empty()) {
    strlib::String* newStr = new strlib::String(25.5,10,strlib::PL,strlib::notes::E,4);
    StringDisplay* d = new StringDisplay(newStr,0);
    window->add(d->getPackPtr());
    list->push_back(d);
  }
  else {
    strlib::String* newStr = new strlib::String(*(list->front()->getStringPtr()),true);
    StringDisplay* d = new StringDisplay(newStr,0);
    window->add(d->getPackPtr());
    list->push_front(d);
    for (int i = 0; i < list->size(); i++) {
      list->at(i)->reposition(i);
    }
  }
  window->redraw();
}

// Add's a string to the bpttom of the list.
void addDown_cb(Fl_Widget* w, void* v) {
  std::deque<StringDisplay*>* list = static_cast<std::deque<StringDisplay*>*>(v);
  if (list->empty()) {
    strlib::String* newStr = new strlib::String(25.5,10,strlib::PL,strlib::notes::E,4);
    StringDisplay* d = new StringDisplay(newStr,0);
    window->add(d->getPackPtr());
    list->push_back(d);
  }
  else {
    strlib::String* newStr = new strlib::String(*(list->back()->getStringPtr()),false);
    StringDisplay* d = new StringDisplay(newStr,list->size());
    window->add(d->getPackPtr());
    list->push_back(d);
    for (int i = 0; i < list->size(); i++) {
      list->at(i)->reposition(i);
    }
  }
  window->redraw();
}

int main() {
  window = new Fl_Window(900,900, "String Tension Calculator");
  Fl::scheme("gtk+");
  

  std::deque<strlib::String*> strList = {};
  strList.push_back(new strlib::String(25.5,10,strlib::PL,strlib::notes::E, 4));
  strList.push_back(new strlib::String(25.5,13,strlib::PL,strlib::notes::B, 3));
  strList.push_back(new strlib::String(25.5,17,strlib::PL,strlib::notes::G, 3));
  strList.push_back(new strlib::String(25.5,26,strlib::NW,strlib::notes::D, 3));
  strList.push_back(new strlib::String(25.5,36,strlib::NW,strlib::notes::A, 2));
  strList.push_back(new strlib::String(25.5,46,strlib::NW,strlib::notes::E, 2));
  
  std::deque<StringDisplay*> displays = {};
  for (int i = 0; i < strList.size(); i++) {
    StringDisplay* d = new StringDisplay(strList[i],i);
    displays.push_back(d);
  }
  
  Fl_Pack* controls = new Fl_Pack(40,20,100,40);
  controls->type(Fl_Pack::HORIZONTAL);
  controls->spacing(10);
  controls->begin();
  Fl_Button* addUp = new Fl_Button(0,0,160,0,"Add higher string");
  Fl_Button* addDown = new Fl_Button(0,0,160,0,"Add lower string");
  controls->end();
  addUp->callback(addUp_cb,&displays);
  addDown->callback(addDown_cb,&displays);

  Fl_Box* resizeBox = new Fl_Box(9999,9999,5,5);
  resizeBox->hide();
  window->resizable(resizeBox);
  window->end();
  window->show();
  return Fl::run();
}