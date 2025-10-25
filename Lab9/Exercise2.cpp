#include <iostream>
#include <Windows.h>
#include "DivideByZeroError.h"
#include "Functions.h"

using namespace std;

int Exercise2()
{
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   cout << "Введите число:\n";
   int number1;
   cin >> number1;
   for (int i = -10; i < 10; i++) 
   { 
      try 
      {
         float result = quotient(number1, i); 
         cout << "Частное равно " << result << endl; 
      } 
      catch (DivideByZeroError& error) 
      { 
         cout << "ОШИБКА: "; 
         error.printMessage(); 
      } 
   }
   return 0; 
}