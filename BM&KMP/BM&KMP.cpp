#include <iostream>
#include <string>
using namespace std;

string sub, s;

int BM() {
    unsigned int shift[256];
    for (int i = 0; i < 256; i++) {
        shift[i] = sub.length();
    }
    for (int i = sub.length() - 2; i >= 0; i--) {
        if (shift[sub[i] + 128] == sub.length()) {
            shift[sub[i] + 128] = sub.length() - 1 - i;
        }
    }
    int ei = sub.length() - 1;
    while (ei < s.length()) {
        bool find = true;
        for (int i = sub.length() - 1; i >= 0 && find; i--) {
            if (s[ei - sub.length() + 1 + i] != sub[i]) {
                ei += shift[s[ei - sub.length() + 1 + i] + 128];
                find = false;
            }
        }
        if (find) {
            return ei - sub.length() + 1;
        }
    }
    return -1;
}

int KMP() {
    int* t = new int[sub.length()] {};
    int k = -1;
    t[0] = -1;
    int i = 0;
    while(i < sub.length() - 1) {
        while (k >= 0 && sub[i] != sub[k]) {
            k = t[k];
        }
        i++;
        k++;
        if (sub[i] == sub[k]) {
            t[i] = t[k];
        }
        else {
            t[i] = k;
        }
    }
    for (int i = 0; i < sub.length(); i++) cout << t[i] << ' ';
    cout << '\n';
    for (i = 0, k = 0; i < s.length() && k < sub.length(); i++, k++) {
        while (k >= 0 && sub[k] != s[i]) {
            k = t[k];
        }
    }
    delete[] t;
    if (k == sub.length()) {
        return i - k;
    }
    else {
        return -1;
    }
}

int main() {
    system("chcp 1251 > Null");
    cout << "Введите строку, в которой требуется найти образ: ";
    cin >> s;
    cout << "Введите образ: ";
    cin >> sub;
    //cout << BM();
    cout << KMP();
    return 0;
}