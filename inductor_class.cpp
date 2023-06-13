#include "inductor_class.h"
#include <cmath>
// Implementation of the inductor_class member functions
std::string inductor_class::get_type() const {
    return "Inductance";
}
// Returns the symbol used to represent the component
char inductor_class::get_symbol() const {
    return 'I';
}
inductor_class::inductor_class(double l) : inductance(l) {}
// Returns the impedance of the inductor at the specified frequency
std::complex<double> inductor_class::get_impedance(double frequency) const {
    double imag = 2 * pi * frequency * inductance;
    // Return a complex number with the imaginary part as the impedance and the real part as 0
    return std::complex<double>(0.0, imag);
}