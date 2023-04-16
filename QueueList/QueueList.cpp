#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
using namespace std;

int n;

struct Node {
    string key;
    Node* next;
};

struct LinkedList {
    Node* last, * current, * head, * last2, * current2, * head2;
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
            last2 = head2 = head;
            cout << head->key << ' ';
            head = head->next;
            last2->next = NULL;
            while (head != NULL) {
                cout << head->key << ' ';
                last2->next = head;
                last2 = last2->next;
                head = head->next;
                last2->next = NULL;
            }
            cout << "\n----------------\n";
            head = head2;//замена очереди 1 очередью 2
        }
        else {
            cout << "Очередь пуста!\n";
        }
    }
    void AIL() {//AddIntoList
        int l;
        cout << "Введите номер элемента: ";
        cin >> l;
        if (l > 1) {
            last2 = head2 = head;
            head = head->next;
            head2->next = NULL;
            for (int i = 1; i < l - 1; i++) {//Перемещаем все элементы во вторую очередь до нужного номера
                current2 = head;
                head = head->next;
                current2->next = NULL;
                last2->next = current2;
                last2 = current2;
            }
            cout << "Введите количество элементов: ";
            cin >> l;
            n += l;
            for (int i = 0; i < l; i++) {//Вводим новые K элементов во вторую очередь
                current2 = new Node;
                cout << "Введите " << i + 1 << " элемент: ";
                cin >> current2->key;
                last2->next = current2;
                last2 = current2;
            }
            while (head != NULL) {//Списываем оставшиеся элементы из первой очереди во второй
                last2->next = head;
                last2 = last2->next;
                head = head->next;
                last2->next = NULL;
            }
            head = head2;//замена очереди 1 очередью 2

        }
        else {//Вторая очередь начинаниется с новых элементов
            cout << "Введите количество элементов: ";
            cin >> l;
            n += l;
            if (l) {
                current2 = new Node;
                cout << "Введите 1 элемент: ";
                cin >> current2->key;
                last2 = head2 = current2;
                last2->next = NULL;
                for (int i = 1; i < l; i++) {
                    current2 = new Node;
                    cout << "Введите" << ' ' << i + 1 << " элемент: ";
                    cin >> current2->key;
                    last2->next = current2;
                    last2 = current2;
                }
                while (head != NULL) {//Списываем оставшиеся элементы из первой очереди во второй
                    last2->next = head;
                    last2 = last2->next;
                    head = head->next;
                    last2->next = NULL;
                }
                head = head2;//замена очереди 1 очередью 2
            }
        }
    }
    void DFL() {//DeleteFromList
        string l;
        cout << "Введите ключ элемента: ";
        cin >> l;
        current = NULL;
        last = head;
        bool replace = false;
        if (last->key == l) {//Если нужный элемент является первым, то просто удаляем его из очереди
            head = last->next;
            delete last;
            replace = true;
            n--;
        }
        else {
            last2 = head2 = last;
            last = last->next;
            head2->next = NULL;
            while (last != NULL) {
                current2 = last;
                last = last->next;
                current2->next = NULL;
                if (current2->key != l) {
                    last2->next = current2;
                    last2 = current2;
                }
                else {
                    delete current2;
                    n--;
                }
            }
            head = head2;//замена очереди 1 очередью 2
        }
    }
    void WF() {//WriteFile
        ofstream F("F.txt");
        F << ' ' << n;
        last2 = head2 = head;
        F << ' ' << head->key;
        head = head->next;
        last2->next = NULL;
        while (head != NULL) {
            F << ' ' << head->key;
            last2->next = head;
            last2 = last2->next;
            head = head->next;
            last2->next = NULL;
        }
        head = head2;//замена очереди 1 очередью 2
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
        cout << "Введите номер команды меню:\n1. Создание очереди\n2. Добавить К элементов перед элементом с заданным номером\n3. Удалить элемент с заданным ключом\n4. Печать очереди\n5. Запись очереди в файл\n6. Уничтожение очереди\n7. Восстановление очереди из файла\n";
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