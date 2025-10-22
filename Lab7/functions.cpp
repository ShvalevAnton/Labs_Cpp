#include "functions.h"
#include <iostream>
#include "structures.h"
#include <string>
#include <tuple>
#include <vector>

using namespace std;

Distance AddDist(const Distance& d1, const Distance& d2)
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

//Distance AddDist(Distance d1, Distance d2)
//{
//   Distance d;
//   d.feet = d1.feet + d2.feet;
//   d.inches = d1.inches + d2.inches;
//   if (d.inches >= 12.0)
//   {
//      d.inches -= 12.0;
//      d.feet++;
//   }
//   return d;
//}

Distance InputDist()
{
   Distance d;
   cout << "\n������� ����� �����: ";
   cin >> d.feet;
   cout << "������� ����� ������: ";
   cin >> d.inches;
   return d;
}

void printTupleOfThree(tuple<string, int, double> t)
{
   cout << "("
      << std::get<0>(t) << ", "
      << std::get<1>(t) << ", "
      << std::get<2>(t) << ")" << endl;
}