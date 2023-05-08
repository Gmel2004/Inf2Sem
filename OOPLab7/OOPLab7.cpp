#include <iostream>
using namespace std;
#include "List.h"
#include "Pair.h"

int main() {
    List <int> l;
    l << 5;
    l << 4;
    cout << "List<int>:\n";
    cout << l << '\n';
    List <Pair> p;
    Pair c;
    c.SetFirst(9);
    c.SetSecond(9.4);
    p << c;
    cout << "List<Pair>:\n";
    cout << p << '\n';
    return 0;
}
