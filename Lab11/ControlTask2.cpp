#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

class Point {
private:
   double x, y;

public:
   //  онструктор с параметрами
   Point(double x_val = 0, double y_val = 0) : x(x_val), y(y_val) {}

   // ‘ункци€ расчета рассто€ни€ до центра координат
   double distanceToOrigin() const {
      return std::sqrt(x * x + y * y);
   }

   // ѕерегрузка оператора < дл€ сравнени€ по рассто€нию до центра координат
   bool operator<(const Point& other) const {
      return distanceToOrigin() < other.distanceToOrigin();
   }

   // ѕерегрузка оператора << дл€ вывода в поток
   friend std::ostream& operator<<(std::ostream& os, const Point& point);
};

// –еализаци€ оператора <<
std::ostream& operator<<(std::ostream& os, const Point& point) {
   os << "(" << point.x << ", " << point.y << ") - рассто€ние: " << point.distanceToOrigin();
   return os;
}

int ControlTask2()
{
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   std::vector<Point> v;
   v.push_back(Point(1, 2));
   v.push_back(Point(10, 12));
   v.push_back(Point(21, 7));
   v.push_back(Point(4, 8));

   std::sort(v.begin(), v.end()); // используетс€ перегруженный оператор <

   for (auto& point : v)
      std::cout << point << '\n'; // используетс€ перегруженный оператор <<

   return 0;
}