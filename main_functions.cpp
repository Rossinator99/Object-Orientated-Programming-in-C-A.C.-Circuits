#include "command.h"
#include "circuit_class.h"
#include "capacitor_class.h"
#include "diode_class.h"
#include "component_class.h"
#include "create_component.h"
#include "circuit_functions.h"
#include "input_validation.h"
#include "helper_functions.h"
#include "inductor_class.h"
#include "transistor_class.h"
#include "resistor_class.h"
#include <functional>
#include <map>
#include <string>
#include <iostream>
#include <stdexcept>
#include <memory>
int main() {
    try {
        std::shared_ptr<circuit_class> current_circuit;
        // Set the frequency for the entire circuit
        double frequency, voltage;
        std::cout << "Enter the frequency (Hz): ";
        frequency = get_valid_double();
        std::cout << "Enter the voltage (V): ";
        voltage = get_valid_double();
        auto circuit = create_circuit();
        circuit->set_frequency(frequency);
        circuit->set_voltage(voltage);
        circuits.insert({ "Main Circuit", circuit });
        current_circuit = circuit;
        // Print component information
        std::cout << "============================================\n";
        std::cout << "           Circuit Analysis                 \n";
        std::cout << "============================================\n";
        display_circuit(circuit);
        while (true) {
            std::cout << "Enter command (setfreq, setvolt, display, newcircuit, editcircuit, removecircuit, help, exit): ";
            switch (get_command()) {
            case SetFreq: {
                double new_frequency;
                std::cout << "Enter new frequency: ";
                new_frequency = get_valid_double();
                circuit->set_frequency(new_frequency);
                break;
            }
            case SetVolt: {
                double new_voltage;
                std::cout << "Enter new voltage: ";
                new_voltage = get_valid_double();
                circuit->set_voltage(new_voltage);
                break;
            }
            case Display: {
                display_circuit(circuit);
                break;
            }
            case NewCircuit: {
                std::cout << "Creating a new circuit...\n";
                circuit = create_circuit(circuit_class::series, "Main Circuit", nullptr, true);
                current_circuit = circuit;
                double new_frequency, new_voltage;
                std::cout << "Enter the frequency for the new circuit (Hz): ";
                new_frequency = get_valid_double();
                circuit->set_frequency(new_frequency);
                std::cout << "Enter the voltage for the new circuit (V): ";
                new_voltage = get_valid_double();
                circuit->set_voltage(new_voltage);
                break;
            }
            case EditCircuit: {
                std::cout << "Enter the name of the circuit you want to edit: ";
                std::string circuit_name;
                std::cin.ignore();
                std::getline(std::cin, circuit_name);
                if (circuits.find(circuit_name) == circuits.end()) {
                    std::cout << "Circuit not found. Please try again.\n";
                }
                else {
                    std::shared_ptr<circuit_class> edit_circuit = circuits[circuit_name];
                    double edit_circuit_frequency = edit_circuit->get_frequency();
                    create_circuit(edit_circuit->connection_type, circuit_name, edit_circuit, false, edit_circuit_frequency);
                    current_circuit = edit_circuit;
                }
                break;
            }
            case RemoveCircuit: {
                std::cout << "Enter the name of the circuit you want to remove: ";
                std::string circuit_name;
                std::cin.ignore();
                std::getline(std::cin, circuit_name);

                if (circuit_name == "Main Circuit") {
                    std::cout << "You cannot remove the Main Circuit.\n";
                }
                else {
                    auto it = circuits.find(circuit_name);
                    if (it == circuits.end()) {
                        std::cout << "Circuit not found. Please try again.\n";
                    }
                    else {
                        // Function to recursively remove a circuit and its children
                        std::function<void(const std::string&)> remove_circuit_and_children;

                        remove_circuit_and_children = [&](const std::string& name) {
                            auto parent_it = circuit_parents.find(name);
                            if (parent_it != circuit_parents.end()) {
                                circuits[parent_it->second]->remove_component(circuits[name]);
                                circuit_parents.erase(parent_it);
                            }
                            std::vector<std::string> children;
                            for (const auto& pair : circuit_parents) {
                                if (pair.second == name) {
                                    children.push_back(pair.first);
                                }
                            }
                            for (const auto& child : children) {
                                remove_circuit_and_children(child);
                            }
                            circuits.erase(name);
                        };
                        // Use the function to remove the selected circuit and its children
                        remove_circuit_and_children(circuit_name);
                        std::cout << "Circuit " << circuit_name << " and all its nested circuits have been removed.\n";
                    }
                }
                break;
            }
            // Details about available commands
            case Help: {
                std::cout << "Available commands:\n";
                std::cout << "  setfreq: Change the frequency of the current circuit\n";
                std::cout << "  setvolt: Change the voltage of the current circuit\n";
                std::cout << "  display: Displays the current, impedence, phase difference of the current circuit and its components\n";
                std::cout << "  newcircuit: Creates a new circuit\n";
                std::cout << "  editcircuit: Edits an existing nested circuit\n";
                std::cout << "  removecircuit: Removes an existing nested circuit\n";
                std::cout << "  exit: Exits the program\n";
                break;
            }
            case Exit: {
                return 0;
            }
            case Invalid: default: {
                std::cout << "Invalid command. Please try again.\n";
                break;
            }
            }
        }
    }
    // Catch blocks to catch exceptions
    catch (const std::invalid_argument& e) {
        std::cerr << "Caught an invalid_argument exception: " << e.what() << '\n';
    }
    catch (const std::exception& e) {
        std::cerr << "Caught a general exception: " << e.what() << '\n';
    }
    catch (...) {
        std::cerr << "Caught an unknown exception\n";
    }
    return 0;
}