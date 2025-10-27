#include <iostream>
#include <Windows.h>
#include <cmath>

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

   // Перегрузка оператора + для сложения двух объектов Time
   Time operator+(const Time& other) const {
      return add(other);
   }

   // Перегрузка оператора вычитания
   Time operator-(const Time& other) const {
      return Time(hours - other.hours,
         minutes - other.minutes,
         seconds - other.seconds);
   }

   // Перегрузка оператора сложения Time + double
   Time operator+(double hoursToAdd) const {
      int totalSeconds = hours * 3600 + minutes * 60 + seconds;
      totalSeconds += static_cast<int>(hoursToAdd * 3600);

      int h = totalSeconds / 3600;
      int m = (totalSeconds % 3600) / 60;
      int s = totalSeconds % 60;

      return Time(h, m, s);
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

   // Перегрузка операторов сравнения
   bool operator==(const Time& other) const {
      return hours == other.hours &&
         minutes == other.minutes &&
         seconds == other.seconds;
   }

   bool operator!=(const Time& other) const {
      return !(*this == other);
   }

   bool operator<(const Time& other) const {
      if (hours != other.hours) return hours < other.hours;
      if (minutes != other.minutes) return minutes < other.minutes;
      return seconds < other.seconds;
   }

   bool operator>(const Time& other) const {
      return other < *this;
   }

   bool operator<=(const Time& other) const {
      return !(other < *this);
   }

   bool operator>=(const Time& other) const {
      return !(*this < other);
   }

   // Метод для получения общего количества секунд (вспомогательный)
   int toSeconds() const {
      return hours * 3600 + minutes * 60 + seconds;
   }
};

// Перегрузка оператора сложения double + Time (глобальная функция)
Time operator+(double hoursToAdd, const Time& time) {
   return time + hoursToAdd;
}

int ControlTask1()
{
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   // Создаем два инициализированных объекта
   const Time time1(2, 45, 30);    // 2:45:30
   const Time time2(1, 70, 90);    // 1:70:90 будет преобразовано в 2:11:30

   // Создаем неинициализированный объект
   Time result;

   std::cout << "Время 1: ";
   time1.display();

   std::cout << "Время 2: ";
   time2.display();

   // Складываем два времени и присваиваем результат третьему объекту
   result = time1 + time2;
   std::cout << "Результат сложения (time1 + time2): ";
   result.display();

   // Вычитание объектов Time
   result = time1 - time2;
   std::cout << "Результат вычитания (time1 - time2): ";
   result.display();

   // Сложение объекта Time и переменной вещественного типа
   result = time1 + 1.5; // 1.5 часа = 1 час 30 минут
   std::cout << "Результат сложения (time1 + 1.5 часа): ";
   result.display();

   // Сложение переменной вещественного типа и объекта Time
   result = 0.75 + time2; // 0.75 часа = 45 минут
   std::cout << "Результат сложения (0.75 часа + time2): ";
   result.display();

   // Сравнение двух объектов Time
   std::cout << "\nСравнение времени:\n";
   std::cout << "time1 == time2: " << (time1 == time2 ? "true" : "false") << std::endl;
   std::cout << "time1 != time2: " << (time1 != time2 ? "true" : "false") << std::endl;
   std::cout << "time1 < time2: " << (time1 < time2 ? "true" : "false") << std::endl;
   std::cout << "time1 > time2: " << (time1 > time2 ? "true" : "false") << std::endl;
   std::cout << "time1 <= time2: " << (time1 <= time2 ? "true" : "false") << std::endl;
   std::cout << "time1 >= time2: " << (time1 >= time2 ? "true" : "false") << std::endl;

   // Демонстрация работы с некорректными значениями
   Time testTime(25, 70, 80);  // 25:70:80 будет преобразовано в 2:11:20
   std::cout << "\nТестовое время (25:70:80): ";
   testTime.display();

   return 0;
}
