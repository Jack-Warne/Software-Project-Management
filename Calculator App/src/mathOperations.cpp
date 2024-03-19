#include "MathOperations.h"
#include <iostream>
#include <sstream>

double MathOperations::evaluate(const std::string& expression) {
    std::istringstream iss(expression);
    double result = 0.0f;
    char op = '+';
    double operand;

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

double MathOperations::add(double a, double b) {
    return a + b;
}

double MathOperations::subtract(double a, double b) {
    return a - b;
}

double MathOperations::multiply(double a, double b) {
    return a * b;
}

double MathOperations::divide(double a, double b) {
    if (b == 0) {
        // Division by zero error
        return 0; // Just a placeholder because can't return a string yet :DDD
    }
    return a / b;
}
