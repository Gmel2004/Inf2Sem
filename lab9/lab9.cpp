#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int n;

void CreateF1() {
    ofstream F1("F1.txt");
    string s;
    cin.get();
    for (int i = 0; i < n; i++) {
        cout << "Введите строку " << i + 1 << ": ";
        getline(cin, s);
        F1 << s << '\n';
    }
    F1.close();
}

void Repeats() {
    ifstream F1("F1.txt");
    ofstream F2("F2.txt");
    string s;
    while (getline(F1, s)) {
        string* m = new string [s.length() / 2 + 1];
        string v = "";
        int count = 0;
        for (char i : s) {
            if (i != 32) {
                v += i;
            }
            else if (v.length() != 0) {
                m[count] = v;
                count++;
                v = "";
            }
        }
        if (v.length() != 0) {
            m[count] = v;
            count++;
            v = "";
        }
        bool r = false;
        for (int j = 0; j < count - 1 && !r; j++) {
            for (int k = j + 1; k < count && !r; k++) {
                if (m[j] == m[k]) {
                    r = true;
                }
            }
        }
        delete[] m;
        if (r) {
            F2 << s << '\n';
        }
    }
    F1.close();
    F2.close();
}

void MaxDigits() {
    ifstream F1("F1.txt");
    string s;
    int num = 0;
    int mx = 0;
    int mn = 0;
    while (F1 >> s) {
        int count = 0;
        num++;
        for (char i : s) {
            if (i > 47 && i < 58) {
                count++;
            }
        }
        if (count > mx) {
            mx = count;
            mn = num;
        }
    }
    cout << "Номер слова с наибольшим количеством цифр: " << mn;
    F1.close();
}

void ShowF2() {
    ifstream F2("F2.txt");
    string s;
    while (getline(F2, s)) {
        cout << s << '\n';
    }
    F2.close();
}

int main() {
    system("chcp 1251>NULL");
    cout << "Введите количество строк: ";
    cin >> n;
    CreateF1();
    Repeats();
    cout << "\nФайл F2:\n";
    ShowF2();
    cout << '\n';
    MaxDigits();
    return 0;
}