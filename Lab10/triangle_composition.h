#pragma once
#include "dot.h"

class TriangleComposition
{
private:
   Dot point1;
   Dot point2;
   Dot point3;

public:
   // ����������� � ������������ �����
   TriangleComposition(double x1, double y1, double x2, double y2, double x3, double y3);

   // ������ ������
   void printSides();
   double calculatePerimeter();
   double calculateArea();
};

