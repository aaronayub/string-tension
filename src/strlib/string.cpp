#include <cmath>
#include "stringtype.h"
#include "notes.h"
#include "calcTension.h"
#include "stringweight.h"
#include "string.h"

namespace strlib {
    String::String(double length, int gauge, strlib::StringType type, int note, int octave) {
        /** Copy arguments into member variables */
        length_ = length < 0 ? 0 : length;
        gauge_ = gauge < 0 ? 0 : gauge;
        type_ = type;
        note_ = note;
        octave_ = octave;

        /** Calculate the MIDI note, frequency, and tension */
        updateNote();
        updateTension();
    }

    String::String(const String& string, bool higher) {
        /** Copy properties from reference string to the new string */
        length_ = string.getLength();
        gauge_= string.getGauge();
        type_ = string.getType();
        midiNote_ = (string.getOctave() + 1) * 12 + string.getNote();
        incrementNote(higher ? 5 : -5);

        // Calculate an appropriate gauge and string type for the new note.
        if (higher) {
            gauge_ = round(gauge_ * 0.758);
            // Convert sufficiently small wound strings to plain strings
            if (type_ == strlib::NW && gauge_ < 20) {
                type_ = strlib::PL;
            }
        } else {
            gauge_ = round(gauge_ * 1.32);
            // Convert sufficiently large plain strings to wound strings
            if (type_ == strlib::PL && gauge_ > 19) {
                type_ = strlib::NW;
            }
        }

        // Round sufficiently large bass strings up within 0.005 gauge
        if (type_ == strlib::XLB && gauge_ > 50) {
            gauge_+= gauge_ % 5;
        }

        updateTension();
    }

    double String::getLength() const { return length_; }
    void String::setLength(double length) {
        length_ = length < 0 ? 0 : length;
        updateTension();
    }

    int String::getGauge() const { return gauge_; }
    void String::setGauge(int gauge) {
        gauge_ = gauge < 0 ? 0 : gauge;
        updateTension();
    }

    strlib::StringType String::getType() const { return type_; }
    void String::setType(strlib::StringType type) {
        type_ = type;
        updateTension();
    }

    double String::getNote() const { return note_; }
    void String::setNote(int note) {
        note_ = note;
        updateNote();
        updateTension();
    }

    int String::getOctave() const { return octave_; }
    void String::setOctave(int octave) {
        octave_ = octave;
        updateNote();
        updateTension();
    }

    double String::getFrequency() const { return frequency_; }
    
    double String::getTension() const { return tension_; }

    void String::incrementNote(int amount) {
        midiNote_+=amount;
        note_ = midiNote_ % 12;
        octave_ = (midiNote_ / 12) - 1;
        frequency_ = strlib::noteToFrequency(midiNote_);
        updateTension();
    }

    void String::updateTension() {
        tension_ = strlib::calcTension(strlib::getUnitWeight(gauge_,type_),length_,frequency_);
    }

    void String::updateNote() {
        midiNote_ = note_ + ((octave_ + 1) * 12);
        frequency_ = strlib::noteToFrequency(midiNote_);
    }
}