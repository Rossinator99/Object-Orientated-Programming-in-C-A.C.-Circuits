#include "component_class.h"
// This is the implementation of the base class component_class that all components inherit from.
component_class::component_class(double freq) : frequency(freq) {}
// Constructor with a frequency parameter that sets the frequency of the component.
void component_class::set_frequency(double freq) {
    frequency = freq;
}
double component_class::get_frequency() const {
    return frequency;
}
// Functions that returns the magnitude of the impedance and phase difference at a specified frequency.
double component_class::get_magnitude_impedance(double frequency) const {
    return std::abs(get_impedance(frequency));
}
double component_class::get_phase_difference(double frequency) const {
    return std::arg(get_impedance(frequency));
}
// Virtual destructor for the component class.
component_class::~component_class() {}