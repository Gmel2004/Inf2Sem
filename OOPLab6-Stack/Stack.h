#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Node {
    string key;
    Node* prev;
};

class Iterator {
private:
    Node* current;
    friend class Stack;
public:
    Iterator() {};
    Iterator(Node* node) {
        current = node;
    };
    void operator -- () {
        current = current->prev;
    }
    Node* operator *() const {
        return current;
    }
};

class Stack {
private:
    Node* lastNd, * current, * tail, * lastNd2, * current2, * tail2;
    int n = 0;
    Iterator end;
public:
    Stack() {};
    Stack(int);
    ~Stack();
    Stack& operator = (Stack&);
    int operator () ();
    friend ostream& operator << (ostream&, Stack&);
    friend istream& operator >> (istream&, Stack&);
    Iterator last();
    void operator << (string);
    void AIS() {//AddIntoStack
        int l;
        cout << "Введите номер элемента: ";
        cin >> l;
        lastNd2 = tail;
        tail = tail->prev;
        lastNd2->prev = NULL;
        for (int i = 1; i < n - l + 1; i++) {//Перемещаем все элементы во стек 2 до нужного номера включительно
            current2 = tail;
            tail = tail->prev;
            current2->prev = lastNd2;
            lastNd2 = current2;
        }
        tail2 = lastNd2;
        cout << "Введите количество элементов: ";
        cin >> l;
        n += l;
        lastNd = tail;
        for (int i = 0; i < l; i++) {//Вводим новые K элементов в стек 1
            current = new Node;
            cout << "Введите " << i + 1 << " элемент: ";
            cin >> current->key;
            current->prev = lastNd;
            lastNd = current;
        }
        tail = lastNd;
        while (tail2 != NULL) {//возвращаем обратно списанные элементы
            current = tail2;
            tail2 = tail2->prev;
            current->prev = lastNd;
            lastNd = current;
        }
        tail = lastNd;
    }
    void DFS() {//DeleteFromStack
        string l;
        cout << "Введите ключ элемента: ";
        cin >> l;
        current = NULL;
        lastNd = tail;
        bool replace = false;
        if (lastNd->key == l) {//Если нужный элемент является последним, то просто удаляем его из стека
            tail = lastNd->prev;
            delete lastNd;
            replace = true;
            n--;
        }
        else {
            lastNd2 = lastNd;
            lastNd = lastNd->prev;
            lastNd2->prev = NULL;
            while (lastNd != NULL) {//переписывем все элементы из стека 1 в стек 2, кроме удаляемого
                current2 = lastNd;
                lastNd = lastNd->prev;
                if (current2->key != l) {
                    current2->prev = lastNd2;
                    lastNd2 = current2;
                }
                else {
                    delete current2;
                    n--;
                }
            }
            tail = lastNd2;//замена стека 1 стеком 2, теперь стек 1 отражённый и не содержит в себе элемента с заданным ключом

            lastNd2 = NULL;
            while (tail != NULL) {//переписываем все элементы из стека 1 в стек 2, таким образом возвращая исходный стек
                current2 = tail;
                tail = tail->prev;
                current2->prev = lastNd2;
                lastNd2 = current2;
            }
            tail = lastNd2;//замена стека 1 стеком 2
        }
    }
    void WF() {//WriteFile
        ofstream F("F.txt");
        F << ' ' << n;
        lastNd2 = tail;
        tail = tail->prev;
        lastNd2->prev = NULL;
        while (tail != NULL) {//переписываем все элементы из стека 1 в стек 2, таким образом переворачивая исходный стек
            current2 = tail;
            tail = tail->prev;
            current2->prev = lastNd2;
            lastNd2 = current2;
        }
        tail = lastNd2;//замена стека 1 стеком 2

        lastNd2 = NULL;
        while (tail != NULL) {//записываем элементы в файл и восстанавливаем исходный стек в стек 2
            F << ' ' << tail->key;
            current2 = tail;
            tail = tail->prev;
            current2->prev = lastNd2;
            lastNd2 = current2;
        }
        tail = lastNd2;//заменяем стек 1 на стек 2
        F.close();
    }
    void RF() {//ReadFile
        ifstream F("F.txt");
        F >> n;
        lastNd = NULL;
        while (F.get() && !F.eof()) {
            current = new Node;
            F >> current->key;
            current->prev = lastNd;
            lastNd = current;
        }
        tail = lastNd;
        F.close();
    }
    void RS() {//RemoveStack
        lastNd = tail;
        while (lastNd != NULL) {
            current = lastNd->prev;
            delete lastNd;
            lastNd = current;
        }
        n = 0;
    }
};