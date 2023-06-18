#include <iostream>
#include <string>
using namespace std;

int main() {
	system("chcp 1251>NULL");
	string s, subS;
	cout << "Введите строку в которой требуется найти образ: ";
	cin >> s;
	cout << "Введите образ: ";
	cin >> subS;
	bool find = false;
	for (int i = 0; i < s.length() && !find; i++) {
		if (i + subS.length() <= s.length()) {
			find = true;
			for (int j = i; j < i + subS.length(); j++) {
				if (s[j] != subS[j-i]) {
					find = false;
				}
			}
			if (find) {
				cout << "Образ начинается с " << i << " индекса";
			}
		}
	}
	if (!find) {
		cout << "Строка не содержит данный образ!";
	}
	return 0;
}
