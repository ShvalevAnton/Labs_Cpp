#include "Distance.h"

Distance Distance::operator+ (const Distance& d2) const
{
	int f = feet + d2.feet;
	float i = inches + d2.inches;
	if (i >= 12.0)
	{
		i -= 12.0;
		f++;
	}
	return Distance(f, i);
}

// Альтернативная реализация дружественной функции вычитания
Distance  Distance::operator-(const Distance& d2) const
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
      return Distance(0, 0);
   }

   return Distance(f, i);
}

std::ostream& operator<< (std::ostream& out, const Distance& dist)
{
   out << dist.feet << "\' - " << dist.inches << "\"\n";
   return out;
}