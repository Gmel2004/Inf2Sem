#include <iostream>
using namespace std;

const int n = 10;
int m[n] = { 45, 96, 73, 43, 64, 12, 90, 88, 23, 45 };

void Marge(int begin, int end, int r) {
    int a = r + 1;
    int b = begin;
    int i = begin;
    int vm[n] = {};
    while (b <= r && a <= end) {
        if (m[a] < m[b]) {
            vm[i] = m[a];
            a++;
        }
        else {
            vm[i] = m[b];
            b++;
        }
        i++;
    }
    while (b <= r) {
        vm[i] = m[b];
        i++;
        b++;
    }
    while (a <= end) {
        vm[i] = m[a];
        i++;
        a++;
    }
    for (int j = begin; j < i; j++) {
        m[j] = vm[j];
    }
}

void Slice(int begin, int end) {
    if (begin < end) {
        int r = (begin + end) / 2;
        Slice(begin, r);
        Slice(r + 1, end);
        Marge(begin, end, r);
    }
}

int main() {
    Slice(0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << m[i] << ' ';
    }
    return 0;
}