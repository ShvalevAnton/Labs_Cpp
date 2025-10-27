#include <iostream>
#include <Windows.h>
#include <cmath>

class Time {
private:
   int hours;
   int minutes;
   int seconds;

   // ��������������� ������� ��� ������������ �������
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
         minutes -= 1 + (-seconds) / 60;
         seconds = 60 - (-seconds) % 60;
      }
      if (minutes < 0) {
         hours -= 1 + (-minutes) / 60;
         minutes = 60 - (-minutes) % 60;
      }
      if (hours < 0) {
         hours = 24 - (-hours) % 24;
      }
   }

public:
   // ����������� �� ��������� � ������� �������������
   Time() : hours(0), minutes(0), seconds(0) {}

   // ����������� � �����������
   Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
      normalize();
   }

   // ������� ��� ������ �������
   void display() const {
      std::cout << (hours < 10 ? "0" : "") << hours << ":"
         << (minutes < 10 ? "0" : "") << minutes << ":"
         << (seconds < 10 ? "0" : "") << seconds << std::endl;
   }

   // ������� �������� ���� �������� Time
   Time add(const Time& other) const {
      return Time(hours + other.hours,
         minutes + other.minutes,
         seconds + other.seconds);
   }

   // ���������� ��������� + ��� �������� ���� �������� Time
   Time operator+(const Time& other) const {
      return add(other);
   }

   // ���������� ��������� ���������
   Time operator-(const Time& other) const {
      return Time(hours - other.hours,
         minutes - other.minutes,
         seconds - other.seconds);
   }

   // ���������� ��������� �������� Time + double
   Time operator+(double hoursToAdd) const {
      int totalSeconds = hours * 3600 + minutes * 60 + seconds;
      totalSeconds += static_cast<int>(hoursToAdd * 3600);

      int h = totalSeconds / 3600;
      int m = (totalSeconds % 3600) / 60;
      int s = totalSeconds % 60;

      return Time(h, m, s);
   }

   // ���������� ��������� ������������
   Time& operator=(const Time& other) {
      if (this != &other) {
         hours = other.hours;
         minutes = other.minutes;
         seconds = other.seconds;
      }
      return *this;
   }

   // ���������� ���������� ���������
   bool operator==(const Time& other) const {
      return hours == other.hours &&
         minutes == other.minutes &&
         seconds == other.seconds;
   }

   bool operator!=(const Time& other) const {
      return !(*this == other);
   }

   bool operator<(const Time& other) const {
      if (hours != other.hours) return hours < other.hours;
      if (minutes != other.minutes) return minutes < other.minutes;
      return seconds < other.seconds;
   }

   bool operator>(const Time& other) const {
      return other < *this;
   }

   bool operator<=(const Time& other) const {
      return !(other < *this);
   }

   bool operator>=(const Time& other) const {
      return !(*this < other);
   }

   // ����� ��� ��������� ������ ���������� ������ (���������������)
   int toSeconds() const {
      return hours * 3600 + minutes * 60 + seconds;
   }
};

// ���������� ��������� �������� double + Time (���������� �������)
Time operator+(double hoursToAdd, const Time& time) {
   return time + hoursToAdd;
}

int ControlTask1()
{
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   // ������� ��� ������������������ �������
   const Time time1(2, 45, 30);    // 2:45:30
   const Time time2(1, 70, 90);    // 1:70:90 ����� ������������� � 2:11:30

   // ������� �������������������� ������
   Time result;

   std::cout << "����� 1: ";
   time1.display();

   std::cout << "����� 2: ";
   time2.display();

   // ���������� ��� ������� � ����������� ��������� �������� �������
   result = time1 + time2;
   std::cout << "��������� �������� (time1 + time2): ";
   result.display();

   // ��������� �������� Time
   result = time1 - time2;
   std::cout << "��������� ��������� (time1 - time2): ";
   result.display();

   // �������� ������� Time � ���������� ������������� ����
   result = time1 + 1.5; // 1.5 ���� = 1 ��� 30 �����
   std::cout << "��������� �������� (time1 + 1.5 ����): ";
   result.display();

   // �������� ���������� ������������� ���� � ������� Time
   result = 0.75 + time2; // 0.75 ���� = 45 �����
   std::cout << "��������� �������� (0.75 ���� + time2): ";
   result.display();

   // ��������� ���� �������� Time
   std::cout << "\n��������� �������:\n";
   std::cout << "time1 == time2: " << (time1 == time2 ? "true" : "false") << std::endl;
   std::cout << "time1 != time2: " << (time1 != time2 ? "true" : "false") << std::endl;
   std::cout << "time1 < time2: " << (time1 < time2 ? "true" : "false") << std::endl;
   std::cout << "time1 > time2: " << (time1 > time2 ? "true" : "false") << std::endl;
   std::cout << "time1 <= time2: " << (time1 <= time2 ? "true" : "false") << std::endl;
   std::cout << "time1 >= time2: " << (time1 >= time2 ? "true" : "false") << std::endl;

   // ������������ ������ � ������������� ����������
   Time testTime(25, 70, 80);  // 25:70:80 ����� ������������� � 2:11:20
   std::cout << "\n�������� ����� (25:70:80): ";
   testTime.display();

   return 0;
}
