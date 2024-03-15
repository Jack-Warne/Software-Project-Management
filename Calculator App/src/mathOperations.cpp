#include "MathOperations.h"
#include <iostream>

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
