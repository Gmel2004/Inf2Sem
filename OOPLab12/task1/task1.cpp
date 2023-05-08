#include <iostream>
#include <set>
using namespace std;

void PushArithmeticMiddle(multiset<double>& m_multiset) {
	if (m_multiset.size() > 0) {
		double Sum = 0;
		for (auto i = m_multiset.begin(); i != m_multiset.end(); i++) {
			Sum += *i;
		}
		m_multiset.insert(Sum / m_multiset.size());
	}
	else {
		cout << "Множество пусто!\n";
	}
}

void EraseIfInRange(multiset<double>& m_multiset, const double BeginValue, const double EndValue) {
	auto i = m_multiset.begin();
	while (i != m_multiset.end()) {
		if (*i >= BeginValue && *i <= EndValue) {
			i = m_multiset.erase(i);
		}
		else {
			i++;
		}
	}
}

void PlusMinAndMax(multiset<double>& m_multiset) {
	if (m_multiset.size() > 0) {
		multiset<double> tmp_multiset = m_multiset;
		double MaxValue, MinValue;
		MaxValue = MinValue = *m_multiset.begin();

		for (auto i = m_multiset.begin(); i != m_multiset.end(); i++) {
			if (*i > MaxValue) {
				MaxValue = *i;
			}
			else if (*i < MinValue) {
				MinValue = *i;
			}
		}
		m_multiset = {};

		for (auto i = tmp_multiset.begin(); i != tmp_multiset.end(); i++) {
			double NewValue = *i + MaxValue + MinValue;
			m_multiset.insert(NewValue);
		}
		tmp_multiset = {};
	}
}

void ShowMultiset(const multiset<double>& m_multiset) {
	if (m_multiset.size() > 0) {
		for (auto i = m_multiset.begin(); i != m_multiset.end(); i++) {
			cout << *i << ' ';
		}
	}
	else {
		cout << "Множество пусто!";
	}
	cout << '\n';
}

int main() {

	system("chcp 1251 > NULL");

	multiset<double> a = { 1, 2, 3, 4, 5, 6, 7};

	cout << "Множество с дубликатами а:\n";
	ShowMultiset(a);

	cout << "Добавляем среднее арифмитическое множестава а в контейнер\n";
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