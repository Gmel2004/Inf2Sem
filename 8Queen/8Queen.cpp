#include <iostream>
using namespace std;

const int Size = 8;
int Board[Size][Size];
int x, y;
bool NotFound = true;

void ShowBoard();

bool СurrentPositionFits(int a, int b);

void FindThePositionOfTheNextQueen(int a);

int main() {
	setlocale(LC_ALL, "Rus");
	cout << "Введите положение первого ферзя (x, y): ";
	cin >> x >> y;
	y = Size - y - 1;
	Board[y][x] = 1;
	FindThePositionOfTheNextQueen(0);
	return 0;
}

void FindThePositionOfTheNextQueen(int a)
{
	int i = 0;
	while (i < Size && NotFound) {
		if (СurrentPositionFits(a, i)) {
			Board[a][i] = 1;
			if (a + 1 == Size) {
				ShowBoard();
			}
			else {
				FindThePositionOfTheNextQueen(a + 1);
			}
			if (a != y || i != x) {
				Board[a][i] = 0;
			}
		}
		i++;
	}
}

bool СurrentPositionFits(int a, int b)
{
	for (int i = 0; i < Size; i++) {
		if (Board[i][b] && i != a) {
			return false;
		}
	}
	for (int i = 0; i < Size; i++) {
		if (Board[a][i] && i != b) {
			return false;
		}
	}
	for (int i = 1; i <= b && i <= a; i++) {
		if (Board[a - i][b - i]) {
			return false;
		}
	}
	for (int i = 1; i <= b && i + a < Size; i++) {
		if (Board[a + i][b - i]) {
			return false;
		}
	}
	for (int i = 1; i + b < Size && i + a < Size; i++) {
		if (Board[a + i][b + i]) {
			return false;
		}
	}
	for (int i = 1; i <= a && i + b < Size; i++) {
		if (Board[a - i][b + i]) {
			return false;
		}
	}
	return true;
}

void ShowBoard()
{
	NotFound = false;
	for (int a = 0; a < Size; a++) {
		for (int b = 0; b < Size; b++) {
			cout << (Board[a][b] ? "Q " : ". ");
		}
		cout << '\n';
	}
}
