#include <iostream>
#include <Windows.h>
using namespace std;

bool Input(int& a, int& b) {
   // Проверка на число 
   if (!(cin >> a)) {
      return false;
   }

   // Проверка на число
   if (!(cin >> b)) {
      return false;
   }

   return true;
}

int ControlTask2()
{
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   int a, b;
   if (!Input(a, b)) {
      cerr << "error";
      return 1;
   }
   int s = a + b;

   return 0;
}

