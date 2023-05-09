#include <map>
#include <iostream>
#include <list>
#include <numeric>
#include <algorithm>
using namespace std;

void PushArithmeticMiddle(map <int, int>& m_map) {
	if (m_map.size() > 0) {
		int MaxKey = max_element(m_map.begin(), m_map.end(), [](const auto& p1, const auto& p2) {
			return p1.first < p2.first;
		})->first + 1;
		int MiddleSecond = accumulate(m_map.begin(), m_map.end(), 0, [](int value, const auto& p) {
			return value + p.second;
		}) / m_map.size();
		m_map[MaxKey] = MiddleSecond;
		m_map.insert({ MaxKey, MiddleSecond });
	}
	else {
		cout << "Словарь пуст!\n";
	}
}

void EraseIfInRange(map <int, int>& m_map, const int BeginValue, const int EndValue) {
	for (auto p = m_map.begin(); p != m_map.end();) {
		if (BeginValue <= (*p).second && (*p).second <= EndValue) {
			p = m_map.erase(p);
		}
		else {
			p++;
		}
	};
}

void PlusMinAndMax(map <int, int>& m_map) {
	if (m_map.size() > 0) {
		int MaxValue = max_element(m_map.begin(), m_map.end(), [](const auto& p1, const auto& p2) {
			return p1.second < p2.second;
		})->second;
		int MinValue = min_element(m_map.begin(), m_map.end(), [](const auto& p1, const auto& p2) {
			return p1.second < p2.second;
		})->second;
		for (auto& p : m_map) {
			p.second += MaxValue + MinValue;
		}
	}
}

void ShowMap(const map <int, int>& m_map) {
	if (m_map.size() > 0) {
		for (auto& p : m_map) {
			cout << p.first << " : " << p.second << '\n';
		}
	}
	else {
		cout << "Словарь пуст!";
	}
	cout << '\n';
}

int main() {

	system("chcp 1251 > NULL");

	map <int, int> a = { {6, 4}, {7, 9}, {2, 3} };

	cout << "Словарь а:\n";
	ShowMap(a);

	cout << "Добавляем среднее арифмитическое словаря а в конец контейнера\n";
	PushArithmeticMiddle(a);
	cout << "Словарь а:\n";
	ShowMap(a);

	cout << "Удаляем из словаря а элементы, значения которых входят в диапазон от 2 до 3\n";
	EraseIfInRange(a, 2, 3);
	cout << "Словарь а:\n";
	ShowMap(a);

	cout << "К каждому элементу добавляем сумму минимального и максимального элементов контейнера\n";
	PlusMinAndMax(a);
	cout << "Словарь а:\n";
	ShowMap(a);

	return 0;
}