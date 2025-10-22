#include <iostream>
#include <windows.h>
#include <string>
#include <tuple>
#include <vector>
#include "functions.h"
//using namespace std;



int Exercise4()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	vector<string> v1{ "one", "two", "three", "four", "five", "six" };
	vector<int> v2 = { 1, 2, 3, 4, 5, 6 };
	vector<double> v3 = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6 };

	auto t0 = make_tuple(v1[1], v2[1], v3[1]);
	
	printTupleOfThree(t0);

	return 0;
}