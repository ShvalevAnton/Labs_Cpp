#include <iostream>
#include <Windows.h>
using namespace std;

void show_array1(const int Arr[], const int N)
{
   for (int i = 0; i < N; i++)
      cout << Arr[i] << " ";
   cout << "\n";
}

bool from_min1(const int a, const int b)
{
   return a > b;
}
bool from_max1(const int a, const int b)
{
   return a < b;
}

void bubble_sort1(int Arr[], const int N, bool (*compare)(int a, int b))
{
   for (int i = 1; i < N; i++)
   {
      for (int j = 0; j < N - 1; j++)
      {
         if ((*compare)(Arr[j], Arr[j + 1])) swap(Arr[j], Arr[j + 1]);
      }
   }
}

int Exercise4()
{
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   bool (*from_f[2])(int, int) = { from_min1,from_max1 };

   int n = 0;
   cout << "Введите размер массива: ";
   cin >> n;

   // Проверка корректности размера
   if (n <= 0)
   {
      cout << "Размер массива должен быть положительным числом.\n";
      return 1;
   }

   // Выделение динамической памяти
   int* A = new int[n];

   cout << "Введите " << n << " целых чисел:\n";
   for (int i = 0; i < n; i++)
   {
      cout << "A[" << i << "] = ";
      cin >> A[i];
   }
   
   int my_choose = 0;   
   cout << "1. Сортировать по возрастанию\n";
   cout << "2. Сортировать по убыванию\n";
   cin >> my_choose;
   cout << "Исходные данные: ";
   show_array1(A, n);

   bubble_sort1(A, n, (from_f[my_choose - 1]));
   show_array1(A, n);

   // Освобождение динамической памяти
   delete[] A;
   A = nullptr;

   return 0;
}