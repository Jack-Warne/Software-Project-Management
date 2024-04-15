#pragma once

#include <string>
#include <variant>

class TokeniserHex
{
	std::string text;
	std::string::iterator head;
	bool was_operator_last = true;


	bool isDigit(char symbol);
public:
	TokeniserHex(std::string text);
	bool readToken(std::string* token);
};

