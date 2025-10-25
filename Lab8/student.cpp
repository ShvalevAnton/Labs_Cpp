#include "Student.h"

// Установка имени студента
void Student::set_name(string student_name)
{
   name = student_name;
}

// Получение имени студента
string Student::get_name()
{
   return name;
}

// Установка фамилии студента
void Student::set_last_name(string student_last_name)
{
   last_name = student_last_name;
}

// Получение фамилии студента
string Student::get_last_name()
{
   return last_name;
}

// Установка промежуточных оценок
void Student::set_scores(int student_scores[])
{
   for (int i = 0; i < 5; ++i) {
      scores[i] = student_scores[i];
   }
}

// Установка среднего балла
void Student::set_average_score(double ball)
{
   average_score = ball;
}

// Получение среднего балла
double Student::get_average_score()
{
   return average_score;
}
