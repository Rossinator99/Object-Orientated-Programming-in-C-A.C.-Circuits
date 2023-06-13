#ifndef CIRCUIT_FUNCTIONS_H
#define CIRCUIT_FUNCTIONS_H
#include <map>
#include <memory>
#include <string>
#include "circuit_class.h"
// Map to store all circuits
extern std::map<std::string, std::shared_ptr<circuit_class>> circuits;
// Map to store the parent of each circuit
extern std::map<std::string, std::string> circuit_parents;
// Function to create a new circuit
std::shared_ptr<circuit_class> create_circuit(circuit_class::connection type = circuit_class::series,
    const std::string& parent_circuit_name = "Main Circuit", std::shared_ptr<circuit_class> existing_circuit = nullptr,
    bool clear_existing_circuits = false, double parent_frequency = 0.0);
#endif // CIRCUIT_FUNCTIONS_H