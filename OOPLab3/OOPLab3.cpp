#include <iostream>
#include "Pair.h"
using namespace std;

Pair& operator+(int number, Pair& pair) { //заменяем местами для коммуникативности - сложение с целой константой
    return pair + number;
}
Pair& operator+(double number, Pair& pair) { //заменяем местами для коммуникативности - сложение с вещественной константой
    return pair + number;
}

int main() {
    system("chcp 1251 > NULL");

    Pair pair1;
    Pair pair2(3, 4.5);

    cout << "Вывод значений pair2:\n" << pair2 << '\n';

    cout << "Ввод значений для pair1:\n";
    cin >> pair1;

    cout << "Вывод значений pair1:\n" << pair1 << '\n';

    cout << "Вычитание из значений pair2 соответствующие значения pair1:\n" << pair2 - pair1 << '\n';

    cout << "Присваивние: pair1 = pair2\n";
    pair1 = pair2;
    cout << "Вывод значений pair1:\n" << pair1 << '\n';

    Pair tmp = pair1;//сохраняем значение
    cout << "Сложение pair1 с целой константой 3:\n";
    cout << pair1 + 3 << '\n';
    pair1 = tmp;//возвращаем предыдущее значение
    cout << "Проверка коммуникативности:\n";
    cout << 3 + pair1 << '\n';

    tmp = pair1;//сохраняем значение
    cout << "Сложение pair1 с вещественной константой 4.5:\n";
    cout << pair1 + 4.5 << '\n';
    pair1 = tmp;//возвращаем предыдущее значение
    cout << "Проверка коммуникативности:\n";
    cout << 4.5 + pair1 << '\n';

    cout << "++ префикс для pair1:\n";
    cout << ++pair1 << '\n';

    cout << "++ постфикс для pair1\n";
    cout << pair1++ << '\n';
    cout << "Проверка изменения значений:\n";
    cout << pair1 << '\n';
}