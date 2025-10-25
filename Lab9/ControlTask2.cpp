#include <iostream>
#include <Windows.h>
#include <stdexcept>
#include <string>


   class Time {
   private:
      int hours;
      int minutes;
      int seconds;

      void validateTime(int h, int m, int s) const {
         if (h < 0 || h > 23) throw std::invalid_argument("Часы должны быть 0-23");
         if (m < 0 || m > 59) throw std::invalid_argument("Минуты должны быть 0-59");
         if (s < 0 || s > 59) throw std::invalid_argument("Секунды должны быть 0-59");
      }

      // Вспомогательная функция для нормализации времени (теперь приватная)
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
            if (seconds == 60) seconds = 0;
         }
         if (minutes < 0) {
            hours -= 1 + (-minutes) / 60;
            minutes = 60 - (-minutes) % 60;
            if (minutes == 60) minutes = 0;
         }
         if (hours < 0) {
            hours = 24 - (-hours) % 24;
            if (hours == 24) hours = 0;
         }
      }

   public:
      // Конструкторы
      Time() : hours(0), minutes(0), seconds(0) {}

      Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
         normalize();
         validateTime(hours, minutes, seconds);
      }

      // Основные методы
      void display() const {
         std::cout << (hours < 10 ? "0" : "") << hours << ":"
            << (minutes < 10 ? "0" : "") << minutes << ":"
            << (seconds < 10 ? "0" : "") << seconds << std::endl;
      }

      // Cложение
      Time add(const Time& other) const {
         int totalSeconds = seconds + other.seconds;
         int totalMinutes = minutes + other.minutes + totalSeconds / 60;
         int totalHours = hours + other.hours + totalMinutes / 60;

         return Time(totalHours, totalMinutes % 60, totalSeconds % 60);
      }

      // Cравнение
      bool equals(const Time& other) const {
         return hours == other.hours &&
            minutes == other.minutes &&
            seconds == other.seconds;
      }

      bool isBefore(const Time& other) const {
         if (hours != other.hours) return hours < other.hours;
         if (minutes != other.minutes) return minutes < other.minutes;
         return seconds < other.seconds;
      }

      // Геттеры
      int getHours() const { return hours; }
      int getMinutes() const { return minutes; }
      int getSeconds() const { return seconds; }
   };

   int ControlTask2() 
   {
      SetConsoleOutputCP(1251);
      SetConsoleCP(1251);

      try 
      {
         const Time time1(2, 45, 30);
         const Time time2(1, 70, 90);  // Будет нормализовано до 2:11:30

         Time result;

         std::cout << "Время 1: ";
         time1.display();

         std::cout << "Время 2: ";
         time2.display();

         result = time1.add(time2);

         std::cout << "Результат сложения: ";
         result.display();

      }
      catch (const std::exception& e) {
         std::cerr << "Ошибка: " << e.what() << std::endl;
      }

      return 0;
   }