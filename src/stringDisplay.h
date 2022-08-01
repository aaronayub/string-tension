/* A StringDisplay holds information about a string in the calculator,
as well as how it is displayed in the GUI. */

#include <FL/Fl.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Pack.H>
#include <string>

#include "./strlib/string.h"
#include "./strlib/stringtype.h"
#include "./strlib/notes.h"

class StringDisplay {
  public:
    StringDisplay(strlib::String* string, int position);
    void remove();
    void reposition(int position);
    
    strlib::String* getStringPtr();
    void updateFrequency();
    void updateTension();

  private:
    Fl_Pack *pack_;
    Fl_Input *length_;
    Fl_Input *gauge_;
    Fl_Input *octave_;
    Fl_Choice *note_;
    Fl_Choice *type_;
    Fl_Output *frequency_;
    Fl_Output *tension_;

    strlib::String* string_;
    static void type_cb(Fl_Widget* w, void* v);
    static void note_cb(Fl_Widget* w, void* v);
    static void length_cb(Fl_Widget* w, void* v);
    static void gauge_cb(Fl_Widget* w, void* v);
    static void octave_cb(Fl_Widget* w, void* v);

};

static std::string dtoaNoZeroes(double number);

template <typename T>
static T atoPosNum (const char * a);