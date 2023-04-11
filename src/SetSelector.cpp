#include <FL/Enumerations.H>
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
    this->add("Super Light Guitar");
    this->add("Super Light Top Regular Bottom");
    this->add("Four String Bass");
    this->when(FL_WHEN_RELEASE_ALWAYS);
    this->label("Presets:");
    this->align(FL_ALIGN_TOP);
}

void SetSelector::init(StringView* view) {
    // Set up the callback with the StringView
    view_ = view;
    this->callback(applySet_cb,view_);

    // Apply the string set and tuning on startup
    this->value(0);
    this->setCurrentTuning(0);
    applySet_cb(this,view_);
}

int SetSelector::getCurrentTuning() { return currentTuning_; }
void SetSelector::setCurrentTuning(int tuning) { currentTuning_ = tuning; }

/** Tune the set by incrementing certain strings based on the tuning.*/
void SetSelector::tuneSet(std::vector<strlib::String*>& set, int tuning, bool isGuitar) {
    switch (tuning) {
        // Standard Tuning, do nothing.
        case 0:
            break;
        // Perfect Fourths, increment top two strings on guitar. Same as Standard on Bass.
        case 1:
            if (isGuitar && set.size() > 1) {
                set[0]->incrementNote(1);
                set[1]->incrementNote(1);
            }
            break;
        // Drop Tuning, decrement the lowest string by a whole tone.
        case 2:
            if (!set.empty()) {
                set.back()->incrementNote(-2);
            }
            break;
    }
}

void applySet_cb(Fl_Widget* w, void* v) {
    StringView* view = static_cast<StringView*>(v);
    SetSelector *selector = static_cast<SetSelector *>(w);

    // Listing of string sets; should be in the same order as the labels from the constructor.
    std::vector<strlib::String*> set {};
    bool isGuitar = false;

    switch (selector->value()) {
    // Six String Guitar
    case 0:
        set.push_back(new strlib::String{25.5,10.0,strlib::PL,strlib::notes::E, 4});
        set.push_back(new strlib::String{25.5,13.0,strlib::PL,strlib::notes::B, 3});
        set.push_back(new strlib::String{25.5,17.0,strlib::PL,strlib::notes::G, 3});
        set.push_back(new strlib::String{25.5,26.0,strlib::NW,strlib::notes::D, 3});
        set.push_back(new strlib::String{25.5,36.0,strlib::NW,strlib::notes::A, 2});
        set.push_back(new strlib::String{25.5,46.0,strlib::NW,strlib::notes::E, 2});
        isGuitar = true;
        break;
    // Super Light Guitar
    case 1:
        set.push_back(new strlib::String{25.5,9.0,strlib::PL,strlib::notes::E, 4});
        set.push_back(new strlib::String{25.5,11.0,strlib::PL,strlib::notes::B, 3});
        set.push_back(new strlib::String{25.5,16.0,strlib::PL,strlib::notes::G, 3});
        set.push_back(new strlib::String{25.5,24.0,strlib::NW,strlib::notes::D, 3});
        set.push_back(new strlib::String{25.5,32.0,strlib::NW,strlib::notes::A, 2});
        set.push_back(new strlib::String{25.5,42.0,strlib::NW,strlib::notes::E, 2});
        isGuitar = true;
        break;
    case 2:
        set.push_back(new strlib::String{25.5,9.0,strlib::PL,strlib::notes::E, 4});
        set.push_back(new strlib::String{25.5,11.0,strlib::PL,strlib::notes::B, 3});
        set.push_back(new strlib::String{25.5,16.0,strlib::PL,strlib::notes::G, 3});
        set.push_back(new strlib::String{25.5,26.0,strlib::NW,strlib::notes::D, 3});
        set.push_back(new strlib::String{25.5,36.0,strlib::NW,strlib::notes::A, 2});
        set.push_back(new strlib::String{25.5,46.0,strlib::NW,strlib::notes::E, 2});
        isGuitar = true;
        break;
    // Four String Bass
    case 3:
        set.push_back(new strlib::String{34,45.0,strlib::XLB,strlib::notes::G, 2});
        set.push_back(new strlib::String{34,65.0,strlib::XLB,strlib::notes::D, 2});
        set.push_back(new strlib::String{34,85.0,strlib::XLB,strlib::notes::A, 1});
        set.push_back(new strlib::String{34,105.0,strlib::XLB,strlib::notes::E, 1});
        break;
    }

    SetSelector::tuneSet(set,selector->getCurrentTuning(),isGuitar);
    view->applySet(set);
}