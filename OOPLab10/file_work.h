#pragma once
#include "Pair.h"
#include <iostream>
using namespace std;

char f_name[30];

int value;

void check_k(int k) {
	if (k < 0) {
		cout << "Невозможно прочесть файл!\n";
	}
}

int make_file() {
	cout << "Введите название файла: ";
	cin >> f_name;
	fstream stream(f_name, ios::out | ios::trunc);
	if (!stream) {
		return -1;
	}
	int n;
	Pair m_Pair;
	cout << "Введите количество элиментов: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m_Pair;
		stream << m_Pair << '\n';
	}
	stream.close();
	return n;
}

int print_file() {
	cout << "Введите название файла: ";
	cin >> f_name;
	fstream stream(f_name, ios::in);
	if (!stream) {
		return -1;
	}
	Pair m_Pair;
	int i = 0;
	while (stream >> m_Pair) {
		cout << m_Pair << '\n';
		i++;
	}
	if (i == 0) {
		cout << "Файл пуст!\n";
	}
	stream.close();
	return i;
}

int del_file() {
	cout << "Введите название файла: ";
	cin >> f_name;
	cout << "Введите значение: ";
	cin >> value;
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream) {
		return -1;
	}
	int i = 0;
	Pair m_Pair;
	while (stream >> m_Pair) {
		if (stream.eof()) {
			break;
		}
		i++;
		if (m_Pair >= value) {
			temp << m_Pair;
		}
	}
	stream.close();
	temp.close();
	remove(f_name);
	rename("temp", f_name);
	return i;
}

int add_file() {
	int number;
	cout << "Введите название файла: ";
	cin >> f_name;
	cout << "Введите номер: ";
	cin >> number;
	cout << "Введите количество записей: ";
	cin >> value;
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	int i = 1;
	if (!stream) {
		return -1;
	}
	Pair pair;
	while (i != number && stream >> pair) {
		if (stream.eof()) {
			break;
		}
		i++;
		temp << pair;
	}
	if (i == number) {
		for (int j = 0; j < value; j++) {
			Pair m_Pair;
			cin >> m_Pair;
			temp << m_Pair;
		}
	}
	while (stream >> pair) {
		if (stream.eof()) {
			break;
		}
		temp << pair;
	}
	temp.close();
	stream.close();
	remove(f_name);
	rename("temp", f_name);
	return value;
}

int change_file() {
	cout << "Введите название файла: ";
	cin >> f_name;
	cout << "Введите значение: ";
	cin >> value;
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream) {
		return -1;
	}
	Pair pair;
	int i = 0;
	while (stream >> pair) {
		temp << pair + value;
	}
	temp.close();
	stream.close();
	remove(f_name);
	rename("temp", f_name);
	return i;
}