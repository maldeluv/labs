
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

void z_1()
{
	cout << "а)" << endl;
	int i = 1, j = 2, k = 3;
	cout << "i < j = " << (i < j) << "\n(i + j) >= k = " << ((i + j) >= k)
		<< "\n(j + k) > (i + 5) = " << ((j + k) > (i + 5)) << "\nk != 3 = " << (k != 3)
		<< "\nj==2 = " << (j == 2) << endl;
	cout << "б)" << endl;
	i = 7;
	double f = 5.5, c = 100;
	cout << "f > 5 = " << (f > 5) << "\n(i + f) <= 10 = " << ((i + f) <= 10)
		<< "\nс >= 10 * (i + f) = " << (c >= 10 * (i + f)) << endl;
}

void z_2()
{
	double i = 7, f = 5.5, c = 100;
	cout << "i + f <= 10 = " << (i + f <= 10) << "\ni >= 6 && с == 120 = "
		<< (i >= 6 && c == 120) << "\nс != 94 || i + f <= 10 = "
		<< (c != 94 || i + f <= 10) << endl;
}

void z_3()
{
	int  х = 2, у = 1, z = 0;
	int x = х && у || z;
	cout << "х = х && у || z = " << x << endl;
	x = 2;
	int w = x || !у && z;
	cout << "w = x || !y && z = " << w << endl;
}

void z_4()
{
	int х = 1, у = 1, z = 1, w;
	w = ++х || ++у || ++z;
	cout << "а)" << endl;
	cout << w << endl;
	cout << х << у << z << endl;
	х = 1; у = 1; z = 1;
	w = ++х && ++у || ++z;
	cout << "б)" << endl;
	cout << w << endl;
	cout << х << у << z << endl;
	х = 1; у = 1; z = 1;
	w = ++х && ++у && ++z;
	cout << "в)" << endl;
	cout << w << endl;
	cout << х << у << z << endl;
}

void z_5()
{
	int x = 1, y = 2, z = 3;
	int a, b, c;
	x = y == z;
	cout << x << endl;
	a = x == (y = z);
	cout << a << endl;
	b = x == y < z;
	cout << b << endl;
	c = x && !y <= z;
	cout << c << endl;
}

void z_6()
{
	{
		cout << "\t6.1\n";
		int x;
		printf("Введите X: ");
		scanf("%d", &x);
		printf("X = %d\n", x);
	}
	{
		cout << "\t6.2\n";
		int x;
		float y;
		double z;
		printf("Введите x: ");
		scanf("%d", &x);
		printf("Введите y: ");
		scanf("%f", &y);
		printf("Введите z: ");
		scanf("%lf", &z);
		printf("x = %d; y = %f; z = %f\n", x, y, z);
	}
	{
		cout << "\t6.3\n";
		int x;
		float y;
		double z;
		printf("Введите x, y и z через пробелы: ");
		scanf("%d%f%lf", &x, &y, &z);
		printf("x = %d; y = %f; z = %f\n", x, y, z);
	}
	{
		cout << "\t6.4\n";
		char s1[20], s2[20], s3[20];
		int i;
		printf("Введите 3 строки через пробел: ");
		i = scanf("%s%s%s", &s1, &s2, &s3);
		i = printf("%s%s%s\n", &s1, &s2, &s3);
		i = printf("%d\n", i);
		printf("%d\n", i);
		// scanf() возвращает число, равное колличеству присвоеных переменных
		// printf() возвращает число, равное колличеству символов,
		// выведенных на консоль, включая escape-последовательности
	}
	{
		cout << "\t6.5\n";
		int m = 0;
		float x = 0;
		printf("а) Введите (987,654): ");
		scanf("%6f%d", &x, &m);
		printf("x = %f, m = %d\n", x, m);
		m = x = 0;
		printf("б) Введите (-987,654): ");
		scanf("%6f%d", &x, &m);
		printf("x = %f, m = %d\n", x, m);
		printf("в) Введите (987,6 54): ");
		scanf("%6f%d", &x, &m);
		printf("x = %f, m = %d\n", x, m);
		printf("г) Введите (-987,65A4): ");
		scanf("%6f%d", &x, &m);
		printf("x = %f, m = %d\n", x, m);
	}
}

int main()
{
	setlocale(LC_ALL, "RUS");

	int number = 1;

	while (number != 0) // Завершение работы оператора switch при 0
	{
		cout << "Введите номер задания: ";
		cin >> number;

		switch (number)
		{
		case 1:
			z_1();
			break;
		case 2:
			z_2();
			break;
		case 3:
			z_3();
			break;
		case 4:
			z_4();
			break;
		case 5:
			z_5();
			break;
		case 6:
			z_6();
			break;
		default: cout << "Нет такого задания\n";
		}
	}
	return 0;
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
