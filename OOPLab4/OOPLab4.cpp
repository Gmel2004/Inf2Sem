#include "Person.h"
#include "Student.h"

void getObject(Student& object) {//функция принимающая объект
	object.setName("Дима");
	object.setAge(15);
	object.setSubject("Физика");
	object.setMark(3);
}

Student ReturnObject() {//функция возвращающая объект
	Student s("Антон", 21, "Информатика", 5);
	return s;
}

int main() {
	system("chcp 1251 > NULL");
	Person p1("Миша", 3);//Миша ещё не ученик
	cout << p1;//выводим значения
	cin >> p1;//вводим новые знаения
	cout << p1;//проверяем значения
	Student s1("Олег", 23, "inf", 4);//У Олега, как и у любого человека есть имя и возвраст, а как у ученика - предмет и оценка
	Student s2;
	getObject(s2);//установка значений через функцию
	cout << s2.getName() << ' ' << s2.getAge() << ' ' << s2.getSubject() << ' ' << s2.getMark() << '\n';//проверка значений
	Student s3 = ReturnObject();//создание объекта через функцию
	cout << s3;//проверка значений
	cin >> s3;//считываем новые значения для s3
	s2 = s3;//заменяем значения s2 соответствующими значениями s3
	cout << s2;//проверяем значение
	s2.BadMark();//проверяем оценку (выведет сообщение, если плохая)
	return 0;
}