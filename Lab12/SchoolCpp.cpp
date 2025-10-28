#include <iostream>
#include <Windows.h>
#include <vector>
#include "human.h"
#include "student.h"
#include "teacher.h"


using namespace std;

int SchoolCpp()
{
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   // ��������������
   std::vector<int> scores;
   // ���������� ������ �������� � ������
   scores.push_back(5);
   scores.push_back(3);
   scores.push_back(4);
   scores.push_back(4);
   scores.push_back(5);
   scores.push_back(3);
   scores.push_back(3);
   scores.push_back(3);
   scores.push_back(3);

   student* stud = new student("������", "����", "����������", scores);
  
   std::cout << stud->get_full_name() << std::endl;

   std::cout << "������� ���� : " << stud->get_average_score() << std::endl;
   
   unsigned int teacher_work_time = 40;
   teacher* tch = new teacher("�������", "�������", "���������", teacher_work_time);
   std::cout << tch->get_full_name() << std::endl;
   std::cout << "���������� �����: " << tch->get_work_time() << std::endl;
   
   return 0;
}