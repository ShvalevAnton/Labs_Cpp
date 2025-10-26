#pragma once
#include "dot.h"

class TriangleComposition
{
private:
   Dot point1;
   Dot point2;
   Dot point3;

public:
   // Конструктор с координатами точек
   TriangleComposition(double x1, double y1, double x2, double y2, double x3, double y3);

   // Методы класса
   void printSides();
   double calculatePerimeter();
   double calculateArea();
};

