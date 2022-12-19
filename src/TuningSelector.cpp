#include <FL/Fl.H>
#include <FL/Fl_Choice.H>

#include "./TuningSelector.h"
#include "SetSelector.h"
#include "StringView.h"

TuningSelector::TuningSelector(int x, int y, int w, int h, const char* label): Fl_Choice(x,y,w,h,0) {
    this->add("Standard Tuning");
    this->add("Perfect Fourths");
    this->add("Drop Tuning");
    this->when(FL_WHEN_CHANGED);
    this->label("Preset Tuning:");
    this->align(FL_ALIGN_TOP);
}

void TuningSelector::init(SetSelector* setSelector) {
    this->value(0);
    this->callback(tuningSelector_cb,setSelector);
}

/** Update the tuning on the setSelector, and then trigger the setSelector's callback. */
static void tuningSelector_cb(Fl_Widget* w, void* v) {
    SetSelector* setSelector = static_cast<SetSelector*>(v);
    TuningSelector* tuningSelector = static_cast<TuningSelector*>(w);
    setSelector->setCurrentTuning(tuningSelector->value());
    setSelector->do_callback();
}