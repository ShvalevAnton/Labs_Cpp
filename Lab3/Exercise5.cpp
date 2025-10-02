#include <iostream>
#include <Windows.h>
#include <cmath>
#include <iomanip>
using namespace std;

int addNumders(int n)
{
   if (n == 1) return 1; // ����� �� ��������
   else return (n + addNumders(n - 1));
}

int gcd(int m, int n)
{
   if (n == 0) return m;
   return gcd(n, m % n);
}

int Exercise5()
{
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);
   
   int n;
   // ���� �������� ������
   cout << "������� ����� n: "; cin >> n;   
   // ����� ������� 
   int result = addNumders(n);   
   // ����� ����������
   cout << "���������: " << n << endl;

   // �������� �������
   cout << "�������� �������" << endl;
   int a,b;
   // ���� �������� ������
   cout << "������� ����� a: "; cin >> a;
   cout << "������� ����� b: "; cin >> b;

   // ����� ������� 
   result = gcd(a,b);
   // ����� ����������
   cout << "���������: " << result << endl;
   return 0;
}