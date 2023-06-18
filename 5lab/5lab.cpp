#include <iostream>
using namespace std;

int main() {
	const int size = 3;
	int m[size][size] = { {1,2,3}, {4, 5, 2}, {7, 3, 5} };
	int mn = m[0][size - 1];
	for (int i = 1; i < size; i++) {
		mn = min(mn, m[i][size - 1]);
	}
	int i = size - 2;
	bool Yes = true;
	while (i >= 0 && Yes) {
		int t = mn;
		for (int j = 0; j < size; j++) {
			if (t < m[j][i] && (mn > m[j][i] || mn == t)) {
				mn = m[j][i];
			}
		}
		if (mn == t) {
			Yes = false;
		}
		i--;
	}
	if (Yes) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
	return 0;
}
