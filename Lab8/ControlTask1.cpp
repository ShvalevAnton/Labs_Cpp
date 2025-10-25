#include <iostream>
#include <Windows.h>


class Time {
private:
   int hours;
   int minutes;
   int seconds;

   // Вспомогательная функция для нормализации времени
   void normalize() {
      if (seconds >= 60) {
         minutes += seconds / 60;
         seconds %= 60;
      }
      if (minutes >= 60) {
         hours += minutes / 60;
         minutes %= 60;
      }
      if (hours >= 24) {
         hours %= 24;
      }

      // Обработка отрицательных значений
      if (seconds < 0) {
         minutes -= 1 + (-seconds) / 60;
         seconds = 60 - (-seconds) % 60;
      }
      if (minutes < 0) {
         hours -= 1 + (-minutes) / 60;
         minutes = 60 - (-minutes) % 60;
      }
      if (hours < 0) {
         hours = 24 - (-hours) % 24;
      }
   }

public:
   // Конструктор по умолчанию с списком инициализации
   Time() : hours(0), minutes(0), seconds(0) {}

   // Конструктор с параметрами
   Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
      normalize();
   }

   // Функция для вывода времени
   void display() const {
      std::cout << (hours < 10 ? "0" : "") << hours << ":"
         << (minutes < 10 ? "0" : "") << minutes << ":"
         << (seconds < 10 ? "0" : "") << seconds << std::endl;
   }

   // Функция сложения двух объектов Time
   Time add(const Time& other) const {
      return Time(hours + other.hours,
         minutes + other.minutes,
         seconds + other.seconds);
   }

   // Перегрузка оператора + для более удобного использования
   Time operator+(const Time& other) const {
      return add(other);
   }

   // Перегрузка оператора присваивания
   Time& operator=(const Time& other) {
      if (this != &other) {
         hours = other.hours;
         minutes = other.minutes;
         seconds = other.seconds;
      }
      return *this;
   }
};

int ControlTask1() 
{
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   // Создаем два инициализированных объекта (константные, так как их значения не меняются)
   const Time time1(2, 45, 30);    // 2:45:30
   const Time time2(1, 70, 90);    // 1:70:90 будет преобразовано в 2:11:30

   // Создаем неинициализированный объект
   Time result;

   std::cout << "Время 1: ";
   time1.display();

   std::cout << "Время 2: ";
   time2.display();

   // Складываем два времени и присваиваем результат третьему объекту
   result = time1.add(time2);

   std::cout << "Результат сложения: ";
   result.display();

   // Демонстрация работы с некорректными значениями
   Time testTime(25, 70, 80);  // 25:70:80 будет преобразовано в 2:11:20
   std::cout << "Тестовое время (25:70:80): ";
   testTime.display();

   return 0;
}