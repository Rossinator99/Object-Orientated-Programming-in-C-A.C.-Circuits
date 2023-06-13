#include "Command.h"
#include "helper_functions.h"
#include "circuit_class.h"
#include <iostream>
// Checks the users inputs against recognised commands
Command get_command() {
    std::string input;
    std::cin >> input;
    if (input == "setfreq") return SetFreq;
    if (input == "setvolt") return SetVolt;
    if (input == "display") return Display;
    if (input == "newcircuit") return NewCircuit;
    if (input == "editcircuit") return EditCircuit;
    if (input == "removecircuit") return RemoveCircuit;
    if (input == "exit") return Exit;
    if (input == "help") return Help;
    // If users inputs does not match command list, it returns Invalid command
    return Invalid;
}

// Prints out information about circuit
void display_circuit(std::shared_ptr<circuit_class>& circuit) {
    print_component_info(*circuit, "Entire Circuit");
    std::cout << "  Voltage: " << circuit->get_voltage() << " V\n";
    std::cout << "  Current: " << circuit->calculate_current() << " A\n";
    std::cout << "============================================\n";
    circuit->print_all_components_information();
    std::cout << "============================================\n";
    print_circuit_layout(*circuit);
}