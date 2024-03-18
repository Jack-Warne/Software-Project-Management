#include "MathOperations.h"
#include <iostream>
#include <sstream>

float MathOperations::evaluate(const std::string& expression) {
    std::istringstream iss(expression);
    float result = 0.0f;
    char op = '+';
    float operand;

    while (iss >> operand) {
        switch (op) {
        case '+':
            result += operand;
            break;
        case '-':
            result -= operand;
            break;
        case '*':
            result *= operand;
            break;
        case '/':
            if (operand != 0) {
                result /= operand;
            }
            else {
                std::cerr << "Error: Division by zero." << std::endl;
                return 0; // You can handle this error in a better way if needed
            }
            break;
        }

        // Read next operator
        iss >> op;
    }

    return result;
}
float MathOperations::add(float a, float b) {
    return a + b;
}

float MathOperations::subtract(float a, float b) {
    return a - b;
}

float MathOperations::multiply(float a, float b) {
    return a * b;
}

float MathOperations::divide(float a, float b) {
    if (b == 0) {
        // Division by zero error
        return 0; // Just a placeholder because can't return a string yet :DDD
    }
    return a / b;
}
