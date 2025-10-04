#include <iostream>
#include <Windows.h>
using namespace std;

// Рекурсивная функция для перевода числа в двоичную систему
void decToBin(int num) {
   if (num > 1) {
      decToBin(num / 2); // Рекурсивный вызов с целой частью от деления на 2
   }
   cout << num % 2;  // Вывод остатка от деления на 2
}


int ControlTask5() {
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   int number;
   cout << "Введите целое положительное число: ";
   cin >> number;

   if (number < 0) {
     cout << "Ошибка: введите положительное число!" << endl;
      return 1;
   }

   if (number == 0) {
      cout << "0" << endl;
   }
   else {
      decToBin(number);
      cout << endl;
   }

   return 0;
}