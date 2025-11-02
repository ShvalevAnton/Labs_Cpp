#include <iostream>
#include <Windows.h>
#include "functions.h"
#include <string>
#include <tuple>
#include <vector>
#include <cstdlib>
using namespace std;



// Шаблонный класс массива
template<class T, class T1> class MyArray
{
public:
   MyArray(int size);
   ~MyArray();
   T1 sum();
   T average_value();
   void show_array();
   int add_value(T);
private:
   T* data;
   int size;
   int index;
};

// Конструктор
template<class T, class T1>
MyArray<T, T1>::MyArray(int size)
{
   data = new T[size];
   if (data == nullptr)  // Лучше использовать nullptr вместо NULL в C++
   {
      cerr << "Error memory ---- exit program" << endl;
      exit(1);
   }
   this->size = size;    // Используем this-> для избежания неоднозначности
   this->index = 0;
}

// Деструктор
template<class T, class T1>
MyArray<T, T1>::~MyArray()
{
   delete[] data;  // Освобождаем память
}

// Метод для вычисления суммы
template<class T, class T1> T1 MyArray<T, T1>::sum()
{
   T1 sum = 0;
   for (int i = 0; i < index; i++) sum += data[i];
   return(sum);
}

// Метод для вычисления среднего значения
template<class T, class T1> T MyArray<T, T1>::average_value()
{
   T1 sum_val = 0;
   for (int i = 0; i < index; i++) sum_val += data[i];
   return (sum_val / index);
}

// Метод для отображения массива
template<class T, class T1> void MyArray<T, T1>::show_array()
{
   for (int i = 0; i < index; i++) cout << data[i] << ' ';
   cout << endl;
}

// Метод для добавления значения
template<class T, class T1> int MyArray<T, T1>::add_value(T value)
{
   if (index == size)
      return(-1);
   else
   {
      data[index] = value;
      index++;
      return(0);
   }
}

int Exercise4()
{
   // Создание массивов разных типов
   MyArray<int, long> numbers(100);
   MyArray<float, float> values(200);

   // Заполнение и работа с массивом целых чисел
   cout << "Array of integers:" << endl;
   int i;
   for (i = 0; i < 50; i++) numbers.add_value(i);
   numbers.show_array();
   cout << "Sum = " << numbers.sum() << endl;
   cout << "Average = " << numbers.average_value() << endl;

   cout << endl;

   // Заполнение и работа с массивом вещественных чисел
   cout << "Array of floats:" << endl;
   for (i = 0; i < 100; i++) values.add_value(i * 100);
   values.show_array();
   cout << "Sum = " << values.sum() << endl;
   cout << "Average = " << values.average_value() << endl;

   return 0;
}