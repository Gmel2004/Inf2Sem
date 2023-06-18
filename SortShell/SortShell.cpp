#include <iostream>
using namespace std;

int main() {
	const int n = 10;
	int m[n] = { 45, 96, 73, 43, 64, 12, 90, 88, 23, 45 };
	for (int l = n / 2; l > 0; l /= 2) {
		for (int i = 0; i < n - l; i++) {
			for (int j = i; j >= 0 && m[j] > m[j + l]; j--) {
				int c = m[j];
				m[j] = m[j + l];
				m[j + l] = c;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << m[i] << ' ';
	}
	return 0;
}