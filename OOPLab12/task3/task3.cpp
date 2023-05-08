#include <iostream>
#include "List.h"
using namespace std;

int main() {

	system("chcp 1251 > NULL");

	List<double> a;
	a.MakeMultiset(7);

	cout << "Множество с дубликатами а:\n";
	a.ShowMultiset();

	cout << "Добавляем среднее арифмитическое множества a в контейнер\n";
	a.PushArithmeticMiddle();
	cout << "Множество а:\n";
	a.ShowMultiset();

	cout << "Удаляем из множества а элементы, значения которых входят в диапазон от 2 до 3\n";
	a.EraseIfInRange(2, 3);
	cout << "Множество а:\n";
	a.ShowMultiset();

	cout << "К каждому элементу добавляем сумму минимального и максимального элементов контейнера\n";
	a.PlusMinAndMax();
	cout << "Множество а:\n";
	a.ShowMultiset();

	return 0;
}