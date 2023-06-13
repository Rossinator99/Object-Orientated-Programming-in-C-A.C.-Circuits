#ifndef COMPONENT_CLASS_H
#define COMPONENT_CLASS_H

#include <complex>
#include <cmath>
#include <iostream>
#include <vector>
#include <memory>
#include <stdexcept>
#include <map>
#include <limits>
#include <functional>
// Constant value for pi
const double pi = 3.14159265358979323846;
class component_class {
protected:
    // Frequency in Hz
    double frequency;
public:
    // Pure virtual functions for getting component type and symbol
    virtual std::string get_type() const = 0;
    virtual char get_symbol() const = 0;
    // Constructor with frequency (default is 0.0 Hz)
    component_class(double freq = 0.0);
    // Set and get frequency
    virtual void set_frequency(double freq);
    virtual double get_frequency() const;
    // Pure virtual function for getting impedance
    virtual std::complex<double> get_impedance(double frequency) const = 0;
    virtual double get_magnitude_impedance(double frequency) const;
    virtual double get_phase_difference(double frequency) const;
    // Virtual destructor
    virtual ~component_class();
};
#endif