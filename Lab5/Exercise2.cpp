#include <iostream>
#include <Windows.h>
using namespace std;

int Exercise2()
{
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   const int N = 10;
   int a[N] = { 1, 25, 6, 32, 43, 5, 96, 23, 4, 55 };
   int min = 0; // дл€ записи минимального значени€
   int buf = 0; // дл€ обмена значени€ми

   for (int i = 0; i < N; i++)
   {
      min = i; // номер текущей €чейки, как €чейки с минимальным значением
      // в цикле найдем реальный номер €чейки с минимальным значением
      for (int j = i + 1; j < N; j++)
         min = (a[j] < a[min]) ? j : min;
      // перестановка этого элемента, помен€в его местами с текущим
      if (i != min)
      {
         buf = a[i];
         a[i] = a[min];
         a[min] = buf;
      }
   }
   for (int i : a)
      cout << i << '\t';
  
   return 0;
}