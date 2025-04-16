#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <Windows.h>

using namespace std;

#define MAX_NAME 50
#define MAX_SUBJECT 30
#define MIN_SCHOLARSHIP 71
#define FILENAME "students.dat"

struct Record {
    int student_id;
    char fio[MAX_NAME];
    int subject_code;
    char subject_name[MAX_SUBJECT];
    int mark;

    Record() {
        memset(fio, 0, MAX_NAME);
        memset(subject_name, 0, MAX_SUBJECT);
    }
};

class Vedomost {
protected:
    void clear_buffer() {
        cin.ignore(1000, '\n');
    }

public:
    void input_record() {
        Record r;
        cout << "\nНомер билета: ";
        cin >> r.student_id;
        clear_buffer();

        cout << "ФИО студента: ";
        cin.getline(r.fio, MAX_NAME);

        cout << "Код предмета: ";
        cin >> r.subject_code;
        clear_buffer();

        cout << "Название предмета: ";
        cin.getline(r.subject_name, MAX_SUBJECT);

        cout << "Оценка (0-100): ";
        cin >> r.mark;
        clear_buffer();

        FILE* fp = fopen(FILENAME, "ab");
        if (fp) {
            fwrite(&r, sizeof(Record), 1, fp);
            fclose(fp);
            cout << "Запись сохранена!\n";
        }
        else {
            cout << "Ошибка записи!\n";
        }
    }

    void print_all() {
        cout << "\nВЕДОМОСТЬ\n";
        FILE* fp = fopen(FILENAME, "rb");
        if (fp) {
            Record temp;
            while (fread(&temp, sizeof(Record), 1, fp)) {
                cout << "Билет: " << temp.student_id
                    << "\tФИО: " << temp.fio
                    << "\tПредмет: " << temp.subject_name
                    << "\tОценка: " << temp.mark << endl;
            }
            fclose(fp);
        }
        else {
            cout << "Файл не найден!\n";
        }
    }
};

class Uspevaemost : public Vedomost {
public:
    void print_student_info(int student_id) {
        cout << "\nРезультаты студента " << student_id << ":\n";
        FILE* fp = fopen(FILENAME, "rb");
        if (fp) {
            Record temp;
            bool found = false;
            while (fread(&temp, sizeof(Record), 1, fp)) {
                if (temp.student_id == student_id) {
                    cout << temp.subject_name << " ("
                        << temp.subject_code << "): "
                        << temp.mark << endl;
                    found = true;
                }
            }
            if (!found) cout << "Студент не найден!\n";
            fclose(fp);
        }
    }

    void print_unique_students() {
        cout << "\nСписок студентов:\n";
        FILE* fp = fopen(FILENAME, "rb");
        if (fp) {
            Record temp;
            int prev_id = -1;
            while (fread(&temp, sizeof(Record), 1, fp)) {
                if (temp.student_id != prev_id) {
                    cout << temp.student_id << "\t" << temp.fio << endl;
                    prev_id = temp.student_id;
                }
            }
            fclose(fp);
        }
    }

    void print_unique_subjects() {
        cout << "\nСписок предметов:\n";
        FILE* fp = fopen(FILENAME, "rb");
        if (fp) {
            Record temp;
            int prev_id = -1;
            while (fread(&temp, sizeof(Record), 1, fp)) {
                if (temp.subject_code != prev_id) {
                    cout << temp.subject_code << "\t" << temp.subject_name << endl;
                    prev_id = temp.subject_code;
                }
            }
            fclose(fp);
        }
    }

