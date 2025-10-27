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

std::ostream& operator<< (std::ostream& out, const Distance2& dist)
{
   out << dist.feet << "\' - " << dist.inches << "\"\n";
   return out;
}