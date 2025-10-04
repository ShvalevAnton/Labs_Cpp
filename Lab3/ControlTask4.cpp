#include <iostream>
#include <Windows.h>
using namespace std;

// ����������� ������� ��� ���������� ����� ���� S = 5 + 10 + 15 + ... + 5*n
int sumSeries(int n) {
   if (n == 1) {
      return 5;
   }
   return 5 * n + sumSeries(n - 1);
}


int ControlTask4() {
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);
   
   int n;
   cout << "������� ������������� ����� ����� n: ";
   cin >> n;

   if (n <= 0) {
      cout << "������: n ������ ���� ������ 0.\n";
      return 1;
   }

   int result = sumSeries(n);
   cout << "����� ���� S = 5 + 10 + 15 + ... + " << 5 * n << " ����� " << result << endl;

   return 0;
}