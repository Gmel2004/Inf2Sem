#include <iostream>
using namespace std;

void ToMin(int h, int m);

void ToMin(double h);

void ToH(int m);

void ToH(double m);


int main() {
    setlocale(LC_ALL, "Rus");
    int a, b;
    double c;
    cout << "Введите кол-во часов, а затем минут: ";
    cin >> a >> b;
    cout << "Введите кол-во часов (доля часа = мантисса): ";
    cin >> c;
    ToMin(a, b);
    ToMin(c);
    return 0;
}


void ToMin(int h, int m) {
    int r = h * 60 + m;
    cout << r << " М.";
    ToH(r);
}

void ToMin(double h) {
    double r = (int)h * 60 + (h - (int)h) * 100 * 60.0 / 100;
    cout << r << " М.";
    ToH(r);
}

void ToH(int m) {
    int r[2] = { m / 60, m - m / 60 * 60 };
    cout << " это " << r[0] << " Ч. " << r[1] << " М.\n";
}

void ToH(double m) {
    double r[2] = { (double)(int)m / 60, m - (int) m / 60 * 60 };
    cout << " это " << (int)r[0] << " Ч. " << r[1] << " М.\n";
}