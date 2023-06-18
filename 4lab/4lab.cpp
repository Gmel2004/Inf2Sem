#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Rus");
    int m[100];
    int n = 0;
    while (true) {
        cout << "Введите номер команды:\n1. Добавить элемент в очередь\n2. Удалить элемент из очереди\n";
        int a;
        cin >> a;
        if (a == 1) {
            cout << "Введите элемент: ";
            cin >> m[n];
            n++;
        }
        else if (a == 2) {
            if (n == 0) {
                cout << "Очередь пуста, невозможно произвести удаление!\n";
            }
            else {
                for (int i = 1; i < n; i++) {
                    m[i - 1] = m[i];
                }
                n--;
            }
        }
        else {
            cout << "Команды под таким номером не существует!\n";
        }
        if (n == 0) {
            cout << "Очередь пуста";
        }
        else {
            cout << "Очередь: ";
            for (int i = 0; i < n; i++) {
                cout << m[i] << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}