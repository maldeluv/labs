#include <iostream>
using namespace std;

template<typename T>
class Array {
protected:
    T* arr;
    int size;

public:
    Array(int size) : size(size) {
        arr = new T[size];
        for (int i = 0; i < size; ++i)
            arr[i] = T();
    }
    Array() {
        arr = new T[0];
    }
    void in(T a, T b) {
        for (int i = 0; i < size; ++i)
            arr[i] = a * i / b;
    }

    void Input() {
        for (int i = 0; i < size; ++i) {
            cout << "Введите элемент [" << i << "]: ";
            cin >> arr[i];
        }
    }

    void out(){
        for (int i = 0; i < size; ++i)
            cout << arr[i] << " ";
        cout << endl;
    }

    T& operator[](int index) {
        return arr[index];
    }

};

template<typename T>
class NewArray : public Array<T> {
public:
    int size = 0;
    NewArray(int size) : Array<T>(size) {}
    NewArray() :Array<T>() {}
    NewArray<T> operator+(NewArray<T>& other){
        NewArray<T> result(this->size);
        for (int i = 0; i < this->size; ++i)
            result[i] = this->arr[i] + other[i];
        return result;
    }

    friend NewArray<T> operator-(NewArray<T>& a, NewArray<T>& b) {
        NewArray<T> result(a.size);
        for (int i = 0; i < a.size; ++i)
            result[i] = a[i] - b[i];
        return result;
    }
};
int main() {
    setlocale(LC_ALL, "RU");
    int choice;
    do {
        cout << "\nМеню\n";
        cout << "1. Заполнение через формулу(Массив double)\n";
        cout << "2. Ручной ввод(Массив int)\n";
        cout << "0. Выход\n";
        cout << "Выбор: ";
        cin >> choice;

        if (choice == 1) {
            int size = 10;
            double a1, b1, a2, b2;
            cout << "Введите a и b для первого массива: ";
            cin >> a1 >> b1;
            cout << "Введите a и b для второго массива: ";
            cin >> a2 >> b2;

            NewArray<double> arr1(size), arr2(size);
            arr1.in(a1, b1);
            arr2.in(a2, b2);

            NewArray<double> sum = arr1 + arr2;
            cout << "Массив 1: "; 
            arr1.out();
            cout << "Массив 2: "; 
            arr2.out();
            cout << "Сумма:    "; 
            sum.out();
        }
        else if (choice == 2) {
            int size;
            cout << "Введите размер массивов: ";
            cin >> size;

            NewArray<int> arr1(size), arr2(size);
            cout << "Введите элементы для первого массива:\n";
            arr1.Input();
            cout << "Введите элементы для второго массива:\n";
            arr2.Input();

            NewArray<int> diff = arr1 - arr2;
            cout << "Разность массивов:\n";
            diff.out();
        }

    } while (choice != 0);

    return 0;
}
