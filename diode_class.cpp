#include "diode_class.h"
std::string diode_class::get_type() const {
    return "Diode";
}
char diode_class::get_symbol() const {
    return 'D';
}
diode_class::diode_class(bool fb) : forward_biased(fb) {}
std::complex<double> diode_class::get_impedance(double frequency) const {
    // If the diode is forward biased, its impedance is 0. 
    // If it's reverse biased, it's considered as an open circuit (impedance is infinity).
    return forward_biased ? std::complex<double>(0.0, 0.0) :
        std::complex<double>(std::numeric_limits<double>::infinity(), 0.0);
}