#ifndef TRANSISTOR_CLASS_H
#define TRANSISTOR_CLASS_H
#include "component_class.h"
#include <complex>
// Declaration of vbe
extern const double vbe;  
// Transistor class is derived from component_class
class transistor_class : public component_class {
    // Gain in hFE
    double gain;
    // Base current in amps
    double base_current;
public:
    std::string get_type() const override;
    char get_symbol() const override;
    transistor_class(double g, double ib);
    std::complex<double> get_impedance(double frequency) const override;
};
#endif