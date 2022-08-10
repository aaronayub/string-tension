#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Value_Input.H>
#include <FL/Fl_Pack.H>

#include "./ControlPanel.h"

ControlPanel::ControlPanel(int y) {
  Fl_Pack* pack1 = new Fl_Pack(40,y,100,40);
  pack1->type(Fl_Pack::HORIZONTAL);
  pack1->spacing(10);
  selector_ = new SetSelector(0,0,160,0);
  scaleMin_ = new Fl_Value_Input(0,0,100,0,"Min Length");
  scaleMax_ = new Fl_Value_Input(0,0,100,0,"Max Length");
  scaleButton_ = new Fl_Button(0,0,80,0,"Set Scale");
  scaleMin_->align(FL_ALIGN_TOP);
  scaleMax_->align(FL_ALIGN_TOP);
  scaleMin_->textsize(18);
  scaleMax_->textsize(18);
  pack1->end();

  Fl_Pack* pack2 = new Fl_Pack(40,y+50,100,40);
  pack2->type(Fl_Pack::HORIZONTAL);
  pack2->spacing(10);
  Fl_Output* notesLabel = new Fl_Output(0,0,80,0);
  notesUp_ = new Fl_Button(0,0,30,0,"↑");
  notesDown_ = new Fl_Button(0,0,30,0,"↓");
  addUp_ = new Fl_Button(0,0,140,0,"Add higher string");
  addDown_ = new Fl_Button(0,0,140,0,"Add lower string");
  pack2->end();
  notesLabel->box(FL_NO_BOX);
  notesLabel->static_value("Shift Notes: ");
  notesLabel->set_output();
}

// Initialize the panel with a reference to the string view it manages
void ControlPanel::init(StringView* view) {
  selector_->init(view);

  addUp_->callback(addUp_cb,view);
  addDown_->callback(addDown_cb,view);
  notesUp_->callback(notesUp_cb,view);
  notesDown_->callback(notesDown_cb,view);

  ScaleLengthSet* scale = new ScaleLengthSet{scaleMin_,scaleMax_,view};
  scaleButton_->callback(setScale_cb,scale);
}

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

// Increments all notes up by one semitone
void notesUp_cb(Fl_Widget* w, void* v) {
  StringView* view = static_cast<StringView*>(v);
  view->incrementAll(1);
}

// Increments all notes down by one semitone
void notesDown_cb(Fl_Widget* w, void* v) {
  StringView* view = static_cast<StringView*>(v);
  view->incrementAll(-1);
}

// Sets the scale length of all strings
void setScale_cb(Fl_Widget* w, void* v) {
  ScaleLengthSet* set = static_cast<ScaleLengthSet*>(v);
  double min = set->min->value();
  double max = set->max->value();
  set->sv->setLengths(min,max);
}