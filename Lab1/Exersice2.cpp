#include "Exercises.h"

#include <iostream>
#include <string>
using namespace std;

int Exercise2()
{
   system("chcp 1251");
   string name;
   cout << "������� ���� ���\n";
   double a, b; 
   cout << "������� a � b:\n";
   cin >> a; // ���� � ���������� �������� a
   cin >> name;


   cin >> b; // ���� � ���������� �������� b
   double x = a / b; // ���������� �������� x
   //int x = a / b; // ���������� �������� x
   cout.precision(3);
   cout<< "\nx = " << x << endl; //����� ���������� �� �����
   cout << sizeof(a / b) << ends << " B, " << sizeof(x) << " B." << endl; // ������� ������ ���������� ������ � ������
   cout << "������, " << name << "!\n";
   return 0;
}