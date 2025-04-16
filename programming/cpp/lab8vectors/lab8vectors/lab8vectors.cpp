#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <Windows.h>

#define MAX_NAME 50
#define MAX_SUBJECT 30
#define MIN_SCHOLARSHIP 71
using namespace std;

class Vedomost {
protected:
    struct Record {
        int student_id;
        char fio[MAX_NAME];
        int subject_code;
        char subject_name[MAX_SUBJECT];
        int mark;
    };
    vector<Record> records;
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
        records.push_back(r);
    }
    void save_to_file(const char* filename) {
        FILE* fl = fopen(filename, "wb");
        if (fl) {
            for (size_t i = 0; i < records.size(); i++) {
                fwrite(&records[i], sizeof(Record), 1, fl);
            }
            fclose(fl);
            cout << "Данные сохранены!\n";
        }
        else {
            cout << "Ошибка сохранения!\n";
        }
    }
    void load_from_file(const char* filename) {
        FILE* fl = fopen(filename, "rb");
        if (fl) {
            records.clear();
            Record temp;
            while (fread(&temp, sizeof(Record), 1, fl)) {
                records.push_back(temp);
            }
            fclose(fl);
            cout << "Данные загружены!\n";
        }
        else {
            cout << "Ошибка загрузки!\n";
        }
    }
};
class Uspevaemost : public Vedomost {
public:
    void print_student_info(int student_id) {
        cout << "\nРезультаты студента " << student_id << ":\n";
        bool found = false;
        for (size_t i = 0; i < records.size(); i++) {
            if (records[i].student_id == student_id) {
                cout << records[i].subject_name << " ("
                    << records[i].subject_code << "): "
                    << records[i].mark << endl;
                found = true;
            }
        }
        if (!found) cout << "Студент не найден!\n";
    }
    void print_unique_students() {
        cout << "\nСписок студентов:\n";
        vector<int> shown_ids;
        for (size_t i = 0; i < records.size(); i++) {
            bool exists = false;
            for (size_t j = 0; j < shown_ids.size(); j++) {
                if (shown_ids[j] == records[i].student_id) {
                    exists = true;
                    break;
                }
            }
            if (!exists) {
                cout << records[i].student_id << "\t"
                    << records[i].fio << endl;
                shown_ids.push_back(records[i].student_id);
            }
        }
    }
    void print_unique_subjects() {
        cout << "\nСписок предметов:\n";
        vector<int> shown_codes;
        for (size_t i = 0; i < records.size(); i++) {
            bool exists = false;
            for (size_t j = 0; j < shown_codes.size(); j++) {
                if (shown_codes[j] == records[i].subject_code) {
                    exists = true;
                    break;
                }
            }
            if (!exists) {
                cout << records[i].subject_code << "\t"
                    << records[i].subject_name << endl;
                shown_codes.push_back(records[i].subject_code);
            }
        }
    }
    void print_subjects_with_avg() {
        cout << "\nПредметы со средним баллом:\n";
        vector<int> subject_codes;
        vector<string> subject_names;
        vector<float> averages;

        for (size_t i = 0; i < records.size(); i++) {
            bool exists = false;
            for (size_t j = 0; j < subject_codes.size(); j++) {
                if (subject_codes[j] == records[i].subject_code) {
                    exists = true;
                    break;
                }
            }
            if (!exists) {
                subject_codes.push_back(records[i].subject_code);
                subject_names.push_back(records[i].subject_name);
                averages.push_back(0.0f);
            }
        }
        for (size_t i = 0; i < subject_codes.size(); i++) {
            int total = 0, count = 0;
            for (size_t j = 0; j < records.size(); j++) {
                if (records[j].subject_code == subject_codes[i]) {
                    total += records[j].mark;
                    count++;
                }
            }
            averages[i] = (float)total / count;
        }

        for (size_t i = 0; i < subject_codes.size(); i++) {
            cout << subject_codes[i] << "\t" << subject_names[i]
                << "\tСредний: " << averages[i] << endl;
        }
    }
    void print_students_with_avg() {
        cout << "\nCтуденты со средним баллом:\n";
        vector<int> student_codes;
        vector<string> student_names;
        vector<float> averages;

        for (size_t i = 0; i < records.size(); i++) {
            bool exists = false;
            for (size_t j = 0; j < student_codes.size(); j++) {
                if (student_codes[j] == records[i].student_id) {
                    exists = true;
                    break;
                }
            }
            if (!exists) {
                student_codes.push_back(records[i].student_id);
                student_names.push_back(records[i].fio);
                averages.push_back(0.0f);
            }
        }

        for (size_t i = 0; i < student_codes.size(); i++) {
            int total = 0, count = 0;
            for (size_t j = 0; j < records.size(); j++) {
                if (records[j].student_id == student_codes[i]) {
                    total += records[j].mark;
                    count++;
                }
            }
            averages[i] = (float)total / count;
        }

        for (size_t i = 0; i < student_codes.size(); i++) {
            cout << student_codes[i] << "\t" << student_names[i]
                << "\tСредний: " << averages[i] << endl;
        }
    }
    void print_scholarship_candidates() {
        cout << "\nСтуденты на стипендию:\n";
        vector<int> student_ids;

        for (size_t i = 0; i < records.size(); i++) {
            bool exists = false;
            for (size_t j = 0; j < student_ids.size(); j++) {
                if (student_ids[j] == records[i].student_id) {
                    exists = true;
                    break;
                }
            }
            if (!exists) {
                bool eligible = true;
                for (size_t j = 0; j < records.size(); j++) {
                    if (records[j].student_id == records[i].student_id
                        && records[j].mark < MIN_SCHOLARSHIP) {
                        eligible = false;
                        break;
                    }
                }
                if (eligible) {
                    cout << records[i].student_id << "\t"
                        << records[i].fio << endl;
                    student_ids.push_back(records[i].student_id);
                }
            }
        }
    }
};
int main() {
    setlocale(LC_ALL, "RU");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    Uspevaemost u;
    const char* filename = "Uspevaemost.bin";
    int choice;
    do {
        cout << "\n1. Добавить запись\n"
            << "2. Сохранить данные\n"
            << "3. Загрузить данные\n"
            << "4. Информация по студенту\n"
            << "5. Список студентов\n"
            << "6. Список предметов\n"
            << "7. Предметы с средним баллом\n"
            << "8. Студенты с средним баллом\n"
            << "9. Студенты на стипендию\n"
            << "0. Выход\n"
            << "Выбор: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
        case 1: u.input_record(); break;
        case 2: u.save_to_file(filename); break;
        case 3: u.load_from_file(filename); break;
        case 4: {
            int id;
            cout << "Введите номер студента: ";
            cin >> id;
            u.print_student_info(id);
            break;
        }
        case 5: u.print_unique_students(); break;
        case 6: u.print_unique_subjects(); break;
        case 7: u.print_subjects_with_avg(); break;
        case 8: u.print_students_with_avg(); break;
        case 9: u.print_scholarship_candidates(); break;
        }
    } while (choice != 0);
    return 0;
}

