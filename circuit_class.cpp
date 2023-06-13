#include "circuit_class.h"
#include "helper_functions.h"
#include <vector>
#include <map>
#include <memory>
// Destructor for the circuit_class
circuit_class::~circuit_class() {}
// Constructor of the circuit class.
circuit_class::circuit_class(const std::string& name, connection type)
    : connection_type(type), circuit_name(name), frequency(0.0), voltage(0.0) {}
// Overridden get_type function that returns the string "Circuit".
std::string circuit_class::get_type() const {
    return "Circuit";
}
// Returns the number of components in the circuit.
size_t circuit_class::get_components_size() const {
    return components.size();
}
// Function that adds component to the circuit.
void circuit_class::add_component(std::shared_ptr<component_class> comp, const std::string& circuit_name) {
    std::string type = comp->get_type();
    // Increment count for this type of component
    int count = ++component_counts[type];
    std::string name;
    if (!circuit_name.empty()) {
        name = circuit_name + " -> " + type + " " + std::to_string(count);
    }
    else {
        name = type + " " + std::to_string(count);
    }
    components.push_back({ comp, name });
}
// Prints the information of all components in the circuit_class.
void circuit_class::print_all_components_information() const {
    ::print_component_info(*this, this->circuit_name);
    for (const auto& pair : components) {
        if (auto sub_circuit = dynamic_cast<const circuit_class*>(pair.first.get())) {
            sub_circuit->print_all_components_information();
        }
        else {
            ::print_component_info(*pair.first, pair.second);
        }
    }
}
// Returns a string representing the layout of the circuit.
std::string circuit_class::get_layout() const {
    std::stringstream ss;
    // If the connection type of the circuit is series
    if (connection_type == series) {
        ss << "[ ";
        for (const auto& comp : components) {
            if (dynamic_cast<const circuit_class*>(comp.first.get()) != nullptr) {
                ss << dynamic_cast<const circuit_class*>(comp.first.get())->get_layout();
            }
            else {
                ss << comp.first->get_symbol();
            }
            ss << " -> ";
        }
        std::string layout = ss.str();
        if (!layout.empty()) layout = layout.substr(0, layout.size() - 4);
        ss.str("");
        ss << layout << " ]";
    }
    // If the connection type of the circuit is parallel
    else {
        ss << "[ ";
        for (const auto& comp : components) {
            if (dynamic_cast<const circuit_class*>(comp.first.get()) != nullptr) {
                ss << dynamic_cast<const circuit_class*>(comp.first.get())->get_layout();
            }
            else {
                ss << comp.first->get_symbol();
            }
            ss << " || ";
        }
        std::string layout = ss.str();
        if (!layout.empty()) layout = layout.substr(0, layout.size() - 4);
        ss.str("");
        ss << layout << " ]";
    }
    return ss.str();
}
char circuit_class::get_symbol() const {
    return 'X';
}
void circuit_class::set_frequency(double freq) {
    frequency = freq;
    for (auto& comp : components) {
        comp.first->set_frequency(freq);
    }
}
double circuit_class::get_frequency() const {
    return frequency;
}
// Calculates impedance for parallel and series circuits
std::complex<double> circuit_class::get_impedance(double frequency) const {
    std::complex<double> total(0.0, 0.0);
    if (connection_type == parallel) {
        for (const auto& comp : components) {
            std::complex<double> comp_impedance = comp.first->get_impedance(frequency);
            if (comp_impedance == std::complex<double>(0.0, 0.0)) {
                throw std::invalid_argument("Division by zero error; Component impededance is zero");
            }
            total += 1.0 / comp_impedance;
        }
        total = 1.0 / total;
    }
    else {
        for (const auto& comp : components) {
            total += comp.first->get_impedance(frequency);
        }
    }
    return total;
}

// Returns the magnitude of the impedance at a specific frequency.
double circuit_class::get_magnitude_impedance(double frequency) const {
    return std::abs(get_impedance(frequency));
}
// Returns the magnitude of the impedance at a specific frequency.
double circuit_class::get_phase_difference(double frequency) const {
    return std::arg(get_impedance(frequency));
}
// Gets and sets the voltage
double circuit_class::get_voltage() const {
    return voltage;
}
void circuit_class::set_voltage(double volt) {
    voltage = volt;
}
// Calculates and returns the current through the circuit using Ohm's law.
double circuit_class::calculate_current() const {
    std::complex<double> impedance = get_impedance(frequency);
    double magnitude = std::abs(impedance);
    return voltage / magnitude; // Ohm's law
}
// Function removes nested circuit.
void circuit_class::remove_component(std::shared_ptr<component_class> component) {
    for (auto it = components.begin(); it != components.end(); ++it) {
        if (it->first == component) {
            components.erase(it);
            break;
        }
    }
}