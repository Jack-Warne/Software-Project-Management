
#include "ofApp.h"
#include "screens/MainScreen.h"
#include "ui/UiBox.h"

const char HEX_ALPHABET[] = "0123456789ABCDEF";

MainScreen::MainScreen() : CalculatorScreen() {
	//	Here are a couple examples on how to use my Ui Framework

	//	When something has a data type of "auto" C++ will try to determine the type of this variable for you. Only works inside functions/methods.
	auto btn_click_handler = []() {	//	This is how you define lambda functions in C++. The code inside this lambda will be ran every time the button is clicked.
		std::cout << "The button has been pressed!" << std::endl;
	};

	this->btn = make_shared<UiButton>(0, 0, 50, 50, btn_click_handler);	//	Creates a new ui element (in this case a 50x50 box at position 0,0)
	btn->fillColor = ofColor(255,0,0);	//	Changes the colour of the button to red
	btn->hoverColor = ofColor(200, 0, 0);	//	Changes the colour of the button when it is hovered over
	btn->clickColor = ofColor(128, 0, 0);	//	Changes the colour of the button when it is hovered over

	this->addChild(btn);	//	Adds the button to the screen, allowing it to be drawn and interacted with

	std::shared_ptr<UiButton> other_btn = UiButton::makeButtonWithLabel("Make this button green", 50, 300, []() {});	//	You can define the onClickHandler to be empty at first, and change it later

	other_btn->onClickHandler = [this, other_btn]() {	//	If you use a variable defined outside of the lambda function you need to put it in the square brackets, otherwise your code will not compile.
		other_btn->fillColor = ofColor(0, 255, 0);	//	Simple code which makes the above button more green when you press it.
		other_btn->hoverColor = ofColor(0, 255, 0);
		other_btn->clickColor = ofColor(0, 255, 0);
	};

	for (int i = 0; i < 10; i++) {
		auto btn = UiButton::makeButtonWithLabel(std::to_string(i), 200, 50 + 65 * i, [i]() {
				ofApp::mainApp->keyReleased('0'+i);
			});
		this->addChild(btn);
	}

	this->addChild(UiButton::makeButtonWithLabel("C", 300, 200, []() {
		ofApp::mainApp->keyReleased('c');
		}));

	this->addChild(other_btn);	//	Adds the button to the screen


	//	Now for the actual calculator code

	this->output_text = make_shared<UiText>("0", 20, 20, this->width - 40);
	this->output_text->doWordWrapping = false;
	this->output_text->textAlignment = UiText::TextAlignment::Right;
	this->addChild(this->output_text);
}

void MainScreen::update_display(bool isHex) {
	//	Update the text displayed in the calculator's output
	std::string output_string;

	output_string = ofApp::mainApp->accumulator;
	if (output_string.length() == 0) output_string = "0";
	this->output_text->set_text(output_string);
}