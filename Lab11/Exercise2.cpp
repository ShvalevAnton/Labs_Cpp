#include <iostream>
#include <Windows.h>
#include "Distance2.h"

using namespace std;

int Exercise2()
{
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   Distance2 dist2;

   Distance2 dist1 = 2.35F;

   float mtrs;

   mtrs = static_cast<float>(dist1);
   
   mtrs = dist2;

   cout << "dist2 � ������ (������� ��������������): " << mtrs << " �" << endl;

   // �������������� ������������
   cout << "\n�������������� ������������:" << endl;
   cout << "����� ����� �������� << : " << dist1;

   // �������� ��������� ��������������
   Distance2 dist3(3, 6.5f); // 3 ���� 6.5 ������
   cout << "dist3 (3 ���� 6.5 ������): " << dist3;
   cout << "dist3 � ������: " << static_cast<float>(dist3) << " �" << endl;

   return 0;
}