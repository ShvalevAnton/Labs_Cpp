#include <iostream>
#include <Windows.h>
using namespace std;

void swap(int*, int*);
void swap(int&, int&);

void swap(int* x, int* y)
{
   int temp;
   temp = *x;
   *x = *y;
   *y = temp;
}
void swap(int& x, int& y)
{
   int temp;
   temp = x;
   x = y;
   y = temp;
}

void print(int x, int y)
{
   cout << "x = " << x << "; y = " << y << endl;
}

int Exercise2()
{
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   int x = 5, y = 10;

   swap(&x, &y);
   print(x, y);

   swap(x, y);
   print(x, y);
   

   return 0;
}

