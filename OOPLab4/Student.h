#pragma once
#include <iostream>
#include "Person.h"
using namespace std;

class Student : public Person {
private:
	string subject;
	int mark;
public:
	Student();
	Student(string, int, string, int);
	Student(const Student&);
	void setSubject(string);
	void setMark(int);
	string getSubject();
	int getMark();
	void BadMark();
	friend istream& operator>>(istream&, Student&);
	friend ostream& operator<<(ostream&, const Student&);
	Student& operator=(const Student&);
};