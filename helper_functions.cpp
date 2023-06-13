#include "helper_functions.h"
#include <iomanip>
// Helper function to display the impedance as a complex number
void print_complex_impedance(const std::complex<double>& impedance) {
    std::cout << impedance.real() << " + " << impedance.imag() << "j";
}
// Helper function to display the component information
void print_component_info(const component_class& comp, const std::string& component_name) {
    double frequency = comp.get_frequency();
    std::cout << component_name << ":\n";
    // setprecision(3) limits the output to 3 significant figures
    std::cout << "  Frequency: " << std::setprecision(3) << frequency << " Hz\n";
    std::cout << "  Impedance: ";
    print_complex_impedance(comp.get_impedance(frequency));
    std::cout << " ohms\n";
    std::cout << "  Magnitude of impedance: " << std::setprecision(3) << comp.get_magnitude_impedance(frequency) << " ohms\n";
    std::cout << "  Phase difference: " << std::setprecision(3) << comp.get_phase_difference(frequency) << " radians\n";
}
// Helper function to print the layout of the circuit
void print_circuit_layout(const circuit_class& circuit) {
    std::cout << "Circuit layout: " << circuit.get_layout() << '\n';
}