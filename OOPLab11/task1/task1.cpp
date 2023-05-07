#include <iostream>
#include <list>
using namespace std;

void PushArithmeticMiddle(list<double>& m_list) {
	double Sum = 0;
	for (auto i = m_list.begin(); i != m_list.end(); i++) {
		Sum += *i;
	}
	m_list.push_back(Sum / m_list.size());
}

void EraseIfInRange(list<double>& m_list, const double BeginValue, const double EndValue) {
	for (auto i = m_list.begin(); i != m_list.end(); i++) {
		if (*i >= BeginValue && *i <= EndValue) {
			i = m_list.erase(i);
			i--;
		}
	}
}

void PlusMinAndMax(list<double>& m_list) {
	double MaxValue, MinValue;
	MaxValue = MinValue = *m_list.begin();

	for (auto i = m_list.begin(); i != m_list.end(); i++) {
		if (*i > MaxValue) {
			MaxValue = *i;
		}
		else if (*i < MinValue) {
			MinValue = *i;
		}
	}

	for (auto i = m_list.begin(); i != m_list.end(); i++) {
		*i += MaxValue + MinValue;
	}
}

void ShowList(const list<double>& m_list) {
	for (auto i = m_list.begin(); i != m_list.end(); i++) {
		cout << *i << ' ';
	}
	cout << '\n';
}

int main() {

	system("chcp 1251 > NULL");

	list<double> a = { 1, 2, 3, 4, 5, 6, 7 };

	cout << "Список а:\n";
	ShowList(a);

	cout << "Добавляем среднее арифмитическое списка а в конец контейнера\n";
	PushArithmeticMiddle(a);
	cout << "Список а:\n";
	ShowList(a);

	cout << "Удаляем из списка а элементы, значения которых входят в диапазон от 2 до 3\n";
	EraseIfInRange(a, 2, 3);
	cout << "Список а:\n";
	ShowList(a);

	cout << "К каждому элементу добавляем сумму минимального и максимального элементов контейнера\n";
	PlusMinAndMax(a);
	cout << "Список а:\n";
	ShowList(a);

	return 0;
}