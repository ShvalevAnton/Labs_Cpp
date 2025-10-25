#pragma once
#include "structures.h"
#include <string>
#include <tuple>

using namespace std;
using Tuple = tuple<string, int, double>;

Distance AddDist(const Distance& d1, const Distance& d2);
Distance InputDist();
//void printTupleOfThree(tuple<string, int, double> t);
void printTupleOfThree(Tuple t);