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

// �������������� ���������� ������������� ������� ���������
Distance2  Distance2::operator-(const Distance2& d2) const
{
   int f = feet - d2.feet;
   float i = inches - d2.inches;

   // ���� ����� �������������, �������� 1 ���
   if (i < 0) {
      i += 12.0;
      f--;
   }
   // �������� �� ������������� ���������
   if (f < 0) {
      cout << "������: ��������� �� ����� ���� �������������!" << endl;
      return Distance2(0, 0);
   }

   return Distance2(f, i);
}

// ���������� ��� Distance2 + float
Distance2 operator+ (const Distance2& d, float meters)
{
   Distance2 temp(meters); // ������� ��������� ������ �� ������
   return d + temp; // ���������� ��� ������������ ��������+
}

// ���������� ��� float + Distance2
Distance2 operator+ (float meters, const Distance2& d)
{
   Distance2 temp(meters); // ������� ��������� ������ �� ������
   return temp + d; // ���������� ��� ������������ ��������+
}

// ���������� ��� Distance2 - float
Distance2 operator- (const Distance2& d, float meters)
{
   Distance2 temp(meters); // ������� ��������� ������ �� ������
   return d - temp; // ���������� ��� ������������ ��������-
}

// ���������� ��� float - Distance2
Distance2 operator- (float meters, const Distance2& d)
{
   Distance2 temp(meters); // ������� ��������� ������ �� ������
   return temp - d; // ���������� ��� ������������ ��������-
}

std::ostream& operator<< (std::ostream& out, const Distance2& dist)
{
   out << dist.feet << "\' - " << dist.inches << "\"\n";
   return out;
}