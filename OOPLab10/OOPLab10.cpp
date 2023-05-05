#include <iostream>
using namespace std;
#include "file_work.h"
using namespace std;
#include <string>
#include <functional>

int main() {
	system("chcp 1251 > NULL");
	int choose = 6;
	function<int()> f[5] = {make_file, print_file, del_file, change_file, add_file};
	do {
		if (choose != 6) {
			check_k(f[choose - 1]());
		}
		cout << "Введите номер команды:\n1. Создать файл\n2. Печать файла\n3. Удалить все записи меньше заданного значения\n4. Увеличить все записи с заданным значением на число L\n5. Добавить K записей перед элиментом с заданным номером\n6. Выход\n";
		cin >> choose;
		system("cls");
	} while (choose != 6);
	return 0;
}
