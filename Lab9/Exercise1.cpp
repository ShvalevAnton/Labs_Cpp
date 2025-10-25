#include <iostream>
#include <Windows.h>
#include "DivideByZeroError.h"
#include "Functions.h"

using namespace std;

int Exercise1()
{
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   cout << "Введите два целых числа для расчета их частного:\n"; 
   int number1, number2; 
   cin >> number1; 
   cin >> number2; 
   try { 
      float result = quotient(number1, number2); 
      cout << "Частное равно " << result << endl; 
   }
   catch (DivideByZeroError& error) 
   {
      cout << "ОШИБКА: "; 
      error.printMessage(); 
      return 1; // завершение программы при ошибке 
   }   
   return 0; // нормальное завершение программы
}