#include "capacitor_class.h"
#include <cmath>
// Implementation of the capacitor_class member functions
// Returns the type of the component as a string
std::string capacitor_class::get_type() const {
    return "Capacitor";
}
char capacitor_class::get_symbol() const {
    return 'C';
}
capacitor_class::capacitor_class(double c) : capacitance(c) {}
// Returns the impedance of the capacitor at the specified frequency
std::complex<double> capacitor_class::get_impedance(double frequency) const {
    double imag = -1 / (2 * pi * frequency * capacitance);
    // Return a complex number with 0 as the real part and the calculated imaginary part as the impedance
    return std::complex<double>(0.0, imag);
}