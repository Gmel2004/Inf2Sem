#pragma once
#include "Event.h"
class Object {
public:
	Object(void) {};
	virtual void Show() = 0;
	virtual void Input() = 0;
	virtual ~Object(void) {};
	virtual void HandleEvent(const TEvent& e) = 0;
};