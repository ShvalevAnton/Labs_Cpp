#include <iostream>
#include <Windows.h>
// Подключение .h с функциями из разных файлом
#include "utils.h"   
// Подключение .h с функциями из одного файлом
#include "math_functions.h"   

int main() {

   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   int result = addNumbers(5, 7);
   std::cout << "Результат сложения: " << result << std::endl;

   std::cout << add(3, 4) << std::endl;       // вызов из math.cpp
   std::cout << multiply(3, 4) << std::endl;  // вызов из operations.cpp

   return 0;
}