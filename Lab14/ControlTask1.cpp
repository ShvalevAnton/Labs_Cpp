#include <iostream>
#include <Windows.h>
using namespace std;

// Шаблонная функция для вычисления среднего арифметического
template <typename T>
double average(T arr[], int size) {
   if (size <= 0) {
      return 0.0; // Защита от нулевого или отрицательного размера
   }

   T sum = T(); // Инициализация нулем для типа T
   for (int i = 0; i < size; i++) {
      sum += arr[i];
   }

   return static_cast<double>(sum) / size;
}

int ControlTask1() 
{
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   // Тестирование с массивом int
   int intArr[] = { 1, 2, 3, 4, 5 };
   int intSize = sizeof(intArr) / sizeof(intArr[0]);
   cout << "Массив int: ";
   for (int i = 0; i < intSize; i++) {
      cout << intArr[i] << " ";
   }
   cout << "\nСреднее арифметическое: " << average(intArr, intSize) << endl;

   // Тестирование с массивом long
   long longArr[] = { 10L, 20L, 30L, 40L, 50L };
   int longSize = sizeof(longArr) / sizeof(longArr[0]);
   cout << "\nМассив long: ";
   for (int i = 0; i < longSize; i++) {
      cout << longArr[i] << " ";
   }
   cout << "\nСреднее арифметическое: " << average(longArr, longSize) << endl;

   // Тестирование с массивом double
   double doubleArr[] = { 1.5, 2.5, 3.5, 4.5, 5.5 };
   int doubleSize = sizeof(doubleArr) / sizeof(doubleArr[0]);
   cout << "\nМассив double: ";
   for (int i = 0; i < doubleSize; i++) {
      cout << doubleArr[i] << " ";
   }
   cout << "\nСреднее арифметическое: " << average(doubleArr, doubleSize) << endl;

   // Тестирование с массивом char
   char charArr[] = { 10, 20, 30, 40, 50 }; // ASCII значения
   int charSize = sizeof(charArr) / sizeof(charArr[0]);
   cout << "\nМассив char (значения ASCII): ";
   for (int i = 0; i < charSize; i++) {
      cout << static_cast<int>(charArr[i]) << " ";
   }
   cout << "\nСреднее арифметическое: " << average(charArr, charSize) << endl;

   return 0;
}