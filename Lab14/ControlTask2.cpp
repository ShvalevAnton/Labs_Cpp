#include <iostream>
#include <vector>

template<typename Container>
void Print(const Container& container, const std::string& delimiter) {
   bool first = true;
   for (const auto& element : container) {
      if (!first) {
         std::cout << delimiter;
      }
      std::cout << element;
      first = false;
   }
   std::cout << "\n";
}

// Пример использования
int ControlTask2() {
   std::vector<int> data = { 1, 2, 3 };
   Print(data, ", "); // на экране: 1, 2, 3

   std::vector<std::string> words = { "Hello", "World", "C++" };
   Print(words, " | "); // на экране: Hello | World | C++

   return 0;
}