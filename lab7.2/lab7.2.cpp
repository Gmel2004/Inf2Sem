#include <iostream>
#include <ctime>
#include <string>
#include <cstdarg>
using namespace std;

int n;

int days(string d1, ...);

int main() {
    setlocale(LC_ALL, "Rus");
    string m[8];
    cout << "Введите даты (дд.мм.гг): ";
    for (int i = 0; i < 8; i++) {
        cin >> m[i];
    }
    n = 2 - 1;
    cout << "Между " << m[0] << " и " << m[1] << ' ' << days(m[0], m[1]) << " Д.\n";
    n = 3 - 1;
    cout << "Между " << m[0] << ", " << m[1] << ", " << m[2] << ' ' << days(m[0], m[1], m[2]) << " Д.\n";
    n = 8 - 1;
    cout << "Между " << m[0] << ", " << m[1] << ", " << m[2] << ", " << m[3] << ", " << m[4] << ", " << m[5] << ", " << m[6] << ' '
        << m[7] << ' ' << days(m[0], m[1], m[2], m[3], m[4], m[5], m[6], m[7]) << " Д.\n";
    return 0;
}

int days(string d1, ...) {
    va_list ptr;
    va_start(ptr, d1);
    int s = 0;
    tm dateEnd = { 0, 0, 0, stoi(d1.substr(0, 2)), stoi(d1.substr(3, 2)) - 1, stoi(d1.substr(6, 2)) + 100 };
    time_t time2 = mktime(&dateEnd);
    while (n--) {
        time_t time1 = time2;
        string d2 = va_arg(ptr, string);
        dateEnd = { 0, 0, 0, stoi(d2.substr(0, 2)), stoi(d2.substr(3, 2)) - 1, stoi(d2.substr(6, 2)) + 100 };
        time2 = mktime(&dateEnd);
        s += time1 == time2 ? 0 : ((time1 > time2 ? time1 - time2 - 1 : time2 - time1 - 1)) / (60 * 60 * 24);
    }
    va_end(ptr);
    return s;
}