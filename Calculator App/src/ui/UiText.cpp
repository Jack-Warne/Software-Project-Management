#include "UiText.h"
#include "ofMain.h"
#include "ofApp.h"

UiText::UiText(std::string text, ofTrueTypeFont* font, float x, float y, float width) : UiElement(x, y, width, 0) {
	this->text = text;
	this->pFont = font;
	updateWordWrapping();
}
UiText::UiText(std::string text, float x, float y, float width) : UiElement(x, y, width, 0) {
	this->text = text;
	this->pFont = &ofApp::normalFont;
	updateWordWrapping();
}

void UiText::updateWordWrapping() {
	wordWrappedTextLines.clear();
	if (!this->doWordWrapping) {
		wordWrappedTextLines.push_back(this->text);
		return;
	}
	std::vector<std::string> lines;
	boost::split(lines, this->text, boost::is_any_of("\n"));	//	Split the string by new lines. This way if we explicitly put in a new line inside the text the new line will be preserved.

	this->height = 0;
	if (this->width >= 0) {
		this->estimatedWidth = this->width;	//	The width is known, so no estimation is needed
	}
	else {
		this->estimatedWidth = 0;	//	Set the estimated width to 0 so we can estimate it properly
	}

	this->height = 0;
	std::string wordWrappedLine;
	for (std::string line : lines) {
		if (this->width < 0) {
			wordWrappedTextLines.push_back(line);	//	No wrapping needs to be done, so we can just add the line into the set of finished lines as it is. 
			this->estimatedWidth = std::max(this->estimatedWidth, this->pFont->stringWidth(line));

			this->height += this->pFont->getLineHeight();	//	Recalculate the height of this element, because the height of the text element will change when the words wrap around
			continue;
		}
		std::vector<std::string> words;		//	Split this line into words
		boost::split(words, line, boost::is_any_of(" "));

		for (std::string word : words) {
			std::string newWrappedLine = wordWrappedLine + word + ' ';	//	Check if the current line would be too long if the next word was to be added. If it would be too long we start the next line, otherwise we add the word to what we have.
			float newLineWidth = this->pFont->stringWidth(newWrappedLine);
			if (newLineWidth > this->estimatedWidth) {
				if (wordWrappedLine.length() > 0 && wordWrappedLine[wordWrappedLine.length() - 1] == ' ') wordWrappedLine.pop_back();	//	Remove the last space of the string, since the extra space added by this algorithm could mess with how the text is centered.

				wordWrappedTextLines.push_back(wordWrappedLine);
				wordWrappedLine = word + ' ';
				this->height += this->pFont->getLineHeight();	//	Increment the height of the element by one line
			}
			else {
				wordWrappedLine = newWrappedLine;
			}
		}
		if (wordWrappedLine.length() > 0 && wordWrappedLine[wordWrappedLine.length() - 1] == ' ') wordWrappedLine.pop_back();	//	Remove the last space of the string, since the extra space added by this algorithm could mess with how the text is centered.
		wordWrappedTextLines.push_back(wordWrappedLine);
		wordWrappedLine = "";
		this->height += this->pFont->getLineHeight();	//	Increment the height of the element by one line
	}
}
void UiText::onRender(float x, float y) {
	float offset = 0;
	ofSetColor(this->textColor);

	for (string line : this->wordWrappedTextLines) {
		auto textBoundingBox = pFont->getStringBoundingBox(line, 0, 0);	//	Calculate both the width and the height of the text

		float textXPosition = x;
		float lineWidth = textBoundingBox.getWidth();

		switch (this->textAlignment) {	//	Figure out how to align the text on this line
		case TextAlignment::Left:	//	To the left
			break;
		case TextAlignment::Right:
			textXPosition += this->width - lineWidth;	//	To the right
			break;
		case TextAlignment::Center:
			textXPosition += this->width / 2 - lineWidth / 2;	//	Center the text
			break;
		}

		pFont->drawString(line, textXPosition, y + offset + std::round(textBoundingBox.getHeight() / pFont->getLineHeight()) * pFont->getLineHeight());	//	Draw the line to the screen. For some reason OpenFrameworks draws the text from the bottom left corner instead of the usual top left corner, so we have to offset the text by its height to account for that.
		offset += pFont->getLineHeight();
	}
	UiElement::onRender(x, y);	//	Call onRender on this element's children
}