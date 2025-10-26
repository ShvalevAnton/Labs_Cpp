#include <iostream>
#include <Windows.h>
#include "Distance.h"

using namespace std;

int Exercise1()
{
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   Distance dist1, dist2, dist3, dist4;

   // Заполнение данными
   dist1.getdist();
   dist2.getdist();
   
   dist3 = dist1 - dist2;

   cout << "\n dist1 = ";
   cout << "\ndist1 = " << dist1;
   cout << "\n dist2 = ";
   cout << "\ndist1 = " << dist2;
   cout << "\n dist3 = ";
   cout << "\ndist1 = " << dist3;

   return 0;
}