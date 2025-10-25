#include <iostream>
#include <Windows.h>
#include "DivideByZeroError.h"
#include "Functions.h"

using namespace std;

int Exercise1()
{
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   cout << "������� ��� ����� ����� ��� ������� �� ��������:\n"; 
   int number1, number2; 
   cin >> number1; 
   cin >> number2; 
   try { 
      float result = quotient(number1, number2); 
      cout << "������� ����� " << result << endl; 
   }
   catch (DivideByZeroError& error) 
   {
      cout << "������: "; 
      error.printMessage(); 
      return 1; // ���������� ��������� ��� ������ 
   }   
   return 0; // ���������� ���������� ���������
}