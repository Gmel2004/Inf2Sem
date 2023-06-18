#include <iostream>
#include <cmath>
using namespace std;

int main() {
    setlocale(LC_ALL, "Rus");
    double x1, x2, a, b, e;
    bool solution = true;
    cin >> a >> b >> e;
    if ((sin(a) - 0.4) * -sin(a) > 0) {
        x2 = a;
    }
    else if ((sin(b) - 0.4) * -sin(b) > 0) {
        x2 = b;
    }
    else {
        cout << "Точки не подходят для нахождения решения";
        solution = false;
    }
    if (solution) {
        int k = 0;
        do {
            k++;
            x1 = x2;
            x2 = x1 - (sin(x1) - 0.4) / cos(x1);
            if (x2 > b || x2 < a) {
                solution = false;
            }
        } while (abs(x2 - x1) > e && solution);
        if (solution) {
            cout << "Решение: " << x2 << '\n' << "Найдено за " << k << " итераций цикла" << '\n';
        }
        else {
            cout << "Решения нет!";
        }
    }
    return 0;
}