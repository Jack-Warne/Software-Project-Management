#include "Tokeniser.h"

Tokeniser::Tokeniser(std::string text) {
	this->text = text;
	this->head = this->text.begin();
}

bool Tokeniser::readToken(std::string* token) {
	char last = '\0';
	while (this->head != this->text.end()) {
		last = *this->head;
		this->head++;
		if (last != ' ') break;
	}
	if (last == '\0') return false;

	*token = "";
	token->push_back(last);
	if (last == '/' || last == '*' || last == '+' || (last == '-' && !this->was_operator_last) || last == '(' || last == ')') {
		this->was_operator_last = (last != ')');
		return true;
	}
	this->was_operator_last = false;
	if (last == '.') *token = "0.";

	while (this->head != this->text.end()) {
		char current = *this->head;
		this->head++;
		if(current == ' ') continue;
		
		if (!isDigit(current)) {
			if (current == '.') {
				token->push_back('0');
			}else{
				this->head--;
				break;
			}
		}

		token->push_back(current);
		last = current;
	}

	
	if (token->at(token->length() - 1) == '.')token->push_back('0');

	return true;
}

bool Tokeniser::isDigit(char symbol) {
	return (symbol >= '0' && symbol <= '9');
}