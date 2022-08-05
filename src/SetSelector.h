/* A choice widget which applies predefined string sets to a StringView */
#pragma once

#include <FL/Fl.H>
#include <FL/Fl_Choice.H>

#include "./StringView.h"

class SetSelector : public Fl_Choice {
    public:
        SetSelector(int x, int y, int w, int h, const char* label = 0);
        void init(StringView* view);
    private:
        StringView* view_;
};

static void applySet_cb(Fl_Widget* w, void* v);