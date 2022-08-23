/** Main class for the String Tension GUI. */

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Output.H>

#include "./StringView.h"
#include "./ControlPanel.h"
#include "./Menubar.h"

int main() {
  Fl_Window* window = new Fl_Window(750,900, "String Tension Calculator");
  Fl::scheme("gtk+");

  Menubar* menu = new Menubar(0,0,750,30);
  ControlPanel* panel = new ControlPanel(60);
  StringView* view = new StringView(40,180,700,720);
  panel->init(view);

  /** Initialize a set of labels to describe what each part of a StringDisplay does */
  Fl_Pack* labels = new Fl_Pack(40,180,100,40);
  labels->type(Fl_Pack::HORIZONTAL);
  labels->spacing(10);
  labels->begin();
  Fl_Output* length   = new Fl_Output(0,0,100,40,"Length (in)");
  Fl_Output* gauge    = new Fl_Output(0,0,80,40,"Gauge");
  Fl_Output* type     = new Fl_Output(0,0,80,40,"Type");
  Fl_Output* note     = new Fl_Output(0,0,90,40,"Note");
  Fl_Output* octave   = new Fl_Output(0,0,60,40,"Octave");
  Fl_Output* tension  = new Fl_Output(0,0,100,40,"Tension (lbs)");
  Fl_Output* frequency= new Fl_Output(0,0,100,40,"Frequency (Hz)");
  labels->end();
  
  /** Remove the backgrounds from each label */
  length   ->box(FL_NO_BOX);
  gauge    ->box(FL_NO_BOX);
  type     ->box(FL_NO_BOX);
  note     ->box(FL_NO_BOX);
  octave   ->box(FL_NO_BOX);
  tension  ->box(FL_NO_BOX);
  frequency->box(FL_NO_BOX);

  /* Move each label above the invisible output boxes */
  length   ->align(FL_ALIGN_TOP);
  gauge    ->align(FL_ALIGN_TOP);
  type     ->align(FL_ALIGN_TOP);
  note     ->align(FL_ALIGN_TOP);
  octave   ->align(FL_ALIGN_TOP);
  tension  ->align(FL_ALIGN_TOP);
  frequency->align(FL_ALIGN_TOP);

  /** Allow the window to be resized. The StringView will be resized with the window. */
  window->resizable(view);
  window->end();
  window->show();
  return Fl::run();
}