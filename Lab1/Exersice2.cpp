#include "Exercises.h"

#include <iostream>
#include <string>
using namespace std;

int Exercise2()
{
   system("chcp 1251");
   string name;
   cout << "Введите свое имя\n";
   double a, b; 
   cout << "Введите a и b:\n";
   cin >> a; // ввод с клавиатуры значения a
   cin >> name;


   cin >> b; // ввод с клавиатуры значения b
   double x = a / b; // вычисление значения x
   //int x = a / b; // вычисление значения x
   cout.precision(3);
   cout<< "\nx = " << x << endl; //вывод результата на экран
   cout << sizeof(a / b) << ends << " B, " << sizeof(x) << " B." << endl; // расчета объема занимаемой памяти в байтах
   cout << "Привет, " << name << "!\n";
   return 0;
}