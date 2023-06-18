#include <iostream>
#include <string>
using namespace std;

int main() {
    system("chcp 1251>NULL");
    int n;
    cout << "Введите первоначальную длинну массива: ";
    cin >> n;
    string* m = new string[n]{};
    cout << "Введите первые n строк:\n";
    cin.get();
    for (int i = 0; i < n; i++) {
        getline(cin, m[i]);
    }
    string add;
    cout << "Введите строку, которую нужно добавить: ";
    getline(cin, add);
    int k;
    cout << "Введите номер, на котором должна находиться новая строка: ";
    cin >> k;
    string* tmp = new string[k > n ? k : n + 1];
    for (int i = 0; i < k - 1 && i < n; i++) {
        tmp[i] = m[i];
    }
    tmp[k - 1] = add;
    for (int i = k; i < n + 1; i++) {
        tmp[i] = m[i - 1];
    }
    delete[] m;
    m = tmp;
    for (int i = 0; i < (k > n ? k : n + 1); i++) {
        cout << m[i] << '\n';
    }
    delete[] m;
    return 0;
}