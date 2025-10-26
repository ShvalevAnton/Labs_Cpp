#include "triangle_composition.h"
#include <iostream>
#include <cmath>

TriangleComposition::TriangleComposition(double x1, double y1, double x2, double y2, double x3, double y3)
   : point1(x1, y1), point2(x2, y2), point3(x3, y3)
{
}

void TriangleComposition::printSides()
{
   double side1 = point1.distanceTo(point2);
   double side2 = point2.distanceTo(point3);
   double side3 = point3.distanceTo(point1);

   std::cout << "Длины сторон треугольника:" << std::endl;
   std::cout << "Сторона 1: " << side1 << std::endl;
   std::cout << "Сторона 2: " << side2 << std::endl;
   std::cout << "Сторона 3: " << side3 << std::endl;
}

double TriangleComposition::calculatePerimeter()
{
   double side1 = point1.distanceTo(point2);
   double side2 = point2.distanceTo(point3);
   double side3 = point3.distanceTo(point1);

   return side1 + side2 + side3;
}

double TriangleComposition::calculateArea()
{
   double side1 = point1.distanceTo(point2);
   double side2 = point2.distanceTo(point3);
   double side3 = point3.distanceTo(point1);

   // Формула Герона
   double p = (side1 + side2 + side3) / 2.0;
   return sqrt(p * (p - side1) * (p - side2) * (p - side3));
}
