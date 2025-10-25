#include <iostream>
#include <Windows.h>
#include <string>

class Triangle {
private:
   double sideA, sideB, sideC;

   // Вспомогательная функция для проверки валидности сторон
   bool isValidTriangle(double a, double b, double c) const {
      return (a > 0 && b > 0 && c > 0) &&
         (a + b > c) &&
         (a + c > b) &&
         (b + c > a);
   }

public:
   // Конструктор по умолчанию
   Triangle() : sideA(1.0), sideB(1.0), sideC(1.0) {}

   // Конструктор с параметрами
   Triangle(double a, double b, double c) {
      setSides(a, b, c);
   }

   // Сеттеры для сторон с проверкой
   void setSideA(double a) {
      if (!isValidTriangle(a, sideB, sideC)) {
         throw std::invalid_argument("Недопустимая длина стороны A: " + std::to_string(a));
      }
      sideA = a;
   }

   void setSideB(double b) {
      if (!isValidTriangle(sideA, b, sideC)) {
         throw std::invalid_argument("Недопустимая длина стороны B: " + std::to_string(b));
      }
      sideB = b;
   }

   void setSideC(double c) {
      if (!isValidTriangle(sideA, sideB, c)) {
         throw std::invalid_argument("Недопустимая длина стороны C: " + std::to_string(c));
      }
      sideC = c;
   }

   // Установка всех сторон одновременно
   void setSides(double a, double b, double c) {
      if (!isValidTriangle(a, b, c)) {
         throw std::invalid_argument(
            "Недопустимые длины сторон: " +
            std::to_string(a) + ", " +
            std::to_string(b) + ", " +
            std::to_string(c) +
            " - нарушено неравенство треугольника"
         );
      }
      sideA = a;
      sideB = b;
      sideC = c;
   }

   // Геттеры
   double getSideA() const { return sideA; }
   double getSideB() const { return sideB; }
   double getSideC() const { return sideC; }

   // Функция для вычисления площади по формуле Герона
   double calculateArea() const {
      double p = (sideA + sideB + sideC) / 2.0; // полупериметр
      return std::sqrt(p * (p - sideA) * (p - sideB) * (p - sideC));
   }

   // Вывод информации о треугольнике
   void printInfo() const {
      std::cout << "Треугольник со сторонами: "
         << sideA << ", " << sideB << ", " << sideC
         << "\nПлощадь: " << calculateArea() << std::endl;
   }
};

// Демонстрация работы класса
int ControlTask1() 
{
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   try {
      std::cout << "=== Демонстрация работы класса Triangle ===\n" << std::endl;

      // Создание валидного треугольника
      std::cout << "1. Создание валидного треугольника (3, 4, 5):" << std::endl;
      Triangle t1(3, 4, 5);
      t1.printInfo();
      std::cout << std::endl;

      // Попытка создания невалидного треугольника
      std::cout << "2. Попытка создания невалидного треугольника (1, 2, 5):" << std::endl;
      try {
         Triangle t2(1, 2, 5);
      }
      catch (const std::exception& e) {
         std::cout << "Ошибка: " << e.what() << std::endl;
      }
      std::cout << std::endl;

      // Изменение сторон с проверкой
      std::cout << "3. Изменение сторон существующего треугольника:" << std::endl;
      Triangle t3(5, 5, 5); // равносторонний треугольник
      t3.printInfo();

      std::cout << "\nПопытка изменить сторону A на недопустимое значение (20):" << std::endl;
      try {
         t3.setSideA(20);
      }
      catch (const std::exception& e) {
         std::cout << "Ошибка: " << e.what() << std::endl;
      }

      std::cout << "\nУспешное изменение сторон (6, 6, 6):" << std::endl;
      t3.setSides(6, 6, 6);
      t3.printInfo();
      std::cout << std::endl;

      // Тест с нулевой стороной
      std::cout << "4. Попытка создания треугольника с нулевой стороной:" << std::endl;
      try {
         Triangle t4(0, 4, 5);
      }
      catch (const std::exception& e) {
         std::cout << "Ошибка: " << e.what() << std::endl;
      }
      std::cout << std::endl;

      // Тест с отрицательной стороной
      std::cout << "5. Попытка создания треугольника с отрицательной стороной:" << std::endl;
      try {
         Triangle t5(3, -4, 5);
      }
      catch (const std::exception& e) {
         std::cout << "Ошибка: " << e.what() << std::endl;
      }

   }
   catch (const std::exception& e) {
      std::cerr << "Непредвиденная ошибка: " << e.what() << std::endl;
      return 1;
   }

   return 0;
}