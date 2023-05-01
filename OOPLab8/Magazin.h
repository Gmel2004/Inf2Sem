#pragma once
#include "Print.h"
class Magazin : public Print {
public:
	Magazin();
	~Magazin() {};
	void Show();
	void Input();
	Magazin(string, string, int);
	Magazin(const Magazin&);
	int Get_pages() {
		return pages;
	}
	void Set_pages(int);
	Magazin& operator=(const Magazin&);
protected:
	int pages;
};