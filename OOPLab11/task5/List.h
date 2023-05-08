#pragma once
#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class List {
private:
	priority_queue<T> m_priority_queue;
	int n = 0;
public:
	List() {};
	~List() {};
	void MakeQueue(int count) {
		T a;
		for (size_t i = 0; i < count; i++) {
			cout << "Введите " << i + 1 << " элемент очереди с приоритетами: ";
			cin >> a;
			m_priority_queue.push(a);
		}
		n = count;
	};
	void ShowQueue() {
		if (m_priority_queue.size() > 0) {
			priority_queue<T> tmp_priority_queue = m_priority_queue;
			while (tmp_priority_queue.size()) {
				cout << tmp_priority_queue.top() << ' ';
				tmp_priority_queue.pop();
			}
		}
		else {
			cout << "Очередь пуста!";
		}
		cout << '\n';
	};
	void PushArithmeticMiddle() {
		if (m_priority_queue.size() > 0) {
			priority_queue<T> tmp_priority_queue = m_priority_queue;
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
	};
	void EraseIfInRange(const double BeginValue, const double EndValue) {
		if (m_priority_queue.size() > 0) {
			priority_queue<T> tmp_priority_queue;
			while (m_priority_queue.size()) {
				if (m_priority_queue.top() < BeginValue || m_priority_queue.top() > EndValue) {
					tmp_priority_queue.push(m_priority_queue.top());
				}
				m_priority_queue.pop();
			}
			m_priority_queue = tmp_priority_queue;
		}
	};
	int size() {
		return n;
	};
	void PlusMinAndMax() {
		if (m_priority_queue.size() > 0) {
			priority_queue<T> tmp_priority_queue = m_priority_queue;
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
};