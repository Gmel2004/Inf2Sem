#include "fraction.h"
#include <iostream>
using namespace std;

fraction makeFraction(double, int);

int main() {
	system("chcp 1251 > NULL");
	//
	fraction A;
	A.Init(3.0, 2);
	A.Show();
	cout << A.Element(5) << '\n';

	/*другие способы:
	
	fraction B;
	B.Read();
	B.Show();
	int j1;
	cout << "Введите номер какого элемента вы хотите получить " << '\n';
	cout << "j1: ";
	cin >> j1;
	cout << B.Element(j1) << '\n';
	
	fraction* X = new fraction;
	X->Init(2.0, 5);
	X->Show();

	fraction mas[3];
	for (int i = 0; i < 3; i++) {
		mas[i].Read();
	}
	for (int i = 0; i < 3; i++) {
		mas[i].Show();
	}
	for (int i = 0; i < 3; i++) {
		cout << " Степень? " << '\n';
		cout << "j:";
		cin >> j1;
		mas[i].Element(j1);
	}
	
	fraction* p_mas = new fraction[3];
	for (int i = 0; i < 3; i++) {
		p_mas[i].Read();
	}
	for (int i = 0; i < 3; i++) {
		p_mas[i].Show();
	}
	for (int i = 0; i < 3; i++) {
		cout << " Степень? " << '\n';
		cout << "j:";
		cin >> j1;
		cout << mas[i].Element(j1) << '\n';
	}
	
	double y; int z;
	cout << "first:";
	cin >> y;
	cout << "second:";
	cin >> z;
	fraction F = makeFraction(y, z);
	F.Show();
	cout << F.Element(j1) << '\n';*/
	return 0;
}

fraction makeFraction(double f, int s) {
	fraction t;
	t.Init(f, s);
	return t;
}