#include <iostream>
using namespace std;

const int n = 10;
int m[n] = { 45, 96, 73, 43, 64, 12, 90, 88, 23, 45 };

void Sort(int begin, int end) {
    if (begin < end) {
        int k = begin;
        for (int i = begin; i < end; i++) {
            if (m[i] < m[end]) {
                int c = m[i];
                m[i] = m[k];
                m[k] = c;
                k++;
            }
        }
        int c = m[k];
        m[k] = m[end];
        m[end] = c;
        Sort(begin, k - 1);
        Sort(k + 1, end);
    }
}

int main() { 
    Sort(0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << m[i] << ' ';
    }
    return 0;
}