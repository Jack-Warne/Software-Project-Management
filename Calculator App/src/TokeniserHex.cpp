#include "TokeniserHex.h"
#include "./ErrorCodes.h"
#include <ShuntingYardHex.h>

TokeniserHex::TokeniserHex(std::string text) {
	this->text = text;
	this->head = this->text.begin();
}

bool TokeniserHex::readToken(std::string* token) {
	char last = '\0';
	while (this->head != this->text.end()) {
		last = *this->head;
		this->head++;
		if (last != ' ') break;
	}
	if (last == '\0') return false;

	*token = "";
	token->push_back(last);
	if (last == '/' || last == '*' || last == '+' || last == '-' || last == '(' || last == ')') {
		if (this->was_operator_last) throw ErrorCode::Parse;
		this->was_operator_last = (last != ')' && last!='%');
		return true;
	}
	this->was_operator_last = false;

	while (this->head != this->text.end()) {
		char current = *this->head;
		this->head++;
		if(current == ' ') continue;
		
		if (!isDigit(current)) {
			this->head--;
			break;
		}

		token->push_back(current);
		last = current;
	}

	

	return true;
}


bool TokeniserHex::isDigit(char symbol) {
	return ShuntingYardHex::isHexDigit(symbol);
}