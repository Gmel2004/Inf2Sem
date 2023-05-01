#include "Print.h"
#include "Object.h"
#include "Event.h"
#include <iostream>
using namespace std;

void Print::HandleEvent(const TEvent& e) {
	if (e.what == evMessage) {
		switch (e.command) {
		case cmGet:
			cout << "Название: " << Get_name() << '\n';
			break;
		}
	}
}
Print::Print() {
	author = "";
	name = "";
}
Print::Print(string m_author, string m_name) {
	author = author;
	name = m_name;
}
Print::Print(const Print& Print) {
	author = Print.author;
	name = Print.name;
}
void Print::Set_name(string m_name) {
	name = m_name;
}
void Print::Set_author(string m_name) {
	author = m_name;
}
Print& Print::operator=(const Print& c) {
	if (&c != this) {
		author = c.author;
		name = c.name;
	}
	return *this;
}
void Print::Show() {
	cout << "Автор : " << author << '\n';
	cout << "Название : " << name << "\n\n";
}
void Print::Input() {
	cout << "Введите данные в формате:\nАвтор Название\n";
	cin >> author >> name;
}