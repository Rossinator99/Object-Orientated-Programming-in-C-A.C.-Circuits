#include "input_validation.h"
// Function to validate and retrieve a positive double input from the user
double get_valid_double() {
    double value;
    while (!(std::cin >> value) || std::cin.peek() != '\n' || value <= 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a positive number: ";
    }
    return value;
}
// Function to validate and retrieve an integer within a specified range from the user
int get_valid_int(int min, int max) {
    int value;
    while (!(std::cin >> value) || std::cin.peek() != '\n' || value < min || value > max) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter an integer between " << min << " and " << max << ": ";
    }
    return value;
}