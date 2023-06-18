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
	int r = mx / 10 - mn / 10 + 1;
	int** buckets = new int* [r]{};
	for (int i = 0; i < r; i++) {
		buckets[i] = new int [n] {};
	}
	int* bucketSizes = new int[r] {};
	for (int i = 0; i < n; i++) {
		int bucketIndex = m[i] / 10 - mn / 10;
		buckets[bucketIndex][bucketSizes[bucketIndex]] = m[i];
		bucketSizes[bucketIndex]++;
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < bucketSizes[i] - 1; j++) {
			for (int k = bucketSizes[i] - 2; k >= j; k--) {
				if (buckets[i][k] > buckets[i][k + 1]) {
					int c = buckets[i][k];
					buckets[i][k] = buckets[i][k + 1];
					buckets[i][k + 1] = c;
				}
			}
		}
	}
	int k = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < bucketSizes[i]; j++) {
			m[k] = buckets[i][j];
			k++;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << m[i] << ' ';
	}
	delete[] bucketSizes;
	for (int i = 0; i < r; i++) {
		delete[] buckets[i];
	}
	delete[] buckets;
	return 0;
}