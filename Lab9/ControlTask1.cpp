#include <iostream>
#include <Windows.h>
#include <string>

class Triangle {
private:
   double sideA, sideB, sideC;

   // ��������������� ������� ��� �������� ���������� ������
   bool isValidTriangle(double a, double b, double c) const {
      return (a > 0 && b > 0 && c > 0) &&
         (a + b > c) &&
         (a + c > b) &&
         (b + c > a);
   }

public:
   // ����������� �� ���������
   Triangle() : sideA(1.0), sideB(1.0), sideC(1.0) {}

   // ����������� � �����������
   Triangle(double a, double b, double c) {
      setSides(a, b, c);
   }

   // ������� ��� ������ � ���������
   void setSideA(double a) {
      if (!isValidTriangle(a, sideB, sideC)) {
         throw std::invalid_argument("������������ ����� ������� A: " + std::to_string(a));
      }
      sideA = a;
   }

   void setSideB(double b) {
      if (!isValidTriangle(sideA, b, sideC)) {
         throw std::invalid_argument("������������ ����� ������� B: " + std::to_string(b));
      }
      sideB = b;
   }

   void setSideC(double c) {
      if (!isValidTriangle(sideA, sideB, c)) {
         throw std::invalid_argument("������������ ����� ������� C: " + std::to_string(c));
      }
      sideC = c;
   }

   // ��������� ���� ������ ������������
   void setSides(double a, double b, double c) {
      if (!isValidTriangle(a, b, c)) {
         throw std::invalid_argument(
            "������������ ����� ������: " +
            std::to_string(a) + ", " +
            std::to_string(b) + ", " +
            std::to_string(c) +
            " - �������� ����������� ������������"
         );
      }
      sideA = a;
      sideB = b;
      sideC = c;
   }

   // �������
   double getSideA() const { return sideA; }
   double getSideB() const { return sideB; }
   double getSideC() const { return sideC; }

   // ������� ��� ���������� ������� �� ������� ������
   double calculateArea() const {
      double p = (sideA + sideB + sideC) / 2.0; // ������������
      return std::sqrt(p * (p - sideA) * (p - sideB) * (p - sideC));
   }

   // ����� ���������� � ������������
   void printInfo() const {
      std::cout << "����������� �� ���������: "
         << sideA << ", " << sideB << ", " << sideC
         << "\n�������: " << calculateArea() << std::endl;
   }
};

// ������������ ������ ������
int ControlTask1() 
{
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   try {
      std::cout << "=== ������������ ������ ������ Triangle ===\n" << std::endl;

      // �������� ��������� ������������
      std::cout << "1. �������� ��������� ������������ (3, 4, 5):" << std::endl;
      Triangle t1(3, 4, 5);
      t1.printInfo();
      std::cout << std::endl;

      // ������� �������� ����������� ������������
      std::cout << "2. ������� �������� ����������� ������������ (1, 2, 5):" << std::endl;
      try {
         Triangle t2(1, 2, 5);
      }
      catch (const std::exception& e) {
         std::cout << "������: " << e.what() << std::endl;
      }
      std::cout << std::endl;

      // ��������� ������ � ���������
      std::cout << "3. ��������� ������ ������������� ������������:" << std::endl;
      Triangle t3(5, 5, 5); // �������������� �����������
      t3.printInfo();

      std::cout << "\n������� �������� ������� A �� ������������ �������� (20):" << std::endl;
      try {
         t3.setSideA(20);
      }
      catch (const std::exception& e) {
         std::cout << "������: " << e.what() << std::endl;
      }

      std::cout << "\n�������� ��������� ������ (6, 6, 6):" << std::endl;
      t3.setSides(6, 6, 6);
      t3.printInfo();
      std::cout << std::endl;

      // ���� � ������� ��������
      std::cout << "4. ������� �������� ������������ � ������� ��������:" << std::endl;
      try {
         Triangle t4(0, 4, 5);
      }
      catch (const std::exception& e) {
         std::cout << "������: " << e.what() << std::endl;
      }
      std::cout << std::endl;

      // ���� � ������������� ��������
      std::cout << "5. ������� �������� ������������ � ������������� ��������:" << std::endl;
      try {
         Triangle t5(3, -4, 5);
      }
      catch (const std::exception& e) {
         std::cout << "������: " << e.what() << std::endl;
      }

   }
   catch (const std::exception& e) {
      std::cerr << "�������������� ������: " << e.what() << std::endl;
      return 1;
   }

   return 0;
}