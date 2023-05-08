#include <iostream>
#include "Pair.h"
using namespace std;
#include <list>

void PushArithmeticMiddle(list<Pair>& m_list) {
	if (m_list.size() > 0) {
		int SumFirst = 0;
		double SumSecond = 0;
		for (auto i = m_list.begin(); i != m_list.end(); i++) {
			SumFirst += (*i).GetFirst();
			SumSecond += (*i).GetSecond();
		}
		m_list.push_back(Pair(SumFirst / m_list.size(), SumSecond / m_list.size()));
	}
	else {
		cout << "Список пуст!\n";
	}
}

void EraseIfInRange(list<Pair>& m_list, const double BeginValue, const double EndValue) {
	auto i = m_list.begin();
	while (i != m_list.end()) {
		if (((*i).GetFirst() >= BeginValue && (*i).GetFirst() <= EndValue) || ((*i).GetSecond() >= BeginValue && (*i).GetSecond() <= EndValue)) {
			i = m_list.erase(i);
		}
		else {
			i++;
		}
	}
}

void PlusMinAndMax(list<Pair>& m_list) {
	if (m_list.size() > 0) {
		int MaxFirstValue, MinFirstValue;
		MaxFirstValue = MinFirstValue = (*m_list.begin()).GetFirst();
		double MaxSecondValue, MinSecondValue;
		MaxSecondValue = MinSecondValue = (*m_list.begin()).GetSecond();

		for (auto i = m_list.begin(); i != m_list.end(); i++) {
			if ((*i).GetFirst() > MaxFirstValue) {
				MaxFirstValue = (*i).GetFirst();
			}
			else if ((*i).GetFirst() < MinFirstValue) {
				MinFirstValue = (*i).GetFirst();
			}
			if ((*i).GetSecond() > MaxSecondValue) {
				MaxSecondValue = (*i).GetSecond();
			}
			else if ((*i).GetSecond() < MinSecondValue) {
				MinSecondValue = (*i).GetSecond();
			}
		}

		for (auto i = m_list.begin(); i != m_list.end(); i++) {
			*i + MaxFirstValue + MinFirstValue + MaxSecondValue + MinSecondValue;
		}
	}
}

void ShowList(const list<Pair>& m_list) {
	if (m_list.size() > 0) {
		for (auto i = m_list.begin(); i != m_list.end(); i++) {
			cout << *i << '\n';
		}
	}
	else {
		cout << "Список пуст!";
	}
	cout << '\n';
}

int main() {

	system("chcp 1251 > NULL");

	list<Pair> a = { Pair(6, 4), Pair(7, 9), Pair(2, 3.5) };

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