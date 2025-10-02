#include <iostream>
#include <Windows.h>
using namespace std;


string privet1(string name)
{
   string str = name + ", " + "hello!\n";
   return str;
}

int Exercise2()
{
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   string name;
   cout << "What is your name?" << endl;
   cin >> name;
   string nameOut = privet1(name);
   cout << nameOut << endl;
    
   return 0;
}