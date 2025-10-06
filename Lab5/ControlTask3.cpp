#include <iostream>
#include <Windows.h>
#include <vector>
using namespace std;

// ������� ������ � �������������
int transpositionSearch(vector<int>& arr, int key) {
   for (int i = 0; i < arr.size(); ++i) {
      if (arr[i] == key) {
         // ���� ������� �� ������ � ������ � ����������
         if (i > 0) {
            swap(arr[i], arr[i - 1]);
            return i - 1; // ���������� ����� ������
         }
         return i; // ���� ��� �� ������ �����
      }
   }
   return -1; // ������� �� ������
}

int ControlTask3()
{
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   vector<int> data = { 10, 20, 30, 40, 50 };

   cout << "�������� ������: ";
   for (int x : data) cout << x << " ";
   cout << "\n";

   int key = 30;
   int index = transpositionSearch(data, key);

   if (index != -1) {
      cout << "������� " << key << " ������ �� ������� " << index << "\n";
   }
   else {
      cout << "������� " << key << " �� ������\n";
   }

   cout << "������ ����� ������: ";
   for (int x : data) cout << x << " ";
   cout << "\n";

   return 0;
}

