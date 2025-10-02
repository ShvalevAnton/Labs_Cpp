#include <iostream>
#include <Windows.h>
#include <cmath>
#include <iomanip>
using namespace std;

long double firBinSearch(double a, int n)
{
   double L = 0;
   double R = a;
   while (R - L > 1e-10)
   {
      double M = (L + R) / 2;
      if (pow(M, n) < a)
      {
         L = M;
      }
      else
      {
         R = M;
      }
   }
   return R;
}

int Exercise4()
{
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   double a;
   int n;

   // Ввод исходных данных
   cout << "Введите число a: ";
   cin >> a;
   cout << "Введите степень корня n: ";
   cin >> n;

   // Проверка корректности входных данных
   if (a < 0 && n % 2 == 0) {
      cout << "Ошибка: нельзя извлечь корень четной степени из отрицательного числа" << endl;
      return 1;
   }

   if (n <= 0) {
      cout << "Ошибка: степень корня должна быть положительным числом" << endl;
      return 1;
   }

   // Вызов функции бинарного поиска
   long double result = firBinSearch(abs(a), n);

   // Учет знака для отрицательных чисел с нечетной степенью
   if (a < 0) {
      result = -result;
   }

   // Вывод результата с точностью не менее 6 знаков после запятой
   cout << fixed << setprecision(10);
   cout << "Корень степени " << n << " из " << a << " = " << result << endl;

   return 0;
}