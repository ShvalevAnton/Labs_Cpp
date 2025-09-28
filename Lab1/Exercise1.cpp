#include "Exercises.h"

#include <iostream>
#include <string>
using namespace std;

int Exercise1()
{
   string name;
   cout << "What is your name? ";
   //cin >> name;
   getline(cin, name);
   cout << "Hello, " << name << "!\n";
   return 0;
}