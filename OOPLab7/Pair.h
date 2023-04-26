#pragma once
#include <iostream>
using namespace std;

struct Pair {
	int first;
	double second;
	Pair() {
		first = 0;
		second = 0;
	}
	Pair(int f, double s) {
		first = f;
		second = s;
	}
	Pair(const Pair& t) {
		first = t.first;
		second = t.second;
	}
	~Pair() {}
	friend ostream& operator<<(ostream& out, const Pair& t) {
		return out << t.first << ":" << t.second << "\n";
	}
	friend istream& operator>>(istream& in, Pair& t) {
		return in >> t.first >> t.second;
	}
};