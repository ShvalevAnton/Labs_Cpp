#include "Exercises.h"
#include <iostream>
#include <cmath>
#include <iomanip>
#include <Windows.h>

int TriangleArea() {

   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   double perimeter;

   // Ввод периметра от пользователя
   std::cout << "Введите периметр равностороннего треугольника: ";
   std::cin >> perimeter;

   // Вычисление длины стороны (все стороны равны в равностороннем треугольнике)
   double side = perimeter / 3.0;

   // Полупериметр
   double p = perimeter / 2.0;

   // Формула Герона: S = sqrt(p * (p - a) * (p - b) * (p - c))
   // Так как a = b = c = side, то:
   double area = std::sqrt(p * (p - side) * (p - side) * (p - side));

   // Вывод таблицы
   std::cout << std::fixed << std::setprecision(2);
   std::cout << "Сторона   Площадь" << std::endl;
   std::cout << side << "      " << area << std::endl;

   return 0;
}