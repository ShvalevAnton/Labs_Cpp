#include <iostream>
#include <Windows.h>
#include <fstream>
using namespace std;

int ControlTask2()
{
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   const int N = 10;
   int a[N] = { 1, 25, 6, 32, 43, 5, 96, 23, 4, 55 };
   int min = 0; // для записи минимального значения
   int buf = 0; // для обмена значениями

   // Открываем файл для записи
   ofstream file("array.txt");
   if (!file.is_open()) {
      cerr << "Ошибка: не удалось открыть файл для записи." << endl;
      return 1;
   }

   // Записываем исходный массив
   file << "Исходный массив:" << endl;
   for (int i = 0; i < N; i++) {
      file << a[i] << ' ';
   }
   file << endl;

   // Сортировка массива (алгоритм сортировки выбором)
   for (int i = 0; i < N; i++)
   {
      min = i; // номер текущей ячейки, как ячейки с минимальным значением
      // в цикле найдем реальный номер ячейки с минимальным значением
      for (int j = i + 1; j < N; j++)
         min = (a[j] < a[min]) ? j : min;
      // перестановка этого элемента, поменяв его местами с текущим
      if (i != min)
      {
         buf = a[i];
         a[i] = a[min];
         a[min] = buf;
      }
   }

   // Записываем отсортированный массив
   file << "Отсортированный массив:" << endl;
   for (int i = 0; i < N; i++) {
      file << a[i] << ' ';
   }
   file << endl;

   file.close();

   // Вывод на экран для проверки
   cout << "Массивы записаны в файл array.txt" << endl;
   for (int i : a)
      cout << i << '\t';


   return 0;
}