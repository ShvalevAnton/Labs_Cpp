#include <iostream>
#include <windows.h>
#include <cmath>
#include <tuple>

using namespace std;

// Функция для решения квадратного уравнения ax2 + bx + c = 0
// Возвращает кортеж: (корень1, корень2, флаг_наличия_корней)
tuple<double, double, bool> solveQuadratic(double a, double b, double c) {
   // Если a = 0, то уравнение линейное
   if (a == 0) {
      if (b != 0) {
         double root = -c / b;
         return make_tuple(root, root, true);
      }
      else {
         return make_tuple(0, 0, false); // Нет решений
      }
   }

   // Вычисляем дискриминант
   double discriminant = b * b - 4 * a * c;

   if (discriminant > 0) {
      // Два различных действительных корня
      double root1 = (-b + sqrt(discriminant)) / (2 * a);
      double root2 = (-b - sqrt(discriminant)) / (2 * a);
      return make_tuple(root1, root2, true);
   }
   else if (discriminant == 0) {
      // Один действительный корень (два одинаковых)
      double root = -b / (2 * a);
      return make_tuple(root, root, true);
   }
   else {
      // Действительных корней нет
      return make_tuple(0, 0, false);
   }
}

// Функция для вывода результатов
void printSolution(const tuple<double, double, bool>& solution) {
   double root1 = get<0>(solution);
   double root2 = get<1>(solution);
   bool hasRealRoots = get<2>(solution);

   if (!hasRealRoots) {
      cout << "Уравнение не имеет действительных корней" << endl;
   }
   else if (root1 == root2) {
      cout << "Уравнение имеет один корень: x = " << root1 << endl;
   }
   else {
      cout << "Корни уравнения: x1 = " << root1
         << ", x2 = " << root2 << endl;
   }
}


int ControlTask3()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
   double a, b, c;

   cout << "Решение квадратного уравнения ax2 + bx + c = 0" << endl;
   cout << "Введите коэффициенты a, b, c: ";
   cin >> a >> b >> c;

   // Решаем уравнение и получаем кортеж
   auto solution = solveQuadratic(a, b, c);

   // Выводим результаты
   cout << "\nРезультат:" << endl;
   printSolution(solution);

   return 0;
}