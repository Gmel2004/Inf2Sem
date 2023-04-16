#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
using namespace std;

int n;

struct Node {
    string key;
    Node* prev;
};

struct LinkedList {
    Node* last, * current, * tail, * last2, * current2, * tail2;
    void CL() {//CreateList
        cout << "Введите количество элементов: ";
        cin >> n;
        last = NULL;
        for (int i = 0; i < n; i++) {
            current = new Node;
            cout << "Введите" << ' ' << i + 1 << " элемент: ";
            cin >> current->key;
            current->prev = last;
            last = current;
        }
        tail = last;
    }
    void SL() {//ShowList
        if (n) {
            last2 = tail;
            tail = tail->prev;
            last2->prev = NULL;
            while (tail != NULL) {//переписываем все элементы из стека 1 в стек 2, таким образом переворачивая исходный стек
                current2 = tail;
                tail = tail->prev;
                current2->prev = last2;
                last2 = current2;
            }
            tail = last2;//замена стека 1 стеком 2

            last2 = NULL;
            while (tail != NULL) {//выводим элементы и восстанавливаем исходный стек в стек 2
                cout << tail->key << ' ';
                current2 = tail;
                tail = tail->prev;
                current2->prev = last2;
                last2 = current2;
            }
            cout << "\n----------------\n";
            tail = last2;//заменяем стек 1 на стек 2
        }
        else {
            cout << "Стек пуст!\n";
        }
    }
    void AIL() {//AddIntoList
        int l;
        cout << "Введите номер элемента: ";
        cin >> l;
        last2 = tail;
        tail = tail->prev;
        last2->prev = NULL;
        for (int i = 1; i < n - l + 1; i++) {//Перемещаем все элементы во стек 2 до нужного номера включительно
            current2 = tail;
            tail = tail->prev;
            current2->prev = last2;
            last2 = current2;
        }
        tail2 = last2;
        cout << "Введите количество элементов: ";
        cin >> l;
        n += l;
        last = tail;
        for (int i = 0; i < l; i++) {//Вводим новые K элементов в стек 1
            current = new Node;
            cout << "Введите " << i + 1 << " элемент: ";
            cin >> current->key;
            current->prev = last;
            last = current;
        }
        tail = last;
        while (tail2 != NULL) {//возвращаем обратно списанные элементы
            current = tail2;
            tail2 = tail2->prev;
            current->prev = last;
            last = current;
        }
        tail = last;
    }
    void DFL() {//DeleteFromList
        string l;
        cout << "Введите ключ элемента: ";
        cin >> l;
        current = NULL;
        last = tail;
        bool replace = false;
        if (last->key == l) {//Если нужный элемент является последним, то просто удаляем его из стека
            tail = last->prev;
            delete last;
            replace = true;
            n--;
        }
        else {
            last2 = last;
            last = last->prev;
            last2->prev = NULL;
            while (last != NULL) {//переписывем все элементы из стека 1 в стек 2, кроме удаляемого
                current2 = last;
                last = last->prev;
                if (current2->key != l) {
                    current2->prev = last2;
                    last2 = current2;
                }
                else {
                    delete current2;
                    n--;
                }
            }
            tail = last2;//замена стека 1 стеком 2, теперь стек 1 отражённый и не содержит в себе элемента с заданным ключом

            last2 = NULL;
            while (tail != NULL) {//переписываем все элементы из стека 1 в стек 2, таким образом возвращая исходный стек
                current2 = tail;
                tail = tail->prev;
                current2->prev = last2;
                last2 = current2;
            }
            tail = last2;//замена стека 1 стеком 2
        }
    }
    void WF() {//WriteFile
        ofstream F("F.txt");
        F << ' ' << n;
        last2 = tail;
        tail = tail->prev;
        last2->prev = NULL;
        while (tail != NULL) {//переписываем все элементы из стека 1 в стек 2, таким образом переворачивая исходный стек
            current2 = tail;
            tail = tail->prev;
            current2->prev = last2;
            last2 = current2;
        }
        tail = last2;//замена стека 1 стеком 2

        last2 = NULL;
        while (tail != NULL) {//записываем элементы в файл и восстанавливаем исходный стек в стек 2
            F << ' ' << tail->key;
            current2 = tail;
            tail = tail->prev;
            current2->prev = last2;
            last2 = current2;
        }
        tail = last2;//заменяем стек 1 на стек 2
        F.close();
    }
    void RF() {//ReadFile
        ifstream F("F.txt");
        F >> n;
        last = NULL;
        while (F.get() && !F.eof()) {
            current = new Node;
            F >> current->key;
            current->prev = last;
            last = current;
        }
        tail = last;
        F.close();
    }
    void RL() {//RemoveList
        last = tail;
        while (last != NULL) {
            current = last->prev;
            delete last;
            last = current;
        }
        n = 0;
    }
};

int main() {
    system("chcp 1251 > NULL");
    int a;
    LinkedList lst;
    while (true) {
        cout << "Введите номер команды меню:\n1. Создание стека\n2. Добавить К элементов перед элементом с заданным номером\n3. Удалить элемент с заданным ключом\n4. Печать стека\n5. Запись стека в файл\n6. Уничтожение стека\n7. Восстановление стека из файла\n";
        cin >> a;
        system("cls");
        switch (a) {
        case 1:
            lst.CL();
            break;
        case 2:
            lst.AIL();
            break;
        case 3:
            lst.DFL();
            break;
        case 4:
            lst.SL();
            break;
        case 5:
            lst.WF();
            break;
        case 6:
            lst.RL();
            break;
        case 7:
            lst.RF();
            break;
        }
    }
    return 0;
}