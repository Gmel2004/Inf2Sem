#include <iostream>
#include <cmath>
using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");
	double subst = 1;
	double a, b, e, x0, x1;
	cin >> a >> b >> e;
	bool solution = true;
	if (2 * a - 6 < 1) {
		x0 = a;
	}
	else if (2 * b - 6 < 1) {
		x0 = b;
	}
	else {
		bool solution = false;
		cout << "Измените диапазон";
	}
	if (solution) {
		bool flag = true;
		int k = 0;
		do {
			k++;
			x1 = (x0 * x0 + 4) / 6;
			subst = abs(x1 - x0);
			x0 = x1;
		} while (subst > e && flag);
		cout << "Решение: " << x1 << '\n' << "Найдено за " << k << " итераций цикла" << '\n';
	}
	return 0;
}
