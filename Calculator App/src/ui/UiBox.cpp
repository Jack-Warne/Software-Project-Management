#include "UiBox.h"
#include "ofMain.h"

void UiBox::onRender(float x, float y) {

	if (this->borderWidth > 0) {	//	If we have a border we should render 2 boxes, otherwise we only need 1

		ofSetColor(this->borderColor);	//	Render the outline
		if (this->borderRadius > 0) {		//	If the box has a radius we should use the more advanced and more computationally expensive rendering function
			ofRectRounded(x - this->borderWidth / 2, y - this->borderWidth / 2, this->width + this->borderWidth, this->height + this->borderWidth, this->borderRadius);
		}
		else {
			ofDrawRectangle(x - this->borderWidth / 2, y - this->borderWidth / 2, this->width + this->borderWidth, this->height + this->borderWidth);
		}

		ofSetColor(this->getFillColor());	//	Render the main box
		if (this->borderRadius > 0) {		//	If the box has a radius we should use the more advanced and more computationally expensive rendering function
			ofRectRounded(x + this->borderWidth / 2, y + this->borderWidth / 2, this->width - this->borderWidth, this->height - this->borderWidth, this->borderRadius);
		}
		else {
			ofDrawRectangle(x + this->borderWidth / 2, y + this->borderWidth / 2, this->width - this->borderWidth, this->height - this->borderWidth);
		}
	}
	else {
		ofSetColor(this->getFillColor());
		if (this->borderRadius > 0) {		//	If the box has a radius we should use the more advanced and more computationally expensive rendering function
			ofRectRounded(x, y, this->width, this->height, this->borderRadius);
		}
		else {
			ofDrawRectangle(x, y, this->width, this->height);
		}
	}
	

	UiElement::onRender(x, y);	//	Call onRender on this element's children
}

ofColor UiBox::getFillColor() {	
	return this->fillColor;	//	Simply return the fill color. Normal boxes don't have any hover and click logic, but allow elements based on them to re-use their rendering mechanism if they only need to change the colours by overriding this implementation.
}

UiBox::UiBox(float x, float y, float width, float height, ofColor fillColor) : UiElement(x, y, width, height) {
	this->fillColor = fillColor;
}

std::shared_ptr<UiBox> UiBox::make_frame(float x, float y, float width, float height) {
	auto box = make_shared<UiBox>(x,y, width,height);	//	Sets up the frame to look similar to Pokemon Gen 3's border. 
	box->borderColor = ofColor(0, 0, 255);		//	Make the border blue
	box->borderRadius = 5;
	box->borderWidth = 2;

	box->fillColor = ofColor(255, 255, 255);		//	Make background of the box white
	return box;
}