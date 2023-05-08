#include "Pair.h"

Pair::Pair(int first, double second) {//конструктор с параметрами
	this->first = first;
	this->second = second;
}
istream& operator>>(istream& in, Pair& m_pair) {//перегрузка оператора ввода
	cout << "Введите данные в формате:\nцелое число вещественное число\n";
	in >> m_pair.first;
	in >> m_pair.second;
	return in;
}
ostream& operator<<(ostream& out, const Pair& m_pair) {//перегрузка оператора вывода
	return (out << m_pair.first << " : " << m_pair.second);
}
fstream& operator>>(fstream& fin, Pair& m_Pair) {
	fin >> m_Pair.first;
	fin >> m_Pair.second;
	return fin;
}
fstream& operator<<(fstream& fout, const Pair& m_Pair) {
	fout << m_Pair.first << ' ' << m_Pair.second << '\n';
	return fout;
}
Pair::Pair() {//конструктор без параметров
	first = 0;
	second = 0;
}
Pair::~Pair() {//деструктор
}
Pair::Pair(const Pair& m_pair) {//конструктор копирования
	first = m_pair.first;
	second = m_pair.second;
}
Pair& Pair::operator=(const Pair& m_pair) {//перегрузка оператора присваивания
	if (&m_pair != this) {
		first = m_pair.first;
		second = m_pair.second;
	}
	return *this;
}
Pair Pair::operator-(const Pair& m_pair) {//перегрузка оператора вычитания
	Pair result(first - m_pair.first, second - m_pair.second);
	return result;

}
Pair& Pair::operator+(int first) {//перегрузка оператора сложения - целый аргумент
	this->first += first;
	return *this;
}
Pair& Pair::operator+(double second) {//перегрузка оператора сложения - дробный аргумент
	this->second += second;
	return *this;
}
Pair& Pair::operator++() {//перегрузка оператора ++ префикс
	++first;
	++second;
	return *this;
}
Pair Pair::operator ++(int) {//перегрузка оператора ++ постфикс
	Pair temp = *this;
	this->first++;
	this->second++;
	return temp;//сначала нужно вывести без изменений
}

bool Pair::operator>=(int value) {
	return (this->first >= value && this->second >= value);
}

int Pair::GetFirst() const {
	return first;
}

double Pair::GetSecond() const {
	return second;
}

void Pair::SetFirst(int m_first) {
	first = m_first;
}

void Pair::SetSecond(double m_second) {
	second = m_second;
}