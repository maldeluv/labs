#include <iostream>
#include <string>
using namespace std;

string z1(string file) {
    string str = "";
    int k = 0;
    for (int i = 0; i < file.length(); i++) {
        if (k == 1) {
            if (file[i] == '\\') {
                k++;
                break;
            }
            if (str == "\\") {
                str = "";
            }
            str += file[i];
        }
        if (k == 0 && file[i] == '\\') {
            k++;
            if (k == 1) {
                str = '\\';
            }
        }
    }
    return str;
}

string z2(string predl, int k) {
    string alph = "abcdefghijklmnopqrstuvwxyz";
    string out = predl;

    for (int i = 0; i < predl.length(); i++) {
        for (int j = 0; i < alph.length(); j++) {
            if (predl[i] == alph[j]) {
                if (j + k < 26) {
                    out[i] = alph[j + k];
                }
                else {
                    out[i] = alph[j - 26 + k];
                }
            }
        }
    }
    return out;
}

int main()
{
    setlocale(LC_ALL, "RUS");
    int n = 1;
    cout << "Канкошев Малик\n";
    while (n != 0) {
        cout << "Введите номер задания ";
        cin >> n;
        cout << endl;
        switch (n) {
        case 1:
        {
            string file;
            cout << "Введите путь к файлу ";
            cin >> file;
            cout << "Первый каталог " << z1(file) << endl;
            break;
        }
        case 2:
        {
            string s;
            int k;
            cout << "Введите строку ";
            cin >> s;
            cout << "Введите k(0<k<10) ";
            cin >> k;
            cout << "Зашифрованная строка " << z2(s, k) << endl;
        }
        }
            
    }
}
