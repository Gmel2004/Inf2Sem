#include "Vector.h"
#include "Magazin.h"
#include "Event.h"
#include <iostream>
using namespace std;


void Vector::HandleEvent(const TEvent& e) {
	if (e.what == evMessage) {
		Object** p = beg;
		for (int i = 0; i < cur; i++) {
			(*p)->HandleEvent(e);
			p++;
		}
	}
}


Vector::~Vector() {
	if (beg != 0) {
		delete[] beg;
	}
	beg = 0;
}

Vector::Vector(int n)
{
	beg = new Object * [n];
	cur = 0;
	size = n;
}

Vector::Vector() {
	beg = NULL;
	cur = -1;
	size = 0;
}

void Vector::Add() {
	Object* p;
	cout << "1.Печтное издание\n";
	cout << "2.Журнал\n";
	int y;
	cin >> y;
	if (y == 1) {
		Print* a = new (Print);
		a->Input();
		p = a;
		if (cur < size) {
			beg[cur] = p;
			cur++;
		}
	}
	else if (y == 2) {
		Magazin* b = new Magazin;
		b->Input();
		p = b;
		if (cur < size) {
			beg[cur] = p;
			cur++;
		}
	}
	else return;
}

void Vector::Show() {
	if (cur == 0) {
		cout << "Пусто\n";
	}
	Object** p = beg;
	for (int i = 0; i < cur; i++) {
		(*p)->Show();
		p++;
	}

}

int Vector::operator ()() {
	return cur;
}

void Vector::Del() {
	if (cur == 0) {
		return;
	}
	cur--;
}