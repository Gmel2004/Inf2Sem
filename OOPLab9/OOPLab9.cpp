#include <iostream>
using namespace std;
#include "List.h"
#include "Error.h"

int main() {
    system("chcp 1251 > NULL");
    try {
        List a(2);
        List b;
        cout << a << '\n';
        cout << b << '\n';
        cout << b[0];//Ошибка
        Iterator i = b.first();//Ошибка
        Iterator j = b.last();//Ошибка
        Iterator k = a.last();
        ++k;
        ++k;//Ошибка
        k + 1;//Ошибка
    }
    catch (Error& m_Error) {
        m_Error.What();
    }
    return 0;
}