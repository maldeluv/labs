// 12lab.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <math.h>

using namespace std;

void z1() {
    const int n = 10;
    int a[n][n], b[n], i, j;
    cout << "Начальный массив " << endl;
    for (i = 0; i < n; i++) {
        cout << i;
        for (j = 0; j < n; j++) {
            a[i][j] = rand() % 100 - 50;
            cout << " " << a[i][j];
        }
        cout << endl;
    }
    cout << "Массив сумм" << endl;
    for (i = 0; i < n; i++) {
        b[i] = 0;
        for (j = 0; j < n; j++) {
            b[i] += a[i][j];
        }
        cout << b[i]<<" ";
    }
}

void z2() {
    const int n = 10;
    int a[n][n], b[n], i, j;
    cout << "Начальный массив " << endl;
    for (i = 0; i < n; i++) {
        cout << i;
        for (j = 0; j < n; j++) {
            a[i][j] = rand() % 100 - 50;
            cout << " " << a[i][j];
        }
        cout << endl;
    }
    cout << "Массив произведений" << endl;
    for (j  = 0; j < n; j++) {
        b[j] = 1;
        for (i = 0; i < n; i++) {
            b[j] *= a[i][j];
        }
        cout << b[j] << " ";
    }
}

void z3() {
    const int n = 10;
    int a[n][n], i, j, s = 0;
    cout << "Начальный массив " << endl;
    for (i = 0; i < n; i++) {
        cout << i;
        for (j = 0; j < n; j++) {
            a[i][j] = rand() % 100 - 50;
            cout << " " << a[i][j];
        }
        cout << endl;
    }
    for (i = 0; i < n; i++) {
        if (a[i][i] > 0) {
            s += a[i][i];
        }
    }
    cout << "Сумма положительных элементов главной диагонали равна " << s;
}

void z4() {
    const int n = 10;
    int a[n][n], i, j, s = 0;
    cout << "Начальный массив " << endl;
    for (i = 0; i < n; i++) {
        cout << i;
        for (j = 0; j < n; j++) {
            a[i][j] = rand() % 100 - 50;
            cout << " " << a[i][j];
        }
        cout << endl;
    }

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            s += a[i][j];
        }
    }
    cout << "Сумма элементов расположенных выше главной диагонали " << s;
}

void z5() {
    const int n = 10;
    double s = 0, sr = 0;
    int a[n][n], i, j, k = 0, l = 0, count = 0;
    cout << "Начальный массив " << endl;
    for (i = 0; i < n; i++) {
        cout << i;
        for (j = 0; j < n; j++) {
            a[i][j] = rand() % 100 - 50;
            cout << " " << a[i][j];
            s += a[i][j];
            count++;
        }
        cout << endl;
    }
    sr = s / count;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (abs(sr-a[i][j]) < abs(sr-a[k][l])) {
                sr =sr - a[i][j];
                k = i;
                l = j;
            }
        }
    }
    cout << "Среднее значение " << s / count << endl;
    cout << "Наиболее близок к среднему значению элемент a[" << k+1 << "][" << l+1 << "] = " << a[k][l];
}

void z6() {
    const int n = 10;
    int a[n][n], i, j, k1, k2, b;
    cout << "Начальный массив " << endl;
    for (i = 0; i < n; i++) {
        cout << i;
        for (j = 0; j < n; j++) {
            a[i][j] = rand() % 100 - 50;
            cout << " " << a[i][j];
        }
        cout << endl;
    }
    cout << "Введите числа к1 и к2 ";
    cin >> k1 >> k2;
    for (j = 0; j < n; j++) {
        b = a[k1][j];
        a[k1][j] = a[k2][j];
        a[k2][j] = b;
    }
    cout << "\nНовый массив " << endl;
    for (i = 0; i < n; i++) {
        cout << i;
        for (j = 0; j < n; j++) {
            cout << " " << a[i][j];
        }
        cout << endl;
    }
}

