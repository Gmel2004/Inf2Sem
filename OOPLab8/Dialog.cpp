#include "Dialog.h"
#include "Event.h"
#include "Vector.h"
#include <iostream>
using namespace std;

Dialog::Dialog() : Vector() {
	EndState = 0;
}

Dialog::~Dialog(void) {}

void Dialog::GetEvent(TEvent& Event) {
	string OpInt = "+m-szq";
	string s;
	string param;
	char code;
	cout << '>';
	cin >> s; code = s[0];
	if (OpInt.find(code) >= 0) {
		Event.what = evMessage;
		switch (code) {
		case 'm':Event.command = cmMake; break;
		case '+': Event.command = cmAdd; break;
		case '-': Event.command = cmDel; break;
		case 's': Event.command = cmShow; break;
		case'q': Event.command = cmQuit; break;
		case 'z':Event.command = cmGet; break;
		}
	}
	else Event.what = evNothing;
}

void Dialog::Execute() {
	TEvent Event;
	do {
		EndState = 0;
		GetEvent(Event);
		HandleEvent(Event);
	} while (Valid());
}

bool Dialog::Valid() { return (EndState == 0); }

void Dialog::ClearEvent(TEvent& Event) {
	Event.what = evNothing;
}
void Dialog::EndExec() {
	EndState = 1;
}

void Dialog::HandleEvent(TEvent& Event) {
	if (Event.what == evMessage) {
		switch (Event.command) {
		case cmMake:
			cout << "Введите размер: ";
			cin >> size;
			beg = new Object * [size];
			cur = 0;
			ClearEvent(Event);
			break;
		case cmAdd:
			Add();
			ClearEvent(Event);
			break;
		case cmDel:Del();
			ClearEvent(Event);
			break;
		case cmShow:Show();
			ClearEvent(Event);
			break;
		case cmQuit:EndExec();
			ClearEvent(Event);
			break;
		default:
			Vector::HandleEvent(Event);
			break;
		};
	};
}