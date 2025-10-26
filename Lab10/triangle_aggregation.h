#pragma once
#ifndef TRIANGLE_AGGREGATION_H
#define TRIANGLE_AGGREGATION_H

#include "dot.h"

class TriangleAggregation
{
private:
   Dot* point1;  // убираем const
   Dot* point2;
   Dot* point3;

public:
   //  онструктор с указател€ми на существующие точки
   TriangleAggregation(Dot* p1, Dot* p2, Dot* p3);  // убираем const

   // ћетоды класса
   void printSides();
   double calculatePerimeter();
   double calculateArea();
};

#endif