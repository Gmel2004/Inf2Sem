#include <iostream>
#include <string>
#include "Salary.h"
using namespace std;

Salary makeStaff();
void print(Salary);

int main() {
	system("chcp 1251 > NULL");

	Salary s1;		// конструктор без параметров
	s1.show();

	Salary s2("Антонов Дмитрий Сергеевич", 200054, 45);	// Конструктор с параметрами
	s2.show();

	Salary s3 = s2;			// Конструктор копирования
	print(s3);				// конструктор копирования 
	// Вызов деструктора (так как в параметрах функции не ссылка)
	Salary s4 = makeStaff();
	s4.show();

	// Деструктор вызывается для каждого объекта

	return 0;
}

Salary makeStaff() {
	string name;
	double r;
	int i;
	cout << "Введите ФИО сотрудника:" << '\n';
	getline(cin, name);
	cout << "Зарплата:" << '\n';
	cin >> r;
	cout << "Премия%:" << '\n';
	cin >> i;

	Salary t(name, r, i);			// конструктор с параметрами
	return t;						// конструктор копирования, затем деструктор, так как заканчивается время жизни
}

void print(Salary t) {
	t.show();
}