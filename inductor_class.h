#ifndef INDUCTOR_CLASS_H
#define INDUCTOR_CLASS_H
#include "component_class.h"
#include <complex>
// Inductor class is derived from component_class
class inductor_class : public component_class {
    // Inductance in Henrys
    double inductance;
public:
    std::string get_type() const override;
    char get_symbol() const override;
    inductor_class(double l);
    std::complex<double> get_impedance(double frequency) const override;
};
#endif