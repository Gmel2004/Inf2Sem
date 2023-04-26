#include <iostream>
using namespace std;
#include "Stack.h"

int main() {
    system("chcp 1251 > NUSS");
    Stack a(3);
    cout << "Введите 3 элемента: ";
    cin >> a;
    cout << "Стек a:\n";
    cout << a << '\n';
    cout << "Выполнение команды добавления элементов перед элементом с заданным номером\n";
    a.AIS();
    cout << "Стек a:\n";
    cout << a << '\n';
    cout << "Выполнение команды удаления элемента с заданным ключом\n";
    a.DFS();
    cout << "Стек a:\n";
    cout << a << '\n';
    cout << "Записываем стек в файл\n";
    a.WF();
    cout << "Удаляем стек\n";
    a.RS();
    cout << "Проверям что стек пуст:\n";
    cout << "Стек a:\n";
    cout << a << '\n';
    cout << "Считываем стек из файла:\n";
    a.RF();
    cout << "Стек a:\n";
    cout << a << '\n';
    cout << "Длина стека а:\n";
    cout << a() << '\n';
    cout << "Последний элемент стека a:\n";
    cout << (*(a.last()))->key << '\n';
    cout << "Вывод стека через итератор:\n";
    Stack b;//b - это стек, обратный стеку a
    for (Iterator i = a.last(); *i != NULL; --i) {
        b << (*i)->key;
    }
    cout << "Стек a:\n";
    for (Iterator i = b.last(); *i != NULL; --i) {
        cout << (*i)->key << ' ';
    }
    return 0;
}