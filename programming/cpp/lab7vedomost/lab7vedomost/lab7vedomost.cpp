#define _CRT_SECURE_NO_WARNINGS
#define MAX_NAME 50
#define MAX_SUBJECT 30

#include <iostream>
#include <cstdio>
#include <cstring>
#include <Windows.h>

using namespace std;



class Vedomost {
private:
    int student_id;
    char fio[MAX_NAME];
    int subject_code;
    char subject_name[MAX_SUBJECT];
    int mark;

public:
    void input() {
        cout << "\nВведите данные студента:\n";

        cout << "Номер билета: ";
        cin >> student_id;
        cin.ignore();

        cout << "ФИО: ";
        cin.getline(fio, MAX_NAME);

        cout << "Код предмета: ";
        cin >> subject_code;
        cin.ignore();

        cout << "Название предмета: ";
        cin.getline(subject_name, MAX_SUBJECT);

        cout << "Оценка (0-100): ";
        cin >> mark;
        cin.ignore();
    }

    void save_to_file(const char* filename) {
        FILE* fl = fopen(filename, "ab");
        if (!fl) {
            cout << "Ошибка открытия файла!\n";
            return;
        }
        fwrite(this, sizeof(Vedomost), 1, fl);
        fclose(fl);
    }

    static void print_all(const char* filename) {
        FILE* fl = fopen(filename, "rb");
        if (!fl) {
            cout << "Файл не найден!\n";
            return;
        }

        Vedomost temp;
        cout << "\nВсе записи:\n";
        while (fread(&temp, sizeof(Vedomost), 1, fl)) {
            cout << "Билет: " << temp.student_id
                << "\tФИО: " << temp.fio
                << "\tКод: " << temp.subject_code
                << "\tПредмет: " << temp.subject_name
                << "\tОценка: " << temp.mark << endl;
        }
        fclose(fl);
    }

    static void update_record(const char* filename) {
        FILE* fl = fopen(filename, "r+b");
        if (!fl) {
            cout << "Ошибка открытия файла!\n";
            return;
        }

        int search_id, search_code;
        cout << "Введите номер билета для поиска: ";
        cin >> search_id;
        cout << "Введите код предмета: ";
        cin >> search_code;
        cin.ignore();

        Vedomost temp;
        bool found = false;

        while (fread(&temp, sizeof(Vedomost), 1, fl)) {
            if (temp.student_id == search_id && temp.subject_code == search_code) {
                cout << "Текущая оценка: " << temp.mark
                    << "\nВведите новую оценку: ";
                cin >> temp.mark;
                cin.ignore();

                fseek(fl, -static_cast<long>(sizeof(Vedomost)), SEEK_CUR);
                fwrite(&temp, sizeof(Vedomost), 1, fl);
                found = true;
                break;
            }
        }

        if (!found) cout << "Запись не найдена!\n";
        fclose(fl);
    }

    static void calc_average(const char* filename) {
        FILE* fl = fopen(filename, "rb");
        if (!fl) {
            cout << "Ошибка открытия файла!\n";
            return;
        }

        int search_code;
        cout << "Введите код предмета: ";
        cin >> search_code;
        cin.ignore();

        Vedomost temp;
        int sum = 0, count = 0;

        while (fread(&temp, sizeof(Vedomost), 1, fl)) {
            if (temp.subject_code == search_code) {
                sum += temp.mark;
                count++;
            }
        }

        if (count > 0) {
            cout << "Средний балл: " << (float)sum / count << endl;
        }
        else {
            cout << "Записей по этому предмету нет!\n";
        }
        fclose(fl);
    }

    static void print_subject(const char* filename) {
        FILE* fl = fopen(filename, "rb");
        if (!fl) {
            cout << "Ошибка открытия файла!\n";
            return;
        }

        int search_code;
        cout << "Введите код предмета: ";
        cin >> search_code;
        cin.ignore();

        Vedomost temp;
        bool found = false;

        cout << "\nВедомость по предмету:\n";
        while (fread(&temp, sizeof(Vedomost), 1, fl)) {
            if (temp.subject_code == search_code) {
                if (!found) {
                    cout << "Предмет: " << temp.subject_name << endl;
                    found = true;
                }
                cout << "Билет: " << temp.student_id
                    << "\tФИО: " << temp.fio
                    << "\tОценка: " << temp.mark << endl;
            }
        }

        if (!found) cout << "Предмет не найден!\n";
        fclose(fl);
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    const char* filename = "vedomost.dat";
    int choice;

    do {
        cout << "\n1. Добавить запись\n2. Показать все\n3. Изменить оценку\n"
            "4. Средний балл\n5. Ведомость по предмету\n0. Выход\nВыбор: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            Vedomost v;
            v.input();
            v.save_to_file(filename);
            break;
        }
        case 2:
            Vedomost::print_all(filename);
            break;
        case 3:
            Vedomost::update_record(filename);
            break;
        case 4:
            Vedomost::calc_average(filename);
            break;
        case 5:
            Vedomost::print_subject(filename);
            break;
        }
    } while (choice != 0);

    return 0;
}