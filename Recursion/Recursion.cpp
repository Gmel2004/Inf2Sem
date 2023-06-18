#include <iostream>
#include <cmath>
using namespace std;

double x;

double f(double n) {
    double s = cos((2 * n - 1) * x) / pow((2 * n - 1), 2);
    return n > 1 ? s + f(n - 1) : s;
}

int main() {
    double n;
    cin >> x >> n;
    cout << f(n);
    return 0;
}