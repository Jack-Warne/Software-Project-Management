#include "ofApp.h"
#include "mathOperations.h"


//--------------------------------------------------------------
void ofApp::setup() {
	this->current_number_accumulator = 0;

	float resultAdd = MathOperations::add(5.0f, 3.0f);
	float resultSubtract = MathOperations::subtract(5.0f, 3.0f);
	float resultMultiply = MathOperations::multiply(5.0f, 3.0f);
	float resultDivide = MathOperations::divide(5.0f, 3.0f);

	// Output the results to console or use as needed
	std::cout << "Addition: " << resultAdd << std::endl;
	std::cout << "Subtraction: " << resultSubtract << std::endl;
	std::cout << "Multiplication: " << resultMultiply << std::endl;
	std::cout << "Division: " << resultDivide << std::endl;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

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

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

void ofApp::update_screen(){
	std::cout << this->current_number_accumulator << std::endl;
}



