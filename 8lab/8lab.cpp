#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

int n;
FILE* file;
bool existsf = false;
char surename[255];

struct Student {
    char f[255];
    char i[255];
    char o[255];
    char dateofbirth[255];
    char address[255];
    char rating[255];
};

Student student2;

void ShowFile() {
    system("cls");
    if (n > 0) {
        if ((file = fopen("Students.txt", "rb")) == NULL) {
            cout << "Ошибка чтения файлов\n";
        }
        else {
            int k = 0;
            while (!feof(file) && k < n) {
                Student student;
                fread(&student, sizeof(Student), 1, file);
                cout << "ФИО: " << student.f << ' ' << student.i << ' ' << student.o << ' ' << '\n';
                cout << "Дата рождения: " << student.dateofbirth << '\n';
                cout << "Адрес: " << student.address << '\n';
                cout << "Рейтинг: " << student.rating << '\n';
                cout << "_______________________________________________________________\n";
                k++;
            }
            fclose(file);
        }
    }
    else {
        cout << "Список студентов пуст!\n";
    }
}

void AddCur() {
    FILE* file1;
    FILE* file2;
    if (((file1 = fopen("Students.txt", "rb")) == NULL) || ((file2 = fopen("tmp.txt", "wb")) == NULL)) {
        cout << "Ошибка чтения файлов\n";
    }
    else {
        int k = 0;
        int nums = n;
        while (!feof(file1) && k < nums) {
            Student student;
            fread(&student, sizeof(Student), 1, file1);
            if (!existsf) {
                if (!strcmp(surename, student.f)) {
                    existsf = true;
                    fwrite(&student2, sizeof(Student), 1, file2);
                    n++;
                }
                fwrite(&student, sizeof(Student), 1, file2);
            }
            else {
                fwrite(&student, sizeof(Student), 1, file2);
            }
            k++;
        }
        fclose(file1);
        fclose(file2);
        remove("Students.txt");
        rename("tmp.txt", "Students.txt");
    }
}

void AddStudent() {
    system("cls");
    Student newstudent;
    Student* newstudent_p = &newstudent;
    cout << "Как зовут студента (ФИО)?\n";
    cin >> newstudent.f;
    cin >> newstudent.i;
    cin >> newstudent.o;
    cout << "Когда родился " << newstudent_p->i << "?\n";
    cin.get();
    cin.getline(newstudent.dateofbirth, 255);
    cout << "Где живёт " << newstudent_p->i << "?\n";
    cin.getline(newstudent.address, 255);
    cout << "Какой рейтинг имеет " << newstudent_p->i << "?\n";
    cin.getline(newstudent.rating, 255);
    cout << '\n';
    fwrite(&newstudent, sizeof(Student), 1, file);
}

void TryAddStudent() {
    if (n) {
        if ((file = fopen("Students.txt", "ab")) == NULL) {
            cout << "Ошибка чтения файлов\n";
        }
        else {
            n += 1;
            AddStudent();
            fclose(file);
        }
    }
    else {
        system("cls");
        cout << "Не возможно добавить студента в пустой список\n";
    }
}

void AddStudents() {
    system("cls");
    cout << "Введите количество студентов: ";
    cin >> n;
    if ((file = fopen("Students.txt", "wb")) == NULL) {
        cout << "Ошибка чтения файлов\n";
    }
    else {
        for (int i = 0; i < n; i++) {
            AddStudent();
        }
        fclose(file);
    }
}

void CreateStudent() {
    system("cls");
    if (n) {
        existsf = false;
        cout << "Введите фамилию: ";
        cin >> surename;
        system("cls");
        Student* student2_p = &student2;
        cout << "Как зовут студента (фИО)?\n";
        cin >> student2.f;
        cin >> student2.i;
        cin >> student2.o;
        cout << "Когда родился " << student2_p->i << "?\n";
        cin.get();
        cin.getline(student2.dateofbirth, 255);
        cout << "Где живёт " << student2_p->i << "?\n";
        cin.getline(student2.address, 255);
        cout << "Какой рейтинг имеет " << student2_p->i << "?\n";
        cin.getline(student2.rating, 255);
        cout << '\n';
        AddCur();
        if (!existsf) {
            cout << "Студент с данной фамилией не найден\n";
        }
    }
    else {
        cout << "Невозможно добавить студента в пустой список\n";
    }
}

void DelEqualD() {
    system("cls");
    if (n > 1) {
        FILE* file1;
        FILE* file2;
        if (((file1 = fopen("Students.txt", "rb")) == NULL) || ((file2 = fopen("tmp.txt", "wb")) == NULL)) {
            cout << "Ошибка чтения файлов\n";
        }
        else {
            int nums = n;
            int k = 0;
            string* births = new string[n]{};
            while (!feof(file1) && k < nums) {
                Student student;
                fread(&student, sizeof(Student), 1, file1);
                births[k] = student.dateofbirth;
                k++;
            }
            fclose(file1);
            int* repeats = new int[n] {};
            for (int i = 0; i < n - 1; i++) {
                if (!repeats[i]) {
                    for (int j = i + 1; j < n; j++) {
                        if (births[i] == births[j]) {
                            repeats[i] = 1;
                            repeats[j] = 1;
                        }
                    }
                }
            }
            k = 0;
            fclose(file1);
            file1 = fopen("Students.txt", "rb");
            while (!feof(file1) && k < nums) {
                Student student;
                fread(&student, sizeof(Student), 1, file1);
                if (repeats[k]) {
                    n--;
                }
                else {
                    fwrite(&student, sizeof(Student), 1, file2);
                }
                k++;
            }
            delete[] births;
            delete[] repeats;
            fclose(file1);
            fclose(file2);
            remove("Students.txt");
            rename("tmp.txt", "Students.txt");
        }
    }
    else {
        cout << "Выполнение данной команды невозможно, добавьте студентов!\n";
    }
}

int main() {
    system("chcp 1251>NULL");
    int a;
    while (true) {
        cout << "Введите номер команды:\n1. Создать новый список студентов\n2. Добавить Студента\n3. Добавить студента перед указанной фамилией\n4. Удалить студентов с одинаковой датой рождения\n5. Показать список студентов\n";
        cin >> a;
        switch (a) {
            case 1:
                AddStudents();
                break;
            case 2:
                TryAddStudent();
                break;
            case 3:
                CreateStudent();
                break;
            case 4:
                DelEqualD();
                break;
            default:
                ShowFile();
                break;
        }
    }
    return 0;
}