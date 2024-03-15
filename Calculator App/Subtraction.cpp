#include "Subtraction.h"
#include <iostream>

// Constructor definition
Subtraction::Subtraction(float inputA, float inputB) : a(inputA), b(inputB) {}

// Function to perform subtraction and output result
void Subtraction::calculate() {
    float result = a - b;
    std::cout << "Result of subtraction: " << result << std::endl;
}
