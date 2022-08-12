/* An Fl_Scroll holding a list of strings */
#pragma once

#include <FL/Fl.H>
#include <FL/Fl_Pack.H>
#include <FL/Fl_Scroll.H>
#include <deque>
#include <vector>

#include "./strlib/string.h"

#include "./stringDisplay.h"
class StringView : public Fl_Scroll {
    public:
        StringView(int x, int y, int w, int h, const char *label = 0);
        void applySet(std::vector<strlib::String*>& set);
        void addString(bool higher);
        void incrementAll(int increment);
        void setLengths(double min, double max);

    private:
        std::deque<StringDisplay*> list_;
        Fl_Pack* pack;
};