#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <Windows.h>

using namespace std;

#define MAX_NAME 50
#define MAX_SUBJECT 30

class Vedomost {
protected:
    struct Record {
        int student_id;
        char fio[MAX_NAME];
        int subject_code;
        char subject_name[MAX_SUBJECT];
        int mark;

        Record() { // Конструктор для инициализации
            memset(fio, 0, MAX_NAME);
            memset(subject_name, 0, MAX_SUBJECT);
        }
    };

    vector<Record> records;

public:
    // Добавление записи
    void input() {
        Record new_record;
        cout << "\nВведите данные студента:\n";

        cout << "Номер билета: ";
        cin >> new_record.student_id;
        cin.ignore();

        cout << "ФИО: ";
        cin.getline(new_record.fio, MAX_NAME);

        cout << "Код предмета: ";
        cin >> new_record.subject_code;
        cin.ignore();

        cout << "Название предмета: ";
        cin.getline(new_record.subject_name, MAX_SUBJECT);

        cout << "Оценка (0-100): ";
        cin >> new_record.mark;
        cin.ignore();

        records.push_back(new_record);
    }

    // Вывод всех записей
    void print_all() {
        cout << "\nВЕДОМОСТЬ\n";
        for (size_t i = 0; i < records.size(); i++) {
            cout << "Билет: " << records[i].student_id
                << "\tФИО: " << records[i].fio
                << "\tПредмет: " << records[i].subject_name
                << "\tОценка: " << records[i].mark << endl;
        }
    }

    // Сохранение в файл
    void save_to_file(const char* filename) {
        FILE* file = fopen(filename, "wb");
        if (file) {
            for (size_t i = 0; i < records.size(); i++) {
                fwrite(&records[i], sizeof(Record), 1, file);
            }
            fclose(file);
            cout << "Данные сохранены в файл '" << filename << "'\n";
        }
        else {
            cout << "Ошибка сохранения файла!\n";
        }
    }

    // Загрузка из файла
    void load_from_file(const char* filename) {
        FILE* file = fopen(filename, "rb");
        if (file) {
            records.clear(); // Очищаем старые данные
            Record temp;
            while (fread(&temp, sizeof(Record), 1, file)) {
                records.push_back(temp);
            }
            fclose(file);
            cout << "Данные загружены из файла '" << filename << "'\n";
        }
        else {
            cout << "Ошибка загрузки файла!\n";
        }
    }
};

class Uspevaemost : public Vedomost {
public:
    void show_stats() {
        if (records.empty()) {
            cout << "Нет данных для анализа!\n";
            return;
        }

        int total = 0;
        for (size_t i = 0; i < records.size(); i++) {
            total += records[i].mark;
        }
        cout << "\nСредний балл всех студентов: "
            << (float)total / records.size() << endl;
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    Uspevaemost journal;
    const char* filename = "data.bin";
    int choice;

    do {
        cout << "\n1. Добавить запись\n"
            << "2. Показать все\n"
            << "3. Сохранить в файл\n"
            << "4. Загрузить из файла\n"
            << "5. Показать статистику\n"
            << "0. Выход\n"
            << "Выбор: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: journal.input(); break;
        case 2: journal.print_all(); break;
        case 3: journal.save_to_file(filename); break;
        case 4: journal.load_from_file(filename); break;
        case 5: journal.show_stats(); break;
        }
    } while (choice != 0);

    return 0;
}