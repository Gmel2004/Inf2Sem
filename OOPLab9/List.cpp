#include "List.h"

List::List(int count) {
	n = count;
	head = new Node;
	head->key = 0;
	lastNd = head;
	for (int i = 1; i < n; i++) {
		current = new Node;
		current->key = 0;
		lastNd->next = current;
		lastNd = current;
	}
	lastNd->next = NULL;
}

List::~List() {
	lastNd = head;
	while (lastNd != NULL) {
		current = lastNd->next;
		delete lastNd;
		lastNd = current;
	}
	n = 0;
}

List& List::operator=(List& l) {
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
		lastNd = head = new Node;
		l.lastNd = l.head->next;/////
		lastNd->key = l.head->key;
		while (l.lastNd != NULL) {
			lastNd->next = new Node;
			lastNd->next->key = l.lastNd->key;
			l.lastNd = l.lastNd->next;
			lastNd = lastNd->next;
		}
		lastNd->next = NULL;
		n = l.n;
	}
	return *this;
}

int& List::operator[](int index) {
	if (index >= n) {
		throw Error(3);
	}
	lastNd = head;
	for (int i = 0; i < index; i++) {
		lastNd = lastNd->next;
	}
	return lastNd->key;
}

int List::operator () () {
	return n;
}

Iterator List::first() {
	if (!n) {
		throw Error(1);
	}
	beg.current = head;
	return beg;
}

Iterator List::last() {
	if (!n) {
		throw Error(2);
	}
	lastNd = head;
	while (lastNd->next != NULL) {
		lastNd = lastNd->next;
	}
	end.current = lastNd;
	return end;
}

ostream& operator<<(ostream& out, List& l) {
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
}

istream& operator>>(istream& in, List& l) {
	l.lastNd = l.head;
	while (l.lastNd != NULL) {
		in >> l.lastNd->key;
		l.lastNd = l.lastNd->next;
	}
	return in;
}

void List::operator << (int number) {
	if (head == NULL) {
		head = new Node;
		head->key = number;
		head->next = NULL;
	}
	else {
		lastNd = head;
		while (lastNd->next != NULL) {
			lastNd = lastNd->next;
		}
		lastNd->next = new Node;
		lastNd->next->key = number;
		lastNd = lastNd->next;
		lastNd->next = NULL;
	}
	n += 1;
}