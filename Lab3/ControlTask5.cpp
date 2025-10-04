#include <iostream>
#include <Windows.h>
using namespace std;

// ����������� ������� ��� �������� ����� � �������� �������
void decToBin(int num) {
   if (num > 1) {
      decToBin(num / 2); // ����������� ����� � ����� ������ �� ������� �� 2
   }
   cout << num % 2;  // ����� ������� �� ������� �� 2
}


int ControlTask5() {
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   int number;
   cout << "������� ����� ������������� �����: ";
   cin >> number;

   if (number < 0) {
     cout << "������: ������� ������������� �����!" << endl;
      return 1;
   }

   if (number == 0) {
      cout << "0" << endl;
   }
   else {
      decToBin(number);
      cout << endl;
   }

   return 0;
}