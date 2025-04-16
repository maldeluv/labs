#include <iostream>
#include <string>
using namespace std;

string z1(string s1, string s2) {
    return s1 + s2;
}

string z2(string s1, char ch) {
    string res;
    for (int i = 0; i < s1.length(); i++) {
        res += s1[i];
        if (s1[i] == ch) {
            res += ch;
        }
    }
    return res;
}

int main()
{
    setlocale(LC_ALL, "RUS");
    cout << "Канкошев Малик\n";
    int n = 1;
    while (n != 0) {
        cout << "Введите номер задания ";
        cin >> n;
        switch (n) {
        case 1:
            string s1, s2;
            cout << "Введите s1 ";
            cin >> s1;
            cout << "Введите s2 ";
            cin >> s2;
            cout << endl;
            cout << z1(s1, s2) << endl;
            break;
        case 2:
            string s1;
            char ch;
            cout << "Введите s ";
            cin >> s1;
            cout << "Введите c ";
            cin >> ch;
            cout << endl;
            cout << z2(s1, ch) << endl;
            break;
        }
    }

}

