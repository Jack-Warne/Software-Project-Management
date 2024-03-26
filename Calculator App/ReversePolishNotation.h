#pragma once

#include <string>
#include <stack>

class ReversePolishNotation {
public:
    ReversePolishNotation();
    std::string infixToRPN(const std::string& expression);
    std::string infixToPrefix(const std::string& expression);
    double evaluate(const std::string& expression);

private:
    bool isOperator(char c);
    double performOperation(char operation, double operand1, double operand2);
};
