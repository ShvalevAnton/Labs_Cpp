#include "functions.h"
#include <iostream>
#include "structures.h"
#include <string>
#include <tuple>
#include <vector>

using namespace std;
using Tuple = tuple<string, int, double>;

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

Distance InputDist()
{
   Distance d;
   cout << "\n¬ведите число футов: ";
   cin >> d.feet;
   cout << "¬ведите число дюймов: ";
   cin >> d.inches;
   return d;
}

void printTupleOfThree(Tuple t)
//void printTupleOfThree(tuple<string, int, double> t)
{
   cout << "("
      << get<0>(t) << ", "
      << get<1>(t) << ", "
      << get<2>(t) << ")" << endl;
}