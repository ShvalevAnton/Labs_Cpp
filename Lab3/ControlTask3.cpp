#include <iostream>
#include <Windows.h>
#include <cmath>
#include <iomanip>
using namespace std;

// ������� ��� ���������� ������� ��������������� ������������
double calculateArea(double side) {
   // �������: S = (sqrt(3) / 4) * a^2
   return (sqrt(3) / 4.0) * side * side;
}

// ������� ��� ���������� ������� ��������������� ������������ �� ��� ��������
double calculateArea(double a, double b, double c) {
   // �������� ������������� ������������
   if (a + b <= c || a + c <= b || b + c <= a) {
      throw invalid_argument("����������� � ������ ��������� �� ����������!");
   }

   // ������� ������
   double p = (a + b + c) / 2.0; // ������������
   return sqrt(p * (p - a) * (p - b) * (p - c));
}


int ControlTask3() {
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);
   setlocale(LC_ALL, "Russian"); // ��� ����������� ����������� �������� ����� � ������� (�����������)

   cout << "�������� ��� ������������:\n";
   cout << "1. ��������������\n";
   cout << "2. ��������������\n";
   cout << "��� �����: ";

   int choice;
   cin >> choice;

   try {
      if (choice == 1) {
         double side;
         cout << "������� ����� ������� ��������������� ������������: ";
         cin >> side;

         if (side <= 0) {
            cout << "������: ������� ������ ���� �������������!\n";
            return 1;
         }

         double area = calculateArea(side);
         cout << fixed << setprecision(2);
         cout << "������� ��������������� ������������: " << area << endl;

      }
      else if (choice == 2) {
         double a, b, c;
         cout << "������� ��� ������� ��������������� ������������: ";
         cin >> a >> b >> c;

         if (a <= 0 || b <= 0 || c <= 0) {
            cout << "������: ��� ������� ������ ���� ��������������!\n";
            return 1;
         }

         double area = calculateArea(a, b, c);
         cout << fixed << setprecision(2);
         cout << "������� ��������������� ������������: " << area << endl;
      }
      else {
         cout << "������: �������� �����. �������� 1 ��� 2.\n";
         return 1;
      }
   }
   catch (const invalid_argument& e) {
      cout << "������: " << e.what() << endl;
      return 1;
   }

   return 0;
}