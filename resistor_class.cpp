#include "resistor_class.h"
// Implementation of the resistor_class member functions
// Returns the type of the component as a string
std::string resistor_class::get_type() const {
    return "Resistor";
}// Returns the symbol used to represent the component
char resistor_class::get_symbol() const {
    return 'R';
}
// Constructor for the resistor_class
resistor_class::resistor_class(double r) : resistance(r) {}
// Returns the impedance of the resistor at the specified frequency
std::complex<double> resistor_class::get_impedance(double frequency) const {
    return std::complex<double>(resistance, 0.0);
}