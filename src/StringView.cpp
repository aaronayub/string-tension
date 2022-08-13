#include <FL/Fl.H>
#include <FL/Fl_Pack.H>
#include <FL/Fl_Scroll.H>

#include "./StringView.h"
#include "./stringDisplay.h"
#include "./strlib/notes.h"

StringView::StringView(int x, int y, int w, int h, const char *label) : Fl_Scroll(x, y, w, h, label) {
    list_ = {};
    pack = new Fl_Pack(x,y,w - 20,h);
    pack->spacing(10);
    pack->end();
    this->end();
    this->add(pack);
}

// Replaces the current set of strings with a new one
void StringView::applySet(std::vector<strlib::String*>& set) {
    for (StringDisplay* d : list_) {
        d->remove();
    }
    list_.clear();
    for (int i = 0; i < set.size(); i++) {
        StringDisplay* d = new StringDisplay(set[i]);
        list_.push_back(d);
        pack->add(d);
    }
}

// Changes the note of all strings by a specified amount
void StringView::incrementAll(int increment) {
  for (StringDisplay* d : list_) {
    d->incrementNote(increment);
  }
}

// Updates the scale length of all strings.
void StringView::setLengths(double min, double max) {
  // The maximum scale length cannot be lower than the minimum
  if (max < min) {
    max = min;
  };

  for (int i = 0; i < list_.size(); i++) {
    double length = min + (max - min) * ((double)i / (list_.size() - 1));
    list_.at(i)->setLength(length);
  }
}

// Adds a string to the top or bottom of the view
void StringView::addString(bool higher) {
  // Create a string by default if the list is empty
  if (list_.empty()) {
    strlib::String* newStr = new strlib::String(25.5,10,strlib::PL,strlib::notes::E,4);
    StringDisplay* d = new StringDisplay(newStr);
    pack->add(d);
    list_.push_back(d);
  }
  else {
    StringDisplay* d;
    if (higher) { // Adding a higher string
      strlib::String* newStr = new strlib::String(*(list_.front()->getStringPtr()),true);
      d = new StringDisplay(newStr);
      list_.push_front(d);
    }
    else { // Adding a lower string
      strlib::String* newStr = new strlib::String(*(list_.back()->getStringPtr()),false);
      d = new StringDisplay(newStr);
      list_.push_back(d);
    }

    // Re-add all elements to reorder them.
    for (int i = 0; i < list_.size(); i++) {
      pack->add(list_[i]);
    }
  }
  this->parent()->redraw();
}

// Removes the lowest string from the set
void StringView::removeString() {
  if (list_.empty()) return;

  pack->remove(list_.back());
  list_.pop_back();
  this->redraw();
}