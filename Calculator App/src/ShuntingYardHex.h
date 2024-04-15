#pragma once
#include <string>
#include <stack>
#include <vector>

class ShuntingYardHex {
public:
    static int evaluateExpression(const std::string& expression);
    static bool ShuntingYardHex::isHexDigit(char c);

private:
    static int precedence(char op);
    static bool isOperator(char ch);
    static int applyOperator(int a, int b, char op);
    static int toNumber(std::string num);
};
