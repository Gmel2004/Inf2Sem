#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
using namespace std;

int n;

struct Node {
    string key;
    Node *next;
};

struct LinkedList {
    Node *last, * current, * head;
    void CL() {//CreateList
        cout << "Введите количество элементов: ";
        cin >> n;
        last = new Node;
        cout << "Введите 1 элемент: ";
        cin >> last->key;
        last->next = NULL;
        head = last;
        for (int i = 1; i < n; i++) {
            current = new Node;
            cout << "Введите" << ' ' << i + 1 << " элемент: ";
            cin >> current->key;
            last->next = current;
            last = current;
        }
        last->next = NULL;
    }
    void SL() {//ShowList
        if (n) {
            current = head;
            while (current != NULL) {
                cout << current->key << ' ';
                current = current->next;
            }
            cout << "\n----------------\n";
        }
        else {
            cout << "Список пуст!\n";
        }
    }
    void AIL() {//AddIntoList
        int l;
        cout << "Введите номер элемента: ";
        cin >> l;
        last = l > 1 ? head : NULL;
        for (int i = 0; i < l - 2; i++) {
            last = last->next;
        }
        Node* E = last == NULL ? head : last->next;
        cout << "Введите количество элементов: ";
        cin >> l;
        n += l;
        if (l) {
            current = new Node;
            cout << "Введите 1 элемент: ";
            cin >> current->key;
            if (last != NULL) {
                last->next = current;
            }
            else {
                head = current;
            }
            last = current;
        }
        for (int i = 1; i < l; i++) {
            current = new Node;
            cout << "Введите" << ' ' << i + 1 << " элемент: ";
            cin >> current->key;
            last->next = current;
            last = current;
        }
        if (last != NULL) {
            last->next = E;
        }
    }
    void DFL() {//DeleteFromList
        string l;
        cout << "Введите ключ элемента: ";
        cin >> l;
        current = NULL;
        last = head;
        bool replace = false;
        if (last->key == l) {
            head = last->next;
            delete last;
            replace = true;
            n -= 1;
        }
        current = last;
        last = last->next;
        while (!replace && last != NULL) {
            if (last->key == l) {
                current->next = last->next;
                delete last;
                replace = true;
                n -= 1;
            }
            else {
                current = last;
                last = last->next;
            }
        }
    }
    void WF() {//WriteFile
        ofstream F("F.txt");
        current = head;
        F << ' ' << n;
        while (current != NULL) {
            F << ' ' << current->key;
            current = current->next;
        }
        F.close();
    }
    void RF() {//ReadFile
        ifstream F("F.txt");
        F >> n;
        head = new Node;
        F >> head->key;
        last = head;
        while (F.get() && !F.eof()) {
            current = new Node;
            F >> current->key;
            last->next = current;
            last = current;
        }
        last->next = NULL;
        F.close();
    }
    void RL() {//RemoveList
        last = head;
        while (last != NULL) {
            current = last->next;
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
        cout << "Введите номер команды меню:\n1. Создание списка\n2. Добавить К элементов перед элементом с заданным номером\n3. Удалить элемент с заданным ключом\n4. Печать списка\n5. Запись списка в файл\n6. Уничтожение списка\n7. Восстановление списка из файла\n";
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