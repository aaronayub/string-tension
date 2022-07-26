#pragma once

#include "stringtype.h"

namespace strlib {
    class String {
    public:
        String(double length, double gauge, strlib::StringType type, int note, int octave);

        double getLength();
        void setLength(double length);

        double getGauge();
        void setGauge(double gauge);

        double getType();
        void setType(strlib::StringType type);

        double getNote();
        void setNote(int note);

        double getOctave();
        void setOctave(int octave);

        double getFrequency();
        
        double getTension();

        void incrementNote(int amount);

    private:
        double length_;
        double gauge_;
        strlib::StringType type_;
        int note_; // Where 0 is a C note, and 11 is a B. See strlib::NOTES.
        int octave_;
        int midiNote_;
        double unitWeight_;
        double tension_;
        double frequency_;
        
        void updateTension();
        void updateNote();
    };
}