#include <iostream>
#include <Windows.h>
using namespace std;

int ControlTask3()
{
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   // �������� ������� ������ (�������� � ��������)
   int coins[] = { 1000, 500, 100, 50, 10, 5, 1 };
   int coin_count = sizeof(coins) / sizeof(coins[0]); // ���������� ���������
   int amount;
   cout << "������� ����� � ��������: "; cin >> amount;

   // ������������ ���������� �����, ������� ����� ������������ (� ������ ������ � ��� �� 1 �������)
   int result[10000]; // ����� ���������, ���� ��������� ������� �����
   int result_size = 0; // ������� ������ ����������

   for (int i = 0; i < coin_count; ++i) {
      while (amount >= coins[i]) {
         result[result_size++] = coins[i];
         amount -= coins[i];
      }
   }

   cout << "����� �����:\n";
   for (int i = 0; i < result_size; ++i) {
      cout << result[i] << " ";
   }
   cout << endl;

   return 0;
  

   return 0;
}

