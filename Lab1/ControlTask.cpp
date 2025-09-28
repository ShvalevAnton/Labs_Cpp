#include "Exercises.h"

#include <iostream>
#include <cmath>
#include <iomanip>
#include <Windows.h>

int ControlTask() {

   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   const int N = 5; // ������������
   double x[N], y[N];

   std::cout << "������� ���������� ������ ��������� ������������� (� ������� ������):\n";
   for (int i = 0; i < N; ++i) {
      std::cout << "������� " << (i + 1) << " (x y): ";
      std::cin >> x[i] >> y[i];
   }

   // ��������� ������� ������
   double sum = 0.0;
   for (int i = 0; i < N; ++i) {
      int next = (i + 1) % N; // ��������� ������� (��������� ����������� � ������)
      sum += x[i] * y[next] - x[next] * y[i];
   }

   double area = std::abs(sum) / 2.0;

   // ����� � ����� ������� ����� �������
   std::cout << std::fixed << std::setprecision(2);
   std::cout << "������� �������������: " << area << std::endl;

   return 0;
}