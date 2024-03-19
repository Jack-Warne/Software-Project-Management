
#include "ofApp.h"
#include "screens/MainScreen.h"
#include "ui/UiBox.h"

MainScreen::MainScreen() : UiElement(0, 0, ofGetWidth(), ofGetHeight()) {
	//	When something has a data type of "auto" C++ will try to determine the type of this variable for you. Only works inside functions/methods.
	auto btn_click_handler = []() {	//	This is how you define lambda functions in C++. The code inside this lambda will be ran every time the button is clicked.
		std::cout << "The button has been pressed!" << std::endl;
	};

	this->btn = make_shared<UiButton>(0, 0, 50, 50, btn_click_handler);	//	Creates a new ui element (in this case a 50x50 box at position 0,0)
	btn->fillColor = ofColor(255,0,0);	//	Changes the colour of the button to red
	btn->hoverColor = ofColor(200, 0, 0);	//	Changes the colour of the button when it is hovered over
	btn->clickColor = ofColor(128, 0, 0);	//	Changes the colour of the button when it is hovered over

	this->addChild(btn);	//	Adds the button to the screen, allowing it to be drawn and interacted with

	std::shared_ptr<UiButton> other_btn = UiButton::makeButtonWithLabel("Make this button green", 50, 200, []() {});	//	You can define the onClickHandler to be empty at first, and change it later

	other_btn->onClickHandler = [this, other_btn]() {	//	If you use a variable defined outside of the lambda function you need to put it in the square brackets, otherwise your code will not compile.
		other_btn->fillColor = ofColor(0, 255, 0);	//	Simple code which makes the above button more green when you press it.
		other_btn->hoverColor = ofColor(0, 255, 0);
		other_btn->clickColor = ofColor(0, 255, 0);
	};

	for (int i = 0; i < 10; i++) {
		auto btn = UiButton::makeButtonWithLabel(std::to_string(i), 200, 50 + 75 * i, [i]() {
				ofApp::mainApp->keyReleased('0'+i);
			});
		this->addChild(btn);
	}


	this->addChild(other_btn);	//	Adds the button to the screen
}