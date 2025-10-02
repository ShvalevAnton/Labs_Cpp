#include <iostream>
#include <Windows.h>
#include <cmath>
#include <iomanip>
using namespace std;

long double firBinSearch(double a, int n)
{
   double L = 0;
   double R = a;
   while (R - L > 1e-10)
   {
      double M = (L + R) / 2;
      if (pow(M, n) < a)
      {
         L = M;
      }
      else
      {
         R = M;
      }
   }
   return R;
}

int Exercise4()
{
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   double a;
   int n;

   // ���� �������� ������
   cout << "������� ����� a: ";
   cin >> a;
   cout << "������� ������� ����� n: ";
   cin >> n;

   // �������� ������������ ������� ������
   if (a < 0 && n % 2 == 0) {
      cout << "������: ������ ������� ������ ������ ������� �� �������������� �����" << endl;
      return 1;
   }

   if (n <= 0) {
      cout << "������: ������� ����� ������ ���� ������������� ������" << endl;
      return 1;
   }

   // ����� ������� ��������� ������
   long double result = firBinSearch(abs(a), n);

   // ���� ����� ��� ������������� ����� � �������� ��������
   if (a < 0) {
      result = -result;
   }

   // ����� ���������� � ��������� �� ����� 6 ������ ����� �������
   cout << fixed << setprecision(10);
   cout << "������ ������� " << n << " �� " << a << " = " << result << endl;

   return 0;
}