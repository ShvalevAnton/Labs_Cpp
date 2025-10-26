#include <iostream>
#include <Windows.h>
#include "dot.h"
#include "triangle_composition.h"
#include "triangle_aggregation.h"

int ControlTask1()
{
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   std::cout << "=== ДЕМОНСТРАЦИЯ КОМПОЗИЦИИ===" << std::endl;

   // Создание треугольника с композицией
   TriangleComposition* triangle1 = new TriangleComposition(0, 0, 3, 0, 0, 4);

   triangle1->printSides();
   std::cout << "Периметр: " << triangle1->calculatePerimeter() << std::endl;
   std::cout << "Площадь: " << triangle1->calculateArea() << std::endl;

   std::cout << "\n=== ДЕМОНСТРАЦИЯ АГРЕГАЦИИ===" << std::endl;

   // Создание отдельных точек
   Dot* p1 = new Dot(0, 0);
   Dot* p2 = new Dot(5, 0);
   Dot* p3 = new Dot(0, 12);

   // Создание треугольника с агрегацией
   TriangleAggregation* triangle2 = new TriangleAggregation(p1, p2, p3);

   triangle2->printSides();
   std::cout << "Периметр: " << triangle2->calculatePerimeter() << std::endl;
   std::cout << "Площадь: " << triangle2->calculateArea() << std::endl;   

   // Удаляем все объекты
   std::cout << "\n=== ОСВОБОЖДЕНИЕ ПАМЯТИ ===" << std::endl;

   // Важно удалять в правильном порядке!
   // Сначала удаляем треугольник агрегации (он использует точки)
   delete triangle2;
   std::cout << "triangle2 удален" << std::endl;

   // Точки продолжают существовать независимо от треугольника
   std::cout << "\nРасстояние между p1 и p2: " << p1->distanceTo(*p2) << std::endl;

   // Затем удаляем точки
   delete p1;
   delete p2;
   delete p3;
   std::cout << "\nТочки p1, p2, p3 удалены" << std::endl;

   // Удаляем треугольник композиции
   delete triangle1;
   std::cout << "triangle1 удален" << std::endl;

   return 0;
}