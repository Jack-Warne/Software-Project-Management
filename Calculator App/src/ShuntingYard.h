#pragma once
#include <string>
#include <stack>
#include <vector>

class ShuntingYard {
public:
    static double evaluateExpression(const std::string& expression);

private:
    static int precedence(char op);
    static bool isOperator(char ch);
    static double applyOperator(double a, double b, char op);
};
