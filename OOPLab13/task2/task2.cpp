#include "Pair.h"
#include <iostream>
#include <list>
#include <queue>
#include <numeric>
#include <algorithm>
using namespace std;

list<Pair> priority_queueTolist(priority_queue<Pair>& m_priority_queue) {
	priority_queue <Pair> tmp_priority_queue = m_priority_queue;
	list <Pair> m_list;
	while (tmp_priority_queue.size() > 0) {
		m_list.push_back(tmp_priority_queue.top());
		tmp_priority_queue.pop();
	}
	return m_list;
}

void PushArithmeticMiddle(priority_queue<Pair>& m_priority_queue) {
	if (m_priority_queue.size() > 0) {
		list <Pair> m_list = priority_queueTolist(m_priority_queue);
		Pair Middle = accumulate(m_list.begin(), m_list.end(), Pair(0, 0));
		Middle.SetFirst(Middle.GetFirst() / m_list.size());
		Middle.SetSecond(Middle.GetSecond() / m_list.size());
		m_priority_queue.push(Middle);
	}
	else {
		cout << "Очередь пуста!\n";
	}
}

void EraseIfInRange(priority_queue<Pair>& m_priority_queue, const double BeginValue, const double EndValue) {
	if (m_priority_queue.size() > 0) {
		list <Pair> m_list = priority_queueTolist(m_priority_queue);
		auto i = remove_if(m_list.begin(), m_list.end(), [BeginValue, EndValue](Pair p) {
			return (BeginValue <= p.GetFirst() && p.GetFirst() <= EndValue) || (BeginValue <= p.GetSecond() && p.GetSecond() <= EndValue);
		});
		m_priority_queue = {};
		if (i != m_list.begin()) {
			for_each(m_list.begin(), i--, [&m_priority_queue](Pair p) {
				m_priority_queue.push(p);
			});
		}
	}
}

void PlusMinAndMax(priority_queue<Pair>& m_priority_queue) {
	if (m_priority_queue.size() > 0) {
		list <Pair> m_list = priority_queueTolist(m_priority_queue);
		m_priority_queue = {};
		Pair max = *max_element(m_list.begin(), m_list.end());
		Pair min = *min_element(m_list.begin(), m_list.end());
		for (Pair& c : m_list) {
			m_priority_queue.push(c + max + min);
		}
	}
}

void Show_priority_queue(priority_queue<Pair>& m_priority_queue) {
	if (m_priority_queue.size() > 0) {
		list <Pair> m_list = priority_queueTolist(m_priority_queue);
		for_each(m_list.begin(), m_list.end(), [](Pair p) {
			cout << p << '\n';
		});
	}
	else {
		cout << "Очередь пуста!";
	}
	cout << '\n';
}

int main() {

	system("chcp 1251 > NULL");

	priority_queue <Pair> a;
	for (Pair i : { Pair(6, 4), Pair(7, 9), Pair(2, 3.5) }) {
		a.push(i);
	}

	cout << "Очередь с приоритетами а:\n";
	Show_priority_queue(a);

	cout << "Добавляем среднее арифмитическое очереди а в контейнер\n";
	PushArithmeticMiddle(a);
	cout << "Очередь а:\n";
	Show_priority_queue(a);

	cout << "Удаляем из очереди а элементы, значения которых входят в диапазон от 2 до 3\n";
	EraseIfInRange(a, 2, 3);
	cout << "Очередь а:\n";
	Show_priority_queue(a);

	cout << "К каждому элементу добавляем сумму минимального и максимального элементов контейнера\n";
	PlusMinAndMax(a);
	cout << "Очередь а:\n";
	Show_priority_queue(a);

	return 0;
}