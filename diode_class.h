#ifndef DIODE_CLASS_H
#define DIODE_CLASS_H
#include "component_class.h"
#include <complex>
#include <limits>
// Diode class is derived from component_class
class diode_class : public component_class {
    bool forward_biased;
public:
    std::string get_type() const override;
    char get_symbol() const override;
    diode_class(bool fb);
    std::complex<double> get_impedance(double frequency) const override;
};
#endif