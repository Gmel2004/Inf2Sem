#include <iostream>
using namespace std;

int main() {
	const int n = 10;
	int m[n] = { 45, 96, 73, 43, 64, 12, 90, 88, 23, 45 };
	int mx = m[0];
	int mn = m[0];
	for (int i = 0; i < n; i++) {
		if (m[i] > mx) {
			mx = m[i];
		}
		else if (m[i] < mn) {
			mn = m[i];
		}
	}
	int r = mx - mn + 1;
	int* dm = new int[r]{};
	for (int i = 0; i < n; i++) {
		dm[m[i] - mn] += 1;
	}
	int k = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < dm[i]; j++) {
			m[k] = i + mn;
			k++;
		}
	}
	delete [] dm;
	for (int i = 0; i < n; i++) {
		cout << m[i] << ' ';
	}
	return 0;
}