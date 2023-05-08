#include <iostream>
#include "List.h"
using namespace std;

int main() {

	system("chcp 1251 > NULL");

	List<double> a;
	a.MakeQueue(7);

	cout << "Очередь а:\n";
	a.ShowQueue();

	cout << "Добавляем среднее арифмитическое очереди a в контейнер\n";
	a.PushArithmeticMiddle();
	cout << "Очередь а:\n";
	a.ShowQueue();

	cout << "Удаляем из очереди а элементы, значения которых входят в диапазон от 2 до 3\n";
	a.EraseIfInRange(2, 3);
	cout << "Очередь а:\n";
	a.ShowQueue();

	cout << "К каждому элементу добавляем сумму минимального и максимального элементов контейнера\n";
	a.PlusMinAndMax();
	cout << "Очередь а:\n";
	a.ShowQueue();

	return 0;
}