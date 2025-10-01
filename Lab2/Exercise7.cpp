#include <iostream>
#include <Windows.h>
using namespace std;

int Exercise7()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	int k,m,s = 0;

	cout << "k = "; cin >> k;
	cout << "m = "; cin >> m;

	for (int i = 1; i <= 100; i++)
	{
		if ((i > k) && (i < m))
			continue;
		s += i;
	}
	
	cout << "s = " << s << endl;
	return 0;
}