    void print_subjects_with_avg() {
        cout << "\nПредметы со средним баллом:\n";
        FILE* fp = fopen(FILENAME, "rb");
        if (fp) {
            Record temp;
            int codes[100] = { 0 };
            int counts[100] = { 0 };
            int totals[100] = { 0 };

            while (fread(&temp, sizeof(Record), 1, fp)) {
                for (int i = 0; i < 100; i++) {
                    if (codes[i] == 0) {
                        codes[i] = temp.subject_code;
                        counts[i] = 1;
                        totals[i] = temp.mark;
                        break;
                    }
                    if (codes[i] == temp.subject_code) {
                        counts[i]++;
                        totals[i] += temp.mark;
                        break;
                    }
                }
            }

            for (int i = 0; i < 100 && codes[i] != 0; i++) {
                cout << codes[i] <<"\t"<< temp.subject_name << "\tСредний балл: "
                    << (float)totals[i] / counts[i] << endl;
            }
            fclose(fp);
        }
    }

    void print_students_with_avg() {
        cout << "\nСтуденты со средним баллом:\n";
        FILE* fp = fopen(FILENAME, "rb");
        if (fp) {
            Record temp;
            int codes[100] = { 0 };
            int counts[100] = { 0 };
            int totals[100] = { 0 };

            while (fread(&temp, sizeof(Record), 1, fp)) {
                for (int i = 0; i < 100; i++) {
                    if (codes[i] == 0) {
                        codes[i] = temp.student_id;
                        counts[i] = 1;
                        totals[i] = temp.mark;
                        break;
                    }
                    if (codes[i] == temp.student_id) {
                        counts[i]++;
                        totals[i] += temp.mark;
                        break;
                    }
                }
            }

            for (int i = 0; i < 100 && codes[i] != 0; i++) {
                cout << codes[i] <<"\t"<< temp.fio << "\tСредний балл: "
                    << (float)totals[i] / counts[i] << endl;
            }
            fclose(fp);
        }
    }
    void print_scholarship_candidates() {
        cout << "\nКандидаты на стипендию (мин. " << MIN_SCHOLARSHIP << " баллов)\n";
        FILE* fp = fopen(FILENAME, "rb");
        if (fp) {
            Record temp;
            const int MAX_STUDENTS = 100;
            int codes[MAX_STUDENTS] = { 0 };
            int count = 0;
            while (fread(&temp, sizeof(Record), 1, fp) && count < MAX_STUDENTS) {
                bool exists = false;
                for (int i = 0; i < count; i++) {
                    if (codes[i] == temp.student_id) {
                        exists = true;
                        break;
                    }
                }
                if (!exists) {
                    codes[count++] = temp.student_id;
                }
            }
            for (int i = 0; i < count; i++) {
                bool eligible = true;
                fseek(fp, 0, SEEK_SET);
                while (fread(&temp, sizeof(Record), 1, fp)) {
                    if (temp.student_id == codes[i]) {
                        if (temp.mark < MIN_SCHOLARSHIP) {
                            eligible = false;
                        }
                    }
                }
                if (eligible) {
                    fseek(fp, 0, SEEK_SET);
                    while (fread(&temp, sizeof(Record), 1, fp)) {
                        if (temp.student_id == codes[i]) {
                            cout << "Студент: " << temp.fio
                                << " (ID: " << temp.student_id
                                << ")\n";
                            break;
                        }
                    }
                }
            }
            fclose(fp);
        }
        else {
            cout << "Файл не найден!\n";
        }
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    Uspevaemost system;
    int choice;

    do {
        cout << "\n=== Система управления успеваемостью ===\n"
            << "1. Добавить запись\n"
            << "2. Показать все записи\n"
            << "3. Информация по студенту\n"
            << "4. Список студентов\n"
            << "5. Список предметов\n"
            << "6. Предметы с средним баллом\n"
            << "7. Студенты с средним баллом\n"
            << "8. Студенты на стипендию\n"
            << "0. Выход\n"
            << "Выбор: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: system.input_record(); break;
        case 2: system.print_all(); break;
        case 3: {
            int id;
            cout << "Введите номер студента: ";
            cin >> id;
            system.print_student_info(id);
            break;
        }
        case 4: system.print_unique_students(); break;
        case 5: system.print_unique_subjects(); break;
        case 6: system.print_subjects_with_avg(); break;
        case 7: system.print_students_with_avg(); break;
        case 8: system.print_scholarship_candidates(); break;
        }
    } while (choice != 0);

    return 0;
}