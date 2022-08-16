/**
 * @file
 * @brief Manages the properties of a guitar or bass string
 */
#pragma once

#include "stringtype.h"

namespace strlib {
    class String {
    public:
        /**
         * Constructs a string by providing all of its properties.
         * @param length Length of the string in inches
         * @param gauge Diameter of the string in thousandths of an inch
         * @param type Type of string construction and material
         * @param note Note of the string in 12TET
         * @param octave Octave of the note
         */
        String(double length, int gauge, strlib::StringType type, int note, int octave);

        /**
         * Constructs a string above or below another string.
         * The new string's properties are extrapolated from the provided string.
         * @param string The string to use as a reference for the constructor
         * @param higher If true, the new string is tuned 5 semitones higher than the reference string. Otherwise, it is 5 semitones lower.
         */
        String(const String& string, bool higher);

        /** @return Length of the string in inches */
        double getLength() const;
        /**
         * Sets the length of the string
         * @param length Length of the string in inches
         */
        void setLength(double length);

        /** @return Diameter of the string in thousandths of an inch */
        int getGauge() const;

        /**
         * Sets the gauge of the string
         * @param gauge Diameter of the string in thousandths of an inch
         */
        void setGauge(int gauge);

        /** @return Type of string construction and material */
        strlib::StringType getType() const;
        /**
         * Sets the type of the string
         * @param type Type of string construction and material
         */
        void setType(strlib::StringType type);

        /** @return The note of the string */
        double getNote() const;

        /**
         * Sets the note of the string
         * @param note Note of the string in 12TET
         */
        void setNote(int note);

        /** @return The octave of the string */
        int getOctave() const;

        /**
         * Sets the octave of the string
         * @param octave Octave of the string
         */
        void setOctave(int octave);

        /** @return Frequency of the string in Hz */
        double getFrequency() const;
        /** @return Tension of the string in pounds */
        double getTension() const;

        /**
         * Shifts the note of the string by a specified amount
         * @param amount Number of semitones to tune the string up.
         */
        void incrementNote(int amount);

    private:
        double length_; /** Length of the string in inches */
        int gauge_; /** Diameter of the string in thousandths of an inch */
        strlib::StringType type_; /** Type of string construction and material */
        int note_; /** Note of the string, where C is index 0, and B is index 11. */
        int octave_; /** Octave of the note */
        int midiNote_; /** MIDI value of the note and octave*/
        double unitWeight_; /** Unit weight of the string in lbs/in */
        double tension_; /** Tension of the string in pounds */
        double frequency_; /** Frequency of the string in Hz */
        
        /** Recalculates the tension of the string */
        void updateTension();
        
        /** Recalculates the MIDI note and frequency of the string */
        void updateNote();
    };
}