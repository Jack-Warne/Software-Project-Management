#include "MathOperations.h"
#include <iostream>

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
