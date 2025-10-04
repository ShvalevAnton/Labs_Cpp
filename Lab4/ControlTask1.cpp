#include <iostream>
#include <cmath>
#include <Windows.h>
using namespace std;

// ������� ���������� ������ ����������� ���������
// ����������:
//   1 � ��� ��������� �������������� �����,
//   0 � ���� ������ (������������ = 0),
//  -1 � ��� �������������� ������ (������������ < 0)
int Myroot(double a, double b, double c, double& x1, double& x2) {
   // ��������, ������������� �� ��������� ����������
   if (a == 0.0) {
      // ��������� ����������� � ��������: bx + c = 0
      if (b == 0.0) {
         // ��������� �� ����� ������ (0 = c)
         if (c == 0.0) {
            // 0 = 0 � ���������� ����� �������, �� �� ������� ������
            // ��������� �������� � ���������� ����������,
            // ������� �������, ��� ������ ���
            return -1;
         }
         else {
            return -1; // ��� �������
         }
      }
      else {
         // �������� ���������: ���� ������
         x1 = x2 = -c / b;
         return 0; // ��������� ���� ������
      }
   }

   double D = b * b - 4 * a * c; // ������������

   if (D < 0) {
      return -1; // �������������� ������ ���
   }
   else if (D == 0) {
      x1 = x2 = -b / (2 * a);
      return 0; // ���� ������ (�������)
   }
   else {
      double sqrtD = std::sqrt(D);
      x1 = (-b + sqrtD) / (2 * a);
      x2 = (-b - sqrtD) / (2 * a);
      return 1; // ��� ��������� �����
   }
}


int ControlTask1()
{
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   double a, b, c;
   double x1, x2;

   std::cout << "������� ������������ a, b, c ����������� ��������� ax^2 + bx + c = 0:\n";
   std::cin >> a >> b >> c;

   int result = Myroot(a, b, c, x1, x2);

   switch (result) {
   case -1:
      std::cout << "������ ��������� ���\n";
      break;
   case 0:
      std::cout << "������ ��������� ���� x1 = x2 = " << x1 << "\n";
      break;
   case 1:
      std::cout << "����� ��������� x1 = " << x1 << ", x2 = " << x2 << "\n";
      break;
   default:
      std::cout << "����������� ������\n";
      break;
   }

   return 0;
}

