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
   // ����������� � �����������
   Point(double x_val = 0, double y_val = 0) : x(x_val), y(y_val) {}

   // ������� ������� ���������� �� ������ ���������
   double distanceToOrigin() const {
      return std::sqrt(x * x + y * y);
   }

   // ���������� ��������� < ��� ��������� �� ���������� �� ������ ���������
   bool operator<(const Point& other) const {
      return distanceToOrigin() < other.distanceToOrigin();
   }

   // ���������� ��������� << ��� ������ � �����
   friend std::ostream& operator<<(std::ostream& os, const Point& point);
};

// ���������� ��������� <<
std::ostream& operator<<(std::ostream& os, const Point& point) {
   os << "(" << point.x << ", " << point.y << ") - ����������: " << point.distanceToOrigin();
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

   std::sort(v.begin(), v.end()); // ������������ ������������� �������� <

   for (auto& point : v)
      std::cout << point << '\n'; // ������������ ������������� �������� <<

   return 0;
}