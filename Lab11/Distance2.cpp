#include "Distance2.h"

Distance2 Distance2::operator+ (const Distance2& d2) const
{
   int f = feet + d2.feet;
   float i = inches + d2.inches;
   if (i >= 12.0)
   {
      i -= 12.0;
      f++;
   }
   return Distance2(f, i);
}

// Альтернативная реализация дружественной функции вычитания
Distance2  Distance2::operator-(const Distance2& d2) const
{
   int f = feet - d2.feet;
   float i = inches - d2.inches;

   // Если дюймы отрицательные, занимаем 1 фут
   if (i < 0) {
      i += 12.0;
      f--;
   }
   // Проверка на отрицательный результат
   if (f < 0) {
      cout << "Ошибка: результат не может быть отрицательным!" << endl;
      return Distance2(0, 0);
   }

   return Distance2(f, i);
}

// Перегрузка для Distance2 + float
Distance2 operator+ (const Distance2& d, float meters)
{
   Distance2 temp(meters); // Создаем временный объект из метров
   return d + temp; // Используем уже существующий оператор+
}

// Перегрузка для float + Distance2
Distance2 operator+ (float meters, const Distance2& d)
{
   Distance2 temp(meters); // Создаем временный объект из метров
   return temp + d; // Используем уже существующий оператор+
}

// Перегрузка для Distance2 - float
Distance2 operator- (const Distance2& d, float meters)
{
   Distance2 temp(meters); // Создаем временный объект из метров
   return d - temp; // Используем уже существующий оператор-
}

// Перегрузка для float - Distance2
Distance2 operator- (float meters, const Distance2& d)
{
   Distance2 temp(meters); // Создаем временный объект из метров
   return temp - d; // Используем уже существующий оператор-
}

std::ostream& operator<< (std::ostream& out, const Distance2& dist)
{
   out << dist.feet << "\' - " << dist.inches << "\"\n";
   return out;
}