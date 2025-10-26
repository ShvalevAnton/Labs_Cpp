#include "StudentEx2.h"
#include <string>
#include <fstream>
#include "IdCard.h"
#include <iostream>


// ����������� Student ��� ����������
StudentEx2::StudentEx2() {
   // �������������
   name = "";
   last_name = "";
   average_score = 0.0;
   for (int i = 0; i < 5; i++) {
      scores[i] = 0;
   }
}

StudentEx2::StudentEx2(string name, string last_name, int id, string cat)
{
   StudentEx2::set_name(name);
   StudentEx2::set_last_name(last_name);
   StudentEx2::setIdCard(id, cat);
}

// ���������� Student
StudentEx2::~StudentEx2()
{
   StudentEx2::save();
}


// ������ ������ � �������� � ����
void StudentEx2::save()
{
   ofstream fout("students.txt", ios::app);
   fout << StudentEx2::get_name() << " "
      << StudentEx2::get_last_name() << " ";
   for (int i = 0; i < 5; ++i) {
      fout << StudentEx2::scores[i] << " ";
   }
   fout << endl;
   fout.close();
}

// ��������� ����� ��������
void StudentEx2::set_name(string student_name)
{
   name = student_name;
}

// ��������� ����� ��������
string StudentEx2::get_name()
{
   return name;
}

// ��������� ������� ��������
void StudentEx2::set_last_name(string student_last_name)
{
   last_name = student_last_name;
}

// ��������� ������� ��������
string StudentEx2::get_last_name()
{
   return last_name;
}

// ��������� ������������� ������
void StudentEx2::set_scores(int student_scores[])
{
   for (int i = 0; i < 5; ++i) {
      scores[i] = student_scores[i];
   }
}

// ��������� �������� �����
void StudentEx2::set_average_score(double ball)
{
   average_score = ball;
}

// ��������� �������� �����
double StudentEx2::get_average_score()
{
   return average_score;
}

void StudentEx2::setIdCard(int id, string c)
{
   iCard = IdCard(id, c);
}
int StudentEx2::getIdCard()
{
   return iCard.getNumber();
}
void StudentEx2::display() // ����� ���� ������ � �������� 
{ 
   cout << last_name << " " << name << "\t" << average_score << "\t" << iCard.getNumber()<< "\t" 
      << iCard.getCategory() << endl; 
}
