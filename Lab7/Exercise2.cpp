#include <iostream>
#include <Windows.h>
using namespace std;

struct Distance1
{
   int feet;
   double inches;

   void ShowDist()
   {
      cout << "���������: " << feet << "\'-" << inches << "\"\n";
   }
};

Distance1 AddDist(const Distance1& d1, const Distance1& d2)
{
   Distance1 d;
   d.feet = d1.feet + d2.feet;
   d.inches = d1.inches + d2.inches;
   if (d.inches >= 12.0)
   {
      d.inches -= 12.0;
      d.feet++;
   }
   return d;
}

Distance1 InputDist()
{
   Distance1 d;
   cout << "\n������� ����� �����: ";
   cin >> d.feet;
   cout << "������� ����� ������: ";
   cin >> d.inches;
   return d;
}

//void ShowDist(Distance d)
//{
//   cout << "���������: " << d.feet << "\'-" << d.inches << "\"\n";
//}

int Exercise2()
{
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   Distance1 d1 = InputDist();
   Distance1 d2 = { 1, 6.25 };

   Distance1 d3;

   d3 = AddDist(d1, d2);

   /*ShowDist(d1);
   ShowDist(d2);
   ShowDist(d3);*/

   d1.ShowDist();
   d2.ShowDist();
   d3.ShowDist();   

   return 0;
}