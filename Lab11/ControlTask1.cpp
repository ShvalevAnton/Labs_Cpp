#include <iostream>
#include <Windows.h>
#include <stdexcept>
#include <string>
#include <cmath>

class Time {
private:
   int hours;
   int minutes;
   int seconds;

   void validateTime(int h, int m, int s) const {
      if (h < 0 || h > 23) throw std::invalid_argument("���� ������ ���� 0-23");
      if (m < 0 || m > 59) throw std::invalid_argument("������ ������ ���� 0-59");
      if (s < 0 || s > 59) throw std::invalid_argument("������� ������ ���� 0-59");
   }

   // ��������������� ������� ��� ������������ ������� (������ ���������)
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
         if (seconds == 60) seconds = 0;
      }
      if (minutes < 0) {
         hours -= 1 + (-minutes) / 60;
         minutes = 60 - (-minutes) % 60;
         if (minutes == 60) minutes = 0;
      }
      if (hours < 0) {
         hours = 24 - (-hours) % 24;
         if (hours == 24) hours = 0;
      }
   }

public:
   // ������������
   Time() : hours(0), minutes(0), seconds(0) {}

   Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
      normalize();
      validateTime(hours, minutes, seconds);
   }

   // �������� ������
   void display() const {
      std::cout << (hours < 10 ? "0" : "") << hours << ":"
         << (minutes < 10 ? "0" : "") << minutes << ":"
         << (seconds < 10 ? "0" : "") << seconds << std::endl;
   }

   // C�������
   Time add(const Time& other) const {
      int totalSeconds = seconds + other.seconds;
      int totalMinutes = minutes + other.minutes + totalSeconds / 60;
      int totalHours = hours + other.hours + totalMinutes / 60;

      return Time(totalHours, totalMinutes % 60, totalSeconds % 60);
   }

   // C��������
   bool equals(const Time& other) const {
      return hours == other.hours &&
         minutes == other.minutes &&
         seconds == other.seconds;
   }

   bool isBefore(const Time& other) const {
      if (hours != other.hours) return hours < other.hours;
      if (minutes != other.minutes) return minutes < other.minutes;
      return seconds < other.seconds;
   }

   // �������
   int getHours() const { return hours; }
   int getMinutes() const { return minutes; }
   int getSeconds() const { return seconds; }

   // ���������� ����������

   // �������� �������� Time
   Time operator+(const Time& other) const {
      int totalSeconds = seconds + other.seconds;
      int totalMinutes = minutes + other.minutes + totalSeconds / 60;
      int totalHours = hours + other.hours + totalMinutes / 60;

      return Time(totalHours, totalMinutes % 60, totalSeconds % 60);
   }

   // ��������� �������� Time
   Time operator-(const Time& other) const {
      int totalSeconds = seconds - other.seconds;
      int totalMinutes = minutes - other.minutes;
      int totalHours = hours - other.hours;

      return Time(totalHours, totalMinutes, totalSeconds);
   }

   // �������� ������� Time � ���������� ������������� ���� (� �����)
   Time operator+(double hoursToAdd) const {
      int additionalHours = static_cast<int>(hoursToAdd);
      double fractionalPart = hoursToAdd - additionalHours;
      int additionalMinutes = static_cast<int>(fractionalPart * 60);
      int additionalSeconds = static_cast<int>((fractionalPart * 60 - additionalMinutes) * 60);

      return *this + Time(additionalHours, additionalMinutes, additionalSeconds);
   }

   // �������� ���������� ������������� ���� � ������� Time (������������� �������)
   friend Time operator+(double hoursToAdd, const Time& time) {
      return time + hoursToAdd;
   }

   // ��������� ���������
   bool operator==(const Time& other) const {
      return hours == other.hours && minutes == other.minutes && seconds == other.seconds;
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
};

int ControlTask1()
{
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   try
   {
      std::cout << "=== ������������ ���������� ���������� � ������ Time ===" << std::endl;

      Time time1(2, 45, 30);
      Time time2(1, 70, 90);  // ����� ������������� �� 2:11:30
      Time time3(23, 30, 0);

      std::cout << "����� 1: ";
      time1.display();

      std::cout << "����� 2: ";
      time2.display();

      std::cout << "����� 3: ";
      time3.display();

      // ������������ �������� �������� Time
      std::cout << "\n--- �������� �������� Time ---" << std::endl;
      Time sum1 = time1 + time2;
      std::cout << "time1 + time2 = ";
      sum1.display();

      // ������������ ��������� �������� Time
      std::cout << "\n--- ��������� �������� Time ---" << std::endl;
      Time diff1 = time1 - time2;
      std::cout << "time1 - time2 = ";
      diff1.display();

      // ������������ �������� Time � double
      std::cout << "\n--- �������� Time � double ---" << std::endl;
      Time sum2 = time1 + 1.5;  // 1 ��� 30 �����
      std::cout << "time1 + 1.5 ���� = ";
      sum2.display();

      // ������������ �������� double � Time
      std::cout << "\n--- �������� double � Time ---" << std::endl;
      Time sum3 = 0.75 + time1;  // 45 �����
      std::cout << "0.75 ���� + time1 = ";
      sum3.display();

      // ������������ ���������
      std::cout << "\n--- ��������� �������� Time ---" << std::endl;
      std::cout << "time1 == time2: " << (time1 == time2 ? "true" : "false") << std::endl;
      std::cout << "time1 != time2: " << (time1 != time2 ? "true" : "false") << std::endl;
      std::cout << "time1 < time2: " << (time1 < time2 ? "true" : "false") << std::endl;
      std::cout << "time1 > time2: " << (time1 > time2 ? "true" : "false") << std::endl;
      std::cout << "time1 <= time2: " << (time1 <= time2 ? "true" : "false") << std::endl;
      std::cout << "time1 >= time2: " << (time1 >= time2 ? "true" : "false") << std::endl;

      // �������������� �����
      std::cout << "\n--- �������������� ����� ---" << std::endl;
      Time lateTime(23, 59, 59);
      std::cout << "������� �����: ";
      lateTime.display();

      Time afterHour = lateTime + 1.0;  // +1 ���
      std::cout << "����� ���������� 1 ����: ";
      afterHour.display();

      Time earlyTime(0, 0, 0);
      Time beforeHour = earlyTime - 1.5;  // -1.5 ����
      std::cout << "00:00:00 - 1.5 ���� = ";
      beforeHour.display();

   }
   catch (const std::exception& e) {
      std::cerr << "������: " << e.what() << std::endl;
   }

   return 0;
}