#include <iostream>
#include "List.h"
using namespace std;

template <class T>
void PushArithmeticMiddle(List<T>& m_List) {
	if (m_List.length() > 0) {
		T Sum = 0;
		for (Iterator<T> i = m_List.begin(); *i != NULL; ++i) {
			Sum += (*i)->key;
		}
		m_List << (Sum / m_List.length());
	}
	else {
		cout << "Список пуст!\n";
	}
}

template <class T>
void EraseIfInRange(List<T>& m_List, const T BeginValue, const T EndValue) {
	Iterator<T> i = m_List.begin();
	while (*i != NULL) {
		if ((*i)->key >= BeginValue && (*i)->key <= EndValue) {
			 i = m_List.erase(i);
		}
		else {
			++i;
		}
	}
}

template <class T>
void PlusMinAndMax(List<T>& m_List) {
	if (m_List.length() > 0) {
		T MaxValue, MinValue;
		MaxValue = MinValue = (*(m_List.begin()))->key;

		for (Iterator<T> i = m_List.begin(); *i != NULL; ++i) {
			if ((*i)->key > MaxValue) {
				MaxValue = (*i)->key;
			}
			else if ((*i)->key < MinValue) {
				MinValue = (*i)->key;
			}
		}

		for (Iterator<T> i = m_List.begin(); *i != NULL; ++i) {
			i + MaxValue + MinValue;
		}
	}
}

template <class T>
void ShowList(List<T>& m_List) {
	if (m_List.length() > 0) {
		for (Iterator<T> i = m_List.begin(); *i != NULL; ++i) {
			cout << (*i)->key << ' ';
		}
	}
	else {
		cout << "Список пуст!";
	}
	cout << '\n';
}

int main() {

	system("chcp 1251 > NULL");

	List<double> a;
	for (double i : { 1, 2, 3, 4, 5, 6, 7 }) {
		a << i;
	}
	cout << "Список а:\n";
	ShowList(a);

	cout << "Добавляем среднее арифмитическое списка а в конец контейнера\n";
	PushArithmeticMiddle(a);
	cout << "Список а:\n";
	ShowList(a);

	cout << "Удаляем из списка а элементы, значения которых входят в диапазон от 2 до 3\n";
	EraseIfInRange(a, 2.0, 3.0);
	cout << "Список а:\n";
	ShowList(a);

	cout << "К каждому элементу добавляем сумму минимального и максимального элементов контейнера\n";
	PlusMinAndMax(a);
	cout << "Список а:\n";
	ShowList(a);

	return 0;
}