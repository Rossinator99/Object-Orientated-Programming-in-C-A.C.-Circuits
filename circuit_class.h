#ifndef CIRCUIT_CLASS_H
#define CIRCUIT_CLASS_H
#include "component_class.h"
#include <vector>
#include <map>
#include <memory>
// Forward declare of function print_component_info
void print_component_info(const component_class& comp, const std::string& component_name);
class circuit_class : public component_class {
private:
    // Contains all the components in the circuit, and their names
    std::vector<std::pair<std::shared_ptr<component_class>, std::string>> components;
    // Stores the count of each type of component in the circuit
    std::map<std::string, int> component_counts;
    // Name of the circuit
    std::string circuit_name;
    // Voltage across the circuit in volts
    double voltage;
public:
    // Enum representing type of connection in the circuit
    enum connection { series, parallel };
    // The type of connection used in the circuit: parallel or series
    connection connection_type;
    double frequency;
    circuit_class(const std::string& name = "Circuit", connection type = series);
    ~circuit_class() noexcept override;
    std::string get_type() const override;
    size_t get_components_size() const;
    void add_component(std::shared_ptr<component_class> comp, const std::string& circuit_name = "");
    void remove_component(std::shared_ptr<component_class> component);
    void print_all_components_information() const;
    std::string get_layout() const;
    char get_symbol() const override;
    void set_frequency(double freq) override;
    double get_frequency() const override;
    std::complex<double> get_impedance(double frequency) const override;
    double get_magnitude_impedance(double frequency) const override;
    double get_phase_difference(double frequency) const override;
    double get_voltage() const;
    void set_voltage(double volt);
    double calculate_current() const;

};
#endif