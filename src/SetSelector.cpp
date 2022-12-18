#include <FL/Fl.H>
#include <FL/Fl_Choice.H>
#include <vector>

#include "./strlib/string.h"
#include "./strlib/stringtype.h"
#include "./strlib/notes.h"

#include "./StringView.h"
#include "./SetSelector.h"

SetSelector::SetSelector(int x, int y, int w, int h, const char* label): Fl_Choice (x,y,w,h,0) {
    this->add("Six String Guitar");
    this->add("Four String Bass");
    this->when(FL_WHEN_CHANGED);
    this->label("Presets:");
    this->align(FL_ALIGN_TOP);
}

void SetSelector::init(StringView* view) {
    // Set up the callback with the StringView
    view_ = view;
    this->callback(applySet_cb,view_);

    // Apply the string set on startup
    this->value(0);
    applySet_cb(this,view_);
}

void applySet_cb(Fl_Widget* w, void* v) {
    StringView* view = static_cast<StringView*>(v);
    SetSelector* selector = static_cast<SetSelector*>(w);

    // Listing of string sets; should be in the same order as the labels from the constructor.
    std::vector<strlib::String*> set {};
    switch (selector->value()) {
    // Six String Guitar
    case 0:
        set.push_back(new strlib::String{25.5,10.0,strlib::PL,strlib::notes::E, 4});
        set.push_back(new strlib::String{25.5,13.0,strlib::PL,strlib::notes::B, 3});
        set.push_back(new strlib::String{25.5,17.0,strlib::PL,strlib::notes::G, 3});
        set.push_back(new strlib::String{25.5,26.0,strlib::NW,strlib::notes::D, 3});
        set.push_back(new strlib::String{25.5,36.0,strlib::NW,strlib::notes::A, 2});
        set.push_back(new strlib::String{25.5,46.0,strlib::NW,strlib::notes::E, 2});
        break;
    // Four String Bass
    case 1:
        set.push_back(new strlib::String{34,45.0,strlib::XLB,strlib::notes::G, 2});
        set.push_back(new strlib::String{34,65.0,strlib::XLB,strlib::notes::D, 2});
        set.push_back(new strlib::String{34,85.0,strlib::XLB,strlib::notes::A, 1});
        set.push_back(new strlib::String{34,105.0,strlib::XLB,strlib::notes::E, 1});
        break;
    }

    view->applySet(set);

    // Reset the set value, so a user can repeatedly select the same set
    selector->value(-1);
}