/* A StringDisplay holds information about a string in the calculator,
as well as how it is displayed in the GUI. */

#include <FL/Fl.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Pack.H>
#include <string>

#include "./strlib/string.h"

class StringDisplay {
  public:
    StringDisplay(strlib::String& string, int position);
    void remove();
    void reposition(int position);

  private:
    Fl_Pack *pack;
    Fl_Input *length;
    Fl_Input *gauge;
    Fl_Input *octave;
    Fl_Choice *note;
    Fl_Choice *type;
    Fl_Output *frequency;
    Fl_Output *tension;
    strlib::String string_;
};

std::string dtoaNoZeroes(double number);