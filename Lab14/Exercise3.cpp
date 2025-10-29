#include <iostream>
#include <Windows.h>
#include "functions.h"
#include <string>
#include <tuple>
#include <vector>

using namespace std;

int Exercise3()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	vector<string> v1{ "one", "two", "three", "four", "five", "six" };
	vector<int> v2 = { 1, 2, 3, 4, 5, 6 };
	vector<float> v3 = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6 };
	auto t1 = std::make_tuple(v1[0], v1[1], v3[0]);
	auto t2 = std::make_tuple(v1[0], v1[1], v2[1], v3[0], v3[1]);
	printTuple(t1);
	printTuple(t2);
	return 0;

	return 0;
}