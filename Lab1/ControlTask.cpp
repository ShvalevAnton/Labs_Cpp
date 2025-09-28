#include "Exercises.h"

#include <iostream>
#include <cmath>
#include <iomanip>
#include <Windows.h>

int ControlTask() {

   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   const int N = 5; // пятиугольник
   double x[N], y[N];

   std::cout << "Введите координаты вершин выпуклого пятиугольника (в порядке обхода):\n";
   for (int i = 0; i < N; ++i) {
      std::cout << "Вершина " << (i + 1) << " (x y): ";
      std::cin >> x[i] >> y[i];
   }

   // Применяем формулу Гаусса
   double sum = 0.0;
   for (int i = 0; i < N; ++i) {
      int next = (i + 1) % N; // следующая вершина (последняя соединяется с первой)
      sum += x[i] * y[next] - x[next] * y[i];
   }

   double area = std::abs(sum) / 2.0;

   // Вывод с двумя знаками после запятой
   std::cout << std::fixed << std::setprecision(2);
   std::cout << "Площадь пятиугольника: " << area << std::endl;

   return 0;
}