#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	system("chcp 1251>NULL");
	string str;
	cout << "Введите предложение (длина предложения не должна превышать 100 символов!):\n";
	getline(cin, str);
	const int begin_y = -2;
	const int end_y = 2;
	int width = str.length();
	const int size = end_y - begin_y + 1;
	const int scale_y = 1;// масшатб по оси Y
	int m[(size - 1) * scale_y + 1][100] = {};
	for (int x = 0; x < width; x++) {
		double y = 2 * sin(1.0 / 2 * x) - begin_y;
		int y1 = (size - round(y) - 1) * scale_y;
		m[y1][x] = 1;
	}
	cout << '\n';
	for (int y = 0; y <= (size - 1) * scale_y; y++) {
		for (int x = 0; x < width; x++) {
			cout << (m[y][x] ? str[x] : ' ');
		}
		cout << '\n';
	}
	return 0;
}