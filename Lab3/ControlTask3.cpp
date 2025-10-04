#include <iostream>
#include <Windows.h>
#include <cmath>
#include <iomanip>
using namespace std;

// Функция для вычисления площади равностороннего треугольника
double calculateArea(double side) {
   // Формула: S = (sqrt(3) / 4) * a^2
   return (sqrt(3) / 4.0) * side * side;
}

// Функция для вычисления площади разностороннего треугольника по трём сторонам
double calculateArea(double a, double b, double c) {
   // Проверка существования треугольника
   if (a + b <= c || a + c <= b || b + c <= a) {
      throw invalid_argument("Треугольник с такими сторонами не существует!");
   }

   // Формула Герона
   double p = (a + b + c) / 2.0; // полупериметр
   return sqrt(p * (p - a) * (p - b) * (p - c));
}


int ControlTask3() {
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);
   setlocale(LC_ALL, "Russian"); // Для корректного отображения русского языка в консоли (опционально)

   cout << "Выберите тип треугольника:\n";
   cout << "1. Равносторонний\n";
   cout << "2. Разносторонний\n";
   cout << "Ваш выбор: ";

   int choice;
   cin >> choice;

   try {
      if (choice == 1) {
         double side;
         cout << "Введите длину стороны равностороннего треугольника: ";
         cin >> side;

         if (side <= 0) {
            cout << "Ошибка: сторона должна быть положительной!\n";
            return 1;
         }

         double area = calculateArea(side);
         cout << fixed << setprecision(2);
         cout << "Площадь равностороннего треугольника: " << area << endl;

      }
      else if (choice == 2) {
         double a, b, c;
         cout << "Введите три стороны разностороннего треугольника: ";
         cin >> a >> b >> c;

         if (a <= 0 || b <= 0 || c <= 0) {
            cout << "Ошибка: все стороны должны быть положительными!\n";
            return 1;
         }

         double area = calculateArea(a, b, c);
         cout << fixed << setprecision(2);
         cout << "Площадь разностороннего треугольника: " << area << endl;
      }
      else {
         cout << "Ошибка: неверный выбор. Выберите 1 или 2.\n";
         return 1;
      }
   }
   catch (const invalid_argument& e) {
      cout << "Ошибка: " << e.what() << endl;
      return 1;
   }

   return 0;
}