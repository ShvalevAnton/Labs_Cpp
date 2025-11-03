#include <iostream>
#include <Windows.h>
#include <vector>
#include <algorithm>
#include <stdexcept>

int FindMaxEven(const std::vector<int>& numbers) {
   // Создаем копию вектора для фильтрации чётных чисел
   std::vector<int> even_numbers;

   // Копируем только чётные числа в новый вектор
   std::copy_if(numbers.begin(), numbers.end(),
      std::back_inserter(even_numbers),
      [](int n) { return n % 2 == 0; });

   // Если чётных чисел нет, бросаем исключение
   if (even_numbers.empty()) {
      throw std::runtime_error("Не найдено чётных чисел в векторе");
   }

   // Находим максимальный элемент среди чётных чисел
   return *std::max_element(even_numbers.begin(), even_numbers.end());
}

int ControlTask2() 
{
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   try {
      std::vector<int> vec1 = { 1, 3, 5, 8, 2, 9, 4 };
      std::cout << "Максимальное чётное число: " << FindMaxEven(vec1) << std::endl; // 8

      std::vector<int> vec2 = { 1, 3, 5, 7 };
      std::cout << "Максимальное чётное число: " << FindMaxEven(vec2) << std::endl; // исключение
   }
   catch (const std::runtime_error& e) {
      std::cout << "Ошибка: " << e.what() << std::endl;
   }

   return 0;
}