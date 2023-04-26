#pragma once	
#include <iostream>
#include <string>
#include "Object.h"
using namespace std;

class Person : public Object {
protected:
	string name;
	int age;
	friend istream& operator>>(istream& in, Person& p);		
	friend ostream& operator<<(ostream& out, const Person& p);
	Person& operator=(const Person&);
public:
	void Show();
	void setName(string);								
	void setAge(int);									
	string getName();									
	int getAge();											
	Person();											
	Person(string, int);						
	Person(const Person&);									
	~Person() {};
};