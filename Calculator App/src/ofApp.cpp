#include "ofApp.h"
#include "ui/UiElement.h"
#include "screens/MainScreen.h"


shared_ptr<UiElement> ofApp::root;	//	Declare the constants used by the ui system
ofApp* ofApp::mainApp;
weak_ptr<UiElement> ofApp::hoveredElement;
ofTrueTypeFont ofApp::normalFont;

//--------------------------------------------------------------
void ofApp::setup(){
	mainApp = this;	//	Define some constants for the ui system

	string current_directory = std::filesystem::current_path().string();

	//	Load the fonts here
	ofApp::normalFont.load(current_directory+"\\fonts\\coolvetica.ttf", 25);	//	https://www.dafont.com/coolvetica.font with a size of 25 pixels

	ofApp::root = make_shared<MainScreen>();	//	Show the first screen. To change to a different screen after this is called please use ofApp::changeScreens()

	//	Your setup code goes here

	this->current_number_accumulator = 0;
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
	switch (key) {
	case 77:
	case 109:
		this->current_number_accumulator *= -1;	//	Change the sign of the number in the accumulator
		break;

	case 8:
	case 67:
	case 99:
		this->current_number_accumulator /= 10;	//	Remove the last digit
		break;

	default:
		if (key >= 48 && key < 58) {
			this->current_number_accumulator = this->current_number_accumulator * 10 + (key - 48);	//	Insert the new digit into the accumulator. Clamps the value to the nearest integer boundary if it is too large
		}
	}

	this->update_screen();	//	Update the screen once everything is done
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
	std::cout << this->current_number_accumulator << std::endl;
}



