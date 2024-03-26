#include "calculator.h"
#include <iostream>
#include <cmath>
#include <cctype>

Calculator::Calculator() {}

double Calculator::evaluateExpression(const std::string& expression) {
    size_t pos = 0;
    return evaluate(expression, pos);
}

double Calculator::evaluate(const std::string& expression, size_t& pos) {
    double result = evaluateTerm(expression, pos);

    while (pos < expression.size()) {
        char op = expression[pos];
        if (op == '+' || op == '-') {
            pos++;
            double nextTerm = evaluateTerm(expression, pos);
            if (op == '+')
                result += nextTerm;
            else
                result -= nextTerm;
        }
        else {
            break;
        }
    }

    return result;
}

double Calculator::evaluateTerm(const std::string& expression, size_t& pos) {
    double result = evaluateFactor(expression, pos);

    while (pos < expression.size()) {
        char op = expression[pos];
        if (op == '*' || op == '/') {
            pos++;
            double nextFactor = evaluateFactor(expression, pos);
            if (op == '*')
                result *= nextFactor;
            else
                result /= nextFactor;
        }
        else {
            break;
        }
    }

    return result;
}

double Calculator::evaluateFactor(const std::string& expression, size_t& pos) {
    double result = evaluateNumber(expression, pos);

    while (pos < expression.size() && (expression[pos] == '^' || expression[pos] == '√')) {
        char op = expression[pos];
        pos++;
        double nextFactor = evaluateNumber(expression, pos);
        if (op == '^')
            result = pow(result, nextFactor);
        else if (op == '√')
            result = sqrt(nextFactor);
    }

    return result;
}

double Calculator::evaluateNumber(const std::string& expression, size_t& pos) {
    double result = 0;
    bool negative = false;
    if (expression[pos] == '-') {
        negative = true;
        pos++;
    }

    while (pos < expression.size() && (isdigit(expression[pos]) || expression[pos] == '.')) {
        result = result * 10 + (expression[pos] - '0');
        pos++;
    }

    if (pos < expression.size() && expression[pos] == '.') {
        pos++;
        double fraction = 0.1;
        while (pos < expression.size() && isdigit(expression[pos])) {
            result += fraction * (expression[pos] - '0');
            fraction *= 0.1;
            pos++;
        }
    }

    if (negative)
        result = -result;

    return result;
}
