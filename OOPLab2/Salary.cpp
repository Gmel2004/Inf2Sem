#include <iostream>
#include <string>
#include "Salary.h"
using namespace std;

Salary::Salary() {
	cout << "Вызов конструктора без параметров" << '\n';
	name = "";
	reward = 0;
	percent = 0;
}

Salary::Salary(string s, double d, int i) {
	cout << "Вызов конструктора с параметрами" << '\n';
	name = s; reward = d; percent = i;
}

Salary::Salary(const Salary& t) {
	cout << "Вызов конструктора копирования" << '\n';
	name = t.name;
	reward = t.reward;
	percent = t.percent;
}

Salary::~Salary() {
	cout << "Вызов деструктора" << '\n';
}

void Salary::setName(string name) {
	this->name = name;
}

void Salary::setReward(double reward) {
	this->reward = reward;
}

void Salary::setPercent(int percent) {
	percent = percent;
}

string Salary::getName() {
	return name;
}

double Salary::getReward() {
	return reward;
}

int Salary::getPercent() {
	return percent;
}

void Salary::show() {
	cout << "Name: " << name << '\n';
	cout << "Reward: " << reward << '\n';
	cout << "Percent: " << percent << '\n';
}