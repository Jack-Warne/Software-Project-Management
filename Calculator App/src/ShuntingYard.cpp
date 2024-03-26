#include "ShuntingYard.h"
#include <iostream>
#include <sstream>
#include <cctype>

using namespace std;

double ShuntingYard::evaluateExpression(const string& expression) {
    stack<double> values;
    stack<char> operators;

    istringstream iss(expression);
    string token;
    while (iss >> token) {
        if (isdigit(token[0])) {
            values.push(stod(token));
        }
        else if (isOperator(token[0])) {
            char op = token[0];
            while (!operators.empty() && precedence(operators.top()) >= precedence(op)) {
                double b = values.top(); values.pop();
                double a = values.top(); values.pop();
                values.push(applyOperator(a, b, operators.top()));
                operators.pop();
            }
            operators.push(op);
        }
    }

    while (!operators.empty()) {
        double b = values.top(); values.pop();
        double a = values.top(); values.pop();
        values.push(applyOperator(a, b, operators.top()));
        operators.pop();
    }

    return values.top();
}

int ShuntingYard::precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

bool ShuntingYard::isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

double ShuntingYard::applyOperator(double a, double b, char op) {
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return a / b;
    default: throw runtime_error("Invalid operator");
    }
}
