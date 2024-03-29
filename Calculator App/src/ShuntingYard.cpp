#include "ShuntingYard.h"
#include <iostream>
#include <sstream>
#include <cctype>
#include "Tokeniser.h"

using namespace std;

double ShuntingYard::evaluateExpression(const string& expression) {
    stack<double> values;
    stack<char> operators;

    Tokeniser stream(expression);
    string token;
    while (stream.readToken(&token)) {
        char last = token.at(token.length() - 1);
        if (isdigit(last)) {
            values.push(stod(token));
        }
        else if (isOperator(last)) {
            char op = last;
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
