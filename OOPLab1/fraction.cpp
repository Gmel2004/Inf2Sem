#include <iostream>
#include "fraction.h"
#include <cmath>
using namespace std;

void fraction::Init(double F, int S) {
	first = F;
	second = S;
}

void fraction::Show() {
	cout << "First: " << first << '\n';
	cout << "Second: " << second << '\n';
}

void fraction::Read() {
	cin >> first >> second;
}

double fraction::Element(int j) {
	return first * pow(second, j);
}