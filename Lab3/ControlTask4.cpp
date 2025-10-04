#include <iostream>
#include <Windows.h>
using namespace std;

// Рекурсивная функция для вычисления суммы ряда S = 5 + 10 + 15 + ... + 5*n
int sumSeries(int n) {
   if (n == 1) {
      return 5;
   }
   return 5 * n + sumSeries(n - 1);
}


int ControlTask4() {
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);
   
   int n;
   cout << "Введите положительное целое число n: ";
   cin >> n;

   if (n <= 0) {
      cout << "Ошибка: n должно быть больше 0.\n";
      return 1;
   }

   int result = sumSeries(n);
   cout << "Сумма ряда S = 5 + 10 + 15 + ... + " << 5 * n << " равна " << result << endl;

   return 0;
}