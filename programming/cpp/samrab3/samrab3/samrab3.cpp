#include <iostream>
using namespace std;

void z1(int a, int b,double &sa,double &sg) {
    
    sa = (a + b) / 2.0;
    sg = sqrt(a * b * 1.0);
}

void z2(double *a, double N) {
    for (int i = 0; i <= N; i++) {
        if (i % 2 == 0) {
            a[i] = 2 * i / 3.0;
        }
        else {
            a[i] = -2 * i / 3.0;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "RUS");
    cout << "Канкошев Малик\n";
    int a, b;
    double sa, sg;
    cout << "Введите два числа ";
    cin >> a >> b;
    z1(a, b,sa,sg);
    cout << "Среднее арифметическое равно " << sa << " среднее геометрическое равно " << sg << endl;

    double N;
    cout << "Введите целое число N ";
    cin >> N;
    double a[N];
    cout << "Массив" << endl;
    z2(a, N);
    for (int i = 0; i <= N; i++) {
        cout << i << " " << a[i] << endl;
    }
}
