#include <iostream>
#include <Windows.h>

using namespace std;

// Структура Time
struct Time {
   int hours;
   int minutes;
   int seconds;

   // Конструктор для инициализации
   Time(int h = 0, int m = 0, int s = 0) {
      setTime(h, m, s);
   }

   // Функция для установки времени с проверкой корректности
   void setTime(int h, int m, int s) {
      if (h < 0 || h > 23 || m < 0 || m > 59 || s < 0 || s > 59) {
         throw invalid_argument("Некорректное значение времени!");
      }
      hours = h;
      minutes = m;
      seconds = s;
   }

   // Функция для получения общего количества секунд
   int toSeconds() const {
      return hours * 3600 + minutes * 60 + seconds;
   }

   // Функция для нормализации времени (приведение к корректному формату)
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
         minutes -= 1;
         seconds += 60;
      }
      if (minutes < 0) {
         hours -= 1;
         minutes += 60;
      }
      if (hours < 0) {
         hours += 24;
      }
   }

   // Функция сложения интервалов времени
   Time add(const Time& other) const {
      Time result;
      result.hours = hours + other.hours;
      result.minutes = minutes + other.minutes;
      result.seconds = seconds + other.seconds;
      result.normalize();
      return result;
   }

   // Функция вычитания интервалов времени
   Time subtract(const Time& other) const {
      Time result;
      result.hours = hours - other.hours;
      result.minutes = minutes - other.minutes;
      result.seconds = seconds - other.seconds;
      result.normalize();
      return result;
   }

   // Функция для вывода времени в формате HH:MM:SS
   void display() const {
      cout << (hours < 10 ? "0" : "") << hours << ":"
         << (minutes < 10 ? "0" : "") << minutes << ":"
         << (seconds < 10 ? "0" : "") << seconds;
   }
};

int ControlTask1()
{
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   try {
      Time t1, t2;
      int h, m, s;

      cout << "=== Ввод первого времени ===" << endl;
      cout << "Введите часы: ";
      cin >> h;
      cout << "Введите минуты: ";
      cin >> m;
      cout << "Введите секунды: ";
      cin >> s;

      t1.setTime(h, m, s);

      cout << "\n=== Ввод второго времени ===" << endl;
      cout << "Введите часы: ";
      cin >> h;
      cout << "Введите минуты: ";
      cin >> m;
      cout << "Введите секунды: ";
      cin >> s;

      t2.setTime(h, m, s);

      // Вывод введенных времен
      cout << "\n=== Результаты ===" << endl;
      cout << "Первое время: ";
      t1.display();
      cout << " (" << t1.toSeconds() << " секунд)" << endl;

      cout << "Второе время: ";
      t2.display();
      cout << " (" << t2.toSeconds() << " секунд)" << endl;

      // Сложение времен
      Time sum = t1.add(t2);
      cout << "Сумма: ";
      sum.display();
      cout << " (" << sum.toSeconds() << " секунд)" << endl;

      // Вычитание времен
      Time diff = t1.subtract(t2);
      cout << "Разность (t1 - t2): ";
      diff.display();
      cout << " (" << diff.toSeconds() << " секунд)" << endl;

   }
   catch (const invalid_argument& e) {
      cout << "Ошибка: " << e.what() << endl;
      return 1;
   }

   return 0;
}