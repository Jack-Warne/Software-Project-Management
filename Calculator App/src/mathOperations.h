#pragma once
#include <string>

class MathOperations {
public:
    static float evaluate(const std::string& expression);
    static float add(float a, float b);
    static float subtract(float a, float b);
    static float multiply(float a, float b);
    static float divide(float a, float b);
};
