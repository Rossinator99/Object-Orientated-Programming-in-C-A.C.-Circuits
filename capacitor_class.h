#ifndef CAPACITOR_CLASS_H
#define CAPACITOR_CLASS_H
#include "component_class.h"
#include <complex>
class capacitor_class : public component_class {
    // Capacitance in farads
    double capacitance;
public:
    std::string get_type() const override;
    char get_symbol() const override;
    capacitor_class(double c);
    std::complex<double> get_impedance(double frequency) const override;
};
#endif