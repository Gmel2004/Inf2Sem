#include <iostream>
#include "Object.h"
#include "Person.h"
#include "Student.h"
#include "Vector.h"
using namespace std;

int main() {
	system("chcp 1251 > NULL");
	Vector v(5);
	Person p;
	cin >> p;
	Student s;
	cin >> s;
	s.BadMark();
	Object* o = &p;
	v.Add(o);
	o = &s;
	v.Add(o);
	cout << v;
	return 0;
}
