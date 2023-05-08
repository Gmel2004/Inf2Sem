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
class Iterator {
private:
	Node<T>* current;
	template <class T>
	friend class List;
public:
	Iterator() {
		current = NULL;
	};
	Iterator(Node<T>* node) {
		current = node;
	};
	void operator ++ () {
		current = current->next;
	}
	Node<T>* operator *() const {
		return current;
	}
	Iterator<T>& operator + (T value) {
		current->key += value;
		return *this;
	}
	void operator = (Node<T>& nd) {
		*this = &nd;
	}
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
	Iterator<T> begin() {
		beg.current = head;
		return beg;
	};
	int length() {
		return n;
	}
	Node<T>& erase(Iterator<T> I) {
		lastNd = head;
		if (head == *I) {
			lastNd = head->next;
			delete head;
			head = lastNd;
		}
		else {
			while (lastNd->next != NULL && lastNd->next != *I) {
				lastNd = lastNd->next;
				cout << lastNd->key << ' ';
			}
			if (lastNd->next != NULL) {
				current = lastNd->next->next;
				delete lastNd->next;
				lastNd->next = current;
				lastNd = lastNd->next;
			}
		}
		return *lastNd;
	}

private:
	Node<T>* lastNd, * current, * head;
	int n = 0;
	Iterator<T> beg;
};