#include <iostream>
#include <Windows.h>
#include <math.h>
using namespace std;

int Exercise3()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	double x, x1, x2, y;
	cout << "x1 = "; cin >> x1;
	cout << "x2 = "; cin >> x2;

	cout << "\tx\tsin(x)\n";
	x = x1;
	do
	{
		y = sin(x);
		cout << "\t" << x << "\t" << y << endl;
		x = x + 0.01;
	} while (x <= x2);

	return 0;
}