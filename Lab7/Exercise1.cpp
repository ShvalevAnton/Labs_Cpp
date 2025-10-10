#include <iostream>
#include <Windows.h>
using namespace std;

struct Distance
{
   int feet;
   double inches;

   void ShowDist()
   {
      cout << "Дистанция: " << feet << "\'-" << inches << "\"\n";
   }
};

Distance AddDist(Distance d1, Distance d2)
{
   Distance d;
   d.feet = d1.feet + d2.feet;
   d.inches = d1.inches + d2.inches;
   if (d.inches >= 12.0)
   {
      d.inches -= 12.0;
      d.feet++;
   }
   return d;
}

Distance InputDist()
{
   Distance d;
   cout << "\nВведите число футов: ";
   cin >> d.feet;
   cout << "Введите число дюймов: ";
   cin >> d.inches;
   return d;
}

//void ShowDist(Distance d)
//{
//   cout << "Дистанция: " << d.feet << "\'-" << d.inches << "\"\n";
//}

int Exercise1()
{
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   Distance d1 = InputDist();
   Distance d2 = { 1, 6.25 };

   Distance d3;

   d3 = AddDist(d1, d2);

   /*ShowDist(d1);
   ShowDist(d2);
   ShowDist(d3);*/

   d1.ShowDist();
   d2.ShowDist();
   d3.ShowDist();   

   return 0;
}