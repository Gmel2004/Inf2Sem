#include "Object.h"
#include <iostream>
using namespace std;

class Print :public Object {
public:
	Print();
	virtual ~Print() {};
	void Show();
	void Input();
	Print(string, string);
	Print(const Print&);

	string Get_author() {
		return author; 
	}
	string Get_name() {
		return name;
	}

	void Set_author(string);
	void Set_name(string);
	Print& operator=(const Print&);
	void HandleEvent(const TEvent& e);
protected:
	string author, name;
};