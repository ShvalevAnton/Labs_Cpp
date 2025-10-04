#include <iostream>
#include <Windows.h>
#include <string>
#include <cctype>  // ��� isdigit
using namespace std;

// ������� �������� ���������� �����
bool isValidSNILS(const string& input) {
   string cleaned;
   // ������� ������: ��������� ������ �����, ������� � ������ ����������
   for (char c : input) {
      if (isdigit(c)) {
         cleaned += c;
      }
      else if (c != ' ' && c != '-') {
         // ������������ ������
         return false;
      }
   }

   // ������ ���� ����� 11 ����
   if (cleaned.length() != 11) {
      return false;
   }

   // ����������� ������ 9 ���� � ����� � ������� ����������� �����
   int sum = 0;
   for (int i = 0; i < 9; ++i) {
      sum += (cleaned[i] - '0') * (9 - i);
   }

   // ��������� ����������� �����
   int control;
   if (sum < 100) {
      control = sum;
   }
   else if (sum == 100 || sum == 101) {
      control = 0;
   }
   else {
      control = sum % 101;
      if (control == 100) {
         control = 0;
      }
   }

   // �������� ��������� ��� ����� ��� �����
   int givenControl = (cleaned[9] - '0') * 10 + (cleaned[10] - '0');

   return control == givenControl;
}

int ControlTask1() {
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   string snils;
   cout << "������� �����: ";
   getline(cin, snils); // ���������� getline, ����� ��������� �������

   if (isValidSNILS(snils)) {
      cout << "����� ��������." << endl;
   }
   else {
      cout << "����� �� ��������." << endl;
   }

   return 0;
}