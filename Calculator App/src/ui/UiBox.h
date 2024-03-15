#pragma once
#include "UiElement.h"
#include "ofMain.h"

class UiBox : public UiElement
{
public:
	ofColor fillColor;
	ofColor borderColor = ofColor(0,0,0);
	float borderRadius = 0;
	float borderWidth = 0;

	UiBox(float x, float y, float width, float height, ofColor fillColor = ofColor(0,0,0));
	void onRender(float x, float y);

	virtual ofColor getFillColor();

	/// <summary>
	/// Renders a Pokemon Gen 3 like frame. The actual games had a more complex box than this, but they also rendered their frames through tiles, so they had more flexibility over how each frame looked.
	/// </summary>
	/// <param name="x">X coordinate of the box</param>
	/// <param name="y">Y coordinate of the box</param>
	/// <param name="width">Width of the box</param>
	/// <param name="height">Height of the box</param>
	/// <returns></returns>
	static std::shared_ptr<UiBox> make_frame(float x, float y, float width, float height);
};

