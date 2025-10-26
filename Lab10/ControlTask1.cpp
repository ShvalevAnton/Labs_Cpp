#include <iostream>
#include <Windows.h>
#include "dot.h"
#include "triangle_composition.h"
#include "triangle_aggregation.h"

int ControlTask1()
{
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   std::cout << "=== ������������ ����������===" << std::endl;

   // �������� ������������ � �����������
   TriangleComposition* triangle1 = new TriangleComposition(0, 0, 3, 0, 0, 4);

   triangle1->printSides();
   std::cout << "��������: " << triangle1->calculatePerimeter() << std::endl;
   std::cout << "�������: " << triangle1->calculateArea() << std::endl;

   std::cout << "\n=== ������������ ���������===" << std::endl;

   // �������� ��������� �����
   Dot* p1 = new Dot(0, 0);
   Dot* p2 = new Dot(5, 0);
   Dot* p3 = new Dot(0, 12);

   // �������� ������������ � ����������
   TriangleAggregation* triangle2 = new TriangleAggregation(p1, p2, p3);

   triangle2->printSides();
   std::cout << "��������: " << triangle2->calculatePerimeter() << std::endl;
   std::cout << "�������: " << triangle2->calculateArea() << std::endl;   

   // ������� ��� �������
   std::cout << "\n=== ������������ ������ ===" << std::endl;

   // ����� ������� � ���������� �������!
   // ������� ������� ����������� ��������� (�� ���������� �����)
   delete triangle2;
   std::cout << "triangle2 ������" << std::endl;

   // ����� ���������� ������������ ���������� �� ������������
   std::cout << "\n���������� ����� p1 � p2: " << p1->distanceTo(*p2) << std::endl;

   // ����� ������� �����
   delete p1;
   delete p2;
   delete p3;
   std::cout << "\n����� p1, p2, p3 �������" << std::endl;

   // ������� ����������� ����������
   delete triangle1;
   std::cout << "triangle1 ������" << std::endl;

   return 0;
}