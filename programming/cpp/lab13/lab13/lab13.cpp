// lab13.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

double z1(double x)
{
    double y = 26.2;
    if (x < 0)
        y = -2.0 / x;
    if (x >= 9)
        y = -x;
    if (x >= 3)
        y = x*x*x;
    return y;
}

double z2(int N)
{
    double s = 0;
    for (int i = 1; i <= N; i++)
    {
        s += (double)(i + 1) / (2 * i);
    }
    return s;
}

int z3(int K, int D)
{
    int a;
    a = K * 10 + D;
    return a;
}

void z4(double* x, double* y)
{
    double a;
    a = *x;
    *x = *y;
    *y = a;
}

void z5(int x, int y, double& sa, double& sg)
{
    sa = (x + y) / 2.0;
    sg = sqrt(x * y * 1.0);
}

void z6(double& A, double& B, double& C)
{
    if (A > B)
        z4(&A, &B);
    else if (B > C)
        z4(&B, &C);
    else if (B < A)
        z4(&A, &B);

}

void z7(double* a, int N)
{
    a[0] = 0.5;
    cout << a[0] << " ";
    for (int i = 1; i < N; i++) {
        a[i] = (i + 1.0) / (2.0 * i);
        cout << a[i] << " ";
    }
}

void z8(int* a, int N, int& maxi, int& mini, int& sum_i, int& i_maxi, int& i_mini)
{
    maxi = mini = a[0];
    i_maxi = i_mini = 0;
    sum_i = 0;

    for (int i = 0; i < N; i++)
    {
        if (a[i] > maxi)
        {
            maxi = a[i];
            i_maxi = i;
        }
        if (a[i] < mini)
        {
            mini = a[i];
            i_mini = i;
        }
        if (a[i] > 0)
            sum_i += a[i];
    }
}

double z9(int n)
{
    double fact = 1;
    for (int i = 2; i <= n; i++)
        fact *= i;
    return fact;
}


int main()
{
    int n = 1;
    setlocale(LC_ALL, "RUS");
    cout << "Канкошев Малик\n";
    while (n != 0) {
        cout << "Введите номер задания ";
        cin >> n;
        switch(n){
        case 1:
        {
            double x;
            cout << "\nВведите X ";
            cin >> x;
            cout << "\nY(X) = " << z1(x) << endl;
            break;
        }
        case 2:
        {
            int N;
            cout << "\nВведите число элементов ";
            cin >> N;
            cout << "\nS = " << z2(N) << endl;
            break;
        }
        case 3:
        {
            int K, D;
            cout << "\nВведите числа K и D (0 <= D <= 9) ";
            cin >> K >> D;
            cout << "\nЧисло равно " << z3(K, D) << endl;
            break;
        }
        case 4:
        {
            double x, y;
            cout << "\nВведите числа X и Y ";
            cin >> x >> y;
            z4(&x, &y);
            cout << "X = " << x << " Y = " << y << endl;
            break;
        }
        case 5:
        {
            int x, y;
            double sa, sg;
            cout << "\nВведите два числа ";
            cin >> x >> y;
            z5(x, y, sa, sg);
            cout << "\nСреднее арифметическое равно " << sa << endl;
            cout << "\nСреднее геометрическое равно " << sg << endl;
            break;
        }
        case 6:
        {
            double A, B, C;
            cout << "\nВведите числа A,B и C: ";
            cin >> A >> B >> C;
            z6(A, B, C);
            cout << "\nA = " << A << "; B = " << B << "; C = " << C << endl;
            break;
        }
        case 7:
        {
            int n;
            cout << "\nВведите число элементов ";
            cin >> n;
            double a[100];
            cout << "\nЗаполненый массив"<<endl;
            z7(a, n);
            cout << endl;
            break;
        }
        case 8:
        {
            int N, maxi, mini, sum_i, i_maxi, i_mini;
            cout << "Введите целое число N: ";
            cin >> N;
            int a[100];
            cout << "Массив: "<<endl;
            for (int i = 0; i < N; i++) {
                a[i] = rand() % 100 - 50;
                cout << i << " " << a[i] << endl;
            }
            cout << endl;
            z8(a, N, maxi, mini, sum_i, i_maxi, i_mini);
            cout << "Максимальный элемент: " << maxi << "; его номер: " << i_maxi << endl;
            cout << "Минимальный элемент: " << mini << "; его номер: " << i_mini << endl;
            cout << "Сумма положительных элементов: " << sum_i << endl;
            break;
        }

        case 9:
        {
            int n;
            double fact;
            cout << "Введите целое число N: ";
            cin >> n;
            cout << "Факториал числа " << n << " равен " << z9(n) << endl;
            break;
        }
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
