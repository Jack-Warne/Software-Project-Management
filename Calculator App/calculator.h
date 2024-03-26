#pragma once
#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <string>

class Calculator {
public:
    Calculator();
    double evaluateExpression(const std::string& expression);
private:
    double evaluate(const std::string& expression, size_t& pos);
    double evaluateNumber(const std::string& expression, size_t& pos);
    double evaluateTerm(const std::string& expression, size_t& pos);
    double evaluateFactor(const std::string& expression, size_t& pos);
};

#endif // CALCULATOR_H
