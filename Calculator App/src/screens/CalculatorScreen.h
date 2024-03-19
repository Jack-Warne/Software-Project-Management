#pragma once


#include "ui/UiElement.h"

/// <summary>
/// Abstract class which defines methods common accross the different screens on the calculator. In this context a screen means the group of UiElements currently displayed on screen, not the calculator's screen
/// </summary>
class CalculatorScreen : public UiElement
{
public:
	CalculatorScreen();
	virtual void update_display(bool isHex) = 0;
};

