#include "Stack.h"

Stack::Stack(int count) {
	n = count;
	lastNd = NULL;
	for (int i = 0; i < n; i++) {
		current = new Node;
		current->key = "";
		current->prev = lastNd;
		lastNd = current;
	}
	tail = lastNd;
}

Stack::~Stack() {
	this->RS();
}

Stack& Stack::operator=(Stack& l) {
	if (this != &l) {
		if (this != 0) {
			this->RS();
		}
		lastNd = new Node;
		l.lastNd = l.tail->prev;
		lastNd->key = l.tail->key;
		lastNd->prev = NULL;
		while (l.lastNd != NULL) {
			current = new Node;
			current->key = l.lastNd->key;
			l.lastNd = l.lastNd->prev;
			current->prev = lastNd;
			lastNd = current;
		}
		tail = lastNd;
		n = l.n;

		lastNd2 = NULL;
		while (tail != NULL) {//восстанавливаем исходный стек в стек 2
			current2 = tail;
			tail = tail->prev;
			current2->prev = lastNd2;
			lastNd2 = current2;
		}
		tail = lastNd2;//заменяем стек 1 на стек 2
	}
	return *this;
}

int Stack::operator () () {
	return n;
}

Iterator Stack::last() {
	end.current = tail;
	return end;
}

ostream& operator<<(ostream& out, Stack& l) {
	if (l.n > 0) {
		l.lastNd2 = l.tail;
		l.tail = l.tail->prev;
		l.lastNd2->prev = NULL;
		while (l.tail != NULL) {//переписываем все элементы из стека 1 в стек 2, таким образом переворачивая исходный стек
			l.current2 = l.tail;
			l.tail = l.tail->prev;
			l.current2->prev = l.lastNd2;
			l.lastNd2 = l.current2;
		}
		l.tail = l.lastNd2;//замена стека 1 стеком 2

		l.lastNd2 = NULL;
		while (l.tail != NULL) {//выводим элементы и восстанавливаем исходный стек в стек 2
			out << l.tail->key << ' ';
			l.current2 = l.tail;
			l.tail = l.tail->prev;
			l.current2->prev = l.lastNd2;
			l.lastNd2 = l.current2;
		}
		l.tail = l.lastNd2;//заменяем стек 1 на стек 2
	}
	else {
		out << "Стек пуст!";
	}
	return out;
}

istream& operator>>(istream& in, Stack& l) {
	l.lastNd = l.tail;
	while (l.lastNd != NULL) {
		in >> l.lastNd->key;
		l.lastNd = l.lastNd->prev;
	}

	l.lastNd2 = NULL;
	while (l.tail != NULL) {//восстанавливаем исходный стек в стек 2
		l.current2 = l.tail;
		l.tail = l.tail->prev;
		l.current2->prev = l.lastNd2;
		l.lastNd2 = l.current2;
	}
	l.tail = l.lastNd2;//заменяем стек 1 на стек 2
	return in;
}

void Stack::operator << (string str) {
	if (tail == NULL) {
		tail = new Node;
		tail->key = str;
		tail->prev = NULL;
	}
	else {
		lastNd = new Node;
		lastNd->key = str;
		lastNd->prev = tail;
		tail = lastNd;
	}
	n += 1;
}