#pragma once

#include "ui/UiElement.h"
#include <ui/UiButton.h>
class MainScreen : public UiElement
{
public:
	//	If you need to be able to modify any of the elements while the program is running I recommend defining them as properties here. Every element should be stored inside a shared_ptr, meaning that its type is std::shared_ptr<T> where T is the element's type.
	std::shared_ptr<UiButton> btn;

	MainScreen();
};

