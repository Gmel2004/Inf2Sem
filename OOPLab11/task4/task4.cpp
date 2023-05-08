#include <iostream>
#include <queue>
using namespace std;

void PushArithmeticMiddle(priority_queue<double>& m_priority_queue) {
	if (m_priority_queue.size() > 0) {
		priority_queue<double> tmp_priority_queue = m_priority_queue;
		double Sum = 0;
		while (tmp_priority_queue.size()) {
			Sum += tmp_priority_queue.top();
			tmp_priority_queue.pop();
		}
		m_priority_queue.push(Sum / m_priority_queue.size());
	}
	else {
		cout << "Очередь пуста!\n";
	}
}

void EraseIfInRange(priority_queue<double>& m_priority_queue, const double BeginValue, const double EndValue) {
	priority_queue<double> tmp_priority_queue;
	while (m_priority_queue.size()) {
		if (m_priority_queue.top() < BeginValue || m_priority_queue.top() > EndValue) {
			tmp_priority_queue.push(m_priority_queue.top());
		}
		m_priority_queue.pop();
	}
	m_priority_queue = tmp_priority_queue;
}

void PlusMinAndMax(priority_queue<double>& m_priority_queue) {
	if (m_priority_queue.size() > 0) {
		priority_queue<double> tmp_priority_queue = m_priority_queue;
		double MaxValue, MinValue;
		MaxValue = m_priority_queue.top();

		while (m_priority_queue.size() > 1) {
			m_priority_queue.pop();
		}
		MinValue = m_priority_queue.top();
		m_priority_queue.pop();

		while (tmp_priority_queue.size()) {
			m_priority_queue.push(tmp_priority_queue.top() + MaxValue + MinValue);
			tmp_priority_queue.pop();
		}
	}
}

void ShowQueue(priority_queue<double>& m_priority_queue) {
	if (m_priority_queue.size() > 0) {
		priority_queue<double> tmp_priority_queue = m_priority_queue;
		while (tmp_priority_queue.size()) {
			cout << tmp_priority_queue.top() << ' ';
			tmp_priority_queue.pop();
		}
	}
	else {
		cout << "Очередь пуста!";
	}
	cout << '\n';
}

int main() {

	system("chcp 1251 > NULL");

	priority_queue<double> a;
	for (double i : { 1, 2, 3, 4, 5, 6, 7 }) {
		a.push(i);
	}

	cout << "Очередь с приоритетеми а:\n";
	ShowQueue(a);

	cout << "Добавляем среднее арифмитическое очереди a\n";
	PushArithmeticMiddle(a);
	cout << "Очередь а:\n";
	ShowQueue(a);

	cout << "Удаляем из очереди а элементы, значения которых входят в диапазон от 2 до 3\n";
	EraseIfInRange(a, 2, 3);
	cout << "Очередь а:\n";
	ShowQueue(a);

	cout << "К каждому элементу добавляем сумму минимального и максимального элементов контейнера\n";
	PlusMinAndMax(a);
	cout << "Очередь а:\n";
	ShowQueue(a);

	return 0;
}