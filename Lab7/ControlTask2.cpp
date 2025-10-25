#include <iostream>
#include <windows.h>

using namespace std;

// Структура для хранения корней квадратного уравнения
struct QuadraticSolution {
   double root1;
   double root2;
   bool hasRealRoots; // Флаг для обозначения наличия действительных корней

   // Конструктор для удобной инициализации
   QuadraticSolution(double r1 = 0, double r2 = 0, bool hasRoots = true)
      : root1(r1), root2(r2), hasRealRoots(hasRoots) {
   }
};

// Функция для решения квадратного уравнения ax2 + bx + c = 0
QuadraticSolution solveQuadratic(double a, double b, double c) {
   QuadraticSolution solution;

   // Если a = 0, то уравнение линейное
   if (a == 0) {
      if (b != 0) {
         solution.root1 = -c / b;
         solution.root2 = solution.root1; // Один корень (для совместимости)
         solution.hasRealRoots = true;
      }
      else {
         solution.hasRealRoots = false; // Нет решений или бесконечно много
      }
      return solution;
   }

   // Вычисляем дискриминант
   double discriminant = b * b - 4 * a * c;

   if (discriminant > 0) {
      // Два различных действительных корня
      solution.root1 = (-b + sqrt(discriminant)) / (2 * a);
      solution.root2 = (-b - sqrt(discriminant)) / (2 * a);
      solution.hasRealRoots = true;
   }
   else if (discriminant == 0) {
      // Один действительный корень (два одинаковых)
      solution.root1 = -b / (2 * a);
      solution.root2 = solution.root1;
      solution.hasRealRoots = true;
   }
   else {
      // Действительных корней нет
      solution.hasRealRoots = false;
   }

   return solution;
}

// Функция для вывода результатов
void printSolution(const QuadraticSolution& solution) {
   if (!solution.hasRealRoots) {
      std::cout << "Уравнение не имеет действительных корней" << std::endl;
   }
   else if (solution.root1 == solution.root2) {
      std::cout << "Уравнение имеет один корень: x = " << solution.root1 << std::endl;
   }
   else {
      std::cout << "Корни уравнения: x1 = " << solution.root1
         << ", x2 = " << solution.root2 << std::endl;
   }
}


int ControlTask2()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

   double a, b, c;

   std::cout << "Решение квадратного уравнения ax2 + bx + c = 0" << std::endl;
   std::cout << "Введите коэффициенты a, b, c: ";
   std::cin >> a >> b >> c;

   // Решаем уравнение
   QuadraticSolution solution = solveQuadratic(a, b, c);

   // Выводим результаты
   std::cout << "\nРезультат:" << std::endl;
   printSolution(solution);

	return 0;
}