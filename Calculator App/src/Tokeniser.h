#pragma once

#include <string>
#include <variant>

class Tokeniser
{
	std::string text;
	std::string::iterator head;
	bool was_operator_last = true;


	bool isDigit(char symbol);
public:
	Tokeniser(std::string text);
	bool readToken(std::string* token);
};

