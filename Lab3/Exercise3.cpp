#include <iostream>
#include <Windows.h>
using namespace std;

void privet3(string name, int k)
{
   cout << name << ", " << "hello! " << "you input " << k << endl;
}

string privet3(string name)
{
   string str = name + ", " + "hello!\n";
   return str;
}

int Exercise3()
{
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   string name;
   int k;

   cout << "What is your name?" << endl; cin >> name;
   cout << "Input number:" << endl; cin >> k;

   privet3(name);
   privet3(name, k);

   string nameOut = privet3(name);
   cout << nameOut << endl;

   return 0;
}