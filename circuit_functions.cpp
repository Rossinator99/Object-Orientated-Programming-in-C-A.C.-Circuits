#include "circuit_functions.h"
#include "create_component.h" 
#include "input_validation.h"
// Define the circuits and circuit_parents objects
std::map<std::string, std::shared_ptr<circuit_class>> circuits;
std::map<std::string, std::string> circuit_parents;
std::shared_ptr<circuit_class> create_circuit(circuit_class::connection type,
    const std::string& parent_circuit_name, std::shared_ptr<circuit_class> existing_circuit,
    bool clear_existing_circuits, double parent_frequency) {
    if (clear_existing_circuits) {
        circuits.clear();
        circuit_parents.clear();
    }
    std::shared_ptr<circuit_class> circuit;
    if (existing_circuit) {
        // If an existing circuit is provided, edit it instead of creating a new one
        circuit = existing_circuit;
    }
    else {
        // If no existing circuit is provided, create a new one
        circuit = std::make_shared<circuit_class>(parent_circuit_name, type);
    }
    // Store the circuit in the circuits map
    circuits[parent_circuit_name] = circuit;
    while (true) {
        // Lets the user choose an option for what to do next with the circuit
        std::cout << "\nCurrent circuit: " << parent_circuit_name << '\n';
        std::cout << "Choose an option:\n";
        std::cout << "1. Add a component\n";
        std::cout << "2. Add a series nested circuit\n";
        std::cout << "3. Add a parallel nested circuit\n";
        std::cout << "4. Finalise this circuit\n";
        int choice;
        choice = get_valid_int(1, 4);
        if (choice == 1) {
            auto component = create_component();
            circuit->add_component(component);
        }
        // Creates a nested circuit, and stores its parent
        else if (choice == 2 || choice == 3) {
            std::string nested_circuit_name;
            std::cout << "Enter a name for the nested circuit: ";
            std::cin.ignore();
            while (true) {
                std::getline(std::cin, nested_circuit_name);

                // Check if the circuit name is already in use
                if (circuits.find(nested_circuit_name) == circuits.end()) {
                    break;
                }
                else {
                    std::cout << "A circuit with this name already exists. Please choose a different name.\n";
                }
            }
            auto nested_circuit = create_circuit(choice == 2 ? circuit_class::series : circuit_class::parallel, nested_circuit_name, nullptr, false, circuit->get_frequency());
            circuit->add_component(nested_circuit, parent_circuit_name);
            circuit_parents[nested_circuit_name] = parent_circuit_name;
        }
        // Ensures there is at least one component in the circuit
        else if (choice == 4) {
            if (circuit->get_components_size() == 0) {
                std::cout << "Cannot finalise circuit without at least one component. Please add a component.\n";
                continue;
            }
            break;
        }
        std::cout << "\nCurrent circuit layout: \n" << circuit->get_layout() << '\n';
    }
    // Set the frequency of the nested circuit to the parent frequency
    if (parent_frequency > 0.0) {
        circuit->set_frequency(parent_frequency);
    }
    return circuit;
}