#pragma once
#include <string>
#include <stack>
#include <vector>

class ShuntingYardHex {
public:
    static int evaluateExpression(const std::string& expression);
    static bool ShuntingYardHex::isHexDigit(char c);
    static std::string ShuntingYardHex::toHex(uint32_t num);

private:
    static int precedence(char op);
    static bool isOperator(char ch);
    static int applyOperator(int a, int b, char op);
    static uint32_t toNumber(std::string num);
};
