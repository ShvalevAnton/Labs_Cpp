#include <string>
#include <fstream>
#include "Student.h"
#include "ExScore.h"


// ���������� Student
Student::~Student()
{
   Student::save();
}
// ������ ������ � �������� � ����
void Student::save()
{
   ofstream fout("students.txt", ios::app);
   fout << Student::get_name() << " "
      << Student::get_last_name() << " ";
   for (int i = 0; i < 5; ++i) {
      fout << Student::scores[i] << " ";
   }
   fout << endl;
   fout.close();
}

// ����������� Student
Student::Student() {
   // �������������
   name = "";
   last_name = "";
   average_score = 0.0;
   for (int i = 0; i < 5; i++) {
      scores[i] = 0;
   }
}
Student::Student(string name, string last_name)
{
   Student::set_name(name);
   Student::set_last_name(last_name);
}

// ��������� ����� ��������
void Student::set_name(string student_name)
{
   name = student_name;
}

// ��������� ����� ��������
string Student::get_name()
{
   return name;
}

// ��������� ������� ��������
void Student::set_last_name(string student_last_name)
{
   last_name = student_last_name;
}

// ��������� ������� ��������
string Student::get_last_name()
{
   return last_name;
}

// ��������� ������������� ������
void Student::set_scores(int student_scores[])
{
   for (int i = 0; i < 5; ++i) {
      if (student_scores[i] > 5)
         throw ExScore("� ������� set_scores()", student_scores[i]);
      scores[i] = student_scores[i];
   }
}

// ��������� �������� �����
void Student::set_average_score(double ball)
{
   average_score = ball;
}

// ��������� �������� �����
double Student::get_average_score()
{
   return average_score;
}
