#include <iostream>
#include "structures.h"
#include "functions.h"
#include <Windows.h>
using namespace std;

int Exercise3()
{
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   Distance d1 = InputDist();
   Distance d2 = { 1, 6.25 };

   Distance d3;

   d3 = AddDist(d1, d2);

   d1.ShowDist();
   d2.ShowDist();
   d3.ShowDist();

   int n;
   cout << "¬ведите размер массива рассто€ний ";
   cin >> n;
   Distance *masDist = new Distance[n];

   Distance SumDist{0,0};
   for (int i = 0; i < n; i++)
   {
      masDist[i] = InputDist();
      SumDist = AddDist(SumDist, masDist[i]);
   }
   SumDist.ShowDist();

   delete[] masDist;

   return 0;
}