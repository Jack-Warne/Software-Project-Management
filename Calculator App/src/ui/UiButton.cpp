#include "UiButton.h"
#include "UiText.h"
#include <ofApp.h>

UiButton::UiButton(float x, float y, float width, float height, std::function<void()> onClickHandler) : UiBox(x, y, width, height) {
	this->onClickHandler = onClickHandler;
}

/// <summary>
/// Simple macro for creating a button with the ofApp::normalFont font. Determines the dimensions of the button from the size of the text.
/// </summary>
/// <param name="text">Text for the label of the button.</param>
/// <param name="x">X coordinate of the button</param>
/// <param name="y"></param>
/// <param name="onClickHandler">Lambda function which is ran when the button is pressed.</param>
/// <param name="width">max width of the text. Useful when doing word wrapping on the text.</param>
/// <returns></returns>
std::shared_ptr<UiButton> UiButton::makeButtonWithLabel(std::string text, float x, float y, std::function<void()> onClickHandler, float width) {
	return makeButtonWithLabel(text, x, y, onClickHandler, &ofApp::normalFont, width);
}

//	Simple macro which makes a button with a label which has the given text. onClickHandler is a lambda function which is ran when the button is clicked, font is a pointer to a font, and width is the maximum width of the text (useful if you want your text to have word wrapping).
std::shared_ptr<UiButton> UiButton::makeButtonWithLabel(std::string text, float x, float y, std::function<void()> onClickHandler, ofTrueTypeFont* font, float width) {
	auto textBbox = font->getStringBoundingBox(text,0,0);

	if (width < 0) width = textBbox.getWidth() + 20;

	auto button = make_shared<UiButton>(x, y, width, std::round(textBbox.getHeight()/font->getLineHeight()) * font->getLineHeight() + 10, onClickHandler);
	button->fillColor = ofColor(245, 245, 245);
	button->borderRadius = 3;

	auto label = button->addChild(make_shared<UiText>(text, font, 5, 0, width - 10));
	label->doWordWrapping = false;
	label->textAlignment = UiText::TextAlignment::Center;
	label->updateWordWrapping();

	return button;
}

ofColor UiButton::getFillColor() {
	if (this->isHoveredOver()) {	//	Return the color of this button if its hovered, pressed, or neither.
		if (ofApp::mainApp->isLeftMousePressed) {
			return this->clickColor;
		}
		else {
			return this->hoverColor;
		}
	}
	return this->fillColor;
}

bool UiButton::onClick(float x, float y) {
	try {
		onClickHandler();	//	Try performing the click action
	}
	catch (int exception) {
		//	This is where the error handling for the function of the button should be done. This error handler simply logs it to the console
		std::cout << "An error has occured while handling a button press: " << exception << std::endl;
	}
	return true;
}