#include "Person.h"

Person::Person() {
	this->name = "";
	this->age = 0;
}
Person::Person(string name, int age) {
	this->name = name;
	this->age = age;
}
Person::Person(const Person& copied) {
	age = copied.age;
	name = copied.name;
}
istream& operator>>(istream& in, Person& p) {
	cout << "Введите данные в формате:\nимя возвраст\n";
	return (in >> p.name >> p.age);
}
ostream& operator<<(ostream& out, const Person& p) {
	return (out << p.name << ' ' << p.age << '\n');
}
void Person::setName(string name) {
	this->name = name;
}
void Person::setAge(int age) {
	this->age = age;
}
string Person::getName() {
	return name;
}
int Person::getAge() {
	return age;
}
Person& Person::operator=(const Person& m_person) {//перегрузка оператора присваивания
	if (&m_person != this) {
		name = m_person.name;
		age = m_person.age;
	}
	return *this;
}