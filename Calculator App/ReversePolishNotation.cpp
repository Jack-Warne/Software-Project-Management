#include "ReversePolishNotation.h"
#include <sstream>
#include <cmath>
#include <map>

ReversePolishNotation::ReversePolishNotation() {}

std::string ReversePolishNotation::infixToRPN(const std::string& expression) {
    std::stack<char> operatorStack;
    std::string rpnExpression;

    std::map<char, int> precedence;
    precedence['+'] = precedence['-'] = 1;
    precedence['*'] = precedence['/'] = 2;

    for (char token : expression) {
        if (isdigit(token) || (token == '-' && !operatorStack.empty() && !isdigit(operatorStack.top()))) {
            rpnExpression += token;
            rpnExpression += ' ';
        }
        else if (isOperator(token)) {
            while (!operatorStack.empty() && precedence[token] <= precedence[operatorStack.top()]) {
                rpnExpression += operatorStack.top();
                rpnExpression += ' ';
                operatorStack.pop();
            }
            operatorStack.push(token);
        }
        else if (token == '(') {
            operatorStack.push(token);
        }
        else if (token == ')') {
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                rpnExpression += operatorStack.top();
                rpnExpression += ' ';
                operatorStack.pop();
            }
            operatorStack.pop(); // Remove '('
        }
    }

    while (!operatorStack.empty()) {
        rpnExpression += operatorStack.top();
        rpnExpression += ' ';
        operatorStack.pop();
    }

    // Remove trailing space
    if (!rpnExpression.empty())
        rpnExpression.pop_back();

    return rpnExpression;
}

std::string ReversePolishNotation::infixToPrefix(const std::string& expression) {
    std::string reversedExpression(expression.rbegin(), expression.rend());
    std::stack<char> operatorStack;
    std::string prefixExpression;

    std::map<char, int> precedence;
    precedence['+'] = precedence['-'] = 1;
    precedence['*'] = precedence['/'] = 2;

    for (char token : reversedExpression) {
        if (isdigit(token) || (token == '-' && !operatorStack.empty() && !isdigit(operatorStack.top()))) {
            prefixExpression += token;
        }
        else if (token == ')') {
            operatorStack.push(token);
        }
        else if (token == '(') {
            while (!operatorStack.empty() && operatorStack.top() != ')') {
                prefixExpression += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.pop(); // Remove ')'
        }
        else if (isOperator(token)) {
            while (!operatorStack.empty() && precedence[token] < precedence[operatorStack.top()]) {
                prefixExpression += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.push(token);
        }
    }

    while (!operatorStack.empty()) {
        prefixExpression += operatorStack.top();
        operatorStack.pop();
    }

    std::reverse(prefixExpression.begin(), prefixExpression.end());

    return prefixExpression;
}



bool ReversePolishNotation::isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

double ReversePolishNotation::performOperation(char operation, double operand1, double operand2) {
    switch (operation) {
    case '+':
        return operand1 + operand2;
    case '-':
        return operand1 - operand2;
    case '*':
        return operand1 * operand2;
    case '/':
        if (operand2 != 0)
            return operand1 / operand2;
        else
            throw "Division by zero!";
    default:
        throw "Invalid operator!";
    }
}

double ReversePolishNotation::evaluate(const std::string& expression) {
    std::stack<double> stack;

    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (isdigit(token[0]) || (token.size() > 1 && token[0] == '-' && isdigit(token[1]))) {
            stack.push(std::stod(token));
        }
        else if (isOperator(token[0])) {
            if (stack.size() < 2)
                throw "Invalid expression!";

            double operand2 = stack.top();
            stack.pop();
            double operand1 = stack.top();
            stack.pop();

            double result = performOperation(token[0], operand1, operand2);
            stack.push(result);
        }
        else {
            throw "Invalid token!";
        }
    }

    if (stack.size() != 1)
        throw "Invalid expression!";

    return stack.top();
}
