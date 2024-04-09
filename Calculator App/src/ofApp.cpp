#include "ofApp.h"
#include "ui/UiElement.h"
#include "screens/MainScreen.h"
#include "mathOperations.h"
#include "ShuntingYard.h"


shared_ptr<CalculatorScreen> ofApp::root;	//	Declare the constants used by the ui system
ofApp* ofApp::mainApp;
weak_ptr<UiElement> ofApp::hoveredElement;
ofTrueTypeFont ofApp::normalFont;

//--------------------------------------------------------------
void ofApp::setup(){
	mainApp = this;	//	Define some constants for the ui system

	auto project_directory = std::filesystem::current_path().parent_path();
	auto normal_font_path = project_directory;
	normal_font_path.append("assets");
	normal_font_path.append("fonts");
	normal_font_path.append("coolvetica.ttf");
	std::cout << normal_font_path.string() << std::endl;

	//	Load the fonts here
	ofApp::normalFont.load(normal_font_path.string(), 25);	//	https://www.dafont.com/coolvetica.font with a size of 25 pixels

	ofApp::root = make_shared<MainScreen>();	//	Show the first screen. To change to a different screen after this is called please use ofApp::changeScreens()

	//	Your setup code goes here

	this->accumulator = "";
	std::cout << std::endl << std::endl;

	std::string expr = "2-(.2* -   1.)/3";
	std::cout << expr << " = " << ShuntingYard::evaluateExpression(expr) << std::endl;
}

//--------------------------------------------------------------
void ofApp::update(){
	ofApp::root->onUpdate();	//	Updates the current screens contents
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofApp::root->onRender(0, 0);	//	Draws the current screens contents
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	try {
		if (this->current_error != ErrorCode::Success) {
			this->current_error = ErrorCode::Success;
		}
		else {
			switch (key) {
			case 8:
			case 67:
			case 99:
				//	Remove the last digit
				this->accumulator.pop_back();
				break;
			case 72:
			case 104:	//	Turn on hex mode
				this->isHexMode = !this->isHexMode;
				break;
			default:
				if (key >= 48 && key < 58) {
					this->accumulator.push_back(key);	//	Insert the new digit into the accumulator. Clamps the value to the nearest integer boundary if it is too large
				}
			}
		}
		this->update_screen();	//	Update the screen once everything is done
	}
	catch (ErrorCode code) {
		this->current_error = code;
		this->update_screen();	//	Update the screen once everything is done
	}
}

void ofApp::mouseMoved(int x, int y) {
	ofApp::updateMouseHoveredElement(x, y, ofApp::root);
}

void ofApp::mouseDragged(int x, int y, int button) {
	if (button == 0) isLeftMousePressed = true;
	ofApp::updateMouseHoveredElement(x, y, ofApp::root);
}

void ofApp::mousePressed(int x, int y, int button) {
	if (button == 0) isLeftMousePressed = true;
	ofApp::updateMouseHoveredElement(x, y, ofApp::root);
}

void ofApp::mouseReleased(int x, int y, int button) {
	ofApp::updateMouseHoveredElement(x, y, ofApp::root);
	if (button == 0) {
		isLeftMousePressed = false;
		ofApp::root->onClick((float)x, (float)y);
	}
}

void ofApp::mouseEntered(int x, int y) {
	ofApp::updateMouseHoveredElement(x, y, ofApp::root);
}

void ofApp::mouseExited(int x, int y) {
	this->isLeftMousePressed = false;
}

void ofApp::updateMouseHoveredElement(float mouseX, float mouseY, std::weak_ptr<UiElement> currentNode) {
	if (currentNode.expired()) return;

	hoveredElement = currentNode;
	auto fullPointer = hoveredElement.lock();
	for (auto child : fullPointer->Children) {
		if (child->isInBounds(mouseX - child->xPosition, mouseY - child->yPosition)) updateMouseHoveredElement(mouseX - child->xPosition, mouseY - child->yPosition, child);
	}
}


void ofApp::update_screen(){
	root->update_display(isHexMode);
	std::cout << this->accumulator << std::endl;
}
