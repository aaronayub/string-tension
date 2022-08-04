#include <FL/Fl.H>
#include <FL/Fl_Group.H>

#include "./StringView.h"
#include "./stringDisplay.h"

StringView::StringView(int x, int y, int w, int h, const char *label) : Fl_Group(x, y, w, h, label) {
    list_ = {};
}

void StringView::applySet(std::vector<strlib::String*>& set) {
    for (StringDisplay* d : list_) {
        d->remove();
    }
    list_.clear();
    for (int i = 0; i < set.size(); i++) {
        StringDisplay* d = new StringDisplay(set[i],i);
        list_.push_back(d);
        this->add(d);
    }
}

// Adds a string to the top or bottom of the view
void StringView::addString(bool higher) {
  // Create a string by default if the list is empty
  if (list_.empty()) {
    strlib::String* newStr = new strlib::String(25.5,10,strlib::PL,strlib::notes::E,4);
    StringDisplay* d = new StringDisplay(newStr, 0);
    this->add(d);
    list_.push_back(d);
  }
  else {
    StringDisplay* d;
    if (higher) { // Adding a higher string
    strlib::String* oldStr = list_.front()->getStringPtr();
      strlib::String* newStr = new strlib::String(*(list_.front()->getStringPtr()),true);
      d = new StringDisplay(newStr, 0);
      list_.push_front(d);
    }
    else { // Adding a lower string
      strlib::String* newStr = new strlib::String(*(list_.back()->getStringPtr()),false);
      d = new StringDisplay(newStr, list_.size());
      list_.push_back(d);
    }

    this->add(d);
    for (int i = 0; i < list_.size(); i++) {
      list_[i]->reposition(i);
    }
  }
  this->parent()->redraw();
}