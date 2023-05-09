#include "Pair.h"
#include <iostream>
#include <list>
#include <numeric>
#include <algorithm>
using namespace std;

void PushArithmeticMiddle(list<Pair>& m_list) {
	if (m_list.size() > 0) {
		Pair Middle = accumulate(m_list.begin(), m_list.end(), Pair(0, 0));
		Middle.SetFirst(Middle.GetFirst() / m_list.size());
		Middle.SetSecond(Middle.GetSecond() / m_list.size());
		m_list.push_back(Middle);
	}
	else {
		cout << "Список пуст!\n";
	}
}

void EraseIfInRange(list<Pair>& m_list, const double BeginValue, const double EndValue) {
	auto i = remove_if(m_list.begin(), m_list.end(), [BeginValue, EndValue](Pair p) {
		return ((BeginValue <= p.GetFirst() && p.GetFirst() <= EndValue) || (BeginValue <= p.GetSecond() && p.GetSecond() <= EndValue));
	});
	m_list.erase(i, m_list.end());
}

void PlusMinAndMax(list<Pair>& m_list) {
	if (m_list.size() > 0) {
		Pair max = *max_element(m_list.begin(), m_list.end());
		Pair min = *min_element(m_list.begin(), m_list.end());
		for (Pair& c : m_list) {
			c + max + min;
		}
	}
}

void ShowList(const list<Pair>& m_list) {
	if (m_list.size() > 0) {
		for_each(m_list.begin(), m_list.end(), [](Pair p) {
			cout << p << '\n';
		});
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