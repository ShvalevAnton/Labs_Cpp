#include <iostream>
#include <Windows.h>
using namespace std;

int* max_vect(int kc, const int* a, const int* b) {
   int* result = new int[kc]; // Выделяем память под результирующий массив
   for (int i = 0; i < kc; ++i) {
      result[i] = (a[i] > b[i]) ? a[i] : b[i]; // Выбираем максимум
   }
   return result; // Возвращаем указатель на созданный массив
}

int ControlTask2()
{
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   int a[] = { 1, 2, 3, 4, 5, 6, 7, 2 };
   int b[] = { 7, 6, 5, 4, 3, 2, 1, 3 };

   int kc = sizeof(a) / sizeof(a[0]); // Количество элементов массива
   int* c; // Указатель на результирующий массив
   c = max_vect(kc, a, b); // Вызов функции для создания массива
   for (int i = 0; i < kc; i++) // Вывод результата
      cout << c[i] << " ";
   cout << endl;
   delete[] c; // Возврат памяти
   return 0;
}

