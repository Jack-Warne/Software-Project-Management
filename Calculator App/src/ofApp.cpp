#include "ofApp.h"
#include "mathOperations.h"


//--------------------------------------------------------------
void ofApp::setup() {
    float resultAdd = MathOperations::add(5.0f, 3.0f);
    float resultSubtract = MathOperations::subtract(5.0f, 3.0f);
    float resultMultiply = MathOperations::multiply(5.0f, 3.0f);
    float resultDivide = MathOperations::divide(5.0f, 3.0f);

    // Output the results to console or use as needed
    std::cout << "Addition: " << resultAdd << std::endl;
    std::cout << "Subtraction: " << resultSubtract << std::endl;
    std::cout << "Multiplication: " << resultMultiply << std::endl;
    std::cout << "Division: " << resultDivide << std::endl;
};

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

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
