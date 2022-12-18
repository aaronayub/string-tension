#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Value_Input.H>
#include <FL/Fl_Pack.H>

#include "./ControlPanel.h"

ControlPanel::ControlPanel(int y) {
  // Create first row of controls
  Fl_Pack* pack1 = new Fl_Pack(40,y,100,40);
  pack1->type(Fl_Pack::HORIZONTAL);
  pack1->spacing(10);
  setSelector_ = new SetSelector(0,0,160,0);
  tuningSelector_ = new TuningSelector(0,0,160,0);
  scaleMin_ = new Fl_Value_Input(0,0,100,0,"Min Length");
  scaleMax_ = new Fl_Value_Input(0,0,100,0,"Max Length");
  scaleButton_ = new Fl_Button(0,0,80,0,"Set Scale");
  scaleMin_->align(FL_ALIGN_TOP);
  scaleMax_->align(FL_ALIGN_TOP);
  scaleMin_->textsize(18);
  scaleMax_->textsize(18);
  pack1->end();

  // Create second row of controls
  Fl_Pack* pack2 = new Fl_Pack(40,y+50,100,40);
  pack2->type(Fl_Pack::HORIZONTAL);
  pack2->spacing(10);
  Fl_Output* notesLabel = new Fl_Output(0,0,80,0);
  notesUp_ = new Fl_Button(0,0,30,0,"↑");
  notesDown_ = new Fl_Button(0,0,30,0,"↓");
  addUp_ = new Fl_Button(0,0,140,0,"Add higher string");
  addDown_ = new Fl_Button(0,0,140,0,"Add lower string");
  remove_ = new Fl_Button(0,0,120,0,"Remove string");
  pack2->end();
  notesLabel->box(FL_NO_BOX);
  notesLabel->static_value("Shift Notes: ");
  notesLabel->set_output();
}

void ControlPanel::init(StringView* view) {
  // Initialize the selectors, setting their callbacks and initial values
  setSelector_->init(view);
  tuningSelector_->init(setSelector_);

  // Set up callbacks for all buttons
  addUp_->callback(addUp_cb,view);
  addDown_->callback(addDown_cb,view);
  notesUp_->callback(notesUp_cb,view);
  notesDown_->callback(notesDown_cb,view);
  remove_->callback(remove_cb,view);

  // Set up callback and inputs for scale length settings
  ScaleLengthSet* scale = new ScaleLengthSet{scaleMin_,scaleMax_,view};
  scaleButton_->callback(setScale_cb,scale);
}

void addUp_cb(Fl_Widget* w, void* v) {
  StringView* view = static_cast<StringView*>(v);
  view->addString(true);
}

void addDown_cb(Fl_Widget* w, void* v) {
  StringView* view = static_cast<StringView*>(v);
  view->addString(false);
}

void notesUp_cb(Fl_Widget* w, void* v) {
  StringView* view = static_cast<StringView*>(v);
  view->incrementAll(1);
}

void notesDown_cb(Fl_Widget* w, void* v) {
  StringView* view = static_cast<StringView*>(v);
  view->incrementAll(-1);
}

void setScale_cb(Fl_Widget* w, void* v) {
  ScaleLengthSet* set = static_cast<ScaleLengthSet*>(v);
  double min = set->min->value();
  double max = set->max->value();
  set->sv->setLengths(min,max);
}

void remove_cb(Fl_Widget* w, void* v) {
  StringView* view = static_cast<StringView*>(v);
  view->removeString();
}