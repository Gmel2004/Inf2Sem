#pragma once	
#include <iostream>
#include <string>
using namespace std;

class Person {//Базовый класс
protected:
	string name;
	int age;
	friend istream& operator>>(istream& in, Person& p);		
	friend ostream& operator<<(ostream& out, const Person& p);
	Person& operator=(const Person&);
public:
	void setName(string);								
	void setAge(int);									
	string getName();									
	int getAge();											
	Person();											
	Person(string, int);						
	Person(const Person&);									
	~Person() {};
};