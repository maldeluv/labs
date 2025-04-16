#include <iostream>
#include <string>
using namespace std;

string z1(string s1, string s2) {
    return s1 + s2;
}

string z2(string s, char c) {
    string res;
    for (int i = 0; i < s.length(); i++) {
        res += s[i];
        if (s[i] == c) {
            res += c;
        }
    }
    return res;
}

bool z3(string s, char c, int& k, int& first, int& last) {
    int i;
    k = first = last = 0;
    if (s[0] == c) {
        i = 1;
        first = i;
        k++;
    }
    else {
        for (i = 1; i < s.size(); i++) {
            if (s[i] == c) {
                first = i;
                i++;
                k++;
                break;
            }
        }
    }
    
    for (i; i < s.size(); i++) {
        if (s[i] == c) {
            last = i;
            i++;
            k++;
        }
    }
    if (first) {
        if (first == 1) {
            if (last) {
                last++;
            }
            return true;
        }
        else {
            first++;
            if (last) {
                last++;
            }
            return true;
        }
    }
    else {
        return false;
    }
}

string z4(string s1, string s2, int N)
{
    string result;
    if (N > s1.length()) {
        result += s1 + s2;
    }
    else if (N <= 0) {
        result += s2 + s1;
    }
    else {
        for (int i = 0; i < N; i++) {
            result += s1[i];
        }
        result += s2;
        for (int i = N; i < s1.length(); i++) {
            result += s1[i];
        }
    }
    return result;
}

string z5(string s, int n)
{
    int len_str = s.length(), det = abs(len_str - n);
    string s_out;
    if (len_str > n) {
        for (int i = 0; i < n; i++) {
            s_out += s[det + i];
        }
    }
    else {
        for (int i = 0; i < det; i++) {
            s_out += ".";
        }
        for (int i = 0; i < n - det; i++) {
            s_out += s[i];
        }
    }
    return s_out;
}
string z6(string s1, string s2, int n1, int n2)
{
    string s;
    for (int i = 0; i < n1; i++) {
        s += s1[i];
    }
    for (int i = s2.length() - n2; i < s2.length(); i++) {
        s += s2[i];
    }
    return s;
}
bool z7(string s, string s0)
{
    int i, j, flag;
    for (i = 0; i < s.size() - s0.size() + 1; i++)
        if (s[i] == s0[0])
        {
            j = 1;
            flag = true;
            while (j < s0.size() and flag)
                if (s[i + j] != s0[j])
                    flag = false;
                else
                    j++;
            if (flag)
                return true;
        }
    return false;
}
int z8(string s, string s0)
{
    int i, j, flag, sum = 0;
    for (i = 0; i < s.size() - s0.size() + 1; i++)
        if (s[i] == s0[0])
        {
            j = 1;
            flag = true;
            while (j < s0.size() and flag)
                if (s[i + j] != s0[j])
                    flag = false;
                else
                    j++;
            if (flag)
            {
                sum++;
                i += s0.size() - 1;
            }
        }
    return sum;
}
int main()
{
    setlocale(LC_ALL, "RUS");
    cout << "Канкошев Малик\n";
    int n = 1;
    while (n != 0) {
        cout << "Введите номер задания ";
        cin >> n;
        switch(n) {
        case 1: {
            string s1, s2;
            cout << "Введите s1 ";
            cin >> s1;
            cout << "Введите s2 ";
            cin >> s2;
            cout << endl;
            cout << z1(s1, s2) << endl;
            break;
        }
            
        case 2: {
            string s;
            char c;
            cout << "Введите s ";
            cin >> s;
            cout << "Введите c ";
            cin >> c;
            cout << endl;
            cout << z2(s, c) << endl;
            break;
        }
        case 3:
        {
            string s;
            char c;
            int k, first, last;
            cout << "Введите строку: ";
            cin >> s;
            cout << "Введите символ: ";
            cin >> c;
            if (z3(s, c, k, first, last))
            {
                cout << "Количество вхождений '" << c << "': " << k << endl;
                if (last)
                {
                    cout << "Номер первого вхождения: " << first << endl;
                    cout << "Номер последнего вхождения: " << last << endl;
                }
                else
                    cout << "Номер вхождения '" << first << "': " << first << endl;
            }
            else
                cout << "Вхождений '" << c << "' в строке '" << s << "' нет" << endl;
            break;
        }
        case 4:
        {
            string s1, s2;
            int n;
            cout << "Введите строку 1: ";
            cin >> s1;
            cout << "Введите строку 2: ";
            cin >> s2;
            cout << "Введите число N: ";
            cin >> n;
            cout << "Результат: " << z4(s1, s2, n) << endl;
            break;
        }
        case 5:
        {
            string s;
            int N;
            cout << "Введите строку : ";
            cin >> s;
            cout << "Введите N, больше 0: ";
            cin >> N;
            cout << "Измененная строка: " << z5(s, N) << endl;
            break;
        }
        case 6:
        {
            string s1, s2;
            int n1, n2;
            cout << "Введите первую строку: ";
            cin >> s1;
            cout << "Введите вторую строку: ";
            cin >> s2;
            cout << "Введите целое положительное число N1: ";
            cin >> n1;
            cout << "Введите целое положительное число N2: ";
            cin >> n2;
            cout << "Новая строка: " << z6(s1, s2, n1, n2) << endl;
            break;
        }
        case 7:
        {
            string s, s0;
            cout << "Введите исходную строку: ";
            cin >> s;
            cout << "Введите подстроку: ";
            cin >> s0;
            if (z7(s, s0))
                cout << "Вхождения есть" << endl;
            else
                cout << "Вхождений нет" << endl;
            break;
        }
        case 8:
        {
            string s, s0;
            cout << "Введите исходную строку: ";
            cin >> s;
            cout << "Введите подстроку: ";
            cin >> s0;
            cout << "Количество вхождений: " << z8(s, s0) << endl;
            break;
        }
        
        
        }
    }

}
