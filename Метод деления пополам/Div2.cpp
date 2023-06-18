#include <iostream>
#include <cmath>
using namespace std;

int main() {
    setlocale(LC_ALL, "Rus");
    double a, b, e, x{};
    cin >> a >> b >> e;
    int k = 0;
    bool solution = true;
    while (abs(a - b) > e && solution) {
        k++;
        x = (a + b) / 2;
        if ((sin(x) - 0.4) * (sin(b) - 0.4) < 0) {
            a = x;
        }
        else if ((sin(x) - 0.4) * (sin(a) - 0.4) < 0) {
            b = x;
        }
        else {
            cout << "Решений нет!";
            solution = false;
        }
    }
    if (solution) {
        cout << "Решение: " << x << '\n' << "Найдено за " << k << " итераций цикла" << '\n';
    }
    return 0;
}
