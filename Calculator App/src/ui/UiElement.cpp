#include "UiElement.h"
#include <ofApp.h>

long UiElement::uniqueIdCounter = 0;

bool UiElement::isInBounds(float relX, float relY) {	//	Take coorditanes of a point relative to the top left corner of this element, and determine if the given point is inside this element or not
	return relX >= 0 && relY >= 0 && relX < this->width && relY < this->height;
}
void UiElement::onRender(float x, float y) {
	for (auto child : this->Children) {	//	Call onRender on all the child elements
		child->onRender(x + child->xPosition, y + child->yPosition);
	}
}
void UiElement::onUpdate() {
	for (auto child : this->Children) {	//	Call onUpdate on all the child elements
		child->onUpdate();
	}
}

UiElement::UiElement(float x, float y, float width, float height) {
	this->width = width;	//	Save the arguments of this constructor as fields of this class.
	this->height = height;
	this->xPosition = x;
	this->yPosition = y;

	this->uniqueId = uniqueIdCounter++;	//	Generates a unique id for this element. I have done the maths, and even if this program created 1000 elements per second (1 every millisecond), the computer running this program will decompose before this counter overflows (time for e-waste to decompose is somewhere between 50 years and 1 million years, and this will take aproximately 584 million years to overflow). This means that we can safely assume this id is going to be unique.
}

/// <summary>
/// Checks if this element or one of its children is being hovered over.
/// </summary>
/// <returns></returns>
bool UiElement::isHoveredOver() {
	if (ofApp::hoveredElement.expired()) return false;	//	If the pointer has expired then that means the screen has changed, or the hovered over element somehow went out of scope. Either way we need to update the currently hovered over element, so we can return false for now.

	auto fullPointer = ofApp::hoveredElement.lock();	//	Gets a shared pointer to the element which is being hovered over

	if (fullPointer->uniqueId == this->uniqueId) return true;
	for (auto child : this->Children) {
		if (child->isHoveredOver()) return true;	//	Calls itself on this element's children. If one of the children is being hovered over, then this element is as well.
	}
	return false;
}

bool UiElement::onClick(float x, float y) {
	for (auto child : this->Children) {	//Go through all the child elements in order to determine which one handled the click
		float relX = x - child->xPosition;
		float relY = y - child->yPosition;
		if (child->isInBounds(relX, relY) && child->onClick(relX, relY)) return true;
	}
	return false;
}
void UiElement::centerHorizontallyOnScreen() {
	this->xPosition = ofGetWidth() / 2 - this->width / 2;
}

void UiElement::centerHorizontallyInParent(std::shared_ptr<UiElement> parent) {
	this->xPosition = parent->width / 2 - this->width / 2;
}
