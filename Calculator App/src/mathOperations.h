#pragma once
#include <string>

class MathOperations {
public:
    static double evaluate(const std::string& expression);
    static double add(double a, double b);
    static double subtract(double a, double b);
    static double multiply(double a, double b);
    static double divide(double a, double b);
};
