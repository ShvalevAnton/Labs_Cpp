#include "Exercises.h"
#include <iostream>
#include <cmath>
#include <iomanip>
#include <Windows.h>

int TriangleArea() {

   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   double perimeter;

   // ���� ��������� �� ������������
   std::cout << "������� �������� ��������������� ������������: ";
   std::cin >> perimeter;

   // ���������� ����� ������� (��� ������� ����� � �������������� ������������)
   double side = perimeter / 3.0;

   // ������������
   double p = perimeter / 2.0;

   // ������� ������: S = sqrt(p * (p - a) * (p - b) * (p - c))
   // ��� ��� a = b = c = side, ��:
   double area = std::sqrt(p * (p - side) * (p - side) * (p - side));

   // ����� �������
   std::cout << std::fixed << std::setprecision(2);
   std::cout << "�������   �������" << std::endl;
   std::cout << side << "      " << area << std::endl;

   return 0;
}