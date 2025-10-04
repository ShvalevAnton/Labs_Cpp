#include <iostream>
#include <Windows.h>
#include <cmath>
#include <iomanip>
using namespace std;

// Вариант 1: через pow
double cubeRootPow(double a) {
   if (a < 0) {
      return -pow(-a, 1.0 / 3.0);
   }
   return pow(a, 1.0 / 3.0);
}

// Вариант 2: итерационный метод (Ньютона)
double cubeRootIterative(double a, double epsilon = 1e-10, int maxIter = 100) {
   if (a == 0.0) return 0.0;

   // Обработка знака
   bool negative = (a < 0);
   double abs_a = abs(a);

   // Начальное приближение
   double x = abs_a > 1.0 ? abs_a : 1.0; // если |a| > 1, начинаем с a, иначе с 1

   for (int i = 0; i < maxIter; ++i) {
      double next_x = (1.0 / 3.0) * (abs_a / (x * x) + 2 * x);
      if (abs(next_x - x) < epsilon) {
         x = next_x;
         break;
      }
      x = next_x;
   }

   return negative ? -x : x;
}

int ControlTask2()
{
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);
     
   double test_values;
   cout << "Введите число для вычисления кубического корня: ";
   cin >> test_values;

   cout << fixed << setprecision(10);
   cout << "Число\t\tКубический корень (pow)\tКубический корень (итер.)\n";
   cout << "--------------------------------------------------------------\n";
     
   double root_pow = cubeRootPow(test_values);
   //double root_pow = pow(test_values, 1.0 / 3.0);
   double root_iter = cubeRootIterative(test_values);
   cout << test_values << "\t" << root_pow << "\t" << root_iter << "\n";   

   return 0;
}