#pragma once
#include <iostream>
using namespace std;
#include <fstream>

class Pair {
	int first;
	double second;
public:
	friend istream& operator>>(istream& in, Pair& p);
	friend ostream& operator<<(ostream& out, const Pair& p);
	Pair(int, double);
	Pair();
	Pair(const Pair&);
	~Pair();
	Pair& operator=(const Pair&);
	Pair operator-(const Pair&);
	Pair& operator+(int);
	Pair& operator+(double);
	Pair& operator++();
	Pair operator++(int);
	friend fstream& operator >> (fstream& fin, Pair& m_Pair);
	friend fstream& operator << (fstream& fout, const Pair& m_Pair);
	bool operator>=(int value);
	void SetFirst(int m_first);
	void SetSecond(double m_second);
	int GetFirst() const;
	double GetSecond() const;
};