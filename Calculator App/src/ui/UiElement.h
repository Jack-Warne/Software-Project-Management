#pragma once
#include <memory>
#include <vector>

class UiElement
{
private:
	static long uniqueIdCounter;
public:
	std::vector<std::shared_ptr<UiElement>> Children;	//	Stores child elements of this element
	
	float xPosition;
	float yPosition;
	float width;
	float height;
	
	long uniqueId;

	/// <summary>
	/// Creates this UiElement at the given position, and with the given size.
	/// </summary>
	/// <param name="x">X position relative to this element's parent</param>
	/// <param name="y">Y position relative to this element's parent</param>
	/// <param name="width">Width of this element</param>
	/// <param name="height">Height of this element</param>
	UiElement(float x, float y, float width, float height);

	/// <summary>
	/// Renders this element. Base implementation also calls this on this element's children.
	/// </summary>
	/// <param name="x">X coordinate of this element relative to the window</param>
	/// <param name="y">Y coordinate of this element relative to the window</param>
	virtual void onRender(float x, float y);

	/// <summary>
	/// Updates this element. Base implementation also calls this on this element's children.
	/// </summary>
	virtual void onUpdate();

	/// <summary>
	/// Called when this element has been clicked. 
	/// </summary>
	/// <param name="x">X coordinate of the clicked position relative to this element</param>
	/// <param name="y">Y coordinate of the clicked position relative to this element</param>
	/// <returns>True if this element has handled the event, false otherwise. If false is returned this event might be propagated throughout other elements.</returns>
	virtual bool onClick(float x, float y);

	/// <summary>
	/// Takes coorditanes of a point relative to the top left corner of this element, and determines if the given point is inside this element or not
	/// </summary>
	/// <param name="relX">X coordinate of the point</param>
	/// <param name="relY">Y coordinate of the point</param>
	/// <returns>True if the given point is inside this element, false otherwise.</returns>
	bool isInBounds(float relX, float relY);

	/// <summary>
	/// Takes a shared pointer to a UI Element and adds it as a child of this element. Automatically casts the pointer to UIElement if needed.
	/// </summary>
	/// <typeparam name="T">Type of the UiElement. Has to extend UiElement.</typeparam>
	/// <param name="new_child">shared pointer to the child element to be added.</param>
	/// <returns>The same pointer to the child it was given. Useful for chaining method calls on the child element.</returns>
	template<class T> std::shared_ptr<T> addChild(std::shared_ptr<T> new_child) {	//	Templates have to be implemented in header files due to how c++ compilers work.
		static_assert(std::is_base_of_v<UiElement, T>, "Class needs to extend UiElement");		//	Throw a compile time error if the element we are trying to add is not a ui element
		std::shared_ptr<UiElement> child = std::static_pointer_cast<UiElement, T>(new_child);	//	Casts the shared pointer to a UiElement Shared Pointer
		this->Children.push_back(child);
		return new_child;
	}
	/// <summary>
	/// Checks if this element or its children are being hovered over.
	/// </summary>
	/// <returns>True if this elemnt or its child is being hovered over, false otherwise</returns>
	bool isHoveredOver();

	/// <summary>
	/// Centers this element on the screen horizontally by calculating its x position from the window's width and this element's width.
	/// </summary>
	void centerHorizontallyOnScreen();

	/// <summary>
	/// Centers this element on the screen horizontally by calculating its x position from the parent's width and this element's width.
	/// </summary>
	void centerHorizontallyInParent(std::shared_ptr<UiElement> parent);
};

