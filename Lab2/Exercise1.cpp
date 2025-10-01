#include <iostream>
#include <Windows.h>
using namespace std;

int Exercise1() 
{
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   double x, y;

   cout << "Введите координаты точки (x y): ";
   cin >> x >> y;

   if (x * x + y * y < 9 && y > 0) {
      cout << "внутри" << endl;
   }
   else if (x * x + y * y > 9 || y < 0) {
      cout << "снаружи" << endl;
   }
   else { // x * x + y * y == 9 && y >= 0
      cout << "на границе" << endl;
   }
	return 0;
}

