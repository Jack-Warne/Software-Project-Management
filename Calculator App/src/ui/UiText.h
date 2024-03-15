#pragma once
#include <string>
#include "boost/algorithm/string/classification.hpp"
#include "boost/algorithm/string/split.hpp"
#include "UiElement.h"
#include "ofMain.h"

class UiText : public UiElement
{
private:
	std::vector<std::string> wordWrappedTextLines;	//	Contains the lines of text after the word wrapping has been calculated
	float estimatedWidth = 0;
public:
	enum class TextAlignment { Left, Center, Right };

	ofColor textColor = ofColor(0, 0, 0);	//	Colour of the text
	ofTrueTypeFont* pFont;	//	Font to use when drawing and calculating positions
	bool doWordWrapping = true;

	TextAlignment textAlignment = TextAlignment::Left;	//	How to align the text inside this text element

	std::string text = "";

	UiText(std::string text, ofTrueTypeFont* font, float x, float y, float width = -1);
	UiText(std::string text, float x, float y, float width = -1);

	void onRender(float x, float y);

	/// <summary>
	/// Updates the text displayed on this element accouting for word wrapping. This has to be called every time the text changes, as well as every time this->width gets changed.
	/// </summary>
	void updateWordWrapping();

};

