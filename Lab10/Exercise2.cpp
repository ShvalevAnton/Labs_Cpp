#include <iostream>
#include <Windows.h>
#include "StudentEx2.h"

using namespace std;

int Exercise2()
{
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   int card_number;
   string card_category;

   // ���� ������ ����� � ����������
   cout << "Card number: ";
   cin >> card_number;
   cin.ignore(); // ������� ������ ����� ����� �����

   // ���� ��������� �����
   cout << "Card category: ";
   getline(cin, card_category);  

   string name;
   string last_name;
   // ���� ����� � ����������
   cout << "Name: ";
   getline(std::cin, name);
   // ���� �������
   cout << "Last name: ";
   getline(std::cin, last_name);

   // ��������� ������ ��� ������� Student
   StudentEx2* student02 = new StudentEx2(name, last_name, card_number, card_category);

   // ������
   int scores[5];
   // ����� ���� ������
   int sum = 0;
   // ���� ������������� ������
   for (int i = 0; i < 5; ++i) {
      cout << "Score " << i + 1 << ": ";
      cin >> scores[i];
      // ������������
      sum += scores[i];
   }

   // ���������� ����� � ������� � ������ ������ Students
   student02->set_name(name);
   student02->set_last_name(last_name);
   // ��������� ������������� ������ � ������ ������ Student
   student02->set_scores(scores);
   // ������� ������� ����
   float average_score = sum / 5.0;
   // ��������� ������� ���� � ������ ������ Student
   student02->set_average_score(average_score);
   // ������� ������ �� ��������
   student02->display();

   delete student02;

   return 0;
}