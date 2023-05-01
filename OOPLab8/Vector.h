#pragma once
#include "Object.h"
#include "event.h"
class Vector {
public:
	Vector(int);
	Vector();
	void HandleEvent(const TEvent& e);
	~Vector(void);
	void Add();
	void Del();
	void Show();
	int operator()();
protected:
	Object** beg;
	int size;
	int cur;
};