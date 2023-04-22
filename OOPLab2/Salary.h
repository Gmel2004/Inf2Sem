#pragma once
#include <string>
using namespace std;

class Salary {
	string name;
	double reward;
	int percent;

public:
	Salary();
	Salary(string, double, int);
	Salary(const Salary&);
	~Salary();

	void setName(string);
	void setReward(double);
	void setPercent(int);

	string getName();
	double getReward();
	int getPercent();

	void show();
};