#include <iostream>
#include <Windows.h>
using namespace std;


int ControlTask1()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	
   int n;
   cout << "������� �����: ";
   cin >> n;

   bool isPrimeN = true;

   // ��������, �������� �� n �������
   if (n <= 1) {
      isPrimeN = false;
   }
   else if (n == 2) {
      isPrimeN = true;
   }
   else if (n % 2 == 0) {
      isPrimeN = false;
   }
   else {
      for (int i = 3; i * i <= n; i += 2) {
         if (n % i == 0) {
            isPrimeN = false;
            break;
         }
      }
   }

   bool isSuperPrime = false;

   if (isPrimeN) {
      int count = 0;
      int num = 2;

      while (num <= n) {
         bool isPrimeNum = true;

         // ��������, �������� �� num �������
         if (num <= 1) {
            isPrimeNum = false;
         }
         else if (num == 2) {
            isPrimeNum = true;
         }
         else if (num % 2 == 0) {
            isPrimeNum = false;
         }
         else {
            for (int j = 3; j * j <= num; j += 2) {
               if (num % j == 0) {
                  isPrimeNum = false;
                  break;
               }
            }
         }

         if (isPrimeNum) {
            count++;
            if (num == n) {
               // ��������, �������� �� count (����� n ����� �������) �������
               bool isPrimeCount = true;
               if (count <= 1) {
                  isPrimeCount = false;
               }
               else if (count == 2) {
                  isPrimeCount = true;
               }
               else if (count % 2 == 0) {
                  isPrimeCount = false;
               }
               else {
                  for (int k = 3; k * k <= count; k += 2) {
                     if (count % k == 0) {
                        isPrimeCount = false;
                        break;
                     }
                  }
               }
               isSuperPrime = isPrimeCount;
               break;
            }
         }
         num++;
      }
   }

   if (isSuperPrime) {
      cout << n << " - ������������ �����." << endl;
   }
   else {
      cout << n << " - �� ������������ �����." << endl;
   }

	return 0;
}