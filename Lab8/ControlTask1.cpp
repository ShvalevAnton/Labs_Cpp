#include <iostream>
#include <Windows.h>


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

   // ���������� ��������� + ��� ����� �������� �������������
   Time operator+(const Time& other) const {
      return add(other);
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
};

int ControlTask1() 
{
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   // ������� ��� ������������������ ������� (�����������, ��� ��� �� �������� �� ��������)
   const Time time1(2, 45, 30);    // 2:45:30
   const Time time2(1, 70, 90);    // 1:70:90 ����� ������������� � 2:11:30

   // ������� �������������������� ������
   Time result;

   std::cout << "����� 1: ";
   time1.display();

   std::cout << "����� 2: ";
   time2.display();

   // ���������� ��� ������� � ����������� ��������� �������� �������
   result = time1.add(time2);

   std::cout << "��������� ��������: ";
   result.display();

   // ������������ ������ � ������������� ����������
   Time testTime(25, 70, 80);  // 25:70:80 ����� ������������� � 2:11:20
   std::cout << "�������� ����� (25:70:80): ";
   testTime.display();

   return 0;
}