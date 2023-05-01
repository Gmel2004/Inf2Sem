#pragma once
#include <string>
#include <iostream>
using namespace std;

struct Node {
	int key;
	Node* next;
};

class Iterator {
private:
	Node* current;
	friend class List;
public:
	Iterator() {
		current = NULL;
	};
	Iterator(Node* node) {
		current = node;
	};
	void operator ++ () {
		current = current->next;
	}
	Node* operator *() const {
		return current;
	}
	void operator + (int shift) {
		Node* tmp = current;
		int i = 0;
		while (i < shift && current != NULL && current->next != NULL) {
			current = current->next;
			i++;
		}
		if (i < shift) {
			cout << "Ќельз€ сместитьс€, выход за пределы списка!\n";
			current = tmp;
		}
	}
};

class List {
public:
	List() {};
	List(int);
	~List();
	List& operator = (List&);
	int& operator[] (int);
	int operator () ();
	friend ostream& operator << (ostream&, List&);
	friend istream& operator >> (istream&, List&);
	Iterator first();
	Iterator last();
	void operator << (int);
private:
	Node* lastNd, * current, * head;
	int n = 0;
	Iterator beg, end;
};