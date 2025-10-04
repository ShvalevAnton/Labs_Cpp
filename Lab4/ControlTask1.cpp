#include <iostream>
#include <cmath>
#include <Windows.h>
using namespace std;

// Функция вычисления корней квадратного уравнения
// Возвращает:
//   1 — два различных действительных корня,
//   0 — один корень (дискриминант = 0),
//  -1 — нет действительных корней (дискриминант < 0)
int Myroot(double a, double b, double c, double& x1, double& x2) {
   // Проверка, действительно ли уравнение квадратное
   if (a == 0.0) {
      // Уравнение вырождается в линейное: bx + c = 0
      if (b == 0.0) {
         // Уравнение не имеет смысла (0 = c)
         if (c == 0.0) {
            // 0 = 0 — бесконечно много решений, но по условию задачи
            // требуется работать с квадратным уравнением,
            // поэтому считаем, что корней нет
            return -1;
         }
         else {
            return -1; // нет решений
         }
      }
      else {
         // Линейное уравнение: один корень
         x1 = x2 = -c / b;
         return 0; // формально один корень
      }
   }

   double D = b * b - 4 * a * c; // дискриминант

   if (D < 0) {
      return -1; // действительных корней нет
   }
   else if (D == 0) {
      x1 = x2 = -b / (2 * a);
      return 0; // один корень (кратный)
   }
   else {
      double sqrtD = std::sqrt(D);
      x1 = (-b + sqrtD) / (2 * a);
      x2 = (-b - sqrtD) / (2 * a);
      return 1; // два различных корня
   }
}


int ControlTask1()
{
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   double a, b, c;
   double x1, x2;

   std::cout << "Введите коэффициенты a, b, c квадратного уравнения ax^2 + bx + c = 0:\n";
   std::cin >> a >> b >> c;

   int result = Myroot(a, b, c, x1, x2);

   switch (result) {
   case -1:
      std::cout << "Корней уравнения нет\n";
      break;
   case 0:
      std::cout << "Корень уравнения один x1 = x2 = " << x1 << "\n";
      break;
   case 1:
      std::cout << "Корни уравнения x1 = " << x1 << ", x2 = " << x2 << "\n";
      break;
   default:
      std::cout << "Неизвестная ошибка\n";
      break;
   }

   return 0;
}

