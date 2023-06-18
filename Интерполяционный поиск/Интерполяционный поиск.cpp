#include <iostream>
using namespace std;

int main() {
	system("chcp 1251>NULL");
	int n;
	cout << "Введите размер массива, в котором требуется найти элемент: ";
	cin >> n;
	int* m = new int[n];
	for (int i = 0; i < n; i++) {
		cout << "Введите " << i + 1 << "-й элемент массива: ";
		cin >> m[i];
	}
	int key;
	cout << "Введите искомый элимент: ";
	cin >> key;
	int left = 0;
	int right = n - 1;
	int mid = 0;
	while (m[left] < key && m[right] > key) {
		mid = left + (key - m[left]) * (right - left) / (m[right] - m[left]);
		if (key < m[mid]) {
			right = mid - 1;
		}
		else if (m[mid] < key) {
			left = mid + 1;
		}
		else {
			left = mid;
		}
	}
	if (m[left] == key) {
		cout << "Искомое число распологается под индексом " << left << " в заданном массиве!";
	}
	else {
		cout << "Искомое число не найдено!";
	}
	delete[] m;
}