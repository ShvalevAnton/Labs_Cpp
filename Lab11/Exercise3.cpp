#include <iostream>
#include <Windows.h>
#include "Distance2.h"

using namespace std;

int Exercise3()
{
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   Distance2 dist1(5, 6.0f); // 5 ����� 6 ������
   Distance2 dist2(2, 3.5f); // 2 ���� 3.5 ������

   cout << "�������� ����������:" << endl;
   cout << "dist1: " << dist1;
   cout << "dist2: " << dist2;

   // ������������ ���������� � ������� ������
   cout << "\n�������� � ������� ������:" << endl;

   // Distance2 + float
   Distance2 dist3 = dist1 + 1.5f; // 1.5 �����
   cout << "dist1 + 1.5 ����� = " << dist3;

   // float + Distance2  
   Distance2 dist4 = 1.5f + dist1;
   cout << "1.5 ����� + dist1 = " << dist4;

   // Distance2 - float
   Distance2 dist5 = dist1 - 0.5f; // 0.5 �����
   cout << "dist1 - 0.5 ����� = " << dist5;

   // float - Distance2
   Distance2 dist6 = 3.0f - dist2; // 3.0 ����� - dist2
   cout << "3.0 ����� - dist2 = " << dist6;

   // ��������������� ��������
   cout << "\n��������������� ��������:" << endl;
   Distance2 result = dist1 + 1.0f - 0.5f;
   cout << "dist1 + 1.0 - 0.5 = " << result;

   return 0;
}