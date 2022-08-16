/** @file
 * @brief The StringDisplay pack widget */
#pragma once

#include <FL/Fl.H>
#include <FL/Fl_Value_Input.H>
#include <FL/Fl_Value_Output.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Pack.H>

#include "./strlib/string.h"

/** @brief Holds information on one string, which is displayed in a row. */
class StringDisplay : public Fl_Pack {
  public:
    /** Creates a new StringDisplay based on the provided string */
    StringDisplay(strlib::String* string);

    /** Safely deletes the widget and the associated string */
    void remove();
    
    /** @return A pointer to the string associated with this StringDisplay */
    strlib::String* getStringPtr();

    /** Re-calculates the frequency of the string, and updates the display */
    void updateFrequency();

    /** Re-calculates the tension of the string, and updates the display */
    void updateTension();

    /** Shifts the note of the string by the specified amount
     * @param increment The number of semitones to tune the string up or down
     */
    void incrementNote(int increment);

    /** Sets the scale-length of the string
     * @param length The scale-length of the string in inches
     */
    void setLength(double length);

  private:
    Fl_Value_Input *length_;
    Fl_Value_Input *gauge_;
    Fl_Value_Input *octave_;
    Fl_Choice *note_;
    Fl_Choice *type_;
    Fl_Value_Output *frequency_;
    Fl_Value_Output *tension_;

    strlib::String* string_;

    /** Callback to update the string type
     * @param w The string type choice widget
     * @param v The StringDisplay
     */
    static void type_cb(Fl_Widget* w, void* v);

    /** Callback to update the note of the string
     * @param w The note choice widget
     * @param v The StringDisplay
     */
    static void note_cb(Fl_Widget* w, void* v);

    /** Callback to update the string's scale length
     * @param w The scale length value input
     * @param v The StringDisplay
     */
    static void length_cb(Fl_Widget* w, void* v);

    /** Callback to update the string gauge
     * @param w The gauge value input
     * @param v The StringDisplay
     */
    static void gauge_cb(Fl_Widget* w, void* v);

    /** Callback to update the octave
     * @param w The octave value input
     * @param v The StringDisplay
     */
    static void octave_cb(Fl_Widget* w, void* v);
};