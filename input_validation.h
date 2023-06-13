#ifndef INPUT_VALIDATION_H
#define INPUT_VALIDATION_H
#include <iostream>
#include <limits>
// Function to validate and retrieve a positive double input from the user
double get_valid_double();
// Function to validate and retrieve an integer within a specified range from the user
int get_valid_int(int min = std::numeric_limits<int>::min(), int max = std::numeric_limits<int>::max());
#endif