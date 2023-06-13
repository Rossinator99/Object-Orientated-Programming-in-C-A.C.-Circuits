#include "create_component.h"
#include "resistor_class.h"
#include "capacitor_class.h"
#include "inductor_class.h"
#include "diode_class.h"
#include "transistor_class.h"
#include <iostream>
#include "input_validation.h"
// Give user options in selecting which component for circuit
std::shared_ptr<component_class> create_component() {
    int choice;
    while (true) {
        std::cout << "Choose the type of component to add:\n";
        std::cout << "1. Resistor\n2. Capacitor\n3. Inductor\n4. Diode\n5. Transistor\n";
        choice = get_valid_int(1, 5);
        if (choice == 1) {
            double resistance;
            std::cout << "Enter the resistance (ohms): ";
            resistance = get_valid_double();
            return std::make_shared<resistor_class>(resistance);
        }
        else if (choice == 2) {
            double capacitance;
            std::cout << "Enter the capacitance (farads): ";
            capacitance = get_valid_double();
            return std::make_shared<capacitor_class>(capacitance);
        }
        else if (choice == 3) {
            double inductance;
            std::cout << "Enter the inductance (henries): ";
            inductance = get_valid_double();
            return std::make_shared<inductor_class>(inductance);
        }
        else if (choice == 4) {
            int forward_biased;
            std::cout << "Is the diode forward-biased? (1 for yes, 0 for no): ";
            forward_biased = get_valid_int(0, 1);
            return std::make_shared<diode_class>(forward_biased);
        }
        else if (choice == 5) {
            double gain, base_current;
            std::cout << "Enter the transistor gain: ";
            gain = get_valid_double();
            std::cout << "Enter the base current (amps): ";
            base_current = get_valid_double();
            return std::make_shared<transistor_class>(gain, base_current);
        }
    }
}