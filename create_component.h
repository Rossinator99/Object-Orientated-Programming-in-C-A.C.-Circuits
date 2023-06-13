#ifndef CREATE_COMPONENTS_H
#define CREATE_COMPONENTS_H
#include <memory>
#include "component_class.h"
// Function declaration for create_component and returning a shared_ptr to it
std::shared_ptr<component_class> create_component();
#endif