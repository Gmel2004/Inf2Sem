#pragma once
#pragma once
#include <string>
#include <iostream>
using namespace std;

class Error {
private:
	string code[4] = { "Ошибка: нельзя сместиться, выход за пределы списка!", "Ошибка: невозможно получить первый элемент пустого списка!", "Ошибка: невозможно получить последний элемент пустого списка!", "Ошибка: Индекс за пределами диапазона!" };
	string str;
public:
	Error(int i) {
		str = code[i];
	}
	void What() {
		cout << str << '\n';
	}
};