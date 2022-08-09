#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Text_Display.H>

#include "./StringView.h"
#include "./ControlPanel.h"

int main() {
  Fl_Window* window = new Fl_Window(900,900, "String Tension Calculator");
  Fl::scheme("gtk+");

  StringView* view = new StringView(40,150,860,400);
  ControlPanel* panel = new ControlPanel();
  panel->init(view);

  Fl_Pack* labels = new Fl_Pack(40,150,100,40);
  labels->type(Fl_Pack::HORIZONTAL);
  labels->spacing(10);
  labels->begin();
  Fl_Text_Display* length   = new Fl_Text_Display(0,0,100,40,"Length (in)");
  Fl_Text_Display* gauge    = new Fl_Text_Display(0,0,80,40,"Gauge");
  Fl_Text_Display* type     = new Fl_Text_Display(0,0,80,40,"Type");
  Fl_Text_Display* note     = new Fl_Text_Display(0,0,90,40,"Note");
  Fl_Text_Display* octave   = new Fl_Text_Display(0,0,60,40,"Octave");
  Fl_Text_Display* tension  = new Fl_Text_Display(0,0,100,40,"Tension (lbs)");
  Fl_Text_Display* frequency= new Fl_Text_Display(0,0,100,40,"Frequency (Hz)");
  labels->end();
  
  length   ->box(FL_NO_BOX);
  gauge    ->box(FL_NO_BOX);
  type     ->box(FL_NO_BOX);
  note     ->box(FL_NO_BOX);
  octave   ->box(FL_NO_BOX);
  tension  ->box(FL_NO_BOX);
  frequency->box(FL_NO_BOX);


  window->resizable(view);
  window->end();
  window->show();
  return Fl::run();
}