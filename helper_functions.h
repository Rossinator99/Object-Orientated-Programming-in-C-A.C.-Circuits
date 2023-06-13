#ifndef HELPER_FUNCTIONS_H
#define HELPER_FUNCTIONS_H
#include <complex>
#include <iostream>
#include "circuit_class.h"
#include "component_class.h"
#include "circuit_functions.h"
// Helper function to display the impedance as a complex number
void print_complex_impedance(const std::complex<double>& impedance);
// Helper function to display the component information
void print_component_info(const component_class& comp, const std::string& component_name);
// Helper function to print the layout of the circuit
void print_circuit_layout(const circuit_class& circuit);
#endif