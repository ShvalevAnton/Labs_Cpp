#include <iostream>
#include <Windows.h>
#include <fstream>
using namespace std;

int ControlTask2()
{
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   const int N = 10;
   int a[N] = { 1, 25, 6, 32, 43, 5, 96, 23, 4, 55 };
   int min = 0; // ��� ������ ������������ ��������
   int buf = 0; // ��� ������ ����������

   // ��������� ���� ��� ������
   ofstream file("array.txt");
   if (!file.is_open()) {
      cerr << "������: �� ������� ������� ���� ��� ������." << endl;
      return 1;
   }

   // ���������� �������� ������
   file << "�������� ������:" << endl;
   for (int i = 0; i < N; i++) {
      file << a[i] << ' ';
   }
   file << endl;

   // ���������� ������� (�������� ���������� �������)
   for (int i = 0; i < N; i++)
   {
      min = i; // ����� ������� ������, ��� ������ � ����������� ���������
      // � ����� ������ �������� ����� ������ � ����������� ���������
      for (int j = i + 1; j < N; j++)
         min = (a[j] < a[min]) ? j : min;
      // ������������ ����� ��������, ������� ��� ������� � �������
      if (i != min)
      {
         buf = a[i];
         a[i] = a[min];
         a[min] = buf;
      }
   }

   // ���������� ��������������� ������
   file << "��������������� ������:" << endl;
   for (int i = 0; i < N; i++) {
      file << a[i] << ' ';
   }
   file << endl;

   file.close();

   // ����� �� ����� ��� ��������
   cout << "������� �������� � ���� array.txt" << endl;
   for (int i : a)
      cout << i << '\t';


   return 0;
}