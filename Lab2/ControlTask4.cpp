#include <iostream>
#include <Windows.h>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

int ControlTask4()
{
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   // ������������� ���������� ��������� �����
   srand(static_cast<unsigned int>(time(0)));

   // ���������� ��������� ����� ������ � �������� [-5, 5] ��� ��������
   double target_x = (rand() % 11 - 5) + static_cast<double>(rand()) / RAND_MAX;
   double target_y = (rand() % 11 - 5) + static_cast<double>(rand()) / RAND_MAX;

   cout << "������ ��������! ��������� �������!" << endl;
   cout << "����� ������: (" << fixed << setprecision(2) << target_x << ", " << target_y << ")" << endl;
   cout << "�� �� �� ������ ����� ���! �����!" << endl << endl;

   const int TARGET_SCORE = 30;
   int total_score = 0;
   int shots = 0;

   cout << "������� ���������� �������� (x y). �������� " << TARGET_SCORE << " �����!" << endl;

   while (total_score < TARGET_SCORE) {
      double x, y;
      cout << "������� #" << shots + 1 << ": ";
      cin >> x >> y;

      // ��������� ��������� ������ (��������, �� -0.5 �� +0.5)
      double noise_x = (static_cast<double>(rand()) / RAND_MAX - 0.5) * 1.0; // �0.5
      double noise_y = (static_cast<double>(rand()) / RAND_MAX - 0.5) * 1.0; // �0.5

      double actual_x = x + noise_x;
      double actual_y = y + noise_y;

      cout << "������! ����������� �������: (" << fixed << setprecision(2)
         << actual_x << ", " << actual_y << ")" << endl;

      // ���������� �� ����������� ����� �� ������ ������
      double distance = sqrt((actual_x - target_x) * (actual_x - target_x) +
         (actual_y - target_y) * (actual_y - target_y));

      int score = 0;
      if (distance <= 1.0) {
         score = 10;
         cout << "��������� � �����! +10 ������!" << endl;
      }
      else if (distance <= 2.0) {
         score = 5;
         cout << "��������� � ������! +5 ������!" << endl;
      }
      else {
         cout << "����! 0 ������." << endl;
      }

      total_score += score;
      shots++;

      cout << "������� ����: " << total_score << " / " << TARGET_SCORE << endl << endl;
   }

   // ����� ����������
   cout << "�����������!�� ������� " << total_score << " ����� �� " << shots << " ���������!" << endl;

   // ����������� ������ �������
   string level;
   if (shots <= 5) {
      level = "�������";
   }
   else if (shots <= 10) {
      level = "������� �������";
   }
   else if (shots <= 15) {
      level = "�������";
   }
   else {
      level = "�������";
   }

   cout << "��� �������: " << level << endl;

   return 0;
}

