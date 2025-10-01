#include <iostream>
#include <Windows.h>

using namespace std;

int Exercise4()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int a, b, temp;

	cout << "a = "; cin >> a;
	cout << "b = "; cin >> b;

	while (a != b)
	{
		if (a > b)
			a -= b; // аналогично выражению a = a - b
		else
			b -= a;
	}
	cout << "НОД = " << a << endl;

	return 0;
}