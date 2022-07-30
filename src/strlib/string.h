#pragma once

#include "stringtype.h"

namespace strlib {
    class String {
    public:
        String(double length, int gauge, strlib::StringType type, int note, int octave);

        String(const String& string, bool higher);

        double getLength() const;
        void setLength(double length);

        int getGauge() const;
        void setGauge(int gauge);

        strlib::StringType getType() const;
        void setType(strlib::StringType type);

        double getNote() const;
        void setNote(int note);

        int getOctave() const;
        void setOctave(int octave);

        double getFrequency() const;
        
        double getTension() const;

        void incrementNote(int amount);

    private:
        double length_;
        int gauge_;
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