#include <iostream>
#include <windows.h>
#include <cmath>
#include <tuple>

using namespace std;

// ������� ��� ������� ����������� ��������� ax2 + bx + c = 0
// ���������� ������: (������1, ������2, ����_�������_������)
tuple<double, double, bool> solveQuadratic(double a, double b, double c) {
   // ���� a = 0, �� ��������� ��������
   if (a == 0) {
      if (b != 0) {
         double root = -c / b;
         return make_tuple(root, root, true);
      }
      else {
         return make_tuple(0, 0, false); // ��� �������
      }
   }

   // ��������� ������������
   double discriminant = b * b - 4 * a * c;

   if (discriminant > 0) {
      // ��� ��������� �������������� �����
      double root1 = (-b + sqrt(discriminant)) / (2 * a);
      double root2 = (-b - sqrt(discriminant)) / (2 * a);
      return make_tuple(root1, root2, true);
   }
   else if (discriminant == 0) {
      // ���� �������������� ������ (��� ����������)
      double root = -b / (2 * a);
      return make_tuple(root, root, true);
   }
   else {
      // �������������� ������ ���
      return make_tuple(0, 0, false);
   }
}

// ������� ��� ������ �����������
void printSolution(const tuple<double, double, bool>& solution) {
   double root1 = get<0>(solution);
   double root2 = get<1>(solution);
   bool hasRealRoots = get<2>(solution);

   if (!hasRealRoots) {
      cout << "��������� �� ����� �������������� ������" << endl;
   }
   else if (root1 == root2) {
      cout << "��������� ����� ���� ������: x = " << root1 << endl;
   }
   else {
      cout << "����� ���������: x1 = " << root1
         << ", x2 = " << root2 << endl;
   }
}


int ControlTask3()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
   double a, b, c;

   cout << "������� ����������� ��������� ax2 + bx + c = 0" << endl;
   cout << "������� ������������ a, b, c: ";
   cin >> a >> b >> c;

   // ������ ��������� � �������� ������
   auto solution = solveQuadratic(a, b, c);

   // ������� ����������
   cout << "\n���������:" << endl;
   printSolution(solution);

   return 0;
}