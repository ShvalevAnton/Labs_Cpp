#include "triangle_aggregation.h"
#include <iostream>
#include <cmath>

TriangleAggregation::TriangleAggregation(Dot* p1, Dot* p2, Dot* p3)  // убираем const
   : point1(p1), point2(p2), point3(p3)
{
}

void TriangleAggregation::printSides()
{
   double side1 = point1->distanceTo(*point2);
   double side2 = point2->distanceTo(*point3);
   double side3 = point3->distanceTo(*point1);

   std::cout << "Длины сторон треугольника:" << std::endl;
   std::cout << "Сторона 1: " << side1 << std::endl;
   std::cout << "Сторона 2: " << side2 << std::endl;
   std::cout << "Сторона 3: " << side3 << std::endl;
}

double TriangleAggregation::calculatePerimeter()
{
   double side1 = point1->distanceTo(*point2);
   double side2 = point2->distanceTo(*point3);
   double side3 = point3->distanceTo(*point1);

   return side1 + side2 + side3;
}

double TriangleAggregation::calculateArea()
{
   double side1 = point1->distanceTo(*point2);
   double side2 = point2->distanceTo(*point3);
   double side3 = point3->distanceTo(*point1);

   // Формула Герона
   double p = (side1 + side2 + side3) / 2.0;
   return sqrt(p * (p - side1) * (p - side2) * (p - side3));
}