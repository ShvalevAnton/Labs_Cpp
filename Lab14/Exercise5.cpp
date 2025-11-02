#include <iostream>
#include <Windows.h>
#include "functions.h"
#include <concepts>
using namespace std;

template <std::integral T>
T Factorial(T n) {
	if (n <= 1) return 1;
	return n * Factorial(n - 1);
}


int Exercise5()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	// Вызовы функции Factorial с разными типами
	cout << "Факториал 5 (int): " << Factorial(5) << endl;
	cout << "Факториал 6 (long): " << Factorial(6L) << endl;
	cout << "Факториал 7 (short): " << Factorial(static_cast<short>(7)) << endl;


	return 0;
}