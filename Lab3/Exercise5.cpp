#include <iostream>
#include <Windows.h>
#include <cmath>
#include <iomanip>
using namespace std;

int addNumders(int n)
{
   if (n == 1) return 1; // выход из рекурсии
   else return (n + addNumders(n - 1));
}

int gcd(int m, int n)
{
   if (n == 0) return m;
   return gcd(n, m % n);
}

int Exercise5()
{
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);
   
   int n;
   // Ввод исходных данных
   cout << "Введите число n: "; cin >> n;   
   // Вызов функции 
   int result = addNumders(n);   
   // Вывод результата
   cout << "Результат: " << n << endl;

   // Алгоритм Евклида
   cout << "Алгоритм Евклида" << endl;
   int a,b;
   // Ввод исходных данных
   cout << "Введите число a: "; cin >> a;
   cout << "Введите число b: "; cin >> b;

   // Вызов функции 
   result = gcd(a,b);
   // Вывод результата
   cout << "Результат: " << result << endl;
   return 0;
}