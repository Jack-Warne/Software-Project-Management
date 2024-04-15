#include "ShuntingYardHex.h"
#include <iostream>
#include <sstream>
#include <cctype>
#include "TokeniserHex.h"
#include "ErrorCodes.h"

using namespace std;

int ShuntingYardHex::evaluateExpression(const string& expression) {
	stack<uint32_t> values;
	stack<char> operators;

	TokeniserHex stream(expression);
	string token;
	bool wasOperatorLast = true;
	while (stream.readToken(&token)) {
		char last = token.at(token.length() - 1);
		if (isHexDigit(last)) {
			values.push(toNumber(token));
			wasOperatorLast = false;
		}
		else if (isOperator(last)) {
			char op = last;
			while (!operators.empty() && precedence(operators.top()) >= precedence(op)) {
				uint32_t b = values.top(); values.pop();
				uint32_t a = values.top(); values.pop();
				values.push(applyOperator(a, b, operators.top()));
				operators.pop();
			}
			operators.push(op);
			wasOperatorLast = true;
		}
	}

	while (!operators.empty()) {
		uint32_t b = values.top(); values.pop();
		uint32_t a = values.top(); values.pop();
		values.push(applyOperator(a, b, operators.top()));
		operators.pop();
	}

	if (values.empty()) return 0;

	return values.top();
}

int ShuntingYardHex::precedence(char op) {
	if (op == '+' || op == '-') return 1;
	if (op == '*' || op == '/') return 2;
	return 0;
}
bool ShuntingYardHex::isHexDigit(char c) {
	return (c>='0' && c<= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');
}

bool ShuntingYardHex::isOperator(char ch) {
	return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}
uint32_t ShuntingYardHex::toNumber(string num) {
	uint32_t number = 0;

	std::stack<char> digits;
	while (num.size() > 0) {
		digits.push(num[num.size() - 1]);
		num.pop_back();
	}

	while (!digits.empty()) {
		auto c = std::tolower(digits.top());
		digits.pop();
		if (isdigit(c)) {
			number = (number << 4) | (c - '0');
		}
		else {
			number = (number << 4) | (c - 'a'+10);
		}
	}
	return number;
}
std::string ShuntingYardHex::toHex(uint32_t num) {
	std::stringstream stream;
	stream << std::uppercase << std::hex << num;
	return stream.str();
}

int ShuntingYardHex::applyOperator(int a, int b, char op) {
	switch (op) {
		case '+': 
			return a + b;
		case '-': 
			return a - b;
		case '*': 
			return a * b;
		case '/': 
			if (b == 0.0) throw ErrorCode::DivideByZero;
			return a / b;
		default: throw ErrorCode::Parse;
	}
}
