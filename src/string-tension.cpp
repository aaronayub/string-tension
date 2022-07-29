#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <vector>

#include "./strlib/string.h"
#include "./strlib/stringtype.h"
#include "./strlib/notes.h"

#include "./stringDisplay.h"

int main() {
  Fl_Window *window = new Fl_Window(900,600, "String Tension Calculator");
  window->resizable(window);
  Fl::scheme("gtk+");

  std::vector<strlib::String> strList = {};
  strList.push_back(strlib::String(25.5,26,strlib::PL,strlib::notes::E, 4));
  strList.push_back(strlib::String(25.5,36,strlib::PL,strlib::notes::B, 3));
  strList.push_back(strlib::String(25.5,46,strlib::PL,strlib::notes::G, 3));
  strList.push_back(strlib::String(25.5,26,strlib::NW,strlib::notes::D, 3));
  strList.push_back(strlib::String(25.5,36,strlib::NW,strlib::notes::A, 2));
  strList.push_back(strlib::String(25.5,46,strlib::NW,strlib::notes::E, 2));
  
  std::vector<StringDisplay> displays = {};
  for (int i = 0; i < strList.size(); i++) {
    displays.push_back(StringDisplay(strList[i],i));
  }

  window->end();
  window->show();
  return Fl::run();
}