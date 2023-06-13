#include "transistor_class.h"
// Implementation of the transistor_class member functions
// Base-emitter voltage assumed to be 0.7V assuming a small signal model
const double vbe = 0.7;
// Returns the type of the component as a string
std::string transistor_class::get_type() const {
    return "Transistor";
}
// Returns the symbol used to represent the component
char transistor_class::get_symbol() const {
    return 'T';
}
// Constructor for the transistor_class
transistor_class::transistor_class(double g, double ib) : gain(g), base_current(ib) {}
// Returns the impedance of the transistor at the specified frequency
std::complex<double> transistor_class::get_impedance(double frequency) const {
    double collector_current = gain * base_current;
    double effective_resistance = vbe / collector_current;
    // Returns the effective resistance as the impedance (imaginary part is 0 as transistors 
    // are considered to not have a reactive component)
    return std::complex<double>(effective_resistance, 0.0);
}