#pragma once
#include <iostream>
#include <set>
using namespace std;

template <typename T>
class List {
private:
	multiset<T> m_multiset;
	int n = 0;
public:
	List() {};
	~List() {};
	void MakeMultiset(int count) {
		T a;
		for (size_t i = 0; i < count; i++) {
			cout << "Введите " << i + 1 << " элемент: ";
			cin >> a;
			m_multiset.insert(a);
		}
		n = count;
	};
	void ShowMultiset() {
		if (m_multiset.size() > 0) {
			for (auto i = m_multiset.begin(); i != m_multiset.end(); i++) {
				cout << *i << ' ';
			}
		}
		else {
			cout << "Множество пусто!";
		}
		cout << '\n';
	};
	void PushArithmeticMiddle() {
		if (m_multiset.size() > 0) {
			T Sum = 0;
			for (auto i = m_multiset.begin(); i != m_multiset.end(); i++) {
				Sum += *i;
			}
			m_multiset.insert(Sum / m_multiset.size());
		}
		else {
			cout << "Множество пусто!\n";
		}
	};
	void EraseIfInRange(const double BeginValue, const double EndValue) {
		auto i = m_multiset.begin();
		while (i != m_multiset.end()) {
			if (*i >= BeginValue && *i <= EndValue) {
				i = m_multiset.erase(i);
			}
			else {
				i++;
			}
		}
	};
	int size() {
		return n;
	};
	void PlusMinAndMax() {
		if (m_multiset.size() > 0) {
			multiset<T> tmp_multiset = m_multiset;
			T MaxValue, MinValue;
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
				T NewValue = *i + MaxValue + MinValue;
				m_multiset.insert(NewValue);
			}
			tmp_multiset = {};
		}
	}
};