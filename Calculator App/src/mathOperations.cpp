#include "MathOperations.h"
#include "ErrorCodes.h"
#include <iostream>
#include <sstream>

float MathOperations::evaluate(const std::string& expression) {
	std::istringstream iss(expression);
	float result = 0.;
	char op = '+';
	float operand;

	while (iss >> operand) {
		switch (op) {
		case '+':
			result += operand;
			break;
		case '-':
			result -= operand;
			break;
		case '*':
			result *= operand;
			break;
		case '/':
			if (operand != 0.) {
				result /= operand;
			}
			else {
				throw ErrorCode::DivideByZero;
			}
			break;
		}

		// Read next operator
		iss >> op;
	}

	return result;
}
float MathOperations::add(float a, float b) {
	return a + b;
}

float MathOperations::subtract(float a, float b) {
	return a - b;
}

float MathOperations::multiply(float a, float b) {
	return a * b;
}

float MathOperations::divide(float a, float b) {
	if (b == 0.) {
		throw ErrorCode::DivideByZero;
	}
	return a / b;
}
