#include <iostream>
#include <concepts>
#include <Windows.h>

// Концепт Comparable требует наличия оператора <
template<typename T>
concept Comparable = requires(T a, T b) {
   { a < b } -> std::convertible_to<bool>;
};

// Шаблонная функция с ограничением Comparable
template<Comparable T>
const T& maxOfTwo(const T& a, const T& b) {
   return (a < b) ? b : a;
}

// Пользовательский класс для тестирования
class Person {
private:
   std::string name;
   int age;

public:
   Person(const std::string& n, int a) : name(n), age(a) {}

   // Оператор < для сравнения по возрасту
   bool operator<(const Person& other) const {
      return age < other.age;
   }

   // Метод для вывода информации
   friend std::ostream& operator<<(std::ostream& os, const Person& p) {
      os << p.name << " (" << p.age << " лет)";
      return os;
   }
};

int ControlTask3() 
{
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   // Тестирование с int
   int a = 5, b = 10;
   std::cout << "maxOfTwo(" << a << ", " << b << ") = "
      << maxOfTwo(a, b) << std::endl;

   // Тестирование с double
   double x = 3.14, y = 2.71;
   std::cout << "maxOfTwo(" << x << ", " << y << ") = "
      << maxOfTwo(x, y) << std::endl;

   // Тестирование с пользовательским классом
   Person person1("Анна", 25);
   Person person2("Иван", 30);
   std::cout << "maxOfTwo(" << person1 << ", " << person2 << ") = "
      << maxOfTwo(person1, person2) << std::endl;

   return 0;
}