void z7() {
    const int n = 10;
    int a[n][n], i, j, k1, k2, b;
    cout << "Начальный массив " << endl;
    for (i = 0; i < n; i++) {
        cout << i;
        for (j = 0; j < n; j++) {
            a[i][j] = rand() % 100 - 50;
            cout << " " << a[i][j];
        }
        cout << endl;
    }
    cout << "Введите числа к1 и к2 ";
    cin >> k1 >> k2;
    for (i = 0; i < n; i++) {
        b = a[i][k1];
        a[i][k1] = a[i][k2];
        a[i][k2] = b;
    }
    cout << "\nНовый массив " << endl;
    for (i = 0; i < n; i++) {
        cout << i;
        for (j = 0; j < n; j++) {
            cout << " " << a[i][j];
        }
        cout << endl;
    }
}

void z8() {
    const int n = 10;
    int a[n][n], i, j, b=0;
    cout << "Начальный массив " << endl;
    for (i = 0; i < n; i++) {
        cout << i;
        for (j = 0; j < n; j++) {
            a[i][j] = rand() % 100 - 50;
            cout << " " << a[i][j];
        }
        cout << endl;
    }
    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            b = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = b;
        }
    }
    cout << "\nНовый массив " << endl;
    for (i = 0; i < n; i++) {
        cout << i;
        for (j = 0; j < n; j++) {
            cout << " " << a[i][j];
        }
        cout << endl;
    }

}

void z9() {
    const int n = 10;
    int a[n][n], i, j;
    cout << "Начальный массив " << endl;
    for (i = 0; i < n; i++) {
        cout << i;
        for (j = 0; j < n; j++) {
            a[i][j] = rand() % 100 - 50;
            cout << " " << a[i][j];
        }
        cout << endl;
    }
    for (i = n - 1; i > 0; i--) {
        for (j = i - 1; j >= 0; j--) {
            a[i][j] = 0;
        }
    }
    cout << "\nНовый массив " << endl;
    for (i = 0; i < n; i++) {
        cout << i;
        for (j = 0; j < n; j++) {
            cout << " " << a[i][j];
        }
        cout << endl;
    }
}

void z10()
{
    const int N = 10;
    int i, j, a[N][N], b[N][N], c[N][N];
    cout << "Массив В" << endl;
    for (i = 0; i < N; i++) {
        cout << i << " ";
        for (j = 0; j < N; j++) {
            b[i][j] = rand() % 100 - 50;
            cout << " " << b[i][j];
        }
        cout << endl;
    }
    cout << "Массив C" << endl;
    for (i = 0; i < N; i++) {
        cout << i << " ";
        for (j = 0; j < N; j++) {
            c[i][j] = rand() % 100 - 50;
            cout << " " << c[i][j];
        }
        cout << endl;
    }
    cout << "Массив A" << endl;
    for (i = 0; i < N; i++) {
        cout << i << " ";
        for (j = 0; j < N; j++) {
            a[i][j] = b[i][j] + c[i][j];
            cout << " " << a[i][j];
        }
        cout << endl;
    }
}

void z11()
{
    const int N = 10;
    int b[N], i, j;
    double a[N][N];
    cout << "Изначальный массив" << endl;
    for (i = 0; i < N; i++) {
        cout << i << " ";
        for (j = 0; j < N; j++) {
            a[i][j] = rand() % 100 - 50;
            cout << " " << a[i][j];
        }
        cout << endl;
    }
    cout << "Новый массив" << endl;
    for (i = 0; i < N; i++) {
        b[i] = a[i][i];
        cout << i << " ";
        for (j = 0; j < N; j++) {
            a[i][j] /= b[i];
            cout << " " << a[i][j];
        }
        cout << endl;
    }
}

void z12()
{
    const int N = 10;
    int i, j;
    double a[N][N]; 
    for (i = 0; i < N; i++) {
        for (j = i; j < N; j++) {
            a[i][j] = a[j][i] = (double)(i + j) / (double)(2 * (i + j + 1));
        }
    }
    cout << "Матрица " << endl;
    for (i = 0; i < N; i++) {
        cout << i << " ";
        for (j = 0; j < N; j++) {
            cout << " " << a[i][j];
        }
        cout << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "RUS");
    int n = 1;
    cout << "Канкошев Малик" << endl;
    while (n != 0) {
        cout << "\nВведите номер задания ";
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
        case 9:
            z9();
            break;
        case 10:
            z10();
            break;
        case 11:
            z11();
            break;
        case 12:
            z12();
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
