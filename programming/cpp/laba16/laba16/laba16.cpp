#include <iostream> 
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

string z2(string str, int k) {
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string output = str;

    for (int i = 0; i < str.length(); i++) {
        for (int j = 0; j < alphabet.length(); j++) {
            if (str[i] == alphabet[j]) {
                if (j + k < 26) {
                    output[i] = alphabet[j + k];
                }
                else {
                    output[i] = alphabet[j - 26 + k];
                }
            }
        }
    }
    return output;
}

string z3(string str, int k) {
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string output = str;

    for (int i = 0; i < str.length(); i++) {
        for (int j = 0; j < alphabet.length(); j++) {
            if (str[i] == alphabet[j]) {
                if (j - k < 0) {
                    output[i] = alphabet[26 + (j - k)];
                }
                else {
                    output[i] = alphabet[j - k];
                }
            }
        }
    }
    return output;
}

bool z4(string str)
{
    int j = str.length() - 1;
    for (int i = 0; i < str.length() / 2; i++) {
        if (str[i] == str[j]) {
            j--;
        }
        else {
            return false;
        }
    }
    return true;
}

int main() {
    setlocale(LC_ALL, "RUS");
    int n = 1;
    cout << "Канкошев Малик\n";
    while (n != 0)
    {

        cout << "Введите номер задания: ";
        cin >> n;
        switch (n)
        {
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
            int K;
            cout << "Введите строку: " << endl;
            cin >> s;
            cout << "Введите шаг K: " << endl;
            cin >> K;
            cout << "Результат: " << z2(s, K) << endl;
            break;
        }

        case 3:
        {
            string s;
            int K;
            cout << "Введите строку: " << endl;
            cin >> s;
            cout << "Введите шаг K: " << endl;
            cin >> K;
            cout << "Результат: " << z3(s, K) << endl;
            break;
        }

        case 4:
        {
            string s;
            cout << "Введите строку: " << endl;
            cin >> s;
            cout << "Результат: ";
            if (z4(s) == 0) cout << "не ";
            cout << "палиндром" << endl;
            break;
        }
        }
    }
}
