#include <iostream>
#include <Windows.h>
#include "functions.h"

using namespace std;

int Exercise1()
{
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   int arr[] = { 9,3,17,6,5,4,31,2,12 };
   double arrd[] = { 2.1, 2.3,1.7,6.6,5.3,2.44,3.1,2.4,1.2 };
   char arrc[] = "Hello, word";
   int k1 = sizeof(arr) / sizeof(arr[0]);  
   int k2 = sizeof(arrd) / sizeof(arrd[0]);
   int k3 = sizeof(arrc) / sizeof(arrc[0]) - 1;

   cout << k1 << " " << k2 << " " << k3 << " " << endl;

   sorting(arr, k1);
   for (int i = 0; i < k1; i++) cout << arr[i] << ";";
   cout << endl;
   sorting(arrd, k2);
   for (int i = 0; i < k2; i++) cout << arrd[i] << ";";
   cout << endl;
   sorting(arrc, k3);
   for (int i = 0; i < k3; i++) cout << arrc[i] << ";";
   cout << endl;

   return 0;
}