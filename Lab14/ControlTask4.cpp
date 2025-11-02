#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>
#include <complex>
#include <concepts>
#include <iterator>

// 1. Создание concept Sortable
template<typename T>
concept Sortable = requires(T a, T b) {
   { a < b } -> std::convertible_to<bool>;
   { a > b } -> std::convertible_to<bool>;
};

// 2. Шаблон функции is_sorted с использованием concept
template<typename Iterator>
   requires Sortable<typename std::iterator_traits<Iterator>::value_type>
bool is_sorted(Iterator first, Iterator last) {
   if (first == last) return true; // пустой контейнер считается отсортированным

   Iterator next = first;
   ++next;

   while (next != last) {
      if (*next < *first) { // проверяем порядок по возрастанию
         return false;
      }
      ++first;
      ++next;
   }

   return true;
}

// Перегрузка для удобства работы с контейнерами
template<typename Container>
   requires Sortable<typename Container::value_type>
bool is_sorted(const Container& container) {
   return is_sorted(std::begin(container), std::end(container));
}

// Функция для демонстрации результатов
template<typename Container>
void test_sorting(const Container& container, const std::string& type_name) {
   std::cout << "Контейнер " << type_name << ": ";
   std::cout << (is_sorted(container) ? "отсортирован" : "НЕ отсортирован") << std::endl;
}

int ControlTask4() 
{
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   // 3. Тестирование на различных типах

   // std::vector<int>
   std::vector<int> sorted_int = { 1, 2, 3, 4, 5 };
   std::vector<int> unsorted_int = { 5, 2, 3, 1, 4 };

   std::cout << "=== Тестирование функции is_sorted ===" << std::endl;

   test_sorting(sorted_int, "vector<int> (отсортированный)");
   test_sorting(unsorted_int, "vector<int> (неотсортированный)");

   // std::vector<std::string>
   std::vector<std::string> sorted_str = { "apple", "banana", "cherry" };
   std::vector<std::string> unsorted_str = { "cherry", "apple", "banana" };

   test_sorting(sorted_str, "vector<string> (отсортированный)");
   test_sorting(unsorted_str, "vector<string> (неотсортированный)");

   // Попытка использования с std::vector<std::complex<double>>
   std::vector<std::complex<double>> complex_vec = { {1.0, 2.0}, {3.0, 4.0} };

   std::cout << "\n=== Попытка использования с неподдерживаемым типом ===" << std::endl;

   // Этот код не скомпилируется из-за проверки concept
   // Раскомментируйте для проверки ошибки компиляции:
   /*
   test_sorting(complex_vec, "vector<complex<double>>");
   */

   // Вместо этого покажем сообщение:
   std::cout << "Попытка использовать is_sorted с vector<complex<double>> приведет к ошибке компиляции" << std::endl;
   std::cout << "т.к. std::complex<double> не поддерживает операции < и >" << std::endl;

   return 0;
}