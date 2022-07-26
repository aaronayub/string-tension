/* The class for one string in the calculator */
#include "stringtype.h"
#include "notes.h"
#include "calcTension.h"
#include "stringweight.h"
#include "string.h"

namespace strlib {
    String::String(double length, double gauge, strlib::StringType type, int note, int octave) {
        length_ = length < 0 ? 0 : length;
        gauge_ = gauge < 0 ? 0 : gauge;
        type_ = type;
        note_ = note;
        octave_ = octave;

        updateNote();
        updateTension();
    }

    double String::getLength() { return length_; }
    void String::setLength(double length) {
        length_ = length < 0 ? 0 : length;
        updateTension();
    }

    double String::getGauge() { return gauge_; }
    void String::setGauge(double gauge) {
        gauge_ = gauge < 0 ? 0 : gauge;
        updateTension();
    }

    double String::getType() { return type_; }
    void String::setType(strlib::StringType type) {
        type_ = type;
        updateTension();
    }

    double String::getNote() { return note_; }
    void String::setNote(int note) {
        note_ = note;
        updateNote();
        updateTension();
    }

    double String::getOctave() { return octave_; }
    void String::setOctave(int octave) {
        octave_ = octave;
        updateNote();
        updateTension();
    }

    double String::getFrequency() { return frequency_; }
    double String::getTension() { return tension_; }

    // Increase the string's note by a specified amount.
    void String::incrementNote(int amount) {
        midiNote_+=amount;
        note_ = midiNote_ % 12;
        octave_ = midiNote_ / 12;
        frequency_ = strlib::noteToFrequency(midiNote_);
    }

    // Updates the tension of the string.
    void String::updateTension() {
        tension_ = strlib::calcTension(strlib::getUnitWeight(gauge_,type_),length_,frequency_);
    }

    // Updates the string's fundamental frequency
    void String::updateNote() {
        midiNote_ = note_ + ((octave_ + 1) * 12);
        frequency_ = strlib::noteToFrequency(midiNote_);
    }
}