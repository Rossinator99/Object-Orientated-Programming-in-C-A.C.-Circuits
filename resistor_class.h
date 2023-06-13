#ifndef RESISTOR_CLASS_H
#define RESISTOR_CLASS_H
#include "component_class.h"
#include <complex>
// Define the resistor_class as a derived class of component_class
class resistor_class : public component_class {
    // Resistance in Ohms
    double resistance;
public:
    // Declare public member functions
    std::string get_type() const override;
    char get_symbol() const override;
    // Constructor with resistance
    resistor_class(double r);
    // Overridden function for getting impedance
    std::complex<double> get_impedance(double frequency) const override;
};
#endif