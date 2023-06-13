#ifndef COMMAND_H
#define COMMAND_H
#include <memory>
#include "circuit_class.h"
// Command user can input
enum Command { SetFreq, SetVolt, Display, NewCircuit, EditCircuit, RemoveCircuit, Exit, Help, Invalid };
Command get_command();
void display_circuit(std::shared_ptr<circuit_class>& circuit);
#endif // COMMAND_H