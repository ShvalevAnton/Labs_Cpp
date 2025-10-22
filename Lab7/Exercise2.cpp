#include <iostream>
#include "structures.h"
#include <Windows.h>
#include "functions.h"
using namespace std;

int Exercise2()
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

   return 0;
}