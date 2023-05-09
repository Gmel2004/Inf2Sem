#include <iostream>
#include "Pair.h"
using namespace std;
#include <set>

void PushArithmeticMiddle(multiset<Pair>& m_multiset) {
	if (m_multiset.size() > 0) {
		int SumFirst = 0;
		double SumSecond = 0;
		for (auto i = m_multiset.begin(); i != m_multiset.end(); i++) {
			SumFirst += (*i).GetFirst();
			SumSecond += (*i).GetSecond();
		}
		m_multiset.insert(Pair(SumFirst / m_multiset.size(), SumSecond / m_multiset.size()));
	}
	else {
		cout << "Множество пусто!\n";
	}
}

void EraseIfInRange(multiset<Pair>& m_multiset, const double BeginValue, const double EndValue) {
	auto i = m_multiset.begin();
	while (i != m_multiset.end()) {
		if (((*i).GetFirst() >= BeginValue && (*i).GetFirst() <= EndValue) || ((*i).GetSecond() >= BeginValue && (*i).GetSecond() <= EndValue)) {
			i = m_multiset.erase(i);
		}
		else {
			i++;
		}
	}
}

void PlusMinAndMax(multiset<Pair>& m_multiset) {
	if (m_multiset.size() > 0) {
		multiset<Pair> tmp_multiset;
		Pair MaxValue = *(m_multiset.begin());
		Pair MinValue = *(m_multiset.begin());

		for (auto i = m_multiset.begin(); i != m_multiset.end(); i++) {
			if (MaxValue < *i) {
				MaxValue = *i;
			}
			else if (*i < MinValue) {
				MinValue = *i;
			}
		}

		for (auto i = m_multiset.begin(); i != m_multiset.end(); i++) {
			Pair c = (*i);
			c + MaxValue + MinValue;
			tmp_multiset.insert(c);
		}
		m_multiset = tmp_multiset;
	}
}

void ShowMultiset(const multiset<Pair>& m_multiset) {
	if (m_multiset.size() > 0) {
		for (auto i = m_multiset.begin(); i != m_multiset.end(); i++) {
			cout << *i << '\n';
		}
	}
	else {
		cout << "Множество пусто!";
	}
	cout << '\n';
}

int main() {

	system("chcp 1251 > NULL");

	multiset<Pair> a = { Pair(6, 4), Pair(7, 9), Pair(2, 3.5) };

	cout << "Множество с дубликатами а:\n";
	ShowMultiset(a);

	cout << "Добавляем среднее арифмитическое множества а в контейнер\n";
	PushArithmeticMiddle(a);
	cout << "Множество а:\n";
	ShowMultiset(a);

	cout << "Удаляем из множества а элементы, значения которых входят в диапазон от 2 до 3\n";
	EraseIfInRange(a, 2, 3);
	cout << "Множество а:\n";
	ShowMultiset(a);

	cout << "К каждому элементу добавляем сумму минимального и максимального элементов контейнера\n";
	PlusMinAndMax(a);
	cout << "Множество а:\n";
	ShowMultiset(a);

	return 0;
}