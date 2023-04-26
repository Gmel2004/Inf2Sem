﻿#include <iostream>
using namespace std;
#include "List.h"

int main() {
    system("chcp 1251 > NULL");
    List a(5);
    cout << "Введите 5 элементов:\n";
    cin >> a;
    cout << "Список a:\n";
    cout << a << '\n';
    cout << "Меняем значение 3-его элемента списка а\n";
    a[2] = 100;
    cout << "Список a:\n";
    cout << a << '\n';
    List b(10);
    cout << "Список b:\n";
    cout << b << '\n';
    a = b;
    cout << "Теперь a = b\n";
    cout << "Меняем значение 1-го элемента списка а\n";
    a[0] = 50;
    cout << "Меняем значение последнего элемента списка b\n";
    b[b()-1] = 150;
    cout << "Список a:\n";
    cout << a << '\n';
    cout << "1-ый элемент списка a:\n" << (*(a.first()))->key << '\n';
    cout << "Список b:\n";
    cout << b << '\n';
    cout << "последний элемент списка b:\n" << (*(b.last()))->key << '\n';
    cout << "Выведем список b с помощью итератора:\n";
    for (Iterator i = b.first(); *i != NULL; ++i) {
        cout << (*i)->key << ' ';
    }
    cout << '\n';
    cout << "Добавим элемент 66 в список b\n";
    b << 66;
    cout << "Список b:\n";
    cout << b << '\n';
    return 0;
}