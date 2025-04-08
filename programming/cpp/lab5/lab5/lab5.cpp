// lab5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

void z1() {
	double x, y, z;
	cout << "Задание 1\nВведите 3 числа: ";
	scanf("%lf %lf %lf", &x, &y, &z);
	if (x > y && x > z) {
		cout << "\nНаибольшее число " << x << " \nЕго номер 1";
	}
	else if (y > z) {
		cout << "\nНаибольшее число " << y << " \nЕго номер 2";
	}
	else {
		cout << "\nНаибольшее число " << z << " \nЕго номер 3";
	}
}

void z2() {
	double x, y, z;
	cout << "Задание 2\nВведите 3 числа: ";
	scanf("%lf %lf %lf", &x, &y, &z);
	if (x > y && x > z) {
		if (y > z) {
			printf("%lf %lf %lf", x, y, z);
		}
		else {
			printf("%lf %lf %lf", x, z, y);
		}
	}
	if (y > x && y > z) {
		if (x > z) {
			printf("%lf %lf %lf", y, x, z);
		}
		else {
			printf("%lf %lf %lf", y, z, x);
		}
	}
	if (z > y && z > x) {
		if (x > y) {
			printf("%lf %lf %lf", z, x, y);
		}
		else {
			printf("%lf %lf %lf", z, y, x);
		}
	}
}

void z3() {
	double a, b, c, n, n1;
	cout << "Задание 3\nВведите 3 числа: ";
	scanf("%lf %lf %lf", &a, &b, &c);
	n = a - b;
	n1 = a - c;

	if (n < n1) {
		cout << "\nБлижайшая точка B = " << b << " \nрасстояние до А = " << n;
	}
	else {
		cout << "\nБлижайшая точка C =  " << c << " \nрасстояние до А = " << n1;
	}
}

void z4() {
	cout << "Задание 4\nВведите 6 чисел: ";
	int x1, y1, x2, y2, x3, y3, x4, y4;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	if (x1 == x2)
		x4 = x3;
	else if (x1 == x3)
		x4 = x2;
	else x4 = x1;

	if (y1 == y2)
		y4 = y3;
	else if (y1 == y3)
		y4 = y2;
	else y4 = y1;

	cout << x4 << ", " << y4;
}

void z5() {
	int x;
	double y;
	cout << "Задание 5\nВведите число: ";
	scanf("%d", &x);
	if (x < 0) {
		y = -2 * 1.0 / x;
		cout << "\ny =  " << y << " \n";
	}
	else if (x >= 3 && x < 9) {
		y = x * x * x;
		cout << "\ny =  " << y << " \n";
	}
	else if (x >= 9) {
		y = -x * 1.0 / 3;
		cout << "\ny =  " << y << " \n";
	}
	else {
		y = 26.2;
		cout << "\ny =  " << y << " \n";
	}
}

void z6() {
	int x;
	cout << "Задание 6\nВведите число: ";
	scanf("%d", &x);
	if (x % 100 == 0 && x % 400 != 0) {
		cout << "\nГод " << x << " - невисокосный";
	}
	else if (x % 4 == 0) {
		cout << "\nГод " << x << " - високосный";
	}
	else {
		cout << "\nГод " << x << " - невисокосный";
	}
}

void z7()
{
	cout << "Задание 7" << endl;

	int inputValue;
	string daysName[] = { "Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота", "Воскресенье" };
	cout << "Введите день недели - число в диапазоне от 1 до 7: ";
	cin >> inputValue;

	if (inputValue < 1 || inputValue > 7) {
		cout << "Ошибка ввода\n";
	}
	else {
		cout << "Этот день - " << daysName[inputValue - 1] << endl;
	}
}

void z8()
{
	cout << "Задание 8" << endl;

	string direct;
	int com1;
	int com2;
	int sum;

	string corners[] = { "север", "запад", "юг", "восток" };
	cout << "Ввести направление и две команды поворота: ";
	cin >> direct;
	cin >> com1;
	cin >> com2;
	sum = abs(com1 + com2);


	if (direct == "север") {
		sum += 0;
	}
	if (direct == "запад") {
		sum += 1;
	}
	if (direct == "юг") {
		sum += 2;
	}
	if (direct == "восток") {
		sum += 3;
	}
	sum >= 4 ? sum -= 4 : true;

	cout << "Итоговое направление: " << corners[sum] << endl;
}

void z9()
{
	cout << "задание 9" << endl;

	int day;
	int month;

	cout << "Введите дату: \n";
	cout << "День: ";
	cin >> day;
	cout << "Месяц: ";
	cin >> month;


	if (month == 1) {
		if (day >= 20) {
			cout << "Водолей\n";
		}
		else {
			cout << "Козерог\n";
		}
	}
	if (month == 2) {
		if (day >= 19) {
			cout << "Рыбы\n";
		}
		else {
			cout << "Водолей\n";
		}
	}
	if (month == 3) {
		if (day >= 21) {
			cout << "Овен\n";
		}
		else {
			cout << "Рыбы\n";
		}
	}
	if (month == 4) {
		if (day >= 19) {
			cout << "Телец\n";
		}
		else {
			cout << "Овен\n";
		}
	}
	if (month == 5) {
		if (day >= 21) {
			cout << "Близнецы\n";
		}
		else {
			cout << "Телец\n";
		}
	}
	if (month == 6) {
		if (day >= 22) {
			cout << "Рак\n";
		}
		else {
			cout << "Близнецы\n";
		}
	}
	if (month == 7) {
		if (day >= 23) {
			cout << "Лев\n";
		}
		else {
			cout << "Рак\n";
		}
	}
	if (month == 8) {
		if (day >= 23) {
			cout << "Дева\n";
		}
		else {
			cout << "Лев\n";
		}
	}
	if (month == 9) {
		if (day >= 23) {
			cout << "Весы\n";
		}
		else {
			cout << "Дева\n";
		}
	}
	if (month == 10) {
		if (day >= 23) {
			cout << "Скорпион\n";
		}
		else {
			cout << "Весы\n";
		}
	}
	if (month == 11) {
		if (day >= 23) {
			cout << "Стрелец\n";
		}
		else {
			cout << "Скорпион\n";
		}
	}
	if (month == 12) {
		if (day >= 22) {
			cout << "Козерог\n";
		}
		else {
			cout << "Стрелец\n";
		}
	}

}

int main() {
	setlocale(LC_ALL, "RUS");
	bool num = true;
	while (num == 1) {
		cout << "\nВведите номер задания: ";

		int number;
		cin >> number;

		switch (number) {
		case 0:
			return 0;
			break;
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
