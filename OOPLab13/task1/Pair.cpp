#include "Pair.h"

Pair::Pair(int first, double second) {//конструктор с параметрами
	this->first = first;
	this->second = second;
}
istream& operator>>(istream& in, Pair& m_pair) {//перегрузка оператора ввода
	in >> m_pair.first;
	in >> m_pair.second;
	return in;
}
ostream& operator<<(ostream& out, const Pair& m_pair) {//перегрузка оператора вывода
	return (out << m_pair.first << " : " << m_pair.second);
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

int Pair::GetFirst() const{
	return first;
}

double Pair::GetSecond() const{
	return second;
}

bool operator < (const Pair& pair1, const Pair& pair) {
	return (pair1.GetFirst() + pair1.GetSecond() < pair.GetFirst() + pair.GetSecond());
}

Pair& Pair::operator + (const Pair& m_pair) {
	first += m_pair.first;
	second += m_pair.second;
	return *this;
}

void Pair::SetFirst(int m_first) {
	first = m_first;
}

void Pair::SetSecond(double m_second) {
	second = m_second;
}
