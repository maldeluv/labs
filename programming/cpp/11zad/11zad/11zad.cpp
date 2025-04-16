// 11zad.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

void z1() {
    int arr[10], i, k, l, s = 0;
    double count = 0;
    cout << "Введите номера элементов массива ";
    cin >> k >> l;
    cout << endl;
    for (i = k; i <= l; i++) {
        arr[i] = rand() % 1000 - 500;
        s += arr[i];
        count++;
        cout << i << " " << arr[i] << endl;
    }
    cout << "Сумма элементов массива " << s << endl;
    cout << "Среднее арифметическое равно " << s / count << endl;
}

void z2() {
    double min=500, max=-500;
    int arr[10], i;
    for (i = 0; i < 10; i++) {
        arr[i] = rand() % 1000 - 500;
        cout << i << " " << arr[i] << endl;
    }
    if (arr[0] < arr[1]) {
        min = arr[0];
        if (min > max) {
            max = min;
        }
    }
    
    for (i = 1; i < 9; i++) {
        if ((arr[i] < arr[i-1])&&(arr[i]<arr[i+1])) {
            min = arr[i];
            if (min > max) {
                max = min;
            }
        }
        
    }
    if (arr[9] < arr[8]) {
        min = arr[9];
        if (min > max) {
            max = min;
        }
    }
    
    cout << "Максимальный из всех локальных минимумов равен " << max << endl;
}

void z3() {
    double r, a, modul=500;
    int arr[10], i;
    cout << "Введите R ";
    cin >> r;
    cout << endl;
    for (i = 0; i < 10; i++) {
        arr[i] = rand() % 1000 - 500;
        if ((abs(arr[i] - r)) < modul) {
            modul = abs(arr[i] - r);
            a = arr[i];
        }
        cout << i << " " << arr[i] << endl;
    }
    cout << "Самое близкое число " << a << endl;
}

void z4() {
    int arr[10], i;
    double b[10];
    for (i = 0; i < 10; i++) {
        arr[i] = rand() % 1000 - 500;
        if (arr[i] < 5) {
            b[i] = 2 * arr[i];
        }
        else {
            b[i] = arr[i] / 2.0;
        }
        cout << i << " " << arr[i] << "\n" << i << " " << b[i] << endl;
    }

}

void z5() {
    int i, arr[10], b[10], s = 0;
    for (i = 0; i < 10; i++) {
        arr[i] = rand() % 1000 - 500;
        s += arr[i];
        b[i] = s;
        cout << i << " " << arr[i] << "\n" << i << " " << b[i] << endl;
    }

}

void z6() {
    int arr[10], i;
    cout << "Начальный массив " << endl;
    for (i = 0; i < 10; i++) {
        arr[i] = rand() % 1000 - 500;
        cout << i << " " << arr[i] << endl;
    }
    for (i = 9; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = 0;
    cout << "Массив со сдвигом " << endl;
    for (i = 0; i < 10; i++) {
        cout << i << " " << arr[i] << endl;
    }
}

void z7() {
    const int n = 10;
    int i, j, a[n], b;
    cout << "Начальный массив" << endl;
    for (i = 0; i < n; i++) {
        a[i] = rand() % 1000 - 500;
        cout << i << " " << a[i] << endl;
    }
    
    for (i = 0; i < (n - 1); i++) {
        for (j = 0; j < 10 - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                b = a[j + 1];
                a[j + 1] = a[j];
                a[j] = b;
            }
        }
    }
    cout << "Сортированный массив" << endl;
    for (i = 0; i < n; i++) {
        cout << i << " " << a[i] << endl;
    }
}

void z8() {
    const int n = 10;
    int i, j, a[n], index, max = -500;
    cout << "Начальный массив" << endl;
    for (i = 0; i < n; i++) {
        a[i] = rand() % 1000 - 500;
        cout << i << " " << a[i] << endl;
    }
    for (i = 0; i < (n - 1); i++) {
        for (j = 0; j < 10 - i; j++) {
            if (a[j] > max) {
                max = a[j];
                index = j;
            }
        }
        a[index] = a[9 - i];
        a[9 - i] = max;
        max = -500;
    }
    cout << "Сортированный массив" << endl;
    for (i = 0; i < n; i++) {
        cout << i << " " << a[i] << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "RU");
    cout << "Канкошев Малик\n";
    int n=1;
    while (n != 0) {
        cout << "Введите номер задания ";
        cin >> n;
        switch (n) {
            case 1:
                z1();
                break;
            case 2:
                z2();
                break;
            case 3:
                z3();
                break;
            case 4:
                z4();
                break;
            case 5:
                z5();
                break;
            case 6:
                z6();
                break;
            case 7:
                z7();
                break;
            case 8:
                z8();
                break;
        }
            
    }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
