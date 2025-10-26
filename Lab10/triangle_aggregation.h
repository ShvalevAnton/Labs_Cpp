#pragma once
#ifndef TRIANGLE_AGGREGATION_H
#define TRIANGLE_AGGREGATION_H

#include "dot.h"

class TriangleAggregation
{
private:
   Dot* point1;  // ������� const
   Dot* point2;
   Dot* point3;

public:
   // ����������� � ����������� �� ������������ �����
   TriangleAggregation(Dot* p1, Dot* p2, Dot* p3);  // ������� const

   // ������ ������
   void printSides();
   double calculatePerimeter();
   double calculateArea();
};

#endif