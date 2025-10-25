#include <iostream>
#include <Windows.h>

using namespace std;

// ��������� Time
struct Time {
   int hours;
   int minutes;
   int seconds;

   // ����������� ��� �������������
   Time(int h = 0, int m = 0, int s = 0) {
      setTime(h, m, s);
   }

   // ������� ��� ��������� ������� � ��������� ������������
   void setTime(int h, int m, int s) {
      if (h < 0 || h > 23 || m < 0 || m > 59 || s < 0 || s > 59) {
         throw invalid_argument("������������ �������� �������!");
      }
      hours = h;
      minutes = m;
      seconds = s;
   }

   // ������� ��� ��������� ������ ���������� ������
   int toSeconds() const {
      return hours * 3600 + minutes * 60 + seconds;
   }

   // ������� ��� ������������ ������� (���������� � ����������� �������)
   void normalize() {
      if (seconds >= 60) {
         minutes += seconds / 60;
         seconds %= 60;
      }
      if (minutes >= 60) {
         hours += minutes / 60;
         minutes %= 60;
      }
      if (hours >= 24) {
         hours %= 24;
      }

      // ��������� ������������� ��������
      if (seconds < 0) {
         minutes -= 1;
         seconds += 60;
      }
      if (minutes < 0) {
         hours -= 1;
         minutes += 60;
      }
      if (hours < 0) {
         hours += 24;
      }
   }

   // ������� �������� ���������� �������
   Time add(const Time& other) const {
      Time result;
      result.hours = hours + other.hours;
      result.minutes = minutes + other.minutes;
      result.seconds = seconds + other.seconds;
      result.normalize();
      return result;
   }

   // ������� ��������� ���������� �������
   Time subtract(const Time& other) const {
      Time result;
      result.hours = hours - other.hours;
      result.minutes = minutes - other.minutes;
      result.seconds = seconds - other.seconds;
      result.normalize();
      return result;
   }

   // ������� ��� ������ ������� � ������� HH:MM:SS
   void display() const {
      cout << (hours < 10 ? "0" : "") << hours << ":"
         << (minutes < 10 ? "0" : "") << minutes << ":"
         << (seconds < 10 ? "0" : "") << seconds;
   }
};

int ControlTask1()
{
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   try {
      Time t1, t2;
      int h, m, s;

      cout << "=== ���� ������� ������� ===" << endl;
      cout << "������� ����: ";
      cin >> h;
      cout << "������� ������: ";
      cin >> m;
      cout << "������� �������: ";
      cin >> s;

      t1.setTime(h, m, s);

      cout << "\n=== ���� ������� ������� ===" << endl;
      cout << "������� ����: ";
      cin >> h;
      cout << "������� ������: ";
      cin >> m;
      cout << "������� �������: ";
      cin >> s;

      t2.setTime(h, m, s);

      // ����� ��������� ������
      cout << "\n=== ���������� ===" << endl;
      cout << "������ �����: ";
      t1.display();
      cout << " (" << t1.toSeconds() << " ������)" << endl;

      cout << "������ �����: ";
      t2.display();
      cout << " (" << t2.toSeconds() << " ������)" << endl;

      // �������� ������
      Time sum = t1.add(t2);
      cout << "�����: ";
      sum.display();
      cout << " (" << sum.toSeconds() << " ������)" << endl;

      // ��������� ������
      Time diff = t1.subtract(t2);
      cout << "�������� (t1 - t2): ";
      diff.display();
      cout << " (" << diff.toSeconds() << " ������)" << endl;

   }
   catch (const invalid_argument& e) {
      cout << "������: " << e.what() << endl;
      return 1;
   }

   return 0;
}