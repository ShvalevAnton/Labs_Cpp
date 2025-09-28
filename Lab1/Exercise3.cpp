//#include "Exercises.h"

#include <Windows.h>
#include <fmt/core.h>
#include <string>
#include <numbers>
#include <chrono>

#include <iostream>
using namespace std;

int Exercise3()
{
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   int x = 42;
   std::string name = "Alice";
   // Печать с форматированием
   fmt::print("Hello, {}, the answer is {}!\n", name, x);
   int num = 9;

   // шестнадцатеричное с префиксом 0x
   fmt::print("Hex: {:#x}\n", num);

   // Управление шириной и выравниванием
   fmt::print("|{:>10}|\n", 42); // выравнивание вправо
   fmt::print("|{:<10}|\n", 42); // выравнивание влево
   fmt::print("|{:^10}|\n", 42); // выравнивание по центру
  
  
   // Форматирование с плавающей точкой
   fmt::print("Fixed: {:.2f}\n", std::numbers::pi); // 2 знака после запятой
   fmt::print("Scientific: {:.3e}\n", std::numbers::pi); // экспоненциальный формат
  
   //Использование с std::string(форматирование без вывода)
   std::string s = fmt::format("Pi ≈ {:.3f}", 3.14159);
   fmt::print("{}\n", s);

   // Самостоятельное задание
   fmt::print("Самостоятельное задание\n");
   // Десятичное
   fmt::print("Dec: {}\n", num);
   // шестнадцатеричное с префиксом 0x
   fmt::print("Hex: 0x{:x}\n", num);
   // шестнадцатеричное с префиксом 0x
   fmt::print("Bin: 0b{:b}\n", num);

   //Строку с числом в трёх форматах (по умолчанию,с 2 знаками после запятой,в экспоненциальной форме).
   s = fmt::format("Default: {} | Fixed: {:.2f} | Sci: {:.3e}", 3.14159, 3.14159, 3.14159);
   fmt::print("{}\n", s);
   
   auto now = std::chrono::system_clock::now();
   cout << now << " [INFO] Application started\n";
   //fmt::print("{}\n", now);

    
   
   return 0;
}