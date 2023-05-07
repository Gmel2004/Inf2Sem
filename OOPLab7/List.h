#pragma once
#include <string>
#include <iostream>
using namespace std;

template <class T>
struct Node {
	T key;
	Node<T>* next;
};

template <class T>
class List {
public:
	List() {};
	List(int count) {
		n = count;
		head = new Node<T>;
		head->key = 0;
		lastNd = head;
		for (int i = 1; i < n; i++) {
			current = new Node<T>;
			current->key = 0;
			lastNd->next = current;
			lastNd = current;
		}
		lastNd->next = NULL;
	};
	~List() {
		lastNd = head;
		while (lastNd != NULL) {
			current = lastNd->next;
			delete lastNd;
			lastNd = current;
		}
		n = 0;
	};
	List& operator = (List<T>& l) {
		if (this != &l) {
			if (this != 0) {
				lastNd = head;
				while (lastNd != NULL) {
					current = lastNd->next;
					delete lastNd;
					lastNd = current;
				}
				n = 0;
			}
			lastNd = head = new Node<T>;
			l.lastNd = l.head->next;/////
			lastNd->key = l.head->key;
			while (l.lastNd != NULL) {
				lastNd->next = new Node<T>;
				lastNd->next->key = l.lastNd->key;
				l.lastNd = l.lastNd->next;
				lastNd = lastNd->next;
			}
			lastNd->next = NULL;
			n = l.n;
		}
		return *this;
	};
	int& operator[] (int index) {
		if (index < n) {
			lastNd = head;
			for (int i = 0; i < index; i++) {
				lastNd = lastNd->next;
			}
			return lastNd->key;
		}
		else {
			cout << "Ошибка: Индекс за пределами диапазона!";
		}
	};
	int operator () () {
		return n;
	};
	friend ostream& operator << (ostream& out, List<T>& l) {
		if (l.n) {
			l.lastNd = l.head;
			while (l.lastNd != NULL) {
				out << l.lastNd->key << ' ';
				l.lastNd = l.lastNd->next;
			}
		}
		else {
			out << "Список пуст!";
		}
		return out;
	};
	friend istream& operator >> (istream& in, List<T>& l) {
		l.lastNd = l.head;
		while (l.lastNd != NULL) {
			in >> l.lastNd->key;
			l.lastNd = l.lastNd->next;
		}
		return in;
	};
	void operator << (T t) {
		if (head == NULL) {
			head = new Node<T>;
			head->key = t;
			head->next = NULL;
		}
		else {
			lastNd = head;
			while (lastNd->next != NULL) {
				lastNd = lastNd->next;
			}
			lastNd->next = new Node<T>;
			lastNd->next->key = t;
			lastNd = lastNd->next;
			lastNd->next = NULL;
		}
		n += 1;
	};
private:
	Node<T>* lastNd, * current, * head;
	int n = 0;
};