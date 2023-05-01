#include "Magazin.h"
Magazin::Magazin(void) :Print() {
	pages = 0;
}

Magazin::Magazin(string m_author, string m_name, int m_pages) : Print(m_author, m_name) {
	pages = m_pages;
}

Magazin::Magazin(const Magazin& L) {
	author = L.author;
	name = L.name;
	pages = L.pages;
}

void Magazin::Set_pages(int m_pages) {
	pages = m_pages;
}

Magazin& Magazin::operator=(const Magazin& l) {
	if (&l == this) {
		author = l.author;
		name = l.name;
		pages = l.pages;
	}
	return *this;
}
void Magazin::Show() {
	cout << "Автор : " << author << '\n';
	cout << "Название : " << name << '\n';
	cout << "Количество страниц : " << pages << "\n\n";
}
void Magazin::Input() {
	cout << "Введите данные в формате:\nАвтор Название Количество страниц\n";
	cin >> author >> name >> pages;
}